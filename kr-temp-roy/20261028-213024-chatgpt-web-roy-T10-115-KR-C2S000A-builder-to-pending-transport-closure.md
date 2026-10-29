# T10-115 — KR C→S 000A：`0x5452C0` 建包到 `0x8069A0` 分連線入列的原生呼叫閉環

**研究日期（Asia/Taipei）：** 20261028-213024。**正式段號 T10-115；第一輪重大新發現達標**。唯讀 KR BIN/EXE 靜態研究，未執行、patch 或連接原版客戶端；無現場 wire capture。GitHub 目標分支 `t10/roy/chatgpt-web`；不直接變更 main／T02 等其他 Task。此稿的原始 assembly 來自本輪真實 BIN objdump，先前 T10-101～114 的研究只用作導航及既有已核證的限定前提。

## 0. 來源和位址核對

- `Tartaros.bin` **SHA256** `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` **SHA256** `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，本輪重新計算。
- KR BIN PE32，`.text` VA `0x401000`／raw `0x400`，VA=`raw+0x400C00`；`.rdata` VA `0xBD2000`／raw `0x7D0600`，raw=`VA−0x401A00`。下列範圍只用於原生指令；FB／FE 全域 runtime 資料不可假稱有相同 raw 初始值。
- 本輪直接讀 `.rdata` 以 struct little-endian DWORD 確認 `0xC51758`（虛表 `0xC51748 +0x10`）的值是 `0x008069A0`；原始四位元組 `A0 69 80 00`。同表 `+0xC = 0x8068B0`（WSASend wrapper，T10-114 完整建立 constructor/storage/caller）。
- GitHub 最新 T10-114 指出 `0x5452C0` 至 `0x8069A0` 原本缺少直接 output provenance；本輪找到**明確的 `0x545B71 call edx` 和虛表 slot +0x10**，使原先缺口縮小到具體連線查找與後續成功門檻。

## 1. 第一輪：戰鬥批次輸出在 `0x545B71` 明確使用傳輸物件的 virtual+0x10

在 `0x5457FF..0x54585C` 已核對的正常可發送路徑上，先處理全域 `0xFE48D0` 的累積長度與 `0xFE38D0` 暫存緩衝。`0x545824 mov eax,6` 及 `0x545829 mov edx,0xA` 之後，`0x54583C mov [0xFE48D0],eax` 設初始累積長度 **6 bytes**。`0x54584A` 將含有 opcode WORD `0x000A` 的 DWORD 寫至 `0xFE38D0`；`0x545850` 寫 header 另一 WORD。它不是直接傳給 socket API。

其中每個符合控制器條件的 row 有可能以 **5 bytes** 加入這塊應用緩衝。第一個 append 分支的 `0x545916..0x545935`：`new_size = FE48D0 + 5`，僅當 `new_size <= 0x1000` 時，將 local DWORD 寫入 `FE38D0+old_size`，接著將第五個 byte 寫 `+4`，最後 `FE48D0 +=5`。第二個 row 處理路徑 `0x545AEF..0x545B13` 亦是 5-byte append；但**兩條分支具備各自的虛回呼／狀態條件**，不代表所有 row 都會形成 packet entry。

**真正 outbound call：** `0x545B38 cmp DWORD [0xFE48D0],6; 0x545B43 jbe 0x545B73`。因此只有 buffer 長度 **大於 6** 才執行 `0x545B45..0x545B71`。實際指令：

```asm
545b45 mov eax,[esp+0x28]              ; 目前 tick 的時間／狀態候選，精確語義見前段
545b49 mov ecx,[0xfba854]             ; 已確認的傳輸物件 singleton
545b4f dec dword [0xfba7b0]           ; 內部計數；不可解讀為封包數
545b55 mov dword [esi+0x74],0
545b5c mov [esi+0x64],eax
545b5f mov eax,[0xfe48d0]             ; 封包應用資料總長度，6+5*N
545b64 mov edx,[ecx]                  ; vptr
545b66 mov edx,[edx+0x10]             ; vtable slot +0x10
545b69 push eax                         ; len
545b6a push 0xfe38d0                    ; payload pointer
545b6f push 0                           ; connection selector/index
545b71 call edx
545b73 ...                                ; 長度 <=6 直接到此
```

因此相對 `0x8069A0` 函式 ABI：`ECX=transport manager FBA854`，stack `arg8=0`（lookup index）、`argC=FE38D0`（指標）、`arg10=FE48D0`（長度）。**這個 `0` 是傳輸連線 lookup selector，不是「opcode0」**。`0x5452C0` 中的 `0x000A` 屬於應用緩衝首 WORD；兩者不得混淆。

### 1.1 驗證 vtable 實作而非猜 virtual target

T10-114 原生 constructor `0x8046F7` 指派 vptr `0xC51748`，`0x80470F` 寫全域 `0xFBA854`。本輪重新讀表 `0xC51758` 指向 `0x8069A0`，因此在此已確認的實作類型下，`0x545B71` 真的進入 `0x8069A0`。需保留 runtime vptr 被更換／全域物件被替換未窮盡的限制，並不是動態封包抓取。

## 2. 分連線：`0x8069A0` 的 lookup、失敗分支與入列呼叫

`0x8069A0` 的 `ECX=manager`，將 `arg8` 的 selector/index 地址交給 `0x8438C0`，使用 `manager+0x18` 的樹容器進行查找。`0x8069BF` 把 iterator 結果與 `[manager+0x1C]` sentinel 比較；若查不到或 node+0x10 的 connection pointer 為零，`0x8069CC` 返回0，**並未呼叫 `0x8060D0`**。若查到有效連線且 `arg10==0`，`0x8069DB` 返回1，不入列（此處是本地返回成功候選，而非資料傳送）。只有有效連線且長度非零時：

```asm
8069e6 mov edx,[ebp+0x0c]       ; payload pointer FE38D0
8069e9 push eax                  ; len
8069ea push edx                  ; payload pointer
8069eb call 0x8060d0            ; ECX = lookup 返回的 connection pointer
8069f3 ret 0x0c                 ; 清理 selector/payload/len
```

- `0x545B6F` selector 固定0；**是否存在 selector=0 的連線必須檢查現場 manager tree，不能從靜態證據保證。**
- 此發送入口的成功與失敗由 `0x8069A0`/`0x8060D0` 返回，`0x545B71` 後並未以本函式內顯式判斷 `EAX` 進行重試。不能在這裏捏造「遇到失敗必重發」。

## 3. `0x8060D0`：上限與 Pending List 生命週期

`0x8060D0` 收 `ECX=connection`、`arg8=data`、`argC=len`，先檢查 `[connection+0xA0A4] > 0x12C` 時返回0，未建立這筆成功入列記錄。否則從 `0xFE3358` 來源配置/取得 item，`0x80615B cmp EBX,0x1000`；長度不超過 `0x1000` 時經 `0x89DBD0` 複製到 `item+8`，寫 `[item+4]=len`。隨後 `0x806177 push item; 0x806178 call 0x806060`，將它加入 Connection Pending List。

這裡有一個必須保留的邊界：若 `len > 0x1000`，`0x80615B..0x806177` 跳過複製／len store，但控制仍流向 `0x806060`。**不能未審核 `0x807470` 新 item 初始狀態就聲稱大於4096 一定直接拒絕**。對本段 builder 而言，每次 append 受 `<=0x1000` gate，正常完成的應用資料長度在這個邊界內；但並未動態測所有跨函式狀態。

`0x806060` 經連線同步鎖 `+0xA0D4`、`0x74D700` 將 item 插入 `connection+0xA074` Pending List，更新 `connection+0xA078` 節點數，釋放同步鎖，最後寫 `[connection+0xA024]=1` 並返回1。它**只證實寫入待送佇列，不是 WSASend 已完成**。

T10-112～114 先前已驗證後續：`0x8061A0` pump 以 mode 選 `0x807A70/0x807830` 將待送 records 封入 connection+`0x5020`，再由兩條 update paths 在 `+A028>0`、`+A0B8<=0`、其他外層 gate 成立時，透過 `FBA854` vtable+`0xC → 0x8068B0 → WSASend` 送出。**本輪的新增是首次由「具體 000A builder」接入這段既有下游鏈。**

### 完整但有條件的 Client 鏈

```text
已確認的鍵盤來源 / mapping (T10-101/102/103)
  當前 bank 若含 Key44(Z)→ID13，phase1/2，UI未先消耗等前提
    → controller input bit0 (受 actor、SkillMatrix、timer 等 gate)
    → 0x5452C0（只在有完整 game/tick 條件時執行）
       FE38D0[0..1] = 000A; FE48D0 = 6
       +5 bytes * 成功追加的 row 數
       only if FE48D0 > 6:
         0x545B71 → FBA854 vtable+0x10 → 0x8069A0(selector=0)
         if lookup connection exists and len !=0:
            → 0x8060D0 → 0x806060 Pending List
            → 0x8061A0 frame pump (807A70/807830)
            → +A028>0/+A0B8<=0, other gates:
            → FBA854 vtable+0xC → 0x8068B0 → 0x806912 WSASend
