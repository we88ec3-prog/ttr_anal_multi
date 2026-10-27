# T10-33 — actor +0x3E8 Writer 候選與玩家控制器輸入後段（BIN-first）

- 分析時間：20261027-213053 (Asia/Taipei)
- 對象：KR Tartaros.bin；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；PE `.text` VA `0x401000`、raw `0x400`，由 `objdump -d -Mintel -j .text` 直接反組譯。
- 範圍：T10 普攻/連段/取消；T11 技能施放只作交界參考。前段 T10-1～32 已存在，不重編。
- 狀態：**部分原生驗證；尚未完整還原 Z/X/C/V、V charge 或 cancel/queue 閉環**。
- GitHub：本次只在本地建立完整筆記，**未提交／未推送**；未改動任何 owner/task/catalog。

## 1. 原生觀察與對象同一性

### 1.1 `0x546100` 控制器的 actor 來源（已確認）
`0x546137`：`edi=[ecx+0xC]`；模式常數 3 時由 `0x546141～0x546148` 按 `arg_0` 切換 actor 指標：`edi=[ecx+(3*arg_0+3)*4]`。`0x546171` 及後段均使用該 `edi`；讀取 `edi+0xE4/+0xE0/+0xB0/+0x158/+0x88/+0x3E8`。**本段的 actor+0x3E8 指 `edi` 的欄位，不能與任意類型同偏移相等同**。

### 1.2 技能候選 gate 實際呼叫（已確認）
在 `0x546254～0x546268` 對 controller 指標執行 `0x546780`；`0x5462B4` 載入 `ecx=[edi+0x3E8]`，`0x5462BF` 先 push 此值；選取輸入來源 byte，再由 `0x5462DD` call `0x54F270`；`0x5462E2` 判回值。若失敗又於 `0x5462ED` 比較 actor+0x3E8 是否 0：非 0 時走將 changed flag 設 1，等於 0 時於 `0x5462FD` 清除輸出 WORD 除 `0x8000` 外的 bits。這**不等於**已確認施放成功、取消窗口或 V 等級。

### 1.3 與輸入/方向後段相連之新控制器分支（已確認）
`0x546338`：`cmp byte ptr [0xFB9009],0`、`sete al`、`mov esi,eax`；其布林結果與 `actor+0x158` 的非空及 `+0x30` 非零、`0x4C9ED0` 結果共同決定是否進 `0x546374～0x54646F`。要注意 `0xFB9009=0xFB9004+5`，故是**一般鍵狀態陣列 index=5 的讀取**，**但 index=5 不等於 Z/X/C/V 任一 action 的證明**。`0x5463BB` 執行 `0x545F30`，`0x54642F` 執行 `0x5464C0`，`0x54644E` 執行 `0x4C90C0`；並出現 `controller+0x70/+0x74`、輸出 `WORD +2` bit15 的改寫。此鏈看似方向/位移相關，**不應未驗證當作技能 cancel**。

### 1.4 新找到之 writer 候選，保留型別邊界（已確認寫入；actor 身分未確認）
- `0x4CE90A～0x4CE914`：`movsx ecx, word ptr [ebp+0xC]`，`mov [ebx+0x3E8],ecx`，且 `eax=[ebx+0x364]`。`0x4CE945` 比較 `[ebx+0x3E8],1`。是真正 **非固定值寫入** 候選，**未證明 ebx 與 0x546100 的 edi 同類**；後續需要求證其函式入口、caller、vtable、RTTI 和物件配置。
- `0x4C71EF` 對 `[ebx+0x3E8]` 寫 `esi`，位於大量初始化 `+0x3C0～0x3E8` 之間，且隨後初始化 `+0x3F4` 容器；`esi` 需由函式序言溯源才可稱 zero init。
- `0x493227` 把指向 `0x4943B0` 的**程式碼地址**寫到 `[eax+0x3E8]`，與多處其他偏移的同類函式指標配置並列；不應解為 actor level 1/2。
- `0x68F3C7`、`0x839B0E`、`0x83A188`、`0x8C2540` 同樣寫 `+0x3E8`，但上下文涉及 loop 複製、container 初始化/重設或成段結構複製；**類型尚未關聯前排除作 actor writer 證據**。

