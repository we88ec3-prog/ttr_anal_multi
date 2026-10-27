# KR T08 — 整合重審-02：S2C0007 建立登記、唯一鍵分支及 Script DeleteAllObject 清理邊界

- 生成時間：2026-10-28T01:33:05.717325+08:00（Asia/Taipei）
- 研究者：`chatgpt-web roy`。**本地獨立技術原稿；無 Commit／Push；無 Task 認領／catalog 修改**。
- 使用 GitHub `we88ec3-prog/ttr_anal_multi` main 最新查得候選 HEAD：`52452b5bc1bf0a6f7a10a7c1c83e4f3aca6a780d`（本次查得 commit-list 最新；不宣稱 atomic ref）。
- 一手來源：`Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，12,472,320 bytes；GNU `objdump` `pei-i386` 實際解析的 PE image VA；未執行遊戲或任何歷史腳本。
- 參考前稿：`20261028-012810-chatgpt-web-roy-T08-integrated-reaudit-01.md`。正式 T08 範圍僅包含生成、登記及移除資料介面，無怪物出生決策權限。

## 1. 本批獨立確立的結論（原始 bytes 級）

1. **0007 長度推導不只「每 row 26 bytes」**：`0x4AE510` 取函式第二參數 `len`，若 `<2` 將 row_count 設為 0；否則 `0x4AE51F..0x4AE529` 對 `len-2` 作常數除法，`0x4AE52C` 保存 `floor((len-2)/26)`；`0x4AE538` 以 0 分支跳 `0x4AED58`。證據：`mov eax,0x4EC4EC4F; mul ecx; shr edx,3`（無號除以26的乘法化形式）。這是**接收函式的計數算法**，不是伺服器生成時機。末尾不足26 bytes 的處置、buffer 真正長度契約需 T02 核對。
2. **0007 的類型分派**：`0x4AE5B8 movzx eax, byte [ebx-4]`、`0x4AE5D4 cmp eax,7`、`0x4AE5D7 ja 0x4AED83`、`0x4AE5DD jmp [eax*4+0x4AED90]`。種類由 row actor ID 的低 byte 驅動，超過7走錯誤分支；**jump table 是資料，不可當指令**。`0x4AE5BC` 的資源次級 byte `dec edi`，再與類型及 `WORD [ebx]` 組合索引，非獨立的生成規則。
3. **0007 → GameInfo 登記直接邊**：`0x004AEC03: e8 28 13 03 00` → `0x004DFF30`，PE VA 完全一致。其他保存直接 caller `0x004A11B6,0x004AA222,0x004AF4F7,0x004B2F83` 的 `E8 rel32` 亦在前稿 PE byte 對照已列出（不是完整呼叫者全集）。
4. **GameInfo 插入採『查無既存 key 時才新增』分支**：`0x4DFF4C` 讀 actor `WORD [edi+4]`，`ebx` 為 GameInfo；`0x4DFF56` 取 `ebx+8` map，`0x4DFF5F` 查 `0x82EF00`，`0x4DFF67 cmp edx,[ebx+0xc]`；若相等（end/sentinel）才經 `0x57EF20` 建節點與 `0x82F200` 唯一插入。**非 sentinel 時走 `0x4DFF90` 記錄訊息後返回**，沒有覆寫舊指標的機器碼證據。`0x4DFF42` 零 actor 則呼叫 `0x6EDC70`，惟該函式是否無返回／中止仍需核對，因此不要宣稱後續讀 `[edi+4]` 永遠安全。
5. **節點配置及 payload**：`0x57EF26 push 0x18`、`0x57EF28 call 0x891268` 分配24 bytes；節點 `[+0/+4/+8]` 初始皆為 `esi+4` 的 sentinel；`node+0x0c` 起複製 `[edi]`、`[edi+4]` 兩 DWORD（key 與 actor pointer 候選），`node+0x14` 寫WORD零。這對應 `0x4DFF6C..0x4DFF75` 堆疊暫存設定；**不要把不同節點容器的 +0xC/+0x10 與名稱樹 payload 混淆**。
6. **唯一鍵插入重複分支可見**：`0x82F200..0x82F2C5` 包含按 `[node+0xC]` 比較、`0x44BD00` 插入及 `[esi+4]` 設為1（成功），在另一條分支 `0x82F2B7` 設0（未插入）。由於未完整分析 `0x82EF00` 和回傳所有權，尚不能宣稱重複情況已釋放新 actor，或者重複 ID 永不遺漏。
7. **Script DeleteAllObject 是另一個 owner/container**：`0x563AA0 mov eax,[ecx+0x1C]`，走節點 `[+0x10]` 的 object pointer。非空時虛擬表 `+0x14` 與 `+0` 兩段呼叫（後者 `push 1`），循樹迭代後 `0x563B1D call 0x823850` 清理樹；**沒有看到直接對 GameInfo+8 使用相同 erase 路徑**。後續 `0x563BEA call 0x851420`、`0x563C01/0x563C15 lock xadd` 等為額外 resource/refcount 管理，不等於全體 actor 最終回收。
8. 保存 GitHub `kr/evidence/a607cd903831b70cc24131938368ef19c0a537b63a4506190b2926d48500ae65.txt` 顯示 `0x476430 ret 4`，而 `0x5666A0` 的 DeleteObject 註冊會引用它；因此 **單物件 DeleteObject Lua API 註冊不構成 GameInfo map erase 的證明**。兩者與 `DeleteAllObject` 必須區分。

## 2. 上一批地址映射的更精確處置

上一批正確觀察：部分歷史 B queue／vtable 筆記確實混入 `.text` flat `raw=VA-0x401000`，與 PE raw 相差 `0x400`。**本批反而提供另一組獨立反證**：`S2C0007 (0x004AE4D0)`、`0x004AEC03`、`0x004DFF30`、`0x00563A70`、`0x0057EF20`、`0x0082F200` 在 PE 的 VMA 下具有自洽呼叫與容器構造；不能以單一 `-0x400` 統一校正所有歷史 function labels。須以**來源檔 SHA + 函式入口 bytes + E8 target + PE section**分群建立 mapping provenance，禁止跨群直接拼連 caller/callee。

## 3. 本批 trace／資料結構

```text
Network payload (T02 framing)
  └─ PE 0x004AE4D0 [recv 0007]
      ├─ count=floor((length-2)/26)
      ├─ actor ID low byte branch via [0x4AED90 + type*4]
      ├─ type1 → constructor 0x004D1710 (saved report; full constructor body not revalidated this batch)
      └─ 0x004AEC03 E8 rel32 → PE 0x004DFF30 actor register
          ├─ actor->word+4 as key
          ├─ GameInfo+8 lookup → 0x0082EF00
          ├─ if key absent: 0x0057EF20 allocate 0x18 node
          │    └─ 0x0082F200 ordered/unique insert
          └─ if found: diagnostic 0x006EDB60 and return

