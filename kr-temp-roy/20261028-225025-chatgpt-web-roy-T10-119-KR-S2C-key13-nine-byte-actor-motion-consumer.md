# T10-119 — KR S→C 應用 key13：9-byte 角色更新列、actor lookup、virtual 回呼與 motion/position consumer（BIN-first）

## 0. 來源、方法、有效範圍

唯讀 KR 原始 `Tartaros.bin`／`Tartaros.exe`，沒有執行、修改、連線、抓現場 packet 或使用 fixture 假代原生 Server。研究分支 `t10/roy/chatgpt-web`，本次明確授權提交；`main` 不修改。GitHub T10-118 是段號導航，T10-105/106 是分派表與接收 queue 的導航，重要地址及分支本次重新以 objdump 核對，避免將既有推論當本段原生發現。

- BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，本地本輪實際重算。
- `.text` image VA 0x401000/raw 0x400；`raw=VA−0x400C00`。handler 0x4B01C0 原生 raw `0xAF5C0`，consumer 0x4C8A90 raw `0xC7E90`。
- 本段有效證據是列出的函式／局部分支。仍未從真實 socket wire 封包 capture 識別 category2 header key13 是否就代表某次 Z 普攻回覆，也沒有 dynamic actor 族別實例。

## 1. 第一輪重大新發現：key13 handler 的真正步長為9，不是10

`0x4ADD50` 架設應用分派 table：`0x4ADDD0 mov [eax+0x6c],0x4B01C0`，索引13的每個 8-byte slot 之 handler pointer 所在 `base+4+8*13 = base+0x6C`；這和 T10-105／106 的分派層相容。在分類2且首 WORD key13、active state/table 為這個實作的**條件下**，`0x4B01C0` 會處理收到的記憶體 buffer。這不是直接證實 Server wire 原始 bytes 或傳送端與 C2S 000A 之間的 ACK 因果。

`0x4B01EC` 取 argC length L，L<2 時 count=0。其後 `(L−2)*0x38E38E39` 的高 DWORD 再 `shr edx,1`，可還原為 `floor((L−2)/9)`（對 unsigned 32-bit 定義域）；原始算式 `0x38E38E39=954437177` 為除9的 magic multiplier。`0x4B0211` 將 EDI 設為 `P+5`；`0x4B039E` 每次 `add edi,9`。因此一筆 9 bytes，而非10。handler 採截斷筆數，尾端不足9 bytes 不作當筆。L為2時0列；L=11時1列；L=20時2列。

以列索引 i（從0開始）列出原生存取：

| Buffer offset | 寬度 | BIN 機器碼 | 原生可證用途 |
|---|---:|---|---|
| P+0 | WORD | 分派 callback 先取首 WORD | 應用分派 key=13（條件式來源） |
| P+2+9i | WORD | `4B0250 movzx edx,word [edi−3]` | actor ID/tree key |
| P+4+9i | BYTE | `4B0290 movzx eax,byte [edi−1]` | 傳給 actor `vptr+0x58` 的值（業務語義未知） |
| P+5+9i | WORD | `4B0313 movzx ecx,word [edi]` | `0x4C8A90` 的 stack WORD 參數 |
| P+7+9i | FLOAT32 | `4B030F fld dword [edi+2]` | `0x4C8A90` 的浮點 stack 參數 |

注意 `0x4B031A` 的 `0x4C8A90` **不是全局函式參數都從 stack 讀取**：其開頭以 ESI 作 actor 物件，讀 `[esi+0xD8/+0xDC]`；這是跨函式 ESI live register，不能把 EDI 誤當 actor。上述 WORD、FLOAT32 的玩法名稱（action／方向／距離）不從欄位尺寸臆測。

## 2. 角色 lookup／缺失分支／兩種 callback

