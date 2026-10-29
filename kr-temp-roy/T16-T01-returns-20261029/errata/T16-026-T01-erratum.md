# T16-026 — T01 原始審核退回勘誤（新增文件，不改原稿）

建立時間：`2026-10-29T21:21:45.967286+08:00`；版別 `KR`。

## 精確來源及適用範圍

- 原稿：`kr-temp-roy/20261028-022116-chatgpt-web-roy-T16-26-KR-handler-candidate-one.md`
- **舊原稿 Git blob SHA**：`1a05ec70ba24945d1dc85952d237983f13056a08`
- T01 通知：`T01-RETURN-T16-026-c26518b1`
- first-party BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- **未取得新 Git blob SHA，因為沒有上傳 GitHub**。本勘誤對 source claims 的修正只在明列範圍生效。

## 修正內容


### 討論附錄指令起點錯誤 — 修正提案

T01 marked the supplemental assembly windows below as having **instruction-boundary risk or incorrect decoding**. One `0x4AEDAF→0x4AEDB0` pair additionally overlaps a possible distinct function-entry prologue and must not be judged by naive linear scanning of preceding data. A linear `objdump --start-address` from the bad address will invent instructions; remove affected rows, branch lists and any conclusions that depend on them. For each address below, preserve the source historical appendix unchanged; the listed **candidate preceding instruction anchor** is only a local decode location, not proof of a reachable root or that the original entry is invalid. In particular, the `0x4AEDB0` case needs function-start proof. Full function-root/control-flow re-decoding and independent T01 re-review are still required for a `READY_FOR_REVIEW` claim; this is explicitly **not** a fabricated full rooted CFG.


|原錯誤起點|候選前置 decode 起點（T01 建議／本次局部重解）|實檔 raw 摘要|
|---|---|---|
|`0x4AEDB0`|`0x4AEDAF`|`VA 0x004AEDAF, .text raw 0x000AE1AF: 00 55 8b ec 83 e4 f8 6a ff 68 8c 97`|

#### 原始 bytes 上 anchored decode（只是候選局部窗口，非全 CFG）

`原錯誤窗口起點 0x4AEDB0`，從先前指令 `0x4AEDAF` 解碼：

```asm
  4aedaf:	00 55 8b             	add    BYTE PTR [ebp-0x75],dl
  4aedb2:	ec                   	in     al,dx
  4aedb3:	83 e4 f8             	and    esp,0xfffffff8
  4aedb6:	6a ff                	push   0xffffffff
  4aedb8:	68 8c 97 93 00       	push   0x93978c
  4aedbd:	64 a1 00 00      	mov    eax,fs:0x0
```

**需 T01 下一步：** 找到完整 containing function entry，從 root 和可到達 edges 重新解碼，重做原報告附錄與由該附錄推導的所有 call/branch list；未修完前不要標 `READY_FOR_REVIEW`。

## 修正影響／驗收門檻

- **Client 待逆向**：此勘誤沒有證成任何新的 Quest S→C wire opcode 或 Quest16→15 接取 UI 閉環。
- **Server 待開發**：相容 Server 的任務前置、解鎖、持久化由 S00 SPEC/ADR 獨立設計，不可由局部 ASM 冒稱官方判斷。
- **跨功能待整合**：如涉及 T02 framing/網路、T06 UI 等，由相關 Task 的原始證據及 T01 claim-level review 處理。
- **待遊玩驗證**：未執行原 Client 或動態封包測試。
- **T01 狀態**：GitHub 仍為 `NEEDS_FIX`/`NEEDS_QUALIFICATION`；待來源 Task 將此勘誤審核／提交後，才能提出 `READY_FOR_REVIEW`，且 T01 通過才可 `RESOLVED`。

## 原始來源／交叉引用

- `kr/tasks/T16/README.md` 上固定退回 ID 和精確 blob SHA。
- `shared/integrations/T01-20261029-semantic-review/t16/return-proposals.json`；`shared/integrations/T01-20261029-continuation-02/t16/README.md`。
- `shared/verified-knowledge/README.md` 的有界條目不等於本篇 FULL-PASS。