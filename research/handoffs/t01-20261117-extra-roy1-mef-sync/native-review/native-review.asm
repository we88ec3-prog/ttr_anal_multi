; F_0056A100 source=kr-extra-roy/MEF-comprehensive-contracts-20261117/abi/native-evidence.json blob=d8b59973779f0811e1cbeb3171ee2a4f863571f3
; VA 0x56a100 raw 0x169500 SHA256 4a847ba10e1d61d57aed0dc3f342946eaeeddb5a11774809c3b957afad7db66b
0x56a100 55                               push   ebp
0x56a101 8bec                             mov    ebp,esp
0x56a103 6aff                             push   0xffffffff
0x56a105 68c8839300                       push   0x9383c8
0x56a10a 64a100000000                     mov    eax,fs:0x0
0x56a110 50                               push   eax
0x56a111 83ec0c                           sub    esp,0xc
0x56a114 a1201fd600                       mov    eax,ds:0xd61f20
0x56a119 33c5                             xor    eax,ebp
0x56a11b 50                               push   eax
0x56a11c 8d45f4                           lea    eax,[ebp-0xc]
0x56a11f 64a300000000                     mov    fs:0x0,eax
0x56a125 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x56a128 8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x56a12b 33c0                             xor    eax,eax
0x56a12d 8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x56a130 8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x56a133 8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x56a136 8b0d6c28fe00                     mov    ecx,DWORD PTR ds:0xfe286c
0x56a13c 51                               push   ecx
0x56a13d 8d45e8                           lea    eax,[ebp-0x18]
0x56a140 e8eb020000                       call   0x56a430
0x56a145 83c404                           add    esp,0x4
0x56a148 b801000000                       mov    eax,0x1
0x56a14d 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x56a150 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x56a157 59                               pop    ecx
0x56a158 8be5                             mov    esp,ebp
0x56a15a 5d                               pop    ebp
0x56a15b c3                               ret

; F_0056A430 source=kr-extra-roy/MEF-comprehensive-contracts-20261117/abi/native-evidence.json blob=d8b59973779f0811e1cbeb3171ee2a4f863571f3
; VA 0x56a430 raw 0x169830 SHA256 ed9871da5aa7b7fb1b47dd2cdb5602c38d2554a686fe84960f2c53d470fcd479
0x56a430 55                               push   ebp
0x56a431 8bec                             mov    ebp,esp
0x56a433 8b08                             mov    ecx,DWORD PTR [eax]
0x56a435 83ec18                           sub    esp,0x18
0x56a438 53                               push   ebx
0x56a439 8b1d7827fe00                     mov    ebx,DWORD PTR ds:0xfe2778
0x56a43f 83c8ff                           or     eax,0xffffffff
0x56a442 e8a9ac1800                       call   0x6f50f0
0x56a447 8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x56a44a 83f903                           cmp    ecx,0x3
0x56a44d 742a                             je     0x56a479
0x56a44f 83f904                           cmp    ecx,0x4
0x56a452 7540                             jne    0x56a494
0x56a454 56                               push   esi
0x56a455 8b30                             mov    esi,DWORD PTR [eax]
0x56a457 57                               push   edi
0x56a458 83c610                           add    esi,0x10
0x56a45b 8d7df8                           lea    edi,[ebp-0x8]
0x56a45e e8fdd21800                       call   0x6f7760
0x56a463 5f                               pop    edi
0x56a464 5e                               pop    esi
0x56a465 85c0                             test   eax,eax
0x56a467 742b                             je     0x56a494
0x56a469 dd45f8                           fld    QWORD PTR [ebp-0x8]
0x56a46c c745f003000000                   mov    DWORD PTR [ebp-0x10],0x3
0x56a473 dd5de8                           fstp   QWORD PTR [ebp-0x18]
0x56a476 8d45e8                           lea    eax,[ebp-0x18]
0x56a479 dd00                             fld    QWORD PTR [eax]
0x56a47b dd5df0                           fstp   QWORD PTR [ebp-0x10]
0x56a47e dd45f0                           fld    QWORD PTR [ebp-0x10]
0x56a481 db5dfc                           fistp  DWORD PTR [ebp-0x4]
0x56a484 8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x56a487 50                               push   eax
0x56a488 8bcb                             mov    ecx,ebx
0x56a48a ff5508                           call   DWORD PTR [ebp+0x8]
0x56a48d 33c0                             xor    eax,eax
0x56a48f 5b                               pop    ebx
0x56a490 8be5                             mov    esp,ebp
0x56a492 5d                               pop    ebp
0x56a493 c3                               ret
0x56a494 33c0                             xor    eax,eax
0x56a496 50                               push   eax
0x56a497 8bcb                             mov    ecx,ebx
0x56a499 ff5508                           call   DWORD PTR [ebp+0x8]
0x56a49c 33c0                             xor    eax,eax
0x56a49e 5b                               pop    ebx
0x56a49f 8be5                             mov    esp,ebp
0x56a4a1 5d                               pop    ebp
0x56a4a2 c3                               ret

; F_006F50F0 source=kr-extra-roy/MEF-comprehensive-contracts-20261117/abi/native-evidence.json blob=d8b59973779f0811e1cbeb3171ee2a4f863571f3
; VA 0x6f50f0 raw 0x2f44f0 SHA256 3d6d34894f118a12b1972a3933c4f70ca1ce457dea6c0bf0ca730406fc68c9bf
0x6f50f0 85c0                             test   eax,eax
0x6f50f2 7e14                             jle    0x6f5108
0x6f50f4 8b510c                           mov    edx,DWORD PTR [ecx+0xc]
0x6f50f7 03c0                             add    eax,eax
0x6f50f9 8d44c2f0                         lea    eax,[edx+eax*8-0x10]
0x6f50fd 3b4108                           cmp    eax,DWORD PTR [ecx+0x8]
0x6f5100 7269                             jb     0x6f516b
0x6f5102 b8c8bfc000                       mov    eax,0xc0bfc8
0x6f5107 c3                               ret
0x6f5108 3df0d8ffff                       cmp    eax,0xffffd8f0
0x6f510d 7e07                             jle    0x6f5116
0x6f510f c1e004                           shl    eax,0x4
0x6f5112 034108                           add    eax,DWORD PTR [ecx+0x8]
0x6f5115 c3                               ret
0x6f5116 3deed8ffff                       cmp    eax,0xffffd8ee
0x6f511b 744b                             je     0x6f5168
0x6f511d 3defd8ffff                       cmp    eax,0xffffd8ef
0x6f5122 742c                             je     0x6f5150
0x6f5124 3df0d8ffff                       cmp    eax,0xffffd8f0
0x6f5129 741e                             je     0x6f5149
0x6f512b 8b4914                           mov    ecx,DWORD PTR [ecx+0x14]
0x6f512e 8b5104                           mov    edx,DWORD PTR [ecx+0x4]
0x6f5131 8b12                             mov    edx,DWORD PTR [edx]
0x6f5133 b9eed8ffff                       mov    ecx,0xffffd8ee
0x6f5138 2bc8                             sub    ecx,eax
0x6f513a 0fb64207                         movzx  eax,BYTE PTR [edx+0x7]
0x6f513e 3bc8                             cmp    ecx,eax
0x6f5140 7fc0                             jg     0x6f5102
0x6f5142 03c9                             add    ecx,ecx
0x6f5144 8d44ca08                         lea    eax,[edx+ecx*8+0x8]
0x6f5148 c3                               ret
0x6f5149 8b4110                           mov    eax,DWORD PTR [ecx+0x10]
0x6f514c 83c060                           add    eax,0x60
0x6f514f c3                               ret
0x6f5150 8d4158                           lea    eax,[ecx+0x58]
0x6f5153 8b4914                           mov    ecx,DWORD PTR [ecx+0x14]
0x6f5156 8b5104                           mov    edx,DWORD PTR [ecx+0x4]
0x6f5159 8b0a                             mov    ecx,DWORD PTR [edx]
0x6f515b 8b510c                           mov    edx,DWORD PTR [ecx+0xc]
0x6f515e 8910                             mov    DWORD PTR [eax],edx
0x6f5160 c7400805000000                   mov    DWORD PTR [eax+0x8],0x5
0x6f5167 c3                               ret
0x6f5168 8d4148                           lea    eax,[ecx+0x48]
0x6f516b c3                               ret

; vm_call source=kr-extra-roy/MEF-control-flow-20261116/supervisor/native-windows.json blob=e069b06e37d31f326909740ff6fd3752052ae7a2
; VA 0x6fd01e raw 0x2fc41e SHA256 0a8bc950ad578e9f782df5b2b028fc844bf62140081982ad4166f38a4132c384
0x6fd01e 8bc3                             mov    eax,ebx
0x6fd020 c1eb0e                           shr    ebx,0xe
0x6fd023 81e3ff010000                     and    ebx,0x1ff
0x6fd029 c1e817                           shr    eax,0x17
0x6fd02c 4b                               dec    ebx
0x6fd02d 85c0                             test   eax,eax
0x6fd02f 7408                             je     0x6fd039
0x6fd031 c1e004                           shl    eax,0x4
0x6fd034 03c6                             add    eax,esi
0x6fd036 894708                           mov    DWORD PTR [edi+0x8],eax
0x6fd039 8b442434                         mov    eax,DWORD PTR [esp+0x34]
0x6fd03d 894718                           mov    DWORD PTR [edi+0x18],eax
0x6fd040 53                               push   ebx
0x6fd041 8bc6                             mov    eax,esi
0x6fd043 8bcf                             mov    ecx,edi
0x6fd045 e876110000                       call   0x6fe1c0
0x6fd04a 83c404                           add    esp,0x4
0x6fd04d 83e800                           sub    eax,0x0
0x6fd050 0f843b050000                     je     0x6fd591
0x6fd056 48                               dec    eax
0x6fd057 0f852d060000                     jne    0x6fd68a
0x6fd05d 85db                             test   ebx,ebx
0x6fd05f 7809                             js     0x6fd06a
0x6fd061 8b4f14                           mov    ecx,DWORD PTR [edi+0x14]
0x6fd064 8b5108                           mov    edx,DWORD PTR [ecx+0x8]
0x6fd067 895708                           mov    DWORD PTR [edi+0x8],edx
0x6fd06a 8b470c                           mov    eax,DWORD PTR [edi+0xc]
0x6fd06d 89442438                         mov    DWORD PTR [esp+0x38],eax
0x6fd071 e914f5ffff                       jmp    0x6fc58a

; precall source=kr-extra-roy/MEF-control-flow-20261116/supervisor/native-windows.json blob=e069b06e37d31f326909740ff6fd3752052ae7a2
; VA 0x6fe1c0 raw 0x2fd5c0 SHA256 cdc97c3e9ef59235e8072416e3f980d7a418db3239539c2704e8a5e821692ec7
0x6fe1c0 55                               push   ebp
0x6fe1c1 8bec                             mov    ebp,esp
0x6fe1c3 83ec08                           sub    esp,0x8
0x6fe1c6 83780806                         cmp    DWORD PTR [eax+0x8],0x6
0x6fe1ca 53                               push   ebx
0x6fe1cb 56                               push   esi
0x6fe1cc 57                               push   edi
0x6fe1cd 8bf1                             mov    esi,ecx
0x6fe1cf 740b                             je     0x6fe1dc
0x6fe1d1 50                               push   eax
0x6fe1d2 8bfe                             mov    edi,esi
0x6fe1d4 e807ffffff                       call   0x6fe0e0
0x6fe1d9 83c404                           add    esp,0x4
0x6fe1dc 8b4e14                           mov    ecx,DWORD PTR [esi+0x14]
0x6fe1df 8b5618                           mov    edx,DWORD PTR [esi+0x18]
0x6fe1e2 8bd8                             mov    ebx,eax
0x6fe1e4 2b5e20                           sub    ebx,DWORD PTR [esi+0x20]
0x6fe1e7 8b00                             mov    eax,DWORD PTR [eax]
0x6fe1e9 89510c                           mov    DWORD PTR [ecx+0xc],edx
0x6fe1ec 80780600                         cmp    BYTE PTR [eax+0x6],0x0
0x6fe1f0 895df8                           mov    DWORD PTR [ebp-0x8],ebx
0x6fe1f3 0f85ed000000                     jne    0x6fe2e6
0x6fe1f9 8b4810                           mov    ecx,DWORD PTR [eax+0x10]
0x6fe1fc 0fb6414b                         movzx  eax,BYTE PTR [ecx+0x4b]
0x6fe200 8b561c                           mov    edx,DWORD PTR [esi+0x1c]
0x6fe203 2b5608                           sub    edx,DWORD PTR [esi+0x8]
0x6fe206 8bf8                             mov    edi,eax
0x6fe208 c1e704                           shl    edi,0x4
0x6fe20b 894dfc                           mov    DWORD PTR [ebp-0x4],ecx
0x6fe20e 3bd7                             cmp    edx,edi
0x6fe210 7f16                             jg     0x6fe228
0x6fe212 8b4e2c                           mov    ecx,DWORD PTR [esi+0x2c]
0x6fe215 3bc1                             cmp    eax,ecx
0x6fe217 7f05                             jg     0x6fe21e
0x6fe219 8d0409                           lea    eax,[ecx+ecx*1]
0x6fe21c eb02                             jmp    0x6fe220
0x6fe21e 03c1                             add    eax,ecx
0x6fe220 e88bfaffff                       call   0x6fdcb0
0x6fe225 8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
0x6fe228 8b7e20                           mov    edi,DWORD PTR [esi+0x20]
0x6fe22b 03fb                             add    edi,ebx
0x6fe22d 80794a00                         cmp    BYTE PTR [ecx+0x4a],0x0
0x6fe231 7516                             jne    0x6fe249
0x6fe233 0fb64149                         movzx  eax,BYTE PTR [ecx+0x49]
0x6fe237 c1e004                           shl    eax,0x4
0x6fe23a 8d5f10                           lea    ebx,[edi+0x10]
0x6fe23d 03c3                             add    eax,ebx
0x6fe23f 394608                           cmp    DWORD PTR [esi+0x8],eax
0x6fe242 7625                             jbe    0x6fe269
0x6fe244 894608                           mov    DWORD PTR [esi+0x8],eax
0x6fe247 eb20                             jmp    0x6fe269
0x6fe249 8b4608                           mov    eax,DWORD PTR [esi+0x8]
0x6fe24c 2bc7                             sub    eax,edi
0x6fe24e c1f804                           sar    eax,0x4
0x6fe251 48                               dec    eax
0x6fe252 50                               push   eax
0x6fe253 56                               push   esi
0x6fe254 8bc1                             mov    eax,ecx
0x6fe256 e865fcffff                       call   0x6fdec0
0x6fe25b 8b7e20                           mov    edi,DWORD PTR [esi+0x20]
0x6fe25e 8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
0x6fe261 83c408                           add    esp,0x8
0x6fe264 037df8                           add    edi,DWORD PTR [ebp-0x8]
0x6fe267 8bd8                             mov    ebx,eax
0x6fe269 8b4614                           mov    eax,DWORD PTR [esi+0x14]
0x6fe26c 3b4624                           cmp    eax,DWORD PTR [esi+0x24]
0x6fe26f 750c                             jne    0x6fe27d
0x6fe271 8bc6                             mov    eax,esi
0x6fe273 e818fbffff                       call   0x6fdd90
0x6fe278 8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
0x6fe27b eb06                             jmp    0x6fe283
0x6fe27d 83c018                           add    eax,0x18
0x6fe280 894614                           mov    DWORD PTR [esi+0x14],eax
0x6fe283 897804                           mov    DWORD PTR [eax+0x4],edi
0x6fe286 8918                             mov    DWORD PTR [eax],ebx
0x6fe288 895e0c                           mov    DWORD PTR [esi+0xc],ebx
0x6fe28b 0fb6514b                         movzx  edx,BYTE PTR [ecx+0x4b]
0x6fe28f c1e204                           shl    edx,0x4
0x6fe292 03d3                             add    edx,ebx
0x6fe294 895008                           mov    DWORD PTR [eax+0x8],edx
0x6fe297 8b490c                           mov    ecx,DWORD PTR [ecx+0xc]
0x6fe29a 894e18                           mov    DWORD PTR [esi+0x18],ecx
0x6fe29d 8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x6fe2a0 33d2                             xor    edx,edx
0x6fe2a2 895014                           mov    DWORD PTR [eax+0x14],edx
0x6fe2a5 894810                           mov    DWORD PTR [eax+0x10],ecx
0x6fe2a8 8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
0x6fe2ab 3b4808                           cmp    ecx,DWORD PTR [eax+0x8]
0x6fe2ae 730b                             jae    0x6fe2bb
0x6fe2b0 895108                           mov    DWORD PTR [ecx+0x8],edx
0x6fe2b3 83c110                           add    ecx,0x10
0x6fe2b6 3b4808                           cmp    ecx,DWORD PTR [eax+0x8]
0x6fe2b9 72f5                             jb     0x6fe2b0
0x6fe2bb f6463801                         test   BYTE PTR [esi+0x38],0x1
0x6fe2bf 8b5008                           mov    edx,DWORD PTR [eax+0x8]
0x6fe2c2 895608                           mov    DWORD PTR [esi+0x8],edx
0x6fe2c5 7416                             je     0x6fe2dd
0x6fe2c7 83461804                         add    DWORD PTR [esi+0x18],0x4
0x6fe2cb 6aff                             push   0xffffffff
0x6fe2cd 33d2                             xor    edx,edx
0x6fe2cf 8bce                             mov    ecx,esi
0x6fe2d1 e80afbffff                       call   0x6fdde0
0x6fe2d6 83c404                           add    esp,0x4
0x6fe2d9 834618fc                         add    DWORD PTR [esi+0x18],0xfffffffc
0x6fe2dd 33c0                             xor    eax,eax
0x6fe2df 5f                               pop    edi
0x6fe2e0 5e                               pop    esi
0x6fe2e1 5b                               pop    ebx
0x6fe2e2 8be5                             mov    esp,ebp
0x6fe2e4 5d                               pop    ebp
0x6fe2e5 c3                               ret
0x6fe2e6 8b461c                           mov    eax,DWORD PTR [esi+0x1c]
0x6fe2e9 2b4608                           sub    eax,DWORD PTR [esi+0x8]
0x6fe2ec 3d40010000                       cmp    eax,0x140
0x6fe2f1 7f14                             jg     0x6fe307
0x6fe2f3 8b462c                           mov    eax,DWORD PTR [esi+0x2c]
0x6fe2f6 83f814                           cmp    eax,0x14
0x6fe2f9 7c04                             jl     0x6fe2ff
0x6fe2fb 03c0                             add    eax,eax
0x6fe2fd eb03                             jmp    0x6fe302
0x6fe2ff 83c014                           add    eax,0x14
0x6fe302 e8a9f9ffff                       call   0x6fdcb0
0x6fe307 8b4614                           mov    eax,DWORD PTR [esi+0x14]
0x6fe30a 3b4624                           cmp    eax,DWORD PTR [esi+0x24]
0x6fe30d 7509                             jne    0x6fe318
0x6fe30f 8bc6                             mov    eax,esi
0x6fe311 e87afaffff                       call   0x6fdd90
0x6fe316 eb06                             jmp    0x6fe31e
0x6fe318 83c018                           add    eax,0x18
0x6fe31b 894614                           mov    DWORD PTR [esi+0x14],eax
0x6fe31e 8b4e20                           mov    ecx,DWORD PTR [esi+0x20]
0x6fe321 03cb                             add    ecx,ebx
0x6fe323 894804                           mov    DWORD PTR [eax+0x4],ecx
0x6fe326 83c110                           add    ecx,0x10
0x6fe329 8908                             mov    DWORD PTR [eax],ecx
0x6fe32b 8b5608                           mov    edx,DWORD PTR [esi+0x8]
0x6fe32e 894e0c                           mov    DWORD PTR [esi+0xc],ecx
0x6fe331 8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x6fe334 81c240010000                     add    edx,0x140
0x6fe33a 895008                           mov    DWORD PTR [eax+0x8],edx
0x6fe33d 894810                           mov    DWORD PTR [eax+0x10],ecx
0x6fe340 f6463801                         test   BYTE PTR [esi+0x38],0x1
0x6fe344 740e                             je     0x6fe354
0x6fe346 6aff                             push   0xffffffff
0x6fe348 33d2                             xor    edx,edx
0x6fe34a 8bce                             mov    ecx,esi
0x6fe34c e88ffaffff                       call   0x6fdde0
0x6fe351 83c404                           add    esp,0x4
0x6fe354 8b5614                           mov    edx,DWORD PTR [esi+0x14]
0x6fe357 8b4204                           mov    eax,DWORD PTR [edx+0x4]
0x6fe35a 8b08                             mov    ecx,DWORD PTR [eax]
0x6fe35c 8b5110                           mov    edx,DWORD PTR [ecx+0x10]
0x6fe35f 56                               push   esi
0x6fe360 ffd2                             call   edx
0x6fe362 83c404                           add    esp,0x4
0x6fe365 85c0                             test   eax,eax
0x6fe367 790c                             jns    0x6fe375
0x6fe369 b802000000                       mov    eax,0x2
0x6fe36e 5f                               pop    edi
0x6fe36f 5e                               pop    esi
0x6fe370 5b                               pop    ebx
0x6fe371 8be5                             mov    esp,ebp
0x6fe373 5d                               pop    ebp
0x6fe374 c3                               ret
0x6fe375 c1e004                           shl    eax,0x4
0x6fe378 8bc8                             mov    ecx,eax
0x6fe37a 8b4608                           mov    eax,DWORD PTR [esi+0x8]
0x6fe37d 2bc1                             sub    eax,ecx
0x6fe37f 56                               push   esi
0x6fe380 e83b010000                       call   0x6fe4c0
0x6fe385 83c404                           add    esp,0x4
0x6fe388 5f                               pop    edi
0x6fe389 5e                               pop    esi
0x6fe38a b801000000                       mov    eax,0x1
0x6fe38f 5b                               pop    ebx
0x6fe390 8be5                             mov    esp,ebp
0x6fe392 5d                               pop    ebp
0x6fe393 c3                               ret