### 1.5 全 `.text` 中直接基底+0x3E8 operand 掃描（已確認字面參照；非完整 alias analysis）
此純 operand 靜態清單**漏掉**經 setter、`lea`、memcpy 或暫存器加偏移間接操作，不能據此宣稱 writer 全部列舉：

```asm
  4ce90a:	0f bf 4d 0c          	movsx  ecx,WORD PTR [ebp+0xc]
  4ce90e:	8b 83 64 03 00 00    	mov    eax,DWORD PTR [ebx+0x364]
  4ce914:	89 8b e8 03 00 00    	mov    DWORD PTR [ebx+0x3e8],ecx
  4ce91a:	85 c0                	test   eax,eax
  4ce91c:	74 27                	je     0x4ce945
  4ce91e:	83 78 24 00          	cmp    DWORD PTR [eax+0x24],0x0
  4ce922:	8d 70 24             	lea    esi,[eax+0x24]
  4ce925:	74 05                	je     0x4ce92c
  4ce927:	e8 c4 fc 2e 00       	call   0x7be5f0
  4ce92c:	8b bb 64 03 00 00    	mov    edi,DWORD PTR [ebx+0x364]
  4ce932:	85 ff                	test   edi,edi
  4ce934:	74 0f                	je     0x4ce945
  4ce936:	e8 75 94 ff ff       	call   0x4c7db0
  4ce93b:	c7 83 64 03 00 00 00 	mov    DWORD PTR [ebx+0x364],0x0
  4ce942:	00 00 00 
  4ce945:	83 bb e8 03 00 00 01 	cmp    DWORD PTR [ebx+0x3e8],0x1
  4ce94c:	0f 85 ec 01 00 00    	jne    0x4ceb3e
  4ce952:	d9 e8                	fld1
```

## 2. 核心控制器原生指令

### 2.1 角色選擇、輸入整合與 predicate
```asm
  54612c:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  546130:	83 3d ac a7 fb 00 03 	cmp    DWORD PTR ds:0xfba7ac,0x3
  546137:	8b 79 0c             	mov    edi,DWORD PTR [ecx+0xc]
  54613a:	c6 44 24 17 00       	mov    BYTE PTR [esp+0x17],0x0
  54613f:	75 0a                	jne    0x54614b
  546141:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  546144:	8d 44 40 03          	lea    eax,[eax+eax*2+0x3]
  546148:	8b 3c 81             	mov    edi,DWORD PTR [ecx+eax*4]
  54614b:	33 f6                	xor    esi,esi
  54614d:	3b fe                	cmp    edi,esi
  54614f:	75 20                	jne    0x546171
  546151:	89 71 7c             	mov    DWORD PTR [ecx+0x7c],esi
  546154:	89 b1 80 00 00 00    	mov    DWORD PTR [ecx+0x80],esi
  546254:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  546258:	8d 4c 24 20          	lea    ecx,[esp+0x20]
  54625c:	51                   	push   ecx
  54625d:	8d 54 24 20          	lea    edx,[esp+0x20]
  546261:	52                   	push   edx
  546262:	57                   	push   edi
  546263:	e8 18 05 00 00       	call   0x546780
  546268:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  54626c:	e8 ef e6 ef ff       	call   0x444960
  546271:	80 b8 ef 07 00 00 01 	cmp    BYTE PTR [eax+0x7ef],0x1
  546278:	75 0c                	jne    0x546286
  54627a:	b8 00 01 00 00       	mov    eax,0x100
  54627f:	c6 44 24 17 01       	mov    BYTE PTR [esp+0x17],0x1
  546284:	eb 09                	jmp    0x54628f
  546286:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  54628a:	66 85 c0             	test   ax,ax
  54628d:	74 13                	je     0x5462a2
  54628f:	66 8b 4b 02          	mov    cx,WORD PTR [ebx+0x2]
  546293:	66 33 c8             	xor    cx,ax
  546296:	ba ff 7f 00 00       	mov    edx,0x7fff
  54629b:	66 23 ca             	and    cx,dx
  54629e:	66 31 4b 02          	xor    WORD PTR [ebx+0x2],cx
  5462a2:	83 3d ac a7 fb 00 01 	cmp    DWORD PTR ds:0xfba7ac,0x1
  5462a9:	74 5b                	je     0x546306
  5462ab:	66 85 c0             	test   ax,ax
  5462ae:	74 56                	je     0x546306
  5462b0:	8b 74 24 24          	mov    esi,DWORD PTR [esp+0x24]
  5462b4:	8b 8f e8 03 00 00    	mov    ecx,DWORD PTR [edi+0x3e8]
  5462ba:	33 d2                	xor    edx,edx
  5462bc:	38 56 02             	cmp    BYTE PTR [esi+0x2],dl
  5462bf:	51                   	push   ecx
  5462c0:	0f 95 c2             	setne  dl
  5462c3:	8a 14 32             	mov    dl,BYTE PTR [edx+esi*1]
  5462c6:	88 54 24 28          	mov    BYTE PTR [esp+0x28],dl
  5462ca:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  5462ce:	51                   	push   ecx
  5462cf:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  5462d2:	8d 14 49             	lea    edx,[ecx+ecx*2]
  5462d5:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5462d9:	8b 4c 91 10          	mov    ecx,DWORD PTR [ecx+edx*4+0x10]
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
```

