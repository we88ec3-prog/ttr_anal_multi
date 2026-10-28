# T03-14 — parent/worker 指標來源、初始化與虛擬呼叫的有界證據審核

- 日期：2026-10-28T23:45:45+08:00；研究者：chatgpt-web roy。
- 來源：KR 原始 `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀 GNU objdump x86；沒有執行／修改 Client。
- `.text` VA 起點 `0x401000`，raw `0x400`；raw offset = VA − `0x400C00`（僅對 `.text`）。
- 分支：`t03/roy/chatgpt-web`；比對開始時 `main` 無落後。正式段號 `T03-14`。
- 已查共用索引 `shared/verified-knowledge/README.md`：尚無正式 FULL-PASS 條目；T01 歷史導航不自動提升 native 完成狀態。
- 前段原稿：`kr-temp-roy/20261028-231843-chatgpt-web-roy-T03-13-worker-vtable-provenance-budget.md`、T03-12/11/10。先前 `+0x140` 指標關聯成立，但 vtable target **未確認**。

## 一、研究結論與範圍

**新核實的類型／指標來源約束**：`0x48BE50` 從參數 `[EBP+8]` 載入 parent 到 EBX（`0x48BE90`），此函式不是已被證明的 parent constructor；它於執行後段 `0x48C0E0` 才取 `parent+0x140` 呼叫 `0x804650`。`0x49198A` 的 worker 來源則是 `[ESP+0x20]` → EDI → `LEA EBX,[EDI+0x140]`，屬獨立上層呼叫路徑。二者共同描述兩個**使用**同樣相對 offset 的流程，不足證明建立點或 vtable 安裝者。這是對 T03-10～13 「沿父物件建構」一詞的更嚴格修正。

**原生已確認**：`0x804650` 初始化部分 worker 狀態（`+0x8C=0`）、取得或初始化共用傳輸資源、配置 `0x5C` byte 獨立傳輸物件；其 `MOV [ESI],0xC51748` 作用於新配置物件，不是 `[EDI]`。`0x804740` 接收處理在 `0x80486D` 從 `[worker]` 載入 vtable，讀 `[vtable]` 並間接呼叫；`+8/+0xC` 同理。這些確認**vtable 消費**，沒有確認其初始化點。

**交叉排除**：另一初始化流程 `0x491607 → alloc 0x57C → 0x6F1370` 確實建立全域 `0xFBA80C` 的另種物件，`0x6F1370` 初始清零 `[ESI]`、`[ESI+4]`，另有 `+0x60/+0x260/+0x378/+0x478` 緩衝，**不可因同處 0x49xxxx 的調度路徑就將此物件認定是 `parent+0x140` 的 vtable 來源**。不確定此類物件與接收 worker 的關係，不能混用。

**未突破**：`0x80486D` 的具體虛擬 target、真正 parent 配置／建構及可能的派生覆寫；沒有新的原生 Client 選角批准／拒絕業務 opcode。故這是 **有界訂正及上游排除**，而非宣稱 S→C 已完成。

## 二、第一輪：沿 parent 參數回溯，確立兩條使用路徑

`0x48BE50` 的函式 prologue 與 `0x48BE90` 顯示從 `[EBP+8]` 取外部傳入 pointer；其 `0x48C0E0` 使用 `EBX+0x140`。這不是 C++ new/ctor 的已證實證據，也不保證所有呼叫都使用同一實例。

`0x49198A` 從 `[ESP+0x20]` 取得 parent 指標，傳入地址 `[parent+0x140]` 至 `0x804740`。目前沒有 `[parent+0x140] = <vtable>` 的第一手寫入證據。

## 三、第二輪：分離獨立傳輸物件與 worker vtable

`0x8046D7` 以 `push 0x5C` 配置傳輸實例，成功時 `ESI` 指向新物件，`0x8046F7 mov [esi],0xc51748`。`0x80470F mov [0xfba854],ecx` 寫的是傳輸全域指標。該記憶體寫入不是 `parent+0x140` 第一 DWORD。

`0x80486D` 係從 `worker` 的第 0 DWORD 載入虛擬表，再取表第 0 項間接呼叫；其他 `+8/+0xC` 虛擬項不等於已知 `0xC51748`。若將二者合併，會把 T03 接收結果處理錯導至 T02 傳輸方法；此輪予以排除。

## 四、第三輪：相似物件反證與原生含意

`0x491607` 的 `0x57C` 配置呼叫 `0x6F1370`；`0x6F1370` 會清空 `[ESI]` 與 `[ESI+4]`，並初始化一組明顯更大的緩衝。這不等於 `parent+0x140` 的 vtable 安裝。因此對高層指標，應分別追蹤生命週期與 class identity；在沒有 alias 證據時不合併。

此輪亦核對 T03-13 的正確時間預算（`worker+0x84`、`+0x58/+0x59`）與 T03-11 的發送排程（`0x804A40`），未發現它們能直接解出 `vtable+0`。

本正式段因三輪均未定位要求的 concrete virtual target 而停止，不提前宣稱重大發現；已經完成三輪有界核對及錯誤路徑排除。下一段應更換檢索策略，從真正 `parent` 分配點／上層 API ownership 或 vtable 常數交叉引用切入。

## 五、玩家情境與剩餘工作（嚴格分級）

| 玩家情境 | C→S | 接收資料／worker | 本段可證 Client 狀態 | 等級 |
|---|---|---|---|---|
| 選角操作 | T03-3 的 `42 00 XX YY` builder、T03-4～6 共用傳輸鏈 | 未配對到原版 S→C reply | 無可證實選角成功或拒絕旗標 | 部分確認／Client 待逆向 |
| 收到傳輸 frame | T03-7 解框，T03-8/9 中繼及 worker poll | `0x80486D` vtable+0，實際 target 未知 | 資料消費與回收屬通用程序 | 有界原生／待跨功能整合 |
| Server 回覆選角 | 原版 Server 內部策略不作驗收要求 | Reply opcode/length/handler 尚待找 | UI、角色狀態、T05 交接未證實 | Client 待逆向；Server 待開發 |
| 實際進入世界 | 不能因傳輸完成而推斷 | 未捕獲原版雙向封包 | 需實測 | 待遊玩驗證 |

**分工**：T03 只管登入／選角業務；T02 為通用傳輸 owner，T04 管角色資料原生權威，T05 管場景切換，T06 管 UI 資源。沒有更動其他 Task 原稿、owner、catalog；沒有將 T01 source-only 主張升級 FULL-PASS。

## 六、下一段 T03-15 具體入口

1. 追查 `0x48BE50` 的直接／間接 caller，尋找 parent 的 allocation/constructor（不把初始化用的 `0x804650` 當建構點）；與 `0x49198A` 的 `[ESP+0x20]` parent 做 alias 對齊。
2. 對 \`.rdata\` vtable candidate 和 parent `+0x140` 寫入使用多種 register、memcpy、base-class call 形式追查，並在確認 real target 後才開始業務 opcode dispatcher 的歸類。
3. 真正選角批准／拒絕的 opcode、payload、handler 與世界轉場仍為待證，禁止由 AI fixture `42→43/69` 推斷原版。

## 七、原始 x86 逐段證據（GNU objdump、未手造）

### Caller parent source 0x48BE50

```asm
  48be50:	55                   	push   ebp
  48be51:	8b ec                	mov    ebp,esp
  48be53:	83 e4 f8             	and    esp,0xfffffff8
  48be56:	6a ff                	push   0xffffffff
  48be58:	68 ca a0 94 00       	push   0x94a0ca
  48be5d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  48be63:	50                   	push   eax
  48be64:	81 ec 60 01 00 00    	sub    esp,0x160
  48be6a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  48be6f:	33 c4                	xor    eax,esp
  48be71:	89 84 24 58 01 00 00 	mov    DWORD PTR [esp+0x158],eax
  48be78:	53                   	push   ebx
  48be79:	56                   	push   esi
  48be7a:	57                   	push   edi
  48be7b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  48be80:	33 c4                	xor    eax,esp
  48be82:	50                   	push   eax
  48be83:	8d 84 24 70 01 00 00 	lea    eax,[esp+0x170]
  48be8a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  48be90:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  48be93:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  48be97:	50                   	push   eax
  48be98:	ff 15 f8 20 bd 00    	call   DWORD PTR ds:0xbd20f8
  48be9e:	0f b7          	movzx  ecx,WORD PTR [esp+0x28]
