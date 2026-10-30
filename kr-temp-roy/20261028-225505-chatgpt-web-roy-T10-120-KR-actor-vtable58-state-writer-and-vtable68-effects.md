# T10-120 — KR S→C key13 actor `vtable+0x58` 具體實作、狀態欄位、`vtable+0x68` 分流（BIN-first）

研究時間 Asia/Taipei `20261028-225505`。只讀原始 KR BIN；GitHub 工作分支 `t10/roy/chatgpt-web`。本段依 T10-119 已驗證 9-byte S→C row handler (`0x4B01C0`) 往 actor virtual method 追查。未執行原版 Client、無原始 Server／抓包；對玩法效果嚴格分清 native state write 與 motion clip。

## 0. 原件及映射

- BIN SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，均重新計算。
- PE32 `.text` VA `0x401000` raw `0x400`，`.text raw=VA-0x400C00`；`.rdata` VA `0xBD2000` raw `0x7D0600`，`.rdata raw=VA-0x401A00`。對 runtime 的 `0xFA/0xFB` 欄位不得套用 raw 映射。
- 以 `.rdata` 真實 little-endian DWORD scan 搜尋函式指標 `0x4C8C30`，只列 `.rdata` 此範圍找到的候選；每一張表的 `+0x58`、`+0x44`、`+0x68` 都重新從 BIN bytes 解碼，並以關鍵 actor code 的 objdump 確認入口。

## 1. 第 1 輪重大發現：七張 actor vtable 的 +0x58 都是直接 state byte writer

T10-119 在 `0x4B0290..0x4B029C` 對每個已找到 actor：`movzx eax,byte [edi-1]`、`mov edx,[esi]`、`mov edx,[edx+0x58]`、`push eax`、`mov ecx,esi`、`call edx`。本輪在 `.rdata` 中查到如下七張 table，其 `+0x58` 原生 DWORD 皆為 `0x4C8C30`：

| actor vtable base VA | slot `+0x44` | slot `+0x58` | slot `+0x68` |
|---|---|---|---|
| `0xC07554` | `0x4C8B90` | `0x4C8C30` | `0x4C8DA0` |
| `0xC076AC` | `0x4CAB80` | `0x4C8C30` | `0x4CC0D0` |
| `0xC07B44` | `0x4C8B90` | `0x4C8C30` | `0x4C8DA0` |
| `0xC0C824` | `0x4C8B90` | `0x4C8C30` | `0x4C8DA0` |
| `0xC0C8C4` | `0x4C8B90` | `0x4C8C30` | `0x4C8DA0` |
| `0xC0C9DC` | `0x4C8B90` | `0x4C8C30` | `0x4C8DA0` |
| `0xC0CA9C` | `0x4C8B90` | `0x4C8C30` | `0x4C8DA0` |

`0x4C8C30` 原生指令：`mov al,[ebp+8]` → `mov [ecx+0xB0],al` → `ret 4`。**因此對這七種已確認表，key13 內的 1-byte row field 是 actor+0xB0 的直接寫入來源**，而不是這個 slot 直接啟動 motion clip。

- 靜態掃描範圍只是一段 `.rdata`、等值指標；不能聲稱全程所有 actor 類別都使用同一表，也未從 runtime instance 證實任何特定 actor 是哪一種 vptr。
- 七個命中乃 `+0x58` 算得的候選 vtable base；要由個別 constructor vptr writer 決定實際 instance 型別，不能藉表地址便認定玩家／NPC／怪物分類。

## 2. 同一筆 S→C row 的 actor+0xB0 後續 consumer

`0x4B029C` 回來後，`0x4B02B3 mov bl,[esi+0xB0]` 立即讀回剛寫入的 actor 欄位。`0x4B02BB..0x4B02C8` 在 `+0x3A8`/`+0x370` 等前置條件下寫到 `[actor+0x3A4]`；若附屬物件 `[actor+0x15C]` 可用，便取 `FB7C20[actor+0xB0]` 浮點值並呼叫附屬物件 `virtual+0xC`。這是 byte→浮點表→附屬效果的條件鏈，**不是可確認的 attack motion 起手或攻擊方向**。

`0x4C8A90` 是 key13 每 row 另一條真實 consumer，使用 actor 指標 ESI：當 `[actor+0xD8/+0xDC]` 包含非零 delta 時，對 `[actor+0xA0/+0xA4]` 形成新的 position-like 浮點座標，將 delta 清零，再呼叫 actor `vtable+0x44`；之後又處理 `+0x370/+0x15C/+0xB0` 的附屬回呼。最後 `0x4C8B58..0x4C8B7E` 先對 actor+`0xF0` 的子物件呼叫 `virtual+8` 並 push `0xD`，再以 row WORD（`movsx [ebp+8]`）和 row float（`fld [ebp+C]`）呼叫 actor `vtable+0x68`。這是本段新增的重要 downstream def-use；T10-119 已知二 WORD/float，但本段把 **row 的 WORD+float 如何被下游 virtual+0x68 消費**明確閉合。

