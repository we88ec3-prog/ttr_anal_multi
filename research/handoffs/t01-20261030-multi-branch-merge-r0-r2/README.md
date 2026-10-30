# T01 多來源 Merge / R0–R2 有限驗收（2026-10-30）

- main 基準：`3724d850231ef26b2a36984ac1c5bc3347c4d96d`；原件 KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；原始 Client 資料唯讀、不執行/不修改。
- 採用**具多父提交的 Git commit graph 合併**，保留指定分支 commits 的祖先關係；不是只拷貝單份報告，並非丟棄 source branch。合併前逐項比較了相對 main 的變動，以 main 為最新正確台帳基準，不覆寫既有原稿／S00 合法狀態。
- 主線早已有 extra/roy1 E51–E56 完全相同六個 blob；RR1/E57、RR4/E58 完全相同兩個 blob；其原文不需改寫。新納入 T16-114/115/116/118/119/120/124/125 八份與 RR6/E59 一份原稿。已存在的 T16-117/121/122/123 均保持原 blob。
- RR-0006 已在最新 main **SUBMITTED**，RR-0007 **CLAIMED**；先前分支 RR6-submit 與 RR7-claim 均已成為 main 祖先，故不回寫較舊 dispatch index 或生成 inbox，以免倒退或重複事件。RR1/4 仍 SUBMITTED；RR5 仍 ACCEPTED。T01 無權替 S00 擅標 ACCEPTED。

## 1. 精確來源表 / 首次 R0 身分登錄

| 來源 | SRC | 原 Git blob SHA | SHA256(UTF-8) | 是否新主線原稿 |
|---|---|---|---|---|
| [T16-114](../../../kr-temp-roy/20261030-022715-chatgpt-web-roy-T16-114-KR-Quest14-study3-C2S-questID-proven-0x36-and-scenario14.md) | SRC-0463 | `e1e3b6b38d3ccd6a0e759d23399521e33564118c` | `659ef640ff9c0c4a30ebb87b6e050698513a4614df17206b4d7107830517264c` | 新檔；Quest14 local C2S; prior 0x36 producer overlaps CLM-QUEST-0006; not upgraded |
| [T16-115](../../../kr-temp-roy/20261030-030953-chatgpt-web-roy-T16-115-KR-Quest14-study4-S2C-scenario-vs-quest-record-and-UI-client-boundary.md) | SRC-0464 | `54d96de03a0c10bf954da06249d56b5b06477d11` | `70a8a9293561e35edfd47703c58f2088dc9bdbfdd7b4a41a0a875faba782f3f5` | 新檔；Scenario14 S2C state vs QuestInfo separate |
| [T16-116](../../../kr-temp-roy/20261030-032743-chatgpt-web-roy-T16-116-KR-Quest14-study4-S2C-0x74-quest-owner-demand-UI-end-to-end.md) | SRC-0465 | `a79ee0add91970494a63f4a393694ee1cd5ee15b` | `71ae032c6b64d0f37511170c2daa3c1159116718668d36785748925160c43780` | 新檔；0x74 prerequisite writer corroborates CLM-QUEST-0003; no duplicate claim |
| [T16-118](../../../kr-temp-roy/20261030-042414-chatgpt-web-roy-T16-118-KR-Quest16-study1-resource-demand14-reward50-BIN-loader-and-type2-record.md) | SRC-0466 | `c8a5f75bd6295b01746e0574f7085a80d627af63` | `a08852be3cd1d77b6dd166088dbae0b56984c141d174b33d41a827fde0b000db` | 新檔；Quest16 resource/record gates and demand14 |
| [T16-119](../../../kr-temp-roy/20261030-090619-chatgpt-web-roy-T16-119-KR-Quest16-study2-NPC-giver-selector-event-producers-and-TalkBox-bridge.md) | SRC-0467 | `88fa586a1d54f8b7eae6bf27645a3784c2293f82` | `ae77b0aae8ab2f4bda38fc87e521e7b2a5817cd25fbb88e2cc9624ca2e7e0b3b` | 新檔；NPC10027 type2 conditional lookup |
| [T16-120](../../../kr-temp-roy/20261030-092234-chatgpt-web-roy-T16-120-KR-Quest16-study2-NPC-type2-unique-firstID-C2S-003F-versus-TalkBox-unclosed.md) | SRC-0468 | `6fbd5e121df541081bab93518b5c5eac52e1cb90` | `934eae69ba91cee85873e97ee965090827971ac22fcf722e5ab0e9a93f58dcc4` | 新檔；Historical limited/unclosed TalkBox analysis; successor T16-121/122 narrows, no automatic old claim promotion |
| [T16-124](../../../kr-temp-roy/20261030-103908-chatgpt-web-roy-T16-124-KR-Quest16-study5-Q15-Demand16-town5-NPC10338-C2S-S2C-scene-bridge.md) | SRC-0469 | `79d147affae5e54b688876a1a1ae9765a6edfbaa` | `351a66afbdeec721c2a9ec2ce4471739c9934f09d1e7d1359d90656ef97f93d2` | 新檔；Quest16 prerequisite→Quest15 conditional NPC/type2 bridge |
| [T16-125](../../../kr-temp-roy/20261030-112139-chatgpt-web-roy-T16-125-KR-Quest15-study1-resources-demand16-reward-schema-four-native-scenes.md) | SRC-0470 | `983535d340331f03ca1e253bc1d73e26bb08dd8f` | `e0d583ba3514abc1a80b086bd7d1f0dc6d36a79933d5067e709a8712d9b93dc2` | 新檔；Quest15 resource/Scene 1–4 loader proof; reward numerical values limited |
| [E59](../../../kr-extra-roy/20261030-112205-chatgpt-web-roy-E59-RR0006-compressed2633-22D7-decode-checksum-pool-IOCP.md) | SRC-0471 | `c7c1474b6b3cf928b8031e17fad7761c488d9b18` | `11790f03c08fe62ddea1aa75cc1fac1eb43c5fcb38088e8f344d80c8b28019df` | 新檔；RR-0006 compressed/error parser source; bounded R2 Client |