; F_00565600 source=kr-extra-roy/MEF-P0-content-contracts-20261117/abi-adoption/native-evidence.json blob=c5b59f574864bd281bf26b212fe447e600023352
; VA 0x565600 raw 0x164a00 SHA256 2b84862b44c871197789e80ba044db2f6d5761b9a80209e74e38fd38e9298a4f
0x565600 55                               push   ebp
0x565601 8bec                             mov    ebp,esp
0x565603 b801000000                       mov    eax,0x1
0x565608 c705d436fe0004000000             mov    DWORD PTR ds:0xfe36d4,0x4
0x565612 8405dc36fe00                     test   BYTE PTR ds:0xfe36dc,al
0x565618 7512                             jne    0x56562c
0x56561a 0905dc36fe00                     or     DWORD PTR ds:0xfe36dc,eax
0x565620 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x565623 a3d836fe00                       mov    ds:0xfe36d8,eax
0x565628 5d                               pop    ebp
0x565629 c20400                           ret    0x4
0x56562c 8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x56562f 890dd836fe00                     mov    DWORD PTR ds:0xfe36d8,ecx
0x565635 5d                               pop    ebp
0x565636 c20400                           ret    0x4

; F_006FDCB0 source=kr-extra-roy/MEF-P0-content-contracts-20261117/abi-adoption/native-evidence.json blob=c5b59f574864bd281bf26b212fe447e600023352
; VA 0x6fdcb0 raw 0x2fd0b0 SHA256 a7e46edc1287265bb19480b2c894d95a100d65869dc4c1e15115a2038c3c3a00
0x6fdcb0 55                               push   ebp
0x6fdcb1 8bec                             mov    ebp,esp
0x6fdcb3 51                               push   ecx
0x6fdcb4 53                               push   ebx
0x6fdcb5 57                               push   edi
0x6fdcb6 8bf8                             mov    edi,eax
0x6fdcb8 8b4620                           mov    eax,DWORD PTR [esi+0x20]
0x6fdcbb 8d5f06                           lea    ebx,[edi+0x6]
0x6fdcbe 8d4b01                           lea    ecx,[ebx+0x1]
0x6fdcc1 8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x6fdcc4 81f9ffffff0f                     cmp    ecx,0xfffffff
0x6fdcca 7719                             ja     0x6fdce5
0x6fdccc 8b4e2c                           mov    ecx,DWORD PTR [esi+0x2c]
0x6fdccf 8bd3                             mov    edx,ebx
0x6fdcd1 c1e204                           shl    edx,0x4
0x6fdcd4 52                               push   edx
0x6fdcd5 c1e104                           shl    ecx,0x4
0x6fdcd8 51                               push   ecx
0x6fdcd9 50                               push   eax
0x6fdcda 56                               push   esi
0x6fdcdb e8a02b0000                       call   0x700880
0x6fdce0 83c410                           add    esp,0x10
0x6fdce3 eb09                             jmp    0x6fdcee
0x6fdce5 56                               push   esi
0x6fdce6 e8752b0000                       call   0x700860
0x6fdceb 83c404                           add    esp,0x4
0x6fdcee 8b55fc                           mov    edx,DWORD PTR [ebp-0x4]
0x6fdcf1 c1e704                           shl    edi,0x4
0x6fdcf4 03f8                             add    edi,eax
0x6fdcf6 8bce                             mov    ecx,esi
0x6fdcf8 894620                           mov    DWORD PTR [esi+0x20],eax
0x6fdcfb 895e2c                           mov    DWORD PTR [esi+0x2c],ebx
0x6fdcfe 897e1c                           mov    DWORD PTR [esi+0x1c],edi
0x6fdd01 e82affffff                       call   0x6fdc30
0x6fdd06 5f                               pop    edi
0x6fdd07 5b                               pop    ebx
0x6fdd08 8be5                             mov    esp,ebp
0x6fdd0a 5d                               pop    ebp
0x6fdd0b c3                               ret

; F_006FDC30 source=kr-extra-roy/MEF-P0-content-contracts-20261117/abi-adoption/native-evidence.json blob=c5b59f574864bd281bf26b212fe447e600023352
; VA 0x6fdc30 raw 0x2fd030 SHA256 25e1b1c85750b2e617c7633897eac161ac89a7e4213a2e223dc206d0a5af3425
0x6fdc30 8b4108                           mov    eax,DWORD PTR [ecx+0x8]
0x6fdc33 2bc2                             sub    eax,edx
0x6fdc35 83e0f0                           and    eax,0xfffffff0
0x6fdc38 034120                           add    eax,DWORD PTR [ecx+0x20]
0x6fdc3b 56                               push   esi
0x6fdc3c 894108                           mov    DWORD PTR [ecx+0x8],eax
0x6fdc3f 8b4168                           mov    eax,DWORD PTR [ecx+0x68]
0x6fdc42 85c0                             test   eax,eax
0x6fdc44 7414                             je     0x6fdc5a
0x6fdc46 8b7008                           mov    esi,DWORD PTR [eax+0x8]
0x6fdc49 2bf2                             sub    esi,edx
0x6fdc4b 83e6f0                           and    esi,0xfffffff0
0x6fdc4e 037120                           add    esi,DWORD PTR [ecx+0x20]
0x6fdc51 897008                           mov    DWORD PTR [eax+0x8],esi
0x6fdc54 8b00                             mov    eax,DWORD PTR [eax]
0x6fdc56 85c0                             test   eax,eax
0x6fdc58 75ec                             jne    0x6fdc46
0x6fdc5a 8b4128                           mov    eax,DWORD PTR [ecx+0x28]
0x6fdc5d 3b4114                           cmp    eax,DWORD PTR [ecx+0x14]
0x6fdc60 7732                             ja     0x6fdc94
0x6fdc62 8b7008                           mov    esi,DWORD PTR [eax+0x8]
0x6fdc65 2bf2                             sub    esi,edx
0x6fdc67 83e6f0                           and    esi,0xfffffff0
0x6fdc6a 037120                           add    esi,DWORD PTR [ecx+0x20]
0x6fdc6d 83c018                           add    eax,0x18
0x6fdc70 8970f0                           mov    DWORD PTR [eax-0x10],esi
0x6fdc73 8b70e8                           mov    esi,DWORD PTR [eax-0x18]
0x6fdc76 2bf2                             sub    esi,edx
0x6fdc78 83e6f0                           and    esi,0xfffffff0
0x6fdc7b 037120                           add    esi,DWORD PTR [ecx+0x20]
0x6fdc7e 8970e8                           mov    DWORD PTR [eax-0x18],esi
0x6fdc81 8b70ec                           mov    esi,DWORD PTR [eax-0x14]
0x6fdc84 2bf2                             sub    esi,edx
0x6fdc86 83e6f0                           and    esi,0xfffffff0
0x6fdc89 037120                           add    esi,DWORD PTR [ecx+0x20]
0x6fdc8c 8970ec                           mov    DWORD PTR [eax-0x14],esi
0x6fdc8f 3b4114                           cmp    eax,DWORD PTR [ecx+0x14]
0x6fdc92 76ce                             jbe    0x6fdc62
0x6fdc94 8b410c                           mov    eax,DWORD PTR [ecx+0xc]
0x6fdc97 2bc2                             sub    eax,edx
0x6fdc99 83e0f0                           and    eax,0xfffffff0
0x6fdc9c 034120                           add    eax,DWORD PTR [ecx+0x20]
0x6fdc9f 5e                               pop    esi
0x6fdca0 89410c                           mov    DWORD PTR [ecx+0xc],eax
0x6fdca3 c3                               ret

; F_006FDD90 source=kr-extra-roy/MEF-P0-content-contracts-20261117/abi-adoption/native-evidence.json blob=c5b59f574864bd281bf26b212fe447e600023352
; VA 0x6fdd90 raw 0x2fd190 SHA256 26dd40b283b4c4ebc35f81d746d00b7d624532a7e287790b907b5e9887e0796a
0x6fdd90 56                               push   esi
0x6fdd91 8bf0                             mov    esi,eax
0x6fdd93 8b4630                           mov    eax,DWORD PTR [esi+0x30]
0x6fdd96 3d204e0000                       cmp    eax,0x4e20
0x6fdd9b 7e16                             jle    0x6fddb3
0x6fdd9d 6a05                             push   0x5
0x6fdd9f 56                               push   esi
0x6fdda0 e89bfdffff                       call   0x6fdb40
0x6fdda5 8b4614                           mov    eax,DWORD PTR [esi+0x14]
0x6fdda8 83c408                           add    esp,0x8
0x6fddab 83c018                           add    eax,0x18
0x6fddae 894614                           mov    DWORD PTR [esi+0x14],eax
0x6fddb1 5e                               pop    esi
0x6fddb2 c3                               ret
0x6fddb3 57                               push   edi
0x6fddb4 8d3c00                           lea    edi,[eax+eax*1]
0x6fddb7 e854ffffff                       call   0x6fdd10
0x6fddbc 817e30204e0000                   cmp    DWORD PTR [esi+0x30],0x4e20
0x6fddc3 5f                               pop    edi
0x6fddc4 7e0e                             jle    0x6fddd4
0x6fddc6 68ec2ac400                       push   0xc42aec
0x6fddcb 56                               push   esi
0x6fddcc e88fadffff                       call   0x6f8b60
0x6fddd1 83c408                           add    esp,0x8
0x6fddd4 8b4614                           mov    eax,DWORD PTR [esi+0x14]
0x6fddd7 83c018                           add    eax,0x18
0x6fddda 894614                           mov    DWORD PTR [esi+0x14],eax
0x6fdddd 5e                               pop    esi
0x6fddde c3                               ret

; F_006FDD10 source=kr-extra-roy/MEF-P0-content-contracts-20261117/abi-adoption/native-evidence.json blob=c5b59f574864bd281bf26b212fe447e600023352
; VA 0x6fdd10 raw 0x2fd110 SHA256 e2f689ff4633915fe8857ccccaa8b96765f95b5794d7cf70db7c1a46366dca69
0x6fdd10 55                               push   ebp
0x6fdd11 8bec                             mov    ebp,esp
0x6fdd13 51                               push   ecx
0x6fdd14 8b4e28                           mov    ecx,DWORD PTR [esi+0x28]
0x6fdd17 8d4701                           lea    eax,[edi+0x1]
0x6fdd1a 53                               push   ebx
0x6fdd1b 894dfc                           mov    DWORD PTR [ebp-0x4],ecx
0x6fdd1e 3daaaaaa0a                       cmp    eax,0xaaaaaaa
0x6fdd23 7723                             ja     0x6fdd48
0x6fdd25 8b4630                           mov    eax,DWORD PTR [esi+0x30]
0x6fdd28 8d0440                           lea    eax,[eax+eax*2]
0x6fdd2b 8d147f                           lea    edx,[edi+edi*2]
0x6fdd2e 03d2                             add    edx,edx
0x6fdd30 03c0                             add    eax,eax
0x6fdd32 03d2                             add    edx,edx
0x6fdd34 03d2                             add    edx,edx
0x6fdd36 52                               push   edx
0x6fdd37 03c0                             add    eax,eax
0x6fdd39 03c0                             add    eax,eax
0x6fdd3b 50                               push   eax
0x6fdd3c 51                               push   ecx
0x6fdd3d 56                               push   esi
0x6fdd3e e83d2b0000                       call   0x700880
0x6fdd43 83c410                           add    esp,0x10
0x6fdd46 eb09                             jmp    0x6fdd51
0x6fdd48 56                               push   esi
0x6fdd49 e8122b0000                       call   0x700860
0x6fdd4e 83c404                           add    esp,0x4
0x6fdd51 8b4e14                           mov    ecx,DWORD PTR [esi+0x14]
0x6fdd54 2b4dfc                           sub    ecx,DWORD PTR [ebp-0x4]
0x6fdd57 8bd8                             mov    ebx,eax
0x6fdd59 b8abaaaa2a                       mov    eax,0x2aaaaaab
0x6fdd5e f7e9                             imul   ecx
0x6fdd60 c1fa02                           sar    edx,0x2
0x6fdd63 8bc2                             mov    eax,edx
0x6fdd65 c1e81f                           shr    eax,0x1f
0x6fdd68 03c2                             add    eax,edx
0x6fdd6a 8d0c40                           lea    ecx,[eax+eax*2]
0x6fdd6d 8d14cb                           lea    edx,[ebx+ecx*8]
0x6fdd70 8d047f                           lea    eax,[edi+edi*2]
0x6fdd73 8d4cc3e8                         lea    ecx,[ebx+eax*8-0x18]
0x6fdd77 895e28                           mov    DWORD PTR [esi+0x28],ebx
0x6fdd7a 897e30                           mov    DWORD PTR [esi+0x30],edi
0x6fdd7d 895614                           mov    DWORD PTR [esi+0x14],edx
0x6fdd80 894e24                           mov    DWORD PTR [esi+0x24],ecx
0x6fdd83 5b                               pop    ebx
0x6fdd84 8be5                             mov    esp,ebp
0x6fdd86 5d                               pop    ebp
0x6fdd87 c3                               ret

