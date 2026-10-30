# T16-130 — Pindos 村莊：Table/SceneList 章節/劇情序列、雙入口場景鍵、Event/SceneList Lua、RestoreMap 返回邊界（KR BIN-first）

- 研究日期：`2026-10-30T15:52:19+08:00`（Asia/Taipei）；作者：`chatgpt-web roy`；正式段號：**T16-130**，接已提交 T16-129，未重編歷史段號。
- KR `Tartaros.bin`：`12472320` bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Event.stp` `11241597` bytes SHA256 `2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b`；`Table.stp` `5248784` bytes SHA256 `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442`。原件唯讀、未執行、未修補。**BIN 依先前 PE `.text` VA=raw+`0x400C00`，詳見各 evidence。**
- 本稿研究目標：由 Quest15 場景 `(15,3)` 何以成為 Client scene execution key，追索可辨識的本地資料/記錄 writer，Pindos 實際腳本及 `RestoreMap` 的可證返回界線；查明不可由 Client 靜態證據推導的 Server/Runtime 問題。此處研究範圍是 Client 原生可證流程，而非原版 Server 實作。
- GitHub 記錄：本輪開工 `main=5a38070c762855b73f5fb563f0e673df5e1f940f`，對 `t16/roy/chatgpt-web` 比較 `ahead=4 behind=133`。**同一 ChatGPT 對話已依03執行過一次 main→T16 sync，本輪只讀 GitHub，不再自動 Merge。** `research/requests/index.json` 與 T16 inbox 無 owner T16 RR。T01 固定 ID `T01-RETURN-T16-117-Q16-MODE2-C2S36-001` 仍 NEEDS_FIX；使用者本次指定130，退回修正獨立列為下一步，不把源稿117錯誤重複引用成確定事實。
- 研究前已讀 T16-124..129 的相關有界原稿；共用 `shared/verified-knowledge/` 有7項有限 native verified subclaims，但此 T16 scene chapter/progression 全鏈並無 T01 整篇 FULL-PASS 可直接替代。

## I. 研究結果、重要更正與完成界線

**最重要新發現：先前的 `Event/SceneList.xml` 不是唯一一張 SceneList。** BIN 的另一個 `0x47DE40` loader 直接讀 **`Table/SceneList.xml`**（唯讀字串 VA `0xC032C8`，raw `0x8018C8`），解析 `CHAPTERTABLE→CHAPTER→SCENARIO→SCENE`。前段 `0x5607D0` 則讀 **`Event/SceneList.xml`**，其 key 是 `(questIdx,sceneIdx)`、value 是 `funcName`，索引在 `0xFB73C8`。**兩表名稱相似、實際意義及容器不同；不得將 ChapterIdx、QuestID、TownID、SceneIdx、TalkBox mode 視為可互換。**

1. **新 Table 索引資料提供者（BIN 已證）**：`0x47DD08...` 初始化 `0xFC0F68`，`0x47DE40` 打開 `Table/SceneList.xml` 並讀 `chapterIdx→chapterRecord+0`, `townId→+4`, `chapterName→+8`；章節內 `SCENARIO` 讀 `questId`，`SCENE` 讀 `sceneIdx`，分別填入 DWORD vector `chapterRecord+0x24` 和 `+0x34`（原生指令見 N01..N09）。該資料組成樹的多鍵/階層索引，不能從已解析的欄位名稱推論章節數字必與任務ID相等。
2. **Object 入口拿第一個場景值**：`0x47D36D` 由章節節點 payload 指標呼叫 `0x47B2B0`；物件 `+0x248` 收 `[record+0]`（Chapter/key），`+0x24C` 接 `[record+8]` 的字串（不是場景編號）。`0x47D5A3..0x47D5B7` 傳入這個 key 由 `0x47E890` 查 `0xFC0F68` 的相應節點，讀 `chapterRecord+0x34` DWORD scene 向量**首元素**；回傳0是無匹配/空列表路徑；把所得值傳 `0x47B5C0`。只有一般 key 且非特殊 `0xEA61` 分支才在 `0x47B64A` 以 `(object+0x248, returned sceneIdx)` 呼叫 `0x565720`。
3. **Controller 入口拿下一個場景值**：`0x561DE0` 在有效 `controller+0x89`、`+0x28` 等條件下，`0x561ED1/0x561ED4` 取 `controller+0x3C`（舊 sceneIdx）及 `controller+0x38`（primary key），調 `0x47E640(0xFC0F68,primary,oldSecondary)`；此函式遍歷 matching chapter record 的 `+0x34` DWORD list，找到 oldSecondary 後遞增 index、返回下一值；沒找到/到尾返回0。`0x561EE5` 保存新 `+0x3C`，**新值非0才呼叫 `0x565720(primary,next)`**。並非 `0x3F` 的 pending flag 一旦存在就會自動按 Scene1→2→3→4 順序播放；具體順序來自表。
4. **第二張 Event 腳本索引 consumer**：`0x565720` 再以獨立 `0xFB73C8` 比較 `(primary,sceneIdx)`，命中取得 `funcName`、`0x55D6A0` 建 VM/scene API、`0x6F4A50` 載入腳本；未命中按早退路徑，不應猜為 Scene3 fallback。從 Table 的 **chapterIdx** 與 Event 的 **questIdx** 接合須兩個實際鍵值相同；單靠資料欄位同名或 Quest15 文字標籤不足。
5. **Quest15/Pindos 原始腳本**：XOR-FF 解碼後四份 Lua 的註解明示 `Quest #15 / Scene #1..4`；Scene3 `pindos_talkevent` 有 `LoadMap("town001D.map")`、物件10047、`OpenTalkScene(3,18/24/20/21)`、`DoProlog(1)`、`Q.DeleteAllObject()`、`RestoreMap()`。`DoProlog(1)` 仍不可當成 Server 持久化完成。
6. **恢復/清理的可證邊界**：Lua 原文 `RestoreMap()` 出現在 Scene1..4 的清理尾段，Scene3 位於 `Q.DeleteAllObject()` 後、`RevPhase1()` 前；BIN `0x55E089` 把 global name `RestoreMap`（VA `0xC10554`）送給 VM 名稱註冊 `0x6F5790`。**這確認腳本具有該名稱的原生 VM binding，但不表示已解析 RestoreMap 對場景場地、玩家位置、UI 或網路的全部副作用**。`0x6F5790` 是通用 name registration，不能無符號證據就誤命名成 RestoreMap native callback。

### 完成判定／實質證據限制

**本輪已閉合原始 Client 的 TableSceneList(兩層資料) → FIRST/NEXT selector → EventSceneList(questIdx,sceneIdx) → Lua 腳本執行邊界，以及 Lua 所宣告的恢復順序。** 然而本輪**仍不能直接從完整解包的 `Table/SceneList.xml` 逐列證明**某個 chapter 鍵確實是15、其 sceneIdx vector 包含3且如何排序，亦未證明原版 Server 完成Quest15會使 Client 走此路徑。所以必須將 **「Quest15 完成必定啟動 Pindos Scene3」標為未證；不以函式地址相接誇稱 runtime 因果已閉合**。若完整題目要求由上游 Quest15 完成到 Scene3 的*必然*執行，該目標仍受原始 `Table/SceneList.xml` 可讀內容和 runtime/封包先決條件阻塞；本段只能將 Client 靜態機械層判為「有界完成」、完整 Pindos 可玩流程判為「尚未完成」。

## II. TableSceneList 與 EventSceneList：schema／位址／結構不能混同

| 子系統 | Source | Loader | Native index / key | Consumer | Note |
|---|---|---|---|---|---|
| Chapter/Scene order | `Table/SceneList.xml` | `0x47DE40` | `0xFC0F68` chapter record、`+0x24` quest ID vector / `+0x34` sceneIdx vector | `0x47E890`（FIRST），`0x47E640`（NEXT） | 序列成員由 Table 原件提供，不臆造 `[1,2,3,4]` |
| Quest scene script | `Event/SceneList.xml` | `0x5607D0` | `0xFB73C8` map(questIdx,sceneIdx) | `0x565720` → Lua VM loader | four scripts are directly verified in Event.stp |
| NPC quest candidate | `Table/QuestInfo.xml` | `0x504370` / `0x500240` | QuestRecord Demand16 / +0x28 giver10338 | `0x5008B0` | quest accept eligibility, not SceneList index |
| Town selector | world/context field +0x8C | S2C `0x38` subtype | `0xFAB1BC` (verified from `0x40F060()+0x8C`) | `0x500240` | town5 is not SceneIdx3 |

**Additional raw string evidence** (from KR BIN `.rdata`):
- VA `0xC032C8` = `Table/SceneList.xml`; `0xC03340`=`CHAPTERTABLE`; `0xC03350`=`CHAPTER`; `0xC03358`=`chapterIdx`; `0xC03364`=`townId`; `0xC0336C`=`chapterName`; `0xC03378`=`SCENARIO`; `0xC03384`=`questId`; `0xC0338C`=`SCENE`; `0xC03394`=`sceneIdx`.
- VA `0xC10668`=`Event/SceneList.xml`; `questIdx`, `sceneIdx` 和 `funcName` attribute 由 `0x5607D0` loader 查，映射一個 Quest/Scene 雙鍵到 Lua function name。
- `Table.stp` 頭 `STPD`，不是直接可逐列讀取的 XML 檔。從原件逐行確認 Table/SceneList 實際 keys/順序之前，不能把 Loader 所顯示的 schema 視為原件內容。

## III. 新發現的雙入口資料流，成功／失敗矩陣

| 入口 | 實際來源 | 條件與效果 | 反證／限制 |
|---|---|---|---|
| Object creation | `0x47D290` map iterator → `0x47D36D` | 取 node payload，呼叫 `0x47B2B0`; record+0 → object+0x248, record+8 → object+0x24C string | object key 未證必為 QuestID15 |
| FIRST scene | `0x47D5A3..0x47D5B7` | `0x47E890` 以 object+0x248 查 Table chapter，返回 record+0x34 sceneIdx vector 第一個 | 無匹配或空 vector→0；0不是有效 Scene3 佐證 |
| Object event | `0x47B5C0` | key !=0xEA61 時用 `(object key, selected scene)` 呼叫 `0x565720` | key==0xEA61 且特殊 flag → `0x47B850`；若 EventSceneList miss 無 script |
| NEXT scene | `0x561ED1..0x561EF3` | controller+0x38/+0x3C 經 `0x47E640` 產下一個；非零才 `0x565720` | oldIndex找不到/最後/空→0；不能假設線性自增1 |
| Script start | `0x565720` | EventSceneList map 命中 funcName → Lua prepare/load | resource missing, VM failure, active flag/scene state gate 均可早退 |
| Script cleanup | Lua `pindos_talkevent` | `Q.DeleteAllObject`→`RestoreMap`→`RevPhase1` | callback 的內部 native field/position寫入尚未追完，不能推導永久城鎮/登出 |

## IV. 關鍵偽碼：精確限定於 native 條件

```cpp
// Symbol names are illustrative; two independent tables exist.
struct ChapterRecord {
    uint32_t chapterIdx;   // +0x00
    uint32_t townId;       // +0x04
    String chapterName;    // +0x08
    // ...
    vector<uint32_t> questIds; // +0x24 (separate parsed SCENARIO questId)
    vector<uint32_t> sceneIds; // +0x34 (separate parsed SCENE sceneIdx)
};
// tableIndex: global 0xFC0F68, keyed from chapter data; exact duplicate and object lifetime pending.
uint32_t firstScene(int chapterKey) {
    ChapterRecord *row = chapterIndex.find(chapterKey);
    if (!row || row->sceneIds.empty()) return 0;
    return row->sceneIds.front();
}
uint32_t nextScene(int chapterKey, int previousIndex) {
    ChapterRecord* row = chapterIndex.find(chapterKey);
    if (!row) return 0;
    // 0x47E640 searches sceneIds up to last valid predecessor, then reads successor;
    // absence or exhausted sequence => 0; no arithmetic nextIndex = prior+1 claim.
    for(size_t i=0; i+1<row->sceneIds.size(); ++i)
        if(row->sceneIds[i]==previousIndex) return row->sceneIds[i+1];
    return 0;
}
void sceneObjectEvent(SceneObject* o) {
    int chapterKey=o->field248;
    int n=firstScene(chapterKey);
    if(chapterKey==0xEA61) { /* special flag branch -> 0x47B850 */ }
    else tryExecuteEventScene(chapterKey,n);  // 0x565720 → Event scene map
    // plus Table state update (0x47E750); not proof of Server quest completion
}
void controllerNext(Controller* c) {
    if(!c->sceneFlag89) return;
    if(c->state28!=0) { /* local restoration/UI work */ }
    int n=nextScene(c->key38,c->scene3C);
    c->scene3C=n;
    if(n!=0) tryExecuteEventScene(c->key38,n);
}
```

## V. Native evidence appendix: actual BIN machine code (not decompiler guesses)

- Each appendix has exact VA, raw=`VA-0x400C00`, byte span [begin,end), source bytes SHA256, disassembly from real `Tartaros.bin` by `objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00`. The snippets may contain tail partial instructions in boundaries; conclusions are tied to confirmed complete instruction addresses. Local named functions are descriptive only.

### N01. Table/SceneList.xml initialization and fallback; CHAPTERTABLE resource provider

- VA `0x47DD08..0x47DE40`; raw `0x7D108..0x7D240`; `312` bytes; SHA256 `37d340668f99d3b2cb6b6a2b309aec1d2af19bdac891f24c45813439e7d7b9da`.

```asm
0047dd08 <.data+0x7d108>:
  47dd08:	bf 68 0f fc 00       	mov    edi,0xfc0f68
  47dd0d:	33 db                	xor    ebx,ebx
  47dd0f:	6a 18                	push   0x18
  47dd11:	89 7d ec             	mov    DWORD PTR [ebp-0x14],edi
  47dd14:	89 1d 70 0f fc 00    	mov    DWORD PTR ds:0xfc0f70,ebx
  47dd1a:	e8 49 35 41 00       	call   0x891268
  47dd1f:	83 c4 04             	add    esp,0x4
  47dd22:	3b c3                	cmp    eax,ebx
  47dd24:	0f 84 ec 00 00 00    	je     0x47de16
  47dd2a:	a3 6c 0f fc 00       	mov    ds:0xfc0f6c,eax
  47dd2f:	89 00                	mov    DWORD PTR [eax],eax
  47dd31:	a1 6c 0f fc 00       	mov    eax,ds:0xfc0f6c
  47dd36:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  47dd39:	a1 6c 0f fc 00       	mov    eax,ds:0xfc0f6c
  47dd3e:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  47dd41:	a1 6c 0f fc 00       	mov    eax,ds:0xfc0f6c
  47dd46:	c6 40 14 01          	mov    BYTE PTR [eax+0x14],0x1
  47dd4a:	8b 0d 6c 0f fc 00    	mov    ecx,DWORD PTR ds:0xfc0f6c
  47dd50:	c6 41 15 01          	mov    BYTE PTR [ecx+0x15],0x1
  47dd54:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  47dd57:	89 1d 78 0f fc 00    	mov    DWORD PTR ds:0xfc0f78,ebx
  47dd5d:	c7 05 7c 0f fc 00 61 	mov    DWORD PTR ds:0xfc0f7c,0xea61
  47dd64:	ea 00 00 
  47dd67:	e8 d4 00 00 00       	call   0x47de40
  47dd6c:	f6 05 7c af fa 00 01 	test   BYTE PTR ds:0xfaaf7c,0x1
  47dd73:	75 20                	jne    0x47dd95
  47dd75:	83 0d 7c af fa 00 01 	or     DWORD PTR ds:0xfaaf7c,0x1
  47dd7c:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  47dd80:	e8 8b f6 10 00       	call   0x58d410
  47dd85:	68 c0 cd bc 00       	push   0xbccdc0
  47dd8a:	e8 8b 45 41 00       	call   0x89231a
  47dd8f:	83 c4 04             	add    esp,0x4
  47dd92:	88 5d fc             	mov    BYTE PTR [ebp-0x4],bl
  47dd95:	68 80 af fa 00       	push   0xfaaf80
  47dd9a:	be 78 0f fc 00       	mov    esi,0xfc0f78
  47dd9f:	ba dc 32 c0 00       	mov    edx,0xc032dc
  47dda4:	b9 fc 32 c0 00       	mov    ecx,0xc032fc
  47dda9:	e8 b2 10 11 00       	call   0x58ee60
  47ddae:	f6 05 7c af fa 00 01 	test   BYTE PTR ds:0xfaaf7c,0x1
  47ddb5:	75 20                	jne    0x47ddd7
  47ddb7:	83 0d 7c af fa 00 01 	or     DWORD PTR ds:0xfaaf7c,0x1
  47ddbe:	c6 45 fc 02          	mov    BYTE PTR [ebp-0x4],0x2
  47ddc2:	e8 49 f6 10 00       	call   0x58d410
  47ddc7:	68 c0 cd bc 00       	push   0xbccdc0
  47ddcc:	e8 49 45 41 00       	call   0x89231a
  47ddd1:	83 c4 04             	add    esp,0x4
  47ddd4:	88 5d fc             	mov    BYTE PTR [ebp-0x4],bl
  47ddd7:	68 80 af fa 00       	push   0xfaaf80
  47dddc:	be 7c 0f fc 00       	mov    esi,0xfc0f7c
  47dde1:	ba 24 33 c0 00       	mov    edx,0xc03324
  47dde6:	b9 fc 32 c0 00       	mov    ecx,0xc032fc
  47ddeb:	e8 70 10 11 00       	call   0x58ee60
  47ddf0:	8b 15 78 0f fc 00    	mov    edx,DWORD PTR ds:0xfc0f78
  47ddf6:	8b 0d 7c 0f fc 00    	mov    ecx,DWORD PTR ds:0xfc0f7c
  47ddfc:	52                   	push   edx
  47ddfd:	e8 4e 09 00 00       	call   0x47e750
  47de02:	8b c7                	mov    eax,edi
  47de04:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47de07:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47de0e:	59                   	pop    ecx
  47de0f:	5f                   	pop    edi
  47de10:	5e                   	pop    esi
  47de11:	5b                   	pop    ebx
  47de12:	8b e5                	mov    esp,ebp
  47de14:	5d                   	pop    ebp
  47de15:	c3                   	ret
  47de16:	8d 45 f0             	lea    eax,[ebp-0x10]
  47de19:	50                   	push   eax
  47de1a:	8d 4d e0             	lea    ecx,[ebp-0x20]
  47de1d:	89 5d f0             	mov    DWORD PTR [ebp-0x10],ebx
  47de20:	e8 84 32 41 00       	call   0x8910a9
  47de25:	68 a8 57 c8 00       	push   0xc857a8
  47de2a:	8d 4d e0             	lea    ecx,[ebp-0x20]
  47de2d:	51                   	push   ecx
  47de2e:	c7 45 e0 a4 2c bd 00 	mov    DWORD PTR [ebp-0x20],0xbd2ca4
  47de35:	e8 b6 eb 41 00       	call   0x89c9f0
  47de3a:	cc                   	int3
  47de3b:	cc                   	int3
  47de3c:	cc                   	int3
  47de3d:	cc                   	int3
  47de3e:	cc                   	int3
  47de3f:	cc                   	int3
```

