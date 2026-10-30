# E32 — RR-0005：0x13 回覆狀態橋接、選服 UI RTTI/vtable、三組連線及失敗/重用邊界

**研究時間**：2026-10-29T20:46:28+08:00（Asia/Taipei）  
**分支與授權**：`extra/roy1` 研究線；本輪無 Commit/Push 授權，僅本地 Markdown 原稿。  
**GitHub 核對基準**：`main=e751b18922d205d86dea9f280cfd060f62752bc7`；`extra/roy1=6e16fd7260297f90dde6dc18bb8bc9d278f05af3`（E31）。RR 台帳取上述 main，`RR-0005` 為 `KR / T02 / P0 / PENDING` 且 `dispatch.state=QUEUED`；不聲稱已認領。  
**目標**：在已有 T03 研究和 E01～E31、T02/T01 有界主張之上，追 `0x13` 登入結果到選服界面及 `0x495610`／`0x4957C0` 的**原生可證子流程**。沒有 runtime pcap，不宣稱完整 Server↔Client 封包/重連時序。

## 0. 原件與版本、研究復用核對

| 資產 | 存取及驗證 | 處理方式 |
|---|---|---|
| `Tartaros.bin` | 本地 12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` | 本輪所有新結論的原始 x86 machine-code／read-only direct bytes |
| `Tartaros.exe` | 本地 SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f` | 與 T03 版本核對，不執行、不 patch |
| `Event.stp` | 本地 11,241,597 bytes；SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` | E01/E06 已確認 Tutorial Lua 及 EX v1 解碼；本輪不重新解碼 |
| `SceneList.xml` | 本輪容器沒有獨立同名檔，但 E06 已確認自 Event.stp 提取，158,269 bytes，SHA256 `8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25` | 使用 E06 既有結論，無登入選服直接依賴，不要求重傳 |
| Tutorial/`qbase.lua` | E01 已在 Event.stp 確定三份 Lua 5.1 bytecode；E08～E16 已分析 scene/sequence 用法 | 不把 tutorial/questIdx 1001/1 當作登入或 wire 結果 |
| `kr-bulk-roy/<BIN SHA>/functions/` | 本輪直接取用 GitHub main 上 `0x5a9860.c`、`0x5a7000.c`、`0x66c620.c`、`0x4c37a0.c`、`0x4c3220.c`、`0x495610.c`、`0x4957c0.c`、`0x806ad0.c`、`0x8063e0.c`、`0x805af0.c` 等 | 用於函式/符號導航，新增正面結論逐項回到 BIN 指令及資料確認 |

**PE 主要映射**：`.text VA=raw+0x400C00`（即 VA `0x00401000` 對 raw `0x400`）；`.rdata VA=raw-0x7D0600+0xBD2000`；`.data VA=raw-0x95E800+0xD61000`。下列 VA/raw 均依此換算。原始 BIN 唯讀；禁止把這些研究/資產視為官方 Server 程式碼。

**已核 main 入口**：`AGENTS.md`、`kr/tasks/T02/README.md`、`kr/tasks/T02/task.json`、`research/dispatch/README.md`、`research/dispatch/inbox/T02.md`、`research/requests/index.json`、`research/claims/index.json`、`research/intake/index.json`、`shared/verified-knowledge/README.md`；T02 README 沒有專屬 T01 驗收退回事項章節。`kr/tasks/T03/README.md` 有 T01-RETURN-T03-006-LAYOUT-001（T03-6 WSASend +A050/+A064/+A0B8 基準錯誤），非本 E32 領域，不更改他 Task；本段如涉及 WSASend 必須使用正確的 OV/WSABUF/atomic-counter 區別。main 已錄的有限 `CLM-AUTH`、`CLM-NET` 可用於辨識缺口，但 `CLAIMS_EXTRACTED`、`PARTIAL` 或 `SPEC_CONSUMABLE` 不冒充 FULL-PASS。

**既有去重**：E01～E18 主題為 STP/EX v1/Lua/SceneList 及教程 scene，E19～E25 為 builder/send/IOCP/queue/worker，E26～E29 為舊 0x007E、兩個 Connect、0x39、UI 事件/索引鍵，E30～E31 為 C1C4F0 方法表候選與 `0x7B6890` 紅黑樹 erase。T03 `AUTH-NATIVE-REVIEW.md` 已研究 0x4C37A0 result parser、0x4C3080 group/channel、0x4C3170；`SERVER-CHOICE-REVIEW.md` 已有選取 row 與 `0x66C090`。本段僅補**以前未閉合的 callback 組態、RTTI owner、cache 資料相依及分支失敗所有權**。

## 第一輪：從 0x13 handler register → 結果資料 → 0x39 連線 payload 的有界資料橋接

### 1.1 0x13 handler 是原生表項，而非只有 T03 文獻名稱

在 BIN `0x4C3220..`，`0x4C322E` 呼叫 `0x89E860` 初始化 `[ESI+0x5EAC]` 區段；`0x4C323B` 在 `[ESI+0x5F44]` 寫入函式指標 `0x4C37A0`，並在 `+0x5F48` 設置搭配資料。對既有每 command 8-byte slot 介面，`0x5F44-0x5EAC=0x98=0x13*8`：證實同一註冊區塊的 **slot index 0x13**，並獨立核對 T03 已追的 handler。此僅限該 receiver table index；若未完成 transport dispatch/framing，不把所有 frame 之 packet status 過度命名。

```asm
  4c3220:	68 a8 5e 00 00       	push   0x5ea8
  4c3225:	8d 86 ac 5e 00 00    	lea    eax,[esi+0x5eac]
  4c322b:	6a 00                	push   0x0
  4c322d:	50                   	push   eax
  4c322e:	e8 2d b6 3d 00       	call   0x89e860
  4c3233:	b8 75 23 bf 00       	mov    eax,0xbf2375
  4c3238:	83 c4 0c             	add    esp,0xc
  4c323b:	c7 86 44 5f 00 00 a0 	mov    DWORD PTR [esi+0x5f44],0x4c37a0
  4c3242:	37 4c 00 
  4c3245:	89 86 48 5f 00 00    	mov    DWORD PTR [esi+0x5f48],eax
  4c324b:	c7 86 54 60 00 00 90 	mov    DWORD PTR [esi+0x6054],0x4c3b90
  4c3252:	3b 4c 00 
  4c3255:	89 86 58 60 00 00    	mov    DWORD PTR [esi+0x6058],eax
  4c325b:	c7 86 7c 62 00 00 10 	mov    DWORD PTR [esi+0x627c],0x4c3c10
  4c3262:	3c 4c 00 
  4c3265:	89 86 80 62 00 00    	mov    DWORD PTR [esi+0x6280],eax