; q_flying_create source=kr-extra-roy/MEF-comprehensive-contracts-20261117/reuse/native-evidence.json blob=d845ccb8e5d8b744b76651d743ce90bc82d546f4
; VA 0x564940 raw 0x163d40 SHA256 d84fc1b6bcd5eb80ea5eecfec60a3dcbfef824fbf5e52295d518003955f943e2
0x564940 55                               push   ebp
0x564941 8bec                             mov    ebp,esp
0x564943 6aff                             push   0xffffffff
0x564945 68b9de9100                       push   0x91deb9
0x56494a 64a100000000                     mov    eax,fs:0x0
0x564950 50                               push   eax
0x564951 83ec10                           sub    esp,0x10
0x564954 53                               push   ebx
0x564955 56                               push   esi
0x564956 57                               push   edi
0x564957 a1201fd600                       mov    eax,ds:0xd61f20
0x56495c 33c5                             xor    eax,ebp
0x56495e 50                               push   eax
0x56495f 8d45f4                           lea    eax,[ebp-0xc]
0x564962 64a300000000                     mov    fs:0x0,eax
0x564968 8bd9                             mov    ebx,ecx
0x56496a e8f1000000                       call   0x564a60
0x56496f 6a70                             push   0x70
0x564971 e8f2c83200                       call   0x891268
0x564976 8bf0                             mov    esi,eax
0x564978 83c404                           add    esp,0x4
0x56497b 8975ec                           mov    DWORD PTR [ebp-0x14],esi
0x56497e 33ff                             xor    edi,edi
0x564980 897dfc                           mov    DWORD PTR [ebp-0x4],edi
0x564983 3bf7                             cmp    esi,edi
0x564985 7433                             je     0x5649ba
0x564987 397d20                           cmp    DWORD PTR [ebp+0x20],edi
0x56498a 7405                             je     0x564991
0x56498c 83c8ff                           or     eax,0xffffffff
0x56498f eb03                             jmp    0x564994
0x564991 8b4518                           mov    eax,DWORD PTR [ebp+0x18]
0x564994 8b4d1c                           mov    ecx,DWORD PTR [ebp+0x1c]
0x564997 8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0x56499a 57                               push   edi
0x56499b 51                               push   ecx
0x56499c 8b4d14                           mov    ecx,DWORD PTR [ebp+0x14]
0x56499f 50                               push   eax
0x5649a0 56                               push   esi
0x5649a1 e8eaf4feff                       call   0x553e90
0x5649a6 8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0x5649a9 8b4510                           mov    eax,DWORD PTR [ebp+0x10]
0x5649ac c7064807c100                     mov    DWORD PTR [esi],0xc10748
0x5649b2 895668                           mov    DWORD PTR [esi+0x68],edx
0x5649b5 89466c                           mov    DWORD PTR [esi+0x6c],eax
0x5649b8 eb02                             jmp    0x5649bc
0x5649ba 33f6                             xor    esi,esi
0x5649bc c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x5649c3 f6055473fb0001                   test   BYTE PTR ds:0xfb7354,0x1
0x5649ca 7527                             jne    0x5649f3
0x5649cc b801000000                       mov    eax,0x1
0x5649d1 09055473fb00                     or     DWORD PTR ds:0xfb7354,eax
0x5649d7 8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x5649da e8f1e9feff                       call   0x5533d0
0x5649df 6800d1bc00                       push   0xbcd100
0x5649e4 e831d93200                       call   0x89231a
0x5649e9 83c404                           add    esp,0x4
0x5649ec c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x5649f3 8b16                             mov    edx,DWORD PTR [esi]
0x5649f5 8b4204                           mov    eax,DWORD PTR [edx+0x4]
0x5649f8 8bce                             mov    ecx,esi
0x5649fa ffd0                             call   eax
0x5649fc a1b073fb00                       mov    eax,ds:0xfb73b0
0x564a01 8b0dac73fb00                     mov    ecx,DWORD PTR ds:0xfb73ac
0x564a07 8b16                             mov    edx,DWORD PTR [esi]
0x564a09 8b5220                           mov    edx,DWORD PTR [edx+0x20]
0x564a0c 50                               push   eax
0x564a0d 51                               push   ecx
0x564a0e 8bce                             mov    ecx,esi
0x564a10 ffd2                             call   edx
0x564a12 897e40                           mov    DWORD PTR [esi+0x40],edi
0x564a15 a19873fb00                       mov    eax,ds:0xfb7398
0x564a1a 8975ec                           mov    DWORD PTR [ebp-0x14],esi
0x564a1d 8d7de8                           lea    edi,[ebp-0x18]
0x564a20 be5873fb00                       mov    esi,0xfb7358
0x564a25 8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x564a28 e8f3a40100                       call   0x57ef20
0x564a2d 50                               push   eax
0x564a2e 56                               push   esi
0x564a2f 8d75e8                           lea    esi,[ebp-0x18]
0x564a32 e8c9a72c00                       call   0x82f200
0x564a37 a19873fb00                       mov    eax,ds:0xfb7398
0x564a3c 8bc8                             mov    ecx,eax
0x564a3e 40                               inc    eax
0x564a3f a39873fb00                       mov    ds:0xfb7398,eax
0x564a44 894b40                           mov    DWORD PTR [ebx+0x40],ecx
0x564a47 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x564a4a 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x564a51 59                               pop    ecx
0x564a52 5f                               pop    edi
0x564a53 5e                               pop    esi
0x564a54 5b                               pop    ebx
0x564a55 8be5                             mov    esp,ebp
0x564a57 5d                               pop    ebp
0x564a58 c21c00                           ret    0x1c

; q_flying_cancel source=kr-extra-roy/MEF-comprehensive-contracts-20261117/reuse/native-evidence.json blob=d845ccb8e5d8b744b76651d743ce90bc82d546f4
; VA 0x564a60 raw 0x163e60 SHA256 a06f78b3f59ba829401588af3621b133fb49cdf733c2bde766fc5fbf6b2be535
0x564a60 55                               push   ebp
0x564a61 8bec                             mov    ebp,esp
0x564a63 6aff                             push   0xffffffff
0x564a65 68eece9000                       push   0x90ceee
0x564a6a 64a100000000                     mov    eax,fs:0x0
0x564a70 50                               push   eax
0x564a71 83ec08                           sub    esp,0x8
0x564a74 56                               push   esi
0x564a75 a1201fd600                       mov    eax,ds:0xd61f20
0x564a7a 33c5                             xor    eax,ebp
0x564a7c 50                               push   eax
0x564a7d 8d45f4                           lea    eax,[ebp-0xc]
0x564a80 64a300000000                     mov    fs:0x0,eax
0x564a86 8bf1                             mov    esi,ecx
0x564a88 b801000000                       mov    eax,0x1
0x564a8d 84055473fb00                     test   BYTE PTR ds:0xfb7354,al
0x564a93 751f                             jne    0x564ab4
0x564a95 09055473fb00                     or     DWORD PTR ds:0xfb7354,eax
0x564a9b c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x564aa2 e829e9feff                       call   0x5533d0
0x564aa7 6800d1bc00                       push   0xbcd100
0x564aac e869d83200                       call   0x89231a
0x564ab1 83c404                           add    esp,0x4
0x564ab4 8b4640                           mov    eax,DWORD PTR [esi+0x40]
0x564ab7 8d4df0                           lea    ecx,[ebp-0x10]
0x564aba 8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x564abd 51                               push   ecx
0x564abe 8d45ec                           lea    eax,[ebp-0x14]
0x564ac1 b95873fb00                       mov    ecx,0xfb7358
0x564ac6 e835a42c00                       call   0x82ef00
0x564acb 8b45ec                           mov    eax,DWORD PTR [ebp-0x14]
0x564ace 3b055c73fb00                     cmp    eax,DWORD PTR ds:0xfb735c
0x564ad4 740e                             je     0x564ae4
0x564ad6 8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x564ad9 85c0                             test   eax,eax
0x564adb 7407                             je     0x564ae4
0x564add c7401400000000                   mov    DWORD PTR [eax+0x14],0x0
0x564ae4 c74640ffffffff                   mov    DWORD PTR [esi+0x40],0xffffffff
0x564aeb 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x564aee 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x564af5 59                               pop    ecx
0x564af6 5e                               pop    esi
0x564af7 8be5                             mov    esp,ebp
0x564af9 5d                               pop    ebp
0x564afa c3                               ret

; q_create_actor source=kr-extra-roy/MEF-comprehensive-contracts-20261117/reuse-followup/native-evidence.json blob=c8ec93d4c12340f15bb0753d1d22a004d0cc44b4
; VA 0x562ec0 raw 0x1622c0 SHA256 c70cd69c66adb257ff96a92bcadedb19a32c4f1bd357cad824f39932bcc2dc1a
0x562ec0 55                               push   ebp
0x562ec1 8bec                             mov    ebp,esp
0x562ec3 83e4f8                           and    esp,0xfffffff8
0x562ec6 6aff                             push   0xffffffff
0x562ec8 6803a19300                       push   0x93a103
0x562ecd 64a100000000                     mov    eax,fs:0x0
0x562ed3 50                               push   eax
0x562ed4 83ec20                           sub    esp,0x20
0x562ed7 53                               push   ebx
0x562ed8 56                               push   esi
0x562ed9 57                               push   edi
0x562eda a1201fd600                       mov    eax,ds:0xd61f20
0x562edf 33c4                             xor    eax,esp
0x562ee1 50                               push   eax
0x562ee2 8d442430                         lea    eax,[esp+0x30]
0x562ee6 64a300000000                     mov    fs:0x0,eax
0x562eec 894c2418                         mov    DWORD PTR [esp+0x18],ecx
0x562ef0 8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
0x562ef3 33c0                             xor    eax,eax
0x562ef5 6689442414                       mov    WORD PTR [esp+0x14],ax
0x562efa 83ff0a                           cmp    edi,0xa
0x562efd 7d06                             jge    0x562f05
0x562eff 88442414                         mov    BYTE PTR [esp+0x14],al
0x562f03 eb40                             jmp    0x562f45
0x562f05 81ff10270000                     cmp    edi,0x2710
0x562f0b 7d07                             jge    0x562f14
0x562f0d c644241401                       mov    BYTE PTR [esp+0x14],0x1
0x562f12 eb31                             jmp    0x562f45
0x562f14 81fff82a0000                     cmp    edi,0x2af8
0x562f1a 7d07                             jge    0x562f23
0x562f1c c644241406                       mov    BYTE PTR [esp+0x14],0x6
0x562f21 eb22                             jmp    0x562f45
0x562f23 81ff08520000                     cmp    edi,0x5208
0x562f29 7d07                             jge    0x562f32
0x562f2b c644241407                       mov    BYTE PTR [esp+0x14],0x7
0x562f30 eb13                             jmp    0x562f45
0x562f32 57                               push   edi
0x562f33 681807c100                       push   0xc10718
0x562f38 e823ac1800                       call   0x6edb60
0x562f3d 83c408                           add    esp,0x8
0x562f40 c644241400                       mov    BYTE PTR [esp+0x14],0x0
0x562f45 8a4d08                           mov    cl,BYTE PTR [ebp+0x8]
0x562f48 6838040000                       push   0x438
0x562f4d 884c2419                         mov    BYTE PTR [esp+0x19],cl
0x562f51 e812e33200                       call   0x891268
0x562f56 83c404                           add    esp,0x4
0x562f59 89442424                         mov    DWORD PTR [esp+0x24],eax
0x562f5d 33db                             xor    ebx,ebx
0x562f5f 895c2438                         mov    DWORD PTR [esp+0x38],ebx
0x562f63 3bc3                             cmp    eax,ebx
0x562f65 7408                             je     0x562f6f
0x562f67 50                               push   eax
0x562f68 e813dcf6ff                       call   0x4d0b80
0x562f6d 8bd8                             mov    ebx,eax
0x562f6f c7442438ffffffff                 mov    DWORD PTR [esp+0x38],0xffffffff
0x562f77 668b542414                       mov    dx,WORD PTR [esp+0x14]
0x562f7c 0fb6f2                           movzx  esi,dl
0x562f7f 0fb7c7                           movzx  eax,di
0x562f82 66895304                         mov    WORD PTR [ebx+0x4],dx
0x562f86 8b13                             mov    edx,DWORD PTR [ebx]
0x562f88 c1e618                           shl    esi,0x18
0x562f8b 0bf0                             or     esi,eax
0x562f8d 8b423c                           mov    eax,DWORD PTR [edx+0x3c]
0x562f90 56                               push   esi
0x562f91 8bcb                             mov    ecx,ebx
0x562f93 c7839000000010000000             mov    DWORD PTR [ebx+0x90],0x10
0x562f9d ffd0                             call   eax
0x562f9f f30f104510                       movss  xmm0,DWORD PTR [ebp+0x10]
0x562fa4 8b13                             mov    edx,DWORD PTR [ebx]
0x562fa6 8b5244                           mov    edx,DWORD PTR [edx+0x44]
0x562fa9 6a01                             push   0x1
0x562fab 8d442428                         lea    eax,[esp+0x28]
0x562faf f30f11442428                     movss  DWORD PTR [esp+0x28],xmm0
0x562fb5 f30f104514                       movss  xmm0,DWORD PTR [ebp+0x14]
0x562fba 50                               push   eax
0x562fbb 8bcb                             mov    ecx,ebx
0x562fbd f30f11442430                     movss  DWORD PTR [esp+0x30],xmm0
0x562fc3 ffd2                             call   edx
0x562fc5 8b4d18                           mov    ecx,DWORD PTR [ebp+0x18]
0x562fc8 8b03                             mov    eax,DWORD PTR [ebx]
0x562fca 8b5058                           mov    edx,DWORD PTR [eax+0x58]
0x562fcd 51                               push   ecx
0x562fce 8bcb                             mov    ecx,ebx
0x562fd0 ffd2                             call   edx
0x562fd2 f605b075fb0001                   test   BYTE PTR ds:0xfb75b0,0x1
0x562fd9 7529                             jne    0x563004
0x562fdb b801000000                       mov    eax,0x1
0x562fe0 0905b075fb00                     or     DWORD PTR ds:0xfb75b0,eax
0x562fe6 89442438                         mov    DWORD PTR [esp+0x38],eax
0x562fea e8910df9ff                       call   0x4f3d80
0x562fef 68e0d1bc00                       push   0xbcd1e0
0x562ff4 e821f33200                       call   0x89231a
0x562ff9 83c404                           add    esp,0x4
0x562ffc c7442438ffffffff                 mov    DWORD PTR [esp+0x38],0xffffffff
0x563004 8d54241c                         lea    edx,[esp+0x1c]
0x563008 b97074fb00                       mov    ecx,0xfb7470
0x56300d 8974241c                         mov    DWORD PTR [esp+0x1c],esi
0x563011 e85a4af9ff                       call   0x4f7a70
0x563016 d9405c                           fld    DWORD PTR [eax+0x5c]
0x563019 8b03                             mov    eax,DWORD PTR [ebx]
0x56301b d95c241c                         fstp   DWORD PTR [esp+0x1c]
0x56301f d944241c                         fld    DWORD PTR [esp+0x1c]
0x563023 8b505c                           mov    edx,DWORD PTR [eax+0x5c]
0x563026 51                               push   ecx
0x563027 8bcb                             mov    ecx,ebx
0x563029 d91c24                           fstp   DWORD PTR [esp]
0x56302c ffd2                             call   edx
0x56302e 8b4d24                           mov    ecx,DWORD PTR [ebp+0x24]
0x563031 83ff0a                           cmp    edi,0xa
0x563034 7d09                             jge    0x56303f
0x563036 85c9                             test   ecx,ecx
0x563038 7505                             jne    0x56303f
0x56303a b901000000                       mov    ecx,0x1
0x56303f 8b835c010000                     mov    eax,DWORD PTR [ebx+0x15c]
0x563045 66898b88030000                   mov    WORD PTR [ebx+0x388],cx
0x56304c 85c0                             test   eax,eax
0x56304e 7412                             je     0x563062
0x563050 83bb7003000000                   cmp    DWORD PTR [ebx+0x370],0x0
0x563057 7409                             je     0x563062
0x563059 51                               push   ecx
0x56305a 6a01                             push   0x1
0x56305c 50                               push   eax
0x56305d e83e3e2400                       call   0x7a6ea0
0x563062 f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
0x563069 7529                             jne    0x563094
0x56306b 830d600ffc0001                   or     DWORD PTR ds:0xfc0f60,0x1
0x563072 c744243802000000                 mov    DWORD PTR [esp+0x38],0x2
0x56307a e8c19e2300                       call   0x79cf40
0x56307f 6880dbbc00                       push   0xbcdb80
0x563084 e891f23200                       call   0x89231a
0x563089 83c404                           add    esp,0x4
0x56308c c7442438ffffffff                 mov    DWORD PTR [esp+0x38],0xffffffff
0x563094 8d44241c                         lea    eax,[esp+0x1c]
0x563098 50                               push   eax
0x563099 8d442418                         lea    eax,[esp+0x18]
0x56309d b9900efc00                       mov    ecx,0xfc0e90
0x5630a2 897c2420                         mov    DWORD PTR [esp+0x20],edi
0x5630a6 e8e526fbff                       call   0x515790
0x5630ab 8b442414                         mov    eax,DWORD PTR [esp+0x14]
0x5630af 3b05940efc00                     cmp    eax,DWORD PTR ds:0xfc0e94
0x5630b5 7409                             je     0x5630c0
0x5630b7 8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x5630ba 83785400                         cmp    DWORD PTR [eax+0x54],0x0
0x5630be 7553                             jne    0x563113
0x5630c0 8b742418                         mov    esi,DWORD PTR [esp+0x18]
0x5630c4 8d4d0c                           lea    ecx,[ebp+0xc]
0x5630c7 83c660                           add    esi,0x60
0x5630ca 51                               push   ecx
0x5630cb e870ad1500                       call   0x6bde40
0x5630d0 50                               push   eax
0x5630d1 56                               push   esi
0x5630d2 8d74242c                         lea    esi,[esp+0x2c]
0x5630d6 e8f58aeeff                       call   0x44bbd0
0x5630db f605400efc0001                   test   BYTE PTR ds:0xfc0e40,0x1
0x5630e2 7529                             jne    0x56310d
0x5630e4 830d400efc0001                   or     DWORD PTR ds:0xfc0e40,0x1
0x5630eb c744243803000000                 mov    DWORD PTR [esp+0x38],0x3
0x5630f3 e878d6fdff                       call   0x540770
0x5630f8 6860dbbc00                       push   0xbcdb60
0x5630fd e818f23200                       call   0x89231a
0x563102 83c404                           add    esp,0x4
0x563105 c7442438ffffffff                 mov    DWORD PTR [esp+0x38],0xffffffff
0x56310d 57                               push   edi
0x56310e e8fde4fdff                       call   0x541610
0x563113 8b542418                         mov    edx,DWORD PTR [esp+0x18]
0x563117 837a7000                         cmp    DWORD PTR [edx+0x70],0x0
0x56311b 0f840b010000                     je     0x56322c
0x563121 f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
0x563128 7529                             jne    0x563153
0x56312a 830d600ffc0001                   or     DWORD PTR ds:0xfc0f60,0x1
0x563131 c744243804000000                 mov    DWORD PTR [esp+0x38],0x4
0x563139 e8029e2300                       call   0x79cf40
0x56313e 6880dbbc00                       push   0xbcdb80
0x563143 e8d2f13200                       call   0x89231a
0x563148 83c404                           add    esp,0x4
0x56314b c7442438ffffffff                 mov    DWORD PTR [esp+0x38],0xffffffff
0x563153 8d44241c                         lea    eax,[esp+0x1c]
0x563157 50                               push   eax
0x563158 8d442418                         lea    eax,[esp+0x18]
0x56315c b9900efc00                       mov    ecx,0xfc0e90
0x563161 897c2420                         mov    DWORD PTR [esp+0x20],edi
0x563165 e82626fbff                       call   0x515790
0x56316a 8b442414                         mov    eax,DWORD PTR [esp+0x14]
0x56316e 3b05940efc00                     cmp    eax,DWORD PTR ds:0xfc0e94
0x563174 0f84b2000000                     je     0x56322c
0x56317a 8b4810                           mov    ecx,DWORD PTR [eax+0x10]
0x56317d 8b7154                           mov    esi,DWORD PTR [ecx+0x54]
0x563180 85f6                             test   esi,esi
0x563182 0f84a4000000                     je     0x56322c
0x563188 6a01                             push   0x1
0x56318a 8bfe                             mov    edi,esi
0x56318c e85f262600                       call   0x7c57f0
0x563191 6a04                             push   0x4
0x563193 e858262600                       call   0x7c57f0
0x563198 8b442418                         mov    eax,DWORD PTR [esp+0x18]
0x56319c 0fb75508                         movzx  edx,WORD PTR [ebp+0x8]
0x5631a0 8b7870                           mov    edi,DWORD PTR [eax+0x70]
0x5631a3 8d4c241c                         lea    ecx,[esp+0x1c]
0x5631a7 51                               push   ecx
0x5631a8 8d442418                         lea    eax,[esp+0x18]
0x5631ac 8bcf                             mov    ecx,edi
0x5631ae 89542420                         mov    DWORD PTR [esp+0x20],edx
0x5631b2 e8c9302c00                       call   0x826280
0x5631b7 8b442414                         mov    eax,DWORD PTR [esp+0x14]
0x5631bb 3b4704                           cmp    eax,DWORD PTR [edi+0x4]
0x5631be 746c                             je     0x56322c
0x5631c0 8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x5631c3 8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x5631c6 89442424                         mov    DWORD PTR [esp+0x24],eax
0x5631ca 8b01                             mov    eax,DWORD PTR [ecx]
0x5631cc 8944241c                         mov    DWORD PTR [esp+0x1c],eax
0x5631d0 3bc1                             cmp    eax,ecx
0x5631d2 7458                             je     0x56322c
0x5631d4 0fb7500c                         movzx  edx,WORD PTR [eax+0xc]
0x5631d8 8d442414                         lea    eax,[esp+0x14]
0x5631dc 50                               push   eax
0x5631dd 8d442424                         lea    eax,[esp+0x24]
0x5631e1 8d8ed4000000                     lea    ecx,[esi+0xd4]
0x5631e7 89542418                         mov    DWORD PTR [esp+0x18],edx
0x5631eb e810bd2c00                       call   0x82ef00
0x5631f0 8b7c2420                         mov    edi,DWORD PTR [esp+0x20]
0x5631f4 3bbed8000000                     cmp    edi,DWORD PTR [esi+0xd8]
0x5631fa 741a                             je     0x563216
0x5631fc 8b4f10                           mov    ecx,DWORD PTR [edi+0x10]
0x5631ff 8b11                             mov    edx,DWORD PTR [ecx]
0x563201 8b4208                           mov    eax,DWORD PTR [edx+0x8]
0x563204 ffd0                             call   eax
0x563206 3b442414                         cmp    eax,DWORD PTR [esp+0x14]
0x56320a 750a                             jne    0x563216
0x56320c 8b4f10                           mov    ecx,DWORD PTR [edi+0x10]
0x56320f 8b11                             mov    edx,DWORD PTR [ecx]
0x563211 8b4224                           mov    eax,DWORD PTR [edx+0x24]
0x563214 ffd0                             call   eax
0x563216 8d44241c                         lea    eax,[esp+0x1c]
0x56321a e831a62b00                       call   0x81d850
0x56321f 8b44241c                         mov    eax,DWORD PTR [esp+0x1c]
0x563223 8b4c2424                         mov    ecx,DWORD PTR [esp+0x24]
0x563227 3b4108                           cmp    eax,DWORD PTR [ecx+0x8]
0x56322a 75a8                             jne    0x5631d4
0x56322c 8bf3                             mov    esi,ebx
0x56322e e8adddf6ff                       call   0x4d0fe0
0x563233 8b93f0000000                     mov    edx,DWORD PTR [ebx+0xf0]
0x563239 8b4208                           mov    eax,DWORD PTR [edx+0x8]
0x56323c 8d8bf0000000                     lea    ecx,[ebx+0xf0]
0x563242 6a14                             push   0x14
0x563244 ffd0                             call   eax
0x563246 d9e8                             fld1
0x563248 8b13                             mov    edx,DWORD PTR [ebx]
0x56324a 8b451c                           mov    eax,DWORD PTR [ebp+0x1c]
0x56324d 8b5268                           mov    edx,DWORD PTR [edx+0x68]
0x563250 51                               push   ecx
0x563251 d91c24                           fstp   DWORD PTR [esp]
0x563254 50                               push   eax
0x563255 8bcb                             mov    ecx,ebx
0x563257 ffd2                             call   edx
0x563259 8b4d28                           mov    ecx,DWORD PTR [ebp+0x28]
0x56325c 85c9                             test   ecx,ecx
0x56325e 7421                             je     0x563281
0x563260 8b835c010000                     mov    eax,DWORD PTR [ebx+0x15c]
0x563266 85c0                             test   eax,eax
0x563268 7417                             je     0x563281
0x56326a 83bb7003000000                   cmp    DWORD PTR [ebx+0x370],0x0
0x563271 740e                             je     0x563281
0x563273 6a00                             push   0x0
0x563275 0fb7c9                           movzx  ecx,cx
0x563278 6a00                             push   0x0
0x56327a 51                               push   ecx
0x56327b 50                               push   eax
0x56327c e8bf3f2400                       call   0x7a7240
0x563281 8b5520                           mov    edx,DWORD PTR [ebp+0x20]
0x563284 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x563287 8b742418                         mov    esi,DWORD PTR [esp+0x18]
0x56328b 83c618                           add    esi,0x18
0x56328e 8d7c2424                         lea    edi,[esp+0x24]
0x563292 89932c040000                     mov    DWORD PTR [ebx+0x42c],edx
0x563298 89442424                         mov    DWORD PTR [esp+0x24],eax
0x56329c 895c2428                         mov    DWORD PTR [esp+0x28],ebx
0x5632a0 e87bbc0100                       call   0x57ef20
0x5632a5 50                               push   eax
0x5632a6 56                               push   esi
0x5632a7 8d74242c                         lea    esi,[esp+0x2c]
0x5632ab e850bf2c00                       call   0x82f200
0x5632b0 8b4c2430                         mov    ecx,DWORD PTR [esp+0x30]
0x5632b4 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x5632bb 59                               pop    ecx
0x5632bc 5f                               pop    edi
0x5632bd 5e                               pop    esi
0x5632be 5b                               pop    ebx
0x5632bf 8be5                             mov    esp,ebp
0x5632c1 5d                               pop    ebp
0x5632c2 c22400                           ret    0x24

