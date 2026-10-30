# T10-087 — MapButton phase 派送與介面虛擬方法：未閉合的 controller 邊界

**證據版本**：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪 `sha256sum` 核對）；`.text` VA `0x401000`，raw `0x400`；`objdump -D -Mintel` 直接對 PE32 `.text` 反組譯。檔案靜態唯讀。

## 新結論

1. `0x5961C0` 逐 ID 查詢 `0x6D4CE0`，ID 0..39 包含 13..16；局部 `edi` 為 ID，`esi=edi` 為非標準 ABI reader 參數。phase 1 分派物件 vtable `+0xEC`；phase 3 分派 `+0xF0`，且具物件與 this 的 fallback 路線。
2. `0x59623B` 的 `[0xFB73E8]` 非零條件只在這段 loop 排除不是 13/14 的 ID，並非全域停用 15/16。與 T10-086 中模式切換路徑互相交叉，但沒有具體虛擬槽位的 owning class/vtable address 時不可稱 AttackPress/Release。
3. `0x6D4DC0` 直接 caller 並非僅 UI：原始 `.text` 靜態 callsite 包含 `0x594672..0x5959F4`、`0x5CD68A`、`0x5CE5BA`、`0x62B5BA`、`0x650E96..0x6510A4`。其中 T10-082 已確認 `0x594610` 內的多個 caller 導向 UI 組裝；其他 caller 尚須逐個讀取其返回值用途。**配置查詢不能等同 phase reader，更不能直接當 motion writer**。
4. 目前確認兩個不同介面：(a) 配置 bank→`0x6D4DC0` 得鍵碼清單；(b) 狀態 byte→`0x6D4CE0`→`0x5961C0` 多態處理。兩介面在 scan-code→phase writer 尚未建立直接機器碼因果。

## BIN 直接片段

### VA 0x005961ED..0x005962E0

[code block separately checked in preflight]

### VA 0x00594650..0x00594690

[code block separately checked in preflight]

### VA 0x005CD670..0x005CD6A0

[code block separately checked in preflight]

## 證據分級與研究限制

- 「已確認」僅指列出的 BIN 字節與控制流；對象／業務語義若沒有 vtable 及 producer 證據一律維持「部分確認」或「尚待驗證」。
- 未執行、修改客戶端，未引入任何原始遊戲資源至 GitHub；沒有擅自修改其他 Task 的 owner、catalog 或筆記。
- 此筆記為 T10 專項研究完整原稿，包含可複查的 VA 原始指令及限制，不將反編譯和 AI 替代當原生依據。