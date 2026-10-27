# T08-118 — Verified runtime six-plane writer 0x00838430

研究者：chatgpt-web roy；2026-10-27 Asia/Taipei。
一級來源：原始 Tartaros.bin SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91，本輪重新核對。ASM 直接取自該 BIN 的 x86 反組譯。本 GitHub 筆記為完整研究結論與關鍵證據版本，本機另有較長的逐行 ASM 附錄。

## 重大新確認
0x00799D20 是 0x00838430 的上游呼叫者，後者寫入 [0x00FB76B0] 指向的 96-byte/24-float 緩衝。這修正 T08-105～116 中非初始化寫入者未知的歷史結論。

### 直接 caller 及指標身分
~~~asm
0049255B fld DWORD PTR [ebp+0xc]
0049255E push ecx
0049255F fstp DWORD PTR [esp]
00492562 push 0xfb76a8
00492567 call 0x799d20
007BA562 fld DWORD PTR [ebp+8]
007BA565 push ecx
007BA566 fstp DWORD PTR [esp]
007BA569 push 0xfb76a8
007BA56E call 0x799d20
00799D4B mov ebx,[ebp+8]
00799D7E mov eax,[0xfb76a8]
00799D83 lea esi,[eax+0x54]
00799D86 mov ecx,0x11
00799D91 rep movsd
00799D93 lea esi,[eax+0x98]
00799D99 mov ecx,0xd
00799DA4 rep movsd
00799E8F call 0x838210
00799E94 mov esi,[ebx+8]
00799E97 push eax
00799E98 call 0x838430
~~~

兩個 direct callers 都把字面地址 0x00FB76A8 傳入，因而 EBX=0x00FB76A8，ESI=[EBX+8]=[0x00FB76B0]。0x00838430 使用 ESI 作輸出指標、stack 第1參數作輸入矩陣；以多組實際 stores 完整覆蓋 0x00..0x5C。

### 24 個 float 的 store 位址證據
~~~asm
00838543 mov [esi+0x30],ecx
00838552 mov [esi+0x34],edx
00838561 mov [esi+0x38],ecx
0083859E mov [esi+0x3c],edx
008385C9 mov [esi+0x40],ecx
008385D8 mov [esi+0x44],edx
008385E7 mov [esi+0x48],ecx
008385F6 mov [esi+0x4c],edx
00838652 mov [esi+0x50],ecx
00838661 mov [esi+0x54],edx
00838670 mov [esi+0x58],ecx
008386B0 mov [esi+0x5c],edx
008386D5 mov [esi+0x20],ecx
008386E4 mov [esi+0x24],edx
008386F3 mov [esi+0x28],ecx
00838730 mov [esi+0x2c],edx
00838755 mov [esi+0x10],ecx
00838761 mov [esi+0x14],edx
00838767 mov [esi+0x18],ecx
0083876D mov [esi+0x1c],edx
008387D8 mov [esi],ecx
008387DD mov [esi+4],edx
008387E3 mov [esi+8],ecx
008387EF mov [esi+0xc],edx
~~~

### 概念資料流
~~~cpp
void geometryUpdate(Handle *h, float t) {
  Mat4 combined = combine(coreField54,coreField98); // 0x838210
  Plane* out = *(Plane**)((char*)h+8);  // global [0xFB76B0]
  buildSixPlanes(out, combined);        // 0x838430
  // other state dispatch continues
}
~~~

已確認：直接實參、別名與 heap 寫入。暫定：t 是時間增量、六平面是相機視錐。下一段追 0x862C00 的運算。