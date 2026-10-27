# T16-24 — T16 教學到主線的分派／資料來源驗收矩陣

- 本次產出時間：2026-10-28T02:09:39+08:00
- KR source: `Tartaros.bin`, SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`, 12472320 bytes
- 文件性質：BIN-first 界線驗證與局部 control-flow 研究；以下每個 asm 是本次直接 objdump 的原始輸出
- 基準：提交前再讀取 GitHub main；不宣稱任務完成閉環

## 研究目的與新結論
1. a client-side integer-key container lookup does not prove quest progress state。證據分級：局部程式碼已確認、任務業務語義未確認。
2. Lua call ABI plus XML parser is not yet an end-to-end authoritative quest state machine。證據分級：局部程式碼已確認、任務業務語義未確認。

## 函式／VA 範圍與直接反組譯資料

### VA `0x004AE860`–`0x004AE900`（43 條可解析行；原始 bytes 位於每行 instruction 欄）

```asm
  4ae860:	00 00                	add    BYTE PTR [eax],al
  4ae862:	00 e8                	add    al,ch
  4ae864:	08 11                	or     BYTE PTR [ecx],dl
  4ae866:	09 00                	or     DWORD PTR [eax],eax
  4ae868:	68 10 e8 bc 00       	push   0xbce810
  4ae86d:	e8 a8 3a 3e 00       	call   0x89231a
  4ae872:	83 c4 04             	add    esp,0x4
  4ae875:	89 b4 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],esi
  4ae87c:	0f b7 33             	movzx  esi,WORD PTR [ebx]
  4ae87f:	8d 54 24 14          	lea    edx,[esp+0x14]
  4ae883:	52                   	push   edx
  4ae884:	8d 44 24 44          	lea    eax,[esp+0x44]
  4ae888:	b9 dc 18 fe 00       	mov    ecx,0xfe18dc
  4ae88d:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  4ae891:	e8 2a 50 39 00       	call   0x8438c0
  4ae896:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
  4ae89a:	3b 0d e0 18 fe 00    	cmp    ecx,DWORD PTR ds:0xfe18e0
  4ae8a0:	74 2e                	je     0x4ae8d0
  4ae8a2:	8a 43 fd             	mov    al,BYTE PTR [ebx-0x3]
  4ae8a5:	88 44 24 44          	mov    BYTE PTR [esp+0x44],al
  4ae8a9:	8b 41 10             	mov    eax,DWORD PTR [ecx+0x10]
  4ae8ac:	8b 0d ec 18 fe 00    	mov    ecx,DWORD PTR ds:0xfe18ec
  4ae8b2:	89 44 24 4c          	mov    DWORD PTR [esp+0x4c],eax
  4ae8b6:	8d 44 24 44          	lea    eax,[esp+0x44]
  4ae8ba:	bf cc 18 fe 00       	mov    edi,0xfe18cc
  4ae8bf:	89 74 24 48          	mov    DWORD PTR [esp+0x48],esi
  4ae8c3:	89 4c 24 50          	mov    DWORD PTR [esp+0x50],ecx
  4ae8c7:	e8 d4 02 09 00       	call   0x53eba0
  4ae8cc:	8b 7c 24 1c          	mov    edi,DWORD PTR [esp+0x1c]
  4ae8d0:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  4ae8d4:	eb 41                	jmp    0x4ae917
  4ae8d6:	68 28 04 00 00       	push   0x428
  4ae8db:	e8 88 29 3e 00       	call   0x891268
  4ae8e0:	83 c4 04             	add    esp,0x4
  4ae8e3:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4ae8e7:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x7
  4ae8ee:	07 00 00 00 
  4ae8f2:	85 c0                	test   eax,eax
  4ae8f4:	74 08                	je     0x4ae8fe
  4ae8f6:	50                   	push   eax
  4ae8f7:	e8 64 27 02 00       	call   0x4d1060
  4ae8fc:	eb 02                	jmp    0x4ae900
  4ae8fe:	33 c0                	xor    eax,eax
