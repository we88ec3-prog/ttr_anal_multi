# T16-44 — 任務狀態權威：證據驗收矩陣與本地補證介面

- 分析時間：20261028-095118（Asia/Taipei）
- KR 原始 BIN：`Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 證據來源：https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/shared/integrations/T01-20261028-06/README.md、resource-source-audit.json、NEXT-QUERIES.md；本機 KR BIN 以 objdump -D -Mintel 靜態反組譯
- 分類：**有限範圍已確認／來源內容未讀取的項目待驗證**。這份筆記不是教學流程完成證書。

## 1. 原生來源與內容分級
T01-20261028-06 的來源稽核記載 `96` 個封裝成員重新解取、`12` 個 Lua chunks 共 `216` prototypes／`3450` instruction words，並且明確限制「source/resource checks do not certify official backend, complete native semantics or gameplay」。T16 KR/TC 的 task.json 仍然 `native_complete=false`，並保留獨立版本核對。

## 2. 本次直接 BIN 證據（PE VA）

### `0x004A8A60–0x004A8B90`
```asm
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
  4a8b13:	e8 88 1e 0e 00       	call   0x58a9a0
  4a8b18:	84 1d 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,bl
  4a8b1e:	75 13                	jne    0x4a8b33
  4a8b20:	09 1d 14 13 fb 00    	or     DWORD PTR ds:0xfb1314,ebx
  4a8b26:	68 10 cf bc 00       	push   0xbccf10
  4a8b2b:	e8 ea 97 3e 00       	call   0x89231a
  4a8b30:	83 c4 04             	add    esp,0x4
  4a8b33:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a8b3a:	b8 0c 00 00 00       	mov    eax,0xc
  4a8b3f:	66 89 45 ec          	mov    WORD PTR [ebp-0x14],ax
  4a8b43:	89 5d ee             	mov    DWORD PTR [ebp-0x12],ebx
  4a8b46:	75 15                	jne    0x4a8b5d
  4a8b48:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a8b4e:	8b 11                	mov    edx,DWORD PTR [ecx]
  4a8b50:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4a8b53:	6a 06                	push   0x6
  4a8b55:	8d 45 ec             	lea    eax,[ebp-0x14]
  4a8b58:	50                   	push   eax
  4a8b59:	6a 00                	push   0x0
  4a8b5b:	ff d2                	call   edx
  4a8b5d:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4a8b5f:	68 7c 68 c0 00       	push   0xc0687c
  4a8b64:	e8 e7 be 24 00       	call   0x6f4a50
  4a8b69:	8b 06                	mov    eax,DWORD PTR [esi]
  4a8b6b:	6a 00                	push   0x0
  4a8b6d:	6a 00                	push   0x0
  4a8b6f:	68 a8 68 c0 00       	push   0xc068a8
  4a8b74:	e8 57 c2 24 00       	call   0x6f4dd0
  4a8b79:	83 c4 0c             	add    esp,0xc
  4a8b7c:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4a8b7f:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4a8b86:	59                   	pop    ecx
  4a8b87:	5f                   	pop    edi
  4a8b88:	5b                   	pop    ebx
  4a8b89:	8b e5                	mov    esp,ebp
  4a8b8b:	5d                   	pop    ebp
  4a8b8c:	c3                   	ret
  4a8b8d:	cc                   	int3
  4a8b8e:	cc                   	int3
  4a8b8f:	cc                   	int3
