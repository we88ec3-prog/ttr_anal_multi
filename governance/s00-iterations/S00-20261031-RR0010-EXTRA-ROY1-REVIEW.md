# S00 2026-10-31 — extra/roy1 合併後 RR-0010 有界研究驗證與 Server 交接

**審查者：S00 規格整合（非 T01 原生 FULL-PASS 認證）。**  
**來源合併：** [PR #63](https://github.com/we88ec3-prog/ttr_anal_multi/pull/63)，`extra/roy1` head `76ee900f0cc5f9157809620d84607986a36f23a1` → `main` merge `3ccbee4a78346b0c8751984555fc43157db5f723`。該分支相對當時 main 為 **13 個新增原稿/驗證器檔案、無覆寫**，涉及 RR-0010 E71–E74 與另外 RR-0002 E75（E68–70 屬相鄰研究）。正式 RR 台帳在合併前後仍為 **`RR-0010 BLOCKED`**，`GAP-CHAR-0003 OPEN`，`SPEC-CHAR-0001/SPEC-FLOW-0001 DRAFT/PARTIAL`。

## 1. 驗證方式與真實限制

1. GitHub 對照 main→extra 差異、原 branch/head SHA 和 merge SHA，核對來源研究檔案存在與 Git blob SHA；審閱 E71、E72、E73、E74、E75 的交付敘述、反證、腳本型態及元資料。不把 Git 合併、腳本存在、作者宣稱 PASS 誤視為本次實際原生證明。
2. **交叉讀取已保存的同 KR SHA（`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`）之 Ghidra 派生偽碼**，作為可重現的第二閱讀面；每一檔均標記 `saved-unreviewed`，不能取代機器碼/PE 指令語意審查：
   - `kr-bulk-roy/9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91/functions/0x672180.c`，Git blob **`6f705f7088e8d92e8b41c13eecbee17b252b5283`**：證明名稱取自寬字元 edit、字元檢查、`_wcscpy_s(21)`、有條件呼叫 network-manager virtual；偽碼**不單獨證明精確內層 wire 48B**。
   - `.../functions/0x4c21d0.c`，blob **`f37433daa51f30dba0cd10f176f90ce32883f759`**：`FUN_0058ab80(0xF4245, (int)*(short *)(payload+2))`。
   - `.../functions/0x672570.c`，blob **`9f24613e7c4d33c47a2489f90c762c81274c1f11`**：`result==1` 保存寬字元名稱至 `F938F2` 並關閉對話框；`-1/-2/-3` 有不同本地分支，但無足夠官方錯誤語意。
   - `.../functions/0x4b7f00.c`，blob **`871c336add31a6ad3ddabce41c1a284bc37c41bb`**：名單入口從 `payload+0x0C` 複製名稱到 `F938F2`，和結果對話框共用 Client local name storage；**沒有證明同一個 Server 交易/回覆時序**。
   - `.../functions/0x4de020.c`，blob **`7a6ef7a464da3bf66e8f54ab4b5e568e1bbd72d2`**：佐證 E75 另一條 `(len-4)/5` row consumer 與本地 `F4261`，歸 RR-0002 的鄰接證據，**不能算 RR-0010 的建角成功回覆**。
3. 已檢視原 branch 的 E71/E72/E73/E74/E75 原生驗證腳本：均有特定 KR SHA256 gate、唯讀 `read_bytes()`、指令/RTTI/call 斷言，沒有開啟或執行 Client 的程式路徑；**本次工作環境沒有原始 `Tartaros.bin`**，因此**不能自行執行** E71 34、E72 33、E73 58、E74 81、E75 61 項原始 byte 斷言，也無權宣稱這些數值是本次重跑結果。研究作者報告為 PASS；S00 本輪只完成 Git blob、文件相互一致性與已保存反編譯的有界交叉核對，不是獨立 BIN-first/T01 語意驗收。
4. 原版 Client 執行、封包抓取、官方 Server 回覆與任何具真實帳號的測試**均未發生**。不以研究者提交或原始 SHA 字串比對宣稱正式 Client 相容性。

## 2. 逐項研究證據：正向成果與不可跨越的推論

| 節點 | 來源／檢查 | 本次 S00 可引用的**限定事實** | 未證與實作禁區 |
| --- | --- | --- | --- |
| UI 確認→送建名 | [E73](../../kr-extra-roy/20261031-chatgpt-web-roy-E73-RR0010-expedition-name-create-C2S3E-S2C4A-native-chain.md)、`0x671FD0/0x672180`、同版 Ghidra `0x672180.c` | `CExpeditionCreateDialog` 有 edit→本地 confirm `F4244`→檢查名稱→有條件 queue send | 角色清單 N0→此 dialog **可達**仍另屬 RR-0009；`CEmployNewCharacter` 的 `C2S0x33` 是**不同 UI 類別**、不能混稱建名 |
| C→S `0x003E` | [E73](../../kr-extra-roy/20261031-chatgpt-web-roy-E73-RR0010-expedition-name-create-C2S3E-S2C4A-native-chain.md) `0x672505..67253C`、E73 作者 byte-checker | 作者 byte-level 定位 **48-byte inner app payload**、slot0、`+0..1=3E 00`、`+6..47` 21 UTF-16 WCHAR 容量、`FBA798==0` 才 queue；本次偽碼獨立支持「wide name＋有條件 send」 | **`+2..5` UNKNOWN**，尾部可能未初始化，21 WCHAR 容量不等於可輸入 21 個非 NUL。沒有原始外層 frame / live packet trace；不可把未知 bytes 定成固定零、ID、salt |
| S→C `0x004A` candidate | [E73](../../kr-extra-roy/20261031-chatgpt-web-roy-E73-RR0010-expedition-name-create-C2S3E-S2C4A-native-chain.md)、`0x4C21D0.c` | LOGIN scene 有 index `0x4A` handler 候選，`payload+2` 有號 16-bit → 本地事件 `F4245`；`status==1` 可進本地名稱更新，`-1/-2/-3` 分開消費 | **無原版 Server `0x003E ↔ 0x004A` 請求／回覆正式配對證據**、場景條件/最短包防護、錯誤文字/重名 status mapping；不能叫已驗證 official create ACK |
| Shared name state | [E74](../../kr-extra-roy/20261031-0244-chatgpt-web-roy-E74-RR0010-expedition-name-roster-shared-state.md)、`0x4B7F00.c` | `S2C app2` header `+0x0C` 的 20 WCHAR name 複製到 `F938F2`，與 `S2C0x4A` local success 對話框共享該 Client global；`app2` 還有 65B prefix + 53B rows 的 bounded reader | **共享記憶體≠`0x4A→app2` 因果/順序**；app2 在 65B row-count gate 前就有 header/name 讀取，不可聲稱任何短包都安全 |
| Roster supplementary send | [E74](../../kr-extra-roy/20261031-0244-chatgpt-web-roy-E74-RR0010-expedition-name-roster-shared-state.md)、[E75](../../kr-extra-roy/20261031-0305-chatgpt-web-roy-E75-RR0002-roster-0x26-two-layer-gameinfo-handler-native.md) | app2 中每筆角色 row 的 bounded sender `C2S0x26` 3B、名單結束 `C2S0x24` 2B；E75 補出另方向 `S2C0x26` 在具體 scene/owner 下轉為 `4+5N` 的 5B record consumer + 本地 `F4261` | **相同 opcode 的雙方向不是已證 request/reply**；`F4261` 不是 wire。這是補充初始化研究/另屬 RR-0002，未證建立 playable-character |
| 其它反證 | [E71](../../kr-extra-roy/20261031-010931-chatgpt-web-roy-E71-RR0010-create-C2S-candidates-S2C-roster-blocker.md)、[E72](../../kr-extra-roy/20261031-chatgpt-web-roy-E72-RR0010-create-secondary-dispatch-roster-native-followup.md) | `CEmployNewCharacter→C2S0x33` 只有 2B，`C2S0x42` 是既有角色 selection；另一 `2+53N` record writer 不能和 `65+53N` 併為同包 | 不據 opcode 字面、類名、`request+1` 猜新角色完整產生協定 |

## 3. RR-0010 正式完成條件逐條驗收

正式 `research/requests/index.json` 問題是 **「KR create-character C2S/S2C positive transaction and roster initialization」**，而本次最高信心的是**「遠征隊/遊戲身分名稱建立的 Client 本地路徑」**。評估不可偷換標的：

| RR-0010 驗收條件 | 本次狀態 | 精確理由 |
| --- | --- | --- |
| (1) Build/SHA、producer/consumer、field/slot/frame/encoding/scene | **PARTIAL（局部有價值）** | E73/74 指出 `C2S0x3E` 48B、name+6、slot0、`S2C0x4A` word+2、LOGIN scene；但 payload +2..5、frame/connection、scene 準備及 Server 實際方向/時序未閉合，本輪未再跑原始 BIN |
| (2) 正向 request→accepted/rejected result→roster/初值＋duplicate/retry/disconnect | **BLOCKED（核心未閉合）** | 有彼此相容的 Client sender/receiver/共享名稱，但**沒有原版 Server transaction pairing**、`0x4A` result 到 `app2` roster 的網路因果、實際 playable-character 建立、初值/重送/錯誤碼的完整契約 |
| (3) local event 與 wire、選角/建角分離 | **BOUNDED PASS（定義界線）** | `F4244/F4245/F4261` 是 local event；`0x42` selection 不是 create；`CEmploy` 與 `CExpeditionCreateDialog` 分離；不能反推官方 Server 政策 |
| (4) adjacent RR 不越界或重寫 | **PASS（台帳）** | PR #63 只新增檔案、未改 RR-0002/0007/0008/0009 狀態；E75 分開歸 RR-0002 |
| (5) 原稿、Git blob、反證、Server 影響/解除條件 | **DOCUMENTED / SOURCE RERUN PENDING** | E71–E74 報告和 checksum-guard checker 已在 main，有具體解除項；本輪未直接核對原件 bytes，且 RR-0010 原正式台帳仍 `submission=null`、未經 S00/T01 的 `SUBMITTED→IN_REVIEW` 工作流 |

**S00 結論：RR-0010 核心驗收「未通過／尚不能 ACCEPTED」。** 不能把已證的「客戶端遠征隊建名 sender＋local result」寫成已完成「原版 Server 角色創建交易」。原正式台帳保留 `BLOCKED`（已有可執行解阻條件），`GAP-CHAR-0003 OPEN`，兩份 `SPEC-*` 仍 `DRAFT/PARTIAL`；不新增正式 RR review ledger 紀錄（該 ledger 只為 ACCEPTED/NEEDS_REVISION），不假冒研究者 `SUBMITTED` 或 T01 FULL-PASS。

**進度並非零：** E73/74 應納入 DRAFT 以免 Server 開發者繼續只找傳統 MMORPG 的自由創角 request；現可在 Server 實作庫開展**明示為自訂政策的建名模型、Server-side 驗證與合成失敗/重試 fixture 設計**，但不能先把 `0x3E+2..5` 填入猜測，或宣稱原版 Client 已能完成創角。

## 4. 真正需要的後續研究/設計分流（不把無實機當停工理由）

- **Client T03，先取可在 BIN 靜態繼續的工作：** （a）`0x003E+2..5` stack writer/dominance/指令 CFG；（b）LOGIN scene 與 `CExpeditionCreateDialog` 從 N=0/選單進入的真實正向 UI gate（與 RR-0009 去重）；（c）`S2C0x4A` 表的 scene 實際覆寫、`F4245` event與狀態文案；（d）`0x4A`/app2 之前的正式 Client native 必要觸發鏈，缺證仍標 UNKNOWN。
- **Client/角色 T04/T03**：將「expedition 身分名稱建立」和「招募／選取已存在的可操作角色」分離，追 GUI/newly available角色狀態與寫入/名單邊界；不因此新建重複 RR 或擅改 Task owner。
- **T02 / Server 實作**：對 `0x3E` slot0 的 framing/Conn 依現有網路研究補證；把名稱合法性、重名、DB 持久化、冪等、disconnect/retry、初始角色集合當 **Server 自訂決策**，而不是用「需要原版 Server 原碼」阻止可先測試的內部模型。
- **需另行明確授權的相容性驗收**：用隔離的原 Client + 自製 Server／合成環境驗證 `0x3E/0x4A/app2`；即便通過也只說自製 Server 相容，不說還原原版 Server 原始時序。使用者本次**沒有**授權執行原 Client。
- **S00 後續規格拆分選項**：若經後續原生/T04 證據確認是不同用戶結果，另建「遠征隊命名」`REQ`／ bounded `SPEC`；若只是現有建角需求的同一輸入子階段，沿用現有 `GAP-CHAR-0003` / RR-0010，不新建同義 ID。這不是本次已批准的新 REQ。

## 5. 來源 Git blobs（合併後可直接點選）

| 交付 | Path／Git blob SHA |
| --- | --- |
| E71 original | [E71 report](../../kr-extra-roy/20261031-010931-chatgpt-web-roy-E71-RR0010-create-C2S-candidates-S2C-roster-blocker.md) `57f809809e28d24cd9779549d95e9b269db4870b` |
| E72 supplement | [E72 report](../../kr-extra-roy/20261031-chatgpt-web-roy-E72-RR0010-create-secondary-dispatch-roster-native-followup.md) `7f1907f8fa0877c9fcd905eba048ec7f3e52cb9c` |
| E73 name create | [E73 report](../../kr-extra-roy/20261031-chatgpt-web-roy-E73-RR0010-expedition-name-create-C2S3E-S2C4A-native-chain.md) `eeb598db5c9bee8909d97a3376c4637d382c3bac` |
| E74 roster | [E74 report](../../kr-extra-roy/20261031-0244-chatgpt-web-roy-E74-RR0010-expedition-name-roster-shared-state.md) `f3d4f126c5ce6a60a871189ca44015dc4693b97b` |
| E71 verify | `kr-extra-roy/20261031-010823-chatgpt-web-roy-E71-RR0010-verify.py` `96a51b86fa5066eaf8646ad1133a50b611632cbb` |
| E72 verify | `kr-extra-roy/20261031-chatgpt-web-roy-E72-RR0010-verify.py` `92b4e21a55b2c2d0cbe8584d338c32956bdff186` |
| E73 verify | `kr-extra-roy/20261031-chatgpt-web-roy-E73-RR0010-verify.py` `b8fc331db9fe0fdb9922ee748c7f326c86c3b4e6` |
| E74 verify | `kr-extra-roy/20261031-chatgpt-web-roy-E74-RR0010-verify.py` `1e425c2f7cd35caee4a1e208e9fd4c17c43ffbb3` |
| RR-0002 E75 | [E75 report](../../kr-extra-roy/20261031-0305-chatgpt-web-roy-E75-RR0002-roster-0x26-two-layer-gameinfo-handler-native.md) `715bf8cd6edb423becd84fd4faa0a025940092e6`; checker `ea03b4add37ba5969b08bee019faa7ca2d35d41c` |

## 6. 整體 CI 註記（需獨立問題處理）

來源合併前的最新 `main=afc0b1fe661796912a59250bb1968ae48c727843` 的 GitHub Actions [run #41110975506](https://github.com/we88ec3-prog/ttr_anal_multi/actions/runs/41110975506) 已 **FAILURE**，精確錯誤是 **`CLM-CLIENT-0063: NATIVE_VERIFIED requires scoped native evidence references`**；該錯誤早於 PR #63，非 extra/roy1 新增的 13 個檔案導致。本輪不代替其來源 Task 調整 `CLM-CLIENT-0063` 身分或捏造原生 proof 修過 CI；是否在 PR #63 合併後觸發 main CI 須以 GitHub Actions 實際 SHA/結果為準。所有新的 S00 review 文件與 DRAFT 註記仍受該基線警告限制。
