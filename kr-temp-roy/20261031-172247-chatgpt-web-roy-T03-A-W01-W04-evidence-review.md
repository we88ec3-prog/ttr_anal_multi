# T03-A — W01～W04 證據校正、來源去重、T01/S00 審核與 Client／Server 分流

> 研究者：chatgpt-web roy。2026-10-31 17:22:47 Asia/Taipei。Repository `we88ec3-prog/ttr_anal_multi`；唯一提交分支 `t03/roy/chatgpt-web`。本稿不是正式 RR 台帳、S00 設計決議，也不是 T01 FULL-PASS。本次作業僅針對 A 工作包，保留原稿與其他 Task 主責。

## 0. 驗收與第一手基線

- KR `Tartaros.bin`：**12,472,320 bytes**；本次實體檔唯讀 `sha256sum` = `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 = `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。
- 使用 `objdump -f -h -p -D -M intel` 檢查 PE32/i386、section、WSASend `IAT BD25B8`、WSARecv `IAT BD25BC`、KERNEL32!InterlockedIncrement `IAT BD2284`；23 處指定 bytes 靜態斷言 **PASS**（`kr-temp-roy/20261031-172247-chatgpt-web-roy-T03-A-verify-wsasend.py`）。未執行、附加或修改遊戲。
- `.text` VA `401000` / raw `400`；`.rdata` VA `BD2000` / raw `7D0600`；`.data` VA `D61000` / raw `95E800`。本文 `.text` raw = VA - `400C00`。上述地址都指向**KR**，不借用 TC。
- 來源 Git 基線（讀取當時）：main `f6eeef02dfa3704aabb45349718cc9da4b35fbe0`；T03 branch `f6eeef02dfa3704aabb45349718cc9da4b35fbe0`。GitHub 動態派工需以後續最新 `main` 為準，不因本檔變為第二份 RR 台帳。
- W01 的勘誤完整原稿：[`kr-temp-roy/20261031-172247-chatgpt-web-roy-T03-A-W01-T03-6-corrected.md`](./20261031-172247-chatgpt-web-roy-T03-A-W01-T03-6-corrected.md)；原始舊報告 `kr-temp-roy/20261028-223919-chatgpt-web-roy-T03-6-wsasend-completion-boundary.md` blob `28dc1c2e3e962c85e0187d75d219b9da5ec253aa` **保持不變**。
- 可重現的唯讀驗證：[`kr-temp-roy/20261031-172247-chatgpt-web-roy-T03-A-verify-wsasend.py`](./20261031-172247-chatgpt-web-roy-T03-A-verify-wsasend.py)，帶入相同版本的 BIN，確認 SHA／PE section／指令 23 slices；對 IAT 函式名稱另以原始 PE import 表確認。靜態 slices 不能代表全部 CFG/執行時/原版 Server 配對。
- 完整來源身份清冊（非第二個 RR 台帳）：[`kr-temp-roy/20261031-172247-chatgpt-web-roy-T03-A-source-index.json`](./20261031-172247-chatgpt-web-roy-T03-A-source-index.json)。

## 1. W01 — T01-RETURN-T03-006-LAYOUT-001 勘誤與二次驗證

**原錯誤**：原稿 T03-6 line 78 把 `connection+A050` 命名為 WSABUF layout、`+A0B8` 命名為 overlapped context，導致對 WSASend API 參數和 atomic counter 解釋錯置。另在 line 124、145、198 沿用不清的 context 與 WSABUF 說法。

### 1.1 從真實 bytes／push 順序重建

```asm
8068DE  8D 86 50 A0 00 00   lea eax,[esi+A050]      ; OVERLAPPED*
8068F3  50                  push eax                 ; lpOverlapped
8068F7  8D 48 14            lea ecx,[eax+14]        ; WSABUF*=Conn+A064
8068FC  89 78 18            mov [eax+18],edi        ; WSABUF.buf
806905  89 11               mov [ecx],edx           ; WSABUF.len
806909  51                  push ecx                 ; lpBuffers
80690A  52                  push edx                 ; socket=[esi]
806912  FF 15 B8 25 BD 00   call [BD25B8]           ; WSASend
806961  81 C6 B8 A0 00 00   add esi,A0B8
806967  56                  push esi
806968  FF 15 84 22 BD 00   call [BD2284]           ; InterlockedIncrement
80697A  81 C6 B8 A0 00 00   add esi,A0B8
806980  56                  push esi
806981  FF 15 84 22 BD 00   call [BD2284]           ; same counter
806E7D  8D B8 50 A0 00 00   lea edi,[eax+A050]      ; completed OVERLAPPED
806E83  3B D7               cmp edx,edi             ; pointer identity
806A0A  8D 86 30 A0 00 00   lea eax,[esi+A030]      ; recv OVERLAPPED
806A2E  8D 48 14            lea ecx,[eax+14]        ; recv WSABUF=+A044
806A43  51                  push ecx
806A4C  FF 15 BC 25 BD 00   call [BD25BC]           ; WSARecv
```

