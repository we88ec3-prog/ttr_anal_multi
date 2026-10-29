# E46 — RR-0005／KR T02：把「圖形/通用管理器 +4」與實際收包 Client 分離，驗證 Conn 預設 mode=2、第一個 local payload 的條件式 0BBB/1A68 出線路徑（研究目標導向十大子段）

**研究者**：chatgpt-web roy；**實際研究紀錄時間**：`2026-10-30T00:21:19+08:00`；**正式段號 E46**。E46.1–E46.10 是同一正式段號內 **10 個研究子段**，不是 10 個新正式段號。**停止條件 B（第10子段）**：完整登入→初始實際 wire 和首次 S2C 的 live 時序仍缺可驗證 runtime trace，不能因本段的新 native 發現便提前宣稱研究目標 A。使用者本次只要求繼續，**沒有 Commit/Push 授權**；本稿保存在本機可下載 Markdown，不修改 GitHub/RR 台帳。

**研究目標（端到端）**：對前段 E44/E45 的 `S2C 0x0013/0x007A → IPv4 endpoint/FE1B54 → UI → 0x4957C0(key0/key2) → C2S 0x0001(57B) → framing→WSASend/IOCP→callback` 連通作**物件身分排錯、預設 framing 動作驗證、成功/失敗條件補強**，並盡可能判定 first-wire 與下一個畫面的 Client 前置條件。先檢驗 E43–E45 說 `6E4F90` 可證 `manager+4=C+8` 的暗示；該 manager 可能不是同一個網路 manager，故嚴禁拿其 +4 與其他 Client offset 強行相等。

**第一手資料**：唯讀 `/mnt/data/Tartaros.bin`，大小 `12,472,320` bytes、SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本段實際重新計算）；PE32 i386：`.text` RVA 0x1000/raw 0x400，ImageBase 0x400000，故 `.text` VA−raw `0x400C00`；`.rdata` VA 0xBD2000/raw 0x7D0600，`.data` VA 0xD61000/raw 0x95E800。機器碼直接由 `objdump -d -M intel --start-address=... --stop-address=... Tartaros.bin` 取得，本文顯示第一手 bytes/ASM；E40–E45 為導覽與前述限定結論，不冒充本輪新發現。未執行/附加/patch 原始 Client；沒有官方 Server、pcap、runtime 調試值、Playtest。`N=本輪 BIN 已核實`、`C=條件式原生鏈`、`H=假說`、`U=缺證`；不自動滿足 T01 FULL-PASS、RR ACCEPTED 或可玩。

**GitHub 研究狀態**：同一對話沿用前次驗證的 `main=43c51f579cada3aa6257eb8467f65af281c3585b`（E41 開工基準）及 E45 提交後 `extra/roy1=7905e8e189f50463e89b8d35bcf531c19a447a41`。本段未重新抓取 main；這是**上次已核狀態，不宣稱現在最新遠端**。RR-0005 依上次台帳為 `KR/T02/P0, status=PENDING, dispatch=QUEUED, claim=null, submission=null`，本次仍不正式認領。**本地 E46 未 Commit／Push**。

## 全段研究增量、證據界線

1. **重大反證/身份釐清（N）**：`0x6E4F90` 的第二個 stack 參數 `[ebp+0xC]` 被保存進 `local-0x208`，`0x6E5530` 以它作 `ECX` 呼叫 `0x6E65A0`。此 helper 的正向 writer `0x6E6871` 寫 `[FBA7CC_manager+4]`，value 在 **ECX非零** 時為傳入指標（經 vptr+4 呼叫），而在 **ECX為零** 時可以是先前 vptr+0x40 **out-parameter** 生成的值。多個 `0x6E4F90` caller 第二 stack arg 明確傳零，故**不能由 `manager+4` 有正向 writer 推論它就是 `C+8`**。它不參與 E40 已驗的 `0x491983→0x804740→0x80486D` 直接主循環回呼鏈，需把歷史跨容器聯想降級，不能誤說 runtime 必定是 Client。
2. **framing 預設值的具體補證（N）**：新 Conn 初始化 `0x805D02` **寫 `BYTE [Conn+A02C]=2`**，而 `0x805F50` reset *沒有*覆寫 A02C，只重設 A080=2。`0x806202` 讀 signed A02C，零走 `0x807A70(1A68)`，非零進 `0x807830(0BBB)`，後者失敗可 fallback plain。先前只說 mode0/nonzero 未確認 default 的報告須以 `mode=2` 的直接 writer 釐清；**無 alias/後續改寫完整證據，不能宣稱每個 wire frame 都 0BBB**。
3. **encoded 首候選 frame header bytes（N/C）**：`0x807830` 在正常成功路徑組合 **`[LE16 payload_len][LE16 0x0BBB][LE16 checksum][encoded payload]`**，其中 `0x7D81` 是 stack 暫存初始化的一部分，最後 `0x8079F8` 以 checksum 覆寫後兩 bytes，**不可誤稱 wire magic 為完整 DWORD `0x7D810BBB`**。對本地 57B `0x0001`，若 mode2、無前置待送、buffer 有餘裕且加擾成功，**候選 63B frame**，前四個 bytes `39 00 BB 0B`，checksum 與加擾 payload 取決於實際資料。若 encoder fail、可能改走 `0x1A68` plaintext 61B frame；都不是實際 first-wire 的時序證據。
4. **Connect 與業務 data 的嚴格分離（N/C）**：`0x4957C0` 一次建 key0 `0x20E0`、key2 `0x20DE`，只有兩者非NULL 才建 `0x0001/0x39` local payload；當第一條 key0 非NULL、第二條 NULL 時會呼叫 manager virtual+0x20 對 key0 作處置，返回0；第一條 key0 NULL 時若 key2 已非NULL，也存在對 key2 處置的後續分支，不能把部分成功視為兩 socket 都已完成。
5. **尚缺（U）**：未得到證據讓整體宣告第一個 **WSASend**、第一個**實際網路傳輸**、第一個**S2C command** 的精確順序；`F94294` 初始化零且唯一直接地址 write/read，alias 非零 writer 不知；`0x0013` 分支缺完整 payload length/NUL 安全證據。不能以未知 Server 原版政策補齊。

## 研究方法、否證涵蓋

- **實際靜態直接引用掃描**：只在 BIN `.text` raw `[0x400,0x7D0600)` 逐位元組搜尋 `LE32 0xA02C`，得到 operand 位址 `0x805D04`、`0x806205`，對應精確的 `0x805D02` writer 與 `0x806202` reader；`LE32 0xF94294` 得 `0x4E16C1`、`0x66C180`，對應直接清零和 gate read。這是**direct literal operand** 覆蓋，絕非所有由指標別名/ memcpy/ thunk 或跨模組 API 的全域等價推證。
- 透過 `_e42_text_dump.txt` 的原件反組譯索引另確認多個 direct CALL `0x6E4F90`：`0x6E2DFC,0x6E31CC,0x6E326E,0x6E359D,0x6E3637,0x6E5457,0x6E5A55,0x6E76A6,0x6E7C2E,0x6E7E72,0x6E7EE0,0x6EABC3`；按樣本 caller 的實際 `push` 解析，至少 6E31CC（EBX 在 6E2E49 清為0）、6E359D、6E7E72 第二參數為0。這是**上游參數身份的反證**，不是「12 個 caller 全部逐路徑到 manager+4 同一值」的保證。

## E46.1 — 反向追查 6E4F90 的正式 stack ABI 與 caller：「第二參數」不能先驗定為 Client

**研究問題**：E43 E45 對 `6E4F90` 第二參數是否可以直接說明 `manager+4=C+8`？入口在何處保存它、哪些 caller 將其設為零、哪些跳向 callback provider？

**N / 分支模型**：`6E4FA3 mov eax,[ebp+0xC]; 6E4FAA mov [ebp-0x208],eax` 保存**第二個** stack 參數，後續 `6E552A mov ecx,[ebp-0x208]` → `6E5530 call 6E65A0`，沒有 `lea Client+8` 中間指令。`6E5457` 的 recursive 呼叫從 local-208 將此參數原樣轉傳。上游多個獨立 caller（例如 `6E31CC`）以五個 `push` 後呼叫 `6E4F90`，由最右至左的 x86 stack convention，倒數第二個 `push EBX` 是第二參數，該 caller 的 EBX 在 `6E2E49 xor ebx,ebx` 設為0；另有 caller 直接使用 `push 0`。故在那些分支，+4 的來源不是一個非零 `C+8`；另有非零 caller、外部 vtable out-parameter，不能反推它**永遠**是零。

**否證**：這些 caller 很多沒有任何 `0x490FE0`、`0x804740`、`0xFBA854` 的直接同函式資料傳遞；不能僅以 FBA7CC 同屬全域單例判定網路 callback。**後續**：對必要窗口應追 active instance 的 call stack；若未獲執行授權，結論僅限定靜態參數路徑。

**新增 caller EBX 來源驗證：`0x6E2E49`**（單一函式 prologue 清0，後段 6E31CC 才 push EBX）：

```asm
  6e2e37:	00 00                	add    BYTE PTR [eax],al
  6e2e39:	00 53 56             	add    BYTE PTR [ebx+0x56],dl
  6e2e3c:	8d 44 24 54          	lea    eax,[esp+0x54]
  6e2e40:	57                   	push   edi
  6e2e41:	50                   	push   eax
  6e2e42:	e8 99 76 00 00       	call   0x6ea4e0
  6e2e47:	8b f0                	mov    esi,eax
  6e2e49:	33 db                	xor    ebx,ebx
  6e2e4b:	b9 12 00 00 00       	mov    ecx,0x12
```

**第一手機器碼：6E4F90 第二參數保存與 manager 資源分支**（VA `0x6e4f90–0x6e502d`；`.text` raw 起點 `0x002E4390`）

```asm
  6e4f90:	55                   	push   ebp
  6e4f91:	8b ec                	mov    ebp,esp
  6e4f93:	81 ec 18 02 00 00    	sub    esp,0x218
  6e4f99:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6e4f9e:	33 c5                	xor    eax,ebp
  6e4fa0:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  6e4fa3:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  6e4fa6:	8b 4d 18             	mov    ecx,DWORD PTR [ebp+0x18]
  6e4fa9:	53                   	push   ebx
  6e4faa:	89 85 f8 fd ff ff    	mov    DWORD PTR [ebp-0x208],eax
  6e4fb0:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e4fb5:	56                   	push   esi
  6e4fb6:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  6e4fb9:	57                   	push   edi
  6e4fba:	89 8d f4 fd ff ff    	mov    DWORD PTR [ebp-0x20c],ecx
  6e4fc0:	85 c0                	test   eax,eax
  6e4fc2:	75 1f                	jne    0x6e4fe3
  6e4fc4:	68 80 13 00 00       	push   0x1380
  6e4fc9:	e8 9a c2 1a 00       	call   0x891268
  6e4fce:	83 c4 04             	add    esp,0x4
  6e4fd1:	85 c0                	test   eax,eax
  6e4fd3:	74 07                	je     0x6e4fdc
  6e4fd5:	e8 f6 a3 ff ff       	call   0x6df3d0
  6e4fda:	eb 02                	jmp    0x6e4fde
  6e4fdc:	33 c0                	xor    eax,eax
  6e4fde:	a3 cc a7 fb 00       	mov    ds:0xfba7cc,eax
  6e4fe3:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e4fea:	8b f8                	mov    edi,eax
  6e4fec:	74 0b                	je     0x6e4ff9
  6e4fee:	68 c8 a4 fb 00       	push   0xfba4c8
  6e4ff3:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  6e4ff9:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e5000:	8b 57 0c             	mov    edx,DWORD PTR [edi+0xc]
  6e5003:	89 95 f0 fd ff ff    	mov    DWORD PTR [ebp-0x210],edx
  6e5009:	74 0b                	je     0x6e5016
  6e500b:	68 c8 a4 fb 00       	push   0xfba4c8
  6e5010:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  6e5016:	c7 85 fc fd ff ff 00 	mov    DWORD PTR [ebp-0x204],0x0
  6e501d:	00 00 00 
  6e5020:	e8 5b ab ff ff       	call   0x6dfb80
  6e5025:	85 c0                	test   eax,eax
  6e5027:	0f 84 e9 00 00 00    	je     0x6e5116
```