上一批已在 main 的四份 T16 117/121/122/123，以及六份 E51–E56，都沿用既存來源身份/SRC，不重複編號。每份新文件沿原作者 blob 原樣進 main；R0 身分、有限 R1/高風險 R2 區分，不將 branch 合併認為全文受審。

## 2. 新增限定 S00 可檢索的主張

| CLM | 依據 | 品質/界線 |
|---|---|---|
| CLM-QUEST-0008 | T16-115 | PARTIAL：Scenario14 0x4C scene state / Lua reader，**不是** QuestInfo14 accept ACK |
| CLM-QUEST-0009 | T16-118 | PARTIAL：Quest16 Demand14/type2 resource-loader/gate；未證 Server 獎勵 |
| CLM-QUEST-0010 | T16-119 | PARTIAL：NPC10027 giver type2 候選/QID16 本地橋接；runtime/Wire unknown |
| CLM-QUEST-0011 | T16-124 | PARTIAL：Quest16 prerequisite16→Quest15 Demand16/town5/NPC10338 的條件串接；配對 unknown |
| CLM-QUEST-0012 | T16-125 | PARTIAL：Quest15 resource/schema 與四段場景；真實 reward 數值和執行 unknown |
| CLM-NET-0026 | E59 | PARTIAL：0x2633 8B header、XOR seed0x7C、0x727190 decompress gate |
| CLM-NET-0027 | E59 | PARTIAL：checksum/inflate/invalid n/incomplete frame 的分支差異 |
| CLM-NET-0028 | E59 | PARTIAL：node pool/0x807E50/0x8076F0、lane dispatch 的條件 |

**不重複建 claim**：T16-116 的 0x74 vec writer 先與 CLM-QUEST-0003 對照；T16-114 的 0x36 producer 要與既存 CLM-QUEST-0006 保持各自確切 producer；T16-120 是後來 121/122 更精確研究前的未閉合階段，不能倒退新主張或解除既有衝突。原 T16-117 `T01-RETURN-T16-117-Q16-MODE2-C2S36-001 NEEDS_FIX` 照常待作者提交正式勘誤，不因 merge 變成 RESOLVED。

## 3. 獨立 KR BIN 重要位元組區間（R2 受限證據）

PE32 .text VA 0x401000/raw0x400，因此本段 code raw=VA−0x400C00。下列八段由 T01 在當次提供的同 SHA KR BIN 重新讀取、計 SHA256；byte 身分及已知 root 的局部分支相符，但不宣稱全文所有 CFG/indirect aliases 同時驗收。

