# T08-128 — owner 身分驗證邊界、靜態證據總結與下一段方案

研究者：chatgpt-web roy｜2026-10-27 Asia/Taipei。來源：本機 `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪使用 sha256sum 重新計算一致）；機器碼由已存在 `t08_current_disasm.txt` 及原始 PE 的 x86 objdump 核對。GitHub 已完成 T08-124；本輪研究自125接續。

**證據約定**：已確認＝BIN 可重現；推測＝語義未獲符號/實際呼叫驗證；未知＝仍無直接證據。相同欄位偏移不可跨 C++ 物件型別混用。這是按研究主題完整保留的分段原稿，不將負向搜尋冒充不存在證明。

## 本輪關鍵鏈與尚未閉合處
1. `[0x00FB7740]` 全域 22 桶：22×0x2004，配置/釋放明確；15個 immediate xrefs 目前都是初始化、釋放或 producer。固定第10桶插入在 `0x007FECE9`。
2. `0x0079A3C0` 的某些呼叫路徑透過 manager handle 地址 `0x00FB76A8`，對 `[ECX+0x98]` 指向全域 `[0x00FB7740]`，因此該路徑確實是全域 **producer**，不是 consumer。
3. `0x00C4FF8C+0x04` 目標 `0x005F5D10` = 單指令 `ret`；`0x00799B6E` 不是桶 consumer 路徑。
4. `0x00C4FF8C+0x0C` 目標 `0x007D1310`：第一個 stack 參數 `[EBP+8]` -> EBX 作 22 桶結構 base。多個 stage 的 entry 虛槽 +0x0C 派送已確認，並有 **22個 count 都清零**的最終迴圈（`0x007D1769～0x007D178D`）。
5. 最後一段中的 owner 身分目前仍**未知**；若實際 dispatcher 的 owner == `[0x00FB7740]`，這可以證明 global consumer；但該必要前提尚未確認。

## 已知 call/alias 結構
```text
[0x00FB7740] -> heap[22 * 0x2004]
  xrefs: alloc/free & many object enqueue
  007D35F7 (ecx=0x00FB76A8) -> 0079A3C0 reads [ecx+0x98] -> global bucket producer

callback 4-byte instance at handle+0xA0
  vptr 0x00C4FF8C
  slot+04 -> 005F5D10 (ret)
  slot+0C -> 007D1310
                 EBX=[EBP+8] (EXTERNAL bucket base, unproven global identity)
                 per-entry virtual0C
                 counts reset for all 22 buckets

other independent path:
  00492567 / 007BA56E -> 00799D20 -> 00838430
  ESI=[0x00FB76B0]; 24 float stores
  (plane content writer resolved in T08-118; do not reopen)
```

## 虛擬呼叫與 ABI 仍待推進
`0x007D1310` 以 `ret 4` 結束，表示本 slot body 回收一個 4-byte stack argument。要定位此函式的真的外部 caller，應搜尋以該 callback object 參數派送 vtable+0x0C 且恰好傳遞 bucket owner pointer 的路徑，不要把不同 entry 的 virtual+0x0C 誤當 slot callback 的 caller。全域指標 alias 需要追蹤實際來源而不只是 opcode offset。

```cpp
// only evidence-supported shape:
using BucketCallbackSlot0C = void(__thiscall*)(Callback* cb, BucketOwner* owner);
void maybeConsumer(Callback* cb, BucketOwner* owner) {
  for (int i=0;i<22;i++) {
    // selected stage virtual dispatch
    owner->buckets[i].count=0;
  }
}
// must prove: owner == *(BucketOwner**)0x00FB7740
```

## 可執行的 T08-129 探測計畫
- **靜態（優先）**：由 `0x00799840` callback 的 `manager+0xA0` 寫入點、`0x007997A0` 初始化與管理器 `0x839940` vtable 查外部註冊／分派者；對每一候選從 `mov reg,[callback]`、`mov reg,[vtable+0xc]` 往上追 `push owner`。
- **動態（條件允許）**：在 `0x007D1310` 設執行斷點，記錄 return address、ECX(this)、`[ESP+4]` owner argument、`[0x00FB7740]`；比較後再於 `0x007D1780` 設 watchpoint/執行斷點核實 count 清零。尚未進行此動態步驟，不得宣稱觀察到實際運行結果。
- **驗證**：在非關閉流程時比較 bucket count 清零是否受 callback 調度控制；不可僅因 `0x007995BA` 把 pointer 歸零就當作 drain。
- **跨 Task**：本批未改動其他 Agent 文件。GitHub 只可提交這四份原稿；長期知識庫的 T08-118 writer 結論如未更新需另行提醒，不在本段自動改寫。

## 結論與狀態
T08-125～128 已完成可獨立回溯的 BIN 靜態分段研究；**尚未找出真正全域 22 桶 consumer 的完整證據鏈**。下一段 T08-129 以 callback dispatcher 實參恢復為優先。