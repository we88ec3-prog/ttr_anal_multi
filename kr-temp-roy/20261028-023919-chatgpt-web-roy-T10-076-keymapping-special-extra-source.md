# T10-076 — keymapping special extra source

- 記錄時間：2026-10-28T02:39:19+08:00
- 標的：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀靜態取證，沒有執行／附加遊戲。
- PE `.text` 映射（由本機 PE section header 核對）：VA `0x401000`、raw `0x400`，本筆記列出之 `.text` 地址使用 `raw=VA-0x400C00`。
- PE `.rdata` 映射：VA `0xBD2000`、raw `0x7D0600`，`raw=VA-0x401A00`。資料字串來自同 SHA 原始 BIN，並非推測生成。
- 先前研究：參照已提交 T10-1～68、T01 有限整合結論；本次第一手證據僅限下列 byte 與指令及明確控制流。
- 分工：T10 為輸入／普攻／連段與取消；T11 技能施放裁決僅引用。沒有修改 owner、catalog、程式或封包。
- 完成界線：本段**不代表**原版 Z/V 動作、連段取消、施放 tier 或伺服器規則全鏈已驗證。

## 研究問題及本段結果

BIN `.rdata` 同時保留 `Table/KeyMappingExtra.xml` 與 `VirualkeyExtra.dll`，`0x6D0D10` 以額外字串地址 `0xC408D8` 開啟另一種資料來源（此位址是 `Virualkey.dll` 字串）；在其流程內解析數值對並填入 `0xFB8D34`。注意 extra XML 字串與二進位 DLL 名稱不可混為一個文件。

## 可複核第一手機器碼

### VA `0x006D0D10–0x006D0DD9`（raw `0x2D0110–0x2D01D9`）

```asm
; PE .text raw window bytes: 55 8b ec 81 ec 14 01 00 00 a1 20 1f d6 00 33 c5 89 45 fc 53 68 e0 d1 be 00 8d 85 f8 fe ff ff 68 d8 08 c4 00 33 db 50 89 9d f8 fe ff ff e8 50 0b 1c 00 83 c4 0c 39 9d f8 fe ff ff 0f 84 46 01 00 00 b8 34 8d fb 00 e8 a5 f9 ff ff 68 ff 00 00 00 8d 8d fd fe ff ff 53 51 89 9d ec fe ff ff 89 9d f0 fe ff ff 88 9d fc fe ff ff e8 e1 da 1c 00 8b 95 f8 fe ff ff 52 8d 85 fc fe ff ff 68 ff 00 00 00 50 e8 81 68 1c 00 83 c4 18 85 c0 0f 84 e6 00 00 00 56 57 eb 0a 8d a4 24 00 00 00 00 8d 49 00 8d 8d f0 fe ff ff 51 8d 95 ec fe ff ff 52 8d 85 fc fe ff ff 68 e8 08 c4 00 50 e8 bd 51 1c 00 83 c4 10 83 f8 02 75 7a 8b b5 ec
; 反組譯自指定起始 VA 線性解碼；窗口起點若不在 instruction boundary，須與 caller/CFG 再核對。
  6d0d10:	55                   	push   ebp
  6d0d11:	8b ec                	mov    ebp,esp
  6d0d13:	81 ec 14 01 00 00    	sub    esp,0x114
  6d0d19:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6d0d1e:	33 c5                	xor    eax,ebp
  6d0d20:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  6d0d23:	53                   	push   ebx
  6d0d24:	68 e0 d1 be 00       	push   0xbed1e0
  6d0d29:	8d 85 f8 fe ff ff    	lea    eax,[ebp-0x108]
  6d0d2f:	68 d8 08 c4 00       	push   0xc408d8
  6d0d34:	33 db                	xor    ebx,ebx
  6d0d36:	50                   	push   eax
  6d0d37:	89 9d f8 fe ff ff    	mov    DWORD PTR [ebp-0x108],ebx
  6d0d3d:	e8 50 0b 1c 00       	call   0x891892
  6d0d42:	83 c4 0c             	add    esp,0xc
  6d0d45:	39 9d f8 fe ff ff    	cmp    DWORD PTR [ebp-0x108],ebx
  6d0d4b:	0f 84 46 01 00 00    	je     0x6d0e97
  6d0d51:	b8 34 8d fb 00       	mov    eax,0xfb8d34
  6d0d56:	e8 a5 f9 ff ff       	call   0x6d0700
  6d0d5b:	68 ff 00 00 00       	push   0xff
  6d0d60:	8d 8d fd fe ff ff    	lea    ecx,[ebp-0x103]
  6d0d66:	53                   	push   ebx
  6d0d67:	51                   	push   ecx
  6d0d68:	89 9d ec fe ff ff    	mov    DWORD PTR [ebp-0x114],ebx
  6d0d6e:	89 9d f0 fe ff ff    	mov    DWORD PTR [ebp-0x110],ebx
  6d0d74:	88 9d fc fe ff ff    	mov    BYTE PTR [ebp-0x104],bl
  6d0d7a:	e8 e1 da 1c 00       	call   0x89e860
  6d0d7f:	8b 95 f8 fe ff ff    	mov    edx,DWORD PTR [ebp-0x108]
  6d0d85:	52                   	push   edx
  6d0d86:	8d 85 fc fe ff ff    	lea    eax,[ebp-0x104]
  6d0d8c:	68 ff 00 00 00       	push   0xff
  6d0d91:	50                   	push   eax
  6d0d92:	e8 81 68 1c 00       	call   0x897618
  6d0d97:	83 c4 18             	add    esp,0x18
  6d0d9a:	85 c0                	test   eax,eax
  6d0d9c:	0f 84 e6 00 00 00    	je     0x6d0e88
  6d0da2:	56                   	push   esi
  6d0da3:	57                   	push   edi
  6d0da4:	eb 0a                	jmp    0x6d0db0
  6d0da6:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  6d0dad:	8d 49 00             	lea    ecx,[ecx+0x0]
  6d0db0:	8d 8d f0 fe ff ff    	lea    ecx,[ebp-0x110]
  6d0db6:	51                   	push   ecx
  6d0db7:	8d 95 ec fe ff ff    	lea    edx,[ebp-0x114]
  6d0dbd:	52                   	push   edx
  6d0dbe:	8d 85 fc fe ff ff    	lea    eax,[ebp-0x104]
  6d0dc4:	68 e8 08 c4 00       	push   0xc408e8
  6d0dc9:	50                   	push   eax
  6d0dca:	e8 bd 51 1c 00       	call   0x895f8c
  6d0dcf:	83 c4 10             	add    esp,0x10
  6d0dd2:	83 f8 02             	cmp    eax,0x2
  6d0dd5:	75 7a                	jne    0x6d0e51
  6d0dd7:	8b                   	.byte 0x8b
  6d0dd8:	b5 ec                	mov    ch,0xec
```

