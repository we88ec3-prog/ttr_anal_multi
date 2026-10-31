# T08-204 — Monster／NPC Actor → CDoll 資源、場景更新、可見性門檻、B-queue／繪製介面消費（原始KR BIN-first深度研究）

研究者：chatgpt-web roy；研究時間：2026-10-31 17:15:02 Asia/Taipei。範圍：T08-204-01～05（有界Client靜態研究）。原件：唯讀 KR Tartaros.bin，12,472,320 bytes，SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91，本輪本地sha256sum吻合。PE32 .text VA0x401000/file raw0x400，所以 code raw=VA−0x400C00；.rdata VA0xBD2000/raw0x7D0600，所以資料 raw=VA−0x401A00。所有函式地址均為真PE VA，由objdump -d -M intel從有效入口重新反組譯並與原始bytes核對；沒有執行、附加、修改Client。

## 0. 固定研究終點與歷史證據邊界

開工核對 GitHub main@679cbc10c1775490aefe0f24548f22d3d593a6d1、AGENTS、T08 README及task.json、T01退回、shared verified knowledge、T08 S00 inbox/RR（無待處理RR），並於既有t08/roy/chatgpt-web分支非強制同步最新main。T08-203已證本地接收index7、26byte Actor row、CMonster type1→4D1710、CNPC type6→4D2120與主樹登記。T08-201及T08-202有CDoll/Controller/B-vector以前的研究；對PE錯偏修正後只沿真原始BIN核對，不重用尚未驗的raw0假函式。

本段五項：204-01 Actor到Avatar/Model/Render持有者；204-02 首次進update及render候選、下游consumer；204-03資源數值key與資產查找界線；204-04不能顯示、延遲及失敗；204-05交T06/T07/Server。完成條件為至少一條CMonster及一條CNPC的有條件「Actor建立→scene/image consumer」原生鏈，加上失敗及跨Task界線。嚴格不等同於已在實機看到GPU像素、已還原全部模型檔名或官方Server生成規則。

## 1. 204-01：兩個原生Actor的特定入口合流到同一CDoll建立函式

在本地index7 4AE4D0處理26byte row時，建立Actor、寫入位置狀態後，在4AEB78～4AEB7D以Actor primary vptr+0x30派送特定初始化。此步驟位於4AEC03→4DFF30主Actor樹插入之前；因此建立Actor主樹記錄不保證模型已可見。

|本地type|原生類別、ctor / primary vptr|vptr+0x30|真入口call及差別|
|---|---|---|---|
|1|CMonster，4D1710 / C0C9DC|4D1910|4D193E E8 AD 64 FF FF →4C7DF0，模式參數0|
|6|CNPC，4D2120 / C0CA9C|4D2820|4D2827 E8 C4 55 FF FF →4C7DF0，模式參數1|

兩類採同一4C7DF0但不同mode；NPC有附加初始化，不能聲稱兩類完全等同。具體共用根CFG：

    4C7E21 39 BB 70 03 00 00   cmp [Actor+0x370],EDI=0
    4C7E27 0F 85 09 02 00 00   jne 4C8036；已設定即跳過此setup
    4C7E2D 8B 83 8C 00 00 00   mov EAX,[Actor+0x8C]
    4C7E39 8B B3 88 00 00 00   若零用[Actor+0x88]當候選數值key
    4C7E3F 68 70 01 00 00      push 0x170；配置CDoll本體
    4C7E5D E8 EE CD 2D 00      call 7A4C50；建構CDoll，參數為key低16bit
    4C7E7B E8 E0 25 00 00      call 4CA460；控制塊
    4C7E80 8D BB 5C 01 00 00   lea EDI,[Actor+0x15C]
    4C7E92 E8 C9 90 01 00      call 4E0F60；移入CDoll* + control block
    4C7ECC 0F B7 8B 88 03 00 00 movzx ECX,word [Actor+0x388]
    4C7ED9 E8 C2 EF 2D 00      call 7A6EA0；資源/鍵控查找處理
    4C7EDE 80 7D 0C 00         cmp byte [mode],0；NPC才走附加支線
    4C7EED E8 7E 0F 2E 00      call 7A8E70；NPC額外resource/狀態
    4C7F02 C7 83 70 03 00 00 01 00 00 00  mov [Actor+0x370],1
    4C7FBD C7 40 24 01 00 00 00  mov [auxiliary+0x24],1

