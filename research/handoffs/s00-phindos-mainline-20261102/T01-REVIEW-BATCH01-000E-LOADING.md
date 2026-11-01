# T01 批次 01：000E 分層／000D 動作／loading 23–24 的獨立原生複驗

日期：2026-11-01（Asia/Taipei）。本稿是 **T01 主張級來源驗證與 S00 可用界線**，不是 S00 規格採用、PR 核准、原版 Server 行為認定、全文 FULL-PASS 或可玩驗收。使用者優先把 AI／MEF 和戰鬥連擊核心交給 S00；T01 對 P0-A 只審前端節流、row 來源限定，**不展開 keyup／combo 演算法**。

## 0. 精確來源與工作權限

| 來源 | pinned commit | Git blob | 用途 |
|---|---|---|---|
| T01 工作卡 `research/handoffs/s00-phindos-mainline-20261102/T01-REVIEW.md` | `017d85c88c2ca4651ed6e309a0c6173ac2cb362f` | `96950f0bf7e9b3eb59712efee2d5f0fccb52776a` | 任務/限制 |
| S00 總卡同目錄 `README.md` | 同上 | `591220e86761cbec715838cc26641d4798a832c7` | typed-domain／W1–3／先交可用資料 |
| Web T10 P0-A `research/handoffs/s00-web-skill-gap-20261101/20261101-T10-P0A-V7-Z-INPUT-ROW-CLOCK-BOUNDARY.md` | `0419c66009a958597e95c9a88740d6f7f0d6772c` | `d5de9db6fb6db5fccb837abd5be7e50ca5156d12` | Input row / clock boundary |
| Web T10/T11 P0-B `research/handoffs/s00-web-skill-gap-20261101/20261101-T10-T11-P0B-KR-000E-VTABLE-VS-000D-MOTION.md` | 同上 | `02d09ab834d5f5b878a419a3391da76b9b077dc4` | 000E vs 000D |
| S00 loading `governance/s00-iterations/S00-20261101-LOADING-DISPLAY-LIFECYCLE.md` | `0556a7af8b501cae52d2dd9ffa40ff65b893ad0c` | `072d9516b1bcfc03959465da8b3feb4cacd410e7` | 23/24、顯示候選 |
| S00 loading `governance/s00-iterations/evidence/S00-20261101-LOADING-DISPLAY.json` | 同上 | `96770ee1da111ae3e114c331aac8b2539ff92bc8` | 原生 windows / resource pins |

**原件本人核驗**：`/mnt/data/Tartaros.bin` 長 12,472,320、SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。另外核對本次提供的 `Event.stp`、`Table.stp` 容器各自 SHA，**不能拿這兩件檔案代替缺少的 UI/Texture.stp 與 _LoadDisplay member 實算**。

PE：MZ/PE32 x86 machine 0x14c，ImageBase 0x400000；`.text` VA 0x401000/raw 0x400，`.rdata` VA 0xBD2000/raw 0x7D0600，`.data` VA 0xD61000/raw 0x95E800。根據 section 各自算 VA→raw；以 Python `hashlib/struct` 在**真實原始檔**重算 **16/16 code SHA256 windows、7/7 vtable DWORD、12/12 raw instruction anchors**，再用 GNU `objdump` 自合法函式入口檢查局部位址/指令邊界。完整有限測試收據見同目錄 `T01-REVIEW-BATCH01-000E-LOADING-AUDIT.json`；歷史其它原稿未逐一重驗。第一次自寫 BND 比對字串曾將原生 `830095 ... 74 19` 誤抄，**已改正本輪驗證器預期而非變更來源原稿**，最後 12/12 正確錨點均通過。

## 1. 逐主張矩陣（R0 來源／R2 限定，非 R3）

