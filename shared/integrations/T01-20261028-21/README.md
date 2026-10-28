# T01-20261028-21 — 連續驗收下一批 10 份 FULL-PASS（原稿主張限定）

> 本批依照使用者指示，在上一批 T01-20261028-20 的 10 份之外，新增 **10 份不同原稿的 FULL-PASS**。這裡 FULL-PASS 的單位僅是**原稿內明確肯定、限定於其自身主題的技術主張**，並不等於 Task 的 gameplay、所有外部動態目標或完整 client/server 行為都已證實。每份原稿原先明列的 unknown / limitations 保留，無來源時不得補猜。

## 基準與重新驗證

- 來源：KR `Tartaros.bin`，本輪本地直接重算 SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`Tartaros.exe` SHA256 `03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f`。均與原始研究版一致；不執行程式、無修改任何原件。
- PE32/i386 `.text` VA `0x401000`、raw `0x400`；text 內 `raw = VA - 0x400C00`；其他 section 需個別映射。
- 透過 `objdump -d -Mintel --start-address=... --stop-address=...` 重新核對重要完整函式視窗。以 Python raw-byte assertions 重驗 **78/78 指令位置／位元組相符**，所有以 `E8 rel32` 列出的直接呼叫均重算目的地；另對 `[0xFB73E8]` literal `e873fb00` 全段掃描共 **18 處**，與 T10-099 逐項一致。
- 稽核時發現兩處手動撰寫的**預期位移**錯誤，已先依原始 BIN 更正檢查式：`0x59635F e89c731b00→0x74D700`、`0x59615A e8a18d2900→0x82EF00`。這是審核檢查式的更正，不是原始研究原稿錯誤；沒有把不符樣本忽略。
- GitHub 逐份重新 `fetch_file`，下表 10 份原稿的 Git blob SHA 與既有 T01-07 一致。KR KeyMapping XML 原件另外從 `kr/evidence/6194d2ff4b51eacfb64b03698a10dfea57041b2e714de9a762ea139fffe82b18.txt` 讀取（blob `cb8a9da734567b10e37cc966a981300cb3e7b8bc`）：Type0 的 MapButton13～16 = Key44～47、ModKey=0，**同檔其他 Type 的配置不應當作 Type0**。
- 本次沒有將 raw-byte xrefs 提升成已知 dynamic caller／writer，沒有把按鍵配置證據提升為動作與連段，沒有把 Lua callback 直接當成原版 Server 封包／結果，也不修改他人原稿、Task owner、catalog。

## 十份原稿逐項裁決

### 1. T10-092 — FULL-PASS（文件肯定主張限定）
- 原稿：[kr-temp-roy/20261028-101100-chatgpt-web-roy-T10-092-mapping-consumer-domain.md](../../../kr-temp-roy/20261028-101100-chatgpt-web-roy-T10-092-mapping-consumer-domain.md)；Git blob SHA `4902528ed87c5ecfc0477cb248794ea1bd937f4c`。
- **肯定主張逐項驗證：** (a) 0x5CD67A push2、0x5CD67C push16、0x5CD68A call 0x6D4DC0；(b) 0x650E86 push2、0x650E88 push0x2904、0x650E96 call 0x6D4DC0；(c) 呼叫後皆有 vector/string 後處理 0x402160；不直接推定 attack opcode。
- **第一手 BIN／資料原件證據：** 0x5CD67A=6a02, 0x5CD67C=6a10, 0x5CD68A=e831771000; 0x650E86=6a02, 0x650E88=6804290000, 0x650E96=e8253f0800。
- **限制與反證邊界：** XML 類型及角色 runtime input 未確認；原稿本身並未宣稱完整 motion。
- **裁決：** `FULL-PASS (document-scope)`。只採認原稿明確限定的可直接驗證結論，不把待辦／未知列為已證。


