# T10-32 — 蓄氣、技能矩陣、普攻互接的已證實資料鏈與缺口歸檔

## 本段目標
整合 T10-29～31 與前段 T10-1～28，建立日後可交給 T11 的**精確證據路徑**，清楚區分玩家輸入、角色狀態、SubAI 目標候選、矩陣索引與真正動作／取消判定；不把跨路徑重用的偏移當成同一個物件。

## 新的技術整理（BIN 原生證據）
(1) `0x54ADC0` 的 actor+0x3E8 和 condition+0x4 做相等比較，actor 缺失視為 0。這是能檢查 actor 目前某技能狀態的 condition-like predicate。
(2) `0x5490FB..0x549141` 同 actor 狀態 1/2 控制多次更新計數並選擇 7/9，**有能力隨狀態改變候選**，但屬 SubAI target/skill 流程；次數 0x3C 不等於 60ms 或 60 frames 的已確認時間。
(3) `0x549C60` 的 sentinel -1 從 actor+0x3E8 補值後呼叫 `0x54F270`。這是在 SubAI 技能決策入口與可用性 gate 之間目前最具體的 actor state 傳遞證據。
(4) `0x546100`、`0x54827F` 從角色狀態取得樣本再呼叫 `0x54F270`，同時還有方向、actor active flag 及 controller 節點等守門，不能直接把 `0x54F270` 的 return 1 命名為「動畫取消成功」。
(5) `0x54F270 → 0x819220 → 0x81A8E0` 的 4 tier × 11 key 矩陣回傳技能 ID 並查 cooldown/availability entry，但只是**候選技能是否可用**，未證明如何啟動施放、扣能量、動畫與 server-cast command。

## 典型第一手交叉指令

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

### VA 0x005490FB–0x00549145
```asm
005490fb <.text+0x1480fb>:
  5490fb:	80 7e 4c 00          	cmp    BYTE PTR [esi+0x4c],0x0
  5490ff:	74 17                	je     0x549118
  549101:	8b 56 50             	mov    edx,DWORD PTR [esi+0x50]
  549104:	8b 82 e8 03 00 00    	mov    eax,DWORD PTR [edx+0x3e8]
  54910a:	83 f8 01             	cmp    eax,0x1
  54910d:	74 05                	je     0x549114
  54910f:	83 f8 02             	cmp    eax,0x2
  549112:	75 04                	jne    0x549118
  549114:	ff 44 9e 40          	inc    DWORD PTR [esi+ebx*4+0x40]
  549118:	83 7c 9e 40 3c       	cmp    DWORD PTR [esi+ebx*4+0x40],0x3c
  54911d:	7e 26                	jle    0x549145
  54911f:	8b 46 50             	mov    eax,DWORD PTR [esi+0x50]
  549122:	8b 80 e8 03 00 00    	mov    eax,DWORD PTR [eax+0x3e8]
  549128:	83 f8 01             	cmp    eax,0x1
  54912b:	75 04                	jne    0x549131
  54912d:	6a 07                	push   0x7
  54912f:	eb 07                	jmp    0x549138
  549131:	83 f8 02             	cmp    eax,0x2
  549134:	75 0b                	jne    0x549141
  549136:	6a 09                	push   0x9
  549138:	6a ff                	push   0xffffffff
  54913a:	57                   	push   edi
  54913b:	57                   	push   edi
  54913c:	e8 1f 0b 00 00       	call   0x549c60
  549141:	89 7c 9e 40          	mov    DWORD PTR [esi+ebx*4+0x40],edi
```

### VA 0x00549D29–0x00549D89
```asm
00549d29 <.text+0x148d29>:
  549d29:	83 7d 10 ff          	cmp    DWORD PTR [ebp+0x10],0xffffffff
  549d2d:	75 09                	jne    0x549d38
  549d2f:	8b 8a e8 03 00 00    	mov    ecx,DWORD PTR [edx+0x3e8]
  549d35:	89 4d 10             	mov    DWORD PTR [ebp+0x10],ecx
  549d38:	8b 4d 10             	mov    ecx,DWORD PTR [ebp+0x10]
  549d3b:	33 d2                	xor    edx,edx
  549d3d:	38 50 02             	cmp    BYTE PTR [eax+0x2],dl
  549d40:	51                   	push   ecx
  549d41:	0f 95 c2             	setne  dl
  549d44:	8b cb                	mov    ecx,ebx
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
  549d88:	eb                   	.byte 0xeb
```

### VA 0x005462B0–0x00546307
```asm
005462b0 <.text+0x1452b0>:
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
```

### VA 0x0081A8E0–0x0081A909
```asm
0081a8e0 <.text+0x4198e0>:
  81a8e0:	55                   	push   ebp
  81a8e1:	8b ec                	mov    ebp,esp
  81a8e3:	3c 04                	cmp    al,0x4
  81a8e5:	73 1c                	jae    0x81a903
  81a8e7:	80 f9 0b             	cmp    cl,0xb
  81a8ea:	73 17                	jae    0x81a903
  81a8ec:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  81a8ef:	0f b6 c0             	movzx  eax,al
  81a8f2:	6b c0 0b             	imul   eax,eax,0xb
  81a8f5:	0f b6 c9             	movzx  ecx,cl
  81a8f8:	03 c1                	add    eax,ecx
  81a8fa:	66 8b 44 42 04       	mov    ax,WORD PTR [edx+eax*2+0x4]
  81a8ff:	5d                   	pop    ebp
  81a900:	c2 04 00             	ret    0x4
  81a903:	33 c0                	xor    eax,eax
  81a905:	5d                   	pop    ebp
  81a906:	c2 04 00             	ret    0x4
```

## 按鍵／施放四個核心假說的驗證矩陣
| 行為（使用者回報） | 目前 BIN 支援的邊 | 阻塞證據 |
|---|---|---|
| 可自訂的普攻輸入 | KeyMapping.xml loader 與三 Bank 已有證據 | 實際 XML、預設 Z 對應 action、按鍵 event writer |
| 六種 Z/X/C 單雙組合技能 | 0x54F270 接受 1/2/4 和 3/5/6 flags | 實際操作對應 flags；不同角色的 matrix rows |
| V 點按與長按導致改招 | 角色狀態被採樣並影響 skill availability；SubAI state 1/2 決定候選參數 | V 行動的 KeyMapping、held/edge 判定、寫入 actor+0x3E8 者與 tier 的關係 |
| 普攻→技能、技能→普攻以及連段 | actor availability、控制器輸入 mask 與候選篩選 | motion playback state、動畫完成 callback、next-action queue、取消 gate、server authoritative decision |

## 下一段 T10-33 / T11 關聯任務
- 第一優先：透過 actor 類別 RTTI/vtable 與已知 constructor 查 `[actor+0x3E8]` 的**非零寫入者**，分析設定值變更時機。不可只搜尋固定絕對地址。
- 第二：展開 `0x548D20`、`0x54AA60`，將 `7/9` 的真實轉換與 `0x54F270` AL flags 串起來，避免把參數當 key。
- 第三：查 `0x546100` 在技能 availability 返回後的 actor motion consumer／S2C 回饋，尋找動畫取消、蓄氣後技能與普通攻擊的共同狀態機。
- 第四：取得本機原版 `Table/KeyMapping.xml`，對可自訂 Z/X/C/V 做 mapping-first 證據。

## 限制／協作
T10 主責普攻連段與技能互接；上述 SubAI 技能可用性只作 T11 標記，不覆寫 T11 task.json／owner、不將 AI 動作直接視為玩家輸入。原件唯讀，無客戶端修補。所有未知語義保留在此稿。