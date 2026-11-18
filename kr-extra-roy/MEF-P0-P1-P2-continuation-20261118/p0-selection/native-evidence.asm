; Target SHA256 9741d1975327b9309d82b52f631165bc410757694d7c183a5eed970a53ebef91
; New windows only. Reused windows are pinned by source path/id in native-evidence.json.

; group_definition_first_wins 0x716040..0x716240 exclusive
; Existing exact group skips allocation and writes; new group stores pattern+0, directory+1c, recursion+38, index+3c.
0x716040: 55                               push ebp
0x716041: 8bec                             mov ebp,esp
0x716043: 83e4f8                           and esp,0xfffffff8
0x716046: 6aff                             push 0xffffffff
0x716048: 687e5c9100                       push 0x915c7e
0x71604d: 64a100000000                     mov eax,fs:0x0
0x716053: 50                               push eax
0x716054: 83ec60                           sub esp,0x60
0x716057: a1201fd600                       mov eax,ds:0xd61f20
0x71605c: 33c4                             xor eax,esp
0x71605e: 89442458                         mov DWORD PTR [esp+0x58],eax
0x716062: 53                               push ebx
0x716063: 56                               push esi
0x716064: 57                               push edi
0x716065: a1201fd600                       mov eax,ds:0xd61f20
0x71606a: 33c4                             xor eax,esp
0x71606c: 50                               push eax
0x71606d: 8d442470                         lea eax,[esp+0x70]
0x716071: 64a300000000                     mov fs:0x0,eax
0x716077: 8b450c                           mov eax,DWORD PTR [ebp+0xc]
0x71607a: 8b5d08                           mov ebx,DWORD PTR [ebp+0x8]
0x71607d: 8944241c                         mov DWORD PTR [esp+0x1c],eax
0x716081: 8bf2                             mov esi,edx
0x716083: 8bc3                             mov eax,ebx
0x716085: 89742424                         mov DWORD PTR [esp+0x24],esi
0x716089: 894c2418                         mov DWORD PTR [esp+0x18],ecx
0x71608d: c74424400f000000                 mov DWORD PTR [esp+0x40],0xf
0x716095: c744243c00000000                 mov DWORD PTR [esp+0x3c],0x0
0x71609d: c644242c00                       mov BYTE PTR [esp+0x2c],0x0
0x7160a2: 8d7801                           lea edi,[eax+0x1]
0x7160a5: 8a08                             mov cl,BYTE PTR [eax]
0x7160a7: 40                               inc eax
0x7160a8: 84c9                             test cl,cl
0x7160aa: 75f9                             jne 0x7160a5
0x7160ac: 2bc7                             sub eax,edi
0x7160ae: 50                               push eax
0x7160af: 53                               push ebx
0x7160b0: 8d4c2434                         lea ecx,[esp+0x34]
0x7160b4: e8b7c9ceff                       call 0x402a70
0x7160b9: 8d54242c                         lea edx,[esp+0x2c]
0x7160bd: 52                               push edx
0x7160be: 8bc6                             mov eax,esi
0x7160c0: c744247c00000000                 mov DWORD PTR [esp+0x7c],0x0
0x7160c8: e8630e0a00                       call 0x7b6f30
0x7160cd: 89442420                         mov DWORD PTR [esp+0x20],eax
0x7160d1: 3b4604                           cmp eax,DWORD PTR [esi+0x4]
0x7160d4: 7416                             je 0x7160ec
0x7160d6: 83c00c                           add eax,0xc
0x7160d9: 8d54242c                         lea edx,[esp+0x2c]
0x7160dd: e84e4dd8ff                       call 0x49ae30
0x7160e2: 84c0                             test al,al
0x7160e4: 7506                             jne 0x7160ec
0x7160e6: 8d442420                         lea eax,[esp+0x20]
0x7160ea: eb0b                             jmp 0x7160f7
0x7160ec: 8b4604                           mov eax,DWORD PTR [esi+0x4]
0x7160ef: 89442414                         mov DWORD PTR [esp+0x14],eax
0x7160f3: 8d442414                         lea eax,[esp+0x14]
0x7160f7: 8b38                             mov edi,DWORD PTR [eax]
0x7160f9: c7442478ffffffff                 mov DWORD PTR [esp+0x78],0xffffffff
0x716101: 837c244010                       cmp DWORD PTR [esp+0x40],0x10
0x716106: 720d                             jb 0x716115
0x716108: 8b4c242c                         mov ecx,DWORD PTR [esp+0x2c]
0x71610c: 51                               push ecx
0x71610d: e8fab01700                       call 0x89120c
0x716112: 83c404                           add esp,0x4
0x716115: 3b7e04                           cmp edi,DWORD PTR [esi+0x4]
0x716118: 0f8502010000                     jne 0x716220
0x71611e: 6a6c                             push 0x6c
0x716120: e843b11700                       call 0x891268
0x716125: 8bf8                             mov edi,eax
0x716127: 83c404                           add esp,0x4
0x71612a: 897c2414                         mov DWORD PTR [esp+0x14],edi
0x71612e: 33c0                             xor eax,eax
0x716130: c744247801000000                 mov DWORD PTR [esp+0x78],0x1
0x716138: 3bf8                             cmp edi,eax
0x71613a: 7428                             je 0x716164
0x71613c: b90f000000                       mov ecx,0xf
0x716141: 894f14                           mov DWORD PTR [edi+0x14],ecx
0x716144: 894710                           mov DWORD PTR [edi+0x10],eax
0x716147: 8807                             mov BYTE PTR [edi],al
0x716149: 894f30                           mov DWORD PTR [edi+0x30],ecx
0x71614c: 89472c                           mov DWORD PTR [edi+0x2c],eax
0x71614f: 88471c                           mov BYTE PTR [edi+0x1c],al
0x716152: c644247803                       mov BYTE PTR [esp+0x78],0x3
0x716157: 8d773c                           lea esi,[edi+0x3c]
0x71615a: 894738                           mov DWORD PTR [edi+0x38],eax
0x71615d: e88e2b0000                       call 0x718cf0
0x716162: eb02                             jmp 0x716166
0x716164: 33ff                             xor edi,edi
0x716166: 8b442418                         mov eax,DWORD PTR [esp+0x18]
0x71616a: c7442478ffffffff                 mov DWORD PTR [esp+0x78],0xffffffff
0x716172: 8d4f1c                           lea ecx,[edi+0x1c]
0x716175: 8d7001                           lea esi,[eax+0x1]
0x716178: 8a10                             mov dl,BYTE PTR [eax]
0x71617a: 40                               inc eax
0x71617b: 84d2                             test dl,dl
0x71617d: 75f9                             jne 0x716178
0x71617f: 8b542418                         mov edx,DWORD PTR [esp+0x18]
0x716183: 2bc6                             sub eax,esi
0x716185: 50                               push eax
0x716186: 52                               push edx
0x716187: e8e4c8ceff                       call 0x402a70
0x71618c: 8b44241c                         mov eax,DWORD PTR [esp+0x1c]
0x716190: 8d7001                           lea esi,[eax+0x1]
0x716193: 8a08                             mov cl,BYTE PTR [eax]
0x716195: 40                               inc eax
0x716196: 84c9                             test cl,cl
0x716198: 75f9                             jne 0x716193
0x71619a: 2bc6                             sub eax,esi
0x71619c: 50                               push eax
0x71619d: 8b442420                         mov eax,DWORD PTR [esp+0x20]
0x7161a1: 50                               push eax
0x7161a2: 8bcf                             mov ecx,edi
0x7161a4: e8c7c8ceff                       call 0x402a70
0x7161a9: 8b4d10                           mov ecx,DWORD PTR [ebp+0x10]
0x7161ac: 8bc3                             mov eax,ebx
0x7161ae: 894f38                           mov DWORD PTR [edi+0x38],ecx
0x7161b1: c744245c0f000000                 mov DWORD PTR [esp+0x5c],0xf
0x7161b9: c744245800000000                 mov DWORD PTR [esp+0x58],0x0
0x7161c1: c644244800                       mov BYTE PTR [esp+0x48],0x0
0x7161c6: 8d7001                           lea esi,[eax+0x1]
0x7161c9: 8da42400000000                   lea esp,[esp+0x0]
0x7161d0: 8a08                             mov cl,BYTE PTR [eax]
0x7161d2: 40                               inc eax
0x7161d3: 84c9                             test cl,cl
0x7161d5: 75f9                             jne 0x7161d0
0x7161d7: 2bc6                             sub eax,esi
0x7161d9: 50                               push eax
0x7161da: 53                               push ebx
0x7161db: 8d4c2450                         lea ecx,[esp+0x50]
0x7161df: e88cc8ceff                       call 0x402a70
0x7161e4: 897c2464                         mov DWORD PTR [esp+0x64],edi
0x7161e8: c744247804000000                 mov DWORD PTR [esp+0x78],0x4
0x7161f0: 8b742424                         mov esi,DWORD PTR [esp+0x24]
0x7161f4: 8d542448                         lea edx,[esp+0x48]
0x7161f8: 52                               push edx
0x7161f9: 8bce                             mov ecx,esi
0x7161fb: e8e0cbe3ff                       call 0x552de0
0x716200: 50                               push eax
0x716201: 8d442428                         lea eax,[esp+0x28]
0x716205: 50                               push eax
0x716206: 56                               push esi
0x716207: e804c70c00                       call 0x7e2910
0x71620c: 837c245c10                       cmp DWORD PTR [esp+0x5c],0x10
0x716211: 720d                             jb 0x716220
0x716213: 8b4c2448                         mov ecx,DWORD PTR [esp+0x48]
0x716217: 51                               push ecx
0x716218: e8efaf1700                       call 0x89120c
0x71621d: 83c404                           add esp,0x4
0x716220: 8b4c2470                         mov ecx,DWORD PTR [esp+0x70]
0x716224: 64890d00000000                   mov DWORD PTR fs:0x0,ecx
0x71622b: 59                               pop ecx
0x71622c: 5f                               pop edi
0x71622d: 5e                               pop esi
0x71622e: 5b                               pop ebx
0x71622f: 8b4c2458                         mov ecx,DWORD PTR [esp+0x58]
0x716233: 33cc                             xor ecx,esp
0x716235: e8c7ad1700                       call 0x891001
0x71623a: 8be5                             mov esp,ebp
0x71623c: 5d                               pop ebp
0x71623d: c20c00                           ret 0xc