Actor+0x15C/+0x160從本函式是帶refcount控制塊的shared持有者，不是保證CDoll永不被其它owner釋放。後半另配置0x30輔助物件裝Actor+0x368；其欄位與CDoll、owner P（0x2C）及Controller三個raw Actor槽不可混淆。構造函式7A4C50設CDoll原生多重介面vptr：

    7A4CA5  [CDoll+0]=0xC4F67C     primary
    7A4CAB  [CDoll+4]=0xC4F690     embedded interface
    7A4CB2  [CDoll+8]=0xC4F6B0     other embedded interface
    7A4CB9  [CDoll+0xC]=0xC4F6C0   B-vector entry subobject
    7A4CC3  [CDoll+0x1C]=0         no active resource yet
    7A4ED0  [CDoll+0x124]=0        not yet marked eligible

本次原始.rdata讀出CDoll primary vptr C4F67C+8=7A63C0、CDoll+C secondary vptr C4F6C0+4=7A8310及+8=7A8E10；CDoll+8 secondary C4F6B0+8=7A57C0（不同的資源清理函式）。錯把vptr偏移視作同一this或將完整DWORD減0x400，會重現歷史錯誤。

## 2. 204-03：數值key→資源registry，外觀檔名尚無原生一對一證明

CDoll的建構key取Actor+0x8C（為0則+0x88）後按低16bit傳入7A4C50，保存於CDoll+0x18。7A6EA0將這個key送到鍵控容器：

    7A6EFB 8B 43 18                mov EAX,[CDoll+0x18]
    7A6F08 B9 90 0E FC 00          mov ECX,0xFC0E90
    7A6F0D E8 7E E8 D6 FF          call 515790；lookup
    7A6F15 3B 05 94 0E FC 00       cmp EAX,[0xFC0E94]；sentinel
    7A6F1D 8B 50 10                mov EDX,[node+0x10]
    7A6F20 8B 42 54                mov EAX,[EDX+0x54]；payload resource
    7A6F23 85 C0                   test EAX,EAX
    7A6F27 83 B8 BC 00 00 00 00   cmp dword [EAX+0xBC],0
    7A6F3A E8 D1 9B FF FF         call 7A0B10
    7A6F5C E8 6F A6 FF FF         call 7A15D0
    7A6F6F E8 EC 31 D2 FF         call 4CA160
    7A6F8B C6 43 28 01            mov byte [CDoll+0x28],1

存在查找缺失/特殊payload條件可跳過資源及CDoll+0x28標記；因此「CDoll已配置」不等於「外觀key已成功解出資源」。原生可證FC0E90是以CDoll key查的容器，**尚不足證明它就是模型檔名registry**或能把key寫成某個mesh/texture/motion的完整名稱。後期0x7A90F0的空模式分支7A9141將CDoll+0x1C清0，而另一條路7A91B5寫入非零resource pointer，靜態caller候選0x79DC5E、79EA6A、79EC3C；其完整外部資產服務/檔名解析交T06，不猜不存在的檔名。

## 3. 204-02：Monster與NPC均有真更新consumer，條件性CDoll visual tick

主vtable現場值：

|type|vptr+0x20 更新|vptr+0x24 時間更新|vptr+0x30 setup|
|---|---|---|---|
|CMonster（C0C9DC）|4D1AE0 = E9 9B 6A FF FF →4C8580|4D1AF0（條件進4C87D0 /7A5BB0）|4D1910→4C7DF0(mode0)|
|CNPC（C0CA9C）|4D2890；4D2894 E8 E7 5C FF FF →4C8580，後有NPC額外處理4D2360|4D28C0；4D2A2A E8 A1 5D FF FF→4C87D0|4D2820→4C7DF0(mode1)|