**第一手機器碼：6E5457 recursive call 將第二參數透過 local-208 傳回**（VA `0x6e5442–0x6e545f`；`.text` raw 起點 `0x002E4842`）

```asm
  6e5442:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  6e5445:	8b 8d f8 fd ff ff    	mov    ecx,DWORD PTR [ebp-0x208]
  6e544b:	8d 95 fc fd ff ff    	lea    edx,[ebp-0x204]
  6e5451:	52                   	push   edx
  6e5452:	50                   	push   eax
  6e5453:	6a 01                	push   0x1
  6e5455:	51                   	push   ecx
  6e5456:	53                   	push   ebx
  6e5457:	e8 34 fb ff ff       	call   0x6e4f90
  6e545c:	83 c4 14             	add    esp,0x14
```

**第一手機器碼：6E31CC caller 五個 push，第二參數為零的實例**（VA `0x6e31c3–0x6e31de`；`.text` raw 起點 `0x002E25C3`）

```asm
  6e31c3:	53                   	push   ebx
  6e31c4:	53                   	push   ebx
  6e31c5:	53                   	push   ebx
  6e31c6:	8d 4c 24 1c          	lea    ecx,[esp+0x1c]
  6e31ca:	53                   	push   ebx
  6e31cb:	51                   	push   ecx
  6e31cc:	e8 bf 1d 00 00       	call   0x6e4f90
  6e31d1:	8b f8                	mov    edi,eax
  6e31d3:	83 c4 14             	add    esp,0x14
  6e31d6:	3b fb                	cmp    edi,ebx
  6e31d8:	0f 8d a1 00 00 00    	jge    0x6e327f
```

**第一手機器碼：6E7E72 caller 五個 push，第二參數為零的另一個實例**（VA `0x6e7e63–0x6e7e83`；`.text` raw 起點 `0x002E7263`）

```asm
  6e7e63:	6a 00                	push   0x0
  6e7e65:	6a 00                	push   0x0
  6e7e67:	6a 00                	push   0x0
  6e7e69:	8d 85 40 ff ff ff    	lea    eax,[ebp-0xc0]
  6e7e6f:	6a 00                	push   0x0
  6e7e71:	50                   	push   eax
  6e7e72:	e8 19 d1 ff ff       	call   0x6e4f90
  6e7e77:	83 c4 14             	add    esp,0x14
  6e7e7a:	85 c0                	test   eax,eax
  6e7e7c:	0f 89 cd 04 00 00    	jns    0x6e834f
  6e7e82:	e8                   	.byte 0xe8
```

## E46.2 — 6E65A0 的 ECX 非零／零雙來源，+4 writer 其實儲存何種值

**研究問題**：`6E6871 mov [edi+4],esi` 的 ESI 真實來自哪裡？能否從 BIN 說它是主遊戲 Client？

**N / CFG**：`6E65BB mov edi,ecx` 接收 `6E4F90` 第二 arg；`6E65BD mov [ebp-0xfc],0`。`6E6617 test edi,edi; jne 6E6813` 是關鍵轉折：若非零，`6E6813 mov ecx,[edi]`、`6E6815 mov edx,[ecx+4]`、`push edi; call edx`，再 `mov [ebp-0xfc],edi`，符合某介面引用計數形態，但缺 RTTI 不應擅叫 DirectX 或 CClient。若為零，走 `6E661F` 等輔助/回呼；`6E673D lea [ebp-0xfc]`, `push` output，經 `[edi+0x40]` 的 virtual function 可更改 local-0xFC，然後依 HRESULT-like return 與特殊 0x88760868/負值分支決定是否走至 writer。共同後段 `6E6850 mov esi,[ebp-0xfc]`、`6E6856 mov edi,eax (FBA7CC)`、`6E6871 mov [edi+4],esi`；**這是兩種可達來源，不是原始 C+8 的同義字**。

**N / 失敗/生命週期**：`6E6765` 特殊結果可寫 manager+0x328=1 早退；負值時 `6E67E9..6807` 返回 0x80040905 不經常規 writer；`6E9F9C` 才是 +4 清零，另有別的 callback slot 0x398/0x39C。**U**：若任一實際 caller 提供 C+8，仍須獨立 object identity 佐證；這份靜態分支不排除，只否定「所有情境均已證」。

**第一手機器碼：6E65A0 receiver、nonzero ECX/zero ECX 分支**（VA `0x6e65b3–0x6e6644`；`.text` raw 起點 `0x002E59B3`）

```asm
  6e65b3:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e65b8:	53                   	push   ebx
  6e65b9:	56                   	push   esi
  6e65ba:	57                   	push   edi
  6e65bb:	8b f9                	mov    edi,ecx
  6e65bd:	c7 85 04 ff ff ff 00 	mov    DWORD PTR [ebp-0xfc],0x0
  6e65c4:	00 00 00 
  6e65c7:	85 c0                	test   eax,eax
  6e65c9:	75 1f                	jne    0x6e65ea
  6e65cb:	68 80 13 00 00       	push   0x1380
  6e65d0:	e8 93 ac 1a 00       	call   0x891268
  6e65d5:	83 c4 04             	add    esp,0x4
  6e65d8:	85 c0                	test   eax,eax
  6e65da:	74 07                	je     0x6e65e3
  6e65dc:	e8 ef 8d ff ff       	call   0x6df3d0
  6e65e1:	eb 02                	jmp    0x6e65e5
  6e65e3:	33 c0                	xor    eax,eax
  6e65e5:	a3 cc a7 fb 00       	mov    ds:0xfba7cc,eax
  6e65ea:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e65f1:	8b f0                	mov    esi,eax
  6e65f3:	74 0b                	je     0x6e6600
  6e65f5:	68 c8 a4 fb 00       	push   0xfba4c8
  6e65fa:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  6e6600:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e6607:	8b 5e 0c             	mov    ebx,DWORD PTR [esi+0xc]
  6e660a:	74 0b                	je     0x6e6617
  6e660c:	68 c8 a4 fb 00       	push   0xfba4c8
  6e6611:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  6e6617:	85 ff                	test   edi,edi
  6e6619:	0f 85 f4 01 00 00    	jne    0x6e6813
  6e661f:	e8 5c 95 ff ff       	call   0x6dfb80
  6e6624:	8b 73 30             	mov    esi,DWORD PTR [ebx+0x30]
  6e6627:	89 85 fc fe ff ff    	mov    DWORD PTR [ebp-0x104],eax
  6e662d:	8b 43 40             	mov    eax,DWORD PTR [ebx+0x40]
  6e6630:	89 b5 f8 fe ff ff    	mov    DWORD PTR [ebp-0x108],esi
  6e6636:	89 85 00 ff ff ff    	mov    DWORD PTR [ebp-0x100],eax
  6e663c:	85 f6                	test   esi,esi
  6e663e:	0f 85 ee 00 00 00    	jne    0x6e6732
```

**第一手機器碼：6E65A0：out pointer 傳入 vptr+40與三種回傳**（VA `0x6e6732–0x6e677c`；`.text` raw 起點 `0x002E5B32`）

```asm
  6e6732:	8b 95 fc fe ff ff    	mov    edx,DWORD PTR [ebp-0x104]
  6e6738:	8b 3a                	mov    edi,DWORD PTR [edx]
  6e673a:	8b 53 0c             	mov    edx,DWORD PTR [ebx+0xc]
  6e673d:	8d 85 04 ff ff ff    	lea    eax,[ebp-0xfc]
  6e6743:	50                   	push   eax
  6e6744:	8d 4b 10             	lea    ecx,[ebx+0x10]
  6e6747:	51                   	push   ecx
  6e6748:	52                   	push   edx
  6e6749:	e8 c2 96 ff ff       	call   0x6dfe10
  6e674e:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  6e6750:	8b 95 fc fe ff ff    	mov    edx,DWORD PTR [ebp-0x104]
  6e6756:	50                   	push   eax
  6e6757:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  6e675a:	50                   	push   eax
  6e675b:	8b 47 40             	mov    eax,DWORD PTR [edi+0x40]
  6e675e:	51                   	push   ecx
  6e675f:	52                   	push   edx
  6e6760:	ff d0                	call   eax
  6e6762:	89 73 30             	mov    DWORD PTR [ebx+0x30],esi
  6e6765:	3d 68 08 76 88       	cmp    eax,0x88760868
  6e676a:	75 79                	jne    0x6e67e5
  6e676c:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e6771:	8b 8d 00 ff ff ff    	mov    ecx,DWORD PTR [ebp-0x100]
  6e6777:	89 4b 40             	mov    DWORD PTR [ebx+0x40],ecx
  6e677a:	85 c0                	test   eax,eax
```

**第一手機器碼：6E65A0：非零 interface AddRef-like、統一 writer**（VA `0x6e6808–0x6e688e`；`.text` raw 起點 `0x002E5C08`）

```asm
  6e6808:	8b 85 00 ff ff ff    	mov    eax,DWORD PTR [ebp-0x100]
  6e680e:	89 43 40             	mov    DWORD PTR [ebx+0x40],eax
  6e6811:	eb 0e                	jmp    0x6e6821
  6e6813:	8b 0f                	mov    ecx,DWORD PTR [edi]
  6e6815:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
  6e6818:	57                   	push   edi
  6e6819:	ff d2                	call   edx
  6e681b:	89 bd 04 ff ff ff    	mov    DWORD PTR [ebp-0xfc],edi
  6e6821:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e6826:	85 c0                	test   eax,eax
  6e6828:	75 1f                	jne    0x6e6849
  6e682a:	68 80 13 00 00       	push   0x1380
  6e682f:	e8 34 aa 1a 00       	call   0x891268
  6e6834:	83 c4 04             	add    esp,0x4
  6e6837:	85 c0                	test   eax,eax
  6e6839:	74 07                	je     0x6e6842
  6e683b:	e8 90 8b ff ff       	call   0x6df3d0
  6e6840:	eb 02                	jmp    0x6e6844
  6e6842:	33 c0                	xor    eax,eax
  6e6844:	a3 cc a7 fb 00       	mov    ds:0xfba7cc,eax
  6e6849:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e6850:	8b b5 04 ff ff ff    	mov    esi,DWORD PTR [ebp-0xfc]
  6e6856:	8b f8                	mov    edi,eax
  6e6858:	74 10                	je     0x6e686a
  6e685a:	68 c8 a4 fb 00       	push   0xfba4c8
  6e685f:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  6e6865:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e686a:	80 3d 09 3d d6 00 00 	cmp    BYTE PTR ds:0xd63d09,0x0
  6e6871:	89 77 04             	mov    DWORD PTR [edi+0x4],esi
  6e6874:	8b 3d 48 22 bd 00    	mov    edi,DWORD PTR ds:0xbd2248
  6e687a:	74 0c                	je     0x6e6888
  6e687c:	68 c8 a4 fb 00       	push   0xfba4c8
  6e6881:	ff d7                	call   edi
  6e6883:	a1 cc a7 fb 00       	mov    eax,ds:0xfba7cc
  6e6888:	83 7b 04 02          	cmp    DWORD PTR [ebx+0x4],0x2
  6e688c:	75 61                	jne    0x6e68ef
```

