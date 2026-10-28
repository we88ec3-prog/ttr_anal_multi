# KR T16-58 — RequestStartScenario Lua 註冊、native callback 與參數處理鏈

- 日期：2026-10-28T10:58:06.857560+08:00；研究者：`chatgpt-web roy`，KR T16 only。
- 唯讀來源：`Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。PE32/i386 `.text` VA `0x401000`，raw `0x400`；`.rdata` VA `0xBD2000`，raw `0x7D0600`；`.data` VA `0xD61000`，raw `0x95E800`。
- GitHub repo：https://github.com/we88ec3-prog/ttr_anal_multi，前段 T16-53～56 已提交；此批不修改其他 Task／catalog／owner，不研究 TC；不啟動程式。
- disassembly：`objdump -D -Mintel --start-address=... --stop-address=... Tartaros.bin`；局部片段不保證全函式 CFG，但已按已知入口與連續指令核對。

## 原生確認的註冊鏈
- 在 `0x004AB8F8` 有 `push 0x00D6AD68`（`RequestStartScenario` 字串）；接著 `call 0x006F5510`；`push 0`、`push 0x004AC9E0`、`call 0x006F55B0`；之後以 `eax = -3` 呼叫 `0x006F57F0`，結尾清理 `esp += 0x0c`。
- `0x004AC9E0` 的 callback 將 `[ebp+8]` 初始化為本地 `0x18` byte 概念的值物件、取得 `[0xFE187C]`，再 `call 0x004ACB70`；回傳 `eax=1`。
- `0x004ACB70` 是 callback 參數值的搬運／型別判定（型別 3/4），其後 `call [ebp-0x18]` 是**間接呼叫**，不應未追地址就宣稱網路 send。它檢查 `[edi+8]` 的參數 tag，並在 `0x6FB5D0`、`0x6FB3A0` 等本地分支之後選取傳入值。
- `TutorialMain.lua` proto6 含同名 `RequestStartScenario` 常數及 `IsScenarioEnded` polling（T16-46），但需要先對 Lua 常數參數與本 callback 接線做逐指令還原；**尚無 scenario14 實際傳入與勝利 ACK 證據**。

## assembly 原件

VA 0x004AB8F8 raw 0xAACF8 bytes: 68 68 ad d6 00 e8 0e 9c 24 00 8b 37 83 c4 04 6a 00 68 e0 c9 4a 00 e8 9d 9c 24 00 8b 0f 51 b8 fd
```asm
004ab8f0 <.text+0xaa8f0>:
  4ab8f0:	8b 3d 00 18 fe 00    	mov    edi,DWORD PTR ds:0xfe1800
  4ab8f6:	8b 37                	mov    esi,DWORD PTR [edi]
  4ab8f8:	68 68 ad d6 00       	push   0xd6ad68
  4ab8fd:	e8 0e 9c 24 00       	call   0x6f5510
  4ab902:	8b 37                	mov    esi,DWORD PTR [edi]
  4ab904:	83 c4 04             	add    esp,0x4
  4ab907:	6a 00                	push   0x0
  4ab909:	68 e0 c9 4a 00       	push   0x4ac9e0
  4ab90e:	e8 9d 9c 24 00       	call   0x6f55b0
  4ab913:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4ab915:	51                   	push   ecx
  4ab916:	b8 fd ff ff ff       	mov    eax,0xfffffffd
  4ab91b:	e8 d0 9e 24 00       	call   0x6f57f0
  4ab920:	8b 15 00 18 fe 00    	mov    edx,DWORD PTR ds:0xfe1800
  4ab926:	8b 02                	mov    eax,DWORD PTR [edx]
  4ab928:	83 c4 0c             	add    esp,0xc
  4ab92b:	83 40 08 f0          	add    DWORD PTR [eax+0x8],0xfffffff0
  4ab92f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4ab932:	5f                   	pop    edi
  4ab933:	5e                   	pop    esi
  4ab934:	5b                   	pop    ebx
  4ab935:	5d                   	pop    ebp
  4ab936:	c2 04 00             	ret    0x4
```

VA 0x004AC9E0 raw 0xABDE0 bytes: 55 8b ec 6a ff 68 c8 83 93 00 64 a1 00 00 00 00 50 83 ec 0c a1 20 1f d6 00 33 c5 50 8d 45 f4 64
```asm
004ac9e0 <.text+0xab9e0>:
  4ac9e0:	55                   	push   ebp
  4ac9e1:	8b ec                	mov    ebp,esp
  4ac9e3:	6a ff                	push   0xffffffff
  4ac9e5:	68 c8 83 93 00       	push   0x9383c8
  4ac9ea:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4ac9f0:	50                   	push   eax
  4ac9f1:	83 ec 0c             	sub    esp,0xc
  4ac9f4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4ac9f9:	33 c5                	xor    eax,ebp
  4ac9fb:	50                   	push   eax
  4ac9fc:	8d 45 f4             	lea    eax,[ebp-0xc]
  4ac9ff:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4aca05:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4aca08:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4aca0b:	33 c0                	xor    eax,eax
  4aca0d:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  4aca10:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4aca13:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4aca16:	8b 0d 7c 18 fe 00    	mov    ecx,DWORD PTR ds:0xfe187c
  4aca1c:	51                   	push   ecx
  4aca1d:	8d 45 e8             	lea    eax,[ebp-0x18]
  4aca20:	e8 4b 01 00 00       	call   0x4acb70
  4aca25:	83 c4 04             	add    esp,0x4
  4aca28:	b8 01 00 00 00       	mov    eax,0x1
  4aca2d:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4aca30:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4aca37:	59                   	pop    ecx
  4aca38:	8b e5                	mov    esp,ebp
  4aca3a:	5d                   	pop    ebp
  4aca3b:	c3                   	ret
