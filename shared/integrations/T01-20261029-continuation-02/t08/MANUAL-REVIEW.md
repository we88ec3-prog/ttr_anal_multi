# T08-177／197／200 全文原生主張複驗

審核者：Codex T01 / review_t08_new；2026-10-29 Asia/Taipei。凍結基準 `fd8507169932ee9cb9d9362fcab07a5a3bd9bfa5`。原件為唯讀KR BIN，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。全文行號綁定各自 [frozen-sources.json](frozen-sources.json) 的blob/SHA，不使用檔名段號冒充版本。

本輪讀取三篇全文及全部17個碼塊：177有12塊（2個流程圖、10個組語窗口），197有2個組語窗口，200有3個組語窗口。574條組語／原始byte行均核對實際bytes、完整指令、明示operand寬度與函式入口可達性；這個機械核對**另於**以下人工資料流與主張裁決，並不代替它。全部逐行紀錄在 [code-block-audit.json](code-block-audit.json)。

全文原生主張裁決：177、197在其自訂邊界內FULL_PASS；200為PARTIAL（L11「索引」可能指鍵域或容器，尚需澄清），不是已證錯誤。來源作者的研究時間、工具執行敘述、輪次是否啟動等為歷史自述，未冒充本輪可原生證明的行為；原件身份、位址映射及Git來源身份已獨立核對。

## 對碼塊的完整處理原則

沒有跳過窗口尾端的截斷指令。177的L173/213/235/254/351/448/475只保存完整指令的前幾個bytes，但列出的mnemonic／operand與原件完整指令一致，本輪補出完整指令供重現。這些是原稿明示的有界窗口，不當成新的函式入口。197的L63及200的L171是4DFC60長指令的續行bytes，不獨立解碼；197的4DFC8D～8F、4DFD37及4DFCA8/AF為ret後填充或跳過的對齊NOP，已區分可達指令與padding。200 L90～91明示`.byte`的C2/04為窗口尾部原始bytes，完整指令實為4DFFA7的`ret 4`；原稿沒有把4DFFA8當合法獨立native指令。

每個碼塊均保留起止行、全文、內容SHA、每行實際指令、root入口與資料流摘要。原稿inline `text`流程圖逐條與其所引用完整根CFG對應，未以流程圖自己作證據。

## 177：模式、producer／consumer與ABI

### P177-A（L8、L13、L106；碼塊3）

PE `.text` 的VA為401000、raw為400、virtual size為7D01F0，raw mapping只適用該節區。`7B7FD0`以prologue開始，兩個normal return均為`ret 4`，其中尾端7B8025的完整bytes為C2 04 00。前一根7B7F30在7B7F9E有`mov ecx,0x10`（B9 10 00 00 00），7B7FA0落其立即數中。原稿L13關於先前錯入口的更正成立。

### P177-B（L14～16、L53～67、L107；碼塊1、3、4）

`7B7FD0`從stack+8取container到EBX；第一集合經[EBX]→[index+4]→[sentinel]遍歷node，對node+24 payload發出slot+4的virtual call。接著取[EBX+8]的另一個sentinel遍歷；**7B7FFE的ECX=1支配7B8006寫入，第二迴圈沒有任何改寫ECX或call**，故來源值不依caller。兩個正常出口皆寫container+30=1。

`7B8030`先取第二集合node+24到ESI，以ESI呼叫drain，然後清ESI+44；完成後才對第一集合payload發slot+8，最後寫container+30=0。第一／第二集合、payload、container的欄位來自不同pointer provenance，不能合成同一欄位／同一動態類別。原稿也未這樣宣稱。這完成RETURN173的所有+44 writer、入口與順序影響，而不是只驗一個立即數。

### P177-C（L17～18、L29～37、L41～47、L108/110；碼塊5、6及附錄B）

獨立全`.text`逐byte E8枚舉的九個目標數目依序為1、1、1、2、2、42、5、2、11；每一列callsite與5 bytes及附錄B的全部42筆均相同。七個rel32算式逐項重算相同。這些仍是raw候選；原稿有明確排除間接、tail、外部與全部CFG caller的宣稱。

