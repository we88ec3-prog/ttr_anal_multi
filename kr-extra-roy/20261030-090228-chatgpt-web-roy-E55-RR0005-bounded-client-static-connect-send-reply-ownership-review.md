# E55 — RR-0005 KR T02：以原件再審 Connect／slot／首次送出／回覆接收／關閉和重連所有權（目標導向靜態研究）

- 日期：`2026-10-30T09:02:28+0800` Asia/Taipei；`chatgpt-web roy`。**E55 是研究與 RR 靜態交付證據綜合，不是 Server 觀測或 T01 FULL-PASS。**
- 原始 KR：`Tartaros.bin` bytes=`12,472,320`；SHA256=`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；未執行、未改檔、未連接任何 Server。
- PE `.text`: VA=`0x00401000`，raw=`0x00000400`，size=`0x007D01F0`；對原始 `.text` 起點切片後 `objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000`，每段從既有可證入口開始；不以 arbitrary intra-instruction 起點當函式入口。
- 開工 GitHub：`main=dbaf50a1dc1ff119e942458f79700bd18e8c7004`，`extra/roy1=8cf7693d26d813aa87d5aed19a90af4b148149dd`；RR-0005 KR T02 `ACTIVE/CLAIMED`，尚無 `submission`；主線有其他 Agent 提交，不能覆寫或假定落後分支等於合併完成。
- 方法界限：此次新證據直接讀原始 BIN；歷史 E44/E45/E50/E51/E52/E53/E54 限定主張來源依列出的 Git SHA 與本地完整原稿，未做全篇 T01 審查。

## RR-0005 唯一權威研究問題與目標

`question`：Join T03 `0x13` response and choice UI with KR `0x495610/0x4957C0` Connect call sites; derive actual conditions/order, close/retry/slot ownership and initial frame per connection. Separate legacy static port values from server deployment recommendations.

`acceptance_criteria`：Bound actual KR Client Connect/close/port roles and `0x13` login-to-choice handoff sequence including first sender/response, error/retry behavior, **without inventing endpoint authority**.

本稿將每個子目標分成「靜態 Client 可證的控制／資料流」、「尚需其他 Client 靜態 work」、「純 Client 靜態不足以證明的原版 Server/runtime 事實」。**不得使用已找到重大發現、15/20 個單元或有 Markdown 作為研究完成的理由。**

## 已有完整原稿的權威識別（非自行提高為 FULL-PASS）

| 來源 | 版本 / 核對 | 可引用的有界技術範圍 |
|---|---|---|
| E44 | Git blob `3b3aa88bcb7de51440a31b8798121b2aa53a43f3` | S2C `0x0013/0x007A` 二級 handler、列表 `0x4C3080`、UI `0x66C090` |
| E45 | Git blob `0ff5b0d86ddac2a6b75e8922a48cd3cd2f02a9a9` | 4-octet IPv4 文本拼接、record+0xC 選服來源、接收條件 |
| E51 | Git blob `356d4659d8069c42f05492002b00476a778171bb` | 同 key replace、Manager vtable、Pool 回收、IOCP SEND 計數 |
| E52 | Git blob `6fb5baab06fc9d564ed296742d092973b7bf1779` | Conn queue drain、fresh/reuse throttle、有界 close |
| E53 | local `20261030-040946-chatgpt-web-roy-E53-RR0005-pool28-to-48-virtual-update-prewarm-lifecycle.md`，本次應 Push | Pool+28/48 → reset 生命週期、`0x490FE0` virtual 來源 |
| E54 | local `20261030-042000-chatgpt-web-roy-E54-RR0005-first-send-drain-frame-dispatch-pump-key-slots.md`，本次應 Push | 57-byte key0 enqueue → send pump → IOCP receive → queue → handler |

## E55 新核對 1 — key1 `0x495610` 的六個 direct-call 上游不等價

以 `.text` 全區 raw byte 掃描 `E8 rel32` **候選位址**，找到 `0x495610` call site `0x6D6377`, `0x6D6424`, `0x6D6508`, `0x6D65C8`, `0x6D670C`, `0x6D696C`，再從各 caller 合理入口的完整 disassembly 驗證 `call` 是真指令而非資料 byte 命中。

| direct call | 第三引數 / 成功路徑 | 第一筆同 caller 的本地送出候選 | 分級 |
|---|---|---|---|
| `6D6377` | `push 0`；成功則進上層 callback `6D63E9` | 此函式無直接 `Manager+0x10` 送出呼叫 | N（局部函式範圍） |
| `6D6424` | `push 0`；成功則到 `6D6498` 間接方法 | 此函式無直接 `Manager+0x10` 呼叫 | N（局部函式範圍） |
| `6D6508` | **`push 1`**；成功則 `6D6563` 設 `len 0x38`、`key 1`，Manager vtable+0x10 | 56-byte 本地 send-by-key 佇列候選；payload 前處理由 `6D6B70` | N（entry/len/key）；不是實際 wire |
| `6D65C8` | `push 0`；成功則 `6D6683` 設 `len 0x68`、`key 1`，Manager vtable+0x10 | 104-byte 本地送出候選；前置 `WORD 0x00E1` at `6D665B`，其餘需依 builder 確認 | N/C |
| `6D670C` | `push 0`；成功則 `6D687F` 設 `len 0x2CE`、`key 1`，Manager vtable+0x10 | 718-byte 本地送出候選；前置多個 0x100/0x66-length copy，非單純相同首包 | N/C |
| `6D696C` | `push 0`；成功則 `6D6ADF` 設 `len 0x2CE`、`key 1`，Manager vtable+0x10 | 718-byte 本地送出候選；與前條件可能共用編碼布局，不能直接宣稱二者發送時間相同 | N/C |

**關鍵新結論**：`0x495610` 是 key1 Transport connect helper，不是其每個 caller 的「固定首封包」產生者；同一 helper 的上層有 0x38/0x68/0x2CE 長度及 callback-only 支路。`0x6D6508` 的第三引數 `1` 在 `4956B8→4956E0` 允許先向 key0/key2 發 shutdown-by-key，其他五處傳 0 不具有同一前置 shutdown gate。對相容 Server 不可將 key1 封包固定填成 key0 的 57-byte `0x0001`。

## E55 新核對 2 — key0/key2 `0x4957C0` 的可觀察順序、成果與失敗路徑

只找到 `0x66C1A7` 和 `0x66C247` 兩個直接 `E8` caller；其上游根據 E44/E45 為 `0x66C090` lookup，從被解析的選服 `record+0x0C` 取得 IPv4 dotted-decimal ASCII 候選地址。`0x4957C0` 使用同一參數先呼叫 Manager vtable `+0x18`（key0，port=0x20E0，lane=2），再呼叫（key2，port=0x20DE，lane=2）。兩個 Connect 都非 NULL 才執行後續 `key0` 57-byte local queue（`0x495935`）、為兩個 Conn 各呼叫 vtable `+0x14` post-WSARecv（`0x49594A/0x495958`），最後按 `ESI=Client-like*` 存 `Client+BF64=key0Conn`、`Client+BF68=key2Conn`（`49595B/495962`）。

若 key0 非 NULL 但 key2 NULL，`0x49597E` 呼叫 Manager `+0x20` 對 key0 shutdown；若 key0 NULL 而 key2 非 NULL，`0x4959C1→4959D0` 對 key2 shutdown。這兩個分支均回傳0，而非在該函式內再次 Connect / close-by-Conn / map-erase。`0x4959B0` path 也沒有必然 full cleanup。**負面結論限這個函式，不代表其他邏輯全域沒有 retry**。

`Client+BF60` 是另一路 key1 Conn 保存槽（`0x495794`），在切換選服成功時可能進入 `0x495820→0x495868`：將兩-byte `0x007E` 本地排給舊 BF60 Conn，置 `Conn+A0B0=1`，清 `Client+BF60=0`。這既不是 key0 的 `0x0001`，也不代表已送 wire。`Client+BF64/BF68` 在本函式成功分支才更新，不能推說部分 Connect 失敗已填入新值。

## E55 新核對 3 — `0x806AD0` 成功回傳與舊 Conn 的所有權須分離

Manager vtable `0xC51748+0x18 = 0x806AD0`。函式先呼叫 Pool `0x805950(1)` 取得新/reuse Conn，寫 `Conn+A0B4=2` 與 `Conn+A080=[ebp+0x14]`（lane）；在設定 sockaddr 後建立 `socket`、`connect`、選項設定、`CreateIoCompletionPort`，進行 key 查找與同-key 替換。

`0x806C9E` 以 tree-find 查舊 key；如果找到，`0x806CB3→0x7B6890` 刪除的是 **map node**；接著 `0x806CC7→0x57EF20`、`0x806CD2→0x57E850` 將新 Conn 插入 map。該函式沒有取得 `oldConn*` 並呼叫 `vtable+0x24` close-by-pointer 的 direct path。**不能因 key 被新 Conn 覆蓋而認定舊 socket 已關閉。**

`0x7B6890` 更深入查至 `0x7B6AC6`：對移除的 node 走 `0x89120C` deallocate，再 `0x7B6ADA..0x7B6AE6` 遞減容器 count／寫 next iterator；這是 tree-node 回收證據，不是 `Conn+0` socket close 證據。舊 Conn 若已失去 map 索引，仍可能因之前投遞的 IOCP、另外的 Conn* 槽或 Pool tracking 被後續回收；未證明每條 oldConn 路徑都必然發生，因此**僅將 same-key replacement→old Conn deterministic release 標為 U**，而不是宣稱必然 leak。

Connect failure `0x806BD4/0x806BFB` 呼叫 `0x805AF0` 把 Conn 加入 Pool+0x48；`0x805B40` 要待 `A0B8==0` 才清除並返回 Pool+0x10 free vector。`0x805F50` reset 先把 Conn socket 欄位設 `0xFFFFFFFF`、clear state / queue，並未在該函式呼叫 OS `closesocket`。因此 **Pool reuse/close/socket handle** 是三個不同事件，且失敗的 socket handle 必須另追 caller closure/WS2 return semantics，不能把 reset 當 close 證據。

## E55 新核對 4 — IOCP completion 閉合的上界與清理條件

Manager worker `0x806CF0` 中 `RECV OVERLAPPED == Conn+A030`：成功且 `Conn+A0AC != 0` 時 `0x806E08→0x807B40` framing decode，正常 return 有條件再 post-recv (`vtable+0x14`)；這個成功 branch 沒有扣 `Conn+A0B8`。`SEND OVERLAPPED == Conn+A050` 在 `0x806EC3` 用 `InterlockedDecrement(A0B8)`，失敗的 SEND 在 `0x806EF1` 也扣；失敗且 `A0B8==0` 時 `0x806F0E→vtable+0x24` close-by-pointer 並置 `Conn+A0A8=1`。`0x806DC7` 的零 bytes successful completion 也經 close-by-pointer。

Manager `+0x24 = 0x806FC0` 帶有 shutdown/closesocket 以及 `0x805A80` Pool+0x28 tracking 的局部 gate；Client virtual `0x490FE0` 對 Pool+28 每個 `Conn+A0AC!=0` 的 entry 提供 Pool+48 第三條生產者路徑（`0x49117C`），後經 `0x491203→0x805B40` 判定重用。`Conn+0x14` 在 `0x4911B7` 被清零。`Client+BF58` 若指到該 Conn 會多作 callback，但 `BF58` 相等與否不阻斷 Pool+48 轉移。

**持續中的所有權限制**：`0x806CB3` 同 key map replace 可以讓舊 Conn 仍為 IOCP completion key；IOCP failed/zero-byte receive 路徑在其後可因目前 Conn 狀態呼叫 close tracking，*但此處無法證明每個 old Conn 必有該 completion*。因此正確契約是「有條件可回收」而非「保證同步關閉」。

## E55 新核對 5 — `Client+BF58` 陰性寫入者搜尋不能擴張為全域不存在

對原始 `.text` 8,192,496-byte（0x7D01F0）執行 `58 BF 00 00` raw displacement 掃描，**只有 `0x4910C7`（指令起點 `0x4910C5 cmp [eax+BF58],ebx`）**。因這是全 `.text` 的常量樣式掃描，能直接界定「沒有其他直接 `disp32=+BF58` encoding 的出現」；但 **不能排除** `LEA`/split offset、address arith、memset/memcpy whole-object、別名指標、其他模組/動態 plugin 對 BF58 寫入。此欄位不能擅自分類成已確認的 Conn slot 或已證只讀。

`Client+BF60`、`BF64`、`BF68` 的 raw displacement 分別找到 11、3、12 個候選命中；其中 `0x495794`、`0x49595B`、`0x495962` 是已從完整程式流確認的**實際寫入**，其他可能是其他 object 共用數值不能全算作同欄位。

## E55 新核對 6 — S2C 接收能到處理器，不代表該次 session 的 first reply

**對照 E44/E45 與 E54 經原始機器碼再查重要 junction**：

`0x806CF0 IOCP recv success → 0x807B40 frame parser → 0x807D9E lane=Conn+A080 enqueue → 0x8040A0 / FC10D0 → 0x49198A mainloop → 0x804740 pop → virtual Client callback → 0x4930E0 → 0x48AAD0 → 0x494360 → 0x4FDA30 → 0x4B7EC0 → 0x4C4670 secondary-command table → 0x4C37A0 (opcode 0x0013) 或 0x4C3C10 (opcode 0x007A) → 0x4C3080 → FE1B54 group records → 0x66B910/0x66C620 UI → 0x66C090/0x4957C0`。

必要 gate：IOCP recv positive bytes、有效 frame/transform、應用 queue 正長度、Conn lane=2、該 Client callback 的 vtable identity、初/次級 handler 已安裝、`0x0013` 的 mode0 payload UTF-16 非空和變長列表可讀，選服 UI record 有效且 gate 成功。這是 **Client S2C 反應的 static reachability**。但是 `0x4957C0` 發生於列表接收及 UI 選擇**之後**，所以不能把之前的 `0x0013/0x007A` 成功列表回覆反過來宣稱為 key0 `0x0001` 送出後的第一筆 S2C。

可被 Client BIN 證明的「首回覆」只有 decoder 容許什麼、哪類命令有 handler、收到後怎麼改本地狀態；**實際第一封 Server bytes 不能由純 Client 原件得知**。此未知屬原版 Server/遊玩驗證，非擅自猜造另一個 S2C opcode，並不妨礙提交「bounded client interface」供 S00 設計，但最終 S00 是否接受由審查流程判斷。

## E55 新核對 7 — Legacy Ports / Endpoint Authority 絕不等於部署指示

| Client call path | KR Client 靜態常數 | 資料來源 | 實作方應如何使用 |
|---|---:|---|---|
| `0x495610`, key1 | port `0x20DF` (8415 decimal), lane 2 | 上層六種 caller 提供的 endpoint 文字 | **只作原生舊版協定／連線角色證據**，實際部署按相容 Server 的 ADR 與可用配置決定 |
| `0x4957C0`, key0 | port `0x20E0` (8416 decimal), lane 2 | 從選服紀錄中的 IPv4 ASCII `record+0xC` | 同上 |
| `0x4957C0`, key2 | port `0x20DE` (8414 decimal), lane 2 | 同一個 `record+0xC` | 同上 |

E45 於 native `0x4C3080/0x4C4330` 從 10-byte child 的四 octets `+4..+7` 以 `%d.%d.%d.%d` 組合文字；`0x507610→0x507B10` 放入 0x60-byte record 的 +0xC；`0x507750` 在 UI 選擇後回傳此欄位。此為 **Client endpoint 來源路徑**，未證明實際對應官方 Server IP、路由、DNS、proxy 或 deployment 可用性。

## E55 新核對 8 — RR-0005 驗收目標／反證／影響矩陣

| 子問題 | 已取得 Client 直接／可重現證據 | 保留限定／尚未解者 | 靜態提交判斷 |
|---|---|---|---|
| `S2C 0x13→choice UI` | E44/E45 二級 handler、0x4C3080、FE1B54、0x66C090 → 0x4957C0 | mode5/非0、缺失文字、frame/lane/handler gate | **有界已證** |
| key0 / key2 Connect | 0x4957C0 +0x18 calls, host record+0xC, port/key/lane/order | 異步結果/是否成功最終連線 | **有界已證** |
| key1 Connect | 0x495610，六 direct callers，第三參數分流、0x20DF | 其他 indirect callers、遠端實際 session | **有界已證** |
| 初始 C2S per Conn | key0 0x39 byte local queue；key2 該函式無直送；key1 多個 upper caller 0x38/0x68/0x2CE 或 callback-only | wire-first 受 send pump、條件、其他 sender 影響 | **靜態 bounded，非 first-wire witness** |
| 正常及部分失敗 | 兩 Conn 均非 NULL 則排 key0、post-recv、更新 BF64/BF68；部分失敗 shutdown 成功 key、回傳0 | 成功後 OS-level net result，後續重試由其他 state/callback 控制 | **局部 CFG 已證** |
| slot ownership | key1 BF60、key0 BF64、key2 BF68 成功分支，Pool/Conn+lane/A0B8 等 | BF58 欄位間接 writer 不明、同 key oldConn 沒有必然同步釋放 | **有界已證／殘留 owner 未完成** |
| stale Conn closure | 806FC0、805A80、490FE0、805B40 conditional cleanup；map erase 7B6890 節點 free | 並非所有 oldConn 保證走到 IOCP close；是否 leak 不可推定 | **條件式已證／全路徑未閉合** |
| initial S2C reply | 807B40→FC10D0→0x4930E0→0x0013/0x007A 的有條件 Client parser | **哪個 Server 指令是每個 key 的第一筆**不能從 Client-only 靜態原件決定 | **Client parser 有界已證／原版 Server U** |
| endpoint/ports | 靜態 port constants、真正 record IPv4 字串來源 | 不主張官方真實 endpoint 或 server 部署權威 | **有界已證** |

**判定**：這個矩陣可作 RR 的 S00 / T01 **有界 Client 靜態分析候選交付**，但**不應冒稱**所有 runtime session 都符合單一路徑；尤其「舊 Conn 必然釋放」和「server first S2C opcode」皆非已證。若嚴格要求全所有權終態完全確定，本稿只能是**階段性研究，不滿足 full static objective**；實際審查由 S00，不得作者自行 ACCEPTED。

### 具體未解、已查界線、解除條件

1. **舊 Conn 最終 owner**：在 `806AD0/806CB3/7B6890` 只證 map 節點 erase，`806CF0/806FC0/805A80/490FE0/805B40` 可在特定條件完成延後回收；欠缺「every replacement oldConn 必經 close」的全路徑證明。已掃上述函式與 Manager vtable，必要解除：更完整的 xrefs/全域 owner alias 分析，或可控 conn lifetime trace；不得推定 leak。
2. **BF58**：全 `.text` 直接 `disp32 +BF58` 搜尋只見 compare，欠缺 alias writer；必要解除：以更廣泛的 dataflow/whole-object construction 或有符號類別對照分析。此缺口不阻礙 BF60/64/68 直接 writer 結論。
3. **Server first response**：無原版 Server、同一會話封包或 server-side 原件；純 Client 靜態無法實證首個對端 opcode。解除需可靠一手 runtime trace、封包記錄或 Server 原件。不得以此阻止既有 Client parser 靜態成果交付。
4. **首封包的實際 wire bytes**：已追 key0 local 57 bytes、key1 多個 sender 長度、send pump/WSASend；加密/transform、排程/非同步結果不是靜態「某次 first-wire」觀測。解除需 static transform 全鏈或對等測試向量；不得補造。
5. **其他 retry**：同一 `4957C0` 失敗分支沒有直接 retry，但從其他 callback/event 再走 `495610/4957C0` 的全域有限狀態機尚未證明。解除需完整 caller/virtual event graph 與屬主旗標變更；當前負面主張只限已析函式。

### 與 Server／S00 應移交而非推造事項

- `Client 待逆向`：BF58 alias owner；same-key stale Conn 終態、其他可能 retry; key1 variable payload bytes / frame transform 未全部確定。
- `跨功能待整合`：T03 的登入／角色選擇 UI state 對這些 connect helper 的業務前後時序；E44/E45 已有靜態 handler，嚴禁回填未驗證 T03 結論。
- `Server 待開發`：按已確認 Client schema、opcode/lane/framing 作相容 Server 回覆與會話管理；當原版 Server 實際 first response 未知，應由 S00 明確記為設計選擇（ADR）與測試缺口。
- `待遊玩驗證`：wire-first ordering、socket close race、real server result、玩家成功進入角色選擇/遊玩。

## E55 研究交付狀態與後續指令

這份 Markdown 保存原件切片與可重現 xref 搜尋、六個 key1 上游 caller、新的候選第一包分類，以及 RR acceptance matrix；**有界 Client 靜態研究候選交付已具備**，但需按 `question/acceptance_criteria` 特別檢查 owner/retry 未閉合是否阻礙 `SUBMITTED`。任何 `SUBMITTED` 必須在 GitHub 確實有本稿 blob 後經 `CLAIMED→IN_PROGRESS→SUBMITTED` 正式流程；不得在研究報告字面宣稱 Git 或 S00 已接受。

## 附錄 A — 機器碼可重現的搜尋範圍及程式化檢查

- `.text` raw bytes `Tartaros.bin[0x400 : 0x400+0x7D01F0]`（PE header 確認）。
- `0x495610` xref 候選：對每個 `0xE8` instruction-like byte 計算 `srcVA+5+signed(rel32)` 是否等於 `0x495610`，並在各函式的完整正確起點再驗證。
- `Client+BF58`：在整個 `.text` 搜尋 little endian `58 BF 00 00`，結果是 `0x4910C7` 的 displacement，instruction 起點 `0x4910C5`。此陰性只針對該 encoding；未知 alias writer 仍可成立。
- 所有下面的片段都由 `.text` 正確 VA 映射重新執行 GNU objdump 而來；**它們保留真指令，非歷史反編譯器摘要**。

```bash
sha256sum Tartaros.bin
objdump -h Tartaros.bin
python - <<'PY2'
b=open('Tartaros.bin','rb').read()
open('rr5-text.bin','wb').write(b[0x400:0x400+0x7D01F0])
PY2
objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 --start-address=0x495610 --stop-address=0x4957BA rr5-text.bin
```

#### key1 helper / success / initial WSARecv

Native source: Tartaros.bin SHA256 `9741d...`; VA `0x00495610..0x004957BA`, raw start `0x00094A10`. 以下為原始 `.text` 指令重反組譯，非伪碼。

```asm
  495610:	55                   	push   ebp
  495611:	8b ec                	mov    ebp,esp
  495613:	83 e4 f8             	and    esp,0xfffffff8
  495616:	6a ff                	push   0xffffffff
  495618:	68 7c 1c 94 00       	push   0x941c7c
  49561d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  495623:	50                   	push   eax
  495624:	83 ec 08             	sub    esp,0x8
  495627:	53                   	push   ebx
  495628:	56                   	push   esi
  495629:	57                   	push   edi
  49562a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  49562f:	33 c4                	xor    eax,esp
  495631:	50                   	push   eax
  495632:	8d 44 24 18          	lea    eax,[esp+0x18]
  495636:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  49563c:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  49563f:	33 ff                	xor    edi,edi
  495641:	83 ce ff             	or     esi,0xffffffff
  495644:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  49564b:	75 21                	jne    0x49566e
  49564d:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  495654:	89 7c 24 20          	mov    DWORD PTR [esp+0x20],edi
  495658:	e8 33 bf 04 00       	call   0x4e1590
  49565d:	68 80 cc bc 00       	push   0xbccc80
  495662:	e8 b3 cc 3f 00       	call   0x89231a
  495667:	83 c4 04             	add    esp,0x4
  49566a:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  49566e:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  495675:	89 3d c0 41 f9 00    	mov    DWORD PTR ds:0xf941c0,edi
  49567b:	75 25                	jne    0x4956a2
  49567d:	b8 01 00 00 00       	mov    eax,0x1
  495682:	09 05 90 43 f9 00    	or     DWORD PTR ds:0xf94390,eax
  495688:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  49568c:	e8 ff be 04 00       	call   0x4e1590
  495691:	68 80 cc bc 00       	push   0xbccc80
  495696:	e8 7f cc 3f 00       	call   0x89231a
  49569b:	83 c4 04             	add    esp,0x4
  49569e:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  4956a2:	6a 0a                	push   0xa
  4956a4:	68 fc d1 be 00       	push   0xbed1fc
  4956a9:	6a 0b                	push   0xb
  4956ab:	68 c4 41 f9 00       	push   0xf941c4
  4956b0:	e8 49 e9 3f 00       	call   0x893ffe
  4956b5:	83 c4 10             	add    esp,0x10
  4956b8:	39 7d 10             	cmp    DWORD PTR [ebp+0x10],edi
  4956bb:	74 7e                	je     0x49573b
  4956bd:	f6 05 f8 8b fd 00 01 	test   BYTE PTR ds:0xfd8bf8,0x1
  4956c4:	75 1a                	jne    0x4956e0
  4956c6:	83 0d f8 8b fd 00 01 	or     DWORD PTR ds:0xfd8bf8,0x1
  4956cd:	68 10 e3 bc 00       	push   0xbce310
  4956d2:	89 3d fc 8b fd 00    	mov    DWORD PTR ds:0xfd8bfc,edi
  4956d8:	e8 3d cc 3f 00       	call   0x89231a
  4956dd:	83 c4 04             	add    esp,0x4
  4956e0:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4956e6:	89 3d 00 8c fd 00    	mov    DWORD PTR ds:0xfd8c00,edi
  4956ec:	89 3d fc 8b fd 00    	mov    DWORD PTR ds:0xfd8bfc,edi
  4956f2:	8b 01                	mov    eax,DWORD PTR [ecx]
  4956f4:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  4956f7:	6a 01                	push   0x1
  4956f9:	57                   	push   edi
  4956fa:	ff d2                	call   edx
  4956fc:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495702:	8b 01                	mov    eax,DWORD PTR [ecx]
  495704:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  495707:	6a 01                	push   0x1
  495709:	6a 02                	push   0x2
  49570b:	ff d2                	call   edx
  49570d:	39 bb 60 bf 00 00    	cmp    DWORD PTR [ebx+0xbf60],edi
  495713:	74 2e                	je     0x495743
  495715:	68 04 5a c0 00       	push   0xc05a04
  49571a:	e8 41 84 25 00       	call   0x6edb60
  49571f:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495725:	8b 01                	mov    eax,DWORD PTR [ecx]
  495727:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  49572a:	83 c4 04             	add    esp,0x4
  49572d:	6a 01                	push   0x1
  49572f:	6a 01                	push   0x1
  495731:	ff d2                	call   edx
  495733:	89 bb 60 bf 00 00    	mov    DWORD PTR [ebx+0xbf60],edi
  495739:	eb 08                	jmp    0x495743
  49573b:	39 bb 60 bf 00 00    	cmp    DWORD PTR [ebx+0xbf60],edi
  495741:	75 5d                	jne    0x4957a0
  495743:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495749:	8b 01                	mov    eax,DWORD PTR [ecx]
  49574b:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  49574e:	8b 40 18             	mov    eax,DWORD PTR [eax+0x18]
  495751:	6a 02                	push   0x2
  495753:	6a 01                	push   0x1
  495755:	68 df 20 00 00       	push   0x20df
  49575a:	52                   	push   edx
  49575b:	ff d0                	call   eax
  49575d:	8b f0                	mov    esi,eax
  49575f:	3b f7                	cmp    esi,edi
  495761:	75 1e                	jne    0x495781
  495763:	57                   	push   edi
  495764:	ff 15 ec 24 bd 00    	call   DWORD PTR ds:0xbd24ec
  49576a:	33 c0                	xor    eax,eax
  49576c:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  495770:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  495777:	59                   	pop    ecx
  495778:	5f                   	pop    edi
  495779:	5e                   	pop    esi
  49577a:	5b                   	pop    ebx
  49577b:	8b e5                	mov    esp,ebp
  49577d:	5d                   	pop    ebp
  49577e:	c2 0c 00             	ret    0xc
  495781:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495787:	8b 11                	mov    edx,DWORD PTR [ecx]
  495789:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  49578c:	56                   	push   esi
  49578d:	ff d0                	call   eax
  49578f:	68 f4 01 00 00       	push   0x1f4
  495794:	89 b3 60 bf 00 00    	mov    DWORD PTR [ebx+0xbf60],esi
  49579a:	ff 15 04 23 bd 00    	call   DWORD PTR ds:0xbd2304
  4957a0:	b8 01 00 00 00       	mov    eax,0x1
  4957a5:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4957a9:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4957b0:	59                   	pop    ecx
  4957b1:	5f                   	pop    edi
  4957b2:	5e                   	pop    esi
  4957b3:	5b                   	pop    ebx
  4957b4:	8b e5                	mov    esp,ebp
  4957b6:	5d                   	pop    ebp
  4957b7:	c2 0c 00             	ret    0xc