; group_scan_rebuild 0x716240..0x716432 exclusive
; Group entries are collected, each index is cleared then scanned with its stored directory/pattern/recursive fields.
0x716240: 55                               push ebp
0x716241: 8bec                             mov ebp,esp
0x716243: 83e4f8                           and esp,0xfffffff8
0x716246: 6aff                             push 0xffffffff
0x716248: 68086a9000                       push 0x906a08
0x71624d: 64a100000000                     mov eax,fs:0x0
0x716253: 50                               push eax
0x716254: 83ec18                           sub esp,0x18
0x716257: 53                               push ebx
0x716258: 56                               push esi
0x716259: 57                               push edi
0x71625a: a1201fd600                       mov eax,ds:0xd61f20
0x71625f: 33c4                             xor eax,esp
0x716261: 50                               push eax
0x716262: 8d442428                         lea eax,[esp+0x28]
0x716266: 64a300000000                     mov fs:0x0,eax
0x71626c: 33c9                             xor ecx,ecx
0x71626e: 33f6                             xor esi,esi
0x716270: 33d2                             xor edx,edx
0x716272: 89742414                         mov DWORD PTR [esp+0x14],esi
0x716276: 89542418                         mov DWORD PTR [esp+0x18],edx
0x71627a: 894c241c                         mov DWORD PTR [esp+0x1c],ecx
0x71627e: 8b4508                           mov eax,DWORD PTR [ebp+0x8]
0x716281: 894c2430                         mov DWORD PTR [esp+0x30],ecx
0x716285: 8b4004                           mov eax,DWORD PTR [eax+0x4]
0x716288: 8b18                             mov ebx,DWORD PTR [eax]
0x71628a: 89442410                         mov DWORD PTR [esp+0x10],eax
0x71628e: 3bd8                             cmp ebx,eax
0x716290: 7542                             jne 0x7162d4
0x716292: 2bd6                             sub edx,esi
0x716294: c1fa02                           sar edx,0x2
0x716297: 33ff                             xor edi,edi
0x716299: 89542410                         mov DWORD PTR [esp+0x10],edx
0x71629d: 85d2                             test edx,edx
0x71629f: 0f846b010000                     je 0x716410
0x7162a5: 8b34be                           mov esi,DWORD PTR [esi+edi*4]
0x7162a8: 8d5e3c                           lea ebx,[esi+0x3c]
0x7162ab: 53                               push ebx
0x7162ac: e82f2c0000                       call 0x718ee0
0x7162b1: 8d461c                           lea eax,[esi+0x1c]
0x7162b4: b910000000                       mov ecx,0x10
0x7162b9: 394814                           cmp DWORD PTR [eax+0x14],ecx
0x7162bc: 7202                             jb 0x7162c0
0x7162be: 8b00                             mov eax,DWORD PTR [eax]
0x7162c0: 394e14                           cmp DWORD PTR [esi+0x14],ecx
0x7162c3: 0f8229010000                     jb 0x7163f2
0x7162c9: 8b0e                             mov ecx,DWORD PTR [esi]
0x7162cb: e924010000                       jmp 0x7163f4
0x7162d0: 8b4c241c                         mov ecx,DWORD PTR [esp+0x1c]
0x7162d4: 8d7b28                           lea edi,[ebx+0x28]
0x7162d7: 3bfa                             cmp edi,edx
0x7162d9: 7361                             jae 0x71633c
0x7162db: 3bf7                             cmp esi,edi
0x7162dd: 775d                             ja 0x71633c
0x7162df: 2bfe                             sub edi,esi
0x7162e1: c1ff02                           sar edi,0x2
0x7162e4: 3bd1                             cmp edx,ecx
0x7162e6: 7549                             jne 0x716331
0x7162e8: 8bc2                             mov eax,edx
0x7162ea: 2bc6                             sub eax,esi
0x7162ec: c1f802                           sar eax,0x2
0x7162ef: 3dfeffff3f                       cmp eax,0x3ffffffe
0x7162f4: 0f87ee000000                     ja 0x7163e8
0x7162fa: 2bce                             sub ecx,esi
0x7162fc: 40                               inc eax
0x7162fd: c1f902                           sar ecx,0x2
0x716300: 3bc1                             cmp eax,ecx
0x716302: 762d                             jbe 0x716331
0x716304: 8bd1                             mov edx,ecx
0x716306: d1ea                             shr edx,1
0x716308: beffffff3f                       mov esi,0x3fffffff
0x71630d: 2bf2                             sub esi,edx
0x71630f: 3bf1                             cmp esi,ecx
0x716311: 7304                             jae 0x716317
0x716313: 33c9                             xor ecx,ecx
0x716315: eb02                             jmp 0x716319
0x716317: 03ca                             add ecx,edx
0x716319: 3bc8                             cmp ecx,eax
0x71631b: 7302                             jae 0x71631f
0x71631d: 8bc8                             mov ecx,eax
0x71631f: 51                               push ecx
0x716320: 8d742418                         lea esi,[esp+0x18]
0x716324: e857160800                       call 0x797980
0x716329: 8b542418                         mov edx,DWORD PTR [esp+0x18]
0x71632d: 8b742414                         mov esi,DWORD PTR [esp+0x14]
0x716331: 85d2                             test edx,edx
0x716333: 745c                             je 0x716391
0x716335: 8b0cbe                           mov ecx,DWORD PTR [esi+edi*4]
0x716338: 890a                             mov DWORD PTR [edx],ecx
0x71633a: eb55                             jmp 0x716391
0x71633c: 3bd1                             cmp edx,ecx
0x71633e: 7549                             jne 0x716389
0x716340: 8bc2                             mov eax,edx
0x716342: 2bc6                             sub eax,esi
0x716344: c1f802                           sar eax,0x2
0x716347: 3dfeffff3f                       cmp eax,0x3ffffffe
0x71634c: 0f8796000000                     ja 0x7163e8
0x716352: 2bce                             sub ecx,esi
0x716354: 40                               inc eax
0x716355: c1f902                           sar ecx,0x2
0x716358: 3bc1                             cmp eax,ecx
0x71635a: 762d                             jbe 0x716389
0x71635c: 8bd1                             mov edx,ecx
0x71635e: d1ea                             shr edx,1
0x716360: beffffff3f                       mov esi,0x3fffffff
0x716365: 2bf2                             sub esi,edx
0x716367: 3bf1                             cmp esi,ecx
0x716369: 7304                             jae 0x71636f
0x71636b: 33c9                             xor ecx,ecx
0x71636d: eb02                             jmp 0x716371
0x71636f: 03ca                             add ecx,edx
0x716371: 3bc8                             cmp ecx,eax
0x716373: 7302                             jae 0x716377
0x716375: 8bc8                             mov ecx,eax
0x716377: 51                               push ecx
0x716378: 8d742418                         lea esi,[esp+0x18]
0x71637c: e8ff150800                       call 0x797980
0x716381: 8b542418                         mov edx,DWORD PTR [esp+0x18]
0x716385: 8b742414                         mov esi,DWORD PTR [esp+0x14]
0x716389: 85d2                             test edx,edx
0x71638b: 7404                             je 0x716391
0x71638d: 8b07                             mov eax,DWORD PTR [edi]
0x71638f: 8902                             mov DWORD PTR [edx],eax
0x716391: 83c204                           add edx,0x4
0x716394: 807b2d00                         cmp BYTE PTR [ebx+0x2d],0x0
0x716398: 89542418                         mov DWORD PTR [esp+0x18],edx
0x71639c: 753b                             jne 0x7163d9
0x71639e: 8b4b08                           mov ecx,DWORD PTR [ebx+0x8]
0x7163a1: 80792d00                         cmp BYTE PTR [ecx+0x2d],0x0
0x7163a5: 7517                             jne 0x7163be
0x7163a7: 8b01                             mov eax,DWORD PTR [ecx]
0x7163a9: 80782d00                         cmp BYTE PTR [eax+0x2d],0x0
0x7163ad: 750b                             jne 0x7163ba
0x7163af: 90                               nop
0x7163b0: 8bc8                             mov ecx,eax
0x7163b2: 8b01                             mov eax,DWORD PTR [ecx]
0x7163b4: 80782d00                         cmp BYTE PTR [eax+0x2d],0x0
0x7163b8: 74f6                             je 0x7163b0
0x7163ba: 8bd9                             mov ebx,ecx
0x7163bc: eb1b                             jmp 0x7163d9
0x7163be: 8b4304                           mov eax,DWORD PTR [ebx+0x4]
0x7163c1: 80782d00                         cmp BYTE PTR [eax+0x2d],0x0
0x7163c5: 7510                             jne 0x7163d7
0x7163c7: 3b5808                           cmp ebx,DWORD PTR [eax+0x8]
0x7163ca: 750b                             jne 0x7163d7
0x7163cc: 8bd8                             mov ebx,eax
0x7163ce: 8b4004                           mov eax,DWORD PTR [eax+0x4]
0x7163d1: 80782d00                         cmp BYTE PTR [eax+0x2d],0x0
0x7163d5: 74f0                             je 0x7163c7
0x7163d7: 8bd8                             mov ebx,eax
0x7163d9: 3b5c2410                         cmp ebx,DWORD PTR [esp+0x10]
0x7163dd: 0f85edfeffff                     jne 0x7162d0
0x7163e3: e9aafeffff                       jmp 0x716292
0x7163e8: 687823bf00                       push 0xbf2378
0x7163ed: e83e771600                       call 0x87db30
0x7163f2: 8bce                             mov ecx,esi
0x7163f4: 8b5638                           mov edx,DWORD PTR [esi+0x38]
0x7163f7: 52                               push edx
0x7163f8: 50                               push eax
0x7163f9: 51                               push ecx
0x7163fa: 8bcb                             mov ecx,ebx
0x7163fc: e8af2b0000                       call 0x718fb0
0x716401: 8b742414                         mov esi,DWORD PTR [esp+0x14]
0x716405: 47                               inc edi
0x716406: 3b7c2410                         cmp edi,DWORD PTR [esp+0x10]
0x71640a: 0f8295feffff                     jb 0x7162a5
0x716410: 85f6                             test esi,esi
0x716412: 7409                             je 0x71641d
0x716414: 56                               push esi
0x716415: e8f2ad1700                       call 0x89120c
0x71641a: 83c404                           add esp,0x4
0x71641d: 8b4c2428                         mov ecx,DWORD PTR [esp+0x28]
0x716421: 64890d00000000                   mov DWORD PTR fs:0x0,ecx
0x716428: 59                               pop ecx
0x716429: 5f                               pop edi
0x71642a: 5e                               pop esi
0x71642b: 5b                               pop ebx
0x71642c: 8be5                             mov esp,ebp
0x71642e: 5d                               pop ebp
0x71642f: c20400                           ret 0x4

; index_clear 0x718ee0..0x718fa7 exclusive
; Clear releases entry-owned directory/filename objects and index containers.
0x718ee0: 55                               push ebp
0x718ee1: 8bec                             mov ebp,esp
0x718ee3: 53                               push ebx
0x718ee4: 8b5d08                           mov ebx,DWORD PTR [ebp+0x8]
0x718ee7: 8b4308                           mov eax,DWORD PTR [ebx+0x8]
0x718eea: 56                               push esi
0x718eeb: 57                               push edi
0x718eec: 8b38                             mov edi,DWORD PTR [eax]
0x718eee: 3bf8                             cmp edi,eax
0x718ef0: 745a                             je 0x718f4c
0x718ef2: 33db                             xor ebx,ebx
0x718ef4: 8b7724                           mov esi,DWORD PTR [edi+0x24]
0x718ef7: 3bf3                             cmp esi,ebx
0x718ef9: 7445                             je 0x718f40
0x718efb: 837e3010                         cmp DWORD PTR [esi+0x30],0x10
0x718eff: 720c                             jb 0x718f0d
0x718f01: 8b461c                           mov eax,DWORD PTR [esi+0x1c]
0x718f04: 50                               push eax
0x718f05: e802831700                       call 0x89120c
0x718f0a: 83c404                           add esp,0x4
0x718f0d: c746300f000000                   mov DWORD PTR [esi+0x30],0xf
0x718f14: 895e2c                           mov DWORD PTR [esi+0x2c],ebx
0x718f17: 885e1c                           mov BYTE PTR [esi+0x1c],bl
0x718f1a: 837e1410                         cmp DWORD PTR [esi+0x14],0x10
0x718f1e: 720b                             jb 0x718f2b
0x718f20: 8b0e                             mov ecx,DWORD PTR [esi]
0x718f22: 51                               push ecx
0x718f23: e8e4821700                       call 0x89120c
0x718f28: 83c404                           add esp,0x4
0x718f2b: c746140f000000                   mov DWORD PTR [esi+0x14],0xf
0x718f32: 895e10                           mov DWORD PTR [esi+0x10],ebx
0x718f35: 56                               push esi
0x718f36: 881e                             mov BYTE PTR [esi],bl
0x718f38: e8cf821700                       call 0x89120c
0x718f3d: 83c404                           add esp,0x4
0x718f40: 8b3f                             mov edi,DWORD PTR [edi]
0x718f42: 8b5508                           mov edx,DWORD PTR [ebp+0x8]
0x718f45: 3b7a08                           cmp edi,DWORD PTR [edx+0x8]
0x718f48: 75aa                             jne 0x718ef4
0x718f4a: 8bda                             mov ebx,edx
0x718f4c: 8d7308                           lea esi,[ebx+0x8]
0x718f4f: 56                               push esi
0x718f50: e8eb96e3ff                       call 0x552640
0x718f55: 8b06                             mov eax,DWORD PTR [esi]
0x718f57: 8b7314                           mov esi,DWORD PTR [ebx+0x14]
0x718f5a: 8d5314                           lea edx,[ebx+0x14]
0x718f5d: 894508                           mov DWORD PTR [ebp+0x8],eax
0x718f60: 8b4204                           mov eax,DWORD PTR [edx+0x4]
0x718f63: 3bf0                             cmp esi,eax
0x718f65: 741a                             je 0x718f81
0x718f67: 8bc8                             mov ecx,eax
0x718f69: 3bc0                             cmp eax,eax
0x718f6b: 7411                             je 0x718f7e
0x718f6d: 8d4900                           lea ecx,[ecx+0x0]
0x718f70: 8b39                             mov edi,DWORD PTR [ecx]
0x718f72: 893e                             mov DWORD PTR [esi],edi
0x718f74: 83c104                           add ecx,0x4
0x718f77: 83c604                           add esi,0x4
0x718f7a: 3bc8                             cmp ecx,eax
0x718f7c: 75f2                             jne 0x718f70
0x718f7e: 897204                           mov DWORD PTR [edx+0x4],esi
0x718f81: 8b02                             mov eax,DWORD PTR [edx]
0x718f83: 8d4d08                           lea ecx,[ebp+0x8]
0x718f86: 51                               push ecx
0x718f87: 50                               push eax
0x718f88: b910000000                       mov ecx,0x10
0x718f8d: e8fe3c0c00                       call 0x7dcc90
0x718f92: 5f                               pop edi
0x718f93: 5e                               pop esi
0x718f94: c7432407000000                   mov DWORD PTR [ebx+0x24],0x7
0x718f9b: c7432808000000                   mov DWORD PTR [ebx+0x28],0x8
0x718fa2: 5b                               pop ebx
0x718fa3: 5d                               pop ebp
0x718fa4: c20400                           ret 0x4

