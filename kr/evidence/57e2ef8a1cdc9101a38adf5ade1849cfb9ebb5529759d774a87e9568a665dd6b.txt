# T10-50 — indexed-byte-store-provenance

- 時間：2026-10-28T01:49:00+08:00 (Asia/Taipei)
- 來源：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- PE .text: VA 0x401000 / raw 0x400；此處所有摘錄均由原始 bytes 唯讀反組譯，非 Ghidra 摘要。
- GitHub T01-20261027-05 語意接受範圍僅為部分確認；此筆記無法自動擴大為整函式 native 驗收。
- 原始目標未執行，未修改、未附加遊戲。

## 本段核心：靜態位址引用的讀寫分類

BIN `.text` 掃描 little-endian `0x00FB9004` 立即數共 **7** 處命中：`0x54895A`、`0x6D0876`、`0x6D1B03`、`0x6D4A9D`、`0x6D4B6C`、`0x6D4CB0`、`0x6D4D9B`（均是即時值出現的位置，與指令起點可差 1–3 bytes）。

### 逐路分類

- `0x548957: movzx eax, byte ptr [esi+0xFB9004]`：**讀取**，緊接著 `cmp eax,1`。這只證 index 狀態 byte 是否等於 1，不證其是 keydown。
- `0x6D4D98: movzx eax,byte ptr [esi+0xFB9004]`：**讀取**；此前有 `esi<=0x27` 的範圍守衛。
- `0x6D1B00: xor eax,eax; 0x6D1B02: mov [0xFB9004],eax`，並連續清理後續 DWORD：**寫零**。
- `0x6D4CAE: mov byte ptr [esi+0xFB9004],0`：**indexed 寫零**；前段 `0x6D4C20` 用特殊鍵碼範圍比較選樹分支、`0x6D4C7C` 寫特殊節點 `+0x10=0`。此段對兩域都可見 reset/clear。
- `0x6D4A9C`、`0x6D4B6B`：初始化／重置清零，需結合完整前置 `xor eax,eax` 與可達上下文判斷；不視為事件 writer。
- `0x6D0875`：初始化片段內直接 DWORD 寫入，不能只憑地址 literal 判定為實時 input phase。

### 精確限制

命中數是**原始 `.text` 位元組對 4-byte literal 的出現次數**，不是 CFG 資料流覆蓋率，亦可能漏掉 pointer alias、relocation 表、base+displacement 拆開或間接位址，因此 **不能以「沒查到」證明不存在非零 writer**。下一步需要反向找對該全域陣列取地址的 routine 或 OS 事件轉換。

## 第一手反組譯片段

### VA `0x006d1ae1` / raw `0x002d0ee1` (90 bytes)

```asm
006d1ae1 <.data>:
  6d1ae1:	8a 0d eb 91 fb 00    	mov    cl,BYTE PTR ds:0xfb91eb
  6d1ae7:	8a c3                	mov    al,bl
  6d1ae9:	3a d9                	cmp    bl,cl
  6d1aeb:	76 02                	jbe    0x6d1aef
  6d1aed:	8a c1                	mov    al,cl
  6d1aef:	8a 0d ea 91 fb 00    	mov    cl,BYTE PTR ds:0xfb91ea
  6d1af5:	3a c1                	cmp    al,cl
  6d1af7:	73 02                	jae    0x6d1afb
  6d1af9:	8a c1                	mov    al,cl
  6d1afb:	a2 e9 91 fb 00       	mov    ds:0xfb91e9,al
  6d1b00:	33 c0                	xor    eax,eax
  6d1b02:	a3 04 90 fb 00       	mov    ds:0xfb9004,eax
  6d1b07:	a3 08 90 fb 00       	mov    ds:0xfb9008,eax
  6d1b0c:	a3 0c 90 fb 00       	mov    ds:0xfb900c,eax
  6d1b11:	a3 10 90 fb 00       	mov    ds:0xfb9010,eax
  6d1b16:	a3 14 90 fb 00       	mov    ds:0xfb9014,eax
  6d1b1b:	a3 18 90 fb 00       	mov    ds:0xfb9018,eax
  6d1b20:	a3 1c 90 fb 00       	mov    ds:0xfb901c,eax
  6d1b25:	a3 20 90 fb 00       	mov    ds:0xfb9020,eax
  6d1b2a:	a3 24 90 fb 00       	mov    ds:0xfb9024,eax
  6d1b2f:	a3 28 90 fb 00       	mov    ds:0xfb9028,eax
  6d1b34:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d1b37:	64                   	fs
  6d1b38:	89                   	.byte 0x89
  6d1b39:	0d                   	.byte 0xd
	...
```
### VA `0x006d4a90` / raw `0x002d3e90` (75 bytes)