```

**限定 ABI**：`ESI` 是初始化期間的 owner；`0x4C37A0` 沒有直接 E8 caller，原因是此處把它寫為 callback pointer。全 `.text` E8 rel32 位元掃描本輪未見任意 direct-call bytes 指向 `0x4C37A0`；整個 BIN little-endian `0x004C37A0` 恰有 1 處，raw `0x0C2641`（VA `0x4C3241` 位於 `mov [esi+0x5F44],imm32` 的 immediate 內）。不能用「無 E8」否定它可被間接派送；也不能只由靜態 slot 推斷 inbound frame 尚未驗證的方向性。

### 1.2 0x4C37A0 的可驗資料來源，與後續 0x4957C0 的讀入位置吻合

從原始 BIN：回覆 `status=[ESI+0x16]`，值 5 特殊分支；值 0 且 `ESI+2` UTF-16 名稱非空走寫入路徑；其他值/空名進失敗清理。T03 先前已驗的欄位**本輪不用重做**，只建立下表 caller/consumer 一對一：

| `0x4C37A0` 讀取 response | 寫入 client（透過 `0x404BA0`） | `0x4957C0` 後續讀取 | 證據性質 |
|---|---|---|---|
| `response+0x18` dword | `client+0x67E0` | `0x4958B8` → 0x39 payload +2 | **同一欄位來源已證**；official account ID 語意仍不可自填 |
| `response+2` UTF-16 | `client+0x67E4`，容量 11 wide/count 10 | `0x4958C8..D4` → +6 開始（20-byte wide 區） | **資料依賴已證**；字串與 copy 失敗邊界未全驗 |
| `response+0x86` byte | `client+0x6898` | `0x4958FA..0x495900` → +27 | 已證 byte copy，token/權限命名未知 |
| `response+0x87` narrow string | `client+0x6899`，目的容量 5 | `0x495908..0x495914` → +28..+32 | 已證字串/容量，內容政策未知 |
| `response+0x8C` dword | `client+0x68A0` | `0x495921..0x495927` → +33..+36 | 已證數值依賴 |
| 非 0x13 本次對照來源 | `client+0x67FA` | `0x4958DE..0x4958EC` → +37..+56 | **原生讀取確立，但這個來源未由本 0x13 分支證明** |

此處是 E32 的真正 **0x13 → 登入 cache → 選服後 0x39 payload** *資料橋接*，不等於 0x13 回包立即呼叫 Connect。另 `0x4C3080` 消費 `+0x1C` group count、`+0x92` cursor：3-byte group header、每 channel 10-byte row；函式末呼叫 `0x58AAD0(0xF4243)`，而條件 `response+0x90 ==0` 會經 `0x4C3170` 下發 `0xF4241`。它們是**本地 FUI 事件**，不是透過網路發出的 opcode。

代表性原生指令（0x13 status gate；其餘欄位原始存取位址保留上表，可用命令重新完整反組譯）：

```asm
  4c381e:	83 c4 10             	add    esp,0x10
  4c3821:	8a 56 16             	mov    dl,BYTE PTR [esi+0x16]
  4c3824:	80 fa 05             	cmp    dl,0x5
  4c3827:	0f 85 1c 01 00 00    	jne    0x4c3949
  4c382d:	6a 34                	push   0x34
  4c382f:	e8           	call   0x891268
  4c3a0a:	8d 8e 92 00 00 00    	lea    ecx,[esi+0x92]
  4c3a10:	e8 6b f6 ff ff       	call   0x4c3080
  4c3a15:	80 be 90 00 00 00 00 	cmp    BYTE PTR [esi+0x90],0x0
  4c3a1c:	75 0b                	jne    0x4c3a29
  4c3a1e:	8b bd b0 fb ff ff    	mov    edi,DWORD PTR [ebp-0x450]
  4c3a24:	e8 47 f7 ff ff       	call   0x4c3170
  4c3a29:	33                 	xor    eax,eax
