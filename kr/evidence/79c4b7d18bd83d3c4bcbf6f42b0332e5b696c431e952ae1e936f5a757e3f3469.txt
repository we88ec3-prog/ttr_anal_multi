# T10-072 — keymapping vector append

- 記錄時間：2026-10-28T02:39:19+08:00
- 標的：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀靜態取證，沒有執行／附加遊戲。
- PE `.text` 映射（由本機 PE section header 核對）：VA `0x401000`、raw `0x400`，本筆記列出之 `.text` 地址使用 `raw=VA-0x400C00`。
- PE `.rdata` 映射：VA `0xBD2000`、raw `0x7D0600`，`raw=VA-0x401A00`。資料字串來自同 SHA 原始 BIN，並非推測生成。
- 先前研究：參照已提交 T10-1～68、T01 有限整合結論；本次第一手證據僅限下列 byte 與指令及明確控制流。
- 分工：T10 為輸入／普攻／連段與取消；T11 技能施放裁決僅引用。沒有修改 owner、catalog、程式或封包。
- 完成界線：本段**不代表**原版 Z/V 動作、連段取消、施放 tier 或伺服器規則全鏈已驗證。

## 研究問題及本段結果

`0x6D0B1F～0x6D0C18` 在映射 slot 上操作 begin/end/capacity，必要時呼叫 `0x6D6240`，將組合的 DWORD 元素寫入 vector。這是**非零資料寫入證據**，但其接收者是 key-mapping vector，不是 runtime phase。

## 可複核第一手機器碼

### VA `0x006D0B0E–0x006D0B6F`（raw `0x2CFF0E–0x2CFF6F`）

```asm
; PE .text raw window bytes: 0f b6 cb c1 e6 04 c1 e7 10 0b f9 81 c6 34 88 fb 00 8b 46 04 8d 4c 24 10 89 7c 24 10 3b c8 0f 83 c4 00 00 00 8b 0e 8d 54 24 10 3b ca 0f 87 b6 00 00 00 8b fa 2b f9 c1 ff 02 3b 46 08 75 0c b9 01 00 00 00 8b c6 e8 e8 56 00 00 8b 06 8d 0c b8 8b 46 04 85 c0 0f 84 a8 00 00 00 8b 09 89 08 e9 9f 00 00
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

### VA `0x006D0BF6–0x006D0C27`（raw `0x2CFFF6–0x2D0027`）

```asm
; PE .text raw window bytes: 3b 46 08 75 0c b9 01 00 00 00 8b c6 e8 39 56 00 00 8b 46 04 85 c0 74 02 89 38 8b 44 24 14 83 46 04 04 bf c0 08 c4 00 e8 9e d7 05 00 89 44 24 14 85 c0
; 反組譯自指定起始 VA 線性解碼；窗口起點若不在 instruction boundary，須與 caller/CFG 再核對。
  6d0bf6:	3b 46 08             	cmp    eax,DWORD PTR [esi+0x8]
  6d0bf9:	75 0c                	jne    0x6d0c07
  6d0bfb:	b9 01 00 00 00       	mov    ecx,0x1
  6d0c00:	8b c6                	mov    eax,esi
  6d0c02:	e8 39 56 00 00       	call   0x6d6240
  6d0c07:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  6d0c0a:	85 c0                	test   eax,eax
  6d0c0c:	74 02                	je     0x6d0c10
  6d0c0e:	89 38                	mov    DWORD PTR [eax],edi
  6d0c10:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  6d0c14:	83 46 04 04          	add    DWORD PTR [esi+0x4],0x4
  6d0c18:	bf c0 08 c4 00       	mov    edi,0xc408c0
  6d0c1d:	e8 9e d7 05 00       	call   0x72e3c0
  6d0c22:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  6d0c26:	85 c0                	test   eax,eax
```

## 資料流／分支推導

1. `0x6D0B14 shl edi,0x10` 與 `or edi,ecx` 組合一個 32-bit 值；具體 bit 欄位以暫存器來源限定。
2. 若 end==capacity，在 `0x6D0B53` 或 `0x6D0C02` 呼叫 `0x6D6240` 以增加空間；兩個路徑各有寫入與 `end +=4`。
3. 這種 append 發生於 XML 載入分支，不能直接解釋點按／長按的 frame phase。

## 局部 C++ 型偽碼（非原版符號／非完整函式）

```cpp
uint32_t packed = (modifierCandidate<<16) | buttonCandidate; // variable roles tentative
if (slot.end == slot.capacity) reserveLike(0x6D6240, &slot, 1);
*slot.end++ = packed;
```

## 確定性、正反證與後續

- **已確認**：上述 address/raw 的原始 bytes 解碼與局部分支算術；字串地址以原始 `.rdata` 比對。
- **部分確認**：指標角色、資料結構屬以指令讀寫推估的局部語義，未完成所有 caller/receiver 實例的全域驗證。
- **不得推論**：此處 mapping bank 或 byte／DWORD vector 就是玩家 V 點按、V 長按時間或普攻 chain window；不能把正常資料載入視作 runtime phase writer。
- **尚待查證**：需追 `0x6D6240` 的 allocator / copy path，並由 downstream consumer 核實 packed 位元域與 action id。


## 供下段接續

以 `0x6D08F0`、`0x6D0D10`、`0x6D1A70` 與 `0x6D4CE0` 為相互獨立的來源／消費路徑；先以同一物件與 caller 參數證明可達性，再嘗試接到玩家動作或封包。若沒有跨指標證據，必須保留缺口。