## 3. 確實存在不同的 actor subclass 空間／動作下游

- 六張候選表 `+0x44=0x4C8B90`，其中一張 `0xC076AC` 的 `+0x44=0x4CAB80`。後者只有在目標座標與 actor+0xA0/A4 不同時才寫兩個 float；第三個 stack arg 非零時會寫 actor+0xAC=1 並再呼叫 vtable+0x38。前者 `0x4C8B90` 另有附屬物件回呼；兩者效果不應相互套用。
- 六張表 `+0x68=0x4C8DA0`；`0xC076AC` 的 `+0x68=0x4CC0D0`，此函式在原生窗口 `0x4CC0D0` 起始可見 SEH、`[esi] = 0xC07714`、釋放 `+0xF0` 的序列，屬**destructor-like** 特徵。這導致重要限制：不能只由某一張候選表的 +0x68 指向 4CC0D0 就斷言該表與 key13 運行期 actor 相容；可能有不同 vtable address-point／偏移或資料型別。需要 constructor／RTTI 進一步審核以排除假候選。
- 對六張 `+0x68=0x4C8DA0`，該函式把傳入 WORD/DWORD 值寫入 `actor+0x38C`，且當 `[actor+0x15C]!=0` 且 `[actor+0x370]!=0` 時，將 row float 與值交給 `0x7A6970`。這提供明確 row WORD→`actor+0x38C` 的持久 state writer，及另一條附屬效果邊。

**關鍵反證**：`vtable+0x58` 直接寫 `+0xB0`，並不是 animation clip launcher；`vtable+0x68` 的部分表有不同實作且疑似 destructor，不可把所有這七張表一概稱為同一種 Actor subtype。不能以 key13 收到便推論短按 Z 的 ACK 或動畫一定等網路。

## 4. 局部 C++ 偽碼（已證範圍）

```cpp
// ONLY if runtime actor vptr uses one of verified relevant tables;
// descriptive names, not original source
void key13_row_consume(Actor* actor, uint8_t byte2, uint16_t word3, float scalar5) {
    actor->vfunc58(byte2);               // verified 4C8C30: actor->byteB0 = byte2
    if (actor->flag3A8) actor->flag3A8 = 0;
    if (!actor->flag3A8) {
        actor->byte3A4 = actor->byteB0;
        if (actor->ptr370 && actor->ptr15C) subordinate_update(actor->byteB0);
    }
    // in assembly, actor pointer is live in ESI, not passed via stack to 4C8A90
    actor_position_state_consumer_4C8A90(actor, word3, scalar5);
}

void actor_position_state_consumer_4C8A90(Actor* a, uint16_t w, float f) {
    if (a->deltaD8 != 0.0f || a->deltaDC != 0.0f) {
        float xy[2] = {a->posA0 + a->deltaD8, a->posA4 + a->deltaDC};
        a->deltaD8 = a->deltaDC = 0.0f;
        a->vfunc44(xy, 1);
    }
    if (!a->flag3A8 && a->ptr370 && a->ptr15C) subordinate_update(a->byteB0);
    a->subobjectF0->vfunc8(0xD); // actual EAX pointer dereference, not direct F0 vptr
    a->vfunc68((int16_t)w, f);
}
```

## 5. 玩家情境 × C→S × S→C × 動作／分工

| 玩家／觸發 | Client 本地條件 | C→S | S→C | 本地／其他角色結果 | 分工與等級 |
|---|---|---|---|---|---|
| 站立短按 Z，bank 確為 Key44→ID13 | 前段 phase/UI/tick gates 仍在 | `000A` 在 N>0、selector0/queue/send gates 成立時可進 WSASend；本段未重驗動態包數 | key13 是否為 000A ACK **unknown** | 本地起手需否等待未知；不能因 state byte 更新而假定播放攻擊 | C2S 條件式已確認；S2C 因果 unknown |
| 收到 key13 actorID 對應本次確定 table 的 actor | row 寬9 bytes，actor lookup 成功 | 非此 handler 主責 | byte→actor+B0；WORD/float→vfunc68，條件式座標與附屬效果 | actor state 可更動；是否觸發實際 clip 未證 | 原生已確認局部 handler |
| actor vptr slot+44 是 4CAB80 的類別 | position 變動且 flag 非零 | 不涉及 | 存 pos+ A0/A4，置 AC=1、virtual+38 | 更完整的空間狀態更新，非普攻 ACK | BIN 已確認 |
| actor 沒有該 ID／沒有可用附屬物件 | lookup 或 +370/+15C 條件 fail | unknown | 跳過該 actor 或附屬效果 | 不會強行呼叫缺失 actor | 原生確認條件 |
| 相同 key13 row 是本地 actor／其他 actor | 必須另證 instance provenance；特殊 +9C identity branch 未解 | 本段無新發包 | 同 handler 的 object dispatch 依 vptr 分化 | 預播/廣播是否不同仍未知 | 不造 Server ACK 規則 |