```

#### key0/key2 helper / success, partial-failure / slot writes

Native source: Tartaros.bin SHA256 `9741d...`; VA `0x004957C0..0x004959E1`, raw start `0x00094BC0`. 以下為原始 `.text` 指令重反組譯，非伪碼。

```asm
  4957c0:	55                   	push   ebp
  4957c1:	8b ec                	mov    ebp,esp
  4957c3:	83 ec 44             	sub    esp,0x44
  4957c6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4957cb:	33 c5                	xor    eax,ebp
  4957cd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4957d0:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4957d6:	8b 01                	mov    eax,DWORD PTR [ecx]
  4957d8:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  4957db:	53                   	push   ebx
  4957dc:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4957df:	57                   	push   edi
  4957e0:	6a 02                	push   0x2
  4957e2:	6a 00                	push   0x0
  4957e4:	68 e0 20 00 00       	push   0x20e0
  4957e9:	53                   	push   ebx
  4957ea:	ff d2                	call   edx
  4957ec:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4957f2:	6a 02                	push   0x2
  4957f4:	6a 02                	push   0x2
  4957f6:	8b f8                	mov    edi,eax
  4957f8:	8b 01                	mov    eax,DWORD PTR [ecx]
  4957fa:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  4957fd:	68 de 20 00 00       	push   0x20de
  495802:	53                   	push   ebx
  495803:	ff d2                	call   edx
  495805:	8b d8                	mov    ebx,eax
  495807:	85 ff                	test   edi,edi
  495809:	0f 84 a1 01 00 00    	je     0x4959b0
  49580f:	85 db                	test   ebx,ebx
  495811:	0f 84 67 01 00 00    	je     0x49597e
  495817:	83 be 60 bf 00 00 00 	cmp    DWORD PTR [esi+0xbf60],0x0
  49581e:	74 52                	je     0x495872
  495820:	e8 5b 7e fb ff       	call   0x44d680
  495825:	8b 08                	mov    ecx,DWORD PTR [eax]
  495827:	85 c9                	test   ecx,ecx
  495829:	74 07                	je     0x495832
  49582b:	8b 01                	mov    eax,DWORD PTR [ecx]
  49582d:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  495830:	ff d2                	call   edx
  495832:	8b 86 60 bf 00 00    	mov    eax,DWORD PTR [esi+0xbf60]
  495838:	50                   	push   eax
  495839:	e8 a2 0b 37 00       	call   0x8063e0
  49583e:	b9 7e 00 00 00       	mov    ecx,0x7e
  495843:	6a 02                	push   0x2
  495845:	8d 55 be             	lea    edx,[ebp-0x42]
  495848:	66 89 4d be          	mov    WORD PTR [ebp-0x42],cx
  49584c:	8b 8e 60 bf 00 00    	mov    ecx,DWORD PTR [esi+0xbf60]
  495852:	52                   	push   edx
  495853:	e8 78 08 37 00       	call   0x8060d0
  495858:	8b 86 60 bf 00 00    	mov    eax,DWORD PTR [esi+0xbf60]
  49585e:	c7 80 b0 a0 00 00 01 	mov    DWORD PTR [eax+0xa0b0],0x1
  495865:	00 00 00 
  495868:	c7 86 60 bf 00 00 00 	mov    DWORD PTR [esi+0xbf60],0x0
  49586f:	00 00 00 
  495872:	68 90 01 00 00       	push   0x190
  495877:	ff 15 04 23 bd 00    	call   DWORD PTR ds:0xbd2304
  49587d:	33 c0                	xor    eax,eax
  49587f:	b9 01 00 00 00       	mov    ecx,0x1
  495884:	66 89 4d c0          	mov    WORD PTR [ebp-0x40],cx
  495888:	89 45 c6             	mov    DWORD PTR [ebp-0x3a],eax
  49588b:	89 45 ca             	mov    DWORD PTR [ebp-0x36],eax
  49588e:	89 45 ce             	mov    DWORD PTR [ebp-0x32],eax
  495891:	89 45 d2             	mov    DWORD PTR [ebp-0x2e],eax
  495894:	89 45 d6             	mov    DWORD PTR [ebp-0x2a],eax
  495897:	66 89 4d da          	mov    WORD PTR [ebp-0x26],cx
  49589b:	89 45 dc             	mov    DWORD PTR [ebp-0x24],eax
  49589e:	88 45 e0             	mov    BYTE PTR [ebp-0x20],al
  4958a1:	89 45 e1             	mov    DWORD PTR [ebp-0x1f],eax
  4958a4:	89 45 e5             	mov    DWORD PTR [ebp-0x1b],eax
  4958a7:	89 45 e9             	mov    DWORD PTR [ebp-0x17],eax
  4958aa:	89 45 ed             	mov    DWORD PTR [ebp-0x13],eax
  4958ad:	89 45 f1             	mov    DWORD PTR [ebp-0xf],eax
  4958b0:	89 45 f5             	mov    DWORD PTR [ebp-0xb],eax
  4958b3:	e8 e8 f2 f6 ff       	call   0x404ba0
  4958b8:	8b 90 e0 67 00 00    	mov    edx,DWORD PTR [eax+0x67e0]
  4958be:	89 55 c2             	mov    DWORD PTR [ebp-0x3e],edx
  4958c1:	e8 da f2 f6 ff       	call   0x404ba0
  4958c6:	6a 0a                	push   0xa
  4958c8:	05 e4 67 00 00       	add    eax,0x67e4
  4958cd:	50                   	push   eax
  4958ce:	8d 45 c6             	lea    eax,[ebp-0x3a]
  4958d1:	6a 0a                	push   0xa
  4958d3:	50                   	push   eax
  4958d4:	e8 25 e7 3f 00       	call   0x893ffe
  4958d9:	e8 c2 f2 f6 ff       	call   0x404ba0
  4958de:	6a 0a                	push   0xa
  4958e0:	05 fa 67 00 00       	add    eax,0x67fa
  4958e5:	50                   	push   eax
  4958e6:	8d 4d e5             	lea    ecx,[ebp-0x1b]
  4958e9:	6a 0a                	push   0xa
  4958eb:	51                   	push   ecx
  4958ec:	e8 0d e7 3f 00       	call   0x893ffe
  4958f1:	c6 45 da 01          	mov    BYTE PTR [ebp-0x26],0x1
  4958f5:	e8 a6 f2 f6 ff       	call   0x404ba0
  4958fa:	8a 90 98 68 00 00    	mov    dl,BYTE PTR [eax+0x6898]
  495900:	88 55 db             	mov    BYTE PTR [ebp-0x25],dl
  495903:	e8 98 f2 f6 ff       	call   0x404ba0
  495908:	05 99 68 00 00       	add    eax,0x6899
  49590d:	50                   	push   eax
  49590e:	8d 45 dc             	lea    eax,[ebp-0x24]
  495911:	6a 05                	push   0x5
  495913:	50                   	push   eax
  495914:	e8 40 e2 3f 00       	call   0x893b59
  495919:	83 c4 2c             	add    esp,0x2c
  49591c:	e8 7f f2 f6 ff       	call   0x404ba0
  495921:	8b 88 a0 68 00 00    	mov    ecx,DWORD PTR [eax+0x68a0]
  495927:	89 4d e1             	mov    DWORD PTR [ebp-0x1f],ecx
  49592a:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495930:	8b 11                	mov    edx,DWORD PTR [ecx]
  495932:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  495935:	6a 39                	push   0x39
  495937:	8d 45 c0             	lea    eax,[ebp-0x40]
  49593a:	50                   	push   eax
  49593b:	6a 00                	push   0x0
  49593d:	ff d2                	call   edx
  49593f:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495945:	8b 01                	mov    eax,DWORD PTR [ecx]
  495947:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  49594a:	57                   	push   edi
  49594b:	ff d2                	call   edx
  49594d:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495953:	8b 01                	mov    eax,DWORD PTR [ecx]
  495955:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  495958:	53                   	push   ebx
  495959:	ff d2                	call   edx
  49595b:	89 be 64 bf 00 00    	mov    DWORD PTR [esi+0xbf64],edi
  495961:	5f                   	pop    edi
  495962:	89 9e 68 bf 00 00    	mov    DWORD PTR [esi+0xbf68],ebx
  495968:	b8 01 00 00 00       	mov    eax,0x1
  49596d:	5b                   	pop    ebx
  49596e:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  495971:	33 cd                	xor    ecx,ebp
  495973:	e8 89 b6 3f 00       	call   0x891001
  495978:	8b e5                	mov    esp,ebp
  49597a:	5d                   	pop    ebp
  49597b:	c2 04 00             	ret    0x4
  49597e:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495984:	8b 01                	mov    eax,DWORD PTR [ecx]
  495986:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  495989:	6a 01                	push   0x1
  49598b:	6a 00                	push   0x0
  49598d:	ff d2                	call   edx
  49598f:	68 3c 5a c0 00       	push   0xc05a3c
  495994:	e8 c7 81 25 00       	call   0x6edb60
  495999:	83 c4 04             	add    esp,0x4
  49599c:	5f                   	pop    edi
  49599d:	33 c0                	xor    eax,eax
  49599f:	5b                   	pop    ebx
  4959a0:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4959a3:	33 cd                	xor    ecx,ebp
  4959a5:	e8 57 b6 3f 00       	call   0x891001
  4959aa:	8b e5                	mov    esp,ebp
  4959ac:	5d                   	pop    ebp
  4959ad:	c2 04 00             	ret    0x4
  4959b0:	68 1c 5a c0 00       	push   0xc05a1c
  4959b5:	e8 a6 81 25 00       	call   0x6edb60
  4959ba:	83 c4 04             	add    esp,0x4
  4959bd:	85 db                	test   ebx,ebx
  4959bf:	74 ce                	je     0x49598f
  4959c1:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4959c7:	8b 01                	mov    eax,DWORD PTR [ecx]
  4959c9:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  4959cc:	6a 01                	push   0x1
  4959ce:	6a 02                	push   0x2
  4959d0:	ff d2                	call   edx
  4959d2:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4959d5:	5f                   	pop    edi
  4959d6:	33 cd                	xor    ecx,ebp
  4959d8:	33 c0                	xor    eax,eax
  4959da:	5b                   	pop    ebx
  4959db:	e8 21 b6 3f 00       	call   0x891001
  4959e0:	8b                 	mov    esp,ebp
