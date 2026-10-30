# T08-202 — 000A Actor／owner關聯、控制器3槽、pair效果消費與26／81／reset（BIN-first續證）

**產製：** 20261031-005014 Asia/Taipei；研究者 chatgpt-web roy。原始 KR Tartaros.bin `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes；`.text` VA401000/raw400，以下`raw=VA-400C00`。T08-202是接續而非新段號203。

**證據等級：** 下列指定原生路徑已取得直接bytes／CFG／caller／vtable交叉；不等於每一個可能dispatcher、所有Actor類型或動態時序的全球性完全證明。這份文件是 **202有界靜態研究成果 + 明確的未閉合全域writer清單**；未完成「所有possible owner-field writer」的窮舉，不能宣稱整個T08／S00／T01已通過。附錄保留前手階段稿（舊語句已註記不適用），以供全文追溯。

## 本次接續後新閉合的實際 consumer（超出原202草稿）

### A. pair從000A的 slot+8 登記，不是只存vector等後續猜測

`4AF920`對local owner、idA!=idB的每列呼叫controller vtable+8，六張已有RTTI表此槽均為 `5451D0`。將 `WORD(actorA+4), WORD(idB), DWORD(0)` 以8-byte項 append到 `controller+30..38` vector；idB不是Actor raw pointer。原202階段稿在`545390`的第一個reader即停下，現在已沿著 `5452C0` 同函式後半部續走至 `545B8A`。

**真正的第二pass：** `5459B7..545B32`逐8-byte pair，先用 `[entry+0]`主樹exact find 取得ActorA指標（`5459FC..545A4E`），如果找不到即 skip；讀`ActorA+E0` DWORD及`+E4` BYTE，然後 `545A6D..545A86` 取`[entry+2]` idB，於`545A5E..545A97`經controller vtable `+0x44` 呼叫。六表`+0x44`皆為`546EF0`。這是已證**實際虛擬consumer**，推翻「vector只被查找沒有生效下游」的舊停止理由。

`546EF0`確定將idB作WORD key查Actor主樹（`546F81..546FAC`），比較idB所查Actor與傳入ActorA的`+A0/+A4`數值，計算平方長度開根、角度，依門檻與actor狀態更新第三引數指向的5-byte狀態暫存（`+2` WORD flags，`+4` BYTE）。若有變更，返回碼與 `controller+58`、ActorA virtual `+0x58` 結合決定是否進一步寫入；這是**Client內部相對位置／狀態資料流**，不能提升為原版Server「控制權交換」規則。

`545AEB..545B13`若滿足分支，將`WORD(actorA+4)`（實際向DWORD槽寫入）與狀態BYTE塞入`FE38D0`，每筆5 bytes；`FE48D0`為目前累積byte count，守衛`count+5<=0x1000`。`545B38..545B71`當累積超過6 bytes時呼叫`[FBA854]->vtable+0x10(0,FE38D0,FE48D0)`；**此為本地管理器間接傳遞，不保證其就是socket wire封包**。此鏈已比草稿的lookup-only更接近玩家可見控制效果，但此vtable接下來的T02 socket路徑仍另證。

### B. controller派生差異，與真正上游 update tick

原BIN `.rdata` 每表 `slot+0x2C`（第11個）：

| RTTI/vtable | +2C update target | 對pair的有界結果 |
|---|---|---|
| `CController` / C0F944 | `5452C0` | 直接執行second pass（有+4 gate） |
| `CEmptyController` / C0F99C | `8DC2F0` | 空實作，**不能聲稱會消費pair** |
| `CMissionRoomController` / C0FA6C | `548350` | 有gate後 call `5452C0`，再派生附加程序 |
| `CSingleController` / C0FAC4 | `548A90` | 有gate後 call `5452C0`，再處理Actor槽與派生旗標 |
| `CTutorialController` / C0FB1C | `548CB0` | 有+4和+DC gates後 call `5452C0` |
| `CTagController` / BFB5A4 | `444670` | 條件執行`5452C0`及模式附加程序（詳附錄） |

**直接真實上游：** `491CAF call 40F060` 得 owner，`491CB6 call 4E0060`（所在caller有`[edi+BFCC]==0` gate）。`4E009B mov ecx,[FBA7A4]`，`4E00AB mov eax,[ecx]`，`4E00AD mov edx,[eax+2C]`，`4E00B0 call edx`；`owner+AC`浮點與`C5566C`比較後可能先設 `controller+58=1`，不阻止這條virtual call。這閉合了**主要本地update caller → 多型slot+2C → 5452C0 → pair第二pass → v44 → 狀態變更與管理器consumer**。仍不能從此單一路徑推得所有frame／所有mode都調度。

### C. owner record+4/+8 與移除：證明有界差異，不捏造清零

`4C6E50`於`4C6E57`寫`P+4 = eax`，其唯一經原始text直接`E8` callsite位於`4AEC83`（0007 producer），後續`4C6E89`寫`P+8 = WORD(Actor+88)`，無命中時`4C6E91`清`P+8=0`。另一實際已證 writer 為`4AF920` 000A的一般分支 i==0（直接覆寫P+4/P+8）；其特殊localOwner且idA!=idB分支不觸碰兩欄。`4C6EA0`於`54D189/54D239/54D2F8`被直接呼叫，經原件證明是**讀Actor+BC的reader**，不是 P+4 清零者。這些是具證據的寫入者集，並非宣稱消除了所有函式指標／alias writer。

**26**在`4B2A56..87`查controller三個raw Actor槽；命中待刪Actor key先 `vtable+14`一次清三槽，`4B2AC2`才`4DFBC0`主樹erase，沒有在這個caller更新P+4/+8。**81**在`4B3710→4DFC90`走主樹Actor+88 composite移除，所覆蓋窗口沒有同樣的controller clear；`4DFC90`無P+4/+8 writer。**type0 reset** `4B1A30`先用`4DFD40`刪type0 Actor，之後clear controller三槽、清 owner+F8、`4E1070`整批釋放次級P；因此它不必對已被釋放的P逐一清零，亦不是無條件全Actor reset。**次級指定刪除** `4BBAE0→4DFC30`直接釋放P與node，但沒有刪Actor本體。`4DFD40`依據Actor+4 BYTE過濾，不會呼叫`4C6E50`；部分路徑有 `7A7CC0/7A7BF0`子物件副作用，不能將其錯當owner記錄P writer。

因為 `P+4/+8`是**數值識別**而非Actor指標，26/81本體沒有清零不等於直接證明runtime use-after-free；上層收包順序、owner記錄重建、剩餘別名writer可解釋此現象。**全域清零writer與不同封包跨幀一致性目前尚未由完整靜態資料證明存在或不存在**，不能冒稱已解決；但各已證可達caller的副作用與保留界線已清楚閉合。

### D. 000A→控制槽→移除情境矩陣

| 原生輸入 | 實際Client分支 | Actor/controller/P變更 | 目前保留未知 |
|---|---|---|---|
| 本地索引10，B+2 owner，B+6 signed BYTE count，rows `WORD idA,idB` | record查找；local-owner時先v14清槽；idA!=idB append pair | 一般路設Actor+98/+9C與P+4/+8；特殊路只存pair | S2C wire opcode/完整長度、Server觸發 |
| 更新loop（非直接收包） | 491CB6→4E0060 virtual+2C；六類按派生表分流 | +4 gate與mode gate；pair第二pass比較Actor相對資料、寫暫存或5-byte manager buffer | FE38D0下游真正wire與遊戲觸發時序 |
| 命令26 | key命中controller 3槽才清全部slot，後主樹erase | raw Actor從controller清除；P數值未在caller清除 | 他處是否清P、跨封包排列 |
| 命令81 | composite匹配主樹Actor erase | 無相同controller clear/window内無P writer | 其他wrapper／上層mode是否已有解除 |
| 本地索引16（reset） | type0 erase→clear slots→owner+F8=0→釋放所有P | 非所有type皆被刪 | T07場景語意、Server相容場景時序 |
| 次級指定erase wrapper | 指定key delete P/node，保留主樹Actor | 不代表monster死亡 | 派生handler的真正wire domain |

**結論／停止界線：** 202本段核心的本地producer→writer→update consumer→已知移除次序已以第一手機器碼閉合。仍未將全域P別名寫入者或wire/domain→manager後續視為已完成；它們依精確範圍記為 Client 待逆向，原版Server策略、場景波次判定屬Server待開發／跨T07/T14，動態收包先後與遊玩場景屬待遊玩驗證。若以「全程所有清零writer必須驗完」定義更寬的202目標，則應維持 **202尚未完全完成／待原生全域xrefs**，而非另開203跳過此缺口。

## T01 接續結果

本次已另外產生T01六項狀態矩陣與五項原BIN定向修正技術筆記 `20261031-005014-chatgpt-web-roy-T08-T01-return-corrections-bounded.md`；24份legacy來源尚未逐篇重建，不可全部宣稱修復。T08-173/196依T01歷史RESOLVED保留。

## 附錄：新增第一手code windows

### `00491CA7..00491CD8` (raw `0x910A7..0x910D8`, stop排他)

```asm
491ca7:	39 b7 cc bf 00 00    	cmp    DWORD PTR [edi+0xbfcc],esi
  491cad:	75 54                	jne    0x491d03
  491caf:	e8 ac d3 f7 ff       	call   0x40f060
  491cb4:	8b c8                	mov    ecx,eax
  491cb6:	e8 a5 e3 04 00       	call   0x4e0060
  491cbb:	e8 a0 7f ff ff       	call   0x489c60
  491cc0:	50                   	push   eax
  491cc1:	e8 6a 78 ff ff       	call   0x489530
  491cc6:	e8 65 24 fa ff       	call   0x434130
  491ccb:	8b 08                	mov    ecx,DWORD PTR [eax]
  491ccd:	3b ce                	cmp    ecx,esi
  491ccf:	74 07                	je     0x491cd8
  491cd1:	8b 01                	mov    eax,DWORD PTR [ecx]
  491cd3:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  491cd6:	ff d2                	call   edx
```

### `004E0060..004E00C9` (raw `0xDF460..0xDF4C9`, stop排他)

```asm
4e0060:	55                   	push   ebp
  4e0061:	8b ec                	mov    ebp,esp
  4e0063:	6a ff                	push   0xffffffff
  4e0065:	68 ba b1 93 00       	push   0x93b1ba
  4e006a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4e0070:	50                   	push   eax
  4e0071:	83 ec 20             	sub    esp,0x20
  4e0074:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4e0079:	33 c5                	xor    eax,ebp
  4e007b:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  4e007e:	56                   	push   esi
  4e007f:	57                   	push   edi
  4e0080:	50                   	push   eax
  4e0081:	8d 45 f4             	lea    eax,[ebp-0xc]
  4e0084:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4e008a:	8b f9                	mov    edi,ecx
  4e008c:	f3 0f 10 87 ac 00 00 	movss  xmm0,DWORD PTR [edi+0xac]
  4e0093:	00 
  4e0094:	0f 2f 05 6c 56 c5 00 	comiss xmm0,DWORD PTR ds:0xc5566c
  4e009b:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4e00a1:	be 01 00 00 00       	mov    esi,0x1
  4e00a6:	76 03                	jbe    0x4e00ab
  4e00a8:	89 71 58             	mov    DWORD PTR [ecx+0x58],esi
  4e00ab:	8b 01                	mov    eax,DWORD PTR [ecx]
  4e00ad:	8b 50 2c             	mov    edx,DWORD PTR [eax+0x2c]
  4e00b0:	ff d2                	call   edx
  4e00b2:	8b 47 0c             	mov    eax,DWORD PTR [edi+0xc]
  4e00b5:	8b 08                	mov    ecx,DWORD PTR [eax]
  4e00b7:	c6 45 d4 00          	mov    BYTE PTR [ebp-0x2c],0x0
  4e00bb:	8b 55 d4             	mov    edx,DWORD PTR [ebp-0x2c]
  4e00be:	52                   	push   edx
  4e00bf:	50                   	push   eax
  4e00c0:	51                   	push   ecx
  4e00c1:	e8 2a 13 00 00       	call   0x4e13f0
  4e00c6:	83 c4 0c             	add    esp,0xc
```

### `005452C0..00545400` (raw `0x1446C0..0x144800`, stop排他)

```asm
5452c0:	55                   	push   ebp
  5452c1:	8b ec                	mov    ebp,esp
  5452c3:	83 e4 f8             	and    esp,0xfffffff8
  5452c6:	6a ff                	push   0xffffffff
  5452c8:	68 1c 3f 94 00       	push   0x943f1c
  5452cd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5452d3:	50                   	push   eax
  5452d4:	83 ec 30             	sub    esp,0x30
  5452d7:	53                   	push   ebx
  5452d8:	56                   	push   esi
  5452d9:	57                   	push   edi
  5452da:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5452df:	33 c4                	xor    eax,esp
  5452e1:	50                   	push   eax
  5452e2:	8d 44 24 40          	lea    eax,[esp+0x40]
  5452e6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5452ec:	8b f1                	mov    esi,ecx
  5452ee:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  5452f2:	83 7e 04 00          	cmp    DWORD PTR [esi+0x4],0x0
  5452f6:	0f 84 8e 08 00 00    	je     0x545b8a
  5452fc:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  545303:	75 29                	jne    0x54532e
  545305:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  54530c:	c7 44 24 48 00 00 00 	mov    DWORD PTR [esp+0x48],0x0
  545313:	00 
  545314:	e8 77 c2 f9 ff       	call   0x4e1590
  545319:	68 80 cc bc 00       	push   0xbccc80
  54531e:	e8 f7 cf 34 00       	call   0x89231a
  545323:	83 c4 04             	add    esp,0x4
  545326:	c7 44 24 48 ff ff ff 	mov    DWORD PTR [esp+0x48],0xffffffff
  54532d:	ff 
  54532e:	a1 3c 42 f9 00       	mov    eax,ds:0xf9423c
  545333:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  545337:	2b 46 64             	sub    eax,DWORD PTR [esi+0x64]
  54533a:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  54533e:	e8 6d 7b 00 00       	call   0x54ceb0
  545343:	83 c6 10             	add    esi,0x10
  545346:	bb 03 00 00 00       	mov    ebx,0x3
  54534b:	8b 06                	mov    eax,DWORD PTR [esi]
  54534d:	85 c0                	test   eax,eax
  54534f:	74 22                	je     0x545373
  545351:	e8 aa 9e 00 00       	call   0x54f200
  545356:	8b 46 fc             	mov    eax,DWORD PTR [esi-0x4]
  545359:	85 c0                	test   eax,eax
  54535b:	74 16                	je     0x545373
  54535d:	8b 80 58 01 00 00    	mov    eax,DWORD PTR [eax+0x158]
  545363:	83 78 08 03          	cmp    DWORD PTR [eax+0x8],0x3
  545367:	75 0a                	jne    0x545373
  545369:	8b 3e                	mov    edi,DWORD PTR [esi]
  54536b:	8d 7f 04             	lea    edi,[edi+0x4]
  54536e:	e8 fd 27 05 00       	call   0x597b70
  545373:	83 c6 0c             	add    esi,0xc
  545376:	4b                   	dec    ebx
  545377:	75 d2                	jne    0x54534b
  545379:	8b 5c 24 14          	mov    ebx,DWORD PTR [esp+0x14]
  54537d:	8b 4b 34             	mov    ecx,DWORD PTR [ebx+0x34]
  545380:	2b 4b 30             	sub    ecx,DWORD PTR [ebx+0x30]
  545383:	33 ff                	xor    edi,edi
  545385:	c1 f9 03             	sar    ecx,0x3
  545388:	85 c9                	test   ecx,ecx
  54538a:	74 74                	je     0x545400
  54538c:	8d 64 24 00          	lea    esp,[esp+0x0]
  545390:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  545397:	8b 53 30             	mov    edx,DWORD PTR [ebx+0x30]
  54539a:	8d 34 fa             	lea    esi,[edx+edi*8]
  54539d:	75 29                	jne    0x5453c8
  54539f:	b8 01 00 00 00       	mov    eax,0x1
  5453a4:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  5453aa:	89 44 24 48          	mov    DWORD PTR [esp+0x48],eax
  5453ae:	e8 dd 98 f9 ff       	call   0x4dec90
  5453b3:	68 30 ce bc 00       	push   0xbcce30
  5453b8:	e8 5d cf 34 00       	call   0x89231a
  5453bd:	83 c4 04             	add    esp,0x4
  5453c0:	c7 44 24 48 ff ff ff 	mov    DWORD PTR [esp+0x48],0xffffffff
  5453c7:	ff 
  5453c8:	a1 3c b1 fa 00       	mov    eax,ds:0xfab13c
  5453cd:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  5453d0:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  5453d4:	0f b7 0e             	movzx  ecx,WORD PTR [esi]
  5453d7:	75 19                	jne    0x5453f2
  5453d9:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  5453e0:	39 48 0c             	cmp    DWORD PTR [eax+0xc],ecx
  5453e3:	73 05                	jae    0x5453ea
  5453e5:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  5453e8:	eb 02                	jmp    0x5453ec
  5453ea:	8b 00                	mov    eax,DWORD PTR [eax]
  5453ec:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  5453f0:	74 ee                	je     0x5453e0
  5453f2:	8b 4b 34             	mov    ecx,DWORD PTR [ebx+0x34]
  5453f5:	2b 4b 30             	sub    ecx,DWORD PTR [ebx+0x30]
  5453f8:	47                   	inc    edi
  5453f9:	c1 f9 03             	sar    ecx,0x3
  5453fc:	3b f9                	cmp    edi,ecx
  5453fe:	72 90                	jb     0x545390
