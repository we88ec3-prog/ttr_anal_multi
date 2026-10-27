# T10-3 — KeyMapping.xml 載入、內建預設映射與三 Bank 初始化（BIN-first）

時間：2026-10-27 18:44:14 Asia/Taipei（檔名時間）  
任務：KR T10 普通攻擊與連段；T10-1 為先前全部研究、T10-2 為條件樹與 Bank writer；本稿為 T10-3。  
範圍：確認 **設定載入／Bank 來源**，不將設定表逕認為按鍵事件或普通攻擊連段機制。  
原始檔：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。兩檔均唯讀；本輪 x86 反組譯來源為原始 BIN，工具 `objdump -D -Mintel`。PE `.text` VA `0x401000`, raw `0x400`；`.rdata` VA `0xBD2000`, raw `0x7D0600`。

## 1. 新的關鍵結論

**已確認** `0x6D08F0` 是對設定 `Table/KeyMapping.xml` 的 XML 解析入口；`0x6D0A00–0x6D0C14` 所屬的同一函式遍歷 `Type/Key`，按 `idx` / `MapButton` / `ModKey` 欄位寫入 16-byte row 裡的 DWORD vector。上次推測「可能是設定載入」得到第一手字串與分支支持。

**已確認** 該載入器在讀取失敗的分支呼叫 `0x6D0EB0`，初始化硬編碼預設按鍵配置；讀取成功則按 `DefaultType` 計算資料來源（僅 0/1 進入該選擇分支），並把來源映射覆蓋/複製至 Bank2（`0xFB8D34`）。

**尚未確認** 哪一項 MapButton 是「普通攻擊」；`0x5A`（ASCII `Z`/Win32 VK_Z）沒有被此函式證實直接映射為普通攻擊；兩種 Z 操作方式是否在 held 或 edge 層合流仍未知。

## 2. XML 語法線索：直接從 .rdata 解出

| VA | 原始 ASCII |
|---|---|
| `0xC40888` | `Table/KeyMapping.xml` |
| `0xC408A0` | `KeyMapping` |
| `0xC408AC` | `DefaultType` |
| `0xC408B8` | `Type` |
| `0xC408C0` | `Key` |
| `0xC408C4` | `MapButton` |
| `0xC408D0` | `ModKey` |
| `0xC408D8` | `Virualkey.dll`（原始拼字如此，不擅改） |
| `0xC408E8` | `%d %d` |

關鍵原始指令：
```asm
6D0930 lea eax,[esp+24h]
6D0934 push eax
6D0935 mov ecx,0C40888h    ; Table/KeyMapping.xml
6D093A call 72EE30
6D0970 push 0C408A0h       ; KeyMapping
6D0977 call 72E2E0
6D099E push 0C408ACh       ; DefaultType
6D09A6 call 7300A0
6D09CA mov [0FB9034h],eax  ; parsed DefaultType
6D09CF mov edi,0C408B8h    ; Type
6D09D6 call 72E360
6D09F0 push 0C071FCh       ; idx
6D09F8 call 7300A0
6D0A23 cmp esi,3           ; parsed Type idx < 3
6D0A2C mov edi,0C408C0h   ; Key
6D0A33 call 72E360
6D0A71 push 0C408C4h      ; MapButton
6D0A77 call 893CB1
6D0AAA push 0C408C0h      ; Key (text lookup)
6D0AB0 call 893CB1
6D0ADF push 0C408D0h      ; ModKey
6D0AE5 call 893CB1
```
註：`0x6D0AAA` 的 Key 是對內層文字欄位的比較，尚不可單由此宣稱每個 XML 節點的 schema。

## 3. Bank 佈局、欄位編碼與 T10-2 的修正

`0x6D0A44–0x6D0A4D` 計算 `parsedType*40`：
```asm
6D0A44 lea esi,[esi+esi*4] ; 5*x
6D0A47 add esi,esi         ; 10*x
6D0A49 add esi,esi         ; 20*x
6D0A4B add esi,esi         ; 40*x
6D0B0B lea esi,[esi+eax]   ; + MapButton/index candidate
6D0B11 shl esi,4           ; *16-byte row
6D0B19 add esi,0FB8834h
6D0B14 shl edi,10h
6D0B17 or edi,ecx
6D0C0E mov [eax],edi
6D0C14 add dword [esi+4],4
```
因此函式讀取的 `Type` 限制為 0..2；每 Type 的 row 條目步長是 **40*16 = 0x280**（可交叉驗證 Bank0 `FB8834`、Bank1 `FB8AB4`、Bank2 `FB8D34`）。元件向量 begin/end/capacity 在 row `+0/+4/+8`，append DWORD 的編碼為 `(uint8_t)mapButton << 16 | (uint8_t)modKey` **需小心**：由 `6D0B00` 之前控制流，EDI 的 high byte 值取自 `0x6D0BCE` 字串解析結果；BL 來自另一條解析結果。確切欄位對應仍需跟完整 CFG 核對，不把 mapButton/modKey 名稱和暫存器以 100% 語意等同。

