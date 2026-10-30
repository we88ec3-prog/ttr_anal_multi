# E19 — RR-0001／RR-0004：A02C 直接引用窮舉、encoded frame transform、佇列消費與返回值（KR BIN-first）

日期：2026-10-29T18:31:15+08:00。
版本：KR `Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪即時計算確認；原件唯讀，不執行/patch。
main 已發布 RR-0001（T02 P0）及 RR-0004（T02 P0）仍 QUEUED；此文件為跨 Task 支援，不正式認領、改台帳或表示 S00 ACCEPTED。

## 1. 新增一手結論

### 1.1 A02C 的直接 32-bit displacement xref 是兩處，非全域 writer 完整證明

在完整原始 BIN `.text` 中查找 little-endian 四 byte `2c a0 00 00`，限定到 executable raw 0x400..0x7D0600，只找到 `VA 0x805D04`（`0x805D02: mov byte [esi+0xA02C],2`）和 `VA 0x806205`（`0x806202: movsx eax,byte [esi+0xA02C]`）。因此**直接使用同一位移常數**的 writer 目前只有 init `0x805D02`；不能排除先計算地址/指標別名或 memcpy 的間接寫入。不得宣稱 A02C 全程永遠等於 2。

### 1.2 非零 mode 均匯入 encoded builder

在 `0x806202..0x80623F`，mode=0 直接 `0x807A70`；mode≠0 的值無論 1/2/其他都通過 `0x80621E` 進 `0x807830`；builder 返回 0 才落到 `0x807A70`。這裡的 `sub/dec/je` 沒有各自不同的轉換 handler，應避免把 mode 1 和 2 宣告為兩種 confirmed wire format。

### 1.3 807830 的資料轉換與 checksum bytes 是首次有界閉合

`0x80786D: lea eax,[edi+6]` 並以 `0x807887 cmp eax,0x1000`、`0x807892 test edi,edi`、`0x8078A2 cmp edx,0x4000` 進行容量/空包 gate。`0x807870: mov dword [ebp-0x101A],0x7D810BBB`，為小端 byte 順序 `bb 0b 81 7d`；`0x80787A` 再寫 2-byte length。之後 `0x8078FD` 讀 payload 第一 byte，`0x807901 xor dl,0xB6`，迴圈 `0x807967..0x80799C` 逐 byte 與相鄰 payload bytes XOR，並在 `0x807974`,`0x80798E`,`0x8079C9` 加總 byte 至 16-bit accumulator。`0x8079E9..` 把這些 checksum 及 header 寫入目標緩衝。此為本地 framed transform，不以這些 bytes 宣稱 Server 已協定接受。

### 1.4 8061A0 的業務角色：pending-list drain → global outgoing staging；不等於 WSASend

在 `0x8061E6` 取得 connection `+0xA074` 待送 linked-list head。`0x8061F6..0x80622F` 選 builder；成功後 `0x80624F..0x806275` unlink 舊 list node，`0x80626A call 0x89120C` 釋放，`0x806275 dec [esi+0xA078]` 減少佇列 count。`0x8062F0..0x80635D` 則將 pending descriptor 插進另一個全域 pool/list (`0xFE3368` 等)，更新 `0xFE3374`、`0xFE337C`；尾端 `0x8063BA..0x8063DB` 釋放同步鎖並返回 `0/1`。故 `0x8061A0` 的 success = **本地封包建構+佇列交接**，不是已確認 Winsock 傳送成功；仍需追 `0x8068B0 WSASend` 與 global pool consumer。

### 1.5 有界失敗路徑

`0x80623F test eax,eax` 若 encoded fallback builder 也失敗，`0x806246 je 0x8063A4`；`0x8063A4 cmp [esi+0xA0B4],1` 且 `0x8063AD cmp [ebp-0x18],0`，在特定組合下 `0x8063B3 mov [ebp-0x1C],0`；否則返回初始 1。不可把返回 1 當已傳完所有封包，也不可在無上下文時把 fallback 定義成「網路明文傳送」：它僅是另一個本地 frame builder。

## 2. 依據性質與 RR 完成界線

- 已確認（原始 BIN）：A02C 直接參照 2 處，mode 非零均進 807830，first builder 的 XOR+checksum 演算骨架，builder 成功後 linked-list node 被摘除並交給全域 pool；失敗條件和 bounded ret gate。
- 推測：`0x807830` encoded frame 可能供對端 decoder；相容 Server 必須再比對接收端 0x2633/0x22D7 和真正 outgoing bytes；不可將推測升成官方編碼契約。
- RR-0001 待辦：conn-specific first send event/schedule, actual emitted frame kind, first incoming parser/dispatcher, socket slot/Connect pairing。
- RR-0004 待辦：A02C indirect alias writer（直接 xref 搜尋不是完整所有 writer 證明）、0x807830 failure reason distribution、fallback 被呼叫後的真實 socket wire/type、對端兼容性。
- 其他 RR 受影響：RR-0005（登入後每次 Connect 的首送）、RR-0006（parser/checksum 下游）以及 RR-0007（S2C dispatch）。RR-0002/0003/0008 的 login/select 消費者仍無新閉合，不能稱整八筆完成。
- Client 待逆向：以上 wire 與 writer 缺口；Server 待開發：只依確認的 framing 制定可測規格；跨功能待整合：T02/T03/T05，E01–E18 場景資料仍需獨立來源；待遊玩驗證：尚無 socket trace 或原 Client/Server 測試。

## 3. 可重現重驗

```python
from pathlib import Path
from hashlib import sha256
b=Path('Tartaros.bin').read_bytes()
assert sha256(b).hexdigest()=='9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91'
p=(0xA02C).to_bytes(4,'little')
print([hex(i+0x400C00) for i in range(0x400,0x7D0600) if b[i:i+4]==p])
# expected ['0x805d04','0x806205']
```

## 4. 原始 objdump 位址證據視窗（完整節選）

### 0x805CF0–0x805D25（raw 0x4050F0–0x405125）
```asm
  805cf0:	bd 00 eb 02 33       	mov    ebp,0x3302eb00
  805cf5:	ff 8d 86 20 50 00    	dec    DWORD PTR [ebp+0x502086]
  805cfb:	00 89 be 1c 50 00    	add    BYTE PTR [ecx+0x501cbe],cl
  805d01:	00 c6                	add    dh,al
  805d03:	86 2c a0             	xchg   BYTE PTR [eax+eiz*4],ch
  805d06:	00 00                	add    BYTE PTR [eax],al
  805d08:	02 89 86 20 a0 00    	add    cl,BYTE PTR [ecx+0xa02086]
  805d0e:	00 88 9e 24 a0 00    	add    BYTE PTR [eax+0xa0249e],cl
  805d14:	00 89 9e 28 a0 00    	add    BYTE PTR [ecx+0xa0289e],cl
  805d1a:	00 89 5d fc 89 9e    	add    BYTE PTR [ecx-0x617603a3],cl
  805d20:	4c                   	dec    esp
  805d21:	a0 00 00 33        	mov    al,ds:0xc0330000
