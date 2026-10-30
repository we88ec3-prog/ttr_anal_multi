# T16-93 — KR Quest 靜態查找成功分支、互動控制器與條件性 0x00010049 dispatch（BIN-first）

研究者：`chatgpt-web roy`；分析日期：2026-10-28 21:33:25 Asia/Taipei。此為獨立原生研究原稿，**未 Commit／Push**。

## 0. 前置 Git 分支同步驗證

- Repo `we88ec3-prog/ttr_anal_multi`，已用 GitHub connector 分別比較 `main...t16/roy/chatgpt-web` 與反方向。
- `main` HEAD=`9fda9a44142c8ce01750e838bcb30bf8912b0a05`；T16 工作分支 HEAD=`20aec864564996c14462cc968a5b36e0bfbb1199`。compare: ahead=1、behind=0、merge base=main HEAD，說明 main 已是 T16 分支的祖先，當前 `main → t16` 無待合入提交（Already up to date）。**本次沒有生成新的 merge commit，亦沒有更新分支**。
- 在已同步的工作分支讀回 `AGENTS.md`、`HANDOFF.md`、`shared/CLIENT-MODIFICATION-POLICY.md`、`kr/tasks/T16/README.md`、`kr/tasks/T16/task.json`、T16-92 完整原稿。T16 README/task.json 仍存在較舊的 next_steps（T16-69），但最新完成段以 T16-92 原稿與交接為準；task.json 仍 `owner:null`、`state:unclaimed`、`native_complete:false`，**未更動**。

## 1. 來源、hash、映射及方法

