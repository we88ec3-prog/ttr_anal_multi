# T10 REBASE-02 — 輸入狀態回傳旗標、索引清除與命令產生資料流

- 時間：2026-10-28T01:30:56.494136+08:00
- 來源：本機 `/mnt/data/Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，原始唯讀靜態分析；GNU objdump `-D -Mintel -b pei-i386 -m i386`。
- GitHub：繼承 REBASE-01 的 T01-20261027-05 限定接受邊界；本段 **沒有** commit、push、owner/catalog 變動。T10-1～44 尚未逐份完成 SHA reconciliation，不能稱全面 rebase。
- 新段號採 `REBASE-02`，不是未經基準重審的 `T10-45`。

## 核心新證據及分析

### A. `0x546780`：狀態機輸出轉換為 WORD bitmask，再合流三路輸入

1. `0x546791` 從 `[edi+0x5c]` 取 WORD 作為 `ebx` 既有旗標；`esi=edi+0x40`。`0x54678f` 取得來源 BYTE，複製到三個暫存位置。
2. `0x5467a4` 直接呼叫 `0x547240`；該函式按照 `esi` 的兩 DWORD state/tick 與全域 `[0xFB9014]` 做狀態轉換，當它回傳 **2、3、4**，caller 各自把 **`0x08`、`0x80`、`0x40`** OR 到 `ebx`。其他回傳值（0、1）不在這段設定上述位元。
3. `0x5467cc` 呼叫 `0x546850`，`0x5467e0` 呼叫 `0x546b50`，`0x5467ec` 呼叫 `0x546d50`。`0x5467f4` 將 WORD `bx` 寫至 `[ebp+0x10]` 指向的外部輸出；0x5467f7 後呈現路徑優先順序：`546850` 非零則選第一個 byte；否則 `546b50` 非零則選第二個 byte；否則依第三個結果走後續分支。各路 BOOL 結果使用 OR 合流，不能與 byte 選擇優先順序混淆。
4. **限制：** 僅知 machine-code 的 bitmask 生成，不可命名 `0x80=V 長按` 或 `0x08=普攻`；`edi+0x5c` 的結構來源、caller 實參、輸出消費者仍需逆追。

```asm
  546780:	55                   	push   ebp
  546781:	8b ec                	mov    ebp,esp
  546783:	83 e4 f8             	and    esp,0xfffffff8
  546786:	51                   	push   ecx
  546787:	53                   	push   ebx
  546788:	56                   	push   esi
  546789:	57                   	push   edi
  54678a:	8b f8                	mov    edi,eax
  54678c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  54678f:	8a 00                	mov    al,BYTE PTR [eax]
  546791:	0f b7 5f 5c          	movzx  ebx,WORD PTR [edi+0x5c]
  546795:	8d 77 40             	lea    esi,[edi+0x40]
  546798:	88 44 24 0d          	mov    BYTE PTR [esp+0xd],al
  54679c:	88 44 24 0e          	mov    BYTE PTR [esp+0xe],al
  5467a0:	88 44 24 0f          	mov    BYTE PTR [esp+0xf],al
  5467a4:	e8 97 0a 00 00       	call   0x547240
  5467a9:	85 c0                	test   eax,eax
  5467ab:	74 1b                	je     0x5467c8
  5467ad:	83 e8 02             	sub    eax,0x2
  5467b0:	74 13                	je     0x5467c5
  5467b2:	48                   	dec    eax
  5467b3:	74 08                	je     0x5467bd
  5467b5:	48                   	dec    eax
  5467b6:	75 10                	jne    0x5467c8
  5467b8:	83 cb 40             	or     ebx,0x40
  5467bb:	eb 0b                	jmp    0x5467c8
  5467bd:	81 cb 80 00 00 00    	or     ebx,0x80
  5467c3:	eb 03                	jmp    0x5467c8
  5467c5:	83 cb 08             	or     ebx,0x8
  5467c8:	8d 4c 24 0d          	lea    ecx,[esp+0xd]
  5467cc:	51                   	push   ecx
  5467cd:	e8 7e 00 00 00       	call   0x546850
  5467d2:	8b f0                	mov    esi,eax
  5467d4:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5467d7:	56                   	push   esi
  5467d8:	8d 54 24 12          	lea    edx,[esp+0x12]
  5467dc:	52                   	push   edx
  5467dd:	50                   	push   eax
  5467de:	8b c7                	mov    eax,edi
  5467e0:	e8 6b 03 00 00       	call   0x546b50
  5467e5:	8d 4c 24 0f          	lea    ecx,[esp+0xf]
  5467e9:	51                   	push   ecx
  5467ea:	8b f8                	mov    edi,eax
  5467ec:	e8 5f 05 00 00       	call   0x546d50
  5467f1:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  5467f4:	66 89 1a             	mov    WORD PTR [edx],bx
  5467f7:	85 f6                	test   esi,esi
  5467f9:	74 16                	je     0x546811
  5467fb:	8a 4c 24 0d          	mov    cl,BYTE PTR [esp+0xd]
  5467ff:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  546802:	0b c7                	or     eax,edi
  546804:	88 0a                	mov    BYTE PTR [edx],cl
  546806:	0b c6                	or     eax,esi
  546808:	5f                   	pop    edi
  546809:	5e                   	pop    esi
  54680a:	5b                   	pop    ebx
  54680b:	8b e5                	mov    esp,ebp
  54680d:	5d                   	pop    ebp
  54680e:	c2 0c 00             	ret    0xc
  546811:	85 ff                	test   edi,edi
  546813:	74 16                	je     0x54682b
  546815:	8a 4c 24 0e          	mov    cl,BYTE PTR [esp+0xe]
  546819:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  54681c:	0b c7                	or     eax,edi
  54681e:	88 0a                	mov    BYTE PTR [edx],cl
  546820:	0b c6                	or     eax,esi
  546822:	5f                   	pop    edi
  546823:	5e                   	pop    esi
  546824:	5b                   	pop    ebx
  546825:	8b e5                	mov    esp,ebp
  546827:	5d                   	pop    ebp
  546828:	c2 0c 00             	ret    0xc
