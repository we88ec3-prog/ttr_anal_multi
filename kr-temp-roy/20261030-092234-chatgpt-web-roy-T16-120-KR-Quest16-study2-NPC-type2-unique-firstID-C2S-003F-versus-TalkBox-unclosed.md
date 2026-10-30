# T16-120 — Quest16／②：NPC10027 type2 唯一候選、控制器 C→S 0x3F／場景分支及 TalkBox 缺口的擴大 BIN-first 驗證（KR）

- 作業者：`chatgpt-web roy`；生成時間：`2026-10-30T09:22:34+08:00`。
- 承接 GitHub T16-119 `dd8a23195ee3f6b94f10d4485ca15cbe1e485892`；正式段號 T16-120。此段以已完成 119 所列的缺口為研究對象；**Quest16-② 尚未靜態達標，本篇為完整階段原稿，不將部分突破冒稱完成**。
- 唯讀原始 KR BIN：12,472,320B，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；Client `.text` ImageBase=0x400000，VA 0x401000 對 raw 0x400，故全部下文 code raw=`VA−0x400C00`。來源精確限定本份 BIN；不執行、不 patch、不上傳原 binary。
- 此對話已於首次開工完成 `main→t16/roy/chatgpt-web` PR#26；同對話絕不再主動 Merge。既有 T16-118/119 兩份完整 Markdown 已於上輪上傳並由 GitHub 讀回檢驗。本次沒有修改其他 Task 或 S00/RR/T01 狀態。
- 研究目標（不可擅自縮小）：NPC10027 玩家觸發後，type2 候選的 QID16 如何真正進入 `0x105B9→QuestInfo TalkBox`，以及它與控制器、實際 Client 發包的關聯。原版 Server 任務判定與實測玩家按下情形分開，不作為靜態閉合必要條件。

## 1. 核心成果與一個必要反證

### A. `giver=10027` 之 type2 可接候選可限定為 Quest16，而非只有「首個可能是16」

先前 T16-112 已針對原版 Table QuestInfo 逐項列舉 NPC10027 相關 Quest ID 八筆：`14(type3),16(type2),1002(type3),2742..2746(type3)`。T16-118/119 已驗 `record+0x20=town`、`record+0x28=giver`、`record+4=type`。所以在**前段 XML 群真的完整、同一資源版本已載入、Quest16 的 Demand14／level／town／20-slot exclusion 全部通過、對應 QuestOwner 候選 vector 不含其他非法鍵**的前提下：

```
0x105BD action6A7 -> payload 0x105BF, event+0x14=10027
 -> 0x5B9407 (owner=0xFAB2A0, giver=10027)
 -> 0x5008B0 -> 0x500A00
 -> QuestInfo g=10027 + type2 唯一 record: QID16
 -> return WORD=16
 -> 0x5B943F push 1; push 16; 0x5B9447 call 0x561760
```

**這個唯一性比 T16-119 中「可能有多個同 NPC type2」更強；但它只是上面列舉的 XML 版本與 gate 的靜態推論**。本段未重新由 Table.stp 完整解析 QuestInfo 全文、未做原版動態 NPC 觸發。若 candidate16 不存在，則 `0x5008B0` 回 0，不能反向宣稱必然點擊 NPC 即 QID16。

### B. 重要新增：`0x561760` 下游有 C→S app `0x003F`，**不是** TalkBox event `0x105B9` 或已證 QID16 接取

`0x4A39A0` 在 [0xFBA798]==0 時將 8-byte 本地 app payload 交給 `[0xFBA854]` vtable+0x10：

```
WORD0 = 0x003F
WORD1 = (u16) arg1
WORD2 = (u16) arg2
WORD3 = 0x0001
```

因此若確實從 `0x5B9447` QID16 進入 `0x561760(16,1)`、先前 controller 不 busy、在 `+0x89==0` 的 deferred branch 且其它 `0x561F7E..` 邏輯 gate 允許，`0x561FB0` 或 `0x561FE0` 可形成 `3F 00 10 00 01 00 01 00`。這是**條件式 C→S 構造**，不能升級成原版 Server 必然接受 Quest16，也不能當作裸 TCP wire 已送達；network framing 仍由 T02 主責。

**必要反例**：`0x5618C8` 在 controller 的 mode `0x19` 特殊分支呼叫 `0x4A39A0` 時，`0x5618C2 push [ebp+0x0C]; 0x5618C6 push 0`，可構造的是 **`3F 00 00 00 01 00 01 00`**（當 arg2=1），而不是 QID16！它也不能當作 Q16 C→S 的證據。`0x5617C2` 若 controller+0x28 非 0，會走已在途 early exit；`0x5617C6` 清 `controller+0x89`，但後續 `0x565720` 又可設為 1，故 deferred downstream 必須分 gate 說明。

### C. 另一個互斥路徑：`controller+0x89 != 0` 且 `+0x28 !=0` 會走場景 key，而非 `0x3F` 或 TalkBox

在 `0x561DB0`：`0x561DE0 cmp byte [controller+0x89],0`，若非零，接著檢查 `+0x28`；`0x561ED1` 將 `controller+0x38/+0x3C` 當兩參數交給 `0x47E640`，僅後者結果非零，`0x561EF3 call 0x565720`；`0x565720` 有 `+0x89=1` 與二鍵 map 查找。這與 T16-108 SceneList `(questIdx,sceneIdx)` 有界路徑相符，但原 SceneList 無 `(16,*)`，**不能**因此宣稱 Q16 TalkBox 必然被執行；也不能把此分支誤稱為 QID16 的 `0x3F` 出口。

### D. `0x105BA→0x105B9` producer 不是普遍可用的 QID16 橋接，新增具體反例

`0x5B9B10` 轉換型別時確實用 `source[+0x18]` 寫入新事件 `+0x14`。但是已證 actor branch `0x54422D..0x54428D` 在構建 `vptr=0xC47BCC` (105BA) 時**明確把 source+0x18 清為 0**，且把 `+0x14` 寫入局部 EDI。故**至少這一條**接到 `0x5B9B10`，只能產生 `0x105B9(event+0x14=0)`，不能拼成 `QID16`。其他 105BA producers 可能使用不同 +0x18 值，但需具體物件別名與事件派發路徑再驗。

`0x5442CC` 的 0x105BF event 則保存 actor/control+F4/F6 在 +18/+1C；`0x5B9850` 將其 source+14（NPC/context selector）原樣複製到新 105B9+14。若該值為 NPC10027，對 `0x5B6C0C` 的 QuestInfo ID exact map lookup 就是 ID10027，**不會無條件轉成 ID16**。

### E. `0x105BE` 還有不同 TalkBox mode0 入口，不能拿它冒充 QID16 mode1

`0x5B6B70` 針對 0x105BE，從 event+14/+18 送入 `0x636520` 的 mode0，接著 `0x635CA0` 是 T16-117 已指出 type1 的路徑；Quest16 type2 不在 type1 專屬列表。所以 **NPC 對話可以有多條模式**，不可只從一個 TalkBox 入口存在就宣稱 Quest16 type2 項目在 UI 可見。

`0x5B6C0C` 的 mode1 則要求 `0x105B9(+14=真正 QuestInfo key)` 命中 `0x503D20`，QID16 命中才傳入 `0x636520(mode1)`，在玩家確認和 sender gate 成立時可接 T16-114 的 `0x36,ID16`。前述 `0x561760` 整條 control+0x38/+0x3C 分支**未證到任何一個把 QID16 寫入 105B9+14 的 direct writer**，所以仍不能閉合 NPC10027→Quest16 TalkBox。

## 2. 客戶端玩家情境矩陣

