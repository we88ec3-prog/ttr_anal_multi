# T16-106 — KR 場景 callback 表、TalkBoxDialog 型別補證及 4-byte UI 發送候選（BIN-first，三輪）

- 研究者：`chatgpt-web roy`；本地記錄：`2026-10-29T22:51:43.253655+08:00`；研究版本：**KR**。
- 最新 GitHub 開工基準：`main=43c51f579cada3aa6257eb8467f65af281c3585b`、`t16/roy/chatgpt-web=6723fd0b0da2b870812450ee424574e96c10555b`；使用 GitHub compare `main...t16/roy/chatgpt-web` 驗證 **ahead=22，behind=0**，因此**無須再 merge**；未建立任何 Commit／Push；請勿將本文的未提交路徑當成遠端 Git blob。
- `kr/tasks/T16/README.md`：**43 個 `READY_FOR_REVIEW`；0 個新的 `NEEDS_FIX`、0 個 `RESOLVED`**。43 筆為作者端送審，T01 尚未完成獨立複驗，不能升格 FULL-PASS。`research/dispatch/inbox/T16.md` 與 `research/requests/index.json` 沒有本 Task 待處理 RR。
- GitHub 正式研究稿最高為 `T16-105`，本篇 `T16-106` 為本地新段；舊原稿不覆寫。
- 原件：`Tartaros.bin` **12,472,320 bytes**，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` **2,594,816 bytes**，SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；兩者與 03 指定值精確一致。未執行、修補或附加目標。
- 靜態工具：Python `struct`／`hashlib`，`objdump -D -b binary -m i386 -M intel`，依有界函式入口/已證跳轉解碼；不是遊戲封包抓取或執行時 trace。資料表及 RTTI 用 PE section 原生 bytes 獨立查證。

## 1. 本段結果與原生限制（摘要）

**A. 場景接收器的型別界線（新）**：`0x4ADD50` 初始化 3029 組 `(callback, context)`，而 **不同 Scene 子類別**先呼叫它再覆寫自身 vptr。`0x49530E → 0x4ADD50 → mov [eax],0xC072B4` 是 `Scene::CFirstScene`；其他 `Scene::CDuelSquare` / `CMissionRoom` / `CDuelField` / `CEternalTowerField` 的初始化鏈另有原生 RTTI。這證明 callback array 由場景類別實例使用，**不等於該表是全域 socket 的 wire-opcode dispatcher**。index 66 slot 在 `scene_obj + 0x214` 內指向 `0x4B2190`，但 index=66 目前沒有原生 frame→dispatcher 的證明。

**B. UI 動態型別補證（新）**：`0x635930` constructor 把 `0xC2E3DC` 寫成物件 vptr，MSVC RTTI TypeDescriptor 指向 `.?AVCTalkBoxDialog@FUI@@`。`0x638E60` 是這張 vtable 上的 method slot **110**；其從 `[this+4]` 取得**另一個指標**，讀該 *child pointer* 的 `+0xB4/+0xB5`，透過 `[this+0x14]` 與 `[this+0x18]` 的 `vtable+0x94` 分別傳播 bool，另有 +0x8C 條件連到第三 UI 控件。**注意：`[this+4]+B4` 不能自動與 `this+B4` 視為同一欄位。**

**C. record-filter → UI 條件 writer（新界線）**：`0x636520` 入口以 `ESI=ECX`、`EDI=EDX` 區分兩個實例。它把 `EDI+0x84=ESI`，依 `EDI+0x90` 小範圍狀態跳表於 case 0 呼叫 `0x635CA0`。後者 `0x635D23 → 0x500950`、`0x635D67 → 0x500E00`，比較兩份結果 begin/end，**寫 `EDI+0xB4/+0xB5`**。由於 EDI 是傳入的 EDX，尚須證明這個實例與 `0x638E60` 裡 `[this+4]` 的動態指標是否為同一物件；僅憑一致 offset 不足以閉合，惟 UI 視窗子系統及可見控件傳播已找到實體入口。

**D. 新的玩家 UI 發送候選（新）**：`FUI::CTalkBoxDialog` vtable slot **87** → `0x636DE0`，處理輸入 object `[esi+0x10] == 0x000F4402` 時呼叫 `0x636E10`；該分支核對經 virtual type 抽取的值 `0x000105BD`，再比較 `[entity+0x14] == 0x6A7`，`[dialog+0x88] != 0`。在 `[0xFBA798]==0` 下建立 `WORD 0x0036`、`WORD [ [dialog+0x88] ]` 的**4-byte 本地 buffer**，使用全域 `[0xFBA854]` `vtable+0x10` 以 `(0, buffer, 4)` 交付。`[0xFBA798]!=0` 時不走該虛擬呼叫，改走 UI `vtable+0xD4`；事件 id `0x6A8` 亦走 UI 後續，不能將所有分支混成發包。**此 0x36 是本地 buffer 首 WORD，尚未封包底層 socket 證明；不可宣稱原版 Quest wire opcode。**

**E. 尚未閉合**：receive frame / `0x4930E0` → Scene callback array index 66、`0x4B2190` 真實資料來源、UI `0x36` 呼叫後的 enqueue/framing/WSASend 跨 Task 連結、Quest16 完成/Quest15 變可接及實際接取回覆。Server 原版任務判斷規則未知，不以它取代 Client 的 wire 缺口。

## 2. 三輪研究進程及停止規範

### 第一輪 T16-106 — Scene callback 物件與 RTTI（達標的新增證據）

- 直接以 PE `.text` 搜索 `E8 rel32` 可能呼叫目標，並以已知函式入口附近 disassembly 驗證實際 call boundary。`0x4ADD50` 有 `0x49530E`、`0x4B9129`、`0x4B9379`、`0x4B9AA8`、`0x4BBB73`、`0x4369D2` 等多處真正 call sites。`0x4952FD` 在配置大小 `0x5EAC` 後，`0x49530E` 呼叫共用 base constructor，`0x495313` 寫 vptr `0xC072B4`。另 `0x4B9129` 寫 `0xC06F7C`、`0x4B9379` 寫 `0xC07098`、`0x4B9AA8` 寫 `0xC0710C`、`0x4369D2` 寫 `0xBF9BAC`。
- `.rdata` RTTI 分別解析 vtable[-1] CompleteObjectLocator +0xC -> TypeDescriptor，+8 為 MSVC mangled name；**它是原件符號資料**而非分析者臆測類名。vtable 不同 Scene 類別名稱證明「這個基底服務於場景類別」，但沒有消除其受網路資料驅動的可能性。
- 物件內嵌 callback pair 第一個 callable `[object+4]`，下一個 `[object+0xC]`；因 `object+4+8*66=object+0x214`，`0x4ADF3D` 寫 `0x4B2190`。另有全域 `[0xFD2CFC]` 表由 `0x4B7DC0` 初始化，預設函式 `0x4B7EC0`，仍是不同管理域。
- 限制：`0x4B2190` 的 little-endian input/subtype 格式已由 T16-105 有界驗證；**沒有** frame source 直接索引到 scene table 的 caller。從 constructor 定性不能反推網路 opcode。

### 第二輪 T16-106-2 — UI writer/reader 真正物件來源與 vtable（新增）

- `0x635930` 設 `FUI::CTalkBoxDialog` vptr、初始化本物件 `WORD +0xB4=0`、`DWORD +0xB8=0`，並配置、初始化 `+0xBC` 指標。`0x5C071D` 在配置 `0xDC` bytes 後呼叫此 constructor（另一外層物件是否為 quest 控制器尚未證）。
- `0x636520` 保存 `ESI=ECX`、`EDI=EDX`，`0x63656B` 寫 `[EDI+0x84]=ESI`，`0x636629` 以 `[EDI+0x90]` 0..3 跳到 `0x636630/0x636654/0x636687/0x6366BA`；case 0 `0x63664A` 呼叫 `0x635CA0`。
- `0x635CA0` 在 `EDI+0xB8 !=0` 下呼叫上述兩個不同 records filter，產出 flags `B4=(out1.begin!=out1.end)`、`B5=(out2.begin!=out2.end)`；`0x636629` 其他 cases 用 `0x500F90` 並可能通往 `0x635F10`，不是相同的 flag reset。此方法本身未直接顯示 socket 收到的 wire bytes。
- `CTalkBoxDialog` vtable slot 110 `0x638E60` 將 `[this+4]` *子指標* 中 `B4/B5` 讀出，經 UI controls `+0x14/+0x18` 的 vfunc `+0x94` 更新，另以 `this+0x1C` 的 UI flags 再參考子指標 `+0x8C` 交第三控制項。`0x635CA0` 的 EDI 與 `[this+4]` 的指標相等仍需精確 alias/caller 補證，不能因 offset 一樣推成一個類別。
- 由 constructor 到有名 UI 類型再到控件 bool 傳播，是本輪實質新增的**有界 UI consumer**，但不是 Quest16 狀態的已證 UI acceptance。

### 第三輪 T16-106-3 — CTalkBoxDialog 事件與 4-byte outbound 候選（新增）

- `0xC2E3DC` vtable 第 87 slot (`0xC2E538`) 的原件值為 `0x636DE0`。`0x636DF8` 比對事件物件 DWORD `[esi+0x10] == 0xF4402` 後 `call 0x636E10`，不是無條件送出。
- `0x636E10` 從事件 virtual accessor 取得型別，先核對 `0x105BD`，再讀 `[eax+0x14]`；若 equals `0x6A7`，且 `this+0x88` 非空，則取得 `[this+0x88]` 首 WORD。分支與 `0x6A8` 的本地 UI 處理分開。
- `0x636E85~0x636E8E` 將兩個 WORD 置於 `[ebp-4]/[ebp-2]`，依 little endian 是 4-byte `36 00 ?? ??`。`0x636E94~0x636EA7` 只在 `[FBA798]==0` 調 `[FBA854]` 虛表 +0x10，push size=4、pointer、第三參數 0；**還不能證明 vtable 實際目標、排入網路 queue、實際 WSASend 或 S→C acceptance**。
- 此流程可作 T16 的 TalkBox UI → message producer 新入口。它與 T16-69 的相同全域 sender 候選有交集，但此段拒絕僅因重用同一 vtable slot 就宣稱 `0x36` 為 Quest accepted packet；後續應以 T02 的 queue/framing 及真實表頭識別獨立接合。
- 三輪均有實質新增；此段停於可審核的 UI/scene 層邊界，避免把未知 Server 決策補猜成流程。

## 3. 原件 section 映射、RTTI及 vtable 驗證表

從 PE32 原件 header 重新驗證（見下面 verification code）；`.text` raw = VA - `0x400C00`，`.rdata` raw = VA − `0xBD2000` + `0x7D0600`，`.data` raw = VA − `0xD61000` + `0x95E800`。不同 segment 不可套一個固定偏移。

| vtable VA | vtable[-1] COL | TypeDescriptor | 原生 TypeDescriptor 名稱 | 作用 | 
|---|---|---|---|---|
| `0x00C072B4` | `0x00C69CC0` | `0x00F7E158` | `.?AVCFirstScene@Scene@@` | first |
| `0x00C06F7C` | `0x00C69994` | `0x00F7DFFC` | `.?AVCDuelSquare@Scene@@` | duelsquare |
| `0x00C07098` | `0x00C69AD8` | `0x00F7E084` | `.?AVCMissionRoom@Scene@@` | missionroom |
| `0x00C0710C` | `0x00C69B7C` | `0x00F7E0CC` | `.?AVCDuelField@Scene@@` | duelfield |
| `0x00BF9BAC` | `0x00C65EE0` | `0x00F7C08C` | `.?AVCEternalTowerField@Scene@@` | tower |
| `0x00C2E3DC` | `0x00C7601C` | `0x00F8563C` | `.?AVCTalkBoxDialog@FUI@@` | talk |

| CTalkBoxDialog vtable index | entry VA | function VA | 驗證範圍 |
|---:|---|---|---|
| 7 | `0x00C2E3F8` | `0x00635A70` | 依 vtable 原件小端資料解出，未直接證明所有 virtual call sites 進入 |
| 52 | `0x00C2E4AC` | `0x00636790` | 依 vtable 原件小端資料解出，未直接證明所有 virtual call sites 進入 |
| 53 | `0x00C2E4B0` | `0x00636840` | 依 vtable 原件小端資料解出，未直接證明所有 virtual call sites 進入 |
| 65 | `0x00C2E4E0` | `0x00635C90` | 依 vtable 原件小端資料解出，未直接證明所有 virtual call sites 進入 |
| 69 | `0x00C2E4F0` | `0x00635BD0` | 依 vtable 原件小端資料解出，未直接證明所有 virtual call sites 進入 |
| 80 | `0x00C2E51C` | `0x00636DC0` | 依 vtable 原件小端資料解出，未直接證明所有 virtual call sites 進入 |
| 87 | `0x00C2E538` | `0x00636DE0` | 依 vtable 原件小端資料解出，未直接證明所有 virtual call sites 進入 |
| 110 | `0x00C2E594` | `0x00638E60` | 依 vtable 原件小端資料解出，未直接證明所有 virtual call sites 進入 |

## 4. 玩家情境／雙向封包／狀態效果矩陣

| 玩家或程序情境 | Client 本地 gate | C→S 本地資料/是否確實送網路 | S→C | Client 結果 | Server 待開發 | 判定 |
|---|---|---|---|---|---|---|
| 場景 receiver index66 被選取 | `0x4ADD50` 物件表配置、`0x4ADF3D` overwrite | 此路徑是 callback，未證任何 outgoing | `0x4B2190` 處理 input[5]，但前段接收網路來源未知 | `0x53D840` 對 runtime record 有界更新（承 T16-105） | 若對應任務 S2C，必要欄位/真實表頭仍待 Client 補證 | 原生 callback/writer 已證；wire unknown |
| 對話 UI 消費 records | `0x636520` case0，`EDI+B8` 存在 | 未見此分支直接送網路 | records 資料來源可由其他 writer 更新，未閉合真正 S2C | `0x635CA0` 寫 EDI+B4/B5；`0x638E60` 將 `[this+4]+B4/B5` 轉成控件 bool（別名尚待驗證） | 原版 Server 何時更新 record 未知 | UI 子流程原生已證、端到端部分確認 |
| 對話事件 `0xF4402` → ID `0x6A7`，有選取 ID 且 sender gate=0 | `0x636DE0` → `0x636E10`，`[this+88]!=0`，`[FBA798]==0` | **4-byte local**：word `0x36` + word `[this+88]` 首 WORD，呼叫 `[FBA854].vtable+0x10`，WSASend 未證 | 直接回覆 opcode 未證 | 後續呼叫 `[this].vtable+0xD4` | 若此事件確實對應 Quest 接取，需實作已證的 Client 接受資料；Quest 身分待驗證 | 原生本地 producer 已證、wire 未證 |
| 對話事件 `0x6A7`、sender gate!=0 | `0x636E92` 條件跳過虛擬 sender | 不走 `0x636E94~EA7` 這一個 send call；其他發包路徑未排除 | unknown | 進 UI virtual `+0xD4` | unknown | 有界反例 |
| 對話事件 ID `0x6A8` | 比較 `0x636EB9` | 未見同 0x36 send call | unknown | UI 虛擬動作 | unknown | 局部分支已證 |
| Quest16 完成 → Quest15 可接 → 點選接取 | 尚未有可靠任務 ID／事件映射 | **unknown**，不能把 0x36 指定為接取封包 | **unknown**，不能把 index66 當 opcode | NPC/Quest UI 需要補證 | 將來開發相容 Server，不推測官方資料庫/判定 | Client 待逆向 |

## 5. 四類未解事項分別列管

**Client 待逆向（P0）：** scene callback indexing 如何從 receive frame 的哪個欄位取得；index66 實際 dispatcher；TalkBox `0x36` 發送流程是否真的 enqueue→framing→socket；其兩個 WORD 的 namespace；Quest 接取/完成/拒絕 UI 與 packets，以及 Quest16→Quest15 映射。`0x635CA0` EDI 與 `0x638E60` child pointer 是否 alias、對話事件 0x6A7 身分與 Quest 資料欄位。

**Server 待開發（僅在 Client 契約閉合後）：** 承接可驗證的 C→S 請求，持久化/驗證任務進度，產生 Client 實際識別的 S→C 狀態及 UI 更新；原版 Server 如何計算前置仍不可由本地推論。

**跨功能待整合：** T02 的 sender `0xFBA854`→ queue/framing/socket 與 receive dispatcher；T06 UI 控件；T07 NPC/場景、T14 完成結算、T15 snapshot/保存；禁止修改他們的主責原稿。

**待遊玩驗證：** 原始 Client 輸入對話選項時的實際封包 capture、收到進度回覆後 UI/可接列表及 Quest16→Quest15 狀態；本次未執行程式。

## 6. 精確後續入口（T16-107 候選，正式段號下次先查 GitHub）

1. 檢查 `[0xFBA854]` runtime type/vtable +0x10 的真實 target 及 `0x36` 後續 frame header、send state、socket；對照 T16-69~71 **已勘誤版**，不重用舊錯誤 queue A0A4/WSABUF/raw 位址。
2. 證明 `0x636E10` 的 `0x6A7` 是否是選項、場景或任務/NPC ID；定位 `[dialog+0x88]` writer／UI 選取事件和 `0x638E60` 的 `[this+4]` child pointer alias。
3. 在 T02 frame parser `0x4930E0` 追動態 callback table base/索引而不是以 constructor xref 作假證明；必要時把具體待查問題提交 T02/S00 協作，不自動認領 RR。
4. KR QuestInfo 15/16/TutorialBase 真實資源若可用再做 ID namespace 交叉驗證；不將 legacy `005F type6` fixture 當作官服回覆。
5. T01 的 43 筆仍待獨立審核；若新退回出現，下一次復工優先補修。`READY_FOR_REVIEW` 不能擅自變 `RESOLVED`。

## 7. 原始 x86 machine bytes、addresses、ranges（直接來自此 SHA 的 BIN）

每段列原始 raw offset、長度及 SHA256 便於 T01 切塊重放。`objdump` 有時在**提供的切片終點**印出 `.byte`，那只是截斷，不代表完整原生函式結束；所有論點僅使用已列明指令起點與完整指令。無符號的語意標籤是研究者限定推論。

### Scene-base constructor callback default: `0x4ADD50..0x4ADD7E`

- VA: `0x004ADD50..0x004ADD7E` (end-exclusive); raw: `0x000AD150..0x000AD17E`; length 46 bytes; SHA256 `0eb543a5531e56b12d92a513de4da514bd65fde9813e37784c283b187341a444`.

```asm
  4add50:	53                   	push   ebx
  4add51:	56                   	push   esi
  4add52:	8d 50 08             	lea    edx,[eax+0x8]
  4add55:	be d5 0b 00 00       	mov    esi,0xbd5
  4add5a:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4add5f:	90                   	nop
  4add60:	c7 42 fc 40 7d 4b 00 	mov    DWORD PTR [edx-0x4],0x4b7d40
  4add67:	89 0a                	mov    DWORD PTR [edx],ecx
  4add69:	83 c2 08             	add    edx,0x8
  4add6c:	4e                   	dec    esi
  4add6d:	75 f1                	jne    0x4add60
  4add6f:	ba 80 fb 4a 00       	mov    edx,0x4afb80
  4add74:	c7 40 34 30 7d 4b 00 	mov    DWORD PTR [eax+0x34],0x4b7d30
  4add7b:	89 48 38             	mov    DWORD PTR [eax+0x38],ecx
