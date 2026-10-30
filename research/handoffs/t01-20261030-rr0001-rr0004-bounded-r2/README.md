# T01 — KR RR-0001/E57 與 RR-0004/E58 限定驗收整合（2026-10-30）

- Main 基準：`7b8a635358837ca3b7a709342c0f863b58336be7`；原始 BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes；PE .text VA `0x401000`/raw `0x400`，本次 .text raw=VA−0x400C00。
- T01 審查身份：2026-10-30 ChatGPT-web roy。只離線讀原件、未執行或修改 Client、未連原版 Server。
- **結論**：完成兩份已 SUBMITTED 原稿的精確 R0 登錄、有限 R1 主張去重、八個原始 BIN 定向區間 R2 與必要控制流比對。報告可進一步交 S00 判斷 RR 完成條件；**沒有由 T01 擅自標 ACCEPTED**。
- 先前 GitHub Actions 出現 RR-0001 / RR-0004 `missing or unsafe submitted report path`，兩份報告雖在各作者 branch 有正確 blob SHA，但未在 main。此次用**完全不修改的原始 Git blob**引入 main，修補可審查來源的身份斷裂。

## 1. 來源及確切追溯

| RR | SRC | 原作者原稿 Git 相對路徑 | blob SHA | 原始 UTF-8 SHA256 |
|---|---|---|---|---|
| RR-0001 | SRC-0461 | `kr-extra-roy/20261030-103206-chatgpt-web-roy-E57-RR0001-KR-first-frame-0BBB-1A68-mode-sequencing-static-contract.md` | `a379f776b9a1d7566de539daa7153f33b9b91e36` | `a8121d2787a2cd826ad87c27a65f22f81434357351908360a9804a1837153243` |
| RR-0004 | SRC-0462 | `kr-extra-roy/20261030-110906-chatgpt-web-roy-E58-RR0004-A02C-alias-mode-fallback-bounded-BIN-first.md` | `b5c53b93ec20e056fb3f07374468a341ce4ee9c9` | `0760fcd27895d5332fb6e4e3a9abf04cf6bf82eef08c0c127cd146139064fc46` |

兩份均已在 RR 唯一台帳填 SUBMITTED 與相符來源 SHA；本次原稿接收不等於 RR S00 正式 ACCEPTED。R1 以原稿精確主張分組，避免重複建立 E57/E58 的 framing/mode 事實；源作者也明示 unknown 的遠端 first reply／間接 alias 仍 unknown。

## 2. 獨立 BIN-first 抽驗及位移/直接呼叫搜尋

原始 PE .text 八處已知功能窗口以本機 Tartaros.bin 重新 SHA256，**8/8 相符，合計 698 bytes**；下表是精確原始區間與完整 hash；匹配本身不代表整份源報告語義驗收。

| 子流程 | VA [begin,end) | bytes | 本機原始 SHA256 |
|---|---|---:|---|
| A02C constructor | `0x805CFA..0x805D2C` | 50 | `fbcf937927da5096e9dde745698576ecf2ca23a1aa693430f298567686ae5b93` |
| drain mode switch | `0x8061E6..0x80624F` | 105 | `35e2eaf34e1362bcc09488d142ae458c04457dd19d4a326ff7c63b74c623f135` |
| 0BBB guard | `0x80786D..0x8078B6` | 73 | `744ad55ddfb3d51c566eb1ee569d3d161e4cff04355a38ccd292434df70e3344` |
| 1A68 guard | `0x807A88..0x807ABB` | 51 | `657aa19da69f2b3f2792e81f3cf31184edfd325297456e7b9795b873cb0ef2e8` |
| Rx marker selector | `0x807BD0..0x807C40` | 112 | `ebd1675f0b768c92e31cfca9d4c29b698aa95483dbced22e4f6d0c3b31388743` |
| Rx XOR/checksum | `0x807D33..0x807D7A` | 71 | `4d7a7586435f68a91ae50447b4ef553228b9c8a401d6dbd82113e78f1715f784` |
| queue unlink | `0x80624F..0x80627B` | 44 | `55d238a7ad15c831708f45a2b2eb7c18394ad1d119597c729d488327cdac560d` |
| Conn reset | `0x805F50..0x806010` | 192 | `316982ab1b311e9a3fed8a70e7f0ef30bfc99f38f7a57fdca1462098428a8434` |

獨立對 `.text` 全段（raw 0x400..0x7D05F0）掃 4-byte little endian displacement：A02C 只找到 operand bytes VA **0x805D04** 和 **0x806205**。指令起點分別 **0x805D02** (`C6 86 2C A0 00 00 02`) 與 **0x806202** (`0F BE 86 2C A0 00 00`)；不是直接 xref/addressable data。A028 16、A020 2、A030 4 個原始位移命中，用來辨清相鄰非重疊欄位，但不是全域 alias graph。

獨立重算 .text raw `E8 + signed displacement` 的直接 CALL 候選：0x805CA0 ← 0x80577A/0x805A1B；0x805F50 ← 0x8059E9/0x805BB7/0x805E1B/0x805E9E；0x806010 ← 0x804C33/0x80538D；0x8061A0 ← 0x804AD6/0x805228；0x807830 ← 0x806223；0x807A70 ← 0x80623A；0x495610 ← 0x6D6377/0x6D6424/0x6D6508/0x6D65C8/0x6D670C/0x6D696C。只在已知實際 root 內的目標才作正向有界主張；位元組掃描不能取代 CFG 或間接 caller 分析。