| 玩家／事件情境 | 必要本地 gate | C→S app | S→C | 本地效果 | 證據分級 |
|---|---|---|---|---|---|
| NPC selector10027 的 type2 候選檢索 | owner 有 key14；town0、level、20-slot exclusion；同版 XML | 此 lookup 不發包 | key14 歷史 S2C `74 00 0E 00` 可影響 candidate | 若 Q16 是可接候選：type2/giver 唯一 QID16 | 原生限定 + XML 全集關聯 |
| 0x105BD(action6A7) 包含 0x105BF+14=10027 | 非空正確型別 | 獨立 `1C 00 <event+18 WORD> <event+1C WORD>`（gate成立） | 尚未唯一配對 | 把 first type2 QID16 交到控制器(16,1) | 原生有界 |
| 控制器(16,1) defer，+89=0 | nonbusy，後續操作 gate 成立 | **條件式 `3F 00 10 00 01 00 01 00`** | 0x3F 回應未配對 | local stage/controller state，非已證 TalkBox | 新原生有界 |
| 控制器 mode0x19 特殊分支 | 特定 mode/state | `3F 00 00 00 01 00 01 00`（arg2=1） | 未知 | 第二位置參數，**不帶 QID16** | 新反證 |
| 控制器+89≠0 | +28非零、`0x47E640` 返回非零 | 此分支未證 0x3F | 未知 | `0x565720` 場景鍵相關 | 原生有界 |
| NPC 105BA→105B9 | 0x544245 actor branch，source+18清0 | 不在 producer 立即發包 | 無 | event+14=0，不是 QID16 | 新反證 |
| NPC 105BF→105B9 | source+14 為 NPC10027 | producer 不直接發包 | 無 | QID map lookup 仍為10027，不會替換16 | 舊證據＋反證 |
| true 105B9(+14=16) 進入 TalkBox | 必須有**另一個** QID16 event producer，QuestInfo map hit | 玩家另確認時 `36 00 10 00` | 無唯一 ACK | `0x636520(mode1)` | 條件式已證；上游未閉合 |
| 原版成功/拒絕/獎勵 | 需要 Server 狀態決策 | 未唯一配對 | 未唯一配對 | UI結果未知 | ④＋Server 待開發 |

## 3. Quest16 ①～⑤ 與四種後續責任

| 子研究 | 本段後狀態 |
|---|---|
| ①資源／前置 | **已完成有界**（T16-118，T16-119 的 giver selector） |
| **②玩家觸發** | **仍未完成**：已新增唯一 QID16 候選、條件式 0x003F 以及 105BA 反證；尚缺 NPC10027→105B9 QID16／TalkBox 同鍵、同物件 native bridge，不可冒稱結案 |
| ③C→S | 0x36(QID16)、0x1C(NPC事件)、新 0x3F(控制器) 為**三種不同 app producer**；mode／實際到達與業務語意待正式研究 |
| ④S→C／狀態/UI | 0x40/0x74 既有局部，不得發明 0x36/0x3F ACK；accepted/rejected/reward UI 未唯一配對 |
| ⑤Q16→Q15 | 靜態 Demand16 已知；NPC10338、城鎮/場景/wire 未完成 |

- **Client 待逆向**：`0x6391C0/0x639210` 的 `[context+4]+0x84` 究竟何時為 QuestID16；`0x636520` `[TalkBox+0x84]` 寫的是 NPC giver，不能用同 offset 保證 UI widget 同一個 object；`0x561760` +0x89 producer 與 deferred update 時序；還有哪個 UI item/callback 能產生 105B9(+14=16)。
- **Server 待開發**：Q16 合法接取與完成判定、回報/拒絕、獎勵50（類型2不解釋）、重連持久化、何時發 prerequisite key14/key16；由 S00 產生 DRAFT SPEC/GAP/ADR/TEST，不是本段自建原版規則。
- **跨 Task 待整合**：T02 `0x3F/0x1C/0x36` framing/routing 與入站 index；T06 UI widget；T07 SceneList/scene flow；T03/T04 session；T08 NPC actor；T14 教學關卡；T15 持久化；保留 owner。
- **待遊玩驗證**：NPC10027 是否實例且可互動、`actor+F6` runtime value、UI 控制器各 gate、真正 WSASend/Server ACK、Quest16 任務可玩、Quest15 解鎖均無原版動態資料。

## 4. 仍可靜態推進、不能假裝已達標的精確下一入口

1. `0x6386F2` 註冊 `0x6391C0/+0xE0` 及 `0x639210/+0xE4` 等 widget callbacks；追其物件建構者、`context+4` 指向的 UI widget 真正建立與 `+0x84` writer，再與 `0x636520` 儲存 giver10027 和 `0x6389E0` UI list rebuild 做**同一物件 alias 驗證**。不能靠相同 offset 下結論。
2. 全部與 Quest16 sender 同路的 `0x105BA` source+0x18 非零 writers，需要對 `0x5B9B10` 的派發路徑建 caller/selector table；本篇已以 `0x54422D` 排除一條常被誤拼接的全零來源。
3. `0x561760` 的 C→S `0x3F` 三個已證 callsites (`0x5618C8`、`0x561FB0`、`0x561FE0`) 與 `0x565720` 的 scene branch 應交叉 T02/T07 釐清是否同一玩家情境，**不可在②先發明回覆或直接叫它 quest accept**。
4. 如果特定 NPC 的 QuestID16 widget producer 只在遊戲載入後由資料動態建立，要求本地合法 trace：捕捉 105BD/105BF +14/+18/+1C、UI QID、105B9 +14、`0x561760`+38/+3C、`0x636520`+84/+88，並比對 trigger action 與 app queue；沒有動態證據前仍盡可能完成上述原生靜態補證。

## 5. 第一手 BIN 對齊 assembly、VA/raw、切片 hash

以下皆由本次同一 `/mnt/data/Tartaros.bin` 唯讀擷取，`objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00` 的獨立切片。單純線性反組譯跨跳表/函式邊界可能產生無效指令；肯定主張只用已對齊的完整指令與 caller 跳轉，切片起頭若落在前一條指令中途不能作證據。每段原始 byte SHA256 可與 PE `.text` raw 對應反查。對 T01 的正式 FULL-PASS 或整個 Quest16 可玩**一律不宣稱**。

### S01 — Native C2S 0x003F payload builder and suppression gate: VA `0x004a39a0..0x004a39ec` / raw `0xa2da0..0xa2dec` / 76 B / SHA256 `dbb0c12cfc16ef6738deb33fda9cb2b410be3aae67e89a6df6b71e7fd1711976`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

004a39a0 <.data+0xa2da0>:
  4a39a0:	55                   	push   ebp
  4a39a1:	8b ec                	mov    ebp,esp
  4a39a3:	83 ec 08             	sub    esp,0x8
  4a39a6:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  4a39ad:	66 8b 4d 08          	mov    cx,WORD PTR [ebp+0x8]
  4a39b1:	66 8b 55 0c          	mov    dx,WORD PTR [ebp+0xc]
  4a39b5:	b8 3f 00 00 00       	mov    eax,0x3f
  4a39ba:	66 89 45 f8          	mov    WORD PTR [ebp-0x8],ax
  4a39be:	b8 01 00 00 00       	mov    eax,0x1
  4a39c3:	66 89 4d fa          	mov    WORD PTR [ebp-0x6],cx
  4a39c7:	66 89 55 fc          	mov    WORD PTR [ebp-0x4],dx
  4a39cb:	66 89 45 fe          	mov    WORD PTR [ebp-0x2],ax
  4a39cf:	75 15                	jne    0x4a39e6
  4a39d1:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  4a39d7:	8b 11                	mov    edx,DWORD PTR [ecx]
  4a39d9:	8b 52 10             	mov    edx,DWORD PTR [edx+0x10]
  4a39dc:	6a 08                	push   0x8
  4a39de:	8d 45 f8             	lea    eax,[ebp-0x8]
  4a39e1:	50                   	push   eax
  4a39e2:	6a 00                	push   0x0
  4a39e4:	ff d2                	call   edx
  4a39e6:	8b e5                	mov    esp,ebp
  4a39e8:	5d                   	pop    ebp
  4a39e9:	c2 08 00             	ret    0x8
