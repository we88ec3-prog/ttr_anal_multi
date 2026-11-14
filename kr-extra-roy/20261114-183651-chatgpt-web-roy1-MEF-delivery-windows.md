# KR Server → Client 的 .mef 可傳遞時機

日期：2026-11-14，Asia/Taipei。工作線：使用者指定的 **extra/roy1**。本稿是有界原件靜態分析及 Server 需求交接，未執行 Client／更新器、未改 Client／資源／Server、未聯絡舊更新站。

## 1. 回答本次問題

研究目標是「我們開發的 Server 可以選哪些時機傳遞內容」，**不要求還原官方曾在何時傳 .mef，也不以取得已不可得的原版 .mef 作為前置**。實際區分三個完成條件：

1. 檔案內容已被接收、還原並寫入本機。
2. 遊戲資源系統能取得正確版本的內容。
3. 對應解析器與執行器確實使用內容。

**已找到的正向檔案交付通道是遊戲程序啟動前的原版更新器流程。** 遠端更新清單的 FILE 檔名是資料；普通檔案分支沒有把可交付名稱限制成現有幾種遊戲副檔名。新增一個符合該分支條件的 `DeliveryProbe.mef`，可以經名稱加 `.gz`、HTTP 下載、gzip 解碼及普通檔案寫入路徑交付。這是從實際接收程式推導的**條件式靜態可行性**，不必先找到原清單曾列出 .mef。完整原件鏈見附錄 A。

此通道仍有具體前置：原版啟動器必須實際啟用更新流程，且能連到相容的更新服務。原 EXE 有自己的更新端點選擇，並不是遊戲 TCP Server 換好後就會自動轉送。直接啟動遊戲 BIN 或指定測試 EXE 不會因此自動走原更新器。**這次沒有建立更新服務、調整端點或完成實機交付。**

**遊戲內的可收包窗口比「換圖那一刻」寬。** 有效連線、framing、lane 及 callback 就緒時，登入／選單、載入畫面、已進地圖等階段均可能分派 Client 已支援的命令；共用層不要求每一筆 S2C 都先有配對 C2S。尤其 `0023` 開 loading 到 `0024` 關 loading 之間，正常主循環仍會處理接收佇列。

**但是，遊戲 TCP 的可收包窗口尚不能列為 .mef 檔案接收窗口。** 已查入口仍缺把新 .mef bytes 接收／重組／登記為資源再交解析器的正向鏈。時間選對不能補出不存在於已證路徑的資料消費端。這裡的剩餘問題是 Client 相容介面，不是官方歷史發送順序。

**可用的排程設計是「啟動前完成內容交付，遊戲中依狀態啟用已安裝內容」。** 對已證 .seq 場景介面，Server 可於符合條件時送場景鍵；對原生 .mef 的解析與執行，本輪仍未證實，不將 .seq 或 Server 自訂 JSON 改名當作 .mef 功能完成。

## 2. 時機矩陣

「可收合法命令」是共用 transport 的有界能力，不保證任一 opcode 在所有狀態有效。

| 時機 | 可以安排的交付／處理 | 必要條件 | .mef 結論 |
|---|---|---|---|
| 原版更新器執行更新，遊戲尚未啟動 | 遠端 FILE 清單驅動普通檔案下載、解壓、寫入；也存在封裝更新支線 | 相容更新端點可達、更新流程啟用、清單／檔案／目錄條件正確、更新成功 | **可作普通檔名交付，靜態有正向鏈；不證明遊戲能執行其內容** |
| 遊戲已啟動但 game socket 尚未建立 | 已落地內容可供本機初始化 | 檔案已存在，資源掛載／映射一致 | 不能透過尚未建立的 game TCP 傳檔 |
| 登入、選服、選角等已連線階段 | 有效 S2C 可進接收佇列與對應 handler | 正確連線及 lane；目前 handler／場景與欄位就緒 | 未證遊戲內通用 .mef receiver |
| `0023` 開 loading 後、`0024` 關 loading 前 | 正常 tick 仍 pump；可分批處理既有入場命令 | 主循環有運作、前一同步 handler 正常返回；個別命令可讓同 lane 留待下一 tick | **是可收命令窗口，不是已證的任意檔案下載窗口** |
| `0038` 預載或 `0012` 載圖之前 | 安排所需內容已在本機可見，再觸發既有讀取器 | 不能只看「TCP 已送達」；掛載索引與快取可能更早建立 | 未證這兩個命令可夾帶 .mef |
| 舊場景切換至新場景 | 前端／全域命令按自身 gate；場景命令按分派當下的 scene | 新場景 handler 已安裝；不把 scene-null 當自動等候區 | 無已證的 .mef 暫存及稍後回放機制 |
| 已在地圖、角色可活動或 NPC 互動／戰鬥中 | 共用網路層可繼續接收既有命令；idle 時可按已證鍵啟動既有場景 | 各 handler 的資料、scene、busy 等前置成立 | 未證原生 .mef 熱更新／熱啟動 |
| 場景腳本正在執行 | 本次已載入／解析出的 Lua 內容維持既有版本 | 新腳本啟動須等 busy gate 可通過；外部下載是另一通道 | 更新磁碟檔不會自動替換已載入的程式內容；不排除腳本稍後另行讀檔 |
| 結束遊戲後、下次啟動前 | 可再次做版本與內容部署 | 走已定義的更新流程，讓新程序重建掛載與映射 | 可重用啟動前交付策略，仍需獨立證實 .mef consumer |

## 3. 這次新增的判斷，與既有研究的關係

最新 main 已有大量 MEF 查核。本輪先讀取其限定陰性範圍，沒有重做全套 STP 檔名搜尋，也沒有把 `MapList.TRIGGER` 名稱當 parser 證據。

本輪新增／補足：

- **檔名由新清單提供的正向路徑**：從 manifest FILE 屬性、更新計畫、新項目迭代、provider 到 HTTP／gzip／本地寫檔，回答「未曾在原清單列出的 .mef 能否作普通檔案交付」。
- **loading 主循環位置**：以正確 Client 子物件基址證明收包 pump 在 loading 的場景／部分演出更新 gate 之前。既有研究已證 `0x100` yield，本輪補其與實際 tick 的關係。
- **交付截止點**：STP 同名優先、成員 loaded flag、映射提前解析、腳本 busy gate 及 owned buffer，說明為何「進圖前送出」不是完整內容已生效的保證。
- **場景啟用的必要條件**：直接覆核 `0047 → 503040 → 561760`，兩個 WORD 是選擇鍵；busy 分支返回，不會自動等下一份腳本。

沿用但不冒稱新發現：

- 地圖 TRIGGER 查詢後未形成 .mef consumer 的已核分支。
- `0012/0038/0014/0049` 的既有數字 ID／本機資源用途。
- 通用 frame 的 `0x1000` 上限及逐 frame 佇列。
- 同 Map ID 重送 `0012` 可走跳過正常模型／碰撞讀取的分支。
- Lua 資源 loader 與 Event/SceneList 的既有 .seq 載入路徑。

## 4. 遊戲內時序的精確界線

### 4.1 Loading 不是收包開關

以完整 Client 物件為 C，tick 使用 C+8 子物件：

- `491983` 取 `(C+8)+140 = C+148`，`49198A → 804740` 先分派接收佇列。
- `491CA7` 才測 `(C+8)+BFCC = C+BFD4`。loading 非零時跳過包含 current-scene vtable +18 的更新。
- `491E75` 再測同一旗標，略過部分更新，包括 `491ED7 → 561520` 演出管理更新。
- `49313F..493150` 在 handler **返回後**計算 `return==100h && loading`，形成 callback 的 yield 回傳值。`804740` 取得該值後先回收當筆 record，才於 `80499F/8049A3` 決定停止本 lane 當輪取包；本筆不重播。