```

### Scene-base index 66 writer: `0x4ADF3D..0x4ADF5D`

- VA: `0x004ADF3D..0x004ADF5D` (end-exclusive); raw: `0x000AD33D..0x000AD35D`; length 32 bytes; SHA256 `10c86085f130582f6db0c48d7baa6546bd10a3b5e767bc293539512e53b022b5`.

```asm
  4adf3d:	c7 80 14 02 00 00 90 	mov    DWORD PTR [eax+0x214],0x4b2190
  4adf44:	21 4b 00 
  4adf47:	89 88 18 02 00 00    	mov    DWORD PTR [eax+0x218],ecx
  4adf4d:	c7 80 0c 02 00 00 10 	mov    DWORD PTR [eax+0x20c],0x4b2310
  4adf54:	23 4b 00 
  4adf57:	89 88 10 02 00 00    	mov    DWORD PTR [eax+0x210],ecx
```

### FirstScene allocation/Scene RTTI vptr: `0x4952FD..0x49534D`

- VA: `0x004952FD..0x0049534D` (end-exclusive); raw: `0x000946FD..0x0009474D`; length 80 bytes; SHA256 `a6ad8d2d9b7fc6a9accacc2bae7ce2f3b7f64eaf283311f9d90eade5cb62ef8a`.

```asm
  4952fd:	68 ac 5e 00 00       	push   0x5eac
  495302:	e8 61 bf 3f 00       	call   0x891268
  495307:	83 c4 04             	add    esp,0x4
  49530a:	3b c3                	cmp    eax,ebx
  49530c:	74 19                	je     0x495327
  49530e:	e8 3d 8a 01 00       	call   0x4add50
  495313:	c7 00 b4 72 c0 00    	mov    DWORD PTR [eax],0xc072b4
  495319:	c7 05 74 a6 d6 00 53 	mov    DWORD PTR ds:0xd6a674,0x46495253
  495320:	52 49 46 
  495323:	8b f8                	mov    edi,eax
  495325:	eb 02                	jmp    0x495329
  495327:	33 ff                	xor    edi,edi
  495329:	f6 05 f4 2c fd 00 01 	test   BYTE PTR ds:0xfd2cf4,0x1
  495330:	75 28                	jne    0x49535a
  495332:	09 35 f4 2c fd 00    	or     DWORD PTR ds:0xfd2cf4,esi
  495338:	c7 05 f8 2c fd 00 b4 	mov    DWORD PTR ds:0xfd2cf8,0xc06eb4
  49533f:	6e c0 00 
  495342:	89 1d a4 8b fd 00    	mov    DWORD PTR ds:0xfd8ba4,ebx
  495348:	e8 73 2a 02 00       	call   0x4b7dc0