```

### B. `0x6D4A30`：輸入索引清除 producer；不是非零 key-phase writer

1. 在 `[ebp+8]` BYTE 非零分支 (`0x6d4a93` 起)，`xor eax,eax` 後多次 `mov [0xFB9004..0xFB9028],eax`，每次是 DWORD zero；實際覆蓋連續 bytes，不應直接把這些位置都當獨立 action。
2. 在 BYTE 零分支，若 `[0xFB8830]` 非零，`0x6d4b69..0x6d4b98` 也執行同區域清除。
3. `0x6d4c20..0x6d4cb5` 遍歷傳入鏈表的節點 `[edi+8]`，比較 `esi - 0x2711` 與 `0x270E`，區分受管理 key/index 域。範圍外走 `0x6d4cae: mov byte ptr [esi+0xFB9004],0`；範圍內則查 `0xFDF630` 索引樹並清節點 `+0x10` BYTE。此為依 key domain 選擇不同清零位置，不能等同 nonzero writer。
4. **重要邊界：** index 來源取自鏈表資料，尚未與遊戲 action row 或 Z/X/C/V 直接綁定；`0x2711..0x4E1F` 的算術測試不代表真實可用鍵碼完整列表。

```asm
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
  6d4b69:	33 c0                	xor    eax,eax
  6d4b6b:	a3 04 90 fb 00       	mov    ds:0xfb9004,eax
  6d4b70:	a3 08 90 fb 00       	mov    ds:0xfb9008,eax
  6d4b75:	a3 0c 90 fb 00       	mov    ds:0xfb900c,eax
  6d4b7a:	a3 10 90 fb 00       	mov    ds:0xfb9010,eax
  6d4b7f:	a3 14 90 fb 00       	mov    ds:0xfb9014,eax
  6d4b84:	a3 18 90 fb 00       	mov    ds:0xfb9018,eax
  6d4b89:	a3 1c 90 fb 00       	mov    ds:0xfb901c,eax
  6d4b8e:	a3 20 90 fb 00       	mov    ds:0xfb9020,eax
  6d4b93:	a3 24 90 fb 00       	mov    ds:0xfb9024,eax
  6d4b98:	a3 28 90 fb 00       	mov    ds:0xfb9028,eax
  6d4c06:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  6d4c09:	8b 00                	mov    eax,DWORD PTR [eax]
  6d4c0b:	8b 38                	mov    edi,DWORD PTR [eax]
  6d4c0d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  6d4c10:	3b f8                	cmp    edi,eax
  6d4c12:	0f 84 a8 00 00 00    	je     0x6d4cc0
  6d4c18:	eb 06                	jmp    0x6d4c20
  6d4c1a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  6d4c20:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  6d4c23:	8d 8e ef d8 ff ff    	lea    ecx,[esi-0x2711]
  6d4c29:	81 f9 0e 27 00 00    	cmp    ecx,0x270e
  6d4c2f:	77 51                	ja     0x6d4c82
  6d4c31:	f6 05 ec f3 fd 00 01 	test   BYTE PTR ds:0xfdf3ec,0x1
  6d4c38:	75 23                	jne    0x6d4c5d
  6d4c3a:	83 0d ec f3 fd 00 01 	or     DWORD PTR ds:0xfdf3ec,0x1
  6d4c41:	c7 45 fc 06 00 00 00 	mov    DWORD PTR [ebp-0x4],0x6
  6d4c48:	e8 53 d1 ff ff       	call   0x6d1da0
  6d4c4d:	68 30 e3 bc 00       	push   0xbce330
  6d4c52:	e8 c3 d6 1b 00       	call   0x89231a
  6d4c57:	83 c4 04             	add    esp,0x4
  6d4c5a:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4c5d:	8d 55 08             	lea    edx,[ebp+0x8]
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
```

### C. `0x6D4CE0`：一般與特殊鍵範圍的讀取介面

`0x6d4d05` 使用 `[esi - 0x2711] <= 0x270E` unsigned 範圍決定查 `0xFDF630` 索引樹並取 `node+0x10` BYTE，超出範圍時轉到 `0x6d4d70`，後續讀 `[esi+0xFB9004]`；與 `0x6d4a30` 的清除分流對應。尚未定位其所有 caller 如何提供 `esi`，所以不是全域玩家輸入 API 的完整證明。

```asm
  6d4ce0:	55                   	push   ebp
  6d4ce1:	8b ec                	mov    ebp,esp
  6d4ce3:	6a ff                	push   0xffffffff
  6d4ce5:	68 5c 68 92 00       	push   0x92685c
  6d4cea:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  6d4cf0:	50                   	push   eax
  6d4cf1:	83 ec 08             	sub    esp,0x8
  6d4cf4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6d4cf9:	33 c5                	xor    eax,ebp
  6d4cfb:	50                   	push   eax
  6d4cfc:	8d 45 f4             	lea    eax,[ebp-0xc]
  6d4cff:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  6d4d05:	8d 86 ef d8 ff ff    	lea    eax,[esi-0x2711]
  6d4d0b:	3d 0e 27 00 00       	cmp    eax,0x270e
  6d4d10:	b8 01 00 00 00       	mov    eax,0x1
  6d4d15:	77 59                	ja     0x6d4d70
  6d4d17:	84 05 ec f3 fd 00    	test   BYTE PTR ds:0xfdf3ec,al
  6d4d1d:	75 1f                	jne    0x6d4d3e
  6d4d1f:	09 05 ec f3 fd 00    	or     DWORD PTR ds:0xfdf3ec,eax
  6d4d25:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  6d4d2c:	e8 6f d0 ff ff       	call   0x6d1da0
  6d4d31:	68 30 e3 bc 00       	push   0xbce330
  6d4d36:	e8 df d5 1b 00       	call   0x89231a
  6d4d3b:	83 c4 04             	add    esp,0x4
  6d4d3e:	8d 4d f0             	lea    ecx,[ebp-0x10]
  6d4d41:	51                   	push   ecx
  6d4d42:	8d 45 ec             	lea    eax,[ebp-0x14]
  6d4d45:	b9 30 f6 fd 00       	mov    ecx,0xfdf630
  6d4d4a:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  6d4d4d:	e8 ae a1 15 00       	call   0x82ef00
  6d4d52:	8b 45 ec             	mov    eax,DWORD PTR [ebp-0x14]
  6d4d55:	3b 05 34 f6 fd 00    	cmp    eax,DWORD PTR ds:0xfdf634
  6d4d5b:	74 51                	je     0x6d4dae
  6d4d5d:	0f b6 40 10          	movzx  eax,BYTE PTR [eax+0x10]
  6d4d61:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d4d64:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d4d6b:	59                   	pop    ecx
  6d4d6c:	8b e5                	mov    esp,ebp
  6d4d6e:	5d                   	pop    ebp
  6d4d6f:	c3                   	ret
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
  6d4db3:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d4dba:	59                   	pop    ecx
  6d4dbb:	8b e5                	mov    esp,ebp
  6d4dbd:	5d                   	pop    ebp
  6d4dbe:	c3                   	ret
