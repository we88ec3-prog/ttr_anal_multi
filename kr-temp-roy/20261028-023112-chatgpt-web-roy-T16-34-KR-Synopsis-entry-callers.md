# T16-34 — Synopsis 入口及兩個上游場景的指令級差異

- 原始研究時間（Asia/Taipei）：20261028-023112
- Source: KR `Tartaros.bin`，唯讀靜態分析，bytes=`12472320`，SHA256=`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- GitHub 起始基線：`0de4fe39719a83f38a003af8efeed6b5c9b20f90`（研究啟動時核對）
- 本段主題：Synopsis 入口及兩個上游場景的指令級差異
- 界線：可確定的只有原生機器碼與本段直接解析之位址／跳躍；**不宣稱**任何原版任務 ID、NPC、完成條件、封包權威或 Lua/XML 實體內容。
- 研究方法：`objdump -D -Mintel -j .text` 依 VA 擷取原始 bytes；另外從 `.text` 扫描 `E8 rel32` 作交叉參照候選，僅經指令對齊與上下文核對後方可作控制流程證據。

## 1. 可重現基線與 PE 映射

| section | VA 起點 | file offset | 限制 |
|---|---|---|---|
| .text | `0x00401000` | `0x400` | 指令與常數候選 |
| .rdata | `0x00BD2000` | `0x007D0600` | 字串不是語義證據 |
| .data | `0x00D61000` | `0x0095E800` | static image ≠ runtime field value |

## 2. 研究範圍與函式邊界

本段截取下列 **位址視窗**，它們不必然等於完整函式；需以 prologue、返回路徑及多入口參照重新界定。總計 155 行反組譯輸出。

| start | stop (exclusive) | raw start | direct E8 candidates to start |
|---|---|---|---|
| `0x004A89C0` | `0x004A8A60` | `0xA7DC0` | `0x0047BACE`, `0x004C1FFC` |
| `0x0047BA80` | `0x0047BB30` | `0x7AE80` | `none found by raw E8 sweep` |
| `0x004C1F90` | `0x004C2040` | `0xC1390` | `none found by raw E8 sweep` |

**注意：** raw `E8` 比對可能掃到指令中間；不得把表格所有候選自動計為真實 caller。`call [reg]`、vtable 呼叫亦不受 raw E8 掃描覆蓋。

## 3. Native assembly evidence

### `0x004A89C0` .. `0x004A8A60`

```asm
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

### `0x0047BA80` .. `0x0047BB30`