```asm
006d4a90 <.data>:
  6d4a90:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4a93:	33 c0                	xor    eax,eax
  6d4a95:	f6 05 ec f3 fd 00 01 	test   BYTE PTR ds:0xfdf3ec,0x1
  6d4a9c:	a3 04 90 fb 00       	mov    ds:0xfb9004,eax
  6d4aa1:	a3 08 90 fb 00       	mov    ds:0xfb9008,eax
  6d4aa6:	a3 0c 90 fb 00       	mov    ds:0xfb900c,eax
  6d4aab:	a3 10 90 fb 00       	mov    ds:0xfb9010,eax
  6d4ab0:	a3 14 90 fb 00       	mov    ds:0xfb9014,eax
  6d4ab5:	a3 18 90 fb 00       	mov    ds:0xfb9018,eax
  6d4aba:	a3 1c 90 fb 00       	mov    ds:0xfb901c,eax
  6d4abf:	a3 20 90 fb 00       	mov    ds:0xfb9020,eax
  6d4ac4:	a3 24 90 fb 00       	mov    ds:0xfb9024,eax
  6d4ac9:	a3 28 90 fb 00       	mov    ds:0xfb9028,eax
  6d4ace:	75 1e                	jne    0x6d4aee
  6d4ad0:	09 35 ec f3 fd 00    	or     DWORD PTR ds:0xfdf3ec,esi
  6d4ad6:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  6d4ad9:	e8                   	.byte 0xe8
  6d4ada:	c2                   	.byte 0xc2
```
### VA `0x006d4c60` / raw `0x002d4060` (115 bytes)

```asm
006d4c60 <.data>:
  6d4c60:	52                   	push   edx
  6d4c61:	8d 45 f0             	lea    eax,[ebp-0x10]
  6d4c64:	b9 30 f6 fd 00       	mov    ecx,0xfdf630
  6d4c69:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  6d4c6c:	e8 8f a2 15 00       	call   0x82ef00
  6d4c71:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  6d4c74:	3b 05 34 f6 fd 00    	cmp    eax,DWORD PTR ds:0xfdf634
  6d4c7a:	74 39                	je     0x6d4cb5
  6d4c7c:	c6 40 10 00          	mov    BYTE PTR [eax+0x10],0x0
  6d4c80:	eb 33                	jmp    0x6d4cb5
  6d4c82:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  6d4c89:	75 23                	jne    0x6d4cae
  6d4c8b:	83 0d 14 7c fb 00 01 	or     DWORD PTR ds:0xfb7c14,0x1
  6d4c92:	c7 45 fc 07 00 00 00 	mov    DWORD PTR [ebp-0x4],0x7
  6d4c99:	e8 b2 ba ff ff       	call   0x6d0750
  6d4c9e:	68 30 d5 bc 00       	push   0xbcd530
  6d4ca3:	e8 72 d6 1b 00       	call   0x89231a
  6d4ca8:	83 c4 04             	add    esp,0x4
  6d4cab:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4cae:	c6 86 04 90 fb 00 00 	mov    BYTE PTR [esi+0xfb9004],0x0
  6d4cb5:	8b 3f                	mov    edi,DWORD PTR [edi]
  6d4cb7:	3b 7d ec             	cmp    edi,DWORD PTR [ebp-0x14]
  6d4cba:	0f 85 60 ff ff ff    	jne    0x6d4c20
  6d4cc0:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d4cc3:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d4cca:	59                   	pop    ecx
  6d4ccb:	5f                   	pop    edi
  6d4ccc:	5e                   	pop    esi
  6d4ccd:	5b                   	pop    ebx
  6d4cce:	8b e5                	mov    esp,ebp
  6d4cd0:	5d                   	pop    ebp
  6d4cd1:	c3                   	ret
  6d4cd2:	cc                   	int3
```
### VA `0x006d4d70` / raw `0x002d4170` (70 bytes)

```asm
006d4d70 <.data>:
  6d4d70:	84 05 14 7c fb 00    	test   BYTE PTR ds:0xfb7c14,al
  6d4d76:	75 1b                	jne    0x6d4d93
  6d4d78:	09 05 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,eax
  6d4d7e:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  6d4d81:	e8 ca b9 ff ff       	call   0x6d0750
  6d4d86:	68 30 d5 bc 00       	push   0xbcd530
  6d4d8b:	e8 8a d5 1b 00       	call   0x89231a
  6d4d90:	83 c4 04             	add    esp,0x4
  6d4d93:	83 fe 27             	cmp    esi,0x27
  6d4d96:	77 16                	ja     0x6d4dae
  6d4d98:	0f b6 86 04 90 fb 00 	movzx  eax,BYTE PTR [esi+0xfb9004]
  6d4d9f:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d4da2:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d4da9:	59                   	pop    ecx
  6d4daa:	8b e5                	mov    esp,ebp
  6d4dac:	5d                   	pop    ebp
  6d4dad:	c3                   	ret
  6d4dae:	33 c0                	xor    eax,eax
  6d4db0:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d4db3:	64                   	fs
  6d4db4:	89                   	.byte 0x89
  6d4db5:	0d                   	.byte 0xd
```
### VA `0x00548950` / raw `0x00147d50` (85 bytes)

