# T10-087 — MapButton phase 派送與介面虛擬方法：未閉合的 controller 邊界

**證據版本**：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪 `sha256sum` 核對）；`.text` VA `0x401000`，raw `0x400`；`objdump -D -Mintel` 直接對 PE32 `.text` 反組譯。檔案靜態唯讀。

## 新結論

1. `0x5961C0` 逐 ID 查詢 `0x6D4CE0`，ID 0..39 包含 13..16；局部 `edi` 為 ID，`esi=edi` 為非標準 ABI reader 參數。phase 1 分派物件 vtable `+0xEC`；phase 3 分派 `+0xF0`，且具物件與 this 的 fallback 路線。
2. `0x59623B` 的 `[0xFB73E8]` 非零條件只在這段 loop 排除不是 13/14 的 ID，並非全域停用 15/16。與 T10-086 中模式切換路徑互相交叉，但沒有具體虛擬槽位的 owning class/vtable address 時不可稱 AttackPress/Release。
3. `0x6D4DC0` 直接 caller 並非僅 UI：原始 `.text` 靜態 callsite 包含 `0x594672..0x5959F4`、`0x5CD68A`、`0x5CE5BA`、`0x62B5BA`、`0x650E96..0x6510A4`。其中 T10-082 已確認 `0x594610` 內的多個 caller 導向 UI 組裝；其他 caller 尚須逐個讀取其返回值用途。**配置查詢不能等同 phase reader，更不能直接當 motion writer**。
4. 目前確認兩個不同介面：(a) 配置 bank→`0x6D4DC0` 得鍵碼清單；(b) 狀態 byte→`0x6D4CE0`→`0x5961C0` 多態處理。兩介面在 scan-code→phase writer 尚未建立直接機器碼因果。

## BIN 直接片段

### VA 0x005961ED..0x005962E0

```asm
  5961ed:	8b c3                	mov    eax,ebx
  5961ef:	e8 1c ae 1c 00       	call   0x761010
  5961f4:	33 ff                	xor    edi,edi
  5961f6:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  5961f9:	c6 45 f3 00          	mov    BYTE PTR [ebp-0xd],0x0
  5961fd:	3b c7                	cmp    eax,edi
  5961ff:	74 0e                	je     0x59620f
  596201:	8b 40 28             	mov    eax,DWORD PTR [eax+0x28]
  596204:	c1 e8 0d             	shr    eax,0xd
  596207:	a8 01                	test   al,0x1
  596209:	74 04                	je     0x59620f
  59620b:	c6 45 f3 01          	mov    BYTE PTR [ebp-0xd],0x1
  59620f:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  596216:	75 23                	jne    0x59623b
  596218:	83 0d b8 73 fb 00 01 	or     DWORD PTR ds:0xfb73b8,0x1
  59621f:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  596222:	e8 49 9f fc ff       	call   0x560170
  596227:	68 10 d1 bc 00       	push   0xbcd110
  59622c:	e8 e9 c0 2f 00       	call   0x89231a
  596231:	83 c4 04             	add    esp,0x4
  596234:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  59623b:	39 3d e8 73 fb 00    	cmp    DWORD PTR ds:0xfb73e8,edi
  596241:	0f 95 45 f1          	setne  BYTE PTR [ebp-0xf]
  596245:	8b f7                	mov    esi,edi
  596247:	c6 45 f2 00          	mov    BYTE PTR [ebp-0xe],0x0
  59624b:	89 7d dc             	mov    DWORD PTR [ebp-0x24],edi
  59624e:	e8 8d ea 13 00       	call   0x6d4ce0
  596253:	80 7d f1 00          	cmp    BYTE PTR [ebp-0xf],0x0
  596257:	74 0e                	je     0x596267
  596259:	83 ff 0d             	cmp    edi,0xd
  59625c:	74 09                	je     0x596267
  59625e:	83 ff 0e             	cmp    edi,0xe
  596261:	0f 85 1f 01 00 00    	jne    0x596386
  596267:	83 f8 01             	cmp    eax,0x1
  59626a:	75 50                	jne    0x5962bc
  59626c:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  59626f:	85 c9                	test   ecx,ecx
  596271:	74 11                	je     0x596284
  596273:	8b 11                	mov    edx,DWORD PTR [ecx]
  596275:	8b 82 ec 00 00 00    	mov    eax,DWORD PTR [edx+0xec]
  59627b:	57                   	push   edi
  59627c:	ff d0                	call   eax
  59627e:	84 c0                	test   al,al
  596280:	b0 01                	mov    al,0x1
  596282:	75 03                	jne    0x596287
  596284:	8a 45 f2             	mov    al,BYTE PTR [ebp-0xe]
  596287:	80 7d f3 00          	cmp    BYTE PTR [ebp-0xd],0x0
  59628b:	0f 85 bc 00 00 00    	jne    0x59634d
  596291:	84 c0                	test   al,al
  596293:	0f 85 b8 00 00 00    	jne    0x596351
  596299:	6a 01                	push   0x1
  59629b:	8b c3                	mov    eax,ebx
  59629d:	e8 9e fe ff ff       	call   0x596140
  5962a2:	84 c0                	test   al,al
  5962a4:	0f 85 a7 00 00 00    	jne    0x596351
  5962aa:	8b 13                	mov    edx,DWORD PTR [ebx]
  5962ac:	8b 82 ec 00 00 00    	mov    eax,DWORD PTR [edx+0xec]
  5962b2:	57                   	push   edi
  5962b3:	8b cb                	mov    ecx,ebx
  5962b5:	ff d0                	call   eax
  5962b7:	e9 91 00 00 00       	jmp    0x59634d
  5962bc:	83 f8 03             	cmp    eax,0x3
  5962bf:	0f 85 c1 00 00 00    	jne    0x596386
  5962c5:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  5962c8:	85 c9                	test   ecx,ecx
  5962ca:	74 13                	je     0x5962df
  5962cc:	8b 11                	mov    edx,DWORD PTR [ecx]
  5962ce:	8b 82 f0 00 00 00    	mov    eax,DWORD PTR [edx+0xf0]
  5962d4:	57                   	push   edi
  5962d5:	ff d0                	call   eax
  5962d7:	84 c0                	test   al,al
  5962d9:	74 04                	je     0x5962df
  5962db:	c6 45 f2 01          	mov    BYTE PTR [ebp-0xe],0x1
  5962df:	80 7d f3 00          	cmp    BYTE PTR [ebp-0xd],0x0
```