```

重要：上圖把各段已證的**條件式 Client static path**接起來，沒有動態同一次按鍵的封包記錄，也沒有確認 Wire 原始 frame 的全部欄位、實際發送時序或 Server 何時 ACK。`0x000A` 是應用資料開頭 opcode；傳輸 frame prefix `0x1A68` 等是另一層，不能混寫。

## 4. 玩家情境、Server 分工與反證矩陣

| 情境 | Client gate/判斷 | C→S | S→C | 角色 motion | 證據等級/責任 |
|---|---|---|---|---|---|
| 一次短按 Z，bank 含 Key44→ID13 | phase1/2→bit0，受 UI/actor/matrix/timer gate 限制 | **已確認可達** 000A buffer→selector0→Pending→WSASend 的條件式靜態路徑；非每次必送 | 尚未識別專屬 ack | 本地是否先播未知 | Client 原生鏈有界閉合；Server 規則未知 |
| 長按／連按／放開 Z | phase2/phase1/phase3 的可用性依當前 bank、結果消費及控制器 tick | 包數、節流、頻率 unknown | unknown | combo/cancel unknown | 無真實按鍵/封包 trace |
| 000A 沒有任何 5-byte row | 長度保留6 | **不會由此 `0x545B71` 呼叫送出入口** | 不適用本分支 | 無直接結論 | 原生有界否證，不代表全遊戲沒有其他封包 |
| selector0 不在 manager 連線樹 | `0x8069A0` 返回0 | **本分支不入列** | 未由此產生 | 不確定 | 本地失敗路徑已確認 |
| connection pending-count >0x12C | `0x8060D0` 早退0 | **本分支不新入列** | 不適用 | 不確定 | queue backpressure 已確認；不是原版 Server 拒絕 |
| 有 item 入列但 send gate 關閉 | 已建立 Pending，尚需 pump及有效 socket | 尚不能保證 `WSASend` 執行 | OS send completion 不等於 game ack | 不確定 | 各層分工需分清 |
| 施放技能中再次按 Z／鍵盤／滑鼠移動 | 尚未核對相關 phase gate 及 device event def-use | unknown | unknown | unknown | T10/T11 界面待驗 |

## 5. 輪次、限制與下一正式入口

- **T10-115 第1輪達標：** `0x545B71` 的真實 virtual+0x10 由 `.rdata C51758` 解到 `0x8069A0`，結合 `0x8069EB → 0x8060D0` 和 `0x806178 → 0x806060`，首次把 000A 批次 builder 接至 Pending List 與已證下游 WSASend 鏈。對已明確前提可構成可驗證**完整條件式 Client 發送途徑**；無須啟動 `T10-115-2/-3`。這不代表「玩家每按一次 Z 就一包」或「Server 接受攻擊」已證。
- 未確認：連線 selector0 實際建立條件、`0x807470` 對超界 item 初始化、outer tick/phase 决策的完整時序、000A 每個 record 的精確欄位及所有合法值、socket frame 最後二進位、S→C motion 與000A的因果、連段取消/施放中輸入與兩類移動。所有 Server 裁決依相容介面列為待開發，不採任何自製 0.65s/fixture。
- **T10-116 優先**：追 `0x806AD0` 分類/連線建立處如何向 transport manager 的 tree 插入 selector0→connection；核對 000A 5-byte record 真正 byte layout 和多 row／合批條件；S→C key13 motion handler 到 local/remote actor 的實際 consumer，確定回包是否為動作啟動必要條件。

## 6. 可重現 BIN 命令

```bash
sha256sum Tartaros.bin Tartaros.exe
objdump -D -Mintel --start-address=0x5457ff --stop-address=0x545858 Tartaros.bin
objdump -D -Mintel --start-address=0x5458f7 --stop-address=0x54593e Tartaros.bin
objdump -D -Mintel --start-address=0x545ad6 --stop-address=0x545b9f Tartaros.bin
objdump -D -Mintel --start-address=0x8069a0 --stop-address=0x8069f6 Tartaros.bin
objdump -D -Mintel --start-address=0x8060d0 --stop-address=0x806191 Tartaros.bin
objdump -D -Mintel --start-address=0x806060 --stop-address=0x8060ce Tartaros.bin
```

## 7. 第一手完整原生指令附錄（各研究窗口）

### 000A header & gate — VA `0x005457ff..0x00545858`；raw `0x00144bff..0x00144c58`

```asm