### 2.2 `0xFB9009` 狀態 gate 及後段 dispatch
```asm
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
  54647a:	eb 09                	jmp    0x546485
  54647c:	ba ff 7f 00 00       	mov    edx,0x7fff
  546481:	66 21 53 02          	and    WORD PTR [ebx+0x2],dx
  546485:	66 8b 43 02          	mov    ax,WORD PTR [ebx+0x2]
  546489:	66 33 44 24 2e       	xor    ax,WORD PTR [esp+0x2e]
  54648e:	b9 00 80 00 00       	mov    ecx,0x8000
  546493:	66 85 c1             	test   cx,ax
  546496:	74 05                	je     0x54649d
  546498:	c6 44 24 17 01       	mov    BYTE PTR [esp+0x17],0x1
  54649d:	8a 44 24 17          	mov    al,BYTE PTR [esp+0x17]
```

### 2.3 writer 候選分離
**函式指標表（不應判為 actor state）**
```asm
  493217:	ba b0 43 49 00       	mov    edx,0x4943b0
  49321c:	89 90 98 04 00 00    	mov    DWORD PTR [eax+0x498],edx
  493222:	ba b0 43 49 00       	mov    edx,0x4943b0
  493227:	89 90 e8 03 00 00    	mov    DWORD PTR [eax+0x3e8],edx
  49322d:	ba b0 43 49 00       	mov    edx,0x4943b0
  493232:	89 90 48 06 00 00    	mov    DWORD PTR [eax+0x648],edx
  493238:	ba b0 43 49 00       	mov    edx,0x4943b0
  49323d:	89 90 a8 04 00 00    	mov    DWORD PTR [eax+0x4a8],edx
  493243:	ba b0 43 49 00       	mov    edx,0x4943b0
  493248:	89 90 c8 04 00 00    	mov    DWORD PTR [eax+0x4c8],edx
```
**另一個 `+0x3E8` 複合物件初始化/清空，身分待確認**
```asm
  4c71d1:	89 b3 d4 03 00 00    	mov    DWORD PTR [ebx+0x3d4],esi
  4c71d7:	89 b3 d8 03 00 00    	mov    DWORD PTR [ebx+0x3d8],esi
  4c71dd:	89 b3 dc 03 00 00    	mov    DWORD PTR [ebx+0x3dc],esi
  4c71e3:	89 b3 e0 03 00 00    	mov    DWORD PTR [ebx+0x3e0],esi
  4c71e9:	89 b3 e4 03 00 00    	mov    DWORD PTR [ebx+0x3e4],esi
  4c71ef:	89 b3 e8 03 00 00    	mov    DWORD PTR [ebx+0x3e8],esi
  4c71f5:	6a 18                	push   0x18
  4c71f7:	89 b3 f8 03 00 00    	mov    DWORD PTR [ebx+0x3f8],esi
  4c71fd:	e8 66 a0 3c 00       	call   0x891268
  4c7202:	83 c4 04             	add    esp,0x4
  4c7205:	3b c6                	cmp    eax,esi
  4c7207:	0f 84 fe 08 00 00    	je     0x4c7b0b
  4c720d:	89 83 f4 03 00 00    	mov    DWORD PTR [ebx+0x3f4],eax
  4c7213:	89 00                	mov    DWORD PTR [eax],eax
```
**獨立容器重設的例子**
```asm
  83a157:	8b 96 e4 03 00 00    	mov    edx,DWORD PTR [esi+0x3e4]
  83a15d:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  83a160:	50                   	push   eax
  83a161:	8d 8e e0 03 00 00    	lea    ecx,[esi+0x3e0]
  83a167:	e8 94 50 00 00       	call   0x83f200
  83a16c:	8b 86 e4 03 00 00    	mov    eax,DWORD PTR [esi+0x3e4]
  83a172:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  83a175:	8b 86 e4 03 00 00    	mov    eax,DWORD PTR [esi+0x3e4]
  83a17b:	89 00                	mov    DWORD PTR [eax],eax
  83a17d:	8b 86 e4 03 00 00    	mov    eax,DWORD PTR [esi+0x3e4]
  83a183:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  83a186:	33 db                	xor    ebx,ebx
  83a188:	89 9e e8 03 00 00    	mov    DWORD PTR [esi+0x3e8],ebx
  83a18e:	8b 8e d4 03 00 00    	mov    ecx,DWORD PTR [esi+0x3d4]
  83a194:	8b 51 04             	mov    edx,DWORD PTR [ecx+0x4]
```