; q_actor_immediate_init source=kr-extra-roy/MEF-comprehensive-contracts-20261117/reuse-followup/native-evidence.json blob=c8ec93d4c12340f15bb0753d1d22a004d0cc44b4
; VA 0x4d0fe0 raw 0xd03e0 SHA256 e8e96b6111fef172f31d4c01f63699db38780fa77aaac1008582e78ec2532df3
0x4d0fe0 57                               push   edi
0x4d0fe1 6a01                             push   0x1
0x4d0fe3 56                               push   esi
0x4d0fe4 e8076effff                       call   0x4c7df0
0x4d0fe9 8d8ef0000000                     lea    ecx,[esi+0xf0]
0x4d0fef 8bf8                             mov    edi,eax
0x4d0ff1 8b01                             mov    eax,DWORD PTR [ecx]
0x4d0ff3 8b5008                           mov    edx,DWORD PTR [eax+0x8]
0x4d0ff6 6a14                             push   0x14
0x4d0ff8 ffd2                             call   edx
0x4d0ffa 8b8668030000                     mov    eax,DWORD PTR [esi+0x368]
0x4d1000 85c0                             test   eax,eax
0x4d1002 7407                             je     0x4d100b
0x4d1004 c7402400000000                   mov    DWORD PTR [eax+0x24],0x0
0x4d100b 83be5c01000000                   cmp    DWORD PTR [esi+0x15c],0x0
0x4d1012 742a                             je     0x4d103e
0x4d1014 8b865c010000                     mov    eax,DWORD PTR [esi+0x15c]
0x4d101a 8b4818                           mov    ecx,DWORD PTR [eax+0x18]
0x4d101d 6a00                             push   0x0
0x4d101f 6a00                             push   0x0
0x4d1021 81c118790000                     add    ecx,0x7918
0x4d1027 51                               push   ecx
0x4d1028 50                               push   eax
0x4d1029 e812622d00                       call   0x7a7240
0x4d102e 8b965c010000                     mov    edx,DWORD PTR [esi+0x15c]
0x4d1034 c7823c01000000000000             mov    DWORD PTR [edx+0x13c],0x0
0x4d103e 8bc7                             mov    eax,edi
0x4d1040 5f                               pop    edi
0x4d1041 c3                               ret

; actor_doll_init source=kr-extra-roy/MEF-comprehensive-contracts-20261117/reuse-followup/native-evidence.json blob=c8ec93d4c12340f15bb0753d1d22a004d0cc44b4
; VA 0x4c7df0 raw 0xc71f0 SHA256 12768229bfe6d5625163369f99f708d49ea68c525fb67a4d7bf7cb7882c54199
0x4c7df0 55                               push   ebp
0x4c7df1 8bec                             mov    ebp,esp
0x4c7df3 83e4f8                           and    esp,0xfffffff8
0x4c7df6 6aff                             push   0xffffffff
0x4c7df8 683e969300                       push   0x93963e
0x4c7dfd 64a100000000                     mov    eax,fs:0x0
0x4c7e03 50                               push   eax
0x4c7e04 83ec10                           sub    esp,0x10
0x4c7e07 53                               push   ebx
0x4c7e08 56                               push   esi
0x4c7e09 57                               push   edi
0x4c7e0a a1201fd600                       mov    eax,ds:0xd61f20
0x4c7e0f 33c4                             xor    eax,esp
0x4c7e11 50                               push   eax
0x4c7e12 8d442420                         lea    eax,[esp+0x20]
0x4c7e16 64a300000000                     mov    fs:0x0,eax
0x4c7e1c 8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x4c7e1f 33ff                             xor    edi,edi
0x4c7e21 39bb70030000                     cmp    DWORD PTR [ebx+0x370],edi
0x4c7e27 0f8509020000                     jne    0x4c8036
0x4c7e2d 8b838c000000                     mov    eax,DWORD PTR [ebx+0x8c]
0x4c7e33 8bf0                             mov    esi,eax
0x4c7e35 3bc7                             cmp    eax,edi
0x4c7e37 7506                             jne    0x4c7e3f
0x4c7e39 8bb388000000                     mov    esi,DWORD PTR [ebx+0x88]
0x4c7e3f 6870010000                       push   0x170
0x4c7e44 e81f943c00                       call   0x891268
0x4c7e49 83c404                           add    esp,0x4
0x4c7e4c 89442414                         mov    DWORD PTR [esp+0x14],eax
0x4c7e50 897c2428                         mov    DWORD PTR [esp+0x28],edi
0x4c7e54 3bc7                             cmp    eax,edi
0x4c7e56 740c                             je     0x4c7e64
0x4c7e58 0fb7ce                           movzx  ecx,si
0x4c7e5b 51                               push   ecx
0x4c7e5c 50                               push   eax
0x4c7e5d e8eecd2d00                       call   0x7a4c50
0x4c7e62 eb02                             jmp    0x4c7e66
0x4c7e64 33c0                             xor    eax,eax
0x4c7e66 50                               push   eax
0x4c7e67 8d542418                         lea    edx,[esp+0x18]
0x4c7e6b 83ceff                           or     esi,0xffffffff
0x4c7e6e 8974242c                         mov    DWORD PTR [esp+0x2c],esi
0x4c7e72 52                               push   edx
0x4c7e73 897c241c                         mov    DWORD PTR [esp+0x1c],edi
0x4c7e77 897c2420                         mov    DWORD PTR [esp+0x20],edi
0x4c7e7b e8e0250000                       call   0x4ca460
0x4c7e80 8dbb5c010000                     lea    edi,[ebx+0x15c]
0x4c7e86 8d442414                         lea    eax,[esp+0x14]
0x4c7e8a c744242801000000                 mov    DWORD PTR [esp+0x28],0x1
0x4c7e92 e8c9900100                       call   0x4e0f60
0x4c7e97 89742428                         mov    DWORD PTR [esp+0x28],esi
0x4c7e9b 8b742418                         mov    esi,DWORD PTR [esp+0x18]
0x4c7e9f 85f6                             test   esi,esi
0x4c7ea1 7429                             je     0x4c7ecc
0x4c7ea3 8d4604                           lea    eax,[esi+0x4]
0x4c7ea6 83c9ff                           or     ecx,0xffffffff
0x4c7ea9 f00fc108                         lock xadd DWORD PTR [eax],ecx
0x4c7ead 751d                             jne    0x4c7ecc
0x4c7eaf 8b16                             mov    edx,DWORD PTR [esi]
0x4c7eb1 8b02                             mov    eax,DWORD PTR [edx]
0x4c7eb3 8bce                             mov    ecx,esi
0x4c7eb5 ffd0                             call   eax
0x4c7eb7 8d4e08                           lea    ecx,[esi+0x8]
0x4c7eba 83caff                           or     edx,0xffffffff
0x4c7ebd f00fc111                         lock xadd DWORD PTR [ecx],edx
0x4c7ec1 7509                             jne    0x4c7ecc
0x4c7ec3 8b06                             mov    eax,DWORD PTR [esi]
0x4c7ec5 8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x4c7ec8 8bce                             mov    ecx,esi
0x4c7eca ffd2                             call   edx
0x4c7ecc 0fb78b88030000                   movzx  ecx,WORD PTR [ebx+0x388]
0x4c7ed3 8b07                             mov    eax,DWORD PTR [edi]
0x4c7ed5 51                               push   ecx
0x4c7ed6 6a01                             push   0x1
0x4c7ed8 50                               push   eax
0x4c7ed9 e8c2ef2d00                       call   0x7a6ea0
0x4c7ede 807d0c00                         cmp    BYTE PTR [ebp+0xc],0x0
0x4c7ee2 740e                             je     0x4c7ef2
0x4c7ee4 8b07                             mov    eax,DWORD PTR [edi]
0x4c7ee6 c6402001                         mov    BYTE PTR [eax+0x20],0x1
0x4c7eea 8b07                             mov    eax,DWORD PTR [edi]
0x4c7eec 50                               push   eax
0x4c7eed e87e0f2e00                       call   0x7a8e70
0x4c7ef2 8b13                             mov    edx,DWORD PTR [ebx]
0x4c7ef4 8b5244                           mov    edx,DWORD PTR [edx+0x44]
0x4c7ef7 6a01                             push   0x1
0x4c7ef9 8d83a0000000                     lea    eax,[ebx+0xa0]
0x4c7eff 50                               push   eax
0x4c7f00 8bcb                             mov    ecx,ebx
0x4c7f02 c7837003000001000000             mov    DWORD PTR [ebx+0x370],0x1
0x4c7f0c ffd2                             call   edx
0x4c7f0e 0fb68bb0000000                   movzx  ecx,BYTE PTR [ebx+0xb0]
0x4c7f15 8b03                             mov    eax,DWORD PTR [ebx]
0x4c7f17 8b5058                           mov    edx,DWORD PTR [eax+0x58]
0x4c7f1a 51                               push   ecx
0x4c7f1b 8bcb                             mov    ecx,ebx
0x4c7f1d ffd2                             call   edx
0x4c7f1f 83bba803000000                   cmp    DWORD PTR [ebx+0x3a8],0x0
0x4c7f26 8a83b0000000                     mov    al,BYTE PTR [ebx+0xb0]
0x4c7f2c 88442414                         mov    BYTE PTR [esp+0x14],al
0x4c7f30 752f                             jne    0x4c7f61
0x4c7f32 83bb7003000000                   cmp    DWORD PTR [ebx+0x370],0x0
0x4c7f39 8883a4030000                     mov    BYTE PTR [ebx+0x3a4],al
0x4c7f3f 7420                             je     0x4c7f61
0x4c7f41 8b3f                             mov    edi,DWORD PTR [edi]
0x4c7f43 85ff                             test   edi,edi
0x4c7f45 741a                             je     0x4c7f61
0x4c7f47 8b442414                         mov    eax,DWORD PTR [esp+0x14]
0x4c7f4b 8b7704                           mov    esi,DWORD PTR [edi+0x4]
0x4c7f4e 50                               push   eax
0x4c7f4f e83ccbf7ff                       call   0x444a90
0x4c7f54 8b560c                           mov    edx,DWORD PTR [esi+0xc]
0x4c7f57 8d4f04                           lea    ecx,[edi+0x4]
0x4c7f5a f30f110424                       movss  DWORD PTR [esp],xmm0
0x4c7f5f ffd2                             call   edx
0x4c7f61 8b03                             mov    eax,DWORD PTR [ebx]
0x4c7f63 d983b4000000                     fld    DWORD PTR [ebx+0xb4]
0x4c7f69 8b505c                           mov    edx,DWORD PTR [eax+0x5c]
0x4c7f6c 51                               push   ecx
0x4c7f6d 8bcb                             mov    ecx,ebx
0x4c7f6f d91c24                           fstp   DWORD PTR [esp]
0x4c7f72 ffd2                             call   edx
0x4c7f74 d9e8                             fld1
0x4c7f76 8b03                             mov    eax,DWORD PTR [ebx]
0x4c7f78 8b5068                           mov    edx,DWORD PTR [eax+0x68]
0x4c7f7b 51                               push   ecx
0x4c7f7c 8b8b8c030000                     mov    ecx,DWORD PTR [ebx+0x38c]
0x4c7f82 d91c24                           fstp   DWORD PTR [esp]
0x4c7f85 51                               push   ecx
0x4c7f86 8bcb                             mov    ecx,ebx
0x4c7f88 ffd2                             call   edx
0x4c7f8a 6a30                             push   0x30
0x4c7f8c e8d7923c00                       call   0x891268
0x4c7f91 83c404                           add    esp,0x4
0x4c7f94 89442414                         mov    DWORD PTR [esp+0x14],eax
0x4c7f98 c744242802000000                 mov    DWORD PTR [esp+0x28],0x2
0x4c7fa0 85c0                             test   eax,eax
0x4c7fa2 7409                             je     0x4c7fad
0x4c7fa4 8bf0                             mov    esi,eax
0x4c7fa6 e855c02e00                       call   0x7b4000
0x4c7fab eb02                             jmp    0x4c7faf
0x4c7fad 33c0                             xor    eax,eax
0x4c7faf c7442428ffffffff                 mov    DWORD PTR [esp+0x28],0xffffffff
0x4c7fb7 898368030000                     mov    DWORD PTR [ebx+0x368],eax
0x4c7fbd c7402401000000                   mov    DWORD PTR [eax+0x24],0x1
0x4c7fc4 8b03                             mov    eax,DWORD PTR [ebx]
0x4c7fc6 8b504c                           mov    edx,DWORD PTR [eax+0x4c]
0x4c7fc9 8bcb                             mov    ecx,ebx
0x4c7fcb ffd2                             call   edx
0x4c7fcd 8b08                             mov    ecx,DWORD PTR [eax]
0x4c7fcf 8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x4c7fd2 8b7808                           mov    edi,DWORD PTR [eax+0x8]
0x4c7fd5 8b8368030000                     mov    eax,DWORD PTR [ebx+0x368]
0x4c7fdb f30f10058c5ac500                 movss  xmm0,DWORD PTR ds:0xc55a8c
0x4c7fe3 894810                           mov    DWORD PTR [eax+0x10],ecx
0x4c7fe6 895014                           mov    DWORD PTR [eax+0x14],edx
0x4c7fe9 897818                           mov    DWORD PTR [eax+0x18],edi
0x4c7fec 8b8368030000                     mov    eax,DWORD PTR [ebx+0x368]
0x4c7ff2 f30f11442414                     movss  DWORD PTR [esp+0x14],xmm0
0x4c7ff8 f30f10050858c500                 movss  xmm0,DWORD PTR ds:0xc55808
0x4c8000 8b4c2414                         mov    ecx,DWORD PTR [esp+0x14]
0x4c8004 f30f11442418                     movss  DWORD PTR [esp+0x18],xmm0
0x4c800a 8b542418                         mov    edx,DWORD PTR [esp+0x18]
0x4c800e 89481c                           mov    DWORD PTR [eax+0x1c],ecx
0x4c8011 895020                           mov    DWORD PTR [eax+0x20],edx
0x4c8014 8b9b68030000                     mov    ebx,DWORD PTR [ebx+0x368]
0x4c801a 53                               push   ebx
0x4c801b 8d442414                         lea    eax,[esp+0x14]
0x4c801f c644241400                       mov    BYTE PTR [esp+0x14],0x0
0x4c8024 e8a7ce2e00                       call   0x7b4ed0
0x4c8029 f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
0x4c8031 f30f11400c                       movss  DWORD PTR [eax+0xc],xmm0
0x4c8036 b801000000                       mov    eax,0x1
0x4c803b 8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
0x4c803f 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4c8046 59                               pop    ecx
0x4c8047 5f                               pop    edi
0x4c8048 5e                               pop    esi
0x4c8049 5b                               pop    ebx
0x4c804a 8be5                             mov    esp,ebp
0x4c804c 5d                               pop    ebp
0x4c804d c20800                           ret    0x8

