# W5 — 馮德斯角色、任務、獎勵：KR BIN-first 限定契約與待證封包

> 2026-11-02，Asia/Taipei，chatgpt-web roy；工作分支 extra/roy2。交付等級：**W5-PARTIAL**。本批確認 QuestState、Quest Reward metadata 與 Roster 更新接口；仍未能從可審證據閉合「招募成功」「獲得技能」「取得／穿戴裝備」及其保存／S2C 回覆，**不可宣稱 W5 全部完成**。不修改 Client、Server、既有研究／RR／APPROVED 或他人 owner；不執行／附加 Client，沒有負向、重放、重登、併發、故障、壓測或 live packet。T01 原生驗證與 S00 採用分開。

## 0. 第一手來源與引用界限

- 原始 KR Tartaros.bin：12,472,320 bytes，SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91，**本輪實際唯讀重算 PASS**。PE32 i386，ImageBase 0x400000，.text VA 0x401000/raw 0x400，text VA→raw = VA−0x400C00。
- 本輪唯讀 Table.stp 5,248,784 bytes SHA256 09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442；Event.stp SHA256 2e68e0202565530e574e0810ad7f758a2fc8d6826a0de0975ccaff12c2d4718b。未重新解包 XML member。
- RESOURCE-BASELINE.json pinned Git blob 5ac883881d3ab0c711ad7c0bdd84c4dd3c2e5cd6（QuestInfo.xml member 5d251415fdfdc453adefbff03114ded5a8ea41b696ce0aab86a23070e0fdca60）：下述 Q15～Q133 和 raw reward 值來自此 pinned **資源**，不是 runtime Server 結算。
- 核對既有主責原稿：T16-125 blob 983535d340331f03ca1e253bc1d73e26bb08dd8f（Quest reward parser）、T16-128 blob bddbc8f94c32a3a69a43537be0631f7be3cb9a79（0x46/0x6F/cache）、T16-135 blob b0a15aaabe1fc2d86225c5d5466b6ab78564c29c（Quest 14→16→15 到村）；T03-E W17～W20 的 role-store 报告，在 t03/roy/chatgpt-web 分支 blob 5bf17fd8078344bb41a26e8de956b2ec23843731；E81 blob 7fea46f8803d67e8d63c281f448515c37a521796（EmployNewCharacter 本地事件不等於招募）。
- 本輪針對原件的 **33 個確切指令視窗＋6 個 reward jump-table DWORD** 進行離線正向核對 PASS；見本地 W5 native-audit 方法及下述原始 bytes。窄驗證不等於全文 T01 FULL-PASS。

## 1. 必須分開的狀態域

| Domain | 已有 Client 本地資料 | 不能混同 |
| --- | --- | --- |
| QuestDefinition | QuestInfo record（Demands、Accept/CompleteAction、RewardsEtc） | 不等於 Server QuestCompletion 或獎勵入帳 |
| QuestProgress | QuestOwner+0x5EB0/+0x5EB4 的 WORD prerequisite vector | 不等於 DB 保存或 QuestOwner+0x5ED0 20-slot exclusion |
| QuestAvailability | QuestOwner+0x5EC0 candidates、town selector FAB1BC、level、exclusion | mode2/mode3 UI 或播放 scene 不是下一任務已可接 |
| RoleRoster | S2C 0002、002B → RoleStore F94304，slot+0x5C flag | 不等於 recruit/create transaction 或技能裝備擁有權 |
| Skill/Equipment | 有 local skill reader，裝備初始資料尚有 T04 缺口 | 不能由 reward type 或 role row 猜 item/skill grant |
| Reward and persistence | Server 應獨立擁有結果、grant、角色快照及 transaction | 0x46 UI、Scenario22/0 或 C2S33 不等於 DB commit |

## 2. 村莊任務需求與 Raw Rewards（RESOURCE-BASELINE，非貨幣/EXP命名）