**第一手機器碼：6E9F9C 有界清零，非等價於網路 Client 析構**（VA `0x6e9f81–0x6e9fb8`；`.text` raw 起點 `0x002E9381`）

```asm
  6e9f81:	8b 35 cc a7 fb 00    	mov    esi,DWORD PTR ds:0xfba7cc
  6e9f87:	8b 3d 4c 22 bd 00    	mov    edi,DWORD PTR ds:0xbd224c
  6e9f8d:	38 1d 09 3d d6 00    	cmp    BYTE PTR ds:0xd63d09,bl
  6e9f93:	74 07                	je     0x6e9f9c
  6e9f95:	68 c8 a4 fb 00       	push   0xfba4c8
  6e9f9a:	ff d7                	call   edi
  6e9f9c:	89 5e 04             	mov    DWORD PTR [esi+0x4],ebx
  6e9f9f:	38 1d 09 3d d6 00    	cmp    BYTE PTR ds:0xd63d09,bl
  6e9fa5:	74 0b                	je     0x6e9fb2
  6e9fa7:	68 c8 a4 fb 00       	push   0xfba4c8
  6e9fac:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  6e9fb2:	38 5d 08             	cmp    BYTE PTR [ebp+0x8],bl
  6e9fb5:	0f                   	.byte 0xf
  6e9fb6:	84                   	.byte 0x84
  6e9fb7:	b1                   	.byte 0xb1
```

## E46.3 — 網路主迴圈的實際 callback holder 與 FBA7CC 隔離

**研究問題**：若管理器+4 并未證明 C+8，E40/E41 的收包 consumer 是否隨之失效？

**N**：沒有失效。`0x4A3041..0x4A305A` 直接在 stack 建 Client，`lea esi,[esp+0x34]` 得 C+8，進 `6DEB40` 註冊的是其他 manager callbacks；`0x48AC9A` 對 constructor 次級物件寫 `vptr=0xC05AEC`。獨立主迴圈 `0x49197F` 讀 `[esp+0x20]` 的 Client 座標，`lea ebx,[edi+0x140]` 送給 `0x804740`。在該函式 `0x804855` 把 callback holder 放 ECX/EBX，讀 `vptr[0]`，stack 入參為 `Conn* / payload / len / lane`，call dispatch。`+0x140` 對 `C+8` 座標轉換為 `C+0x148` 的結構關係由 E41 有界證明，但**ECX 與 EDI 活性/Client 型別來自 E41 主迴圈上下文**；這裡未自行把任意「管理器+4」搬進來。

**新責任界線**：`FBA7CC` 可稱一個另行分配 `0x1380` bytes 的通用 manager；**`FBA854` 是網路 vtable manager**。兩個全域位址不同，讀寫不同類型及欄位，不要因都叫 `manager` 而判等。`6DEB40` 註冊 FBA7CC+0x398 也不能當作 FBA7CC+4 具體身分。尚未核對經合法 live session 同時記錄 C+8 / callback vptr 的資料，因此「主迴圈實際執行了 0x4930E0」仍是 C 而非 runtime 已發生 N。

**分派載荷**：`0x80486D` 向 callback push 的 4 arguments 由 packet pool block+0/+4/+8 與 current lane 構成，不是 `6E4F90` 的五個 args。此 ABI 反證兩者是同一 callback signature 的說法。

**第一手機器碼：Client stack 物件及 C+8 註冊入口**（VA `0x4a3041–0x4a306b`；`.text` raw 起點 `0x000A2441`）

```asm
  4a3041:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  4a3045:	51                   	push   ecx
  4a3046:	e8 25 7b fe ff       	call   0x48ab70
  4a304b:	8d 74 24 34          	lea    esi,[esp+0x34]
  4a304f:	c7 84 24 c0 c0 00 00 	mov    DWORD PTR [esp+0xc0c0],0x1
  4a3056:	01 00 00 00 
  4a305a:	e8 e1 ba 23 00       	call   0x6deb40
  4a305f:	e8 dc bb 23 00       	call   0x6dec40
  4a3064:	8b fe                	mov    edi,esi
  4a3066:	e8 25 bc 23 00       	call   0x6dec90
```

**第一手機器碼：Client 次級 subobject vptr= C05AEC**（VA `0x48ac8c–0x48aca6`；`.text` raw 起點 `0x0008A08C`）

```asm
  48ac8c:	c7 87 00 02 00 00 38 	mov    DWORD PTR [edi+0x200],0xc05b38
  48ac93:	5b c0 00 
  48ac96:	c6 45 fc 07          	mov    BYTE PTR [ebp-0x4],0x7
  48ac9a:	c7 00 ec 5a c0 00    	mov    DWORD PTR [eax],0xc05aec
  48aca0:	c7 07 9c 5a c0 00    	mov    DWORD PTR [edi],0xc05a9c
```

**第一手機器碼：主迴圈從 Client 導出 callback holder**（VA `0x49197f–0x49198f`；`.text` raw 起點 `0x00090D7F`）

```asm
  49197f:	8b 7c 24 20          	mov    edi,DWORD PTR [esp+0x20]
  491983:	8d 9f 40 01 00 00    	lea    ebx,[edi+0x140]
  491989:	53                   	push   ebx
  49198a:	e8 b1 2d 37 00       	call   0x804740
```

**第一手機器碼：packet callback 真實 stack args 與 vptr slot0**（VA `0x804855–0x804872`；`.text` raw 起點 `0x00403C55`）

```asm
  804855:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  804858:	8b 13                	mov    edx,DWORD PTR [ebx]
  80485a:	8b 12                	mov    edx,DWORD PTR [edx]
  80485c:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  80485f:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  804862:	51                   	push   ecx
  804863:	50                   	push   eax
  804864:	8d 46 08             	lea    eax,[esi+0x8]
  804867:	50                   	push   eax
  804868:	8b 06                	mov    eax,DWORD PTR [esi]
  80486a:	50                   	push   eax
  80486b:	8b cb                	mov    ecx,ebx
  80486d:	ff d2                	call   edx
  80486f:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
```

## E46.4 — Conn+A02C 的「初始化 2」：和 A080 lane 2 不同、最小的 direct writer 覆蓋

**研究問題**：能否從第一手原件確認新 Conn mode 是 0、1、2 其中哪個？reset 有否改動？

**N**：`805D02: c6 86 2c a0 00 00 02` **精確寫 `[Conn+A02C]=2`（BYTE）**。之後 `805F50` reset 覆蓋 `A0AC`, `A024`, `A028`, `A020`, `A084..A0A4`, `A080=2` 等，但在這段原生 reset body **沒有**對 A02C 寫入。`A080` 是 32-bit app queue lane；`A02C` 是 `0x806202` 從 signed BYTE 讀出的 framing mode。新初始化時二者都可能值2，但**欄位不同、語意不同、reset 效果也不同**。

**direct-xref 覆蓋**：只在 `.text` native bytes 搜尋 `LE32(0xA02C)` 得 `0x805D04` / `0x806205` 兩處，反組譯確認是 805D02 literal writer、806202 literal reader。此不能證明無 `mov byte [ptr],x` 對 alias（例如 C-style pointer cast/後設 byte offset）或 bulk buffer overwrite。`0x806202` 的條件是 `mode==0` 走 plaintext `807A70`，`mode!=0` 到 `807830`；中間 `dec eax` 是對 1/2 的算術，但其分支又落同一 `807830`，因此 1 與 2 對這處的 framing choice 並無不同 native target。

**U**：仍欠 socket 建立後的間接 setter、外部 packet 協商、是否有失敗時重設 Conn 物件的 mode 且不經 constructor；不能宣稱 live first wire 必用 mode2。

**第一手機器碼：Conn 原生 constructor 設定 framing mode=2**（VA `0x805cf6–0x805d24`；`.text` raw 起點 `0x004050F6`）

```asm
  805cf6:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  805cfc:	89 be 1c 50 00 00    	mov    DWORD PTR [esi+0x501c],edi
  805d02:	c6 86 2c a0 00 00 02 	mov    BYTE PTR [esi+0xa02c],0x2
  805d09:	89 86 20 a0 00 00    	mov    DWORD PTR [esi+0xa020],eax
  805d0f:	88 9e 24 a0 00 00    	mov    BYTE PTR [esi+0xa024],bl
  805d15:	89 9e 28 a0 00 00    	mov    DWORD PTR [esi+0xa028],ebx
  805d1b:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  805d1e:	89 9e 4c a0 00 00    	mov    DWORD PTR [esi+0xa04c],ebx
```

**第一手機器碼：Conn reuse/reset 不寫 A02C、只重設 A080 lane2**（VA `0x805f50–0x805fda`；`.text` raw 起點 `0x00405350`）

```asm
  805f50:	c7 06 ff ff ff ff    	mov    DWORD PTR [esi],0xffffffff
  805f56:	33 c0                	xor    eax,eax
  805f58:	53                   	push   ebx
  805f59:	33 db                	xor    ebx,ebx
  805f5b:	89 9e ac a0 00 00    	mov    DWORD PTR [esi+0xa0ac],ebx
  805f61:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  805f64:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  805f67:	89 46 0c             	mov    DWORD PTR [esi+0xc],eax
  805f6a:	89 46 10             	mov    DWORD PTR [esi+0x10],eax
  805f6d:	89 5e 14             	mov    DWORD PTR [esi+0x14],ebx
  805f70:	8d 46 18             	lea    eax,[esi+0x18]
  805f73:	89 80 00 50 00 00    	mov    DWORD PTR [eax+0x5000],eax
  805f79:	88 9e 24 a0 00 00    	mov    BYTE PTR [esi+0xa024],bl
  805f7f:	89 9e 28 a0 00 00    	mov    DWORD PTR [esi+0xa028],ebx
  805f85:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  805f8b:	89 86 20 a0 00 00    	mov    DWORD PTR [esi+0xa020],eax
  805f91:	33 c0                	xor    eax,eax
  805f93:	89 86 84 a0 00 00    	mov    DWORD PTR [esi+0xa084],eax
  805f99:	89 86 88 a0 00 00    	mov    DWORD PTR [esi+0xa088],eax
  805f9f:	89 86 8c a0 00 00    	mov    DWORD PTR [esi+0xa08c],eax
  805fa5:	89 86 90 a0 00 00    	mov    DWORD PTR [esi+0xa090],eax
  805fab:	89 86 94 a0 00 00    	mov    DWORD PTR [esi+0xa094],eax
  805fb1:	89 86 98 a0 00 00    	mov    DWORD PTR [esi+0xa098],eax
  805fb7:	89 86 9c a0 00 00    	mov    DWORD PTR [esi+0xa09c],eax
  805fbd:	89 86 a0 a0 00 00    	mov    DWORD PTR [esi+0xa0a0],eax
  805fc3:	89 9e a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],ebx
  805fc9:	56                   	push   esi
  805fca:	89 9e a8 a0 00 00    	mov    DWORD PTR [esi+0xa0a8],ebx
  805fd0:	c7 86 80 a0 00 00 02 	mov    DWORD PTR [esi+0xa080],0x2
  805fd7:	00 00 00 
```

