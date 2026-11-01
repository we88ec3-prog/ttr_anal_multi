# S00：戰鬥與廣場接續候選v7本機啟用

2026-11-01 13:19:55 UTC，依既有指定loopback Host換版授權，將v6替換為v7。
換版前原Host PID/path核對相符，8415/8416/8414僅有127.0.0.1監聽，沒有Established遊戲連線；
沒有以舊metadata或等待時間推定已退出。使用者仍操作Client，沒有代開／附加／修改遊戲。

## 本次整批內容

以私庫源碼commit `0de80050c9a9f12f5666eaeb63a3e94c57529062` publish到新目錄，
包含能力頁與actor資源初始化、伊莉西亞技能名目片長、既有三怪／持續輸入戰鬥，及
獨立EXIT模式的有序劇情→CSquare入口→最後reset後玩家重建／綁定→12個NPC actor候選。
不是只改一個數值就中斷測試；舊v6沒有進行中的遊戲連線。

啟用 `LOCAL_WORKING_COPY_TUTORIAL_EXIT_CANDIDATE`，另以已釘原資源解出新square001.bnd副本，
Host在啟動時核對SHA、玩家入口與全部NPC靜態點。原資源／Client未改，沒有all-clear fallback。
對應限制見出口、NPC、stat／resource與skill-timeline報告；原本所稱「尚未部署」是各報告當時狀態，
此次才合併啟用。v7結果卡明確取代v6卡。

發布DLL SHA256：

| 元件 | SHA256 |
| --- | --- |
| Network | 7c130fbc022d1a23f1ed834055cdd0b5583c2f2e6ed4436389b29c681cc2e0f8 |
| Protocol | 72f8bd553d8da6bef00e2578bd47c5540cf899af5adfb5ca38c0388ae4e3d174 |

SQLite備份API先從唯讀連線建立一致快照，未列印帳號內容。快照SHA
`2ab03e789bf7ba9da49206d9ddde019c0ce610e9c3593da4defff3f14bfdd407`；
相同DB、Admin與既有角色／名稱保留，global schema2／既有component保持，沒有migration。
新Host健康端點正常。一般health的diagnostic gameListener=false與本機candidate auth/journey
flags是不同層，不能把前者誤寫成本機遊戲服務未綁定。

## 驗證與人工結果界線

16個HappyPath合成case、Host Release build/publish通過。
私庫上述精確commit的[CI41310383350](https://github.com/we88ec3-prog/ttr_server_roy/actions/runs/41310383350) success；
公庫分析前一head `a84bf6df0db4f33a4e5ec00377727447223e5fab` 的
[CI41310383334](https://github.com/we88ec3-prog/ttr_anal_multi/actions/runs/41310383334) success。
這不是本部署附記新head的CI，也不是Client驗收。

人工連測卡：重開正常登入／教學→預設伊莉西亞首戰，觀察三怪追擊／出招與玩家受傷，
一次X、Z連按／放開／收尾；若戰鬥正常才續招募／蘋果家末段劇情→廣場人物／NPC→短走與停止。
異常立即停，不跳過教學、不接新任務，另回報loading是否出現。
結果尚待回，沒有把成功啟動、資料發送或NPC數量當作人測通過。

正式Quest16結算／完成持久化、官方位置／完整傷害時序、loading呈現、NPC互動及真實同登入
可操作性仍有限制。REQ-0016／0017與完整新帳號完成教學→廣場尚未結案，goal保持進行中。
原版Client compatibility、formal admission、normative pin與APPROVED狀態不變。