```asm
00548950 <.data>:
  548950:	ff                   	(bad)
  548951:	ff 83 fe 27 77 57    	inc    DWORD PTR [ebx+0x577727fe]
  548957:	0f b6 86 04 90 fb 00 	movzx  eax,BYTE PTR [esi+0xfb9004]
  54895e:	83 f8 01             	cmp    eax,0x1
  548961:	75 4b                	jne    0x5489ae
  548963:	84 05 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,al
  548969:	75 13                	jne    0x54897e
  54896b:	09 05 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,eax
  548971:	68 10 cf bc 00       	push   0xbccf10
  548976:	e8 9f 99 34 00       	call   0x89231a
  54897b:	83 c4 04             	add    esp,0x4
  54897e:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  548985:	b9 68 00 00 00       	mov    ecx,0x68
  54898a:	8d 53 01             	lea    edx,[ebx+0x1]
  54898d:	66 89 4c 24 14       	mov    WORD PTR [esp+0x14],cx
  548992:	88 54 24 16          	mov    BYTE PTR [esp+0x16],dl
  548996:	75 16                	jne    0x5489ae
  548998:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  54899e:	8b 01                	mov    eax,DWORD PTR [ecx]
  5489a0:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  5489a3:	6a 03                	push   0x3
```
### VA `0x006d0820` / raw `0x002cfc20` (145 bytes)

```asm
006d0820 <.data>:
  6d0820:	a3 c0 8f fb 00       	mov    ds:0xfb8fc0,eax
  6d0825:	a3 c4 8f fb 00       	mov    ds:0xfb8fc4,eax
  6d082a:	a3 c8 8f fb 00       	mov    ds:0xfb8fc8,eax
  6d082f:	a3 cc 8f fb 00       	mov    ds:0xfb8fcc,eax
  6d0834:	a3 d0 8f fb 00       	mov    ds:0xfb8fd0,eax
  6d0839:	a3 d4 8f fb 00       	mov    ds:0xfb8fd4,eax
  6d083e:	a3 d8 8f fb 00       	mov    ds:0xfb8fd8,eax
  6d0843:	a3 dc 8f fb 00       	mov    ds:0xfb8fdc,eax
  6d0848:	a3 e0 8f fb 00       	mov    ds:0xfb8fe0,eax
  6d084d:	a3 e4 8f fb 00       	mov    ds:0xfb8fe4,eax
  6d0852:	a3 e8 8f fb 00       	mov    ds:0xfb8fe8,eax
  6d0857:	a3 ec 8f fb 00       	mov    ds:0xfb8fec,eax
  6d085c:	a3 f0 8f fb 00       	mov    ds:0xfb8ff0,eax
  6d0861:	a3 f4 8f fb 00       	mov    ds:0xfb8ff4,eax
  6d0866:	a3 f8 8f fb 00       	mov    ds:0xfb8ff8,eax
  6d086b:	a3 fc 8f fb 00       	mov    ds:0xfb8ffc,eax
  6d0870:	a3 00 90 fb 00       	mov    ds:0xfb9000,eax
  6d0875:	a3 04 90 fb 00       	mov    ds:0xfb9004,eax
  6d087a:	a3 08 90 fb 00       	mov    ds:0xfb9008,eax
  6d087f:	a3 0c 90 fb 00       	mov    ds:0xfb900c,eax
  6d0884:	a3 10 90 fb 00       	mov    ds:0xfb9010,eax
  6d0889:	a3 14 90 fb 00       	mov    ds:0xfb9014,eax
  6d088e:	a3 18 90 fb 00       	mov    ds:0xfb9018,eax
  6d0893:	a3 1c 90 fb 00       	mov    ds:0xfb901c,eax
  6d0898:	a3 20 90 fb 00       	mov    ds:0xfb9020,eax
  6d089d:	a3 24 90 fb 00       	mov    ds:0xfb9024,eax
  6d08a2:	a3 28 90 fb 00       	mov    ds:0xfb9028,eax
  6d08a7:	b8 30 88 fb 00       	mov    eax,0xfb8830
  6d08ac:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d08af:	64                   	fs
  6d08b0:	89                   	.byte 0x89
```

## 可重現的呼叫掃描（原始 BIN）

- Direct E8 target `0x6d4ce0`：0x59624e, 0x59643f。注意僅是 bytes 命中，不是全部可達路徑。
- Direct E8 target `0x6d4a30`：0x490dfc, 0x58a607。注意僅是 bytes 命中，不是全部可達路徑。
- Direct E8 target `0x594610`：0x5cd91f, 0x5d1b75, 0x5d2dd5, 0x5d4045, 0x60e06b, 0x651122, 0x65117e, 0x6511da, 0x65120a。注意僅是 bytes 命中，不是全部可達路徑。

## 明確未解

- 自訂 action mapping 的實際 XML 資料與儲存 writer 尚未連上。
- 玩家 V 短按／長按、Z 長按自動續段、普通攻擊與技能前後銜接的 queue、cancel window 均尚無直接跨函式證據。
- 間接函式、物件類型與多執行緒事件來源應繼續按實例校驗，不可單憑相同 offset 或名稱視為相等。