- `Tartaros.bin` 12,472,320 bytes，實測 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- `Tartaros.exe` 實測 SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- 本次列示的 `.text` VA→BIN raw：`raw=VA-0x00400C00`；例如 `0x00596FBA→0x001963BA`、`0x005B6C86→0x001B6086`、`0x00636520→0x00235920`。上述範圍落在既有 KR 映射；opcode 不由常數名稱臆測。
- 在 BIN 原件直接用 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00` 反組譯指定區間；**非直接執行**客戶端，且無 Socket runtime capture / Server 原始碼。反組譯截取範圍按已知函式入口，邊界以 T16-92 和原生 int3 對照；不把全區間雜訊當函式。
- 追查主線：`0x5B6C86 → 0x636520, 0x74A010, 0x596E00 → 0x596EC0 → [0xFBA854] virtual+0x10`。另外確認另一路同族 caller `0x5B6B90...` 的共用模式。

## 2. 第一輪（T16-93）— 0x5B6C86 查找成功後三個依序調用

已確定從 `EBX+0x14` 取 key，`ECX=[0xFB114C]` 呼叫 `0x503D20`（T16-92 的 Quest 靜態 map reader），比對 node 與 `owner+4` sentinel；不相等則取 `node+0x10`，`[nodePayload+0x28]` 轉入 ECX，並依序呼叫以下三個 helper：

```asm
5b6c6e: 8b 43 14                mov eax,DWORD PTR [ebx+0x14]
5b6c71: 8b 35 4c 11 fb 00       mov esi,DWORD PTR ds:0xfb114c
5b6c86: e8 95 d0 f4 ff          call 0x503d20
5b6c92: 3b c6                   cmp eax,esi
5b6c94: 74 6c                   je 0x5b6d02
5b6c96: 8d 70 10                lea esi,[eax+0x10]
5b6cd0: 8b 53 14                mov edx,DWORD PTR [ebx+0x14]
5b6cd7: 8b 4e 28                mov ecx,DWORD PTR [esi+0x28]
5b6cda: 52                      push edx
5b6cdb: 8b 97 24 02 00 00       mov edx,DWORD PTR [edi+0x224]
5b6ce1: 6a 01                   push 0x1
5b6ce3: 50                      push eax
5b6ce4: e8 37 f8 07 00          call 0x636520
5b6cf0: e8 1b 33 19 00          call 0x74a010
5b6cfd: e8 fe 00 fe ff          call 0x596e00
```

其中 `0x636520` 不是 packet builder 的直接證據。它以 `ECX`、`EDX` 參數建立互動／控制器狀態，至少寫 `[EDI+0x80]`（輸入 [EBP+8]）、`[EDI+0x84]`（原 ECX）、`[EDI+0x90]`（[EBP+C]），透過 `0x8438C0` 取查找結果與 `0x6389E0`，配置 0x24 byte sentinel-like object，並透過 `0x4FC250` 查詢。`[EDI+0x8C]` 是該次查找結果非零 flag，之後按 `[EDI+0x90]` 的 0–3 範圍 jump-table 分派。其物件意義仍不宜只靠本次片段斷言為 NPC/Quest 接取視窗。

**本輪新增加的確切上下游：** Quest XML map 命中後不只建立文字，而是立即以 payload+0x28 的資料進入 `0x636520` 控制器流程，後續 `0x596E00` 進入可觀察的條件式 dispatcher。這是 T16-92 未驗證的下游鏈。

## 3. 第二輪（T16-93-2）— 0x596E00 類別／模式篩選與 0x596EC0

另一 caller `0x5B6B90` 附近亦有同樣三函式序列，但 `0x636520` 傳入的第 2 參數為 0，而 `0x5B6C86` 命中後傳入 1；這提示不同操作模式，**不得硬寫成接受/交付**。

`0x596E00` 呼叫 `0x848020` 對三組 0x10 bytes 的欄位做查找（實際基底為 caller 第一參數+`0xC4`），依 0/1/2 與例外分支呼叫 `0x597250` 或 `0x596EC0`；`0x596EC0` 依第二參數物件 `[+0x28]` 的 flags、`0x539AA0` 回傳物件之 flag 及 `[ESI+4/+5/+6/+8]` 決定後續執行。

**直接原生發現：** 在 `0x596F7C` 分支中，只有 `BYTE PTR [ESI+5] != 0`、全域 `[0x00FBA798] == 0` 才執行下列 4-byte 下游 virtual call：

```asm
596f7c: 80 7e 05 00            cmp BYTE PTR [esi+0x5],0x0
596f80: 74 42                  je 0x596fc4
596f9f: 83 3d 98 a7 fb 00 00   cmp DWORD PTR ds:0xfba798,0x0
596fa6: c7 45 08 49 00 01 00   mov DWORD PTR [ebp+0x8],0x10049
596fad: 75 15                  jne 0x596fc4
596faf: 8b 0d 54 a8 fb 00      mov ecx,DWORD PTR ds:0xfba854
596fb5: 8b 11                  mov edx,DWORD PTR [ecx]
596fb7: 8b 52 10               mov edx,DWORD PTR [edx+0x10]
596fba: 6a 04                  push 0x4
596fbc: 8d 45 08               lea eax,[ebp+0x8]
596fbf: 50                     push eax
596fc0: 6a 00                  push 0x0
596fc2: ff d2                  call edx
```

物件/旗標結論：`[ESI+5]` 是是否發動此事件的 gate，`[0xFBA798]` 是抑制 gate；`[0xFBA854]` 指向 virtual dispatcher 物件，具 `vtable+0x10` 函式。**可確定向此 virtual method 傳入 4-byte data、長度 4、另有 0 參數；不可確認 virtual target、queue、socket、wire opcode/domain。`0x00010049` 暫記為 local message 值。**

除此之外，本地結果仍會按 flags 寫 `[EBX+0xB0]` 的 16-bit 值 `0x0101`（當 [ESI+4] 非零）、根據 `[ESI+8]` 走 vtable `+0x19C`，並複製 `[ESI]` 所選索引的 4×4byte 資料至 `[EBX+index*16+0xFC]`，最後調用第二參數物件 vtable `+0xD0`。**這些是本地 object/state 的變更，不應稱 Quest cache writer。**

## 4. 第三輪（T16-93-3）— 協定歸屬與缺失的下游驗證

三輪門檻：前兩輪已新增 `0x596EC0` 的具體條件式 virtual message 呼叫與多個本地 writer，但尚**沒有**將其證實為 Quest C→S wire、也沒有 S→C Quest state cache。因此第三輪針對能否將此訊息直接視為業務封包進行邊界檢查。

- `0x596FBA` virtual method 的 `ECX` 指向 `[0xFBA854]`；單靠間接 vtable `+0x10` 無法證明最終方法是 socket/queue。相同 T16 早期 4-byte `0x004AA4D0` 也屬相似研究邊界；本次**沒有確認**兩者相同 target 或 domain。
- `0x596FCA` 等後續直接修改互動物件與回呼，**不是由已確認的 S→C handler 呼入**，也沒有動態 Quest state cache 寫入證據。若 Server 回覆/重入必須另追真正 receive opcode dispatcher。
- 由 `0x5B6C86` 的 XML key 成功分支到 4-byte virtual call 是**可確認的條件性候選 producer 鏈**，但 `0x596E00` 中 3-slot matching、`0x596EC0` 的權限旗標及 virtual target 未完全確定，因此不把單一 event ID 填到 Quest wire 協定表。
- **停止理由：** 已找到與過往缺口不同的原生條件式訊息 producer 和本地結果寫入，屬可驗證的功能鏈增量；三輪證據不足以稱 Quest 交付/接取封包已閉合。此處停止本段並明列待補入口，避免猜測。

## 5. 三輪原始組語附錄（BIN 直接讀取）

以下為以本機 BIN `objdump` 所得的逐指令原始地址/bytes/assembly。涉及前段有已知函式邊界者按入口截取；非入口中途的區塊只作上下文，不視為獨立函式。分析以本附錄為可重現原稿。

### A. Quest map 命中後 caller

```asm
  5b6be0:	55                   	push   ebp
  5b6be1:	8b ec                	mov    ebp,esp
  5b6be3:	83 e4 f8             	and    esp,0xfffffff8
  5b6be6:	6a ff                	push   0xffffffff
  5b6be8:	68 2c 93 94 00       	push   0x94932c
  5b6bed:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5b6bf3:	50                   	push   eax
  5b6bf4:	83 ec 10             	sub    esp,0x10
  5b6bf7:	53                   	push   ebx
  5b6bf8:	56                   	push   esi
  5b6bf9:	57                   	push   edi
  5b6bfa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5b6bff:	33 c4                	xor    eax,esp
  5b6c01:	50                   	push   eax
  5b6c02:	8d 44 24 20          	lea    eax,[esp+0x20]
  5b6c06:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5b6c0c:	8b f1                	mov    esi,ecx
  5b6c0e:	8b fa                	mov    edi,edx
  5b6c10:	85 f6                	test   esi,esi
  5b6c12:	74 26                	je     0x5b6c3a
  5b6c14:	8b 06                	mov    eax,DWORD PTR [esi]
  5b6c16:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b6c19:	ff d2                	call   edx
  5b6c1b:	3d b9 05 01 00       	cmp    eax,0x105b9
  5b6c20:	75 04                	jne    0x5b6c26
  5b6c22:	8b de                	mov    ebx,esi
  5b6c24:	eb 16                	jmp    0x5b6c3c
  5b6c26:	6a 00                	push   0x0
  5b6c28:	68 c0 1f bf 00       	push   0xbf1fc0
  5b6c2d:	68 18 21 bf 00       	push   0xbf2118
  5b6c32:	6a 00                	push   0x0
  5b6c34:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  5b6c3a:	33 db                	xor    ebx,ebx
  5b6c3c:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  5b6c43:	75 29                	jne    0x5b6c6e
  5b6c45:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  5b6c4c:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  5b6c53:	00 
  5b6c54:	e8 07 92 f4 ff       	call   0x4ffe60
  5b6c59:	68 00 cf bc 00       	push   0xbccf00
  5b6c5e:	e8 b7 b6 2d 00       	call   0x89231a
  5b6c63:	83 c4 04             	add    esp,0x4
  5b6c66:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6c6d:	ff 
  5b6c6e:	8b 43 14             	mov    eax,DWORD PTR [ebx+0x14]
  5b6c71:	8b 35 4c 11 fb 00    	mov    esi,DWORD PTR ds:0xfb114c
  5b6c77:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  5b6c7b:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5b6c7f:	51                   	push   ecx
  5b6c80:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5b6c84:	8b ce                	mov    ecx,esi
  5b6c86:	e8 95 d0 f4 ff       	call   0x503d20
  5b6c8b:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  5b6c8e:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  5b6c92:	3b c6                	cmp    eax,esi
  5b6c94:	74 6c                	je     0x5b6d02
  5b6c96:	8d 70 10             	lea    esi,[eax+0x10]
  5b6c99:	85 f6                	test   esi,esi
  5b6c9b:	74 65                	je     0x5b6d02
  5b6c9d:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  5b6ca4:	75 29                	jne    0x5b6ccf
  5b6ca6:	b8 01 00 00 00       	mov    eax,0x1
  5b6cab:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  5b6cb1:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  5b6cb5:	e8 d6 7f f2 ff       	call   0x4dec90
  5b6cba:	68 30 ce bc 00       	push   0xbcce30
  5b6cbf:	e8 56 b6 2d 00       	call   0x89231a
  5b6cc4:	83 c4 04             	add    esp,0x4
  5b6cc7:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6cce:	ff 
  5b6ccf:	8b 53 14             	mov    edx,DWORD PTR [ebx+0x14]
  5b6cd2:	a1 bc b1 fa 00       	mov    eax,ds:0xfab1bc
  5b6cd7:	8b 4e 28             	mov    ecx,DWORD PTR [esi+0x28]
  5b6cda:	52                   	push   edx
  5b6cdb:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6ce1:	6a 01                	push   0x1
  5b6ce3:	50                   	push   eax
  5b6ce4:	e8 37 f8 07 00       	call   0x636520
  5b6ce9:	8b 8f 24 02 00 00    	mov    ecx,DWORD PTR [edi+0x224]
  5b6cef:	51                   	push   ecx
  5b6cf0:	e8 1b 33 19 00       	call   0x74a010
  5b6cf5:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6cfb:	52                   	push   edx
  5b6cfc:	57                   	push   edi
  5b6cfd:	e8 fe 00 fe ff       	call   0x596e00
  5b6d02:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5b6d06:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5b6d0d:	59                   	pop    ecx
  5b6d0e:	5f                   	pop    edi
  5b6d0f:	5e                   	pop    esi
  5b6d10:	5b                   	pop    ebx
  5b6d11:	8b e5                	mov    esp,ebp
  5b6d13:	5d                   	pop    ebp
  5b6d14:	c3                   	ret
