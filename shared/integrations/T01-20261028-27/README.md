# T01-20261028-27 — 第八批 10 份原稿 FULL-PASS 獨立驗收

> 本份 FULL-PASS 採用既定的 **document-scope／實際肯定技術主張** 定義：對每份原稿明確已證的原始指令、局部 CFG、資料流與證據界線重新驗證；原稿明示未知、研究計畫、未執行測試**不會**被冒充已完成的遊戲功能。此為 **10 份不同 GitHub 原稿檔案**，不重複 T01-20～26 的前七批 70 份原稿。

## 原件／版本／方法

- 唯讀 KR `Tartaros.bin` 12,472,320 bytes，SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本次直接重新計算。 `.text` VA 0x00401000/raw 0x400；**僅 text** 的 `raw=VA-0x400C00`。
- 本輪新增本機程式 `t01_batch8_audit.py`，經 BIN 原始位元組與 objdump 對照 **80/80 項位址、指令助記符通過，涵蓋 59 個唯一位址**；本地機器可另讀 `t01_batch8_native_evidence.json` 內完整 80 筆逐地址 bytes、指令及運算元。下表已複製關鍵原生 bytes 以供 GitHub 獨立複核。
- GitHub `main` 十份原稿 **10/10 Git blob SHA 再讀一致**；額外從舊提交 `2f164ea7850c13f85b1a5128b5ba2bba6117720e`、`f50fc17495984683176fae4e281c62aa5669c479`、`acba182e48929382ddff91d96004b52aaacc74a5` 確認前批索引未列入的 T08-170～172。原始 markdown、Task owner、共用 catalog 均未改動。
- 使用 `objdump -d -Mintel --start-address ... --stop-address ...` 從正確 PE VA 入口讀上下文，E8 rel32 依 next EIP+signed offset 複核。直接 bytes/局部 CFG 與動態 vtable、不同物件 alias、執行時結果分層，不將 raw byte candidate 當完整可達 CFG。
- 本輪特別重審 **0x82EF00 的整段查找**：`0x82EF20` 比較 node key 進行 lower_bound 步進；`0x82EF3F～0x82EF55` 再比較查詢 key 與 candidate key，較小時返回 sentinel。故 T08-200 所稱 non-sentinel=已存在 key 有原生證據，**撤回此前因「lower_bound 不保證 equality」而對 T08-200 的阻塞理由**。
- T08-173 若把 ECX 寫入值視為外部可變，已被 `0x7B7FFE mov ecx,1` 收窄；T08-187 的 `0x7F6FC1 push 0x30` 亦與 BIN `0x7F6FBF push 0x30` 不符；T08-196 的 owner+0x18 claim 與 `0x4DFC96 lea edi,[eax+8]` 不一致。三份**本批不算 FULL-PASS**。

## 逐份原稿／全部有限肯定主張裁決

### 1. T08-170 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-023349-chatgpt-web-roy-T08-170-nested-collection-cleanup-7be0f0.md](../../../kr-temp-roy/20261028-023349-chatgpt-web-roy-T08-170-nested-collection-cleanup-7be0f0.md)
- Git blob SHA：`592aad324dee70c010dca59b8490aabff09e2528`
- 本份 native checks：**8**。
- **所驗證的肯定主張、caller/callee/資料流**：0x7BE0F0 依 [item+4]..[item+8] 掃描巢狀 node，先經 node+8 payload 的 vtable+8 預清理，再重讀 payload 並條件呼叫 vtable+0(1)，清空 node+8，最後 item+0x74=0。
- **原始 BIN bytes／分支／位址**：0x7BE111 8b5008 → vtable+8；0x7BE114 ffd2；0x7BE121 6a01；0x7BE123 ffd2；0x7BE125 c7460800000000；0x7BE138 c7407400000000
- **保留未知與反證界線**：真實多型目標及 null node 安全前提未解。
- **裁決**：所明確肯定的有界事實均在上述原生位元組與對應局部控制流程內成立；不替 unknown 域背書。


