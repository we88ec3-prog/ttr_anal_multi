# T10-118 — KR selector 0 的實際連線建立呼叫者、category=2 與多連線分支（BIN-first）

> 2026-10-28 Asia/Taipei，研究原稿；只讀 KR 原始 PE，不執行／patch／連接原版。主題為上一段 T10-117 未閉合的 selector=0 呼叫端。GitHub 目標僅 `t10/roy/chatgpt-web`；保留 T10-117 舊稿，不改他人 Task。

## 0. 版本與權限

- `Tartaros.bin` SHA256 **`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`**；`Tartaros.exe` SHA256 **`03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`**。本段實際重新計算。
- `.text` VA 0x401000，raw 0x400；VA=raw+0x400C00。`.rdata` VA 0xBD2000，raw 0x7D0600。FB/FD runtime zero-fill 的現場值不從 raw 猜測。
- 前段 T10-114、115、117 為導航；**本段 caller push 與返回條件均重新由原生 BIN objdump 核對**。沒有遊戲執行時／真實封包 trace；不把有界路徑等同所有玩家會走到。

## 1. 第一輪重大新增結論：真實 selector 0 producer 存在

### 1.1 入口 `0x4957C0` 同時註冊 selector0、selector2

在原生 `0x4957D0..0x495805`，兩組呼叫同一個 `FBA854 vtable+0x18`。依已確認 vtable `0xC51748+0x18` 對應 `0x806AD0`，並依 32-bit stdcall stack 從**最後 push 為第一參數**還原：

| call 指令 | 函式 | arg8（位址／Host） | argC（Port） | arg10（selector） | arg14（queue category） |
|---|---|---|---|---|---|
| `0x4957EA call edx` | `0x806AD0` | `EBX = caller arg8` | `0x20E0` | **0** | **2** |
| `0x495803 call edx` | `0x806AD0` | 同 EBX | `0x20DE` | **2** | **2** |
| `0x49575B call eax` | `0x806AD0` | `EDX = caller argC` | `0x20DF` | **1** | **2** |

**第一次確認的實質增量**：T10-117 僅證 writer `0x806AD0` 以第三個參數寫入 manager+0x18 selector tree；本次在 `0x4957EA` 直接證明上游傳第三參數 **0**、第四參數 **2**。也在獨立 `0x495743` 流程驗出 selector 1，以及 `0x495803` selector 2，這些是**三個不同連線索引**，而非 app opcode 0／1／2。

同一函式 `0x806B25 mov eax,[ebp+0x14]` → `0x806B33 mov [ebx+0xA080],eax` 保證上述呼叫若成功配置 connection，category 欄位寫2；`0x806C91 lea eax,[ebp+0x10]` 指向 selector 作 tree search/insert 的原生鏈由 T10-117 已證。selector 0 的 writer 與 `0x8069A0(selector0)` reader 不再只是「假設上游會用0」。

### 1.2 複數連線回傳、失敗分支與狀態寫入

`0x4957EC mov edi,eax` 保存 selector0 的 `0x806AD0` 返回值；`0x495805 mov ebx,eax` 保存 selector2 回傳值。`0x495807 test edi,edi; je 0x4959B0`，selector0 返回0時進另一個失敗分支；selector2 返回0時 `0x49580F..11` 跳 `0x49597E`，`0x49597E` 經傳輸管理器 vtable+0x20 操作 `selector0`（push0、push1），再記錄錯誤並返回0。**這是兩個獨立 failure gates；不能說只要開始呼叫兩次初始化必定兩條 socket 均已可用。**

當兩者都非0時，後續 `0x495817` 檢查 `owner+0xBF60`（非 connection+0xBF60）。若非0，先在 `0x495838` 呼叫 `0x8063E0` 處理既有物件並可對原 owner 發入短訊息。`0x495872` 存在 OS sleep/延遲 API call（確切 import 以 IAT 導航核查，不能當 attack combo delay）。`0x495935..93D` 再透過 `vtable+0x10` 以 selector0 發送一段長度 `0x39` 的本地初始化資料；這個 **0x39 是局部訊息長度，不是戰鬥 app opcode**。其後 `0x495945..959` 依序呼叫 `vtable+0x14`，對 selector0 與 selector2 返回的連線物件提交接收工作（見 T10-111 的 WSARecv wrapper）。