```

### CMissionRoom call-vptr evidence: `0x4B9366..0x4B93A1`

- VA: `0x004B9366..0x004B93A1` (end-exclusive); raw: `0x000B8766..0x000B87A1`; length 59 bytes; SHA256 `0debbb6e0084e44a41d61ce6225f942970cada1c762252c7af79129757d55e8e`.

```asm
  4b9366:	68 58 bd 00 00       	push   0xbd58
  4b936b:	e8 f8 7e 3d 00       	call   0x891268
  4b9370:	8b f0                	mov    esi,eax
  4b9372:	83 c4 04             	add    esp,0x4
  4b9375:	85 f6                	test   esi,esi
  4b9377:	74 26                	je     0x4b939f
  4b9379:	e8 d2 49 ff ff       	call   0x4add50
  4b937e:	c7 06 98 70 c0 00    	mov    DWORD PTR [esi],0xc07098
  4b9384:	c7 86 54 bd 00 00 00 	mov    DWORD PTR [esi+0xbd54],0x0
  4b938b:	00 00 00 
  4b938e:	c7 05 74 a6 d6 00 52 	mov    DWORD PTR ds:0xd6a674,0x4d495352
  4b9395:	53 49 4d 
  4b9398:	e8 a3 37 00 00       	call   0x4bcb40
  4b939d:	eb 02                	jmp    0x4b93a1
  4b939f:	33 f6                	xor    esi,esi
