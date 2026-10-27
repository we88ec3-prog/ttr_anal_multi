# T10-45 — 按鍵映射查詢展開、兩類鍵碼容器與後續事件轉換（BIN-first）

- 產出時間（Asia/Taipei）：2026-10-28T01:35:43.055855+08:00
- 一手來源：`Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE32 x86；唯讀靜態反組譯，沒有執行遊戲。
- 段號接續 T10-1～44；先前 `REBASE-01/02` 僅作審核附錄，**不是 T10-45/46**。
- GitHub：既有 T01-20261027-05 接受範圍僅部分確認。**本次未 Commit、Push、變更 owner、catalog 或其他任務資料。**
- 位址映射取本次 BIN PE header：`.text` RVA 0x1000、ImageBase 0x400000、raw pointer 0x400，故下列 `.text` VA 轉 raw = VA - `0x401000` + `0x400`；不應套用 flat raw 0。

## 本批核心判定

1. **`0x6D4DC0` 不是非零 phase writer**。從直接 x86 控制流看是以 `[ebp+8]` 鍵碼及 `[ebp+0xC]` 第二參數尋找映射集合，走兩類來源容器後逐項加入 ECX 指向的輸出 vector-like buffer（`[edi]` begin、`[edi+4]` end、`[edi+8]` capacity）。回傳 `ret`，不含把 `FB9004` phase 寫成非零的直接證據。
2. 特殊鍵碼範圍使用 `(unsigned)(key-0x2711) <= 0x270E`，每個第二參數以 `shl eax,4` 定位 `0xFDF3F4 + 16 * arg2` 的容器，透過 `0x6D43F0` 查鍵碼樹，取其 +0x10 動態 DWORD 指標集合，再逐筆追加。另一支以 `0xFB8834 + 16*(key + 40*arg2)` 指向 vector-like 集合。**這是映射結果集合，尚未證明 key 是 Virtual-Key、XML action row 或 combo command。**
3. `0x6D4DC0` 在本 BIN 找到 29 處直接 E8 call 相對指令編碼候選（僅位元組比對，不等於皆可達執行），集中 `0x594610` 周邊，另有多處。首批檢查確認 `0x594610` 給第二參數 2，先以 EDI 原值查詢，再在 `edi==0x18` 時查 `0x0D`、`0x0E`；`edi==0x19` 時查 `0x0E`、`0x0F`。返回的集合元素透過 `0x594A80` 或 `0x594570` 轉成後續輸入／顯示資料。**此為具體下游消費路徑，不是 Z/X/C/V 實體綁定已證。**
4. `0x594A80` 針對輸入 DWORD 取 bits 16..23 與 bits 0..7；前者非零時 `0x4026E0`，後者非零時 `0x4041F0`；如兩者全零則 `0x402160` 設定 fallback。目的指標使用 `(byte*7)*4 + 4` 偏移，說明至少有兩個子欄位格式，**尚不應將其中一個稱為按下／放開事件**。
5. `0x546263` 是 `0x546780` 的直接 caller，且先檢查 actor 來源及 `0x4C9ED0` gate，後續把 WORD 輸出與 `[ebx+2]` 比較、合併。因此 500ms 狀態機不是獨立運作，亦沒有充足證據把它定義為原版連段時間。

## 交叉參照（本 BIN 原始 E8 rel32 bytes 搜尋）

完整 `call 0x6D4DC0` 候選 VA：0x594672, 0x5946cb, 0x59471b, 0x5947fd, 0x59484d, 0x59492f, 0x59497f, 0x594cd4, 0x594dc4, 0x594eb4, 0x594fa4, 0x595094, 0x595184, 0x595274, 0x595364, 0x595454, 0x595544, 0x595634, 0x595724, 0x595814, 0x595901, 0x5959f4, 0x5cd68a, 0x5ce5ba, 0x62b5ba, 0x650e96, 0x650f48, 0x650ff6, 0x6510a4。

注意：此搜尋僅對 E8 + signed rel32 計算目標，未掃描 indirect call、tailjmp，也可能在資料或反組譯邊界中誤判；`0x594672` 等已用 objdump 交叉核對。

## 重要證據窗口：原始 PE 指令解碼


### 0x006D4DC0–0x006D4E5F（raw 0x2D41C0）

```asm
006d4dc0 <.text+0x2d3dc0>:
  6d4dc0:	55                   	push   ebp
  6d4dc1:	8b ec                	mov    ebp,esp
  6d4dc3:	6a ff                	push   0xffffffff
  6d4dc5:	68 18 68 92 00       	push   0x926818
  6d4dca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  6d4dd0:	50                   	push   eax
  6d4dd1:	83 ec 0c             	sub    esp,0xc
  6d4dd4:	53                   	push   ebx
  6d4dd5:	56                   	push   esi
  6d4dd6:	57                   	push   edi
  6d4dd7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6d4ddc:	33 c5                	xor    eax,ebp
  6d4dde:	50                   	push   eax
  6d4ddf:	8d 45 f4             	lea    eax,[ebp-0xc]
  6d4de2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  6d4de8:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  6d4deb:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  6d4dee:	8b f9                	mov    edi,ecx
  6d4df0:	8d 8b ef d8 ff ff    	lea    ecx,[ebx-0x2711]
  6d4df6:	81 f9 0e 27 00 00    	cmp    ecx,0x270e
  6d4dfc:	0f 87 e4 00 00 00    	ja     0x6d4ee6
  6d4e02:	c1 e0 04             	shl    eax,0x4
  6d4e05:	c7 45 08 00 00 00 00 	mov    DWORD PTR [ebp+0x8],0x0
  6d4e0c:	89 5d ec             	mov    DWORD PTR [ebp-0x14],ebx
  6d4e0f:	8d b0 f4 f3 fd 00    	lea    esi,[eax+0xfdf3f4]
  6d4e15:	f6 05 ec f3 fd 00 01 	test   BYTE PTR ds:0xfdf3ec,0x1
  6d4e1c:	75 27                	jne    0x6d4e45
  6d4e1e:	83 0d ec f3 fd 00 01 	or     DWORD PTR ds:0xfdf3ec,0x1
  6d4e25:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  6d4e2c:	e8 6f cf ff ff       	call   0x6d1da0
  6d4e31:	68 30 e3 bc 00       	push   0xbce330
  6d4e36:	e8 df d4 1b 00       	call   0x89231a
  6d4e3b:	83 c4 04             	add    esp,0x4
  6d4e3e:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  6d4e45:	56                   	push   esi
  6d4e46:	8d 4d ec             	lea    ecx,[ebp-0x14]
  6d4e49:	e8 a2 f5 ff ff       	call   0x6d43f0
  6d4e4e:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  6d4e51:	2b 10                	sub    edx,DWORD PTR [eax]
  6d4e53:	c1 fa 02             	sar    edx,0x2
  6d4e56:	39 55 08             	cmp    DWORD PTR [ebp+0x8],edx
  6d4e59:	0f 83 9b 01 00 00    	jae    0x6d4ffa
