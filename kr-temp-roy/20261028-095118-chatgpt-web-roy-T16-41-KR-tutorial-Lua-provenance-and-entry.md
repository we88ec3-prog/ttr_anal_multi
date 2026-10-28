# T16-41 — 教學 Lua：可驗證來源與客戶端執行邊界

- 分析時間：20261028-095118（Asia/Taipei）
- KR 原始 BIN：`Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 證據來源：https://github.com/we88ec3-prog/ttr_anal_multi/blob/main/shared/integrations/T01-20261028-06/README.md、resource-source-audit.json、NEXT-QUERIES.md；本機 KR BIN 以 objdump -D -Mintel 靜態反組譯
- 分類：**有限範圍已確認／來源內容未讀取的項目待驗證**。這份筆記不是教學流程完成證書。

## 1. 原生來源與內容分級
KR TutorialBase.lua SHA256 `26e5fe047b3489b5198023571d1cd3123e0dce712af2c81f57aa767d42ca7744`; TutorialMain.lua SHA256 `662f8416ac7f865b94b15d6ea3145e9a59fbbbaaa8e3be6521c4cff636344809`。T01 的靜態檢驗分別記錄 6 prototypes／72 instruction words 與 11 prototypes／558 instruction words，且 `full_consumption_and_saved_code_match=true`。上述為 Lua chunk 可完整解析與保存碼一致的證據，**不等於已取得完整 Lua 程式碼內容**。對比 TC TutorialBase 6／71、TutorialMain 11／539，不得將 KR 流程直接當作 TC。

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

### `0x006F4A50–0x006F4B45`
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
  6f4b44:	33                 	xor    eax,eax
```

### `0x006F4DD0–0x006F4E70`
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
  6f4e6e:	8d 54            	lea    edx,[esp+0x10]
```

## 3. 功能分析／偽碼邊界
客戶端 `0x004A8A60` 內存在初始化、條件檢查與通往 Lua 入口的後續路徑。由於外部 Lua code 在本執行環境無法取得，不能從腳本名稱推定教程步驟、分支及完成條件； `0xFA ADEC` 比較 15 的行為只可記錄為程式條件，不能命名「教學完成」。

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