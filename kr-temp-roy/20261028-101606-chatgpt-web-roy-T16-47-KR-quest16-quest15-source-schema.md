# T16-47 — KR Quest16／Quest15 資源定義與命名空間：可讀 XML、BIN 字串交叉檢查

- 研究者 `chatgpt-web roy`；KR T16（不涉及 TC）；日期 `2026-10-28T10:16:06+08:00`。
- SHA256(KR BIN) `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，size `12472320`；原檔唯讀。
- GitHub `we88ec3-prog/ttr_anal_multi`, main 最近 commit 查詢回報 `4b2f7cc8295df4256b7b1c1f94a33083c2f8a7c1`（commit 搜尋的最近項，非 ref 原子鎖定）；未改 catalog/owner。
- 證據標示：「原生已確認」僅限本輪實際解析位元組／讀取 XML；「部分確認」為本地 script 與 client 邊界；「資訊缺失」為無 server writer/packet 的結果；不可推成可玩驗收。


## 1. 真正取得的 Quest XML

已使用 GitHub connector `fetch_file` 讀取 `kr/evidence/b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28.txt` 的 XML 原文第1～23行，來源 `Table/QuestTalk.xml`，來源 SHA256 `b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28`。

```xml
<?xml version="1.0" encoding="UTF-8" standalone="yes"?>
<QuestTalk>
  <Quest id="11" givertalk="374" givertotalk="377" finishertalk="378"/>
  <Quest id="12" givertalk="380" givertotalk="383" finishertalk="385"/>
  <Quest id="13" givertalk="387" givertotalk="389" finishertalk="390"/>
  <Quest id="17" givertalk="2216" givertotalk="2219" finishertalk="2220"/>
  <Quest id="18" givertalk="486" givertotalk="488" finishertalk="489"/>
</QuestTalk>
```

註：上面是選定行的**摘錄**，不是連續合法完整 XML 文件，最後的 `</QuestTalk>` 是示意摘錄閉合，不是取自此視窗的原始行；不將其計入原始證據。`QuestTalk` root／行中實見 `id`, `givertalk`, `givertotalk`, `finishertalk` 欄位。該檔有 4322 children 的數量是 T01 source audit 而非這次逐項解析。開頭已讀局部從 13 跳至 17，無法判定全檔及 QuestInfo 是否包含 14/15/16；尤其不代表 Quest16 未被官方定義。

**DEFERRED-LOCAL-RESOURCE:** `Table/QuestInfo.xml` SHA256 `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`; 原始本地候選 `kr-temp-roy/T16-local-20261028/evidence/resources/kr/Table/QuestInfo.xml`，GitHub `kr/evidence/<SHA>.txt` connector 在指定行1～12與 base64/utf8 回空，尚未讀到任何 Quest15/Quest16 `<Quest>` 原件節點。T01 稽核 root=`QuestInfo`, 4798 children 只算 metadata，**不算已驗證任務欄位**。

## 2. 本輪 KR BIN 直接來源字串搜尋

SHA256 見首段。實際檔案 bytes 的 ASCII 精確字串命中（raw file offset，不是 VA，不預設全為函式入口）：

| needle | raw offset(s) |
|---|---|
| `QuestInfo.xml` | `0x80C14E` |
| `QuestTalk.xml` | `0x80C162` |
| `TutorialMain.lua` | `0x804E82` |
| `TutorialBase.lua` | `0x804E6A` |
| `TutoQuest` | `0x80D7A4` |
| `HasQuest` | `0x80DAEC` |
| `HasCompletableQuest` | `0x80DAF8` |
| `HasScenario` | `0x80DB0C` |

**注意：** raw offsets `0x80....` 多位於 rdata 資料段；按 PE header，`.rdata` raw `0x007D0600`, VA `0x00BD2000`，需逐項確認區段再映射：`VA = 0x00BD2000 + (raw - 0x007D0600)`。原始字串存在不代表 C++ 直接實作了 Quest state 更新，也不能憑識別符名稱當成 server 持久化欄位。`QuestInfo.xml` 和 `QuestTalk.xml` 不應在缺乏解析/引用證據下合併命名空間。

## 3. 證據分級與 Quest16 → Quest15 鏈

| 研究問題 | 證據判定 | 缺少的原件 |
|---|---|---|
| 是否有 Quest16 定義？ | 資訊缺失 | QuestInfo.xml 完整 `id=16` 元素與 schema |
| 是否有 Quest15 定義？ | 資訊缺失 | QuestInfo.xml 完整 `id=15` 元素與 schema |
| Quest16 是否為 Quest15 必要前置？ | **unknown** | 原生前置條件欄位與 server 接取驗證 |
| Quest15 NPC、地圖／對話／任務狀態？ | **unknown** | QuestInfo + NPC/scene 定義 + 原生 request/reply |
| QuestTalk 開頭對話映射已讀？ | 原生已確認（局部） | 所有相關 XML 節點尚未取回 |
| 教學 Lua 會請求 scenario 嗎？ | 部分確認，見 T16-46 | Lua call 的參數、server 回傳鏈 |

`TutoQuest`, `HasQuest`, `HasCompletableQuest`, `HasScenario` 的存在僅確認原生字串與 BIN 資源消費路徑候選，不等於已綁定某個玩家資料表。禁用「看到 QuestTalk 缺 15/16，所以 Quest16 應由 Tutorial 自動完成」等推理。

## 4. 可接棒取證規格

- 提供 `QuestInfo.xml` 檔案原始 bytes 或能分段讀取的 UTF-8 文本，先驗 SHA256，再逐欄抽取 Quest 15、16 及引用的 giver/finisher/condition/level/scene 欄位，**只列原始 schema 實有欄位**。
- 對 `QuestTalk.xml` 實際全檔搜尋 `id="15"`、`id="16"`，如果查無節點，僅可推論對話映射缺漏，不能推論 QuestInfo 缺漏。
- 對任何任務 id 使用來源命名空間標籤（QuestInfo id / QuestTalk id / scenario id / stage id / NPC id），必須有引用關係才做等值關聯。
- 本段不擴展 TC；原始 KR 資源唯讀。