共同Actor更新函式4C8580有4C85AD call4CA890、4C85BE在條件下寫Actor+0xAC=1、4C85C8 call4C89A0、4C85CD經[FBA7A4] Controller取候選Actor（vtable+0x20）、後續4C86DA call4C83C0並對Actor+0x364/+0x368及Actor+0x164起128個子狀態做有限更新。這是Actor物件的Scene相關更新與子資源consumer，不是GPU draw本體，也不能用它聲稱每個場景tick都派送這個方法。

進一步的共享 visual tick 4C87D0：

    4C87D9 83 BE 70 03 00 00 00 cmp [Actor+0x370],0
    4C87E6 8B 86 5C 01 00 00    mov EAX,[Actor+0x15C]；CDoll*
    4C87FA E8 51 D4 2D 00       call 7A5C50；條件到CDoll視覺更新
    4C887F E8 AC FD 2D 00       call 7A8630；transform/state
    4C8897 8B 86 68 03 00 00    mov EAX,[Actor+0x368]；auxiliary

7A5C50的CDoll visual stage在7A5C93測byte CDoll+0x28是否零、7A5CAE比CDoll+0x1C有效性，走成功路後可有7A5D71 call838860空間/狀態helper、7A5D81寫CDoll+0x124，也有7A5D9E另一條分支改寫此欄位，然後7A5DBA call7A86B0及7A5E65 call7D3030更新。**CDoll+0x124是從這條visual stage/其輸入得出的狀態，不是spawn封包直接寫的「visible」位元。** 純靜態不能對838860判定精確像素範圍/視錐角或其公式；若Scene還未派送更新，該狀態可維持ctor的0。

## 4. 204-02／204-04：CDoll有條件加入B-vector；真下游consumer至7A8310

入列者是CDoll primary vptr C4F67C+8=7A63C0。它在真 .text 中有兩個立即必要條件及更多resource/state gate：

    7A63ED 83 7F 1C 00          cmp dword [CDoll+0x1C],0
    7A63F1 0F 84 92 02 00 00    je 7A6689；no active resource
    7A63F7 83 BF 24 01 00 00 00 cmp dword [CDoll+0x124],0
    7A63FE 0F 84 85 02 00 00    je 7A6689；eligible flag=0
    7A65BE 83 BF 8C 00 00 00 00 cmp dword [CDoll+0x8C],0
    7A65C5 0F 84 A0 00 00 00    je 7A666B
    7A65D9 8B 35 38 A8 FB 00   mov ESI,[0xFBA838]；manager
    7A65E5 83 C7 0C             add EDI,0xC；CDoll embedded subobject
    ...                          manager+B4/B8/BC begin/end/cap及兩條grow分支
    7A6651 83 86 B8 00 00 00 04 add [manager+0xB8],4

即成功時追加的entry是指向**CDoll+0xC嵌入介面**的4byte指標，放入manager的B-vector；不是值拷貝整個CDoll、不是主Actor樹、不是CModel 22 buckets。因7A63C0是virtual函式，沒有direct E8不等於無法呼叫，但**本輪尚未定位每種Scene的真dispatcher對這個CDoll primary+8 slot的實際頻率**。

在B-vector消費者0x7BB240，本輪真PE CFG：

    7BB264 8B 86 B8 00 00 00    mov EAX,[manager+B8]
    7BB26A 2B 86 B4 00 00 00    sub EAX,[manager+B4]
    7BB276 C1 F8 02             sar EAX,2；ptr count
    7BB2DC E8 CF 00 00 00       call 7BB3B0；有條件排序/優先取樣
    7BB2F0 8B 8E B4 00 00 00   mov ECX,[manager+B4]
    7BB2F6 8B 0C B9             mov ECX,[ECX+EDI*4]；entry = CDoll+C*
    7BB2F9 8B 11                mov EDX,[ECX]；embedded vptr
    7BB2FB 8B 42 04             mov EAX,[EDX+4]
    7BB2FE FF D0                call EAX
    7BB330 89 9E B8 00 00 00   mov [manager+B8],EBX；logical consumer state