這顯示 selector0 的連線註冊和接收初始化可在同一函式中發生，**但該函式何時由登入／切線／角色進遊戲的上游呼叫仍不完整**。不能把它表述成「所有玩家進遊戲 selector0 一定存在」，因為 socket/bind/IOCP/tree insertion、兩個連線返回值都可能失敗。

### 1.3 selector1 的獨立上游

`0x495743..0x49575D` 由 `FBA854` vtable+0x18 建立 selector1、port 0x20DF、category2；返回0時 `0x495763..77E` 走 error branch，非0時在 `0x495781..78D` 用 `vtable+0x14` 以該連線物件提交接收。`0x4957A0` 的成功返回1只能表示此 Client 初始化函式的本地流程成功，不能等同 Server 登入或選角接受。

### 1.4 C2S 000A 的具體接合

T10-115 已由 native `0x545B71` 證明：`000A` 建包器在至少有一筆 5-byte row 時，向 `FBA854 vtable+0x10` 傳 `(selector0, FE38D0, FE48D0)`。在 `0xC51748` 這個已確認虛表實作下，它到 `0x8069A0` 使用 manager+0x18 tree 查 selector0，取 `node+0x10` 的 connection，然後調用 `0x8060D0 → 0x806060` 入 Pending；T10-112～114 的後段可達 `WSASend`。**本段的新獨立證據是 selector0 tree key 的真實 caller 來源**，並非重新宣稱全部 gameplay 被解開。

## 2. 對於原版封包的已確認邊界

- **已確認**：caller `0x4957EA` push 參數 (`host`, `0x20E0`, `selector0`, `category2`)，`0x495803` 建 selector2，`0x49575B` 建 selector1；vtable slot 正確；返回值雙重 gate；後續 selector0 初始化資料與 WSARecv 發起。
- **部分確認**：成功完成這些初始化路徑會提供 `000A` 用的 selector0；仍欠 caller 的運行時來源、連線是否經 session/reconnect 替換、category2 的多 session 生命週期。
- **未知**：該 host 是否特定正式伺服器、port 的實際運行時 endpoint、Server 對000A的 opcode解析／接受、S→C 攻擊動作 key13 的真實對應、本地預播／其他玩家廣播、任何 combo window 或技能中斷時序。
- **禁止混淆**：port `0x20E0`（十進位 8416）是 socket 連線埠候選，不是 `0x20E0` 封包 opcode；selector0 是本地 manager tree 的 key；category2 是 queue 分類，與包首 WORD 000A 各有獨立角色。

## 3. 玩家行為矩陣

| 玩家／系統情境 | Client 條件 | C→S | S→C | Actor motion | Server 責任／未知 |
|---|---|---|---|---|---|
| 短按 Z，bank 真映射 ID13，且 selector0 建立成功 | 輸入 phase、UI 消耗、matrix/timer 與000A append 的多層 gate（依 T10-101～116） | 000A 的 6+5N 應用資料在 N>0、連線樹有 selector0 且 send gate 成立時，**原生有界可到 WSASend** | 此段沒有獨立 ACK mapping | 起手先播未知 | Client producer/transport 有界支持；Server 判定待開發 |
| 嘗試連線 selector0，`0x806AD0` 返回0 | `0x495807 test edi` → failure | 此次未建立可由該返回證明的 usable selector0 | 未證任何正常回覆 | 不推論動畫 | 本地 socket failure，非攻擊拒絕 |
| selector0 成功、selector2 失敗 | `0x49580F` → `0x49597E` 的 cleanup/log | 已有 selector0 嘗試，後續是否保留須查 remove/erase | 不可宣稱進入遊戲後持續在線 | unknown | 失敗路徑限制 |
| selector0/2 均成功 | 還須 owner 原有狀態及 receive start | selector0 可以入列初始化訊息；不等於立即發000A | `vtable+0x14` 提交 WSARecv；遊戲回覆 unknown | unknown | 應用後續狀態取決於回包 |
| selector1 單獨初始化 | `0x495743` → `0x49575B`，category2 | 有本地連線建立，是否用於戰鬥資料依 selector | 會提交自己的 WSARecv | unknown | 不混同 selector0 |
| 長按／連按／技能中再次輸入 | 本輪未新增 producer/timer gate | 發包數、時序未確認 | unknown | 連段／取消 unknown | 不使用假造時窗 |

