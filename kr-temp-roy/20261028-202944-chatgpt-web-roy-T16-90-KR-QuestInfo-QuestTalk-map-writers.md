# KR T16-90 — QuestInfo／QuestTalk XML 寫入樹狀索引與欄位結構（BIN-first）

> 研究者：chatgpt-web roy；2026-10-28 20:29:44 Asia/Taipei；承接 T16-89，僅 KR Client。此文件獨立保存原始可驗證證據，不等同 Quest C→S／S→C 封包已完成。

## 0. 原件與限制

- 直接驗證 `/mnt/data/Tartaros.bin`：12,472,320 bytes；SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- `/mnt/data/Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- `objdump -h` 已確認 PE32 x86：`.text` VA `0x401000` raw `0x400` → **raw=VA−0x400C00**；`.rdata` VA `0xBD2000` raw `0x7D0600` → **raw=VA−0x401A00**；`.data` VA `0xD61000` raw `0x95E800` → **raw=VA−0x402800**。下方所有執行位址以 `.text` 轉換，不混用 sections。
- 直接從原始機器碼 `objdump -d -Mintel` 復核；反編譯與前稿僅為導航。程式未執行、附加、修改；沒有 Quest XML 實體檔、原始 Server、執行期封包紀錄。原生語意不確定處標 unknown。
- GitHub 先核對最新 `main` T16-89 `kr-temp-roy/20261028-202525-chatgpt-web-roy-T16-89-KR-QuestInfo-QuestTalk-actual-loaders.md` 與 `kr/tasks/T16/task.json`；前段已由 `0x504370` 確認 `0x504740`（QuestInfo）再 `0x505570`（QuestTalk）。本段不更動其他 Task 的 catalog / owner / 技術檔。

## 1. T16-90 第 1 輪：QuestTalk XML row 的可驗證儲存鏈

### 1.1 XML 資料來源（正確 `.rdata` VA/raw）

| XML 名稱／欄位 | VA | raw | native 直接引用 |
|---|---|---|---|
| `Table/QuestTalk.xml` | `0xC0DB5C` | `0x80C15C` | `0x5055B8` |
| `QuestTalk` | `0xC0DC44` | `0x80C244` | `0x505641` |
| `id` | `0xBED1D0` | `0x7EB7D0` | `0x5056C9` |
| `givertalk` | `0xC0DC68` | `0x80C268` | `0x505723` |
| `givertotalk` | `0xC0DC74` | `0x80C274` | `0x50574D` |
| `finishertalk` | `0xC0DC80` | `0x80C280` | `0x50577A` |
| `Table/QuestInfo.xml` | `0xC0DB48` | `0x80C148` | `0x50478B` |
| `AcceptAction` | `0xC0DBD0` | `0x80C1D0` | `0x504ADF` |
| `CompleteAction` | `0xC0DBE8` | `0x80C1E8` | `0x504B52` |

上述字串是 Client 本地 Quest 資料欄位，**不是直接確認的 network packet 或 Server 業務狀態**。

### 1.2 `0x505570` → `0x503D20`（key lookup）→ row fields

`0x5056AF` 先取得待解析 XML item；`0x5056C9` 以 `id` 鍵讀取文字欄位、用 `0x8917B4` 轉為整數，缺值時 0。`0x505700–0x50570B` 在 QuestTalk 容器中以整數鍵做 find，`0x50570F–0x50571D` 檢查是否為 sentinel / 存在值。取得有效 node 後，使用 node `+0x10` 作 row 的起始，對三項 talk 欄位繼續做字元→整數轉換，寫入 row 的 **`+0x30`、`+0x34`、`+0x38`**。相對於原 node，實際為 `+0x40/+0x44/+0x48`；不同類型的相同偏移不可相互合併。

**特別勘誤**：`0x503D20` 是帶 key 的 tree lower-bound/find helper；單靠 `call 0x503D20` **不能認定它負責插入新節點**。在 QuestTalk loader 中，此節的主要動作是對找到的容器項目進行欄位更新。若某個 ID 查無 node，控制流跳過三欄寫入；是否允許 QuestTalk-only ID 建立獨立項目仍待其他入口驗證。

### 1.3 簡化偽碼（證據限定，非原生符號）

```cpp
// 0x505570 successful XML row loop — layout names provisional
for (XmlNode* n = firstQuestTalkRow; n != nullptr; n = next(n)) {
    int key = attr_int_or_zero(n, "id");
    auto it = tree_find_or_end(questContainer, key); // 0x503D20
    if (it != questContainer.end()) {
        unsigned char* row = ((unsigned char*)it.node) + 0x10;
        *(uint32_t*)(row + 0x30) = attr_int_or_zero(n, "givertalk");
        *(uint32_t*)(row + 0x34) = attr_int_or_zero(n, "givertotalk");
        *(uint32_t*)(row + 0x38) = attr_int_or_zero(n, "finishertalk");
    }
}
```

本碼只表達此區段可見的 `id` lookup → 三個整數 writer；xml parser 的實際 class/呼叫慣例需依 ASM，不表示真實 C++ 原始碼如此命名。

## 2. QuestInfo（`0x504740`）容器寫入與分支

前段證實 `AcceptAction`、`CompleteAction` 為 XML 欄位查找。本段在 `0x505294–0x505470` 進一步核對：

- `0x505294–0x5052C2` 遍歷 XML nodes（虛呼叫 +0x18，next +0x50），`0x5052E4–0x5052E9` 透過 node vtable +0x30 取得內容，並在 `0x505307` 填入暫存結構。
- `0x505396: call 0x505870`：**樹狀容器按 key 查找／必要時插入**。`0x505870` 檢查 `[esi+0x4]` sentinel，樹 node 的 `+0x0C` 為比較的整數鍵；缺值時呼叫 `0x5063F0` 建立，並使用 `0x505E40` 等 helper 回傳可寫 row 指標（回傳 row = `node + 0x10`）。有舊項時沿 existing node `+0x10` 直接返回。這與 QuestTalk 的只查找並寫入不同。
- `0x5053A9: call 0x4026E0`，緊接 `0x505870`；從 caller 只可證它處理前一步建立／取回的 local row，完整複製／賦值語意及 `0x4026E0` 實際 ABI 需下段驗證，不能擅稱全部 QuestInfo 欄位佈局已還原。
- `0x50540D–0x50545F` 另呼叫 `0x5064D0`、`0x506310`、`0x505F70`、`0x5045C0` 做臨時結構／字串處理；區分它們與最終 map node 生命週期。
- `0x5054D8` 進入共同清理；不能用此出口推論 Server Quest persistence 或登入重載。

### QuestInfo 容器功能偽碼（限觀察）

```cpp
for (auto* info = firstInfoNode; info; info = nextInfoNode(info)) {
    // earlier nodes extract AcceptAction/CompleteAction and related attributes
    auto key = parsedInfoKey; // actual source examined at 0x5052xx–0x5053xx
    auto* destRow = questInfoTree_find_or_insert(key); // 0x505870
    assign_to_row(destRow, parsedTemporary); // 0x4026E0; exact ABI pending
    cleanup_temporaries();
}
```

此處 `parsedInfoKey` 具體來源與 `0x4026E0` 拷貝範圍尚未完成完整寄存器回溯，**不應從函式名稱假設 `AcceptAction` 就是接任務指令**。

## 3. 成功、失敗與證據邊界

| 資料流 | 可確認 | 不可推論 |
|---|---|---|
| QuestTalk XML `id` | `0x8917B4` 字元→整數，`0x503D20` tree lookup | wire Quest ID、Server 採用的完整主鍵規則 |
| QuestTalk talk 欄位 | `row+0x30/+0x34/+0x38` 寫入 3 個整數 | Quest 實際進度、NPC 是否可接 |
| QuestInfo XML row | `0x505870` 有界 find-or-insert，`0x4026E0` downstream | Server state writer／Quest cache snapshot |
| XML 讀檔失敗 | `0x5055EC` flag 與 `0x505641` node gate 限制 parser | 是否同步到伺服器、封包錯誤碼 |
| Client ↔ Server | 本段沒有看到已閉合 network producer/handler | opcode、長度、封包內容、Server 規則均 unknown |

本地 QuestInfo/QuestTalk 的資料載入是任務 **靜態定義表**，與角色在 Server 認可的**動態任務狀態**屬不同證據層。將載入表的 XML key/write 當成 S→C Quest cache writer，會錯誤產生偽封包。

## 4. 三輪門檻

- **T16-90 第一輪（本段已進行）**：從前段只定位 XML loader，延伸到 `QuestTalk id → tree lookup → 3 個 row 欄位 writer`，並從 `QuestInfo tree find/insert → row payload processing` 追到 `0x505870` 的 sentinel 比較、缺值插入和返回 row。此為新的可檢驗**多函式資料寫入鏈**，而非僅新增函式名字；足以達到本輪重大進展門檻。
- **T16-90-2**：未啟動，第一輪已達重大進展。
- **T16-90-3**：未啟動，第一輪已達重大進展。
- 下一段 **T16-91**：深入 `0x4026E0` 的 row copy/assign、`0x5063F0/0x505E40` 的初始化及真正 row layout；由 `0x504370` 的 xrefs 找到 Quest 靜態資料表 consumer，然後以「玩家 NPC 按接受」或 T02 inbound business dispatcher 獨立搜尋**動態任務狀態**，不能在 XML loader 停留太久。

## 5. 玩家情境 × Client/Server 資料與封包

| 玩家情境 | Client 本地處理 | C→S | S→C | Client 狀態／UI | Server 待開發 |
|---|---|---|---|---|---|
| 啟動讀取 QuestInfo | XML 資料解析，`0x505870` find-or-insert | unknown | unknown | 靜態 row 寫入已部分確認 | 不可自行發明 Quest opcode |
| 啟動讀取 QuestTalk | 依 XML `id` 查靜態 row，寫 3 個 talk 整數欄位 | unknown | unknown | 對話欄位填入 Client 本地表 | 不代表 Quest state accepted |
| NPC 接受任務 | callback 未確認 | unknown | unknown | cache writer unknown | 確認／拒絕協定待找 |
| Quest 完成／下一任務開放 | 靜態資料非 Server 判定證據 | unknown | unknown | unlock writer unknown | 原版 Server 判定／持久化未取得 |

## 6. 原始反組譯（KR BIN .text；全部由本次重新取得）

### QuestTalk key parsing, map lookup and payload writes — 0x5056c2–0x5057b0

```asm
  5056c2:	8b 44 24 14          	mov    eax,DWORD PTR [esp+0x14]
  5056c6:	8d 78 44             	lea    edi,[eax+0x44]
  5056c9:	68 d0 d1 be 00       	push   0xbed1d0
  5056ce:	e8 cd a9 22 00       	call   0x7300a0
  5056d3:	3b c3                	cmp    eax,ebx
  5056d5:	74 1a                	je     0x5056f1
  5056d7:	83 c0 30             	add    eax,0x30
  5056da:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  5056de:	72 02                	jb     0x5056e2
  5056e0:	8b 00                	mov    eax,DWORD PTR [eax]
  5056e2:	3b c3                	cmp    eax,ebx
  5056e4:	74 0b                	je     0x5056f1
  5056e6:	50                   	push   eax
  5056e7:	e8 c8 c0 38 00       	call   0x8917b4
  5056ec:	83 c4 04             	add    esp,0x4
  5056ef:	eb 02                	jmp    0x5056f3
  5056f1:	33 c0                	xor    eax,eax
  5056f3:	8b 74 24 18          	mov    esi,DWORD PTR [esp+0x18]
  5056f7:	8d 4c 24 20          	lea    ecx,[esp+0x20]
  5056fb:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  5056ff:	51                   	push   ecx
  505700:	8d 44 24 20          	lea    eax,[esp+0x20]
  505704:	8b ce                	mov    ecx,esi
  505706:	e8 15 e6 ff ff       	call   0x503d20
  50570b:	8b 4c 24 1c          	mov    ecx,DWORD PTR [esp+0x1c]
  50570f:	3b 4e 04             	cmp    ecx,DWORD PTR [esi+0x4]
  505712:	0f 84 92 00 00 00    	je     0x5057aa
  505718:	8d 71 10             	lea    esi,[ecx+0x10]
  50571b:	3b f3                	cmp    esi,ebx
  50571d:	0f 84 87 00 00 00    	je     0x5057aa
  505723:	68 68 dc c0 00       	push   0xc0dc68
  505728:	e8 73 a9 22 00       	call   0x7300a0
  50572d:	3b c3                	cmp    eax,ebx
  50572f:	74 1a                	je     0x50574b
  505731:	83 c0 30             	add    eax,0x30
  505734:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  505738:	72 02                	jb     0x50573c
  50573a:	8b 00                	mov    eax,DWORD PTR [eax]
  50573c:	3b c3                	cmp    eax,ebx
  50573e:	74 0b                	je     0x50574b
  505740:	50                   	push   eax
  505741:	e8 6e c0 38 00       	call   0x8917b4
  505746:	83 c4 04             	add    esp,0x4
  505749:	eb 02                	jmp    0x50574d
  50574b:	33 c0                	xor    eax,eax
  50574d:	68 74 dc c0 00       	push   0xc0dc74
  505752:	89 46 30             	mov    DWORD PTR [esi+0x30],eax
  505755:	e8 46 a9 22 00       	call   0x7300a0
  50575a:	3b c3                	cmp    eax,ebx
  50575c:	74 1a                	je     0x505778
  50575e:	83 c0 30             	add    eax,0x30
  505761:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  505765:	72 02                	jb     0x505769
  505767:	8b 00                	mov    eax,DWORD PTR [eax]
  505769:	3b c3                	cmp    eax,ebx
  50576b:	74 0b                	je     0x505778
  50576d:	50                   	push   eax
  50576e:	e8 41 c0 38 00       	call   0x8917b4
  505773:	83 c4 04             	add    esp,0x4
  505776:	eb 02                	jmp    0x50577a
  505778:	33 c0                	xor    eax,eax
  50577a:	68 80 dc c0 00       	push   0xc0dc80
  50577f:	89 46 34             	mov    DWORD PTR [esi+0x34],eax
  505782:	e8 19 a9 22 00       	call   0x7300a0
  505787:	3b c3                	cmp    eax,ebx
  505789:	74 1a                	je     0x5057a5
  50578b:	83 c0 30             	add    eax,0x30
  50578e:	83 78 14 10          	cmp    DWORD PTR [eax+0x14],0x10
  505792:	72 02                	jb     0x505796
  505794:	8b 00                	mov    eax,DWORD PTR [eax]
  505796:	3b c3                	cmp    eax,ebx
  505798:	74 0b                	je     0x5057a5
  50579a:	50                   	push   eax
  50579b:	e8 14 c0 38 00       	call   0x8917b4
  5057a0:	83 c4 04             	add    esp,0x4
  5057a3:	eb 02                	jmp    0x5057a7
  5057a5:	33 c0                	xor    eax,eax
  5057a7:	89 46 38             	mov    DWORD PTR [esi+0x38],eax
  5057aa:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  5057ae:	8b                   	.byte 0x8b
  5057af:	72                   	.byte 0x72