**第一手機器碼：scheduler 取得 signed mode，非零先嘗試 encoder**（VA `0x8061e6–0x80624f`；`.text` raw 起點 `0x004055E6`）

```asm
  8061e6:	8b 86 74 a0 00 00    	mov    eax,DWORD PTR [esi+0xa074]
  8061ec:	8b 18                	mov    ebx,DWORD PTR [eax]
  8061ee:	3b d8                	cmp    ebx,eax
  8061f0:	0f 84 c4 01 00 00    	je     0x8063ba
  8061f6:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  8061f9:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  8061fc:	8d 47 08             	lea    eax,[edi+0x8]
  8061ff:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  806202:	0f be 86 2c a0 00 00 	movsx  eax,BYTE PTR [esi+0xa02c]
  806209:	83 e8 00             	sub    eax,0x0
  80620c:	8d 8e 1c 50 00 00    	lea    ecx,[esi+0x501c]
  806212:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  806215:	89 55 e0             	mov    DWORD PTR [ebp-0x20],edx
  806218:	74 15                	je     0x80622f
  80621a:	48                   	dec    eax
  80621b:	74 01                	je     0x80621e
  80621d:	48                   	dec    eax
  80621e:	52                   	push   edx
  80621f:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  806222:	52                   	push   edx
  806223:	e8 08 16 00 00       	call   0x807830
  806228:	85 c0                	test   eax,eax
  80622a:	75 23                	jne    0x80624f
  80622c:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  80622f:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  806232:	52                   	push   edx
  806233:	50                   	push   eax
  806234:	8d be 1c 50 00 00    	lea    edi,[esi+0x501c]
  80623a:	e8 31 18 00 00       	call   0x807a70
  80623f:	85 c0                	test   eax,eax
  806241:	0f 95 c0             	setne  al
  806244:	84 c0                	test   al,al
  806246:	0f 84 58 01 00 00    	je     0x8063a4
  80624c:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
```

## E46.5 — 0BBB 封裝 header 順序、checksum 區與 mode0 fallback：first-wire 候選不等於觀察

**研究問題**：若這次新 Conn 保持 mode2，而且送出的是先前已知的 57-byte payload，究竟哪個 bytes 可以從 BIN 嚴格算出？

**N**：`80786D` 計算 `payload+6`，`807870` 先在 local 準備 DWORD `0x7D810BBB`；但 `80787A` 在這個 DWORD **之前兩 bytes** 寫 `payload len`，`8079EF` 將 `[local-0x101C]` 4 bytes 寫入輸出目的地，`8079F8` 將 `[local-0x1008]` checksum WORD 寫在 destination+4。故成功編碼封包真正前六 bytes = **[LE16 len][LE16 BB 0B][LE16 checksum]**，不要把局部的 DWORD 0x7D810BBB 全部誤搬為 wire header。body `8078FD` 開始以 XOR 程式轉換、`807A0E` copy。`0x807830` success 回傳 EAX=1；0/超 0x1000、環形 buffer 容量超 0x4000 或指標範圍不合法時回0，不一定 push output。`0x806228 test eax` fail → `0x807A70` plain formatter，成功 encoded 不落 fallback。

**C / 精確的可建模候選**：若 `len==57(0x39)`，encoded success 的 wire buffer（假設本次 buffer 空，且是最早 flushed packet）會是 `39 00 BB 0B ?? ?? [57 bytes encoded data]`，共 `57+6=63` bytes；未知 checksum 不是任意 Server 值，而由 payload bytes native 算出。mode0/fallback plain header 在 `807A8A`、`807AE9` 形成 `[LE16 len][LE16 0x1A68]` + payload，若 len57 則 61 bytes，開頭 `39 00 68 1A`；兩者都只是**條件下的固定框架推導**，不是已封包擷取的 wire。

**失敗分支**：`807887 cmp len+6,0x1000`、`807892 test len`、`8078A2 cmp buffer+len+6,0x4000`；plain 在 `807A97 cmp len+4,0x1000`, `807AA3 test len`, `807AB3 cmp buffer+len+4,0x4000`；因此前者拒絕/退回時可能後者仍允許，`0x807A70` 失敗後 `806246 je 8063A4`，不可把有 queued packet 說成必定已轉入 WSASend。

**U**：mainloop、socket queue、network scheduler 何時 flush、同一時刻前面有沒有舊 `0x007E`/其他 key packet，都未以 live trace 解答；條件式 header 不是第一條 wire 的充分證明。

**第一手機器碼：0BBB encoder：準備 len + magic + checksum slot 與 guard**（VA `0x807867–0x8078b6`；`.text` raw 起點 `0x00406C67`）

```asm
  807867:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  80786d:	8d 47 06             	lea    eax,[edi+0x6]
  807870:	c7 85 e6 ef ff ff bb 	mov    DWORD PTR [ebp-0x101a],0x7d810bbb
  807877:	0b 81 7d 
  80787a:	66 89 bd e4 ef ff ff 	mov    WORD PTR [ebp-0x101c],di
  807881:	89 85 d8 ef ff ff    	mov    DWORD PTR [ebp-0x1028],eax
  807887:	3d 00 10 00 00       	cmp    eax,0x1000
  80788c:	0f 87 bb 01 00 00    	ja     0x807a4d
  807892:	85 ff                	test   edi,edi
  807894:	0f 84 b3 01 00 00    	je     0x807a4d
  80789a:	8b 96 0c 50 00 00    	mov    edx,DWORD PTR [esi+0x500c]
  8078a0:	03 d0                	add    edx,eax
  8078a2:	81 fa 00 40 00 00    	cmp    edx,0x4000
  8078a8:	76 0c                	jbe    0x8078b6
  8078aa:	8b 85 f0 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1010]
  8078b0:	50                   	push   eax
  8078b1:	e9 9e 01 00 00       	jmp    0x807a54
```

**第一手機器碼：0BBB encoder：組 final header/加擾 body/buffer pointer 更新**（VA `0x8079d7–0x807a4b`；`.text` raw 起點 `0x00406DD7`）

```asm
  8079d7:	8b 95 f4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x100c]
  8079dd:	03 95 ec ef ff ff    	add    edx,DWORD PTR [ebp-0x1014]
  8079e3:	01 95 f8 ef ff ff    	add    DWORD PTR [ebp-0x1008],edx
  8079e9:	8b 95 e4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x101c]
  8079ef:	66 8b 85 f8 ef ff ff 	mov    ax,WORD PTR [ebp-0x1008]
  8079f6:	89 11                	mov    DWORD PTR [ecx],edx
  8079f8:	66 89 41 04          	mov    WORD PTR [ecx+0x4],ax
  8079fc:	8b 8e 04 50 00 00    	mov    ecx,DWORD PTR [esi+0x5004]
  807a02:	57                   	push   edi
  807a03:	8d 85 fc ef ff ff    	lea    eax,[ebp-0x1004]
  807a09:	50                   	push   eax
  807a0a:	83 c1 06             	add    ecx,0x6
  807a0d:	51                   	push   ecx
  807a0e:	e8 bd 61 09 00       	call   0x89dbd0
  807a13:	8b 85 d8 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1028]
  807a19:	8b 95 f0 ef ff ff    	mov    edx,DWORD PTR [ebp-0x1010]
  807a1f:	01 86 0c 50 00 00    	add    DWORD PTR [esi+0x500c],eax
  807a25:	01 86 04 50 00 00    	add    DWORD PTR [esi+0x5004],eax
  807a2b:	83 c4 0c             	add    esp,0xc
  807a2e:	52                   	push   edx
  807a2f:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807a35:	5f                   	pop    edi
  807a36:	5e                   	pop    esi
  807a37:	b8 01 00 00 00       	mov    eax,0x1
  807a3c:	5b                   	pop    ebx
  807a3d:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  807a40:	33 cd                	xor    ecx,ebp
  807a42:	e8 ba 95 08 00       	call   0x891001
  807a47:	8b e5                	mov    esp,ebp
  807a49:	5d                   	pop    ebp
  807a4a:	c2                   	.byte 0xc2
```

**第一手機器碼：1A68 plain：組 LE16 len + magic與 body copy**（VA `0x807a84–0x807b19`；`.text` raw 起點 `0x00406E84`）

```asm
  807a84:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  807a87:	8d 5a 04             	lea    ebx,[edx+0x4]
  807a8a:	b8 68 1a 00 00       	mov    eax,0x1a68
  807a8f:	66 89 45 fe          	mov    WORD PTR [ebp-0x2],ax
  807a93:	66 89 55 fc          	mov    WORD PTR [ebp-0x4],dx
  807a97:	81 fb 00 10 00 00    	cmp    ebx,0x1000
  807a9d:	0f 87 8a 00 00 00    	ja     0x807b2d
  807aa3:	85 d2                	test   edx,edx
  807aa5:	0f 84 82 00 00 00    	je     0x807b2d
  807aab:	8b 8f 0c 50 00 00    	mov    ecx,DWORD PTR [edi+0x500c]
  807ab1:	03 cb                	add    ecx,ebx
  807ab3:	81 f9 00 40 00 00    	cmp    ecx,0x4000
  807ab9:	77 72                	ja     0x807b2d
  807abb:	8b 87 04 50 00 00    	mov    eax,DWORD PTR [edi+0x5004]
  807ac1:	8d b7 04 50 00 00    	lea    esi,[edi+0x5004]
  807ac7:	8d 0c 18             	lea    ecx,[eax+ebx*1]
  807aca:	89 4d 0c             	mov    DWORD PTR [ebp+0xc],ecx
  807acd:	8d 4f 04             	lea    ecx,[edi+0x4]
  807ad0:	3b c1                	cmp    eax,ecx
  807ad2:	72 45                	jb     0x807b19
  807ad4:	3b c6                	cmp    eax,esi
  807ad6:	73 41                	jae    0x807b19
  807ad8:	39 4d 0c             	cmp    DWORD PTR [ebp+0xc],ecx
  807adb:	72 3c                	jb     0x807b19
  807add:	39 75 0c             	cmp    DWORD PTR [ebp+0xc],esi
  807ae0:	73 37                	jae    0x807b19
  807ae2:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  807ae5:	52                   	push   edx
  807ae6:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  807ae9:	89 08                	mov    DWORD PTR [eax],ecx
  807aeb:	8b 06                	mov    eax,DWORD PTR [esi]
  807aed:	52                   	push   edx
  807aee:	83 c0 04             	add    eax,0x4
  807af1:	50                   	push   eax
  807af2:	e8 d9 60 09 00       	call   0x89dbd0
  807af7:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  807afa:	01 9f 0c 50 00 00    	add    DWORD PTR [edi+0x500c],ebx
  807b00:	01 1e                	add    DWORD PTR [esi],ebx
  807b02:	83 c4 0c             	add    esp,0xc
  807b05:	51                   	push   ecx
  807b06:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807b0c:	5e                   	pop    esi
  807b0d:	b8 01 00 00 00       	mov    eax,0x1
  807b12:	5b                   	pop    ebx
  807b13:	8b e5                	mov    esp,ebp
  807b15:	5d                   	pop    ebp
  807b16:	c2 08 00             	ret    0x8
```

