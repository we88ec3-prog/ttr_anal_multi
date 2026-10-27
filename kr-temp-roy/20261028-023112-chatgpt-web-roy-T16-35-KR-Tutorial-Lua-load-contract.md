# T16-35 — Lua 腳本讀取與具名函式分派之錯誤／參數路徑

- 原始研究時間（Asia/Taipei）：20261028-023112
- Source: KR `Tartaros.bin`，唯讀靜態分析，bytes=`12472320`，SHA256=`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- GitHub 起始基線：`0de4fe39719a83f38a003af8efeed6b5c9b20f90`（研究啟動時核對）
- 本段主題：Lua 腳本讀取與具名函式分派之錯誤／參數路徑
- 界線：可確定的只有原生機器碼與本段直接解析之位址／跳躍；**不宣稱**任何原版任務 ID、NPC、完成條件、封包權威或 Lua/XML 實體內容。
- 研究方法：`objdump -D -Mintel -j .text` 依 VA 擷取原始 bytes；另外從 `.text` 扫描 `E8 rel32` 作交叉參照候選，僅經指令對齊與上下文核對後方可作控制流程證據。

## 1. 可重現基線與 PE 映射

| section | VA 起點 | file offset | 限制 |
|---|---|---|---|
| .text | `0x00401000` | `0x400` | 指令與常數候選 |
| .rdata | `0x00BD2000` | `0x007D0600` | 字串不是語義證據 |
| .data | `0x00D61000` | `0x0095E800` | static image ≠ runtime field value |

## 2. 研究範圍與函式邊界

本段截取下列 **位址視窗**，它們不必然等於完整函式；需以 prologue、返回路徑及多入口參照重新界定。總計 351 行反組譯輸出。

| start | stop (exclusive) | raw start | direct E8 candidates to start |
|---|---|---|---|
| `0x006F4A50` | `0x006F4C40` | `0x2F3E50` | `0x0048B11D`, `0x0048B12C`, `0x0048B13B`, `0x0048CA11`, `0x0048CA4D`, `0x004A89B6`, `0x004A8A36`, `0x004A8B64`, `0x0055D7C2`, `0x00560796`, `0x005607A2`, `0x005607AE` |
| `0x006F4DD0` | `0x006F4F90` | `0x2F41D0` | `0x004A8A46`, `0x004A8B74`, `0x005615D8` |

**注意：** raw `E8` 比對可能掃到指令中間；不得把表格所有候選自動計為真實 caller。`call [reg]`、vtable 呼叫亦不受 raw E8 掃描覆蓋。

## 3. Native assembly evidence

### `0x006F4A50` .. `0x006F4C40`

```asm
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
  6f4b04:	50                   	push   eax
  6f4b05:	8d 4b 03             	lea    ecx,[ebx+0x3]
  6f4b08:	51                   	push   ecx
  6f4b09:	33 c0                	xor    eax,eax
  6f4b0b:	e8 00 26 00 00       	call   0x6f7110
  6f4b10:	83 c4 08             	add    esp,0x8
  6f4b13:	85 c0                	test   eax,eax
  6f4b15:	0f 85 9d 00 00 00    	jne    0x6f4bb8
  6f4b1b:	8b 36                	mov    esi,DWORD PTR [esi]
  6f4b1d:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  6f4b20:	83 e8 10             	sub    eax,0x10
  6f4b23:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  6f4b27:	2b 46 20             	sub    eax,DWORD PTR [esi+0x20]
  6f4b2a:	8d 54 24 10          	lea    edx,[esp+0x10]
  6f4b2e:	50                   	push   eax
  6f4b2f:	52                   	push   edx
  6f4b30:	eb 57                	jmp    0x6f4b89
  6f4b32:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  6f4b36:	8b 0e                	mov    ecx,DWORD PTR [esi]
  6f4b38:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  6f4b3c:	8d 44 24 10          	lea    eax,[esp+0x10]
  6f4b40:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  6f4b44:	33 c0                	xor    eax,eax
  6f4b46:	89 4c 24 2c          	mov    DWORD PTR [esp+0x2c],ecx
  6f4b4a:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  6f4b4e:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  6f4b52:	51                   	push   ecx
  6f4b53:	b9 00 27 c4 00       	mov    ecx,0xc42700
  6f4b58:	8d 44 24 20          	lea    eax,[esp+0x20]
  6f4b5c:	89 5c 24 14          	mov    DWORD PTR [esp+0x14],ebx
  6f4b60:	c7 44 24 28 e0 70 6f 	mov    DWORD PTR [esp+0x28],0x6f70e0
  6f4b67:	00 
  6f4b68:	e8 23 9e 00 00       	call   0x6fe990
  6f4b6d:	83 c4 04             	add    esp,0x4
  6f4b70:	85 c0                	test   eax,eax
  6f4b72:	75 44                	jne    0x6f4bb8
  6f4b74:	8b 36                	mov    esi,DWORD PTR [esi]
  6f4b76:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  6f4b79:	83 e8 10             	sub    eax,0x10
  6f4b7c:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  6f4b80:	2b 46 20             	sub    eax,DWORD PTR [esi+0x20]
  6f4b83:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  6f4b87:	50                   	push   eax
  6f4b88:	51                   	push   ecx
  6f4b89:	68 50 5a 6f 00       	push   0x6f5a50
  6f4b8e:	33 d2                	xor    edx,edx
  6f4b90:	8b c6                	mov    eax,esi
  6f4b92:	c7 44 24 20 ff ff ff 	mov    DWORD PTR [esp+0x20],0xffffffff
  6f4b99:	ff 
  6f4b9a:	e8 d1 9b 00 00       	call   0x6fe770
  6f4b9f:	8b 4e 14             	mov    ecx,DWORD PTR [esi+0x14]
  6f4ba2:	8b 76 08             	mov    esi,DWORD PTR [esi+0x8]
  6f4ba5:	83 c4 0c             	add    esp,0xc
  6f4ba8:	3b 71 08             	cmp    esi,DWORD PTR [ecx+0x8]
  6f4bab:	72 03                	jb     0x6f4bb0
  6f4bad:	89 71 08             	mov    DWORD PTR [ecx+0x8],esi
  6f4bb0:	85 c0                	test   eax,eax
  6f4bb2:	75 04                	jne    0x6f4bb8
  6f4bb4:	33 f6                	xor    esi,esi
  6f4bb6:	eb 05                	jmp    0x6f4bbd
  6f4bb8:	be 01 00 00 00       	mov    esi,0x1
  6f4bbd:	8b 17                	mov    edx,DWORD PTR [edi]
  6f4bbf:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  6f4bc2:	8b cf                	mov    ecx,edi
  6f4bc4:	ff d0                	call   eax
  6f4bc6:	53                   	push   ebx
  6f4bc7:	e8 71 d1 19 00       	call   0x891d3d
  6f4bcc:	83 c4 04             	add    esp,0x4
  6f4bcf:	8d 4c 24 30          	lea    ecx,[esp+0x30]
  6f4bd3:	51                   	push   ecx
  6f4bd4:	8d 94 24 34 01 00 00 	lea    edx,[esp+0x134]
  6f4bdb:	68 9c 26 c4 00       	push   0xc4269c
  6f4be0:	52                   	push   edx
  6f4be1:	e8 49 df 19 00       	call   0x892b2f
  6f4be6:	83 c4 0c             	add    esp,0xc
  6f4be9:	85 f6                	test   esi,esi
  6f4beb:	74 12                	je     0x6f4bff
  6f4bed:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  6f4bf1:	8d 84 24 30 01 00 00 	lea    eax,[esp+0x130]
  6f4bf8:	50                   	push   eax
  6f4bf9:	51                   	push   ecx
  6f4bfa:	e8 a1 fb ff ff       	call   0x6f47a0
  6f4bff:	8b 8c 24 34 02 00 00 	mov    ecx,DWORD PTR [esp+0x234]
  6f4c06:	5f                   	pop    edi
  6f4c07:	8b c6                	mov    eax,esi
  6f4c09:	5e                   	pop    esi
  6f4c0a:	5b                   	pop    ebx
  6f4c0b:	33 cc                	xor    ecx,esp
  6f4c0d:	e8 ef c3 19 00       	call   0x891001
  6f4c12:	8b e5                	mov    esp,ebp
  6f4c14:	5d                   	pop    ebp
  6f4c15:	c2 04 00             	ret    0x4
  6f4c18:	cc                   	int3
  6f4c19:	cc                   	int3
  6f4c1a:	cc                   	int3
  6f4c1b:	cc                   	int3
  6f4c1c:	cc                   	int3
  6f4c1d:	cc                   	int3
  6f4c1e:	cc                   	int3
  6f4c1f:	cc                   	int3
  6f4c20:	55                   	push   ebp
  6f4c21:	8b ec                	mov    ebp,esp
  6f4c23:	83 e4 f8             	and    esp,0xfffffff8
  6f4c26:	83 ec 20             	sub    esp,0x20
  6f4c29:	8b 07                	mov    eax,DWORD PTR [edi]
  6f4c2b:	53                   	push   ebx
  6f4c2c:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  6f4c2f:	89 4c 24 0c          	mov    DWORD PTR [esp+0xc],ecx
  6f4c33:	33 c9                	xor    ecx,ecx
  6f4c35:	56                   	push   esi
  6f4c36:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  6f4c3a:	8d 54 24 0c          	lea    edx,[esp+0xc]
  6f4c3e:	89 4c            	mov    DWORD PTR [esp+0x14],ecx
