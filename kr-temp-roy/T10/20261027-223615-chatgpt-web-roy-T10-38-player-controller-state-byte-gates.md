# T10-38 — 控制器 index-5 輸入閘門與狀態更新（BIN-first）

- 研究時間：2026-10-27 22:36:15 Asia/Taipei
- 原始樣本：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪實際驗證。
- PE `.text`: VA 0x401000 / raw 0x400。以 objdump `-d -Mintel` 唯讀反組譯，沒有啟動、修補或附加客戶端。
- 關係：T10-33～36 先前證明 constructor 0x4CD6F0、vtable 0xC07B44、slot +0x2C 0x4CE7F0；本文僅以直接 BIN 複驗內容增加限定結論。
- 證據標籤：【確認】直接指令；【推論】結構或控制流解釋；【未知】缺乏呼叫身分／玩家輸入語義。

## 新確認的精確分支
1. 【確認】`0x546338` 對全域 byte `[0xFB9009]` 與零比較後使用 `sete al`，故 `esi = (input_index5 == 0)`。先前僅述「參與分支」；現在已釐清極性：**值為零時通過這一層判斷**，不代表 index 5 即鍵位 V 或 pressed。
2. 【確認】actor 指標 `edi` 的 `[edi+0x158]` 必須非零，且其 `+0x30` 必須非零；`0x4C9ED0(edi)` 需回傳 0；還要 `esi!=0` 才進入 `0x546374`。這四個閘門可獨立列為客戶端真實前置條件。
3. 【確認】`0x546394` 呼叫 `actor.vfunc_60`，結果乘以 `0xC55A70` 的浮點常數，作為 `0x545F30` 第二參數；`0x545F30` 第一參數是 `[ebx+0x4]` BYTE，receiver 是 `actor+0xA0`。屬於具有方向／距離參數的狀態查詢，不可直接命名攻擊施放。
4. 【確認】若 `0x545F30` 回傳 0 且 `[controller+0x74]` 為零，將 actor `+0x3A8` 置零；若非零則 `0x5464C0` 產生下一個 BYTE 結果，存 controller `+0x70`，並設 `[ebx+2]` WORD 的 bit 15。此處的 bit 15 由動作分支進行設/清，並非完整鍵盤 pressed 狀態定義。
5. 【確認】若 controller `+0x70 !=0`，`0x54644E` 呼叫 `0x4C90C0(actor,1)`，而 `0x4C90C0` 操作 actor `+0x3A8`，不操作 `+0x3E8`。這是與 selector=5 setter **不同的已知狀態機**。
6. 【確認】`0x546453` 最終用 actor vfunc `+0x58` 回寫某 byte，並將 controller `+0x74` 歸零，構成此 branch 的狀態收尾。尚無 action ID 或實際 motion queue 證據。
## 條件表
| 條件 | 結果 | 證據 |
|---|---|---|
| `[FB9009] != 0` | 跳出此分支 | 0x546338/36C |
| `[actor+158]==0` 或其 `[+30]==0` | 跳出 | 0x546345/357 |
| `0x4C9ED0(actor)!=0` | 跳出 | 0x54635D/366 |
| direction helper 成功/queue slot 非零 | 呼叫 `0x5464C0` | 0x5463CA..0x54642F |
| controller+70 非零 | 呼叫 `0x4C90C0(actor,1)` | 0x546444..44E |
## 邊界
- 【未知】global input index 5 的 key mapping row 或 action code；不推定 Z/V。
- 【未知】這條方向分支是否被攻擊 controller 共同使用，不據此聲稱取消／接段。
- 後續追 vfunc +0x58/+0x60 實際目標與 `0xFB9009` 非零寫入者。

## 原始 x86 證據附錄（區間按函式入口或前文已知分支起點擷取）