```

**否證/邊界**：`0xF4243`/`0xF4241` 的 post 不能自行當作 UI button event `0x70A` 的 producer；`0x13` 和 `0x70A` 不在同一 opcode domain。關於錯誤 status、登入先後和 retry，只有 handler 局部結果，尚無官方 Server decision/trace。

## 第二輪：0xC1C4F0 真正的類別表起點、RTTI owner 與原生 vptr 安裝

### 2.1 修正 E30/E31 限定掃描範圍造成的未解事項

先前 E31 只對 table **內部候選** `0xC1C480..0xC1C4F0` 搜尋 vptr 首址，結果無引用且保守保留未知。E32 向前拓寬 `.rdata`：

```text
0xC1C390 = 0x00C6F404    ; MSVC x86 RTTI Complete Object Locator
0xC1C394 = 0x004882E0    ; FUI::CServerSelectDialog vftable start (slot +0)
...
0xC1C4E8 = 0x00476430    ; slot +0x154
0xC1C4EC = 0x00476430    ; slot +0x158
0xC1C4F0 = 0x0066C620    ; slot +0x15C == virtual index 87
...
0xC1C52C = 0x00000000
0xC1C530 = 0x00C6F3AC    ; next RTTI COL, not part of CServerSelectDialog vftable
0xC1C534 = 0x00423F20    ; next vftable start
```

`.rdata` raw：`0xC1C390→0x81A990`、`0xC1C394→0x81A994`、`0xC1C4F0→0x81AAF0`。`0xC6F404` (raw `0x86DA04`) 的 COL fields 在 x86 little-endian 為 `signature=0, offset=0, cdOffset=0, pTypeDescriptor=0x00F812A8, pClassDescriptor=0x00C6F418`。TypeDescriptor `0xF812A8`（.data raw `0xB7EAA8`）以 `.?AVCServerSelectDialog@FUI@@` 明確標記**FUI::CServerSelectDialog**。這是 PE MSVC RTTI 及原生指標的證據，不再是「似乎為 vtable」。

整份 BIN 中 `0xC1C394` little-endian 常數在 raw `0x1A6402`（VA `0x5A7002`）及 `0x1A8CC3`（VA `0x5A98C3`）各一次：

```asm
  5a98b4:	8b ce                	mov    ecx,esi
  5a98b6:	e8 25 cc 1a 00       	call   0x7564e0
  5a98bb:	89 be ec 00 00 00    	mov    DWORD PTR [esi+0xec],edi
  5a98c1:	c7 06 94 c3 c1 00    	mov    DWORD PTR [esi],0xc1c394
  5a98c7:	89 be fc 00 00 00    	mov    DWORD PTR [esi+0xfc],edi
  5a98cd:	89 be 00 01 00 00    	mov    DWORD PTR [esi+0x100],edi
  5a98d3:	89 be 04 01 00 00    	mov    DWORD PTR [esi+0x104],edi
  5a98d9:	89 be f0 00 00 00    	mov    DWORD PTR [esi+0xf0],edi
  5a98df:	89 be f4 00 00 00    	mov    DWORD PTR [esi+0xf4],edi
  5a98e5:	eb 02                	jmp    0x5a98e9
  5a98e7:	33 f6                	xor    esi,esi
  5a7000:	c7 06 94 c3 c1 00    	mov    DWORD PTR [esi],0xc1c394
  5a7006:	8b 86 fc 00 00 00    	mov    eax,DWORD PTR [esi+0xfc]
  5a700c:	85 c0                	test   eax,eax
  5a700e:	74 1b                	je     0x5a702b
  5a7010:	8b 8e 00 01 00 00    	mov    ecx,DWORD PTR [esi+0x100]
  5a7016:	51                   	push   ecx
  5a7017:	e8 e4 2f 00 00       	call   0x5aa000
  5a701c:	8b 96 fc 00 00 00    	mov    edx,DWORD PTR [esi+0xfc]
  5a7022:	52                   	push   edx
  5a7023:	e8 e4 a1 2e 00       	call   0x89120c
  5a7028:	83 c4 08             	add    esp,0x8
  5a702b:	c7 86 fc 00 00 00 00 	mov    DWORD PTR [esi+0xfc],0x0
  5a7032:	00 00 00 
  5a7035:	c7 86 00 01 00 00 00 	mov    DWORD PTR [esi+0x100],0x0
  5a703c:	00 00 00 
  5a703f:	c7 86 04 01 00 00 00 	mov    DWORD PTR [esi+0x104],0x0
  5a7046:	00 00 00 
  5a7049:	c7 06 ec a7 c4 00    	mov    DWORD PTR [esi],0xc4a7ec
  5a704f:	8b ce                	mov    ecx,esi
  5a7051:	e9 3a f5 1a        	jmp    0x756590