```

### `0x006F4DD0` .. `0x006F4F90`

```asm
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
  6f4e81:	e8 ea 98 00 00       	call   0x6fe770
  6f4e86:	83 c4 0c             	add    esp,0xc
  6f4e89:	83 fb ff             	cmp    ebx,0xffffffff
  6f4e8c:	75 0e                	jne    0x6f4e9c
  6f4e8e:	8b 4e 14             	mov    ecx,DWORD PTR [esi+0x14]
  6f4e91:	8b 76 08             	mov    esi,DWORD PTR [esi+0x8]
  6f4e94:	3b 71 08             	cmp    esi,DWORD PTR [ecx+0x8]
  6f4e97:	72 03                	jb     0x6f4e9c
  6f4e99:	89 71 08             	mov    DWORD PTR [ecx+0x8],esi
  6f4e9c:	85 c0                	test   eax,eax
  6f4e9e:	0f 84 87 00 00 00    	je     0x6f4f2b
  6f4ea4:	8b 3f                	mov    edi,DWORD PTR [edi]
  6f4ea6:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  6f4ea9:	83 ee 10             	sub    esi,0x10
  6f4eac:	83 7e 08 04          	cmp    DWORD PTR [esi+0x8],0x4
  6f4eb0:	74 25                	je     0x6f4ed7
  6f4eb2:	e8 19 67 00 00       	call   0x6fb5d0
  6f4eb7:	85 c0                	test   eax,eax
  6f4eb9:	75 04                	jne    0x6f4ebf
  6f4ebb:	33 f6                	xor    esi,esi
  6f4ebd:	eb 1d                	jmp    0x6f4edc
  6f4ebf:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  6f4ec2:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  6f4ec5:	3b 48 40             	cmp    ecx,DWORD PTR [eax+0x40]
  6f4ec8:	72 07                	jb     0x6f4ed1
  6f4eca:	8b c7                	mov    eax,edi
  6f4ecc:	e8 cf 64 00 00       	call   0x6fb3a0
  6f4ed1:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  6f4ed4:	83 ee 10             	sub    esi,0x10
  6f4ed7:	8b 36                	mov    esi,DWORD PTR [esi]
  6f4ed9:	83 c6 10             	add    esi,0x10
  6f4edc:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  6f4edf:	56                   	push   esi
  6f4ee0:	52                   	push   edx
  6f4ee1:	68 78 26 c4 00       	push   0xc42678
  6f4ee6:	e8 d2 e1 19 00       	call   0x8930bd
  6f4eeb:	83 c4 0c             	add    esp,0xc
  6f4eee:	5f                   	pop    edi
  6f4eef:	5e                   	pop    esi
  6f4ef0:	5b                   	pop    ebx
  6f4ef1:	8b e5                	mov    esp,ebp
  6f4ef3:	5d                   	pop    ebp
  6f4ef4:	c3                   	ret
  6f4ef5:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6f4ef8:	50                   	push   eax
  6f4ef9:	68 10 26 c4 00       	push   0xc42610
  6f4efe:	e8 ba e1 19 00       	call   0x8930bd
  6f4f03:	8b 07                	mov    eax,DWORD PTR [edi]
  6f4f05:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  6f4f08:	83 c4 08             	add    esp,0x8
  6f4f0b:	3b 48 0c             	cmp    ecx,DWORD PTR [eax+0xc]
  6f4f0e:	73 15                	jae    0x6f4f25
  6f4f10:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  6f4f13:	c7 42 08 00 00 00 00 	mov    DWORD PTR [edx+0x8],0x0
  6f4f1a:	01 58 08             	add    DWORD PTR [eax+0x8],ebx
  6f4f1d:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  6f4f20:	3b 48 0c             	cmp    ecx,DWORD PTR [eax+0xc]
  6f4f23:	72 eb                	jb     0x6f4f10
  6f4f25:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  6f4f28:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  6f4f2b:	5f                   	pop    edi
  6f4f2c:	5e                   	pop    esi
  6f4f2d:	5b                   	pop    ebx
  6f4f2e:	8b e5                	mov    esp,ebp
  6f4f30:	5d                   	pop    ebp
  6f4f31:	c3                   	ret
  6f4f32:	cc                   	int3
  6f4f33:	cc                   	int3
  6f4f34:	cc                   	int3
  6f4f35:	cc                   	int3
  6f4f36:	cc                   	int3
  6f4f37:	cc                   	int3
  6f4f38:	cc                   	int3
  6f4f39:	cc                   	int3
  6f4f3a:	cc                   	int3
  6f4f3b:	cc                   	int3
  6f4f3c:	cc                   	int3
  6f4f3d:	cc                   	int3
  6f4f3e:	cc                   	int3
  6f4f3f:	cc                   	int3
  6f4f40:	55                   	push   ebp
  6f4f41:	8b ec                	mov    ebp,esp
  6f4f43:	83 e4 f8             	and    esp,0xfffffff8
  6f4f46:	83 ec 0c             	sub    esp,0xc
  6f4f49:	53                   	push   ebx
  6f4f4a:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  6f4f4d:	56                   	push   esi
  6f4f4e:	57                   	push   edi
  6f4f4f:	8b f8                	mov    edi,eax
  6f4f51:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  6f4f54:	8b 37                	mov    esi,DWORD PTR [edi]
  6f4f56:	50                   	push   eax
  6f4f57:	e8 b4 05 00 00       	call   0x6f5510
  6f4f5c:	8b 37                	mov    esi,DWORD PTR [edi]
  6f4f5e:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  6f4f61:	8d 41 f0             	lea    eax,[ecx-0x10]
  6f4f64:	8b 49 e0             	mov    ecx,DWORD PTR [ecx-0x20]
  6f4f67:	83 c4 04             	add    esp,0x4
  6f4f6a:	e8 e1 4c 00 00       	call   0x6f9c50
  6f4f6f:	8b 10                	mov    edx,DWORD PTR [eax]
  6f4f71:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  6f4f74:	89 51 f0             	mov    DWORD PTR [ecx-0x10],edx
  6f4f77:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  6f4f7a:	89 51 f4             	mov    DWORD PTR [ecx-0xc],edx
  6f4f7d:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  6f4f80:	89 41 f8             	mov    DWORD PTR [ecx-0x8],eax
  6f4f83:	8b 0f                	mov    ecx,DWORD PTR [edi]
  6f4f85:	8b 41 08             	mov    eax,DWORD PTR [ecx+0x8]
  6f4f88:	83 e8 10             	sub    eax,0x10
  6f4f8b:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
