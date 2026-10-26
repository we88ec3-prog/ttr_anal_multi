# KR T07：兩村切換場景介面交接

狀態：待接手／待原生語意驗收。使用者已指定「交給其他對話處理 T07」；T06／roy不認領T07核心，也未建立新對話或傳送跨對話訊息。此頁是共用Markdown交接，不是原生結論。

目標：支援馮德斯村與爾斯梅勒村切換，優先封包／伺服器資料恢復。原始證據唯讀、不執行或附加遊戲、不呼叫目標API。

基準BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。

## 下一個直接查證點

1. 先查方法歸屬並在T07登記，再從已保存的4B9090（0069歷史handler候選）與4BBB70開始；核對註冊路由、真正RTTI場景類與後續初始化，不能信scene7註解。
2. 核對場景安裝4B7D50、0012/4B24F0 reset與0014/4C5930 ready的必要先後與當前場景條件。005F與0069是不同訊息，type7不可互換。
3. 列出切城時保留／清除的actor與controller狀態，與T08玩家控制綁定、T04初值、T09bounds介面分開。不要把廣場／教學fixture順序直接當官方序列。

## 已有原生擷取可直接選讀

大量反編譯已完成且關閉，請勿重啟全量工作。以下pseudo僅衍生視圖，raw Evidence優先，語意仍未驗收。

- `0x4b9090`：[raw](../kr-bulk-roy/9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91/raw/20261025T182755495890-batch-20261025T184322715638-3200.json)，SHA256 `ff70ce95dcd7c30ad53ca5d8f80898d05eeac32043ed0e4521aad1fc81fa1fbd`；[pseudo](../kr-bulk-roy/9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91/functions/0x4b9090.c)，SHA256 `d31cab226005d9f6a81e85cf825638b4182f8ce16283b1c91c0262e534fde299`。
- `0x4bbb70`：[raw](../kr-bulk-roy/9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91/raw/20261025T182755495890-batch-20261025T184324205567-3232.json)，SHA256 `01290063a1d656c7a962c57fed16b94491a966bae921230a73d7ac3d72da5ea1`；[pseudo](../kr-bulk-roy/9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91/functions/0x4bbb70.c)，SHA256 `2562b976db6a528c0d82851865e11b6ccc4dee1a6b7d0a9246fb42907aceec12`。

既有場景/reset/ready報告：[正式保存版本](../kr/evidence/0bab714e82d96b0f6a4165471fc52531ba4b250f63878e2721bdd706fb8bab37.txt)。其Scenario分支ready證據不自動適用town。

## T06已交付與邊界

- MapList182→town001D/BOUNDtown001、183→town002D/BOUNDtown002有資源證據；正常Town1/2配對仍未直接證實。
- [封包契約](../kr-temp-roy/T06/PACKET-RESTORATION-CONTRACT.md)及[跨任務介面](../kr-temp-roy/T06/PACKET-DEPENDENCY-HANDOFF-v2.md)均有逐項限制。
- 原生4DF510相同Map selector局部路徑會跳過顯式模型／BOUND載入callsite，不能把重送0012當必然重載；[已整合來源](../kr-temp-roy/T06/evidence/map-repeat-branch-v1.json)。
- 兩村37/39快取名稱都有完整FCS→archive候選路徑；只是候選存在，不代表mount／實際載入／spawn完成。
- 目前工作副本為Tartaros.ip-zh-tw-only-v2.exe，SHA256 `6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`。v1有PE區段空洞，已以header-only修正；v2僅通過Windows不執行image驗證，未取得實際啟動結果。
- 切城以前的登入／角色／背包卡關，使用者指定由該部分對話續查；不要把本次乾淨client缺舊guard後的問題混進town語意。

## T07交付驗收

每項結論附同SHA原生來源、位址／範圍、工具版本、原始bytes與控制流程限制；區分觀察／推論／後端重建政策。交付明確的場景選擇、安裝、reset、ready局部契約及仍缺資料，不要求猜官方完整序列。新成果先留接手者個人暫存區，通過原任務驗收才整合；與T06以介面引用連結，不重定義地圖資源lookup。

更新：2026-10-26T00:28:50.278404+00:00
