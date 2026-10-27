# T10-46 — 一般索引鍵狀態讀取、清零與雙來源的分離

- 產生時間：2026-10-28T01:40:26+08:00（Asia/Taipei）
- BIN：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- EXE：`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`
- BIN PE `.text` 解碼採 VA = `0x401000 + (file_offset - 0x400)`；以下 raw offset = VA − 0x401000 + 0x400，僅適用 `.text`。
- 只做唯讀靜態分析；沒有啟動／附加／修改遊戲，也沒有把 AI fixture 視為原生結論。
- T10-45 後續連號；REBASE-01/02 不佔正式段號；過去筆記的主張須與 T01 限定整合及 BIN 直接核對分開。

## 本段原生核對與限定結論

### 已確認資料流
- `0x6D4CE0` 入口的 key 值在 ESI；先用 `key-0x2711` 與 `0x270E` 無號比較。進入特殊域時，呼叫 `0x82EF00` 以 `0xFDF630` 管理樹讀取，命中時讀節點 `+0x10` 單位 byte；非特殊域僅在 `key<=0x27` 時讀取 `BYTE PTR [0xFB9004+key]`，其餘落至零回傳。此處是 **reader** 而非 writer。
- `0x6D4A30` 在有條件的分支中直接連續清 `0xFB9004...0xFB9028` 十個 DWORD，共 40 bytes，不能把它稱作每一鍵之非零事件 writer。清零分支與一次性初始化旗標、容器建構有關，未從此判定每幀頻率。
- `0x6D4DC0` 是另外一個映射集合查詢，對特殊域與一般域查不同容器，結果附加至呼叫者提供的 vector；不能將 `0x6D4CE0` 單 byte state 與 `0x6D4DC0` 的 DWORD 映射元素當同一型別。
### 反證與缺口
- 沒有觀測任何對 `0xFB9004+key` 寫入非零 byte 的完整可達路徑；缺少 direct xref 不能證明不存在間接 pointer writer。
- 尚未證實一般域 key index 與 Z/X/C/V 的 XML action row、VK、組合輸入的對應。
- `0x2711...` 特殊鍵域的語意未命名；容器樹 `+0x10` 是被讀取者，不足以命名 keyboard phase。
### 後續可接續的追查
1. 在 `0x6D4CE0` xrefs 中辨識傳入 ESI 的來源；追該來源是否是 XML 加載的 action row 或掃描碼。
2. 用 address-literal + pointer-indexed xrefs 分離直接和間接對 `0xFB9004` 的 write；對命中者原始 BIN 核對其非零來源。
3. 對 `0xFDF630` 建構與節點 `+0x10` 寫入者做實例限定。


## 目標位址與原始 PE bytes 證據

### VA `0x006D4CE0` / raw `0x002D40E0` / window `213` bytes

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
  6d4db3:	64                   	fs
  6d4db4:	89                   	.byte 0x89
```

### VA `0x006D4A30` / raw `0x002D3E30` / window `224` bytes

```asm
  6d4a30:	55                   	push   ebp
  6d4a31:	8b ec                	mov    ebp,esp
  6d4a33:	6a ff                	push   0xffffffff
  6d4a35:	68 f0 68 92 00       	push   0x9268f0
  6d4a3a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  6d4a40:	50                   	push   eax
  6d4a41:	83 ec 0c             	sub    esp,0xc
  6d4a44:	53                   	push   ebx
  6d4a45:	56                   	push   esi
  6d4a46:	57                   	push   edi
  6d4a47:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6d4a4c:	33 c5                	xor    eax,ebp
  6d4a4e:	50                   	push   eax
  6d4a4f:	8d 45 f4             	lea    eax,[ebp-0xc]
  6d4a52:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  6d4a58:	83 cb ff             	or     ebx,0xffffffff
  6d4a5b:	80 7d 08 00          	cmp    BYTE PTR [ebp+0x8],0x0
  6d4a5f:	8d 73 02             	lea    esi,[ebx+0x2]
  6d4a62:	0f 84 a2 00 00 00    	je     0x6d4b0a
  6d4a68:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  6d4a6f:	75 22                	jne    0x6d4a93
  6d4a71:	09 35 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,esi
  6d4a77:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  6d4a7e:	e8 cd bc ff ff       	call   0x6d0750
  6d4a83:	68 30 d5 bc 00       	push   0xbcd530
  6d4a88:	e8 8d d8 1b 00       	call   0x89231a
  6d4a8d:	83 c4 04             	add    esp,0x4
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
  6d4ad9:	e8 c2 d2 ff ff       	call   0x6d1da0
  6d4ade:	68 30 e3 bc 00       	push   0xbce330
  6d4ae3:	e8 32 d8 1b 00       	call   0x89231a
  6d4ae8:	83 c4 04             	add    esp,0x4
  6d4aeb:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4aee:	bf 30 f6 fd 00       	mov    edi,0xfdf630
  6d4af3:	e8 58 ed 14 00       	call   0x823850
  6d4af8:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d4afb:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d4b02:	59                   	pop    ecx
  6d4b03:	5f                   	pop    edi
  6d4b04:	5e                   	pop    esi
  6d4b05:	5b                   	pop    ebx
  6d4b06:	8b e5                	mov    esp,ebp
  6d4b08:	5d                   	pop    ebp
  6d4b09:	c3                   	ret
  6d4b0a:	f6                   	.byte 0xf6
  6d4b0b:	05 14 7c fb 00       	add    eax,0xfb7c14