- `0x4B0250` 讀 actorID，`0x4B025D mov ecx,0xFAB138`，`0x4B0266 call 0x82EF00`；`0x4B026F` 比對 sentinel `[0xFAB13C]`。有效 node 才從 `[node+0x10]` 取得 `ESI=actor`。
- 查不到 actor 或 payload 為0，`0x4B027E..4B028B` 記錄錯誤、跳過當筆效果，再到 `0x4B039E` 推進下一筆；不會必然 abort 全包。
- 找到 actor，`0x4B0290..29C` 以 `actor vtable+0x58`、推入該列 BYTE 呼叫。**這是物件 virtual method，本段未在所有 actor 子類確認具體實作或驗證為 motion 起手**。
- 在 `0x4B029E..2AC`，若 `actor+0x3A8` 非零則置零；其後 `actor+0xB0` 旗標被存取，若 `actor+0x370` 非零且 `actor+0x15C` 可用，會透過附屬物件的 `vtable+0xC` 做另一種浮點回呼。呼叫參數來源含 `[0xFB7C20+4*BYTE(actor+0xB0)]` 對應 float table。這是有界的附屬效果支鏈，不可直接說是本地普攻起手。
- `0x4B030F..31A` 傳 WORD、float 並呼叫 `0x4C8A90`；後者會讀角色 position/delta 類浮點欄位（`actor+0xA0/+0xA4`、`+0xD8/+0xDC`）、有條件呼叫 actor `vptr+0x44`，再處理 `+0x370/+0x3A8/+0xB0` 等旗標。因此收包角色分支確實可能修改 actor 的運動／空間相關 state，但不能只因函式的用途而宣稱一定啟動某個攻擊 animation clip。

## 3. 本地 actor 與一般 actor 的真正邊界

`0x4B0326 mov esi,[esi+0x9C]` 後，`0x4B0357 cmp esi,[0xF93930]`；只有相等才進 `0x4B035F cmp word[edi],0x12` 的特殊分支。特殊分支在條件成立且 lazy flag 尚未設置時呼叫 `0x4FFE60`，之後 `push 0xA; call 0x501650`。**這是原生 object identity 差異支線**，不能在沒有 `actor+0x9C`／`0xF93930` provenance 前將其確定叫「本地玩家」。即使這裡是局部主體的特例，也沒有本段證據表明 key13 是 Client 預播或 Server 承認之後才播。

此外特例 `word[edi]==0x12` 並非 `app key 0x12`：EDI 此刻指向當筆 P+5，讀的是列內 WORD，不可與 outer key13 或 C2S 000A 混成同一命名空間。

## 4. 有界資料路徑及推導偽碼

```cpp
// descriptive pseudo-code, not original C++ symbols
void handleKey13(uint8_t* P, uint32_t L, Context* ctx) {
  uint32_t n = L < 2 ? 0 : (L - 2) / 9;
  for (uint32_t i = 0; i < n; ++i) {
    uint8_t* row = P + 2 + 9*i;
    uint16_t actorId = read_u16(row + 0);
    uint8_t stateByte = row[2];
    uint16_t valueWord = read_u16(row + 3);
    float valueFloat = read_f32(row + 5);
    Actor* a = findActor(FAB138, actorId);
    if (!a) { native_log_missing(); continue; }
    a->vfunc58(stateByte);
    // actor flags and optional subordinate callback
    actor_position_related_consumer_4C8A90(a, valueWord, valueFloat);
    // special object identity + per-row valueWord == 0x12 may trigger a side-effect
  }
}
```

**重要限制**：不清楚上述 `valueWord`、`valueFloat` 到 `0x4C8A90` 的全部執行 ABI 細節、各 actor 具體 vtable、全部 overflow／錯誤分支；偽碼只是列迴圈/有界 def-use 的記號，並非 payload 全欄位業務規格。

## 5. 玩家操作 → C→S → S→C → actor 矩陣

| 玩家情境 | Client 本地條件 | C→S | S→C | Client actor/motion 效果 | 責任及等級 |
|---|---|---|---|---|---|
| 站立短按 Z，當前 bank Key44→ID13 | phase1/2、UI未攔截、matrix/timer／controller 前提見 T10-101～118 | C2S 000A (6+5N) 在 N>0、selector0 有效及 queue/socket gates 開時可到 `WSASend` | **本段尚未證明 key13 是該次000A的回覆**；僅證 key13 handler 執行角色列 | 初始動畫在回包前或後未知 | Client 發送有條件；原版 Server 內部裁決未知 |
| 收到分類2 header K=13、使用本表 | callback4930E0→分派→4B01C0；L≥11有至少一列 | 此收包 handler 不送普攻封包 | 對每列查角色、呼叫 vptr+58、再作空間/附屬更新 | actor-specific，未證與 Z 一一配對 | 原生確定局部消費； wire 來源仍有 framing/decode 前提 |
| 收到 K13，但 actorID 不存在 | 跳過本列，仍可遍歷其餘列 | 無由本 handler 確認的新 C2S | 有界 log 缺 actor | 不對該缺失 actor 呼叫 vptr58/4C8A90 | 原生確認 |
| 特殊身份 object 匹配且列 WORD=0x12 | 經 +0x9C identity 對比 F93930 | 不證明有額外攻擊包 | 有界觸發特殊回呼 | 含 4FFE60/501650 支線；語義 unknown | 部分確認，不臆指本地玩家 |
| 長按／連按／施放中再按 Z，鍵盤或滑鼠移動 | 需 phase/tick 和 motion 時序分別追 | 封包次數與門檻未證 | K13 是否按頻率/情境送未證 | combo、cancel、預播都 unknown | Server 需相容規則，但不能編造原版 |

