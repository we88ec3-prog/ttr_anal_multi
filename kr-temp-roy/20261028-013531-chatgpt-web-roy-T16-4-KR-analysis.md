# T16-4 — KR QuestInfo/QuestTalk XML 載入、欄位容器與證據分域

- 日期：2026-10-28 Asia/Taipei；工作批次 `20261028-013531`
- 研究者：`chatgpt-web roy`；版本 KR；任務：T16 任務與劇情流程
- 第一手映像：`Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（本輪直接核對）
- PE32 x86：`.text` VA `0x401000` → raw `0x400`；`.rdata` VA `0xBD2000` → raw `0x7D0600`。全部位址僅對 KR 適用。
- GitHub 啟動基準 HEAD `52452b5bc1bf0a6f7a10a7c1c83e4f3aca6a780d`；每次提交前再次核對。
- 分工：只記錄 T16 任務／教學接口，不改 T02/T03/T04/T07/T08/T14/T15 的主責。原檔未執行、未修改，靜態解析而非動態驗收。
- 證據定性：**原生已確認**指原映像的機器碼 bytes／靜態分支；**部分確認**指用途待上游或動態條件補證；**合理推測**不得當作官方行為；**未知**不以 fixture 補猜。

## 研究摘要

T16-4 追查兩個版本匹配的 KR 原生 XML 路徑消費函式，以及此前 `HasQuest`、`HasCompletableQuest`、`HasScenario` 解析器的子表輸出。**確認兩個 XML loader 是不同函式且都使用 `0x72EE30` 建立路徑／字串表示，隨後 `0x72F110` 進行資源開啟／處理候選，依返回布林值進入早期失敗路徑；不能因此認定該函式直接解析 Quest state。**

## 第一手 XML 函式對照

| KR 函式入口 | 原生路徑常數 | helper | early check | 判定 |
|---|---|---|---|---|
| `0x00504740` | `0x00C0DB48` (`QuestInfo.xml`) | `0x0072EE30`; `0x0072F110` | `[esp+0x170]` 非零走早期退出 | 已確認 client resource path + early branch |
| `0x00505570` | `0x00C0DB5C` (`QuestTalk.xml`) | `0x0072EE30`; `0x0072F110` | `[esp+0x68]` 非零走早期退出 | 已確認 client resource path + early branch |

局部失敗路徑並不等於「XML不存在」，且未證實可能的 all-or-nothing 全局副作用。`0x72F110` 的精確 ABI / 成功碼方向只由兩處分支觀察、其內部語義尚待完整查證。

### XML 載入和分支的完整關鍵原生片段

```asm
  504780:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  504783:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  50478a:	51                   	push   ecx
  50478b:	b9 48 db c0 00       	mov    ecx,0xc0db48
  504790:	89 44 24 40          	mov    DWORD PTR [esp+0x40],eax
  504794:	e8 97 a6 22 00       	call   0x72ee30
  504799:	33 ff                	xor    edi,edi
  50479b:	89 bc 24 60 02 00 00 	mov    DWORD PTR [esp+0x260],edi
  5047a2:	8b 8c 24 4c 01 00 00 	mov    ecx,DWORD PTR [esp+0x14c]
  5047a9:	bb 10 00 00 00       	mov    ebx,0x10
  5047ae:	39 9c 24 60 01 00 00 	cmp    DWORD PTR [esp+0x160],ebx
  5047b5:	73 07                	jae    0x5047be
  5047b7:	8d 8c 24 4c 01 00 00 	lea    ecx,[esp+0x14c]
  5047be:	57                   	push   edi
  5047bf:	8d b4 24 30 01 00 00 	lea    esi,[esp+0x130]
  5047c6:	e8 45 a9 22 00       	call   0x72f110
  5047cb:	80 bc 24 70 01 00 00 	cmp    BYTE PTR [esp+0x170],0x0
  5047d2:	00 
  5047d3:	74 5c                	je     0x504831
  5047d5:	c7 84 24 60 02 00 00 	mov    DWORD PTR [esp+0x260],0xffffffff
  5047dc:	ff ff ff ff 
  5047e0:	c7 84 24 2c 01 00 00 	mov    DWORD PTR [esp+0x12c],0xbf2394
  5047e7:	94 23 bf 00 
  5047eb:	39 9c 24 8c 01 00 00 	cmp    DWORD PTR [esp+0x18c],ebx
  5047f2:	72 10                	jb     0x504804
  5047f4:	8b 94 24 78 01 00 00 	mov    edx,DWORD PTR [esp+0x178]
  5047fb:	52                   	push   edx
  5047fc:	e8 0b ca 38 00       	call   0x89120c
  504801:	83 c4 04             	add    esp,0x4
  504804:	8d 8c 24 2c 01 00 00 	lea    ecx,[esp+0x12c]
  50480b:	c7 84 24 8c 01 00 00 	mov    DWORD PTR [esp+0x18c],0xf
  504812:	0f 00 00 00 
  504816:	89 bc 24 88 01 00 00 	mov    DWORD PTR [esp+0x188],edi
  50481d:	c6 84 24 78 01 00 00 	mov    BYTE PTR [esp+0x178],0x0
  504824:	00 
  504825:	e8 16 98 22 00       	call   0x72e040
  50482a:	33 c0                	xor    eax,eax
  50482c:	e9 a7 0c 00 00       	jmp    0x5054d8
  504831:	68 70 db c0 00       	push   0xc0db70
  504836:	8d 84 24 30 01 00 00 	lea    eax,[esp+0x130]
  50483d:	e8 9e 9a 22 00       	call   0x72e2e0
  504842:	3b c7                	cmp    eax,edi
  504844:	75 69                	jne    0x5048af
  504846:	68 7c db c0 00       	push   0xc0db7c
  50484b:	e8 10 93 1e 00       	call   0x6edb60
  504850:	c7 84      	mov    DWORD PTR [esp+0x264],0xffffffff
  504857:	    
  5055b0:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  5055b3:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  5055b7:	51                   	push   ecx
  5055b8:	b9 5c db c0 00       	mov    ecx,0xc0db5c
  5055bd:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  5055c1:	e8 6a 98 22 00       	call   0x72ee30
  5055c6:	33 db                	xor    ebx,ebx
  5055c8:	89 9c 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],ebx
  5055cf:	8b 4c 24 44          	mov    ecx,DWORD PTR [esp+0x44]
  5055d3:	bf 10 00 00 00       	mov    edi,0x10
  5055d8:	39 7c 24 58          	cmp    DWORD PTR [esp+0x58],edi
  5055dc:	73 04                	jae    0x5055e2
  5055de:	8d 4c 24 44          	lea    ecx,[esp+0x44]
  5055e2:	53                   	push   ebx
  5055e3:	8d 74 24 28          	lea    esi,[esp+0x28]
  5055e7:	e8 24 9b 22 00       	call   0x72f110
  5055ec:	38 5c 24 68          	cmp    BYTE PTR [esp+0x68],bl
  5055f0:	74 4f                	je     0x505641
  5055f2:	c7 84 24 b0 00 00 00 	mov    DWORD PTR [esp+0xb0],0xffffffff
  5055f9:	ff ff ff ff 
  5055fd:	c7 44 24 24 94 23 bf 	mov    DWORD PTR [esp+0x24],0xbf2394
  505604:	00 
  505605:	39 bc 24 84 00 00 00 	cmp    DWORD PTR [esp+0x84],edi
  50560c:	72 0d                	jb     0x50561b
  50560e:	8b 54 24 70          	mov    edx,DWORD PTR [esp+0x70]
  505612:	52                   	push   edx
  505613:	e8 f4 bb 38 00       	call   0x89120c
  505618:	83 c4 04             	add    esp,0x4
  50561b:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  50561f:	c7 84 24 84 00 00 00 	mov    DWORD PTR [esp+0x84],0xf
  505626:	0f 00 00 00 
  50562a:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  505631:	88 5c 24 70          	mov    BYTE PTR [esp+0x70],bl
  505635:	e8 06 8a 22 00       	call   0x72e040
  50563a:	33 c0                	xor    eax,eax
  50563c:	e9 ec 01 00 00       	jmp    0x50582d
  505641:	68 44 dc c0 00       	push   0xc0dc44
  505646:	8d 44 24 28          	lea    eax,[esp+0x28]
  50564a:	e8 91 8c 22 00       	call   0x72e2e0
  50564f:	3b c3                	cmp    eax,ebx
  505651:	75 5c                	jne    0x5056af
  505653:	68 50 dc c0 00       	push   0xc0dc50
  505658:	e8 03 85 1e 00       	call   0x6edb60
  50565d:	c7 84 24 b4 00 00 00 	mov    DWORD PTR [esp+0xb4],0xffffffff
  505664:	ff    
