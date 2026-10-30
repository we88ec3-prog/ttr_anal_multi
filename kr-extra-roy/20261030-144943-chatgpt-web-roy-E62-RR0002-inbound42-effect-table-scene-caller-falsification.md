# E62 — RR-0002：對 S2C 0x42 的實際容器副作用與 scene 上游作進一步反證

> 這是 E61 原稿的追加、非替代。**RR-0002 尚未完成**：雖然 Client 對 S2C 0x42/0x43 的處理可深入定位，仍不能建立 C2S 0x42 選角要求與實際 S2C 批准／拒絕／世界轉場之間的正向因果。完整原稿持續保存在 `extra/roy1`；正式共享 RR 台帳只應標 `IN_PROGRESS`，不能基於完成報告就轉 `SUBMITTED`。研究者僅用唯讀 `Tartaros.bin`，未啟動遊戲。

## 來源

- 原件 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，PE `.text` VA `0x401000`、raw `0x400`，source byte slice 用 GNU objdump 對應 VMA；不是高階反編譯的推斷。
- E61：`kr-extra-roy/20261030-144616-chatgpt-web-roy-E61-RR0002-selection-C2S-roster-S2C-candidate-negative-join.md`，獨立證 C2S `42 00 XX YY`、三個 UI sender、roster command2 與 scene callback table。
- T02 E60、T03-3、T04 roster 既有有界原稿可供 cross-task 引用；不得在此自行升級 FULL-PASS。

## 新的逐節 native 結果

### S2C 0x0042 不是空 handler，也不是已證選角批准

`0x4B2190` 從 `payload+2` 讀**signed 16-bit** 值進 ESI，設定 EDI=`0xFAB2A0`，於 `0x4B2206` CALL `0x500110`。`0x500110` 從 `edi+0x5ED0` 起搜尋**最多20筆 WORD**（`0x14`），若找到相同值立即返回，若沒有則尋找空 WORD 並寫入，若表滿則返回。這是有上界的集合／識別碼表插入，不是已證選角批准旗標；對負值的 ESI 比對並無一般業務合法性檢查。

若傳入該 handler 的 `[ebp+0xC]` 長度 `>4`，在 `0x4B221C` 讀 payload+5 的 byte 進跳表（規整為 byte-1，允許索引0..10）。跳表按資料類型把 cursor 加 `9/10/11/13/15` 等可變距離；遇 `byte [esi]==9` 就回到 loop。其它值會先檢查本地 `0xFAB22C` 的一次性初始化並從 `0xFAB134` 取容器，經 `0x53D840` 更新。

`0x53D840` 在 `0x53D84B..53D865` 使用 `0x18` = 24-byte stride 的記錄陣列，按 `WORD[src+4]` 搜尋既有記錄；未找到時動態增列。正常分支 `0x53D8B6` 把 caller 提供的 index/種類等寫進 24-byte record；`0x53D8E9..53D904` 依 `src[0]`、`src[1]` 使用跳表決定不同欄位拼裝。本地來源 byte 被分類成不同記錄更新方式。**沒有一條當下直接可見的 branch 以選角 index 或 mode 判定角色已進入世界，也沒有直接呼叫進入場景的 `0x565720`。** 不能把這個負向結果誇張成對所有可能間接 callback 的否定。

### S2C 0x0043 作用不同

`0x4B1A90` `push 6 → 0x40F060 → 0x4DFD40`；`0x4DFD40` 遍歷物件容器，依 `record+4` 的低 byte 與傳入的種類比對。在符合狀態、可用指標後，會經虛擬方法及 tree erase 解除／清理該物件。這不直接寫入 C2S 0x42 的 selected index，也不直接啟動 tutorial；**0x43 與 0x42 字面相鄰只是數值事實，不是 request→reply 或成功回覆的證據。**

### 場景函式上游進一步閉合：0x47D530

`0x47B5C0` 的已找到 direct E8 caller 為 `0x47D5B7`（本輪原始 bytes 再核對）。其 enclosing function `0x47D530` 先把 `[source+0x248]` 寫到 `[target+0x120]`，把 `[source+0x24C]` 寫到 `[target+0x11C]`；接著從 `[target+0x120]` 取值，CALL `0x47E890`，將返回值作為 `0x47B5C0` 的 stack arg，而 ECX 為 source。於 `0x47B5C0` 可進 `0x565720` 的路徑，使用的是 `source+0x248`、`arg` 的**雙鍵**，不等於 `0x42` 的 4-byte C2S payload 中 `XX/YY`，亦不等於已確立的 Server 選角回覆。

`.text` 的直接 E8 候選掃描進一步找到 `0x47D530` 的 caller `0x47D9DA`；該指令附近對已持有的 `ECX/EDX` object 與 stack param 做傳遞，並不能未經 object provenance 就貼上「網路接收 handler」。因此 scene caller **已有比 E61 更精確的上游 object flow**，但 `+0x248` 的來源 writer、訊息類別、場景 identity 仍是 RR-0008/T05 必要缺口。

## 可以直接交付 S00／不允許寫入 Server MUST 的界線