### VA 0x5462dd–0x546374
```asm
005462dd <.text+0x1452dd>:
  5462dd:	e8 8e 8f 00 00       	call   0x54f270
  5462e2:	85 c0                	test   eax,eax
  5462e4:	74 07                	je     0x5462ed
  5462e6:	c6 44 24 17 01       	mov    BYTE PTR [esp+0x17],0x1
  5462eb:	eb 19                	jmp    0x546306
  5462ed:	83 bf e8 03 00 00 00 	cmp    DWORD PTR [edi+0x3e8],0x0
  5462f4:	74 07                	je     0x5462fd
  5462f6:	c6 44 24 17 01       	mov    BYTE PTR [esp+0x17],0x1
  5462fb:	eb 09                	jmp    0x546306
  5462fd:	ba 00 80 00 00       	mov    edx,0x8000
  546302:	66 21 53 02          	and    WORD PTR [ebx+0x2],dx
  546306:	f6 05 14 7c fb 00 01 	test   BYTE PTR ds:0xfb7c14,0x1
  54630d:	75 29                	jne    0x546338
  54630f:	b8 01 00 00 00       	mov    eax,0x1
  546314:	09 05 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,eax
  54631a:	89 44 24 40          	mov    DWORD PTR [esp+0x40],eax
  54631e:	e8 2d a4 18 00       	call   0x6d0750
  546323:	68 30 d5 bc 00       	push   0xbcd530
  546328:	e8 ed bf 34 00       	call   0x89231a
  54632d:	83 c4 04             	add    esp,0x4
  546330:	c7 44 24 40 ff ff ff 	mov    DWORD PTR [esp+0x40],0xffffffff
  546337:	ff 
  546338:	33 c0                	xor    eax,eax
  54633a:	38 05 09 90 fb 00    	cmp    BYTE PTR ds:0xfb9009,al
  546340:	0f 94 c0             	sete   al
  546343:	8b f0                	mov    esi,eax
  546345:	8b 87 58 01 00 00    	mov    eax,DWORD PTR [edi+0x158]
  54634b:	85 c0                	test   eax,eax
  54634d:	0f 84 29 01 00 00    	je     0x54647c
  546353:	83 78 30 00          	cmp    DWORD PTR [eax+0x30],0x0
  546357:	0f 84 1f 01 00 00    	je     0x54647c
  54635d:	8b cf                	mov    ecx,edi
  54635f:	e8 6c 3b f8 ff       	call   0x4c9ed0
  546364:	85 c0                	test   eax,eax
  546366:	0f 85 10 01 00 00    	jne    0x54647c
  54636c:	85 f6                	test   esi,esi
  54636e:	0f 84 08 01 00 00    	je     0x54647c
```

