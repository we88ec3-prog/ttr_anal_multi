# T16-49 — KR Quest／Tutorial 來源可及性重檢與 PE 位址證據

- 研究時間：2026-10-28；研究者 chatgpt-web roy；KR T16 only。
- 原始 KR BIN：12472320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 原始 EXE：SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；本批次未啟動或修改檔案。
- 來源優先：本機原始 BIN/PE、已核對的 GitHub main 和 T16-45～48。
- 注意：以下機器碼中的函式語意是有限範圍判斷；沒有 server source/封包便不宣稱 server 端任務狀態。

## PE section 直接解析

| section | RVA | raw ptr | raw size |
|---|---:|---:|---:|
| `.text` | RVA `0x00001000` | raw `0x400` | rawsize `0x7D0200` |
| `.rdata` | RVA `0x007D2000` | raw `0x7D0600` | rawsize `0x18E200` |
| `.data` | RVA `0x00961000` | raw `0x95E800` | rawsize `0x22B800` |
| `.rsrc` | RVA `0x00BE9000` | raw `0xB8A000` | rawsize `0x5B000` |

## 已知關鍵路徑 BIN 原件重新讀取

- `0x004A89C0`：`.text`, raw `0xA7DC0`, 前32 bytes `55 8b ec 6a ff 68 7e a4 93 00 64 a1 00 00 00 00 50 57 a1 20 1f d6 00 33 c5 50 8d 45 f4 64 a3 00`。
- `0x004A8A60`：`.text`, raw `0xA7E60`, 前32 bytes `55 8b ec 6a ff 68 4c a4 93 00 64 a1 00 00 00 00 50 83 ec 08 53 57 a1 20 1f d6 00 33 c5 50 8d 45`。
- `0x004A8B90`：`.text`, raw `0xA7F90`, 前32 bytes `55 8b ec 83 ec 18 53 8b 5d 08 8b 03 56 57 68 d4 68 c0 00 6a 01 50 e8 f5 44 00 00 8b 0b 8b 09 83`。
- `0x00504740`：`.text`, raw `0x103B40`, 前32 bytes `55 8b ec 83 e4 f8 6a ff 68 3d 42 92 00 64 a1 00 00 00 00 50 81 ec 48 02 00 00 a1 20 1f d6 00 33`。
- `0x00505570`：`.text`, raw `0x104970`, 前32 bytes `55 8b ec 83 e4 f8 6a ff 68 7b 28 92 00 64 a1 00 00 00 00 50 81 ec 98 00 00 00 a1 20 1f d6 00 33`。
- `0x006F4A50`：`.text`, raw `0x2F3E50`, 前32 bytes `55 8b ec 83 e4 f8 81 ec 2c 02 00 00 a1 20 1f d6 00 33 c4 89 84 24 28 02 00 00 8b 45 08 53 56 8d`。
- `0x006F4DD0`：`.text`, raw `0x2F41D0`, 前32 bytes `55 8b ec 83 e4 f8 83 ec 14 53 56 57 8b f8 8b 37 8b 45 08 8d 5e 48 8d 48 01 8d a4 24 00 00 00 00`。

## 來源邊界及 deferred 資源

GitHub T01 source-audit 已記錄 KR `Event/TutorialBase.lua` SHA `26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744`（6 prototypes / 72 words）；`Table/QuestInfo.xml` SHA `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`（4798 children）。這只驗證來源稽核 metadata，非正文；本地已掛載 `/mnt/data` 並無這兩個資源本體、亦無原始 Event.stp/Table.stp，故 **DEFERRED-LOCAL-RESOURCE**。禁止以孩子數量填補 Quest15／Quest16 欄位。

相反地 `/mnt/data/Tartaros.bin` 存在並且 hash 符合，可繼續研究消費者呼叫鏈、header、raw offset。`Tartaros.exe` 與 BIN 是不同 SHA，不可混用同一 PE 位址映射。前段 T16-46 的 `TutorialMain.lua` opcode/proto 驗證有效，但不能因 TutorialMain.lua 被呼叫而推導已由伺服器更新 Quest16。

## 證據矩陣

| 命題 | 判定 | 缺口 |
|---|---|---|
| KR BIN header/地址映射 | 原生已確認 | 見上表 |
| KR QuestInfo 原文含 Quest16 / 15 條件 | 資訊缺失 | Resource bytes / XML nodes |
| TutorialBase 實際邏輯 | 資訊缺失 | Bytecode chunk |
| Lua 與 QuestInfo 雙來源連到 server 寫入 | 資訊缺失 | request/reply 和 writer |

本輪不改目標、不執行 Lua/EXE、不介入 TC。下一段先追原生 Lua loader，保留跨版本隔離。
