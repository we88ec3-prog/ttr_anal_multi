# KR Client — Scenario 狀態容器：原生讀取與重設（兩筆有界 FULL-PASS）

審核日期：2026-10-28（Asia/Taipei）；審核者：ChatGPT GPT-6。原件：KR `Tartaros.bin`，12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。PE `.text` VA=0x401000/raw=0x400，以下 VA→raw = VA − 0x401000 + 0x400。

原始來源 Task：T14；原稿 `kr/evidence/1d78642bfec7b5005988a1c2121404a3daadd2f62ba1e0068f8918b314b1ae99.txt`，Git blob `909cd378dbe0283355924358d3087c88ff7b49a3`；另一歷史機器碼來源 `kr/evidence/4588fb3ec2f797c4231f0797c68b22a249ab8541d77d5bd48e7d61c23d6f779d.txt`，blob `603357b26291eb8af7cee4f07d3e3c55914fe2d7`。不改歷史 Claim/verdict。

## CK-SCENARIO-MAP-READ-NATIVE-01 — FULL-PASS（限定正常返回）

**精確結論：** 當 ECX 指向有效 owner、整數 key 實參有效，且 `0x4C2880` 正常返回合法 value 指標時，`0x4AA510` 將 ECX+4 作為容器，將 `[EBP+8]` 的地址傳給 Map accessor，再從回傳指標讀取 DWORD 至 EAX，最後 `ret 4`。本體無額外條件分支。

逐指令（原件 raw `0xA9910`）：
```asm
4AA510 push ebp
4AA511 mov ebp,esp
4AA513 lea eax,[ecx+4]
4AA516 lea edx,[ebp+8]
4AA519 call 0x4C2880
4AA51E mov eax,[eax]
4AA520 pop ebp
4AA521 ret 4
```
20-byte BIN 視窗 SHA256 `56570b9ffbec6f763df4e278d34c59620e6726cb5fbbe2c42da7151cfa41e8db`。Accessor `0x4C2880` 已核對既有 key 返回 node+0x10、缺鍵時初始化值 0 並呼叫插入 helper 的主要路徑；**不保證配置失敗、例外路徑或全局 Lua binding 永遠不變**。已知關聯：`0x4AB958` 寫 FE1880=`0x4AA510`；`0x4ACA76` 讀 FE1880 並向 `0x4ACF90` 傳 callback；`0x4ACFF0` 是間接 call。全生命周期及其他 writer 未窮盡。

## CK-SCENARIO-MAP-CLEAR-STATE-01 — FULL-PASS（限定正常返回）

**精確結論：** 當 EDI 指向有效樹容器、節點與 sentinel 有效，且被呼叫的節點清理函式正常返回時，`0x823850` 先依 sentinel 標記決定是否循環處理節點，再將 `[EDI+4]` 指向的 sentinel 三個 links（+4、+0、+8）指回自身，最後寫入 `DWORD [EDI+8]=0` 並返回。

主要指令（raw `0x422C50`）：
```asm
823857 cmp byte ptr [ebx+0x15],0
82385E jne 0x82387E
823866 call 0x73EBA0
82386E call 0x89120C
82387C je 0x823860
823881 mov [eax+4],eax
823887 mov [eax],eax
82388D mov [eax+8],eax
823890 mov dword ptr [edi+8],0
823898 ret
```
73-byte 視窗 SHA256 `e6c34542ace750d3a671b99b77fbf5367cdaaf2fabade389afd63ff8675556dd`。已確認的一條具體 caller 路徑：`0x4C4D3A mov esi,0xFC0F84` → `0x4C4D3F call 0x4A8A60` → `0x4A8A87 lea edi,[esi+4]` → `0x4A8A94 call 0x823850`，因此此路徑容器位址 `0xFC0F88`。不主張任意 scene 的所有節點擁有權／釋放語意或 TUTO 永久狀態保證。

## 尚未 FULL-PASS／其他責任

Client 待逆向：FE1804/FE1880 所有 writer 和場景世代、Map accessor 配置/例外、Lua callback 的全部生命週期；完整讀寫同一 owner 的無條件性未證。Server 待開發：官方勝負／獎勵／交易持久化；跨功能待整合：TUTO reset 和教學等待 coroutine；遊玩待驗證：無動態測試。這兩筆 FULL-PASS **不代表 T14 整份報告、整個 Lua reader/reset 生命周期或遊戲功能完成**。

審核方法：本地完整原件 SHA、PE/raw 換算、BIN-first 指令邊界、getter 函式全部路徑、clear 的分支/迴圈與返回後容器狀態、caller/callee 及必要資料流、歷史原稿差異與範圍限制核對。未發現可推翻上述**有界且條件化**主張的衝突；其他未閉合主張明確不予准入。審核決議：以上兩個獨立 ID **FULL-PASS**，其他範圍 **NOT_ADMITTED**。
