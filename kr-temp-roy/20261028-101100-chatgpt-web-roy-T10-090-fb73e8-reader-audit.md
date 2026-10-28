# T10-090 — FB73E8 全部直接引用與初始化／getter 區分

## 原始來源／驗證方式

- 對象：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本批於實際掛載檔重新計算且一致。
- `.text` 原生 VA `0x401000`、raw offset `0x400`，既有反組譯文字 `t10-full-disasm.txt` 由 KR BIN 的 `objdump` 產生；本段抽查來源指令，並以 VA 保存可重做的窗口。
- 靜態唯讀，不啟動／附加／修改客戶端；先前 T10-081～088 作查詢線索，不把先前推測升格為本段原生結論。
- 證據分級：**已確認**＝以下實際 x86 指令與控制流；**部分確認**＝受限路徑或候選物件；**尚待驗證**＝class／語義／間接 producer、callback、motion 行為。

## 主題：0xFB73E8 跨系統讀者／唯一可直接證實的初始化 writer

### 全 .text 絕對位址參照（採文字反組譯掃描）

```asm
4a97fe:	a1 e8 73 fb 00       	mov    eax,ds:0xfb73e8
4b25ce:	83 3d e8 73 fb 00 00 	cmp    DWORD PTR ds:0xfb73e8,0x0
4c8611:	83 3d e8 73 fb 00 00 	cmp    DWORD PTR ds:0xfb73e8,0x0
4e00f8:	83 3d e8 73 fb 00 00 	cmp    DWORD PTR ds:0xfb73e8,0x0
4e8c40:	83 3d e8 73 fb 00 00 	cmp    DWORD PTR ds:0xfb73e8,0x0
4f1e17:	83 3d e8 73 fb 00 00 	cmp    DWORD PTR ds:0xfb73e8,0x0
4fe21d:	83 3d e8 73 fb 00 00 	cmp    DWORD PTR ds:0xfb73e8,0x0
4fe4c3:	39 3d e8 73 fb 00    	cmp    DWORD PTR ds:0xfb73e8,edi
53a32a:	83 3d e8 73 fb 00 00 	cmp    DWORD PTR ds:0xfb73e8,0x0
53ed19:	83 3d e8 73 fb 00 00 	cmp    DWORD PTR ds:0xfb73e8,0x0
53ffad:	83 3d e8 73 fb 00 00 	cmp    DWORD PTR ds:0xfb73e8,0x0
5548c5:	83 3d e8 73 fb 00 00 	cmp    DWORD PTR ds:0xfb73e8,0x0
560239:	89 1d e8 73 fb 00    	mov    DWORD PTR ds:0xfb73e8,ebx
59623b:	39 3d e8 73 fb 00    	cmp    DWORD PTR ds:0xfb73e8,edi
5973ee:	83 3d e8 73 fb 00 00 	cmp    DWORD PTR ds:0xfb73e8,0x0
597465:	83 3d e8 73 fb 00 00 	cmp    DWORD PTR ds:0xfb73e8,0x0
59a286:	83 3d e8 73 fb 00 00 	cmp    DWORD PTR ds:0xfb73e8,0x0
5a4614:	39 1d e8 73 fb 00    	cmp    DWORD PTR ds:0xfb73e8,ebx
```

這是反組譯行中**直接包含** `fb73e8` 的參照，既不包含通過 pointer alias 的寫入，也不保證所有 data producer 都是同一 `.text` 區段。不能將搜尋負面結果敘述成「此狀態永遠為零」。

### 初始化 writer 復查

```asm
  560197:	33 db                	xor    ebx,ebx
  560199:	6a 34                	push   0x34
  56019b:	c7 45 e4 c0 73 fb 00 	mov    DWORD PTR [ebp-0x1c],0xfb73c0
  5601a2:	89 1d c0 73 fb 00    	mov    DWORD PTR ds:0xfb73c0,ebx
  5601a8:	89 1d c4 73 fb 00    	mov    DWORD PTR ds:0xfb73c4,ebx
  5601ae:	89 1d d0 73 fb 00    	mov    DWORD PTR ds:0xfb73d0,ebx
  5601b4:	e8 af 10 33 00       	call   0x891268
  5601b9:	83 c4 04             	add    esp,0x4
  5601bc:	3b c3                	cmp    eax,ebx
  5601be:	0f 84 32 02 00 00    	je     0x5603f6
  5601c4:	a3 cc 73 fb 00       	mov    ds:0xfb73cc,eax
  5601c9:	89 00                	mov    DWORD PTR [eax],eax
  5601cb:	a1 cc 73 fb 00       	mov    eax,ds:0xfb73cc
  5601d0:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  5601d3:	a1 cc 73 fb 00       	mov    eax,ds:0xfb73cc
  5601d8:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  5601db:	a1 cc 73 fb 00       	mov    eax,ds:0xfb73cc
  5601e0:	c6 40 30 01          	mov    BYTE PTR [eax+0x30],0x1
  5601e4:	8b 0d cc 73 fb 00    	mov    ecx,DWORD PTR ds:0xfb73cc
  5601ea:	c6 41 31 01          	mov    BYTE PTR [ecx+0x31],0x1
  5601ee:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  5601f1:	6a 18                	push   0x18
  5601f3:	89 1d e0 73 fb 00    	mov    DWORD PTR ds:0xfb73e0,ebx
  5601f9:	e8 6a 10 33 00       	call   0x891268
  5601fe:	83 c4 04             	add    esp,0x4
  560201:	3b c3                	cmp    eax,ebx
  560203:	0f 84 c9 01 00 00    	je     0x5603d2
  560209:	a3 dc 73 fb 00       	mov    ds:0xfb73dc,eax
  56020e:	89 00                	mov    DWORD PTR [eax],eax
  560210:	a1 dc 73 fb 00       	mov    eax,ds:0xfb73dc
  560215:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  560218:	a1 dc 73 fb 00       	mov    eax,ds:0xfb73dc
  56021d:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  560220:	8b 15 dc 73 fb 00    	mov    edx,DWORD PTR ds:0xfb73dc
  560226:	c6 42 14 01          	mov    BYTE PTR [edx+0x14],0x1
  56022a:	a1 dc 73 fb 00       	mov    eax,ds:0xfb73dc
  56022f:	c6 40 15 01          	mov    BYTE PTR [eax+0x15],0x1
  560233:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  560237:	6a 48                	push   0x48
  560239:	89 1d e8 73 fb 00    	mov    DWORD PTR ds:0xfb73e8,ebx
  56023f:	89 1d ec 73 fb 00    	mov    DWORD PTR ds:0xfb73ec,ebx
  560245:	e8 1e 10 33 00       	call   0x891268
```