```

### CTalkBoxDialog allocation via outer constructor: `0x5C06FE..0x5C0732`

- VA: `0x005C06FE..0x005C0732` (end-exclusive); raw: `0x001BFAFE..0x001BFB32`; length 52 bytes; SHA256 `46ade53a8b1b0d52ff08570fc1ff707e3c779cb133789a34d153bd8ca8e96383`.

```asm
  5c06fe:	68 dc 00 00 00       	push   0xdc
  5c0703:	c7 06 7c ea c1 00    	mov    DWORD PTR [esi],0xc1ea7c
  5c0709:	e8 5a 19 2d 00       	call   0x892068
  5c070e:	83 c4 04             	add    esp,0x4
  5c0711:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  5c0714:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  5c0718:	85 c0                	test   eax,eax
  5c071a:	74 08                	je     0x5c0724
  5c071c:	50                   	push   eax
  5c071d:	e8 0e 52 07 00       	call   0x635930
  5c0722:	eb 02                	jmp    0x5c0726
  5c0724:	33 c0                	xor    eax,eax
  5c0726:	89 46 0c             	mov    DWORD PTR [esi+0xc],eax
  5c0729:	c7 46 04 d2 00 00 00 	mov    DWORD PTR [esi+0x4],0xd2
  5c0730:	8b c6                	mov    eax,esi