```

#### key1 caller: returns callback only 6d6350/6d6400

Native source: Tartaros.bin SHA256 `9741d...`; VA `0x006D6350..0x006D64C0`, raw start `0x002D5750`. 以下為原始 `.text` 指令重反組譯，非伪碼。

```asm
  6d6350:	55                   	push   ebp
  6d6351:	8b ec                	mov    ebp,esp
  6d6353:	83 ec 0c             	sub    esp,0xc
  6d6356:	56                   	push   esi
  6d6357:	8b f0                	mov    esi,eax
  6d6359:	8b 06                	mov    eax,DWORD PTR [esi]
  6d635b:	85 c0                	test   eax,eax
  6d635d:	0f 84 8f 00 00 00    	je     0x6d63f2
  6d6363:	83 c0 0c             	add    eax,0xc
  6d6366:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  6d636a:	72 02                	jb     0x6d636e
  6d636c:	8b 00                	mov    eax,DWORD PTR [eax]
  6d636e:	6a 00                	push   0x0
  6d6370:	50                   	push   eax
  6d6371:	a1 18 13 fb 00       	mov    eax,ds:0xfb1318
  6d6376:	50                   	push   eax
  6d6377:	e8 94 f2 db ff       	call   0x495610
  6d637c:	85 c0                	test   eax,eax
  6d637e:	75 69                	jne    0x6d63e9
  6d6380:	8b 15 18 13 fb 00    	mov    edx,DWORD PTR ds:0xfb1318
  6d6386:	68 c4 0a c4 00       	push   0xc40ac4
  6d638b:	83 c2 08             	add    edx,0x8
  6d638e:	e8 6d 89 00 00       	call   0x6ded00
  6d6393:	83 c4 04             	add    esp,0x4
  6d6396:	c7 45 fc 81 01 00 00 	mov    DWORD PTR [ebp-0x4],0x181
  6d639d:	e8 0e f1 ea ff       	call   0x5854b0
  6d63a2:	8b f0                	mov    esi,eax
  6d63a4:	8d 4d fc             	lea    ecx,[ebp-0x4]
  6d63a7:	51                   	push   ecx
  6d63a8:	8d 45 f8             	lea    eax,[ebp-0x8]
  6d63ab:	8b ce                	mov    ecx,esi
  6d63ad:	e8 3e dd e9 ff       	call   0x5740f0
  6d63b2:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  6d63b5:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  6d63b8:	74 0d                	je     0x6d63c7
  6d63ba:	83 c0 10             	add    eax,0x10
  6d63bd:	83 78 14 08          	cmp    DWORD PTR [eax+0x14],0x8
  6d63c1:	72 0a                	jb     0x6d63cd
  6d63c3:	8b 00                	mov    eax,DWORD PTR [eax]
  6d63c5:	eb 06                	jmp    0x6d63cd
  6d63c7:	cc                   	int3
  6d63c8:	b8 fc d1 be 00       	mov    eax,0xbed1fc
  6d63cd:	6a 00                	push   0x0
  6d63cf:	6a 00                	push   0x0
  6d63d1:	68 fc d1 be 00       	push   0xbed1fc
  6d63d6:	50                   	push   eax
  6d63d7:	68 ca 00 00 00       	push   0xca
  6d63dc:	e8 2f e7 d2 ff       	call   0x404b10
  6d63e1:	83 c4 14             	add    esp,0x14
  6d63e4:	5e                   	pop    esi
  6d63e5:	8b e5                	mov    esp,ebp
  6d63e7:	5d                   	pop    ebp
  6d63e8:	c3                   	ret
  6d63e9:	8b 0e                	mov    ecx,DWORD PTR [esi]
  6d63eb:	8b 11                	mov    edx,DWORD PTR [ecx]
  6d63ed:	8b 42 2c             	mov    eax,DWORD PTR [edx+0x2c]
  6d63f0:	ff d0                	call   eax
  6d63f2:	5e                   	pop    esi
  6d63f3:	8b e5                	mov    esp,ebp
  6d63f5:	5d                   	pop    ebp
  6d63f6:	c3                   	ret
  6d63f7:	cc                   	int3
  6d63f8:	cc                   	int3
  6d63f9:	cc                   	int3
  6d63fa:	cc                   	int3
  6d63fb:	cc                   	int3
  6d63fc:	cc                   	int3
  6d63fd:	cc                   	int3
  6d63fe:	cc                   	int3
  6d63ff:	cc                   	int3
  6d6400:	55                   	push   ebp
  6d6401:	8b ec                	mov    ebp,esp
  6d6403:	56                   	push   esi
  6d6404:	8b f0                	mov    esi,eax
  6d6406:	8b 06                	mov    eax,DWORD PTR [esi]
  6d6408:	85 c0                	test   eax,eax
  6d640a:	0f 84 81 00 00 00    	je     0x6d6491
  6d6410:	83 c0 0c             	add    eax,0xc
  6d6413:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  6d6417:	72 02                	jb     0x6d641b
  6d6419:	8b 00                	mov    eax,DWORD PTR [eax]
  6d641b:	6a 00                	push   0x0
  6d641d:	50                   	push   eax
  6d641e:	a1 18 13 fb 00       	mov    eax,ds:0xfb1318
  6d6423:	50                   	push   eax
  6d6424:	e8 e7 f1 db ff       	call   0x495610
  6d6429:	85 c0                	test   eax,eax
  6d642b:	75 6b                	jne    0x6d6498
  6d642d:	8b 15 18 13 fb 00    	mov    edx,DWORD PTR ds:0xfb1318
  6d6433:	68 c4 0a c4 00       	push   0xc40ac4
  6d6438:	83 c2 08             	add    edx,0x8
  6d643b:	e8 c0 88 00 00       	call   0x6ded00
  6d6440:	83 c4 04             	add    esp,0x4
  6d6443:	c7 45 0c 81 01 00 00 	mov    DWORD PTR [ebp+0xc],0x181
  6d644a:	e8 61 f0 ea ff       	call   0x5854b0
  6d644f:	8b f0                	mov    esi,eax
  6d6451:	8d 4d 0c             	lea    ecx,[ebp+0xc]
  6d6454:	51                   	push   ecx
  6d6455:	8d 45 08             	lea    eax,[ebp+0x8]
  6d6458:	8b ce                	mov    ecx,esi
  6d645a:	e8 91 dc e9 ff       	call   0x5740f0
  6d645f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6d6462:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  6d6465:	74 0d                	je     0x6d6474
  6d6467:	83 c0 10             	add    eax,0x10
  6d646a:	83 78 14 08          	cmp    DWORD PTR [eax+0x14],0x8
  6d646e:	72 0a                	jb     0x6d647a
  6d6470:	8b 00                	mov    eax,DWORD PTR [eax]
  6d6472:	eb 06                	jmp    0x6d647a
  6d6474:	cc                   	int3
  6d6475:	b8 fc d1 be 00       	mov    eax,0xbed1fc
  6d647a:	6a 00                	push   0x0
  6d647c:	6a 00                	push   0x0
  6d647e:	68 fc d1 be 00       	push   0xbed1fc
  6d6483:	50                   	push   eax
  6d6484:	68 ca 00 00 00       	push   0xca
  6d6489:	e8 82 e6 d2 ff       	call   0x404b10
  6d648e:	83 c4 14             	add    esp,0x14
  6d6491:	33 c0                	xor    eax,eax
  6d6493:	5e                   	pop    esi
  6d6494:	5d                   	pop    ebp
  6d6495:	c2 08 00             	ret    0x8
  6d6498:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  6d649b:	8b 0e                	mov    ecx,DWORD PTR [esi]
  6d649d:	8b 11                	mov    edx,DWORD PTR [ecx]
  6d649f:	8b 52 30             	mov    edx,DWORD PTR [edx+0x30]
  6d64a2:	50                   	push   eax
  6d64a3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6d64a6:	50                   	push   eax
  6d64a7:	ff d2                	call   edx
  6d64a9:	b8 01 00 00 00       	mov    eax,0x1
  6d64ae:	5e                   	pop    esi
  6d64af:	5d                   	pop    ebp
  6d64b0:	c2 08 00             	ret    0x8
  6d64b3:	cc                   	int3
  6d64b4:	cc                   	int3
  6d64b5:	cc                   	int3
  6d64b6:	cc                   	int3
  6d64b7:	cc                   	int3
  6d64b8:	cc                   	int3
  6d64b9:	cc                   	int3
  6d64ba:	cc                   	int3
  6d64bb:	cc                   	int3
  6d64bc:	cc                   	int3
  6d64bd:	cc                   	int3
  6d64be:	cc                   	int3
  6d64bf:	cc                   	int3
