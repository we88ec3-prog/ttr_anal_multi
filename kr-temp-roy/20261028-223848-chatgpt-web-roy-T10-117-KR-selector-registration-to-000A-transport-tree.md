# T10-117 — KR `000A` selector 0 對應連線的註冊 writer：Socket／IOCP → 連線樹 → 送包 lookup（BIN-first）

研究時間（Asia/Taipei）：20261028-223848。正式段號 **T10-117**。本次只靜態唯讀研究 KR 原始 PE，不執行、patch 或連線遊戲。GitHub 同步前最新 `main` 已由 PR #11 merge 到 `t10/roy/chatgpt-web`（merge `0272175ba201c8b32db124020b0cff9fe334b012`）。本次有明確授權提交完整研究到 **T10 分支**，不寫 main。

## 0. 實際來源和可重現邊界

- `Tartaros.bin` SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪重新計算）。
- `Tartaros.exe` SHA256：`03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`（本輪重新計算）。
- PE32 x86，`.text` VA `0x401000`／raw `0x400`，**`.text raw = VA - 0x400C00`**；`.rdata` VA `0xBD2000`／raw `0x7D0600`。FB/FE 等 runtime zero-fill 不能當成 BIN 原始值。
- 原生函式與位元組依下列 `objdump -D -Mintel` 指令窗口；既有 T10-115／116 作定位導航，不作本次第一手證據替身。
- 已讀 `02-PROJECT-SHARED-INSTRUCTIONS.md`、`03-PROJECT-T10-INSTRUCTIONS.md`；不修改 T02 或其他任務。

## 1. 第一輪重大增量：`0x806AD0` 確認是 manager selector 樹的 producer

此前 T10-115 確認 `0x545B71` 對 transport `0xFBA854` virtual `+0x10` 傳 `(selector=0, pointer=0xFE38D0, length=0xFE48D0)`，在已確認的 `0xC51748` 虛表下進 `0x8069A0`，後者搜尋 `manager+0x18` 的 tree，存在 node+0x10 connection 才進 `0x8060D0 → 0x806060` pending list。當時尚缺這張 tree 的**實際寫入端**。

本段新確認：同一個虛表 `0xC51748+0x18` 指向 `0x806AD0`（參照 T10-114 原生表），此函式在 socket 初始化成功後將 `arg10` DWORD selector 對應到新連線物件，並對 `manager+0x18` tree 插入節點：

1. `0x806AD0` 從 `[ebp+8]` 取第一個 stack 參數保存在 ESI，`0x806B1B` 在 `0x805950` 配置／取得 connection 後保存 EBX。`0x806B25 mov eax,[ebp+0x14]` 是**第四個參數**，寫入 `connection+0xA080` 作 receive queue category；不能與 selector 混同。
2. socket 建構與 `bind` 類似步驟失敗走 `0x806BB6..806C13`，呼叫 `0x805AF0` 回收及返回 0，**不執行後續 tree insertion**。
3. 成功後 `0x806C7B..806C87` 將 socket 與 connection 指標交給 IAT `CreateIoCompletionPort`，使 key 指向該 connection。接著 `0x806C8D mov edi,[esp+0x14]` 取 transport manager context，`0x806C94 lea esi,[edi+0x18]` 取得**與 `0x8069A0` 完全相同的 manager tree 子物件**。
4. `0x806C91 lea eax,[ebp+0x10]` 對第三個 stack arg 取址；`0x806C9E call 0x8438C0` 將其作 key 查詢。`0x806CA7 cmp eax,[edi+0x1c]` 比較 sentinel；不相同則呼叫 `0x7B6890`（可能處理既有紀錄，其精確替換語義待核）。
5. `0x806CB8` 將第三參數 selector 值存到 local `[esp+0x14]`，`0x806CC3` 將新 connection EBX 存到 `[esp+0x18]`；`0x806CC7 call 0x57EF20` 配置 **0x18-byte** tree node 並由 caller 指向的兩個 DWORD 初始化 `node+0x0C` key、`node+0x10` value；`0x806CD2 call 0x57E850` 將 node 插入 tree，且有 key comparison / duplicate path。
6. `0x8069B0` 對同一 `manager+0x18` 使用 `0x8438C0`，`0x8069BF` 比對 `manager+0x1C` sentinel，`0x8069C5` 讀 `[node+0x10]` connection。這正是 writer 的 value 寫入地址，**不再只有未驗證的假設性 selector lookup**。

