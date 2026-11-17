# A1 v1：普通 Mission／Scenario 的一次既有互動點開啟

**文件性質：相容內容的最小可實作規格（NOT_NATIVE_MEF）。** 供 Server／內容工具開發；不是官方 MEF grammar、S00 已發布 STABLE 規格、已部署資源或已通過遊玩驗收。

工作分支 `extra/roy1`；研究父提交 `ce1d4f829f43db6793065499e3b0abd013df3451`；沿用已包含的 main `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。只在自有研究目錄新增文件和離線契約檢查，未改 Client／Server／原件／RR／owner。本文的「必須」是本提案的相容實作要求，不聲稱是官方 Server 內部規則。

## 1. 本版只完成什麼

同一普通 Mission 或 Scenario 實例內，在 Server 已確認適合短暫插播的正常時點，把**一個已安裝、唯一且原狀態為 0 的互動點設為 1**。採 `0047` 啟動一份新相容 sequence，正式 coroutine 做一次 setter 後 End；以 quest0 的既有回報／解除等待流程收尾。

本版是 `set enabled=1`，不是「讀目前狀態後反轉」。不提供任意腳本執行、換圖、生怪、鏡頭、對白、特效編排、多步驟排程、同次多人同步、任意重試、無干擾戰鬥 B 或全 Server 替代。category 限 **0（出口）、2（ShopNo）、3（NPC）**；每個已綁定發布品只選其中一個。category0 的原生開門效果必須已有合法資源；2／3 的服務資料沿原流程，不由本版建立。

**A 允許的干擾：**Q busy 可能抑制控制列，Start 的 F4358 仍有已證普通 UI／相機暫態副作用；End 之後尚有等待解除與殘留 busy 的正常消費。不得宣稱「只停一幀」「End 返回即全恢復」或保存既有自由相機狀態。[S1 §§6–8]

**最小正常環境：**先在單一受控玩家、Server 判定無需立即移動／攻擊的同場景安全時點整合，例如權威階段完成後、下一波尚未發布。這是 Server 排程條件，不是新無敵／暫停封包，也不宣稱 Client 所有模擬停止。

## 2. 固定選擇，避免實作者繼續猜

| 項目 | A1 v1 決策 | 分級／理由 |
|---|---|---|
| 場景入口 | S2C application `0047` | 已證普通前端→Quest manager→Q，不換成 Tutorial |
| sequence 雙鍵 | `questIdx=0, sceneIdx=32760` | **新相容設計候選鍵**；本輪核原 SceneList 無此組合，仍須查實際合併索引 |
| funcName | `compat_point_once_a_v1` | 新名稱，原 SceneList／Event 索引未占用；不是官方保留區 |
| 正式資源路徑 | `Event/Sequences/compat_point_once_a_v1.seq` | 由原路徑形成規則產生，不傳入網路檔名 |
| 新表列 | `SCENE questIdx="0" sceneIdx="32760" funcName="compat_point_once_a_v1" endBehavior="0"` | 規格中的新增列設計，未實際寫入原件 |
| 結束策略 | quest0 正常 End→003F→Server安排00EB | 免去非零 quest 的確認旗標前提；003F**不證明**setter成功 |
| 重複使用 | 一個已證新 Client 啟動週期最多發一次此鍵 | 排除 seen-skip；斷線重連不視為新啟動週期 |
| 目標點 | 取本次已發布 `0027` 快照中的唯一 `(category,key)` | 不猜現場 point key、XY 或半徑；在**內容建置時**綁定為 literal |
| 狀態改動 | `expected_before=0, desired=1` | 明確、單項、可驗證；舊值已為1不算本次替代成功 |
| 其他資料／操作 | 不變 | 不重建0027、不送同項0048、不換場、不重綁controller、不改qbase／Register |

核對原件結果：SceneList **1,687 列**，quest0 共324列、最大原 sceneIdx 323；候選雙鍵、funcName、路徑命中均0。這不證明其他發布者沒有額外 overlay；**合併後索引的衝突檢查仍為發布門檻**。原資料已有重複列，本版只檢查新增候選的唯一性，不能順手全表去重／重排／改其他列。[E1]

## 3. 開發輸入契約：把缺資料改成具體接口，不猜值

Server／內容建置器接收一份 `Binding`；其完整欄位和拒絕規則由 `contract.py::validate_binding` 定義。這是自有 JSON 配置，不是 Client 會自行解析的 MEF 格式。

| 輸入 | 約束及來源 |
|---|---|
| `profile_id` | 固定 `A1-v1` |
| `field_type`、`field_instance` | Mission 或 Scenario；非空的 Server 實例識別。不得以 MapID 當實例識別 |
| `client_epoch` | 經受控啟動／外部發行流程確認的 Client 程序啟動週期。原wire沒有它；無法確認新程序時不得重設已使用帳 |
| `connection_id`、`snapshot_generation` | Server 內部連線與點集合版本，不附加到原封包 |
| `snapshot_sha256`、`snapshot_evidence` | 本場景最近一次完整0027 application的SHA與來源紀錄；**已送出不自動等於Client已安裝** |
| `point_key`、`point_category` | 精確整數；key 0..65535，category僅0/2/3；必須在該快照出現且只出現一次 |
| `expected_before`、`desired` | 固定0→1；快照的目標狀態須是0；本次期間不得另有寫入者 |
| `release_id`、`sequence_sha256`、`scene_list_sha256` | 實際新發布品的版本、sequence和有效完整索引SHA，不以草稿hash代替 |
| `release_evidence` | 實際資源選取／Client啟動前已載入新索引的證據紀錄。不是單憑磁碟檔名存在 |
| `timeout_ms` | 必須顯式配置的Server watchdog政策，正整數。沒有原生固定完成時間；到期**不得重送0047** |

**兩階段綁定：**內容建置階段先從有來源的預定點模板或已驗證快照，固定發布品的 `(category,key,desired)`；Client啟動前完成發布。RunBinding才填當次連線／field實例／generation／完整快照，並檢查 `release_point_key/release_point_category` 與當次point相等。不能等進場後才決定新target，再用舊鍵假裝Client載到了新sequence。

`0027`輸入形狀是2-byte opcode後N×18-byte rows；target row布局 `[u16 key, i8 category, u8 enabled, f32 x, f32 y, f32 radius, u8 tail0, u8 tail1]`。只核對目標行、保留完整快照byte identity；目標XY／radius須為有限數值且radius>0，合法場景／可達位置仍依來源，不由算術檢查證明。[S1 §§3–5]

**重要限制：0047 只有 scene 雙鍵，沒有 point 參數。** 目標category/key不能臨時塞進0047。內容建置器先從Binding固定目標常數，再發布配套sequence及完整SceneList；Server在啟動時核對當前快照正好符合這個發布品。不同目標／版本不能在同一Client程序中熱換同一鍵。A1-v1不發明通用參數通道。

尚未有本次實際Session／快照／已發布sequence，所以本包 `profile.json` 的部署狀態為 `UNBOUND_NOT_DEPLOYABLE`。**這是明確的呼叫者輸入與發布工作，不是未解Client欄位**；完整規格可據此開發。不得把SYN測試的key、XY、hash貼進實機當原生資料。

## 4. Client相容內容的精確產生規則

保留現有原始資源，只有取得資源新增／部署授權後才在工作副本建置。不得patch EXE/BIN、改qbase、Rebind或以記憶體寫入達標。本輪只有以下文件骨架，**不提供或部署遊戲SEQ/Lua檔**。[G2]

```lua
-- SPECIFICATION TEMPLATE; NOT A DEPLOYED GAME RESOURCE
local formal_after_register = false
Register(function()
    if not formal_after_register then
        return -- prepass：空依賴、無Tutorial呼叫、無等待
    end
    Tutorial.SetCheckPointStatus(BOUND_POINT_KEY, BOUND_CATEGORY, 1)
    Q.EndCutScene()
    return -- End之後不再做任何操作
end)
formal_after_register = true
```

產生的資源payload選用**ASCII Lua 5.1文字、LF換行、無BOM**，使用原本強制的`.seq`路徑；不需要另造MEF容器或使用其他版本的Lua bytecode編譯器。已證parser對非ESC首byte走文字parser，外層仍必須由已確認資源resolver取得bytes。[S5]

建置器把`BOUND_*`替換為驗證過的十進位整數literal，沒有在執行時搜尋／猜點。所有bindings與原版Register保持未改寫；只有本段一個qco工作，無重入。

prepass的Register同步執行callback，此時local=false；正式Register只登記工作，chunk正常返回後local=true；真正callback由後續Q pump執行。**不能把setter／End移到chunk頂層**：Start尾段會在loader返回後再把point呈現gate設0。不得用全域DoFile是否存在判階段，也不需要額外.mef模組、模型／動畫／相機依賴。[S1 §6；S3]

空宣告仍經原資源工作與等待，沒有固定載入時間保證。內容不呼Phase1／RevPhase1、Start/Stop、EnableInput、LoadMap、camera、DeleteAll或其他會取得共享資源的helper。setter沒有可靠成功值；不得寫`if SetCheckPointStatus(...) then success`。

## 5. 發布門檻與rollback

**P0：原件不變。** BIN必須為本規格pin的KR SHA。保留原始STP／索引。新內容、相容schema與版本有獨立紀錄，不稱官方MEF。

**P1：有效索引。** 從實際會被Client選中的SceneList建立工作副本；原有每一列、順序和屬性保留，只新增上述一列。重複鍵、同名資源衝突、任何其他列變更都拒絕。不能直接用本包新增片段取代整份SceneList。檔名相符不代表resolver選到它。

**P2：綁定與不可變性。** release_id、完整索引SHA、實際sequence SHA、category/key、目標場景上下文綁成同一發布品。禁止以同鍵熱換不同內容／point。

**P3：載入時機。** SceneList在既有初始化時載入，0047不刷新它；首次驗收採受控新Client啟動前發布。發布方案必須列出實際resource resolver／archive優先序驗證，不預設loose file一定覆蓋STP。

**P4：起動前置。** 同一正常field/page/controller、無pending換場；目標point確已安裝且唯一；Q idle／normal、qco空；point呈現gate初始1；無其他input mask／modal capture；保持該場景直到解除完成。Server可證部分依log／序列化取得；無原wire query的本地項目，列受控流程前提及後續核驗，不偽造Client ready ACK。

**P5：部署授權與試跑分開。** 使用者本輪授權規格與Git，不等於允許改Client資源或啟動遊戲。執行／新增資源依專案政策另取得授權。這不阻擋編寫Server處理器與離線建置工具。

rollback在**下次啟動前**恢復工作副本索引／新內容選路，保留原件。進行中timeout或斷線不是安全熱rollback點；不得盲送另一個Q或重建0027掩蓋結果。必要操作恢復另按授權處理。

## 6. Application封包契約（不是完整TCP frame）

| 方向 | Application | 長度 | A1-v1定義 |
|---|---|---:|---|
| S→C | `47 00 00 00 F8 7F` | 6 | `u16 0047, i16 quest=0, i16 scene=32760` |
| C→S | `3F 00 00 00 F8 7F 01 00` | 8 | 原builder回兩鍵low16和常數1；最後1**不是setter成功碼** |
| S→C | `EB 00` | 2 | 只解除既有等待dialog／mask2，不停止Q、不回專用ACK |

003F原builder `4A39A0..4A39EC` 本輪重核，排送長度是8，不是6。[E2；S2 §6] 0047解碼是signed16，因此候選32760可精確表示。這些為規格合成byte vectors，未發送。底層lane／framing／encryption與既有連線實作共用，不能在application塞run ID、檔名、point或新的成功值。

`0048`為對照：`u16 0048,u16 key,u8 category,u8 status`，此能力能直接完成同一setter，但**A試驗流程不得送出目標同項0048**。也不得中途重送0027，否則不能證明由腳本改了原來那個point。

## 7. Server最小狀態機與精確責任

推薦新增獨立的有限內容請求服務，而不是修改每個Quest的if；其工作資料至少有`run_id、connection_id、client_epoch、field_instance、snapshot_generation、release_id、scene pair、point ref、desired、deadline、state`。這些是**Server內部欄位**，不冒充原wire。

| 狀態／事件 | 動作 | 下一狀態／可主張結果 |
|---|---|---|
| `UNBOUND` | 缺Binding或發布證據時拒絕enqueue | 保持未就緒，不猜預設point |
| `PREPARED` | 通關／安全時點／發布／snapshot／同玩家排他條件成立 | 可準備單次發送；不代表Client已執行 |
| dispatch | 在可靠發送佇列之前，持久記錄該`client_epoch+scene pair`已消耗及唯一pending run，再只排一個0047 | `SENT`；任何enqueue結果不確定都不重送 |
| `SENT`收到合法003F | 只接受同連線、同epoch、同field實例、同generation、兩鍵匹配、最後WORD=1且長度8的回報 | `END_REPORTED`；**不設operation_verified** |
| `END_REPORTED` | 在同場景連線排一次00EB；以正常Client主循環的End／接收順序為前提，不靠任意sleep競速 | `RELEASE_ENQUEUED_UNVERIFIED` |
| 重複／非本次003F | 記log；不再排00EB、不發獎、不釋放別的run | 原狀態 |
| field/generation/connection變化、timeout或送出結果未知 | 封存為`UNCERTAIN`；不重送0047，不用缺回報猜「沒執行」 | 等獨立授權的恢復流程 |
| Client畫面／狀態驗收證據完整 | 由獨立驗收紀錄標`GAMEPLAY_VERIFIED` | 不是native003F自動觸發的Server狀態 |

`contract.py::Exchange`是這套政策的**純記憶體參考模型**，不連網、不寫DB、不修改Server。正式開發還須實作持久已用鍵帳、排他、可靠outbox／send outcome處理及事件審計。斷線／Server重啟後仍不得把同一Client程序當新epoch；無法證明新程序就維持禁重用。

**為何003F仍可用於解鎖但不能當成功？** seen-skip及查無SceneList的結束支線也可能回003F；一般End的送報亦早於全部清理。本版透過新鍵／新程序／有效索引降低正常路徑歧義，卻沒有創造新的操作ACK。匹配003F足以在受控同場景中觸發解除等待策略，仍不足以確定point存在、setter命中、UI恢復或任務成功。[S1 §7；S2 §§6–7]

**00EB時序：**正常主循環先pump收到的application，之後才Q更新；003F經原sender排送，End繼續建立等待鎖並完成尾段。匹配回報後返回的00EB在後續合格接收pump處理；本契約排除重入、外部換場及不完整End。不要在0047後立刻預送00EB，否則End可能重新置鎖。無00EB專用ACK，所以`RELEASE_ENQUEUED`不能叫`INPUT_RESTORED`。

**業務狀態與畫面狀態分離：**Server先按權威進度決定門／服務可開，保存desired state。003F不扣款、不發獎、不完成任務。後續實際互動／轉場仍驗證Server條件；重進場景按權威資料重建快照。腳本本地變更不自動保存到DB。

## 8. 正常路徑的Client時間線及退出後置條件

```
原場景、原point、Q idle
→ 0047接納、prepass、正式chunk只Register
→ Start尾段561CCE關point animate/draw gate
→ 後續Q tick先在5615C4寫controller+58=1
→ 唯一callback：同point setter(enabled=1)
→ Q.EndCutScene：active=0、point gate=1、條件式003F／wait、清qco、還原既有保存項
→ callback立即return
→ Server匹配003F後排00EB
→ 00EB移除F4322 wait、清mask0x2
→ 合格普通controller更新消費並清殘留busy
```

F4358可晚於End才被同一ordinary page消費；它仍可能改控制器／相機暫態、關閉FreeCam。故驗收必須觀察正常輸入實際恢復，不能只看Q inactive。[S1 §7]

退出後置條件：原field/page/controller/point身分未替換；target enabled=1且其他點未被本內容修改；Q inactive、該段qco已清；point呈現gate=1；適用wait已解除；busy經合格更新清除；沒有由本段留下的新modal／mask阻塞。沒有保證下一畫面幀達成，也沒有保證外部其他input owner一併被清掉。

## 9. 最小工作包與驗收（不等待B）

| 工作包 | 可直接開始實作的產出 | 完成條件 |
|---|---|---|
| A1-CONTENT | Binding檢查、原SceneList單列追加的工作副本建置、受控literal substitution、release manifest | 雙VM骨架不變、目標固定、hash與原資源選路一致；部署另授權 |
| A1-SERVER | 單次請求服務、003F精確parser、00EB序列化、同場景排他／使用鍵帳／審計 | 上述狀態機；無重送、無假ACK、無新wire欄位 |
| A1-DATA | 有來源的已安裝point快照、通關／安全時點、合法NPC／Shop／出口依賴 | 不猜ID座標、不改世界身分、不把UI等同業務授權 |
| A1-OBSERVE | 正常流程證據紀錄、封包比對、Client實際效果／控制恢復 | 所有後置條件有證據；不可觀察項明列未驗 |

第一條驗收只跑正常流程，依專案排程另取得實機授權：

1. 記錄KR BIN、release_id、effective SceneList／sequence hashes、新Client epoch與普通field/page。
2. 記錄原完整0027、唯一target、原enabled=0及同集合generation；確認既有資源／互動可用。
3. Server依已決定的業務條件只發一次指定0047；從此到完成，target無0048、集合無0027、無轉場／其他Q。
4. 記錄正確target變為1，其他point保持、沒有靠Server fallback造成效果。native狀態若未獲准附加讀取，不假造記憶體trace；先記可見效果／原互動與限制。
5. 核對8-byte003F、其後2-byte00EB、等待畫面解除、移動／攻擊重新可操作、point繪製仍正常、同場景身分未換。
6. 另檢查Server權威desired state與後續重新入場快照；該項不依003F發獎。

單一category2/3沒有招牌變化保證，應以其原本互動是否開放驗收；category0可觀察原出口表現。**原生狀態完整觀察不足時只能標部分遊玩驗收，不把封包與畫面替代所有內部後置條件。** 重送、斷線、重疊、故障及併發案例只列後續實機計畫；本包測試僅是離線格式與政策算術，不是啟動Server做這些測試。

## 10. 已完成、剩餘與來源

本版已把入口、phase、目標綁定、原封包形狀、正常退出、歧義／timeout政策、發布門檻與驗收定成可實作接口；**設計規格完成不等於已綁定發布品**。

- **Server待開發：**本章工作包中的請求／發布／序列化／outbox／權威判定、服務與持久化。
- **跨功能待整合：**實際Binding、資源選路證據、合法工作副本及輸入／退出的正常流程。缺本次point key不是要求重做已證setter。
- **Client待逆向：**官方MEF格式／首次loader、B無操控干擾入口保持原狀；**不阻擋A1的已定接口開發**。A1未新增必要的未知Client wire欄位。
- **待遊玩驗證：**所有實際部署、載入、畫面、時序及雙端一致性，未執行。

S1：父提交研究封裝中的 `MEF-one-shot-study-20261116/REPORT.md`（SHA256 `874e3fffdd2f727f47042ae475dd955f2248b8ff5b54039221446b642937ac7d`），相應原件包已重跑PASS。其解包文件身分比對公開publication-manifest，非從對話重寫。

S2：[既有wire契約](../MEF-world-integration-20261115/wire/report.md)，blob `53349ee42ada1d9ac3e99fd6bf3c4943b9b715e4`，特別§§6–7。

S3：[lexical phase與入口契約](../MEF-end-to-end-20261116/entry/report.md)，同父提交；本文復用S1已固定的引證，不重做相關GC／VM研究。

S4：[上一輪A/B分流及研究封裝](../MEF-one-shot-followup-20261116/README.md)。B候選與阻塞保存，不用本次規格結案B。

S5：[既有記憶體parser與文字／binary契約](../MEF-parser-executor-storage-20261114/parser.md) §§1、3，同研究父提交；本次僅選定已證ASCII文字分支，不重新分析grammar。

G1：main `AGENTS.md`，blob `1c6f71dae694c76fe1efb50413583c743d0f84f7`；G2：`shared/CLIENT-MODIFICATION-POLICY.md`，blob `e951438a2bdb6a0889ef012508ab8b530c33913c`。新增資源／遊戲執行仍需對應授權。

E1／E2：[本輪原件與候選鍵核對](evidence.json)；[實際驗證結果](verification-result.json)。驗證只證有限bytes、資料讀取與規格自洽，不提升T01 FULL-PASS、S00 STABLE或遊玩狀態。