## 4. 三輪深入判定

本次**第1輪達重大新發現門檻**：原先 T10-117 證明 manager tree writer 但欠真實 caller，T10-118 找到三個直接虛呼叫點，明確還原 selector0/category2、selector1/category2、selector2/category2 及兩個初始化返回值的獨立失敗路徑，且跟 T10-115 的 selector0 戰鬥輸出 lookup 接合。具關鍵原生 push/ABI、流程與反證。因此 `T10-118-2`／`T10-118-3` **未啟動**；不代表完整普通攻擊玩法或 Server wire ACK 已還原。

後續 T10-119 優先從 S→C class2 收包的 app key13 motion consumer 回溯 actor motion，並對照這次 selector0 的來源；其次追 `0x4957C0` 真正誰呼叫、角色選角／切線在何狀態建立及移除 selector0；最後深化000A第二WORD由 virtual+0x58 的具體函式實作。需要原版 Server 或封包 trace 才能說明接受/拒絕與廣播，不用 fixture 取代。

## 5. 原生 assembly（BIN 重新反組譯，與先前來源隔離）

### 初始化呼叫者 0x4956b8..0x4957b8

- VA `0x4956b8..0x4957b8`；.text raw `0x94ab8..0x94bb8`。

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004956b8 <.text+0x946b8>:
  4956b8:	39 7d 10             	cmp    DWORD PTR [ebp+0x10],edi
  4956bb:	74 7e                	je     0x49573b
  4956bd:	f6 05 f8 8b fd 00 01 	test   BYTE PTR ds:0xfd8bf8,0x1
  4956c4:	75 1a                	jne    0x4956e0
  4956c6:	83 0d f8 8b fd 00 01 	or     DWORD PTR ds:0xfd8bf8,0x1
  4956cd:	68 10 e3 bc 00       	push   0xbce310
  4956d2:	89 3d fc 8b fd 00    	mov    DWORD PTR ds:0xfd8bfc,edi
  4956d8:	e8 3d cc 3f 00       	call   0x89231a
  4956dd:	83 c4 04             	add    esp,0x4
  4956e0:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4956e6:	89 3d 00 8c fd 00    	mov    DWORD PTR ds:0xfd8c00,edi
  4956ec:	89 3d fc 8b fd 00    	mov    DWORD PTR ds:0xfd8bfc,edi
  4956f2:	8b 01                	mov    eax,DWORD PTR [ecx]
  4956f4:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  4956f7:	6a 01                	push   0x1
  4956f9:	57                   	push   edi
  4956fa:	ff d2                	call   edx
  4956fc:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495702:	8b 01                	mov    eax,DWORD PTR [ecx]
  495704:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  495707:	6a 01                	push   0x1
  495709:	6a 02                	push   0x2
  49570b:	ff d2                	call   edx
  49570d:	39 bb 60 bf 00 00    	cmp    DWORD PTR [ebx+0xbf60],edi
  495713:	74 2e                	je     0x495743
  495715:	68 04 5a c0 00       	push   0xc05a04
  49571a:	e8 41 84 25 00       	call   0x6edb60
  49571f:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495725:	8b 01                	mov    eax,DWORD PTR [ecx]
  495727:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  49572a:	83 c4 04             	add    esp,0x4
  49572d:	6a 01                	push   0x1
  49572f:	6a 01                	push   0x1
  495731:	ff d2                	call   edx
  495733:	89 bb 60 bf 00 00    	mov    DWORD PTR [ebx+0xbf60],edi
  495739:	eb 08                	jmp    0x495743
  49573b:	39 bb 60 bf 00 00    	cmp    DWORD PTR [ebx+0xbf60],edi
  495741:	75 5d                	jne    0x4957a0
  495743:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495749:	8b 01                	mov    eax,DWORD PTR [ecx]
  49574b:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  49574e:	8b 40 18             	mov    eax,DWORD PTR [eax+0x18]
  495751:	6a 02                	push   0x2
  495753:	6a 01                	push   0x1
  495755:	68 df 20 00 00       	push   0x20df
  49575a:	52                   	push   edx
  49575b:	ff d0                	call   eax
  49575d:	8b f0                	mov    esi,eax
  49575f:	3b f7                	cmp    esi,edi
  495761:	75 1e                	jne    0x495781
  495763:	57                   	push   edi
  495764:	ff 15 ec 24 bd 00    	call   DWORD PTR ds:0xbd24ec
  49576a:	33 c0                	xor    eax,eax
  49576c:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  495770:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  495777:	59                   	pop    ecx
  495778:	5f                   	pop    edi
  495779:	5e                   	pop    esi
  49577a:	5b                   	pop    ebx
  49577b:	8b e5                	mov    esp,ebp
  49577d:	5d                   	pop    ebp
  49577e:	c2 0c 00             	ret    0xc
  495781:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495787:	8b 11                	mov    edx,DWORD PTR [ecx]
  495789:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  49578c:	56                   	push   esi
  49578d:	ff d0                	call   eax
  49578f:	68 f4 01 00 00       	push   0x1f4
  495794:	89 b3 60 bf 00 00    	mov    DWORD PTR [ebx+0xbf60],esi
  49579a:	ff 15 04 23 bd 00    	call   DWORD PTR ds:0xbd2304
  4957a0:	b8 01 00 00 00       	mov    eax,0x1
  4957a5:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4957a9:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4957b0:	59                   	pop    ecx
  4957b1:	5f                   	pop    edi
  4957b2:	5e                   	pop    esi
  4957b3:	5b                   	pop    ebx
  4957b4:	8b e5                	mov    esp,ebp
  4957b6:	5d                   	pop    ebp
  4957b7:	c2               	ret    0xc