```

#### key1 caller + one shutdown-flag=1 + 56-byte enqueue

Native source: Tartaros.bin SHA256 `9741d...`; VA `0x006D64C0..0x006D6583`, raw start `0x002D58C0`. 以下為原始 `.text` 指令重反組譯，非伪碼。

```asm
  6d64c0:	55                   	push   ebp
  6d64c1:	8b ec                	mov    ebp,esp
  6d64c3:	83 e4 f8             	and    esp,0xfffffff8
  6d64c6:	83 ec 3c             	sub    esp,0x3c
  6d64c9:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6d64ce:	33 c4                	xor    eax,esp
  6d64d0:	89 44 24 38          	mov    DWORD PTR [esp+0x38],eax
  6d64d4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6d64d7:	8b 00                	mov    eax,DWORD PTR [eax]
  6d64d9:	56                   	push   esi
  6d64da:	8b f1                	mov    esi,ecx
  6d64dc:	85 c0                	test   eax,eax
  6d64de:	75 14                	jne    0x6d64f4
  6d64e0:	33 c0                	xor    eax,eax
  6d64e2:	5e                   	pop    esi
  6d64e3:	8b 4c 24 38          	mov    ecx,DWORD PTR [esp+0x38]
  6d64e7:	33 cc                	xor    ecx,esp
  6d64e9:	e8 13 ab 1b 00       	call   0x891001
  6d64ee:	8b e5                	mov    esp,ebp
  6d64f0:	5d                   	pop    ebp
  6d64f1:	c2 08 00             	ret    0x8
  6d64f4:	83 c0 0c             	add    eax,0xc
  6d64f7:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  6d64fb:	72 02                	jb     0x6d64ff
  6d64fd:	8b 00                	mov    eax,DWORD PTR [eax]
  6d64ff:	6a 01                	push   0x1
  6d6501:	50                   	push   eax
  6d6502:	a1 18 13 fb 00       	mov    eax,ds:0xfb1318
  6d6507:	50                   	push   eax
  6d6508:	e8 03 f1 db ff       	call   0x495610
  6d650d:	85 c0                	test   eax,eax
  6d650f:	74 cf                	je     0x6d64e0
  6d6511:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  6d6514:	8b d6                	mov    edx,esi
  6d6516:	57                   	push   edi
  6d6517:	8d 74 24 08          	lea    esi,[esp+0x8]
  6d651b:	e8 50 06 00 00       	call   0x6d6b70
  6d6520:	e8 7b e6 d2 ff       	call   0x404ba0
  6d6525:	8a 88 98 68 00 00    	mov    cl,BYTE PTR [eax+0x6898]
  6d652b:	88 4c 24 32          	mov    BYTE PTR [esp+0x32],cl
  6d652f:	e8 6c e6 d2 ff       	call   0x404ba0
  6d6534:	05 99 68 00 00       	add    eax,0x6899
  6d6539:	50                   	push   eax
  6d653a:	8d 54 24 37          	lea    edx,[esp+0x37]
  6d653e:	6a 05                	push   0x5
  6d6540:	52                   	push   edx
  6d6541:	e8 13 d6 1b 00       	call   0x893b59
  6d6546:	83 c4 0c             	add    esp,0xc
  6d6549:	e8 52 e6 d2 ff       	call   0x404ba0
  6d654e:	8b 80 a0 68 00 00    	mov    eax,DWORD PTR [eax+0x68a0]
  6d6554:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  6d655a:	89 44 24 38          	mov    DWORD PTR [esp+0x38],eax
  6d655e:	8b 11                	mov    edx,DWORD PTR [ecx]
  6d6560:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  6d6563:	6a 38                	push   0x38
  6d6565:	8b c6                	mov    eax,esi
  6d6567:	50                   	push   eax
  6d6568:	6a 01                	push   0x1
  6d656a:	ff d2                	call   edx
  6d656c:	8b 4c 24 3c          	mov    ecx,DWORD PTR [esp+0x3c]
  6d6570:	5e                   	pop    esi
  6d6571:	33 cc                	xor    ecx,esp
  6d6573:	b8 01 00 00 00       	mov    eax,0x1
  6d6578:	e8 84 aa 1b 00       	call   0x891001
  6d657d:	8b e5                	mov    esp,ebp
  6d657f:	5d                   	pop    ebp
  6d6580:	c2 08 00             	ret    0x8
```

#### key1 caller + 104-byte local sender

Native source: Tartaros.bin SHA256 `9741d...`; VA `0x006D6590..0x006D66A5`, raw start `0x002D5990`. 以下為原始 `.text` 指令重反組譯，非伪碼。

```asm
  6d6590:	55                   	push   ebp
  6d6591:	8b ec                	mov    ebp,esp
  6d6593:	83 e4 f8             	and    esp,0xfffffff8
  6d6596:	83 ec 7c             	sub    esp,0x7c
  6d6599:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6d659e:	33 c4                	xor    eax,esp
  6d65a0:	89 44 24 78          	mov    DWORD PTR [esp+0x78],eax
  6d65a4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6d65a7:	8b 00                	mov    eax,DWORD PTR [eax]
  6d65a9:	56                   	push   esi
  6d65aa:	8b f1                	mov    esi,ecx
  6d65ac:	85 c0                	test   eax,eax
  6d65ae:	0f 84 85 00 00 00    	je     0x6d6639
  6d65b4:	83 c0 0c             	add    eax,0xc
  6d65b7:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  6d65bb:	72 02                	jb     0x6d65bf
  6d65bd:	8b 00                	mov    eax,DWORD PTR [eax]
  6d65bf:	6a 00                	push   0x0
  6d65c1:	50                   	push   eax
  6d65c2:	a1 18 13 fb 00       	mov    eax,ds:0xfb1318
  6d65c7:	50                   	push   eax
  6d65c8:	e8 43 f0 db ff       	call   0x495610
  6d65cd:	85 c0                	test   eax,eax
  6d65cf:	75 7c                	jne    0x6d664d
  6d65d1:	8b 15 18 13 fb 00    	mov    edx,DWORD PTR ds:0xfb1318
  6d65d7:	68 c4 0a c4 00       	push   0xc40ac4
  6d65dc:	83 c2 08             	add    edx,0x8
  6d65df:	e8 1c 87 00 00       	call   0x6ded00
  6d65e4:	83 c4 04             	add    esp,0x4
  6d65e7:	c7 44 24 0c 81 01 00 	mov    DWORD PTR [esp+0xc],0x181
  6d65ee:	00 
  6d65ef:	e8 bc ee ea ff       	call   0x5854b0
  6d65f4:	8b f0                	mov    esi,eax
  6d65f6:	8d 4c 24 0c          	lea    ecx,[esp+0xc]
  6d65fa:	51                   	push   ecx
  6d65fb:	8d 44 24 0c          	lea    eax,[esp+0xc]
  6d65ff:	8b ce                	mov    ecx,esi
  6d6601:	e8 ea da e9 ff       	call   0x5740f0
  6d6606:	8b 44 24 08          	mov    eax,DWORD PTR [esp+0x8]
  6d660a:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  6d660d:	74 0d                	je     0x6d661c
  6d660f:	83 c0 10             	add    eax,0x10
  6d6612:	83 78 14 08          	cmp    DWORD PTR [eax+0x14],0x8
  6d6616:	72 0a                	jb     0x6d6622
  6d6618:	8b 00                	mov    eax,DWORD PTR [eax]
  6d661a:	eb 06                	jmp    0x6d6622
  6d661c:	cc                   	int3
  6d661d:	b8 fc d1 be 00       	mov    eax,0xbed1fc
  6d6622:	6a 00                	push   0x0
  6d6624:	6a 00                	push   0x0
  6d6626:	68 fc d1 be 00       	push   0xbed1fc
  6d662b:	50                   	push   eax
  6d662c:	68 ca 00 00 00       	push   0xca
  6d6631:	e8 da e4 d2 ff       	call   0x404b10
  6d6636:	83 c4 14             	add    esp,0x14
  6d6639:	33 c0                	xor    eax,eax
  6d663b:	5e                   	pop    esi
  6d663c:	8b 4c 24 78          	mov    ecx,DWORD PTR [esp+0x78]
  6d6640:	33 cc                	xor    ecx,esp
  6d6642:	e8 ba a9 1b 00       	call   0x891001
  6d6647:	8b e5                	mov    esp,ebp
  6d6649:	5d                   	pop    ebp
  6d664a:	c2 04 00             	ret    0x4
  6d664d:	6a 66                	push   0x66
  6d664f:	8d 44 24 16          	lea    eax,[esp+0x16]
  6d6653:	ba e1 00 00 00       	mov    edx,0xe1
  6d6658:	6a 00                	push   0x0
  6d665a:	50                   	push   eax
  6d665b:	66 89 54 24 1c       	mov    WORD PTR [esp+0x1c],dx
  6d6660:	e8 fb 81 1c 00       	call   0x89e860
  6d6665:	83 c4 0c             	add    esp,0xc
  6d6668:	56                   	push   esi
  6d6669:	8d 4c 24 16          	lea    ecx,[esp+0x16]
  6d666d:	6a 33                	push   0x33
  6d666f:	51                   	push   ecx
  6d6670:	e8 d8 c7 1b 00       	call   0x892e4d
  6d6675:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  6d667b:	8b 11                	mov    edx,DWORD PTR [ecx]
  6d667d:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  6d6680:	83 c4 0c             	add    esp,0xc
  6d6683:	6a 68                	push   0x68
  6d6685:	8d 44 24 14          	lea    eax,[esp+0x14]
  6d6689:	50                   	push   eax
  6d668a:	6a 01                	push   0x1
  6d668c:	ff d2                	call   edx
  6d668e:	8b 4c 24 7c          	mov    ecx,DWORD PTR [esp+0x7c]
  6d6692:	5e                   	pop    esi
  6d6693:	33 cc                	xor    ecx,esp
  6d6695:	b8 01 00 00 00       	mov    eax,0x1
  6d669a:	e8 62 a9 1b 00       	call   0x891001
  6d669f:	8b e5                	mov    esp,ebp
  6d66a1:	5d                   	pop    ebp
  6d66a2:	c2 04 00             	ret    0x4