```


### 0x006D4E8F–0x006D4F00（raw 0x2D428F）

```asm
006d4e8f <.text+0x2d3e8f>:
  6d4e8f:	56                   	push   esi
  6d4e90:	8d 4d f0             	lea    ecx,[ebp-0x10]
  6d4e93:	89 5d f0             	mov    DWORD PTR [ebp-0x10],ebx
  6d4e96:	e8 55 f5 ff ff       	call   0x6d43f0
  6d4e9b:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  6d4e9e:	2b 08                	sub    ecx,DWORD PTR [eax]
  6d4ea0:	f7 c1 fc ff ff ff    	test   ecx,0xfffffffc
  6d4ea6:	75 17                	jne    0x6d4ebf
  6d4ea8:	8d 45 f0             	lea    eax,[ebp-0x10]
  6d4eab:	c7 45 f0 00 00 00 00 	mov    DWORD PTR [ebp-0x10],0x0
  6d4eb2:	e8 c9 37 dd ff       	call   0x4a8680
  6d4eb7:	ff 45 08             	inc    DWORD PTR [ebp+0x8]
  6d4eba:	e9 56 ff ff ff       	jmp    0x6d4e15
  6d4ebf:	56                   	push   esi
  6d4ec0:	8d 4d f0             	lea    ecx,[ebp-0x10]
  6d4ec3:	89 5d f0             	mov    DWORD PTR [ebp-0x10],ebx
  6d4ec6:	e8 25 f5 ff ff       	call   0x6d43f0
  6d4ecb:	8b 10                	mov    edx,DWORD PTR [eax]
  6d4ecd:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6d4ed0:	8b 0c 82             	mov    ecx,DWORD PTR [edx+eax*4]
  6d4ed3:	8d 45 f0             	lea    eax,[ebp-0x10]
  6d4ed6:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  6d4ed9:	e8 a2 37 dd ff       	call   0x4a8680
  6d4ede:	ff 45 08             	inc    DWORD PTR [ebp+0x8]
  6d4ee1:	e9 2f ff ff ff       	jmp    0x6d4e15
  6d4ee6:	8d 14 80             	lea    edx,[eax+eax*4]
  6d4ee9:	8d 1c d3             	lea    ebx,[ebx+edx*8]
  6d4eec:	33 f6                	xor    esi,esi
  6d4eee:	c1 e3 04             	shl    ebx,0x4
  6d4ef1:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  6d4ef4:	8d 9b 34 88 fb 00    	lea    ebx,[ebx+0xfb8834]
  6d4efa:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