## 3. 形式化部分資料流／偽碼
```cpp
// 只能表達觀察到的局部分支，並非原始遊戲完整邏輯。
ActorLike* actor = (global_mode == 3) ? controller->actors[3*slot+3] : controller->actor_at_0xC;
if (!actor) return false;
// 其他 actor states / component guards ...
auto input_word = controller_546780(...);
if (global_mode != 1 && input_word != 0) {
    auto type_byte = select_byte_from_controller_input_record(...);
    auto gate_result = predicate_54F270(actor_context_for_slot, type_byte, actor->field_0x3E8);
    if (gate_result != 0 || actor->field_0x3E8 != 0) changed = true;
    else output.word_at_2 &= 0x8000;
}
bool index5_is_zero = (global_input_state_0xFB9009 == 0);
if (actor->component_0x158 && actor->component_0x158->field_0x30 &&
    predicate_4C9ED0(actor) == 0 && index5_is_zero) {
    // 0x545F30 / 0x5464C0 / 0x4C90C0 / actor vtable calls ...
    // 具體功能仍待核對，不能先命名成 combo/cancel
}
```

## 4. 證據與推測邊界

| 問題 | 狀態 | 說明 |
|---|---|---|
| BIN 同版本及 PE section | 已確認 | 本次本地原檔 hash + objdump section 核對 |
| `0x546100` actor 指標來源 | 已確認 | `0x546137` / `0x546141～148` |
| actor+0x3E8 流入 `0x54F270` | 已確認 | `0x5462B4～0x5462DD` |
| `0x4CE914` 是可變 16-bit 寫入者 | 已確認 | 其 `ebx` 對象的欄位，非 actor 等價已驗 |
| `0x4CE914` 是玩家 actor 的 charge setter | 尚待驗證 | 缺 RTTI、caller、型別同一性、V action producer |
| `0xFB9009` 為 index5 狀態、影響後段 gate | 已確認 | 但映射到哪個行為仍未確認 |
| Z/X/C 可自訂鍵→動作 row→六組 flags | 尚待驗證 | fallback XML/action row、event writer 尚缺 |
| V tap/held/tier 來源與 Z 普攻替換 | 尚待驗證 | 不可把 SubAI 7/9 當 V level |
| 動作啟動→motion→queue→cancel→next action | 尚待驗證 | 需要跨模組 caller/callee 與寫入者 |