具體資料流：`ESI` 是**該條 connection pointer**，並非 frame buffer 指標；`+A050` 是先清理首五 DWORD 的 send OVERLAPPED，隨後的 `+14/+18` 組成 WSABUF 的 len/buf。stack push 次序與 WinSock API 呼叫參數一致。send 正常返回或 997 pending 路徑才在 `+A0B8` 做 atomic increment；`A0B8` 沒有被當作 `lpOverlapped` push。completion 比對的是 `OVERLAPPED=+A050`，接收的 completion 與 send 不同：`+A030`；recv WSABUF 在 `+A044`。

| 原文位置 | 反證／更正 | 判定 |
| --- | --- | --- |
| 78 | WSABUF 從 `+A050` 更正為 `+A064`；overlapped 不是 `+A0B8` 而是 `+A050`；`+A0B8` atomic | **已更正並定向 BIN 驗證** |
| 102 | receive 正確分隔 `+A030` OVERLAPPED 與 `+A044` WSABUF | **補明地址類型** |
| 124 | `806E83` 比的是完成事件的 send OVERLAPPED pointer，非 WSABUF | **已更正** |
| 145 | 保留完成長度驅動 staging consume，但 pointer 身份限定 OV，與 counter 分離 | **已更正、未擴大業務含義** |
| 149 | receive completion compare `+A030` 是 OVERLAPPED | **補明地址類型** |
| 198 | 未來 WSABUF buffer consumer 應由 `Conn+A064` 追，frame/connection 基準不能互代 | **已更正** |

**保留且不擴大**：在 `8068B0` 的前置 gate 有效時，非 -1 API result 為 return1；-1/997 為 return2；其他 error 為 return0；gate fail 為 return -1；`806E7D→8077B0` 有條件消耗 staging buffer；recv completion 可進 `807B40`。這些不能證 C2S42 實際送達、S2C42/43/69 為選角回覆、Server ACK、遊戲畫面轉換。

**T01 工作流**：原始報告 SHA/BLOB 均保留；本次提供完整修訂版、新 blob SHA 與驗證器，再將 T03 README 的 `T01-RETURN-T03-006-LAYOUT-001` 提交為 `READY_FOR_REVIEW`，**不是 RESOLVED**。T01 必須重核受影響的 API 引數、相對位址、completion 關係與原稿其它主張，通過後由 T01 更新 `RESOLVED`。沒有新增 T01 FULL-PASS。

## 2. W02 — 來源去重、19+20 篇原稿及 RR3 基線

### 2.1 舊 T03-LOGIN-01/02 與 T03-3～19（19 份）

來源：`research/handoffs/t01-t03-roy-20261029/sources.json`、`source-dispositions.json`、`README.md`。**19 篇均已收件，`CONFLICT_CHECKED`、歷史 `PENDING`，不是 FULL-PASS。**以下為精確來源路徑／blob／限定可復用主張。

