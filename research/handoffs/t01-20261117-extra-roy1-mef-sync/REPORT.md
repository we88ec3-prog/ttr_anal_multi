# T01 — extra/roy1 同步 main：MEF 來源、主張與原件有界檢核

日期：2026-11-17（Asia/Taipei）。責任：T01 整合審核；研究來源：extra/roy1。此文件是本輪完整審核記錄，原作者的 608 份研究檔案保留原 bytes 與來源歷史。

## 1. 授權、工作範圍與完成判定

使用者明確指示「將 extra/roy1 同步到 main，並進行 T1 檢核」，並要求不任意新增 branch、Server 缺口列為 Server 開發需求。T1 按本庫正式 T01 流程解讀。

| 項目 | 固定基準／結果 |
| --- | --- |
| 開工 main | `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc` |
| 收件 extra/roy1 | `534746f194a889ebb34dda7471c2ae62d30a1dd1` |
| Git 關係 | main 是來源祖先；左右分歧 `0 / 17` |
| 原稿變更 | 608 檔，全部新增於 `kr-extra-roy/`；39,030,338 bytes |
| 本輪寫入範圍 | 本 T01 handoff、正式 intake／claims 與 T01 README 導讀 |
| Git 策略 | 保留來源完整歷史，以 fast-forward 更新 main；不 force push、不另開遠端 branch |
| T01 結果 | R0 接收完成；R1 限定主張登錄；R2 重要反證與原件鏈有界複驗 |
| R3／正式狀態 | 不新增 FULL-PASS／NATIVE_VERIFIED，不更動 RR、S00、Task owner 或可玩狀態 |

目標是讓主線可追溯地使用此次 MEF 研究。依 `governance/t01-integration-workflow.md`，一般整合不以全部歷史全文達到 FULL-PASS 為前提；每個來源的證據、限制與已知反證仍須保留。

本輪先讀上傳 `02-PROJECT-SHARED-INSTRUCTIONS.md`、main 的 AGENTS、T01 README／task.json、派工規則／T01 inbox／唯一 RR 台帳、FULL-PASS 政策與共用驗證索引。T01 inbox 的六個既有 RR 並非本批新 MEF 專用請求；未代替其 owner 認領或結案。

## 2. 原件身份、PE 映射與全件 R0

`r0-audit.json` 逐項記錄實際原件長度、SHA256、PE section 與 608 份來源身份。

| 原件 | 本輪實測 SHA256 |
| --- | --- |
| KR Tartaros.bin | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| Tartaros.exe | `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f` |
| Event.stp | `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` |
| Table.stp | `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` |
| BoundMap.stp | `07d8f3a20aa4a396312c60927431a53a89dce6370ef8bb8192bd8d8eca1dd6b8` |

BIN 為 PE32/i386、ImageBase `0x400000`。`.text` VA `0x401000` 對 raw `0x400`；`.rdata` VA `0xBD2000` 對 raw `0x7D0600`。本輪以 section 的 raw-backed 範圍映射 VA，沒有跨 section 或 KR／TC 混用固定偏移。EXE 僅核身份，不由其 hash 推導 BIN 語意。

全件 R0 結果：

- **608/608** 工作樹內容與來源 commit 的 Git blob 完全吻合；每檔另計 SHA256 與長度。
- **341** 份 JSON 經 strict parser，拒絕重複鍵與非標準數值；**80** 份 Python 經 AST 語法檢查。
- 其餘包括 131 Markdown、36 ASM、5 TXT、2 TSV、1 patch 與12分片；原件及完整資源未作為新增檔案發布。
- 12 分片串成研究 tar.xz，實際為 **24 個 regular members**；其中 `packed/previous-native.json` 可還原成兩份研究證據，因此作者 restore 工具的 **25 個還原原稿**與24個封裝成員是不同計數。
- 不解壓到原件目錄、不執行包內 Client／Lua／資源。本輪獨立 R0 工具只讀資料並輸出 JSON。

完整來源清單與 SRC 關係在 [source-provenance.json](source-provenance.json)；不以摘要替換原稿。

## 3. 研究工具實際重跑及兩個重現條件

17 個早期 MEF package 已按其指定依賴重跑；其中 runtime／world／content 三包由 end-to-end 的 `--recheck-prior` 呼叫並留下各自結果。one-shot-followup 封裝中的 study 與 callbacks 分別還原驗證。另重跑 comprehensive 與 P0 兩包，共覆蓋本次19個目錄包；11份外置主稿在R0來源清單中獨立保留。

### 3.1 原載體檔名是部分舊收據的比較欄位

首次以附件名稱 `06-Event.stp` 等傳給部分舊工具，8組執行因儲存 metadata 的 `carrier` 欄位與原收據 `Event.stp` 不同而失敗。檢查 decoded qbase SHA 與 bytes 均相同；使用 scratch 中指向同一原件的 `Event.stp`、`Table.stp`、`BoundMap.stp`、`Tartaros.bin` 唯讀同內容路徑後，相關工具通過。