```

### `0054598B..00545B9F` (raw `0x144D8B..0x144F9F`, stop排他)

```asm
54598b:	e8 20 18 00 00       	call   0x5471b0
  545990:	47                   	inc    edi
  545991:	83 ff 03             	cmp    edi,0x3
  545994:	0f 8c fb fe ff ff    	jl     0x545895
  54599a:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  54599e:	8b 48 34             	mov    ecx,DWORD PTR [eax+0x34]
  5459a1:	2b 48 30             	sub    ecx,DWORD PTR [eax+0x30]
  5459a4:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  5459ab:	00 
  5459ac:	c1 f9 03             	sar    ecx,0x3
  5459af:	85 c9                	test   ecx,ecx
  5459b1:	0f 84 81 01 00 00    	je     0x545b38
  5459b7:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  5459bb:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  5459bf:	8b 72 30             	mov    esi,DWORD PTR [edx+0x30]
  5459c2:	03 c0                	add    eax,eax
  5459c4:	03 c0                	add    eax,eax
  5459c6:	03 c0                	add    eax,eax
  5459c8:	03 f0                	add    esi,eax
  5459ca:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  5459d1:	75 29                	jne    0x5459fc
  5459d3:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  5459da:	c7 44 24 48 11 00 00 	mov    DWORD PTR [esp+0x48],0x11
  5459e1:	00 
  5459e2:	e8 a9 92 f9 ff       	call   0x4dec90
  5459e7:	68 30 ce bc 00       	push   0xbcce30
  5459ec:	e8 29 c9 34 00       	call   0x89231a
  5459f1:	83 c4 04             	add    esp,0x4
  5459f4:	c7 44 24 48 ff ff ff 	mov    DWORD PTR [esp+0x48],0xffffffff
  5459fb:	ff 
  5459fc:	0f b7 16             	movzx  edx,WORD PTR [esi]
  5459ff:	8b 35 3c b1 fa 00    	mov    esi,DWORD PTR ds:0xfab13c
  545a05:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  545a08:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  545a0c:	8b ce                	mov    ecx,esi
  545a0e:	75 14                	jne    0x545a24
  545a10:	39 50 0c             	cmp    DWORD PTR [eax+0xc],edx
  545a13:	73 05                	jae    0x545a1a
  545a15:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  545a18:	eb 04                	jmp    0x545a1e
  545a1a:	8b c8                	mov    ecx,eax
  545a1c:	8b 00                	mov    eax,DWORD PTR [eax]
  545a1e:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  545a22:	74 ec                	je     0x545a10
  545a24:	89 4c 24 20          	mov    DWORD PTR [esp+0x20],ecx
  545a28:	3b ce                	cmp    ecx,esi
  545a2a:	74 0b                	je     0x545a37
  545a2c:	3b 51 0c             	cmp    edx,DWORD PTR [ecx+0xc]
  545a2f:	72 06                	jb     0x545a37
  545a31:	8d 44 24 20          	lea    eax,[esp+0x20]
  545a35:	eb 08                	jmp    0x545a3f
  545a37:	89 74 24 24          	mov    DWORD PTR [esp+0x24],esi
  545a3b:	8d 44 24 24          	lea    eax,[esp+0x24]
  545a3f:	8b 00                	mov    eax,DWORD PTR [eax]
  545a41:	3b c6                	cmp    eax,esi
  545a43:	0f 84 d1 00 00 00    	je     0x545b1a
  545a49:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  545a4c:	85 f6                	test   esi,esi
  545a4e:	0f 84 c6 00 00 00    	je     0x545b1a
  545a54:	8b 86 e0 00 00 00    	mov    eax,DWORD PTR [esi+0xe0]
  545a5a:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  545a5e:	8b 17                	mov    edx,DWORD PTR [edi]
  545a60:	8b 52 44             	mov    edx,DWORD PTR [edx+0x44]
  545a63:	89 44 24 2c          	mov    DWORD PTR [esp+0x2c],eax
  545a67:	8a 8e e4 00 00 00    	mov    cl,BYTE PTR [esi+0xe4]
  545a6d:	8b 47 30             	mov    eax,DWORD PTR [edi+0x30]
  545a70:	88 4c 24 30          	mov    BYTE PTR [esp+0x30],cl
  545a74:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  545a78:	8a 9e b0 00 00 00    	mov    bl,BYTE PTR [esi+0xb0]
  545a7e:	03 c9                	add    ecx,ecx
  545a80:	03 c9                	add    ecx,ecx
  545a82:	03 c9                	add    ecx,ecx
  545a84:	03 c1                	add    eax,ecx
  545a86:	0f b7 40 02          	movzx  eax,WORD PTR [eax+0x2]
  545a8a:	8d 4c 24 2c          	lea    ecx,[esp+0x2c]
  545a8e:	51                   	push   ecx
  545a8f:	56                   	push   esi
  545a90:	50                   	push   eax
  545a91:	8b cf                	mov    ecx,edi
  545a93:	88 5c 24 28          	mov    BYTE PTR [esp+0x28],bl
  545a97:	ff d2                	call   edx
  545a99:	85 c0                	test   eax,eax
  545a9b:	74 0f                	je     0x545aac
  545a9d:	83 7f 58 00          	cmp    DWORD PTR [edi+0x58],0x0
  545aa1:	74 33                	je     0x545ad6
  545aa3:	33 c0                	xor    eax,eax
  545aa5:	66 89 44 24 2e       	mov    WORD PTR [esp+0x2e],ax
  545aaa:	eb 18                	jmp    0x545ac4
  545aac:	83 7f 58 00          	cmp    DWORD PTR [edi+0x58],0x0
  545ab0:	74 68                	je     0x545b1a
  545ab2:	b8 00 80 00 00       	mov    eax,0x8000
  545ab7:	66 85 47 6a          	test   WORD PTR [edi+0x6a],ax
  545abb:	74 5d                	je     0x545b1a
  545abd:	33 c9                	xor    ecx,ecx
  545abf:	66 89 4c 24 2e       	mov    WORD PTR [esp+0x2e],cx
  545ac4:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  545ac8:	88 5c 24 30          	mov    BYTE PTR [esp+0x30],bl
  545acc:	8b 16                	mov    edx,DWORD PTR [esi]
  545ace:	8b 52 58             	mov    edx,DWORD PTR [edx+0x58]
  545ad1:	50                   	push   eax
  545ad2:	8b ce                	mov    ecx,esi
  545ad4:	ff d2                	call   edx
  545ad6:	83 7c 24 18 00       	cmp    DWORD PTR [esp+0x18],0x0
  545adb:	8a 4c 24 30          	mov    cl,BYTE PTR [esp+0x30]
  545adf:	75 0a                	jne    0x545aeb
  545ae1:	8b 44 24 2c          	mov    eax,DWORD PTR [esp+0x2c]
  545ae5:	89 47 68             	mov    DWORD PTR [edi+0x68],eax
  545ae8:	88 4f 6c             	mov    BYTE PTR [edi+0x6c],cl
  545aeb:	66 8b 56 04          	mov    dx,WORD PTR [esi+0x4]
  545aef:	a1 d0 48 fe 00       	mov    eax,ds:0xfe48d0
  545af4:	66 89 54 24 2c       	mov    WORD PTR [esp+0x2c],dx
  545af9:	8d 50 05             	lea    edx,[eax+0x5]
  545afc:	81 fa 00 10 00 00    	cmp    edx,0x1000
  545b02:	77 16                	ja     0x545b1a
  545b04:	8b 54 24 2c          	mov    edx,DWORD PTR [esp+0x2c]
  545b08:	8d 80 d0 38 fe 00    	lea    eax,[eax+0xfe38d0]
  545b0e:	89 10                	mov    DWORD PTR [eax],edx
  545b10:	88 48 04             	mov    BYTE PTR [eax+0x4],cl
  545b13:	83 05 d0 48 fe 00 05 	add    DWORD PTR ds:0xfe48d0,0x5
  545b1a:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  545b1e:	8b 51 34             	mov    edx,DWORD PTR [ecx+0x34]
  545b21:	2b 51 30             	sub    edx,DWORD PTR [ecx+0x30]
  545b24:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  545b28:	40                   	inc    eax
  545b29:	c1 fa 03             	sar    edx,0x3
  545b2c:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  545b30:	3b c2                	cmp    eax,edx
  545b32:	0f 82 7f fe ff ff    	jb     0x5459b7
  545b38:	83 3d d0 48 fe 00 06 	cmp    DWORD PTR ds:0xfe48d0,0x6
  545b3f:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  545b43:	76 2e                	jbe    0x545b73
  545b45:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  545b49:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  545b4f:	ff 0d b0 a7 fb 00    	dec    DWORD PTR ds:0xfba7b0
  545b55:	c7 46 74 00 00 00 00 	mov    DWORD PTR [esi+0x74],0x0
  545b5c:	89 46 64             	mov    DWORD PTR [esi+0x64],eax
  545b5f:	a1 d0 48 fe 00       	mov    eax,ds:0xfe48d0
  545b64:	8b 11                	mov    edx,DWORD PTR [ecx]
  545b66:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  545b69:	50                   	push   eax
  545b6a:	68 d0 38 fe 00       	push   0xfe38d0
  545b6f:	6a 00                	push   0x0
  545b71:	ff d2                	call   edx
  545b73:	8b 5c 24 14          	mov    ebx,DWORD PTR [esp+0x14]
  545b77:	33 c0                	xor    eax,eax
  545b79:	66 89 46 5c          	mov    WORD PTR [esi+0x5c],ax
  545b7d:	83 7b 58 00          	cmp    DWORD PTR [ebx+0x58],0x0
  545b81:	74 07                	je     0x545b8a
  545b83:	c7 43 58 00 00 00 00 	mov    DWORD PTR [ebx+0x58],0x0
  545b8a:	33 c0                	xor    eax,eax
  545b8c:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
  545b90:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  545b97:	59                   	pop    ecx
  545b98:	5f                   	pop    edi
  545b99:	5e                   	pop    esi
  545b9a:	5b                   	pop    ebx
  545b9b:	8b e5                	mov    esp,ebp
  545b9d:	5d                   	pop    ebp
  545b9e:	c3                   	ret