### 2. T08-171 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-023349-chatgpt-web-roy-T08-171-cleanup-and-vector-storage-7bd850-7bb350.md](../../../kr-temp-roy/20261028-023349-chatgpt-web-roy-T08-171-cleanup-and-vector-storage-7bd850-7bb350.md)
- Git blob SHA：`98cf0873fefdb3d11792f5edafd270b10655ad55`
- 本份 native checks：**8**。
- **所驗證的肯定主張、caller/callee/資料流**：0x7BD850 使用 EDI 作 vector 接收者，對非空指標元素呼叫 0x89120C，再處理 backing storage 並清零三指標；0x7BB350 由 EDI 容器、EAX 指向來源元素推入 +7C 暫存區，擴容委派 0x797930。
- **原始 BIN bytes／分支／位址**：0x7BD851 8b5f08；0x7BD867 e8a0390d00；0x7BD886 8bc1 / 0x7BD888 2bc1 → memcpy 長度 0；0x7BD897 e8543a0d00；0x7DD1C2 e889e1fdff→0x7BB350
- **保留未知與反證界線**：不能因此斷言 allocator bug、data race 或 ownership 唯一性。
- **裁決**：所明確肯定的有界事實均在上述原生位元組與對應局部控制流程內成立；不替 unknown 域背書。


### 3. T08-172 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-023349-chatgpt-web-roy-T08-172-ownership-defer-immediate-cross-check.md](../../../kr-temp-roy/20261028-023349-chatgpt-web-roy-T08-172-ownership-defer-immediate-cross-check.md)
- Git blob SHA：`3f6ae14acbc533c822fd49c85a59ec57c920419c`
- 本份 native checks：**8**。
- **所驗證的肯定主張、caller/callee/資料流**：將 actor 樹刪除與 resource slot 釋放隔離；0x7BE5F0 對 owner+0x60--，依 resource+0x74/+0x78 決定 deferred 0x7DD1A0 或 immediate 0x7BE0F0→0x7BD850，且 0x7DD1A0 以 owner+0x44 控制延遲/立即。
- **原始 BIN bytes／分支／位址**：0x7BE5F9 ff4860；0x7BE60F e88ceb0100；0x7BE626 e8c5faffff；0x7BE632 e819f2ffff；0x7DD1A7 837b4401；0x7DD1C2 e889e1fdff
- **保留未知與反證界線**：原稿明列 drain 時機、IAT 真名、runtime 不完整，維持未知。
- **裁決**：所明確肯定的有界事實均在上述原生位元組與對應局部控制流程內成立；不替 unknown 域背書。


### 4. T08-184 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-184-0007-scene-actor-resource-ownership-interface.md](../../../kr-temp-roy/20261028-100222-chatgpt-web-roy-T08-184-0007-scene-actor-resource-ownership-interface.md)
- Git blob SHA：`55058a01ad35dc4f01c49ab781780e556ef506ee`
- 本份 native checks：**8**。
- **所驗證的肯定主張、caller/callee/資料流**：actor registry 0x4DFF30/0x4DFBC0/0x4DFE90 與資源 acquire/release 0x7DCFB0/0x7BE5F0/0x7DD1F0 為兩個層級；定位局部 component cleanup→release，但不宣稱 actor tree node 與 manager owner 同一指標。
- **原始 BIN bytes／分支／位址**：0x4DFF5F e89cef3400→0x82EF00；0x4DFF82 e879f23400→0x82F200；0x4DFBD5 e826f33400；0x4DFC1E e86d6c2d00；0x7BE60F e88ceb0100
- **保留未知與反證界線**：完整 actor→component→wrapper→resource→owner 指標 provenance 尚待解決。
- **裁決**：所明確肯定的有界事實均在上述原生位元組與對應局部控制流程內成立；不替 unknown 域背書。


### 5. T08-188 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-101203-chatgpt-web-roy-T08-188-actor-registry-and-resource-lifetime-gap.md](../../../kr-temp-roy/20261028-101203-chatgpt-web-roy-T08-188-actor-registry-and-resource-lifetime-gap.md)
- Git blob SHA：`115bbbf2b6005d2920cc46f606763c3ff8b8d687`
- 本份 native checks：**8**。
- **所驗證的肯定主張、caller/callee/資料流**：0x4DFF30 key 查找/樹插入不直接 drain；0x4DFBC0 key 查找後 callback/0x7B6890 erase；0x4C838C 的 component 釋放經 0x7BE5F0 到 0x7DD1A0，但不是所有 actor 的共同 destructor。
- **原始 BIN bytes／分支／位址**：0x4DFF5F e89cef3400；0x4DFF82 e879f23400；0x4DFC1E e86d6c2d00；0x4C838C e85f622f00；0x7BE5F9 ff4860；0x7BE60F e88ceb0100
- **保留未知與反證界線**：尚未閉合各派生 actor 實例與 pool owner 的同一性。
- **裁決**：所明確肯定的有界事實均在上述原生位元組與對應局部控制流程內成立；不替 unknown 域背書。


