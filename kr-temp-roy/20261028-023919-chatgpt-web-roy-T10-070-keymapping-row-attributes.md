# T10-070 — keymapping row attributes

- 記錄時間：2026-10-28T02:39:19+08:00
- 標的：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀靜態取證，沒有執行／附加遊戲。
- PE `.text` 映射（由本機 PE section header 核對）：VA `0x401000`、raw `0x400`，本筆記列出之 `.text` 地址使用 `raw=VA-0x400C00`。
- PE `.rdata` 映射：VA `0xBD2000`、raw `0x7D0600`，`raw=VA-0x401A00`。資料字串來自同 SHA 原始 BIN，並非推測生成。
- 先前研究：參照已提交 T10-1～68、T01 有限整合結論；本次第一手證據僅限下列 byte 與指令及明確控制流。
- 分工：T10 為輸入／普攻／連段與取消；T11 技能施放裁決僅引用。沒有修改 owner、catalog、程式或封包。
- 完成界線：本段**不代表**原版 Z/V 動作、連段取消、施放 tier 或伺服器規則全鏈已驗證。

## 研究問題及本段結果

主配置讀取函式在 `0x6D0A2C` 以 `Type`／`Key`／`MapButton`／`ModKey` 等字串查詢列資料，並以轉整數 helper `0x8917B4` 產生數值欄位。其迴圈依 XML node 分支與比較退出，不能光看表名就把行索引換成 Z 或 V。

## 可複核第一手機器碼

### VA `0x006D0A2C–0x006D0ACE`（raw `0x2CFE2C–0x2CFECE`）

```asm
; PE .text raw window bytes: bf c0 08 c4 00 8b c3 e8 28 d9 05 00 89 44 24 14 85 c0 0f 84 ee 01 00 00 8d 34 b6 03 f6 03 f6 03 f6 89 74 24 20 8b b0 94 00 00 00 8d 78 44 bb 10 00 00 00 89 7c 24 10 3b f7 74 27 39 5e 28 8d 46 14 72 02 8b 00 68 c4 08 c4 00 50 e8 35 32 1c 00 83 c4 08 85 c0 0f 84 f1 00 00 00 8b 76 50 3b f7 75 d9 c7 44 24 1c 00 00 00 00 8b 77 50 3b f7 74 2a 8d 49 00 39 5e 28 8d 46 14 72 02 8b 00 68 c0 08 c4 00 50 e8 fc 31 1c 00 83 c4 08 85 c0 0f 84 e4 00 00 00 8b 76 50 3b f7 75 d9 33 db 8b 77 50 3b f7 74
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
  6d0a57:	8d 78 44             	lea    edi,[eax+0x44]
  6d0a5a:	bb 10 00 00 00       	mov    ebx,0x10
  6d0a5f:	89 7c 24 10          	mov    DWORD PTR [esp+0x10],edi
  6d0a63:	3b f7                	cmp    esi,edi
  6d0a65:	74 27                	je     0x6d0a8e
  6d0a67:	39 5e 28             	cmp    DWORD PTR [esi+0x28],ebx
  6d0a6a:	8d 46 14             	lea    eax,[esi+0x14]
  6d0a6d:	72 02                	jb     0x6d0a71
  6d0a6f:	8b 00                	mov    eax,DWORD PTR [eax]
  6d0a71:	68 c4 08 c4 00       	push   0xc408c4
  6d0a76:	50                   	push   eax
  6d0a77:	e8 35 32 1c 00       	call   0x893cb1
  6d0a7c:	83 c4 08             	add    esp,0x8
  6d0a7f:	85 c0                	test   eax,eax
  6d0a81:	0f 84 f1 00 00 00    	je     0x6d0b78
  6d0a87:	8b 76 50             	mov    esi,DWORD PTR [esi+0x50]
  6d0a8a:	3b f7                	cmp    esi,edi
  6d0a8c:	75 d9                	jne    0x6d0a67
  6d0a8e:	c7 44 24 1c 00 00 00 	mov    DWORD PTR [esp+0x1c],0x0
  6d0a95:	00 
  6d0a96:	8b 77 50             	mov    esi,DWORD PTR [edi+0x50]
  6d0a99:	3b f7                	cmp    esi,edi
  6d0a9b:	74 2a                	je     0x6d0ac7
  6d0a9d:	8d 49 00             	lea    ecx,[ecx+0x0]
  6d0aa0:	39 5e 28             	cmp    DWORD PTR [esi+0x28],ebx
  6d0aa3:	8d 46 14             	lea    eax,[esi+0x14]
  6d0aa6:	72 02                	jb     0x6d0aaa
  6d0aa8:	8b 00                	mov    eax,DWORD PTR [eax]
  6d0aaa:	68 c0 08 c4 00       	push   0xc408c0
  6d0aaf:	50                   	push   eax
  6d0ab0:	e8 fc 31 1c 00       	call   0x893cb1
  6d0ab5:	83 c4 08             	add    esp,0x8
  6d0ab8:	85 c0                	test   eax,eax
  6d0aba:	0f 84 e4 00 00 00    	je     0x6d0ba4
  6d0ac0:	8b 76 50             	mov    esi,DWORD PTR [esi+0x50]
  6d0ac3:	3b f7                	cmp    esi,edi
  6d0ac5:	75 d9                	jne    0x6d0aa0
  6d0ac7:	33 db                	xor    ebx,ebx
  6d0ac9:	8b 77 50             	mov    esi,DWORD PTR [edi+0x50]
  6d0acc:	3b f7                	cmp    esi,edi
  6d0ace:	74                   	.byte 0x74
```