```

## 任務相關的另一解析器（**schema origin 未閉合**）

`0x53FD76..0x53FDF2` 透過四個 key 查找，依 null check 各別傳入 `0x53FEB0`，目標容器分別 base、base+0x10、+0x20、+0x30。依先前 T16-2 來源字串：`HasQuest`、`HasCompletableQuest`、`HasScenario` 是其中三個，第一個名稱請以直接 ASCII 讀取確認；目前只確定四個獨立欄位，**不能宣稱它們一定是 QuestInfo.xml 或 QuestTalk.xml 欄位，因為路徑與解析器資料流尚無直通證據**。

```asm
  53fd76:	68 e4 f4 c0 00       	push   0xc0f4e4
  53fd7b:	8b c3                	mov    eax,ebx
  53fd7d:	e8 5e e5 1e 00       	call   0x72e2e0
  53fd82:	8b f8                	mov    edi,eax
  53fd84:	68 ec f4 c0 00       	push   0xc0f4ec
  53fd89:	8b c3                	mov    eax,ebx
  53fd8b:	e8 50 e5 1e 00       	call   0x72e2e0
  53fd90:	8b f0                	mov    esi,eax
  53fd92:	68 f8 f4 c0 00       	push   0xc0f4f8
  53fd97:	8b c3                	mov    eax,ebx
  53fd99:	e8 42 e5 1e 00       	call   0x72e2e0
  53fd9e:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  53fda2:	68 0c f5 c0 00       	push   0xc0f50c
  53fda7:	8b c3                	mov    eax,ebx
  53fda9:	e8 32 e5 1e 00       	call   0x72e2e0
  53fdae:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  53fdb2:	85 ff                	test   edi,edi
  53fdb4:	74 0c                	je     0x53fdc2
  53fdb6:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  53fdba:	51                   	push   ecx
  53fdbb:	8b c7                	mov    eax,edi
  53fdbd:	e8 ee 00 00 00       	call   0x53feb0
  53fdc2:	8b 7c 24 14          	mov    edi,DWORD PTR [esp+0x14]
  53fdc6:	85 f6                	test   esi,esi
  53fdc8:	74 0b                	je     0x53fdd5
  53fdca:	8d 57 10             	lea    edx,[edi+0x10]
  53fdcd:	52                   	push   edx
  53fdce:	8b c6                	mov    eax,esi
  53fdd0:	e8 db 00 00 00       	call   0x53feb0
  53fdd5:	8b 44 24 20          	mov    eax,DWORD PTR [esp+0x20]
  53fdd9:	85 c0                	test   eax,eax
  53fddb:	74 09                	je     0x53fde6
  53fddd:	8d 4f 20             	lea    ecx,[edi+0x20]
  53fde0:	51                   	push   ecx
  53fde1:	e8 ca 00 00 00       	call   0x53feb0
  53fde6:	8b 44 24 1c          	mov    eax,DWORD PTR [esp+0x1c]
  53fdea:	85 c0                	test   eax,eax
  53fdec:	74 09                	je     0x53fdf7
  53fdee:	8d 57 30             	lea    edx,[edi+0x30]
  53fdf1:	52                   	push   edx
  53fdf2:	e8 b9 00 00 00       	call   0x53feb0
  53fdf7:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  53fdfb:	89 7c 24 28          	mov    DWORD PTR [esp+0x28],edi
  53fdff:	8d 7c 24 24          	lea    edi,[esp+0x24]
  53fe03:	be dc 18 fe 00       	mov    esi,0xfe18dc
  53fe08:	89 44 24 24          	mov    DWORD PTR [esp+0x24],eax
  53fe0c:	e8 0f f1 03 00       	call   0x57ef20
  53fe11:	50                   	push   eax
  53fe12:	56                   	push   esi
  53fe13:	8d 74 24 34          	lea    esi,[esp+0x34]
  53fe17:	e8 34 ea 03 00       	call   0x57e850
  53fe1c:	33 f6                	xor    esi,esi
  53fe1e:	8b 5b 40             	mov    ebx,DWORD PTR [ebx+0x40]
  53fe21:	3b de                	cmp    ebx,esi
  53fe23:	0f 85 cc fe ff ff    	jne    0x53fcf5