```

### 0x8061E6–0x80627B（raw 0x4055E6–0x40567B）
```asm
  8061e6:	8b 86 74 a0 00 00    	mov    eax,DWORD PTR [esi+0xa074]
  8061ec:	8b 18                	mov    ebx,DWORD PTR [eax]
  8061ee:	3b d8                	cmp    ebx,eax
  8061f0:	0f 84 c4 01 00 00    	je     0x8063ba
  8061f6:	8b 7b 08             	mov    edi,DWORD PTR [ebx+0x8]
  8061f9:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  8061fc:	8d 47 08             	lea    eax,[edi+0x8]
  8061ff:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  806202:	0f be 86 2c a0 00 00 	movsx  eax,BYTE PTR [esi+0xa02c]
  806209:	83 e8 00             	sub    eax,0x0
  80620c:	8d 8e 1c 50 00 00    	lea    ecx,[esi+0x501c]
  806212:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  806215:	89 55 e0             	mov    DWORD PTR [ebp-0x20],edx
  806218:	74 15                	je     0x80622f
  80621a:	48                   	dec    eax
  80621b:	74 01                	je     0x80621e
  80621d:	48                   	dec    eax
  80621e:	52                   	push   edx
  80621f:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  806222:	52                   	push   edx
  806223:	e8 08 16 00 00       	call   0x807830
  806228:	85 c0                	test   eax,eax
  80622a:	75 23                	jne    0x80624f
  80622c:	8b 55 e0             	mov    edx,DWORD PTR [ebp-0x20]
  80622f:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  806232:	52                   	push   edx
  806233:	50                   	push   eax
  806234:	8d be 1c 50 00 00    	lea    edi,[esi+0x501c]
  80623a:	e8 31 18 00 00       	call   0x807a70
  80623f:	85 c0                	test   eax,eax
  806241:	0f 95 c0             	setne  al
  806244:	84 c0                	test   al,al
  806246:	0f 84 58 01 00 00    	je     0x8063a4
  80624c:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  80624f:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  806251:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  806254:	3b 9e 74 a0 00 00    	cmp    ebx,DWORD PTR [esi+0xa074]
  80625a:	74 1f                	je     0x80627b
  80625c:	8b 43 04             	mov    eax,DWORD PTR [ebx+0x4]
  80625f:	89 08                	mov    DWORD PTR [eax],ecx
  806261:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  806263:	8b 53 04             	mov    edx,DWORD PTR [ebx+0x4]
  806266:	53                   	push   ebx
  806267:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  80626a:	e8 9d af 08 00       	call   0x89120c
  80626f:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  806272:	83 c4 04             	add    esp,0x4
  806275:	ff 8e 78 a0 00 00    	dec    DWORD PTR [esi+0xa078]
