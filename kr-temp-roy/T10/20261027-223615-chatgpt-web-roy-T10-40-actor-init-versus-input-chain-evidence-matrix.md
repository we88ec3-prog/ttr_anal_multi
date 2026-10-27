# T10-40 — actor 初始化與控制器輸入的雙鏈界線、後續可驗證橋接點（BIN-first）

- 研究時間：2026-10-27 22:36:15 Asia/Taipei
- 原始樣本：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本輪實際驗證。
- PE `.text`: VA 0x401000 / raw 0x400。以 objdump `-d -Mintel` 唯讀反組譯，沒有啟動、修補或附加客戶端。
- 關係：T10-33～36 先前證明 constructor 0x4CD6F0、vtable 0xC07B44、slot +0x2C 0x4CE7F0；本文僅以直接 BIN 複驗內容增加限定結論。
- 證據標籤：【確認】直接指令；【推論】結構或控制流解釋；【未知】缺乏呼叫身分／玩家輸入語義。

## 新核對：同名/同偏移不能自動合併
1. 【確認】factory `0x4AE5E4` 分配 `0x444`，`0x4AE609` 呼叫 `0x4CD6F0`，`0x4AEB34..0x4AEB7D` 對同一個 `esi` 連續執行 vfunc `+0x3C/+0x44/+0x58/+0x5C/+0x30`。這建立 constructor → instance field init → 虛擬方法的一條具體鏈，但**尚未找到這個 instance 寫入玩家 controller 所讀取的 actor slot 的中間指令**。
2. 【確認】setter `0x4CE90A` 透過 selector 5 把帶號 WORD 擴展為 DWORD `+0x3E8`，先清理 `[+0x364]` 舊從屬狀態；只有當新值為 1 才呼叫 vfunc `+0x4C`、`0x49B140`、`0x551F90`，並把新返回物件存回 `+0x364`。這是具體資料生命週期，不能直接稱作 V 蓄氣動畫。
3. 【確認】`0x5462ED` controller 在 `0x54F270` predicate 失敗後，如果 actor `+0x3E8!=0`，仍會把局部 byte `[esp+0x17]` 設 1。若兩者都不允許，`0x5462FD` 執行 `and WORD [ebx+2],0x8000`。**這是 selector/actor state 影響 controller gate 的強直接證據**，但真正玩家事件如何設定 selector 未知。
4. 【確認】`0x546338` 的 index5==0 判斷只出現在後續的空間/方向輔助分支，不能直接和 `0x5462ED` gate 混成同一個 V 按鍵。
5. 【確認】`0x4C90C0` 管理 `+0x3A8` 旗標；`0x5464C0` 搜尋方向；兩者均可出現在玩家控制器流程中，但不是 `+0x3E8` 的寫入者。
## 可測試狀態轉移（靜態條件）
| 靜態條件 | 可觀察程式分支 | 原生來源 | 玩家語義 |
|---|---|---|---|
| `54F270` true | local flag=1 | 0x5462DD..2E6 | 未知技能類型 |
| predicate false 且 `actor+3E8!=0` | local flag=1 | 0x5462ED..2F6 | 未知 charge/state |
| predicate false 且 `actor+3E8==0` | `word[ebx+2] &= 0x8000` | 0x5462FD..302 | 未知 bit-group |
| `[FB9009]==0` 且 158 chain/4C9ED0 pass | 空間/方向分支 | 0x546338..374 | 未證明攻擊 |
| `4C90C0(actor,1)` 且 `actor+3A8==0` | `actor+3A8=1` | 0x4C90CC..113 | 非 +3E8 |
## 後續工作清單（精確阻塞點）
- 找到確切 `vptr+0x2C` call，其 receiver 必須有從 `0x4CD6F0` 建構實例連續傳遞的資料流；從此回查 selector 參數是否 `5`，而不是盲搜所有 `+0x2C`。
- 確定 actor 指標來自哪個 registry/slot：追 `0x4AEC00` 的 `0x4DFF30` 及 `0x546137` 的取值鏈，中途每個樹節點與索引保留型別。
- 針對 `[0xFB9004+index]` 的**非零 writer**，先辨別 index 5 是何 action row，獨立證實鍵重映射的 Z/X/C/V 對應；勿直接以 VK_Z 猜。
- `0x546100` 下游要另尋動作開始→動畫事件→queue→完成/cancel 的有證據 callback；T11 已有的 skill matrix 只作跨任務引用。
## 批次總結／交付界線
四段分別得到：型別 factory 至 instance 初始化鏈、輸入 index5 的閘門極性和控制器局部 state、方向掃描 helper 的 256 候選上限、setter 與 controller gate 的嚴格證據矩陣。研究深度以函式/狀態流證據為準；未解結構連線明示，不聲稱已還原 V 或 Z 普攻。