Separate: Script owner/container
  Script DeleteAllObject 0x00563A70
     ├─ tree at script-this+0x1C
     ├─ item value at node+0x10
     ├─ virtual +0x14 and +0 (1) for each held object
     ├─ 0x00823850 tree cleanup
     └─ further resource/refcount processing
```

### 3.1 可考證結構（不是最終型別定義）

| 來源物件 | 位移 | 指令級用途 | 禁止的外推 |
|---|---:|---|---|
| `actor*` | `+0x04` | `movzx eax,WORD [edi+4]` 作 map key | 不能推出全部 actor ID 唯一來源 |
| `GameInfo*` | `+0x08` | 容器基址傳給 `0x82EF00` | 不同 owner 的 `+8` 不能混用 |
| `GameInfo*` | `+0x0C` | lookup end/sentinel 比較 | 不等於 actor count |
| 新樹節點 (0x18) | `+0/+4/+8` | 三個指向 sentinel 的 pointer | 不直接等於 actor 欄位 |
| 新樹節點 (0x18) | `+0x0C/+0x10` | key/value 候選 DWORD | 不等於 NameRegistry node+0x24 |
| script owner | `+0x1C` | DeleteAllObject 的樹 head | 不得認成 GameInfo+8 |
| script tree node | `+0x10` | script actor/item pointer | 不保證每個 GameInfo actor 都出現 |

## 4. C++ 風格偽碼：根據目前 trace 的限定接口

```cpp
// 不是完整原版反編譯；為已驗證分支之語意抽象。
uint32_t spawnRowCount(uint32_t nbytes) {
    return nbytes < 2 ? 0 : (nbytes - 2) / 26;
}