## E46.6 — C2S local queue 的背壓、flush 和 Winsock 返回值，為何仍不能宣告 first-send

**研究問題**：如何從 `0x49593D` 的本地 enqueue 到最終 `WSASend`，失敗條件/統計欄位在哪？

**N / producer 與 backpressure**：`8069A0` 在 keyed-tree 找不到 Conn→回0；有但 `len=0`→回1（不一定 queue）；有資料才 call `0x8060D0`。後者 `Conn+A0A4 > 0x12C` 提前回0，<=0x1000 才複製 bytes+寫 packet+4，再以 `806060` 追加送出隊列。若 >0x1000 `806177` 仍可能把 pool block 交入 queue，這段並不足以安全推定 payload 真正有效；需看 block reinit、上游長度約束，**不宣告已證漏洞**。

**N / scheduler**：`804A40` 遍歷 `[FBA858]` 的 Conn list，只有 `Conn+A0AC!=0` 才呼叫 `8061A0`。若 flush 成功，統計 `A094++`，將 `A0A4` 依原先值減 5 並以 0 floor；失敗可能在 tick gate `delta>0x21` 時 `A084++` / `A0A4+=5`。另外 `Conn+A028`、`A0B8` 決定是否允許新 WSASend。實際呼叫 imported WSA send 的 `8068B0` 仍先檢查資料 pointer、length 非零、`A0A8` 未關閉；Winsock returns 將 `-1+WSAGetLastError==0x3E5` 分作 pending 返回2，immediate 成功返回1，其他錯誤返回0，**都不是 on-wire delivery ack**。

**C**：`0x49593D` 只證 key0 0x0001/57B 經 manager 虛擬 send→ keyed-tree → local enqueue；`804A40` 需要 active list/tick/active flags，buffer 累積/IOCP 并發可能影響順序。沒有任何地方能把「已排第一個在此函式」提升成「網路上第一個封包」。

**第一手機器碼：key/Conn lookup 到 local queue 的三態**（VA `0x8069a0–0x8069f6`；`.text` raw 起點 `0x00405DA0`）

```asm
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
  8069f3:	c2 0c 00             	ret    0xc
```

**第一手機器碼：local enqueue：backpressure、0x1000 copy 與 pool**（VA `0x8060f5–0x80618e`；`.text` raw 起點 `0x004054F5`）

```asm
  8060f5:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  8060f8:	8b f1                	mov    esi,ecx
  8060fa:	81 be a4 a0 00 00 2c 	cmp    DWORD PTR [esi+0xa0a4],0x12c
  806101:	01 00 00 
  806104:	7e 16                	jle    0x80611c
  806106:	33 c0                	xor    eax,eax
  806108:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  80610b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  806112:	59                   	pop    ecx
  806113:	5f                   	pop    edi
  806114:	5e                   	pop    esi
  806115:	5b                   	pop    ebx
  806116:	8b e5                	mov    esp,ebp
  806118:	5d                   	pop    ebp
  806119:	c2 08 00             	ret    0x8
  80611c:	b8 01 00 00 00       	mov    eax,0x1
  806121:	84 05 54 33 fe 00    	test   BYTE PTR ds:0xfe3354,al
  806127:	75 26                	jne    0x80614f
  806129:	09 05 54 33 fe 00    	or     DWORD PTR ds:0xfe3354,eax
  80612f:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  806136:	e8 e5 0f 00 00       	call   0x807120
  80613b:	68 90 0b bd 00       	push   0xbd0b90
  806140:	e8 d5 c1 08 00       	call   0x89231a
  806145:	83 c4 04             	add    esp,0x4
  806148:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80614f:	bf 58 33 fe 00       	mov    edi,0xfe3358
  806154:	e8 17 13 00 00       	call   0x807470
  806159:	8b f8                	mov    edi,eax
  80615b:	81 fb 00 10 00 00    	cmp    ebx,0x1000
  806161:	77 14                	ja     0x806177
  806163:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  806166:	53                   	push   ebx
  806167:	50                   	push   eax
  806168:	8d 4f 08             	lea    ecx,[edi+0x8]
  80616b:	51                   	push   ecx
  80616c:	e8 5f 7a 09 00       	call   0x89dbd0
  806171:	83 c4 0c             	add    esp,0xc
  806174:	89 5f 04             	mov    DWORD PTR [edi+0x4],ebx
  806177:	57                   	push   edi
  806178:	e8 e3 fe ff ff       	call   0x806060
  80617d:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  806180:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  806187:	59                   	pop    ecx
  806188:	5f                   	pop    edi
  806189:	5e                   	pop    esi
  80618a:	5b                   	pop    ebx
  80618b:	8b e5                	mov    esp,ebp
  80618d:	5d                   	pop    ebp
```

**第一手機器碼：定時 scheduler：A0AC active gate 與 backlog counter**（VA `0x804a85–0x804b1a`；`.text` raw 起點 `0x00403E85`）

```asm
  804a85:	ff d3                	call   ebx
  804a87:	8b 8f 88 00 00 00    	mov    ecx,DWORD PTR [edi+0x88]
  804a8d:	2b c8                	sub    ecx,eax
  804a8f:	bb 01 00 00 00       	mov    ebx,0x1
  804a94:	83 f9 21             	cmp    ecx,0x21
  804a97:	76 09                	jbe    0x804aa2
  804a99:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  804a9f:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  804aa2:	8b 7e 04             	mov    edi,DWORD PTR [esi+0x4]
  804aa5:	2b 3e                	sub    edi,DWORD PTR [esi]
  804aa7:	33 c0                	xor    eax,eax
  804aa9:	c1 ff 02             	sar    edi,0x2
  804aac:	89 7d f8             	mov    DWORD PTR [ebp-0x8],edi
  804aaf:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  804ab2:	85 ff                	test   edi,edi
  804ab4:	0f 84 a1 01 00 00    	je     0x804c5b
  804aba:	eb 07                	jmp    0x804ac3
  804abc:	8d 64 24 00          	lea    esp,[esp+0x0]
  804ac0:	8b 75 f0             	mov    esi,DWORD PTR [ebp-0x10]
  804ac3:	8b 16                	mov    edx,DWORD PTR [esi]
  804ac5:	8b 34 82             	mov    esi,DWORD PTR [edx+eax*4]
  804ac8:	83 be ac a0 00 00 00 	cmp    DWORD PTR [esi+0xa0ac],0x0
  804acf:	0f 84 76 01 00 00    	je     0x804c4b
  804ad5:	56                   	push   esi
  804ad6:	e8 c5 16 00 00       	call   0x8061a0
  804adb:	85 c0                	test   eax,eax
  804add:	74 28                	je     0x804b07
  804adf:	8b 86 a4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0a4]
  804ae5:	01 9e 94 a0 00 00    	add    DWORD PTR [esi+0xa094],ebx
  804aeb:	83 f8 05             	cmp    eax,0x5
  804aee:	73 0c                	jae    0x804afc
  804af0:	c7 86 a4 a0 00 00 00 	mov    DWORD PTR [esi+0xa0a4],0x0
  804af7:	00 00 00 
  804afa:	eb 1e                	jmp    0x804b1a
  804afc:	83 c0 fb             	add    eax,0xfffffffb
  804aff:	89 86 a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],eax
  804b05:	eb 13                	jmp    0x804b1a
  804b07:	83 7d fc 00          	cmp    DWORD PTR [ebp-0x4],0x0
  804b0b:	74 0d                	je     0x804b1a
  804b0d:	01 9e 84 a0 00 00    	add    DWORD PTR [esi+0xa084],ebx
  804b13:	83 86 a4 a0 00 00 05 	add    DWORD PTR [esi+0xa0a4],0x5
```

**第一手機器碼：WSASend direct API, pending0x3E5/error/immediate**（VA `0x8068b0–0x80699d`；`.text` raw 起點 `0x00405CB0`）

```asm
  8068b0:	55                   	push   ebp
  8068b1:	8b ec                	mov    ebp,esp
  8068b3:	53                   	push   ebx
  8068b4:	56                   	push   esi
  8068b5:	57                   	push   edi
  8068b6:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  8068b9:	8b d9                	mov    ebx,ecx
  8068bb:	85 ff                	test   edi,edi
  8068bd:	0f 84 d0 00 00 00    	je     0x806993
  8068c3:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  8068c6:	85 d2                	test   edx,edx
  8068c8:	0f 84 c5 00 00 00    	je     0x806993
  8068ce:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  8068d1:	83 be a8 a0 00 00 00 	cmp    DWORD PTR [esi+0xa0a8],0x0
  8068d8:	0f 85 b5 00 00 00    	jne    0x806993
  8068de:	8d 86 50 a0 00 00    	lea    eax,[esi+0xa050]
  8068e4:	33 c9                	xor    ecx,ecx
  8068e6:	89 08                	mov    DWORD PTR [eax],ecx
  8068e8:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  8068eb:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  8068ee:	6a 00                	push   0x0
  8068f0:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  8068f3:	50                   	push   eax
  8068f4:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  8068f7:	8d 48 14             	lea    ecx,[eax+0x14]
  8068fa:	6a 00                	push   0x0
  8068fc:	89 78 18             	mov    DWORD PTR [eax+0x18],edi
  8068ff:	8d 45 0c             	lea    eax,[ebp+0xc]
  806902:	50                   	push   eax
  806903:	6a 01                	push   0x1
  806905:	89 11                	mov    DWORD PTR [ecx],edx
  806907:	8b 16                	mov    edx,DWORD PTR [esi]
  806909:	51                   	push   ecx
  80690a:	52                   	push   edx
  80690b:	c7 45 0c 00 00 00 00 	mov    DWORD PTR [ebp+0xc],0x0
  806912:	ff 15 b8 25 bd 00    	call   DWORD PTR ds:0xbd25b8
  806918:	8b 4d 14             	mov    ecx,DWORD PTR [ebp+0x14]
  80691b:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  80691e:	89 11                	mov    DWORD PTR [ecx],edx
  806920:	83 f8 ff             	cmp    eax,0xffffffff
  806923:	75 55                	jne    0x80697a
  806925:	ff 15 cc 25 bd 00    	call   DWORD PTR ds:0xbd25cc
  80692b:	8b f8                	mov    edi,eax
  80692d:	81 ff e5 03 00 00    	cmp    edi,0x3e5
  806933:	74 2c                	je     0x806961
  806935:	83 7b 58 00          	cmp    DWORD PTR [ebx+0x58],0x0
  806939:	74 1d                	je     0x806958
  80693b:	8b 36                	mov    esi,DWORD PTR [esi]
  80693d:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  806943:	50                   	push   eax
  806944:	57                   	push   edi
  806945:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806948:	56                   	push   esi
  806949:	68 00 16 c5 00       	push   0xc51600
  80694e:	6a 02                	push   0x2
  806950:	e8 ab 9a ee ff       	call   0x6f0400
  806955:	83 c4 14             	add    esp,0x14
  806958:	5f                   	pop    edi
  806959:	5e                   	pop    esi
  80695a:	33 c0                	xor    eax,eax
  80695c:	5b                   	pop    ebx
  80695d:	5d                   	pop    ebp
  80695e:	c2 10 00             	ret    0x10
  806961:	81 c6 b8 a0 00 00    	add    esi,0xa0b8
  806967:	56                   	push   esi
  806968:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  80696e:	5f                   	pop    edi
  80696f:	5e                   	pop    esi
  806970:	b8 02 00 00 00       	mov    eax,0x2
  806975:	5b                   	pop    ebx
  806976:	5d                   	pop    ebp
  806977:	c2 10 00             	ret    0x10
  80697a:	81 c6 b8 a0 00 00    	add    esi,0xa0b8
  806980:	56                   	push   esi
  806981:	ff 15 84 22 bd 00    	call   DWORD PTR ds:0xbd2284
  806987:	5f                   	pop    edi
  806988:	5e                   	pop    esi
  806989:	b8 01 00 00 00       	mov    eax,0x1
  80698e:	5b                   	pop    ebx
  80698f:	5d                   	pop    ebp
  806990:	c2 10 00             	ret    0x10
  806993:	5f                   	pop    edi
  806994:	5e                   	pop    esi
  806995:	83 c8 ff             	or     eax,0xffffffff
  806998:	5b                   	pop    ebx
  806999:	5d                   	pop    ebp
  80699a:	c2 10 00             	ret    0x10
```