; filesystem_scan_complete 0x718fb0..0x7197d4 exclusive
; Win32 filesystem enumeration; collect child directories; current-directory files before child recursion; hidden/directory masks; first basename retained.
0x718fb0: 55                               push ebp
0x718fb1: 8bec                             mov ebp,esp
0x718fb3: 6aff                             push 0xffffffff
0x718fb5: 6896899200                       push 0x928996
0x718fba: 64a100000000                     mov eax,fs:0x0
0x718fc0: 50                               push eax
0x718fc1: 81ec38030000                     sub esp,0x338
0x718fc7: a1201fd600                       mov eax,ds:0xd61f20
0x718fcc: 33c5                             xor eax,ebp
0x718fce: 8945ec                           mov DWORD PTR [ebp-0x14],eax
0x718fd1: 53                               push ebx
0x718fd2: 56                               push esi
0x718fd3: 57                               push edi
0x718fd4: 50                               push eax
0x718fd5: 8d45f4                           lea eax,[ebp-0xc]
0x718fd8: 64a300000000                     mov fs:0x0,eax
0x718fde: 8b4508                           mov eax,DWORD PTR [ebp+0x8]
0x718fe1: 8b750c                           mov esi,DWORD PTR [ebp+0xc]
0x718fe4: 33db                             xor ebx,ebx
0x718fe6: 898de0fcffff                     mov DWORD PTR [ebp-0x320],ecx
0x718fec: 8985dcfcffff                     mov DWORD PTR [ebp-0x324],eax
0x718ff2: 89b5e8fcffff                     mov DWORD PTR [ebp-0x318],esi
0x718ff8: 899dc8fcffff                     mov DWORD PTR [ebp-0x338],ebx
0x718ffe: 899dccfcffff                     mov DWORD PTR [ebp-0x334],ebx
0x719004: 899dd0fcffff                     mov DWORD PTR [ebp-0x330],ebx
0x71900a: 895dfc                           mov DWORD PTR [ebp-0x4],ebx
0x71900d: 395d10                           cmp DWORD PTR [ebp+0x10],ebx
0x719010: 0f84a4010000                     je 0x7191ba
0x719016: 8bc6                             mov eax,esi
0x719018: c745e40f000000                   mov DWORD PTR [ebp-0x1c],0xf
0x71901f: 895de0                           mov DWORD PTR [ebp-0x20],ebx
0x719022: 885dd0                           mov BYTE PTR [ebp-0x30],bl
0x719025: 8d5001                           lea edx,[eax+0x1]
0x719028: 8a08                             mov cl,BYTE PTR [eax]
0x71902a: 40                               inc eax
0x71902b: 84c9                             test cl,cl
0x71902d: 75f9                             jne 0x719028
0x71902f: 2bc2                             sub eax,edx
0x719031: 50                               push eax
0x719032: 56                               push esi
0x719033: 8d4dd0                           lea ecx,[ebp-0x30]
0x719036: e8359aceff                       call 0x402a70
0x71903b: 6a03                             push 0x3
0x71903d: 68b044c400                       push 0xc444b0
0x719042: 8d4dd0                           lea ecx,[ebp-0x30]
0x719045: c645fc01                         mov BYTE PTR [ebp-0x4],0x1
0x719049: e8728fceff                       call 0x401fc0
0x71904e: 6840010000                       push 0x140
0x719053: 8d8d34feffff                     lea ecx,[ebp-0x1cc]
0x719059: 53                               push ebx
0x71905a: 51                               push ecx
0x71905b: e800581800                       call 0x89e860
0x719060: 8b45d0                           mov eax,DWORD PTR [ebp-0x30]
0x719063: 83c40c                           add esp,0xc
0x719066: 837de410                         cmp DWORD PTR [ebp-0x1c],0x10
0x71906a: 7303                             jae 0x71906f
0x71906c: 8d45d0                           lea eax,[ebp-0x30]
0x71906f: 8d9534feffff                     lea edx,[ebp-0x1cc]
0x719075: 52                               push edx
0x719076: 50                               push eax
0x719077: ff154422bd00                     call DWORD PTR ds:0xbd2244
0x71907d: 8bf8                             mov edi,eax
0x71907f: 89bdf0fcffff                     mov DWORD PTR [ebp-0x310],edi
0x719085: 83ffff                           cmp edi,0xffffffff
0x719088: 7516                             jne 0x7190a0
0x71908a: 50                               push eax
0x71908b: ff154022bd00                     call DWORD PTR ds:0xbd2240
0x719091: e907010000                       jmp 0x71919d
0x719096: eb08                             jmp 0x7190a0
0x719098: 8da42400000000                   lea esp,[esp+0x0]
0x71909f: 90                               nop
0x7190a0: 8a8534feffff                     mov al,BYTE PTR [ebp-0x1cc]
0x7190a6: a810                             test al,0x10
0x7190a8: 0f84d3000000                     je 0x719181
0x7190ae: a802                             test al,0x2
0x7190b0: 0f85cb000000                     jne 0x719181
0x7190b6: b99011c400                       mov ecx,0xc41190
0x7190bb: 8d8560feffff                     lea eax,[ebp-0x1a0]
0x7190c1: 8a10                             mov dl,BYTE PTR [eax]
0x7190c3: 3a11                             cmp dl,BYTE PTR [ecx]
0x7190c5: 751a                             jne 0x7190e1
0x7190c7: 84d2                             test dl,dl
0x7190c9: 7412                             je 0x7190dd
0x7190cb: 8a5001                           mov dl,BYTE PTR [eax+0x1]
0x7190ce: 3a5101                           cmp dl,BYTE PTR [ecx+0x1]
0x7190d1: 750e                             jne 0x7190e1
0x7190d3: 83c002                           add eax,0x2
0x7190d6: 83c102                           add ecx,0x2
0x7190d9: 84d2                             test dl,dl
0x7190db: 75e4                             jne 0x7190c1
0x7190dd: 33c0                             xor eax,eax
0x7190df: eb05                             jmp 0x7190e6
0x7190e1: 1bc0                             sbb eax,eax
0x7190e3: 83d8ff                           sbb eax,0xffffffff
0x7190e6: 3bc3                             cmp eax,ebx
0x7190e8: 0f8493000000                     je 0x719181
0x7190ee: b9802cc400                       mov ecx,0xc42c80
0x7190f3: 8d8560feffff                     lea eax,[ebp-0x1a0]
0x7190f9: 8da42400000000                   lea esp,[esp+0x0]
0x719100: 8a10                             mov dl,BYTE PTR [eax]
0x719102: 3a11                             cmp dl,BYTE PTR [ecx]
0x719104: 751a                             jne 0x719120
0x719106: 84d2                             test dl,dl
0x719108: 7412                             je 0x71911c
0x71910a: 8a5001                           mov dl,BYTE PTR [eax+0x1]
0x71910d: 3a5101                           cmp dl,BYTE PTR [ecx+0x1]
0x719110: 750e                             jne 0x719120
0x719112: 83c002                           add eax,0x2
0x719115: 83c102                           add ecx,0x2
0x719118: 84d2                             test dl,dl
0x71911a: 75e4                             jne 0x719100
0x71911c: 33c0                             xor eax,eax
0x71911e: eb05                             jmp 0x719125
0x719120: 1bc0                             sbb eax,eax
0x719122: 83d8ff                           sbb eax,0xffffffff
0x719125: 3bc3                             cmp eax,ebx
0x719127: 7458                             je 0x719181
0x719129: 8d8560feffff                     lea eax,[ebp-0x1a0]
0x71912f: c745c80f000000                   mov DWORD PTR [ebp-0x38],0xf
0x719136: 895dc4                           mov DWORD PTR [ebp-0x3c],ebx
0x719139: c645b400                         mov BYTE PTR [ebp-0x4c],0x0
0x71913d: 8d5001                           lea edx,[eax+0x1]
0x719140: 8a08                             mov cl,BYTE PTR [eax]
0x719142: 40                               inc eax
0x719143: 84c9                             test cl,cl
0x719145: 75f9                             jne 0x719140
0x719147: 2bc2                             sub eax,edx
0x719149: 50                               push eax
0x71914a: 8d8560feffff                     lea eax,[ebp-0x1a0]
0x719150: 50                               push eax
0x719151: 8d4db4                           lea ecx,[ebp-0x4c]
0x719154: e81799ceff                       call 0x402a70
0x719159: 8d4db4                           lea ecx,[ebp-0x4c]
0x71915c: 8dbdc8fcffff                     lea edi,[ebp-0x338]
0x719162: c645fc02                         mov BYTE PTR [ebp-0x4],0x2
0x719166: e8f57ad2ff                       call 0x440c60
0x71916b: c645fc01                         mov BYTE PTR [ebp-0x4],0x1
0x71916f: 837dc810                         cmp DWORD PTR [ebp-0x38],0x10
0x719173: 720c                             jb 0x719181
0x719175: 8b4db4                           mov ecx,DWORD PTR [ebp-0x4c]
0x719178: 51                               push ecx
0x719179: e88e801700                       call 0x89120c
0x71917e: 83c404                           add esp,0x4
0x719181: 8bbdf0fcffff                     mov edi,DWORD PTR [ebp-0x310]
0x719187: 8d9534feffff                     lea edx,[ebp-0x1cc]
0x71918d: 52                               push edx
0x71918e: 57                               push edi
0x71918f: ff15a022bd00                     call DWORD PTR ds:0xbd22a0
0x719195: 85c0                             test eax,eax
0x719197: 0f8503ffffff                     jne 0x7190a0
0x71919d: 57                               push edi
0x71919e: ff154022bd00                     call DWORD PTR ds:0xbd2240
0x7191a4: c645fc00                         mov BYTE PTR [ebp-0x4],0x0
0x7191a8: 837de410                         cmp DWORD PTR [ebp-0x1c],0x10
0x7191ac: 720c                             jb 0x7191ba
0x7191ae: 8b45d0                           mov eax,DWORD PTR [ebp-0x30]
0x7191b1: 50                               push eax
0x7191b2: e855801700                       call 0x89120c
0x7191b7: 83c404                           add esp,0x4
0x7191ba: 8bc6                             mov eax,esi
0x7191bc: c7458c0f000000                   mov DWORD PTR [ebp-0x74],0xf
0x7191c3: 895d88                           mov DWORD PTR [ebp-0x78],ebx
0x7191c6: c68578ffffff00                   mov BYTE PTR [ebp-0x88],0x0
0x7191cd: 8d5001                           lea edx,[eax+0x1]
0x7191d0: 8a08                             mov cl,BYTE PTR [eax]
0x7191d2: 40                               inc eax
0x7191d3: 84c9                             test cl,cl
0x7191d5: 75f9                             jne 0x7191d0
0x7191d7: 2bc2                             sub eax,edx
0x7191d9: 50                               push eax
0x7191da: 56                               push esi
0x7191db: 8d8d78ffffff                     lea ecx,[ebp-0x88]
0x7191e1: e88a98ceff                       call 0x402a70
0x7191e6: 8bb5dcfcffff                     mov esi,DWORD PTR [ebp-0x324]
0x7191ec: 8bc6                             mov eax,esi
0x7191ee: c645fc03                         mov BYTE PTR [ebp-0x4],0x3
0x7191f2: 8d5001                           lea edx,[eax+0x1]
0x7191f5: 8a08                             mov cl,BYTE PTR [eax]
0x7191f7: 40                               inc eax
0x7191f8: 84c9                             test cl,cl
0x7191fa: 75f9                             jne 0x7191f5
0x7191fc: 2bc2                             sub eax,edx
0x7191fe: 50                               push eax
0x7191ff: 56                               push esi
0x719200: 8d8d78ffffff                     lea ecx,[ebp-0x88]
0x719206: e8b58dceff                       call 0x401fc0
0x71920b: 6840010000                       push 0x140
0x719210: 8d8df4fcffff                     lea ecx,[ebp-0x30c]
0x719216: 53                               push ebx
0x719217: 51                               push ecx
0x719218: e843561800                       call 0x89e860
0x71921d: 8b8578ffffff                     mov eax,DWORD PTR [ebp-0x88]
0x719223: 83c40c                           add esp,0xc
0x719226: 837d8c10                         cmp DWORD PTR [ebp-0x74],0x10
0x71922a: 7306                             jae 0x719232
0x71922c: 8d8578ffffff                     lea eax,[ebp-0x88]
0x719232: 8d95f4fcffff                     lea edx,[ebp-0x30c]
0x719238: 52                               push edx
0x719239: 50                               push eax
0x71923a: ff154422bd00                     call DWORD PTR ds:0xbd2244
0x719240: 8985f0fcffff                     mov DWORD PTR [ebp-0x310],eax
0x719246: 83f8ff                           cmp eax,0xffffffff
0x719249: 0f8591010000                     jne 0x7193e0
0x71924f: 50                               push eax
0x719250: ff154022bd00                     call DWORD PTR ds:0xbd2240
0x719256: 8b8df0fcffff                     mov ecx,DWORD PTR [ebp-0x310]
0x71925c: 51                               push ecx
0x71925d: ff154022bd00                     call DWORD PTR ds:0xbd2240
0x719263: 8b8dccfcffff                     mov ecx,DWORD PTR [ebp-0x334]
0x719269: 8bbdc8fcffff                     mov edi,DWORD PTR [ebp-0x338]
0x71926f: 2bcf                             sub ecx,edi
0x719271: b893244992                       mov eax,0x92492493
0x719276: f7e9                             imul ecx
0x719278: 03d1                             add edx,ecx
0x71927a: c1fa04                           sar edx,0x4
0x71927d: 8bc2                             mov eax,edx
0x71927f: c1e81f                           shr eax,0x1f
0x719282: 03c2                             add eax,edx
0x719284: bb10000000                       mov ebx,0x10
0x719289: 0f84a2000000                     je 0x719331
0x71928f: 8bb5e8fcffff                     mov esi,DWORD PTR [ebp-0x318]
0x719295: 8985f0fcffff                     mov DWORD PTR [ebp-0x310],eax
0x71929b: 8bc6                             mov eax,esi
0x71929d: c745e40f000000                   mov DWORD PTR [ebp-0x1c],0xf
0x7192a4: c745e000000000                   mov DWORD PTR [ebp-0x20],0x0
0x7192ab: c645d000                         mov BYTE PTR [ebp-0x30],0x0
0x7192af: 8d4801                           lea ecx,[eax+0x1]
0x7192b2: 8a10                             mov dl,BYTE PTR [eax]
0x7192b4: 40                               inc eax
0x7192b5: 84d2                             test dl,dl
0x7192b7: 75f9                             jne 0x7192b2
0x7192b9: 2bc1                             sub eax,ecx
0x7192bb: 50                               push eax
0x7192bc: 56                               push esi
0x7192bd: 8d4dd0                           lea ecx,[ebp-0x30]
0x7192c0: e8ab97ceff                       call 0x402a70
0x7192c5: 6aff                             push 0xffffffff
0x7192c7: 6a00                             push 0x0
0x7192c9: 57                               push edi
0x7192ca: 8d4dd0                           lea ecx,[ebp-0x30]
0x7192cd: c645fc09                         mov BYTE PTR [ebp-0x4],0x9
0x7192d1: e8fa8bceff                       call 0x401ed0
0x7192d6: 6a01                             push 0x1
0x7192d8: 68d420c400                       push 0xc420d4
0x7192dd: 8d4dd0                           lea ecx,[ebp-0x30]
0x7192e0: e8db8cceff                       call 0x401fc0
0x7192e5: 8b45d0                           mov eax,DWORD PTR [ebp-0x30]
0x7192e8: 395de4                           cmp DWORD PTR [ebp-0x1c],ebx
0x7192eb: 7303                             jae 0x7192f0
0x7192ed: 8d45d0                           lea eax,[ebp-0x30]
0x7192f0: 8b5510                           mov edx,DWORD PTR [ebp+0x10]
0x7192f3: 8b8de0fcffff                     mov ecx,DWORD PTR [ebp-0x320]
0x7192f9: 52                               push edx
0x7192fa: 50                               push eax
0x7192fb: 8b85dcfcffff                     mov eax,DWORD PTR [ebp-0x324]
0x719301: 50                               push eax
0x719302: e8a9fcffff                       call 0x718fb0
0x719307: c645fc03                         mov BYTE PTR [ebp-0x4],0x3
0x71930b: 395de4                           cmp DWORD PTR [ebp-0x1c],ebx
0x71930e: 720c                             jb 0x71931c
0x719310: 8b4dd0                           mov ecx,DWORD PTR [ebp-0x30]
0x719313: 51                               push ecx
0x719314: e8f37e1700                       call 0x89120c
0x719319: 83c404                           add esp,0x4
0x71931c: 83c71c                           add edi,0x1c
0x71931f: ff8df0fcffff                     dec DWORD PTR [ebp-0x310]
0x719325: 0f8570ffffff                     jne 0x71929b
0x71932b: 8bbdc8fcffff                     mov edi,DWORD PTR [ebp-0x338]
0x719331: 8b95e0fcffff                     mov edx,DWORD PTR [ebp-0x320]
0x719337: 8b420c                           mov eax,DWORD PTR [edx+0xc]
0x71933a: 8985ecfcffff                     mov DWORD PTR [ebp-0x314],eax
0x719340: 395d8c                           cmp DWORD PTR [ebp-0x74],ebx
0x719343: 720f                             jb 0x719354
0x719345: 8b8d78ffffff                     mov ecx,DWORD PTR [ebp-0x88]
0x71934b: 51                               push ecx
0x71934c: e8bb7e1700                       call 0x89120c
0x719351: 83c404                           add esp,0x4
0x719354: c7458c0f000000                   mov DWORD PTR [ebp-0x74],0xf
0x71935b: c7458800000000                   mov DWORD PTR [ebp-0x78],0x0
0x719362: c68578ffffff00                   mov BYTE PTR [ebp-0x88],0x0
0x719369: 85ff                             test edi,edi
0x71936b: 744a                             je 0x7193b7
0x71936d: 8bb5c8fcffff                     mov esi,DWORD PTR [ebp-0x338]
0x719373: 8bbdccfcffff                     mov edi,DWORD PTR [ebp-0x334]
0x719379: 3bf7                             cmp esi,edi
0x71937b: 742b                             je 0x7193a8
0x71937d: 8d4900                           lea ecx,[ecx+0x0]
0x719380: 395e14                           cmp DWORD PTR [esi+0x14],ebx
0x719383: 720b                             jb 0x719390
0x719385: 8b16                             mov edx,DWORD PTR [esi]
0x719387: 52                               push edx
0x719388: e87f7e1700                       call 0x89120c
0x71938d: 83c404                           add esp,0x4
0x719390: c746140f000000                   mov DWORD PTR [esi+0x14],0xf
0x719397: c7461000000000                   mov DWORD PTR [esi+0x10],0x0
0x71939e: c60600                           mov BYTE PTR [esi],0x0
0x7193a1: 83c61c                           add esi,0x1c
0x7193a4: 3bf7                             cmp esi,edi
0x7193a6: 75d8                             jne 0x719380
0x7193a8: 8b85c8fcffff                     mov eax,DWORD PTR [ebp-0x338]
0x7193ae: 50                               push eax
0x7193af: e8587e1700                       call 0x89120c
0x7193b4: 83c404                           add esp,0x4
0x7193b7: 8b85ecfcffff                     mov eax,DWORD PTR [ebp-0x314]
0x7193bd: 8b4df4                           mov ecx,DWORD PTR [ebp-0xc]
0x7193c0: 64890d00000000                   mov DWORD PTR fs:0x0,ecx
0x7193c7: 59                               pop ecx
0x7193c8: 5f                               pop edi
0x7193c9: 5e                               pop esi
0x7193ca: 5b                               pop ebx
0x7193cb: 8b4dec                           mov ecx,DWORD PTR [ebp-0x14]
0x7193ce: 33cd                             xor ecx,ebp
0x7193d0: e82c7c1700                       call 0x891001
0x7193d5: 8be5                             mov esp,ebp
0x7193d7: 5d                               pop ebp
0x7193d8: c20c00                           ret 0xc
0x7193db: eb03                             jmp 0x7193e0
0x7193dd: 8d4900                           lea ecx,[ecx+0x0]
0x7193e0: f685f4fcffff12                   test BYTE PTR [ebp-0x30c],0x12
0x7193e7: 0f85bc030000                     jne 0x7197a9
0x7193ed: 6a38                             push 0x38
0x7193ef: e8747e1700                       call 0x891268
0x7193f4: 33db                             xor ebx,ebx
0x7193f6: 83c404                           add esp,0x4
0x7193f9: 3bc3                             cmp eax,ebx
0x7193fb: 7420                             je 0x71941d
0x7193fd: b90f000000                       mov ecx,0xf
0x719402: 894814                           mov DWORD PTR [eax+0x14],ecx
0x719405: 895810                           mov DWORD PTR [eax+0x10],ebx
0x719408: 8818                             mov BYTE PTR [eax],bl
0x71940a: 894830                           mov DWORD PTR [eax+0x30],ecx
0x71940d: 89582c                           mov DWORD PTR [eax+0x2c],ebx
0x719410: 88581c                           mov BYTE PTR [eax+0x1c],bl
0x719413: 8bf0                             mov esi,eax
0x719415: 8985e4fcffff                     mov DWORD PTR [ebp-0x31c],eax
0x71941b: eb08                             jmp 0x719425
0x71941d: 33f6                             xor esi,esi
0x71941f: 89b5e4fcffff                     mov DWORD PTR [ebp-0x31c],esi
0x719425: 8b95e8fcffff                     mov edx,DWORD PTR [ebp-0x318]
0x71942b: 8bc2                             mov eax,edx
0x71942d: 8d7801                           lea edi,[eax+0x1]
0x719430: 8a08                             mov cl,BYTE PTR [eax]
0x719432: 40                               inc eax
0x719433: 84c9                             test cl,cl
0x719435: 75f9                             jne 0x719430
0x719437: 2bc7                             sub eax,edi
0x719439: 50                               push eax
0x71943a: 52                               push edx
0x71943b: 8bce                             mov ecx,esi
0x71943d: e82e96ceff                       call 0x402a70
0x719442: 8d8520fdffff                     lea eax,[ebp-0x2e0]
0x719448: 8d4e1c                           lea ecx,[esi+0x1c]
0x71944b: 8d7001                           lea esi,[eax+0x1]
0x71944e: 8bff                             mov edi,edi
0x719450: 8a10                             mov dl,BYTE PTR [eax]
0x719452: 40                               inc eax
0x719453: 84d2                             test dl,dl
0x719455: 75f9                             jne 0x719450
0x719457: 2bc6                             sub eax,esi
0x719459: 50                               push eax
0x71945a: 8d8520fdffff                     lea eax,[ebp-0x2e0]
0x719460: 50                               push eax
0x719461: e80a96ceff                       call 0x402a70
0x719466: 8d8d20fdffff                     lea ecx,[ebp-0x2e0]
0x71946c: 51                               push ecx
0x71946d: 8d956cfeffff                     lea edx,[ebp-0x194]
0x719473: 6804010000                       push 0x104
0x719478: 52                               push edx
0x719479: e8dba61700                       call 0x893b59
0x71947e: 83c40c                           add esp,0xc
0x719481: 8d856cfeffff                     lea eax,[ebp-0x194]
0x719487: 50                               push eax
0x719488: e823040000                       call 0x7198b0
0x71948d: 8d856cfeffff                     lea eax,[ebp-0x194]
0x719493: c745c80f000000                   mov DWORD PTR [ebp-0x38],0xf
0x71949a: 895dc4                           mov DWORD PTR [ebp-0x3c],ebx
0x71949d: 885db4                           mov BYTE PTR [ebp-0x4c],bl
0x7194a0: 8d4801                           lea ecx,[eax+0x1]
0x7194a3: 8a10                             mov dl,BYTE PTR [eax]
0x7194a5: 40                               inc eax
0x7194a6: 84d2                             test dl,dl
0x7194a8: 75f9                             jne 0x7194a3
0x7194aa: 2bc1                             sub eax,ecx
0x7194ac: 50                               push eax
0x7194ad: 8d8d6cfeffff                     lea ecx,[ebp-0x194]
0x7194b3: 51                               push ecx
0x7194b4: 8d4db4                           lea ecx,[ebp-0x4c]
0x7194b7: e8b495ceff                       call 0x402a70
0x7194bc: 8bbde0fcffff                     mov edi,DWORD PTR [ebp-0x320]
0x7194c2: 8d55b4                           lea edx,[ebp-0x4c]
0x7194c5: c645fc04                         mov BYTE PTR [ebp-0x4],0x4
0x7194c9: 8b7708                           mov esi,DWORD PTR [edi+0x8]
0x7194cc: 52                               push edx
0x7194cd: 8d85ecfcffff                     lea eax,[ebp-0x314]
0x7194d3: 83c704                           add edi,0x4
0x7194d6: 50                               push eax
0x7194d7: 8bc7                             mov eax,edi
0x7194d9: e812f20900                       call 0x7b86f0
0x7194de: 39b5ecfcffff                     cmp DWORD PTR [ebp-0x314],esi
0x7194e4: c645fc03                         mov BYTE PTR [ebp-0x4],0x3
0x7194e8: 0f95c3                           setne bl
0x7194eb: 837dc810                         cmp DWORD PTR [ebp-0x38],0x10
0x7194ef: 720c                             jb 0x7194fd
0x7194f1: 8b4db4                           mov ecx,DWORD PTR [ebp-0x4c]
0x7194f4: 51                               push ecx
0x7194f5: e8127d1700                       call 0x89120c
0x7194fa: 83c404                           add esp,0x4
0x7194fd: 8d856cfeffff                     lea eax,[ebp-0x194]
0x719503: 84db                             test bl,bl
0x719505: 0f8407020000                     je 0x719712
0x71950b: 33f6                             xor esi,esi
0x71950d: c745c80f000000                   mov DWORD PTR [ebp-0x38],0xf
0x719514: 8975c4                           mov DWORD PTR [ebp-0x3c],esi
0x719517: c645b400                         mov BYTE PTR [ebp-0x4c],0x0
0x71951b: 8d5001                           lea edx,[eax+0x1]
0x71951e: 8bff                             mov edi,edi
0x719520: 8a08                             mov cl,BYTE PTR [eax]
0x719522: 40                               inc eax
0x719523: 84c9                             test cl,cl
0x719525: 75f9                             jne 0x719520
0x719527: 2bc2                             sub eax,edx
0x719529: 50                               push eax
0x71952a: 8d956cfeffff                     lea edx,[ebp-0x194]
0x719530: 52                               push edx
0x719531: 8d4db4                           lea ecx,[ebp-0x4c]
0x719534: e83795ceff                       call 0x402a70
0x719539: 8d45b4                           lea eax,[ebp-0x4c]
0x71953c: 50                               push eax
0x71953d: 8d8dd8fcffff                     lea ecx,[ebp-0x328]
0x719543: 51                               push ecx
0x719544: 8bc7                             mov eax,edi
0x719546: c645fc05                         mov BYTE PTR [ebp-0x4],0x5
0x71954a: e8a1f10900                       call 0x7b86f0
0x71954f: bb10000000                       mov ebx,0x10
0x719554: c645fc03                         mov BYTE PTR [ebp-0x4],0x3
0x719558: 395dc8                           cmp DWORD PTR [ebp-0x38],ebx
0x71955b: 720c                             jb 0x719569
0x71955d: 8b55b4                           mov edx,DWORD PTR [ebp-0x4c]
0x719560: 52                               push edx
0x719561: e8a67c1700                       call 0x89120c
0x719566: 83c404                           add esp,0x4
0x719569: 8bbdd8fcffff                     mov edi,DWORD PTR [ebp-0x328]
0x71956f: 8b4f24                           mov ecx,DWORD PTR [edi+0x24]
0x719572: 395914                           cmp DWORD PTR [ecx+0x14],ebx
0x719575: 7202                             jb 0x719579
0x719577: 8b09                             mov ecx,DWORD PTR [ecx]
0x719579: 8bc1                             mov eax,ecx
0x71957b: 8975a8                           mov DWORD PTR [ebp-0x58],esi
0x71957e: c745ac0f000000                   mov DWORD PTR [ebp-0x54],0xf
0x719585: c6459800                         mov BYTE PTR [ebp-0x68],0x0
0x719589: 8d7001                           lea esi,[eax+0x1]
0x71958c: 8d642400                         lea esp,[esp+0x0]
0x719590: 8a10                             mov dl,BYTE PTR [eax]
0x719592: 40                               inc eax
0x719593: 84d2                             test dl,dl
0x719595: 75f9                             jne 0x719590
0x719597: 2bc6                             sub eax,esi
0x719599: 50                               push eax
0x71959a: 51                               push ecx
0x71959b: 8d4d98                           lea ecx,[ebp-0x68]
0x71959e: e8cd94ceff                       call 0x402a70
0x7195a3: c645fc06                         mov BYTE PTR [ebp-0x4],0x6
0x7195a7: 395f1c                           cmp DWORD PTR [edi+0x1c],ebx
0x7195aa: 7205                             jb 0x7195b1
0x7195ac: 8b4f08                           mov ecx,DWORD PTR [edi+0x8]
0x7195af: eb03                             jmp 0x7195b4
0x7195b1: 8d4f08                           lea ecx,[edi+0x8]
0x7195b4: 8bc1                             mov eax,ecx
0x7195b6: 8d7001                           lea esi,[eax+0x1]
0x7195b9: 8da42400000000                   lea esp,[esp+0x0]
0x7195c0: 8a10                             mov dl,BYTE PTR [eax]
0x7195c2: 40                               inc eax
0x7195c3: 84d2                             test dl,dl
0x7195c5: 75f9                             jne 0x7195c0
0x7195c7: 2bc6                             sub eax,esi
0x7195c9: 50                               push eax
0x7195ca: 51                               push ecx
0x7195cb: 8d4d98                           lea ecx,[ebp-0x68]
0x7195ce: e8ed89ceff                       call 0x401fc0
0x7195d3: 6a0b                             push 0xb
0x7195d5: 68b444c400                       push 0xc444b4
0x7195da: 8d4dd0                           lea ecx,[ebp-0x30]
0x7195dd: c745e40f000000                   mov DWORD PTR [ebp-0x1c],0xf
0x7195e4: c745e000000000                   mov DWORD PTR [ebp-0x20],0x0
0x7195eb: c645d000                         mov BYTE PTR [ebp-0x30],0x0
0x7195ef: e87c94ceff                       call 0x402a70
0x7195f4: c645fc07                         mov BYTE PTR [ebp-0x4],0x7
0x7195f8: 8b85d8fcffff                     mov eax,DWORD PTR [ebp-0x328]
0x7195fe: 8b4024                           mov eax,DWORD PTR [eax+0x24]
0x719601: bb10000000                       mov ebx,0x10
0x719606: 395814                           cmp DWORD PTR [eax+0x14],ebx
0x719609: 7204                             jb 0x71960f
0x71960b: 8b10                             mov edx,DWORD PTR [eax]
0x71960d: eb02                             jmp 0x719611
0x71960f: 8bd0                             mov edx,eax
0x719611: 8bc2                             mov eax,edx
0x719613: 8d7001                           lea esi,[eax+0x1]
0x719616: 8a08                             mov cl,BYTE PTR [eax]
0x719618: 40                               inc eax
0x719619: 84c9                             test cl,cl
0x71961b: 75f9                             jne 0x719616
0x71961d: 2bc6                             sub eax,esi
0x71961f: 50                               push eax
0x719620: 52                               push edx
0x719621: 8d4dd0                           lea ecx,[ebp-0x30]
0x719624: e89789ceff                       call 0x401fc0
0x719629: 395f1c                           cmp DWORD PTR [edi+0x1c],ebx
0x71962c: 7205                             jb 0x719633
0x71962e: 8b4f08                           mov ecx,DWORD PTR [edi+0x8]
0x719631: eb03                             jmp 0x719636
0x719633: 8d4f08                           lea ecx,[edi+0x8]
0x719636: 8bc1                             mov eax,ecx
0x719638: 8d7001                           lea esi,[eax+0x1]
0x71963b: eb03                             jmp 0x719640
0x71963d: 8d4900                           lea ecx,[ecx+0x0]
0x719640: 8a10                             mov dl,BYTE PTR [eax]
0x719642: 40                               inc eax
0x719643: 84d2                             test dl,dl
0x719645: 75f9                             jne 0x719640
0x719647: 2bc6                             sub eax,esi
0x719649: 50                               push eax
0x71964a: 51                               push ecx
0x71964b: 8d4dd0                           lea ecx,[ebp-0x30]
0x71964e: e86d89ceff                       call 0x401fc0
0x719653: 6a02                             push 0x2
0x719655: 68c044c400                       push 0xc444c0
0x71965a: 8d4dd0                           lea ecx,[ebp-0x30]
0x71965d: e85e89ceff                       call 0x401fc0
0x719662: 8bb5e8fcffff                     mov esi,DWORD PTR [ebp-0x318]
0x719668: 8bc6                             mov eax,esi
0x71966a: 8d5001                           lea edx,[eax+0x1]
0x71966d: 8d4900                           lea ecx,[ecx+0x0]
0x719670: 8a08                             mov cl,BYTE PTR [eax]
0x719672: 40                               inc eax
0x719673: 84c9                             test cl,cl
0x719675: 75f9                             jne 0x719670
0x719677: 2bc2                             sub eax,edx
0x719679: 50                               push eax
0x71967a: 56                               push esi
0x71967b: 8d4dd0                           lea ecx,[ebp-0x30]
0x71967e: e83d89ceff                       call 0x401fc0
0x719683: 8d8520fdffff                     lea eax,[ebp-0x2e0]
0x719689: 8d5001                           lea edx,[eax+0x1]
0x71968c: 8d642400                         lea esp,[esp+0x0]
0x719690: 8a08                             mov cl,BYTE PTR [eax]
0x719692: 40                               inc eax
0x719693: 84c9                             test cl,cl
0x719695: 75f9                             jne 0x719690
0x719697: 2bc2                             sub eax,edx
0x719699: 50                               push eax
0x71969a: 8d8d20fdffff                     lea ecx,[ebp-0x2e0]
0x7196a0: 51                               push ecx
0x7196a1: 8d4dd0                           lea ecx,[ebp-0x30]
0x7196a4: e81789ceff                       call 0x401fc0
0x7196a9: 6a01                             push 0x1
0x7196ab: 68c011c400                       push 0xc411c0
0x7196b0: 8d4dd0                           lea ecx,[ebp-0x30]
0x7196b3: e80889ceff                       call 0x401fc0
0x7196b8: 8b45d0                           mov eax,DWORD PTR [ebp-0x30]
0x7196bb: 395de4                           cmp DWORD PTR [ebp-0x1c],ebx
0x7196be: 7303                             jae 0x7196c3
0x7196c0: 8d45d0                           lea eax,[ebp-0x30]
0x7196c3: 50                               push eax
0x7196c4: ff150c21bd00                     call DWORD PTR ds:0xbd210c
0x7196ca: 8bb5e4fcffff                     mov esi,DWORD PTR [ebp-0x31c]
0x7196d0: 85f6                             test esi,esi
0x7196d2: 7405                             je 0x7196d9
0x7196d4: e8a7f7ffff                       call 0x718e80
0x7196d9: 395de4                           cmp DWORD PTR [ebp-0x1c],ebx
0x7196dc: 720c                             jb 0x7196ea
0x7196de: 8b55d0                           mov edx,DWORD PTR [ebp-0x30]
0x7196e1: 52                               push edx
0x7196e2: e8257b1700                       call 0x89120c
0x7196e7: 83c404                           add esp,0x4
0x7196ea: c645fc03                         mov BYTE PTR [ebp-0x4],0x3
0x7196ee: c745e40f000000                   mov DWORD PTR [ebp-0x1c],0xf
0x7196f5: c745e000000000                   mov DWORD PTR [ebp-0x20],0x0
0x7196fc: c645d000                         mov BYTE PTR [ebp-0x30],0x0
0x719700: 395dac                           cmp DWORD PTR [ebp-0x54],ebx
0x719703: 0f82a0000000                     jb 0x7197a9
0x719709: 8b4598                           mov eax,DWORD PTR [ebp-0x68]
0x71970c: 50                               push eax
0x71970d: e98f000000                       jmp 0x7197a1
0x719712: c745a80f000000                   mov DWORD PTR [ebp-0x58],0xf
0x719719: c745a400000000                   mov DWORD PTR [ebp-0x5c],0x0
0x719720: c6459400                         mov BYTE PTR [ebp-0x6c],0x0
0x719724: 8d4801                           lea ecx,[eax+0x1]
0x719727: 8a10                             mov dl,BYTE PTR [eax]
0x719729: 40                               inc eax
0x71972a: 84d2                             test dl,dl
0x71972c: 75f9                             jne 0x719727
0x71972e: 2bc1                             sub eax,ecx
0x719730: 50                               push eax
0x719731: 8d8d6cfeffff                     lea ecx,[ebp-0x194]
0x719737: 51                               push ecx
0x719738: 8d4d94                           lea ecx,[ebp-0x6c]
0x71973b: e83093ceff                       call 0x402a70
0x719740: 8b95e4fcffff                     mov edx,DWORD PTR [ebp-0x31c]
0x719746: 8955b0                           mov DWORD PTR [ebp-0x50],edx
0x719749: c645fc08                         mov BYTE PTR [ebp-0x4],0x8
0x71974d: 8b4704                           mov eax,DWORD PTR [edi+0x4]
0x719750: 8b30                             mov esi,DWORD PTR [eax]
0x719752: 8b4e04                           mov ecx,DWORD PTR [esi+0x4]
0x719755: 8d4594                           lea eax,[ebp-0x6c]
0x719758: 50                               push eax
0x719759: 51                               push ecx
0x71975a: 56                               push esi
0x71975b: e830040000                       call 0x719b90
0x719760: 8b4f08                           mov ecx,DWORD PTR [edi+0x8]
0x719763: bafeffff07                       mov edx,0x7fffffe
0x719768: 2bd1                             sub edx,ecx
0x71976a: 83fa01                           cmp edx,0x1
0x71976d: 725b                             jb 0x7197ca
0x71976f: 41                               inc ecx
0x719770: 894f08                           mov DWORD PTR [edi+0x8],ecx
0x719773: 894604                           mov DWORD PTR [esi+0x4],eax
0x719776: 8b4804                           mov ecx,DWORD PTR [eax+0x4]
0x719779: 8901                             mov DWORD PTR [ecx],eax
0x71977b: 8b4704                           mov eax,DWORD PTR [edi+0x4]
0x71977e: 8b08                             mov ecx,DWORD PTR [eax]
0x719780: 51                               push ecx
0x719781: 8d4108                           lea eax,[ecx+0x8]
0x719784: 50                               push eax
0x719785: 8d85c0fcffff                     lea eax,[ebp-0x340]
0x71978b: 50                               push eax
0x71978c: 8bcf                             mov ecx,edi
0x71978e: e8ed780b00                       call 0x7d1080
0x719793: c645fc03                         mov BYTE PTR [ebp-0x4],0x3
0x719797: 837da810                         cmp DWORD PTR [ebp-0x58],0x10
0x71979b: 720c                             jb 0x7197a9
0x71979d: 8b4d94                           mov ecx,DWORD PTR [ebp-0x6c]
0x7197a0: 51                               push ecx
0x7197a1: e8667a1700                       call 0x89120c
0x7197a6: 83c404                           add esp,0x4
0x7197a9: 8b85f0fcffff                     mov eax,DWORD PTR [ebp-0x310]
0x7197af: 8d95f4fcffff                     lea edx,[ebp-0x30c]
0x7197b5: 52                               push edx
0x7197b6: 50                               push eax
0x7197b7: ff15a022bd00                     call DWORD PTR ds:0xbd22a0
0x7197bd: 85c0                             test eax,eax
0x7197bf: 0f851bfcffff                     jne 0x7193e0
0x7197c5: e98cfaffff                       jmp 0x719256
0x7197ca: 683420bf00                       push 0xbf2034
0x7197cf: e85c431600                       call 0x87db30

