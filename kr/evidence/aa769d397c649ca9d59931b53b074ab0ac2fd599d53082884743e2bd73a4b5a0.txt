# KR T03 角色UI更新／事件消費介面 — 待整合

來源Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。REA6.5.0/Ghidra12.1.4，profile 3c06738e45e144d5f073edbd3244c6bff46222f389525fe659bc92dca2ccdece。Evidence：rea-roster-ui-update-caller-5a67d0.json，ev_4c3cb63dbf87932b7de00f55ec74da6d760fe6218a7da275c15f1ca075730aa7；原始檔SHA 7b7de540d1c8776140b284b047d36867c1a81b39f4f02c697dd968124e88ccf0。body為[5A67D0,5A6986] inclusive。

## 已觀察與獨立核對

5A67D0讀event+10。原檔switch的selector table在5A69A0，jump table在5A6988；事件範圍從F4245開始，以下對應已用原檔位元組與Capstone獨立核對，不只依賴偽碼case標籤。完整位元組、file offsets與table SHA在roster-ui-update-byte-verification.json；此function的def-use輸出未截斷，仍不代表整個UI語意已完成。

| 事件 | 觀察到的分支 | 成立條件／限制 |
|---|---|---|
| F4246 | 取得40AFC0返回物件的+14值作ECX，receiver+138所指dialog作stack argument呼叫672F00；之後呼叫該dialog virtual+D0 | +14的原始狀態來源未在本項重新定義；virtual方法的人類UI名稱不由offset猜測。 |
| F4247 | receiver+138 dialog的virtual+D4 | 與已查673DA0於event387產生F4247接上局部producer/consumer；尚未驗證event訂閱／實際投遞。 |
| F4278 | 40AFC0返回物件+14為0時，以ECX=0與receiver+138 dialog呼叫672F00；之後對receiver+13C物件呼叫virtual+D4並走訊息路徑 | 672F00的0輸入沿用dialog+D8，已有先前原生依據；本分支不是清單到達後無條件刷新。 |
| F4245 | 呼叫672570等其他UI分支 | 本項只保留定位，沒有重新定義其他dialog業務。 |
| F4248 | 呼叫5A64B0 | 初始化／其他業務僅作後續定位，不藉此展開其他任務。 |

## 推論界線

已能描述兩種UI更新入口的參數與狀態條件，並定位F4247的局部消費者。合併先前command2→53-byte記錄→+5C寫入與672F00讀取條件，可建立資料及更新入口的介面規格；仍不能斷言command2直接產生F4246/F4278，或收到封包必定立即更新畫面。

F42EF不在這個switch列出的處理範圍；這只排除此單一函式，不能宣稱事件無消費者。它的業務路由與F4246/F4278來源仍待查。資源存在、dialog建立與訂閱、目前選取值的設定、完整bootstrap及轉場時序仍是缺口。T05保留實際場景前置／世界轉場，T06保留資源標籤／存在性；不得自行解除gate或補猜回應。

## 後續開發影響

相容層仍應先完成正確清單與初始化回覆，不能以修改旗標或注入UI事件冒充原流程。LocalHero、固定初值、預設名單與42配對43/69仍保留AI替代標記。此結果縮小「完全不知道如何刷新UI」的缺口，但沒有完成T03可玩驗收。

本次結果在工具閒置關閉前已保存；roster session33920於idle_deadline_close後正常close，已觀察exit0。未為審閱已保存結果重啟引擎。