| 有界內容 | 靜態信心 | 不能得出的結論 |
|---|---|---|
| S2C 42 使用 payload+2 signed WORD 與 20-slot set | native bytes 已核 | 不等於選角批准，不能以此製作成功回覆 |
| S2C 42 有條件更新 24-byte record | native bytes 已核 | 未證等於角色世界初始資料或場景切線 |
| S2C 43 使用 type6 cleanup 入口 | native bytes 已核 | 不等於 C2S42 的回覆 |
| source+248 到 scene double-key loader | native bytes 已核 | 尚未證回覆 writer／首進教學 key |
| 角色 C2S `42 00 XX YY` | E61 原生已核 | XX 的原版角色身份語意、Server 會怎樣答仍未知 |

## 待續追：有證據的阻斷點而非抽象「缺 runtime」

1. `0x47D530` 的 caller `0x47D9DA`，確定 object source（包括 ctor/vtable、`source+248` 正向寫入、target+120 alias）。目前只確定資料搬移，尚無訊息→object 寫入鏈。
2. `0x4B2190 → 0x500110` 的 20-word 表和 `0x53D840` 的 24-byte 資料在其它 Client 狀態/UI 的 consumer；如果無法連到角色選角結果，可正式排除這組 S2C handler 作為 reply。
3. 不只追 0x42/43；要由「角色選擇完成／進世界」的狀態寫入處反向跨越第一層／第二層 handler 表，找出 native S2C opcode 與事件。整個主程式非常大、間接 vtable 高，先前舊資料也未提供正向指向；不能以虛構 callback 代替。
4. 有合法授權及原始 KR Client 互動時，擷取所選 role 及 key0/1/2 接收的 frame marker+payload word、UI前後狀態，才可能驗證真實 request-reply order；執行結果不能由修改 Server 的 synthetic fixture冒充。

**形式上 E61+E62 是完整可保留的分析原稿，但 RR 研究終點仍未達成。** 對 `RR-0002` 的 `selection request+responses and scene transition` 不得自行宣稱達標。T01/S00 應取得本稿作為索證，後續繼續追 exact message/state writer。

### A.1 `0x500110` 20-word bounded set

```asm
  500110:	33 c0                	xor    eax,eax
  500112:	8d 8f d0 5e 00 00    	lea    ecx,[edi+0x5ed0]
  500118:	53                   	push   ebx
  500119:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  500120:	0f b7 19             	movzx  ebx,WORD PTR [ecx]
  500123:	3b de                	cmp    ebx,esi
  500125:	74 2a                	je     0x500151
  500127:	40                   	inc    eax
  500128:	83 c1 02             	add    ecx,0x2
  50012b:	83 f8 14             	cmp    eax,0x14
  50012e:	7c f0                	jl     0x500120
  500130:	33 c0                	xor    eax,eax
  500132:	8d 8f d0 5e 00 00    	lea    ecx,[edi+0x5ed0]
  500138:	66 83 39 00          	cmp    WORD PTR [ecx],0x0
  50013c:	74 0b                	je     0x500149
  50013e:	40                   	inc    eax
  50013f:	83 c1 02             	add    ecx,0x2
  500142:	83 f8 14             	cmp    eax,0x14
  500145:	7c f1                	jl     0x500138
  500147:	5b                   	pop    ebx
  500148:	c3                   	ret
  500149:	66 89 b4 47 d0 5e 00 	mov    WORD PTR [edi+eax*2+0x5ed0],si
  500150:	00 
  500151:	5b                   	pop    ebx
  500152:	c3                   	ret
```

### A.2 `0x53D840` record-24 logic/variable subtypes