```

### `0x0053FD70–0x0053FE45`
```asm
  53fd70:	eb 04                	jmp    0x53fd76
  53fd72:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  53fd76:	68 e4 f4 c0 00       	push   0xc0f4e4
  53fd7b:	8b c3                	mov    eax,ebx
  53fd7d:	e8 5e e5 1e 00       	call   0x72e2e0
  53fd82:	8b f8                	mov    edi,eax
  53fd84:	68 ec f4 c0 00       	push   0xc0f4ec
  53fd89:	8b c3                	mov    eax,ebx
  53fd8b:	e8 50 e5 1e 00       	call   0x72e2e0
  53fd90:	8b f0                	mov    esi,eax
  53fd92:	68 f8 f4 c0 00       	push   0xc0f4f8
  53fd97:	8b c3                	mov    eax,ebx
  53fd99:	e8 42 e5 1e 00       	call   0x72e2e0
  53fd9e:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  53fda2:	68 0c f5 c0 00       	push   0xc0f50c
  53fda7:	8b c3                	mov    eax,ebx
  53fda9:	e8 32 e5 1e 00       	call   0x72e2e0
  53fdae:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  53fdb2:	85 ff                	test   edi,edi
  53fdb4:	74 0c                	je     0x53fdc2
  53fdb6:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  53fdba:	51                   	push   ecx
  53fdbb:	8b c7                	mov    eax,edi
  53fdbd:	e8 ee 00 00 00       	call   0x53feb0
  53fdc2:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  53fdc6:	85 f6                	test   esi,esi
  53fdc8:	74 0b                	je     0x53fdd5
  53fdca:	8d 57 10             	lea    edx,[edi+0x10]
  53fdcd:	52                   	push   edx
  53fdce:	8b c6                	mov    eax,esi
  53fdd0:	e8 db 00 00 00       	call   0x53feb0
  53fdd5:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  53fdd9:	85 c0                	test   eax,eax
  53fddb:	74 09                	je     0x53fde6
  53fddd:	8d 4f 20             	lea    ecx,[edi+0x20]
  53fde0:	51                   	push   ecx
  53fde1:	e8 ca 00 00 00       	call   0x53feb0
  53fde6:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  53fdea:	85 c0                	test   eax,eax
  53fdec:	74 09                	je     0x53fdf7
  53fdee:	8d 57 30             	lea    edx,[edi+0x30]
  53fdf1:	52                   	push   edx
  53fdf2:	e8 b9 00 00 00       	call   0x53feb0
  53fdf7:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  53fdfb:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  53fdff:	8d 7c 24 24          	lea    edi,[esp+0x24]
  53fe03:	be dc 18 fe 00       	mov    esi,0xfe18dc
  53fe08:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  53fe0c:	e8 0f f1 03 00       	call   0x57ef20
  53fe11:	50                   	push   eax
  53fe12:	56                   	push   esi
  53fe13:	8d 74 24 34          	lea    esi,[esp+0x34]
  53fe17:	e8 34 ea 03 00       	call   0x57e850
  53fe1c:	33 f6                	xor    esi,esi
  53fe1e:	8b 5b 40             	mov    ebx,DWORD PTR [ebx+0x40]
  53fe21:	3b de                	cmp    ebx,esi
  53fe23:	0f 85 cc fe ff ff    	jne    0x53fcf5
  53fe29:	bb 10 00 00 00       	mov    ebx,0x10
  53fe2e:	c7 84 24 c0 00 00 00 	mov    DWORD PTR [esp+0xc0],0xffffffff
  53fe35:	ff ff ff ff 
  53fe39:	c7 44 24 34 94 23 bf 	mov    DWORD PTR [esp+0x34],0xbf2394
  53fe40:	00 
  53fe41:	39 9c 24 94    	cmp    DWORD PTR [esp+0x94],ebx
```

### `0x004ADD50–0x004ADE20`
```asm
  4add50:	53                   	push   ebx
  4add51:	56                   	push   esi
  4add52:	8d 50 08             	lea    edx,[eax+0x8]
  4add55:	be d5 0b 00 00       	mov    esi,0xbd5
  4add5a:	b9 75 23 bf 00       	mov    ecx,0xbf2375
  4add5f:	90                   	nop
  4add60:	c7 42 fc 40 7d 4b 00 	mov    DWORD PTR [edx-0x4],0x4b7d40
  4add67:	89 0a                	mov    DWORD PTR [edx],ecx
  4add69:	83 c2 08             	add    edx,0x8
  4add6c:	4e                   	dec    esi
  4add6d:	75 f1                	jne    0x4add60
  4add6f:	ba 80 fb 4a 00       	mov    edx,0x4afb80
  4add74:	c7 40 34 30 7d 4b 00 	mov    DWORD PTR [eax+0x34],0x4b7d30
  4add7b:	89 48 38             	mov    DWORD PTR [eax+0x38],ecx
  4add7e:	c7 40 3c d0 e4 4a 00 	mov    DWORD PTR [eax+0x3c],0x4ae4d0
  4add85:	89 48 40             	mov    DWORD PTR [eax+0x40],ecx
  4add88:	c7 80 f4 09 00 00 b0 	mov    DWORD PTR [eax+0x9f4],0x4aedb0
  4add8f:	ed 4a 00 
  4add92:	89 88 f8 09 00 00    	mov    DWORD PTR [eax+0x9f8],ecx
  4add98:	c7 40 44 30 f5 4a 00 	mov    DWORD PTR [eax+0x44],0x4af530
  4add9f:	89 48 48             	mov    DWORD PTR [eax+0x48],ecx
  4adda2:	c7 40 54 20 f9 4a 00 	mov    DWORD PTR [eax+0x54],0x4af920
  4adda9:	89 48 58             	mov    DWORD PTR [eax+0x58],ecx
  4addac:	c7 40 04 f0 fa 4a 00 	mov    DWORD PTR [eax+0x4],0x4afaf0
  4addb3:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  4addb6:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  4addb9:	89 48 10             	mov    DWORD PTR [eax+0x10],ecx
  4addbc:	c7 40 5c 60 fe 4a 00 	mov    DWORD PTR [eax+0x5c],0x4afe60
  4addc3:	89 48 60             	mov    DWORD PTR [eax+0x60],ecx
  4addc6:	c7 40 64 30 01 4b 00 	mov    DWORD PTR [eax+0x64],0x4b0130
  4addcd:	89 48 68             	mov    DWORD PTR [eax+0x68],ecx
  4addd0:	c7 40 6c c0 01 4b 00 	mov    DWORD PTR [eax+0x6c],0x4b01c0
  4addd7:	89 48 70             	mov    DWORD PTR [eax+0x70],ecx
  4addda:	c7 80 7c 05 00 00 d0 	mov    DWORD PTR [eax+0x57c],0x4b03d0
  4adde1:	03 4b 00 
  4adde4:	89 88 80 05 00 00    	mov    DWORD PTR [eax+0x580],ecx
  4addea:	c7 40 74 40 6c 43 00 	mov    DWORD PTR [eax+0x74],0x436c40
  4addf1:	89 48 78             	mov    DWORD PTR [eax+0x78],ecx
  4addf4:	c7 80 fc 09 00 00 40 	mov    DWORD PTR [eax+0x9fc],0x4b1940
  4addfb:	19 4b 00 
  4addfe:	89 88 00 0a 00 00    	mov    DWORD PTR [eax+0xa00],ecx
  4ade04:	c7 40 7c d0 19 4b 00 	mov    DWORD PTR [eax+0x7c],0x4b19d0
  4ade0b:	89 88 80 00 00 00    	mov    DWORD PTR [eax+0x80],ecx
  4ade11:	c7 80 84 00 00 00 30 	mov    DWORD PTR [eax+0x84],0x4b1a30
  4ade18:	1a 4b 00 
  4ade1b:	89 88 88 00 00     	mov    DWORD PTR [eax+0x88],ecx
