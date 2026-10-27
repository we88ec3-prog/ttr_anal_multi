# T16-33 — Tutorial 入口及上游直接呼叫：確認分派前條件和 caller 範圍

- 原始研究時間（Asia/Taipei）：20261028-023112
- Source: KR `Tartaros.bin`，唯讀靜態分析，bytes=`12472320`，SHA256=`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- GitHub 起始基線：`0de4fe39719a83f38a003af8efeed6b5c9b20f90`（研究啟動時核對）
- 本段主題：Tutorial 入口及上游直接呼叫：確認分派前條件和 caller 範圍
- 界線：可確定的只有原生機器碼與本段直接解析之位址／跳躍；**不宣稱**任何原版任務 ID、NPC、完成條件、封包權威或 Lua/XML 實體內容。
- 研究方法：`objdump -D -Mintel -j .text` 依 VA 擷取原始 bytes；另外從 `.text` 扫描 `E8 rel32` 作交叉參照候選，僅經指令對齊與上下文核對後方可作控制流程證據。

## 1. 可重現基線與 PE 映射

| section | VA 起點 | file offset | 限制 |
|---|---|---|---|
| .text | `0x00401000` | `0x400` | 指令與常數候選 |
| .rdata | `0x00BD2000` | `0x007D0600` | 字串不是語義證據 |
| .data | `0x00D61000` | `0x0095E800` | static image ≠ runtime field value |

## 2. 研究範圍與函式邊界

本段截取下列 **位址視窗**，它們不必然等於完整函式；需以 prologue、返回路徑及多入口參照重新界定。總計 174 行反組譯輸出。

| start | stop (exclusive) | raw start | direct E8 candidates to start |
|---|---|---|---|
| `0x004A8A60` | `0x004A8B8E` | `0xA7E60` | `0x004C4D3F` |
| `0x004C4C80` | `0x004C4DA0` | `0xC4080` | `none found by raw E8 sweep` |

**注意：** raw `E8` 比對可能掃到指令中間；不得把表格所有候選自動計為真實 caller。`call [reg]`、vtable 呼叫亦不受 raw E8 掃描覆蓋。

## 3. Native assembly evidence

### `0x004A8A60` .. `0x004A8B8E`

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
```

### `0x004C4C80` .. `0x004C4DA0`