```

#### key1 caller + 718-byte local sender

Native source: Tartaros.bin SHA256 `9741d...`; VA `0x006D66B0..0x006D6907`, raw start `0x002D5AB0`. 以下為原始 `.text` 指令重反組譯，非伪碼。

```asm
  6d66b0:	55                   	push   ebp
  6d66b1:	8b ec                	mov    ebp,esp
  6d66b3:	6a ff                	push   0xffffffff
  6d66b5:	68 28 22 94 00       	push   0x942228
  6d66ba:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  6d66c0:	50                   	push   eax
  6d66c1:	81 ec 30 03 00 00    	sub    esp,0x330
  6d66c7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6d66cc:	33 c5                	xor    eax,ebp
  6d66ce:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  6d66d1:	53                   	push   ebx
  6d66d2:	56                   	push   esi
  6d66d3:	57                   	push   edi
  6d66d4:	50                   	push   eax
  6d66d5:	8d 45 f4             	lea    eax,[ebp-0xc]
  6d66d8:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  6d66de:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6d66e1:	8b 00                	mov    eax,DWORD PTR [eax]
  6d66e3:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  6d66e6:	33 db                	xor    ebx,ebx
  6d66e8:	8b f2                	mov    esi,edx
  6d66ea:	89 8d c8 fc ff ff    	mov    DWORD PTR [ebp-0x338],ecx
  6d66f0:	3b c3                	cmp    eax,ebx
  6d66f2:	0f 84 8b 00 00 00    	je     0x6d6783
  6d66f8:	83 c0 0c             	add    eax,0xc
  6d66fb:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  6d66ff:	72 02                	jb     0x6d6703
  6d6701:	8b 00                	mov    eax,DWORD PTR [eax]
  6d6703:	8b 15 18 13 fb 00    	mov    edx,DWORD PTR ds:0xfb1318
  6d6709:	53                   	push   ebx
  6d670a:	50                   	push   eax
  6d670b:	52                   	push   edx
  6d670c:	e8 ff ee db ff       	call   0x495610
  6d6711:	85 c0                	test   eax,eax
  6d6713:	75 75                	jne    0x6d678a
  6d6715:	8b 15 18 13 fb 00    	mov    edx,DWORD PTR ds:0xfb1318
  6d671b:	68 c4 0a c4 00       	push   0xc40ac4
  6d6720:	83 c2 08             	add    edx,0x8
  6d6723:	e8 d8 85 00 00       	call   0x6ded00
  6d6728:	83 c4 04             	add    esp,0x4
  6d672b:	c7 85 c4 fc ff ff 81 	mov    DWORD PTR [ebp-0x33c],0x181
  6d6732:	01 00 00 
  6d6735:	e8 76 ed ea ff       	call   0x5854b0
  6d673a:	8b f0                	mov    esi,eax
  6d673c:	8d 85 c4 fc ff ff    	lea    eax,[ebp-0x33c]
  6d6742:	50                   	push   eax
  6d6743:	8d 85 c8 fc ff ff    	lea    eax,[ebp-0x338]
  6d6749:	8b ce                	mov    ecx,esi
  6d674b:	e8 a0 d9 e9 ff       	call   0x5740f0
  6d6750:	8b 85 c8 fc ff ff    	mov    eax,DWORD PTR [ebp-0x338]
  6d6756:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  6d6759:	74 0d                	je     0x6d6768
  6d675b:	83 c0 10             	add    eax,0x10
  6d675e:	83 78 14 08          	cmp    DWORD PTR [eax+0x14],0x8
  6d6762:	72 0a                	jb     0x6d676e
  6d6764:	8b 00                	mov    eax,DWORD PTR [eax]
  6d6766:	eb 06                	jmp    0x6d676e
  6d6768:	cc                   	int3
  6d6769:	b8 fc d1 be 00       	mov    eax,0xbed1fc
  6d676e:	53                   	push   ebx
  6d676f:	53                   	push   ebx
  6d6770:	68 fc d1 be 00       	push   0xbed1fc
  6d6775:	50                   	push   eax
  6d6776:	68 ca 00 00 00       	push   0xca
  6d677b:	e8 90 e3 d2 ff       	call   0x404b10
  6d6780:	83 c4 14             	add    esp,0x14
  6d6783:	33 c0                	xor    eax,eax
  6d6785:	e9 5f 01 00 00       	jmp    0x6d68e9
  6d678a:	68 00 02 00 00       	push   0x200
  6d678f:	8d 95 ce fc ff ff    	lea    edx,[ebp-0x332]
  6d6795:	b9 e2 00 00 00       	mov    ecx,0xe2
  6d679a:	53                   	push   ebx
  6d679b:	52                   	push   edx
  6d679c:	66 89 8d cc fc ff ff 	mov    WORD PTR [ebp-0x334],cx
  6d67a3:	e8 b8 80 1c 00       	call   0x89e860
  6d67a8:	6a 66                	push   0x66
  6d67aa:	8d 85 ce fe ff ff    	lea    eax,[ebp-0x132]
  6d67b0:	53                   	push   ebx
  6d67b1:	50                   	push   eax
  6d67b2:	e8 a9 80 1c 00       	call   0x89e860
  6d67b7:	6a 66                	push   0x66
  6d67b9:	8d 8d 34 ff ff ff    	lea    ecx,[ebp-0xcc]
  6d67bf:	53                   	push   ebx
  6d67c0:	51                   	push   ecx
  6d67c1:	e8 9a 80 1c 00       	call   0x89e860
  6d67c6:	56                   	push   esi
  6d67c7:	8d 95 ce fe ff ff    	lea    edx,[ebp-0x132]
  6d67cd:	6a 33                	push   0x33
  6d67cf:	52                   	push   edx
  6d67d0:	e8 78 c6 1b 00       	call   0x892e4d
  6d67d5:	57                   	push   edi
  6d67d6:	8d 7d 9c             	lea    edi,[ebp-0x64]
  6d67d9:	e8 62 8d da ff       	call   0x47f540
  6d67de:	83 c4 34             	add    esp,0x34
  6d67e1:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d67e4:	be 0f 00 00 00       	mov    esi,0xf
  6d67e9:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  6d67ec:	89 5d e4             	mov    DWORD PTR [ebp-0x1c],ebx
  6d67ef:	88 5d d4             	mov    BYTE PTR [ebp-0x2c],bl
  6d67f2:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  6d67f6:	83 7d b0 10          	cmp    DWORD PTR [ebp-0x50],0x10
  6d67fa:	8b 4d 9c             	mov    ecx,DWORD PTR [ebp-0x64]
  6d67fd:	73 02                	jae    0x6d6801
  6d67ff:	8b cf                	mov    ecx,edi
  6d6801:	8b 45 ac             	mov    eax,DWORD PTR [ebp-0x54]
  6d6804:	50                   	push   eax
  6d6805:	8d 7d d4             	lea    edi,[ebp-0x2c]
  6d6808:	e8 c3 d5 05 00       	call   0x733dd0
  6d680d:	83 ec 18             	sub    esp,0x18
  6d6810:	8b cc                	mov    ecx,esp
  6d6812:	89 a5 c4 fc ff ff    	mov    DWORD PTR [ebp-0x33c],esp
  6d6818:	6a ff                	push   0xffffffff
  6d681a:	53                   	push   ebx
  6d681b:	8b d7                	mov    edx,edi
  6d681d:	89 71 14             	mov    DWORD PTR [ecx+0x14],esi
  6d6820:	89 59 10             	mov    DWORD PTR [ecx+0x10],ebx
  6d6823:	52                   	push   edx
  6d6824:	88 19                	mov    BYTE PTR [ecx],bl
  6d6826:	e8 15 c8 d2 ff       	call   0x403040
  6d682b:	8d 4d b8             	lea    ecx,[ebp-0x48]
  6d682e:	e8 8d 7b d9 ff       	call   0x46e3c0
  6d6833:	83 c4 1c             	add    esp,0x1c
  6d6836:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  6d683a:	8b 45 b8             	mov    eax,DWORD PTR [ebp-0x48]
  6d683d:	be 08 00 00 00       	mov    esi,0x8
  6d6842:	39 75 cc             	cmp    DWORD PTR [ebp-0x34],esi
  6d6845:	73 03                	jae    0x6d684a
  6d6847:	8d 45 b8             	lea    eax,[ebp-0x48]
  6d684a:	50                   	push   eax
  6d684b:	8d 85 34 ff ff ff    	lea    eax,[ebp-0xcc]
  6d6851:	6a 33                	push   0x33
  6d6853:	50                   	push   eax
  6d6854:	e8 f4 c5 1b 00       	call   0x892e4d
  6d6859:	8b 8d c8 fc ff ff    	mov    ecx,DWORD PTR [ebp-0x338]
  6d685f:	51                   	push   ecx
  6d6860:	8d 95 ce fc ff ff    	lea    edx,[ebp-0x332]
  6d6866:	68 00 01 00 00       	push   0x100
  6d686b:	52                   	push   edx
  6d686c:	e8 dc c5 1b 00       	call   0x892e4d
  6d6871:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  6d6877:	8b 01                	mov    eax,DWORD PTR [ecx]
  6d6879:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  6d687c:	83 c4 18             	add    esp,0x18
  6d687f:	68 ce 02 00 00       	push   0x2ce
  6d6884:	8d 95 cc fc ff ff    	lea    edx,[ebp-0x334]
  6d688a:	52                   	push   edx
  6d688b:	6a 01                	push   0x1
  6d688d:	ff d0                	call   eax
  6d688f:	39 75 cc             	cmp    DWORD PTR [ebp-0x34],esi
  6d6892:	72 0c                	jb     0x6d68a0
  6d6894:	8b 4d b8             	mov    ecx,DWORD PTR [ebp-0x48]
  6d6897:	51                   	push   ecx
  6d6898:	e8 6f a9 1b 00       	call   0x89120c
  6d689d:	83 c4 04             	add    esp,0x4
  6d68a0:	33 d2                	xor    edx,edx
  6d68a2:	be 10 00 00 00       	mov    esi,0x10
  6d68a7:	c7 45 cc 07 00 00 00 	mov    DWORD PTR [ebp-0x34],0x7
  6d68ae:	89 5d c8             	mov    DWORD PTR [ebp-0x38],ebx
  6d68b1:	66 89 55 b8          	mov    WORD PTR [ebp-0x48],dx
  6d68b5:	39 75 e8             	cmp    DWORD PTR [ebp-0x18],esi
  6d68b8:	72 0c                	jb     0x6d68c6
  6d68ba:	8b 45 d4             	mov    eax,DWORD PTR [ebp-0x2c]
  6d68bd:	50                   	push   eax
  6d68be:	e8 49 a9 1b 00       	call   0x89120c
  6d68c3:	83 c4 04             	add    esp,0x4
  6d68c6:	c7 45 e8 0f 00 00 00 	mov    DWORD PTR [ebp-0x18],0xf
  6d68cd:	89 5d e4             	mov    DWORD PTR [ebp-0x1c],ebx
  6d68d0:	88 5d d4             	mov    BYTE PTR [ebp-0x2c],bl
  6d68d3:	39 75 b0             	cmp    DWORD PTR [ebp-0x50],esi
  6d68d6:	72 0c                	jb     0x6d68e4
  6d68d8:	8b 4d 9c             	mov    ecx,DWORD PTR [ebp-0x64]
  6d68db:	51                   	push   ecx
  6d68dc:	e8 2b a9 1b 00       	call   0x89120c
  6d68e1:	83 c4 04             	add    esp,0x4
  6d68e4:	b8 01 00 00 00       	mov    eax,0x1
  6d68e9:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d68ec:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d68f3:	59                   	pop    ecx
  6d68f4:	5f                   	pop    edi
  6d68f5:	5e                   	pop    esi
  6d68f6:	5b                   	pop    ebx
  6d68f7:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  6d68fa:	33 cd                	xor    ecx,ebp
  6d68fc:	e8 00 a7 1b 00       	call   0x891001
  6d6901:	8b e5                	mov    esp,ebp
  6d6903:	5d                   	pop    ebp
  6d6904:	c2 08 00             	ret    0x8
```

#### key1 other 718-byte local sender

Native source: Tartaros.bin SHA256 `9741d...`; VA `0x006D6910..0x006D6B67`, raw start `0x002D5D10`. 以下為原始 `.text` 指令重反組譯，非伪碼。

```asm
  6d6910:	55                   	push   ebp
  6d6911:	8b ec                	mov    ebp,esp
  6d6913:	6a ff                	push   0xffffffff
  6d6915:	68 28 22 94 00       	push   0x942228
  6d691a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  6d6920:	50                   	push   eax
  6d6921:	81 ec 30 03 00 00    	sub    esp,0x330
  6d6927:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6d692c:	33 c5                	xor    eax,ebp
  6d692e:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  6d6931:	53                   	push   ebx
  6d6932:	56                   	push   esi
  6d6933:	57                   	push   edi
  6d6934:	50                   	push   eax
  6d6935:	8d 45 f4             	lea    eax,[ebp-0xc]
  6d6938:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  6d693e:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6d6941:	8b 00                	mov    eax,DWORD PTR [eax]
  6d6943:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  6d6946:	33 db                	xor    ebx,ebx
  6d6948:	8b f2                	mov    esi,edx
  6d694a:	89 8d c8 fc ff ff    	mov    DWORD PTR [ebp-0x338],ecx
  6d6950:	3b c3                	cmp    eax,ebx
  6d6952:	0f 84 8b 00 00 00    	je     0x6d69e3
  6d6958:	83 c0 0c             	add    eax,0xc
  6d695b:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  6d695f:	72 02                	jb     0x6d6963
  6d6961:	8b 00                	mov    eax,DWORD PTR [eax]
  6d6963:	8b 15 18 13 fb 00    	mov    edx,DWORD PTR ds:0xfb1318
  6d6969:	53                   	push   ebx
  6d696a:	50                   	push   eax
  6d696b:	52                   	push   edx
  6d696c:	e8 9f ec db ff       	call   0x495610
  6d6971:	85 c0                	test   eax,eax
  6d6973:	75 75                	jne    0x6d69ea
  6d6975:	8b 15 18 13 fb 00    	mov    edx,DWORD PTR ds:0xfb1318
  6d697b:	68 c4 0a c4 00       	push   0xc40ac4
  6d6980:	83 c2 08             	add    edx,0x8
  6d6983:	e8 78 83 00 00       	call   0x6ded00
  6d6988:	83 c4 04             	add    esp,0x4
  6d698b:	c7 85 c4 fc ff ff 81 	mov    DWORD PTR [ebp-0x33c],0x181
  6d6992:	01 00 00 
  6d6995:	e8 16 eb ea ff       	call   0x5854b0
  6d699a:	8b f0                	mov    esi,eax
  6d699c:	8d 85 c4 fc ff ff    	lea    eax,[ebp-0x33c]
  6d69a2:	50                   	push   eax
  6d69a3:	8d 85 c8 fc ff ff    	lea    eax,[ebp-0x338]
  6d69a9:	8b ce                	mov    ecx,esi
  6d69ab:	e8 40 d7 e9 ff       	call   0x5740f0
  6d69b0:	8b 85 c8 fc ff ff    	mov    eax,DWORD PTR [ebp-0x338]
  6d69b6:	3b 46 04             	cmp    eax,DWORD PTR [esi+0x4]
  6d69b9:	74 0d                	je     0x6d69c8
  6d69bb:	83 c0 10             	add    eax,0x10
  6d69be:	83 78 14 08          	cmp    DWORD PTR [eax+0x14],0x8
  6d69c2:	72 0a                	jb     0x6d69ce
  6d69c4:	8b 00                	mov    eax,DWORD PTR [eax]
  6d69c6:	eb 06                	jmp    0x6d69ce
  6d69c8:	cc                   	int3
  6d69c9:	b8 fc d1 be 00       	mov    eax,0xbed1fc
  6d69ce:	53                   	push   ebx
  6d69cf:	53                   	push   ebx
  6d69d0:	68 fc d1 be 00       	push   0xbed1fc
  6d69d5:	50                   	push   eax
  6d69d6:	68 ca 00 00 00       	push   0xca
  6d69db:	e8 30 e1 d2 ff       	call   0x404b10
  6d69e0:	83 c4 14             	add    esp,0x14
  6d69e3:	33 c0                	xor    eax,eax
  6d69e5:	e9 5f 01 00 00       	jmp    0x6d6b49
  6d69ea:	68 00 02 00 00       	push   0x200
  6d69ef:	8d 95 ce fc ff ff    	lea    edx,[ebp-0x332]
  6d69f5:	b9 e3 00 00 00       	mov    ecx,0xe3
  6d69fa:	53                   	push   ebx
  6d69fb:	52                   	push   edx
  6d69fc:	66 89 8d cc fc ff ff 	mov    WORD PTR [ebp-0x334],cx
  6d6a03:	e8 58 7e 1c 00       	call   0x89e860
  6d6a08:	6a 66                	push   0x66
  6d6a0a:	8d 85 ce fe ff ff    	lea    eax,[ebp-0x132]
  6d6a10:	53                   	push   ebx
  6d6a11:	50                   	push   eax
  6d6a12:	e8 49 7e 1c 00       	call   0x89e860
  6d6a17:	6a 66                	push   0x66
  6d6a19:	8d 8d 34 ff ff ff    	lea    ecx,[ebp-0xcc]
  6d6a1f:	53                   	push   ebx
  6d6a20:	51                   	push   ecx
  6d6a21:	e8 3a 7e 1c 00       	call   0x89e860
  6d6a26:	56                   	push   esi
  6d6a27:	8d 95 ce fe ff ff    	lea    edx,[ebp-0x132]
  6d6a2d:	6a 33                	push   0x33
  6d6a2f:	52                   	push   edx
  6d6a30:	e8 18 c4 1b 00       	call   0x892e4d
  6d6a35:	57                   	push   edi
  6d6a36:	8d 7d 9c             	lea    edi,[ebp-0x64]
  6d6a39:	e8 02 8b da ff       	call   0x47f540
  6d6a3e:	83 c4 34             	add    esp,0x34
  6d6a41:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d6a44:	be 0f 00 00 00       	mov    esi,0xf
  6d6a49:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  6d6a4c:	89 5d e4             	mov    DWORD PTR [ebp-0x1c],ebx
  6d6a4f:	88 5d d4             	mov    BYTE PTR [ebp-0x2c],bl
  6d6a52:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  6d6a56:	83 7d b0 10          	cmp    DWORD PTR [ebp-0x50],0x10
  6d6a5a:	8b 4d 9c             	mov    ecx,DWORD PTR [ebp-0x64]
  6d6a5d:	73 02                	jae    0x6d6a61
  6d6a5f:	8b cf                	mov    ecx,edi
  6d6a61:	8b 45 ac             	mov    eax,DWORD PTR [ebp-0x54]
  6d6a64:	50                   	push   eax
  6d6a65:	8d 7d d4             	lea    edi,[ebp-0x2c]
  6d6a68:	e8 63 d3 05 00       	call   0x733dd0
  6d6a6d:	83 ec 18             	sub    esp,0x18
  6d6a70:	8b cc                	mov    ecx,esp
  6d6a72:	89 a5 c4 fc ff ff    	mov    DWORD PTR [ebp-0x33c],esp
  6d6a78:	6a ff                	push   0xffffffff
  6d6a7a:	53                   	push   ebx
  6d6a7b:	8b d7                	mov    edx,edi
  6d6a7d:	89 71 14             	mov    DWORD PTR [ecx+0x14],esi
  6d6a80:	89 59 10             	mov    DWORD PTR [ecx+0x10],ebx
  6d6a83:	52                   	push   edx
  6d6a84:	88 19                	mov    BYTE PTR [ecx],bl
  6d6a86:	e8 b5 c5 d2 ff       	call   0x403040
  6d6a8b:	8d 4d b8             	lea    ecx,[ebp-0x48]
  6d6a8e:	e8 2d 79 d9 ff       	call   0x46e3c0
  6d6a93:	83 c4 1c             	add    esp,0x1c
  6d6a96:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  6d6a9a:	8b 45 b8             	mov    eax,DWORD PTR [ebp-0x48]
  6d6a9d:	be 08 00 00 00       	mov    esi,0x8
  6d6aa2:	39 75 cc             	cmp    DWORD PTR [ebp-0x34],esi
  6d6aa5:	73 03                	jae    0x6d6aaa
  6d6aa7:	8d 45 b8             	lea    eax,[ebp-0x48]
  6d6aaa:	50                   	push   eax
  6d6aab:	8d 85 34 ff ff ff    	lea    eax,[ebp-0xcc]
  6d6ab1:	6a 33                	push   0x33
  6d6ab3:	50                   	push   eax
  6d6ab4:	e8 94 c3 1b 00       	call   0x892e4d
  6d6ab9:	8b 8d c8 fc ff ff    	mov    ecx,DWORD PTR [ebp-0x338]
  6d6abf:	51                   	push   ecx
  6d6ac0:	8d 95 ce fc ff ff    	lea    edx,[ebp-0x332]
  6d6ac6:	68 00 01 00 00       	push   0x100
  6d6acb:	52                   	push   edx
  6d6acc:	e8 7c c3 1b 00       	call   0x892e4d
  6d6ad1:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  6d6ad7:	8b 01                	mov    eax,DWORD PTR [ecx]
  6d6ad9:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  6d6adc:	83 c4 18             	add    esp,0x18
  6d6adf:	68 ce 02 00 00       	push   0x2ce
  6d6ae4:	8d 95 cc fc ff ff    	lea    edx,[ebp-0x334]
  6d6aea:	52                   	push   edx
  6d6aeb:	6a 01                	push   0x1
  6d6aed:	ff d0                	call   eax
  6d6aef:	39 75 cc             	cmp    DWORD PTR [ebp-0x34],esi
  6d6af2:	72 0c                	jb     0x6d6b00
  6d6af4:	8b 4d b8             	mov    ecx,DWORD PTR [ebp-0x48]
  6d6af7:	51                   	push   ecx
  6d6af8:	e8 0f a7 1b 00       	call   0x89120c
  6d6afd:	83 c4 04             	add    esp,0x4
  6d6b00:	33 d2                	xor    edx,edx
  6d6b02:	be 10 00 00 00       	mov    esi,0x10
  6d6b07:	c7 45 cc 07 00 00 00 	mov    DWORD PTR [ebp-0x34],0x7
  6d6b0e:	89 5d c8             	mov    DWORD PTR [ebp-0x38],ebx
  6d6b11:	66 89 55 b8          	mov    WORD PTR [ebp-0x48],dx
  6d6b15:	39 75 e8             	cmp    DWORD PTR [ebp-0x18],esi
  6d6b18:	72 0c                	jb     0x6d6b26
  6d6b1a:	8b 45 d4             	mov    eax,DWORD PTR [ebp-0x2c]
  6d6b1d:	50                   	push   eax
  6d6b1e:	e8 e9 a6 1b 00       	call   0x89120c
  6d6b23:	83 c4 04             	add    esp,0x4
  6d6b26:	c7 45 e8 0f 00 00 00 	mov    DWORD PTR [ebp-0x18],0xf
  6d6b2d:	89 5d e4             	mov    DWORD PTR [ebp-0x1c],ebx
  6d6b30:	88 5d d4             	mov    BYTE PTR [ebp-0x2c],bl
  6d6b33:	39 75 b0             	cmp    DWORD PTR [ebp-0x50],esi
  6d6b36:	72 0c                	jb     0x6d6b44
  6d6b38:	8b 4d 9c             	mov    ecx,DWORD PTR [ebp-0x64]
  6d6b3b:	51                   	push   ecx
  6d6b3c:	e8 cb a6 1b 00       	call   0x89120c
  6d6b41:	83 c4 04             	add    esp,0x4
  6d6b44:	b8 01 00 00 00       	mov    eax,0x1
  6d6b49:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d6b4c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d6b53:	59                   	pop    ecx
  6d6b54:	5f                   	pop    edi
  6d6b55:	5e                   	pop    esi
  6d6b56:	5b                   	pop    ebx
  6d6b57:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  6d6b5a:	33 cd                	xor    ecx,ebp
  6d6b5c:	e8 a0 a4 1b 00       	call   0x891001
  6d6b61:	8b e5                	mov    esp,ebp
  6d6b63:	5d                   	pop    ebp
  6d6b64:	c2 08 00             	ret    0x8
