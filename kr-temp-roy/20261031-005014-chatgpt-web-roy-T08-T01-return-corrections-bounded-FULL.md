# T08 — T01 最新退回定向原生勘誤與尚待全文複驗矩陣（KR BIN-first）

- 產製時間：20261031-005014 Asia/Taipei；作者：chatgpt-web roy；研究版本：KR `Tartaros.bin`，12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- GitHub 開工基準：`main@e434bfa657df9f21b88147a0d5c9262b81e0b2b8`；`kr/tasks/T08/README.md` blob `c5cbcc9c0beb3728517ab52b6d77a8419d2af489`；當下 T08 inbox 無 RR。
- PE映射：`.text` VA 0x401000 / raw 0x400，本文所有 code 的 `raw=VA-0x400C00`；`.rdata` VA 0xBD2000/raw 0x7D0600，絕不可拿錯誤 `-0x400` 改動 `.rdata` 中的絕對函式指標。
- **保留全部舊原稿**；本勘誤獨立追加，不修改 T01 reviewer 歷史裁決。不將個別窗口 bytes 再驗視作原稿全部 FULL-PASS、或逕行把 NEEDS_FIX 改為 RESOLVED。

## 最新狀態與處理結果

| 退回ID | main狀態 | 此次定向修正 | 全文／T01驗收 |
|---|---|---|---|
| T08-153-ABI-001 | NEEDS_FIX | 精確改正 key 指標／iterator 輸出槽及stack重用；完整 callers 保留 | 待 T01 語意複驗 |
| T08-155-ASM-001 | NEEDS_FIX | 從7B6890入口重解7B698E/7B6991兩child搬移CFG | 待 T01 全文複驗 |
| T08-157-001 | NEEDS_FIX | 4B297A→2980→2982真實指令邊界（與201補證去重） | 待 T01 語意複驗 |
| T08-183-001 | NEEDS_FIX | 7B8680更正為hash-bucket／list unlink，否定ordered-tree rotation | 需全文源主張再驗 |
| T08-187-001 | NEEDS_FIX | 7F6FBF push30、7F6FC1 manager→EDI、null及wrapper+2C重驗 | 待 T01 語意複驗 |
| LEGACY-MAPPING-001 | NEEDS_FIX | 24篇來源座標負差裁決建立更正限制，絕不套用跨section平移 | **24篇逐篇完整版重建尚未完成** |
| T08-173-001 / 196-001 | RESOLVED | 不重開；引用T08-177/197既有正式修訂 | 已由T01結案；舊稿仍FAILED |

### 153：search key vs erase successor iterator

`0x4DFBC0`：`[ebp+8]`先存要找的 DWORD key；在`4DFBC9` `lea eax,[ebp+8]`向`82EF00`傳入search-key **地址**，`4DFBD3 ecx=&owner+8`傳入主樹。命中後`4DFC18..1E`依序 `push node`、`lea ecx,[ebp+8]; push ecx`、`push tree`，到`7B6890`：第二個引數是輸出 iterator slot 的地址而非 key 值。由於 node 已定位，此時 caller 把相同stack槽重用。`7B6890`先呼叫`49E6A0`取得 successor，`7B6AE3..E6`寫 `[out-slot] = successor`；`4DFC90`另一個 consumer `4DFCE6 mov esi,[eax]`則得到安全的後繼節點而非原node free後的指標。

不能將所有呼叫點的 `&[ebp+8]` 理解為永遠相同的型別／生命期；由具體callee語意決定。共享 FULL-PASS 項 `CK-CLIENT-EXACT-TREE-LOOKUP-01` 與 `CK-CLIENT-ERASE-NEXT-ITERATOR-01` 已限定接受搜索／erase子主張，不等同舊 T08-153 全篇通過。

### 155：two-child relocation 指令邊界

**不得從7B698F/90/92當成獨立指令解析**。在`0x7B698E: 89 41 04`為`mov [ecx+4],eax`，`0x7B6991: EB 0E`為`jmp 0x7B69A1`。此分支屬`7B6890`從正常函式入口經 two-child 處理導入的內部分支；和原node釋放、successor輸出分開。既有包含803等有限字元片段的錯位解碼不再引用，完整 CFG 請以T01 `native-cfg/007b6890.json`和下列原碼窗口為準。