; doll_request source=kr-extra-roy/MEF-comprehensive-contracts-20261117/reuse-followup/native-evidence.json blob=c8ec93d4c12340f15bb0753d1d22a004d0cc44b4
; VA 0x7a8e70 raw 0x3a8270 SHA256 3d628a3d2643d15b529b91e3ad44c6979df144b0edc41c4d30b6be877907892a
0x7a8e70 55                               push   ebp
0x7a8e71 8bec                             mov    ebp,esp
0x7a8e73 83e4f8                           and    esp,0xfffffff8
0x7a8e76 6aff                             push   0xffffffff
0x7a8e78 68fb909300                       push   0x9390fb
0x7a8e7d 64a100000000                     mov    eax,fs:0x0
0x7a8e83 50                               push   eax
0x7a8e84 83ec18                           sub    esp,0x18
0x7a8e87 53                               push   ebx
0x7a8e88 56                               push   esi
0x7a8e89 57                               push   edi
0x7a8e8a a1201fd600                       mov    eax,ds:0xd61f20
0x7a8e8f 33c4                             xor    eax,esp
0x7a8e91 50                               push   eax
0x7a8e92 8d442428                         lea    eax,[esp+0x28]
0x7a8e96 64a300000000                     mov    fs:0x0,eax
0x7a8e9c 8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x7a8e9f 6a74                             push   0x74
0x7a8ea1 e8c2830e00                       call   0x891268
0x7a8ea6 8bf0                             mov    esi,eax
0x7a8ea8 83c404                           add    esp,0x4
0x7a8eab 89742414                         mov    DWORD PTR [esp+0x14],esi
0x7a8eaf 33ff                             xor    edi,edi
0x7a8eb1 897c2430                         mov    DWORD PTR [esp+0x30],edi
0x7a8eb5 3bf7                             cmp    esi,edi
0x7a8eb7 742d                             je     0x7a8ee6
0x7a8eb9 8d4608                           lea    eax,[esi+0x8]
0x7a8ebc 50                               push   eax
0x7a8ebd e85ec1ffff                       call   0x7a5020
0x7a8ec2 8d4e28                           lea    ecx,[esi+0x28]
0x7a8ec5 51                               push   ecx
0x7a8ec6 c644243401                       mov    BYTE PTR [esp+0x34],0x1
0x7a8ecb e850c1ffff                       call   0x7a5020
0x7a8ed0 8d5648                           lea    edx,[esi+0x48]
0x7a8ed3 52                               push   edx
0x7a8ed4 c644243402                       mov    BYTE PTR [esp+0x34],0x2
0x7a8ed9 e842c1ffff                       call   0x7a5020
0x7a8ede 897e68                           mov    DWORD PTR [esi+0x68],edi
0x7a8ee1 897e6c                           mov    DWORD PTR [esi+0x6c],edi
0x7a8ee4 eb02                             jmp    0x7a8ee8
0x7a8ee6 33f6                             xor    esi,esi
0x7a8ee8 56                               push   esi
0x7a8ee9 8d442420                         lea    eax,[esp+0x20]
0x7a8eed c7442434ffffffff                 mov    DWORD PTR [esp+0x34],0xffffffff
0x7a8ef5 50                               push   eax
0x7a8ef6 897c2424                         mov    DWORD PTR [esp+0x24],edi
0x7a8efa 897c2428                         mov    DWORD PTR [esp+0x28],edi
0x7a8efe e80d190000                       call   0x7aa810
0x7a8f03 c744243003000000                 mov    DWORD PTR [esp+0x30],0x3
0x7a8f0b 8b74241c                         mov    esi,DWORD PTR [esp+0x1c]
0x7a8f0f 8b4b18                           mov    ecx,DWORD PTR [ebx+0x18]
0x7a8f12 8d434c                           lea    eax,[ebx+0x4c]
0x7a8f15 8d7e28                           lea    edi,[esi+0x28]
0x7a8f18 890e                             mov    DWORD PTR [esi],ecx
0x7a8f1a 3bf8                             cmp    edi,eax
0x7a8f1c 7421                             je     0x7a8f3f
0x7a8f1e 8b4704                           mov    eax,DWORD PTR [edi+0x4]
0x7a8f21 8b08                             mov    ecx,DWORD PTR [eax]
0x7a8f23 50                               push   eax
0x7a8f24 51                               push   ecx
0x7a8f25 8d74241c                         lea    esi,[esp+0x1c]
0x7a8f29 8bc7                             mov    eax,edi
0x7a8f2b e83012d2ff                       call   0x4ca160
0x7a8f30 8d434c                           lea    eax,[ebx+0x4c]
0x7a8f33 50                               push   eax
0x7a8f34 8bc7                             mov    eax,edi
0x7a8f36 e80586ffff                       call   0x7a1540
0x7a8f3b 8b74241c                         mov    esi,DWORD PTR [esp+0x1c]
0x7a8f3f 8d435c                           lea    eax,[ebx+0x5c]
0x7a8f42 8d7e38                           lea    edi,[esi+0x38]
0x7a8f45 3bf8                             cmp    edi,eax
0x7a8f47 7421                             je     0x7a8f6a
0x7a8f49 8b4704                           mov    eax,DWORD PTR [edi+0x4]
0x7a8f4c 8b08                             mov    ecx,DWORD PTR [eax]
0x7a8f4e 50                               push   eax
0x7a8f4f 51                               push   ecx
0x7a8f50 8d74241c                         lea    esi,[esp+0x1c]
0x7a8f54 8bc7                             mov    eax,edi
0x7a8f56 e8c5e1f2ff                       call   0x6d7120
0x7a8f5b 8d435c                           lea    eax,[ebx+0x5c]
0x7a8f5e 50                               push   eax
0x7a8f5f 8bc7                             mov    eax,edi
0x7a8f61 e8fa86ffff                       call   0x7a1660
0x7a8f66 8b74241c                         mov    esi,DWORD PTR [esp+0x1c]
0x7a8f6a 8d4310                           lea    eax,[ebx+0x10]
0x7a8f6d 8d4c2414                         lea    ecx,[esp+0x14]
0x7a8f71 e81a0e0000                       call   0x7a9d90
0x7a8f76 8d7e68                           lea    edi,[esi+0x68]
0x7a8f79 c644243004                       mov    BYTE PTR [esp+0x30],0x4
0x7a8f7e e8dd7fd3ff                       call   0x4e0f60
0x7a8f83 c644243003                       mov    BYTE PTR [esp+0x30],0x3
0x7a8f88 8b442418                         mov    eax,DWORD PTR [esp+0x18]
0x7a8f8c 85c0                             test   eax,eax
0x7a8f8e 742b                             je     0x7a8fbb
0x7a8f90 8bf0                             mov    esi,eax
0x7a8f92 83c004                           add    eax,0x4
0x7a8f95 83caff                           or     edx,0xffffffff
0x7a8f98 f00fc110                         lock xadd DWORD PTR [eax],edx
0x7a8f9c 751d                             jne    0x7a8fbb
0x7a8f9e 8b06                             mov    eax,DWORD PTR [esi]
0x7a8fa0 8b10                             mov    edx,DWORD PTR [eax]
0x7a8fa2 8bce                             mov    ecx,esi
0x7a8fa4 ffd2                             call   edx
0x7a8fa6 8d4608                           lea    eax,[esi+0x8]
0x7a8fa9 83c9ff                           or     ecx,0xffffffff
0x7a8fac f00fc108                         lock xadd DWORD PTR [eax],ecx
0x7a8fb0 7509                             jne    0x7a8fbb
0x7a8fb2 8b16                             mov    edx,DWORD PTR [esi]
0x7a8fb4 8b4204                           mov    eax,DWORD PTR [edx+0x4]
0x7a8fb7 8bce                             mov    ecx,esi
0x7a8fb9 ffd0                             call   eax
0x7a8fbb 8b74241c                         mov    esi,DWORD PTR [esp+0x1c]
0x7a8fbf 8d4b2c                           lea    ecx,[ebx+0x2c]
0x7a8fc2 51                               push   ecx
0x7a8fc3 8d7e08                           lea    edi,[esi+0x8]
0x7a8fc6 e865c7ffff                       call   0x7a5730
0x7a8fcb 837b2400                         cmp    DWORD PTR [ebx+0x24],0x0
0x7a8fcf 0f94c2                           sete   dl
0x7a8fd2 885604                           mov    BYTE PTR [esi+0x4],dl
0x7a8fd5 807b2000                         cmp    BYTE PTR [ebx+0x20],0x0
0x7a8fd9 7410                             je     0x7a8feb
0x7a8fdb 6a00                             push   0x0
0x7a8fdd 6a00                             push   0x0
0x7a8fdf 6a00                             push   0x0
0x7a8fe1 6a00                             push   0x0
0x7a8fe3 ff15cc20bd00                     call   DWORD PTR ds:0xbd20cc
0x7a8fe9 eb03                             jmp    0x7a8fee
0x7a8feb 83c8ff                           or     eax,0xffffffff
0x7a8fee 8b7c2420                         mov    edi,DWORD PTR [esp+0x20]
0x7a8ff2 894670                           mov    DWORD PTR [esi+0x70],eax
0x7a8ff5 83ec08                           sub    esp,0x8
0x7a8ff8 8bf4                             mov    esi,esp
0x7a8ffa c6432800                         mov    BYTE PTR [ebx+0x28],0x0
0x7a8ffe c7432402000000                   mov    DWORD PTR [ebx+0x24],0x2
0x7a9005 8964241c                         mov    DWORD PTR [esp+0x1c],esp
0x7a9009 c70600000000                     mov    DWORD PTR [esi],0x0
0x7a900f c7460400000000                   mov    DWORD PTR [esi+0x4],0x0
0x7a9016 85ff                             test   edi,edi
0x7a9018 7416                             je     0x7a9030
0x7a901a 8bd7                             mov    edx,edi
0x7a901c e82f32cdff                       call   0x47c250
0x7a9021 84c0                             test   al,al
0x7a9023 740b                             je     0x7a9030
0x7a9025 8b442424                         mov    eax,DWORD PTR [esp+0x24]
0x7a9029 57                               push   edi
0x7a902a 50                               push   eax
0x7a902b e890a1ffff                       call   0x7a31c0
0x7a9030 c644243805                       mov    BYTE PTR [esp+0x38],0x5
0x7a9035 f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
0x7a903c 7523                             jne    0x7a9061
0x7a903e 830d600ffc0001                   or     DWORD PTR ds:0xfc0f60,0x1
0x7a9045 c644243806                       mov    BYTE PTR [esp+0x38],0x6
0x7a904a e8f13effff                       call   0x79cf40
0x7a904f 6880dbbc00                       push   0xbcdb80
0x7a9054 e8c1920e00                       call   0x89231a
0x7a9059 83c404                           add    esp,0x4
0x7a905c c644243805                       mov    BYTE PTR [esp+0x38],0x5
0x7a9061 b9900efc00                       mov    ecx,0xfc0e90
0x7a9066 c644243803                       mov    BYTE PTR [esp+0x38],0x3
0x7a906b e8004affff                       call   0x79da70
0x7a9070 807b2000                         cmp    BYTE PTR [ebx+0x20],0x0
0x7a9074 7427                             je     0x7a909d
0x7a9076 8b74241c                         mov    esi,DWORD PTR [esp+0x1c]
0x7a907a 8b4e70                           mov    ecx,DWORD PTR [esi+0x70]
0x7a907d 6aff                             push   0xffffffff
0x7a907f 51                               push   ecx
0x7a9080 ff15fc20bd00                     call   DWORD PTR ds:0xbd20fc
0x7a9086 8b5670                           mov    edx,DWORD PTR [esi+0x70]
0x7a9089 52                               push   edx
0x7a908a ff15c821bd00                     call   DWORD PTR ds:0xbd21c8
0x7a9090 681cf6c400                       push   0xc4f61c
0x7a9095 e823a00e00                       call   0x8930bd
0x7a909a 83c404                           add    esp,0x4
0x7a909d c7442430ffffffff                 mov    DWORD PTR [esp+0x30],0xffffffff
0x7a90a5 85ff                             test   edi,edi
0x7a90a7 7429                             je     0x7a90d2
0x7a90a9 8d4704                           lea    eax,[edi+0x4]
0x7a90ac 83c9ff                           or     ecx,0xffffffff
0x7a90af f00fc108                         lock xadd DWORD PTR [eax],ecx
0x7a90b3 751d                             jne    0x7a90d2
0x7a90b5 8b17                             mov    edx,DWORD PTR [edi]
0x7a90b7 8b02                             mov    eax,DWORD PTR [edx]
0x7a90b9 8bcf                             mov    ecx,edi
0x7a90bb ffd0                             call   eax
0x7a90bd 8d4f08                           lea    ecx,[edi+0x8]
0x7a90c0 83caff                           or     edx,0xffffffff
0x7a90c3 f00fc111                         lock xadd DWORD PTR [ecx],edx
0x7a90c7 7509                             jne    0x7a90d2
0x7a90c9 8b07                             mov    eax,DWORD PTR [edi]
0x7a90cb 8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x7a90ce 8bcf                             mov    ecx,edi
0x7a90d0 ffd2                             call   edx
0x7a90d2 8b4c2428                         mov    ecx,DWORD PTR [esp+0x28]
0x7a90d6 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x7a90dd 59                               pop    ecx
0x7a90de 5f                               pop    edi
0x7a90df 5e                               pop    esi
0x7a90e0 5b                               pop    ebx
0x7a90e1 8be5                             mov    esp,ebp
0x7a90e3 5d                               pop    ebp
0x7a90e4 c20400                           ret    0x4