```asm
  47ba80:	90                   	nop
  47ba81:	0e                   	push   cs
  47ba82:	fc                   	cld
  47ba83:	00 c6                	add    dh,al
  47ba85:	45                   	inc    ebp
  47ba86:	fc                   	cld
  47ba87:	02 e8                	add    ch,al
  47ba89:	53                   	push   ebx
  47ba8a:	22 32                	and    dh,BYTE PTR [edx]
  47ba8c:	00 8b f0 6a ff 56    	add    BYTE PTR [ebx+0x56ff6af0],cl
  47ba92:	ff 15 fc 20 bd 00    	call   DWORD PTR ds:0xbd20fc
  47ba98:	56                   	push   esi
  47ba99:	ff 15 c8 21 bd 00    	call   DWORD PTR ds:0xbd21c8
  47ba9f:	f6 05 80 0f fc 00 01 	test   BYTE PTR ds:0xfc0f80,0x1
  47baa6:	75 21                	jne    0x47bac9
  47baa8:	83 0d 80 0f fc 00 01 	or     DWORD PTR ds:0xfc0f80,0x1
  47baaf:	c6 45 fc 05          	mov    BYTE PTR [ebp-0x4],0x5
  47bab3:	e8 f8 f3 ff ff       	call   0x47aeb0
  47bab8:	68 70 db bc 00       	push   0xbcdb70
  47babd:	e8 58 68 41 00       	call   0x89231a
  47bac2:	83 c4 04             	add    esp,0x4
  47bac5:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  47bac9:	be 84 0f fc 00       	mov    esi,0xfc0f84
  47bace:	e8 ed ce 02 00       	call   0x4a89c0
  47bad3:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  47bad7:	85 ff                	test   edi,edi
  47bad9:	74 29                	je     0x47bb04
  47badb:	8d 57 04             	lea    edx,[edi+0x4]
  47bade:	83 c8 ff             	or     eax,0xffffffff
  47bae1:	f0 0f c1 02          	lock xadd DWORD PTR [edx],eax
  47bae5:	75 1d                	jne    0x47bb04
  47bae7:	8b 17                	mov    edx,DWORD PTR [edi]
  47bae9:	8b 02                	mov    eax,DWORD PTR [edx]
  47baeb:	8b cf                	mov    ecx,edi
  47baed:	ff d0                	call   eax
  47baef:	8d 4f 08             	lea    ecx,[edi+0x8]
  47baf2:	83 ca ff             	or     edx,0xffffffff
  47baf5:	f0 0f c1 11          	lock xadd DWORD PTR [ecx],edx
  47baf9:	75 09                	jne    0x47bb04
  47bafb:	8b 07                	mov    eax,DWORD PTR [edi]
  47bafd:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  47bb00:	8b cf                	mov    ecx,edi
  47bb02:	ff d2                	call   edx
  47bb04:	8b 45 a8             	mov    eax,DWORD PTR [ebp-0x58]
  47bb07:	85 c0                	test   eax,eax
  47bb09:	74 09                	je     0x47bb14
  47bb0b:	50                   	push   eax
  47bb0c:	e8 fb 56 41 00       	call   0x89120c
  47bb11:	83 c4 04             	add    esp,0x4
  47bb14:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47bb17:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47bb1e:	59                   	pop    ecx
  47bb1f:	5f                   	pop    edi
  47bb20:	5e                   	pop    esi
  47bb21:	5b                   	pop    ebx
  47bb22:	8b e5                	mov    esp,ebp
  47bb24:	5d                   	pop    ebp
  47bb25:	c2 04 00             	ret    0x4
  47bb28:	8b 7d bc             	mov    edi,DWORD PTR [ebp-0x44]
  47bb2b:	8b 4d b8             	mov    ecx,DWORD PTR [ebp-0x48]
  47bb2e:	8b 75              	mov    esi,DWORD PTR [ebp+0x8]
```

### `0x004C1F90` .. `0x004C2040`

```asm
  4c1f90:	2d 00 68 80 db       	sub    eax,0xdb806800
  4c1f95:	bc 00 e8 7e 03       	mov    esp,0x37ee800
  4c1f9a:	3d 00 83 c4 04       	cmp    eax,0x4c48300
  4c1f9f:	c6 44 24 30 01       	mov    BYTE PTR [esp+0x30],0x1
  4c1fa4:	b9 90 0e fc 00       	mov    ecx,0xfc0e90
  4c1fa9:	88 5c 24 30          	mov    BYTE PTR [esp+0x30],bl
  4c1fad:	e8 2e bd 2d 00       	call   0x79dce0
  4c1fb2:	8b f0                	mov    esi,eax
  4c1fb4:	6a ff                	push   0xffffffff
  4c1fb6:	56                   	push   esi
  4c1fb7:	ff 15 fc 20 bd 00    	call   DWORD PTR ds:0xbd20fc
  4c1fbd:	56                   	push   esi
  4c1fbe:	ff 15 c8 21 bd 00    	call   DWORD PTR ds:0xbd21c8
  4c1fc4:	f6 05 80 0f fc 00 01 	test   BYTE PTR ds:0xfc0f80,0x1
  4c1fcb:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4c1fce:	89 ba 78 bd 00 00    	mov    DWORD PTR [edx+0xbd78],edi
  4c1fd4:	75 21                	jne    0x4c1ff7
  4c1fd6:	09 3d 80 0f fc 00    	or     DWORD PTR ds:0xfc0f80,edi
  4c1fdc:	c6 44 24 28 03       	mov    BYTE PTR [esp+0x28],0x3
  4c1fe1:	e8 ca 8e fb ff       	call   0x47aeb0
  4c1fe6:	68 70 db bc 00       	push   0xbcdb70
  4c1feb:	e8 2a 03 3d 00       	call   0x89231a
  4c1ff0:	83 c4 04             	add    esp,0x4
  4c1ff3:	88 5c 24 28          	mov    BYTE PTR [esp+0x28],bl
  4c1ff7:	be 84 0f fc 00       	mov    esi,0xfc0f84
  4c1ffc:	e8 bf 69 fe ff       	call   0x4a89c0
  4c2001:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  4c2008:	ff 
  4c2009:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  4c200d:	3b f3                	cmp    esi,ebx
  4c200f:	74 29                	je     0x4c203a
  4c2011:	8d 46 04             	lea    eax,[esi+0x4]
  4c2014:	83 c9 ff             	or     ecx,0xffffffff
  4c2017:	f0 0f c1 08          	lock xadd DWORD PTR [eax],ecx
  4c201b:	75 1d                	jne    0x4c203a
  4c201d:	8b 16                	mov    edx,DWORD PTR [esi]
  4c201f:	8b 02                	mov    eax,DWORD PTR [edx]
  4c2021:	8b ce                	mov    ecx,esi
  4c2023:	ff d0                	call   eax
  4c2025:	8d 4e 08             	lea    ecx,[esi+0x8]
  4c2028:	83 ca ff             	or     edx,0xffffffff
  4c202b:	f0 0f c1 11          	lock xadd DWORD PTR [ecx],edx
  4c202f:	75 09                	jne    0x4c203a
  4c2031:	8b 06                	mov    eax,DWORD PTR [esi]
  4c2033:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  4c2036:	8b ce                	mov    ecx,esi
  4c2038:	ff d2                	call   edx
  4c203a:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  4c203e:	64 89      	mov    DWORD PTR fs:0x0,ecx
```