### 確定的物件／欄位表

| 物件／位址 | offset | 原生讀／寫證據 | 可確定意義 |
|---|---:|---|---|
| Transport manager（本研究已確認正常全域為 `0xFBA854`） | `+0x18` | `806C94 lea esi,[edi+18]`、`8069B1 lea ecx,[esi+18]` | 索引 tree |
| manager | `+0x1C` | `806CA7 cmp [edi+1c]`、`8069BF cmp [esi+1c]` | tree sentinel 指標 |
| tree node | `+0x0C` | `57EF54 mov [node+0xC],DWORD[keypair]`、`57E86F..` comparison | selector key DWORD |
| tree node | `+0x10` | `57EF59 mov [node+0x10],DWORD[keypair+4]`、`8069C5 mov ecx,[eax+10]` | connection 指標 |
| connection | `+0xA080` | `806B25 [ebp+14] → 806B33` | queue category，**不是 selector** |
| connection | `+0x0` | `806B8A mov [ebx],socket` | socket handle |
| connection | `+0xA030/+0xA050` | T10-111 WSARecv／WSASend 與 IOCP identity | read/send overlapped，與 category 不同 |

### 主題閉環與限制

```text
連線初始化 0x806AD0(manager; arg10=selector, arg14=queue category)
 ├─ 0x805950 → connection EBX
 ├─ socket/bind/setsockopt/IOCP bind 成功條件
 └─ manager+0x18 tree：查 selector
     ├─ 已有候選：0x7B6890 處理舊 node（替換細節未閉）
     └─ (node+0x0C)=selector, (node+0x10)=EBX
         0x57EF20 配 node → 0x57E850 插入

T10-115：0x5452C0 建 C2S 000A（6+5N bytes，N>0）
 → manager FBA854 virtual+0x10 → 0x8069A0(selector=0)
 → manager+0x18 tree lookup → node+0x10=connection
 → 0x8060D0 pending record → 0x8061A0 frame pump
 → manager virtual+0xC → 0x8068B0 → WSASend
```

**新增證據的準確說法**：已閉合「連線初始化 writer 對應戰鬥 output reader」的**原生資料結構與指標欄位**。但尚未從 `0x806AD0` caller 確認這次初始化傳入 `arg10=0`；不能把 selector0 一定存在寫成玩家實測。更不能把 `arg14` 的 queue category2 寫成 selector2 或 S→C opcode。

## 2. 呼叫及分支的反證

- `0x806B29 mov [ebx+A0B4],2` 是另一個 connection 狀態欄位；`0x806B33` 的 `[ebp+14]` category 可能為2也可能其他值。此常數2**不證**該連線一定入 category2。
- socket/bind 失敗的路徑呼叫 `0x805AF0`，沒有到 `0x806C91` tree writer。`CreateIoCompletionPort` 的失敗檢查是否完整本段未全審，不能宣稱所有執行皆成功入樹。
- `0x7B6890` 出現在重複 selector 情境；未作完整 tree node ownership／erase 生命週期，**不能聲稱必然用新 connection 取代舊 connection、亦不能聲稱無泄漏**。
- `0x57E850` 在比較 `node+0x0C` 後可走既有鍵不插入的路徑，`57E907` 把 resultFlag 設0；因此「呼叫 insert」不等於「每次都插入成功」。
- 本段尚未確認 `0x806AD0` 的具體虛呼叫 caller／third arg0 runtime，未定位 S→C 動作同步 key13 的完整玩家因果，不宣稱本地起手一定等待 Server。

## 3. 玩家情境與 Client ↔ Server 矩陣

