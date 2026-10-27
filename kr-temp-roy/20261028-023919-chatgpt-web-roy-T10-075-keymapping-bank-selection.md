# T10-075 — keymapping bank selection

- 記錄時間：2026-10-28T02:39:19+08:00
- 標的：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀靜態取證，沒有執行／附加遊戲。
- PE `.text` 映射（由本機 PE section header 核對）：VA `0x401000`、raw `0x400`，本筆記列出之 `.text` 地址使用 `raw=VA-0x400C00`。
- PE `.rdata` 映射：VA `0xBD2000`、raw `0x7D0600`，`raw=VA-0x401A00`。資料字串來自同 SHA 原始 BIN，並非推測生成。
- 先前研究：參照已提交 T10-1～68、T01 有限整合結論；本次第一手證據僅限下列 byte 與指令及明確控制流。
- 分工：T10 為輸入／普攻／連段與取消；T11 技能施放裁決僅引用。沒有修改 owner、catalog、程式或封包。
- 完成界線：本段**不代表**原版 Z/V 動作、連段取消、施放 tier 或伺服器規則全鏈已驗證。

## 研究問題及本段結果

`0x6D1A70` 依模式參數 `mode` 計算 `0xFB8834+mode*0x280`，寫入 `0xFB902C`，另把模式存 `0xFB9030`；這是映射 bank 切換，比直接綁固定 VK_Z 更符合使用者可自訂鍵位的實際需求。

## 可複核第一手機器碼

### VA `0x006D1A70–0x006D1B44`（raw `0x2D0E70–0x2D0F44`）

```asm
; PE .text raw window bytes: 55 8b ec 6a ff 68 2e ab 90 00 64 a1 00 00 00 00 50 53 a1 20 1f d6 00 33 c5 50 8d 45 f4 64 a3 00 00 00 00 8b 5d 08 83 fb 03 0f 8d 95 00 00 00 8d 04 9b c1 e0 07 05 34 88 fb 00 a3 2c 90 fb 00 b8 01 00 00 00 89 1d 30 90 fb 00 84 05 28 88 fb 00 75 1f 09 05 28 88 fb 00 c7 45 fc 00 00 00 00 e8 7c dd e7 ff 68 80 d5 bc 00 e8 3c 08 1c 00 83 c4 04 8a 0d eb 91 fb 00 8a c3 3a d9 76 02 8a c1 8a 0d ea 91 fb 00 3a c1 73 02 8a c1 a2 e9 91 fb 00 33 c0 a3 04 90 fb 00 a3 08 90 fb 00 a3 0c 90 fb 00 a3 10 90 fb 00 a3 14 90 fb 00 a3 18 90 fb 00 a3 1c 90 fb 00 a3 20 90 fb 00 a3 24 90 fb 00 a3 28 90 fb 00 8b 4d f4 64 89 0d 00 00 00 00 59 5b 8b e5 5d c2 04
; 反組譯自指定起始 VA 線性解碼；窗口起點若不在 instruction boundary，須與 caller/CFG 再核對。
  6d1a70:	55                   	push   ebp
  6d1a71:	8b ec                	mov    ebp,esp
  6d1a73:	6a ff                	push   0xffffffff
  6d1a75:	68 2e ab 90 00       	push   0x90ab2e
  6d1a7a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  6d1a80:	50                   	push   eax
  6d1a81:	53                   	push   ebx
  6d1a82:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6d1a87:	33 c5                	xor    eax,ebp
  6d1a89:	50                   	push   eax
  6d1a8a:	8d 45 f4             	lea    eax,[ebp-0xc]
  6d1a8d:	64 a3 00 00 00 00    	mov    fs:0x0,eax
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
  6d1b34:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  6d1b37:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  6d1b3e:	59                   	pop    ecx
  6d1b3f:	5b                   	pop    ebx
  6d1b40:	8b e5                	mov    esp,ebp
  6d1b42:	5d                   	pop    ebp
  6d1b43:	c2                   	.byte 0xc2
  6d1b44:	04                   	.byte 0x4
```

## 資料流／分支推導

1. `cmp ebx,3`、`jge 0x6D1B34` 只明確表示 signed mode>=3 不進選擇；對負值的檢查不能在此函式單獨證明。
2. bank 地址由 `lea eax,[ebx+ebx*4]; shl eax,7; add eax,0xFB8834` 算出。
3. 同路徑寫 `0xFB91E9` 的模式／類型 byte，並清除 `0xFB9004...0xFB9028`；這反映設定切換可能引發狀態重置，仍不證 V held。

## 局部 C++ 型偽碼（非原版符號／非完整函式）

```cpp
if (mode < 3) { // lower-bound validation at caller unresolved
  activeBank = 0xFB8834 + mode*0x280;
  activeMode = mode;
  resetIndexedPhaseBytes();
}
```

## 確定性、正反證與後續

- **已確認**：上述 address/raw 的原始 bytes 解碼與局部分支算術；字串地址以原始 `.rdata` 比對。
- **部分確認**：指標角色、資料結構屬以指令讀寫推估的局部語義，未完成所有 caller/receiver 實例的全域驗證。
- **不得推論**：此處 mapping bank 或 byte／DWORD vector 就是玩家 V 點按、V 長按時間或普攻 chain window；不能把正常資料載入視作 runtime phase writer。
- **尚待查證**：尋找對 `0x6D1A70` 的 caller、模式值來源及 `0xFB902C` 的 consumer，證明玩家設定何時生效。


## 供下段接續

以 `0x6D08F0`、`0x6D0D10`、`0x6D1A70` 與 `0x6D4CE0` 為相互獨立的來源／消費路徑；先以同一物件與 caller 參數證明可達性，再嘗試接到玩家動作或封包。若沒有跨指標證據，必須保留缺口。