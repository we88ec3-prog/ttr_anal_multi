# 發布狀態與累積交付

核對日期：2026-11-17（Asia/Taipei）。目標是既有 `extra/roy1`，不是 main，未建立新分支。

**本輪尚未推上Git。** 最後讀回的遠端head仍為
`0d76b827dfda0deb263e2692281ec304747652f8`；main仍為
`03b3ea5eae2cb92f9fc373d432edeaf635d6c5fc`。
目前GitHub connector可讀取、搜尋及比較，但沒有建立blob/tree/commit或更新ref的寫入操作。
已確認GitHub插件安裝／啟用，沒有可改用的已連線寫入通路；本地亦無gh CLI或已配置token。
這是本次工具能力限制，不是使用者未授權，也不是公開研究需要再次請求同意。

## 交付範圍

累積patch只新增三個自有研究目錄：

- `kr-extra-roy/MEF-full-surface-native-continuation-20261116`：前輪13檔。
- `kr-extra-roy/MEF-feature-lifecycle-20261117`：前輪18檔。
- `kr-extra-roy/MEF-world-identity-scene-interaction-20261117`：本輪18檔。

合計49檔。前31檔逐位元組保留，包含其歷史PUBLICATION；本次最新發布狀態以本文及外層發布核對JSON為準。

完整原稿、選定原件節錄、機讀契約、純資料模型、唯讀驗證器均保留。沒有原BIN、EXE、STP、完整解包member、可部署遊戲腳本、Server程式改動或正式RR/owner變更。沒有重寫舊提交。

## 在已存在的工作副本套用

先確認工作樹與遠端狀態；若原分支已被其他人更新，先比較來源並處理相容性，不reset／force。
以下為使用者可執行的發布步驟；本輪沒有執行commit或push。

```sh
git switch extra/roy1
git status --short
git fetch origin
git log -1 --oneline origin/extra/roy1
git apply --check /path/to/MEF-world-scene-cumulative-20261117.patch
git apply /path/to/MEF-world-scene-cumulative-20261117.patch
git diff --check
git add -- kr-extra-roy/MEF-full-surface-native-continuation-20261116 \
  kr-extra-roy/MEF-feature-lifecycle-20261117 \
  kr-extra-roy/MEF-world-identity-scene-interaction-20261117
git diff --cached --stat
git commit -m "docs(mef): publish world identity, scene interaction and pending lifecycle research"
git push origin extra/roy1
```

不要將「patch套用通過」說成已遠端發布；應在push後讀回commit與檔案hash。
本輪以隔離scratch實際檢查add-only patch、套用後49檔身分以及本輪原件驗證器；
實際結果另存外層`MEF-world-scene-publication-check-20261117.json`。

本輪native PASS不是T01 FULL-PASS、遊玩驗收或ordinary-world結果到Lua已閉合。資料綁定及未證入口見總報告，不以此發布包增加正式完成狀態。