### VA 0x00594650..0x00594690

```asm
  594650:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  594654:	89 74 24 18          	mov    DWORD PTR [esp+0x18],esi
  594658:	89 5c 24 3c          	mov    DWORD PTR [esp+0x3c],ebx
  59465c:	89 5c 24 40          	mov    DWORD PTR [esp+0x40],ebx
  594660:	89 5c 24 44          	mov    DWORD PTR [esp+0x44],ebx
  594664:	6a 02                	push   0x2
  594666:	57                   	push   edi
  594667:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  59466b:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  594672:	e8 49 07 14 00       	call   0x6d4dc0
  594677:	83 c4 08             	add    esp,0x8
  59467a:	53                   	push   ebx
  59467b:	68 fc d1 be 00       	push   0xbed1fc
  594680:	8b ce                	mov    ecx,esi
  594682:	e8 d9 da e6 ff       	call   0x402160
  594687:	83 ff 18             	cmp    edi,0x18
  59468a:	0f 85 29 01 00 00    	jne    0x5947b9
```

### VA 0x005CD670..0x005CD6A0

```asm
  5cd672:	89 7c 24 4c          	mov    DWORD PTR [esp+0x4c],edi
  5cd676:	89 7c 24 50          	mov    DWORD PTR [esp+0x50],edi
  5cd67a:	6a 02                	push   0x2
  5cd67c:	6a 10                	push   0x10
  5cd67e:	8d 4c 24 50          	lea    ecx,[esp+0x50]
  5cd682:	c6 84 24 f8 00 00 00 	mov    BYTE PTR [esp+0xf8],0x3
  5cd689:	03 
  5cd68a:	e8 31 77 10 00       	call   0x6d4dc0
  5cd68f:	83 c4 08             	add    esp,0x8
  5cd692:	57                   	push   edi
  5cd693:	68 fc d1 be 00       	push   0xbed1fc
  5cd698:	8d 8c 24 cc 00 00 00 	lea    ecx,[esp+0xcc]
  5cd69f:	e8 bc 4a e3 ff       	call   0x402160
```

## 證據分級與研究限制

- 「已確認」僅指列出的 BIN 字節與控制流；對象／業務語義若沒有 vtable 及 producer 證據一律維持「部分確認」或「尚待驗證」。
- 未執行、修改客戶端，未引入任何原始遊戲資源至 GitHub；沒有擅自修改其他 Task 的 owner、catalog 或筆記。
- 此筆記為 T10 專項研究完整原稿，包含可複查的 VA 原始指令及限制，不將反編譯和 AI 替代當原生依據。