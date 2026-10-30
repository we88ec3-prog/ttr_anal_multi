# T08-202 — 四種原生Actor RTTI派生型別的slot+0x14清理與Controller H-tree真正析構邊界（續查，BIN-first）

chatgpt-web roy，2026-10-31 04:40 Asia/Taipei。KR \`Tartaros.bin\`，12,472,320 bytes，SHA256 \`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91\`，本輪直接本地hash核對。PE .text VA=0x401000/raw0x400：真code raw=VA−0x400C00；.rdata VA=BD2000/raw=7D0600：raw=VA−0x401A00；.data VA=D61000/raw=95E800：raw=VA−0x402800。來源是同一個原始PE32，不使用舊全檔raw0錯偏反組譯，也未執行Client/Server。

## 0. 本輪新舊證據界線與獨立論點

本篇對0x4DFC90（本地index81）及0x4DFBC0（本地index26）所呼叫之 \`Actor->vptr+0x14\` 做**四種已知0007可建構的Actor型別逐一對位**，並追它們實際資源清理下游；另追Controller歷史索引 \`+0x48\` 在**不同於slot14的destructor**是如何真正清理。

**不應虛報為新發現：** T08-201原始完整研究（本機 \`T08-201-original-full-20261028.md\`，已有完整論述）已證 \`4AF530→alloc(0x2C)→4DFFB0\`的新P建立/次級樹插入，及CMonster vptr+0x14=4D1F80→4C8360。本輪前一份T08-202新報告重核了這些鏈，但**不是第一次發現**，今後引用時一律標「201已證、202復核」。真正本篇新增是對其他三種Actor的RTTI/caller side-effect及Controller H-tree析構鏈，還有P同key refresh未覆蓋P+4/+8之相對於201的具體新限制。

### 舊主張不可繼承的修正

1. 不能說「index81沒有call Controller.slot14 → 所有Actor type都不做清理」。index81 \`4DFCC0\` 透過 **Actor vptr+14** call不同Actor class的resources cleanup；\`4DFCD0\`再調Actor deleting destructor及 \`4DFCE1\`移除主樹。
2. 不能說「Controller slot14沒有erase +0x48 H-tree → 此樹從不被釋放」。本篇直接驗證Controller primary deleting destructor \`0x544E50→0x544E80\` 中的H-tree析構，與前置slot14只logical-clear raw Actor slot/pair vector是兩個不同生命週期。
3. 不能將 \`0x544E80\`這個Controller析構路徑擴張到index26/index81會立即觸發Controller析構：這些Actor移除分支沒有證實call此Controller deleting destructor；若Controller本身仍存活，H-tree是否保留取決於其它owner生命週期。

## 1. 四個原生ctor寫vptr與MSVC RTTI精確對應

直接由真PE \`.text\` constructor的vptr store和 \`.rdata\` vtable[-1] CompleteObjectLocator (COL) → TypeDescriptor.name at type+8相互獨立對照：

|0007 type|ctor in .text, vptr store |actor primary vptr|vptr[-1] RTTI COL|TypeDescriptor.name原始字串|vptr+0x14 func|
|---|---|---|---|---|---|
|0|4CD6F0，4CD728: mov [edi],0xC07B44|**C07B44**|C6AAAC| \`.?AVCCharacter@@\`|**4CEBF0**|
|1|4D1710，4D1749: mov [edi],0xC0C9DC|**C0C9DC**|C6AC84|\`.?AVCMonster@@\`|**4D1F80**|
|6|4D2120，4D2159: mov [edi],0xC0CA9C|**C0CA9C**|C6ACF0|\`.?AVCNPC@@\`|**4D2860**|
|7|4D1060，4D1096: mov [edi],0xC0C8C4|**C0C8C4**|C6AC18|\`.?AVCEventObject@@\`|**4D16A0**|

一手0007 handler（true PE code，非憑typename猜type）：

~~~asm
4AE5E4 68 44 04 00 00        push 0x444
4AE609 E8 E2 F0 01 00        call 0x4CD6F0          ; type0
4AE671 68 34 04 00 00        push 0x434
4AE692 E8 79 30 02 00        call 0x4D1710          ; type1
4AE80A 68 2C 04 00 00        push 0x42C
4AE82B E8 F0 38 02 00        call 0x4D2120          ; type6
4AE8D6 68 28 04 00 00        push 0x428
4AE8F7 E8 64 27 02 00        call 0x4D1060          ; type7
~~~

上表要以T08-201已核的type jump table \`0x4AED90\`校對：0→4AE5E4，1→4AE671，6→4AE80A，7→4AE8D6。2/3/4/5與>7另走錯誤/診斷路，不能稱本表已枚舉所有經其他機制可存在的Actor類。各vptr從ctor完成到移除時是否仍原值屬**動態型別前提**，不能單憑ctor證每個遊戲實體必然使用該函式。

## 2. Actor vptr+0x14 = resource cleanup，不是 Controller slot+0x14

**本地index81** 的 \`0x4DFC90\` 在 \`4DFCB6 cmp [Actor+0x88],key\` 命中後：
~~~asm
4DFCBE 8B 11               mov edx,[ecx]       ; Actor primary vptr
4DFCC0 8B 42 14            mov eax,[edx+0x14] ; Actor slot+0x14
4DFCC3 FF D0               call eax
4DFCC5 8B 4E 10            mov ecx,[esi+0x10]
4DFCCC 8B 11               mov edx,[ecx]
4DFCCE 8B 02               mov eax,[edx]
4DFCD0 6A 01               push 1             ; Actor deleting destructor
4DFCD2 FF D0               call eax
4DFCD4 C7 46 10 00 00 00 00 mov [esi+0x10],0
4DFCE1 E8 AA 6B 2D 00      call 0x7B6890     ; Actor main tree node
~~~

原始四種實際callee均由vptr DWORD確定：

- **CCharacter \`0x4CEBF0\`**：
~~~asm
4CEBF0 56                  push esi
4CEBF1 57                  push edi
4CEBF2 8B F9               mov edi,ecx
4CEBF4 8B B7 2C 04 00 00  mov esi,[edi+0x42C]
4CEBFE E8 DD FE 2E 00     call 0x7BEAE0     ; if child nonnull
4CEC03 8B B7 30 04 00 00  mov esi,[edi+0x430]
4CEC0D E8 CE FE 2E 00     call 0x7BEAE0     ; if child nonnull
4CEC12 8B CF               mov ecx,edi
4CEC14 E8 47 97 FF FF     call 0x4C8360     ; common actor children
4CEC19 8B BF 24 04 00 00  mov edi,[edi+0x424]
4CEC2C E8 BF F9 2E 00     call 0x7BE5F0     ; if +0x24 refcount field
~~~
- **CMonster \`0x4D1F80\`**：\`4D1F80:E8 DB 63 FF FF\`直接call \`4C8360\`，\`4D1F85 33 C0\`零回傳，\`4D1F87 C3\`。此身份鏈 **T08-201已證**, 本輪只再次核vtable+14。
- **CNPC \`0x4D2860\`**：
~~~asm
4D2860 56                 push esi
4D2861 57                 push edi
4D2862 8B F1              mov esi,ecx
4D2864 E8 F7 5A FF FF    call 0x4C8360
4D2869 8B B6 20 04 00 00 mov esi,[esi+0x420]
4D2878 83 3E 00          cmp dword [esi],0
4D287D E8 6E BD 2E 00    call 0x7BE5F0       ; if +0x420+0x24 control !=0
4D2884 5F                 pop edi
4D2885 5E                 pop esi
4D2886 C3                 ret
~~~
- **CEventObject \`0x4D16A0\`**：
~~~asm
4D16A0 53                 push ebx
4D16A1 8B D9              mov ebx,ecx
4D16A3 8B 83 24 04 00 00 mov eax,[ebx+0x424]
4D16B8 E8 33 CF 2E 00    call 0x7BE5F0         ; child+0x24 present
4D16C7 E8 E4 66 FF FF    call 0x4C7DB0         ; child destroy
4D16CC C7 83 24 04 00 00 00 00 00 00 mov [ebx+0x424],0
4D16D8 8B CB             mov ecx,ebx
4D16DB E9 80 6C FF FF    jmp 0x4C8360        ; tail into shared cleanup
~~~

Common subcleanup \`0x4C8360\`:
~~~asm
4C8363 8B F9                   mov edi,ecx
4C8365 8B 87 5C 01 00 00      mov eax,[edi+0x15C]
4C836D 74 0A                  je 0x4C8379
4C836F 8D 48 08               lea ecx,[eax+8]     ; child+8 interface, not child primary
4C8372 8B 01                  mov eax,[ecx]       ; interface vptr
4C8374 8B 50 08               mov edx,[eax+8]
4C8377 FF D2                  call edx           ; nested virtual side effects UNKNOWN
4C8379 8B 87 64 03 00 00      mov eax,[edi+0x364]
4C838C E8 5F 62 2F 00         call 0x7BE5F0      ; conditional refcount release
4C8391 81 C7 64 01 00 00      add edi,0x164
4C8397 BB 80 00 00 00         mov ebx,0x80
4C83A0 8B 07                  mov eax,[edi]       ; 128 subordinate slots
4C83AF E8 3C 62 2F 00         call 0x7BE5F0      ; conditional release per slot
4C83B4 83 C7 04               add edi,4
4C83B7 4B                     dec ebx
4C83B8 75 E6                  jne 0x4C83A0
~~~

已閉合：**這四個Actor type在index81已核的virtual+14首先走具體的資源清理程式，與Controller slot14=545210/444910不是同一dynamic this。** 已知直接CFG內無把ECX設為controller或直接CALL 545210/444910，**但共用4C8360的child+8 virtual call 4C8377和resource-release helpers內部可能經其它owner回調；這些真實動態目標與副作用需要單獨處理，不能僅以本局部說「Controller必然未被清」或「必然出UAF」。**

## 3. 更重要的新生命週期：Controller H-tree +0x48確實在owning Controller destructor清理

前份T08-202只證 \`Controller vtable+0x14→545210\`或 \`Tag vtable+0x14→444910\`會清raw slots及pair vector的**有效長度**，沒有erase \`Controller+0x48\` 的H-tree；現在由**另一條合法析構路徑**找到真正全量釋放：

**五種普通/衍生Controller primary vptr+0** \`0x544E50\` deleting destructor wrapper（Tag為另外0x4442D0；須區分）。其normal call：
~~~asm
544E50 55 8B EC                  push ebp; mov ebp,esp
544E54 8B F1                     mov esi,ecx
544E56 E8 25 00 00 00            call 0x544E80 ; Controller cleanup
544E5B F6 45 08 01               test byte [ebp+8],1
544E62 E8 A5 C3 34 00            call 0x89120C ; if delete bit
~~~

**Controller destructor root \`0x544E80\`**：
~~~asm
544EA8 8B F9                     mov edi,ecx
544EAD C7 07 44 F9 C0 00        mov [edi],0xC0F944  ; base vptr restoration
544EBA 8D 9F 88 00 00 00        lea ebx,[edi+0x88] ; other owned tree
544ED3 E8 E8 F1 00 00           call 0x5540C0     ; tree subtree cleanup
544EDB 53                        push ebx
544EDC E8 2B C3 34 00          call 0x89120C      ; sentinel
544EE1 8D 5F 48                 lea ebx,[edi+0x48] ; **Controller H-tree**
544EE7 53                       push ebx
544EEC E8 7F A6 00 00           call 0x54F570      ; payload tree walk/release
544EF8 8B 43 04                 mov eax,[ebx+4]
544F04 E8 B7 F1 00 00           call 0x5540C0      ; tree/node cleanup
544F09 8B 43 04                 mov eax,[ebx+4]
544F0D E8 FA C2 34 00           call 0x89120C      ; H-tree sentinel
544F12 8B 47 30                 mov eax,[edi+0x30]
544F1E E8 E8 C2 34 00           call 0x89120C      ; pair vector allocated capacity
544F27 89 77 30                 mov [edi+0x30],esi ; zero begin
544F2A 89 77 34                 mov [edi+0x34],esi ; zero end
544F2D 89 77 38                 mov [edi+0x38],esi ; zero cap
~~~

\`0x54F570\` 在H-tree payload處理中有實際釋放分支（非只是空stubs）：
~~~asm
54F598 8B 5D 08                 mov ebx,[ebp+8] ; &Controller+48
54F59B 8B 43 04                 mov eax,[ebx+4]
54F59E 8B 38                    mov edi,[eax]
54F5A8 8B 47 10                 mov eax,[edi+0x10] ; node payload
54F5CB E8 50 7B 18 00           call 0x6D7120     ; nested subtree cleanup
54F5DB E8 2C 1C 34 00           call 0x89120C     ; nested sentinel
54F5E4 E8 23 1C 34 00           call 0x89120C     ; H-node payload
~~~

**正式新結論**：Controller的 \`slot14\` 是控制槽與pair的logical reset，保留H-tree；**Controller object真正析構**可釋放H-tree payloads、nodes、sentinel以及pair vector capacity，兩個階段是不同的生命週期，不可對其中之一泛化「永遠保留」或「已全部free」。此外Controller+0x88是另一個獨立擁有的tree，不能併入H-tree+0x48；二者分別析構。

尚待：Tag deleting destructor \`0x4442D0\` 是否最後進入base Controller \`0x544E80\`，目前此稿沒有完整根CFG；其它派生方法可能早於析構清H-tree；特定Actor移除 index26/81 **沒有**本段直接證明會因此析構 Controller instance。這些未知是可在Client BIN繼續追索的問題，不因有了H-tree destructor就假稱所有path的處置已全域閉合。

## 4. 與 T08-202 完成要求之關係和保留的精確缺口

本稿按原件已進一步解決「四種可由0007建構的Actor移除前slot14究竟進入什麼」及「Controller H-tree是否有真正owned destructor」兩個此前尚未核實的子問題。連同201原有的P建立／二樹區分，最近202確認的refresh保留數值、0007/000A不同writer、26/81 handler、pair第二pass與WSASend/GQCS，可構成有界完整玩家輸入→Client狀態→Client局部效果候選鏈，但**不構成以下任一完整排他證明**：

1. Owner P+4/+8所有能通過pointer alias（owner+F8 cache、二級tree payload、多個handler callback）進入的間接writer全集，尚缺整個程式CFG及別名來源歸屬；不能把已見三條寫入形式誤說成全局唯一。
2. 共同Actor \`4C8360\` 的 \`child+8→vtable+8\` 真實runtime類別、所有callback與Controller raw槽、P生命期的關係尚缺。不能把「無直接call Controller.slot14」等同「永不經回調同步」。
3. Controller衍生Tag/Single/Mission/Tutorial及各種reset中H-tree其它可能的release/erase路徑，仍缺動態類別及上下游完備性證明；**上面已證的正常Controller析構只是確定的一條**。
4. T02 wire解幀到T08業務handler local index的精確domain對照仍屬跨Task契約；目前不能靠本地index就當成原版Server opcode。

**Client已證**為上述函式與有條件副作用；**Client待逆向**為1–3與其他缺乏原生caller的靜態邊；**Server待開發**為相容Server應如何決定Actor建立、位置、死亡／移除、關卡波次（不是本地handler能反推的官方邏輯）；**跨功能**為T02封包、T06/T07/T14場景與S00規格設計；**待遊玩驗證**為動態執行/封包觀察。T01限定FULL-PASS和S00是否接受由專責獨立處理。

**T08-202進度裁決**：本次取得進一步真正的新原生靜態證據，但本段原本的Owner alias writer和不同場景刪除一致性仍有可進一步查的Client BIN路徑，**不得標整體202 FINISHED**，不新增203。


## 5. 同批追加：Tag和Single Controller最終也呼叫同一base H-tree析構，修訂§3限定

初次提交本稿時尚保留「Tag/Single destructor是否進0x544E80」未知。隨後從原生PE進一步進行完整有效入口→E8直接邊查驗，**此細項已閉合**；保留原§3問題的歷史文字以便比較，但下述新驗證覆蓋該局部未知：

- **CTagController primary vptr 0xBFB5A4+0 → 0x4442D0**。0x4442D6 push ESI（this）→0x4442D7 call 0x444300；後者在0x444327暫設Tag vptr，先處理自身+0xB8和+0xB4資源；**0x444381 mov ecx,edi，0x44438A call 0x544E80**（E8 F1 0A 10 00），進入base Controller cleanup。若0x4442DC判delete bit，外層再free這個Controller*。故Tag的H-tree+48和另一+88 tree在**真正Tag析構**條件下也會走base清理，並非永不釋放。
- **CSingleController primary vptr 0xC0FAC4+0 → 0x548600**。0x548606 push ESI→0x548607 call 0x548630；本體先釋放自己+0xB8與+0xB4（0x548664..0x5486AE），再在**0x5486B1 mov ecx,edi，0x5486BA call 0x544E80**（E8 C1 C7 FF FF）。因此Single也有同一base H-tree析構。
- **CEmptyController vptr 0xC0F99C+0 → 0x547200**：0x547206先重設子vptr，再於**0x54720C call 0x544E80**（E8 6F DC FF FF）；與Tag/Single相似，H-tree最終由base cleanup釋放。
- **CController / MissionRoom / Tutorial** 的已知vptr+0 多數為 \`0x544E50\`，它一開始於 \`0x544E56 call 0x544E80\`，故在此已知類別表下有共同的base H-tree析構終點。

這是**至少六張已知Controller主vtable的真正生命週期共通點**：除slot14重置以外，型別的deleting destructor終會處理+48 H-tree、+88另一tree和+30 pair vector配置。**但這不證明Actor命令26/81即時析構Controller**，因它們只是對現有Controller呼叫slot14（26條件性），不是vptr+0 deleting destructor。未核所有外部Plugin或動態vptr替換，也不能由此證明Actor與Controller的跨owner引用安全性。