```


### 0x006D4F70–0x006D500C（raw 0x2D4370）

```asm
006d4f70 <.text+0x2d3f70>:
  6d4f70:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  6d4f73:	2b 0b                	sub    ecx,DWORD PTR [ebx]
  6d4f75:	f7 c1 fc ff ff ff    	test   ecx,0xfffffffc
  6d4f7b:	75 04                	jne    0x6d4f81
  6d4f7d:	33 f6                	xor    esi,esi
  6d4f7f:	eb 05                	jmp    0x6d4f86
  6d4f81:	8b 13                	mov    edx,DWORD PTR [ebx]
  6d4f83:	8b 34 b2             	mov    esi,DWORD PTR [edx+esi*4]
  6d4f86:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  6d4f89:	8d 4d 08             	lea    ecx,[ebp+0x8]
  6d4f8c:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  6d4f8f:	3b c8                	cmp    ecx,eax
  6d4f91:	73 3e                	jae    0x6d4fd1
  6d4f93:	8b 0f                	mov    ecx,DWORD PTR [edi]
  6d4f95:	8d 55 08             	lea    edx,[ebp+0x8]
  6d4f98:	3b ca                	cmp    ecx,edx
  6d4f9a:	77 35                	ja     0x6d4fd1
  6d4f9c:	8b f2                	mov    esi,edx
  6d4f9e:	2b f1                	sub    esi,ecx
  6d4fa0:	c1 fe 02             	sar    esi,0x2
  6d4fa3:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  6d4fa6:	75 0c                	jne    0x6d4fb4
  6d4fa8:	b9 01 00 00 00       	mov    ecx,0x1
  6d4fad:	8b c7                	mov    eax,edi
  6d4faf:	e8 8c 12 00 00       	call   0x6d6240
  6d4fb4:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  6d4fb7:	85 c0                	test   eax,eax
  6d4fb9:	74 30                	je     0x6d4feb
  6d4fbb:	8b 0f                	mov    ecx,DWORD PTR [edi]
  6d4fbd:	8b 14 b1             	mov    edx,DWORD PTR [ecx+esi*4]
  6d4fc0:	89 10                	mov    DWORD PTR [eax],edx
  6d4fc2:	83 47 04 04          	add    DWORD PTR [edi+0x4],0x4
  6d4fc6:	ff 45 f0             	inc    DWORD PTR [ebp-0x10]
  6d4fc9:	8b 75 f0             	mov    esi,DWORD PTR [ebp-0x10]
  6d4fcc:	e9 2f ff ff ff       	jmp    0x6d4f00
  6d4fd1:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  6d4fd4:	75 0c                	jne    0x6d4fe2
  6d4fd6:	b9 01 00 00 00       	mov    ecx,0x1
  6d4fdb:	8b c7                	mov    eax,edi
  6d4fdd:	e8 5e 12 00 00       	call   0x6d6240
  6d4fe2:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  6d4fe5:	85 c0                	test   eax,eax
  6d4fe7:	74 02                	je     0x6d4feb
  6d4fe9:	89 30                	mov    DWORD PTR [eax],esi
  6d4feb:	83 47 04 04          	add    DWORD PTR [edi+0x4],0x4
  6d4fef:	ff 45 f0             	inc    DWORD PTR [ebp-0x10]
  6d4ff2:	8b 75 f0             	mov    esi,DWORD PTR [ebp-0x10]
  6d4ff5:	e9 06 ff ff ff       	jmp    0x6d4f00
  6d4ffa:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d4ffd:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d5004:	59                   	pop    ecx
  6d5005:	5f                   	pop    edi
  6d5006:	5e                   	pop    esi
  6d5007:	5b                   	pop    ebx
  6d5008:	8b e5                	mov    esp,ebp
  6d500a:	5d                   	pop    ebp
  6d500b:	c3                   	ret