; flying_fade_constructor source=kr-extra-roy/MEF-control-flow-20261116/world/native-windows.json blob=dd8fe112221a3fe3cfa89119eedcd77089a43210
; VA 0x553e90 raw 0x153290 SHA256 c28e38c3fad65e45c323c56c3bf222de83e0f8e0cacb2206b187751be51e4cd1
0x553e90 55                               push   ebp
0x553e91 8bec                             mov    ebp,esp
0x553e93 6aff                             push   0xffffffff
0x553e95 68086d9100                       push   0x916d08
0x553e9a 64a100000000                     mov    eax,fs:0x0
0x553ea0 50                               push   eax
0x553ea1 53                               push   ebx
0x553ea2 56                               push   esi
0x553ea3 57                               push   edi
0x553ea4 a1201fd600                       mov    eax,ds:0xd61f20
0x553ea9 33c5                             xor    eax,ebp
0x553eab 50                               push   eax
0x553eac 8d45f4                           lea    eax,[ebp-0xc]
0x553eaf 64a300000000                     mov    fs:0x0,eax
0x553eb5 8b4510                           mov    eax,DWORD PTR [ebp+0x10]
0x553eb8 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x553ebb 33db                             xor    ebx,ebx
0x553ebd 894e1c                           mov    DWORD PTR [esi+0x1c],ecx
0x553ec0 894620                           mov    DWORD PTR [esi+0x20],eax
0x553ec3 894e28                           mov    DWORD PTR [esi+0x28],ecx
0x553ec6 8b4d14                           mov    ecx,DWORD PTR [ebp+0x14]
0x553ec9 89462c                           mov    DWORD PTR [esi+0x2c],eax
0x553ecc 8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x553ecf 895e04                           mov    DWORD PTR [esi+0x4],ebx
0x553ed2 895e08                           mov    DWORD PTR [esi+0x8],ebx
0x553ed5 895e24                           mov    DWORD PTR [esi+0x24],ebx
0x553ed8 894630                           mov    DWORD PTR [esi+0x30],eax
0x553edb 895e34                           mov    DWORD PTR [esi+0x34],ebx
0x553ede 885e38                           mov    BYTE PTR [esi+0x38],bl
0x553ee1 894e3c                           mov    DWORD PTR [esi+0x3c],ecx
0x553ee4 895e10                           mov    DWORD PTR [esi+0x10],ebx
0x553ee7 895e0c                           mov    DWORD PTR [esi+0xc],ebx
0x553eea c7461401000000                   mov    DWORD PTR [esi+0x14],0x1
0x553ef1 895e18                           mov    DWORD PTR [esi+0x18],ebx
0x553ef4 895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x553ef7 c70694ffc000                     mov    DWORD PTR [esi],0xc0ff94
0x553efd 895e44                           mov    DWORD PTR [esi+0x44],ebx
0x553f00 8bc2                             mov    eax,edx
0x553f02 8d4801                           lea    ecx,[eax+0x1]
0x553f05 c7465c0f000000                   mov    DWORD PTR [esi+0x5c],0xf
0x553f0c 895e58                           mov    DWORD PTR [esi+0x58],ebx
0x553f0f 885e48                           mov    BYTE PTR [esi+0x48],bl
0x553f12 894d10                           mov    DWORD PTR [ebp+0x10],ecx
0x553f15 8a08                             mov    cl,BYTE PTR [eax]
0x553f17 40                               inc    eax
0x553f18 3acb                             cmp    cl,bl
0x553f1a 75f9                             jne    0x553f15
0x553f1c 2b4510                           sub    eax,DWORD PTR [ebp+0x10]
0x553f1f 8d4e48                           lea    ecx,[esi+0x48]
0x553f22 50                               push   eax
0x553f23 52                               push   edx
0x553f24 e847ebeaff                       call   0x402a70
0x553f29 895e64                           mov    DWORD PTR [esi+0x64],ebx
0x553f2c 8bc6                             mov    eax,esi
0x553f2e 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x553f31 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x553f38 59                               pop    ecx
0x553f39 5f                               pop    edi
0x553f3a 5e                               pop    esi
0x553f3b 5b                               pop    ebx
0x553f3c 8be5                             mov    esp,ebp
0x553f3e 5d                               pop    ebp
0x553f3f c21000                           ret    0x10

; flying_image_load source=kr-extra-roy/MEF-control-flow-20261116/world/native-windows.json blob=dd8fe112221a3fe3cfa89119eedcd77089a43210
; VA 0x560030 raw 0x15f430 SHA256 ae9f97be596e208633867ffc9a1e114902f329a6297849480ad7b14995e1e9f8
0x560030 56                               push   esi
0x560031 57                               push   edi
0x560032 8bf9                             mov    edi,ecx
0x560034 8b4f44                           mov    ecx,DWORD PTR [edi+0x44]
0x560037 85c9                             test   ecx,ecx
0x560039 740e                             je     0x560049
0x56003b 8b01                             mov    eax,DWORD PTR [ecx]
0x56003d 8b5008                           mov    edx,DWORD PTR [eax+0x8]
0x560040 ffd2                             call   edx
0x560042 c7474400000000                   mov    DWORD PTR [edi+0x44],0x0
0x560049 837f5c10                         cmp    DWORD PTR [edi+0x5c],0x10
0x56004d 8d7748                           lea    esi,[edi+0x48]
0x560050 7204                             jb     0x560056
0x560052 8b06                             mov    eax,DWORD PTR [esi]
0x560054 eb02                             jmp    0x560058
0x560056 8bc6                             mov    eax,esi
0x560058 6a00                             push   0x0
0x56005a 50                               push   eax
0x56005b e8d0421d00                       call   0x734330
0x560060 83c408                           add    esp,0x8
0x560063 894744                           mov    DWORD PTR [edi+0x44],eax
0x560066 85c0                             test   eax,eax
0x560068 7516                             jne    0x560080
0x56006a 837e1410                         cmp    DWORD PTR [esi+0x14],0x10
0x56006e 7202                             jb     0x560072
0x560070 8b36                             mov    esi,DWORD PTR [esi]
0x560072 56                               push   esi
0x560073 682406c100                       push   0xc10624
0x560078 e8e3da1800                       call   0x6edb60
0x56007d 83c408                           add    esp,0x8
0x560080 c7473401000000                   mov    DWORD PTR [edi+0x34],0x1
0x560087 5f                               pop    edi
0x560088 5e                               pop    esi
0x560089 c3                               ret

; flying_lifecycle source=kr-extra-roy/MEF-feature-lifecycle-20261117/native-evidence.json blob=03e80e0da3df16cad5bba9eea6feb383dca64bf6
; VA 0x553b60 raw 0x152f60 SHA256 27d597aea61b31b92ff5be5a204e4a3dd972412b6ebec11ca21630cfbac5309e
0x553b60 55                               push   ebp
0x553b61 8bec                             mov    ebp,esp
0x553b63 8b4134                           mov    eax,DWORD PTR [ecx+0x34]
0x553b66 83ec08                           sub    esp,0x8
0x553b69 83f804                           cmp    eax,0x4
0x553b6c 0f87da000000                     ja     0x553c4c
0x553b72 ff2485503c5500                   jmp    DWORD PTR [eax*4+0x553c50]
0x553b79 c7411400000000                   mov    DWORD PTR [ecx+0x14],0x0
0x553b80 8be5                             mov    esp,ebp
0x553b82 5d                               pop    ebp
0x553b83 c3                               ret
0x553b84 8b4124                           mov    eax,DWORD PTR [ecx+0x24]
0x553b87 85c0                             test   eax,eax
0x553b89 7e08                             jle    0x553b93
0x553b8b 48                               dec    eax
0x553b8c 894124                           mov    DWORD PTR [ecx+0x24],eax
0x553b8f 8be5                             mov    esp,ebp
0x553b91 5d                               pop    ebp
0x553b92 c3                               ret
0x553b93 c7413402000000                   mov    DWORD PTR [ecx+0x34],0x2
0x553b9a 8b4128                           mov    eax,DWORD PTR [ecx+0x28]
0x553b9d 85c0                             test   eax,eax
0x553b9f 7e39                             jle    0x553bda
0x553ba1 48                               dec    eax
0x553ba2 8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x553ba5 db45fc                           fild   DWORD PTR [ebp-0x4]
0x553ba8 894128                           mov    DWORD PTR [ecx+0x28],eax
0x553bab d97dfe                           fnstcw WORD PTR [ebp-0x2]
0x553bae da711c                           fidiv  DWORD PTR [ecx+0x1c]
0x553bb1 0fb745fe                         movzx  eax,WORD PTR [ebp-0x2]
0x553bb5 0d000c0000                       or     eax,0xc00
0x553bba 8945f8                           mov    DWORD PTR [ebp-0x8],eax
0x553bbd dd058856c500                     fld    QWORD PTR ds:0xc55688
0x553bc3 dcc9                             fmul   st(1),st
0x553bc5 dee1                             fsubrp st(1),st
0x553bc7 d96df8                           fldcw  WORD PTR [ebp-0x8]
0x553bca db5df8                           fistp  DWORD PTR [ebp-0x8]
0x553bcd 8a45f8                           mov    al,BYTE PTR [ebp-0x8]
0x553bd0 884138                           mov    BYTE PTR [ecx+0x38],al
0x553bd3 d96dfe                           fldcw  WORD PTR [ebp-0x2]
0x553bd6 8be5                             mov    esp,ebp
0x553bd8 5d                               pop    ebp
0x553bd9 c3                               ret
0x553bda c64138ff                         mov    BYTE PTR [ecx+0x38],0xff
0x553bde c7413403000000                   mov    DWORD PTR [ecx+0x34],0x3
0x553be5 8be5                             mov    esp,ebp
0x553be7 5d                               pop    ebp
0x553be8 c3                               ret
0x553be9 8b4130                           mov    eax,DWORD PTR [ecx+0x30]
0x553bec 85c0                             test   eax,eax
0x553bee 7e08                             jle    0x553bf8
0x553bf0 48                               dec    eax
0x553bf1 894130                           mov    DWORD PTR [ecx+0x30],eax
0x553bf4 8be5                             mov    esp,ebp
0x553bf6 5d                               pop    ebp
0x553bf7 c3                               ret
0x553bf8 7552                             jne    0x553c4c
0x553bfa c7413404000000                   mov    DWORD PTR [ecx+0x34],0x4
0x553c01 8be5                             mov    esp,ebp
0x553c03 5d                               pop    ebp
0x553c04 c3                               ret
0x553c05 8b412c                           mov    eax,DWORD PTR [ecx+0x2c]
0x553c08 85c0                             test   eax,eax
0x553c0a 7e35                             jle    0x553c41
0x553c0c 48                               dec    eax
0x553c0d d97dfe                           fnstcw WORD PTR [ebp-0x2]
0x553c10 8945f8                           mov    DWORD PTR [ebp-0x8],eax
0x553c13 db45f8                           fild   DWORD PTR [ebp-0x8]
0x553c16 89412c                           mov    DWORD PTR [ecx+0x2c],eax
0x553c19 0fb745fe                         movzx  eax,WORD PTR [ebp-0x2]
0x553c1d 0d000c0000                       or     eax,0xc00
0x553c22 da7120                           fidiv  DWORD PTR [ecx+0x20]
0x553c25 8945f8                           mov    DWORD PTR [ebp-0x8],eax
0x553c28 dc0d8856c500                     fmul   QWORD PTR ds:0xc55688
0x553c2e d96df8                           fldcw  WORD PTR [ebp-0x8]
0x553c31 db5df8                           fistp  DWORD PTR [ebp-0x8]
0x553c34 8a55f8                           mov    dl,BYTE PTR [ebp-0x8]
0x553c37 885138                           mov    BYTE PTR [ecx+0x38],dl
0x553c3a d96dfe                           fldcw  WORD PTR [ebp-0x2]
0x553c3d 8be5                             mov    esp,ebp
0x553c3f 5d                               pop    ebp
0x553c40 c3                               ret
0x553c41 c6413800                         mov    BYTE PTR [ecx+0x38],0x0
0x553c45 c7413400000000                   mov    DWORD PTR [ecx+0x34],0x0
0x553c4c 8be5                             mov    esp,ebp
0x553c4e 5d                               pop    ebp
0x553c4f c3                               ret