### N02. Table/SceneList.xml parser and CHAPTERTABLE/CHAPTER gate

- VA `0x47DE40..0x47DFA0`; raw `0x7D240..0x7D3A0`; `352` bytes; SHA256 `63037e81763cfa016f5cb5426d5e4641449d8b84dabf71918487fb36715332f8`.

```asm
0047de40 <.data+0x7d240>:
  47de40:	55                   	push   ebp
  47de41:	8b ec                	mov    ebp,esp
  47de43:	83 e4 f8             	and    esp,0xfffffff8
  47de46:	6a ff                	push   0xffffffff
  47de48:	68 75 54 92 00       	push   0x925475
  47de4d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47de53:	50                   	push   eax
  47de54:	81 ec f0 00 00 00    	sub    esp,0xf0
  47de5a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47de5f:	33 c4                	xor    eax,esp
  47de61:	89 84 24 e8 00 00 00 	mov    DWORD PTR [esp+0xe8],eax
  47de68:	53                   	push   ebx
  47de69:	56                   	push   esi
  47de6a:	57                   	push   edi
  47de6b:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47de70:	33 c4                	xor    eax,esp
  47de72:	50                   	push   eax
  47de73:	8d 84 24 00 01 00 00 	lea    eax,[esp+0x100]
  47de7a:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47de80:	8d 44 24 7c          	lea    eax,[esp+0x7c]
  47de84:	50                   	push   eax
  47de85:	b9 c8 32 c0 00       	mov    ecx,0xc032c8
  47de8a:	e8 a1 0f 2b 00       	call   0x72ee30
  47de8f:	33 db                	xor    ebx,ebx
  47de91:	89 9c 24 08 01 00 00 	mov    DWORD PTR [esp+0x108],ebx
  47de98:	8b 8c 24 9c 00 00 00 	mov    ecx,DWORD PTR [esp+0x9c]
  47de9f:	bf 10 00 00 00       	mov    edi,0x10
  47dea4:	39 bc 24 b0 00 00 00 	cmp    DWORD PTR [esp+0xb0],edi
  47deab:	73 07                	jae    0x47deb4
  47dead:	8d 8c 24 9c 00 00 00 	lea    ecx,[esp+0x9c]
  47deb4:	53                   	push   ebx
  47deb5:	8d b4 24 80 00 00 00 	lea    esi,[esp+0x80]
  47debc:	e8 4f 12 2b 00       	call   0x72f110
  47dec1:	38 9c 24 c0 00 00 00 	cmp    BYTE PTR [esp+0xc0],bl
  47dec8:	74 55                	je     0x47df1f
  47deca:	c7 84 24 08 01 00 00 	mov    DWORD PTR [esp+0x108],0xffffffff
  47ded1:	ff ff ff ff 
  47ded5:	c7 44 24 7c 94 23 bf 	mov    DWORD PTR [esp+0x7c],0xbf2394
  47dedc:	00 
  47dedd:	39 bc 24 dc 00 00 00 	cmp    DWORD PTR [esp+0xdc],edi
  47dee4:	72 10                	jb     0x47def6
  47dee6:	8b 8c 24 c8 00 00 00 	mov    ecx,DWORD PTR [esp+0xc8]
  47deed:	51                   	push   ecx
  47deee:	e8 19 33 41 00       	call   0x89120c
  47def3:	83 c4 04             	add    esp,0x4
  47def6:	8d 4c 24 7c          	lea    ecx,[esp+0x7c]
  47defa:	c7 84 24 dc 00 00 00 	mov    DWORD PTR [esp+0xdc],0xf
  47df01:	0f 00 00 00 
  47df05:	89 9c 24 d8 00 00 00 	mov    DWORD PTR [esp+0xd8],ebx
  47df0c:	88 9c 24 c8 00 00 00 	mov    BYTE PTR [esp+0xc8],bl
  47df13:	e8 28 01 2b 00       	call   0x72e040
  47df18:	33 c0                	xor    eax,eax
  47df1a:	e9 16 06 00 00       	jmp    0x47e535
  47df1f:	68 40 33 c0 00       	push   0xc03340
  47df24:	8d 84 24 80 00 00 00 	lea    eax,[esp+0x80]
  47df2b:	e8 b0 03 2b 00       	call   0x72e2e0
  47df30:	3b c3                	cmp    eax,ebx
  47df32:	75 55                	jne    0x47df89
  47df34:	c7 84 24 08 01 00 00 	mov    DWORD PTR [esp+0x108],0xffffffff
  47df3b:	ff ff ff ff 
  47df3f:	c7 44 24 7c 94 23 bf 	mov    DWORD PTR [esp+0x7c],0xbf2394
  47df46:	00 
  47df47:	39 bc 24 dc 00 00 00 	cmp    DWORD PTR [esp+0xdc],edi
  47df4e:	72 10                	jb     0x47df60
  47df50:	8b 94 24 c8 00 00 00 	mov    edx,DWORD PTR [esp+0xc8]
  47df57:	52                   	push   edx
  47df58:	e8 af 32 41 00       	call   0x89120c
  47df5d:	83 c4 04             	add    esp,0x4
  47df60:	8d 4c 24 7c          	lea    ecx,[esp+0x7c]
  47df64:	c7 84 24 dc 00 00 00 	mov    DWORD PTR [esp+0xdc],0xf
  47df6b:	0f 00 00 00 
  47df6f:	89 9c 24 d8 00 00 00 	mov    DWORD PTR [esp+0xd8],ebx
  47df76:	88 9c 24 c8 00 00 00 	mov    BYTE PTR [esp+0xc8],bl
  47df7d:	e8 be 00 2b 00       	call   0x72e040
  47df82:	33 c0                	xor    eax,eax
  47df84:	e9 ac 05 00 00       	jmp    0x47e535
  47df89:	bf 50 33 c0 00       	mov    edi,0xc03350
  47df8e:	e8 cd 03 2b 00       	call   0x72e360
  47df93:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  47df97:	3b c3                	cmp    eax,ebx
  47df99:	0f 84 41 05 00 00    	je     0x47e4e0
  47df9f:	90                   	nop
```

### N03. chapterIdx/townId/chapterName into chapter record+0,+4,+8

- VA `0x47DFA0..0x47E0F0`; raw `0x7D3A0..0x7D4F0`; `336` bytes; SHA256 `fc56617806ae45b3d24fcfe87f0e482ae3162831b0ce435cf64b5834bf5eb470`.

```asm
0047dfa0 <.data+0x7d3a0>:
  47dfa0:	6a 44                	push   0x44
  47dfa2:	e8 c1 32 41 00       	call   0x891268
  47dfa7:	83 c4 04             	add    esp,0x4
  47dfaa:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  47dfae:	c6 84 24 08 01 00 00 	mov    BYTE PTR [esp+0x108],0x1
  47dfb5:	01 
  47dfb6:	85 c0                	test   eax,eax
  47dfb8:	74 0e                	je     0x47dfc8
  47dfba:	50                   	push   eax
  47dfbb:	e8 c0 05 00 00       	call   0x47e580
  47dfc0:	8b d8                	mov    ebx,eax
  47dfc2:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  47dfc6:	eb 06                	jmp    0x47dfce
  47dfc8:	33 db                	xor    ebx,ebx
  47dfca:	89 5c 24 18          	mov    DWORD PTR [esp+0x18],ebx
  47dfce:	8b 7c 24 10          	mov    edi,DWORD PTR [esp+0x10]
  47dfd2:	83 c7 44             	add    edi,0x44
  47dfd5:	68 58 33 c0 00       	push   0xc03358
  47dfda:	c6 84 24 0c 01 00 00 	mov    BYTE PTR [esp+0x10c],0x0
  47dfe1:	00 
  47dfe2:	e8 b9 20 2b 00       	call   0x7300a0
  47dfe7:	85 c0                	test   eax,eax
  47dfe9:	74 1a                	je     0x47e005
  47dfeb:	83 c0 30             	add    eax,0x30
  47dfee:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  47dff2:	72 02                	jb     0x47dff6
  47dff4:	8b 00                	mov    eax,DWORD PTR [eax]
  47dff6:	85 c0                	test   eax,eax
  47dff8:	74 0b                	je     0x47e005
  47dffa:	50                   	push   eax
  47dffb:	e8 b4 37 41 00       	call   0x8917b4
  47e000:	83 c4 04             	add    esp,0x4
  47e003:	eb 02                	jmp    0x47e007
  47e005:	33 c0                	xor    eax,eax
  47e007:	68 64 33 c0 00       	push   0xc03364
  47e00c:	89 03                	mov    DWORD PTR [ebx],eax
  47e00e:	e8 8d 20 2b 00       	call   0x7300a0
  47e013:	85 c0                	test   eax,eax
  47e015:	74 1a                	je     0x47e031
  47e017:	83 c0 30             	add    eax,0x30
  47e01a:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  47e01e:	72 02                	jb     0x47e022
  47e020:	8b 00                	mov    eax,DWORD PTR [eax]
  47e022:	85 c0                	test   eax,eax
  47e024:	74 0b                	je     0x47e031
  47e026:	50                   	push   eax
  47e027:	e8 88 37 41 00       	call   0x8917b4
  47e02c:	83 c4 04             	add    esp,0x4
  47e02f:	eb 02                	jmp    0x47e033
  47e031:	33 c0                	xor    eax,eax
  47e033:	6a 0b                	push   0xb
  47e035:	bf 0f 00 00 00       	mov    edi,0xf
  47e03a:	68 6c 33 c0 00       	push   0xc0336c
  47e03f:	8d 4c 24 68          	lea    ecx,[esp+0x68]
  47e043:	89 43 04             	mov    DWORD PTR [ebx+0x4],eax
  47e046:	89 7c 24 7c          	mov    DWORD PTR [esp+0x7c],edi
  47e04a:	c7 44 24 78 00 00 00 	mov    DWORD PTR [esp+0x78],0x0
  47e051:	00 
  47e052:	c6 44 24 68 00       	mov    BYTE PTR [esp+0x68],0x0
  47e057:	e8 14 4a f8 ff       	call   0x402a70
  47e05c:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47e060:	68 75 23 bf 00       	push   0xbf2375
  47e065:	8d 44 24 64          	lea    eax,[esp+0x64]
  47e069:	8d 74 24 48          	lea    esi,[esp+0x48]
  47e06d:	c6 84 24 0c 01 00 00 	mov    BYTE PTR [esp+0x10c],0x2
  47e074:	02 
  47e075:	e8 76 0c 2b 00       	call   0x72ecf0
  47e07a:	50                   	push   eax
  47e07b:	8d 43 08             	lea    eax,[ebx+0x8]
  47e07e:	c6 84 24 0c 01 00 00 	mov    BYTE PTR [esp+0x10c],0x3
  47e085:	03 
  47e086:	e8 a5 20 fc ff       	call   0x440130
  47e08b:	be 10 00 00 00       	mov    esi,0x10
  47e090:	83 c4 04             	add    esp,0x4
  47e093:	39 74 24 58          	cmp    DWORD PTR [esp+0x58],esi
  47e097:	72 0d                	jb     0x47e0a6
  47e099:	8b 44 24 44          	mov    eax,DWORD PTR [esp+0x44]
  47e09d:	50                   	push   eax
  47e09e:	e8 69 31 41 00       	call   0x89120c
  47e0a3:	83 c4 04             	add    esp,0x4
  47e0a6:	c6 84 24 08 01 00 00 	mov    BYTE PTR [esp+0x108],0x0
  47e0ad:	00 
  47e0ae:	89 7c 24 58          	mov    DWORD PTR [esp+0x58],edi
  47e0b2:	c7 44 24 54 00 00 00 	mov    DWORD PTR [esp+0x54],0x0
  47e0b9:	00 
  47e0ba:	c6 44 24 44 00       	mov    BYTE PTR [esp+0x44],0x0
  47e0bf:	39 74 24 74          	cmp    DWORD PTR [esp+0x74],esi
  47e0c3:	72 0d                	jb     0x47e0d2
  47e0c5:	8b 4c 24 60          	mov    ecx,DWORD PTR [esp+0x60]
  47e0c9:	51                   	push   ecx
  47e0ca:	e8 3d 31 41 00       	call   0x89120c
  47e0cf:	83 c4 04             	add    esp,0x4
  47e0d2:	8b 44 24 10          	mov    eax,DWORD PTR [esp+0x10]
  47e0d6:	bf 78 33 c0 00       	mov    edi,0xc03378
  47e0db:	e8 80 02 2b 00       	call   0x72e360
  47e0e0:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  47e0e4:	85 c0                	test   eax,eax
  47e0e6:	0f 84 9e 03 00 00    	je     0x47e48a
  47e0ec:	8d 64 24 00          	lea    esp,[esp+0x0]
```

### N04. SCENARIO questId child search and SCENE hierarchy

- VA `0x47E0F0..0x47E1AB`; raw `0x7D4F0..0x7D5AB`; `187` bytes; SHA256 `fb1ce00c07537ac5e4d5d4879409d676993cbe8596390bdb885de36dc583734f`.