```


### 0x00594647–0x00594727（raw 0x193A47）

```asm
00594647 <.text+0x193647>:
  594647:	8b f9                	mov    edi,ecx
  594649:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  59464c:	33 db                	xor    ebx,ebx
  59464e:	8b f2                	mov    esi,edx
  594650:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  594654:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  594658:	89 5c 24 3c          	mov    DWORD PTR [esp+0x3c],ebx
  59465c:	89 5c 24 40          	mov    DWORD PTR [esp+0x40],ebx
  594660:	89 5c 24 44          	mov    DWORD PTR [esp+0x44],ebx
  594664:	6a 02                	push   0x2
  594666:	57                   	push   edi
  594667:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  59466b:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  594672:	e8 49 07 14 00       	call   0x6d4dc0
  594677:	83 c4 08             	add    esp,0x8
  59467a:	53                   	push   ebx
  59467b:	68 fc d1 be 00       	push   0xbed1fc
  594680:	8b ce                	mov    ecx,esi
  594682:	e8 d9 da e6 ff       	call   0x402160
  594687:	83 ff 18             	cmp    edi,0x18
  59468a:	0f 85 29 01 00 00    	jne    0x5947b9
  594690:	89 5c 24 2c          	mov    DWORD PTR [esp+0x2c],ebx
  594694:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  594698:	89 5c 24 34          	mov    DWORD PTR [esp+0x34],ebx
  59469c:	89 5c 24 1c          	mov    DWORD PTR [esp+0x1c],ebx
  5946a0:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  5946a4:	89 5c 24 24          	mov    DWORD PTR [esp+0x24],ebx
  5946a8:	33 c9                	xor    ecx,ecx
  5946aa:	c7 44 24 60 07 00 00 	mov    DWORD PTR [esp+0x60],0x7
  5946b1:	00 
  5946b2:	89 5c 24 5c          	mov    DWORD PTR [esp+0x5c],ebx
  5946b6:	66 89 4c 24 4c       	mov    WORD PTR [esp+0x4c],cx
  5946bb:	6a 02                	push   0x2
  5946bd:	6a 0d                	push   0xd
  5946bf:	8d 4c 24 34          	lea    ecx,[esp+0x34]
  5946c3:	c6 84 24 80 00 00 00 	mov    BYTE PTR [esp+0x80],0x3
  5946ca:	03 
  5946cb:	e8 f0 06 14 00       	call   0x6d4dc0
  5946d0:	8b 44 24 34          	mov    eax,DWORD PTR [esp+0x34]
  5946d4:	83 c4 08             	add    esp,0x8
  5946d7:	3b 44 24 30          	cmp    eax,DWORD PTR [esp+0x30]
  5946db:	74 27                	je     0x594704
  5946dd:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  5946e1:	38 5d 0c             	cmp    BYTE PTR [ebp+0xc],bl
  5946e4:	74 12                	je     0x5946f8
  5946e6:	8b 10                	mov    edx,DWORD PTR [eax]
  5946e8:	52                   	push   edx
  5946e9:	8d 74 24 50          	lea    esi,[esp+0x50]
  5946ed:	e8 8e 03 00 00       	call   0x594a80
  5946f2:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  5946f6:	eb 0c                	jmp    0x594704
  5946f8:	8b 00                	mov    eax,DWORD PTR [eax]
  5946fa:	50                   	push   eax
  5946fb:	8d 44 24 50          	lea    eax,[esp+0x50]
  5946ff:	e8 6c fe ff ff       	call   0x594570
  594704:	6a ff                	push   0xffffffff
  594706:	53                   	push   ebx
  594707:	8d 4c 24 54          	lea    ecx,[esp+0x54]
  59470b:	51                   	push   ecx
  59470c:	8b ce                	mov    ecx,esi
  59470e:	e8 dd fa e6 ff       	call   0x4041f0
  594713:	6a 02                	push   0x2
  594715:	6a 0e                	push   0xe
  594717:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  59471b:	e8 a0 06 14 00       	call   0x6d4dc0
  594720:	8b 7c 24 24          	mov    edi,DWORD PTR [esp+0x24]
  594724:	83 c4 08             	add    esp,0x8
