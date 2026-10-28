# T16-89 — KR QuestInfo / QuestTalk 真正的 XML loader 與 AcceptAction / CompleteAction 解析入口

> 研究者：chatgpt-web roy；2026-10-28 Asia/Taipei。此檔 20:25:25（Asia/Taipei）為提交前實際檔案命名時間。T16 Quest & Story Progression，僅原版 KR Client，BIN-first。

## 0. 來源、約束與校驗

- 唯讀 /mnt/data/Tartaros.bin，實測 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。
- /mnt/data/Tartaros.exe SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- objdump PE32 .text VA 0x00401000 raw 0x400, raw=VA−0x00400C00；.rdata VA 0x00BD2000 raw 0x007D0600, **raw=VA−0x00401A00**；.data VA 0x00D61000 raw 0x0095E800，raw=VA−0x00402800。
- GitHub 最新 main：T16-88 已交付；T16-86/87 action factory 後經 T16-88 證明是 **ItemUsableTable.xml/ItemUsingMsg.xml 的道具資料**，不能視為 Quest。
- 本段沒有執行、改動、hook Client，也沒有原始 Server 程式、Quest XML 檔本體或真實抓包。故本文建立的是 **Quest XML loader** 的原生證據，非任務收發封包驗收。T02/T07/T14/T15 主責不變。

## 1. T16-89 第 1 輪：由 XML 字串直接反向追至初始化 caller

對 BIN 原始字元序列掃描：

| ASCII 原文 | BIN raw | .rdata VA | .text 中直接引用 |
|---|---:|---:|---:|
| Table/QuestInfo.xml | 0x80C148 | 0xC0DB48 | 0x50478B（立即數操作數）；完整指令 0x50478B |
| Table/QuestTalk.xml | 0x80C15C | 0xC0DB5C | 0x5055B8（立即數操作數）；完整指令 0x5055B8 |
| AcceptAction | 0x80C1D0 | 0xC0DBD0 | 0x504ADF–0x504AE4 |
| CompleteAction | 0x80C1E8 | 0xC0DBE8 | 0x504B52–0x504B57 |

字串之 VA 的轉換採此版本真實 .rdata section，不得沿用更早筆記的錯誤 VA/raw 差值。

對原始 .text 做 E8-rel32 靜態掃描，逐項反組譯核對**直接 caller**：
- `0x5043E9: call 0x504740`，唯一掃描命中。
- `0x5043EF: call 0x505570`，唯一掃描命中。
- 兩個 call 在 **同一函式 `0x504370` 中連續出現**，先 QuestInfo，再 QuestTalk。

```asm
504370: push ebp
504371: mov ebp,esp
50439d: xor esi,esi
50439f: push 0xb8
5043aa: mov DWORD PTR [edi+0x8],esi
5043ad: call 0x891268
5043b5: cmp eax,esi
5043b7: je 0x504522
5043bd: mov DWORD PTR [edi+0x4],eax
5043c0: mov DWORD PTR [eax],eax
5043c2: mov eax,DWORD PTR [edi+0x4]
5043c5: mov DWORD PTR [eax+0x4],eax
5043c8: mov eax,DWORD PTR [edi+0x4]
5043cb: mov DWORD PTR [eax+0x8],eax
5043ce: mov eax,DWORD PTR [edi+0x4]
5043d1: mov ebx,0x1
5043d6: mov BYTE PTR [eax+0xb4],bl
5043dc: mov ecx,DWORD PTR [edi+0x4]
5043df: mov BYTE PTR [ecx+0xb5],bl
5043e5: push edi
5043e6: mov DWORD PTR [ebp-0x4],esi
5043e9: call 0x504740
5043ee: push edi
5043ef: call 0x505570
5043f4: lea edx,[ebp-0xb8]
5043fa: push edx
5043fb: call 0x4ff920
```