### 6. T08-190 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-190-resource-counter-acquire-release-balance.md](../../../kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-190-resource-counter-acquire-release-balance.md)
- Git blob SHA：`a633fc34c161afd168b74ba1f35a6fcf3fd17c33`
- 本份 native checks：**8**。
- **所驗證的肯定主張、caller/callee/資料流**：acquire 0x7DCFB0 在鎖 +0x64 前 inc owner+0x60，非空 pop/0x7BE5B0，空則 alloc 0x7C；release 0x7BE5F0 dec owner+0x60；與 manager+0x5C 不同。
- **原始 BIN bytes／分支／位址**：0x7DCFB7 8b5d08；0x7DCFBA ff4360；0x7DCFBF 8d7b64；0x7DCFDF e8cc15feff；0x7DD011 6a7c；0x7DD013 e850420b00；0x7BE5F9 ff4860
- **保留未知與反證界線**：不推論配置失敗/NULL 時計數總是平衡，不宣稱所有呼叫同步。
- **裁決**：所明確肯定的有界事實均在上述原生位元組與對應局部控制流程內成立；不替 unknown 域背書。


### 7. T08-191 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-191-wrapper-binding-registry-integration.md](../../../kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-191-wrapper-binding-registry-integration.md)
- Git blob SHA：`728bf5f312d0959def19e48b53bc3f25cd28a478`
- 本份 native checks：**8**。
- **所驗證的肯定主張、caller/callee/資料流**：0x7F6FBA 周邊建立 0x30 wrapper、由 0x7DCFB0 取得 0x7C resource 並存 wrapper+0x2C；mode gate 0x7DD0E4 只在新資源分支才可觸發 0x7BDF90 binding；0x7BE0F0 是解除巢狀 payload 的不同入口。
- **原始 BIN bytes／分支／位址**：0x7F6FBF 6a30；0x7F6FC3 e8a0a20900→0x891268；0x7F6FDC e8cf5ffeff→0x7DCFB0；0x7F6FEA c706cc11c500；0x7F700B 89462c；0x7DD0EC e89f0efeff
- **保留未知與反證界線**：此原稿使用『0x7F6FBA 周邊』正確；勿與 **T08-187 把 0x7F6FC1 誤記為 push 0x30** 混淆。
- **裁決**：所明確肯定的有界事實均在上述原生位元組與對應局部控制流程內成立；不替 unknown 域背書。


### 8. T08-192 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-192-0007-actor-component-release-crosscheck.md](../../../kr-temp-roy/20261028-102919-chatgpt-web-roy-T08-192-0007-actor-component-release-crosscheck.md)
- Git blob SHA：`b94d840de16d8b1d6b43d9132993b52b8ca03175`
- 本份 native checks：**8**。
- **所驗證的肯定主張、caller/callee/資料流**：actor 0x4DFF30 16-bit key 與 0x4DFBC0 刪除樹節點；0x4C86DA→0x4C83C0 component 清理、0x4C838C→0x7BE5F0 提供局部資源 release 連結；不是全體 actor 必然 drain 的證據。
- **原始 BIN bytes／分支／位址**：0x4DFF4C 0fb74704；0x4DFF5F e89cef3400；0x4DFBD5 e826f33400；0x4C86DA e8e1fcffff；0x4C838C e85f622f00；0x7BE60F e88ceb0100
- **保留未知與反證界線**：actor+0xF4 components 真正 vptr、wrapper+0x2C resource identity 及 owner graph 未解。
- **裁決**：所明確肯定的有界事實均在上述原生位元組與對應局部控制流程內成立；不替 unknown 域背書。


### 9. T08-200 — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-200-registration-identity-and-duplicate.md](../../../kr-temp-roy/20261028-111046-chatgpt-web-roy-T08-200-registration-identity-and-duplicate.md)
- Git blob SHA：`6f867a929563e531a09342c2e0cecafb8d6baf44`
- 本份 native checks：**8**。
- **所驗證的肯定主張、caller/callee/資料流**：0x4DFF4C movzx WORD [actor+4] 取主 key；0x4DFF5F 用 0x82EF00 回傳精確 key 命中或 sentinel；只有 sentinel→0x82F200 插入，非 sentinel→0x6EDB60 訊息分支，不觀察到在這兩條本地分支直接 replace/free 新 actor。
- **原始 BIN bytes／分支／位址**：0x4DFF4C 0fb74704；0x4DFF67 3b530c；0x4DFF82 e879f23400；0x4DFF99 e8c2db2000；**0x82EF20 39790c；0x82EF41 3b720c；0x82EF44 720f**
- **保留未知與反證界線**：**更正 T01-23～26 舊阻塞**：0x82EF00 先 lower_bound，再用 `cmp key,[node+0x0C]; jb sentinel` 篩除不相等，確有精確等值查詢；新 actor 上游分配與 runtime 後果仍未知。
- **裁決**：所明確肯定的有界事實均在上述原生位元組與對應局部控制流程內成立；不替 unknown 域背書。