## 原始 x86 證據附錄（區間按函式入口或前文已知分支起點擷取）

### VA 0x4ae5dd–0x4ae614
```asm
004ae5dd <.text+0xad5dd>:
  4ae5dd:	ff 24 85 90 ed 4a 00 	jmp    DWORD PTR [eax*4+0x4aed90]
  4ae5e4:	68 44 04 00 00       	push   0x444
  4ae5e9:	e8 7a 2c 3e 00       	call   0x891268
  4ae5ee:	83 c4 04             	add    esp,0x4
  4ae5f1:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  4ae5f5:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x1
  4ae5fc:	01 00 00 00 
  4ae600:	85 c0                	test   eax,eax
  4ae602:	74 0e                	je     0x4ae612
  4ae604:	8b 53 0e             	mov    edx,DWORD PTR [ebx+0xe]
  4ae607:	52                   	push   edx
  4ae608:	50                   	push   eax
  4ae609:	e8 e2 f0 01 00       	call   0x4cd6f0
  4ae60e:	8b f0                	mov    esi,eax
  4ae610:	eb 02                	jmp    0x4ae614
  4ae612:	33 f6                	xor    esi,esi
```

### VA 0x4aeb0a–0x4aeb80
```asm
004aeb0a <.text+0xadb0a>:
  4aeb0a:	0f b6 53 15          	movzx  edx,BYTE PTR [ebx+0x15]
  4aeb0e:	8d 8e f0 00 00 00    	lea    ecx,[esi+0xf0]
  4aeb14:	52                   	push   edx
  4aeb15:	ff d0                	call   eax
  4aeb17:	8b 43 0e             	mov    eax,DWORD PTR [ebx+0xe]
  4aeb1a:	8b 16                	mov    edx,DWORD PTR [esi]
  4aeb1c:	89 86 9c 00 00 00    	mov    DWORD PTR [esi+0x9c],eax
  4aeb22:	0f b6 43 14          	movzx  eax,BYTE PTR [ebx+0x14]
  4aeb26:	89 86 90 00 00 00    	mov    DWORD PTR [esi+0x90],eax
  4aeb2c:	66 8b 43 fc          	mov    ax,WORD PTR [ebx-0x4]
  4aeb30:	66 89 46 04          	mov    WORD PTR [esi+0x4],ax
  4aeb34:	8b 42 3c             	mov    eax,DWORD PTR [edx+0x3c]
  4aeb37:	57                   	push   edi
  4aeb38:	8b ce                	mov    ecx,esi
  4aeb3a:	ff d0                	call   eax
  4aeb3c:	8b 16                	mov    edx,DWORD PTR [esi]
  4aeb3e:	8b 52 44             	mov    edx,DWORD PTR [edx+0x44]
  4aeb41:	6a 01                	push   0x1
  4aeb43:	8d 43 02             	lea    eax,[ebx+0x2]
  4aeb46:	50                   	push   eax
  4aeb47:	8b ce                	mov    ecx,esi
  4aeb49:	ff d2                	call   edx
  4aeb4b:	0f b6 4b 12          	movzx  ecx,BYTE PTR [ebx+0x12]
  4aeb4f:	8b 06                	mov    eax,DWORD PTR [esi]
  4aeb51:	8b 50 58             	mov    edx,DWORD PTR [eax+0x58]
  4aeb54:	51                   	push   ecx
  4aeb55:	8b ce                	mov    ecx,esi
  4aeb57:	ff d2                	call   edx
  4aeb59:	8b 06                	mov    eax,DWORD PTR [esi]
  4aeb5b:	d9 43 0a             	fld    DWORD PTR [ebx+0xa]
  4aeb5e:	8b 50 5c             	mov    edx,DWORD PTR [eax+0x5c]
  4aeb61:	51                   	push   ecx
  4aeb62:	8b ce                	mov    ecx,esi
  4aeb64:	d9 1c 24             	fstp   DWORD PTR [esp]
  4aeb67:	ff d2                	call   edx
  4aeb69:	80 7b 15 18          	cmp    BYTE PTR [ebx+0x15],0x18
  4aeb6d:	75 07                	jne    0x4aeb76
  4aeb6f:	c6 86 bc 00 00 00 01 	mov    BYTE PTR [esi+0xbc],0x1
  4aeb76:	8b 06                	mov    eax,DWORD PTR [esi]
  4aeb78:	8b 50 30             	mov    edx,DWORD PTR [eax+0x30]
  4aeb7b:	8b ce                	mov    ecx,esi
  4aeb7d:	ff d2                	call   edx
  4aeb7f:	8a                   	.byte 0x8a
```