```

### 解析器後段新結論

- `0x53FDF7` 取 `[esp+0x18]`，`0x53FE03 mov esi,0xFE18DC`，隨後呼叫 `0x57EF20`、`0x57E850`，之後 `mov ebx,[ebx+0x40]` 返回 `0x53FCF5`。這是可確認的鏈結／節點迴圈，但 `0xFE18DC` 的實際容器型別及 writer 未確認。
- `0x53FEB0` 由四個位置直接呼叫，表示共用欄位展開 helper。沒有看到其資料持久化 API，**輸出偏移**不是保存檔 offset。
- QuestInfo/QuestTalk 目前只能確定原生檔名、入口與初期分支；缺 XML bytes，無法枚舉任務 ID、任務章節、NPC、獎勵和台韓對照。

### 有界偽碼（僅展示靜態已知）

```cpp
void parse_quest_related_attributes_candidate(Node* n, Output* out) {
    auto a = lookup(n, key0);
    auto b = lookup(n, "HasQuest");
    auto c = lookup(n, "HasCompletableQuest");
    auto d = lookup(n, "HasScenario");
    if (a) parse_child_list(a, out + 0x00);
    if (b) parse_child_list(b, out + 0x10);
    if (c) parse_child_list(c, out + 0x20);
    if (d) parse_child_list(d, out + 0x30);
    append_to_unknown_container(/*0xFE18DC reference*/);
}
```

**以上為表示性 pseudocode，Node/Output 型別、四個值的含義與 `0xFE18DC` 容器 ownership 尚未確認。**

## source-inventory 與 KR/TC 差異

| 類別 | KR (本輪直接驗證) | TC | 可信度／限制 |
|---|---|---|---|
| PE 映像 | SHA 如文件首 | 只知 repo TC metadata SHA | KR 原生確認、TC 缺原檔 |
| QuestInfo.xml | 原生路徑 + `0x504740` | unknown | 不代表取得 XML 内容 |
| QuestTalk.xml | 原生路徑 + `0x505570` | unknown | 不代表取得 XML 内容 |
| Quest state schema | `HasQuest` 三項解析候選 | unknown | 未綁定上述 XML loader |
| tutorial Lua | T16-2/3 入口查證 | unknown | 沒有 Lua 腳本文本 |
| MAINLINE-FLOW 舊測試 | 不採作官方來源 | unknown | historical fixture only |

## tutorial-node-matrix / early-mainline-flow

| 結點 | source | prerequisites | event | authority | writer | UI/notification | unlock/relogin | 判定 |
|---|---|---|---|---|---|---|---|---|
| Tutorial entry | KR `0x4A8A60` | unknown | local invocation | unknown | unknown | unknown | unknown | native entry confirmed |
| Quest table resource | KR `0x504740` | n/a | parse/open | unknown | unknown | unknown | unknown | native resource handler |
| Quest dialogue resource | KR `0x505570` | n/a | parse/open | unknown | unknown | unknown | unknown | native resource handler |
| First mainline quest | unknown | unknown | unknown | unknown | unknown | unknown | unknown | gap, no conjectured ID |
| First mainline delivery | unknown | unknown | unknown | unknown | unknown | unknown | unknown | gap |
| Post-mainline unlock | unknown | unknown | unknown | unknown | unknown | unknown | unknown | gap |

## cross-task-interfaces / acceptance / unresolved

- T04/T03：角色已存在且能登入是 T16 的輸入，現無證據將 XML 預設值等同角色初始旗標。
- T02：XML 客戶端顯示不等於封包 server authority；封包 ID 與 payload unknown。
- T07/T14：任務要求的關卡事件與通關結果尚未鏈接原生 quest writer。
- T15：需要持久化的 task/step/完成欄位 unknown。
- 驗收已達：KR 兩個 distinct loader、失敗分支、欄位展開與容器候選，直接 BIN bytes／assembly 引用。
- 驗收未達：客戶端 quest writer/consumer 閉環、教學完成主線解鎖、重登入續接、實際 XML 任務定義、TC 欄位比較、可玩性。
- 下一段 T16-5：定位 QuestInfo/QuestTalk loader 的 call sites、最早有效 root / node、資料表索引寫入／讀取者；另索引 `0xFE18DC` consumers。

## 禁止事項

不推論官方任務 ID；不搬運 KR 地址到 TC；不變更 catalog/owner；不更動遊戲程式；不拿歷史修補/AI fixture 作 native completion。