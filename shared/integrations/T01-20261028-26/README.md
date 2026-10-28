# T01-20261028-26 | 第七批 10 份獨立原稿 FULL-PASS（各原稿有界肯定主張）

## 驗收基準與工作紀錄

- 本批採認十份**前六批沒有列入的不同 GitHub 原稿文件**。FULL-PASS 限於該份原稿已明確肯定、可以原始 BIN 證據復核的**有界事實**；原稿標註 unknown 的動態實作／跨模組物件身分／runtime／官方 server 任務規則不算已證明，也沒有一併將 Task 改為 native_complete。
- 第一手客戶端：韓版 `Tartaros.bin`（12,472,320 bytes），SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本輪從本機原始檔直接重算。唯讀、沒有執行。
- PE `.text` VA `0x401000`、raw `0x400`，故在該 section 內 `raw=VA-0x400C00`。對每份原稿 5 或 6 個肯定的 opcode/address 結論以 Python 實際讀 BIN 比較：**59/59 項一致**。核查檔保留在本地 `t01_batch7_audit.py` 與 JSON，另完整 1,202 行附 objdump 函式視窗的本地完整版 Markdown `20261028-145733-chatgpt-web-roy-T01-026-ten-document-native-fullpass-review.md`。
- 每份原稿 Git blob SHA 於本輪由 GitHub `main` 讀得。已有記錄中的 raw `E8` 掃描僅限位元組候選，不虛稱所有動態/間接函式目標均已查完。以下的欄位對應與 caller/callee 依原始 x86 指令控制流描述。
- 特別排除原稿 **T08-187**：原稿在 `0x7F6FC1` 斷言 `push 0x30`，BIN 實際為 `mov edi,eax`；真正 `push 0x30` 在 `0x7F6FBF`。另 **T08-173** 的 caller-determined `ECX` 說法被後續 `0x7B7FFE mov ecx,1` 收窄；T08-196/200 的第二索引與 lower_bound duplicate 判斷仍待釐清。此四份不計分。

## 每份原稿裁決

### 1. T08-174 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-085944-chatgpt-web-roy-T08-174-deferred-queue-consumer.md](../../../kr-temp-roy/20261028-085944-chatgpt-web-roy-T08-174-deferred-queue-consumer.md)
- Git blob SHA：`c56a5cae912d81bfad8141eeeaaa3b83016e209b`
- 全部本份可肯定的有限技術結論／上下游資料流：0x7DD1A0 +0x44 gate, +0x64 lock, +0x7C vector insertion; 0x7DD1F0 iterates +0x7C/+0x80, calls 0x7BE0F0→conditional 0x7BD850/0x89120C; end reset to begin
- 本輪原始 BIN x86 bytes （VA 後為十六進位指令位元組）：0x7DD1A7 837b4401; 0x7DD1C2 e889e1fdff; 0x7DD1F5 8d4664; 0x7DD21B e8d00efeff; 0x7DD285 899e80000000
- **保留未知及禁止越界推論**：Dynamic cleanup target, lock unwind and runtime interleaving unknown.
- 裁決：在原稿**自己明確肯定的有界技術內容**之範圍內相符；保留其餘內容的未確認狀態。

### 2. T08-175 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-085944-chatgpt-web-roy-T08-175-release-protocol.md](../../../kr-temp-roy/20261028-085944-chatgpt-web-roy-T08-175-release-protocol.md)
- Git blob SHA：`7af6cbd50284aee17caf4b77912b1a708a239efe`
- 全部本份可肯定的有限技術結論／上下游資料流：0x7BE5F0 loads resource from slot, decrements owner+0x60; +0x74/+0x78 gate leads to 0x7DD1A0 deferred/immediate release and clears slot; local cleanup alternative 0x7BE0F0/0x7BD850/0x89120C
- 本輪原始 BIN x86 bytes （VA 後為十六進位指令位元組）：0x7BE5F0 8b06; 0x7BE5F9 ff4860; 0x7BE60F e88ceb0100; 0x7DD1A7 837b4401; 0x7DD1C2 e889e1fdff; 0x7DD21B e8d00efeff
- **保留未知及禁止越界推論**：No universal concurrency, exception or object-type equivalence inferred.
- 裁決：在原稿**自己明確肯定的有界技術內容**之範圍內相符；保留其餘內容的未確認狀態。

