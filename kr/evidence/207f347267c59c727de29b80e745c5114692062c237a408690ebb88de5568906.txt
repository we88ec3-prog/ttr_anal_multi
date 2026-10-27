# T16-37 — HasQuest / HasCompletableQuest / HasScenario 解析及目的結構

- 原始研究時間（Asia/Taipei）：20261028-023112
- Source: KR `Tartaros.bin`，唯讀靜態分析，bytes=`12472320`，SHA256=`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- GitHub 起始基線：`0de4fe39719a83f38a003af8efeed6b5c9b20f90`（研究啟動時核對）
- 本段主題：HasQuest / HasCompletableQuest / HasScenario 解析及目的結構
- 界線：可確定的只有原生機器碼與本段直接解析之位址／跳躍；**不宣稱**任何原版任務 ID、NPC、完成條件、封包權威或 Lua/XML 實體內容。
- 研究方法：`objdump -D -Mintel -j .text` 依 VA 擷取原始 bytes；另外從 `.text` 扫描 `E8 rel32` 作交叉參照候選，僅經指令對齊與上下文核對後方可作控制流程證據。

## 1. 可重現基線與 PE 映射

| section | VA 起點 | file offset | 限制 |
|---|---|---|---|
| .text | `0x00401000` | `0x400` | 指令與常數候選 |
| .rdata | `0x00BD2000` | `0x007D0600` | 字串不是語義證據 |
| .data | `0x00D61000` | `0x0095E800` | static image ≠ runtime field value |

## 2. 研究範圍與函式邊界

本段截取下列 **位址視窗**，它們不必然等於完整函式；需以 prologue、返回路徑及多入口參照重新界定。總計 192 行反組譯輸出。

| start | stop (exclusive) | raw start | direct E8 candidates to start |
|---|---|---|---|
| `0x0053FD00` | `0x0053FE20` | `0x13F100` | `none found by raw E8 sweep` |
| `0x0053FEB0` | `0x0053FFB0` | `0x13F2B0` | `0x0053FDBD`, `0x0053FDD0`, `0x0053FDE1`, `0x0053FDF2` |

**注意：** raw `E8` 比對可能掃到指令中間；不得把表格所有候選自動計為真實 caller。`call [reg]`、vtable 呼叫亦不受 raw E8 掃描覆蓋。

## 3. Native assembly evidence

### `0x0053FD00` .. `0x0053FE20`

```asm
  53fd00:	3b c6                	cmp    eax,esi
  53fd02:	0f 84 16 01 00 00    	je     0x53fe1e
  53fd08:	68 d0 d1 be 00       	push   0xbed1d0
  53fd0d:	8d 78 44             	lea    edi,[eax+0x44]
  53fd10:	e8 8b 03 1f 00       	call   0x7300a0
  53fd15:	3b c6                	cmp    eax,esi
  53fd17:	74 1e                	je     0x53fd37
  53fd19:	83 c0 30             	add    eax,0x30
  53fd1c:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  53fd20:	72 02                	jb     0x53fd24
  53fd22:	8b 00                	mov    eax,DWORD PTR [eax]
  53fd24:	3b c6                	cmp    eax,esi
  53fd26:	74 0f                	je     0x53fd37
  53fd28:	50                   	push   eax
  53fd29:	e8 86 1a 35 00       	call   0x8917b4
  53fd2e:	83 c4 04             	add    esp,0x4
  53fd31:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  53fd35:	eb 04                	jmp    0x53fd3b
  53fd37:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  53fd3b:	6a 40                	push   0x40
  53fd3d:	e8 26 15 35 00       	call   0x891268
  53fd42:	83 c4 04             	add    esp,0x4
  53fd45:	3b c6                	cmp    eax,esi
  53fd47:	74 29                	je     0x53fd72
  53fd49:	89 30                	mov    DWORD PTR [eax],esi
  53fd4b:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  53fd4e:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  53fd51:	89 70 10             	mov    DWORD PTR [eax+0x10],esi
  53fd54:	89 70 14             	mov    DWORD PTR [eax+0x14],esi
  53fd57:	89 70 18             	mov    DWORD PTR [eax+0x18],esi
  53fd5a:	89 70 20             	mov    DWORD PTR [eax+0x20],esi
  53fd5d:	89 70 24             	mov    DWORD PTR [eax+0x24],esi
  53fd60:	89 70 28             	mov    DWORD PTR [eax+0x28],esi
  53fd63:	89 70 30             	mov    DWORD PTR [eax+0x30],esi
  53fd66:	89 70 34             	mov    DWORD PTR [eax+0x34],esi
  53fd69:	89 70 38             	mov    DWORD PTR [eax+0x38],esi
  53fd6c:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
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
  53fe1e:	8b 5b              	mov    ebx,DWORD PTR [ebx+0x40]