```

### D. `0x548918`：特殊索引 phase=1 生成命令的前次 BIN 證據交叉引用

`0x548957` 對 `[esi+0xFB9004]` 按 BYTE 讀取，`0x54895e` 只接受 1，`0x548985` 設命令 WORD=0x68；`0x5489a0` 從 `[0xFBA854]` 取得 receiver vtable+0x10，經 gate `[0xFBA798]==0` 後間接呼叫。索引初始化 28，最後處理至 37。此僅證明 phase consumer / conditional command producer，不證明 0x68 命令就是普攻或取消。

```asm
  548918:	33 db                	xor    ebx,ebx
  54891a:	8d 73 1c             	lea    esi,[ebx+0x1c]
  54891d:	8d 49 00             	lea    ecx,[ecx+0x0]
  548920:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  548927:	75 29                	jne    0x548952
  548929:	83 0d 14 7c fb 00 01 	or     DWORD PTR ds:0xfb7c14,0x1
  548930:	c7 44 24 28 04 00 00 	mov    DWORD PTR [esp+0x28],0x4
  548937:	00 
  548938:	e8 13 7e 18 00       	call   0x6d0750
  54893d:	68 30 d5 bc 00       	push   0xbcd530
  548942:	e8 d3 99 34 00       	call   0x89231a
  548947:	83 c4 04             	add    esp,0x4
  54894a:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  548951:	ff 
  548952:	83 fe 27             	cmp    esi,0x27
  548955:	77 57                	ja     0x5489ae
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
  5489a5:	8d 54 24 18          	lea    edx,[esp+0x18]
  5489a9:	52                   	push   edx
  5489aa:	6a 00                	push   0x0
  5489ac:	ff d0                	call   eax
  5489ae:	46                   	inc    esi
  5489af:	43                   	inc    ebx
  5489b0:	83 fe 26             	cmp    esi,0x26
  5489b3:	0f 8c 67 ff ff ff    	jl     0x548920
  5489b9:	8a 44 24 13          	mov    al,BYTE PTR [esp+0x13]
