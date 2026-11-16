# v37 原生氣散發狀態

原始BIN SHA9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91，保留唯讀。RTTI型別／locator／vtable／建構ABI／OnEnter與輸入gate以[契約](contract.json)及[指令](native-windows.txt)限定驗證。

CCharacter在4CD9B7以ECX12傳入4CB230，狀態物件+8保存ID、+4保存actor。ForceState vtable C079B4的OnEnter4CBE30直接播放motion19，保留+2C與+30旗標，546100可繼續收集V放開與動作輸入。000C的4B0130讀actor及signed state byte後呼叫actorFSM virtual8。

000D動作入口4C8A90則先切FSM13再播放motion；用它播放循環19且Server無限等放開，會有輸入收集被關閉的因果風險。v36人測退回及最後收包128／出站motion19吻合此機制，但未附加Client記憶體，不宣稱觀察了當時FSM值。

因此v37改送000C狀態12；放開改回1。不改Client、資源或技能ID。ForceState本身不改actor+3E8或技能列，長按期間row2仍是既有明示Server重建。

重現：以本機capstone／anal/build_native_index.py執行 verify_force_state.py --workspace-root E:/Tartaros/workspace。腳本只讀原件及既有bulk，輸出限定指令與hash，不執行Client或provider。初版視窗起點5461D0不在指令邊界，及RTTI字串讀取長度不足，皆被assert擋下；修正成rooted546230視窗及完整字串後才通過，不把失敗嘗試當有效證據。

此為限定原生來源，不是整函式／Task FULL-PASS，亦未證實官方Server完整封包時序。95項正流程合成通過，實機待回。
