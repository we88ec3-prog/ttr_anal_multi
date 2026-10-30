# RR-0004 — A02C mode 與有界 fallback，原始 BIN 補證

日期 2026-10-29 (Asia/Taipei)；跨 Task 研究支援 S00 RR-0004（正式 owner T02，未認領）。原始檔 Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91。獨立以 objdump -D -b binary -m i386 -M intel --adjust-vma=0x400c00 查核；source PE .text VA/raw 差 0x400c00。

## 可直接確定的 init、mode gate、兩種 builder

```asm
805D02 c6 86 2c a0 00 00 02   mov byte ptr [esi+0xA02C],2
805D09 89 86 20 a0 00 00      mov [esi+0xA020],eax
805D15 89 9e 28 a0 00 00      mov [esi+0xA028],ebx
806202 0f be 86 2c a0 00 00   movsx eax,byte ptr [esi+0xA02C]
806218 74 15                  je 0x80622F    ; mode zero
806223 e8 08 16 00 00         call 0x807830
806228 85 c0                  test eax,eax
80622A 75 23                  jne 0x80624F    ; first builder success
80622F 8b 45 f0               mov eax,[ebp-0x10]
806234 8d be 1c 50 00 00      lea edi,[esi+0x501C]
80623A e8 31 18 00 00         call 0x807A70    ; fallback
806246 0f 84 58 01 00 00      je 0x8063A4    ; fallback failure
```

上面資料顯示 mode 為 0 時直接走 807A70；非 0 先走 807830，失敗才走 807A70。**不是** mode 1/2 已證分別選不同編碼，因 80621B/80621D 的分支最後會合流至 80621E；必須繼續追 mode writer alias 與真正 807830 成功語意。

兩條 builder 的本地 buffer base 均是 connection+0x501C，callee 見 +0x5004/+0x500C 對應 connection+0xA020/+0xA028，避免誤寫 offset。

### 0x807830 首要條件

```asm
80786D lea eax,[edi+6]
807870 mov dword ptr [ebp-0x101A],0x7D810BBB
807887 cmp eax,0x1000
807892 test edi,edi
80789A mov edx,[esi+0x500C]
8078A0 add edx,eax
8078A2 cmp edx,0x4000
```

含 6-byte local frame overhead，payload 非零、total <=0x1000，且 pending buffered total <=0x4000。

### 0x807A70 首要條件

```asm
807A84 mov edx,[ebp+0xC]
807A87 lea ebx,[edx+4]
807A8A mov eax,0x1A68
807A8F mov word ptr [ebp-2],ax
807A93 mov word ptr [ebp-4],dx
807A97 cmp ebx,0x1000
807AA3 test edx,edx
807AAB mov ecx,[edi+0x500C]
807AB1 add ecx,ebx
807AB3 cmp ecx,0x4000
807AE2 mov ecx,[ebp-4]
807AE9 mov dword ptr [eax],ecx
```

含 4-byte local frame overhead，payload 非零、total <=0x1000，且 pending total <=0x4000。先寫長度再寫 marker（若使用 local dword [ebp-4]），與 T01 舊來源誤標「marker first」的錯誤更正一致。

## 界線

此處已證 **conditional framing fallback**，但未證 mode=A02C 的完整 writer aliases、是否所有連線 mode 都等於 2、兩個 builder 是否對等傳輸、checksum/decode 與 wire capture，不能宣稱 original Client 的 plaintext fallback 一定發生。RR-0004 **尚未完成**。關聯 RR-0001（初始 frame）、RR-0005（各 socket 初送）、RR-0006（checksum）、RR-0007（dispatch）。

Client 待逆向：追 A02C 直接及間接寫入者、具體失敗條件與 fallback 成功後 socket output；Server 待開發：兩種 frame 接受策略需原生證據及測試；跨功能待整合：T02/T03 登入連線；待遊玩驗證：無 runtime trace/pcap。

本文件是額外的原生補證，不修改正式 RR 台帳，不冒稱 SUBMITTED、ACCEPTED、FULL-PASS 或 S00 SPEC STABLE。
