# KR T16-56 — Quest16→Quest15 原版 writer／notification 未閉合鏈與下一批可重現接棒

- 研究時間：20261028-103816 Asia/Taipei；`chatgpt-web roy`；**KR only**。
- GitHub：https://github.com/we88ec3-prog/ttr_anal_multi，目標 `main`，此份僅專屬研究原稿，不更改 catalog/owner。

## 原始來源與證據級別
- 原始檔 `/mnt/data/Tartaros.bin`，實際本輪重算 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes；唯讀。
- `Tartaros.exe` 不執行；不使用 TC。
- GitHub 已提交原稿 T16-45～52 與 T01-20261028-06 的來源稽核為交叉脈絡，不把曾有的推測列為新證據。
- 此處 direct CALL 搜尋是 `.text` raw 位元組掃描 `E8 rel32`，可能有 embedded data／非指令邊界假陽性，需 CFG 進一步確認。

## 本批實測新增證據整合
- `0x00504740` 直接 CALL 位元組命中：`0x005043E9`；仍需 CFG 核實。
- `0x00505570` 直接 CALL 位元組命中：`0x005043EF`；仍需 CFG 核實。
- `0x006F4A50` 直接 CALL 位元組命中：`0x0048B11D`, `0x0048B12C`, `0x0048B13B`, `0x0048CA11`, `0x0048CA4D`, `0x004A89B6`, `0x004A8A36`, `0x004A8B64`, `0x0055D7C2`, `0x00560796`, `0x005607A2`, `0x005607AE`, `0x005607BA`, `0x00561C7D`, `0x005659D9`；仍需 CFG 核實。
- `0x006F4DD0` 直接 CALL 位元組命中：`0x004A8A46`, `0x004A8B74`, `0x005615D8`；仍需 CFG 核實。

## End-to-end 狀態矩陣（嚴格不填猜測）

| 邊界 | 本批證據 | 權威 writer | 實際驗收 |
|---|---|---|---|
| KR Tutorial script-load | native direct call xrefs＋既有 Lua bytecode | client loader | 部分確認；參數未完全還原 |
| Tutorial Part1/2 本地同步 | T16-46 Lua opcode/coroutine | client/controller | 局部原生已確認 |
| `RequestStartScenario` → stage completion | Lua 常數與本地介面 | server/T14 | 缺 scenario ID、server result |
| scenario14 合法結算、回到 TUTO | T01 NEXT-QUERIES 研究待辦 | server/T14、T07 | unknown |
| Quest16 marked completed | 本批未取得特定 server writer / ACK | unknown | unknown |
| Quest15 可接前置 | QuestInfo id15/16 原始元素缺失 | unknown | unknown |
| 重登後 Quest 狀態 | 未讀到 server role-scoped reader/store | T15 | unknown |

## 研究限制與避免誤判
- 沒有抓封包或執行遊戲；本批新增的是 KR PE 原始 bytes 層級 xrefs，不是可玩性驗收。
- `TutoQuest`、`HasQuest`、`HasCompletableQuest`、`HasScenario` 的 native literal references 只能支持**client-facing 解析／判斷候選**，不得推論 server DB 欄位、response opcode 或完成閥值。
- 原版 `005F type6` 與歷史 tutorial client patch 不可混同。
- 未觸碰 TC、其他 Task、catalog、owner、原始檔案。

## DEFERRED-LOCAL-RESOURCE 接棒契約

1. `Event/TutorialBase.lua`：SHA `26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744`；需要完整 Lua 5.1 raw chunk 與 proto/instruction、callback、arguments。
2. `Table/QuestInfo.xml`：SHA `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`；需要 id 15/16 原件及 schema；阻塞任務前置與 Quest namespace。
3. KR 原始 server quest-writer/Quest16 notify/ACK 封包：SHA unknown；阻塞 server-authoritative completion。
4. T14 scenario14 winner/result and T07 TUTO return authoritative event：來源另核；只在 T16 記交接，不取代主責分析。
5. T15 role-scoped persistent quest snapshot reader/writer：來源另核；阻塞 reload/relogin recovery semantics。

## 下一批具體切入點
- 在 BIN 的 `0x0053FD85`／`0x0053FD93`／`0x0053FDA3` 周邊解析完整函式邊界，分辨 Lua condition-binding vs quest state reader。
- 對 `0x004AB8F9` 指向 `RequestStartScenario` 字串的引數建立 Lua-binding 到 native handler 的證據鏈。
- 查 `0x00504740`／`0x00505570` 的 caller 中實際 table loads；若能取得 QuestInfo，直接建立 id15/16 欄位到 consumer 的 xref 矩陣。
