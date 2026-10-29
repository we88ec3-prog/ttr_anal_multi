# 有限主張與功能去重表

本表是R1導航；PARTIAL不是原生認證，UNKNOWN不得補猜，REFUTED不得作規範來源。所有子範圍與原文行號見各proposal及source-dispositions。

| CLM | 信心 | 功能／有限主張 |
| --- | --- | --- |
| CLM-CLIENT-0008 | PARTIAL | 094來源將7A86B0與7A87D0列為共同上游依序調度，並描述未完成資源由+108/+120轉入+10C active list後清槽；不等同actor登記。 |
| CLM-CLIENT-0009 | PARTIAL | 來源描述0007按前置2 bytes及26-byte row處理、以actor key去重並有4DFF30登記；主樹、其他狀態/資源容器與Server生成政策須分開。 |
| CLM-CLIENT-0010 | PARTIAL | 101描述Binding+7C與+80兩旗標分離：7F2520反轉測試結果寫+80，7BDF40僅在特定三重gate派送+18；不是所有更新都停用。 |
| CLM-CLIENT-0011 | PARTIAL | 來源描述7BDF90按item+4名稱查索引，對node+24 payload virtual+10取得item+8 Binding，與7BE0F0解綁及resource+74流程標記成對；+74=1不保證每項成功。 |
| CLM-CLIENT-0012 | PARTIAL | 來源描述共用／CMonster建構會把依component+8索引的元件指標存到owner+F4表，並有25槽清理；不賦予事件或遊戲規則名稱。 |
| CLM-CLIENT-0013 | PARTIAL | reaudit來源區分PE映射與歷史flat標籤，text受影響位置的標籤差不能自動移動rdata內真實指標或全程式所有函式。 |
| CLM-CLIENT-0014 | UNKNOWN | 元件virtual+4/+8的實際調度者與事件7/8的遊戲含義未被這些來源閉合；不能命名死亡或認為命令151直接觸發事件8。 |
| CLM-CLIENT-0015 | UNKNOWN | 六組四float係數測試與三／四參數入口可作研究導航，但係數物理意義、相機視錐／半徑、正規化方向與NaN契約尚未閉合；早期未找到writer不是不存在writer。 |
| CLM-CLIENT-0016 | PARTIAL | 來源描述515790以unsigned DWORD key查有序容器，輸出node/sentinel；7A7800另有重映射與下游查找，不能把返回節點直接當Actor。 |
| CLM-CLIENT-0017 | PARTIAL | 099以FE173C字面地址對比[FE173C]內容區分相鄰內嵌管理容器與heap名稱索引；節點+24不能證明payload同型，0x8C首DWORD是順序ID。 |
| CLM-CLIENT-0018 | PARTIAL | 來源描述2C-byte變換、子項輸出與有序有限float的resource+20最大值聚合；實際量綱、座標系與遊戲名稱未確定。 |
| CLM-CLIENT-0019 | PARTIAL | 來源將primary vtable+68解析為4C8DA0，描述寫owner+38C並由+15C/+370 gate轉送參數；事件碼意義保持未知。 |
| CLM-CLIENT-0020 | PARTIAL | 100描述heap索引7DC660接收0xB4多型Provider，C50A8C+10→7F21A0建立Binding複本，須與0x8C ID管理器及+84次級receiver分開。 |
| CLM-CLIENT-0021 | PARTIAL | 093描述7BD8D0累加resource+1C、處理子項virtual與變換，讀resource+20並有條件設+6C；不把phase、完成訊號當動畫時間或必然立即free。 |
| CLM-CLIENT-0022 | PARTIAL | 來源描述global/scene table的8-byte stride、default forwarding與scene handler index7；transport拆框與wire opcode對應仍未確立。 |
| CLM-CLIENT-0023 | PARTIAL | reaudit-02把script DeleteAllObject的owner/tree及virtual清理與GameInfo主樹分開；DeleteObject註冊與no-op不能證明通用Actor erase或最終回收。 |
| CLM-CLIENT-0024 | PARTIAL | 來源把狀態樹批次更新與128個狀態資源槽的按需建立／稍後回收分開；局部缺<128檢查不等於可利用漏洞。 |
| CLM-CLIENT-0025 | PARTIAL | 來源描述716740以字串查找後把node+28調整+3C交7197E0，並非直接返回payload或建立Actor。 |
| CLM-CLIENT-0026 | UNKNOWN | 真正場景物件vtable+20上層調度與固定更新頻率未在此來源集合中閉合；Binding/manager同offset不能替代scene receiver。 |
| CLM-CLIENT-0027 | PARTIAL | 來源把541130附近node+C列為傳給79D8E0的key來源，並指出更新候選來自既存node+28，不能當新建物件。 |
| CLM-CLIENT-0028 | PARTIAL | 原稿依4D1710／4D0B80建構vptr和C0C9DC／C0C824表值，提出CMonster／CEventActor兩個具體個案的slot+14預清理及slot0(flag1) deleting-wrapper次序。 |
| CLM-CLIENT-0029 | PARTIAL | 原稿分開描述主樹 +8 的單 key 移除、actor+88 條件遍歷、actor+4 低 byte 篩選和整表清理；查找、controller callback、actor virtual cleanup 與節點回收按各入口分離。 |
| CLM-CLIENT-0030 | PARTIAL | 原稿描述4DFF30以actor+4 WORD作查詢key，absent時插入、duplicate時走訊息分支；與+88 predicate不同，但owner+8主樹相同。 |
| CLM-CLIENT-0031 | PARTIAL | 原稿描述4C7B90基底清理多組欄位／容器、128項及25項槽、引用控制塊及4C7DB0子清理；與4C8360預清理不同。 |
| CLM-CLIENT-0032 | PARTIAL | 原稿將actor+15C指向child後的child+8介面作this-adjust，再由該介面vptr+8間接呼叫；它先於其他nested binding cleanup。 |
| CLM-CLIENT-0033 | PARTIAL | 原稿描述7DCF40以EDI為manager基址，先free+4C向量項、再free+7C buffer／清欄位和同步資源、最後回收+4C storage。 |
| CLM-CLIENT-0034 | PARTIAL | 原稿描述manager+5C歸零時drain／清44，再經FE173C名稱索引；7DC510查找sentinel後由payload vcall+C零返回才作vcall0及index erase。 |
| CLM-CLIENT-0035 | PARTIAL | 原稿描述7BE0F0對item begin/end內node+8 payload先vslot+8，再條件vslot0(1)，清payload並重設+74；7BD850另外回收pointer vector及storage。 |
| CLM-CLIENT-0036 | PARTIAL | 原稿將 7B6890 的節點 unlink／balance／free／iterator 輸出與 caller 的 actor cleanup 分開；共享 helper 不等於相同容器或物件所有權。 |
| CLM-CLIENT-0037 | PARTIAL | 原稿描述4C8360在+364和+164起128槽的nested+24非零時呼叫7BE5F0；這與清空actor外層slots及最終actor free分層。 |
| CLM-CLIENT-0038 | REFUTED | 153／157舊稿把erase傳參中的stack slot當key；既有原件反證區分傳82EF00的key地址與傳7B6890的out-iterator地址，slot被重用後不再保持原key角色。 |
| CLM-CLIENT-0039 | REFUTED | 155舊碼塊在7B698E指令中途重起，虛構7B698F/90/92等instruction rows，不能作該處精確CFG證據。 |
| CLM-CLIENT-0040 | REFUTED | 196把4DFC90歸owner+18次級樹；既有反證4DFC96 LEA EDI,[EAX+8]是主樹，真正次級路徑為4DFC30 owner+18。 |
| CLM-CLIENT-0041 | REFUTED | 183將7B8680描述為ordered-tree節點移除；既有反證為string hash/mask、bucket及list unlink/free，不能當RB tree旋轉／調整。 |
| CLM-CLIENT-0042 | REFUTED | 173將7B8006的ECX視為caller待定可變來源；既有反證7B7FFE mov ecx,1支配該store，且真入口是7B7FD0。 |
| CLM-CLIENT-0043 | REFUTED | 187把7F6FC1寫為push30；既有原件反證push30在7F6FBF，7F6FC1為mov EDI,EAX，保存manager。 |
| CLM-CLIENT-0044 | PARTIAL | 原稿以owner+44的signed gate區分7DD1A0 queue／immediate，7BB350向+7C vector寫指標，7DD1F0 drain逐槽清理；mode stop及manager引用歸零是已列caller候選。 |
| CLM-CLIENT-0045 | PARTIAL | 來源把 7C-byte 資源的 acquire／pop／reset／release／mode-gated 路徑分層，並區分 manager+0x5C 與 resource 計數 +0x60。池可復用，不是只待刪除；精確模式條件另見既有 CLM-CLIENT-0002，各步只採各來源實際覆蓋範圍。 |
| CLM-CLIENT-0046 | PARTIAL | 原稿以7BE5F0的可寫slot輸入，描述resource及其owner計數、+74/+78 gate、延遲或立即分支，並區分清nested+24 slot與清actor陣列項。 |
| CLM-CLIENT-0047 | PARTIAL | 原稿描述 4B28D0 的 WORD ID陣列候選接收路徑及 4B3710 的 WORD／06000000 條件key；與0007的26-byte建立row不同。 |
| CLM-CLIENT-0048 | PARTIAL | 原稿以4C7DB4／4C838C等有限callsite連到7BE5F0，再到資源producer；scene actor樹移除、名稱索引和manager pool仍分開。 |
| CLM-CLIENT-0049 | UNKNOWN | 仍缺移除接收器精確opcode／業務方向、actor+88 key正式schema、child與payload具體target、跨層同指標所有權、完整失敗／重入／併發及runtime觸發；原版Server生成時點／波次／AI不由這些本地資源helper決定。 |
| CLM-CLIENT-0050 | PARTIAL | 來源把 30-byte wrapper 與 7C-byte resource 分層，wrapper+0x2C 保存 acquire 結果；同為 +0x20 的欄位不證明同一物件。Binding／acquire／reuse 依各來源子範圍導航，187 的指令座標錯誤另行排除。 |
| CLM-CLIENT-0051 | UNKNOWN | B entry具體型別、其+04執行/+08浮點評分目標與分數語意仍需同一物件來源鏈；不採距離/相機/畫面優先級命名。 |
| CLM-CLIENT-0052 | UNKNOWN | B佇列排序/前N執行與22桶派送的時間順序，不能直接當entry execute造成入桶的資料因果鏈；此橋接仍是S00具體阻塞時才需R2的問題。 |
| CLM-CLIENT-0053 | UNKNOWN | 137..140的局部writer未找到與141..144聲稱找到Host+0C append屬來源研究進展；在精確PE修正版複驗前只能導航producer、guard、grow/alias問題。 |
| CLM-CLIENT-0054 | PARTIAL | 來源把 FB7740 的 22 桶配置、producer append、count 及候選 consumer 分開；局部上界／stride／相同版型不證明同一實例或每幀處理。各來源只提供其實際覆蓋子集，owner closure 的映射衝突另保留。 |
| CLM-CLIENT-0055 | UNKNOWN | 候選 dispatcher／callback 的實參 owner 是否連到 FB7740 全域 heap，仍需按精確 PE 座標及指標 alias 確認。未直接讀 global 不證明不同，129-resolved 的 FAILED 版本也不能覆蓋先前未知。 |
| CLM-CLIENT-0056 | PARTIAL | callback配置/註冊、callback+04空方法候選與+0C分桶方法是不同調度職責；entry本身的+0C又屬另一型別，整合時保留三者區隔。 |
| CLM-CLIENT-0057 | UNKNOWN | 既有T01精確映射裁決已指出129-resolved及130..152的來源座標問題；舊flat文字區與PE相差0x400須逐點更正，資料/vtable絕對值保持其自身節區解讀。 |
| CLM-CLIENT-0058 | PARTIAL | 來源區分manager handle、配置核心、callback與manager+EC介面，並將EC建構參數來源和幾何/dispatch虛槽作有限研究導航。 |
| CLM-CLIENT-0059 | UNKNOWN | 候選Host建構、embedded vptr、holder/control pair與兩階段release研究尚未連到同一B entry的入列/執行/析構時序；沒有UAF或安全存活保證結論。 |
| CLM-CLIENT-0060 | PARTIAL | 來源先記錄0x60/24-float幾何係數初始化與讀取，118/119後稿提出非初始化writer及平面生成數學，120明示為歷史缺口的後續研究。 |
| CLM-CLIENT-0061 | UNKNOWN | 按名稱登記record+20、A-array及group子陣列的append不可因共用helper誤認成B queue producer；修正映射後仍需按實參owner確證此區隔。 |
| CLM-CLIENT-0062 | UNKNOWN | 兩條幾何更新入口與participant回呼職責有研究線索，真正外層觸發、頻率及與場景更新之關聯未確證。 |

## 歸併而未新增的群組

| 提案key | canonical | 理由 |
| --- | --- | --- |
| early-pool-lifecycle | CLM-CLIENT-0045 | 同一功能問題的不同子範圍追加引用，條件／未知仍分開 |
| early-wrapper-provenance | CLM-CLIENT-0050 | 同一功能問題的不同子範圍追加引用，條件／未知仍分開 |
| early-bucket-producers | CLM-CLIENT-0054 | 同一功能問題的不同子範圍追加引用，條件／未知仍分開 |
| early-bucket-owner | CLM-CLIENT-0055 | 同一功能問題的不同子範圍追加引用，條件／未知仍分開 |
| late-getter-history-correction | CLM-CLIENT-0001 | 既有精確決議；新稿僅PARTIAL，154／156舊轉換器假設只作REFUTED歷史關聯 |
| late-mode-collection-order | CLM-CLIENT-0002 | 既有精確決議；新稿僅PARTIAL，154／156舊轉換器假設只作REFUTED歷史關聯 |
