# T10-65 — `0x5961C0` 消費者與 receiver 型別邊界

- 研究時間：2026-10-28T02:22:16+08:00（Asia/Taipei）
- 研究對象：KR `Tartaros.bin`；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 原始 PE：`.text` VA `0x401000`，raw `0x400`；本檔 VA 與 raw 使用 `raw=VA−0x400C00`（限 `.text`）
- 版本／方法：x86 objdump 從本機原始 BIN 離線只讀重解碼；已有 T10-1～60、T01整合為歷史線索而非本批 native 證明
- 主責限制：T10 普攻、輸入與連段；T11技能裁決、T12傷害公式僅引用；未執行/附加客戶端
- 本段是否完整還原原生功能：**否**。局部組合與資料流保留未閉合點。

## 摘要：可由本次原始 BIN 核對的有限事實

`0x59624E` 呼叫 `0x6D4CE0` 後，先受局部 `byte [ebp-0xF]` 與 index 0x0D/0x0E 條件影響，接著在 return==1 時呼叫 `[vtable+0xEC]`，以該 virtual 的結果決定某局部 byte；另一處 `0x59643F` 再次呼叫 reader。這表明 reader 結果進入多態 predicate，而非直接寫 actor motion。Virtual receiver 的實際類型必須從 `[ebp-0x1C]` 的指標來源、建構與 vtable 反查確定。

## 第一手 x86 證據

### VA `0x005961C0` ～ `0x005962CD`／raw start `0x001955C0`

```asm
  5961c0:	55                   	push   ebp
  5961c1:	8b ec                	mov    ebp,esp
  5961c3:	6a ff                	push   0xffffffff
  5961c5:	68 ea ae 93 00       	push   0x93aeea
  5961ca:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5961d0:	50                   	push   eax
  5961d1:	83 ec 24             	sub    esp,0x24
  5961d4:	53                   	push   ebx
  5961d5:	56                   	push   esi
  5961d6:	57                   	push   edi
  5961d7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5961dc:	33 c5                	xor    eax,ebp
  5961de:	50                   	push   eax
  5961df:	8d 45 f4             	lea    eax,[ebp-0xc]
  5961e2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5961e8:	8b d9                	mov    ebx,ecx
  5961ea:	89 5d ec             	mov    DWORD PTR [ebp-0x14],ebx
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
```

### VA `0x005963EA` ～ `0x00596480`／raw start `0x001957EA`

```asm
  5963ea:	e8 2b bf 2f 00       	call   0x89231a
  5963ef:	83 c4 04             	add    esp,0x4
  5963f2:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  5963f9:	8b 0d 24 f6 fd 00    	mov    ecx,DWORD PTR ds:0xfdf624
  5963ff:	89 4d d0             	mov    DWORD PTR [ebp-0x30],ecx
  596402:	3b f1                	cmp    esi,ecx
  596404:	0f 84 ac 01 00 00    	je     0x5965b6
  59640a:	80 7d f1 00          	cmp    BYTE PTR [ebp-0xf],0x0
  59640e:	8b 45 e8             	mov    eax,DWORD PTR [ebp-0x18]
  596411:	8b 70 08             	mov    esi,DWORD PTR [eax+0x8]
  596414:	89 75 d4             	mov    DWORD PTR [ebp-0x2c],esi
  596417:	74 24                	je     0x59643d
  596419:	81 fe f9 2a 00 00    	cmp    esi,0x2af9
  59641f:	72 08                	jb     0x596429
  596421:	81 fe fa 2a 00 00    	cmp    esi,0x2afa
  596427:	76 14                	jbe    0x59643d
  596429:	8b 10                	mov    edx,DWORD PTR [eax]
  59642b:	89 55 e8             	mov    DWORD PTR [ebp-0x18],edx
  59642e:	e9 7a 01 00 00       	jmp    0x5965ad
  596433:	68 34 20 bf 00       	push   0xbf2034
  596438:	e8 f3 76 2e 00       	call   0x87db30
  59643d:	32 db                	xor    bl,bl
  59643f:	e8 9c e8 13 00       	call   0x6d4ce0
  596444:	83 f8 01             	cmp    eax,0x1
  596447:	0f 85 96 00 00 00    	jne    0x5964e3
  59644d:	8b 4d e4             	mov    ecx,DWORD PTR [ebp-0x1c]
  596450:	85 c9                	test   ecx,ecx
  596452:	74 11                	je     0x596465
  596454:	8b 01                	mov    eax,DWORD PTR [ecx]
  596456:	8b 90 ec 00 00 00    	mov    edx,DWORD PTR [eax+0xec]
  59645c:	56                   	push   esi
  59645d:	ff d2                	call   edx
  59645f:	84 c0                	test   al,al
  596461:	74 02                	je     0x596465
  596463:	b3 01                	mov    bl,0x1
  596465:	80 7d f3 00          	cmp    BYTE PTR [ebp-0xd],0x0
  596469:	0f 85 fd 00 00 00    	jne    0x59656c
  59646f:	84 db                	test   bl,bl
  596471:	0f 85 f9 00 00 00    	jne    0x596570
  596477:	8b 7d ec             	mov    edi,DWORD PTR [ebp-0x14]
  59647a:	8d 45 dc             	lea    eax,[ebp-0x24]
  59647d:	50                   	push   eax
  59647e:	8d 8f 80 00 00 00    	lea    ecx,[edi+0x80]
```