| 原稿 | 原始 path | Blob SHA1 | 限定 CLM／索引 | 品質／處置 |
| --- | --- | --- | --- | --- |
| LOGIN-01 | `kr-temp-roy/20261028-203031-chatgpt-web-roy-T03-LOGIN-01-F42EF-native-event-chain.md` | `563ef44eb41beada1c35214d3591a66dbeccc68f` | CLM-CHAR-0003 | PENDING / R1 |
| LOGIN-02 | `kr-temp-roy/20261028-204121-chatgpt-web-roy-T03-LOGIN-02-665150-dialog-update-native.md` | `39a12e6feeea532f6fd235061b77ed80aa408220` | CLM-CHAR-0004 | PENDING / R1 |
| T03-3 | `kr-temp-roy/20261028-204757-chatgpt-web-roy-T03-3-command42-selection-callback.md` | `e38d3c84ab6e65bc9df95789a749349df81234e4` | CLM-CHAR-0005, CLM-CHAR-0006 | PENDING / R2 |
| T03-4 | `kr-temp-roy/20261028-212612-chatgpt-web-roy-T03-4-vtable-send-queue.md` | `d5d56758757b8342d4b6a00681a1b9484632f184` | CLM-NET-0005 | PENDING / R1 |
| T03-5 | `kr-temp-roy/20261028-213316-chatgpt-web-roy-T03-5-queue-drain-framing.md` | `55cc20c59112d7166a970c4d95f963901a599c66` | CLM-NET-0001, CLM-NET-0002, CLM-NET-0003 | PENDING / R1 |
| T03-6 | `kr-temp-roy/20261028-223919-chatgpt-web-roy-T03-6-wsasend-completion-boundary.md` | `28dc1c2e3e962c85e0187d75d219b9da5ec253aa` | CLM-NET-0005, CLM-NET-0013 | **REFUTED 局部 layout，待新版複驗** |
| T03-7 | `kr-temp-roy/20261028-224318-chatgpt-web-roy-T03-7-recv-frame-decode-boundary.md` | `2df0b188dadd34f852929c7196b3017b63b84999` | CLM-NET-0004 | PENDING / R2 |
| T03-8 | `kr-temp-roy/20261028-224903-chatgpt-web-roy-T03-8-recv-staging-two-lanes.md` | `8eaa4acc384ca4078b337ff897a35cde5bd93568` | CLM-NET-0006 | PENDING / R1 |
| T03-9 | `kr-temp-roy/20261028-225522-chatgpt-web-roy-T03-9-recv-queue-worker-virtual-dispatch.md` | `235a130caeec86d56fcc7af507697bd97ad48aa3` | CLM-NET-0009 | PENDING / R1 |
| T03-10 | `kr-temp-roy/20261028-230450-chatgpt-web-roy-T03-10-worker-owner-callers.md` | `0ff391c3e28de57a5a232bad320d7577e7783e50` | CLM-NET-0010 | PENDING / R2 |
| T03-11 | `kr-temp-roy/20261028-231121-chatgpt-web-roy-T03-11-worker-and-send-scheduler.md` | `10dda12c85d43bace2a7afcc639dd725213d83b2` | CLM-NET-0005 | PENDING / R1 |
| T03-12 | `kr-temp-roy/20261028-231458-chatgpt-web-roy-T03-12-worker-poll-recycle-lifecycle.md` | `78978d48072de78517298c58dc1718effa591e47` | CLM-NET-0011 | PENDING / R1 |
| T03-13 | `kr-temp-roy/20261028-231843-chatgpt-web-roy-T03-13-worker-vtable-provenance-budget.md` | `f383be544b99d755bbe9cc198343326618f750fe` | CLM-NET-0012 | PENDING / R1 |
| T03-14 | `kr-temp-roy/20261028-234545-chatgpt-web-roy-T03-14-parent-provenance-worker-vtable.md` | `c53fcfcffee7f029619c0bcce400390eb0b6c079` | CLM-NET-0010 | PENDING / R2 |
| T03-15 | `kr-temp-roy/20261028-234749-chatgpt-web-roy-T03-15-parent-output-slot-virtual-source.md` | `87ebf5cd59535b0c6cea09f6c4449f8451d10998` | CLM-CLIENT-0004 | PENDING / R2 |
| T03-16 | `kr-temp-roy/20261028-235041-chatgpt-web-roy-T03-16-output-slot-stack-ssa.md` | `5b60a1f59ad396f138b364631e9eded832b4158f` | CLM-CLIENT-0005 | PENDING / R2 |
| T03-17 | `kr-temp-roy/20261028-235314-chatgpt-web-roy-T03-17-parent-output-gates-interface.md` | `07b947d276e8037e93399c5e60e927d2781b5df4` | CLM-CLIENT-0006 | PENDING / R2 |
| T03-18 | `kr-temp-roy/20261029-001216-chatgpt-web-roy-T03-18-printscreen-d3dx-native-boundary.md` | `a1d42e16f768edc1b653ee37b2eab8bf4576994b` | CLM-CLIENT-0007 | PENDING / R2 |
| T03-19 | `kr-temp-roy/20261029-001541-chatgpt-web-roy-T03-19-worker-parent-provenance-audit.md` | `6c4747696a71d9f552f7d517db732d98c9dde8ce` | CLM-NET-0010 | PENDING / R2 |

舊版 T03-6 的 `CLM-NET-0013` 已有精確 layout 反證；本版只讓來源 Task 提交修正版，不直接覆寫 T01 `REFUTED`／`PENDING` 歷史裁定。T03-15～18 的 **Print Screen／D3DX** 介面不具有角色 S2C 業務證據；亦不得用 worker vtable 假定同一 socket 實例。已見基礎 framing/scheduler 屬 T02，T03 僅引用；不做二次 owner 登記。