| QID | Town／Field | Demand | NPC giver | Reward type:value |
| ---: | --- | ---: | ---: | --- |
| 15 | 5／19 | 16 | 10338 | 2:2800、4:468 |
| 117 | 1／— | 15 | 10002 | 2:710 |
| 118 | 1／28 | 117 | 10047 | pinned rows 未列 |
| 119 | 1／26 | 118 | 10047 | 2:5850、3:40、4:900 |
| 120 | 1／— | 119 | 10008 | pinned rows 未列 |
| 121 | 1／— | 120 | 10002 | pinned rows 未列 |
| 122 | 1／27 | 121 | 10002 | 2:9686、3:40、4:918 |
| 123 | 1／— | 122 | 10048 | pinned rows 未列 |
| 124 | 1／17 | 123 | 10048 | 2:13086、3:40、4:1440 |
| 131 | 1／— | 124 | 10002 | pinned rows 未列 |
| 132 | 1／28 | 131 | 10002 | 2:15850、3:40、4:1440 |
| 133 | 2／21 | 132 | 10053 | 下一 Town 邊界 |

此鏈僅是 pinned 候選 Quest chain，不是官方任務完成排序。pinned 空 rewards 不表示任務沒有任何獎勵。不能由數字量級推測 type2 是 EXP、type3 是技能點、type4 是錢。

## 3. RewardsEtc 的原生 type→record offset：六個正向分支

0x504D96 將 Reward.type−1 作 index，0x504D99 驗 0..5，0x504D9E 從 native jump table 0x505554 跳到各自 Writer。直接從本輪 BIN 讀得：

| XML Reward.type | jump target | temp stack Writer | QuestRecord offset | 原生業務意義 |
| --- | --- | --- | --- | --- |
| 1 | 504DE2 | esp+E4 | +0x80 | UNKNOWN |
| **2** | **504DF4** | **esp+EC** | **+0x88** | UNKNOWN |
| 3 | 504DEB | esp+E8 | +0x84 | UNKNOWN |
| **4** | **504DFD** | **esp+E0** | **+0x7C** | UNKNOWN |
| 5 | 504E06 | esp+F0 | +0x8C | UNKNOWN |
| 6 | 504E0F | esp+F4 | +0x90 | UNKNOWN |

~~~asm
504D96 8D 4B FF              lea ecx,[ebx-1]
504D99 83 F9 05              cmp ecx,5
504D9E FF 24 8D 54 55 50 00 jmp [ecx*4+505554]
504DF4 89 84 24 EC 00 00 00 mov [esp+EC],eax ; type2
504DFD 89 84 24 E0 00 00 00 mov [esp+E0],eax ; type4
~~~

Record-copy 下游 0x506596..0x5065E6 見 T16-125（保留他人主責）；**這是 QuestInfo.xml 的本地資料載入，不是 Server 發獎、道具增加、技能學會的原生封包**。Q15 2800/468 資源值來自 pinned 基準，不是此組機器碼顯示的某次實際發放。

## 4. Client 需要的任務進度／下一 Quest 更新：訊息表

Offset 為 **decoded S2C application payload**，不是 TCP 外框或 C2S 同號事件。主責既有 T16-128、T16-135 與歷史 Quest native evidence；本輪只重核列出的原生關鍵指令。

| S2C | 已知最小欄位／handler | 本地效果與精確限制 |
| --- | --- | --- |
| 0x0040 | +2 QID(u16)，+4 state(u32)，至少8B；502270 | state0 插入 exclusion，F438B→mode2 TalkBox 等候選處理；**不是獎勵入帳** |
| 0x0045 | +2 QID(i16)，至少4B；5027D0 | 依 QuestInfo record CompleteAction type 分流到 controller 或通知；**不是 +5EB0 writer 的替代品** |
| **0x0046** | +2 QID(u16)、+4 substate(u16)，至少6B；502B40 | substate0 才走 5000D0 移除 exclusion；QuestRecord+8!=3 時 44B4E0 追加 prerequisite；500240 依當前 town 重建，F438C→mode3；其餘 substate 異路 |
| 0x0064 | +2 QID(u16)、+4 state(u32)，至少8B；5030C0 | state0 移除 exclusion＋重建，**不等於 0x46 追加 prerequisite** |
| 0x0065 | T16-123 有界 | 清 exclusion list，**不是清 prerequisite** |
| **0x006F** | payload 長度由呼叫處傳入，DWORD bitmask，自 +2 後按 T16-128 | **整組重建／替換** owner+5EB0 前置 keys；不能說是 append |
| 0x0072 | T16-123 有界 | prerequisite reset，與 0x0065 domain 不同 |
| **0x0074** | +2 u16 key，至少4B；503400 | 44B4E0 append prerequisite key，500240 立即依當前 town 重建；未見直接發獎 |
| 0x0038 | +2 subtype、+3 u16 town；subtype6 還讀 +7 u16 | town selector 同一 FAB1BC；subtype0/5 有立即 500240 重建；subtype6 此局部無立即重建 |