## 資料流／分支推導

1. `0xC408D8` 是 `Virualkey.dll`，直接從 `.rdata` 字節確認，不能錯認成 Extra XML。
2. 同區 `.rdata` 另有 `0xC408FC`=`Table/KeyMappingExtra.xml`、`0xC40918`=`VirualkeyExtra.dll`；是候選資料來源，需各自追明確 xref 才能斷言實際開啟。
3. `0x6D0DCA` 呼叫 `0x895F8C` 比對格式字串，`cmp eax,2` 條件後處理兩個數值候選。

## 局部 C++ 型偽碼（非原版符號／非完整函式）

```cpp
if (openCandidate(0xC408D8 /* Virualkey.dll */)) {
  while (readNumericPair(...)) { appendExtraValue(...); }
}
```

## 確定性、正反證與後續

- **已確認**：上述 address/raw 的原始 bytes 解碼與局部分支算術；字串地址以原始 `.rdata` 比對。
- **部分確認**：指標角色、資料結構屬以指令讀寫推估的局部語義，未完成所有 caller/receiver 實例的全域驗證。
- **不得推論**：此處 mapping bank 或 byte／DWORD vector 就是玩家 V 點按、V 長按時間或普攻 chain window；不能把正常資料載入視作 runtime phase writer。
- **尚待查證**：各來源路徑的真正檔案 API／載入 DLL 行為不可由名稱推出；`KeyMappingExtra.xml` 是否由其他 caller 載入待查。

## 額外靜態證據

原始 .rdata：`0xC408D8`=`Virualkey.dll`；`0xC408FC`=`Table/KeyMappingExtra.xml`；`0xC40918`=`VirualkeyExtra.dll`。

## 供下段接續

以 `0x6D08F0`、`0x6D0D10`、`0x6D1A70` 與 `0x6D4CE0` 為相互獨立的來源／消費路徑；先以同一物件與 caller 參數證明可達性，再嘗試接到玩家動作或封包。若沒有跨指標證據，必須保留缺口。