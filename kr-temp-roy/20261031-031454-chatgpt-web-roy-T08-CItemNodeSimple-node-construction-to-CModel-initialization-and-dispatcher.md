# T08／T01 LEGACY 勘誤追加：CItemNodeSimple 建構→7F07B0→7FC380→CModel 真正caller閉合

研究者chatgpt-web roy；2026-10-31 03:14:54 Asia/Taipei。原始 Tartaros.bin 12,472,320 bytes、SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91；只讀靜態BIN，.text code原生VA−0x400C00。先前獨立來源：
- 20261031-030908-chatgpt-web-roy-T08-LEGACY-152-followup-IRenderable-CDoll-CModel-bucket-producer-BIN-first-FULL.md（已證CModel的7D3470直接bucket writer與7D3601→79A3C0之同base別名）；
- 20261031-031253-chatgpt-web-roy-T08-CItemNodeSimple-CModel-virtual-forwarder-native-ABI-and-two-constructors.md（已證CItemNodeSimple slot+2C＝7FC360，按Node+34轉送CModel slot+8）。

本篇接續查原先尚未確認的Node建構對象與CModel初始化caller是否相同，使用真PE direct E8 / 兩函式局部完整CFG閉合，並追查初始化後dispatch邊界。不修改舊T08-129～152 FAILED原稿；T01仍NEEDS_FIX。

## 1. 確切的 SAME Node object傳遞：7EF8D2 → 7EF912 → 7F07D5 → 7F080D → 7FC3A7

原生7EF89E：push0x50並call0x891268，傳回EAX指向新Node；7EF8D2：mov [eax],0xC51020（RTTI CItemNodeSimple，繼承CItemNode）；7EF8DB把Node+0x34清零；7EF8EA ESI=EAX、7EF90F push ESI、7EF910 mov ECX,EDI；**7EF912 E8 99 0E 00 00 CALL 7F07B0**。

在7F07B0入口，EBX=[EBP+8]就是剛才傳入的Node*，ESI=ECX是owner（不同物件）。只有當owner+0x128非null，才會走下游初始化：

~~~asm
7EF89E 6A 50                     push 0x50
7EF8A0 E8 C3 19 0A 00            call 0x891268
7EF8D2 C7 00 20 10 C5 00         mov [eax],0xC51020
7EF8DB 89 58 34                  mov [eax+0x34],ebx  ; zero init
7EF8EA 8B F0                     mov esi,eax
7EF90F 56                        push esi
7EF910 8B CF                     mov ecx,edi
7EF912 E8 99 0E 00 00            call 0x7F07B0

7F07B0 55 8B EC                  push ebp; mov ebp,esp
7F07D5 8B 5D 08                  mov ebx,[ebp+8]    ; SAME Node*
7F07D8 8B F1                     mov esi,ecx        ; owner
7F07DA 83 BE 28 01 00 00 00      cmp dword [esi+0x128],0
7F07E1 0F 84 F8 00 00 00         je 0x7F08DF        ; no Model init on this path
7F07E7 8B 8E 24 01 00 00         mov ecx,[esi+0x124]
7F07ED 8B 01                     mov eax,[ecx]
7F07EF 8B 50 0C                  mov edx,[eax+0xC]
7F07F2 FF D2                     call edx           ; owner external factory/context
7F07F4 8B F8                     mov edi,eax
7F07F6 8B 17                     mov edx,[edi]
7F07FC 8B 42 30                  mov eax,[edx+0x30]
7F080A FF D0                     call eax           ; returns ECX argument for 7FC380
7F080C 57                        push edi
7F080D 53                        push ebx           ; SAME Node*
7F080E 8B C8                     mov ecx,eax        ; returned external context
7F0810 E8 6B BB 00 00            call 0x7FC380      ; model init helper
~~~

因此之前「7FC380 的 EBX=[EBP+8] 型別只是候選」可提高證據等級：至少**此已解caller路徑的 EBX 精確就是RTTI CItemNodeSimple Node***，不是另一個相同+0x34位移的無關物件。其他未知caller仍須獨立檢查（本輪direct E8至7FC380共這1處）。

