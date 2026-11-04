# W2-RESULT-01 — Field19／Case103 一般 Scenario22/type0 → C2S33 首批限定契約

> 2026-11-02 09:41 Asia/Taipei；作者 chatgpt-web roy；既有 extra/roy2 分支。**首批而非 W2 全部完成**。不改 Client／Server、其他 Task、原始證據、正式 RR／APPROVED；不做負向／重播／重登／併發／故障／壓測、不重新分析 AI／MEF／連擊。T01 負責獨立驗證，S00 決定 Server 採用。原生位元組抽查與原件 hash 不等於全文 FULL-PASS。

## 0. 來源與方法
- W2 卡 research/handoffs/s00-phindos-mainline-20261102/W2-SCENARIO-RESULTS.md，blob 3a7b1e6c2f53db6e3705387447908143deafb641；總卡 README blob 591220e86761cbec715838cc26641d4798a832c7；唯讀 RESOURCE-BASELINE.json（commit 27c1faf7d）blob 5ac883881d3ab0c711ad7c0bdd84c4dd3c2e5cd6。
- 原始 KR Tartaros.bin：12,472,320 bytes，**實際 SHA256 = 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91**；PE32 i386、ImageBase 0x400000、.text VA 0x401000、raw offset 0x400，該 section 的 VA-to-raw = VA − 0x400C00。未啟動/修改/附加 Client。
- 本機 Table.stp SHA256 = 09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442，Event.stp SHA256 = 2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b。Pinned RESOURCE-BASELINE 的 Table member carrier SHA 是 ea2af30c9a451dcebcf2318868ec13153f8be5647db4ab84e7a38cd1dba4154c，**不能把不同 carrier 等同**；本次僅引用 pinned member facts，沒有重解包/重驗 member。
- 繼承 T14 WP03 blob de17ff49afb2ff460453784b8c1180e63021a3b9（一般結果與 0033 返回）、WP02 blob 827216ca7b8ce9dc7460b37673e057d4b0753448、T16-135 blob b0a15aaabe1fc2d86225c5d5466b6ab78564c29c（Quest15 與 Scene）。本輪按下列精確 VA 從本機原始 BIN 重核 native bytes/指令；保留 T14、T07、T16 主責，不自行升格來源。

## 1. 正確的資源 Domain，不能把所有 ID 放進一個欄位

| Domain／型別 | Pinned resource | 本批使用界線 |
| --- | --- | --- |
| QuestInfo row | QuestID=15、type2、town=5、field=19、giver/finisher NPC10338、Demand=16、level1；raw reward type2=2800/type4=468 | Quest16 前置、Quest15 任務候選；**reward type 語義未證** |
| CaseList row | CaseID=103，STAGE=19，MAPFLOW=CHART_S_pathofpindus_01.xml，CLUSTER=CLUST_S_pathofpindus_01.xml | Case preload 必須是 Case 域，不用 QuestID15 或 FieldID19 代填 |
| MapFlow | node1: map191 (100%), node2: map192 (100%)；node1 type0、node2 type1 | 只是資源次序與各節點 map；百分比不等於通關判定 |
| MapList | map191 → S_pathofpindus01.mef／scenario_pathofpindus01D／scenario_pathofpindus01；map192 → S_pathofpindus02.mef／scenario_pathofpindus02D／scenario_pathofpindus02 | trigger、map、bound 是不同資源 |
| BoundMap | Scenario191/192 兩個 BND 的 header version2、768×768/world768；Town1/map182 的 BND version0/world1536 | **version2 格式仍 U**，不可使用 version0 全清/改 version 標籤 |
| 進村 | TownID1／map182 與 Quest/Scene key (15,3) | (15,3) 是 Event SceneList pair，不是 C2S33 目的地，亦不證明 Quest15 已完成 |

Pinned component SHA：Chart 79f79516d68183a0f8efb44664139f2c69813c4c190f5e89bbacfef82e6d5049；Map191 BND adb627155fc051aaa5a568ae57fe8731d388d58c2cf3244711078ef377321c58；Map192 BND 89cc3d4b77d3cf0cdf64d45f610d7b987c704bc268881c13396e1375a2234fff。這些 hash 是 pinned report，不是本次獨立 materialization。

## 2. 首批正常進場→結果→返回偏序，及尚不可填值的入口

