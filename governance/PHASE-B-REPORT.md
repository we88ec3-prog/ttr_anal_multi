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