### 157：命令26的唯一有效短序列

`0x4B297A: 3B 05 3C B1 FA 00 = cmp eax,[0xFAB13C]` (6 bytes)；`4B2980: 74 07 = je 4B2989`；`4B2982: 8B 70 10 = mov esi,[eax+0x10]`。`4B297C`位於前條指令absolute displacement內，錯解的`cmp al`／`cli`不是另一條有效控制路徑。此修訂與尚未提交的T08-201的第5.2／附錄B對應；不把局部修訂冒稱整份舊157完成全文驗收。

### 183：hash index/list 與 actor RB tree 是不同容器

`7B868B`從`[esi+0x20]`取hash/mask相關欄，`7B8690`等比較／迭代字串key及hash，`7B86DE`取得`&index+4`，其後`719B20`按雙向list link unlink/free node。**這不是RB ordered-tree rebalance／rotate。** 原來manager最後引用釋放順序，若其獨立證據成立應保留；但原稿把此helper描述為「樹節點移除／調整」之主張失效，不能類比0x7B6890的actor樹erase。仍須獨立核對old183全文所有引用此型別的衍生結論。

### 187：manager來源與null edge

`7F6FBA call 7B8180` 的返回值先由`7F6FC1 mov edi,eax`保留為 manager；`7F6FBF push 0x30`則是給`891268`的 allocation size。`7F6FC8 mov esi,eax`保存新wrapper，`7F6FD7 test esi,esi; 7F6FD9 je 7F7021`：null路回`eax=0`，不呼叫acquire。非null路 `7F6FDB push edi ; 7F6FDC call 7DCFB0`，`7F700B mov [esi+0x2C],eax`將 acquire 結果保存於wrapper；`wrapper+0x2C`不是manager指標原值。未證所有acquire失敗可能性；不能把manager與wrapper所有權混為一個指標。

## LEGACY-MAPPING：24來源退回維持 NEEDS_FIX

T01當前裁決顯示24篇來源受影響；其中18篇保存的1263條機器碼均能在標示VA減0x400後找到匹配，但這是**已檢該組來源列的位址座標問題**，不是全檔任意rebase合法性。其他6篇無該逐列統計，不可宣稱通過。24篇必須從原PE code有效函式entry重新產生 caller/callee/vtable/CFG，再逐條重新判斷語意與指標類型。清單：

- T08-129 `129-global-22-bucket-dispatcher-resolved`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-130 `130-dispatcher-phase-and-queue-lifecycle`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-131 `131-queue-sort-constructor-and-comparator`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-132 `132-second-queue-caller-and-producer-boundary`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-133 `133-record-registry-7E8640`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-134 `134-two-caller-record-name-routing`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-135 `135-vector-append-owner-isolation`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-136 `136-priority-queue-consumer-reset-boundary`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-137 `137-B-writer-xref-audit`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-138 `138-manager-vtable-and-entry-type-boundary`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-139 `139-B-comparator-ABI-and-two-callers`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-140 `140-B-queue-to-global-bucket-evidence-boundary`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-141 `141-B-vector-producer-confirmed`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-142 `142-B-producer-control-gates`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-143 `143-B-vector-growth-and-alias-safety`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-144 `144-B-producer-consumer-link-and-vtable-limit`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-145 `145-embedded-vptr-construction-candidate`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-146 `146-vtable-slots-and-rdata-section-mapping`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-147 `147-subobject-vptr-destruction-lifetime-boundary`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-148 `148-priority-entry-dynamic-identification-plan`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-149 `149-ctor-callers-and-b-entry-vtable-abi`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-150 `150-shared-control-block-construction-and-owner-transfer`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-151 `151-control-block-two-stage-release-and-host-dispatch-boundaries`（舊正文保留、衍生主張待逐篇重新驗收）
- T08-152 `152-vtable-entry-boundary-negative-xrefs`（舊正文保留、衍生主張待逐篇重新驗收）

