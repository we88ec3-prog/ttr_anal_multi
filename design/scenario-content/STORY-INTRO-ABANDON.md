# 戰鬥建立前的主線開場取消

2026-11-24。Server 接線／正常工程驗證已完成；**指定v2操作、鏡頭及輸入清理仍待驗**。
接[入場／清場演出取消](STORY-PRESENTATION-ABANDON.md)的既有Town0038先Stop再載入，
本批處理尚未選本次主線角色、尚無Scenario instance的Intro，包含不帶戰鬥的主線開場。

## 村莊場景的來源

正常Town的既有69/7 bootstrap建立CSquare；不能把它直接當作前批的CScenarioField。
`4BBB70`先呼共用`4ADD50`，設vtable `C06FB0`，再呼`4BBBA0`；後者清的是
`+5EAC`開始、長`5EA8`的本地區段，並寫十個列明本地callback欄位，沒有覆掉共用0038的`+1C4`。
因此沿用前批已核的`4B1BF0`：先呼active-Q Stop，再依既有subtype0／Town WORD預載。
仍是同一個有目的村副作用的9-byte context，沒有虛構Stop-only opcode。

[intro-stop-source.json](../../kr-extra-roy/SCENARIO-PRESENTATION-ABANDON-20261124/intro-stop-source.json)，SHA256
`a22255bfda0de57dbf2d020e8ff2800e7e10e16af43c8f989e904dae124c6423`；
[唯讀驗證器](../../kr-extra-roy/SCENARIO-PRESENTATION-ABANDON-20261124/verify_intro_stop.py)。
兩個直線constructor／reset到首個return的窗口共141bytes／27指令，兩份凍結REA／Ghidra身份另驗；
重用前批0038／Stop證據，不重匯原件或推整函式FULL-PASS。原件SHA前後保持。

另只讀核對指定 `Tartaros.ip-zh-tw-only-v2.exe`，SHA256
`6f92ba12d83cd75668353ca175122309ffa5b35a9fa2fee9fe85e2c0350d3b3c`：
本批與前批相關十段constructor／共用處理器／Stop／確認／sender code windows全部與原件相同，
v2前後SHA保持。[code比較收據](../../kr-extra-roy/SCENARIO-PRESENTATION-ABANDON-20261124/specified-v2-code-comparison.json)
SHA `845396b2887ff6276084154a0f94b6797bb57a64b02f27c6b3f99337b2499182`，
[唯讀工具](../../kr-extra-roy/SCENARIO-PRESENTATION-ABANDON-20261124/compare_specified_v2.py)。
此範圍不是整個主程式／資源／全局資料／UI可達性比較，不能取代實機active-Q、畫面或輸入驗收。

## 保存與返回

Intro沒有Scenario，原本只檢查「在戰鬥副本內」會漏掉這條正常取消。
連線現在將有效Intro納入同一取消context，仍檢查租約、非debug、loaded、無待提交轉換及單人owner。
domain規劃同一任務Npc／node0／scene0、revision+1、不含ScenarioCompletion；
保留已完成前置、背包／裝備／餘額與經驗，不建立一個假戰鬥來套取消。
Intro返村也先讀已提交資產，避免因沒有Scenario而漏掉回村背包快照。
這項預讀只在Intro取消提交時生效，正常播完Intro仍沿原本完成流程。

提交成功後，同一份目的Town0038在69載入之前送出，43後不重送；原0089隊伍清理保持。
工程路線模擬一次Stop可能產生的正常003F，pending Town loading期間不把它當成任務完成。
原生是否真的送回報仍受原確認政策影響，Server phase不是native active／cleanup ACK。

## 證據

- 新domain正流程分別涵蓋Q117無戰鬥開場、Q119有後續戰鬥開場：取消前後Scenario皆空，
  任務索引不變、revision+1、零完成項，NPC重開仍Intro。
- Q119正常TCP：scene1未回報完成就取消，村莊context先於69且只一份；0擊倒EXP、183×3保留，
  零Q119獎勵，同連線NPC／intro／選角重開到新Encounter。原scene2／scene4兩TCP控制仍保留0／52EXP。
- 獨立實際時計Host：在最後實際發布的Town1／Map182取消Intro，Scenario為空；可能的Stop回報後
  正常返村與NPC重開。停止後DB／日誌副本讀回39,000EXP、183×3、零Q119獎勵與新Encounter進度；原檔／seed保持。
- 三Release零警告／錯誤、816HappyPath零失敗／略過。只跑正常套件，未排入重送／重登／故障或壓測。

收據：[story-intro-abandon-20261124.receipt.json](../testing/story-intro-abandon-20261124.receipt.json)，SHA256
`0439df1cf7ae8b3be695570f6343da6f00fd6550e69c48537420c881fb95ae33`。
首個成功Host的工具metadata誤填未來戰鬥圖632；修正為當前最後發布圖182後另存新場。
Server接線未改，原成功場次保留但不採其錯誤map欄位作最終證據。
最後把Intro資產預讀明確限定於取消，保留正常開場完成原路；另存最終批次重新通過三Release／
816HappyPath／三TCP／獨立Host。前一批收據及輸出另存保留，最終收據只綁新版DLL。

TCP／Host已準備教學、Q15、Lv15與183×3，不算自然新帳號或掉落驗收；
Q117目前是domain證據，TCP／Host本批實測Q119。ReturnScene、Q15演出及指定v2仍各自待補。
未啟動／附加遊戲、修改Client／資源或替換現用服務；整體MEF目標保持開啟。