```asm
0047e0f0 <.data+0x7d4f0>:
  47e0f0:	33 db                	xor    ebx,ebx
  47e0f2:	89 5c 24 48          	mov    DWORD PTR [esp+0x48],ebx
  47e0f6:	89 5c 24 4c          	mov    DWORD PTR [esp+0x4c],ebx
  47e0fa:	89 5c 24 50          	mov    DWORD PTR [esp+0x50],ebx
  47e0fe:	8b 7c 24 20          	mov    edi,DWORD PTR [esp+0x20]
  47e102:	83 c7 44             	add    edi,0x44
  47e105:	c6 84 24 08 01 00 00 	mov    BYTE PTR [esp+0x108],0x4
  47e10c:	04 
  47e10d:	8b 77 50             	mov    esi,DWORD PTR [edi+0x50]
  47e110:	3b f7                	cmp    esi,edi
  47e112:	74 28                	je     0x47e13c
  47e114:	83 7e 28 10          	cmp    DWORD PTR [esi+0x28],0x10
  47e118:	8d 46 14             	lea    eax,[esi+0x14]
  47e11b:	72 02                	jb     0x47e11f
  47e11d:	8b 00                	mov    eax,DWORD PTR [eax]
  47e11f:	68 84 33 c0 00       	push   0xc03384
  47e124:	50                   	push   eax
  47e125:	e8 87 5b 41 00       	call   0x893cb1
  47e12a:	83 c4 08             	add    esp,0x8
  47e12d:	85 c0                	test   eax,eax
  47e12f:	0f 84 da 00 00 00    	je     0x47e20f
  47e135:	8b 76 50             	mov    esi,DWORD PTR [esi+0x50]
  47e138:	3b f7                	cmp    esi,edi
  47e13a:	75 d8                	jne    0x47e114
  47e13c:	c7 44 24 1c 00 00 00 	mov    DWORD PTR [esp+0x1c],0x0
  47e143:	00 
  47e144:	8b 54 24 1c          	mov    edx,DWORD PTR [esp+0x1c]
  47e148:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  47e14c:	bf 8c 33 c0 00       	mov    edi,0xc0338c
  47e151:	89 54 24 14          	mov    DWORD PTR [esp+0x14],edx
  47e155:	e8 06 02 2b 00       	call   0x72e360
  47e15a:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  47e15e:	85 c0                	test   eax,eax
  47e160:	0f 84 ac 01 00 00    	je     0x47e312
  47e166:	eb 08                	jmp    0x47e170
  47e168:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  47e16f:	90                   	nop
  47e170:	8b 7c 24 28          	mov    edi,DWORD PTR [esp+0x28]
  47e174:	8b b7 94 00 00 00    	mov    esi,DWORD PTR [edi+0x94]
  47e17a:	83 c7 44             	add    edi,0x44
  47e17d:	3b f7                	cmp    esi,edi
  47e17f:	74 28                	je     0x47e1a9
  47e181:	83 7e 28 10          	cmp    DWORD PTR [esi+0x28],0x10
  47e185:	8d 46 14             	lea    eax,[esi+0x14]
  47e188:	72 02                	jb     0x47e18c
  47e18a:	8b 00                	mov    eax,DWORD PTR [eax]
  47e18c:	68 94 33 c0 00       	push   0xc03394
  47e191:	50                   	push   eax
  47e192:	e8 1a 5b 41 00       	call   0x893cb1
  47e197:	83 c4 08             	add    esp,0x8
  47e19a:	85 c0                	test   eax,eax
  47e19c:	0f 84 9a 00 00 00    	je     0x47e23c
  47e1a2:	8b 76 50             	mov    esi,DWORD PTR [esi+0x50]
  47e1a5:	3b f7                	cmp    esi,edi
  47e1a7:	75 d8                	jne    0x47e181
  47e1a9:	33 ff                	xor    edi,edi
```

### N05. SCENE sceneIdx and vector growth; first branch

- VA `0x47E1AB..0x47E312`; raw `0x7D5AB..0x7D712`; `359` bytes; SHA256 `85ca20e3037d5081ae3d891b7dcd3fe2db16620d6dbed0316cae9005155d55cf`.

```asm
0047e1ab <.data+0x7d5ab>:
  47e1ab:	8b 54 24 48          	mov    edx,DWORD PTR [esp+0x48]
  47e1af:	8d 44 24 24          	lea    eax,[esp+0x24]
  47e1b3:	89 7c 24 24          	mov    DWORD PTR [esp+0x24],edi
  47e1b7:	3b c3                	cmp    eax,ebx
  47e1b9:	0f 83 cc 00 00 00    	jae    0x47e28b
  47e1bf:	8b c8                	mov    ecx,eax
  47e1c1:	3b d1                	cmp    edx,ecx
  47e1c3:	0f 87 c2 00 00 00    	ja     0x47e28b
  47e1c9:	8b 4c 24 50          	mov    ecx,DWORD PTR [esp+0x50]
  47e1cd:	8b f8                	mov    edi,eax
  47e1cf:	2b fa                	sub    edi,edx
  47e1d1:	c1 ff 02             	sar    edi,0x2
  47e1d4:	3b d9                	cmp    ebx,ecx
  47e1d6:	0f 85 a4 00 00 00    	jne    0x47e280
  47e1dc:	8b c3                	mov    eax,ebx
  47e1de:	2b c2                	sub    eax,edx
  47e1e0:	c1 f8 02             	sar    eax,0x2
  47e1e3:	3d fe ff ff 3f       	cmp    eax,0x3ffffffe
  47e1e8:	0f 87 87 03 00 00    	ja     0x47e575
  47e1ee:	2b ca                	sub    ecx,edx
  47e1f0:	40                   	inc    eax
  47e1f1:	c1 f9 02             	sar    ecx,0x2
  47e1f4:	3b c1                	cmp    eax,ecx
  47e1f6:	0f 86 84 00 00 00    	jbe    0x47e280
  47e1fc:	8b d1                	mov    edx,ecx
  47e1fe:	d1 ea                	shr    edx,1
  47e200:	be ff ff ff 3f       	mov    esi,0x3fffffff
  47e205:	2b f2                	sub    esi,edx
  47e207:	3b f1                	cmp    esi,ecx
  47e209:	73 5c                	jae    0x47e267
  47e20b:	33 c9                	xor    ecx,ecx
  47e20d:	eb 5a                	jmp    0x47e269
  47e20f:	85 f6                	test   esi,esi
  47e211:	0f 84 25 ff ff ff    	je     0x47e13c
  47e217:	83 c6 30             	add    esi,0x30
  47e21a:	83 7e 14 10          	cmp    DWORD PTR [esi+0x14],0x10
  47e21e:	72 02                	jb     0x47e222
  47e220:	8b 36                	mov    esi,DWORD PTR [esi]
  47e222:	85 f6                	test   esi,esi
  47e224:	0f 84 12 ff ff ff    	je     0x47e13c
  47e22a:	56                   	push   esi
  47e22b:	e8 84 35 41 00       	call   0x8917b4
  47e230:	83 c4 04             	add    esp,0x4
  47e233:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  47e237:	e9 08 ff ff ff       	jmp    0x47e144
  47e23c:	85 f6                	test   esi,esi
  47e23e:	0f 84 65 ff ff ff    	je     0x47e1a9
  47e244:	83 7e 44 10          	cmp    DWORD PTR [esi+0x44],0x10
  47e248:	8d 46 30             	lea    eax,[esi+0x30]
  47e24b:	72 02                	jb     0x47e24f
  47e24d:	8b 00                	mov    eax,DWORD PTR [eax]
  47e24f:	85 c0                	test   eax,eax
  47e251:	0f 84 52 ff ff ff    	je     0x47e1a9
  47e257:	50                   	push   eax
  47e258:	e8 57 35 41 00       	call   0x8917b4
  47e25d:	83 c4 04             	add    esp,0x4
  47e260:	8b f8                	mov    edi,eax
  47e262:	e9 44 ff ff ff       	jmp    0x47e1ab
  47e267:	03 ca                	add    ecx,edx
  47e269:	3b c8                	cmp    ecx,eax
  47e26b:	0f 42 c8             	cmovb  ecx,eax
  47e26e:	51                   	push   ecx
  47e26f:	8d 74 24 4c          	lea    esi,[esp+0x4c]
  47e273:	e8 08 97 31 00       	call   0x797980
  47e278:	8b 5c 24 4c          	mov    ebx,DWORD PTR [esp+0x4c]
  47e27c:	8b 54 24 48          	mov    edx,DWORD PTR [esp+0x48]
  47e280:	85 db                	test   ebx,ebx
  47e282:	74 59                	je     0x47e2dd
  47e284:	8b 14 ba             	mov    edx,DWORD PTR [edx+edi*4]
  47e287:	89 13                	mov    DWORD PTR [ebx],edx
  47e289:	eb 52                	jmp    0x47e2dd
  47e28b:	8b 4c 24 50          	mov    ecx,DWORD PTR [esp+0x50]
  47e28f:	3b d9                	cmp    ebx,ecx
  47e291:	75 44                	jne    0x47e2d7
  47e293:	8b c3                	mov    eax,ebx
  47e295:	2b c2                	sub    eax,edx
  47e297:	c1 f8 02             	sar    eax,0x2
  47e29a:	3d fe ff ff 3f       	cmp    eax,0x3ffffffe
  47e29f:	0f 87 d0 02 00 00    	ja     0x47e575
  47e2a5:	2b ca                	sub    ecx,edx
  47e2a7:	40                   	inc    eax
  47e2a8:	c1 f9 02             	sar    ecx,0x2
  47e2ab:	3b c1                	cmp    eax,ecx
  47e2ad:	76 28                	jbe    0x47e2d7
  47e2af:	8b d1                	mov    edx,ecx
  47e2b1:	d1 ea                	shr    edx,1
  47e2b3:	be ff ff ff 3f       	mov    esi,0x3fffffff
  47e2b8:	2b f2                	sub    esi,edx
  47e2ba:	3b f1                	cmp    esi,ecx
  47e2bc:	73 04                	jae    0x47e2c2
  47e2be:	33 c9                	xor    ecx,ecx
  47e2c0:	eb 02                	jmp    0x47e2c4
  47e2c2:	03 ca                	add    ecx,edx
  47e2c4:	3b c8                	cmp    ecx,eax
  47e2c6:	0f 42 c8             	cmovb  ecx,eax
  47e2c9:	51                   	push   ecx
  47e2ca:	8d 74 24 4c          	lea    esi,[esp+0x4c]
  47e2ce:	e8 ad 96 31 00       	call   0x797980
  47e2d3:	8b 5c 24 4c          	mov    ebx,DWORD PTR [esp+0x4c]
  47e2d7:	85 db                	test   ebx,ebx
  47e2d9:	74 02                	je     0x47e2dd
  47e2db:	89 3b                	mov    DWORD PTR [ebx],edi
  47e2dd:	8b 44 24 28          	mov    eax,DWORD PTR [esp+0x28]
  47e2e1:	8b 70 40             	mov    esi,DWORD PTR [eax+0x40]
  47e2e4:	83 c3 04             	add    ebx,0x4
  47e2e7:	89 5c 24 4c          	mov    DWORD PTR [esp+0x4c],ebx
  47e2eb:	85 f6                	test   esi,esi
  47e2ed:	74 15                	je     0x47e304
  47e2ef:	90                   	nop
  47e2f0:	8b 16                	mov    edx,DWORD PTR [esi]
  47e2f2:	8b 42 18             	mov    eax,DWORD PTR [edx+0x18]
  47e2f5:	8b ce                	mov    ecx,esi
  47e2f7:	ff d0                	call   eax
  47e2f9:	85 c0                	test   eax,eax
  47e2fb:	75 70                	jne    0x47e36d
  47e2fd:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  47e300:	85 f6                	test   esi,esi
  47e302:	75 ec                	jne    0x47e2f0
  47e304:	33 c0                	xor    eax,eax
  47e306:	89 44 24 28          	mov    DWORD PTR [esp+0x28],eax
  47e30a:	85 c0                	test   eax,eax
  47e30c:	0f 85 5e fe ff ff    	jne    0x47e170
```

### N06. SCENARIO questId list insert; distinct vector from sceneIdx

- VA `0x47E312..0x47E3F7`; raw `0x7D712..0x7D7F7`; `229` bytes; SHA256 `8436b868a1b01d84a02e3fed3ed1a807500ee1404823f2797f8dc723a7818ee4`.

```asm
0047e312 <.data+0x7d712>:
  47e312:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  47e316:	8b 46 28             	mov    eax,DWORD PTR [esi+0x28]
  47e319:	8b 7c 24 1c          	mov    edi,DWORD PTR [esp+0x1c]
  47e31d:	83 c6 24             	add    esi,0x24
  47e320:	8d 4c 24 14          	lea    ecx,[esp+0x14]
  47e324:	89 7c 24 44          	mov    DWORD PTR [esp+0x44],edi
  47e328:	3b c8                	cmp    ecx,eax
  47e32a:	73 6b                	jae    0x47e397
  47e32c:	8b 16                	mov    edx,DWORD PTR [esi]
  47e32e:	3b d1                	cmp    edx,ecx
  47e330:	77 65                	ja     0x47e397
  47e332:	8b f9                	mov    edi,ecx
  47e334:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  47e337:	2b fa                	sub    edi,edx
  47e339:	c1 ff 02             	sar    edi,0x2
  47e33c:	3b c1                	cmp    eax,ecx
  47e33e:	75 45                	jne    0x47e385
  47e340:	2b c2                	sub    eax,edx
  47e342:	c1 f8 02             	sar    eax,0x2
  47e345:	3d fe ff ff 3f       	cmp    eax,0x3ffffffe
  47e34a:	0f 87 25 02 00 00    	ja     0x47e575
  47e350:	2b ca                	sub    ecx,edx
  47e352:	40                   	inc    eax
  47e353:	c1 f9 02             	sar    ecx,0x2
  47e356:	3b c1                	cmp    eax,ecx
  47e358:	76 2b                	jbe    0x47e385
  47e35a:	8b d1                	mov    edx,ecx
  47e35c:	d1 ea                	shr    edx,1
  47e35e:	bb ff ff ff 3f       	mov    ebx,0x3fffffff
  47e363:	2b da                	sub    ebx,edx
  47e365:	3b d9                	cmp    ebx,ecx
  47e367:	73 0f                	jae    0x47e378
  47e369:	33 c9                	xor    ecx,ecx
  47e36b:	eb 0d                	jmp    0x47e37a
  47e36d:	8b 16                	mov    edx,DWORD PTR [esi]
  47e36f:	8b 42 18             	mov    eax,DWORD PTR [edx+0x18]
  47e372:	8b ce                	mov    ecx,esi
  47e374:	ff d0                	call   eax
  47e376:	eb 8e                	jmp    0x47e306
  47e378:	03 ca                	add    ecx,edx
  47e37a:	3b c8                	cmp    ecx,eax
  47e37c:	0f 42 c8             	cmovb  ecx,eax
  47e37f:	51                   	push   ecx
  47e380:	e8 fb 95 31 00       	call   0x797980
  47e385:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  47e388:	8b 16                	mov    edx,DWORD PTR [esi]
  47e38a:	8d 3c ba             	lea    edi,[edx+edi*4]
  47e38d:	85 c0                	test   eax,eax
  47e38f:	74 52                	je     0x47e3e3
  47e391:	8b 0f                	mov    ecx,DWORD PTR [edi]
  47e393:	89 08                	mov    DWORD PTR [eax],ecx
  47e395:	eb 4c                	jmp    0x47e3e3
  47e397:	8b 4e 08             	mov    ecx,DWORD PTR [esi+0x8]
  47e39a:	3b c1                	cmp    eax,ecx
  47e39c:	75 3c                	jne    0x47e3da
  47e39e:	8b 16                	mov    edx,DWORD PTR [esi]
  47e3a0:	2b c2                	sub    eax,edx
  47e3a2:	c1 f8 02             	sar    eax,0x2
  47e3a5:	3d fe ff ff 3f       	cmp    eax,0x3ffffffe
  47e3aa:	0f 87 c5 01 00 00    	ja     0x47e575
  47e3b0:	2b ca                	sub    ecx,edx
  47e3b2:	40                   	inc    eax
  47e3b3:	c1 f9 02             	sar    ecx,0x2
  47e3b6:	3b c1                	cmp    eax,ecx
  47e3b8:	76 20                	jbe    0x47e3da
  47e3ba:	8b d1                	mov    edx,ecx
  47e3bc:	d1 ea                	shr    edx,1
  47e3be:	bb ff ff ff 3f       	mov    ebx,0x3fffffff
  47e3c3:	2b da                	sub    ebx,edx
  47e3c5:	3b d9                	cmp    ebx,ecx
  47e3c7:	73 04                	jae    0x47e3cd
  47e3c9:	33 c9                	xor    ecx,ecx
  47e3cb:	eb 02                	jmp    0x47e3cf
  47e3cd:	03 ca                	add    ecx,edx
  47e3cf:	3b c8                	cmp    ecx,eax
  47e3d1:	0f 42 c8             	cmovb  ecx,eax
  47e3d4:	51                   	push   ecx
  47e3d5:	e8 a6 95 31 00       	call   0x797980
  47e3da:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  47e3dd:	85 c0                	test   eax,eax
  47e3df:	74 02                	je     0x47e3e3
  47e3e1:	89 38                	mov    DWORD PTR [eax],edi
  47e3e3:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  47e3e7:	83 46 04 04          	add    DWORD PTR [esi+0x4],0x4
  47e3eb:	8d 54 24 48          	lea    edx,[esp+0x48]
  47e3ef:	89 44 24 60          	mov    DWORD PTR [esp+0x60],eax
  47e3f3:	89 44 24 64          	mov    DWORD PTR [esp+0x64],eax
```

### N07. sceneIdx materialized + chapter record+0x34 and index insertion

- VA `0x47E3F7..0x47E4DE`; raw `0x7D7F7..0x7D8DE`; `231` bytes; SHA256 `a4c5bda48acc14883cd26fbb9dc37313bd304f2252f792bffbc24a25c974ef31`.

