# T10-116 — KR C→S 000A 的雙路 5-byte row 實際來源、回呼與阻斷條件（BIN-first）

研究時間：2026-10-28 21:32:48 Asia/Taipei。只研究 KR；使用者明確授權完成後上傳 `t10/roy/chatgpt-web`；未執行、修改或連線原版遊戲，未使用測試伺服器/fixture 作為證據。

## 0. 權威來源、已核對狀態與範圍

- `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；本輪實際 `sha256sum`。
- 原生 PE32 `.text` VA `0x401000`、raw `0x400`、長度 `0x7D01F0`，因此 `.text` raw = VA−`0x400C00`；`.rdata` VA `0xBD2000`、raw `0x7D0600`；`.data` VA `0xD61000`、raw `0x95E800`，FB/FE runtime 零填充 global 不可假裝可映射成原始資料值。
- 本次開工時 GitHub `main` 相對 `t10/roy/chatgpt-web` 為 `ahead 27, behind 0`；原稿 T10-115 已存在且是本段直接上游。T10-115 已證明 `0x5452C0→0x545B71→FBA854 vtable+0x10→0x8069A0(selector 0)→0x8060D0→0x806060 Pending List→pump→WSASend` 的**條件式 Client 靜態發送鏈**。本段不重複冒稱那條鏈是新發現。
- 本輪以 `objdump -D -Mintel` 親自核實 `.text` 指令；既有 T10-115 Markdown 僅作導航。原始 `0x5452C0` 函式內兩條獨立 row append 是本段重點。線性反組譯的視窗須從正確指令邊界起讀（例如 `0x545AD6`，不是 `0x545AD5`）。

## 1. 重大增量：第一條 row 的 5-byte **確切來源順序**

`0x545895` 從 stack 中的 owner 指標（此處簡稱 `A`，無 RTTI 原生名稱）取得 `A+0xC+0xC*index` 指向的子物件 `R`，並檢查 `R!=0` 以及該 12-byte slot 的 `+0x14` flag 非零。即使滿足這兩個 gate，也需 `A->virtual+0x48(index, &stack+0x34)` 回傳 `AL!=0` 才走第一條 append。不能將 `R` 認定為角色、技能或動作而無其他 class 證據。

在此路徑中：

1. `0x5458BB` 從 `R+0xB0` 讀取 byte 到 `BL`，保存到 `[esp+0x38]`。
2. `0x5458D8` 若 `A+0x58 != 0`，先把 local `[esp+0x36]` WORD 設 0，然後 `R->virtual+0x58` 被呼叫。這個間接回呼可能影響本地暫存內容；必須先核對其具體 vtable 實作才能固定高兩 byte 真正語意。若 `A+0x58==0`，跳過此回呼，不能因此認定高兩 byte 在任何 runtime 都相同。
3. `0x54590D` 無條件讀 `[R+4]` WORD，寫入 `[esp+0x34]`，**覆蓋原先 local 低兩 byte**。接著以 `0x545926` 從 `[esp+0x34]` 讀完整 DWORD，寫入 packet row 的前四 byte。換言之，**row[0..1] 已證 = WORD[R+4]**，但 **row[2..3] 必須追蹤 local 高 WORD/回呼寫入者才能命名**。
4. `0x5458FB` 從 `[esp+0x38]` 取回 flag byte（已證來源是 `R+0xB0`），`0x545932` 寫 row[4]。對這條可達路徑而言，**row[4] 已證 = BYTE[R+0xB0]**。
5. `0x545916..935` 先檢查 `length+5<=0x1000`，成功才以 `FE38D0+oldLength` 寫 4-byte DWORD 與第5 byte、再令 `FE48D0 +=5`；超界直接走 `0x545990` 而不新增此 row。

因此第一類 row 目前精確可寫為（對已確認能達到 append 的分支）：

```cpp
// 僅是原始 C→S application buffer row 的有限結構，非 gameplay 語意類別
struct RowA { uint16_t source_word_R_plus_4; uint16_t local_high_word; uint8_t source_flag_R_plus_B0; }; // packed 5 bytes
if (R && slot_enabled && virtual_48_succeeded && app_length + 5 <= 0x1000) {
    // highWord 依 A+0x58 gate / virtual+0x58 等來源決定；不能猜成技能id
    append_word(load_u16(R+4)); append_word(local_high_word);
    append_byte(load_u8(R+0xB0));
}
```

## 2. 第二條 row：actor-like 查找分支的精確差異

第二條使用 8-byte stride (`0x5459B7..5459C8`) 從 owner 的 `[A+0x30]` 取得輸入 row 項，先讀 WORD 作 `FAB13C` tree 查找 key。查不到 node / payload 為零就跳到 `0x545B1A`，**不 append**。即使查到 payload object `R`，也須通過 `A->virtual+0x44` 帶入 `A+0x30` row `+2` WORD、`R` 與可寫暫存。虛回呼成功或失敗會進不同門檻：

- 回傳 EAX 非零時，`[A+0x58]==0` 可跳過另一個 virtual；若 `A+0x58!=0` 則清 `[esp+0x2E]` WORD，後續呼叫 `R->virtual+0x58`。
- 回傳 EAX=0 時，只有 `[A+0x58]!=0` 且 `[A+0x6A] WORD` 的 bit15(`0x8000`) 設置才允許走後續處理；否則直接跳 `0x545B1A` **不 append**。
- `0x545A54` / `0x545A67` 先由 `R+0xE0` DWORD 及 `R+0xE4` byte 建立 local `[esp+0x2C] / [esp+0x30]`；後續 `0x545AD6` 使用 `[esp+0x30]`。`0x545A78` 亦從 `R+0xB0` 取得 `BL`，但在 `0x545AC8` 寫入 `[esp+0x30]` **覆蓋**此前取自 `R+0xE4` 的 local byte。因此實際 append 第 5 byte 來源依這條路徑是 `R+0xB0`，**不是未更新的 R+0xE4**。
- `0x545AEB` `mov dx,WORD [R+4]`；`0x545AF4` 寫至 `[esp+0x2C]`，仍覆蓋 local DWORD 低 WORD；`0x545B04..B10` 依這個 DWORD 寫 row 前4 byte，`0x545B10` 寫第五 byte（CL來自 `[esp+0x30]`）。
- `0x545AF9..545B13` 的 `len+5<=0x1000` 檢查，超界直接跳 `0x545B1A`，不影響之前已 append 的 row。

兩路匯合得到**共同的實際 5-byte ABI（限已核實分支）**：`u16(R+4) + u16(local_high_word) + u8(R+0xB0)`。它們**不是**相同 producer：第一路從 `A` 內部 12-byte slot 選 R，第二路從 8-byte row `key` 經 `FAB13C` tree lookup 得 R，且第二路多了 `virtual+0x44`、`A+0x6A bit15` 的 gate。這是比 T10-115「6+5*N」更實質的欄位與行為增量。

**尚需進一步限定**：`R+0xB0` 是否在所有間接回呼中維持不變、各個 virtual+0x58 是否會間接修改 R+4 或 flags，靜態單一函式尚不能窮盡；以上是發包寫入時的直接讀取來源與寄存器追蹤，不是運行期值保證。

## 3. 底層 byte-level、長度和結果區分

Header：`0x545824` 長度起始6；`0x545829` 將 `0x000A` 放入局部 WORD，`0x54584A` 將 DWORD 寫至 `FE38D0`，另 `0x545850` 將一個 WORD 寫至 `FE38D4`。`0x545B38` 比較總長度是否 `>6` 才走 `0x545B71` 虛傳輸 `+0x10`。**對本段分析的 buffer，長度公式 `6 + 5*N` 是 native 直接可證**，但不保證每次單按 Z 有 N>=1。

### 5-byte row layout（本輪能確定的物理欄位）

| Offset（row start） | size | 已確認來源 | 業務語意 |
|---:|---:|---|---|
| +0 | 2 | `WORD[R+4]` | unknown，不直稱 action/skill ID |
| +2 | 2 | local 高 WORD；受回呼／前置欄位影響 | unknown，需追真正 writer |
| +4 | 1 | `BYTE[R+0xB0]`（回呼之後重新取得 local） | unknown，不命名為方向或戰鬥狀態 |

`N<=floor((0x1000-6)/5)=818` 是單就這個 0x1000 buffer 的上界算術；**不是原版每 tick 可發 818 動作或 Server 支援 818 個技能**。如果 5-byte row 不足以追加，這條 branch 不增長封包，已存在其他 row 仍可繼續進最後發送門檻。

## 4. 與 selector0 註冊的關係、搜尋限制與反證

`0x8069A0` 使用 `FBA854` manager+0x18 的 tree 按 stack arg8 selector 查有效 connection；T10-115 的 selector=0 是實際 `0x545B6F push 0`，**但本段沒有找到 selector0 的 tree writer 或 runtime 非空證據**。第一手位元組掃描 `.text` raw `[0x400,0x7D0600)` 以 `E8 rel32` 搜尋 `0x806AD0` 得到 **0 個直接 near call 候選**；該方法不能排除 `vtable+0x18` 間接進入（原生 `C51760 → 806AD0` 已由 T10-114 證）。因此不把「0個直接呼叫」寫成此連線從未建立。

`0x806AD0` 實際讀 `[ebp+0x14]`（第四個 stack argument）寫 `[key+0xA080]`，屬分類值來源；該欄位不是連線 lookup selector=0 的直接證據。本輪也沒有查證 `manager+0x18` 的插入 key 來源，因此「selector0 確實存在」仍為 unknown。

## 5. 玩家情境 × Client × C→S × S→C × 動作／Server

| 情境 | Client gate | C→S | S→C | Motion | Server/證據 |
|---|---|---|---|---|---|
| 短按 Z 且當前 bank 映射 ID13 | T10-101~103 已證輸入 phase→controller bit0 的條件式鏈；本段增加 row 寫入具體來源 | 000A 可按條件追加 row 並入 Pending/WSASend；**不保證每次按鍵都發** | 本段未核對對應回覆 | 本地是否先播 unknown | 原生部分確定；Server 判定 unknown |
| row 第一類，slot enable 且 virtual48 成功 | `R+4`、`R+0xB0`、高 WORD local | 只在長度+5<=0x1000 時 append | 未因這個分支確認 | unknown | 本地 row producer native |
| row 第二類，tree lookup 命中且 virtual44 通過（或允許 fallback） | `R+4`、`R+0xB0`、local high WORD | 同上，可能與第一類合批 | unknown | unknown | 有界 fallback native |
| 沒有 row 成功 append | 長度仍6 | `0x545B71` 不執行此發送入口 | 不適用本分支 | unknown | 只是此 builder 不送 |
| selector0 tree 缺失 | `0x8069A0` lookup fail | 不入列 | unknown | unknown | 已證失敗 branch，不等於 runtime 一定失敗 |
| Z 連按／施放中 Z／鍵盤或滑鼠移動 | 尚未核對全部外層 gate | 次數／發送與否 unknown | unknown | combo/cancel unknown | 不採 AI 時窗 |

## 6. 輪次、下一研究入口

**T10-116 第一輪：** 新增兩種 row 的分別 producer、精確 `u16+u16+u8` 直接讀取來源、第二路 fallback gate、包含回呼覆蓋之後的 byte provenance、兩路合批的實質證據。這符合共用 02 的重大功能鏈增量門檻；`T10-116-2`/`-3` **未啟動**。不能擴張為 gameplay 端到端可玩驗收。

**T10-117 優先**：核對 `A->virtual+0x48/+0x44` 實作及 `R->virtual+0x58` 的真正高 WORD writer；逆追 `FBA854 manager+0x18` selector0 tree 插入點及連線 owner 註冊；再從 category2 app key13 S→C motion consumer 向 actor 實際動作反查，區分 local／remote 是否預播。不得用 fixture 的 combo timing 補不明欄位。

## 7. 原始機器碼附錄（本輪實際 BIN disassembly，可重現）

### VA 0x545887 .. 0x54593e (raw subtract 0x400C00)
```asm
Disassembly of section .text:

00545887 <.text+0x144887>:
  545887:	8b 0d 44 39 f9 00    	mov    ecx,DWORD PTR ds:0xf93944
  54588d:	89 0d d2 38 fe 00    	mov    DWORD PTR ds:0xfe38d2,ecx
  545893:	33 ff                	xor    edi,edi
  545895:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  545899:	8d 14 7f             	lea    edx,[edi+edi*2]
  54589c:	8b 74 90 0c          	mov    esi,DWORD PTR [eax+edx*4+0xc]
  5458a0:	8d 04 90             	lea    eax,[eax+edx*4]
  5458a3:	85 f6                	test   esi,esi
  5458a5:	0f 84 e5 00 00 00    	je     0x545990
  5458ab:	80 78 14 00          	cmp    BYTE PTR [eax+0x14],0x0
  5458af:	0f 84 db 00 00 00    	je     0x545990
  5458b5:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  5458b9:	8b 11                	mov    edx,DWORD PTR [ecx]
  5458bb:	8a 9e b0 00 00 00    	mov    bl,BYTE PTR [esi+0xb0]
  5458c1:	8b 52 48             	mov    edx,DWORD PTR [edx+0x48]
  5458c4:	8d 44 24 34          	lea    eax,[esp+0x34]
  5458c8:	50                   	push   eax
  5458c9:	57                   	push   edi
  5458ca:	88 5c 24 20          	mov    BYTE PTR [esp+0x20],bl
  5458ce:	ff d2                	call   edx
  5458d0:	84 c0                	test   al,al
  5458d2:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  5458d6:	74 66                	je     0x54593e
  5458d8:	83 78 58 00          	cmp    DWORD PTR [eax+0x58],0x0
  5458dc:	74 1d                	je     0x5458fb
  5458de:	33 c0                	xor    eax,eax
  5458e0:	66 89 44 24 36       	mov    WORD PTR [esp+0x36],ax
  5458e5:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  5458e9:	88 5c 24 38          	mov    BYTE PTR [esp+0x38],bl
  5458ed:	8b 16                	mov    edx,DWORD PTR [esi]
  5458ef:	8b 52 58             	mov    edx,DWORD PTR [edx+0x58]
  5458f2:	50                   	push   eax
  5458f3:	8b ce                	mov    ecx,esi
  5458f5:	ff d2                	call   edx
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

