# T01 第二批實質整合：RR-0005 Pool+0x28/0x48 × send-count/RX-throttle × T16 傳輸邊界（R2）

**交付性質**：延續第一批 `T01-20261030-EXTRA-T16-CROSS-TASK-R0-R2.md` 的 **T01 增量分析草案**。已於本地原件 BIN-first 核對，不修改任何原稿、正式收件台帳、RR、FULL-PASS 共用知識或 S00 SPEC。本批未獲使用者明確 Commit／Push 授權，僅本地檔案。

- **唯一客戶端**：KR `Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本次重新核對；KR `.text` VA `0x401000`、raw `0x400` → `raw=VA−0x400C00`。不同 section 不套用此公式。
- **遠端來源基準**：GitHub `main=fb70e1325069c2069b428cf01ab57b4a4d7319c2`（開工讀回，來源 SHA 固定），本地第一批 59 份來源及 14 項草案主張已保留；T16 工作分支在本次開工讀回與主線**不同步**，未嘗試整合後續新增文檔。
- **本次可重現新增核對**：[腳本](T01-20261030-batch2-verify.py)、[結果 JSON](T01-20261030-batch2-native-results.json)、[原始解碼摘錄](T01-20261030-batch2-native-excerpts.md)。**57 個定點機器碼 bytes、20 條 E8/Jcc 相對分支／目的地、5 個 PE import、4 組 opcode-pattern census、5 個有界新進展**全部通過。此項是 R2 位置/控制流定向驗證，**不是完整 rooted-CFG／所有 writer/caller 的 exhaustiveness 驗收**。
- 本批正式索引無新 `SRC`、`CLM`、`RR ACCEPTED`、`NATIVE_VERIFIED` 或 S00 `SPEC STABLE`。來源 R0 59 份仍為本地草案，沒有偽稱原稿 SHA256 已逐檔獲得。

## 1. 重大增量：`Conn+A0B8` 的 send-only 可見鏈，不可混 `A0BC`

### 1.1 原件 IAT 與 send 兩個成功分支

由 PE IAT 實際重算：`BD25B8=WSASend`、`BD25BC=WSARecv`、`BD2284=InterlockedIncrement`、`BD227C=InterlockedDecrement`、`BD2280=InterlockedExchange`；實際 RAW 確認 `0x806912` 是唯一 `WSASend` *直接 FF15 IAT 指令模式*命中；本輪找到 `0x806A4C` 為 `WSARecv` 直接 FF15 指令。**模式搜尋不等於所有間接 call 的 CFG 完全列舉**。

```asm
8068DE  lea eax,[esi+A050]      ; outgoing OVERLAPPED identity
8068F3  push eax                ; lpOverlapped
8068F7  lea ecx,[eax+14]       ; WSABUF at Conn+A064
806909  push ecx                ; lpBuffers
806912  call [BD25B8]         ; WSASend
806920  cmp eax,-1
806923  jne 80697A            ; synchronous API success
80692D  cmp edi,3E5h           ; WSA_IO_PENDING = 997
806933  je 806961             ; pending accepted
806961  add esi,A0B8h; push esi; call [BD2284] ; pending branch +1
80697A  add esi,A0B8h; push esi; call [BD2284] ; synchronous success branch +1
```

因此 `A0B8` 不是「WSASend 成功就已將資料送達 Server」，而是**這個出站路徑中兩種已提交/send-post 結果的在途完成計數**。同步成功仍 ++，不能只在 pending path 做平衡。

### 1.2 IOCP 成功及失敗兩條 send decrement

```asm
806D84  call [BD2274]         ; GetQueuedCompletionStatus
806DE4  lea edi,[eax+A030]    ; receive OVERLAPPED identity
806DEC  jne 806E7D            ; unmatched RX -> test send identity
806E04  lea edx,[eax+18]; push eax
806E08  call 807B40           ; receive frame parser (conditional)
806E7D  lea edi,[eax+A050]    ; send OVERLAPPED identity
806E83  cmp edx,edi
806E85  jne 806D30            ; not this send instance -> no send count --
806EA1  call 8077B0           ; when A0AC branch permits, consume local sent bytes
806EBD  add edx,A0B8h
806EC4  call [BD227C]         ; decrement on successful send completion
806ECF  ...                   ; failed GQCS branch
806EE7  lea edx,[eax+A050]
806EED  cmp ecx,edx
806EEF  jne 806F00
806EF1  add eax,A0B8h
806EF7  call [BD227C]         ; decrement on failed send I/O completion
806F00  mov eax,[eax+A0B8]
806F08  jne 806D30            ; count nonzero: do not take this close path
806F13  mov edx,[edx+24h]    ; virtual close/error handler (purpose bounded)
806F1A  call edx
806F1F  mov [eax+A0A8],1
```

**新精確限制**：`0x806EF7` 的 `--` 只在 **GQCS 失敗且 OVERLAPPED matches `A050`** 的 branch；其他失敗事件也可能走至 0x806F00 零計數判斷，但不代表所有錯誤都呼叫 `InterlockedDecrement`。此處不宣稱 `virtual+0x24` 的所有副作用，也無證據說 `A0A8` 立刻 free 舊 Conn。

### 1.3 RX 沒有使用相同的計數地址（限定具體路徑）

```asm
806A0A  lea eax,[esi+A030]     ; RX OVERLAPPED
806A2E  lea ecx,[eax+14]      ; RX WSABUF=Conn+A044
806A3B  mov [ecx],1000h       ; RX buffer capacity
806A4C  call [BD25BC]        ; WSARecv
806AAB  call 8065B0          ; successful/pending receive -> separate gate
8065C5  mov eax,[esi+A0BC]
8065D3  lea edi,[esi+A0BC]
8065F2  call [BD2280]        ; InterlockedExchange on A0BC
806611  call [BD2284]        ; InterlockedIncrement on A0BC
```

`806A00` **這個 RX 呼叫者**及所接的 `8065B0` 在可見路徑只碰 `A030` 的 RX OVERLAPPED 和另一個 `A0BC` gate；`806DE4..806E78` 的正常 RX 完成路徑也不在 `A0B8` 做計數遞減。所以在本路徑可稱 **A0B8 observed send-outstanding count**，而不是「所有非同步 I/O (send+receive) 總計數」。`8065B0` 的 `A0BC` 比較／節流語意仍待獨立追查，不在本批稱為 send count。

### 1.4 原子呼叫模式全節搜索（只是候選 xref）

在 PE `.text` 全區按位元組搜尋直接 `FF 15` import 模式：`InterlockedIncrement` **8** 處、`InterlockedDecrement` **16** 處、`WSASend` **1** 處、`WSARecv` **1** 處；每個位址見 JSON。**這只是 raw pattern census**，不得推論所有位址都有正確入口／動態可達、也不能推論間接 import function pointer call 不存在。`0x806611` 對 `A0BC`，`0x806968/806981` 對 `A0B8`；不能將三次 Increment 合併成同一欄位。

## 2. 重大增量：`Pool+48` marker→`Pool+28` 清理→`Pool+48` 等待 async count 的兩階段回收

### 2.1 兩類 Pool+48 producer 已在原生程式逐段查證

**連線失敗入列（`0x805AF0`）**：

```asm
805AF3  dec dword [esi+44]     ; Pool reference/count candidate
805AF7  mov edi,[esi+48]      ; Pool+48 sentinel
805B03  call 74D700          ; insert list node
805B24  inc ecx               ; Pool+4C count update at 805B25
805B30  mov dword [edx+14],0  ; Conn+14 cleared
```

上游有 `0x806BD4`、`0x806BFB` 呼叫 `805AF0` 的條件性 Connect 失敗分支，需先經當時 socket 出錯分支，不是每次 connect 都回收。

**manager teardown inline（`0x8066A0`）**：

```asm
80673C  mov eax,[esi+10]      ; tree-node+10 -> Conn pointer candidate
80673F  dec dword [edi+44]   ; Pool+44
806742  mov ebx,[edi+48]     ; Pool+48 sentinel
806751  call 74D700          ; insert list node
806769  inc ecx             ; Pool+4C update at 80676A
806775  mov eax,[ebp-10]    ; saved Conn pointer
806778  mov dword [eax+14],0 ; same eligibility marker
```

兩條來源都有 **Pool+48 list insertion + count update + `Conn+14=0`**。這使 `Conn+14` 不再只是「無語意舊欄位」；在本批可見路徑它是**回收流程的狀態標記/清理 gate**，但不能稱為官方 refcount 或保證獨占所有權。

### 2.2 `0x805B40` 先掃兩條不同列表，條件不同

```asm
805B4C  mov ebx,[edi+28]       ; Pool+28 sentinel
805B55  mov ecx,[eax+8]        ; linked node Conn*
805B58  cmp dword [ecx+14],0   ; Conn+14==0 -> detach tracking node
805B7B  dec dword [edi+2C]     ; Pool+28 tracking count--
805B88  mov ecx,[edi+48]       ; Pool+48 sentinel
805BA3  mov esi,[eax+8]        ; linked node Conn*
805BA6  mov ecx,[esi+A0B8]     ; pending send count gate
805BAF  test ecx,ecx
805BB1  jne 805C51             ; count nonzero -> skip this Conn
805BB7  call 805F50           ; reset Conn fields for recycling
805C49  dec dword [edi+4C]     ; Pool+48 count-- after node remove
```

`0x805B40` 在 `A0B8==0` 分支先做 reset，再將該 Conn 指標放入 Pool 的 block/vector，才移除 `Pool+48` node；`0x805C06` 若配置 16-byte block 失敗則進例外分支，**不保證所有時候立即回收**。若 count 非零，`805C51` 跳過該次 reset/remove，保留待後續掃描。`0x805F50` 寫 socket=-1、`A0A4=0`、清 pending queue 等部分欄位；不該把這個 reset 當 socket close 的所有責任。

**整合後有界偽碼（推導，非原 C++）**：

```cpp
// This is only the observed bounded path; locks/threads/exception owners omitted.
void pool_enqueue_recycle(Pool* pool, Conn* old) {
    --pool->field_44;
    list_push(pool->list_48, old);
    ++pool->count_4c;
    old->field_14 = 0;
}
void pool_scan(Pool* pool) {
    for (Node* n : pool->list_28) {
        if (n->conn->field_14 == 0) {
            list_erase(n);
            --pool->count_2c;
        }
    }
    for (Node* n : pool->list_48) {
        Conn* c = n->conn;
        if (c->field_a0b8 != 0) continue; // observed send outstanding gate
        reset_conn_805f50(c);
        pool_vector_insert(c);  // helper and allocator error paths are not fully closed
        list_erase(n);
        --pool->count_4c;
    }
}
```

**重要反例與上游缺口**：
- `Conn+14=0` 可能還有其他 writer，不可宣稱只有這兩種 producer；manager key-map node erase `0x806CB3→0x7B6890` 與 Pool lists 的 Conn owner alias 關係未閉合。
- 顯示的兩條 Pool+48 producer 尚未證明相同 Conn 可否重複入列、是否 mutex 涵蓋所有路徑、或 list28/list48 的掃描和 IOCP 完成 callback 之間是否有競態。
- 本次 native result 查 57 處 bytes、20 個相對分支，並**非 805B40/8066A0 的完整 rooted CFG 主張**；上述偽碼將可見的正常/主要路徑合併，不宣稱覆蓋例外與所有 branch。

## 3. RR-0005 與 T16 的交叉責任矩陣

| 主題／研究來源 | 這批可從 native 直接受支持 | 仍未知（不得冒充 Server 決策） | 責任與交接 |
|---|---|---|---|
| E48/E49/E50：重連 key-map & Conn ownership | `806C9E` lookup、條件式 `806CAA`、`806CB3` erase helper、`806CC7→806CD2` 新 node | 舊 Conn 是否在 map erase 時仍有 pool/UI/socket/IOCP owners；世代/競態 | **Client 待逆向** T02，RR-0005 的具體缺口，不代表 S00 ACCEPTED |
| E49/E50：Pool+28/+48 | 兩類 producer、`+14` gate、兩列表不同 count、`A0B8==0` reset gate | 同 Conn 不同列表生命週期的 race-free 不變式；所有錯誤／cancel | Client T02 + T01 風險複核；Server 不需要重做客戶端內部 pool 演算法 |
| E50 + T16-97 + T03-6 | 兩 WSASend increment / send completion success/failure decrement，RX A0BC 節流不同 | 同 session 所有增減是否完全配對、OVERLAPPED 重用、fail GQCS 之後 old owner | T01 的既有 `CLM-NET-0013` 反證持續，避免第二條 duplicate；R2 限定驗證 |
| T16-107 TalkBox / 0x36 | 作者觀察符合本地 queue→frame→WSASend 這套框架 | 0x36 特定 wire 已達 Server、Quest ACK / NPC state 及 Quest16→15 | **Client 待逆向** T16；不能把 T02 send count 換成 Quest 通過 |
| T16-110-REV/113 Scenario14 | QuestInfo14 與 Scenario14 同值不同 namespace，原先限制保留 | Quest14 專屬完成回覆、任務 UI state writer | T16 Client GAP + S00 自訂 Server Quest 規則規格 DRAFT |
| S00 | 可引用有界 Client 靜態契約及否證做 SPEC/GAP/TEST 候選 | 合法首包 payload 長度／資料與端到端狀態 | **S00 審查方**，未經審查不能標 SPEC_CONSUMABLE、RR ACCEPTED、SPEC STABLE |

### S00 可採用的具體測試計畫（提案，不是測試通過）

1. **IOCP send accounting**：模擬 `WSASend` 同步成功、997 pending、其他失敗，再分別投遞 send completion 成功與失敗（matching `A050`）；驗計數 increment/decrement；**不把 WSARecv `A0BC` 演算法誤算 A0B8**。
2. **Pool+48 gate**：Conn 進入 Pool+48 後，當 `A0B8>0`，驗證 `805B40` 應跳過 reset/remove；計數降到 0 後再檢查 reset/vector/list/remove 路徑；所有此類測試都需在可控模擬/分析環境，不以原版遊戲可玩宣稱。
3. **Pool+28 marker**：透過 `805AF0` 及 `8066A0` 兩 producer 分別讓 `Conn+14=0`，檢查 `805B40` 掃描 Pool+28 tracking node 時採用該條件，而不是把該 field 當 UI status。
4. **重連舊所有權**：要求 T02 針對相同 key 的舊 Conn xrefs、node+10 與 manager map 的替代方式補全 CFG；本批不能決定實際 free/finalize 及 race 策略。
5. **Quest 14/16/15**：不同 namespace 狀態比較（QuestId, ScenarioId, NPC object, opcode, channel）及錯誤/不送/重連後 UI gating；保留 payload/Client update UNKNOWN。

## 4. 本輪階段狀態和停止理由

- **本批重大有界增量**：從「A0B8 是 pending async IO」精化到 **send success/pending ++、send completion success/failure --，RX+A0BC 是不同 throttle**；從「Pool 雙列表」精化到 **Pool+48 producer 清 Conn+14 → Pool+28 node detach gate → Pool+48 A0B8 gate + reset/recycle**。具原始指令 + direct branch 和第三方來源相互參照，達到一個新的實質研究交付門檻；不進行無意義的同主題重複第三輪。
- **R0**：前一批 59 個 identity 仍是本地暫存、raw SHA 未逐一完成；這輪針對 9 份關鍵原稿與既有 T02/T03 canonical 做 R1/R2 限定交叉核對，**未逐篇全文審核**。
- **R2**：獨立確認 57 個定點 bytes、20 條直接分支／CALL displacement、5 個 PE import；跨 Task 限定衝突結果與 source version 顯式呈現。
- **R3**：**0 新增**；沒有將原稿全文、所有 Conn alias、全部 IOCP 生命週期、Quest wire 或 S00 可玩契約冒稱 FULL-PASS。
- **不開新 RR、不認領 RR-0005**：正式主責為 T02，待 S00 指派／Task 依流程認領；T01 此次做增量整合與複核。
- **下一大批**：沿 `0x806AD0` conn create→`0x806CB3` replace→`0x8066A0` manager teardown、`0x806FC0` close、`0x805B40` reset，釐清 `Conn+14` 其餘 writers 與 map node erase 是否 release 舊 Conn；再展開 `0x806CF0` 所有 GQCS 成功／失敗／unknown OVERLAPPED 分支的 owner、live state 與 `A0B8` 是否存在 unmatched cleanup。另一條獨立主題是 T16-107→Quest state writer／回覆處理的同一 local→wire→S2C 通路。

## 5. 本批交付清單

- `T01-20261030-R2-BATCH2-NATIVE-SEND-RECYCLE.md`（本報告）。
- `T01-20261030-batch2-native-results.json`（57 bytes + 20 edge + 原始呼叫 pattern 全區候選）。
- `T01-20261030-batch2-verify.py`（只讀可重現腳本，需原始 `Tartaros.bin`）。
- `T01-20261030-batch2-native-excerpts.md`（原始 BIN 12 個較完整函式窗口之組語摘錄，**線性解碼非完整 CFG**）。
- `T01-20261030-batch2-claim-delta.json`（承接第一批 C02/C05/C06/C09 的 source 級別修正／gap，不含正式 `CLM` 編號）。

**GitHub 狀態：本輪未 Commit／Push。**