### 2.2 E61～E80：20 份原稿；避免跨 RR 混用

GitHub `main` 的 `kr-extra-roy/` 目錄已核對**每個序號有一份 .md**（隨附的 verify.py 是獨立驗證器，非第二篇原稿）。各個 blob 僅證明原稿身份；作者的 BIN-first 結果採用有界主張，尚未成為 T01 全文 FULL-PASS。

| 原稿 | 原始 path | Blob SHA1 | 本項 RR 最新關聯 | 限制 |
| --- | --- | --- | --- | --- |
| E61 | `kr-extra-roy/20261030-144616-chatgpt-web-roy-E61-RR0002-selection-C2S-roster-S2C-candidate-negative-join.md` | `fc1d4845b3e1647a963e07b0838e05108e4218ca` | RR-0002 BLOCKED | 原稿留存／有界來源，**不自動 FULL-PASS** |
| E62 | `kr-extra-roy/20261030-144943-chatgpt-web-roy-E62-RR0002-inbound42-effect-table-scene-caller-falsification.md` | `88ebd073cc14f2dee47d712ce9086346b8f62ace` | RR-0002 BLOCKED | 原稿留存／有界來源，**不自動 FULL-PASS** |
| E63 | `kr-extra-roy/20261030-chatgpt-web-roy-E63-RR0002-scenario-review-rtti-scene-switch-60-69-5F-native.md` | `3232b05dbc0d3878aeae206bc84f5726bf2b93bf` | RR-0002 BLOCKED | 原稿留存／有界來源，**不自動 FULL-PASS** |
| E64 | `kr-extra-roy/20261030-chatgpt-web-roy-E64-RR0002-expedition-square-69-subtype-and-full-E63-native-appendix.md` | `715636b667f47e42a31d50590ffd39d75e93f4b7` | RR-0002 BLOCKED | 原稿留存／有界來源，**不自動 FULL-PASS** |
| E65 | `kr-extra-roy/20261030-chatgpt-web-roy-E65-RR0002-square-scene-vtable-entry-and-subtype-jump-table-static-tests.md` | `38b224caa99a3c2c9dc0b797f00b5cd16a790fda` | RR-0002 BLOCKED | 原稿留存／有界來源，**不自動 FULL-PASS** |
| E66 | `kr-extra-roy/20261030-chatgpt-web-roy-E66-RR0002-square-handshake-43-68-6A-and-dual-state-RTTI.md` | `a802e8482af20145476015c17ee3dda029558f6c` | RR-0002 BLOCKED | 原稿留存／有界來源，**不自動 FULL-PASS** |
| E67 | `kr-extra-roy/20261030-chatgpt-web-roy-E67-RR0002-Client-static-completion-original-reply-evidence-blocker.md` | `835ce66c56e91f65b1f1e32176d3892834992a70` | RR-0002 BLOCKED | 原稿留存／有界來源，**不自動 FULL-PASS** |
| E68 | `kr-extra-roy/20261030-chatgpt-web-roy-E68-RR0008-selection42-scenario-review-writer-endcutscene-static-closure.md` | `0af10e12b2247f3cd4493086d282044fae249c31` | RR-0008 IN_REVIEW | 原稿留存／有界來源，**不自動 FULL-PASS** |
| E69 | `kr-extra-roy/20261030-chatgpt-web-roy-E69-RR0003-E8-tail-uninitialized-CPACP-and-13-handoff-native.md` | `98546ce73206e2b8f6fede78d83923af7a76cf5b` | RR-0003 IN_REVIEW | 原稿留存／有界來源，**不自動 FULL-PASS** |
| E70 | `kr-extra-roy/20261031-chatgpt-web-roy-E70-RR0009-empty-roster-GUI-blocker.md` | `ef778ac58ccdfd4013962b86a2aa33bf6f245d13` | RR-0009 SUBMITTED | 原稿留存／有界來源，**不自動 FULL-PASS** |
| E71 | `kr-extra-roy/20261031-010931-chatgpt-web-roy-E71-RR0010-create-C2S-candidates-S2C-roster-blocker.md` | `57f809809e28d24cd9779549d95e9b269db4870b` | RR-0010 BLOCKED | 原稿留存／有界來源，**不自動 FULL-PASS** |
| E72 | `kr-extra-roy/20261031-chatgpt-web-roy-E72-RR0010-create-secondary-dispatch-roster-native-followup.md` | `7f1907f8fa0877c9fcd905eba048ec7f3e52cb9c` | RR-0010 BLOCKED | 原稿留存／有界來源，**不自動 FULL-PASS** |
| E73 | `kr-extra-roy/20261031-chatgpt-web-roy-E73-RR0010-expedition-name-create-C2S3E-S2C4A-native-chain.md` | `eeb598db5c9bee8909d97a3376c4637d382c3bac` | RR-0010 BLOCKED | 原稿留存／有界來源，**不自動 FULL-PASS** |
| E74 | `kr-extra-roy/20261031-0244-chatgpt-web-roy-E74-RR0010-expedition-name-roster-shared-state.md` | `f3d4f126c5ce6a60a871189ca44015dc4693b97b` | RR-0010 BLOCKED | 原稿留存／有界來源，**不自動 FULL-PASS** |
| E75 | `kr-extra-roy/20261031-0305-chatgpt-web-roy-E75-RR0002-roster-0x26-two-layer-gameinfo-handler-native.md` | `715bf8cd6edb423becd84fd4faa0a025940092e6` | RR-0002 BLOCKED | 原稿留存／有界來源，**不自動 FULL-PASS** |
| E76 | `kr-extra-roy/20261031-0335-chatgpt-web-roy-E76-RR0010-expedition-page-ready-dual-entry-error-reset.md` | `672a884d84c8a6349c71b3059f1094d8e62b5fb0` | RR-0010 BLOCKED | 原稿留存／有界來源，**不自動 FULL-PASS** |
| E77 | `kr-extra-roy/20261031-chatgpt-web-roy-E77-RR0010-B6-roster-event-EXPD-scene-boundary.md` | `7589e9c63f56f9a9d8737f825c46170ea9e64ac7` | RR-0010 BLOCKED | 原稿留存／有界來源，**不自動 FULL-PASS** |
| E78 | `kr-extra-roy/20261031-chatgpt-web-roy-E78-RR0010-native-static-closure-and-S00-final-handoff.md` | `ae381dd784f8d492a5b760723c8912ad7be2531a` | RR-0010 BLOCKED | 原稿留存／有界來源，**不自動 FULL-PASS** |
| E79 | `kr-extra-roy/20261031-chatgpt-web-roy-E79-RR0010-S2C2B-network-roster-alias-native-closure.md` | `95ced26202c2aedf7ff57c87d4991eff00ad64ff` | RR-0010 BLOCKED | 原稿留存／有界來源，**不自動 FULL-PASS** |
| E80 | `kr-extra-roy/20261031-0414-chatgpt-web-roy-E80-RR0002-selection-UI-roster-square-new-server-contract.md` | `8b15f43fe9414936ec8e6f987347e27c77fb211e` | RR-0002 BLOCKED | 原稿留存／有界來源，**不自動 FULL-PASS** |

