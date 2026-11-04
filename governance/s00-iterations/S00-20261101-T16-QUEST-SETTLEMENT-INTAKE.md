# S00：T16任務介面收件與結算開發責任

本輪補入既有REQ-0017，不建立重複REQ。它包含教學合法任務狀態、出口及同登入廣場控制；
REQ-0016戰鬥優先不變。這是對現存來源的定向收件／規劃，不是新遊戲觀察、APPROVED契約
或新增CODE_ANALYSIS discovery；沒有尚未登記的CLM便不虛填該通道。

## 精確來源與必要勘誤

本機公庫分支已保存、以git blob讀取的兩份T16原稿：

- `kr-temp-roy/20261030-034517-chatgpt-web-roy-T16-117-KR-Quest14-study5-Quest16-type2-unlock-UI-C2S-S2C.md`
  blob `388b9100362ed43ec65ba1f7504f73518dce5d44`。
- `kr-temp-roy/20261031-165535-chatgpt-web-roy-T16-135-KR-Quest14-16-15-Pindos-player-flow-Server-contract-evidence-matrix.md`
  blob `b0a15aaabe1fc2d86225c5d5466b6ab78564c29c`。

這些是有限研究來源，不由S00整份升FULL-PASS。T16-117把Quest16 type2讀端從誤用type1的
500950改到500A00／5008B0／500A80；T16-135又限定不能將mode1的36發送推廣到任何mode2/3按鈕。
相同功能有後續勘誤，不能只取較早摘要。原稿中的Server隔離／交易建議也不是使用者原話或官服事實。

原始KR目標SHA `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
本輪重讀保存Ghidra並核對其Evidence/pseudocode hash的有限入口：

| 函式 | 偽碼SHA256 | 限定用途 |
| --- | --- | --- |
| 503400 | 5e94a5696166aad0d5dd7105113cf797609ffb42f186e30246075a149a3cda9f | 74增量key經44B4E0後重算候選 |
| 44B4E0 | 5604e590775cb3f240601a9249828c011845708cec0a53fc0cc2a5ce2d11215d | WORD向量追加；非Server完成裁決 |
| 502B40 | ee796cb749ac965ac2d595d65089d81d120d76be3ef9987249add8bb2473f68f | 46/substate0有排除清理、record+8 gate、key追加與F438C事件；非DB給獎 |
| 636E10 | 8d38f634b7b518e48f447dd95a26009d56a02e81564275ac6fd60afad41d34e0 | 有selected record／action／sender gate的36/QID組包，未因此證所有UI mode路由 |

另唯讀核對已釘Event/TutorialMain.lua的Main末端：呼叫Part2後RETURN；Part2尾段開NPC10016、
等待1000/14，再PostUIMessage_TutoMsg(TUTORIAL_STARTSCENARIO,0)及RETURN。這是該精確腳本的
有限控制流，沒有額外明確的「完成Quest16並通知Server」呼叫可直接引用，亦非所有本機事件／
Server反應已窮盡。原檔、Lua與遊戲未執行；Event包可能含歷史本地翻譯的限制沿先前報告。

## 可用介面與不可偷渡的語意

| 邊界 | 有限Client介面 | Server必須自己處理／仍需補證 |
| --- | --- | --- |
| prerequisite快照 | 6F重建bitmap集合 | 從完整權威集合發布，不能把局部delta當snapshot |
| prerequisite增量 | 74／WORD key；46/sub0有條件追加 | 何時合法產生key、DB commit與版本、重送一致性；UI變更不等於給獎 |
| 接取類回饋 | 40/QID/DWORD state0對應mode2等有限效果 | 合法意圖與accept/turn-in/reject規則；不宣稱是36唯一官服回覆 |
| 完成類回饋 | 46/QID/WORD substate0、45依CompleteAction | 與scene scheduling、獎勵、成功保存分開；record+8 gate不亂命名成QuestInfo.type |
| NPC/對話意圖 | 1C兩個event欄位、36條件式QID、3F主次鍵 | 來源各不同；NPC10027不等於Quest16，也不把任意3F認成成功 |
| 地圖／城鎮 | 38/context、69/CSquare、43進度、12物理map | Town5、map511、完成key16是不同維度；實際控制／loading另驗 |

不存在官服後端源碼不代表無法開發Server狀態機；接取、完成、給獎、交易與重登策略屬
Server設計責任。相反地，缺少Client欄位、事件路由與畫面效果不能用「Server自訂」冒充已證原生。
目前v7仍是有標籤的相容候選，其首戰、owned roles及有序劇情不是完整Quest16結算實作。

## 同一需求下的可檢閱開發包

機讀追蹤：[結算工作包](S00-20261101-TUTORIAL-SETTLEMENT-WORK-PACKAGES.json)。
它是PLAN_ONLY／未核准的Server設計，非新增正式SPEC、RR或conformance TEST。

1. **進度所有者與識別**：先明確帳號／冒險團、可切換隊員Role、Quest與Encounter的關係。
   ADR-0006的per-role及T16原稿的角色隔離都是提案，不可直接把每次Tab切角視為獨立新手進度。
   現有候選依account保存首戰／ownership，但不代表已定官服作用域。保留actor action owner隔離。
2. **正常達成／結算**：分開Scenario14 outcome、Quest14可交付／完成、Quest16可接／接取／
   達成／完成、Quest15可接及terminal tutorial。每個轉移列觸發、必要Server證據與未知點；
   不因最後3F、43、輸入或一次send成功就自動結算。整個首次教學必須能正常跑完，不能只交mock。
3. **資料與獎勵交易**：current lease／owner／revision查核、唯一settlement key、quest state、
   reward entitlement／ledger與發布版本在同一交易或明示outbox界線；raw type2/value50不猜貨幣。
   正常授予／保存是當前實作目標；競態／故障／重播測試仍依使用者暫緩。
4. **Client狀態發布**：對照已核對的6F／74／40／45／46／64用途，分清snapshot與delta及
   accepted/excluded cache；使用同一帳號／scope最新提交版本，沒有過時snapshot覆蓋新增key。
5. **完整人工正流程**：隔離新帳號從命名、移動／切角、首戰、招募、末段到廣場可動且無殘窗，
   再以獨立DB讀取證實結算與持久化。現在v7結果卡仍待回，未要求重登／恢復等暫緩測試。

REQ-0017連到既有ADR-0006/0007提案及上述驗收，不把設計提案改為APPROVED或作normative依據。
私庫SFD-0012保持OPEN。原始Client相容性、合法Quest16 terminal、獎勵類型與全部畫面／
完成保存仍有限制，完整goal未達成。沒有改Client、schema、服務或要求使用者重新測同一張卡。
