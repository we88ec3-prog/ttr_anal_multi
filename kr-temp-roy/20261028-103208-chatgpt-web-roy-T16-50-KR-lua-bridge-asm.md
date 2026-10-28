# T16-50 — KR Lua loader／具名呼叫原生機器碼與協程邊界

- 研究時間：2026-10-28；研究者 chatgpt-web roy；KR T16 only。
- 原始 KR BIN：12472320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- 原始 EXE：SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`；本批次未啟動或修改檔案。
- 來源優先：本機原始 BIN/PE、已核對的 GitHub main 和 T16-45～48。
- 注意：以下機器碼中的函式語意是有限範圍判斷；沒有 server source/封包便不宣稱 server 端任務狀態。

## 核查方法

以原生 PE header 映射 VA 至 raw，以 `objdump -D -b binary -m i386` 對切片反組譯；每一小段僅為局部反組譯，**不可宣稱已完整解析函式 CFG**。下列是直接 bytes，不是 AI 生成的函式偽碼。

### `0x006F4A50`（raw 0x2F3E50，.text）

```asm
006f4a50 <.data>:
  6f4a50:	55                   	push   ebp
  6f4a51:	8b ec                	mov    ebp,esp
  6f4a53:	83 e4 f8             	and    esp,0xfffffff8
  6f4a56:	81 ec 2c 02 00 00    	sub    esp,0x22c
  6f4a5c:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6f4a61:	33 c4                	xor    eax,esp
  6f4a63:	89 84 24 28 02 00 00 	mov    DWORD PTR [esp+0x228],eax
  6f4a6a:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6f4a6d:	53                   	push   ebx
  6f4a6e:	56                   	push   esi
  6f4a6f:	8d 54 24 2c          	lea    edx,[esp+0x2c]
  6f4a73:	57                   	push   edi
  6f4a74:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  6f4a78:	2b d0                	sub    edx,eax
  6f4a7a:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  6f4a80:	8a 08                	mov    cl,BYTE PTR [eax]
  6f4a82:	88 0c 02             	mov    BYTE PTR [edx+eax*1],cl
  6f4a85:	40                   	inc    eax
  6f4a86:	84 c9                	test   cl,cl
  6f4a88:	75 f6                	jne    0x6f4a80
  6f4a8a:	8d 54 24 30          	lea    edx,[esp+0x30]
  6f4a8e:	68 e0 d1 be 00       	push   0xbed1e0
  6f4a93:	52                   	push   edx
  6f4a94:	be 01 00 00 00       	mov    esi,0x1
  6f4a99:	e8 d2 fc 01 00       	call   0x714770
  6f4a9e:	8b f8                	mov    edi,eax
  6f4aa0:	83 c4 08             	add    esp,0x8
  6f4aa3:	85 ff                	test   edi,edi
  6f4aa5:	0f 84 24 01 00 00    	je     0x6f4bcf
  6f4aab:	8b 07                	mov    eax,DWORD PTR [edi]
  6f4aad:	8b 50 2c             	mov    edx,DWORD PTR [eax+0x2c]
  6f4ab0:	8b cf                	mov    ecx,edi
  6f4ab2:	ff d2                	call   edx
  6f4ab4:	8b f0                	mov    esi,eax
  6f4ab6:	8d 46 01             	lea    eax,[esi+0x1]
  6f4ab9:	50                   	push   eax
  6f4aba:	e8 7e 91 18 00       	call   0x87dc3d
  6f4abf:	8b 17                	mov    edx,DWORD PTR [edi]
  6f4ac1:	83 c4 04             	add    esp,0x4
  6f4ac4:	8b d8                	mov    ebx,eax
  6f4ac6:	8b 42 38             	mov    eax,DWORD PTR [edx+0x38]
  6f4ac9:	56                   	push   esi
  6f4aca:	8b cf                	mov    ecx,edi
  6f4acc:	ff d0                	call   eax
  6f4ace:	50                   	push   eax
  6f4acf:	53                   	push   ebx
  6f4ad0:	e8 fb 90 1a 00       	call   0x89dbd0
  6f4ad5:	c6 04 1e 00          	mov    BYTE PTR [esi+ebx*1],0x0
  6f4ad9:	8b 17                	mov    edx,DWORD PTR [edi]
  6f4adb:	8b 42 2c             	mov    eax,DWORD PTR [edx+0x2c]
  6f4ade:	83 c4 0c             	add    esp,0xc
  6f4ae1:	8b cf                	mov    ecx,edi
  6f4ae3:	ff d0                	call   eax
  6f4ae5:	83 f8 03             	cmp    eax,0x3
  6f4ae8:	72 48                	jb     0x6f4b32
  6f4aea:	80 3b ef             	cmp    BYTE PTR [ebx],0xef
  6f4aed:	75 43                	jne    0x6f4b32
  6f4aef:	80 7b 01 bb          	cmp    BYTE PTR [ebx+0x1],0xbb
  6f4af3:	75 3d                	jne    0x6f4b32
  6f4af5:	80 7b 02 bf          	cmp    BYTE PTR [ebx+0x2],0xbf
  6f4af9:	75 37                	jne    0x6f4b32
  6f4afb:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  6f4aff:	8b 16                	mov    edx,DWORD PTR [esi]
  6f4b01:	83 c0 fd             	add    eax,0xfffffffd