; group_lookup_complete 0x716740..0x71682b exclusive
; Exact group lookup, miss returns zero, hit queries basename; no scan/provider open in this body.
0x716740: 55                               push ebp
0x716741: 8bec                             mov ebp,esp
0x716743: 6aff                             push 0xffffffff
0x716745: 68c8849200                       push 0x9284c8
0x71674a: 64a100000000                     mov eax,fs:0x0
0x716750: 50                               push eax
0x716751: 83ec2c                           sub esp,0x2c
0x716754: a1201fd600                       mov eax,ds:0xd61f20
0x716759: 33c5                             xor eax,ebp
0x71675b: 8945f0                           mov DWORD PTR [ebp-0x10],eax
0x71675e: 53                               push ebx
0x71675f: 56                               push esi
0x716760: 57                               push edi
0x716761: 50                               push eax
0x716762: 8d45f4                           lea eax,[ebp-0xc]
0x716765: 64a300000000                     mov fs:0x0,eax
0x71676b: 8b4508                           mov eax,DWORD PTR [ebp+0x8]
0x71676e: 8945cc                           mov DWORD PTR [ebp-0x34],eax
0x716771: 33db                             xor ebx,ebx
0x716773: 8bc1                             mov eax,ecx
0x716775: 8bf2                             mov esi,edx
0x716777: c745e80f000000                   mov DWORD PTR [ebp-0x18],0xf
0x71677e: 895de4                           mov DWORD PTR [ebp-0x1c],ebx
0x716781: 885dd4                           mov BYTE PTR [ebp-0x2c],bl
0x716784: 8d7801                           lea edi,[eax+0x1]
0x716787: 8a10                             mov dl,BYTE PTR [eax]
0x716789: 40                               inc eax
0x71678a: 3ad3                             cmp dl,bl
0x71678c: 75f9                             jne 0x716787
0x71678e: 2bc7                             sub eax,edi
0x716790: 50                               push eax
0x716791: 51                               push ecx
0x716792: 8d4dd4                           lea ecx,[ebp-0x2c]
0x716795: e8d6c2ceff                       call 0x402a70
0x71679a: 8d4dd4                           lea ecx,[ebp-0x2c]
0x71679d: 51                               push ecx
0x71679e: 8bc6                             mov eax,esi
0x7167a0: 895dfc                           mov DWORD PTR [ebp-0x4],ebx
0x7167a3: e888070a00                       call 0x7b6f30
0x7167a8: 8945c8                           mov DWORD PTR [ebp-0x38],eax
0x7167ab: 3b4604                           cmp eax,DWORD PTR [esi+0x4]
0x7167ae: 7414                             je 0x7167c4
0x7167b0: 83c00c                           add eax,0xc
0x7167b3: 8d55d4                           lea edx,[ebp-0x2c]
0x7167b6: e87546d8ff                       call 0x49ae30
0x7167bb: 84c0                             test al,al
0x7167bd: 7505                             jne 0x7167c4
0x7167bf: 8d45c8                           lea eax,[ebp-0x38]
0x7167c2: eb09                             jmp 0x7167cd
0x7167c4: 8b5604                           mov edx,DWORD PTR [esi+0x4]
0x7167c7: 8955d0                           mov DWORD PTR [ebp-0x30],edx
0x7167ca: 8d45d0                           lea eax,[ebp-0x30]
0x7167cd: 8b38                             mov edi,DWORD PTR [eax]
0x7167cf: c745fcffffffff                   mov DWORD PTR [ebp-0x4],0xffffffff
0x7167d6: 837de810                         cmp DWORD PTR [ebp-0x18],0x10
0x7167da: 720c                             jb 0x7167e8
0x7167dc: 8b45d4                           mov eax,DWORD PTR [ebp-0x2c]
0x7167df: 50                               push eax
0x7167e0: e827aa1700                       call 0x89120c
0x7167e5: 83c404                           add esp,0x4
0x7167e8: c745e80f000000                   mov DWORD PTR [ebp-0x18],0xf
0x7167ef: 895de4                           mov DWORD PTR [ebp-0x1c],ebx
0x7167f2: 885dd4                           mov BYTE PTR [ebp-0x2c],bl
0x7167f5: 3b7e04                           cmp edi,DWORD PTR [esi+0x4]
0x7167f8: 7504                             jne 0x7167fe
0x7167fa: 33c0                             xor eax,eax
0x7167fc: eb0f                             jmp 0x71680d
0x7167fe: 8b7728                           mov esi,DWORD PTR [edi+0x28]
0x716801: 8b4dcc                           mov ecx,DWORD PTR [ebp-0x34]
0x716804: 83c63c                           add esi,0x3c
0x716807: 51                               push ecx
0x716808: e8d32f0000                       call 0x7197e0
0x71680d: 8b4df4                           mov ecx,DWORD PTR [ebp-0xc]
0x716810: 64890d00000000                   mov DWORD PTR fs:0x0,ecx
0x716817: 59                               pop ecx
0x716818: 5f                               pop edi
0x716819: 5e                               pop esi
0x71681a: 5b                               pop ebx
0x71681b: 8b4df0                           mov ecx,DWORD PTR [ebp-0x10]
0x71681e: 33cd                             xor ecx,ebp
0x716820: e8dca71700                       call 0x891001
0x716825: 8be5                             mov esp,ebp
0x716827: 5d                               pop ebp
0x716828: c20400                           ret 0x4