T10-2 已指出 `0x6D0B00` 不是獨立函式入口；本次再以 `0x6D08F0` prologue / `0x6D0D03 ret` 確認它包含在更大 XML 載入流程中。

## 4. 成功載入、失敗 fallback 與啟動呼叫者

```asm
6D0963 call 72F110         ; XML resource load/check
6D0968 test al,al
6D096A je 6D0C68           ; failure
...
6D0C4C mov eax,[0FB9034h] ; DefaultType
6D0C55 cmp eax,1
6D0C58 jne 6D0C92          ; 0 or 1 only for copy
6D0C5A lea eax,[eax+eax*4]
6D0C5D shl eax,7           ; type*0x280
6D0C60 add eax,0FB8834h
6D0C65 push eax            ; src
6D0C88 push 0FB8D34h      ; dst Bank2
6D0C8D call 6D1BE0        ; vector/mapping copy helper
...
6D0C68 call 6D0EB0        ; XML load failure -> default mapping
6D0C6D mov eax,[0FB9034h]
6D0C76 cmp eax,1
6D0C7B lea ecx,[eax+eax*4]
6D0C7E shl ecx,7
6D0C81 add ecx,0FB8834h
6D0C87 push ecx
6D0C88 push 0FB8D34h
6D0C8D call 6D1BE0
```
`0x6D1BE0` 從 `+0`, `+4`, `+8` 等 vector 欄位做區間複製／擴容；尚未窮盡每個路徑，保守稱為 **Bank 複製／更新 helper**。

`0x6D0750` 為三個 0x280 Bank 的初始化入口，會呼叫 `0x6D08F0`。對照：
```asm
6D077F push 3
6D0781 push 280h
6D0788 push 0FB8834h
6D079A call 892003          ; array init
6D07CE call 6D08F0        ; XML/key mapping load
6D07FA cmp byte [0FB91E9h],2
6D0803 call 6D0D10        ; conditional supplementary loader
6D0808 push 2
6D080A call 6D1A70        ; select active Bank2
```
`0x6D1A70` 用 `type*0x280+0xFB8834` 設 `[0xFB902C]`，將 `[0xFB9030]` 更新為 selected type，並清 `[0xFB9004..0xFB9028]` 一組狀態值（包括 T10-1 的 `FB9014`）。

## 5. 預設按鍵表：有實際 hardcoded key 值，但不能硬套 Z

`0x6D0EB0` 從 `0xFB8844` 開始對連續 row 呼叫 `0x4A8680`，例如：
```asm
6D0EB8 mov edi,0FB8844h
6D0EBD mov dword [ebp-4],48h
6D0EC4 call 4A8680
6D0ECC mov dword [ebp-4],0C8h
6D0ED3 call 4A8680
6D0EDB mov edi,0FB8854h
6D0EE0 mov dword [ebp-4],4Ch
6D0EE7 call 4A8680
6D0EEF mov dword [ebp-4],50h
6D0EF6 call 4A8680
6D0F0D mov edi,0FB8864h
6D0F12 mov dword [ebp-4],4Bh
6D0F19 call 4A8680
```
這些是回退的預設映射資料，並非當前設定 XML 的實際內容；`0x4A8680` 如何將 DWORD 追加、特殊位元如何編碼，需繼續審核。

## 6. 與 Z 連按／Z 長按之關係、下一步

| 問題 | 本段證據狀態 |
|---|---|
| 原生載入 Table/KeyMapping.xml | 已確認（字串 + 呼叫） |
| 讀取 Type、idx、Key、MapButton、ModKey | 已確認（直接執行碼字串參照） |
| 三個 0x280 Bank / 選 active Bank2 | 已確認（算術 + caller） |
| 缺 XML 時預設映射 | 已確認（fail branch -> 6D0EB0） |
| `Z` 所代表的行動索引 | 尚未驗證，需 XML 真實內容或映射讀取者 |
| Z pressed / held 分流及合流 | 尚未驗證；`FB9014` 的靜態直接 xref 只查到初始化/清零及讀取，動態寫入可能為索引 |
| Z 連段、取消時間窗口 | 尚未驗證；此前 500ms timer 與自製 0.65s 不可等同 |

下一段 **T10-4**：優先完整展開 `0x4A8680` 以固定預設 vector 插入的語義；追 `0xFB902C` active Bank 的間接讀取者與鍵盤事件 dispatcher，串到 `0x547240`。尋找實際 `Table/KeyMapping.xml`（目前只有路徑，尚未有檔案），才能核定遊戲既有/可配置的 Z 綁定。對比 Z edge 與 held 各自的 bit transition，最後才追普攻續段狀態。

## 7. Source/Git 狀態

GitHub 既有 T10 任務定位：`kr/tasks/T10/README.md` 普通攻擊及連段；範圍不含 T12 傷害公式。參照上一段 T10-2 技術筆記及 `02-PROJECT-SHARED-INSTRUCTIONS.md`。本次原始機器碼由上述 SHA 原始 BIN 直接反組譯驗證；沒有讀取、修改或執行遊戲流程、沒有修改 repository／他人 Task、沒有 Commit/Push。未將字串參照或配置建立視為已驗證普攻實作。