| 玩家／連線情境 | Client gate／已確認 | C→S | S→C | Motion／玩家效果 | Server 責任、證據 |
|---|---|---|---|---|---|
| 站立單按 Z，bank 確有 Key44→ID13 | 按鍵 phase→controller bit0→`000A` row 受 UI／matrix／timer gate；本段未重新審所有 gate | builder 在 N>0、selector0 已註冊且 Pending / send gates 通過時，可到 `WSASend`；**尚未確認 selector0 runtime 建立** | 具體 Z 專屬回覆未知 | 本機預播／回覆後播未知 | 客戶端條件式路徑，非 Server acceptance 事實 |
| 初始化 selector=0 且 socket／tree 成功 | `806AD0 arg10=0` 時 node+0xC key0、node+0x10 為 connection | 可以供 `8069A0(selector0)` 查到連線；非自動送包 | 其 `arg14` category 是否2依 caller | 不直接啟動動畫 | 原生條件式 producer → consumer 已確認 |
| 重複 selector 初始化 | sentinel 分支與 `7B6890`／`57E850` | 實際 lookup 哪個 connection 取決於 tree 結果 | 不由這條支鏈決定 | 不直接證 motion | 重複處理細節 unknown |
| socket/bind 失敗 | `806BB6..806C13` cleanup 返回0 | 本次不入 tree，無該 connection 的新傳送 | 無本次連線的收包證據 | 不代表普攻被 gameplay 判拒 | native failure branch |
| 長按／重按／放開 Z 或施放中 Z | 本段未新增 phase gating | 次數與允許時機 unknown | unknown | combo/cancel unknown | 不用虛構 0.65s 時窗 |
| 施放中鍵盤／滑鼠移動 | 分開追 producer | unknown | unknown | unknown | 待後段 |

## 4. 深入輪次與接棒

第 **1 輪**已獲實質重大新發現：由原生 `0x806AD0 → 0x8438C0 → 0x57EF20 → 0x57E850` 定位**與 `0x8069A0` 完全相同 tree** 的 writer，明確對接 `node+0x0C` selector 和 `node+0x10` connection，補足 T10-115 selector0 lookup 缺 writer 的技術缺口。符合 02 重大新發現門檻，所以 T10-117-2／117-3 **未啟動**；不代表 T10 玩家普攻整體完成。

下一正式段 **T10-118**：優先從 transport `0xC51748 +0x18` (`0x806AD0`) 的真實 caller 證明 `arg10=0` 以及 `arg14` category（應用分類），對照 connect lifecycle；其次從 `000A` 第2 WORD `virtual+0x58` 的具體物件 RTTI/vtable 尋找值的定義；再核 S→C key13 motion 與本地 actor 是否預播。只要未找到 Server 第一手資料，不造原版 ACK 規則。

## 5. BIN 原生反組譯附錄

下列全部指令由本次重新 objdump，並保留 raw=VA−0x400C00；並未執行 Ghidra 或宣稱整函式 FULL-PASS。

### connection constructor and category writer — VA 0x00806ad0..0x00806b4f; raw 0x00405ed0..0x00405f4f

```asm
00806ad0 <.text+0x405ad0>:
  806ad0:	55                   	push   ebp
  806ad1:	8b ec                	mov    ebp,esp
  806ad3:	83 e4 f8             	and    esp,0xfffffff8
  806ad6:	83 ec 24             	sub    esp,0x24
  806ad9:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  806ade:	33 c4                	xor    eax,esp
  806ae0:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  806ae4:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  806aeb:	53                   	push   ebx
  806aec:	56                   	push   esi
  806aed:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  806af0:	57                   	push   edi
  806af1:	8b f9                	mov    edi,ecx
  806af3:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  806af7:	75 15                	jne    0x806b0e
  806af9:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  806b00:	74 07                	je     0x806b09
  806b02:	e8 59 44 c9 ff       	call   0x49af60
  806b07:	eb 05                	jmp    0x806b0e
  806b09:	e8 f2 44 c9 ff       	call   0x49b000
  806b0e:	8b 0d 58 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba858
  806b14:	6a 01                	push   0x1
  806b16:	e8 35 ee ff ff       	call   0x805950
  806b1b:	8b d8                	mov    ebx,eax
  806b1d:	85 db                	test   ebx,ebx
  806b1f:	0f 84 b2 01 00 00    	je     0x806cd7
  806b25:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  806b28:	56                   	push   esi
  806b29:	c7 83 b4 a0 00 00 02 	mov    DWORD PTR [ebx+0xa0b4],0x2
  806b30:	00 00 00 
  806b33:	89 83 80 a0 00 00    	mov    DWORD PTR [ebx+0xa080],eax
  806b39:	ff 15 c0 25 bd 00    	call   DWORD PTR ds:0xbd25c0
  806b3f:	0f bf 48 0a          	movsx  ecx,WORD PTR [eax+0xa]
  806b43:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  806b46:	8b 02                	mov    eax,DWORD PTR [edx]
  806b48:	51                   	push   ecx
  806b49:	50                   	push   eax
  806b4a:	8d 4c 24 28          	lea    ecx,[esp+0x28]
  806b4e:	51                   	push   ecx
```

