> **2026-10-31 原生T01修正版（待複驗）**：保留原版 `kr-temp-roy/20261028-013809-chatgpt-web-roy-T08-153-GameInfo-actor-erase-bulk-cleanup.md`（blob `10bb0608cd1dbc9cf944eab51c74d4a2fa205e1a`）；本檔直接修正原有內容中已證錯誤並保存其餘正文。未經T01全文審核，不能標為FULL-PASS／RESOLVED。KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；code raw=VA−0x400C00，不可平移.rdata pointer。

## 本次修正的原生 dataflow／CFG

`4DFBC9 lea eax,[ebp+8]`把搜尋key地址交給`82EF00`；命中後`4DFC19 lea ecx,[ebp+8]`重用同一stack地址供`7B6890`的next_iterator **out-slot**；`49E6A0`在unlink前求successor；`7B6AE6`回寫輸出，非傳key值或解參照free node。

相應T01退回在`kr/tasks/T08/README.md`；shared/verified-knowledge 有界FULL-PASS只復用具體子主張，不能擴張為本全文驗收。其餘claims保留供T01逐項複核。

---

# KR T08-153 — GameInfo 實體移除、控制器解除、批次清理與容器所有權（接續正式 T08 段號）

- 研究時間：2026-10-28T01:38:09+08:00（舊稿原標示；修正版日期 2026-10-31）（Asia/Taipei）
- 作者：`chatgpt-web roy`；本次獨立研究原稿，**未 Commit／Push**、未認領 GitHub Task、未修改原始遊戲。
- 歷史段號：`T08-152` 之後恢復 `T08-153`；「整合重審-01／02」為中間研究成果，**不重新編成 T08-001/002，不冒稱正式整合驗收**。
- 檔案：`Tartaros.bin`，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`（實際本地 `sha256sum` 驗證）；EXE SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`（本段不使用其位址）。
- 方法：GNU `objdump -D -Mintel --start-address=0x4dfb00 --stop-address=0x4e0400 Tartaros.bin`（PE `pei-i386` VA），逐一核對立即數、直接 E8 呼叫、分支、容器 receiver；不執行客戶端或歷史腳本。
- GitHub 比對：`main` 最近查得 `52452b5bc1bf0a6f7a10a7c1c83e4f3aca6a780d`；主要前置來源 `kr/evidence/6ef16f...txt`、`b9e06b...txt`、`c21e090...txt` 和前兩份整合重審報告。GitHub 仍以即時遠端為準；本次不更新 catalog。

## A. 本段直接新增的關鍵結論

### A1. 實體單鍵移除：`0x004DFBC0..0x004DFC29`

**原始 BIN 已確認**，與先前已確立的 `0x004DFF30` 插入函式形成同一 `receiver+0x08` 樹容器的相反操作：

1. `0x4DFBC6 mov esi,eax` 將傳入的 receiver 保存於 `esi`；`0x4DFBC9 lea eax,[ebp+8]` 讀取單一參數 key；`0x4DFBCC lea ebx,[esi+8]`，`0x4DFBD5 call 0x82EF00` 查 key。
2. `0x4DFBDD cmp edi,[esi+0x0C]`：與 sentinel 相等則 `0x4DFC23` 返回，**不呼叫 actor 釋放，也不 erase**。
3. 命中時，`0x4DFBE2..0x4DFBF6` 從全域 `[0x00FBA7A4]` 取得控制器，將 0、1、2 三個索引逐個推送，**經控制器 vtable `+0x1C` 虛擬呼叫**。直接可確認迴圈恰為 3 次；其虛擬方法的具體名稱／其是否只清除此 actor 尚未獨立證明。
4. `0x4DFBF8` 取 `node+0x10` actor，`0x4DFBFD..0x4DFC00` 呼叫 actor vtable `+0x14`；`0x4DFC02..0x4DFC11` 在指標非零時再呼叫 actor vtable `+0x00`，帶 `push 1`，並將 `node+0x10 = 0`。
5. 最後 `0x4DFC18..0x4DFC1E` 以 `(tree=receiver+8, &next_iterator, node)` 呼叫 `0x007B6890` 移除樹節點；**直接 E8 bytes `E8 6D 6C 2D 00`，目標與 PE VA 一致**。