```

#### Client virtual tick + BF58 compare + Pool+48 transfer

Native source: Tartaros.bin SHA256 `9741d...`; VA `0x00490FE0..0x00491240`, raw start `0x000903E0`. 以下為原始 `.text` 指令重反組譯，非伪碼。

```asm
  490fe0:	55                   	push   ebp
  490fe1:	8b ec                	mov    ebp,esp
  490fe3:	83 e4 f8             	and    esp,0xfffffff8
  490fe6:	6a ff                	push   0xffffffff
  490fe8:	68 d0 98 94 00       	push   0x9498d0
  490fed:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  490ff3:	50                   	push   eax
  490ff4:	81 ec 40 03 00 00    	sub    esp,0x340
  490ffa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  490fff:	33 c4                	xor    eax,esp
  491001:	89 84 24 38 03 00 00 	mov    DWORD PTR [esp+0x338],eax
  491008:	53                   	push   ebx
  491009:	56                   	push   esi
  49100a:	57                   	push   edi
  49100b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  491010:	33 c4                	xor    eax,esp
  491012:	50                   	push   eax
  491013:	8d 84 24 50 03 00 00 	lea    eax,[esp+0x350]
  49101a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  491020:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  491023:	33 f6                	xor    esi,esi
  491025:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  491029:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  49102f:	75 14                	jne    0x491045
  491031:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  491037:	74 07                	je     0x491040
  491039:	e8 22 9f 00 00       	call   0x49af60
  49103e:	eb 05                	jmp    0x491045
  491040:	e8 bb 9f 00 00       	call   0x49b000
  491045:	8b 0d 58 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba858
  49104b:	8b 41 34             	mov    eax,DWORD PTR [ecx+0x34]
  49104e:	50                   	push   eax
  49104f:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  491055:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  49105b:	75 14                	jne    0x491071
  49105d:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  491063:	74 07                	je     0x49106c
  491065:	e8 f6 9e 00 00       	call   0x49af60
  49106a:	eb 05                	jmp    0x491071
  49106c:	e8 8f 9f 00 00       	call   0x49b000
  491071:	8b 15 58 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba858
  491077:	8b 4a 28             	mov    ecx,DWORD PTR [edx+0x28]
  49107a:	8b 01                	mov    eax,DWORD PTR [ecx]
  49107c:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  491080:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  491084:	3b c1                	cmp    eax,ecx
  491086:	0f 84 4a 01 00 00    	je     0x4911d6
  49108c:	8b 58 08             	mov    ebx,DWORD PTR [eax+0x8]
  49108f:	39 b3 ac a0 00 00    	cmp    DWORD PTR [ebx+0xa0ac],esi
  491095:	75 0b                	jne    0x4910a2
  491097:	8b 00                	mov    eax,DWORD PTR [eax]
  491099:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  49109d:	e9 2c 01 00 00       	jmp    0x4911ce
  4910a2:	a1 04 f7 fd 00       	mov    eax,ds:0xfdf704
  4910a7:	bf 01 00 00 00       	mov    edi,0x1
  4910ac:	03 c7                	add    eax,edi
  4910ae:	50                   	push   eax
  4910af:	68 68 58 c0 00       	push   0xc05868
  4910b4:	a3 04 f7 fd 00       	mov    ds:0xfdf704,eax
  4910b9:	e8 a6 20 40 00       	call   0x893164
  4910be:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  4910c2:	83 c4 08             	add    esp,0x8
  4910c5:	39 98 58 bf 00 00    	cmp    DWORD PTR [eax+0xbf58],ebx
  4910cb:	75 50                	jne    0x49111d
  4910cd:	f6 05 d0 ac fb 00 01 	test   BYTE PTR ds:0xfbacd0,0x1
  4910d4:	75 35                	jne    0x49110b
  4910d6:	09 3d d0 ac fb 00    	or     DWORD PTR ds:0xfbacd0,edi
  4910dc:	89 b4 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],esi
  4910e3:	89 35 d4 ac fb 00    	mov    DWORD PTR ds:0xfbacd4,esi
  4910e9:	e8 12 52 24 00       	call   0x6d6300
  4910ee:	68 70 d6 bc 00       	push   0xbcd670
  4910f3:	a3 d4 ac fb 00       	mov    ds:0xfbacd4,eax
  4910f8:	e8 1d 12 40 00       	call   0x89231a
  4910fd:	83 c4 04             	add    esp,0x4
  491100:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  491107:	ff ff ff ff 
  49110b:	8b 0d d4 ac fb 00    	mov    ecx,DWORD PTR ds:0xfbacd4
  491111:	3b ce                	cmp    ecx,esi
  491113:	74 08                	je     0x49111d
  491115:	8b 11                	mov    edx,DWORD PTR [ecx]
  491117:	8b 42 10             	mov    eax,DWORD PTR [edx+0x10]
  49111a:	57                   	push   edi
  49111b:	ff d0                	call   eax
  49111d:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  491122:	3b c6                	cmp    eax,esi
  491124:	75 56                	jne    0x49117c
  491126:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  49112c:	74 0c                	je     0x49113a
  49112e:	e8 2d 9e 00 00       	call   0x49af60
  491133:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  491138:	eb 42                	jmp    0x49117c
  49113a:	f6 05 00 12 fc 00 01 	test   BYTE PTR ds:0xfc1200,0x1
  491141:	75 2f                	jne    0x491172
  491143:	09 3d 00 12 fc 00    	or     DWORD PTR ds:0xfc1200,edi
  491149:	68 08 12 fc 00       	push   0xfc1208
  49114e:	89 bc 24 5c 03 00 00 	mov    DWORD PTR [esp+0x35c],edi
  491155:	e8 06 43 37 00       	call   0x805460
  49115a:	68 70 e6 bc 00       	push   0xbce670
  49115f:	e8 b6 11 40 00       	call   0x89231a
  491164:	83 c4 04             	add    esp,0x4
  491167:	c7 84 24 58 03 00 00 	mov    DWORD PTR [esp+0x358],0xffffffff
  49116e:	ff ff ff ff 
  491172:	b8 08 12 fc 00       	mov    eax,0xfc1208
  491177:	a3 58 a8 fb 00       	mov    ds:0xfba858,eax
  49117c:	ff 48 44             	dec    DWORD PTR [eax+0x44]
  49117f:	8b 78 48             	mov    edi,DWORD PTR [eax+0x48]
  491182:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  491185:	8d 70 48             	lea    esi,[eax+0x48]
  491188:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  49118c:	51                   	push   ecx
  49118d:	52                   	push   edx
  49118e:	57                   	push   edi
  49118f:	89 5c 24 24          	mov    DWORD PTR [esp+0x24],ebx
  491193:	e8 68 c5 2b 00       	call   0x74d700
  491198:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  49119b:	ba fe ff ff 3f       	mov    edx,0x3ffffffe
  4911a0:	2b d1                	sub    edx,ecx
  4911a2:	83 fa 01             	cmp    edx,0x1
  4911a5:	72 46                	jb     0x4911ed
  4911a7:	41                   	inc    ecx
  4911a8:	89 4e 04             	mov    DWORD PTR [esi+0x4],ecx
  4911ab:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  4911ae:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  4911b1:	89 01                	mov    DWORD PTR [ecx],eax
  4911b3:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4911b7:	c7 43 14 00 00 00 00 	mov    DWORD PTR [ebx+0x14],0x0
  4911be:	8b 08                	mov    ecx,DWORD PTR [eax]
  4911c0:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  4911c4:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  4911c8:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4911cc:	33 f6                	xor    esi,esi
  4911ce:	3b c1                	cmp    eax,ecx
  4911d0:	0f 85 b6 fe ff ff    	jne    0x49108c
  4911d6:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  4911dc:	75 1e                	jne    0x4911fc
  4911de:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  4911e4:	74 11                	je     0x4911f7
  4911e6:	e8 75 9d 00 00       	call   0x49af60
  4911eb:	eb 0f                	jmp    0x4911fc
  4911ed:	68 34 20 bf 00       	push   0xbf2034
  4911f2:	e8 39 c9 3e 00       	call   0x87db30
  4911f7:	e8 04 9e 00 00       	call   0x49b000
  4911fc:	8b 15 58 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba858
  491202:	52                   	push   edx
  491203:	e8 38 49 37 00       	call   0x805b40
  491208:	39 35 58 a8 fb 00    	cmp    DWORD PTR ds:0xfba858,esi
  49120e:	75 14                	jne    0x491224
  491210:	39 35 5c a8 fb 00    	cmp    DWORD PTR ds:0xfba85c,esi
  491216:	74 07                	je     0x49121f
  491218:	e8 43 9d 00 00       	call   0x49af60
  49121d:	eb 05                	jmp    0x491224
  49121f:	e8 dc 9d 00 00       	call   0x49b000
  491224:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  491229:	8b 40 34             	mov    eax,DWORD PTR [eax+0x34]
  49122c:	50                   	push   eax
  49122d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  491233:	bf 01 00 00 00       	mov    edi,0x1
  491238:	29 3d 78 dd f7 00    	sub    DWORD PTR ds:0xf7dd78,edi
  49123e:	75 19                	jne    0x491259