```

### `00546EF0..005471AA` (raw `0x1462F0..0x1465AA`, stop排他)

```asm
546ef0:	55                   	push   ebp
  546ef1:	8b ec                	mov    ebp,esp
  546ef3:	83 e4 f8             	and    esp,0xfffffff8
  546ef6:	6a ff                	push   0xffffffff
  546ef8:	68 8e 66 93 00       	push   0x93668e
  546efd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  546f03:	50                   	push   eax
  546f04:	83 ec 30             	sub    esp,0x30
  546f07:	53                   	push   ebx
  546f08:	56                   	push   esi
  546f09:	57                   	push   edi
  546f0a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  546f0f:	33 c4                	xor    eax,esp
  546f11:	50                   	push   eax
  546f12:	8d 44 24 40          	lea    eax,[esp+0x40]
  546f16:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  546f1c:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
  546f1f:	85 ff                	test   edi,edi
  546f21:	75 17                	jne    0x546f3a
  546f23:	33 c0                	xor    eax,eax
  546f25:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
  546f29:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  546f30:	59                   	pop    ecx
  546f31:	5f                   	pop    edi
  546f32:	5e                   	pop    esi
  546f33:	5b                   	pop    ebx
  546f34:	8b e5                	mov    esp,ebp
  546f36:	5d                   	pop    ebp
  546f37:	c2 0c 00             	ret    0xc
  546f3a:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  546f41:	8b 87 e0 00 00 00    	mov    eax,DWORD PTR [edi+0xe0]
  546f47:	8a 9f e4 00 00 00    	mov    bl,BYTE PTR [edi+0xe4]
  546f4d:	89 44 24 2c          	mov    DWORD PTR [esp+0x2c],eax
  546f51:	c6 44 24 17 00       	mov    BYTE PTR [esp+0x17],0x0
  546f56:	75 29                	jne    0x546f81
  546f58:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  546f5f:	c7 44 24 48 00 00 00 	mov    DWORD PTR [esp+0x48],0x0
  546f66:	00 
  546f67:	e8 24 7d f9 ff       	call   0x4dec90
  546f6c:	68 30 ce bc 00       	push   0xbcce30
  546f71:	e8 a4 b3 34 00       	call   0x89231a
  546f76:	83 c4 04             	add    esp,0x4
  546f79:	c7 44 24 48 ff ff ff 	mov    DWORD PTR [esp+0x48],0xffffffff
  546f80:	ff 
  546f81:	0f b7 4d 08          	movzx  ecx,WORD PTR [ebp+0x8]
  546f85:	8d 54 24 1c          	lea    edx,[esp+0x1c]
  546f89:	89 4c 24 1c          	mov    DWORD PTR [esp+0x1c],ecx
  546f8d:	52                   	push   edx
  546f8e:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  546f92:	b9 38 b1 fa 00       	mov    ecx,0xfab138
  546f97:	e8 64 7f 2e 00       	call   0x82ef00
  546f9c:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  546fa0:	3b 05 3c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab13c
  546fa6:	75 04                	jne    0x546fac
  546fa8:	33 c0                	xor    eax,eax
  546faa:	eb 03                	jmp    0x546faf
  546fac:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  546faf:	8b 88 a0 00 00 00    	mov    ecx,DWORD PTR [eax+0xa0]
  546fb5:	8b 90 a4 00 00 00    	mov    edx,DWORD PTR [eax+0xa4]
  546fbb:	8b 87 a0 00 00 00    	mov    eax,DWORD PTR [edi+0xa0]
  546fc1:	89 4c 24 24          	mov    DWORD PTR [esp+0x24],ecx
  546fc5:	d9 44 24 24          	fld    DWORD PTR [esp+0x24]
  546fc9:	8b 8f a4 00 00 00    	mov    ecx,DWORD PTR [edi+0xa4]
  546fcf:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  546fd3:	d8 64 24 1c          	fsub   DWORD PTR [esp+0x1c]
  546fd7:	89 54 24 28          	mov    DWORD PTR [esp+0x28],edx
  546fdb:	89 4c 24 20          	mov    DWORD PTR [esp+0x20],ecx
  546fdf:	d9 5c 24 18          	fstp   DWORD PTR [esp+0x18]
  546fe3:	d9 44 24 18          	fld    DWORD PTR [esp+0x18]
  546fe7:	d9 5c 24 34          	fstp   DWORD PTR [esp+0x34]
  546feb:	d9 44 24 28          	fld    DWORD PTR [esp+0x28]
  546fef:	d8 64 24 20          	fsub   DWORD PTR [esp+0x20]
  546ff3:	d9 5c 24 1c          	fstp   DWORD PTR [esp+0x1c]
  546ff7:	d9 44 24 1c          	fld    DWORD PTR [esp+0x1c]
  546ffb:	d9 5c 24 38          	fstp   DWORD PTR [esp+0x38]
  546fff:	d9 44 24 38          	fld    DWORD PTR [esp+0x38]
  547003:	d9 44 24 34          	fld    DWORD PTR [esp+0x34]
  547007:	dc c8                	fmul   st(0),st
  547009:	d9 c1                	fld    st(1)
  54700b:	de ca                	fmulp  st(2),st
  54700d:	de c1                	faddp  st(1),st
  54700f:	d9 5c 24 24          	fstp   DWORD PTR [esp+0x24]
  547013:	d9 44 24 24          	fld    DWORD PTR [esp+0x24]
  547017:	e8 54 88 3b 00       	call   0x8ff870
  54701c:	d9 5c 24 24          	fstp   DWORD PTR [esp+0x24]
  547020:	d9 05 c0 56 c5 00    	fld    DWORD PTR ds:0xc556c0
  547026:	8b 75 10             	mov    esi,DWORD PTR [ebp+0x10]
  547029:	d9 44 24 24          	fld    DWORD PTR [esp+0x24]
  54702d:	df f1                	fcomip st,st(1)
  54702f:	dd d8                	fstp   st(0)
  547031:	0f 86 88 00 00 00    	jbe    0x5470bf
  547037:	d9 44 24 1c          	fld    DWORD PTR [esp+0x1c]
  54703b:	ba 00 80 00 00       	mov    edx,0x8000
  547040:	d9 44 24 18          	fld    DWORD PTR [esp+0x18]
  547044:	66 09 56 02          	or     WORD PTR [esi+0x2],dx
  547048:	e8 7d 7d 3b 00       	call   0x8fedca
  54704d:	d9 5c 24 24          	fstp   DWORD PTR [esp+0x24]
  547051:	d9 44 24 24          	fld    DWORD PTR [esp+0x24]
  547055:	51                   	push   ecx
  547056:	dc 05 28 58 c5 00    	fadd   QWORD PTR ds:0xc55828
  54705c:	d9 5c 24 28          	fstp   DWORD PTR [esp+0x28]
  547060:	d9 44 24 28          	fld    DWORD PTR [esp+0x28]
  547064:	d9 1c 24             	fstp   DWORD PTR [esp]
  547067:	e8 e4 43 f7 ff       	call   0x4bb450
  54706c:	d9 44 24 1c          	fld    DWORD PTR [esp+0x1c]
  547070:	83 c4 04             	add    esp,0x4
  547073:	d9 5c 24 34          	fstp   DWORD PTR [esp+0x34]
  547077:	88 46 04             	mov    BYTE PTR [esi+0x4],al
  54707a:	d9 44 24 1c          	fld    DWORD PTR [esp+0x1c]
  54707e:	d9 5c 24 38          	fstp   DWORD PTR [esp+0x38]
  547082:	d9 44 24 38          	fld    DWORD PTR [esp+0x38]
  547086:	d9 44 24 34          	fld    DWORD PTR [esp+0x34]
  54708a:	dc c8                	fmul   st(0),st
  54708c:	d9 c1                	fld    st(1)
  54708e:	de ca                	fmulp  st(2),st
  547090:	de c1                	faddp  st(1),st
  547092:	d9 5c 24 24          	fstp   DWORD PTR [esp+0x24]
  547096:	d9 44 24 24          	fld    DWORD PTR [esp+0x24]
  54709a:	e8 d1 87 3b 00       	call   0x8ff870
  54709f:	d9 5c 24 24          	fstp   DWORD PTR [esp+0x24]
  5470a3:	d9 05 3c 5a c5 00    	fld    DWORD PTR ds:0xc55a3c
  5470a9:	d9 44 24 24          	fld    DWORD PTR [esp+0x24]
  5470ad:	df f1                	fcomip st,st(1)
  5470af:	dd d8                	fstp   st(0)
  5470b1:	76 15                	jbe    0x5470c8
  5470b3:	66 83 4e 02 02       	or     WORD PTR [esi+0x2],0x2
  5470b8:	c6 44 24 17 01       	mov    BYTE PTR [esp+0x17],0x1
  5470bd:	eb 09                	jmp    0x5470c8
  5470bf:	b8 ff 7f 00 00       	mov    eax,0x7fff
  5470c4:	66 21 46 02          	and    WORD PTR [esi+0x2],ax
  5470c8:	8b 87 58 01 00 00    	mov    eax,DWORD PTR [edi+0x158]
  5470ce:	85 c0                	test   eax,eax
  5470d0:	74 11                	je     0x5470e3
  5470d2:	83 78 2c 00          	cmp    DWORD PTR [eax+0x2c],0x0
  5470d6:	74 0b                	je     0x5470e3
  5470d8:	8b cf                	mov    ecx,edi
  5470da:	e8 f1 2d f8 ff       	call   0x4c9ed0
  5470df:	85 c0                	test   eax,eax
  5470e1:	74 09                	je     0x5470ec
  5470e3:	b9 00 80 00 00       	mov    ecx,0x8000
  5470e8:	66 21 4e 02          	and    WORD PTR [esi+0x2],cx
  5470ec:	66 8b 46 02          	mov    ax,WORD PTR [esi+0x2]
  5470f0:	ba ff 7f 00 00       	mov    edx,0x7fff
  5470f5:	66 23 c2             	and    ax,dx
  5470f8:	74 04                	je     0x5470fe
  5470fa:	66 89 46 02          	mov    WORD PTR [esi+0x2],ax
  5470fe:	8b 87 58 01 00 00    	mov    eax,DWORD PTR [edi+0x158]
  547104:	85 c0                	test   eax,eax
  547106:	74 67                	je     0x54716f
  547108:	83 78 30 00          	cmp    DWORD PTR [eax+0x30],0x0
  54710c:	74 61                	je     0x54716f
  54710e:	8b cf                	mov    ecx,edi
  547110:	e8 bb 2d f8 ff       	call   0x4c9ed0
  547115:	85 c0                	test   eax,eax
  547117:	75 56                	jne    0x54716f
  547119:	0f b7 46 02          	movzx  eax,WORD PTR [esi+0x2]
  54711d:	a9 00 80 00 00       	test   eax,0x8000
  547122:	74 40                	je     0x547164
  547124:	0f b6 46 04          	movzx  eax,BYTE PTR [esi+0x4]
  547128:	3a c3                	cmp    al,bl
  54712a:	74 0f                	je     0x54713b
  54712c:	8b 17                	mov    edx,DWORD PTR [edi]
  54712e:	50                   	push   eax
  54712f:	8b 42 58             	mov    eax,DWORD PTR [edx+0x58]
  547132:	8b cf                	mov    ecx,edi
  547134:	ff d0                	call   eax
  547136:	c6 44 24 17 01       	mov    BYTE PTR [esp+0x17],0x1
  54713b:	8b bf 58 01 00 00    	mov    edi,DWORD PTR [edi+0x158]
  547141:	85 ff                	test   edi,edi
  547143:	74 05                	je     0x54714a
  547145:	8b 47 28             	mov    eax,DWORD PTR [edi+0x28]
  547148:	eb 02                	jmp    0x54714c
  54714a:	33 c0                	xor    eax,eax
  54714c:	66 8b 4e 02          	mov    cx,WORD PTR [esi+0x2]
  547150:	ba ff 7f 00 00       	mov    edx,0x7fff
  547155:	66 23 ca             	and    cx,dx
  547158:	c1 e0 0f             	shl    eax,0xf
  54715b:	66 0b c8             	or     cx,ax
  54715e:	66 89 4e 02          	mov    WORD PTR [esi+0x2],cx
  547162:	eb 14                	jmp    0x547178
  547164:	25 ff 7f 00 00       	and    eax,0x7fff
  547169:	66 89 46 02          	mov    WORD PTR [esi+0x2],ax
  54716d:	eb 09                	jmp    0x547178
  54716f:	b8 ff 7f 00 00       	mov    eax,0x7fff
  547174:	66 21 46 02          	and    WORD PTR [esi+0x2],ax
  547178:	66 8b 4e 02          	mov    cx,WORD PTR [esi+0x2]
  54717c:	66 33 4c 24 2e       	xor    cx,WORD PTR [esp+0x2e]
  547181:	ba 00 80 00 00       	mov    edx,0x8000
  547186:	66 85 ca             	test   dx,cx
  547189:	74 05                	je     0x547190
  54718b:	c6 44 24 17 01       	mov    BYTE PTR [esp+0x17],0x1
  547190:	0f b6 44 24 17       	movzx  eax,BYTE PTR [esp+0x17]
  547195:	8b 4c 24 40          	mov    ecx,DWORD PTR [esp+0x40]
  547199:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5471a0:	59                   	pop    ecx
  5471a1:	5f                   	pop    edi
  5471a2:	5e                   	pop    esi
  5471a3:	5b                   	pop    ebx
  5471a4:	8b e5                	mov    esp,ebp
  5471a6:	5d                   	pop    ebp
  5471a7:	c2 0c 00             	ret    0xc
```

### `00548A90..00548B2F` (raw `0x147E90..0x147F2F`, stop排他)

```asm
548a90:	55                   	push   ebp
  548a91:	8b ec                	mov    ebp,esp
  548a93:	6a ff                	push   0xffffffff
  548a95:	68 2e 53 94 00       	push   0x94532e
  548a9a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  548aa0:	50                   	push   eax
  548aa1:	51                   	push   ecx
  548aa2:	53                   	push   ebx
  548aa3:	56                   	push   esi
  548aa4:	57                   	push   edi
  548aa5:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  548aaa:	33 c5                	xor    eax,ebp
  548aac:	50                   	push   eax
  548aad:	8d 45 f4             	lea    eax,[ebp-0xc]
  548ab0:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  548ab6:	8b f9                	mov    edi,ecx
  548ab8:	83 7f 04 00          	cmp    DWORD PTR [edi+0x4],0x0
  548abc:	75 14                	jne    0x548ad2
  548abe:	33 c0                	xor    eax,eax
  548ac0:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  548ac3:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  548aca:	59                   	pop    ecx
  548acb:	5f                   	pop    edi
  548acc:	5e                   	pop    esi
  548acd:	5b                   	pop    ebx
  548ace:	8b e5                	mov    esp,ebp
  548ad0:	5d                   	pop    ebp
  548ad1:	c3                   	ret
  548ad2:	e8 e9 c7 ff ff       	call   0x5452c0
  548ad7:	8b 77 0c             	mov    esi,DWORD PTR [edi+0xc]
  548ada:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  548add:	85 f6                	test   esi,esi
  548adf:	74 3f                	je     0x548b20
  548ae1:	8b 86 58 01 00 00    	mov    eax,DWORD PTR [esi+0x158]
  548ae7:	33 db                	xor    ebx,ebx
  548ae9:	85 c0                	test   eax,eax
  548aeb:	74 03                	je     0x548af0
  548aed:	8b 58 30             	mov    ebx,DWORD PTR [eax+0x30]
  548af0:	8b ce                	mov    ecx,esi
  548af2:	e8 d9 13 f8 ff       	call   0x4c9ed0
  548af7:	85 db                	test   ebx,ebx
  548af9:	74 25                	je     0x548b20
  548afb:	85 c0                	test   eax,eax
  548afd:	75 21                	jne    0x548b20
  548aff:	8b 86 58 01 00 00    	mov    eax,DWORD PTR [esi+0x158]
  548b05:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  548b08:	83 f8 01             	cmp    eax,0x1
  548b0b:	74 05                	je     0x548b12
  548b0d:	83 f8 02             	cmp    eax,0x2
  548b10:	75 0e                	jne    0x548b20
  548b12:	8d 8f 88 00 00 00    	lea    ecx,[edi+0x88]
  548b18:	56                   	push   esi
  548b19:	e8 a2 3a f5 ff       	call   0x49c5c0
  548b1e:	eb 0e                	jmp    0x548b2e
  548b20:	33 c0                	xor    eax,eax
  548b22:	89 87 a4 00 00 00    	mov    DWORD PTR [edi+0xa4],eax
  548b28:	89 87 ac 00 00 00    	mov    DWORD PTR [edi+0xac],eax
  548b2e:	f6                   	.byte 0xf6
```

### `00548CB0..00548D0D` (raw `0x1480B0..0x14810D`, stop排他)

```asm
548cb0:	56                   	push   esi
  548cb1:	8b f1                	mov    esi,ecx
  548cb3:	83 7e 04 00          	cmp    DWORD PTR [esi+0x4],0x0
  548cb7:	75 04                	jne    0x548cbd
  548cb9:	33 c0                	xor    eax,eax
  548cbb:	5e                   	pop    esi
  548cbc:	c3                   	ret
  548cbd:	83 be dc 00 00 00 00 	cmp    DWORD PTR [esi+0xdc],0x0
  548cc4:	74 f3                	je     0x548cb9
  548cc6:	57                   	push   edi
  548cc7:	e8 f4 c5 ff ff       	call   0x5452c0
  548ccc:	83 7e 0c 00          	cmp    DWORD PTR [esi+0xc],0x0
  548cd0:	8b f8                	mov    edi,eax
  548cd2:	75 05                	jne    0x548cd9
  548cd4:	5f                   	pop    edi
  548cd5:	33 c0                	xor    eax,eax
  548cd7:	5e                   	pop    esi
  548cd8:	c3                   	ret
  548cd9:	e8 82 bc ef ff       	call   0x444960
  548cde:	80 b8 e1 07 00 00 01 	cmp    BYTE PTR [eax+0x7e1],0x1
  548ce5:	75 13                	jne    0x548cfa
  548ce7:	6a 01                	push   0x1
  548ce9:	e8 62 b5 ee ff       	call   0x434250
  548cee:	8b c8                	mov    ecx,eax
  548cf0:	e8 0b bd ff ff       	call   0x544a00
  548cf5:	8b c7                	mov    eax,edi
  548cf7:	5f                   	pop    edi
  548cf8:	5e                   	pop    esi
  548cf9:	c3                   	ret
  548cfa:	6a 00                	push   0x0
  548cfc:	e8 4f b5 ee ff       	call   0x434250
  548d01:	8b c8                	mov    ecx,eax
  548d03:	e8 f8 bc ff ff       	call   0x544a00
  548d08:	8b c7                	mov    eax,edi
  548d0a:	5f                   	pop    edi
  548d0b:	5e                   	pop    esi
  548d0c:	c3                   	ret
```

### `005471B0..005471D8` (raw `0x1465B0..0x1465D8`, stop排他)

```asm
5471b0:	a1 d0 48 fe 00       	mov    eax,ds:0xfe48d0
  5471b5:	8d 50 05             	lea    edx,[eax+0x5]
  5471b8:	81 fa 00 10 00 00    	cmp    edx,0x1000
  5471be:	77 17                	ja     0x5471d7
  5471c0:	8b 11                	mov    edx,DWORD PTR [ecx]
  5471c2:	8d 80 d0 38 fe 00    	lea    eax,[eax+0xfe38d0]
  5471c8:	89 10                	mov    DWORD PTR [eax],edx
  5471ca:	8a 49 04             	mov    cl,BYTE PTR [ecx+0x4]
  5471cd:	88 48 04             	mov    BYTE PTR [eax+0x4],cl
  5471d0:	83 05 d0 48 fe 00 05 	add    DWORD PTR ds:0xfe48d0,0x5
  5471d7:	c3                   	ret
```

### `004C6E50..004C6E9D` (raw `0xC6250..0xC629D`, stop排他)

```asm
4c6e50:	55                   	push   ebp
  4c6e51:	8b ec                	mov    ebp,esp
  4c6e53:	83 ec 08             	sub    esp,0x8
  4c6e56:	56                   	push   esi
  4c6e57:	89 47 04             	mov    DWORD PTR [edi+0x4],eax
  4c6e5a:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4c6e5d:	e8 fe 81 f4 ff       	call   0x40f060
  4c6e62:	8b f0                	mov    esi,eax
  4c6e64:	8d 45 fc             	lea    eax,[ebp-0x4]
  4c6e67:	50                   	push   eax
  4c6e68:	8d 4e 08             	lea    ecx,[esi+0x8]
  4c6e6b:	8d 45 f8             	lea    eax,[ebp-0x8]
  4c6e6e:	e8 8d 80 36 00       	call   0x82ef00
  4c6e73:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  4c6e76:	3b 46 0c             	cmp    eax,DWORD PTR [esi+0xc]
  4c6e79:	74 16                	je     0x4c6e91
  4c6e7b:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4c6e7e:	85 c0                	test   eax,eax
  4c6e80:	74 0f                	je     0x4c6e91
  4c6e82:	0f b7 88 88 00 00 00 	movzx  ecx,WORD PTR [eax+0x88]
  4c6e89:	89 4f 08             	mov    DWORD PTR [edi+0x8],ecx
  4c6e8c:	5e                   	pop    esi
  4c6e8d:	8b e5                	mov    esp,ebp
  4c6e8f:	5d                   	pop    ebp
  4c6e90:	c3                   	ret
  4c6e91:	c7 47 08 00 00 00 00 	mov    DWORD PTR [edi+0x8],0x0
  4c6e98:	5e                   	pop    esi
  4c6e99:	8b e5                	mov    esp,ebp
  4c6e9b:	5d                   	pop    ebp
  4c6e9c:	c3                   	ret