```

### TalkBox constructor RTTI and fields: `0x635958..0x635A46`

- VA: `0x00635958..0x00635A46` (end-exclusive); raw: `0x00234D58..0x00234E46`; length 238 bytes; SHA256 `0d1e4d5a7869a31136fda208dc06c114a0c742c6cee1f5669e676733e69500e6`.

```asm
  635958:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  63595b:	8b ce                	mov    ecx,esi
  63595d:	e8 8e f8 10 00       	call   0x7451f0
  635962:	33 db                	xor    ebx,ebx
  635964:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  635967:	c7 06 dc e3 c2 00    	mov    DWORD PTR [esi],0xc2e3dc
  63596d:	89 9e 80 00 00 00    	mov    DWORD PTR [esi+0x80],ebx
  635973:	89 9e 84 00 00 00    	mov    DWORD PTR [esi+0x84],ebx
  635979:	89 9e 88 00 00 00    	mov    DWORD PTR [esi+0x88],ebx
  63597f:	88 9e 8c 00 00 00    	mov    BYTE PTR [esi+0x8c],bl
  635985:	89 9e 90 00 00 00    	mov    DWORD PTR [esi+0x90],ebx
  63598b:	89 9e 94 00 00 00    	mov    DWORD PTR [esi+0x94],ebx
  635991:	89 9e 98 00 00 00    	mov    DWORD PTR [esi+0x98],ebx
  635997:	8d be 9c 00 00 00    	lea    edi,[esi+0x9c]
  63599d:	6a 08                	push   0x8
  63599f:	89 1f                	mov    DWORD PTR [edi],ebx
  6359a1:	e8 c2 b8 25 00       	call   0x891268
  6359a6:	83 c4 04             	add    esp,0x4
  6359a9:	3b c3                	cmp    eax,ebx
  6359ab:	0f 84 97 00 00 00    	je     0x635a48
  6359b1:	89 07                	mov    DWORD PTR [edi],eax
  6359b3:	33 c9                	xor    ecx,ecx
  6359b5:	89 08                	mov    DWORD PTR [eax],ecx
  6359b7:	33 d2                	xor    edx,edx
  6359b9:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  6359bc:	8b 07                	mov    eax,DWORD PTR [edi]
  6359be:	89 38                	mov    DWORD PTR [eax],edi
  6359c0:	89 5f 04             	mov    DWORD PTR [edi+0x4],ebx
  6359c3:	89 5f 08             	mov    DWORD PTR [edi+0x8],ebx
  6359c6:	89 5f 0c             	mov    DWORD PTR [edi+0xc],ebx
  6359c9:	89 5f 10             	mov    DWORD PTR [edi+0x10],ebx
  6359cc:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  6359d0:	68 80 01 00 00       	push   0x180
  6359d5:	66 89 9e b4 00 00 00 	mov    WORD PTR [esi+0xb4],bx
  6359dc:	89 9e b8 00 00 00    	mov    DWORD PTR [esi+0xb8],ebx
  6359e2:	e8 81 b8 25 00       	call   0x891268
  6359e7:	83 c4 04             	add    esp,0x4
  6359ea:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  6359ed:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  6359f1:	3b c3                	cmp    eax,ebx
  6359f3:	74 08                	je     0x6359fd
  6359f5:	50                   	push   eax
  6359f6:	e8 c5 16 00 00       	call   0x6370c0
  6359fb:	eb 02                	jmp    0x6359ff
  6359fd:	33 c0                	xor    eax,eax
  6359ff:	89 86 bc 00 00 00    	mov    DWORD PTR [esi+0xbc],eax
  635a05:	89 9e c0 00 00 00    	mov    DWORD PTR [esi+0xc0],ebx
  635a0b:	89 9e c4 00 00 00    	mov    DWORD PTR [esi+0xc4],ebx
  635a11:	89 9e c8 00 00 00    	mov    DWORD PTR [esi+0xc8],ebx
  635a17:	89 9e cc 00 00 00    	mov    DWORD PTR [esi+0xcc],ebx
  635a1d:	89 9e d0 00 00 00    	mov    DWORD PTR [esi+0xd0],ebx
  635a23:	89 9e d4 00 00 00    	mov    DWORD PTR [esi+0xd4],ebx
  635a29:	89 9e d8 00 00 00    	mov    DWORD PTR [esi+0xd8],ebx
  635a2f:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  635a32:	8b c6                	mov    eax,esi
  635a34:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  635a37:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  635a3e:	59                   	pop    ecx
  635a3f:	5f                   	pop    edi
  635a40:	5e                   	pop    esi
  635a41:	5b                   	pop    ebx
  635a42:	8b e5                	mov    esp,ebp
  635a44:	5d                   	pop    ebp
  635a45:	c2                   	.byte 0xc2
