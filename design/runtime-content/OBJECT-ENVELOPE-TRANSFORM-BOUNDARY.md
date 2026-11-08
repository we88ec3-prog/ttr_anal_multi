# 技能物件外層轉換：有限還原與範圍補正

2026-11-08，SOURCE_BACKED_PARTIAL。KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。

## 已能離線執行的轉換

本次對既有421個同名EMF候選進行離線轉換，沒有增加載體搜尋。member皆為gzip容器；解壓後保留8-byte前綴，再按WORD+4的模式執行原始7CC000／733EA0中的固定區塊轉換：

- 模式0／2：對offset8開始的128bytes進行XOR。
- 模式1／2：對整份解壓資料最後128bytes進行XOR。
- XOR使用733EA0的32-byte常數，擴展至128bytes：`key[i] = byte(key[i % 32] * i)`，i從32到127。區塊轉換次序與原始指令一致。
- 7CC000之後將offset8／length-8傳給862450。這不等於已完成862450或上游壓縮與完整模型載入規則的語意驗收。

421個觀察樣本全為模式2，每一份均核對原件／工作副本相同、原有gzip解壓雜湊一致，且轉換後可逆回同一解壓資料。沒有把模型資產寫出或上傳Git。

[轉換函式](../../governance/client-variants/20261107-all-skills-unlock/decode_object_envelope.py) 回傳記憶體中的不透明body，僅支援本次覆核的0／1／2模式及至少136bytes的envelope；遇到未覆核範圍會拒絕。它不是模型解析器、通用NIF讀取器或原生MEF讀取器。

## 補正前一份回退證據的用途

前份 [物件依賴報告](ACTION-OBJECT-DEPENDENCY-BOUNDARY.md) 中6D7560的尾碼轉換指令本身正確；但補看上下文後，確認它在預檢F882E8的固定27項資源清單。6D7640讀取表格項，6D77A5比較0x6C位元組界線。**不能將它升級成「所有EFF模型的通用載入回退」。**前份433項member可用性及容器雜湊結果不受影響。

另有79BCE0：在manager+300啟用且原名稱714550查詢返回0時，用splitpath及原路徑／stem構造EMF名稱；已找到7D0920的直接呼叫候選及相鄰7CBEE0／7CBF70處理路徑。但隱藏暫存器／回傳ABI、完整呼叫分支及EFF到模型的接線尚未在本次閉合，不據此宣稱載入成功。

## 對技能配對的結果與下一步

在這421份轉換後body中搜尋既有72個新增配置技能的完整ASCII Practice stem，沒有命中。這只是精確名稱byte檢查，不排除數字、間接、縮寫、其他編碼或body之外的關聯，不能宣稱整個Client沒有技能對應表。

目前62個缺少動作對應的技能仍未解鎖。這個外層轉換讓後續可以分析body的節點／材質／動畫資料，但還沒有完成幾何、骨架、貼圖依賴或實機渲染。沒有修改Client、Server技能規則或目前Host，也沒有執行遊戲。

[查核程式](../../governance/client-variants/20261107-all-skills-unlock/audit_object_envelope_decode.py) 與 [原始指令／逐member雜湊](../../governance/client-variants/20261107-all-skills-unlock/object-envelope-transform-boundary-v1.json)。報告SHA256：`a33f2c595e9942e78915d7fe3864b5b4b5f52b53295e0ae085449760069c09e0`。完整函式未取得T01 FULL-PASS；沒有虛構MEF格式或封包。
