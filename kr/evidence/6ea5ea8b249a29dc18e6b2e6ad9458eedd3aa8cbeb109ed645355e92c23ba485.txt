# T10-074 — keymapping default fallback

- 記錄時間：2026-10-28T02:39:19+08:00
- 標的：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；唯讀靜態取證，沒有執行／附加遊戲。
- PE `.text` 映射（由本機 PE section header 核對）：VA `0x401000`、raw `0x400`，本筆記列出之 `.text` 地址使用 `raw=VA-0x400C00`。
- PE `.rdata` 映射：VA `0xBD2000`、raw `0x7D0600`，`raw=VA-0x401A00`。資料字串來自同 SHA 原始 BIN，並非推測生成。
- 先前研究：參照已提交 T10-1～68、T01 有限整合結論；本次第一手證據僅限下列 byte 與指令及明確控制流。
- 分工：T10 為輸入／普攻／連段與取消；T11 技能施放裁決僅引用。沒有修改 owner、catalog、程式或封包。
- 完成界線：本段**不代表**原版 Z/V 動作、連段取消、施放 tier 或伺服器規則全鏈已驗證。

## 研究問題及本段結果

主配置讀取 `0x72F110` 失敗／條件未符合時會轉到 `0x6D0C68` 呼叫 `0x6D0EB0`；後者明確以多組常數與 slot 位址建立初始映射。可判定存在原生 fallback，仍不能認為這等於玩家個人設定。

## 可複核第一手機器碼

### VA `0x006D0C4C–0x006D0C97`（raw `0x2D004C–0x2D0097`）

```asm
; PE .text raw window bytes: a1 34 90 fb 00 85 c0 74 05 83 f8 01 75 38 8d 04 80 c1 e0 07 05 34 88 fb 00 50 eb 20 e8 43 02 00 00 a1 34 90 fb 00 85 c0 74 05 83 f8 01 75 17 8d 0c 80 c1 e1 07 81 c1 34 88 fb 00 51 68 34 8d fb 00 e8 4e 0f 00 00 c7 84 24 b0 00 00
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
  6d0c93:	84 24 b0             	test   BYTE PTR [eax+esi*4],ah
```

### VA `0x006D0EB0–0x006D0FCE`（raw `0x2D02B0–0x2D03CE`）

