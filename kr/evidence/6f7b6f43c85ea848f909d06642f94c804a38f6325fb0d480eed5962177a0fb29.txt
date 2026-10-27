# KR T08 — 整合重審-01：任務歸屬、證據狀態、PE 映射與 S2C0007 生命周期核對

- 製作日期：2026-10-28T01:28:10+08:00 Asia/Taipei
- 作者標識：chatgpt-web roy；**本地研究稿，未 Commit／Push，亦未認領 GitHub Task**
- GitHub：`we88ec3-prog/ttr_anal_multi`，`main` 最新提交查詢為 `52452b5bc1bf0a6f7a10a7c1c83e4f3aca6a780d`（2026-10-28 01:10 Asia/Taipei 對應 GitHub 時間 2026-10-27 17:10:49Z）。這是本輪查詢的最新列表項，不聲稱取得 remote refs/heads/main 原子式引用。
- 研究對象：KR `Tartaros.bin`，長度 `12,472,320` bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` 長度 `2,594,816`，SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。兩者不是相同的 PE 映像。
- 不執行目標；不附加遊戲；不修改原檔，不呼叫目標 API；研究只作靜態讀取。GitHub 文件為外部整合證據，與本次第一手 bytes 區別。

## 0. 重要結論與研究界線

1. GitHub `kr/tasks/T08/task.json` 的正式 T08 = **實體生成與移除**；`scope=0007 建立、登記、移除的資料介面；不制定生成時間或決策規則`，`owner=null`、`state=unclaimed`、`dependencies=[T02,T06,T07]`。Project `03` 長期包含資源、Binding、場景控制/B queue 等較廣泛主題，僅能作為待審核 cross-task 原稿，不直接以 T08 正式 owner 身分改 catalog。
2. 原檔 `Tartaros.bin` 是 **PE32 MZ/PE 映像**而不是只含 .text 的 flat dump。標準 PE 映射 `.text` VA `0x401000`→raw `0x400`；歷史 flat 算法 `VA-0x401000` **不等同 PE VA→file offset**。同一標籤 A 的兩處 bytes 不同，這不是純粹文字上的 offset 歧義。
3. 一組重要反例：`.rdata` 候選 vtable `0x00C4F6C0` 以標準 PE rdata 映射取指標，其 `0x007A8E10` 與 `0x007A3920` **在標準 PE .text 映射讀到正常函式入口候選**；用歷史 flat 映射讀則落在指令中途。此前「中途指令」反證不能直接套用到 vtable 正式 VA。**這支持 vtable 指標遵循標準 PE VA；不等於已完全驗證 vtable 對象或完整 ABI。**
4. 反之，歷史 `0x007A5050`、`0x007A67C0`、`0x004CA860`、`0x004E1360` 的保存 flat 起點是典型 x86 函式序言；在 PE VA 同名位置不是相同入口。若確實取自對此同一 BIN 的 flat raw bytes 並按 `0x401000` 起算，該**物理位置的標準 PE VA 應為歷史標籤減 `0x400`**（僅限 `.text`、此來源排列、無其他重定位視角的情況），因此不能直接以歷史標籤和 PE vtable entry 比較。需要以函式內 call immediate 和 bulk 函式 bytes 進一步固定各原稿所採用的地址空間。
5. 本工作包已進行正式 T08 `S2C0007` 的來源復核與靜態 bytes 對照；**尚未完成整條建立→登記→移除鏈的獨立逐分支機器碼重放**。尤其移除路徑及 server authority 仍是缺口，不把來源描述稱作本輪新的完整原生驗收。

## 1. 實際閱讀的規範與 repo 入口

Project：`02-PROJECT-SHARED-INSTRUCTIONS.md`、`03-PROJECT-T08-INSTRUCTIONS.md`、本次 `04-T08-NEXT-CHAT(5).md`。
GitHub main：`AGENTS.md`、`HANDOFF.md`、`README.md`、`kr/tasks/T08/README.md`、`kr/tasks/T08/task.json`、`shared/CLIENT-MODIFICATION-POLICY.md`、`shared/targets.json`、`shared/source-review-status.json`、`shared/integrations/T01-20261027-05/README.md` 及兩輪 resolutions、T01-05 accepted-claims/pending、T08 原版生成證據。`shared/catalog.json` 由 fetch 返回空文字（大型檔讀取限制），**本輪未可靠解析其實際內容**；不能宣稱已逐 entity 核對 catalog。尚未逐項下載 T01-04 全部 accepted-claims 或 bulk functions，列為交付缺口。

GitHub 參考入口：
- https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/AGENTS.md
- https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/kr/tasks/T08/README.md
- https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/kr/tasks/T08/task.json
- https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/shared/source-review-status.json
- https://github.com/we88ec3-prog/ttr_anal_multi/tree/main/shared/integrations/T01-20261027-05

不可將「存在於 kr-temp-roy」「source SHA 一致」「整合 accepted-claims」「本次原始 bytes 驗證」混為同一級別。

## 2. 任務與來源歸屬矩陣

| 技術主題 | 正式 T08 可處理部分 | 外部權責／限制 | 本輪級別 |
|---|---|---|---|
| S2C0007 row 解析、type1 對象建立 | 是，實體生成資料介面 | 封包拆框 T02；場景條件 T07 | 已保存部分原生觀察，本輪未完全復核 |
| actor ID map 登記、重複鍵與移除 | 是，需定向追 4DFF30 與逆向 remove caller | 登記容器 helper 可能共用，先核對 catalog owner | 部分來源觀察，移除未知 |
| S2C000A owner／slot | 只引用與生成相關界線 | 操控/控制器並非怪物生成決策證據 | 部分來源觀察 |
| 怪物 HP、固定座標、波次／策略 | 不應推定原生規則 | fixture/伺服器規則，需要 T06/T07 等協調 | AI 替代或未知 |
| CMonster/AvatarBase 基礎構造 | 與建立直接相關的部分引用 | 共用物件／資源不得重新登記自己主責 | 需審核 |
| 資源 Binding、B queue、視域更新 | 僅當 T08 生成直接依賴時引用 | 可能跨任務，需要協調 catalog | 歷史廣義研究，未整體驗收 |

未修改 `task.json`、owner、`shared/catalog.json` 或任何其他 Task 原稿。

## 3. 整合結論的分級矩陣

| 項目 | 整合記錄／原始狀態 | 本輪處置 |
|---|---|---|
| T01-20261027-05 accepted-claims 關於 7BDF90/7BE0F0 binding lifecycle | `部分確認`；保存報告比對、非獨立 whole-function replay | 保留，非正式 T08 生成主鏈的完成證明 |
| 7BD8D0 resource+20 reader | `部分確認`；T08-093 補舊未知 | 保留，但 resource+20 不能硬命名動畫長度 |
| 7A87D0/7A86B0/75A6F0 active-list transfer | `部分確認` | 不自動等同 actor/monster register |
| T08-098/099 名稱管理 0x8C 與 binding provider 區別 | T01-04 更正 `C-T01-20261027-04-name-registry` | 接受更正界線，不混合相鄰全域 |
| T08-129 callback+0C/manager+98 owner 線 | T01-04 `C-T01-20261027-04-kb-stale-owner` 限定 | 舊 KB「完全未知」與新原稿均保留，未按名義決定哪條正確 |
| T08-129、130、141、149～152 映射／vtable ABI | T01-04 `C-T01-20261027-04-mapping-conflict`，T01-05 pending 映射未解 | **新原始 bytes 證實混用兩種地址座標，明確提供 vtable 反例**，不把全 ABI 升為已確認 |
| 直接 DWORD/xref 零命中 | T01-04 `C-T01-20261027-04-negative-scans` | 只能說當次掃描條件零命中，不能推出無間接 caller |
| 所有 105 份 source-only 報告 | `source-sha-and-bounded-content-audited`，`whole_report_semantic_reviews_complete=0` | 有限內容處置；非整份原生語意驗收 |
| S2C0007 row 26 bytes 與怪物建立 | `kr/evidence/6ef16...` 保存的原版局部路徑 | 來源層部分確認；本輪二進位錨點對照，不擴大成功範圍 |
| 普遍移除、owner 權威、spawn 時機 | 正式 T08 README 保留缺口 | 尚未驗證 |

`source-review-status.json` 明確規範 per-source bounded review 不變更 bulk whole-function review status。T08-129/130/141/149～152 的逐份 SHA 對應，必須再將 GitHub 詳細 source list 與各原稿 SHA 做集合比對；本輪未做完，不捏造單份通過狀態。

## 4. PE 原始標頭、映射與不同地址空間

### 4.1 第一手檔案

`Tartaros.bin` PE offset `0x120`，machine `I386`，image base `0x00400000`，AddressOfEntryPoint RVA `0x4978E6`，SizeOfImage `0xC44000`。

| section | VA start | VirtualSize | PointerToRawData | SizeOfRawData | 權限 flags |
|---|---:|---:|---:|---:|---:|
| .text | 0x00401000 | 0x007D01F0 | 0x00000400 | 0x007D0200 | 0x60000020 |
| .rdata | 0x00BD2000 | 0x0018E07C | 0x007D0600 | 0x0018E200 | 0x40000040 |
| .data | 0x00D61000 | 0x002873D8 | 0x0095E800 | 0x0022B800 | 0xC0000040 |
| .rsrc | 0x00FE9000 | 0x0005AF58 | 0x00B8A000 | 0x0005B000 | 0x40000040 |

`Tartaros.exe` 為不同且小得多的 PE32：image base `0x400000`、`.text` VA `0x401000`、raw `0x400`、raw size `0xC5600`、`.rdata` VA `0x4C7000`。因此不能用 EXE 同名地址到 BIN 之大 VA，二者不是互補區段的可直接拼合證據。

標準映射：`PE_raw(A) = section.PointerToRawData + (A - (ImageBase + section.VirtualAddress))`。歷史 flat 算法 `.text: flat(A)=A-0x401000`。**對 .text：PE_raw(A)=flat(A)+0x400**。

### 4.2 可重現錨點對照

每一列為「**同一地址標籤 A**」在兩種算法算出的本機 BIN byte 前12個位元組，並非宣稱二者是同一函式。

| 歷史地址標籤 A | PE raw | 依 PE 讀 bytes | Flat raw | 依 Flat 讀 bytes |
|---|---:|---|---:|---|
| `0x00401000` | `0x400` | `83 be e0 00 00 00 10 72 0f 8b 86 cc` | `0x0` | `4d 5a 90 00 03 00 00 00 04 00 00 00` |
| `0x004AE4D0` | `0xAD8D0` | `55 8b ec 83 e4 f8 6a ff 68 db 0c 94` | `0xAD4D0` | `05 00 00 80 4d 4b 00 89 88 28 05 00` |
| `0x004D1710` | `0xD0B10` | `55 8b ec 6a ff 68 b9 08 91 00 64 a1` | `0xD0710` | `70 03 00 00 00 74 09 50 6a 01 51 e8` |
| `0x004DFF30` | `0xDF330` | `55 8b ec 83 ec 10 53 8b 5d 08 56 57` | `0xDEF30` | `55 8b ec 51 8d 45 08 50 8d 4e 38 8d` |
| `0x004C6E50` | `0xC6250` | `55 8b ec 83 ec 08 56 89 47 04 89 45` | `0xC5E50` | `76 8b 4e 08 80 79 28 00 75 16 88 59` |
| `0x004AF920` | `0xAED20` | `55 8b ec 83 ec 14 53 56 8b 75 08 8b` | `0xAE920` | `30 33 cc e8 d9 1a 3e 00 8b e5 5d c2` |
| `0x004A11B6` | `0xA05B6` | `e8 75 ed 03 00 01 3d 04 de f7 00 83` | `0xA01B6` | `30 00 8b 4c 24 10 64 89 0d 00 00 00` |
| `0x004AA222` | `0xA9622` | `e8 09 5d 03 00 8b 4c 24 18 64 89 0d` | `0xA9222` | `08 75 0b 8b c8 8b 40 04 80 78 11 00` |
| `0x004AEC03` | `0xAE003` | `e8 28 13 03 00 83 7b 0e 00 0f 84 86` | `0xADC03` | `24 1c e9 0d 01 00 00 68 2c 04 00 00` |
| `0x004AF4F7` | `0xAE8F7` | `e8 34 0a 03 00 83 c7 18 ff 4c 24 18` | `0xAE4F7` | `ff 8d 4c 24 30 51 c7 84 24 4c 05 00` |
| `0x004B2F83` | `0xB2383` | `e8 a8 cf 02 00 83 cf ff f6 05 a4 d9` | `0xB1F83` | `3b d3 0f 86 22 01 00 00 8b 7d 08 83` |
| `0x007A5050` | `0x3A4450` | `7e 08 e8 11 c2 0e 00 83 c4 04 3b c7` | `0x3A4050` | `55 8b ec 6a ff 68 63 79 90 00 64 a1` |
| `0x007A67C0` | `0x3A5BC0` | `d9 45 fc d8 d1 df e0 f6 c4 05 7a 04` | `0x3A57C0` | `55 8b ec 6a ff 68 76 bd 92 00 64 a1` |
| `0x004CA860` | `0xC9C60` | `b4 00 00 00 88 81 bc 00 00 00 c3 cc` | `0xC9860` | `55 8b ec 6a ff 68 20 89 90 00 64 a1` |
| `0x004E1360` | `0xE0760` | `c3 cc cc cc cc cc cc cc cc cc cc cc` | `0xE0360` | `55 8b ec 83 ec 0c 56 8d 75 f8 33 d2` |
| `0x007A8E10` | `0x3A8210` | `55 8b ec 83 ec 0c 8b 45 08 d9 81 e0` | `0x3A7E10` | `00 00 00 de d9 df e0 f6 c4 41 7a 41` |
| `0x007A3920` | `0x3A2D20` | `85 c9 74 09 8b 01 8b 50 08 6a 01 ff` | `0x3A2920` | `c4 04 3b c2 74 2e 8b 4e 04 89 08 8b` |
| `0x007BDF90` | `0x3BD390` | `55 8b ec 6a ff 68 b6 8a 91 00 64 a1` | `0x3BCF90` | `04 d8 63 40 8b 4e 08 8b 11 8b 42 1c` |

重要性：`0x7A5050` flat 為 `55 8B EC 6A FF ...`，PE 同名為 `7E 08 E8 ...`；`0x7A67C0` flat 為 `55 8B EC ...`，PE 同名為 `D9 45 FC ...`；`0x4E1360` flat 為 `55 8B EC ...`，PE 同名 `C3 CC...`。由於歷史起點顯得像獨立函式，不可自動將兩種讀法的 caller/callee 拼接成單一 CFG。

### 4.3 vtable 指標原始資料

vtable 候選儲於 `.rdata`，採標準 .rdata 映射，例如 `0xC4F6C0 -> 0x84DCC0`、`0xC0760C -> 0x805C0C`。下表各 target 的 PE 讀取與 flat 讀取可直接比對。

| table/slot | 指標值（小端 DWORD） | 指標值按 PE .text 起點 bytes | 按歷史 flat 起點 bytes |
|---|---|---|---|
| `0x00C4F6C0+0x0` | `0x007AAA90` | `83 e9 0c e9 58 a5 ff ff cc cc cc cc` | `20 10 8b 3f 72 0c 8b 4e 0c 51 e8 6d` |
| `0x00C4F6C0+0x4` | `0x007A8310` | `55 8b ec 83 e4 f8 83 ec 4c a1 20 1f` | `83 bf ac 00 00 00 00 8b 45 08 d9 00` |
| `0x00C4F6C0+0x8` | `0x007A8E10` | `55 8b ec 83 ec 0c 8b 45 08 d9 81 e0` | `00 00 00 de d9 df e0 f6 c4 41 7a 41` |
| `0x00C4F6C0+0xC` | `0x00C7F9F4` | `非.text` | `非.text` |
| `0x00C4F6C0+0x10` | `0x007AAA40` | `8b 41 0c 85 c0 74 06 50 e8 c3 fe ff` | `00 e8 c6 6b 0e 00 8b 4d 08 8b 41 08` |
| `0x00C4F6C0+0x14` | `0x007A3920` | `85 c9 74 09 8b 01 8b 50 08 6a 01 ff` | `c4 04 3b c2 74 2e 8b 4e 04 89 08 8b` |
| `0x00C4F6C0+0x18` | `0x007A3950` | `55 8b ec f6 45 08 01 56 8b f1 c7 06` | `8b e5 5d c3 8d 45 fc 50 8d 4d f0 89` |
| `0x00C4F6C0+0x1C` | `0x007848C0` | `33 c0 c2 04 00 cc cc cc cc cc cc cc` | `e5 5d c2 08 00 8b 45 08 8b 4b 0c 39` |
| `0x00C0760C+0x0` | `0x004CA660` | `8b 49 0c 85 c9 74 08 8b 01 8b 10 6a` | `58 04 75 05 89 78 04 eb 0b 39 1e 75` |
| `0x00C0760C+0x4` | `0x007A3920` | `85 c9 74 09 8b 01 8b 50 08 6a 01 ff` | `c4 04 3b c2 74 2e 8b 4e 04 89 08 8b` |
| `0x00C0760C+0x8` | `0x007A3950` | `55 8b ec f6 45 08 01 56 8b f1 c7 06` | `8b e5 5d c3 8d 45 fc 50 8d 4d f0 89` |
| `0x00C0760C+0xC` | `0x007848C0` | `33 c0 c2 04 00 cc cc cc cc cc cc cc` | `e5 5d c2 08 00 8b 45 08 8b 4b 0c 39` |
| `0x00C0760C+0x10` | `0x6C6C6143` | `非.text` | `非.text` |
| `0x00C0760C+0x14` | `0x43206465` | `非.text` | `非.text` |
| `0x00C0760C+0x18` | `0x69736142` | `非.text` | `非.text` |
| `0x00C0760C+0x1C` | `0x6A624F63` | `非.text` | `非.text` |

對 `0xC4F6C0+8`：DWORD `0x007A8E10`，在 PE raw `0x3A8210` 為 `55 8B EC 83 EC 0C ...`；其 flat raw `0x3A7E10` 則為 `00 00 00 DE D9...`。對 `0xC4F6C0+0x14`：DWORD `0x007A3920`，PE raw `0x3A2D20` 為 `85 C9 74 09 ...`，flat raw `0x3A2920` 則是 `C4 04 ...`。這兩個 byte 級錨點反駁「只因 flat 中途指令便否定 vtable target」的論證。

`0xC0760C` 讀出的 DWORD `0x004CA660、0x007A3920、0x007A3950、0x007848C0` 仍須回查 object vptr store 與 RTTI；緊接數值可能混入字串資料，未證 table 長度。**此處只確認 raw dword 與候選目標 byte，不聲稱已重建完整 vtable 或類別。**

### 4.4 映射推論與待核證的全局關係

設歷史 `FlatLabel=A` 指向 bytes raw=`A-0x401000`，則該位置若在 `.text` 有效原始資料，PE VA=`A-0x400`。這不是去修正 `.rdata` 內真實 DWORD 的操作；指標的 VA 值需保留。不自動套用到其他 section 或反編譯項目的分析器內部地址。

後續關鍵驗證：從 bulk 取得 `0x4AE4D0`、`0x4DFF30`、`0x7A5050` 函式 machine-byte 證據，按兩種基準各解碼 direct `E8 rel32`，比對保存 caller→callee 絕對地址與 vtable target；確認 label 轉換是否在一整個函式區間都成立。任何相對 call 目標的地址都取決於選用的起算 VA，不能混合算式。

## 5. 正式 T08 的 S2C0007 建立／登記功能鏈：來源審計

本節技術數據引用 GitHub 保存的 `kr/evidence/6ef16f451f942d2e828a1b6936b466332736d7dc75fa0152fcbb6289863902dd.txt`，**尚非本輪逐分支完全重新反組譯**。

原版索引描述 `S→C 0007` 的接收函式標籤 `0x004AE4D0`，正常返回 `0x004AED80`，失敗支 `0x004AED83`；`0x004AED90` 起是 jump table data，不能誤解作自然順序的新函式。前置2 bytes，row 26 bytes；依各 row 的 actor ID 低位元組分流。已保存 type1 分支呼叫 `0x004D1710`，暫稱 CMonster 建立。其後設定 transform/model 及加入共用 actor map；manager 間接與腳本建立等共用 caller 仍須依映射重核。

| Row relative offset | 型別 | 已保存的作用與限制 |
|---:|---|---|
| 0 | WORD | actor ID；低 byte 參與 type switch |
| 2 | BYTE | 資源索引第2欄，計算減一；不能獨立命名 |
| 4 | WORD | 模型/資源編號 |
| 6, 10 | float, float | 水平座標，進入 actor virtual +0x44 |
| 14 | float | 提供 actor virtual +0x5C；語意未完成 |
| 18 | DWORD | 寫 actor+0x9C 的 owner 值；不等於 AI 主控權 |
| 22 | BYTE | 朝向，actor virtual +0x58 |
| 23 | BYTE | type-specific 值；monster +0x424、值4另影響+0x428 |
| 24 | BYTE | actor+0x90 faction |
| 25 | BYTE | status component virtual +0x8 的參數 |

**建構→登記候選資料流（保存來源，未獨立升級）**：

```text
network S2C0007  (T02 packet framing responsibility)
 -> receiver 0x004AE4D0 : header(2), rows(26)
 -> row.actor_id low byte discriminator
 -> type1 : 0x004D1710 / CMonster candidate
 -> configure actor position and resources / type flags / owner
 -> 0x004DFF30..0x004DFFA9 : GameInfo+8 map using actor+4 WORD
 -> owner!=0 : optional player-current-actor update via 0x004C6E50..0x004C6E9C
 -> 0x004AE69D auxiliary 0x48 bytes -> 0x004AE77A -> 0x0056F5C0
    -> global 0x00FDF3C4 minimap marker list, NOT monster AI scheduler
