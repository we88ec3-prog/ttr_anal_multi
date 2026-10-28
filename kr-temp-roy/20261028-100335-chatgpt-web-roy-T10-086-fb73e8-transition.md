# T10-086 — 全域 0xFB73E8 與模式切換／物件狀態控制流

## 版本
KR Tartaros.bin SHA256 `9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91`，本機已驗證；PE32 .text VA=0x401000 raw=0x400。靜態 objdump -D -Mintel；不執行目標。

## 直接寫入與資料流

```asm
00560197 xor ebx,ebx
005601f1 push 0x18
005601f3 mov ds:0xfb73e0,ebx
00560237 push 0x48
00560239 mov ds:0xfb73e8,ebx
0056023f mov ds:0xfb73ec,ebx
00560245 call 0x891268
005a45de cmp BYTE PTR [esi+0x15c],bl
005a45e4 jne 0x5a4671
005a4614 cmp DWORD PTR ds:0xfb73e8,ebx
005a461a mov al,BYTE PTR [esi+0x154]
005a4620 setne bl
005a4623 test al,al
005a4625 jne 0x5a465c
005a4627 test bl,bl
005a4629 je 0x5a4658
005a462b push 0x2
005a462d xor cl,cl
005a462f mov edx,esi
005a4631 call 0x5a55e0
005a4636 mov edx,DWORD PTR [esi+0x10]
005a4639 sub edx,0x13b
005a463f push esi
005a4640 mov eax,0x5
005a4645 call 0x5a5760
005a464a mov edx,0x66
005a464f mov ecx,esi
005a4651 call 0x5a57a0
005a465c test bl,bl
005a465e jne 0x5a466b
005a4660 push 0x1
005a4662 xor cl,cl
005a4664 mov edx,esi
005a4666 call 0x5a55e0
005a466b mov BYTE PTR [esi+0x154],bl
```

0x560239 是 **初始化清零**：ebx 在 0x560197 已歸零。以全 .text 的絕對常量引用掃描，無其他直接非零寫入指令；但不能排除物件 base / alias / pointer writes。

## 下游 0x5A55E0

```asm
005a5605 mov eax,DWORD PTR [ebp+0x8]
005a5608 mov esi,edx
005a560a mov ebx,0x1
005a560f mov DWORD PTR [esi+0x158],eax
005a5617 mov BYTE PTR [esi+0x15c],cl
005a5625 jne 0x5a5744
005a5655 mov DWORD PTR ds:0xfb11e8,0x2
005a565f mov ecx,DWORD PTR [esi+0x140]
005a5667 mov eax,DWORD PTR [edx+0xd4]
005a566d call eax
005a566f mov ecx,DWORD PTR [esi+0x148]
005a5677 mov eax,DWORD PTR [edx+0xd0]
005a567d call eax
005a5694 mov eax,DWORD PTR [esi+0x148]
005a569a or DWORD PTR [eax+0x28],0x80000
005a56b2 push esi
005a56b3 call 0x74a010
005a56fa mov ds:0xfb11e8,ebx
005a5700 mov ecx,DWORD PTR [esi+0x148]
005a5708 mov eax,DWORD PTR [edx+0xd4]
005a570e call eax
005a5720 xor eax,0x80000
005a5725 mov DWORD PTR [ecx+0x28],eax
005a5728 mov ecx,DWORD PTR [esi+0x140]
005a5730 mov eax,DWORD PTR [edx+0xd0]
005a5736 call eax
005a573f call 0x645250
```

[esi+0x154] 是前次狀態布林快取，[esi+0x158] 接收參數 mode 1/2，[esi+0x15c] 接收 cl 參數。0x5A55E0 同時接觸 [esi+0x140/0x148] 兩個候選子物件和後者 +0x28 bit0x80000。已證明「控制狀態切換」，不能未經 owning class 證據稱它為角色蓄氣／攻擊取消／motion reset。0x5961C0 也讀 0xFB73E8，因此跨路徑關聯存在但仍缺該 global 的非零 writer。

## 下一步
追 0xFB73C0 區域別名寫入、0x5A5760/0x5A57A0 對象、vtable +0xD0/+0xD4 實際 implementation；禁止以命令 0x66 的值推論一定是攻擊指令。