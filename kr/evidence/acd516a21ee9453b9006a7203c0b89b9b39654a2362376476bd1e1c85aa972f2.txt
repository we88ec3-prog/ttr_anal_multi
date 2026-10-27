# KR T10/T11 交界研究 — T10-21 輸入處理進入技能可用性檢查

- 日期：2026-10-27 Asia/Taipei
- 證據：原始 Tartaros.bin，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- 方式：BIN 唯讀 objdump i386，.text VA 0x401000／raw 0x400，位址均為 VA
- 任務隔離：T10 主導攻擊輸入與連接；技能計時、消耗、施放裁決的 T11 邊界以引用／候選標記，不擅改 T11 task.json 或別人的分析
- 不執行目標、不修改遊戲檔案、不將本地替代連段窗口視為原版值

## 核心結論
已於同一控制器流程確認 `0x546263 CALL 0x546780` 取得輸入，之後 `0x5462DD CALL 0x54F270` 使用角色／矩陣／當前附加參數判斷可用性。這是 T10↔T11 的**實際靜態交界**，比單純同時引用矩陣強。不過，尚不能證明 `0x546780` 輸出的某個 bit 是 Z 普攻或技能取消。

函式由 actor (`edi`) +0x3E8、索引自 `[ebp+8]` 與矩陣相關資料整理給 `0x54F270`。回傳非零時，`0x5462E6` 設定堆疊 byte flag 1；回傳零後仍檢查 actor+0x3E8，並可能在 `0x546302` 清除 word 中部分位元（保留 bit15）。這代表輸入結果與技能可用性不是同一件事，後續會依 guard 裁決，不能直接視作施放成功。

## 證據與精確限制
`0x5462DD` 是 T11 技能可用性 predicate 的使用點，建議標記為 **T10 控制器 -> T11 技能 gate**。對 T11 而言不是技能施放結束／開始證據：這裡沒有確認冷卻啟動 writer、消耗 writer、普攻完成回調。

## 暫定 C++ 控制流
```cpp
// 意義暫定，只反映可見分支
inputMask = AggregateInput(actor, ...);    // 0x546780
if (inputMask & 0x7FFF) {
    bool available = SkillFlagAvailability(skillCtx, index, selectedFlag); // 0x54F270
    if (available || actor->field3E8 != 0) localGate = 1;
    else output.word2 &= 0x8000;
}
```

## 下一段
擴充 `0x54F270` 本身，核實位元組 flag 到矩陣 key 的映射，以及返回值的精確判斷與副作用。

## 附錄：原始 BIN 位址範圍反組譯摘錄

### VA 00546230..00546320
```asm
00546230 <.data+0x145630>:
  546230:	8b 87 58 01 00 00    	mov    eax,DWORD PTR [edi+0x158]
  546236:	85 c0                	test   eax,eax
  546238:	74 03                	je     0x54623d
  54623a:	8b 70 2c             	mov    esi,DWORD PTR [eax+0x2c]
  54623d:	8b cf                	mov    ecx,edi
  54623f:	e8 8c 3c f8 ff       	call   0x4c9ed0
  546244:	85 f6                	test   esi,esi
  546246:	0f 84 ba 00 00 00    	je     0x546306
  54624c:	85 c0                	test   eax,eax
  54624e:	0f 85 b2 00 00 00    	jne    0x546306
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
  54630f:	b8 01 00 00 00       	mov    eax,0x1
  546314:	09 05 14 7c fb 00    	or     DWORD PTR ds:0xfb7c14,eax
  54631a:	89 44 24 40          	mov    DWORD PTR [esp+0x40],eax
  54631e:	e8 2d          	call   0x6d0750
```