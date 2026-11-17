# 發布狀態與 Git patch

## 本輪尚未推送

最後唯讀核對遠端 `we88ec3-prog/ttr_anal_multi` 的 `extra/roy1` 仍為：

`0d76b827dfda0deb263e2692281ec304747652f8`

本輪現有GitHub連線只暴露讀取／搜尋／比較介面；重新列出全部48個可用操作後，沒有create_blob/create_tree/create_commit/update_ref等寫入方法。亦已查詢已安裝GitHub整合，其描述的CLI寫入途徑在本環境沒有可用gh或已配置認證的Git工作副本。沒有將GET介面偽裝成寫入，也沒有要求使用者重複先前已提供的公開授權。

**本輪沒有建立新Git提交、沒有Push、沒有新的遠端SHA。** 研究與驗證結果已完整保存在檔案中；不能把上輪A1 commit當成本輪提交。

## 套用範圍

配套 `MEF-full-surface-native-continuation.patch` 只新增：

`kr-extra-roy/MEF-full-surface-native-continuation-20261116/`

共13個文字研究／證據／驗證檔，包含本說明和逐檔manifest；不修改既有檔案，不包含BIN/EXE/STP、完整解包遊戲資源、快取或部署腳本。patch在獨立空目錄實際通過 `git apply --check`，套用後逐檔大小／SHA256／Git blob均與原交付相符。這個核對不代表遠端提交。

## 已有本機研究庫的備援套用方式

以下是供本機操作者使用的PowerShell範例，**本輪未在使用者電腦執行**。先將patch位置改成實際下載路徑；只在既有extra/roy1工作分支上操作，不建立或切換branch。

```powershell
$ErrorActionPreference = 'Stop'
$Patch = 'C:\path\to\MEF-full-surface-native-continuation.patch'
if ((git branch --show-current).Trim() -ne 'extra/roy1') { throw '請在既有 extra/roy1 上操作；此程序不建立分支。' }
if (git status --porcelain) { throw '工作目錄有變更，請先保留並處理。' }
git fetch origin extra/roy1
if ($LASTEXITCODE -ne 0) { throw 'fetch failed' }
if ((git rev-parse HEAD).Trim() -ne (git rev-parse origin/extra/roy1).Trim()) { throw '請先正常同步既有分支；不得 force push。' }
git merge-base --is-ancestor 0d76b827dfda0deb263e2692281ec304747652f8 HEAD
if ($LASTEXITCODE -ne 0) { throw '研究父提交不在目前歷史中，請先核對來源。' }
git apply --check $Patch
if ($LASTEXITCODE -ne 0) { throw 'patch check failed; no changes applied' }
git apply $Patch
if ($LASTEXITCODE -ne 0) { throw 'patch apply failed' }
git add -- kr-extra-roy/MEF-full-surface-native-continuation-20261116
git diff --cached --stat
git commit -m 'docs(mef): audit binding surface and native post-End continuation'
if ($LASTEXITCODE -ne 0) { throw 'commit failed' }
git push origin HEAD:extra/roy1
if ($LASTEXITCODE -ne 0) { throw 'push failed; preserve local commit, do not force' }
```

推送者須核對origin確實是指定研究庫；完成後讀回遠端SHA與檔案，而不是以本地commit成功當作推送成功。若遠端有競爭更新，保留本地結果並依正常歷史整合，不覆蓋其他人的提交。
