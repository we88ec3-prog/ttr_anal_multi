# 公開發布提交與原本機研究提交的對照

日期：2026-11-16（Asia/Taipei）。使用者已明確授權將本輪及前輪 MEF 完整分析與節錄證據，公開推送到 `we88ec3-prog/ttr_anal_multi` 的 `extra/roy1`；不包含原始 BIN、STP 或完整解包資源。

## 發布方式與身分變更

本機 Git／gh 沒有寫入憑證，因此改由已連線的 GitHub 介面建立 tree、commit，再更新既有 branch。該介面使用自己的提交者與時間 metadata，不能保留先前本機 commit SHA。本次保留原本機歷史，對 R8 與 main merge 另建立**完全相同 tree** 的公開提交，並將 R9 實際來源 pin 指向公開提交。

| 角色 | 原本機提交，僅作歷史記錄 | 公開提交，供來源驗證 | 內容等價依據 |
|---|---|---|---|
| 第八輪 R8 | `c0c2ce5aa025b86a85a402071d4c0c18fcdbc2d5` | `dda39a65ca483f2b4539c6feb74e05dfcdbf7ac8` | 相同 tree `a9a20e5f15ea7d3af2f57044fd1bfae76be8fa78` |
| 合併 main | `b0bf6bb5986f9c849fcfac4e16db42f0a1cf960c` | `15819c892c0a9a23924704daa5883615a09626bf` | 相同 tree `344c2c61197f0426a230ff7a506c33027db015ee` |
| 本輪 R9 原稿 | `28c88573fd19ddde0a748d85787622ca1881edfa` | 最終發布提交以 branch／交付訊息為準 | R9 更新了來源 commit pins、發布說明、驗證器及結果，**不聲稱與原 R9 tree 相同** |

公開 R8 的 parent 仍是 `88b22bcd750ea219bfc56580139396d0ee677644`；公開 merge 的兩個 parents 依序是公開 R8 與 main `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。共同祖先仍是 `0a2503db089a4867cff5ef8bf6d7689333f12fd1`。沒有新增 branch，也沒有 force update。

## 證據保存與重驗

R1–R8 的任何檔案均未因發布方式改動。R9 引用它們的 `git_blob`、SHA-256 與 bytes 維持原值，只將未公開的本機 commit carrier 映射至上述同 tree 的公開 carrier。原件身分、native windows／ASM、Lua instruction words、技術結論與未解邊界亦保持不變。

R9 的 `source-manifest.json` 保留 `git.initial_local_head` 作為開工時的真實本機歷史，另外使用 `git.published_r8_commit` 進行 parent、ancestor 與 merge-base 驗證。乾淨 clone 的重驗不要求取得原本機 C0、B0 或 R9 提交。

更新 pins 後，重新執行三支分題 verifier、重建 runner 的交付 manifest 及本輪總 artifact manifest，再執行包含 R6–R8 的總控重驗。實際結果保存於 [verification-result.json](verification-result.json)，機讀身分對照在 [publication-provenance.json](publication-provenance.json)。

這項修訂只處理發布可追溯性，不改變本輪的靜態分析等級，也不宣告原生 MapList first caller、ordinary gameplay、Server 實作或遊玩驗收已完成。