```

### `0x006F4DD0`（raw 0x2F41D0，.text）

```asm
006f4dd0 <.data>:
  6f4dd0:	55                   	push   ebp
  6f4dd1:	8b ec                	mov    ebp,esp
  6f4dd3:	83 e4 f8             	and    esp,0xfffffff8
  6f4dd6:	83 ec 14             	sub    esp,0x14
  6f4dd9:	53                   	push   ebx
  6f4dda:	56                   	push   esi
  6f4ddb:	57                   	push   edi
  6f4ddc:	8b f8                	mov    edi,eax
  6f4dde:	8b 37                	mov    esi,DWORD PTR [edi]
  6f4de0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6f4de3:	8d 5e 48             	lea    ebx,[esi+0x48]
  6f4de6:	8d 48 01             	lea    ecx,[eax+0x1]
  6f4de9:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  6f4df0:	8a 10                	mov    dl,BYTE PTR [eax]
  6f4df2:	40                   	inc    eax
  6f4df3:	84 d2                	test   dl,dl
  6f4df5:	75 f9                	jne    0x6f4df0
  6f4df7:	2b c1                	sub    eax,ecx
  6f4df9:	50                   	push   eax
  6f4dfa:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6f4dfd:	50                   	push   eax
  6f4dfe:	56                   	push   esi
  6f4dff:	e8 6c 9e 00 00       	call   0x6fec70
  6f4e04:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  6f4e07:	83 c4 0c             	add    esp,0xc
  6f4e0a:	51                   	push   ecx
  6f4e0b:	8d 54 24 14          	lea    edx,[esp+0x14]
  6f4e0f:	52                   	push   edx
  6f4e10:	53                   	push   ebx
  6f4e11:	56                   	push   esi
  6f4e12:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  6f4e16:	c7 44 24 28 04 00 00 	mov    DWORD PTR [esp+0x28],0x4
  6f4e1d:	00 
  6f4e1e:	e8 2d 6a 00 00       	call   0x6fb850
  6f4e23:	bb 10 00 00 00       	mov    ebx,0x10
  6f4e28:	01 5e 08             	add    DWORD PTR [esi+0x8],ebx
  6f4e2b:	8b 07                	mov    eax,DWORD PTR [edi]
  6f4e2d:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  6f4e30:	2b c3                	sub    eax,ebx
  6f4e32:	83 c4 10             	add    esp,0x10
  6f4e35:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  6f4e3a:	0f 84 b5 00 00 00    	je     0x6f4ef5
  6f4e40:	83 78 08 06          	cmp    DWORD PTR [eax+0x8],0x6
  6f4e44:	0f 85 ab 00 00 00    	jne    0x6f4ef5
  6f4e4a:	8b 55 10             	mov    edx,DWORD PTR [ebp+0x10]
  6f4e4d:	8d 45 14             	lea    eax,[ebp+0x14]
  6f4e50:	50                   	push   eax
  6f4e51:	57                   	push   edi
  6f4e52:	e8 79 fe ff ff       	call   0x6f4cd0
  6f4e57:	8b 37                	mov    esi,DWORD PTR [edi]
  6f4e59:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  6f4e5c:	8d 48 01             	lea    ecx,[eax+0x1]
  6f4e5f:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  6f4e62:	c1 e1 04             	shl    ecx,0x4
  6f4e65:	2b c1                	sub    eax,ecx
  6f4e67:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  6f4e6b:	2b 46 20             	sub    eax,DWORD PTR [esi+0x20]
  6f4e6e:	8d 54 24 10          	lea    edx,[esp+0x10]
  6f4e72:	50                   	push   eax
  6f4e73:	52                   	push   edx
  6f4e74:	68 50 5a 6f 00       	push   0x6f5a50
  6f4e79:	33 d2                	xor    edx,edx
  6f4e7b:	8b c6                	mov    eax,esi
  6f4e7d:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  6f4e81:	e8                   	.byte 0xe8
  6f4e82:	ea                   	.byte 0xea
  6f4e83:	98                   	cwde