005457ff <.text+0x1447ff>:
  5457ff:	f6 05 68 72 fe 00 01 	test   BYTE PTR ds:0xfe7268,0x1
  545806:	75 1a                	jne    0x545822
  545808:	83 0d 68 72 fe 00 01 	or     DWORD PTR ds:0xfe7268,0x1
  54580f:	68 30 f2 bc 00       	push   0xbcf230
  545814:	89 35 d0 48 fe 00    	mov    DWORD PTR ds:0xfe48d0,esi
  54581a:	e8 fb ca 34 00       	call   0x89231a
  54581f:	83 c4 04             	add    esp,0x4
  545822:	33 c0                	xor    eax,eax
  545824:	b8 06 00 00 00       	mov    eax,0x6
  545829:	ba 0a 00 00 00       	mov    edx,0xa
  54582e:	66 89 54 24 2c       	mov    WORD PTR [esp+0x2c],dx
  545833:	8b 4c 24 2c          	mov    ecx,DWORD PTR [esp+0x2c]
  545837:	66 8b 54 24 30       	mov    dx,WORD PTR [esp+0x30]
  54583c:	a3 d0 48 fe 00       	mov    ds:0xfe48d0,eax
  545841:	33 c0                	xor    eax,eax
  545843:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  54584a:	89 0d d0 38 fe 00    	mov    DWORD PTR ds:0xfe38d0,ecx
  545850:	66 89 15 d4 38 fe 00 	mov    WORD PTR ds:0xfe38d4,dx
  545857:	66           	mov    WORD PTR [esp+0x34],ax