```

`0x5A9860`（本輪已讀 GitHub `kr-bulk-roy/.../functions/0x5a9860.c` 並比對下列原碼）配置 0x10C bytes 的實際 dialog object，先 `0x7564E0` 初始化，然後 `0x5A98C1` 安裝 `0xC1C394`，清 +EC/+FC/+100/+104/+F0/+F4。cache wrapper 之 `param_1` 為 `FUI::UICachingData<3,FUI::CServerSelectDialog>`；`0x5A873D` 經 `0x5A9860` 建立全域 cache `0xFE2D60`，實際 object 有配置成功條件。`0x5A7000` 回收時重新安裝該 vptr，釋放 `+FC` 私有資料，最後切換為 base vtable `0xC4A7EC` 並呼叫 `0x756590`。此析構 UI 物件流程不是 transport Conn* destructor。

**新增已確認**：事件接收函式 `0x66C620` 的原生 C++ 類別 owner = `FUI::CServerSelectDialog`，vtable offset `+0x15C`；既有 E29 的 `event+0x10` values 0x709/0x70A/0x578 確為其本地 UI 事件處理分支候選。這是 E31 所缺的 *exact vptr install + RTTI owner*。沒有證實 `0xF4243` 廣播實際轉為 `0x70A/0x578`，也不把它們當作登入 status。

### 2.2 類別生命週期、UI event 選擇與 Connect 邊界

`0x66C620`（已以原始 BIN 重驗）按 `event+0x10` 分支：`0x709` 依 identity 走 `0x66BBD0` 或 `0x66C510`，`0x70A` 要求 `event+8 == [dialog+0xF4]->+0x20`，`0x578` 要求對應 `dialog+0xF8`；兩後者 reset 3 個子 control virtual `+0x90` 後轉 `0x66C090`。`0x66C090` 選擇值在 `FUI` group/row 容器 lookup (`0x5078C0/0x507750`)；特定 `row+4` branches、row+C nonnull 和 `[0xF94294]` gate 才能呼叫 `0x4957C0`。這裡是**使用者操作/可選 UI gate**到 Connect 的路徑，不是 0x13 直接觸發。

此類別身份由 `kr-bulk-roy` 的命名提示找到，**關鍵指標位置、RTTI、兩處 install 與 slot+15C 都由同版本 BIN 重新核實**；實務上即表明 bulk 非被忽略，而是用來縮減搜尋域。

## 第三輪：連線 key、局部重用/失敗、queue 與 socket ownership 分離

### 3.1 0x495610：登入 conn key=1／0x20DF，沒有本函式內 retry loop

`0x495610` 的 `param_1=[EBP+8]` 是 Client context、`param_2=[EBP+C]` 是 host、`param_3=[EBP+10]` 是切線模式。具體分支：

| 條件 | 原生動作 | 可觀測的返回／限制 |
|---|---|---|
| `param_3==0` 且 `client+0xBF60 !=0` | 不呼叫新的 Connect，直接返回 1 | **舊連線 handle/指標重用 gate**，但沒有 socket 健康檢查，不等於 live socket 一定可用 |
| `param_3 !=0` | transport virtual+0x20(key0,1) 與 +0x20(key2,1)；若 BF60 非零，再對 key1 呼叫 +0x20(1,1)，清 client+BF60 | **發出 close/removal 類虛擬命令已證**，其底層實際 closesocket/worker join 尚待查 |
| BF60=0（或切線清除後） | transport virtual+0x18(host, port `0x20DF`, key1, arg2)，成功則 virtual+0x14 註冊該 Conn*、寫 BF60，Sleep(500)，返回 1 | key1 connector 安裝已證，第一筆 C2S 輸出未見於此函式 |
| connect 返回零 | 呼叫 `PostQuitMessage(0)`，返回 0 | **本函式內無本地自動重試迴圈**；但跨 caller 重進入不能據此排除 |

```asm
  4956b8:	39 7d 10             	cmp    DWORD PTR [ebp+0x10],edi
  4956bb:	74 7e                	je     0x49573b
  4956bd:	f6 05 f8 8b fd 00 01 	test   BYTE PTR ds:0xfd8bf8,0x1
  4956c4:	75 1a                	jne    0x4956e0
  4956c6:	83 0d f8 8b fd 00 01 	or     DWORD PTR ds:0xfd8bf8,0x1
  4956cd:	68 10 e3 bc 00       	push   0xbce310
  4956d2:	89 3d fc 8b fd 00    	mov    DWORD PTR ds:0xfd8bfc,edi
  4956d8:	e8 3d cc 3f 00       	call   0x89231a
  4956dd:	83 c4 04             	add    esp,0x4
  4956e0:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4956e6:	89 3d 00 8c fd 00    	mov    DWORD PTR ds:0xfd8c00,edi
  4956ec:	89 3d fc 8b fd 00    	mov    DWORD PTR ds:0xfd8bfc,edi
  4956f2:	8b 01                	mov    eax,DWORD PTR [ecx]
  4956f4:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  4956f7:	6a 01                	push   0x1
  4956f9:	57                   	push   edi
  4956fa:	ff d2                	call   edx
  4956fc:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495702:	8b 01                	mov    eax,DWORD PTR [ecx]
  495704:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  495707:	6a 01                	push   0x1
  495709:	6a 02                	push   0x2
  49570b:	ff d2                	call   edx
  49570d:	39 bb 60 bf 00 00    	cmp    DWORD PTR [ebx+0xbf60],edi
  495713:	74 2e                	je     0x495743
  495715:	68 04 5a c0 00       	push   0xc05a04
  49571a:	e8 41 84 25 00       	call   0x6edb60
  49571f:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495725:	8b 01                	mov    eax,DWORD PTR [ecx]
  495727:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  49572a:	83 c4 04             	add    esp,0x4
  49572d:	6a 01                	push   0x1
  49572f:	6a 01                	push   0x1
  495731:	ff d2                	call   edx
  495733:	89 bb 60 bf 00 00    	mov    DWORD PTR [ebx+0xbf60],edi
  495739:	eb 08                	jmp    0x495743
  49573b:	39 bb 60 bf 00 00    	cmp    DWORD PTR [ebx+0xbf60],edi
  495741:	75 5d                	jne    0x4957a0
  495743:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495749:	8b 01                	mov    eax,DWORD PTR [ecx]
  49574b:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  49574e:	8b 40 18             	mov    eax,DWORD PTR [eax+0x18]
  495751:	6a 02                	push   0x2
  495753:	6a 01                	push   0x1
  495755:	68 df 20 00 00       	push   0x20df
  49575a:	52                   	push   edx
  49575b:	ff d0                	call   eax
  49575d:	8b f0                	mov    esi,eax
  49575f:	3b f7                	cmp    esi,edi
  495761:	75 1e                	jne    0x495781
  495763:	57                   	push   edi
  495764:	ff 15 ec 24 bd 00    	call   DWORD PTR ds:0xbd24ec
  49576a:	33 c0                	xor    eax,eax
  49576c:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  495770:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  495777:	59                   	pop    ecx
  495778:	5f                   	pop    edi
  495779:	5e                   	pop    esi
  49577a:	5b                   	pop    ebx
  49577b:	8b e5                	mov    esp,ebp
  49577d:	5d                   	pop    ebp
  49577e:	c2 0c 00             	ret    0xc
  495781:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495787:	8b 11                	mov    edx,DWORD PTR [ecx]
  495789:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  49578c:	56                   	push   esi
  49578d:	ff d0                	call   eax
  49578f:	68 f4 01 00 00       	push   0x1f4
  495794:	89 b3 60 bf 00 00    	mov    DWORD PTR [ebx+0xbf60],esi
  49579a:	ff 15 04 23 bd 00    	call   DWORD PTR ds:0xbd2304
  4957a0:	b8 01 00 00 00       	mov    eax,0x1
  4957a5:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4957a9:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4957b0:	59                   	pop    ecx
  4957b1:	5f                   	pop    edi
  4957b2:	5e                   	pop    esi
  4957b3:	5b                   	pop    ebx
  4957b4:	8b e5                	mov    esp,ebp
  4957b6:	5d                   	pop    ebp
  4957b7:	c2               	ret    0xc