| 正常 phase | Client 資料方向／來源 | Server 可以先交付（自訂設計） | 不可宣稱已證的內容 |
| --- | --- | --- | --- |
| 任務 eligibility | T16 有界 QuestOwner／Q15 Demand16；Pinned field19 | 驗證 Q15 與前置／資料庫進度；不要提前發獎 | Q15 與 Case103 必須同數值 |
| Case preload | Field19→Case103→Chart node1/2→Map191/192 | Typed ScenarioCatalog(stage19,case103,chart,orderedMaps) | 原本 C2S 預載 key=FieldID 或 QuestID |
| Formation / Enter | 工作卡列 C2S 004E/0028 token、S2C 005F/type2/kind3、0038 subtype2/6、0012/reset/actor-bind/0014 | 保留編隊 token **opaque**、正常 phase Entering→Ready；不同 opcode/direction 各自 DTO | 004E/0028 任一長度/欄位或官方 token echo、這些封包唯一固定順序 |
| Map node | Chart node1=Map191→node2=Map192 | 由 Server 另儲 node ID 和 map ID；合法座標、版本2碰撞先驗證 | MapFlow x/y 是出生點；MEF 自動換圖、固定倒數、全清怪即完成 |
| 結果 | **S2C 0022/type0** 在 SceneManager 0x4B9770 結果 consumer | source-reviewed 有界 22-byte app prefix 的合成結果 DTO | 整份 wire 長度必為22；type0=勝利；結果當場發獎 |
| 結果頁返回 | 結果 UI event0x578→F431F→在 zero branch 送 **C2S 0033、2 byte、slot0** | 收到 33 僅解 ReturnRequested；依 Server 保存目的地/phase | 0033 自帶 Town/Map/Quest/Case ID 或保證直接進村 |
| 村莊 | 獨立 T16 Scene(15,3) 及 Town1/map182 | 合法完成及 Quest state 才進入另外 scene/map bootstrap | 33 自動完成 Quest15 或自動觸發 (15,3) |

005F/type2 的既有 scene router 可參考 T07/T02：0x4B99C0，0x4B9A26 從 app payload+2 讀 unsigned subtype，type2 在既存局部來源的候選路由內。**本首批並未封閉其 Field19-specific 所有欄位、actor bind、ready 或由哪個 C2S 引起**，須以 UNKNOWN 留給 W2 後續；005F 與結果 0022 不是相同 body。

## 3. 真正重新核對的 S2C 0022/type0 native chain

SceneManager 第一層 application command0x22 表入口 0x4B7DC0 → 0x4B9770（T14/T07 既存；本輪重核函式內指令）。原始 .text：
~~~asm
4B9798 8B 45 08                 mov eax,[ebp+8]
4B979B 0F BE 40 02              movsx eax,byte [eax+2]     ; signed decision type
4B979F 83 F8 07                 cmp eax,7
4B97A2 0F 87 C4 01 00 00        ja 4B996C
4B97A8 FF 24 85 94 99 4B 00    jmp [eax*4+4B9994]
; TYPE 0 only:
4B97AF 68 04 61 00 00           push 0x6104
4B97B4 E8 AF 7A 3D 00           call 891268
4B97CC E8 5F 06 00 00           call 4B9E30
4B97D1 C7 06 74 73 C0 00        mov [esi],0xC07374
4B97D7 C7 05 74 A6 D6 00 44 45 43 53
                                mov [D6A674],0x53434544  ; SCED, decision scene
4B97F0 E8 5B E5 FF FF           call 4B7D50                ; install/replace scene
4B97FB 8B 17                    mov edx,[edi]
4B97FD 8B 52 38                 mov edx,[edx+0x38]
4B9808 FF D2                    call edx                   ; type0 v+38 → 4C4550
~~~
**TYPE0 是結果場景子類別**，不是勝敗 enum。0x4C43B0 初始化該場景、整理過場/Checkpoint 與 UI state8；不能將其內部 EmptyController ready 當成 Field19 actor ready。TUTO004C、一般 0022/type0、MissionDecision 0022/type2 與 Raid type9 不是共用的結果 schema。

### 3.1 ScenarioDecision type0 app payload 欄位表（offset 從 decoded app 開始）

