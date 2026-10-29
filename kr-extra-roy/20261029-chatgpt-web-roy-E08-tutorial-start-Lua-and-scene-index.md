# E08 — Event SceneList 索引節點及原始 tutorial_start Lua 實作（KR BIN / Event.stp 原件）

日期：2026-10-29；研究分支 `extra/roy1`；原件唯讀。承接 E07。研究源：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Event.stp` SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；E06 `Event/SceneList.xml` SHA256 `8d2e6a053b71750bfbd5337545446170f03316b185b2fdd94163bebe7146ba25`。

## 本段重大新增：tutorial_start 真正原始 Lua source 已在 Event.stp 內找到

原始 STP 經逐 byte XOR 0xFF 後，offset `0xA1C010..0xA1C219` 是連續 **522 bytes** 的教學場景 Lua source，SHA256 `1fc158a28915b6f0047941cb8a5c00534aa81c5538d153f1f05b5b2ff012eedc`；此段 source 包含註釋 `-- Quest #1001 / Scene #1 - Function tutorial_start`、`function tutorial_start()` 與 `Register(tutorial_start)`。同一原件 XOR view 在 `0xAB8640` 可找到 `tutorial_start.seq` 目錄檔名，這比 E07 的「只是 XML 名稱」有重大實質增量。後續需把目錄的 ordinal / payload SHA 做更完整結構驗證；本段 source 邊界採兩個可讀文字錨點界定，不宣稱已證明 container record 的所有 metadata。

所還原 Lua body，依實際 source 順序：
- `SetTransitionType(0)`、`SetFinalMusic("")`、`HideOriginalObjs(1)`、`Phase1()`
- `LoadMap("town000D.map")`、`MoveCamera(223.00, 140.00, 200.00)`、`RotCamera(4.18, 1.06, 12.00)`
- `Phase2()`、`Phase3()`、`Phase4()`
- `PlayCamera("tutorial_00_1.cam", 0, 0.00, 0.00, 0.00)`
- `RevPhase4()`、`RevPhase3()`、`RevPhase2()`
- `Q.DeleteAllObject()`、`RestoreMap()`、`RevPhase1()`
- `Register(tutorial_start)`

這是 **Event scene function** 而非 `TutorialMain.lua` 裡 `Tutorial_EntryPoint` 的自動別名；兩者直接調用鏈仍未證實。場景資源路徑 `town000D.map` 與 `tutorial_00_1.cam` 是 script 字面值，不能據此猜出相容 Server 送出的地圖指令。

## 原始 Client BIN：SceneList XML row 的兩欄鍵索引已實質定性

E07 中 `0x5609B3 call 0x568950`、`0x5609C4 call 0x568680` 本輪向下分析證明：

```asm
568980: push 0x34         ; new record node (52 bytes)
568982: call 0x891268
568995: mov eax,[ebx+4] ; header/sentinel child link
568998: mov [esi],eax
5689A6: lea eax,[esi+0xc]
5689BE: mov ecx,[edi]
5689C0: mov [eax],ecx
5689C2: mov ecx,[edi+4]
5689C5: mov [eax+4],ecx
5689CE: mov dword ptr [ecx+0x14],0xf ; local std::string SSO init
5689DB: call 0x402BB0   ; copy trailing funcName string
5689F3: ret 4
```

新 node `+0xC,+0x10` 存入來自 XML parser 建立記錄的兩個 32-bit 整數；`+0x14` 起是 C++ 字串相關儲存（不可將 `0x5689CE` 的 `ecx` 誤認為 node base，精確指令需依上下文保留）。`0x568680` 明顯使用兩個鍵做先後排序，而非單一 id：