```asm
0047e3f7 <.data+0x7d7f7>:
  47e3f7:	52                   	push   edx
  47e3f8:	8d 44 24 6c          	lea    eax,[esp+0x6c]
  47e3fc:	50                   	push   eax
  47e3fd:	e8 8e a6 36 00       	call   0x7e8a90
  47e402:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  47e406:	8d 4c 24 60          	lea    ecx,[esp+0x60]
  47e40a:	83 c6 34             	add    esi,0x34
  47e40d:	51                   	push   ecx
  47e40e:	8b ce                	mov    ecx,esi
  47e410:	c6 84 24 0c 01 00 00 	mov    BYTE PTR [esp+0x10c],0x5
  47e417:	05 
  47e418:	e8 73 09 00 00       	call   0x47ed90
  47e41d:	8d 54 24 34          	lea    edx,[esp+0x34]
  47e421:	52                   	push   edx
  47e422:	56                   	push   esi
  47e423:	e8 f8 06 00 00       	call   0x47eb20
  47e428:	8b 44 24 68          	mov    eax,DWORD PTR [esp+0x68]
  47e42c:	85 c0                	test   eax,eax
  47e42e:	74 09                	je     0x47e439
  47e430:	50                   	push   eax
  47e431:	e8 d6 2d 41 00       	call   0x89120c
  47e436:	83 c4 04             	add    esp,0x4
  47e439:	c6 84 24 08 01 00 00 	mov    BYTE PTR [esp+0x108],0x0
  47e440:	00 
  47e441:	8b 44 24 48          	mov    eax,DWORD PTR [esp+0x48]
  47e445:	85 c0                	test   eax,eax
  47e447:	74 09                	je     0x47e452
  47e449:	50                   	push   eax
  47e44a:	e8 bd 2d 41 00       	call   0x89120c
  47e44f:	83 c4 04             	add    esp,0x4
  47e452:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  47e456:	8b 70 40             	mov    esi,DWORD PTR [eax+0x40]
  47e459:	85 f6                	test   esi,esi
  47e45b:	74 1b                	je     0x47e478
  47e45d:	8d 49 00             	lea    ecx,[ecx+0x0]
  47e460:	8b 16                	mov    edx,DWORD PTR [esi]
  47e462:	8b 42 18             	mov    eax,DWORD PTR [edx+0x18]
  47e465:	8b ce                	mov    ecx,esi
  47e467:	ff d0                	call   eax
  47e469:	85 c0                	test   eax,eax
  47e46b:	0f 85 e8 00 00 00    	jne    0x47e559
  47e471:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  47e474:	85 f6                	test   esi,esi
  47e476:	75 e8                	jne    0x47e460
  47e478:	33 c0                	xor    eax,eax
  47e47a:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  47e47e:	85 c0                	test   eax,eax
  47e480:	0f 85 6a fc ff ff    	jne    0x47e0f0
  47e486:	8b 5c 24 18          	mov    ebx,DWORD PTR [esp+0x18]
  47e48a:	8b 0b                	mov    ecx,DWORD PTR [ebx]
  47e48c:	8d 7c 24 2c          	lea    edi,[esp+0x2c]
  47e490:	be 68 0f fc 00       	mov    esi,0xfc0f68
  47e495:	89 4c 24 2c          	mov    DWORD PTR [esp+0x2c],ecx
  47e499:	89 5c 24 30          	mov    DWORD PTR [esp+0x30],ebx
  47e49d:	e8 7e 0a 10 00       	call   0x57ef20
  47e4a2:	50                   	push   eax
  47e4a3:	56                   	push   esi
  47e4a4:	8d 74 24 44          	lea    esi,[esp+0x44]
  47e4a8:	e8 a3 03 10 00       	call   0x57e850
  47e4ad:	8b 54 24 10          	mov    edx,DWORD PTR [esp+0x10]
  47e4b1:	8b 72 40             	mov    esi,DWORD PTR [edx+0x40]
  47e4b4:	85 f6                	test   esi,esi
  47e4b6:	74 18                	je     0x47e4d0
  47e4b8:	8b 06                	mov    eax,DWORD PTR [esi]
  47e4ba:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  47e4bd:	8b ce                	mov    ecx,esi
  47e4bf:	ff d2                	call   edx
  47e4c1:	85 c0                	test   eax,eax
  47e4c3:	0f 85 9e 00 00 00    	jne    0x47e567
  47e4c9:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  47e4cc:	85 f6                	test   esi,esi
  47e4ce:	75 e8                	jne    0x47e4b8
  47e4d0:	33 c0                	xor    eax,eax
  47e4d2:	89 44 24 10          	mov    DWORD PTR [esp+0x10],eax
  47e4d6:	85 c0                	test   eax,eax
  47e4d8:	0f 85 c2 fa ff ff    	jne    0x47dfa0
```

### N08. final tree insertion/cleanup/failure branch for Table SceneList

- VA `0x47E4DE..0x47E575`; raw `0x7D8DE..0x7D975`; `151` bytes; SHA256 `89ec400a76374569ab9431eeb9b314235d3ae46aa874ef4f6b87ac48d88a417e`.

```asm
0047e4de <.data+0x7d8de>:
  47e4de:	33 db                	xor    ebx,ebx
  47e4e0:	c7 84 24 08 01 00 00 	mov    DWORD PTR [esp+0x108],0xffffffff
  47e4e7:	ff ff ff ff 
  47e4eb:	83 bc 24 dc 00 00 00 	cmp    DWORD PTR [esp+0xdc],0x10
  47e4f2:	10 
  47e4f3:	c7 44 24 7c 94 23 bf 	mov    DWORD PTR [esp+0x7c],0xbf2394
  47e4fa:	00 
  47e4fb:	72 10                	jb     0x47e50d
  47e4fd:	8b 84 24 c8 00 00 00 	mov    eax,DWORD PTR [esp+0xc8]
  47e504:	50                   	push   eax
  47e505:	e8 02 2d 41 00       	call   0x89120c
  47e50a:	83 c4 04             	add    esp,0x4
  47e50d:	8d 4c 24 7c          	lea    ecx,[esp+0x7c]
  47e511:	c7 84 24 dc 00 00 00 	mov    DWORD PTR [esp+0xdc],0xf
  47e518:	0f 00 00 00 
  47e51c:	89 9c 24 d8 00 00 00 	mov    DWORD PTR [esp+0xd8],ebx
  47e523:	c6 84 24 c8 00 00 00 	mov    BYTE PTR [esp+0xc8],0x0
  47e52a:	00 
  47e52b:	e8 10 fb 2a 00       	call   0x72e040
  47e530:	b8 01 00 00 00       	mov    eax,0x1
  47e535:	8b 8c 24 00 01 00 00 	mov    ecx,DWORD PTR [esp+0x100]
  47e53c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47e543:	59                   	pop    ecx
  47e544:	5f                   	pop    edi
  47e545:	5e                   	pop    esi
  47e546:	5b                   	pop    ebx
  47e547:	8b 8c 24 e8 00 00 00 	mov    ecx,DWORD PTR [esp+0xe8]
  47e54e:	33 cc                	xor    ecx,esp
  47e550:	e8 ac 2a 41 00       	call   0x891001
  47e555:	8b e5                	mov    esp,ebp
  47e557:	5d                   	pop    ebp
  47e558:	c3                   	ret
  47e559:	8b 16                	mov    edx,DWORD PTR [esi]
  47e55b:	8b 42 18             	mov    eax,DWORD PTR [edx+0x18]
  47e55e:	8b ce                	mov    ecx,esi
  47e560:	ff d0                	call   eax
  47e562:	e9 13 ff ff ff       	jmp    0x47e47a
  47e567:	8b 06                	mov    eax,DWORD PTR [esi]
  47e569:	8b 50 18             	mov    edx,DWORD PTR [eax+0x18]
  47e56c:	8b ce                	mov    ecx,esi
  47e56e:	ff d2                	call   edx
  47e570:	e9 5d ff ff ff       	jmp    0x47e4d2
```

### N09. Chapter row allocation and native record layout initialization

- VA `0x47E580..0x47E635`; raw `0x7D980..0x7DA35`; `181` bytes; SHA256 `88f1796256832c94911b7d55b73f1d39d3a4b7cc7ff320d3fbed802dc902fab0`.

```asm
0047e580 <.data+0x7d980>:
  47e580:	55                   	push   ebp
  47e581:	8b ec                	mov    ebp,esp
  47e583:	6a ff                	push   0xffffffff
  47e585:	68 46 b6 90 00       	push   0x90b646
  47e58a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47e590:	50                   	push   eax
  47e591:	83 ec 10             	sub    esp,0x10
  47e594:	56                   	push   esi
  47e595:	57                   	push   edi
  47e596:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47e59b:	33 c5                	xor    eax,ebp
  47e59d:	50                   	push   eax
  47e59e:	8d 45 f4             	lea    eax,[ebp-0xc]
  47e5a1:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47e5a7:	8b 75 08             	mov    esi,DWORD PTR [ebp+0x8]
  47e5aa:	33 ff                	xor    edi,edi
  47e5ac:	33 c0                	xor    eax,eax
  47e5ae:	c7 46 1c 07 00 00 00 	mov    DWORD PTR [esi+0x1c],0x7
  47e5b5:	89 7e 18             	mov    DWORD PTR [esi+0x18],edi
  47e5b8:	66 89 46 08          	mov    WORD PTR [esi+0x8],ax
  47e5bc:	89 7d fc             	mov    DWORD PTR [ebp-0x4],edi
  47e5bf:	89 7e 24             	mov    DWORD PTR [esi+0x24],edi
  47e5c2:	89 7e 28             	mov    DWORD PTR [esi+0x28],edi
  47e5c5:	89 7e 2c             	mov    DWORD PTR [esi+0x2c],edi
  47e5c8:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  47e5cc:	6a 28                	push   0x28
  47e5ce:	89 7e 3c             	mov    DWORD PTR [esi+0x3c],edi
  47e5d1:	e8 92 2c 41 00       	call   0x891268
  47e5d6:	83 c4 04             	add    esp,0x4
  47e5d9:	3b c7                	cmp    eax,edi
  47e5db:	74 34                	je     0x47e611
  47e5dd:	89 46 38             	mov    DWORD PTR [esi+0x38],eax
  47e5e0:	89 00                	mov    DWORD PTR [eax],eax
  47e5e2:	8b 46 38             	mov    eax,DWORD PTR [esi+0x38]
  47e5e5:	89 40 04             	mov    DWORD PTR [eax+0x4],eax
  47e5e8:	8b 46 38             	mov    eax,DWORD PTR [esi+0x38]
  47e5eb:	89 40 08             	mov    DWORD PTR [eax+0x8],eax
  47e5ee:	8b 4e 38             	mov    ecx,DWORD PTR [esi+0x38]
  47e5f1:	c6 41 24 01          	mov    BYTE PTR [ecx+0x24],0x1
  47e5f5:	8b 56 38             	mov    edx,DWORD PTR [esi+0x38]
  47e5f8:	c6 42 25 01          	mov    BYTE PTR [edx+0x25],0x1
  47e5fc:	8b c6                	mov    eax,esi
  47e5fe:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47e601:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47e608:	59                   	pop    ecx
  47e609:	5f                   	pop    edi
  47e60a:	5e                   	pop    esi
  47e60b:	8b e5                	mov    esp,ebp
  47e60d:	5d                   	pop    ebp
  47e60e:	c2 04 00             	ret    0x4
  47e611:	8d 45 f0             	lea    eax,[ebp-0x10]
  47e614:	50                   	push   eax
  47e615:	8d 4d e4             	lea    ecx,[ebp-0x1c]
  47e618:	89 7d f0             	mov    DWORD PTR [ebp-0x10],edi
  47e61b:	e8 89 2a 41 00       	call   0x8910a9
  47e620:	68 a8 57 c8 00       	push   0xc857a8
  47e625:	8d 4d e4             	lea    ecx,[ebp-0x1c]
  47e628:	51                   	push   ecx
  47e629:	c7 45 e4 a4 2c bd 00 	mov    DWORD PTR [ebp-0x1c],0xbd2ca4
  47e630:	e8 bb e3 41 00       	call   0x89c9f0
```

### N10. Controller NEXT scene selector: argument and ordered list lookup

- VA `0x47E640..0x47E6D9`; raw `0x7DA40..0x7DAD9`; `153` bytes; SHA256 `6ee4a4a301d411e580431ad8d6c10e1dcdfce1b838358a52d853ee60179b3d61`.

```asm
0047e640 <.data+0x7da40>:
  47e640:	55                   	push   ebp
  47e641:	8b ec                	mov    ebp,esp
  47e643:	6a ff                	push   0xffffffff
  47e645:	68 b8 8a 90 00       	push   0x908ab8
  47e64a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47e650:	50                   	push   eax
  47e651:	83 ec 14             	sub    esp,0x14
  47e654:	53                   	push   ebx
  47e655:	56                   	push   esi
  47e656:	57                   	push   edi
  47e657:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47e65c:	33 c5                	xor    eax,ebp
  47e65e:	50                   	push   eax
  47e65f:	8d 45 f4             	lea    eax,[ebp-0xc]
  47e662:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47e668:	8b 5d 10             	mov    ebx,DWORD PTR [ebp+0x10]
  47e66b:	83 7d 0c 00          	cmp    DWORD PTR [ebp+0xc],0x0
  47e66f:	0f 84 86 00 00 00    	je     0x47e6fb
  47e675:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47e678:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  47e67b:	8b 07                	mov    eax,DWORD PTR [edi]
  47e67d:	89 45 10             	mov    DWORD PTR [ebp+0x10],eax
  47e680:	3b c7                	cmp    eax,edi
  47e682:	74 77                	je     0x47e6fb
  47e684:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  47e687:	8d 4d 0c             	lea    ecx,[ebp+0xc]
  47e68a:	51                   	push   ecx
  47e68b:	8d 4e 34             	lea    ecx,[esi+0x34]
  47e68e:	8d 45 08             	lea    eax,[ebp+0x8]
  47e691:	e8 3a e8 0a 00       	call   0x52ced0
  47e696:	8b 76 38             	mov    esi,DWORD PTR [esi+0x38]
  47e699:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47e69c:	3b c6                	cmp    eax,esi
  47e69e:	75 11                	jne    0x47e6b1
  47e6a0:	8d 45 10             	lea    eax,[ebp+0x10]
  47e6a3:	e8 f8 ff 01 00       	call   0x49e6a0
  47e6a8:	8b 45 10             	mov    eax,DWORD PTR [ebp+0x10]
  47e6ab:	3b c7                	cmp    eax,edi
  47e6ad:	75 d5                	jne    0x47e684
  47e6af:	eb 4a                	jmp    0x47e6fb
  47e6b1:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  47e6b4:	83 c0 14             	add    eax,0x14
  47e6b7:	50                   	push   eax
  47e6b8:	8d 45 e4             	lea    eax,[ebp-0x1c]
  47e6bb:	50                   	push   eax
  47e6bc:	89 55 e0             	mov    DWORD PTR [ebp-0x20],edx
  47e6bf:	e8 cc a3 36 00       	call   0x7e8a90
  47e6c4:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47e6cb:	8b 4d e8             	mov    ecx,DWORD PTR [ebp-0x18]
  47e6ce:	8b 55 e4             	mov    edx,DWORD PTR [ebp-0x1c]
  47e6d1:	2b ca                	sub    ecx,edx
  47e6d3:	c1 f9 02             	sar    ecx,0x2
  47e6d6:	8d 71 ff             	lea    esi,[ecx-0x1]
```

### N11. NEXT scene selector miss/advance and zero vs next result

- VA `0x47E6D9..0x47E746`; raw `0x7DAD9..0x7DB46`; `109` bytes; SHA256 `8cdc1c157eb94163974a693faa3ff6bbef987820d31975a7265c2266d5511061`.

```asm
0047e6d9 <.data+0x7dad9>:
  47e6d9:	33 c0                	xor    eax,eax
  47e6db:	85 f6                	test   esi,esi
  47e6dd:	74 0f                	je     0x47e6ee
  47e6df:	90                   	nop
  47e6e0:	3b c8                	cmp    ecx,eax
  47e6e2:	76 32                	jbe    0x47e716
  47e6e4:	3b 1c 82             	cmp    ebx,DWORD PTR [edx+eax*4]
  47e6e7:	74 28                	je     0x47e711
  47e6e9:	40                   	inc    eax
  47e6ea:	3b c6                	cmp    eax,esi
  47e6ec:	72 f2                	jb     0x47e6e0
  47e6ee:	85 d2                	test   edx,edx
  47e6f0:	74 09                	je     0x47e6fb
  47e6f2:	52                   	push   edx
  47e6f3:	e8 14 2b 41 00       	call   0x89120c
  47e6f8:	83 c4 04             	add    esp,0x4
  47e6fb:	33 c0                	xor    eax,eax
  47e6fd:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47e700:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47e707:	59                   	pop    ecx
  47e708:	5f                   	pop    edi
  47e709:	5e                   	pop    esi
  47e70a:	5b                   	pop    ebx
  47e70b:	8b e5                	mov    esp,ebp
  47e70d:	5d                   	pop    ebp
  47e70e:	c2 0c 00             	ret    0xc
  47e711:	40                   	inc    eax
  47e712:	3b c8                	cmp    ecx,eax
  47e714:	77 0a                	ja     0x47e720
  47e716:	68 08 34 bf 00       	push   0xbf3408
  47e71b:	e8 5d f4 3f 00       	call   0x87db7d
  47e720:	8b 34 82             	mov    esi,DWORD PTR [edx+eax*4]
  47e723:	85 d2                	test   edx,edx
  47e725:	74 09                	je     0x47e730
  47e727:	52                   	push   edx
  47e728:	e8 df 2a 41 00       	call   0x89120c
  47e72d:	83 c4 04             	add    esp,0x4
  47e730:	8b c6                	mov    eax,esi
  47e732:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47e735:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47e73c:	59                   	pop    ecx
  47e73d:	5f                   	pop    edi
  47e73e:	5e                   	pop    esi
  47e73f:	5b                   	pop    ebx
  47e740:	8b e5                	mov    esp,ebp
  47e742:	5d                   	pop    ebp
  47e743:	c2 0c 00             	ret    0xc
```