void registerActorCandidate(GameInfo* game, Actor* actor) {
    // actor == nullptr 路徑呼叫診斷函式，其實際 termination semantics 未證
    uint16_t id = actor->idAtOffset4;
    auto keyResult = lookup(game->mapAt8, id); // 0x82EF00
    if (keyResult.node == game->endAtOffsetC) {
        auto* node = allocate24byteNode(id, actor); // 0x57EF20
        uniqueInsert(game->mapAt8, node); // 0x82F200, success flag not yet followed
    } else {
        diagnosticExistingKey(id); // 0x6EDB60, format string unverified
    }
}

void scriptDeleteAllCandidate(ScriptOwner* owner) {
    // 不是通用 GameInfo map erase
    for (auto* n : owner->treeAt1C) {
        if (auto* obj = n->valueAt10) {
            obj->virtualAt14();
            obj->virtualDestructorLike(1);
        }
    }
    clearTree(owner->treeAt18); // 0x823850, underlying full behavior pending
    // further cleanup/resource routines omitted, not yet fully proven
}
```

## 5. 關聯正式整合來源與責任分界

- `kr/evidence/6ef16f451f942d2e828a1b6936b466332736d7dc75fa0152fcbb6289863902dd.txt`：0007 26-byte rows、type1 CMonster、GameInfo+8 map、minimap marker 相互獨立；本輪對 count、type jump、map insertion 新增 PE 原始驗證。
- `kr/evidence/3a44c60063ffad3833adaadb65fe0e1dacc127cef3a1ca10b213dffd97848453.txt`：DeleteAllObject 儲存的 Ghidra 指令；本輪以 objdump PE 原始逐指令覆核主要 cleanup。
- `kr/evidence/c21e09019d3e7e97fddc6f8ff8b334aa849964cd7eba41662f3fec5e6f0c9d56.txt`：只覆蓋 script CEventActor 及 Lua API 有界函式；不驗收 GameInfo 通用移除。
- `shared/integrations/T01-20261027-05/pending.json` 與 `shared/source-review-status.json`：partial claims 與 native gaps 保留；**本報告自身的原始 bytes 驗證不自動修改正式整合 accepted-claims**。
- 尚未確認 `shared/catalog.json` 共用 helper 具體主責（GitHub fetch 大檔返回空）；所以不改 task.json／catalog，也不宣稱新 owner。

## 6. 未解問題與優先後續工作

| 問題 | 本批已驗證 | 下批需要 |
|---|---|---|
| 接收 0007 count | 無號 `floor((len-2)/26)`，0 件跳空路徑 | 上游 length/payload 契約、buffer 限界、不足尾資料 |
| 同 actor ID 再登記 | 進入 diagnostic branch、未在該分支覆寫 | diagnostic 是否 fatal、new actor 釋放責任及 packet error handling |
| Unique insert helper | `0x82F200` 有 success 1/0 分支 | 0x44BD00、caller 是否讀成功 flag、失敗節點生命週期 |
| 網路移除路徑 | 尚未定位確定對 GameInfo+8 map erase 的 caller | 靜態 xref 0x82F? erase、封包 handler 逆向、actor free 和 minimap marker 同步 |
| Script DeleteAllObject | script tree 節點虛擬清理與樹 reset | vtable 動態型別、item 真正 delete/free、GameInfo map 是否另有同步 |
| Mapping | 0007/登記/腳本鏈已 PE bytes 驗證 | 舊 B-queue 與本批 PE 群分別列出 address provenance |

## 7. 一手 disassembly 附錄（完整列出本批選定的關鍵區間）

下列均用 `/mnt/data/Tartaros.bin` 由 `objdump -D -Mintel --start-address --stop-address` 直接取得；每個區間起點為確立的 PE VMA，個別截取的首／尾 instruction 若邊界錯切，須以前一個 function 入口為基準重解碼。

### S2C0007 length / dispatch: `0x004AE510`–`0x004AE5E4`

```asm
004ae510 <.text+0xad510>:
  4ae510:	8b 45 0c             	mov    eax,DWORD PTR [ebp+0xc]
  4ae513:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4ae516:	83 f8 02             	cmp    eax,0x2
  4ae519:	73 04                	jae    0x4ae51f
  4ae51b:	33 d2                	xor    edx,edx
  4ae51d:	eb 0d                	jmp    0x4ae52c
  4ae51f:	8d 48 fe             	lea    ecx,[eax-0x2]
  4ae522:	b8 4f ec c4 4e       	mov    eax,0x4ec4ec4f
  4ae527:	f7 e1                	mul    ecx
  4ae529:	c1 ea 03             	shr    edx,0x3
  4ae52c:	89 54 24 28          	mov    DWORD PTR [esp+0x28],edx
  4ae530:	c7 44 24 24 00 00 00 	mov    DWORD PTR [esp+0x24],0x0
  4ae537:	00 
  4ae538:	85 d2                	test   edx,edx
  4ae53a:	0f 84 18 08 00 00    	je     0x4aed58
  4ae540:	83 c3 06             	add    ebx,0x6
  4ae543:	eb 0b                	jmp    0x4ae550
  4ae545:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  4ae54c:	8d 64 24 00          	lea    esp,[esp+0x0]
  4ae550:	b8 01 00 00 00       	mov    eax,0x1
  4ae555:	89 44 24 20          	mov    DWORD PTR [esp+0x20],eax
  4ae559:	84 05 2c b2 fa 00    	test   BYTE PTR ds:0xfab22c,al
  4ae55f:	75 2e                	jne    0x4ae58f
  4ae561:	09 05 2c b2 fa 00    	or     DWORD PTR ds:0xfab22c,eax
  4ae567:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0x0
  4ae56e:	00 00 00 00 
  4ae572:	e8 19 07 03 00       	call   0x4dec90
  4ae577:	68 30 ce bc 00       	push   0xbcce30
  4ae57c:	e8 99 3d 3e 00       	call   0x89231a
  4ae581:	83 c4 04             	add    esp,0x4
  4ae584:	c7 84 24 50 01 00 00 	mov    DWORD PTR [esp+0x150],0xffffffff
  4ae58b:	ff ff ff ff 
  4ae58f:	0f b7 53 fc          	movzx  edx,WORD PTR [ebx-0x4]
  4ae593:	8d 44 24 18          	lea    eax,[esp+0x18]
  4ae597:	50                   	push   eax
  4ae598:	8d 44 24 58          	lea    eax,[esp+0x58]
  4ae59c:	b9 38 b1 fa 00       	mov    ecx,0xfab138
  4ae5a1:	89 54 24 1c          	mov    DWORD PTR [esp+0x1c],edx
  4ae5a5:	e8 56 09 38 00       	call   0x82ef00
  4ae5aa:	8b 08                	mov    ecx,DWORD PTR [eax]
  4ae5ac:	3b 0d 3c b1 fa 00    	cmp    ecx,DWORD PTR ds:0xfab13c
  4ae5b2:	0f 85 8a 07 00 00    	jne    0x4aed42
  4ae5b8:	0f b6 43 fc          	movzx  eax,BYTE PTR [ebx-0x4]
  4ae5bc:	0f b6 7b fe          	movzx  edi,BYTE PTR [ebx-0x2]
  4ae5c0:	0f b7 0b             	movzx  ecx,WORD PTR [ebx]
  4ae5c3:	4f                   	dec    edi
  4ae5c4:	8b d0                	mov    edx,eax
  4ae5c6:	c1 e2 08             	shl    edx,0x8
  4ae5c9:	0b fa                	or     edi,edx
  4ae5cb:	c1 e7 10             	shl    edi,0x10
  4ae5ce:	0b f9                	or     edi,ecx
  4ae5d0:	89 7c 24 1c          	mov    DWORD PTR [esp+0x1c],edi
  4ae5d4:	83 f8 07             	cmp    eax,0x7
  4ae5d7:	0f 87 a6 07 00 00    	ja     0x4aed83
  4ae5dd:	ff 24 85 90 ed 4a 00 	jmp    DWORD PTR [eax*4+0x4aed90]
