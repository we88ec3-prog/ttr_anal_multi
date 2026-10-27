# T10-080 — config to action open chain matrix

- 記錄時間：2026-10-28T02:39:19+08:00
- 標的：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀靜態取證，沒有執行／附加遊戲。
- PE `.text` 映射（由本機 PE section header 核對）：VA `0x401000`、raw `0x400`，本筆記列出之 `.text` 地址使用 `raw=VA-0x400C00`。
- PE `.rdata` 映射：VA `0xBD2000`、raw `0x7D0600`，`raw=VA-0x401A00`。資料字串來自同 SHA 原始 BIN，並非推測生成。
- 先前研究：參照已提交 T10-1～68、T01 有限整合結論；本次第一手證據僅限下列 byte 與指令及明確控制流。
- 分工：T10 為輸入／普攻／連段與取消；T11 技能施放裁決僅引用。沒有修改 owner、catalog、程式或封包。
- 完成界線：本段**不代表**原版 Z/V 動作、連段取消、施放 tier 或伺服器規則全鏈已驗證。

## 研究問題及本段結果

本批獲得完整且可核的「來源字串 → 主配置解析 → packed DWORD vector → active/default bank 選擇 → Extra DWORD 表」局部鏈。到執行時 phase、玩家 Z/X/C/V、V tap/held、普通攻擊 queue/cancel、motion writer 的連接仍未證實；不應以段號完成冒充原版玩法還原。

## 可複核第一手機器碼

### VA `0x006D0930–0x006D096A`（raw `0x2CFD30–0x2CFD6A`）

```asm
; PE .text raw window bytes: 8d 44 24 24 50 b9 88 08 c4 00 e8 f1 e4 05 00 c7 84 24 b0 00 00 00 00 00 00 00 8b 4c 24 44 bb 10 00 00 00 39 5c 24 58 73 04 8d 4c 24 44 6a 00 8d 74 24 28 e8 a8 e7 05 00 84 c0 0f
; 反組譯自指定起始 VA 線性解碼；窗口起點若不在 instruction boundary，須與 caller/CFG 再核對。
  6d0930:	8d 44 24 24          	lea    eax,[esp+0x24]
  6d0934:	50                   	push   eax
  6d0935:	b9 88 08 c4 00       	mov    ecx,0xc40888
  6d093a:	e8 f1 e4 05 00       	call   0x72ee30
  6d093f:	c7 84 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],0x0
  6d0946:	00 00 00 00 
  6d094a:	8b 4c 24 44          	mov    ecx,DWORD PTR [esp+0x44]
  6d094e:	bb 10 00 00 00       	mov    ebx,0x10
  6d0953:	39 5c 24 58          	cmp    DWORD PTR [esp+0x58],ebx
  6d0957:	73 04                	jae    0x6d095d
  6d0959:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  6d095d:	6a 00                	push   0x0
  6d095f:	8d 74 24 28          	lea    esi,[esp+0x28]
  6d0963:	e8 a8 e7 05 00       	call   0x72f110
  6d0968:	84 c0                	test   al,al
  6d096a:	0f                   	.byte 0xf
```

### VA `0x006D0B0E–0x006D0B6E`（raw `0x2CFF0E–0x2CFF6E`）

