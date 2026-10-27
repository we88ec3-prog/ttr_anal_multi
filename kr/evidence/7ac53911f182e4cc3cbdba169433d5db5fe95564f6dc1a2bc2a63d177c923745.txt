# T10-069 — keymapping xml source

- 記錄時間：2026-10-28T02:39:19+08:00
- 標的：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀靜態取證，沒有執行／附加遊戲。
- PE `.text` 映射（由本機 PE section header 核對）：VA `0x401000`、raw `0x400`，本筆記列出之 `.text` 地址使用 `raw=VA-0x400C00`。
- PE `.rdata` 映射：VA `0xBD2000`、raw `0x7D0600`，`raw=VA-0x401A00`。資料字串來自同 SHA 原始 BIN，並非推測生成。
- 先前研究：參照已提交 T10-1～68、T01 有限整合結論；本次第一手證據僅限下列 byte 與指令及明確控制流。
- 分工：T10 為輸入／普攻／連段與取消；T11 技能施放裁決僅引用。沒有修改 owner、catalog、程式或封包。
- 完成界線：本段**不代表**原版 Z/V 動作、連段取消、施放 tier 或伺服器規則全鏈已驗證。

## 研究問題及本段結果

直接從 `.rdata` 證實原生主配置檔 `Table/KeyMapping.xml`，`0x6D08F0` 以其位址初始化字串，接 `0x72F110` 條件分支，再依 `KeyMapping`、`DefaultType` 欄位進入資料讀取。這是鍵位自訂載入來源的確認，還不是戰鬥鍵綁定的語義完成。

## 可複核第一手機器碼

### VA `0x006D08F0–0x006D099F`（raw `0x2CFCF0–0x2CFD9F`）

```asm
; PE .text raw window bytes: 55 8b ec 83 e4 f8 6a ff 68 7b 28 92 00 64 a1 00 00 00 00 50 81 ec 98 00 00 00 a1 20 1f d6 00 33 c4 89 84 24 90 00 00 00 53 56 57 a1 20 1f d6 00 33 c4 50 8d 84 24 a8 00 00 00 64 a3 00 00 00 00 8d 44 24 24 50 b9 88 08 c4 00 e8 f1 e4 05 00 c7 84 24 b0 00 00 00 00 00 00 00 8b 4c 24 44 bb 10 00 00 00 39 5c 24 58 73 04 8d 4c 24 44 6a 00 8d 74 24 28 e8 a8 e7 05 00 84 c0 0f 84 f8 02 00 00 68 a0 08 c4 00 8b c6 e8 64 d9 05 00 8b f0 85 f6 74 1a 8b 16 8b 42 14 8b ce ff d0 85 c0 74 0d 8b 16 8b 42 14 8b ce ff d0 8b f0 eb 02 33 f6 68 ac
; 反組譯自指定起始 VA 線性解碼；窗口起點若不在 instruction boundary，須與 caller/CFG 再核對。
  6d08f0:	55                   	push   ebp
  6d08f1:	8b ec                	mov    ebp,esp
  6d08f3:	83 e4 f8             	and    esp,0xfffffff8
  6d08f6:	6a ff                	push   0xffffffff
  6d08f8:	68 7b 28 92 00       	push   0x92287b
  6d08fd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  6d0903:	50                   	push   eax
  6d0904:	81 ec 98 00 00 00    	sub    esp,0x98
  6d090a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6d090f:	33 c4                	xor    eax,esp
  6d0911:	89 84 24 90 00 00 00 	mov    DWORD PTR [esp+0x90],eax
  6d0918:	53                   	push   ebx
  6d0919:	56                   	push   esi
  6d091a:	57                   	push   edi
  6d091b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  6d0920:	33 c4                	xor    eax,esp
  6d0922:	50                   	push   eax
  6d0923:	8d 84 24 a8 00 00 00 	lea    eax,[esp+0xa8]
  6d092a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
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
  6d096a:	0f 84 f8 02 00 00    	je     0x6d0c68
  6d0970:	68 a0 08 c4 00       	push   0xc408a0
  6d0975:	8b c6                	mov    eax,esi
  6d0977:	e8 64 d9 05 00       	call   0x72e2e0
  6d097c:	8b f0                	mov    esi,eax
  6d097e:	85 f6                	test   esi,esi
  6d0980:	74 1a                	je     0x6d099c
  6d0982:	8b 16                	mov    edx,DWORD PTR [esi]
  6d0984:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  6d0987:	8b ce                	mov    ecx,esi
  6d0989:	ff d0                	call   eax
  6d098b:	85 c0                	test   eax,eax
  6d098d:	74 0d                	je     0x6d099c
  6d098f:	8b 16                	mov    edx,DWORD PTR [esi]
  6d0991:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  6d0994:	8b ce                	mov    ecx,esi
  6d0996:	ff d0                	call   eax
  6d0998:	8b f0                	mov    esi,eax
  6d099a:	eb 02                	jmp    0x6d099e
  6d099c:	33 f6                	xor    esi,esi
  6d099e:	68                   	.byte 0x68
  6d099f:	ac                   	lods   al,BYTE PTR ds:[esi]
```

### VA `0x006D09A0–0x006D0A2B`（raw `0x2CFDA0–0x2CFE2B`）