```

### `0x004A89C0`（raw 0xA7DC0，.text）

```asm
004a89c0 <.data>:
  4a89c0:	55                   	push   ebp
  4a89c1:	8b ec                	mov    ebp,esp
  4a89c3:	6a ff                	push   0xffffffff
  4a89c5:	68 7e a4 93 00       	push   0x93a47e
  4a89ca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a89d0:	50                   	push   eax
  4a89d1:	57                   	push   edi
  4a89d2:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a89d7:	33 c5                	xor    eax,ebp
  4a89d9:	50                   	push   eax
  4a89da:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a89dd:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a89e3:	8d 7e 14             	lea    edi,[esi+0x14]
  4a89e6:	c7 05 a0 a7 fb 00 00 	mov    DWORD PTR ds:0xfba7a0,0x0
  4a89ed:	00 00 00 
  4a89f0:	e8 2b 8a 3a 00       	call   0x851420
  4a89f5:	f6 05 54 73 fb 00 01 	test   BYTE PTR ds:0xfb7354,0x1
  4a89fc:	75 27                	jne    0x4a8a25
  4a89fe:	83 0d 54 73 fb 00 01 	or     DWORD PTR ds:0xfb7354,0x1
  4a8a05:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4a8a0c:	e8 bf a9 0a 00       	call   0x5533d0
  4a8a11:	68 00 d1 bc 00       	push   0xbcd100
  4a8a16:	e8 ff 98 3e 00       	call   0x89231a
  4a8a1b:	83 c4 04             	add    esp,0x4
  4a8a1e:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  4a8a25:	c7 05 b4 73 fb 00 01 	mov    DWORD PTR ds:0xfb73b4,0x1
  4a8a2c:	00 00 00 
  4a8a2f:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4a8a31:	68 7c 68 c0 00       	push   0xc0687c
  4a8a36:	e8 15 c0 24 00       	call   0x6f4a50
  4a8a3b:	8b 06                	mov    eax,DWORD PTR [esi]
  4a8a3d:	6a 00                	push   0x0
  4a8a3f:	6a 00                	push   0x0
  4a8a41:	68 94 68 c0 00       	push   0xc06894
  4a8a46:	e8 85 c3 24 00       	call   0x6f4dd0
  4a8a4b:	83 c4 0c             	add    esp,0xc
  4a8a4e:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a8a51:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a8a58:	59                   	pop    ecx
  4a8a59:	5f                   	pop    edi
  4a8a5a:	8b e5                	mov    esp,ebp
  4a8a5c:	5d                   	pop    ebp
  4a8a5d:	c3                   	ret
  4a8a5e:	cc                   	int3
  4a8a5f:	cc                   	int3
  4a8a60:	55                   	push   ebp
  4a8a61:	8b ec                	mov    ebp,esp
  4a8a63:	6a ff                	push   0xffffffff
  4a8a65:	68 4c a4 93 00       	push   0x93a44c
  4a8a6a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a8a70:	50                   	push   eax
  4a8a71:	83 ec 08             	sub    esp,0x8