### 3. T08-176 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-085944-chatgpt-web-roy-T08-176-ownership-lifecycle-audit.md](../../../kr-temp-roy/20261028-085944-chatgpt-web-roy-T08-176-ownership-lifecycle-audit.md)
- Git blob SHA：`735c789499a8af2581f748dc766de87a417def90`
- 全部本份可肯定的有限技術結論／上下游資料流：Producer and consumer use same owner+0x64 synchronization field and +0x7C/+0x80 region; 0x7B804A and 0x7DD140 clear owner+0x44; direct callers of 0x7DD1F0 at 0x7B8045,0x7DD132
- 本輪原始 BIN x86 bytes （VA 後為十六進位指令位元組）：0x7DD1A7 837b4401; 0x7DD1B2 8d7364; 0x7DD1C2 e889e1fdff; 0x7B804A c7464400000000; 0x7DD140 895e44; 0x7DD132 e8b9000000
- **保留未知及禁止越界推論**：T08-177 corrects the enable function true entry to 0x7B7FD0, not stale 0x7B7FA0.
- 裁決：在原稿**自己明確肯定的有界技術內容**之範圍內相符；保留其餘內容的未確認狀態。

### 4. T08-180 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-095341-chatgpt-web-roy-T08-180-formal-0007-resource-interface-audit.md](../../../kr-temp-roy/20261028-095341-chatgpt-web-roy-T08-180-formal-0007-resource-interface-audit.md)
- Git blob SHA：`4ab548ce691aca8e04f0be4ec83899d577290719`
- 全部本份可肯定的有限技術結論／上下游資料流：Scene registry insertion 0x4DFF30, erase 0x4DFBC0, bulk cleanup 0x4DFE90 have different direct calls from resource owner drain 0x7DD1F0; some component cleanup calls 0x7BE5F0 without proving owner identity
- 本輪原始 BIN x86 bytes （VA 後為十六進位指令位元組）：0x4DFF5F e89cef3400; 0x4DFF82 e879f23400; 0x4DFBD5 e826f33400; 0x4DFF0A e841393400; 0x7BE60F e88ceb0100; 0x7DD132 e8b9000000
- **保留未知及禁止越界推論**：No native full actor pointer→resource manager pointer chain established.
- 裁決：在原稿**自己明確肯定的有界技術內容**之範圍內相符；保留其餘內容的未確認狀態。

### 5. T08-181 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-181-reuse-pool-acquisition-and-count-separation.md](../../../kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-181-reuse-pool-acquisition-and-count-separation.md)
- Git blob SHA：`2f0175b00bd9f96ec62b92065a832693b4cebe6a`
- 全部本份可肯定的有限技術結論／上下游資料流：0x7DCFB0 increments owner+0x60 before lock owner+0x64, reuses last +0x7C/+0x80 pointer via 0x7BE5B0; empty path allocates 0x7C; new branch mode+0x44 test; +0x5C is separate counter
- 本輪原始 BIN x86 bytes （VA 後為十六進位指令位元組）：0x7DCFB7 8b5d08; 0x7DCFBA ff4360; 0x7DCFBF 8d7b64; 0x7DCFDF e8cc15feff; 0x7DD011 6a7c; 0x7DD0E4 837b4401
- **保留未知及禁止越界推論**：Failure rollback, actual binding class and synchronization under parallel callers not asserted.
- 裁決：在原稿**自己明確肯定的有界技術內容**之範圍內相符；保留其餘內容的未確認狀態。