**本次範圍界線：** 修復上述5項的具體原始反證與新202新證據，不宣稱24篇完整改寫、也不將映射更正自動推展至 `.rdata`／`.data`。這部分仍標 NEEDS_FIX，解除條件為每一篇精確source blob、correct PE VA+raw、新完整CFG及全部受影響主張的可稽核勘誤。

## BIN 有界組語附錄

以下由本次相同原件直接抽取，非工具猜補、非錯位節區轉換；結尾 stop 排他，跨窗後續另見標示的完整函式紀錄。正式 T01 複驗還需對全文主張重新走 CFG。

### `004DFBC0..004DFC2A` (raw `0xDEFC0..0xDF02A`, stop排他)

```asm
4dfbc0:	55                   	push   ebp
  4dfbc1:	8b ec                	mov    ebp,esp
  4dfbc3:	51                   	push   ecx
  4dfbc4:	53                   	push   ebx
  4dfbc5:	56                   	push   esi
  4dfbc6:	8b f0                	mov    esi,eax
  4dfbc8:	57                   	push   edi
  4dfbc9:	8d 45 08             	lea    eax,[ebp+0x8]
  4dfbcc:	8d 5e 08             	lea    ebx,[esi+0x8]
  4dfbcf:	50                   	push   eax
  4dfbd0:	8d 45 fc             	lea    eax,[ebp-0x4]
  4dfbd3:	8b cb                	mov    ecx,ebx
  4dfbd5:	e8 26 f3 34 00       	call   0x82ef00
  4dfbda:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  4dfbdd:	3b 7e 0c             	cmp    edi,DWORD PTR [esi+0xc]
  4dfbe0:	74 41                	je     0x4dfc23
  4dfbe2:	33 f6                	xor    esi,esi
  4dfbe4:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4dfbea:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbec:	8b 42 1c             	mov    eax,DWORD PTR [edx+0x1c]
  4dfbef:	56                   	push   esi
  4dfbf0:	ff d0                	call   eax
  4dfbf2:	46                   	inc    esi
  4dfbf3:	83 fe 03             	cmp    esi,0x3
  4dfbf6:	7c ec                	jl     0x4dfbe4
  4dfbf8:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfbfb:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbfd:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4dfc00:	ff d0                	call   eax
  4dfc02:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfc05:	85 c9                	test   ecx,ecx
  4dfc07:	74 0f                	je     0x4dfc18
  4dfc09:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfc0b:	8b 02                	mov    eax,DWORD PTR [edx]
  4dfc0d:	6a 01                	push   0x1
  4dfc0f:	ff d0                	call   eax
  4dfc11:	c7 47 10 00 00 00 00 	mov    DWORD PTR [edi+0x10],0x0
  4dfc18:	57                   	push   edi
  4dfc19:	8d 4d 08             	lea    ecx,[ebp+0x8]
  4dfc1c:	51                   	push   ecx
  4dfc1d:	53                   	push   ebx
  4dfc1e:	e8 6d 6c 2d 00       	call   0x7b6890
  4dfc23:	5f                   	pop    edi
  4dfc24:	5e                   	pop    esi
  4dfc25:	5b                   	pop    ebx
  4dfc26:	8b e5                	mov    esp,ebp
  4dfc28:	5d                   	pop    ebp
  4dfc29:	c2                   	.byte 0xc2
```

### `007B6890..007B6B08` (raw `0x3B5C90..0x3B5F08`, stop排他)