| Claim | 原生實際證據與分層 | 裁決（Client已證／推論／Server設計／未知） | S00 可採用與禁止推論 |
|---|---|---|---|
| **T01-PHI-B01**：application 000E 分派 | `4ADDEA C7 40 74 40 6C 43 00`：`(0x74-4)/8=14`，app table key0E 指向 `436C40`；`436C40=8B 01 FF 60 28` 由 ECX 物件 vtable +28 **tail jump**，不在 wrapper 中讀 HP / payload | **原生已證，限同一 active application table 與 ECX 實例** | 先確認 manager／active scene 或 controller 實際 ECX 才能推具體處理，不能用封包名稱當 controller 身份 |
| **T01-PHI-B02**：Controller virtual +28 | .rdata `C0FB1C+28→8DC2F0`、`C0FAC4+28→5486E0`、`C0FA14+28→547C80`；各選定完整函式視窗重算 SHA。stub `33 C0 C3`，Single/Formation 的限定路徑為清理/釋放相關成員，不以收到的 row 做 HP 解析 | **有界原生支持**：已核三種 table，不是全部 dynamic 類別 | 不能宣稱「000E 對所有 Controller/Scene 都只是清理」；也不能保證 v7 首戰 live controller 必為 Tutorial |
| **T01-PHI-B03**：scene/common-result 與 P0-B 是否矛盾 | **新增獨立交叉定位**：.rdata `BF6CDC+28→4B0640`、`C06F3C+28→4B0640`，另 `C073B4+28→4C4920`；`4B0640` 的真函式 prologue 已從原 BIN 反組譯。這些 slot 與 controller `C0FB1C` 等是**不同 vtable / 不同動態接收物件層**。既有 T10-W06/T12 談的 `4B0640` 13-byte common-result 是**有條件的 scene/result consumer 路線**，不是每個 controller 自動同時消費 | **有界 vtable 原生事實 + upstream / runtime INSTANCE 未閉合**；此項不否定 T10-W06/T12 有界解碼，也不撤銷 P0-B 在指定 controller 下的反證 | **必須保留兩條 routes**：`000E→436C40→actual vtable+28→(stub/cleanup 或 4B0640/4C4920)`。實際 `scene/context→ECX` 建立和目前 vtable identity 未證前，**common-result 不自動變成 v7/Field19 可用** |
| **T01-PHI-B04**：application 000D | `4ADDD0 [eax+6C]=4B01C0`，長度合法時走 `2+9N`；`4B0250` 讀 actor WORD、`4B0290` 讀 status byte、`4B0313` 讀 motion-like WORD、`4C8A90→actor vtable+68` 有條件消費 | **原生已證局部 parser/code window**，具體 motion-ID 資源與 runtime 呈現未知 | 000D 與 000E 是兩個 app entry；不能說 000E 後必然 000D 或 000D 必成功播放 Isla Motion9 |
| **T01-PHI-B05**：P0-A 發送門檻 | `5457A4..5457F9` 根據 `[FBA7B0]`、`[FB1318]+BF74`、`controller+0C`、delta 決定是否可組 `000A`；原 `.data D6A62C..` little-endian 四 DWORD **100、120、180、300**；row 與 reset 對應 4 個 code windows 本輪 SHA 相符 | **有限原生確認**。clock 單位、所有 writer、按鍵連擊段數 **未知** | 只把這些當本地輸入發送節流的證據，**不能**把 100/120/180/300 當連擊窗口或把 row 次數當攻擊段數；AI/MEF/連段核心由 S00 |
| **T01-PHI-L01**：S2C 23/24 handler 的註冊 | `493170` 函式 `+0x438←494860`、`+0x448←494A90`，6 個 loading 原生視窗含該函式均 SHA 符合。E41 指出下層 dispatcher 是完整 Client object 的 subobject（原點需區分），signed16 command 經 scale16；S00 由此主張 23/24 | **有限原生有據**；本輪核固定寫入槽 +0x438/+0x448，還須在具體接收實例確認完整 subobject base/命令推導 | 23 `payload+2/+4` signed WORD 用作 category/index 候選，24 為另一端的結束候選；**不得與不同方向的 C2S24 混淆** |
| **T01-PHI-L02**：begin/end side-effects | 原生 `494860` 啟用相關 flags 並進資源/繪製條件路線；`494A90` 清理 flags/display resources；二者可返回 0x100。S00 原稿的 native windows 150/549 bytes 本輪重算一致 | **指定原始碼視窗已證，端到端顯示完成及 SceneReady 未證** | 允許規劃 opt-in 的 begin→業務/scene/map/actor→end；**不認證任何 category/index 的 Town1 實際序列**，不能以發24認定地圖/NPC/player 已可走 |
| **T01-PHI-L03**：_LoadDisplay 與 Lua stub | `55D7E0` string registration 視窗、`8DC2F0=33C0C3` 重驗；S00 source 指 `554FC0` 處理 _LoadDisplay.xml、`5550E0` 選 category/index，來源 metadata 顯示 Category1 index0/5、Category2 六圖、Category3 index0。無原 UI/Texture carrier 可直接重算 member | **本地 handler 原生局部確認；資源清單 = S00 pinned metadata，尚非本批獨立資源驗證** | `StartLoading/EndLoading` 綁 zero-stub 不等於直接調 Lua 就開始載入；`552FC0` CFadeObject/38 不等於 _LoadDisplay；texture 存在不證像素必呈現 |
| **T01-PHI-L04**：21 synthetic 正流程 | 來源報告稱 21 項合成測試已過，但 T01 **未執行**這些 Server/client journey tests，亦未部署 | **來源報告／Server設計候選，非 T01 原生驗證** | S00 可以取其為待採的測試用例；不把原作者合成 PASS 當原版人測或 Server 目前可玩 |