```

### 0x8062F0–0x8063DB（raw 0x4056F0–0x4057DB）
```asm
  8062f0:	8b 3d 70 33 fe 00    	mov    edi,DWORD PTR ds:0xfe3370
  8062f6:	03 3d 74 33 fe 00    	add    edi,DWORD PTR ds:0xfe3374
  8062fc:	a1 6c 33 fe 00       	mov    eax,ds:0xfe336c
  806301:	8b f7                	mov    esi,edi
  806303:	c1 ee 02             	shr    esi,0x2
  806306:	3b c6                	cmp    eax,esi
  806308:	77 02                	ja     0x80630c
  80630a:	2b f0                	sub    esi,eax
  80630c:	8b 0d 68 33 fe 00    	mov    ecx,DWORD PTR ds:0xfe3368
  806312:	83 3c b1 00          	cmp    DWORD PTR [ecx+esi*4],0x0
  806316:	75 17                	jne    0x80632f
  806318:	6a 10                	push   0x10
  80631a:	e8 49 af 08 00       	call   0x891268
  80631f:	83 c4 04             	add    esp,0x4
  806322:	85 c0                	test   eax,eax
  806324:	74 56                	je     0x80637c
  806326:	8b 15 68 33 fe 00    	mov    edx,DWORD PTR ds:0xfe3368
  80632c:	89 04 b2             	mov    DWORD PTR [edx+esi*4],eax
  80632f:	a1 68 33 fe 00       	mov    eax,ds:0xfe3368
  806334:	8b 0c b0             	mov    ecx,DWORD PTR [eax+esi*4]
  806337:	83 e7 03             	and    edi,0x3
  80633a:	8d 04 b9             	lea    eax,[ecx+edi*4]
  80633d:	85 c0                	test   eax,eax
  80633f:	74 05                	je     0x806346
  806341:	8b 55 ec             	mov    edx,DWORD PTR [ebp-0x14]
  806344:	89 10                	mov    DWORD PTR [eax],edx
  806346:	a1 80 33 fe 00       	mov    eax,ds:0xfe3380
  80634b:	be 01 00 00 00       	mov    esi,0x1
  806350:	01 35 74 33 fe 00    	add    DWORD PTR ds:0xfe3374,esi
  806356:	29 35 7c 33 fe 00    	sub    DWORD PTR ds:0xfe337c,esi
  80635c:	50                   	push   eax
  80635d:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  806363:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  806366:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  806369:	89 75 e8             	mov    DWORD PTR [ebp-0x18],esi
  80636c:	8b f2                	mov    esi,edx
  80636e:	3b 8a 74 a0 00 00    	cmp    ecx,DWORD PTR [edx+0xa074]
  806374:	0f 85 7c fe ff ff    	jne    0x8061f6
  80637a:	eb 3e                	jmp    0x8063ba
  80637c:	8d 45 dc             	lea    eax,[ebp-0x24]
  80637f:	50                   	push   eax
  806380:	8d 4d d0             	lea    ecx,[ebp-0x30]
  806383:	c7 45 dc 00 00 00 00 	mov    DWORD PTR [ebp-0x24],0x0
  80638a:	e8 1a ad 08 00       	call   0x8910a9
  80638f:	68 a8 57 c8 00       	push   0xc857a8
  806394:	8d 4d d0             	lea    ecx,[ebp-0x30]
  806397:	51                   	push   ecx
  806398:	c7 45 d0 a4 2c bd 00 	mov    DWORD PTR [ebp-0x30],0xbd2ca4
  80639f:	e8 4c 66 09 00       	call   0x89c9f0
  8063a4:	83 be b4 a0 00 00 01 	cmp    DWORD PTR [esi+0xa0b4],0x1
  8063ab:	75 0d                	jne    0x8063ba
  8063ad:	83 7d e8 00          	cmp    DWORD PTR [ebp-0x18],0x0
  8063b1:	75 07                	jne    0x8063ba
  8063b3:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  8063ba:	8b 96 d4 a0 00 00    	mov    edx,DWORD PTR [esi+0xa0d4]
  8063c0:	52                   	push   edx
  8063c1:	ff 15 48 22 bd 00    	call   DWORD PTR ds:0xbd2248
  8063c7:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  8063ca:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  8063cd:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  8063d4:	59                   	pop    ecx
  8063d5:	5f                   	pop    edi
  8063d6:	5e                   	pop    esi
  8063d7:	5b                   	pop    ebx
  8063d8:	8b e5                	mov    esp,ebp
  8063da:	5d                   	pop    ebp