```

### B. 另一條同族 caller

```asm
  5b6b90:	bf 00 68 18 21       	mov    edi,0x21186800
  5b6b95:	bf 00 6a 00 ff       	mov    edi,0xff006a00
  5b6b9a:	15 80 25 bd 00       	adc    eax,0xbd2580
  5b6b9f:	33 c0                	xor    eax,eax
  5b6ba1:	8b 48 14             	mov    ecx,DWORD PTR [eax+0x14]
  5b6ba4:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6baa:	6a 00                	push   0x0
  5b6bac:	6a 00                	push   0x0
  5b6bae:	51                   	push   ecx
  5b6baf:	8b 48 18             	mov    ecx,DWORD PTR [eax+0x18]
  5b6bb2:	e8 69 f9 07 00       	call   0x636520
  5b6bb7:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6bbd:	52                   	push   edx
  5b6bbe:	e8 4d 34 19 00       	call   0x74a010
  5b6bc3:	8b 87 24 02 00 00    	mov    eax,DWORD PTR [edi+0x224]
  5b6bc9:	50                   	push   eax
  5b6bca:	57                   	push   edi
  5b6bcb:	e8 30 02 fe ff       	call   0x596e00
  5b6bd0:	5f                   	pop    edi
  5b6bd1:	c3                   	ret
