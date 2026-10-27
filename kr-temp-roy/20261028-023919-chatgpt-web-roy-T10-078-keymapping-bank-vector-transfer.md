# T10-078 — keymapping bank vector transfer

- 記錄時間：2026-10-28T02:39:19+08:00
- 標的：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀靜態取證，沒有執行／附加遊戲。
- PE `.text` 映射（由本機 PE section header 核對）：VA `0x401000`、raw `0x400`，本筆記列出之 `.text` 地址使用 `raw=VA-0x400C00`。
- PE `.rdata` 映射：VA `0xBD2000`、raw `0x7D0600`，`raw=VA-0x401A00`。資料字串來自同 SHA 原始 BIN，並非推測生成。
- 先前研究：參照已提交 T10-1～68、T01 有限整合結論；本次第一手證據僅限下列 byte 與指令及明確控制流。
- 分工：T10 為輸入／普攻／連段與取消；T11 技能施放裁決僅引用。沒有修改 owner、catalog、程式或封包。
- 完成界線：本段**不代表**原版 Z/V 動作、連段取消、施放 tier 或伺服器規則全鏈已驗證。

## 研究問題及本段結果

主 XML loader 在結尾依 `0xFB9034`（候選 default type）選擇 bank `0xFB8834+mode*0x280`，並以 `0x6D1BE0` 向 `0xFB8D34` 傳遞 vector 資料；另一分支先呼叫 fallback builder，再使用相同選擇。這是配置 bank→輸出表的靜態證據。

## 可複核第一手機器碼

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

### VA `0x006D1BE0–0x006D1C8A`（raw `0x2D0FE0–0x2D108A`）

```asm
; PE .text raw window bytes: 55 8b ec 83 ec 0c 8b 4d 08 53 8b 5d 0c 8b c3 56 2b d9 57 c7 45 f8 00 00 00 00 89 45 0c 8d 71 04 89 5d fc 8d 4e fc 3b c8 0f 84 29 01 00 00 8b 0c 33 8b 00 8b d1 2b d0 c1 fa 02 85 d2 75 32 8b 0e 8b 7e fc 3b f9 0f 84 0c 01 00 00 8b c1 2b c1 c1 f8 02 03 c0 03 c0 50 51 57 89 45 f4 e8 af f6 1b 00 8b 55 f4 83 c4 0c 03 d7 89 16 e9 e7 00 00 00 8b 5e fc 8b 3e 2b fb c1 ff 02 3b d7 77 2d 2b c8 c1 f9 02 03 c9 03 c9 51 50 53 e8 81 f6 1b 00 8b 5d fc 8b 04 33 8b 4d 0c 2b 01 8b 56 fc 83 c4 0c c1 f8 02 8d 04 82 e9 aa 00 00 00
; 反組譯自指定起始 VA 線性解碼；窗口起點若不在 instruction boundary，須與 caller/CFG 再核對。
  6d1be0:	55                   	push   ebp
  6d1be1:	8b ec                	mov    ebp,esp
  6d1be3:	83 ec 0c             	sub    esp,0xc
  6d1be6:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  6d1be9:	53                   	push   ebx
  6d1bea:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  6d1bed:	8b c3                	mov    eax,ebx
  6d1bef:	56                   	push   esi
  6d1bf0:	2b d9                	sub    ebx,ecx
  6d1bf2:	57                   	push   edi
  6d1bf3:	c7 45 f8 00 00 00 00 	mov    DWORD PTR [ebp-0x8],0x0
  6d1bfa:	89 45 0c             	mov    DWORD PTR [ebp+0xc],eax
  6d1bfd:	8d 71 04             	lea    esi,[ecx+0x4]
  6d1c00:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d1c03:	8d 4e fc             	lea    ecx,[esi-0x4]
  6d1c06:	3b c8                	cmp    ecx,eax
  6d1c08:	0f 84 29 01 00 00    	je     0x6d1d37
  6d1c0e:	8b 0c 33             	mov    ecx,DWORD PTR [ebx+esi*1]
  6d1c11:	8b 00                	mov    eax,DWORD PTR [eax]
  6d1c13:	8b d1                	mov    edx,ecx
  6d1c15:	2b d0                	sub    edx,eax
  6d1c17:	c1 fa 02             	sar    edx,0x2
  6d1c1a:	85 d2                	test   edx,edx
  6d1c1c:	75 32                	jne    0x6d1c50
  6d1c1e:	8b 0e                	mov    ecx,DWORD PTR [esi]
  6d1c20:	8b 7e fc             	mov    edi,DWORD PTR [esi-0x4]
  6d1c23:	3b f9                	cmp    edi,ecx
  6d1c25:	0f 84 0c 01 00 00    	je     0x6d1d37
  6d1c2b:	8b c1                	mov    eax,ecx
  6d1c2d:	2b c1                	sub    eax,ecx
  6d1c2f:	c1 f8 02             	sar    eax,0x2
  6d1c32:	03 c0                	add    eax,eax
  6d1c34:	03 c0                	add    eax,eax
  6d1c36:	50                   	push   eax
  6d1c37:	51                   	push   ecx
  6d1c38:	57                   	push   edi
  6d1c39:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  6d1c3c:	e8 af f6 1b 00       	call   0x8912f0
  6d1c41:	8b 55 f4             	mov    edx,DWORD PTR [ebp-0xc]
  6d1c44:	83 c4 0c             	add    esp,0xc
  6d1c47:	03 d7                	add    edx,edi
  6d1c49:	89 16                	mov    DWORD PTR [esi],edx
  6d1c4b:	e9 e7 00 00 00       	jmp    0x6d1d37
  6d1c50:	8b 5e fc             	mov    ebx,DWORD PTR [esi-0x4]
  6d1c53:	8b 3e                	mov    edi,DWORD PTR [esi]
  6d1c55:	2b fb                	sub    edi,ebx
  6d1c57:	c1 ff 02             	sar    edi,0x2
  6d1c5a:	3b d7                	cmp    edx,edi
  6d1c5c:	77 2d                	ja     0x6d1c8b
  6d1c5e:	2b c8                	sub    ecx,eax
  6d1c60:	c1 f9 02             	sar    ecx,0x2
  6d1c63:	03 c9                	add    ecx,ecx
  6d1c65:	03 c9                	add    ecx,ecx
  6d1c67:	51                   	push   ecx
  6d1c68:	50                   	push   eax
  6d1c69:	53                   	push   ebx
  6d1c6a:	e8 81 f6 1b 00       	call   0x8912f0
  6d1c6f:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  6d1c72:	8b 04 33             	mov    eax,DWORD PTR [ebx+esi*1]
  6d1c75:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  6d1c78:	2b 01                	sub    eax,DWORD PTR [ecx]
  6d1c7a:	8b 56 fc             	mov    edx,DWORD PTR [esi-0x4]
  6d1c7d:	83 c4 0c             	add    esp,0xc
  6d1c80:	c1 f8 02             	sar    eax,0x2
  6d1c83:	8d 04 82             	lea    eax,[edx+eax*4]
  6d1c86:	e9 aa 00 00 00       	jmp    0x6d1d35
```

