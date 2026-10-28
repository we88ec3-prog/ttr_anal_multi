# T01-20261028-23 — 第四批連續驗收 10 份 FULL-PASS（原稿肯定且有界主張）

## 審查前提

- 新增 10 份，**不重複**前三批 T01-20/21/22 的 30 份。FULL-PASS 的單位是原稿自己**明確肯定且範圍有限的技術主張**，不是 T08/T10 遊戲完整功能 native_complete；原稿已列 unknown/下一段/動態證據缺失一律保留。
- KR 原件 `/mnt/data/Tartaros.bin` SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`、`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`，本次直接讀原件重算一致；唯讀、不執行。
- PE .text 映射 VA 0x00401000，raw=0x400，地址轉換 `raw=VA-0x400C00`。本輪以 Python 實際讀取以上 10 份的 45 條**明確位址/bytes 斷言**，經修正一項審核腳本手動填入錯誤後 **45/45 真實 BIN 一致**。錯誤是最初將 0x4A14A5 的 `add eax,0xFB8834` 寫成 `add eax,0`，BIN 實際 bytes `05 34 88 FB 00`；原稿原本記載是正確的。直接 E8 的 next-EIP+rel32 目標亦重算。
- Source blob SHA 全部重新向 GitHub main 取得，符合 T01-07 先前清單。KeyMapping Type0 的 MapButton13..16=Key44..47 另從官方 KR 資源原件 `kr/evidence/6194d2ff4b51eacfb64b03698a10dfea57041b2e714de9a762ea139fffe82b18.txt`（Git blob `cb8a9da734567b10e37cc966a981300cb3e7b8bc`）交叉查證；Type1 基本表 MapButton13..16=Key36..39，不能混同。
- 篩選時另檢查 T08-196、T08-200，**未將其列為 FULL-PASS**：T08-196 將 0x4DFC90 關聯至次級 owner+0x18 的說法需要和該函式 `lea edi,[eax+8]` 調和；T08-200 以查得 non-sentinel 即重複 key 的說法受 `0x82EF00` lower_bound、未見精確 equality check 所限，不能直接採認。這是實質反證稽核，不為數量取消。
- 下列「原生已確認」僅限具體指令、明確局部 CFG 分支與資料欄位來源。未取得的 opcode 伺服器權威、動態 vtable 目標、設備輸入 producer、動作/連段完整鏈不因本批通過升級。

## 10 份逐稿裁決／資料流／指令證據

### 1. T10-082 — FULL-PASS (document-scope)
- **原稿**：[kr-temp-roy/20261028-094926-chatgpt-web-roy-T10-082-keymapping-runtime-xrefs.md](../../../kr-temp-roy/20261028-094926-chatgpt-web-roy-T10-082-keymapping-runtime-xrefs.md)；Git blob SHA `4a3f3028ffc003883430eaf88c70852cc6314ab4`。
- **肯定主張／必要 caller-callee-CFG／資料流**：0x6D4DC0 的 mode/MapButton 實參與 ID-domain gate；0x5961C0 經 0x6D4CE0 讀 phase 分派 +EC/+F0；Type0 XML 13..16=44..47，Type1 基本表 13..16=36..39。
- **獨立 BIN 驗證**：0x6D4DE8 8b450c、0x6D4DEB 8b5d08、0x6D4DF6 81f90e270000、0x59624E e88dea1300；XML 原件 Git blob cb8a9da734567b10e37cc966a981300cb3e7b8bc。
- **尚未知／禁止外推**：不推定 DirectInput producer、真實目前配置、actor motion 或 queue；vtable 動態實作 unknown。
- **裁決**：全文中此主題已肯定、可原生校驗的有界主張通過；仍待研究的項目不假裝完成。


### 2. T10-083 — FULL-PASS (document-scope)
- **原稿**：[kr-temp-roy/20261028-095434-chatgpt-web-roy-T10-083-working-bank-configuration.md](../../../kr-temp-roy/20261028-095434-chatgpt-web-roy-T10-083-working-bank-configuration.md)；Git blob SHA `3097b2d57a62703d31bb59409283ac4e00becf33`。
- **肯定主張／必要 caller-callee-CFG／資料流**：三組 0x280 bank；0x4A1440 mode0/1 對 bank2 複製、0x6D0D10 外部資料配對回填工作 bank2；沒有將 bank2 當 XML Type2。
- **獨立 BIN 驗證**：0x4A1493 8b4508、0x4A149A 83f801、0x4A14A2 c1e007、0x4A14A5 053488fb00；0x4A14AB push 0xFB8D34；0x6D1AB4 寫 [0xFB9030]。
- **尚未知／禁止外推**：外部檔名及完整保存 writer、runtime Key45 fallback 和 controller 行為 unknown。
- **裁決**：全文中此主題已肯定、可原生校驗的有界主張通過；仍待研究的項目不假裝完成。


### 3. T10-084 — FULL-PASS (document-scope)
- **原稿**：[kr-temp-roy/20261028-095435-chatgpt-web-roy-T10-084-phase-dispatch-boundaries.md](../../../kr-temp-roy/20261028-095435-chatgpt-web-roy-T10-084-phase-dispatch-boundaries.md)；Git blob SHA `91fcdcce12d14724648650829e971a380be25ecf`。
- **肯定主張／必要 caller-callee-CFG／資料流**：0x596245 將 loop ID EDI 提供 ESI 給 0x6D4CE0；0xFB73E8 非零時此函式只讓 ID13/14 繼續；phase 1/3 對應 vtable +EC/+F0。
- **獨立 BIN 驗證**：0x596245 8bf7；0x59624E e88dea1300→0x6D4CE0；0x596259 83ff0d、0x59625E 83ff0e；0x596275 8b82ec000000；0x5962CE 8b82f0000000。
- **尚未知／禁止外推**：非零 phase writer、動態覆寫目標、動畫/連段未證，不外推成全遊戲停用 ID15/16。
- **裁決**：全文中此主題已肯定、可原生校驗的有界主張通過；仍待研究的項目不假裝完成。


### 4. T10-085 — FULL-PASS (document-scope)
- **原稿**：[kr-temp-roy/20261028-100335-chatgpt-web-roy-T10-085-phase-reset-and-event-map.md](../../../kr-temp-roy/20261028-100335-chatgpt-web-roy-T10-085-phase-reset-and-event-map.md)；Git blob SHA `cf1906f0c6f6d09846d1aefc45736d0f6eb1d706`。
- **肯定主張／必要 caller-callee-CFG／資料流**：0x6D4A30 對十個連續 DWORD 清零而非建立 phase 1/3；special ID 門檻以 0x2711、0x270E 運算區分；普通 ID 消除 byte[FB9004+ID]；0x6D4CE0 兩域讀者。
- **獨立 BIN 驗證**：0x6D4A93 33c0、0x6D4A9C a30490fb00、0x6D4C23 8d8eefd8ffff、0x6D4CAE c6860490fb0000；其餘 9 個 DWORD 清零連續位址 0x6D4AA1..0x6D4AC9。
- **尚未知／禁止外推**：裝置事件 producer/phase 非零 writer unknown；不把 reset 函式當發生事件的來源。
- **裁決**：全文中此主題已肯定、可原生校驗的有界主張通過；仍待研究的項目不假裝完成。


### 5. T10-086 — FULL-PASS (document-scope)
- **原稿**：[kr-temp-roy/20261028-100335-chatgpt-web-roy-T10-086-fb73e8-transition.md](../../../kr-temp-roy/20261028-100335-chatgpt-web-roy-T10-086-fb73e8-transition.md)；Git blob SHA `c5290e18160287e2e77ea430b4b26697fcac6b3f`。
- **肯定主張／必要 caller-callee-CFG／資料流**：0x560239 是由 xor ebx,ebx 來源決定的零初始化；0x5A4614 比對全域並經 0x5A55E0 在 mode1/2 更新狀態；此旗標亦被 0x5961C0 查詢。
- **獨立 BIN 驗證**：0x560197 33db；0x560239 891de873fb00；0x5A4614 391de873fb00；0x5A4631 e8aa0f0000→0x5A55E0；0x5A4666 e8750f0000→0x5A55E0。
- **尚未知／禁止外推**：全域間接 nonzero writer 未找到，不能從讀者推成特定攻擊或姿態旗標。
- **裁決**：全文中此主題已肯定、可原生校驗的有界主張通過；仍待研究的項目不假裝完成。


### 6. T10-087 — FULL-PASS (document-scope)
- **原稿**：[kr-temp-roy/20261028-100335-chatgpt-web-roy-T10-087-dispatch-consumer.md](../../../kr-temp-roy/20261028-100335-chatgpt-web-roy-T10-087-dispatch-consumer.md)；Git blob SHA `161febaa46a936da40588783860ef904b0e620cf`。
- **肯定主張／必要 caller-callee-CFG／資料流**：0x5961C0 的 phase 處理、0x761010 selector；vtable +EC/+F0 與配置查詢 0x6D4DC0 是不同介面；這段不能自己生成完整 controller/motion 因果。
- **獨立 BIN 驗證**：0x5961ED 8bc3、0x5961EF e81cae1c00→0x761010、0x59624E e88dea1300→0x6D4CE0、0x596275 8b82ec000000、0x5962CE 8b82f0000000。
- **尚未知／禁止外推**：其它配置 caller 未逐個被命名 runtime attack，原稿明列待追。
- **裁決**：全文中此主題已肯定、可原生校驗的有界主張通過；仍待研究的項目不假裝完成。


### 7. T10-088 — FULL-PASS (document-scope)
- **原稿**：[kr-temp-roy/20261028-100335-chatgpt-web-roy-T10-088-producer-gap-and-next.md](../../../kr-temp-roy/20261028-100335-chatgpt-web-roy-T10-088-producer-gap-and-next.md)；Git blob SHA `54a205919cb7cbb180610439067aa85eef1815c9`。
- **肯定主張／必要 caller-callee-CFG／資料流**：前段已證資料流的邊界總表：兩種 caller 傳給 0x6D4A30 的不同容器／參數，reset≠非零 writer；Z/V combo timer 不可用 AI 參數代替。
- **獨立 BIN 驗證**：0x490DEF 0fb605faadfa00、0x490DFC e82f3c2400→0x6D4A30、0x58A5EF 8936、0x58A607 e824a41400→0x6D4A30；Type0 原始 XML 13..16→44..47。
- **尚未知／禁止外推**：此文件是證據缺口矩陣，不宣稱已完成 input producer→motion 鏈。
- **裁決**：全文中此主題已肯定、可原生校驗的有界主張通過；仍待研究的項目不假裝完成。


### 8. T08-197 — FULL-PASS (document-scope)
- **原稿**：[kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-197-secondary-tree-key-removal.md](../../../kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-197-secondary-tree-key-removal.md)；Git blob SHA `4812aa8da49c40647538206679b414753a4c6e5e`。
- **肯定主張／必要 caller-callee-CFG／資料流**：次級樹入口 0x4DFC30 使用 owner+0x18，經 0x8438C0 查找；若 owner+0xF8 快取 payload key 相等則清零，node+0x10 payload 是 direct allocator free，無主 actor vtable 預清理；隨後 0x7B6890 tree erase。
- **獨立 BIN 驗證**：0x4DFC39 8d5e18、0x4DFC42 e8793c3600→0x8438C0、0x4DFC4F 8b86f8000000、0x4DFC72 e895153b00→0x89120C、0x4DFC80 e80b6c2d00→0x7B6890。
- **尚未知／禁止外推**：兩棵樹 payload type、共享同一 actor 與防 double-free 均 unknown；原稿未稱其已解。
- **裁決**：全文中此主題已肯定、可原生校驗的有界主張通過；仍待研究的項目不假裝完成。


### 9. T08-198 — FULL-PASS (document-scope)
- **原稿**：[kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-198-conditional-type-removal.md](../../../kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-198-conditional-type-removal.md)；Git blob SHA `0a143c3b3a9fa33976e536dc03848041dcd15ec1`。
- **肯定主張／必要 caller-callee-CFG／資料流**：0x4DFD40 的 actor 條件 predicate 先從 actor+4 以 byte 讀並與入參 16-bit 比對，低位型別只走值 0/1/6/7；後續檢查 actor+0x15C、+0x370 並在條件路徑呼叫下游清理。
- **獨立 BIN 驗證**：0x4DFD73 0fb65004、0x4DFD77 663b5508、0x4DFD87 0fb74704、0x4DFD9B 8b875c010000、0x4DFDC9 e8f27e2c00→0x7A7CC0。
- **尚未知／禁止外推**：0/1/6/7 不能命名官方怪物分類；child vptr 真正類型與 runtime 生命週期未知。
- **裁決**：全文中此主題已肯定、可原生校驗的有界主張通過；仍待研究的項目不假裝完成。


### 10. T08-199 — FULL-PASS (document-scope)
- **原稿**：[kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-199-bulk-removal-sentinel.md](../../../kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-199-bulk-removal-sentinel.md)；Git blob SHA `195f91121f21352ad2b8f26d16fb534ce4d84a09`。
- **肯定主張／必要 caller-callee-CFG／資料流**：0x4DFE90 使用主索引 sentinel 遍歷 actor，vtable+0x14→vtable+0x00(1)，後呼叫 0x823850 清樹，再對 FBA7A4 全域物件 vtable+0x14 回呼；不同於逐節點 erase。
- **獨立 BIN 驗證**：0x4DFE94 8b5d08、0x4DFEA2 8b7e10、0x4DFEB0 ffd2、0x4DFEBA ffd2、0x4DFF0A e841393400→0x823850、0x4DFF1A ffd2。
- **尚未知／禁止外推**：全域 callback 身分、其它 actor 派生型別及並發語義未命名。
- **裁決**：全文中此主題已肯定、可原生校驗的有界主張通過；仍待研究的項目不假裝完成。


## 可重現與後續

```bash
sha256sum /mnt/data/Tartaros.bin /mnt/data/Tartaros.exe
objdump -d -Mintel --start-address=0x6d4de8 --stop-address=0x6d4e20 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x4a1490 --stop-address=0x4a14b6 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x596245 --stop-address=0x5962dc /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x4dfc30 --stop-address=0x4dfd39 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x4dfd40 --stop-address=0x4dfe90 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x4dfe90 --stop-address=0x4dff23 /mnt/data/Tartaros.bin
```

- **本批 SUCCESS**：T10-082/083/084/085/086/087/088 + T08-197/198/199，共 10 份 doc-scope FULL-PASS；三批先前報告加本批共 40 份不同原稿有審核報告。
- **未列本批的候選仍待驗**：T08-196/200 優先解決前述與 BIN 的矛盾；T08-173..192 的 actor/resource ownership 仍應全主張重檢；T10 的非零 phase writer/動態回呼與 action motion 仍沒完成。
- **協作**：只新增 T01 自有驗收檔，不改所有者原稿、不改全域 catalog/owner 或 task-level native_complete。若後續原稿修改，須以新 blob SHA 重新稽核。
