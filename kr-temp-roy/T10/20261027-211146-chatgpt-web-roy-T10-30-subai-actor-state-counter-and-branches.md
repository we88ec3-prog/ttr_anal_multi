# T10-30 — SubAI 對 actor+0x3E8=1/2 的逐 slot 計數與兩個候選技能鍵

## 研究目標與新資料流
先前只確認 `0x549D7D` 寫入狀態 4。這一段轉往 `0x548FF0` 的有界 SubAI 更新函式，查看它是否有輸入來源和切換動作條件。

- `0x548FF0` 的 prologue 與 `ret 0x10` 結束於 `0x54916E`。入口保存 actor、target、索引等資料於 `this+0x50..0x60`，呼叫 `0x549180`，然後透過 actor+0x4 的 model? WORD 與 `this+0xA8` 起三個 stride16 的項目做匹配。注意 actor+0x4 的**正式語義未知**；不能將三個項目當三個技能鍵。
- 在有匹配的 slot（ebx）下依序呼叫 `0x549E10 → 0x54A450 → 0x54A3A0 → 0x54A200 → 0x54A2D0 → 0x54A050`，前一個成功即跳過後續。這是**多條技能/目標候選策略**的證據，不是證明普通攻擊六種組合都透過這個 chain。
- `0x5490FB..0x549114`：若 this+0x4C 非零、actor+0x3E8 為 1 或 2，才執行 `inc DWORD [this+0x40+ebx*4]`；若不是則不累加。
- `0x549118..0x549141`：計數大於 `0x3C`（60）時，如果 actor 狀態是 1 就 push `7`；若為 2 就 push `9`，再 push -1,0,0 到 `0x549C60`，最後把計數清零。**這是多次更新呼叫的次數門檻**，沒有 tick rate 的證據，不能寫成「V 按一秒」。`7`/`9` 尚非已確認的矩陣 key，須先追 `0x549C60` 参数使用。

## BIN 指令原文

研究日期：2026-10-27 Asia/Taipei。原始 KR `Tartaros.bin`（PE32 i386，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`）；唯讀 GNU objdump -Mintel，VA 使用原 PE image base。原件未執行、修改或動態附加。此稿的「函式／物件語義」若沒有 RTTI 標示，僅是可閱讀的暫名。

### VA 0x00548FF0–0x00549050
```asm
00548ff0 <.text+0x147ff0>:
  548ff0:	55                   	push   ebp
  548ff1:	8b ec                	mov    ebp,esp
  548ff3:	83 e4 f8             	and    esp,0xfffffff8
  548ff6:	51                   	push   ecx
  548ff7:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  548ffa:	53                   	push   ebx
  548ffb:	56                   	push   esi
  548ffc:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  548fff:	57                   	push   edi
  549000:	8b 7d 10             	mov    edi,DWORD PTR [ebp+0x10]
  549003:	89 46 50             	mov    DWORD PTR [esi+0x50],eax
  549006:	8d 47 01             	lea    eax,[edi+0x1]
  549009:	89 4e 54             	mov    DWORD PTR [esi+0x54],ecx
  54900c:	89 56 58             	mov    DWORD PTR [esi+0x58],edx
  54900f:	89 7e 5c             	mov    DWORD PTR [esi+0x5c],edi
  549012:	89 46 60             	mov    DWORD PTR [esi+0x60],eax
  549015:	e8 66 01 00 00       	call   0x549180
  54901a:	8b 4e 50             	mov    ecx,DWORD PTR [esi+0x50]
  54901d:	85 c9                	test   ecx,ecx
  54901f:	0f 84 43 01 00 00    	je     0x549168
  549025:	0f b7 51 04          	movzx  edx,WORD PTR [ecx+0x4]
  549029:	33 db                	xor    ebx,ebx
  54902b:	8d 86 a8 00 00 00    	lea    eax,[esi+0xa8]
  549031:	39 10                	cmp    DWORD PTR [eax],edx
  549033:	74 12                	je     0x549047
  549035:	43                   	inc    ebx
  549036:	83 c0 10             	add    eax,0x10
  549039:	83 fb 03             	cmp    ebx,0x3
  54903c:	7c f3                	jl     0x549031
  54903e:	5f                   	pop    edi
  54903f:	5e                   	pop    esi
  549040:	5b                   	pop    ebx
  549041:	8b e5                	mov    esp,ebp
  549043:	5d                   	pop    ebp
  549044:	c2 10 00             	ret    0x10
  549047:	83 fb ff             	cmp    ebx,0xffffffff
  54904a:	0f 84 18 01 00 00    	je     0x549168