```

### S2C0007 register caller: `0x004AEBEC`–`0x004AEC15`

```asm
004aebec <.text+0xadbec>:
  4aebec:	3e 00 83 c4 04 c7 84 	add    BYTE PTR ds:[ebx-0x7b38fb3c],al
  4aebf3:	24 50                	and    al,0x50
  4aebf5:	01 00                	add    DWORD PTR [eax],eax
  4aebf7:	00 ff                	add    bh,bh
  4aebf9:	ff                   	(bad)
  4aebfa:	ff                   	(bad)
  4aebfb:	ff 68 30             	jmp    FWORD PTR [eax+0x30]
  4aebfe:	b1 fa                	mov    cl,0xfa
  4aec00:	00 8b c6 e8 28 13    	add    BYTE PTR [ebx+0x1328e8c6],cl
  4aec06:	03 00                	add    eax,DWORD PTR [eax]
  4aec08:	83 7b 0e 00          	cmp    DWORD PTR [ebx+0xe],0x0
  4aec0c:	0f 84 86 00 00 00    	je     0x4aec98
  4aec12:	f6 05 2c     	test   BYTE PTR ds:0xfab22c,0x1
```

### GameInfo register: `0x004DFF30`–`0x004DFFA8`

```asm
004dff30 <.text+0xdef30>:
  4dff30:	55                   	push   ebp
  4dff31:	8b ec                	mov    ebp,esp
  4dff33:	83 ec 10             	sub    esp,0x10
  4dff36:	53                   	push   ebx
  4dff37:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4dff3a:	56                   	push   esi
  4dff3b:	57                   	push   edi
  4dff3c:	8b f8                	mov    edi,eax
  4dff3e:	85 ff                	test   edi,edi
  4dff40:	75 0a                	jne    0x4dff4c
  4dff42:	68 d0 ce c0 00       	push   0xc0ced0
  4dff47:	e8 24 dd 20 00       	call   0x6edc70
  4dff4c:	0f b7 47 04          	movzx  eax,WORD PTR [edi+0x4]
  4dff50:	8d 4d 08             	lea    ecx,[ebp+0x8]
  4dff53:	89 45 08             	mov    DWORD PTR [ebp+0x8],eax
  4dff56:	8d 73 08             	lea    esi,[ebx+0x8]
  4dff59:	51                   	push   ecx
  4dff5a:	8d 45 f8             	lea    eax,[ebp-0x8]
  4dff5d:	8b ce                	mov    ecx,esi
  4dff5f:	e8 9c ef 34 00       	call   0x82ef00
  4dff64:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  4dff67:	3b 53 0c             	cmp    edx,DWORD PTR [ebx+0xc]
  4dff6a:	75 24                	jne    0x4dff90
  4dff6c:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4dff6f:	89 7d f8             	mov    DWORD PTR [ebp-0x8],edi
  4dff72:	8d 7d f4             	lea    edi,[ebp-0xc]
  4dff75:	89 45 f4             	mov    DWORD PTR [ebp-0xc],eax
  4dff78:	e8 a3 ef 09 00       	call   0x57ef20
  4dff7d:	50                   	push   eax
  4dff7e:	56                   	push   esi
  4dff7f:	8d 75 f4             	lea    esi,[ebp-0xc]
  4dff82:	e8 79 f2 34 00       	call   0x82f200
  4dff87:	5f                   	pop    edi
  4dff88:	5e                   	pop    esi
  4dff89:	5b                   	pop    ebx
  4dff8a:	8b e5                	mov    esp,ebp
  4dff8c:	5d                   	pop    ebp
  4dff8d:	c2 04 00             	ret    0x4
  4dff90:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  4dff93:	51                   	push   ecx
  4dff94:	68 f0 ce c0 00       	push   0xc0cef0
  4dff99:	e8 c2 db 20 00       	call   0x6edb60
  4dff9e:	83 c4 08             	add    esp,0x8
  4dffa1:	5f                   	pop    edi
  4dffa2:	5e                   	pop    esi
  4dffa3:	5b                   	pop    ebx
  4dffa4:	8b e5                	mov    esp,ebp
  4dffa6:	5d                   	pop    ebp
  4dffa7:	c2               	ret    0x4
