2026-11-08 v72準備（未部署）：[拳套往返與拉引](../../../design/runtime-content/LAB-RETURNING-PROJECTILE-POLICY.md)新增獨立NOT_NATIVE_MEF邏輯命中體，Pipa2995去程沿途命中一次／回程只拉引、碰撞與遮擋檢查、追蹤目前玩家位置；速度／範圍／傷害／拉引值明列測試校準，不宣稱原版投射物或強制位移動畫。201項正流程、Host建置、來源重現、頁面檢查及自製Server組件資料投影通過。現行仍v71，正常進村與技能實機待驗；181候選／883slots、62未開不變。

2026-11-08 已整批部署v71，PID45668，來源7c2347e15a055a82278449459df949f9692b85ce，取代v68／43752（換版時0遊戲連線）。含九角色受擊、兩項拳套／冰針比較與部分凍傷。197項HappyPath通過；四個loopback埠、獨立備份檢查及實際HTTP目錄181候選／883slots已確認。62項仍無動作候選，完整玩法／原生MEF／實機均未完成。正常建房進村仍為首項實機驗收，使用者稍後測、不重複催測。收據host-v71-deployment.json；以下未部署敘述為當時準備紀錄。

2026-11-08 v71準備（未部署）：[凍傷部分效果](../../../design/runtime-content/LAB-FROSTBITE-POLICY.md)對Crmd3034套用Buff28來源攻速下降20～28%／原始時間5～7，移速20%及必定觸發／秒換算明列Server測試選擇。個別怪物移動、攻擊動作與排程減速、到期恢復；群體間隔及其他怪物保留。197項正流程、Host建置、來源重現及頁面顯示檢查通過。181候選／883slots、62未開不變；現行v68，實機仍待驗。

2026-11-08 v70準備（未部署）：[拳套／冰針整段比較](../../../design/runtime-content/PUNCH-ICE-LAB-COMPARISON.md)接入Pipa2995四clip及Crmd3034兩clip，保留原配置／消耗／冷卻，頁面明列往返拉引／多段冰針／凍傷待實作。193項HappyPath、Host建置及來源／投影重現通過；181比較候選／883slots、62項尚無動作候選，不等於完整技能。現行v68，正常進村與技能實機仍待驗。

2026-11-08 v69準備（未部署）：[九角色受擊規則](../../../design/runtime-content/ALL-ROLE-HURT-REACTION-POLICY.md)補上原本只有role4送受擊狀態的缺口。九角色原始ABF／ASD與共用state5入口有界核對；0.15秒反應／0.9秒觸發冷卻與施法保留仍是Server選擇。191項HappyPath及Host建置通過。179候選／881slots、64項未開不變；現行v68，正常進村與實機技能仍待驗。

2026-11-08 現行Host已整批更新v68，PID43752，來源5afda2ef6d76b35afabb91e0564964569f1eb869，取代v63。181項正流程與四個loopback埠／DB備份／實際HTTP目錄及新效果設定已核對；現行179候選／881slots，64項仍未開。頁面新增可選三怪與精簡輪詢，本次未連線狀態回覆472bytes；非遊戲延遲／壓測驗收。正常建房進村與技能實機仍待驗，不重複催測；需重新整理測試頁取得新功能。收據見host-v68-deployment.json，後文準備版敘述保留歷史範圍。

2026-11-08 v68準備：[技能目錄分流](../../../design/runtime-content/SKILL-LAB-CATALOGUE-DELIVERY.md)保留舊狀態API，新增固定目錄端點及精簡輪詢，避免每2秒重送整份技能資料。181項正流程、Host建置與頁面流程通過；不宣稱壓測／遊戲延遲改善或實機通過。後續部署收據另列。