```

### 雙連線初始化 0x4957c0..0x49583f

- VA `0x4957c0..0x49583f`；.text raw `0x94bc0..0x94c3f`。

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004957c0 <.text+0x947c0>:
  4957c0:	55                   	push   ebp
  4957c1:	8b ec                	mov    ebp,esp
  4957c3:	83 ec 44             	sub    esp,0x44
  4957c6:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4957cb:	33 c5                	xor    eax,ebp
  4957cd:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4957d0:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4957d6:	8b 01                	mov    eax,DWORD PTR [ecx]
  4957d8:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  4957db:	53                   	push   ebx
  4957dc:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4957df:	57                   	push   edi
  4957e0:	6a 02                	push   0x2
  4957e2:	6a 00                	push   0x0
  4957e4:	68 e0 20 00 00       	push   0x20e0
  4957e9:	53                   	push   ebx
  4957ea:	ff d2                	call   edx
  4957ec:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4957f2:	6a 02                	push   0x2
  4957f4:	6a 02                	push   0x2
  4957f6:	8b f8                	mov    edi,eax
  4957f8:	8b 01                	mov    eax,DWORD PTR [ecx]
  4957fa:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  4957fd:	68 de 20 00 00       	push   0x20de
  495802:	53                   	push   ebx
  495803:	ff d2                	call   edx
  495805:	8b d8                	mov    ebx,eax
  495807:	85 ff                	test   edi,edi
  495809:	0f 84 a1 01 00 00    	je     0x4959b0
  49580f:	85 db                	test   ebx,ebx
  495811:	0f 84 67 01 00 00    	je     0x49597e
  495817:	83 be 60 bf 00 00 00 	cmp    DWORD PTR [esi+0xbf60],0x0
  49581e:	74 52                	je     0x495872
  495820:	e8 5b 7e fb ff       	call   0x44d680
  495825:	8b 08                	mov    ecx,DWORD PTR [eax]
  495827:	85 c9                	test   ecx,ecx
  495829:	74 07                	je     0x495832
  49582b:	8b 01                	mov    eax,DWORD PTR [ecx]
  49582d:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  495830:	ff d2                	call   edx
  495832:	8b 86 60 bf 00 00    	mov    eax,DWORD PTR [esi+0xbf60]
  495838:	50                   	push   eax
  495839:	e8 a2 0b 37 00       	call   0x8063e0
  49583e:	b9           	mov    ecx,0x7e
```

### 成功、失敗與初始化後送包 0x49592a..0x4959b0

- VA `0x49592a..0x4959b0`；.text raw `0x94d2a..0x94db0`。

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

