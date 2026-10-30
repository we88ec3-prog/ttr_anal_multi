# Iteration 23 — Expedition 名稱/FullRoster/Delta/UI 驗收矩陣（計畫）

**這是 S00 設計測試，24 項全部 `PLAN_ONLY / NOT_RUN`**；編號 `I23-Txx` **不是**正式 `conformance/test-index.json` 的原生 TEST ID；只有合成 DTO/domain/unit test 才能在 Server 開發前期執行。KR 原始 BIN/Client、原版 Server 真實交易、slot/frame/native playback 均未在本輪執行。測試的 `expected` 是**Server V1 採行時的安全建議**，**不代表原版 Client 的既定錯誤或 Server 協定政策**。

| ID | 測試模式 | 輸入/觸發 | 預期與不能聲稱的事 |
| --- | --- | --- | --- |
| I23-T01 | DOMAIN | WEB 管理新建只有 AccountId 的帳號 | ExpeditionName 未設定、Roster empty；不能自動標 playable角色已建立 |
| I23-T02 | DOMAIN | Expedition 取合法 UTF-16 姓名 | Server-owned policy 通過才原子保存，name revision +1；不代表 KR Client 已顯示 |
| I23-T03 | DOMAIN | 同一命名請求重送/超時 retry | 冪等鍵或已存在 identity 唯一判定；不雙建、資料庫一致 |
| I23-T04 | DOMAIN | 同時兩請求競爭相同 Expedition name | 一個成功/其餘衝突（自訂政策）；不硬映射為原版 status -1 |
| I23-T05 | DOMAIN | 名稱含空字串/不合政策控制字元/缺 NUL | 安全拒絕並可重新輸入；不得宣稱 KR Client 所有錯誤碼相同 |
| I23-T06 | STATIC PLAN | C2S app3E inner length 48、opcode3E LE、name+6 | codec 文檔比對原始 E73/E78；來源缺 BIN 時標 NEEDS_NATIVE_RERUN，wire adapter 不啟用 |
| I23-T07 | STATIC PLAN | C2S app3E 位移 +2..+5 用不一樣的 4 bytes | 保留為 UNKNOWN/opaque，不依其值配對帳號；**不可默認它全是0** |
| I23-T08 | NEGATIVE | 名稱長過 21 WCHAR 目的容量、UTF-16 截斷或 surrogate 損毀 | Server 自訂驗證拒絕；原 Client helper 可能清空首 WCHAR 且 caller 未檢查回傳 |
| I23-T09 | STATIC PLAN | 有效 LOGIN/EXPD scene 收到 S2C app4A、signed16 status +2=1 | 本地 F4245/NameReady 可達的條件式路徑；不宣稱原版 3E→4A pair |
| I23-T10 | STATIC PLAN | app4A result=-1/-2/-3/default | 各有 Client 本地分支，不自動對應 duplicate/滿額/網路失敗等官方語意 |
| I23-T11 | STATIC PLAN | app4A 的本地結果非1 | 不走 E76 這條 NameReady + 三個控制啟用分支；不推論不可能由其他 sender ready |
| I23-T12 | DOMAIN | FullRosterSnapshot 0 個角色 | domain 保留 0 role；若要編 app2，仍須合成完整 65B header，不能拿2-byte清單代替 |
| I23-T13 | DOMAIN | FullRosterSnapshot 1/10 個角色 | 以 slot/revision 對齊同一角色資料源；invalid/duplicate/out-of-range rejected before encoding |
| I23-T14 | STATIC PLAN | app2 header name+0x0C | Client 可寫 F938F2；name header 在 row-count length gate 之前被讀，不能稱短包安全 |
| I23-T15 | STATIC PLAN | app2 65+53N，slot <=9，UTF-16 row NUL | record writer 可將可用旗標 +0x5C 設1；無此證據時不可擅造其他字段的值 |
| I23-T16 | DOMAIN | ApplyRosterDelta 0/1/N 個完整 53B record | 與 full 使用同一 RoleStore/slot，版本序列化，N=0 no-op 於 domain；**不等於原版 2B no-op UI** |
| I23-T17 | STATIC PLAN | S2C app2B 2+53N vs app2 65+53N | 兩者**不同 header 長度**，不能共用 off-by-63 錯誤解析器，完整 row 從 app2B+2 |
| I23-T18 | STATIC PLAN | E79 app2B network callback index2B / singleton / handler | 需要符合 network dispatch/scene/owner 前提；命中同一 `F94304` pointer cell，不是簡單靠 opcode 推論 |
| I23-T19 | DOMAIN | 先 full→delta，再 delta→full，且 revision 不同 | Server 自訂 revision/CAS 決策明確；Client 原生未證 out-of-order replay policy，測試不得說它原生拒絕 |
| I23-T20 | NEGATIVE | 不滿 53B row、超過 slot上界、無終止的 53B name | Safe **Server encoder** fail closed；不把 Client native memcpy 當完整越界保護 |
| I23-T21 | STATIC PLAN | S2C appB6 到 F4278(0) 的事件 | 有條件 Expedition Page 角色 UI/placeholder branch；B6 handler 不讀角色 idx payload，不對應任何官方建角 ACK |
| I23-T22 | STATIC PLAN | F4278 由 CPhaseSlot 發出／F4261 由其他元件發出 | UI 本地 event namespace **非單源**；防止把任何 event 當作 Server network command |
| I23-T23 | DOMAIN | 角色新增→選角→入世界之前 | NameReady、RosterHydrated、RoleUiReady、RoleSelected 是分離 gate；B6 不單獨開放 world，C2S0x42 pairing 仍阻塞 |
| I23-T24 | E2E PLAN | 實際 KR Client 0/1/10角色、同名建名、N0視窗、重登、2B/B6的到達順序 | **另須使用者授權隔離實機測試**；合成 Server 測得的相容性 ≠ 官方 Server 真實歷史行為 |

## 對實作者的 fail-closed 防線

- **原生封包 encoder 預設關閉**：在 T02 確認 connection/frame/admission 和 T03/T04 提供明確欄位/場景前，只能做 Domain DTO 及無副作用 parser/合成向量。若設計中的資訊不足以初始化 65B header 或 53B record，**不要發送猜測包來「驗收成功」**。
- **兩個來源、一個 record array**：Full `0x2` 和 incremental `0x2B` 使用同一個 Server domain 的 RoleRecord 權威模型。這是 E79 造成的實質設計改動；不可因兩個 Client handler 不同就維護兩個彼此不一致的 DB 名單。
- **事件不是封包**：`F4244/F4245/F4261/F4278` 僅本地 event；S2C0xB6/0x4A 的可達性依 scene。保留負面／空資料路徑。
- **名稱 ≠ 角色建立**：Admin WEB 建帳 `REQ-0007` 只建立玩家 Account；Expedition name V1 與 playable role availability 是兩種模型；沒有原版 Server 成功配對就不能宣稱 RR-0010 ACCEPTED。

## 對測試證據等級的記錄規範

每項日後執行需在 Server repo 保存：`run_id`、commit SHA、資料集 hash、scenario ID、preconditions、actual、expected、evidence_level（DOMAIN_SYNTHETIC / ORIGINAL_BIN_STATIC / COMPAT_CLIENT_RUNTIME / ORIGINAL_SERVER_CAPTURE）、pass/fail、未解項。不得使用本文件的 `PLAN_ONLY` 編號冒充已存在原生 TEST。更不能因 Domain test PASS 就將 T01 full pass 或 S00 SPEC maturity 提升。