### 2. T10-093 — FULL-PASS（文件肯定主張限定）
- 原稿：[kr-temp-roy/20261028-103000-chatgpt-web-roy-T10-093-reset-branch-and-parameters.md](../../../kr-temp-roy/20261028-103000-chatgpt-web-roy-T10-093-reset-branch-and-parameters.md)；Git blob SHA `886c94170e3a83f5161c6df9608f2c874f6b3dee`。
- **肯定主張逐項驗證：** (a) 兩 caller 使用不同實參容器：0x490DFC 使用全域 byte 與 0xF95CD8；0x58A607 使用自鏈暫時節點；(b) 0x6D4A5B 檢查 [ebp+8] 低 byte，0 值走 0x6D4B0A；(c) 0x6D4A93/0x6D4B69 均 xor eax,eax，對 phase 連續清零；(d) lazy guards 限制初始化不是每 frame 推論。
- **第一手 BIN／資料原件證據：** 0x490DEF=0fb605faadfa00; 0x490DFC=e82f3c2400; 0x58A5EF=8936; 0x58A607=e824a41400; 0x6D4A5B=807d0800; 0x6D4A62=0f84a2000000; 0x6D4A93/0x6D4B69=33c0; 0x6D4A9C=a30490fb00。
- **限制與反證邊界：** 全域 ID producer、非零 phase writer 與執行頻率未被原稿當成已證實。
- **裁決：** `FULL-PASS (document-scope)`。只採認原稿明確限定的可直接驗證結論，不把待辦／未知列為已證。


### 3. T10-094 — FULL-PASS（文件肯定主張限定）
- 原稿：[kr-temp-roy/20261028-103000-chatgpt-web-roy-T10-094-phase-dispatch-fallback.md](../../../kr-temp-roy/20261028-103000-chatgpt-web-roy-T10-094-phase-dispatch-fallback.md)；Git blob SHA `f5534c77d75aab81b72a448c0901ec552a29a364`。
- **肯定主張逐項驗證：** (a) 先讀 phase，再檢查非零 0xFB73E8 下 ID13/14 gate；(b) phase1 先 candidate vtable+0xEC，失敗後 listener helper 0x596140，再 caller vtable+0xEC；(c) phase3 先 candidate +0xF0、再經 bucket/其他 listener +0xF0；非對稱早停。
- **第一手 BIN／資料原件證據：** 0x59624E=e88dea1300; 0x596259=83ff0d; 0x59625E=83ff0e; 0x596267=83f801; 0x596275=8b82ec000000; 0x59629D=e89efeffff; 0x5962BC=83f803; 0x5962CE=8b82f0000000; 0x5962FB=e8008c2900; 0x596325=8b82f0000000。
- **限制與反證邊界：** 不將 listener handled 說成真正 gameplay action 或 Z/V 連段。
- **裁決：** `FULL-PASS (document-scope)`。只採認原稿明確限定的可直接驗證結論，不把待辦／未知列為已證。


### 4. T10-095 — FULL-PASS（文件肯定主張限定）
- 原稿：[kr-temp-roy/20261028-103000-chatgpt-web-roy-T10-095-mode-subobject-routing.md](../../../kr-temp-roy/20261028-103000-chatgpt-web-roy-T10-095-mode-subobject-routing.md)；Git blob SHA `1049f0f0c409d202a552ef35c673051fc0527f89`。
- **肯定主張逐項驗證：** (a) 0x5A4614 的全域 gate 與 mode writer 0x5A55E0；(b) 0x5A5760 mode 1→owner+0x140，mode 2→+0x148，其他提前返回；(c) 子物件四個欄位差量修正後 call 0x746F70；(d) 0x5A57A0 同模式規則 call vtable+0xB4，EDX 常數 0x66 不能當 action opcode。
- **第一手 BIN／資料原件證據：** 0x5A4614=391de873fb00; 0x5A4631=e8aa0f0000; 0x5A4651=e84a110000; 0x5A5767=8bb158010000; 0x5A5773=8b8948010000; 0x5A577B=8b8940010000; 0x5A5793=e8d8171a00; 0x5A57B5/0x5A57C7=8b90b4000000。
- **限制與反證邊界：** dynamic vtable implementer/owner 類型/角色 motion 未宣稱已確立。
- **裁決：** `FULL-PASS (document-scope)`。只採認原稿明確限定的可直接驗證結論，不把待辦／未知列為已證。