```

### node allocate: `0x0057EF20`–`0x0057EF60`

```asm
0057ef20 <.text+0x17df20>:
  57ef20:	55                   	push   ebp
  57ef21:	8b ec                	mov    ebp,esp
  57ef23:	83 ec 10             	sub    esp,0x10
  57ef26:	6a 18                	push   0x18
  57ef28:	e8 3b 23 31 00       	call   0x891268
  57ef2d:	33 d2                	xor    edx,edx
  57ef2f:	83 c4 04             	add    esp,0x4
  57ef32:	3b c2                	cmp    eax,edx
  57ef34:	74 2a                	je     0x57ef60
  57ef36:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  57ef39:	89 08                	mov    DWORD PTR [eax],ecx
  57ef3b:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  57ef3e:	89 48 04             	mov    DWORD PTR [eax+0x4],ecx
  57ef41:	8b 4e 04             	mov    ecx,DWORD PTR [esi+0x4]
  57ef44:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  57ef47:	8d 48 0c             	lea    ecx,[eax+0xc]
  57ef4a:	66 89 50 14          	mov    WORD PTR [eax+0x14],dx
  57ef4e:	3b ca                	cmp    ecx,edx
  57ef50:	74 0a                	je     0x57ef5c
  57ef52:	8b 17                	mov    edx,DWORD PTR [edi]
  57ef54:	89 11                	mov    DWORD PTR [ecx],edx
  57ef56:	8b 57 04             	mov    edx,DWORD PTR [edi+0x4]
  57ef59:	89 51 04             	mov    DWORD PTR [ecx+0x4],edx
  57ef5c:	8b e5                	mov    esp,ebp
  57ef5e:	5d                   	pop    ebp
  57ef5f:	c3                   	ret