```

### record append branch — VA `0x005458f7..0x0054593e`；raw `0x00144cf7..0x00144d3e`

```asm

005458f7 <.text+0x1448f7>:
  5458f7:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  5458fb:	8a 4c 24 38          	mov    cl,BYTE PTR [esp+0x38]
  5458ff:	85 ff                	test   edi,edi
  545901:	75 0a                	jne    0x54590d
  545903:	8b 54 24 34          	mov    edx,DWORD PTR [esp+0x34]
  545907:	89 50 68             	mov    DWORD PTR [eax+0x68],edx
  54590a:	88 48 6c             	mov    BYTE PTR [eax+0x6c],cl
  54590d:	66 8b 46 04          	mov    ax,WORD PTR [esi+0x4]
  545911:	66 89 44 24 34       	mov    WORD PTR [esp+0x34],ax
  545916:	a1 d0 48 fe 00       	mov    eax,ds:0xfe48d0
  54591b:	8d 50 05             	lea    edx,[eax+0x5]
  54591e:	81 fa 00 10 00 00    	cmp    edx,0x1000
  545924:	77 6a                	ja     0x545990
  545926:	8b 54 24 34          	mov    edx,DWORD PTR [esp+0x34]
  54592a:	8d 80 d0 38 fe 00    	lea    eax,[eax+0xfe38d0]
  545930:	89 10                	mov    DWORD PTR [eax],edx
  545932:	88 48 04             	mov    BYTE PTR [eax+0x4],cl
  545935:	83 05 d0 48 fe 00 05 	add    DWORD PTR ds:0xfe48d0,0x5
  54593c:	eb 52                	jmp    0x545990