```

### C. 模式建立與資料結構

```asm
  636520:	55                   	push   ebp
  636521:	8b ec                	mov    ebp,esp
  636523:	83 e4 f8             	and    esp,0xfffffff8
  636526:	6a ff                	push   0xffffffff
  636528:	68 32 92 94 00       	push   0x949232
  63652d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  636533:	50                   	push   eax
  636534:	83 ec 28             	sub    esp,0x28
  636537:	53                   	push   ebx
  636538:	56                   	push   esi
  636539:	57                   	push   edi
  63653a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  63653f:	33 c4                	xor    eax,esp
  636541:	50                   	push   eax
  636542:	8d 44 24 38          	lea    eax,[esp+0x38]
  636546:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  63654c:	8b f1                	mov    esi,ecx
  63654e:	8b fa                	mov    edi,edx
  636550:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  636553:	8b 1d d0 1b fe 00    	mov    ebx,DWORD PTR ds:0xfe1bd0
  636559:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  63655d:	89 87 80 00 00 00    	mov    DWORD PTR [edi+0x80],eax
  636563:	51                   	push   ecx
  636564:	8d 4b 08             	lea    ecx,[ebx+0x8]
  636567:	8d 44 24 18          	lea    eax,[esp+0x18]
  63656b:	89 b7 84 00 00 00    	mov    DWORD PTR [edi+0x84],esi
  636571:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  636575:	e8 46 d3 20 00       	call   0x8438c0
  63657a:	8b 43 0c             	mov    eax,DWORD PTR [ebx+0xc]
  63657d:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  636581:	33 db                	xor    ebx,ebx
  636583:	3b c8                	cmp    ecx,eax
  636585:	74 05                	je     0x63658c
  636587:	8b 49 10             	mov    ecx,DWORD PTR [ecx+0x10]
  63658a:	eb 02                	jmp    0x63658e
  63658c:	33 c9                	xor    ecx,ecx
  63658e:	8b 87 bc 00 00 00    	mov    eax,DWORD PTR [edi+0xbc]
  636594:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  636597:	56                   	push   esi
  636598:	50                   	push   eax
  636599:	89 8f b8 00 00 00    	mov    DWORD PTR [edi+0xb8],ecx
  63659f:	89 97 90 00 00 00    	mov    DWORD PTR [edi+0x90],edx
  6365a5:	89 9f 88 00 00 00    	mov    DWORD PTR [edi+0x88],ebx
  6365ab:	e8 30 24 00 00       	call   0x6389e0
  6365b0:	6a 24                	push   0x24
  6365b2:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  6365b6:	e8 ad ac 25 00       	call   0x891268
  6365bb:	83 c4 04             	add    esp,0x4
  6365be:	3b c3                	cmp    eax,ebx
  6365c0:	0f 84 85 01 00 00    	je     0x63674b
  6365c6:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  6365ca:	89 00                	mov    DWORD PTR [eax],eax
  6365cc:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  6365d0:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  6365d3:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  6365d7:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  6365da:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  6365de:	c6 41 20 01          	mov    BYTE PTR [ecx+0x20],0x1
  6365e2:	8b 54 24 28          	mov    edx,DWORD PTR [esp+0x28]
  6365e6:	c6 42 21 01          	mov    BYTE PTR [edx+0x21],0x1
  6365ea:	53                   	push   ebx
  6365eb:	89 5c 24 44          	mov    DWORD PTR [esp+0x44],ebx
  6365ef:	8b 8f 84 00 00 00    	mov    ecx,DWORD PTR [edi+0x84]
  6365f5:	8b 97 80 00 00 00    	mov    edx,DWORD PTR [edi+0x80]
  6365fb:	8d 44 24 28          	lea    eax,[esp+0x28]
  6365ff:	50                   	push   eax
  636600:	a1 b4 1d fe 00       	mov    eax,ds:0xfe1db4
  636605:	51                   	push   ecx
  636606:	52                   	push   edx
  636607:	50                   	push   eax
  636608:	e8 43 5c ec ff       	call   0x4fc250
  63660d:	39 5c 24 2c          	cmp    DWORD PTR [esp+0x2c],ebx
  636611:	8b 87 90 00 00 00    	mov    eax,DWORD PTR [edi+0x90]
  636617:	0f 95 c1             	setne  cl
  63661a:	88 8f 8c 00 00 00    	mov    BYTE PTR [edi+0x8c],cl
  636620:	83 f8 03             	cmp    eax,0x3
  636623:	0f 87 e3 00 00 00    	ja     0x63670c
  636629:	ff 24 85 74 67 63 00 	jmp    DWORD PTR [eax*4+0x636774]
  636630:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636636:	8b 11                	mov    edx,DWORD PTR [ecx]
  636638:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  63663b:	ff d0                	call   eax
  63663d:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636643:	8b 11                	mov    edx,DWORD PTR [ecx]
  636645:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  636648:	ff d0                	call   eax
  63664a:	e8 51 f6 ff ff       	call   0x635ca0
  63664f:	e9 b8 00 00 00       	jmp    0x63670c
  636654:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  63665a:	8b 11                	mov    edx,DWORD PTR [ecx]
  63665c:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  63665f:	ff d0                	call   eax
  636661:	e8 ca 92 dd ff       	call   0x40f930
  636666:	8b c8                	mov    ecx,eax
  636668:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  63666b:	e8 20 a9 ec ff       	call   0x500f90
  636670:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  636676:	3b c3                	cmp    eax,ebx
  636678:	74 73                	je     0x6366ed
  63667a:	8b 48 30             	mov    ecx,DWORD PTR [eax+0x30]
  63667d:	51                   	push   ecx
  63667e:	8b c7                	mov    eax,edi
  636680:	e8 8b f8 ff ff       	call   0x635f10
  636685:	eb 72                	jmp    0x6366f9
  636687:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  63668d:	8b 11                	mov    edx,DWORD PTR [ecx]
  63668f:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  636692:	ff d0                	call   eax
  636694:	e8 97 92 dd ff       	call   0x40f930
  636699:	8b c8                	mov    ecx,eax
  63669b:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  63669e:	e8 ed a8 ec ff       	call   0x500f90
  6366a3:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  6366a9:	3b c3                	cmp    eax,ebx
  6366ab:	74 40                	je     0x6366ed
  6366ad:	8b 48 34             	mov    ecx,DWORD PTR [eax+0x34]