```

### `0x004A8A60`（raw 0xA7E60，.text）

```asm
004a8a60 <.data>:
  4a8a60:	55                   	push   ebp
  4a8a61:	8b ec                	mov    ebp,esp
  4a8a63:	6a ff                	push   0xffffffff
  4a8a65:	68 4c a4 93 00       	push   0x93a44c
  4a8a6a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4a8a70:	50                   	push   eax
  4a8a71:	83 ec 08             	sub    esp,0x8
  4a8a74:	53                   	push   ebx
  4a8a75:	57                   	push   edi
  4a8a76:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4a8a7b:	33 c5                	xor    eax,ebp
  4a8a7d:	50                   	push   eax
  4a8a7e:	8d 45 f4             	lea    eax,[ebp-0xc]
  4a8a81:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4a8a87:	8d 7e 04             	lea    edi,[esi+0x4]
  4a8a8a:	c7 05 a0 a7 fb 00 00 	mov    DWORD PTR ds:0xfba7a0,0x0
  4a8a91:	00 00 00 
  4a8a94:	e8 b7 ad 37 00       	call   0x823850
  4a8a99:	8d 7e 14             	lea    edi,[esi+0x14]
  4a8a9c:	e8 7f 89 3a 00       	call   0x851420
  4a8aa1:	bb 01 00 00 00       	mov    ebx,0x1
  4a8aa6:	83 cf ff             	or     edi,0xffffffff
  4a8aa9:	84 1d 54 73 fb 00    	test   BYTE PTR ds:0xfb7354,bl
  4a8aaf:	75 22                	jne    0x4a8ad3
  4a8ab1:	09 1d 54 73 fb 00    	or     DWORD PTR ds:0xfb7354,ebx
  4a8ab7:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4a8abe:	e8 0d a9 0a 00       	call   0x5533d0
  4a8ac3:	68 00 d1 bc 00       	push   0xbcd100
  4a8ac8:	e8 4d 98 3e 00       	call   0x89231a
  4a8acd:	83 c4 04             	add    esp,0x4
  4a8ad0:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4a8ad3:	89 1d b4 73 fb 00    	mov    DWORD PTR ds:0xfb73b4,ebx
  4a8ad9:	84 1d d4 ad fa 00    	test   BYTE PTR ds:0xfaadd4,bl
  4a8adf:	75 1e                	jne    0x4a8aff
  4a8ae1:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
  4a8ae7:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  4a8aea:	e8 91 e9 0d 00       	call   0x587480
  4a8aef:	68 c0 cc bc 00       	push   0xbcccc0
  4a8af4:	e8 21 98 3e 00       	call   0x89231a
  4a8af9:	83 c4 04             	add    esp,0x4
  4a8afc:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  4a8aff:	b8 0f 00 00 00       	mov    eax,0xf
  4a8b04:	39 05 ec ad fa 00    	cmp    DWORD PTR ds:0xfaadec,eax
  4a8b0a:	74 07                	je     0x4a8b13
  4a8b0c:	a3 f0 ad fa 00       	mov    ds:0xfaadf0,eax
  4a8b11:	eb 05                	jmp    0x4a8b18
  4a8b13:	e8                   	.byte 0xe8
```

## 關係與限制

- `0x006F4DD0` 可觀察到由 `[ebp+8]` 取得 NUL terminated string，計算長度後經 `0x006FEC70`、`0x006FB850` 等傳遞；這支援**具名字串與 Lua VM 相關實作候選**，不證明該文字等於 Quest16 的完成事件。
- `0x004A89C0` 與 `0x004A8A60` 是前段已知 Synopsis/Tutorial 入口；上述 bytes 中存在 SEH prologue、初始化與條件旗標。這些旗標不能沒資料流就當作 server quest flags。
- Lua 5.1 `TutorialMain` proto8 已確認經 `t_executeCoFunction(Tutorial_Part1)`，再在 local coroutine 結束後呼叫 `Tutorial_Part2`。從 Lua 到 C++ bridge、request opcode、server ACK 三者仍是**不同驗證層**。
- 不能將 `0x006F4DD0` 稱為 Quest business handler；下段追 Quest XML 的 table reader，以明確界定 client cache 與權威進度。