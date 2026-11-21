# 完整 MEF 副本 TCP 正流程

2026-11-22。沿用已發布 Case693 整合與投射物配套、原版BND及同一操作驅動。
目標補齊登入／primary handoff、廣場建隊、正常進村／選關、戰鬥、機關、分支、
結算與回村的真正loopback TCP證據。這不代替指定v2 Client的畫面驗收。

## 約束

- 一次性SQLite帳號已準備教學／Q15、角色4 Lv15；準備期間的本機lease先釋放，
  然後走正常KR帳密登入及primary交接。這是第一次TCP登入，不跑重登／重送測試，
  也不聲稱本批從全新帳號升級到Lv15。
- 所有遊戲意圖使用既有E1b C2S writer經socket送入正式gateway。所有遊戲回覆及
  定時更新都從socket讀取；不直接呼叫connection.Handle/Poll或本機獎勵提交。
- 既有0010／0019查詢僅用來界定有序回覆讀取，不當作Client畫面完成ACK。
- world及gateway排程可注入測試TimeProvider；預設仍為系統時計／100ms間隔。
  測試每步world最多推進100ms，再推進排程100ms；等待gateway實際完成poll與
  輸出，才讀取socket。完成poll的計數只是程序觀測，不是新遊戲協定。
- 純讀取SQL與診斷可比對目前lease、角色經驗、條件旗標及帳本，不用診斷跳關。
  各route維持獨立帳號、資料庫與loopback連接埠，不替換現有Host/Admin。
- 每一條分支核對同村同隊返回、88EXP保存、入口消耗1個Product183、頭目存活時
  的階段增援，以及選用視覺配套的每個0094／001A生命期。

此為 OFFLINE_SYNTHETIC + LOOPBACK_TCP 的正常流程，Server-owned NOT_NATIVE_MEF。
原生MEF容器、Client效果／速度及非正流程測試維持各自待驗。

## 已完成路線

兩條分支都已通過。節點5路線為1960步／1960次實際gateway poll、3706個送出請求、
6319個收到的封包；節點6路線為2084步／2084次poll、4278個請求、7276個封包。
兩路均保存88EXP、消耗1個Product183、頭目存活時增援、建立／清除5枚方向子彈，
最後正常結算返回同村原隊伍。舊應用層兩路亦保持通過。

這使用檢查器程序內的正式Server元件及真正socket，沒有宣稱另啟的部署Host或
原版Client已走完。時計是受控制的合成時計，不是效能測量或Client完成確認。
實際帳號／角色進度由Server handler提交，SQL與診斷只作觀察。

私有工具 `tools/check-mef-integrated-dungeon.py --projectile-visuals --tcp` 會核對
完整配套、兩路徑、機關、頭目階段、子彈生命期、gateway計數與回村保存。
參數仍需 `--analysis-directory`、`--bounds`、`--output`。

最初沿用離線帳號stage1_walk，觸發既有handoff顯示名最多9個ASCII字元限制，
在AUTHACCEPTED後關閉；這筆失敗不算通過。已改用正常受支援短名稱mefwalk，
登入帳號政策與交接顯示規則不一致另列Server followup SFD-0019，未新增或執行
名稱長度／編碼的邊界矩陣，也未改Client。

Release Host／檢查器／管理端皆零警告／零錯誤，最終 **648/648 HappyPath通過**，
零失敗／略過。[完整驗證收據](mef-integrated-tcp-validation.json) 保留兩路socket
收據雜湊、實際計數、準備帳號限制、應用層對照與首次fixture失敗，沒有混成通過。