```

### VA `0x0053FEB0`–`0x0053FFD0`（108 條可解析行；原始 bytes 位於每行 instruction 欄）

```asm
  53feb0:	55                   	push   ebp
  53feb1:	8b ec                	mov    ebp,esp
  53feb3:	51                   	push   ecx
  53feb4:	56                   	push   esi
  53feb5:	68 a0 f4 c0 00       	push   0xc0f4a0
  53feba:	e8 21 e4 1e 00       	call   0x72e2e0
  53febf:	8b f0                	mov    esi,eax
  53fec1:	85 f6                	test   esi,esi
  53fec3:	74 51                	je     0x53ff16
  53fec5:	57                   	push   edi
  53fec6:	8b 06                	mov    eax,DWORD PTR [esi]
  53fec8:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  53fecb:	8b ce                	mov    ecx,esi
  53fecd:	ff d2                	call   edx
  53fecf:	85 c0                	test   eax,eax
  53fed1:	74 3b                	je     0x53ff0e
  53fed3:	68 a8 f4 c0 00       	push   0xc0f4a8
  53fed8:	8d 78 44             	lea    edi,[eax+0x44]
  53fedb:	e8 c0 01 1f 00       	call   0x7300a0
  53fee0:	85 c0                	test   eax,eax
  53fee2:	74 1a                	je     0x53fefe
  53fee4:	83 c0 30             	add    eax,0x30
  53fee7:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  53feeb:	72 02                	jb     0x53feef
  53feed:	8b 00                	mov    eax,DWORD PTR [eax]
  53feef:	85 c0                	test   eax,eax
  53fef1:	74 0b                	je     0x53fefe
  53fef3:	50                   	push   eax
  53fef4:	e8 bb 18 35 00       	call   0x8917b4
  53fef9:	83 c4 04             	add    esp,0x4
  53fefc:	eb 02                	jmp    0x53ff00
  53fefe:	33 c0                	xor    eax,eax
  53ff00:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  53ff03:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  53ff06:	8d 45 fc             	lea    eax,[ebp-0x4]
  53ff09:	e8 72 87 f6 ff       	call   0x4a8680
  53ff0e:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  53ff11:	85 f6                	test   esi,esi
  53ff13:	75 b1                	jne    0x53fec6
  53ff15:	5f                   	pop    edi
  53ff16:	5e                   	pop    esi
  53ff17:	8b e5                	mov    esp,ebp
  53ff19:	5d                   	pop    ebp
  53ff1a:	c2 04 00             	ret    0x4
  53ff1d:	cc                   	int3
  53ff1e:	cc                   	int3
  53ff1f:	cc                   	int3
  53ff20:	55                   	push   ebp
  53ff21:	8b ec                	mov    ebp,esp
  53ff23:	51                   	push   ecx
  53ff24:	e8 74 29 35 00       	call   0x89289d
  53ff29:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  53ff2c:	db 45 fc             	fild   DWORD PTR [ebp-0x4]
  53ff2f:	db 45 08             	fild   DWORD PTR [ebp+0x8]
  53ff32:	dc 0d e0 57 c5 00    	fmul   QWORD PTR ds:0xc557e0
  53ff38:	de c9                	fmulp  st(1),st
  53ff3a:	e8 d1 ed 3b 00       	call   0x8fed10
  53ff3f:	8b e5                	mov    esp,ebp
  53ff41:	5d                   	pop    ebp
  53ff42:	c3                   	ret
  53ff43:	cc                   	int3
  53ff44:	cc                   	int3
  53ff45:	cc                   	int3
  53ff46:	cc                   	int3
  53ff47:	cc                   	int3
  53ff48:	cc                   	int3
  53ff49:	cc                   	int3
  53ff4a:	cc                   	int3
  53ff4b:	cc                   	int3
  53ff4c:	cc                   	int3
  53ff4d:	cc                   	int3
  53ff4e:	cc                   	int3
  53ff4f:	cc                   	int3
  53ff50:	55                   	push   ebp
  53ff51:	8b ec                	mov    ebp,esp
  53ff53:	83 e4 f8             	and    esp,0xfffffff8
  53ff56:	6a ff                	push   0xffffffff
  53ff58:	68 4a 78 94 00       	push   0x94784a
  53ff5d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  53ff63:	50                   	push   eax
  53ff64:	83 ec 14             	sub    esp,0x14
  53ff67:	53                   	push   ebx
  53ff68:	56                   	push   esi
  53ff69:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  53ff6e:	33 c4                	xor    eax,esp
  53ff70:	50                   	push   eax
  53ff71:	8d 44 24 20          	lea    eax,[esp+0x20]
  53ff75:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  53ff7b:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  53ff82:	75 29                	jne    0x53ffad
  53ff84:	83 0d b8 73 fb 00 01 	or     DWORD PTR ds:0xfb73b8,0x1
  53ff8b:	c7 44 24 28 00 00 00 	mov    DWORD PTR [esp+0x28],0x0
  53ff92:	00 
  53ff93:	e8 d8 01 02 00       	call   0x560170
  53ff98:	68 10 d1 bc 00       	push   0xbcd110
  53ff9d:	e8 78 23 35 00       	call   0x89231a
  53ffa2:	83 c4 04             	add    esp,0x4
  53ffa5:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  53ffac:	ff 
  53ffad:	83 3d e8 73 fb 00 00 	cmp    DWORD PTR ds:0xfb73e8,0x0
  53ffb4:	0f 85 25 02 00 00    	jne    0x5401df
  53ffba:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  53ffbd:	2b 07                	sub    eax,DWORD PTR [edi]
  53ffbf:	c1 f8 04             	sar    eax,0x4
  53ffc2:	85 c0                	test   eax,eax
  53ffc4:	0f 84 15 02 00 00    	je     0x5401df
  53ffca:	33 db                	xor    ebx,ebx
  53ffcc:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