```

### 0x80786D–0x80790F（raw 0x406C6D–0x406D0F）
```asm
  80786d:	8d 47 06             	lea    eax,[edi+0x6]
  807870:	c7 85 e6 ef ff ff bb 	mov    DWORD PTR [ebp-0x101a],0x7d810bbb
  807877:	0b 81 7d 
  80787a:	66 89 bd e4 ef ff ff 	mov    WORD PTR [ebp-0x101c],di
  807881:	89 85 d8 ef ff ff    	mov    DWORD PTR [ebp-0x1028],eax
  807887:	3d 00 10 00 00       	cmp    eax,0x1000
  80788c:	0f 87 bb 01 00 00    	ja     0x807a4d
  807892:	85 ff                	test   edi,edi
  807894:	0f 84 b3 01 00 00    	je     0x807a4d
  80789a:	8b 96 0c 50 00 00    	mov    edx,DWORD PTR [esi+0x500c]
  8078a0:	03 d0                	add    edx,eax
  8078a2:	81 fa 00 40 00 00    	cmp    edx,0x4000
  8078a8:	76 0c                	jbe    0x8078b6
  8078aa:	8b 85 f0 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1010]
  8078b0:	50                   	push   eax
  8078b1:	e9 9e 01 00 00       	jmp    0x807a54
  8078b6:	8b 8e 04 50 00 00    	mov    ecx,DWORD PTR [esi+0x5004]
  8078bc:	8d 96 04 50 00 00    	lea    edx,[esi+0x5004]
  8078c2:	03 c1                	add    eax,ecx
  8078c4:	89 85 f4 ef ff ff    	mov    DWORD PTR [ebp-0x100c],eax
  8078ca:	8d 46 04             	lea    eax,[esi+0x4]
  8078cd:	89 8d dc ef ff ff    	mov    DWORD PTR [ebp-0x1024],ecx
  8078d3:	3b c8                	cmp    ecx,eax
  8078d5:	72 d3                	jb     0x8078aa
  8078d7:	3b ca                	cmp    ecx,edx
  8078d9:	73 cf                	jae    0x8078aa
  8078db:	8b 95 f4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x100c]
  8078e1:	3b d0                	cmp    edx,eax
  8078e3:	72 c5                	jb     0x8078aa
  8078e5:	8d 86 04 50 00 00    	lea    eax,[esi+0x5004]
  8078eb:	3b d0                	cmp    edx,eax
  8078ed:	73 bb                	jae    0x8078aa
  8078ef:	33 c0                	xor    eax,eax
  8078f1:	89 85 ec ef ff ff    	mov    DWORD PTR [ebp-0x1014],eax
  8078f7:	89 85 f4 ef ff ff    	mov    DWORD PTR [ebp-0x100c],eax
  8078fd:	8a 03                	mov    al,BYTE PTR [ebx]
  8078ff:	8a d0                	mov    dl,al
  807901:	80 f2 b6             	xor    dl,0xb6
  807904:	88 95 fc ef ff ff    	mov    BYTE PTR [ebp-0x1004],dl
  80790a:	0f b6 d0             	movzx  edx,al
  80790d:	b8 01          	mov    eax,0x1