```
### Parent +0x140 initialization 0x48C0B5

```asm
  48c0b5:	f6 05 d8 37 fe 00 01 	test   BYTE PTR ds:0xfe37d8,0x1
  48c0bc:	c7 05 78 3d d6 00 00 	mov    DWORD PTR ds:0xd63d78,0x0
  48c0c3:	00 00 00 
  48c0c6:	75 18                	jne    0x48c0e0
  48c0c8:	09 3d d8 37 fe 00    	or     DWORD PTR ds:0xfe37d8,edi
  48c0ce:	e8 1d 93 37 00       	call   0x8053f0
  48c0d3:	68 a0 0b bd 00       	push   0xbd0ba0
  48c0d8:	e8 3d 62 40 00       	call   0x89231a
  48c0dd:	83 c4 04             	add    esp,0x4
  48c0e0:	8d bb 40 01 00 00    	lea    edi,[ebx+0x140]
  48c0e6:	e8 65 85 37 00       	call   0x804650
  48c0eb:	6a 34                	push   0x34
  48c0ed:	6a 01                	push   0x1
  48c0ef:	6a 01                	push   0x1
  48c0f1:	68 24 57 c0 00       	push   0xc05724
  48c0f6:	8d 94 24 54 01 00 00 	lea    edx,[esp+0x154]
  48c0fd:	e8 ae cd 00 00       	call   0x498eb0
  48c102:	83 c4 10             	add    esp,0x10
  48c105:	e8 76 15 fc ff       	call   0x44d680
  48c10a:	8b                 	mov    ecx,DWORD PTR [eax]