```

### VA `0x006F4DD0`–`0x006F4F00`（111 條可解析行；原始 bytes 位於每行 instruction 欄）

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
  6f4efe:	e8 ba          	call   0x8930bd
```

## 有界 caller/callee 候選（僅本次觀察視窗中指令）

| 指令 VA | 操作 | 目標 |
|---|---|---|
| `0x4ae86d` | call | `0x89231a` |
| `0x4ae891` | call | `0x8438c0` |
| `0x4ae8c7` | call | `0x53eba0` |
| `0x4ae8d4` | jmp | `0x4ae917` |
| `0x4ae8db` | call | `0x891268` |
| `0x4ae8f7` | call | `0x4d1060` |
| `0x4ae8fc` | jmp | `0x4ae900` |
| `0x53feba` | call | `0x72e2e0` |
| `0x53fedb` | call | `0x7300a0` |
| `0x53fef4` | call | `0x8917b4` |
| `0x53fefc` | jmp | `0x53ff00` |
| `0x53ff09` | call | `0x4a8680` |
| `0x53ff24` | call | `0x89289d` |
| `0x53ff3a` | call | `0x8fed10` |
| `0x53ff93` | call | `0x560170` |
| `0x53ff9d` | call | `0x89231a` |
| `0x6f4dff` | call | `0x6fec70` |
| `0x6f4e1e` | call | `0x6fb850` |
| `0x6f4e52` | call | `0x6f4cd0` |
| `0x6f4e81` | call | `0x6fe770` |
| `0x6f4eb2` | call | `0x6fb5d0` |
| `0x6f4ebd` | jmp | `0x6f4edc` |
| `0x6f4ecc` | call | `0x6fb3a0` |
| `0x6f4ee6` | call | `0x8930bd` |
| `0x6f4efe` | call | `0x8930bd` |

## 資料流與局部偽碼（抽象表示；不冒充正式 class/function 名稱）

```cpp
// 每個 node/packet 的實際型別、生命週期、寫入者未證實；務必以下方 BIN 指令為準。
void native_window_observation_unknown(Context *ctx) {
    // Inspect the branch/call edges in the assembly windows above.
    // Do not map unknown payload to player quest-state without evidence.
}
```