```

#### Manager Connect + same-key erase and replacement

Native source: Tartaros.bin SHA256 `9741d...`; VA `0x00806AD0..0x00806CED`, raw start `0x00405ED0`. 以下為原始 `.text` 指令重反組譯，非伪碼。

```asm
  806ad0:	55                   	push   ebp
  806ad1:	8b ec                	mov    ebp,esp
  806ad3:	83 e4 f8             	and    esp,0xfffffff8
  806ad6:	83 ec 24             	sub    esp,0x24
  806ad9:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  806ade:	33 c4                	xor    eax,esp
  806ae0:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  806ae4:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  806aeb:	53                   	push   ebx
  806aec:	56                   	push   esi
  806aed:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  806af0:	57                   	push   edi
  806af1:	8b f9                	mov    edi,ecx
  806af3:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  806af7:	75 15                	jne    0x806b0e
  806af9:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  806b00:	74 07                	je     0x806b09
  806b02:	e8 59 44 c9 ff       	call   0x49af60
  806b07:	eb 05                	jmp    0x806b0e
  806b09:	e8 f2 44 c9 ff       	call   0x49b000
  806b0e:	8b 0d 58 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba858
  806b14:	6a 01                	push   0x1
  806b16:	e8 35 ee ff ff       	call   0x805950
  806b1b:	8b d8                	mov    ebx,eax
  806b1d:	85 db                	test   ebx,ebx
  806b1f:	0f 84 b2 01 00 00    	je     0x806cd7
  806b25:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  806b28:	56                   	push   esi
  806b29:	c7 83 b4 a0 00 00 02 	mov    DWORD PTR [ebx+0xa0b4],0x2
  806b30:	00 00 00 
  806b33:	89 83 80 a0 00 00    	mov    DWORD PTR [ebx+0xa080],eax
  806b39:	ff 15 c0 25 bd 00    	call   DWORD PTR ds:0xbd25c0
  806b3f:	0f bf 48 0a          	movsx  ecx,WORD PTR [eax+0xa]
  806b43:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  806b46:	8b 02                	mov    eax,DWORD PTR [edx]
  806b48:	51                   	push   ecx
  806b49:	50                   	push   eax
  806b4a:	8d 4c 24 28          	lea    ecx,[esp+0x28]
  806b4e:	51                   	push   ecx
  806b4f:	e8 7c 70 09 00       	call   0x89dbd0
  806b54:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  806b57:	83 c4 0c             	add    esp,0xc
  806b5a:	ba 02 00 00 00       	mov    edx,0x2
  806b5f:	50                   	push   eax
  806b60:	66 89 54 24 20       	mov    WORD PTR [esp+0x20],dx
  806b65:	ff 15 a8 25 bd 00    	call   DWORD PTR ds:0xbd25a8
  806b6b:	6a 01                	push   0x1
  806b6d:	6a 00                	push   0x0
  806b6f:	6a 00                	push   0x0
  806b71:	6a 00                	push   0x0
  806b73:	6a 01                	push   0x1
  806b75:	6a 02                	push   0x2
  806b77:	66 89 44 24 36       	mov    WORD PTR [esp+0x36],ax
  806b7c:	ff 15 d0 25 bd 00    	call   DWORD PTR ds:0xbd25d0
  806b82:	6a 10                	push   0x10
  806b84:	8d 4c 24 20          	lea    ecx,[esp+0x20]
  806b88:	51                   	push   ecx
  806b89:	50                   	push   eax
  806b8a:	89 03                	mov    DWORD PTR [ebx],eax
  806b8c:	ff 15 c4 25 bd 00    	call   DWORD PTR ds:0xbd25c4
  806b92:	83 f8 ff             	cmp    eax,0xffffffff
  806b95:	75 7f                	jne    0x806c16
  806b97:	83 7f 58 00          	cmp    DWORD PTR [edi+0x58],0x0
  806b9b:	74 19                	je     0x806bb6
  806b9d:	ff 15 cc 25 bd 00    	call   DWORD PTR ds:0xbd25cc
  806ba3:	8b 7f 58             	mov    edi,DWORD PTR [edi+0x58]
  806ba6:	50                   	push   eax
  806ba7:	68 ac 16 c5 00       	push   0xc516ac
  806bac:	6a 02                	push   0x2
  806bae:	e8 4d 98 ee ff       	call   0x6f0400
  806bb3:	83 c4 0c             	add    esp,0xc
  806bb6:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  806bbd:	75 35                	jne    0x806bf4
  806bbf:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  806bc6:	74 27                	je     0x806bef
  806bc8:	e8 93 43 c9 ff       	call   0x49af60
  806bcd:	8b 35 58 a8 fb 00    	mov    esi,DWORD PTR ds:0xfba858
  806bd3:	53                   	push   ebx
  806bd4:	e8 17 ef ff ff       	call   0x805af0
  806bd9:	33 c0                	xor    eax,eax
  806bdb:	5f                   	pop    edi
  806bdc:	5e                   	pop    esi
  806bdd:	5b                   	pop    ebx
  806bde:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  806be2:	33 cc                	xor    ecx,esp
  806be4:	e8 18 a4 08 00       	call   0x891001
  806be9:	8b e5                	mov    esp,ebp
  806beb:	5d                   	pop    ebp
  806bec:	c2 10 00             	ret    0x10
  806bef:	e8 0c 44 c9 ff       	call   0x49b000
  806bf4:	8b 35 58 a8 fb 00    	mov    esi,DWORD PTR ds:0xfba858
  806bfa:	53                   	push   ebx
  806bfb:	e8 f0 ee ff ff       	call   0x805af0
  806c00:	33 c0                	xor    eax,eax
  806c02:	5f                   	pop    edi
  806c03:	5e                   	pop    esi
  806c04:	5b                   	pop    ebx
  806c05:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  806c09:	33 cc                	xor    ecx,esp
  806c0b:	e8 f1 a3 08 00       	call   0x891001
  806c10:	8b e5                	mov    esp,ebp
  806c12:	5d                   	pop    ebp
  806c13:	c2 10 00             	ret    0x10
  806c16:	8b 33                	mov    esi,DWORD PTR [ebx]
  806c18:	8b 3d ac 25 bd 00    	mov    edi,DWORD PTR ds:0xbd25ac
  806c1e:	6a 04                	push   0x4
  806c20:	8d 54 24 14          	lea    edx,[esp+0x14]
  806c24:	52                   	push   edx
  806c25:	6a 01                	push   0x1
  806c27:	6a 06                	push   0x6
  806c29:	56                   	push   esi
  806c2a:	c7 44 24 24 00 00 00 	mov    DWORD PTR [esp+0x24],0x0
  806c31:	00 
  806c32:	ff d7                	call   edi
  806c34:	83 f8 ff             	cmp    eax,0xffffffff
  806c37:	74 c7                	je     0x806c00
  806c39:	6a 04                	push   0x4
  806c3b:	8d 44 24 14          	lea    eax,[esp+0x14]
  806c3f:	50                   	push   eax
  806c40:	68 02 10 00 00       	push   0x1002
  806c45:	68 ff ff 00 00       	push   0xffff
  806c4a:	56                   	push   esi
  806c4b:	c7 44 24 24 00 40 00 	mov    DWORD PTR [esp+0x24],0x4000
  806c52:	00 
  806c53:	ff d7                	call   edi
  806c55:	83 f8 ff             	cmp    eax,0xffffffff
  806c58:	74 a6                	je     0x806c00
  806c5a:	6a 04                	push   0x4
  806c5c:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  806c60:	51                   	push   ecx
  806c61:	68 01 10 00 00       	push   0x1001
  806c66:	68 ff ff 00 00       	push   0xffff
  806c6b:	56                   	push   esi
  806c6c:	c7 44 24 24 00 80 00 	mov    DWORD PTR [esp+0x24],0x8000
  806c73:	00 
  806c74:	ff d7                	call   edi
  806c76:	83 f8 ff             	cmp    eax,0xffffffff
  806c79:	74 85                	je     0x806c00
  806c7b:	e8 a0 f9 ff ff       	call   0x806620
  806c80:	8b 10                	mov    edx,DWORD PTR [eax]
  806c82:	6a 00                	push   0x0
  806c84:	53                   	push   ebx
  806c85:	52                   	push   edx
  806c86:	56                   	push   esi
  806c87:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
  806c8d:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  806c91:	8d 45 10             	lea    eax,[ebp+0x10]
  806c94:	8d 77 18             	lea    esi,[edi+0x18]
  806c97:	50                   	push   eax
  806c98:	8d 44 24 18          	lea    eax,[esp+0x18]
  806c9c:	8b ce                	mov    ecx,esi
  806c9e:	e8 1d cc 03 00       	call   0x8438c0
  806ca3:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  806ca7:	3b 47 1c             	cmp    eax,DWORD PTR [edi+0x1c]
  806caa:	74 0c                	je     0x806cb8
  806cac:	50                   	push   eax
  806cad:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  806cb1:	51                   	push   ecx
  806cb2:	56                   	push   esi
  806cb3:	e8 d8 fb fa ff       	call   0x7b6890
  806cb8:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  806cbb:	8d 7c 24 14          	lea    edi,[esp+0x14]
  806cbf:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  806cc3:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  806cc7:	e8 54 82 d7 ff       	call   0x57ef20
  806ccc:	50                   	push   eax
  806ccd:	56                   	push   esi
  806cce:	8d 74 24 1c          	lea    esi,[esp+0x1c]
  806cd2:	e8 79 7b d7 ff       	call   0x57e850
  806cd7:	8b 4c 24 2c          	mov    ecx,DWORD PTR [esp+0x2c]
  806cdb:	5f                   	pop    edi
  806cdc:	5e                   	pop    esi
  806cdd:	8b c3                	mov    eax,ebx
  806cdf:	5b                   	pop    ebx
  806ce0:	33 cc                	xor    ecx,esp
  806ce2:	e8 1a a3 08 00       	call   0x891001
  806ce7:	8b e5                	mov    esp,ebp
  806ce9:	5d                   	pop    ebp
  806cea:	c2 10 00             	ret    0x10
```

#### Manager close/shutdown and Pool tracking

Native source: Tartaros.bin SHA256 `9741d...`; VA `0x00806F60..0x00807091`, raw start `0x00406360`. 以下為原始 `.text` 指令重反組譯，非伪碼。

```asm
  806f60:	55                   	push   ebp
  806f61:	8b ec                	mov    ebp,esp
  806f63:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  806f66:	8b 08                	mov    ecx,DWORD PTR [eax]
  806f68:	6a 01                	push   0x1
  806f6a:	51                   	push   ecx
  806f6b:	ff 15 c8 25 bd 00    	call   DWORD PTR ds:0xbd25c8
  806f71:	5d                   	pop    ebp
  806f72:	c2 04 00             	ret    0x4
  806f75:	cc                   	int3
  806f76:	cc                   	int3
  806f77:	cc                   	int3
  806f78:	cc                   	int3
  806f79:	cc                   	int3
  806f7a:	cc                   	int3
  806f7b:	cc                   	int3
  806f7c:	cc                   	int3
  806f7d:	cc                   	int3
  806f7e:	cc                   	int3
  806f7f:	cc                   	int3
  806f80:	55                   	push   ebp
  806f81:	8b ec                	mov    ebp,esp
  806f83:	51                   	push   ecx
  806f84:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  806f87:	56                   	push   esi
  806f88:	8b f1                	mov    esi,ecx
  806f8a:	8d 4d 08             	lea    ecx,[ebp+0x8]
  806f8d:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  806f90:	51                   	push   ecx
  806f91:	8d 4e 18             	lea    ecx,[esi+0x18]
  806f94:	8d 45 fc             	lea    eax,[ebp-0x4]
  806f97:	e8 24 c9 03 00       	call   0x8438c0
  806f9c:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  806f9f:	3b 46 1c             	cmp    eax,DWORD PTR [esi+0x1c]
  806fa2:	5e                   	pop    esi
  806fa3:	74 12                	je     0x806fb7
  806fa5:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  806fa8:	85 c0                	test   eax,eax
  806faa:	74 0b                	je     0x806fb7
  806fac:	8b 10                	mov    edx,DWORD PTR [eax]
  806fae:	6a 01                	push   0x1
  806fb0:	52                   	push   edx
  806fb1:	ff 15 c8 25 bd 00    	call   DWORD PTR ds:0xbd25c8
  806fb7:	8b e5                	mov    esp,ebp
  806fb9:	5d                   	pop    ebp
  806fba:	c2 08 00             	ret    0x8
  806fbd:	cc                   	int3
  806fbe:	cc                   	int3
  806fbf:	cc                   	int3
  806fc0:	55                   	push   ebp
  806fc1:	8b ec                	mov    ebp,esp
  806fc3:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  806fca:	75 15                	jne    0x806fe1
  806fcc:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  806fd3:	74 07                	je     0x806fdc
  806fd5:	e8 86 3f c9 ff       	call   0x49af60
  806fda:	eb 05                	jmp    0x806fe1
  806fdc:	e8 1f 40 c9 ff       	call   0x49b000
  806fe1:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  806fe6:	8b 48 34             	mov    ecx,DWORD PTR [eax+0x34]
  806fe9:	56                   	push   esi
  806fea:	57                   	push   edi
  806feb:	51                   	push   ecx
  806fec:	ff 15 4c 22 bd 00    	call   DWORD PTR ds:0xbd224c
  806ff2:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  806ff5:	83 bf a8 a0 00 00 00 	cmp    DWORD PTR [edi+0xa0a8],0x0
  806ffc:	8b 37                	mov    esi,DWORD PTR [edi]
  806ffe:	75 4a                	jne    0x80704a
  807000:	85 f6                	test   esi,esi
  807002:	74 46                	je     0x80704a
  807004:	83 fe ff             	cmp    esi,0xffffffff
  807007:	74 41                	je     0x80704a
  807009:	80 7d 0c 00          	cmp    BYTE PTR [ebp+0xc],0x0
  80700d:	75 1e                	jne    0x80702d
  80700f:	6a 04                	push   0x4
  807011:	8d 4d 0c             	lea    ecx,[ebp+0xc]
  807014:	51                   	push   ecx
  807015:	68 80 00 00 00       	push   0x80
  80701a:	68 ff ff 00 00       	push   0xffff
  80701f:	56                   	push   esi
  807020:	c7 45 0c 01 00 00 00 	mov    DWORD PTR [ebp+0xc],0x1
  807027:	ff 15 ac 25 bd 00    	call   DWORD PTR ds:0xbd25ac
  80702d:	6a 02                	push   0x2
  80702f:	56                   	push   esi
  807030:	ff 15 c8 25 bd 00    	call   DWORD PTR ds:0xbd25c8
  807036:	56                   	push   esi
  807037:	ff 15 d4 25 bd 00    	call   DWORD PTR ds:0xbd25d4
  80703d:	57                   	push   edi
  80703e:	e8 2d 40 c9 ff       	call   0x49b070
  807043:	8b f8                	mov    edi,eax
  807045:	e8 36 ea ff ff       	call   0x805a80
  80704a:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  807051:	5f                   	pop    edi
  807052:	5e                   	pop    esi
  807053:	75 27                	jne    0x80707c
  807055:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  80705c:	74 19                	je     0x807077
  80705e:	e8 fd 3e c9 ff       	call   0x49af60
  807063:	8b 15 58 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba858
  807069:	8b 42 34             	mov    eax,DWORD PTR [edx+0x34]
  80706c:	50                   	push   eax
  80706d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  807073:	5d                   	pop    ebp
  807074:	c2 08 00             	ret    0x8
  807077:	e8 84 3f c9 ff       	call   0x49b000
  80707c:	8b 15 58 a8 fb 00    	mov    edx,DWORD PTR ds:0xfba858
  807082:	8b 42 34             	mov    eax,DWORD PTR [edx+0x34]
  807085:	50                   	push   eax
  807086:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  80708c:	5d                   	pop    ebp
  80708d:	c2 08 00             	ret    0x8
  807090:	55                   	push   ebp
```

#### Conn reset and resource drain

Native source: Tartaros.bin SHA256 `9741d...`; VA `0x00805F50..0x00806050`, raw start `0x00405350`. 以下為原始 `.text` 指令重反組譯，非伪碼。

```asm
  805f50:	c7 06 ff ff ff ff    	mov    DWORD PTR [esi],0xffffffff
  805f56:	33 c0                	xor    eax,eax
  805f58:	53                   	push   ebx
  805f59:	33 db                	xor    ebx,ebx
  805f5b:	89 9e ac a0 00 00    	mov    DWORD PTR [esi+0xa0ac],ebx
  805f61:	89 46 04             	mov    DWORD PTR [esi+0x4],eax
  805f64:	89 46 08             	mov    DWORD PTR [esi+0x8],eax
  805f67:	89 46 0c             	mov    DWORD PTR [esi+0xc],eax
  805f6a:	89 46 10             	mov    DWORD PTR [esi+0x10],eax
  805f6d:	89 5e 14             	mov    DWORD PTR [esi+0x14],ebx
  805f70:	8d 46 18             	lea    eax,[esi+0x18]
  805f73:	89 80 00 50 00 00    	mov    DWORD PTR [eax+0x5000],eax
  805f79:	88 9e 24 a0 00 00    	mov    BYTE PTR [esi+0xa024],bl
  805f7f:	89 9e 28 a0 00 00    	mov    DWORD PTR [esi+0xa028],ebx
  805f85:	8d 86 20 50 00 00    	lea    eax,[esi+0x5020]
  805f8b:	89 86 20 a0 00 00    	mov    DWORD PTR [esi+0xa020],eax
  805f91:	33 c0                	xor    eax,eax
  805f93:	89 86 84 a0 00 00    	mov    DWORD PTR [esi+0xa084],eax
  805f99:	89 86 88 a0 00 00    	mov    DWORD PTR [esi+0xa088],eax
  805f9f:	89 86 8c a0 00 00    	mov    DWORD PTR [esi+0xa08c],eax
  805fa5:	89 86 90 a0 00 00    	mov    DWORD PTR [esi+0xa090],eax
  805fab:	89 86 94 a0 00 00    	mov    DWORD PTR [esi+0xa094],eax
  805fb1:	89 86 98 a0 00 00    	mov    DWORD PTR [esi+0xa098],eax
  805fb7:	89 86 9c a0 00 00    	mov    DWORD PTR [esi+0xa09c],eax
  805fbd:	89 86 a0 a0 00 00    	mov    DWORD PTR [esi+0xa0a0],eax
  805fc3:	89 9e a4 a0 00 00    	mov    DWORD PTR [esi+0xa0a4],ebx
  805fc9:	56                   	push   esi
  805fca:	89 9e a8 a0 00 00    	mov    DWORD PTR [esi+0xa0a8],ebx
  805fd0:	c7 86 80 a0 00 00 02 	mov    DWORD PTR [esi+0xa080],0x2
  805fd7:	00 00 00 
  805fda:	e8 01 04 00 00       	call   0x8063e0
  805fdf:	89 9e c0 a0 00 00    	mov    DWORD PTR [esi+0xa0c0],ebx
  805fe5:	89 9e c4 a0 00 00    	mov    DWORD PTR [esi+0xa0c4],ebx
  805feb:	89 9e c8 a0 00 00    	mov    DWORD PTR [esi+0xa0c8],ebx
  805ff1:	89 9e cc a0 00 00    	mov    DWORD PTR [esi+0xa0cc],ebx
  805ff7:	89 9e d0 a0 00 00    	mov    DWORD PTR [esi+0xa0d0],ebx
  805ffd:	89 9e b0 a0 00 00    	mov    DWORD PTR [esi+0xa0b0],ebx
  806003:	c7 86 b4 a0 00 00 01 	mov    DWORD PTR [esi+0xa0b4],0x1
  80600a:	00 00 00 
  80600d:	5b                   	pop    ebx
  80600e:	c3                   	ret
  80600f:	cc                   	int3
  806010:	56                   	push   esi
  806011:	c7 06 ff ff ff ff    	mov    DWORD PTR [esi],0xffffffff
  806017:	c7 86 a8 a0 00 00 01 	mov    DWORD PTR [esi+0xa0a8],0x1
  80601e:	00 00 00 
  806021:	e8 ba 03 00 00       	call   0x8063e0
  806026:	33 c0                	xor    eax,eax
  806028:	89 86 c0 a0 00 00    	mov    DWORD PTR [esi+0xa0c0],eax
  80602e:	89 86 c4 a0 00 00    	mov    DWORD PTR [esi+0xa0c4],eax
  806034:	89 86 c8 a0 00 00    	mov    DWORD PTR [esi+0xa0c8],eax
  80603a:	89 86 cc a0 00 00    	mov    DWORD PTR [esi+0xa0cc],eax
  806040:	89 86 d0 a0 00 00    	mov    DWORD PTR [esi+0xa0d0],eax
  806046:	c7 86 b4 a0 00 00 01 	mov    DWORD PTR [esi+0xa0b4],0x1
  80604d:	00 00 00 