## 6. 三輪門檻與下一段

第一輪有**原生重大新發現**：由七張 `.rdata` 虛表精確落地 key13 的 `+0x58 → 0x4C8C30`，確認 row BYTE 的直接 writer `actor+0xB0`；延伸 `0x4C8A90` 的 `+0x68` dispatch，六張候選 table 具體指向 `0x4C8DA0`，後者寫 `actor+0x38C` 並在條件下呼叫 `0x7A6970`。另記錄一張表的疑似 destructor-like 特例，不假冒所有表相容。**T10-120-2/-3 未啟動**；整體動畫與 Server 因果仍未完成。

下一正式段 **T10-121**：查 actor constructor / exact vptr writer，尤其 `0xC076AC`/`0xC07714` 的 vtable 覆寫與 `+0x68` destructor-like 特例；追 actor+0x38C writer 的下游 clip 消費者與 `0x7A6970`；分辨真正 remote actor 與 local actor 的構造／subtype／預播來源。依 T02 和 T09 分工保留介面，不改他人文件。

## 7. 原始機器碼與反組譯附錄（BIN 實際取樣）


### S2C key13 byte writer caller and downstream — VA `0x4b0290..0x4b0326`, raw `0xaf690..0xaf726`

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004b0290 <.text+0xaf290>:
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
```


### vfunc58 actual body — VA `0x4c8c30..0x4c8c40`, raw `0xc8030..0xc8040`

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c8c30 <.text+0xc7c30>:
  4c8c30:	55                   	push   ebp
  4c8c31:	8b ec                	mov    ebp,esp
  4c8c33:	8a 45 08             	mov    al,BYTE PTR [ebp+0x8]
  4c8c36:	88 81 b0 00 00 00    	mov    BYTE PTR [ecx+0xb0],al
  4c8c3c:	5d                   	pop    ebp
  4c8c3d:	c2 04 00             	ret    0x4
```


### row float/WORD consumer — VA `0x4c8a90..0x4c8b88`, raw `0xc7e90..0xc7f88`

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
```


### vfunc68 actor+38C writer — VA `0x4c8da0..0x4c8dd2`, raw `0xc81a0..0xc81d2`

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004c8da0 <.text+0xc7da0>:
  4c8da0:	55                   	push   ebp
  4c8da1:	8b ec                	mov    ebp,esp
  4c8da3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4c8da6:	57                   	push   edi
  4c8da7:	8b b9 5c 01 00 00    	mov    edi,DWORD PTR [ecx+0x15c]
  4c8dad:	89 81 8c 03 00 00    	mov    DWORD PTR [ecx+0x38c],eax
  4c8db3:	85 ff                	test   edi,edi
  4c8db5:	74 16                	je     0x4c8dcd
  4c8db7:	83 b9 70 03 00 00 00 	cmp    DWORD PTR [ecx+0x370],0x0
  4c8dbe:	74 0d                	je     0x4c8dcd
  4c8dc0:	d9 45 0c             	fld    DWORD PTR [ebp+0xc]
  4c8dc3:	51                   	push   ecx
  4c8dc4:	d9 1c 24             	fstp   DWORD PTR [esp]
  4c8dc7:	50                   	push   eax
  4c8dc8:	e8 a3 db 2d 00       	call   0x7a6970
  4c8dcd:	5f                   	pop    edi
  4c8dce:	5d                   	pop    ebp
  4c8dcf:	c2 08 00             	ret    0x8
```