## 5. 後續追查順序（不為段號拆分析）
1. 從 `0x4CE90A` 所屬函式入口、call XREF、物件 constructor/vtable 找 `ebx` 的真實類型；和 `0x546100` 的 `edi` / `+0x158` 布局**逐欄比較**。
2. 沿 `0x6D08F0` 的 key map schema、fallback 與 `[0xFB9004+index]` 非零 writer 查 index5 對應行為；不可把 key index 當 VK 或玩家 action id。
3. 從 `0x545F30`、`0x5464C0`、`0x4C90C0` 追消費者，若僅方向/移動操作則與攻擊分流；再沿 `0x548D20`、`0x54AA60` 動作候選路線進行。
4. 同時核對原稿 T10-29～32 與 T11 的交界，不改他人資料。

## 6. 此段沒有得出的結論
- 沒有證明 `actor+0x3E8` 的有效全域值域或 V 等級，沒有證明 500ms / 60 tick 是連段／蓄氣時間。
- 沒有證明 4 tier 與 V 點按／長按的映射，也沒有證明 Z held 能自動續段或 cancel 行為。
- 目前屬於**T10-33 局部進展**，並非使用者要求的完整功能鏈終局。


---

# T10-33 補充深查（2026-10-27 22:09 Asia/Taipei）

> 此版本保留前述 T10-33 原稿全文並追加第一手證據與重要修正。原稿「局部進展」的判定仍有效：這次封閉了 `+0x3E8` setter 的分支選取與一條 vtable 入口，**並未取得 V 蓄氣／普攻技能互接完整閉環**。以下所有機器碼來自同 SHA256 的 `Tartaros.bin`、由函式入口重新 disassemble；未執行遊戲。

## 7. 重要新突破：actor-like `+0x3E8` 並非孤立的未知 writer

### 7.1 `0x4CE7F0` 是分派 30 種 selector 的原生函式

```asm
4ce7f0: 55                    push ebp
4ce7f1: 8b ec                 mov ebp,esp
4ce81b: 8b d9                 mov ebx,ecx
4ce81d: 0f bf 4d 08           movsx ecx,WORD PTR [ebp+0x8]
4ce821: 8d 41 ff              lea eax,[ecx-0x1]
4ce824: 83 f8 1d              cmp eax,0x1d
4ce827: 0f 87 fe 02 00 00     ja 0x4ceb2b
4ce82d: 0f b6 80 88 eb 4c 00  movzx eax,BYTE PTR [eax+0x4ceb88]
4ce834: ff 24 85 5c eb 4c 00 jmp DWORD PTR [eax*4+0x4ceb5c]
4ce90a: 0f bf 4d 0c           movsx ecx,WORD PTR [ebp+0xc]
4ce90e: 8b 83 64 03 00 00     mov eax,DWORD PTR [ebx+0x364]
4ce914: 89 8b e8 03 00 00     mov DWORD PTR [ebx+0x3e8],ecx
4ce945: 83 bb e8 03 00 00 01  cmp DWORD PTR [ebx+0x3e8],0x1
```

跳轉表本地直接讀取原始位元組，PE `.text` 映射 `file_offset = VA - 0x401000 + 0x400`：

- `0x4CEB5C` 11-entry DWORD table 的第 3 號 index（從 0 起）為 `0x4CE90A`。
- `0x4CEB88` 30-byte selector-to-branch table：`index = selector-1`，其中 **index 4 = 3**，故 **selector 5** 進入 `0x4CE90A`。
- 這裡的 *selector 5* 是參數 `word [ebp+8]` 的協定/屬性編號，**不是 `[0xFB9004+5]` 的按鍵 index 5，更不是 VK_V**。前述 index 5 與此 selector 值相同屬巧合，證據鏈目前完全沒有連線。
- `value = (int16_t)[ebp+0xC]` sign-extend 為 DWORD，對 `this+0x3E8` 寫值，並於 value=1 有進一步的物件處理分支；不能由此直接推得值域恰好為 0/1/2。