2026-11-08 v67未部署：[群羊暴走輕微暈眩](../../../design/runtime-content/LAB-WEAK-STUN-POLICY.md)區分Buff39／4～8原始持續值與拘束12，加入技能場移動及攻擊鎖定、到期與後續受擊解除。必定觸發／受擊必解及時間轉換明列Server選擇，不宣稱原生機率或暈眩姿態。180項正流程、Host建置、JS／頁面流程通過。候選仍179／881，64項未開；現行仍v63，正常進村與新效果實機待驗。

2026-11-08 v66未部署：[技能場可選測試怪物](../../../design/runtime-content/OPTIONAL-SKILL-LAB-TARGETS.md)新增None／Melee選擇，三怪HP1000／傷害5，進場至少80單位、5秒後追擊；預設空場及正常副本保留，清怪不推主線。177項正流程、Host建置、JS／頁面流程通過；編譯程式對實際Road191 BND的安全位置檢查通過，非實機驗收。現行仍v63，候選仍179／881、64未開。

2026-11-08 v65未部署：[怪物拘束部分效果](../../../design/runtime-content/LAB-ENEMY-HOLD-POLICY.md)接上Grnt6／483周圍目標的移動鎖定與到期追擊，保留怪物近身攻擊及施法者恢復；半徑／必定觸發／等級與時間轉換明列Server測試選擇，未新增敵方Buff封包。175項正流程、Host建置與JS語法通過。候選仍179／881，64項未開；現行仍v63，正常進村與新效果實機待驗。

2026-11-08 v64未部署：[群羊暴走比較候選](../../../design/runtime-content/GRNT-SHEEP-LAB-COMPARISON.md)核對三方向宣告與舊效果單方向重用，僅新增Grnt6／3056五個整段比較片段，不宣稱官方派送或等級變體。172項正流程及Host建置通過，準備版179候選／881slots，64項仍未開；現行仍v63，正常建房進村與新視效實機待驗。

2026-11-08 現行Host已整批更新v63，PID33620，來源94e60d735bfe90921e6c17e4d16c6996731a4234，取代v58。四個loopback埠、DB一致備份、HTTP個別等級與雙Buff配置均獨立核對；171項正流程結果保留，仍189組／880slots／178候選。正常建房進村及技能圖示實機仍待驗，未重複催測。部署收據見host-v63-deployment.json；下方未部署敘述保留歷史範圍。

2026-11-08 v63未部署：[個別技能等級](../../../design/runtime-content/INDEPENDENT-SKILL-LAB-LEVELS.md)允許依Practice指定等級，0126快取、扣量與係數一致，V／Tab按技能身份保留等級；頁面新增個別選單。171項正流程、Host建置、JS語法與頁面流程模擬通過。仍178個動作候選／880slots，並非完整技能；現行Host仍v58，正常進村與混合等級實機待驗。

2026-11-08 持續回復缺口核對：[八項回復Buff計畫](../../../design/runtime-content/PERIODIC-RESOURCE-BUFF-GAPS.md)區分回復屬性、每次回復量與通用暫定回復。TC475名稱不一致、335第8級無同號Buff說明均保留；測試頁新增未完成效果標示，沒有新增回復數值／Buff授予。Host建置與JS語法通過，現行仍v58，未新增實機通過紀錄。

2026-11-08 v61未部署：[額外Buff組成政策](../../../design/runtime-content/LAB-ADDITIONAL-BUFF-POLICY.md)新增強力防禦雙Buff、神聖之盾減傷及反轉受擊回HP的部分玩法；1297不自套，屬性／隊友／native grant與level仍有缺口。V2資料40rows，0077只擴至已核1/2/3/4/8/86/107。160項正流程、Host Release與JS語法通過，現行Host仍v58，正常進村與圖示實機待測；178／880候選數不變。後文保留歷史範圍。

2026-11-08 v60未部署：[原生Buff快照0077接線政策](../../../design/runtime-content/LAB-BUFF-SNAPSHOT-0077-POLICY.md)已核接收lane2／primary可達、actor+3F0替換、ID／level至UI；剩餘時間與高byte語意未證明。技能場接上四防禦Buff套用／到期／耗盡的完整清單，僅發自身已核ID1..4。154項正流程及27組初始化順序追加斷言通過，Host Release通過；圖示／視效仍待實機，現行Host仍v58。後文舊的Buff wire未決／未部署敘述保留其當時範圍。