```

### D. 相依物件派送

```asm
  596e00:	55                   	push   ebp
  596e01:	8b ec                	mov    ebp,esp
  596e03:	83 ec 0c             	sub    esp,0xc
  596e06:	53                   	push   ebx
  596e07:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  596e0a:	83 bb f0 00 00 00 00 	cmp    DWORD PTR [ebx+0xf0],0x0
  596e11:	56                   	push   esi
  596e12:	57                   	push   edi
  596e13:	0f 85 9d 00 00 00    	jne    0x596eb6
  596e19:	33 f6                	xor    esi,esi
  596e1b:	33 ff                	xor    edi,edi
  596e1d:	c7 45 f8 ff ff ff ff 	mov    DWORD PTR [ebp-0x8],0xffffffff
  596e24:	81 c3 c4 00 00 00    	add    ebx,0xc4
  596e2a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  596e30:	8d 45 0c             	lea    eax,[ebp+0xc]
  596e33:	50                   	push   eax
  596e34:	8d 4b fc             	lea    ecx,[ebx-0x4]
  596e37:	8d 45 fc             	lea    eax,[ebp-0x4]
  596e3a:	e8 e1 11 2b 00       	call   0x848020
  596e3f:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  596e42:	3b 03                	cmp    eax,DWORD PTR [ebx]
  596e44:	75 0e                	jne    0x596e54
  596e46:	47                   	inc    edi
  596e47:	83 c3 10             	add    ebx,0x10
  596e4a:	83 ff 03             	cmp    edi,0x3
  596e4d:	7c e1                	jl     0x596e30
  596e4f:	8b 7d f8             	mov    edi,DWORD PTR [ebp-0x8]
  596e52:	eb 03                	jmp    0x596e57
  596e54:	8d 70 10             	lea    esi,[eax+0x10]
  596e57:	8b c7                	mov    eax,edi
  596e59:	83 e8 00             	sub    eax,0x0
  596e5c:	74 45                	je     0x596ea3
  596e5e:	48                   	dec    eax
  596e5f:	74 2c                	je     0x596e8d
  596e61:	48                   	dec    eax
  596e62:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  596e65:	74 13                	je     0x596e7a
  596e67:	8b 11                	mov    edx,DWORD PTR [ecx]
  596e69:	8b 82 d0 00 00 00    	mov    eax,DWORD PTR [edx+0xd0]
  596e6f:	ff d0                	call   eax
  596e71:	5f                   	pop    edi
  596e72:	5e                   	pop    esi
  596e73:	5b                   	pop    ebx
  596e74:	8b e5                	mov    esp,ebp
  596e76:	5d                   	pop    ebp
  596e77:	c2 08 00             	ret    0x8
  596e7a:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  596e7d:	51                   	push   ecx
  596e7e:	52                   	push   edx
  596e7f:	e8 3c 00 00 00       	call   0x596ec0
  596e84:	5f                   	pop    edi
  596e85:	5e                   	pop    esi
  596e86:	5b                   	pop    ebx
  596e87:	8b e5                	mov    esp,ebp
  596e89:	5d                   	pop    ebp
  596e8a:	c2 08 00             	ret    0x8
  596e8d:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  596e90:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  596e93:	50                   	push   eax
  596e94:	51                   	push   ecx
  596e95:	e8 26 00 00 00       	call   0x596ec0
  596e9a:	5f                   	pop    edi
  596e9b:	5e                   	pop    esi
  596e9c:	5b                   	pop    ebx
  596e9d:	8b e5                	mov    esp,ebp
  596e9f:	5d                   	pop    ebp
  596ea0:	c2 08 00             	ret    0x8
  596ea3:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  596ea6:	57                   	push   edi
  596ea7:	e8 a4 03 00 00       	call   0x597250
  596eac:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  596eaf:	52                   	push   edx
  596eb0:	57                   	push   edi
  596eb1:	e8 0a 00 00 00       	call   0x596ec0
  596eb6:	5f                   	pop    edi
  596eb7:	5e                   	pop    esi
  596eb8:	5b                   	pop    ebx
  596eb9:	8b e5                	mov    esp,ebp
  596ebb:	5d                   	pop    ebp
  596ebc:	c2 08 00             	ret    0x8
  596ebf:	cc                   	int3