### 10. T16-44 (08:59) — FULL-PASS (document-scoped)
- 原稿：[kr-temp-roy/20261028-085929-chatgpt-web-roy-T16-44-KR-quest-state-authority-and-acceptance.md](../../../kr-temp-roy/20261028-085929-chatgpt-web-roy-T16-44-KR-quest-state-authority-and-acceptance.md)
- Git blob SHA：`c7d68207f95fd2ceb1d9ad8cbe4d5410e04e8f41`
- 本份 native checks：**8**。
- **所驗證的肯定主張、caller/callee/資料流**：此份是 client-side resource provenance 對 server 任務狀態五階段 request/validate/write/notify/restore 的**驗收缺口契約**；有 Lua loader、Quest reader 入口與 T01-06 靜態資源稽核，並清楚聲明 Quest16 完成／Quest15 可接與重登恢復尚未通過。
- **原始 BIN bytes／分支／位址**：0x4A8A60 55；0x4A8A94 e8b7ad3700；0x4A8A36 e815c02400→0x6F4A50；0x4A8A46 e885c32400→0x6F4DD0；0x5043E9 e852030000→0x504740；0x5043EF e87c110000→0x505570
- **保留未知與反證界線**：原稿中的測試矩陣**尚未執行**；只驗其有界證據和未證實判定，不視為任務完成。與此前 09:51 版不同 Git blob/file。
- **裁決**：所明確肯定的有界事實均在上述原生位元組與對應局部控制流程內成立；不替 unknown 域背書。


## 附加原生校正與重要守則

```asm
004dff4c: 0f b7 47 04       movzx eax,WORD PTR [edi+4]
004dff5f: e8 9c ef 34 00    call  0x82ef00
004dff67: 3b 53 0c          cmp   edx,DWORD PTR [ebx+0xc]
004dff6a: 75 24             jne   0x4dff90
004dff82: e8 79 f2 34 00    call  0x82f200
004dff99: e8 c2 db 20 00    call  0x6edb60
0082ef20: 39 79 0c          cmp   DWORD PTR [ecx+0xc],edi
0082ef41: 3b 72 0c          cmp   esi,DWORD PTR [edx+0xc]
0082ef44: 72 0f             jb    0x82ef55
0082ef55: 89 4d fc          mov   DWORD PTR [ebp-4],ecx
007be111: 8b 50 08          mov   edx,DWORD PTR [eax+8]
007be114: ff d2             call  edx
007be121: 6a 01             push  1
007be123: ff d2             call  edx
007be125: c7 46 08 00 00 00 00 mov DWORD PTR [esi+8],0
007bd886: 8b c1             mov   eax,ecx
007bd888: 2b c1             sub   eax,ecx
007dcfba: ff 43 60          inc   DWORD PTR [ebx+0x60]
007be5f9: ff 48 60          dec   DWORD PTR [eax+0x60]
```

所有上述 bytes 與源碼對照只支持有限的局部資料流，**不**證明遊戲已安全處理每個 allocation failure、間接 virtual destructor、並發 race、Quest server 持久化或完整 actor 生命週期。

## 本次狀態與交接

- 新增 **10/10 document-scope FULL-PASS**：T08-170, T08-171, T08-172, T08-184, T08-188, T08-190, T08-191, T08-192, T08-200, T16-44 (08:59)。前七批共 70 個路徑，本次 10 個全新原稿路徑 → **累計 80 份不同檔案**；段號如 T16-44 有多版本，不等於 80 個不同段號。
- 本批解除 T08-200 舊誤判；T08-173/187/196 保留具體衝突，須由原稿修正後重新驗收，禁止將 T01-27 驗收回填成所有 Task 的 native_complete。
- 下一批建議改從 GitHub 其他已提交但 T01-07 未列的較早原稿繼續，先取得原稿/commit SHA 再 BIN-first。
- 本次僅新增 T01 integration 驗收文檔，沒有覆蓋其他 Task 檔案或共用 status。