```asm
7b6890:	55                   	push   ebp
  7b6891:	8b ec                	mov    ebp,esp
  7b6893:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  7b6896:	83 ec 08             	sub    esp,0x8
  7b6899:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  7b689d:	74 0a                	je     0x7b68a9
  7b689f:	68 28 d2 be 00       	push   0xbed228
  7b68a4:	e8 d4 72 0c 00       	call   0x87db7d
  7b68a9:	53                   	push   ebx
  7b68aa:	56                   	push   esi
  7b68ab:	8b d8                	mov    ebx,eax
  7b68ad:	57                   	push   edi
  7b68ae:	8d 45 10             	lea    eax,[ebp+0x10]
  7b68b1:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  7b68b4:	e8 e7 7d ce ff       	call   0x49e6a0
  7b68b9:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  7b68bb:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  7b68bf:	74 05                	je     0x7b68c6
  7b68c1:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  7b68c4:	eb 17                	jmp    0x7b68dd
  7b68c6:	8b 43 08             	mov    eax,DWORD PTR [ebx+0x8]
  7b68c9:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  7b68cd:	74 04                	je     0x7b68d3
  7b68cf:	8b f9                	mov    edi,ecx
  7b68d1:	eb 0a                	jmp    0x7b68dd
  7b68d3:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  7b68d6:	8b 78 08             	mov    edi,DWORD PTR [eax+0x8]
  7b68d9:	3b c3                	cmp    eax,ebx
  7b68db:	75 7c                	jne    0x7b6959
  7b68dd:	80 7f 15 00          	cmp    BYTE PTR [edi+0x15],0x0
  7b68e1:	8b 73 04             	mov    esi,DWORD PTR [ebx+0x4]
  7b68e4:	75 03                	jne    0x7b68e9
  7b68e6:	89 77 04             	mov    DWORD PTR [edi+0x4],esi
  7b68e9:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b68ec:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7b68ef:	39 58 04             	cmp    DWORD PTR [eax+0x4],ebx
  7b68f2:	75 05                	jne    0x7b68f9
  7b68f4:	89 78 04             	mov    DWORD PTR [eax+0x4],edi
  7b68f7:	eb 0b                	jmp    0x7b6904
  7b68f9:	39 1e                	cmp    DWORD PTR [esi],ebx
  7b68fb:	75 04                	jne    0x7b6901
  7b68fd:	89 3e                	mov    DWORD PTR [esi],edi
  7b68ff:	eb 03                	jmp    0x7b6904
  7b6901:	89 7e 08             	mov    DWORD PTR [esi+0x8],edi
  7b6904:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7b6907:	39 18                	cmp    DWORD PTR [eax],ebx
  7b6909:	75 24                	jne    0x7b692f
  7b690b:	80 7f 15 00          	cmp    BYTE PTR [edi+0x15],0x0
  7b690f:	74 04                	je     0x7b6915
  7b6911:	8b ce                	mov    ecx,esi
  7b6913:	eb 15                	jmp    0x7b692a
  7b6915:	8b 07                	mov    eax,DWORD PTR [edi]
  7b6917:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  7b691b:	8b cf                	mov    ecx,edi
  7b691d:	75 0b                	jne    0x7b692a
  7b691f:	90                   	nop
  7b6920:	8b c8                	mov    ecx,eax
  7b6922:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b6924:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  7b6928:	74 f6                	je     0x7b6920
  7b692a:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7b692d:	89 08                	mov    DWORD PTR [eax],ecx
  7b692f:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  7b6932:	89 4d f8             	mov    DWORD PTR [ebp-0x8],ecx
  7b6935:	39 59 08             	cmp    DWORD PTR [ecx+0x8],ebx
  7b6938:	75 7c                	jne    0x7b69b6
  7b693a:	80 7f 15 00          	cmp    BYTE PTR [edi+0x15],0x0
  7b693e:	74 07                	je     0x7b6947
  7b6940:	8b c6                	mov    eax,esi
  7b6942:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  7b6945:	eb 6f                	jmp    0x7b69b6
  7b6947:	8b c7                	mov    eax,edi
  7b6949:	e8 32 d2 06 00       	call   0x823b80
  7b694e:	8b 4d f8             	mov    ecx,DWORD PTR [ebp-0x8]
  7b6951:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b6954:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  7b6957:	eb 5d                	jmp    0x7b69b6
  7b6959:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  7b695c:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  7b695e:	89 08                	mov    DWORD PTR [eax],ecx
  7b6960:	3b 43 08             	cmp    eax,DWORD PTR [ebx+0x8]
  7b6963:	75 04                	jne    0x7b6969
  7b6965:	8b f0                	mov    esi,eax
  7b6967:	eb 1a                	jmp    0x7b6983
  7b6969:	80 7f 15 00          	cmp    BYTE PTR [edi+0x15],0x0
  7b696d:	8b 70 04             	mov    esi,DWORD PTR [eax+0x4]
  7b6970:	75 03                	jne    0x7b6975
  7b6972:	89 77 04             	mov    DWORD PTR [edi+0x4],esi
  7b6975:	89 3e                	mov    DWORD PTR [esi],edi
  7b6977:	8b 4b 08             	mov    ecx,DWORD PTR [ebx+0x8]
  7b697a:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  7b697d:	8b 53 08             	mov    edx,DWORD PTR [ebx+0x8]
  7b6980:	89 42 04             	mov    DWORD PTR [edx+0x4],eax
  7b6983:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  7b6986:	8b 49 04             	mov    ecx,DWORD PTR [ecx+0x4]
  7b6989:	39 59 04             	cmp    DWORD PTR [ecx+0x4],ebx
  7b698c:	75 05                	jne    0x7b6993
  7b698e:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  7b6991:	eb 0e                	jmp    0x7b69a1
  7b6993:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  7b6996:	39 19                	cmp    DWORD PTR [ecx],ebx
  7b6998:	75 04                	jne    0x7b699e
  7b699a:	89 01                	mov    DWORD PTR [ecx],eax
  7b699c:	eb 03                	jmp    0x7b69a1
  7b699e:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  7b69a1:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  7b69a4:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  7b69a7:	8a 53 14             	mov    dl,BYTE PTR [ebx+0x14]
  7b69aa:	8a 48 14             	mov    cl,BYTE PTR [eax+0x14]
  7b69ad:	88 50 14             	mov    BYTE PTR [eax+0x14],dl
  7b69b0:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b69b3:	88 4b 14             	mov    BYTE PTR [ebx+0x14],cl
  7b69b6:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  7b69b9:	b3 01                	mov    bl,0x1
  7b69bb:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b69be:	0f 85 ff 00 00 00    	jne    0x7b6ac3
  7b69c4:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  7b69c7:	3b 79 04             	cmp    edi,DWORD PTR [ecx+0x4]
  7b69ca:	0f 84 f0 00 00 00    	je     0x7b6ac0
  7b69d0:	38 5f 14             	cmp    BYTE PTR [edi+0x14],bl
  7b69d3:	0f 85 e7 00 00 00    	jne    0x7b6ac0
  7b69d9:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7b69db:	3b f9                	cmp    edi,ecx
  7b69dd:	75 69                	jne    0x7b6a48
  7b69df:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7b69e2:	80 79 14 00          	cmp    BYTE PTR [ecx+0x14],0x0
  7b69e6:	75 15                	jne    0x7b69fd
  7b69e8:	88 59 14             	mov    BYTE PTR [ecx+0x14],bl
  7b69eb:	52                   	push   edx
  7b69ec:	8b ce                	mov    ecx,esi
  7b69ee:	c6 46 14 00          	mov    BYTE PTR [esi+0x14],0x0
  7b69f2:	e8 69 d5 fa ff       	call   0x763f60
  7b69f7:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7b69fa:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b69fd:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  7b6a01:	75 78                	jne    0x7b6a7b
  7b6a03:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b6a05:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a08:	75 08                	jne    0x7b6a12
  7b6a0a:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6a0d:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a10:	74 65                	je     0x7b6a77
  7b6a12:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6a15:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a18:	75 15                	jne    0x7b6a2f
  7b6a1a:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b6a1c:	88 58 14             	mov    BYTE PTR [eax+0x14],bl
  7b6a1f:	52                   	push   edx
  7b6a20:	c6 41 14 00          	mov    BYTE PTR [ecx+0x14],0x0
  7b6a24:	e8 47 7c c8 ff       	call   0x43e670
  7b6a29:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  7b6a2c:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b6a2f:	8a 46 14             	mov    al,BYTE PTR [esi+0x14]
  7b6a32:	88 41 14             	mov    BYTE PTR [ecx+0x14],al
  7b6a35:	88 5e 14             	mov    BYTE PTR [esi+0x14],bl
  7b6a38:	8b 49 08             	mov    ecx,DWORD PTR [ecx+0x8]
  7b6a3b:	88 59 14             	mov    BYTE PTR [ecx+0x14],bl
  7b6a3e:	52                   	push   edx
  7b6a3f:	8b ce                	mov    ecx,esi
  7b6a41:	e8 1a d5 fa ff       	call   0x763f60
  7b6a46:	eb 78                	jmp    0x7b6ac0
  7b6a48:	80 79 14 00          	cmp    BYTE PTR [ecx+0x14],0x0
  7b6a4c:	75 14                	jne    0x7b6a62
  7b6a4e:	88 59 14             	mov    BYTE PTR [ecx+0x14],bl
  7b6a51:	52                   	push   edx
  7b6a52:	8b ce                	mov    ecx,esi
  7b6a54:	c6 46 14 00          	mov    BYTE PTR [esi+0x14],0x0
  7b6a58:	e8 13 7c c8 ff       	call   0x43e670
  7b6a5d:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7b6a5f:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b6a62:	80 79 15 00          	cmp    BYTE PTR [ecx+0x15],0x0
  7b6a66:	75 13                	jne    0x7b6a7b
  7b6a68:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6a6b:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a6e:	75 1e                	jne    0x7b6a8e
  7b6a70:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b6a72:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a75:	75 17                	jne    0x7b6a8e
  7b6a77:	c6 41 14 00          	mov    BYTE PTR [ecx+0x14],0x0
  7b6a7b:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  7b6a7e:	8b fe                	mov    edi,esi
  7b6a80:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  7b6a83:	3b 79 04             	cmp    edi,DWORD PTR [ecx+0x4]
  7b6a86:	0f 85 44 ff ff ff    	jne    0x7b69d0
  7b6a8c:	eb 32                	jmp    0x7b6ac0
  7b6a8e:	8b 01                	mov    eax,DWORD PTR [ecx]
  7b6a90:	38 58 14             	cmp    BYTE PTR [eax+0x14],bl
  7b6a93:	75 15                	jne    0x7b6aaa
  7b6a95:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6a98:	88 58 14             	mov    BYTE PTR [eax+0x14],bl
  7b6a9b:	52                   	push   edx
  7b6a9c:	c6 41 14 00          	mov    BYTE PTR [ecx+0x14],0x0
  7b6aa0:	e8 bb d4 fa ff       	call   0x763f60
  7b6aa5:	8b 0e                	mov    ecx,DWORD PTR [esi]
  7b6aa7:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  7b6aaa:	8a 46 14             	mov    al,BYTE PTR [esi+0x14]
  7b6aad:	88 41 14             	mov    BYTE PTR [ecx+0x14],al
  7b6ab0:	88 5e 14             	mov    BYTE PTR [esi+0x14],bl
  7b6ab3:	8b 09                	mov    ecx,DWORD PTR [ecx]
  7b6ab5:	88 59 14             	mov    BYTE PTR [ecx+0x14],bl
  7b6ab8:	52                   	push   edx
  7b6ab9:	8b ce                	mov    ecx,esi
  7b6abb:	e8 b0 7b c8 ff       	call   0x43e670
  7b6ac0:	88 5f 14             	mov    BYTE PTR [edi+0x14],bl
  7b6ac3:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  7b6ac6:	52                   	push   edx
  7b6ac7:	e8 40 a7 0d 00       	call   0x89120c
  7b6acc:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  7b6acf:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  7b6ad2:	83 c4 04             	add    esp,0x4
  7b6ad5:	5f                   	pop    edi
  7b6ad6:	5e                   	pop    esi
  7b6ad7:	5b                   	pop    ebx
  7b6ad8:	85 c0                	test   eax,eax
  7b6ada:	74 04                	je     0x7b6ae0
  7b6adc:	48                   	dec    eax
  7b6add:	89 41 08             	mov    DWORD PTR [ecx+0x8],eax
  7b6ae0:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  7b6ae3:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  7b6ae6:	89 08                	mov    DWORD PTR [eax],ecx
  7b6ae8:	8b e5                	mov    esp,ebp
  7b6aea:	5d                   	pop    ebp
  7b6aeb:	c2 0c 00             	ret    0xc
  7b6aee:	cc                   	int3
  7b6aef:	cc                   	int3
  7b6af0:	55                   	push   ebp
  7b6af1:	8b ec                	mov    ebp,esp
  7b6af3:	6a ff                	push   0xffffffff
  7b6af5:	68 a8 19 91 00       	push   0x9119a8
  7b6afa:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  7b6b00:	50                   	push   eax
  7b6b01:	83 ec 10             	sub    esp,0x10
  7b6b04:	56                   	push   esi
  7b6b05:	a1                   	.byte 0xa1
  7b6b06:	20 1f                	and    BYTE PTR [edi],bl
```