```

### VA `0x006D4DC0` / raw `0x002D41C0` / window `352` bytes

```asm
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
  6d4e5f:	f6 05 ec f3 fd 00 01 	test   BYTE PTR ds:0xfdf3ec,0x1
  6d4e66:	75 27                	jne    0x6d4e8f
  6d4e68:	b8 01 00 00 00       	mov    eax,0x1
  6d4e6d:	09 05 ec f3 fd 00    	or     DWORD PTR ds:0xfdf3ec,eax
  6d4e73:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  6d4e76:	e8 25 cf ff ff       	call   0x6d1da0
  6d4e7b:	68 30 e3 bc 00       	push   0xbce330
  6d4e80:	e8 95 d4 1b 00       	call   0x89231a
  6d4e85:	83 c4 04             	add    esp,0x4
  6d4e88:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
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
  6d4f00:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  6d4f07:	75 27                	jne    0x6d4f30
  6d4f09:	83 0d 14 7c fb 00 01 	or     DWORD PTR ds:0xfb7c14,0x1
  6d4f10:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  6d4f17:	e8 34 b8 ff ff       	call   0x6d0750
  6d4f1c:	68                   	.byte 0x68
  6d4f1d:	30 d5                	xor    ch,dl
  6d4f1f:	bc                   	.byte 0xbc
```

## Direct E8 relative call 候選（機械搜尋，不等同完整 CFG）

- `0x006D4CE0`：2 個候選指令位址：`0x0059624E`, `0x0059643F`

- `0x006D4A30`：2 個候選指令位址：`0x00490DFC`, `0x0058A607`

- `0x006D4DC0`：29 個候選指令位址：`0x00594672`, `0x005946CB`, `0x0059471B`, `0x005947FD`, `0x0059484D`, `0x0059492F`, `0x0059497F`, `0x00594CD4`, `0x00594DC4`, `0x00594EB4`, `0x00594FA4`, `0x00595094`, `0x00595184`, `0x00595274`, `0x00595364`, `0x00595454`, `0x00595544`, `0x00595634`, `0x00595724`, `0x00595814`, `0x00595901`, `0x005959F4`, `0x005CD68A`, `0x005CE5BA`, `0x0062B5BA`, `0x00650E96`, `0x00650F48`, `0x00650FF6`, `0x006510A4`

## 記錄品質／驗收界線
- 本段第一手原始 bytes 是上述每段 BIN window，由 GNU objdump i386 解析；窗口起點選自既有函式入口，遇內部跳轉目標超出窗口時需另定位反組譯，不能把未列入的分支稱不存在。
- E8 搜尋依 direct rel32 靜態匹配（可能偽陽性），只屬候選來源，不包含 indirect/vtable/tailcall。
- PE raw vs flat 位址混淆應每次由原始 PE section header 檢查，絕不把本報告的局部核對推廣為整個反編譯索引皆正確。
- 本段不宣稱 Z/X/C/V 特定綁定、V 蓄氣、Z held 自動續段、queue/cancel 已閉合；亦不新增動作／伺服器規則或修改程式。
- GitHub 送交狀態以實際遠端 Commit+讀回為準；本檔在本機完成不等於已提交。