### 6. T08-182 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-182-mode-switch-and-binding-boundary.md](../../../kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-182-mode-switch-and-binding-boundary.md)
- Git blob SHA：`f9717b667a90cee6a554f04d4070472e643918bb`
- 全部本份可肯定的有限技術結論／上下游資料流：0x7B7FD0 sets manager +0x44=1, 0x7B8030 drains before zeroing; new allocation uses mode gate at 0x7DD0E4→0x7BDF90 binding, re-use goes 0x7DCFDF→0x7BE5B0 distinct reset path
- 本輪原始 BIN x86 bytes （VA 後為十六進位指令位元組）：0x7B7FFE b901000000; 0x7B8006 894a44; 0x7B8045 e8a6510200; 0x7DD0E4 837b4401; 0x7DD0EC e89f0efeff; 0x7DCFDF e8cc15feff
- **保留未知及禁止越界推論**：Dynamic Provider/Binder concrete target and equivalence of reset/rebind unknown.
- 裁決：在原稿**自己明確肯定的有界技術內容**之範圍內相符；保留其餘內容的未確認狀態。

### 7. T08-183 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-183-manager-last-release-and-container-destruction.md](../../../kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-183-manager-last-release-and-container-destruction.md)
- Git blob SHA：`ecbec611a9d99a7640ae4fad9668dcc3c06ad4be`
- 全部本份可肯定的有限技術結論／上下游資料流：0x7B8124 node+0x24 manager payload, 0x7B8129 decrements ref via 0x7DD100, tests return; only zero path calls 0x7DCF40 then 0x89120C, and 0x7B8680 updates/removes tree node
- 本輪原始 BIN x86 bytes （VA 後為十六進位指令位元組）：0x7B8124 8b7824; 0x7B8129 e8d24f0200; 0x7B812E 85c0; 0x7B8136 e8054e0200; 0x7B814C e82f050000; 0x7DD132 e8b9000000
- **保留未知及禁止越界推論**：Does not prove all possible references or exceptional deletion routes.
- 裁決：在原稿**自己明確肯定的有界技術內容**之範圍內相符；保留其餘內容的未確認狀態。

### 8. T08-185 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-101203-chatgpt-web-roy-T08-185-registry-node-virtual-callback-disposal.md](../../../kr-temp-roy/20261028-101203-chatgpt-web-roy-T08-185-registry-node-virtual-callback-disposal.md)
- Git blob SHA：`24077d1529e6031fa9fda874ac14b2b79b5ccb7f`
- 全部本份可肯定的有限技術結論／上下游資料流：0x7DC510 sentinel-gated lookup and node+0x24 payload; callback vtable+0x0C, zero result permits vtable+0x00(1) and 0x7B8680 erase; 0x7DD17D is a direct callsite
- 本輪原始 BIN x86 bytes （VA 後為十六進位指令位元組）：0x7DC599 8b7824; 0x7DC59C 8b07; 0x7DC59E 8b500c; 0x7DC5A3 ffd2; 0x7DC5C2 e8b9c0fdff; 0x7DD17D e88ef3ffff
- **保留未知及禁止越界推論**：Index payload vtable and actor registry identity unresolved.
- 裁決：在原稿**自己明確肯定的有界技術內容**之範圍內相符；保留其餘內容的未確認狀態。

### 9. T08-186 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-101203-chatgpt-web-roy-T08-186-manager-destructor-buffer-lock-order.md](../../../kr-temp-roy/20261028-101203-chatgpt-web-roy-T08-186-manager-destructor-buffer-lock-order.md)
- Git blob SHA：`2e9880fdf0b4a0bec0b2f92dfc401f0013439a1a`
- 全部本份可肯定的有限技術結論／上下游資料流：0x7DCF40 EDI-based cleanup: nonnull pointers over +0x4C..+0x50 freed, +0x7C buffer freed, zero +0x7C/+0x80/+0x84, IAT [0xBD2228] given owner+0x64, then +0x4C backing buffer free and +0x4C/+0x50/+0x54 zeros
- 本輪原始 BIN x86 bytes （VA 後為十六進位指令位元組）：0x7DCF42 8b774c; 0x7DCF57 e8b0420b00; 0x7DCF69 8b477c; 0x7DCF71 e896420b00; 0x7DCF8C ff152822bd00; 0x7DCFA3 895f4c
- **保留未知及禁止越界推論**：Import name and all nested item destructors/exception safety remain open.
- 裁決：在原稿**自己明確肯定的有界技術內容**之範圍內相符；保留其餘內容的未確認狀態。