### socket setup and tree registration — VA 0x00806b54..0x00806cd7; raw 0x00405f54..0x004060d7

```asm
00806b54 <.text+0x405b54>:
  806b54:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  806b57:	83 c4 0c             	add    esp,0xc
  806b5a:	ba 02 00 00 00       	mov    edx,0x2
  806b5f:	50                   	push   eax
  806b60:	66 89 54 24 20       	mov    WORD PTR [esp+0x20],dx
  806b65:	ff 15 a8 25 bd 00    	call   DWORD PTR ds:0xbd25a8
  806b6b:	6a 01                	push   0x1
  806b6d:	6a 00                	push   0x0
  806b6f:	6a 00                	push   0x0
  806b71:	6a 00                	push   0x0
  806b73:	6a 01                	push   0x1
  806b75:	6a 02                	push   0x2
  806b77:	66 89 44 24 36       	mov    WORD PTR [esp+0x36],ax
  806b7c:	ff 15 d0 25 bd 00    	call   DWORD PTR ds:0xbd25d0
  806b82:	6a 10                	push   0x10
  806b84:	8d 4c 24 20          	lea    ecx,[esp+0x20]
  806b88:	51                   	push   ecx
  806b89:	50                   	push   eax
  806b8a:	89 03                	mov    DWORD PTR [ebx],eax
  806b8c:	ff 15 c4 25 bd 00    	call   DWORD PTR ds:0xbd25c4
  806b92:	83 f8 ff             	cmp    eax,0xffffffff
  806b95:	75 7f                	jne    0x806c16
  806b97:	83 7f 58 00          	cmp    DWORD PTR [edi+0x58],0x0
  806b9b:	74 19                	je     0x806bb6
  806b9d:	ff 15 cc 25 bd 00    	call   DWORD PTR ds:0xbd25cc
  806ba3:	8b 7f 58             	mov    edi,DWORD PTR [edi+0x58]
  806ba6:	50                   	push   eax
  806ba7:	68 ac 16 c5 00       	push   0xc516ac
  806bac:	6a 02                	push   0x2
  806bae:	e8 4d 98 ee ff       	call   0x6f0400
  806bb3:	83 c4 0c             	add    esp,0xc
  806bb6:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  806bbd:	75 35                	jne    0x806bf4
  806bbf:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  806bc6:	74 27                	je     0x806bef
  806bc8:	e8 93 43 c9 ff       	call   0x49af60
  806bcd:	8b 35 58 a8 fb 00    	mov    esi,DWORD PTR ds:0xfba858
  806bd3:	53                   	push   ebx
  806bd4:	e8 17 ef ff ff       	call   0x805af0
  806bd9:	33 c0                	xor    eax,eax
  806bdb:	5f                   	pop    edi
  806bdc:	5e                   	pop    esi
  806bdd:	5b                   	pop    ebx
  806bde:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  806be2:	33 cc                	xor    ecx,esp
  806be4:	e8 18 a4 08 00       	call   0x891001
  806be9:	8b e5                	mov    esp,ebp
  806beb:	5d                   	pop    ebp
  806bec:	c2 10 00             	ret    0x10
  806bef:	e8 0c 44 c9 ff       	call   0x49b000
  806bf4:	8b 35 58 a8 fb 00    	mov    esi,DWORD PTR ds:0xfba858
  806bfa:	53                   	push   ebx
  806bfb:	e8 f0 ee ff ff       	call   0x805af0
  806c00:	33 c0                	xor    eax,eax
  806c02:	5f                   	pop    edi
  806c03:	5e                   	pop    esi
  806c04:	5b                   	pop    ebx
  806c05:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  806c09:	33 cc                	xor    ecx,esp
  806c0b:	e8 f1 a3 08 00       	call   0x891001
  806c10:	8b e5                	mov    esp,ebp
  806c12:	5d                   	pop    ebp
  806c13:	c2 10 00             	ret    0x10
  806c16:	8b 33                	mov    esi,DWORD PTR [ebx]
  806c18:	8b 3d ac 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25ac
  806c1e:	6a 04                	push   0x4
  806c20:	8d 54 24 14          	lea    edx,[esp+0x14]
  806c24:	52                   	push   edx
  806c25:	6a 01                	push   0x1
  806c27:	6a 06                	push   0x6
  806c29:	56                   	push   esi
  806c2a:	c7 44 24 24 00 00 00 	mov    DWORD PTR [esp+0x24],0x0
  806c31:	00 
  806c32:	ff d7                	call   edi
  806c34:	83 f8 ff             	cmp    eax,0xffffffff
  806c37:	74 c7                	je     0x806c00
  806c39:	6a 04                	push   0x4
  806c3b:	8d 44 24 14          	lea    eax,[esp+0x14]
  806c3f:	50                   	push   eax
  806c40:	68 02 10 00 00       	push   0x1002
  806c45:	68 ff ff 00 00       	push   0xffff
  806c4a:	56                   	push   esi
  806c4b:	c7 44 24 24 00 40 00 	mov    DWORD PTR [esp+0x24],0x4000
  806c52:	00 
  806c53:	ff d7                	call   edi
  806c55:	83 f8 ff             	cmp    eax,0xffffffff
  806c58:	74 a6                	je     0x806c00
  806c5a:	6a 04                	push   0x4
  806c5c:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  806c60:	51                   	push   ecx
  806c61:	68 01 10 00 00       	push   0x1001
  806c66:	68 ff ff 00 00       	push   0xffff
  806c6b:	56                   	push   esi
  806c6c:	c7 44 24 24 00 80 00 	mov    DWORD PTR [esp+0x24],0x8000
  806c73:	00 
  806c74:	ff d7                	call   edi
  806c76:	83 f8 ff             	cmp    eax,0xffffffff
  806c79:	74 85                	je     0x806c00
  806c7b:	e8 a0 f9 ff ff       	call   0x806620
  806c80:	8b 10                	mov    edx,DWORD PTR [eax]
  806c82:	6a 00                	push   0x0
  806c84:	53                   	push   ebx
  806c85:	52                   	push   edx
  806c86:	56                   	push   esi
  806c87:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
  806c8d:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  806c91:	8d 45 10             	lea    eax,[ebp+0x10]
  806c94:	8d 77 18             	lea    esi,[edi+0x18]
  806c97:	50                   	push   eax
  806c98:	8d 44 24 18          	lea    eax,[esp+0x18]
  806c9c:	8b ce                	mov    ecx,esi
  806c9e:	e8 1d cc 03 00       	call   0x8438c0
  806ca3:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  806ca7:	3b 47 1c             	cmp    eax,DWORD PTR [edi+0x1c]
  806caa:	74 0c                	je     0x806cb8
  806cac:	50                   	push   eax
  806cad:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  806cb1:	51                   	push   ecx
  806cb2:	56                   	push   esi
  806cb3:	e8 d8 fb fa ff       	call   0x7b6890
  806cb8:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  806cbb:	8d 7c 24 14          	lea    edi,[esp+0x14]
  806cbf:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  806cc3:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  806cc7:	e8 54 82 d7 ff       	call   0x57ef20
  806ccc:	50                   	push   eax
  806ccd:	56                   	push   esi
  806cce:	8d 74 24 1c          	lea    esi,[esp+0x1c]
  806cd2:	e8 79 7b d7 ff       	call   0x57e850
```

