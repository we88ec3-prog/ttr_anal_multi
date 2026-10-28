# KR T16-67 — 全域 send object 設定、callback 與 Quest XML vector 分界

- 研究日期：20261028-110904 Asia/Taipei；分析者 `chatgpt-web roy`；**僅 KR T16**。
- KR BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；大小 `12472320` bytes。實際讀取 `/mnt/data/Tartaros.bin`（唯讀）；未啟動遊戲或呼叫任何原版 API。
- PE `.text` 有效映射：VA `0x00401000`, raw `0x400`；下列 `.text` 函式轉檔案位移使用 `raw = VA - 0x00400C00`，跨 section 必須重算。
- 證據術語：原生已確認=本次直接 BIN 原始位元組與逐指令反組譯；部分確認=指標來源／語意尚未對齊；unknown=缺少原始資料。

## 1. `0x004AA5A0` 的關聯全域欄位

`0x004AA5AB` 直接 `mov [0xFE1804],eax`；`0x004AA5B7` `mov [0xFE1800],ebx`。此處建立 scripting/native runtime 指標來源候選，與上一段 `0xFBA854` 虛呼叫 transport 物件不可無證混為一個物件。

```asm
  4aa5a0:	55                   	push   ebp
  4aa5a1:	8b ec                	mov    ebp,esp
  4aa5a3:	51                   	push   ecx
  4aa5a4:	53                   	push   ebx
  4aa5a5:	8b 5d 0c             	mov    ebx,DWORD PTR [ebp+0xc]
  4aa5a8:	56                   	push   esi
  4aa5a9:	8b 33                	mov    esi,DWORD PTR [ebx]
  4aa5ab:	a3 04 18 fe 00       	mov    ds:0xfe1804,eax
  4aa5b0:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  4aa5b3:	8b 48 44             	mov    ecx,DWORD PTR [eax+0x44]
  4aa5b6:	57                   	push   edi
  4aa5b7:	89 1d 00 18 fe 00    	mov    DWORD PTR ds:0xfe1800,ebx
  4aa5bd:	3b 48 40             	cmp    ecx,DWORD PTR [eax+0x40]
  4aa5c0:	72 07                	jb     0x4aa5c9
  4aa5c2:	8b c6                	mov    eax,esi
  4aa5c4:	e8 d7 0d 25 00       	call   0x6fb3a0
  4aa5c9:	8b 7e 08             	mov    edi,DWORD PTR [esi+0x8]
  4aa5cc:	6a 00                	push   0x0
  4aa5ce:	6a 00                	push   0x0
  4aa5d0:	56                   	push   esi
  4aa5d1:	e8 ca f3 24 00       	call   0x6f99a0
  4aa5d6:	89 07                	mov    DWORD PTR [edi],eax
  4aa5d8:	c7 47 08 05 00 00 00 	mov    DWORD PTR [edi+0x8],0x5
  4aa5df:	83 46 08 10          	add    DWORD PTR [esi+0x8],0x10
  4aa5e3:	8b 33                	mov    esi,DWORD PTR [ebx]
  4aa5e5:	83 c4 0c             	add    esp,0xc
  4aa5e8:	bf 58 68 c0 00       	mov    edi,0xc06858
  4aa5ed:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4aa5f2:	e8 99 b1 24 00       	call   0x6f5790
  4aa5f7:	8b 33                	mov    esi,DWORD PTR [ebx]
  4aa5f9:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  4aa5fe:	e8 7d b0 24 00       	call   0x6f5680
  4aa603:	8b 03                	mov    eax,DWORD PTR [ebx]
  4aa605:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  4aa608:	83 e8 10             	sub    eax,0x10
  4aa60b:	bf f0 ff ff ff       	mov    edi,0xfffffff0
  4aa610:	3d c8 bf c0 00       	cmp    eax,0xc0bfc8
  4aa615:	74 06                	je     0x4aa61d
  4aa617:	83 78 08 05          	cmp    DWORD PTR [eax+0x8],0x5
  4aa61b:	74 17                	je     0x4aa634
  4aa61d:	68 58 68 c0 00       	push   0xc06858
  4aa622:	68 c4 26 c4 00       	push   0xc426c4
  4aa627:	e8 91 8a 3e 00       	call   0x8930bd
  4aa62c:	8b 03                	mov    eax,DWORD PTR [ebx]
  4aa62e:	83 c4 08             	add    esp,0x8
  4aa631:	01 78 08             	add    DWORD PTR [eax+0x8],edi
  4aa634:	8b 33                	mov    esi,DWORD PTR [ebx]
  4aa636:	68 24 62 c0 00       	push   0xc06224
```

