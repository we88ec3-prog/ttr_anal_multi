# KR T10-8 — 控制器 Gate 與 Z 連段證據邊界整合

紀錄日期：2026-10-27T19:11:40+08:00

## 0. 來源與限制
- 研究對象：韓版 KR T10「普通攻擊與連段」，使用者指出 Z 連按、Z 按住不放兩種操作。
- 原始檔 `/mnt/data/Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；僅唯讀，PE `.text` VA `0x00401000` 對映檔案 raw `0x400`；GNU objdump `-b binary -mi386 -Mintel --adjust-vma`。**所有位址為 VA，函式名稱除符號佐證者均為暫定。**
- 已有 T10-1～T10-4 原稿作背景；本段新增事項皆以本次 raw BIN 讀取核對。未啟動／附加遊戲或修改任何原始資料。
- 原生證據只證明目前觀察到的機器碼與資料流；不可反推出 Z 對應 bit、實際連段時間、是否可玩。

## 1. 分析與證據
本段將 T10-7 已確認的輸入輸出，延伸到 `0x546100` 下游 gate，區分三種層級：**input state**、**actor/action constraint**、**傳送封包**。本輪未見足以證實 Z 長按自動續段的原生閉環，故不把「取得關鍵 bit」虛報為 Z 已還原。

`0x546263` 的返回存進 caller stack，對 controller／actor 的輸入 Word 在 `0x54628F～0x5462A2` 結合原舊值；`0x5462A2` 檢查全域 `0xFBA7AC==1` 並可能短路。`0x5462B0` 取 `[edi+0x3E8]`，`0x5462DD` 用 `ecx` 中的資料結構呼叫 `0x54F270`，以返回值控制 `0x5462E2～0x546306` 是否接受或清理資料。`0x5462FD` 用 `and WORD [ebx+2],0x8000` 清除其低 15 位，**但此分支並未證明是 Z 連段取消**。

在 `0x546306～0x54636E`，全域一次性初始化可呼叫 `0x6D0750`；接著檢查 `[edi+0x158]` 狀態元件是否存在及 `+0x30` 是否為 0，並呼叫 `0x4C9ED0` 檢查旗標。**這是下游條件限制的機器碼事實，正式動作語義未核定。**

本輪 T10-5～T10-8 的可連結證據鏈：
```text
KeyMapping.xml -> 0x6D08F0 / 0x6D0EB0  (前段證據：設定來源)
  -> 0x6D4DC0                    (T10-5 直接使用者：設定查詢與 UI 使用)
  -> 0x6D43F0 / 0x6D1DA0        (T10-6：樹取值／初始化)
[尚未驗證的連結：實際 Z action 與 runtime consumer]
  -> 0x547240 -> 0x546780       (T10-7：時間相位結果→bit；其他 3 路合併)
  -> 0x546100 -> 0x54F270       (T10-8：actor 狀態與分類 gate)
  -> 0x5452C0 -> 0x000A 發送     (之前 T10-1、已引用跨任務網路證據)
```

**明確缺口**：
1. 找到**實際版本** `Table/KeyMapping.xml` 並確認 Z 對應的 row 與 action；fallback 不等於實際配置。
2. 找出 physical keydown、keyup、held 或 polling writer，連回 `0xFB9014`，而非把 `0x547240` 直接命名為 Z 長按。
3. 找出 attack motion／animation 的下一段消費者，確認 held 會如何每段續發，連按是否只依 pressed edge；查出 cancel 與 chain window 的真正依據。
4. 區分 client 與 server 權威；不可沿用本機自製 `CHAIN_WINDOW=0.65`。T12 傷害公式排除。

**證據級別**：確定＝上述指令、欄位、mask 運算、呼叫鏈中每一已觀察邊；合理推測＝存在 actor/action 接受條件；未確認＝兩類 Z 操作合流、續段、取消／窗口與遊玩實測。

**下一階段 T10-9**：優先取得實際 XML 與上游 writer，按控制器 action bit 追查原生普通攻擊下游消費者；不再擴大通用映射 tree/CRT 分支。

**協作**：僅保存 T10 個人研究文件，無遊戲執行或修改，不能覆蓋 T02／T04／T09／T12 的主責結論。根據使用者本次明確授權，四段全完成後方允許 Commit／Push。


## 2. 原始 BIN 組語摘錄（逐址重新反組譯）
### actor/input gate (VA `0x0054627A`)
```asm
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
  54633a:	38                   	.byte 0x38
  54633b:	05                   	.byte 0x5
  54633c:	09                   	.byte 0x9
```

### actor 狀態後續 gate (VA `0x00546338`)
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
  5463c1:	8b                   	.byte 0x8b
  5463c2:	4c                   	dec    esp
  5463c3:	24                   	.byte 0x24
```

### 狀態機 500ms 分支 (VA `0x005472F6`)
```asm
  5472f6:	83 f8 03             	cmp    eax,0x3
  5472f9:	74 34                	je     0x54732f
  5472fb:	3b c7                	cmp    eax,edi
  5472fd:	74 30                	je     0x54732f
  5472ff:	ff 15 a0 25 bd 00    	call   DWORD PTR ds:0xbd25a0
  547305:	2b 46 04             	sub    eax,DWORD PTR [esi+0x4]
  547308:	3d f4 01 00 00       	cmp    eax,0x1f4
  54730d:	76 4f                	jbe    0x54735e
  54730f:	89 7e 04             	mov    DWORD PTR [esi+0x4],edi
  547312:	bf 03 00 00 00       	mov    edi,0x3
  547317:	c7 06 03 00 00 00    	mov    DWORD PTR [esi],0x3
  54731d:	8b c7                	mov    eax,edi
  54731f:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  547322:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  547329:	59                   	pop    ecx
  54732a:	5f                   	pop    edi
  54732b:	8b e5                	mov    esp,ebp
  54732d:	5d                   	pop    ebp
  54732e:	c3                   	ret
  54732f:	89 7e 04             	mov    DWORD PTR [esi+0x4],edi
  547332:	89 3e                	mov    DWORD PTR [esi],edi
  547334:	bf 02 00 00 00       	mov    edi,0x2
  547339:	8b c7                	mov    eax,edi
  54733b:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  54733e:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  547345:	59                   	pop    ecx
  547346:	5f                   	pop    edi
  547347:	8b e5                	mov    esp,ebp
  547349:	5d                   	pop    ebp
  54734a:	c3                   	ret
  54734b:	83 f8 03             	cmp    eax,0x3
  54734e:	74 04                	je     0x547354
  547350:	3b c7                	cmp    eax,edi
  547352:	75 0a                	jne    0x54735e
  547354:	89 7e 04             	mov    DWORD PTR [esi+0x4],edi
  547357:	89 3e                	mov    DWORD PTR [esi],edi
  547359:	bf 04 00 00 00       	mov    edi,0x4
  54735e:	8b c7                	mov    eax,edi
  547360:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  547363:	64                   	fs
```