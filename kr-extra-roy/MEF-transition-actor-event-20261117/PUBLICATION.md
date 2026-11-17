# Git 發布狀態與推送後核對

## 本輪狀態：尚未推送

已連線GitHub的當前操作集合只有讀取／搜尋／比較，沒有建立commit／更新ref的寫入操作。已查已啟用GitHub插件，未找到另一個已授權可用寫入介面。本機沒有gh或GitHub寫入憑證；一般git clone也因github.com DNS解析失敗，不能用CLI完成真實遠端提交。

目前讀回extra/roy1為`0d76b827dfda0deb263e2692281ec304747652f8`；main為`03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`，compare ahead14/behind0。沒有新增遠端commit，所以**不能把本地patch套用、blob雜湊核對稱作「推上去後的內容已驗證」**。未建立遠端分支，未force push。

## 完整成果保存

累積包保留前三輪49個研究檔逐位元組不變，再加入本輪檔案。補丁僅新增四個自有kr-extra-roy研究目錄，不修改原有公開研究或正式規劃。只含有限原件節錄與分析，沒有原始EXE/BIN/STP、完整解包member、私有Server程式或可部署遊戲腳本。

包根的`publication-manifest.json`保存每個path、bytes、SHA256與Git blob，以及整份patch的SHA。套用後按manifest逐檔比對；研究驗證器亦在套用後副本重跑。這是離線校驗，不是遠端成功。

## 有寫入權限的本機可一次發布並讀回

本研究提供`publish_and_verify.py`，只在**已存在**且乾淨的extra/roy1、origin為指定公開研究庫、local與remote都仍為上列base、main已包含於HEAD時才寫入。它不建立／切換分支、不force、不reset；有競爭提交便停止，避免覆蓋其他人。

把累積ZIP解壓到倉庫外，在已登入GitHub的Windows本機執行（下例路徑自行替換）：

```powershell
py -3 "E:\MEF-review\kr-extra-roy\MEF-transition-actor-event-20261117\publish_and_verify.py" `
  --repo "E:\Tartaros\ttr_anal_multi" `
  --manifest "E:\MEF-review\publication-manifest.json" `
  --patch "E:\MEF-review\research.patch" `
  --receipt "E:\MEF-review\remote-receipt.json"
```

腳本核patch/hash與授權檔案集合，apply --index，核staged blobs，commit後再核，正常non-force push，fetch真正remote，再按遠端commit的每個blob重新讀取比對，最後再次確認remote HEAD沒有競爭變動。成功才產生`REMOTE_CONTENT_VERIFIED`receipt。

若已由其他方式推送同一內容，只加`--verify-only`（不需要--patch）即可讀回遠端；仍必須在既有extra/roy1。若本機或遠端base不同，不能繞過檢查直接force；先整合新增歷史，再調整發布方案。

**這個腳本本輪只作語法與離線blob核對邏輯檢查，沒有在真實GitHub執行寫入。** 它不執行Client／Server或遊戲資源。缺憑證應使用使用者正常GitHub認證，不提供或蒐集任何憑證。
