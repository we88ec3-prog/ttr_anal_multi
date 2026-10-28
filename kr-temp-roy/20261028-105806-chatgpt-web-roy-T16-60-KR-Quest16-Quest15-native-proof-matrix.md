# KR T16-60 — 教學末端、Quest16→Quest15 原生證據合併與下一段界限

- 日期：2026-10-28T10:58:06.857560+08:00；研究者：`chatgpt-web roy`，KR T16 only。
- 唯讀來源：`Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。PE32/i386 `.text` VA `0x401000`，raw `0x400`；`.rdata` VA `0xBD2000`，raw `0x7D0600`；`.data` VA `0xD61000`，raw `0x95E800`。
- GitHub repo：https://github.com/we88ec3-prog/ttr_anal_multi，前段 T16-53～56 已提交；此批不修改其他 Task／catalog／owner，不研究 TC；不啟動程式。
- disassembly：`objdump -D -Mintel --start-address=... --stop-address=... Tartaros.bin`；局部片段不保證全函式 CFG，但已按已知入口與連續指令核對。

## 本批新確認的架構邊界
1. `HasQuest`／`HasCompletableQuest`／`HasScenario` 被 `0x72E2E0` 當作名稱找節點，再把節點交 `0x53FEB0` 轉換／寫入本地記錄；這**反駁**「字串引用本身就是 server 完成判斷器」的過度歸因（T16-57）。
2. `RequestStartScenario` 由 `0x4AB8F8` 註冊 `0x4AC9E0` native callback；`0x4ACB70` 搬運參數／可能間接呼叫，不能僅依命名認定完成伺服器 ACK（T16-58）。
3. Quest reader 的 `0x504740`／`0x505570` 由同一 caller `0x5043E5` 連續呼叫（T16-59），屬 table 初始化而非 server state writer 證據。

## 逐節點端到端矩陣
| 節點 | 原始可驗證 | authority | 狀態 | 下一證據 |
|---|---|---|---|---|
| Lua Part1→Part2 | T16-46 proto8、proto5/6 | client | 已確認本地協程流 | callback arguments + scene step |
| RequestStartScenario | T16-58 native callback address | 未追到 server | 部分確認 | 0x4ACB70 delegated callee／封包 |
| scenario14 合法成功 | T01 待辦，沒有勝利回報原件 | server/T14 | unknown | server result/packet |
| 返回 TUTO | 跨 T07 交接 | scene/server | unknown | 正式 scene transition ACK |
| Quest16 complete | 無原版 writer/ACK | server/unknown | unknown | QuestInfo id16 + server state writer |
| Quest15 available | 無原版 id15 predecessor | server/unknown | unknown | QuestInfo id15 + quest ACK |
| relogin persistent | 無 role-scoped snapshot | T15/server | unknown | T15 state reader/writer |

## 禁止推論
- 本地名字表中的 `HasQuest` 不是可直接套用為 Lua 全域 query，更不能當 server DB persisted bit。
- `IsScenarioEnded` (client) ≠ game victory/success。
- T01 resource audit 的 manifest/SHA、歷史 fixture／patched client 不等於 server-native flow。
- 沒有原始資料不得填 Quest ID predicate、NPC／zone 或官方 reward。

## 精確接棒
- **下一段 T16-61**：沿 `0x4ACB70` 的 indirect call 分支逆向 callback 實參，查 `0xFE187C` writer；以 original bytes／CFG 核對。
- **下一段 T16-62**：找 `0x53FEB0` 的消費欄位與 `0xFE18DC` 資料樹語意，不混同別處的名稱容器。
- **外部仍需**：`Event/TutorialBase.lua` 原 chunk SHA `26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744`，`Table/QuestInfo.xml` SHA `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`；原生 server Quest16 writer、Quest15 acceptance、T14/T07 result、T15 persistence 均缺。
- 禁止在無必要時改 client；原版 `005F type6` 不等於 fixture 補丁；KR-only；原始唯讀。