```

## 附錄：原交接時的202階段性保存原文

以下保留2026-10-31 00:38交接時舊正文／12個原組語窗口；其中「第一輪已完成門檻」「本次提交」皆為**當時草擬語句，非真正提交或新規則已達成的證據**。若與以上新增分析／停止邊界衝突，以上新原BIN核對與實際Git回讀為準。


---

# T08-202 階段性未完成：新對話保存稿

- 交接產製時間：2026-10-31T00:38:48.967829+08:00，Asia/Taipei。
- **狀態：202研究已啟動，只有既有正文草稿與離線查驗；尚未完成整體靜態目標、未正式提交、無Commit／Push收據。下一對話續完202，不能直接跳203。**
- 原正文是本對話實際保存的206行文字，另保留未修改的 `T08-202-original-body-draft.md`。以下正文僅修正完成／提交狀態的章名及舊停止判定，技術主張仍待下一對話按目標逐項重驗，不是假稱完成的新研究。
- 原稿寫「達門檻」「本次提交」的語句屬尚未執行的草擬意圖；最新02已取消固定三輪與重大發現停止門檻。本保存稿上方狀態優先。
- 附錄為此次交接重新由相同BIN解出的有界窗口，以免新對話只剩摘要；這是保存證據，不將202升格為完成或FULL-PASS。
- 原BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。

---

# T08-202 — 000A owner/Actor關聯、控制槽與移除同步邊界

研究者：`chatgpt-web roy`。本稿為接續201的正式大型批次，原始KR BIN-first，非從對話恢復摘要。時間、來源SHA與機器碼附錄由產製程序填入。使用者本次明確授權完成後將所有完整分析提交GitHub main；本稿與201最終合併稿為本次兩份正式原稿，04不提交。

## 1. 新發現與停止門檻

1. **已確認：000A的第一個ID不一定代表主樹Actor。** `4AF920`先以buffer+2的DWORD查**次級0x2C記錄樹**；記錄不存在／payload空，直接返回0x80004005。記錄存在後才依buffer+7起的兩WORD pair查主樹。這把201已證的次級資料生產者（本地索引8）接到另一個真實consumer（本地索引10）。
2. **已確認：同owner與跨owner是不同資料流。** owner==`[404BA0()+0x5F50]`時先呼叫控制器slot+0x14、slot+0xC；每列兩WORD不等且owner匹配時，只將actor與第二WORD交slot+8，不執行該列一般actor+0x98／+0x9C、record+4／+8寫入。其他情況走一般關聯寫入，再有條件加入控制槽。
3. **已確認：控制器是真正的第三種持有者，與兩樹分開。** `545040`在controller+0xC/+0x18/+0x24三個slot存**原始Actor指標**，slot stride=0xC；slot的另一DWORD指向0x14 bytes歷史／狀態項，該項又由controller+0x48樹持有。它既不是次級0x2C owner記錄，也不是CDoll控制塊。
4. **已確認：具體virtual清理與getter不同。** 原BIN RTTI辨識CController、CEmptyController、CMissionRoomController、CSingleController、CTutorialController、CTagController。這六張表的slot+4=545040、+8=5451D0、+0x1C=545290；slot+0x14多為545210，CTagController例外444910。兩種clear均清三slot與關聯佇列；slot+0x1C僅回傳指標。000A呼叫的slot+0xC/+0x10在這六表都指向單指令ret的5F5D10，不能從呼叫位置想像出額外開始／完成動作。
5. **已確認：命令26有條件性全slot清除，generic erase本身沒有。** `4B2A56`掃三slot，匹配待刪Actor WORD key時調slot+0x14，**把三slot一起清除**，然後才4DFBC0；4DFBC0內部三次slot+0x1C對上述六型別只是getter，不能視作清理。這補上201所留「移除與其他持有者」的具體同步點。
6. **已確認：次級指定刪除和全清有不同上層。** `4BBAE0`從buffer+2 DWORD呼叫4DFC30刪次級記錄；本地表索引16的4B1A30則先按type0刪主樹、clear控制槽、清owner+F8快取，再清次級樹。二者不可稱為同一種Actor死亡包；也不能將該reset稱為完整全場景清除，因為主樹filter明確是type0。

舊稿曾按當時三輪門檻判斷局部進展；本次交接依2026-10-30新版02重新標示為階段性未完成，不能以重大發現或局部鏈代替整體目標達成。

## 2. 來源、版本、責任與既有修正

使用本Project 02／T08專屬03、本次對話已有04與201完整版；原BIN唯讀、PE section映射核對，未執行／附加遊戲或patch。GitHub開工時main=`609665d38c53b2d2734b9cc9e7c42e8b4abc3757`，重讀AGENTS、T08 README、本地追查矩陣與相關bulk偽碼；T08 README blob仍為`e99f9517e741335847ae7c76fe4edfd018428693`，退回條目未新增。

201已提供157與196主要勘誤，173／187指定窗口修正及LEGACY-MAPPING的來源缺口；本次一併提交201最終合併完整版，保留舊原稿不覆寫。沒有把T01驗收／READY／RESOLVED或Task native_complete擅自改為通過。本稿只改自己的`kr-temp-roy/`，不更新其他Task owner/catalog。

201指出4DFC90是**主樹**，第二樹為4DFC30；本稿沿用修正後定義，不再用錯誤「雙樹均析構actor」前提。CController等類名本輪有原始RTTI支持；「owner記錄」「歷史項」「關聯佇列」仍為行為暫名，不替原版命名用途。T02 socket/framing與其他Task關卡決策只引用，不接管。

## 3. 000A完整有界資料流

### 3.1 handler引數與格式

`4ADD50`在base+0x54寫4AF920，與201已驗的4FDA30表consumer符合本地索引10。此處仍稱「既有S2C 000A標記／本地索引10」，沒有新增socket→wire域全鏈證明。

令B=`[ebp+8]`，第三引數屬分派命令域；L=`[ebp+0xC]`雖被上層傳入，**此handler本體不讀L作長度驗證**。buffer欄位：

| buffer offset | 原始讀法 | consumer／寫入 | 界線 |
|---|---|---|---|
| +0..1 | 本handler不解析其含義 | 保留header域 | 不捏造wire定義 |
| +2..5 | DWORD owner-key | FAB148次級樹查找；比對本地識別值 | 不直接是Actor指標 |
| +6 | signed BYTE count | `jle`／`movsx`，正數才進loop | 0x80..FF視負數、跳過loop，不是128..255筆 |
| +7+4*i | WORD idA | FAB138主樹查找，零擴展DWORD | actor必須已存在，否則診斷後下列 |
| +9+4*i | WORD idB | 與idA比較；特定分支交controller slot+8 | 未證idB是scene/Monster ID或正式控制權 |

對正count，若要滿足本handler已觀察的讀取，輸入至少需7+4*count bytes；這是靜態讀取範圍，不是原版framing驗收規則。缺失L檢查不構成runtime漏洞斷言：上游驗證仍待T02。

### 3.2 控制流程與分支表

先以u32(B+2)查owner次級樹，失敗／空payload→診斷、EAX=80004005、ret0xC。成功取得record P後，以owner-key==`[404BA0()+0x5F50]`計算localOwner布林。

localOwner時，在處理任何row前對全域`[FBA7A4]`依序call vtable+0x14、+0xC；最後不論count是否為0或負數，仍call vtable+0x10。這六種已核對型別的+C/+10都是ret，但+14確有清槽實作，因此**count<=0也可能清掉原控制slot**。

| owner匹配 | idA與idB | actor查找 | 這列作用 |
|---|---|---|---|
| 任意 | 任意 | 缺失／空 | 診斷，跳4AFAB7前進；不因一列缺失中止整包 |
| true | 不同 | 命中A | slot+8(idB, actorA)；跳過一般關聯寫入與slot+4 |
| true | 相同 | 命中A | 一般關聯寫入，再slot+4(actorA) |
| false | 相同或不同 | 命中A | 一般關聯寫入；不加入本地controller三slot |

一般關聯分支對**實際i==0**設actor+0x98=1、P+4=idA，並查主樹重取Actor，把其+0x88低WORD零擴展寫P+8（失敗則0）。對i>0設actor+0x98=0，但不更新P+4/+8。所有一般分支都設actor+0x9C=P[0]。

**第一列不等於第一個成功row。** 若i0找不到或走idA!=idB的localOwner特殊分支，後面i1成功不會補設P+4/+8或actor+98=1；本輪沒有證實這是錯誤，可能由上游格式約束。要保留原始i條件，不可把偽碼重寫成firstSuccessful。

### 3.3 與201的建立包資料關聯

0007一般尾端在主樹登記後，只於record存在且P+4==0時才4C6E50綁定；000A一般分支對i0則直接覆寫P+4/P+8，**沒有P+4==0的保護**。這是實質不同的writer權限／更新語意，不能把000A視為0007的純重播。

二者共同以數值key關聯，不持有Actor raw pointer於P+4。raw pointer現在確定另存於controller slot，由下一節的0x14歷史項輔助。

## 4. 第三持有者：CController的實際類型、配置與三slot

### 4.1 vtable與原始RTTI

以下表由BIN原始DWORD／COL／TypeDescriptor讀回，並以base或派生建構vptr writer交叉，不只掃到某個函式位址就認定型別。後附raw bytes。

| 類別（RTTI） | vtable | +4 add | +8 pair | +C/+10 | +14 clear | +1C getter |
|---|---|---|---|---|---|---|
| CController | C0F944 | 545040 | 5451D0 | 5F5D10 | 545210 | 545290 |
| CEmptyController | C0F99C | 同上 | 同上 | 同上 | 同上 | 同上 |
| CMissionRoomController | C0FA6C | 同上 | 同上 | 同上 | 同上 | 同上 |
| CSingleController | C0FAC4 | 同上 | 同上 | 同上 | 同上 | 同上 |
| CTutorialController | C0FB1C | 同上 | 同上 | 同上 | 同上 | 同上 |
| CTagController | BFB5A4 | 同上 | 同上 | 同上 | **444910** | 同上 |

非六表的其他多型對象不在此宣稱。FBA7A4是可被替換的heap物件指標，不是固定全域內嵌controller。`4DEC90`預設配置0xB4→5471E0→544C40→最終vptr C0F99C，FBA7AC=0；42452B路徑配置0xB4→544C40後寫C0FA6C、mode1；436AC1配置0xC0→444210寫BFB5A4、mode6。CSingle／CTutorial的vptr writer亦在548540／548B90建構窗口；本稿不因類名推導模式玩法或Server規則。

base ctor544C40將三個slot的Actor指標、歷史項指標清0，旗標BYTE設1，另配置0x18 sentinel作controller+0x48歷史樹；同時將pair-array begin/end/capacity區與其他欄位初始化。

### 4.2 add slot+4=545040

1. 由controller+0xC起每0xC掃至3槽，找到第一個Actor指標為0的槽；三槽滿則直接返回，不覆寫、不刪Actor。沒有在此掃描相同Actor是否已在其他slot，故不據函式本體保證去重。
2. 設controller+4=1，slot.actor=傳入Actor。將Actor+4的WORD作key查controller+0x48樹。
3. 未命中：配置0x14 bytes歷史項H，其中WORD H+0=Actor key、WORD H+2=actor+0x88低WORD；H+4處有另一容器，其sentinel配置0x24，插入controller歷史樹（節點helper57EF20／82F200）。
4. 命中：取既有H，寫H.word0=Actor key；若H.word2與actor+88低WORD不同，先597B70(H+4)清其子容器，再更新word2。這是**同key與不同composite低WORD**的特定重設證據，不是所有重複ID一概共享相同狀態。
5. slot.history=H。三slot布局為：

| i | Actor raw pointer | H pointer | BYTE flag |
|---|---|---|---|
| 0 | controller+0x0C | +0x10 | +0x14 |
| 1 | controller+0x18 | +0x1C | +0x20 |
| 2 | controller+0x24 | +0x28 | +0x2C |

controller可持有raw Actor指標，但本函式不作Actor refcount增減，不可稱shared_ptr。H由controller歷史樹保存；clear slot不等於free H或Actor。

### 4.3 pair slot+8=5451D0與實際consumer限制

slot+8的第一引數為idB WORD，第二引數為ActorA pointer。它建8-byte暫存項：offset0 WORD=actorA+4、offset2 WORD=idB、offset4 DWORD=0；以controller+0x30為vector交4FC620 append8 bytes，cap不足可539180擴容。**這裡沒有存Actor raw pointer，記錄的是兩個WORD。**

另外核對5452C0的一段consumer（545379–545400）：讀vector長度、逐8-byte項取第一WORD，遍歷FAB138主樹作key比較。該窗口只見查找迴圈，沒有把結果寫入Actor或第二WORD派送；本稿**不把「已找到vector reader」擴張成控制切換／交換完整閉合**。更重要：不同controller的更新slot+0x2C不同，CEmptyController該槽為8DC2F0，不能從base5452C0存在保證每個模式每frame都消費。此處留下具體深追入口，而非自行補Server控制規則。

## 5. 三種清理與殘留邊界

### 5.1 clear slot+0x14

545210清三槽Actor／H指標、三flag設1，再將pair vector end=begin。這是解除slot引用／丟棄pair，沒有free Actor，沒有清controller+48歷史樹。444910同樣清Actor／H指標和pair vector，**flag0=1、flag1/2=0**；因此clear不代表所有派生型別重設值完全相同。兩段中copy-loop出現`cmp esi,esi`，固定走end更新，不可把不可達區作有效資料搬移。

545290則是**getter**：輸入0..2，回controller+0xC+12*i的raw Actor，超過2回0；完全沒有寫slot。5F5D10為單一ret；403DB0為xor al,al;ret，亦不能添上旗標／cleanup語意。

### 5.2 命令26與81的控制持有者差異

26的4B2A56–4B2A87會取待刪Actor WORD key，逐槽比對非空Actor+4；若匹配則call controller+0x14，一次clear全部三槽。之後4B2AC2才進4DFBC0刪主樹Actor。**此路已證明刪除前解除這三個slot的持有。** 但保留controller歷史樹中的H，不可把clear說成析構全部控制狀態。

反例交叉：4DFBC0內部在預清理前做3次controller+0x1C(index)，上述六表的目標是getter545290，返回值被忽略；本體無slot清空。81→4DFC90的已驗主樹composite erase也沒有相同controller clear呼叫。因此**不能把26 caller提供的安全順序概括為所有主樹移除都自帶**。本稿不將這些局部差異斷言為runtime dangling-pointer bug：還可能有其他caller、模式時序或上層reset。

### 5.3 owner記錄指定移除、type0 reset與查詢者

4BBAE0只讀B+2 DWORD key，ESI=FAB130，call4DFC30：查owner+18次級樹，若快取owner+F8非空且其首DWORD等key則清cache，直接free0x2C payload再erase node。此wrapper本體沒有Actor destructor或控制slot clear。由其特定派生handler初始化可見登記，但此段未閉合該擴展表的wire域；**不給它捏造opcode**。

4B1A30由4ADD50的base+84登記，即本地索引16：push type0→40F060→4DFD40主樹type filter；再controller clear+14；40F060取owner，設+F8=0；最後4E1070(owner+18)整批清次級記錄。順序是**type0 actor刪除在先、controller clear在後**，與26相反。主樹type1怪物未由該filter自動全部刪除；這不是無條件全Actor reset。相鄰索引17的4B1A70只push type1→4DFD40，沒有相同次級清理尾端。

4C6EA0看起來靠近record綁定函式，但它實際是**查詢**：由輸入record+4取key查主樹，命中讀Actor+0xBC BYTE，缺失回AL=0。不能因鄰接4C6E50就把它當解除綁定writer。這是本輪探索中的否證。

**尚未閉合的核心：** 一般Actor指定刪除後，owner記錄P+4/+8是否由其他writer主動清0。本稿已證26清raw controller slot，卻不能把它誤當P+4/+8也已清除。P數值欄位的真正writer全貌與不同收包先後順序仍列本地／下段追查。

## 6. C++行為偽碼與分支保真

```cpp
Result handle10(Buffer B, uint32_t L, Domain cmd) {
  // 原碼不在這裡使用L驗證；header語意未命名。
  auto P = record_tree_find(u32(B+2));
  if (!P) return 0x80004005;
  bool local = u32(B+2) == context()->field5F50;
  if (local) { control->v14(); control->v0C(); }
  for (int i=0; i<int8_t(B[6]); ++i) {
    uint16_t a=u16(B+7+4*i), b=u16(B+9+4*i);
    Actor* A = main_tree_find(a);
    if (!A) { diagnostic(); continue; }
    if (local && a!=b) { control->v08(b,A); continue; }
    if (i==0) { A->field98=1; P->field4=a;
      auto again=main_tree_find(a);
      P->field8=again ? u16(again+0x88) : 0;
    } else { A->field98=0; }
    A->field9C=P->key;
    if (local) control->v04(A);
  }
  if (local) control->v10();
  return 0x100;
}
void before_remove26(Actor* A, Control* C) {
  for(int i=0;i<3;++i) if(C->slot[i].actor &&
      u16(C->slot[i].actor+4)==u16(A+4)) { C->v14(); break; }
  remove_actor_by_key(u16(A+4));
}
```

偽碼只覆蓋已驗欄位與成功／失敗分支，不是可部署原Server。使用vtable實值區分getter、no-op和clear；所有欄位名稱為行為註記，不將owner等同角色帳號／控制權策略。

## 7. 玩家情境矩陣與本地可驗收工作

| 原生資料／情境 | 已證handler與欄位 | writer及場景／持有者改變 | 原生確認 | 部分確認／合理推測 | Server資訊缺失／本地待查 |
|---|---|---|---|---|---|
| 既有000A標記，本地索引10 | 4AF920：owner、signed count、兩WORD | P+4/+8、A+98/+9C；本地匹配可加三slot或pair vector | 分支與值來源、真實controller類型／ABI | 玩家可控制對象／UI效果未動態驗收 | wire域、封包完整長度及發送理由 |
| 000A count<=0且owner匹配 | 同上 | 仍先clear三slot；無row寫入 | clear時機與+C/+10 no-op在六類成立 | 是否正式「清空控制」訊息尚未知 | 原生流量／上下文 |
| 命令26指定ID移除 | 4B28D0 WORD key | 若key在三slot則全slot clear，再主樹Actor清理 | 特定caller的解除raw pointer次序 | 畫面退場／操作焦點切換時序未驗收 | Server死亡／切場景因果不可推 |
| 命令81 composite移除 | 4B3710→4DFC90 | 主樹erase；無同樣clear在該窗口 | selector與直接清理差異 | 其他層保護未查齊 | 完整caller／controller模式時序 |
| 本地索引16 reset | 4B1A30 | type0主樹刪→clear control→清cache→次級全清 | 明確順序與type限制 | 不能叫完整全場景清除 | 關卡切換／Server決策要其他Task補證 |
| 次級指定刪除wrapper | 4BBAE0 DWORD owner key | cache清除（命中時）、free P與node | 非Actor deleting destructor | 不指定wire opcode、非已證死亡 | 派生表域與實際recv入口 |

本輪AI替代：無。待補開發：沒有新增協定實作，需原生證據到位後再制定恢復方案；沒有runtime遊玩驗收。

具體待接續：

1. T02以該BIN版本的原生trace把000A之B/L/第三引數接回socket/framing，尤其signed count與上游長度門檻；驗收需完整bytes，不以十進位handler index直接當wire opcode。
2. owner記錄P+4/+8的所有非初始化writer及清零路徑；對26／81／type0 reset各別記錄是否保留數值關聯。本輪未找到清零writer不能視為原版不存在。
3. controller+30 pair vector後續真正生效consumer與派生virtual+2C調度；545390的讀取窗口尚不足證控制對象交換。提供mode、兩WORD來源與實際Actor writer作驗收。
4. generic erase／81之外的上游reset與controller strong/raw引用生命週期；避免僅憑helper不clear便宣稱runtime bug。另需依法取得的完整相依檔及另經授權的本地動態診斷。
5. 次級erase派生表的命令域與場景狀態來源；跨T06/T07/T14引用，不自行定義波次／事件／OnDeath。

## 8. 歷史輪次筆記（舊規則；不可作本次完成判定）

| 輪次 | 入口／延伸 | 新證據／停止 |
|---|---|---|
| 202第一輪 | 從4C6EA0「可能解除綁定」入手否證為讀取；轉000A→次級record→三slot／history樹→六種RTTI／vtable→26與reset／次級erase順序交叉 | 取得新consumer、raw pointer持有者、具體clear／getter／no-op區分與指定刪除同步，完整有界進展達標 |
| 202-2 | 未啟動 | 第一輪已取得重大新證據，不為增加輪數重做 |
| 202-3 | 未啟動 | 同上；未虛構後續輪次 |

這個停止理由不是「所有Server／render已完成」；未解部分上列到具體地址與驗收條件。下段優先pair vector實際生效writer或owner數值關聯在Actor刪後的處置，不再把已證六表clear當未知重找。

## 9. 原擬Git交付範圍（尚未實際執行）

本次提交兩份正式完整原稿：201最終稿（含201-2、歷史勘誤及完整附錄）與本202稿。目錄中的`20261028-190354-...T08-201...`為較早產製的中間輸出，曾有窗口截斷且已由`190427`最終合併稿取代，移入暫存證據區，不作另一段或另一份正式成果提交。不是遺漏尚未交付的獨立研究。

201原稿的「未Commit／Push」是當時交付狀態；本次新授權後隨202一起首次提交，不倒寫歷史。提交前重查main、確認相同path不存在／內容無衝突，commit只含本研究者兩份原稿。若有其他對話同時更新main，保留其提交，以fast-forward或拒絕後重新核對方式處理，不force覆蓋。

遠端驗證以固定commit的完整blob讀回逐bytes比對本地與SHA256；僅檔名存在或hash檔存在不足以宣稱成功。真實SHA與逐檔驗證結果於對話及提交收據回報；研究本文不填尚未產生的commit SHA。04交接檔不在本次Git範圍。

## 10. 原始證據與方法

objdump對PE32以正確函式／窗口起點解碼，Python struct讀vtable、COL與TypeDescriptor；底層跳表／資料不當作機器碼。全檔線性搜尋只定位候選，實質結論回原始指令邊界與caller參數。201不重複盤點的核心資源/CDoll路徑僅引用。

輔助bulk `0x4af920.c` blob=`79c36adaba6be378569b4b3f60a96bc25d9b61d6`，其count與分支對照BIN後採用；反編譯prototype缺L／第三引數不代表原函式不由上層傳入。其他helper語意只對本稿指定窗口成立，不宣稱整函式所有用途或所有派生型別已完成驗收。


## 交接附錄：離線原始指令窗口


### 0x004AF920 至 0x004AFAF0（stop排他）

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004af920 <.text+0xae920>:
  4af920:	55                   	push   ebp
  4af921:	8b ec                	mov    ebp,esp
  4af923:	83 ec 14             	sub    esp,0x14
  4af926:	53                   	push   ebx
  4af927:	56                   	push   esi
  4af928:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  4af92b:	8b 5e 02             	mov    ebx,DWORD PTR [esi+0x2]
  4af92e:	57                   	push   edi
  4af92f:	e8 2c f7 f5 ff       	call   0x40f060
  4af934:	8b f8                	mov    edi,eax
  4af936:	8d 45 f8             	lea    eax,[ebp-0x8]
  4af939:	50                   	push   eax
  4af93a:	8d 4f 18             	lea    ecx,[edi+0x18]
  4af93d:	8d 45 fc             	lea    eax,[ebp-0x4]
  4af940:	89 5d f8             	mov    DWORD PTR [ebp-0x8],ebx
  4af943:	e8 78 3f 39 00       	call   0x8438c0
  4af948:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  4af94b:	3b 47 1c             	cmp    eax,DWORD PTR [edi+0x1c]
  4af94e:	74 0c                	je     0x4af95c
  4af950:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4af953:	33 db                	xor    ebx,ebx
  4af955:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  4af958:	3b c3                	cmp    eax,ebx
  4af95a:	75 1f                	jne    0x4af97b
  4af95c:	8b 4e 02             	mov    ecx,DWORD PTR [esi+0x2]
  4af95f:	51                   	push   ecx
  4af960:	68 40 6a c0 00       	push   0xc06a40
  4af965:	e8 f6 e1 23 00       	call   0x6edb60
  4af96a:	83 c4 08             	add    esp,0x8
  4af96d:	5f                   	pop    edi
  4af96e:	5e                   	pop    esi
  4af96f:	b8 05 40 00 80       	mov    eax,0x80004005
  4af974:	5b                   	pop    ebx
  4af975:	8b e5                	mov    esp,ebp
  4af977:	5d                   	pop    ebp
  4af978:	c2 0c 00             	ret    0xc
  4af97b:	89 5d f8             	mov    DWORD PTR [ebp-0x8],ebx
  4af97e:	e8 1d 52 f5 ff       	call   0x404ba0
  4af983:	8b 56 02             	mov    edx,DWORD PTR [esi+0x2]
  4af986:	3b 90 50 5f 00 00    	cmp    edx,DWORD PTR [eax+0x5f50]
  4af98c:	75 21                	jne    0x4af9af
  4af98e:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4af994:	8b 01                	mov    eax,DWORD PTR [ecx]
  4af996:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4af999:	ff d2                	call   edx
  4af99b:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4af9a1:	8b 01                	mov    eax,DWORD PTR [ecx]
  4af9a3:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  4af9a6:	ff d2                	call   edx
  4af9a8:	c7 45 f8 01 00 00 00 	mov    DWORD PTR [ebp-0x8],0x1
  4af9af:	38 5e 06             	cmp    BYTE PTR [esi+0x6],bl
  4af9b2:	0f 8e 0f 01 00 00    	jle    0x4afac7
  4af9b8:	eb 08                	jmp    0x4af9c2
  4af9ba:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  4af9c0:	8b f1                	mov    esi,ecx
  4af9c2:	0f b7 74 9e 07       	movzx  esi,WORD PTR [esi+ebx*4+0x7]
  4af9c7:	89 75 f4             	mov    DWORD PTR [ebp-0xc],esi
  4af9ca:	e8 91 f6 f5 ff       	call   0x40f060
  4af9cf:	8b f8                	mov    edi,eax
  4af9d1:	8d 45 f4             	lea    eax,[ebp-0xc]
  4af9d4:	50                   	push   eax
  4af9d5:	8d 4f 08             	lea    ecx,[edi+0x8]
  4af9d8:	8d 45 f0             	lea    eax,[ebp-0x10]
  4af9db:	e8 20 f5 37 00       	call   0x82ef00
  4af9e0:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  4af9e3:	3b 47 0c             	cmp    eax,DWORD PTR [edi+0xc]
  4af9e6:	74 07                	je     0x4af9ef
  4af9e8:	8b 78 10             	mov    edi,DWORD PTR [eax+0x10]
  4af9eb:	85 ff                	test   edi,edi
  4af9ed:	75 12                	jne    0x4afa01
  4af9ef:	68 70 6a c0 00       	push   0xc06a70
  4af9f4:	e8 67 e1 23 00       	call   0x6edb60
  4af9f9:	83 c4 04             	add    esp,0x4
  4af9fc:	e9 b6 00 00 00       	jmp    0x4afab7
  4afa01:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4afa04:	66 8b 4c 98 07       	mov    cx,WORD PTR [eax+ebx*4+0x7]
  4afa09:	66 3b 4c 98 09       	cmp    cx,WORD PTR [eax+ebx*4+0x9]
  4afa0e:	74 27                	je     0x4afa37
  4afa10:	83 7d f8 00          	cmp    DWORD PTR [ebp-0x8],0x0
  4afa14:	74 21                	je     0x4afa37
  4afa16:	e8 45 f6 f5 ff       	call   0x40f060
  4afa1b:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4afa1e:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4afa24:	0f b7 44 98 09       	movzx  eax,WORD PTR [eax+ebx*4+0x9]
  4afa29:	8b 11                	mov    edx,DWORD PTR [ecx]
  4afa2b:	8b 52 08             	mov    edx,DWORD PTR [edx+0x8]
  4afa2e:	57                   	push   edi
  4afa2f:	50                   	push   eax
  4afa30:	ff d2                	call   edx
  4afa32:	e9 80 00 00 00       	jmp    0x4afab7
  4afa37:	85 db                	test   ebx,ebx
  4afa39:	75 53                	jne    0x4afa8e
  4afa3b:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  4afa3e:	c7 87 98 00 00 00 01 	mov    DWORD PTR [edi+0x98],0x1
  4afa45:	00 00 00 
  4afa48:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  4afa4b:	89 75 f4             	mov    DWORD PTR [ebp-0xc],esi
  4afa4e:	e8 0d f6 f5 ff       	call   0x40f060
  4afa53:	8b f0                	mov    esi,eax
  4afa55:	8d 4d f4             	lea    ecx,[ebp-0xc]
  4afa58:	51                   	push   ecx
  4afa59:	8d 4e 08             	lea    ecx,[esi+0x8]
  4afa5c:	8d 45 ec             	lea    eax,[ebp-0x14]
  4afa5f:	e8 9c f4 37 00       	call   0x82ef00
  4afa64:	8b 45 ec             	mov    eax,DWORD PTR [ebp-0x14]
  4afa67:	3b 46 0c             	cmp    eax,DWORD PTR [esi+0xc]
  4afa6a:	74 16                	je     0x4afa82
  4afa6c:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4afa6f:	85 c0                	test   eax,eax
  4afa71:	74 0f                	je     0x4afa82
  4afa73:	0f b7 90 88 00 00 00 	movzx  edx,WORD PTR [eax+0x88]
  4afa7a:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  4afa7d:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  4afa80:	eb 16                	jmp    0x4afa98
  4afa82:	8b 4d fc             	mov    ecx,DWORD PTR [ebp-0x4]
  4afa85:	c7 41 08 00 00 00 00 	mov    DWORD PTR [ecx+0x8],0x0
  4afa8c:	eb 0a                	jmp    0x4afa98
  4afa8e:	c7 87 98 00 00 00 00 	mov    DWORD PTR [edi+0x98],0x0
  4afa95:	00 00 00 
  4afa98:	83 7d f8 00          	cmp    DWORD PTR [ebp-0x8],0x0
  4afa9c:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  4afa9f:	8b 02                	mov    eax,DWORD PTR [edx]
  4afaa1:	89 87 9c 00 00 00    	mov    DWORD PTR [edi+0x9c],eax
  4afaa7:	74 0e                	je     0x4afab7
  4afaa9:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4afaaf:	8b 11                	mov    edx,DWORD PTR [ecx]
  4afab1:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  4afab4:	57                   	push   edi
  4afab5:	ff d0                	call   eax
  4afab7:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4afaba:	0f be 51 06          	movsx  edx,BYTE PTR [ecx+0x6]
  4afabe:	43                   	inc    ebx
  4afabf:	3b da                	cmp    ebx,edx
  4afac1:	0f 8c f9 fe ff ff    	jl     0x4af9c0
  4afac7:	83 7d f8 00          	cmp    DWORD PTR [ebp-0x8],0x0
  4afacb:	74 0d                	je     0x4afada
  4afacd:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4afad3:	8b 01                	mov    eax,DWORD PTR [ecx]
  4afad5:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  4afad8:	ff d2                	call   edx
  4afada:	5f                   	pop    edi
  4afadb:	5e                   	pop    esi
  4afadc:	b8 00 01 00 00       	mov    eax,0x100
  4afae1:	5b                   	pop    ebx
  4afae2:	8b e5                	mov    esp,ebp
  4afae4:	5d                   	pop    ebp
  4afae5:	c2 0c 00             	ret    0xc
  4afae8:	cc                   	int3
  4afae9:	cc                   	int3
  4afaea:	cc                   	int3
  4afaeb:	cc                   	int3
  4afaec:	cc                   	int3
  4afaed:	cc                   	int3
  4afaee:	cc                   	int3
  4afaef:	cc                   	int3
```