### VA 0x4ce90a–0x4ce9a3
```asm
004ce90a <.text+0xcd90a>:
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
  4ce954:	8b 13                	mov    edx,DWORD PTR [ebx]
  4ce956:	8b 42 4c             	mov    eax,DWORD PTR [edx+0x4c]
  4ce959:	83 ec 08             	sub    esp,0x8
  4ce95c:	d9 5c 24 04          	fstp   DWORD PTR [esp+0x4]
  4ce960:	83 cf ff             	or     edi,0xffffffff
  4ce963:	d9 ee                	fldz
  4ce965:	8b cb                	mov    ecx,ebx
  4ce967:	d9 1c 24             	fstp   DWORD PTR [esp]
  4ce96a:	c7 45 b8 02 00 00 00 	mov    DWORD PTR [ebp-0x48],0x2
  4ce971:	c7 45 bc ec 7a c0 00 	mov    DWORD PTR [ebp-0x44],0xc07aec
  4ce978:	89 7d c0             	mov    DWORD PTR [ebp-0x40],edi
  4ce97b:	89 7d c4             	mov    DWORD PTR [ebp-0x3c],edi
  4ce97e:	c7 45 c8 00 00 00 00 	mov    DWORD PTR [ebp-0x38],0x0
  4ce985:	ff d0                	call   eax
  4ce987:	0f b7 4b 04          	movzx  ecx,WORD PTR [ebx+0x4]
  4ce98b:	51                   	push   ecx
  4ce98c:	8b f0                	mov    esi,eax
  4ce98e:	e8 ad c7 fc ff       	call   0x49b140
  4ce993:	8d 55 b8             	lea    edx,[ebp-0x48]
  4ce996:	8b c8                	mov    ecx,eax
  4ce998:	e8 f3 35 08 00       	call   0x551f90
  4ce99d:	89 83 64 03 00 00    	mov    DWORD PTR [ebx+0x364],eax
```

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

### VA 0x4c90c0–0x4c913a
```asm
004c90c0 <.text+0xc80c0>:
  4c90c0:	55                   	push   ebp
  4c90c1:	8b ec                	mov    ebp,esp
  4c90c3:	51                   	push   ecx
  4c90c4:	83 7d 08 00          	cmp    DWORD PTR [ebp+0x8],0x0
  4c90c8:	53                   	push   ebx
  4c90c9:	57                   	push   edi
  4c90ca:	74 55                	je     0x4c9121
  4c90cc:	83 be a8 03 00 00 00 	cmp    DWORD PTR [esi+0x3a8],0x0
  4c90d3:	75 5f                	jne    0x4c9134
  4c90d5:	83 be 70 03 00 00 00 	cmp    DWORD PTR [esi+0x370],0x0
  4c90dc:	8a 86 b0 00 00 00    	mov    al,BYTE PTR [esi+0xb0]
  4c90e2:	88 45 fc             	mov    BYTE PTR [ebp-0x4],al
  4c90e5:	88 86 a4 03 00 00    	mov    BYTE PTR [esi+0x3a4],al
  4c90eb:	74 23                	je     0x4c9110
  4c90ed:	8b 9e 5c 01 00 00    	mov    ebx,DWORD PTR [esi+0x15c]
  4c90f3:	85 db                	test   ebx,ebx
  4c90f5:	74 19                	je     0x4c9110
  4c90f7:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  4c90fa:	8b 7b 04             	mov    edi,DWORD PTR [ebx+0x4]
  4c90fd:	50                   	push   eax
  4c90fe:	e8 8d b9 f7 ff       	call   0x444a90
  4c9103:	8b 57 0c             	mov    edx,DWORD PTR [edi+0xc]
  4c9106:	8d 4b 04             	lea    ecx,[ebx+0x4]
  4c9109:	f3 0f 11 04 24       	movss  DWORD PTR [esp],xmm0
  4c910e:	ff d2                	call   edx
  4c9110:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4c9113:	89 86 a8 03 00 00    	mov    DWORD PTR [esi+0x3a8],eax
  4c9119:	5f                   	pop    edi
  4c911a:	5b                   	pop    ebx
  4c911b:	8b e5                	mov    esp,ebp
  4c911d:	5d                   	pop    ebp
  4c911e:	c2 04 00             	ret    0x4
  4c9121:	83 be a8 03 00 00 00 	cmp    DWORD PTR [esi+0x3a8],0x0
  4c9128:	74 0a                	je     0x4c9134
  4c912a:	c7 86 a8 03 00 00 00 	mov    DWORD PTR [esi+0x3a8],0x0
  4c9131:	00 00 00 
  4c9134:	5f                   	pop    edi
  4c9135:	5b                   	pop    ebx
  4c9136:	8b e5                	mov    esp,ebp
  4c9138:	5d                   	pop    ebp
  4c9139:	c2                   	.byte 0xc2
```