上述已從 BIN 證明「**查 ID → 控制器三槽操作 → actor 虛擬清理/釋放 → map erase**」的有條件本機路徑。尚無證據可稱其為「伺服器發送的移除封包」或全體物件的唯一 free。

### A2. 不同容器不能混合：`0x004DFC30..0x004DFC8A`

這個相鄰函式操作 `receiver+0x18` 的樹，使用 **`0x008438C0`** 查找、以 `receiver+0x1C` 當 sentinel。若命中，先檢查 `receiver+0xF8` 所指資料第 0 DWORD 是否等於輸入 key，符合便清掉 `receiver+0xF8`；隨後 `node+0x10` 非空時直接傳給 `0x89120C`，然後 `0x7B6890` erase。沒有看見前一函式的控制器 3 次循環或 actor virtual +0x14；**不應把這條關聯表的 direct free 視為 GameInfo+8 actor 刪除**。

### A3. 遍歷並依 `actor+0x88` 移除：`0x004DFC90..0x004DFD34`

直接以 `receiver+8` 樹的 `node+0x10` actor 比較 `[actor+0x88] == stack key`。匹配時 actor virtual +0x14、virtual +0(1)、清 node+0x10，`0x7B6890` erase，接著**採 erase 回傳指標續走**；不匹配時手動按樹後繼移動。這是一條**以 actor 欄位條件成批刪除**的獨立路徑；`+0x88` 的確切身分（例如 owner／group／scene）未證。不可混同 `actor+0x9C` 的 0007 owner 欄位。

### A4. 依 ID 低 8-bit 掃描、伴隨資源回收：`0x004DFD40..0x004DFE87`

由 `receiver+0x0C` 取得樹 sentinel，在 `receiver+8` 樹走訪。`0x4DFD73 movzx edx,byte [eax+4]`、`0x4DFD77 cmp dx,word [ebp+8]`：**只從 actor ID `+0x04` 讀 1 byte**；與輸入 `WORD` 比較，是否能匹配所有16-bit ID 取決於傳入值。命中 actor 後，類型低 byte 限制 `{0,1,6,7}` 可走特別的 `actor+0x15C` 路徑。若 `+0x15C` 與 `+0x370` 均非零，先呼叫 `0x7A7CC0`，後呼叫 `0x7A7BF0`（另有 16-byte 暫存區）。此段目前**僅能定為釋放前的條件式關聯處置**，不能冒稱動畫、怪物 AI 或全部資源釋放。

不論特別路徑是否觸發，匹配後 `0x4DFDF9` 執行 actor virtual+0x14，再 virtual+0(1)，將 `node+0x10=0`，`0x4DFE24` E8 `0x7B6890` erase，持續遍歷直到 sentinel。對未匹配元素則不釋放。

### A5. 全表清除：`0x004DFE90..0x004DFF22`

輸入 `arg+0x0C` 取得樹 head/sentinel，遍歷所有 `node+0x10` 非空物件，對每個呼叫 virtual+0x14 和 virtual+0(1)。迴圈結束後 `0x4DFF07 lea edi,[ebx+8]`、`0x4DFF0A call 0x823850` **一次清掉整個 +8 樹**；接著 `[0xFBA7A4]` 控制器 vtable `+0x14` 一次。此函式中 actor 虛擬清理與樹節點釋放有**先遍歷物件、再整樹清除**的明確順序。

其呼叫端、是否僅於場景退出／新關卡 reset／全域關閉時觸發，尚未調出；不要把函式名稱推定為「S2C0007 每次執行後」或「怪物死亡」。

## B. 重新閉合正式 T08 與前兩批的對照