```asm
  4c4c80:	70 db                	jo     0x4c4c5d
  4c4c82:	bc 00 e8 91 d6       	mov    esp,0xd691e800
  4c4c87:	3c 00                	cmp    al,0x0
  4c4c89:	83 c4 04             	add    esp,0x4
  4c4c8c:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4c4c90:	b9 84 0f fc 00       	mov    ecx,0xfc0f84
  4c4c95:	e8 86 3f fe ff       	call   0x4a8c20
  4c4c9a:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4c4ca0:	3b ce                	cmp    ecx,esi
  4c4ca2:	74 2f                	je     0x4c4cd3
  4c4ca4:	83 3d ac a7 fb 00 04 	cmp    DWORD PTR ds:0xfba7ac,0x4
  4c4cab:	75 0e                	jne    0x4c4cbb
  4c4cad:	8b f9                	mov    edi,ecx
  4c4caf:	e8 9c 02 08 00       	call   0x544f50
  4c4cb4:	bf 01 00 00 00       	mov    edi,0x1
  4c4cb9:	eb 52                	jmp    0x4c4d0d
  4c4cbb:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c4cbd:	8b 50 28             	mov    edx,DWORD PTR [eax+0x28]
  4c4cc0:	ff d2                	call   edx
  4c4cc2:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4c4cc8:	3b ce                	cmp    ecx,esi
  4c4cca:	74 07                	je     0x4c4cd3
  4c4ccc:	8b 01                	mov    eax,DWORD PTR [ecx]
  4c4cce:	8b 10                	mov    edx,DWORD PTR [eax]
  4c4cd0:	57                   	push   edi
  4c4cd1:	ff d2                	call   edx
  4c4cd3:	68 38 01 00 00       	push   0x138
  4c4cd8:	e8 8b c5 3c 00       	call   0x891268
  4c4cdd:	83 c4 04             	add    esp,0x4
  4c4ce0:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  4c4ce4:	c7 44 24 20 08 00 00 	mov    DWORD PTR [esp+0x20],0x8
  4c4ceb:	00 
  4c4cec:	3b c6                	cmp    eax,esi
  4c4cee:	74 09                	je     0x4c4cf9
  4c4cf0:	8b f0                	mov    esi,eax
  4c4cf2:	e8 99 3e 08 00       	call   0x548b90
  4c4cf7:	eb 02                	jmp    0x4c4cfb
  4c4cf9:	33 c0                	xor    eax,eax
  4c4cfb:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4c4cff:	8b 10                	mov    edx,DWORD PTR [eax]
  4c4d01:	a3 a4 a7 fb 00       	mov    ds:0xfba7a4,eax
  4c4d06:	8b c8                	mov    ecx,eax
  4c4d08:	8b 42 24             	mov    eax,DWORD PTR [edx+0x24]
  4c4d0b:	ff d0                	call   eax
  4c4d0d:	f6 05 80 0f fc 00 01 	test   BYTE PTR ds:0xfc0f80,0x1
  4c4d14:	75 24                	jne    0x4c4d3a
  4c4d16:	09 3d 80 0f fc 00    	or     DWORD PTR ds:0xfc0f80,edi
  4c4d1c:	c7 44 24 20 0b 00 00 	mov    DWORD PTR [esp+0x20],0xb
  4c4d23:	00 
  4c4d24:	e8 87 61 fb ff       	call   0x47aeb0
  4c4d29:	68 70 db bc 00       	push   0xbcdb70
  4c4d2e:	e8 e7 d5 3c 00       	call   0x89231a
  4c4d33:	83 c4 04             	add    esp,0x4
  4c4d36:	89 5c 24 20          	mov    DWORD PTR [esp+0x20],ebx
  4c4d3a:	be 84 0f fc 00       	mov    esi,0xfc0f84
  4c4d3f:	e8 1c 3d fe ff       	call   0x4a8a60
  4c4d44:	33 c0                	xor    eax,eax
  4c4d46:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  4c4d4a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c4d51:	59                   	pop    ecx
  4c4d52:	5f                   	pop    edi
  4c4d53:	5e                   	pop    esi
  4c4d54:	5b                   	pop    ebx
  4c4d55:	8b e5                	mov    esp,ebp
  4c4d57:	5d                   	pop    ebp
  4c4d58:	c3                   	ret
  4c4d59:	cc                   	int3
  4c4d5a:	cc                   	int3
  4c4d5b:	cc                   	int3
  4c4d5c:	cc                   	int3
  4c4d5d:	cc                   	int3
  4c4d5e:	cc                   	int3
  4c4d5f:	cc                   	int3
  4c4d60:	55                   	push   ebp
  4c4d61:	8b ec                	mov    ebp,esp
  4c4d63:	6a ff                	push   0xffffffff
  4c4d65:	68 ce 3e 93 00       	push   0x933ece
  4c4d6a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c4d70:	50                   	push   eax
  4c4d71:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c4d76:	33 c5                	xor    eax,ebp
  4c4d78:	50                   	push   eax
  4c4d79:	8d 45 f4             	lea    eax,[ebp-0xc]
  4c4d7c:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c4d82:	b8 01 00 00 00       	mov    eax,0x1
  4c4d87:	84 05 80 0f fc 00    	test   BYTE PTR ds:0xfc0f80,al
  4c4d8d:	75 26                	jne    0x4c4db5
  4c4d8f:	09 05 80 0f fc 00    	or     DWORD PTR ds:0xfc0f80,eax
  4c4d95:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4c4d9c:	e8 0f 61 fb        	call   0x47aeb0
```

