# T10-088 — 輸入 producer／動作 consumer 缺口審核與可驗證接續矩陣

**證據版本**：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪 `sha256sum` 核對）；`.text` VA `0x401000`，raw `0x400`；`objdump -D -Mintel` 直接對 PE32 `.text` 反組譯。檔案靜態唯讀。

## 整體結果與嚴格驗收

* 已確認：KR `KeyMapping.xml` Type0 `MapButton=13..16` 對 `Key=44..47`；type1 MapButton 13..16 另指向 Key36..39。映射 ID ≠ action opcode。
* 已確認：bank0/1 的 0x280-byte 欄位可複製至 bank2；外部設定也可逐 slot 回填 bank2（T10-083）。但不能證明玩家現用的配置模式／Type1 Key45 fallback。
* 已確認：phase reader 普通 0..39 使用 `0xFB9004+ID`，特殊 10001..19999 的查詢使用 `0xFDF630` 節點，`0x6D4A30` 可對兩類執行清零。
* 已確認：phase1/3 進入 `0x5961C0` 的多態 slot；`0xFB73E8` 非零情況在該函式限制輸入 ID 13/14；`0x5A46xx` 使用同一全域旗標控制 `[esi+0x154]` 變化並以 `0x5A55E0` 進入 mode 1/2。
* 未確認：本機輸入 producer 是否採 DirectInput DIK 掃描碼及其翻譯機制、phase=1/3 的任何**非零** writer、vtable `+0xEC/+0xF0` 所屬 class／具體虛擬覆寫、動作 motion consumer、Z 持按與連擊／V tap-hold／queue/cancel 規則與時窗。這些不能以 AI `CHAIN_WINDOW=.65` 或 `>500ms` 假設填補。

## 對下一段 T10-089 的精確實驗路線

1. 以 `0x490DFC`、`0x58A607` 追 `0x6D4A30` 的事件容器參數，定位究竟是「設備輪詢→事件節點」或清除出口，查 node 的構造和非零 writer。
2. 以 `[0xFB73E8]` 真實物件所屬 `0xFB73C0` 及其鄰接容器追 alias writer；絕對位址 xref 已僅見初始化清零 `0x560239`，其他常數讀取不代表缺少 runtime 修改。
3. 從 `0x5961C0` dispatch target 追虛擬表具體指標與 override，避免將 vtable **byte offsets** 與 object member offset 混同；只有證實實例來源後才能跨 T08/T09/T11 引用。
4. 抽樣檢查 `0x5CD68A`/`0x5CE5BA`/`0x62B5BA`/`0x650E96` 的 `0x6D4DC0` 返回值用途，標註 UI 配置消費者與真正 runtime 消費者。
5. 需在實際原始證據確認 writer、motion、連段／取消分支，才能把任何 T10 功能列 native_complete；現在只屬 bounded native review。

## 額外 BIN xref 片段

### VA 0x00490DE0..0x00490E15

[code block separately checked in preflight]

### VA 0x0058A5ED..0x0058A620

[code block separately checked in preflight]

### VA 0x005A4614..0x005A4671

[code block separately checked in preflight]

## 證據分級與研究限制

- 「已確認」僅指列出的 BIN 字節與控制流；對象／業務語義若沒有 vtable 及 producer 證據一律維持「部分確認」或「尚待驗證」。
- 未執行、修改客戶端，未引入任何原始遊戲資源至 GitHub；沒有擅自修改其他 Task 的 owner、catalog 或筆記。
- 此筆記為 T10 專項研究完整原稿，包含可複查的 VA 原始指令及限制，不將反編譯和 AI 替代當原生依據。