```

**上游**：本輪 raw E8 rel32 位元掃描找到 `0x495610` 的直接 callsites：`0x6D6377`、`0x6D6424`、`0x6D6508`、`0x6D65C8`、`0x6D670C`、`0x6D696C`；其中 `0x6D6508` 明確 `push 1`，其餘例 `0x6D6377` 是 `push 0`，host 值來自 Login module 參數指標中的字串（長短字串分支）。它們支援「不同入口重用／切線模式」，不等同特定官方登入 UI 按鈕順序。`0x495610` return 1 不代表 Server auth 成功。

### 3.2 0x4957C0：兩個 Connect 順序、error matrix、57-byte queue

輸入 host 同一 stack argument；transport vtable+0x18 先 key0／port `0x20E0`，再 key2／port `0x20DE`。原生正常分支 **兩者均非零** 才繼續：

1. 若原舊 login `client+BF60` 非零：`0x44D680()` 取得外部物件並可能調 virtual+0x18；`0x8063E0(oldConn)` **清理其 pending message list/將 payload 放回全域 free pool**，這個 helper 本身並未呼叫 closesocket。然後 `0x8060D0(oldConn, &0x007E, 2)` 把獨立 2 bytes 入列、寫 `oldConn+0xA0B0=1`、`client+BF60=0`。**這些動作不能合稱「舊 socket 已完全關閉」。**
2. 原生 `Sleep(0x190)` 後建構堆疊 0x39 長度的本地 payload，使用上表已填的 `client+67E0/+67E4/+6898/+6899/+68A0`，以及另有來源的 `+67FA`。
3. 對 transport virtual+0x10 以 key0 呼叫 `(0, payload, 0x39)` 進 queue，**隨後**對兩個新 Conn* 呼叫 virtual+0x14，然後賦 `client+BF64=Conn0`、`client+BF68=Conn2` 並返回 1。因不同 worker/排程/連線狀態，不能證明 0x39 就是 socket 的 first wire frame；writer 可能包上 0BBB 或 1A68 header。

| key0 returned Conn* | key2 returned Conn* | 0x4957C0 實際 branch | 限制 |
|---|---|---|---|
| 非零 | 非零 | 全部正常 gate，舊連線 queue 轉換，key0 入列 0x39，註冊兩 Conn*，返回 1 | 回傳指標／入列不等於成功 WSASend/Server 接收 |
| 非零 | 零 | 0x49597E: vtable+0x20(key0,1) 清理、log，返回 0 | +0x20 下游 close 未在本段閉合 |
| 零 | 非零 | 0x4959B0: log，vtable+0x20(key2,1)，返回 0 | 不進舊 BF60 的 queue 轉移 |
| 零 | 零 | 0x4959B0 log，再 0x49598F 第二訊息／返回 0 | 不假設任何一方重試/回滾是原版 Server 決策 |

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
  495872:	68 90 01 00 00       	push   0x190
  495877:	ff 15 04 23 bd 00    	call   DWORD PTR ds:0xbd2304
  49587d:	33 c0                	xor    eax,eax
  49587f:	b9 01 00 00        	mov    ecx,0x1
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
  49597b:	c2               	ret    0x4
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
  4959e3:	c2               	ret    0x4
```