這是輸入命名的精確重現條件，沒有改 parser、放寬 hash 或改寫原資源。初跑失敗、診斷與成功收據全部保留於 [history-review](history-review/report.md)，不只保留綠燈結果。

### 3.2 parser pin 已找到相符的封裝版本

comprehensive 原報告記錄的歷史失敗，是當次所用另一個 Git parser 與舊 verifier pin 不一致。本輪從 one-shot-followup 的12分片恢復出被 pin 的 parser，原稿身份驗證後再執行 A1／full-surface／feature 等工具，已能成功重現。

因此正確結論是「精確封裝 parser 可用；前次傳入版本失配的紀錄保留」，不能把舊紀錄擴大為整個舊研究包永遠不可重現，也不能據此撤回後來已成立的語意勘誤。

### 3.3 最新兩包

- P0 根驗證器帶 `--run-evidence`，實際跑 ABI、資源、生命期與現行 Server 資料對照四組；121 binding、兩個原 SEQ 的108次 body call、22 owner與3策略之跨題檢查通過。
- comprehensive 根機械檢查、六個原件 verifier 與14例 ABI fixture 通過。會寫 fixture 的工具在暫存副本運行，原始研究收據未覆寫。
- 新收據與作者已保存的有界結果比對；資源 `ready=false`、官方 grammar 未證、無 Server／Client／Lua 執行及無遊玩驗收的旗標持續保留。

這些結果只表示特定驗證器在已審讀的範圍可重現。尤其舊合成模型即使再次 PASS，其假設仍可能已被原 BIN 反證。

## 4. R1 主張採用與 R2 高風險核對

正式 SRC／CLM 僅追加，不改802筆舊SRC及189筆舊CLM。本次新增 **SRC-0803～SRC-1410 共608筆**，其中600筆為REGISTERED、8份主報告為CLAIMS_EXTRACTED；新增 **CLM-MEF-0001～0024 共24條**，21條PARTIAL、2條UNKNOWN、1條INFERRED。來源狀態與原生可信度是不同軸；未經全部主張的正式 R3 檢核，不標 NATIVE_VERIFIED。

| 核對項 | 本輪可採用的限定結論 | 不可擴張的範圍 |
| --- | --- | --- |
| 121正常binding與ABI | 以新版全名稱參數／marshaller／producer表及P0採用規則為入口；stub及無count producer名稱仍明列 | 121名稱不等於121功能已實作，return count不是業務成功ACK |
| `Q.FlyingObject` 替換 | `0x56496A → 0x564A60` 先取消Q追蹤的舊圖，再配置新圖；後續manager負責實體回收 | 舊「僅覆寫handle、不取消舊圖」模型不再採用；取消不是同步釋放，也不是全共享owner清掃 |
| 原零fade-out | 所選phase4先判remaining，零值跳過除法；phase0、alive清零與manager回收分階段 | 不外推任意負值／任意路徑安全；不保證固定wall-clock完成 |
| `Q.EndSepia()` 原零參數 | 所選VM CALL／marshaller路徑可追到native integer0；原callee frame與tag分支必須成立 | 不概括所有缺參數都等於nil或0；新內容作者政策仍要求顯式參數 |
| 正常Q Create | 實際Q caller走immediate1；Doll引用／apply與一般deferred producer分開 | 不把所有Create都說成留下pending state2；不推render與全queue已就緒 |
| 執行與收尾 | 22類owner、3策略與條件式cleanup偏序可供內容工具及排程設計使用 | End、qco removal、003F、level signal或計時都不是所有owner共同完成證明 |
| 原場景與依賴 | Q119/3、Q2440/5的108次呼叫及已達資料邊可重算；selector與typed ID保持分域 | 不把Q119/3當119/4或119/5；候選basename不是已被原resolver選中 |
| 0048互動點更新 | 所選handler送category／key／status至既有集合的第一個匹配點，miss不建立新點 | 不是upsert、座標搬移、actor生成或交易／任務完成 |
| 互動點latch | disable早退不清`point+104`；落空／離開分支才清，mode分支另有input gate差異 | disable／enable不保證新one-shot邊緣，亦非已證Lua getter |
| 003F反例 | Start既看過支線可發003F後略過正常接納；normal End也在coroutine移除前送出 | 收到003F不足以證明新腳本已執行、全清理或業務成功 |
| 00EB等待解除 | 所選handler沿`4B61E5 → 562250`移除指定等待UI並清mask bit2 | 不能外推全部input owner／Q／coroutine已結束；沒有新run token |

精確指令窗口、CFG、資料流、來源blob及各項審核決議見 [native-review/report.md](native-review/report.md)；歷史入口／scheduler／場景／封包邊界見 [history-review/report.md](history-review/report.md)。以上為有界審核，並非19包逐句FULL-PASS。

既有共用 `CK-CLIENT-SCRIPT-REGISTRATION-ZERO-STUB-01`／`CLM-CLIENT-0063` 仍僅證原stub的精確範圍，不能用它為新121名稱全表背書。既有場景CLM的PARTIAL範圍保留；本批不自動撤銷舊FAILED或結束舊退回。