## E46.7 — 0x4957C0 key0+key2 的成功/失敗/舊連線處置：精確保留 partial case

**研究問題**：兩次 Connect 與「新連線已可傳輸」之間至少隔著哪些 native gates？失敗時是否仍能保證沒 socket 殘留？

**N / 連線參數與成功分支**：同一 `endpoint` stack arg 在 `4957DB..495803` 呼叫網路 manager vptr+0x18 兩次，`(key=0, port=0x20E0, lane=2)` 和 `(key=2, port=0x20DE, lane=2)`。**只有** `test edi`/`test ebx` 均非零才在 `495817..` 處理舊 `BF60`，之後 `495872` delay 0x190，構造 0x0001/57，呼叫 virtual send+0x10，並用 manager vptr+0x14 處理兩 Conn；`BF64=edi, BF68=ebx` 最後才寫。它沒有讓我們看見該兩 Conn 的 `WSARecv` 首完成。

**N / 部分成功**：key0 nonNULL/key2 NULL 落 `49597E`，呼叫 manager virtual+0x20 (key=0, flag=1)，返回0；key0 NULL 時先 `4959B0` 記錄 local 訊息，若 key2 非NULL，`4959C1..4959D0` 針對 key2 virtual+0x20 (key=2, flag=1)，返回0。**注意**：沒有執行 socket，因此僅能稱「執行關閉/處置 interface」，無法證這些方法已同步完成 OS closes、IOCP pending 已完全消失。成功時先呼叫 manager+0x14，也不能單純解釋為 socket 已握手完成。

**舊連線**：如果 `BF60 !=0`，本地 `0x007E` 2B 透過 `8060D0` 入隊，設 `oldConn+A0B0=1` 並清 `BF60`；只證 local queue + close intent。**候選第一送出**應按 connection/socket 及排程分流，不可跨不同 key 比絕對時間。

**U**：key0 key2 close 的實際 IOCP completion、是否產生 read callback、最初 connect 失敗/短連重試時 UI 顯示與 timer 交互，還需 manager vtable 實作及 live trace。

**第一手機器碼：2次 key0/key2 connect、2 conn 成功判斷**（VA `0x4957d0–0x495820`；`.text` raw 起點 `0x00094BD0`）

```asm
  4957d0:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4957d6:	8b 01                	mov    eax,DWORD PTR [ecx]
  4957d8:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  4957db:	53                   	push   ebx
  4957dc:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4957df:	57                   	push   edi
  4957e0:	6a 02                	push   0x2
  4957e2:	6a 00                	push   0x0
  4957e4:	68 e0 20 00 00       	push   0x20e0
  4957e9:	53                   	push   ebx
  4957ea:	ff d2                	call   edx
  4957ec:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4957f2:	6a 02                	push   0x2
  4957f4:	6a 02                	push   0x2
  4957f6:	8b f8                	mov    edi,eax
  4957f8:	8b 01                	mov    eax,DWORD PTR [ecx]
  4957fa:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  4957fd:	68 de 20 00 00       	push   0x20de
  495802:	53                   	push   ebx
  495803:	ff d2                	call   edx
  495805:	8b d8                	mov    ebx,eax
  495807:	85 ff                	test   edi,edi
  495809:	0f 84 a1 01 00 00    	je     0x4959b0
  49580f:	85 db                	test   ebx,ebx
  495811:	0f 84 67 01 00 00    	je     0x49597e
  495817:	83 be 60 bf 00 00 00 	cmp    DWORD PTR [esi+0xbf60],0x0
  49581e:	74 52                	je     0x495872
```

**第一手機器碼：舊 key1 0x007E 排入與 close-intent 狀態**（VA `0x495820–0x495872`；`.text` raw 起點 `0x00094C20`）

```asm
  495820:	e8 5b 7e fb ff       	call   0x44d680
  495825:	8b 08                	mov    ecx,DWORD PTR [eax]
  495827:	85 c9                	test   ecx,ecx
  495829:	74 07                	je     0x495832
  49582b:	8b 01                	mov    eax,DWORD PTR [ecx]
  49582d:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  495830:	ff d2                	call   edx
  495832:	8b 86 60 bf 00 00    	mov    eax,DWORD PTR [esi+0xbf60]
  495838:	50                   	push   eax
  495839:	e8 a2 0b 37 00       	call   0x8063e0
  49583e:	b9 7e 00 00 00       	mov    ecx,0x7e
  495843:	6a 02                	push   0x2
  495845:	8d 55 be             	lea    edx,[ebp-0x42]
  495848:	66 89 4d be          	mov    WORD PTR [ebp-0x42],cx
  49584c:	8b 8e 60 bf 00 00    	mov    ecx,DWORD PTR [esi+0xbf60]
  495852:	52                   	push   edx
  495853:	e8 78 08 37 00       	call   0x8060d0
  495858:	8b 86 60 bf 00 00    	mov    eax,DWORD PTR [esi+0xbf60]
  49585e:	c7 80 b0 a0 00 00 01 	mov    DWORD PTR [eax+0xa0b0],0x1
  495865:	00 00 00 
  495868:	c7 86 60 bf 00 00 00 	mov    DWORD PTR [esi+0xbf60],0x0
  49586f:	00 00 00 
```

**第一手機器碼：成功 local send 與 BF64/BF68 active state**（VA `0x49592a–0x49597e`；`.text` raw 起點 `0x00094D2A`）

```asm
  49592a:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495930:	8b 11                	mov    edx,DWORD PTR [ecx]
  495932:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  495935:	6a 39                	push   0x39
  495937:	8d 45 c0             	lea    eax,[ebp-0x40]
  49593a:	50                   	push   eax
  49593b:	6a 00                	push   0x0
  49593d:	ff d2                	call   edx
  49593f:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495945:	8b 01                	mov    eax,DWORD PTR [ecx]
  495947:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  49594a:	57                   	push   edi
  49594b:	ff d2                	call   edx
  49594d:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495953:	8b 01                	mov    eax,DWORD PTR [ecx]
  495955:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  495958:	53                   	push   ebx
  495959:	ff d2                	call   edx
  49595b:	89 be 64 bf 00 00    	mov    DWORD PTR [esi+0xbf64],edi
  495961:	5f                   	pop    edi
  495962:	89 9e 68 bf 00 00    	mov    DWORD PTR [esi+0xbf68],ebx
  495968:	b8 01 00 00 00       	mov    eax,0x1
  49596d:	5b                   	pop    ebx
  49596e:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  495971:	33 cd                	xor    ecx,ebp
  495973:	e8 89 b6 3f 00       	call   0x891001
  495978:	8b e5                	mov    esp,ebp
  49597a:	5d                   	pop    ebp
  49597b:	c2 04 00             	ret    0x4
```

**第一手機器碼：key2 fail 和 key0 fail 各自 cleanup branches**（VA `0x49597e–0x4959e6`；`.text` raw 起點 `0x00094D7E`）

```asm
  49597e:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495984:	8b 01                	mov    eax,DWORD PTR [ecx]
  495986:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  495989:	6a 01                	push   0x1
  49598b:	6a 00                	push   0x0
  49598d:	ff d2                	call   edx
  49598f:	68 3c 5a c0 00       	push   0xc05a3c
  495994:	e8 c7 81 25 00       	call   0x6edb60
  495999:	83 c4 04             	add    esp,0x4
  49599c:	5f                   	pop    edi
  49599d:	33 c0                	xor    eax,eax
  49599f:	5b                   	pop    ebx
  4959a0:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4959a3:	33 cd                	xor    ecx,ebp
  4959a5:	e8 57 b6 3f 00       	call   0x891001
  4959aa:	8b e5                	mov    esp,ebp
  4959ac:	5d                   	pop    ebp
  4959ad:	c2 04 00             	ret    0x4
  4959b0:	68 1c 5a c0 00       	push   0xc05a1c
  4959b5:	e8 a6 81 25 00       	call   0x6edb60
  4959ba:	83 c4 04             	add    esp,0x4
  4959bd:	85 db                	test   ebx,ebx
  4959bf:	74 ce                	je     0x49598f
  4959c1:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4959c7:	8b 01                	mov    eax,DWORD PTR [ecx]
  4959c9:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  4959cc:	6a 01                	push   0x1
  4959ce:	6a 02                	push   0x2
  4959d0:	ff d2                	call   edx
  4959d2:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4959d5:	5f                   	pop    edi
  4959d6:	33 cd                	xor    ecx,ebp
  4959d8:	33 c0                	xor    eax,eax
  4959da:	5b                   	pop    ebx
  4959db:	e8 21 b6 3f 00       	call   0x891001
  4959e0:	8b e5                	mov    esp,ebp
  4959e2:	5d                   	pop    ebp
  4959e3:	c2 04 00             	ret    0x4
```

## E46.8 — 57B 初始 payload 的精確來源與 bytes footprint：命令與識別資料不可自行業務命名

**研究問題**：`0x0001` packet 的固定欄位來自哪個 Client 原生狀態，如何保證不以 UI 文字或 endpoint 覆寫它？