```

### S02 — Native NPC 0x105BD/action6A7 + 0x105BF first-ID and independent 0x001C request: VA `0x005b9370..0x005b9498` / raw `0x1b8770..0x1b8898` / 296 B / SHA256 `f7accb05aa7ab30e68a10a850dfa2f9ef67493911ee2d95afe154104d5f871be`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b9370 <.data+0x1b8770>:
  5b9370:	f6 74 22 8b          	div    BYTE PTR [edx+eiz*1-0x75]
  5b9374:	06                   	push   es
  5b9375:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b9378:	ff d2                	call   edx
  5b937a:	3d bd 05 01 00       	cmp    eax,0x105bd
  5b937f:	75 04                	jne    0x5b9385
  5b9381:	8b c6                	mov    eax,esi
  5b9383:	eb 12                	jmp    0x5b9397
  5b9385:	6a 00                	push   0x0
  5b9387:	68 c0 1f bf 00       	push   0xbf1fc0
  5b938c:	68 18 21 bf 00       	push   0xbf2118
  5b9391:	6a 00                	push   0x0
  5b9393:	ff d7                	call   edi
  5b9395:	33 c0                	xor    eax,eax
  5b9397:	8b 48 14             	mov    ecx,DWORD PTR [eax+0x14]
  5b939a:	81 f9 a7 06 00 00    	cmp    ecx,0x6a7
  5b93a0:	0f 85 f2 00 00 00    	jne    0x5b9498
  5b93a6:	8b 70 18             	mov    esi,DWORD PTR [eax+0x18]
  5b93a9:	85 f6                	test   esi,esi
  5b93ab:	74 20                	je     0x5b93cd
  5b93ad:	8b 06                	mov    eax,DWORD PTR [esi]
  5b93af:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b93b2:	8b ce                	mov    ecx,esi
  5b93b4:	ff d2                	call   edx
  5b93b6:	3d bf 05 01 00       	cmp    eax,0x105bf
  5b93bb:	74 12                	je     0x5b93cf
  5b93bd:	6a 00                	push   0x0
  5b93bf:	68 c0 1f bf 00       	push   0xbf1fc0
  5b93c4:	68 18 21 bf 00       	push   0xbf2118
  5b93c9:	6a 00                	push   0x0
  5b93cb:	ff d7                	call   edi
  5b93cd:	33 f6                	xor    esi,esi
  5b93cf:	f6 05 9c b2 fa 00 01 	test   BYTE PTR ds:0xfab29c,0x1
  5b93d6:	75 27                	jne    0x5b93ff
  5b93d8:	83 0d 9c b2 fa 00 01 	or     DWORD PTR ds:0xfab29c,0x1
  5b93df:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  5b93e6:	e8 75 6a f4 ff       	call   0x4ffe60
  5b93eb:	68 00 cf bc 00       	push   0xbccf00
  5b93f0:	e8 25 8f 2d 00       	call   0x89231a
  5b93f5:	83 c4 04             	add    esp,0x4
  5b93f8:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  5b93ff:	8b 4e 14             	mov    ecx,DWORD PTR [esi+0x14]
  5b9402:	ba a0 b2 fa 00       	mov    edx,0xfab2a0
  5b9407:	e8 a4 74 f4 ff       	call   0x5008b0
  5b940c:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  5b9413:	0f b7 f8             	movzx  edi,ax
  5b9416:	75 27                	jne    0x5b943f
  5b9418:	b8 01 00 00 00       	mov    eax,0x1
  5b941d:	09 05 b8 73 fb 00    	or     DWORD PTR ds:0xfb73b8,eax
  5b9423:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  5b9426:	e8 45 6d fa ff       	call   0x560170
  5b942b:	68 10 d1 bc 00       	push   0xbcd110
  5b9430:	e8 e5 8e 2d 00       	call   0x89231a
  5b9435:	83 c4 04             	add    esp,0x4
  5b9438:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  5b943f:	6a 01                	push   0x1
  5b9441:	57                   	push   edi
  5b9442:	b9 c0 73 fb 00       	mov    ecx,0xfb73c0
  5b9447:	e8 14 83 fa ff       	call   0x561760
  5b944c:	83 3d 98 a7 fb 00 00 	cmp    DWORD PTR ds:0xfba798,0x0
  5b9453:	b8 1c 00 00 00       	mov    eax,0x1c
  5b9458:	66 89 45 e8          	mov    WORD PTR [ebp-0x18],ax
  5b945c:	66 8b 4e 18          	mov    cx,WORD PTR [esi+0x18]
  5b9460:	66 89 4d ea          	mov    WORD PTR [ebp-0x16],cx
  5b9464:	66 8b 56 1c          	mov    dx,WORD PTR [esi+0x1c]
  5b9468:	66 89 55 ec          	mov    WORD PTR [ebp-0x14],dx
  5b946c:	0f 85 e1 00 00 00    	jne    0x5b9553
  5b9472:	8b 0d 54 a8 fb 00    	mov    ecx,DWORD PTR ds:0xfba854
  5b9478:	8b 01                	mov    eax,DWORD PTR [ecx]
  5b947a:	8b 40 10             	mov    eax,DWORD PTR [eax+0x10]
  5b947d:	6a 06                	push   0x6
  5b947f:	8d 55 e8             	lea    edx,[ebp-0x18]
  5b9482:	52                   	push   edx
  5b9483:	6a 00                	push   0x0
  5b9485:	ff d0                	call   eax
  5b9487:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  5b948a:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5b9491:	59                   	pop    ecx
  5b9492:	5f                   	pop    edi
  5b9493:	5e                   	pop    esi
  5b9494:	8b e5                	mov    esp,ebp
  5b9496:	5d                   	pop    ebp
  5b9497:	c3                   	ret
```

### S03 — Controller initial busy/early-exit gating: VA `0x005617c2..0x00561801` / raw `0x160bc2..0x160c01` / 63 B / SHA256 `93971b1a89ab6cd4fa2af5674fe6c4906ef5dcb9b398f29fd8a5e7d356c28af9`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005617c2 <.data+0x160bc2>:
  5617c2:	83 7b 28 00          	cmp    DWORD PTR [ebx+0x28],0x0
  5617c6:	c6 83 89 00 00 00 00 	mov    BYTE PTR [ebx+0x89],0x0
  5617cd:	74 1a                	je     0x5617e9
  5617cf:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  5617d2:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  5617d5:	50                   	push   eax
  5617d6:	51                   	push   ecx
  5617d7:	68 ac 06 c1 00       	push   0xc106ac
  5617dc:	e8 7f c3 18 00       	call   0x6edb60
  5617e1:	83 c4 0c             	add    esp,0xc
  5617e4:	e9 9d 05 00 00       	jmp    0x561d86
  5617e9:	f6 05 28 88 fb 00 01 	test   BYTE PTR ds:0xfb8828,0x1
  5617f0:	be 01 00 00 00       	mov    esi,0x1
  5617f5:	75 29                	jne    0x561820
  5617f7:	09 35 28 88 fb 00    	or     DWORD PTR ds:0xfb8828,esi
  5617fd:	c7 44 24 68    	mov    DWORD PTR [esp+0x68],0x0
  561804:
