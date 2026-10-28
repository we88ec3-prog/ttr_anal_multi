# T01-20261028-09 — 可取得第一手證據的限定驗收與缺件登記

> 使用者指示：現階段可直接驗證的先行驗收；無法取得的原件先跳過，逐項註記。本批僅對**實際讀到並重驗的位址／局部機器碼**標記通過；不因某檔通過部分指令驗證，將整份報告、整個函式或整個遊戲流程標為 native complete。

## 來源與操作

- 索引基準：`T01-20261028-07`（T08 173–200 共 28、T10 081–100 共 20、T16 41–68 共 32，80 份）；`T01-20261028-08`（T16 41–44 八份獨立原稿的配對與差異）。
- 本次直接讀取本機 `/mnt/data/Tartaros.bin`（12,472,320 bytes）和 `Tartaros.exe`，執行 `sha256sum`、`file`、`objdump -h` 與 **唯讀**定址反組譯、raw byte 比對；未執行或修改目標。
- KR BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` — **本批直接驗算通過**。
- KR EXE SHA256：`03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f` — **本批直接驗算通過**。
- PE32 x86 sections：`.text` VA 0x00401000/raw 0x400，`.rdata` VA 0x00BD2000/raw 0x007D0600，`.data` VA 0x00D61000/raw 0x0095E800 — **本批由 objdump -h 通過**。僅限 `.text` 內，`raw = VA - 0x00400C00`。
- 同時從 GitHub `main` 讀回 T16 41–44 兩組 Markdown、T08-200、T10-100、T16-68，並核對對應 Git blob SHA。以下內容是**抽樣、限定指令**的實際驗收，不是宣稱 80 份逐行審畢。

## 直接 BIN 驗收紀錄

| Task／原稿 | 位址與直接原始證據（BIN raw bytes） | 本批通過的最小主張 | 仍未驗收 |
|---|---|---|---|
| T16-43 B：`kr-temp-roy/20261028-095118-chatgpt-web-roy-T16-43-KR-tutorial-to-quest16-quest15-evidence.md` | `004A8A31: 68 7C 68 C0 00 E8 15 C0 24 00`、`004A8A41: 68 94 68 C0 00 E8 85 C3 24 00` | 直接 push 常數後 call `0x006F4A50`、`0x006F4DD0`；兩個具名腳本處理路徑的本地 callsite bytes 存在。 | 常數字串實際內容／Lua 事件語義、場景結果→Quest16→Quest15。 |
| T16-41 B、T16-44 B：`20261028-095118` 兩份對應原稿 | `004A8A8A: C7 05 A0 A7 FB 00 00 00 00 00`、`004A8B53: 6A 06 8D 45 EC 50 6A 00 FF D2` | 直接對照原稿的初始化存值、push 參數與間接 call 指令片段，byte 對應通過。 | 間接 call 動態 receiver/vtable、quest state writer、server authority。 |
| T16-42 B：`20261028-095118-chatgpt-web-roy-T16-42-KR-quest-XML-versioned-source.md` | `0050478B: B9 48 DB C0 00` | Quest XML loader 入口附近 `mov ecx,0xC0DB48` 的直接指令存在；原稿的 `0x00504740` 入口反組譯部分得到支持。 | 常數所指字串內容與完整 XML row、Quest 15/16 schema。 |
| T08-200：`20261028-111046-chatgpt-web-roy-T08-200-registration-identity-and-duplicate.md` | `004DFF4C: 0F B7 47 04`; `004DFF5F: E8 9C EF 34 00`; `004DFF67: 3B 53 0C 75 24`; `004DFF82: E8 79 F2 34 00`; `004DFF90: 8B 4D 08 51 68 F0 CE C0 00 E8 C2 DB 20 00` | 使用 `actor+4` 讀 16-bit lookup key，call `0x82EF00`；比較 `owner+0xC`、非等值跳到 `0x4DFF90`，等值路徑 call `0x82F200`，非等值路徑 call `0x6EDB60`，均與 BIN 指令一致。 | 完整 tree payload 型別、重複 key 的 actor ownership、所有上游與析構路徑。 |
| T16-68：`20261028-110904-chatgpt-web-roy-T16-68-KR-quest16-quest15-native-handoff.md` | `004AB8B8: C7 05 7C 18 FE 00 D0 A4 4A 00`; `004AA4D0:` 開頭 `55 8B EC 51 83 3D 98 A7 FB 00 00` | `[0x00FE187C] = 0x004AA4D0` 的靜態 callback slot writer **直接通過**；`0x004AA4D0` 的原生入口 bytes 存在。 | writer 執行時序、所有 alias writer、socket 路徑、server ACK、Quest 完成。 |
| T10-100：`20261028-1102-chatgpt-web-roy-T10-100-input-dispatch-closure-matrix.md` | `005961C0` 開頭 `55 8B EC 6A FF 68 EA AE 93 00`；`00596351` 開頭 `8B 5D 08 8B 33 8B 56 04`；`00560239` 開頭 `89 1D E8 73 FB 00 89 1D EC 73 FB 00` | 三個入口原始 bytes 存在；`0x560239` 片段有針對 `0xFB73E8` 與 `0xFB73EC` 的直接 stores，但這個局部片段**不單獨驗證 store value 是零或完整 writer universe**。 | KeyMapping 原始 XML 欄位、40 個 ID 的完整 loop、listener vtable 真正目的地、phase 非零 writer、C→S 封包與普攻連段完整閉環。 |

### 純 ASM 的可回溯再現

對原始 PE 只做局部反組譯。例如：

```bash
sha256sum /mnt/data/Tartaros.bin /mnt/data/Tartaros.exe
objdump -h /mnt/data/Tartaros.bin
objdump -D -M intel --start-address=0x4dff4c --stop-address=0x4dff9f /mnt/data/Tartaros.bin
objdump -D -M intel --start-address=0x4ab8b0 --stop-address=0x4ab8d0 /mnt/data/Tartaros.bin
```

`0x004DFF67` 解成 `cmp edx,[ebx+0xc]; jne 0x004DFF90`。此指令確認**局部分支**，不能單靠它宣稱「所有 duplicate 都不釋放 actor」；後者需追其他 caller/callee。

## T16 同段雙原稿驗收處置

- **T16-41 A/B**：Lua source SHA、prototype 數來自既有 T01 資源稽核；此次可確認 B 的部分 BIN callsite 指令，**沒有重驗 Lua chunk 原始 bytes**。結論：`bounded-native-callsite-pass` + `resource-deferred`。
- **T16-42 A/B**：本次核對 B 的 XML loader 局部指令；A/B 的 XML root/child、carrier offset 仍是**已保存之 T01 來源稽核記錄**，非此次 direct-file 驗收。結論：`bounded-native-loader-pass` + `resource-deferred`。
- **T16-43 A/B**：局部 Lua loader/bridge 調用指令已直接核對；`scenario14→TUTO→Quest16→Quest15` 仍只是待證邊，不能由 callsite 推出狀態轉換。結論：`bounded-native-callsite-pass` + `quest-flow-unverified`。
- **T16-44 A/B**：局部初始化／間接呼叫模式與既有 A/B 研究範圍相容，**未查到完成 request→validate→write→notify→restore** 的全鏈。結論：`bounded-native-instruction-pass` + `server-authority-unverified`。
- 以上並非 A/B 之間每一條技術主張都已逐項仲裁。原稿均保留兩份，按完整路徑與 Git blob SHA 區分，不取其一覆蓋。

## 缺件與跳過登記（deferred，不視為反證）

| 所缺原件 | 本批可否直接讀取 | 本批處置／被阻塞的主張 |
|---|---|---|
| KR `Event.stp` 原始封裝及已解的 `TutorialMain.lua` / `TutorialBase.lua` / `qbase.lua` bytecode/text | 否；僅能見既有稽核與報告所載摘要 | `DEFERRED-RESOURCE`；Lua 事件、terminal callback、教學逐步狀態不可升級。 |
| KR `Table.stp` 及已解 `QuestInfo.xml`、`QuestTalk.xml` row | 否；僅能見舊摘要 | `DEFERRED-RESOURCE`；Quest 15/16 原始 row、前置條件、NPC、獎勵不可驗收。 |
| TC 原始檔／對應 Lua/XML bytes | 否 | `DEFERRED-TC`；本次只驗 KR BIN；不跨版本。 |
| 官方 server quest writer/ACK、跨登入 snapshot、實際封包資料 | 否 | `DEFERRED-SERVER`；任務權威、持久化、重登與遊玩驗收均未進行。 |
| T10 KeyMapping 原始 XML bytes／裝置事件與 C→S 動態證據 | 本批未能直接解出完整原件 | `DEFERRED-INPUT`；`Key=44..47` 僅引用前段原稿，不能本輪稱直接驗證。 |
| 80 份研究原稿的其餘完整函式與跨函式上下游 | 可在 GitHub 選讀，但本批**未逐函式完整覆蓋** | `PENDING-BOUNDED-REVIEW`；不得以小樣本驗收代替其餘 80 份正式驗收。 |

## 接續驗收原則及全局狀態

1. **通過的範圍僅限表中列示 bytes／局部分支、BIN/EXE hash 和 PE 映射。** 當局部直接證據不足時，不擴大為整函式語義或「原版 Server 行為已確認」。
2. 保留 `T01-20261028-07` 對 80 份來源的「已收件」紀錄；本次只增加一小部分獨立可重驗的 first-hand validation，沒有宣稱把 80 份一律提升驗收。
3. `shared/source-review-status.json`、`shared/catalog.json`、owner、`kr-temp-roy/` 原始技術稿均不變；本次驗收記錄放在獨立 T01 integration 檔，以免舊狀態機器索引被「部分通過」誤解成全體通過。
4. 日後補資源時先驗 raw SHA、容器版本及與 BIN 的關聯，然後只解除對應阻塞；不得因任一檔案補上就推論 Quest16→Quest15 或連段可玩。
5. 下批可優先按 T01-07 清單擴大逐原稿 ASM 抽查與全文論點仲裁，逐行產出精確檔案 blob SHA／VA／raw bytes／claim／pass-or-deferred；不能把本批未覆蓋的 80 份說成已驗收。