| 步驟 | 機器碼已核對地址 | key / 接收者 | 本段判定 |
|---|---|---|---|
| 網路建立 | `0x4AE4D0`（前批） | 2-byte header、26-byte rows | 前批 BIN 確認 |
| 生成 CMonster | `0x4D1710`（前批保存證據） | actor 類型 1 | 需依真正 branch/context 判讀 |
| map 插入 | `0x4DFF30`（前批與本批重看） | `GameInfo+8`、actor WORD `+4` | 有 key 存在檢查 |
| **單 ID 移除** | **`0x4DFBC0`** | `receiver+8`、stack key | **本批 BIN 確認** |
| **按 actor+88 移除** | **`0x4DFC90`** | `receiver+8`、actor+88 | **本批 BIN 確認** |
| **依 ID 低 byte 移除** | **`0x4DFD40`** | `receiver+8`、1-byte ID 比較 | **本批 BIN 確認** |
| **清除全部 actor** | **`0x4DFE90`** | `arg+8` tree、`arg+0xC` sentinel | **本批 BIN 確認** |
| script 額外物件釋放 | `0x563A70`（前批） | 不同 script `this+0x18` | 不合併 owner |
| 共享 tree erase | `0x7B6890` | 各自特定容器 | erase helper 本體仍待追 |
| actor vtable+0/+0x14 | 間接 call | 候選析構/清理順序 | **未追具體 vtable slot 對象** |

**注意 receiver 認證界線**：`0x4DFBC0` 與 `0x4DFF30` 都使用 `+0x08/+0x0C` 樹配置且在鄰近地址；這是同類容器操作的直接證據，但要證明所有 caller 都傳入同一個 GameInfo 實例，仍需上游逐路徑回追。不可僅因地址相鄰便推導動態 receiver 永遠相同。

## C. C++ 風格限定偽碼（僅已證明的局部分支）

```cpp
// 並非原版簽名。CALL ABI、虛擬槽名稱尚待 vtable/caller 核對。
void eraseActorByIdCandidate(GameLike* receiver, unsigned key) {
    Node* n = lookup(receiver->treeAt8, key); // 0x82EF00
    if (n == receiver->sentinelAtC) return;
    for (int slot = 0; slot < 3; ++slot) {
        controllerVirtual1C(globalFBA7A4, slot); // 暫不命名為 DeleteActor
    }
    Actor* a = n->valueAt10;
    a->vtable14();
    if (a) {
        a->vtable00(/*flag=*/1);
        n->valueAt10 = nullptr;
    }
    eraseTreeNode(receiver->treeAt8, &next_iterator, n); // 0x7B6890; same stack storage reused
}

void clearActorTreeCandidate(Holder* arg) {
    for (auto* n = treeBegin(arg->treeAt8); n != treeEnd(arg->treeAt8); n=treeNext(n)) {
        if (Actor* a=n->valueAt10) { a->vtable14(); a->vtable00(1); }
    }
    clearNodes(arg->treeAt8);  // 0x823850
    controllerVirtual14(globalFBA7A4);
}
```

**重要實作安全註記**：上面的 `a->vtable14()` 在原 assembly 的單鍵移除路徑之前並沒有對 a 明確做非零檢查；偽碼省略了診斷/非法狀態例外處理，不能作為可直接重建的安全實作。`vtable00(1)` 很像刪除析構器慣用模式，但尚不能宣稱必定釋放所有 GPU／minimap／sidecar 資源。

## D. 必須保留的反證／限制

1. 舊說「GameInfo map erase 尚未定位」：**本次定位多條 `receiver+8` map erase／clear 候選並以 BIN 證明本地指令**，但呼叫端與封包事件關聯仍未確認；應將缺口由「erase 地址未知」改成「具體上游 caller／執行條件與回收邊界未知」。
2. `0x4DFC30` 是 `receiver+18` 容器且沒有 actor virtual 釋放，不可與 `0x4DFBC0` 誤併。
3. `0x4DFD40` 比對的是 **BYTE `[actor+4]`** 與 WORD 參數，而 `0x4DFF30` key 是 `WORD [actor+4]`；禁止不經核對就稱兩者等價。此差異可能影響大於 255 的 actor ID 處置。
4. `0x4DFC90` 測試 `actor+0x88`，不是 `0x9C`；不能自動命名為 0007 owner removal。
5. 先前 `.text PE raw+400` 和 flat mapping 衝突仍限於特定來源群，不擴張到本段已經以 PE E8、資料結構與相鄰邊界確認的函式鏈。
6. 靜態檢查沒有運行時封包、動態呼叫權限／原版伺服器實際生成時機，也未驗證所有間接 xref；**不能稱整個 T08 原生功能已完成**。

## E. 下一段值得直接深入的技術工作