## 資料流／分支推導

1. `0x6D0C4C` 讀 `0xFB9034` 且只對0或1作輸入分支，`mode*0x280` 計算與 active bank 的 caller 概念不同。
2. `0x6D0C88 push 0xFB8D34` 與上一步的計算 bank pointer 一起給 `0x6D1BE0`；callee 進行按指標差計算的 DWORD 序列複製。
3. `0x6D1BE0` 的 ABI 與完整迭代上限未驗收；不能單憑 caller 視為 deep copy 或最新設定對所有玩家動作生效。

## 局部 C++ 型偽碼（非原版符號／非完整函式）

```cpp
if (defaultType == 0 || defaultType == 1) {
 auto src = 0xFB8834 + defaultType*0x280;
 copyOrMergeMapping(0x6D1BE0, 0xFB8D34, src);
}
```

## 確定性、正反證與後續

- **已確認**：上述 address/raw 的原始 bytes 解碼與局部分支算術；字串地址以原始 `.rdata` 比對。
- **部分確認**：指標角色、資料結構屬以指令讀寫推估的局部語義，未完成所有 caller/receiver 實例的全域驗證。
- **不得推論**：此處 mapping bank 或 byte／DWORD vector 就是玩家 V 點按、V 長按時間或普攻 chain window；不能把正常資料載入視作 runtime phase writer。
- **尚待查證**：沿 `0xFB8D34` 消費者追蹤輸出 mapping 成功後的讀取，並驗證 `0x6D1BE0` 所有別名處理。


## 供下段接續

以 `0x6D08F0`、`0x6D0D10`、`0x6D1A70` 與 `0x6D4CE0` 為相互獨立的來源／消費路徑；先以同一物件與 caller 參數證明可達性，再嘗試接到玩家動作或封包。若沒有跨指標證據，必須保留缺口。