### selector lookup and pending enqueue — VA 0x008069a0..0x008069f5; raw 0x00405da0..0x00405df5

```asm
008069a0 <.text+0x4059a0>:
  8069a0:	55                   	push   ebp
  8069a1:	8b ec                	mov    ebp,esp
  8069a3:	51                   	push   ecx
  8069a4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8069a7:	56                   	push   esi
  8069a8:	8b f1                	mov    esi,ecx
  8069aa:	8d 4d 08             	lea    ecx,[ebp+0x8]
  8069ad:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  8069b0:	51                   	push   ecx
  8069b1:	8d 4e 18             	lea    ecx,[esi+0x18]
  8069b4:	8d 45 fc             	lea    eax,[ebp-0x4]
  8069b7:	e8 04 cf 03 00       	call   0x8438c0
  8069bc:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  8069bf:	3b 46 1c             	cmp    eax,DWORD PTR [esi+0x1c]
  8069c2:	5e                   	pop    esi
  8069c3:	74 07                	je     0x8069cc
  8069c5:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  8069c8:	85 c9                	test   ecx,ecx
  8069ca:	75 08                	jne    0x8069d4
  8069cc:	33 c0                	xor    eax,eax
  8069ce:	8b e5                	mov    esp,ebp
  8069d0:	5d                   	pop    ebp
  8069d1:	c2 0c 00             	ret    0xc
  8069d4:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  8069d7:	85 c0                	test   eax,eax
  8069d9:	75 0b                	jne    0x8069e6
  8069db:	b8 01 00 00 00       	mov    eax,0x1
  8069e0:	8b e5                	mov    esp,ebp
  8069e2:	5d                   	pop    ebp
  8069e3:	c2 0c 00             	ret    0xc
  8069e6:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  8069e9:	50                   	push   eax
  8069ea:	52                   	push   edx
  8069eb:	e8 e0 f6 ff ff       	call   0x8060d0
  8069f0:	8b e5                	mov    esp,ebp
  8069f2:	5d                   	pop    ebp
  8069f3:	c2 0c              	ret    0xc
```