; basename_lookup_complete 0x7197e0..0x7198a9 exclusive
; 64-byte query copy, uppercase helper, index query, zero on miss.
0x7197e0: 55                               push ebp
0x7197e1: 8bec                             mov ebp,esp
0x7197e3: 6aff                             push 0xffffffff
0x7197e5: 68f85b9100                       push 0x915bf8
0x7197ea: 64a100000000                     mov eax,fs:0x0
0x7197f0: 50                               push eax
0x7197f1: 83ec64                           sub esp,0x64
0x7197f4: a1201fd600                       mov eax,ds:0xd61f20
0x7197f9: 33c5                             xor eax,ebp
0x7197fb: 8945f0                           mov DWORD PTR [ebp-0x10],eax
0x7197fe: 50                               push eax
0x7197ff: 8d45f4                           lea eax,[ebp-0xc]
0x719802: 64a300000000                     mov fs:0x0,eax
0x719808: 8b4508                           mov eax,DWORD PTR [ebp+0x8]
0x71980b: 50                               push eax
0x71980c: 8d45b0                           lea eax,[ebp-0x50]
0x71980f: 6a40                             push 0x40
0x719811: 50                               push eax
0x719812: e842a31700                       call 0x893b59
0x719817: 83c40c                           add esp,0xc
0x71981a: 8d4db0                           lea ecx,[ebp-0x50]
0x71981d: 51                               push ecx
0x71981e: e88d000000                       call 0x7198b0
0x719823: 8d45b0                           lea eax,[ebp-0x50]
0x719826: c745a80f000000                   mov DWORD PTR [ebp-0x58],0xf
0x71982d: c745a400000000                   mov DWORD PTR [ebp-0x5c],0x0
0x719834: c6459400                         mov BYTE PTR [ebp-0x6c],0x0
0x719838: 8d5001                           lea edx,[eax+0x1]
0x71983b: eb03                             jmp 0x719840
0x71983d: 8d4900                           lea ecx,[ecx+0x0]
0x719840: 8a08                             mov cl,BYTE PTR [eax]
0x719842: 40                               inc eax
0x719843: 84c9                             test cl,cl
0x719845: 75f9                             jne 0x719840
0x719847: 2bc2                             sub eax,edx
0x719849: 50                               push eax
0x71984a: 8d55b0                           lea edx,[ebp-0x50]
0x71984d: 52                               push edx
0x71984e: 8d4d94                           lea ecx,[ebp-0x6c]
0x719851: e81a92ceff                       call 0x402a70
0x719856: 8d4594                           lea eax,[ebp-0x6c]
0x719859: 50                               push eax
0x71985a: 8d4d90                           lea ecx,[ebp-0x70]
0x71985d: 51                               push ecx
0x71985e: 8d4604                           lea eax,[esi+0x4]
0x719861: c745fc00000000                   mov DWORD PTR [ebp-0x4],0x0
0x719868: e883ee0900                       call 0x7b86f0
0x71986d: 837da810                         cmp DWORD PTR [ebp-0x58],0x10
0x719871: 720c                             jb 0x71987f
0x719873: 8b5594                           mov edx,DWORD PTR [ebp-0x6c]
0x719876: 52                               push edx
0x719877: e890791700                       call 0x89120c
0x71987c: 83c404                           add esp,0x4
0x71987f: 8b4590                           mov eax,DWORD PTR [ebp-0x70]
0x719882: 3b4608                           cmp eax,DWORD PTR [esi+0x8]
0x719885: 7504                             jne 0x71988b
0x719887: 33c0                             xor eax,eax
0x719889: eb03                             jmp 0x71988e
0x71988b: 8b4024                           mov eax,DWORD PTR [eax+0x24]
0x71988e: 8b4df4                           mov ecx,DWORD PTR [ebp-0xc]
0x719891: 64890d00000000                   mov DWORD PTR fs:0x0,ecx
0x719898: 59                               pop ecx
0x719899: 8b4df0                           mov ecx,DWORD PTR [ebp-0x10]
0x71989c: 33cd                             xor ecx,ebp
0x71989e: e85e771700                       call 0x891001
0x7198a3: 8be5                             mov esp,ebp
0x7198a5: 5d                               pop ebp
0x7198a6: c20400                           ret 0x4