## 2. 關鍵差異圖：不能把 base、scene、controller 當一件事

```text
app-key 0x000E (在 4ADD50 建立的 active application table)
    → table + 4 + 8*14 = 0x74 → 0x436C40
    → ECX->vptr[+0x28]                     ← ECX 真正動態型別需要追
       ├─ concrete Controller(Tutorial)  → 0x8DC2F0 (zero)
       ├─ concrete Controller(Single)    → 0x5486E0 (cleanup)
       ├─ concrete Controller(Formation) → 0x547C80 (cleanup)
       ├─ scene-vtable candidate BF6CDC / C06F3C  → 0x4B0640 (13-byte result)
       └─ scene-vtable candidate C073B4          → 0x4C4920 (distinct override)
```

上圖展示的是**相同 slot 對不同物件的實作集合**，**不是已經證明某一場景一定用過所有列出的物件/回覆**。在前一輪 S00「common-result」敘述中，`0x4B0640` 有真實 Native consumer 依據；但 P0-B 的 Controller 表中確實有 stub/cleanup。**兩者應按 runtime active scene/owner/ECX 指標對應去選擇，既不能「全 000E 都是傷害」，也不能「全 000E 都不解傷害」**。

T01 後續 R2 若要對 S00 特定環境確認：從 `4930E0` / active app table callback 追 ECX 實際 owner，再由 `4B7D50` scene installer、T07/T12 scene vtable 及 controller 物件持有追到 `+28` 實際 pointee。沒有追完之前不對 S00 原先 common-result 規劃下 APPROVED/NEEDS_FIX 裁決，也不能動 PR102。

## 3. 可交 S00 的立即實作界線（**建議**而非批准）

- 可保留三個互不混淆的 domain：`ApplicationKey`（000D/000E）、`SceneReceiverVtable`（+28，因 active scene 而異）、`ControllerVtable`（+28，因具體 controller 而異）。不要把 application opcode 當 vtable method ID。
- `000D` 可提供「有 actor 資訊時顯式 motion」的有界 parser 介面草案：`{u16 actor, u8 status, u16 motionCandidate, f32 parameter}` 每 9 bytes，但必須有 actor/scene/context、資源 gate；**傷害/死亡/Server 結果決策不是這個 parser 的驗證結果**。
- 若 S00 規劃 loading，可分離 `LoadingBegin{category,index}`（候選 S2C23，6B）與 `LoadingEnd`（候選 S2C24，2B），並獨立驗 `scene/map/actor/controller` 的 ready。**Town1 category/index 和真實 end 時點 UNKNOWN**。
- 玩家動作輸入 row 與送出 Clock gate 只能作 client-local gating/navigation；技能可用/成本/連段由 S00 原流程處理，不能引用此篇作官方連擊決策。
- 本批沒有執行 Client、Server、PR102、負向/重播/重登/併發/故障／壓測。沒有修改 Task owner、舊稿、RR/APPROVED 或其他對話。S00 對 Server 方案是否採用，**另行負責**。

## 4. 下一批接棒

下一批接 `extra/roy3` commit `58851e4ea2404f2370e8c4310df7384519fdc80e` 四個 W3 報告，優先 `830040 ==3 / !=3` 、`82F660` 的格式門檻、`F43D9→5B9453` 間接001C、Town1/Map182/Quest117/Spawn 未知。受限於目前環境沒有 Field19 兩張 BND 原始 carrier `Map/BoundMap.stp`，應將 header2 的 R 級來源依 pinned baseline 保存，但**不會在未獨立讀到完整 decoded member 時聲稱安全 v2 decoder 或走得通的出生座標**。

**提交分支**：僅 `t01/roy/chatgpt-web`，不上 main；本批無 S00 PR/Server 變更。來源審核決議：**R0 + 限定 R2 PARTIAL**，沒有任何新 FULL-PASS、RR ACCEPTED 或 SPEC STABLE。