```asm
; PE .text raw window bytes: 0f b6 cb c1 e6 04 c1 e7 10 0b f9 81 c6 34 88 fb 00 8b 46 04 8d 4c 24 10 89 7c 24 10 3b c8 0f 83 c4 00 00 00 8b 0e 8d 54 24 10 3b ca 0f 87 b6 00 00 00 8b fa 2b f9 c1 ff 02 3b 46 08 75 0c b9 01 00 00 00 8b c6 e8 e8 56 00 00 8b 06 8d 0c b8 8b 46 04 85 c0 0f 84 a8 00 00 00 8b 09 89 08 e9 9f 00
; 反組譯自指定起始 VA 線性解碼；窗口起點若不在 instruction boundary，須與 caller/CFG 再核對。
  6d0b0e:	0f b6 cb             	movzx  ecx,bl
  6d0b11:	c1 e6 04             	shl    esi,0x4
  6d0b14:	c1 e7 10             	shl    edi,0x10
  6d0b17:	0b f9                	or     edi,ecx
  6d0b19:	81 c6 34 88 fb 00    	add    esi,0xfb8834
  6d0b1f:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  6d0b22:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  6d0b26:	89 7c 24 10          	mov    DWORD PTR [esp+0x10],edi
  6d0b2a:	3b c8                	cmp    ecx,eax
  6d0b2c:	0f 83 c4 00 00 00    	jae    0x6d0bf6
  6d0b32:	8b 0e                	mov    ecx,DWORD PTR [esi]
  6d0b34:	8d 54 24 10          	lea    edx,[esp+0x10]
  6d0b38:	3b ca                	cmp    ecx,edx
  6d0b3a:	0f 87 b6 00 00 00    	ja     0x6d0bf6
  6d0b40:	8b fa                	mov    edi,edx
  6d0b42:	2b f9                	sub    edi,ecx
  6d0b44:	c1 ff 02             	sar    edi,0x2
  6d0b47:	3b 46 08             	cmp    eax,DWORD PTR [esi+0x8]
  6d0b4a:	75 0c                	jne    0x6d0b58
  6d0b4c:	b9 01 00 00 00       	mov    ecx,0x1
  6d0b51:	8b c6                	mov    eax,esi
  6d0b53:	e8 e8 56 00 00       	call   0x6d6240
  6d0b58:	8b 06                	mov    eax,DWORD PTR [esi]
  6d0b5a:	8d 0c b8             	lea    ecx,[eax+edi*4]
  6d0b5d:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  6d0b60:	85 c0                	test   eax,eax
  6d0b62:	0f 84 a8 00 00 00    	je     0x6d0c10
  6d0b68:	8b 09                	mov    ecx,DWORD PTR [ecx]
  6d0b6a:	89 08                	mov    DWORD PTR [eax],ecx
  6d0b6c:	e9                   	.byte 0xe9
  6d0b6d:	9f                   	lahf
```

### VA `0x006D0C4C–0x006D0C93`（raw `0x2D004C–0x2D0093`）

```asm
; PE .text raw window bytes: a1 34 90 fb 00 85 c0 74 05 83 f8 01 75 38 8d 04 80 c1 e0 07 05 34 88 fb 00 50 eb 20 e8 43 02 00 00 a1 34 90 fb 00 85 c0 74 05 83 f8 01 75 17 8d 0c 80 c1 e1 07 81 c1 34 88 fb 00 51 68 34 8d fb 00 e8 4e 0f 00 00 c7 84
; 反組譯自指定起始 VA 線性解碼；窗口起點若不在 instruction boundary，須與 caller/CFG 再核對。
  6d0c4c:	a1 34 90 fb 00       	mov    eax,ds:0xfb9034
  6d0c51:	85 c0                	test   eax,eax
  6d0c53:	74 05                	je     0x6d0c5a
  6d0c55:	83 f8 01             	cmp    eax,0x1
  6d0c58:	75 38                	jne    0x6d0c92
  6d0c5a:	8d 04 80             	lea    eax,[eax+eax*4]
  6d0c5d:	c1 e0 07             	shl    eax,0x7
  6d0c60:	05 34 88 fb 00       	add    eax,0xfb8834
  6d0c65:	50                   	push   eax
  6d0c66:	eb 20                	jmp    0x6d0c88
  6d0c68:	e8 43 02 00 00       	call   0x6d0eb0
  6d0c6d:	a1 34 90 fb 00       	mov    eax,ds:0xfb9034
  6d0c72:	85 c0                	test   eax,eax
  6d0c74:	74 05                	je     0x6d0c7b
  6d0c76:	83 f8 01             	cmp    eax,0x1
  6d0c79:	75 17                	jne    0x6d0c92
  6d0c7b:	8d 0c 80             	lea    ecx,[eax+eax*4]
  6d0c7e:	c1 e1 07             	shl    ecx,0x7
  6d0c81:	81 c1 34 88 fb 00    	add    ecx,0xfb8834
  6d0c87:	51                   	push   ecx
  6d0c88:	68 34 8d fb 00       	push   0xfb8d34
  6d0c8d:	e8 4e 0f 00 00       	call   0x6d1be0
  6d0c92:	c7                   	.byte 0xc7
  6d0c93:	84                   	.byte 0x84
```

### VA `0x006D1A93–0x006D1B33`（raw `0x2D0E93–0x2D0F33`）