; flying_manager_tick source=kr-extra-roy/MEF-feature-lifecycle-20261117/native-evidence.json blob=03e80e0da3df16cad5bba9eea6feb383dca64bf6
; VA 0x5537f0 raw 0x152bf0 SHA256 4e325989863bc8a60288bc728364ee33ea7be8ce0141af7980c0c37043119bdb
0x5537f0 55                               push   ebp
0x5537f1 8bec                             mov    ebp,esp
0x5537f3 83ec10                           sub    esp,0x10
0x5537f6 53                               push   ebx
0x5537f7 56                               push   esi
0x5537f8 33c0                             xor    eax,eax
0x5537fa 57                               push   edi
0x5537fb 33db                             xor    ebx,ebx
0x5537fd eb03                             jmp    0x553802
0x5537ff 90                               nop
0x553800 33c0                             xor    eax,eax
0x553802 8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x553805 8945f4                           mov    DWORD PTR [ebp-0xc],eax
0x553808 8945f8                           mov    DWORD PTR [ebp-0x8],eax
0x55380b b901000000                       mov    ecx,0x1
0x553810 3bd8                             cmp    ebx,eax
0x553812 7e09                             jle    0x55381d
0x553814 39449f40                         cmp    DWORD PTR [edi+ebx*4+0x40],eax
0x553818 7403                             je     0x55381d
0x55381a 894df4                           mov    DWORD PTR [ebp-0xc],ecx
0x55381d 8bd3                             mov    edx,ebx
0x55381f c1e204                           shl    edx,0x4
0x553822 8b443a04                         mov    eax,DWORD PTR [edx+edi*1+0x4]
0x553826 8b30                             mov    esi,DWORD PTR [eax]
0x553828 03d7                             add    edx,edi
0x55382a 8955fc                           mov    DWORD PTR [ebp-0x4],edx
0x55382d 3bf0                             cmp    esi,eax
0x55382f 0f84d3000000                     je     0x553908
0x553835 eb0e                             jmp    0x553845
0x553837 eb07                             jmp    0x553840
0x553839 8da42400000000                   lea    esp,[esp+0x0]
0x553840 b901000000                       mov    ecx,0x1
0x553845 8b5204                           mov    edx,DWORD PTR [edx+0x4]
0x553848 8b02                             mov    eax,DWORD PTR [edx]
0x55384a 8b7e10                           mov    edi,DWORD PTR [esi+0x10]
0x55384d 3bf0                             cmp    esi,eax
0x55384f 7415                             je     0x553866
0x553851 8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x553854 83783c00                         cmp    DWORD PTR [eax+0x3c],0x0
0x553858 7503                             jne    0x55385d
0x55385a 894df8                           mov    DWORD PTR [ebp-0x8],ecx
0x55385d 837f3c00                         cmp    DWORD PTR [edi+0x3c],0x0
0x553861 7503                             jne    0x553866
0x553863 894df8                           mov    DWORD PTR [ebp-0x8],ecx
0x553866 837df400                         cmp    DWORD PTR [ebp-0xc],0x0
0x55386a 7506                             jne    0x553872
0x55386c 837df800                         cmp    DWORD PTR [ebp-0x8],0x0
0x553870 7403                             je     0x553875
0x553872 014f24                           add    DWORD PTR [edi+0x24],ecx
0x553875 8b17                             mov    edx,DWORD PTR [edi]
0x553877 8b4214                           mov    eax,DWORD PTR [edx+0x14]
0x55387a 8bcf                             mov    ecx,edi
0x55387c ffd0                             call   eax
0x55387e 8b17                             mov    edx,DWORD PTR [edi]
0x553880 8b4224                           mov    eax,DWORD PTR [edx+0x24]
0x553883 8bcf                             mov    ecx,edi
0x553885 ffd0                             call   eax
0x553887 85c0                             test   eax,eax
0x553889 7525                             jne    0x5538b0
0x55388b 8b17                             mov    edx,DWORD PTR [edi]
0x55388d 8b4208                           mov    eax,DWORD PTR [edx+0x8]
0x553890 8bcf                             mov    ecx,edi
0x553892 ffd0                             call   eax
0x553894 8b17                             mov    edx,DWORD PTR [edi]
0x553896 8b02                             mov    eax,DWORD PTR [edx]
0x553898 6a01                             push   0x1
0x55389a 8bcf                             mov    ecx,edi
0x55389c ffd0                             call   eax
0x55389e 8b55fc                           mov    edx,DWORD PTR [ebp-0x4]
0x5538a1 56                               push   esi
0x5538a2 8d4df0                           lea    ecx,[ebp-0x10]
0x5538a5 51                               push   ecx
0x5538a6 52                               push   edx
0x5538a7 e8e42f2600                       call   0x7b6890
0x5538ac 8b30                             mov    esi,DWORD PTR [eax]
0x5538ae eb47                             jmp    0x5538f7
0x5538b0 807e1500                         cmp    BYTE PTR [esi+0x15],0x0
0x5538b4 7541                             jne    0x5538f7
0x5538b6 8b4608                           mov    eax,DWORD PTR [esi+0x8]
0x5538b9 80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x5538bd 751d                             jne    0x5538dc
0x5538bf 8bf0                             mov    esi,eax
0x5538c1 8b06                             mov    eax,DWORD PTR [esi]
0x5538c3 80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x5538c7 752e                             jne    0x5538f7
0x5538c9 8da42400000000                   lea    esp,[esp+0x0]
0x5538d0 8bf0                             mov    esi,eax
0x5538d2 8b06                             mov    eax,DWORD PTR [esi]
0x5538d4 80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x5538d8 74f6                             je     0x5538d0
0x5538da eb1b                             jmp    0x5538f7
0x5538dc 8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x5538df 80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x5538e3 7510                             jne    0x5538f5
0x5538e5 3b7008                           cmp    esi,DWORD PTR [eax+0x8]
0x5538e8 750b                             jne    0x5538f5
0x5538ea 8bf0                             mov    esi,eax
0x5538ec 8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x5538ef 80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x5538f3 74f0                             je     0x5538e5
0x5538f5 8bf0                             mov    esi,eax
0x5538f7 8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x5538fa 8bd0                             mov    edx,eax
0x5538fc 3b7004                           cmp    esi,DWORD PTR [eax+0x4]
0x5538ff 0f853bffffff                     jne    0x553840
0x553905 8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x553908 85db                             test   ebx,ebx
0x55390a 7504                             jne    0x553910
0x55390c 33c0                             xor    eax,eax
0x55390e eb04                             jmp    0x553914
0x553910 8b449f40                         mov    eax,DWORD PTR [edi+ebx*4+0x40]
0x553914 89449f44                         mov    DWORD PTR [edi+ebx*4+0x44],eax
0x553918 8b4204                           mov    eax,DWORD PTR [edx+0x4]
0x55391b 8b08                             mov    ecx,DWORD PTR [eax]
0x55391d 3bc8                             cmp    ecx,eax
0x55391f 7456                             je     0x553977
0x553921 8b4110                           mov    eax,DWORD PTR [ecx+0x10]
0x553924 83783404                         cmp    DWORD PTR [eax+0x34],0x4
0x553928 7d04                             jge    0x55392e
0x55392a ff449f44                         inc    DWORD PTR [edi+ebx*4+0x44]
0x55392e 80791500                         cmp    BYTE PTR [ecx+0x15],0x0
0x553932 753e                             jne    0x553972
0x553934 8b4108                           mov    eax,DWORD PTR [ecx+0x8]
0x553937 80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x55393b 7516                             jne    0x553953
0x55393d 8bc8                             mov    ecx,eax
0x55393f 8b01                             mov    eax,DWORD PTR [ecx]
0x553941 80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x553945 752b                             jne    0x553972
0x553947 8bc8                             mov    ecx,eax
0x553949 8b01                             mov    eax,DWORD PTR [ecx]
0x55394b 80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x55394f 74f6                             je     0x553947
0x553951 eb1f                             jmp    0x553972
0x553953 8b4104                           mov    eax,DWORD PTR [ecx+0x4]
0x553956 80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x55395a 7514                             jne    0x553970
0x55395c 8d642400                         lea    esp,[esp+0x0]
0x553960 3b4808                           cmp    ecx,DWORD PTR [eax+0x8]
0x553963 750b                             jne    0x553970
0x553965 8bc8                             mov    ecx,eax
0x553967 8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x55396a 80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x55396e 74f0                             je     0x553960
0x553970 8bc8                             mov    ecx,eax
0x553972 3b4a04                           cmp    ecx,DWORD PTR [edx+0x4]
0x553975 75aa                             jne    0x553921
0x553977 8b4a08                           mov    ecx,DWORD PTR [edx+0x8]
0x55397a 014c9f44                         add    DWORD PTR [edi+ebx*4+0x44],ecx
0x55397e 43                               inc    ebx
0x55397f 83fb04                           cmp    ebx,0x4
0x553982 0f8c78feffff                     jl     0x553800
0x553988 5f                               pop    edi
0x553989 5e                               pop    esi
0x55398a 5b                               pop    ebx
0x55398b 8be5                             mov    esp,ebp
0x55398d 5d                               pop    ebp
0x55398e c20400                           ret    0x4

; flying_alive source=kr-extra-roy/MEF-feature-lifecycle-20261117/native-evidence.json blob=03e80e0da3df16cad5bba9eea6feb383dca64bf6
; VA 0x80f010 raw 0x40e410 SHA256 01d3abacb68aac3537badfe563d0e21d0244fb61db1d805bcef8f455407fad96
0x80f010 8b4114                           mov    eax,DWORD PTR [ecx+0x14]
0x80f013 c3                               ret

; flying_release source=kr-extra-roy/MEF-feature-lifecycle-20261117/native-evidence.json blob=03e80e0da3df16cad5bba9eea6feb383dca64bf6
; VA 0x553de0 raw 0x1531e0 SHA256 ec2c067f34a2e5871b1eae876a76e5f8afbb765316c8f1d0d495f387898cdc61
0x553de0 56                               push   esi
0x553de1 8bf1                             mov    esi,ecx
0x553de3 8b4e44                           mov    ecx,DWORD PTR [esi+0x44]
0x553de6 85c9                             test   ecx,ecx
0x553de8 740e                             je     0x553df8
0x553dea 8b01                             mov    eax,DWORD PTR [ecx]
0x553dec 8b5008                           mov    edx,DWORD PTR [eax+0x8]
0x553def ffd2                             call   edx
0x553df1 c7464400000000                   mov    DWORD PTR [esi+0x44],0x0
0x553df8 5e                               pop    esi
0x553df9 c3                               ret

; flying_deleting_dtor source=kr-extra-roy/MEF-feature-lifecycle-20261117/native-evidence.json blob=03e80e0da3df16cad5bba9eea6feb383dca64bf6
; VA 0x553e40 raw 0x153240 SHA256 a682e3a86980b9950b07f8390692e231d76b0a294e8b9b343c8074fe8f820aa5
0x553e40 55                               push   ebp
0x553e41 8bec                             mov    ebp,esp
0x553e43 56                               push   esi
0x553e44 8bf1                             mov    esi,ecx
0x553e46 c70694ffc000                     mov    DWORD PTR [esi],0xc0ff94
0x553e4c 837e5c10                         cmp    DWORD PTR [esi+0x5c],0x10
0x553e50 720c                             jb     0x553e5e
0x553e52 8b4648                           mov    eax,DWORD PTR [esi+0x48]
0x553e55 50                               push   eax
0x553e56 e8b1d33300                       call   0x89120c
0x553e5b 83c404                           add    esp,0x4
0x553e5e 33c0                             xor    eax,eax
0x553e60 f6450801                         test   BYTE PTR [ebp+0x8],0x1
0x553e64 c7465c0f000000                   mov    DWORD PTR [esi+0x5c],0xf
0x553e6b 894658                           mov    DWORD PTR [esi+0x58],eax
0x553e6e 884648                           mov    BYTE PTR [esi+0x48],al
0x553e71 c70634ffc000                     mov    DWORD PTR [esi],0xc0ff34
0x553e77 7409                             je     0x553e82
0x553e79 56                               push   esi
0x553e7a e88dd33300                       call   0x89120c
0x553e7f 83c404                           add    esp,0x4
0x553e82 8bc6                             mov    eax,esi
0x553e84 5e                               pop    esi
0x553e85 5d                               pop    ebp
0x553e86 c20400                           ret    0x4