```

保存 `0x4DFF30` 五個**直接 caller 候選**：`0x4A11B6 / 0x4AA222 / 0x4AEC03 / 0x4AF4F7 / 0x4B2F83`；僅為舊索引，不是完整 XREF 證明。傳遞 GameInfo+8 map 的具體 owner/type 仍需按標準 PE VA 對照。`0x4D1060` 的 CEventObject 分支不得混同 CMonster。`0x4AE69D` 的0x48小地圖標記與 actor 生存/移除是兩種生命週期，不能當作怪物控制佇列。

### 5.1 S2C000A 不等於怪物 AI

來源 `0x004AF920..0x004AFAE7`：header 7 bytes（+2 owner DWORD，+6 signed BYTE row count），row 每4 bytes（actor WORD、related WORD）。本機 owner 相關分支重設槽位並呼叫 controller virtual +4/+8/+10；首筆 actor+0x98=1，後續為0，actor+0x9C=owner。保存索引明言 **沒有證據顯示普通怪物由此取得獨立 AI 決策控制器**。此路徑可作生成後登記對照，但不屬 T08 的怪物 AI 規則設計。

### 5.2 移除：源證據不足，不虛構完整逆鏈

目前讀到 `kr/evidence/3888059...txt` 保存 `0x005666A0` Lua `DeleteObject` registration wrapper，其末尾 `ret 4`；`kr/evidence/a607cd9...txt` 僅 `0x00476430 ret 4`。**一個 wrapper 與 no-op 不足以證實 actor map erase、指標引用減少、物件最終 destructor、minimap marker free 及 server-driven removal 的全局順序**。`DeleteAllObject`／`0x4DFF30` 逆向 erase 尚待逐函式 + 原始 bytes 驗證。不能因登記表有 key 就推導它何時刪掉。

核心未解：（1）rows count 權威及 payload bounds checks；（2）重複 actor key 的行為；（3）哪種封包/腳本導致 remove；（4）GameInfo+8 erase 和物件 destruct / marker cleanup 的先後；（5）owner 權威及斷線事件；（6）每條候選函式的地址標籤轉換與獨立 caller/callee proof。

## 6. 資料流 C++ 式偽碼（嚴格界線）

下列是**由保存來源重建的接口模型，不是逐指令等價偽碼**：

```cpp
struct SpawnRowCandidate {
  uint16_t actor_id;      // +0
  uint8_t resource_index2;// +2; semantic unknown
  uint8_t unknown3;       // +3; do not fill invented semantic
  uint16_t model_id;      // +4
  float x;                // +6
  float z;                // +10
  float factor;           // +14
  uint32_t owner;         // +18
  uint8_t facing;         // +22
  uint8_t type_extra;     // +23
  uint8_t faction;        // +24
  uint8_t status_arg;     // +25
}; // packed; 26 bytes, provenance: saved bounded evidence

