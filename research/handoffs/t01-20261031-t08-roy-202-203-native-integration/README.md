# T01 | T08-202／203 原始研究整合及獨立原生複核（2026-10-31）

## Git 來源、版本與保護

- 整合至 `main`；來源 `t08/roy/chatgpt-web`，main 基準 `5897c5058a7386686efaeb6173c8ac11bd83c78b`、branch HEAD `2fc9430028ddbfbbf2a58f7ae6a9ca6c7fdc2f8d`，compare `ahead=26, behind=0`。兩個提交為真正雙父 Merge Commit，不 force push，不新增 branch。
- 來源差異：6 篇 Markdown、2 份可重跑 Python 作者工具及 `kr/tasks/T08/README.md` 的研究進度敘述。新增研究文件原樣保存，不改 T08 主責、task.json、catalog 或舊原稿。來源身份各自登錄為 **SRC-0591～SRC-0598**（Git blob SHA 與 UTF-8 SHA256）。
- **凍結來源 SRC-0589** 精確 Git blob `1db1077f7e7c0ed9cd0de070a09daec9f9db5eb9`，本次分支與 main 相同，並未覆寫。T08 作者另建 `20261031-163734-...-provenance-addendum...` 解釋舊改寫曾造成 CI source SHA mismatch；不將此歷史錯誤視為 BIN 機器碼反證。
- T08 README 將 202 和 203 稱為作者範圍的 `FINISHED (BOUNDED_*)`，只認為**研究交付進度**，不等於 T01 `FULL-PASS`。舊有 `FAILED`、`NEEDS_FIX/READY_FOR_REVIEW/RESOLVED`、共用知識、S00 RR 一律保留。

## 真正執行的 T01 第一手檢查（非引用作者測試結果）

使用已提供的 `/mnt/data/Tartaros.bin` 原檔唯讀執行 Python `hashlib/struct`、解析 DOS/PE/COFF/section header、比較原始 machine bytes、vtable DWORD、MSVC RTTI TypeDescriptor，以及 GNU objdump 連續函式區間反組譯；沒有運行、修改或 patch 遊戲。

| 來源 | 本輪獨立 SHA256 |
| --- | --- |
| `Tartaros.bin` 12,472,320 bytes | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` |
| `Tartaros.exe` | `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f` |
| `Event.stp` | `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b` |
| `Table.stp` | `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` |

PE32 x86 `machine=0x014C`, `imagebase=0x400000`; `.text` VA `401000`／raw `400`；`.rdata` VA `BD2000`／raw `7D0600`；`.data` VA `D61000`／raw `95E800`。

**獨立執行通過的測量：72 個指定原生 instruction byte sites、8/8 Actor type jump-table entries、四個 Actor vptr 20/20 欄位與 4 個 RTTI class names、6/6 Controller vptr+44、CDoll 子介面 vptr+8、Scene::CDuelDecision vptr+30、6/6 處到 `544E80` 的 Controller deleting-destructor direct E8 rel32、`.text` 中 `0xFAB148` 小端直接常數引用 **30/30**（11 整樹重置，16 lookup，3 other）、12 個 unsigned 除26 長度邊界實例。**本輪沒有實際執行 GitHub 上兩份作者 .py；不得把作者聲稱的 113 或 59 anchors 冒充 T01 此次測數。**

## T01 有界語義判決／精確反證

| 項目 | 本輪原生有界支持 | 明確保留 |
| --- | --- | --- |
| Actor row 與分派 | `4ADD7E` 設 table+3C→`4AE4D0`（本地 index 7）；`4AE51F/22/27/29` 以除26魔數計算 `floor((L-2)/26)`，`4AE540` 將 `EBX` 移為 `R+4`，`4AED47` 每列+0x1A；jump table type 0/1/6/7 各入 constructor，2～5 診斷 | 本地 index 7 **非已證完整 wire opcode**；T02 framing/dispatch 未整鏈驗收 |
| T08-203 的 T08-201 原稿欄位勘誤 | 原始 `4AE8A2 8A 43 FD` 及有效 root 解碼為 `mov al,[EBX-3]`；因 `EBX=R+4`，type6 讀 **R+1** 而非舊說 `R+3`；`4AEB43 lea eax,[EBX+2]` 指 `R+6`；`4CAB80` 以 x87 比較有條件寫 `Actor+A0/A4` | 不確認 3D 坐標實際單位、異常 OOM / exception 完整回滾 |
| T08-202 pair 第二 pass | `5459B7..545A97` 有第二個 pair consumer；`545A86 0F B7 40 02` 讀 second WORD；**`545A93 88 5C 24 28` 為 `mov byte [esp+0x28],bl`，真正 `call edx` 是 `545A97 FF D2`**。六種已知 Controller vptr+44 均 `546EF0` | 六種已知 vptr 以外的類別、間接 callback 和 Server 實際接收／ACK 尚未證 |
| 資源清理與 H-tree | 四種 Actor 主 vtable/RTTI 對應，六處 Controller destructor 的真 E8 均指向 `544E80`；`544EE1` 對 controller+48 H-tree 操作、`544EEC` 進 payload release。區分 Actor slot14 清理與 Controller 本體析構 | 不能由此推 26/81 移除 Actor 必然析構 Controller 或完全沒有跨物件 callback |
| P+4 真讀者與 Scene | `4BD708` owner次級 P tree 查找，`4BD728` 取 `P+4` 數值ID、`4BD742` 查 Actor 主樹，`4BD766` 位置的 Scene 欄位 writer；`C070CC+30=4BD600`；原始 .text `48 B1 FA 00` 找出 30 個直接引用 | 直接 literal 完整 != 間接 alias writer/consumer 全集，亦非真畫面播放或 UAF 安全性的全局證明 |

原始 x86 關鍵局部根連續反組譯 `0x4AE4D0..0x4AE60F`、`0x4AEB0A..0x4AEC08`、`0x4CAB80..0x4CABD4` 另由 GNU objdump 重讀；不能把單點 bytes 相符等同全部 CFG／caller/callee／資料生命週期、狀態與 UI 功能全文驗收。

## 正式狀態與交接

- 本次 **R0**：八個精確新來源 `REGISTERED`，沒有冒建 `CLM-*`，沒有改歷史來源 FULL-PASS 判決。
- 本次 **限定 R2**：以上第一手指令／vtable／局部 source dataflow 有界正面支持，特定舊欄位偏移獲更正；**沒有把來源整篇/全部 claim 提升 R3、NATIVE_VERIFIED 或 FULL-PASS**。R2 記於本 T01 紀錄，R0 欄位仍保守維持 REGISTERED，後續如要萃取主張需正式建 claim IDs 和 conflict check。
- **Client 待逆向**：T02 外層真正封包 domain、完整 alias/virtual writer、繼續 T08-204 圖像／Scene 可見 consumer、異常 rollback。**Server 待開發**：spawn/despawn 時序、波次、業務決策由 S00 相容規格處理，不能稱原版算法。
- **跨 Task**：T02 封包、T06 資源、T07 場景、T14 結算。**待遊玩驗證**：實際 Client／Server 互通、視覺結果、重複/無效封包與非同步回收。
- 既有 24 個映射相關 legacy 修正及其它 `READY_FOR_REVIEW` 通知**仍待 T01 專案級逐篇複驗**；本次只是 T08-202/203 新來源整合，不能因作者段號 FINISHED 直接結案。

**整合裁決**：允許所有來源以 Git 歷史及 Git blob 原樣進 `main`，T01 本輪做了實際可重現的 BIN-first 有界 R2 檢查；T08-202 與 T08-203 的**全文 T01 FULL-PASS 未完成**。