2026-11-08 v59未部署：[四項防禦技能政策](../../../design/runtime-content/LAB-DEFENCE-BUFF-POLICY.md)採用新核對BuffExplain同名候選，接上索瑪防禦、坦基裝甲減傷、坦基屏障與意志之盾的自身有限次阻擋；不聲稱原版Active→Buff派送或time單位已證明。物攻／迴避公式與隊友效果待開發。153項正流程通過，現行Host仍v58；178／880候選數不變，正常進村實機仍待測。後文保留歷史狀態。

2026-11-08 現行Host已整批更新至v58，PID30588，來源d2b85b791ce02b250818ddce19b30b77ed398580；取代v53測試版。四個loopback埠、健康與HTTP技能189組／880slots／178個候選獨立核對，巡行陣每2秒補105HP等暫定設定已實際提供。149項HappyPath通過、DB一致備份已核驗。正常建隊進村仍優先且實機待測，未催測；原生MEF、多人與完整技能仍未完成。收據見host-v58-deployment.json；後文未部署／v53敘述為歷史狀態。

2026-11-08 v58未部署：[巡行陣持續治療政策](../../../design/runtime-content/LAB-HEALING-FIELD-POLICY.md)新增固定位置治療陣：Server暫定半徑45、每2秒補血、6秒到期，只接自身；不是原生數值／MEF或多人治療。149項正流程、Host Release與JS語法通過。現行Host仍v53，正常建隊進村實機待測；候選數178／880slots不變。後文保留歷史狀態。

2026-11-08 v57未部署：[技能攻擊／治療分流政策](../../../design/runtime-content/LAB-SKILL-IMPACT-ROUTING.md)修正治療／防禦輔助技能誤走通用傷害，五項自身補血採明示Server暫用魔攻100與校準公式；不是官方公式、多人治療或完整技能。148項正流程通過，現行Host仍v53，正常建隊進村實機待測。候選數仍178／880slots，65個active未開放。後文為歷史狀態。

2026-11-08 v56未部署：[四項元件線索比較政策](../../../design/runtime-content/FOUR-TOKEN-LAB-POLICY.md)新增幻滅刀影、躍舞手裏劍201、聖靈之盾與正義火焰炮隔離候選。178個lab候選／880slots，65個active尚不可測；不是完整技能或官方映射。128項正流程及Host Release建置通過，Host仍v53、正常建隊進村實機待測。後文保留歷史狀態。

2026-11-08 v55未部署：[元件名稱錨點比較政策](../../../design/runtime-content/COMPONENT-ANCHOR-LAB-POLICY.md)新增露可伏擊、艾芬多絲冰盾與冰鎚的隔離視效候選。174個lab候選／876slots，69個active仍不可測；不是原版映射或完整技能。124項正流程通過，測試fixture調整後3項再通過。Host仍v53，正常進村實機待測；後文為歷史狀態。

2026-11-08 v54未部署：[其餘舊技能比較政策](../../../design/runtime-content/LEGACY-SKILL-COMPARISON-POLICY.md)準備3角色普攻、造化之劍及2個單次完整視效變體比較；171個lab候選／873slots，剩72個新矩陣active尚不可測。121項正流程／Host建置／JS語法通過。這不是171個完整技能或原版選擇規則；現行Host仍v53、正常進村實機待使用者稍後測。後文為歷史狀態。

2026-11-08 現行測試Host已改為v53，PID44028，部署來源8d4638e4a166172040ea8c8f25bdaf460668af95。115項HappyPath通過；四個loopback端口／健康／HTTP技能目錄189組、841可用slot獨立核對。此合併版取代v50測試卡，原正常建隊進村路徑保留；165個lab候選不等於完整技能，實機仍待使用者稍後測。多人加入／邀請仍預設停用，原生MEF仍不支援。

