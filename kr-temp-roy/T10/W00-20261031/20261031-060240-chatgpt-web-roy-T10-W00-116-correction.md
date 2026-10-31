# W00-116 — KR C→S 000A 的兩路 5-byte row、虛函式與 stack ABI 勘誤

## 1. 修正結論
原稿「Row A/B 第五位元組一律是 R+0xB0」不成立；**撤回此無條件結論**，保留已由 BIN 支持的局部 header、6+5N、長度 guard、selector0 條件式傳輸。row[0..1] 的直接 append 前來源仍是 WORD[R+4]；row[2..3] 是會被 callback 改動的 local high WORD；row[4] 需要按 branch 和 callback 最後 writer 判定。不得把任何 row byte 無證命名為技能 ID、方向或 Server status。

## 2. Row B 真實 branch×最後寫入矩陣
```asm
545A54 8B 86 E0 00 00 00    mov eax,[esi+E0]
545A63 89 44 24 2C          mov [esp+2C],eax
545A67 8A 8E E4 00 00 00    mov cl,[esi+E4]
545A70 88 4C 24 30          mov [esp+30],cl ; E4 初始化
545A78 8A 9E B0 00 00 00    mov bl,[esi+B0]
545A8A 8D 4C 24 2C          lea ecx,[esp+2C] ; virtual44 的 out 指標
545A93 88 5C 24 28          mov [esp+28],bl ; 已有 3 個 push，別與穩定 local+30 混淆
545A97 FF D2                call edx ; A::virtual+44
545A99 85 C0                test eax,eax
545A9D 83 7F 58 00          cmp dword [edi+58],0
545AA1 74 33                je 545AD6 ; return!=0 且 A+58=0：無 B0 覆寫
545AB7 66 85 47 6A          test word [edi+6A],ax ; ax=8000h
545ABB 74 5D                je 545B1A ; fallback 不可 append
545AC8 88 5C 24 30          mov [esp+30],bl ; 其餘可 append 分支覆寫 B0
545AD4 FF D2                call edx ; R::virtual+58
545ADB 8A 4C 24 30          mov cl,[esp+30]
545AF4 66 89 54 24 2C       mov word [esp+2C],dx ; dx=WORD[R+4]
545AFC 81 FA 00 10 00 00    cmp edx,1000h
545B02 77 16                ja 545B1A ; 超長不 append
545B0E 89 10                mov [eax],edx
545B10 88 48 04             mov [eax+4],cl
```
| virtual+44 回傳 | A+58 | A+6A bit15 | 其它 gate 成立後可 append？ | row[4] 在 caller 的最後直接 local writer |
|---|---|---|---|---|
| 非零 | 0 | 不檢查 | 是 | 初始 `545A70` = R+E4；**需考慮 virtual44 對輸出指標改值**，不是無條件 E4 |
| 非零 | 非零 | 不檢查 | 是 | `545AC8` = 呼叫前擷取的 R+B0 |
| 0 | 0 | 任意 | 否 | 無 row |
| 0 | 非零 | 0 | 否 | 無 row |
| 0 | 非零 | 1 | 是 | `545AC8` = 呼叫前擷取的 R+B0 |

上述「可 append」都還需要 tree lookup、payload、length+5≤0x1000 等 gate。特別重要：vtable 候選 `0xC0F944` 的 +0x44 = `0x546EF0`，該函式 `547077 88 46 04 (mov [esi+4],al)` 能直接寫 output+4，`5471A7 C2 0C 00` 為 `ret 12`。所以 T01 原先指出「跳過 AC8 的路徑保留 E4」應準確表述成「**跳過 caller 的 B0 覆寫；在 callback 沒有改動 output+4 的條件下維持 E4**」。不可未核對具體 virtual call path 就升格為對所有 runtime 的確定 E4。