```

### Map key find helper (return existing/sentinel) — 0x503d20–0x503d89

```asm
  503d20:	55                   	push   ebp
  503d21:	8b ec                	mov    ebp,esp
  503d23:	51                   	push   ecx
  503d24:	53                   	push   ebx
  503d25:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  503d28:	56                   	push   esi
  503d29:	8b f1                	mov    esi,ecx
  503d2b:	8b 56 04             	mov    edx,DWORD PTR [esi+0x4]
  503d2e:	8b 4a 04             	mov    ecx,DWORD PTR [edx+0x4]
  503d31:	80 b9 b5 00 00 00 00 	cmp    BYTE PTR [ecx+0xb5],0x0
  503d38:	75 1e                	jne    0x503d58
  503d3a:	57                   	push   edi
  503d3b:	8b 3b                	mov    edi,DWORD PTR [ebx]
  503d3d:	8d 49 00             	lea    ecx,[ecx+0x0]
  503d40:	39 79 0c             	cmp    DWORD PTR [ecx+0xc],edi
  503d43:	7d 05                	jge    0x503d4a
  503d45:	8b 49 08             	mov    ecx,DWORD PTR [ecx+0x8]
  503d48:	eb 04                	jmp    0x503d4e
  503d4a:	8b d1                	mov    edx,ecx
  503d4c:	8b 09                	mov    ecx,DWORD PTR [ecx]
  503d4e:	80 b9 b5 00 00 00 00 	cmp    BYTE PTR [ecx+0xb5],0x0
  503d55:	74 e9                	je     0x503d40
  503d57:	5f                   	pop    edi
  503d58:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  503d5b:	89 55 08             	mov    DWORD PTR [ebp+0x8],edx
  503d5e:	3b d1                	cmp    edx,ecx
  503d60:	74 16                	je     0x503d78
  503d62:	8b 33                	mov    esi,DWORD PTR [ebx]
  503d64:	3b 72 0c             	cmp    esi,DWORD PTR [edx+0xc]
  503d67:	7c 0f                	jl     0x503d78
  503d69:	8d 4d 08             	lea    ecx,[ebp+0x8]
  503d6c:	8b 09                	mov    ecx,DWORD PTR [ecx]
  503d6e:	5e                   	pop    esi
  503d6f:	89 08                	mov    DWORD PTR [eax],ecx
  503d71:	5b                   	pop    ebx
  503d72:	8b e5                	mov    esp,ebp
  503d74:	5d                   	pop    ebp
  503d75:	c2 04 00             	ret    0x4
  503d78:	89 4d fc             	mov    DWORD PTR [ebp-0x4],ecx
  503d7b:	8d 4d fc             	lea    ecx,[ebp-0x4]
  503d7e:	8b 09                	mov    ecx,DWORD PTR [ecx]
  503d80:	5e                   	pop    esi
  503d81:	89 08                	mov    DWORD PTR [eax],ecx
  503d83:	5b                   	pop    ebx
  503d84:	8b e5                	mov    esp,ebp
  503d86:	5d                   	pop    ebp
  503d87:	c2                   	.byte 0xc2
  503d88:	04                   	.byte 0x4
