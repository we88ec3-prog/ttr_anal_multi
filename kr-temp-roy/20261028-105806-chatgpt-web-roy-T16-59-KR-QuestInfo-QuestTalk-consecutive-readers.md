# KR T16-59 — QuestInfo／QuestTalk reader 同一 caller 及資料來源边界

- 日期：2026-10-28T10:58:06.857560+08:00；研究者：`chatgpt-web roy`，KR T16 only。
- 唯讀來源：`Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。PE32/i386 `.text` VA `0x401000`，raw `0x400`；`.rdata` VA `0xBD2000`，raw `0x7D0600`；`.data` VA `0xD61000`，raw `0x95E800`。
- GitHub repo：https://github.com/we88ec3-prog/ttr_anal_multi，前段 T16-53～56 已提交；此批不修改其他 Task／catalog／owner，不研究 TC；不啟動程式。
- disassembly：`objdump -D -Mintel --start-address=... --stop-address=... Tartaros.bin`；局部片段不保證全函式 CFG，但已按已知入口與連續指令核對。

## 已確認的順序與 ABI 級別
- 在 `0x005043E5` 指令 `push edi`，`0x005043E9: call 0x00504740`；緊接 `0x005043EE: push edi`、`0x005043EF: call 0x00505570`。兩次的參數都是 `edi`，且呼叫者以相同 receiver/結構容器連續初始化兩組 reader。
- `0x00504740` 和 `0x00505570` 均有 SEH prologue、大型本地 stack frame，取 `[ebp+8]` 與 `0xC0DB48`／`0xC0DB5C` 作本地字串資料轉換，呼叫 `0x72EE30` 和 `0x72F110`；由之前 T16-51 來源結合，分別為 QuestInfo、QuestTalk loader 候選。
- 兩者屬資源**載入／解析入口**，在此片段未見玩家 quest completion 的 server writer、`Quest16` / `Quest15` 判定或 ACK。

## 直接證據

VA 0x005043E5 raw 0x1037E5 bytes: 57 89 75 fc e8 52 03 00 00 57 e8 7c 11 00 00 8d 95 48 ff ff ff 52 e8 20 b5 ff ff 88 5d fc c7 85
```asm
005043d6 <.text+0x1033d6>:
  5043d6:	88 98 b4 00 00 00    	mov    BYTE PTR [eax+0xb4],bl
  5043dc:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  5043df:	88 99 b5 00 00 00    	mov    BYTE PTR [ecx+0xb5],bl
  5043e5:	57                   	push   edi
  5043e6:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  5043e9:	e8 52 03 00 00       	call   0x504740
  5043ee:	57                   	push   edi
  5043ef:	e8 7c 11 00 00       	call   0x505570
  5043f4:	8d 95 48 ff ff ff    	lea    edx,[ebp-0xb8]
  5043fa:	52                   	push   edx
  5043fb:	e8 20 b5 ff ff       	call   0x4ff920
  504400:	88 5d fc             	mov    BYTE PTR [ebp-0x4],bl
  504403:	c7 85 48 ff ff ff 61 	mov    DWORD PTR [ebp-0xb8],0xea61
  50440a:	ea 00 00 
  50440d:	c7 85 4c ff ff ff 02 	mov    DWORD PTR [ebp-0xb4],0x2
  504414:	00 00 00 
  504417:	84 1d e4 5a fe 00    	test   BYTE PTR ds:0xfe5ae4,bl
  50441d:	75 24                	jne    0x504443
  50441f:	09 1d e4 5a fe 00    	or     DWORD PTR ds:0xfe5ae4,ebx
  504425:	68 c4 5a fe 00       	push   0xfe5ac4
  50442a:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  50442e:	e8 0d 08 08 00       	call   0x584c40
  504433:	68 90 f3 bc 00       	push   0xbcf390
  504438:	e8 dd          	call   0x89231a
