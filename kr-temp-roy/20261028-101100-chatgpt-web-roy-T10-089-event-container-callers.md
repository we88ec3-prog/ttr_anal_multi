# T10-089 — 事件容器 caller 與 reset 非 producer 反證

## 原始來源／驗證方式

- 對象：KR `Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。本批於實際掛載檔重新計算且一致。
- `.text` 原生 VA `0x401000`、raw offset `0x400`，既有反組譯文字 `t10-full-disasm.txt` 由 KR BIN 的 `objdump` 產生；本段抽查來源指令，並以 VA 保存可重做的窗口。
- 靜態唯讀，不啟動／附加／修改客戶端；先前 T10-081～088 作查詢線索，不把先前推測升格為本段原生結論。
- 證據分級：**已確認**＝以下實際 x86 指令與控制流；**部分確認**＝受限路徑或候選物件；**尚待驗證**＝class／語義／間接 producer、callback、motion 行為。

## 主題：0x6D4A30 的兩個真實 caller 不是同一容器來源

### Callsite A：0x490DFC 與既有全域容器

```asm
  490de8:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  490def:	0f b6 05 fa ad fa 00 	movzx  eax,BYTE PTR ds:0xfaadfa
  490df6:	68 d8 5c f9 00       	push   0xf95cd8
  490dfb:	50                   	push   eax
  490dfc:	e8 2f 3c 24 00       	call   0x6d4a30
  490e01:	83 c4 08             	add    esp,0x8
  490e04:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  490e07:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  490e0e:	59                   	pop    ecx
  490e0f:	5b                   	pop    ebx
  490e10:	8b e5                	mov    esp,ebp
  490e12:	5d                   	pop    ebp
  490e13:	c3                   	ret
```

`0x490DEF` 由 `[0xFAADFA]` 取一個 byte 並零延伸，按順序 `push 0xF95CD8`、`push eax` 後呼叫 `0x6D4A30`。只可說明第一參數是當時取得的全域 byte，第二參數是 `0xF95CD8` 容器地址；尚未知道這個 byte 是模式、事件數量或 reset selector。因為此處未見建立容器節點，它與第二個 caller 的生命週期不同。

### Callsite B：0x58A607 配置 12 bytes 的自連結節點

```asm
  58a5c4:	83 3d 2c 13 fb 00 00 	cmp    DWORD PTR ds:0xfb132c,0x0
  58a5cb:	0f 84 8b 00 00 00    	je     0x58a65c
  58a5d1:	6a 0c                	push   0xc
  58a5d3:	c7 44 24 1c 00 00 00 	mov    DWORD PTR [esp+0x1c],0x0
  58a5da:	00 
  58a5db:	e8 88 6c 30 00       	call   0x891268
  58a5e0:	8b f0                	mov    esi,eax
  58a5e2:	33 ff                	xor    edi,edi
  58a5e4:	83 c4 04             	add    esp,0x4
  58a5e7:	3b f7                	cmp    esi,edi
  58a5e9:	0f 84 a0 01 00 00    	je     0x58a78f
  58a5ef:	89 36                	mov    DWORD PTR [esi],esi
  58a5f1:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  58a5f5:	89 76 04             	mov    DWORD PTR [esi+0x4],esi
  58a5f8:	8d 44 24 14          	lea    eax,[esp+0x14]
  58a5fc:	50                   	push   eax
  58a5fd:	6a 01                	push   0x1
  58a5ff:	c7 44 24 50 03 00 00 	mov    DWORD PTR [esp+0x50],0x3
  58a606:	00 
  58a607:	e8 24 a4 14 00       	call   0x6d4a30
  58a60c:	89 bb 3c 01 00 00    	mov    DWORD PTR [ebx+0x13c],edi
  58a612:	89 bb 40 01 00 00    	mov    DWORD PTR [ebx+0x140],edi
  58a618:	89 bb 44 01 00 00    	mov    DWORD PTR [ebx+0x144],edi
  58a61e:	66 89 bb 48 01 00 00 	mov    WORD PTR [ebx+0x148],di
  58a625:	c6 83 4a 01 00 00 00 	mov    BYTE PTR [ebx+0x14a],0x0
