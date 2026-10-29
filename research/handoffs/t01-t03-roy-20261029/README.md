# T01：t03/roy/chatgpt-web 來源與有限主張整合

2026-10-29，T01 integrator。使用者指定整合 `t03/roy/chatgpt-web`。基準main：`5cb495f4561833e0a123bbded14b76266ac1f201`；來源head：`6dc876e84358c1f1ab343ce5b8899006574ddf26`。採[新T01風險分流方法](../../../governance/t01-integration-workflow.md)，不恢復318篇全文驗收門檻。

**19篇原稿已按精確blob原樣納入；本批來源收件及有限主張整合剩餘0篇。** 全部完成來源身份、有限範圍萃取與已知更正／衝突查對，狀態為CONFLICT_CHECKED。這不是整篇原生驗收、S00接受、SPEC_CONSUMABLE或可玩流程完成；新原稿全文歷史狀態仍PENDING。

- 原稿：LOGIN-01、LOGIN-02、T03-3～19，19篇，共283,064 bytes。檔案路徑、SHA256、Git blob SHA1及行數見[sources.json](sources.json)。只帶入研究原稿，未merge整個分支，也未帶入分支的`03-PROJECT-T03-INSTRUCTIONS.md`作為main規則。
- SRC-0329～SRC-0347進入[唯一來源索引](../../intake/index.json)。新增13項主張：11 PARTIAL、1 INFERRED、1 REFUTED；沒有新增NATIVE_VERIFIED或共用FULL-PASS。
- 共用framing／queue／receive-stage已和既有CLM-NET-0001～0006去重，建立10筆`additional_sources`引用；明示每份只支持的subset及未知，不改原主張品質或把它的可信度借給新原稿。
- [逐篇處置](source-dispositions.json)、[動作／引用歸併紀錄](actions.json)、[Server影響交接](server-impact.md)、[驗證結果](validation.json)。原稿與各Task owner／task.json／catalog、既有318版歷史台帳、RR、SPEC/GAP/ADR/TEST均保持。

## 逐篇的有限用途與衝突

| 原稿 | CLM／歸併 | 有限用途及必留限制 |
| --- | --- | --- |
| LOGIN-01 | CLM-CHAR-0003 | F42EF本地writer／consumer與dialog通知；事件ID、訂閱與投遞不等於wire opcode或批准 |
| LOGIN-02 | CLM-CHAR-0004 | 665150兩層gate、UI欄位與list-hit返回；59A520與5A6A28的通知gate不同，未知控件不命名 |
| T03-3 | CLM-CHAR-0005／0006 | 分支限定的70A roster gate與本地`42 00 XX YY`建構；其他578 caller不借用同一gate；回覆43／69仍為fixture |
| T03-4 | CLM-NET-0005追加引用 | FBA854 sender安裝／vtable+10／slot lookup／copy queue；零長返回1不等於入列，A0A4不稱queue length |
| T03-5 | CLM-NET-0001～0003追加引用 | guarded本地plain／encoded framing及mode fallback；framer基準是connection+501C，未驗實際session模式或wire送達 |
| T03-6 | CLM-NET-0005追加引用；CLM-NET-0013 REFUTED | transport API／completion導航保留；第78行的API位置標示有精確R2反證，不能作規範來源，見下節 |
| T03-7 | CLM-NET-0004追加引用 | header／decode／remainder；default4不是whitelist，checksum不符不直接推成整筆丟棄／不callback |
| T03-8 | CLM-NET-0006追加引用 | 804310／489920是getter，後接pool／queue；只支持canonical route的前段，未獨立證明4930E0，不能叫business dispatcher |
| T03-9 | CLM-NET-0009 | FC10D0 reader至worker間接callback；record欄位非自動opcode。804820為804740內部block，由T03-10釐清 |
| T03-10 | CLM-NET-0010 | parent+140使用／初始化參數來源；後篇14／19限定不是constructor或實例alias證明 |
| T03-11 | CLM-NET-0005追加引用 | outbound804A40→8061A0 scheduler；A094/A084/A0A4只保留數值更新，與inbound worker分離 |
| T03-12 | CLM-NET-0011 | 0..5 bucket／retry／callback／record回收；不保證所有資源失敗／例外路徑安全或無條件回收 |
| T03-13 | CLM-NET-0012 | 44-byte狀態複製、84/58/59預算與pointer／increment1分離；exact-byte scan不排除其他writer |
| T03-14 | CLM-NET-0010追加引用 | 48BE50取外部parent參數；區別sender C51748與worker vtable、另一57C配置物件不混認 |
| T03-15 | CLM-CLIENT-0004 | 保留局部virtual+48及out-slot觀察；其推向worker parent的業務橋接未成立，由16／18收斂 |
| T03-16 | CLM-CLIENT-0005 | 三push的pre-call別名算術；不把不同ESP狀態或post-call槽認成同一parent，COM release語意未知 |
| T03-17 | CLM-CLIENT-0006 | gate與FB9225分支的局部介面呼叫；未知IAT名稱由18補足，重複virtual offset不表示同一介面 |
| T03-18 | CLM-CLIENT-0007 INFERRED | GetAsyncKeyState／D3DX import支持Print Screen功能推論；不是選角S2C、精確COM類別或worker target證據 |
| T03-19 | CLM-NET-0010追加引用 | 外部parent／獨立transport的後續provenance審查；44D680介面失敗值80004005不當成Server拒絕碼 |