### 5. T10-096 — FULL-PASS（文件肯定主張限定）
- 原稿：[kr-temp-roy/20261028-103000-chatgpt-web-roy-T10-096-evidence-closure-and-next.md](../../../kr-temp-roy/20261028-103000-chatgpt-web-roy-T10-096-evidence-closure-and-next.md)；Git blob SHA `951336b952cd2bbf7bf19fa01eb6e31177027ea3`。
- **肯定主張逐項驗證：** (a) 對已有研究的有界矩陣：Type0 XML MapButton13..16 對 Key44..47；(b) 0x6D4CE0 ID<=39 以 byte[0xFB9004+ID] 讀 phase；(c) 0x5961C0 phase1/3 實際調 vtable+0xEC/+0xF0；(d) 0x5A5760 mode 子物件路由；明確將完整 combo、nonzero phase writer 列未知。
- **第一手 BIN／資料原件證據：** KR XML 原件 kr/evidence/6194d2ff4b51eacfb64b03698a10dfea57041b2e714de9a762ea139fffe82b18.txt (blob cb8a9da734567b10e37cc966a981300cb3e7b8bc)；0x6D4D93=83fe27; 0x6D4D98=0fb6860490fb00; 0x59624E=e88dea1300; 0x596275=8b82ec000000; 0x5962CE=8b82f0000000; 0x5A5767=8bb158010000。
- **限制與反證邊界：** 此文為證據矩陣，完整 key->device->motion 邊不主張閉合。
- **裁決：** `FULL-PASS (document-scope)`。只採認原稿明確限定的可直接驗證結論，不把待辦／未知列為已證。


### 6. T10-097 — FULL-PASS（文件肯定主張限定）
- 原稿：[kr-temp-roy/20261028-1102-chatgpt-web-roy-T10-097-dispatch-success-result-list.md](../../../kr-temp-roy/20261028-1102-chatgpt-web-roy-T10-097-dispatch-success-result-list.md)；Git blob SHA `4384b7604b9ece90d765978d426192585a383000`。
- **肯定主張逐項驗證：** (a) 0x596351 取得 caller 給定的結果容器；(b) 0x59635F call 0x74D700，配置 0x0C 節點並用三實參初始化；(c) 計數上限檢查後增 count 並連到前後鏈；(d) 此為回呼成功結果 list，不是已確立的普攻 combo queue。
- **第一手 BIN／資料原件證據：** 0x596351=8b5d08; 0x59635F=e89c731b00 (rel32→0x74D700, 注意非 e89c732000); 0x596377=41; 0x59637E=894604; 0x74D706=6a0c; 0x74D708=e85b3b1400; 0x74D71A=8908; 0x74D730=c20c00。
- **限制與反證邊界：** 結果容器後續 consumer、元素生命週期與 motion 未宣稱已解。
- **裁決：** `FULL-PASS (document-scope)`。只採認原稿明確限定的可直接驗證結論，不把待辦／未知列為已證。