- **優先 1**：回追 `0x4DFBC0`／`0x4DFC90`／`0x4DFD40`／`0x4DFE90` 的 caller（尤其 CDefaultScene 封包分派及場景 transition）。來源限定 E8 edges 加上 indirect / vtable roots；確認是否存在真實 `S2C` remove 路徑。
- **優先 2**：完整驗證 `0x7B6890` erase helper、`0x823850` clear、`0x82EF00` lookup 與所有權；核查 key/node/allocator mismatch 的可能性。
- **優先 3**：繼續追 actor vtable `+0/+0x14`、全域控制器 vtable `+0x1C/+0x14` 及其在移除順序中的語意，保留析構可能性而不臆造。
- **優先 4**：檢查單鍵移除時 minimap 72-byte marker 路徑是否同步清除。沒建立直接 edge 前不宣稱必然連動。

## F. BIN 原始反組譯附錄（所有新增主函式、完整可重現）

命令：

```bash
objdump -D -Mintel --start-address=0x4dfb00 --stop-address=0x4e0400 Tartaros.bin
```

### 單鍵移除與控制器清理：0x004DFBC0

```asm
  4dfbc0:	55                   	push   ebp
  4dfbc1:	8b ec                	mov    ebp,esp
  4dfbc3:	51                   	push   ecx
  4dfbc4:	53                   	push   ebx
  4dfbc5:	56                   	push   esi
  4dfbc6:	8b f0                	mov    esi,eax
  4dfbc8:	57                   	push   edi
  4dfbc9:	8d 45 08             	lea    eax,[ebp+0x8]
  4dfbcc:	8d 5e 08             	lea    ebx,[esi+0x8]
  4dfbcf:	50                   	push   eax
  4dfbd0:	8d 45 fc             	lea    eax,[ebp-0x4]
  4dfbd3:	8b cb                	mov    ecx,ebx
  4dfbd5:	e8 26 f3 34 00       	call   0x82ef00
  4dfbda:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  4dfbdd:	3b 7e 0c             	cmp    edi,DWORD PTR [esi+0xc]
  4dfbe0:	74 41                	je     0x4dfc23
  4dfbe2:	33 f6                	xor    esi,esi
  4dfbe4:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4dfbea:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbec:	8b 42 1c             	mov    eax,DWORD PTR [edx+0x1c]
  4dfbef:	56                   	push   esi
  4dfbf0:	ff d0                	call   eax
  4dfbf2:	46                   	inc    esi
  4dfbf3:	83 fe 03             	cmp    esi,0x3
  4dfbf6:	7c ec                	jl     0x4dfbe4
  4dfbf8:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfbfb:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfbfd:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4dfc00:	ff d0                	call   eax
  4dfc02:	8b 4f 10             	mov    ecx,DWORD PTR [edi+0x10]
  4dfc05:	85 c9                	test   ecx,ecx
  4dfc07:	74 0f                	je     0x4dfc18
  4dfc09:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfc0b:	8b 02                	mov    eax,DWORD PTR [edx]
  4dfc0d:	6a 01                	push   0x1
  4dfc0f:	ff d0                	call   eax
  4dfc11:	c7 47 10 00 00 00 00 	mov    DWORD PTR [edi+0x10],0x0
  4dfc18:	57                   	push   edi
  4dfc19:	8d 4d 08             	lea    ecx,[ebp+0x8]
  4dfc1c:	51                   	push   ecx
  4dfc1d:	53                   	push   ebx
  4dfc1e:	e8 6d 6c 2d 00       	call   0x7b6890
  4dfc23:	5f                   	pop    edi
  4dfc24:	5e                   	pop    esi
  4dfc25:	5b                   	pop    ebx
  4dfc26:	8b e5                	mov    esp,ebp
  4dfc28:	5d                   	pop    ebp
  4dfc29:	c2 04 00             	ret    0x4
```

### 關聯容器移除：0x004DFC30