```

### S04 — Controller mode0x19 alternate request versus stored key: VA `0x00561830..0x00561904` / raw `0x160c30..0x160d04` / 212 B / SHA256 `56226456b38737d4657605edb0e453e460e93b5cc82d5c8719bf17e4ee2a9816`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00561830 <.data+0x160c30>:
  561830:	83 7d 08 00          	cmp    DWORD PTR [ebp+0x8],0x0
  561834:	0f 85 a2 00 00 00    	jne    0x5618dc
  56183a:	e8 61 33 ea ff       	call   0x404ba0
  56183f:	83 b8 4c 5f 00 00 09 	cmp    DWORD PTR [eax+0x5f4c],0x9
  561846:	74 1c                	je     0x561864
  561848:	e8 53 33 ea ff       	call   0x404ba0
  56184d:	83 b8 4c 5f 00 00 04 	cmp    DWORD PTR [eax+0x5f4c],0x4
  561854:	74 0e                	je     0x561864
  561856:	e8 45 33 ea ff       	call   0x404ba0
  56185b:	83 b8 4c 5f 00 00 19 	cmp    DWORD PTR [eax+0x5f4c],0x19
  561862:	75 78                	jne    0x5618dc
  561864:	8b 73 78             	mov    esi,DWORD PTR [ebx+0x78]
  561867:	8d 55 0c             	lea    edx,[ebp+0xc]
  56186a:	52                   	push   edx
  56186b:	8d 4b 74             	lea    ecx,[ebx+0x74]
  56186e:	8d 44 24 14          	lea    eax,[esp+0x14]
  561872:	e8 49 4c ed ff       	call   0x4364c0
  561877:	39 30                	cmp    DWORD PTR [eax],esi
  561879:	74 5c                	je     0x5618d7
  56187b:	6a 0f                	push   0xf
  56187d:	e8 2e 3d 02 00       	call   0x5855b0
  561882:	8b f0                	mov    esi,eax
  561884:	e8 a7 3a 02 00       	call   0x585330
  561889:	50                   	push   eax
  56188a:	8d 4c 24 40          	lea    ecx,[esp+0x40]
  56188e:	e8 bd 09 ea ff       	call   0x402250
  561893:	8d 44 24 3c          	lea    eax,[esp+0x3c]
  561897:	50                   	push   eax
  561898:	c7 44 24 6c 01 00 00 	mov    DWORD PTR [esp+0x6c],0x1
  56189f:	00 
  5618a0:	e8 1b e0 ea ff       	call   0x40f8c0
  5618a5:	8b f8                	mov    edi,eax
  5618a7:	e8 84 52 f7 ff       	call   0x4d6b30
  5618ac:	8d 4c 24 3c          	lea    ecx,[esp+0x3c]
  5618b0:	c7 44 24 68 ff ff ff 	mov    DWORD PTR [esp+0x68],0xffffffff
  5618b7:	ff 
  5618b8:	e8 83 8b f9 ff       	call   0x4fa440
  5618bd:	e8 be 2d eb ff       	call   0x414680
  5618c2:	8b 4d 0c             	mov    ecx,DWORD PTR [ebp+0xc]
  5618c5:	51                   	push   ecx
  5618c6:	6a 00                	push   0x0
  5618c8:	e8 d3 20 f4 ff       	call   0x4a39a0
  5618cd:	e8 de 07 00 00       	call   0x5620b0
  5618d2:	e9 af 04 00 00       	jmp    0x561d86
  5618d7:	be 01 00 00 00       	mov    esi,0x1
  5618dc:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  5618e3:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  5618e6:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  5618e9:	89 53 38             	mov    DWORD PTR [ebx+0x38],edx
  5618ec:	89 43 3c             	mov    DWORD PTR [ebx+0x3c],eax
  5618ef:	89 73 28             	mov    DWORD PTR [ebx+0x28],esi
  5618f2:	75 24                	jne    0x561918
  5618f4:	09 35 d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,esi
  5618fa:	c7 44 24 68 02 00 00 	mov    DWORD PTR [esp+0x68],0x2
  561901:	00 
  561902:	e8 79          	call   0x587480
```

### S05 — Deferred controller +0x89 versus +0x28 control branch: VA `0x00561ddc..0x00561e06` / raw `0x1611dc..0x161206` / 42 B / SHA256 `929a7c2d74fd91c4ac95062605bdfbcf85ab985565febddae51634fd8925518f`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00561ddc <.data+0x1611dc>:
  561ddc:	8b f9                	mov    edi,ecx
  561dde:	33 f6                	xor    esi,esi
  561de0:	80 bf 89 00 00 00 00 	cmp    BYTE PTR [edi+0x89],0x0
  561de7:	0f 84 73 01 00 00    	je     0x561f60
  561ded:	39 77 28             	cmp    DWORD PTR [edi+0x28],esi
  561df0:	0f 84 aa 00 00 00    	je     0x561ea0
  561df6:	89 77 28             	mov    DWORD PTR [edi+0x28],esi
  561df9:	e8 52 24 ed ff       	call   0x434250
  561dfe:	bb 01 00 00 00       	mov    ebx,0x1
  561e03:	89 58 14             	mov    DWORD PTR [eax+0x14],ebx
```

### S06 — Controller scene-key transfer to 0x565720: VA `0x00561ed1..0x00561f0b` / raw `0x1612d1..0x16130b` / 58 B / SHA256 `9c3730eb69f44b32f778ce4a8f4aba5fe9eb59bf29778cdd9b979b5b31b383eb`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00561ed1 <.data+0x1612d1>:
  561ed1:	8b 47 3c             	mov    eax,DWORD PTR [edi+0x3c]
  561ed4:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  561ed7:	50                   	push   eax
  561ed8:	51                   	push   ecx
  561ed9:	68 68 0f fc 00       	push   0xfc0f68
  561ede:	e8 5d c7 f1 ff       	call   0x47e640
  561ee3:	33 db                	xor    ebx,ebx
  561ee5:	89 47 3c             	mov    DWORD PTR [edi+0x3c],eax
  561ee8:	3b c3                	cmp    eax,ebx
  561eea:	74 1f                	je     0x561f0b
  561eec:	8b 57 38             	mov    edx,DWORD PTR [edi+0x38]
  561eef:	50                   	push   eax
  561ef0:	52                   	push   edx
  561ef1:	8b f7                	mov    esi,edi
  561ef3:	e8 28 38 00 00       	call   0x565720
  561ef8:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  561efc:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  561f03:	59                   	pop    ecx
  561f04:	5f                   	pop    edi
  561f05:	5e                   	pop    esi
  561f06:	5b                   	pop    ebx
  561f07:	8b e5                	mov    esp,ebp
  561f09:	5d                   	pop    ebp
  561f0a:	c3                   	ret
```

### S07 — Controller +0x89=0 and conditional 0x003F call sites: VA `0x00561f60..0x00562000` / raw `0x161360..0x161400` / 160 B / SHA256 `cf39e82bacde2d2bfa14103dc440dda8fb551d2a01066cfe8ba04389c47b6a3c`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00561f60 <.data+0x161360>:
  561f60:	39 77 28             	cmp    DWORD PTR [edi+0x28],esi
  561f63:	0f 84 28 01 00 00    	je     0x562091
  561f69:	89 77 28             	mov    DWORD PTR [edi+0x28],esi
  561f6c:	e8 df 22 ed ff       	call   0x434250
  561f71:	bb 01 00 00 00       	mov    ebx,0x1
  561f76:	89 58 14             	mov    DWORD PTR [eax+0x14],ebx
  561f79:	39 77 38             	cmp    DWORD PTR [edi+0x38],esi
  561f7c:	74 39                	je     0x561fb7
  561f7e:	68 44 03 c1 00       	push   0xc10344
  561f83:	53                   	push   ebx
  561f84:	e8 a7 92 f3 ff       	call   0x49b230
  561f89:	50                   	push   eax
  561f8a:	e8 11 b1 f4 ff       	call   0x4ad0a0
  561f8f:	6a ff                	push   0xffffffff
  561f91:	51                   	push   ecx
  561f92:	e8 99 92 f3 ff       	call   0x49b230
  561f97:	83 c4 04             	add    esp,0x4
  561f9a:	e8 b1 0b f4 ff       	call   0x4a2b50
  561f9f:	3b c3                	cmp    eax,ebx
  561fa1:	75 4e                	jne    0x561ff1
  561fa3:	e8 d8 26 eb ff       	call   0x414680
  561fa8:	8b 4f 3c             	mov    ecx,DWORD PTR [edi+0x3c]
  561fab:	8b 57 38             	mov    edx,DWORD PTR [edi+0x38]
  561fae:	51                   	push   ecx
  561faf:	52                   	push   edx
  561fb0:	e8 eb 19 f4 ff       	call   0x4a39a0
  561fb5:	eb 3a                	jmp    0x561ff1
  561fb7:	8d 5f 3c             	lea    ebx,[edi+0x3c]
  561fba:	8d 77 74             	lea    esi,[edi+0x74]
  561fbd:	53                   	push   ebx
  561fbe:	e8 7d be 15 00       	call   0x6bde40
  561fc3:	50                   	push   eax
  561fc4:	56                   	push   esi
  561fc5:	8d 74 24 1c          	lea    esi,[esp+0x1c]
  561fc9:	e8 c2 48 ed ff       	call   0x436890
  561fce:	57                   	push   edi
  561fcf:	e8 cc 03 00 00       	call   0x5623a0
  561fd4:	e8 a7 26 eb ff       	call   0x414680
  561fd9:	8b 03                	mov    eax,DWORD PTR [ebx]
  561fdb:	8b 4f 38             	mov    ecx,DWORD PTR [edi+0x38]
  561fde:	50                   	push   eax
  561fdf:	51                   	push   ecx
  561fe0:	e8 bb 19 f4 ff       	call   0x4a39a0
  561fe5:	e8 c6 00 00 00       	call   0x5620b0
  561fea:	bb 01 00 00 00       	mov    ebx,0x1
  561fef:	33 f6                	xor    esi,esi
  561ff1:	f6 05 d4 f3 fd 00 01 	test   BYTE PTR ds:0xfdf3d4,0x1
  561ff8:	75 28                	jne    0x562022
  561ffa:	09 1d d4 f3 fd 00    	or     DWORD PTR ds:0xfdf3d4,ebx