### `004B294A..004B29A0` (raw `0xB1D4A..0xB1DA0`, stop排他)

```asm
4b294a:	f9                   	stc
  4b294b:	3d 00 83 c4 04       	cmp    eax,0x4c48300
  4b2950:	c7 44 24 40 ff ff ff 	mov    DWORD PTR [esp+0x40],0xffffffff
  4b2957:	ff 
  4b2958:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  4b295c:	0f b7 02             	movzx  eax,WORD PTR [edx]
  4b295f:	8d 4c 24 1c          	lea    ecx,[esp+0x1c]
  4b2963:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  4b2967:	51                   	push   ecx
  4b2968:	8d 44 24 24          	lea    eax,[esp+0x24]
  4b296c:	b9 38 b1 fa 00       	mov    ecx,0xfab138
  4b2971:	e8 8a c5 37 00       	call   0x82ef00
  4b2976:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4b297a:	3b 05 3c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab13c
  4b2980:	74 07                	je     0x4b2989
  4b2982:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  4b2985:	85 f6                	test   esi,esi
  4b2987:	75 12                	jne    0x4b299b
  4b2989:	68 e0 6c c0 00       	push   0xc06ce0
  4b298e:	e8 cd b1 23 00       	call   0x6edb60
  4b2993:	83 c4 04             	add    esp,0x4
  4b2996:	e9 2c 01 00 00       	jmp    0x4b2ac7
  4b299b:	0f b7 46 04          	movzx  eax,WORD PTR [esi+0x4]
  4b299f:	3a                   	.byte 0x3a
```