這表示 loading 可保留接收與命令控制窗口，也表示**可以收到啟用命令，不等於相關演出會在 loading 尚未解除時照常逐幀更新**。

同步本機讀取或 Wait 尚未返回時，網路 IOCP 入列不等於主執行緒已消費下一筆。不得據此承諾在任意一毫秒送入內容，都能趕在這次讀檔之前生效。

### 4.2 場景切換要以分派時點判斷

`4B7D50` 同步離開／析構舊 scene、清空 current pointer、安裝新 scene、呼叫初始化。封包在 pointer 清空的幾條指令期間抵達網路，不代表會立即插入 main-thread dispatch。

已證的限定負面分支是：**真正執行 `4B7EC0` 時 current scene 仍為空**，它只 log／return，沒有保存供新場景重播。前端與全域直接覆寫命令不一律經過這個 gate。因此 Server 應按有效目標 scene 排程，不將先塞進 socket 當成 Client 自動延後處理的承諾。

### 4.3 已有腳本可延後啟用，但不接受任意檔案名稱

`0047` 的已證任務管理器 consumer `503040`：

```asm
503098  movsx ecx,word [eax+4]    ; scene key
50309c  movsx edx,word [eax+2]    ; quest key
5030a0  push ecx
5030a1  push edx
5030a2  mov ecx,0xfb73c0
5030a7  call 0x561760
```

`561760` 的有界順序：

```text
manager+28 != 0
    → 5617CF..5617E4 log 後跳至返回區；本次不讀新腳本
manager+28 == 0，且其他 mode／場景 gate 通過
    → 5618E9/5618EC 保存兩個 key；5618EF 設 busy
    → 查既有場景表
    → key 命中才組 Event/Sequences/<funcName>.seq
    → 55D6A0 / 6F4A50 讀取本機資源
```

這提供「先交付、稍後按需要開始」的已知 .seq 內容啟用模型。它不把 `0047` 的任意尾部當檔案，不接受 Server 任意指定 `.mef` 檔名，也未證實原生 MEF parser。忙碌時不可連送下一場景並預期 Client 內建排隊。

## 5. 交付完成要早於哪個截止點

| 要變更的內容 | 必須早於 | 為何 |
|---|---|---|
| 包索引、member 對應與 SceneList 新映射 | 對應包掛載及 singleton 首次解析；可靠部署策略為遊戲啟動前 | 已掛載 provider／索引與已解析 key 表不會因磁碟檔剛出現自動刷新 |
| 已有映射指向的腳本內容 | 真正資源 open／讀取之前，且 provider 回傳的是新版本 | STP 優先於散檔；member 可以已有 buffer |
| 本次 loader 取得的來源內容 | `6F4AD0` 複製進獨立 buffer 之前 | 之後磁碟更新不改這次已取得的來源；解析後原始 buffer 會釋放，並非整段場景持續持有它 |
| 場景啟用命令 | manager idle、key／角色／場景前置成立後 | transport 可收不代表 business handler 可執行 |
| 一般同地圖重新讀資源 | 需要有明確的重載入口；不能只重送相同 `0012` | 相同 Map ID 可以跳過正常模型／碰撞載入 |

部分 STP 成員在引用歸零後會清 loaded flag，下一次可再 materialize，**不能宣稱所有資源全程永不重讀**。但其既有 offset／length／membership 不因此重建。本輪沒有找到可由遊戲 Server 操作的通用 remount／cache invalidate 介面，故不承諾遊戲中直接替換 STP 會生效。

`6F4BC4` 釋放資源物件，`6F4BC7 → 891D3D` 釋放本次複製出的來源 buffer；場景繼續使用的是載入／解析後的 Lua 狀態。這項結論只涵蓋本次 loader 呼叫，不排除腳本之後另行讀檔。

### 5.1 更新完成與遊戲啟動的門檻

原 launcher 的正常成功順序為：`4BADC0` 完成檔案作業 → `4788FA` 設更新物件 `+170=7` → `47891A` 發 `0x6D2` 完成訊息 → `44E230` 恢復相關 UI 控制項 → 啟動遊戲 handler 將 `Tartaros.bin` 加入 launch queue → 關閉 UI 時停止並等待更新 worker → `46E850` 對 BIN 做單檔 MD5 比較 → `4722E8 CreateProcessW`。

這是正常更新流程的先後關係，不是所有資源已通過完整驗證的證明。完成支線的 manifest Delete／Move API 回傳值沒有被再次檢查，普通檔案 provider／writer 也沒有拿 `FILE.Checksum` 重算並驗證 `.mef`；**launch gate 比較的是 BIN 自身，不能當成 `.mef` hash 或載入 ACK**。Server 的發布驗收必須另外核對真正落地的 bytes。完整分支、錯誤與端點來源見附錄 A。

## 6. Server 開發需求交接

以下是供 S00 在現有 `REQ-0019／REQ-0021`、`GAP-SCENE-0001／GAP-FLOW-0001` 與 SFD-0015 關卡內容工作線中去重、採用的候選需求，**未建立第二份正式台帳，也未修改 owner／RR／APPROVED**。

| Server 開發需求 | 已證 Client 介面／約束 | 實作與驗收交付 |
|---|---|---|
| 相容更新服務與內容發布 | 原版 launcher 的 manifest → 普通檔案 → HTTP／gzip／寫檔鏈 | 相容清單及 payload、檔名／長度／校驗與版本關聯；先完成合法可達的更新服務部署條件。單次正常更新後核對落地檔 hash，再核對遊戲啟動；不把 BIN 自身校驗當全部資源校驗 |
| 交付與啟用兩階段排程 | 本機索引／SceneList／buffer 的讀取期限；已有 `0047` 場景鍵 consumer | 在啟動前完整部署，遊戲中按功能啟用。內容版本與實例採用版本可追溯；沒有原生版本回報欄位時，不虛構 ACK/opcode |
| 依連線與場景狀態發布 | 有效連線／lane、當前 handler、scene-null 無回放、loading yield | 將 connection generation、scene/map/case、既有 ready／回報語意納入 Server 排程；不用固定延遲假裝已載入 |
| 場景播放排程 | `561760` busy gate，場景鍵命中及其他模式前置 | Server 管理待啟用項目，按已確認的場景完成介面銜接；未證通用 ACK 時保留缺口，不把 `0009` 或 `0014` 稱成檔案完成通知 |
| .mef 相容能力的明確狀態 | 通用接收層不是檔案重組器；本機 .mef parser 未閉合 | 交付、可讀、可解析、可執行分別記錄。不得因普通檔案已下載就把 nativeMef 設為已完成；不新增猜測的 MEF blob opcode |

其中「更新服務、發布資料、內容版本、發送排程」是 **Server 待開發**；「原 Client 的 .mef parser／executor 或可用 blob consumer」仍是 **Client 介面待逆向**，不能將未知 wire 推給 Server 猜。新規則與內容不需要等原版 Server 的內部實作，當前遊戲內檔案介面也不會只因 Server 新增程式而自動出現。

本輪沒有要求修改 Client，也沒有將 hosts／DNS／端點攔截或變更當作已授權部署方案。

## 7. 已完成與剩餘項目

- **本輪已完成的有界靜態問題**：普通新檔名的 updater 交付能力；原版 launcher 更新與遊戲啟動的條件關係；遊戲 TCP 在 loading 的持續分派；scene／loader／快取對交付期限與啟用時機的限制。
- **Client 待逆向**：能實際消費 .mef 的檔名／buffer／parser／executor 正向鏈。已查多層接收表、Lua loader 與 TRIGGER 路徑沒有提供此鏈，但不把有限陰性結果擴成全 Client 永遠不存在。
- **Server 待開發**：上述更新服務與狀態排程需求；本輪沒有實作、部署或測試它們。
- **跨功能待整合**：把 patch 內容身分、掛載版本、可用 scene key 與 instance 排程串成同一版本契約；由 S00 採用，T01 獨立審核。
- **待遊玩／更新驗證**：正常更新實際落地、指定啟動路徑、磁碟版本與遊戲使用版本一致、正常進圖及後續場景效果。本輪沒有執行任何遊戲或 updater，不要求官方歷史封包作為可行性分析的必要條件。