Native positives：

~~~asm
502DBA 83 7F 08 03          cmp dword [edi+8],3
502DD0 8D 45 DC             lea eax,[ebp-24]
502DD3 E8 08 87 F4 FF       call 44B4E0
502DE8 E8 53 D4 FF FF       call 500240
50340D 8D BE B0 5E 00 00   lea edi,[esi+5EB0]
503413 E8 C8 80 F4 FF       call 44B4E0
503425 E8 16 CE FF FF       call 500240
44AA53 BA 01 00 00 00       mov edx,1
500652 8B 50 24             mov edx,[eax+24]       ; Demand end
500690 0F B7 18             movzx ebx,word [eax]   ; Owner WORD key
5B6F61 6A 03                push 3                 ; mode3
~~~

**保證下一任務可顯示的 Server 交接（新 Server 策略，不宣稱官方流程）**：

1. Server 依 Quest/Scenario 合法結果與 DB 規則持久化 completed Quest15，且**獎勵／領取**另立交易帳本，不用 Client cutscene 代替。
2. 透過有原生來源的 S2C0x46 state0 條件分支、0x74(key15)、或含 bit15 的 0x6F snapshot，使 Client 的前置 key **15 存在**。0x6F 後送會覆寫先前增量；不得把 0x74 的 append 當作 durable DB。
3. 將 Client town selector 更新到 Q117 需要的 Town1，且**觸發 0x500240**；subtype6 writer 不會在已查局部自動重算。
4. Q117 level、20-slot exclusion、QuestInfo definition、giver10002、候選 first-match 仍各有 gate。若要 mode3→下一筆 mode1 對話，另須 0x500950 記錄 context/+4==1 與 0x5007D0 的 Demand 關係；不保證每筆對話自動串接。
5. Scene(15,3)、一般 Scenario22/type0、C2S33、S2C45 本地通知都**不能單獨**取代 prerequisite + town + rebuild 的流程。

## 5. 招募與角色名單：能顯示角色，不等於已證取得交易

T03-E W17/W18 已核有兩種對同一 RoleStore 的正向 S2C：

| 封包 | 已知原生欄位 | Reader→Store | 重要限制 |
| --- | --- | --- | --- |
| S2C app0x0002 full | 65B header，app+0x41 起每 53B role row；index=row+0x2E(u8,<=9) | 4B7F00→4B8920→4D4150；F94304+index*0x210，record+5C=1 | full 專用 per-row C2S26/3B、post C2S24/2B、mask F94240（須 manager/Conn gate）；**不是招募成功 ACK** |
| S2C app0x002B delta | 2B header，app+2 起每 53B role row，index=row+0x2E<=9 | 4E2730→4D4150；同 F94304 RoleStore | delta 沒有 full 的同一組 C2S26/24；**不能宣稱是 recruit request 的官方結果** |

~~~asm
4B8923 8B 4D 0C             mov ecx,[ebp+C]
4B8992 0F B6 07             movzx eax,byte[edi]   ; role index
4D4154 C7 46 5C 01 00 00 00 mov [esi+5C],1
4E2767 0F B6 47 2E          movzx eax,byte[edi+2E]
~~~

後續 UI 還要求 F4278／F42EF 等 local event、record+5C 與 widget/list-hit；角色可見不是 Server 授權、創角完成或招募交易。E81 的 F431F 同時被 CEmployNewCharacter UI 及結果頁返回分支使用；部分路徑送 **C2S33** 而非 recruit success。T03 E/ E81 與此 W5 的保守來源不能混成「招募一個角色就直接送 0x002B」。