**已確認行為**：`0x504370` 將類似容器的 `+0x4` 指向配置的 0xB8-byte 節點，初始化自連結的 `+0,+4,+8` 三個鏈接及 `+0xB4,+0xB5` flags，然後將 `EDI` 作為兩個 loader 參數連續呼叫。

注意 `EDI` 的正式類別與容器所有權，仍需其 caller 驗證；不能由相鄰函式就認定它是 Quest cache 或網路 handler。配置 0xB8 是容器節點大小，不可等同 QuestInfo XML row 大小。

## 2. QuestInfo 真正的 loader：0x504740

```asm
504740: push ebp
504741: mov ebp,esp
504754: sub esp,0x248
504780: mov eax,DWORD PTR [ebp+0x8]
504783: lea ecx,[esp+0x12c]
50478a: push ecx
50478b: mov ecx,0xc0db48 ; "Table/QuestInfo.xml"
504794: call 0x72ee30
504799: xor edi,edi
5047a9: mov ebx,0x10
5047be: push edi
5047bf: lea esi,[esp+0x130]
5047c6: call 0x72f110
5047cb: cmp BYTE PTR [esp+0x170],0x0
5047d3: je 0x504831
5047e0: mov DWORD PTR [esp+0x12c],0xbf2394
504825: call 0x72e040
50482a: xor eax,eax
50482c: jmp 0x5054d8
```

原生可證：使用 `Table/QuestInfo.xml` 路徑初始化本地讀檔/解析物件，`0x72F110` 之後檢查局部成功旗標；若失敗則清理局部 string/buffer 與返回 failure（此階段的 0x5054D8 是函式內共同清理出口）。不能把 XML parser 結果當 Server 傳來的 Quest state。

### 2.1 QuestInfo 內部欄位引用

```asm
504adf: mov edi,0xc0dbd0 ; "AcceptAction"
504ae4: mov eax,esi
504ae6: call 0x72e360
504aeb: test eax,eax
504aed: je 0x504b52
504aef: lea edi,[eax+0x44]
504af2: push 0xbfb808
504af7: call 0x7300a0
504afc: test eax,eax
504afe: je 0x504b19
504b1b: push 0xc0dbe0
504b27: call 0x7300a0
504b52: mov edi,0xc0dbe8 ; "CompleteAction"
504b57: mov eax,esi
504b59: call 0x72e360
504b5e: test eax,eax
504b60: je 0x504bc5
504b62: lea edi,[eax+0x44]
504b65: push 0xbfb808
504b6a: call 0x7300a0
504bc5: push 0xc0dbf8
504bcc: call 0x72e2e0
504bd1: test eax,eax
504bd3: je 0x504ccd
```

已證實：QuestInfo XML 節點的 `AcceptAction` 與 `CompleteAction` 分別被 `0x72E360` 依欄名尋找，若存在則沿 `+0x44` 子結構再次呼叫 `0x7300A0` 讀取指定屬性，可能進一步用 `0x8917B4` 字元→數值轉換。**不要因欄位名稱就宣稱 accept callback、接任務封包或遊戲中的完成條件已解析**。實際寫入目標/物件類型需下一段針對 `0x504CCD` 後的行程驗證。

## 3. QuestTalk 真正的 loader：0x505570

```asm
505570: push ebp
505571: mov ebp,esp
505584: sub esp,0x98
5055b0: mov eax,DWORD PTR [ebp+0x8]
5055b3: lea ecx,[esp+0x24]
5055b7: push ecx
5055b8: mov ecx,0xc0db5c ; "Table/QuestTalk.xml"
5055c1: call 0x72ee30
5055c6: xor ebx,ebx
5055cf: mov ecx,DWORD PTR [esp+0x44]
5055d8: cmp DWORD PTR [esp+0x58],edi
5055e2: push ebx
5055e3: lea esi,[esp+0x28]
5055e7: call 0x72f110
5055ec: cmp BYTE PTR [esp+0x68],bl
5055f0: je 0x505641
5055f2: mov DWORD PTR [esp+0xb0],0xffffffff
505635: call 0x72e040
50563a: xor eax,eax
50563c: jmp 0x50582d
```