### 3.3 物件所有權與 first-frame 的未閉合界線

- `0x806AD0` transport virtual+0x18 新 Conn 建立之 `connect(s,..)`，失敗走 `0x805AF0`（Conn 放回 pool），成功則 setsockopt/IOCP/keyed tree；`0x806C91` 透過 `0x8438C0` 查同 key，命中後 `0x7B6890` 移除舊 **tree node**，`0x57EF20` 新配置 0x18-byte node、`0x57E850` 插入。`node+0x10` 只是 Conn* 指標，E31 已證 node free 不等同 Conn* dispose。
- `0x805AF0` 自身將 pool 數量調整、串回 list、將 connection+0x14 置零；**沒有該函式內 closesocket 呼叫**。不能宣稱 connect 失敗時 socket 已被正確關閉，需追 caller/worker/OS close 路徑。
- `0x8063E0` 在 Connection 的 `+0xA0D4` CriticalSection 下遍歷 pending list，清兩個 DWORD、把 payload 指標放回全域回收 queue、清 list 並釋放 list node；沒有 closesocket。**此函式是 queue drain/回收，不是網路 FD close**。
- transport vtable+0x20 的實際 target/成功失敗路徑、`oldConn+0xA0B0=1` 對 worker 的結束訊號語意、OS `closesocket` 誰呼叫何時呼叫，均仍待追。對 duplicate-key erase 不能自動判為舊 socket 已終止。
- E19～E25 已證 `0x8061A0` mode 決策、`0x807830` 0BBB 加密/校驗與 `0x807A70` 1A68 素包 writer、`0x8068B0` WSASend/`0x806CF0` IOCP，無需重做。E32 沒有 runtime 觀察，不可證 0x39 和 0x007E 的實際 first wire order，亦不能把 key0/1/2 的 port 常數當作部署建議或官方機器角色。

