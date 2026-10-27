# T08-124 — Second geometry updater entry, resource iteration, unresolved global consumer

- Task: T08｜researcher: chatgpt-web roy｜time: 2026-10-27 17:51 Asia/Taipei
- Original: Tartaros.bin｜SHA256: `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪本地計算確認）
- Source: 本輪以 `objdump -d -Mintel /mnt/data/Tartaros.bin` 反組譯直接對照 ASM；無 Ghidra 推論冒充原始機器碼。
- Evidence grading: **已確認** = machine code supports; **推測** = interpretation; **未知** = no proof.
- Repository target: `kr-temp-roy/`，不更動其他 Agent 內容。

## 1. 第二個外層呼叫鏈不同於第一個
T08-120 已確認 `0x007BA56E` 同樣呼叫 `0x00799D20` 並傳入 `push 0x00FB76A8`。本段檢查前置分支，發現此路徑同時處理 `[EDI+0x7C]` 物件陣列及多個本地狀態標記。

```asm
007BA3EE cmp ebx,esi
007BA3F2 mov eax,[edi+0x7c]
007BA3F5 mov edi,[eax+esi*4]
007BA3F8 call 0x7e42f0
007BA406 mov byte ptr [esp+0x40],0
007BA40B call 0x837fd0
007BA41F test byte ptr ds:0xfb79e8,1
007BA434 call 0x798de0
007BA44B cmp dword ptr ds:0xfba840,0
007BA458 push 0x258
007BA45D push 0x320
007BA462 push 0x12c
007BA46B push 0x190
007BA470 push eax
007BA476 call 0x7c9190
007BA47E cmp dword ptr [edi+0x40],0
007BA49B call 0x7e7240
007BA4D0 mov edx,[edi+0x7c]
007BA4D3 mov eax,[edx+esi*4]
007BA4DC call 0x7e43d0
007BA4FF test byte ptr ds:0xfb79e8,1
007BA52B mov esi,ds:0xfb76e8
007BA531 call 0x798090
007BA536 test byte ptr ds:0xfb79e8,1
007BA54B call 0x798de0
007BA562 fld dword ptr [ebp+8]
007BA569 push 0xfb76a8
007BA56E call 0x799d20
007BA573 mov eax,0xc4fc3c
007BA578 call 0x8380b0
```

**注意** 上列呈現片段中存在短路分支、局部迴圈與一次性初始化；不能把所有指令當成每次線性必經。尤其 `0x007BA4FF` 和 `0x007BA536` 的初始化檢查不意味每次真的重建。

## 2. 與參與者回呼的區別
`0x00799D20` 呼叫 `0x00838430` 更新 24 floats，後續用 handle+0x9C 迭代並派送各 participant 的 vtable+0x18（詳 T08-120）。和 callback `0x00C4FF8C+0x0C` 以及資源/場景物件 vtable+0x20 的身分不同；不能按槽位相似推斷它們屬同一類。

## 3. 本輪 121～124 結論、偽碼與尚待解決
```cpp
void secondaryUpdate(float value) {
  for (auto* item : owner->array_7C) step_7E42F0(item);
  // conditional global resource init and processing
  step_798090();
  geometry_799D20(&globalHandle,value);
  // other dispatch steps
}
```
這只是摘錄有證據的功能片段，owner/scene class 名稱未知。

**已確認**：兩個 distinct direct `0x00799D20` callers、第二入口的陣列迭代/初始化/後續派送、全域桶建立與多個插入者、callback 不同虛槽。

**合理推測**：兩入口可能位於不同層級的週期更新管線；未證明每幀頻率，也未證明兩入口可並行調用。

**仍未知**：全域 `[0x00FB7740]` 的逐筆 consumer、`0x007D1310` 的外部 owner 實參、場景 vtable `0x00C07554+0x20` 主呼叫迴圈。六係數正常寫入者 `0x00838430` 已由 T08-118 解決，之後不應重複尋找。

## T08-125 最優先方向
1. 追 `0x005F5D10` callback interface/外部 dispatcher，尋找以 `vtable+0x0C` 呼叫並傳入的 owner 指標的完整證據鏈；不可混用 callback+0x04。
2. 以 `[0x00FB7740]` 的動態值或 alias 跟蹤真正 entry 遍歷與 count reset，靜態觀察 layout 不足。
3. 向外追 `0x00492567`、`0x007BA56E` 所在函式的呼叫者，與 `0x004C8580` 的跨系統調度關聯。