```

### VA 0x00549050–0x00549171
```asm
00549050 <.text+0x148050>:
  549050:	8b 46 6c             	mov    eax,DWORD PTR [esi+0x6c]
  549053:	8d 14 47             	lea    edx,[edi+eax*2]
  549056:	03 d0                	add    edx,eax
  549058:	89 9e 08 01 00 00    	mov    DWORD PTR [esi+0x108],ebx
  54905e:	8b 14 95 0c a6 d6 00 	mov    edx,DWORD PTR [edx*4+0xd6a60c]
  549065:	33 ff                	xor    edi,edi
  549067:	89 96 0c 01 00 00    	mov    DWORD PTR [esi+0x10c],edx
  54906d:	39 7c 9e 04          	cmp    DWORD PTR [esi+ebx*4+0x4],edi
  549071:	75 1f                	jne    0x549092
  549073:	8b 56 5c             	mov    edx,DWORD PTR [esi+0x5c]
  549076:	0f b7 89 88 00 00 00 	movzx  ecx,WORD PTR [ecx+0x88]
  54907d:	52                   	push   edx
  54907e:	50                   	push   eax
  54907f:	51                   	push   ecx
  549080:	e8 5b 12 f4 ff       	call   0x48a2e0
  549085:	8b f8                	mov    edi,eax
  549087:	e8 e4 27 00 00       	call   0x54b870
  54908c:	89 44 9e 04          	mov    DWORD PTR [esi+ebx*4+0x4],eax
  549090:	33 ff                	xor    edi,edi
  549092:	e8 79 0d 00 00       	call   0x549e10
  549097:	85 c0                	test   eax,eax
  549099:	75 2b                	jne    0x5490c6
  54909b:	e8 b0 13 00 00       	call   0x54a450
  5490a0:	85 c0                	test   eax,eax
  5490a2:	75 22                	jne    0x5490c6
  5490a4:	e8 f7 12 00 00       	call   0x54a3a0
  5490a9:	85 c0                	test   eax,eax
  5490ab:	75 19                	jne    0x5490c6
  5490ad:	e8 4e 11 00 00       	call   0x54a200
  5490b2:	85 c0                	test   eax,eax
  5490b4:	75 10                	jne    0x5490c6
  5490b6:	e8 15 12 00 00       	call   0x54a2d0
  5490bb:	85 c0                	test   eax,eax
  5490bd:	75 07                	jne    0x5490c6
  5490bf:	8b ce                	mov    ecx,esi
  5490c1:	e8 8a 0f 00 00       	call   0x54a050
  5490c6:	c6 46 4c 01          	mov    BYTE PTR [esi+0x4c],0x1
  5490ca:	39 7c 9e 04          	cmp    DWORD PTR [esi+ebx*4+0x4],edi
  5490ce:	74 2b                	je     0x5490fb
  5490d0:	8d 43 01             	lea    eax,[ebx+0x1]
  5490d3:	c1 e0 04             	shl    eax,0x4
  5490d6:	03 c6                	add    eax,esi
  5490d8:	74 21                	je     0x5490fb
  5490da:	56                   	push   esi
  5490db:	8b f8                	mov    edi,eax
  5490dd:	e8 ce ee 2b 00       	call   0x807fb0
  5490e2:	85 c0                	test   eax,eax
  5490e4:	75 13                	jne    0x5490f9
  5490e6:	8b 8e 08 01 00 00    	mov    ecx,DWORD PTR [esi+0x108]
  5490ec:	03 c9                	add    ecx,ecx
  5490ee:	c7 84 ce ac 00 00 00 	mov    DWORD PTR [esi+ecx*8+0xac],0x1
  5490f5:	01 00 00 00 
  5490f9:	33 ff                	xor    edi,edi
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
  549145:	8b 4e 70             	mov    ecx,DWORD PTR [esi+0x70]
  549148:	8b 45 14             	mov    eax,DWORD PTR [ebp+0x14]
  54914b:	89 08                	mov    DWORD PTR [eax],ecx
  54914d:	8a 56 74             	mov    dl,BYTE PTR [esi+0x74]
  549150:	88 50 04             	mov    BYTE PTR [eax+0x4],dl
  549153:	33 c0                	xor    eax,eax
  549155:	66 89 46 72          	mov    WORD PTR [esi+0x72],ax
  549159:	89 7e 50             	mov    DWORD PTR [esi+0x50],edi
  54915c:	89 7e 54             	mov    DWORD PTR [esi+0x54],edi
  54915f:	89 7e 58             	mov    DWORD PTR [esi+0x58],edi
  549162:	89 7e 5c             	mov    DWORD PTR [esi+0x5c],edi
  549165:	89 7e 60             	mov    DWORD PTR [esi+0x60],edi
  549168:	5f                   	pop    edi
  549169:	5e                   	pop    esi
  54916a:	5b                   	pop    ebx
  54916b:	8b e5                	mov    esp,ebp
  54916d:	5d                   	pop    ebp
  54916e:	c2 10 00             	ret    0x10
```

## 資料流／偽碼
```cpp
// state0x3E8、slotIndex 和 counter 為暫名
if (slotMatched && strategySearchSucceededOrVisited()) {
   if (this_->flag4C && (actor->field3E8 == 1 || actor->field3E8 == 2))
      ++this_->counter40[slotIndex];
   if (this_->counter40[slotIndex] > 60) {
      if (actor->field3E8 == 1) call_549C60(0,0,-1,7);
      else if (actor->field3E8 == 2) call_549C60(0,0,-1,9);
      this_->counter40[slotIndex] = 0;
   }
}
```
該偽碼只保留必要條件；完整分支如上反組譯，參數寄存器／棧位置不可據此取代原生呼叫約定。前置 compare 0x3C 是**大於**才觸發；首次從0開始且每次+1將經過61次加法才成立（若沒有其他重置）。

## 與 T11／V 的分界
T11 候選：`0x549C60` 技能候選測試、`0x549E10` 目標距離狀態、`0x5490xx` 逐 slot counter。現有資料含 AI 目標與 actor 模型匹配，不能當成玩家蓄氣直接作業。下一段對 `0x549C60` 的參數 fallback、角色 gate 和矩陣選取做定向解析。