`0x560197 xor ebx,ebx` 隨後的 `mov [0xFB73E8],ebx`，從來源可證明寫 0；沒有在此窗口寫 1 的原生指令。

### Getter 反例：0x4A97FE

```asm
  4a97ec:	e8 7f 69 0b 00       	call   0x560170
  4a97f1:	68 10 d1 bc 00       	push   0xbcd110
  4a97f6:	e8 1f 8b 3e 00       	call   0x89231a
  4a97fb:	83 c4 04             	add    esp,0x4
  4a97fe:	a1 e8 73 fb 00       	mov    eax,ds:0xfb73e8
  4a9803:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a9806:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a980d:	59                   	pop    ecx
  4a980e:	8b e5                	mov    esp,ebp
  4a9810:	5d                   	pop    ebp
  4a9811:	c3                   	ret
```

此函式先呼叫 `0x560170`，再從 `0xFB73E8` 取值為返回 `eax`；是**讀取與回傳**，非直接 flag producer。`0x560170` 的間接效果與各 caller 尚須另追，不能因 `call` 在 load 之前就宣稱它設置了 flag。

### 與控制流程的有界關聯

```asm
  5a4614:	39 1d e8 73 fb 00    	cmp    DWORD PTR ds:0xfb73e8,ebx
  5a461a:	8a 86 54 01 00 00    	mov    al,BYTE PTR [esi+0x154]
  5a4620:	0f 95 c3             	setne  bl
  5a4623:	84 c0                	test   al,al
  5a4625:	75 35                	jne    0x5a465c
  5a4627:	84 db                	test   bl,bl
  5a4629:	74 2d                	je     0x5a4658
  5a462b:	6a 02                	push   0x2
  5a462d:	32 c9                	xor    cl,cl
  5a462f:	8b d6                	mov    edx,esi
  5a4631:	e8 aa 0f 00 00       	call   0x5a55e0
  5a4636:	8b 56 10             	mov    edx,DWORD PTR [esi+0x10]
  5a4639:	81 ea 3b 01 00 00    	sub    edx,0x13b
  5a463f:	56                   	push   esi
  5a4640:	b8 05 00 00 00       	mov    eax,0x5
  5a4645:	e8 16 11 00 00       	call   0x5a5760
  5a464a:	ba 66 00 00 00       	mov    edx,0x66
  5a464f:	8b ce                	mov    ecx,esi
  5a4651:	e8 4a 11 00 00       	call   0x5a57a0
  5a4656:	eb 13                	jmp    0x5a466b
  5a4658:	84 c0                	test   al,al
  5a465a:	74 0f                	je     0x5a466b
  5a465c:	84 db                	test   bl,bl
  5a465e:	75 0b                	jne    0x5a466b
  5a4660:	6a 01                	push   0x1
  5a4662:	32 c9                	xor    cl,cl
  5a4664:	8b d6                	mov    edx,esi
  5a4666:	e8 75 0f 00 00       	call   0x5a55e0
  5a466b:	88 9e 54 01 00 00    	mov    BYTE PTR [esi+0x154],bl
```

當 `0xFB73E8` 非零，此控制流按 `[esi+0x154]` 舊狀態條件呼叫 `0x5A55E0` 的 mode=2，並伴隨 `0x5A5760`、`0x5A57A0`。非零變零時可呼叫 mode=1；它跟 `0x5961C0` 的 ID13/14 特例共用同一全域條件。**不可直接命名**其為戰鬥取消／蓄力狀態，也不可將物件 `+0x154` 等同全域地址。

## 證據分級與後續

- 已確認：列出的直接 xrefs、初始化 zero store、0x4A97FE getter、0x5A4614 條件消費者。
- 尚未確認：`0xFB73E8` 非零 writer（可能是 base-relative，間接 alias，其他模組）；`0x560170` 間接副作用；所有 reader 的業務分類。
- 推薦按 0xFB73C0 鄰近全域結構作 base pointer/alias 追溯；釐清 bitfield/整數型態後才命名業務語義。