```

## 3. 功能分析／偽碼邊界
本次可驗收：來源文件/雜湊/原生客戶端部分 CFG。不能驗收：server opcode→business handler→持久化 writer→重登 snapshot→下一 Quest 解鎖。應保留缺失列與本地復核需要的最小輸入（Lua decode JSON／Quest XML 元素、有效 payload、權威端碼或抓包）。

```cpp
// 證據分級式流程模型；未知值不臆造
resource = find_source_by_version_and_sha();
if (!resource.full_bytes_read) mark("DEFERRED-LOCAL-RESOURCE");
native_entry = verify_machine_code_boundaries();
// Quest16/Quest15 server authority & persistence: unknown
```

## 4. 與既有 T16 分段的關係
- T16-1～T16-40 原稿位於 `kr-temp-roy/`，提供 Lua 入口、XML 載入、quest parser 與分派路徑的歷史分析。這份筆記保留新來源稽核和原生組合語言，**不把舊推論提升成已驗收業務規則**。
- 原版 BIN 的 PE VA 與 TC 不可共用。

## 5. 尚缺證據與本地補證工作
1. `DEFERRED-LOCAL-RESOURCE`：從已核對 SHA 的 KR Event.stp 解出並交付 `Event/TutorialMain.lua`、`Event/TutorialBase.lua` 的完整 bytes 與 Lua proto/constant/branch 解碼。
2. `DEFERRED-LOCAL-RESOURCE`：KR Table.stp 中 `QuestInfo.xml`／`QuestTalk.xml` 完整元素，單獨列 Quest15、Quest16 及相關前置和 ID namespace。
3. 確認 scenario14/TUTO 交界、正式 opcode/payload、伺服器任務 writer，並以重登恢復抓包或伺服器碼交叉驗證。
4. 只有來源 hash 或 XML root children count 時，quest step、完成條件、獎勵與權威仍填 `unknown`。

## 6. 最小測試矩陣
| 問題 | 目前狀態 | 下一個驗收證據 |
|---|---|---|
| 是否能確認 KR 腳本/表來源 | 已確認來源稽核，尚未讀全文 | 提供 hash 對應原始位元組 |
| Tutorial 入口可定位 | 原生程式入口部分確認 | 腳本 function/branch 對應 |
| 教學逐節點順序 | 未確認 | Lua proto/constant/CFG 與 XML 對照 |
| Quest16 完成／Quest15 接取 | 未確認 | XML rule + server notification/write |
| 重登／保存 | 未確認 | T15 提供 writer 與 snapshot |

## 7. 版本與提交注意
- KR/TC 嚴格隔離，無 TC BIN 的本次直接反組譯。
- 未啟動或修改遊戲程序。
- 本稿作為獨立分析來源提交，不變更 catalog、owner、其他 Task。