## 2. 由7FC380配置0xB8 CModel、回寫 SAME Node+34，再向後使用

~~~asm
7FC380 55 8B EC                   push ebp ;mov ebp,esp
7FC3A7 8B 5D 08                   mov ebx,[ebp+8] ; Node from 7F080D
7FC3AA 68 B8 00 00 00             push 0xB8
7FC3AF E8 B4 4E 09 00             call 0x891268
7FC3C1 85 C0                      test eax,eax
7FC3C3 74 0C                      je 0x7FC3D1
7FC3C9 50                         push eax
7FC3CA E8 E1 69 FD FF             call 0x7D2DB0 ; native CModel ctor
7FC3DD 89 43 34                   mov [ebx+0x34],eax ; SAME Node+34
7FC413 8B 7B 34                   mov edi,[ebx+0x34]
7FC416 8B 77 74                   mov esi,[edi+0x74]
7FC432 8B 5B 34                   mov ebx,[ebx+0x34]
7FC435 C7 43 04 0F 00 00 00       mov [ebx+4],0xF ; CModel index candidate
7FC43C C7 43 08 12 00 00 00       mov [ebx+8],0x12
7FC443 C7 43 0C 08 00 00 00       mov [ebx+0xC],8

7F0862 83 3D 4C 77 FB 00 03      cmp dword [0xFB774C],3
7F0869 8B 5B 34                   mov ebx,[ebx+0x34] ; CModel* (not Node*)
7F0896 8B 0D 44 77 FB 00         mov ecx,[0xFB7744]
7F089C 53                         push ebx          ; CModel* payload
7F089D 68 DC F4 C4 00            push 0xC4F4DC    ; selector/type context
7F08A2 51                         push ecx
7F08A3 EB 35                      jmp 0x7F08DA
7F08CD 8B 15 44 77 FB 00         mov edx,[0xFB7744]
7F08D3 53                         push ebx          ; CModel* payload
7F08D4 68 E8 F4 C4 00            push 0xC4F4E8    ; other selector/type context
7F08D9 52                         push edx
7F08DA E8 11 29 FC FF             call 0x7B31F0
~~~

此處有**新上下游具體事實**：成功走過factory及allocation後，此Node必然經7FC3DD寫入CModel*，然後7F0869又從**同一Node**取Model指標，依[0xFB774C]==3擇一傳到**7B31F0**。0xFB774C與0xFB7744雖地址在0xFB7740附近，**不可**因相鄰就當成bucket base pointer；其中[0xFB7744]是這裡傳入的另一個動態pointer，[0xFB774C]是選擇器條件的DWORD。

## 3. 7B31F0不是證實的bucket writer，為list的virtual matching/conditional dispatch

繼續從7B31F0真PE入口核驗，該函式把[EBP+8]當作pointer-vector *owner*，按begin/end算count，逐item先以vtable+0x08向[EBP+0x0C]比較，若外部比較helper0x893CB1測試返回非零則繼續；否則以對應item的vtable+0x0C和[EBP+0x10]執行另一路：

~~~asm
7B31F0 55 8B EC                   push ebp; mov ebp,esp
7B31F4 8B 5D 08                   mov ebx,[ebp+8]   ; pointer vector owner
7B31F8 8B 73 04                   mov esi,[ebx+4]   ; end
7B31FB 2B 33                      sub esi,[ebx]     ; end-begin
7B31FE C1 FE 02                   sar esi,2
7B3207 8B 03                      mov eax,[ebx]     ; begin
7B3209 8B 0C B8                   mov ecx,[eax+edi*4]
7B320C 8B 55 0C                   mov edx,[ebp+0xC]
7B320F 8B 01                      mov eax,[ecx]
7B3211 52                         push edx
7B3212 8B 50 08                   mov edx,[eax+8]
7B3215 FF D2                      call edx         ; item vptr+8
7B3217 50                         push eax
7B3218 E8 94 0A 0E 00            call 0x893CB1
7B3220 85 C0                      test eax,eax
7B3222 74 0E                      je 0x7B3232
7B3232 8B 03                      mov eax,[ebx]
7B3234 8B 0C B8                   mov ecx,[eax+edi*4]
7B3237 8B 11                      mov edx,[ecx]
7B3239 8B 45 10                   mov eax,[ebp+0x10]
7B323C 8B 52 0C                   mov edx,[edx+0xC]
7B323F 50                         push eax
7B3240 FF D2                      call edx
7B3246 C2 0C 00                   ret 0xC
~~~