| VA slice | bytes | SHA256 |
|---|---:|---|
| `0x807B40..0x807C40` | 256 | `57fd65c82cc34e760072c3c62992b572e4b6c4f4de4b981cbb38a2168a1321c3` |
| `0x807CD2..0x807D21` | 79 | `f9fab4aae2f8a708394c6402704fedaa6a7b8a0b6658837bd2567c1994d3c0be` |
| `0x807D33..0x807D7A` | 71 | `4d7a7586435f68a91ae50447b4ef553228b9c8a401d6dbd82113e78f1715f784` |
| `0x807D7F..0x807E50` | 209 | `b3c4b15189681a90d43fef0eacd248eb0dfc9adba5e138f46d8f2aa40f7d1787` |
| `0x8075B0..0x807700` | 336 | `b89f113f6c173dc8fdf0e8f9abf8f6f299429eb05fca0a68fc07a33c67eae4d2` |
| `0x806DE4..0x806E24` | 64 | `84f443b5ea1c87aa1ebdfd091b882f47ef821ad638cec1beae9e3bf4489f1c0e` |
| `0x500F90..0x500FC0` | 48 | `6c2351c30c77176b9ded4c3658ab1b4474a3cdf5033eff6eb5ba0c6e1b39783a` |
| `0x503400..0x503440` | 64 | `29cae14b7820e8bea1af396ffe6ef44bba7656a49ba702d8ae77d1bc9033734d` |

合計 **1127 bytes**，原生 SHA 已比對。以下是受限正向第一手機器碼：

```asm
807BE5  cmp cx,2633h           ; compressed marker
807C04  cmp cx,0BBBh           ; XOR/checksum marker
807C22  mov edx,22D7h         ; 4-byte raw marker branch
807D33  xor al,0B6h            ; decoded 0BBB seed
807D66  cmp word [ebx+4],cx   ; decoded checksum check
806E08  call 807B40           ; IOCP completion -> parser
503400  push ebp              ; Quest prereq WORD append handler root
```

Compressed 0x2633 的 0x7C XOR 與解壓結果判定依 E59 的 0x807CD2..0x807D21 原稿、獨立核驗部份；`+4..+7` 未於 parser 被賦予本稿可證的原版 Server 欄位語意。`0x22D7` 與 unknown marker 同享 local header4/raw branch，不推論全部 marker 官方允許。

## 4. Merge 衝突、台帳及驗收隔離

- 新增 `SRC-0463..0471` 與 `CLM-QUEST-0008..0012`、`CLM-NET-0026..0028`；全部有準確源 blob/SHA/版本與限定，沒有升級 NATIVE_VERIFIED 或 FULL-PASS。
- `extra/roy1` 六份 E51–E56、`rr/t02/roy/rr-0001` 的 E57、`rr/t02/roy/rr-0004` 的 E58，主線已存在同 SHA；合併其 Git 歷史但不重複更改原稿或索引。
- `rr/t02/roy/rr-0006-submit`、`rr/t02/roy/rr-0007-claim` 的 S00 dispatch 已由其他 Agent 先一步合入 latest main；以最新 main 為唯一台帳真相，不採舊 branch `inbox` 覆寫。
- `t16/roy/chatgpt-web` 的八個原稿新加入，四個 T16 既有相同 blob 保留；沒有改 T16 README 裡的固定 NEEDS_FIX，因作者尚無勘誤提交。
- CI 是否成功請以最終 merge commit 的 GitHub Actions 實測為準。上一輪測試中 `governance/tests` 有依舊「八筆 RR 尚未認領」假設的 baseline，以及 RR5 review-fixture 來源缺失，不能改 RR 台帳來讓舊測試通過；需 S00 測試維護者獨立修正。若仍失敗列為待整合，不假稱全綠。

## 5. 待辦歸類

- **Client 待逆向**：E59 decoded compressed failure 全部分支、unknown marker 不同上層業務 handler、Quest15 後段及 mode2 accept producer、更深間接 alias。
- **Server 待開發**：相容首包/多 Conn 先後與超時政策、quest 持久化/獎勵/拒絕，須由 S00 設計，不能假稱官方原始規則。
- **跨功能待整合**：RR-0006→RR-0007/T03、T16 Quest14→16→15 與 T02 framing/S00 DRAFT SPEC。
- **待遊玩驗證**：原版 Client 對新 Server 實際 session、伺服器任務回覆與 NPC/場景流轉。

沒有任何原稿整體 FULL-PASS、SPEC_CONSUMABLE、RR ACCEPTED（本次新）、SPEC STABLE 或真實 gameplay 實測判定。