```

### QuestInfo final structure writer and value lookup — 0x505294–0x505470

```asm
  505294:	8b b3 94 00 00 00    	mov    esi,DWORD PTR [ebx+0x94]
  50529a:	8d 7b 44             	lea    edi,[ebx+0x44]
  50529d:	3b f7                	cmp    esi,edi
  50529f:	74 28                	je     0x5052c9
  5052a1:	83 7e 28 10          	cmp    DWORD PTR [esi+0x28],0x10
  5052a5:	8d 46 14             	lea    eax,[esi+0x14]
  5052a8:	72 02                	jb     0x5052ac
  5052aa:	8b 00                	mov    eax,DWORD PTR [eax]
  5052ac:	68 d0 d1 be 00       	push   0xbed1d0
  5052b1:	50                   	push   eax
  5052b2:	e8 fa e9 38 00       	call   0x893cb1
  5052b7:	83 c4 08             	add    esp,0x8
  5052ba:	85 c0                	test   eax,eax
  5052bc:	0f 84 4a 02 00 00    	je     0x50550c
  5052c2:	8b 76 50             	mov    esi,DWORD PTR [esi+0x50]
  5052c5:	3b f7                	cmp    esi,edi
  5052c7:	75 d8                	jne    0x5052a1
  5052c9:	33 c0                	xor    eax,eax
  5052cb:	8d 78 10             	lea    edi,[eax+0x10]
  5052ce:	8b 4b 18             	mov    ecx,DWORD PTR [ebx+0x18]
  5052d1:	05 e8 03 00 00       	add    eax,0x3e8
  5052d6:	33 f6                	xor    esi,esi
  5052d8:	89 44 24 1c          	mov    DWORD PTR [esp+0x1c],eax
  5052dc:	3b ce                	cmp    ecx,esi
  5052de:	0f 84 ec 00 00 00    	je     0x5053d0
  5052e4:	8b 11                	mov    edx,DWORD PTR [ecx]
  5052e6:	8b 42 30             	mov    eax,DWORD PTR [edx+0x30]
  5052e9:	ff d0                	call   eax
  5052eb:	3b c6                	cmp    eax,esi
  5052ed:	0f 84 dd 00 00 00    	je     0x5053d0
  5052f3:	39 78 34             	cmp    DWORD PTR [eax+0x34],edi
  5052f6:	8d 48 20             	lea    ecx,[eax+0x20]
  5052f9:	72 02                	jb     0x5052fd
  5052fb:	8b 09                	mov    ecx,DWORD PTR [ecx]
  5052fd:	3b ce                	cmp    ecx,esi
  5052ff:	0f 84 cb 00 00 00    	je     0x5053d0
  505305:	33 d2                	xor    edx,edx
  505307:	c7 84 24 24 01 00 00 	mov    DWORD PTR [esp+0x124],0x7
  50530e:	07 00 00 00 
  505312:	89 b4 24 20 01 00 00 	mov    DWORD PTR [esp+0x120],esi
  505319:	66 89 94 24 10 01 00 	mov    WORD PTR [esp+0x110],dx
  505320:	00 
  505321:	c6 84 24 60 02 00 00 	mov    BYTE PTR [esp+0x260],0x6
  505328:	06 
  505329:	8b c1                	mov    eax,ecx
  50532b:	89 74 24 58          	mov    DWORD PTR [esp+0x58],esi
  50532f:	c7 44 24 5c 0f 00 00 	mov    DWORD PTR [esp+0x5c],0xf
  505336:	00 
  505337:	88 54 24 48          	mov    BYTE PTR [esp+0x48],dl
  50533b:	8d 70 01             	lea    esi,[eax+0x1]
  50533e:	8b ff                	mov    edi,edi
  505340:	8a 10                	mov    dl,BYTE PTR [eax]
  505342:	40                   	inc    eax
  505343:	84 d2                	test   dl,dl
  505345:	75 f9                	jne    0x505340
  505347:	2b c6                	sub    eax,esi
  505349:	50                   	push   eax
  50534a:	51                   	push   ecx
  50534b:	8d 4c 24 50          	lea    ecx,[esp+0x50]
  50534f:	e8 1c d7 ef ff       	call   0x402a70
  505354:	8d 44 24 48          	lea    eax,[esp+0x48]
  505358:	50                   	push   eax
  505359:	8d 84 24 14 01 00 00 	lea    eax,[esp+0x114]
  505360:	c6 84 24 64 02 00 00 	mov    BYTE PTR [esp+0x264],0x7
  505367:	07 
  505368:	e8 c3 ad f3 ff       	call   0x440130
  50536d:	83 c4 04             	add    esp,0x4
  505370:	c6 84 24 60 02 00 00 	mov    BYTE PTR [esp+0x260],0x6
  505377:	06 
  505378:	39 7c 24 5c          	cmp    DWORD PTR [esp+0x5c],edi
  50537c:	72 0d                	jb     0x50538b
  50537e:	8b 4c 24 48          	mov    ecx,DWORD PTR [esp+0x48]
  505382:	51                   	push   ecx
  505383:	e8 84 be 38 00       	call   0x89120c
  505388:	83 c4 04             	add    esp,0x4
  50538b:	8d 54 24 1c          	lea    edx,[esp+0x1c]
  50538f:	8d 8c 24 cc 00 00 00 	lea    ecx,[esp+0xcc]
  505396:	e8 d5 04 00 00       	call   0x505870
  50539b:	6a ff                	push   0xffffffff
  50539d:	6a 00                	push   0x0
  50539f:	8d 94 24 18 01 00 00 	lea    edx,[esp+0x118]
  5053a6:	52                   	push   edx
  5053a7:	8b c8                	mov    ecx,eax
  5053a9:	e8 32 d3 ef ff       	call   0x4026e0
  5053ae:	c6 84 24 60 02 00 00 	mov    BYTE PTR [esp+0x260],0x1
  5053b5:	01 
  5053b6:	83 bc 24 24 01 00 00 	cmp    DWORD PTR [esp+0x124],0x8
  5053bd:	08 
  5053be:	72 10                	jb     0x5053d0
  5053c0:	8b 84 24 10 01 00 00 	mov    eax,DWORD PTR [esp+0x110]
  5053c7:	50                   	push   eax
  5053c8:	e8 3f be 38 00       	call   0x89120c
  5053cd:	83 c4 04             	add    esp,0x4
  5053d0:	8b 73 40             	mov    esi,DWORD PTR [ebx+0x40]
  5053d3:	85 f6                	test   esi,esi
  5053d5:	74 18                	je     0x5053ef
  5053d7:	8b 16                	mov    edx,DWORD PTR [esi]
  5053d9:	8b 42 18             	mov    eax,DWORD PTR [edx+0x18]
  5053dc:	8b ce                	mov    ecx,esi
  5053de:	ff d0                	call   eax
  5053e0:	85 c0                	test   eax,eax
  5053e2:	0f 85 51 01 00 00    	jne    0x505539
  5053e8:	8b 76 40             	mov    esi,DWORD PTR [esi+0x40]
  5053eb:	85 f6                	test   esi,esi
  5053ed:	75 e8                	jne    0x5053d7
  5053ef:	33 c0                	xor    eax,eax
  5053f1:	8b d8                	mov    ebx,eax
  5053f3:	85 c0                	test   eax,eax
  5053f5:	0f 85 99 fe ff ff    	jne    0x505294
  5053fb:	8b 4c 24 64          	mov    ecx,DWORD PTR [esp+0x64]
  5053ff:	8d 94 24 a8 01 00 00 	lea    edx,[esp+0x1a8]
  505406:	89 8c 24 a4 01 00 00 	mov    DWORD PTR [esp+0x1a4],ecx
  50540d:	52                   	push   edx
  50540e:	8d 4c 24 68          	lea    ecx,[esp+0x68]
  505412:	e8 b9 10 00 00       	call   0x5064d0
  505417:	8b 74 24 3c          	mov    esi,DWORD PTR [esp+0x3c]
  50541b:	8d 84 24 a4 01 00 00 	lea    eax,[esp+0x1a4]
  505422:	50                   	push   eax
  505423:	8b ce                	mov    ecx,esi
  505425:	c6 84 24 64 02 00 00 	mov    BYTE PTR [esp+0x264],0x8
  50542c:	08 
  50542d:	e8 de 0e 00 00       	call   0x506310
  505432:	50                   	push   eax
  505433:	56                   	push   esi
  505434:	8d 74 24 48          	lea    esi,[esp+0x48]
  505438:	e8 33 0b 00 00       	call   0x505f70
  50543d:	8d 8c 24 a8 01 00 00 	lea    ecx,[esp+0x1a8]
  505444:	51                   	push   ecx
  505445:	c6 84 24 64 02 00 00 	mov    BYTE PTR [esp+0x264],0x1
  50544c:	01 
  50544d:	e8 6e f1 ff ff       	call   0x5045c0
  505452:	8d 54 24 64          	lea    edx,[esp+0x64]
  505456:	52                   	push   edx
  505457:	c6 84 24 64 02 00 00 	mov    BYTE PTR [esp+0x264],0x0
  50545e:	00 
  50545f:	e8 5c f1 ff ff       	call   0x5045c0
  505464:	8b 44 24 18          	mov    eax,DWORD PTR [esp+0x18]
  505468:	8b 40 40             	mov    eax,DWORD PTR [eax+0x40]
  50546b:	89 44 24 18          	mov    DWORD PTR [esp+0x18],eax
  50546f:	85                   	.byte 0x85
