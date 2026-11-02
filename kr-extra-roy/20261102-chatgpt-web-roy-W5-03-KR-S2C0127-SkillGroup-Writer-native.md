# W5-03 — KR S2C 0x0127：角色技能群組快照／重新填入／後續狀態消費（BIN-first）

> 2026-11-02，chatgpt-web roy，既有 extra/roy2。承接 W5-01 與 W5-02；**本次新交付是技能群組 Client S2C 接收契約的有界正向證據，不是「取得技能」完整交易或 W5 FULL-PASS**。原始 KR Client 未執行、未修改、未附加；沒有 Server 操作，也沒有負向/重登/重播/併發/故障/壓測。原版 Server 內部規則由 S00 決策，T01 獨立驗證。禁止把現有 skill matrix reader、角色屬性、獎勵 type 等幾個不同 domain 混用。

## 0. 基準與交叉來源

- 第一手唯讀 KR Tartaros.bin：12,472,320 bytes，SHA256 **9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91**，本輪實際重新計算吻合。PE32 i386，ImageBase 0x400000，.text VA=0x401000、raw=0x400，code raw=VA−0x400C00。所有以下 ASM 地址均屬此原件，不跨 TC。
- 目前同分支前一批 W5-02：kr-extra-roy/20261102-chatgpt-web-roy-W5-02-KR-S2C005C-RoleStat-QuestCandidate-native.md，blob **295d96901492c5f162fd6de9fdc3bc885ab4fa54**；機讀 blob **c1a9334b6101cb24a536eaea320deee00e9f8273**。前一批 S2C0x005C 更新 record+0x08,+0x40..0x74,+0xD4，再呼叫 Quest0x500240；這一批 **S2C0x0127 更新 role+0x110 的技能群組結構**，沒有把兩個 opcode 當別名。
- 既有技能 T11 來源入口：kr/tasks/T11/README.md 與 native-index skill matrix consumers；W5-01 已引用 0x61C7C0 skill matrix read。T03-E 的角色 S2C0x0002/0x002B 53B row 與 RoleStore pointer F94304/Client+6924 僅引用主責，不複寫既有結論。Quest T16 及 Reward type 映射仍獨立。
- 本輪按已知入口用 objdump 從原始 BIN 提取 0x4E1DA0/4E21BF、0x4E48A0..4E4AA5、0x4D4270、0x41D780、0x61C7C0；獨立唯讀 checker 確認 **44 個 machine-code prefix、兩個 E8 callee、table index、正向 entry stride**，PASS。這是限定 bytes/CFG，不是全部函式全文審核、UI 動態或官方 Server 交易。

## 1. 原生 S2C app0x0127 registration：不是推測 opcode

Role/Client manager 的 8-byte callback table 由 0x4E1DA0 建構：每個 slot 在表基底 +4 寫 handler，slot+8 為下一命令；原 T03-E 已由 0x4E1E3F 的 +0x15C 對應 app0x002B/0x4E2730 複核此基準。現在新的：

~~~asm
4E1DA4 BE D5 0B 00 00          mov esi,0xBD5
4E1DB0 C7 42 FC 40 7D 4B 00   mov [edx-4],0x4B7D40
4E1DB7 89 0A                   mov [edx],ecx
4E1DB9 83 C2 08                add edx,8
4E21BF C7 80 3C 09 00 00 A0 48 4E 00
                                  mov [eax+0x93C],0x4E48A0
~~~

因 0x93C = 4 + 8×295，295 decimal = **0x0127**。此 S2C 命令在此 callback table 指向 **0x4E48A0**。它不同於第一層 SceneManager 的表、也不同於同數字 C2S 或 T02 外層 marker；尚需要有效 Client/Conn/lane、manager/scene callback 安裝才能到達。

## 2. 更新流程：RoleStore slot → 技能群組 → 逐筆資料 → recompute/UI