### 0x00544C40 至 0x00544E40（stop排他）

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00544c40 <.text+0x143c40>:
  544c40:	55                   	push   ebp
  544c41:	8b ec                	mov    ebp,esp
  544c43:	6a ff                	push   0xffffffff
  544c45:	68 55 f0 92 00       	push   0x92f055
  544c4a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  544c50:	50                   	push   eax
  544c51:	83 ec 10             	sub    esp,0x10
  544c54:	53                   	push   ebx
  544c55:	56                   	push   esi
  544c56:	57                   	push   edi
  544c57:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  544c5c:	33 c5                	xor    eax,ebp
  544c5e:	50                   	push   eax
  544c5f:	8d 45 f4             	lea    eax,[ebp-0xc]
  544c62:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  544c68:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  544c6b:	c7 07 44 f9 c0 00    	mov    DWORD PTR [edi],0xc0f944
  544c71:	33 db                	xor    ebx,ebx
  544c73:	89 5f 04             	mov    DWORD PTR [edi+0x4],ebx
  544c76:	89 5f 0c             	mov    DWORD PTR [edi+0xc],ebx
  544c79:	89 5f 10             	mov    DWORD PTR [edi+0x10],ebx
  544c7c:	c6 47 14 01          	mov    BYTE PTR [edi+0x14],0x1
  544c80:	89 5f 18             	mov    DWORD PTR [edi+0x18],ebx
  544c83:	89 5f 1c             	mov    DWORD PTR [edi+0x1c],ebx
  544c86:	c6 47 20 01          	mov    BYTE PTR [edi+0x20],0x1
  544c8a:	89 5f 24             	mov    DWORD PTR [edi+0x24],ebx
  544c8d:	89 5f 28             	mov    DWORD PTR [edi+0x28],ebx
  544c90:	c6 47 2c 01          	mov    BYTE PTR [edi+0x2c],0x1
  544c94:	89 5f 30             	mov    DWORD PTR [edi+0x30],ebx
  544c97:	89 5f 34             	mov    DWORD PTR [edi+0x34],ebx
  544c9a:	89 5f 38             	mov    DWORD PTR [edi+0x38],ebx
  544c9d:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  544ca0:	89 5f 40             	mov    DWORD PTR [edi+0x40],ebx
  544ca3:	89 5f 44             	mov    DWORD PTR [edi+0x44],ebx
  544ca6:	6a 18                	push   0x18
  544ca8:	89 5f 50             	mov    DWORD PTR [edi+0x50],ebx
  544cab:	e8 b8 c5 34 00       	call   0x891268
  544cb0:	83 c4 04             	add    esp,0x4
  544cb3:	3b c3                	cmp    eax,ebx
  544cb5:	0f 84 61 01 00 00    	je     0x544e1c
  544cbb:	89 47 4c             	mov    DWORD PTR [edi+0x4c],eax
  544cbe:	89 00                	mov    DWORD PTR [eax],eax
  544cc0:	8b 47 4c             	mov    eax,DWORD PTR [edi+0x4c]
  544cc3:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  544cc6:	8b 47 4c             	mov    eax,DWORD PTR [edi+0x4c]
  544cc9:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  544ccc:	8b 47 4c             	mov    eax,DWORD PTR [edi+0x4c]
  544ccf:	c6 40 14 01          	mov    BYTE PTR [eax+0x14],0x1
  544cd3:	8b 4f 4c             	mov    ecx,DWORD PTR [edi+0x4c]
  544cd6:	c6 41 15 01          	mov    BYTE PTR [ecx+0x15],0x1
  544cda:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  544cde:	33 d2                	xor    edx,edx
  544ce0:	89 5f 58             	mov    DWORD PTR [edi+0x58],ebx
  544ce3:	89 57 5c             	mov    DWORD PTR [edi+0x5c],edx
  544ce6:	89 5f 60             	mov    DWORD PTR [edi+0x60],ebx
  544ce9:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  544cef:	f3 0f 10 05 68 56 c5 	movss  xmm0,DWORD PTR ds:0xc55668
  544cf6:	00 
  544cf7:	33 c9                	xor    ecx,ecx
  544cf9:	89 47 64             	mov    DWORD PTR [edi+0x64],eax
  544cfc:	66 89 4f 68          	mov    WORD PTR [edi+0x68],cx
  544d00:	8d b7 88 00 00 00    	lea    esi,[edi+0x88]
  544d06:	89 5f 70             	mov    DWORD PTR [edi+0x70],ebx
  544d09:	89 5f 74             	mov    DWORD PTR [edi+0x74],ebx
  544d0c:	89 5f 78             	mov    DWORD PTR [edi+0x78],ebx
  544d0f:	89 5f 7c             	mov    DWORD PTR [edi+0x7c],ebx
  544d12:	89 9f 80 00 00 00    	mov    DWORD PTR [edi+0x80],ebx
  544d18:	f3 0f 11 87 84 00 00 	movss  DWORD PTR [edi+0x84],xmm0
  544d1f:	00 
  544d20:	e8 5b 77 f5 ff       	call   0x49c480
  544d25:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  544d29:	f6 05 e8 79 fb 00 01 	test   BYTE PTR ds:0xfb79e8,0x1
  544d30:	89 5f 0c             	mov    DWORD PTR [edi+0xc],ebx
  544d33:	89 5f 10             	mov    DWORD PTR [edi+0x10],ebx
  544d36:	c6 47 14 01          	mov    BYTE PTR [edi+0x14],0x1
  544d3a:	89 5f 18             	mov    DWORD PTR [edi+0x18],ebx
  544d3d:	89 5f 1c             	mov    DWORD PTR [edi+0x1c],ebx
  544d40:	c6 47 20 01          	mov    BYTE PTR [edi+0x20],0x1
  544d44:	89 5f 24             	mov    DWORD PTR [edi+0x24],ebx
  544d47:	89 5f 28             	mov    DWORD PTR [edi+0x28],ebx
  544d4a:	c6 47 2c 01          	mov    BYTE PTR [edi+0x2c],0x1
  544d4e:	89 1d 34 ab fb 00    	mov    DWORD PTR ds:0xfbab34,ebx
  544d54:	89 1d 38 ab fb 00    	mov    DWORD PTR ds:0xfbab38,ebx
  544d5a:	75 1d                	jne    0x544d79
  544d5c:	83 0d e8 79 fb 00 01 	or     DWORD PTR ds:0xfb79e8,0x1
  544d63:	c6 45 fc 07          	mov    BYTE PTR [ebp-0x4],0x7
  544d67:	e8 74 40 25 00       	call   0x798de0
  544d6c:	68 e0 d2 bc 00       	push   0xbcd2e0
  544d71:	e8 a4 d5 34 00       	call   0x89231a
  544d76:	83 c4 04             	add    esp,0x4
  544d79:	a1 e8 76 fb 00       	mov    eax,ds:0xfb76e8
  544d7e:	d9 80 d4 00 00 00    	fld    DWORD PTR [eax+0xd4]
  544d84:	8b 35 24 22 bd 00    	mov    esi,DWORD PTR ds:0xbd2224
  544d8a:	68 84 f8 c0 00       	push   0xc0f884
  544d8f:	d9 98 d8 00 00 00    	fstp   DWORD PTR [eax+0xd8]
  544d95:	6a 64                	push   0x64
  544d97:	c7 80 b0 00 00 00 01 	mov    DWORD PTR [eax+0xb0],0x1
  544d9e:	00 00 00 
  544da1:	68 a0 f8 c0 00       	push   0xc0f8a0
  544da6:	89 5f 68             	mov    DWORD PTR [edi+0x68],ebx
  544da9:	68 b8 f8 c0 00       	push   0xc0f8b8
  544dae:	88 5f 6c             	mov    BYTE PTR [edi+0x6c],bl
  544db1:	ff d6                	call   esi
  544db3:	68 84 f8 c0 00       	push   0xc0f884
  544db8:	6a 78                	push   0x78
  544dba:	68 c8 f8 c0 00       	push   0xc0f8c8
  544dbf:	68 b8 f8 c0 00       	push   0xc0f8b8
  544dc4:	a3 2c a6 d6 00       	mov    ds:0xd6a62c,eax
  544dc9:	ff d6                	call   esi
  544dcb:	68 84 f8 c0 00       	push   0xc0f884
  544dd0:	68 b4 00 00 00       	push   0xb4
  544dd5:	68 e0 f8 c0 00       	push   0xc0f8e0
  544dda:	68 b8 f8 c0 00       	push   0xc0f8b8
  544ddf:	a3 30 a6 d6 00       	mov    ds:0xd6a630,eax
  544de4:	ff d6                	call   esi
  544de6:	68 84 f8 c0 00       	push   0xc0f884
  544deb:	68 2c 01 00 00       	push   0x12c
  544df0:	68 fc f8 c0 00       	push   0xc0f8fc
  544df5:	68 b8 f8 c0 00       	push   0xc0f8b8
  544dfa:	a3 34 a6 d6 00       	mov    ds:0xd6a634,eax
  544dff:	ff d6                	call   esi
  544e01:	a3 38 a6 d6 00       	mov    ds:0xd6a638,eax
  544e06:	8b c7                	mov    eax,edi
  544e08:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  544e0b:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  544e12:	59                   	pop    ecx
  544e13:	5f                   	pop    edi
  544e14:	5e                   	pop    esi
  544e15:	5b                   	pop    ebx
  544e16:	8b e5                	mov    esp,ebp
  544e18:	5d                   	pop    ebp
  544e19:	c2 04 00             	ret    0x4
  544e1c:	8d 55 f0             	lea    edx,[ebp-0x10]
  544e1f:	52                   	push   edx
  544e20:	8d 4d e4             	lea    ecx,[ebp-0x1c]
  544e23:	89 5d f0             	mov    DWORD PTR [ebp-0x10],ebx
  544e26:	e8 7e c2 34 00       	call   0x8910a9
  544e2b:	68 a8 57 c8 00       	push   0xc857a8
  544e30:	8d 45 e4             	lea    eax,[ebp-0x1c]
  544e33:	50                   	push   eax
  544e34:	c7 45 e4 a4 2c bd 00 	mov    DWORD PTR [ebp-0x1c],0xbd2ca4
  544e3b:	e8 b0 7b 35 00       	call   0x89c9f0