CDoll+C embedded vptr C4F6C0+4 真DLL內原生函式地址為**7A8310**，因此在此已知entry型別有效且實際被consumer選中時，確實派送7A8310。其自身還有resource/transform下游：

    7A8327 83 BB A0 00 00 00 00 cmp dword[embedded_this+A0],0
    7A8332 8B 43 10             mov EAX,[embedded_this+0x10]
    7A8335 85 C0                test EAX,EAX
    7A8347 8B 50 40             mov EDX,[resource.vptr+0x40]
    7A834A FF D2                call EDX；有條件drawable/resource介面
    7A8353 E8 D8 C0 02 00       call 7D4430；座標轉換/下游
    7A8362 8B 43 10             mov EAX,[embedded_this+0x10]
    7A8367 0F 84 FD 01 00 00    je 7A856A；missing subresource
    7A8385 E8 76 ED FF FF       call 7A7100；fallback transform

此為本204指定的**原生scene/image interface consumer**：從有效CDoll entry進到有資源/位置更新及virtual renderer的函式，而不只是Actor內存。另一分支還有7A85F6 call7BAA80後續draw候選。但不能以這段替代GPU API、實機像素或所有資產檔名驗證。

**重要legacy反證仍保持**：另一個CModel primary vptr+8=7D3470往全域[FB7740]的22個render buckets寫入，7D34D4讀resource+5C、7D34EB取bucket owner、7D3515改bucket。此**CModel**和本段的**CDoll**是不同物件與不同容器；目前沒有真原生因果證據可將「CDoll B-vector→CModel22 bucket」當成已證的必經路徑，不把歷史錯誤重帶回203/204。

## 5. 204-04：看不到或延遲顯示的具體失敗分支／安全邊界

|情境|真PE條件|Client可證的局部結果|不可擅稱|
|---|---|---|---|
|Actor已有ID但未完成模型|本地index7先call Actor+30 setup，之後才4AEC03主Actor登記；4C7E21另有Actor+370 guard|兩階段並非同一布林，主樹Actor可與CDoll可用程度不同|已顯示實際像素或必定重試|
|CDoll配置失敗|4C7E3F malloc0x170，4C7E64將0值包入shared holder後仍有7A6EA0 call|成功的資源鏈不成立，部分下游可能NULL使用|必定crash/安全rollback，無實機證據|
|0x30 auxiliary配置失敗|4C7F8A配置，4C7FBD對其+24寫1，局部可缺NULL guard|高風險無保護的解參照候選|已實測崩潰或資源洩漏|
|模型key registry缺失/無效|7A6F15 sentinel、7A6F23 null、+BC等branch|可跳過CDoll+28有效設置|外部asset一定缺檔|
|CDoll資源未激活|ctor7A4CC3設+1C=0；另一路7A91B5才寫handle|7A63ED不通過即不進本B-vector成功路|不可能有其它顯示路徑|
|visual state未算出有效值|ctor7A4ED0設+124=0，7A5D81/9E更新，7A63F7檢查|+124=0不會通過此producer|可直接命名是精確距離/視錐結果|
|resource+8C或extra+AC未滿足|7A65BE等其他分支|本producer可不入列|所有 renderer 永不顯示|
|queue沒有被frame consumer使用|7A65D9..6651 append vs 7BB240另一根consumer|可追出被消費時的多型callee，無法從static證同一幀|每幀定時與OS GPU完成|
|Actor已被刪而queue仍有借用子物件|前T08-202 命令26/81會觸發Actor/CDoll析構；B-vector用CDoll+C borrowed pointer|存在需查的跨生命期別名風險|已證UAF或必然沒問題（另交205/208）|

