# T08-136 — B queue consumer 結尾重置、可觀測性與全域22桶關係界限

## 第一手來源
- 原始證據：`Tartaros.bin`，12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪直接以原始檔計算）。
- 反組譯：使用 GNU `objdump -D -b binary -m i386 -M intel --adjust-vma=0x401000`，對當前 BIN 全檔建立線性反組譯索引；重要 VA 再以功能邊界與既有 T08-131/132 筆記核對。線性反組譯可能包含資料誤判，不等同控制流程圖。
- 研究屬**靜態分析**；未執行客戶端、未設記憶體斷點。
- 分析區分「已確認的本段指令」、「合理推測」、「未證實的全域別名身分」。

## consumer 的上游與 top-N 路徑
已確認 `0x007BB640` 至少有兩個 `E8 rel32` 直接呼叫：`0x0079A394`（22桶 dispatcher 前階段）和 `0x007BAC79`（另一局部 stage 執行 A-array 與群組物件派送後）。函式使用 `ESI+B4/B8` 求陣列元素數，取 `ESI+C4` 上限，對整個陣列呼叫 `0x007BB7B0`，其中 middle=`begin+4*min(cap,count)`；對前段 entry 依序執行 `vtable+4`。

```asm
  7bb664:	8b 86 b8 00 00 00    	mov    eax,DWORD PTR [esi+0xb8]
  7bb66a:	2b 86 b4 00 00 00    	sub    eax,DWORD PTR [esi+0xb4]
  7bb670:	8b 9e c4 00 00 00    	mov    ebx,DWORD PTR [esi+0xc4]
  7bb676:	c1 f8 02             	sar    eax,0x2
  7bb679:	3b d8                	cmp    ebx,eax
  7bb67b:	76 02                	jbe    0x7bb67f
  7bb67d:	8b d8                	mov    ebx,eax
  7bb67f:	f6 05 e8 79 fb 00 01 	test   BYTE PTR ds:0xfb79e8,0x1
  7bb670:	8b 9e c4 00 00 00    	mov    ebx,DWORD PTR [esi+0xc4]
  7bb676:	c1 f8 02             	sar    eax,0x2
  7bb679:	3b d8                	cmp    ebx,eax
  7bb67b:	76 02                	jbe    0x7bb67f
  7bb67d:	8b d8                	mov    ebx,eax
  7bb67f:	f6 05 e8 79 fb 00 01 	test   BYTE PTR ds:0xfb79e8,0x1
  7bb686:	75 27                	jne    0x7bb6af
  7bb688:	83 0d e8 79 fb 00 01 	or     DWORD PTR ds:0xfb79e8,0x1
  7bb679:	3b d8                	cmp    ebx,eax
  7bb67b:	76 02                	jbe    0x7bb67f
  7bb67d:	8b d8                	mov    ebx,eax
  7bb67f:	f6 05 e8 79 fb 00 01 	test   BYTE PTR ds:0xfb79e8,0x1
  7bb686:	75 27                	jne    0x7bb6af
  7bb688:	83 0d e8 79 fb 00 01 	or     DWORD PTR ds:0xfb79e8,0x1
  7bb68f:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  7bb696:	e8 45 db fd ff       	call   0x7991e0
  7bb6af:	a1 e8 76 fb 00       	mov    eax,ds:0xfb76e8
  7bb6b4:	8b 78 0c             	mov    edi,DWORD PTR [eax+0xc]
  7bb6b7:	8b 96 b4 00 00 00    	mov    edx,DWORD PTR [esi+0xb4]
  7bb6bd:	83 ec 0c             	sub    esp,0xc
  7bb6c0:	8b cc                	mov    ecx,esp
  7bb6c2:	89 39                	mov    DWORD PTR [ecx],edi
  7bb6c4:	8b 78 10             	mov    edi,DWORD PTR [eax+0x10]
  7bb6c7:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  7bb6d0:	8b 86 b8 00 00 00    	mov    eax,DWORD PTR [esi+0xb8]
  7bb6d6:	50                   	push   eax
  7bb6d7:	8d 04 9a             	lea    eax,[edx+ebx*4]
  7bb6da:	50                   	push   eax
  7bb6db:	52                   	push   edx
  7bb6dc:	e8 cf 00 00 00       	call   0x7bb7b0
  7bb6e1:	83 c4 18             	add    esp,0x18
  7bb6e4:	33 ff                	xor    edi,edi
  7bb6d7:	8d 04 9a             	lea    eax,[edx+ebx*4]
  7bb6da:	50                   	push   eax
  7bb6db:	52                   	push   edx
  7bb6dc:	e8 cf 00 00 00       	call   0x7bb7b0
  7bb6e1:	83 c4 18             	add    esp,0x18
  7bb6e4:	33 ff                	xor    edi,edi
  7bb6e6:	85 db                	test   ebx,ebx
  7bb6e8:	74 1b                	je     0x7bb705
  7bb6dc:	e8 cf 00 00 00       	call   0x7bb7b0
  7bb6e1:	83 c4 18             	add    esp,0x18
  7bb6e4:	33 ff                	xor    edi,edi
  7bb6e6:	85 db                	test   ebx,ebx
  7bb6e8:	74 1b                	je     0x7bb705
  7bb6ea:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  7bb6f0:	8b 8e b4 00 00 00    	mov    ecx,DWORD PTR [esi+0xb4]
  7bb6f6:	8b 0c b9             	mov    ecx,DWORD PTR [ecx+edi*4]
  7bb6f0:	8b 8e b4 00 00 00    	mov    ecx,DWORD PTR [esi+0xb4]
  7bb6f6:	8b 0c b9             	mov    ecx,DWORD PTR [ecx+edi*4]
  7bb6f9:	8b 11                	mov    edx,DWORD PTR [ecx]
  7bb6fb:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7bb6fe:	ff d0                	call   eax
  7bb700:	47                   	inc    edi
  7bb701:	3b fb                	cmp    edi,ebx
  7bb703:	72 eb                	jb     0x7bb6f0
  7bb6f9:	8b 11                	mov    edx,DWORD PTR [ecx]
  7bb6fb:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  7bb6fe:	ff d0                	call   eax
  7bb700:	47                   	inc    edi
  7bb701:	3b fb                	cmp    edi,ebx
  7bb703:	72 eb                	jb     0x7bb6f0
  7bb705:	8b 8e b8 00 00 00    	mov    ecx,DWORD PTR [esi+0xb8]
  7bb70b:	8b be b4 00 00 00    	mov    edi,DWORD PTR [esi+0xb4]
  7bac79:	e8 c2 09 00 00       	call   0x7bb640
  7bac7e:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  7bac81:	8b 08                	mov    ecx,DWORD PTR [eax]
  7bac83:	8b 51 08             	mov    edx,DWORD PTR [ecx+0x8]
  7bac86:	50                   	push   eax
  7bac87:	ff d2                	call   edx
  7bac89:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7bac8c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
```

