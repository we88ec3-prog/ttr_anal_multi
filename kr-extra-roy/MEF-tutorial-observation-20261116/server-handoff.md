# R14 Server／內容開發交接：玩家觸發後由腳本接續

承接 REQ-0019／REQ-0021 既有脈絡，供 S00 去重整合；不另建正式需求或修改台帳。完整原件見 [主報告](../20261116-191747-chatgpt-web-roy1-MEF-tutorial-observation.md)。

## 可交付功能

在已證 Tutorial context，內容可建立原表提示點，讓玩家進入範圍或按映射互動動作後，由 Client 寫 progress，Lua 觀察同一 key 並接續對話／演出。這是原版 TutorialMain 已有用法。Server 保留場景、服務、共享狀態、任務及資產權威，不以全面移交普通戰鬥為驗收前提。

## Server 開發需求與內容整合要求

| 工作 | 負責範圍及具體要求 | 原件限制／驗收 |
|---|---|---|
| 內容版本與依賴 | Server／發布工具保存 build、hash、Tutorial table、effect、scene與實際loader所選檔案 | 不能只有檔案落地；不是新 MEF 傳檔 opcode |
| 合法執行環境 | Server流程與Client內容對齊現有教學controller、page、角色與原生入口 | 32格progress只在相符controller下有意義；不是任意世界事件API |
| 控制索引分配 | 內容工具檢查 key、category、progress index、Q slot、world ID 各自型別；不得碰撞現有0/10用途 | index10是掃描gate，0供Part1中止控制；沒有bounds保護不能當自由擴充能力 |
| 一次性提示內容 | 選已存在表列，使用其mode/效果，首次建立前明確設定本次progress | 成功Insert不清舊progress；無可靠Lua成功ACK；避免重複(category,key) |
| 重用／再入 | 內容及Server明定重新啟用、離開再入、完整point重建與progress清理順序 | 0027只重建point，0048只改enabled；兩者不自動清控制器progress；沒有已證遠端任意clear API |
| 輸入設定 | 保留原鍵位選型及動作13；正常流程以「新按下」測試mode0 | 長按state2不是state1，原表type0 Key44/type1 Key36；不可硬寫全部情境固定Z |
| 位置與同時提示 | 使用有來源座標／半徑，避免多個活躍自動範圍重疊；配置時檢查分派gate | latch更新先於選winner，沒有證明落選事件排隊；半徑邊界採嚴格小於 |
| 結果與持久化 | Server保存權威教學／任務進度、商店條件、轉場與獎勵；關聯既有回報和session | local progress=1只代表已證本地條件，不等於獎勵資格；此分支沒有新增結果封包 |
| 能力紀錄 | 記所選內容、點key、mode、controller、實際映射、開始／取消／結束與Server續接 | 沒有證據可取得的Client欄位應記未觀察，不幻想Server收到local flag或run token |

## 正常流程驗收定義（本輪未執行）

合法 Tutorial entry 與角色/context → 開啟既有掃描gate → 唯一合法提示點 → 玩家到達；mode0再新按互動動作 → 控制器對應progress變1 → 原Lua同key讀取 → 關提示點 → 下一段演出 → 既有收尾／回覆 → Server權威進度一致。

先驗一條有來源的正常路徑。重疊範圍、舊progress、停用／再啟用、重建集合、取消及斷線，只列為後續驗收契約，遵守專案現行測試排程，不在本輪擅自啟動遊戲或壓測。

鍵盤／滑鼠教學的已核完成條件只看對應抵達旗標，未檢驗移動來源；不能把畫面標題當「玩家確實用了某種裝置」的證據。若產品需求要求嚴格辨識，屬新增需求，須另找合法觀察接口，不改寫原版已證語義。

## 分開維持的狀態

**已證Client能力：**此Tutorial提示點→進度旗標→Lua等待→下一段演出鏈。**Server待開發：**發布、相容流程、權威結果與保存。**跨功能待整合：**新內容、owner、重用及回報對帳。**Client待逆向：**官方MEF首次入口／grammar、超出本Tutorial上下文的實際需要接口。**待遊玩驗證：**畫面、輸入、事件時序與雙端一致性。靜態PASS不提升任何正式狀態。