2026-11-08 時序來源後補：loaded-animation-span-producer-v1.json追到載入entry+4的產生與回呼鏈，主要是動畫資料range終點做signed整數/160後轉float，並非直接證明秒數；完整FPS clock與取消／恢復窗口仍未知。0x24 bytes配置大小已核對為36bytes，不把尾碼B黏成hex0x24B。這是獨立的新增producer範圍，未重掃舊parser／MEF。

2026-11-08 v53來源／政策更新（未部署）：[八項具名家族比較政策](../../../design/runtime-content/NAMED-BASIS-LAB-POLICY.md)新增8項Server選定的Basis測試候選，保留原矩陣與V階段。lab現在165個active／841個slot可比較，78個active仍不可測。歷史87項是原命名缺口紀錄，不表示其他156項已證明官方dispatch；本批亦沒有新證明官方映射或完整玩法。115項正流程通過，實機待使用者稍後測；Host仍v50。後文數量保留歷史狀態。

2026-11-08 候選政策更新（未部署）：[索瑪普攻測試政策](../../../design/runtime-content/SOMA-BASIC-LAB-POLICY.md)新增role1/Practice1/active1專用六clip候選，明確是Server選定的隔離比較方案，並非新找到官方動作映射。lab候選157項／799個矩陣slot，尚不可測86項；來源映射缺口仍87項（索瑪此項仍未閉合），不可混計。新duration查核亦未驗證舊sum((End+Delay)/FPS)為原生時鐘，不能改成End−Start或稱為硬直／cancel權威。後文數量／「未開放」敘述保留歷史狀態。

# 全角色技能開放接續

本包是原始資源的欄位／SHA投影與Server隔離預覽候選，不是Client資源包或完整技能完成證明。

`runtime-unlock-candidates-v1.json`：索瑪1287與蘋果1289的兩個單clip候選、98個member身份與等價fingerprints。完整canonical ASD樹只留本機；公開檔不含raw XML。`project_equivalent_runtime.py`只更新這兩個role/practice/active的14個已核對配置slot，保留其餘資料，不會開放未解項。

`explicit-links-public.json`保留89個原未開項目的Practice／ActiveInfo欄位投影與輔助schemas調查：同鍵替換不等於動畫繼承，沒有可據以自動連動的已證bridge。這是有界查核，未證整個Client無任何關聯，也未證缺檔。
兩個候選之外仍87項未開：72新配置動作映射、13命名橋、2個不等價多Basis；另行逐項續查。所有動畫候選的傷害、命中、目標、持續、投射物與特性呈現仍須獨立實作／驗收。

後續瀏覽器已讀到使用者四份播放清單：索瑪、蘋果、舒博爾、柯摩托各27支。`user-video-index-108.json`保存實際可見標題／連結，`video-title-skill-join.json`以role+台版顯示名精確連到105項技能，其中40項尚未開放。這不是108支皆看完或影片可直接提供motion ID；只有索瑪電火球抽看約0/1/2/4秒畫面，保留藍球／前方impact的有限觀察，未據此自動開放技能。其餘五角色的清單不在這108支索引。

[cache-consumer](cache-consumer/README.md)另補閉合549980的原生成本ABI：cache word+4傳EAX、activeID傳ECX到HP/SP/MP getters。+6的MAX建構與真正呈現consumer分開，這條路線未給出新的active→motion映射，不因此開放87項。只收白名單9檔，18個既有bulk函式身份／6個指令區段及小型指令窗；未發布本機完整工作dump。
影片是使用者指定的台版Rebirth參考，不表示與本次KR原始build完全一致。

參見 [v35採用與需求](../../s00-iterations/S00-20261107-V35-NPC-MARKER-CHARGE-AND-SKILL-OPENING.md)。原始檔／完整ASD樹不推Git；工具需由操作者另備指定原件與既有metadata，不能直接把歷史路徑當已配置環境。