```

### final builder & selector call — VA `0x00545ad6..0x00545b9f`；raw `0x00144ed6..0x00144f9f`

```asm

00545ad6 <.text+0x144ad6>:
  545ad6:	83 7c 24 18 00       	cmp    DWORD PTR [esp+0x18],0x0
  545adb:	8a 4c 24 30          	mov    cl,BYTE PTR [esp+0x30]
  545adf:	75 0a                	jne    0x545aeb
  545ae1:	8b 44 24 2c          	mov    eax,DWORD PTR [esp+0x2c]
  545ae5:	89 47 68             	mov    DWORD PTR [edi+0x68],eax
  545ae8:	88 4f 6c             	mov    BYTE PTR [edi+0x6c],cl
  545aeb:	66 8b 56 04          	mov    dx,WORD PTR [esi+0x4]
  545aef:	a1 d0 48 fe 00       	mov    eax,ds:0xfe48d0
  545af4:	66 89 54 24 2c       	mov    WORD PTR [esp+0x2c],dx
  545af9:	8d 50 05             	lea    edx,[eax+0x5]
  545afc:	81 fa 00 10 00 00    	cmp    edx,0x1000
  545b02:	77 16                	ja     0x545b1a
  545b04:	8b 54 24 2c          	mov    edx,DWORD PTR [esp+0x2c]
  545b08:	8d 80 d0 38 fe 00    	lea    eax,[eax+0xfe38d0]
  545b0e:	89 10                	mov    DWORD PTR [eax],edx
  545b10:	88 48 04             	mov    BYTE PTR [eax+0x4],cl
  545b13:	83 05 d0 48 fe 00 05 	add    DWORD PTR ds:0xfe48d0,0x5
  545b1a:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  545b1e:	8b 51 34             	mov    edx,DWORD PTR [ecx+0x34]
  545b21:	2b 51 30             	sub    edx,DWORD PTR [ecx+0x30]
  545b24:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  545b28:	40                   	inc    eax
  545b29:	c1 fa 03             	sar    edx,0x3
  545b2c:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  545b30:	3b c2                	cmp    eax,edx
  545b32:	0f 82 7f fe ff ff    	jb     0x5459b7
  545b38:	83 3d d0 48 fe 00 06 	cmp    DWORD PTR ds:0xfe48d0,0x6
  545b3f:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  545b43:	76 2e                	jbe    0x545b73
  545b45:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  545b49:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  545b4f:	ff 0d b0 a7 fb 00    	dec    DWORD PTR ds:0xfba7b0
  545b55:	c7 46 74 00 00 00 00 	mov    DWORD PTR [esi+0x74],0x0
  545b5c:	89 46 64             	mov    DWORD PTR [esi+0x64],eax
  545b5f:	a1 d0 48 fe 00       	mov    eax,ds:0xfe48d0
  545b64:	8b 11                	mov    edx,DWORD PTR [ecx]
  545b66:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  545b69:	50                   	push   eax
  545b6a:	68 d0 38 fe 00       	push   0xfe38d0
  545b6f:	6a 00                	push   0x0
  545b71:	ff d2                	call   edx
  545b73:	8b 5c 24 14          	mov    ebx,DWORD PTR [esp+0x14]
  545b77:	33 c0                	xor    eax,eax
  545b79:	66 89 46 5c          	mov    WORD PTR [esi+0x5c],ax
  545b7d:	83 7b 58 00          	cmp    DWORD PTR [ebx+0x58],0x0
  545b81:	74 07                	je     0x545b8a
  545b83:	c7 43 58 00 00 00 00 	mov    DWORD PTR [ebx+0x58],0x0
  545b8a:	33 c0                	xor    eax,eax
  545b8c:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
  545b90:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  545b97:	59                   	pop    ecx
  545b98:	5f                   	pop    edi
  545b99:	5e                   	pop    esi
  545b9a:	5b                   	pop    ebx
  545b9b:	8b e5                	mov    esp,ebp
  545b9d:	5d                   	pop    ebp
  545b9e:	c3                   	ret
