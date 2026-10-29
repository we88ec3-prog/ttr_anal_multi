# T10-62 — `0x6D4A30` 雙模式清理與資源 gate

- 研究時間：2026-10-28T02:22:16+08:00（Asia/Taipei）
- 研究對象：KR `Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 原始 PE：`.text` VA `0x401000`，raw `0x400`；本檔 VA 與 raw 使用 `raw=VA−0x400C00`（限 `.text`）
- 版本／方法：x86 objdump 從本機原始 BIN 離線只讀重解碼；已有 T10-1～60、T01整合為歷史線索而非本批 native 證明
- 主責限制：T10 普攻、輸入與連段；T11技能裁決、T12傷害公式僅引用；未執行/附加客戶端
- 本段是否完整還原原生功能：**否**。局部組合與資料流保留未閉合點。

## 摘要：可由本次原始 BIN 核對的有限事實

`0x6D4A5B` 依 `[ebp+8]` 的低 byte 導向兩支流程。第一支透過 `0xFB7C14` 與 `0xFDF3EC` gate 決定呼叫 `0x6D0750` 或 `0x6D1DA0`；然後於 `0x6D4A9C..0x6D4AC9` 清除 0xFB9004..0xFB9028 的 DWORD。另一支先檢查 `0xFB8830`，在條件成立時於 `0x6D4B6B..0x6D4B98` 清相同區域，並且對 `0xFDF630` 走 `0x823850`。可見 reset 與特殊鍵樹資源處理存在控制相依，尚不能把布林選擇器命名為按下或放開。

## 第一手 x86 證據

### VA `0x006D4A30` ～ `0x006D4AFB`／raw start `0x002D3E30`

[code block separately checked in preflight]

### VA `0x006D4B0A` ～ `0x006D4C1A`／raw start `0x002D3F0A`

[code block separately checked in preflight]

## 直接 caller 檢索（僅 E8 near call，不含虛擬／間接）

- `0x6D4A30` 的 .text 直接 `call` 候選 `2` 處：`0x490DFC`, `0x58A607`
- `0x6D4CE0` 的 .text 直接 `call` 候選 `2` 處：`0x59624E`, `0x59643F`
- `0x6D4DC0` 的 .text 直接 `call` 候選 `29` 處：`0x594672`, `0x5946CB`, `0x59471B`, `0x5947FD`, `0x59484D`, `0x59492F`, `0x59497F`, `0x594CD4`, `0x594DC4`, `0x594EB4`, `0x594FA4`, `0x595094`, `0x595184`, `0x595274`, `0x595364`, `0x595454`, `0x595544`, `0x595634`, `0x595724`, `0x595814`, `0x595901`, `0x5959F4`, `0x5CD68A`, `0x5CE5BA`, `0x62B5BA` …

## 可檢驗偽碼（只描述局部控制流）

[code block separately checked in preflight]

## 證據分級與反證邊界

- **已確認（局部）**：上列 x86 指令及已列明直接控制分支與資料讀寫；逐段原始 bytes 已由 hash 符合的 BIN 反組譯。
- **部分確認**：來源索引／回傳 byte 與多態 callback 存在聯繫；型別、物件生命週期及上游來源尚未封閉。
- **僅合理假設**：此資料可能參與玩家可自訂鍵位及攻擊輸入；缺完整 player receiver 身分與事件來源證據。
- **尚待驗證**：非零 phase writer、V tap/held、Z press/hold、普攻／技能隊列、動畫完成／取消、client-server authority。
- **明確排除推論**：`0x547240` 的 `>500ms` 不是原版連段窗口；SubAI >60 次不是 V held 秒數；`CHAIN_WINDOW=0.65` 為 AI 替代；命令索引數不等普攻段數。

## 可接續工作

後續應追上游 `call 0x6D4A30` 的實參來源及兩路 mode 的進入時機，並確定 `0x823850` 是否只清 tree、還有其他持有者。應避免「兩個模式 = V tap/hold」的跳躍。

## 與歷史原稿的關係

- 以 T10-45～60（原始 `kr-temp-roy/`）作交叉參考；這份是本輪**新補定向 BIN 原始證據與條件細分**，不是宣布舊報告全函式獲正式接受。
- 未改動 owner/catalog、T11/T12 或其他研究者產物。須由 T01 後續整合者另行審核才可提正式 claim。