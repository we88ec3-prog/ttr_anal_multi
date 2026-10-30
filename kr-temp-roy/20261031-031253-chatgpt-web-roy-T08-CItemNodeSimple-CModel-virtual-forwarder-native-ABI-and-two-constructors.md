# T08／T01 LEGACY 勘誤：CItemNodeSimple 虛擬方法轉送到 CModel+8 的真實 caller 與 CModel 配置鏈

日期 2026-10-31 03:12:53 Asia/Taipei，研究者 chatgpt-web roy。原生KR Tartaros.bin，12,472,320 bytes，SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。PE .text VA=401000 raw=400 ⇒ raw=VA−400C00；.rdata raw=VA−401A00；.data VA=D61000 raw=95E800。直接由原件比對DWORD、函式入口及E8。靜態資料，不曾執行遊戲。

相依新來源：kr-temp-roy/20261031-030908-chatgpt-web-roy-T08-LEGACY-152-followup-IRenderable-CDoll-CModel-bucket-producer-BIN-first-FULL.md（本次已提交，CModel+8 7D3470直接／經79A3C0寫全域bucket）；T08-152 RTTI PE勘誤blob 14813f82c72673a0ffe271dcdc23ad6abcb106f3。此來源補上之前僅看到 CModel vtable target、缺乏實際間接分派 caller 的**一段確定上游**，仍保持整體 LEGACY-MAPPING-001 NEEDS_FIX。

## 1. CItemNodeSimple RTTI 主表，slot+0x2C是真0x7FC360

直接讀原BIN：

~~~text
C5101C = C80CE8        MSVC RTTI CompleteObjectLocator (offset=0)
                        DWORDs 0,0,0,F8AEF8,C80CFC
                        TypeDescriptor.name = .?AVCItemNodeSimple@IS3D@@
