# T08-120 — Two upstream update entry points and outstanding consumers

研究者：chatgpt-web roy；2026-10-27 Asia/Taipei。
一級來源：原始 Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91，本輪重新核對。ASM 直接取自該 BIN 的 x86 反組譯。本 GitHub 筆記為完整研究結論與關鍵證據版本，本機另有較長的逐行 ASM 附錄。

## 兩個入口與初始化保護
原始 .text 直接 call 0x00799D20 發現 0x00492567 及 0x007BA56E。兩者都使用全域一次性 bit 0x00FB79E8，未初始化時呼叫 0x00798DE0；然後 push 同一 literal handle slot 地址 0x00FB76A8 及一個 stack float。前者/後者是否每幀執行，靜態證據不能單獨確認。

~~~asm
0049252E test BYTE PTR [0xfb79e8],1
00492545 call 0x798de0
0049255B fld DWORD PTR [ebp+0xc]
00492562 push 0xfb76a8
00492567 call 0x799d20
007BA536 test BYTE PTR [0xfb79e8],1
007BA54B call 0x798de0
007BA562 fld DWORD PTR [ebp+8]
007BA569 push 0xfb76a8
007BA56E call 0x799d20
~~~

## 不只幾何更新：其他副作用
0x00799D20 完成六係數後，將浮點參數寫入 [0x00FBA93C]，呼叫 0x00780890，再遍歷 handle+0x9C 中參與者並派送各自 vtable+0x18。此 +0x18 與 callback constructor 的 +0x10、桶 entry consumer 的 +0x0C 是三個不同調用職責。

~~~asm
00799E9D fld DWORD PTR [ebp+0xc]
00799EA2 fstp DWORD PTR [0xfba93c]
00799ECF mov ecx,[ebx+4]
00799ED4 call 0x780890
00799ED9 mov ebx,[ebx+0x9c]
00799EDF mov esi,[ebx+4]
00799EE2 sub esi,[ebx]
00799EE6 sar esi,2
00799EF0 mov ecx,[ebx]
00799EF5 mov ecx,[ecx+edi*4]
00799EF8 mov edx,[ecx]
00799EFA mov eax,[edx+0x18]
00799EFD push ecx
00799F01 call eax
~~~

## 已確認的新資料流總結
~~~text
00492567 / 007BA56E
  -> 0x00799D20 (handleAddress 0x00FB76A8)
  -> core+0x54 / core+0x98 temporary copies
  -> 0x00838210 matrix composition
  -> ESI = [0x00FB76B0]
  -> 0x00838430 plane output
  -> 0x00862C00 six plane equations
  -> 0x00838800 / 0x00838860 downstream half-space readers

independent: [0x00FB7740] global 22 buckets
  -> several confirmed producers
  -> true per-entry global consumer still not located
~~~

## 修訂與後續
- T08-112/116 的「六係數運行寫入者未知」由 T08-118 明確解決，先前原稿保留作為歷史快照。
- 未證實全域 22 桶 consumer；0x007D1310 的 owner 仍是 caller 的 [EBP+8]，與 [0x00FB7740] 不能硬等同。
- 未證實是相機視錐或場景主更新迴圈；需向上追兩條 0x00799D20 caller 的 outer scheduler。
- T08-121 建議優先查 callback+0x0C 的真實調度者及 owner，並釐清場景物件 +0x20 更新與這條幾何更新之時序。