```

## 4. 局部控制流程與資料流（指令級）

以下為本段出現的直接 call 指令節錄；**callee 的高階名稱均不自動確定**：

```asm
  6f4a99:	e8 d2 fc 01 00       	call   0x714770
  6f4ab2:	ff d2                	call   edx
  6f4aba:	e8 7e 91 18 00       	call   0x87dc3d
  6f4acc:	ff d0                	call   eax
  6f4ad0:	e8 fb 90 1a 00       	call   0x89dbd0
  6f4ae3:	ff d0                	call   eax
  6f4b0b:	e8 00 26 00 00       	call   0x6f7110
  6f4b68:	e8 23 9e 00 00       	call   0x6fe990
  6f4b9a:	e8 d1 9b 00 00       	call   0x6fe770
  6f4bc4:	ff d0                	call   eax
  6f4bc7:	e8 71 d1 19 00       	call   0x891d3d
  6f4be1:	e8 49 df 19 00       	call   0x892b2f
  6f4bfa:	e8 a1 fb ff ff       	call   0x6f47a0
  6f4c0d:	e8 ef c3 19 00       	call   0x891001
  6f4dff:	e8 6c 9e 00 00       	call   0x6fec70
  6f4e1e:	e8 2d 6a 00 00       	call   0x6fb850
  6f4e52:	e8 79 fe ff ff       	call   0x6f4cd0
  6f4e81:	e8 ea 98 00 00       	call   0x6fe770
  6f4eb2:	e8 19 67 00 00       	call   0x6fb5d0
  6f4ecc:	e8 cf 64 00 00       	call   0x6fb3a0
  6f4ee6:	e8 d2 e1 19 00       	call   0x8930bd
  6f4efe:	e8 ba e1 19 00       	call   0x8930bd
  6f4f57:	e8 b4 05 00 00       	call   0x6f5510
  6f4f6a:	e8 e1 4c 00 00       	call   0x6f9c50