### VA `0x006D0ACF–0x006D0AFF`（raw `0x2CFECF–0x2CFEFF`）

```asm
; PE .text raw window bytes: 2e bf 10 00 00 00 39 7e 28 8d 46 14 72 02 8b 00 68 d0 08 c4 00 50 e8 c7 31 1c 00 83 c4 08 85 c0 0f 84 d9 00 00 00 8b 76 50 3b 74 24 10 75 d7 33 c0
; 反組譯自指定起始 VA 線性解碼；窗口起點若不在 instruction boundary，須與 caller/CFG 再核對。
  6d0acf:	2e bf 10 00 00 00    	cs mov edi,0x10
  6d0ad5:	39 7e 28             	cmp    DWORD PTR [esi+0x28],edi
  6d0ad8:	8d 46 14             	lea    eax,[esi+0x14]
  6d0adb:	72 02                	jb     0x6d0adf
  6d0add:	8b 00                	mov    eax,DWORD PTR [eax]
  6d0adf:	68 d0 08 c4 00       	push   0xc408d0
  6d0ae4:	50                   	push   eax
  6d0ae5:	e8 c7 31 1c 00       	call   0x893cb1
  6d0aea:	83 c4 08             	add    esp,0x8
  6d0aed:	85 c0                	test   eax,eax
  6d0aef:	0f 84 d9 00 00 00    	je     0x6d0bce
  6d0af5:	8b 76 50             	mov    esi,DWORD PTR [esi+0x50]
  6d0af8:	3b 74 24 10          	cmp    esi,DWORD PTR [esp+0x10]
  6d0afc:	75 d7                	jne    0x6d0ad5
  6d0afe:	33 c0                	xor    eax,eax
```

## 資料流／分支推導

1. `0xC408B8`=`Type`，`0xC408C0`=`Key`，`0xC408C4`=`MapButton`，`0xC408D0`=`ModKey`，由 BIN .rdata 查核。
2. 子項遍歷使用 `+0x50` 指標與 `edi` 比較，`0x893CB1` 文字比較結果決定對應分支，`0x8917B4` 轉成整數。
3. 數值候選以不同暫存器及 stack slot 匯合到 bank writer；必須先核對哪個欄位對應哪個暫存值才能定義 key/action 綁定。

## 局部 C++ 型偽碼（非原版符號／非完整函式）

```cpp
for (auto node : xmlChildren) {
  if (match(node, "Key")) index = parseInt(node);
  if (match(node, "MapButton")) value = parseInt(node);
  if (match(node, "ModKey")) mod = parseInt(node);
  // schema inference; see raw x86 for exact branch offsets
}
```

## 確定性、正反證與後續

- **已確認**：上述 address/raw 的原始 bytes 解碼與局部分支算術；字串地址以原始 `.rdata` 比對。
- **部分確認**：指標角色、資料結構屬以指令讀寫推估的局部語義，未完成所有 caller/receiver 實例的全域驗證。
- **不得推論**：此處 mapping bank 或 byte／DWORD vector 就是玩家 V 點按、V 長按時間或普攻 chain window；不能把正常資料載入視作 runtime phase writer。
- **尚待查證**：釐清每個解析分支的 `esi`、`edi`、`ebx`、`stack+1c` 實際值與上游 node 類型。


## 供下段接續

以 `0x6D08F0`、`0x6D0D10`、`0x6D1A70` 與 `0x6D4CE0` 為相互獨立的來源／消費路徑；先以同一物件與 caller 參數證明可達性，再嘗試接到玩家動作或封包。若沒有跨指標證據，必須保留缺口。