```asm
; PE .text raw window bytes: 55 8b ec 51 57 8d 45 fc bf 44 88 fb 00 c7 45 fc 48 00 00 00 e8 b7 77 dd ff 8d 45 fc c7 45 fc c8 00 00 00 e8 a8 77 dd ff 8d 45 fc bf 54 88 fb 00 c7 45 fc 4c 00 00 00 e8 94 77 dd ff 8d 45 fc c7 45 fc 50 00 00 00 e8 85 77 dd ff 8d 45 fc c7 45 fc d0 00 00 00 e8 76 77 dd ff 8d 45 fc bf 64 88 fb 00 c7 45 fc 4b 00 00 00 e8 62 77 dd ff 8d 45 fc c7 45 fc cb 00 00 00 e8 53 77 dd ff 8d 45 fc bf 74 88 fb 00 c7 45 fc 4d 00 00 00 e8 3f 77 dd ff 8d 45 fc c7 45 fc cd 00 00 00 e8 30 77 dd ff 8d 45 fc bf 84 88 fb 00 c7 45 fc 52 00 00 00 e8 1c 77 dd ff 8d 45 fc bf 94 88 fb 00 c7 45 fc 51 00 00 00 e8 08 77 dd ff 8d 45 fc bf a4 88 fb 00 c7 45 fc 4f 00 00 00 e8 f4 76 dd ff 8d 45 fc bf b4 88 fb 00 c7 45 fc 47 00 00 00 e8 e0 76 dd ff 8d 45 fc bf c4 88 fb 00 c7 45 fc 49 00 00 00 e8 cc 76 dd ff 8d 45 fc bf d4 88 fb 00 c7 45 fc 4e 00 00 00 e8 b8 76 dd ff 8d 45 fc bf e4 88 fb
; 反組譯自指定起始 VA 線性解碼；窗口起點若不在 instruction boundary，須與 caller/CFG 再核對。
  6d0eb0:	55                   	push   ebp
  6d0eb1:	8b ec                	mov    ebp,esp
  6d0eb3:	51                   	push   ecx
  6d0eb4:	57                   	push   edi
  6d0eb5:	8d 45 fc             	lea    eax,[ebp-0x4]
  6d0eb8:	bf 44 88 fb 00       	mov    edi,0xfb8844
  6d0ebd:	c7 45 fc 48 00 00 00 	mov    DWORD PTR [ebp-0x4],0x48
  6d0ec4:	e8 b7 77 dd ff       	call   0x4a8680
  6d0ec9:	8d 45 fc             	lea    eax,[ebp-0x4]
  6d0ecc:	c7 45 fc c8 00 00 00 	mov    DWORD PTR [ebp-0x4],0xc8
  6d0ed3:	e8 a8 77 dd ff       	call   0x4a8680
  6d0ed8:	8d 45 fc             	lea    eax,[ebp-0x4]
  6d0edb:	bf 54 88 fb 00       	mov    edi,0xfb8854
  6d0ee0:	c7 45 fc 4c 00 00 00 	mov    DWORD PTR [ebp-0x4],0x4c
  6d0ee7:	e8 94 77 dd ff       	call   0x4a8680
  6d0eec:	8d 45 fc             	lea    eax,[ebp-0x4]
  6d0eef:	c7 45 fc 50 00 00 00 	mov    DWORD PTR [ebp-0x4],0x50
  6d0ef6:	e8 85 77 dd ff       	call   0x4a8680
  6d0efb:	8d 45 fc             	lea    eax,[ebp-0x4]
  6d0efe:	c7 45 fc d0 00 00 00 	mov    DWORD PTR [ebp-0x4],0xd0
  6d0f05:	e8 76 77 dd ff       	call   0x4a8680
  6d0f0a:	8d 45 fc             	lea    eax,[ebp-0x4]
  6d0f0d:	bf 64 88 fb 00       	mov    edi,0xfb8864
  6d0f12:	c7 45 fc 4b 00 00 00 	mov    DWORD PTR [ebp-0x4],0x4b
  6d0f19:	e8 62 77 dd ff       	call   0x4a8680
  6d0f1e:	8d 45 fc             	lea    eax,[ebp-0x4]
  6d0f21:	c7 45 fc cb 00 00 00 	mov    DWORD PTR [ebp-0x4],0xcb
  6d0f28:	e8 53 77 dd ff       	call   0x4a8680
  6d0f2d:	8d 45 fc             	lea    eax,[ebp-0x4]
  6d0f30:	bf 74 88 fb 00       	mov    edi,0xfb8874
  6d0f35:	c7 45 fc 4d 00 00 00 	mov    DWORD PTR [ebp-0x4],0x4d
  6d0f3c:	e8 3f 77 dd ff       	call   0x4a8680
  6d0f41:	8d 45 fc             	lea    eax,[ebp-0x4]
  6d0f44:	c7 45 fc cd 00 00 00 	mov    DWORD PTR [ebp-0x4],0xcd
  6d0f4b:	e8 30 77 dd ff       	call   0x4a8680
  6d0f50:	8d 45 fc             	lea    eax,[ebp-0x4]
  6d0f53:	bf 84 88 fb 00       	mov    edi,0xfb8884
  6d0f58:	c7 45 fc 52 00 00 00 	mov    DWORD PTR [ebp-0x4],0x52
  6d0f5f:	e8 1c 77 dd ff       	call   0x4a8680
  6d0f64:	8d 45 fc             	lea    eax,[ebp-0x4]
  6d0f67:	bf 94 88 fb 00       	mov    edi,0xfb8894
  6d0f6c:	c7 45 fc 51 00 00 00 	mov    DWORD PTR [ebp-0x4],0x51
  6d0f73:	e8 08 77 dd ff       	call   0x4a8680
  6d0f78:	8d 45 fc             	lea    eax,[ebp-0x4]
  6d0f7b:	bf a4 88 fb 00       	mov    edi,0xfb88a4
  6d0f80:	c7 45 fc 4f 00 00 00 	mov    DWORD PTR [ebp-0x4],0x4f
  6d0f87:	e8 f4 76 dd ff       	call   0x4a8680
  6d0f8c:	8d 45 fc             	lea    eax,[ebp-0x4]
  6d0f8f:	bf b4 88 fb 00       	mov    edi,0xfb88b4
  6d0f94:	c7 45 fc 47 00 00 00 	mov    DWORD PTR [ebp-0x4],0x47
  6d0f9b:	e8 e0 76 dd ff       	call   0x4a8680
  6d0fa0:	8d 45 fc             	lea    eax,[ebp-0x4]
  6d0fa3:	bf c4 88 fb 00       	mov    edi,0xfb88c4
  6d0fa8:	c7 45 fc 49 00 00 00 	mov    DWORD PTR [ebp-0x4],0x49
  6d0faf:	e8 cc 76 dd ff       	call   0x4a8680
  6d0fb4:	8d 45 fc             	lea    eax,[ebp-0x4]
  6d0fb7:	bf d4 88 fb 00       	mov    edi,0xfb88d4
  6d0fbc:	c7 45 fc 4e 00 00 00 	mov    DWORD PTR [ebp-0x4],0x4e
  6d0fc3:	e8 b8 76 dd ff       	call   0x4a8680
  6d0fc8:	8d 45 fc             	lea    eax,[ebp-0x4]
  6d0fcb:	bf                   	.byte 0xbf
  6d0fcc:	e4 88                	in     al,0x88
  6d0fce:	fb                   	sti
```

## 資料流／分支推導

1. `0x6D0C68 call 0x6D0EB0` 是主 XML loader 的備援分支，是否因檔案缺失或格式不符，需查前面的判斷 helper。
2. `0x6D0EB0` 對 `0xFB8844`、`0xFB8854` 等以 0x10 步長的映射 slot 反覆呼叫 `0x4A8680`。
3. 預設常數如 0x48、0xC8、0x4C、0x50 是原生 fallback 映射資料；不可直接將 ASCII 相近字母當成 Z/X/C/V 遊戲預設 action。

## 局部 C++ 型偽碼（非原版符號／非完整函式）

```cpp
if (!mappingSourceReady) {
  populateFallbackMapping(0x6D0EB0);
}
// actual action/key interpretation requires the slot consumer
```

## 確定性、正反證與後續

- **已確認**：上述 address/raw 的原始 bytes 解碼與局部分支算術；字串地址以原始 `.rdata` 比對。
- **部分確認**：指標角色、資料結構屬以指令讀寫推估的局部語義，未完成所有 caller/receiver 實例的全域驗證。
- **不得推論**：此處 mapping bank 或 byte／DWORD vector 就是玩家 V 點按、V 長按時間或普攻 chain window；不能把正常資料載入視作 runtime phase writer。
- **尚待查證**：追 `0x4A8680` 的輸入與真正寫入 slot 格式，並驗證每個 fallback slot 的 action 語義。


## 供下段接續

以 `0x6D08F0`、`0x6D0D10`、`0x6D1A70` 與 `0x6D4CE0` 為相互獨立的來源／消費路徑；先以同一物件與 caller 參數證明可達性，再嘗試接到玩家動作或封包。若沒有跨指標證據，必須保留缺口。