# T01 第三輪：T16 16 筆附錄 CFG 複驗與 KR Table.stp 資源復原
審核：ChatGPT-web roy（T01）；2026-10-30；核對時 GitHub `main` HEAD `54747b31a1c093704785d43b9c599f4bf7fb3907`。

## 結果與適用範圍
**第三輪新增 16 筆限定退回 `RESOLVED`。43 筆固定通知目前全部 `RESOLVED`，但原作者 37 篇歷史 Markdown 原稿、個別全部主張及 T16 整體並未被宣告 FULL-PASS。**
本輪僅對通知所述 appendix/指令錯位/CFG 以及需要的依存引用進行獨立複核。不得由通知 RESOLVED 推得 Quest16 完成、Quest15 接取、Server 規則、Client wire 協定或遊玩完成。

## 來源版別與原件
- 原件 KR `Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，PE .text VA `0x401000`/raw `0x400`，.text raw = VA−`0x400C00`。
- 使用者 ZIP `20261029-220621-chatgpt-web-roy-T16-T01-returns-phase3(1).zip`，SHA256 `245465cc52c9673d560a05155ce978652103b34f56fe3e7732eacf96dd7e119c`。包含 19 root JSON、28 source-to-native windows、71 筆獨立列舉的歷史 call/jmp、37 篇 per-source 修正指引。ZIP 作者自述不是驗證；T01 用 BIN 原始 bytes 重算後才採用。ZIP 為使用者附件，**未將遊戲原件提交至 GitHub**。
- KR `Table.stp`，5,248,784 bytes，SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`；本次實際解出的 XML 資源及完整 hash 見 [Table XML 稽核](TABLE-RESOURCE-AUDIT.md)。
- 前兩輪 T01 27 筆結案原稿仍在 `shared/integrations/T01-20261030-t16-followup/`、`shared/integrations/T01-20261030-t16-resource-followup/`；本批不重寫舊裁決。

## BIN-first 完整有界 root 複核
直接抽 KR BIN 原件各 root 的 bytes；檢查每條指令 VA/size/byte match，無指令重疊；相對 E8/E9/EB、7x Jcc、0F8x Jcc 的 signed offset 逐一重算，跟作者 JSON 的目的地交叉核對。直接 CFG 的 edge origin、branch destination、fallthrough、正常終端、是否 root 可達均核對。

結果：**19 root，4,464 instructions，4,905 edges，1,046 個直接 call/jmp/jcc opcode；0 bytes mismatch、0 overlapping、0 invalid target／edge、0 missing reachable root。** 其中條件跳轉 460、無條件跳轉 103、終止指令 23。對 `0x504D9E` indexed-jmp `[ecx*4+0x505554]` 另外在 BIN 取六個 DWORD：`0x504DE2`、`0x504DF4`、`0x504DEB`、`0x504DFD`、`0x504E06`、`0x504E0F`，均與 six-way indexed edge 一一對應。

### 例外尾端的精確限定
`0x50554C: E8 DF 85 37 00 call 0x87DB30` 後緊接對齊與跳轉表資料（`0x505551: 8D 49 00`、`0x505554` 6 個 DWORD）。原生 `0x87DB30` 下游以 `call 0x89C9F0; int3` 收尾；此為無正常落入跳轉表的例外／不可返回呼叫路徑。**不能**僅為了每條 CALL 都有 fallthrough，創造 `0x505551` 為正常執行路徑。此特殊截斷已作為獨立 CFG 稽核例外；不能將其當一般已完成函式的正常返回證據。