```

VA 0x004ACAA0 raw 0xABEA0 bytes: 55 8b ec 83 ec 18 a1 0c 18 fe 00 8b 0d 04 18 fe 00 53 8b 5d 08 56 89 45 e8 89 4d ec 8b 0b 57 83
```asm
004acaa0 <.text+0xabaa0>:
  4acaa0:	55                   	push   ebp
  4acaa1:	8b ec                	mov    ebp,esp
  4acaa3:	83 ec 18             	sub    esp,0x18
  4acaa6:	a1 0c 18 fe 00       	mov    eax,ds:0xfe180c
  4acaab:	8b 0d 04 18 fe 00    	mov    ecx,DWORD PTR ds:0xfe1804
  4acab1:	53                   	push   ebx
  4acab2:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4acab5:	56                   	push   esi
  4acab6:	89 45 e8             	mov    DWORD PTR [ebp-0x18],eax
  4acab9:	89 4d ec             	mov    DWORD PTR [ebp-0x14],ecx
  4acabc:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  4acabe:	57                   	push   edi
  4acabf:	83 c8 ff             	or     eax,0xffffffff
  4acac2:	e8 29 86 24 00       	call   0x6f50f0
  4acac7:	8b 48 08             	mov    ecx,DWORD PTR [eax+0x8]
  4acaca:	83 f9 03             	cmp    ecx,0x3
  4acacd:	74 26                	je     0x4acaf5
  4acacf:	83 f9 04             	cmp    ecx,0x4
  4acad2:	75 5f                	jne    0x4acb33
  4acad4:	8b 30                	mov    esi,DWORD PTR [eax]
  4acad6:	83 c6 10             	add    esi,0x10
  4acad9:	8d 7d f8             	lea    edi,[ebp-0x8]
  4acadc:	e8 7f ac 24 00       	call   0x6f7760
  4acae1:	85 c0                	test   eax,eax
  4acae3:	74 4e                	je     0x4acb33
  4acae5:	dd 45 f8             	fld    QWORD PTR [ebp-0x8]
  4acae8:	c7 45 f8 03 00 00 00 	mov    DWORD PTR [ebp-0x8],0x3
  4acaef:	dd 5d f0             	fstp   QWORD PTR [ebp-0x10]
  4acaf2:	8d 45 f0             	lea    eax,[ebp-0x10]
  4acaf5:	dd 00                	fld    QWORD PTR [eax]
  4acaf7:	dd 5d f8             	fstp   QWORD PTR [ebp-0x8]
  4acafa:	dd 45 f8             	fld    QWORD PTR [ebp-0x8]
  4acafd:	db 5d 08             	fistp  DWORD PTR [ebp+0x8]
  4acb00:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4acb03:	89 55 fc             	mov    DWORD PTR [ebp-0x4],edx
  4acb06:	8b 3b                	mov    edi,DWORD PTR [ebx]
  4acb08:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  4acb0b:	83 ee 20             	sub    esi,0x20
  4acb0e:	83 7e 08 04          	cmp    DWORD PTR [esi+0x8],0x4
  4acb12:	74 40                	je     0x4acb54
  4acb14:	e8 b7 ea 24 00       	call   0x6fb5d0
  4acb19:	85 c0                	test   eax,eax
  4acb1b:	75 1f                	jne    0x4acb3c
  4acb1d:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  4acb20:	8b 4d ec             	mov    ecx,DWORD PTR [ebp-0x14]
  4acb23:	52                   	push   edx
  4acb24:	33 f6                	xor    esi,esi
  4acb26:	56                   	push   esi
  4acb27:	ff 55 e8             	call   DWORD PTR [ebp-0x18]
  4acb2a:	5f                   	pop    edi
  4acb2b:	5e                   	pop    esi
  4acb2c:	33 c0                	xor    eax,eax
  4acb2e:	5b                   	pop    ebx
  4acb2f:	8b e5                	mov    esp,ebp
  4acb31:	5d                   	pop    ebp
  4acb32:	c3                   	ret
  4acb33:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4acb3a:	eb ca                	jmp    0x4acb06
  4acb3c:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  4acb3f:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  4acb42:	3b 48 40             	cmp    ecx,DWORD PTR [eax+0x40]
  4acb45:	72 07                	jb     0x4acb4e
  4acb47:	8b c7                	mov    eax,edi
  4acb49:	e8 52 e8 24 00       	call   0x6fb3a0
  4acb4e:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  4acb51:	83 ee 20             	sub    esi,0x20
  4acb54:	8b 36                	mov    esi,DWORD PTR [esi]
  4acb56:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  4acb59:	8b 4d ec             	mov    ecx,DWORD PTR [ebp-0x14]
  4acb5c:	52                   	push   edx
  4acb5d:	83 c6 10             	add    esi,0x10
  4acb60:	56                   	push   esi
  4acb61:	ff 55 e8             	call   DWORD PTR [ebp-0x18]
  4acb64:	5f                   	pop    edi
  4acb65:	5e                   	pop    esi
  4acb66:	33 c0                	xor    eax,eax
  4acb68:	5b                   	pop    ebx
  4acb69:	8b e5                	mov    esp,ebp
  4acb6b:	5d                   	pop    ebp
  4acb6c:	c3                   	ret
```

## 最小確定與限制
- 確定：字串註冊→函式指標 `0x4AC9E0`→callback 進 `0x4ACB70`，值處理含間接函式指標。
- 未確定：callback 及委派者是否封包，scenario ID 與結果合法性、T14 成敗、T07 場景返回，均為 unknown。
- 後續應追 `0x4ACB70` 的 indirect callback 裝入者及 `0xFE187C` 的 writer；不可由 Lua binding 名稱直接生成伺服器 API。
