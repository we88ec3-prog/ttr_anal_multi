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
