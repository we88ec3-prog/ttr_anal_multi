# T10-079 — config vs runtime phase boundary

- 記錄時間：2026-10-28T02:39:19+08:00
- 標的：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀靜態取證，沒有執行／附加遊戲。
- PE `.text` 映射（由本機 PE section header 核對）：VA `0x401000`、raw `0x400`，本筆記列出之 `.text` 地址使用 `raw=VA-0x400C00`。
- PE `.rdata` 映射：VA `0xBD2000`、raw `0x7D0600`，`raw=VA-0x401A00`。資料字串來自同 SHA 原始 BIN，並非推測生成。
- 先前研究：參照已提交 T10-1～68、T01 有限整合結論；本次第一手證據僅限下列 byte 與指令及明確控制流。
- 分工：T10 為輸入／普攻／連段與取消；T11 技能施放裁決僅引用。沒有修改 owner、catalog、程式或封包。
- 完成界線：本段**不代表**原版 Z/V 動作、連段取消、施放 tier 或伺服器規則全鏈已驗證。

## 研究問題及本段結果

已確認 `0x6D08F0`／`0x6D0D10` 有**非零映射 vector writer**；但 `0x6D4CE0` 讀取的執行時 `0xFB9004+index` 或 `0xFDF630` 節點 byte 是不同的記憶體對象。此處精確區分「找到配置表 writer」與「找到按下／放開 phase writer」。

## 可複核第一手機器碼

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

### VA `0x006D0DBE–0x006D0E4F`（raw `0x2D01BE–0x2D024F`）