```

### E. 條件式 4-byte 派送與本地狀態寫入

```asm
  596ec0:	55                   	push   ebp
  596ec1:	8b ec                	mov    ebp,esp
  596ec3:	6a ff                	push   0xffffffff
  596ec5:	68 fe 51 94 00       	push   0x9451fe
  596eca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  596ed0:	50                   	push   eax
  596ed1:	53                   	push   ebx
  596ed2:	57                   	push   edi
  596ed3:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  596ed8:	33 c5                	xor    eax,ebp
  596eda:	50                   	push   eax
  596edb:	8d 45 f4             	lea    eax,[ebp-0xc]
  596ede:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  596ee4:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  596ee7:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  596eea:	8b 48 28             	mov    ecx,DWORD PTR [eax+0x28]
  596eed:	c1 e9 08             	shr    ecx,0x8
  596ef0:	f6 c1 01             	test   cl,0x1
  596ef3:	0f 85 27 01 00 00    	jne    0x597020
  596ef9:	f6 05 78 13 fb 00 01 	test   BYTE PTR ds:0xfb1378,0x1
  596f00:	75 27                	jne    0x596f29
  596f02:	83 0d 78 13 fb 00 01 	or     DWORD PTR ds:0xfb1378,0x1
  596f09:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  596f10:	e8 0b 2d fa ff       	call   0x539c20
  596f15:	68 b0 cf bc 00       	push   0xbccfb0
  596f1a:	e8 fb b3 2f 00       	call   0x89231a
  596f1f:	83 c4 04             	add    esp,0x4
  596f22:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  596f29:	8b 3d 58 72 fb 00    	mov    edi,DWORD PTR ds:0xfb7258
  596f2f:	85 ff                	test   edi,edi
  596f31:	74 2b                	je     0x596f5e
  596f33:	e8 68 dc e6 ff       	call   0x404ba0
  596f38:	8b 90 50 5f 00 00    	mov    edx,DWORD PTR [eax+0x5f50]
  596f3e:	52                   	push   edx
  596f3f:	8b d7                	mov    edx,edi
  596f41:	e8 5a 2b fa ff       	call   0x539aa0
  596f46:	85 c0                	test   eax,eax
  596f48:	0f 84 d2 00 00 00    	je     0x597020
  596f4e:	80 78 08 00          	cmp    BYTE PTR [eax+0x8],0x0
  596f52:	74 0a                	je     0x596f5e
  596f54:	80 7e 06 00          	cmp    BYTE PTR [esi+0x6],0x0
  596f58:	0f 84 c2 00 00 00    	je     0x597020
  596f5e:	83 3e 01             	cmp    DWORD PTR [esi],0x1
  596f61:	75 19                	jne    0x596f7c
  596f63:	83 bb f4 00 00 00 00 	cmp    DWORD PTR [ebx+0xf4],0x0
  596f6a:	74 10                	je     0x596f7c
  596f6c:	8b 8b f4 00 00 00    	mov    ecx,DWORD PTR [ebx+0xf4]
  596f72:	8b 01                	mov    eax,DWORD PTR [ecx]
  596f74:	8b 90 d4 00 00 00    	mov    edx,DWORD PTR [eax+0xd4]
  596f7a:	ff d2                	call   edx
  596f7c:	80 7e 05 00          	cmp    BYTE PTR [esi+0x5],0x0
  596f80:	74 42                	je     0x596fc4
  596f82:	f6 05 14 13 fb 00 01 	test   BYTE PTR ds:0xfb1314,0x1
  596f89:	75 14                	jne    0x596f9f
  596f8b:	83 0d 14 13 fb 00 01 	or     DWORD PTR ds:0xfb1314,0x1
  596f92:	68 10 cf bc 00       	push   0xbccf10
  596f97:	e8 7e b3 2f 00       	call   0x89231a
  596f9c:	83 c4 04             	add    esp,0x4
  596f9f:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  596fa6:	c7 45 08 49 00 01 00 	mov    DWORD PTR [ebp+0x8],0x10049
  596fad:	75 15                	jne    0x596fc4
  596faf:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  596fb5:	8b 11                	mov    edx,DWORD PTR [ecx]
  596fb7:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  596fba:	6a 04                	push   0x4
  596fbc:	8d 45 08             	lea    eax,[ebp+0x8]
  596fbf:	50                   	push   eax
  596fc0:	6a 00                	push   0x0
  596fc2:	ff d2                	call   edx
  596fc4:	80 7e 04 00          	cmp    BYTE PTR [esi+0x4],0x0
  596fc8:	74 09                	je     0x596fd3
  596fca:	66 c7 83 b0 00 00 00 	mov    WORD PTR [ebx+0xb0],0x101
  596fd1:	01 01 
  596fd3:	80 7e 08 00          	cmp    BYTE PTR [esi+0x8],0x0
  596fd7:	74 10                	je     0x596fe9
  596fd9:	8b 4e 0c             	mov    ecx,DWORD PTR [esi+0xc]
  596fdc:	8b 03                	mov    eax,DWORD PTR [ebx]
  596fde:	8b 90 9c 01 00 00    	mov    edx,DWORD PTR [eax+0x19c]
  596fe4:	51                   	push   ecx
  596fe5:	8b cb                	mov    ecx,ebx
  596fe7:	ff d2                	call   edx
  596fe9:	8b 06                	mov    eax,DWORD PTR [esi]
  596feb:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  596fee:	89 8c 83 f0 00 00 00 	mov    DWORD PTR [ebx+eax*4+0xf0],ecx
  596ff5:	8b 16                	mov    edx,DWORD PTR [esi]
  596ff7:	03 d2                	add    edx,edx
  596ff9:	8d 84 d3 fc 00 00 00 	lea    eax,[ebx+edx*8+0xfc]
  597000:	8b 16                	mov    edx,DWORD PTR [esi]
  597002:	89 10                	mov    DWORD PTR [eax],edx
  597004:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  597007:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  59700a:	8b 56 08             	mov    edx,DWORD PTR [esi+0x8]
  59700d:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  597010:	8b 56 0c             	mov    edx,DWORD PTR [esi+0xc]
  597013:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  597016:	8b 01                	mov    eax,DWORD PTR [ecx]
  597018:	8b 90 d0 00 00 00    	mov    edx,DWORD PTR [eax+0xd0]
  59701e:	ff d2                	call   edx
  597020:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  597023:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  59702a:	59                   	pop    ecx
  59702b:	5f                   	pop    edi
  59702c:	5b                   	pop    ebx
  59702d:	8b e5                	mov    esp,ebp
  59702f:	5d                   	pop    ebp
  597030:	c2 08 00             	ret    0x8