## 精確 16 筆固定通知與原始來源追溯
| 通知 | 歷史原稿 Git blob | 作者獨立勘誤 Git blob | 裁決 |
|---|---|---|---|
| `T01-RETURN-T16-001-c26518b1` | `ec933435d90f08710ffe594a0b5ac68e3d012f40` | `ad7031509bd926aa9440dae2afaaf6f331e3b539` | appendix-CFG `RESOLVED` |
| `T01-RETURN-T16-009-c26518b1` | `d6bbfe7ac55f07308093cc2ca2f0ad021bed37e5` | `aae80b9e5f3ec116ea8e8c8f6c3f717308e3eff7` | appendix-CFG `RESOLVED` |
| `T01-RETURN-T16-020-c26518b1` | `342da9acb11bfe29720419d8a7c615f2296c139a` | `6c18eadc765bb68c8314ca7dbf5a426bdaf7d419` | appendix-CFG `RESOLVED` |
| `T01-RETURN-T16-021-c26518b1` | `f6ca97b7c25a0dd957305d98b929e3467253805c` | `bfa8076bcd1e372c2e28f940c98a6e7231eb7437` | appendix-CFG `RESOLVED` |
| `T01-RETURN-T16-022-c26518b1` | `138c49cbd53e41169c386c9f1d7e826211fec283` | `f065e2c8458355edcd12c7ad7c493e2dc692caf5` | appendix-CFG `RESOLVED` |
| `T01-RETURN-T16-029-c26518b1` | `72d9faebfa9bf65628a57ab0f0d57e67d764a4c4` | `5925836868b7f2d374f6a0bf81565b6cd61f900c` | appendix-CFG `RESOLVED` |
| `T01-RETURN-T16-030-c26518b1` | `bc12a16b71a596a32ceeafe47795e892fb2b38f5` | `910a4bc2daf1ee4c44d867bb55f550a298886ecf` | appendix-CFG `RESOLVED` |
| `T01-RETURN-T16-031-c26518b1` | `50d455ad73780a4b351a166dce23f2d0b4ee835e` | `f59171e9c568bd5135d77bdac0e81638d7cb74f4` | appendix-CFG `RESOLVED` |
| `T01-RETURN-T16-033-c26518b1` | `d4d3e8e5c276c2e0236f16c3381ce9daabbab0e0` | `1c26b5275f7c72e2b021617258a278e43c58b183` | appendix-CFG `RESOLVED` |
| `T01-RETURN-T16-034-c26518b1` | `d40e04e082a100447c773be6e4a9a3c5f786b57b` | `3123d1e815c70c0e2abe3f1055f8dab79895142a` | appendix-CFG `RESOLVED` |
| `T01-RETURN-T16-036-c26518b1` | `cac59d7ffa953663da5753574eb47304504887f0` | `e02e0b4f4503b3e2a6cff2221aa8f3c3cd7f4532` | appendix-CFG `RESOLVED` |
| `T01-RETURN-T16-040-c26518b1` | `b35ca329c1a657364c997c701b806d6847ea5917` | `ae73f08fe02c50d29bc5292253dee25d1747493b` | appendix-CFG `RESOLVED` |
| `T01-RETURN-T16-050-c26518b1` | `bf3fc0814f75e19ced4ac95bfff6a67ebf4e9564` | `620f1186066700e97162f0c22ce29b7336766fc2` | appendix-CFG `RESOLVED` |
| `T01-RETURN-T16-051-c26518b1` | `d6591307065c066485ec3e312aafe69b38c72448` | `b48238622a74e961b6b12125779ec9512e230fdc` | appendix-CFG `RESOLVED` |
| `T01-RETURN-T16-065-c26518b1` | `c248ef57f8604d09ed0020c69533b236881cfd5e` | `a2f1e7300ff622bf1b32040d0930f66eee23d1ee` | appendix-CFG `RESOLVED` |
| `T01-RETURN-T16-092-6df3bb2c` | `bd044356f64dd859fe898477d443414a468f4b85` | `6b5fb000aa1015a0c2f37be9015ab52c24dc8fd0` | appendix-CFG `RESOLVED` |

每筆來源的 exact path、SHA 與 43 項完整狀態見 [機器可讀索引](native-validation.json)。作者原稿和作者分支勘誤**原封不動**，T01 在自己的 integration 匯總精確校正。

## 根 CFG 統計
| Root | Native instructions | Edges | Direct call/jmp/jcc |
|---|---:|---:|---:|
| `0x47B850` | 223 | 242 | 49 |
| `0x4A88E0` | 77 | 76 | 33 |
| `0x4A89C0` | 41 | 41 | 6 |
| `0x4A8A60` | 82 | 86 | 16 |
| `0x4AB8A0` | 48 | 49 | 7 |
| `0x4AEDB0` | 269 | 290 | 47 |
| `0x4C1E10` | 151 | 158 | 30 |
| `0x4C4B10` | 149 | 161 | 34 |
| `0x502270` | 394 | 426 | 95 |
| `0x5027D0` | 256 | 274 | 54 |
| `0x504740` | 1063 | 1232 | 289 |
| `0x505570` | 207 | 231 | 54 |
| `0x531D00` | 549 | 601 | 132 |
| `0x53FA40` | 87 | 97 | 17 |
| `0x53FBB0` | 223 | 246 | 54 |
| `0x5B6BE0` | 91 | 96 | 15 |
| `0x62E490` | 335 | 364 | 77 |
| `0x62F640` | 90 | 97 | 17 |
| `0x6F4DD0` | 129 | 138 | 20 |