```

### 0x807967–0x807A20（raw 0x406D67–0x406E20）
```asm
  807967:	8a 08                	mov    cl,BYTE PTR [eax]
  807969:	03 f0                	add    esi,eax
  80796b:	0f b6 1c 16          	movzx  ebx,BYTE PTR [esi+edx*1]
  80796f:	32 d9                	xor    bl,cl
  807971:	0f b6 c9             	movzx  ecx,cl
  807974:	66 01 8d ec ef ff ff 	add    WORD PTR [ebp-0x1014],cx
  80797b:	8a 48 01             	mov    cl,BYTE PTR [eax+0x1]
  80797e:	88 1e                	mov    BYTE PTR [esi],bl
  807980:	0f b6 18             	movzx  ebx,BYTE PTR [eax]
  807983:	8b b5 d0 ef ff ff    	mov    esi,DWORD PTR [ebp-0x1030]
  807989:	32 d9                	xor    bl,cl
  80798b:	0f b6 c9             	movzx  ecx,cl
  80798e:	66 01 8d f4 ef ff ff 	add    WORD PTR [ebp-0x100c],cx
  807995:	88 1c 06             	mov    BYTE PTR [esi+eax*1],bl
  807998:	83 c0 02             	add    eax,0x2
  80799b:	4f                   	dec    edi
  80799c:	75 c3                	jne    0x807961
  80799e:	8b 85 e0 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1020]
  8079a4:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  8079a7:	8b b5 cc ef ff ff    	mov    esi,DWORD PTR [ebp-0x1034]
  8079ad:	8b 9d d4 ef ff ff    	mov    ebx,DWORD PTR [ebp-0x102c]
  8079b3:	8b 8d dc ef ff ff    	mov    ecx,DWORD PTR [ebp-0x1024]
  8079b9:	3b c7                	cmp    eax,edi
  8079bb:	73 1a                	jae    0x8079d7
  8079bd:	8a 14 03             	mov    dl,BYTE PTR [ebx+eax*1]
  8079c0:	8a 5c 03 ff          	mov    bl,BYTE PTR [ebx+eax*1-0x1]
  8079c4:	32 da                	xor    bl,dl
  8079c6:	0f b6 d2             	movzx  edx,dl
  8079c9:	66 01 95 f8 ef ff ff 	add    WORD PTR [ebp-0x1008],dx
  8079d0:	88 9c 05 fc ef ff ff 	mov    BYTE PTR [ebp+eax*1-0x1004],bl
  8079d7:	8b 95 f4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x100c]
  8079dd:	03 95 ec ef ff ff    	add    edx,DWORD PTR [ebp-0x1014]
  8079e3:	01 95 f8 ef ff ff    	add    DWORD PTR [ebp-0x1008],edx
  8079e9:	8b 95 e4 ef ff ff    	mov    edx,DWORD PTR [ebp-0x101c]
  8079ef:	66 8b 85 f8 ef ff ff 	mov    ax,WORD PTR [ebp-0x1008]
  8079f6:	89 11                	mov    DWORD PTR [ecx],edx
  8079f8:	66 89 41 04          	mov    WORD PTR [ecx+0x4],ax
  8079fc:	8b 8e 04 50 00 00    	mov    ecx,DWORD PTR [esi+0x5004]
  807a02:	57                   	push   edi
  807a03:	8d 85 fc ef ff ff    	lea    eax,[ebp-0x1004]
  807a09:	50                   	push   eax
  807a0a:	83 c1 06             	add    ecx,0x6
  807a0d:	51                   	push   ecx
  807a0e:	e8 bd 61 09 00       	call   0x89dbd0
  807a13:	8b 85 d8 ef ff ff    	mov    eax,DWORD PTR [ebp-0x1028]
  807a19:	8b 95 f0 ef ff ff    	mov    edx,DWORD PTR [ebp-0x1010]
  807a1f:	01         	add    DWORD PTR [esi+0x500c],eax
```

## 5. 停止理由與下一段
本輪第 1 輪取得有意義新鏈：直接位移引用窮舉、encoded frame XOR 與 checksum 寫入、drain/pool 效果、具體失敗返回；符合重大有界新發現，因此 `E19-2` 與 `E19-3` 未啟動。尚待下一段以 `0xFE3368` pool consumer → `0x8068B0` 完成實際 socket output，並實際追 A02C alias。這不是 RR ACCEPTED / FULL-PASS；不修改 main 或 RR 台帳。