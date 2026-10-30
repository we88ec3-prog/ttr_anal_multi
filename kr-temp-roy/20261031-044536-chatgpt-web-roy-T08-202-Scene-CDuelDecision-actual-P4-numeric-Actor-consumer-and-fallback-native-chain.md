# T08-202 — P+4 的真實場景消費者：Scene::CDuelDecision → owner P-tree → Actor main-tree → Actor+0x88／0x15C（BIN-first）

作者 chatgpt-web roy；時間 2026-10-31 04:45 Asia/Taipei。原件KR \`Tartaros.bin\` 12,472,320 bytes，SHA256 \`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91\`，本地sha256sum實核。PE .text VA0x401000 raw0x400，真raw=VA−0x400C00；.rdata VA0xBD2000 raw0x7D0600，TypeDescriptor .data VA D61000 raw95E800；從完整原生PE根入口0x4BD600使用objdump -d -M intel與原始data DWORD、MSVC TypeDescriptor直接交叉驗證。不啟動Client/Server，不用fixture當原生。

## 0. 先前已證和本篇新事實

前置已證：T08-201原始完稿已有0x4AF530→0x2C P record allocation→0x4DFFB0插入owner+0x18的資料身分，T08-202已核本地index7/10的P+4/+8正數值寫入，新的index8 same-key refresh保留P+4/+8，以及命令26/81主Actor erase後未直接清P+4/+8。這些是**輸入與writer背景**，非本篇首次發現。

**本篇新事實**：從全PE direct E8 to generic lookup \`0x8438C0\` 的419個原始byte模式候選，先依caller根入口和真全域owner次級樹 \`ECX=0xFAB148\`過濾，找到 **0x4BD708**。其真函式 \`0x4BD600\` 讀P+4並再次從Actor主樹查詢，成功後**有具體Scene物件狀態寫入者**；不是只在Actor暫存資料或推測UI。另由原生MSVC RTTI識別其this所屬 \`Scene::CDuelDecision\` 類，而不猜使用者顯示的決鬥遊戲規則。

## 1. 真場景物件型別：Scene::CDuelDecision

- 有效函式 \`0x4BD590\`：0x4BD5A6 **C7 06 CC 70 C0 00**, 設物件primary vptr \`0xC070CC\`；owner字段 +0xBFA8 初始化0。
- 此vptr 的 \`.rdata[vptr−4]\` = **0xC69B28** MSVC RTTI CompleteObjectLocator；其TypeDescriptor原名在 \`.data\` 為 **\`.?AVCDuelDecision@Scene@@\`**，這是確切原始MSVC type string。
- \`0x4BD600\` prologue \`55 8B EC 83 E4 F8\`，\`4BD62C mov EBX,ECX\`，因此後續 \`[EBX+0xBFA8]\`／\`[EBX+0x5EE0]\` 都是這個**同一Scene::CDuelDecision instance**的欄位，不是P/Actor自身的偏移。
- 該類Vtable的前8實際slot：C070CC+0=4BD5D0（deleting destructor）；+4=4342A0；+8=422810；+0C=4227F0；+10=4C0680；+14=4C50E0；+18=4BB150；+1C=4ADB90。0x4BD600本身是內部可達caller函式，**不能**只因本身在相同區域就假稱它由哪一個slot派送；其上游仍須定位。

## 2. 第一段：從Controller選 Actor，依其WORD +4 ID驗證主樹Actor及狀態gate

~~~asm
4BD600 55 8B EC                  push ebp; mov ebp,esp
4BD62C 8B D9                     mov ebx,ecx           ; CDuelDecision*
4BD62E 8B 0D A4 A7 FB 00         mov ecx,[0xFBA7A4] ; Controller*
4BD634 8B 01                     mov eax,[ecx]
4BD636 8B 50 20                  mov edx,[eax+0x20]
4BD641 FF D2                     call edx            ; controller virtual+0x20
4BD643 85 C0                     test eax,eax
4BD645 0F 84 5E 01 00 00         je 0x4BD7A9       ; null fallback
4BD64B 66 8B 70 04               mov si,word [eax+4] ; Actor ID
4BD690 B9 38 B1 FA 00            mov ecx,0xFAB138 ; main Actor tree
4BD695 E8 66 18 37 00            call 0x82EF00
4BD69A 8B 44 24 18               mov eax,[esp+0x18]
4BD69E 3B 05 3C B1 FA 00         cmp eax,[0xFAB13C] ; tree sentinel
4BD6AA 8B 40 10                  mov eax,[eax+0x10] ; Actor*
4BD6B5 80 B8 BC 00 00 00 00     cmp byte [eax+0xBC],0
4BD6BC 0F 84 E7 00 00 00         je 0x4BD7A9       ; actor disabled gate
~~~

此時source Actor為Controller選出的真Actor*，其+4是WORD key；第一段先查主樹自己是否有效且Actor+BC BYTE非零，符合後才進關聯P分支。不能把「Controller vptr+20返回Actor」推廣為所有Controller類型，需基於當前動態slot與guard。

## 3. 第二段：Owner secondary P-tree → P+4 numeric Actor lookup → Scene狀態

~~~asm
4BD6F0 8B 93 A8 BF 00 00          mov edx,[ebx+0xBFA8]     ; CDuelDecision P-owner key
4BD6FF B9 48 B1 FA 00             mov ecx,0xFAB148       ; **owner secondary P tree**
4BD704 89 54 24 1C                mov [esp+0x1C],edx
4BD708 E8 B3 61 38 00             call 0x8438C0        ; find P by owner key
4BD70D 8B 44 24 14                mov eax,[esp+0x14]    ; iterator
4BD711 3B 05 4C B1 FA 00          cmp eax,[0xFAB14C]  ; owner tree sentinel
4BD71D 8B 40 10                   mov eax,[eax+0x10]   ; **P***
4BD720 85 C0                      test eax,eax
4BD728 8B 48 04                   mov ecx,[eax+4]      ; **P+4 numeric Actor ID, not Actor pointer**
4BD72B 89 4C 24 18                mov [esp+0x18],ecx
4BD72F E8 2C 19 F5 FF             call 0x40F060        ; main Actor owner
4BD736 8D 54 24 18                lea edx,[esp+0x18]
4BD73B 8D 4E 08                   lea ecx,[esi+8]      ; main Actor tree
4BD742 E8 B9 17 37 00             call 0x82EF00        ; exact Actor ID lookup
4BD747 8B 44 24 14                mov eax,[esp+0x14]
4BD74B 3B 46 0C                   cmp eax,[esi+0x0C]  ; main sentinel
4BD754 8B 40 10                   mov eax,[eax+0x10]  ; matching Actor*
4BD757 85 C0                      test eax,eax
4BD75F 0F B7 88 88 00 00 00       movzx ecx,word [eax+0x88]
4BD766 89 8B E0 5E 00 00          mov [ebx+0x5EE0],ecx  ; **CDuelDecision state writer**
4BD76C 8B 88 5C 01 00 00          mov ecx,[eax+0x15C] ; Actor child P*
4BD772 85 C9                      test ecx,ecx
4BD776 83 B8 70 03 00 00 00       cmp [eax+0x370],0
4BD77F 8D 83 E8 5E 00 00          lea eax,[ebx+0x5EE8] ; Scene child holder
4BD785 51                         push ecx           ; Actor child
4BD786 E8 25 9F 2E 00             call 0x7A76B0       ; conditional child pair update
4BD78B B8 01 00 00 00             mov eax,1
4BD790 89 83 D0 5E 00 00          mov [ebx+0x5ED0],eax ; set state flag=1
~~~

這是實際的 **P+4 reader與Scene writer**，比「命令26/81刪後P仍記錄舊ID」推測更具體：若P+4仍持有已移除Actor的數值key，則場景reader在本鏈使用主樹lookup並**檢查sentinel/payload非空**，沒有在這段直接對過去Actor pointer解參照。這能在此reader範圍排除「光因P+4殘留數字就必然UAF」的誤判，**不代表全域所有P consumers都具有相同guard**。

## 4. 失敗回退與真正玩家可見狀態限制

本函式的第一次Controller actor為null/主樹無匹配/Actor+BC禁用，或P次級樹缺key、P pointer null、按P+4查主Actor tree失敗等情況，跳出已述成功鏈。另一分支自0x4BD7A9取得Controller+0x1C slot index0的Actor 候選，可能更新同一CDuelDecision+5EE0/+5EE8狀態：
~~~asm
4BD7A9 33 FF                     xor edi,edi
4BD7AB 8D B3 E8 5E 00 00        lea esi,[ebx+0x5EE8]
4BD7B1 8B 0D A4 A7 FB 00        mov ecx,[0xFBA7A4]
4BD7B9 8B 42 1C                 mov eax,[edx+0x1C]
4BD7BC 57                       push edi           ; index 0
4BD7BD FF D0                    call eax           ; Controller slot+0x1C getter
4BD7BF 85 C0                    test eax,eax
4BD7C3 0F B7 88 88 00 00 00     movzx ecx,word [eax+0x88]
4BD7CA 89 4E F8                 mov [esi-8],ecx    ; EBX+5EE0
4BD7CD 8B 88 5C 01 00 00        mov ecx,[eax+0x15C]
4BD7E3 E8 C8 9E 2E 00           call 0x7A76B0      ; conditional child pair
~~~
回退的完整失敗/return status paths、該Scene物件的上游調度及UI顯示真正讀+5EE0是否畫面轉換，不能在此單一函式被誤當已驗。更不能把 \`CDuelDecision\` 類別名稱推成原版Server決鬥勝負規則。**Class name確證，Server內部決策仍unknown**。

## 5. 對T08-202靜態終點的實際推進/仍未閉合

本次以 Client 一手原生證據首次具體形成：**本地index8建立P / index7或10寫P+4 → Scene::CDuelDecision讀P+4 → owner主Actor tree精確找Actor → Scene+5EE0、+5ED0等欄位更新，必要時以Actor+15C子物件更新Scene+5EE8**，並有sentinel guards/後備Controller index0。這能提供T06/T07/T14場景集成時確定的數值關聯consumer，不需猜「Actor已釋放時所有reader都會UAF」。

但 **尚未由Client靜態證據全域閉合**：
1. 所有能取到P*（owner+F8 cached、owner+18及其它間接傳遞）的 **P+4/P+8 alias writer全集及其它consumer**，只是新增此一重要consumer。
2. \`0x4BD600\` 真正上游callsite／何時執行及Scene輸出到玩家畫面的消費者（仍可由BIN追）。
3. 命令81所有可能Actor callback、Controller H-tree的各局部erase與生存期及跨幀狀態，不能由此類別下游單獨證實。
4. T02 wire framing→Client handler index的正式業務domain，以及相容Server應產出哪種資料；這屬跨Task交接，不是原版Server算法可反推。

Client已證為上述確切有界鏈；**Client待逆向**為1–3；**Server待開發**為相容資料/決鬥業務判斷（不得宣稱復刻官方）；**跨T02/T06/T07/T14/S00**資料契約和顯示結果待串；**待遊玩驗證**與靜態SRC證據分開。**T08-202仍不應因單一新Scene consumer就標整體FINISHED**；此為真新的限定進展而非另一份描述舊P建立的重複報告。


## 6. 當批追加：0x4BD600 的真正多型介面已在原生vtable直接定位

本篇初稿對 \`0x4BD600\` 的上游只知同類別函式，未確認可經哪個virtual slot派送；隨即用原始BIN全長DWORD搜尋得 **exact \`0x004BD600\` hit只有一筆，raw \`0x8056FC\`**。按.rdata真PE對照 **VA=0xC070FC = Scene::CDuelDecision primary vptr \`0xC070CC\` +0x30**。所以在動態vptr仍為C070CC、場景dispatcher呼叫該物件virtual+0x30時，**必定跳入0x4BD600 P+4 consumer**。前面僅列8個vtable slot未顯示到此slot，這裡補上完整關鍵交界：

~~~text
C070C8 = C69B28   MSVC COL (Scene::CDuelDecision)
C070CC = 4BD5D0   vptr +0 : deleting destructor
C070F8 = 4B2570   vptr +2C : another function
C070FC = 4BD600   **vptr +30 : verified P+4 numeric consumer**
C07100 = 4C0B20   vptr +34
C07104 = 4BD820   vptr +38
C07108 = C69B7C   **NEXT CLASS COL, not CDuelDecision method +3C**
~~~

全.text以原始 \`E8 rel32\`搜尋 \`0x4BD600\` **0個direct E8 byte candidate**，與它是virtual method相容；**不能**據此說不存在場景caller。完整scene update迴圈是哪個主體對CDuelDecision呼叫vptr+0x30及其時序，仍待追具體ECX來源；本篇目前已從「函式無caller」進步為**完整RTTI/vtable可達接口**，不可提升為「已實際在玩家每幀調用」。