**去重核心：**
- E61–E67、E75、E80 是 **RR-0002** 的既有選角／Square 邊界；保留正式 `BLOCKED`；`C2S0x42` 4-byte payload（角色 index 與 mode），**不**自動配對任何 S2C 0x42/43/69。
- E68 是 **RR-0008** 的 Scene/ScenarioReview：S2C 0x42→`FAB2A0` 20-WORD、`47D610` UI；`SceneItem+248`／`565720` 是另一條 review-key 寫入者；EndCutScene 另用 +38/+3C。不可串成首次入場教學 wire。
- E69 和原 **RR-0003** 技術稿重複處理 E8 不透明尾、CP_ACP 路徑、S2C 0x13 結果；兩份都不能證原版 Server 密碼政策。
- E70 **RR-0009** 有界 N=0 roster 分支與 GUI 候選，缺正向 N0→可見 create UI。T01/S00 仍須對 blocker submission 審核。
- E71–E74、E76–E79 是 **RR-0010**；Expedition name `C2S3E`/候選 `S2C4A`、full `S2C2`/delta `2B` 同 RoleStore、`B6` local UI event **都不等於 playable role 建立交易**。
- 共享 opcode 不等於 request→reply：C2S26 與 S2C26 是不同應用方向；`F4241/F4245/F4278` 屬 local event，絕非 wire opcode。

### 2.3 T01 舊來源／新 RR 審核與共用 FULL-PASS