```

#### IOCP recv/send completion and close caller

Native source: Tartaros.bin SHA256 `9741d...`; VA `0x00806CF0..0x00806F29`, raw start `0x004060F0`. 以下為原始 `.text` 指令重反組譯，非伪碼。

```asm
  806cf0:	55                   	push   ebp
  806cf1:	8b ec                	mov    ebp,esp
  806cf3:	83 ec 24             	sub    esp,0x24
  806cf6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  806cfb:	33 c5                	xor    eax,ebp
  806cfd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  806d00:	53                   	push   ebx
  806d01:	56                   	push   esi
  806d02:	33 f6                	xor    esi,esi
  806d04:	8b d9                	mov    ebx,ecx
  806d06:	57                   	push   edi
  806d07:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806d0a:	89 75 e4             	mov    DWORD PTR [ebp-0x1c],esi
  806d0d:	89 75 e0             	mov    DWORD PTR [ebp-0x20],esi
  806d10:	89 75 dc             	mov    DWORD PTR [ebp-0x24],esi
  806d13:	3b fe                	cmp    edi,esi
  806d15:	74 19                	je     0x806d30
  806d17:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  806d1a:	50                   	push   eax
  806d1b:	68 d0 16 c5 00       	push   0xc516d0
  806d20:	56                   	push   esi
  806d21:	e8 da 96 ee ff       	call   0x6f0400
  806d26:	83 c4 0c             	add    esp,0xc
  806d29:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  806d30:	f6 05 b4 33 fe 00 01 	test   BYTE PTR ds:0xfe33b4,0x1
  806d37:	75 36                	jne    0x806d6f
  806d39:	83 0d b4 33 fe 00 01 	or     DWORD PTR ds:0xfe33b4,0x1
  806d40:	56                   	push   esi
  806d41:	56                   	push   esi
  806d42:	56                   	push   esi
  806d43:	6a ff                	push   0xffffffff
  806d45:	89 35 b8 33 fe 00    	mov    DWORD PTR ds:0xfe33b8,esi
  806d4b:	89 35 bc 33 fe 00    	mov    DWORD PTR ds:0xfe33bc,esi
  806d51:	89 35 c0 33 fe 00    	mov    DWORD PTR ds:0xfe33c0,esi
  806d57:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
  806d5d:	68 b0 0b bd 00       	push   0xbd0bb0
  806d62:	a3 b8 33 fe 00       	mov    ds:0xfe33b8,eax
  806d67:	e8 ae b5 08 00       	call   0x89231a
  806d6c:	83 c4 04             	add    esp,0x4
  806d6f:	6a ff                	push   0xffffffff
  806d71:	8d 4d e0             	lea    ecx,[ebp-0x20]
  806d74:	51                   	push   ecx
  806d75:	8b 0d b8 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe33b8
  806d7b:	8d 55 e4             	lea    edx,[ebp-0x1c]
  806d7e:	52                   	push   edx
  806d7f:	8d 45 dc             	lea    eax,[ebp-0x24]
  806d82:	50                   	push   eax
  806d83:	51                   	push   ecx
  806d84:	ff 15 74 22 bd 00    	call   DWORD PTR ds:0xbd2274
  806d8a:	85 c0                	test   eax,eax
  806d8c:	0f 84 3d 01 00 00    	je     0x806ecf
  806d92:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806d95:	83 f8 01             	cmp    eax,0x1
  806d98:	0f 84 90 01 00 00    	je     0x806f2e
  806d9e:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  806da1:	3b d6                	cmp    edx,esi
  806da3:	75 1b                	jne    0x806dc0
  806da5:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806da8:	3b fe                	cmp    edi,esi
  806daa:	74 84                	je     0x806d30
  806dac:	68 04 17 c5 00       	push   0xc51704
  806db1:	6a 02                	push   0x2
  806db3:	e8 48 96 ee ff       	call   0x6f0400
  806db8:	83 c4 08             	add    esp,0x8
  806dbb:	e9 70 ff ff ff       	jmp    0x806d30
  806dc0:	8b 4d dc             	mov    ecx,DWORD PTR [ebp-0x24]
  806dc3:	3b ce                	cmp    ecx,esi
  806dc5:	75 1d                	jne    0x806de4
  806dc7:	8b 13                	mov    edx,DWORD PTR [ebx]
  806dc9:	56                   	push   esi
  806dca:	50                   	push   eax
  806dcb:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  806dce:	8b cb                	mov    ecx,ebx
  806dd0:	ff d0                	call   eax
  806dd2:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  806dd5:	c7 81 a8 a0 00 00 01 	mov    DWORD PTR [ecx+0xa0a8],0x1
  806ddc:	00 00 00 
  806ddf:	e9 4c ff ff ff       	jmp    0x806d30
  806de4:	8d b8 30 a0 00 00    	lea    edi,[eax+0xa030]
  806dea:	3b d7                	cmp    edx,edi
  806dec:	0f 85 8b 00 00 00    	jne    0x806e7d
  806df2:	01 4b 2c             	add    DWORD PTR [ebx+0x2c],ecx
  806df5:	ff 43 3c             	inc    DWORD PTR [ebx+0x3c]
  806df8:	39 b0 ac a0 00 00    	cmp    DWORD PTR [eax+0xa0ac],esi
  806dfe:	0f 84 2c ff ff ff    	je     0x806d30
  806e04:	8d 50 18             	lea    edx,[eax+0x18]
  806e07:	50                   	push   eax
  806e08:	e8 33 0d 00 00       	call   0x807b40
  806e0d:	85 c0                	test   eax,eax
  806e0f:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806e12:	74 0f                	je     0x806e23
  806e14:	8b 13                	mov    edx,DWORD PTR [ebx]
  806e16:	8b 52 14             	mov    edx,DWORD PTR [edx+0x14]
  806e19:	50                   	push   eax
  806e1a:	8b cb                	mov    ecx,ebx
  806e1c:	ff d2                	call   edx
  806e1e:	e9 0d ff ff ff       	jmp    0x806d30
  806e23:	39 b0 b0 a0 00 00    	cmp    DWORD PTR [eax+0xa0b0],esi
  806e29:	0f 85 01 ff ff ff    	jne    0x806d30
  806e2f:	39 73 58             	cmp    DWORD PTR [ebx+0x58],esi
  806e32:	74 3a                	je     0x806e6e
  806e34:	0f b6 48 0b          	movzx  ecx,BYTE PTR [eax+0xb]
  806e38:	0f b6 50 0a          	movzx  edx,BYTE PTR [eax+0xa]
  806e3c:	51                   	push   ecx
  806e3d:	0f b6 48 09          	movzx  ecx,BYTE PTR [eax+0x9]
  806e41:	52                   	push   edx
  806e42:	0f b6 50 08          	movzx  edx,BYTE PTR [eax+0x8]
  806e46:	51                   	push   ecx
  806e47:	52                   	push   edx
  806e48:	68 50 b0 bf 00       	push   0xbfb050
  806e4d:	8d 55 e8             	lea    edx,[ebp-0x18]
  806e50:	e8 db d4 cb ff       	call   0x4c4330
  806e55:	8b 7b 58             	mov    edi,DWORD PTR [ebx+0x58]
  806e58:	8d 45 e8             	lea    eax,[ebp-0x18]
  806e5b:	50                   	push   eax
  806e5c:	68 18 17 c5 00       	push   0xc51718
  806e61:	6a 02                	push   0x2
  806e63:	e8 98 95 ee ff       	call   0x6f0400
  806e68:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806e6b:	83 c4 20             	add    esp,0x20
  806e6e:	c7 80 b0 a0 00 00 01 	mov    DWORD PTR [eax+0xa0b0],0x1
  806e75:	00 00 00 
  806e78:	e9 b3 fe ff ff       	jmp    0x806d30
  806e7d:	8d b8 50 a0 00 00    	lea    edi,[eax+0xa050]
  806e83:	3b d7                	cmp    edx,edi
  806e85:	0f 85 a5 fe ff ff    	jne    0x806d30
  806e8b:	01 4b 28             	add    DWORD PTR [ebx+0x28],ecx
  806e8e:	ff 43 38             	inc    DWORD PTR [ebx+0x38]
  806e91:	39 b0 ac a0 00 00    	cmp    DWORD PTR [eax+0xa0ac],esi
  806e97:	74 12                	je     0x806eab
  806e99:	8d b0 1c 50 00 00    	lea    esi,[eax+0x501c]
  806e9f:	8b f9                	mov    edi,ecx
  806ea1:	e8 0a 09 00 00       	call   0x8077b0
  806ea6:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806ea9:	33 f6                	xor    esi,esi
  806eab:	39 b0 28 a0 00 00    	cmp    DWORD PTR [eax+0xa028],esi
  806eb1:	0f 97 c1             	seta   cl
  806eb4:	88 88 24 a0 00 00    	mov    BYTE PTR [eax+0xa024],cl
  806eba:	8b 55 e4             	mov    edx,DWORD PTR [ebp-0x1c]
  806ebd:	81 c2 b8 a0 00 00    	add    edx,0xa0b8
  806ec3:	52                   	push   edx
  806ec4:	ff 15 7c 22 bd 00    	call   DWORD PTR ds:0xbd227c
  806eca:	e9 61 fe ff ff       	jmp    0x806d30
  806ecf:	8b 4d e0             	mov    ecx,DWORD PTR [ebp-0x20]
  806ed2:	3b ce                	cmp    ecx,esi
  806ed4:	0f 84 56 fe ff ff    	je     0x806d30
  806eda:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806edd:	8d 90 30 a0 00 00    	lea    edx,[eax+0xa030]
  806ee3:	3b ca                	cmp    ecx,edx
  806ee5:	74 19                	je     0x806f00
  806ee7:	8d 90 50 a0 00 00    	lea    edx,[eax+0xa050]
  806eed:	3b ca                	cmp    ecx,edx
  806eef:	75 0f                	jne    0x806f00
  806ef1:	05 b8 a0 00 00       	add    eax,0xa0b8
  806ef6:	50                   	push   eax
  806ef7:	ff 15 7c 22 bd 00    	call   DWORD PTR ds:0xbd227c
  806efd:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f00:	8b 80 b8 a0 00 00    	mov    eax,DWORD PTR [eax+0xa0b8]
  806f06:	85 c0                	test   eax,eax
  806f08:	0f 85 22 fe ff ff    	jne    0x806d30
  806f0e:	8b 13                	mov    edx,DWORD PTR [ebx]
  806f10:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f13:	8b 52 24             	mov    edx,DWORD PTR [edx+0x24]
  806f16:	56                   	push   esi
  806f17:	50                   	push   eax
  806f18:	8b cb                	mov    ecx,ebx
  806f1a:	ff d2                	call   edx
  806f1c:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  806f1f:	c7 80 a8 a0 00 00 01 	mov    DWORD PTR [eax+0xa0a8],0x1
  806f26:	00 00 00 
```

#### erase-map-node routine footer / free

Native source: Tartaros.bin SHA256 `9741d...`; VA `0x007B6AB8..0x007B6AEE`, raw start `0x003B5EB8`. 以下為原始 `.text` 指令重反組譯，非伪碼。

```asm
  7b6ab8:	52                   	push   edx
  7b6ab9:	8b ce                	mov    ecx,esi
  7b6abb:	e8 b0 7b c8 ff       	call   0x43e670
  7b6ac0:	88 5f 14             	mov    BYTE PTR [edi+0x14],bl
  7b6ac3:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  7b6ac6:	52                   	push   edx
  7b6ac7:	e8 40 a7 0d 00       	call   0x89120c
  7b6acc:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  7b6acf:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6ad2:	83 c4 04             	add    esp,0x4
  7b6ad5:	5f                   	pop    edi
  7b6ad6:	5e                   	pop    esi
  7b6ad7:	5b                   	pop    ebx
  7b6ad8:	85 c0                	test   eax,eax
  7b6ada:	74 04                	je     0x7b6ae0
  7b6adc:	48                   	dec    eax
  7b6add:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  7b6ae0:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  7b6ae3:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  7b6ae6:	89 08                	mov    DWORD PTR [eax],ecx
  7b6ae8:	8b e5                	mov    esp,ebp
  7b6aea:	5d                   	pop    ebp
  7b6aeb:	c2 0c 00             	ret    0xc
```

#### key1 receive/first sender manager indirection

Native source: Tartaros.bin SHA256 `9741d...`; VA `0x006D6554..0x006D656D`, raw start `0x002D5954`. 以下為原始 `.text` 指令重反組譯，非伪碼。

```asm
  6d6554:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  6d655a:	89 44 24 38          	mov    DWORD PTR [esp+0x38],eax
  6d655e:	8b 11                	mov    edx,DWORD PTR [ecx]
  6d6560:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  6d6563:	6a 38                	push   0x38
  6d6565:	8b c6                	mov    eax,esi
  6d6567:	50                   	push   eax
  6d6568:	6a 01                	push   0x1
  6d656a:	ff d2                	call   edx
  6d656c:	8b             	mov    ecx,DWORD PTR [esp+0x3c]
```

#### key1 receive/first sender manager indirection 2

Native source: Tartaros.bin SHA256 `9741d...`; VA `0x006D6675..0x006D6690`, raw start `0x002D5A75`. 以下為原始 `.text` 指令重反組譯，非伪碼。

```asm
  6d6675:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  6d667b:	8b 11                	mov    edx,DWORD PTR [ecx]
  6d667d:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  6d6680:	83 c4 0c             	add    esp,0xc
  6d6683:	6a 68                	push   0x68
  6d6685:	8d 44 24 14          	lea    eax,[esp+0x14]
  6d6689:	50                   	push   eax
  6d668a:	6a 01                	push   0x1
  6d668c:	ff d2                	call   edx
  6d668e:	8b 4c            	mov    ecx,DWORD PTR [esp+0x7c]
```

#### key1 receive/first sender manager indirection 3

Native source: Tartaros.bin SHA256 `9741d...`; VA `0x006D6871..0x006D688F`, raw start `0x002D5C71`. 以下為原始 `.text` 指令重反組譯，非伪碼。

```asm
  6d6871:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  6d6877:	8b 01                	mov    eax,DWORD PTR [ecx]
  6d6879:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  6d687c:	83 c4 18             	add    esp,0x18
  6d687f:	68 ce 02 00 00       	push   0x2ce
  6d6884:	8d 95 cc fc ff ff    	lea    edx,[ebp-0x334]
  6d688a:	52                   	push   edx
  6d688b:	6a 01                	push   0x1
  6d688d:	ff d0                	call   eax
```

#### key1 receive/first sender manager indirection 4

Native source: Tartaros.bin SHA256 `9741d...`; VA `0x006D6AD1..0x006D6AEF`, raw start `0x002D5ED1`. 以下為原始 `.text` 指令重反組譯，非伪碼。

```asm
  6d6ad1:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  6d6ad7:	8b 01                	mov    eax,DWORD PTR [ecx]
  6d6ad9:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  6d6adc:	83 c4 18             	add    esp,0x18
  6d6adf:	68 ce 02 00 00       	push   0x2ce
  6d6ae4:	8d 95 cc fc ff ff    	lea    edx,[ebp-0x334]
  6d6aea:	52                   	push   edx
  6d6aeb:	6a 01                	push   0x1
  6d6aed:	ff d0                	call   eax
```
