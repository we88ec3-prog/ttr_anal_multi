# T10-29 — Actor +0x3E8 的共用技能狀態來源、條件物件比對與控制器邊界

## 本段目標
先前 T10-25 提到 actor+0x3E8 傳入 `0x54F270`。本段反向驗證此欄位至少還被 SubAI 的條件物件所讀取，避免把它只按 Z/V 蓄氣狀態命名。此欄位真正 setter 尚未定位。

## 新增原生驗證
- `0x54ADC0` 是獨立函式，以輸入物件 `[arg+0x50]` 找 actor，actor 存在時取得 `[actor+0x3E8]`，actor 不存在取 0。最後與 `this+0x4` 比較，相等回 1，不等回 0。**這直接證明同一 actor 欄位可作為 SubAI condition predicate 的精確相等比較參數**，但不能證明 `this+0x4` 是蓄氣需求。
- `0x546100` 中呼叫 `0x54F270` 前，`0x5462B4` 將 `actor+0x3E8` 壓棧；`0x5462BC..0x5462C3` 依資料記錄第 2 byte 是否非零選擇兩個 byte 之一，`0x5462D2..0x5462D9` 再用 controller 索引選 skill status object。呼叫結果 0 的分支將輸出 action word 與 0x8000 AND，清除低15 bits，**輸入准入**和**施放成功**在此不可等同。
- `0x54825D` 在另一控制器路徑同樣讀 `actor+0x3E8`，並用 `0x54F270`。這是一個交叉的資料來源，不應把 0x546100 專稱「Z」的唯一 handler。

## 可復現 BIN 指令：精確函式窗口

研究日期：2026-10-27 Asia/Taipei。原始 KR `Tartaros.bin`（PE32 i386，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`）；唯讀 GNU objdump -Mintel，VA 使用原 PE image base。原件未執行、修改或動態附加。此稿的「函式／物件語義」若沒有 RTTI 標示，僅是可閱讀的暫名。

### VA 0x0054ADC0–0x0054ADE0
```asm
0054adc0 <.text+0x149dc0>:
  54adc0:	55                   	push   ebp
  54adc1:	8b ec                	mov    ebp,esp
  54adc3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  54adc6:	8b 40 50             	mov    eax,DWORD PTR [eax+0x50]
  54adc9:	33 d2                	xor    edx,edx
  54adcb:	85 c0                	test   eax,eax
  54adcd:	74 06                	je     0x54add5
  54adcf:	8b 90 e8 03 00 00    	mov    edx,DWORD PTR [eax+0x3e8]
  54add5:	33 c0                	xor    eax,eax
  54add7:	3b 51 04             	cmp    edx,DWORD PTR [ecx+0x4]
  54adda:	0f 94 c0             	sete   al
  54addd:	5d                   	pop    ebp
  54adde:	c2                   	.byte 0xc2
  54addf:	04                   	.byte 0x4
```

### VA 0x00546254–0x00546309
```asm
00546254 <.text+0x145254>:
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
  546306:	f6                   	.byte 0xf6
  546307:	05                   	.byte 0x5
  546308:	14                   	.byte 0x14
```

### VA 0x0054824C–0x00548290
```asm
0054824c <.text+0x14724c>:
  54824c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  54824f:	66 8b 40 02          	mov    ax,WORD PTR [eax+0x2]
  548253:	ba ff 7f 00 00       	mov    edx,0x7fff
  548258:	66 23 c2             	and    ax,dx
  54825b:	74 30                	je     0x54828d
  54825d:	8b 8e e8 03 00 00    	mov    ecx,DWORD PTR [esi+0x3e8]
  548263:	33 d2                	xor    edx,edx
  548265:	38 57 02             	cmp    BYTE PTR [edi+0x2],dl
  548268:	51                   	push   ecx
  548269:	0f 95 c2             	setne  dl
  54826c:	8a 14 3a             	mov    dl,BYTE PTR [edx+edi*1]
  54826f:	88 54 24 1c          	mov    BYTE PTR [esp+0x1c],dl
  548273:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  548277:	8b 54 24 18          	mov    edx,DWORD PTR [esp+0x18]
  54827b:	51                   	push   ecx
  54827c:	8b 4a 10             	mov    ecx,DWORD PTR [edx+0x10]
  54827f:	e8 ec 6f 00 00       	call   0x54f270
  548284:	85 c0                	test   eax,eax
  548286:	74 56                	je     0x5482de
  548288:	c6 44 24 13 01       	mov    BYTE PTR [esp+0x13],0x1
  54828d:	8b 7d 0c             	mov    edi,DWORD PTR [ebp+0xc]
```

## 暫定 C++ 語意草圖
```cpp
bool SkillConditionEquals(Condition* self, SubAIContext* input) {
    Actor* actor = input->actorAt50;
    uint32_t state = actor ? *(uint32_t*)((char*)actor + 0x3E8) : 0;
    return state == *(uint32_t*)((char*)self + 0x4);
}
// 控制器實際分支：InputMask -> availability -> 有條件保留/清除行動低15位
```
這是指令層級功能概要，不含真正型別與命名；需透過 constructor/RTTI 回填。

## 與使用者遊戲行為的關係
使用者指出按鍵可改、Z/X/C 與其組合、V 點按／長按均會影響招式。actor+0x3E8 很可能提供技能取用的其中一項選擇狀態；**尚未找到此欄位由 V 輸入更新的 writer**，也未證實四個 matrix tier 全由 V 控制。

## 證據級別／待查
已確認：兩路 controller 讀取及 SubAI 精確相等條件。推測：該欄位表示角色技能可用性相關狀態。未確認：V 綁定、是否 charge stage、狀態 0/1/2 的玩家意義、動作 cancel 或 cooldown 對應。下一段沿 SubAI 選招與逐 slot 計數詳細展開，不假定它是玩家蓄氣。