## 6. 技能與裝備：原生 reader 與真正需要補的 writer

技能矩陣 consumer 0x61C7C0 根據 hero／matrix/角色物件組合操作。原件：
~~~asm
61C900 0F B7 74 4A 04       movzx esi,word [edx+ecx*2+4] 
61CA4A 8B 11                mov edx,[ecx]
61CA4C 8B 82 9C 01 00 00    mov eax,[edx+19C]
61CA52 6A 01 56 57 FF D0    push 1; push skillId; push role; call eax
~~~
**只能推到 Client 已有技能資料 reader/使用路徑**；沒有證實 skill grant C2S、S2C、學會的角色/技能欄位、持久化/重登初始技能快照、真 UI 取得效果。**不允許**直接將 Reward.type3 value40 當作技能點或新技能 ID。

裝備方面，T04 README 已註明能力/裝備初值未完全確認；T15 README 說明本機 SQLite 任務/道具及 profile 清理不能冒稱原版儲存。現有來源不足以填物品 instance、背包 slot、角色所有權、裝備位置、獲得和穿戴兩種不同交易的 C2S/S2C opcode，均須保留 **CLIENT_NATIVE_UNKNOWN**。

新 Server 可以先建（**自訂，不是 Client wire**）：RoleOwnership、SkillUnlock(characterId,skillId,revision)、InventoryItem(instanceId,itemDefId,count,owner)、EquipmentSlot(characterId,slot,itemInstanceId)、QuestRewardGrant(questId,claimId,sourceRevision) 等資料契約；但在 native packet schema 未經 T01 複驗前，**不能宣稱 Client 已收到新角色/技能/裝備**。

## 7. W5 限定交付／待補責任表

| W5 子項 | 已交付可用事實 | 尚未閉合／需誰定向補證 |
| --- | --- | --- |
| 招募／角色 | 0x0002 全量、0x002B 增量、53B row、RoleStore+5C/UI gate | 招募 action、授予/ownership 與真正 S2C grant pairing，T03/T04 |
| 技能取得 | 0x61C7C0 matrix reader 與 local object virtual 消費 | acquire/learn request、S2C grant、SkillStore writer、UI、初始技能載入，T11/T04/T15 |
| 裝備取得／穿戴 | 不把 Reward.type 與 Item 數據誤認 | inventory/equip parser、欄位、ItemStore/slot writer、UI/重載，T04/T15 |
| 任務保存 | 0x46/0x74/0x6F 影響 Client cache；town/重算 gate | Server DB completion、full restore sequence/Session，T15＋S00 |
| 獎勵類型 | type1..6 → QuestRecord +80/+88/+84/+7C/+8C/+90 | 具體官方金錢／EXP／道具／技能語意、實際給獎 S2C/資料 writer，T14/T16 |
| 下一任務 | Quest15→117 及 Q chain、可見性/狀態條件 | Town1/NPC scene 正常時序、Player live acceptance，S00/T01 後續 |

**研究判定：W5 現階段 PARTIAL。** 33 個 machine-code 確認及 6-entry 跳表只能證原件局部資料流，不是 whole-function FULL-PASS／S00 Approved／原版可玩或 Server 已實作。資料不夠時應交精確 Native blocker，不把 Client 未知冒稱 Server 自訂政策已解。原始 Client、Server、其他 Task 原稿與正式 RR 保持不動。

### 本輪重現範圍
本輪僅做原件 bytes/PE/6-entry jump table 唯讀確認，33/33 instruction windows、6/6 target PASS。核對地址：504D96/504D99/504D9E、504DE2/EB/F4/FD/504E06/0F、502DBA/DD0/DE8、503403/40D/413/425、5021A2/1D1、44AA53、500652/690、5B6E60/F61、4B8923/8992、4E2767、4D4154、4B89F7/8ADB、61C7C0/900/CA4A/CA52。這是唯讀確認，不涉及原版遊戲啟動、測試失敗/重播/壓測。