### N12. FIRST scene selector per chapter key; ordered search

- VA `0x47E890..0x47E941`; raw `0x7DC90..0x7DD41`; `177` bytes; SHA256 `efb491d30f56cfab505da3bc207de37af28c681a1b64b17d168790a62bf992d4`.

```asm
0047e890 <.data+0x7dc90>:
  47e890:	55                   	push   ebp
  47e891:	8b ec                	mov    ebp,esp
  47e893:	6a ff                	push   0xffffffff
  47e895:	68 b8 8a 90 00       	push   0x908ab8
  47e89a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47e8a0:	50                   	push   eax
  47e8a1:	83 ec 14             	sub    esp,0x14
  47e8a4:	53                   	push   ebx
  47e8a5:	56                   	push   esi
  47e8a6:	57                   	push   edi
  47e8a7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47e8ac:	33 c5                	xor    eax,ebp
  47e8ae:	50                   	push   eax
  47e8af:	8d 45 f4             	lea    eax,[ebp-0xc]
  47e8b2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47e8b8:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47e8bb:	8b 58 04             	mov    ebx,DWORD PTR [eax+0x4]
  47e8be:	8b 33                	mov    esi,DWORD PTR [ebx]
  47e8c0:	3b f3                	cmp    esi,ebx
  47e8c2:	74 67                	je     0x47e92b
  47e8c4:	8b 7e 10             	mov    edi,DWORD PTR [esi+0x10]
  47e8c7:	8d 4d 0c             	lea    ecx,[ebp+0xc]
  47e8ca:	51                   	push   ecx
  47e8cb:	8d 4f 34             	lea    ecx,[edi+0x34]
  47e8ce:	8d 45 08             	lea    eax,[ebp+0x8]
  47e8d1:	e8 fa e5 0a 00       	call   0x52ced0
  47e8d6:	8b 7f 38             	mov    edi,DWORD PTR [edi+0x38]
  47e8d9:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47e8dc:	3b c7                	cmp    eax,edi
  47e8de:	75 61                	jne    0x47e941
  47e8e0:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  47e8e4:	75 41                	jne    0x47e927
  47e8e6:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  47e8e9:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  47e8ed:	75 1d                	jne    0x47e90c
  47e8ef:	8b f0                	mov    esi,eax
  47e8f1:	8b 06                	mov    eax,DWORD PTR [esi]
  47e8f3:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  47e8f7:	75 2e                	jne    0x47e927
  47e8f9:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  47e900:	8b f0                	mov    esi,eax
  47e902:	8b 06                	mov    eax,DWORD PTR [esi]
  47e904:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  47e908:	74 f6                	je     0x47e900
  47e90a:	eb 1b                	jmp    0x47e927
  47e90c:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  47e90f:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  47e913:	75 10                	jne    0x47e925
  47e915:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  47e918:	75 0b                	jne    0x47e925
  47e91a:	8b f0                	mov    esi,eax
  47e91c:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  47e91f:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  47e923:	74 f0                	je     0x47e915
  47e925:	8b f0                	mov    esi,eax
  47e927:	3b f3                	cmp    esi,ebx
  47e929:	75 99                	jne    0x47e8c4
  47e92b:	33 c0                	xor    eax,eax
  47e92d:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47e930:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47e937:	59                   	pop    ecx
  47e938:	5f                   	pop    edi
  47e939:	5e                   	pop    esi
  47e93a:	5b                   	pop    ebx
  47e93b:	8b e5                	mov    esp,ebp
  47e93d:	5d                   	pop    ebp
  47e93e:	c2 08 00             	ret    0x8
```

### N13. FIRST scene result from chapter record+0x34; no-key=0

- VA `0x47E941..0x47E995`; raw `0x7DD41..0x7DD95`; `84` bytes; SHA256 `bf91b4849ca8461e739e25277e0f77897ef8d191f7af334b68c3336e3db826b7`.

```asm
0047e941 <.data+0x7dd41>:
  47e941:	8b 50 10             	mov    edx,DWORD PTR [eax+0x10]
  47e944:	83 c0 14             	add    eax,0x14
  47e947:	50                   	push   eax
  47e948:	8d 45 e4             	lea    eax,[ebp-0x1c]
  47e94b:	50                   	push   eax
  47e94c:	89 55 e0             	mov    DWORD PTR [ebp-0x20],edx
  47e94f:	e8 3c a1 36 00       	call   0x7e8a90
  47e954:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47e95b:	8b 4d e8             	mov    ecx,DWORD PTR [ebp-0x18]
  47e95e:	8b 45 e4             	mov    eax,DWORD PTR [ebp-0x1c]
  47e961:	2b c8                	sub    ecx,eax
  47e963:	c1 f9 02             	sar    ecx,0x2
  47e966:	85 c9                	test   ecx,ecx
  47e968:	75 0a                	jne    0x47e974
  47e96a:	68 08 34 bf 00       	push   0xbf3408
  47e96f:	e8 09 f2 3f 00       	call   0x87db7d
  47e974:	8b 30                	mov    esi,DWORD PTR [eax]
  47e976:	50                   	push   eax
  47e977:	e8 90 28 41 00       	call   0x89120c
  47e97c:	83 c4 04             	add    esp,0x4
  47e97f:	8b c6                	mov    eax,esi
  47e981:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47e984:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47e98b:	59                   	pop    ecx
  47e98c:	5f                   	pop    edi
  47e98d:	5e                   	pop    esi
  47e98e:	5b                   	pop    ebx
  47e98f:	8b e5                	mov    esp,ebp
  47e991:	5d                   	pop    ebp
  47e992:	c2 08 00             	ret    0x8
```

### N14. Map iterator drives chapter record into scene object

- VA `0x47D290..0x47D361`; raw `0x7C690..0x7C761`; `209` bytes; SHA256 `a982c45f40af8629732dd2dfa2b6449659e02387502fa714121c2c744ed78646`.

```asm
0047d290 <.data+0x7c690>:
  47d290:	55                   	push   ebp
  47d291:	8b ec                	mov    ebp,esp
  47d293:	6a ff                	push   0xffffffff
  47d295:	68 4e 41 93 00       	push   0x93414e
  47d29a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47d2a0:	50                   	push   eax
  47d2a1:	83 ec 08             	sub    esp,0x8
  47d2a4:	53                   	push   ebx
  47d2a5:	56                   	push   esi
  47d2a6:	57                   	push   edi
  47d2a7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47d2ac:	33 c5                	xor    eax,ebp
  47d2ae:	50                   	push   eax
  47d2af:	8d 45 f4             	lea    eax,[ebp-0xc]
  47d2b2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47d2b8:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  47d2bb:	8b 83 f8 00 00 00    	mov    eax,DWORD PTR [ebx+0xf8]
  47d2c1:	8b 80 cc 00 00 00    	mov    eax,DWORD PTR [eax+0xcc]
  47d2c7:	8b 8b 14 01 00 00    	mov    ecx,DWORD PTR [ebx+0x114]
  47d2cd:	85 c0                	test   eax,eax
  47d2cf:	74 07                	je     0x47d2d8
  47d2d1:	51                   	push   ecx
  47d2d2:	50                   	push   eax
  47d2d3:	e8 48 b6 f8 ff       	call   0x408920
  47d2d8:	8b 83 10 01 00 00    	mov    eax,DWORD PTR [ebx+0x110]
  47d2de:	8b 30                	mov    esi,DWORD PTR [eax]
  47d2e0:	33 d2                	xor    edx,edx
  47d2e2:	89 45 ec             	mov    DWORD PTR [ebp-0x14],eax
  47d2e5:	89 55 f0             	mov    DWORD PTR [ebp-0x10],edx
  47d2e8:	3b f0                	cmp    esi,eax
  47d2ea:	0f 84 30 01 00 00    	je     0x47d420
  47d2f0:	eb 11                	jmp    0x47d303
  47d2f2:	eb 0c                	jmp    0x47d300
  47d2f4:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  47d2fb:	eb 03                	jmp    0x47d300
  47d2fd:	8d 49 00             	lea    ecx,[ecx+0x0]
  47d300:	8b 55 f0             	mov    edx,DWORD PTR [ebp-0x10]
  47d303:	8b 83 f8 00 00 00    	mov    eax,DWORD PTR [ebx+0xf8]
  47d309:	8b 88 cc 00 00 00    	mov    ecx,DWORD PTR [eax+0xcc]
  47d30f:	85 c9                	test   ecx,ecx
  47d311:	74 49                	je     0x47d35c
  47d313:	8b 81 ac 00 00 00    	mov    eax,DWORD PTR [ecx+0xac]
  47d319:	2b 81 a8 00 00 00    	sub    eax,DWORD PTR [ecx+0xa8]
  47d31f:	c1 f8 02             	sar    eax,0x2
  47d322:	83 fa ff             	cmp    edx,0xffffffff
  47d325:	7e 35                	jle    0x47d35c
  47d327:	3b d0                	cmp    edx,eax
  47d329:	7d 31                	jge    0x47d35c
  47d32b:	8b 81 a8 00 00 00    	mov    eax,DWORD PTR [ecx+0xa8]
  47d331:	8b 3c 90             	mov    edi,DWORD PTR [eax+edx*4]
  47d334:	85 ff                	test   edi,edi
  47d336:	74 24                	je     0x47d35c
  47d338:	8b 17                	mov    edx,DWORD PTR [edi]
  47d33a:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  47d33d:	8b cf                	mov    ecx,edi
  47d33f:	ff d0                	call   eax
  47d341:	3d 2d 01 00 00       	cmp    eax,0x12d
  47d346:	74 16                	je     0x47d35e
  47d348:	6a 00                	push   0x0
  47d34a:	68 c0 1f bf 00       	push   0xbf1fc0
  47d34f:	68 18 21 bf 00       	push   0xbf2118
  47d354:	6a 00                	push   0x0
  47d356:	ff 15 80 25 bd 00    	call   DWORD PTR ds:0xbd2580
  47d35c:	33 ff                	xor    edi,edi
  47d35e:	ff 45 f0             	inc    DWORD PTR [ebp-0x10]
```

### N15. Record-to-object call at 0x47D36D and object event setup

- VA `0x47D361..0x47D3D2`; raw `0x7C761..0x7C7D2`; `113` bytes; SHA256 `b1f7d2b782b649d28450765cdf720693108b75e379e1f05cee9f7efc7c07739e`.

```asm
0047d361 <.data+0x7c761>:
  47d361:	3b b3 10 01 00 00    	cmp    esi,DWORD PTR [ebx+0x110]
  47d367:	74 69                	je     0x47d3d2
  47d369:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  47d36c:	57                   	push   edi
  47d36d:	e8 3e df ff ff       	call   0x47b2b0
  47d372:	f6 05 64 0f fc 00 01 	test   BYTE PTR ds:0xfc0f64,0x1
  47d379:	75 27                	jne    0x47d3a2
  47d37b:	83 0d 64 0f fc 00 01 	or     DWORD PTR ds:0xfc0f64,0x1
  47d382:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47d389:	e8 52 09 00 00       	call   0x47dce0
  47d38e:	68 f0 da bc 00       	push   0xbcdaf0
  47d393:	e8 82 4f 41 00       	call   0x89231a
  47d398:	83 c4 04             	add    esp,0x4
  47d39b:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47d3a2:	8b 46 0c             	mov    eax,DWORD PTR [esi+0xc]
  47d3a5:	3b 05 78 0f fc 00    	cmp    eax,DWORD PTR ds:0xfc0f78
  47d3ab:	8b 8f 6c 02 00 00    	mov    ecx,DWORD PTR [edi+0x26c]
  47d3b1:	8b 11                	mov    edx,DWORD PTR [ecx]
  47d3b3:	8b 92 94 00 00 00    	mov    edx,DWORD PTR [edx+0x94]
  47d3b9:	0f 94 c0             	sete   al
  47d3bc:	0f b6 c0             	movzx  eax,al
  47d3bf:	50                   	push   eax
  47d3c0:	ff d2                	call   edx
  47d3c2:	8b 8f 6c 02 00 00    	mov    ecx,DWORD PTR [edi+0x26c]
  47d3c8:	8b 01                	mov    eax,DWORD PTR [ecx]
  47d3ca:	8b 90 c8 00 00 00    	mov    edx,DWORD PTR [eax+0xc8]
  47d3d0:	ff d2                	call   edx
```

### N16. Object record key writer: chapter key and display name

- VA `0x47B2B0..0x47B315`; raw `0x7A6B0..0x7A715`; `101` bytes; SHA256 `c68bd103e5cb21c6d629cb6eea6606161eddf17cd41d9bab9adf5af91a427cb8`.

```asm
0047b2b0 <.data+0x7a6b0>:
  47b2b0:	55                   	push   ebp
  47b2b1:	8b ec                	mov    ebp,esp
  47b2b3:	6a ff                	push   0xffffffff
  47b2b5:	68 dc ce 91 00       	push   0x91cedc
  47b2ba:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47b2c0:	50                   	push   eax
  47b2c1:	83 ec 08             	sub    esp,0x8
  47b2c4:	53                   	push   ebx
  47b2c5:	56                   	push   esi
  47b2c6:	57                   	push   edi
  47b2c7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47b2cc:	33 c5                	xor    eax,ebp
  47b2ce:	50                   	push   eax
  47b2cf:	8d 45 f4             	lea    eax,[ebp-0xc]
  47b2d2:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47b2d8:	8b f9                	mov    edi,ecx
  47b2da:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  47b2dd:	8b 07                	mov    eax,DWORD PTR [edi]
  47b2df:	6a ff                	push   0xffffffff
  47b2e1:	6a 00                	push   0x0
  47b2e3:	8d 4f 08             	lea    ecx,[edi+0x8]
  47b2e6:	8d b3 4c 02 00 00    	lea    esi,[ebx+0x24c]
  47b2ec:	51                   	push   ecx
  47b2ed:	8b ce                	mov    ecx,esi
  47b2ef:	89 83 48 02 00 00    	mov    DWORD PTR [ebx+0x248],eax
  47b2f5:	e8 e6 73 f8 ff       	call   0x4026e0
  47b2fa:	56                   	push   esi
  47b2fb:	8d b3 e8 00 00 00    	lea    esi,[ebx+0xe8]
  47b301:	e8 fa c4 2d 00       	call   0x757800
  47b306:	83 7f 04 16          	cmp    DWORD PTR [edi+0x4],0x16
  47b30a:	b8 01 00 00 00       	mov    eax,0x1
  47b30f:	0f 8e 86 00 00 00    	jle    0x47b39b
```

### N17. Object writer tail: alternate map lookup and resource gate

- VA `0x47B343..0x47B440`; raw `0x7A743..0x7A840`; `253` bytes; SHA256 `66e211d7f29069773cf3b8f5876411c086e137d2806e52bd29cdc079e520a553`.