```
### Receive loop caller 0x49196E

```asm
  49196e:	8b 0d d4 ac fb 00    	mov    ecx,DWORD PTR ds:0xfbacd4
  491974:	3b cb                	cmp    ecx,ebx
  491976:	74 07                	je     0x49197f
  491978:	8b 11                	mov    edx,DWORD PTR [ecx]
  49197a:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  49197d:	ff d0                	call   eax
  49197f:	8b 7c 24 20          	mov    edi,DWORD PTR [esp+0x20]
  491983:	8d 9f 40 01 00 00    	lea    ebx,[edi+0x140]
  491989:	53                   	push   ebx
  49198a:	e8 b1 2d 37 00       	call   0x804740
  49198f:	f6 05 cc 10 fc 00  	test   BYTE PTR ds:0xfc10cc,0x1
```
### Worker initialize 0x804650

```asm
00804650 <.text+0x403650>:
  804650:	55                   	push   ebp
  804651:	8b ec                	mov    ebp,esp
  804653:	6a ff                	push   0xffffffff
  804655:	68 99 c4 91 00       	push   0x91c499
  80465a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  804660:	50                   	push   eax
  804661:	51                   	push   ecx
  804662:	56                   	push   esi
  804663:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  804668:	33 c5                	xor    eax,ebp
  80466a:	50                   	push   eax
  80466b:	8d 45 f4             	lea    eax,[ebp-0xc]
  80466e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  804674:	f6 05 54 33 fe 00 01 	test   BYTE PTR ds:0xfe3354,0x1
  80467b:	c7 87 8c 00 00 00 00 	mov    DWORD PTR [edi+0x8c],0x0
  804682:	00 00 00 
  804685:	75 27                	jne    0x8046ae
  804687:	83 0d 54 33 fe 00 01 	or     DWORD PTR ds:0xfe3354,0x1
  80468e:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  804695:	e8 86 2a 00 00       	call   0x807120
  80469a:	68 90 0b bd 00       	push   0xbd0b90
  80469f:	e8 76 dc 08 00       	call   0x89231a
  8046a4:	83 c4 04             	add    esp,0x4
  8046a7:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  8046ae:	83 3d 58 a8 fb 00 00 	cmp    DWORD PTR ds:0xfba858,0x0
  8046b5:	75 15                	jne    0x8046cc
  8046b7:	83 3d 5c a8 fb 00 00 	cmp    DWORD PTR ds:0xfba85c,0x0
  8046be:	74 07                	je     0x8046c7
  8046c0:	e8 9b 68 c9 ff       	call   0x49af60
  8046c5:	eb 05                	jmp    0x8046cc
  8046c7:	e8 34 69 c9 ff       	call   0x49b000
  8046cc:	a1 58 a8 fb 00       	mov    eax,ds:0xfba858
  8046d1:	50                   	push   eax
  8046d2:	e8 49 10 00 00       	call   0x805720
  8046d7:	6a 5c                	push   0x5c
  8046d9:	e8 8a cb 08 00       	call   0x891268
  8046de:	8b f0                	mov    esi,eax
  8046e0:	83 c4 04             	add    esp,0x4
  8046e3:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  8046e6:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  8046ed:	85 f6                	test   esi,esi
  8046ef:	74 10                	je     0x804701
  8046f1:	56                   	push   esi
  8046f2:	e8 69 f6 ff ff       	call   0x803d60
  8046f7:	c7 06 48 17 c5 00    	mov    DWORD PTR [esi],0xc51748
  8046fd:	8b ce                	mov    ecx,esi
  8046ff:	eb 02                	jmp    0x804703
  804701:	33 c9                	xor    ecx,ecx
  804703:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  80470a:	8b 11                	mov    edx,DWORD PTR [ecx]
  80470c:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  80470f:	89 0d 54 a8 fb 00    	mov    DWORD PTR ds:0xfba854,ecx
  804715:	ff d0                	call   eax
  804717:	8b 35 a0 25 bd 00    	mov    esi,DWORD PTR ds:0xbd25a0
  80471d:	ff d6                	call   esi
  80471f:	89 47 60             	mov    DWORD PTR [edi+0x60],eax
  804722:	ff d6                	call   esi
  804724:	89 47 34             	mov    DWORD PTR [edi+0x34],eax
  804727:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  80472a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  804731:	59                   	pop    ecx
  804732:	5e                   	pop    esi
  804733:	8b e5                	mov    esp,ebp
