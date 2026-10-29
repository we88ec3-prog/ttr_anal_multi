# T01 → S00：有限主張交接

來源：SRC-0011～SRC-0328（318版R0收件），精確對應以[來源索引](../../intake/index.json)為準；其中4個來源新增CLM-CLIENT-0001／0002／0003、CLM-QUEST-0001，其餘只有來源身份而未萃取主張。全部限KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。

**可觀察Server契約更新：** 本批沒有新增可規範的wire欄位、opcode、回覆順序或失敗值。CLM-CLIENT三項是已驗證Client內部有限資料流，缺少與Server消息的完整關聯，不擴大Phase-B契約。CLM-QUEST-0001僅可在SPEC-NET-0003作Quest本地名稱表研究導航；禁止把表內1F、11、12、13推成C2S／S2C opcode。

**已確認與部分來源：** 三個Client主張引用前批已正式通過的CK與精確審查決議；Quest表保持PARTIAL，未重新認證原稿全文。參數／owner／動態類別與正常返回限制見各CLM及本批README。

**Server設計選擇：** 無新增ADR；不設計觸發時機、任務前置、成功／拒絕政策或持久化規則。上述皆不可冒稱官方Server。

**缺口與owner：** 所需wire／場景證據仍由既有Task及RR按scope處理；T01不代認領T02／T03的QUEUED請求。Quest名稱表沒有完整producer、consumer與wire域，尚不足以據此新增或解除一個Phase-B阻塞。沒有S00有限用途接受紀錄前維持CONFLICT_CHECKED，不升SPEC_CONSUMABLE。

**測試：** 既有合成framing／roster／auth向量只作回歸。Client資料流不直接產生wire向量；Quest表尚無合法wire測試來源。需要對應實際契約時，由S00標TEST_MISSING／既有GAP，不補猜封包。

**版本及相容性：** 不適用TC，不改既有公開契約或SPEC成熟度；未執行原版Client，未部署Server，未驗證端到端相容性。