```

VA 0x00504740 raw 0x103B40 bytes: 55 8b ec 83 e4 f8 6a ff 68 3d 42 92 00 64 a1 00 00 00 00 50 81 ec 48 02 00 00 a1 20 1f d6 00 33
```asm
00504740 <.text+0x103740>:
  504740:	55                   	push   ebp
  504741:	8b ec                	mov    ebp,esp
  504743:	83 e4 f8             	and    esp,0xfffffff8
  504746:	6a ff                	push   0xffffffff
  504748:	68 3d 42 92 00       	push   0x92423d
  50474d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  504753:	50                   	push   eax
  504754:	81 ec 48 02 00 00    	sub    esp,0x248
  50475a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50475f:	33 c4                	xor    eax,esp
  504761:	89 84 24 40 02 00 00 	mov    DWORD PTR [esp+0x240],eax
  504768:	53                   	push   ebx
  504769:	56                   	push   esi
  50476a:	57                   	push   edi
  50476b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  504770:	33 c4                	xor    eax,esp
  504772:	50                   	push   eax
  504773:	8d 84 24 58 02 00 00 	lea    eax,[esp+0x258]
  50477a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  504780:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  504783:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  50478a:	51                   	push   ecx
  50478b:	b9 48 db c0 00       	mov    ecx,0xc0db48
  504790:	89 44 24 40          	mov    DWORD PTR [esp+0x40],eax
  504794:	e8 97 a6 22 00       	call   0x72ee30
  504799:	33 ff                	xor    edi,edi
  50479b:	89 bc 24 60 02 00 00 	mov    DWORD PTR [esp+0x260],edi
  5047a2:	8b 8c 24 4c 01 00 00 	mov    ecx,DWORD PTR [esp+0x14c]
  5047a9:	bb 10 00 00 00       	mov    ebx,0x10
  5047ae:	39 9c 24 60 01 00 00 	cmp    DWORD PTR [esp+0x160],ebx
  5047b5:	73 07                	jae    0x5047be
  5047b7:	8d 8c 24 4c 01 00 00 	lea    ecx,[esp+0x14c]
  5047be:	57                   	push   edi
  5047bf:	8d b4 24 30 01 00 00 	lea    esi,[esp+0x130]
  5047c6:	e8 45 a9 22 00       	call   0x72f110
  5047cb:	80 bc 24 70 01   	cmp    BYTE PTR [esp+0x170],0x0
  5047d2:
```

VA 0x00505570 raw 0x104970 bytes: 55 8b ec 83 e4 f8 6a ff 68 7b 28 92 00 64 a1 00 00 00 00 50 81 ec 98 00 00 00 a1 20 1f d6 00 33
```asm
00505570 <.text+0x104570>:
  505570:	55                   	push   ebp
  505571:	8b ec                	mov    ebp,esp
  505573:	83 e4 f8             	and    esp,0xfffffff8
  505576:	6a ff                	push   0xffffffff
  505578:	68 7b 28 92 00       	push   0x92287b
  50557d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  505583:	50                   	push   eax
  505584:	81 ec 98 00 00 00    	sub    esp,0x98
  50558a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  50558f:	33 c4                	xor    eax,esp
  505591:	89 84 24 90 00 00 00 	mov    DWORD PTR [esp+0x90],eax
  505598:	53                   	push   ebx
  505599:	56                   	push   esi
  50559a:	57                   	push   edi
  50559b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5055a0:	33 c4                	xor    eax,esp
  5055a2:	50                   	push   eax
  5055a3:	8d 84 24 a8 00 00 00 	lea    eax,[esp+0xa8]
  5055aa:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5055b0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5055b3:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  5055b7:	51                   	push   ecx
  5055b8:	b9 5c db c0 00       	mov    ecx,0xc0db5c
  5055bd:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  5055c1:	e8 6a 98 22 00       	call   0x72ee30
  5055c6:	33 db                	xor    ebx,ebx
  5055c8:	89 9c 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],ebx
  5055cf:	8b 4c 24 44          	mov    ecx,DWORD PTR [esp+0x44]
  5055d3:	bf 10 00 00 00       	mov    edi,0x10
  5055d8:	39 7c 24 58          	cmp    DWORD PTR [esp+0x58],edi
  5055dc:	73 04                	jae    0x5055e2
  5055de:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  5055e2:	53                   	push   ebx
  5055e3:	8d 74 24 28          	lea    esi,[esp+0x28]
  5055e7:	e8 24 9b 22 00       	call   0x72f110
  5055ec:	38 5c 24 68          	cmp    BYTE PTR [esp+0x68],bl
  5055f0:	74 4f                	je     0x505641
```

## 部分確定／缺口
- `Table/QuestInfo.xml` KR 原始 SHA `5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60`，本環境仍未取得可讀 id15/16 節點。`Table/QuestTalk.xml` 原始 SHA `b136fddf1696ff73c5780c269604b5670e35cbb416cd8cce4274aa05865edd28`，先前僅有局部可讀資料。
- T16 owner 僅能追其到任務前置／通知的業務語意；底層 xml reader 不代替 T02／T15 的主責。
- DEFERRED-LOCAL-RESOURCE：需要 `QuestInfo.xml` 的 `id=15/16` 完整 element、其屬性、資料表其他引用；以及根據此表消費者的 xrefs。