```


### 0x00594A80–0x00594B09（raw 0x193E80）

```asm
00594a80 <.text+0x193a80>:
  594a80:	55                   	push   ebp
  594a81:	8b ec                	mov    ebp,esp
  594a83:	53                   	push   ebx
  594a84:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  594a87:	8b c3                	mov    eax,ebx
  594a89:	c1 e8 10             	shr    eax,0x10
  594a8c:	84 c0                	test   al,al
  594a8e:	74 41                	je     0x594ad1
  594a90:	0f b6 c0             	movzx  eax,al
  594a93:	8d 0c c5 00 00 00 00 	lea    ecx,[eax*8+0x0]
  594a9a:	6a ff                	push   0xffffffff
  594a9c:	2b c8                	sub    ecx,eax
  594a9e:	8d 54 8f 04          	lea    edx,[edi+ecx*4+0x4]
  594aa2:	6a 00                	push   0x0
  594aa4:	52                   	push   edx
  594aa5:	8b ce                	mov    ecx,esi
  594aa7:	e8 34 dc e6 ff       	call   0x4026e0
  594aac:	84 db                	test   bl,bl
  594aae:	74 54                	je     0x594b04
  594ab0:	0f b6 c3             	movzx  eax,bl
  594ab3:	8d 0c c5 00 00 00 00 	lea    ecx,[eax*8+0x0]
  594aba:	6a ff                	push   0xffffffff
  594abc:	2b c8                	sub    ecx,eax
  594abe:	8d 54 8f 04          	lea    edx,[edi+ecx*4+0x4]
  594ac2:	6a 00                	push   0x0
  594ac4:	52                   	push   edx
  594ac5:	8b ce                	mov    ecx,esi
  594ac7:	e8 24 f7 e6 ff       	call   0x4041f0
  594acc:	5b                   	pop    ebx
  594acd:	5d                   	pop    ebp
  594ace:	c2 04 00             	ret    0x4
  594ad1:	84 db                	test   bl,bl
  594ad3:	74 21                	je     0x594af6
  594ad5:	0f b6 c3             	movzx  eax,bl
  594ad8:	8d 0c c5 00 00 00 00 	lea    ecx,[eax*8+0x0]
  594adf:	6a ff                	push   0xffffffff
  594ae1:	2b c8                	sub    ecx,eax
  594ae3:	8d 54 8f 04          	lea    edx,[edi+ecx*4+0x4]
  594ae7:	6a 00                	push   0x0
  594ae9:	52                   	push   edx
  594aea:	8b ce                	mov    ecx,esi
  594aec:	e8 ef db e6 ff       	call   0x4026e0
  594af1:	5b                   	pop    ebx
  594af2:	5d                   	pop    ebp
  594af3:	c2 04 00             	ret    0x4
  594af6:	6a 00                	push   0x0
  594af8:	68 fc d1 be 00       	push   0xbed1fc
  594afd:	8b ce                	mov    ecx,esi
  594aff:	e8 5c d6 e6 ff       	call   0x402160
  594b04:	5b                   	pop    ebx
  594b05:	5d                   	pop    ebp
  594b06:	c2 04 00             	ret    0x4
```


### 0x00546230–0x005462A4（raw 0x145630）

```asm
00546230 <.text+0x145230>:
  546230:	8b 87 58 01 00 00    	mov    eax,DWORD PTR [edi+0x158]
  546236:	85 c0                	test   eax,eax
  546238:	74 03                	je     0x54623d
  54623a:	8b 70 2c             	mov    esi,DWORD PTR [eax+0x2c]
  54623d:	8b cf                	mov    ecx,edi
  54623f:	e8 8c 3c f8 ff       	call   0x4c9ed0
  546244:	85 f6                	test   esi,esi
  546246:	0f 84 ba 00 00 00    	je     0x546306
  54624c:	85 c0                	test   eax,eax
  54624e:	0f 85 b2 00 00 00    	jne    0x546306
  546254:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  546258:	8d 4c 24 20          	lea    ecx,[esp+0x20]
  54625c:	51                   	push   ecx
  54625d:	8d 54 24 20          	lea    edx,[esp+0x20]
  546261:	52                   	push   edx
  546262:	57                   	push   edi
  546263:	e8 18 05 00 00       	call   0x546780
  546268:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  54626c:	e8 ef e6 ef ff       	call   0x444960
  546271:	80 b8 ef 07 00 00 01 	cmp    BYTE PTR [eax+0x7ef],0x1
  546278:	75 0c                	jne    0x546286
  54627a:	b8 00 01 00 00       	mov    eax,0x100
  54627f:	c6 44 24 17 01       	mov    BYTE PTR [esp+0x17],0x1
  546284:	eb 09                	jmp    0x54628f
  546286:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  54628a:	66 85 c0             	test   ax,ax
  54628d:	74 13                	je     0x5462a2
  54628f:	66 8b 4b 02          	mov    cx,WORD PTR [ebx+0x2]
  546293:	66 33 c8             	xor    cx,ax
  546296:	ba ff 7f 00 00       	mov    edx,0x7fff
  54629b:	66 23 ca             	and    cx,dx
  54629e:	66 31 4b 02          	xor    WORD PTR [ebx+0x2],cx
  5462a2:	83 3d      	cmp    DWORD PTR ds:0xfba7ac,0x1
