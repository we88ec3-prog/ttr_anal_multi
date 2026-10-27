# T10-071 — keymapping bank stride index

- 記錄時間：2026-10-28T02:39:19+08:00
- 標的：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀靜態取證，沒有執行／附加遊戲。
- PE `.text` 映射（由本機 PE section header 核對）：VA `0x401000`、raw `0x400`，本筆記列出之 `.text` 地址使用 `raw=VA-0x400C00`。
- PE `.rdata` 映射：VA `0xBD2000`、raw `0x7D0600`，`raw=VA-0x401A00`。資料字串來自同 SHA 原始 BIN，並非推測生成。
- 先前研究：參照已提交 T10-1～68、T01 有限整合結論；本次第一手證據僅限下列 byte 與指令及明確控制流。
- 分工：T10 為輸入／普攻／連段與取消；T11 技能施放裁決僅引用。沒有修改 owner、catalog、程式或封包。
- 完成界線：本段**不代表**原版 Z/V 動作、連段取消、施放 tier 或伺服器規則全鏈已驗證。

## 研究問題及本段結果

主檔讀取者把一個維度乘 `0x280`，另一維乘 `0x10`，以 `0xFB8834` 作 bank 基址，再取該 slot 的 DWORD vector header；這是高價值的映射資料布局證據，但 slot index 不應當成遊戲 action id。

## 可複核第一手機器碼

### VA `0x006D0A2C–0x006D0A56`（raw `0x2CFE2C–0x2CFE56`）

```asm
; PE .text raw window bytes: bf c0 08 c4 00 8b c3 e8 28 d9 05 00 89 44 24 14 85 c0 0f 84 ee 01 00 00 8d 34 b6 03 f6 03 f6 03 f6 89 74 24 20 8b b0 94 00 00 00
; 反組譯自指定起始 VA 線性解碼；窗口起點若不在 instruction boundary，須與 caller/CFG 再核對。
  6d0a2c:	bf c0 08 c4 00       	mov    edi,0xc408c0
  6d0a31:	8b c3                	mov    eax,ebx
  6d0a33:	e8 28 d9 05 00       	call   0x72e360
  6d0a38:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  6d0a3c:	85 c0                	test   eax,eax
  6d0a3e:	0f 84 ee 01 00 00    	je     0x6d0c32
  6d0a44:	8d 34 b6             	lea    esi,[esi+esi*4]
  6d0a47:	03 f6                	add    esi,esi
  6d0a49:	03 f6                	add    esi,esi
  6d0a4b:	03 f6                	add    esi,esi
  6d0a4d:	89 74 24 20          	mov    DWORD PTR [esp+0x20],esi
  6d0a51:	8b b0 94 00 00 00    	mov    esi,DWORD PTR [eax+0x94]
```

### VA `0x006D0AFE–0x006D0B50`（raw `0x2CFEFE–0x2CFF50`）

```asm
; PE .text raw window bytes: 33 c0 8b 74 24 20 0f b6 f8 8b 44 24 1c 8d 34 06 0f b6 cb c1 e6 04 c1 e7 10 0b f9 81 c6 34 88 fb 00 8b 46 04 8d 4c 24 10 89 7c 24 10 3b c8 0f 83 c4 00 00 00 8b 0e 8d 54 24 10 3b ca 0f 87 b6 00 00 00 8b fa 2b f9 c1 ff 02 3b 46 08 75 0c b9 01 00 00 00
; 反組譯自指定起始 VA 線性解碼；窗口起點若不在 instruction boundary，須與 caller/CFG 再核對。
  6d0afe:	33 c0                	xor    eax,eax
  6d0b00:	8b 74 24 20          	mov    esi,DWORD PTR [esp+0x20]
  6d0b04:	0f b6 f8             	movzx  edi,al
  6d0b07:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  6d0b0b:	8d 34 06             	lea    esi,[esi+eax*1]
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
```

## 資料流／分支推導

1. `lea esi,[esi+esi*4]` 與三次 `add esi,esi` 給出 `esi*40`，隨後 `shl esi,4`，總倍率 `0x280`，並加上另一個 row 索引的 `0x10` 與基址。
2. `0x6D0B19 add esi,0xFB8834` 是 slot 起點；`[esi]`、`[esi+4]`、`[esi+8]` 行為符合 vector begin/end/capacity（暫定）。
3. 資料來源是 XML 解析，不能視為 `0xFB9004 + index` 的執行時 phase byte writer。

## 局部 C++ 型偽碼（非原版符號／非完整函式）

```cpp
uint32_t* bankSlot = (uint32_t*)(0xFB8834 + typeIndex*0x280 + rowIndex*0x10);
// slot stores 3-pointer vector header; fourth DWORD still requires lifecycle verification
```

## 確定性、正反證與後續

- **已確認**：上述 address/raw 的原始 bytes 解碼與局部分支算術；字串地址以原始 `.rdata` 比對。
- **部分確認**：指標角色、資料結構屬以指令讀寫推估的局部語義，未完成所有 caller/receiver 實例的全域驗證。
- **不得推論**：此處 mapping bank 或 byte／DWORD vector 就是玩家 V 點按、V 長按時間或普攻 chain window；不能把正常資料載入視作 runtime phase writer。
- **尚待查證**：`rowIndex` 合法上限與第 4 個 DWORD 的職責尚未完整封閉。


## 供下段接續

以 `0x6D08F0`、`0x6D0D10`、`0x6D1A70` 與 `0x6D4CE0` 為相互獨立的來源／消費路徑；先以同一物件與 caller 參數證明可達性，再嘗試接到玩家動作或封包。若沒有跨指標證據，必須保留缺口。