```asm
0047b343 <.data+0x7a743>:
  47b343:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  47b346:	8d 45 08             	lea    eax,[ebp+0x8]
  47b349:	50                   	push   eax
  47b34a:	8d 45 f0             	lea    eax,[ebp-0x10]
  47b34d:	b9 a0 45 f9 00       	mov    ecx,0xf945a0
  47b352:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  47b355:	e8 a6 3b 3b 00       	call   0x82ef00
  47b35a:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  47b35d:	3b 05 a4 45 f9 00    	cmp    eax,DWORD PTR ds:0xf945a4
  47b363:	74 05                	je     0x47b36a
  47b365:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  47b368:	eb 02                	jmp    0x47b36c
  47b36a:	33 f6                	xor    esi,esi
  47b36c:	8b bb 68 02 00 00    	mov    edi,DWORD PTR [ebx+0x268]
  47b372:	80 bf a4 00 00 00 00 	cmp    BYTE PTR [edi+0xa4],0x0
  47b379:	0f 84 a6 00 00 00    	je     0x47b425
  47b37f:	83 bf 94 00 00 00 00 	cmp    DWORD PTR [edi+0x94],0x0
  47b386:	0f 84 99 00 00 00    	je     0x47b425
  47b38c:	8b 8f 94 00 00 00    	mov    ecx,DWORD PTR [edi+0x94]
  47b392:	8b 11                	mov    edx,DWORD PTR [ecx]
  47b394:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  47b397:	ff d0                	call   eax
  47b399:	eb 78                	jmp    0x47b413
  47b39b:	84 05 94 43 f9 00    	test   BYTE PTR ds:0xf94394,al
  47b3a1:	75 22                	jne    0x47b3c5
  47b3a3:	09 05 94 43 f9 00    	or     DWORD PTR ds:0xf94394,eax
  47b3a9:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  47b3ac:	e8 2f 8a 14 00       	call   0x5c3de0
  47b3b1:	68 30 cc bc 00       	push   0xbccc30
  47b3b6:	e8 5f 6f 41 00       	call   0x89231a
  47b3bb:	83 c4 04             	add    esp,0x4
  47b3be:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47b3c5:	8b 4f 04             	mov    ecx,DWORD PTR [edi+0x4]
  47b3c8:	8d 55 08             	lea    edx,[ebp+0x8]
  47b3cb:	89 4d 08             	mov    DWORD PTR [ebp+0x8],ecx
  47b3ce:	52                   	push   edx
  47b3cf:	8d 45 f0             	lea    eax,[ebp-0x10]
  47b3d2:	b9 90 45 f9 00       	mov    ecx,0xf94590
  47b3d7:	e8 24 3b 3b 00       	call   0x82ef00
  47b3dc:	8b 45 f0             	mov    eax,DWORD PTR [ebp-0x10]
  47b3df:	3b 05 94 45 f9 00    	cmp    eax,DWORD PTR ds:0xf94594
  47b3e5:	74 05                	je     0x47b3ec
  47b3e7:	8b 70 10             	mov    esi,DWORD PTR [eax+0x10]
  47b3ea:	eb 02                	jmp    0x47b3ee
  47b3ec:	33 f6                	xor    esi,esi
  47b3ee:	8b bb 68 02 00 00    	mov    edi,DWORD PTR [ebx+0x268]
  47b3f4:	80 bf a4 00 00 00 00 	cmp    BYTE PTR [edi+0xa4],0x0
  47b3fb:	74 28                	je     0x47b425
  47b3fd:	83 bf 94 00 00 00 00 	cmp    DWORD PTR [edi+0x94],0x0
  47b404:	74 1f                	je     0x47b425
  47b406:	8b 8f 94 00 00 00    	mov    ecx,DWORD PTR [edi+0x94]
  47b40c:	8b 01                	mov    eax,DWORD PTR [ecx]
  47b40e:	8b 50 04             	mov    edx,DWORD PTR [eax+0x4]
  47b411:	ff d2                	call   edx
  47b413:	3d 6b bf 00 00       	cmp    eax,0xbf6b
  47b418:	75 0b                	jne    0x47b425
  47b41a:	8b bf 94 00 00 00    	mov    edi,DWORD PTR [edi+0x94]
  47b420:	e8 db fd 2f 00       	call   0x77b200
  47b425:	8b 8b 68 02 00 00    	mov    ecx,DWORD PTR [ebx+0x268]
  47b42b:	8b 01                	mov    eax,DWORD PTR [ecx]
  47b42d:	8b 90 c8 00 00 00    	mov    edx,DWORD PTR [eax+0xc8]
  47b433:	ff d2                	call   edx
  47b435:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47b438:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47b43f:	59                   	pop    ecx
```

### N18. Object spawn with default -1 keys and state

- VA `0x47B480..0x47B550`; raw `0x7A880..0x7A950`; `208` bytes; SHA256 `9386bfca57891f0b5503a6c987a77b09f8019db5f443f66b7efabc85bf366b16`.

```asm
0047b480 <.data+0x7a880>:
  47b480:	55                   	push   ebp
  47b481:	8b ec                	mov    ebp,esp
  47b483:	6a ff                	push   0xffffffff
  47b485:	68 68 9c 91 00       	push   0x919c68
  47b48a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47b490:	50                   	push   eax
  47b491:	51                   	push   ecx
  47b492:	53                   	push   ebx
  47b493:	56                   	push   esi
  47b494:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47b499:	33 c5                	xor    eax,ebp
  47b49b:	50                   	push   eax
  47b49c:	8d 45 f4             	lea    eax,[ebp-0xc]
  47b49f:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47b4a5:	8b f1                	mov    esi,ecx
  47b4a7:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  47b4aa:	e8 d1 93 2d 00       	call   0x754880
  47b4af:	8d 86 5c 01 00 00    	lea    eax,[esi+0x15c]
  47b4b5:	33 db                	xor    ebx,ebx
  47b4b7:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  47b4ba:	50                   	push   eax
  47b4bb:	c7 06 dc 67 c4 00    	mov    DWORD PTR [esi],0xc467dc
  47b4c1:	e8 5a 00 30 00       	call   0x77b520
  47b4c6:	83 c8 ff             	or     eax,0xffffffff
  47b4c9:	89 86 48 02 00 00    	mov    DWORD PTR [esi+0x248],eax
  47b4cf:	89 86 4c 02 00 00    	mov    DWORD PTR [esi+0x24c],eax
  47b4d5:	c6 86 58 01 00 00 01 	mov    BYTE PTR [esi+0x158],0x1
  47b4dc:	c7 06 3c 2f c0 00    	mov    DWORD PTR [esi],0xc02f3c
  47b4e2:	c7 86 64 02 00 00 07 	mov    DWORD PTR [esi+0x264],0x7
  47b4e9:	00 00 00 
  47b4ec:	89 9e 60 02 00 00    	mov    DWORD PTR [esi+0x260],ebx
  47b4f2:	33 c9                	xor    ecx,ecx
  47b4f4:	66 89 8e 50 02 00 00 	mov    WORD PTR [esi+0x250],cx
  47b4fb:	88 9e 6c 02 00 00    	mov    BYTE PTR [esi+0x26c],bl
  47b501:	89 9e 70 02 00 00    	mov    DWORD PTR [esi+0x270],ebx
  47b507:	8b c6                	mov    eax,esi
  47b509:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47b50c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47b513:	59                   	pop    ecx
  47b514:	5e                   	pop    esi
  47b515:	5b                   	pop    ebx
  47b516:	8b e5                	mov    esp,ebp
  47b518:	5d                   	pop    ebp
  47b519:	c3                   	ret
  47b51a:	cc                   	int3
  47b51b:	cc                   	int3
  47b51c:	cc                   	int3
  47b51d:	cc                   	int3
  47b51e:	cc                   	int3
  47b51f:	cc                   	int3
  47b520:	55                   	push   ebp
  47b521:	8b ec                	mov    ebp,esp
  47b523:	6a ff                	push   0xffffffff
  47b525:	68 38 d4 91 00       	push   0x91d438
  47b52a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47b530:	50                   	push   eax
  47b531:	51                   	push   ecx
  47b532:	56                   	push   esi
  47b533:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47b538:	33 c5                	xor    eax,ebp
  47b53a:	50                   	push   eax
  47b53b:	8d 45 f4             	lea    eax,[ebp-0xc]
  47b53e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47b544:	8b f1                	mov    esi,ecx
  47b546:	89 75 f0             	mov    DWORD PTR [ebp-0x10],esi
  47b549:	c7 06 3c 2f c0 00    	mov    DWORD PTR [esi],0xc02f3c
  47b54f:	83       	cmp    DWORD PTR [esi+0x264],0x8
```

### N19. Object event consumer composes new key and FIRST scene selector

- VA `0x47D530..0x47D5C2`; raw `0x7C930..0x7C9C2`; `146` bytes; SHA256 `ff49e2ee15cc38c0d9af67bb2c948b6ca3d6157c449b918f8eb906c21c48c360`.

```asm
0047d530 <.data+0x7c930>:
  47d530:	55                   	push   ebp
  47d531:	8b ec                	mov    ebp,esp
  47d533:	6a ff                	push   0xffffffff
  47d535:	68 7e 7e 94 00       	push   0x947e7e
  47d53a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47d540:	50                   	push   eax
  47d541:	56                   	push   esi
  47d542:	57                   	push   edi
  47d543:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47d548:	33 c5                	xor    eax,ebp
  47d54a:	50                   	push   eax
  47d54b:	8d 45 f4             	lea    eax,[ebp-0xc]
  47d54e:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47d554:	8b f1                	mov    esi,ecx
  47d556:	8b fa                	mov    edi,edx
  47d558:	8b 86 48 02 00 00    	mov    eax,DWORD PTR [esi+0x248]
  47d55e:	89 87 20 01 00 00    	mov    DWORD PTR [edi+0x120],eax
  47d564:	8b 86 4c 02 00 00    	mov    eax,DWORD PTR [esi+0x24c]
  47d56a:	89 87 1c 01 00 00    	mov    DWORD PTR [edi+0x11c],eax
  47d570:	b8 01 00 00 00       	mov    eax,0x1
  47d575:	84 05 64 0f fc 00    	test   BYTE PTR ds:0xfc0f64,al
  47d57b:	75 26                	jne    0x47d5a3
  47d57d:	09 05 64 0f fc 00    	or     DWORD PTR ds:0xfc0f64,eax
  47d583:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47d58a:	e8 51 07 00 00       	call   0x47dce0
  47d58f:	68 f0 da bc 00       	push   0xbcdaf0
  47d594:	e8 81 4d 41 00       	call   0x89231a
  47d599:	83 c4 04             	add    esp,0x4
  47d59c:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47d5a3:	8b 87 20 01 00 00    	mov    eax,DWORD PTR [edi+0x120]
  47d5a9:	50                   	push   eax
  47d5aa:	68 68 0f fc 00       	push   0xfc0f68
  47d5af:	e8 dc 12 00 00       	call   0x47e890
  47d5b4:	50                   	push   eax
  47d5b5:	8b ce                	mov    ecx,esi
  47d5b7:	e8 04 e0 ff ff       	call   0x47b5c0
  47d5bc:	57                   	push   edi
  47d5bd:	e8 2e f8 ff ff       	call   0x47cdf0
```

### N20. Object event post-scene callback and cleanup

- VA `0x47D5C2..0x47D609`; raw `0x7C9C2..0x7CA09`; `71` bytes; SHA256 `964af34a8ec9623176d25d71c60d6db110ada434f4fe7976cbd5214f4772cf28`.

```asm
0047d5c2 <.data+0x7c9c2>:
  47d5c2:	8b 8f 00 01 00 00    	mov    ecx,DWORD PTR [edi+0x100]
  47d5c8:	8b 31                	mov    esi,DWORD PTR [ecx]
  47d5ca:	e8 41 00 00 00       	call   0x47d610
  47d5cf:	8b 8f 00 01 00 00    	mov    ecx,DWORD PTR [edi+0x100]
  47d5d5:	0f b6 d0             	movzx  edx,al
  47d5d8:	8b 86 90 00 00 00    	mov    eax,DWORD PTR [esi+0x90]
  47d5de:	52                   	push   edx
  47d5df:	ff d0                	call   eax
  47d5e1:	8b 8f 00 01 00 00    	mov    ecx,DWORD PTR [edi+0x100]
  47d5e7:	8b 11                	mov    edx,DWORD PTR [ecx]
  47d5e9:	8b 82 c8 00 00 00    	mov    eax,DWORD PTR [edx+0xc8]
  47d5ef:	ff d0                	call   eax
  47d5f1:	8b cf                	mov    ecx,edi
  47d5f3:	e8 b8 fa ff ff       	call   0x47d0b0
  47d5f8:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47d5fb:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47d602:	59                   	pop    ecx
  47d603:	5f                   	pop    edi
  47d604:	5e                   	pop    esi
  47d605:	8b e5                	mov    esp,ebp
  47d607:	5d                   	pop    ebp
  47d608:	c3                   	ret
```

### N21. Object scene entry: 0xEA61 special path vs Event SceneList

- VA `0x47B5C0..0x47B64F`; raw `0x7A9C0..0x7AA4F`; `143` bytes; SHA256 `53dd8506239db93db828016e09cadb63b173d026ffd5cd4d32e833282810fa46`.

```asm
0047b5c0 <.data+0x7a9c0>:
  47b5c0:	55                   	push   ebp
  47b5c1:	8b ec                	mov    ebp,esp
  47b5c3:	83 e4 f8             	and    esp,0xfffffff8
  47b5c6:	6a ff                	push   0xffffffff
  47b5c8:	68 7c 10 94 00       	push   0x94107c
  47b5cd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47b5d3:	50                   	push   eax
  47b5d4:	51                   	push   ecx
  47b5d5:	56                   	push   esi
  47b5d6:	57                   	push   edi
  47b5d7:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47b5dc:	33 c4                	xor    eax,esp
  47b5de:	50                   	push   eax
  47b5df:	8d 44 24 10          	lea    eax,[esp+0x10]
  47b5e3:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47b5e9:	8b f9                	mov    edi,ecx
  47b5eb:	81 bf 48 02 00 00 61 	cmp    DWORD PTR [edi+0x248],0xea61
  47b5f2:	ea 00 00 
  47b5f5:	75 11                	jne    0x47b608
  47b5f7:	80 bf 6c 02 00 00 00 	cmp    BYTE PTR [edi+0x26c],0x0
  47b5fe:	75 4f                	jne    0x47b64f
  47b600:	57                   	push   edi
  47b601:	e8 4a 02 00 00       	call   0x47b850
  47b606:	eb 47                	jmp    0x47b64f
  47b608:	f6 05 b8 73 fb 00 01 	test   BYTE PTR ds:0xfb73b8,0x1
  47b60f:	75 29                	jne    0x47b63a
  47b611:	83 0d b8 73 fb 00 01 	or     DWORD PTR ds:0xfb73b8,0x1
  47b618:	c7 44 24 18 00 00 00 	mov    DWORD PTR [esp+0x18],0x0
  47b61f:	00 
  47b620:	e8 4b 4b 0e 00       	call   0x560170
  47b625:	68 10 d1 bc 00       	push   0xbcd110
  47b62a:	e8 eb 6c 41 00       	call   0x89231a
  47b62f:	83 c4 04             	add    esp,0x4
  47b632:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  47b639:	ff 
  47b63a:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47b63d:	8b 8f 48 02 00 00    	mov    ecx,DWORD PTR [edi+0x248]
  47b643:	50                   	push   eax
  47b644:	51                   	push   ecx
  47b645:	be c0 73 fb 00       	mov    esi,0xfb73c0
  47b64a:	e8 d1 a0 0e 00       	call   0x565720
```

### N22. Object scene entry followup table state side effect

- VA `0x47B64F..0x47B6AA`; raw `0x7AA4F..0x7AAAA`; `91` bytes; SHA256 `97e1dd5d12964947e8e731d2bb87d38bc470e5559c0b003ca952cfb7952e8144`.

```asm
0047b64f <.data+0x7aa4f>:
  47b64f:	f6 05 64 0f fc 00 01 	test   BYTE PTR ds:0xfc0f64,0x1
  47b656:	75 29                	jne    0x47b681
  47b658:	b8 01 00 00 00       	mov    eax,0x1
  47b65d:	09 05 64 0f fc 00    	or     DWORD PTR ds:0xfc0f64,eax
  47b663:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  47b667:	e8 74 26 00 00       	call   0x47dce0
  47b66c:	68 f0 da bc 00       	push   0xbcdaf0
  47b671:	e8 a4 6c 41 00       	call   0x89231a
  47b676:	83 c4 04             	add    esp,0x4
  47b679:	c7 44 24 18 ff ff ff 	mov    DWORD PTR [esp+0x18],0xffffffff
  47b680:	ff 
  47b681:	8b 97 4c 02 00 00    	mov    edx,DWORD PTR [edi+0x24c]
  47b687:	8b 8f 48 02 00 00    	mov    ecx,DWORD PTR [edi+0x248]
  47b68d:	52                   	push   edx
  47b68e:	bf 68 0f fc 00       	mov    edi,0xfc0f68
  47b693:	e8 b8 30 00 00       	call   0x47e750
  47b698:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  47b69c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47b6a3:	59                   	pop    ecx
  47b6a4:	5f                   	pop    edi
  47b6a5:	5e                   	pop    esi
  47b6a6:	8b e5                	mov    esp,ebp
  47b6a8:	5d                   	pop    ebp
  47b6a9:	c2               	ret    0x4
```

### N23. Controller live scene state and second scene selector

- VA `0x561DB0..0x561ED1`; raw `0x1611B0..0x1612D1`; `289` bytes; SHA256 `d4a9b70300c423fc61d65c5843118ba9a627f9bfae852a99b43d03a395e9bd1c`.