## 4. 局部控制流程與資料流（指令級）

以下為本段出現的直接 call 指令節錄；**callee 的高階名稱均不自動確定**：

```asm
  4a8a94:	e8 b7 ad 37 00       	call   0x823850
  4a8a9c:	e8 7f 89 3a 00       	call   0x851420
  4a8abe:	e8 0d a9 0a 00       	call   0x5533d0
  4a8ac8:	e8 4d 98 3e 00       	call   0x89231a
  4a8aea:	e8 91 e9 0d 00       	call   0x587480
  4a8af4:	e8 21 98 3e 00       	call   0x89231a
  4a8b13:	e8 88 1e 0e 00       	call   0x58a9a0
  4a8b2b:	e8 ea 97 3e 00       	call   0x89231a
  4a8b5b:	ff d2                	call   edx
  4a8b64:	e8 e7 be 24 00       	call   0x6f4a50
  4a8b74:	e8 57 c2 24 00       	call   0x6f4dd0
  4c4c95:	e8 86 3f fe ff       	call   0x4a8c20
  4c4caf:	e8 9c 02 08 00       	call   0x544f50
  4c4cc0:	ff d2                	call   edx
  4c4cd1:	ff d2                	call   edx
  4c4cd8:	e8 8b c5 3c 00       	call   0x891268
  4c4cf2:	e8 99 3e 08 00       	call   0x548b90
  4c4d0b:	ff d0                	call   eax
  4c4d24:	e8 87 61 fb ff       	call   0x47aeb0
  4c4d2e:	e8 e7 d5 3c 00       	call   0x89231a
  4c4d3f:	e8 1c 3d fe ff       	call   0x4a8a60
  4c4d9c:	e8 0f 61 fb        	call   0x47aeb0
```

比較、測試及分支位置（節錄）：

```asm
  4a8aa9:	84 1d 54 73 fb 00    	test   BYTE PTR ds:0xfb7354,bl
  4a8aaf:	75 22                	jne    0x4a8ad3
  4a8ad9:	84 1d d4 ad fa 00    	test   BYTE PTR ds:0xfaadd4,bl
  4a8adf:	75 1e                	jne    0x4a8aff
  4a8b04:	39 05 ec ad fa 00    	cmp    DWORD PTR ds:0xfaadec,eax
  4a8b0a:	74 07                	je     0x4a8b13
  4a8b11:	eb 05                	jmp    0x4a8b18
  4a8b18:	84 1d 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,bl
  4a8b1e:	75 13                	jne    0x4a8b33
  4a8b33:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a8b46:	75 15                	jne    0x4a8b5d
  4a8b8c:	c3                   	ret
  4c4c80:	70 db                	jo     0x4c4c5d
  4c4c87:	3c 00                	cmp    al,0x0
  4c4ca0:	3b ce                	cmp    ecx,esi
  4c4ca2:	74 2f                	je     0x4c4cd3
  4c4ca4:	83 3d ac a7 fb 00 04 	cmp    DWORD PTR ds:0xfba7ac,0x4
  4c4cab:	75 0e                	jne    0x4c4cbb
  4c4cb9:	eb 52                	jmp    0x4c4d0d
  4c4cc8:	3b ce                	cmp    ecx,esi
  4c4cca:	74 07                	je     0x4c4cd3
  4c4cec:	3b c6                	cmp    eax,esi
  4c4cee:	74 09                	je     0x4c4cf9
  4c4cf7:	eb 02                	jmp    0x4c4cfb
  4c4d0d:	f6 05 80 0f fc 00 01 	test   BYTE PTR ds:0xfc0f80,0x1
  4c4d14:	75 24                	jne    0x4c4d3a
  4c4d58:	c3                   	ret
  4c4d87:	84 05 80 0f fc 00    	test   BYTE PTR ds:0xfc0f80,al
  4c4d8d:	75 26                	jne    0x4c4db5
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