## 新增核實：清除範圍的機器碼細節
`0x007BB705` 取 end，`0x007BB70B` 取 begin，兩者不相等才呼叫 `0x008916F0`；其原始序列在 `0x007BB715` **先 `mov eax, ecx`，再 `sub eax, ecx`，因此就此路徑而言 EAX=0，接續計出的 EBX=0**。呼叫參數依序為 begin、end、0，最後 `end = begin+0`。這不同於聲稱每個元素被 destructor 釋放；看到的只是一個長度0的 move/copy 類 helper 呼叫與邏輯清空。

```asm
  7bb705:	8b 8e b8 00 00 00    	mov    ecx,DWORD PTR [esi+0xb8]
  7bb70b:	8b be b4 00 00 00    	mov    edi,DWORD PTR [esi+0xb4]
  7bb711:	3b f9                	cmp    edi,ecx
  7bb713:	74 21                	je     0x7bb736
  7bb715:	8b c1                	mov    eax,ecx
  7bb717:	2b c1                	sub    eax,ecx
  7bb719:	c1 f8 02             	sar    eax,0x2
  7bb71c:	8d 1c 85 00 00 00 00 	lea    ebx,[eax*4+0x0]
  7bb70b:	8b be b4 00 00 00    	mov    edi,DWORD PTR [esi+0xb4]
  7bb711:	3b f9                	cmp    edi,ecx
  7bb713:	74 21                	je     0x7bb736
  7bb715:	8b c1                	mov    eax,ecx
  7bb717:	2b c1                	sub    eax,ecx
  7bb719:	c1 f8 02             	sar    eax,0x2
  7bb71c:	8d 1c 85 00 00 00 00 	lea    ebx,[eax*4+0x0]
  7bb723:	53                   	push   ebx
  7bb711:	3b f9                	cmp    edi,ecx
  7bb713:	74 21                	je     0x7bb736
  7bb715:	8b c1                	mov    eax,ecx
  7bb717:	2b c1                	sub    eax,ecx
  7bb719:	c1 f8 02             	sar    eax,0x2
  7bb71c:	8d 1c 85 00 00 00 00 	lea    ebx,[eax*4+0x0]
  7bb723:	53                   	push   ebx
  7bb724:	51                   	push   ecx
  7bb715:	8b c1                	mov    eax,ecx
  7bb717:	2b c1                	sub    eax,ecx
  7bb719:	c1 f8 02             	sar    eax,0x2
  7bb71c:	8d 1c 85 00 00 00 00 	lea    ebx,[eax*4+0x0]
  7bb723:	53                   	push   ebx
  7bb724:	51                   	push   ecx
  7bb725:	57                   	push   edi
  7bb726:	e8 c5 5f 0d 00       	call   0x8916f0
  7bb717:	2b c1                	sub    eax,ecx
  7bb719:	c1 f8 02             	sar    eax,0x2
  7bb71c:	8d 1c 85 00 00 00 00 	lea    ebx,[eax*4+0x0]
  7bb723:	53                   	push   ebx
  7bb724:	51                   	push   ecx
  7bb725:	57                   	push   edi
  7bb726:	e8 c5 5f 0d 00       	call   0x8916f0
  7bb72b:	83 c4 0c             	add    esp,0xc
  7bb719:	c1 f8 02             	sar    eax,0x2
  7bb71c:	8d 1c 85 00 00 00 00 	lea    ebx,[eax*4+0x0]
  7bb723:	53                   	push   ebx
  7bb724:	51                   	push   ecx
  7bb725:	57                   	push   edi
  7bb726:	e8 c5 5f 0d 00       	call   0x8916f0
  7bb72b:	83 c4 0c             	add    esp,0xc
  7bb72e:	03 df                	add    ebx,edi
  7bb71c:	8d 1c 85 00 00 00 00 	lea    ebx,[eax*4+0x0]
  7bb723:	53                   	push   ebx
  7bb724:	51                   	push   ecx
  7bb725:	57                   	push   edi
  7bb726:	e8 c5 5f 0d 00       	call   0x8916f0
  7bb72b:	83 c4 0c             	add    esp,0xc
  7bb72e:	03 df                	add    ebx,edi
  7bb730:	89 9e b8 00 00 00    	mov    DWORD PTR [esi+0xb8],ebx
  7bb723:	53                   	push   ebx
  7bb724:	51                   	push   ecx
  7bb725:	57                   	push   edi
  7bb726:	e8 c5 5f 0d 00       	call   0x8916f0
  7bb72b:	83 c4 0c             	add    esp,0xc
  7bb72e:	03 df                	add    ebx,edi
  7bb730:	89 9e b8 00 00 00    	mov    DWORD PTR [esi+0xb8],ebx
  7bb736:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7bb726:	e8 c5 5f 0d 00       	call   0x8916f0
  7bb72b:	83 c4 0c             	add    esp,0xc
  7bb72e:	03 df                	add    ebx,edi
  7bb730:	89 9e b8 00 00 00    	mov    DWORD PTR [esi+0xb8],ebx
  7bb736:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7bb739:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7bb740:	59                   	pop    ecx
  7bb741:	5f                   	pop    edi
  7bb72e:	03 df                	add    ebx,edi
  7bb730:	89 9e b8 00 00 00    	mov    DWORD PTR [esi+0xb8],ebx
  7bb736:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7bb739:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7bb740:	59                   	pop    ecx
  7bb741:	5f                   	pop    edi
  7bb742:	5b                   	pop    ebx
  7bb743:	8b e5                	mov    esp,ebp
  7bb730:	89 9e b8 00 00 00    	mov    DWORD PTR [esi+0xb8],ebx
  7bb736:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  7bb739:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  7bb740:	59                   	pop    ecx
  7bb741:	5f                   	pop    edi
  7bb742:	5b                   	pop    ebx
  7bb743:	8b e5                	mov    esp,ebp
  7bb745:	5d                   	pop    ebp
```