```

### transport vtable +10 target — VA `0x008069a0..0x008069f6`；raw `0x00405da0..0x00405df6`

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
  8069f3:	c2 0c 00             	ret    0xc
```

### outbound queue item copy — VA `0x008060d0..0x00806191`；raw `0x004054d0..0x00405591`

```asm

008060d0 <.text+0x4050d0>:
  8060d0:	55                   	push   ebp
  8060d1:	8b ec                	mov    ebp,esp
  8060d3:	6a ff                	push   0xffffffff
  8060d5:	68 5e 99 90 00       	push   0x90995e
  8060da:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  8060e0:	50                   	push   eax
  8060e1:	53                   	push   ebx
  8060e2:	56                   	push   esi
  8060e3:	57                   	push   edi
  8060e4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  8060e9:	33 c5                	xor    eax,ebp
  8060eb:	50                   	push   eax
  8060ec:	8d 45 f4             	lea    eax,[ebp-0xc]
  8060ef:	64 a3 00 00 00 00    	mov    fs:0x0,eax
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
  80618e:	c2 08 00             	ret    0x8
```

### pending list append — VA `0x00806060..0x008060ce`；raw `0x00405460..0x004054ce`

```asm

00806060 <.text+0x405060>:
  806060:	55                   	push   ebp
  806061:	8b ec                	mov    ebp,esp
  806063:	8b 86 d4 a0 00 00    	mov    eax,DWORD PTR [esi+0xa0d4]
  806069:	57                   	push   edi
  80606a:	50                   	push   eax
  80606b:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  806071:	8b be 74 a0 00 00    	mov    edi,DWORD PTR [esi+0xa074]
  806077:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  80607a:	8d 4d 08             	lea    ecx,[ebp+0x8]
  80607d:	51                   	push   ecx
  80607e:	52                   	push   edx
  80607f:	57                   	push   edi
  806080:	e8 7b 76 f4 ff       	call   0x74d700
  806085:	8b 8e 78 a0 00 00    	mov    ecx,DWORD PTR [esi+0xa078]
  80608b:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  806090:	2b d1                	sub    edx,ecx
  806092:	83 fa 01             	cmp    edx,0x1
  806095:	73 0a                	jae    0x8060a1
  806097:	68 34 20 bf 00       	push   0xbf2034
  80609c:	e8 8f 7a 07 00       	call   0x87db30
  8060a1:	41                   	inc    ecx
  8060a2:	89 8e 78 a0 00 00    	mov    DWORD PTR [esi+0xa078],ecx
  8060a8:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  8060ab:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  8060ae:	89 01                	mov    DWORD PTR [ecx],eax
  8060b0:	8b 96 d4 a0 00 00    	mov    edx,DWORD PTR [esi+0xa0d4]
  8060b6:	52                   	push   edx
  8060b7:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  8060bd:	c6 86 24 a0 00 00 01 	mov    BYTE PTR [esi+0xa024],0x1
  8060c4:	b8 01 00 00 00       	mov    eax,0x1
  8060c9:	5f                   	pop    edi
  8060ca:	5d                   	pop    ebp
  8060cb:	c2 04 00             	ret    0x4
```