### 7. T10-098 — FULL-PASS（文件肯定主張限定）
- 原稿：[kr-temp-roy/20261028-1102-chatgpt-web-roy-T10-098-child-selector-and-listener-buckets.md](../../../kr-temp-roy/20261028-1102-chatgpt-web-roy-T10-098-child-selector-and-listener-buckets.md)；Git blob SHA `868aa5369cb5c062dbe13dccaaeed7cc7da71f91`。
- **肯定主張逐項驗證：** (a) 0x761010 selector 按 bit19==0、bit8==1、bit12==0 返回 node+8，不符則走下一個節點或 NULL；(b) 0x596140 listener bucket 依 phase1/3 取 +0xEC/+0xF0 並在首個非零 callback 短路回傳。
- **第一手 BIN／資料原件證據：** 0x761010=83786800; 0x76102C=c1ea13; 0x761036=c1ea08; 0x76103E=c1e90c; 0x761051=8b4608; 0x59615A=e8a18d2900 (rel32→0x82EF00, 注意非 e8a1ad2900); 0x59619C=ffd0。
- **限制與反證邊界：** selector 的具體角色類型及 vtable 動態 override 未解析，原稿明列缺口。
- **裁決：** `FULL-PASS (document-scope)`。只採認原稿明確限定的可直接驗證結論，不把待辦／未知列為已證。


### 8. T10-099 — FULL-PASS（文件肯定主張限定）
- 原稿：[kr-temp-roy/20261028-1102-chatgpt-web-roy-T10-099-fb73e8-direct-xrefs-and-writer-limits.md](../../../kr-temp-roy/20261028-1102-chatgpt-web-roy-T10-099-fb73e8-direct-xrefs-and-writer-limits.md)；Git blob SHA `ecaf018a76ba0e0ab11570a629dfa99fea3aa7f3`。
- **肯定主張逐項驗證：** (a) .text raw literal `e8 73 fb 00` 恰好 18 處，位址為 literal 出現處而非函式入口；(b) 0x560197 xor ebx,ebx 使 0x560239 直接 store 0；(c) 0x59623B、0x5A4614 等僅 reader/condition；(d) 未發現不等於全局不存在 nonzero alias writer。
- **第一手 BIN／資料原件證據：** literal 18 次，首 0x4A97FF、末 0x5A4616；0x560197=33db; 0x560239=891de873fb00; 0x59623B=393de873fb00; 0x596241=0f9545f1; 0x5A4614=391de873fb00。
- **限制與反證邊界：** pointer alias、非零 writer 與業務語義繼續 unknown，無擅自命名。
- **裁決：** `FULL-PASS (document-scope)`。只採認原稿明確限定的可直接驗證結論，不把待辦／未知列為已證。


### 9. T10-100 — FULL-PASS（文件肯定主張限定）
- 原稿：[kr-temp-roy/20261028-1102-chatgpt-web-roy-T10-100-input-dispatch-closure-matrix.md](../../../kr-temp-roy/20261028-1102-chatgpt-web-roy-T10-100-input-dispatch-closure-matrix.md)；Git blob SHA `124e47117fee777aea6da73d9fb755fd1915fa9a`。
- **肯定主張逐項驗證：** (a) Type0 XML 基本 MapButton13..16=Key44..47；(b) bank/phase 分層而非將 MapButton 當 action opcode；(c) 0x5961C0 以 ID 0..39 loop、phase1/3 vtable 分派且 0xFB73E8 非零時僅 ID13/14；(d) 0x596351 append 0x74D700 12-byte node；(e) 0x560239 是 zero initialization、0x5A4614 是相關 reader/consumer；(f) 明確列出無 full gameplay closure。
- **第一手 BIN／資料原件證據：** XML 原件同 T10-096；0x5961ED=8bc3, 0x5961EF=e81cae1c00, 0x59624E=e88dea1300, 0x596351=8b5d08, 0x59635F=e89c731b00, 0x560239=891de873fb00, 0x5A4614=391de873fb00；分派 loop 0x596387 cmp edi,0x28。
- **限制與反證邊界：** Type1 fallback、自訂配置、device producer、完整 wire/motion/攻擊 timing 明列 unknown。
- **裁決：** `FULL-PASS (document-scope)`。只採認原稿明確限定的可直接驗證結論，不把待辦／未知列為已證。