C51020 = 7FC290        CItemNodeSimple primary vfptr +0 (wrapper)
C51024 = 7FC750        +4
C51028 = 7FC620        +8
C5102C = 7FC760        +C
C51030 = 7FC7B0        +10
C51034 = 7FC7D0        +14
C51038 = 7FC7F0        +18
C5103C = 7FC460        +1C
C51040 = 7FC530        +20
C51044 = 7FC690        +24
C51048 = 7FC740        +28
C5104C = 7FC360        +2C (THIS WRAPPER'S forwarding method)
C51050 = 7FC780        +30
C51054 = C80D34        NEXT CLASS COL (CItemNodeParticle), NOT a +34 slot
~~~

ClassHierarchyDescriptor C80CFC的原始DWORD為 [0,0,2,C80D0C]，解析baseArray後有 [CItemNodeSimple, CItemNode] 二筆。這只證類別命名／繼承關係與vtable擁有者，不證哪個Scene經由本slot分派。

**constructor／lifetime寫入**（非僅看vtable資料）：於真PE 7EF8D2，原生bytes C7 00 20 10 C5 00，將C51020寫到一個原本由7EF89E push 0x50、7EF8A0 call 891268配置的0x50 bytes物件；緊接著在7EF8DB把 [object+0x34] 初始化為零。另一個入口7FC2C0是destructor phase，在7FC2E7再次寫入C51020，並在7FC2F2/7FC307檢查/清理+0x34指標；因此+0x34是實際存活與回收欄位，不能把它當直接CModel物件內的+0x34。

~~~asm
7EF89E 6A 50                     push 0x50
7EF8A0 E8 C3 19 0A 00            call 0x891268
7EF8D2 C7 00 20 10 C5 00         mov [eax],0xC51020
7EF8DB 89 58 34                  mov [eax+0x34],ebx ; zero init
7EF90F 56                        push esi
7EF912 E8 99 0E 00 00            call 0x7F07B0 ; stores/refers node, must trace separately

7FC2C0 55 8B EC                  push ebp ; mov ebp,esp
7FC2E4 8B 75 08                  mov esi,[ebp+8]
7FC2E7 C7 06 20 10 C5 00         mov [esi],0xC51020
7FC2F2 8B 46 34                  mov eax,[esi+0x34]
7FC2F5 3B C3                     cmp eax,ebx
~~~

這兩個相互獨立的vptr寫點在原始BIN raw分別為0x3EECD4（立即常數起點，真code 7EF8D2）及0x3FB6E9（真code 7FC2E7）。只找到兩次 literal DWORD值，也不能把這種原始常數命中說成所有物件的runtime vptr狀態。

## 2. 0x7FC380 確定配置0xB8 bytes **CModel** 並保存到 CItemNodeSimple+0x34

本體入口0x7FC380有效，CE call 0x7D2DB0（CModel constructor）已核實。EBX是[EBP+8]、來自呼叫者的指標（被填入的wrapper/Node）；ESI=進入時ECX（獨立來源），這兩者**不一樣**：

~~~asm
7FC380 55 8B EC                  push ebp ; mov ebp,esp
7FC3A5 8B F1                     mov esi,ecx
7FC3A7 8B 5D 08                  mov ebx,[ebp+8] ; destination CItemNodeSimple*
7FC3AA 68 B8 00 00 00            push 0xB8
7FC3AF E8 B4 4E 09 00            call 0x891268
7FC3B4 83 C4 04                  add esp,4
7FC3B7 89 45 08                  mov [ebp+8],eax
7FC3C1 85 C0                     test eax,eax
7FC3C3 74 0C                     je 0x7FC3D1
7FC3C5 8B 4D 0C                  mov ecx,[ebp+0xC] ; model parameter
7FC3C8 51                        push ecx
7FC3C9 50                        push eax
7FC3CA E8 E1 69 FD FF            call 0x7D2DB0 ; CModel constructor
7FC3CF EB 02                     jmp 0x7FC3D3
7FC3D1 33 C0                     xor eax,eax
7FC3D3 8B 55 10                  mov edx,[ebp+0x10]
7FC3DD 89 43 34                  mov [ebx+0x34],eax  ; Node+0x34 = CModel*
7FC3E0 8B 45 14                  mov eax,[ebp+0x14]
7FC3E3 89 73 38                  mov [ebx+0x38],esi
7FC3E6 89 53 40                  mov [ebx+0x40],edx
7FC3E9 89 43 2C                  mov [ebx+0x2C],eax
7FC413 8B 7B 34                  mov edi,[ebx+0x34]
7FC416 8B 77 74                  mov esi,[edi+0x74]
7FC419 E8 32 25 FF FF            call 0x7EE950
7FC432 8B 5B 34                  mov ebx,[ebx+0x34]
7FC435 C7 43 04 0F 00 00 00      mov [ebx+4],0xF
7FC43C C7 43 08 12 00 00 00      mov [ebx+8],0x12
7FC443 C7 43 0C 08 00 00 00      mov [ebx+0xC],8
~~~

**意義**：Node+0x34確實存放由CModel ctor返回的指標（成功分配/建構條件下）；CModel上三個初始group indices+4/+8/+C在此被重新覆寫為0xF,0x12,0x8。因而CModel 0x7D3470取+4、並在特定gate改取+8/+C作0x2004步幅索引時，**可觀察到這個Node初始化路徑的明確上游候選index資料**。但是0xF=15、0x12=18、0x8=8只對**此路線**成立，不是所有CModel固定索引，也不能推廣成全部22桶的合法值範圍證明。

另一獨立CModel建構站點真0x7C5100：0x7C515D push 0xB8 → 0x7C5164 call 0x891268 → 0x7C517C call 0x7D2DB0 → 0x7C518C mov [EDI],EAX；其後0x7C5192..0x7C51AB用兩個word組合key，透過0x82EF00操作外層+0xB4索引，顯示CModel可被不同owner配置。**不能**把另一站點0x7C5100的CModel直接當CItemNodeSimple+0x34子成員。

## 3. 完全可驗的間接call-forwarder 7FC360 -> [CModel vptr+8]，有明確this來源

此為本輪真正的新ABI／caller邊界；不像只根據RTTI期待會有人call 7D3470，這裡**已具體找到轉送的方法**：

~~~asm
7FC360 83 79 34 00                cmp dword [ecx+0x34],0 ; Node has Model?
7FC364 74 0A                      je 0x7FC370
7FC366 8B 49 34                   mov ecx,[ecx+0x34] ; ECX := CModel*
7FC369 8B 01                      mov eax,[ecx]      ; vtable
7FC36B 8B 50 08                   mov edx,[eax+8]    ; CModel primary +8
7FC36E FF E2                      jmp edx           ; tailcall
7FC370 C3                         ret               ; no Model
~~~

- 如果Node+0x34為null，直接ret，**不會寫分桶**。
- 如果+0x34指向由7FC3CA建構且vptr仍為C500D4的CModel，則[JMPEDX]在真原件 **C500DC = 7D3470**；ECX從Node改成實際CModel this，因此CModel 7D349C mov EBX,ECX的this來源已補上。
- CItemNodeSimple自己的vtable C51020+0x2C = C5104C → 7FC360，表示上游若通過CItemNodeSimple slot+0x2C派送，就會走此轉送。**但目前尚未確定哪個scene loop/actor owner對該node呼叫slot+0x2C，亦未證每個runtime Node都已調用7FC380完成+34初始化**；不可從vtable靜態存在推說整條在每幀必定執行。
- 不必為了在此片段找不到direct E8到7D3470而宣稱Model writer不可達，因為7FC36E是**JMP間接尾呼叫**。這是對T08-152既有「缺少producer上游」問題的實質修正。

## 4. 已閉合的**條件性**上游到bucket與回收

~~~text
7EF89E allocate 0x50 Node
 -> 7EF8D2 Node.vptr = C51020; Node+0x34 = 0
7FC380 Node-associated init (caller仍待定位)
 -> 7FC3AA alloc 0xB8
 -> 7FC3CA E8 7D2DB0 : CModel ctor / vptr C500D4
 -> 7FC3DD Node+0x34 = CModel*
 -> 7FC435 Node.Model+4=15, +8=18, +C=8
   ...
CItemNodeSimple.vtable+0x2C = 7FC360
 -> if(Node+0x34) ECX = Model*
 -> 7FC36E JMP [Model.vptr+8]  **=> 7D3470 when vptr C500D4**
 -> CModel guarded direct bucket writer 7D3515 / 7D35A4
    and/or 7D3601 E8 79A3C0 alternative producer
 -> [0xFB7740] same global bucket base as [0xFB76A8+0x98]
 -> callback 7D1310 consumption (known conditional dispatcher route)
~~~

**主要負面**：7FC2C0 destructor既有0x34清理路，不能把Node保存的Model永不釋放當作事實；JMP轉送前有null guard，但沒有證實不會在其他線程/owner並行析構。沒有給出完整scene render loop、bucket索引上界證明、T02 packet來源或原版Server決策。

## 5. 交接S00／T01：玩家可見流程和四種狀態

|範圍|Client直接證據|Client待逆向|Server待開發|跨Task/遊玩驗證|
|---|---|---|---|---|
|場景可渲染Node持有Model|0x50 Node結構由CItemNodeSimple RTTI辨識、0xB8 CModel 配置、Node+34指標，Node.vptr+2C→7FC360→Model.vptr+8→7D3470，最後寫[FB7740] bucket|Node虛擬method在何種scene loop被派送、Node/Model生命周期、bucket index實際合法性與各category效果|無本段可證的Server opcode/怪物spawn時間|T02 framing/handler、T06/T07場景、可玩驗收|
|CDoll B vector vs Model bucket|兩種物件皆屬IRenderable派生，但CDoll primary+8=7A63C0，CModel primary+8=7D3470，不能混為同一實作|CDoll B→CModel/Node bridge仍缺正確pointer identity|需由已證Client wire/SPec及S00獨立定義相容設計|T01原生FULL-PASS未完成|

**T01退回**：保留全部舊源，LEGACY-MAPPING-001仍 NEEDS_FIX；本稿是獨立原生證據而非T01審核決議。雖本輪已找到 CModel上游確切virtual tailcall，CDoll B→bucket的相應跨物件橋仍缺，故研究目標尚未完全達成，應延續。


## 事後補證（同次分析 03:14:54）

原稿中「7FC380的EBX=[EBP+8]仍需從caller確定是否同一Node」已在獨立新原生證據 [7EF912→7F07B0→7F0810→7FC380同一Node資料流](20261031-031454-chatgpt-web-roy-T08-CItemNodeSimple-node-construction-to-CModel-initialization-and-dispatcher.md)（blob **80471c49eadbddbae5446b97a0debaf73024e4c8**）解決：7EF8D2寫CItemNodeSimple vptr後同一ESI Node由7EF912 push並在7F07D5成為EBX、7F080D再push EBX傳7FC380。**限制：成功路受owner+0x128與多型呼叫/配置結果制約；真正scene loop呼叫Node slot+0x2C仍待證。**