```asm
  53d840:	55                   	push   ebp
  53d841:	8b ec                	mov    ebp,esp
  53d843:	83 ec 18             	sub    esp,0x18
  53d846:	53                   	push   ebx
  53d847:	57                   	push   edi
  53d848:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53d84b:	8b 4f 14             	mov    ecx,DWORD PTR [edi+0x14]
  53d84e:	2b 4f 10             	sub    ecx,DWORD PTR [edi+0x10]
  53d851:	83 c7 10             	add    edi,0x10
  53d854:	b8 ab aa aa 2a       	mov    eax,0x2aaaaaab
  53d859:	f7 e9                	imul   ecx
  53d85b:	c1 fa 02             	sar    edx,0x2
  53d85e:	8b c2                	mov    eax,edx
  53d860:	c1 e8 1f             	shr    eax,0x1f
  53d863:	03 c2                	add    eax,edx
  53d865:	b9 00 00 00 00       	mov    ecx,0x0
  53d86a:	74 28                	je     0x53d894
  53d86c:	8b 17                	mov    edx,DWORD PTR [edi]
  53d86e:	0f b7 5e 04          	movzx  ebx,WORD PTR [esi+0x4]
  53d872:	83 c2 02             	add    edx,0x2
  53d875:	66 39 1a             	cmp    WORD PTR [edx],bx
  53d878:	74 0c                	je     0x53d886
  53d87a:	41                   	inc    ecx
  53d87b:	83 c2 18             	add    edx,0x18
  53d87e:	3b c8                	cmp    ecx,eax
  53d880:	72 f3                	jb     0x53d875
  53d882:	33 c9                	xor    ecx,ecx
  53d884:	eb 0e                	jmp    0x53d894
  53d886:	8b 07                	mov    eax,DWORD PTR [edi]
  53d888:	8d 0c 49             	lea    ecx,[ecx+ecx*2]
  53d88b:	8d 04 c8             	lea    eax,[eax+ecx*8]
  53d88e:	33 c9                	xor    ecx,ecx
  53d890:	3b c1                	cmp    eax,ecx
  53d892:	75 22                	jne    0x53d8b6
  53d894:	33 d2                	xor    edx,edx
  53d896:	8d 45 e8             	lea    eax,[ebp-0x18]
  53d899:	89 55 e8             	mov    DWORD PTR [ebp-0x18],edx
  53d89c:	89 55 ec             	mov    DWORD PTR [ebp-0x14],edx
  53d89f:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  53d8a2:	89 4d f4             	mov    DWORD PTR [ebp-0xc],ecx
  53d8a5:	89 4d f8             	mov    DWORD PTR [ebp-0x8],ecx
  53d8a8:	e8 43 ac 0b 00       	call   0x5f84f0
  53d8ad:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  53d8b0:	8b 40 14             	mov    eax,DWORD PTR [eax+0x14]
  53d8b3:	83 e8 18             	sub    eax,0x18
  53d8b6:	66 8b 4d 0c          	mov    cx,WORD PTR [ebp+0xc]
  53d8ba:	66 89 48 14          	mov    WORD PTR [eax+0x14],cx
  53d8be:	0f b6 56 01          	movzx  edx,BYTE PTR [esi+0x1]
  53d8c2:	66 89 50 04          	mov    WORD PTR [eax+0x4],dx
  53d8c6:	0f b6 4e 02          	movzx  ecx,BYTE PTR [esi+0x2]
  53d8ca:	66 89 08             	mov    WORD PTR [eax],cx
  53d8cd:	0f b7 56 04          	movzx  edx,WORD PTR [esi+0x4]
  53d8d1:	66 89 50 02          	mov    WORD PTR [eax+0x2],dx
  53d8d5:	0f b6 4e 03          	movzx  ecx,BYTE PTR [esi+0x3]
  53d8d9:	88 48 0a             	mov    BYTE PTR [eax+0xa],cl
  53d8dc:	0f b6 56 06          	movzx  edx,BYTE PTR [esi+0x6]
  53d8e0:	89 50 10             	mov    DWORD PTR [eax+0x10],edx
  53d8e3:	0f b6 0e             	movzx  ecx,BYTE PTR [esi]
  53d8e6:	88 48 0b             	mov    BYTE PTR [eax+0xb],cl
  53d8e9:	80 3e 02             	cmp    BYTE PTR [esi],0x2
  53d8ec:	75 08                	jne    0x53d8f6
  53d8ee:	ba ff 00 00 00       	mov    edx,0xff
  53d8f3:	66 89 10             	mov    WORD PTR [eax],dx
  53d8f6:	0f b6 4e 01          	movzx  ecx,BYTE PTR [esi+0x1]
  53d8fa:	49                   	dec    ecx
  53d8fb:	83 f9 0a             	cmp    ecx,0xa
  53d8fe:	0f 87 3b 01 00 00    	ja     0x53da3f
  53d904:	ff 24 8d 48 da 53 00 	jmp    DWORD PTR [ecx*4+0x53da48]
  53d90b:	66 8b 4e 09          	mov    cx,WORD PTR [esi+0x9]
  53d90f:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53d913:	66 8b 56 07          	mov    dx,WORD PTR [esi+0x7]
  53d917:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53d91b:	0f b6 4e 0b          	movzx  ecx,BYTE PTR [esi+0xb]
  53d91f:	0f b7 56 0d          	movzx  edx,WORD PTR [esi+0xd]
  53d923:	49                   	dec    ecx
  53d924:	81 c9 00 01 00 00    	or     ecx,0x100
  53d92a:	c1 e1 10             	shl    ecx,0x10
  53d92d:	0b ca                	or     ecx,edx
  53d92f:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  53d932:	5f                   	pop    edi
  53d933:	5b                   	pop    ebx
  53d934:	8b e5                	mov    esp,ebp
  53d936:	5d                   	pop    ebp
  53d937:	c2 08 00             	ret    0x8
  53d93a:	66 8b 4e 09          	mov    cx,WORD PTR [esi+0x9]
  53d93e:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53d942:	66 8b 56 07          	mov    dx,WORD PTR [esi+0x7]
  53d946:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53d94a:	5f                   	pop    edi
  53d94b:	5b                   	pop    ebx
  53d94c:	8b e5                	mov    esp,ebp
  53d94e:	5d                   	pop    ebp
  53d94f:	c2 08 00             	ret    0x8
  53d952:	66 8b 4e 09          	mov    cx,WORD PTR [esi+0x9]
  53d956:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53d95a:	66 8b 56 07          	mov    dx,WORD PTR [esi+0x7]
  53d95e:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53d962:	0f b7 4e 0b          	movzx  ecx,WORD PTR [esi+0xb]
  53d966:	81 c9 00 00 00 03    	or     ecx,0x3000000
  53d96c:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  53d96f:	5f                   	pop    edi
  53d970:	5b                   	pop    ebx
  53d971:	8b e5                	mov    esp,ebp
  53d973:	5d                   	pop    ebp
  53d974:	c2 08 00             	ret    0x8
  53d977:	0f b6 56 06          	movzx  edx,BYTE PTR [esi+0x6]
  53d97b:	89 50 10             	mov    DWORD PTR [eax+0x10],edx
  53d97e:	0f b6 4e 08          	movzx  ecx,BYTE PTR [esi+0x8]
  53d982:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53d986:	0f b6 56 07          	movzx  edx,BYTE PTR [esi+0x7]
  53d98a:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53d98e:	0f b6 4e 09          	movzx  ecx,BYTE PTR [esi+0x9]
  53d992:	0f b7 56 0b          	movzx  edx,WORD PTR [esi+0xb]
  53d996:	49                   	dec    ecx
  53d997:	81 c9 00 04 00 00    	or     ecx,0x400
  53d99d:	c1 e1 10             	shl    ecx,0x10
  53d9a0:	0b ca                	or     ecx,edx
  53d9a2:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  53d9a5:	5f                   	pop    edi
  53d9a6:	5b                   	pop    ebx
  53d9a7:	8b e5                	mov    esp,ebp
  53d9a9:	5d                   	pop    ebp
  53d9aa:	c2 08 00             	ret    0x8
  53d9ad:	8b 4e 07             	mov    ecx,DWORD PTR [esi+0x7]
  53d9b0:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  53d9b3:	5f                   	pop    edi
  53d9b4:	5b                   	pop    ebx
  53d9b5:	8b e5                	mov    esp,ebp
  53d9b7:	5d                   	pop    ebp
  53d9b8:	c2 08 00             	ret    0x8
  53d9bb:	0f b6 56 08          	movzx  edx,BYTE PTR [esi+0x8]
  53d9bf:	66 89 50 06          	mov    WORD PTR [eax+0x6],dx
  53d9c3:	0f b6 4e 07          	movzx  ecx,BYTE PTR [esi+0x7]
  53d9c7:	66 89 48 08          	mov    WORD PTR [eax+0x8],cx
  53d9cb:	0f b6 56 09          	movzx  edx,BYTE PTR [esi+0x9]
  53d9cf:	0f b7 4e 0b          	movzx  ecx,WORD PTR [esi+0xb]
  53d9d3:	4a                   	dec    edx
  53d9d4:	81 ca 00 01 00 00    	or     edx,0x100
  53d9da:	c1 e2 10             	shl    edx,0x10
  53d9dd:	0b d1                	or     edx,ecx
  53d9df:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  53d9e2:	5f                   	pop    edi
  53d9e3:	5b                   	pop    ebx
  53d9e4:	8b e5                	mov    esp,ebp
  53d9e6:	5d                   	pop    ebp
  53d9e7:	c2 08 00             	ret    0x8
  53d9ea:	0f b6 56 08          	movzx  edx,BYTE PTR [esi+0x8]
  53d9ee:	66 89 50 06          	mov    WORD PTR [eax+0x6],dx
  53d9f2:	0f b6 4e 07          	movzx  ecx,BYTE PTR [esi+0x7]
  53d9f6:	66 89 48 08          	mov    WORD PTR [eax+0x8],cx
  53d9fa:	0f b6 56 09          	movzx  edx,BYTE PTR [esi+0x9]
  53d9fe:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  53da01:	5f                   	pop    edi
  53da02:	5b                   	pop    ebx
  53da03:	8b e5                	mov    esp,ebp
  53da05:	5d                   	pop    ebp
  53da06:	c2 08 00             	ret    0x8
  53da09:	0f b6 4e 08          	movzx  ecx,BYTE PTR [esi+0x8]
  53da0d:	66 89 48 06          	mov    WORD PTR [eax+0x6],cx
  53da11:	0f b6 56 07          	movzx  edx,BYTE PTR [esi+0x7]
  53da15:	66 89 50 08          	mov    WORD PTR [eax+0x8],dx
  53da19:	0f b6 4e 09          	movzx  ecx,BYTE PTR [esi+0x9]
  53da1d:	89 48 0c             	mov    DWORD PTR [eax+0xc],ecx
  53da20:	5f                   	pop    edi
  53da21:	5b                   	pop    ebx
  53da22:	8b e5                	mov    esp,ebp
  53da24:	5d                   	pop    ebp
  53da25:	c2 08 00             	ret    0x8
  53da28:	0f b6 56 0a          	movzx  edx,BYTE PTR [esi+0xa]
  53da2c:	66 89 50 06          	mov    WORD PTR [eax+0x6],dx
  53da30:	0f b6 4e 09          	movzx  ecx,BYTE PTR [esi+0x9]
  53da34:	66 89 48 08          	mov    WORD PTR [eax+0x8],cx
  53da38:	0f b7 56 07          	movzx  edx,WORD PTR [esi+0x7]
  53da3c:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  53da3f:	5f                   	pop    edi
```

