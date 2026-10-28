# T01-20261028-28 — 第九批 10 份原稿主張級 FULL-PASS 獨立驗收

## 口徑及來源

- 本批是 **T08-160～169 共 10 份、各自具有不同 GitHub 路徑與 SHA 的原稿**，未見於 T01-20～27 前八批的 80 份名單。本次只驗收原稿**實際肯定的有界技術主張**，不是十個完整 runtime/Server 功能驗收。
- 原始唯讀韓版 `Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本次本機重新計算一致；PE32 `.text` VA `0x401000` 對 raw `0x400`，僅 `.text` 的轉換為 `raw=VA-0x400C00`。
- 本輪直接以本機 Python 和 GNU objdump 檢查：`t01_batch9_audit.py` 的 **49/49 指令位址/raw byte 位元組斷言均相符**，及 CMonster `0xC0C9DC`、CEventActor `0xC0C824` 兩張 vtable 的各 6 個 DWORD 全部一致（共 12 個表項）；vtable 使用獨立 `.rdata` 映射，不套 `.text` 公式。可重驗的完整 49 筆結果在本地 `/mnt/data/t01_batch9_results.json`，本報告保留每份代表性原始 bytes。
- **稽核檢查式更正記錄**：最初手填將 `0x4D18D0` 假設為立即寫 vptr 的指令，與 BIN 不符；重新從函式入口解碼，該位址實為 `55 8B EC 56 8B F1`（prologue），更正預期後重跑 49/49，並非改寫 BIN 或忽略原稿反證。vptr 的實際建構寫入位址 `0x4D1749`。
- 每份原稿從 GitHub `main` 取得全文並記錄 blob SHA；對原稿中標示為推測、unknown、尚未執行測試、其他 Task 的封包/Server 時機，不擅自當已完成。只依原生 byte/有界控制流程、來源表格裁決，其他明列保留。

## 十份逐項主張裁決

### 1. T08-160 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-015216-chatgpt-web-roy-T08-160-bounded-lifecycle-reconciliation-and-evidence-gates.md](../../../kr-temp-roy/20261028-015216-chatgpt-web-roy-T08-160-bounded-lifecycle-reconciliation-and-evidence-gates.md)，原件 Git blob SHA `c77cf4d62a1dea6d0ce7c682a246d6c58a55a9db`。
- **可確認的正面主張／caller-callee／data-flow**：建立/單鍵刪除/條件刪除/全清屬不同入口；修正 0x40F060 為 lazy getter，0x4B3733 才組合 0x06000000|WORD；tree erase 不等於 payload free。
- **第一手 BIN 證據（VA = raw bytes）**：0x40F0B4=b8 30 b1 fa 00；0x4B3733=0d 00 00 00 06；0x4DFBD5=e8 26 f3 34 00；0x4DFC1E=e8 6d 6c 2d 00；0x4DFF4C=0f b7 47 04
- **原稿自己保留的未知/限制**：此份為前序有界證據整合，來源 claim 有按前序研究定界；未驗證封包註冊表、server spawn timing 或 actor+0x88 完整 writer。
- 裁決：原稿當前限定範圍內的肯定事實成立，未知項沒有被宣告完成。


### 2. T08-161 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-020933-chatgpt-web-roy-T08-161-actor-vtables-deleting-destructors.md](../../../kr-temp-roy/20261028-020933-chatgpt-web-roy-T08-161-actor-vtables-deleting-destructors.md)，原件 Git blob SHA `4b6bbd0d2ddae6ac9648d6bb123cb1722b0ecc38`。
- **可確認的正面主張／caller-callee／data-flow**：兩種具體 actor 候選類別的 constructor vptr、主表 slot+0x00/+0x14，後者通往共同 0x4C8360；deleting wrapper 與 pre-remove 分離。
- **第一手 BIN 證據（VA = raw bytes）**：CMonster 0xC0C9DC: +0=0x4D18D0,+0x14=0x4D1F80；CEventActor 0xC0C824: +0=0x4D0CA0,+0x14=0x4C8360；0x4D1749=c7 07 dc c9 c0 00；0x4D1F80=e8 db 63 ff ff；0x4D18D0=55 8b ec 56 8b f1
- **原稿自己保留的未知/限制**：只限這兩種靜態 vptr，其他衍生類與實際動態物件型別未知。
- 裁決：原稿當前限定範圍內的肯定事實成立，未知項沒有被宣告完成。


### 3. T08-162 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-020933-chatgpt-web-roy-T08-162-actor-preremove-binding-release.md](../../../kr-temp-roy/20261028-020933-chatgpt-web-roy-T08-162-actor-preremove-binding-release.md)，原件 Git blob SHA `428922bee50d73c7d59867922b25378303c0443b`。
- **可確認的正面主張／caller-callee／data-flow**：0x4C8360 從 actor+0x15C 的次級介面+8 執行 vptr+8，對 actor+0x364 與 actor+0x164 128 個指標槽條件呼叫 0x7BE5F0；不直接等同析構。
- **第一手 BIN 證據（VA = raw bytes）**：0x4C8365=8b 87 5c 01 00 00；0x4C836F=8d 48 08；0x4C8374=8b 50 08；0x4C838C=e8 5f 62 2f 00；0x4C8397=bb 80 00 00 00
- **原稿自己保留的未知/限制**：未證每個槽最後都被清空；次級 vtable 動態實作依原稿保留。
- 裁決：原稿當前限定範圍內的肯定事實成立，未知項沒有被宣告完成。


### 4. T08-163 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-020933-chatgpt-web-roy-T08-163-removal-packet-boundaries-dispatch-negative-evidence.md](../../../kr-temp-roy/20261028-020933-chatgpt-web-roy-T08-163-removal-packet-boundaries-dispatch-negative-evidence.md)，原件 Git blob SHA `10eb180293d0bfb515de8071d8fb892af22e28bc`。
- **可確認的正面主張／caller-callee／data-flow**：0x4B28D0 的長度 4 起算每筆 WORD；0x4B3710 以長度 2 起算每筆 WORD 後 OR 0x06000000 再經 0x40F060 取得 receiver；兩格式不可與建立 26-byte row 混淆。
- **第一手 BIN 證據（VA = raw bytes）**：0x4B28FF=83 f8 04；0x4B2908=83 c0 fc；0x4B290B=d1 e8；0x4B3733=0d 00 00 00 06；0x4B3739=e8 22 b9 f5 ff；0x4B373E=e8 4d c5 02 00
- **原稿自己保留的未知/限制**：原稿的 `.rdata` 負掃描只能按指定 byte pattern/section 範圍解讀，不能推論正式 opcode 未註冊。
- 裁決：原稿當前限定範圍內的肯定事實成立，未知項沒有被宣告完成。


### 5. T08-164 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-020933-chatgpt-web-roy-T08-164-actor-removal-provenance-and-unresolved-gates.md](../../../kr-temp-roy/20261028-020933-chatgpt-web-roy-T08-164-actor-removal-provenance-and-unresolved-gates.md)，原件 Git blob SHA `515adc8ceba6ebf05bc70a75828ba3d402824b7c`。
- **可確認的正面主張／caller-callee／data-flow**：具體 vtable 下 pre-remove +0x14、delete +0x00(flag1)、tree node erase 三階段彼此不同；個別移除與條件移除/整表清理不混用。
- **第一手 BIN 證據（VA = raw bytes）**：0x4DFBD5=e8 26 f3 34 00；0x4DFBFD=8b 42 14；0x4DFC0D=6a 01；0x4DFC1E=e8 6d 6c 2d 00；0x4DFF82=e8 79 f2 34 00
- **原稿自己保留的未知/限制**：只確立受查型別和局部路徑，保留所有上游 opcode、其它類別和時間語義未知。
- 裁決：原稿當前限定範圍內的肯定事實成立，未知項沒有被宣告完成。


### 6. T08-165 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-021950-chatgpt-web-roy-T08-165-base-actor-destructor-ownership.md](../../../kr-temp-roy/20261028-021950-chatgpt-web-roy-T08-165-base-actor-destructor-ownership.md)，原件 Git blob SHA `433e198f0043b2dfbf01918c7586e78b7b4121a6`。
- **可確認的正面主張／caller-callee／data-flow**：0x4C7B90 base cleanup 覆寫主/次 vptr，逐層釋放內部容器、引用區與 slot 物件；與 0x4C8360 pre-remove 是兩套不同工作；base 子物件結束不表示整個 actor 皆已 free。
- **第一手 BIN 證據（VA = raw bytes）**：0x4C7B90=55；0x4C7BBD=c7 03 54 75 c0 00；0x4C7BC3=c7 83 f0 00 00 00 dc 75 c0 00；0x4C7DB4=e8 37 68 2f 00；兩張派生 vtable +0x00 入口可對照
- **原稿自己保留的未知/限制**：完整 lock xadd 成功/異常/跨 thread 不變式、所有 alias 及 allocator 對稱性未獲原生全域證明。
- 裁決：原稿當前限定範圍內的肯定事實成立，未知項沒有被宣告完成。


### 7. T08-166 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-021950-chatgpt-web-roy-T08-166-resource-release-dispatch.md](../../../kr-temp-roy/20261028-021950-chatgpt-web-roy-T08-166-resource-release-dispatch.md)，原件 Git blob SHA `68b81aac071da5e54743228df9b1249e52ccc98e`。
- **可確認的正面主張／caller-callee／data-flow**：0x7BE5F0 取 ESI 指向 DWORD slot，NULL 直接返回；owner+0x60--；資源+0x74/+0x78 分流至 0x7DD1A0 或立即 0x7BE0F0/0x7BD850/0x89120C，處理後清 slot。
- **第一手 BIN 證據（VA = raw bytes）**：0x7BE5F0=8b 06；0x7BE5F9=ff 48 60；0x7BE605=83 78 78 00；0x7BE60F=e8 8c eb 01 00；0x7BE619=c7 06 00 00 00 00
- **原稿自己保留的未知/限制**：NULL 返回的 EAX 未由函式固定、動態資源類別與記憶體安全不宣稱完成。
- 裁決：原稿當前限定範圍內的肯定事實成立，未知項沒有被宣告完成。


### 8. T08-167 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-021950-chatgpt-web-roy-T08-167-two-phase-cleanup-interaction.md](../../../kr-temp-roy/20261028-021950-chatgpt-web-roy-T08-167-two-phase-cleanup-interaction.md)，原件 Git blob SHA `69e583fb29ba194b91b8994631494310554a1383`。
- **可確認的正面主張／caller-callee／data-flow**：0x4C8360 只做有條件 nested release，0x4C7B90 base cleanup 還會清理 outer slots 與物件；兩階段本地存在，但不能推論每個實例均按固定時序執行。
- **第一手 BIN 證據（VA = raw bytes）**：0x4C8365=8b 87 5c 01 00 00；0x4C8377=ff d2；0x4C838C=e8 5f 62 2f 00；0x4C8397=bb 80 00 00 00；0x7BE5F9=ff 48 60
- **原稿自己保留的未知/限制**：重入、外部引用者、所有派生 vtable 和例外路徑未確立。
- 裁決：原稿當前限定範圍內的肯定事實成立，未知項沒有被宣告完成。


### 9. T08-168 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-021950-chatgpt-web-roy-T08-168-lifecycle-verification-boundaries.md](../../../kr-temp-roy/20261028-021950-chatgpt-web-roy-T08-168-lifecycle-verification-boundaries.md)，原件 Git blob SHA `f0053a5f80eccfbebba8dc8030b3aaf1ab32e303`。
- **可確認的正面主張／caller-callee／data-flow**：建立、單 ID 移除、預清理、基底析構、nested release 與 tree erase 的有界跨檔矩陣一致，明示 opcode 登錄、後端決策和執行時完整性缺口。
- **第一手 BIN 證據（VA = raw bytes）**：0x4DFF82=e8 79 f2 34 00；0x4DFBD5=e8 26 f3 34 00；0x4DFC1E=e8 6d 6c 2d 00；0x4C8365=8b 87 5c 01 00 00；0x7BE60F=e8 8c eb 01 00
- **原稿自己保留的未知/限制**：這份是 source-boundary matrix，不宣稱完成整體 Actor 端到端全生命週期。
- 裁決：原稿當前限定範圍內的肯定事實成立，未知項沒有被宣告完成。


### 10. T08-169 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-023349-chatgpt-web-roy-T08-169-branching-release-7dd1a0.md](../../../kr-temp-roy/20261028-023349-chatgpt-web-roy-T08-169-branching-release-7dd1a0.md)，原件 Git blob SHA `47a0f7138ad051d81499fd75e5df9f0372ec536b`。
- **可確認的正面主張／caller-callee／data-flow**：0x7DD1A0 從 stack owner/item 參數採 owner+0x44 signed gate，>=1 走 +0x64 IAT 夾住的 +0x7C vector append，<1 走非空資源的 0x7BD850→0x89120C immediate。
- **第一手 BIN 證據（VA = raw bytes）**：0x7DD1A7=83 7b 44 01；0x7DD1AC=8b 7d 0c；0x7DD1B2=8d 73 64；0x7DD1C2=e8 89 e1 fd ff；0x7DD1D9=e8 72 06 fe ff
- **原稿自己保留的未知/限制**：IAT API 名稱未證；owner 字段不能推成 Actor 的同偏移，尚無實時、并發完整驗證。
- 裁決：原稿當前限定範圍內的肯定事實成立，未知項沒有被宣告完成。


## 關鍵 vtable 原始資料 (KR BIN)

| Table VA | +0x00 | +0x04 | +0x08 | +0x0C | +0x10 | +0x14 |
|---|---|---|---|---|---|---|
| `0xC0C9DC` | `0x4D18D0` | `0x5F5D10` | `0x4CA880` | `0x8DC2F0` | `0x4D1F70` | `0x4D1F80` |
| `0xC0C824` | `0x4D0CA0` | `0x5F5D10` | `0x4CA880` | `0x8DC2F0` | `0x4C8240` | `0x4C8360` |

兩表是由兩個建構流程寫入的實際靜態主 vptr，不推成所有 actor 的可達動態 vptr。對 `0x4DFBC0` 的單次移除，有預清理虛方法 +0x14、帶 flag1 的 +0x00 方法，然後執行 tree node erase；此處不把 `0x7B6890` 當 actor destructor，也不能把 `0x4C8360` 當最終 heap free。

## 重驗命令與下一輪

```sh
sha256sum /mnt/data/Tartaros.bin
python /mnt/data/t01_batch9_audit.py
objdump -d -Mintel --start-address=0x4b28d0 --stop-address=0x4b2b00 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x4b3710 --stop-address=0x4b3750 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x4c7b90 --stop-address=0x4c7db0 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x4c8360 --stop-address=0x4c83c0 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x7be5f0 --stop-address=0x7be654 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x7dd1a0 --stop-address=0x7dd1f0 /mnt/data/Tartaros.bin
```

- 成果：本批 **10 份有界原稿主張 FULL-PASS**；前八批 80 份不同原稿 + 本批 10 份 = **90 份不同檔案**的 document-scope 驗收紀錄，並非 90 條完整遊戲功能鏈。
- 下一批可由 GitHub 歷史 T08-150～159 與其他 Task 的獨立文件入手；需先檢查與本批及更早驗收名單的重複路徑。T08-173、187、196 仍因特定原稿主張衝突未入通過名單。
- 本次只新增 T01 integration 報告，不改其它 Task 原稿、共用 catalog、owner 或 native-complete 狀態。
