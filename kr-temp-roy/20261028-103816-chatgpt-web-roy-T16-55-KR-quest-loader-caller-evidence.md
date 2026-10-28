# KR T16-55 — QuestInfo／QuestTalk reader 的原生直接 caller 與局部 CFG

- 研究時間：20261028-103816 Asia/Taipei；`chatgpt-web roy`；**KR only**。
- GitHub：https://github.com/we88ec3-prog/ttr_anal_multi，目標 `main`，此份僅專屬研究原稿，不更改 catalog/owner。

## 原始來源與證據級別
- 原始檔 `/mnt/data/Tartaros.bin`，實際本輪重算 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes；唯讀。
- `Tartaros.exe` 不執行；不使用 TC。
- GitHub 已提交原稿 T16-45～52 與 T01-20261028-06 的來源稽核為交叉脈絡，不把曾有的推測列為新證據。
- 此處 direct CALL 搜尋是 `.text` raw 位元組掃描 `E8 rel32`，可能有 embedded data／非指令邊界假陽性，需 CFG 進一步確認。

## 兩個已知 reader 候選的直接 caller（從 KR BIN .text 尋址）

### 目標 `0x00504740`，直接 E8 命中：`0x005043E9`

- caller site VA `0x005043E9`, raw `0x1037E9`
```asm

```

### 目標 `0x00505570`，直接 E8 命中：`0x005043EF`

- caller site VA `0x005043EF`, raw `0x1037EF`
```asm

```

## 已確定的相鄰性 vs 需要補證的語意
- 讀取 `QuestInfo.xml` 與 `QuestTalk.xml` 的 reader 函式不等於 server Quest state authority；reader 只證明客戶端資源管線。
- 兩個 E8 來源若在同一個調度區域，最多支持 loader orchestration 假說；尚不能推出任務先後順序、Quest16 完成或 Quest15 接取條件。
- XML 內 id namespace 必須使用原始元素及其 schema 確認；`QuestTalk` 缺少 id15/16 的局部視窗不能推論 id15/16 被移除。

## 精確阻塞
`DEFERRED-LOCAL-RESOURCE`: `Table/QuestInfo.xml` SHA `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`，尚需可直接解析的 `Quest id=15`、`Quest id=16` 原件欄位；該檔先前 GitHub connector 回空範圍，來源稽核有 SHA 不等於正文已取得。