## 2. `[0xFE187C]` 與其他 slots 不可混用

`[0xFE187C]` 是函式指標 slot（目前有 `0x4AA4D0` 直接 store）；`[0xFE1804]` 是 `0x4ACB70` 使用的 ecx receiver，兩者都不是已經識別出的 persistent quest DB。`0x004AA5A0` 至少能確認 `[FE1804]` 所指來源來自 `EAX`，`[FE1800]` 來自 `EBX`。

## 3. 對照 `0x004A8680` 本地動態指標容器

`0x004A8680` 用 EDI 指向 `begin/end/capacity` 三 pointer 欄位，`[edi]`, `[edi+4]`, `[edi+8]`，插入 4-byte 節點地址或節點值。它由前段 `0x53FEB0` 使用，原生只證實本地 vector 構造；不是 Quest 玩家狀態完成 writer。

```asm
  4a8680:	56                   	push   esi
  4a8681:	8b f0                	mov    esi,eax
  4a8683:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4a8686:	3b f0                	cmp    esi,eax
  4a8688:	73 30                	jae    0x4a86ba
  4a868a:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4a868c:	3b ce                	cmp    ecx,esi
  4a868e:	77 2a                	ja     0x4a86ba
  4a8690:	2b f1                	sub    esi,ecx
  4a8692:	c1 fe 02             	sar    esi,0x2
  4a8695:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  4a8698:	75 0c                	jne    0x4a86a6
  4a869a:	b9 01 00 00 00       	mov    ecx,0x1
  4a869f:	8b c7                	mov    eax,edi
  4a86a1:	e8 9a db 22 00       	call   0x6d6240
  4a86a6:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4a86a9:	85 c0                	test   eax,eax
  4a86ab:	74 29                	je     0x4a86d6
  4a86ad:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4a86af:	8b 14 b1             	mov    edx,DWORD PTR [ecx+esi*4]
  4a86b2:	89 10                	mov    DWORD PTR [eax],edx
  4a86b4:	83 47 04 04          	add    DWORD PTR [edi+0x4],0x4
  4a86b8:	5e                   	pop    esi
  4a86b9:	c3                   	ret
  4a86ba:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  4a86bd:	75 0c                	jne    0x4a86cb
  4a86bf:	b9 01 00 00 00       	mov    ecx,0x1
  4a86c4:	8b c7                	mov    eax,edi
  4a86c6:	e8 75 db 22 00       	call   0x6d6240
  4a86cb:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4a86ce:	85 c0                	test   eax,eax
  4a86d0:	74 04                	je     0x4a86d6
  4a86d2:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4a86d4:	89 08                	mov    DWORD PTR [eax],ecx
  4a86d6:	83 47 04 04          	add    DWORD PTR [edi+0x4],0x4
  4a86da:	5e                   	pop    esi
  4a86db:	c3                   	ret
  4a86dc:	cc                   	int3
  4a86dd:	cc                   	int3
  4a86de:	cc                   	int3
  4a86df:	cc                   	int3
  4a86e0:	a1 64 72 fb 00       	mov    eax,ds:0xfb7264
  4a86e5:	56                   	push   esi
  4a86e6:	8b 35 60 72 fb 00    	mov    esi,DWORD PTR ds:0xfb7260
  4a86ec:	3b f0                	cmp    esi,eax
```

## 4. 偽碼邊界／未知

- 本地解析 vector 與 4-byte message 是**兩套不同證據鏈**；目前沒有原生 xref 把它們閉合。
- 間接 call 的真實目標須抓 vtable `+0x10` 的具體實作與入口所有權，並核對 T02 已有協定，不改 T02 專屬原稿。
- QuestInfo id15／16 內容未取得（SHA `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`）；`TutorialBase.lua` 缺（SHA `26e5fe047b3489b5198023571d0dce712af2c81f57aa767d42ca7744`）。標記 `DEFERRED-LOCAL-RESOURCE`。