### `007B8680..007B86F7` (raw `0x3B7A80..0x3B7AF7`, stop排他)

```asm
7b8680:	55                   	push   ebp
  7b8681:	8b ec                	mov    ebp,esp
  7b8683:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  7b8686:	53                   	push   ebx
  7b8687:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  7b868a:	57                   	push   edi
  7b868b:	8b 7e 20             	mov    edi,DWORD PTR [esi+0x20]
  7b868e:	83 c0 08             	add    eax,0x8
  7b8691:	e8 4a 9f d9 ff       	call   0x5525e0
  7b8696:	23 c7                	and    eax,edi
  7b8698:	39 46 24             	cmp    DWORD PTR [esi+0x24],eax
  7b869b:	77 09                	ja     0x7b86a6
  7b869d:	d1 ef                	shr    edi,1
  7b869f:	83 c9 ff             	or     ecx,0xffffffff
  7b86a2:	2b cf                	sub    ecx,edi
  7b86a4:	03 c1                	add    eax,ecx
  7b86a6:	8b 56 10             	mov    edx,DWORD PTR [esi+0x10]
  7b86a9:	8d 0c c2             	lea    ecx,[edx+eax*8]
  7b86ac:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  7b86af:	39 51 04             	cmp    DWORD PTR [ecx+0x4],edx
  7b86b2:	75 1d                	jne    0x7b86d1
  7b86b4:	39 11                	cmp    DWORD PTR [ecx],edx
  7b86b6:	75 11                	jne    0x7b86c9
  7b86b8:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  7b86bb:	89 11                	mov    DWORD PTR [ecx],edx
  7b86bd:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  7b86c0:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  7b86c3:	89 54 c1 04          	mov    DWORD PTR [ecx+eax*8+0x4],edx
  7b86c7:	eb 10                	jmp    0x7b86d9
  7b86c9:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7b86cc:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  7b86cf:	eb 08                	jmp    0x7b86d9
  7b86d1:	39 11                	cmp    DWORD PTR [ecx],edx
  7b86d3:	75 07                	jne    0x7b86dc
  7b86d5:	8b 12                	mov    edx,DWORD PTR [edx]
  7b86d7:	89 11                	mov    DWORD PTR [ecx],edx
  7b86d9:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  7b86dc:	52                   	push   edx
  7b86dd:	53                   	push   ebx
  7b86de:	8d 7e 04             	lea    edi,[esi+0x4]
  7b86e1:	e8 3a 14 f6 ff       	call   0x719b20
  7b86e6:	5f                   	pop    edi
  7b86e7:	8b c3                	mov    eax,ebx
  7b86e9:	5b                   	pop    ebx
  7b86ea:	5d                   	pop    ebp
  7b86eb:	c2 08 00             	ret    0x8
  7b86ee:	cc                   	int3
  7b86ef:	cc                   	int3
  7b86f0:	55                   	push   ebp
  7b86f1:	8b ec                	mov    ebp,esp
  7b86f3:	83 ec 10             	sub    esp,0x10
  7b86f6:	53                   	push   ebx
```