## 8. 來源、分支及驗證

### 來源身分

| 原件 | bytes | SHA-256 |
|---|---:|---|
| KR Tartaros.bin | 12,472,320 | 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91 |
| KR Tartaros.exe（更新器） | 2,594,816 | 03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f |

使用 GNU objdump 與 Python 標準函式庫；依 PE section table 轉換 VA，沒有以同一個差值跨套 BIN／EXE 或 code／data。現成 Ghidra 偽碼僅作導航，主要主張以原始 bytes、指令邊界與資料流補證。沒有新跑全量反編譯。

整合後以唯讀程式重驗 **91/91 原件視窗、28/28 精確 anchors 相符**：BIN 31 個視窗、EXE 60 個視窗，共 27,895 bytes。兩份完整檔案 SHA-256 也均相符。詳見 [證據及重現說明](MEF-delivery-windows-20261114/README.md)、[驗證結果](MEF-delivery-windows-20261114/verification-result.json)。這是作者端來源／bytes 核對，與端到端更新驗證及 T01 FULL-PASS 分開。

### 開工與權威狀態

- 起始核對的 `origin/main`：`ba5f96dfa94d734cbded291fb8887f50426bfa77`。
- 指定作業分支 `extra/roy1`：`d7288de6c48b59b58b7c8ba07739034dfb64fd11`。
- 已讀專案 `02-PROJECT-SHARED-INSTRUCTIONS.md`、兩分支 AGENTS、最新 Client 修改政策、T01／相關 Task README、task.json、RR 台帳及收件箱、共用已驗知識與 bulk 來源說明。
- 本輪是使用者明確指定的 MEF 可交付時機專題；其他 Task 舊退回保留原狀，未順手改正／結案，也未重新認領 RR。
- 共用 FULL-PASS 索引沒有准入本輪整條 MEF 交付／執行主張；作者端 byte 核對不等於 T01 FULL-PASS。
- 在既有 `extra/roy1` 新增本稿與相關證據；main 只讀，不另建 branch、不自動 merge。
- 分析初稿完成後，使用者明確要求「分析請推上git」。本次已獲 Commit／Push 授權，目標為既有 `extra/roy1`；實際提交結果以 Git 歷史及遠端讀回為準。

### 主要既有來源