### 10. T16-58 — FULL-PASS（文件肯定主張限定）
- 原稿：[kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-58-KR-RequestStartScenario-lua-binding-call-path.md](../../../kr-temp-roy/20261028-105806-chatgpt-web-roy-T16-58-KR-RequestStartScenario-lua-binding-call-path.md)；Git blob SHA `e839fac14c60b94911f002fed0f04b3631729111`。
- **肯定主張逐項驗證：** (a) RequestStartScenario 字串註冊經 0x6F5510；(b) 登記函式指標 0x4AC9E0 經 0x6F55B0；(c) 0x4AC9E0 讀 slot [0xFE187C]，將 callback 交 0x4ACB70；(d) 0x4ACB70 兩條由 [ebp-0x18] 間接呼叫分支；(e) script const 不等於 server scenario success。
- **第一手 BIN／資料原件證據：** 0x4AB8F8=6868add600; 0x4AB8FD=e80e9c2400; 0x4AB909=68e0c94a00; 0x4AB90E=e89d9c2400; 0x4ACA16=8b0d7c18fe00; 0x4ACA20=e84b010000; 0x4ACB27/0x4ACB61=ff55e8。
- **限制與反證邊界：** Lua 原始 chunk 對應 scenario ID、socket、T14/T07 結果未驗收，本文明列未知。
- **裁決：** `FULL-PASS (document-scope)`。只採認原稿明確限定的可直接驗證結論，不把待辦／未知列為已證。


## 正面／負面證據區分與新的注意事項

1. `0x59635F` 的正確原生 bytes 是 `E8 9C 73 1B 00`、正確 call target 是 `0x74D700`；`0x59615A` 是 `E8 A1 8D 29 00`、target `0x82EF00`。以上已由 raw bytes + `next EIP + sign-extended rel32` 二次確認。
2. T10-097 的 `0x74D700` 12-byte node 清單不是「攻擊 queue」的證據；把結果鏈表誤當連段應視為未證。
3. T10-099 的 18 筆 literal 是**位元組位置**，不等於 18 個函式或所有寫入者；唯一已直接定位的 `0x560239` 為零初始化，不把「未查得非零」當成「全局永遠為零」。
4. T10-100 的 KeyMapping Type0 證據另有可讀的原始 XML，但自訂設定、Type1/其他模式、實際裝置掃描與 gameplay 的整條 producer→motion 不屬這份矩陣已完成的正面結論。
5. T16-58 的 Lua binding、間接呼叫和函式指標傳遞已查，未有證據聲稱已找到官方 Server scenario accepted/Quest16 completed 的封包。
6. `FULL-PASS` 是**審核原稿正面有限主張**，而不是將原稿內的「尚未確認」全部變成已解。未來如原稿文字明示已完整閉合但仍欠必要證據，則必須降為 `BLOCKED` 並提供精確反證；不得為了計數放寬。

## 下一批接棒

- 本批成功採認 `T10-092, T10-093, T10-094, T10-095, T10-096, T10-097, T10-098, T10-099, T10-100, T16-58`，與 T01-20261028-20 的十份不重複。
- T01-07 其餘尚未 document-scope FULL-PASS 的研究原稿照舊保持待驗，尤其 T08-173 等未處理的 owner/allocator 全生命週期、T16 quest XML 原件和官方 wire 級主張不能跳級。
- 本次只新增一份 T01 integration 報告；保留其他任務原稿不動。若未來要將共用 source-review-status 切換為「整體 native_complete」，**必須另外做 task-level 功能鏈驗收**，不能用此 document-scope FULL-PASS 直接代替。

## 本地重驗指令

```bash
sha256sum /mnt/data/Tartaros.bin /mnt/data/Tartaros.exe
objdump -d -Mintel --start-address=0x596240 --stop-address=0x596390 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x74d700 --stop-address=0x74d734 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x761010 --stop-address=0x761057 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x5a5760 --stop-address=0x5a57d0 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x4ab8f0 --stop-address=0x4ab937 /mnt/data/Tartaros.bin
objdump -d -Mintel --start-address=0x4acaa0 --stop-address=0x4acb6d /mnt/data/Tartaros.bin
```