### `007F6FBA..007F7034` (raw `0x3F63BA..0x3F6434`, stop排他)

```asm
7f6fba:	e8 c1 11 fc ff       	call   0x7b8180
  7f6fbf:	6a 30                	push   0x30
  7f6fc1:	8b f8                	mov    edi,eax
  7f6fc3:	e8 a0 a2 09 00       	call   0x891268
  7f6fc8:	8b f0                	mov    esi,eax
  7f6fca:	83 c4 04             	add    esp,0x4
  7f6fcd:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  7f6fd0:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  7f6fd7:	85 f6                	test   esi,esi
  7f6fd9:	74 46                	je     0x7f7021
  7f6fdb:	57                   	push   edi
  7f6fdc:	e8 cf 5f fe ff       	call   0x7dcfb0
  7f6fe1:	d9 ee                	fldz
  7f6fe3:	c7 46 04 00 00 00 00 	mov    DWORD PTR [esi+0x4],0x0
  7f6fea:	c7 06 cc 11 c5 00    	mov    DWORD PTR [esi],0xc511cc
  7f6ff0:	d9 56 08             	fst    DWORD PTR [esi+0x8]
  7f6ff3:	d9 56 0c             	fst    DWORD PTR [esi+0xc]
  7f6ff6:	d9 56 10             	fst    DWORD PTR [esi+0x10]
  7f6ff9:	d9 56 14             	fst    DWORD PTR [esi+0x14]
  7f6ffc:	d9 56 18             	fst    DWORD PTR [esi+0x18]
  7f6fff:	d9 56 1c             	fst    DWORD PTR [esi+0x1c]
  7f7002:	d9 56 20             	fst    DWORD PTR [esi+0x20]
  7f7005:	d9 56 24             	fst    DWORD PTR [esi+0x24]
  7f7008:	d9 5e 28             	fstp   DWORD PTR [esi+0x28]
  7f700b:	89 46 2c             	mov    DWORD PTR [esi+0x2c],eax
  7f700e:	8b c6                	mov    eax,esi
  7f7010:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7f7013:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7f701a:	59                   	pop    ecx
  7f701b:	5f                   	pop    edi
  7f701c:	5e                   	pop    esi
  7f701d:	8b e5                	mov    esp,ebp
  7f701f:	5d                   	pop    ebp
  7f7020:	c3                   	ret
  7f7021:	33 c0                	xor    eax,eax
  7f7023:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7f7026:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7f702d:	59                   	pop    ecx
  7f702e:	5f                   	pop    edi
  7f702f:	5e                   	pop    esi
  7f7030:	8b e5                	mov    esp,ebp
  7f7032:	5d                   	pop    ebp
  7f7033:	c3                   	ret
```

## 仍需T01審核的狀態與責任邊界

- 來源修正完整文件可交T01查核；**不能由來源 Task 自行宣告 FULL-PASS**。
- 201及202局部新增證據優先補正實際指令與有界含義；其他版本及舊映射全部持續掛起。
- Client待逆向：其他使用同一legacy VA的完整主張及可能alias writer；Server待開發：官方關卡/生成/死亡規則不在這些指令中；跨功能待整合：T02 framing、T07/T14 stage；待遊玩驗證：沒有執行原Client。
