# T10-086 — 全域狀態 0xFB73E8 與角色切換路徑的控制流

**證據版本**：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪 `sha256sum` 核對）；`.text` VA `0x401000`，raw `0x400`；`objdump -D -Mintel` 直接對 PE32 `.text` 反組譯。檔案靜態唯讀。

## 新結論

1. `[0xFB73E8]` 的直接絕對寫入參考在全 `.text` 掃描中僅定位 `0x560239: mov [0xFB73E8],ebx`，而前段 `0x560197 xor ebx,ebx`：確定這一條是**初始化清零**。不代表不存在由基址／別名／間接指標寫非零的路徑。
2. `0x5A4614` 在主物件 `[esi+0x15c]==0` 的前提下讀全域 `[0xFB73E8]`，將布林結果放入 `bl`，與 `[esi+0x154]` 舊值比較。若轉為非零，`0x5A462B push 2; call 0x5A55E0`，之後 `0x5A5760`、`0x5A57A0`；若轉為零則 `push 1; call 0x5A55E0`。最後 `0x5A466B` 將新 bool 寫入 `[esi+0x154]`。
3. `0x5A55E0` 不只是單純動畫 setter：存入 `[esi+0x158]` 新 mode、`[esi+0x15c]` 旗標，再針對 mode 1/2 操作 `[esi+0x140]`、`[esi+0x148]` 所指物件之 vtable `+0xD0/+0xD4`，設定或清除 `[object+0x28] & 0x80000` 並引入其他資源邏輯。此路徑屬**模式／子物件狀態切換**，目前未證明是普通攻擊、連段或取消。
4. `[0xFB73E8]` 既在 `0x5961C0` 限定 ID 13/14 的 dispatch，又在 `0x5A46xx` 觸發模式切換，構成跨路徑證據；但旗標的語義、權威寫入者仍未證實，必須保留不同 class/instance 區隔。

## 直接引用清單

### VA 0x00560197..0x00560274

[code block separately checked in preflight]

### VA 0x005A45DB..0x005A4671

[code block separately checked in preflight]

### VA 0x005A5605..0x005A5745

[code block separately checked in preflight]

## 證據分級與研究限制

- 「已確認」僅指列出的 BIN 字節與控制流；對象／業務語義若沒有 vtable 及 producer 證據一律維持「部分確認」或「尚待驗證」。
- 未執行、修改客戶端，未引入任何原始遊戲資源至 GitHub；沒有擅自修改其他 Task 的 owner、catalog 或筆記。
- 此筆記為 T10 專項研究完整原稿，包含可複查的 VA 原始指令及限制，不將反編譯和 AI 替代當原生依據。