**有界結論**：7F07B0的後置7B31F0執行的是**可觀察的list matching/conditional dispatch**，但間接item.vptr目標和參數 C4F4DC/C4F4E8的確切型別尚需查；它並非在本函式內直接執行 [0xFB7740] bucket count increase。這個新結果不能拿來錯誤補CDoll B→22桶之間缺少的pointer identity。

## 4. 真正model slot +8的forwarder，與Node初始化生命週期現在可以相接

Node primary vfptr = C51020：MSVC RTTI CItemNodeSimple offset0；其slot+0x2C於C5104C取出0x7FC360。先前新source已核：

~~~asm
7FC360 83 79 34 00             cmp dword [ecx+0x34],0
7FC364 74 0A                   je 0x7FC370
7FC366 8B 49 34                mov ecx,[ecx+0x34] ; Node -> Model*
7FC369 8B 01                   mov eax,[ecx]
7FC36B 8B 50 08                mov edx,[eax+8]    ; Model vtable+8
7FC36E FF E2                   jmp edx           ; tailcall
7FC370 C3                      ret
~~~

此時 Node+0x34的producer已從**真7EF8D2建構及7F07B0直接呼叫7FC380**連上，不再只是「兩個偏移吻合的候選」。在Node vptr仍C51020、Node+34指向CModel且其vptr仍C500D4時，這個method forwarder指向**CModel真0x7D3470**，後者具有向[0xFB7740] bucket直接及經79A3C0條件寫入的native paths。這是一條由constructor→owner→real virtual forwarder→bucket producer的**可達性功能鏈**。

**尚缺的最上游邊**：哪一個場景／項目更新迴圈實際對CItemNodeSimple呼叫slot+0x2C；本源只證Node確實被建構、被初始化為CModel、提供一個可分派的方法，**不把所有相鄰函式的存在冒充runtime每幀實際派送**。

## 5. 初步資料結構與剩餘風險／Server責任

~~~cpp
// names have RTTI support; fields are partial and provisional
struct CItemNodeSimple {
    void** vptr;       // 0xC51020
    // ...
    CModel* model;     // +0x34, 0 if not initialized; writer 7FC3DD
};
void CItemNodeSimple_slot2C(CItemNodeSimple* node) {
    if (node->model) node->model->vptr[2](node->model);
}
~~~

- 先前「7FC380的[EBP+8]只是可能的CItemNodeSimple」已由**caller 7F080D**確認成同一Node*。
- 0x7B31F0後置處理的item vptr+8/+0C**並非**已證 CModel vptr或bucket writer；中介selector/observer型別仍欠證。
- Node析構0x7FC2C0（vptr寫回C51020並清理+34相關資源）仍可能改變Model物件生存期。與bucket內借用CModel*的指標釋放順序未完全閉合，不宣稱UAF已存在或不存在。
- 舊T08-152地址錯置及錯誤negative xref仍為LEGACY-MAPPING-001的一部分；本稿是增量修復，不代替T01 FULL-PASS、RR接受、S00 SPEC或實機可玩。
- Server待開發：此輪未驗T02 wire opcode/SC->UI效果，不能推原版Server怪物spawn/波次；跨T02/T06/T07待串接，Client仍需補Node虛擬slot+0x2C caller、Model指標生命週期、CDoll B到CModel的資料橋。

|玩家情境候選|Client已證|Client未證／本地下個查點|Server-only未知|
|---|---|---|---|
|ItemNode經Model送入渲染資料|Node allocated0x50、true RTTI、owner gate後建立Model0xB8、Node+0x34寫入，具vtable+0x2C→CModel vtable+8→bucket寫入的完整靜態可達鏈|外層scene loop的virtual dispatch/Model可視效果/析構時序|何種Server輸入導入這類Node與生成時機；不由此補猜|
