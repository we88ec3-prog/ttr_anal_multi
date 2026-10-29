# SPEC-AUTH-0001 — KR Client 認證局部 payload 契約

**DRAFT / PARTIAL**｜KR SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。以下為 Client 本地 payload，不含 TCP framing。

| C2S command | 總長 | 兩個字串 slot | 其他欄位 |
|---|---:|---|---|
| LE16 0x00E8 | 112 bytes | +2..52、+53..103；各 51-byte narrow slot | +104..109 opaque；+110..111 common u16 |
| LE16 0x000F | 214 bytes | +2..103、+104..205；各 51 UTF-16 word | +206..209=DWORD 0x00010001；+210..211=WORD 0x0034；+212..213 common u16 |

兩個格式不能互相套用。Client 觀察到 MD5 小寫 hex 摘要相關路徑，但 OS ACP/codepage、字串轉換失敗、E8 opaque tail 與 Server 官方帳密政策仍未知。**不要求獨立 Server 使用原版 Server 的 DB/雜湊儲存策略**；這屬獨立設計決策，需另立 ADR。

局部登入結果消費者 0x4C37A0 讀 status+0x16；status0 +2 的寬字串非空才更新資訊；status5 為另一非成功路徑。群組使用 3-byte prefix（u16 ID + u8 channel count），每頻道 10 bytes、IPv4 octets +4..7。這不證明完整 0x13 長度、回覆順序、token、切線或實際登入成功。

`conformance/session/` 只檢查**人造 payload 槽位幾何**，不能用作合法帳密/登入成功範例。

來源 `CLM-AUTH-0001`、`CLM-AUTH-0002`（PARTIAL），`kr/evidence/602d11a657a2e8a3dc53cff4664f837d579cd6cb187311b2c4c7070e994887d9.txt`；缺口 `GAP-AUTH-0001`；請求 `RR-0003`；測試 `TEST-AUTH-0001`。