兩個模式callsite在完整7AAD40與7AB020根CFG中確為可達call。前置push為立即值FE173C（欄位槽的**地址**），不是從該地址load的DWORD。drain的兩個E8 site為7B8045及7DD132；各自根CFG均保持ESI為所述owner。此有限的直接caller敘述成立。

### P177-D（L19、L86、L109；碼塊7、10）

7DD100入口將ECX存ESI，EDI=-1，`add [ESI+5C],EDI`，中間load EAX不改flags，因此JNE用的是減量結果。非零直接走尾端，零才drain、清+44及逐一以EDX傳name、ECX=[FE173C]呼叫7DC510。零路徑最後會重讀+5C作回傳；上游7B8090在回傳非零時跳過cleanup/free/index erase，零時才呼叫7DCF40、heap free及7B8680。完整callee根均核對，無「每次減量都free」誤判。+5C為唯一所有權計數未被宣稱完成。

### P177-E（L20、L71～82；碼塊2、8、11、12）

7DD1A0 stack+8是owner、stack+C是item，`cmp owner+44,1; jl`為**有號**mode gate。達門檻時push owner+64呼叫EnterCriticalSection，EDI=&owner+7C、EAX=&stack item交7BB350 append，再對同鎖LeaveCriticalSection；否則對非null item作7BD850及heap free。callee `ret 8`。

7A86B0根內的7A8741以及7BE5F0根內的7BE60F均先push resource，再push從resource首DWORD取得的owner，所以與callee ABI一致。7BE5F0輸入ESI是slot地址，第一次解參照取得resource；這不與actor registry owner同義。7BB350的alias／非alias分支、可選growth、DWORD寫入及end+=4已從完整根核對。未把失敗／exception／重入安全性宣稱完成。

### P177-F（L21、L90～94、L111；碼塊9）

drain入口以ESI+64作鎖；begin=[ESI+7C]、end=[ESI+80]，數量差SAR2。每輪先讀slot VALUE至EDX、push EDX呼叫7BE0F0，再重讀slot決定是否7BD850及heap free、slot清零；原稿L92的`push slot`依附錄與L82明示的值來源解讀為slot內值，不是slot地址。7BE0F0的完整根使用stack item、其+4/+8範圍與node+8 virtual清理，**不具預先null item guard**；原稿保留不能推定所有entry nonnull及再入行為未知，因此未暗中增加安全前提或虛構防護。

迴圈後重新load end，每輪亦重新load end，故不是固定snapshot大小。tail的`eax=ecx; eax-=ecx`和SAR、LEA保持EBX=0，push的第三參數長度為0。normal return後EBX+=begin再寫end=begin；空range原本已end==begin。原稿只認證這條實際資料流，不認證完整memmove實作或編譯器bug。根中沒有直接frame/time counter讀取；不能推定間接callback內也無時間源。

### P177-G（L98～100；附錄B）

完整4DFF30、4DFBC0、4DFE90根中沒有對7DD1F0的直接call。它們的E8候選caller集合與drain不同。4C7DB0與4C8360根中的4C7DB4/4C838C確實傳resource slot地址給7BE5F0；這支持有限接口bridge，不支持actor、resource、manager為同一owner。原稿明示沒有跨實例所有權／runtime／server政策結論。

### P177-H（L112～124）

合理推測及未知、後續工作均保留，不當成肯定主張自動驗過。特別是「沒有其他drain呼叫方式」、「每frame清空」、「唯一writer」、「所有權同一性」、「child concrete vptr」、「異常／thread安全」仍未知。全文沒有把這些未知逆轉成肯定承諾。這些邊界不否定已證的Client局部主張。

## 197：secondary key erase與main-tree predicate erase

### P197-A（L11；碼塊1）

4DFC30以ESI為owner，LEA EBX=&owner+18，ECX=EBX呼叫8438C0，輸出放stack local。比較node與owner+1C sentinel，未找到就直接return。全文L11的`[ESI+18]`以其附錄LEA明確限定為此內嵌容器位置，而非宣稱載入該DWORD當容器base。8438C0是有號比較版exact find；82EF00是主樹的無號exact find，兩者尾端都會驗候選key。原稿只宣稱兩個不同查詢入口，並未錯稱兩者皆lower-bound-only。