**局部偽碼**：

```cpp
// 名稱只為研究用途，未經符號證明。
void actor_like_property_dispatch(int16_t selector, int16_t value) {
    if ((uint32_t)(selector - 1) > 29) goto default_branch;
    switch (selector) {
      case 5:
        this->field_0x3E8 = static_cast<int32_t>(value);
        if (this->field_0x364) { /* previous object cleanup via 0x7BE5F0 / 0x4C7DB0 */ }
        if (this->field_0x3E8 == 1) { /* invokes virtual +0x4C, 0x49B140, 0x551F90;
                                           stores result at +0x364 */ }
        break;
      default: /* many unrelated attributes */ break;
    }
}
```

### 7.2 這條 setter 的宿主具有與玩家控制器 actor 相同的鄰接 layout（增強、但未嚴格完成身分證明）

`0x4CE797～0x4CE7BF`（上一函式）針對 `ebx` 使用 `+0x428 / +0x42C` 和 `+0x158`，並讀 `[ebx+0x158]+0x34`；`0x4CE7F0` 的 this 也是 `[ecx] -> ebx` 並使用 `+0x364` 與 `+0x3E8`；`0x546100` 的 `edi` 使用 `+0x158` 和 `+0x3E8`。此外 `0x4C7070` 建構函式樣式在 `0x4C70C4` 初始化 `+0x15C` 容器並在 `0x4C71EF` 初始化 `+0x3E8`。

```asm
4c7070: 55                    push ebp
4c7098: 8b 5d 08              mov ebx,DWORD PTR [ebp+0x8]
4c70cb: c7 03 54 75 c0 00     mov DWORD PTR [ebx],0xc07554
4c70d1: c7 83 f0 00 00 00 dc 75 c0 00  mov DWORD PTR [ebx+0xf0],0xc075dc
4c71e9: 89 b3 e4 03 00 00     mov DWORD PTR [ebx+0x3e4],esi
4c71ef: 89 b3 e8 03 00 00     mov DWORD PTR [ebx+0x3e8],esi
```

`0x4C7070` 早期於 `0x4C70BE` 明確 `xor esi,esi`，在沒有中途覆寫 `esi` 的情況下 `0x4C71EF` 是零初始化；但仍需跨該完整流程逐指令確認沒有別路變更，**不能以此當 V released reset 的證明**。這些布局線索將 writer 升級為「高關聯候選」，但缺少此 setter 的**物件實例指標與 `0x546100` 的 `edi` 等價的上游鏈**；不得寫成已嚴格證明同一類別。

### 7.3 setter 透過虛擬函式表掛載（新原生 xref）

對 PE raw bytes 搜尋 little-endian `0x004CE7F0` 得到 `file_offset 0x806170` 一筆。依 `.rdata` 映射 `VA 0xBD2000 ↔ raw 0x7D0600`，是 `0x00C07B70`；附近連續的函式指標：

```text
0xC07B64 -> 0x4CDD40
0xC07B68 -> 0x4CDE30
0xC07B6C -> 0x4CE270
0xC07B70 -> 0x4CE7F0  ; 本次 setter dispatcher
0xC07B74 -> 0x4CDBA0
0xC07B78 -> 0x4C8060
0xC07B7C -> 0x4CAB30
0xC07B80 -> 0x4C6FB0
```

此為**可驗證的虛擬方法入口候選**。仍需確認 vtable 頭地址/RTTI，以免將表中的內部偏移當作 slot 0。直接 `call 0x4CE7F0` 在 `.text` 掃描中沒有命中，不代表它沒有被呼叫；**很可能需要沿 virtual dispatch 追 selector/value producer**。這也解釋先前只找 direct caller 為何找不到寫入上游。

