# 發布狀態：尚未推送，累積保留兩輪完整研究

目標：`we88ec3-prog/ttr_anal_multi` 的既有 `extra/roy1`。

本輪讀回 HEAD：`0d76b827dfda0deb263e2692281ec304747652f8`。main仍為 `03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。本輪沒有create/update-ref寫入工具，CLI也沒有可用推送通路；沒有建立新commit、更新遠端ref、merge或新branch。不把計算的blob雜湊當成遠端已有檔案。

使用者已授權公開研究與必要節錄；這個授權保留，不重複要求公開確認。問題是當前寫入能力，不是拒絕處理分析或缺少使用者授權。

## 累積內容

`MEF-pending-combined-20261117.patch` 同時新增：

- 原封保存前輪 `kr-extra-roy/MEF-full-surface-native-continuation-20261116/` 的13個交付檔案。
- 本輪 `kr-extra-roy/MEF-feature-lifecycle-20261117/` 全部18個交付檔案。

合計31檔，沒有覆寫舊稿、刪除檔案、修改Client/Server/正式台帳，沒有原始BIN/EXE/STP、完整解包資源或可部署seq。另有本輪單獨patch，用於前輪已人工套用的情況；不要把累積與單輪patch重複套用。

完整ZIP保留上述同樣目錄結構、兩份patch與外層逐檔雜湊清單。`publication-check.json` 記錄實際 `git apply --check`、套用後31檔SHA核對，以及原件/模型復驗結果。

## 在具備寫入能力的工作環境發布

先檢查repo/branch與工作目錄，不在其他branch套用，不強制覆寫並行變更。以下是人工命令示例，**本輪未執行commit/push**：

```powershell
git status --short
git branch --show-current
# 應是 extra/roy1，工作目錄須可辨識且沒有衝突；不要新建branch。
git pull --ff-only origin extra/roy1
git apply --check --whitespace=nowarn C:\path\MEF-pending-combined-20261117.patch
git apply --whitespace=nowarn C:\path\MEF-pending-combined-20261117.patch
git add -- kr-extra-roy/MEF-full-surface-native-continuation-20261116 kr-extra-roy/MEF-feature-lifecycle-20261117
git diff --cached --stat
git commit -m "docs(mef): census capabilities and close native effect ownership lifecycles"
git push origin extra/roy1
```

若新檔已存在或branch已包含部分研究，先比較逐檔SHA，再選適用的單輪patch；不要用覆寫或force-push解決。如果遠端main更新，按既有規範另作非破壞性同步和衝突核對，不假設舊快照仍是最新。

真正發布後應讀回遠端commit及檔案blob，才更新發布狀態。現有READMEs與原稿的「未發布」描述是當時的歷史紀錄，正式發布補註可以新增，不需抹去舊證據。