```

### 0x00545040 至 0x005452C0（stop排他）

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00545040 <.text+0x144040>:
  545040:	55                   	push   ebp
  545041:	8b ec                	mov    ebp,esp
  545043:	6a ff                	push   0xffffffff
  545045:	68 ab 83 90 00       	push   0x9083ab
  54504a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  545050:	50                   	push   eax
  545051:	83 ec 1c             	sub    esp,0x1c
  545054:	53                   	push   ebx
  545055:	56                   	push   esi
  545056:	57                   	push   edi
  545057:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  54505c:	33 c5                	xor    eax,ebp
  54505e:	50                   	push   eax
  54505f:	8d 45 f4             	lea    eax,[ebp-0xc]
  545062:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  545068:	33 c0                	xor    eax,eax
  54506a:	8d 51 0c             	lea    edx,[ecx+0xc]
  54506d:	8d 49 00             	lea    ecx,[ecx+0x0]
  545070:	83 3a 00             	cmp    DWORD PTR [edx],0x0
  545073:	74 1d                	je     0x545092
  545075:	40                   	inc    eax
  545076:	83 c2 0c             	add    edx,0xc
  545079:	83 f8 03             	cmp    eax,0x3
  54507c:	7c f2                	jl     0x545070
  54507e:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  545081:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  545088:	59                   	pop    ecx
  545089:	5f                   	pop    edi
  54508a:	5e                   	pop    esi
  54508b:	5b                   	pop    ebx
  54508c:	8b e5                	mov    esp,ebp
  54508e:	5d                   	pop    ebp
  54508f:	c2 04 00             	ret    0x4
  545092:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  545095:	8d 04 40             	lea    eax,[eax+eax*2]
  545098:	8d 04 81             	lea    eax,[ecx+eax*4]
  54509b:	c7 41 04 01 00 00 00 	mov    DWORD PTR [ecx+0x4],0x1
  5450a2:	89 78 0c             	mov    DWORD PTR [eax+0xc],edi
  5450a5:	0f b7 5f 04          	movzx  ebx,WORD PTR [edi+0x4]
  5450a9:	8d 71 48             	lea    esi,[ecx+0x48]
  5450ac:	8b cb                	mov    ecx,ebx
  5450ae:	8d 55 f0             	lea    edx,[ebp-0x10]
  5450b1:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  5450b4:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  5450b7:	52                   	push   edx
  5450b8:	8d 45 e8             	lea    eax,[ebp-0x18]
  5450bb:	8b ce                	mov    ecx,esi
  5450bd:	e8 3e 9e 2e 00       	call   0x82ef00
  5450c2:	8b 4d e8             	mov    ecx,DWORD PTR [ebp-0x18]
  5450c5:	3b 4e 04             	cmp    ecx,DWORD PTR [esi+0x4]
  5450c8:	0f 85 c4 00 00 00    	jne    0x545192
  5450ce:	6a 14                	push   0x14
  5450d0:	e8 93 c1 34 00       	call   0x891268
  5450d5:	8b f8                	mov    edi,eax
  5450d7:	83 c4 04             	add    esp,0x4
  5450da:	89 7d f0             	mov    DWORD PTR [ebp-0x10],edi
  5450dd:	33 db                	xor    ebx,ebx
  5450df:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  5450e2:	3b fb                	cmp    edi,ebx
  5450e4:	74 36                	je     0x54511c
  5450e6:	33 c0                	xor    eax,eax
  5450e8:	89 07                	mov    DWORD PTR [edi],eax
  5450ea:	6a 24                	push   0x24
  5450ec:	89 5f 0c             	mov    DWORD PTR [edi+0xc],ebx
  5450ef:	e8 74 c1 34 00       	call   0x891268
  5450f4:	83 c4 04             	add    esp,0x4
  5450f7:	3b c3                	cmp    eax,ebx
  5450f9:	74 73                	je     0x54516e
  5450fb:	89 47 08             	mov    DWORD PTR [edi+0x8],eax
  5450fe:	89 00                	mov    DWORD PTR [eax],eax
  545100:	8b 47 08             	mov    eax,DWORD PTR [edi+0x8]
  545103:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  545106:	8b 47 08             	mov    eax,DWORD PTR [edi+0x8]
  545109:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  54510c:	8b 57 08             	mov    edx,DWORD PTR [edi+0x8]
  54510f:	c6 42 20 01          	mov    BYTE PTR [edx+0x20],0x1
  545113:	8b 47 08             	mov    eax,DWORD PTR [edi+0x8]
  545116:	c6 40 21 01          	mov    BYTE PTR [eax+0x21],0x1
  54511a:	8b df                	mov    ebx,edi
  54511c:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  54511f:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  545126:	66 8b 48 04          	mov    cx,WORD PTR [eax+0x4]
  54512a:	66 89 0b             	mov    WORD PTR [ebx],cx
  54512d:	0f b7 88 88 00 00 00 	movzx  ecx,WORD PTR [eax+0x88]
  545134:	89 4d f0             	mov    DWORD PTR [ebp-0x10],ecx
  545137:	66 39 4b 02          	cmp    WORD PTR [ebx+0x2],cx
  54513b:	74 13                	je     0x545150
  54513d:	8d 7b 04             	lea    edi,[ebx+0x4]
  545140:	e8 2b 2a 05 00       	call   0x597b70
  545145:	66 8b 55 f0          	mov    dx,WORD PTR [ebp-0x10]
  545149:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  54514c:	66 89 53 02          	mov    WORD PTR [ebx+0x2],dx
  545150:	0f b7 40 04          	movzx  eax,WORD PTR [eax+0x4]
  545154:	8d 7d ec             	lea    edi,[ebp-0x14]
  545157:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  54515a:	89 5d f0             	mov    DWORD PTR [ebp-0x10],ebx
  54515d:	e8 be 9d 03 00       	call   0x57ef20
  545162:	50                   	push   eax
  545163:	56                   	push   esi
  545164:	8d 75 ec             	lea    esi,[ebp-0x14]
  545167:	e8 94 a0 2e 00       	call   0x82f200
  54516c:	eb 45                	jmp    0x5451b3
  54516e:	8d 4d e8             	lea    ecx,[ebp-0x18]
  545171:	51                   	push   ecx
  545172:	8d 4d d8             	lea    ecx,[ebp-0x28]
  545175:	89 5d e8             	mov    DWORD PTR [ebp-0x18],ebx
  545178:	e8 2c bf 34 00       	call   0x8910a9
  54517d:	68 a8 57 c8 00       	push   0xc857a8
  545182:	8d 55 d8             	lea    edx,[ebp-0x28]
  545185:	52                   	push   edx
  545186:	c7 45 d8 a4 2c bd 00 	mov    DWORD PTR [ebp-0x28],0xbd2ca4
  54518d:	e8 5e 78 35 00       	call   0x89c9f0
  545192:	8b 71 10             	mov    esi,DWORD PTR [ecx+0x10]
  545195:	66 89 1e             	mov    WORD PTR [esi],bx
  545198:	0f b7 9f 88 00 00 00 	movzx  ebx,WORD PTR [edi+0x88]
  54519f:	66 39 5e 02          	cmp    WORD PTR [esi+0x2],bx
  5451a3:	74 0c                	je     0x5451b1
  5451a5:	8d 7e 04             	lea    edi,[esi+0x4]
  5451a8:	e8 c3 29 05 00       	call   0x597b70
  5451ad:	66 89 5e 02          	mov    WORD PTR [esi+0x2],bx
  5451b1:	8b de                	mov    ebx,esi
  5451b3:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  5451b6:	89 59 10             	mov    DWORD PTR [ecx+0x10],ebx
  5451b9:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5451bc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5451c3:	59                   	pop    ecx
  5451c4:	5f                   	pop    edi
  5451c5:	5e                   	pop    esi
  5451c6:	5b                   	pop    ebx
  5451c7:	8b e5                	mov    esp,ebp
  5451c9:	5d                   	pop    ebp
  5451ca:	c2 04 00             	ret    0x4
  5451cd:	cc                   	int3
  5451ce:	cc                   	int3
  5451cf:	cc                   	int3
  5451d0:	55                   	push   ebp
  5451d1:	8b ec                	mov    ebp,esp
  5451d3:	83 ec 08             	sub    esp,0x8
  5451d6:	66 8b 45 08          	mov    ax,WORD PTR [ebp+0x8]
  5451da:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  5451dd:	66 89 45 fa          	mov    WORD PTR [ebp-0x6],ax
  5451e1:	0f b7 42 04          	movzx  eax,WORD PTR [edx+0x4]
  5451e5:	57                   	push   edi
  5451e6:	66 89 45 f8          	mov    WORD PTR [ebp-0x8],ax
  5451ea:	8d 79 30             	lea    edi,[ecx+0x30]
  5451ed:	8d 45 f8             	lea    eax,[ebp-0x8]
  5451f0:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  5451f7:	e8 24 74 fb ff       	call   0x4fc620
  5451fc:	5f                   	pop    edi
  5451fd:	8b e5                	mov    esp,ebp
  5451ff:	5d                   	pop    ebp
  545200:	c2 08 00             	ret    0x8
  545203:	cc                   	int3
  545204:	cc                   	int3
  545205:	cc                   	int3
  545206:	cc                   	int3
  545207:	cc                   	int3
  545208:	cc                   	int3
  545209:	cc                   	int3
  54520a:	cc                   	int3
  54520b:	cc                   	int3
  54520c:	cc                   	int3
  54520d:	cc                   	int3
  54520e:	cc                   	int3
  54520f:	cc                   	int3
  545210:	33 c0                	xor    eax,eax
  545212:	89 41 0c             	mov    DWORD PTR [ecx+0xc],eax
  545215:	89 41 18             	mov    DWORD PTR [ecx+0x18],eax
  545218:	89 41 10             	mov    DWORD PTR [ecx+0x10],eax
  54521b:	b2 01                	mov    dl,0x1
  54521d:	88 51 14             	mov    BYTE PTR [ecx+0x14],dl
  545220:	89 41 1c             	mov    DWORD PTR [ecx+0x1c],eax
  545223:	88 51 20             	mov    BYTE PTR [ecx+0x20],dl
  545226:	89 41 24             	mov    DWORD PTR [ecx+0x24],eax
  545229:	89 41 28             	mov    DWORD PTR [ecx+0x28],eax
  54522c:	88 51 2c             	mov    BYTE PTR [ecx+0x2c],dl
  54522f:	8b 51 30             	mov    edx,DWORD PTR [ecx+0x30]
  545232:	56                   	push   esi
  545233:	8b 71 34             	mov    esi,DWORD PTR [ecx+0x34]
  545236:	3b d6                	cmp    edx,esi
  545238:	74 1f                	je     0x545259
  54523a:	8b c6                	mov    eax,esi
  54523c:	3b f6                	cmp    esi,esi
  54523e:	74 16                	je     0x545256
  545240:	57                   	push   edi
  545241:	8b 38                	mov    edi,DWORD PTR [eax]
  545243:	89 3a                	mov    DWORD PTR [edx],edi
  545245:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  545248:	89 7a 04             	mov    DWORD PTR [edx+0x4],edi
  54524b:	83 c0 08             	add    eax,0x8
  54524e:	83 c2 08             	add    edx,0x8
  545251:	3b c6                	cmp    eax,esi
  545253:	75 ec                	jne    0x545241
  545255:	5f                   	pop    edi
  545256:	89 51 34             	mov    DWORD PTR [ecx+0x34],edx
  545259:	5e                   	pop    esi
  54525a:	c3                   	ret
  54525b:	cc                   	int3
  54525c:	cc                   	int3
  54525d:	cc                   	int3
  54525e:	cc                   	int3
  54525f:	cc                   	int3
  545260:	55                   	push   ebp
  545261:	8b ec                	mov    ebp,esp
  545263:	56                   	push   esi
  545264:	66 8b 75 08          	mov    si,WORD PTR [ebp+0x8]
  545268:	33 c0                	xor    eax,eax
  54526a:	83 c2 0c             	add    edx,0xc
  54526d:	8d 49 00             	lea    ecx,[ecx+0x0]
  545270:	8b 0a                	mov    ecx,DWORD PTR [edx]
  545272:	85 c9                	test   ecx,ecx
  545274:	74 06                	je     0x54527c
  545276:	66 39 71 04          	cmp    WORD PTR [ecx+0x4],si
  54527a:	74 0c                	je     0x545288
  54527c:	40                   	inc    eax
  54527d:	83 c2 0c             	add    edx,0xc
  545280:	83 f8 03             	cmp    eax,0x3
  545283:	7c eb                	jl     0x545270
  545285:	83 c8 ff             	or     eax,0xffffffff
  545288:	5e                   	pop    esi
  545289:	5d                   	pop    ebp
  54528a:	c2 04 00             	ret    0x4
  54528d:	cc                   	int3
  54528e:	cc                   	int3
  54528f:	cc                   	int3
  545290:	55                   	push   ebp
  545291:	8b ec                	mov    ebp,esp
  545293:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  545296:	83 f8 02             	cmp    eax,0x2
  545299:	77 0b                	ja     0x5452a6
  54529b:	8d 44 40 03          	lea    eax,[eax+eax*2+0x3]
  54529f:	8b 04 81             	mov    eax,DWORD PTR [ecx+eax*4]
  5452a2:	5d                   	pop    ebp
  5452a3:	c2 04 00             	ret    0x4
  5452a6:	33 c0                	xor    eax,eax
  5452a8:	5d                   	pop    ebp
  5452a9:	c2 04 00             	ret    0x4
  5452ac:	cc                   	int3
  5452ad:	cc                   	int3
  5452ae:	cc                   	int3
  5452af:	cc                   	int3
  5452b0:	8b 01                	mov    eax,DWORD PTR [ecx]
  5452b2:	8b 50 1c             	mov    edx,DWORD PTR [eax+0x1c]
  5452b5:	6a 00                	push   0x0
  5452b7:	ff d2                	call   edx
  5452b9:	c3                   	ret
  5452ba:	cc                   	int3
  5452bb:	cc                   	int3
  5452bc:	cc                   	int3
  5452bd:	cc                   	int3
  5452be:	cc                   	int3
  5452bf:	cc                   	int3
```

