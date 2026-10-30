# T01 — RR-0003 / T03 Auth E8/000F/13 原生有界驗收（2026-10-30）

## 身份與來源 R0

研究目標：KR Tartaros.bin，12,472,320 bytes，SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。Tartaros.exe SHA256 03771b8e1c1e66248f54585fadf9a5e926eb77228721325bb9be5febc53b3b5f。兩者由此次上傳的原件唯讀重新計 hash，未執行、修改或附加 Client，無原版 Server 流量。

RR-0003 在 main 正式提交台帳已為 SUBMITTED，但最初 main 缺報告；來源 t03/roy/chatgpt-web 的原稿共 1463 行。T01 以原樣 blob 已恢復至 main：

- kr-temp-roy/20261030-142513-chatgpt-web-roy-T03-RR0003-KR-auth-E8-000F-13-codepage-group-handoff.md
- Git blob SHA1 64c8c1a3429ae6ff177a84dee0d08ad69dba0b17
- 原文 UTF-8 SHA256 e0ac3471052dac7a0c9222ed18966e8406ff6fb24b957643cad675b7aaff6bd7

來源身份完整不等於全篇語意 FULL-PASS。

## BIN-first 有界 R2

PE .text VA 0x401000/raw 0x400；函式 VA 對應 raw = VA − 0x400C00。本次自原件抽取 10 段並以 objdump x86 Intel 重新解讀，下面為精確 [start,end) VA 的 raw bytes SHA256。這是樣本與定向分支審查，不代表所有間接 caller 或全文都通過。

| VA 區段 | 長度 | SHA256 |
|---|---:|---|
| 440790..440830 | 160 | 3458fcbaec57113c7a8c1be4c0d58f3a6a15bbbe7388097e9f84b0cd3c5460e4 |
| 4A31B0..4A32D0 | 288 | 835c38ad5d287c8f07f934d22e9aeb4d282de1821415a0bb621d4d2222260740 |
| 4A3360..4A3510 | 432 | 82dd354c90dd3a62536e63938c34c966634e2594057a8621da75303e18a14e79 |
| 47F540..47F600 | 192 | 945396d41ab3276e3899d586efe9a8e734719a59ba5b8b77640ea5459b1488da |
| 4C3080..4C3160 | 224 | c248a5dfd4c626efffcfcf1229761ccd47c5f926c7b40b5cd678fb0ce738be0f |
| 4C3170..4C3220 | 176 | f9795578d99911728cef07a320acfd26da6669553a595977f390640f64dc39f0 |
| 4C3220..4C3280 | 96 | 3f459daab3e6da940be743ee9c80223c25852a9e04a5d5e84cb524ee70fa0794 |
| 4C37A0..4C3BA0 | 1024 | 279be80cafa2f06e281b30ecb32d32c3a4f3757a0aa08d7c00dc4fb98c7d7ffb |
| 4C3C10..4C3C60 | 80 | c68bbaa05b1bfb4146577e971acb015ee20dbc83a67105dabba03be98db9d443 |
| 4957C0..495850 | 144 | 1a11dff50383dd27972c40c183b35765ab1ffe74a0a1d3f39c403d7133742409 |

    440796 83 F8 52           cmp eax,52h
    4407C2 E8 99 2B 06 00     call 4A3360  ; mode52 narrow E8
    4407CB 83 F8 54           cmp eax,54h
    4407F7 E8 B4 29 06 00     call 4A31B0  ; mode54 wide 000F
    440822 E8 89 29 06 00     call 4A31B0  ; other wide 000F
    4A31F3 C7 45 92 01 00 01 00  mov dword [ebp-6Eh],10001h
    4A33AB B9 E8 00 00 00     mov ecx,0E8h
    4C323B ...                mov dword [esi+5F44h],4C37A0h
    4C325B ...                mov dword [esi+627Ch],4C3C10h
    4C37E7 8B 15 08 A8 FB 00 mov edx,[FBA808h]
    4C3821 8A 56 16           mov dl,[esi+16h]
    4C3824 80 FA 05           cmp dl,5
    4C30BE 0F B7 0B           movzx ecx,word [ebx]
    4C30C1 83 C7 03           add edi,3
    4C30FF 83 C7 0A           add edi,10
    4C313C 3B C1              cmp eax,ecx
    4C314A 68 43 42 0F 00     push 0F4243h
    4C3C16 8B 48 02           mov ecx,[eax+2]
    4C3C1A 8D 48 06           lea ecx,[eax+6]
    4C3C1D E8 5E F4 FF FF     call 4C3080

## 有界解讀及不可偷換的負向界線

1. Client mode 52 呼叫 4A3360 建 E8；mode 54/其他呼叫 4A31B0 建 000F。兩種送包來源和本地 payload 尺寸按既有 CLM-AUTH-0001；不代表某個玩家 session 已成功發送或官方 Server 接受兩種模式。
2. FBA808 位於 PE .data 的虛擬零區：FBA808-D61000=0x258808，大於 raw size 0x22B800 且小於 virtual size 0x2873D8；只能證明**初始值**零及原生 codepage 使用點，不代表 runtime 不會被間接寫入，也不能固定 OS ACP 為 UTF-8 或 CP949。
3. LOGIN scene 第二層 command 13→4C37A0、7A→4C3C10，需 T02/E60 既有 scene/lane 前置。13 讀 payload+16h status；7A 從 payload+2 讀 DWORD count、payload+6 作游標，不能將兩個不同命令混為同一 layout，亦不意味 Server 一定先回某命令。
4. 4C3080 的每組 3 bytes（WORD ID / BYTE count）、每 child 10 bytes，row+4..7 傳給 IPv4 formatter，row+8 決定是否 append。局部計數迴圈未見每個子項的 remaining-payload byte-length guard，但不能因此宣稱上游也沒驗或存在真實漏洞。zero group 仍會進 F4243 本地通知。
5. E8 +104..109 opaque 六個 byte 尚無全域正向 writer 定論；Client 靜態不能證實官方 Server 密碼、session、token、回覆先後或選角批准。

## 驗收決議與後續

T01 此批完成來源 R0 與上述有界 R2，**原稿整體依然 PARTIAL / NOT FULL-PASS**。不改 T03 既有 NEEDS_FIX/owner、原稿、catalog，也不代 S00 把 RR 升 ACCEPTED，SPEC/GAP/TEST 不升格。建議將本來源列 SRC-0473，細分新有界 PARTIAL CLM-AUTH-0003..0005，與既存 CLM-AUTH-0001/2 去重。

- Client 待逆向：E8 opaque writer、codepage runtime alias、auth 失敗分支、真實選角結果與場景 writer。
- Server 待開發：帳號／session／選服／錯誤政策，自訂決策不得冒稱官方 Server。
- 跨 Task 待整合：T02 RR1/4/5/6/7 framing 和 lane + T03 auth + T04 roster + T05 scene。
- 待遊玩驗證：無原版封包擷取、未執行原版 Client，沒有原生可玩驗收。