```

### S08 — 0x105BA actor branch initializes source+0x18 to zero: VA `0x0054422d..0x0054428d` / raw `0x14362d..0x14368d` / 96 B / SHA256 `551063e79ac7e0769f8eecf88abc41c78803f2fe4a5025d15826def70f474ab9`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

0054422d <.data+0x14362d>:
  54422d:	e8 8e 12 ec ff       	call   0x4054c0
  544232:	6a 1c                	push   0x1c
  544234:	e8 2f d0 34 00       	call   0x891268
  544239:	33 f6                	xor    esi,esi
  54423b:	83 c4 04             	add    esp,0x4
  54423e:	83 cb ff             	or     ebx,0xffffffff
  544241:	3b c6                	cmp    eax,esi
  544243:	74 1e                	je     0x544263
  544245:	89 70 0c             	mov    DWORD PTR [eax+0xc],esi
  544248:	89 70 18             	mov    DWORD PTR [eax+0x18],esi
  54424b:	89 58 04             	mov    DWORD PTR [eax+0x4],ebx
  54424e:	89 58 08             	mov    DWORD PTR [eax+0x8],ebx
  544251:	c7 40 10 d6 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf43d6
  544258:	c7 00 cc 7b c4 00    	mov    DWORD PTR [eax],0xc47bcc
  54425e:	89 78 14             	mov    DWORD PTR [eax+0x14],edi
  544261:	8b f0                	mov    esi,eax
  544263:	e8 38 08 ec ff       	call   0x404aa0
  544268:	8b 80 c4 13 00 00    	mov    eax,DWORD PTR [eax+0x13c4]
  54426e:	50                   	push   eax
  54426f:	56                   	push   esi
  544270:	83 ec 1c             	sub    esp,0x1c
  544273:	8b cc                	mov    ecx,esp
  544275:	89 64 24 38          	mov    DWORD PTR [esp+0x38],esp
  544279:	68 fc d1 be 00       	push   0xbed1fc
  54427e:	e8 cd df eb ff       	call   0x402250
  544283:	6a 20                	push   0x20
  544285:	c7 44 24 50 02 00 00 	mov    DWORD PTR [esp+0x50],0x2
  54428c:	00
```

### S09 — 0x105BF actor event carries +0xF4/+0xF6 selectors: VA `0x005442cc..0x0054435f` / raw `0x1436cc..0x14375f` / 147 B / SHA256 `d20cf0521a8d90a09a972cd3ff0b8e3376df58b1e48e73b2a796b3249db29204`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005442cc <.data+0x1436cc>:
  5442cc:	53                   	push   ebx
  5442cd:	e8 1e 58 ff ff       	call   0x539af0
  5442d2:	e8 e9 11 ec ff       	call   0x4054c0
  5442d7:	6a 20                	push   0x20
  5442d9:	e8 8a cf 34 00       	call   0x891268
  5442de:	83 c4 04             	add    esp,0x4
  5442e1:	85 c0                	test   eax,eax
  5442e3:	74 3e                	je     0x544323
  5442e5:	0f b7 8e f6 00 00 00 	movzx  ecx,WORD PTR [esi+0xf6]
  5442ec:	0f b7 96 f4 00 00 00 	movzx  edx,WORD PTR [esi+0xf4]
  5442f3:	0f bf d2             	movsx  edx,dx
  5442f6:	0f bf c9             	movsx  ecx,cx
  5442f9:	83 cb ff             	or     ebx,0xffffffff
  5442fc:	89 58 04             	mov    DWORD PTR [eax+0x4],ebx
  5442ff:	89 58 08             	mov    DWORD PTR [eax+0x8],ebx
  544302:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  544309:	c7 40 10 d9 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf43d9
  544310:	c7 00 e4 7b c4 00    	mov    DWORD PTR [eax],0xc47be4
  544316:	89 78 14             	mov    DWORD PTR [eax+0x14],edi
  544319:	89 50 18             	mov    DWORD PTR [eax+0x18],edx
  54431c:	89 48 1c             	mov    DWORD PTR [eax+0x1c],ecx
  54431f:	8b f0                	mov    esi,eax
  544321:	eb 05                	jmp    0x544328
  544323:	33 f6                	xor    esi,esi
  544325:	83 cb ff             	or     ebx,0xffffffff
  544328:	e8 73 07 ec ff       	call   0x404aa0
  54432d:	8b 80 c4 13 00 00    	mov    eax,DWORD PTR [eax+0x13c4]
  544333:	50                   	push   eax
  544334:	56                   	push   esi
  544335:	83 ec 1c             	sub    esp,0x1c
  544338:	8b cc                	mov    ecx,esp
  54433a:	89 64 24 3c          	mov    DWORD PTR [esp+0x3c],esp
  54433e:	68 fc d1 be 00       	push   0xbed1fc
  544343:	e8 08 df eb ff       	call   0x402250
  544348:	c7 44 24 4c 03 00 00 	mov    DWORD PTR [esp+0x4c],0x3
  54434f:	00 
  544350:	c7 44 24 38 21 00 00 	mov    DWORD PTR [esp+0x38],0x21
  544357:	00 
  544358:	e8 53 11 04 00       	call   0x5854b0
  54435d:	8b f0                	mov    esi,eax
```

### S10 — 0x105BA to 0x105B9 event conversion reads +0x18: VA `0x005b9b9b..0x005b9bd0` / raw `0x1b8f9b..0x1b8fd0` / 53 B / SHA256 `9dae761199a976c6e6f274dce3f66e95e281177965740205cccdd0fa8f84d5f8`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b9b9b <.data+0x1b8f9b>:
  5b9b9b:	6a 18                	push   0x18
  5b9b9d:	e8 c6 76 2d 00       	call   0x891268
  5b9ba2:	83 c4 04             	add    esp,0x4
  5b9ba5:	3b c7                	cmp    eax,edi
  5b9ba7:	74 21                	je     0x5b9bca
  5b9ba9:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  5b9bac:	8b 49 18             	mov    ecx,DWORD PTR [ecx+0x18]
  5b9baf:	89 70 04             	mov    DWORD PTR [eax+0x4],esi
  5b9bb2:	89 70 08             	mov    DWORD PTR [eax+0x8],esi
  5b9bb5:	89 78 0c             	mov    DWORD PTR [eax+0xc],edi
  5b9bb8:	c7 40 10 e1 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf43e1
  5b9bbf:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  5b9bc5:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  5b9bc8:	eb 02                	jmp    0x5b9bcc
  5b9bca:	33 c0                	xor    eax,eax
  5b9bcc:	f6 05 e4 5a    	test   BYTE PTR ds:0xfe5ae4,0x1
```

### S11 — 0x105BF to 0x105B9 selector-preserving map gate: VA `0x005b9850..0x005b98d7` / raw `0x1b8c50..0x1b8cd7` / 135 B / SHA256 `7d09cb1cef187c1510f81ef51b4616301ee1b8eb80b503472d34ae0dadf04dfe`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b9850 <.data+0x1b8c50>:
  5b9850:	55                   	push   ebp
  5b9851:	8b ec                	mov    ebp,esp
  5b9853:	83 e4 f8             	and    esp,0xfffffff8
  5b9856:	6a ff                	push   0xffffffff
  5b9858:	68 70 36 93 00       	push   0x933670
  5b985d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  5b9863:	50                   	push   eax
  5b9864:	83 ec 20             	sub    esp,0x20
  5b9867:	53                   	push   ebx
  5b9868:	56                   	push   esi
  5b9869:	57                   	push   edi
  5b986a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  5b986f:	33 c4                	xor    eax,esp
  5b9871:	50                   	push   eax
  5b9872:	8d 44 24 30          	lea    eax,[esp+0x30]
  5b9876:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  5b987c:	8b f1                	mov    esi,ecx
  5b987e:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  5b9881:	33 ff                	xor    edi,edi
  5b9883:	3b f7                	cmp    esi,edi
  5b9885:	74 26                	je     0x5b98ad
  5b9887:	8b 06                	mov    eax,DWORD PTR [esi]
  5b9889:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b988c:	ff d2                	call   edx
  5b988e:	3d bf 05 01 00       	cmp    eax,0x105bf
  5b9893:	75 06                	jne    0x5b989b
  5b9895:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  5b9899:	eb 16                	jmp    0x5b98b1
  5b989b:	57                   	push   edi
  5b989c:	68 c0 1f bf 00       	push   0xbf1fc0
  5b98a1:	68 18 21 bf 00       	push   0xbf2118
  5b98a6:	57                   	push   edi
  5b98a7:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  5b98ad:	89 7c 24 14          	mov    DWORD PTR [esp+0x14],edi
  5b98b1:	8b 74 24 14          	mov    esi,DWORD PTR [esp+0x14]
  5b98b5:	83 c6 14             	add    esi,0x14
  5b98b8:	8d 8b e8 02 00 00    	lea    ecx,[ebx+0x2e8]
  5b98be:	56                   	push   esi
  5b98bf:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5b98c3:	89 4c 24 24          	mov    DWORD PTR [esp+0x24],ecx
  5b98c7:	e8 f4 9f 28 00       	call   0x8438c0
  5b98cc:	8b 83 ec 02 00 00    	mov    eax,DWORD PTR [ebx+0x2ec]
  5b98d2:	39 44 24 18          	cmp    DWORD PTR [esp+0x18],eax
  5b98d6:	0f         	jne    0x5b9af4
