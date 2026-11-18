# 本輪讀取範圍與停止條件

## 已完成的明確問題

- 讀固定基線的既有 MEF 功能完成追蹤與當前 Server 關卡、WaveCleared、WaveHealthReached、巡邏規格，保留實作／人測／待驗差異。
- 沿 lb 本地 CMonster 的同一 world owner，核 frame → world tree → typed v+20 → 位置步進／gate／writer，以及 v+24 → state 更新。
- 核普通技能 000D → state13／motion 及真正 CSkillState entry/update，區分技能表現與命中/HP/死亡。
- 重核 selected Single/Tutorial attach 與 SubAI model > 9 排除，沒有重做全體 T10/T13 決策來源。
- 原件重核前稿 8 個生成、輸入、HP、死亡、移除範圍；復用其既有完整語意鏈。
- 將既有普通 Lua observer 排除結果轉成適配器的必要資料契約；沒有重新生成 bindings/call-sink census。

## 必要新搜尋的精確範圍

只對 PE .text 的每個 byte 檢查 E8/E9 rel32 指向 4C8A90 或 4E0060；候選再用完整函式入口解碼確認。這不涵蓋間接呼叫、alias、其他模組或動態腳本。native-evidence 記錄候選與排除界線。

bulk C 只供入口/資料流導航，語意以原 BIN 與固定既有原件報告為依據。source-manifest 列出實際使用的不可變來源。查無的大寫路徑/個別未拆分 thunk 不是功能不存在證據；4D1AE0 由 vtable 與原件 tail jump 證實。

## 停止條件已到達

本題已能回答哪些規則屬 MEF、哪些 Client 可執行、哪個 Server 基礎已有、具體缺哪個輸入/輸出、怎樣驗收實際減負。普通 Lua handle/HP/death 的新 adapter 需開發；沒有新 producer/binding 候選時，不重跑舊 121 names、20+4 Lua sinks 或原檔清冊。不以無官方 MEF 或形式 owner 代替這個技術結論。

未執行 Client、Server、Lua 或依賴 DLL；未修改正式 Task/RR/owner；未發送任何封包或新增 branch。原件只有讀取，沒有公開完整原件/member。