| Offset | Native Source / type | 消費者與結果 store | 本次可以實作/不可猜 |
| --- | --- | --- | --- |
| +0..1 | uint16LE command 0x0022 | SceneManager dispatcher | 已知 opcode |
| +2 | signed byte，**必須 0 才進 normal type0 handler** | 4C4580 比較 | 不是勝敗結果 |
| +3 | byte；本局部沒有正向讀取 | 未確認 | UNKNOWN，不命名 reserved |
| +4..7 | uint32LE | resultStore+0x24 (4C45DA/DD) | 值原樣；其中 byte+4 zero/nonzero 影響 UI，不能整個 DWORD 當 bool |
| +8..11 | uint32LE | resultStore+0x28 (4C45E0/E3) | 原樣；**byte+9** 後續影響返回頁 UI 分岔 |
| +12..15 | uint32LE | resultStore+0x2C (4C45E6/E9) | 原樣，業務名 UNKNOWN |
| +16..19 | uint32LE | resultStore+0x30 (4C45EC/EF) | 原樣，業務名 UNKNOWN |
| +20..21 | uint16LE | resultStore+0x34 (4C45F2/F6) | 原樣，業務名 UNKNOWN |
| +22..尾端 | 此 handler 未見此段獨立讀取 | UNKNOWN | **不能宣稱原版完整 app payload 只有22B** |

因此**已核原生至少讀到 offset+21，最小已讀前綴22B**；沒有官方完整 wire length／signed status enum／結果交易定義。正常 handler 指令：
~~~asm
4C4580 80 7E 02 00       cmp byte [esi+2],0
4C4584 74 4F             je 4C45D5
4C45D5 A1 F8 18 FE 00    mov eax,[FE18F8]
4C45DA 8B 4E 04          mov ecx,[esi+4]
4C45DD 89 48 24          mov [eax+24h],ecx
4C45E0 8B 56 08          mov edx,[esi+8]
4C45E3 89 50 28          mov [eax+28h],edx
4C45E6 8B 4E 0C          mov ecx,[esi+0Ch]
4C45E9 89 48 2C          mov [eax+2Ch],ecx
4C45EC 8B 56 10          mov edx,[esi+10h]
4C45EF 89 50 30          mov [eax+30h],edx
4C45F2 66 8B 4E 14       mov cx,[esi+14h]
4C45F6 66 89 48 34       mov [eax+34h],cx
4C462F 68 97 42 0F 00    push F4297h              ; local UI event
4C4634 E8 97 64 0C 00    call 58AAD0
4C463E 38 56 04          cmp [esi+4],dl           ; DL=0 at this point
4C4643 0F 94 C2          sete dl
4C4647 E8 74 62 FF FF    call 4BA8C0              ; result presentation
~~~
T14 WP03 另證 local 0x6BA624 依 resultStore+0x24 低 BYTE 的零／非零選 UI 字串索引0x159/0x15A；**本輪不將其命名為勝/敗**，也不把本地 UI 畫面當成任務 DB 已持久化。

## 4. 由 S2C22 的 +9 byte 追到正常 C2S0033 返回的精確資料流

同一個有效 resultStore 未經其它 Writer 覆寫時：
- 原生 4C45E0/4C45E3：S2C22 app+8..11 → resultStore+0x28..0x2B；
- 原生 6BA336：讀 resultStore+0x29，**即 app+9**；包成 F431F local event payload；
- 原生 5AAEB2：F431F event+0x14 非0走角色資訊 UI（非本分支 C2S33）；若0，才走 5AAEEA 的發送分支；
- 原生 5AAF0A：全域 FBA798==0 時才呼叫 manager.vtable+0x10，slot0，**2-byte** app opcode0x0033。

~~~asm
6BA2E6 81 7A 10 78 05 00 00 cmp dword [uiEvent+10h],0x578
6BA2EF 8B 81 0C 01 00 00    mov eax,[owner+10Ch]
6BA2F5 8B 40 20             mov eax,[eax+20h]
6BA2F8 39 42 08             cmp [uiEvent+8],eax       ; exact widget gate
6BA2FD 8B 35 F8 18 FE 00    mov esi,[FE18F8]
6BA336 0F B6 4E 29          movzx ecx,byte [esi+29h]
6BA33A 51                   push ecx
6BA33B 68 1F 43 0F 00       push F431Fh               ; local UI event
6BA340 E8 3B 08 ED FF       call 58AB80
5AAEA9 81 7F 10 1F 43 0F 00 cmp dword [event+10h],F431Fh
5AAEB2 83 7F 14 00          cmp dword [event+14h],0
5AAEB6 74 32                je 5AAEEA
5AAED2 E8 39 44 11 00       call 6BF310              ; other UI, no 33 here
5AAF0A 83 3D 98 A7 FB 00 00 cmp dword [FBA798],0
5AAF11 BA 33 00 00 00       mov edx,0x33
5AAF16 66 89 55 0A          mov word [ebp+0Ah],dx
5AAF1A 75 15                jne 5AAF31
5AAF1C 8B 0D 54 A8 FB 00    mov ecx,[FBA854]
5AAF24 8B 40 10             mov eax,[eax+10h]
5AAF27 6A 02                push 2
5AAF29 8D 55 0A             lea edx,[ebp+0Ah]
5AAF2C 52                   push edx
5AAF2D 6A 00                push 0
5AAF2F FF D0                call eax                  ; local enqueue, NOT WSASend completion
~~~