0049592a <.text+0x9492a>:
  49592a:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495930:	8b 11                	mov    edx,DWORD PTR [ecx]
  495932:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  495935:	6a 39                	push   0x39
  495937:	8d 45 c0             	lea    eax,[ebp-0x40]
  49593a:	50                   	push   eax
  49593b:	6a 00                	push   0x0
  49593d:	ff d2                	call   edx
  49593f:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495945:	8b 01                	mov    eax,DWORD PTR [ecx]
  495947:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  49594a:	57                   	push   edi
  49594b:	ff d2                	call   edx
  49594d:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495953:	8b 01                	mov    eax,DWORD PTR [ecx]
  495955:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  495958:	53                   	push   ebx
  495959:	ff d2                	call   edx
  49595b:	89 be 64 bf 00 00    	mov    DWORD PTR [esi+0xbf64],edi
  495961:	5f                   	pop    edi
  495962:	89 9e 68 bf 00 00    	mov    DWORD PTR [esi+0xbf68],ebx
  495968:	b8 01 00 00 00       	mov    eax,0x1
  49596d:	5b                   	pop    ebx
  49596e:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  495971:	33 cd                	xor    ecx,ebp
  495973:	e8 89 b6 3f 00       	call   0x891001
  495978:	8b e5                	mov    esp,ebp
  49597a:	5d                   	pop    ebp
  49597b:	c2 04 00             	ret    0x4
  49597e:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  495984:	8b 01                	mov    eax,DWORD PTR [ecx]
  495986:	8b 50 20             	mov    edx,DWORD PTR [eax+0x20]
  495989:	6a 01                	push   0x1
  49598b:	6a 00                	push   0x0
  49598d:	ff d2                	call   edx
  49598f:	68 3c 5a c0 00       	push   0xc05a3c
  495994:	e8 c7 81 25 00       	call   0x6edb60
  495999:	83 c4 04             	add    esp,0x4
  49599c:	5f                   	pop    edi
  49599d:	33 c0                	xor    eax,eax
  49599f:	5b                   	pop    ebx
  4959a0:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4959a3:	33 cd                	xor    ecx,ebp
  4959a5:	e8 57 b6 3f 00       	call   0x891001
  4959aa:	8b e5                	mov    esp,ebp
  4959ac:	5d                   	pop    ebp
  4959ad:	c2 04 00             	ret    0x4
```

### 連線實體與 category writer 0x806ad0..0x806b39

- VA `0x806ad0..0x806b39`；.text raw `0x405ed0..0x405f39`。

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00806ad0 <.text+0x405ad0>:
  806ad0:	55                   	push   ebp
  806ad1:	8b ec                	mov    ebp,esp
  806ad3:	83 e4 f8             	and    esp,0xfffffff8
  806ad6:	83 ec 24             	sub    esp,0x24
  806ad9:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  806ade:	33 c4                	xor    eax,esp
  806ae0:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  806ae4:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  806aeb:	53                   	push   ebx
  806aec:	56                   	push   esi
  806aed:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  806af0:	57                   	push   edi
  806af1:	8b f9                	mov    edi,ecx
  806af3:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  806af7:	75 15                	jne    0x806b0e
  806af9:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  806b00:	74 07                	je     0x806b09
  806b02:	e8 59 44 c9 ff       	call   0x49af60
  806b07:	eb 05                	jmp    0x806b0e
  806b09:	e8 f2 44 c9 ff       	call   0x49b000
  806b0e:	8b 0d 58 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba858
  806b14:	6a 01                	push   0x1
  806b16:	e8 35 ee ff ff       	call   0x805950
  806b1b:	8b d8                	mov    ebx,eax
  806b1d:	85 db                	test   ebx,ebx
  806b1f:	0f 84 b2 01 00 00    	je     0x806cd7
  806b25:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  806b28:	56                   	push   esi
  806b29:	c7 83 b4 a0 00 00 02 	mov    DWORD PTR [ebx+0xa0b4],0x2
  806b30:	00 00 00 
  806b33:	89 83 80 a0 00 00    	mov    DWORD PTR [ebx+0xa080],eax
```

### writer 入樹 0x806c75..0x806ce0