## 4. 局部控制流程與資料流（指令級）

以下為本段出現的直接 call 指令節錄；**callee 的高階名稱均不自動確定**：

```asm
  4a89f0:	e8 2b 8a 3a 00       	call   0x851420
  4a8a0c:	e8 bf a9 0a 00       	call   0x5533d0
  4a8a16:	e8 ff 98 3e 00       	call   0x89231a
  4a8a36:	e8 15 c0 24 00       	call   0x6f4a50
  4a8a46:	e8 85 c3 24 00       	call   0x6f4dd0
  47ba92:	ff 15 fc 20 bd 00    	call   DWORD PTR ds:0xbd20fc
  47ba99:	ff 15 c8 21 bd 00    	call   DWORD PTR ds:0xbd21c8
  47bab3:	e8 f8 f3 ff ff       	call   0x47aeb0
  47babd:	e8 58 68 41 00       	call   0x89231a
  47bace:	e8 ed ce 02 00       	call   0x4a89c0
  47baed:	ff d0                	call   eax
  47bb02:	ff d2                	call   edx
  47bb0c:	e8 fb 56 41 00       	call   0x89120c
  4c1fad:	e8 2e bd 2d 00       	call   0x79dce0
  4c1fb7:	ff 15 fc 20 bd 00    	call   DWORD PTR ds:0xbd20fc
  4c1fbe:	ff 15 c8 21 bd 00    	call   DWORD PTR ds:0xbd21c8
  4c1fe1:	e8 ca 8e fb ff       	call   0x47aeb0
  4c1feb:	e8 2a 03 3d 00       	call   0x89231a
  4c1ffc:	e8 bf 69 fe ff       	call   0x4a89c0
  4c2023:	ff d0                	call   eax
  4c2038:	ff d2                	call   edx
```

比較、測試及分支位置（節錄）：

```asm
  4a89f5:	f6 05 54 73 fb 00 01 	test   BYTE PTR ds:0xfb7354,0x1
  4a89fc:	75 27                	jne    0x4a8a25
  4a8a5d:	c3                   	ret
  47ba9f:	f6 05 80 0f fc 00 01 	test   BYTE PTR ds:0xfc0f80,0x1
  47baa6:	75 21                	jne    0x47bac9
  47bad7:	85 ff                	test   edi,edi
  47bad9:	74 29                	je     0x47bb04
  47bae5:	75 1d                	jne    0x47bb04
  47baf9:	75 09                	jne    0x47bb04
  47bb07:	85 c0                	test   eax,eax
  47bb09:	74 09                	je     0x47bb14
  47bb25:	c2 04 00             	ret    0x4
  4c1f9a:	3d 00 83 c4 04       	cmp    eax,0x4c48300
  4c1fc4:	f6 05 80 0f fc 00 01 	test   BYTE PTR ds:0xfc0f80,0x1
  4c1fd4:	75 21                	jne    0x4c1ff7
  4c200d:	3b f3                	cmp    esi,ebx
  4c200f:	74 29                	je     0x4c203a
  4c201b:	75 1d                	jne    0x4c203a
  4c202f:	75 09                	jne    0x4c203a
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