第二個 loader 和 QuestInfo loader 遵循類似讀檔初始化、狀態檢查與失敗清理框架；但兩函式實際容器寫入方式未逐指令閉合，**不得因相同 helper 就假設 QuestTalk 與 QuestInfo 存到同一元素類型**。

## 4. 關係、界線與下一步

```text
0x504370 [shared init / container]
  ├─ call 0x504740 → "Table/QuestInfo.xml"
  │   ├─ XML/path preparation 0x72EE30
  │   ├─ reader/load helper 0x72F110
  │   └─ field searches "AcceptAction", "CompleteAction" via 0x72E360
  └─ call 0x505570 → "Table/QuestTalk.xml"
      ├─ 0x72EE30
      └─ 0x72F110
```

**證據層級**：
- 原生已確認：XML 原文字串及 VA/raw、唯一直接 E8-rel32 caller、順序呼叫兩 loader、基本 XML 成功／失敗分支、兩個 QuestInfo 欄位名及查找函式。
- 部分確認：`0x504370` 建立可用於兩個 loader 的 container，部分節點初始化；完整 XML 解析到元素欄位仍待查。
- 尚待驗證：QuestInfo item/row layout、QuestTalk row、caller 是誰、AcceptAction/CompleteAction 的狀態 writer/consumer、NPC click callback、Quest C→S 或 S→C packet header/handler。
- 反證：`0x522D20 → 0x523260` 屬 ItemUsable XML，不可替代本段真正 QuestInfo loader；`0x504740/0x505570` 是資源讀取，現有路徑未連到 socket，**未找到≠證明永不發包**。
- 原始 Server Quest16→Quest15 前置、通關結算與保存資料庫仍未知，不能從 Client XML loader 推論。

### 第 1 輪門檻

本次從前段誤歸屬的 ItemUsable loader 成功切到 QuestInfo、QuestTalk **真正路徑**，有字串 raw/VA、兩個 verified E8 callers、容器初始化、XML 欄位 consumer 與失敗分支共同構成新上下游原生功能鏈，足以作為本段重大進展。故 `T16-89-2` / `T16-89-3` **未啟動**，不捏造搜尋。

下一正式段 `T16-90`：`0x504740` 內 `0x504CCD–0x5054D8` 的 XML row → 實際 container writer，以及 `0x505570` 成功分支至 `0x50582D` 的資料寫入；再向 `0x504370` caller 追使用者。並以 T02 receiver/business dispatcher 或真正 Quest cache writer 獨立尋找 C→S/S→C，不能只停留在資源 loader。

## 5. 玩家情境 × Client ↔ Server 矩陣

| 玩家操作 | 本段可驗證 Client 本地行為 | C→S (opcode/len/fields) | S→C (handler/fields) | Client Quest/UI state | Server 相容需求 |
|---|---|---|---|---|---|
| 啟動並載入任務資料 | 0x504370 先讀 QuestInfo 後讀 QuestTalk | unknown | unknown | XML 資料載入（已確認）；是否更新任務 cache unknown | 不因資源 loader 直接新增協定 |
| NPC 選擇任務、點接取 | 尚未找到玩家操作 callback | unknown | unknown | AcceptAction 欄位解析可證，與操作未連線 | 接取確認/拒絕協定待原生證據 |
| 完成/交付任務 | 尚未確認交付 native callback | unknown | unknown | CompleteAction 欄位名稱已找到，消費者 unknown | Server 完成裁決與 DB 不能從 XML 猜補 |
| 教學/劇情 RequestStartScenario | 前段 T16-65..70 已追過 4-byte 本機 payload | wire opcode domain 未定 | unknown | unknown | 需真正封包證據 |

## 6. 資料管理

本次僅提交 `kr-temp-roy/` 的 T16 Markdown 技術原稿；不修改 Task catalog、其他研究者資料或二進位。上一段 T16-88 修正照舊保留；本段提供真正 Quest XML 路徑以接續。