```

### unique insert: `0x0082F200`–`0x0082F2C5`

```asm
0082f200 <.text+0x42e200>:
  82f200:	55                   	push   ebp
  82f201:	8b ec                	mov    ebp,esp
  82f203:	83 ec 08             	sub    esp,0x8
  82f206:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  82f209:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  82f20c:	53                   	push   ebx
  82f20d:	57                   	push   edi
  82f20e:	8b 78 04             	mov    edi,DWORD PTR [eax+0x4]
  82f211:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  82f214:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  82f218:	b1 01                	mov    cl,0x1
  82f21a:	88 4d f8             	mov    BYTE PTR [ebp-0x8],cl
  82f21d:	75 1f                	jne    0x82f23e
  82f21f:	8b 5a 0c             	mov    ebx,DWORD PTR [edx+0xc]
  82f222:	3b 58 0c             	cmp    ebx,DWORD PTR [eax+0xc]
  82f225:	8b f8                	mov    edi,eax
  82f227:	0f 92 c1             	setb   cl
  82f22a:	88 4d f8             	mov    BYTE PTR [ebp-0x8],cl
  82f22d:	84 c9                	test   cl,cl
  82f22f:	74 04                	je     0x82f235
  82f231:	8b 00                	mov    eax,DWORD PTR [eax]
  82f233:	eb 03                	jmp    0x82f238
  82f235:	8b 40 08             	mov    eax,DWORD PTR [eax+0x8]
  82f238:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  82f23c:	74 e4                	je     0x82f222
  82f23e:	8b df                	mov    ebx,edi
  82f240:	89 5d fc             	mov    DWORD PTR [ebp-0x4],ebx
  82f243:	84 c9                	test   cl,cl
  82f245:	74 3a                	je     0x82f281
  82f247:	8b 4d 08             	mov    ecx,DWORD PTR [ebp+0x8]
  82f24a:	8b 41 04             	mov    eax,DWORD PTR [ecx+0x4]
  82f24d:	3b 38                	cmp    edi,DWORD PTR [eax]
  82f24f:	75 22                	jne    0x82f273
  82f251:	52                   	push   edx
  82f252:	6a 01                	push   0x1
  82f254:	8d 55 0c             	lea    edx,[ebp+0xc]
  82f257:	8b c7                	mov    eax,edi
  82f259:	52                   	push   edx
  82f25a:	8b f9                	mov    edi,ecx
  82f25c:	e8 9f ca c1 ff       	call   0x44bd00
  82f261:	8b 00                	mov    eax,DWORD PTR [eax]
  82f263:	5f                   	pop    edi
  82f264:	89 06                	mov    DWORD PTR [esi],eax
  82f266:	c6 46 04 01          	mov    BYTE PTR [esi+0x4],0x1
  82f26a:	8b c6                	mov    eax,esi
  82f26c:	5b                   	pop    ebx
  82f26d:	8b e5                	mov    esp,ebp
  82f26f:	5d                   	pop    ebp
  82f270:	c2 08 00             	ret    0x8
  82f273:	8d 45 fc             	lea    eax,[ebp-0x4]
  82f276:	e8 25 06 d1 ff       	call   0x53f8a0
  82f27b:	8b 5d fc             	mov    ebx,DWORD PTR [ebp-0x4]
  82f27e:	8b 55 0c             	mov    edx,DWORD PTR [ebp+0xc]
  82f281:	8b 4b 0c             	mov    ecx,DWORD PTR [ebx+0xc]
  82f284:	52                   	push   edx
  82f285:	3b 4a 0c             	cmp    ecx,DWORD PTR [edx+0xc]
  82f288:	73 24                	jae    0x82f2ae
  82f28a:	8b 55 f8             	mov    edx,DWORD PTR [ebp-0x8]
  82f28d:	52                   	push   edx
  82f28e:	8d 45 0c             	lea    eax,[ebp+0xc]
  82f291:	50                   	push   eax
  82f292:	8b c7                	mov    eax,edi
  82f294:	8b 7d 08             	mov    edi,DWORD PTR [ebp+0x8]
  82f297:	e8 64 ca c1 ff       	call   0x44bd00
  82f29c:	8b 08                	mov    ecx,DWORD PTR [eax]
  82f29e:	5f                   	pop    edi
  82f29f:	89 0e                	mov    DWORD PTR [esi],ecx
  82f2a1:	c6 46 04 01          	mov    BYTE PTR [esi+0x4],0x1
  82f2a5:	8b c6                	mov    eax,esi
  82f2a7:	5b                   	pop    ebx
  82f2a8:	8b e5                	mov    esp,ebp
  82f2aa:	5d                   	pop    ebp
  82f2ab:	c2 08 00             	ret    0x8
  82f2ae:	e8 59 1f 06 00       	call   0x89120c
  82f2b3:	83 c4 04             	add    esp,0x4
  82f2b6:	5f                   	pop    edi
  82f2b7:	89 1e                	mov    DWORD PTR [esi],ebx
  82f2b9:	c6 46 04 00          	mov    BYTE PTR [esi+0x4],0x0
  82f2bd:	8b c6                	mov    eax,esi
  82f2bf:	5b                   	pop    ebx
  82f2c0:	8b e5                	mov    esp,ebp
  82f2c2:	5d                   	pop    ebp
  82f2c3:	c2 08              	ret    0x8