```

### F. 另一個 caller 0x62E579 的文字消費點

```asm
  62e62f:	50                   	push   eax
  62e630:	52                   	push   edx
  62e631:	8d 4d ac             	lea    ecx,[ebp-0x54]
  62e634:	e8 27 3b dd ff       	call   0x402160
  62e639:	8b b3 08 01 00 00    	mov    esi,DWORD PTR [ebx+0x108]
  62e63f:	81 c6 e8 00 00 00    	add    esi,0xe8
  62e645:	c7 45 fc 04 00 00 00 	mov    DWORD PTR [ebp-0x4],0x4
  62e64c:	e8 9f 92 12 00       	call   0x7578f0
  62e651:	6a 7d                	push   0x7d
  62e653:	6a 7b                	push   0x7b
  62e655:	8d 55 ac             	lea    edx,[ebp-0x54]
  62e658:	52                   	push   edx
  62e659:	56                   	push   esi
  62e65a:	e8 71 b8 12 00       	call   0x759ed0
  62e65f:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  62e666:	39 7d c0             	cmp    DWORD PTR [ebp-0x40],edi
  62e669:	72 0c                	jb     0x62e677
  62e66b:	8b 45 ac             	mov    eax,DWORD PTR [ebp-0x54]
  62e66e:	50                   	push   eax
  62e66f:	e8 98 2b 26 00       	call   0x89120c
  62e674:	83 c4 04             	add    esp,0x4
  62e677:	8b 8b 08 01 00 00    	mov    ecx,DWORD PTR [ebx+0x108]
  62e67d:	8b 11                	mov    edx,DWORD PTR [ecx]
  62e67f:	8b 82 c8 00 00 00    	mov    eax,DWORD PTR [edx+0xc8]
  62e685:	ff d0                	call   eax
  62e687:	e9 cd 00 00 00       	jmp    0x62e759