| 限定 CLM | 目前來源品質 | 原稿已核定界線（摘要） |
| --- | --- | --- |
| `CLM-SCENE-0004` | `PARTIAL` | KR 0x47B5C0→0x565720, 0x561EF3 EndCutScene→0x565720 and dual script load evidence |
| `CLM-CHAR-0003` | `PARTIAL` | Local F42EF event provenance and UI consumer navigation, not complete event subscription/runtime delivery. |
| `CLM-CHAR-0004` | `PARTIAL` | Bounded UI record/detail function and two distinct caller return gates. |
| `CLM-CHAR-0005` | `PARTIAL` | T03-3 branch-specific UI→selection producer conditions; no universal gate on all callers. |
| `CLM-CHAR-0006` | `PARTIAL` | Local C2S selection payload builder, strictly excluding framing/session/reply semantics. |
| `CLM-NET-0013` | `REFUTED` | Exactly the API-layout attribution atT03-6L78, not the whole source or return/pending behavior. |
| `CLM-AUTH-0003` | `PARTIAL` | KR PE .data virtual-zero FBA808 plus mode entry 440790, conversion caller 4C37E7 |
| `CLM-AUTH-0004` | `PARTIAL` | KR active LOGIN scene second level 4C3220 handlers 4C37A0/4C3C10 |
| `CLM-AUTH-0005` | `PARTIAL` | KR 4C3080 group parser count loops / zero group local event |
| `CLM-SCENE-0005` | `PARTIAL` | KR .text 4ADF3D base-scene command42 table; 4B2190/4B21FD..4B222C payload/len path; 500110 20-word set; 47D693→503440 Review  |
| `CLM-SCENE-0006` | `PARTIAL` | KR .rdata C02F3C/C02D9C RTTI, .data TypeDescriptors F7D864/F7D890, .text 47B143/47B2EF/47B4C9/47D558..47D5B7/47B5EB..47B64A/5 |
| `CLM-AUTH-0006` | `PARTIAL` | 4A32B6..4A32C4; 4A33B5..4A3505 |

- RR-0003 原研究：`kr-temp-roy/20261030-142513-chatgpt-web-roy-T03-RR0003-KR-auth-E8-000F-13-codepage-group-handoff.md`；blob `64c8c1a3429ae6ff177a84dee0d08ad69dba0b17`，源級限定 `SRC-0473`、`CLM-AUTH-0003..0005`，T01 `PARTIAL`。
- RR-0008 原研究：`kr-extra-roy/20261030-chatgpt-web-roy-E68-RR0008-selection42-scenario-review-writer-endcutscene-static-closure.md`；blob `0af10e12b2247f3cd4493086d282044fae249c31`，`SRC-0474`、`CLM-SCENE-0005/0006`，T01 `PARTIAL`。
- RR-0009 原研究：`kr-extra-roy/20261031-chatgpt-web-roy-E70-RR0009-empty-roster-GUI-blocker.md`；blob `ef778ac58ccdfd4013962b86a2aa33bf6f245d13`，`SUBMITTED`（非 `IN_REVIEW`）；精確 blocker 不能稱 GUI 正向閉合。
- `shared/verified-knowledge/` 收錄的跨功能有界 FULL-PASS 不自動把這些 T03 原稿升級全文通過，亦不證 original Server 序列。不得用來源匯入、R1、R2 抽查、CI 綠燈代替 FULL-PASS。

## 3. W03 — T01/S00 正式 review 反饋、待補證與驗收出口

截至本次 `main` 派工台帳（僅快照）：

| RR | 最新 state | P | 原稿位置或現階段 blocker | GAP |
| --- | --- | --- | --- | --- |
| RR-0002 | `BLOCKED` | P0 | 未進入正式提交／保留阻塞 | GAP-CHAR-0001 |
| RR-0003 | `IN_REVIEW` | P0 | `kr-temp-roy/20261030-142513-chatgpt-web-roy-T03-RR0003-KR-auth-E8-000F-13-codepage-group-handoff.md` (64c8c1a3429ae6ff177a84dee0d08ad69dba0b17) | GAP-AUTH-0001 |
| RR-0008 | `IN_REVIEW` | P0 | `kr-extra-roy/20261030-chatgpt-web-roy-E68-RR0008-selection42-scenario-review-writer-endcutscene-static-closure.md` (0af10e12b2247f3cd4493086d282044fae249c31) | GAP-SCENE-0001, GAP-FLOW-0001 |
| RR-0009 | `SUBMITTED` | P0 | `kr-extra-roy/20261031-chatgpt-web-roy-E70-RR0009-empty-roster-GUI-blocker.md` (ef778ac58ccdfd4013962b86a2aa33bf6f245d13) | GAP-CHAR-0002 |
| RR-0010 | `BLOCKED` | P0 | 未進入正式提交／保留阻塞 | GAP-CHAR-0003 |