void receive_0007_candidate(const uint8_t* payload, size_t length) {
  // Header(2): its precise two-byte semantics / count domain NOT established here.
  // Require independent bounds & count check; not reproduced.
  for (/* each bounded 26-byte row; iteration derivation still TODO */) {
    // low_byte(actor_id)==1 -> candidate CMonster construction;
    // set coordinates/model/owner/faction/status via actor interfaces;
    // register actor ID -> actor* in GameInfo+8;
    // minimap marker via separate manager;
    // failure cleanup and duplicate ID handling remain unknown.
  }
}
```

此偽碼刻意不表示拆解器已完全解析 all switch branches，不宣稱伺服器生成決策。結構 row+3 的未知位元組是 row 26 bytes 佈局必然空位，但沒有給它新意義。

## 7. 自主驗證清單與下一工作包

### 本輪實際完成
- [x] 三份專案文件原文閱讀。
- [x] 遠端 GitHub 最新提交列表重新查詢；不是使用舊交接 SHA。
- [x] 正式 T08 title/scope/state/owner/dependencies 檢查。
- [x] policy、T01-04/T01-05 主要更正與 T01-05 部分 accepted claims 檢查。
- [x] BIN、EXE 真實檔案 SHA256、MZ/PE headers/sections 自主解析。
- [x] 多組 `.text` PE vs flat bytes 對照、兩組 `.rdata` 候選 vtable 真實 DWORD 與函式 entry 比對。
- [x] `S2C0007` 已保存正式證據及部分 DeleteObject 來源定向對照。
- [ ] `shared/catalog.json` 全解析、正式方法 owner matrix。
- [ ] `source-review-status.json` 中重點 T08 129/130/141/149..152 全 SHA 集合核對。
- [ ] 完整 `kr-bulk-roy` 指定函式原始碼與 stored provenance 對照。
- [ ] S2C0007 每條 case / bounds / object-init / map insertion 真正逐指令二次驗證。
- [ ] 移除鏈：find/remove/erase/destructor/minimap marker/server opcode 的閉環。

### 下一個大型批次（建議）

**T08-整合重審-02：固定單一地址座標系後，沿 `0x004AE4D0` (S2C0007) → type1 ctor `0x004D1710` → actor map `0x004DFF30` → 相反路徑 remove，逐指令追 bounds、key collision、owner、ref lifetime。** 同時指定 T02 為 framing 分工、T07 為生成時機／場景上下文分工。每個函式必記 (1) PE VA (2) raw offset (3) bulk label (4) bytes hash/前後 bytes (5) caller & callee (6) 可信程度。若分析器採 flat+0x400 label，先做映射座標轉換並保存原名，不任意覆寫 source。

## 8. GitHub 交付狀態

研究稿僅存在使用者可下載的本機 Markdown；沒有 git clone 成功（環境 `git ls-remote` 無法 DNS resolve），GitHub 內容透過已連接的 GitHub 讀取介面取得。沒有建立分支、沒有改動遠端、沒有 Commit 或 Push。本次仍未透過 GitHub 整合者正式驗收。此文檔若日後推送，應先查最新 remote HEAD、owner、catalog 權限及重複 SHA，並維持自己的研究路徑。