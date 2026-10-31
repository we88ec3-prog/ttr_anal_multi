# S00 — RR-0009／RR-0010 創角研究審查與交接（2026-10-31）

> 基準 `main=ad1fda170734767c67dd0f62066a34ece34e118a`；本次為 S00 規格、RR 驗收與研究缺口整合，不修改原 Client、Server 程式或其他 Task 原稿，也沒有獨立重跑 KR BIN、遊玩驗收或 T01 全文複驗。

## 決議

| RR | 研究交件與來源 | S00 決議 | 功能／相容狀態 |
| --- | --- | --- | --- |
| RR-0009 | [T03 E70](../../kr-extra-roy/20261031-chatgpt-web-roy-E70-RR0009-empty-roster-GUI-blocker.md)，Git blob `ef778ac58ccdfd4013962b86a2aa33bf6f245d13` | **ACCEPTED 僅限明示的第5條：沒有 positive entry 時提交精確 blocker**。詳 [專項審查](../reviews/RR-0009-20261031-bounded-blocker-acceptance.md) | N=0 roster 只跳過 row，未證開可點擊創角 UI；GAP-CHAR-0002 OPEN |
| RR-0010 | [T03 E71](../../kr-extra-roy/20261031-010931-chatgpt-web-roy-E71-RR0010-create-C2S-candidates-S2C-roster-blocker.md)，Git blob `57f809809e28d24cd9779549d95e9b269db4870b`；[S00 E71–E74 審查](S00-20261031-RR0010-EXTRA-ROY1-REVIEW.md) | **BLOCKED 不變**；無正式 SUBMITTED 報告可由 S00 結案 | GAP-CHAR-0003 OPEN，真 playable character create→result→roster 未閉合 |

## 可以沿用的局部研究，不能跨越的斷點

1. E70：`S2C app2` payload `65+53N` 中，N=0 分支由 `0x4B894C` 跳至 `0x4B8A20`；N>0 可能 `0x4D4150` 寫入 record `+0x5C`。RTTI `CEmployNewCharacter`、`0x5AB020/0x5AB280` cache、`0x5C30FD/5C316A` UI owner、`0x65D550` 本地事件均有來源，**無已證 N0→scene listener→control enabled/visible→dialog open**。本地 `F42EF/F4246/F4247/F4278`、`0x665150` detail hit 不是 wire 也不是正向開窗。
2. E71：`CEmployNewCharacter` event `0x578` 有條件產生 C2S `0x0033` 2B，但不攜帶角色姓名或外觀，不能視為建立可操作角色的 wire。
3. E73–E74：`CExpeditionCreateDialog` 有條件建立**遠征隊名稱** C2S `0x003E` 48B、slot0、UTF-16 名字自 +6，+2..5 UNKNOWN；LOGIN scene 另有 S2C `0x004A` result → local `F4245`／name UI。原版 Server 是否回 `0x004A` 作 `0x003E` 的 ACK，**未證**；更不能等同 playable-role creation。
4. E79：`S2C app2` full `65+53N` 與 `app2B` delta `2+53N` 都寫相同 `F94304` role array；無已證這些消息是創角成功後的固定順序。C2S `0x0042` 為選取既有角色，非創角。E77 `S2C0xB6→F4278` 只作有條件 UI 更新。
5. 所有 E70/E71/E73/E74/E79 只沿同版原作者來源與 S00 先前限定交叉核對使用；此次 S00 未實際執行原版 Client 或原版 Server 抓包，不是 T01 FULL-PASS。凡原版 Server 的成功碼、回覆順序、重名/拒絕、角色初值均不可猜值。

## 下一步責任（不複製 RR）

- **GAP-CHAR-0002，T03/T06**：先針對 N0-postprocessing `0x4B8A20`／`0x4E5FB0` 狀態 writer 的真正 consumer/xref、scene event listener、UI control identity/visible-enabling、相同 KR GUI resource 與缺資源反例繼續靜態調查。RR-0009 的限定 blocker 交付已接受，**缺口尚未解決**；新正向研究若需要正式派工，S00 先依唯一台帳去重定義。
- **GAP-CHAR-0003，T03（T02/T04 協作）**：定位真 playable-role create 的 UI producer→C2S builder→queue、對應 S2C success/reject consumer、roster full/delta 初始化與重試。靜態可追分支不能只因缺原服就停止；在原生證據解除阻塞後，S00 才能依 `BLOCKED→QUEUED` 正式重新派工 RR-0010，而非替 T03 建立假的 `SUBMITTED`。
- **Server 開發**：帳號、遠征隊身分、角色資料分離；可先做 mock-side 交易、重送/重名/斷線測試；**原版 KR native adapter OFF**，不以合成 fixture 宣稱可玩。
- **審核分層**：S00 limited RR acceptance、T01 原生嚴格審核、GAP CLOSED、SPEC STABLE、正式 TEST、Server 開發、原版 Client runtime 各自獨立。此輪仍 `GAP-CHAR-0002/0003 OPEN`、`SPEC-CHAR-0001/SPEC-FLOW-0001 DRAFT/PARTIAL`、只有原有 OFFLINE_SYNTHETIC 正式 TEST。沒有修改 T03 舊 T01 NEEDS_FIX。

## Server-facing 決策

不得以 `0x33`、`0x3E`、`0x4A`、`0x42` 或 `0x2/0x2B` 串成原服必然建角流程；缺 direction/frame/slot/scene/回覆與 UI 正證前，不能編製必須遵守的 create wire contract。未經另行授權不啟動原版 Client。