```


## 保守偽碼（僅對已讀路徑）

```cpp
// 0x6D4DC0：函式名是研究用暫名；arg2 與 key 的遊戲語義待查
void collect_mapped_values(Vector<uint32_t>& out, uint32_t key, uint32_t arg2) {
    if ((uint32_t)(key - 0x2711) <= 0x270e) {
        auto& tree = special_bank[arg2]; // base 0xFDF3F4 + 16*arg2
        auto values = lookup_or_create_key_vector(tree, key); // 0x6D43F0；動態配置
        for (uint32_t v : values) out.push_back(v); // 空集合分支的預設 0 待看完整 CFG
    } else {
        auto& values = ordinary_bank[key + 40*arg2]; // base FB8834, stride 16
        for (uint32_t v : values) out.push_back(v);
    }
}
```

這個偽碼只示意已觀察到的資料流，不宣稱超界防護、參數範圍或 `lookup_or_create` 的完整安全語義。`0x6D43F0` 會在找不到鍵時配置節點，從機器碼看不能單純寫成純唯讀 lookup。

## 證據分級與新缺口

| 判定 | 級別 | 依據／限制 |
|---|---|---|
| 6D4DC0 按兩參數選 bank，迴圈將 DWORD 追加到輸出 | 局部 BIN 已確認 | 6D4E02、6D4E49、6D4EE6、6D4F30～4FE9 |
| 6D4DC0 是非零 phase writer | 與當前直接證據不符 | 目前發現的是映射結果寫入 output vector；**不能**據此否定另有 phase writer |
| 594610 消費多個查詢結果，指定查 0D/0E/0F | 局部 BIN 已確認 | 5946BB～59471B、5947ED～59484D |
| 594A80 把編碼 DWORD 分解送往兩類輸出函式 | 局部 BIN 已確認 | 594A87～594AFF |
| 0D/0E/0F 或 EDI=18/19 等於 Z/X/C/V | 尚待驗證 | 尚缺 XML action row、設定讀取及使用者重綁實例連線 |
| 546780 與 546263 是 direct caller/callee | BIN 已確認 | E8 rel32 在 546263；後續 actor gate 沒有還原完整 |
| 非零鍵 phase writer、V 蓄氣、普通攻擊 next-action/cancel | 缺口 | 此段沒觸及可靠 writer 或動作 queue 證據 |

## 下一大型研究主題（不限一兩個函式）

1. 從 `0x594610` 的 caller 向上追，查明 `edi` 是否真正是可重綁 action 及其 XML 載入路徑；確認 `0x0D`、`0x0E`、`0x0F` 是修飾鍵還是 action indices。
2. 定位 `0x6D4DC0` 所用 `0xFB8834` 與 `0xFDF3F4` 容器的非初始化 writer；不把 container writer 與 phase writer 混同。
3. 依 `0x6D4CE0` 的調用者與非零 `0xFB9004` writes 追真正鍵盤事件來源；找 KeyMapping.xml/default row 證據。
4. 沿 `0x546263`、`0x546780` 輸出流追 actor 動作啟動及 queue/cancel；與 T11 技能裁決僅做明確 interface 引用。

## GitHub 證據使用界線

本次一手原始 BIN 已核對；`T01-20261027-05` 與 REBASE 原稿只能作索引，沒有逐份完成 T10-1～44 的最新 GitHub SHA reconciliation，不宣稱舊 44 段全部驗收。原版 0.65 秒是 AI 替代，500ms state gate 也不等於原版 Z 連段窗口。