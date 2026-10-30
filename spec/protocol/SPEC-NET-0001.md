# SPEC-NET-0001 — KR Client frame codec 有限契約

**DRAFT / PARTIAL；不是完整網路相容性認證。** 原版 KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`。

## 出站 local frame writer（非 socket 已送出證據）

| Writer | frame bytes（LE） | Payload 上限 |
|---|---|---|
| 0x807A70 | u16(len), u16(0x1A68), raw payload | 1..4092（len+4<=4096） |
| 0x807830 | u16(len), u16(0x0BBB), u16(checksum), XOR payload | 1..4090（len+6<=4096） |

`checksum=sum(plaintext_bytes)&0xFFFF`，`out[0]=in[0]^0xB6`，`out[i]=in[i]^in[i-1]`（i>=1）。除長度外尚有 output ring 累計量<=0x4000 及指標檢查。0x8061A0 的 mode `connection+0xA02C` 為 0 時用 1A68，非零先嘗試 0BBB，若失敗仍會 fallback 1A68，**不能假定非零 mode 一定是 0BBB**。

## 入站局部 parser（0x807B40）

LE16 payload length 允許 1..4096（與 local sender 限制不同）。marker 在 +2；0x2633 header=8、0x0BBB header=6、其他（含 0x1A68/0x22D7）預設 header=4。資料不足會留待後續。0BBB 會還原 XOR 與驗證 plaintext byte-sum。**未知 marker 沒有被這個比較鏈直接拒絕**；checksum 不符的後續 pool/record 語意未閉合；0x2633 解碼、mode 的所有寫入者及登入時序亦未完整確認。

## 開發者可以做什麼

可以實作 1A68/0BBB 的**離線條件式** encoder/decoder，將業務 opcode 與 frame marker 分層；不可將離線測試的成功當成真實 Client 已連線相容。測試工具對不支援 marker 與 checksum 錯誤採**保守拒絕政策**，這是工具設計，**不是原版 Client 的完整錯誤行為**。

測試：`TEST-NET-0001`、`TEST-NET-0002`；缺口 `GAP-NET-0001`；請求 `RR-0001`。來源 `CLM-NET-0001..0004`（PARTIAL），`kr/evidence/f398779b1e129b0150f009451dc72b51b1cb9b88e9f2aa5c43b4eeeac02e0e94.txt`。T16-70 有 T01 退回的錯誤 header 標記與位址，不能直接當證據。未在 Phase B 重做原生 BIN FULL-PASS。

## Phase B T02 邊界整合補充（2026-10-29）

T02 舊研究另外確認了有界 `WSASend`、`WSARecv/IOCP` 與後續 CClient 命令分派路徑，參見 [SPEC-NET-0002](SPEC-NET-0002.md) 與 [SPEC-NET-0003](SPEC-NET-0003.md)。因此「socket API 或收包 dispatcher 尚未定位」不再是正確的整體狀態。**仍未知的是 Client 何時/以哪種 frame 送出首筆消息、模式實際轉換、跨階段連線與異常語意。**

較早研究的 `conn+A02C` 直接存取掃描發現初始化以值 `2` 寫入（`0x805D02`），但該掃描未排除間接/alias writer，故不能由此宣稱原版全部時間都使用 XOR 外框。舊 T16-70 的標頭、stream/connection offset 混淆另見 [證據勘誤](T02-EVIDENCE-INVENTORY.md)，不將錯誤搬入此規格。

## 2026-10-30 T02 RR-0001/0004/0006 source-scoped revision

T02 E57/E58/E59 reports have been published as bounded native-static research, but RR-0001, RR-0004 and RR-0006 are still **IN_REVIEW**. The local outbound and inbound modes remain different kinds of information.

- Inbound **0x2633** has an observed 8-byte header: LE16 encoded-input length 1..0x1000, LE16 marker, **4 header bytes of unproven meaning**, then input bytes. Unlike 0x0BBB, its transformation first reverses a rolling XOR with first byte xor **0x7C** and subsequent byte xor previous decoded byte; `0x727190` then performs an inflate-like decode, success when return=0, with decoded output capacity at most `0x1000`. Do not call the four opaque header bytes official length/checksum fields or presume original Server chooses this marker. Native evidence is scoped to the Client parser.
- Inbound **0x22D7** and otherwise unrecognized markers take the observed default **4-byte/raw** parser branch. This is a local parser branch, **not** proof of a permissive official Server protocol, safe malformed-data handling, or successful app dispatch.
- **0x0BBB checksum mismatch** (16-bit plaintext sum) and **0x2633 decode error** both skip the decoded-payload copy, retain a zero-length pool node, then recycle it without sending a business command to the decoded app queue. The parsed wire frame can nevertheless be consumed; this is not proof the socket is closed.
- Outer LE16 payload length **zero or >0x1000** returns parser status 0 and follows a *different* IOCP branch; incomplete header/body is compacted and preserved for the next WSARecv. Do not conflate invalid length, bad checksum and partial frames.
- New-Conn `Conn+A02C` has a direct observed initializer `2`; same-Conn reset/reuse and aliases prevent any blanket claim that *every* connection uses only XOR framing or that indirect mode-zero writers cannot exist. Nonzero mode attempts 0x0BBB and may fall back to 0x1A68 under writer-guard failure. The first actual original-Server S2C packet and complete cross-socket ordering remain **UNKNOWN**.

Scoped registered evidence: `CLM-NET-0021..0028`, `SRC-0461/0462/0471` (PARTIAL); author reports E57/E58/E59 under `kr-extra-roy/` (RR-0001/0004/0006). This section **does not** confer T01 FULL-PASS, promote any CLM to NATIVE_VERIFIED, approve synthetic example packets as captured wire, or close `GAP-NET-0001/0003`.