## 直接 caller 檢索（僅 E8 near call，不含虛擬／間接）

- `0x5961C0` 的 .text 直接 `call` 候選 `0` 處：
- `0x6D4A30` 的 .text 直接 `call` 候選 `2` 處：`0x490DFC`, `0x58A607`
- `0x6D4CE0` 的 .text 直接 `call` 候選 `2` 處：`0x59624E`, `0x59643F`
- `0x6D4DC0` 的 .text 直接 `call` 候選 `29` 處：`0x594672`, `0x5946CB`, `0x59471B`, `0x5947FD`, `0x59484D`, `0x59492F`, `0x59497F`, `0x594CD4`, `0x594DC4`, `0x594EB4`, `0x594FA4`, `0x595094`, `0x595184`, `0x595274`, `0x595364`, `0x595454`, `0x595544`, `0x595634`, `0x595724`, `0x595814`, `0x595901`, `0x5959F4`, `0x5CD68A`, `0x5CE5BA`, `0x62B5BA` …

## 可檢驗偽碼（只描述局部控制流）

```cpp
// 研究用示意，非原始符號／函式原型
// state_read(index): index 域首先決定容器，查無或超出時可回傳 0；
// reset(context): 按 mode / gate 清零一般 array 或特殊樹中對應 node；
// event_candidate: state_byte == 1 時可觸發有限命令構造／virtual callback。
// 尚缺：OS event writer -> action mapping -> player receiver -> motion writer。
```

## 證據分級與反證邊界

- **已確認（局部）**：上列 x86 指令及已列明直接控制分支與資料讀寫；逐段原始 bytes 已由 hash 符合的 BIN 反組譯。
- **部分確認**：來源索引／回傳 byte 與多態 callback 存在聯繫；型別、物件生命週期及上游來源尚未封閉。
- **僅合理假設**：此資料可能參與玩家可自訂鍵位及攻擊輸入；缺完整 player receiver 身分與事件來源證據。
- **尚待驗證**：非零 phase writer、V tap/held、Z press/hold、普攻／技能隊列、動畫完成／取消、client-server authority。
- **明確排除推論**：`0x547240` 的 `>500ms` 不是原版連段窗口；SubAI >60 次不是 V held 秒數；`CHAIN_WINDOW=0.65` 為 AI 替代；命令索引數不等普攻段數。

## 可接續工作

後續應辨識 vptr `+0xEC/+0xF0` 的 caller ABI、該物件的 ctor 及獨立寫入者，再以具體條件區分普攻候選和 UI/其他 input consumer；不同 virtual slot 不可從 offset 猜測為 cast/cancel。

## 與歷史原稿的關係

- 以 T10-45～60（原始 `kr-temp-roy/`）作交叉參考；這份是本輪**新補定向 BIN 原始證據與條件細分**，不是宣布舊報告全函式獲正式接受。
- 未改動 owner/catalog、T11/T12 或其他研究者產物。須由 T01 後續整合者另行審核才可提正式 claim。