## 6. 深入門檻與後續追查

**第1輪達重大新發現**：自 native `4ADD50` 真正表項導向 4B01C0；用 `0x38E38E39` 除9與 `add edi,9` 核實 **9-byte 行（而非誤認10）**；完成列內 actorID、state byte、WORD、float 的真實偏移；證實角色 lookup 分支與 `vtable+0x58 → 4C8A90` 更新流程，以及 identity+0x9C 特殊支線。為與舊稿有別的重要有界 payload parser/actor consumer 進展，因此 T10-119-2／-3 未啟動。不代表普攻 S2C ACK／預播時序已閉合。

**T10-120 下一入口**：從 `0x4B01C0` 接受的 actor 具體 vtable 表出發，將 `+0x58` 的動作狀態實作落到 motion clip／controller；查 `0x4C8A90` WORD/float 完整效果與 actor 族別；獨立尋找是否有本地 Client 000A 建包同 tick 的動作啟動，避免以 S2C 存在推論必等待 Server。繼續留存 T02 socket/queue 介面，不跨任務改他人 owner。

## 7. BIN 原生 assembly 附錄

### 7.1 S→C app key13 handler VA 0x4B01C0..0x4B03C7（raw 0xAF5C0..0xAF7C7）

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004b01c0 <.text+0xaf1c0>:
  4b01c0:	55                   	push   ebp
  4b01c1:	8b ec                	mov    ebp,esp
  4b01c3:	83 e4 f8             	and    esp,0xfffffff8
  4b01c6:	6a ff                	push   0xffffffff
  4b01c8:	68 ca 7d 94 00       	push   0x947dca
  4b01cd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4b01d3:	50                   	push   eax
  4b01d4:	83 ec 18             	sub    esp,0x18
  4b01d7:	53                   	push   ebx
  4b01d8:	56                   	push   esi
  4b01d9:	57                   	push   edi
  4b01da:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4b01df:	33 c4                	xor    eax,esp
  4b01e1:	50                   	push   eax
  4b01e2:	8d 44 24 28          	lea    eax,[esp+0x28]
  4b01e6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4b01ec:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4b01ef:	83 f8 02             	cmp    eax,0x2
  4b01f2:	73 04                	jae    0x4b01f8
  4b01f4:	33 d2                	xor    edx,edx
  4b01f6:	eb 0c                	jmp    0x4b0204
  4b01f8:	8d 48 fe             	lea    ecx,[eax-0x2]
  4b01fb:	b8 39 8e e3 38       	mov    eax,0x38e38e39
  4b0200:	f7 e1                	mul    ecx
  4b0202:	d1 ea                	shr    edx,1
  4b0204:	33 db                	xor    ebx,ebx
  4b0206:	3b d3                	cmp    edx,ebx
  4b0208:	0f 86 a1 01 00 00    	jbe    0x4b03af
  4b020e:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  4b0211:	83 c7 05             	add    edi,0x5
  4b0214:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  4b0218:	89 54 24 18          	mov    DWORD PTR [esp+0x18],edx
  4b021c:	eb 04                	jmp    0x4b0222
  4b021e:	8b ff                	mov    edi,edi
  4b0220:	33 db                	xor    ebx,ebx
  4b0222:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  4b0229:	75 25                	jne    0x4b0250
  4b022b:	83 0d 2c b2 fa 00 01 	or     DWORD PTR ds:0xfab22c,0x1
  4b0232:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  4b0236:	e8 55 ea 02 00       	call   0x4dec90
  4b023b:	68 30 ce bc 00       	push   0xbcce30
  4b0240:	e8 d5 20 3e 00       	call   0x89231a
  4b0245:	83 c4 04             	add    esp,0x4
  4b0248:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b024f:	ff 
  4b0250:	0f b7 57 fd          	movzx  edx,WORD PTR [edi-0x3]
  4b0254:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  4b0258:	50                   	push   eax
  4b0259:	8d 44 24 24          	lea    eax,[esp+0x24]
  4b025d:	b9 38 b1 fa 00       	mov    ecx,0xfab138
  4b0262:	89 54 24 20          	mov    DWORD PTR [esp+0x20],edx
  4b0266:	e8 95 ec 37 00       	call   0x82ef00
  4b026b:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  4b026f:	3b 05 3c b1 fa 00    	cmp    eax,DWORD PTR ds:0xfab13c
  4b0275:	74 07                	je     0x4b027e
  4b0277:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  4b027a:	3b f3                	cmp    esi,ebx
  4b027c:	75 12                	jne    0x4b0290
  4b027e:	68 24 6b c0 00       	push   0xc06b24
  4b0283:	e8 d8 d8 23 00       	call   0x6edb60
  4b0288:	83 c4 04             	add    esp,0x4
  4b028b:	e9 0e 01 00 00       	jmp    0x4b039e
  4b0290:	0f b6 47 ff          	movzx  eax,BYTE PTR [edi-0x1]
  4b0294:	8b 16                	mov    edx,DWORD PTR [esi]
  4b0296:	8b 52 58             	mov    edx,DWORD PTR [edx+0x58]
  4b0299:	50                   	push   eax
  4b029a:	8b ce                	mov    ecx,esi
  4b029c:	ff d2                	call   edx
  4b029e:	39 9e a8 03 00 00    	cmp    DWORD PTR [esi+0x3a8],ebx
  4b02a4:	74 06                	je     0x4b02ac
  4b02a6:	89 9e a8 03 00 00    	mov    DWORD PTR [esi+0x3a8],ebx
  4b02ac:	83 be a8 03 00 00 00 	cmp    DWORD PTR [esi+0x3a8],0x0
  4b02b3:	8a 9e b0 00 00 00    	mov    bl,BYTE PTR [esi+0xb0]
  4b02b9:	75 54                	jne    0x4b030f
  4b02bb:	83 be 70 03 00 00 00 	cmp    DWORD PTR [esi+0x370],0x0
  4b02c2:	88 9e a4 03 00 00    	mov    BYTE PTR [esi+0x3a4],bl
  4b02c8:	74 45                	je     0x4b030f
  4b02ca:	8b 86 5c 01 00 00    	mov    eax,DWORD PTR [esi+0x15c]
  4b02d0:	85 c0                	test   eax,eax
  4b02d2:	74 3b                	je     0x4b030f
  4b02d4:	f6 05 18 7c fb 00 01 	test   BYTE PTR ds:0xfb7c18,0x1
  4b02db:	8d 78 04             	lea    edi,[eax+0x4]
  4b02de:	75 0c                	jne    0x4b02ec
  4b02e0:	83 0d 18 7c fb 00 01 	or     DWORD PTR ds:0xfb7c18,0x1
  4b02e7:	e8 e4 46 f9 ff       	call   0x4449d0
  4b02ec:	8b 17                	mov    edx,DWORD PTR [edi]
  4b02ee:	0f b6 c3             	movzx  eax,bl
  4b02f1:	51                   	push   ecx
  4b02f2:	8b cf                	mov    ecx,edi
  4b02f4:	d9 04 85 20 7c fb 00 	fld    DWORD PTR [eax*4+0xfb7c20]
  4b02fb:	8b 42 0c             	mov    eax,DWORD PTR [edx+0xc]
  4b02fe:	d9 5c 24 20          	fstp   DWORD PTR [esp+0x20]
  4b0302:	d9 44 24 20          	fld    DWORD PTR [esp+0x20]
  4b0306:	d9 1c 24             	fstp   DWORD PTR [esp]
  4b0309:	ff d0                	call   eax
  4b030b:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  4b030f:	d9 47 02             	fld    DWORD PTR [edi+0x2]
  4b0312:	51                   	push   ecx
  4b0313:	0f b7 0f             	movzx  ecx,WORD PTR [edi]
  4b0316:	d9 1c 24             	fstp   DWORD PTR [esp]
  4b0319:	51                   	push   ecx
  4b031a:	e8 71 87 01 00       	call   0x4c8a90
  4b031f:	f6 05 90 43 f9 00 01 	test   BYTE PTR ds:0xf94390,0x1
  4b0326:	8b b6 9c 00 00 00    	mov    esi,DWORD PTR [esi+0x9c]
  4b032c:	75 29                	jne    0x4b0357
  4b032e:	b8 01 00 00 00       	mov    eax,0x1
  4b0333:	09 05 90 43 f9 00    	or     DWORD PTR ds:0xf94390,eax
  4b0339:	89 44 24 30          	mov    DWORD PTR [esp+0x30],eax
  4b033d:	e8 4e 12 03 00       	call   0x4e1590
  4b0342:	68 80 cc bc 00       	push   0xbccc80
  4b0347:	e8 ce 1f 3e 00       	call   0x89231a
  4b034c:	83 c4 04             	add    esp,0x4
  4b034f:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b0356:	ff 
  4b0357:	3b 35 30 39 f9 00    	cmp    esi,DWORD PTR ds:0xf93930
  4b035d:	75 3f                	jne    0x4b039e
  4b035f:	66 83 3f 12          	cmp    WORD PTR [edi],0x12
  4b0363:	75 39                	jne    0x4b039e
  4b0365:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  4b036c:	75 29                	jne    0x4b0397
  4b036e:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  4b0375:	c7 44 24 30 02 00 00 	mov    DWORD PTR [esp+0x30],0x2
  4b037c:	00 
  4b037d:	e8 de fa 04 00       	call   0x4ffe60
  4b0382:	68 00 cf bc 00       	push   0xbccf00
  4b0387:	e8 8e 1f 3e 00       	call   0x89231a
  4b038c:	83 c4 04             	add    esp,0x4
  4b038f:	c7 44 24 30 ff ff ff 	mov    DWORD PTR [esp+0x30],0xffffffff
  4b0396:	ff 
  4b0397:	6a 0a                	push   0xa
  4b0399:	e8 b2 12 05 00       	call   0x501650
  4b039e:	83 c7 09             	add    edi,0x9
  4b03a1:	ff 4c 24 18          	dec    DWORD PTR [esp+0x18]
  4b03a5:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  4b03a9:	0f 85 71 fe ff ff    	jne    0x4b0220
  4b03af:	33 c0                	xor    eax,eax
  4b03b1:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  4b03b5:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4b03bc:	59                   	pop    ecx
  4b03bd:	5f                   	pop    edi
  4b03be:	5e                   	pop    esi
  4b03bf:	5b                   	pop    ebx
  4b03c0:	8b e5                	mov    esp,ebp
  4b03c2:	5d                   	pop    ebp
  4b03c3:	c2 0c 00             	ret    0xc
  4b03c6:	cc                   	int3