### key/value node allocation — VA 0x0057ef20..0x0057ef60; raw 0x0017e320..0x0017e360

```asm
0057ef20 <.text+0x17df20>:
  57ef20:	55                   	push   ebp
  57ef21:	8b ec                	mov    ebp,esp
  57ef23:	83 ec 10             	sub    esp,0x10
  57ef26:	6a 18                	push   0x18
  57ef28:	e8 3b 23 31 00       	call   0x891268
  57ef2d:	33 d2                	xor    edx,edx
  57ef2f:	83 c4 04             	add    esp,0x4
  57ef32:	3b c2                	cmp    eax,edx
  57ef34:	74 2a                	je     0x57ef60
  57ef36:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  57ef39:	89 08                	mov    DWORD PTR [eax],ecx
  57ef3b:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  57ef3e:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  57ef41:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  57ef44:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  57ef47:	8d 48 0c             	lea    ecx,[eax+0xc]
  57ef4a:	66 89 50 14          	mov    WORD PTR [eax+0x14],dx
  57ef4e:	3b ca                	cmp    ecx,edx
  57ef50:	74 0a                	je     0x57ef5c
  57ef52:	8b 17                	mov    edx,DWORD PTR [edi]
  57ef54:	89 11                	mov    DWORD PTR [ecx],edx
  57ef56:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  57ef59:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  57ef5c:	8b e5                	mov    esp,ebp
  57ef5e:	5d                   	pop    ebp
  57ef5f:	c3                   	ret
```

### key comparison and tree insertion — VA 0x0057e850..0x0057e916; raw 0x0017dc50..0x0017dd16

