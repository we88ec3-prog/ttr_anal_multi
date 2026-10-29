# KR Bulk 中央 QA 第十六段：第一個 FULL-PASS 精確主張候選（2026-10-29）

**提交狀態：FULL-PASS CANDIDATE — T01 PENDING REVIEW。不得當成已獲 T01 FULL-PASS。**

## 研究目標及決策依據

使用者明確要求優先取得第一個 FULL-PASS。依 `shared/T01-FULL-PASS-UNCLASSIFIED-INTEGRATION-RULES.md`（Git blob `177bcf06343dec13a5535a6081ebfc205e7d406b`），FULL-PASS 可對「精確主張／有界子流程」作出，而不必驗完整個函式群、遊戲功能或 Server；但必須由 **T01 正式審核**，本工作分支 `extra/roy2` 不得越權寫入 `shared/verified-knowledge/`。

選擇具有最少 CFG 與資料流歧義的原生函式 `VA 0x008DC2F0`，並將範圍限制為**本函式入口開始，在正常 CPU 執行與正常返回條件下的直接程式碼行為**。

## 原件、PE 與雜湊

- 上傳原件：`/mnt/data/Tartaros.bin`，12,472,320 bytes。
- 實測 SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- PE header `e_lfanew=0x120`，ImageBase `0x00400000`、4 sections。
- `.text`：RVA `0x00001000`，VirtualSize `0x007D01F0`，raw pointer `0x400`，raw size `0x007D0200`。
- `.rdata`：RVA `0x007D2000`，raw pointer `0x007D0600`。
- `VA 0x008DC2F0` 所屬 `.text`；RVA `0x004DC2F0`，raw `0x004DB6F0`，二者依 PE section map 計算（VA - `0x00400C00`）。

## 第一手 BIN：完整函式 byte 與 x86 CFG

從 raw `0x004DB6F0` 直接取得：
```asm
008DC2F0  33 C0     xor eax,eax
008DC2F2  C3        ret
008DC2F3  CC        int3       ; 後續 padding（非可達函式本體）
008DC2F4  CC        int3       ; 後續 padding
```

CFG：**一個 basic block；無條件分支、無直接／間接 call，`xor eax,eax` → `ret`**。沒有在本體中取用 incoming stack arguments、讀取記憶體、寫入 global／heap 或更動堆疊局部欄位。 `ret` 依 CPU 語意會讀取堆疊頂端返回位址並更新 ESP；這是正常返回動作，不應將「無存取任何記憶體」作過度泛化。

**適合 T01 審核的精確主張：**
> 在這份指定 SHA256 的 x86 Client BIN 中，從 VA `0x008DC2F0` 進入時，依正常 x86 執行，函式先將 EAX 清零，隨後直接執行 `ret`；不經其他基本區塊、沒有顯式資料存取或其他函式呼叫，故正常返回時 EAX=0。

**反例／邊界：** 不涉及任意地址跳入、異常堆疊、執行時程式碼修改、外部 hook、CPU 非正常例外。不能將「本體回傳零」擴大成「呼叫者所有功能均無效果」，因為 caller 本身可能初始化、寫表或在 return 後更新狀態。

## 上游原生 xref：72 次 push 的有界核驗

取 `FUN_0055D7E0` 所在 raw `0x0015CBE0`–`0x0015D6D2`（end exclusive），搜尋精確 x86 push 立即數序列：

```asm
6A 00               push 0
68 F0 C2 8D 00      push 0x008DC2F0
```

**本次本地原始 BIN 重新實測：72 次。** 第一處位於 raw `0x0015CBEE`、VA `0x0055D7EE`，當地指令：
```asm
0055D7EE  6A 00                push 0
0055D7F0  68 F0 C2 8D 00       push 0x008DC2F0
0055D7F5  8B D8                mov ebx,eax
0055D7F7  E8 B4 7D 19 00       call 0x006F55B0
0055D7FC  8B 33                mov esi,[ebx]
0055D7FE  BF 7C 02 C1 00       mov edi,0x00C1027C
0055D803  B8 EE D8 FF FF       mov eax,0xFFFFD8EE
0055D808  E8 83 7F 19 00       call 0x006F5790
```

caller 支持其作為 script registration 中的 closure-like callback pointer。**72 個參數位置指向相同函式**屬於可重現的上游觀察；全域所有 xref、是否被其他 table 後續重綁，未全面驗證。

## 對既有來源與反編譯的交叉核驗

- 第十四段來源 `shared/reviews/KR-BULK-CENTRAL-QA-ROUND-14-20261029.md`，保存 72 個 EDI script keys 與此共同 callback 的觀察；第十五段另保存 Rebind／DeleteAllObject handler 的不同路徑。
- 本段以 **BIN 為權威**，不將字串名稱、上一段偽碼或 GitHub bulk 索引完整性當成證明此短函式的必要條件。
- 不聲稱對整個 script module、72 個名字的可用性或玩家劇情流程 FULL-PASS。

## T01 正式驗收待辦清單

1. T01 在符合相同 SHA 的獨立原件環境重新確認 `.text` 映射、完整 bytes `33 C0 C3` 及 CFG/basic block。
2. 確認此精確主張與 `shared/verified-knowledge/` 已收錄內容不重複／衝突，並記錄審核者、時間、來源 Git blob SHA、本段提交 SHA。
3. 如經 T01 驗收，在 **T01 授權分支／流程**建立不按 Task 分類的精確共用知識條目；不能以本報告已提交替代決議。
4. 函式語意之外的上游 72 組註冊、有效腳本功能、Server 與遊玩狀態全部明示為不在此 FULL-PASS 候選範圍。

## 責任邊界

- **Client 待逆向**：Script table 的實際更新者、72 名稱的真正函式實作、Rebind 與 DeleteAllObject 完整生命週期。
- **Server 待開發**：此純 Client stub 沒有導出確定的 wire contract 或相容 Server 需求。
- **跨功能待整合**：可供 Script/UI/場景 Task 查找共同 stub 的確定行為，但正式復用需 T01 審核。
- **待遊玩驗證**：未動態執行原遊戲；本精確候選為原生靜態驗證，不是可玩性測試。

## 三輪門檻

第 1 輪已完成一個有界原生函式的完整單塊 CFG、返回值、可見副作用／反例及至少一類 upstream caller xref，達到本輪「產生可供 T01 驗收精確主張」目標。第 2、3 輪未啟動。**本報告狀態僅為 T01 待審候選，不是正式 FULL-PASS 計數 1。**
