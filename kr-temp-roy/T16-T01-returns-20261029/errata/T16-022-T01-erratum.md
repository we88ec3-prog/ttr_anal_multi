# T16-022 — T01 原始審核退回勘誤（新增文件，不改原稿）

建立時間：`2026-10-29T21:21:45.967286+08:00`；版別 `KR`。

## 精確來源及適用範圍

- 原稿：`kr-temp-roy/20261028-020939-chatgpt-web-roy-T16-22-KR-tutorial-bootstrap.md`
- **舊原稿 Git blob SHA**：`138c49cbd53e41169c386c9f1d7e826211fec283`
- T01 通知：`T01-RETURN-T16-022-c26518b1`
- first-party BIN SHA256：`9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`
- **未取得新 Git blob SHA，因為沒有上傳 GitHub**。本勘誤對 source claims 的修正只在明列範圍生效。

## 修正內容


### 討論附錄指令起點錯誤 — 修正提案

T01 marked the supplemental assembly windows below as having **instruction-boundary risk or incorrect decoding**. One `0x4AEDAF→0x4AEDB0` pair additionally overlaps a possible distinct function-entry prologue and must not be judged by naive linear scanning of preceding data. A linear `objdump --start-address` from the bad address will invent instructions; remove affected rows, branch lists and any conclusions that depend on them. For each address below, preserve the source historical appendix unchanged; the listed **candidate preceding instruction anchor** is only a local decode location, not proof of a reachable root or that the original entry is invalid. In particular, the `0x4AEDB0` case needs function-start proof. Full function-root/control-flow re-decoding and independent T01 re-review are still required for a `READY_FOR_REVIEW` claim; this is explicitly **not** a fabricated full rooted CFG.


|原錯誤起點|候選前置 decode 起點（T01 建議／本次局部重解）|實檔 raw 摘要|
|---|---|---|
|`0x4A89A0`|`0x4A899E`|`VA 0x004A899E, .text raw 0x000A7D9E: e8 5d 2e 00 00 50 e8 f7 2e 00 00 50`|
|`0x4A8B10`|`0x4A8B0C`|`VA 0x004A8B0C, .text raw 0x000A7F0C: a3 f0 ad fa 00 eb 05 e8 88 1e 0e 00`|

#### 原始 bytes 上 anchored decode（只是候選局部窗口，非全 CFG）

`原錯誤窗口起點 0x4A89A0`，從先前指令 `0x4A899E` 解碼：

```asm
  4a899e:	e8 5d 2e 00 00       	call   0x4ab800
  4a89a3:	50                   	push   eax
  4a89a4:	e8 f7 2e 00 00       	call   0x4ab8a0
  4a89a9:	50                   	push   eax
  4a89aa:	e8 91 2f 00 00       	call   0x4ab940
  4a89af:	68           	push   0xc06864
```

`原錯誤窗口起點 0x4A8B10`，從先前指令 `0x4A8B0C` 解碼：

```asm
  4a8b0c:	a3 f0 ad fa 00       	mov    ds:0xfaadf0,eax
  4a8b11:	eb 05                	jmp    0x4a8b18
  4a8b13:	e8 88 1e 0e 00       	call   0x58a9a0
  4a8b18:	84 1d 14 13 fb 00    	test   BYTE PTR ds:0xfb1314,bl
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