### 0x00444910 至 0x00444960（stop排他）

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

00444910 <.text+0x43910>:
  444910:	33 c0                	xor    eax,eax
  444912:	89 41 0c             	mov    DWORD PTR [ecx+0xc],eax
  444915:	89 41 18             	mov    DWORD PTR [ecx+0x18],eax
  444918:	89 41 10             	mov    DWORD PTR [ecx+0x10],eax
  44491b:	b2 01                	mov    dl,0x1
  44491d:	88 51 14             	mov    BYTE PTR [ecx+0x14],dl
  444920:	89 41 1c             	mov    DWORD PTR [ecx+0x1c],eax
  444923:	89 41 24             	mov    DWORD PTR [ecx+0x24],eax
  444926:	89 41 28             	mov    DWORD PTR [ecx+0x28],eax
  444929:	88 41 20             	mov    BYTE PTR [ecx+0x20],al
  44492c:	88 41 2c             	mov    BYTE PTR [ecx+0x2c],al
  44492f:	8b 51 30             	mov    edx,DWORD PTR [ecx+0x30]
  444932:	56                   	push   esi
  444933:	8b 71 34             	mov    esi,DWORD PTR [ecx+0x34]
  444936:	3b d6                	cmp    edx,esi
  444938:	74 1f                	je     0x444959
  44493a:	8b c6                	mov    eax,esi
  44493c:	3b f6                	cmp    esi,esi
  44493e:	74 16                	je     0x444956
  444940:	57                   	push   edi
  444941:	8b 38                	mov    edi,DWORD PTR [eax]
  444943:	89 3a                	mov    DWORD PTR [edx],edi
  444945:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  444948:	89 7a 04             	mov    DWORD PTR [edx+0x4],edi
  44494b:	83 c0 08             	add    eax,0x8
  44494e:	83 c2 08             	add    edx,0x8
  444951:	3b c6                	cmp    eax,esi
  444953:	75 ec                	jne    0x444941
  444955:	5f                   	pop    edi
  444956:	89 51 34             	mov    DWORD PTR [ecx+0x34],edx
  444959:	5e                   	pop    esi
  44495a:	c3                   	ret
  44495b:	cc                   	int3
  44495c:	cc                   	int3
  44495d:	cc                   	int3
  44495e:	cc                   	int3
  44495f:	cc                   	int3
```

### 0x004FC620 至 0x004FC680（stop排他）

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004fc620 <.text+0xfb620>:
  4fc620:	56                   	push   esi
  4fc621:	8b f0                	mov    esi,eax
  4fc623:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4fc626:	3b f0                	cmp    esi,eax
  4fc628:	73 32                	jae    0x4fc65c
  4fc62a:	8b 0f                	mov    ecx,DWORD PTR [edi]
  4fc62c:	3b ce                	cmp    ecx,esi
  4fc62e:	77 2c                	ja     0x4fc65c
  4fc630:	2b f1                	sub    esi,ecx
  4fc632:	c1 fe 03             	sar    esi,0x3
  4fc635:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  4fc638:	75 07                	jne    0x4fc641
  4fc63a:	8b cf                	mov    ecx,edi
  4fc63c:	e8 3f cb 03 00       	call   0x539180
  4fc641:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  4fc644:	85 c9                	test   ecx,ecx
  4fc646:	74 31                	je     0x4fc679
  4fc648:	8b 07                	mov    eax,DWORD PTR [edi]
  4fc64a:	8b 14 f0             	mov    edx,DWORD PTR [eax+esi*8]
  4fc64d:	89 11                	mov    DWORD PTR [ecx],edx
  4fc64f:	8b 44 f0 04          	mov    eax,DWORD PTR [eax+esi*8+0x4]
  4fc653:	89 41 04             	mov    DWORD PTR [ecx+0x4],eax
  4fc656:	83 47 04 08          	add    DWORD PTR [edi+0x4],0x8
  4fc65a:	5e                   	pop    esi
  4fc65b:	c3                   	ret
  4fc65c:	3b 47 08             	cmp    eax,DWORD PTR [edi+0x8]
  4fc65f:	75 07                	jne    0x4fc668
  4fc661:	8b cf                	mov    ecx,edi
  4fc663:	e8 18 cb 03 00       	call   0x539180
  4fc668:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4fc66b:	85 c0                	test   eax,eax
  4fc66d:	74 0a                	je     0x4fc679
  4fc66f:	8b 0e                	mov    ecx,DWORD PTR [esi]
  4fc671:	89 08                	mov    DWORD PTR [eax],ecx
  4fc673:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  4fc676:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  4fc679:	83 47 04 08          	add    DWORD PTR [edi+0x4],0x8
  4fc67d:	5e                   	pop    esi
  4fc67e:	c3                   	ret
  4fc67f:	cc                   	int3
```

### 0x004B2A56 至 0x004B2AF0（stop排他）

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004b2a56 <.text+0xb1a56>:
  4b2a56:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4b2a5c:	66 8b 76 04          	mov    si,WORD PTR [esi+0x4]
  4b2a60:	33 c0                	xor    eax,eax
  4b2a62:	8d 51 0c             	lea    edx,[ecx+0xc]
  4b2a65:	8b 3a                	mov    edi,DWORD PTR [edx]
  4b2a67:	85 ff                	test   edi,edi
  4b2a69:	74 06                	je     0x4b2a71
  4b2a6b:	66 39 77 04          	cmp    WORD PTR [edi+0x4],si
  4b2a6f:	74 0c                	je     0x4b2a7d
  4b2a71:	03 c3                	add    eax,ebx
  4b2a73:	83 c2 0c             	add    edx,0xc
  4b2a76:	83 f8 03             	cmp    eax,0x3
  4b2a79:	7c ea                	jl     0x4b2a65
  4b2a7b:	eb 0c                	jmp    0x4b2a89
  4b2a7d:	83 f8 ff             	cmp    eax,0xffffffff
  4b2a80:	74 07                	je     0x4b2a89
  4b2a82:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b2a84:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4b2a87:	ff d2                	call   edx
  4b2a89:	84 1d 2c b2 fa 00    	test   BYTE PTR ds:0xfab22c,bl
  4b2a8f:	75 24                	jne    0x4b2ab5
  4b2a91:	09 1d 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,ebx
  4b2a97:	89 5c 24 40          	mov    DWORD PTR [esp+0x40],ebx
  4b2a9b:	e8 f0 c1 02 00       	call   0x4dec90
  4b2aa0:	68 30 ce bc 00       	push   0xbcce30
  4b2aa5:	e8 70 f8 3d 00       	call   0x89231a
  4b2aaa:	83 c4 04             	add    esp,0x4
  4b2aad:	c7 44 24 40 ff ff ff 	mov    DWORD PTR [esp+0x40],0xffffffff
  4b2ab4:	ff 
  4b2ab5:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  4b2ab9:	0f b7 08             	movzx  ecx,WORD PTR [eax]
  4b2abc:	51                   	push   ecx
  4b2abd:	b8 30 b1 fa 00       	mov    eax,0xfab130
  4b2ac2:	e8 f9 d0 02 00       	call   0x4dfbc0
  4b2ac7:	83 44 24 14 02       	add    DWORD PTR [esp+0x14],0x2
  4b2acc:	29 5c 24 18          	sub    DWORD PTR [esp+0x18],ebx
  4b2ad0:	0f 85 52 fe ff ff    	jne    0x4b2928
  4b2ad6:	33 c0                	xor    eax,eax
  4b2ad8:	8b 4c 24 38          	mov    ecx,DWORD PTR [esp+0x38]
  4b2adc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b2ae3:	59                   	pop    ecx
  4b2ae4:	5f                   	pop    edi
  4b2ae5:	5e                   	pop    esi
  4b2ae6:	5b                   	pop    ebx
  4b2ae7:	8b e5                	mov    esp,ebp
  4b2ae9:	5d                   	pop    ebp
  4b2aea:	c2 0c 00             	ret    0xc
  4b2aed:	cc                   	int3
  4b2aee:	cc                   	int3
  4b2aef:	cc                   	int3
```

### 0x004DFBC0 至 0x004DFD40（stop排他）

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004dfbc0 <.text+0xdebc0>:
  4dfbc0:	55                   	push   ebp
  4dfbc1:	8b ec                	mov    ebp,esp
  4dfbc3:	51                   	push   ecx
  4dfbc4:	53                   	push   ebx
  4dfbc5:	56                   	push   esi
  4dfbc6:	8b f0                	mov    esi,eax
  4dfbc8:	57                   	push   edi
  4dfbc9:	8d 45 08             	lea    eax,[ebp+0x8]
  4dfbcc:	8d 5e 08             	lea    ebx,[esi+0x8]
  4dfbcf:	50                   	push   eax
  4dfbd0:	8d 45 fc             	lea    eax,[ebp-0x4]
  4dfbd3:	8b cb                	mov    ecx,ebx
  4dfbd5:	e8 26 f3 34 00       	call   0x82ef00
  4dfbda:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  4dfbdd:	3b 7e 0c             	cmp    edi,DWORD PTR [esi+0xc]
  4dfbe0:	74 41                	je     0x4dfc23
  4dfbe2:	33 f6                	xor    esi,esi
  4dfbe4:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4dfbea:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbec:	8b 42 1c             	mov    eax,DWORD PTR [edx+0x1c]
  4dfbef:	56                   	push   esi
  4dfbf0:	ff d0                	call   eax
  4dfbf2:	46                   	inc    esi
  4dfbf3:	83 fe 03             	cmp    esi,0x3
  4dfbf6:	7c ec                	jl     0x4dfbe4
  4dfbf8:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfbfb:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbfd:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4dfc00:	ff d0                	call   eax
  4dfc02:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfc05:	85 c9                	test   ecx,ecx
  4dfc07:	74 0f                	je     0x4dfc18
  4dfc09:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfc0b:	8b 02                	mov    eax,DWORD PTR [edx]
  4dfc0d:	6a 01                	push   0x1
  4dfc0f:	ff d0                	call   eax
  4dfc11:	c7 47 10 00 00 00 00 	mov    DWORD PTR [edi+0x10],0x0
  4dfc18:	57                   	push   edi
  4dfc19:	8d 4d 08             	lea    ecx,[ebp+0x8]
  4dfc1c:	51                   	push   ecx
  4dfc1d:	53                   	push   ebx
  4dfc1e:	e8 6d 6c 2d 00       	call   0x7b6890
  4dfc23:	5f                   	pop    edi
  4dfc24:	5e                   	pop    esi
  4dfc25:	5b                   	pop    ebx
  4dfc26:	8b e5                	mov    esp,ebp
  4dfc28:	5d                   	pop    ebp
  4dfc29:	c2 04 00             	ret    0x4
  4dfc2c:	cc                   	int3
  4dfc2d:	cc                   	int3
  4dfc2e:	cc                   	int3
  4dfc2f:	cc                   	int3
  4dfc30:	55                   	push   ebp
  4dfc31:	8b ec                	mov    ebp,esp
  4dfc33:	51                   	push   ecx
  4dfc34:	53                   	push   ebx
  4dfc35:	57                   	push   edi
  4dfc36:	8d 45 08             	lea    eax,[ebp+0x8]
  4dfc39:	8d 5e 18             	lea    ebx,[esi+0x18]
  4dfc3c:	50                   	push   eax
  4dfc3d:	8d 45 fc             	lea    eax,[ebp-0x4]
  4dfc40:	8b cb                	mov    ecx,ebx
  4dfc42:	e8 79 3c 36 00       	call   0x8438c0
  4dfc47:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  4dfc4a:	3b 7e 1c             	cmp    edi,DWORD PTR [esi+0x1c]
  4dfc4d:	74 36                	je     0x4dfc85
  4dfc4f:	8b 86 f8 00 00 00    	mov    eax,DWORD PTR [esi+0xf8]
  4dfc55:	85 c0                	test   eax,eax
  4dfc57:	74 11                	je     0x4dfc6a
  4dfc59:	8b 08                	mov    ecx,DWORD PTR [eax]
  4dfc5b:	3b 4d 08             	cmp    ecx,DWORD PTR [ebp+0x8]
  4dfc5e:	75 0a                	jne    0x4dfc6a
  4dfc60:	c7 86 f8 00 00 00 00 	mov    DWORD PTR [esi+0xf8],0x0
  4dfc67:	00 00 00 
  4dfc6a:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  4dfc6d:	85 c0                	test   eax,eax
  4dfc6f:	74 09                	je     0x4dfc7a
  4dfc71:	50                   	push   eax
  4dfc72:	e8 95 15 3b 00       	call   0x89120c
  4dfc77:	83 c4 04             	add    esp,0x4
  4dfc7a:	57                   	push   edi
  4dfc7b:	8d 55 08             	lea    edx,[ebp+0x8]
  4dfc7e:	52                   	push   edx
  4dfc7f:	53                   	push   ebx
  4dfc80:	e8 0b 6c 2d 00       	call   0x7b6890
  4dfc85:	5f                   	pop    edi
  4dfc86:	5b                   	pop    ebx
  4dfc87:	8b e5                	mov    esp,ebp
  4dfc89:	5d                   	pop    ebp
  4dfc8a:	c2 04 00             	ret    0x4
  4dfc8d:	cc                   	int3
  4dfc8e:	cc                   	int3
  4dfc8f:	cc                   	int3
  4dfc90:	55                   	push   ebp
  4dfc91:	8b ec                	mov    ebp,esp
  4dfc93:	51                   	push   ecx
  4dfc94:	56                   	push   esi
  4dfc95:	57                   	push   edi
  4dfc96:	8d 78 08             	lea    edi,[eax+0x8]
  4dfc99:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4dfc9c:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfc9e:	3b f0                	cmp    esi,eax
  4dfca0:	0f 84 89 00 00 00    	je     0x4dfd2f
  4dfca6:	eb 08                	jmp    0x4dfcb0
  4dfca8:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  4dfcaf:	90                   	nop
  4dfcb0:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfcb3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4dfcb6:	39 81 88 00 00 00    	cmp    DWORD PTR [ecx+0x88],eax
  4dfcbc:	75 2c                	jne    0x4dfcea
  4dfcbe:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfcc0:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4dfcc3:	ff d0                	call   eax
  4dfcc5:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfcc8:	85 c9                	test   ecx,ecx
  4dfcca:	74 0f                	je     0x4dfcdb
  4dfccc:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfcce:	8b 02                	mov    eax,DWORD PTR [edx]
  4dfcd0:	6a 01                	push   0x1
  4dfcd2:	ff d0                	call   eax
  4dfcd4:	c7 46 10 00 00 00 00 	mov    DWORD PTR [esi+0x10],0x0
  4dfcdb:	56                   	push   esi
  4dfcdc:	8d 4d fc             	lea    ecx,[ebp-0x4]
  4dfcdf:	51                   	push   ecx
  4dfce0:	57                   	push   edi
  4dfce1:	e8 aa 6b 2d 00       	call   0x7b6890
  4dfce6:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfce8:	eb 40                	jmp    0x4dfd2a
  4dfcea:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  4dfcee:	75 3a                	jne    0x4dfd2a
  4dfcf0:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  4dfcf3:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfcf7:	75 16                	jne    0x4dfd0f
  4dfcf9:	8b f0                	mov    esi,eax
  4dfcfb:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfcfd:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfd01:	75 27                	jne    0x4dfd2a
  4dfd03:	8b f0                	mov    esi,eax
  4dfd05:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfd07:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfd0b:	74 f6                	je     0x4dfd03
  4dfd0d:	eb 1b                	jmp    0x4dfd2a
  4dfd0f:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4dfd12:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfd16:	75 10                	jne    0x4dfd28
  4dfd18:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  4dfd1b:	75 0b                	jne    0x4dfd28
  4dfd1d:	8b f0                	mov    esi,eax
  4dfd1f:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4dfd22:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfd26:	74 f0                	je     0x4dfd18
  4dfd28:	8b f0                	mov    esi,eax
  4dfd2a:	3b 77 04             	cmp    esi,DWORD PTR [edi+0x4]
  4dfd2d:	75 81                	jne    0x4dfcb0
  4dfd2f:	5f                   	pop    edi
  4dfd30:	5e                   	pop    esi
  4dfd31:	8b e5                	mov    esp,ebp
  4dfd33:	5d                   	pop    ebp
  4dfd34:	c2 04 00             	ret    0x4
  4dfd37:	cc                   	int3
  4dfd38:	cc                   	int3
  4dfd39:	cc                   	int3
  4dfd3a:	cc                   	int3
  4dfd3b:	cc                   	int3
  4dfd3c:	cc                   	int3
  4dfd3d:	cc                   	int3
  4dfd3e:	cc                   	int3
  4dfd3f:	cc                   	int3
```