```asm
; PE .text raw window bytes: 8b 5d 08 83 fb 03 0f 8d 95 00 00 00 8d 04 9b c1 e0 07 05 34 88 fb 00 a3 2c 90 fb 00 b8 01 00 00 00 89 1d 30 90 fb 00 84 05 28 88 fb 00 75 1f 09 05 28 88 fb 00 c7 45 fc 00 00 00 00 e8 7c dd e7 ff 68 80 d5 bc 00 e8 3c 08 1c 00 83 c4 04 8a 0d eb 91 fb 00 8a c3 3a d9 76 02 8a c1 8a 0d ea 91 fb 00 3a c1 73 02 8a c1 a2 e9 91 fb 00 33 c0 a3 04 90 fb 00 a3 08 90 fb 00 a3 0c 90 fb 00 a3 10 90 fb 00 a3 14 90 fb 00 a3 18 90 fb 00 a3 1c 90 fb 00 a3 20 90 fb 00 a3 24 90 fb 00 a3 28 90 fb 00
; 反組譯自指定起始 VA 線性解碼；窗口起點若不在 instruction boundary，須與 caller/CFG 再核對。
  6d1a93:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  6d1a96:	83 fb 03             	cmp    ebx,0x3
  6d1a99:	0f 8d 95 00 00 00    	jge    0x6d1b34
  6d1a9f:	8d 04 9b             	lea    eax,[ebx+ebx*4]
  6d1aa2:	c1 e0 07             	shl    eax,0x7
  6d1aa5:	05 34 88 fb 00       	add    eax,0xfb8834
  6d1aaa:	a3 2c 90 fb 00       	mov    ds:0xfb902c,eax
  6d1aaf:	b8 01 00 00 00       	mov    eax,0x1
  6d1ab4:	89 1d 30 90 fb 00    	mov    DWORD PTR ds:0xfb9030,ebx
  6d1aba:	84 05 28 88 fb 00    	test   BYTE PTR ds:0xfb8828,al
  6d1ac0:	75 1f                	jne    0x6d1ae1
  6d1ac2:	09 05 28 88 fb 00    	or     DWORD PTR ds:0xfb8828,eax
  6d1ac8:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  6d1acf:	e8 7c dd e7 ff       	call   0x54f850
  6d1ad4:	68 80 d5 bc 00       	push   0xbcd580
  6d1ad9:	e8 3c 08 1c 00       	call   0x89231a
  6d1ade:	83 c4 04             	add    esp,0x4
  6d1ae1:	8a 0d eb 91 fb 00    	mov    cl,BYTE PTR ds:0xfb91eb
  6d1ae7:	8a c3                	mov    al,bl
  6d1ae9:	3a d9                	cmp    bl,cl
  6d1aeb:	76 02                	jbe    0x6d1aef
  6d1aed:	8a c1                	mov    al,cl
  6d1aef:	8a 0d ea 91 fb 00    	mov    cl,BYTE PTR ds:0xfb91ea
  6d1af5:	3a c1                	cmp    al,cl
  6d1af7:	73 02                	jae    0x6d1afb
  6d1af9:	8a c1                	mov    al,cl
  6d1afb:	a2 e9 91 fb 00       	mov    ds:0xfb91e9,al
  6d1b00:	33 c0                	xor    eax,eax
  6d1b02:	a3 04 90 fb 00       	mov    ds:0xfb9004,eax
  6d1b07:	a3 08 90 fb 00       	mov    ds:0xfb9008,eax
  6d1b0c:	a3 0c 90 fb 00       	mov    ds:0xfb900c,eax
  6d1b11:	a3 10 90 fb 00       	mov    ds:0xfb9010,eax
  6d1b16:	a3 14 90 fb 00       	mov    ds:0xfb9014,eax
  6d1b1b:	a3 18 90 fb 00       	mov    ds:0xfb9018,eax
  6d1b20:	a3 1c 90 fb 00       	mov    ds:0xfb901c,eax
  6d1b25:	a3 20 90 fb 00       	mov    ds:0xfb9020,eax
  6d1b2a:	a3 24 90 fb 00       	mov    ds:0xfb9024,eax
  6d1b2f:	a3 28 90 fb 00       	mov    ds:0xfb9028,eax
```

### VA `0x006D4D70–0x006D4DBE`（raw `0x2D4170–0x2D41BE`）