~~~asm
4E48C8 8B 75 08                mov esi,[ebp+8]        ; decoded app payload
4E48CB 0F B6 7E 02             movzx edi,byte [esi+2] ; role slot
4E48CF 8B 89 24 69 00 00      mov ecx,[ecx+0x6924]  ; RoleStore
4E48D5 83 FF 09                cmp edi,9
4E48DE 69 FF 10 02 00 00      imul edi,edi,0x210
4E48E4 03 F9                   add edi,ecx          ; selected RoleRecord
4E48F0 8A 46 03                mov al,[esi+3]       ; skill group
4E48F3 8A 4E 04                mov cl,[esi+4]       ; group metadata byte
4E48F6 3C 07                   cmp al,7
4E4906 8D 84 97 10 01 00 00   lea eax,[edi+edx*4+0x110] ; category+28*g
4E4911 88 48 18                mov [eax+0x18],cl    ; group metadata
4E4914 8A 46 03                mov al,[esi+3]
4E4917 8B D7                   mov edx,edi
4E4919 E8 52 F9 FE FF          call 4D4270         ; clear selected category vector
4E491E 8B 45 0C                mov eax,[ebp+0xC]   ; total decoded app length
4E4921 83 F8 05                cmp eax,5
4E492A 83 C0 FB                add eax,-5
4E492D C1 E8 02                shr eax,2            ; floor((n-5)/4)
4E4934 83 C6 05                add esi,5            ; first 4B record
4E4943 8A 40 03                mov al,[payload+3]   ; original group
4E4946 8A 4E 02                mov cl,[cursor+2]    ; entry byte
4E4949 0F B7 16                movzx edx,word [cursor+0]
4E494C 3C 07                   cmp al,7
4E4961 8D B4 97 10 01 00 00   lea esi,[edi+group*28+0x110]
4E4968 E8 13 8E F3 FF          call 41D780         ; metadata lookup, append/update entry
4E4970 83 C6 04                add esi,4
4E4A34 8D 87 FC 00 00 00      lea eax,[edi+0xFC]   ; additional shared skill data
4E4A3E E8 AD 8B F3 FF          call 41D5F0
4E4A82 E8 19 15 34 00          call 825FA0         ; downstream update/notification
~~~

**局部先決**：role index<=9；RoleStore+index×0x210 可用；此 handler 的 record 不像 W5-02 的 0x005C 那樣顯式先檢查 record+0x5C present flag，不能自動說「不存在的角色一定被拒絕」。技能 group BYTE+3 必須在 0..6，否則不在此局部的 category vector 寫入分支；helper 0x4D4270 自己也檢查 AL <7。合法群組下 0x4D4270 對 record+0x110+group*0x1C 清理有效 vector end、將 group+0x14 aggregate flag 歸0，再逐列以 0x41D780 更新。**這是 snapshot/rebuild 型態的已見資料處理**；不代表是某一個技能解鎖事件的唯一增量格式。

0x41D780 的關鍵反查：它先以 entry u16 key 查 [FB11AC] metadata map；失敗可返回0，不保證所有 ID 被採用。對同一 category 已有的 key，0x41D82C/82E 比對 entry key、0x41D890..899 覆寫該筆 vector-entry+4 的 WORD value；新 key 可由 0x41D8B7..BC 寫入 8-byte record（DWORD key + WORD value），並將 vector end +8。0x41D845/848 與 0x41D899..89F 可用 metadata+4 更新 category+0x14 aggregate flag。**這一點比只看到「SkillList reader」更接近真正的 Client SkillStore Writer。**

## 3. S2C 0x0127 已讀到的 Payload 契約

Offset **從 decoded application payload 起點**，不含 frame header。

| Offset | Type | Local reader/writer | 有界意義與 UNKNOWN |
| --- | --- | --- | --- |
| +0..1 | u16 LE | Role/Client callback table | opcode 0x0127 |
| +2 | u8 | 4E48CB、4E48D5 | RoleStore slot index 0..9 |
| +3 | u8 | 4E48F0/F6、4E4914、4E4943 | Group index 0..6；選 record+0x110 + 0x1C×g |
| +4 | u8 | 4E48F3 → 4E4911 | group+0x18 metadata byte，正式語義 U |
| +5 + 4*i +0..1 | u16 LE | 4E4949 → 41D780 [EBP+8] | skill-like key / metadata map key；不擅自命名為官方學習授予 ID |
| +5 + 4*i +2 | u8 | 4E4946 → 41D780 [EBP+0xC] | vector-entry+4 WORD value，通常可對照技能屬性/等級，但官方意義 U |
| +5 + 4*i +3 | u8 | 本局部迴圈只 cursor+4，不讀該 byte | 未證，**不可命名 padding/固定0** |
| 之後 | any | 本局部未見讀取 | 不推完整 wire size |