## 28 個問題指令窗口
26 個舊窗口位址落在前置指令中間；2 個本身是有效指令起點：`0x4AEDB0` 有 callback 指標寫入證明為獨立函式，已於上輪撤回 T01 初審錯誤反證；`0x62E5CD` 是 `0x62E490` 內 `push eax`，**不是新函式入口**。
| 來源 | 原起點 | 合法 root | 真正的原生指令 | 類型 |
|---|---|---|---|---|
| T16-001 | `0x004A899F` | `0x004A88E0` | `004A899E call 4AB800` | interior |
| T16-001 | `0x004A8B2F` | `0x004A8A60` | `004A8B2B call 89231A` | interior |
| T16-001 | `0x0050559F` | `0x00505570` | `0050559B mov eax,[D61F20]` | interior |
| T16-009 | `0x0053FADE` | `0x0053FA40` | `0053FADC mov [ebp-10],FE18DC` | interior |
| T16-020 | `0x00502460` | `0x00502270` | `0050245D je 5024F9` | interior |
| T16-021 | `0x005321A0` | `0x00531D00` | `0053219F call 532FF0` | interior |
| T16-021 | `0x0053FD40` | `0x0053FBB0` | `0053FD3D call 891268` | interior |
| T16-022 | `0x004A89A0` | `0x004A88E0` | `004A899E call 4AB800` | interior |
| T16-022 | `0x004A8B10` | `0x004A8A60` | `004A8B0C mov [FAADF0],eax` | interior |
| T16-026 | `0x004AEDB0` | `0x004AEDB0` | `004AEDB0 push ebp` | independent-callback |
| T16-029 | `0x00502470` | `0x00502270` | `0050246E mov esi,[edi+15C]` | interior |
| T16-029 | `0x00502860` | `0x005027D0` | `0050285F mov [eax+C],esi` | interior |
| T16-030 | `0x005321A0` | `0x00531D00` | `0053219F call 532FF0` | interior |
| T16-031 | `0x004A89A0` | `0x004A88E0` | `004A899E call 4AB800` | interior |
| T16-033 | `0x004C4C80` | `0x004C4B10` | `004C4C7F push BFDB70` | interior |
| T16-033 | `0x004C4C87` | `0x004C4B10` | `004C4C84 call 89231A` | interior |
| T16-034 | `0x0047BA80` | `0x0047B850` | `0047BA7F mov ecx,FC0E90` | interior |
| T16-034 | `0x004C1F90` | `0x004C1E10` | `004C1F8D call 79CF40` | interior |
| T16-036 | `0x00531E00` | `0x00531D00` | `00531DFC je 532243` | interior |
| T16-036 | `0x005321E0` | `0x00531D00` | `005321DD cmp [esp+A8],8` | interior |
| T16-040 | `0x00502870` | `0x005027D0` | `0050286F mov [eax+14],ecx` | interior |
| T16-050 | `0x006F4E83` | `0x006F4DD0` | `006F4E81 call 6FE770` | interior |
| T16-051 | `0x00504817` | `0x00504740` | `00504816 mov [esp+188],edi` | interior |
| T16-051 | `0x0050564B` | `0x00505570` | `0050564A call 72E2E0` | interior |
| T16-065 | `0x004AB930` | `0x004AB8A0` | `004AB92F mov eax,[ebp+8]` | interior |
| T16-092 | `0x0062E5CD` | `0x0062E490` | `0062E5CD push eax` | valid-instruction-not-function-entry |
| T16-092 | `0x005B6CD0` | `0x005B6BE0` | `005B6CCF mov edx,[ebx+14]` | interior |
| T16-092 | `0x0062F706` | `0x0062F640` | `0062F700 mov [ebp-4],-1` | interior |

T16-092 尚有第四個座標更正：`0x62E659 push esi`，`0x62E65A call 0x759ED0`，不可把前者當 CALL。T16-020／021／022 原稿保有正確的相對 call/jmp **22 + 34 + 15 = 71 條**，已全部從 BIN independent displacement 重算；修正錯誤窗口時不刪掉這些正確資料。

## Table XML 新證據與研究邊界
`Table/QuestInfo.xml` 有原生 Quest 14/16/15 靜態依賴資料：Quest16 有 `Demands/Demand id=14`；Quest15 有 `Demands/Demand id=16`；原始資料對應 **14→16→15**（以 Demand 表格語意而言）。Quest16 giver/finisher 10027，Quest15 giver/finisher 10338，兩者 type=2 level=1。另 `QuestTalk.xml` 4322 個直接節點中並沒有頂層 id15/id16，**不表示 QuestInfo 的任務不存在**。完整原始欄位、SHA 和資源 bytes 位置見 [XML 稽核](TABLE-RESOURCE-AUDIT.md)。

## 後續驗收分類
- **Client 待逆向**：Quest14/16/15 的 native Lua/Quest state 讀寫、實際 C→S/S→C 任務命令、NPC/接受/完成 UI 更新，以及 callback 執行時序；本批沒有建立 wire end-to-end。
- **Server 待開發**：相容 Quest prerequisite、完成/拒絕/保存規則，與 Client 協定相容但不是原版 Server 實作推斷。
- **跨功能待整合**：T02/03 連線、T06 UI、T07 場景、T14 結算、T15 保存、T16 Quest。
- **待遊玩驗證**：沒有執行原版 Client，沒有 Server ACK / gameplay 測試。
- T01 `RESOLVED` 是**精確錯誤通知結案**，不升級 `shared/verified-knowledge`、`NATIVE_VERIFIED`、S00 `RR ACCEPTED` 或任何 `SPEC STABLE`。