```

### script DeleteAllObject head: `0x00563A70`–`0x00563B22`

```asm
00563a70 <.text+0x162a70>:
  563a70:	55                   	push   ebp
  563a71:	8b ec                	mov    ebp,esp
  563a73:	83 e4 f8             	and    esp,0xfffffff8
  563a76:	6a ff                	push   0xffffffff
  563a78:	68 3e 93 93 00       	push   0x93933e
  563a7d:	64 a1 00 00 00 00    	mov    eax,fs:0x0
  563a83:	50                   	push   eax
  563a84:	83 ec 18             	sub    esp,0x18
  563a87:	53                   	push   ebx
  563a88:	56                   	push   esi
  563a89:	57                   	push   edi
  563a8a:	a1 20 1f d6 00       	mov    eax,ds:0xd61f20
  563a8f:	33 c4                	xor    eax,esp
  563a91:	50                   	push   eax
  563a92:	8d 44 24 28          	lea    eax,[esp+0x28]
  563a96:	64 a3 00 00 00 00    	mov    fs:0x0,eax
  563a9c:	89 4c 24 14          	mov    DWORD PTR [esp+0x14],ecx
  563aa0:	8b 41 1c             	mov    eax,DWORD PTR [ecx+0x1c]
  563aa3:	8b 30                	mov    esi,DWORD PTR [eax]
  563aa5:	3b f0                	cmp    esi,eax
  563aa7:	74 6f                	je     0x563b18
  563aa9:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  563ab0:	8b 7e 10             	mov    edi,DWORD PTR [esi+0x10]
  563ab3:	33 db                	xor    ebx,ebx
  563ab5:	3b fb                	cmp    edi,ebx
  563ab7:	74 17                	je     0x563ad0
  563ab9:	8b 07                	mov    eax,DWORD PTR [edi]
  563abb:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  563abe:	8b cf                	mov    ecx,edi
  563ac0:	ff d2                	call   edx
  563ac2:	8b 07                	mov    eax,DWORD PTR [edi]
  563ac4:	8b 10                	mov    edx,DWORD PTR [eax]
  563ac6:	6a 01                	push   0x1
  563ac8:	8b cf                	mov    ecx,edi
  563aca:	ff d2                	call   edx
  563acc:	8b 4c 24 14          	mov    ecx,DWORD PTR [esp+0x14]
  563ad0:	38 5e 15             	cmp    BYTE PTR [esi+0x15],bl
  563ad3:	75 3c                	jne    0x563b11
  563ad5:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  563ad8:	38 58 15             	cmp    BYTE PTR [eax+0x15],bl
  563adb:	75 14                	jne    0x563af1
  563add:	8b f0                	mov    esi,eax
  563adf:	8b 06                	mov    eax,DWORD PTR [esi]
  563ae1:	38 58 15             	cmp    BYTE PTR [eax+0x15],bl
  563ae4:	75 2b                	jne    0x563b11
  563ae6:	8b f0                	mov    esi,eax
  563ae8:	8b 06                	mov    eax,DWORD PTR [esi]
  563aea:	38 58 15             	cmp    BYTE PTR [eax+0x15],bl
  563aed:	74 f7                	je     0x563ae6
  563aef:	eb 20                	jmp    0x563b11
  563af1:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  563af4:	38 58 15             	cmp    BYTE PTR [eax+0x15],bl
  563af7:	75 16                	jne    0x563b0f
  563af9:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  563b00:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  563b03:	75 0a                	jne    0x563b0f
  563b05:	8b f0                	mov    esi,eax
  563b07:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  563b0a:	38 58 15             	cmp    BYTE PTR [eax+0x15],bl
  563b0d:	74 f1                	je     0x563b00
  563b0f:	8b f0                	mov    esi,eax
  563b11:	3b 71 1c             	cmp    esi,DWORD PTR [ecx+0x1c]
  563b14:	75 9a                	jne    0x563ab0
  563b16:	eb 02                	jmp    0x563b1a
  563b18:	33 db                	xor    ebx,ebx
  563b1a:	8d 79 18             	lea    edi,[ecx+0x18]
  563b1d:	e8 2e fd 2b 00       	call   0x823850