- VA `0x806c75..0x806ce0`；.text raw `0x406075..0x4060e0`。

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00806c75 <.text+0x405c75>:
  806c75:	d7                   	xlat   BYTE PTR ds:[ebx]
  806c76:	83 f8 ff             	cmp    eax,0xffffffff
  806c79:	74 85                	je     0x806c00
  806c7b:	e8 a0 f9 ff ff       	call   0x806620
  806c80:	8b 10                	mov    edx,DWORD PTR [eax]
  806c82:	6a 00                	push   0x0
  806c84:	53                   	push   ebx
  806c85:	52                   	push   edx
  806c86:	56                   	push   esi
  806c87:	ff 15 78 22 bd 00    	call   DWORD PTR ds:0xbd2278
  806c8d:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  806c91:	8d 45 10             	lea    eax,[ebp+0x10]
  806c94:	8d 77 18             	lea    esi,[edi+0x18]
  806c97:	50                   	push   eax
  806c98:	8d 44 24 18          	lea    eax,[esp+0x18]
  806c9c:	8b ce                	mov    ecx,esi
  806c9e:	e8 1d cc 03 00       	call   0x8438c0
  806ca3:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  806ca7:	3b 47 1c             	cmp    eax,DWORD PTR [edi+0x1c]
  806caa:	74 0c                	je     0x806cb8
  806cac:	50                   	push   eax
  806cad:	8d 4c 24 18          	lea    ecx,[esp+0x18]
  806cb1:	51                   	push   ecx
  806cb2:	56                   	push   esi
  806cb3:	e8 d8 fb fa ff       	call   0x7b6890
  806cb8:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  806cbb:	8d 7c 24 14          	lea    edi,[esp+0x14]
  806cbf:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  806cc3:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  806cc7:	e8 54 82 d7 ff       	call   0x57ef20
  806ccc:	50                   	push   eax
  806ccd:	56                   	push   esi
  806cce:	8d 74 24 1c          	lea    esi,[esp+0x1c]
  806cd2:	e8 79 7b d7 ff       	call   0x57e850
  806cd7:	8b 4c 24 2c          	mov    ecx,DWORD PTR [esp+0x2c]
  806cdb:	5f                   	pop    edi
  806cdc:	5e                   	pop    esi
  806cdd:	8b c3                	mov    eax,ebx
  806cdf:	5b                   	pop    ebx
```

### 戰鬥端 selector0 查找與送入佇列 0x8069a0..0x8069f6

- VA `0x8069a0..0x8069f6`；.text raw `0x405da0..0x405df6`。

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

008069a0 <.text+0x4059a0>:
  8069a0:	55                   	push   ebp
  8069a1:	8b ec                	mov    ebp,esp
  8069a3:	51                   	push   ecx
  8069a4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  8069a7:	56                   	push   esi
  8069a8:	8b f1                	mov    esi,ecx
  8069aa:	8d 4d 08             	lea    ecx,[ebp+0x8]
  8069ad:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  8069b0:	51                   	push   ecx
  8069b1:	8d 4e 18             	lea    ecx,[esi+0x18]
  8069b4:	8d 45 fc             	lea    eax,[ebp-0x4]
  8069b7:	e8 04 cf 03 00       	call   0x8438c0
  8069bc:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  8069bf:	3b 46 1c             	cmp    eax,DWORD PTR [esi+0x1c]
  8069c2:	5e                   	pop    esi
  8069c3:	74 07                	je     0x8069cc
  8069c5:	8b 48 10             	mov    ecx,DWORD PTR [eax+0x10]
  8069c8:	85 c9                	test   ecx,ecx
  8069ca:	75 08                	jne    0x8069d4
  8069cc:	33 c0                	xor    eax,eax
  8069ce:	8b e5                	mov    esp,ebp
  8069d0:	5d                   	pop    ebp
  8069d1:	c2 0c 00             	ret    0xc
  8069d4:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  8069d7:	85 c0                	test   eax,eax
  8069d9:	75 0b                	jne    0x8069e6
  8069db:	b8 01 00 00 00       	mov    eax,0x1
  8069e0:	8b e5                	mov    esp,ebp
  8069e2:	5d                   	pop    ebp
  8069e3:	c2 0c 00             	ret    0xc
  8069e6:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  8069e9:	50                   	push   eax
  8069ea:	52                   	push   edx
  8069eb:	e8 e0 f6 ff ff       	call   0x8060d0
  8069f0:	8b e5                	mov    esp,ebp
  8069f2:	5d                   	pop    ebp
  8069f3:	c2 0c 00             	ret    0xc
```

**重現指令：** `sha256sum Tartaros.bin Tartaros.exe` 與各章對應 `objdump -D -Mintel --start-address=... --stop-address=... Tartaros.bin`。