```

## 6. 玩家情境與雙向封包／相容 Server 需求矩陣

| 玩家情境 | Client native gate | C→S | S→C | Client 本地效果 | Server 開發與 unknown | 證據等級 |
|---|---|---|---|---|---|---|
| 操作帶 `EBX+0x14` key 的 Quest 相關入口 | `[FB114C]` map lookup 成功，`node+0x10`、payload+0x28 | unknown | unknown | `0x636520` 初始化控制器→`0x596E00` 互動 | 實際 UI / 玩家操作分類與 outbound protocol 未明 | 原生部分確認 |
| 3-slot 模式引發 `0x596EC0` | `[ESI+5] !=0`、`[FBA798]==0` 並未被其他前置 gate 擋下 | `0x00010049` 4-byte local virtual message，**wire 未證** | unknown | 寫入 `[EBX+0xB0]`、slot record、callback 等條件分支 | 需確認 vtable target→queue→socket；任務/非任務業務類型未定 | 條件性 native producer 確認／網路 unknown |
| 玩家接取任務、交付任務 | 真正 callback 尚未綁定 | unknown | unknown | 尚未確認動態 Quest cache writer | 原版 Server 決策不可推測 | unknown |
| Quest16→Quest15 | XML 與靜態 consumer 已知但無端到端收發 | unknown | unknown | 可接列表與下一章節開放未閉合 | 相容 Server 需以後續已證 packet 定義 | unknown |
| 重登恢復 Quest | P2，未追 | unknown | unknown | unknown | 不推論保存/恢復規則 | unknown |

## 7. 後續可交付入口與阻塞

1. `0x00FBA854` 之實際 vptr 寫入者與 vtable `+0x10` target；沿 `0x596FBA` 以原生機器碼確認 queue/frame/socket、4-byte local message namespace、是否確實出站，引用 T02 不篡改 T02。
2. `0x596E00` 的三組 slot 在 `0x848020` 的語義，`0x597250` 的更新與 `0x596EC0` 共同 writer/consumer；`0x636520` jump-table `0x636774` 每支 target 及 `[EDI+0x90]` mode 來源。
3. `0x5B6BE0`、`0x5B6D20` 等相鄰 caller／vtable type=0x105B9 的 UI/event 來源；確認是否真與 Quest NPC 操作有關，再以 event ID 連回具體 UI 控件。`0x62E579→0x759ED0` 文字方向可作比對，但本段未閉合其 UI 類型。
4. 從 T02 receive parser 找 Quest 有證據的 S→C 分派→handler→Quest dynamic cache writer→NPC/UI consumer；沒有 server/trace 不猜 opcode。
5. 若靜態 BIN 難以解出動態 virtual type，交由本地只讀 class metadata / Ghidra vtable xref 補證，要求交付 actual vptr init、target VA、callsite→queue path、wire bytes/length 條件；不得以 runtime fixture 代替 KR 原版。

## 8. 權限與交付狀態

未修改/執行原始 EXE/BIN；未修改任何 T02/T03/T04/T07/T08/T14/T15/owner/catalog/task.json。GitHub 本段分析 **沒有 Commit／Push**，只輸出這份可下載原稿。