以上為R1可用的有限主張與source-derived信心，不是將原稿自述「原生已確認」原樣提升成T01 NATIVE_VERIFIED。碼塊、作者時間／輪次／Git動作保留原文，不主張本批已重跑全部指令、完整CFG或認證過去工具執行。已有原生深驗只在下述定向R2範圍使用。

## 精確R2與更正關聯

**T03-6 layout：** 原件PE import獨立解析，並對既有REA/Ghidra快取來源SHA及87條函式指令重新比對bytes。8068DE／8068F3給WSASend的OVERLAPPED是connection+A050；8068F7／806909給WSABUF是+A064。806961／80697A的+A0B8交給IAT BD2284=`InterlockedIncrement`，不是OVERLAPPED參數。保存[r2-evidence.json](r2-evidence.json)與[重現腳本](check_r2.py)；[T03正式退回專區](../../../kr/tasks/T03/README.md)登記`T01-RETURN-T03-006-LAYOUT-001`，待作者修正版／勘誤與新blob複驗。其他獨立支持的transport主張不因此全部撤銷。

**T03-15～18關聯：** T03-18主張的五個GetAsyncKeyState／D3DX import名稱另以同SHA原件核對吻合。這足以限制早期解釋的使用方向；未把功能推論自動升R3。保留15／16局部stack事實，排除把其圖形output當作選角回包或worker parent來源。作者已有後篇更正，未再建立重複NEEDS_FIX或反寫舊原稿。

**解析／狀態域：** 本地UI事件F42EF／578／70A、C2S payload 42、frame magic、record／bucket及HRESULT均分開。T03-7的copy／checksum文字須搭配T03-8的record+4分支與未直接檢查AL界線，不能當丟棄所有錯誤frame的保證。既有CLM-NET-0006／0008到4930E0的有限路由不因這批worker目標未知而撤銷，也不證明兩路是同一實例；alias仍未知。

## S00交接與剩餘工作

已有RR-0002（selection contract）、RR-0007（T03 response dispatch gate）、RR-0008（selection response→scene）可引用這些導航。它們仍QUEUED，T01不代認領或結案；本批T01收件箱無SUBMITTED／IN_REVIEW回報。沒有重複建RR或關閉GAP。

原版selection S2C opcode／layout／成功拒絕／scene key writer仍未知；沒有證明42→43／69、1001／1由選角回覆寫入、或原版Client可玩。由S00有具體設計阻塞時再定向派R2／R3；不以將這19篇全文重驗作為一般交接門檻。

**本批19篇新通道整合剩0篇；S00用途接受0篇／SPEC_CONSUMABLE0篇。** 既有318版是另一批來源：其中R1待萃取314版、歷史全文未通過315版，均未因本批19篇而扣減。