## 3. Row A ESP alias 與 highWORD/row[4] def-use
令 S = `5458C4` 前穩定 ESP。序列：
```asm
5458BB 8A 9E B0 00 00 00    mov bl,[esi+B0]
5458C4 8D 44 24 34          lea eax,[S+34] ; 5-byte local output
5458C8 50                   push eax
5458C9 57                   push edi
5458CA 88 5C 24 20          mov [esp+20],bl ; 此時 ESP=S−8，實為 [S+18]，**不是 [S+38]**
5458CE FF D2                call A::virtual+48
5458D0 84 C0                test al,al
5458DC 74 1D                je 5458FB ; AL!=0 && A+58==0
5458E0 66 89 44 24 36       mov word [S+36],0
5458E9 88 5C 24 38          mov byte [S+38],bl
5458F5 FF D2                call R::virtual+58
5458FB 8A 4C 24 38          mov cl,[S+38]
54590D 66 8B 46 04          mov ax,word [esi+4]
545911 66 89 44 24 34       mov word [S+34],ax
54591E 81 FA 00 10 00 00    cmp edx,1000h
545924 77 6A                ja 545990
545926 8B 54 24 34          mov edx,[S+34]
545930 89 10                mov [eax],edx
545932 88 48 04             mov byte [eax+4],cl
```
- `AL!=0 && A+58!=0`：先清高 WORD S+36；由 `5458E9` 將 BL 明確保存至 S+38；virtual58 可能修改 R/其它狀態；`5458FB` 再讀 S+38。此路徑 caller 直接 writer 明確，但不能先驗宣稱所有間接副作用都不存在。
- `AL!=0 && A+58==0`：跳過 E0/E9/F5；S+36 與 S+38 取決於 `A::virtual+48` 的輸出，而非 `5458CA`。候選 `0x546100` 在 `546191 66 89 43 02` 寫 out+2=0、`546195 8A 87 B0 00 00 00`/ `54619B 88 43 04` 寫 out+4=R+B0，後續 `546378` 等又可能改 out+4；保留其條件與 runtime subtype 未知。
- `AL==0`：只有 `A+58!=0 && (A+6A & 0x8000)!=0` 可 fallback，`545955` 清 S+36、`54595A` 寫 S+38=BL、`545966` 呼叫 R::virtual+58，`54598B call 5471B0` 走另一個有長度 guard 的 append helper；其餘不 append。

## 4. ABI／指標證據的適用界線
本次在 KR 原生 `.rdata` 得到 vtable **候選** `0xC0F944`：`slot+2C=0x5452C0`、`slot+44=0x546EF0`、`slot+48=0x546100`。後者兩條出口 `54616E C2 08 00`、`5464B3 C2 08 00`（ret 8）與 caller 的兩次 push 平衡；`0x546EF0` 的正常/早退 `ret 12` 與 Row B 三次 push 平衡。不能由候選 vtable 推稱所有多型 owner 都同表。Row A `5458CA` 在 push 後寫的是 S+18，與 `5458E5` 的 callback argument load 相關，**不是 local fifth-byte writer**；Row B `545A93` 在三個 push 後寫穩定 S+1C，也非 S+30。其它可寫 local 的間接 callback/alias 候選應再查，故 row[2..3]、各 runtime 第五 byte 實值仍保留限制。

## 5. 驗收與未知
退回的無條件共同 ABI 已被反證；本次提供明確 source-to-writer/branch、函式指標候選及精確 retN 修正。T01 仍需對新勘誤的 branch/alias/具體 owner 重新複驗；原生局部支撐不等於 T10 原稿全文 FULL-PASS。Client 尚待：各 subtype callback 的完整註冊/值域、S2C ACK/actor motion/連段時窗；Server-only 原版裁決不由此推論。

---

**來源與完成界線：** KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`；`.text` 的 raw=VA−0x400C00、`.rdata` 的 raw=VA−0x401A00。保留舊稿 `kr-temp-roy/20261028-213248-chatgpt-web-roy-T10-116-KR-000A-five-byte-row-field-provenance.md` 與 Git blob `8da51d9e77d3d900bc73743bddc82891f6829c15`，正式 T01 通知 `T01-RETURN-T10-116-ROW5-PROVENANCE-001`；另於同目錄提供 30 bytes asserts / 11 hashes 機讀文件。狀態是**勘誤已提出／待 T01 原生語意複驗**，非 RESOLVED、FULL-PASS、原版 Server 規則或已可玩。未修改原始 Client、T11 owner、正式 RR/S00 台帳或其他 Task 原稿。