### 10. T08-189 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-189-registry-lookup-payload-vcall-boundary.md](../../../kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-189-registry-lookup-payload-vcall-boundary.md)
- Git blob SHA：`a593f50abda9dc3523e07c727c8eeab6d3ae4514`
- 全部本份可肯定的有限技術結論／上下游資料流：0x7DC510 sentinel match and payload callback vtable+0x0C; zero status permits delete slot+0x00 and index erase 0x7B8680; direct 0x7DD17D to 0x7DC510 distinguished from vtable call
- 本輪原始 BIN x86 bytes （VA 後為十六進位指令位元組）：0x7DC599 8b7824; 0x7DC59E 8b500c; 0x7DC5A3 ffd2; 0x7DC5C2 e8b9c0fdff; 0x7DD17D e88ef3ffff; 0x7DC591 8b45b4
- **保留未知及禁止越界推論**：No proven vtable implementation or same-instance actor ownership.
- 裁決：在原稿**自己明確肯定的有界技術內容**之範圍內相符；保留其餘內容的未確認狀態。


## 綜合資料流及反證重點

1. `0x7DD1A0` 的 `owner+0x44` signed gate 為 producer；`0x7DD1F0` 在 `ESI` 指示的 manager 上 drain；`0x7DCFB0` 另從同一 `+0x7C/+0x80` 取出並復用。不可說延遲佇列所有項目「只會在 drain 時 free」。
2. `owner+0x5C` 的管理器 terminal-reference 計數與 `owner+0x60` 的 acquire/release 計數必須分開，兩者 offset 不同，不能用名字相似混成一個 thread-safe 原語。
3. `0x7B8124` node+0x24 manager payload 並不表示所有 actor-tree node 都有這種 manager payload；`0x7DC510` 名稱索引的 vtable+0x0C/+0x00 回呼，不能無依據命名為場景 actor 析構。
4. `0x7DCF40` 的兩個分離向量 `+0x4C` 和 `+0x7C` 有不同清理順序。IAT `[0xBD2228]` 實際 API 名需 PE import table；此處僅確定位址與呼叫。
5. `0x4DFF30` / `0x4DFBC0` / `0x4DFE90` 三個 actor-tree 介面與資源管理器無直接 `E8` drain 邊。Component→resource release 的局部橋已找到，不等於 actor-to-owner 的完整指標身分。
6. 限於**這批文件有界主張**的 FULL-PASS，不代表 0007 server spawn/wave/AI、所有動態 vtable 或 gameplay 都被還原。

## 重現指令

```sh
sha256sum /mnt/data/Tartaros.bin /mnt/data/Tartaros.exe
objdump -d -Mintel --start-address=0x7dd1a0 --stop-address=0x7dd2a5 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x7dcfb0 --stop-address=0x7dd100 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x7dcf40 --stop-address=0x7dcfae /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x7dc510 --stop-address=0x7dc5dc /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x7b80ed --stop-address=0x7b8156 /mnt/data/Tartaros.bin
```

## T01 下一輪交接

- 本批新增文件：T08-174, T08-175, T08-176, T08-180, T08-181, T08-182, T08-183, T08-185, T08-186, T08-189。
- 前六批共有 60 份不同路徑之 document-scope 驗收紀錄；本批新增 10 份，累計 **70 個不同原稿檔案／路徑**，非 70 個不同段號，也**不等於 70 項 end-to-end native_complete 功能**。
- T08-187 的 `0x7F6FC1` 反證待作者更正；T08-173、196、200 均應先排除錯誤/過度命名；其他 T08-184、188、190～192 尚待全主張審查。
- 沒有覆寫原稿、owner、任何其他 Task 技術筆記或共用 source-review-status。