```

比較、測試及分支位置（節錄）：

```asm
  6f4a86:	84 c9                	test   cl,cl
  6f4a88:	75 f6                	jne    0x6f4a80
  6f4aa3:	85 ff                	test   edi,edi
  6f4aa5:	0f 84 24 01 00 00    	je     0x6f4bcf
  6f4ae5:	83 f8 03             	cmp    eax,0x3
  6f4ae8:	72 48                	jb     0x6f4b32
  6f4aea:	80 3b ef             	cmp    BYTE PTR [ebx],0xef
  6f4aed:	75 43                	jne    0x6f4b32
  6f4aef:	80 7b 01 bb          	cmp    BYTE PTR [ebx+0x1],0xbb
  6f4af3:	75 3d                	jne    0x6f4b32
  6f4af5:	80 7b 02 bf          	cmp    BYTE PTR [ebx+0x2],0xbf
  6f4af9:	75 37                	jne    0x6f4b32
  6f4b13:	85 c0                	test   eax,eax
  6f4b15:	0f 85 9d 00 00 00    	jne    0x6f4bb8
  6f4b30:	eb 57                	jmp    0x6f4b89
  6f4b70:	85 c0                	test   eax,eax
  6f4b72:	75 44                	jne    0x6f4bb8
  6f4ba8:	3b 71 08             	cmp    esi,DWORD PTR [ecx+0x8]
  6f4bab:	72 03                	jb     0x6f4bb0
  6f4bb0:	85 c0                	test   eax,eax
  6f4bb2:	75 04                	jne    0x6f4bb8
  6f4bb6:	eb 05                	jmp    0x6f4bbd
  6f4be9:	85 f6                	test   esi,esi
  6f4beb:	74 12                	je     0x6f4bff
  6f4c15:	c2 04 00             	ret    0x4
  6f4df3:	84 d2                	test   dl,dl
  6f4df5:	75 f9                	jne    0x6f4df0
  6f4e35:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  6f4e3a:	0f 84 b5 00 00 00    	je     0x6f4ef5
  6f4e40:	83 78 08 06          	cmp    DWORD PTR [eax+0x8],0x6