**N**：`495884` 寫 LE16 command=1 到 `[EBP-0x40]`；`4958B8..8BE` 來源 `0x404BA0` 回傳物件 `+0x67E0 DWORD` → packet+2；`4958C1..4958D4` 從 `+0x67E4` bounded 0x0A byte 文字拷入 packet+6；`4958D9..4958EC` 將 `+0x67FA` 文字拷入 packet+0x1B；`4958F1` 設 packet+0x1A =1，`4958FA` 將 `+0x6898` 的 byte 放 packet+0x1B? 必須依 stack 位移精確換算：起點 `[EBP-0x40]`，`[EBP-0x26]`= +0x1A，`[EBP-0x25]`=+0x1B；第二 bounded 拷貝實際目標 `[EBP-0x1B]`=+0x25。`495908..495914` 從 `+6899` 拷五 bytes 到 `[EBP-0x24]`=packet+0x1C。`49591C` 由 `+0x68A0` 複製 DWORD 到 `[EBP-0x1F]`=packet+0x21。這組互不重疊的偏移避免把 Unicode 或 host 假設硬插入。

**精確 packet relative offsets（1 byte = 1，不包含外層 0BBB/1A68 frame）**：`+0..1=0x0001`, `+2..5=<DWORD object+67E0>`, `+6..0xF= bounded copied bytes from +67E4`, `+0x10..0x19` 在前段 zero-init 區域內，`+0x1A=1`, `+0x1B=BYTE object+6898`, `+0x1C..0x20=5 bytes +6899`, `+0x21..0x24=DWORD +68A0`, `+0x25..0x2E=bounded copied bytes +67FA`, 其餘 until packet+0x38 =本地初始化資料。請留意兩個 bounded strcpy-like 0x0A 容量有 NUL 的上游資料，這裡並**未**證具體登入業務語意、帳號加密方式、Server auth token 或編碼設定。

**修正註記**：前段 E45 將 stack second 0x0A buffer 一度簡述為 `[+67FA]` → `[EBP-0x1B]` 是正確的**目標位址**，但相對 payload 是 +0x25；在表述 packet byte layout 時必須改成該相對偏移，以免誤指重疊 `[+6898]` 的 +0x1B。上述是本輪新增的 byte 精確對照，不主張 Server 已認可此 packet。

**U**：若固定 57 bytes 中有尚未由顯式寫入覆蓋的位置，需核對 prologue 與完整 zero-init 範圍；不要假設未初始化 bytes 可用於 Server 版本適配。由於這段已構造完整 packet 卻未證實實際 first-wire，本節只交付 bounded local packet schema。

**第一手機器碼：57B local packet init，DWORD與 bounded byte strings**（VA `0x49587d–0x4958f1`；`.text` raw 起點 `0x00094C7D`）

```asm
  49587d:	33 c0                	xor    eax,eax
  49587f:	b9 01 00 00 00       	mov    ecx,0x1
  495884:	66 89 4d c0          	mov    WORD PTR [ebp-0x40],cx
  495888:	89 45 c6             	mov    DWORD PTR [ebp-0x3a],eax
  49588b:	89 45 ca             	mov    DWORD PTR [ebp-0x36],eax
  49588e:	89 45 ce             	mov    DWORD PTR [ebp-0x32],eax
  495891:	89 45 d2             	mov    DWORD PTR [ebp-0x2e],eax
  495894:	89 45 d6             	mov    DWORD PTR [ebp-0x2a],eax
  495897:	66 89 4d da          	mov    WORD PTR [ebp-0x26],cx
  49589b:	89 45 dc             	mov    DWORD PTR [ebp-0x24],eax
  49589e:	88 45 e0             	mov    BYTE PTR [ebp-0x20],al
  4958a1:	89 45 e1             	mov    DWORD PTR [ebp-0x1f],eax
  4958a4:	89 45 e5             	mov    DWORD PTR [ebp-0x1b],eax
  4958a7:	89 45 e9             	mov    DWORD PTR [ebp-0x17],eax
  4958aa:	89 45 ed             	mov    DWORD PTR [ebp-0x13],eax
  4958ad:	89 45 f1             	mov    DWORD PTR [ebp-0xf],eax
  4958b0:	89 45 f5             	mov    DWORD PTR [ebp-0xb],eax
  4958b3:	e8 e8 f2 f6 ff       	call   0x404ba0
  4958b8:	8b 90 e0 67 00 00    	mov    edx,DWORD PTR [eax+0x67e0]
  4958be:	89 55 c2             	mov    DWORD PTR [ebp-0x3e],edx
  4958c1:	e8 da f2 f6 ff       	call   0x404ba0
  4958c6:	6a 0a                	push   0xa
  4958c8:	05 e4 67 00 00       	add    eax,0x67e4
  4958cd:	50                   	push   eax
  4958ce:	8d 45 c6             	lea    eax,[ebp-0x3a]
  4958d1:	6a 0a                	push   0xa
  4958d3:	50                   	push   eax
  4958d4:	e8 25 e7 3f 00       	call   0x893ffe
  4958d9:	e8 c2 f2 f6 ff       	call   0x404ba0
  4958de:	6a 0a                	push   0xa
  4958e0:	05 fa 67 00 00       	add    eax,0x67fa
  4958e5:	50                   	push   eax
  4958e6:	8d 4d e5             	lea    ecx,[ebp-0x1b]
  4958e9:	6a 0a                	push   0xa
  4958eb:	51                   	push   ecx
  4958ec:	e8 0d e7 3f 00       	call   0x893ffe
```

**第一手機器碼：flag/status/5B/DWORD + fixed 57 send**（VA `0x4958f1–0x49593f`；`.text` raw 起點 `0x00094CF1`）

```asm
  4958f1:	c6 45 da 01          	mov    BYTE PTR [ebp-0x26],0x1
  4958f5:	e8 a6 f2 f6 ff       	call   0x404ba0
  4958fa:	8a 90 98 68 00 00    	mov    dl,BYTE PTR [eax+0x6898]
  495900:	88 55 db             	mov    BYTE PTR [ebp-0x25],dl
  495903:	e8 98 f2 f6 ff       	call   0x404ba0
  495908:	05 99 68 00 00       	add    eax,0x6899
  49590d:	50                   	push   eax
  49590e:	8d 45 dc             	lea    eax,[ebp-0x24]
  495911:	6a 05                	push   0x5
  495913:	50                   	push   eax
  495914:	e8 40 e2 3f 00       	call   0x893b59
  495919:	83 c4 2c             	add    esp,0x2c
  49591c:	e8 7f f2 f6 ff       	call   0x404ba0
  495921:	8b 88 a0 68 00 00    	mov    ecx,DWORD PTR [eax+0x68a0]
  495927:	89 4d e1             	mov    DWORD PTR [ebp-0x1f],ecx
  49592a:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495930:	8b 11                	mov    edx,DWORD PTR [ecx]
  495932:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  495935:	6a 39                	push   0x39
  495937:	8d 45 c0             	lea    eax,[ebp-0x40]
  49593a:	50                   	push   eax
  49593b:	6a 00                	push   0x0
  49593d:	ff d2                	call   edx
```

## E46.9 — UI 選服 gate F94294：精確只有 clear/read，不能把未證 alias 當成已開放分支

**研究問題**：`66C090` 中的第一條 Connect path 是否必然可達？`record+4` 的 4/5/0 值與非零 gate 如何交互？

**N**：前段 E45 已證 record+4 來自 S2C 每筆 `child[8]`（只有 !=0 才 append），record+0xC 則是 IPv4 host。`66C090` 取得兩個 selection key → `5078C0` 的 record+4 值存 EBX，`507750` 的 host ptr 存 ESI。`66C17E` 先讀 `[F94294]`：**非零且 EBX!=0 且 ESI!=0** 才走 `66C1A7 call 4957C0`，隨後依 UI child pointer 將某個 selection field 寫入 `D63DCC`；如果 gate=0 或 EBX=0，走 `66C21D`，EBX==4/0/5 有不同 UI 處理，其他 EBX 且 host 非NULL 可以走另一條 `66C247 call 4957C0`（即使 F94294==0）。**故不能把 F94294==0 總結為「不能連線」，也不能把 EBX==4/5 說成 Server 滿載/維護。**

**native xref 覆蓋**：精確 `LE32(F94294)` 只有 `4E16C1 mov [F94294],EBX` 與 `66C180 cmp`；`4E1590` 的 prologue 在 `4E15BF xor ebx,ebx` 清零 EBX；同函式 `4E16BF` 以此 EBX 清零 F94294，本段因此確證 **直接初始化設為0**，但不把「無其他絕對位址 writer」當作「沒有 any alias」。如果後續某處用 `&F94280` +0x14 alias 寫，精確 byte search 找不到。

**C / 玩家行為**：可對 Server 建模最小約束為：有效選服記錄必須有非空 IPv4 string 和不同下游 gate 允許的 type/flags；不能只送合法 IPv4 就宣稱 UI 一定 Connect。UI 另有本地狀態/選中項的可達條件，擬議相容 Server 的 `record+4=1` 等值須先在實際 Client/trace 確認，不能當成官方規則。

**新增直接初始化清零來源 `0x4E1590`**：

```asm
  4e1590:	55                   	push   ebp
  4e1591:	8b ec                	mov    ebp,esp
  4e1593:	6a ff                	push   0xffffffff
  4e1595:	68 13 bc 93 00       	push   0x93bc13
  4e159a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4e15a0:	50                   	push   eax
  4e15a1:	83 ec 1c             	sub    esp,0x1c
  4e15a4:	53                   	push   ebx
  4e15a5:	56                   	push   esi
  4e15a6:	57                   	push   edi
  4e15a7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4e15ac:	33 c5                	xor    eax,ebp
  4e15ae:	50                   	push   eax
  4e15af:	8d 45 f4             	lea    eax,[ebp-0xc]
  4e15b2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4e15b8:	c7 45 ec e0 d9 f8 00 	mov    DWORD PTR [ebp-0x14],0xf8d9e0
  4e15bf:	33 db                	xor    ebx,ebx
  4e15c1:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
```

**第一手機器碼：全域 state 初始化對 F94294 只有直接寫入 (EBX 來源需另核)**（VA `0x4e1689–0x4e16d5`；`.text` raw 起點 `0x000E0A89`）

```asm
  4e1689:	89 1d 70 42 f9 00    	mov    DWORD PTR ds:0xf94270,ebx
  4e168f:	89 1d 74 42 f9 00    	mov    DWORD PTR ds:0xf94274,ebx
  4e1695:	88 1d 78 42 f9 00    	mov    BYTE PTR ds:0xf94278,bl
  4e169b:	89 1d 79 42 f9 00    	mov    DWORD PTR ds:0xf94279,ebx
  4e16a1:	88 1d 7d 42 f9 00    	mov    BYTE PTR ds:0xf9427d,bl
  4e16a7:	89 1d 80 42 f9 00    	mov    DWORD PTR ds:0xf94280,ebx
  4e16ad:	89 1d 84 42 f9 00    	mov    DWORD PTR ds:0xf94284,ebx
  4e16b3:	89 1d 8c 42 f9 00    	mov    DWORD PTR ds:0xf9428c,ebx
  4e16b9:	88 1d 90 42 f9 00    	mov    BYTE PTR ds:0xf94290,bl
  4e16bf:	89 1d 94 42 f9 00    	mov    DWORD PTR ds:0xf94294,ebx
  4e16c5:	89 1d 98 42 f9 00    	mov    DWORD PTR ds:0xf94298,ebx
  4e16cb:	c7 05 9c 42 f9 00 ff 	mov    DWORD PTR ds:0xf9429c,0xffff
  4e16d2:	ff 00 00 
```