### VA 0x5459b7 .. 0x545a55 (raw subtract 0x400C00)
```asm
Disassembly of section .text:

005459b7 <.text+0x1449b7>:
  5459b7:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  5459bb:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  5459bf:	8b 72 30             	mov    esi,DWORD PTR [edx+0x30]
  5459c2:	03 c0                	add    eax,eax
  5459c4:	03 c0                	add    eax,eax
  5459c6:	03 c0                	add    eax,eax
  5459c8:	03 f0                	add    esi,eax
  5459ca:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  5459d1:	75 29                	jne    0x5459fc
  5459d3:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  5459da:	c7 44 24 48 11 00 00 	mov    DWORD PTR [esp+0x48],0x11
  5459e1:	00 
  5459e2:	e8 a9 92 f9 ff       	call   0x4dec90
  5459e7:	68 30 ce bc 00       	push   0xbcce30
  5459ec:	e8 29 c9 34 00       	call   0x89231a
  5459f1:	83 c4 04             	add    esp,0x4
  5459f4:	c7 44 24 48 ff ff ff 	mov    DWORD PTR [esp+0x48],0xffffffff
  5459fb:	ff 
  5459fc:	0f b7 16             	movzx  edx,WORD PTR [esi]
  5459ff:	8b 35 3c b1 fa 00    	mov    esi,DWORD PTR ds:0xfab13c
  545a05:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  545a08:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  545a0c:	8b ce                	mov    ecx,esi
  545a0e:	75 14                	jne    0x545a24
  545a10:	39 50 0c             	cmp    DWORD PTR [eax+0xc],edx
  545a13:	73 05                	jae    0x545a1a
  545a15:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  545a18:	eb 04                	jmp    0x545a1e
  545a1a:	8b c8                	mov    ecx,eax
  545a1c:	8b 00                	mov    eax,DWORD PTR [eax]
  545a1e:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  545a22:	74 ec                	je     0x545a10
  545a24:	89 4c 24 20          	mov    DWORD PTR [esp+0x20],ecx
  545a28:	3b ce                	cmp    ecx,esi
  545a2a:	74 0b                	je     0x545a37
  545a2c:	3b 51 0c             	cmp    edx,DWORD PTR [ecx+0xc]
  545a2f:	72 06                	jb     0x545a37
  545a31:	8d 44 24 20          	lea    eax,[esp+0x20]
  545a35:	eb 08                	jmp    0x545a3f
  545a37:	89 74 24 24          	mov    DWORD PTR [esp+0x24],esi
  545a3b:	8d 44 24 24          	lea    eax,[esp+0x24]
  545a3f:	8b 00                	mov    eax,DWORD PTR [eax]
  545a41:	3b c6                	cmp    eax,esi
  545a43:	0f 84 d1 00 00 00    	je     0x545b1a
  545a49:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  545a4c:	85 f6                	test   esi,esi
  545a4e:	0f 84 c6 00 00 00    	je     0x545b1a
  545a54:	8b         	mov    eax,DWORD PTR [esi+0xe0]
```