```

### 7.2 motion/position consumer 0x4C8A90..0x4C8C00（raw 0xC7E90..0xC8000）

```asm

/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c8a90 <.text+0xc7a90>:
  4c8a90:	55                   	push   ebp
  4c8a91:	8b ec                	mov    ebp,esp
  4c8a93:	f3 0f 10 8e d8 00 00 	movss  xmm1,DWORD PTR [esi+0xd8]
  4c8a9a:	00 
  4c8a9b:	0f 57 c0             	xorps  xmm0,xmm0
  4c8a9e:	83 ec 10             	sub    esp,0x10
  4c8aa1:	0f 2e c8             	ucomiss xmm1,xmm0
  4c8aa4:	9f                   	lahf
  4c8aa5:	53                   	push   ebx
  4c8aa6:	57                   	push   edi
  4c8aa7:	f6 c4 44             	test   ah,0x44
  4c8aaa:	7a 11                	jp     0x4c8abd
  4c8aac:	f3 0f 10 8e dc 00 00 	movss  xmm1,DWORD PTR [esi+0xdc]
  4c8ab3:	00 
  4c8ab4:	0f 2e c8             	ucomiss xmm1,xmm0
  4c8ab7:	9f                   	lahf
  4c8ab8:	f6 c4 44             	test   ah,0x44
  4c8abb:	7b 55                	jnp    0x4c8b12
  4c8abd:	8b 86 a0 00 00 00    	mov    eax,DWORD PTR [esi+0xa0]
  4c8ac3:	8b 8e a4 00 00 00    	mov    ecx,DWORD PTR [esi+0xa4]
  4c8ac9:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  4c8acc:	d9 45 f8             	fld    DWORD PTR [ebp-0x8]
  4c8acf:	d8 86 d8 00 00 00    	fadd   DWORD PTR [esi+0xd8]
  4c8ad5:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  4c8ad8:	f3 0f 11 45 f0       	movss  DWORD PTR [ebp-0x10],xmm0
  4c8add:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  4c8ae0:	d9 5d f8             	fstp   DWORD PTR [ebp-0x8]
  4c8ae3:	f3 0f 11 45 f4       	movss  DWORD PTR [ebp-0xc],xmm0
  4c8ae8:	d9 86 dc 00 00 00    	fld    DWORD PTR [esi+0xdc]
  4c8aee:	8b 45 f4             	mov    eax,DWORD PTR [ebp-0xc]
  4c8af1:	d8 45 fc             	fadd   DWORD PTR [ebp-0x4]
  4c8af4:	89 96 d8 00 00 00    	mov    DWORD PTR [esi+0xd8],edx
  4c8afa:	8b 16                	mov    edx,DWORD PTR [esi]
  4c8afc:	8b 52 44             	mov    edx,DWORD PTR [edx+0x44]
  4c8aff:	89 86 dc 00 00 00    	mov    DWORD PTR [esi+0xdc],eax
  4c8b05:	d9 5d fc             	fstp   DWORD PTR [ebp-0x4]
  4c8b08:	6a 01                	push   0x1
  4c8b0a:	8d 45 f8             	lea    eax,[ebp-0x8]
  4c8b0d:	50                   	push   eax
  4c8b0e:	8b ce                	mov    ecx,esi
  4c8b10:	ff d2                	call   edx
  4c8b12:	83 be a8 03 00 00 00 	cmp    DWORD PTR [esi+0x3a8],0x0
  4c8b19:	8a 86 b0 00 00 00    	mov    al,BYTE PTR [esi+0xb0]
  4c8b1f:	88 45 fc             	mov    BYTE PTR [ebp-0x4],al
  4c8b22:	75 34                	jne    0x4c8b58
  4c8b24:	83 be 70 03 00 00 00 	cmp    DWORD PTR [esi+0x370],0x0
  4c8b2b:	88 86 a4 03 00 00    	mov    BYTE PTR [esi+0x3a4],al
  4c8b31:	74 25                	je     0x4c8b58
  4c8b33:	8b 86 5c 01 00 00    	mov    eax,DWORD PTR [esi+0x15c]
  4c8b39:	85 c0                	test   eax,eax
  4c8b3b:	74 1b                	je     0x4c8b58
  4c8b3d:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  4c8b40:	8d 58 04             	lea    ebx,[eax+0x4]
  4c8b43:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  4c8b46:	50                   	push   eax
  4c8b47:	e8 44 bf f7 ff       	call   0x444a90
  4c8b4c:	8b 57 0c             	mov    edx,DWORD PTR [edi+0xc]
  4c8b4f:	8b cb                	mov    ecx,ebx
  4c8b51:	f3 0f 11 04 24       	movss  DWORD PTR [esp],xmm0
  4c8b56:	ff d2                	call   edx
  4c8b58:	8b 86 f0 00 00 00    	mov    eax,DWORD PTR [esi+0xf0]
  4c8b5e:	8b 50 08             	mov    edx,DWORD PTR [eax+0x8]
  4c8b61:	8d 8e f0 00 00 00    	lea    ecx,[esi+0xf0]
  4c8b67:	6a 0d                	push   0xd
  4c8b69:	ff d2                	call   edx
  4c8b6b:	d9 45 0c             	fld    DWORD PTR [ebp+0xc]
  4c8b6e:	8b 06                	mov    eax,DWORD PTR [esi]
  4c8b70:	8b 50 68             	mov    edx,DWORD PTR [eax+0x68]
  4c8b73:	51                   	push   ecx
  4c8b74:	0f bf 4d 08          	movsx  ecx,WORD PTR [ebp+0x8]
  4c8b78:	d9 1c 24             	fstp   DWORD PTR [esp]
  4c8b7b:	51                   	push   ecx
  4c8b7c:	8b ce                	mov    ecx,esi
  4c8b7e:	ff d2                	call   edx
  4c8b80:	5f                   	pop    edi
  4c8b81:	5b                   	pop    ebx
  4c8b82:	8b e5                	mov    esp,ebp
  4c8b84:	5d                   	pop    ebp
  4c8b85:	c2 08 00             	ret    0x8
  4c8b88:	cc                   	int3
  4c8b89:	cc                   	int3
  4c8b8a:	cc                   	int3
  4c8b8b:	cc                   	int3
  4c8b8c:	cc                   	int3
  4c8b8d:	cc                   	int3
  4c8b8e:	cc                   	int3
  4c8b8f:	cc                   	int3
  4c8b90:	55                   	push   ebp
  4c8b91:	8b ec                	mov    ebp,esp
  4c8b93:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4c8b96:	56                   	push   esi
  4c8b97:	8b f1                	mov    esi,ecx
  4c8b99:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4c8b9c:	50                   	push   eax
  4c8b9d:	51                   	push   ecx
  4c8b9e:	8b ce                	mov    ecx,esi
  4c8ba0:	e8 db 1f 00 00       	call   0x4cab80
  4c8ba5:	83 be 70 03 00 00 00 	cmp    DWORD PTR [esi+0x370],0x0
  4c8bac:	74 24                	je     0x4c8bd2
  4c8bae:	8b 86 5c 01 00 00    	mov    eax,DWORD PTR [esi+0x15c]
  4c8bb4:	85 c0                	test   eax,eax
  4c8bb6:	74 1a                	je     0x4c8bd2
  4c8bb8:	8b 16                	mov    edx,DWORD PTR [esi]
  4c8bba:	53                   	push   ebx
  4c8bbb:	8d 58 04             	lea    ebx,[eax+0x4]
  4c8bbe:	8b 42 4c             	mov    eax,DWORD PTR [edx+0x4c]
  4c8bc1:	57                   	push   edi
  4c8bc2:	8b 3b                	mov    edi,DWORD PTR [ebx]
  4c8bc4:	8b ce                	mov    ecx,esi
  4c8bc6:	ff d0                	call   eax
  4c8bc8:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  4c8bcb:	50                   	push   eax
  4c8bcc:	8b cb                	mov    ecx,ebx
  4c8bce:	ff d2                	call   edx
  4c8bd0:	5f                   	pop    edi
  4c8bd1:	5b                   	pop    ebx
  4c8bd2:	5e                   	pop    esi
  4c8bd3:	5d                   	pop    ebp
  4c8bd4:	c2 08 00             	ret    0x8
  4c8bd7:	cc                   	int3
  4c8bd8:	cc                   	int3
  4c8bd9:	cc                   	int3
  4c8bda:	cc                   	int3
  4c8bdb:	cc                   	int3
  4c8bdc:	cc                   	int3
  4c8bdd:	cc                   	int3
  4c8bde:	cc                   	int3
  4c8bdf:	cc                   	int3
  4c8be0:	55                   	push   ebp
  4c8be1:	8b ec                	mov    ebp,esp
  4c8be3:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4c8be6:	56                   	push   esi
  4c8be7:	8b f1                	mov    esi,ecx
  4c8be9:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4c8bec:	50                   	push   eax
  4c8bed:	51                   	push   ecx
  4c8bee:	8b ce                	mov    ecx,esi
  4c8bf0:	e8 cb 20 00 00       	call   0x4cacc0
  4c8bf5:	83 be 70 03 00 00 00 	cmp    DWORD PTR [esi+0x370],0x0
  4c8bfc:	74 24                	je     0x4c8c22
  4c8bfe:	8b 86        	mov    eax,DWORD PTR [esi+0x15c]

```

### 7.3 分派表註冊原生 store

```asm
4ADDD0 C7 40 6C C0 01 4B 00    mov dword [eax+0x6C],0x4B01C0
```

### 7.4 可重現命令

```bash
sha256sum Tartaros.bin Tartaros.exe
objdump -D -Mintel --start-address=0x4b01c0 --stop-address=0x4b03c7 Tartaros.bin
objdump -D -Mintel --start-address=0x4c8a90 --stop-address=0x4c8c00 Tartaros.bin
objdump -D -Mintel --start-address=0x4addb8 --stop-address=0x4addd8 Tartaros.bin
```