### 控制流及負向分支

```asm
805D02  C6 86 2C A0 00 00 02  mov byte [esi+A02C],2
806202  0F BE 86 2C A0 00 00  movsx eax,byte [esi+A02C]
806218  74 15                 je 80622F       ; mode==0
806223  E8 08 16 00 00        call 807830     ; encoded 0BBB
806228  85 C0                 test eax,eax
80622A  75 23                 jne 80624F      ; encoded success
80623A  E8 31 18 00 00        call 807A70     ; raw 1A68 fallback
806246  0F 84 58 01 00 00     je 8063A4      ; both failed, node not removed
80624F  8B 0B                 mov ecx,[ebx]   ; success-only dequeue
80626A  E8 9D AF 08 00        call 89120C
806275  FF 8E 78 A0 00 00     dec dword [esi+A078]
807887  3D 00 10 00 00        cmp eax,1000h ; encoded n+6
8078A2  81 FA 00 40 00 00     cmp edx,4000h ; cumulative capacity
807A97  81 FB 00 10 00 00     cmp ebx,1000h ; plain n+4
807D66  66 39 4B 04           cmp word [ebx+4],cx ; inbound checksum
807D6A  75 13                 jne 807D7F      ; mismatch skips copy
```

對 synthetic application payload `01 00`，`0BBB` encoder的 byte-level 守恆範例 `02 00 BB 0B 01 00 B7 01`，`1A68` 明文 `02 00 68 1A 01 00`；只是靜態原件算法與合成資料一致，不是原版連線抓包。`n=4091/4092` 在 Tx 空間足夠及正常 cursor 下，可因 encoded n+6 過長而被 plaintext n+4 接受；不可宣稱原版遊戲實際送過此長度。

## 3. 此次正式 canonical R1 主張

| CLM | 證據級別 | 有界內容 | 限制 |
|---|---|---|---|
| CLM-NET-0021 | PARTIAL | constructor A02C=2 與 nonzero encode / fallback CFG | 無全域 alias writer closure |
| CLM-NET-0022 | PARTIAL | outgoing 0BBB XOR+checksum / 1A68 raw shape | synthetic≠原版首包實測 |
| CLM-NET-0023 | PARTIAL | 兩種 n/used 限制和 queue success-only unlink | 本地封裝≠WSASend/完成 |
| CLM-NET-0024 | PARTIAL | inbound marker parser 與 checksum gate | peer first reply 及 compressed failure 未證 |
| CLM-NET-0025 | PARTIAL | 原始 A02C direct operand/xref 的明確陰性搜索範圍 | 不排除 indirect/memcpy/computed alias |

已和既有 CLM-NET-0001..0020、E56 RR5 相同事實去重，且保留新源只支持其本身真正定位的子範圍；沒有賦予 R3 或整體作者來源更高的品質。未改 S00 的 SPEC/GAP/TEST、原始 owner/task.json/catalog。

## 4. 文件缺口、風險分流與後續責任

- E57 Section 8 原始檔仍有未展開的 literal template `{', '.join(...)}`，因此不能把該處當成已實際填好的 caller 清單。T01 在本報告按原始 BIN 重算 direct E8 與 A02C raw hits；**保留作者原稿，沒有替換或竄改**。這是來源呈現／重現性瑕疵，但不直接反證已另以 BIN 限定核實的主要 mode/length 分支，現階段不造重複退回。
- `RR-0001` 的 Client 靜態初包候選與三 Conn 局部建立條件可供 S00 做 bounded 研究交付檢查；真實 Server first response marker/opcode、跨 socket 順序不由 Client 靜態可得。
- `RR-0004` 的 direct A02C 取用、reuse/reset、encoded-failure→plaintext fallback 具局部證據；未找到 mode0 writer 不能寫成『原版永不切到0』。需要更強結論時，需 computed pointer/struct memcpy 或原版同 session trace 才能新增，不能假裝已閉合全域別名。
- **Client 待逆向**：unknown marker handling 與 compressed frame failure/0x727190（RR-0006）、A02C indirect alias 與 first real S2C；**Server 待開發**：多連線初始 payload/回覆與錯誤容錯策略，須 S00 設計並測試；**跨功能待整合**：T02↔T03 登入/選服、RR-0005 slots 及 RR-0007 入口；**待遊玩驗證**：自建 Server 接入真正 Client 的同 session 順序/封包與失敗恢復。
- T01 僅提供 R0/R1/R2 限定審查；RR 的 `ACCEPTED`、`GAP RESOLVED`、SPEC STABLE 都由 S00 分別決定。此次不提升任何 `NATIVE_VERIFIED`／`shared/verified-knowledge` FULL-PASS，也不修改既有 Quest16 T16 NEEDS_FIX。

## 5. 下游建議

S00 優先根據兩份精確來源審閱 bounded `RR-0001`/`RR-0004` acceptance，必要時列出額外 alias / packet ABI 補證。來源現已在 main 可核對 exact blob；CI 可以檢查正式 SUBMITTED artifact 存在。後續 R3 僅在有明確 Server SPEC 阻塞且精確範圍/全部肯定主張完成原生 root/CFG/caller-dataflow 複驗時升格。