```

## 已確認／推測／缺口

| 範圍 | 狀態 | 依據或限制 |
|---|---|---|
| `0x547240` 回傳值 2/3/4 對 bit 0x08/0x80/0x40 | BIN 直接確認 | `0x5467a4..0x5467c5` |
| `0x546780` 三路輸入合流與 byte 優先選擇 | BIN 局部確認 | `0x5467c8..0x546838`；尾段及上游需擴充 |
| `0x6d4a30` 清零 `[0xFB9004]` 索引狀態 | BIN 直接確認 | 多段 DWORD zero 與 indexed byte zero |
| `0x6d4ce0` 根據索引範圍選不同儲存結構查詢 | BIN 局部確認 | key identity / full caller 未閉合 |
| `0x548918` phase1 特殊命令 0x68 | BIN 局部確認 | 0x68 實際 server 協定、動作語義未閉合 |
| 正常鍵 down/held/release phase 非零 writer | 缺口 | 搜到的直接定址多為零；可能間接 / memcpy 寫入 |
| Z/X/C/V 的使用者自訂對照 | 玩家觀察＋研究缺口 | 找 `KeyMapping.xml` row / fallback / parser，不以 VK_Z 假定 |
| V tap/hold 與普攻交互影響 | 玩家觀察＋研究缺口 | 不將 500ms 或 SubAI >60 套為 V 蓄氣 |
| combo / cancel / motion completion / next-action queue | 缺口 | 不使用 0.65 秒替代規則 |

## 後續優先功能鏈（不切碎成補段）

1. 逆追 `0x546780` caller 及 `edi` 真實配置，確認 state/tick +0x40 和 bitmask +0x5c 的 actor/controller 所有權，以及輸出消費者。
2. 沿 `0x6d4ce0` 與 `0x6d4dc0` 事件路由尋找 **非零 byte phase writer**，尤其非立即定址的索引 store、物件 byte 寫入和 keyboard event dispatch。
3. 審核 `KeyMapping.xml` 字串參照、action row loader、fallback 對照，將實際自訂 Z/X/C/V action 與輸入陣列接起來。
4. 找 `0xFBA854` receiver 真正 vtable +0x10 實例和 `0x68` command 處理者，再追 action queue、動作開始／完成與 cancel，跨 T11 只記介面。
5. 將全 44 篇筆記 SHA 對照 `shared/source-review-status.json`，逐條接受有限整合結論與更正。若無逐檔驗證不得寫已完成。

## PE VA↔file raw

本段 `.text` VA = `0x401000` raw = `0x400`（BIN PE section header）。因此 raw = VA - `0x400C00`：`0x546780`→`0x145B80`；`0x6D4A30`→`0x2D3E30`；`0x6D4CE0`→`0x2D40E0`；`0x548918`→`0x147D18`。需注意之前其他 Task 所述 PE/flat 來源映射爭議不可直接套用到此個別核對。