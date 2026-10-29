# T02 → S00：KR 網路收發、連線與分派的既有研究盤點

日期：2026-10-29。**證據導航與衝突對照，非新的 BIN 原生語意驗收。** Client KR SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；不適用 TC。

## 重點結論：不再重跑已知的共用路徑

| 面向 | 已存在的有限證據 | 能寫成 S00 的局部契約 | 還不能宣稱 |
|---|---|---|---|
| Socket 建立 | `806AD0` 使用 TCP socket、connect；第三參數指定 slot，第四參數 A080 pipeline | 已觀察的 Connect 參數、slot 與 pipeline 分離 | 官方端點仍可連、所有連線來源已窮盡 |
| 出站 | `8069A0→8060D0→806060→8061A0→804A40→8068B0→WSASend` | 有條件的資料經本地佇列、framer、Winsock API | Server 已實收／ACK、每次 OS 實際發包次數 |
| Framing | `807A70` 1A68、`807830` 0BBB、`8061A0` mode/fallback | 有界 local codec & 本地 ring guards | 每個階段唯一的 wire mode、所有例外處理 |
| 入站 | `WSARecv/IOCP→807B40→8040A0→804740→4930E0` | 有界 frame→queue→callback 資料交付 | 所有失敗路徑與資料池生命週期已完整 |
| Dispatcher | `4930E0` 讀 payload 首 WORD，`channel==2` 下分派；CClient、Scene tables | 命令分派發生於去除 frame header 後；分派與 wire marker 區分 | 每個命令/狀態均有完整業務回應 |
| 關閉 | `806FC0` 的 shutdown/close 分支與清理 | 具備原生關閉 API 邊界 | Server 重試政策、優雅登出語意及所有錯誤分支 |

## 來源版本及風險（從本庫內容與 Git Blob 查得）

- **E-T02-FRAME**：`kr/evidence/f398779b1e129b0150f009451dc72b51b1cb9b88e9f2aa5c43b4eeeac02e0e94.txt`，Git blob `f6686819dc993c2afa3d8c159d23a94a1125f9ff`。既有 `SRC-0001`；`CLM-NET-0001..0004`；有界靜態 framing 核對。此處不另升級 FULL-PASS。
- **E-T02-SEND**：`kr/evidence/1e15689d7bbdf4c4a83ae76cf1813d538b8cb38db79098c6b85ba386056dab36.txt`，Git blob `3710f1360acbac739247ffd9cbdb8cee054349c4`；有界戰鬥輸入→WSASend 靜態路徑，其他流量不保證相同時序。
- **E-T02-RECV**：`kr/evidence/4a64b51809c87fe6c8bab24f033fb4c94964a8e403e861be22e8210d3f639b8e.txt`，Git blob `0785af3af4df4b11912037504382a26bd026ba8c`；有界 WSARecv/IOCP→frame→queue→CClient/Scene 解析。
- **E-T02-ROLE**：`kr/evidence/bcc93c2f8128b12d86fd1e296198e4e1735fd410336510b15c58415b6a0c9ced.txt`，Git blob `1733907a4685ff40894b81fb84992867c7ea1796`；Connect 參數與三條已查的 KR 呼叫路徑。
- **補充原稿（非正式 CLM 依據）**：`kr-temp-roy/20261026-074628-claude-web-roy-T09-T02-frame-mode-A02C-and-recv-parser-807B40.md`，Git blob `24fa8ab962bdbfd5283bb99b614cdf47b0c56b01`；在限定 `+A02C` 直接存取掃描中，`805D02` 初始化寫入 2，未找到其他直接寫入。**其他間接寫入沒有被排除**。
- **較新相互核對**：`shared/integrations/T01-20261029-continuation-02/t16/README.md` 記錄 T16-69/70/71 的精確退回與有限仍成立主張；T16-70/71 仍 FAILED，不能整篇引用為正確來源。

## 衝突與修訂優先表

| 衝突來源 | S00 目前採用／保留的處理 |
|---|---|
| 部分 T16-70 標題把 1A68 header word 顛倒 | **[length16, marker16]**，依 T02 精確 framer 審核；T01 指出標題錯誤 |
| T16-70 把 connection/stream buffer 基底混淆 | 不把 `obj+5004/+500C` 直接寫成 `conn+5004/+500C`；若需 offset 使用精確 object-base 標記，T01 勘誤優先 |
| T16-71 原稿的 vtable bytes、WSABUF/OVERLAPPED push 地址錯配 | 僅採用與 T01 有界審核相容的靜態鏈；不搬運錯誤 literal |
| T16-69 把 A0A4 直接稱為 queue count | A078 才是 list size；A0A4 的具體語意仍未知 |
| 舊 frame mode 原稿稱非零「一定」使用 0BBB | T02 後續審核顯示 0BBB 失敗可回退 1A68；不宣告唯一出站模式 |
| `login_protocol.py` 過度拒絕未知 marker 與 4091–4096 | 是 AI/local 實作政策，不可替代原生 receiver 的 4096 payload 上限與預設 marker 分支 |
| 較早 T09 報告宣稱完整 dispatch 未知 | 後續 `kr/evidence/4a64…` 與 `kr-temp-roy/20261026-110120-…recv-dispatch-chain-….md` 補上 bounded 分派；不要沿用舊的空白結論 |

## 開發者關心的證據邊界

1. 連線 port 是**舊 KR Client 靜態常數**，不等同現行官方連線端點；Server 的部署 port/host 必須與獨立開發環境及合法 Client 連接方式分開規定。
2. `slot` 是 outbound connection key；`pipeline` 是 inbound queue class；`command` 是去 frame 後 payload 首 WORD；`actor` 是業務欄位。四者不可互作 ID。
3. 這一輪不需要新 REA 就能修正「WSASend 尚未定位／完整 dispatcher 尚未定位」等**過期缺口敘述**。尚需原生研究的是完整 login/choice handoff、error branches、mode 及某些 format。
4. 檢視本庫時，任何歷史「已驗證」僅依當時 bounded scope；本整合未把它轉為新 `NATIVE_VERIFIED`。

後續見 [連線契約](SPEC-NET-0002.md)、[入站分派契約](SPEC-NET-0003.md)、[狀態模型](t02-network-state-model.md)。