### A.3 `0x47D530` scene source→dest alias then call 47B5C0

```asm
  47d530:	55                   	push   ebp
  47d531:	8b ec                	mov    ebp,esp
  47d533:	6a ff                	push   0xffffffff
  47d535:	68 7e 7e 94 00       	push   0x947e7e
  47d53a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47d540:	50                   	push   eax
  47d541:	56                   	push   esi
  47d542:	57                   	push   edi
  47d543:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47d548:	33 c5                	xor    eax,ebp
  47d54a:	50                   	push   eax
  47d54b:	8d 45 f4             	lea    eax,[ebp-0xc]
  47d54e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47d554:	8b f1                	mov    esi,ecx
  47d556:	8b fa                	mov    edi,edx
  47d558:	8b 86 48 02 00 00    	mov    eax,DWORD PTR [esi+0x248]
  47d55e:	89 87 20 01 00 00    	mov    DWORD PTR [edi+0x120],eax
  47d564:	8b 86 4c 02 00 00    	mov    eax,DWORD PTR [esi+0x24c]
  47d56a:	89 87 1c 01 00 00    	mov    DWORD PTR [edi+0x11c],eax
  47d570:	b8 01 00 00 00       	mov    eax,0x1
  47d575:	84 05 64 0f fc 00    	test   BYTE PTR ds:0xfc0f64,al
  47d57b:	75 26                	jne    0x47d5a3
  47d57d:	09 05 64 0f fc 00    	or     DWORD PTR ds:0xfc0f64,eax
  47d583:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47d58a:	e8 51 07 00 00       	call   0x47dce0
  47d58f:	68 f0 da bc 00       	push   0xbcdaf0
  47d594:	e8 81 4d 41 00       	call   0x89231a
  47d599:	83 c4 04             	add    esp,0x4
  47d59c:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47d5a3:	8b 87 20 01 00 00    	mov    eax,DWORD PTR [edi+0x120]
  47d5a9:	50                   	push   eax
  47d5aa:	68 68 0f fc 00       	push   0xfc0f68
  47d5af:	e8 dc 12 00 00       	call   0x47e890
  47d5b4:	50                   	push   eax
  47d5b5:	8b ce                	mov    ecx,esi
  47d5b7:	e8 04 e0 ff ff       	call   0x47b5c0
  47d5bc:	57                   	push   edi
  47d5bd:	e8 2e f8 ff ff       	call   0x47cdf0
  47d5c2:	8b 8f 00 01 00 00    	mov    ecx,DWORD PTR [edi+0x100]
  47d5c8:	8b 31                	mov    esi,DWORD PTR [ecx]
  47d5ca:	e8 41 00 00 00       	call   0x47d610
  47d5cf:	8b 8f 00 01 00 00    	mov    ecx,DWORD PTR [edi+0x100]
  47d5d5:	0f b6 d0             	movzx  edx,al
  47d5d8:	8b 86 90 00 00 00    	mov    eax,DWORD PTR [esi+0x90]
  47d5de:	52                   	push   edx
  47d5df:	ff d0                	call   eax
  47d5e1:	8b 8f 00 01 00 00    	mov    ecx,DWORD PTR [edi+0x100]
  47d5e7:	8b 11                	mov    edx,DWORD PTR [ecx]
  47d5e9:	8b 82 c8 00 00 00    	mov    eax,DWORD PTR [edx+0xc8]
  47d5ef:	ff d0                	call   eax
  47d5f1:	8b cf                	mov    ecx,edi
  47d5f3:	e8 b8 fa ff ff       	call   0x47d0b0
  47d5f8:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
```