## 5. Server 開發需求與原件缺口分開

以下是沿既有REQ交S00去重採用的開發輸入，不另立一份競爭台帳，不虛稱S00已接受或Server已開發。

| 既有需求工作線 | 玩家情境／Server要完成的工作 | 已有Client接口與保留限制 |
| --- | --- | --- |
| REQ-0019／REQ-0021 | 主線演出內容建置：固定Client與ABI版本、檢查typed參照、依賴與owner前後置條件 | 原binding、helper轉換、selector與原結束回報；目前外部scenario schema無任意Lua／PlayScene欄位，擴充需有版本 |
| REQ-0017 | 演出結束及跨場排程：分離發起、原生結束回報、控制回復與業務提交 | 003F僅依既有有限語意；00EB僅解除適用等待，不新增cleanup ACK |
| REQ-0018 | 廣場NPC後續劇情互動及控制恢復 | Q演出actor、world EntityId與NPC身份分域；這項既有需求本身不涵蓋全部商店／強化業務 |
| REQ-0021後續服務候選，由S00去重細化 | 商店服務可用性、販賣／強化、資產變更與保存等Server開發需求 | 沿既有後續銀行／裝備／商店／掉落安排提出增量；不表示強化規格已受理，也不以演出函式替代未證服務協定 |
| REQ-0016 | 普通戰鬥、權威事件、命中／死亡／進度與結果結算 | query可觀察的狀態不等於Server決策；本批不要求普通戰鬥改由MEF完全取代 |
| REQ-0010及相關scene工作線 | 教學、場景context與actor／控制恢復整合 | 已知教學trigger和qbase bridge可復用；普通world不中斷輸入的首次入口B仍未閉合 |

### 四種未完成事項

1. **Client待逆向**：官方MEF格式／grammar、普通場景首次入口B、world結果到Lua的新出口及尚未閉合的原生路徑。這些不能推給Server猜協定。
2. **原始資源待補與選取待確認**：兩個選定場景有13個模型descriptor缺件；仍缺實際CHA_ABF／MAP_FLD entry、Master mount、Items.ipk及所選視聽／幾何payload。缺descriptor的遞迴後代不可填造；exact runtime selection及完整依賴維持blocked。
3. **Server待開發／跨功能待整合**：內容版本審查、owner與run排程、權威任務／戰鬥／服務／獎勵／保存、與現有scenario schema及原封包adapter串接。官方Server內部演算法未知本身不是Client靜態研究未完成的理由。
4. **待遊玩驗證**：完整畫面聲音、輸入恢復、場景返回與實際業務結果；本輪沒有啟動原Client、Lua或Server。

資源缺件不應阻擋不依賴該內容的普通戰鬥、權威旗標、任務／NPC服務或保存開發；亦不能為趕開發把缺資源狀態改成ready。

## 6. 現行退回、RR與原稿保留

按使用者指定優先處理此次MEF整合；以下其他任務舊案未被本批修復，保留其原狀與責任：

- T03-006-LAYOUT NEEDS_FIX。
- T10-116-ROW5／062／063／007／026 NEEDS_FIX；055／056 NEEDS_QUALIFICATION。
- T08-153／155／157／183／187與LEGACY-MAPPING在作者側有READY_FOR_REVIEW資料，但歷史審核台帳狀態尚須各自複驗，不能因本次merge自動結案。
- T16既有117退回的RESOLVED歷史保留。本輪不改其他Task README、task.json、owner、catalog、native_complete。

正式RR台帳、inbox生成檔與S00接受狀態一律原樣保留。來源中的NOT_NATIVE_MEF設計與SYN模型不登為官方規則；來源中的歷史驗證收據不因本輪新成功覆寫。

## 7. 重現與發布

來源／格式檢查：

```sh
python -B research/handoffs/t01-20261117-extra-roy1-mef-sync/audit_sources.py \
  --repo /absolute/path/ttr_anal_multi \
  --sources /absolute/path/project_sources
python -B governance/validate_s00.py
python -B research/dispatch/dispatch.py check
```

各研究包的完整命令、時間、退出碼、stdout／stderr及收據hash另存於本批兩份子審核。補充Base.stp與W1/W2/W3 ZIP僅作本機唯讀來源，未加入Git。

正式登錄後已執行來源R0與五項結構gate：`validate_s00`、`dispatch check`、`phase_b_worklist --check`、`phase_b_review_preflight --check`、`check_server_requirements --check`，全部exit0；[命令收據](structural-checks.json)保留時間及輸出摘要。另獨立確認802舊SRC、189舊CLM完全相同，608來源未改、兩組審核交付manifest逐檔吻合，保護範圍無變更；[整合結果](review-result.json)保留精確計數及未提升旗標。

提交前比對保護範圍、608來源及正式台帳增量；推送前重新取得遠端main與extra/roy1，要求原main祖先及已檢核來源歷史均在結果中。推送後以遠端branch／commit與讀回內容核對。真實發布commit以包含本文件的Git提交為準，不在提交前杜撰SHA。
