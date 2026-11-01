# 交接補充：明天開工前的實作狀態

新帳號教學到廣場人工通過。後續新增的Quest14/16前置保存與6F完整snapshot adapter
已有正常TCP+SQL測試，但只在明示opt-in模式下啟用；目前live v10未啟用／未換版／未migration。
這是Server正常旅程重建政策，不是官服Quest接取交付算法已還原。Quest16 raw2/50仍pending，非paid。

CSquare initializer原件已核對會選／重設kind2單角色控制器，並送4B C2S43，末byte10，
中間opaque；不證普通Town1一定走此scene。村落scene/controller的實際入口、合法正常spawn、
NPC候選／15/1之後的劇情與Quest流程仍是W2/W3重點。

詳見governance/s00-iterations/S00-20261102-TUTORIAL-PREREQUISITES-PUBLICATION.md。
S00的程式準備不能代替Web分析需要交付的Client因果鏈，也不能據此標所有任務已可玩。

## Quest15開場補充

原始NPC10338表TYPE10；Scene15/1使用ScenarioTalkTable3/22、talk2314..2319，文字記錄在02_Lenart，
不同於NPC自身talk28724..28726。不要把NPC表TYPE與actor類別、Scenario group3與文字檔index3混用。
限定發布模式的Server現在準備了15/1 receipt後停止／重新bind既有actor及參數的候選，
只恢復控制，不授Quest15完成或進村；尚未部署／真NPC人測。
來源與細節見S00-20261102-QUEST15-INTRO-CONTROL.md及QUEST15-INTRO-CATALOG.json。

## Scene-start receiver addition

S00-20261102-SCENE-START-CONSUMER.md verifies registration and receiver for
S2C0x47: signed WORD at+2/+4 reaches561760. Source-shaped six-byte encoder exists
privately but is dormant. W2 should use this receiver evidence rather than guess
0x36/0x40 or a generic NPC ACK. Quest acceptance and authorized scheduling after
15/1 remain unresolved; C2S3F literal1 alone is insufficient. No live change.

## Square NPC interaction publication

S00-20261102-SQUARE-NPC-INTERACTION.md records the newly added complete0x27
checkpoint collection in the private candidate mode and restoration after15/1.
26 positive synthetic cases pass; not deployed/human verified. Legacy
anal/plaza_npcs.py had incorrect scene-start/result opcodes and prematurely
completed15 after scene1; do not reuse those transitions. OriginalQuestInfo15
has no explicitAcceptAction/CompleteAction children. This does not remove the
need to determine authoritative acceptance and legal scene progression.