### A.4 `0x47D9DA` static direct caller and return boundary

```asm
  47d9ce:	50                   	push   eax
  47d9cf:	e8 1c c1 0b 00       	call   0x539af0
  47d9d4:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  47d9d7:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  47d9da:	e8 51 fb ff ff       	call   0x47d530
  47d9df:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47d9e2:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47d9e9:	59                   	pop    ecx
  47d9ea:	5f                   	pop    edi
  47d9eb:	5e                   	pop    esi
  47d9ec:	5b                   	pop    ebx
  47d9ed:	8b e5                	mov    esp,ebp
  47d9ef:	5d                   	pop    ebp
  47d9f0:	c2 08 00             	ret    0x8
```

### A.5 `0x4B2190` S2C 0x42 call targets and length checks

```asm
  4b2190:	55                   	push   ebp
  4b2191:	8b ec                	mov    ebp,esp
  4b2193:	83 e4 f8             	and    esp,0xfffffff8
  4b2196:	6a ff                	push   0xffffffff
  4b2198:	68 5c 7c 94 00       	push   0x947c5c
  4b219d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b21a3:	50                   	push   eax
  4b21a4:	83 ec 18             	sub    esp,0x18
  4b21a7:	53                   	push   ebx
  4b21a8:	56                   	push   esi
  4b21a9:	57                   	push   edi
  4b21aa:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b21af:	33 c4                	xor    eax,esp
  4b21b1:	50                   	push   eax
  4b21b2:	8d 44 24 28          	lea    eax,[esp+0x28]
  4b21b6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b21bc:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  4b21c3:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4b21c6:	8d 46 04             	lea    eax,[esi+0x4]
  4b21c9:	bb 04 00 00 00       	mov    ebx,0x4
  4b21ce:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4b21d2:	75 29                	jne    0x4b21fd
  4b21d4:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  4b21db:	c7 44 24 30 00 00 00 	mov    DWORD PTR [esp+0x30],0x0
  4b21e2:	00 
  4b21e3:	e8 78 dc 04 00       	call   0x4ffe60
  4b21e8:	68 00 cf bc 00       	push   0xbccf00
  4b21ed:	e8 28 01 3e 00       	call   0x89231a
  4b21f2:	83 c4 04             	add    esp,0x4
  4b21f5:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b21fc:	ff 
  4b21fd:	0f bf 76 02          	movsx  esi,WORD PTR [esi+0x2]
  4b2201:	bf a0 b2 fa 00       	mov    edi,0xfab2a0
  4b2206:	e8 05 df 04 00       	call   0x500110
  4b220b:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  4b220e:	8b ff                	mov    edi,edi
  4b2210:	3b fb                	cmp    edi,ebx
  4b2212:	0f 86 ae 00 00 00    	jbe    0x4b22c6
  4b2218:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4b221c:	0f b6 48 01          	movzx  ecx,BYTE PTR [eax+0x1]
  4b2220:	8d 70 01             	lea    esi,[eax+0x1]
  4b2223:	49                   	dec    ecx
  4b2224:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4b2228:	83 f9 0a             	cmp    ecx,0xa
  4b222b:	0f 87 95 00 00 00    	ja     0x4b22c6
  4b2231:	ff 24 8d e0 22 4b 00 	jmp    DWORD PTR [ecx*4+0x4b22e0]
  4b2238:	83 c0 0f             	add    eax,0xf
  4b223b:	83 c3 0f             	add    ebx,0xf
  4b223e:	eb 1e                	jmp    0x4b225e
  4b2240:	83 c0 0d             	add    eax,0xd
  4b2243:	83 c3 0d             	add    ebx,0xd
  4b2246:	eb 16                	jmp    0x4b225e
  4b2248:	83 c0 0a             	add    eax,0xa
  4b224b:	83 c3 0a             	add    ebx,0xa
  4b224e:	eb 0e                	jmp    0x4b225e
  4b2250:	83 c0 09             	add    eax,0x9
  4b2253:	83 c3 09             	add    ebx,0x9
  4b2256:	eb 06                	jmp    0x4b225e
  4b2258:	83 c0 0b             	add    eax,0xb
  4b225b:	83 c3 0b             	add    ebx,0xb
  4b225e:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4b2262:	3b df                	cmp    ebx,edi
  4b2264:	76 0d                	jbe    0x4b2273
  4b2266:	68 bc 6c bf 00       	push   0xbf6cbc
  4b226b:	e8 f0 b8 23 00       	call   0x6edb60
  4b2270:	83 c4 04             	add    esp,0x4
  4b2273:	80 3e 09             	cmp    BYTE PTR [esi],0x9
  4b2276:	74 98                	je     0x4b2210
  4b2278:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4b227f:	75 29                	jne    0x4b22aa
  4b2281:	b8 01 00 00 00       	mov    eax,0x1
  4b2286:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  4b228c:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  4b2290:	e8 fb c9 02 00       	call   0x4dec90
  4b2295:	68 30 ce bc 00       	push   0xbcce30
  4b229a:	e8 7b 00 3e 00       	call   0x89231a
  4b229f:	83 c4 04             	add    esp,0x4
  4b22a2:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b22a9:	ff 
  4b22aa:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4b22ad:	0f bf 51 02          	movsx  edx,WORD PTR [ecx+0x2]
  4b22b1:	a1 34 b1 fa 00       	mov    eax,ds:0xfab134
  4b22b6:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  4b22ba:	52                   	push   edx
  4b22bb:	50                   	push   eax
  4b22bc:	e8 7f b5 08 00       	call   0x53d840
  4b22c1:	e9 4a ff ff ff       	jmp    0x4b2210
  4b22c6:	33 c0                	xor    eax,eax
  4b22c8:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  4b22cc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b22d3:	59                   	pop    ecx
  4b22d4:	5f                   	pop    edi
  4b22d5:	5e                   	pop    esi
  4b22d6:	5b                   	pop    ebx
  4b22d7:	8b e5                	mov    esp,ebp
  4b22d9:	5d                   	pop    ebp
  4b22da:	c2 0c 00             	ret    0xc
```