## 證據政策及跨 Task 責任
- KR：直接唯讀解析原始 x86 PE32 BIN；不執行、不修改遊戲。任何位址均為 KR VA。
- T02 分派框架、T03 登入、T04 創角初始化、T07 場景、T14 勝敗結算、T15 保存機制仍為各自任務主責。T16 只研究任務業務語義與介面；不修改他人 owner/catalog。
- 原生已確認 = 對應 bytes / 指令確實存在；部分確認 = 控制流程尚未閉環；合理推測 = 待測；資訊缺失 = 無法取得資源或證據。不得把歷史 AI/fixture 或 `005F type6` 修補當原版事實。
- KR 任務 Lua/XML 正文未提供；TC 原生檔未提供，TC SHA 只使用 GitHub `shared/targets.json` 登記，不轉用 KR VA/ID/判斷。

## tutorial-node-matrix / early-mainline-flow / KR–TC 差異
| 流程節點 | KR 原生入口或資料線索 | 觸發條件 | 原版 server writer | 回覆／UI | 下一狀態 | TC 同項 |
|---|---|---|---|---|---|---|
| Tutorial 腳本路徑 | `Event/TutorialMain.lua` / `Tutorial_EntryPoint` | unknown | unknown | unknown | unknown | unknown |
| Synopsis | `Synopsis_EntryPoint` | unknown | unknown | unknown | unknown | unknown |
| Quest 定義 | `Table/QuestInfo.xml` 路徑 | unknown | unknown | unknown | unknown | unknown |
| NPC/對話候選 | `Table/QuestTalk.xml` 路徑 | unknown | unknown | unknown | unknown | unknown |
| 教學完成→首主線 | 未定位原生閉環 | unknown | unknown | unknown | unknown | unknown |

**重要反證：** 客戶端載入 Lua、索引 XML 或顯示 `QUEST_READY` 皆不足以斷定官方後端曾接受、寫入及持久化任務進度。TC 原生功能無法對照，不能以 KR 推定相同。

## source-inventory / evidence-level

| version | source | SHA / status | evidence |
|---|---|---|---|
| KR | Original BIN | `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91` | current direct bytes/assembly |
| KR | Lua/XML external content | 未取得 | 路徑引用不代表原始檔內容存在 |
| KR | historical notification/fixture | GitHub 索引/前批技術筆記 | 僅線索；未據此推定 native Quest 規則 |
| TC | `shared/targets.json` 中候選映像 | `f181071094286fe4e72cb12863edbe7e83f8fa825cfb65604143cb53ae2cd873`（未直接驗證） | 不得跨版套地址 |

## cross-task-interfaces / acceptance-matrix

| 接口 / 驗收 | 本段結論 | 待 T16 查核 |
|---|---|---|
| T02 → T16 packet | frame/dispatch 仍需業務鍵值與 payload 證明 | quest message command、原版 payload schema |
| T03/T04 → T16 | 已有角色為輸入，不重做角色初值 | tutorial state source and conditions |
| T07/T14 → T16 | 任務對關卡結果的消費未驗證 | result event→quest writer |
| T15 ↔ T16 | 原版持久化未驗證 | per-character flags and relogged snapshot |
| KR 原生技術分析 | 上列指定窗口機器碼直接確認 | 延伸 CFG 和呼叫者映射 |
| 原版端到端教學可玩 | 未測試、不可聲稱完成 | 封包重放與後端原版證據 |

## 未解項目與下一步

- 沿分派表找到確定的 quest command/handler，再核對 packet 欄位來源、長度和狀態寫入；不能用 QUEST READY 字串推定。
- 取得原版 Lua/XML 真實內容，抽取教學節點／QuestInfo ID 與 NPC、對話／前置條件。
- 確認 server acknowledgement → client field consumer → next progression，依任務記錄 writer/reader；必要時引用 T02/T14/T15 已登記主責。
- 如果該片段僅反映共用初始化/容器，保留非任務反證，不繼續無界泛化。

## GitHub 狀態
本原稿於提交之前生成；實際遠端 commit SHA 以提交後驗證結果為準。