```
### Worker virtual dispatch 0x804850

```asm
00804850 <.text+0x403850>:
  804850:	ff d7                	call   edi
  804852:	8b 75 f0             	mov    esi,DWORD PTR [ebp-0x10]
  804855:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  804858:	8b 13                	mov    edx,DWORD PTR [ebx]
  80485a:	8b 12                	mov    edx,DWORD PTR [edx]
  80485c:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  80485f:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  804862:	51                   	push   ecx
  804863:	50                   	push   eax
  804864:	8d 46 08             	lea    eax,[esi+0x8]
  804867:	50                   	push   eax
  804868:	8b 06                	mov    eax,DWORD PTR [esi]
  80486a:	50                   	push   eax
  80486b:	8b cb                	mov    ecx,ebx
  80486d:	ff d2                	call   edx
  80486f:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  804872:	ff d7                	call   edi
  804874:	2b 45 e8             	sub    eax,DWORD PTR [ebp-0x18]
  804877:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  80487a:	8b f8                	mov    edi,eax
  80487c:	8b 03                	mov    eax,DWORD PTR [ebx]
  80487e:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  804881:	57                   	push   edi
  804882:	56                   	push   esi
  804883:	51                   	push   ecx
  804884:	8b cb                	mov    ecx,ebx
  804886:	ff d2                	call   edx
  804888:	83 ff 28             	cmp    edi,0x28
  80488b:	76 16                	jbe    0x8048a3
  80488d:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  804890:	8b 03                	mov    eax,DWORD PTR [ebx]
  804892:	8b 93 8c 00 00 00    	mov    edx,DWORD PTR [ebx+0x8c]
  804898:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  80489b:	57                   	push   edi
  80489c:	56                   	push   esi
  80489d:	51                   	push   ecx
  80489e:	52                   	push   edx
  80489f:	8b cb                	mov    ecx,ebx
  8048a1:	ff d0                	call   eax
  8048a3:	f6       	test   BYTE PTR ds:0xfe3354,0x1
```
### Alternative 0x57C-byte global instance 0x4915FE

```asm
  4915fe:	a1 0c a8 fb 00       	mov    eax,ds:0xfba80c
  491603:	3b c3                	cmp    eax,ebx
  491605:	75 21                	jne    0x491628
  491607:	68 7c 05 00 00       	push   0x57c
  49160c:	e8 57 fc 3f 00       	call   0x891268
  491611:	83 c4 04             	add    esp,0x4
  491614:	3b c3                	cmp    eax,ebx
  491616:	74 09                	je     0x491621
  491618:	8b f0                	mov    esi,eax
  49161a:	e8 51 fd 25 00       	call   0x6f1370
  49161f:	eb 02                	jmp    0x491623
  491621:	33 c0                	xor    eax,eax
  491623:	a3 0c a8 fb 00       	mov    ds:0xfba80c,eax
  491628:	39 58 20             	cmp    DWORD PTR [eax+0x20],ebx
  49162b:	0f         	je     0x4916ba
