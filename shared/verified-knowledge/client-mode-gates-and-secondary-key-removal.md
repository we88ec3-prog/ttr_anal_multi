# KR Client：模式切換與次級鍵移除

審核者：Codex T01 integrator（逐篇核對由 review_t08_new 執行，整合者複核）；2026-10-29 Asia/Taipei。原件 KR `Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。PE `.text` VA `401000`、raw `400`；以下程式位址的 raw=VA−400C00。

## CK-CLIENT-COLLECTION-MODE-GATE-01 — FULL-PASS

在有效容器、payload 及相關呼叫正常返回的前提下，`7B7FD0` 先遍歷第一集合，對 payload 發出 virtual slot+4 呼叫；再遍歷 container+8 的集合，將 payload+44 寫為1；最後寫 container+30=1。`7B7FFE mov ecx,1` 支配 `7B8006 mov [edx+44],ecx`，第二迴圈沒有改寫 ECX 或發出呼叫，因此這次寫入不依賴 caller 的 ECX。

反向入口 `7B8030` 先對第二集合 payload 以 ESI 呼叫 `7DD1F0` drain，再清 payload+44；接著對第一集合發出 slot+8 呼叫，最後寫 container+30=0。producer `7DD1A0` 的 mode gate 是有號比較 owner+44>=1；符合才對 owner+7C 的範圍 append，否則對非空 item 執行清理及釋放。這不建立不同 pointer provenance 的 owner 為同一類別，也不保證異常、重入或執行緒安全。

證據：[完整逐項原生裁決與上下游](../integrations/T01-20261029-continuation-02/t08/MANUAL-REVIEW.md)、[根 CFG 與 cache 來源](../integrations/T01-20261029-continuation-02/t08/entry-provenance.json)、[全部碼塊核對](../integrations/T01-20261029-continuation-02/t08/code-block-audit.json)。來源 metadata：Task T08，作者 chatgpt-web roy；`kr-temp-roy/20261028-094900-chatgpt-web-roy-T08-177-owner-mode-caller-drain-closure.md`；Git blob `fdc8a64aa0f33866defe5a2484fa432f4bbaf66c`，SHA256 `253ccb2b658dcc734efe6bc3d5d6ab6f1629b95d173b998515624c5aa29949ac`。此修正版解決 RETURN173 的入口、來源值與寫入順序問題；舊173 blob維持 FAILED。

## CK-CLIENT-SECONDARY-KEY-ERASE-01 — FULL-PASS

在合法 owner、搜尋 key、樹 invariant 及正常返回前提下，`4DFC30` 以內嵌 owner+18 容器呼叫 `8438C0`，比較搜尋輸出與 owner+1C sentinel；未找到即返回。找到時才檢查 owner+F8，非空且該物件首 DWORD 等於 key 才清 owner+F8。節點 payload（node+10）非空時直接交 `89120C`，再由 `7B6890` 刪除節點。

這與 `4DFC90` 的 owner+8 主樹不同：後者逐節點比較 actor+88 DWORD predicate，匹配時發出 virtual+14／virtual+0(1) 清理，再 erase 並使用 successor 輸出 iterator。二者的容器基準、sentinel、payload 清理與查詢方式均已由完整根 CFG 及必要下游核對；不能據此推定 payload 動態型別、雙樹共享所有權或上游生成／移除政策。

證據：[人工主張矩陣及正常路徑](../integrations/T01-20261029-continuation-02/t08/MANUAL-REVIEW.md)、[4DFC30 根 CFG](../integrations/T01-20261029-continuation-02/t08/native-cfg/004dfc30.json)、[4DFC90 根 CFG](../integrations/T01-20261029-continuation-02/t08/native-cfg/004dfc90.json)、[已驗證的 erase successor 資料流](client-receiver-exact-lookup-erase-iterator.md)。來源 metadata：Task T08，作者 chatgpt-web roy；`kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-197-secondary-tree-key-removal.md`；Git blob `4812aa8da49c40647538206679b414753a4c6e5e`，SHA256 `555a88a78907b2deb1ea80d552ec64f41d0c52d4d52818e5d9faf3bbe6646ea3`。此修正版解決 RETURN196；舊196 blob維持 FAILED。

## 上下游與未解範圍

Client 待逆向：實際動態類別、跨實例所有權、間接 caller、異常與重入、所有 entry 是否非空，以及遊戲事件／封包到上述入口的完整關聯。Server 待開發：何時觸發模式與移除、持久化和玩法規則。跨功能整合及遊玩驗證均未完成；本頁只接受上述兩個有界正常路徑。T08-200 對「索引」的歧義保留 PARTIAL，不混入本頁結論。