```asm
  4dfc30:	55                   	push   ebp
  4dfc31:	8b ec                	mov    ebp,esp
  4dfc33:	51                   	push   ecx
  4dfc34:	53                   	push   ebx
  4dfc35:	57                   	push   edi
  4dfc36:	8d 45 08             	lea    eax,[ebp+0x8]
  4dfc39:	8d 5e 18             	lea    ebx,[esi+0x18]
  4dfc3c:	50                   	push   eax
  4dfc3d:	8d 45 fc             	lea    eax,[ebp-0x4]
  4dfc40:	8b cb                	mov    ecx,ebx
  4dfc42:	e8 79 3c 36 00       	call   0x8438c0
  4dfc47:	8b 7d fc             	mov    edi,DWORD PTR [ebp-0x4]
  4dfc4a:	3b 7e 1c             	cmp    edi,DWORD PTR [esi+0x1c]
  4dfc4d:	74 36                	je     0x4dfc85
  4dfc4f:	8b 86 f8 00 00 00    	mov    eax,DWORD PTR [esi+0xf8]
  4dfc55:	85 c0                	test   eax,eax
  4dfc57:	74 11                	je     0x4dfc6a
  4dfc59:	8b 08                	mov    ecx,DWORD PTR [eax]
  4dfc5b:	3b 4d 08             	cmp    ecx,DWORD PTR [ebp+0x8]
  4dfc5e:	75 0a                	jne    0x4dfc6a
  4dfc60:	c7 86 f8 00 00 00 00 	mov    DWORD PTR [esi+0xf8],0x0
  4dfc67:	00 00 00 
  4dfc6a:	8b 47 10             	mov    eax,DWORD PTR [edi+0x10]
  4dfc6d:	85 c0                	test   eax,eax
  4dfc6f:	74 09                	je     0x4dfc7a
  4dfc71:	50                   	push   eax
  4dfc72:	e8 95 15 3b 00       	call   0x89120c
  4dfc77:	83 c4 04             	add    esp,0x4
  4dfc7a:	57                   	push   edi
  4dfc7b:	8d 55 08             	lea    edx,[ebp+0x8]
  4dfc7e:	52                   	push   edx
  4dfc7f:	53                   	push   ebx
  4dfc80:	e8 0b 6c 2d 00       	call   0x7b6890
  4dfc85:	5f                   	pop    edi
  4dfc86:	5b                   	pop    ebx
  4dfc87:	8b e5                	mov    esp,ebp
  4dfc89:	5d                   	pop    ebp
  4dfc8a:	c2 04 00             	ret    0x4
```

### 依物件 +0x88 條件移除：0x004DFC90

```asm
  4dfc90:	55                   	push   ebp
  4dfc91:	8b ec                	mov    ebp,esp
  4dfc93:	51                   	push   ecx
  4dfc94:	56                   	push   esi
  4dfc95:	57                   	push   edi
  4dfc96:	8d 78 08             	lea    edi,[eax+0x8]
  4dfc99:	8b 47 04             	mov    eax,DWORD PTR [edi+0x4]
  4dfc9c:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfc9e:	3b f0                	cmp    esi,eax
  4dfca0:	0f 84 89 00 00 00    	je     0x4dfd2f
  4dfca6:	eb 08                	jmp    0x4dfcb0
  4dfca8:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  4dfcaf:	90                   	nop
  4dfcb0:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfcb3:	8b 45 08             	mov    eax,DWORD PTR [ebp+0x8]
  4dfcb6:	39 81 88 00 00 00    	cmp    DWORD PTR [ecx+0x88],eax
  4dfcbc:	75 2c                	jne    0x4dfcea
  4dfcbe:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfcc0:	8b 42 14             	mov    eax,DWORD PTR [edx+0x14]
  4dfcc3:	ff d0                	call   eax
  4dfcc5:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfcc8:	85 c9                	test   ecx,ecx
  4dfcca:	74 0f                	je     0x4dfcdb
  4dfccc:	8b 11                	mov    edx,DWORD PTR [ecx]
  4dfcce:	8b 02                	mov    eax,DWORD PTR [edx]
  4dfcd0:	6a 01                	push   0x1
  4dfcd2:	ff d0                	call   eax
  4dfcd4:	c7 46 10 00 00 00 00 	mov    DWORD PTR [esi+0x10],0x0
  4dfcdb:	56                   	push   esi
  4dfcdc:	8d 4d fc             	lea    ecx,[ebp-0x4]
  4dfcdf:	51                   	push   ecx
  4dfce0:	57                   	push   edi
  4dfce1:	e8 aa 6b 2d 00       	call   0x7b6890
  4dfce6:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfce8:	eb 40                	jmp    0x4dfd2a
  4dfcea:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  4dfcee:	75 3a                	jne    0x4dfd2a
  4dfcf0:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  4dfcf3:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfcf7:	75 16                	jne    0x4dfd0f
  4dfcf9:	8b f0                	mov    esi,eax
  4dfcfb:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfcfd:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfd01:	75 27                	jne    0x4dfd2a
  4dfd03:	8b f0                	mov    esi,eax
  4dfd05:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfd07:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfd0b:	74 f6                	je     0x4dfd03
  4dfd0d:	eb 1b                	jmp    0x4dfd2a
  4dfd0f:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4dfd12:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfd16:	75 10                	jne    0x4dfd28
  4dfd18:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  4dfd1b:	75 0b                	jne    0x4dfd28
  4dfd1d:	8b f0                	mov    esi,eax
  4dfd1f:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4dfd22:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfd26:	74 f0                	je     0x4dfd18
  4dfd28:	8b f0                	mov    esi,eax
  4dfd2a:	3b 77 04             	cmp    esi,DWORD PTR [edi+0x4]
  4dfd2d:	75 81                	jne    0x4dfcb0
  4dfd2f:	5f                   	pop    edi
  4dfd30:	5e                   	pop    esi
  4dfd31:	8b e5                	mov    esp,ebp
  4dfd33:	5d                   	pop    ebp
  4dfd34:	c2 04 00             	ret    0x4
```