**第一手機器碼：UI selector keys→record gate+host→F94294 分支**（VA `0x66c124–0x66c1ac`；`.text` raw 起點 `0x0026B524`）

```asm
  66c124:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  66c128:	8b 35 54 1b fe 00    	mov    esi,DWORD PTR ds:0xfe1b54
  66c12e:	57                   	push   edi
  66c12f:	50                   	push   eax
  66c130:	8b c6                	mov    eax,esi
  66c132:	e8 89 b7 e9 ff       	call   0x5078c0
  66c137:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  66c13b:	57                   	push   edi
  66c13c:	8b d8                	mov    ebx,eax
  66c13e:	51                   	push   ecx
  66c13f:	8b c6                	mov    eax,esi
  66c141:	e8 0a b6 e9 ff       	call   0x507750
  66c146:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  66c14d:	8b f0                	mov    esi,eax
  66c14f:	75 2a                	jne    0x66c17b
  66c151:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  66c158:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  66c15f:	00 
  66c160:	e8 2b 54 e7 ff       	call   0x4e1590
  66c165:	68 80 cc bc 00       	push   0xbccc80
  66c16a:	e8 ab 61 22 00       	call   0x89231a
  66c16f:	83 c4 04             	add    esp,0x4
  66c172:	83 cf ff             	or     edi,0xffffffff
  66c175:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  66c179:	eb 03                	jmp    0x66c17e
  66c17b:	83 cf ff             	or     edi,0xffffffff
  66c17e:	83 3d 94 42 f9 00 00 	cmp    DWORD PTR ds:0xf94294,0x0
  66c185:	0f 84 92 00 00 00    	je     0x66c21d
  66c18b:	85 db                	test   ebx,ebx
  66c18d:	0f 84 8a 00 00 00    	je     0x66c21d
  66c193:	85 f6                	test   esi,esi
  66c195:	0f 84 1e 03 00 00    	je     0x66c4b9
  66c19b:	e8 e0 84 da ff       	call   0x414680
  66c1a0:	56                   	push   esi
  66c1a1:	8b 35 18 13 fb 00    	mov    esi,DWORD PTR ds:0xfb1318
  66c1a7:	e8 14 96 e2 ff       	call   0x4957c0
```

**第一手機器碼：UI default 下 EBX==4/0/5 dispatch 與第二 Connect path**（VA `0x66c21d–0x66c275`；`.text` raw 起點 `0x0026B61D`）

```asm
  66c21d:	83 fb 04             	cmp    ebx,0x4
  66c220:	74 52                	je     0x66c274
  66c222:	85 db                	test   ebx,ebx
  66c224:	0f 84 bc 01 00 00    	je     0x66c3e6
  66c22a:	83 fb 05             	cmp    ebx,0x5
  66c22d:	0f 84 bc 01 00 00    	je     0x66c3ef
  66c233:	85 f6                	test   esi,esi
  66c235:	0f 84 7e 02 00 00    	je     0x66c4b9
  66c23b:	e8 40 84 da ff       	call   0x414680
  66c240:	56                   	push   esi
  66c241:	8b 35 18 13 fb 00    	mov    esi,DWORD PTR ds:0xfb1318
  66c247:	e8 74 95 e2 ff       	call   0x4957c0
  66c24c:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  66c24f:	8b 80 f0 00 00 00    	mov    eax,DWORD PTR [eax+0xf0]
  66c255:	e8 d6 02 dc ff       	call   0x42c530
  66c25a:	a3 cc 3d d6 00       	mov    ds:0xd63dcc,eax
  66c25f:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  66c263:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  66c26a:	59                   	pop    ecx
  66c26b:	5f                   	pop    edi
  66c26c:	5e                   	pop    esi
  66c26d:	5b                   	pop    ebx
  66c26e:	8b e5                	mov    esp,ebp
  66c270:	5d                   	pop    ebp
  66c271:	c2 04 00             	ret    0x4
  66c274:	f6                   	.byte 0xf6
```

## E46.10 — 將端到端路徑與 native S2C callback、缺口和外部驗收具體接合

**研究問題**：在前9子段證據修正後，能否不執行 Client 便宣告 login→choice→connect→first wire→first response 全鏈已完成？若不能，最小新證據是甚麼？

**N/C 已閉合的可重用有界子鏈**：`0x4C37A0(native cmd 0x13 mode0)` 在條件成立進 `4C3080`；另一 `0x4C3C10`(cmd 0x7A) 也能進相同 parser；由 E44/E45 本地原件證實 child 十 bytes 的 `+4..7 IPv4`、`+8 record+4` writer → FE1B54 的 0x60-byte record → UI 66C090 兩鍵選取 → 正式 0x4957C0 Connect **一至兩個可能 UI branch** → key0/key2 兩 Conn 成立 → key0 本地 enqueue opcode0x0001、length57 → keyed-tree `8069A0` / `8060D0` → `804A40` active flush → mode A02C 預設2（仍可能 alias 改）→ encoded 0BBB success 或 plain 1A68 fallback → `8068B0` WSASend API。**回收逆向有界**：IOCP `806CF0→807B40` → `FC10D0` app bucket queue → `0x490FE0→804740→80486D`，在 E41 所證的次級 vptr/route 條件下可達 `4930E0→48AAD0→494360→4FDA30`，再分派 native 0x13/0x7A；**但沒有任何 native 必然性讓上一筆 `0x0001` 一定先於該 S2C**。上下行組合的所有可達條件不能裁掉。

**N 這輪否證最重要之處**：不再把 `FBA7CC+4` 的未知 COM-like pointer 當成 `Client+8` 或上述 `80486D` 的必要來源。它的部分 caller 傳零，且產生自另一組 interface dispatch；在本 RR packet 研究上，這是先前誤放跨系統 alias 的更正。也不再用當地 constructor 的 DWORD `0x7D810BBB` 冒充完整固定 wire header；真正 encoded header 是 LE16(len), 0BBB, checksum。

**仍需驗收/解除條件**：完整 original Client 合法執行授權 + 同一 session trace （由本地研究者在合法環境採集，**本稿未執行**）：(1) 斷線→登入前 socket ID/key/Conn*，(2) 0x13/0x7A 實際 payload 長度、UTF16 terminator、record group count 與 UI state, (3) `66C090` 真正 branch/`F94294`, (4) `4957C0` 兩次 Connect result / A02C runtime bytes, (5) `8068B0` 真正 WSASend bytes 和順序/IOCP completion, (6) `807B40` 第一個 decoded S2C command/lane, (7) callback target vptr 和主畫面變化。沒有上述一致 trace 即使已證 handler 也不等於 Server schema 已完整、規格 STABLE 或遊戲可玩。

### Player contract / 增量驗證矩陣

| 玩家／網路情境 | 已有 native 限定效果 | 尚未證明 | 負責類別 |
|---|---|---|---|
| 收到 0x13 mode0 | 進 4C3080 parser 的條件分支，需高位資料和 UTF16 NUL | exact upstream length guard，是否 first S2C | Client 待逆向、T03 |
| 收到 0x7A | 另一入口進相同 group parser | 是否必然在 0x13 之後、first reply | Client 待逆向、T03 |
| 選服記錄 | child IPv4、record type、FE1B54 lookup | type4/5 official semantics / UI gate alias | Client 待逆向、T03／S00 |
| 選伺服器 | UI 兩條不同 gate 到 `4957C0` | live branch/F94294 | Client 待逆向 |
| 新 key0、key2 | 20E0/20DE、兩指標非NULL後本地 key0 0x0001/57B | actual TCP Connect handshake readiness | Client 待逆向 |
| new Conn frame | init mode2；0BBB success候選63B、plain fallback61B | alias setter、實際首 wire 和 checksum bytes | Client 待逆向 |
| recv→handler | IOCP→packet FIFO→vcall→命令表的條件式鏈 | 實際 first S2C / cb vptr 時序 | Client 待逆向 |
| 相容 Server | 可用有限 native wire 資料作 DRAFT SPEC/TEST | 官方驗證/授權可玩 session | Server 待開發、S00 |

### 四類缺口（不得混淆）

- **Client 待逆向**：A02C alias/non-default writer、`F94294` 非零 writer、UI branch runtime選中、`0x13/0x7A` 安全讀取邊界/長度傳遞、active `FBA854` Conn metadata/第一筆 WSASend/S2C。**`FBA7CC+4` 身分歧義已收斂為「不能作 C+8 的依據」**，而不是宣告已得到 Client+8。
- **Server 待開發**：須有合理回覆及 endpoint/role/policy，使原版 Client 在已驗證的 wire parser 與 Conn role 下能互通；使用 S00 ADR 記錄自訂登入驗證/資料庫和重試規則，不宣稱官方 Server 的內部演算法。
- **跨功能待整合**：T02 (framing/Conn/queue) 證據、T03 (0x13、選服 UI)、T01 有界原生審核、S00 GAP-NET-0002。此稿只是 E46 原始研究，不能由來源 SHA 相同自動升成 FULL-PASS，也沒有權限修改他們的狀態。
- **待遊玩驗證**：Client/socket pcap/IOCP、同一場景 UI /兩個 port/first wire/first response/下一畫面，均需獨立合法實測，未有不得稱可玩。

### 停止理由與下一段交接

**本次正式停止 B**：E46.1–E46.10 每個子段均已執行，獲得對前段脆弱 alias 假設的原生否證、Conn 預設 mode2 的 native 答案、0BBB 正確 header/61B fallback 與 UI/Connect 失敗分支矩陣；整條功能鏈仍不能在缺 first live socket/recv 時宣告 A。依使用者要求 **E46 只有一份完整 Markdown，不延伸 E46.11，也不因新重要局部發現提前結束**。

**E47 優先**：基於 E46 修正不再以 `FBA7CC manager+4` 浪費 RR 研究；改沿 `FBA854` network vtable 與 key0/key2 socket/Conn active registration 真正支援的 `A02C` alias writer；對 `F94294` 嘗試指標 alias/全域 nearby-writer 的對比，`0x13/0x7A` receiver upstream length guard；若沒有新靜態證據，要明確轉交本地合法 trace 而非無限用不同函式當作 first wire。

**工作狀態**：沒有 Commit、Push、RR 正式認領、台帳修改。原始本機 BIN 唯讀；本文包內可由以下指令重現：

```bash
sha256sum Tartaros.bin
objdump -h Tartaros.bin
objdump -d -M intel --start-address=0x6e65a0 --stop-address=0x6e6900 Tartaros.bin
objdump -d -M intel --start-address=0x805f50 --stop-address=0x806260 Tartaros.bin
objdump -d -M intel --start-address=0x807830 --stop-address=0x807b40 Tartaros.bin
objdump -d -M intel --start-address=0x4957c0 --stop-address=0x4959e6 Tartaros.bin
objdump -d -M intel --start-address=0x66c090 --stop-address=0x66c280 Tartaros.bin
```