### P197-B（L12～13；碼塊1）

只在found分支讀owner+F8，先null test，再把其指向的首DWORD與stack key比較，等值才清owner+F8。payload=node+10的非null值直接push給89120C，然後7B6890 erase；此根沒有actor主vtable+14/+0 call。heap free的normal null行為及API出處另由原件IAT證實，沒有推其未知payload型別。

### P197-C（L14、L18、L22、L28～34；碼塊2）

4DFC90的LEA為EDI=&EAX-owner+8，sentinel=[EDI+4]=owner+C；不是owner+18次樹。對每個node+10 actor比較其DWORD+88與stack DWORD，匹配則virtual+14、reload／null test、virtual+0(1)、清payload並erase，然後用erase輸出iterator續走；不匹配走in-order successor分支。7B6890會先以49E6A0更新stack node到successor，記下原node，完成unlink/rotation/free後把successor寫到out iterator，與caller從EAX out-pointer載入下一node一致。沒有把已釋放舊node當next。

此new source已將RETURN196涉及的容器位置、sentinel、payload清理ABI、virtual/direct-free關係都改正；且L29明示是否共享物件未知，未繼承196以錯誤雙樹前提作的ownership推導。作者的舊196仍FAILED，這份新來源可作該return的修復版本，不需要求重發相同bytes。原稿未完成的實際動態類別／共享／異常／server／runtime範圍保持未知。

## 200：exact find成立，鍵域／容器語句待澄清

### P200-A（L11；碼塊1）

4DFF4C確實從actor+4 WORD零擴成DWORD，放入查詢key stack slot。actor+88則是另一個predicate欄位，不能視為同一key。**但是**L11「不是同一索引」可能指不同鍵域，也可能被理解為不同容器；原件4DFF56與4DFC96都指owner+8主樹，只有查詢方式／predicate不同。上下文沒有足夠明確斷言不同tree，故不確證FAILED、不建立NEEDS_FIX；全文PARTIAL，建議改為「同一owner+8主樹，actor+4 key與actor+88 predicate不同」。

### P200-B（L12；碼塊1）

82EF00先選key>=request的最小候選，尾端還在82EF3F/41/44拒絕request<candidate.key。結合前者candidate>=request，因此非sentinel結果是exact equality，不是lower-bound-only。4DFF67比較sentinel，只有absent分支配置18-byte節點（57EF20 copies key至node+C、actor至node+10）、82F200檢查樹位置／重複，透過44BD00接鏈與balance並遞增count。這個下游閉合支援「插入」而不只看call名字。

### P200-C（L13；碼塊1）

duplicate分支由4DFF90載入key、推key和format，call6EDB60，再return，沒有直接替換actor allocation或actor free。format原件bytes及CP949檢視、`WARNING: %s`和6EDB60完整根表明這是warning格式化／console消息路徑；不能把callee內部可能的buffer配置或間接日誌I/O等同replacement actor。原稿也只宣稱此分支沒有**直接**actor替換／free。

### P200-D（L14、L18、L22、L28～34；碼塊2、3）

4DFBC0用同一owner+8與82EF00查詢，再作三槽controller callback、actor+14／+0(1)及node erase；4DFC30則是另一個owner+18容器與不同payload清理。相同key協定與不同ownership責任均依原稿保留，duplicate actor的上游責任不推定。原稿對payload型別、所有權／runtime／server等未知沒有肯定完成；碼塊的每行指令、分支、填充、續行與尾端raw directives已全核對。

## 退回項與原稿版本的關係

RETURN173可由new177完整修復；RETURN196可由new197完整修復。兩個舊blob都保留FAILED，return項RESOLVED的對象是明確問題／新版本，不是把舊稿改判。200的lower-bound-only舊退回理由仍撤銷，新L11歧義不使舊錯誤理由復活。詳 [issue-resolution.json](issue-resolution.json)。

本輪不執行、附加或修改遊戲、不呼叫目標API，不改原稿、Task owner/catalog/native_complete，亦未commit/push。