```

`0x58A5D1 push 0xC`、`0x58A5DB call 0x891268`、`0x58A5EF mov [esi],esi` 與 `0x58A5F5 mov [esi+4],esi`，證明 12-byte allocation 的前兩個指標初始化為指回自己；stack `[esp+0x14]` 指向它。`push 1` 和 `push &stack_container` 後呼叫 `0x6D4A30`，這條路可確定使用**新建暫時容器**，但不能從 node 自連結推論已經包含按鍵事件。

### 清零實體與方向

```asm
  6d4a93:	33 c0                	xor    eax,eax
  6d4a95:	f6 05 ec f3 fd 00 01 	test   BYTE PTR ds:0xfdf3ec,0x1
  6d4a9c:	a3 04 90 fb 00       	mov    ds:0xfb9004,eax
  6d4aa1:	a3 08 90 fb 00       	mov    ds:0xfb9008,eax
  6d4aa6:	a3 0c 90 fb 00       	mov    ds:0xfb900c,eax
  6d4aab:	a3 10 90 fb 00       	mov    ds:0xfb9010,eax
  6d4ab0:	a3 14 90 fb 00       	mov    ds:0xfb9014,eax
  6d4ab5:	a3 18 90 fb 00       	mov    ds:0xfb9018,eax
  6d4aba:	a3 1c 90 fb 00       	mov    ds:0xfb901c,eax
  6d4abf:	a3 20 90 fb 00       	mov    ds:0xfb9020,eax
  6d4ac4:	a3 24 90 fb 00       	mov    ds:0xfb9024,eax
  6d4ac9:	a3 28 90 fb 00       	mov    ds:0xfb9028,eax
```
```asm
  6d4c20:	8b 77 08             	mov    esi,DWORD PTR [edi+0x8]
  6d4c23:	8d 8e ef d8 ff ff    	lea    ecx,[esi-0x2711]
  6d4c29:	81 f9 0e 27 00 00    	cmp    ecx,0x270e
  6d4c2f:	77 51                	ja     0x6d4c82
  6d4c31:	f6 05 ec f3 fd 00 01 	test   BYTE PTR ds:0xfdf3ec,0x1
  6d4c38:	75 23                	jne    0x6d4c5d
  6d4c3a:	83 0d ec f3 fd 00 01 	or     DWORD PTR ds:0xfdf3ec,0x1
  6d4c41:	c7 45 fc 06 00 00 00 	mov    DWORD PTR [ebp-0x4],0x6
  6d4c48:	e8 53 d1 ff ff       	call   0x6d1da0
  6d4c4d:	68 30 e3 bc 00       	push   0xbce330
  6d4c52:	e8 c3 d6 1b 00       	call   0x89231a
  6d4c57:	83 c4 04             	add    esp,0x4
  6d4c5a:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4c5d:	8d 55 08             	lea    edx,[ebp+0x8]
  6d4c60:	52                   	push   edx
  6d4c61:	8d 45 f0             	lea    eax,[ebp-0x10]
  6d4c64:	b9 30 f6 fd 00       	mov    ecx,0xfdf630
  6d4c69:	89 75 08             	mov    DWORD PTR [ebp+0x8],esi
  6d4c6c:	e8 8f a2 15 00       	call   0x82ef00
  6d4c71:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  6d4c74:	3b 05 34 f6 fd 00    	cmp    eax,DWORD PTR ds:0xfdf634
  6d4c7a:	74 39                	je     0x6d4cb5
  6d4c7c:	c6 40 10 00          	mov    BYTE PTR [eax+0x10],0x0
  6d4c80:	eb 33                	jmp    0x6d4cb5
  6d4c82:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  6d4c89:	75 23                	jne    0x6d4cae
  6d4c8b:	83 0d 14 7c fb 00 01 	or     DWORD PTR ds:0xfb7c14,0x1
  6d4c92:	c7 45 fc 07 00 00 00 	mov    DWORD PTR [ebp-0x4],0x7
  6d4c99:	e8 b2 ba ff ff       	call   0x6d0750
  6d4c9e:	68 30 d5 bc 00       	push   0xbcd530
  6d4ca3:	e8 72 d6 1b 00       	call   0x89231a
  6d4ca8:	83 c4 04             	add    esp,0x4
  6d4cab:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  6d4cae:	c6 86 04 90 fb 00 00 	mov    BYTE PTR [esi+0xfb9004],0x0
```

重點反證：對 `0xFB9004..0xFB9028` 的 10 個 DWORD stores 使用 `xor eax,eax` 的 **0**；對一般 `ID` 的 `byte[0xFB9004+ID]` 與特殊容器項 `[eax+0x10]` 也是清零。不能因這些 caller 與鍵盤事件共用名稱或數據結構就稱它們是 `phase=1/3` producer。

## 可重建的有限資料流

```text
A: byte[0xFAADFA] + persistent container 0xF95CD8
                                 └→ 0x6D4A30 → phase reset
B: allocate(0xC) → sentinel self-links → temporary container
                                 └→ 0x6D4A30 → reset → [ebx+0x13C..0x14A] 清理
```

## 結論與缺口

- 已確認：兩個 callsite 的參數、暫時容器節點布局、清零操作與後續物件欄位清理。
- 部分確認：`0x6D4A30` 消費容器中的 ID；但 A 的持久容器內容 producer 與 B 的後續節點插入者不能從此處直接得到。
- 未確認：任何 Key44..47 → MapButton13..16 → phase1/3 的寫入；`0xFAADFA` 的語義；`0xF95CD8` 的寫入者。
- 下一步：追 `0xF95CD8` 的插入路徑及 `0xFAADFA` 非零 writer；不要把 reset caller 當作輸入事件發布。