上述「不顯示」都限定**這條已驗B-vector路徑未達成功分支**，不是全Client所有可能Renderer的否定式窮盡。

## 6. 204-05：精確交T06/T07／Server規格／本地遊玩

|責任方|T08本段可交付原生證據|精確待補且不屬本段已證部分|
|---|---|---|
|T08|type1/6本地index7 Actor→特定mode 4C7DF0→CDoll/Actor+15C shared holder→7A6EA0 resource registry→vptr+20/+24 Actor update→4C87D0/7A5C50→7A63C0 gated B-vector producer→7BB240 embedded+4=7A8310 image consumer|新205研究Actor移除後CDoll+C借用entry及owner生命期|
|T06|key由Actor+8C（0則+88）取低16bit進CDoll+18，索引FC0E90/515790，node payload+54和其+BC gate；7A90F0/7A91B5晚期設CDoll+1C|依實際模型/貼圖/動作/mesh和資源容器，建立key→檔名→asset handle的精確對應、追0x79DC5E/79EA6A/79EC3C到0x7A90F0並確認Renderer API/外部DLL|
|T07|Actor+370、CDoll+28/+1C/+124/+8C、manager FBA838 B-vector+0xB4/B8/BC與其兩端多型函式，Actor vptr+20/+24|Scene ready/map load與frame tick/render dispatcher到底如何呼叫CDoll primary+8、何時7BB240 consume、首次可見及fail→retry/切圖順序|
|T02|local index7 /4AE4D0收到2+26N，type1/6後接本段Client路徑|正確wire framing與業務domain，不直接將local index稱為Server wire opcode|
|S00/Server待開發|Client對Actor ID、模型key、初始化資源/有效visual state有必要條件|原版Server波次、生成時間、資源發送時機與場景等待規則未證；相容Server用SPEC/ADR明確自訂而不冒稱官方|
|本地實機驗收|可觀察Actor主樹、Actor+15C、CDoll+1C/+28/+124/+8C、B-vector entry、7BB2FE/7A8310、資源名及最終GPU/窗口|合法取得完整原版Client依賴與資產，分別測Monster/NPC首次可見/不顯示、資源缺失、距離、切圖、再加入/清除；未執行不能寫PASS|

## 7. BIN核驗與正式段號狀態

本次對原始BIN**已實際執行** Python逐位元組核對腳本：
- 檔長和SHA256吻合；
- **58/58 code byte anchors PASS**，涵蓋兩Actor不同mode到CDoll與registry、可見性旗標、B producer/consumer、CModel隔離；
- **10/10 .rdata vtable DWORD PASS**：Monster/NPC各+0x20/+0x24/+0x30，以及CDoll primary+8、embedded+C+4/+8、embedded+8+8；
- **9/9 E8 rel32與1/1 E9 rel32 PASS**，直接call/jmp真目標已重算。此測試**不是整篇T01 FULL-PASS、asset檔名解析或GPU像素的證據**。
- 可重跑的腳本見同目錄 T08-204-native-pe-verifier.py，命令示例：python -B T08-204-native-pe-verifier.py /path/to/Tartaros.bin。

**2026-10-31 作者完成判定**：依204-01～05原訂有界目標，CMonster與CNPC均已追到有條件的Scene/renderer interface consumer（B-vector→7A8310），且資源缺失/不可見/延遲條件已以原生字段明列，因此**T08-204 = FINISHED (BOUNDED_CLIENT_STATIC_SCENE_STAGE)**。但**不是**「玩家已實機看到怪物/NPC」；資源key→實體檔名、全部scene dispatch/root每幀確證、GPU/DLL及玩家視覺驗收仍是明確跨T06/T07/本地待驗證。**T08全Task native_complete不變；T01原稿退回與FULL-PASS未自動解除；Server/S00/RR無自動驗收。**

下一個分析大段T08-205專注26/81/全場reset後Actor/CDoll borrowed B-entry與P/Controller/Scene引用生命期一致性，不重跑203的26-byte row或本204已核的CDoll資源/顯示候選核心鏈。
