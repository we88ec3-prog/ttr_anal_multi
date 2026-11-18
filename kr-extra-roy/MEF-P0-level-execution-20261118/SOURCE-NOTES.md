# 來源與研究邊界

## 固定版本

| 來源 | 本輪基準 | 用途 |
|---|---|---|
| 分析 branch | `extra/roy1@19005c9f8a8180e6f0deb00faf008a11ef98023f` | 前輪 20 類功能、原生 binding／生命期與地形證據 |
| 開工核對的分析 main | `7344eeb65198e2dd61684b66cf811021765ed8f5` | AGENTS、T01／共用成果、正式派工與較新實作記錄 |
| Server 原碼 | `ttr_server_roy@e88ac0ad5fd6e911b28b1e61b6eedab3bfdfb4b4` | 實際 scenario、波次／時計、怪物行為、碰撞 overlay 與換圖接線 |
| Server Git tree | `1c42df357de7385bb0263732c9c8a33550a8f571` | 原碼路徑、Git blob 及來源固定 |
| KR BIN | SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` | 新的 actor／戰鬥／投射物／碰撞與出口原生補證 |

已重新閱讀 Project 的 `02-PROJECT-SHARED-INSTRUCTIONS.md`、root／extra AGENTS、目前 MEF 方向與本題相關既有來源。最新 main 與上輪發布前已核版本相同；不為本輪工作建立 branch，也不合併其他工作線。

T01 已發布的 MEF 整合檢核仍是限定 R0／R1／R2，不能當全部 121 binding 或每篇報告 FULL-PASS。共用驗證知識的局部適用範圍照原文；舊 FlyingObject 說法採既有更正。RR-0013 仍為 T13 的原有請求，本輪補證可供該工作線引用，不替它認領或結案。其他 Task 的既有退回保持原狀，依使用者本次指定範圍接續八項 MEF 分析。

## 原件與私有實作的處理

原 BIN、Event／Table／Master／BoundMap 載體及完整解出內容只作本機唯讀來源。公開交付包含必要的有界原件指令／資料證據、來源 hash、幾何推導及作者候選，不上傳完整載體或完整解包資源。

Server 原碼由 GitHub 固定 commit 讀回，base64 解碼後以 Git blob、長度及 SHA256 核對。Server AGENTS 要求實作保持私有，本包只保存來源識別、函式／欄位名稱、有界語意分析與重驗條件；完整 C# 留在來源快照，不搬入分析 repo。驗證時須提供相符的 `--server-sources`。

原碼讀取補足前輪僅依分析文件仍未精確關閉的問題，例如時間轉換與不同場景的清場 gate。這能證明該 commit 的實作行為，不能證明使用者目前執行的本機部署就是這個版本，也不能當原版 Server 的演算法證明。

## 證據層次

| 標示 | 可以支持的結論 | 不因此支持的結論 |
|---|---|---|
| Client 原件補證 | 精確入口、欄位、條件、consumer 與有界生命期 | 未查的所有場景、官方 Server 決策或實際到包順序 |
| 固定 Server 原碼 | 該版本已存在的規則與接口、時間計算及處理次序 | 原版演算法、已部署或真人已玩過 |
| 作者候選／靜態投影 | 配置格式、條件安排、圖與指定二維地形政策下的可達性 | 完整三維碰撞、素材可見性或通關驗收 |
| 來源與交付驗證 | 檔案一致、證據可重跑、分類與範圍沒有悄悄改變 | T01 FULL-PASS、RR/S00 接受或 Server 新功能已完成 |

所有新增設計保留 Server MEF 身分。事件索引、期限排程、有限展開或新的道具條件等，必須按各自契約區分已可沿用、需接 adapter 與需新增 runtime 的範圍。

各子題記錄自己的原件與 Server 精確 read set；根 [source-manifest.json](source-manifest.json) 與 [server-source-manifest.json](server-source-manifest.json) 保存整合來源身分，分類由 [type-definitions.json](type-definitions.json) 與固定原 binding 表重建。
