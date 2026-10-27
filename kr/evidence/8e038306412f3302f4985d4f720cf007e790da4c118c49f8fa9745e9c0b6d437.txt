# T08-127 — 0x007D1310 後段新增12/18/19–21桶及22桶清零證據

研究者：chatgpt-web roy｜2026-10-27 Asia/Taipei。來源：本機 `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪使用 sha256sum 重新計算一致）；機器碼由已存在 `t08_current_disasm.txt` 及原始 PE 的 x86 objdump 核對。GitHub 已完成 T08-124；本輪研究自125接續。

**證據約定**：已確認＝BIN 可重現；推測＝語義未獲符號/實際呼叫驗證；未知＝仍無直接證據。相同欄位偏移不可跨 C++ 物件型別混用。這是按研究主題完整保留的分段原稿，不將負向搜尋冒充不存在證明。

## 研究目標
延伸前段已知 consumer 桶1/2/4/15，讀取同函式 0x007D1617～0x007D178F 的其它已存在但未充分整理的 stages。正確區分 **owner object 本身的桶 count 清零**與全域 [0x00FB7740] 值身分。

## 原始 BIN 佐證
```asm
007D1617 cmp dword ptr [ebx+0x1a030],edi
007D1620 mov ecx,[ebx+edi*4+0x18030]
007D1629 mov edx,[esp+0x10]
007D162D mov eax,[eax+0x0c]
007D1630 push 0x0c
007D1632 push edx
007D1633 call eax
007D1644 mov dword ptr [ebx+0x1a030],0

007D1692 cmp dword ptr [ebx+0x26048],edi
007D16A0 mov ecx,[ebx+edi*4+0x24048]
007D16A9 mov edx,[eax+0x0c]
007D16AC push 0x12
007D16AE push esi
007D16AF call edx
007D16BF mov dword ptr [ebx+0x26048],0

007D16F8 mov edx,0x13
007D16FD lea eax,[ebx+0x2604c]
007D170B cmp edx,0x16
007D1720 mov ecx,[eax+edi*4]
007D1725 push edx
007D1726 mov edx,[eax+0x0c]
007D1729 push esi
007D172A call edx
007D173D mov dword ptr [eax+0x2000],0
007D1747 inc edx
007D1748 add eax,0x2004
007D1755 cmp edx,0x16
007D1769 add ebx,0x2000
007D176F mov eax,0x16
007D1780 mov dword ptr [ebx],0
007D1786 add ebx,0x2004
007D178C dec eax
007D178D jne 0x7d1780
```

## 偏移/桶索引核算
`12×0x2004=0x18030`，count=0x1A030。 `18×0x2004=0x24048`，count=0x26048。由 `0x2604C` 起，stage 19/20/21 逐桶 dispatch，且 count 每桶清零（條件 `edx < 0x16`）。最後 `EBX+=0x2000`，依序為 22 桶 `[EBX + i×0x2004 + 0x2000]=0`，並非全面清理 entries pointer slots。

**重要更正**：大迴圈之末的 22 次 count reset 確實是 BIN 所證；但它 reset 的是 `[EBP+8]` 所提供的 owner instance，不能僅據布局將此描述成 **全域 [0x00FB7740] 週期清零**。

```cpp
struct Bucket { void* entries[2048]; int count; };
void callbackSlot0C(BucketOwner* owner, ...){
  // selected stages 1,2,4,12,15,18,19,20,21 dispatch entries->virtual0C
  // other stages and interface call sequences omitted
  for (int i=0;i<22;i++) owner->buckets[i].count=0;
}
```

## 仍需驗證
1. 真實呼叫 callback slot +0x0C 的 dispatcher 與輸入的 owner 值。
2. 為何某些 stage 需要 extra graphics-interface operations；是否 stage 與 rendering/material subsystem 有關。
3. 外部 runtime owner 是否等於全域桶配置（不能用 stride 一致取代 proof）。
4. 在循環期間 callback 可能改變 count 的併發/重入問題未檢查；不可聲稱 thread-safe。

**T08-128** 對可證實 owner 指標、方法 ABI、目前證據死角提出可實作的下一步。