```

### UI callback EDX/ECX alias and state set: `0x636520..0x6365B0`

- VA: `0x00636520..0x006365B0` (end-exclusive); raw: `0x00235920..0x002359B0`; length 144 bytes; SHA256 `2d7cae95d74559fee174b16f7b4cd7b24cc5637b233721f1e954a9af1f2035d9`.

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
```

### UI callback mode0 dispatch into record filter: `0x63660D..0x636654`

- VA: `0x0063660D..0x00636654` (end-exclusive); raw: `0x00235A0D..0x00235A54`; length 71 bytes; SHA256 `59b9da8094849b74bf756e2735432949149abd0cdcb6c67d6da8e1a65ac78a82`.

```asm
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
```

### record filter vector comparisons to B4/B5: `0x635CC7..0x635D8A`

- VA: `0x00635CC7..0x00635D8A` (end-exclusive); raw: `0x002350C7..0x0023518A`; length 195 bytes; SHA256 `e78afdd8c523b19272f3a23bd052e3d69123cf7191dbeffe9115c7da10aec860`.

```asm
  635cc7:	33 f6                	xor    esi,esi
  635cc9:	39 b7 b8 00 00 00    	cmp    DWORD PTR [edi+0xb8],esi
  635ccf:	0f 84 1f 02 00 00    	je     0x635ef4
  635cd5:	89 75 b4             	mov    DWORD PTR [ebp-0x4c],esi
  635cd8:	89 75 b8             	mov    DWORD PTR [ebp-0x48],esi
  635cdb:	89 75 bc             	mov    DWORD PTR [ebp-0x44],esi
  635cde:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  635ce1:	89 75 c4             	mov    DWORD PTR [ebp-0x3c],esi
  635ce4:	89 75 c8             	mov    DWORD PTR [ebp-0x38],esi
  635ce7:	89 75 cc             	mov    DWORD PTR [ebp-0x34],esi
  635cea:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  635cee:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  635cf5:	75 21                	jne    0x635d18
  635cf7:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  635cfe:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  635d02:	e8 59 a1 ec ff       	call   0x4ffe60
  635d07:	68 00 cf bc 00       	push   0xbccf00
  635d0c:	e8 09 c6 25 00       	call   0x89231a
  635d11:	83 c4 04             	add    esp,0x4
  635d14:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  635d18:	8b 8f 84 00 00 00    	mov    ecx,DWORD PTR [edi+0x84]
  635d1e:	8d 45 b4             	lea    eax,[ebp-0x4c]
  635d21:	50                   	push   eax
  635d22:	51                   	push   ecx
  635d23:	68 a0 b2 fa 00       	push   0xfab2a0
  635d28:	e8 23 ac ec ff       	call   0x500950
  635d2d:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  635d34:	75 21                	jne    0x635d57
  635d36:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  635d3d:	c6 45 fc 03          	mov    BYTE PTR [ebp-0x4],0x3
  635d41:	e8 1a a1 ec ff       	call   0x4ffe60
  635d46:	68 00 cf bc 00       	push   0xbccf00
  635d4b:	e8 ca c5 25 00       	call   0x89231a
  635d50:	83 c4 04             	add    esp,0x4
  635d53:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  635d57:	8b 87 84 00 00 00    	mov    eax,DWORD PTR [edi+0x84]
  635d5d:	8d 55 c4             	lea    edx,[ebp-0x3c]
  635d60:	52                   	push   edx
  635d61:	50                   	push   eax
  635d62:	68 a0 b2 fa 00       	push   0xfab2a0
  635d67:	e8 94 b0 ec ff       	call   0x500e00
  635d6c:	8b 4d b4             	mov    ecx,DWORD PTR [ebp-0x4c]
  635d6f:	3b 4d b8             	cmp    ecx,DWORD PTR [ebp-0x48]
  635d72:	8b 45 c4             	mov    eax,DWORD PTR [ebp-0x3c]
  635d75:	0f 95 c2             	setne  dl
  635d78:	3b 45 c8             	cmp    eax,DWORD PTR [ebp-0x38]
  635d7b:	88 97 b4 00 00 00    	mov    BYTE PTR [edi+0xb4],dl
  635d81:	0f 95 c1             	setne  cl
  635d84:	88 8f b5 00 00 00    	mov    BYTE PTR [edi+0xb5],cl
```

