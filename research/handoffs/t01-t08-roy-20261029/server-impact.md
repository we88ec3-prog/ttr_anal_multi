# T08 → S00：Client實體／資源／幾何的限定來源導航

來源：`t08/roy/chatgpt-web@5816884ef481995a9fe0d92277b1dde06aff32e8`的138份原稿。精確SRC／blob／SHA／行號見[sources.json](sources.json)、[逐來源處置](source-dispositions.json)。限KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，不跨用TC。

**Server可觀察契約：** 本批沒有新增已證wire opcode、spawn／despawn消息格式或回覆時序。Task的0007標籤、本地event7／8、actor+88、resource狀態、bucket index、callback offset與Server業務域不能等同。Client建立26-byte row與本地移除路徑只作source-derived介面導航；完整dispatch註冊、觸發與Server政策仍未知。

**Client資料結構與生命週期：** 對actor主／次樹、節點與payload清理、component／child介面、wrapper／resource／Provider／Binding、pool復用與計數、22桶／plane／B queue分開整理；135個來源完成限定萃取，3個既有正式來源保持其精確scope。37 PARTIAL不是新原生認證；12 UNKNOWN不可補猜；6 REFUTED只能作排除／修復導航，不得寫入規範性MUST。

**更正與限制：** 24個精確mapping FAILED原稿只供缺口導航；不從同offset／stride推同一owner，也不從沒讀global推不同。getter／mode／次級移除與既有canonical歸併，但新稿品質不繼承。既有退回和173／196的歷史結案保持，不新增重複問題或改原稿。

**對既有SPEC：** 目前沒有已確認的Phase-B framing、auth、roster／selection／scene契約直接依賴這些Client內部群組，故新群`affected_spec_ids=[]`，不臆造SPEC或拉高既有DRAFT。S00若提出實際設計阻塞，才依精確來源與函式子範圍派R2／R3；沒有S00接受，全部停在CONFLICT_CHECKED而非SPEC_CONSUMABLE。

**Server自訂政策：** 出生時點、波次、怪物AI、權威資料、任務／勝負與持久化仍屬Server待開發或其他Task；未新增／批准ADR，不冒稱官方規則。T02 transport、T06／T07場景及其他Task主責不變，未改owner／catalog。

**TEST／RR／發布：** 無新方向別wire向量或真實Client測試，既有離線合成測試只作回歸；沒有RR認領／SUBMITTED／ACCEPTED或GAP解除。未執行Client、未部署Server，未宣稱可玩流程完成。