### A.6 `0x4B1A90` S2C 0x43 native entry

```asm
  4b1a90:	6a 06                	push   0x6
  4b1a92:	e8 c9 d5 f5 ff       	call   0x40f060
  4b1a97:	8b c8                	mov    ecx,eax
  4b1a99:	e8 a2 e2 02 00       	call   0x4dfd40
  4b1a9e:	33 c0                	xor    eax,eax
  4b1aa0:	c2 0c 00             	ret    0xc
  4b1aa3:	cc                   	int3
  4b1aa4:	cc                   	int3
  4b1aa5:	cc                   	int3
  4b1aa6:	cc                   	int3
  4b1aa7:	cc                   	int3
  4b1aa8:	cc                   	int3
  4b1aa9:	cc                   	int3
  4b1aaa:	cc                   	int3
  4b1aab:	cc                   	int3
  4b1aac:	cc                   	int3
  4b1aad:	cc                   	int3
  4b1aae:	cc                   	int3
  4b1aaf:	cc                   	int3
```

### A.7 `0x47B5C0` scene double-key conditional call

```asm
  47b5c0:	55                   	push   ebp
  47b5c1:	8b ec                	mov    ebp,esp
  47b5c3:	83 e4 f8             	and    esp,0xfffffff8
  47b5c6:	6a ff                	push   0xffffffff
  47b5c8:	68 7c 10 94 00       	push   0x94107c
  47b5cd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47b5d3:	50                   	push   eax
  47b5d4:	51                   	push   ecx
  47b5d5:	56                   	push   esi
  47b5d6:	57                   	push   edi
  47b5d7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47b5dc:	33 c4                	xor    eax,esp
  47b5de:	50                   	push   eax
  47b5df:	8d 44 24 10          	lea    eax,[esp+0x10]
  47b5e3:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47b5e9:	8b f9                	mov    edi,ecx
  47b5eb:	81 bf 48 02 00 00 61 	cmp    DWORD PTR [edi+0x248],0xea61
  47b5f2:	ea 00 00 
  47b5f5:	75 11                	jne    0x47b608
  47b5f7:	80 bf 6c 02 00 00 00 	cmp    BYTE PTR [edi+0x26c],0x0
  47b5fe:	75 4f                	jne    0x47b64f
  47b600:	57                   	push   edi
  47b601:	e8 4a 02 00 00       	call   0x47b850
  47b606:	eb 47                	jmp    0x47b64f
  47b608:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  47b60f:	75 29                	jne    0x47b63a
  47b611:	83 0d b8 73 fb 00 01 	or     DWORD PTR ds:0xfb73b8,0x1
  47b618:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  47b61f:	00 
  47b620:	e8 4b 4b 0e 00       	call   0x560170
  47b625:	68 10 d1 bc 00       	push   0xbcd110
  47b62a:	e8 eb 6c 41 00       	call   0x89231a
  47b62f:	83 c4 04             	add    esp,0x4
  47b632:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  47b639:	ff 
  47b63a:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47b63d:	8b 8f 48 02 00 00    	mov    ecx,DWORD PTR [edi+0x248]
  47b643:	50                   	push   eax
  47b644:	51                   	push   ecx
  47b645:	be c0 73 fb 00       	mov    esi,0xfb73c0
  47b64a:	e8 d1 a0 0e 00       	call   0x565720
  47b64f:	f6 05 64 0f fc 00 01 	test   BYTE PTR ds:0xfc0f64,0x1
  47b656:	75 29                	jne    0x47b681
  47b658:	b8 01 00 00 00       	mov    eax,0x1
  47b65d:	09 05 64 0f fc 00    	or     DWORD PTR ds:0xfc0f64,eax
  47b663:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  47b667:	e8 74 26 00 00       	call   0x47dce0
  47b66c:	68 f0 da bc 00       	push   0xbcdaf0
  47b671:	e8 a4 6c 41 00       	call   0x89231a
  47b676:	83 c4 04             	add    esp,0x4
  47b679:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  47b680:	ff 
  47b681:	8b 97 4c 02 00 00    	mov    edx,DWORD PTR [edi+0x24c]
  47b687:	8b 8f 48 02 00 00    	mov    ecx,DWORD PTR [edi+0x248]
  47b68d:	52                   	push   edx
  47b68e:	bf 68 0f fc 00       	mov    edi,0xfc0f68
  47b693:	e8 b8 30 00 00       	call   0x47e750
  47b698:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47b69c:	64 89 0d 00    	mov    DWORD PTR fs:0x0,ecx
```

