# Phase B — 第一批 KR T02/T03 可實作的有限契約

日期 2026-10-29。此階段成果在獨立工作分支，尚未合併 main。**沒有完整 Server 相容性或實際 Client 執行驗證**，也沒有重新做 BIN FULL-PASS。

## 交付

- 來源 `SRC-0001..0003`：精確 Git blob SHA、SHA256、KR SHA，對應 T02 framing、T03 roster 與 T03 authentication。
- `CLM-NET-0001..0004`、`CLM-CHAR-0001..0002`、`CLM-AUTH-0001..0002`，合計 8 條 bounded PARTIAL 主張，均非 NATIVE_VERIFIED。
- `SPEC-NET-0001`、`SPEC-CHAR-0001`、`SPEC-AUTH-0001` 三份有限 DRAFT 規格。
- `GAP-NET-0001`、`GAP-CHAR-0001`、`GAP-AUTH-0001`，3 項仍 OPEN；`RR-0001..0003` 仍 PENDING。
- 4 個 TEST-ID 的離線測試，涵蓋 Network frame、Character roster 幾何及 E8/000F 認證 payload。資料全部是手工合成，沒有任何 Client 封包捕獲。
- `governance/validate_s00.py` 防止無來源 lineage、缺失 fixture、跨版本與未滿足門檻的 STABLE 升格。這是**機械檢查**，不能認證原生語義。

## 已解釋的關鍵限制

- 本地 sender 1A68 payload 最大 4092、0BBB 最大 4090；receiver 對完整 payload 長度判斷最高 4096。
- 非零 mode 先做 0BBB，但失敗可能 fallback 1A68；不能把靜態預設分支當成唯一 wire 格式。
- 原生 receiver 的未知 marker 使用預設 header4 分支；離線測試器採保守不支援，不等價於 native rejection。
- T16-70 舊報告已受 T01 退回；1A68 marker / length bytes 順序必依修正過的 T02 限定研究。
- command2 roster 65+53*N 的幾何不證明 65-byte prefix 的完整業務含義、角色合法 ID 政策或選角成功。
- E8/000F 兩個 Client auth builder 的本地 payload 不證明原版 Server 的驗證、加密儲存或 session/token 政策。

## 下一步研究阻塞（以最先能完成端到端 Server 契約者優先）

`RR-0001`：確認 mode/連線關係、0x2633/0x22D7、收端 dispatcher 與真實 socket 邊界。  
`RR-0002`：確認 command2 完整 header、角色初始化回覆鏈、選角請求與成功/失敗回覆及 T04/T05/T06 前置。  
`RR-0003`：確認 E8 opaque tail、codepage、0x13 回覆長度/狀態、選服/切線。

下一輪優先使一個 Server-facing 收發流程達到可獨立實作的完整程度，再用與逆向隔離的 Agent 只閱讀 `spec/` 與 `conformance/` 來驗證是否足夠。

## 再現

```powershell
python -B governance/validate_s00.py
python -B -m unittest discover -s governance/tests -v
python -B -m unittest discover -s conformance/protocol -p "test_*.py" -v
python -B -m unittest discover -s conformance/character -p "test_*.py" -v
python -B -m unittest discover -s conformance/session -p "test_*.py" -v
```

CI 是離線規格與 SHA 自動檢查，**不能直接推論 Client 相容或 Server 可啟動**。

## T02 第二輪：收發／連線邊界既有研究整合（2026-10-29）

本輪未使用 REA 或重做 BIN 深度逆向，從現有 T02、T09 與 T01 T16 勘誤中核對可引用的 bounded 靜態研究，完成：

1. [來源盤點](../spec/protocol/T02-EVIDENCE-INVENTORY.md)：證據路徑、Git blob SHA、T16-69/70/71 更正及過期缺口的精確整理。
2. [SPEC-NET-0002](../spec/protocol/SPEC-NET-0002.md)：KR `806AD0` 的連線槽、三條已知 port+slot+pipeline 呼叫、C2S→WSASend 邊界。
3. [SPEC-NET-0003](../spec/protocol/SPEC-NET-0003.md)：WSARecv/IOCP→frame→queue→CClient `4930E0`→Scene dispatch 邊界。
4. [狀態模型](../spec/protocol/t02-network-state-model.md)：只有有界 Client 路徑，分離 Connect/slot/pipeline/frame mode/業務 Session；未臆造端到端時序。
5. 新增三份 SHA 綁定來源、四條 PARTIAL 主張；新增 `GAP-NET-0002/0003` 並收窄既有 `GAP-NET-0001`，研究請求精準化至 `RR-0004..0007`。
6. 新增 `TEST-NET-0003` 為**靜態映射一致性**離線測試，並非對原版 Client 的實際網路相容驗證。

**重要修正：**「WSASend 找不到」「完整命令分派未知」等舊結論已有較新來源補足限定的靜態路徑。仍無完整 `0x13` 回覆→選服/切線、首次 S2C frame、0x2633 與錯誤恢復的契約。桌面 Agent 應只補這些 GAP，而不是重做已定位的收發函式。

[REA/無 REA Agent 精確交接請求](T02-S00-AGENT-REQUESTS.md)。研究請求已建立但**未實際派遣 Agent**；完整 T02/T03 相容性規格尚未完成，所有規格仍維持 DRAFT/PARTIAL。

## T03 第三輪：extra/roy1 來源導入與登入→選角→場景依賴（2026-10-29）

已將 `extra/roy1@44a610968a228d4104e39457891e4fc565a3790c` 中 E01–E16 **16 份原稿 Git blob 原樣保存至本分支**，不合併其他歷史、不中斷原本 T03 研究主責；T01 FULL-PASS 仍需後續獨立審核。

從 E06/E08/E13/E16 **選擇性**登記 SRC-0007..0010（4 份）及 CLM-SCENE-0001..0004（4 條，PARTIAL）。E14/E15 是同一條 Lua loader 研究的必要更正與反證，不能只引用早期 E13 描述。

新增 [SPEC-FLOW-0001](../spec/session-account/SPEC-FLOW-0001.md) 將 E8/0F 認證、登入結果、三條 KR 靜態 Connect、command2 roster、C2S command42 與資源場景依賴並排記錄，但**沒有**推定這些步驟的完整 packet trace。新增 [SPEC-SCENE-0001](../spec/world/SPEC-SCENE-0001.md) 記錄場景雙鍵/seq path 與 E16 `EndCutScene` 重用同一 scene 入口的關鍵反證。新增 GAP-FLOW-0001 / GAP-SCENE-0001 及 RR-0008，下一階段重點是選角回覆的真正 S2C handler 與 scene key writer，而非重做全部 STP/Lua 解析。

本輪只做**來源與規格整合**，沒有重新執行 Client、沒有 REA/BIN 原生深度驗收、沒有 Server 網路相容性測試，也沒有宣稱 `1001/1` 是選角 S2C 欄位。所有新規格保持 DRAFT / PARTIAL。詳見 [交付報告](PHASE-B-T03-EXTRA-ROY1.md) 和 [Agent 任務規格](T03-S00-AGENT-REQUESTS.md)。