## 4. 玩家／Server 相容性流程矩陣

| 玩家情境/事件 | Client local gate | C→S／queue | S→C | Client 狀態/UI/Conn | 證據等級／未解 |
|---|---|---|---|---|---|
| `0x13` status0 + 非空 UTF-16 名稱 | handler slot0x13 的 callback，`0x4C37A0` | 這個 handler 本身未證立即 send | result callback 的輸入格式/多組 cursor 局部已證 | 更新 `client+67E0/67E4/6898/6899/68A0`、群組/row cache；post F4243，條件下 F4241 | **原生局部已確認**；回覆真正 wire framing/完整邊界仍 T02/T03 |
| status5／非0／空名 | `0x4C37A0` status gate | 未確立 | result status 局部分支已證 | 本地錯誤/清理/通知；具體 UI 畫面與官方 status enum 未閉合 | **局部確認**，勿從 fixture 實例外推 |
| 玩家在 `CServerSelectDialog` 選 row | FUI event 70A/578 identity 且 5078C0/507750 lookup、value gate | 條件成立進 4957C0 key0/key2 Connect，0x39 queue (key0) | 目前未證對應的 Server 首收／回覆 | 舊 login BF60 狀態修改，成功時 BF64/BF68 設定 | **已證 UI→Connect 有條件鏈**；未證 F4243→70A producer |
| 初始化/重登入 login Conn | 495610 param3=0/!=0；BF60 是否存在 | key1 port20DF Connect；在本函式內未見首筆 payload | 未確立 | reuse、關閉類虛擬調用、success Sleep500、失敗 PostQuitMessage | **原生 branch 已證**；下游真實 close/重試未知 |
| key0 或 key2 Connect 失敗 | 4957C0 兩次 connect 結果 gate | 成功一方收到 virtual+20(key,1) | 不適用/未知 | return0，不進正常 0x39 queue | **原生 branch 已證**；完整 FD lifetime 待查 |
| 收到 0x39/0x007E 的 Server 回覆 | 未取得原版方向/類型對照 | 前者 0x39 本地 queue；後者 0x7E 二位元組在舊 Conn queue | 無 native runtime trace | 不應推斷成功選服/角色清單必跟隨 | **未知**；首包/首收和 socket 時序待遊玩驗證 |

**相容 Server 設計界線**：以上是原 Client 會要求的**局部連線與 payload 介面**。Client 編碼、群組/頻道、token、connect port roles 和 slot 切換是可能影響相容性的原生事實；但官方帳號驗證、token 發行、port 部署/重試/權限規則不可從單一 Client 靜態值臆造。S00 可據此更新 `GAP-NET-0002` 的 DRAFT/有限主張，未閉合 first-wire/close 故 **RR-0005 尚不足 S00 ACCEPTED**。

## 5. 三輪研究記錄、交叉驗證及否證

1. **E32 第一輪**：先讀 T03/`kr-bulk-roy`，首次以 BIN 核對 handler `0x4C37A0` 寫入 slot0x13，並閉合 0x13 消費字段 → Client cache → `0x4957C0` local 0x39 欄位的資料相依；不等同 immediate callback。
2. **E32 第二輪**：E31 內部表址掃描沒有找到 vptr，但新擴展至 `0xC1C390` RTTI COL 和 `0xC1C394`，在原始 BIN 找到兩處真正 vptr 安裝和 type descriptor 的 `FUI::CServerSelectDialog`；確認 `0x66C620` 虛擬 slot +0x15C／index87，克服原本 owner 身分缺口。
3. **E32 第三輪**：回到 `0x495610` 及 `0x4957C0` 的條件分支/雙 key 失敗路徑，排除把 `0x8063E0` queue drain／`0x805AF0` pool return／`0x7B6890` node erase 等同 socket close 的誤推。新增 bounded failure/return matrix，不自稱已證 retry。

**停止理由**：同一段已有兩項重大直接原生新發現（完整 UI RTTI+vptr owner、0x13→新連線 payload 的跨函式寫讀 bridge），並擴展雙連線失敗路徑；符合 02 三輪門檻。本 E32 三輪都實際執行；後續尚需跨 worker/scheduler 和 runtime 原生 trace。沒有發現任何證據足以把 E32 整篇提高為 T01 FULL-PASS。