```

### Map insertion/lookup helper — 0x505870–0x505985

```asm
  505870:	55                   	push   ebp
  505871:	8b ec                	mov    ebp,esp
  505873:	6a ff                	push   0xffffffff
  505875:	68 80 bc 91 00       	push   0x91bc80
  50587a:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  505880:	50                   	push   eax
  505881:	83 ec 48             	sub    esp,0x48
  505884:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  505889:	33 c5                	xor    eax,ebp
  50588b:	89 45 f0             	mov    DWORD PTR [ebp-0x10],eax
  50588e:	56                   	push   esi
  50588f:	57                   	push   edi
  505890:	50                   	push   eax
  505891:	8d 45 f4             	lea    eax,[ebp-0xc]
  505894:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  50589a:	8b f1                	mov    esi,ecx
  50589c:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  50589f:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  5058a2:	80 78 2d 00          	cmp    BYTE PTR [eax+0x2d],0x0
  5058a6:	8b f9                	mov    edi,ecx
  5058a8:	75 1a                	jne    0x5058c4
  5058aa:	8b 0a                	mov    ecx,DWORD PTR [edx]
  5058ac:	8d 64 24 00          	lea    esp,[esp+0x0]
  5058b0:	39 48 0c             	cmp    DWORD PTR [eax+0xc],ecx
  5058b3:	7d 05                	jge    0x5058ba
  5058b5:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  5058b8:	eb 04                	jmp    0x5058be
  5058ba:	8b f8                	mov    edi,eax
  5058bc:	8b 00                	mov    eax,DWORD PTR [eax]
  5058be:	80 78 2d 00          	cmp    BYTE PTR [eax+0x2d],0x0
  5058c2:	74 ec                	je     0x5058b0
  5058c4:	3b 7e 04             	cmp    edi,DWORD PTR [esi+0x4]
  5058c7:	74 0b                	je     0x5058d4
  5058c9:	8b 02                	mov    eax,DWORD PTR [edx]
  5058cb:	3b 47 0c             	cmp    eax,DWORD PTR [edi+0xc]
  5058ce:	0f 8d 92 00 00 00    	jge    0x505966
  5058d4:	33 c0                	xor    eax,eax
  5058d6:	33 c9                	xor    ecx,ecx
  5058d8:	c7 45 c8 07 00 00 00 	mov    DWORD PTR [ebp-0x38],0x7
  5058df:	89 45 c4             	mov    DWORD PTR [ebp-0x3c],eax
  5058e2:	66 89 4d b4          	mov    WORD PTR [ebp-0x4c],cx
  5058e6:	89 45 fc             	mov    DWORD PTR [ebp-0x4],eax
  5058e9:	8b 12                	mov    edx,DWORD PTR [edx]
  5058eb:	8d 4d b4             	lea    ecx,[ebp-0x4c]
  5058ee:	51                   	push   ecx
  5058ef:	8d 4d d4             	lea    ecx,[ebp-0x2c]
  5058f2:	89 55 d0             	mov    DWORD PTR [ebp-0x30],edx
  5058f5:	c7 45 e8 07 00 00 00 	mov    DWORD PTR [ebp-0x18],0x7
  5058fc:	89 45 e4             	mov    DWORD PTR [ebp-0x1c],eax
  5058ff:	66 89 45 d4          	mov    WORD PTR [ebp-0x2c],ax
  505903:	e8 f8 ce ef ff       	call   0x402800
  505908:	8d 55 d0             	lea    edx,[ebp-0x30]
  50590b:	52                   	push   edx
  50590c:	8b ce                	mov    ecx,esi
  50590e:	c6 45 fc 01          	mov    BYTE PTR [ebp-0x4],0x1
  505912:	e8 d9 0a 00 00       	call   0x5063f0
  505917:	57                   	push   edi
  505918:	8d 4d b0             	lea    ecx,[ebp-0x50]
  50591b:	51                   	push   ecx
  50591c:	8b ce                	mov    ecx,esi
  50591e:	e8 1d 05 00 00       	call   0x505e40
  505923:	8b 75 b0             	mov    esi,DWORD PTR [ebp-0x50]
  505926:	bf 08 00 00 00       	mov    edi,0x8
  50592b:	39 7d e8             	cmp    DWORD PTR [ebp-0x18],edi
  50592e:	72 0c                	jb     0x50593c
  505930:	8b 55 d4             	mov    edx,DWORD PTR [ebp-0x2c]
  505933:	52                   	push   edx
  505934:	e8 d3 b8 38 00       	call   0x89120c
  505939:	83 c4 04             	add    esp,0x4
  50593c:	33 c0                	xor    eax,eax
  50593e:	c7 45 e8 07 00 00 00 	mov    DWORD PTR [ebp-0x18],0x7
  505945:	c7 45 e4 00 00 00 00 	mov    DWORD PTR [ebp-0x1c],0x0
  50594c:	66 89 45 d4          	mov    WORD PTR [ebp-0x2c],ax
  505950:	39 7d c8             	cmp    DWORD PTR [ebp-0x38],edi
  505953:	72 0c                	jb     0x505961
  505955:	8b 4d b4             	mov    ecx,DWORD PTR [ebp-0x4c]
  505958:	51                   	push   ecx
  505959:	e8 ae b8 38 00       	call   0x89120c
  50595e:	83 c4 04             	add    esp,0x4
  505961:	8d 46 10             	lea    eax,[esi+0x10]
  505964:	eb 03                	jmp    0x505969
  505966:	8d 47 10             	lea    eax,[edi+0x10]
  505969:	8b 4d f4             	mov    ecx,DWORD PTR [ebp-0xc]
  50596c:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  505973:	59                   	pop    ecx
  505974:	5f                   	pop    edi
  505975:	5e                   	pop    esi
  505976:	8b 4d f0             	mov    ecx,DWORD PTR [ebp-0x10]
  505979:	33 cd                	xor    ecx,ebp
  50597b:	e8 81 b6 38 00       	call   0x891001
  505980:	8b e5                	mov    esp,ebp
  505982:	5d                   	pop    ebp
  505983:	c3                   	ret
  505984:	cc                   	int3