```

### script DeleteAllObject tail: `0x00563BF7`–`0x00563C37`

```asm
00563bf7 <.text+0x162bf7>:
  563bf7:	85 db                	test   ebx,ebx
  563bf9:	74 29                	je     0x563c24
  563bfb:	8d 4b 04             	lea    ecx,[ebx+0x4]
  563bfe:	83 ca ff             	or     edx,0xffffffff
  563c01:	f0 0f c1 11          	lock xadd DWORD PTR [ecx],edx
  563c05:	75 1d                	jne    0x563c24
  563c07:	8b 03                	mov    eax,DWORD PTR [ebx]
  563c09:	8b 10                	mov    edx,DWORD PTR [eax]
  563c0b:	8b cb                	mov    ecx,ebx
  563c0d:	ff d2                	call   edx
  563c0f:	8d 43 08             	lea    eax,[ebx+0x8]
  563c12:	83 c9 ff             	or     ecx,0xffffffff
  563c15:	f0 0f c1 08          	lock xadd DWORD PTR [eax],ecx
  563c19:	75 09                	jne    0x563c24
  563c1b:	8b 13                	mov    edx,DWORD PTR [ebx]
  563c1d:	8b 42 04             	mov    eax,DWORD PTR [edx+0x4]
  563c20:	8b cb                	mov    ecx,ebx
  563c22:	ff d0                	call   eax
  563c24:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  563c28:	64 89 0d 00 00 00 00 	mov    DWORD PTR fs:0x0,ecx
  563c2f:	59                   	pop    ecx
  563c30:	5f                   	pop    edi
  563c31:	5e                   	pop    esi
  563c32:	5b                   	pop    ebx
  563c33:	8b e5                	mov    esp,ebp
  563c35:	5d                   	pop    ebp
  563c36:	c3                   	ret
```