```asm
0057e850 <.text+0x17d850>:
  57e850:	55                   	push   ebp
  57e851:	8b ec                	mov    ebp,esp
  57e853:	83 ec 08             	sub    esp,0x8
  57e856:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  57e859:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  57e85c:	53                   	push   ebx
  57e85d:	57                   	push   edi
  57e85e:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  57e861:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  57e864:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  57e868:	b1 01                	mov    cl,0x1
  57e86a:	88 4d f8             	mov    BYTE PTR [ebp-0x8],cl
  57e86d:	75 1f                	jne    0x57e88e
  57e86f:	8b 5a 0c             	mov    ebx,DWORD PTR [edx+0xc]
  57e872:	3b 58 0c             	cmp    ebx,DWORD PTR [eax+0xc]
  57e875:	8b f8                	mov    edi,eax
  57e877:	0f 9c c1             	setl   cl
  57e87a:	88 4d f8             	mov    BYTE PTR [ebp-0x8],cl
  57e87d:	84 c9                	test   cl,cl
  57e87f:	74 04                	je     0x57e885
  57e881:	8b 00                	mov    eax,DWORD PTR [eax]
  57e883:	eb 03                	jmp    0x57e888
  57e885:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  57e888:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  57e88c:	74 e4                	je     0x57e872
  57e88e:	8b df                	mov    ebx,edi
  57e890:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  57e893:	84 c9                	test   cl,cl
  57e895:	74 3a                	je     0x57e8d1
  57e897:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  57e89a:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  57e89d:	3b 38                	cmp    edi,DWORD PTR [eax]
  57e89f:	75 22                	jne    0x57e8c3
  57e8a1:	52                   	push   edx
  57e8a2:	6a 01                	push   0x1
  57e8a4:	8d 55 0c             	lea    edx,[ebp+0xc]
  57e8a7:	8b c7                	mov    eax,edi
  57e8a9:	52                   	push   edx
  57e8aa:	8b f9                	mov    edi,ecx
  57e8ac:	e8 4f d4 ec ff       	call   0x44bd00
  57e8b1:	8b 00                	mov    eax,DWORD PTR [eax]
  57e8b3:	5f                   	pop    edi
  57e8b4:	89 06                	mov    DWORD PTR [esi],eax
  57e8b6:	c6 46 04 01          	mov    BYTE PTR [esi+0x4],0x1
  57e8ba:	8b c6                	mov    eax,esi
  57e8bc:	5b                   	pop    ebx
  57e8bd:	8b e5                	mov    esp,ebp
  57e8bf:	5d                   	pop    ebp
  57e8c0:	c2 08 00             	ret    0x8
  57e8c3:	8d 45 fc             	lea    eax,[ebp-0x4]
  57e8c6:	e8 d5 0f fc ff       	call   0x53f8a0
  57e8cb:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  57e8ce:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  57e8d1:	8b 4b 0c             	mov    ecx,DWORD PTR [ebx+0xc]
  57e8d4:	52                   	push   edx
  57e8d5:	3b 4a 0c             	cmp    ecx,DWORD PTR [edx+0xc]
  57e8d8:	7d 24                	jge    0x57e8fe
  57e8da:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  57e8dd:	52                   	push   edx
  57e8de:	8d 45 0c             	lea    eax,[ebp+0xc]
  57e8e1:	50                   	push   eax
  57e8e2:	8b c7                	mov    eax,edi
  57e8e4:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  57e8e7:	e8 14 d4 ec ff       	call   0x44bd00
  57e8ec:	8b 08                	mov    ecx,DWORD PTR [eax]
  57e8ee:	5f                   	pop    edi
  57e8ef:	89 0e                	mov    DWORD PTR [esi],ecx
  57e8f1:	c6 46 04 01          	mov    BYTE PTR [esi+0x4],0x1
  57e8f5:	8b c6                	mov    eax,esi
  57e8f7:	5b                   	pop    ebx
  57e8f8:	8b e5                	mov    esp,ebp
  57e8fa:	5d                   	pop    ebp
  57e8fb:	c2 08 00             	ret    0x8
  57e8fe:	e8 09 29 31 00       	call   0x89120c
  57e903:	83 c4 04             	add    esp,0x4
  57e906:	5f                   	pop    edi
  57e907:	89 1e                	mov    DWORD PTR [esi],ebx
  57e909:	c6 46 04 00          	mov    BYTE PTR [esi+0x4],0x0
  57e90d:	8b c6                	mov    eax,esi
  57e90f:	5b                   	pop    ebx
  57e910:	8b e5                	mov    esp,ebp
  57e912:	5d                   	pop    ebp
  57e913:	c2 08 00             	ret    0x8
```