```

### `0x0053FEB0` .. `0x0053FFB0`

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
  53ffad:	83 3d e8     	cmp    DWORD PTR ds:0xfb73e8,0x0
```

## 4. 局部控制流程與資料流（指令級）

以下為本段出現的直接 call 指令節錄；**callee 的高階名稱均不自動確定**：

```asm
  53fd10:	e8 8b 03 1f 00       	call   0x7300a0
  53fd29:	e8 86 1a 35 00       	call   0x8917b4
  53fd3d:	e8 26 15 35 00       	call   0x891268
  53fd7d:	e8 5e e5 1e 00       	call   0x72e2e0
  53fd8b:	e8 50 e5 1e 00       	call   0x72e2e0
  53fd99:	e8 42 e5 1e 00       	call   0x72e2e0
  53fda9:	e8 32 e5 1e 00       	call   0x72e2e0
  53fdbd:	e8 ee 00 00 00       	call   0x53feb0
  53fdd0:	e8 db 00 00 00       	call   0x53feb0
  53fde1:	e8 ca 00 00 00       	call   0x53feb0
  53fdf2:	e8 b9 00 00 00       	call   0x53feb0
  53fe0c:	e8 0f f1 03 00       	call   0x57ef20
  53fe17:	e8 34 ea 03 00       	call   0x57e850
  53feba:	e8 21 e4 1e 00       	call   0x72e2e0
  53fecd:	ff d2                	call   edx
  53fedb:	e8 c0 01 1f 00       	call   0x7300a0
  53fef4:	e8 bb 18 35 00       	call   0x8917b4
  53ff09:	e8 72 87 f6 ff       	call   0x4a8680
  53ff24:	e8 74 29 35 00       	call   0x89289d
  53ff3a:	e8 d1 ed 3b 00       	call   0x8fed10
  53ff93:	e8 d8 01 02 00       	call   0x560170
  53ff9d:	e8 78 23 35 00       	call   0x89231a
```

比較、測試及分支位置（節錄）：

```asm
  53fd00:	3b c6                	cmp    eax,esi
  53fd02:	0f 84 16 01 00 00    	je     0x53fe1e
  53fd15:	3b c6                	cmp    eax,esi
  53fd17:	74 1e                	je     0x53fd37
  53fd1c:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  53fd20:	72 02                	jb     0x53fd24
  53fd24:	3b c6                	cmp    eax,esi
  53fd26:	74 0f                	je     0x53fd37
  53fd35:	eb 04                	jmp    0x53fd3b
  53fd45:	3b c6                	cmp    eax,esi
  53fd47:	74 29                	je     0x53fd72
  53fd70:	eb 04                	jmp    0x53fd76
  53fdb2:	85 ff                	test   edi,edi
  53fdb4:	74 0c                	je     0x53fdc2
  53fdc6:	85 f6                	test   esi,esi
  53fdc8:	74 0b                	je     0x53fdd5
  53fdd9:	85 c0                	test   eax,eax
  53fddb:	74 09                	je     0x53fde6
  53fdea:	85 c0                	test   eax,eax
  53fdec:	74 09                	je     0x53fdf7
  53fec1:	85 f6                	test   esi,esi
  53fec3:	74 51                	je     0x53ff16
  53fecf:	85 c0                	test   eax,eax
  53fed1:	74 3b                	je     0x53ff0e
  53fee0:	85 c0                	test   eax,eax
  53fee2:	74 1a                	je     0x53fefe
  53fee7:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  53feeb:	72 02                	jb     0x53feef
  53feef:	85 c0                	test   eax,eax
  53fef1:	74 0b                	je     0x53fefe
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