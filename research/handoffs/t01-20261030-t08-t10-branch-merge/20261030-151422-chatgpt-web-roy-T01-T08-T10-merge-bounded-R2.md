# T01 — T08／T10 雙分支真實合併、來源去重與有限原生驗收

日期：2026-10-30 Asia/Taipei；操作者 chatgpt-web roy；工作是使用者明確授權的 T01 合併與驗證整合，不是新的 T08/T10 原創研究正式段號。庫 `we88ec3-prog/ttr_anal_multi`、KR 版本。

## 1. Git graph 與來源一致性

- 基準 main `79eab9b15981d6b9b918ac47dc82cc2906230e3f`。
- T08 來源 `t08/roy/chatgpt-web@5816884ef481995a9fe0d92277b1dde06aff32e8`，合併前 main...T08 ahead=1, behind=359。PR [#47](https://github.com/we88ec3-prog/ttr_anal_multi/pull/47) 使用 **merge commit** `a87af29258644898bc19084ec19ecd2c4bd5f20e`，父節點依序 `79eab9b15981d6b9b918ac47dc82cc2906230e3f`、`5816884ef481995a9fe0d92277b1dde06aff32e8`。合併後 T08 相對 main ahead=0。
- T10 來源 `t10/roy/chatgpt-web@decc50e3c5c05bb405704df82dae06ebcf783454`，基於 T08 合併後 main 的比較 ahead=34, behind=353。PR [#48](https://github.com/we88ec3-prog/ttr_anal_multi/pull/48) 使用 **merge commit** `96d072e262a1e8dcd0e1d21f11b856da12db774a`，父節點依序 `a87af29258644898bc19084ec19ecd2c4bd5f20e`、`decc50e3c5c05bb405704df82dae06ebcf783454`。合併後 T10 相對 main ahead=0。
- 所有來源分支仍保留；不是 squash、cherry-pick、覆寫或把新增報告拷貝後稱作 Merge。合併後 main 與各自分支的比較皆 ahead=0。
- **tree 精確差異**：前一 main → T08 merge 只新增 `03-PROJECT-T08-INSTRUCTIONS.md`（blob `d36db31a49f78ebc6a1a90f06fbabcdba9e47b8e`）；T08 main → T10 merge 只新增 `03-PROJECT-T10-INSTRUCTIONS.md`（blob `7a9c4cad088ba8e012d96cae3a15a91c4ead2bbf`）。原稿不是這次新檔案：T08 138 份在先前 T01 R0/R1 已原樣納入 main；T10 22 份在先前 T01 階段整合 R0 已原樣納入 main。
- T10 `kr-temp-roy` git tree：T10 branch SHA `e50cd250253c67b0f2a8d36951668040b86ea013`；merge 前與 merge 後 main 都是 `205ee2a9ca83aa0efe4b57a3f2a78dd6fb46a575`。逐檔比對 **22/22** 本批 T10 原稿 Git tree blob 完全相同，無內容覆寫；T10 前 101/102 兩套稿以完整路徑與 blob 分開，不以段號去重。
- 既有 T08 T01 R1 及原生錯誤處置原文見 `research/handoffs/t01-t08-roy-20261029/README.md`；T10 前期全 127 篇來源只有 R0 與 early/middle 提案，見 `research/handoffs/t01-t10-roy-20261029/README.md`。本輪不變更任一舊 T01 退回、T08 24 篇 mapping FAILED、T10 055/056 NEEDS_QUALIFICATION 或作者原稿結論。

## 2. R0 原件及 native scoped R2
- 唯讀 `Tartaros.bin` 12,472,320 bytes，當次 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` 2,594,816 bytes，SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- x86 PE32：.text VA 0x401000/raw 0x400，所以以下 VA 使用 `raw=VA-0x400C00`；.rdata VA 0xBD2000/raw 0x7D0600，所以靜態 vtable DWORD 使用 `raw=VA-0x401A00`。FB/FE runtime 欄位不可按 .text 映射推初始值。工具：Python hashlib/struct 與 GNU objdump Intel x86；沒有執行、附加、修改 Client、連線或使用原版 Server 抓包。
- 以下資料均以原始 BIN 重算定向 [start,end) 位元組 SHA256，**不是原稿全部函式或全段機器碼語意 FULL-PASS**：

| KR .text VA [start,end) | SHA256 |
|---|---|
| 4914A0..4914C0 | 0632785ae70c28460864c6e1cdc1a112739a7162fe0b9139928c6f1b7a951e01 |
| 6D1540..6D1640 | 4e9b7cde299a605ca363307593dbca91991597fffa6b843a6e8560d0e5ce2bda |
| 545824..545857 | 642308877ebd72d98c18c7eca57a7e6b7eb549353035210fa294db948c392195 |
| 545B38..545B73 | 170e1d95e58df6a123a3f6bd63e7a28ed0d97a42895078d7e0d3d8adcb89fe6c |
| 4B01F0..4B0215 | 26dd24e2f4a58c2de81ea4481d4b3200d986b047d93425146285a73e72f89faf |
| 4B0250..4B031F | f8369b007f96d9ac3dc9f0c5ebd561c44fce89408554feff4e1479f3d7c76e28 |
| 4B0390..4B03B0 | eac30eeca44ae59ec94923a3077f2562b1806f77a9ee36b5818a3670e0ec160c |
| 4C8C30..4C8C40 | ea2c5e4b2c272bbf69b25395af84f2e0beee255e89eb773523a1eebfdee6d911 |
| 4C8A90..4C8B80 | cc81bccf1c9d5d9a524d481528a7ef8dda74a44a57d2013681f8f8dcee282f16 |
| 8069A0..806A00 | 2ba61625d9b02c3e73b031395491966375cca46b78d622fbe26fa245f07f83b3 |

- **輸入**（T10-101）：`4914AC mov ecx,FB8830` → `4914B1 call 6D1480`，限定本更新路徑及當時 object；不能推所有實體 Z 觸發或每次都發包。
- **C2S 應用 000A**（T10-115）：`545824 mov eax,6`, `545829 mov edx,0xA`, `54583C mov [FE48D0],eax`, `54584A mov [FE38D0],ecx`; `545B38 cmp [FE48D0],6`、`545B43 jbe`、`545B66 mov edx,[edx+10h]`、`545B69 push length`、`545B6A push FE38D0`、`545B6F push 0`、`545B71 call edx`。在確定的靜態 vtable C51748，`[C51758]=8069A0`，`[C51754]=8068B0`；8069A0 先按 selector lookup，有有效連線且長度非零才 call 8060D0。這不是已觀察 socket 傳包。
- **S2C key13**（T10-119）：`4B01FB mov eax,38E38E39h; mul ecx; shr edx,1` 對 (L−2) 做除9，`4B0211 add edi,5`、`4B039E add edi,9`；每列資料 P+2 的 actor WORD、P+4 BYTE、P+5 WORD、P+7 float 符合本函式相對讀法。`4B0294 mov edx,[esi]`,`4B0296 mov edx,[edx+58h]`, `4B029C call edx`。這是條件式應用分派路徑，不證明 key13 是 000A 的 Server ACK。
- **具體 actor slot**（T10-120）：.rdata 七張候選 vtable 基址 C07554/C076AC/C07B44/C0C824/C0C8C4/C0C9DC/C0CA9C 的 `+58h` DWORD 均為 4C8C30；`4C8C33 mov al,[ebp+8]`, `4C8C36 mov [ecx+B0h],al`,`ret 4`。+68h 不同實作，不能直接當動作片段或推斷所有 actor 分類。
- 對原作者所述每個語意、32-bit arithmetic overflow、間接 vptr provenance、完整異常路徑及 Server wire 的真實回應順序**沒有做 R3/full review**；所有以下 CLM 僅 PARTIAL。

## 3. 證據整合去重與分層
- 確認本批 T10 22 原稿已註冊 `SRC-0363..SRC-0384`，且 R0 SHA 與 main/branch 所見 blob 一致。本次不重複建立 22 個來源，也不改動已有 127 篇其他版本審核決議。
- 僅這四份有直接 R1 限定主張與抽樣 R2：SRC-0363 → CLM-COMBAT-0001、SRC-0379 → CLM-COMBAT-0002、SRC-0383 → CLM-COMBAT-0003、SRC-0384 → CLM-COMBAT-0004。與既有 `CLM-NET-0005/0006` 只做有界交叉引用；C2S opcode 000A、S2C app key13、socket framing、actor state 四個域不能混為單一確定 ACK 流程。
- 其他 **18/22** 這一批研究原稿仍 REGISTERED/PENDING，T10 早期來源亦不因本輪被升格；原 T10 127 份大範圍 canonical 整合不是本批已完成事項。沒有 S00/T01 的新 full-pass 或 SPEC_CONSUMABLE，也沒有臆造缺失的 `SPEC-COMBAT-*` ID；未建立非使用者授權的 RR。
- T08 138 原稿、已查 24 個映射 FAILED、既有局部反證/更正，保留前次 T01 R1 原樣，這次只實際合入該分支唯一獨有之固定指令檔與提交歷史。其不同 actor/resource/wrapper field offsets 不用來自動佐證 T10 虛表。
- 兩 Task 研究指令文檔中早期「同步方向 main→Task」的限制，是 **Task 研究新段開工**規則；這次係使用者另行明確要求 T01 反向整合 Task→main，PR 實際操作合法，後續研究新段仍依專屬分支隔離。

## 4. 交 S00／T01 的有界導航與開放問題

| 玩家場景／類別 | Client 靜態支持 | 尚未證明；後續主責 |
|---|---|---|
| 實體 Z／Key44 → phase／UI → 戰鬥 tick | 4914AC→6D1480 一條原生更新呼叫；先前 T10-102/103 提供裝置／matrix導航 | 當前 bank、UI 消耗／phase override、真實每次事件發包數：T10 待逆向 |
| 控制器輸出 app C2S 000A | 545824/545B71、vtable+10、8069A0 選連線與待送入口（有條件） | 000A 每列各 actor 的所有字段、何時 WSASend 實際提交、wire framing、Server acceptance：T10/T02，Server 待開發 |
| S2C app key13 → actor | 4B01C0 9-byte 解析/actor virtual+58；七張 vtable slot 寫 actor+B0 | key13 是否為某次 000A 的回覆、動作/技能時序與 motion clip：T10/T09，跨功能待整合 |
| 正式原生驗收與相容 Server | R0 identity + 四條 PARTIAL bounded R1/R2 | 全文 T01 FULL-PASS、S00 SPEC/STABLE、Server 實作與原版 Client 遊玩驗證均未完成 |

## 5. 本次範圍與驗證界限
- 這是 **T01 合併 + 4 條限定主張**，不是 T10 127 份研究全文 R1/R2。原稿研究者提出的其他主張保留原先 PENDING；不因來源存在、CI 綠燈或某些 bytes 抽查而改動原稿歷史 FULL_PASS/FAILED、NEEDS_FIX 或 task.json/native_complete。
- 正式權威以合併後最新 `research/intake/index.json`、`research/claims/index.json`、`research/requests/index.json` 為準；本報告只作帶精確證據的 T01 審核操作紀錄。
- 本報告並未修改原始 BIN/EXE、沒有執行遊戲、沒有網路抓包、沒有對原版 Server 或 Client 可玩性作出肯定結論。

## 附錄：此次 T10 22 篇原始 SHA/blob 導航（均已原樣存在 main）

| SRC | 完整檔名（於 kr-temp-roy/） | Git blob SHA1 | 本輪 R1/R2 |
|---|---|---|---|
| SRC-0363 | `20261028-1843-chatgpt-web-roy-T10-101-phase-writer-consumption-and-transport.md` | `388d050b133af5325424391fb5eb487922f7cf5f` | bounded R1/R2 |
| SRC-0364 | `20261028-1855-chatgpt-web-roy-T10-102-directinput-key44-and-battle-tick-order.md` | `1a034ab7112645f0996266c42ed47e5d8b52aeb1` | R0 REGISTERED |
| SRC-0365 | `20261028-1906-chatgpt-web-roy-T10-103-input-skill-matrix-and-tick-countdown.md` | `5eda574c9d7b32c01def1cc97f0024fdb3027c2c` | R0 REGISTERED |
| SRC-0366 | `20261028-1914-chatgpt-web-roy-T10-104-actor-3e8-property4-and-force-effect.md` | `05dcaf39ac7a5326f2b2850b18f4f92b21e39bd2` | R0 REGISTERED |
| SRC-0367 | `20261028-1919-chatgpt-web-roy-T10-105-paramupdate-handler-and-property-dispatch.md` | `9b12f6f3572a1f15540fa9a874a21bb8056aee52` | R0 REGISTERED |
| SRC-0368 | `20261028-1942-chatgpt-web-roy-T10-106-queue-header-key-and-dispatch-bases.md` | `b9873d454eca75147c3251b85aed7f54929ecb5f` | R0 REGISTERED |
| SRC-0369 | `20261028-200349-chatgpt-web-roy-T10-101-KR-virtual-dispatch-second-domain.md` | `6d456ac37490d29016b3dd9508902bc6da846f71` | R0 REGISTERED |
| SRC-0370 | `20261028-201335-chatgpt-web-roy-T10-107-branch-merge-evidence-reconciliation.md` | `c1213e91ad89775dcbace3b9de2c667d9c5efbcb` | R0 REGISTERED |
| SRC-0371 | `20261028-201500-chatgpt-web-roy-T10-102-KR-event-container-cleanup-and-caller-matrix.md` | `dee434518439b49db91415ee4912d55e52c57cf1` | R0 REGISTERED |
| SRC-0372 | `20261028-201546-chatgpt-web-roy-T10-108-KR-framed-receive-to-queue-producer.md` | `804572ab576259cc82162f56d68379b4f0f7d940` | R0 REGISTERED |
| SRC-0373 | `20261028-202433-chatgpt-web-roy-T10-109-KR-queue-owner-class-event-and-empty-record.md` | `dcc4609011535695f4573f5af4e729d150b146c8` | R0 REGISTERED |
| SRC-0374 | `20261028-203129-chatgpt-web-roy-T10-110-KR-IOCP-completion-to-frame-consumer.md` | `c63e65b5c3270ec3bb1b5339960668bae106ade3` | R0 REGISTERED |
| SRC-0375 | `20261028-204203-chatgpt-web-roy-T10-111-KR-WSARecv-WSASend-IOCP-overlapped-and-category-writer.md` | `af59cc9b4c11586b65989701d6e169d864e14876` | R0 REGISTERED |
| SRC-0376 | `20261028-204914-chatgpt-web-roy-T10-112-KR-connection-vtable-and-outbound-buffer-lifecycle.md` | `e236268d27bf0c54fa626e330cc8d84549ca883b` | R0 REGISTERED |
| SRC-0377 | `20261028-205943-chatgpt-web-roy-T10-113-KR-pending-send-pump-and-virtual-transport-gate.md` | `c23374e904a1977e6fd3b4eafc29db953801cf89` | R0 REGISTERED |
| SRC-0378 | `20261028-212516-chatgpt-web-roy-T10-114-KR-transport-vtable-to-WSASend-closure.md` | `4c58fab0d36bcc57914c0916ec1d39ee2c6a8e63` | R0 REGISTERED |
| SRC-0379 | `20261028-213024-chatgpt-web-roy-T10-115-KR-C2S000A-builder-to-pending-transport-closure.md` | `e5de0249c0fdc0b97685e68b76921510e57aea78` | bounded R1/R2 |
| SRC-0380 | `20261028-213248-chatgpt-web-roy-T10-116-KR-000A-five-byte-row-field-provenance.md` | `8da51d9e77d3d900bc73743bddc82891f6829c15` | R0 REGISTERED |
| SRC-0381 | `20261028-223848-chatgpt-web-roy-T10-117-KR-selector-registration-to-000A-transport-tree.md` | `01607b45a2decdc526063081ad6020b3d8742e0e` | R0 REGISTERED |
| SRC-0382 | `20261028-224346-chatgpt-web-roy-T10-118-KR-selector0-category2-connect-callers.md` | `8f00225b580fab47b9d7964c9bdf6511047c911f` | R0 REGISTERED |
| SRC-0383 | `20261028-225025-chatgpt-web-roy-T10-119-KR-S2C-key13-nine-byte-actor-motion-consumer.md` | `d44df2cf097e112ff98a78ebd918fbf9910b8952` | bounded R1/R2 |
| SRC-0384 | `20261028-225505-chatgpt-web-roy-T10-120-KR-actor-vtable58-state-writer-and-vtable68-effects.md` | `d0efddc90c9943bbad3bc121ad9898304f11d8ea` | bounded R1/R2 |

## 後續具體工作
1. T01 以既有 `t01-t10-roy-20261029/early`、`middle` 之候選為基礎，完成 127 篇跨區 canonical 去重；不可把提案自動當新證據。當出現高風險衝突或原生門檻，再挑確切函式做 R2。
2. T10 繼續 Client 尚未知 Z phase/000A 與 app key13、motion clip／cancel/連段時窗之實際邊界；T02 僅維護 framing/IOCP 共用層；S00 依具體 Spec/GAP 再決定受納，不要猜 Server 規則。
3. 若已經有其他 Agent 更動原稿或 claim 狀態，應以當時最新 main Git blob 與正文重新核對，不能用本報告的快照覆蓋後來更新。