; N01_doll_release_before_actor_delete source=kr-extra-roy/MEF-P0-content-contracts-20261117/execution-lifecycle/native-evidence.json blob=533c3b8a7bd9cbd06be539978fc7b2475ee41d06
; VA 0x7a57c0 raw 0x3a4bc0 SHA256 f9d757cc0ca25f42931c4e7f2b6d8da04ef16d43ec96cd62650b53d41354684b
0x7a57c0 55                               push   ebp
0x7a57c1 8bec                             mov    ebp,esp
0x7a57c3 83e4f8                           and    esp,0xfffffff8
0x7a57c6 6aff                             push   0xffffffff
0x7a57c8 68a9919300                       push   0x9391a9
0x7a57cd 64a100000000                     mov    eax,fs:0x0
0x7a57d3 50                               push   eax
0x7a57d4 83ec18                           sub    esp,0x18
0x7a57d7 53                               push   ebx
0x7a57d8 56                               push   esi
0x7a57d9 57                               push   edi
0x7a57da a1201fd600                       mov    eax,ds:0xd61f20
0x7a57df 33c4                             xor    eax,esp
0x7a57e1 50                               push   eax
0x7a57e2 8d442428                         lea    eax,[esp+0x28]
0x7a57e6 64a300000000                     mov    fs:0x0,eax
0x7a57ec 8bd9                             mov    ebx,ecx
0x7a57ee 8b8b18010000                     mov    ecx,DWORD PTR [ebx+0x118]
0x7a57f4 33ff                             xor    edi,edi
0x7a57f6 3bcf                             cmp    ecx,edi
0x7a57f8 740d                             je     0x7a5807
0x7a57fa 8b01                             mov    eax,DWORD PTR [ecx]
0x7a57fc 8b5008                           mov    edx,DWORD PTR [eax+0x8]
0x7a57ff ffd2                             call   edx
0x7a5801 89bb18010000                     mov    DWORD PTR [ebx+0x118],edi
0x7a5807 be01000000                       mov    esi,0x1
0x7a580c 39731c                           cmp    DWORD PTR [ebx+0x1c],esi
0x7a580f 0f8568010000                     jne    0x7a597d
0x7a5815 6a38                             push   0x38
0x7a5817 e84cba0e00                       call   0x891268
0x7a581c 83c404                           add    esp,0x4
0x7a581f 89442420                         mov    DWORD PTR [esp+0x20],eax
0x7a5823 897c2430                         mov    DWORD PTR [esp+0x30],edi
0x7a5827 3bc7                             cmp    eax,edi
0x7a5829 7408                             je     0x7a5833
0x7a582b 50                               push   eax
0x7a582c e84ffeffff                       call   0x7a5680
0x7a5831 eb02                             jmp    0x7a5835
0x7a5833 33c0                             xor    eax,eax
0x7a5835 50                               push   eax
0x7a5836 8d44241c                         lea    eax,[esp+0x1c]
0x7a583a c7442434ffffffff                 mov    DWORD PTR [esp+0x34],0xffffffff
0x7a5842 50                               push   eax
0x7a5843 897c2420                         mov    DWORD PTR [esp+0x20],edi
0x7a5847 897c2424                         mov    DWORD PTR [esp+0x24],edi
0x7a584b e8304f0000                       call   0x7aa780
0x7a5850 89742430                         mov    DWORD PTR [esp+0x30],esi
0x7a5854 8b742418                         mov    esi,DWORD PTR [esp+0x18]
0x7a5858 8b4b10                           mov    ecx,DWORD PTR [ebx+0x10]
0x7a585b 8d5324                           lea    edx,[ebx+0x24]
0x7a585e 52                               push   edx
0x7a585f 8d7e08                           lea    edi,[esi+0x8]
0x7a5862 890e                             mov    DWORD PTR [esi],ecx
0x7a5864 e8c7feffff                       call   0x7a5730
0x7a5869 8b4314                           mov    eax,DWORD PTR [ebx+0x14]
0x7a586c 894604                           mov    DWORD PTR [esi+0x4],eax
0x7a586f 8d4364                           lea    eax,[ebx+0x64]
0x7a5872 8d7e28                           lea    edi,[esi+0x28]
0x7a5875 3bf8                             cmp    edi,eax
0x7a5877 7421                             je     0x7a589a
0x7a5879 8b4704                           mov    eax,DWORD PTR [edi+0x4]
0x7a587c 8b08                             mov    ecx,DWORD PTR [eax]
0x7a587e 50                               push   eax
0x7a587f 51                               push   ecx
0x7a5880 8d742428                         lea    esi,[esp+0x28]
0x7a5884 8bc7                             mov    eax,edi
0x7a5886 e89518f3ff                       call   0x6d7120
0x7a588b 8d4364                           lea    eax,[ebx+0x64]
0x7a588e 50                               push   eax
0x7a588f 8bc7                             mov    eax,edi
0x7a5891 e8ba480000                       call   0x7aa150
0x7a5896 8b742418                         mov    esi,DWORD PTR [esp+0x18]
0x7a589a 8b54241c                         mov    edx,DWORD PTR [esp+0x1c]
0x7a589e 83ec08                           sub    esp,0x8
0x7a58a1 8bfc                             mov    edi,esp
0x7a58a3 89642428                         mov    DWORD PTR [esp+0x28],esp
0x7a58a7 c70700000000                     mov    DWORD PTR [edi],0x0
0x7a58ad c7470400000000                   mov    DWORD PTR [edi+0x4],0x0
0x7a58b4 85d2                             test   edx,edx
0x7a58b6 7416                             je     0x7a58ce
0x7a58b8 e89369cdff                       call   0x47c250
0x7a58bd 84c0                             test   al,al
0x7a58bf 740d                             je     0x7a58ce
0x7a58c1 8b4c2424                         mov    ecx,DWORD PTR [esp+0x24]
0x7a58c5 51                               push   ecx
0x7a58c6 56                               push   esi
0x7a58c7 8bf7                             mov    esi,edi
0x7a58c9 e8f2d8ffff                       call   0x7a31c0
0x7a58ce c644243802                       mov    BYTE PTR [esp+0x38],0x2
0x7a58d3 f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
0x7a58da 7523                             jne    0x7a58ff
0x7a58dc 830d600ffc0001                   or     DWORD PTR ds:0xfc0f60,0x1
0x7a58e3 c644243803                       mov    BYTE PTR [esp+0x38],0x3
0x7a58e8 e85376ffff                       call   0x79cf40
0x7a58ed 6880dbbc00                       push   0xbcdb80
0x7a58f2 e823ca0e00                       call   0x89231a
0x7a58f7 83c404                           add    esp,0x4
0x7a58fa c644243802                       mov    BYTE PTR [esp+0x38],0x2
0x7a58ff b9900efc00                       mov    ecx,0xfc0e90
0x7a5904 c644243801                       mov    BYTE PTR [esp+0x38],0x1
0x7a5909 e8f284ffff                       call   0x79de00
0x7a590e 8d7b64                           lea    edi,[ebx+0x64]
0x7a5911 c7431400000000                   mov    DWORD PTR [ebx+0x14],0x0
0x7a5918 e85322dfff                       call   0x597b70
0x7a591d 8b8398000000                     mov    eax,DWORD PTR [ebx+0x98]
0x7a5923 33ff                             xor    edi,edi
0x7a5925 3bc7                             cmp    eax,edi
0x7a5927 7414                             je     0x7a593d
0x7a5929 8b08                             mov    ecx,DWORD PTR [eax]
0x7a592b ff492c                           dec    DWORD PTR [ecx+0x2c]
0x7a592e 50                               push   eax
0x7a592f e8d8b80e00                       call   0x89120c
0x7a5934 83c404                           add    esp,0x4
0x7a5937 89bb98000000                     mov    DWORD PTR [ebx+0x98],edi
0x7a593d c7442430ffffffff                 mov    DWORD PTR [esp+0x30],0xffffffff
0x7a5945 8b74241c                         mov    esi,DWORD PTR [esp+0x1c]
0x7a5949 897b1c                           mov    DWORD PTR [ebx+0x1c],edi
0x7a594c c6432001                         mov    BYTE PTR [ebx+0x20],0x1
0x7a5950 3bf7                             cmp    esi,edi
0x7a5952 7429                             je     0x7a597d
0x7a5954 8d5604                           lea    edx,[esi+0x4]
0x7a5957 83c8ff                           or     eax,0xffffffff
0x7a595a f00fc102                         lock xadd DWORD PTR [edx],eax
0x7a595e 751d                             jne    0x7a597d
0x7a5960 8b16                             mov    edx,DWORD PTR [esi]
0x7a5962 8b02                             mov    eax,DWORD PTR [edx]
0x7a5964 8bce                             mov    ecx,esi
0x7a5966 ffd0                             call   eax
0x7a5968 8d4e08                           lea    ecx,[esi+0x8]
0x7a596b 83caff                           or     edx,0xffffffff
0x7a596e f00fc111                         lock xadd DWORD PTR [ecx],edx
0x7a5972 7509                             jne    0x7a597d
0x7a5974 8b06                             mov    eax,DWORD PTR [esi]
0x7a5976 8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x7a5979 8bce                             mov    ecx,esi
0x7a597b ffd2                             call   edx
0x7a597d 8b8348010000                     mov    eax,DWORD PTR [ebx+0x148]
0x7a5983 2b8344010000                     sub    eax,DWORD PTR [ebx+0x144]
0x7a5989 33f6                             xor    esi,esi
0x7a598b c1f803                           sar    eax,0x3
0x7a598e 85c0                             test   eax,eax
0x7a5990 743f                             je     0x7a59d1
0x7a5992 8b8b44010000                     mov    ecx,DWORD PTR [ebx+0x144]
0x7a5998 8b7cf104                         mov    edi,DWORD PTR [ecx+esi*8+0x4]
0x7a599c 85ff                             test   edi,edi
0x7a599e 741d                             je     0x7a59bd
0x7a59a0 57                               push   edi
0x7a59a1 e8ea2e0300                       call   0x7d8890
0x7a59a6 57                               push   edi
0x7a59a7 e860b80e00                       call   0x89120c
0x7a59ac 8b9344010000                     mov    edx,DWORD PTR [ebx+0x144]
0x7a59b2 83c404                           add    esp,0x4
0x7a59b5 c744f20400000000                 mov    DWORD PTR [edx+esi*8+0x4],0x0
0x7a59bd 8b8348010000                     mov    eax,DWORD PTR [ebx+0x148]
0x7a59c3 2b8344010000                     sub    eax,DWORD PTR [ebx+0x144]
0x7a59c9 46                               inc    esi
0x7a59ca c1f803                           sar    eax,0x3
0x7a59cd 3bf0                             cmp    esi,eax
0x7a59cf 72c1                             jb     0x7a5992
0x7a59d1 8b8b44010000                     mov    ecx,DWORD PTR [ebx+0x144]
0x7a59d7 8b9348010000                     mov    edx,DWORD PTR [ebx+0x148]
0x7a59dd 3bca                             cmp    ecx,edx
0x7a59df 7420                             je     0x7a5a01
0x7a59e1 8bc2                             mov    eax,edx
0x7a59e3 3bd2                             cmp    edx,edx
0x7a59e5 7414                             je     0x7a59fb
0x7a59e7 8b30                             mov    esi,DWORD PTR [eax]
0x7a59e9 8931                             mov    DWORD PTR [ecx],esi
0x7a59eb 8b7004                           mov    esi,DWORD PTR [eax+0x4]
0x7a59ee 897104                           mov    DWORD PTR [ecx+0x4],esi
0x7a59f1 83c008                           add    eax,0x8
0x7a59f4 83c108                           add    ecx,0x8
0x7a59f7 3bc2                             cmp    eax,edx
0x7a59f9 75ec                             jne    0x7a59e7
0x7a59fb 898b48010000                     mov    DWORD PTR [ebx+0x148],ecx
0x7a5a01 8b8300010000                     mov    eax,DWORD PTR [ebx+0x100]
0x7a5a07 85c0                             test   eax,eax
0x7a5a09 7406                             je     0x7a5a11
0x7a5a0b 50                               push   eax
0x7a5a0c e8df860100                       call   0x7be0f0
0x7a5a11 8b8304010000                     mov    eax,DWORD PTR [ebx+0x104]
0x7a5a17 8b38                             mov    edi,DWORD PTR [eax]
0x7a5a19 897c2414                         mov    DWORD PTR [esp+0x14],edi
0x7a5a1d 3bf8                             cmp    edi,eax
0x7a5a1f 0f842b010000                     je     0x7a5b50
0x7a5a25 eb04                             jmp    0x7a5a2b
0x7a5a27 8b7c2414                         mov    edi,DWORD PTR [esp+0x14]
0x7a5a2b 8b7708                           mov    esi,DWORD PTR [edi+0x8]
0x7a5a2e 85f6                             test   esi,esi
0x7a5a30 0f84cb000000                     je     0x7a5b01
0x7a5a36 8b06                             mov    eax,DWORD PTR [esi]
0x7a5a38 ff4860                           dec    DWORD PTR [eax+0x60]
0x7a5a3b 8b4674                           mov    eax,DWORD PTR [esi+0x74]
0x7a5a3e 85c0                             test   eax,eax
0x7a5a40 0f849c000000                     je     0x7a5ae2
0x7a5a46 837e7800                         cmp    DWORD PTR [esi+0x78],0x0
0x7a5a4a 0f8492000000                     je     0x7a5ae2
0x7a5a50 8b3e                             mov    edi,DWORD PTR [esi]
0x7a5a52 837f4401                         cmp    DWORD PTR [edi+0x44],0x1
0x7a5a56 89742418                         mov    DWORD PTR [esp+0x18],esi
0x7a5a5a 0f8c8d000000                     jl     0x7a5aed
0x7a5a60 8d4764                           lea    eax,[edi+0x64]
0x7a5a63 50                               push   eax
0x7a5a64 89442424                         mov    DWORD PTR [esp+0x24],eax
0x7a5a68 ff154c22bd00                     call   DWORD PTR ds:0xbd224c
0x7a5a6e 8b8780000000                     mov    eax,DWORD PTR [edi+0x80]
0x7a5a74 8d4c2418                         lea    ecx,[esp+0x18]
0x7a5a78 3bc8                             cmp    ecx,eax
0x7a5a7a 7336                             jae    0x7a5ab2
0x7a5a7c 8b4f7c                           mov    ecx,DWORD PTR [edi+0x7c]
0x7a5a7f 8d542418                         lea    edx,[esp+0x18]
0x7a5a83 3bca                             cmp    ecx,edx
0x7a5a85 772b                             ja     0x7a5ab2
0x7a5a87 8bf2                             mov    esi,edx
0x7a5a89 2bf1                             sub    esi,ecx
0x7a5a8b c1fe02                           sar    esi,0x2
0x7a5a8e 3b8784000000                     cmp    eax,DWORD PTR [edi+0x84]
0x7a5a94 7508                             jne    0x7a5a9e
0x7a5a96 8d477c                           lea    eax,[edi+0x7c]
0x7a5a99 e8921effff                       call   0x797930
0x7a5a9e 8b8780000000                     mov    eax,DWORD PTR [edi+0x80]
0x7a5aa4 85c0                             test   eax,eax
0x7a5aa6 7426                             je     0x7a5ace
0x7a5aa8 8b4f7c                           mov    ecx,DWORD PTR [edi+0x7c]
0x7a5aab 8b14b1                           mov    edx,DWORD PTR [ecx+esi*4]
0x7a5aae 8910                             mov    DWORD PTR [eax],edx
0x7a5ab0 eb1c                             jmp    0x7a5ace
0x7a5ab2 3b8784000000                     cmp    eax,DWORD PTR [edi+0x84]
0x7a5ab8 7508                             jne    0x7a5ac2
0x7a5aba 8d477c                           lea    eax,[edi+0x7c]
0x7a5abd e86e1effff                       call   0x797930
0x7a5ac2 8b8780000000                     mov    eax,DWORD PTR [edi+0x80]
0x7a5ac8 85c0                             test   eax,eax
0x7a5aca 7402                             je     0x7a5ace
0x7a5acc 8930                             mov    DWORD PTR [eax],esi
0x7a5ace 8b442420                         mov    eax,DWORD PTR [esp+0x20]
0x7a5ad2 83878000000004                   add    DWORD PTR [edi+0x80],0x4
0x7a5ad9 50                               push   eax
0x7a5ada ff154822bd00                     call   DWORD PTR ds:0xbd2248
0x7a5ae0 eb1b                             jmp    0x7a5afd
0x7a5ae2 83f801                           cmp    eax,0x1
0x7a5ae5 7c06                             jl     0x7a5aed
0x7a5ae7 56                               push   esi
0x7a5ae8 e803860100                       call   0x7be0f0
0x7a5aed 8bfe                             mov    edi,esi
0x7a5aef e85c7d0100                       call   0x7bd850
0x7a5af4 56                               push   esi
0x7a5af5 e812b70e00                       call   0x89120c
0x7a5afa 83c404                           add    esp,0x4
0x7a5afd 8b7c2414                         mov    edi,DWORD PTR [esp+0x14]
0x7a5b01 8b770c                           mov    esi,DWORD PTR [edi+0xc]
0x7a5b04 85f6                             test   esi,esi
0x7a5b06 7412                             je     0x7a5b1a
0x7a5b08 8b16                             mov    edx,DWORD PTR [esi]
0x7a5b0a 8b4210                           mov    eax,DWORD PTR [edx+0x10]
0x7a5b0d 8bce                             mov    ecx,esi
0x7a5b0f ffd0                             call   eax
0x7a5b11 8b16                             mov    edx,DWORD PTR [esi]
0x7a5b13 8b4208                           mov    eax,DWORD PTR [edx+0x8]
0x7a5b16 8bce                             mov    ecx,esi
0x7a5b18 ffd0                             call   eax
0x7a5b1a 8b37                             mov    esi,DWORD PTR [edi]
0x7a5b1c 3bbb04010000                     cmp    edi,DWORD PTR [ebx+0x104]
0x7a5b22 741c                             je     0x7a5b40
0x7a5b24 8b4f04                           mov    ecx,DWORD PTR [edi+0x4]
0x7a5b27 8931                             mov    DWORD PTR [ecx],esi
0x7a5b29 8b17                             mov    edx,DWORD PTR [edi]
0x7a5b2b 8b4704                           mov    eax,DWORD PTR [edi+0x4]
0x7a5b2e 57                               push   edi
0x7a5b2f 894204                           mov    DWORD PTR [edx+0x4],eax
0x7a5b32 e8d5b60e00                       call   0x89120c
0x7a5b37 83c404                           add    esp,0x4
0x7a5b3a ff8b08010000                     dec    DWORD PTR [ebx+0x108]
0x7a5b40 89742414                         mov    DWORD PTR [esp+0x14],esi
0x7a5b44 3bb304010000                     cmp    esi,DWORD PTR [ebx+0x104]
0x7a5b4a 0f85d7feffff                     jne    0x7a5a27
0x7a5b50 8b8b04010000                     mov    ecx,DWORD PTR [ebx+0x104]
0x7a5b56 8b01                             mov    eax,DWORD PTR [ecx]
0x7a5b58 8909                             mov    DWORD PTR [ecx],ecx
0x7a5b5a 8b8b04010000                     mov    ecx,DWORD PTR [ebx+0x104]
0x7a5b60 894904                           mov    DWORD PTR [ecx+0x4],ecx
0x7a5b63 33ff                             xor    edi,edi
0x7a5b65 89bb08010000                     mov    DWORD PTR [ebx+0x108],edi
0x7a5b6b 3b8304010000                     cmp    eax,DWORD PTR [ebx+0x104]
0x7a5b71 7415                             je     0x7a5b88
0x7a5b73 8b30                             mov    esi,DWORD PTR [eax]
0x7a5b75 50                               push   eax
0x7a5b76 e891b60e00                       call   0x89120c
0x7a5b7b 83c404                           add    esp,0x4
0x7a5b7e 8bc6                             mov    eax,esi
0x7a5b80 3bb304010000                     cmp    esi,DWORD PTR [ebx+0x104]
0x7a5b86 75eb                             jne    0x7a5b73
0x7a5b88 89bb10010000                     mov    DWORD PTR [ebx+0x110],edi
0x7a5b8e 8b4c2428                         mov    ecx,DWORD PTR [esp+0x28]
0x7a5b92 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x7a5b99 59                               pop    ecx
0x7a5b9a 5f                               pop    edi
0x7a5b9b 5e                               pop    esi
0x7a5b9c 5b                               pop    ebx
0x7a5b9d 8be5                             mov    esp,ebp
0x7a5b9f 5d                               pop    ebp
0x7a5ba0 c3                               ret

; N05_string_assign source=kr-extra-roy/MEF-P0-content-contracts-20261117/execution-lifecycle/native-evidence.json blob=533c3b8a7bd9cbd06be539978fc7b2475ee41d06
; VA 0x402a70 raw 0x1e70 SHA256 bc46338969aaa8231f4cc88ebba53847ade071972dab891ec1f61c1ba237b4a3
0x402a70 55                               push   ebp
0x402a71 8bec                             mov    ebp,esp
0x402a73 53                               push   ebx
0x402a74 8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x402a77 56                               push   esi
0x402a78 8bf1                             mov    esi,ecx
0x402a7a 85db                             test   ebx,ebx
0x402a7c 7459                             je     0x402ad7
0x402a7e 8b4e14                           mov    ecx,DWORD PTR [esi+0x14]
0x402a81 83f910                           cmp    ecx,0x10
0x402a84 7204                             jb     0x402a8a
0x402a86 8b06                             mov    eax,DWORD PTR [esi]
0x402a88 eb02                             jmp    0x402a8c
0x402a8a 8bc6                             mov    eax,esi
0x402a8c 3bd8                             cmp    ebx,eax
0x402a8e 7247                             jb     0x402ad7
0x402a90 83f910                           cmp    ecx,0x10
0x402a93 7204                             jb     0x402a99
0x402a95 8b06                             mov    eax,DWORD PTR [esi]
0x402a97 eb02                             jmp    0x402a9b
0x402a99 8bc6                             mov    eax,esi
0x402a9b 8b5610                           mov    edx,DWORD PTR [esi+0x10]
0x402a9e 03d0                             add    edx,eax
0x402aa0 3bd3                             cmp    edx,ebx
0x402aa2 7633                             jbe    0x402ad7
0x402aa4 83f910                           cmp    ecx,0x10
0x402aa7 7217                             jb     0x402ac0
0x402aa9 8b06                             mov    eax,DWORD PTR [esi]
0x402aab 8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0x402aae 51                               push   ecx
0x402aaf 2bd8                             sub    ebx,eax
0x402ab1 53                               push   ebx
0x402ab2 56                               push   esi
0x402ab3 8bce                             mov    ecx,esi
0x402ab5 e886050000                       call   0x403040
0x402aba 5e                               pop    esi
0x402abb 5b                               pop    ebx
0x402abc 5d                               pop    ebp
0x402abd c20800                           ret    0x8
0x402ac0 8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0x402ac3 8bc6                             mov    eax,esi
0x402ac5 51                               push   ecx
0x402ac6 2bd8                             sub    ebx,eax
0x402ac8 53                               push   ebx
0x402ac9 56                               push   esi
0x402aca 8bce                             mov    ecx,esi
0x402acc e86f050000                       call   0x403040
0x402ad1 5e                               pop    esi
0x402ad2 5b                               pop    ebx
0x402ad3 5d                               pop    ebp
0x402ad4 c20800                           ret    0x8
0x402ad7 57                               push   edi
0x402ad8 8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
0x402adb 83fffe                           cmp    edi,0xfffffffe
0x402ade 760a                             jbe    0x402aea
0x402ae0 6800d2be00                       push   0xbed200
0x402ae5 e846b04700                       call   0x87db30
0x402aea 8b4614                           mov    eax,DWORD PTR [esi+0x14]
0x402aed 3bc7                             cmp    eax,edi
0x402aef 731a                             jae    0x402b0b
0x402af1 8b5610                           mov    edx,DWORD PTR [esi+0x10]
0x402af4 52                               push   edx
0x402af5 57                               push   edi
0x402af6 8bce                             mov    ecx,esi
0x402af8 e8c3020000                       call   0x402dc0
0x402afd 85ff                             test   edi,edi
0x402aff 745b                             je     0x402b5c
0x402b01 837e1410                         cmp    DWORD PTR [esi+0x14],0x10
0x402b05 722a                             jb     0x402b31
0x402b07 8b06                             mov    eax,DWORD PTR [esi]
0x402b09 eb28                             jmp    0x402b33
0x402b0b 85ff                             test   edi,edi
0x402b0d 75f2                             jne    0x402b01
0x402b0f 897e10                           mov    DWORD PTR [esi+0x10],edi
0x402b12 83f810                           cmp    eax,0x10
0x402b15 720e                             jb     0x402b25
0x402b17 8b06                             mov    eax,DWORD PTR [esi]
0x402b19 5f                               pop    edi
0x402b1a c60000                           mov    BYTE PTR [eax],0x0
0x402b1d 8bc6                             mov    eax,esi
0x402b1f 5e                               pop    esi
0x402b20 5b                               pop    ebx
0x402b21 5d                               pop    ebp
0x402b22 c20800                           ret    0x8
0x402b25 5f                               pop    edi
0x402b26 8bc6                             mov    eax,esi
0x402b28 5e                               pop    esi
0x402b29 c60000                           mov    BYTE PTR [eax],0x0
0x402b2c 5b                               pop    ebx
0x402b2d 5d                               pop    ebp
0x402b2e c20800                           ret    0x8
0x402b31 8bc6                             mov    eax,esi
0x402b33 57                               push   edi
0x402b34 53                               push   ebx
0x402b35 50                               push   eax
0x402b36 e895b04900                       call   0x89dbd0
0x402b3b 83c40c                           add    esp,0xc
0x402b3e 837e1410                         cmp    DWORD PTR [esi+0x14],0x10
0x402b42 897e10                           mov    DWORD PTR [esi+0x10],edi
0x402b45 720f                             jb     0x402b56
0x402b47 8b06                             mov    eax,DWORD PTR [esi]
0x402b49 c6043800                         mov    BYTE PTR [eax+edi*1],0x0
0x402b4d 5f                               pop    edi
0x402b4e 8bc6                             mov    eax,esi
0x402b50 5e                               pop    esi
0x402b51 5b                               pop    ebx
0x402b52 5d                               pop    ebp
0x402b53 c20800                           ret    0x8
0x402b56 8bc6                             mov    eax,esi
0x402b58 c6043800                         mov    BYTE PTR [eax+edi*1],0x0
0x402b5c 5f                               pop    edi
0x402b5d 8bc6                             mov    eax,esi
0x402b5f 5e                               pop    esi
0x402b60 5b                               pop    ebx
0x402b61 5d                               pop    ebp
0x402b62 c20800                           ret    0x8