### 按 ID 低位元組掃描並釋放：0x004DFD40

```asm
  4dfd40:	55                   	push   ebp
  4dfd41:	8b ec                	mov    ebp,esp
  4dfd43:	83 e4 f8             	and    esp,0xfffffff8
  4dfd46:	83 ec 18             	sub    esp,0x18
  4dfd49:	8b 41 0c             	mov    eax,DWORD PTR [ecx+0xc]
  4dfd4c:	83 c1 08             	add    ecx,0x8
  4dfd4f:	56                   	push   esi
  4dfd50:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfd52:	57                   	push   edi
  4dfd53:	89 4c 24 08          	mov    DWORD PTR [esp+0x8],ecx
  4dfd57:	3b f0                	cmp    esi,eax
  4dfd59:	0f 84 23 01 00 00    	je     0x4dfe82
  4dfd5f:	f3 0f 10 05 c0 56 c4 	movss  xmm0,DWORD PTR ds:0xc456c0
  4dfd66:	00 
  4dfd67:	eb 07                	jmp    0x4dfd70
  4dfd69:	8d a4 24 00 00 00 00 	lea    esp,[esp+0x0]
  4dfd70:	8b 46 10             	mov    eax,DWORD PTR [esi+0x10]
  4dfd73:	0f b6 50 04          	movzx  edx,BYTE PTR [eax+0x4]
  4dfd77:	66 3b 55 08          	cmp    dx,WORD PTR [ebp+0x8]
  4dfd7b:	0f 85 b8 00 00 00    	jne    0x4dfe39
  4dfd81:	8b f8                	mov    edi,eax
  4dfd83:	85 ff                	test   edi,edi
  4dfd85:	74 72                	je     0x4dfdf9
  4dfd87:	0f b7 47 04          	movzx  eax,WORD PTR [edi+0x4]
  4dfd8b:	3c 01                	cmp    al,0x1
  4dfd8d:	74 0c                	je     0x4dfd9b
  4dfd8f:	3c 06                	cmp    al,0x6
  4dfd91:	74 08                	je     0x4dfd9b
  4dfd93:	84 c0                	test   al,al
  4dfd95:	74 04                	je     0x4dfd9b
  4dfd97:	3c 07                	cmp    al,0x7
  4dfd99:	75 5e                	jne    0x4dfdf9
  4dfd9b:	8b 87 5c 01 00 00    	mov    eax,DWORD PTR [edi+0x15c]
  4dfda1:	f3 0f 11 44 24 10    	movss  DWORD PTR [esp+0x10],xmm0
  4dfda7:	f3 0f 11 44 24 14    	movss  DWORD PTR [esp+0x14],xmm0
  4dfdad:	f3 0f 11 44 24 18    	movss  DWORD PTR [esp+0x18],xmm0
  4dfdb3:	f3 0f 11 44 24 1c    	movss  DWORD PTR [esp+0x1c],xmm0
  4dfdb9:	85 c0                	test   eax,eax
  4dfdbb:	74 3c                	je     0x4dfdf9
  4dfdbd:	83 bf 70 03 00 00 00 	cmp    DWORD PTR [edi+0x370],0x0
  4dfdc4:	74 33                	je     0x4dfdf9
  4dfdc6:	6a 00                	push   0x0
  4dfdc8:	50                   	push   eax
  4dfdc9:	e8 f2 7e 2c 00       	call   0x7a7cc0
  4dfdce:	8b 4c 24 10          	mov    ecx,DWORD PTR [esp+0x10]
  4dfdd2:	8b 54 24 14          	mov    edx,DWORD PTR [esp+0x14]
  4dfdd6:	83 ec 10             	sub    esp,0x10
  4dfdd9:	8b c4                	mov    eax,esp
  4dfddb:	89 08                	mov    DWORD PTR [eax],ecx
  4dfddd:	8b 4c 24 28          	mov    ecx,DWORD PTR [esp+0x28]
  4dfde1:	89 50 04             	mov    DWORD PTR [eax+0x4],edx
  4dfde4:	8b 54 24 2c          	mov    edx,DWORD PTR [esp+0x2c]
  4dfde8:	89 48 08             	mov    DWORD PTR [eax+0x8],ecx
  4dfdeb:	89 50 0c             	mov    DWORD PTR [eax+0xc],edx
  4dfdee:	8b 87 5c 01 00 00    	mov    eax,DWORD PTR [edi+0x15c]
  4dfdf4:	e8 f7 7d 2c 00       	call   0x7a7bf0
  4dfdf9:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfdfc:	8b 01                	mov    eax,DWORD PTR [ecx]
  4dfdfe:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4dfe01:	ff d2                	call   edx
  4dfe03:	8b 4e 10             	mov    ecx,DWORD PTR [esi+0x10]
  4dfe06:	85 c9                	test   ecx,ecx
  4dfe08:	74 0f                	je     0x4dfe19
  4dfe0a:	8b 01                	mov    eax,DWORD PTR [ecx]
  4dfe0c:	8b 10                	mov    edx,DWORD PTR [eax]
  4dfe0e:	6a 01                	push   0x1
  4dfe10:	ff d2                	call   edx
  4dfe12:	c7 46 10 00 00 00 00 	mov    DWORD PTR [esi+0x10],0x0
  4dfe19:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  4dfe1d:	56                   	push   esi
  4dfe1e:	8d 44 24 10          	lea    eax,[esp+0x10]
  4dfe22:	50                   	push   eax
  4dfe23:	51                   	push   ecx
  4dfe24:	e8 67 6a 2d 00       	call   0x7b6890
  4dfe29:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfe2b:	f3 0f 10 05 c0 56 c4 	movss  xmm0,DWORD PTR ds:0xc456c0
  4dfe32:	00 
  4dfe33:	8b 4c 24 08          	mov    ecx,DWORD PTR [esp+0x8]
  4dfe37:	eb 40                	jmp    0x4dfe79
  4dfe39:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  4dfe3d:	75 3a                	jne    0x4dfe79
  4dfe3f:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  4dfe42:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe46:	75 16                	jne    0x4dfe5e
  4dfe48:	8b f0                	mov    esi,eax
  4dfe4a:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfe4c:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe50:	75 27                	jne    0x4dfe79
  4dfe52:	8b f0                	mov    esi,eax
  4dfe54:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfe56:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe5a:	74 f6                	je     0x4dfe52
  4dfe5c:	eb 1b                	jmp    0x4dfe79
  4dfe5e:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4dfe61:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe65:	75 10                	jne    0x4dfe77
  4dfe67:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  4dfe6a:	75 0b                	jne    0x4dfe77
  4dfe6c:	8b f0                	mov    esi,eax
  4dfe6e:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4dfe71:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfe75:	74 f0                	je     0x4dfe67
  4dfe77:	8b f0                	mov    esi,eax
  4dfe79:	3b 71 04             	cmp    esi,DWORD PTR [ecx+0x4]
  4dfe7c:	0f 85 ee fe ff ff    	jne    0x4dfd70
  4dfe82:	5f                   	pop    edi
  4dfe83:	5e                   	pop    esi
  4dfe84:	8b e5                	mov    esp,ebp
  4dfe86:	5d                   	pop    ebp
  4dfe87:	c2 04 00             	ret    0x4
```