| 項目 | 現有 reviewer 意見／已補來源 | T03 下一動作 | 不得擅自變更 |
| --- | --- | --- | --- |
| `T01-RETURN-T03-006-LAYOUT-001` | T01 定向 R2 指出 +A050/+A064/+A0B8 混淆，原始 T03-6 blob `28dc1c2e3e962c85e0187d75d219b9da5ec253aa` | **本次修正文書、23 slices、README 提 READY_FOR_REVIEW**；等待 T01 對所有受影響的結論做複驗 | 不能自己 `RESOLVED` 或清除舊版 REFUTED |
| `RR-0003` | T01 已 R0 精確 source `64c8c1a...` 與 10 slices 的有限 R2，`SRC-0473/CLM-AUTH-0003..0005 PARTIAL`；沒有 S00 結案 | 用 E69 衝突與來源去重；後續只有 reviewer 精確指出缺項才修報告；真正 first-response/opaque tail 若仍可從 Client 靜態追則 B 工作包處理 | `IN_REVIEW`、`GAP-AUTH-0001 OPEN` |
| `RR-0008` | T01 R0/R2 `SRC-0474` 及 20-WORD／SceneItem+248/EndCutScene 反例，限定 `PARTIAL` | 保持 Review 與首次教程分流；正向 select→scene-key wire 缺口交 G/H，不重複 E68 已驗片段 | `IN_REVIEW`、`GAP-SCENE-0001/FLOW-0001 OPEN` |
| `RR-0009` | E70 `SUBMITTED`，無完整可見 create UI 正向鏈，驗收準則容許 precise blocker | 保留 N0/N>0/missing resource/資料已寫而 UI 未 ready 四反例；需要 T06 同 KR layout/control/source 及具場景條件的 listener | 未有 S00 `ACCEPTED` 或新的 `NEEDS_REVISION`，不自稱已採納 |
| `RR-0002` | E61–67、E75/E80 C2S42 與 Square 局部，原版 Server 回覆匹配未知 | G 工作包先繼續可由 Client 靜態判定的 `scene+CC` reset、mode2 UI gate、失敗 consumer，再明確申請原版 trace | 保持 `BLOCKED`，不猜 `42→69/7` |
| `RR-0010` | E71–E79 的 ExpeditionName／角色清單／招募分流，建造 playable role 配對未證 | F 工作包查 create/recruit control→C2S33 等候選的真實 consumer；需要時提供 KR multi-Conn capture / Server origin 解阻條件 | 保持 `BLOCKED`，不等於 Expedition 建名成功就能遊玩 |

**提交授權分界**：這次使用者授權 A 文件及 T03 修正 **Commit／Push 到 `t03/roy/chatgpt-web`**；不授權 T01 直接 `RESOLVED`、S00 `ACCEPTED`、重寫正式 RR/Inbox 或直接提交 `main`。W03 是 reviewer-feedback 待補查清單，而非代 T01/S00 做決議。

## 4. W04 — Client 待逆向 / Server 待開發 / 跨 Task 整合 / 待遊玩驗證