; group_lower_bound 0x7b6f30..0x7b6fb5 exclusive
; Raw byte comparison and lengths, no uppercase normalization for group name.
0x7b6f30: 55                               push ebp
0x7b6f31: 8bec                             mov ebp,esp
0x7b6f33: 83ec08                           sub esp,0x8
0x7b6f36: 8b4004                           mov eax,DWORD PTR [eax+0x4]
0x7b6f39: 57                               push edi
0x7b6f3a: 8b7804                           mov edi,DWORD PTR [eax+0x4]
0x7b6f3d: 807f2d00                         cmp BYTE PTR [edi+0x2d],0x0
0x7b6f41: 8945fc                           mov DWORD PTR [ebp-0x4],eax
0x7b6f44: 7568                             jne 0x7b6fae
0x7b6f46: 8b4d08                           mov ecx,DWORD PTR [ebp+0x8]
0x7b6f49: 8b5114                           mov edx,DWORD PTR [ecx+0x14]
0x7b6f4c: 53                               push ebx
0x7b6f4d: 8b5910                           mov ebx,DWORD PTR [ecx+0x10]
0x7b6f50: 56                               push esi
0x7b6f51: 8955f8                           mov DWORD PTR [ebp-0x8],edx
0x7b6f54: eb03                             jmp 0x7b6f59
0x7b6f56: 8b4d08                           mov ecx,DWORD PTR [ebp+0x8]
0x7b6f59: 837df810                         cmp DWORD PTR [ebp-0x8],0x10
0x7b6f5d: 8d470c                           lea eax,[edi+0xc]
0x7b6f60: 7202                             jb 0x7b6f64
0x7b6f62: 8b09                             mov ecx,DWORD PTR [ecx]
0x7b6f64: 8b7010                           mov esi,DWORD PTR [eax+0x10]
0x7b6f67: 8bd6                             mov edx,esi
0x7b6f69: 3bd6                             cmp edx,esi
0x7b6f6b: 7300                             jae 0x7b6f6d
0x7b6f6d: 8bd6                             mov edx,esi
0x7b6f6f: 3bf3                             cmp esi,ebx
0x7b6f71: 7202                             jb 0x7b6f75
0x7b6f73: 8bd3                             mov edx,ebx
0x7b6f75: 83781410                         cmp DWORD PTR [eax+0x14],0x10
0x7b6f79: 7202                             jb 0x7b6f7d
0x7b6f7b: 8b00                             mov eax,DWORD PTR [eax]
0x7b6f7d: 52                               push edx
0x7b6f7e: 8bd0                             mov edx,eax
0x7b6f80: e8eb0ec5ff                       call 0x407e70
0x7b6f85: 83c404                           add esp,0x4
0x7b6f88: 85c0                             test eax,eax
0x7b6f8a: 750b                             jne 0x7b6f97
0x7b6f8c: 3bf3                             cmp esi,ebx
0x7b6f8e: 7209                             jb 0x7b6f99
0x7b6f90: 3bf3                             cmp esi,ebx
0x7b6f92: 0f95c0                           setne al
0x7b6f95: 85c0                             test eax,eax
0x7b6f97: 7905                             jns 0x7b6f9e
0x7b6f99: 8b7f08                           mov edi,DWORD PTR [edi+0x8]
0x7b6f9c: eb05                             jmp 0x7b6fa3
0x7b6f9e: 897dfc                           mov DWORD PTR [ebp-0x4],edi
0x7b6fa1: 8b3f                             mov edi,DWORD PTR [edi]
0x7b6fa3: 807f2d00                         cmp BYTE PTR [edi+0x2d],0x0
0x7b6fa7: 74ad                             je 0x7b6f56
0x7b6fa9: 8b45fc                           mov eax,DWORD PTR [ebp-0x4]
0x7b6fac: 5e                               pop esi
0x7b6fad: 5b                               pop ebx
0x7b6fae: 5f                               pop edi
0x7b6faf: 8be5                             mov esp,ebp
0x7b6fb1: 5d                               pop ebp
0x7b6fb2: c20400                           ret 0x4