```asm
56869F: mov edx,[esi+0xC]
5686A2: mov ecx,[eax+0xC]
5686A7: cmp ecx,edx
5686AD: mov ecx,[esi+0x10]
5686B0: cmp ecx,[eax+0x10]
5686D5: push 1
5686DF: call 0x5687B0
5686E7: mov [ebx],edx
5686E9: mov byte ptr [ebx+4],1
5686F6: mov eax,[eax]
568710: mov ecx,[esi+0xC]
568719: mov ecx,[ebp+0xC]
56871C: mov eax,[ecx+0x10]
568731: call 0x5687B0
56873B: mov byte ptr [ebx+4],1
568778: mov [ebx],eax
56877B: mov byte ptr [ebx+4],0
```

`0x568680` 是紅黑樹式有序索引查找/插入，lexicographic key為 `(node+0xC, node+0x10)`，成功新插入經 `0x5687B0` 並對 output flag 寫 1，匹配已有項則可走 output flag 0 分支。它不是網路事件 handler，也不是 EX 解碼器。**鍵欄位對照**：在 `0x5608D9` 讀 `questIdx`（整數轉換後儲存 stack 欄位），`0x560911` 讀 `sceneIdx`，`0x56093D` 讀 `funcName`；這三者包成 record 由 `0x5609B3` 寫節點，再由 `0x5609C4` 插入索引。由此可將 `(questIdx,sceneIdx) → funcName` 稱為**原版 Client SceneList 雙鍵索引**；尚未找到玩家端哪個 caller 用該表進行實際場景開啟。

`0x5687B0` 內 `0x5687FA inc [container+8]` 更新元素數，`0x5687FE..` 寫 tree parent/link；`0x56883C..` 在插入後處理 byte `node+0x30` 的平衡旗標，支持 red-black-style tree 解讀。新節點大小 0x34、排序鍵 +C/+10 與 flag +30 是本輪直接機器碼觀察；具體 C++ STL 實作名只是推定。

## 可重現驗證片段

```python
from pathlib import Path
from hashlib import sha256
b=Path("Event.stp").read_bytes()
assert b[:4]==b"STPD"
d=bytes(c^255 for c in b)
source=d[0xA1C010:0xA1C21A]
assert len(source)==522
assert sha256(source).hexdigest()=="1fc158a28915b6f0047941cb8a5c00534aa81c5538d153f1f05b5b2ff012eedc"
assert b"Quest #1001 / Scene #1 - Function tutorial_start" in source
assert b"function tutorial_start()" in source
assert b'Register(tutorial_start)' in source
assert b'tutorial_start.seq' in d
```

```bash
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x568680 --stop-address=0x568a30 Tartaros.bin
objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 --start-address=0x5608d0 --stop-address=0x5609d0 Tartaros.bin
```

## 玩家情境、跨 Task 與限制

- **已確認**：XML 中 `1001/1→tutorial_start`；Event.stp 同時含完整 `tutorial_start` Lua source 和 `tutorial_start.seq` 目錄名稱；Client 透過 `0x5607D0 → 0x568950 → 0x568680` 將 XML 的 `(questIdx,sceneIdx,funcName)` 存成有序索引。
- **尚未證明**：`tutorial_start.seq` 是否被哪個原生 caller 載入／執行；`Tutorial_EntryPoint` 與 `tutorial_start` 之間的因果調用；第一次選角之後 server 如何指定場景；哪些 S→C bytes 構成正式 1001/1 啟動。
- **Server 待開發**：只可先保存已證 XML key/funcName 表關係；不可將 1001/1 升格為「所有新帳號必然進入」的已證官方協定。
- **下段 E09**：找 `tutorial_start.seq` 實際 loader / scene-index reader，並沿 Lua Register/Execute 層確認 key-to-script dispatch；從 T03 `0x42` response 追首次登入 state，跨 T07 controller 核對。
- **Git 清理規則**：原稿保留 `extra/roy1:kr-extra-roy/`，只有 T01 正式吸收且稽核通過後再刪暫存路徑；本輪不碰 main。

## 三輪門檻

E08 第 1 輪已取得過去不存在的 `tutorial_start` 完整原件 source + `(questIdx,sceneIdx)` 有序索引原生新增關係，符合重大新發現，故 E08-2/E08-3 未啟動；不表示玩家首登端到端已完成。
