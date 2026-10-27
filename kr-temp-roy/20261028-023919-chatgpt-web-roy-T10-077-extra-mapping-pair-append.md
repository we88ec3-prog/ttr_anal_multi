# T10-077 — extra mapping pair append

- 記錄時間：2026-10-28T02:39:19+08:00
- 標的：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀靜態取證，沒有執行／附加遊戲。
- PE `.text` 映射（由本機 PE section header 核對）：VA `0x401000`、raw `0x400`，本筆記列出之 `.text` 地址使用 `raw=VA-0x400C00`。
- PE `.rdata` 映射：VA `0xBD2000`、raw `0x7D0600`，`raw=VA-0x401A00`。資料字串來自同 SHA 原始 BIN，並非推測生成。
- 先前研究：參照已提交 T10-1～68、T01 有限整合結論；本次第一手證據僅限下列 byte 與指令及明確控制流。
- 分工：T10 為輸入／普攻／連段與取消；T11 技能施放裁決僅引用。沒有修改 owner、catalog、程式或封包。
- 完成界線：本段**不代表**原版 Z/V 動作、連段取消、施放 tier 或伺服器規則全鏈已驗證。

## 研究問題及本段結果

額外來源解析兩個整數後，以第一整數 `<<4` 決定 `0xFB8D34` 的 vector slot，再把第二個整數作為 DWORD 附加；此配置與 main `0xFB8834` bank 不同。

## 可複核第一手機器碼

### VA `0x006D0DBE–0x006D0E51`（raw `0x2D01BE–0x2D0251`）

```asm
; PE .text raw window bytes: 8d 85 fc fe ff ff 68 e8 08 c4 00 50 e8 bd 51 1c 00 83 c4 10 83 f8 02 75 7a 8b b5 ec fe ff ff 8b bd f0 fe ff ff c1 e6 04 81 c6 34 8d fb 00 8b 46 04 8d 8d f4 fe ff ff 89 bd f4 fe ff ff 3b c8 73 34 8b 0e 8d 95 f4 fe ff ff 3b ca 77 28 8b fa 2b f9 c1 ff 02 3b 46 08 75 0c b9 01 00 00 00 8b c6 e8 1d 54 00 00 8b 46 04 3b c3 74 23 8b 0e 8b 14 b9 89 10 eb 1a 3b 46 08 75 0c b9 01 00 00 00 8b c6 e8 fc 53 00 00 8b 46 04 3b c3 74 02 89 38 83 46 04 04 68
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
  6d0e4d:	83 46 04 04          	add    DWORD PTR [esi+0x4],0x4
  6d0e51:	68                   	.byte 0x68
```

### VA `0x006D0E51–0x006D0E9D`（raw `0x2D0251–0x2D029D`）

```asm
; PE .text raw window bytes: 68 00 01 00 00 8d 85 fc fe ff ff 53 50 e8 fd d9 1c 00 8b 8d f8 fe ff ff 51 8d 95 fc fe ff ff 68 ff 00 00 00 52 e8 9d 67 1c 00 83 c4 18 85 c0 0f 85 2a ff ff ff 5f 5e 8b 85 f8 fe ff ff 50 e8 35 0e 1c 00 83 c4 04 8b 4d fc 33 cd 5b e8
; 反組譯自指定起始 VA 線性解碼；窗口起點若不在 instruction boundary，須與 caller/CFG 再核對。
  6d0e51:	68 00 01 00 00       	push   0x100
  6d0e56:	8d 85 fc fe ff ff    	lea    eax,[ebp-0x104]
  6d0e5c:	53                   	push   ebx
  6d0e5d:	50                   	push   eax
  6d0e5e:	e8 fd d9 1c 00       	call   0x89e860
  6d0e63:	8b 8d f8 fe ff ff    	mov    ecx,DWORD PTR [ebp-0x108]
  6d0e69:	51                   	push   ecx
  6d0e6a:	8d 95 fc fe ff ff    	lea    edx,[ebp-0x104]
  6d0e70:	68 ff 00 00 00       	push   0xff
  6d0e75:	52                   	push   edx
  6d0e76:	e8 9d 67 1c 00       	call   0x897618
  6d0e7b:	83 c4 18             	add    esp,0x18
  6d0e7e:	85 c0                	test   eax,eax
  6d0e80:	0f 85 2a ff ff ff    	jne    0x6d0db0
  6d0e86:	5f                   	pop    edi
  6d0e87:	5e                   	pop    esi
  6d0e88:	8b 85 f8 fe ff ff    	mov    eax,DWORD PTR [ebp-0x108]
  6d0e8e:	50                   	push   eax
  6d0e8f:	e8 35 0e 1c 00       	call   0x891cc9
  6d0e94:	83 c4 04             	add    esp,0x4
  6d0e97:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  6d0e9a:	33 cd                	xor    ecx,ebp
  6d0e9c:	5b                   	pop    ebx
  6d0e9d:	e8                   	.byte 0xe8
```

## 資料流／分支推導

1. `0x6D0DD2 cmp eax,2` 為兩欄解析成功的檢查；`0x6D0DE3 shl esi,4`、`0x6D0DE6 add esi,0xFB8D34` 定位 slot。
2. 使用 `[esi]`、`[esi+4]`、`[esi+8]` 三 pointer 邏輯和 `0x6D6240` capacity grow helper；此處 append 的是第二整數 DWORD，而非 mode+flag packed 值。
3. slot index 的合法上界、從何種來源來的整數和資料完整性檢查仍缺，不可推成客戶端動作列表。

## 局部 C++ 型偽碼（非原版符號／非完整函式）

```cpp
slot = extraMappingSlots + firstNumber*0x10;
if (slot.end == slot.capacity) grow(slot,1);
*slot.end++ = secondNumber;
```

## 確定性、正反證與後續

- **已確認**：上述 address/raw 的原始 bytes 解碼與局部分支算術；字串地址以原始 `.rdata` 比對。
- **部分確認**：指標角色、資料結構屬以指令讀寫推估的局部語義，未完成所有 caller/receiver 實例的全域驗證。
- **不得推論**：此處 mapping bank 或 byte／DWORD vector 就是玩家 V 點按、V 長按時間或普攻 chain window；不能把正常資料載入視作 runtime phase writer。
- **尚待查證**：需要 `0xFB8D34` 的 downstream reader 與真正的額外檔載入 API；不得將第1整數固定認作 Z/V。


## 供下段接續

以 `0x6D08F0`、`0x6D0D10`、`0x6D1A70` 與 `0x6D4CE0` 為相互獨立的來源／消費路徑；先以同一物件與 caller 參數證明可達性，再嘗試接到玩家動作或封包。若沒有跨指標證據，必須保留缺口。