```

### QuestTalk resource load and errors — 0x5055b0–0x5056b5

```asm
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
  505664:	ff ff ff ff 
  505668:	83 c4 04             	add    esp,0x4
  50566b:	c7 44 24 24 94 23 bf 	mov    DWORD PTR [esp+0x24],0xbf2394
  505672:	00 
  505673:	39 bc 24 84 00 00 00 	cmp    DWORD PTR [esp+0x84],edi
  50567a:	72 0d                	jb     0x505689
  50567c:	8b 44 24 70          	mov    eax,DWORD PTR [esp+0x70]
  505680:	50                   	push   eax
  505681:	e8 86 bb 38 00       	call   0x89120c
  505686:	83 c4 04             	add    esp,0x4
  505689:	8d 4c 24 24          	lea    ecx,[esp+0x24]
  50568d:	c7 84 24 84 00 00 00 	mov    DWORD PTR [esp+0x84],0xf
  505694:	0f 00 00 00 
  505698:	89 9c 24 80 00 00 00 	mov    DWORD PTR [esp+0x80],ebx
  50569f:	88 5c 24 70          	mov    BYTE PTR [esp+0x70],bl
  5056a3:	e8 98 89 22 00       	call   0x72e040
  5056a8:	33 c0                	xor    eax,eax
  5056aa:	e9 7e 01 00 00       	jmp    0x50582d
  5056af:	e8 7c 13 00 00       	call   0x506a30
  5056b4:	89                   	.byte 0x89
```