已讀最小正常 payload **5 bytes**（零條目），當有 N 條目時至少 **5+4N bytes**；迴圈計數由 floor((totalAppLength−5)/4) 計算，所以不是 packet header 中直接有一個已證的 count。**最後未滿4 bytes 的尾端在這個 loop 不成完整 entry**，不能從此宣稱一定安全拒絕 malformed 封包；本次未做負向執行測試。

伺服器的 profile 安全策略可以選擇只產生 payload 長度剛好 5+4N，group 0..6、skill metadata ID 有來源、值與權限合法，但這是**自訂 Server 相容條件**，不是這段 Client static 說原版官方必然如此。

## 4. 技能寫入與其他 W5 封包不能混同

| Client 更新種類 | 已證目的 | 不能誤認 |
| --- | --- | --- |
| S2C0x0002/0x002B | RoleStore 53B row/名單及 present flag | 不等於學會技能 |
| S2C0x005C | 同一角色的基本數值（+8、+40..+74、+D4），之後 Quest 0x500240 rebuild | **不**等於 skill-group vector write |
| **S2C0x0127** | RoleStore +0x110 + group*0x1C 的 8B records、group+0x14/+0x18，後續 41D5F0/825FA0 | 不是 item/equipment grant，也不是 Quest prerequisite append |
| 0x61C7C0 | 已存在角色技能/矩陣 reader（依 slot/metadata gate） | reader 不證新學習交易與正式 cooldown policy |
| Quest Reward XML type1..6 | QuestRecord 的數字資料欄位（與 W5-01 一致） | reward type/value 不提供 skill acquisition request/reply |

**可直接採用的成果**：若已有一個合法角色和技能群組狀態，Server 可以在自己的資料模型中準備、經 T01/S00 審核後實作 S2C0x0127 的**技能群組更新 DTO**，並用原版 Client 正常正向測試驗證 UI 消費；不能在未核權時直接啟用，亦不能由此證明這是玩家招募/升級/任務獎勵時必發的封包。

**還缺且可繼續做 Client 靜態分析**：
1. 真正 **C2S learn/unlock request Producer**、技能成本/前置與合法 callback。
2. 0x0127 這個 S2C 的所有相關 caller（及其它技能更新 opcode），其對 gameplay/quest/reward 何時出現的因果；目前唯一證的是 callback handler 接收和本地 state writer。
3. 0x825FA0 下游 UI listener、資料刷新、角色有效性條件；本次僅證本地呼叫，不宣稱畫面已可見。
4. 該 record metadata FB11AC 的官方 key/value 語義與完整技能存檔/重新同步；目前無真 Session/Server trace。
5. **裝備／Inventory** 仍沒有從某個官方 C2S/S2C packet 到 ItemStore/equip-slot/角色外觀的正向全鏈；不能把 0x0127、0x005C 或 Reward type3/4 填進這個缺口。
6. **招募** 仍須真實 C2S event、S2C grant/roster 的來源與角色 ownership；0x0127 不創建角色或修改 RoleStore+5C present flag。

## 5. Server 待開發／Client 待逆向／整合／遊玩驗收

- **Server 待開發（政策層）**：Server-owned CharacterSkillCollection（角色ID、技能群組、skill key、對應 level/value、revision）、技能合法授予、完整技能狀態持久化、reward/quest 與技能更新交易的權威分離；收到 Client command 的技能成本、解鎖與 UI 同步必須用已審核 native contract，不由本稿擅自創造官方政策。
- **Client 待逆向（實際 wire）**：C2S 技能學習/升級、S2C 解鎖結果與 0x0127 配對、裝備取得/穿戴、招募結果，以及這些變化是否另有不同 S2C UI/snapshot 命令；不得把它們全歸為 Server-only unknown。
- **跨功能待整合**：T11 技能矩陣及 skill object、T03 角色/RowStore、T04 初始技能與裝備、T15 保存、T16 Quest reward、T02 framing；T01 個別驗證本稿的 S2C0x0127 欄位和 41D780 vector+metadata semantics，再交 S00 設計/開發。
- **待遊玩驗證**：有效 KR 角色透過受信 Server 得到合法 0x0127 訊息，檢視角色技能群組實際 UI、正常技能使用能力與場景綁定；原版 Client 沒有在本輪執行，NOT_RUN。

**W5-03 已提交原生正向源證據，W5 整體仍 PARTIAL**。本次 byte verifier PASS 不等於 T01 全文 FULL-PASS 或原版 Server 真實封包／技能取得已恢復。
