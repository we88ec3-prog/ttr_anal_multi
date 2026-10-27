# KR T10/T11 交界研究 — T10-24 普攻→技能／技能→普攻交界：已證實資料流與缺口

- 日期：2026-10-27 Asia/Taipei
- 證據：原始 Tartaros.bin，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 方式：BIN 唯讀 objdump i386，.text VA 0x401000／raw 0x400，位址均為 VA
- 任務隔離：T10 主導攻擊輸入與連接；技能計時、消耗、施放裁決的 T11 邊界以引用／候選標記，不擅改 T11 task.json 或別人的分析
- 不執行目標、不修改遊戲檔案、不將本地替代連段窗口視為原版值

## 研究命題
使用者明確補充「普攻可視為技能系統的一部分」，並要求比較 Z 普攻接技能及技能結束接普攻。本文件把這當作**研究假說／觀察**而不是 BIN 已驗證的實作結構。

## 已由第一手機器碼支持的關係
1. `0x546780` 的輸入聚合與 `0x54F270` availability 在同一條 `0x546100` 控制器路徑相接（`0x546263` -> `0x5462DD`）。可證明 **控制器依技能 availability 篩選輸入**。
2. `0x54F270` 讀取 matrix model/tier/key，並經 tree lookup 查 remaining DWORD 為零，為真正 T11 相關的技能 gate，但不代表發出施放事件。
3. 另外三個 `0x54F270` 呼叫者分別來自不同 controller / SubAI 條件，並不能直接合成一個全域 combo graph。
4. `0x549D7D` 寫入 `object + (object+0x108)*16 + 0xAC` 一個 DWORD 值 4，構成可繼續追查的**條件成立後狀態寫入者**，但暫不能命名為 normal attack index。

## 尚未證實的四種 transition
| 問題 | 現況 | 應採集的證據 |
|---|---|---|
| Z 重複按下，普攻續段 | 未證實 | action key + actor motion completion + state writer |
| Z 按住，普攻自動續段 | 未證實 | held poll / animation end / next action |
| 普攻中按技能，切到技能 | 未證實 | 同一 actor current motion 與 skill input 接受／拒絕條件，是否緩存 |
| 技能結束接普攻 | 未證實 | 技能完成 callback、狀態清除／queue flush、Z pressed/held 被消費的時間 |

## T11 標記表
- **T11-相關已確認**：`0x54F270` 可用性 check；`0x819220`/`0x81A8E0` 矩陣 key；`0x54F4E0` 樹查找含可能插入；`0x549980` SubAI 技能條件，僅既有 audited 范圍。
- **T10 主責、引用 T11**：`0x546100`、`0x546780`、`0x54827F` controller 輸入 gate。
- **可能交叉但暫不可命名**：`0x549D54` 返回後狀態寫入；`0x5961C0` 事件 phase 1/3 分流；`0x547240` 500ms gate。
- **不可直接當技能判定**：`0x50C640` cmd 0x22、`0x548918` cmd 0x68、`0x81A8E0` 純 lookup、T10-1 的 500ms timer。

## 下一批 T10-25～28 / T11
A. 從 motion 完成及 actor+0x3E8 讀寫 xref 追 action completion consumer。
B. 找 `0x549D7D` 那組 16-byte status slot 的 reader、初始化、重置條件。
C. 尋找 `0x54F4E0` cooldown entry 的實際非零剩餘時間 writer，不能只找 predicate。
D. 找 Z 映射的 `Table/KeyMapping.xml`，並驗證 pressed/held。
E. 最後才比較四種 transition 的 gating（Z 連按、Z 長按、普攻→技能、技能→普攻）。

## 範圍限制
不執行目標、不修改遊戲或封包；T11 尚未正式 owner 登記，本批只分析 T10↔T11 shared boundary，不覆寫任何其他 Agent 已負責的方法。

## 附錄：原始 BIN 位址範圍反組譯摘錄

### VA 00546250..00546310
```asm
00546250 <.data+0x145650>:
  546250:	b2 00                	mov    dl,0x0
  546252:	00 00                	add    BYTE PTR [eax],al
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
  54630d:	75 29                	jne    0x546338
  54630f:	b8           	mov    eax,0x1
```

### VA 00549D45..00549D95
```asm
00549d45 <.data+0x149145>:
  549d45:	cb                   	retf
  549d46:	8a 04 02             	mov    al,BYTE PTR [edx+eax*1]
  549d49:	88 44 24 14          	mov    BYTE PTR [esp+0x14],al
  549d4d:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  549d51:	52                   	push   edx
  549d52:	8b c7                	mov    eax,edi
  549d54:	e8 17 55 00 00       	call   0x54f270
  549d59:	85 c0                	test   eax,eax
  549d5b:	74 2d                	je     0x549d8a
  549d5d:	66 8b 46 72          	mov    ax,WORD PTR [esi+0x72]
  549d61:	8b 96 08 01 00 00    	mov    edx,DWORD PTR [esi+0x108]
  549d67:	66 33 c7             	xor    ax,di
  549d6a:	b9 ff 7f 00 00       	mov    ecx,0x7fff
  549d6f:	66 23 c1             	and    ax,cx
  549d72:	66 31 46 72          	xor    WORD PTR [esi+0x72],ax
  549d76:	03 d2                	add    edx,edx
  549d78:	b8 01 00 00 00       	mov    eax,0x1
  549d7d:	c7 84 d6 ac 00 00 00 	mov    DWORD PTR [esi+edx*8+0xac],0x4
  549d84:	04 00 00 00 
  549d88:	eb 04                	jmp    0x549d8e
  549d8a:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  549d8e:	8b 4c 24 18          	mov    ecx,DWORD PTR [esp+0x18]
  549d92:	85 c9                	test   ecx,ecx
  549d94:	74                 	je     0x549df3
```