### VA 0x546374–0x54647a
```asm
00546374 <.text+0x145374>:
  546374:	8a 4c 24 1c          	mov    cl,BYTE PTR [esp+0x1c]
  546378:	88 4b 04             	mov    BYTE PTR [ebx+0x4],cl
  54637b:	39 44 24 28          	cmp    DWORD PTR [esp+0x28],eax
  54637f:	0f 84 ea 00 00 00    	je     0x54646f
  546385:	ba ff 7f 00 00       	mov    edx,0x7fff
  54638a:	66 85 53 02          	test   WORD PTR [ebx+0x2],dx
  54638e:	0f 85 db 00 00 00    	jne    0x54646f
  546394:	8b 07                	mov    eax,DWORD PTR [edi]
  546396:	8b 50 60             	mov    edx,DWORD PTR [eax+0x60]
  546399:	8b cf                	mov    ecx,edi
  54639b:	8d b7 a0 00 00 00    	lea    esi,[edi+0xa0]
  5463a1:	ff d2                	call   edx
  5463a3:	dc 0d 70 5a c5 00    	fmul   QWORD PTR ds:0xc55a70
  5463a9:	0f b6 43 04          	movzx  eax,BYTE PTR [ebx+0x4]
  5463ad:	51                   	push   ecx
  5463ae:	d9 5c 24 2c          	fstp   DWORD PTR [esp+0x2c]
  5463b2:	8b ce                	mov    ecx,esi
  5463b4:	d9 44 24 2c          	fld    DWORD PTR [esp+0x2c]
  5463b8:	d9 1c 24             	fstp   DWORD PTR [esp]
  5463bb:	50                   	push   eax
  5463bc:	e8 6f fb ff ff       	call   0x545f30
  5463c1:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  5463c5:	33 d2                	xor    edx,edx
  5463c7:	89 51 70             	mov    DWORD PTR [ecx+0x70],edx
  5463ca:	3b c2                	cmp    eax,edx
  5463cc:	75 43                	jne    0x546411
  5463ce:	39 51 74             	cmp    DWORD PTR [ecx+0x74],edx
  5463d1:	75 3e                	jne    0x546411
  5463d3:	39 97 a8 03 00 00    	cmp    DWORD PTR [edi+0x3a8],edx
  5463d9:	74 06                	je     0x5463e1
  5463db:	89 97 a8 03 00 00    	mov    DWORD PTR [edi+0x3a8],edx
  5463e1:	8b 87 58 01 00 00    	mov    eax,DWORD PTR [edi+0x158]
  5463e7:	3b c2                	cmp    eax,edx
  5463e9:	74 1b                	je     0x546406
  5463eb:	39 50 28             	cmp    DWORD PTR [eax+0x28],edx
  5463ee:	74 16                	je     0x546406
  5463f0:	0f b7 43 02          	movzx  eax,WORD PTR [ebx+0x2]
  5463f4:	a9 ff 7f 00 00       	test   eax,0x7fff
  5463f9:	75 0b                	jne    0x546406
  5463fb:	0d 00 80 00 00       	or     eax,0x8000
  546400:	66 89 43 02          	mov    WORD PTR [ebx+0x2],ax
  546404:	eb 4d                	jmp    0x546453
  546406:	b8 ff 7f 00 00       	mov    eax,0x7fff
  54640b:	66 21 43 02          	and    WORD PTR [ebx+0x2],ax
  54640f:	eb 42                	jmp    0x546453
  546411:	8b 17                	mov    edx,DWORD PTR [edi]
  546413:	8d 43 04             	lea    eax,[ebx+0x4]
  546416:	50                   	push   eax
  546417:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  54641b:	50                   	push   eax
  54641c:	8b 42 60             	mov    eax,DWORD PTR [edx+0x60]
  54641f:	8b cf                	mov    ecx,edi
  546421:	ff d0                	call   eax
  546423:	51                   	push   ecx
  546424:	8b 4c 24 24          	mov    ecx,DWORD PTR [esp+0x24]
  546428:	d9 1c 24             	fstp   DWORD PTR [esp]
  54642b:	8b 51 74             	mov    edx,DWORD PTR [ecx+0x74]
  54642e:	52                   	push   edx
  54642f:	e8 8c 00 00 00       	call   0x5464c0
  546434:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  546438:	89 41 70             	mov    DWORD PTR [ecx+0x70],eax
  54643b:	b8 00 80 00 00       	mov    eax,0x8000
  546440:	66 09 43 02          	or     WORD PTR [ebx+0x2],ax
  546444:	83 79 70 00          	cmp    DWORD PTR [ecx+0x70],0x0
  546448:	74 09                	je     0x546453
  54644a:	6a 01                	push   0x1
  54644c:	8b f7                	mov    esi,edi
  54644e:	e8 6d 2c f8 ff       	call   0x4c90c0
  546453:	0f b6 43 04          	movzx  eax,BYTE PTR [ebx+0x4]
  546457:	8b 17                	mov    edx,DWORD PTR [edi]
  546459:	8b 52 58             	mov    edx,DWORD PTR [edx+0x58]
  54645c:	50                   	push   eax
  54645d:	8b cf                	mov    ecx,edi
  54645f:	ff d2                	call   edx
  546461:	8a 44 24 30          	mov    al,BYTE PTR [esp+0x30]
  546465:	38 43 04             	cmp    BYTE PTR [ebx+0x4],al
  546468:	74 05                	je     0x54646f
  54646a:	c6 44 24 17 01       	mov    BYTE PTR [esp+0x17],0x1
  54646f:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  546473:	c7 41 74 00 00 00 00 	mov    DWORD PTR [ecx+0x74],0x0
```