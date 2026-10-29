# KR Table.stp 原始 XML 狀態與 Quest14→16→15 依賴（靜態表格）
來源：KR `Table.stp` 5,248,784B，SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`；使用者附檔。所列每份 XML 都由容器指定 raw offset/size 擷取後 XOR 0xFF；EX(cipher1) 以 1024-byte resource KEY 再 XOR，zlib 解壓；對解壓完整原始 XML 重算 SHA256 並以 ElementTree 解析。

| 成員 | offset / stored | expanded bytes | SHA256 | XML root / 直接子元素 |
|---|---:|---:|---|---|
| `Table/QuestInfo.xml` | 4345872 / 204056 | 2503464 | `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60` | QuestInfo / 4798 |
| `Table/QuestTalk.xml` | 4550672 / 52404 | 342958 | `b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28` | QuestTalk / 4322 |
| `Table/ScenarioBookContents.xml` | 4620304 / 10987 | 55810 | `15b67767af884ac2abe05319ca406c9bc5e705c5ea8311de8d6b45644f8210d1` | ScenarioBook / 426 |
| `Table/TutCheckPointList.xml` | 4870160 / 282 | 512 | `fe0a7131118ae804897ed8255da00f4cf8bad58bbe8fcc87ca2e5676146a2555` | TutCheckPointList / 4 |

## 從 QuestInfo 原文選出的完整三個 entry
```xml
<Quest id="14" type="3" town="0" field="18" level="1" giver="10027" finisher="10027" subtype="1" subject="튜토리얼-이실리아">
  <CompleteAction type="1" />
  <AcceptAction type="1" />
</Quest>
<Quest id="16" type="2" town="0" level="1" giver="10027" finisher="10027" subtype="1" subject="튜토리얼-핑코파파">
  <Demands><Demand id="14" /></Demands>
  <RewardsEtc id="16"><Reward type="2" value="50" /></RewardsEtc>
</Quest>
<Quest id="15" type="2" town="5" field="19" level="1" giver="10338" finisher="10338" subtype="1" subject="핀더스 마을로">
  <Demands><Demand id="16" /></Demands>
  <RewardsEtc id="15"><Reward type="2" value="2800" /><Reward type="4" value="468" /></RewardsEtc>
</Quest>
```
QuestInfo 有 id15/id16，但 QuestTalk 直接子元素 id15/id16 的數量各為 **0**；不同表格／namespace，不可推定任務不存在。Demand 關係可作 **14→16→15 有向關係的靜態證據**，實際遊戲中何時滿足、NPC 何時發送通知、是否要求 Server 權威判定，均未在本輪得到原生 Client 封包證據。

## 資源需求
**不需追加 .stp、.xml、.lua 以完成目前的 43 筆「限定退回通知複驗」；** `Table.stp` 和 `Event.stp` 可離線供後續定向分析。若期望原版 Server 全部任務觸發和 Client 動態完整互動，仍需更深的 BIN state writer、封包接收/送出、以及條件式 runtime trace，但原版 Server 內部源碼不是 Client 逆向先決條件。