# MEF 延遲門檻與父旗標相依索引

2026-11-22。SERVER_DESIGN_CHOICE / NOT_NATIVE_MEF。
接續[波次血量事件索引](WAVE-HEALTH-EVENT-INDEX.md)與既有 OPT-01／03，
不改關卡schema、Client或既有延遲數值。

## 原點及派送契約

| 類型 | 起算點 | 本批策略 |
|---|---|---|
| NodeDelayElapsed | 原節點啟用時計 | 同起點的門檻排序，游標只比下一個尚未到期門檻 |
| ClearDelayElapsed | 清場後首次有效位置觀察 | 保留獨立起點；同起點門檻游標 |
| FlagDelayElapsed | 父旗標成立後首次有效ObserveNodeTime | 反向父旗標索引排候選，到原phase才啟動；依相同起點分批使用門檻游標 |

所有到期判定仍是既有 `GetElapsedTime(...).TotalSeconds >= DelaySeconds`。
不計算新的絕對tick、不引入floor／ceil或以動畫等待取代時計。
同一poll可能多個門檻已過，派送仍按原signals陣列順序，不按排序後的到期順序改寫。
已完成列不重比；空的到期集合不配置集合。這是分起點門檻索引，不宣稱完成所有combat timer的全域deadline queue。

父旗標變更只排入相依旗標延遲候選；不在封包／傷害／背包callback直接啟動時間。
FlagsCountReached新產生的旗標也必須通知相依列。父旗標由前一房保留時，進段只排候選，
仍等新節點啟用與首次正常觀察才起算。
旗標延遲均為正值，新啟動者不能在同一時間戳到期；鏈的父節點到期時，子列在同poll以同一now啟動。
同一時間戳另有正常父事件可合併尚未elapsed的批次，不能丟列或預支時間。

fork複製游標、待啟動集合、各起點批次及原時計，不能修改原實例。
真正Enter／循環重訪清空當房批次與游標，再依重置後旗標seed候選；舊房計時不得流入新訪次。
RegionHeld、定時／順序增援、技能冷卻、回血、投射物等維持原執行器，不混用本索引。

## 驗證與工作量

需要獨立全掃模型比對混合延遲／反向鏈／FlagsCount／起算與fork，
同時間戳父事件、真循環重訪、原順序派送與安靜等待的正流程證據。
正常TCP使用既有1.5秒機關與0.75秒活頭目增援候選，舊／新版相同Inspector及原BND／內容，
完整回包只正規化已查明的每登入wireAlias；其餘byte與順序須相同。
原波次、頭目、機關、88EXP保存與同隊回村仍需同場成立。

診斷記錄原候選槽位的保守下界、實際門檻比較、啟動／派送數與走過的父相依邊。
舊FlagDelay的固定點可能多pass，槽位基準只記一次，不能把此下界當作精確舊CPU／迴圈成本。
這些是有限正常內容的工作量，不是壓測、CPU節省或Client卸載。
原件／現用Host／使用者DB不更動，指定v2及自然新帳號保持獨立驗收。

## 本批結果

[驗證收據](delay-threshold-index-validation.json) SHA-256
`95282d827a49d1d4b642b33bea96b26b790e0f3efa8ee40ac569de2be85a444d`。
基準Network `605c2a41`、新版 `4173f0c1`，兩者使用相同Inspector `c615c594`。
兩路完整primary回包3669／4159筆、mission段3507／3997筆，只正規化每路57筆
既有隨機wireAlias；其他byte與順序相同。原始完整回包SHA不同的事實保留。
每節點FlagDelay觀察／起算與旗標一致，1.5秒機關及0.75秒存活頭目增援均通過。
兩路各保存88EXP並回原村同隊。頭目房累積候選槽下界870／851，實際門檻比較52／46；
各啟動2個旗標計時、派送3個timer旗標、走過2條父相依邊。這不是CPU量測。

同新版Network的獨立Host使用原BND、真實時計、另備角色4／Lv15資料庫，
正常登入／廣場建隊／進村後走10→1→3→5→4→2，機關、波次、頭目階段、
單次88EXP結算入庫及原村同隊返回均通過；Host與driver是不同程序。
原seed DB未變，已核對PID／部署路徑後停止本批Host，沒有替換現用服務。

四個新正流程測試與全部752／752 HappyPath通過，失敗／跳過均0；
TRX SHA-256 `53dc2be460d0f1d240d32230d2262d62179cfe584096565342cfd5032cbfc83e`。
Host、Inspector、Admin三個Release建置皆零警告／零錯誤。
停權／重送／重登／故障／安全／併發／壓測未執行；指定v2及自然新帳號仍待驗。