```

### S12 — Independent 0x105BE direct mode0 TalkBox initialization: VA `0x005b6b70..0x005b6bd2` / raw `0x1b5f70..0x1b5fd2` / 98 B / SHA256 `4557a28b516bbe1fddb579dceb18988bed0e59d2f47b4f667919b235529d4185`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b6b70 <.data+0x1b5f70>:
  5b6b70:	57                   	push   edi
  5b6b71:	8b f8                	mov    edi,eax
  5b6b73:	85 f6                	test   esi,esi
  5b6b75:	74 28                	je     0x5b6b9f
  5b6b77:	8b 06                	mov    eax,DWORD PTR [esi]
  5b6b79:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  5b6b7c:	8b ce                	mov    ecx,esi
  5b6b7e:	ff d2                	call   edx
  5b6b80:	3d be 05 01 00       	cmp    eax,0x105be
  5b6b85:	75 04                	jne    0x5b6b8b
  5b6b87:	8b c6                	mov    eax,esi
  5b6b89:	eb 16                	jmp    0x5b6ba1
  5b6b8b:	6a 00                	push   0x0
  5b6b8d:	68 c0 1f bf 00       	push   0xbf1fc0
  5b6b92:	68 18 21 bf 00       	push   0xbf2118
  5b6b97:	6a 00                	push   0x0
  5b6b99:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  5b6b9f:	33 c0                	xor    eax,eax
  5b6ba1:	8b 48 14             	mov    ecx,DWORD PTR [eax+0x14]
  5b6ba4:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6baa:	6a 00                	push   0x0
  5b6bac:	6a 00                	push   0x0
  5b6bae:	51                   	push   ecx
  5b6baf:	8b 48 18             	mov    ecx,DWORD PTR [eax+0x18]
  5b6bb2:	e8 69 f9 07 00       	call   0x636520
  5b6bb7:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6bbd:	52                   	push   edx
  5b6bbe:	e8 4d 34 19 00       	call   0x74a010
  5b6bc3:	8b 87 24 02 00 00    	mov    eax,DWORD PTR [edi+0x224]
  5b6bc9:	50                   	push   eax
  5b6bca:	57                   	push   edi
  5b6bcb:	e8 30 02 fe ff       	call   0x596e00
  5b6bd0:	5f                   	pop    edi
  5b6bd1:	c3                   	ret
```

### S13 — 0x105B9 event+0x14 QuestInfo exact lookup and TalkBox mode1: VA `0x005b6c6e..0x005b6d15` / raw `0x1b606e..0x1b6115` / 167 B / SHA256 `e3b11a514ccdeb830079978c4e66500f9a67cfa70bfff38c1da80f596b07fc5c`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

005b6c6e <.data+0x1b606e>:
  5b6c6e:	8b 43 14             	mov    eax,DWORD PTR [ebx+0x14]
  5b6c71:	8b 35 4c 11 fb 00    	mov    esi,DWORD PTR ds:0xfb114c
  5b6c77:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  5b6c7b:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  5b6c7f:	51                   	push   ecx
  5b6c80:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5b6c84:	8b ce                	mov    ecx,esi
  5b6c86:	e8 95 d0 f4 ff       	call   0x503d20
  5b6c8b:	8b 76 04             	mov    esi,DWORD PTR [esi+0x4]
  5b6c8e:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  5b6c92:	3b c6                	cmp    eax,esi
  5b6c94:	74 6c                	je     0x5b6d02
  5b6c96:	8d 70 10             	lea    esi,[eax+0x10]
  5b6c99:	85 f6                	test   esi,esi
  5b6c9b:	74 65                	je     0x5b6d02
  5b6c9d:	f6 05 2c b2 fa 00 01 	test   BYTE PTR ds:0xfab22c,0x1
  5b6ca4:	75 29                	jne    0x5b6ccf
  5b6ca6:	b8 01 00 00 00       	mov    eax,0x1
  5b6cab:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  5b6cb1:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  5b6cb5:	e8 d6 7f f2 ff       	call   0x4dec90
  5b6cba:	68 30 ce bc 00       	push   0xbcce30
  5b6cbf:	e8 56 b6 2d 00       	call   0x89231a
  5b6cc4:	83 c4 04             	add    esp,0x4
  5b6cc7:	c7 44 24 28 ff ff ff 	mov    DWORD PTR [esp+0x28],0xffffffff
  5b6cce:	ff 
  5b6ccf:	8b 53 14             	mov    edx,DWORD PTR [ebx+0x14]
  5b6cd2:	a1 bc b1 fa 00       	mov    eax,ds:0xfab1bc
  5b6cd7:	8b 4e 28             	mov    ecx,DWORD PTR [esi+0x28]
  5b6cda:	52                   	push   edx
  5b6cdb:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6ce1:	6a 01                	push   0x1
  5b6ce3:	50                   	push   eax
  5b6ce4:	e8 37 f8 07 00       	call   0x636520
  5b6ce9:	8b 8f 24 02 00 00    	mov    ecx,DWORD PTR [edi+0x224]
  5b6cef:	51                   	push   ecx
  5b6cf0:	e8 1b 33 19 00       	call   0x74a010
  5b6cf5:	8b 97 24 02 00 00    	mov    edx,DWORD PTR [edi+0x224]
  5b6cfb:	52                   	push   edx
  5b6cfc:	57                   	push   edi
  5b6cfd:	e8 fe 00 fe ff       	call   0x596e00
  5b6d02:	8b 4c 24 20          	mov    ecx,DWORD PTR [esp+0x20]
  5b6d06:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  5b6d0d:	59                   	pop    ecx
  5b6d0e:	5f                   	pop    edi
  5b6d0f:	5e                   	pop    esi
  5b6d10:	5b                   	pop    ebx
  5b6d11:	8b e5                	mov    esp,ebp
  5b6d13:	5d                   	pop    ebp
  5b6d14:	c3                   	ret
