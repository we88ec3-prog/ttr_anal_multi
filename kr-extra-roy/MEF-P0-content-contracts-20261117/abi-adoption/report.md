# ABI、勘誤與原內容相容：P0完整採用分析

## 1. 結論及可驗證終點

本題的完成條件是：將前輪已證 ABI／勘誤轉為內容工具可採用的明確規則，涵蓋所有121正常名稱；將新作者的拒絕政策與原 Client 實際接受行為分開；對選定原 SEQ 的真正語句、helper 與 C binding 邊界補齊必要證據；每個規則都有來源、預期結果、反例與可重跑工具。本題已達成此有界靜態目標。這不等於 Server 已接入、所有遊戲事件已還原或可玩驗收完成。

基準固定為 `ac7e668ef19b91f86f05074d660aba10612c9a5f`。`source-manifest.json` 保存每一來源的 commit、path、Git blob、SHA256與bytes。原 KR BIN 為12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；Event為11,241,597 bytes，SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`。本題引用既有已證成果，原 BIN 只追加檢查本題需要的原窗口及零參數相容鏈，沒有重掃全部函式或重建全部資源。

| 覆蓋面 | 本題採用邊界 |
|---|---|
| 121正常綁定、15功能domain | 每名稱均有精確 arity、型別、suffix index、closure、marshaller、native、功能限制與採用用途 |
| 33種marshaller | 重跑前輪完整 ABI verifier，保留各種類的原始轉型證據 |
| 17個新number producer | 16本地觀察 query＋`lb.DoFile`診斷數值 |
| 104個不建立新值的綁定 | 禁止以C callback回傳1推論成功、ACK或新物件ID |
| 四stub＋一偽count | 全部明示不可採用為該功能，不因名稱存在而啟用 |
| 前輪15個勘誤項 | 全數採用，followup三項已去重一致；不改舊稿與歷史測試 |
| 原qbase75個export helper | CFG有界名稱資料流，76處正常native callsite，唯一arity差異已另閉合 |
| Q119/3、Q2440/5原SEQ | 分別46／62個body呼叫，另各一個top-level Register；不改原碼 |
| Boot／Logic／Coroutine | 3份原Git保存chunk、15個prototype、199個instruction word；確認Boot數值常數來源 |

全121索引見 [ADOPTION-INDEX.md](ADOPTION-INDEX.md)；詳細欄位見 [adoption-catalog.json](adoption-catalog.json)。以下 `[ABI]`、`[OBSERVATIONS]` 等為本題manifest的精確來源ID，不是未固定版本的泛稱。

## 2. 原生事實與作者政策分開

### 2.1 last-N視窗不是按名稱補參數

原marshaller從當前 Lua stack 的最後N格取值，例如 `Q.CreateObject`為 `-9..-1`；宣告的native順序由實際push順序確認。多加尾參數會移動整個視窗。缺參數不代表自動補nil；某些負索引可以落到函式格或更前面的caller資料。Colon語法附加self偶爾未移動所需suffix，也不構成另一個安全作者介面。[ABI、ABI_NATIVE]

新作者計畫因此只接受121正常dot名稱及**精確參數數量**。Helper是另一層契約，例如原 `WalkObject`七參數不是 `Q.WalkObject`六參數。工具不悄悄刪引數、不補nil、不插self、不將字串/數值猜成ID。原件中已有的相容特例另作證明，不能用新作者政策的REJECTED判定原Client不可靠。

### 2.2 數值、boolean、nil是不同來源型別

一般數值模板接受tag3 number，或將tag4 string經`6F7760`解析。整數用x87 `FISTP DWORD`，float用`FSTP DWORD`；boolean與nil等其他tag走0。故 `true`、`false`在這類數值格都轉0。數值小數的整數捨入還受當時FPU控制狀態影響。[ABI_REPORT、ABI_NATIVE]

`ScenarioTalkTable.open`第三參數是特別的Lua truthiness契約：nil、boolean false為0；number0、空string、boolean true為1。不能把它的規則套到所有整數開關。

| 明確存在的一格 | 原生一般整數marshaller | 原生open第三格 | 新作者政策 |
|---|---:|---:|---|
| number0 | 0 | 1 | 數值格接受；truthiness格拒絕 |
| number1 | 1 | 1 | 數值格接受；truthiness格拒絕 |
| boolean false | 0 | 0 | 數值格拒絕；truthiness格接受 |
| boolean true | 0 | 1 | 數值格拒絕；truthiness格接受 |
| nil | 0 | 0 | 本工具不採用隱式型別轉換 |
| 空string | 數值解析失敗→0 | 1 | 一般字串及truthiness格拒絕；FinalMusic例外另述 |

表中的nil必須確實佔有一格，不能套到任意missing args。嚴格作者政策要求有限signed32整數、有限且不超最大float32的數值，拒絕boolean、數字字串、非整數、小數整數捨入、NaN、Infinity、溢位及超大整數。float32政策允許轉換捨入、subnormal及underflow；它只證可採用的數值輸入範圍，不承諾非零物理位移、動畫時間或幾何效果。這些屬較窄的工具政策，不能說原native本身具有同樣的拒絕檢查。

### 2.3 字串需保留payload及encoding條件

新作者拒NUL、孤立Unicode surrogate與一般空字串，以免JSON長度與Client窄字串consumer不一致。這是作者政策。JSON Unicode並不等於指定KR codepage、資源path bytes或原遊戲文字encoding；非ASCII輸入會保留 `STRING_ENCODING_UNPROVED` 警告。資源選中、文字內容與path大小寫／byte身分由資源契約處理，不由字串type PASS代替。[ABI、AV_REPORT]

## 3. 回傳用途與所有query採用範圍

121正常closure均以EAX=1作C callback結果個數，只有17個binding／marshaller另寫tag3、數值並將top加16。其餘104個不建立新值，因此呼叫結果不得作spawn ID、完成ACK或操作成功。它們在研究計畫僅允許 `discard`；原Lua若要求結果，可能得到既有stack值，不能把名稱語意補成新producer。[ABI]

16個query均是**number**。Lua的number0仍是真值；條件必須按個別語意作明確數值比較，不能以 `if query() then` 當真假或世界完成。下表是逐來源的採用範圍；完整receiver、writer、參數、歧義與context token在機讀catalog。[OBSERVATIONS、EVENTS_NATIVE]

| query | 實際觀察來源 | 作者／Server不可外推事項 |
|---|---|---|
| `lb.GetTime` | Client本機時計數值 | 不是Server時間或網路序號 |
| `Tutorial.IsSynopsisSkipped` | 指定序章skip旗標 | 不是所有scene的通用跳過結果 |
| `Tutorial.IsCutSceneRunning` | Q owner active；帶lazy-init | 不因getter存在就證該內容已成功啟動 |
| `Tutorial.IsCharacterAvailable` | 固定roster entry index2 | 形式整數參數不選任意角色 |
| `Tutorial.GetControlStatus` | controller+B4+4×index | 只採0..31既有layout，不是任意world state |
| `Tutorial.GetTutorialState` | controller+134 | 是教學UI state |
| `Tutorial.IsIsiliaFound` | 固定u16 world key F000及幾何／畫面條件 | 不是任意NPC存在查詢 |
| `Tutorial.CheckLeader` | leader actor+88 WORD與3比較 | 不接受任意model/key選擇 |
| `Tutorial.IsLeaderDialogOpened` | 教學UI owner+38旗標 | 不代表任意對話資料已播放完成 |
| `Tutorial.IsScenarioEnded` | owner+4 map按key取DWORD | 特定scenario旗標，不是全世界事件stream |
| `CameraWorks.IsEnded` | 當前camera work predicate | 無current等分支需保留歧義；不代表owner釋放 |
| `Q.IsCutSceneRunning` | Q owner+28 | 不證清場、資源回收或Server進度 |
| `Q.GetLeaderPosN` | local vector分量0/1/2 | selector無效也有0；新作者拒其他selector |
| `Q.IsAllObjectsStopped` | Q私有actor tree的movement bit | 不等死亡、受擊、碰撞或清波；空集合分支需保留 |
| `Q.IsPrologRunning` | Prolog owner running DWORD；lazy-init | 不等Server敘事狀態或所有效果完成 |
| `Q.IsBookFlying` | 固定Book owner+74；lazy-init | 不選任意書本、圖片或物件 |

工具的 `read_number`／`compare_number` 必須標明 `LOCAL_OBSERVATION_ONLY` 並附精確context token；比較運算子和值必須明示。**context token只是一個研究範圍標籤，不能證明真正receiver、typed identity、當前scene或owner合法性**。即使拿正確token填入計畫，remaining gates仍未解除。

第17個producer是 `lb.DoFile`。原件 `4A1230` 開啟失敗回0，`6F4C20`執行成功也回0；數字0不能單獨證明已載入。工具只准 `LOADER_DIAGNOSTIC_ONLY` 記錄，拒將任何數字比較提升為成功predicate。大寫全域`DoFile`是另一個入口，不能交換其current-state／0/1契約。本題未展開新版loader協定；當次export、version與phase仍須沿既有入口規格。[ABI_REPORT、ABI_NATIVE]

四stub為 `Q.DeleteObject`、`Q.BalloonTalk`、`Tutorial.InsertObject`、`lb.PrintCurrSceneID`；`lb.GetObjectCount`不提供可採用的count。工具全數拒絕作功能入口。`Q.Book`雖接受整數也不以該參數選任意書本；其ignored-selector警告不等功能停用。[ABI、FUNCTIONS]

## 4. 前輪勘誤的完整採用

`errata-adoption.json`原樣保存15個published entry的path／location／status／反證與修正，再加本題採用動作；followup三項已在這15項中去重，未重寫歷史檔案或改歷史PASS。

1. **FlyingObject先取消舊追蹤圖。** `56496A`先呼叫`564A60`，之後才配置／發布新圖。串行A→B時A已被取消，不能沿用「只覆蓋handle造成A未取消」的舊模型。若需求同時多張持久圖，Q這個單一追蹤入口仍不提供並存保證。取消、alive=0、manager合格pass與物理釋放是不同時點；Del也不是全共享owner sweep。[REUSE_ERRATA、REUSE_NATIVE]
2. **歷史SYN PASS不能修正原生語義。** 舊模型及舊測試的錯誤前提被撤銷；原本完整ASM已含取消call，字節不需要改。本題的兩次FlyingObject fixture只驗工具輸出兩次替換效果，不宣稱實際執行或回收。[REUSE_ERRATA、REUSE_MODEL]
3. **parser版本固定依Git實存內容。** 不沿用舊aggregate的錯誤PARSER_SHA。本題先核內容hash才匯入資料reader，沒有聲稱那份舊aggregate重跑PASS。[REUSE_ERRATA、LUA_PARSER]
4. **Doll引用與level租約分開。** 正常保留Doll有獨立R+5C引用、有效request可回載同R、release對稱，原D callback有強持有；不能僅由level3減少推論保留actor必然失去資源。層級event不等全queue drain，zero-Doll投影只能用於沒有Doll／其他引用的情況。[REUSE_FOLLOWUP_REPORT、REUSE_FOLLOWUP_NATIVE、REUSE_FOLLOWUP_MODEL]
5. **實際direct caller優先於其他receiver的槽。** Q.CreateObject在56322E直接call4D0FE0，4D0FE1 push1傳共同初始化；不能把base/Q vtable+30→4C8050→4C7DF0(actor,0)外推成實際Q一律非immediate。槽本身原事實仍保留。[REUSE_FOLLOWUP_ERRATA、REUSE_FOLLOWUP_NATIVE]

本題對上述published語意採用精確範圍，來源byte核對不升級整函式FULL-PASS。完整資源租約與收尾交接由本批兄弟分題接合；本題沒有以ABI接受取代那些gate。

## 5. 原件審閱：保留真正語句與helper層

### 5.1 實際原SEQ，沒有把JSON當官方MEF

從固定Event.stp解出Q119/3的 `Event/Sequences/Phindous_YuriandRazed_Boss.seq` 與Q2440/5的 `Event/Sequences/Aisen_01_After.seq`。這兩份選定原SEQ實際只有ASCII bytes；本題強制核此事實，再由資料lexer審閱，不猜一般Client文字codepage。每個call保存line、名稱、引數數量、層級、helper prototype、精確arity與TRUE/FALSE來源符號；只納少量必要語句摘錄，不將完整member放入此包。

Q119/3有46個body call、Q2440/5有62個，均另有top-level `Register`，兩者各到達31個qbase helper。`wait`是外部coroutine/helper範圍，不計入121正常binding；`Register`不是scene body操作。詞法工具排除`function`等關鍵字，因此 `Register(function() ... end)` 不會多計一個叫做function的callee。完整資源集合與原SEQ控制形式由資源分題另作全token解析，本題call metadata不聲稱通用Lua parser。

### 5.2 Boot原件正向補證與mutable global邊界

本次找到已保存於Git的KR原chunk，source-map明確映射至 `kr-temp-roy/T16-local-20261028/evidence/resources/kr/` 原路徑；不是TC或新產生替代版本。三份內容分別為179 bytes Boot、56 bytes Logic、2168 bytes Coroutine。精確Git blob、SHA256、source-map entry及prototype見 `bootstrap-global-contract.json`。

原native loader call順序為 `560796 Coroutine.lua`、`5607A2 Boot.lua`、`5607AE Logic.lua`、`5607BA Event/qbase.lua`，均經`6F4A50`。Boot根prototype前四字碼是 `LOADK R0 number1; SETGLOBAL TRUE; LOADK R0 number0; SETGLOBAL FALSE`。故**原Boot這四條實際執行後的初始值為number1／number0，並非Lua boolean**。後面的math隨機初始化呼叫與其成敗不能倒轉這段已執行的前綴。[PARSER_NATIVE、BOOT_CHUNK、SOURCE_MAP]

Logic一個RETURN；Coroutine13個prototype。加上完整解析qbase、TutorialBase、TutorialMain，所選原prototype的直接TRUE/FALSE讀取分別22／0／24處，未見直接SETGLOBAL覆寫。此有界掃描不排除其他載入內容、計算式table寫入、debug hook或後續runtime替換；Git中的原件也不等於某台實際Client當次選到這些bytes。已解除「缺Boot原件」這個材料阻塞，保留實際載入／後寫條件，不能把沒有命中BIN字串或qbase未賦值誤報成Client未定義常數。

### 5.3 Create、Walk、Talk的真實轉接

原 `CreateObject` P62有9參數。第6參數若Lua-equals number0就變1；第7參數以**typed equality**比number0：相等時先寫global `isVisible=number1`，否則寫number0，再讀回作native第7格。該格native型別是integer32，**不是lua_toboolean**。[helper-bridge-evidence.json P62、ABI Q.CreateObject]

| 原helper第7參數 | 等於number0？ | native第7整數 |
|---|---|---:|
| Boot `FALSE`，且仍為number0 | 是 | 1 |
| 改成Lua boolean false | 否 | 0 |
| 明確nil | 否 | 0 |
| Boot `TRUE`，且仍為number1 | 否 | 0 |

因此把原FALSE「現代化」成JSON／Lua boolean false會改變可見性；本題保留原符號及條件，不默改原SEQ。第9參數非零是item／appearance語境，不能當另一Q slot、world ID或直接資源號，完整typed解析交給資源契約。[ACTOR_REPORT、本批資源分題]

原 `WalkObject` P26的7參數轉為native6參數：原1、2、3、5、修正後6、P25轉換後7。原4 direction不轉送；原6的number−1改成4。P25 speed-step 0→1、1→1.2、2→0.5、3→0.25、4→0.125、5→0，其他走診斷並回1。這是helper層原語義，不是native允許多一個引數。[MOVEMENT_REPORT、helper-bridge-evidence.json P25/P26]

預掃描是不同綁定：`55D6A0`暫將全域WalkObject綁到`55CED0`，其 `55D188 test/jns` 對任意負整數改4；正式qbase P26只有number−1改4。不能為了兩層外觀一致就統一成同一規則；本批資源分題保留prepass action與formal action各自來源。這個差異也說明預掃描PASS本身不能代替正式helper語意。[本批 content-dependencies 原prepass_walk證據]

`OpenTalkScene` P17、`OpenAutoTalkScene` P18在native第三格分別用實際 `LOADBOOL true/false`；它們不是從Boot TRUE/FALSE取值。另將global TRUE寫入g_scenePlaying，然後WaitForScene。`PlayMusic` P21前加字面`Sound/`，將global TRUE當native整數loop flag，並yield。`FlyingObject` P38七格直傳再yield，並不因此取消原native先取消舊圖的所有權規則。[helper-adoption-rules.json]

### 5.4 全75 helper資料流工具的保證範圍

原75 helper全部建立CFG與有限名稱集合的reaching-definition。每個前驅的可能值合流；只在所有到達來源都得出唯一已知global/member名稱時記正向callee，否則UNKNOWN。`SELF`同時覆寫A與A+1；CALL／VARARG多result、FORLOOP A/A+3、TFORLOOP result範圍均做kill。TESTSET保守unknown；nested CLOSURE與SETLIST C=0延伸資料字明確拒絕，不能拿線性指令序假裝完整CFG。

目前選定75 helper實際包含17種opcode：ADD、CALL、CONCAT、EQ、GETGLOBAL、GETTABLE、JMP、LE、LOADBOOL、LOADK、MOVE、MUL、RETURN、SELF、SETGLOBAL、SUB、TAILCALL；沒有上述nested closure／VARARG／FOR／SETLIST複雜構型。逐prototype coverage保留於機讀audit。SYN反例涵蓋不同branch callee合流、同callee所有前驅、一個前驅被kill、SELF第二格、VARARG／FOR多格kill及拒絕未知構型。這是名稱來源分析，沒有執行Lua運算或證明執行期global永遠未變。

結果有76個正常native callsite；唯一arity差異是 `RevPhase1` P74 PC38 的 `Q.EndSepia()`。`BalloonTalk` helper仍指向已知stub；它在全helper索引中列明，不包裝成有效功能。

## 6. 原零參數EndSepia：證明得到0，而不是停止於拒絕

兩原scene均透過收尾helper到達此例。新作者預驗器依exactarity拒絕零參數；原件的實際native輸入則由下列完整有界鏈決定。精確原指令、來源及假設見 `zeroarg-endsepia-contract.json`。

| 步驟 | 原件錨點 | 可證推導 |
|---|---|---|
| 原呼叫 | P74 PC36..38 | GETGLOBAL Q、GETTABLE EndSepia、CALL A0 B1 C1，零user args、零requested results |
| VM CALL | 6FD029..6FD045 | B=1令L.top=callee格+16，再將callee與L傳precall |
| C分支 | 6FE1C6、6FE1EC、6FE2E6..360 | 函式tag6且是C closure；ci.base=func+16；ci.top=L.top+320，不能將ci.top誤讀為L.top |
| 可能成長 | 6FDCB0→6FDC30；6FDD90→6FDD10 | stack的top及func保持同一相對位移；CI成長只搬CallInfo |
| closure | 56A100→56A430 | 同一L傳marshaller，不新增Lua引數 |
| 索引 | 6F510F..6F5115 | −1→L.top−16，正好是callee函式格，不是nil |
| 數值轉型 | 56A447..56A499 | tag6不等number3／string4，走明示push native integer0 |
| consumer | 565600..565639 | FE36D4設4、FE36DC bit1設起，兩分支均寫FE36D8=0 |

stack成長使用 `700880` allocator wrapper；原stateconstructor `6F7528`設default allocator `6F7170`，該路至`897A66`，原PE import精確映射 `BD21E0→KERNEL32.HeapReAlloc`。本題只閉合正常分配保留現有stack內容這個必要邊；未展開無關CRT/error handler。分配失敗或stack錯誤不算成功到達native。

結論限定原registered C binding未被替換、frame有效、正常allocator回傳、沒有修改stack/callee的debug hook。新state hook mask初值為0，不推論後續絕無修改。這些條件下原例**確定傳0**，不能停在「原件arity不符，所以值未知」。同時不能由一個特定zeroarg CALL推廣所有missing arg都等nil／0，亦不能將FE36D8=0直接寫成畫面立即全部清除；視覺phase／清理仍依生命期分題的consumer與pump證據。

## 7. FinalMusic與圖片的作者規則

原Q119/3確有 `SetFinalMusic("")`。既有strict工具一律拒空字串，這是過窄的作者政策，不是原consumer認定非法。Native `565560`檢空指標、首字元分類，再走append／clear；空字串append長度0，因此**保留原值**。一般非空名稱是append，重複呼叫可能拼接，不是替換；RestoreMap另行消費最終值，不是setter立即播音樂。[AV_REPORT §5.5、AV_NATIVE M24/M25]

Accepted Start在 `561A17→402A70`是assign空值，真正清空；setter `5655A6→401FC0`是append。兩條路不可混為一談。本工具只為 `Q.SetFinalMusic`允許空字串例外並輸出retain效果；其餘一般字串政策保持非空。literal ASCII space採為clear標記但保留 `CTYPE_CONTEXT_UNPROVED`：本批生命期原件核 `895541 [D62868]→BD3CA8`、`BD3CE8 WORD0048`含bit8，且有 `F8CB10` locale分支。這是default窄字元分類條件，不推Unicode whitespace；其他起始空白一律拒絕為未採用policy。[本批 execution-lifecycle/native-evidence.json N06/N07及default_ctype資料]

圖片採用原先取消舊再建立的勘誤。工具只檢七參數ABI並宣告替換效果，不用未證的完成token。原Q2440/5的fade-out count0保留原樣；生命期分題已證phase4在remaining<=0時跳過除法而進alpha0／phase0，不能因看到0就報原件一定除零。本題沒有另加「全部fade必須>0」政策。有限hold、holdForever、manager pump及離開／取消的完整契約仍須過生命期審閱，ABI PASS不取代它。

## 8. 舊預驗器的漏判與本題改進

既有 `validate_calls.py`的數值／bool／arity／stub／producer骨架成立，原稿保持不動。它沒有提供完整採用封裝；本題另建獨立工具，差異如下。[OLD_PREFLIGHT]

| 既有工具邊界 | 本題處理 | 屬性 |
|---|---|---|
| 不固定target/schema，容許空calls | 原BIN與ABI內容hash、非空call集合、固定schema／NOT_NATIVE_MEF | 工具契約 |
| 允許未知欄位及省略result_use | 每層exact fields、明示result模式 | 工具契約 |
| 定義讀取不先固定hash | runtime_input資料先驗SHA／bytes，污染副本必拒 | 來源身分 |
| number讀取沒有逐query範圍 | exact context token＋明示本地用途＋數值比較；仍不證runtimeowner | 原生範圍與工具政策 |
| loader僅一般warning | 只記診斷，禁止將比較當成功predicate | 較窄作者政策 |
| 一般empty string全拒 | 只為FinalMusic採已證retain例外 | 原件相容修正 |
| 不處理重複JSON key／非標準NaN字面 | strict JSON拒重複key、NaN/Infinity、孤立surrogate key；溢位指數由數值gate拒 | 工具輸入邊界 |
| 原helper／SEQ與native分層不在工具中 | 另建原件只讀review與helper轉接契約 | 研究輸入分層 |
| 舊圖片模型曾有反向前提 | 採完整勘誤，保留原歷史結果 | 證據優先 |

工具status只有 `REJECTED` 或 `AUTHORING_CONTRACT_PASS_ONLY`；無論哪個結果，deployment_ready、gameplay_verified、client_executed、lua_executed、server_executed均為false。對巨大integer、1e309變成非有限float、未知數值object及非string result mode有實際反例，未以未捕捉例外當錯誤處理。

## 9. 驗證結果與實作交接

`verification-result.json`為本題實際收據。驗證器核所有固定Git blob與SHA、原BIN／Event、重跑原ABI完整驗證、對採用窗口比原BIN、重建兩原SEQ metadata／75 helper／bootstrap資料、重現新增9窗口1044 bytes與HeapReAlloc import、檢查精確EndSepia／Create反例、逐檔產物hash。SYN部分是44作者案例、4 strict JSON拒絕、2數值shape、1來源污染拒絕、9資料流構型、1匿名function詞法案例及4 typed Create對照。這些驗證範圍不是Client執行、Server測試或全文FULL-PASS。

Server實際採用仍屬待開發：把typed content identity、合法入口／pump、資源依賴與preview/formal一致性、owner acquire/release、正常收尾與二次執行、可用事件來源與業務進度接入現有內容流程。沿包根 `SERVER-ADOPTION.md`的REQ-0019／REQ-0021去重接收，不新造同義需求或狀態。`preflight.py`可以作其中一個只讀階段，但其輸入是研究sidecar，不可直接塞進現行產品schema，也不能由工具PASS自動設定ready。

本題沒有尚未查完的必需Client靜態缺邊。保留的是明確適用條件與其他責任：實際安裝資源／codepage／loader選中內容、後續global或hook變更、完整資源與生命期組合、Server規則及原Client正常遊玩驗證。需要解除的是對應的真實選擇內容／runtime條件或Server實作證據，不再要求已於Git找到的Boot三原件。兄弟分題的同批證據由包根固定hash；所有正式T01／RR／S00狀態維持原值。

## 10. 固定來源入口

- **ABI／ABI_NATIVE／ABI_REPORT／ABI_VERIFY／ABI_SUPPORT**：前輪 `MEF-comprehensive-contracts-20261117/abi/`，全正常表、33marshaller及原生轉型／結果產生。
- **OBSERVATIONS／EVENTS_NATIVE／EVENTS_REPORT**：前輪 `events/`，16個query的typed owner、writer與歧義。
- **FUNCTIONS**：前輪 `function-map/function-coverage.json`，每名稱功能與限制。
- **REUSE_ERRATA／REUSE_NATIVE／REUSE_REPORT／REUSE_MODEL**及**REUSE_FOLLOWUP_***：前輪勘誤、原件及引用／回載followup；原歷史資料保持不動。
- **AV_REPORT／AV_NATIVE**：`MEF-capabilities-20261116/audiovisual/`，FinalMusic setter及RestoreMap consumer。
- **ACTOR_REPORT／MOVEMENT_REPORT／HELPERS**：原演出actor、Walk helper與75 export索引。
- **PARSER_REPORT／PARSER_NATIVE／LUA_PARSER／STP_READER／LEXER**：固定原loader與只讀資料parser／lexer。
- **SOURCE_MAP／BOOT_CHUNK／LOGIC_CHUNK／COROUTINE_CHUNK**：精確KR原件身分與已保存原bytecode；本題只讀不複製完整原件。
- **SUPERVISOR_NATIVE／SUPERVISOR_REPORT**：`MEF-control-flow-20261116/supervisor/`，VM CALL及C precall原件。
- **VERIFIED_INDEX／BULK_REVIEW_POLICY**與其他manifest條目：既有驗證／復用邊界。完整path、commit、Git blob及SHA以 [source-manifest.json](source-manifest.json)為準。
