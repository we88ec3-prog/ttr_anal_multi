# T01 — extra/roy1 E81 與 extra/roy2 RR-0006：三父 Git Merge、來源 R0 / 限定 R1–R2 驗證
2026-11-01 (Asia/Taipei)。**本批僅提交到 `t01/roy/chatgpt-web`，不合回 main；無來源全文 FULL-PASS、NATIVE_VERIFIED 或遊玩驗收。**

## 來源 Git 身份與去重
- 開工時 `main@ecc948a9e2fa731a272a826e30f691dde88d7d76`，來源 `extra/roy1@b889296d22c404e2a74f8e77ecf0be4ded433932`、`extra/roy2@ebf123af46569e445d5238766abb9e0248a9527a`。原始 Git 提交以三父 merge 保留，而非 cherry-pick/覆寫舊原稿；使用 main 原 tree 加入兩分支相對主線**尚未納入的四個 blob**。來源路徑互不重複。
- `main...extra/roy1`：3 ahead、318 behind，缺 E81 報告+驗證器；`main...extra/roy2`：1 ahead、24 behind，缺 RR6 報告+驗證器。其餘既存主線檔案、S00 RR/dispatch、SPEC/GAP/TEST、owner/task.json、其他 Task 原稿均保留。
- KR 原件 `Tartaros.bin` 12,472,320 bytes SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`、`Tartaros.exe` `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`、`Table.stp` `09e2cc48be98ad491afe394f966feb5812983fbf35da9037a8fa477d9848a442` 均由本次上傳原始檔唯讀重算確認。PE32 .text VA=0x401000 raw=0x400，raw_offset=VA−0x400C00。
- 新來源 `SRC-0652` 原稿 `kr-extra-roy/20261031-chatgpt-web-roy-E81-RR0009-F431F-Employ-UI-events-native-supplement.md`，blob `7fea46f8803d67e8d63c281f448515c37a521796`，UTF-8 SHA256 `792843ef036053df03dacac18edb3efb6b69f7ad4943aaed77bd4c17a2147e37`；作者機械驗證器 `kr-extra-roy/20261031-chatgpt-web-roy-E81-RR0009-verify.py` blob `55b56673e7ba569e82933075055833fc283c7d97`。
- 新來源 `SRC-0653` 原稿 `kr-extra-roy/20261101-020429-chatgpt-web-roy-RR0006-Rx-boundary-node-lifetime-post-error-frame.md`，blob `ca698712d6016884308f866f0e7e643ce22c7d64`，UTF-8 SHA256 `386287b933005709f536b07defab968ea859aa532725135521bbb2e6b8c6c4f6`；作者機械驗證器 `kr-extra-roy/tools/rr6_rx_boundary_audit.py` blob `689e1ae68c2adf71e62786b872a2d541d6b6196c`。
- 來源由 `research/intake/index.json` 的 2 條精確 SHA/版本 R0 登記；`research/claims/index.json` 新增 `CLM-CHAR-0007` 與 `CLM-NET-0037`，**均 PARTIAL**。原稿已有的 E70/E59 與既有 CLM 保留不改、不因同一作者重複來源就升級驗證品質。

## T01 獨立 BIN 原生局部 R2（不是作者測試輸出）
- 針對本次原始 KR BIN，以 PE32 section 重新解算 VA→raw，以原始 bytes、rel32 call 與 jcc target 進行 **41 個 native checks**，另做 **1 個 math bound check**，全部 PASS。以 GNU objdump 在 `0x5C32D0`、`0x807C7C`、`0x807D7F` 周邊交叉反組譯。41 項是有交集的機器碼檢查，**不是 41 條獨立語意主張**；作者的 31/34/4/16 checks 不拿來累加當 T01 成績。
- E81 代碼關聯：
```asm
5C32E0 mov eax,[edi+10h]        ; local event ID
5C32E3 sub eax,0F42DBh
5C32EA sub eax,2
5C32EF sub eax,42h
5C32F2 jne 5C3340
5C32F6 call 5C36D0              ; F431F route
5C36DE call 6BF310              ; nonzero event+14 gate + owner Employ object
5AAEA9 cmp dword [edi+10h],0F431Fh  ; second local consumer
4A992A push 0F431Fh             ; local event constructor
4AAE18 mov [FE1838h],4A98D0h   ; indirect callback registered
```
  E81 另與 `4B894C` roster N0 gate、`4D4154` record+5C ready flag、`5C30FD` owner+230 Employ lazy cache、`5C329A` 類型 0x11B 登記一致；在 .text 原始 literal 掃描僅見 `4A992B/5AAEAC/6BA33C`，**不等於全數可能的間接 event producer**。現有正向證據僅到條件式本地 consumer/record update；**仍無 N=0 → F431F 投遞 → 同版本 create dialog/control visible/enabled 完整鏈**。0x11B 不是已驗證 XML 控件 identity，local 0x33 亦不能直接稱 new character creation wire。採 `CLM-CHAR-0007 PARTIAL`。
- RR-0006 代碼關聯：
```asm
807C81 call 8075B0              ; checkout before bounds
807C97 jb 807DD6
807CA9 jae 807DD6
807CB3 jb 807DD6
807CC5 jae 807DD6
807D83 cmp dword [eax+4],0     ; normal node decision
807D97 call 8076F0             ; normal pool return
807DAD call 8040A0             ; normal enqueue
807DD6 mov edi,[esp+14h]       ; bounds-failure bypass
807DCB cmp eax,4               ; normal next frame check
807DCE jae 807BB0
```
  上述 **四處原始 jcc 全部精確跳到 0x807DD6**；`806E08 call 807B40`、`806A3B` WSARecv 0x1000、pool 活動計數 `8076C7 inc/80771D dec` 亦核對。若 pointer invalid branch 在 checkout 後**真可達**，局部路徑沒有走正常 recycle/enqueue，存在 **conditional unmatched-checkout / orphan risk**；但本次**不證明**有效 Conn、正常玩家或官方 Server 封包能觸發，也不證明實際 leak、可利用漏洞、OOM crash。單一正常部分幀最壞 `4096+8−1=4103`，加下一次 WSARecv 4096 為 `8199<20480=0x5000`；此算術不能排除異常 cursor、race、別名。既有 E59 checksum/decompress failure recycle 與 pointer failure 跳過 recycle **是不同路徑**。採 `CLM-NET-0037 PARTIAL`。
- `RR-0009` 在本次 main 已由 S00 `ACCEPTED`，是接受 E70 的**精確阻塞提交條款**，不是創角 UI 已可見；本次不變更。 `RR-0006` 在 main `IN_REVIEW`，本批不擅改 RR/S00 決議。不新增 NATIVE_VERIFIED 或 `shared/verified-knowledge` 條目，R0/R1 整合 ≠ R3 全文審查。

## 尚缺的證據及 S00 回報
- **Client 待逆向**：E81 的 FE1838/delegate/listener 與 event+14 來源、T06 GUI pack/可見狀態；RR6 合法 Rx cursor/alias/IOCP 分支可達性和 allocator null contract。以上是真正 Client-only 的未閉合部分，不能單純移交 Server 取代。
- **Server 待開發**：合法分包、黏包、frame error 策略和空角色初次進入/創角業務設計，應由 S00 的 SPEC/GAP/ADR/TEST 決策；不能聲稱還原官方 Server 內部。
- **跨功能待整合**：T03↔T06 GUI；T02↔T03 receive/lane；既有 RR9／RR6 未自行變動。
- **待遊玩驗證**：未執行或修改原版 Client，未觀察原版 Server pcap、同 session UI 或記憶體測量。
- 所有原生結論的正向範圍與反證詳見上述兩份來源原稿；本次 T01 整合報告保留裁決範圍，**不是任何原稿全文 FULL-PASS**。需正式對其他 Agent 生效時，由使用者另指示將 T01 工作分支整合到 `main`。