```asm
; PE .text raw window bytes: 08 c4 00 8d 7e 44 e8 f5 f6 05 00 85 c0 74 19 83 c0 30 39 58 14 72 02 8b 00 85 c0 74 0b 50 e8 f1 0d 1c 00 83 c4 04 eb 02 33 c0 a3 34 90 fb 00 bf b8 08 c4 00 8b c6 e8 85 d9 05 00 8b d8 89 5c 24 18 85 db 0f 84 63 02 00 00 8d a4 24 00 00 00 00 68 fc 71 c0 00 8d 7b 44 e8 a3 f6 05 00 85 c0 0f 84 6c 01 00 00 83 c0 30 83 78 14 10 72 02 8b 00 85 c0 0f 84 59 01 00 00 50 e8 96 0d 1c 00 8b f0 83 c4 04 83 fe 03 0f 83 66 02 00 00
; 反組譯自指定起始 VA 線性解碼；窗口起點若不在 instruction boundary，須與 caller/CFG 再核對。
  6d09a0:	08 c4                	or     ah,al
  6d09a2:	00 8d 7e 44 e8 f5    	add    BYTE PTR [ebp-0xa17bb82],cl
  6d09a8:	f6 05 00 85 c0 74 19 	test   BYTE PTR ds:0x74c08500,0x19
  6d09af:	83 c0 30             	add    eax,0x30
  6d09b2:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  6d09b5:	72 02                	jb     0x6d09b9
  6d09b7:	8b 00                	mov    eax,DWORD PTR [eax]
  6d09b9:	85 c0                	test   eax,eax
  6d09bb:	74 0b                	je     0x6d09c8
  6d09bd:	50                   	push   eax
  6d09be:	e8 f1 0d 1c 00       	call   0x8917b4
  6d09c3:	83 c4 04             	add    esp,0x4
  6d09c6:	eb 02                	jmp    0x6d09ca
  6d09c8:	33 c0                	xor    eax,eax
  6d09ca:	a3 34 90 fb 00       	mov    ds:0xfb9034,eax
  6d09cf:	bf b8 08 c4 00       	mov    edi,0xc408b8
  6d09d4:	8b c6                	mov    eax,esi
  6d09d6:	e8 85 d9 05 00       	call   0x72e360
  6d09db:	8b d8                	mov    ebx,eax
  6d09dd:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  6d09e1:	85 db                	test   ebx,ebx
  6d09e3:	0f 84 63 02 00 00    	je     0x6d0c4c
  6d09e9:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  6d09f0:	68 fc 71 c0 00       	push   0xc071fc
  6d09f5:	8d 7b 44             	lea    edi,[ebx+0x44]
  6d09f8:	e8 a3 f6 05 00       	call   0x7300a0
  6d09fd:	85 c0                	test   eax,eax
  6d09ff:	0f 84 6c 01 00 00    	je     0x6d0b71
  6d0a05:	83 c0 30             	add    eax,0x30
  6d0a08:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  6d0a0c:	72 02                	jb     0x6d0a10
  6d0a0e:	8b 00                	mov    eax,DWORD PTR [eax]
  6d0a10:	85 c0                	test   eax,eax
  6d0a12:	0f 84 59 01 00 00    	je     0x6d0b71
  6d0a18:	50                   	push   eax
  6d0a19:	e8 96 0d 1c 00       	call   0x8917b4
  6d0a1e:	8b f0                	mov    esi,eax
  6d0a20:	83 c4 04             	add    esp,0x4
  6d0a23:	83 fe 03             	cmp    esi,0x3
  6d0a26:	0f 83 66 02 00 00    	jae    0x6d0c92
```

## 資料流／分支推導

1. `0x6D0935: mov ecx,0xC40888` 指向 `Table/KeyMapping.xml`；`0x6D0963` 呼叫 `0x72F110`，其 `al` 只用來選擇設定讀取或 fallback 分支。
2. `0xC408A0` 為 `KeyMapping`，`0xC408AC` 為 `DefaultType`，由原始 `.rdata` NUL 結束 bytes 確認。
3. XML parser 型別與錯誤行為不可由 string evidence 直接命名為某個 library 或已成功開啟檔案。

## 局部 C++ 型偽碼（非原版符號／非完整函式）

```cpp
auto source = LITERAL_AT(0xC40888); // "Table/KeyMapping.xml"
if (probe(0x72F110, source)) { /* fetch KeyMapping / DefaultType candidate */ }
else { /* fallback, see 0x6D0C68 */ }
```

## 確定性、正反證與後續

- **已確認**：上述 address/raw 的原始 bytes 解碼與局部分支算術；字串地址以原始 `.rdata` 比對。
- **部分確認**：指標角色、資料結構屬以指令讀寫推估的局部語義，未完成所有 caller/receiver 實例的全域驗證。
- **不得推論**：此處 mapping bank 或 byte／DWORD vector 就是玩家 V 點按、V 長按時間或普攻 chain window；不能把正常資料載入視作 runtime phase writer。
- **尚待查證**：要取得實際 XML 檔與各 row 的值；`0x72F110` 返回條件與取得物件型別還需追 caller/receiver。

## 額外靜態證據

字串直接 raw 查核：`0xC40888`=`Table/KeyMapping.xml`，`0xC408A0`=`KeyMapping`，`0xC408AC`=`DefaultType`。

## 供下段接續

以 `0x6D08F0`、`0x6D0D10`、`0x6D1A70` 與 `0x6D4CE0` 為相互獨立的來源／消費路徑；先以同一物件與 caller 參數證明可達性，再嘗試接到玩家動作或封包。若沒有跨指標證據，必須保留缺口。