```asm
; PE .text raw window bytes: 84 05 14 7c fb 00 75 1b 09 05 14 7c fb 00 89 45 fc e8 ca b9 ff ff 68 30 d5 bc 00 e8 8a d5 1b 00 83 c4 04 83 fe 27 77 16 0f b6 86 04 90 fb 00 8b 4d f4 64 89 0d 00 00 00 00 59 8b e5 5d c3 33 c0 8b 4d f4 64 89 0d 00 00 00 00 59 8b e5 5d c3
; 反組譯自指定起始 VA 線性解碼；窗口起點若不在 instruction boundary，須與 caller/CFG 再核對。
  6d4d70:	84 05 14 7c fb 00    	test   BYTE PTR ds:0xfb7c14,al
  6d4d76:	75 1b                	jne    0x6d4d93
  6d4d78:	09 05 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,eax
  6d4d7e:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  6d4d81:	e8 ca b9 ff ff       	call   0x6d0750
  6d4d86:	68 30 d5 bc 00       	push   0xbcd530
  6d4d8b:	e8 8a d5 1b 00       	call   0x89231a
  6d4d90:	83 c4 04             	add    esp,0x4
  6d4d93:	83 fe 27             	cmp    esi,0x27
  6d4d96:	77 16                	ja     0x6d4dae
  6d4d98:	0f b6 86 04 90 fb 00 	movzx  eax,BYTE PTR [esi+0xfb9004]
  6d4d9f:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d4da2:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d4da9:	59                   	pop    ecx
  6d4daa:	8b e5                	mov    esp,ebp
  6d4dac:	5d                   	pop    ebp
  6d4dad:	c3                   	ret
  6d4dae:	33 c0                	xor    eax,eax
  6d4db0:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d4db3:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d4dba:	59                   	pop    ecx
  6d4dbb:	8b e5                	mov    esp,ebp
  6d4dbd:	5d                   	pop    ebp
  6d4dbe:	c3                   	ret
```

## 資料流／分支推導

1. 來源：`.rdata` `0xC40888`=`Table/KeyMapping.xml`，`0xC408C0`=`Key`，`0xC408C4`=`MapButton`，`0xC408D0`=`ModKey`。
2. loader：`0x6D08F0` 經 parser/helper 取欄位，合成32-bit DWORD 並附加至 `0xFB8834+type*0x280+row*0x10` vector。
3. bank 選用：`0x6D1A70` 設 `0xFB902C`；另一 default branch 讀 `0xFB9034` 並呼叫 `0x6D1BE0`；是否同一實際使用時機不明。
4. runtime phase：`0x6D4CE0` 僅證明一般／特殊鍵 byte 查詢，未見直接 same-object writer；需按資料擁有者追記憶體別名。
5. motion / queue / cancel：目前沒有由 `0x6D08F0` 的配置 slot 直達 actor motion 的 receiver 及 call graph，不能推時間常數或 combo 排隊機制。

## 局部 C++ 型偽碼（非原版符號／非完整函式）

```cpp
config = parseKeyMapping("Table/KeyMapping.xml");
banks = packIntoVectors(config);
active = selectBank(mode);
// UNPROVEN LINK: physical input event -> phase writer -> mapped action
// UNPROVEN LINK: action -> actor motion -> next queue / cancel -> network
```

## 確定性、正反證與後續

- **已確認**：上述 address/raw 的原始 bytes 解碼與局部分支算術；字串地址以原始 `.rdata` 比對。
- **部分確認**：指標角色、資料結構屬以指令讀寫推估的局部語義，未完成所有 caller/receiver 實例的全域驗證。
- **不得推論**：此處 mapping bank 或 byte／DWORD vector 就是玩家 V 點按、V 長按時間或普攻 chain window；不能把正常資料載入視作 runtime phase writer。
- **尚待查證**：下一段先查 `0x6D0D10` 是否真為 Extra 檔、`0x6D1BE0` 及 `0xFB8D34` 的 reader；最優先查 `0xFB902C` consumer、非零 phase writer，以及 game actor queue/cancel writer。


## 供下段接續

以 `0x6D08F0`、`0x6D0D10`、`0x6D1A70` 與 `0x6D4CE0` 為相互獨立的來源／消費路徑；先以同一物件與 caller 參數證明可達性，再嘗試接到玩家動作或封包。若沒有跨指標證據，必須保留缺口。