**C2S33 有界協定**：app bytes hex **33 00**，長度2，slot/key0。本 builder 沒有 map ID、town ID、Quest ID、Case ID、return destination、retry bit、result confirmation 或 reward identifier。其它 UI producer 4A38D0 與 6BF2A0 的 mode gate 另由 T14 記錄，不能把本分支當所有情境唯一返回。

## 5. Server 契約、未解欄位及採用門檻

| Server-facing interface | Client native／pinned 可確認 | Server 自行決策／NOT PROVEN |
| --- | --- | --- |
| ScenarioCatalog | Quest15、field19、Case103、Chart node1→2 maps191/192 | 原版 Case preload key/opaque 004E/0028 token layout與實際回填 |
| Formation/Entry | 005F/type2 與一般場景 handler 已在其它 Task 存限定研究 | 004E、0028、005F、0038/0012/0014 每欄位及完整正常依賴順序尚 U，不能憑空發 native |
| OutcomePayloadType0 | 0022/type0 消費者可證至少22B app prefix；+4/+9 UI 分支 | 官方勝敗 enum、完整長度、獎勵、kill/window/timeout 判定皆 U |
| ReturnRequested | 結果 UI zero branch 的 C2S33 兩 bytes，slot0 | Server 可持有 ResultAwaitReturn phase、scene/party/Quest/return target 作權威；**此為設計而非官服已證** |
| Quest15/Town | T16 Quest15/Demand16；Town1 map182；SceneList (15,3) 獨立 | Quest15 完成、reward、Scene3 播放、進村合法時序/出生點 U，不能由33自動推出 |

此首批**可直接交 Server 開發的是 typed 資源 catalog、結果 DTO 的有界欄位模型、C2S33 返回意圖模型與 Server-side phase 設計候選**；未完成前置 packet schema 的 Field19 native entry 仍需後續 BIN-first，保持 fail closed。收到 33 只代表在限定 UI gate 下的返回意圖，真正地圖、actor ready 和 Quest 紀錄仍須獨立事件/狀態與驗證。

**四類缺口**：
- Client 待逆向：004E/0028 token、005F/type2、0038 type2/6、0012/0014/actor binder，map node1→2 trigger、結果其他尾端/語義及回圖 scene opcode。
- Server 待開發：持有 Quest/Case/ScenarioSession/party/return destination 不同 domain、合法結果與任務完成政策、結算/持久化/合法坐標，沒有本次 C2S33 的目標字段。
- 跨 Task 待整合：T07 scene owner、T14 result、T16 Quest15 scene、T02 socket/framing、T08 actor/ready，T01 驗證後 S00 採用；AI/MEF/連擊由 S00 自行處理。
- 待玩家授權遊玩驗收：Field19 真入場、Node191→192、結果 UI zero branch、C2S33 收包、合法村莊/Scene(15,3) 接續。本次全未執行。

**限定重現**：同批工具 kr-extra-roy/tools/w2_field19_result_native_audit.py 用標準庫核對原件SHA/PE及原生指令前綴。機讀相依與 UNKNOWN 使用 kr-extra-roy/W2-FIELD19-RESULT-01.json。抽查 PASS 只是本限定報告的原生位元組補證；**全文 FULL-PASS、S00 APPROVED、Server 實作與可玩驗收均不能由此推得。**

## 6. 首批後續待做（不在本次範圍）
下一批才定向研究：004E/0028 token 真正欄位／owner、005F/type2/0038/0012/0014 時序、node1→2 native trigger、15/3 场景接續，然後查村內 Field17/26/27/28。對於新證據保留 T14/T07/T16 原稿及 owner，不新增平行 RR 或自行通知別的對話。