| 玩家情境 | Client 待逆向（可從同版原件續追） | Server 待開發（非官方政策） | 跨功能待整合 | 待遊玩驗證（另行授權） |
| --- | --- | --- | --- | --- |
| 登入送出 | E8 +104..109 間接 writer、launcher mode gate、local queue 到 socket 的完整來源 | 帳密存儲、驗證與 Session/token 政策，須有明確 ADR | T02 frame／slot1、T03 E8/000F | 同版登入成功/失敗原生多 Conn trace |
| 登入回覆 | `S2C13` 狀態與 UI、`7A` count、真正 first-message 前提與負面分支 | 結果/錯誤回包與安全合法資料的相容實作，不能猜原版 enum | T02 active LOGIN scene、T03 auth、S00 SPEC-AUTH/FLOW | 原版 Client 收包順序、畫面和有效 Session |
| 選服切線 | `F4241` 本地 event→`66C090` selection／Connect gate 與選服拒絕處理 | server endpoint 配發、跨 Conn Session 遷移策略 | T02 key0/1/2、T03 row/selection UI | 分組/channel/斷線/重連多路擷取 |
| 無角色 UI | `S2C2 N=0` 到可操作 Expedition/Create GUI 的 resource/scene/callback 缺環 | 帳號、遠征隊身分與可操作角色拆分 | T06 GUI 資源，T03 RR9 | N0/N>0/缺資源/未就緒四種畫面 |
| Expedition 建名 | `C2S3E+2..5` writer、`S2C4A` 現實配對、狀態更新可達路徑 | 名稱唯一性／帳號權限／重試／長度政策 | T02 transport、T03 local event、S00 ADR | 3E→4A 是否真有同一 session request-reply |
| Role roster | full `2`/delta `2B` 的分派、mask、可用旗標與 `B6` UI gate | 同一權威 RoleStore、合法角色資料與 snapshot/delta 規則 | T04 role values、T06 role display、T02 dispatch | 新舊帳號清單、短包、重刷與重登 |
| 真正創角／招募 | `CEmployNewCharacter` UI→C2S33/其他候選、接受/拒絕→同 role record 的 positive writer | 招募合法性、角色建立初始值、持久化交易（以 ADR 識別自訂） | T04 初值、T03 RR10、S00 SPEC-CHAR | 原版 KR 多 Conn create/reject/roster trace |
| 選角 | C2S42 mode2、pending reset、真實 S2C success/error consumer | Server 檢查 ownership/disabled/role state/Session lease 等自訂設計 | T02 transport、T03 RR2、T05 Square | 成功/失敗選角原版封包及 UI 回退 |
| 世界/教學 | `S2C69/7`／`C2S43` 的場景條件、scene key writer、完整前置 | 首登／教學進度／世界就緒策略由 Server 設計，不得稱官方 | T05/T07/T16、T03 RR8 | Square world readiness/教程入場真實 runtime |
| WinSock transport | 本次 W01 只校正送收 OV/WSABUF/counter，整條 C2S42 wire 證據仍待 T02/T03 銜接 | 正確 framing／回覆排序遵循獨立協定證據 | T02 為 transport owner | WSASend 完成不能當成 Server 已收到 |

四欄互不替代。Server-only 不明不阻止 T03 後續靜態逆向；反之 Client 還未知的 body/handler/UI gate 不可推給 Server 隨意編碼。原始 Server 的認證／交易配對缺失，須用明確未知或可回溯的有限相容試驗表示。

## 5. 驗收表（T03 A 工作包，不冒充 RR 結案）

| WID | 對應目標 | 本次完成可重現交付 | 限定結果 |
| --- | --- | --- | --- |
| **W01** | T03-6 勘誤 | 原始 report 留存、完整修訂版、精確 assembler/VA/raw/23 bytes、README READY_FOR_REVIEW | **T03 作者已修正；等待 T01** |
| **W02** | 來源去重索引 | T03 19 篇與 E61–E80 20 篇 paths/blob、RR3、T01 source dispositions、有限 CLM 索引；JSON snapshot | **來源去重完成；非全部原生語意通過** |
| **W03** | reviewer feedback 清單 | RR3/8/9 查正式台帳與 T01/RR 證據，具體待補、拒絕升格、受影響 GAP | **清單完成；各 RR 仍由 T01/S00 審核** |
| **W04** | 四類未知分類 | 上節 10 條情境 × Client / Server / Integration / Runtime matrix | **界線與後續 owner 交接完成** |

## 6. 依賴與後續研究入口

- B/W05–W08：認證實際 payload/source/handler與第一個 S2C，接續 `RR-0003` 具體待逆向事項，不能重複用假定 UTF8/CP949 或 E8 tail 六 bytes 全零。
- D/W13–W16、E/W17–W20、F/W21–W24：Expedition 建名、full/delta roster、真正 playable role recruit 三條路徑各自對應 `RR-0009/0010`，不可混淆。
- G/W25–W28：選角 C2S42 的 mode、fail/UI、pending reset、positive pairing 靜態鏈先追可證部分；原版 Server wire pairing 若無證須列精確解除條件。
- H/W29–W32：選角後 scene/square→tutorial 的跨 T05/T07/T16 接口分流；`Event.stp (1001,1)` 是資源 key，不是已驗 wire。
- T01 請依本稿和修正版先定向確認 `T01-RETURN-T03-006-LAYOUT-001`。S00 可引用有界 claims，但不能因本次 A 工作包完成而調整 `SPEC-AUTH/CHAR/FLOW` 的 DRAFT/PARTIAL 或未解 GAP。

**資料保護**：不修改其他 Task、owner/catalog、原始二進位、T01 審核本身，也不新增 branch。歷史 T03-6 以原 Blob 完整保留；本報告為 A 階段實際校正／審核查對，不是 RR-0003/8/9 的新正式 `SUBMITTED` 報告。