```asm
00561db0 <.data+0x1611b0>:
  561db0:	55                   	push   ebp
  561db1:	8b ec                	mov    ebp,esp
  561db3:	83 e4 f8             	and    esp,0xfffffff8
  561db6:	6a ff                	push   0xffffffff
  561db8:	68 64 fc 93 00       	push   0x93fc64
  561dbd:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  561dc3:	50                   	push   eax
  561dc4:	83 ec 10             	sub    esp,0x10
  561dc7:	53                   	push   ebx
  561dc8:	56                   	push   esi
  561dc9:	57                   	push   edi
  561dca:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  561dcf:	33 c4                	xor    eax,esp
  561dd1:	50                   	push   eax
  561dd2:	8d 44 24 20          	lea    eax,[esp+0x20]
  561dd6:	64 a3 00 00 00 00    	mov    fs:0x0,eax
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
  561e06:	84 1d d4 f3 fd 00    	test   BYTE PTR ds:0xfdf3d4,bl
  561e0c:	75 25                	jne    0x561e33
  561e0e:	09 1d d4 f3 fd 00    	or     DWORD PTR ds:0xfdf3d4,ebx
  561e14:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  561e18:	e8 63 25 19 00       	call   0x6f4380
  561e1d:	68 d0 e6 bc 00       	push   0xbce6d0
  561e22:	e8 f3 04 33 00       	call   0x89231a
  561e27:	83 c4 04             	add    esp,0x4
  561e2a:	83 ce ff             	or     esi,0xffffffff
  561e2d:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  561e31:	eb 03                	jmp    0x561e36
  561e33:	83 ce ff             	or     esi,0xffffffff
  561e36:	68 ec 06 c1 00       	push   0xc106ec
  561e3b:	6a 00                	push   0x0
  561e3d:	68 c8 f3 fd 00       	push   0xfdf3c8
  561e42:	e8 59 b2 f4 ff       	call   0x4ad0a0
  561e47:	f6 05 d4 ad fa 00 01 	test   BYTE PTR ds:0xfaadd4,0x1
  561e4e:	75 20                	jne    0x561e70
  561e50:	09 1d d4 ad fa 00    	or     DWORD PTR ds:0xfaadd4,ebx
  561e56:	89 5c 24 28          	mov    DWORD PTR [esp+0x28],ebx
  561e5a:	e8 21 56 02 00       	call   0x587480
  561e5f:	68 c0 cc bc 00       	push   0xbcccc0
  561e64:	e8 b1 04 33 00       	call   0x89231a
  561e69:	83 c4 04             	add    esp,0x4
  561e6c:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
  561e70:	d9 87 84 00 00 00    	fld    DWORD PTR [edi+0x84]
  561e76:	83 ec 08             	sub    esp,0x8
  561e79:	d9 5c 24 1c          	fstp   DWORD PTR [esp+0x1c]
  561e7d:	d9 44 24 1c          	fld    DWORD PTR [esp+0x1c]
  561e81:	d9 54 24 04          	fst    DWORD PTR [esp+0x4]
  561e85:	d9 1c 24             	fstp   DWORD PTR [esp]
  561e88:	e8 93 7b 02 00       	call   0x589a20
  561e8d:	8a 9f 88 00 00 00    	mov    bl,BYTE PTR [edi+0x88]
  561e93:	e8 08 2d ea ff       	call   0x404ba0
  561e98:	88 98 c4 68 00 00    	mov    BYTE PTR [eax+0x68c4],bl
  561e9e:	eb 03                	jmp    0x561ea3
  561ea0:	83 ce ff             	or     esi,0xffffffff
  561ea3:	f6 05 64 0f fc 00 01 	test   BYTE PTR ds:0xfc0f64,0x1
  561eaa:	75 25                	jne    0x561ed1
  561eac:	83 0d 64 0f fc 00 01 	or     DWORD PTR ds:0xfc0f64,0x1
  561eb3:	c7 44 24 28 02 00 00 	mov    DWORD PTR [esp+0x28],0x2
  561eba:	00 
  561ebb:	e8 20 be f1 ff       	call   0x47dce0
  561ec0:	68 f0 da bc 00       	push   0xbcdaf0
  561ec5:	e8 50 04 33 00       	call   0x89231a
  561eca:	83 c4 04             	add    esp,0x4
  561ecd:	89 74 24 28          	mov    DWORD PTR [esp+0x28],esi
```

### N24. Controller NEXT scene selector call, zero gate, dispatch

- VA `0x561ED1..0x561F0B`; raw `0x1612D1..0x16130B`; `58` bytes; SHA256 `9c3730eb69f44b32f778ce4a8f4aba5fe9eb59bf29778cdd9b979b5b31b383eb`.

```asm
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

### N25. Event SceneList consumer and pending scene flags

- VA `0x565720..0x56578E`; raw `0x164B20..0x164B8E`; `110` bytes; SHA256 `6fd1483f22342272cb2c767abcda4759ed0c890f16733ae478732172f3a28fd8`.

```asm
00565720 <.data+0x164b20>:
  565720:	55                   	push   ebp
  565721:	8b ec                	mov    ebp,esp
  565723:	83 e4 f8             	and    esp,0xfffffff8
  565726:	6a ff                	push   0xffffffff
  565728:	68 e8 fb 93 00       	push   0x93fbe8
  56572d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  565733:	50                   	push   eax
  565734:	83 ec 34             	sub    esp,0x34
  565737:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  56573c:	33 c4                	xor    eax,esp
  56573e:	89 44 24 2c          	mov    DWORD PTR [esp+0x2c],eax
  565742:	53                   	push   ebx
  565743:	57                   	push   edi
  565744:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  565749:	33 c4                	xor    eax,esp
  56574b:	50                   	push   eax
  56574c:	8d 44 24 40          	lea    eax,[esp+0x40]
  565750:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  565756:	83 7e 28 00          	cmp    DWORD PTR [esi+0x28],0x0
  56575a:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  56575d:	c6 86 89 00 00 00 01 	mov    BYTE PTR [esi+0x89],0x1
  565764:	74 17                	je     0x56577d
  565766:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  565769:	50                   	push   eax
  56576a:	51                   	push   ecx
  56576b:	68 ac 06 c1 00       	push   0xc106ac
  565770:	e8 eb 83 18 00       	call   0x6edb60
  565775:	83 c4 0c             	add    esp,0xc
  565778:	e9 e8 02 00 00       	jmp    0x565a65
  56577d:	8b 55 08             	mov    edx,DWORD PTR [ebp+0x8]
  565780:	bb 01 00 00 00       	mov    ebx,0x1
  565785:	89 56 38             	mov    DWORD PTR [esi+0x38],edx
  565788:	89 46 3c             	mov    DWORD PTR [esi+0x3c],eax
  56578b:	89 5e 28             	mov    DWORD PTR [esi+0x28],ebx
```

### N26. Event SceneList two DWORD key lookup and no-match branch

- VA `0x5658AC..0x56592C`; raw `0x164CAC..0x164D2C`; `128` bytes; SHA256 `ed53b15a0fed7b2dcc01f985aec31d3a02ce6bcfa85b8c414b4d71d5913d8e76`.

```asm
005658ac <.data+0x164cac>:
  5658ac:	6a 00                	push   0x0
  5658ae:	68 75 23 bf 00       	push   0xbf2375
  5658b3:	8d 4e 44             	lea    ecx,[esi+0x44]
  5658b6:	c6 05 a4 42 f9 00 01 	mov    BYTE PTR ds:0xf942a4,0x1
  5658bd:	e8 ae d1 e9 ff       	call   0x402a70
  5658c2:	8b 4e 0c             	mov    ecx,DWORD PTR [esi+0xc]
  5658c5:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  5658c8:	80 78 31 00          	cmp    BYTE PTR [eax+0x31],0x0
  5658cc:	75 27                	jne    0x5658f5
  5658ce:	8b ff                	mov    edi,edi
  5658d0:	8b 50 0c             	mov    edx,DWORD PTR [eax+0xc]
  5658d3:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  5658d6:	3b fa                	cmp    edi,edx
  5658d8:	7f 0a                	jg     0x5658e4
  5658da:	7c 0d                	jl     0x5658e9
  5658dc:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  5658df:	39 50 10             	cmp    DWORD PTR [eax+0x10],edx
  5658e2:	7d 05                	jge    0x5658e9
  5658e4:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  5658e7:	eb 04                	jmp    0x5658ed
  5658e9:	8b c8                	mov    ecx,eax
  5658eb:	8b 00                	mov    eax,DWORD PTR [eax]
  5658ed:	80 78 31 00          	cmp    BYTE PTR [eax+0x31],0x0
  5658f1:	74 dd                	je     0x5658d0
  5658f3:	eb 03                	jmp    0x5658f8
  5658f5:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  5658f8:	8b 56 0c             	mov    edx,DWORD PTR [esi+0xc]
  5658fb:	89 4c 24 18          	mov    DWORD PTR [esp+0x18],ecx
  5658ff:	3b ca                	cmp    ecx,edx
  565901:	74 17                	je     0x56591a
  565903:	8b 41 0c             	mov    eax,DWORD PTR [ecx+0xc]
  565906:	3b c7                	cmp    eax,edi
  565908:	7f 10                	jg     0x56591a
  56590a:	7c 08                	jl     0x565914
  56590c:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  56590f:	3b 41 10             	cmp    eax,DWORD PTR [ecx+0x10]
  565912:	7c 06                	jl     0x56591a
  565914:	8d 44 24 18          	lea    eax,[esp+0x18]
  565918:	eb 08                	jmp    0x565922
  56591a:	89 54 24 10          	mov    DWORD PTR [esp+0x10],edx
  56591e:	8d 44 24 10          	lea    eax,[esp+0x10]
  565922:	8b 38                	mov    edi,DWORD PTR [eax]
  565924:	3b fa                	cmp    edi,edx
  565926:	0f 84 39 01 00 00    	je     0x565a65
```

### N27. Event SceneList selected Lua name and VM dispatch

- VA `0x56592C..0x5659E1`; raw `0x164D2C..0x164DE1`; `181` bytes; SHA256 `0206dcc2616a584d8b4bbb3ea17fe26e3c928aedb2e950bd7d55b9490c158536`.

```asm
0056592c <.data+0x164d2c>:
  56592c:	6a 10                	push   0x10
  56592e:	68 d0 06 c1 00       	push   0xc106d0
  565933:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  565937:	c7 44 24 38 0f 00 00 	mov    DWORD PTR [esp+0x38],0xf
  56593e:	00 
  56593f:	c7 44 24 34 00 00 00 	mov    DWORD PTR [esp+0x34],0x0
  565946:	00 
  565947:	c6 44 24 24 00       	mov    BYTE PTR [esp+0x24],0x0
  56594c:	e8 1f d1 e9 ff       	call   0x402a70
  565951:	6a ff                	push   0xffffffff
  565953:	8d 47 14             	lea    eax,[edi+0x14]
  565956:	6a 00                	push   0x0
  565958:	bb 05 00 00 00       	mov    ebx,0x5
  56595d:	50                   	push   eax
  56595e:	8d 4c 24 28          	lea    ecx,[esp+0x28]
  565962:	89 5c 24 54          	mov    DWORD PTR [esp+0x54],ebx
  565966:	e8 65 c5 e9 ff       	call   0x401ed0
  56596b:	6a 04                	push   0x4
  56596d:	68 e4 06 c1 00       	push   0xc106e4
  565972:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  565976:	e8 45 c6 e9 ff       	call   0x401fc0
  56597b:	83 7c 24 30 10       	cmp    DWORD PTR [esp+0x30],0x10
  565980:	8b 7c 24 1c          	mov    edi,DWORD PTR [esp+0x1c]
  565984:	73 04                	jae    0x56598a
  565986:	8d 7c 24 1c          	lea    edi,[esp+0x1c]
  56598a:	f6 05 e8 1e fe 00 01 	test   BYTE PTR ds:0xfe1ee8,0x1
  565991:	75 22                	jne    0x5659b5
  565993:	83 0d e8 1e fe 00 01 	or     DWORD PTR ds:0xfe1ee8,0x1
  56599a:	c6 44 24 48 06       	mov    BYTE PTR [esp+0x48],0x6
  56599f:	e8 6c 6c ff ff       	call   0x55c610
  5659a4:	68 90 f2 bc 00       	push   0xbcf290
  5659a9:	e8 6c c9 32 00       	call   0x89231a
  5659ae:	83 c4 04             	add    esp,0x4
  5659b1:	88 5c 24 48          	mov    BYTE PTR [esp+0x48],bl
  5659b5:	57                   	push   edi
  5659b6:	68 ec 1e fe 00       	push   0xfe1eec
  5659bb:	e8 e0 7c ff ff       	call   0x55d6a0
  5659c0:	bf 10 00 00 00       	mov    edi,0x10
  5659c5:	89 46 70             	mov    DWORD PTR [esi+0x70],eax
  5659c8:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  5659cc:	39 7c 24 30          	cmp    DWORD PTR [esp+0x30],edi
  5659d0:	73 04                	jae    0x5659d6
  5659d2:	8d 44 24 1c          	lea    eax,[esp+0x1c]
  5659d6:	8b 0e                	mov    ecx,DWORD PTR [esi]
  5659d8:	50                   	push   eax
  5659d9:	e8 72 f0 18 00       	call   0x6f4a50
  5659de:	e8 6d e8         	call   0x434250
```

### N28. Lua global name RestoreMap registration (binding, not effect)

- VA `0x55E04C..0x55E09D`; raw `0x15D44C..0x15D49D`; `81` bytes; SHA256 `a3b7f1924ab1c9d7b2df90b0e1f26d8474cf0dfd1bc3470e2d4656a42dcfa472`.

```asm
0055e04c <.data+0x15d44c>:
  55e04c:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e051:	8b 30                	mov    esi,DWORD PTR [eax]
  55e053:	6a 00                	push   0x0
  55e055:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e05a:	8b d8                	mov    ebx,eax
  55e05c:	e8 4f 75 19 00       	call   0x6f55b0
  55e061:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e063:	bf 4c 05 c1 00       	mov    edi,0xc1054c
  55e068:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e06d:	e8 1e 77 19 00       	call   0x6f5790
  55e072:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
  55e077:	8b 30                	mov    esi,DWORD PTR [eax]
  55e079:	6a 00                	push   0x0
  55e07b:	68 f0 c2 8d 00       	push   0x8dc2f0
  55e080:	8b d8                	mov    ebx,eax
  55e082:	e8 29 75 19 00       	call   0x6f55b0
  55e087:	8b 33                	mov    esi,DWORD PTR [ebx]
  55e089:	bf 54 05 c1 00       	mov    edi,0xc10554
  55e08e:	b8 ee d8 ff ff       	mov    eax,0xffffd8ee
  55e093:	e8 f8 76 19 00       	call   0x6f5790
  55e098:	a1 f0 1e fe 00       	mov    eax,ds:0xfe1ef0
```

### N29. Generic Lua name registration backend, not direct RestoreMap native callback

- VA `0x6F5790..0x6F57E7`; raw `0x2F4B90..0x2F4BE7`; `87` bytes; SHA256 `121f17c9df6d15c936ee12e3fce63d98478b0aa9ab8bd316f4d123aeacec330c`.

```asm
006f5790 <.data+0x2f4b90>:
  6f5790:	55                   	push   ebp
  6f5791:	8b ec                	mov    ebp,esp
  6f5793:	83 e4 f8             	and    esp,0xfffffff8
  6f5796:	83 ec 14             	sub    esp,0x14
  6f5799:	53                   	push   ebx
  6f579a:	8b ce                	mov    ecx,esi
  6f579c:	e8 4f f9 ff ff       	call   0x6f50f0
  6f57a1:	8b d8                	mov    ebx,eax
  6f57a3:	8b c7                	mov    eax,edi
  6f57a5:	8d 50 01             	lea    edx,[eax+0x1]
  6f57a8:	8a 08                	mov    cl,BYTE PTR [eax]
  6f57aa:	40                   	inc    eax
  6f57ab:	84 c9                	test   cl,cl
  6f57ad:	75 f9                	jne    0x6f57a8
  6f57af:	2b c2                	sub    eax,edx
  6f57b1:	50                   	push   eax
  6f57b2:	57                   	push   edi
  6f57b3:	56                   	push   esi
  6f57b4:	e8 b7 94 00 00       	call   0x6fec70
  6f57b9:	89 44 24 14          	mov    DWORD PTR [esp+0x14],eax
  6f57bd:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  6f57c0:	83 c4 0c             	add    esp,0xc
  6f57c3:	83 e8 10             	sub    eax,0x10
  6f57c6:	50                   	push   eax
  6f57c7:	8d 4c 24 0c          	lea    ecx,[esp+0xc]
  6f57cb:	51                   	push   ecx
  6f57cc:	53                   	push   ebx
  6f57cd:	56                   	push   esi
  6f57ce:	c7 44 24 20 04 00 00 	mov    DWORD PTR [esp+0x20],0x4
  6f57d5:	00 
  6f57d6:	e8 c5 61 00 00       	call   0x6fb9a0
  6f57db:	83 c4 10             	add    esp,0x10
  6f57de:	83 46 08 f0          	add    DWORD PTR [esi+0x8],0xfffffff0
  6f57e2:	5b                   	pop    ebx
  6f57e3:	8b e5                	mov    esp,ebp
  6f57e5:	5d                   	pop    ebp
  6f57e6:	c3                   	ret