### VA 0x545a54 .. 0x545b1a (raw subtract 0x400C00)
```asm
Disassembly of section .text:

00545a54 <.text+0x144a54>:
  545a54:	8b 86 e0 00 00 00    	mov    eax,DWORD PTR [esi+0xe0]
  545a5a:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  545a5e:	8b 17                	mov    edx,DWORD PTR [edi]
  545a60:	8b 52 44             	mov    edx,DWORD PTR [edx+0x44]
  545a63:	89 44 24 2c          	mov    DWORD PTR [esp+0x2c],eax
  545a67:	8a 8e e4 00 00 00    	mov    cl,BYTE PTR [esi+0xe4]
  545a6d:	8b 47 30             	mov    eax,DWORD PTR [edi+0x30]
  545a70:	88 4c 24 30          	mov    BYTE PTR [esp+0x30],cl
  545a74:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  545a78:	8a 9e b0 00 00 00    	mov    bl,BYTE PTR [esi+0xb0]
  545a7e:	03 c9                	add    ecx,ecx
  545a80:	03 c9                	add    ecx,ecx
  545a82:	03 c9                	add    ecx,ecx
  545a84:	03 c1                	add    eax,ecx
  545a86:	0f b7 40 02          	movzx  eax,WORD PTR [eax+0x2]
  545a8a:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  545a8e:	51                   	push   ecx
  545a8f:	56                   	push   esi
  545a90:	50                   	push   eax
  545a91:	8b cf                	mov    ecx,edi
  545a93:	88 5c 24 28          	mov    BYTE PTR [esp+0x28],bl
  545a97:	ff d2                	call   edx
  545a99:	85 c0                	test   eax,eax
  545a9b:	74 0f                	je     0x545aac
  545a9d:	83 7f 58 00          	cmp    DWORD PTR [edi+0x58],0x0
  545aa1:	74 33                	je     0x545ad6
  545aa3:	33 c0                	xor    eax,eax
  545aa5:	66 89 44 24 2e       	mov    WORD PTR [esp+0x2e],ax
  545aaa:	eb 18                	jmp    0x545ac4
  545aac:	83 7f 58 00          	cmp    DWORD PTR [edi+0x58],0x0
  545ab0:	74 68                	je     0x545b1a
  545ab2:	b8 00 80 00 00       	mov    eax,0x8000
  545ab7:	66 85 47 6a          	test   WORD PTR [edi+0x6a],ax
  545abb:	74 5d                	je     0x545b1a
  545abd:	33 c9                	xor    ecx,ecx
  545abf:	66 89 4c 24 2e       	mov    WORD PTR [esp+0x2e],cx
  545ac4:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  545ac8:	88 5c 24 30          	mov    BYTE PTR [esp+0x30],bl
  545acc:	8b 16                	mov    edx,DWORD PTR [esi]
  545ace:	8b 52 58             	mov    edx,DWORD PTR [edx+0x58]
  545ad1:	50                   	push   eax
  545ad2:	8b ce                	mov    ecx,esi
  545ad4:	ff d2                	call   edx
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
```

### VA 0x545b1a .. 0x545b75 (raw subtract 0x400C00)
```asm
Disassembly of section .text:

00545b1a <.text+0x144b1a>:
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
  545b73:	8b 5c            	mov    ebx,DWORD PTR [esp+0x14]
```

### VA 0x8069a0 .. 0x8069f5 (raw subtract 0x400C00)
```asm
Disassembly of section .text:

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