### subclass +44 position writer — VA `0x4cab80..0x4cabd7`, raw `0xc9f80..0xc9fd7`

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004cab80 <.text+0xc9b80>:
  4cab80:	55                   	push   ebp
  4cab81:	8b ec                	mov    ebp,esp
  4cab83:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  4cab86:	d9 81 a0 00 00 00    	fld    DWORD PTR [ecx+0xa0]
  4cab8c:	d9 02                	fld    DWORD PTR [edx]
  4cab8e:	df e9                	fucomip st,st(1)
  4cab90:	dd d8                	fstp   st(0)
  4cab92:	9f                   	lahf
  4cab93:	f6 c4 44             	test   ah,0x44
  4cab96:	7a 13                	jp     0x4cabab
  4cab98:	d9 81 a4 00 00 00    	fld    DWORD PTR [ecx+0xa4]
  4cab9e:	d9 42 04             	fld    DWORD PTR [edx+0x4]
  4caba1:	df e9                	fucomip st,st(1)
  4caba3:	dd d8                	fstp   st(0)
  4caba5:	9f                   	lahf
  4caba6:	f6 c4 44             	test   ah,0x44
  4caba9:	7b 28                	jnp    0x4cabd3
  4cabab:	83 7d 0c 00          	cmp    DWORD PTR [ebp+0xc],0x0
  4cabaf:	8b 02                	mov    eax,DWORD PTR [edx]
  4cabb1:	89 81 a0 00 00 00    	mov    DWORD PTR [ecx+0xa0],eax
  4cabb7:	8b 52 04             	mov    edx,DWORD PTR [edx+0x4]
  4cabba:	89 91 a4 00 00 00    	mov    DWORD PTR [ecx+0xa4],edx
  4cabc0:	74 11                	je     0x4cabd3
  4cabc2:	8b 01                	mov    eax,DWORD PTR [ecx]
  4cabc4:	8b 50 38             	mov    edx,DWORD PTR [eax+0x38]
  4cabc7:	c7 81 ac 00 00 00 01 	mov    DWORD PTR [ecx+0xac],0x1
  4cabce:	00 00 00 
  4cabd1:	ff d2                	call   edx
  4cabd3:	5d                   	pop    ebp
  4cabd4:	c2 08 00             	ret    0x8
```


### outlier vtable+68 — VA `0x4cc0d0..0x4cc150`, raw `0xcb4d0..0xcb550`

```asm
/mnt/data/Tartaros.bin:     file format pei-i386


Disassembly of section .text:

004cc0d0 <.text+0xcb0d0>:
  4cc0d0:	55                   	push   ebp
  4cc0d1:	8b ec                	mov    ebp,esp
  4cc0d3:	6a ff                	push   0xffffffff
  4cc0d5:	68 38 d9 90 00       	push   0x90d938
  4cc0da:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  4cc0e0:	50                   	push   eax
  4cc0e1:	51                   	push   ecx
  4cc0e2:	56                   	push   esi
  4cc0e3:	57                   	push   edi
  4cc0e4:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  4cc0e9:	33 c5                	xor    eax,ebp
  4cc0eb:	50                   	push   eax
  4cc0ec:	8d 45 f4             	lea    eax,[ebp-0xc]
  4cc0ef:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  4cc0f5:	8b f1                	mov    esi,ecx
  4cc0f7:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  4cc0fa:	c7 06 14 77 c0 00    	mov    DWORD PTR [esi],0xc07714
  4cc100:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  4cc107:	8b be f0 00 00 00    	mov    edi,DWORD PTR [esi+0xf0]
  4cc10d:	85 ff                	test   edi,edi
  4cc10f:	74 0f                	je     0x4cc120
  4cc111:	e8 9a bc ff ff       	call   0x4c7db0
  4cc116:	c7 86 f0 00 00 00 00 	mov    DWORD PTR [esi+0xf0],0x0
  4cc11d:	00 00 00 
  4cc120:	f6 45 08 01          	test   BYTE PTR [ebp+0x8],0x1
  4cc124:	c7 06 ac 76 c0 00    	mov    DWORD PTR [esi],0xc076ac
  4cc12a:	74 09                	je     0x4cc135
  4cc12c:	56                   	push   esi
  4cc12d:	e8 da 50 3c 00       	call   0x89120c
  4cc132:	83 c4 04             	add    esp,0x4
  4cc135:	8b c6                	mov    eax,esi
  4cc137:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  4cc13a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  4cc141:	59                   	pop    ecx
  4cc142:	5f                   	pop    edi
  4cc143:	5e                   	pop    esi
  4cc144:	8b e5                	mov    esp,ebp
  4cc146:	5d                   	pop    ebp
  4cc147:	c2 04 00             	ret    0x4
  4cc14a:	cc                   	int3
  4cc14b:	cc                   	int3
  4cc14c:	cc                   	int3
  4cc14d:	cc                   	int3
  4cc14e:	cc                   	int3
  4cc14f:	cc                   	int3
```