1. [最新 MEF 可行性基線](https://github.com/we88ec3-prog/ttr_anal_multi/blob/ba5f96dfa94d734cbded291fb8887f50426bfa77/governance/s00-iterations/S00-20261101-MEF-RECEIVE-FEASIBILITY.md)，Git blob `6fc6018a3dd5119cbd927fa183cb4228229d0dd7`。
2. [E84 前端及場景分派](https://github.com/we88ec3-prog/ttr_anal_multi/blob/ba5f96dfa94d734cbded291fb8887f50426bfa77/kr-extra-roy/20261101-chatgpt-web-roy-E84-RR0007-outer-router-alternate-paths-native-review.md)。
3. [E60 接收與場景 gate](https://github.com/we88ec3-prog/ttr_anal_multi/blob/ba5f96dfa94d734cbded291fb8887f50426bfa77/kr-extra-roy/20261030-113803-chatgpt-web-roy-E60-RR0007-KR-auth-roster-selection-scene-gated-S2C-dispatch.md)。
4. [20261107 MEF 初始化／TRIGGER 邊界](https://github.com/we88ec3-prog/ttr_anal_multi/blob/ba5f96dfa94d734cbded291fb8887f50426bfa77/governance/client-variants/20261107-mef-resume/native/README.md)。
5. [20261109 本地腳本能力與 Server 分工](https://github.com/we88ec3-prog/ttr_anal_multi/blob/ba5f96dfa94d734cbded291fb8887f50426bfa77/governance/client-variants/20261109-mef-town-services/README.md)。
6. E14／E15 的兩條 .seq loader、T06 本機資源還原契約及既有 BIN framing 原稿，均由附錄及 [source-manifest.json](MEF-delivery-windows-20261114/source-manifest.json) 保留精確來源。原始 .mef 未取得，不是本輪普通檔案交付鏈的前置。

本稿下列附錄保留完整支線原稿及原始指令證據；證據目錄另有原件 VA／raw／hex／SHA-256 視窗與唯讀重驗程式。


## 附錄 A. 更新器的新增檔名、HTTP／gzip 與啟動門檻

日期：2026-11-14。供 extra/roy1 本次分析整合的臨時筆記；未修改 repo、Client、資源、分支，未啟動 EXE/BIN 或聯絡更新站。

### 結論

**能。這份原版 Tartaros.exe 有一條由新遠端清單 FILE.name 決定名稱、HTTP 下載 gzip 內容、解壓後寫入一般檔案的完整路徑。** 在合法可達的相容更新站提供新清單項目 `foo.mef`，並提供其所要求的 `foo.mef.gz`，可走此已存在的交付路徑；不需要證明官方清單曾列過 `.mef`。這是靜態確認的通道能力，尚未以實際更新站、原 launcher、指定 Client 做端到端驗證。

明確可用窗口是 **Tartaros.exe 本次更新作業中、啟動 Tartaros.bin 之前**。它是 Client launcher 發出 HTTP 請求後由 patch service 回覆，不是遊戲 TCP Server 可隨時主動推檔的 API。指定 BIN 若直接啟動而未走此 launcher，不能據此視為有此窗口。

普通檔案路徑以 `4B7630` 未匹配 package mapping 為條件；該函式的副檔名比對決定是否歸入封裝，未匹配會落入普通寫檔分支，並不是拒絕所有未列出的副檔名。`foo.mef` 可使用不落入 package mapping 的正常相對路徑。下載成功只證明檔案交付；BIN 對 `.mef` 的解析、載入和執行沒有在本子任務得到證明。

### 原件與範圍

- 原件：`/workspace/scratch/b43c6175f310/project_sources/01-Tartaros.exe`
- SHA-256：`03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`
- PE32，ImageBase `0x400000`。
- `.text` VA `0x401000`、raw `0x400`，本文指令 raw offset = VA − `0x400C00`。
- `.rdata` VA `0x4C7000`、raw `0xC5A00`，字串／虛表 raw offset = VA − `0x401600`。
- `.data` VA `0x4E9000`、raw `0xE6C00`，資料 raw offset = VA − `0x402400`。
- 已先讀共用指示及現有 `S00-20261101-MEF-RECEIVE-FEASIBILITY.md`（main snapshot，722 行），新結果補上其未追完的動態檔名來源，不依賴舊版清單內含 `.mef`。

### 1. 遠端清單確實可以供應新檔名

#### 已證的清單語義結構

| 節點／欄位 | 原件消費方式 |
| --- | --- |
| `PATCH` → 第一層 `FOLDER` | `4B8CA0` 對新舊清單各建 document、呼叫 `415500`，再用 `40B2F0 / 416C20 / 40B1B0` 取得節點，於 `4B8D91` 呼叫差異計畫器 `4B8390`。字串在 `4D138C/4D139C`、`4D1394/4D13A4`。 |
| 該 `FOLDER` 下的 `FILE` | `4B83E5..4B849D` 列舉舊／新 `FILE`，每項進 `4B7FE0`。新清單入口 `4B8482`。 |
| `FILE.name` | `4B8026` 引用 `4D12F4 = name`，`4B805C → 415020` 取屬性；`4B80D5..4B80EC` 將當前相對路徑前綴加上此 name，作為清單 key。 |
| `FILE.Checksum` | `4B8070` 引用 `4D12FC = Checksum`，`4B80A3 → 415020` 取屬性；存於 metadata。 |
| `FILE.FileLength` | `4B80B7..4B80D2` 以 `4D1308 = FileLength` 取整數；差異器用於累計要處理的長度。此次未把此累計值擴張為最終下載內容驗證。 |
| 子目錄 `FOLDER.name` | `4B7F20` 讀 `name`；`4B8390` 的後半遞迴處理目錄。根層文件可先以普通 root FILE 項目論證 `foo.mef`，不需完整復原所有目錄／封裝規則。 |

這是解析後的 XML 語義；留存 Integrity 原件另有既有研究已辨識的 EX/zlib 包裝。此表不是可以直接上線的完整 manifest 文件，也未宣稱所有 XML 外層編碼／版本欄位可以省略。

#### 新檔案清單與其他操作清單分開

`4B8390 → 4051C0` 的參數依序是 old FILE map、new FILE map、`plan+0x214`、`plan+0x230`、`plan+0x24C`、總長度指標。

- 新清單獨有名稱：`4052EC..40531B` 或尾段 `40535E..4053AA` 將 new map 的 key 複製到第三個參數，即 **plan+0x214**。
- 同名但 Checksum 字串不同：`40524F..4052A5` 將該相同路徑加入 **plan+0x230**。
- 舊清單獨有名稱進 **plan+0x24C**，屬其他刪除操作，不可和新增清單混用。
- 相同名稱、相同 Checksum 不加入上述下載清單。因此 Server 只有修改檔案內容、卻保留同一清單 Checksum，不能據此期待每次重新交付；新增項目／需更新項目必須真正進差異計畫。

新增路徑的完整跨物件傳遞為：

`4B7FE0(FILE.name)` → `4051C0(plan+214)` → `47A460(return this+214)` → `47879D` → `4787C6 → 4BADC0` 的第 4 個參數（`[ebp+14]`）→ `4BB03D..4BB0DB` 新檔案迴圈 → **`4BB0C1 → 4BA280`**。

`4BADC0` 與 `4BA280` 是執行器，`4B8BA0/4B8390` 屬計畫器；本文的 `plan+214` 不是執行器欄位。

#### Provider 身分不是推測

1. `47713E → 47A590` 在 stack `ebp-3D8` 建 provider，傳入本次 launcher 更新物件。
2. `47A5A2` 寫入 vptr `4C8DD8`；原件此處首個 DWORD 是 `47A5C0`。`47A5AE` 把更新物件放 provider+4。
3. `477CBD..477CCA` 把同一個 stack provider 傳給 executor constructor `4B9750`；`4B9776..4B977C` 保存於 executor offset 0。
4. 普通檔案分支 `4BA624..4BA64D` 把 root、該 filename、outBuffer、outLength 交給 executor offset 0 指向之 provider 的 vtable 首槽。因此此處 `call eax` 解析為 **47A5C0**。

### 2. foo.mef → foo.mef.gz → 解壓 bytes → foo.mef

`4BA2BF → 4B7630` 查 path 對應的封裝。未命中時 `4BA2CB` 跳 `4BA541`。`4B7630` 有 package 規則的路徑前綴與副檔名選擇；未命中返回 null，由這條普通分支接手。

`47A5C0` provider 從 `[ebp+0C]` 收到 FILE 的相對名稱，建立完整相對名與 basename。`47A6EB/47A6FB` 使用 `4D4F14 = .gz`，分別追加到這兩個名稱；basename 用於本機暫存，完整相對名用於遠端請求。`47A7E5..47A801` 把 `\` 正規化為 `/`。

`47A806` 讀 `[4EA4E0] = 4C8DDC = PatchTemp/`，建立本機暫存名；`47A8C0..47A8DB` 呼叫 `478AC0(remoteRelative, localTempRelative)`。故正常示例是：

| 角色 | 名稱 |
| --- | --- |
| 新清單 FILE.name | `foo.mef` |
| 遠端相對內容路徑 | `foo.mef.gz` |
| 本機壓縮暫存 | `PatchTemp/foo.mef.gz` |
| 解壓後普通目的檔 | `foo.mef` |

`478AC0` 把 remoteRelative 接到本次更新 URL base，把 localTempRelative 接到本次目的地 base（`478B03/478B24 → 4813B0`），再於 `478B86 → 44B0C0` 執行 HTTP 檔案下載。`44C227` 為 InternetOpenUrlW，`44B4A2 → 44C150 → 44C175` 讀 WinINet body，`44B505` 寫暫存。

#### gzip 解碼有實際指令，不只是副檔名字串

- `47AB13 → 43E330` 打開暫存檔，`43E363..43E36F` 要求最初兩 bytes 為 `1F 8B`；不符返回失敗。
- `47ABA8 → 43E3A0` 建壓縮檔 wrapper，`43E481` 設 vptr `4D4F1C`。
- 此 vtable `+0x10 = 43E5D0`，reader `47A360` 的 virtual call 接到 `43E5EE → 446B20`，再於 `446C13 → 41ED50` 進入實際 inflate 狀態機。
- `43E4C2..43E4D5` 讀壓縮檔末尾 4 bytes 到 wrapper+0C；vtable `+0x2C = 43E6D0` 回該長度，`47AC58 → 47A3E0` 用它分配解壓輸出。這是 gzip footer ISIZE 路徑。
- `47ACA5` 讀解壓內容；讀取失敗時清空輸出。`47AD9D` DeleteFileA 壓縮暫存，失敗亦清空輸出並返回失敗。

普通檔案執行器檢查 provider 成功且 outBuffer 非空（`4BA64F..4BA672`），然後 **`4BA696..4BA6A4` 以 `wb` 打開相同 FILE 路徑，`4BA6C9` 寫 provider 提供的解壓 bytes**，關檔與釋放 buffer 後返回。這個普通 branch 不做 `.mef` 格式分析，也沒有在已核對的 name → plan → provider → writer 鏈拒絕 `.mef`。

主啟動程序 `46E6C3 GetModuleFileNameW`、裁掉最後 `\`、`46E6FB SetCurrentDirectoryW`，先把工作目錄設為 launcher 所在目錄；普通目的路徑因此相對於此工作目錄（本次正常流程）。

### 3. 錯誤與完成狀態

不能把某一層的 success bit 宣稱為完整檔案、所有資源雜湊、遊戲載入均通過。

- HTTP 層 `44B0C0` 會查 Content-Length、建立本機 `wb` stream；InternetReadFile 迴圈直到讀回 0。寫入返回 0 或例外會失敗。已核對函式未見在最後以累積 bytes 嚴格比較 Content-Length；取消分支也不是自行完整性證明。
- provider 使用 gzip magic、wrapper 解碼、讀取與清除暫存的成功路徑；它沒有接收 FILE.Checksum 作參數，也未在這條普通分支重算 `.mef` MD5 後比較清單。
- 普通 writer 若開檔／寫入失敗，回 0；`4BB0C6..4BB0CC` 將新增作業失敗向 `4BADC0` 呼叫者回傳。
- `4787DE..4787E5` 檢查整個 executor 的返回。失敗在 `4787F1` 設更新物件 **+170 = 9**，通知錯誤，未走正常完成支線。
- 成功走 `4788CE`：刪除 Integrity_temp.xml 與舊 Integrity.xml，`4788EE MoveFileA(Integrity_new.xml, Integrity.xml)`；隨後 `4788FA` 設 **+170 = 7**，`47891A PostMessageW(hwnd,0x6D2,0,1)`。注意這裡未檢查三個 Delete/Move API 的返回值，故狀態 7 本身不等於磁碟 manifest 替換成功已再次證明。
- message dispatcher `45022C..45024F` 將 `0x6D2` 送 `44E230`，其 `44E242/252`、`44E262/272`、`44E27F/28C` 呼叫 ShowWindow(5) 與 EnableWindow(1) 恢復更新完成後的三個控制項。
- `4EE514` 是本次更新工作仍啟用的旗標：`478A32` 設 1 後啟動 `476C40 → 4770B0` 工作；取消／收尾 `478A72` 清 0。provider 在 `47A71E` 與 `47AA72` 看見 0 會提前離開；不能把此當成另一個正常下載模式。

### 4. 與 BIN 啟動的先後關係及校驗對象

正常成功次序是：檔案執行器完成 → 更新物件狀態 7／完成訊息 → 使用者啟動遊戲 → 原 launcher 結束 UI → 對 BIN 做單獨校驗 → CreateProcessW。

- `44CC00` 是把啟動遊戲行為加入佇列的 handler；`44CE92` 固定推入 `Tartaros.bin`，`44CEC3 → 450800` 加入 launch queue，`44CEDC → 44D240` 關閉 launcher UI。
- `44D240` 用 vtable+1C (`4C7954+1C = 452410`) → `4608F0 DestroyWindow`；WM_DESTROY 由 `45011E → 44CBC0`，`44CBCE → 478A60` 停止／等待更新工作。`44D258 PostQuitMessage` 結束 message loop。
- `46E850` 先 `46E86F → 46E440` 執行 launcher/UI 工作，返回後才處理 launch queue；`46E8C8` 特判 `Tartaros.bin`。
- BIN gate 讀本機 `Integrity.xml`；`46E9CA..46EA28` 找 `FILE.name` 與 BIN 名稱匹配的項，`46EA6D..46EA93` 讀該項 `Checksum`。
- `46EAE0 → 411D90 → 411C30` 計算 BIN 的 16-byte digest，再轉 32 個小寫十六進位字元（`%02x`）。原件使用 MD5：`4B67F0` 有 MD5 初始值，`4B69B0 → 4B57E0` 有第一輪常數 `D76AA478` 及 rotate 7；`46EB10 → 4276F0` 與清單 checksum 比較，成功才在 `46EB1F` 將 allow 設 1。
- `46EB67..46EB7F` 依 allow 呼叫 `472250`；`4722E8` 才 CreateProcessW。此證據只保證它要校驗 **Tartaros.bin**，沒有對全部資源／`foo.mef` 逐一重驗的意思。
- `472250` 建立程序後只關閉 process/thread handle 返回；已核對的後續主程序 launch queue 路徑沒有重新跑更新工作。沒有證據可把這個 launcher 通道搬到遊戲登入、換圖或副本活動中當成在遊戲程序內可用的收檔機制。

### 5. 更新 URL 屬於原 launcher 的獨立端點

這份 EXE 的 host/path 來源已追到內建表，不是遊戲 Server 下發一個新 URL 即可改指向：

| 來源 | 已核內容 |
| --- | --- |
| `44C811 GetCommandLineW → 44C8A0` | 依啟動命令列選兩個模式之一；`44C920` 查 `4E90B0` 的表。 |
| 表 `4E90B0 / 4E90BC` | host 都指向 `funpleworks.wzcdnservice.com/funpleworks/`；路徑分別是 `Test`、`patch`。原始字串地址 `4C77A0/4C7800`、`4C77F4/4C7854`。 |
| `44C844..44C87C` | 把選出的 host/path 存在 UI 物件+2B8/+2D4。 |
| `44E087..44E0B8` | 把這兩個欄位與空的目的地 base 交 `476C70`。 |
| `476CA4..476D18` | `http://` + 正規化 host + 正規化 path；`481510` 正規化斜線、補上末尾 `/`。正常表模式因此為 `http://…/funpleworks/patch/` 或 `http://…/funpleworks/Test/`。 |
| `478B03 → 4813B0` | 在上述 base 後接本次要求的遠端相對名，例如 `foo.mef.gz`。 |

沒有操作上述第三方端點。未提出或執行 hosts/DNS 修改、服務繞行或 Client patch。**部署前置**是：使用者授權的環境與 launcher 設定能合法到達我們的相容更新服務，或另有已授權的整合方案。現行遊戲 Server 本身有 TCP port 並不滿足此前置。

### 6. 要列成 Server 開發需求的部分

1. 相容 patch HTTP service：提供 launcher 實際請求的 Integrity.xml.gz、Master.stp.gz 與新增 FILE 路徑的 gzip 內容；不能只提供遊戲 TCP opcode。
2. Manifest/content 發佈：以相容的包裝、版本／格式欄位、FILE name、Checksum、FileLength 建出 coherent release；新檔案進 plan+214；同名更新要改到差異判定可見的 checksum。`PatchClientVersion` 在 `477758..47776F` 等於 1 時不要求 launcher 自身更新；其他值會走額外 self-update 路徑，不能任意宣告版本。
3. 路徑／封裝一致性：普通相對檔名需在所提供／使用 Master package mapping 下落入普通寫檔分支；若要進 package，另以既有成員寫入路徑整合，不能拿散檔結果當封裝成員完成。
4. 啟動前同步：所有要求的內容／manifest 完成後才使用正常 launch；不可把原有成功訊息或 BIN 單獨 MD5 誤用為 `.mef` 已載入、已執行的 ack。若後續要 Server 強制某資源版本，需有自己的明確版本／就緒契約。
5. 更新服務端點部署前置與指定 v2 launcher 整合需另外落地；此輪只有分析。

Client 待逆向仍是 `.mef` 的 consumer／語義、以及若要求遊戲執行中傳輸是否另有可用機制。實際以原 launcher 更新無害測試檔後確認磁碟 bytes、錯誤路徑與再啟動，屬後續整合驗證；不應以缺官方 `.mef` 樣本阻擋上面已證的一般檔案交付能力。

### 已有報告的一項有界更正

現有 baseline 把 `4BAF92 → 4BA9E0` 與 `4BAC75 → 4BA280` 接成一條；原件 `4BA9E0` 與 `4BAC00` 是相鄰但不同函式。此次新增 FILE 的直接已證入口是 **`4BB0C1 → 4BA280`**，不用該含糊舊鏈作支撐。

## 附錄 B. 遊戲接收層、loading 與場景切換

本附稿由 `/root/receive_windows` 交付主研究者整合。研究目標是新 Server 可以利用哪些 Client 接收／分派窗口，不尋求還原官方 `.mef` 發送歷史。原件只讀，未執行 Client、未改原始資源；支線研究階段未自行 commit/push，未改 RR/owner。

### 來源與範圍

- KR `Tartaros.bin`，SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。`.text` VA→raw=`VA−0x400C00`；`.rdata` VA→raw=`VA−0x401A00`。
- Repository main 快照 `ba5f96dfa94d734cbded291fb8887f50426bfa77`；本地作業分支仍是使用者指定 `extra/roy1`，未合併 main。
- 既有基線 `governance/s00-iterations/S00-20261101-MEF-RECEIVE-FEASIBILITY.md`，blob `6fc6018a3dd5119cbd927fa183cb4228229d0dd7`。其中前端／共用／全域／七管理器表的陰性搜尋及 loading yield 鏈均為既有結果，本稿不把它們稱為本次新發現。
- `E54`：`kr-extra-roy/20261030-042000-chatgpt-web-roy-E54-RR0005-first-send-drain-frame-dispatch-pump-key-slots.md`，blob `d0e4153c4998132cb231c964c88255b95dda2141`。
- `E60`：`kr-extra-roy/20261030-113803-chatgpt-web-roy-E60-RR0007-KR-auth-roster-selection-scene-gated-S2C-dispatch.md`，blob `2ca02f3870d79d3217abf39b8651c43226eb77d6`。
- 衍生偽碼按精確入口讀取；整合證據目錄的 `source-manifest.json` 保存各來源 blob；`native-windows.json` 與 `native-windows.asm` 保留原 BIN 定址視窗。

### 可直接用於總結的答案

**接收層並沒有把 Server 主動推送限制在登入或換圖的某一個瞬間。已建立連線、有效接收資源、正確 framing 及 lane 2 callback 存在時，可以主動送 Client 已支援的 S2C 命令。`0023` 開啟載入畫面後，到 `0024` 關閉載入畫面之前，接收與命令分派仍可運作；部分返回 `0x100` 的命令只會使同 lane 本輪暫停，下一 tick 繼續。**

**但這條通路只證明合法命令能抵達對應 handler，不能把任意 `.mef` bytes 當成可接收、保存或執行的檔案。現有總基線已檢查的接收器沒有建立 `.mef` 內容 consumer，因此不能直接把任一窗口標成已可實作的原生 `.mef` 上傳窗口。缺的是接收／消費能力，不是官方何時送的紀錄。**

### 本次新增的直接證據：loading 阻擋更新，沒有阻擋前面的收包 pump

既有基線已確認 `0023/0024` 與 callback yield，本稿再把 loading 旗標連到主循環的實際位置。

完整 Client 記為 `C`：

1. 建構式 `0x48AB70` 的 `0x48AC79` 設 `ESI=C+8`，`0x48ACA6` 寫 `C05AA4`。原始 `.rdata` 的 `C05AD4`（`C05AA4+0x30`）是 `0x490FE0`，故該 tick 入口的第一參數是這個 `C+8` 子物件。
2. 同建構式 `0x48AC81` 設 `EAX=C+0x148`，`0x48AC87` 呼叫 `0x804380`，`0x48AC9A` 安裝 `C05AEC`；原始 `C05AEC+0` 值為 `0x4930E0`。
3. `0x490FE0` 保存第一參數到 `[ESP+0x20]`，`0x49197F` 取回，`0x491983` 加 `0x140` 得 `C+0x148`；`0x49198A` 先呼叫 `0x804740` 排出並分派接收佇列。
4. **之後**的 `0x491CA7` 才檢查 `[EDI+0xBFCC]`，即 `(C+8)+0xBFCC=C+0xBFD4`。非零就跳 `0x491D03`，略過包含當前 scene vtable `+0x18` 的更新（`0x491CD8..0x491CF2`）。
5. `0x491E75` 又檢查同一旗標，非零跳 `0x491F43`，略過其他更新，包括 `0x491ED7 → 0x561520` 的演出管理更新。
6. `0023 → 0x494860` 在 `0x49488C` 將 `C+BFD4` 設 1；`0024 → 0x494A90` 在 `0x494BE2` 將其清零。這兩筆已由基線確認，本稿重新讀原 bytes。

因此 loading 並不是「網路暫停直到收完換圖命令」。正常 tick 的安排是先收包分派，才依 loading 旗標跳過部分場景／演出更新。這是可以在 loading 期間預備或控制現有功能的靜態窗口證據。

```asm
0049197f  mov edi,[esp+0x20]           ; tick object C+8
00491983  lea ebx,[edi+0x140]         ; callback holder C+148
00491989  push ebx
0049198a  call 0x804740               ; inbound app queue pump
...
00491ca7  cmp [edi+0xbfcc],esi         ; esi=0; same C+BFD4
00491cad  jne 0x491d03
...
00491cd8  call 0x489cb0
00491cdd  mov ecx,[eax+0x5eac]        ; active scene
00491ce3  cmp ecx,esi
00491ce5  je 0x491cf4
00491ce7  mov eax,[ecx]
00491ce9  mov edx,[eax+0x18]
00491cec  call edx                    ; skipped while loading flag set
...
00491e71  mov eax,[esp+0x20]
00491e75  cmp dword ptr [eax+0xbfcc],0
00491e7c  jne 0x491f43
...
00491ed7  call 0x561520               ; part of another skipped update group
```

有界條件：必須正常進入此 tick 且前面的同步呼叫返回。`0x491597..0x4915B9` 的特殊輸入分支可呼叫數個 Client 虛擬槽後提早離開 tick；本稿沒有替該分支命名。因此不宣稱每一 tick 都無條件 pump，不保證磁碟長載入或 UI 阻塞時的牆鐘延遲。IOCP 已入列與主執行緒已消費是兩件事。

### Loading yield 的精確意思

原件 `0x4930E0`：

- `0x4930ED` 先讀 payload 開頭 WORD 命令碼。
- 長度非零，且 lane=`2`，才經 callback holder `+0xB8` 的 vtable `+4` 分派。
- handler 回傳 `0x100`，且 holder `+0xBE8C` 非零，才回傳 1。由 holder=`C+148`，`+BE8C` 正是 `C+BFD4`。
- 此比較在 handler **之後**。它不是接收前置，不代表 loading 時拒絕命令。

`0x804740` 在 callback 後先把當筆 record 歸回 pool，再於 `0x80499F/0x8049A3` 檢查 callback 結果。非零跳到 lane 尾；零則在同 lane 繼續 pop。

所以 `0023` 本身與 loading 期間的 `0012`（`4B255C` 回傳 `0x100`）可以跨 tick 分段，已處理的一筆不會再執行。`0024` 先清 loading 旗標後，僅有 `0x100` 不足以暫停同 lane。不能把 yield 說成所有命令都等待 `0024`。

### 場景切換窗口：無 scene 不是自動等候區

`0x4B7D50`：

```asm
004b7d5f  mov ecx,[esi+0x5eac]
004b7d69  mov eax,[ecx]
004b7d6b  mov edx,[eax+0x14]
004b7d6e  call edx                    ; old scene leave
...
004b7d7a  mov eax,[ecx]
004b7d7c  mov edx,[eax]
004b7d7e  push 1
004b7d80  call edx                    ; old scene destructor
004b7d82  mov dword ptr [esi+0x5eac],0
...
004b7da7  mov [esi+0x5eac],edi        ; install new scene
...
004b7db4  mov edx,[eax+0x10]
004b7dbc  call edx                    ; initialize new scene
```

同時要注意這是一個同步函式的順序；不能直接推論外部任一包必會在清零與安裝之間插入 main-thread dispatch。可證的是：若 generic handler 實際被呼叫時 scene 為空，`0x4B7EC0` 只記錄訊息並回傳 0，沒有保存待後來 scene 重播的內容。`0x804740` 隨後正常回收本 record。

因此 Server 預先送給目標場景的命令，仍可能在舊場景分派，或在 scene-null 路徑直接被消費掉；不能拿「先送進 socket 等 Client 自己好」當可靠資源排程。全域／前端覆寫命令是不同路徑，不能套用 generic scene-null gate。

### 主動推送的相容界線

通用 transport `0x806CF0 → 0x807B40 → 0x489920 → 0x8040A0` 不參照「先前某個 C2S request 的待回覆槽」再決定是否入列。`0x4930E0` 也沒有此通用對應 gate。因此，在 socket、framing、lane 及 handler 前置成立時，Client 可以接收 Server 主動送出的既有命令。

這項結論限上述共用層。個別業務 handler 可以有自己的狀態要求，某包在別的場景會被不同 handler 處理；不能從共用層無 gate 推成每個 opcode 隨時有效。

`0x4FDA30` 是依 WORD 命令索引的函式表；NULL entry 走 vtable `+0xC`，非空才呼叫已安裝 handler。前端 `0x48AAD0` 亦是明確表驅動。通用層不把 payload 自動判斷為 `.mef`、不依副檔名選解譯器，也沒有這一層的任意資源註冊。

### 封包容量與分塊不能混用

原始 `0x807B40`：

- `0x807BB5` 排除外層 payload 長度 0；`0x807BC3` 排除 `>0x1000`。
- 可選外框 marker `0x2633/0x0BBB/0x1A68/0x22D7`，但 marker 是封包格式，非檔案傳輸 opcode。
- 壓縮路徑 `0x807D06` 將輸出空間容量設為 `0x1000` 後交 `0x727190`。
- `0x807DB2..0x807DCE` 按每個 frame 長度移到下一 frame，各自成為一筆 app packet。

因此，這個 framing 本身沒有把多個 frame 自動串成一份 `.mef` 的規則。即使 Server 把一份檔案切成多個 4 KiB 以下 frame，仍要 Client 中有已知的分塊重組／保存／資源登記／啟動 consumer。這些不可以由 Server 單方面發明。單筆通用 payload 上限也不等於可用檔案內容上限，因為業務命令還有自己的 header 與欄位。

### 對『可傳遞時機』的分層矩陣

| 階段 | 通用 game transport／命令分派 | `.mef` bytes 可當檔案保存／執行？ |
|---|---|---|
| game socket 尚未建立 | 此 game TCP 路徑不可送；外部更新器是另一條路 | 本稿不涵蓋更新器 |
| socket 已接通、lane2 callback已存在 | 有效 frame 可入列並分派；沒有通用 request→reply 必須配對 gate | 仍須真實 file/blob consumer；不能由接通自動得出 |
| 舊 scene／正在切換 | 前端／全域 handler按其本身條件；generic 路徑依當時 current scene | 沒有等目標scene ready再自動 replay 的保證 |
| `0023` loading 已開、`0024` 尚未處理 | 正常 tick 仍 pump；`0x100`+loading 可使同lane跨tick；scene部分更新暫停 | 是可調度資料與本機資源工作的窗口，不是原生任意檔案 receiver |
| `0012` 本機地圖載入正在同步執行 | IOCP 可獨立入列；該 main-thread callback 返回前不保證再消費下一筆 | 不可把 TCP 已抵達視為資源已載入 |
| loading 已關、場景已啟用 | 一般命令照既有表與狀態處理；演出更新不再被上述loading gate略過 | 仍不能自行添加 `.mef` opcode |
| 閒置／移動／NPC互動／戰鬥 | transport沒有這些玩家活動的共用收包禁令，個別handler前置仍有效 | 沒有原生 `.mef` 熱載入的正向鏈 |
| 舊連線已關、新連線未完成 | 不可依舊Conn/舊scene延後交付；需以新有效接收通道與狀態為準 | 必須重新檢查內容與場景版本 |

### Server 待開發需求候選（供 S00 去重，不新增平行台帳）

1. **場景發送排程與世代綁定**：把 connection generation、目標 scene/map/case、對應可用 handler 與前置狀態納入發送條件，拒絕把 scene-null 當等候佇列。這是新 Server 自定規則；Client 依當前場景分派是已證相容介面。
2. **Loading 期間保留控制通道**：`0023/0012/0024` 不應用固定秒數猜測處理完成；遵從可證命令順序、處理時序與實際已有的回報語意。不得把 `C2S 0009` 說成資源到齊或載入完成 ACK；基線已證它在 `0005` handler分支前發送。
3. **內容就緒與場景啟用分離**：若交付內容採外部更新流程，Server 需要版本／內容準備的契約再放行進場；不能拿 `0014`（場景啟用）當 `.mef` payload carrier或內容驗證回覆。
4. **檔案／腳本 receiver未閉合時不得發明 wire**：保留為 Client 介面待逆向或另提明確配套方案；Server 可先利用既有數字ID／場景鍵／native動作通道，實作來源清楚的排程。本稿未授權修改 Client。

### 四類完成分界

- **Client 已確認**：上述 transport／dispatcher／loading yield／scene-null回收與 tick後置loading gate。
- **Client 待逆向**：未確認通用 `.mef` blob接收與消費介面，不能把有收包窗口算作檔案功能已完成。本稿未窮舉所有深層間接呼叫。
- **Server 待開發**：場景排程、內容版本條件、跨連線世代、恰當命令序列與必要傳送節流。
- **跨功能待整合**：更新器檔案交付、原生本機資源載入、腳本可觸發入口與上述接收時序由主研究者整合。
- **待遊玩驗證**：畫面時長、I/O阻塞下實際排程、到包順序、特定轉場及內容操作效果；本稿未執行遊戲，也不要求官方Server歷史封包才可提出新Server時機設計。

### 可重現核對

接收支線初始核對為 24/24 anchors、15 個 VA/raw/hex/SHA-256 視窗。本交付已整合至 `MEF-delivery-windows-20261114/native-windows.json`；使用同目錄 `verify_native_windows.py` 可與 launcher／loader 一起重驗，命令見該目錄 README。

來源與局部 bytes 核對不等於 T01 FULL-PASS、完整 `.mef` 功能完成或實機驗收。

#### 不可超出的時序結論

- `4B7D50` 是同步切換函式，IOCP 到包先排佇列。因此 **wire 恰在 current-scene 清零的幾條指令期間抵達，不代表該包當場分派，更不能推成必定丟包**。已確認的丟棄條件只限：main thread 真正進 `4B7EC0` 時 current scene 仍為空。
- 在 `0012` 本機載入、`0038` 本機模型預載或其他同步等待尚未返回時，IOCP 可以繼續排入 bytes／records；主循環是否消費下一筆，仍取決於原 handler 返回與可再執行 pump。**「loading期間可收」不等於任意送入時刻都能在本次資源讀取之前被消費**。
- 若採更新器或外部內容下載方案，內容實際可見／封裝索引刷新／下一個本機讀取點仍是獨立門檻。Server 不能只在網路佇列中插入某筆資料就假設已被資源載入器看見。

## 附錄 C. 本機資源期限、映射與快取

本筆記供 root 整合；支線研究階段沒有修改 repository、原始 Client、資源或 Server，沒有執行遊戲，也未自行 commit/push。

### 研究範圍與來源

- 原始 KR `02-Tartaros.bin`：12,472,320 bytes；SHA-256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 原始 `01-Tartaros.exe`：2,594,816 bytes；SHA-256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本支線只核 EXE 身分，未分析其更新器。
- 已先復用 `governance/s00-iterations/S00-20261101-MEF-RECEIVE-FEASIBILITY.md`、20261107 MEF native resume、E14/E15 與 T06 `PACKET-RESTORATION-CONTRACT.md`。本筆記**不把這些已知陰性結果當新發現**。
- 本次額外定向核對：資源已掛載／成員已緩衝／SceneList 已解析／場景正在執行，對新內容交付截止點的影響。
- 整合證據目錄的 `native-windows.json` 中 `loader/` 保存本支線 13 個原始 BIN 指令窗的 VA、raw offset、完整 bytes 與 SHA-256；`native-windows.asm` 保存 objdump 指令。這是作者端有界靜態核對，不是 T01 FULL-PASS。

### 可直接用於 Server 規劃的結論

1. **能新增下載／落地端時，完整內容部署最可靠的窗口是遊戲程序啟動之前。** 檔案、封裝索引與必要的場景映射要先安裝完成，再啟動原版程序，讓既有資源掛載和解析取得同一版本。這是由本機讀取生命週期推導的開發策略；不是已證遊戲 TCP 有傳檔介面。
2. **若只打算延後啟用已預先安裝的場景內容，Server 可把啟用訊號留到需要播放時。** `.seq` 的實際內容讀取是在場景 lookup 命中及 busy gate 通過後才發生；Server 不必把「檔案部署」和「內容啟用」綁在同一時間。具體 S2C handler 由 root 的主線補證。
3. **「進圖前收到」不是充分條件。** Client 可能早已掛載 STP、解析場景索引或保留成員緩衝；只讓某個新檔在磁碟上出現，不保證會被使用。
4. **同地圖再送 `0012` 不是可靠的重新讀檔命令。** 這一點已由 T06 完成；本輪沿用，不重做。相同 Map ID 走 `4DF53E → 4DFA13`，不走正常模型／碰撞載入支線。
5. **以上描述「交付截止點」和「已知內容的啟用窗口」，不代表任意原生 `.mef` bytes 已具備 parser。** 未安裝接收端時，即使 Server 選對時間，亦不能憑延長載入畫面讓遊戲接收器自動保存新檔。若採自訂格式或轉換成 `.seq`，必須標明自訂相容設計。

### A. `714770`：先讀已掛載項目，才考慮散檔

`71479B..7147AB` 以 path/mode 呼叫 `713910`；非零結果立即走 `71486F` 返回。只有 miss 才進 fallback。`7147DD` 讀 `FE4C94`；旗標為零直接 `714030`，非零時先經 `7143B0` extension 及 `714470` path-prefix 條件，允許後才 `714030`。`7142D0` 初建旗標為零，但其他設定者不在本支線窮盡範圍。

`714030` 的普通檔案分支經 `713CC0 → 89187B (_fopen)`；gzip 分支先用 `717B60` 查 `1F 8B`，再 `717BC0` 開檔。`713910` 只在 read mode 使用 package provider，從 `FBA814+4` 查掛載目錄。既有 `FBA818` MD5 provider 結論沿用，不把它誤稱下載器。

**對交付的實際影響：** 若 `Event/Sequences/X.seq` 在既有 STP 命中，同名散檔無法靠 fallback 覆蓋它；新增同名磁碟檔並不是足以證明更新生效的方式。若是原 STP 沒有的新路徑且 fallback 條件允許，磁碟檔可在下一次原生 open 前準備，但仍需要既有 consumer 確實呼叫該路徑，並需要外部落地端。

### B. 掛載索引與成員資料是兩個生命週期

`714C50` 將路徑按 `/` 或 `\\` 分段，在已掛載的 linked directory list 查名稱；命中之後才從該目錄的 provider 取成員。`714D50` 是目錄登記；開包 `715620` 另解析 STPD/STPI 和 member metadata。既有 direct-call census 的掛載入口仍是啟動／固定資源初始化；本輪未新增任何 Server packet → 索引重建入口。

新增精確的 member buffer gate：

```asm
7155F7 cmp dword ptr [ecx+08],0
7155FB mov ebx,ecx
7155FD jne 715608              ; 已載入直接返回 entry
715600 mov edi,esi
715602 call 7186A0             ; 未載入才 materialize
```

`7186A0` 取得 locks 後再次測 `entry+08`（`7186F1`）；已載入就返回。新讀取使用原有 entry 的 block selector (`[entry+00] << 10`, 再加 `0x10`，`71871E..718731`) 與 length `entry+4C`；在 `71878A/71878D` 將 `entry+0C/+08` 設為 1。`+08` 是已載入狀態，**不是 data pointer**；本機 allocation pointer 可見在 `entry+48`。

`713AC0` 是 archive handle release：在鎖內減 `entry+54`；降到零且 `entry+50 != 0` 時，`713AE9` 呼叫 `717AE0`。後者還要求 `entry+24 == 0`、`entry+08 != 0`；才清 `+08`，並按 `+0C/+48` 釋放 buffer。

**對交付的實際影響：** 有些成員可在 release 後再次從既有包讀取，不能說「所有資源整個程序內永不重讀」。但這仍不是新包／新索引自動刷新：offset、length 和 provider membership 已存在。更新包檔時若改了索引或資料位置，下一次讀取未必對應新版本；本次未驗證可由 Server 操作的 cache invalidation／remount。不能據此承諾遊戲中更新整包安全有效。

### C. SceneList 的 deadline 早於該場景腳本內容的 deadline

原始常數：`C10668 = Event/SceneList.xml`、`C1067C = SCENESET`、`C10688 = questIdx`、`C03394 = sceneIdx`、`C10694 = funcName`、`C106D0 = Event/Sequences/`、`C106E4 = .seq`。

`560170` 初始化全域場景管理器，`560344 → 5607D0` 開啟並解析 `Event/SceneList.xml`，把 `(questIdx,sceneIdx) → funcName` 存入 `FB73C8` tree。定向 `.text E8/E9 rel32` 搜尋 `5607D0`，只找到 `560344` 這一個直接 callsite；這不排除間接入口。

`0014` 共用 ready consumer 的 `4B25A0..4B25CE` 先測 `FB73B8` init bit，只有第一次才呼叫 `560170`；已初始化時不重讀 SceneList。另有許多其他 consumer 也能先初始化同一 singleton，故**不可承諾第一次 `0014` 一定是整個程序第一次讀 SceneList**。

**對交付的實際影響：** 新增／改名場景映射必須在該 singleton 首次解析前可見，不能只在送某次 scene-start 前替換 XML；最可靠的可控期限仍是啟動前。只是觸發既有映射的腳本，則可以延後到該腳本真正 open 之前。

### D. 場景內容真正被開啟前，還有 busy 與 key gate

兩個已知選擇器 `561760`、`565720` 都先檢查 `manager+28`。非零表示已有場景工作，走記錄分支後退出，沒有讀取新場景腳本。零值路徑保存兩個 key、置 `+28=1`，再查 `(questIdx,sceneIdx)`。只有命中既有 scene table 才組合 `Event/Sequences/<funcName>.seq`。

- `5617C2..5617E4`：busy gate；`561760` 另有 `FB92F1`／mode／當前場景鍵 gate，不能把所有遊戲狀態一律視為可開始。
- `565756..565778`：另一條 busy gate。
- `55D6A0` 內 `55D7C2 → 6F4A50` 以及 selector 的 `561C7D/5659D9 → 6F4A50` 為已知腳本 open 時點，沿用 E15。
- `6F4A99 → 714770(path,"rb")` 取得資源，虛擬槽 `+2C/+38` 取 length/data，`6F4AD0` 複製到 owned buffer，之後才交 Lua parser。完成解析／受保護呼叫後，`6F4BC4` 釋放資源，`6F4BC7 → 891D3D` 釋放複製的來源 buffer；該 buffer 並非整段場景常駐。磁碟更新不會自動改寫此輪已建立的 Lua 狀態，須經下一次明確的 open／解析／啟用流程。

因此 Server 的啟用排程應至少要求：Client 已裝相符內容版本、scene table 含該鍵、現有場景工作已結束、所需角色／場景資源已就緒，再發已證的啟用命令。完整 gameplay gate 與 scene 結束回報由主線分析整合；本筆記沒有自訂新的 native acknowledgement。

### 建議交付矩陣（開發設計，非已實作）

| 時點 | 可安排的工作 | 必要條件／限制 |
|---|---|---|
| 啟動遊戲前 | 完成完整包、索引、映射與版本 manifest 的交付與安裝 | 需 updater／launcher／其他明確接收端；先完成校驗再啟動，不宣稱原 launcher 提供整批原子安裝 |
| 登入後、首次使用某資源前 | 對既有 consumer 未命中的新散檔進行 staged download | 原生 fallback 必須允許、路徑必須已被 consumer 選到；不是一般保證的熱更新 |
| 進地圖前 | 驗證該 map/scene 所需內容版本；延後發觸發載入的訊號直到內容齊備 | `0012/0038` 是選擇本機內容，不會自行收檔；已掛載包／解析表仍可能早於此時 |
| 玩家已在同地圖且場景 idle | 啟用預先部署的既有場景鍵 | `manager+28=0`、key命中、mode等前置滿足；不等於同地圖換新包 |
| 腳本正在執行 | 可在新設計的下載端預取下一版，但不應承諾替換本次內容 | 這次來源已解析為 Lua 狀態，來源 buffer 於載入呼叫末釋放；須等下一次啟用／重啟／明確重載機制 |

### 界線

本輪沒有發現「只要換一個發送時機，既有遊戲 TCP 就能接收任意 `.mef`」的正向鏈。這項限制不依賴原服封包或原版 `.mef` 樣本；接收端能力與時序是兩個條件。可由 Server 自行設計的是：版本門檻、資源部署、下載完成後再啟用、逐場景的預取與重試。需要 Client 證據的是：哪個實際 consumer 會開哪個檔案／緩衝、接受什麼內容與如何啟動。