```

### 最低限度的局部偽碼（語義不作確定）

```cpp
// Abstracted from instruction traces, not reconstructed source.
void candidate_native_path(State* opaque, Input* candidate) {
    // Calls and conditional transitions follow the literal assembly above.
    // Unknowns: field ownership, valid input domain, caller context, side effects.
    // Any quest step / success / tutorial flag semantics remain unknown.
}
```

## 5. T16 功能鏈驗收矩陣

| 驗證項 | 狀態 | 說明 |
|---|---|---|
| KR 映像版本與 VA 原生反組譯 | 原生已確認 | 本段實際读取 BIN 機器碼並附起訖區間 |
| 選定指令之直接 call / branch | 原生已確認（有界） | 詳見 assembly，非完整函式 call graph |
| 此路徑是否屬 Quest / Tutorial 的業務邏輯 | 部分確認／推測 | 依前批上下文選取；需要 event 與進度鏈封閉 |
| 伺服器權威任務 writer | 資訊缺失 | 未由本段地址鎖定 |
| 教學步驟及觸發旗標 | 資訊缺失 | 不能由腳本入口名稱倒推 |
| 教學完成後第一個主線 | 資訊缺失 | 無原生 quest/step ID |
| TC 版本函式對應 | 資訊缺失 | 本段只使用 KR BIN |
| 可玩性驗證 | 未測試 | 禁止將原生指令分析視為可玩 |

## 6. 跨 Task 分工與證據風險

- T02：封包 envelope／dispatcher 是其主責；T16 僅需任務業務欄位與事件結果。
- T03/T04：登入與既有角色是 T16 的輸入；不可臆造新角色教學初始值。
- T07/T14：關卡轉場／結算由其主責，T16 僅需其對進度的輸入事件。
- T15：持久化底層，T16 僅指定需要寫入或恢復之欄位（目前 unknown）。
- T08：實體行為僅作事件界面引用。

## 7. 延後本地資源（DEFERRED-LOCAL-RESOURCE）

| 來源 | 待本地分析交付的最小內容 | 阻塞語義 |
|---|---|---|
| `Event/TutorialMain.lua` | 函式定義／呼叫、步驟與事件線索、原檔 SHA | 教學節點序列／完成條件 |
| `Event/TutorialBase.lua` | 提供的 Lua API 清單及參數 | 客戶端教學行為 |
| `Table/QuestInfo.xml` | Quest/step ID 與前置條件及資料 schema | 主線入口／依賴 |
| `Table/QuestTalk.xml` | NPC／對話／任務 ID 關聯及 SHA | 交付與對話 |
| 原版伺服器任務資料與封包 | 任務業務欄位、接受／拒絕及重登資料 | 權威、儲存、恢復 |

以上列為延後，本批不要求、下載或臆造檔案。

## 8. 後續應查項目

1. 從本段已驗證的 branch / call 對應上游條件與下游 consumer；目標是可確認業務 writer，而非重複解析 CRT 或 container。
2. 比對 T16-1～T16-32 有界結論，釐清新發現是否真能跨越任務介面。
3. 有足夠原生來源前不將任何 `0x6`、Quest 顯示文字或本地補丁當作原版進度旗標。
4. 將原始資源缺口留待本地流程回填，下一段仍優先研究 BIN/EXE 可證實的路徑。

## 9. 提交狀態

本文件生成時為原始本地稿；是否已推 GitHub 以後續實際提交收據為準。