**重要限制**：這段可據實確認傳給 `0x008916F0` 的第三參數（由 EBX push）為0；是否有副作用及是否觸發異常需分析被呼叫函式，不能僅據名稱推斷安全性。

## 與全域22桶 consumer 的對照
`0x0079A394 -> 0x007BB640` 在 `0x0079A3AB` 的全域22桶 callback 呼叫之前，能確立排序佇列消費**先於**當次分桶派送；但尚未發現 B entry 的 `vtable+4` 直接落入 `[0x00FB7740]` producer 的機器碼鏈。相同先後次序**不代表**同一容器、亦不代表資料由前段流入後段。

## 待進行的動態／靜態驗證方案（未執行）
1. 監視同一個 owner 物件的 `[owner+0xB4]` 與 `[owner+0xB8]`，找出首次由相等變不等的 EIP；同時記錄 `ESI`、`EDI`、`EAX`、實際容器指標。
2. 在 `0x007BB6F9` 記錄 `ECX` entry vptr，解析 `+4/+8` 的函式與其實際控制流。
3. 在 `0x0079A394`、`0x0079A3AB` 記錄 `[0x00FB7740]` 的 count 快照，以確定前後是否有直接增加。
4. 若無可執行環境，從反編譯/追蹤 owner 構造、間接 push、callback dispatch 的 caller 帶入別名，不能用全程式 offset `+0xB4` 搜尋結果冒充同一 owner 的寫入證據。

## 段落判定
**T08-133～136 本輪完成的是四個可獨立交付的靜態主題段落，而非整個 B producer 命題已解決。** 目前最重要的未解仍是 B 的真實 writer、entry vtable、以及是否直接引發全域22桶 producer。下一段 T08-137 從實際 `owner+B8` 增長點與 entry concrete vptr 著手。