### 0x004B1A30 至 0x004B1A90（stop排他）

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004b1a30 <.text+0xb0a30>:
  4b1a30:	6a 00                	push   0x0
  4b1a32:	e8 29 d6 f5 ff       	call   0x40f060
  4b1a37:	8b c8                	mov    ecx,eax
  4b1a39:	e8 02 e3 02 00       	call   0x4dfd40
  4b1a3e:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4b1a44:	8b 01                	mov    eax,DWORD PTR [ecx]
  4b1a46:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4b1a49:	ff d2                	call   edx
  4b1a4b:	e8 10 d6 f5 ff       	call   0x40f060
  4b1a50:	c7 80 f8 00 00 00 00 	mov    DWORD PTR [eax+0xf8],0x0
  4b1a57:	00 00 00 
  4b1a5a:	83 c0 18             	add    eax,0x18
  4b1a5d:	50                   	push   eax
  4b1a5e:	e8 0d f6 02 00       	call   0x4e1070
  4b1a63:	83 c4 04             	add    esp,0x4
  4b1a66:	33 c0                	xor    eax,eax
  4b1a68:	c2 0c 00             	ret    0xc
  4b1a6b:	cc                   	int3
  4b1a6c:	cc                   	int3
  4b1a6d:	cc                   	int3
  4b1a6e:	cc                   	int3
  4b1a6f:	cc                   	int3
  4b1a70:	6a 01                	push   0x1
  4b1a72:	e8 e9 d5 f5 ff       	call   0x40f060
  4b1a77:	8b c8                	mov    ecx,eax
  4b1a79:	e8 c2 e2 02 00       	call   0x4dfd40
  4b1a7e:	33 c0                	xor    eax,eax
  4b1a80:	c2 0c 00             	ret    0xc
  4b1a83:	cc                   	int3
  4b1a84:	cc                   	int3
  4b1a85:	cc                   	int3
  4b1a86:	cc                   	int3
  4b1a87:	cc                   	int3
  4b1a88:	cc                   	int3
  4b1a89:	cc                   	int3
  4b1a8a:	cc                   	int3
  4b1a8b:	cc                   	int3
  4b1a8c:	cc                   	int3
  4b1a8d:	cc                   	int3
  4b1a8e:	cc                   	int3
  4b1a8f:	cc                   	int3
```

### 0x004BBAE0 至 0x004BBB70（stop排他）

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004bbae0 <.text+0xbaae0>:
  4bbae0:	55                   	push   ebp
  4bbae1:	8b ec                	mov    ebp,esp
  4bbae3:	83 e4 f8             	and    esp,0xfffffff8
  4bbae6:	6a ff                	push   0xffffffff
  4bbae8:	68 fe 6e 93 00       	push   0x936efe
  4bbaed:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4bbaf3:	50                   	push   eax
  4bbaf4:	83 ec 08             	sub    esp,0x8
  4bbaf7:	56                   	push   esi
  4bbaf8:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4bbafd:	33 c4                	xor    eax,esp
  4bbaff:	50                   	push   eax
  4bbb00:	8d 44 24 10          	lea    eax,[esp+0x10]
  4bbb04:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4bbb0a:	b8 01 00 00 00       	mov    eax,0x1
  4bbb0f:	84 05 2c b2 fa 00    	test   BYTE PTR ds:0xfab22c,al
  4bbb15:	75 28                	jne    0x4bbb3f
  4bbb17:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  4bbb1d:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  4bbb24:	00 
  4bbb25:	e8 66 31 02 00       	call   0x4dec90
  4bbb2a:	68 30 ce bc 00       	push   0xbcce30
  4bbb2f:	e8 e6 67 3d 00       	call   0x89231a
  4bbb34:	83 c4 04             	add    esp,0x4
  4bbb37:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  4bbb3e:	ff 
  4bbb3f:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4bbb42:	8b 48 02             	mov    ecx,DWORD PTR [eax+0x2]
  4bbb45:	51                   	push   ecx
  4bbb46:	be 30 b1 fa 00       	mov    esi,0xfab130
  4bbb4b:	e8 e0 40 02 00       	call   0x4dfc30
  4bbb50:	33 c0                	xor    eax,eax
  4bbb52:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  4bbb56:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4bbb5d:	59                   	pop    ecx
  4bbb5e:	5e                   	pop    esi
  4bbb5f:	8b e5                	mov    esp,ebp
  4bbb61:	5d                   	pop    ebp
  4bbb62:	c2 0c 00             	ret    0xc
  4bbb65:	cc                   	int3
  4bbb66:	cc                   	int3
  4bbb67:	cc                   	int3
  4bbb68:	cc                   	int3
  4bbb69:	cc                   	int3
  4bbb6a:	cc                   	int3
  4bbb6b:	cc                   	int3
  4bbb6c:	cc                   	int3
  4bbb6d:	cc                   	int3
  4bbb6e:	cc                   	int3
  4bbb6f:	cc                   	int3
```

### 0x004C6EA0 至 0x004C6F60（stop排他）

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c6ea0 <.text+0xc5ea0>:
  4c6ea0:	55                   	push   ebp
  4c6ea1:	8b ec                	mov    ebp,esp
  4c6ea3:	83 e4 f8             	and    esp,0xfffffff8
  4c6ea6:	6a ff                	push   0xffffffff
  4c6ea8:	68 fe 6e 93 00       	push   0x936efe
  4c6ead:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4c6eb3:	50                   	push   eax
  4c6eb4:	83 ec 0c             	sub    esp,0xc
  4c6eb7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4c6ebc:	33 c4                	xor    eax,esp
  4c6ebe:	50                   	push   eax
  4c6ebf:	8d 44 24 10          	lea    eax,[esp+0x10]
  4c6ec3:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4c6ec9:	b8 01 00 00 00       	mov    eax,0x1
  4c6ece:	84 05 2c b2 fa 00    	test   BYTE PTR ds:0xfab22c,al
  4c6ed4:	75 20                	jne    0x4c6ef6
  4c6ed6:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  4c6edc:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  4c6ee3:	00 
  4c6ee4:	e8 a7 7d 01 00       	call   0x4dec90
  4c6ee9:	68 30 ce bc 00       	push   0xbcce30
  4c6eee:	e8 27 b4 3c 00       	call   0x89231a
  4c6ef3:	83 c4 04             	add    esp,0x4
  4c6ef6:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4c6ef9:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  4c6efc:	8d 54 24 04          	lea    edx,[esp+0x4]
  4c6f00:	89 4c 24 04          	mov    DWORD PTR [esp+0x4],ecx
  4c6f04:	52                   	push   edx
  4c6f05:	8d 44 24 0c          	lea    eax,[esp+0xc]
  4c6f09:	b9 38 b1 fa 00       	mov    ecx,0xfab138
  4c6f0e:	e8 ed 7f 36 00       	call   0x82ef00
  4c6f13:	8b 44 24 08          	mov    eax,DWORD PTR [esp+0x8]
  4c6f17:	3b 05 3c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab13c
  4c6f1d:	74 1f                	je     0x4c6f3e
  4c6f1f:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  4c6f22:	85 c0                	test   eax,eax
  4c6f24:	74 18                	je     0x4c6f3e
  4c6f26:	8a 80 bc 00 00 00    	mov    al,BYTE PTR [eax+0xbc]
  4c6f2c:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  4c6f30:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c6f37:	59                   	pop    ecx
  4c6f38:	8b e5                	mov    esp,ebp
  4c6f3a:	5d                   	pop    ebp
  4c6f3b:	c2 04 00             	ret    0x4
  4c6f3e:	32 c0                	xor    al,al
  4c6f40:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  4c6f44:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4c6f4b:	59                   	pop    ecx
  4c6f4c:	8b e5                	mov    esp,ebp
  4c6f4e:	5d                   	pop    ebp
  4c6f4f:	c2 04 00             	ret    0x4
  4c6f52:	cc                   	int3
  4c6f53:	cc                   	int3
  4c6f54:	cc                   	int3
  4c6f55:	cc                   	int3
  4c6f56:	cc                   	int3
  4c6f57:	cc                   	int3
  4c6f58:	cc                   	int3
  4c6f59:	cc                   	int3
  4c6f5a:	cc                   	int3
  4c6f5b:	cc                   	int3
  4c6f5c:	cc                   	int3
  4c6f5d:	cc                   	int3
  4c6f5e:	cc                   	int3
  4c6f5f:	cc                   	int3
```

### 0x005471E0 至 0x00547200（stop排他）

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005471e0 <.text+0x1461e0>:
  5471e0:	51                   	push   ecx
  5471e1:	56                   	push   esi
  5471e2:	e8 59 da ff ff       	call   0x544c40
  5471e7:	c7 06 9c f9 c0 00    	mov    DWORD PTR [esi],0xc0f99c
  5471ed:	c7 05 ac a7 fb 00 00 	mov    DWORD PTR ds:0xfba7ac,0x0
  5471f4:	00 00 00 
  5471f7:	8b c6                	mov    eax,esi
  5471f9:	59                   	pop    ecx
  5471fa:	c3                   	ret
  5471fb:	cc                   	int3
  5471fc:	cc                   	int3
  5471fd:	cc                   	int3
  5471fe:	cc                   	int3
  5471ff:	cc                   	int3
```

### 0x005452C0 至 0x00545400（stop排他）

```asm

/workspace/scratch/8e6536b79eff/project_sources/02-Tartaros.bin:     file format pei-i386


Disassembly of section .text:

005452c0 <.text+0x1442c0>:
  5452c0:	55                   	push   ebp
  5452c1:	8b ec                	mov    ebp,esp
  5452c3:	83 e4 f8             	and    esp,0xfffffff8
  5452c6:	6a ff                	push   0xffffffff
  5452c8:	68 1c 3f 94 00       	push   0x943f1c
  5452cd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5452d3:	50                   	push   eax
  5452d4:	83 ec 30             	sub    esp,0x30
  5452d7:	53                   	push   ebx
  5452d8:	56                   	push   esi
  5452d9:	57                   	push   edi
  5452da:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5452df:	33 c4                	xor    eax,esp
  5452e1:	50                   	push   eax
  5452e2:	8d 44 24 40          	lea    eax,[esp+0x40]
  5452e6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5452ec:	8b f1                	mov    esi,ecx
  5452ee:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  5452f2:	83 7e 04 00          	cmp    DWORD PTR [esi+0x4],0x0
  5452f6:	0f 84 8e 08 00 00    	je     0x545b8a
  5452fc:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  545303:	75 29                	jne    0x54532e
  545305:	83 0d 90 43 f9 00 01 	or     DWORD PTR ds:0xf94390,0x1
  54530c:	c7 44 24 48 00 00 00 	mov    DWORD PTR [esp+0x48],0x0
  545313:	00 
  545314:	e8 77 c2 f9 ff       	call   0x4e1590
  545319:	68 80 cc bc 00       	push   0xbccc80
  54531e:	e8 f7 cf 34 00       	call   0x89231a
  545323:	83 c4 04             	add    esp,0x4
  545326:	c7 44 24 48 ff ff ff 	mov    DWORD PTR [esp+0x48],0xffffffff
  54532d:	ff 
  54532e:	a1 3c 42 f9 00       	mov    eax,ds:0xf9423c
  545333:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  545337:	2b 46 64             	sub    eax,DWORD PTR [esi+0x64]
  54533a:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  54533e:	e8 6d 7b 00 00       	call   0x54ceb0
  545343:	83 c6 10             	add    esi,0x10
  545346:	bb 03 00 00 00       	mov    ebx,0x3
  54534b:	8b 06                	mov    eax,DWORD PTR [esi]
  54534d:	85 c0                	test   eax,eax
  54534f:	74 22                	je     0x545373
  545351:	e8 aa 9e 00 00       	call   0x54f200
  545356:	8b 46 fc             	mov    eax,DWORD PTR [esi-0x4]
  545359:	85 c0                	test   eax,eax
  54535b:	74 16                	je     0x545373
  54535d:	8b 80 58 01 00 00    	mov    eax,DWORD PTR [eax+0x158]
  545363:	83 78 08 03          	cmp    DWORD PTR [eax+0x8],0x3
  545367:	75 0a                	jne    0x545373
  545369:	8b 3e                	mov    edi,DWORD PTR [esi]
  54536b:	8d 7f 04             	lea    edi,[edi+0x4]
  54536e:	e8 fd 27 05 00       	call   0x597b70
  545373:	83 c6 0c             	add    esi,0xc
  545376:	4b                   	dec    ebx
  545377:	75 d2                	jne    0x54534b
  545379:	8b 5c 24 14          	mov    ebx,DWORD PTR [esp+0x14]
  54537d:	8b 4b 34             	mov    ecx,DWORD PTR [ebx+0x34]
  545380:	2b 4b 30             	sub    ecx,DWORD PTR [ebx+0x30]
  545383:	33 ff                	xor    edi,edi
  545385:	c1 f9 03             	sar    ecx,0x3
  545388:	85 c9                	test   ecx,ecx
  54538a:	74 74                	je     0x545400
  54538c:	8d 64 24 00          	lea    esp,[esp+0x0]
  545390:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  545397:	8b 53 30             	mov    edx,DWORD PTR [ebx+0x30]
  54539a:	8d 34 fa             	lea    esi,[edx+edi*8]
  54539d:	75 29                	jne    0x5453c8
  54539f:	b8 01 00 00 00       	mov    eax,0x1
  5453a4:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  5453aa:	89 44 24 48          	mov    DWORD PTR [esp+0x48],eax
  5453ae:	e8 dd 98 f9 ff       	call   0x4dec90
  5453b3:	68 30 ce bc 00       	push   0xbcce30
  5453b8:	e8 5d cf 34 00       	call   0x89231a
  5453bd:	83 c4 04             	add    esp,0x4
  5453c0:	c7 44 24 48 ff ff ff 	mov    DWORD PTR [esp+0x48],0xffffffff
  5453c7:	ff 
  5453c8:	a1 3c b1 fa 00       	mov    eax,ds:0xfab13c
  5453cd:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  5453d0:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  5453d4:	0f b7 0e             	movzx  ecx,WORD PTR [esi]
  5453d7:	75 19                	jne    0x5453f2
  5453d9:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  5453e0:	39 48 0c             	cmp    DWORD PTR [eax+0xc],ecx
  5453e3:	73 05                	jae    0x5453ea
  5453e5:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  5453e8:	eb 02                	jmp    0x5453ec
  5453ea:	8b 00                	mov    eax,DWORD PTR [eax]
  5453ec:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  5453f0:	74 ee                	je     0x5453e0
  5453f2:	8b 4b 34             	mov    ecx,DWORD PTR [ebx+0x34]
  5453f5:	2b 4b 30             	sub    ecx,DWORD PTR [ebx+0x30]
  5453f8:	47                   	inc    edi
  5453f9:	c1 f9 03             	sar    ecx,0x3
  5453fc:	3b f9                	cmp    edi,ecx
  5453fe:	72 90                	jb     0x545390
```