; group_compare 0x49ae30..0x49ae8d exclusive
; Byte comparator then length, used for exact group membership.
0x49ae30: 53                               push ebx
0x49ae31: 8b5810                           mov ebx,DWORD PTR [eax+0x10]
0x49ae34: b910000000                       mov ecx,0x10
0x49ae39: 56                               push esi
0x49ae3a: 394814                           cmp DWORD PTR [eax+0x14],ecx
0x49ae3d: 7202                             jb 0x49ae41
0x49ae3f: 8b00                             mov eax,DWORD PTR [eax]
0x49ae41: 8b7210                           mov esi,DWORD PTR [edx+0x10]
0x49ae44: 57                               push edi
0x49ae45: 8bfe                             mov edi,esi
0x49ae47: 3bfe                             cmp edi,esi
0x49ae49: 0f42f7                           cmovb esi,edi
0x49ae4c: 8bfe                             mov edi,esi
0x49ae4e: 3bf3                             cmp esi,ebx
0x49ae50: 7202                             jb 0x49ae54
0x49ae52: 8bfb                             mov edi,ebx
0x49ae54: 394a14                           cmp DWORD PTR [edx+0x14],ecx
0x49ae57: 7202                             jb 0x49ae5b
0x49ae59: 8b12                             mov edx,DWORD PTR [edx]
0x49ae5b: 57                               push edi
0x49ae5c: 8bc8                             mov ecx,eax
0x49ae5e: e80dd0f6ff                       call 0x407e70
0x49ae63: 83c404                           add esp,0x4
0x49ae66: 5f                               pop edi
0x49ae67: 85c0                             test eax,eax
0x49ae69: 7518                             jne 0x49ae83
0x49ae6b: 3bf3                             cmp esi,ebx
0x49ae6d: 730d                             jae 0x49ae7c
0x49ae6f: 83c8ff                           or eax,0xffffffff
0x49ae72: 33c9                             xor ecx,ecx
0x49ae74: 85c0                             test eax,eax
0x49ae76: 5e                               pop esi
0x49ae77: 0f98c0                           sets al
0x49ae7a: 5b                               pop ebx
0x49ae7b: c3                               ret
0x49ae7c: 33c0                             xor eax,eax
0x49ae7e: 3bf3                             cmp esi,ebx
0x49ae80: 0f95c0                           setne al
0x49ae83: 33c9                             xor ecx,ecx
0x49ae85: 85c0                             test eax,eax
0x49ae87: 5e                               pop esi
0x49ae88: 0f98c0                           sets al
0x49ae8b: 5b                               pop ebx
0x49ae8c: c3                               ret

; byte_compare 0x407e70..0x407ee3 exclusive
; Unsigned byte comparisons, not case-folding.
0x407e70: 55                               push ebp
0x407e71: 8bec                             mov ebp,esp
0x407e73: 56                               push esi
0x407e74: 8b7508                           mov esi,DWORD PTR [ebp+0x8]
0x407e77: 57                               push edi
0x407e78: 83fe04                           cmp esi,0x4
0x407e7b: 7217                             jb 0x407e94
0x407e7d: 8d4900                           lea ecx,[ecx+0x0]
0x407e80: 8b02                             mov eax,DWORD PTR [edx]
0x407e82: 3b01                             cmp eax,DWORD PTR [ecx]
0x407e84: 7512                             jne 0x407e98
0x407e86: 83ee04                           sub esi,0x4
0x407e89: 83c104                           add ecx,0x4
0x407e8c: 83c204                           add edx,0x4
0x407e8f: 83fe04                           cmp esi,0x4
0x407e92: 73ec                             jae 0x407e80
0x407e94: 85f6                             test esi,esi
0x407e96: 7445                             je 0x407edd
0x407e98: 0fb602                           movzx eax,BYTE PTR [edx]
0x407e9b: 0fb639                           movzx edi,BYTE PTR [ecx]
0x407e9e: 2bc7                             sub eax,edi
0x407ea0: 7531                             jne 0x407ed3
0x407ea2: 83fe01                           cmp esi,0x1
0x407ea5: 7636                             jbe 0x407edd
0x407ea7: 0fb64201                         movzx eax,BYTE PTR [edx+0x1]
0x407eab: 0fb67901                         movzx edi,BYTE PTR [ecx+0x1]
0x407eaf: 2bc7                             sub eax,edi
0x407eb1: 7520                             jne 0x407ed3
0x407eb3: 83fe02                           cmp esi,0x2
0x407eb6: 7625                             jbe 0x407edd
0x407eb8: 0fb64202                         movzx eax,BYTE PTR [edx+0x2]
0x407ebc: 0fb67902                         movzx edi,BYTE PTR [ecx+0x2]
0x407ec0: 2bc7                             sub eax,edi
0x407ec2: 750f                             jne 0x407ed3
0x407ec4: 83fe03                           cmp esi,0x3
0x407ec7: 7614                             jbe 0x407edd
0x407ec9: 0fb64203                         movzx eax,BYTE PTR [edx+0x3]
0x407ecd: 0fb64903                         movzx ecx,BYTE PTR [ecx+0x3]
0x407ed1: 2bc1                             sub eax,ecx
0x407ed3: c1f81f                           sar eax,0x1f
0x407ed6: 5f                               pop edi
0x407ed7: 83c801                           or eax,0x1
0x407eda: 5e                               pop esi
0x407edb: 5d                               pop ebp
0x407edc: c3                               ret
0x407edd: 5f                               pop edi
0x407ede: 33c0                             xor eax,eax
0x407ee0: 5e                               pop esi
0x407ee1: 5d                               pop ebp
0x407ee2: c3                               ret