```

### N30. Table chapter state producer on object scene return

- VA `0x47E750..0x47E890`; raw `0x7DB50..0x7DC90`; `320` bytes; SHA256 `85e6e5c81b9b316339c7f67d2aaf7a993fa24d960bc6b65ef66a096a0c2bfb66`.

```asm
0047e750 <.data+0x7db50>:
  47e750:	55                   	push   ebp
  47e751:	8b ec                	mov    ebp,esp
  47e753:	6a ff                	push   0xffffffff
  47e755:	68 ec 00 92 00       	push   0x9200ec
  47e75a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  47e760:	50                   	push   eax
  47e761:	83 ec 3c             	sub    esp,0x3c
  47e764:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  47e769:	33 c5                	xor    eax,ebp
  47e76b:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  47e76e:	53                   	push   ebx
  47e76f:	56                   	push   esi
  47e770:	50                   	push   eax
  47e771:	8d 45 f4             	lea    eax,[ebp-0xc]
  47e774:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  47e77a:	f6 05 7c af fa 00 01 	test   BYTE PTR ds:0xfaaf7c,0x1
  47e781:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  47e784:	89 47 10             	mov    DWORD PTR [edi+0x10],eax
  47e787:	89 4f 14             	mov    DWORD PTR [edi+0x14],ecx
  47e78a:	75 27                	jne    0x47e7b3
  47e78c:	83 0d 7c af fa 00 01 	or     DWORD PTR ds:0xfaaf7c,0x1
  47e793:	c7 45 fc 00 00 00 00 	mov    DWORD PTR [ebp-0x4],0x0
  47e79a:	e8 71 ec 10 00       	call   0x58d410
  47e79f:	68 c0 cd bc 00       	push   0xbccdc0
  47e7a4:	e8 71 3b 41 00       	call   0x89231a
  47e7a9:	83 c4 04             	add    esp,0x4
  47e7ac:	c7 45 fc ff ff ff ff 	mov    DWORD PTR [ebp-0x4],0xffffffff
  47e7b3:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  47e7b6:	8d 75 d4             	lea    esi,[ebp-0x2c]
  47e7b9:	e8 c2 07 f9 ff       	call   0x40ef80
  47e7be:	bb 08 00 00 00       	mov    ebx,0x8
  47e7c3:	c7 45 fc 01 00 00 00 	mov    DWORD PTR [ebp-0x4],0x1
  47e7ca:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  47e7cd:	72 02                	jb     0x47e7d1
  47e7cf:	8b 00                	mov    eax,DWORD PTR [eax]
  47e7d1:	68 dc 32 c0 00       	push   0xc032dc
  47e7d6:	68 80 af fa 00       	push   0xfaaf80
  47e7db:	8b c8                	mov    ecx,eax
  47e7dd:	ba fc 32 c0 00       	mov    edx,0xc032fc
  47e7e2:	e8 29 04 11 00       	call   0x58ec10
  47e7e7:	83 ce ff             	or     esi,0xffffffff
  47e7ea:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  47e7ed:	39 5d e8             	cmp    DWORD PTR [ebp-0x18],ebx
  47e7f0:	72 0c                	jb     0x47e7fe
  47e7f2:	8b 55 d4             	mov    edx,DWORD PTR [ebp-0x2c]
  47e7f5:	52                   	push   edx
  47e7f6:	e8 11 2a 41 00       	call   0x89120c
  47e7fb:	83 c4 04             	add    esp,0x4
  47e7fe:	f6 05 7c af fa 00 01 	test   BYTE PTR ds:0xfaaf7c,0x1
  47e805:	75 23                	jne    0x47e82a
  47e807:	83 0d 7c af fa 00 01 	or     DWORD PTR ds:0xfaaf7c,0x1
  47e80e:	c7 45 fc 02 00 00 00 	mov    DWORD PTR [ebp-0x4],0x2
  47e815:	e8 f6 eb 10 00       	call   0x58d410
  47e81a:	68 c0 cd bc 00       	push   0xbccdc0
  47e81f:	e8 f6 3a 41 00       	call   0x89231a
  47e824:	83 c4 04             	add    esp,0x4
  47e827:	89 75 fc             	mov    DWORD PTR [ebp-0x4],esi
  47e82a:	8b 4f 14             	mov    ecx,DWORD PTR [edi+0x14]
  47e82d:	8d 75 b8             	lea    esi,[ebp-0x48]
  47e830:	e8 4b 07 f9 ff       	call   0x40ef80
  47e835:	c7 45 fc 03 00 00 00 	mov    DWORD PTR [ebp-0x4],0x3
  47e83c:	39 58 14             	cmp    DWORD PTR [eax+0x14],ebx
  47e83f:	72 02                	jb     0x47e843
  47e841:	8b 00                	mov    eax,DWORD PTR [eax]
  47e843:	68 24 33 c0 00       	push   0xc03324
  47e848:	68 80 af fa 00       	push   0xfaaf80
  47e84d:	8b c8                	mov    ecx,eax
  47e84f:	ba fc 32 c0 00       	mov    edx,0xc032fc
  47e854:	e8 b7 03 11 00       	call   0x58ec10
  47e859:	39 5d cc             	cmp    DWORD PTR [ebp-0x34],ebx
  47e85c:	72 0c                	jb     0x47e86a
  47e85e:	8b 45 b8             	mov    eax,DWORD PTR [ebp-0x48]
  47e861:	50                   	push   eax
  47e862:	e8 a5 29 41 00       	call   0x89120c
  47e867:	83 c4 04             	add    esp,0x4
  47e86a:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  47e86d:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  47e874:	59                   	pop    ecx
  47e875:	5e                   	pop    esi
  47e876:	5b                   	pop    ebx
  47e877:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  47e87a:	33 cd                	xor    ecx,ebp
  47e87c:	e8 80 27 41 00       	call   0x891001
  47e881:	8b e5                	mov    esp,ebp
  47e883:	5d                   	pop    ebp
  47e884:	c2 04 00             	ret    0x4
  47e887:	cc                   	int3
  47e888:	cc                   	int3
  47e889:	cc                   	int3
  47e88a:	cc                   	int3
  47e88b:	cc                   	int3
  47e88c:	cc                   	int3
  47e88d:	cc                   	int3
  47e88e:	cc                   	int3
  47e88f:	cc                   	int3
```

## VI. Original Quest15 Event.stp scripts (XOR-FF, original offset, SHA)

**These are verbatim decoded script resources**, not a synthetic reproduction, and their ordering across scene indices is not proven runtime ordering. They are indexed by `-- Quest #15 / Scene #n` own comments; actual Table/SceneList.xml payload has not been dumped.

### Quest #15 / Scene #1 — `Square_Tutorial01`

- Event.stp original encoded byte range `0x96943E..0x9696A6`, `616` bytes, SHA256 of decoded segment `e0a3e5809ea2d39116b4a11adb9e2d3c9173d89c16cdfe8343e8f7f563de5deb`.

```lua
-- Quest #15 / Scene #1 - Function Square_Tutorial01
function Square_Tutorial01()
	SetTransitionType(2)
	SetFinalMusic("")
	HideOriginalObjs(1)
	Phase1()

	LoadMap("Square03D.fld")
	MoveCamera(0.00, 0.00, 0.00)
	RotCamera(0.00, 1.57, 100.00)

	CreateObject(1, 10338, 869.00, 1052.00, 0, 0, FALSE, 0, 0)

	Phase2()
	Phase3()
	Phase4()

	PlayMusic("BGM040.ogg")
	PlayCameraNoWait("Square_Tutorial01_01.cam", 0, 0.00, 0.00, 0.00)
	wait(500)
	OpenTalkScene(3, 22)

	RevPhase4()
	RevPhase3()
	RevPhase2()

	Q.DeleteAllObject()
	RestoreMap()

	RevPhase1()
end

Register(Square_Tutorial01)
```

### Quest #15 / Scene #2 — `scenario_tuto1_1`

- Event.stp original encoded byte range `0x96883E..0x968C4F`, `1041` bytes, SHA256 of decoded segment `1ba55891d8ef770a868128ba0ebd18fff44524128e70d066b8faf67441f2b012`.

```lua
-- Quest #15 / Scene #2 - Function scenario_tuto1_1
function scenario_tuto1_1()
	SetTransitionType(2)
	SetFinalMusic("")
	HideOriginalObjs(1)
	Phase1()

	LoadMap("Square03D.fld")
	MoveCamera(869.00, 1037.00, 171.80)
	RotCamera(0.70, 1.47, 30.00)

	CreateObject(0, 10338, 869.00, 1052.00, 0, 0, FALSE, 0, 0)
	CreateObject(1, 1478, 864.00, 1032.00, 128, 0, FALSE, 1, 1)
	CreateObject(2, 1479, 869.00, 1027.00, 128, 0, FALSE, 1, 10)
	CreateObject(3, 1480, 869.00, 1042.00, 0, 0, FALSE, 1, 19)
	CreateObject(4, 1481, 874.00, 1032.00, 128, 0, FALSE, 1, 28)

	Phase2()
	Phase3()
	Phase4()

	OpenTalkScene(3, 15)
	OpenTalkScene(3, 16)
	OpenTalkScene(3, 17)
	PlayCameraNoWait("scenario_tuto1_1.cam", 0, 0.00, 0.00, 0.00)
	WarpObject(3, 869.000000, 1038.000000, 0.000000, 0, 1, 1)
	FaceObject(2, 10, 0)
	RotateObject(1, 50, 1)
	RotateObject(4, 206, 1)
	wait(500)
	OpenTalkScene(3, 25)

	RevPhase4()
	RevPhase3()
	RevPhase2()

	Q.DeleteAllObject()
	RestoreMap()

	RevPhase1()
end

Register(scenario_tuto1_1)
```

### Quest #15 / Scene #3 — `pindos_talkevent`

- Event.stp original encoded byte range `0x8C1C3E..0x8C2276`, `1592` bytes, SHA256 of decoded segment `3c848c3f678426bd46899c18cf923688900168e9638d9c8d7a694ebd9b7e09ee`.

```lua
-- Quest #15 / Scene #3 - Function pindos_talkevent
function pindos_talkevent()
	SetTransitionType(2)
	SetFinalMusic("BGM003.ogg")
	HideOriginalObjs(1)
	Phase1()

	LoadMap("town001D.map")
	MoveCamera(755.00, 416.00, 57.75)
	RotCamera(5.67, 1.33, 55.00)

	CreateObject(0, 1478, 751.00, 416.00, 128, 0, FALSE, 1, 1)
	CreateObject(1, 1479, 760.00, 416.00, 128, 0, FALSE, 1, 10)
	CreateObject(2, 1480, 755.00, 429.00, 0, 0, FALSE, 1, 19)
	CreateObject(3, 1481, 755.00, 421.00, 128, 0, FALSE, 1, 28)
	CreateObject(4, 10047, 734.00, 744.00, 0, 0, FALSE, 0, 0)

	Phase2()
	Phase3()
	Phase4()

	PlayMusic("BGM003.ogg")
	PlayCameraNoWait("tutorial_01_18.cam", 0, 0.00, 0.00, 0.00)
	wait(2000)
	OpenTalkScene(3, 18)
	PlayCameraNoWait("tutorial_01_18b.cam", 0, 0.00, 0.00, 0.00)
	wait(1000)
	WalkObject(2, 755.000000, 439.000000, 0.000000, 1, 4, 3)
	wait(1500)
	AniObject(2, 2, 1)
	RotateObject(2, 0, 1)
	wait(1000)
	OpenTalkScene(3, 24)
	PlayCamera("tutorial_01_19.cam", 0, 0.00, 0.00, 0.00)
	OpenTalkScene(3, 20)
	PlayCameraNoWait("tutorial_01_20.cam", 0, 0.00, 0.00, 0.00)
	wait(500)
	OpenTalkScene(3, 21)
	PlayCamera("tutorial_01_22.cam", 0, 0.00, 0.00, 0.00)
	ClearObjects()
	PlayCameraNoWait("tutorial_01_21.cam", 0, 0.00, 0.00, 0.00)
	PlayMusic("BGM007.ogg")
	wait(3000)
	FlyingObject("Image/Prologue/Phindous00_1.dds", 50, 35, 100, 9999, 0, 0)
	wait(4000)
	DelFlyingObject()
	DoProlog(1)
	PlayMusic("BGM003.ogg")

	RevPhase4()
	RevPhase3()
	RevPhase2()

	Q.DeleteAllObject()
	RestoreMap()

	RevPhase1()
end

Register(pindos_talkevent)
```

### Quest #15 / Scene #4 — `scenario_tuto2_1`

- Event.stp original encoded byte range `0x96903E..0x9691D8`, `410` bytes, SHA256 of decoded segment `d6ca315a6eb92441b1271a7e9581328e9a0689afbf95bdca2b0812b53eb4dda2`.

```lua
-- Quest #15 / Scene #4 - Function scenario_tuto2_1
function scenario_tuto2_1()
	SetTransitionType(0)
	SetFinalMusic("")
	HideOriginalObjs(0)
	Phase1()

	LoadMap("")
	MoveCamera(0.00, 0.00, 0.00)
	RotCamera(0.00, 1.57, 100.00)


	Phase2()
	Phase3()
	Phase4()


	RevPhase4()
	RevPhase3()
	RevPhase2()

	Q.DeleteAllObject()
	RestoreMap()

	RevPhase1()
end

Register(scenario_tuto2_1)
```

## VII. Separate Client / Server / Cross-task / Runtime gaps and unblock routes

**Client still to reverse:** Full native implementation for `RestoreMap` and `LoadMap` side effects (the observed `0x6F5790` is a generic Lua global name registration, not a proven callback); identify ultimate scene scheduler that causes a Pindos terminal Scene to run without assuming key selection; complete `0x47E750` persistence boundary; `0x47E640` list/search corner cases and duplicate entries, and downstream Map UI unwind. Obtain actual decompressed **`Table/SceneList.xml`** chapter+scene rows and **`Event/SceneList.xml`** rows and validate the `(15,3)` intersection. The two STPD archives cannot be mistaken for decoded XML because their bodies contain compressed/packed data; filename index alone is not enough.

**Server to develop:** Decide authoritative Quest16 completion key distribution, Quest15 eligibility/accept/complete/award, and if/when chapter/scene selection data delivered or triggered; base compatibility on Client confirmed opcodes `0x1C`,`0x3F` outgoing and `0x38`,`0x40`,`0x45`,`0x46`,`0x6F`,`0x74` inbound with their conditions, not on invented official packet ordering or reward transactions. In particular **`S→C 0x46(15,0) → mode3 TalkBox` is not native evidence of `sceneIdx=3`**.

**Cross-task integration:** T02 socket/frame and actual packet routing; T07 Scene scheduler, map load/render return; T08 first-party unpacking/validation of `Table/SceneList.xml`; T06 NPC/scene UI event; T03/T04 character/wold snapshot; T14 stage; T15 persistence; T01 strict returned issue `T01-RETURN-T16-117-Q16-MODE2-C2S36-001` needs separate author erratum; S00 limited SPEC/GAP/TEST design, no server code here. No S00 RR owned by T16 at check time.

**Runtime/player verification:** Capture Quest15 NPC click, scene FIRST/NEXT keys before and after Pindos, `RestoreMap` Player position and world-state/UI return, playable new village/quest chain and Server events. Original Server internal policy need not be reverse engineered to complete Client analysis, but cannot be asserted either.

### Exact blockers and next research

1. **Actual row values/order of `Table/SceneList.xml`** missing due STPD-only native source; only source file names and parser verified. Unblock: decode actual Table.stp archive using independently verified STPD unpacker (T08) or an established canonical extracted `Table/SceneList.xml` with its provenance and SHA.
2. **Native RestoreMap side effects** beyond binding and Lua ordering not located. Unblock: trace script `Q.RestoreMap` / global callback registration through VM and original scene entity/UI manager, then map callback class vtable and readers/writers. T07 has responsibility but T16 should incorporate confirmed contract when available.
3. **Explicit original runtime completion→scene selection** not directly in static evidence; existing conditional producer path does not prove exact history. Unblock: Client packet trace + table row validation and event dispatcher state, then compare one complete Pindos route. This is a separate runtime acceptance boundary, not permission to guess official Server policy.
4. **T01 mode2/0x36 correction**: preserve 117 immutable original, draft dedicated erratum D.1/D.3 using T16-121+122 bytes; request T01 re-review after branch change. Do not self-mark RESOLVED.

### Final status

**T16-130**: original BIN-first Table/SceneList→FIRST/NEXT→Event SceneList scene-loader subchain and Pindos Lua resources **bounded complete as to conditional machinery**; **the strict playable Pindos end-to-end objective remains *not fully proven*** on the missing original Table XML row data/native RestoreMap callback and runtime sender/scene pairing. This is a *stage-result*, not a claim of original Server pairing or T01 FULL-PASS. Preserve this complete evidence draft and its unresolved branches even if submitting; do not rename the status to complete solely because GitHub commit succeeded.