## 6. 四類待辦與可提供的外部材料

### Client 待逆向（本地 BIN 能繼續，不阻塞 E33）

1. `0x58AAD0(0xF4243 / 0xF4241)` → UI event producer / receiver list → `0x66C620` 的事件變換、身份/選擇 gate，**不要只以兩組數字相近猜連線**。
2. transport vtable `+0x20` 真正 target（key0/1/2），其 map remove、Conn refcount、`closesocket`/CancelIo/worker completion、`+0xA0B0` close flag consumer；重新確認 `0x495610` 的 params/返回與 failure policy。
3. `0x4957C0` 新 key0 入列 0x39 的排程、是否有其他更早 C2S、key2 收發、first incoming frame 與 reconnect/retry/timeout（亦屬 T02 RR-0001/0004 交叉依賴）；`0x13` slot 上游 framed handler dispatch 的終端邊界。
4. `client+67FA` 字串來源及 0x13 中 0x90 flag/0x17/0x1C/0x92 在不同登入結果下完整原生 UI/handshake 時序。

### Server 待開發

- 保存三組 slot/本地端口及 payload shape 的相容契約，但 Server 端點部署、帳戶認證、token 核發、錯誤碼政策、重連策略應以自訂 ADR 明示，不能說是官方規則；尚缺 first response/可靠時序，不可直接宣稱 SPEC STABLE。

### 跨功能待整合

- T02 RR-0005（主責，不改台帳）、RR-0001/0004 的 transport mode；T03 RR-0003 的 `0x13` reply/通知與 RR-0002 的選角前置；T05 的角色世界切換。RR-0003 owner T03 不因 E32 追了共用字段而移轉。

### 待遊玩驗證與材料表

| 材料名稱 | 用途 | 本輪是否必需 | 缺少是否阻塞 |
|---|---|---|---|
| **同版本 Client ↔ 測試用 Server 的 `pcapng`（或精確時序日志）**，記錄每次 `connect` 的目標地址/port、成功與失敗操作、首筆 C2S/S2C 及來源時間 | 識別 key0/1/2 各自的真正 first wire frame、選服回包/close/retry 時序；需分清測試 Server 為合成回覆 | **非必需** | 不阻塞靜態 E33，但阻塞實際 wire 首包/遊玩驗收 |
| **若現有 Event.stp 及可用資源沒有，額外同版 KR UI 打包檔／資源索引與相對路徑** | 對 `CServerSelectDialog` 控件 F0/F4/F8 的**顯示名稱**與 UI layout 建立原生對照 | 可選 | 不阻塞 vtable/Connect 靜態研究；阻塞按鈕文字/資源可視身份驗證 |
| **同版 Ghidra/REA project 或精確 runtime connection trace** | 加速虛擬 target/異步生命週期、socket status 查證 | 可選 | **不阻塞** BIN-first 研究 |
| `Event.stp`、`SceneList.xml`、`TutorialBase.lua`、`TutorialMain.lua`、`qbase.lua` | E01/E06 已存在/可重建的研究素材 | **不再索取** | 不阻塞 E32/RR-0005；不要求重複上傳 |

## 7. 可重現命令與來源索引

```bash
sha256sum /mnt/data/Tartaros.bin /mnt/data/Tartaros.exe /mnt/data/Event.stp
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x4c3220 --stop-address=0x4c3270 /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x5a98b4 --stop-address=0x5a98e9 /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x495610 --stop-address=0x4957b8 /mnt/data/Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x4957c0 --stop-address=0x4959e4 /mnt/data/Tartaros.bin
```

GitHub main 研究復用：
- `kr-temp-roy/T03/`（AUTH-NATIVE-REVIEW.md、SERVER-CHOICE-REVIEW.md、PLAYABLE-FLOW-GAPS.md）（有界原生資料，非 FULL-PASS）
- `kr-bulk-roy/<SHA>/functions/`（0x5a9860.c、0x5a7000.c、0x4c3220.c、0x4c37a0.c、0x66c620.c、0x495610.c、0x4957c0.c、0x806ad0.c、0x8063e0.c、0x805af0.c）（反編譯導航）
- `research/requests/index.json`、`research/claims/index.json`、`research/intake/index.json`、`shared/verified-knowledge/README.md`（正式狀態）
- `extra/roy1` 的 `kr-extra-roy/` E01～E31，尤其 E01、E06、E27～E31。

**GitHub 狀態**：僅讀取 `main` 與 `extra/roy1`；**未 Commit／Push**，無遠端 Git blob SHA，也沒有變更 RR owner/state、T01 驗收或他 Task 原稿。應在使用者未來明確授權後才按 `extra/roy1` 研究線提交並遠端讀回驗證。