### UI control consumer of child pointer B4/B5: `0x638E8C..0x638F20`

- VA: `0x00638E8C..0x00638F20` (end-exclusive); raw: `0x0023828C..0x00238320`; length 148 bytes; SHA256 `6a97f3bd69f5d4ddf702c5e9a10dc624d371532a67776bd8ba35719c815ac8fc`.

```asm
  638e8c:	8b f1                	mov    esi,ecx
  638e8e:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  638e91:	85 c0                	test   eax,eax
  638e93:	74 69                	je     0x638efe
  638e95:	8a 80 b4 00 00 00    	mov    al,BYTE PTR [eax+0xb4]
  638e9b:	8b 4e 14             	mov    ecx,DWORD PTR [esi+0x14]
  638e9e:	8b 11                	mov    edx,DWORD PTR [ecx]
  638ea0:	8b 92 94 00 00 00    	mov    edx,DWORD PTR [edx+0x94]
  638ea6:	88 44 24 10          	mov    BYTE PTR [esp+0x10],al
  638eaa:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  638eae:	50                   	push   eax
  638eaf:	ff d2                	call   edx
  638eb1:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  638eb4:	8a 88 b5 00 00 00    	mov    cl,BYTE PTR [eax+0xb5]
  638eba:	88 4c 24 10          	mov    BYTE PTR [esp+0x10],cl
  638ebe:	8b 4e 18             	mov    ecx,DWORD PTR [esi+0x18]
  638ec1:	8b 11                	mov    edx,DWORD PTR [ecx]
  638ec3:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  638ec7:	8b 92 94 00 00 00    	mov    edx,DWORD PTR [edx+0x94]
  638ecd:	50                   	push   eax
  638ece:	ff d2                	call   edx
  638ed0:	8b 46 1c             	mov    eax,DWORD PTR [esi+0x1c]
  638ed3:	8b 48 28             	mov    ecx,DWORD PTR [eax+0x28]
  638ed6:	c1 e9 08             	shr    ecx,0x8
  638ed9:	f6 c1 01             	test   cl,0x1
  638edc:	74 10                	je     0x638eee
  638ede:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  638ee1:	80 ba 8c 00 00 00 00 	cmp    BYTE PTR [edx+0x8c],0x0
  638ee8:	74 04                	je     0x638eee
  638eea:	b0 01                	mov    al,0x1
  638eec:	eb 02                	jmp    0x638ef0
  638eee:	32 c0                	xor    al,al
  638ef0:	8b 4e 1c             	mov    ecx,DWORD PTR [esi+0x1c]
  638ef3:	8b 11                	mov    edx,DWORD PTR [ecx]
  638ef5:	50                   	push   eax
  638ef6:	8b 82 94 00 00 00    	mov    eax,DWORD PTR [edx+0x94]
  638efc:	ff d0                	call   eax
  638efe:	8b 4e 0c             	mov    ecx,DWORD PTR [esi+0xc]
  638f01:	8b 11                	mov    edx,DWORD PTR [ecx]
  638f03:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  638f06:	8b 92 94 00 00 00    	mov    edx,DWORD PTR [edx+0x94]
  638f0c:	50                   	push   eax
  638f0d:	ff d2                	call   edx
  638f0f:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  638f12:	8b 01                	mov    eax,DWORD PTR [ecx]
  638f14:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  638f17:	8b 80 94 00 00 00    	mov    eax,DWORD PTR [eax+0x94]
  638f1d:	52                   	push   edx
  638f1e:	ff d0                	call   eax
```

### TalkBox virtual event gate: `0x636DE0..0x636E10`

- VA: `0x00636DE0..0x00636E10` (end-exclusive); raw: `0x002361E0..0x00236210`; length 48 bytes; SHA256 `db4d0de6f72ce023b7051457c8479cc4a6d68222a03bf52464f8dbaa4df90ff6`.

```asm
  636de0:	55                   	push   ebp
  636de1:	8b ec                	mov    ebp,esp
  636de3:	56                   	push   esi
  636de4:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  636de7:	57                   	push   edi
  636de8:	8b f9                	mov    edi,ecx
  636dea:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636df0:	8b 01                	mov    eax,DWORD PTR [ecx]
  636df2:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  636df5:	56                   	push   esi
  636df6:	ff d2                	call   edx
  636df8:	81 7e 10 02 44 0f 00 	cmp    DWORD PTR [esi+0x10],0xf4402
  636dff:	75 05                	jne    0x636e06
  636e01:	e8 0a 00 00 00       	call   0x636e10
  636e06:	5f                   	pop    edi
  636e07:	5e                   	pop    esi
  636e08:	5d                   	pop    ebp
  636e09:	c2 04 00             	ret    0x4
  636e0c:	cc                   	int3
  636e0d:	cc                   	int3
  636e0e:	cc                   	int3
  636e0f:	cc                   	int3
```