```

### S14 — TalkBox stores giver selector and chooses mode-specific record: VA `0x00636550..0x006366b9` / raw `0x235950..0x235ab9` / 361 B / SHA256 `33f88d225b89a1ac591ba9af76acb6de184c397a86e98362f9bb62dcc84380ea`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00636550 <.data+0x235950>:
  636550:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  636553:	8b 1d d0 1b fe 00    	mov    ebx,DWORD PTR ds:0xfe1bd0
  636559:	8d 4c 24 10          	lea    ecx,[esp+0x10]
  63655d:	89 87 80 00 00 00    	mov    DWORD PTR [edi+0x80],eax
  636563:	51                   	push   ecx
  636564:	8d 4b 08             	lea    ecx,[ebx+0x8]
  636567:	8d 44 24 18          	lea    eax,[esp+0x18]
  63656b:	89 b7 84 00 00 00    	mov    DWORD PTR [edi+0x84],esi
  636571:	89 74 24 14          	mov    DWORD PTR [esp+0x14],esi
  636575:	e8 46 d3 20 00       	call   0x8438c0
  63657a:	8b 43 0c             	mov    eax,DWORD PTR [ebx+0xc]
  63657d:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  636581:	33 db                	xor    ebx,ebx
  636583:	3b c8                	cmp    ecx,eax
  636585:	74 05                	je     0x63658c
  636587:	8b 49 10             	mov    ecx,DWORD PTR [ecx+0x10]
  63658a:	eb 02                	jmp    0x63658e
  63658c:	33 c9                	xor    ecx,ecx
  63658e:	8b 87 bc 00 00 00    	mov    eax,DWORD PTR [edi+0xbc]
  636594:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  636597:	56                   	push   esi
  636598:	50                   	push   eax
  636599:	89 8f b8 00 00 00    	mov    DWORD PTR [edi+0xb8],ecx
  63659f:	89 97 90 00 00 00    	mov    DWORD PTR [edi+0x90],edx
  6365a5:	89 9f 88 00 00 00    	mov    DWORD PTR [edi+0x88],ebx
  6365ab:	e8 30 24 00 00       	call   0x6389e0
  6365b0:	6a 24                	push   0x24
  6365b2:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  6365b6:	e8 ad ac 25 00       	call   0x891268
  6365bb:	83 c4 04             	add    esp,0x4
  6365be:	3b c3                	cmp    eax,ebx
  6365c0:	0f 84 85 01 00 00    	je     0x63674b
  6365c6:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  6365ca:	89 00                	mov    DWORD PTR [eax],eax
  6365cc:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  6365d0:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  6365d3:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  6365d7:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  6365da:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  6365de:	c6 41 20 01          	mov    BYTE PTR [ecx+0x20],0x1
  6365e2:	8b 54 24 28          	mov    edx,DWORD PTR [esp+0x28]
  6365e6:	c6 42 21 01          	mov    BYTE PTR [edx+0x21],0x1
  6365ea:	53                   	push   ebx
  6365eb:	89 5c 24 44          	mov    DWORD PTR [esp+0x44],ebx
  6365ef:	8b 8f 84 00 00 00    	mov    ecx,DWORD PTR [edi+0x84]
  6365f5:	8b 97 80 00 00 00    	mov    edx,DWORD PTR [edi+0x80]
  6365fb:	8d 44 24 28          	lea    eax,[esp+0x28]
  6365ff:	50                   	push   eax
  636600:	a1 b4 1d fe 00       	mov    eax,ds:0xfe1db4
  636605:	51                   	push   ecx
  636606:	52                   	push   edx
  636607:	50                   	push   eax
  636608:	e8 43 5c ec ff       	call   0x4fc250
  63660d:	39 5c 24 2c          	cmp    DWORD PTR [esp+0x2c],ebx
  636611:	8b 87 90 00 00 00    	mov    eax,DWORD PTR [edi+0x90]
  636617:	0f 95 c1             	setne  cl
  63661a:	88 8f 8c 00 00 00    	mov    BYTE PTR [edi+0x8c],cl
  636620:	83 f8 03             	cmp    eax,0x3
  636623:	0f 87 e3 00 00 00    	ja     0x63670c
  636629:	ff 24 85 74 67 63 00 	jmp    DWORD PTR [eax*4+0x636774]
  636630:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636636:	8b 11                	mov    edx,DWORD PTR [ecx]
  636638:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  63663b:	ff d0                	call   eax
  63663d:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  636643:	8b 11                	mov    edx,DWORD PTR [ecx]
  636645:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  636648:	ff d0                	call   eax
  63664a:	e8 51 f6 ff ff       	call   0x635ca0
  63664f:	e9 b8 00 00 00       	jmp    0x63670c
  636654:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  63665a:	8b 11                	mov    edx,DWORD PTR [ecx]
  63665c:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  63665f:	ff d0                	call   eax
  636661:	e8 ca 92 dd ff       	call   0x40f930
  636666:	8b c8                	mov    ecx,eax
  636668:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  63666b:	e8 20 a9 ec ff       	call   0x500f90
  636670:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  636676:	3b c3                	cmp    eax,ebx
  636678:	74 73                	je     0x6366ed
  63667a:	8b 48 30             	mov    ecx,DWORD PTR [eax+0x30]
  63667d:	51                   	push   ecx
  63667e:	8b c7                	mov    eax,edi
  636680:	e8 8b f8 ff ff       	call   0x635f10
  636685:	eb 72                	jmp    0x6366f9
  636687:	8b 8f bc 00 00 00    	mov    ecx,DWORD PTR [edi+0xbc]
  63668d:	8b 11                	mov    edx,DWORD PTR [ecx]
  63668f:	8b 42 08             	mov    eax,DWORD PTR [edx+0x8]
  636692:	ff d0                	call   eax
  636694:	e8 97 92 dd ff       	call   0x40f930
  636699:	8b c8                	mov    ecx,eax
  63669b:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  63669e:	e8 ed a8 ec ff       	call   0x500f90
  6366a3:	89 87 88 00 00 00    	mov    DWORD PTR [edi+0x88],eax
  6366a9:	3b c3                	cmp    eax,ebx
  6366ab:	74 40                	je     0x6366ed
  6366ad:	8b 48 34             	mov    ecx,DWORD PTR [eax+0x34]
  6366b0:	51                   	push   ecx
  6366b1:	8b c7                	mov    eax,edi
  6366b3:	e8 58 f8 ff ff       	call   0x635f10
  6366b8:	eb                 	jmp    0x6366f9
```

### S15 — UI provider list rebuild based on record-giver value: VA `0x006389e0..0x00638abb` / raw `0x237de0..0x237ebb` / 219 B / SHA256 `88c1bbac4979079ed5e78908f317ba677dd2ccb6fe812bf7386e495df3050206`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

006389e0 <.data+0x237de0>:
  6389e0:	55                   	push   ebp
  6389e1:	8b ec                	mov    ebp,esp
  6389e3:	83 ec 1c             	sub    esp,0x1c
  6389e6:	53                   	push   ebx
  6389e7:	56                   	push   esi
  6389e8:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  6389eb:	57                   	push   edi
  6389ec:	8d 9e b0 00 00 00    	lea    ebx,[esi+0xb0]
  6389f2:	8b fb                	mov    edi,ebx
  6389f4:	e8 57 ae 1e 00       	call   0x823850
  6389f9:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  6389fc:	8b 3d d0 1b fe 00    	mov    edi,DWORD PTR ds:0xfe1bd0
  638a02:	8d 4d 0c             	lea    ecx,[ebp+0xc]
  638a05:	89 45 0c             	mov    DWORD PTR [ebp+0xc],eax
  638a08:	51                   	push   ecx
  638a09:	8d 4f 08             	lea    ecx,[edi+0x8]
  638a0c:	8d 45 fc             	lea    eax,[ebp-0x4]
  638a0f:	e8 ac ae 20 00       	call   0x8438c0
  638a14:	8b 45 fc             	mov    eax,DWORD PTR [ebp-0x4]
  638a17:	3b 47 0c             	cmp    eax,DWORD PTR [edi+0xc]
  638a1a:	0f 84 94 00 00 00    	je     0x638ab4
  638a20:	8b 78 10             	mov    edi,DWORD PTR [eax+0x10]
  638a23:	85 ff                	test   edi,edi
  638a25:	0f 84 89 00 00 00    	je     0x638ab4
  638a2b:	8a 57 20             	mov    dl,BYTE PTR [edi+0x20]
  638a2e:	8d 86 c8 00 00 00    	lea    eax,[esi+0xc8]
  638a34:	8d 8e 7c 01 00 00    	lea    ecx,[esi+0x17c]
  638a3a:	50                   	push   eax
  638a3b:	88 11                	mov    BYTE PTR [ecx],dl
  638a3d:	e8 de 1d 00 00       	call   0x63a820
  638a42:	8b 48 04             	mov    ecx,DWORD PTR [eax+0x4]
  638a45:	2b 08                	sub    ecx,DWORD PTR [eax]
  638a47:	89 45 f8             	mov    DWORD PTR [ebp-0x8],eax
  638a4a:	c1 f9 02             	sar    ecx,0x2
  638a4d:	89 4d f4             	mov    DWORD PTR [ebp-0xc],ecx
  638a50:	c7 45 0c 00 00 00 00 	mov    DWORD PTR [ebp+0xc],0x0
  638a57:	85 c9                	test   ecx,ecx
  638a59:	74 59                	je     0x638ab4
  638a5b:	eb 09                	jmp    0x638a66
  638a5d:	8d 49 00             	lea    ecx,[ecx+0x0]
  638a60:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  638a63:	8b 45 f8             	mov    eax,DWORD PTR [ebp-0x8]
  638a66:	8b 08                	mov    ecx,DWORD PTR [eax]
  638a68:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  638a6b:	8b 04 91             	mov    eax,DWORD PTR [ecx+edx*4]
  638a6e:	8b 74 86 0c          	mov    esi,DWORD PTR [esi+eax*4+0xc]
  638a72:	33 c0                	xor    eax,eax
  638a74:	39 43 08             	cmp    DWORD PTR [ebx+0x8],eax
  638a77:	74 15                	je     0x638a8e
  638a79:	8b 4b 04             	mov    ecx,DWORD PTR [ebx+0x4]
  638a7c:	8d 45 fc             	lea    eax,[ebp-0x4]
  638a7f:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  638a82:	e8 19 6e f0 ff       	call   0x53f8a0
  638a87:	8b 55 fc             	mov    edx,DWORD PTR [ebp-0x4]
  638a8a:	8b 42 0c             	mov    eax,DWORD PTR [edx+0xc]
  638a8d:	40                   	inc    eax
  638a8e:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  638a91:	8d 7d ec             	lea    edi,[ebp-0x14]
  638a94:	8b f3                	mov    esi,ebx
  638a96:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  638a99:	e8 82 64 f4 ff       	call   0x57ef20
  638a9e:	50                   	push   eax
  638a9f:	53                   	push   ebx
  638aa0:	8d 75 e4             	lea    esi,[ebp-0x1c]
  638aa3:	e8 58 67 1f 00       	call   0x82f200
  638aa8:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  638aab:	40                   	inc    eax
  638aac:	89 45 0c             	mov    DWORD PTR [ebp+0xc],eax
  638aaf:	3b 45 f4             	cmp    eax,DWORD PTR [ebp-0xc]
  638ab2:	72 ac                	jb     0x638a60
  638ab4:	5f                   	pop    edi
  638ab5:	5e                   	pop    esi
  638ab6:	5b                   	pop    ebx
  638ab7:	8b e5                	mov    esp,ebp
  638ab9:	5d                   	pop    ebp
  638aba:	c2               	ret    0x8