### 完整 actor tree 清除：0x004DFE90

```asm
  4dfe90:	55                   	push   ebp
  4dfe91:	8b ec                	mov    ebp,esp
  4dfe93:	53                   	push   ebx
  4dfe94:	8b 5d 08             	mov    ebx,DWORD PTR [ebp+0x8]
  4dfe97:	8b 43 0c             	mov    eax,DWORD PTR [ebx+0xc]
  4dfe9a:	56                   	push   esi
  4dfe9b:	8b 30                	mov    esi,DWORD PTR [eax]
  4dfe9d:	57                   	push   edi
  4dfe9e:	3b f0                	cmp    esi,eax
  4dfea0:	74 65                	je     0x4dff07
  4dfea2:	8b 7e 10             	mov    edi,DWORD PTR [esi+0x10]
  4dfea5:	85 ff                	test   edi,edi
  4dfea7:	74 13                	je     0x4dfebc
  4dfea9:	8b 07                	mov    eax,DWORD PTR [edi]
  4dfeab:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4dfeae:	8b cf                	mov    ecx,edi
  4dfeb0:	ff d2                	call   edx
  4dfeb2:	8b 07                	mov    eax,DWORD PTR [edi]
  4dfeb4:	8b 10                	mov    edx,DWORD PTR [eax]
  4dfeb6:	6a 01                	push   0x1
  4dfeb8:	8b cf                	mov    ecx,edi
  4dfeba:	ff d2                	call   edx
  4dfebc:	80 7e 15 00          	cmp    BYTE PTR [esi+0x15],0x0
  4dfec0:	75 40                	jne    0x4dff02
  4dfec2:	8b 46 08             	mov    eax,DWORD PTR [esi+0x8]
  4dfec5:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfec9:	75 16                	jne    0x4dfee1
  4dfecb:	8b f0                	mov    esi,eax
  4dfecd:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfecf:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfed3:	75 2d                	jne    0x4dff02
  4dfed5:	8b f0                	mov    esi,eax
  4dfed7:	8b 06                	mov    eax,DWORD PTR [esi]
  4dfed9:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfedd:	74 f6                	je     0x4dfed5
  4dfedf:	eb 21                	jmp    0x4dff02
  4dfee1:	8b 46 04             	mov    eax,DWORD PTR [esi+0x4]
  4dfee4:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfee8:	75 16                	jne    0x4dff00
  4dfeea:	8d 9b 00 00 00 00    	lea    ebx,[ebx+0x0]
  4dfef0:	3b 70 08             	cmp    esi,DWORD PTR [eax+0x8]
  4dfef3:	75 0b                	jne    0x4dff00
  4dfef5:	8b f0                	mov    esi,eax
  4dfef7:	8b 40 04             	mov    eax,DWORD PTR [eax+0x4]
  4dfefa:	80 78 15 00          	cmp    BYTE PTR [eax+0x15],0x0
  4dfefe:	74 f0                	je     0x4dfef0
  4dff00:	8b f0                	mov    esi,eax
  4dff02:	3b 73 0c             	cmp    esi,DWORD PTR [ebx+0xc]
  4dff05:	75 9b                	jne    0x4dfea2
  4dff07:	8d 7b 08             	lea    edi,[ebx+0x8]
  4dff0a:	e8 41 39 34 00       	call   0x823850
  4dff0f:	8b 0d a4 a7 fb 00    	mov    ecx,DWORD PTR ds:0xfba7a4
  4dff15:	8b 01                	mov    eax,DWORD PTR [ecx]
  4dff17:	8b 50 14             	mov    edx,DWORD PTR [eax+0x14]
  4dff1a:	ff d2                	call   edx
  4dff1c:	5f                   	pop    edi
  4dff1d:	5e                   	pop    esi
  4dff1e:	5b                   	pop    ebx
  4dff1f:	5d                   	pop    ebp
  4dff20:	c2 04 00             	ret    0x4
```