### A.8 `0x4DFD40` type6 object erase downstream

```asm
  4dfd40:	55                   	push   ebp
  4dfd41:	8b ec                	mov    ebp,esp
  4dfd43:	83 e4 f8             	and    esp,0xfffffff8
  4dfd46:	83 ec 18             	sub    esp,0x18
  4dfd49:	8b 41 0c             	mov    eax,DWORD PTR [ecx+0xc]
  4dfd4c:	83 c1 08             	add    ecx,0x8
  4dfd4f:	56                   	push   esi
  4dfd50:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfd52:	57                   	push   edi
  4dfd53:	89 4c 24 08          	mov    DWORD PTR [esp+0x8],ecx
  4dfd57:	3b f0                	cmp    esi,eax
  4dfd59:	0f 84 23 01 00 00    	je     0x4dfe82
  4dfd5f:	f3 0f 10 05 c0 56 c4 	movss  xmm0,DWORD PTR ds:0xc456c0
  4dfd66:	00 
  4dfd67:	eb 07                	jmp    0x4dfd70
  4dfd69:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  4dfd70:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  4dfd73:	0f b6 50 04          	movzx  edx,BYTE PTR [eax+0x4]
  4dfd77:	66 3b 55 08          	cmp    dx,WORD PTR [ebp+0x8]
  4dfd7b:	0f 85 b8 00 00 00    	jne    0x4dfe39
  4dfd81:	8b f8                	mov    edi,eax
  4dfd83:	85 ff                	test   edi,edi
  4dfd85:	74 72                	je     0x4dfdf9
  4dfd87:	0f b7 47 04          	movzx  eax,WORD PTR [edi+0x4]
  4dfd8b:	3c 01                	cmp    al,0x1
  4dfd8d:	74 0c                	je     0x4dfd9b
  4dfd8f:	3c 06                	cmp    al,0x6
  4dfd91:	74 08                	je     0x4dfd9b
  4dfd93:	84 c0                	test   al,al
  4dfd95:	74 04                	je     0x4dfd9b
  4dfd97:	3c 07                	cmp    al,0x7
  4dfd99:	75 5e                	jne    0x4dfdf9
  4dfd9b:	8b 87 5c 01 00 00    	mov    eax,DWORD PTR [edi+0x15c]
  4dfda1:	f3 0f 11 44 24 10    	movss  DWORD PTR [esp+0x10],xmm0
  4dfda7:	f3 0f 11 44 24 14    	movss  DWORD PTR [esp+0x14],xmm0
  4dfdad:	f3 0f 11 44 24 18    	movss  DWORD PTR [esp+0x18],xmm0
  4dfdb3:	f3 0f 11 44 24 1c    	movss  DWORD PTR [esp+0x1c],xmm0
  4dfdb9:	85 c0                	test   eax,eax
  4dfdbb:	74 3c                	je     0x4dfdf9
  4dfdbd:	83 bf 70 03 00 00 00 	cmp    DWORD PTR [edi+0x370],0x0
  4dfdc4:	74 33                	je     0x4dfdf9
  4dfdc6:	6a 00                	push   0x0
  4dfdc8:	50                   	push   eax
  4dfdc9:	e8 f2 7e 2c 00       	call   0x7a7cc0
  4dfdce:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  4dfdd2:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  4dfdd6:	83 ec 10             	sub    esp,0x10
  4dfdd9:	8b c4                	mov    eax,esp
  4dfddb:	89 08                	mov    DWORD PTR [eax],ecx
  4dfddd:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  4dfde1:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  4dfde4:	8b 54 24 2c          	mov    edx,DWORD PTR [esp+0x2c]
  4dfde8:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  4dfdeb:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  4dfdee:	8b 87 5c 01 00 00    	mov    eax,DWORD PTR [edi+0x15c]
  4dfdf4:	e8 f7 7d 2c 00       	call   0x7a7bf0
  4dfdf9:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfdfc:	8b 01                	mov    eax,DWORD PTR [ecx]
  4dfdfe:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4dfe01:	ff d2                	call   edx
  4dfe03:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfe06:	85 c9                	test   ecx,ecx
  4dfe08:	74 0f                	je     0x4dfe19
  4dfe0a:	8b 01                	mov    eax,DWORD PTR [ecx]
  4dfe0c:	8b 10                	mov    edx,DWORD PTR [eax]
  4dfe0e:	6a 01                	push   0x1
  4dfe10:	ff d2                	call   edx
  4dfe12:	c7 46 10 00 00 00 00 	mov    DWORD PTR [esi+0x10],0x0
  4dfe19:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  4dfe1d:	56                   	push   esi
  4dfe1e:	8d 44 24 10          	lea    eax,[esp+0x10]
  4dfe22:	50                   	push   eax
  4dfe23:	51                   	push   ecx
  4dfe24:	e8 67 6a 2d 00       	call   0x7b6890
  4dfe29:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfe2b:	f3 0f 10 05 c0 56 c4 	movss  xmm0,DWORD PTR ds:0xc456c0
  4dfe32:	00 
  4dfe33:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  4dfe37:	eb 40                	jmp    0x4dfe79
  4dfe39:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  4dfe3d:	75 3a                	jne    0x4dfe79
  4dfe3f:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  4dfe42:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe46:	75 16                	jne    0x4dfe5e
  4dfe48:	8b f0                	mov    esi,eax
  4dfe4a:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfe4c:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe50:	75 27                	jne    0x4dfe79
  4dfe52:	8b f0                	mov    esi,eax
  4dfe54:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfe56:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe5a:	74 f6                	je     0x4dfe52
  4dfe5c:	eb 1b                	jmp    0x4dfe79
  4dfe5e:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4dfe61:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe65:	75 10                	jne    0x4dfe77
  4dfe67:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  4dfe6a:	75 0b                	jne    0x4dfe77
  4dfe6c:	8b f0                	mov    esi,eax
  4dfe6e:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4dfe71:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe75:	74 f0                	je     0x4dfe67
  4dfe77:	8b f0                	mov    esi,eax
  4dfe79:	3b 71 04             	cmp    esi,DWORD PTR [ecx+0x4]
  4dfe7c:	0f 85 ee fe ff ff    	jne    0x4dfd70
  4dfe82:	5f                   	pop    edi
  4dfe83:	5e                   	pop    esi
  4dfe84:	8b e5                	mov    esp,ebp
  4dfe86:	5d                   	pop    ebp
  4dfe87:	c2 04 00             	ret    0x4
```