```

### S16 — UI producer 0x105B9 gets event+0x14 from context+4+0x84: VA `0x006391c0..0x0063925e` / raw `0x2385c0..0x23865e` / 158 B / SHA256 `bdcd58215c829bf0d3d82156306281fba96206ff2dc15206055b8cfc57b7b62b`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

006391c0 <.data+0x2385c0>:
  6391c0:	56                   	push   esi
  6391c1:	6a 18                	push   0x18
  6391c3:	8b f1                	mov    esi,ecx
  6391c5:	e8 9e 80 25 00       	call   0x891268
  6391ca:	83 c4 04             	add    esp,0x4
  6391cd:	85 c0                	test   eax,eax
  6391cf:	74 32                	je     0x639203
  6391d1:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  6391d4:	8b 89 84 00 00 00    	mov    ecx,DWORD PTR [ecx+0x84]
  6391da:	83 ca ff             	or     edx,0xffffffff
  6391dd:	8b f0                	mov    esi,eax
  6391df:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  6391e2:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  6391e5:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  6391ec:	c7 40 10 ec 42 0f 00 	mov    DWORD PTR [eax+0x10],0xf42ec
  6391f3:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  6391f9:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  6391fc:	e8 9f e0 dc ff       	call   0x4072a0
  639201:	5e                   	pop    esi
  639202:	c3                   	ret
  639203:	33 c0                	xor    eax,eax
  639205:	8b f0                	mov    esi,eax
  639207:	e8 94 e0 dc ff       	call   0x4072a0
  63920c:	5e                   	pop    esi
  63920d:	c3                   	ret
  63920e:	cc                   	int3
  63920f:	cc                   	int3
  639210:	56                   	push   esi
  639211:	6a 18                	push   0x18
  639213:	8b f1                	mov    esi,ecx
  639215:	e8 4e 80 25 00       	call   0x891268
  63921a:	83 c4 04             	add    esp,0x4
  63921d:	85 c0                	test   eax,eax
  63921f:	74 32                	je     0x639253
  639221:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  639224:	8b 89 84 00 00 00    	mov    ecx,DWORD PTR [ecx+0x84]
  63922a:	83 ca ff             	or     edx,0xffffffff
  63922d:	8b f0                	mov    esi,eax
  63922f:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  639232:	89 50 08             	mov    DWORD PTR [eax+0x8],edx
  639235:	c7 40 0c 00 00 00 00 	mov    DWORD PTR [eax+0xc],0x0
  63923c:	c7 40 10 eb 42 0f 00 	mov    DWORD PTR [eax+0x10],0xf42eb
  639243:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  639249:	89 48 14             	mov    DWORD PTR [eax+0x14],ecx
  63924c:	e8 4f e0 dc ff       	call   0x4072a0
  639251:	5e                   	pop    esi
  639252:	c3                   	ret
  639253:	33 c0                	xor    eax,eax
  639255:	8b f0                	mov    esi,eax
  639257:	e8 44 e0 dc ff       	call   0x4072a0
  63925c:	5e                   	pop    esi
  63925d:	c3                   	ret
```

### S17 — Type1-only mode3 event producer disqualifies Quest16 type2: VA `0x00636c84..0x00636cfa` / raw `0x236084..0x2360fa` / 118 B / SHA256 `3099070a534bbe39f8a0239dea9968031f3be268fcf9163a577c36de611f0e66`

```asm
/mnt/data/Tartaros.bin:     file format binary


Disassembly of section .data:

00636c84 <.data+0x236084>:
  636c84:	83 f8 03             	cmp    eax,0x3
  636c87:	75 71                	jne    0x636cfa
  636c89:	8b 87 88 00 00 00    	mov    eax,DWORD PTR [edi+0x88]
  636c8f:	3b c3                	cmp    eax,ebx
  636c91:	74 67                	je     0x636cfa
  636c93:	8b 10                	mov    edx,DWORD PTR [eax]
  636c95:	52                   	push   edx
  636c96:	51                   	push   ecx
  636c97:	e8 94 8c dd ff       	call   0x40f930
  636c9c:	8b 8f 84 00 00 00    	mov    ecx,DWORD PTR [edi+0x84]
  636ca2:	83 c4 04             	add    esp,0x4
  636ca5:	8b d0                	mov    edx,eax
  636ca7:	e8 24 9b ec ff       	call   0x5007d0
  636cac:	0f b7 f0             	movzx  esi,ax
  636caf:	85 f6                	test   esi,esi
  636cb1:	74 47                	je     0x636cfa
  636cb3:	6a 18                	push   0x18
  636cb5:	e8 ae a5 25 00       	call   0x891268
  636cba:	83 c4 04             	add    esp,0x4
  636cbd:	85 c0                	test   eax,eax
  636cbf:	74 1e                	je     0x636cdf
  636cc1:	83 c9 ff             	or     ecx,0xffffffff
  636cc4:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  636cc7:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  636cca:	89 58 0c             	mov    DWORD PTR [eax+0xc],ebx
  636ccd:	c7 40 10 8a 43 0f 00 	mov    DWORD PTR [eax+0x10],0xf438a
  636cd4:	c7 00 ac 67 c4 00    	mov    DWORD PTR [eax],0xc467ac
  636cda:	89 70 14             	mov    DWORD PTR [eax+0x14],esi
  636cdd:	eb 02                	jmp    0x636ce1
  636cdf:	33 c0                	xor    eax,eax
  636ce1:	89 44 24 0c          	mov    DWORD PTR [esp+0xc],eax
  636ce5:	e8 b6 dd dc ff       	call   0x404aa0
  636cea:	8d 4c 24 0c          	lea    ecx,[esp+0xc]
  636cee:	51                   	push   ecx
  636cef:	8d b0 5c 14 00 00    	lea    esi,[eax+0x145c]
  636cf5:	e8 66 d5 1c 00       	call   0x804260
```

