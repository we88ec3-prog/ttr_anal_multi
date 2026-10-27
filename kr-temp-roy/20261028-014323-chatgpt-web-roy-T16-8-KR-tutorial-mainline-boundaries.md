# T16-8 — KR 新手教學入口、任務表與主線阻塞的證據整合

- 執行時間（Asia/Taipei）：20261028-014323
- 任務：T16 Quest & Story Progression，版本 KR（TC 本輪僅索引，不做異版推定）
- 第一手映像：Tartaros.bin，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，以唯讀靜態 objdump 驗證
- VA 對映：KR PE `.text` 0x401000 ↔ raw 0x400；`.rdata` 0xBD2000 ↔ raw 0x7D0600
- 工作基準：GitHub main `e1591500bef6f35acff736615109e1010264dc75`（提交前再次核對）；已有 T16-1～T16-4 研究
- 研究範圍：已存在角色的任務／教學；不重做 T03/T04/T07/T14/T15/T02；未執行遊戲、未修改客戶端或原始證據
- 分級：`native-confirmed` = 指令／常數；`native-partial` = 行為語義局部；`hypothesis` = 未完成 caller/consumer；`missing` = 沒有原版來源。

## 本段研究問題與結論
## 教學入口與任務表證據界面整合
本段以新的機器碼重驗 `0x004A8A60` 及 `0x004A89C0` 跨界入口，並與前段 XML 與樹結構串接。**並無可證實的 call/dataflow 邊可直接從 Lua 入口連到 `0xFE18DC` 或 `QuestInfo` 的任務寫入者**；不能畫成正式原版完整主線。

### 教學入口（已確認呼叫，而非狀態轉換）
- `0x004A8A60` 建立／使用 Lua 上下文後以 `Event/TutorialMain.lua` 與 `Tutorial_EntryPoint` 呼叫既有通用載入／分派 helper。入口判定來源未封閉。
- `0x004A89C0` 參照 `Synopsis_EntryPoint`，與 Tutorial 名稱不同；不將 synopsis 誤認為教學完成。
- `0x00FBA798` 的判斷具有本地間接分支，但現階段未證實它對應角色首次登入，也不能與原始 `005F type6` 混同。

### 可證實的功能鏈與缺邊
```text
已存在角色(T03/T04) --[unknown]--> Tutorial/Synopsis 入口 (KR client native)
           --[Lua 腳本 bytes missing]--> 教學節點／完成條件 (unknown)
 QuestInfo.xml / QuestTalk.xml 路徑 --[native loader]--> 預期 XML root (binary strings)
           --[resource bytes missing]--> quest IDs / NPC / dialogue (unknown)
 candidate flags parser --[native 0x53FEB0]--> vector-like output (confirmed)
           --[unproven connection]--> ordered map insert 0xFE18DC (native)
           --[writer consumer missing]--> server authoritative quest state (unknown)
 教學完成 --[missing]--> 首個主線 --[missing]--> 下一主線解鎖
```

## 優先且不越界的下一批研究
1. 查 KR 資源封裝中實際 `Event/TutorialMain.lua`、`QuestInfo.xml`、`QuestTalk.xml`，記錄來源 SHA；無內容不得補任務 ID。
2. 在 native `0x0047BACE` / `0x004C1FFC` / `0x004C4D3F` 上游追實際角色狀態條件。
3. 找 `0xFE18DC` consumer 和 Quest 狀態通知入站解析，將 UI 與 server 權威分開。
4. TC 優先有來源的文字與表格；此輪沒有 TC 原件，未知維持未知。

### KR VA `0x004A89C0..0x004A8A60`（原生指令）
```asm
004a89c0 <.text+0xa79c0>:
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
```
### KR VA `0x004A8A60..0x004A8B91`（原生指令）
```asm
004a8a60 <.text+0xa7a60>:
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
  4a8b90:	55                   	push   ebp
```

## 教學／主線節點矩陣（本段更新）
| state／節點 | evidence | 入口／觸發 | 權威／writer | 下一節點／續接 |
|---|---|---|---|---|
| Tutorial Lua 入口 | T16-1/2/3 native-partial | `0x004A8A60`, `0x004A89C0` | unknown | unknown |
| QuestInfo/QuestTalk 客戶端資料 | T16-4 native-partial | `0x00504740`, `0x00505570` | unknown | unknown |
| 首項教學目標／完成 | missing | unknown | unknown | unknown |
| 主線第一個 ID／NPC／交付 | missing | unknown | unknown | unknown |

## KR／TC 比較與驗收界線
| 項 | KR | TC | 驗收 |
|---|---|---|---|
| native SHA | 直接讀取與驗證 | `f181071094286fe4e72cb12863edbe7e83f8fa825cfb65604143cb53ae2cd873` 僅 repo 登記 | KR pass，TC 未直接驗證 |
| 函式／偏移 | 本篇所列只對 KR 有效 | unknown | 不得搬用 |
| 教學完整路線 | unknown | unknown | 未達標 |
| 首段主線閉環／伺服器授權 | unknown | unknown | 未達標 |
| 角色初始值 | T04 主責 | T04 主責 | 不在 T16 重作 |
| 可玩測試 | 未執行 | 未執行 | 未驗收 |

## 跨 Task 介面與後續查核
- T04 → T16：已有角色資料的教學適用條件／旗標來源 `unknown`。
- T02 ↔ T16：Quest 網路命令／權威 `unknown`；不可把 UI 或 Lua 呼叫視為伺服器寫入。
- T07/T14 → T16：關卡結果映射到 quest step `unknown`。
- T15 ↔ T16：保存與重登續接契約 `unknown`。
- 既有 `005F type6` 與歷史 tutorial fixture 無權擴大認定。
- 不以「反編譯已上傳」判定整體函式語義驗證完成。

## 提交狀態
本文件產生時不代表已 GitHub 提交；由本對話完成 T16-8 後逐檔提交及讀回核實。