### TalkBox 4-byte outbound candidate and UI continuation: `0x636E10..0x636ECC`

- VA: `0x00636E10..0x00636ECC` (end-exclusive); raw: `0x00236210..0x002362CC`; length 188 bytes; SHA256 `0cc4d7212173ddd7c989e126e2d4340c145f34b2166490de4fcd4c02f5bf16ec`.

```asm
  636e10:	55                   	push   ebp
  636e11:	8b ec                	mov    ebp,esp
  636e13:	51                   	push   ecx
  636e14:	85 f6                	test   esi,esi
  636e16:	74 28                	je     0x636e40
  636e18:	8b 06                	mov    eax,DWORD PTR [esi]
  636e1a:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  636e1d:	8b ce                	mov    ecx,esi
  636e1f:	ff d2                	call   edx
  636e21:	3d bd 05 01 00       	cmp    eax,0x105bd
  636e26:	75 04                	jne    0x636e2c
  636e28:	8b c6                	mov    eax,esi
  636e2a:	eb 16                	jmp    0x636e42
  636e2c:	6a 00                	push   0x0
  636e2e:	68 c0 1f bf 00       	push   0xbf1fc0
  636e33:	68 18 21 bf 00       	push   0xbf2118
  636e38:	6a 00                	push   0x0
  636e3a:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  636e40:	33 c0                	xor    eax,eax
  636e42:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  636e45:	3d a7 06 00 00       	cmp    eax,0x6a7
  636e4a:	75 6d                	jne    0x636eb9
  636e4c:	83 bf 88 00 00 00 00 	cmp    DWORD PTR [edi+0x88],0x0
  636e53:	74 77                	je     0x636ecc
  636e55:	b8 01 00 00 00       	mov    eax,0x1
  636e5a:	84 05 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,al
  636e60:	75 13                	jne    0x636e75
  636e62:	09 05 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,eax
  636e68:	68 10 cf bc 00       	push   0xbccf10
  636e6d:	e8 a8 b4 25 00       	call   0x89231a
  636e72:	83 c4 04             	add    esp,0x4
  636e75:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  636e7c:	8b 8f 88 00 00 00    	mov    ecx,DWORD PTR [edi+0x88]
  636e82:	66 8b 11             	mov    dx,WORD PTR [ecx]
  636e85:	b8 36 00 00 00       	mov    eax,0x36
  636e8a:	66 89 45 fc          	mov    WORD PTR [ebp-0x4],ax
  636e8e:	66 89 55 fe          	mov    WORD PTR [ebp-0x2],dx
  636e92:	75 2c                	jne    0x636ec0
  636e94:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  636e9a:	8b 01                	mov    eax,DWORD PTR [ecx]
  636e9c:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  636e9f:	6a 04                	push   0x4
  636ea1:	8d 55 fc             	lea    edx,[ebp-0x4]
  636ea4:	52                   	push   edx
  636ea5:	6a 00                	push   0x0
  636ea7:	ff d0                	call   eax
  636ea9:	8b 17                	mov    edx,DWORD PTR [edi]
  636eab:	8b 82 d4 00 00 00    	mov    eax,DWORD PTR [edx+0xd4]
  636eb1:	8b cf                	mov    ecx,edi
  636eb3:	ff d0                	call   eax
  636eb5:	8b e5                	mov    esp,ebp
  636eb7:	5d                   	pop    ebp
  636eb8:	c3                   	ret
  636eb9:	3d a8 06 00 00       	cmp    eax,0x6a8
  636ebe:	75 0c                	jne    0x636ecc
  636ec0:	8b 17                	mov    edx,DWORD PTR [edi]
  636ec2:	8b 82 d4 00 00 00    	mov    eax,DWORD PTR [edx+0xd4]
  636ec8:	8b cf                	mov    ecx,edi
  636eca:	ff d0                	call   eax
```

## 8. 重現與未升格聲明

下方靜態 Python 片段僅供在合法持有對應 KR BIN 的工作環境驗證 RTTI 與 vtable，不呼叫任何原版程式碼：

```python
import struct, hashlib
p = open('Tartaros.bin', 'rb').read()
assert hashlib.sha256(p).hexdigest() == '9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
def ro(va):
    if 0x401000 <= va < 0xBD1200: return va - 0x401000 + 0x400
    if 0xBD2000 <= va < 0xD60200: return va - 0xBD2000 + 0x7D0600
    if 0xD61000 <= va < 0xFE7400: return va - 0xD61000 + 0x95E800
    raise ValueError(hex(va))
def u32(va): return struct.unpack_from('<I',p,ro(va))[0]
def rtti(vtable):
    col = u32(vtable - 4)
    td  = u32(col + 12)
    return p[ro(td + 8):ro(td + 8)+100].split(b'\0')[0]
assert rtti(0xC2E3DC) == b'.?AVCTalkBoxDialog@FUI@@'
assert rtti(0xC072B4) == b'.?AVCFirstScene@Scene@@'
assert u32(0xC2E3DC + 4*87) == 0x636DE0
assert u32(0xC2E3DC + 4*110) == 0x638E60
```

本稿含**作者端有界原生靜態觀察**，未經 T01 對本稿全文複驗，不可標 FULL-PASS；只有已保存在 `shared/verified-knowledge/` 且符合其精確限定條件的既有主張具有該審核地位。沒有真實封包記錄、Server 原始碼或執行時 UI 観測；未證之事明列 unknown。