; ptc_local_fallback 0x7f6b80..0x7f6d66 exclusive
; MAP_PTC global lookup miss uses stack-local Map/*.ptc recursive scanner; local index destroyed on exit; no global insertion.
0x7f6b80: 55                               push ebp
0x7f6b81: 8bec                             mov ebp,esp
0x7f6b83: 83e4f8                           and esp,0xfffffff8
0x7f6b86: 6aff                             push 0xffffffff
0x7f6b88: 68aca49200                       push 0x92a4ac
0x7f6b8d: 64a100000000                     mov eax,fs:0x0
0x7f6b93: 50                               push eax
0x7f6b94: 83ec58                           sub esp,0x58
0x7f6b97: a1201fd600                       mov eax,ds:0xd61f20
0x7f6b9c: 33c4                             xor eax,esp
0x7f6b9e: 89442450                         mov DWORD PTR [esp+0x50],eax
0x7f6ba2: 53                               push ebx
0x7f6ba3: 56                               push esi
0x7f6ba4: 57                               push edi
0x7f6ba5: a1201fd600                       mov eax,ds:0xd61f20
0x7f6baa: 33c4                             xor eax,esp
0x7f6bac: 50                               push eax
0x7f6bad: 8d442468                         lea eax,[esp+0x68]
0x7f6bb1: 64a300000000                     mov fs:0x0,eax
0x7f6bb7: 8bf9                             mov edi,ecx
0x7f6bb9: 837f2000                         cmp DWORD PTR [edi+0x20],0x0
0x7f6bbd: 897c2410                         mov DWORD PTR [esp+0x10],edi
0x7f6bc1: 0f8581010000                     jne 0x7f6d48
0x7f6bc7: 83c704                           add edi,0x4
0x7f6bca: 837f1410                         cmp DWORD PTR [edi+0x14],0x10
0x7f6bce: 7204                             jb 0x7f6bd4
0x7f6bd0: 8b37                             mov esi,DWORD PTR [edi]
0x7f6bd2: eb02                             jmp 0x7f6bd6
0x7f6bd4: 8bf7                             mov esi,edi
0x7f6bd6: f605f81dfe0001                   test BYTE PTR ds:0xfe1df8,0x1
0x7f6bdd: 7529                             jne 0x7f6c08
0x7f6bdf: 830df81dfe0001                   or DWORD PTR ds:0xfe1df8,0x1
0x7f6be6: c744247000000000                 mov DWORD PTR [esp+0x70],0x0
0x7f6bee: e8edfff1ff                       call 0x716be0
0x7f6bf3: 68a0f1bc00                       push 0xbcf1a0
0x7f6bf8: e81db70900                       call 0x89231a
0x7f6bfd: 83c404                           add esp,0x4
0x7f6c00: c7442470ffffffff                 mov DWORD PTR [esp+0x70],0xffffffff
0x7f6c08: 56                               push esi
0x7f6c09: b99cf2c400                       mov ecx,0xc4f29c
0x7f6c0e: bafc1dfe00                       mov edx,0xfe1dfc
0x7f6c13: e828fbf1ff                       call 0x716740
0x7f6c18: 8d742414                         lea esi,[esp+0x14]
0x7f6c1c: 8bd8                             mov ebx,eax
0x7f6c1e: e8cd20f2ff                       call 0x718cf0
0x7f6c23: c744247001000000                 mov DWORD PTR [esp+0x70],0x1
0x7f6c2b: 85db                             test ebx,ebx
0x7f6c2d: 7557                             jne 0x7f6c86
0x7f6c2f: 6a01                             push 0x1
0x7f6c31: 68c8cec000                       push 0xc0cec8
0x7f6c36: 6894f2c400                       push 0xc4f294
0x7f6c3b: 8bce                             mov ecx,esi
0x7f6c3d: e86e23f2ff                       call 0x718fb0
0x7f6c42: 837f1410                         cmp DWORD PTR [edi+0x14],0x10
0x7f6c46: 7204                             jb 0x7f6c4c
0x7f6c48: 8b07                             mov eax,DWORD PTR [edi]
0x7f6c4a: eb02                             jmp 0x7f6c4e
0x7f6c4c: 8bc7                             mov eax,edi
0x7f6c4e: 50                               push eax
0x7f6c4f: 8d742418                         lea esi,[esp+0x18]
0x7f6c53: e8882bf2ff                       call 0x7197e0
0x7f6c58: 8bd8                             mov ebx,eax
0x7f6c5a: 85db                             test ebx,ebx
0x7f6c5c: 7528                             jne 0x7f6c86
0x7f6c5e: 837f1410                         cmp DWORD PTR [edi+0x14],0x10
0x7f6c62: 7202                             jb 0x7f6c66
0x7f6c64: 8b3f                             mov edi,DWORD PTR [edi]
0x7f6c66: 6a00                             push 0x0
0x7f6c68: 68cc0cc500                       push 0xc50ccc
0x7f6c6d: 57                               push edi
0x7f6c6e: 6a00                             push 0x0
0x7f6c70: ff159024bd00                     call DWORD PTR ds:0xbd2490
0x7f6c76: 8b442410                         mov eax,DWORD PTR [esp+0x10]
0x7f6c7a: c7402000000000                   mov DWORD PTR [eax+0x20],0x0
0x7f6c81: e9b9000000                       jmp 0x7f6d3f
0x7f6c86: 8d742444                         lea esi,[esp+0x44]
0x7f6c8a: 8bc3                             mov eax,ebx
0x7f6c8c: e8ff58faff                       call 0x79c590
0x7f6c91: b910000000                       mov ecx,0x10
0x7f6c96: c644247002                       mov BYTE PTR [esp+0x70],0x2
0x7f6c9b: 394814                           cmp DWORD PTR [eax+0x14],ecx
0x7f6c9e: 7204                             jb 0x7f6ca4
0x7f6ca0: 8b30                             mov esi,DWORD PTR [eax]
0x7f6ca2: eb02                             jmp 0x7f6ca6
0x7f6ca4: 8bf0                             mov esi,eax
0x7f6ca6: 394f14                           cmp DWORD PTR [edi+0x14],ecx
0x7f6ca9: 7202                             jb 0x7f6cad
0x7f6cab: 8b3f                             mov edi,DWORD PTR [edi]
0x7f6cad: f6054c32fe0001                   test BYTE PTR ds:0xfe324c,0x1
0x7f6cb4: 7523                             jne 0x7f6cd9
0x7f6cb6: 830d4c32fe0001                   or DWORD PTR ds:0xfe324c,0x1
0x7f6cbd: c644247003                       mov BYTE PTR [esp+0x70],0x3
0x7f6cc2: e8e971fdff                       call 0x7cdeb0
0x7f6cc7: 68b009bd00                       push 0xbd09b0
0x7f6ccc: e849b60900                       call 0x89231a
0x7f6cd1: 83c404                           add esp,0x4
0x7f6cd4: c644247002                       mov BYTE PTR [esp+0x70],0x2
0x7f6cd9: 56                               push esi
0x7f6cda: 685032fe00                       push 0xfe3250
0x7f6cdf: 8bcf                             mov ecx,edi
0x7f6ce1: e8ba73fdff                       call 0x7ce0a0
0x7f6ce6: be10000000                       mov esi,0x10
0x7f6ceb: c644247001                       mov BYTE PTR [esp+0x70],0x1
0x7f6cf0: 8bf8                             mov edi,eax
0x7f6cf2: 39742458                         cmp DWORD PTR [esp+0x58],esi
0x7f6cf6: 720d                             jb 0x7f6d05
0x7f6cf8: 8b4c2444                         mov ecx,DWORD PTR [esp+0x44]
0x7f6cfc: 51                               push ecx
0x7f6cfd: e80aa50900                       call 0x89120c
0x7f6d02: 83c404                           add esp,0x4
0x7f6d05: 85ff                             test edi,edi
0x7f6d07: 7436                             je 0x7f6d3f
0x7f6d09: 397330                           cmp DWORD PTR [ebx+0x30],esi
0x7f6d0c: 8d431c                           lea eax,[ebx+0x1c]
0x7f6d0f: 7202                             jb 0x7f6d13
0x7f6d11: 8b00                             mov eax,DWORD PTR [eax]
0x7f6d13: 397314                           cmp DWORD PTR [ebx+0x14],esi
0x7f6d16: 7202                             jb 0x7f6d1a
0x7f6d18: 8b1b                             mov ebx,DWORD PTR [ebx]
0x7f6d1a: 50                               push eax
0x7f6d1b: e82071fdff                       call 0x7cde40
0x7f6d20: 8bcb                             mov ecx,ebx
0x7f6d22: 8bd0                             mov edx,eax
0x7f6d24: e8476effff                       call 0x7edb70
0x7f6d29: e8d21ffaff                       call 0x798d00
0x7f6d2e: 50                               push eax
0x7f6d2f: e83c8dfdff                       call 0x7cfa70
0x7f6d34: 8b542410                         mov edx,DWORD PTR [esp+0x10]
0x7f6d38: c7422001000000                   mov DWORD PTR [edx+0x20],0x1
0x7f6d3f: 8d4c2414                         lea ecx,[esp+0x14]
0x7f6d43: e88820f2ff                       call 0x718dd0
0x7f6d48: 8b4c2468                         mov ecx,DWORD PTR [esp+0x68]
0x7f6d4c: 64890d00000000                   mov DWORD PTR fs:0x0,ecx
0x7f6d53: 59                               pop ecx
0x7f6d54: 5f                               pop edi
0x7f6d55: 5e                               pop esi
0x7f6d56: 5b                               pop ebx
0x7f6d57: 8b4c2450                         mov ecx,DWORD PTR [esp+0x50]
0x7f6d5b: 33cc                             xor ecx,esp
0x7f6d5d: e89fa20900                       call 0x891001
0x7f6d62: 8be5                             mov esp,ebp
0x7f6d64: 5d                               pop ebp
0x7f6d65: c3                               ret

; index_constructor 0x718cf0..0x718d99 exclusive
; Initialize empty local index/container at ESI; separate allocation-failure branch is not treated as a safe fallback.
0x718cf0: 55                               push ebp
0x718cf1: 8bec                             mov ebp,esp
0x718cf3: 6aff                             push 0xffffffff
0x718cf5: 68c6a79000                       push 0x90a7c6
0x718cfa: 64a100000000                     mov eax,fs:0x0
0x718d00: 50                               push eax
0x718d01: 83ec18                           sub esp,0x18
0x718d04: 53                               push ebx
0x718d05: 57                               push edi
0x718d06: a1201fd600                       mov eax,ds:0xd61f20
0x718d0b: 33c5                             xor eax,ebp
0x718d0d: 50                               push eax
0x718d0e: 8d45f4                           lea eax,[ebp-0xc]
0x718d11: 64a300000000                     mov fs:0x0,eax
0x718d17: 8a45f3                           mov al,BYTE PTR [ebp-0xd]
0x718d1a: 8d7e04                           lea edi,[esi+0x4]
0x718d1d: c706c844c400                     mov DWORD PTR [esi],0xc444c8
0x718d23: 8807                             mov BYTE PTR [edi],al
0x718d25: 33db                             xor ebx,ebx
0x718d27: 6a28                             push 0x28
0x718d29: 897de8                           mov DWORD PTR [ebp-0x18],edi
0x718d2c: 895f08                           mov DWORD PTR [edi+0x8],ebx
0x718d2f: e834851700                       call 0x891268
0x718d34: 83c404                           add esp,0x4
0x718d37: 3bc3                             cmp eax,ebx
0x718d39: 743a                             je 0x718d75
0x718d3b: 894704                           mov DWORD PTR [edi+0x4],eax
0x718d3e: 8900                             mov DWORD PTR [eax],eax
0x718d40: 8b4704                           mov eax,DWORD PTR [edi+0x4]
0x718d43: 894004                           mov DWORD PTR [eax+0x4],eax
0x718d46: 895dfc                           mov DWORD PTR [ebp-0x4],ebx
0x718d49: 895f10                           mov DWORD PTR [edi+0x10],ebx
0x718d4c: 895f14                           mov DWORD PTR [edi+0x14],ebx
0x718d4f: 895f18                           mov DWORD PTR [edi+0x18],ebx
0x718d52: c645fc01                         mov BYTE PTR [ebp-0x4],0x1
0x718d56: d9e8                             fld1
0x718d58: 6a08                             push 0x8
0x718d5a: d95f28                           fstp DWORD PTR [edi+0x28]
0x718d5d: e8ce3e0c00                       call 0x7dcc30
0x718d62: 8bc6                             mov eax,esi
0x718d64: 8b4df4                           mov ecx,DWORD PTR [ebp-0xc]
0x718d67: 64890d00000000                   mov DWORD PTR fs:0x0,ecx
0x718d6e: 59                               pop ecx
0x718d6f: 5f                               pop edi
0x718d70: 5b                               pop ebx
0x718d71: 8be5                             mov esp,ebp
0x718d73: 5d                               pop ebp
0x718d74: c3                               ret
0x718d75: 8d4dec                           lea ecx,[ebp-0x14]
0x718d78: 51                               push ecx
0x718d79: 8d4ddc                           lea ecx,[ebp-0x24]
0x718d7c: 895dec                           mov DWORD PTR [ebp-0x14],ebx
0x718d7f: e825831700                       call 0x8910a9
0x718d84: 68a857c800                       push 0xc857a8
0x718d89: 8d55dc                           lea edx,[ebp-0x24]
0x718d8c: 52                               push edx
0x718d8d: c745dca42cbd00                   mov DWORD PTR [ebp-0x24],0xbd2ca4
0x718d94: e8573c1800                       call 0x89c9f0

; index_destructor 0x718dd0..0x718e74 exclusive
; Release all index entry objects, strings and containers; same local owner used by PTC fallback.
0x718dd0: 53                               push ebx
0x718dd1: 57                               push edi
0x718dd2: 8bf9                             mov edi,ecx
0x718dd4: 8b4708                           mov eax,DWORD PTR [edi+0x8]
0x718dd7: c707c844c400                     mov DWORD PTR [edi],0xc444c8
0x718ddd: 8b18                             mov ebx,DWORD PTR [eax]
0x718ddf: 3bd8                             cmp ebx,eax
0x718de1: 745f                             je 0x718e42
0x718de3: 56                               push esi
0x718de4: 8b7324                           mov esi,DWORD PTR [ebx+0x24]
0x718de7: 85f6                             test esi,esi
0x718de9: 744f                             je 0x718e3a
0x718deb: 837e3010                         cmp DWORD PTR [esi+0x30],0x10
0x718def: 720c                             jb 0x718dfd
0x718df1: 8b461c                           mov eax,DWORD PTR [esi+0x1c]
0x718df4: 50                               push eax
0x718df5: e812841700                       call 0x89120c
0x718dfa: 83c404                           add esp,0x4
0x718dfd: c746300f000000                   mov DWORD PTR [esi+0x30],0xf
0x718e04: c7462c00000000                   mov DWORD PTR [esi+0x2c],0x0
0x718e0b: c6461c00                         mov BYTE PTR [esi+0x1c],0x0
0x718e0f: 837e1410                         cmp DWORD PTR [esi+0x14],0x10
0x718e13: 720b                             jb 0x718e20
0x718e15: 8b0e                             mov ecx,DWORD PTR [esi]
0x718e17: 51                               push ecx
0x718e18: e8ef831700                       call 0x89120c
0x718e1d: 83c404                           add esp,0x4
0x718e20: c746140f000000                   mov DWORD PTR [esi+0x14],0xf
0x718e27: c7461000000000                   mov DWORD PTR [esi+0x10],0x0
0x718e2e: 56                               push esi
0x718e2f: c60600                           mov BYTE PTR [esi],0x0
0x718e32: e8d5831700                       call 0x89120c
0x718e37: 83c404                           add esp,0x4
0x718e3a: 8b1b                             mov ebx,DWORD PTR [ebx]
0x718e3c: 3b5f08                           cmp ebx,DWORD PTR [edi+0x8]
0x718e3f: 75a3                             jne 0x718de4
0x718e41: 5e                               pop esi
0x718e42: 8b4714                           mov eax,DWORD PTR [edi+0x14]
0x718e45: 85c0                             test eax,eax
0x718e47: 7409                             je 0x718e52
0x718e49: 50                               push eax
0x718e4a: e8bd831700                       call 0x89120c
0x718e4f: 83c404                           add esp,0x4
0x718e52: 33c0                             xor eax,eax
0x718e54: 894714                           mov DWORD PTR [edi+0x14],eax
0x718e57: 894718                           mov DWORD PTR [edi+0x18],eax
0x718e5a: 89471c                           mov DWORD PTR [edi+0x1c],eax
0x718e5d: 83c708                           add edi,0x8
0x718e60: 57                               push edi
0x718e61: e8da97e3ff                       call 0x552640
0x718e66: 8b17                             mov edx,DWORD PTR [edi]
0x718e68: 52                               push edx
0x718e69: e89e831700                       call 0x89120c
0x718e6e: 83c404                           add esp,0x4
0x718e71: 5f                               pop edi
0x718e72: 5b                               pop ebx
0x718e73: c3                               ret
