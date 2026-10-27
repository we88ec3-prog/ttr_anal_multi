# T08-148 — B entry 實際型別識別與 22 桶因果鏈的最小閉合方案

**Task**: T08 | **來源**: `Tartaros.bin`（12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪實測）

**方法**：`.text` 在此 BIN 以 `offset=VA-0x401000` 讀取；`.rdata` 使用 PE 節區映射 `offset=VA-0x00BD2000+0x007D0600`，以 T08-125 已驗證 `0x00C4FF8C` 的 callback vtable 為交叉檢查。`objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000 Tartaros.bin`。只作靜態研究，未執行除錯器。

**分級**：[確認] 指令或資料本身；[候選] 多項偏移結構相合但尚缺函式身分證據；[未知] 動態類別 / 實際方法身分。

## 1. 已確認主幹（接續 T08-129、141、144）

```text
ECX Host → 0x007A67C0 (guards)
  → 0x007A69E5: Host+0x0C
  → 0x007A6A2E / 0x007A6A4F store pointer
  → 0x007A6A51 global B.end += 4
  → consumer 0x007BB640
  → 0x007BBC70 entry.vptr+0x08(score)
  → 0x007BB6F9 entry.vptr+0x04(execute)
  → clear B.end = B.begin

Sequential but independently dispatched:
0x0079A320 → 0x007BB640 → callback 0x007D1310(global 22-bucket consumer)
```

## 2. 本輪新增但尚未閉合的 Host 候選

`0x007A5050` 在 object+0x0C 寫入 `0x00C4F66C`→`0x00C4F6C0`；`0x007A5A51` 在析構段回寫 `0x00C4F66C`。相關 Host 欄位偏移 +0x1C/+0x70/+0x8C/+0xAC/+0x124 也與 producer 相符，構成高優先候選，**尚未驗證 producer 呼叫時之 ECX 即為此物件**。

## 3. 缺失的必要因果邊

- B entry vptr 的實際值 `[Host+0x0C]`：尚缺動態讀值或完整構造→producer 身分鏈。
- `[entry.vptr+4]` 與 `[entry.vptr+8]` 的真實目標：尚缺經具體物件證明的 vtable 定址與 ABI 核對。
- execute 時是否寫入全域 22 桶 count：尚缺直呼/間呼路徑或時間序列。

## 4. 動態驗證最小方案（未執行）

1. `0x007A69E5` 記 `EDI`（加 0x0C 前的 Host）及 `[EDI+0x0C]`。
2. `0x007A6A51` 記 `[0x00FBA838]`、`B.begin/end/cap`、新增 entry pointer。
3. `0x007BB6F6` 記 `ECX=entry`、`[entry]`、`[[entry]+4]`、`[[entry]+8]`；逐一確認是否等於候選 vfptr。
4. `0x007BB6FE` 的間接呼叫前後，記全域 `[0x00FB7740]` 與 22 個 count 的變化；區分原有 producer 與此 entry execute 造成的變化。
5. `0x007D1310` 記 owner 與全域槽相等、回傳前的清桶路徑。

## 5. 建議下一段 T08-149

追 `0x007A5050` constructor 的上游配置 / 虛擬表註冊和 `0x007A67C0` caller 間的物件身分鏈。先做具體入口對照，避免只用大量固定 offset xref 湊結論。若有可重現的遊戲 runtime 再執行動態觀測；在沒有執行前不得聲稱 B execute 生成 22 桶。

## 6. 原始 bytes 支持索引

- `0x007A507F/0x007A508D/0x007A50B9`：constructor vfptr stores。
- `0x007A5A51`：destructor vfptr restore。
- `0x007A69E5/0x007A6A51`：B append producer。
- `0x007BB6F9/0x007BBC7D`：execute / score dispatch。
- `.rdata` 讀取需用 PE 節區 raw 映射，而非 BIN 文字區線性映射。