## 8. 按鍵狀態與 setter selector 5 的反例

```asm
6d4cae: c6 86 04 90 fb 00 00  mov BYTE PTR [esi+0xfb9004],0x0
6d4d93: 83 fe 27                 cmp esi,0x27
6d4d98: 0f b6 86 04 90 fb 00     movzx eax,BYTE PTR [esi+0xfb9004]
54633a: 38 05 09 90 fb 00        cmp BYTE PTR ds:0xfb9009,al
```

這裡的普通鍵狀態查詢界限是索引 `0..39`，index 5 即 `0xFB9009`；目前只觀察到讀取與部分清零者，**未解析 action-to-key map、非零事件寫入者或 press/held/release phase**。由 selector 5 推導「V」或由 `0xFB9009` 推導「Z」都不成立。

## 9. 實質結果與缺口管理

| 目標 | 進展 | 結論級別 |
| --- | --- | --- |
| `+0x3E8` 非零可變寫入者 | 找到 `0x4CE7F0` selector 5 → `0x4CE90A/14`；value 來自第二個 WORD 參數 | **已確認局部機器碼** |
| setter 的 virtual xref | `.rdata` `0xC07B70` 指向 `0x4CE7F0` | **已確認指標；slot 類型待 RTTI** |
| constructor 類型關聯 | `0x4C7070` 初始化 `+0x3E8`，鄰接有共同 actor-like 欄位 | **合理推測同家族，未關閉 identity path** |
| 玩家輸入產生 selector=5 | 未取得從 Z/X/C/V mapping/event 到 virtual setter 的 callsite | **尚待驗證** |
| V tap/hold → 4-tier 技能選擇 | 未證明 | **尚待驗證** |
| Z held / combo / skill cancel / action queue | 未證明 | **尚待驗證** |

### 接續精確追查

1. 用 `0xC07B70` 所屬 vtable 的 ctor/vptr writer 鎖定 actor 類型和 virtual index，從所有 `call [vptr+offset]` 的上游回溯 `selector=5,value` 的生成者；尤其要驗證 selector 是否源於動畫/網路/腳本，而不是誤判為 V 鍵。
2. 繼續追 `0x6D08F0` XML row/action mapping 與鍵事件非零 writer，釐清 `[0xFB9009]` 是哪個動作。
3. 回到 `0x546100` 的 WORD+2 與 `0x54F270`、`0x548D20`/`0x54AA60`，把 movement branch 與攻擊、skill、motion/cancel queue 拆開並沿實際呼叫關係驗證。

**交付邊界：** 本段可視為「完成一個有原生證據的新 writer 及其分派入口研究主題」，**不可視為 T10 的 Z/X/C/V 與 V 蓄氣、普攻技能互接整條功能鏈已完成**。無 GitHub Commit、Push 或任何 Task 檔案修改。


## 10. T10-33 正式分析結論／結案判定

**研究主題已完成（不等於整體系統已完整還原）。** 原始 BIN 直接證實 `0x4CE7F0` 依 1..30 selector 進入 jump-table；selector=5 時，由 `0x4CE90A` 將第二個 signed WORD 參數擴展後於 `0x4CE914` 寫入接收物件 `+0x3E8`；若舊關聯 `+0x364` 存在，隨後執行清理；新值為 1 時另走特殊後續處理。原始 `.rdata` 中 `0xC07B70` 指向 dispatcher。`0x546100` 的玩家控制器亦讀取所選 actor `+0x3E8`，並在 `0x5462DD` 前傳入技能可用性檢查。

**證據保留界限：** 不能單由同 offset 判定控制器 actor 與 setter 物件完全同一型別；selector=5 絕不能與 `[0xFB9009]` 的鍵狀態 index 5 混同；更不能據此宣稱 V 點按／長按等級。缺少事件輸入到 selector/value、player actor instance identity、motion/queue/cancel 的證據。本段完成 writer/dispatch 主題的深入研究，後續由 T10-34 接續，不以未解缺口阻止結案。

**GitHub：未提交／未推送。**