```
### Alternative instance constructor 0x6F1370

```asm
006f1370 <.text+0x2f0370>:
  6f1370:	57                   	push   edi
  6f1371:	33 ff                	xor    edi,edi
  6f1373:	89 3e                	mov    DWORD PTR [esi],edi
  6f1375:	89 7e 04             	mov    DWORD PTR [esi+0x4],edi
  6f1378:	c7 46 20 01 00 00 00 	mov    DWORD PTR [esi+0x20],0x1
  6f137f:	68 00 01 00 00       	push   0x100
  6f1384:	8d 46 60             	lea    eax,[esi+0x60]
  6f1387:	57                   	push   edi
  6f1388:	89 7e 08             	mov    DWORD PTR [esi+0x8],edi
  6f138b:	89 7e 0c             	mov    DWORD PTR [esi+0xc],edi
  6f138e:	89 7e 10             	mov    DWORD PTR [esi+0x10],edi
  6f1391:	89 7e 14             	mov    DWORD PTR [esi+0x14],edi
  6f1394:	89 7e 18             	mov    DWORD PTR [esi+0x18],edi
  6f1397:	50                   	push   eax
  6f1398:	89 7e 1c             	mov    DWORD PTR [esi+0x1c],edi
  6f139b:	e8 c0 d4 1a 00       	call   0x89e860
  6f13a0:	68 00 01 00 00       	push   0x100
  6f13a5:	8d 8e 60 02 00 00    	lea    ecx,[esi+0x260]
  6f13ab:	57                   	push   edi
  6f13ac:	51                   	push   ecx
  6f13ad:	e8 ae d4 1a 00       	call   0x89e860
  6f13b2:	33 c0                	xor    eax,eax
  6f13b4:	89 86 60 03 00 00    	mov    DWORD PTR [esi+0x360],eax
  6f13ba:	68 80 00 00 00       	push   0x80
  6f13bf:	89 86 64 03 00 00    	mov    DWORD PTR [esi+0x364],eax
  6f13c5:	8d 96 78 03 00 00    	lea    edx,[esi+0x378]
  6f13cb:	57                   	push   edi
  6f13cc:	89 86 70 03 00 00    	mov    DWORD PTR [esi+0x370],eax
  6f13d2:	52                   	push   edx
  6f13d3:	89 86 74 03 00 00    	mov    DWORD PTR [esi+0x374],eax
  6f13d9:	e8 82 d4 1a 00       	call   0x89e860
  6f13de:	68 80 00 00 00       	push   0x80
  6f13e3:	8d 86 78 04 00 00    	lea    eax,[esi+0x478]
  6f13e9:	57                   	push   edi
  6f13ea:	50                   	push   eax
  6f13eb:	e8 70 d4 1a 00       	call   0x89e860
  6f13f0:	33 c0                	xor    eax,eax
  6f13f2:	6a 30                	push   0x30
  6f13f4:	89 46 24             	mov    DWORD PTR [esi+0x24],eax
  6f13f7:	8d 4e 30             	lea    ecx,[esi+0x30]
  6f13fa:	57                   	push   edi
  6f13fb:	89 46 28             	mov    DWORD PTR [esi+0x28],eax
  6f13fe:	51                   	push   ecx
  6f13ff:	89 46 2c             	mov    DWORD PTR [esi+0x2c],eax
  6f1402:	e8 59 d4 1a 00       	call   0x89e860
  6f1407:	68 80 00 00 00       	push   0x80
  6f140c:	8d 96 f8 04 00 00    	lea    edx,[esi+0x4f8]
  6f1412:	57                   	push   edi
  6f1413:	52                   	push   edx
  6f1414:	e8 47 d4 1a 00       	call   0x89e860
  6f1419:	83 c4 48             	add    esp,0x48
  6f141c:	89 be 78 05 00 00    	mov    DWORD PTR [esi+0x578],edi
  6f1422:	8b c6                	mov    eax,esi
  6f1424:	5f                   	pop    edi
  6f1425:	c3                   	ret
```