```asm
; PE .text raw window bytes: 8d 85 fc fe ff ff 68 e8 08 c4 00 50 e8 bd 51 1c 00 83 c4 10 83 f8 02 75 7a 8b b5 ec fe ff ff 8b bd f0 fe ff ff c1 e6 04 81 c6 34 8d fb 00 8b 46 04 8d 8d f4 fe ff ff 89 bd f4 fe ff ff 3b c8 73 34 8b 0e 8d 95 f4 fe ff ff 3b ca 77 28 8b fa 2b f9 c1 ff 02 3b 46 08 75 0c b9 01 00 00 00 8b c6 e8 1d 54 00 00 8b 46 04 3b c3 74 23 8b 0e 8b 14 b9 89 10 eb 1a 3b 46 08 75 0c b9 01 00 00 00 8b c6 e8 fc 53 00 00 8b 46 04 3b c3 74 02 89 38 83 46 04
; 反組譯自指定起始 VA 線性解碼；窗口起點若不在 instruction boundary，須與 caller/CFG 再核對。
  6d0dbe:	8d 85 fc fe ff ff    	lea    eax,[ebp-0x104]
  6d0dc4:	68 e8 08 c4 00       	push   0xc408e8
  6d0dc9:	50                   	push   eax
  6d0dca:	e8 bd 51 1c 00       	call   0x895f8c
  6d0dcf:	83 c4 10             	add    esp,0x10
  6d0dd2:	83 f8 02             	cmp    eax,0x2
  6d0dd5:	75 7a                	jne    0x6d0e51
  6d0dd7:	8b b5 ec fe ff ff    	mov    esi,DWORD PTR [ebp-0x114]
  6d0ddd:	8b bd f0 fe ff ff    	mov    edi,DWORD PTR [ebp-0x110]
  6d0de3:	c1 e6 04             	shl    esi,0x4
  6d0de6:	81 c6 34 8d fb 00    	add    esi,0xfb8d34
  6d0dec:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  6d0def:	8d 8d f4 fe ff ff    	lea    ecx,[ebp-0x10c]
  6d0df5:	89 bd f4 fe ff ff    	mov    DWORD PTR [ebp-0x10c],edi
  6d0dfb:	3b c8                	cmp    ecx,eax
  6d0dfd:	73 34                	jae    0x6d0e33
  6d0dff:	8b 0e                	mov    ecx,DWORD PTR [esi]
  6d0e01:	8d 95 f4 fe ff ff    	lea    edx,[ebp-0x10c]
  6d0e07:	3b ca                	cmp    ecx,edx
  6d0e09:	77 28                	ja     0x6d0e33
  6d0e0b:	8b fa                	mov    edi,edx
  6d0e0d:	2b f9                	sub    edi,ecx
  6d0e0f:	c1 ff 02             	sar    edi,0x2
  6d0e12:	3b 46 08             	cmp    eax,DWORD PTR [esi+0x8]
  6d0e15:	75 0c                	jne    0x6d0e23
  6d0e17:	b9 01 00 00 00       	mov    ecx,0x1
  6d0e1c:	8b c6                	mov    eax,esi
  6d0e1e:	e8 1d 54 00 00       	call   0x6d6240
  6d0e23:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  6d0e26:	3b c3                	cmp    eax,ebx
  6d0e28:	74 23                	je     0x6d0e4d
  6d0e2a:	8b 0e                	mov    ecx,DWORD PTR [esi]
  6d0e2c:	8b 14 b9             	mov    edx,DWORD PTR [ecx+edi*4]
  6d0e2f:	89 10                	mov    DWORD PTR [eax],edx
  6d0e31:	eb 1a                	jmp    0x6d0e4d
  6d0e33:	3b 46 08             	cmp    eax,DWORD PTR [esi+0x8]
  6d0e36:	75 0c                	jne    0x6d0e44
  6d0e38:	b9 01 00 00 00       	mov    ecx,0x1
  6d0e3d:	8b c6                	mov    eax,esi
  6d0e3f:	e8 fc 53 00 00       	call   0x6d6240
  6d0e44:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  6d0e47:	3b c3                	cmp    eax,ebx
  6d0e49:	74 02                	je     0x6d0e4d
  6d0e4b:	89 38                	mov    DWORD PTR [eax],edi
  6d0e4d:	83                   	.byte 0x83
  6d0e4e:	46                   	inc    esi
  6d0e4f:	04                   	.byte 0x4
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

1. 主映射表 `0xFB8834` 附加 DWORD 到 vector；Extra 目標 `0xFB8D34` 附加 DWORD；兩種都沒有在以上指令寫入 `0xFB9004+index` 的非零 phase。
2. `0x6D4D98` 透過 `[esi+0xFB9004]` 讀取執行時 byte，`0x6D4D5D` 透過映射樹 node+0x10 讀取另一 byte。
3. 不能以同一全域地址高位元組 `0xFB` 或相鄰配置判定兩套資料型別一致；實際 alias 須指標來源證明。

## 局部 C++ 型偽碼（非原版符號／非完整函式）

```cpp
struct MappingBank { VectorDWORD slots[40]; }; // 40*0x10=0x280 (tentative)
uint8_t queryPhase(int index) { /* 0x6D4CE0; unrelated by current evidence */ }
```

## 確定性、正反證與後續

- **已確認**：上述 address/raw 的原始 bytes 解碼與局部分支算術；字串地址以原始 `.rdata` 比對。
- **部分確認**：指標角色、資料結構屬以指令讀寫推估的局部語義，未完成所有 caller/receiver 實例的全域驗證。
- **不得推論**：此處 mapping bank 或 byte／DWORD vector 就是玩家 V 點按、V 長按時間或普攻 chain window；不能把正常資料載入視作 runtime phase writer。
- **尚待查證**：仍須找出輸入事件 pump、raw keyboard callback、`0xFB9004` 間接非零寫入（alias/loop/memcpy），再連玩家 controller。


## 供下段接續

以 `0x6D08F0`、`0x6D0D10`、`0x6D1A70` 與 `0x6D4CE0` 為相互獨立的來源／消費路徑；先以同一物件與 caller 參數證明可達性，再嘗試接到玩家動作或封包。若沒有跨指標證據，必須保留缺口。