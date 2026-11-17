; receive_iocp_prefix 0x806cf0..0x806e23 raw=0x4060f0 sha256=d196dea0f2372aeed27a12320ea0e16521607d7ee16ad9be8c6169a9056ffa98
0x806cf0 55 push   ebp
0x806cf1 8bec mov    ebp,esp
0x806cf3 83ec24 sub    esp,0x24
0x806cf6 a1201fd600 mov    eax,ds:0xd61f20
0x806cfb 33c5 xor    eax,ebp
0x806cfd 8945fc mov    DWORD PTR [ebp-0x4],eax
0x806d00 53 push   ebx
0x806d01 56 push   esi
0x806d02 33f6 xor    esi,esi
0x806d04 8bd9 mov    ebx,ecx
0x806d06 57 push   edi
0x806d07 8b7b58 mov    edi,DWORD PTR [ebx+0x58]
0x806d0a 8975e4 mov    DWORD PTR [ebp-0x1c],esi
0x806d0d 8975e0 mov    DWORD PTR [ebp-0x20],esi
0x806d10 8975dc mov    DWORD PTR [ebp-0x24],esi
0x806d13 3bfe cmp    edi,esi
0x806d15 7419 je     0x806d30
0x806d17 8b4304 mov    eax,DWORD PTR [ebx+0x4]
0x806d1a 50 push   eax
0x806d1b 68d016c500 push   0xc516d0
0x806d20 56 push   esi
0x806d21 e8da96eeff call   0x6f0400
0x806d26 83c40c add    esp,0xc
0x806d29 8da42400000000 lea    esp,[esp+0x0]
0x806d30 f605b433fe0001 test   BYTE PTR ds:0xfe33b4,0x1
0x806d37 7536 jne    0x806d6f
0x806d39 830db433fe0001 or     DWORD PTR ds:0xfe33b4,0x1
0x806d40 56 push   esi
0x806d41 56 push   esi
0x806d42 56 push   esi
0x806d43 6aff push   0xffffffff
0x806d45 8935b833fe00 mov    DWORD PTR ds:0xfe33b8,esi
0x806d4b 8935bc33fe00 mov    DWORD PTR ds:0xfe33bc,esi
0x806d51 8935c033fe00 mov    DWORD PTR ds:0xfe33c0,esi
0x806d57 ff157822bd00 call   DWORD PTR ds:0xbd2278
0x806d5d 68b00bbd00 push   0xbd0bb0
0x806d62 a3b833fe00 mov    ds:0xfe33b8,eax
0x806d67 e8aeb50800 call   0x89231a
0x806d6c 83c404 add    esp,0x4
0x806d6f 6aff push   0xffffffff
0x806d71 8d4de0 lea    ecx,[ebp-0x20]
0x806d74 51 push   ecx
0x806d75 8b0db833fe00 mov    ecx,DWORD PTR ds:0xfe33b8
0x806d7b 8d55e4 lea    edx,[ebp-0x1c]
0x806d7e 52 push   edx
0x806d7f 8d45dc lea    eax,[ebp-0x24]
0x806d82 50 push   eax
0x806d83 51 push   ecx
0x806d84 ff157422bd00 call   DWORD PTR ds:0xbd2274
0x806d8a 85c0 test   eax,eax
0x806d8c 0f843d010000 je     0x806ecf
0x806d92 8b45e4 mov    eax,DWORD PTR [ebp-0x1c]
0x806d95 83f801 cmp    eax,0x1
0x806d98 0f8490010000 je     0x806f2e
0x806d9e 8b55e0 mov    edx,DWORD PTR [ebp-0x20]
0x806da1 3bd6 cmp    edx,esi
0x806da3 751b jne    0x806dc0
0x806da5 8b7b58 mov    edi,DWORD PTR [ebx+0x58]
0x806da8 3bfe cmp    edi,esi
0x806daa 7484 je     0x806d30
0x806dac 680417c500 push   0xc51704
0x806db1 6a02 push   0x2
0x806db3 e84896eeff call   0x6f0400
0x806db8 83c408 add    esp,0x8
0x806dbb e970ffffff jmp    0x806d30
0x806dc0 8b4ddc mov    ecx,DWORD PTR [ebp-0x24]
0x806dc3 3bce cmp    ecx,esi
0x806dc5 751d jne    0x806de4
0x806dc7 8b13 mov    edx,DWORD PTR [ebx]
0x806dc9 56 push   esi
0x806dca 50 push   eax
0x806dcb 8b4224 mov    eax,DWORD PTR [edx+0x24]
0x806dce 8bcb mov    ecx,ebx
0x806dd0 ffd0 call   eax
0x806dd2 8b4de4 mov    ecx,DWORD PTR [ebp-0x1c]
0x806dd5 c781a8a0000001000000 mov    DWORD PTR [ecx+0xa0a8],0x1
0x806ddf e94cffffff jmp    0x806d30
0x806de4 8db830a00000 lea    edi,[eax+0xa030]
0x806dea 3bd7 cmp    edx,edi
0x806dec 0f858b000000 jne    0x806e7d
0x806df2 014b2c add    DWORD PTR [ebx+0x2c],ecx
0x806df5 ff433c inc    DWORD PTR [ebx+0x3c]
0x806df8 39b0aca00000 cmp    DWORD PTR [eax+0xa0ac],esi
0x806dfe 0f842cffffff je     0x806d30
0x806e04 8d5018 lea    edx,[eax+0x18]
0x806e07 50 push   eax
0x806e08 e8330d0000 call   0x807b40
0x806e0d 85c0 test   eax,eax
0x806e0f 8b45e4 mov    eax,DWORD PTR [ebp-0x1c]
0x806e12 740f je     0x806e23
0x806e14 8b13 mov    edx,DWORD PTR [ebx]
0x806e16 8b5214 mov    edx,DWORD PTR [edx+0x14]
0x806e19 50 push   eax
0x806e1a 8bcb mov    ecx,ebx
0x806e1c ffd2 call   edx
0x806e1e e90dffffff jmp    0x806d30

; receive_frame_parser 0x807b40..0x807e45 raw=0x406f40 sha256=16038e2298749cb41d3c0d36e9785ba1ac14b9c8b1df9364855ff4bae82752e7
0x807b40 55 push   ebp
0x807b41 8bec mov    ebp,esp
0x807b43 83e4f8 and    esp,0xfffffff8
0x807b46 6aff push   0xffffffff
0x807b48 68be989000 push   0x9098be
0x807b4d 64a100000000 mov    eax,fs:0x0
0x807b53 50 push   eax
0x807b54 51 push   ecx
0x807b55 b824200000 mov    eax,0x2024
0x807b5a e8118b0a00 call   0x8b0670
0x807b5f a1201fd600 mov    eax,ds:0xd61f20
0x807b64 33c4 xor    eax,esp
0x807b66 89842420200000 mov    DWORD PTR [esp+0x2020],eax
0x807b6d 53 push   ebx
0x807b6e 56 push   esi
0x807b6f 57 push   edi
0x807b70 a1201fd600 mov    eax,ds:0xd61f20
0x807b75 33c4 xor    eax,esp
0x807b77 50 push   eax
0x807b78 8d842438200000 lea    eax,[esp+0x2038]
0x807b7f 64a300000000 mov    fs:0x0,eax
0x807b85 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x807b88 8bfa mov    edi,edx
0x807b8a 018f00500000 add    DWORD PTR [edi+0x5000],ecx
0x807b90 89442424 mov    DWORD PTR [esp+0x24],eax
0x807b94 8b8700500000 mov    eax,DWORD PTR [edi+0x5000]
0x807b9a 2bc7 sub    eax,edi
0x807b9c 897c2414 mov    DWORD PTR [esp+0x14],edi
0x807ba0 8bdf mov    ebx,edi
0x807ba2 83f804 cmp    eax,0x4
0x807ba5 0f822f020000 jb     0x807dda
0x807bab eb03 jmp    0x807bb0
0x807bad 8d4900 lea    ecx,[ecx+0x0]
0x807bb0 0fb733 movzx  esi,WORD PTR [ebx]
0x807bb3 33c9 xor    ecx,ecx
0x807bb5 663bf1 cmp    si,cx
0x807bb8 0f845f020000 je     0x807e1d
0x807bbe ba00100000 mov    edx,0x1000
0x807bc3 663bf2 cmp    si,dx
0x807bc6 0f8751020000 ja     0x807e1d
0x807bcc 894c2418 mov    DWORD PTR [esp+0x18],ecx
0x807bd0 894c241c mov    DWORD PTR [esp+0x1c],ecx
0x807bd4 0fb74b02 movzx  ecx,WORD PTR [ebx+0x2]
0x807bd8 ba33260000 mov    edx,0x2633
0x807bdd c744242004000000 mov    DWORD PTR [esp+0x20],0x4
0x807be5 663bca cmp    cx,dx
0x807be8 7512 jne    0x807bfc
0x807bea c744241801000000 mov    DWORD PTR [esp+0x18],0x1
0x807bf2 c744242008000000 mov    DWORD PTR [esp+0x20],0x8
0x807bfa eb38 jmp    0x807c34
0x807bfc babb0b0000 mov    edx,0xbbb
0x807c01 663bca cmp    cx,dx
0x807c04 7512 jne    0x807c18
0x807c06 c744241c01000000 mov    DWORD PTR [esp+0x1c],0x1
0x807c0e c744242006000000 mov    DWORD PTR [esp+0x20],0x6
0x807c16 eb1c jmp    0x807c34
0x807c18 ba681a0000 mov    edx,0x1a68
0x807c1d 663bca cmp    cx,dx
0x807c20 740a je     0x807c2c
0x807c22 bad7220000 mov    edx,0x22d7
0x807c27 663bca cmp    cx,dx
0x807c2a 7508 jne    0x807c34
0x807c2c c744242004000000 mov    DWORD PTR [esp+0x20],0x4
0x807c34 8bce mov    ecx,esi
0x807c36 8b742420 mov    esi,DWORD PTR [esp+0x20]
0x807c3a 03ce add    ecx,esi
0x807c3c 3bc8 cmp    ecx,eax
0x807c3e 0f8f96010000 jg     0x807dda
0x807c44 f6055433fe0001 test   BYTE PTR ds:0xfe3354,0x1
0x807c4b 752f jne    0x807c7c
0x807c4d 830d5433fe0001 or     DWORD PTR ds:0xfe3354,0x1
0x807c54 c784244020000000000000 mov    DWORD PTR [esp+0x2040],0x0
0x807c5f e8bcf4ffff call   0x807120
0x807c64 68900bbd00 push   0xbd0b90
0x807c69 e8aca60800 call   0x89231a
0x807c6e 83c404 add    esp,0x4
0x807c71 c7842440200000ffffffff mov    DWORD PTR [esp+0x2040],0xffffffff
0x807c7c bf5833fe00 mov    edi,0xfe3358
0x807c81 e82af9ffff call   0x8075b0
0x807c86 8d3c1e lea    edi,[esi+ebx*1]
0x807c89 0fb733 movzx  esi,WORD PTR [ebx]
0x807c8c 89442428 mov    DWORD PTR [esp+0x28],eax
0x807c90 8d0c3e lea    ecx,[esi+edi*1]
0x807c93 3b7c2414 cmp    edi,DWORD PTR [esp+0x14]
0x807c97 0f8239010000 jb     0x807dd6
0x807c9d 8b542414 mov    edx,DWORD PTR [esp+0x14]
0x807ca1 81c200500000 add    edx,0x5000
0x807ca7 3bfa cmp    edi,edx
0x807ca9 0f8327010000 jae    0x807dd6
0x807caf 3b4c2414 cmp    ecx,DWORD PTR [esp+0x14]
0x807cb3 0f821d010000 jb     0x807dd6
0x807cb9 8b542414 mov    edx,DWORD PTR [esp+0x14]
0x807cbd 81c200500000 add    edx,0x5000
0x807cc3 3bca cmp    ecx,edx
0x807cc5 0f830b010000 jae    0x807dd6
0x807ccb 837c241800 cmp    DWORD PTR [esp+0x18],0x0
0x807cd0 745a je     0x807d2c
0x807cd2 8a17 mov    dl,BYTE PTR [edi]
0x807cd4 80f27c xor    dl,0x7c
0x807cd7 b801000000 mov    eax,0x1
0x807cdc 8854242c mov    BYTE PTR [esp+0x2c],dl
0x807ce0 3bf0 cmp    esi,eax
0x807ce2 7610 jbe    0x807cf4
0x807ce4 8a0c07 mov    cl,BYTE PTR [edi+eax*1]
0x807ce7 324c042b xor    cl,BYTE PTR [esp+eax*1+0x2b]
0x807ceb 40 inc    eax
0x807cec 884c042b mov    BYTE PTR [esp+eax*1+0x2b],cl
0x807cf0 3bc6 cmp    eax,esi
0x807cf2 72f0 jb     0x807ce4
0x807cf4 8d94242c100000 lea    edx,[esp+0x102c]
0x807cfb 52 push   edx
0x807cfc 8bce mov    ecx,esi
0x807cfe 8d442430 lea    eax,[esp+0x30]
0x807d02 8d7c241c lea    edi,[esp+0x1c]
0x807d06 c744241c00100000 mov    DWORD PTR [esp+0x1c],0x1000
0x807d0e e87df4f1ff call   0x727190
0x807d13 83c404 add    esp,0x4
0x807d16 85c0 test   eax,eax
0x807d18 7565 jne    0x807d7f
0x807d1a 8b742418 mov    esi,DWORD PTR [esp+0x18]
0x807d1e 8b7c2428 mov    edi,DWORD PTR [esp+0x28]
0x807d22 8d84242c100000 lea    eax,[esp+0x102c]
0x807d29 50 push   eax
0x807d2a eb4e jmp    0x807d7a
0x807d2c 837c241c00 cmp    DWORD PTR [esp+0x1c],0x0
0x807d31 7444 je     0x807d77
0x807d33 8a07 mov    al,BYTE PTR [edi]
0x807d35 34b6 xor    al,0xb6
0x807d37 0fb6c8 movzx  ecx,al
0x807d3a 8bd1 mov    edx,ecx
0x807d3c 8954241c mov    DWORD PTR [esp+0x1c],edx
0x807d40 ba01000000 mov    edx,0x1
0x807d45 8844242c mov    BYTE PTR [esp+0x2c],al
0x807d49 3bf2 cmp    esi,edx
0x807d4b 7619 jbe    0x807d66
0x807d4d 8d4900 lea    ecx,[ecx+0x0]
0x807d50 8a043a mov    al,BYTE PTR [edx+edi*1]
0x807d53 3244142b xor    al,BYTE PTR [esp+edx*1+0x2b]
0x807d57 42 inc    edx
0x807d58 8844142b mov    BYTE PTR [esp+edx*1+0x2b],al
0x807d5c 0fb6c0 movzx  eax,al
0x807d5f 6603c8 add    cx,ax
0x807d62 3bd6 cmp    edx,esi
0x807d64 72ea jb     0x807d50
0x807d66 66394b04 cmp    WORD PTR [ebx+0x4],cx
0x807d6a 7513 jne    0x807d7f
0x807d6c 8b7c2428 mov    edi,DWORD PTR [esp+0x28]
0x807d70 8d4c242c lea    ecx,[esp+0x2c]
0x807d74 51 push   ecx
0x807d75 eb03 jmp    0x807d7a
0x807d77 57 push   edi
0x807d78 8bf8 mov    edi,eax
0x807d7a e8d1000000 call   0x807e50
0x807d7f 8b442428 mov    eax,DWORD PTR [esp+0x28]
0x807d83 83780400 cmp    DWORD PTR [eax+0x4],0x0
0x807d87 8b4c2424 mov    ecx,DWORD PTR [esp+0x24]
0x807d8b 8908 mov    DWORD PTR [eax],ecx
0x807d8d 750f jne    0x807d9e
0x807d8f 50 push   eax
0x807d90 e87bc5ffff call   0x804310
0x807d95 8bf8 mov    edi,eax
0x807d97 e854f9ffff call   0x8076f0
0x807d9c eb14 jmp    0x807db2
0x807d9e 8b8980a00000 mov    ecx,DWORD PTR [ecx+0xa080]
0x807da4 51 push   ecx
0x807da5 50 push   eax
0x807da6 e8751bc8ff call   0x489920
0x807dab 8bf8 mov    edi,eax
0x807dad e8eec2ffff call   0x8040a0
0x807db2 0fb713 movzx  edx,WORD PTR [ebx]
0x807db5 03542420 add    edx,DWORD PTR [esp+0x20]
0x807db9 8b442414 mov    eax,DWORD PTR [esp+0x14]
0x807dbd 8b8000500000 mov    eax,DWORD PTR [eax+0x5000]
0x807dc3 8b7c2414 mov    edi,DWORD PTR [esp+0x14]
0x807dc7 03da add    ebx,edx
0x807dc9 2bc3 sub    eax,ebx
0x807dcb 83f804 cmp    eax,0x4
0x807dce 0f83dcfdffff jae    0x807bb0
0x807dd4 eb04 jmp    0x807dda
0x807dd6 8b7c2414 mov    edi,DWORD PTR [esp+0x14]
0x807dda 8bb700500000 mov    esi,DWORD PTR [edi+0x5000]
0x807de0 8d8700500000 lea    eax,[edi+0x5000]
0x807de6 2bf3 sub    esi,ebx
0x807de8 89442424 mov    DWORD PTR [esp+0x24],eax
0x807dec 8d0c1e lea    ecx,[esi+ebx*1]
0x807def 3bdf cmp    ebx,edi
0x807df1 722a jb     0x807e1d
0x807df3 3bd8 cmp    ebx,eax
0x807df5 7326 jae    0x807e1d
0x807df7 3bcf cmp    ecx,edi
0x807df9 7222 jb     0x807e1d
0x807dfb 3bc8 cmp    ecx,eax
0x807dfd 731e jae    0x807e1d
0x807dff 85f6 test   esi,esi
0x807e01 781a js     0x807e1d
0x807e03 56 push   esi
0x807e04 53 push   ebx
0x807e05 57 push   edi
0x807e06 e8e5940800 call   0x8912f0
0x807e0b 8b442430 mov    eax,DWORD PTR [esp+0x30]
0x807e0f 83c40c add    esp,0xc
0x807e12 03fe add    edi,esi
0x807e14 8938 mov    DWORD PTR [eax],edi
0x807e16 b801000000 mov    eax,0x1
0x807e1b eb02 jmp    0x807e1f
0x807e1d 33c0 xor    eax,eax
0x807e1f 8b8c2438200000 mov    ecx,DWORD PTR [esp+0x2038]
0x807e26 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x807e2d 59 pop    ecx
0x807e2e 5f pop    edi
0x807e2f 5e pop    esi
0x807e30 5b pop    ebx
0x807e31 8b8c2420200000 mov    ecx,DWORD PTR [esp+0x2020]
0x807e38 33cc xor    ecx,esp
0x807e3a e8c2910800 call   0x891001
0x807e3f 8be5 mov    esp,ebp
0x807e41 5d pop    ebp
0x807e42 c20400 ret    0x4

; node_payload_copy 0x807e50..0x807e7b raw=0x407250 sha256=719e4b4ecc026951eef72907d1be7d8fd8cd7491ece5ecdce3aeb3b537bb2dbb
0x807e50 55 push   ebp
0x807e51 8bec mov    ebp,esp
0x807e53 81fe00100000 cmp    esi,0x1000
0x807e59 7606 jbe    0x807e61
0x807e5b 32c0 xor    al,al
0x807e5d 5d pop    ebp
0x807e5e c20400 ret    0x4
0x807e61 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x807e64 56 push   esi
0x807e65 50 push   eax
0x807e66 8d4f08 lea    ecx,[edi+0x8]
0x807e69 51 push   ecx
0x807e6a e8615d0900 call   0x89dbd0
0x807e6f 83c40c add    esp,0xc
0x807e72 897704 mov    DWORD PTR [edi+0x4],esi
0x807e75 b001 mov    al,0x1
0x807e77 5d pop    ebp
0x807e78 c20400 ret    0x4

; queue_owner 0x489920..0x489982 raw=0x88d20 sha256=b409901c6a100c637c4e3ea0dc38663f26ef4c4de82358e03ba54921e4b28e86
0x489920 55 push   ebp
0x489921 8bec mov    ebp,esp
0x489923 6aff push   0xffffffff
0x489925 68ae669000 push   0x9066ae
0x48992a 64a100000000 mov    eax,fs:0x0
0x489930 50 push   eax
0x489931 a1201fd600 mov    eax,ds:0xd61f20
0x489936 33c5 xor    eax,ebp
0x489938 50 push   eax
0x489939 8d45f4 lea    eax,[ebp-0xc]
0x48993c 64a300000000 mov    fs:0x0,eax
0x489942 b801000000 mov    eax,0x1
0x489947 8405cc10fc00 test   BYTE PTR ds:0xfc10cc,al
0x48994d 751f jne    0x48996e
0x48994f 0905cc10fc00 or     DWORD PTR ds:0xfc10cc,eax
0x489955 c745fc00000000 mov    DWORD PTR [ebp-0x4],0x0
0x48995c e88fa63700 call   0x803ff0
0x489961 6890dcbc00 push   0xbcdc90
0x489966 e8af894000 call   0x89231a
0x48996b 83c404 add    esp,0x4
0x48996e b8d010fc00 mov    eax,0xfc10d0
0x489973 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x489976 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x48997d 59 pop    ecx
0x48997e 8be5 mov    esp,ebp
0x489980 5d pop    ebp
0x489981 c3 ret

; queue_enqueue 0x8040a0..0x8040f8 raw=0x4034a0 sha256=2870243484931d7d5d9e361ea818603fbe93e9beb3515101ace58879d2eb9563
0x8040a0 55 push   ebp
0x8040a1 8bec mov    ebp,esp
0x8040a3 8b8724010000 mov    eax,DWORD PTR [edi+0x124]
0x8040a9 53 push   ebx
0x8040aa 8b5d0c mov    ebx,DWORD PTR [ebp+0xc]
0x8040ad 56 push   esi
0x8040ae 50 push   eax
0x8040af ff154c22bd00 call   DWORD PTR ds:0xbd224c
0x8040b5 33d2 xor    edx,edx
0x8040b7 38943b28010000 cmp    BYTE PTR [ebx+edi*1+0x128],dl
0x8040be 8d4d08 lea    ecx,[ebp+0x8]
0x8040c1 0f94c2 sete   dl
0x8040c4 51 push   ecx
0x8040c5 8d045a lea    eax,[edx+ebx*2]
0x8040c8 8d0440 lea    eax,[eax+eax*2]
0x8040cb 8d34c7 lea    esi,[edi+eax*8]
0x8040ce e88d010000 call   0x804260
0x8040d3 8b8f24010000 mov    ecx,DWORD PTR [edi+0x124]
0x8040d9 51 push   ecx
0x8040da ff154822bd00 call   DWORD PTR ds:0xbd2248
0x8040e0 5e pop    esi
0x8040e1 83fb02 cmp    ebx,0x2
0x8040e4 5b pop    ebx
0x8040e5 750d jne    0x8040f4
0x8040e7 8b9720010000 mov    edx,DWORD PTR [edi+0x120]
0x8040ed 52 push   edx
0x8040ee ff15d020bd00 call   DWORD PTR ds:0xbd20d0
0x8040f4 5d pop    ebp
0x8040f5 c20800 ret    0x8

; queue_consume 0x804740..0x804a34 raw=0x403b40 sha256=2ebd30dcc6f0bcf9f4aa447aed53bf82d253e68702b14a53d5570c09ffab4f9d
0x804740 55 push   ebp
0x804741 8bec mov    ebp,esp
0x804743 6aff push   0xffffffff
0x804745 689c9a9000 push   0x909a9c
0x80474a 64a100000000 mov    eax,fs:0x0
0x804750 50 push   eax
0x804751 83ec4c sub    esp,0x4c
0x804754 53 push   ebx
0x804755 56 push   esi
0x804756 57 push   edi
0x804757 a1201fd600 mov    eax,ds:0xd61f20
0x80475c 33c5 xor    eax,ebp
0x80475e 50 push   eax
0x80475f 8d45f4 lea    eax,[ebp-0xc]
0x804762 64a300000000 mov    fs:0x0,eax
0x804768 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x80476b f605cc10fc0001 test   BYTE PTR ds:0xfc10cc,0x1
0x804772 7527 jne    0x80479b
0x804774 830dcc10fc0001 or     DWORD PTR ds:0xfc10cc,0x1
0x80477b c745fc00000000 mov    DWORD PTR [ebp-0x4],0x0
0x804782 e869f8ffff call   0x803ff0
0x804787 6890dcbc00 push   0xbcdc90
0x80478c e889db0800 call   0x89231a
0x804791 83c404 add    esp,0x4
0x804794 c745fcffffffff mov    DWORD PTR [ebp-0x4],0xffffffff
0x80479b a1f011fc00 mov    eax,ds:0xfc11f0
0x8047a0 6a01 push   0x1
0x8047a2 50 push   eax
0x8047a3 c745f000000000 mov    DWORD PTR [ebp-0x10],0x0
0x8047aa ff15fc20bd00 call   DWORD PTR ds:0xbd20fc
0x8047b0 33c0 xor    eax,eax
0x8047b2 8d7b04 lea    edi,[ebx+0x4]
0x8047b5 b90b000000 mov    ecx,0xb
0x8047ba 8d7330 lea    esi,[ebx+0x30]
0x8047bd f3a5 rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
0x8047bf 8945a8 mov    DWORD PTR [ebp-0x58],eax
0x8047c2 8945ac mov    DWORD PTR [ebp-0x54],eax
0x8047c5 8945b0 mov    DWORD PTR [ebp-0x50],eax
0x8047c8 8945b4 mov    DWORD PTR [ebp-0x4c],eax
0x8047cb 8945b8 mov    DWORD PTR [ebp-0x48],eax
0x8047ce 8945bc mov    DWORD PTR [ebp-0x44],eax
0x8047d1 8945c0 mov    DWORD PTR [ebp-0x40],eax
0x8047d4 8945c8 mov    DWORD PTR [ebp-0x38],eax
0x8047d7 8945cc mov    DWORD PTR [ebp-0x34],eax
0x8047da 668945d0 mov    WORD PTR [ebp-0x30],ax
0x8047de b90b000000 mov    ecx,0xb
0x8047e3 8d75a8 lea    esi,[ebp-0x58]
0x8047e6 8d7b30 lea    edi,[ebx+0x30]
0x8047e9 f3a5 rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
0x8047eb 8b3da025bd00 mov    edi,DWORD PTR ds:0xbd25a0
0x8047f1 ffd7 call   edi
0x8047f3 8b8b84000000 mov    ecx,DWORD PTR [ebx+0x84]
0x8047f9 894330 mov    DWORD PTR [ebx+0x30],eax
0x8047fc 2b4310 sub    eax,DWORD PTR [ebx+0x10]
0x8047ff 8d51fc lea    edx,[ecx-0x4]
0x804802 3bc2 cmp    eax,edx
0x804804 760d jbe    0x804813
0x804806 c745ec04000000 mov    DWORD PTR [ebp-0x14],0x4
0x80480d c6435801 mov    BYTE PTR [ebx+0x58],0x1
0x804811 eb03 jmp    0x804816
0x804813 894dec mov    DWORD PTR [ebp-0x14],ecx
0x804816 33f6 xor    esi,esi
0x804818 897350 mov    DWORD PTR [ebx+0x50],esi
0x80481b 897354 mov    DWORD PTR [ebx+0x54],esi
0x80481e ffd7 call   edi
0x804820 894338 mov    DWORD PTR [ebx+0x38],eax
0x804823 897508 mov    DWORD PTR [ebp+0x8],esi
0x804826 83fe02 cmp    esi,0x2
0x804829 750c jne    0x804837
0x80482b ffd7 call   edi
0x80482d 894340 mov    DWORD PTR [ebx+0x40],eax
0x804830 c7435400000000 mov    DWORD PTR [ebx+0x54],0x0
0x804837 56 push   esi
0x804838 8d45f0 lea    eax,[ebp-0x10]
0x80483b 50 push   eax
0x80483c b8d010fc00 mov    eax,0xfc10d0
0x804841 e8baf8ffff call   0x804100
0x804846 84c0 test   al,al
0x804848 0f8482010000 je     0x8049d0
0x80484e 8bff mov    edi,edi
0x804850 ffd7 call   edi
0x804852 8b75f0 mov    esi,DWORD PTR [ebp-0x10]
0x804855 8b4d08 mov    ecx,DWORD PTR [ebp+0x8]
0x804858 8b13 mov    edx,DWORD PTR [ebx]
0x80485a 8b12 mov    edx,DWORD PTR [edx]
0x80485c 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x80485f 8b4604 mov    eax,DWORD PTR [esi+0x4]
0x804862 51 push   ecx
0x804863 50 push   eax
0x804864 8d4608 lea    eax,[esi+0x8]
0x804867 50 push   eax
0x804868 8b06 mov    eax,DWORD PTR [esi]
0x80486a 50 push   eax
0x80486b 8bcb mov    ecx,ebx
0x80486d ffd2 call   edx
0x80486f 8945e4 mov    DWORD PTR [ebp-0x1c],eax
0x804872 ffd7 call   edi
0x804874 2b45e8 sub    eax,DWORD PTR [ebp-0x18]
0x804877 8b4d08 mov    ecx,DWORD PTR [ebp+0x8]
0x80487a 8bf8 mov    edi,eax
0x80487c 8b03 mov    eax,DWORD PTR [ebx]
0x80487e 8b500c mov    edx,DWORD PTR [eax+0xc]
0x804881 57 push   edi
0x804882 56 push   esi
0x804883 51 push   ecx
0x804884 8bcb mov    ecx,ebx
0x804886 ffd2 call   edx
0x804888 83ff28 cmp    edi,0x28
0x80488b 7616 jbe    0x8048a3
0x80488d 8b4d08 mov    ecx,DWORD PTR [ebp+0x8]
0x804890 8b03 mov    eax,DWORD PTR [ebx]
0x804892 8b938c000000 mov    edx,DWORD PTR [ebx+0x8c]
0x804898 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x80489b 57 push   edi
0x80489c 56 push   esi
0x80489d 51 push   ecx
0x80489e 52 push   edx
0x80489f 8bcb mov    ecx,ebx
0x8048a1 ffd0 call   eax
0x8048a3 f6055433fe0001 test   BYTE PTR ds:0xfe3354,0x1
0x8048aa 7527 jne    0x8048d3
0x8048ac b801000000 mov    eax,0x1
0x8048b1 09055433fe00 or     DWORD PTR ds:0xfe3354,eax
0x8048b7 8945fc mov    DWORD PTR [ebp-0x4],eax
0x8048ba e861280000 call   0x807120
0x8048bf 68900bbd00 push   0xbd0b90
0x8048c4 e851da0800 call   0x89231a
0x8048c9 83c404 add    esp,0x4
0x8048cc c745fcffffffff mov    DWORD PTR [ebp-0x4],0xffffffff
0x8048d3 c70600000000 mov    DWORD PTR [esi],0x0
0x8048d9 c7460400000000 mov    DWORD PTR [esi+0x4],0x0
0x8048e0 8b0db033fe00 mov    ecx,DWORD PTR ds:0xfe33b0
0x8048e6 51 push   ecx
0x8048e7 ff154c22bd00 call   DWORD PTR ds:0xbd224c
0x8048ed a1a433fe00 mov    eax,ds:0xfe33a4
0x8048f2 8b15a033fe00 mov    edx,DWORD PTR ds:0xfe33a0
0x8048f8 03d0 add    edx,eax
0x8048fa f6c203 test   dl,0x3
0x8048fd 7518 jne    0x804917
0x8048ff 83c004 add    eax,0x4
0x804902 c1e802 shr    eax,0x2
0x804905 39059c33fe00 cmp    DWORD PTR ds:0xfe339c,eax
0x80490b 770a ja     0x804917
0x80490d 689433fe00 push   0xfe3394
0x804912 e85926e3ff call   0x636f70
0x804917 a1a033fe00 mov    eax,ds:0xfe33a0
0x80491c 0305a433fe00 add    eax,DWORD PTR ds:0xfe33a4
0x804922 8b0d9c33fe00 mov    ecx,DWORD PTR ds:0xfe339c
0x804928 8bf8 mov    edi,eax
0x80492a c1ef02 shr    edi,0x2
0x80492d 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x804930 3bcf cmp    ecx,edi
0x804932 7702 ja     0x804936
0x804934 2bf9 sub    edi,ecx
0x804936 8b159833fe00 mov    edx,DWORD PTR ds:0xfe3398
0x80493c 833cba00 cmp    DWORD PTR [edx+edi*4],0x0
0x804940 751e jne    0x804960
0x804942 6a10 push   0x10
0x804944 e81fc90800 call   0x891268
0x804949 83c404 add    esp,0x4
0x80494c 85c0 test   eax,eax
0x80494e 0f84b8000000 je     0x804a0c
0x804954 8b0d9833fe00 mov    ecx,DWORD PTR ds:0xfe3398
0x80495a 8904b9 mov    DWORD PTR [ecx+edi*4],eax
0x80495d 8b45e8 mov    eax,DWORD PTR [ebp-0x18]
0x804960 8b159833fe00 mov    edx,DWORD PTR ds:0xfe3398
0x804966 8b0cba mov    ecx,DWORD PTR [edx+edi*4]
0x804969 83e003 and    eax,0x3
0x80496c 8d0481 lea    eax,[ecx+eax*4]
0x80496f 85c0 test   eax,eax
0x804971 7402 je     0x804975
0x804973 8930 mov    DWORD PTR [eax],esi
0x804975 8b15b033fe00 mov    edx,DWORD PTR ds:0xfe33b0
0x80497b be01000000 mov    esi,0x1
0x804980 0135a433fe00 add    DWORD PTR ds:0xfe33a4,esi
0x804986 2935ac33fe00 sub    DWORD PTR ds:0xfe33ac,esi
0x80498c 52 push   edx
0x80498d ff154822bd00 call   DWORD PTR ds:0xbd2248
0x804993 017350 add    DWORD PTR [ebx+0x50],esi
0x804996 837d0802 cmp    DWORD PTR [ebp+0x8],0x2
0x80499a 7503 jne    0x80499f
0x80499c 017354 add    DWORD PTR [ebx+0x54],esi
0x80499f 837de400 cmp    DWORD PTR [ebp-0x1c],0x0
0x8049a3 7522 jne    0x8049c7
0x8049a5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x8049a8 50 push   eax
0x8049a9 8d4df0 lea    ecx,[ebp-0x10]
0x8049ac 51 push   ecx
0x8049ad b8d010fc00 mov    eax,0xfc10d0
0x8049b2 e849f7ffff call   0x804100
0x8049b7 8b3da025bd00 mov    edi,DWORD PTR ds:0xbd25a0
0x8049bd 84c0 test   al,al
0x8049bf 0f858bfeffff jne    0x804850
0x8049c5 eb06 jmp    0x8049cd
0x8049c7 8b3da025bd00 mov    edi,DWORD PTR ds:0xbd25a0
0x8049cd 8b7508 mov    esi,DWORD PTR [ebp+0x8]
0x8049d0 83fe02 cmp    esi,0x2
0x8049d3 7505 jne    0x8049da
0x8049d5 ffd7 call   edi
0x8049d7 894344 mov    DWORD PTR [ebx+0x44],eax
0x8049da 46 inc    esi
0x8049db 897508 mov    DWORD PTR [ebp+0x8],esi
0x8049de 83fe06 cmp    esi,0x6
0x8049e1 0f8c3ffeffff jl     0x804826
0x8049e7 ffd7 call   edi
0x8049e9 89433c mov    DWORD PTR [ebx+0x3c],eax
0x8049ec 2b4338 sub    eax,DWORD PTR [ebx+0x38]
0x8049ef 3b45ec cmp    eax,DWORD PTR [ebp-0x14]
0x8049f2 0f97c1 seta   cl
0x8049f5 884b59 mov    BYTE PTR [ebx+0x59],cl
0x8049f8 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x8049fb 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x804a02 59 pop    ecx
0x804a03 5f pop    edi
0x804a04 5e pop    esi
0x804a05 5b pop    ebx
0x804a06 8be5 mov    esp,ebp
0x804a08 5d pop    ebp
0x804a09 c20400 ret    0x4
0x804a0c 8d55e0 lea    edx,[ebp-0x20]
0x804a0f 52 push   edx
0x804a10 8d4dd4 lea    ecx,[ebp-0x2c]
0x804a13 c745e000000000 mov    DWORD PTR [ebp-0x20],0x0
0x804a1a e88ac60800 call   0x8910a9
0x804a1f 68a857c800 push   0xc857a8
0x804a24 8d45d4 lea    eax,[ebp-0x2c]
0x804a27 50 push   eax
0x804a28 c745d4a42cbd00 mov    DWORD PTR [ebp-0x2c],0xbd2ca4
0x804a2f e8bc7f0900 call   0x89c9f0

; client_packet_callback 0x4930e0..0x493161 raw=0x924e0 sha256=6f67884f69dbaa50dbefcca47dd3eb15a7da152bd664dd9aab37ac60a9c1c831
0x4930e0 55 push   ebp
0x4930e1 8bec mov    ebp,esp
0x4930e3 51 push   ecx
0x4930e4 8b450c mov    eax,DWORD PTR [ebp+0xc]
0x4930e7 53 push   ebx
0x4930e8 8b5d10 mov    ebx,DWORD PTR [ebp+0x10]
0x4930eb 56 push   esi
0x4930ec 57 push   edi
0x4930ed 0fb738 movzx  edi,WORD PTR [eax]
0x4930f0 8bf1 mov    esi,ecx
0x4930f2 c645ff00 mov    BYTE PTR [ebp-0x1],0x0
0x4930f6 85db test   ebx,ebx
0x4930f8 750b jne    0x493105
0x4930fa 5f pop    edi
0x4930fb 5e pop    esi
0x4930fc 33c0 xor    eax,eax
0x4930fe 5b pop    ebx
0x4930ff 8be5 mov    esp,ebp
0x493101 5d pop    ebp
0x493102 c21000 ret    0x10
0x493105 8b4514 mov    eax,DWORD PTR [ebp+0x14]
0x493108 83e802 sub    eax,0x2
0x49310b 7547 jne    0x493154
0x49310d 53 push   ebx
0x49310e 57 push   edi
0x49310f 8d86e0be0000 lea    eax,[esi+0xbee0]
0x493115 e8d6802400 call   0x6db1f0
0x49311a ff15a025bd00 call   DWORD PTR ds:0xbd25a0
0x493120 8b96b8000000 mov    edx,DWORD PTR [esi+0xb8]
0x493126 8b450c mov    eax,DWORD PTR [ebp+0xc]
0x493129 8b5204 mov    edx,DWORD PTR [edx+0x4]
0x49312c 57 push   edi
0x49312d 8d8eb8000000 lea    ecx,[esi+0xb8]
0x493133 53 push   ebx
0x493134 50 push   eax
0x493135 ffd2 call   edx
0x493137 8bf8 mov    edi,eax
0x493139 ff15a025bd00 call   DWORD PTR ds:0xbd25a0
0x49313f 81ff00010000 cmp    edi,0x100
0x493145 750d jne    0x493154
0x493147 83be8cbe000000 cmp    DWORD PTR [esi+0xbe8c],0x0
0x49314e 7404 je     0x493154
0x493150 c645ff01 mov    BYTE PTR [ebp-0x1],0x1
0x493154 0fb645ff movzx  eax,BYTE PTR [ebp-0x1]
0x493158 5f pop    edi
0x493159 5e pop    esi
0x49315a 5b pop    ebx
0x49315b 8be5 mov    esp,ebp
0x49315d 5d pop    ebp
0x49315e c21000 ret    0x10

; frontend_dispatch 0x48aad0..0x48ab68 raw=0x89ed0 sha256=8eab8912bc6b3904e9825f1a70c3515570e3655c374fb7bbe07d8fcbb95d4fb4
0x48aad0 55 push   ebp
0x48aad1 8bec mov    ebp,esp
0x48aad3 83ec08 sub    esp,0x8
0x48aad6 53 push   ebx
0x48aad7 8b5d10 mov    ebx,DWORD PTR [ebp+0x10]
0x48aada 0fbfc3 movsx  eax,bx
0x48aadd 56 push   esi
0x48aade 894510 mov    DWORD PTR [ebp+0x10],eax
0x48aae1 03c0 add    eax,eax
0x48aae3 57 push   edi
0x48aae4 8bf9 mov    edi,ecx
0x48aae6 8b4cc70c mov    ecx,DWORD PTR [edi+eax*8+0xc]
0x48aaea 8d34c7 lea    esi,[edi+eax*8]
0x48aaed 8b4608 mov    eax,DWORD PTR [esi+0x8]
0x48aaf0 8945f8 mov    DWORD PTR [ebp-0x8],eax
0x48aaf3 894dfc mov    DWORD PTR [ebp-0x4],ecx
0x48aaf6 85c0 test   eax,eax
0x48aaf8 751b jne    0x48ab15
0x48aafa 8b450c mov    eax,DWORD PTR [ebp+0xc]
0x48aafd 8b4d08 mov    ecx,DWORD PTR [ebp+0x8]
0x48ab00 8b17 mov    edx,DWORD PTR [edi]
0x48ab02 8b520c mov    edx,DWORD PTR [edx+0xc]
0x48ab05 53 push   ebx
0x48ab06 50 push   eax
0x48ab07 51 push   ecx
0x48ab08 8bcf mov    ecx,edi
0x48ab0a ffd2 call   edx
0x48ab0c 5f pop    edi
0x48ab0d 5e pop    esi
0x48ab0e 5b pop    ebx
0x48ab0f 8be5 mov    esp,ebp
0x48ab11 5d pop    ebp
0x48ab12 c20c00 ret    0xc
0x48ab15 8b4610 mov    eax,DWORD PTR [esi+0x10]
0x48ab18 6a06 push   0x6
0x48ab1a 686c6cbf00 push   0xbf6c6c
0x48ab1f 50 push   eax
0x48ab20 e8997d4000 call   0x8928be
0x48ab25 8b4d0c mov    ecx,DWORD PTR [ebp+0xc]
0x48ab28 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x48ab2b 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x48ab2e 83c40c add    esp,0xc
0x48ab31 53 push   ebx
0x48ab32 51 push   ecx
0x48ab33 52 push   edx
0x48ab34 8d8c3800feffff lea    ecx,[eax+edi*1-0x200]
0x48ab3b ff55f8 call   DWORD PTR [ebp-0x8]
0x48ab3e 8bf8 mov    edi,eax
0x48ab40 81ff05400080 cmp    edi,0x80004005
0x48ab46 7515 jne    0x48ab5d
0x48ab48 8b4e10 mov    ecx,DWORD PTR [esi+0x10]
0x48ab4b 8b5510 mov    edx,DWORD PTR [ebp+0x10]
0x48ab4e 51 push   ecx
0x48ab4f 52 push   edx
0x48ab50 68746cbf00 push   0xbf6c74
0x48ab55 e806302600 call   0x6edb60
0x48ab5a 83c40c add    esp,0xc
0x48ab5d 8bc7 mov    eax,edi
0x48ab5f 5f pop    edi
0x48ab60 5e pop    esi
0x48ab61 5b pop    ebx
0x48ab62 8be5 mov    esp,ebp
0x48ab64 5d pop    ebp
0x48ab65 c20c00 ret    0xc

; frontend_registration_full 0x493170..0x494355 raw=0x92570 sha256=3b36c6e6500950e6133bbc5eb65c96577be2b3224d358a42dd2476d66b87ee62
0x493170 53 push   ebx
0x493171 56 push   esi
0x493172 57 push   edi
0x493173 bf60434900 mov    edi,0x494360
0x493178 33db xor    ebx,ebx
0x49317a 8d9010020000 lea    edx,[eax+0x210]
0x493180 bed50b0000 mov    esi,0xbd5
0x493185 b97523bf00 mov    ecx,0xbf2375
0x49318a 8d9b00000000 lea    ebx,[ebx+0x0]
0x493190 897af8 mov    DWORD PTR [edx-0x8],edi
0x493193 895afc mov    DWORD PTR [edx-0x4],ebx
0x493196 890a mov    DWORD PTR [edx],ecx
0x493198 83c210 add    edx,0x10
0x49319b 4e dec    esi
0x49319c 75f2 jne    0x493190
0x49319e ba80474900 mov    edx,0x494780
0x4931a3 899098030000 mov    DWORD PTR [eax+0x398],edx
0x4931a9 bab0434900 mov    edx,0x4943b0
0x4931ae 899048100000 mov    DWORD PTR [eax+0x1048],edx
0x4931b4 bab0434900 mov    edx,0x4943b0
0x4931b9 8990c8030000 mov    DWORD PTR [eax+0x3c8],edx
0x4931bf bab0434900 mov    edx,0x4943b0
0x4931c4 899008040000 mov    DWORD PTR [eax+0x408],edx
0x4931ca ba60484900 mov    edx,0x494860
0x4931cf 899038040000 mov    DWORD PTR [eax+0x438],edx
0x4931d5 ba904a4900 mov    edx,0x494a90
0x4931da 899048040000 mov    DWORD PTR [eax+0x448],edx
0x4931e0 bad04c4900 mov    edx,0x494cd0
0x4931e5 8990f8040000 mov    DWORD PTR [eax+0x4f8],edx
0x4931eb ba50474900 mov    edx,0x494750
0x4931f0 899078090000 mov    DWORD PTR [eax+0x978],edx
0x4931f6 baf0594900 mov    edx,0x4959f0
0x4931fb 8990a80f0000 mov    DWORD PTR [eax+0xfa8],edx
0x493201 ba605a4900 mov    edx,0x495a60
0x493206 8990280f0000 mov    DWORD PTR [eax+0xf28],edx
0x49320c bab0434900 mov    edx,0x4943b0
0x493211 899008090000 mov    DWORD PTR [eax+0x908],edx
0x493217 bab0434900 mov    edx,0x4943b0
0x49321c 899098040000 mov    DWORD PTR [eax+0x498],edx
0x493222 bab0434900 mov    edx,0x4943b0
0x493227 8990e8030000 mov    DWORD PTR [eax+0x3e8],edx
0x49322d bab0434900 mov    edx,0x4943b0
0x493232 899048060000 mov    DWORD PTR [eax+0x648],edx
0x493238 bab0434900 mov    edx,0x4943b0
0x49323d 8990a8040000 mov    DWORD PTR [eax+0x4a8],edx
0x493243 bab0434900 mov    edx,0x4943b0
0x493248 8990c8040000 mov    DWORD PTR [eax+0x4c8],edx
0x49324e bab0434900 mov    edx,0x4943b0
0x493253 899018150000 mov    DWORD PTR [eax+0x1518],edx
0x493259 bab0434900 mov    edx,0x4943b0
0x49325e 8990d8040000 mov    DWORD PTR [eax+0x4d8],edx
0x493264 bab0434900 mov    edx,0x4943b0
0x493269 899018080000 mov    DWORD PTR [eax+0x818],edx
0x49326f bab0434900 mov    edx,0x4943b0
0x493274 899068080000 mov    DWORD PTR [eax+0x868],edx
0x49327a 89b09c030000 mov    DWORD PTR [eax+0x39c],esi
0x493280 8988a0030000 mov    DWORD PTR [eax+0x3a0],ecx
0x493286 89b04c100000 mov    DWORD PTR [eax+0x104c],esi
0x49328c 898850100000 mov    DWORD PTR [eax+0x1050],ecx
0x493292 89b0cc030000 mov    DWORD PTR [eax+0x3cc],esi
0x493298 8988d0030000 mov    DWORD PTR [eax+0x3d0],ecx
0x49329e 89b00c040000 mov    DWORD PTR [eax+0x40c],esi
0x4932a4 898810040000 mov    DWORD PTR [eax+0x410],ecx
0x4932aa 89b03c040000 mov    DWORD PTR [eax+0x43c],esi
0x4932b0 898840040000 mov    DWORD PTR [eax+0x440],ecx
0x4932b6 89b04c040000 mov    DWORD PTR [eax+0x44c],esi
0x4932bc 898850040000 mov    DWORD PTR [eax+0x450],ecx
0x4932c2 89b0fc040000 mov    DWORD PTR [eax+0x4fc],esi
0x4932c8 898800050000 mov    DWORD PTR [eax+0x500],ecx
0x4932ce 89b07c090000 mov    DWORD PTR [eax+0x97c],esi
0x4932d4 898880090000 mov    DWORD PTR [eax+0x980],ecx
0x4932da 89b0ac0f0000 mov    DWORD PTR [eax+0xfac],esi
0x4932e0 8988b00f0000 mov    DWORD PTR [eax+0xfb0],ecx
0x4932e6 89b02c0f0000 mov    DWORD PTR [eax+0xf2c],esi
0x4932ec 8988300f0000 mov    DWORD PTR [eax+0xf30],ecx
0x4932f2 89b00c090000 mov    DWORD PTR [eax+0x90c],esi
0x4932f8 898810090000 mov    DWORD PTR [eax+0x910],ecx
0x4932fe 89b09c040000 mov    DWORD PTR [eax+0x49c],esi
0x493304 8988a0040000 mov    DWORD PTR [eax+0x4a0],ecx
0x49330a 89b0ec030000 mov    DWORD PTR [eax+0x3ec],esi
0x493310 8988f0030000 mov    DWORD PTR [eax+0x3f0],ecx
0x493316 89b04c060000 mov    DWORD PTR [eax+0x64c],esi
0x49331c 898850060000 mov    DWORD PTR [eax+0x650],ecx
0x493322 89b0ac040000 mov    DWORD PTR [eax+0x4ac],esi
0x493328 8988b0040000 mov    DWORD PTR [eax+0x4b0],ecx
0x49332e 89b0cc040000 mov    DWORD PTR [eax+0x4cc],esi
0x493334 8988d0040000 mov    DWORD PTR [eax+0x4d0],ecx
0x49333a 89b01c150000 mov    DWORD PTR [eax+0x151c],esi
0x493340 898820150000 mov    DWORD PTR [eax+0x1520],ecx
0x493346 89b0dc040000 mov    DWORD PTR [eax+0x4dc],esi
0x49334c 8988e0040000 mov    DWORD PTR [eax+0x4e0],ecx
0x493352 89b01c080000 mov    DWORD PTR [eax+0x81c],esi
0x493358 898820080000 mov    DWORD PTR [eax+0x820],ecx
0x49335e 89b06c080000 mov    DWORD PTR [eax+0x86c],esi
0x493364 898870080000 mov    DWORD PTR [eax+0x870],ecx
0x49336a bab0434900 mov    edx,0x4943b0
0x49336f 899078080000 mov    DWORD PTR [eax+0x878],edx
0x493375 bab0434900 mov    edx,0x4943b0
0x49337a 8990b8040000 mov    DWORD PTR [eax+0x4b8],edx
0x493380 bab0434900 mov    edx,0x4943b0
0x493385 8990c8050000 mov    DWORD PTR [eax+0x5c8],edx
0x49338b bab0434900 mov    edx,0x4943b0
0x493390 8990b8090000 mov    DWORD PTR [eax+0x9b8],edx
0x493396 bab0434900 mov    edx,0x4943b0
0x49339b 899088090000 mov    DWORD PTR [eax+0x988],edx
0x4933a1 bab0434900 mov    edx,0x4943b0
0x4933a6 8990d8090000 mov    DWORD PTR [eax+0x9d8],edx
0x4933ac bab0434900 mov    edx,0x4943b0
0x4933b1 8990180a0000 mov    DWORD PTR [eax+0xa18],edx
0x4933b7 bab0434900 mov    edx,0x4943b0
0x4933bc 8990380a0000 mov    DWORD PTR [eax+0xa38],edx
0x4933c2 bab0434900 mov    edx,0x4943b0
0x4933c7 8990980f0000 mov    DWORD PTR [eax+0xf98],edx
0x4933cd bab0434900 mov    edx,0x4943b0
0x4933d2 8990e8090000 mov    DWORD PTR [eax+0x9e8],edx
0x4933d8 bab0434900 mov    edx,0x4943b0
0x4933dd 8990080a0000 mov    DWORD PTR [eax+0xa08],edx
0x4933e3 bab0434900 mov    edx,0x4943b0
0x4933e8 8990180e0000 mov    DWORD PTR [eax+0xe18],edx
0x4933ee bab0434900 mov    edx,0x4943b0
0x4933f3 8990480a0000 mov    DWORD PTR [eax+0xa48],edx
0x4933f9 bab0434900 mov    edx,0x4943b0
0x4933fe 8990280b0000 mov    DWORD PTR [eax+0xb28],edx
0x493404 bab0434900 mov    edx,0x4943b0
0x493409 8990d80c0000 mov    DWORD PTR [eax+0xcd8],edx
0x49340f bab0434900 mov    edx,0x4943b0
0x493414 8990e80c0000 mov    DWORD PTR [eax+0xce8],edx
0x49341a bab0434900 mov    edx,0x4943b0
0x49341f 8990380b0000 mov    DWORD PTR [eax+0xb38],edx
0x493425 bab0434900 mov    edx,0x4943b0
0x49342a 8990280d0000 mov    DWORD PTR [eax+0xd28],edx
0x493430 bab0434900 mov    edx,0x4943b0
0x493435 8990080d0000 mov    DWORD PTR [eax+0xd08],edx
0x49343b bab0434900 mov    edx,0x4943b0
0x493440 899078be0000 mov    DWORD PTR [eax+0xbe78],edx
0x493446 bab0434900 mov    edx,0x4943b0
0x49344b 89b07c080000 mov    DWORD PTR [eax+0x87c],esi
0x493451 898880080000 mov    DWORD PTR [eax+0x880],ecx
0x493457 89b0bc040000 mov    DWORD PTR [eax+0x4bc],esi
0x49345d 8988c0040000 mov    DWORD PTR [eax+0x4c0],ecx
0x493463 89b0cc050000 mov    DWORD PTR [eax+0x5cc],esi
0x493469 8988d0050000 mov    DWORD PTR [eax+0x5d0],ecx
0x49346f 89b0bc090000 mov    DWORD PTR [eax+0x9bc],esi
0x493475 8988c0090000 mov    DWORD PTR [eax+0x9c0],ecx
0x49347b 89b08c090000 mov    DWORD PTR [eax+0x98c],esi
0x493481 898890090000 mov    DWORD PTR [eax+0x990],ecx
0x493487 89b0dc090000 mov    DWORD PTR [eax+0x9dc],esi
0x49348d 8988e0090000 mov    DWORD PTR [eax+0x9e0],ecx
0x493493 89b01c0a0000 mov    DWORD PTR [eax+0xa1c],esi
0x493499 8988200a0000 mov    DWORD PTR [eax+0xa20],ecx
0x49349f 89b03c0a0000 mov    DWORD PTR [eax+0xa3c],esi
0x4934a5 8988400a0000 mov    DWORD PTR [eax+0xa40],ecx
0x4934ab 89b09c0f0000 mov    DWORD PTR [eax+0xf9c],esi
0x4934b1 8988a00f0000 mov    DWORD PTR [eax+0xfa0],ecx
0x4934b7 89b0ec090000 mov    DWORD PTR [eax+0x9ec],esi
0x4934bd 8988f0090000 mov    DWORD PTR [eax+0x9f0],ecx
0x4934c3 89b00c0a0000 mov    DWORD PTR [eax+0xa0c],esi
0x4934c9 8988100a0000 mov    DWORD PTR [eax+0xa10],ecx
0x4934cf 89b01c0e0000 mov    DWORD PTR [eax+0xe1c],esi
0x4934d5 8988200e0000 mov    DWORD PTR [eax+0xe20],ecx
0x4934db 89b04c0a0000 mov    DWORD PTR [eax+0xa4c],esi
0x4934e1 8988500a0000 mov    DWORD PTR [eax+0xa50],ecx
0x4934e7 89b02c0b0000 mov    DWORD PTR [eax+0xb2c],esi
0x4934ed 8988300b0000 mov    DWORD PTR [eax+0xb30],ecx
0x4934f3 89b0dc0c0000 mov    DWORD PTR [eax+0xcdc],esi
0x4934f9 8988e00c0000 mov    DWORD PTR [eax+0xce0],ecx
0x4934ff 89b0ec0c0000 mov    DWORD PTR [eax+0xcec],esi
0x493505 8988f00c0000 mov    DWORD PTR [eax+0xcf0],ecx
0x49350b 89b03c0b0000 mov    DWORD PTR [eax+0xb3c],esi
0x493511 8988400b0000 mov    DWORD PTR [eax+0xb40],ecx
0x493517 89b02c0d0000 mov    DWORD PTR [eax+0xd2c],esi
0x49351d 8988300d0000 mov    DWORD PTR [eax+0xd30],ecx
0x493523 89b00c0d0000 mov    DWORD PTR [eax+0xd0c],esi
0x493529 8988100d0000 mov    DWORD PTR [eax+0xd10],ecx
0x49352f 89b07cbe0000 mov    DWORD PTR [eax+0xbe7c],esi
0x493535 898880be0000 mov    DWORD PTR [eax+0xbe80],ecx
0x49353b 8990280e0000 mov    DWORD PTR [eax+0xe28],edx
0x493541 89b02c0e0000 mov    DWORD PTR [eax+0xe2c],esi
0x493547 8988300e0000 mov    DWORD PTR [eax+0xe30],ecx
0x49354d 89b03c0e0000 mov    DWORD PTR [eax+0xe3c],esi
0x493553 8988400e0000 mov    DWORD PTR [eax+0xe40],ecx
0x493559 89b04c0e0000 mov    DWORD PTR [eax+0xe4c],esi
0x49355f 8988500e0000 mov    DWORD PTR [eax+0xe50],ecx
0x493565 89b06c0e0000 mov    DWORD PTR [eax+0xe6c],esi
0x49356b 8988700e0000 mov    DWORD PTR [eax+0xe70],ecx
0x493571 89b05c0e0000 mov    DWORD PTR [eax+0xe5c],esi
0x493577 8988600e0000 mov    DWORD PTR [eax+0xe60],ecx
0x49357d 89b0dc0f0000 mov    DWORD PTR [eax+0xfdc],esi
0x493583 8988e00f0000 mov    DWORD PTR [eax+0xfe0],ecx
0x493589 89b0fc0f0000 mov    DWORD PTR [eax+0xffc],esi
0x49358f 898800100000 mov    DWORD PTR [eax+0x1000],ecx
0x493595 89b02c100000 mov    DWORD PTR [eax+0x102c],esi
0x49359b 898830100000 mov    DWORD PTR [eax+0x1030],ecx
0x4935a1 bab0434900 mov    edx,0x4943b0
0x4935a6 8990380e0000 mov    DWORD PTR [eax+0xe38],edx
0x4935ac bab0434900 mov    edx,0x4943b0
0x4935b1 8990480e0000 mov    DWORD PTR [eax+0xe48],edx
0x4935b7 bab0434900 mov    edx,0x4943b0
0x4935bc 8990680e0000 mov    DWORD PTR [eax+0xe68],edx
0x4935c2 bab0434900 mov    edx,0x4943b0
0x4935c7 8990580e0000 mov    DWORD PTR [eax+0xe58],edx
0x4935cd bab0434900 mov    edx,0x4943b0
0x4935d2 8990d80f0000 mov    DWORD PTR [eax+0xfd8],edx
0x4935d8 bab0434900 mov    edx,0x4943b0
0x4935dd 8990f80f0000 mov    DWORD PTR [eax+0xff8],edx
0x4935e3 bab0434900 mov    edx,0x4943b0
0x4935e8 899028100000 mov    DWORD PTR [eax+0x1028],edx
0x4935ee bab0434900 mov    edx,0x4943b0
0x4935f3 899038100000 mov    DWORD PTR [eax+0x1038],edx
0x4935f9 89b03c100000 mov    DWORD PTR [eax+0x103c],esi
0x4935ff 898840100000 mov    DWORD PTR [eax+0x1040],ecx
0x493605 bab0434900 mov    edx,0x4943b0
0x49360a 899058100000 mov    DWORD PTR [eax+0x1058],edx
0x493610 89b05c100000 mov    DWORD PTR [eax+0x105c],esi
0x493616 898860100000 mov    DWORD PTR [eax+0x1060],ecx
0x49361c bab0434900 mov    edx,0x4943b0
0x493621 899068100000 mov    DWORD PTR [eax+0x1068],edx
0x493627 89b06c100000 mov    DWORD PTR [eax+0x106c],esi
0x49362d 898870100000 mov    DWORD PTR [eax+0x1070],ecx
0x493633 bab0434900 mov    edx,0x4943b0
0x493638 899018140000 mov    DWORD PTR [eax+0x1418],edx
0x49363e 89b01c140000 mov    DWORD PTR [eax+0x141c],esi
0x493644 898820140000 mov    DWORD PTR [eax+0x1420],ecx
0x49364a bab0434900 mov    edx,0x4943b0
0x49364f 899028140000 mov    DWORD PTR [eax+0x1428],edx
0x493655 89b02c140000 mov    DWORD PTR [eax+0x142c],esi
0x49365b 898830140000 mov    DWORD PTR [eax+0x1430],ecx
0x493661 bab0434900 mov    edx,0x4943b0
0x493666 899068120000 mov    DWORD PTR [eax+0x1268],edx
0x49366c 89b06c120000 mov    DWORD PTR [eax+0x126c],esi
0x493672 898870120000 mov    DWORD PTR [eax+0x1270],ecx
0x493678 bab0434900 mov    edx,0x4943b0
0x49367d 899078100000 mov    DWORD PTR [eax+0x1078],edx
0x493683 89b07c100000 mov    DWORD PTR [eax+0x107c],esi
0x493689 898880100000 mov    DWORD PTR [eax+0x1080],ecx
0x49368f ba40444900 mov    edx,0x494440
0x493694 899008060000 mov    DWORD PTR [eax+0x608],edx
0x49369a 89b00c060000 mov    DWORD PTR [eax+0x60c],esi
0x4936a0 898810060000 mov    DWORD PTR [eax+0x610],ecx
0x4936a6 ba40444900 mov    edx,0x494440
0x4936ab 899058060000 mov    DWORD PTR [eax+0x658],edx
0x4936b1 89b05c060000 mov    DWORD PTR [eax+0x65c],esi
0x4936b7 898860060000 mov    DWORD PTR [eax+0x660],ecx
0x4936bd ba40444900 mov    edx,0x494440
0x4936c2 899068060000 mov    DWORD PTR [eax+0x668],edx
0x4936c8 89b06c060000 mov    DWORD PTR [eax+0x66c],esi
0x4936ce 898870060000 mov    DWORD PTR [eax+0x670],ecx
0x4936d4 ba40444900 mov    edx,0x494440
0x4936d9 899078060000 mov    DWORD PTR [eax+0x678],edx
0x4936df 89b07c060000 mov    DWORD PTR [eax+0x67c],esi
0x4936e5 898880060000 mov    DWORD PTR [eax+0x680],ecx
0x4936eb ba40444900 mov    edx,0x494440
0x4936f0 899048080000 mov    DWORD PTR [eax+0x848],edx
0x4936f6 89b04c080000 mov    DWORD PTR [eax+0x84c],esi
0x4936fc 898850080000 mov    DWORD PTR [eax+0x850],ecx
0x493702 ba40444900 mov    edx,0x494440
0x493707 899058080000 mov    DWORD PTR [eax+0x858],edx
0x49370d 89b05c080000 mov    DWORD PTR [eax+0x85c],esi
0x493713 898860080000 mov    DWORD PTR [eax+0x860],ecx
0x493719 ba40444900 mov    edx,0x494440
0x49371e 8990f8080000 mov    DWORD PTR [eax+0x8f8],edx
0x493724 89b0fc080000 mov    DWORD PTR [eax+0x8fc],esi
0x49372a 898800090000 mov    DWORD PTR [eax+0x900],ecx
0x493730 ba40444900 mov    edx,0x494440
0x493735 899028090000 mov    DWORD PTR [eax+0x928],edx
0x49373b 89b02c090000 mov    DWORD PTR [eax+0x92c],esi
0x493741 898830090000 mov    DWORD PTR [eax+0x930],ecx
0x493747 ba40444900 mov    edx,0x494440
0x49374c 899048090000 mov    DWORD PTR [eax+0x948],edx
0x493752 89b04c090000 mov    DWORD PTR [eax+0x94c],esi
0x493758 898850090000 mov    DWORD PTR [eax+0x950],ecx
0x49375e bad0444900 mov    edx,0x4944d0
0x493763 8990580a0000 mov    DWORD PTR [eax+0xa58],edx
0x493769 89b05c0a0000 mov    DWORD PTR [eax+0xa5c],esi
0x49376f 8988600a0000 mov    DWORD PTR [eax+0xa60],ecx
0x493775 bad0444900 mov    edx,0x4944d0
0x49377a 8990680a0000 mov    DWORD PTR [eax+0xa68],edx
0x493780 89b06c0a0000 mov    DWORD PTR [eax+0xa6c],esi
0x493786 8988700a0000 mov    DWORD PTR [eax+0xa70],ecx
0x49378c bad0444900 mov    edx,0x4944d0
0x493791 8990780a0000 mov    DWORD PTR [eax+0xa78],edx
0x493797 89b07c0a0000 mov    DWORD PTR [eax+0xa7c],esi
0x49379d 8988800a0000 mov    DWORD PTR [eax+0xa80],ecx
0x4937a3 bad0444900 mov    edx,0x4944d0
0x4937a8 899038070000 mov    DWORD PTR [eax+0x738],edx
0x4937ae 89b03c070000 mov    DWORD PTR [eax+0x73c],esi
0x4937b4 898840070000 mov    DWORD PTR [eax+0x740],ecx
0x4937ba bad0444900 mov    edx,0x4944d0
0x4937bf 899048070000 mov    DWORD PTR [eax+0x748],edx
0x4937c5 89b04c070000 mov    DWORD PTR [eax+0x74c],esi
0x4937cb 898850070000 mov    DWORD PTR [eax+0x750],ecx
0x4937d1 bad0444900 mov    edx,0x4944d0
0x4937d6 899058070000 mov    DWORD PTR [eax+0x758],edx
0x4937dc 89b05c070000 mov    DWORD PTR [eax+0x75c],esi
0x4937e2 898860070000 mov    DWORD PTR [eax+0x760],ecx
0x4937e8 bad0444900 mov    edx,0x4944d0
0x4937ed 899068070000 mov    DWORD PTR [eax+0x768],edx
0x4937f3 89b06c070000 mov    DWORD PTR [eax+0x76c],esi
0x4937f9 898870070000 mov    DWORD PTR [eax+0x770],ecx
0x4937ff bad0444900 mov    edx,0x4944d0
0x493804 899078070000 mov    DWORD PTR [eax+0x778],edx
0x49380a 89b07c070000 mov    DWORD PTR [eax+0x77c],esi
0x493810 898880070000 mov    DWORD PTR [eax+0x780],ecx
0x493816 bad0444900 mov    edx,0x4944d0
0x49381b 899088070000 mov    DWORD PTR [eax+0x788],edx
0x493821 89b08c070000 mov    DWORD PTR [eax+0x78c],esi
0x493827 898890070000 mov    DWORD PTR [eax+0x790],ecx
0x49382d bad0444900 mov    edx,0x4944d0
0x493832 8990a8070000 mov    DWORD PTR [eax+0x7a8],edx
0x493838 89b0ac070000 mov    DWORD PTR [eax+0x7ac],esi
0x49383e 8988b0070000 mov    DWORD PTR [eax+0x7b0],ecx
0x493844 ba60454900 mov    edx,0x494560
0x493849 8990d80a0000 mov    DWORD PTR [eax+0xad8],edx
0x49384f 89b0dc0a0000 mov    DWORD PTR [eax+0xadc],esi
0x493855 8988e00a0000 mov    DWORD PTR [eax+0xae0],ecx
0x49385b ba60454900 mov    edx,0x494560
0x493860 8990e80a0000 mov    DWORD PTR [eax+0xae8],edx
0x493866 89b0ec0a0000 mov    DWORD PTR [eax+0xaec],esi
0x49386c 8988f00a0000 mov    DWORD PTR [eax+0xaf0],ecx
0x493872 ba60454900 mov    edx,0x494560
0x493877 8990f80a0000 mov    DWORD PTR [eax+0xaf8],edx
0x49387d 89b0fc0a0000 mov    DWORD PTR [eax+0xafc],esi
0x493883 8988000b0000 mov    DWORD PTR [eax+0xb00],ecx
0x493889 ba60454900 mov    edx,0x494560
0x49388e 8990080b0000 mov    DWORD PTR [eax+0xb08],edx
0x493894 89b00c0b0000 mov    DWORD PTR [eax+0xb0c],esi
0x49389a 8988100b0000 mov    DWORD PTR [eax+0xb10],ecx
0x4938a0 ba60454900 mov    edx,0x494560
0x4938a5 8990880a0000 mov    DWORD PTR [eax+0xa88],edx
0x4938ab 89b08c0a0000 mov    DWORD PTR [eax+0xa8c],esi
0x4938b1 8988900a0000 mov    DWORD PTR [eax+0xa90],ecx
0x4938b7 ba60454900 mov    edx,0x494560
0x4938bc 8990980a0000 mov    DWORD PTR [eax+0xa98],edx
0x4938c2 89b09c0a0000 mov    DWORD PTR [eax+0xa9c],esi
0x4938c8 8988a00a0000 mov    DWORD PTR [eax+0xaa0],ecx
0x4938ce ba60454900 mov    edx,0x494560
0x4938d3 8990a80a0000 mov    DWORD PTR [eax+0xaa8],edx
0x4938d9 89b0ac0a0000 mov    DWORD PTR [eax+0xaac],esi
0x4938df 8988b00a0000 mov    DWORD PTR [eax+0xab0],ecx
0x4938e5 ba60454900 mov    edx,0x494560
0x4938ea 8990b80a0000 mov    DWORD PTR [eax+0xab8],edx
0x4938f0 89b0bc0a0000 mov    DWORD PTR [eax+0xabc],esi
0x4938f6 8988c00a0000 mov    DWORD PTR [eax+0xac0],ecx
0x4938fc ba60454900 mov    edx,0x494560
0x493901 8990c80a0000 mov    DWORD PTR [eax+0xac8],edx
0x493907 89b0cc0a0000 mov    DWORD PTR [eax+0xacc],esi
0x49390d 8988d00a0000 mov    DWORD PTR [eax+0xad0],ecx
0x493913 ba80464900 mov    edx,0x494680
0x493918 899098bd0000 mov    DWORD PTR [eax+0xbd98],edx
0x49391e 89b09cbd0000 mov    DWORD PTR [eax+0xbd9c],esi
0x493924 8988a0bd0000 mov    DWORD PTR [eax+0xbda0],ecx
0x49392a ba80464900 mov    edx,0x494680
0x49392f 8990a8bd0000 mov    DWORD PTR [eax+0xbda8],edx
0x493935 89b0acbd0000 mov    DWORD PTR [eax+0xbdac],esi
0x49393b 8988b0bd0000 mov    DWORD PTR [eax+0xbdb0],ecx
0x493941 ba80464900 mov    edx,0x494680
0x493946 8990b8bd0000 mov    DWORD PTR [eax+0xbdb8],edx
0x49394c 89b0bcbd0000 mov    DWORD PTR [eax+0xbdbc],esi
0x493952 8988c0bd0000 mov    DWORD PTR [eax+0xbdc0],ecx
0x493958 ba80464900 mov    edx,0x494680
0x49395d 8990c8bd0000 mov    DWORD PTR [eax+0xbdc8],edx
0x493963 89b0ccbd0000 mov    DWORD PTR [eax+0xbdcc],esi
0x493969 8988d0bd0000 mov    DWORD PTR [eax+0xbdd0],ecx
0x49396f ba80464900 mov    edx,0x494680
0x493974 899098be0000 mov    DWORD PTR [eax+0xbe98],edx
0x49397a 89b09cbe0000 mov    DWORD PTR [eax+0xbe9c],esi
0x493980 8988a0be0000 mov    DWORD PTR [eax+0xbea0],ecx
0x493986 ba80464900 mov    edx,0x494680
0x49398b 899088be0000 mov    DWORD PTR [eax+0xbe88],edx
0x493991 89b08cbe0000 mov    DWORD PTR [eax+0xbe8c],esi
0x493997 898890be0000 mov    DWORD PTR [eax+0xbe90],ecx
0x49399d ba80464900 mov    edx,0x494680
0x4939a2 8990b8be0000 mov    DWORD PTR [eax+0xbeb8],edx
0x4939a8 89b0bcbe0000 mov    DWORD PTR [eax+0xbebc],esi
0x4939ae 8988c0be0000 mov    DWORD PTR [eax+0xbec0],ecx
0x4939b4 ba80464900 mov    edx,0x494680
0x4939b9 8990d8bd0000 mov    DWORD PTR [eax+0xbdd8],edx
0x4939bf 89b0dcbd0000 mov    DWORD PTR [eax+0xbddc],esi
0x4939c5 8988e0bd0000 mov    DWORD PTR [eax+0xbde0],ecx
0x4939cb ba80464900 mov    edx,0x494680
0x4939d0 8990a8be0000 mov    DWORD PTR [eax+0xbea8],edx
0x4939d6 89b0acbe0000 mov    DWORD PTR [eax+0xbeac],esi
0x4939dc 8988b0be0000 mov    DWORD PTR [eax+0xbeb0],ecx
0x4939e2 ba80464900 mov    edx,0x494680
0x4939e7 8990e8bd0000 mov    DWORD PTR [eax+0xbde8],edx
0x4939ed 89b0ecbd0000 mov    DWORD PTR [eax+0xbdec],esi
0x4939f3 8988f0bd0000 mov    DWORD PTR [eax+0xbdf0],ecx
0x4939f9 ba80464900 mov    edx,0x494680
0x4939fe 8990f8bd0000 mov    DWORD PTR [eax+0xbdf8],edx
0x493a04 89b0fcbd0000 mov    DWORD PTR [eax+0xbdfc],esi
0x493a0a 898800be0000 mov    DWORD PTR [eax+0xbe00],ecx
0x493a10 ba80464900 mov    edx,0x494680
0x493a15 899008be0000 mov    DWORD PTR [eax+0xbe08],edx
0x493a1b 89b00cbe0000 mov    DWORD PTR [eax+0xbe0c],esi
0x493a21 898810be0000 mov    DWORD PTR [eax+0xbe10],ecx
0x493a27 ba80464900 mov    edx,0x494680
0x493a2c 899038be0000 mov    DWORD PTR [eax+0xbe38],edx
0x493a32 89b03cbe0000 mov    DWORD PTR [eax+0xbe3c],esi
0x493a38 898840be0000 mov    DWORD PTR [eax+0xbe40],ecx
0x493a3e ba80464900 mov    edx,0x494680
0x493a43 8990380d0000 mov    DWORD PTR [eax+0xd38],edx
0x493a49 89b03c0d0000 mov    DWORD PTR [eax+0xd3c],esi
0x493a4f 8988400d0000 mov    DWORD PTR [eax+0xd40],ecx
0x493a55 ba80464900 mov    edx,0x494680
0x493a5a 899048be0000 mov    DWORD PTR [eax+0xbe48],edx
0x493a60 89b04cbe0000 mov    DWORD PTR [eax+0xbe4c],esi
0x493a66 898850be0000 mov    DWORD PTR [eax+0xbe50],ecx
0x493a6c ba80464900 mov    edx,0x494680
0x493a71 899058be0000 mov    DWORD PTR [eax+0xbe58],edx
0x493a77 89b05cbe0000 mov    DWORD PTR [eax+0xbe5c],esi
0x493a7d 898860be0000 mov    DWORD PTR [eax+0xbe60],ecx
0x493a83 ba80464900 mov    edx,0x494680
0x493a88 899068be0000 mov    DWORD PTR [eax+0xbe68],edx
0x493a8e 89b06cbe0000 mov    DWORD PTR [eax+0xbe6c],esi
0x493a94 898870be0000 mov    DWORD PTR [eax+0xbe70],ecx
0x493a9a ba80464900 mov    edx,0x494680
0x493a9f 899018be0000 mov    DWORD PTR [eax+0xbe18],edx
0x493aa5 89b01cbe0000 mov    DWORD PTR [eax+0xbe1c],esi
0x493aab 898820be0000 mov    DWORD PTR [eax+0xbe20],ecx
0x493ab1 ba80464900 mov    edx,0x494680
0x493ab6 899028be0000 mov    DWORD PTR [eax+0xbe28],edx
0x493abc 89b02cbe0000 mov    DWORD PTR [eax+0xbe2c],esi
0x493ac2 898830be0000 mov    DWORD PTR [eax+0xbe30],ecx
0x493ac8 ba80464900 mov    edx,0x494680
0x493acd 8990c8be0000 mov    DWORD PTR [eax+0xbec8],edx
0x493ad3 89b0ccbe0000 mov    DWORD PTR [eax+0xbecc],esi
0x493ad9 8988d0be0000 mov    DWORD PTR [eax+0xbed0],ecx
0x493adf ba80464900 mov    edx,0x494680
0x493ae4 8990e8be0000 mov    DWORD PTR [eax+0xbee8],edx
0x493aea 89b0ecbe0000 mov    DWORD PTR [eax+0xbeec],esi
0x493af0 8988f0be0000 mov    DWORD PTR [eax+0xbef0],ecx
0x493af6 ba80464900 mov    edx,0x494680
0x493afb 8990d8be0000 mov    DWORD PTR [eax+0xbed8],edx
0x493b01 89b0dcbe0000 mov    DWORD PTR [eax+0xbedc],esi
0x493b07 8988e0be0000 mov    DWORD PTR [eax+0xbee0],ecx
0x493b0d ba80464900 mov    edx,0x494680
0x493b12 899008100000 mov    DWORD PTR [eax+0x1008],edx
0x493b18 89b00c100000 mov    DWORD PTR [eax+0x100c],esi
0x493b1e 898810100000 mov    DWORD PTR [eax+0x1010],ecx
0x493b24 ba10474900 mov    edx,0x494710
0x493b29 8990080c0000 mov    DWORD PTR [eax+0xc08],edx
0x493b2f 89b00c0c0000 mov    DWORD PTR [eax+0xc0c],esi
0x493b35 8988100c0000 mov    DWORD PTR [eax+0xc10],ecx
0x493b3b ba10474900 mov    edx,0x494710
0x493b40 8990f80b0000 mov    DWORD PTR [eax+0xbf8],edx
0x493b46 89b0fc0b0000 mov    DWORD PTR [eax+0xbfc],esi
0x493b4c 8988000c0000 mov    DWORD PTR [eax+0xc00],ecx
0x493b52 ba10474900 mov    edx,0x494710
0x493b57 8990180c0000 mov    DWORD PTR [eax+0xc18],edx
0x493b5d 89b01c0c0000 mov    DWORD PTR [eax+0xc1c],esi
0x493b63 8988200c0000 mov    DWORD PTR [eax+0xc20],ecx
0x493b69 ba10474900 mov    edx,0x494710
0x493b6e 8990380c0000 mov    DWORD PTR [eax+0xc38],edx
0x493b74 89b03c0c0000 mov    DWORD PTR [eax+0xc3c],esi
0x493b7a 8988400c0000 mov    DWORD PTR [eax+0xc40],ecx
0x493b80 ba10474900 mov    edx,0x494710
0x493b85 8990280c0000 mov    DWORD PTR [eax+0xc28],edx
0x493b8b 89b02c0c0000 mov    DWORD PTR [eax+0xc2c],esi
0x493b91 8988300c0000 mov    DWORD PTR [eax+0xc30],ecx
0x493b97 ba70524900 mov    edx,0x495270
0x493b9c 8990980d0000 mov    DWORD PTR [eax+0xd98],edx
0x493ba2 89b09c0d0000 mov    DWORD PTR [eax+0xd9c],esi
0x493ba8 8988a00d0000 mov    DWORD PTR [eax+0xda0],ecx
0x493bae ba70524900 mov    edx,0x495270
0x493bb3 8990880d0000 mov    DWORD PTR [eax+0xd88],edx
0x493bb9 89b08c0d0000 mov    DWORD PTR [eax+0xd8c],esi
0x493bbf 8988900d0000 mov    DWORD PTR [eax+0xd90],ecx
0x493bc5 ba80524900 mov    edx,0x495280
0x493bca 8990b80d0000 mov    DWORD PTR [eax+0xdb8],edx
0x493bd0 89b0bc0d0000 mov    DWORD PTR [eax+0xdbc],esi
0x493bd6 8988c00d0000 mov    DWORD PTR [eax+0xdc0],ecx
0x493bdc bab0434900 mov    edx,0x4943b0
0x493be1 8990480f0000 mov    DWORD PTR [eax+0xf48],edx
0x493be7 89b04c0f0000 mov    DWORD PTR [eax+0xf4c],esi
0x493bed 8988500f0000 mov    DWORD PTR [eax+0xf50],ecx
0x493bf3 bab0434900 mov    edx,0x4943b0
0x493bf8 8990f8be0000 mov    DWORD PTR [eax+0xbef8],edx
0x493bfe 89b0fcbe0000 mov    DWORD PTR [eax+0xbefc],esi
0x493c04 898800bf0000 mov    DWORD PTR [eax+0xbf00],ecx
0x493c0a bab0434900 mov    edx,0x4943b0
0x493c0f 899048bf0000 mov    DWORD PTR [eax+0xbf48],edx
0x493c15 89b04cbf0000 mov    DWORD PTR [eax+0xbf4c],esi
0x493c1b 898850bf0000 mov    DWORD PTR [eax+0xbf50],ecx
0x493c21 bab0434900 mov    edx,0x4943b0
0x493c26 899008bf0000 mov    DWORD PTR [eax+0xbf08],edx
0x493c2c 89b00cbf0000 mov    DWORD PTR [eax+0xbf0c],esi
0x493c32 898810bf0000 mov    DWORD PTR [eax+0xbf10],ecx
0x493c38 bab0434900 mov    edx,0x4943b0
0x493c3d 8990780f0000 mov    DWORD PTR [eax+0xf78],edx
0x493c43 89b07c0f0000 mov    DWORD PTR [eax+0xf7c],esi
0x493c49 8988800f0000 mov    DWORD PTR [eax+0xf80],ecx
0x493c4f bab0434900 mov    edx,0x4943b0
0x493c54 8990680f0000 mov    DWORD PTR [eax+0xf68],edx
0x493c5a 89b06c0f0000 mov    DWORD PTR [eax+0xf6c],esi
0x493c60 8988700f0000 mov    DWORD PTR [eax+0xf70],ecx
0x493c66 bab0434900 mov    edx,0x4943b0
0x493c6b 8990580f0000 mov    DWORD PTR [eax+0xf58],edx
0x493c71 89b05c0f0000 mov    DWORD PTR [eax+0xf5c],esi
0x493c77 bab0434900 mov    edx,0x4943b0
0x493c7c 8988600f0000 mov    DWORD PTR [eax+0xf60],ecx
0x493c82 899018100000 mov    DWORD PTR [eax+0x1018],edx
0x493c88 89b01c100000 mov    DWORD PTR [eax+0x101c],esi
0x493c8e 898820100000 mov    DWORD PTR [eax+0x1020],ecx
0x493c94 ba805a4900 mov    edx,0x495a80
0x493c99 8990c80f0000 mov    DWORD PTR [eax+0xfc8],edx
0x493c9f 89b0cc0f0000 mov    DWORD PTR [eax+0xfcc],esi
0x493ca5 8988d00f0000 mov    DWORD PTR [eax+0xfd0],ecx
0x493cab bab0434900 mov    edx,0x4943b0
0x493cb0 899098100000 mov    DWORD PTR [eax+0x1098],edx
0x493cb6 89b09c100000 mov    DWORD PTR [eax+0x109c],esi
0x493cbc 8988a0100000 mov    DWORD PTR [eax+0x10a0],ecx
0x493cc2 bab0434900 mov    edx,0x4943b0
0x493cc7 899088100000 mov    DWORD PTR [eax+0x1088],edx
0x493ccd 89b08c100000 mov    DWORD PTR [eax+0x108c],esi
0x493cd3 898890100000 mov    DWORD PTR [eax+0x1090],ecx
0x493cd9 bab0434900 mov    edx,0x4943b0
0x493cde 8990a8100000 mov    DWORD PTR [eax+0x10a8],edx
0x493ce4 89b0ac100000 mov    DWORD PTR [eax+0x10ac],esi
0x493cea 8988b0100000 mov    DWORD PTR [eax+0x10b0],ecx
0x493cf0 ba10474900 mov    edx,0x494710
0x493cf5 8990f8100000 mov    DWORD PTR [eax+0x10f8],edx
0x493cfb 89b0fc100000 mov    DWORD PTR [eax+0x10fc],esi
0x493d01 898800110000 mov    DWORD PTR [eax+0x1100],ecx
0x493d07 ba10474900 mov    edx,0x494710
0x493d0c 899008110000 mov    DWORD PTR [eax+0x1108],edx
0x493d12 89b00c110000 mov    DWORD PTR [eax+0x110c],esi
0x493d18 898810110000 mov    DWORD PTR [eax+0x1110],ecx
0x493d1e ba10474900 mov    edx,0x494710
0x493d23 899018110000 mov    DWORD PTR [eax+0x1118],edx
0x493d29 89b01c110000 mov    DWORD PTR [eax+0x111c],esi
0x493d2f 898820110000 mov    DWORD PTR [eax+0x1120],ecx
0x493d35 ba10474900 mov    edx,0x494710
0x493d3a 899028110000 mov    DWORD PTR [eax+0x1128],edx
0x493d40 89b02c110000 mov    DWORD PTR [eax+0x112c],esi
0x493d46 898830110000 mov    DWORD PTR [eax+0x1130],ecx
0x493d4c ba10474900 mov    edx,0x494710
0x493d51 899038110000 mov    DWORD PTR [eax+0x1138],edx
0x493d57 89b03c110000 mov    DWORD PTR [eax+0x113c],esi
0x493d5d 898840110000 mov    DWORD PTR [eax+0x1140],ecx
0x493d63 bab0434900 mov    edx,0x4943b0
0x493d68 899048110000 mov    DWORD PTR [eax+0x1148],edx
0x493d6e 89b04c110000 mov    DWORD PTR [eax+0x114c],esi
0x493d74 898850110000 mov    DWORD PTR [eax+0x1150],ecx
0x493d7a ba905b4900 mov    edx,0x495b90
0x493d7f 899058110000 mov    DWORD PTR [eax+0x1158],edx
0x493d85 89b05c110000 mov    DWORD PTR [eax+0x115c],esi
0x493d8b 898860110000 mov    DWORD PTR [eax+0x1160],ecx
0x493d91 ba505c4900 mov    edx,0x495c50
0x493d96 899068110000 mov    DWORD PTR [eax+0x1168],edx
0x493d9c 89b06c110000 mov    DWORD PTR [eax+0x116c],esi
0x493da2 898870110000 mov    DWORD PTR [eax+0x1170],ecx
0x493da8 bae05f4900 mov    edx,0x495fe0
0x493dad 899078110000 mov    DWORD PTR [eax+0x1178],edx
0x493db3 89b07c110000 mov    DWORD PTR [eax+0x117c],esi
0x493db9 898880110000 mov    DWORD PTR [eax+0x1180],ecx
0x493dbf baf05f4900 mov    edx,0x495ff0
0x493dc4 899088110000 mov    DWORD PTR [eax+0x1188],edx
0x493dca 89b08c110000 mov    DWORD PTR [eax+0x118c],esi
0x493dd0 898890110000 mov    DWORD PTR [eax+0x1190],ecx
0x493dd6 ba70624900 mov    edx,0x496270
0x493ddb 8990a8110000 mov    DWORD PTR [eax+0x11a8],edx
0x493de1 89b0ac110000 mov    DWORD PTR [eax+0x11ac],esi
0x493de7 8988b0110000 mov    DWORD PTR [eax+0x11b0],ecx
0x493ded baf0624900 mov    edx,0x4962f0
0x493df2 899098110000 mov    DWORD PTR [eax+0x1198],edx
0x493df8 89b09c110000 mov    DWORD PTR [eax+0x119c],esi
0x493dfe 8988a0110000 mov    DWORD PTR [eax+0x11a0],ecx
0x493e04 ba70524900 mov    edx,0x495270
0x493e09 8990e8110000 mov    DWORD PTR [eax+0x11e8],edx
0x493e0f 89b0ec110000 mov    DWORD PTR [eax+0x11ec],esi
0x493e15 8988f0110000 mov    DWORD PTR [eax+0x11f0],ecx
0x493e1b ba70524900 mov    edx,0x495270
0x493e20 8990f8110000 mov    DWORD PTR [eax+0x11f8],edx
0x493e26 89b0fc110000 mov    DWORD PTR [eax+0x11fc],esi
0x493e2c 898800120000 mov    DWORD PTR [eax+0x1200],ecx
0x493e32 ba70524900 mov    edx,0x495270
0x493e37 899008120000 mov    DWORD PTR [eax+0x1208],edx
0x493e3d 89b00c120000 mov    DWORD PTR [eax+0x120c],esi
0x493e43 898810120000 mov    DWORD PTR [eax+0x1210],ecx
0x493e49 ba80634900 mov    edx,0x496380
0x493e4e 899058120000 mov    DWORD PTR [eax+0x1258],edx
0x493e54 89b05c120000 mov    DWORD PTR [eax+0x125c],esi
0x493e5a 898860120000 mov    DWORD PTR [eax+0x1260],ecx
0x493e60 bab0434900 mov    edx,0x4943b0
0x493e65 899078120000 mov    DWORD PTR [eax+0x1278],edx
0x493e6b 89b07c120000 mov    DWORD PTR [eax+0x127c],esi
0x493e71 898880120000 mov    DWORD PTR [eax+0x1280],ecx
0x493e77 bab0434900 mov    edx,0x4943b0
0x493e7c 899088120000 mov    DWORD PTR [eax+0x1288],edx
0x493e82 89b08c120000 mov    DWORD PTR [eax+0x128c],esi
0x493e88 898890120000 mov    DWORD PTR [eax+0x1290],ecx
0x493e8e baf0454900 mov    edx,0x4945f0
0x493e93 899098120000 mov    DWORD PTR [eax+0x1298],edx
0x493e99 89b09c120000 mov    DWORD PTR [eax+0x129c],esi
0x493e9f 8988a0120000 mov    DWORD PTR [eax+0x12a0],ecx
0x493ea5 baf0454900 mov    edx,0x4945f0
0x493eaa 8990a8120000 mov    DWORD PTR [eax+0x12a8],edx
0x493eb0 89b0ac120000 mov    DWORD PTR [eax+0x12ac],esi
0x493eb6 8988b0120000 mov    DWORD PTR [eax+0x12b0],ecx
0x493ebc baf0454900 mov    edx,0x4945f0
0x493ec1 8990b8120000 mov    DWORD PTR [eax+0x12b8],edx
0x493ec7 89b0bc120000 mov    DWORD PTR [eax+0x12bc],esi
0x493ecd 8988c0120000 mov    DWORD PTR [eax+0x12c0],ecx
0x493ed3 baf0454900 mov    edx,0x4945f0
0x493ed8 8990c8120000 mov    DWORD PTR [eax+0x12c8],edx
0x493ede 89b0cc120000 mov    DWORD PTR [eax+0x12cc],esi
0x493ee4 8988d0120000 mov    DWORD PTR [eax+0x12d0],ecx
0x493eea ba50654900 mov    edx,0x496550
0x493eef 899018bf0000 mov    DWORD PTR [eax+0xbf18],edx
0x493ef5 89b01cbf0000 mov    DWORD PTR [eax+0xbf1c],esi
0x493efb 898820bf0000 mov    DWORD PTR [eax+0xbf20],ecx
0x493f01 bab0654900 mov    edx,0x4965b0
0x493f06 8990d8120000 mov    DWORD PTR [eax+0x12d8],edx
0x493f0c 89b0dc120000 mov    DWORD PTR [eax+0x12dc],esi
0x493f12 8988e0120000 mov    DWORD PTR [eax+0x12e0],ecx
0x493f18 baa0664900 mov    edx,0x4966a0
0x493f1d 8990e8120000 mov    DWORD PTR [eax+0x12e8],edx
0x493f23 89b0ec120000 mov    DWORD PTR [eax+0x12ec],esi
0x493f29 8988f0120000 mov    DWORD PTR [eax+0x12f0],ecx
0x493f2f ba206a4900 mov    edx,0x496a20
0x493f34 899038130000 mov    DWORD PTR [eax+0x1338],edx
0x493f3a 89b03c130000 mov    DWORD PTR [eax+0x133c],esi
0x493f40 898840130000 mov    DWORD PTR [eax+0x1340],ecx
0x493f46 ba407d4900 mov    edx,0x497d40
0x493f4b 899048130000 mov    DWORD PTR [eax+0x1348],edx
0x493f51 89b04c130000 mov    DWORD PTR [eax+0x134c],esi
0x493f57 898850130000 mov    DWORD PTR [eax+0x1350],ecx
0x493f5d ba606f4900 mov    edx,0x496f60
0x493f62 8990a8130000 mov    DWORD PTR [eax+0x13a8],edx
0x493f68 89b0ac130000 mov    DWORD PTR [eax+0x13ac],esi
0x493f6e 8988b0130000 mov    DWORD PTR [eax+0x13b0],ecx
0x493f74 ba70524900 mov    edx,0x495270
0x493f79 8990b8130000 mov    DWORD PTR [eax+0x13b8],edx
0x493f7f 89b0bc130000 mov    DWORD PTR [eax+0x13bc],esi
0x493f85 8988c0130000 mov    DWORD PTR [eax+0x13c0],ecx
0x493f8b ba70524900 mov    edx,0x495270
0x493f90 8990c8130000 mov    DWORD PTR [eax+0x13c8],edx
0x493f96 89b0cc130000 mov    DWORD PTR [eax+0x13cc],esi
0x493f9c 8988d0130000 mov    DWORD PTR [eax+0x13d0],ecx
0x493fa2 bae0704900 mov    edx,0x4970e0
0x493fa7 8990e8130000 mov    DWORD PTR [eax+0x13e8],edx
0x493fad 89b0ec130000 mov    DWORD PTR [eax+0x13ec],esi
0x493fb3 8988f0130000 mov    DWORD PTR [eax+0x13f0],ecx
0x493fb9 bab0434900 mov    edx,0x4943b0
0x493fbe 8990f8130000 mov    DWORD PTR [eax+0x13f8],edx
0x493fc4 89b0fc130000 mov    DWORD PTR [eax+0x13fc],esi
0x493fca 898800140000 mov    DWORD PTR [eax+0x1400],ecx
0x493fd0 bab0434900 mov    edx,0x4943b0
0x493fd5 899008140000 mov    DWORD PTR [eax+0x1408],edx
0x493fdb 89b00c140000 mov    DWORD PTR [eax+0x140c],esi
0x493fe1 898810140000 mov    DWORD PTR [eax+0x1410],ecx
0x493fe7 bab0434900 mov    edx,0x4943b0
0x493fec 899038bf0000 mov    DWORD PTR [eax+0xbf38],edx
0x493ff2 89b03cbf0000 mov    DWORD PTR [eax+0xbf3c],esi
0x493ff8 898840bf0000 mov    DWORD PTR [eax+0xbf40],ecx
0x493ffe bab0434900 mov    edx,0x4943b0
0x494003 899068140000 mov    DWORD PTR [eax+0x1468],edx
0x494009 89b06c140000 mov    DWORD PTR [eax+0x146c],esi
0x49400f 898870140000 mov    DWORD PTR [eax+0x1470],ecx
0x494015 bab0434900 mov    edx,0x4943b0
0x49401a 899078140000 mov    DWORD PTR [eax+0x1478],edx
0x494020 89b07c140000 mov    DWORD PTR [eax+0x147c],esi
0x494026 898880140000 mov    DWORD PTR [eax+0x1480],ecx
0x49402c bab0434900 mov    edx,0x4943b0
0x494031 899088140000 mov    DWORD PTR [eax+0x1488],edx
0x494037 89b08c140000 mov    DWORD PTR [eax+0x148c],esi
0x49403d 898890140000 mov    DWORD PTR [eax+0x1490],ecx
0x494043 bab0434900 mov    edx,0x4943b0
0x494048 899098140000 mov    DWORD PTR [eax+0x1498],edx
0x49404e 89b09c140000 mov    DWORD PTR [eax+0x149c],esi
0x494054 8988a0140000 mov    DWORD PTR [eax+0x14a0],ecx
0x49405a bab0434900 mov    edx,0x4943b0
0x49405f 899038140000 mov    DWORD PTR [eax+0x1438],edx
0x494065 89b03c140000 mov    DWORD PTR [eax+0x143c],esi
0x49406b 898840140000 mov    DWORD PTR [eax+0x1440],ecx
0x494071 bab0434900 mov    edx,0x4943b0
0x494076 899048140000 mov    DWORD PTR [eax+0x1448],edx
0x49407c 89b04c140000 mov    DWORD PTR [eax+0x144c],esi
0x494082 898850140000 mov    DWORD PTR [eax+0x1450],ecx
0x494088 ba60434900 mov    edx,0x494360
0x49408d 8990a8140000 mov    DWORD PTR [eax+0x14a8],edx
0x494093 89b0ac140000 mov    DWORD PTR [eax+0x14ac],esi
0x494099 8988b0140000 mov    DWORD PTR [eax+0x14b0],ecx
0x49409f bab0434900 mov    edx,0x4943b0
0x4940a4 8990b8140000 mov    DWORD PTR [eax+0x14b8],edx
0x4940aa 89b0bc140000 mov    DWORD PTR [eax+0x14bc],esi
0x4940b0 8988c0140000 mov    DWORD PTR [eax+0x14c0],ecx
0x4940b6 bab0434900 mov    edx,0x4943b0
0x4940bb 8990c8140000 mov    DWORD PTR [eax+0x14c8],edx
0x4940c1 89b0cc140000 mov    DWORD PTR [eax+0x14cc],esi
0x4940c7 8988d0140000 mov    DWORD PTR [eax+0x14d0],ecx
0x4940cd bab0434900 mov    edx,0x4943b0
0x4940d2 8990d8140000 mov    DWORD PTR [eax+0x14d8],edx
0x4940d8 89b0dc140000 mov    DWORD PTR [eax+0x14dc],esi
0x4940de 8988e0140000 mov    DWORD PTR [eax+0x14e0],ecx
0x4940e4 bab0434900 mov    edx,0x4943b0
0x4940e9 8990e8140000 mov    DWORD PTR [eax+0x14e8],edx
0x4940ef 89b0ec140000 mov    DWORD PTR [eax+0x14ec],esi
0x4940f5 8988f0140000 mov    DWORD PTR [eax+0x14f0],ecx
0x4940fb ba90774900 mov    edx,0x497790
0x494100 8990f8140000 mov    DWORD PTR [eax+0x14f8],edx
0x494106 89b0fc140000 mov    DWORD PTR [eax+0x14fc],esi
0x49410c 898800150000 mov    DWORD PTR [eax+0x1500],ecx
0x494112 bab0434900 mov    edx,0x4943b0
0x494117 899008150000 mov    DWORD PTR [eax+0x1508],edx
0x49411d 89b00c150000 mov    DWORD PTR [eax+0x150c],esi
0x494123 898810150000 mov    DWORD PTR [eax+0x1510],ecx
0x494129 bab0434900 mov    edx,0x4943b0
0x49412e 899028150000 mov    DWORD PTR [eax+0x1528],edx
0x494134 89b02c150000 mov    DWORD PTR [eax+0x152c],esi
0x49413a 898830150000 mov    DWORD PTR [eax+0x1530],ecx
0x494140 bab0434900 mov    edx,0x4943b0
0x494145 899038150000 mov    DWORD PTR [eax+0x1538],edx
0x49414b 89b03c150000 mov    DWORD PTR [eax+0x153c],esi
0x494151 898840150000 mov    DWORD PTR [eax+0x1540],ecx
0x494157 bab0434900 mov    edx,0x4943b0
0x49415c 899048150000 mov    DWORD PTR [eax+0x1548],edx
0x494162 89b04c150000 mov    DWORD PTR [eax+0x154c],esi
0x494168 898850150000 mov    DWORD PTR [eax+0x1550],ecx
0x49416e bab0434900 mov    edx,0x4943b0
0x494173 899078150000 mov    DWORD PTR [eax+0x1578],edx
0x494179 89b07c150000 mov    DWORD PTR [eax+0x157c],esi
0x49417f 898880150000 mov    DWORD PTR [eax+0x1580],ecx
0x494185 bab0434900 mov    edx,0x4943b0
0x49418a 899088150000 mov    DWORD PTR [eax+0x1588],edx
0x494190 89b08c150000 mov    DWORD PTR [eax+0x158c],esi
0x494196 898890150000 mov    DWORD PTR [eax+0x1590],ecx
0x49419c bab0434900 mov    edx,0x4943b0
0x4941a1 899098150000 mov    DWORD PTR [eax+0x1598],edx
0x4941a7 89b09c150000 mov    DWORD PTR [eax+0x159c],esi
0x4941ad 8988a0150000 mov    DWORD PTR [eax+0x15a0],ecx
0x4941b3 bab0434900 mov    edx,0x4943b0
0x4941b8 8990a8150000 mov    DWORD PTR [eax+0x15a8],edx
0x4941be 89b0ac150000 mov    DWORD PTR [eax+0x15ac],esi
0x4941c4 8988b0150000 mov    DWORD PTR [eax+0x15b0],ecx
0x4941ca bab0434900 mov    edx,0x4943b0
0x4941cf 899018160000 mov    DWORD PTR [eax+0x1618],edx
0x4941d5 89b01c160000 mov    DWORD PTR [eax+0x161c],esi
0x4941db 898820160000 mov    DWORD PTR [eax+0x1620],ecx
0x4941e1 bab0434900 mov    edx,0x4943b0
0x4941e6 899028160000 mov    DWORD PTR [eax+0x1628],edx
0x4941ec 89b02c160000 mov    DWORD PTR [eax+0x162c],esi
0x4941f2 898830160000 mov    DWORD PTR [eax+0x1630],ecx
0x4941f8 bab0434900 mov    edx,0x4943b0
0x4941fd 899008160000 mov    DWORD PTR [eax+0x1608],edx
0x494203 89b00c160000 mov    DWORD PTR [eax+0x160c],esi
0x494209 898810160000 mov    DWORD PTR [eax+0x1610],ecx
0x49420f bab0434900 mov    edx,0x4943b0
0x494214 899058150000 mov    DWORD PTR [eax+0x1558],edx
0x49421a 89b05c150000 mov    DWORD PTR [eax+0x155c],esi
0x494220 898860150000 mov    DWORD PTR [eax+0x1560],ecx
0x494226 bab0434900 mov    edx,0x4943b0
0x49422b 899058140000 mov    DWORD PTR [eax+0x1458],edx
0x494231 89b05c140000 mov    DWORD PTR [eax+0x145c],esi
0x494237 898860140000 mov    DWORD PTR [eax+0x1460],ecx
0x49423d ba80464900 mov    edx,0x494680
0x494242 899038160000 mov    DWORD PTR [eax+0x1638],edx
0x494248 89b03c160000 mov    DWORD PTR [eax+0x163c],esi
0x49424e 898840160000 mov    DWORD PTR [eax+0x1640],ecx
0x494254 ba80464900 mov    edx,0x494680
0x494259 899048160000 mov    DWORD PTR [eax+0x1648],edx
0x49425f 89b04c160000 mov    DWORD PTR [eax+0x164c],esi
0x494265 898850160000 mov    DWORD PTR [eax+0x1650],ecx
0x49426b bab0434900 mov    edx,0x4943b0
0x494270 899068160000 mov    DWORD PTR [eax+0x1668],edx
0x494276 89b06c160000 mov    DWORD PTR [eax+0x166c],esi
0x49427c 898870160000 mov    DWORD PTR [eax+0x1670],ecx
0x494282 bab0434900 mov    edx,0x4943b0
0x494287 8990a8160000 mov    DWORD PTR [eax+0x16a8],edx
0x49428d 89b0ac160000 mov    DWORD PTR [eax+0x16ac],esi
0x494293 8988b0160000 mov    DWORD PTR [eax+0x16b0],ecx
0x494299 bab0434900 mov    edx,0x4943b0
0x49429e 899078160000 mov    DWORD PTR [eax+0x1678],edx
0x4942a4 89b07c160000 mov    DWORD PTR [eax+0x167c],esi
0x4942aa 898880160000 mov    DWORD PTR [eax+0x1680],ecx
0x4942b0 bab0434900 mov    edx,0x4943b0
0x4942b5 899088160000 mov    DWORD PTR [eax+0x1688],edx
0x4942bb 89b08c160000 mov    DWORD PTR [eax+0x168c],esi
0x4942c1 898890160000 mov    DWORD PTR [eax+0x1690],ecx
0x4942c7 bab0434900 mov    edx,0x4943b0
0x4942cc 8990c8160000 mov    DWORD PTR [eax+0x16c8],edx
0x4942d2 89b0cc160000 mov    DWORD PTR [eax+0x16cc],esi
0x4942d8 8988d0160000 mov    DWORD PTR [eax+0x16d0],ecx
0x4942de bab0434900 mov    edx,0x4943b0
0x4942e3 8990d8160000 mov    DWORD PTR [eax+0x16d8],edx
0x4942e9 89b0dc160000 mov    DWORD PTR [eax+0x16dc],esi
0x4942ef 8988e0160000 mov    DWORD PTR [eax+0x16e0],ecx
0x4942f5 bab0434900 mov    edx,0x4943b0
0x4942fa 8990e8160000 mov    DWORD PTR [eax+0x16e8],edx
0x494300 89b0ec160000 mov    DWORD PTR [eax+0x16ec],esi
0x494306 8988f0160000 mov    DWORD PTR [eax+0x16f0],ecx
0x49430c bab0434900 mov    edx,0x4943b0
0x494311 899008170000 mov    DWORD PTR [eax+0x1708],edx
0x494317 89b00c170000 mov    DWORD PTR [eax+0x170c],esi
0x49431d 898810170000 mov    DWORD PTR [eax+0x1710],ecx
0x494323 bab0434900 mov    edx,0x4943b0
0x494328 8990c8110000 mov    DWORD PTR [eax+0x11c8],edx
0x49432e 89b0cc110000 mov    DWORD PTR [eax+0x11cc],esi
0x494334 8988d0110000 mov    DWORD PTR [eax+0x11d0],ecx
0x49433a bab0434900 mov    edx,0x4943b0
0x49433f 8990d8110000 mov    DWORD PTR [eax+0x11d8],edx
0x494345 5f pop    edi
0x494346 89b0dc110000 mov    DWORD PTR [eax+0x11dc],esi
0x49434c 5e pop    esi
0x49434d 8988e0110000 mov    DWORD PTR [eax+0x11e0],ecx
0x494353 5b pop    ebx
0x494354 c3 ret

; client_constructor_prefix 0x48ab70..0x48acb6 raw=0x89f70 sha256=51add83b2143d3f58c32b3ed0191b984a01fce499bddce8ee5b5a119e1bf1c9f
0x48ab70 55 push   ebp
0x48ab71 8bec mov    ebp,esp
0x48ab73 6aff push   0xffffffff
0x48ab75 683da79300 push   0x93a73d
0x48ab7a 64a100000000 mov    eax,fs:0x0
0x48ab80 50 push   eax
0x48ab81 83ec10 sub    esp,0x10
0x48ab84 53 push   ebx
0x48ab85 56 push   esi
0x48ab86 57 push   edi
0x48ab87 a1201fd600 mov    eax,ds:0xd61f20
0x48ab8c 33c5 xor    eax,ebp
0x48ab8e 50 push   eax
0x48ab8f 8d45f4 lea    eax,[ebp-0xc]
0x48ab92 64a300000000 mov    fs:0x0,eax
0x48ab98 8b7d08 mov    edi,DWORD PTR [ebp+0x8]
0x48ab9b c707185bc000 mov    DWORD PTR [edi],0xc05b18
0x48aba1 893d1813fb00 mov    DWORD PTR ds:0xfb1318,edi
0x48aba7 33db xor    ebx,ebx
0x48aba9 895dfc mov    DWORD PTR [ebp-0x4],ebx
0x48abac f6052888fb0001 test   BYTE PTR ds:0xfb8828,0x1
0x48abb3 8d7301 lea    esi,[ebx+0x1]
0x48abb6 751c jne    0x48abd4
0x48abb8 09352888fb00 or     DWORD PTR ds:0xfb8828,esi
0x48abbe c645fc01 mov    BYTE PTR [ebp-0x4],0x1
0x48abc2 e8894c0c00 call   0x54f850
0x48abc7 6880d5bc00 push   0xbcd580
0x48abcc e849774000 call   0x89231a
0x48abd1 83c404 add    esp,0x4
0x48abd4 66391dba92fb00 cmp    WORD PTR ds:0xfb92ba,bx
0x48abdb 7e31 jle    0x48ac0e
0x48abdd f6052888fb0001 test   BYTE PTR ds:0xfb8828,0x1
0x48abe4 751c jne    0x48ac02
0x48abe6 09352888fb00 or     DWORD PTR ds:0xfb8828,esi
0x48abec c645fc02 mov    BYTE PTR [ebp-0x4],0x2
0x48abf0 e85b4c0c00 call   0x54f850
0x48abf5 6880d5bc00 push   0xbcd580
0x48abfa e81b774000 call   0x89231a
0x48abff 83c404 add    esp,0x4
0x48ac02 0fbf05ba92fb00 movsx  eax,WORD PTR ds:0xfb92ba
0x48ac09 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x48ac0c eb07 jmp    0x48ac15
0x48ac0e c745f000030000 mov    DWORD PTR [ebp-0x10],0x300
0x48ac15 f6052888fb0001 test   BYTE PTR ds:0xfb8828,0x1
0x48ac1c 751c jne    0x48ac3a
0x48ac1e 09352888fb00 or     DWORD PTR ds:0xfb8828,esi
0x48ac24 c645fc03 mov    BYTE PTR [ebp-0x4],0x3
0x48ac28 e8234c0c00 call   0x54f850
0x48ac2d 6880d5bc00 push   0xbcd580
0x48ac32 e8e3764000 call   0x89231a
0x48ac37 83c404 add    esp,0x4
0x48ac3a 66391daa92fb00 cmp    WORD PTR ds:0xfb92aa,bx
0x48ac41 7e2e jle    0x48ac71
0x48ac43 f6052888fb0001 test   BYTE PTR ds:0xfb8828,0x1
0x48ac4a 751c jne    0x48ac68
0x48ac4c 09352888fb00 or     DWORD PTR ds:0xfb8828,esi
0x48ac52 c645fc04 mov    BYTE PTR [ebp-0x4],0x4
0x48ac56 e8f54b0c00 call   0x54f850
0x48ac5b 6880d5bc00 push   0xbcd580
0x48ac60 e8b5764000 call   0x89231a
0x48ac65 83c404 add    esp,0x4
0x48ac68 0fbf0daa92fb00 movsx  ecx,WORD PTR ds:0xfb92aa
0x48ac6f eb05 jmp    0x48ac76
0x48ac71 b900040000 mov    ecx,0x400
0x48ac76 8b55f0 mov    edx,DWORD PTR [ebp-0x10]
0x48ac79 8d7708 lea    esi,[edi+0x8]
0x48ac7c e81f3e2500 call   0x6deaa0
0x48ac81 8d8748010000 lea    eax,[edi+0x148]
0x48ac87 e8f4963700 call   0x804380
0x48ac8c c78700020000385bc000 mov    DWORD PTR [edi+0x200],0xc05b38
0x48ac96 c645fc07 mov    BYTE PTR [ebp-0x4],0x7
0x48ac9a c700ec5ac000 mov    DWORD PTR [eax],0xc05aec
0x48aca0 c7079c5ac000 mov    DWORD PTR [edi],0xc05a9c
0x48aca6 c706a45ac000 mov    DWORD PTR [esi],0xc05aa4
0x48acac c78700020000045bc000 mov    DWORD PTR [edi+0x200],0xc05b04

; callback_holder_constructor 0x804380..0x804424 raw=0x403780 sha256=13add9719d6c8ac92e0d57ea1c66d7b82bf80e3691cf7414fd30602b6639e8da
0x804380 33c9 xor    ecx,ecx
0x804382 c700ec15c500 mov    DWORD PTR [eax],0xc515ec
0x804388 894804 mov    DWORD PTR [eax+0x4],ecx
0x80438b 894808 mov    DWORD PTR [eax+0x8],ecx
0x80438e 89480c mov    DWORD PTR [eax+0xc],ecx
0x804391 894810 mov    DWORD PTR [eax+0x10],ecx
0x804394 894814 mov    DWORD PTR [eax+0x14],ecx
0x804397 894818 mov    DWORD PTR [eax+0x18],ecx
0x80439a 89481c mov    DWORD PTR [eax+0x1c],ecx
0x80439d 894824 mov    DWORD PTR [eax+0x24],ecx
0x8043a0 894828 mov    DWORD PTR [eax+0x28],ecx
0x8043a3 6689482c mov    WORD PTR [eax+0x2c],cx
0x8043a7 894830 mov    DWORD PTR [eax+0x30],ecx
0x8043aa 894834 mov    DWORD PTR [eax+0x34],ecx
0x8043ad 894838 mov    DWORD PTR [eax+0x38],ecx
0x8043b0 89483c mov    DWORD PTR [eax+0x3c],ecx
0x8043b3 894840 mov    DWORD PTR [eax+0x40],ecx
0x8043b6 894844 mov    DWORD PTR [eax+0x44],ecx
0x8043b9 894848 mov    DWORD PTR [eax+0x48],ecx
0x8043bc 894850 mov    DWORD PTR [eax+0x50],ecx
0x8043bf 894854 mov    DWORD PTR [eax+0x54],ecx
0x8043c2 66894858 mov    WORD PTR [eax+0x58],cx
0x8043c6 89485c mov    DWORD PTR [eax+0x5c],ecx
0x8043c9 894860 mov    DWORD PTR [eax+0x60],ecx
0x8043cc 894864 mov    DWORD PTR [eax+0x64],ecx
0x8043cf 894868 mov    DWORD PTR [eax+0x68],ecx
0x8043d2 89486c mov    DWORD PTR [eax+0x6c],ecx
0x8043d5 894870 mov    DWORD PTR [eax+0x70],ecx
0x8043d8 894874 mov    DWORD PTR [eax+0x74],ecx
0x8043db 894878 mov    DWORD PTR [eax+0x78],ecx
0x8043de 89487c mov    DWORD PTR [eax+0x7c],ecx
0x8043e1 898880000000 mov    DWORD PTR [eax+0x80],ecx
0x8043e7 898884000000 mov    DWORD PTR [eax+0x84],ecx
0x8043ed 898888000000 mov    DWORD PTR [eax+0x88],ecx
0x8043f3 888890000000 mov    BYTE PTR [eax+0x90],cl
0x8043f9 898894000000 mov    DWORD PTR [eax+0x94],ecx
0x8043ff 898898000000 mov    DWORD PTR [eax+0x98],ecx
0x804405 89889c000000 mov    DWORD PTR [eax+0x9c],ecx
0x80440b 8988a4000000 mov    DWORD PTR [eax+0xa4],ecx
0x804411 8988a8000000 mov    DWORD PTR [eax+0xa8],ecx
0x804417 8988ac000000 mov    DWORD PTR [eax+0xac],ecx
0x80441d 8988b0000000 mov    DWORD PTR [eax+0xb0],ecx
0x804423 c3 ret

; client_initialize 0x48be50..0x48c16a raw=0x8b250 sha256=51be5f5973ed4d08dae900f0362bbaac17b3daf72afafdde6aa9dae45c697868
0x48be50 55 push   ebp
0x48be51 8bec mov    ebp,esp
0x48be53 83e4f8 and    esp,0xfffffff8
0x48be56 6aff push   0xffffffff
0x48be58 68caa09400 push   0x94a0ca
0x48be5d 64a100000000 mov    eax,fs:0x0
0x48be63 50 push   eax
0x48be64 81ec60010000 sub    esp,0x160
0x48be6a a1201fd600 mov    eax,ds:0xd61f20
0x48be6f 33c4 xor    eax,esp
0x48be71 89842458010000 mov    DWORD PTR [esp+0x158],eax
0x48be78 53 push   ebx
0x48be79 56 push   esi
0x48be7a 57 push   edi
0x48be7b a1201fd600 mov    eax,ds:0xd61f20
0x48be80 33c4 xor    eax,esp
0x48be82 50 push   eax
0x48be83 8d842470010000 lea    eax,[esp+0x170]
0x48be8a 64a300000000 mov    fs:0x0,eax
0x48be90 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x48be93 8d44241c lea    eax,[esp+0x1c]
0x48be97 50 push   eax
0x48be98 ff15f820bd00 call   DWORD PTR ds:0xbd20f8
0x48be9e 0fb74c2428 movzx  ecx,WORD PTR [esp+0x28]
0x48bea3 0fb7542426 movzx  edx,WORD PTR [esp+0x26]
0x48bea8 0fb7442424 movzx  eax,WORD PTR [esp+0x24]
0x48bead 51 push   ecx
0x48beae 0fb74c2426 movzx  ecx,WORD PTR [esp+0x26]
0x48beb3 52 push   edx
0x48beb4 0fb7542426 movzx  edx,WORD PTR [esp+0x26]
0x48beb9 50 push   eax
0x48beba 0fb7442428 movzx  eax,WORD PTR [esp+0x28]
0x48bebf 51 push   ecx
0x48bec0 52 push   edx
0x48bec1 50 push   eax
0x48bec2 687456c000 push   0xc05674
0x48bec7 e8341e2600 call   0x6edd00
0x48becc 83c41c add    esp,0x1c
0x48becf e88c950000 call   0x495460
0x48bed4 8d4c242c lea    ecx,[esp+0x2c]
0x48bed8 51 push   ecx
0x48bed9 c744243014010000 mov    DWORD PTR [esp+0x30],0x114
0x48bee1 ff15f420bd00 call   DWORD PTR ds:0xbd20f4
0x48bee7 837c243005 cmp    DWORD PTR [esp+0x30],0x5
0x48beec 0f8394000000 jae    0x48bf86
0x48bef2 f6052c5bfe0001 test   BYTE PTR ds:0xfe5b2c,0x1
0x48bef9 7529 jne    0x48bf24
0x48befb 830d2c5bfe0001 or     DWORD PTR ds:0xfe5b2c,0x1
0x48bf02 680c5bfe00 push   0xfe5b0c
0x48bf07 c784247c01000000000000 mov    DWORD PTR [esp+0x17c],0x0
0x48bf12 e8298d0f00 call   0x584c40
0x48bf17 6870f3bc00 push   0xbcf370
0x48bf1c e8f9634000 call   0x89231a
0x48bf21 83c404 add    esp,0x4
0x48bf24 8d542414 lea    edx,[esp+0x14]
0x48bf28 52 push   edx
0x48bf29 8d44241c lea    eax,[esp+0x1c]
0x48bf2d b90c5bfe00 mov    ecx,0xfe5b0c
0x48bf32 c74424188f010000 mov    DWORD PTR [esp+0x18],0x18f
0x48bf3a e8b1810e00 call   0x5740f0
0x48bf3f 8b442418 mov    eax,DWORD PTR [esp+0x18]
0x48bf43 3b05105bfe00 cmp    eax,DWORD PTR ds:0xfe5b10
0x48bf49 740d je     0x48bf58
0x48bf4b 83c010 add    eax,0x10
0x48bf4e 83781408 cmp    DWORD PTR [eax+0x14],0x8
0x48bf52 720a jb     0x48bf5e
0x48bf54 8b00 mov    eax,DWORD PTR [eax]
0x48bf56 eb06 jmp    0x48bf5e
0x48bf58 cc int3
0x48bf59 b8fcd1be00 mov    eax,0xbed1fc
0x48bf5e 8b4b28 mov    ecx,DWORD PTR [ebx+0x28]
0x48bf61 6a00 push   0x0
0x48bf63 51 push   ecx
0x48bf64 50 push   eax
0x48bf65 6a00 push   0x0
0x48bf67 ff158025bd00 call   DWORD PTR ds:0xbd2580
0x48bf6d 689c56c000 push   0xc0569c
0x48bf72 8bd3 mov    edx,ebx
0x48bf74 e8872d2500 call   0x6ded00
0x48bf79 83c404 add    esp,0x4
0x48bf7c b805400080 mov    eax,0x80004005
0x48bf81 e9be010000 jmp    0x48c144
0x48bf86 8d9374bf0000 lea    edx,[ebx+0xbf74]
0x48bf8c 52 push   edx
0x48bf8d 8d8370bf0000 lea    eax,[ebx+0xbf70]
0x48bf93 50 push   eax
0x48bf94 8d8b78bf0000 lea    ecx,[ebx+0xbf78]
0x48bf9a e8f1d9ffff call   0x489990
0x48bf9f 83c408 add    esp,0x8
0x48bfa2 85c0 test   eax,eax
0x48bfa4 7563 jne    0x48c009
0x48bfa6 c744241880010000 mov    DWORD PTR [esp+0x18],0x180
0x48bfae e8fd940f00 call   0x5854b0
0x48bfb3 8bf0 mov    esi,eax
0x48bfb5 8d4c2418 lea    ecx,[esp+0x18]
0x48bfb9 51 push   ecx
0x48bfba 8d442418 lea    eax,[esp+0x18]
0x48bfbe 8bce mov    ecx,esi
0x48bfc0 e82b810e00 call   0x5740f0
0x48bfc5 8b442414 mov    eax,DWORD PTR [esp+0x14]
0x48bfc9 3b4604 cmp    eax,DWORD PTR [esi+0x4]
0x48bfcc 740d je     0x48bfdb
0x48bfce 83c010 add    eax,0x10
0x48bfd1 83781408 cmp    DWORD PTR [eax+0x14],0x8
0x48bfd5 720a jb     0x48bfe1
0x48bfd7 8b00 mov    eax,DWORD PTR [eax]
0x48bfd9 eb06 jmp    0x48bfe1
0x48bfdb cc int3
0x48bfdc b8fcd1be00 mov    eax,0xbed1fc
0x48bfe1 8b5328 mov    edx,DWORD PTR [ebx+0x28]
0x48bfe4 6a00 push   0x0
0x48bfe6 52 push   edx
0x48bfe7 50 push   eax
0x48bfe8 6a00 push   0x0
0x48bfea ff158025bd00 call   DWORD PTR ds:0xbd2580
0x48bff0 68c856c000 push   0xc056c8
0x48bff5 8bd3 mov    edx,ebx
0x48bff7 e8042d2500 call   0x6ded00
0x48bffc 83c404 add    esp,0x4
0x48bfff b805400080 mov    eax,0x80004005
0x48c004 e93b010000 jmp    0x48c144
0x48c009 8b8378bf0000 mov    eax,DWORD PTR [ebx+0xbf78]
0x48c00f 68285bc000 push   0xc05b28
0x48c014 68f056c000 push   0xc056f0
0x48c019 50 push   eax
0x48c01a 68fc56c000 push   0xc056fc
0x48c01f e8dc1c2600 call   0x6edd00
0x48c024 83c410 add    esp,0x10
0x48c027 8d43f8 lea    eax,[ebx-0x8]
0x48c02a e841710000 call   0x493170
0x48c02f f6051413fb0001 test   BYTE PTR ds:0xfb1314,0x1
0x48c036 bf01000000 mov    edi,0x1
0x48c03b 7513 jne    0x48c050
0x48c03d 093d1413fb00 or     DWORD PTR ds:0xfb1314,edi
0x48c043 6810cfbc00 push   0xbccf10
0x48c048 e8cd624000 call   0x89231a
0x48c04d 83c404 add    esp,0x4
0x48c050 83ceff or     esi,0xffffffff
0x48c053 f6056c72fe0001 test   BYTE PTR ds:0xfe726c,0x1
0x48c05a 7559 jne    0x48c0b5
0x48c05c 093d6c72fe00 or     DWORD PTR ds:0xfe726c,edi
0x48c062 89bc2478010000 mov    DWORD PTR [esp+0x178],edi
0x48c069 e8e2480100 call   0x4a0950
0x48c06e 68c0e6bc00 push   0xbce6c0
0x48c073 e8a2624000 call   0x89231a
0x48c078 83c404 add    esp,0x4
0x48c07b 89b42478010000 mov    DWORD PTR [esp+0x178],esi
0x48c082 f6056c72fe0001 test   BYTE PTR ds:0xfe726c,0x1
0x48c089 752a jne    0x48c0b5
0x48c08b 093d6c72fe00 or     DWORD PTR ds:0xfe726c,edi
0x48c091 c784247801000002000000 mov    DWORD PTR [esp+0x178],0x2
0x48c09c e8af480100 call   0x4a0950
0x48c0a1 68c0e6bc00 push   0xbce6c0
0x48c0a6 e86f624000 call   0x89231a
0x48c0ab 83c404 add    esp,0x4
0x48c0ae 89b42478010000 mov    DWORD PTR [esp+0x178],esi
0x48c0b5 f605d837fe0001 test   BYTE PTR ds:0xfe37d8,0x1
0x48c0bc c705783dd60000000000 mov    DWORD PTR ds:0xd63d78,0x0
0x48c0c6 7518 jne    0x48c0e0
0x48c0c8 093dd837fe00 or     DWORD PTR ds:0xfe37d8,edi
0x48c0ce e81d933700 call   0x8053f0
0x48c0d3 68a00bbd00 push   0xbd0ba0
0x48c0d8 e83d624000 call   0x89231a
0x48c0dd 83c404 add    esp,0x4
0x48c0e0 8dbb40010000 lea    edi,[ebx+0x140]
0x48c0e6 e865853700 call   0x804650
0x48c0eb 6a34 push   0x34
0x48c0ed 6a01 push   0x1
0x48c0ef 6a01 push   0x1
0x48c0f1 682457c000 push   0xc05724
0x48c0f6 8d942454010000 lea    edx,[esp+0x154]
0x48c0fd e8aecd0000 call   0x498eb0
0x48c102 83c410 add    esp,0x10
0x48c105 e87615fcff call   0x44d680
0x48c10a 8b08 mov    ecx,DWORD PTR [eax]
0x48c10c 85c9 test   ecx,ecx
0x48c10e 740b je     0x48c11b
0x48c110 8b11 mov    edx,DWORD PTR [ecx]
0x48c112 8b4220 mov    eax,DWORD PTR [edx+0x20]
0x48c115 ffd0 call   eax
0x48c117 85c0 test   eax,eax
0x48c119 7527 jne    0x48c142
0x48c11b 8b4b28 mov    ecx,DWORD PTR [ebx+0x28]
0x48c11e 6a00 push   0x0
0x48c120 51 push   ecx
0x48c121 687b010000 push   0x17b
0x48c126 e885930f00 call   0x5854b0
0x48c12b 8bf0 mov    esi,eax
0x48c12d e8fe910f00 call   0x585330
0x48c132 50 push   eax
0x48c133 6a00 push   0x0
0x48c135 ff158025bd00 call   DWORD PTR ds:0xbd2580
0x48c13b b805400080 mov    eax,0x80004005
0x48c140 eb02 jmp    0x48c144
0x48c142 33c0 xor    eax,eax
0x48c144 8b8c2470010000 mov    ecx,DWORD PTR [esp+0x170]
0x48c14b 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x48c152 59 pop    ecx
0x48c153 5f pop    edi
0x48c154 5e pop    esi
0x48c155 5b pop    ebx
0x48c156 8b8c2458010000 mov    ecx,DWORD PTR [esp+0x158]
0x48c15d 33cc xor    ecx,esp
0x48c15f e89d4e4000 call   0x891001
0x48c164 8be5 mov    esp,ebp
0x48c166 5d pop    ebp
0x48c167 c20400 ret    0x4

; c2s_003f_builder 0x4a39a0..0x4a39ec raw=0xa2da0 sha256=dbb0c12cfc16ef6738deb33fda9cb2b410be3aae67e89a6df6b71e7fd1711976
0x4a39a0 55 push   ebp
0x4a39a1 8bec mov    ebp,esp
0x4a39a3 83ec08 sub    esp,0x8
0x4a39a6 833d98a7fb0000 cmp    DWORD PTR ds:0xfba798,0x0
0x4a39ad 668b4d08 mov    cx,WORD PTR [ebp+0x8]
0x4a39b1 668b550c mov    dx,WORD PTR [ebp+0xc]
0x4a39b5 b83f000000 mov    eax,0x3f
0x4a39ba 668945f8 mov    WORD PTR [ebp-0x8],ax
0x4a39be b801000000 mov    eax,0x1
0x4a39c3 66894dfa mov    WORD PTR [ebp-0x6],cx
0x4a39c7 668955fc mov    WORD PTR [ebp-0x4],dx
0x4a39cb 668945fe mov    WORD PTR [ebp-0x2],ax
0x4a39cf 7515 jne    0x4a39e6
0x4a39d1 8b0d54a8fb00 mov    ecx,DWORD PTR ds:0xfba854
0x4a39d7 8b11 mov    edx,DWORD PTR [ecx]
0x4a39d9 8b5210 mov    edx,DWORD PTR [edx+0x10]
0x4a39dc 6a08 push   0x8
0x4a39de 8d45f8 lea    eax,[ebp-0x8]
0x4a39e1 50 push   eax
0x4a39e2 6a00 push   0x0
0x4a39e4 ffd2 call   edx
0x4a39e6 8be5 mov    esp,ebp
0x4a39e8 5d pop    ebp
0x4a39e9 c20800 ret    0x8

; q_start_and_skip 0x561760..0x561db0 raw=0x160b60 sha256=b1384aa92a8e9b8debc3f2628d2942d6f93185d5b485daae6ddbeb49df62f9d2
0x561760 55 push   ebp
0x561761 8bec mov    ebp,esp
0x561763 83e4f8 and    esp,0xfffffff8
0x561766 6aff push   0xffffffff
0x561768 682cfd9300 push   0x93fd2c
0x56176d 64a100000000 mov    eax,fs:0x0
0x561773 50 push   eax
0x561774 83ec50 sub    esp,0x50
0x561777 a1201fd600 mov    eax,ds:0xd61f20
0x56177c 33c4 xor    eax,esp
0x56177e 89442448 mov    DWORD PTR [esp+0x48],eax
0x561782 53 push   ebx
0x561783 56 push   esi
0x561784 57 push   edi
0x561785 a1201fd600 mov    eax,ds:0xd61f20
0x56178a 33c4 xor    eax,esp
0x56178c 50 push   eax
0x56178d 8d442460 lea    eax,[esp+0x60]
0x561791 64a300000000 mov    fs:0x0,eax
0x561797 833d18abfb0000 cmp    DWORD PTR ds:0xfbab18,0x0
0x56179e 8bd9 mov    ebx,ecx
0x5617a0 7420 je     0x5617c2
0x5617a2 0f57c0 xorps  xmm0,xmm0
0x5617a5 f30f110524abfb00 movss  DWORD PTR ds:0xfbab24,xmm0
0x5617ad e8aed8eaff call   0x40f060
0x5617b2 f30f10057059c500 movss  xmm0,DWORD PTR ds:0xc55970
0x5617ba f30f1180ac000000 movss  DWORD PTR [eax+0xac],xmm0
0x5617c2 837b2800 cmp    DWORD PTR [ebx+0x28],0x0
0x5617c6 c6838900000000 mov    BYTE PTR [ebx+0x89],0x0
0x5617cd 741a je     0x5617e9
0x5617cf 8b450c mov    eax,DWORD PTR [ebp+0xc]
0x5617d2 8b4d08 mov    ecx,DWORD PTR [ebp+0x8]
0x5617d5 50 push   eax
0x5617d6 51 push   ecx
0x5617d7 68ac06c100 push   0xc106ac
0x5617dc e87fc31800 call   0x6edb60
0x5617e1 83c40c add    esp,0xc
0x5617e4 e99d050000 jmp    0x561d86
0x5617e9 f6052888fb0001 test   BYTE PTR ds:0xfb8828,0x1
0x5617f0 be01000000 mov    esi,0x1
0x5617f5 7529 jne    0x561820
0x5617f7 09352888fb00 or     DWORD PTR ds:0xfb8828,esi
0x5617fd c744246800000000 mov    DWORD PTR [esp+0x68],0x0
0x561805 e846e0feff call   0x54f850
0x56180a 6880d5bc00 push   0xbcd580
0x56180f e8060b3300 call   0x89231a
0x561814 83c404 add    esp,0x4
0x561817 83cfff or     edi,0xffffffff
0x56181a 897c2468 mov    DWORD PTR [esp+0x68],edi
0x56181e eb03 jmp    0x561823
0x561820 83cfff or     edi,0xffffffff
0x561823 803df192fb0000 cmp    BYTE PTR ds:0xfb92f1,0x0
0x56182a 0f84ac000000 je     0x5618dc
0x561830 837d0800 cmp    DWORD PTR [ebp+0x8],0x0
0x561834 0f85a2000000 jne    0x5618dc
0x56183a e86133eaff call   0x404ba0
0x56183f 83b84c5f000009 cmp    DWORD PTR [eax+0x5f4c],0x9
0x561846 741c je     0x561864
0x561848 e85333eaff call   0x404ba0
0x56184d 83b84c5f000004 cmp    DWORD PTR [eax+0x5f4c],0x4
0x561854 740e je     0x561864
0x561856 e84533eaff call   0x404ba0
0x56185b 83b84c5f000019 cmp    DWORD PTR [eax+0x5f4c],0x19
0x561862 7578 jne    0x5618dc
0x561864 8b7378 mov    esi,DWORD PTR [ebx+0x78]
0x561867 8d550c lea    edx,[ebp+0xc]
0x56186a 52 push   edx
0x56186b 8d4b74 lea    ecx,[ebx+0x74]
0x56186e 8d442414 lea    eax,[esp+0x14]
0x561872 e8494cedff call   0x4364c0
0x561877 3930 cmp    DWORD PTR [eax],esi
0x561879 745c je     0x5618d7
0x56187b 6a0f push   0xf
0x56187d e82e3d0200 call   0x5855b0
0x561882 8bf0 mov    esi,eax
0x561884 e8a73a0200 call   0x585330
0x561889 50 push   eax
0x56188a 8d4c2440 lea    ecx,[esp+0x40]
0x56188e e8bd09eaff call   0x402250
0x561893 8d44243c lea    eax,[esp+0x3c]
0x561897 50 push   eax
0x561898 c744246c01000000 mov    DWORD PTR [esp+0x6c],0x1
0x5618a0 e81be0eaff call   0x40f8c0
0x5618a5 8bf8 mov    edi,eax
0x5618a7 e88452f7ff call   0x4d6b30
0x5618ac 8d4c243c lea    ecx,[esp+0x3c]
0x5618b0 c7442468ffffffff mov    DWORD PTR [esp+0x68],0xffffffff
0x5618b8 e8838bf9ff call   0x4fa440
0x5618bd e8be2debff call   0x414680
0x5618c2 8b4d0c mov    ecx,DWORD PTR [ebp+0xc]
0x5618c5 51 push   ecx
0x5618c6 6a00 push   0x0
0x5618c8 e8d320f4ff call   0x4a39a0
0x5618cd e8de070000 call   0x5620b0
0x5618d2 e9af040000 jmp    0x561d86
0x5618d7 be01000000 mov    esi,0x1
0x5618dc f605d4adfa0001 test   BYTE PTR ds:0xfaadd4,0x1
0x5618e3 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x5618e6 8b450c mov    eax,DWORD PTR [ebp+0xc]
0x5618e9 895338 mov    DWORD PTR [ebx+0x38],edx
0x5618ec 89433c mov    DWORD PTR [ebx+0x3c],eax
0x5618ef 897328 mov    DWORD PTR [ebx+0x28],esi
0x5618f2 7524 jne    0x561918
0x5618f4 0935d4adfa00 or     DWORD PTR ds:0xfaadd4,esi
0x5618fa c744246802000000 mov    DWORD PTR [esp+0x68],0x2
0x561902 e8795b0200 call   0x587480
0x561907 68c0ccbc00 push   0xbcccc0
0x56190c e8090a3300 call   0x89231a
0x561911 83c404 add    esp,0x4
0x561914 897c2468 mov    DWORD PTR [esp+0x68],edi
0x561918 f605d0adfa0001 test   BYTE PTR ds:0xfaadd0,0x1
0x56191f 7524 jne    0x561945
0x561921 0935d0adfa00 or     DWORD PTR ds:0xfaadd0,esi
0x561927 c744246803000000 mov    DWORD PTR [esp+0x68],0x3
0x56192f e85cc01e00 call   0x74d990
0x561934 6870ccbc00 push   0xbccc70
0x561939 e8dc093300 call   0x89231a
0x56193e 83c404 add    esp,0x4
0x561941 897c2468 mov    DWORD PTR [esp+0x68],edi
0x561945 f6059043f90001 test   BYTE PTR ds:0xf94390,0x1
0x56194c 8b0dbc5bf900 mov    ecx,DWORD PTR ds:0xf95bbc
0x561952 8b15c05bf900 mov    edx,DWORD PTR ds:0xf95bc0
0x561958 894c2414 mov    DWORD PTR [esp+0x14],ecx
0x56195c f30f10442414 movss  xmm0,DWORD PTR [esp+0x14]
0x561962 89542418 mov    DWORD PTR [esp+0x18],edx
0x561966 f30f118384000000 movss  DWORD PTR [ebx+0x84],xmm0
0x56196e 7524 jne    0x561994
0x561970 09359043f900 or     DWORD PTR ds:0xf94390,esi
0x561976 c744246804000000 mov    DWORD PTR [esp+0x68],0x4
0x56197e e80dfcf7ff call   0x4e1590
0x561983 6880ccbc00 push   0xbccc80
0x561988 e88d093300 call   0x89231a
0x56198d 83c404 add    esp,0x4
0x561990 897c2468 mov    DWORD PTR [esp+0x68],edi
0x561994 f605d4adfa0001 test   BYTE PTR ds:0xfaadd4,0x1
0x56199b a0a442f900 mov    al,ds:0xf942a4
0x5619a0 888388000000 mov    BYTE PTR [ebx+0x88],al
0x5619a6 7524 jne    0x5619cc
0x5619a8 0935d4adfa00 or     DWORD PTR ds:0xfaadd4,esi
0x5619ae c744246805000000 mov    DWORD PTR [esp+0x68],0x5
0x5619b6 e8c55a0200 call   0x587480
0x5619bb 68c0ccbc00 push   0xbcccc0
0x5619c0 e855093300 call   0x89231a
0x5619c5 83c404 add    esp,0x4
0x5619c8 897c2468 mov    DWORD PTR [esp+0x68],edi
0x5619cc 6858430f00 push   0xf4358
0x5619d1 e8fa900200 call   0x58aad0
0x5619d6 83c404 add    esp,0x4
0x5619d9 f6059043f90001 test   BYTE PTR ds:0xf94390,0x1
0x5619e0 7524 jne    0x561a06
0x5619e2 09359043f900 or     DWORD PTR ds:0xf94390,esi
0x5619e8 c744246806000000 mov    DWORD PTR [esp+0x68],0x6
0x5619f0 e89bfbf7ff call   0x4e1590
0x5619f5 6880ccbc00 push   0xbccc80
0x5619fa e81b093300 call   0x89231a
0x5619ff 83c404 add    esp,0x4
0x561a02 897c2468 mov    DWORD PTR [esp+0x68],edi
0x561a06 6a00 push   0x0
0x561a08 687523bf00 push   0xbf2375
0x561a0d 8d4b44 lea    ecx,[ebx+0x44]
0x561a10 c605a442f90001 mov    BYTE PTR ds:0xf942a4,0x1
0x561a17 e85410eaff call   0x402a70
0x561a1c 8b730c mov    esi,DWORD PTR [ebx+0xc]
0x561a1f 8b4604 mov    eax,DWORD PTR [esi+0x4]
0x561a22 80783100 cmp    BYTE PTR [eax+0x31],0x0
0x561a26 8bd6 mov    edx,esi
0x561a28 752c jne    0x561a56
0x561a2a 8d9b00000000 lea    ebx,[ebx+0x0]
0x561a30 8b480c mov    ecx,DWORD PTR [eax+0xc]
0x561a33 8b7d08 mov    edi,DWORD PTR [ebp+0x8]
0x561a36 3bf9 cmp    edi,ecx
0x561a38 7f0a jg     0x561a44
0x561a3a 7c0d jl     0x561a49
0x561a3c 8b4d0c mov    ecx,DWORD PTR [ebp+0xc]
0x561a3f 394810 cmp    DWORD PTR [eax+0x10],ecx
0x561a42 7d05 jge    0x561a49
0x561a44 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x561a47 eb04 jmp    0x561a4d
0x561a49 8bd0 mov    edx,eax
0x561a4b 8b00 mov    eax,DWORD PTR [eax]
0x561a4d 80783100 cmp    BYTE PTR [eax+0x31],0x0
0x561a51 74dd je     0x561a30
0x561a53 83cfff or     edi,0xffffffff
0x561a56 8954241c mov    DWORD PTR [esp+0x1c],edx
0x561a5a 3bd6 cmp    edx,esi
0x561a5c 741a je     0x561a78
0x561a5e 8b420c mov    eax,DWORD PTR [edx+0xc]
0x561a61 8b4d08 mov    ecx,DWORD PTR [ebp+0x8]
0x561a64 3bc1 cmp    eax,ecx
0x561a66 7f10 jg     0x561a78
0x561a68 7c08 jl     0x561a72
0x561a6a 8b450c mov    eax,DWORD PTR [ebp+0xc]
0x561a6d 3b4210 cmp    eax,DWORD PTR [edx+0x10]
0x561a70 7c06 jl     0x561a78
0x561a72 8d44241c lea    eax,[esp+0x1c]
0x561a76 eb08 jmp    0x561a80
0x561a78 89742410 mov    DWORD PTR [esp+0x10],esi
0x561a7c 8d442410 lea    eax,[esp+0x10]
0x561a80 8b30 mov    esi,DWORD PTR [eax]
0x561a82 3b730c cmp    esi,DWORD PTR [ebx+0xc]
0x561a85 0f84f4020000 je     0x561d7f
0x561a8b 6a10 push   0x10
0x561a8d 68d006c100 push   0xc106d0
0x561a92 8d4c2428 lea    ecx,[esp+0x28]
0x561a96 c744243c0f000000 mov    DWORD PTR [esp+0x3c],0xf
0x561a9e c744243800000000 mov    DWORD PTR [esp+0x38],0x0
0x561aa6 c644242800 mov    BYTE PTR [esp+0x28],0x0
0x561aab e8c00feaff call   0x402a70
0x561ab0 8d4614 lea    eax,[esi+0x14]
0x561ab3 57 push   edi
0x561ab4 33f6 xor    esi,esi
0x561ab6 56 push   esi
0x561ab7 50 push   eax
0x561ab8 8d4c242c lea    ecx,[esp+0x2c]
0x561abc c744247407000000 mov    DWORD PTR [esp+0x74],0x7
0x561ac4 e80704eaff call   0x401ed0
0x561ac9 6a04 push   0x4
0x561acb 68e406c100 push   0xc106e4
0x561ad0 8d4c2428 lea    ecx,[esp+0x28]
0x561ad4 e8e704eaff call   0x401fc0
0x561ad9 837c243410 cmp    DWORD PTR [esp+0x34],0x10
0x561ade 8b442420 mov    eax,DWORD PTR [esp+0x20]
0x561ae2 7304 jae    0x561ae8
0x561ae4 8d442420 lea    eax,[esp+0x20]
0x561ae8 50 push   eax
0x561ae9 51 push   ecx
0x561aea e8b1aaffff call   0x55c5a0
0x561aef 83c404 add    esp,0x4
0x561af2 50 push   eax
0x561af3 e8a8bbffff call   0x55d6a0
0x561af8 6a1c push   0x1c
0x561afa 894370 mov    DWORD PTR [ebx+0x70],eax
0x561afd e866f73200 call   0x891268
0x561b02 83c404 add    esp,0x4
0x561b05 3bc6 cmp    eax,esi
0x561b07 7411 je     0x561b1a
0x561b09 8930 mov    DWORD PTR [eax],esi
0x561b0b c6400801 mov    BYTE PTR [eax+0x8],0x1
0x561b0f 89700c mov    DWORD PTR [eax+0xc],esi
0x561b12 897010 mov    DWORD PTR [eax+0x10],esi
0x561b15 897014 mov    DWORD PTR [eax+0x14],esi
0x561b18 eb02 jmp    0x561b1c
0x561b1a 33c0 xor    eax,eax
0x561b1c 50 push   eax
0x561b1d 8d4c2418 lea    ecx,[esp+0x18]
0x561b21 51 push   ecx
0x561b22 8974241c mov    DWORD PTR [esp+0x1c],esi
0x561b26 89742420 mov    DWORD PTR [esp+0x20],esi
0x561b2a e8a1a5f1ff call   0x47c0d0
0x561b2f c644246808 mov    BYTE PTR [esp+0x68],0x8
0x561b34 8b742414 mov    esi,DWORD PTR [esp+0x14]
0x561b38 c7460403000000 mov    DWORD PTR [esi+0x4],0x3
0x561b3f c6460801 mov    BYTE PTR [esi+0x8],0x1
0x561b43 8b4b70 mov    ecx,DWORD PTR [ebx+0x70]
0x561b46 8b4104 mov    eax,DWORD PTR [ecx+0x4]
0x561b49 8b00 mov    eax,DWORD PTR [eax]
0x561b4b 8944241c mov    DWORD PTR [esp+0x1c],eax
0x561b4f 3b4104 cmp    eax,DWORD PTR [ecx+0x4]
0x561b52 7436 je     0x561b8a
0x561b54 8d7e0c lea    edi,[esi+0xc]
0x561b57 eb07 jmp    0x561b60
0x561b59 8da42400000000 lea    esp,[esp+0x0]
0x561b60 8b5010 mov    edx,DWORD PTR [eax+0x10]
0x561b63 0fb702 movzx  eax,WORD PTR [edx]
0x561b66 89442410 mov    DWORD PTR [esp+0x10],eax
0x561b6a 8d442410 lea    eax,[esp+0x10]
0x561b6e e80d6bf4ff call   0x4a8680
0x561b73 8d44241c lea    eax,[esp+0x1c]
0x561b77 e824cbf3ff call   0x49e6a0
0x561b7c 8b4370 mov    eax,DWORD PTR [ebx+0x70]
0x561b7f 8b4804 mov    ecx,DWORD PTR [eax+0x4]
0x561b82 8b44241c mov    eax,DWORD PTR [esp+0x1c]
0x561b86 3bc1 cmp    eax,ecx
0x561b88 75d6 jne    0x561b60
0x561b8a 8b542418 mov    edx,DWORD PTR [esp+0x18]
0x561b8e 83ec08 sub    esp,0x8
0x561b91 8bfc mov    edi,esp
0x561b93 89642418 mov    DWORD PTR [esp+0x18],esp
0x561b97 c70700000000 mov    DWORD PTR [edi],0x0
0x561b9d c7470400000000 mov    DWORD PTR [edi+0x4],0x0
0x561ba4 85d2 test   edx,edx
0x561ba6 7416 je     0x561bbe
0x561ba8 e8a3a6f1ff call   0x47c250
0x561bad 84c0 test   al,al
0x561baf 740d je     0x561bbe
0x561bb1 8b4c2420 mov    ecx,DWORD PTR [esp+0x20]
0x561bb5 51 push   ecx
0x561bb6 56 push   esi
0x561bb7 8bf7 mov    esi,edi
0x561bb9 e802162400 call   0x7a31c0
0x561bbe c644247009 mov    BYTE PTR [esp+0x70],0x9
0x561bc3 f605600ffc0001 test   BYTE PTR ds:0xfc0f60,0x1
0x561bca 7523 jne    0x561bef
0x561bcc 830d600ffc0001 or     DWORD PTR ds:0xfc0f60,0x1
0x561bd3 c64424700a mov    BYTE PTR [esp+0x70],0xa
0x561bd8 e863b32300 call   0x79cf40
0x561bdd 6880dbbc00 push   0xbcdb80
0x561be2 e833073300 call   0x89231a
0x561be7 83c404 add    esp,0x4
0x561bea c644247009 mov    BYTE PTR [esp+0x70],0x9
0x561bef b9900efc00 mov    ecx,0xfc0e90
0x561bf4 c644247008 mov    BYTE PTR [esp+0x70],0x8
0x561bf9 e8e2c02300 call   0x79dce0
0x561bfe 8bf0 mov    esi,eax
0x561c00 6aff push   0xffffffff
0x561c02 56 push   esi
0x561c03 ff15fc20bd00 call   DWORD PTR ds:0xbd20fc
0x561c09 56 push   esi
0x561c0a ff15c821bd00 call   DWORD PTR ds:0xbd21c8
0x561c10 f6057017fe0001 test   BYTE PTR ds:0xfe1770,0x1
0x561c17 7523 jne    0x561c3c
0x561c19 830d7017fe0001 or     DWORD PTR ds:0xfe1770,0x1
0x561c20 c64424680b mov    BYTE PTR [esp+0x68],0xb
0x561c25 e876612500 call   0x7b7da0
0x561c2a 6890e7bc00 push   0xbce790
0x561c2f e8e6063300 call   0x89231a
0x561c34 83c404 add    esp,0x4
0x561c37 c644246808 mov    BYTE PTR [esp+0x68],0x8
0x561c3c 8b3d3c17fe00 mov    edi,DWORD PTR ds:0xfe173c
0x561c42 8b4704 mov    eax,DWORD PTR [edi+0x4]
0x561c45 8b30 mov    esi,DWORD PTR [eax]
0x561c47 3bf0 cmp    esi,eax
0x561c49 741c je     0x561c67
0x561c4b eb03 jmp    0x561c50
0x561c4d 8d4900 lea    ecx,[ecx+0x0]
0x561c50 8b4e24 mov    ecx,DWORD PTR [esi+0x24]
0x561c53 83790400 cmp    DWORD PTR [ecx+0x4],0x0
0x561c57 7507 jne    0x561c60
0x561c59 8b11 mov    edx,DWORD PTR [ecx]
0x561c5b 8b4204 mov    eax,DWORD PTR [edx+0x4]
0x561c5e ffd0 call   eax
0x561c60 8b36 mov    esi,DWORD PTR [esi]
0x561c62 3b7704 cmp    esi,DWORD PTR [edi+0x4]
0x561c65 75e9 jne    0x561c50
0x561c67 8b442420 mov    eax,DWORD PTR [esp+0x20]
0x561c6b bf10000000 mov    edi,0x10
0x561c70 397c2434 cmp    DWORD PTR [esp+0x34],edi
0x561c74 7304 jae    0x561c7a
0x561c76 8d442420 lea    eax,[esp+0x20]
0x561c7a 8b0b mov    ecx,DWORD PTR [ebx]
0x561c7c 50 push   eax
0x561c7d e8ce2d1900 call   0x6f4a50
0x561c82 33db xor    ebx,ebx
0x561c84 f605ec79fb0001 test   BYTE PTR ds:0xfb79ec,0x1
0x561c8b be01000000 mov    esi,0x1
0x561c90 7535 jne    0x561cc7
0x561c92 0935ec79fb00 or     DWORD PTR ds:0xfb79ec,esi
0x561c98 6870d2bc00 push   0xbcd270
0x561c9d c705f079fb0068f8c000 mov    DWORD PTR ds:0xfb79f0,0xc0f868
0x561ca7 891df479fb00 mov    DWORD PTR ds:0xfb79f4,ebx
0x561cad 891df879fb00 mov    DWORD PTR ds:0xfb79f8,ebx
0x561cb3 891dfc79fb00 mov    DWORD PTR ds:0xfb79fc,ebx
0x561cb9 8935047afb00 mov    DWORD PTR ds:0xfb7a04,esi
0x561cbf e856063300 call   0x89231a
0x561cc4 83c404 add    esp,0x4
0x561cc7 f605600ffc0001 test   BYTE PTR ds:0xfc0f60,0x1
0x561cce 891d047afb00 mov    DWORD PTR ds:0xfb7a04,ebx
0x561cd4 7522 jne    0x561cf8
0x561cd6 0935600ffc00 or     DWORD PTR ds:0xfc0f60,esi
0x561cdc c64424680c mov    BYTE PTR [esp+0x68],0xc
0x561ce1 e85ab22300 call   0x79cf40
0x561ce6 6880dbbc00 push   0xbcdb80
0x561ceb e82a063300 call   0x89231a
0x561cf0 83c404 add    esp,0x4
0x561cf3 c644246808 mov    BYTE PTR [esp+0x68],0x8
0x561cf8 6a02 push   0x2
0x561cfa 68900efc00 push   0xfc0e90
0x561cff e8bcbc2300 call   0x79d9c0
0x561d04 f605d894fd0001 test   BYTE PTR ds:0xfd94d8,0x1
0x561d0b 751d jne    0x561d2a
0x561d0d 0935d894fd00 or     DWORD PTR ds:0xfd94d8,esi
0x561d13 c64424680d mov    BYTE PTR [esp+0x68],0xd
0x561d18 e813372500 call   0x7b5430
0x561d1d 6860e6bc00 push   0xbce660
0x561d22 e8f3053300 call   0x89231a
0x561d27 83c404 add    esp,0x4
0x561d2a c644246807 mov    BYTE PTR [esp+0x68],0x7
0x561d2f 8b742418 mov    esi,DWORD PTR [esp+0x18]
0x561d33 c705b094fd0002000000 mov    DWORD PTR ds:0xfd94b0,0x2
0x561d3d 3bf3 cmp    esi,ebx
0x561d3f 7429 je     0x561d6a
0x561d41 8d4e04 lea    ecx,[esi+0x4]
0x561d44 83caff or     edx,0xffffffff
0x561d47 f00fc111 lock xadd DWORD PTR [ecx],edx
0x561d4b 751d jne    0x561d6a
0x561d4d 8b06 mov    eax,DWORD PTR [esi]
0x561d4f 8b10 mov    edx,DWORD PTR [eax]
0x561d51 8bce mov    ecx,esi
0x561d53 ffd2 call   edx
0x561d55 8d4608 lea    eax,[esi+0x8]
0x561d58 83c9ff or     ecx,0xffffffff
0x561d5b f00fc108 lock xadd DWORD PTR [eax],ecx
0x561d5f 7509 jne    0x561d6a
0x561d61 8b16 mov    edx,DWORD PTR [esi]
0x561d63 8b4204 mov    eax,DWORD PTR [edx+0x4]
0x561d66 8bce mov    ecx,esi
0x561d68 ffd0 call   eax
0x561d6a 397c2434 cmp    DWORD PTR [esp+0x34],edi
0x561d6e 7216 jb     0x561d86
0x561d70 8b4c2420 mov    ecx,DWORD PTR [esp+0x20]
0x561d74 51 push   ecx
0x561d75 e892f43200 call   0x89120c
0x561d7a 83c404 add    esp,0x4
0x561d7d eb07 jmp    0x561d86
0x561d7f 8bcb mov    ecx,ebx
0x561d81 e82a000000 call   0x561db0
0x561d86 8b4c2460 mov    ecx,DWORD PTR [esp+0x60]
0x561d8a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x561d91 59 pop    ecx
0x561d92 5f pop    edi
0x561d93 5e pop    esi
0x561d94 5b pop    ebx
0x561d95 8b4c2448 mov    ecx,DWORD PTR [esp+0x48]
0x561d99 33cc xor    ecx,esp
0x561d9b e861f23200 call   0x891001
0x561da0 8be5 mov    esp,ebp
0x561da2 5d pop    ebp
0x561da3 c20800 ret    0x8
0x561da6 cc int3
0x561da7 cc int3
0x561da8 cc int3
0x561da9 cc int3
0x561daa cc int3
0x561dab cc int3
0x561dac cc int3
0x561dad cc int3
0x561dae cc int3
0x561daf cc int3

; reused_client_update_order 0x490fe0..0x49201b raw=0x903e0 sha256=77ec8091812f1b181ad03b0396fd803c92bd2205f1169a5af69abd0c3a9b55a4
0x490fe0 55 push   ebp
0x490fe1 8bec mov    ebp,esp
0x490fe3 83e4f8 and    esp,0xfffffff8
0x490fe6 6aff push   0xffffffff
0x490fe8 68d0989400 push   0x9498d0
0x490fed 64a100000000 mov    eax,fs:0x0
0x490ff3 50 push   eax
0x490ff4 81ec40030000 sub    esp,0x340
0x490ffa a1201fd600 mov    eax,ds:0xd61f20
0x490fff 33c4 xor    eax,esp
0x491001 89842438030000 mov    DWORD PTR [esp+0x338],eax
0x491008 53 push   ebx
0x491009 56 push   esi
0x49100a 57 push   edi
0x49100b a1201fd600 mov    eax,ds:0xd61f20
0x491010 33c4 xor    eax,esp
0x491012 50 push   eax
0x491013 8d842450030000 lea    eax,[esp+0x350]
0x49101a 64a300000000 mov    fs:0x0,eax
0x491020 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x491023 33f6 xor    esi,esi
0x491025 89442420 mov    DWORD PTR [esp+0x20],eax
0x491029 393558a8fb00 cmp    DWORD PTR ds:0xfba858,esi
0x49102f 7514 jne    0x491045
0x491031 39355ca8fb00 cmp    DWORD PTR ds:0xfba85c,esi
0x491037 7407 je     0x491040
0x491039 e8229f0000 call   0x49af60
0x49103e eb05 jmp    0x491045
0x491040 e8bb9f0000 call   0x49b000
0x491045 8b0d58a8fb00 mov    ecx,DWORD PTR ds:0xfba858
0x49104b 8b4134 mov    eax,DWORD PTR [ecx+0x34]
0x49104e 50 push   eax
0x49104f ff154c22bd00 call   DWORD PTR ds:0xbd224c
0x491055 393558a8fb00 cmp    DWORD PTR ds:0xfba858,esi
0x49105b 7514 jne    0x491071
0x49105d 39355ca8fb00 cmp    DWORD PTR ds:0xfba85c,esi
0x491063 7407 je     0x49106c
0x491065 e8f69e0000 call   0x49af60
0x49106a eb05 jmp    0x491071
0x49106c e88f9f0000 call   0x49b000
0x491071 8b1558a8fb00 mov    edx,DWORD PTR ds:0xfba858
0x491077 8b4a28 mov    ecx,DWORD PTR [edx+0x28]
0x49107a 8b01 mov    eax,DWORD PTR [ecx]
0x49107c 894c241c mov    DWORD PTR [esp+0x1c],ecx
0x491080 89442414 mov    DWORD PTR [esp+0x14],eax
0x491084 3bc1 cmp    eax,ecx
0x491086 0f844a010000 je     0x4911d6
0x49108c 8b5808 mov    ebx,DWORD PTR [eax+0x8]
0x49108f 39b3aca00000 cmp    DWORD PTR [ebx+0xa0ac],esi
0x491095 750b jne    0x4910a2
0x491097 8b00 mov    eax,DWORD PTR [eax]
0x491099 89442414 mov    DWORD PTR [esp+0x14],eax
0x49109d e92c010000 jmp    0x4911ce
0x4910a2 a104f7fd00 mov    eax,ds:0xfdf704
0x4910a7 bf01000000 mov    edi,0x1
0x4910ac 03c7 add    eax,edi
0x4910ae 50 push   eax
0x4910af 686858c000 push   0xc05868
0x4910b4 a304f7fd00 mov    ds:0xfdf704,eax
0x4910b9 e8a6204000 call   0x893164
0x4910be 8b442428 mov    eax,DWORD PTR [esp+0x28]
0x4910c2 83c408 add    esp,0x8
0x4910c5 399858bf0000 cmp    DWORD PTR [eax+0xbf58],ebx
0x4910cb 7550 jne    0x49111d
0x4910cd f605d0acfb0001 test   BYTE PTR ds:0xfbacd0,0x1
0x4910d4 7535 jne    0x49110b
0x4910d6 093dd0acfb00 or     DWORD PTR ds:0xfbacd0,edi
0x4910dc 89b42458030000 mov    DWORD PTR [esp+0x358],esi
0x4910e3 8935d4acfb00 mov    DWORD PTR ds:0xfbacd4,esi
0x4910e9 e812522400 call   0x6d6300
0x4910ee 6870d6bc00 push   0xbcd670
0x4910f3 a3d4acfb00 mov    ds:0xfbacd4,eax
0x4910f8 e81d124000 call   0x89231a
0x4910fd 83c404 add    esp,0x4
0x491100 c7842458030000ffffffff mov    DWORD PTR [esp+0x358],0xffffffff
0x49110b 8b0dd4acfb00 mov    ecx,DWORD PTR ds:0xfbacd4
0x491111 3bce cmp    ecx,esi
0x491113 7408 je     0x49111d
0x491115 8b11 mov    edx,DWORD PTR [ecx]
0x491117 8b4210 mov    eax,DWORD PTR [edx+0x10]
0x49111a 57 push   edi
0x49111b ffd0 call   eax
0x49111d a158a8fb00 mov    eax,ds:0xfba858
0x491122 3bc6 cmp    eax,esi
0x491124 7556 jne    0x49117c
0x491126 39355ca8fb00 cmp    DWORD PTR ds:0xfba85c,esi
0x49112c 740c je     0x49113a
0x49112e e82d9e0000 call   0x49af60
0x491133 a158a8fb00 mov    eax,ds:0xfba858
0x491138 eb42 jmp    0x49117c
0x49113a f6050012fc0001 test   BYTE PTR ds:0xfc1200,0x1
0x491141 752f jne    0x491172
0x491143 093d0012fc00 or     DWORD PTR ds:0xfc1200,edi
0x491149 680812fc00 push   0xfc1208
0x49114e 89bc245c030000 mov    DWORD PTR [esp+0x35c],edi
0x491155 e806433700 call   0x805460
0x49115a 6870e6bc00 push   0xbce670
0x49115f e8b6114000 call   0x89231a
0x491164 83c404 add    esp,0x4
0x491167 c7842458030000ffffffff mov    DWORD PTR [esp+0x358],0xffffffff
0x491172 b80812fc00 mov    eax,0xfc1208
0x491177 a358a8fb00 mov    ds:0xfba858,eax
0x49117c ff4844 dec    DWORD PTR [eax+0x44]
0x49117f 8b7848 mov    edi,DWORD PTR [eax+0x48]
0x491182 8b5704 mov    edx,DWORD PTR [edi+0x4]
0x491185 8d7048 lea    esi,[eax+0x48]
0x491188 8d4c2418 lea    ecx,[esp+0x18]
0x49118c 51 push   ecx
0x49118d 52 push   edx
0x49118e 57 push   edi
0x49118f 895c2424 mov    DWORD PTR [esp+0x24],ebx
0x491193 e868c52b00 call   0x74d700
0x491198 8b4e04 mov    ecx,DWORD PTR [esi+0x4]
0x49119b bafeffff3f mov    edx,0x3ffffffe
0x4911a0 2bd1 sub    edx,ecx
0x4911a2 83fa01 cmp    edx,0x1
0x4911a5 7246 jb     0x4911ed
0x4911a7 41 inc    ecx
0x4911a8 894e04 mov    DWORD PTR [esi+0x4],ecx
0x4911ab 894704 mov    DWORD PTR [edi+0x4],eax
0x4911ae 8b4804 mov    ecx,DWORD PTR [eax+0x4]
0x4911b1 8901 mov    DWORD PTR [ecx],eax
0x4911b3 8b442414 mov    eax,DWORD PTR [esp+0x14]
0x4911b7 c7431400000000 mov    DWORD PTR [ebx+0x14],0x0
0x4911be 8b08 mov    ecx,DWORD PTR [eax]
0x4911c0 894c2414 mov    DWORD PTR [esp+0x14],ecx
0x4911c4 8b4c241c mov    ecx,DWORD PTR [esp+0x1c]
0x4911c8 8b442414 mov    eax,DWORD PTR [esp+0x14]
0x4911cc 33f6 xor    esi,esi
0x4911ce 3bc1 cmp    eax,ecx
0x4911d0 0f85b6feffff jne    0x49108c
0x4911d6 393558a8fb00 cmp    DWORD PTR ds:0xfba858,esi
0x4911dc 751e jne    0x4911fc
0x4911de 39355ca8fb00 cmp    DWORD PTR ds:0xfba85c,esi
0x4911e4 7411 je     0x4911f7
0x4911e6 e8759d0000 call   0x49af60
0x4911eb eb0f jmp    0x4911fc
0x4911ed 683420bf00 push   0xbf2034
0x4911f2 e839c93e00 call   0x87db30
0x4911f7 e8049e0000 call   0x49b000
0x4911fc 8b1558a8fb00 mov    edx,DWORD PTR ds:0xfba858
0x491202 52 push   edx
0x491203 e838493700 call   0x805b40
0x491208 393558a8fb00 cmp    DWORD PTR ds:0xfba858,esi
0x49120e 7514 jne    0x491224
0x491210 39355ca8fb00 cmp    DWORD PTR ds:0xfba85c,esi
0x491216 7407 je     0x49121f
0x491218 e8439d0000 call   0x49af60
0x49121d eb05 jmp    0x491224
0x49121f e8dc9d0000 call   0x49b000
0x491224 a158a8fb00 mov    eax,ds:0xfba858
0x491229 8b4034 mov    eax,DWORD PTR [eax+0x34]
0x49122c 50 push   eax
0x49122d ff154822bd00 call   DWORD PTR ds:0xbd2248
0x491233 bf01000000 mov    edi,0x1
0x491238 293d78ddf700 sub    DWORD PTR ds:0xf7dd78,edi
0x49123e 7519 jne    0x491259
0x491240 8b0d04a8fb00 mov    ecx,DWORD PTR ds:0xfba804
0x491246 51 push   ecx
0x491247 e8151e4000 call   0x893061
0x49124c 83c404 add    esp,0x4
0x49124f c70578ddf70078000000 mov    DWORD PTR ds:0xf7dd78,0x78
0x491259 f605f88bfd0001 test   BYTE PTR ds:0xfd8bf8,0x1
0x491260 7519 jne    0x49127b
0x491262 093df88bfd00 or     DWORD PTR ds:0xfd8bf8,edi
0x491268 6810e3bc00 push   0xbce310
0x49126d 8935fc8bfd00 mov    DWORD PTR ds:0xfd8bfc,esi
0x491273 e8a2104000 call   0x89231a
0x491278 83c404 add    esp,0x4
0x49127b 8b1da025bd00 mov    ebx,DWORD PTR ds:0xbd25a0
0x491281 3935008cfd00 cmp    DWORD PTR ds:0xfd8c00,esi
0x491287 7446 je     0x4912cf
0x491289 ffd3 call   ebx
0x49128b 8bf8 mov    edi,eax
0x49128d 8bd7 mov    edx,edi
0x49128f 2b15fc8bfd00 sub    edx,DWORD PTR ds:0xfd8bfc
0x491295 81fa60ea0000 cmp    edx,0xea60
0x49129b 722d jb     0x4912ca
0x49129d b8a7000000 mov    eax,0xa7
0x4912a2 6689442414 mov    WORD PTR [esp+0x14],ax
0x4912a7 393598a7fb00 cmp    DWORD PTR ds:0xfba798,esi
0x4912ad 7515 jne    0x4912c4
0x4912af 8b0d54a8fb00 mov    ecx,DWORD PTR ds:0xfba854
0x4912b5 8b11 mov    edx,DWORD PTR [ecx]
0x4912b7 8b5210 mov    edx,DWORD PTR [edx+0x10]
0x4912ba 6a02 push   0x2
0x4912bc 8d442418 lea    eax,[esp+0x18]
0x4912c0 50 push   eax
0x4912c1 56 push   esi
0x4912c2 ffd2 call   edx
0x4912c4 893dfc8bfd00 mov    DWORD PTR ds:0xfd8bfc,edi
0x4912ca bf01000000 mov    edi,0x1
0x4912cf f605c00ffc0001 test   BYTE PTR ds:0xfc0fc0,0x1
0x4912d6 89742418 mov    DWORD PTR [esp+0x18],esi
0x4912da 752e jne    0x49130a
0x4912dc 093dc00ffc00 or     DWORD PTR ds:0xfc0fc0,edi
0x4912e2 c784245803000002000000 mov    DWORD PTR [esp+0x358],0x2
0x4912ed e85e7b2400 call   0x6d8e50
0x4912f2 68b0dbbc00 push   0xbcdbb0
0x4912f7 e81e104000 call   0x89231a
0x4912fc 83c404 add    esp,0x4
0x4912ff c7842458030000ffffffff mov    DWORD PTR [esp+0x358],0xffffffff
0x49130a b9c80ffc00 mov    ecx,0xfc0fc8
0x49130f e8ec8b2400 call   0x6d9f00
0x491314 f6059816fc0001 test   BYTE PTR ds:0xfc1698,0x1
0x49131b 7518 jne    0x491335
0x49131d 093d9816fc00 or     DWORD PTR ds:0xfc1698,edi
0x491323 e878b53700 call   0x80c8a0
0x491328 6820e3bc00 push   0xbce320
0x49132d e8e80f4000 call   0x89231a
0x491332 83c404 add    esp,0x4
0x491335 bfa016fc00 mov    edi,0xfc16a0
0x49133a e8d1b63700 call   0x80ca10
0x49133f f605f4f6fd0001 test   BYTE PTR ds:0xfdf6f4,0x1
0x491346 7522 jne    0x49136a
0x491348 830df4f6fd0001 or     DWORD PTR ds:0xfdf6f4,0x1
0x49134f c784245803000003000000 mov    DWORD PTR [esp+0x358],0x3
0x49135a e831a10000 call   0x49b490
0x49135f c7842458030000ffffffff mov    DWORD PTR [esp+0x358],0xffffffff
0x49136a f605d848fe0001 test   BYTE PTR ds:0xfe48d8,0x1
0x491371 750c jne    0x49137f
0x491373 830dd848fe0001 or     DWORD PTR ds:0xfe48d8,0x1
0x49137a e8919f0000 call   0x49b310
0x49137f be3037fe00 mov    esi,0xfe3730
0x491384 e807a00000 call   0x49b390
0x491389 f6059043f90001 test   BYTE PTR ds:0xf94390,0x1
0x491390 752f jne    0x4913c1
0x491392 830d9043f90001 or     DWORD PTR ds:0xf94390,0x1
0x491399 c784245803000004000000 mov    DWORD PTR [esp+0x358],0x4
0x4913a4 e8e7010500 call   0x4e1590
0x4913a9 6880ccbc00 push   0xbccc80
0x4913ae e8670f4000 call   0x89231a
0x4913b3 83c404 add    esp,0x4
0x4913b6 c7842458030000ffffffff mov    DWORD PTR [esp+0x358],0xffffffff
0x4913c1 ffd3 call   ebx
0x4913c3 f6059043f90001 test   BYTE PTR ds:0xf94390,0x1
0x4913ca a33c42f900 mov    ds:0xf9423c,eax
0x4913cf 752f jne    0x491400
0x4913d1 830d9043f90001 or     DWORD PTR ds:0xf94390,0x1
0x4913d8 c784245803000005000000 mov    DWORD PTR [esp+0x358],0x5
0x4913e3 e8a8010500 call   0x4e1590
0x4913e8 6880ccbc00 push   0xbccc80
0x4913ed e8280f4000 call   0x89231a
0x4913f2 83c404 add    esp,0x4
0x4913f5 c7842458030000ffffffff mov    DWORD PTR [esp+0x358],0xffffffff
0x491400 bfe0d9f800 mov    edi,0xf8d9e0
0x491405 e856080500 call   0x4e1c60
0x49140a a10ca8fb00 mov    eax,ds:0xfba80c
0x49140f 33db xor    ebx,ebx
0x491411 3bc3 cmp    eax,ebx
0x491413 7521 jne    0x491436
0x491415 687c050000 push   0x57c
0x49141a e849fe3f00 call   0x891268
0x49141f 83c404 add    esp,0x4
0x491422 3bc3 cmp    eax,ebx
0x491424 7409 je     0x49142f
0x491426 8bf0 mov    esi,eax
0x491428 e843ff2500 call   0x6f1370
0x49142d eb02 jmp    0x491431
0x49142f 33c0 xor    eax,eax
0x491431 a30ca8fb00 mov    ds:0xfba80c,eax
0x491436 50 push   eax
0x491437 e874022600 call   0x6f16b0
0x49143c f605701afc0001 test   BYTE PTR ds:0xfc1a70,0x1
0x491443 bf01000000 mov    edi,0x1
0x491448 7522 jne    0x49146c
0x49144a 093d701afc00 or     DWORD PTR ds:0xfc1a70,edi
0x491450 c784245803000006000000 mov    DWORD PTR [esp+0x358],0x6
0x49145b e8f0e72300 call   0x6cfc50
0x491460 83ceff or     esi,0xffffffff
0x491463 89b42458030000 mov    DWORD PTR [esp+0x358],esi
0x49146a eb03 jmp    0x49146f
0x49146c 83ceff or     esi,0xffffffff
0x49146f 68781afc00 push   0xfc1a78
0x491474 e877e82300 call   0x6cfcf0
0x491479 f605147cfb0001 test   BYTE PTR ds:0xfb7c14,0x1
0x491480 752a jne    0x4914ac
0x491482 093d147cfb00 or     DWORD PTR ds:0xfb7c14,edi
0x491488 c784245803000007000000 mov    DWORD PTR [esp+0x358],0x7
0x491493 e8b8f22300 call   0x6d0750
0x491498 6830d5bc00 push   0xbcd530
0x49149d e8780e4000 call   0x89231a
0x4914a2 83c404 add    esp,0x4
0x4914a5 89b42458030000 mov    DWORD PTR [esp+0x358],esi
0x4914ac b93088fb00 mov    ecx,0xfb8830
0x4914b1 e8caff2300 call   0x6d1480
0x4914b6 f605ecf3fd0001 test   BYTE PTR ds:0xfdf3ec,0x1
0x4914bd 752a jne    0x4914e9
0x4914bf 093decf3fd00 or     DWORD PTR ds:0xfdf3ec,edi
0x4914c5 c784245803000008000000 mov    DWORD PTR [esp+0x358],0x8
0x4914d0 e8cb082400 call   0x6d1da0
0x4914d5 6830e3bc00 push   0xbce330
0x4914da e83b0e4000 call   0x89231a
0x4914df 83c404 add    esp,0x4
0x4914e2 89b42458030000 mov    DWORD PTR [esp+0x358],esi
0x4914e9 68f0f3fd00 push   0xfdf3f0
0x4914ee e87d292400 call   0x6d3e70
0x4914f3 f605d4adfa0001 test   BYTE PTR ds:0xfaadd4,0x1
0x4914fa 752a jne    0x491526
0x4914fc 093dd4adfa00 or     DWORD PTR ds:0xfaadd4,edi
0x491502 c784245803000009000000 mov    DWORD PTR [esp+0x358],0x9
0x49150d e86e5f0f00 call   0x587480
0x491512 68c0ccbc00 push   0xbcccc0
0x491517 e8fe0d4000 call   0x89231a
0x49151c 83c404 add    esp,0x4
0x49151f 89b42458030000 mov    DWORD PTR [esp+0x358],esi
0x491526 68d8adfa00 push   0xfaadd8
0x49152b e8208d0f00 call   0x58a250
0x491530 e80bf8ffff call   0x490d40
0x491535 8b7c2420 mov    edi,DWORD PTR [esp+0x20]
0x491539 8d77f8 lea    esi,[edi-0x8]
0x49153c e8dff8ffff call   0x490e20
0x491541 a10ca8fb00 mov    eax,ds:0xfba80c
0x491546 3bc3 cmp    eax,ebx
0x491548 7521 jne    0x49156b
0x49154a 687c050000 push   0x57c
0x49154f e814fd3f00 call   0x891268
0x491554 83c404 add    esp,0x4
0x491557 3bc3 cmp    eax,ebx
0x491559 7409 je     0x491564
0x49155b 8bf0 mov    esi,eax
0x49155d e80efe2500 call   0x6f1370
0x491562 eb02 jmp    0x491566
0x491564 33c0 xor    eax,eax
0x491566 a30ca8fb00 mov    ds:0xfba80c,eax
0x49156b 395820 cmp    DWORD PTR [eax+0x20],ebx
0x49156e 0f8446010000 je     0x4916ba
0x491574 80b89b01000001 cmp    BYTE PTR [eax+0x19b],0x1
0x49157b 0f8539010000 jne    0x4916ba
0x491581 0fb6887d010000 movzx  ecx,BYTE PTR [eax+0x17d]
0x491588 3bcb cmp    ecx,ebx
0x49158a 7477 je     0x491603
0x49158c 0fb69098010000 movzx  edx,BYTE PTR [eax+0x198]
0x491593 3bd3 cmp    edx,ebx
0x491595 7427 je     0x4915be
0x491597 8b07 mov    eax,DWORD PTR [edi]
0x491599 8b480c mov    ecx,DWORD PTR [eax+0xc]
0x49159c 57 push   edi
0x49159d ffd1 call   ecx
0x49159f 8b17 mov    edx,DWORD PTR [edi]
0x4915a1 8b4210 mov    eax,DWORD PTR [edx+0x10]
0x4915a4 57 push   edi
0x4915a5 ffd0 call   eax
0x4915a7 8b0f mov    ecx,DWORD PTR [edi]
0x4915a9 8b5104 mov    edx,DWORD PTR [ecx+0x4]
0x4915ac 57 push   edi
0x4915ad ffd2 call   edx
0x4915af 8b07 mov    eax,DWORD PTR [edi]
0x4915b1 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4915b4 57 push   edi
0x4915b5 ffd1 call   ecx
0x4915b7 33c0 xor    eax,eax
0x4915b9 e9370a0000 jmp    0x491ff5
0x4915be 3bcb cmp    ecx,ebx
0x4915c0 7441 je     0x491603
0x4915c2 e8f927fbff call   0x443dc0
0x4915c7 395820 cmp    DWORD PTR [eax+0x20],ebx
0x4915ca 7432 je     0x4915fe
0x4915cc 0fb6808a010000 movzx  eax,BYTE PTR [eax+0x18a]
0x4915d3 3bc3 cmp    eax,ebx
0x4915d5 7427 je     0x4915fe
0x4915d7 e86431faff call   0x434740
0x4915dc 8b809c000000 mov    eax,DWORD PTR [eax+0x9c]
0x4915e2 50 push   eax
0x4915e3 e8d81b3200 call   0x7b31c0
0x4915e8 e85331faff call   0x434740
0x4915ed 8b809c000000 mov    eax,DWORD PTR [eax+0x9c]
0x4915f3 50 push   eax
0x4915f4 e8971b3200 call   0x7b3190
0x4915f9 e9b7000000 jmp    0x4916b5
0x4915fe a10ca8fb00 mov    eax,ds:0xfba80c
0x491603 3bc3 cmp    eax,ebx
0x491605 7521 jne    0x491628
0x491607 687c050000 push   0x57c
0x49160c e857fc3f00 call   0x891268
0x491611 83c404 add    esp,0x4
0x491614 3bc3 cmp    eax,ebx
0x491616 7409 je     0x491621
0x491618 8bf0 mov    esi,eax
0x49161a e851fd2500 call   0x6f1370
0x49161f eb02 jmp    0x491623
0x491621 33c0 xor    eax,eax
0x491623 a30ca8fb00 mov    ds:0xfba80c,eax
0x491628 395820 cmp    DWORD PTR [eax+0x20],ebx
0x49162b 0f8489000000 je     0x4916ba
0x491631 0fb6887d010000 movzx  ecx,BYTE PTR [eax+0x17d]
0x491638 3bcb cmp    ecx,ebx
0x49163a 747e je     0x4916ba
0x49163c e87f27fbff call   0x443dc0
0x491641 395820 cmp    DWORD PTR [eax+0x20],ebx
0x491644 740b je     0x491651
0x491646 0fb68098010000 movzx  eax,BYTE PTR [eax+0x198]
0x49164d 3bc3 cmp    eax,ebx
0x49164f 7564 jne    0x4916b5
0x491651 e86a27fbff call   0x443dc0
0x491656 395820 cmp    DWORD PTR [eax+0x20],ebx
0x491659 740b je     0x491666
0x49165b 0fb6808a010000 movzx  eax,BYTE PTR [eax+0x18a]
0x491662 3bc3 cmp    eax,ebx
0x491664 754f jne    0x4916b5
0x491666 8b35a4a7fb00 mov    esi,DWORD PTR ds:0xfba7a4
0x49166c 3bf3 cmp    esi,ebx
0x49166e 7445 je     0x4916b5
0x491670 8b16 mov    edx,DWORD PTR [esi]
0x491672 8b4220 mov    eax,DWORD PTR [edx+0x20]
0x491675 8bce mov    ecx,esi
0x491677 ffd0 call   eax
0x491679 85c0 test   eax,eax
0x49167b 7438 je     0x4916b5
0x49167d 8b16 mov    edx,DWORD PTR [esi]
0x49167f 8b4220 mov    eax,DWORD PTR [edx+0x20]
0x491682 8bce mov    ecx,esi
0x491684 ffd0 call   eax
0x491686 8bb89c000000 mov    edi,DWORD PTR [eax+0x9c]
0x49168c e8cfd9f7ff call   0x40f060
0x491691 8bf0 mov    esi,eax
0x491693 8bc7 mov    eax,edi
0x491695 e836e40400 call   0x4dfad0
0x49169a 3bc3 cmp    eax,ebx
0x49169c 7417 je     0x4916b5
0x49169e 80782002 cmp    BYTE PTR [eax+0x20],0x2
0x4916a2 7211 jb     0x4916b5
0x4916a4 e8e784ffff call   0x489b90
0x4916a9 ff4008 inc    DWORD PTR [eax+0x8]
0x4916ac 83780803 cmp    DWORD PTR [eax+0x8],0x3
0x4916b0 7e03 jle    0x4916b5
0x4916b2 895808 mov    DWORD PTR [eax+0x8],ebx
0x4916b5 a10ca8fb00 mov    eax,ds:0xfba80c
0x4916ba 3bc3 cmp    eax,ebx
0x4916bc 7521 jne    0x4916df
0x4916be 687c050000 push   0x57c
0x4916c3 e8a0fb3f00 call   0x891268
0x4916c8 83c404 add    esp,0x4
0x4916cb 3bc3 cmp    eax,ebx
0x4916cd 7409 je     0x4916d8
0x4916cf 8bf0 mov    esi,eax
0x4916d1 e89afc2500 call   0x6f1370
0x4916d6 eb02 jmp    0x4916da
0x4916d8 33c0 xor    eax,eax
0x4916da a30ca8fb00 mov    ds:0xfba80c,eax
0x4916df 395820 cmp    DWORD PTR [eax+0x20],ebx
0x4916e2 0f8420010000 je     0x491808
0x4916e8 80b89c01000001 cmp    BYTE PTR [eax+0x19c],0x1
0x4916ef 0f8513010000 jne    0x491808
0x4916f5 8b35a4a7fb00 mov    esi,DWORD PTR ds:0xfba7a4
0x4916fb 3bf3 cmp    esi,ebx
0x4916fd 0f8405010000 je     0x491808
0x491703 8b16 mov    edx,DWORD PTR [esi]
0x491705 8b4220 mov    eax,DWORD PTR [edx+0x20]
0x491708 8bce mov    ecx,esi
0x49170a ffd0 call   eax
0x49170c 85c0 test   eax,eax
0x49170e 0f84f4000000 je     0x491808
0x491714 8b16 mov    edx,DWORD PTR [esi]
0x491716 8b4220 mov    eax,DWORD PTR [edx+0x20]
0x491719 8bce mov    ecx,esi
0x49171b ffd0 call   eax
0x49171d 8bb89c000000 mov    edi,DWORD PTR [eax+0x9c]
0x491723 e838d9f7ff call   0x40f060
0x491728 8bf0 mov    esi,eax
0x49172a 8d4c241c lea    ecx,[esp+0x1c]
0x49172e 51 push   ecx
0x49172f 8d4e18 lea    ecx,[esi+0x18]
0x491732 8d442418 lea    eax,[esp+0x18]
0x491736 897c2420 mov    DWORD PTR [esp+0x20],edi
0x49173a e881213b00 call   0x8438c0
0x49173f 8b761c mov    esi,DWORD PTR [esi+0x1c]
0x491742 8b442414 mov    eax,DWORD PTR [esp+0x14]
0x491746 3bc6 cmp    eax,esi
0x491748 0f84ba000000 je     0x491808
0x49174e 8b4010 mov    eax,DWORD PTR [eax+0x10]
0x491751 3bc3 cmp    eax,ebx
0x491753 0f84af000000 je     0x491808
0x491759 80782005 cmp    BYTE PTR [eax+0x20],0x5
0x49175d 0f82a5000000 jb     0x491808
0x491763 e83834f7ff call   0x404ba0
0x491768 8b804c5f0000 mov    eax,DWORD PTR [eax+0x5f4c]
0x49176e 83c0fe add    eax,0xfffffffe
0x491771 83f816 cmp    eax,0x16
0x491774 7776 ja     0x4917ec
0x491776 0fb69024204900 movzx  edx,BYTE PTR [eax+0x492024]
0x49177d ff24951c204900 jmp    DWORD PTR [edx*4+0x49201c]
0x491784 a108f7fd00 mov    eax,ds:0xfdf708
0x491789 2bc3 sub    eax,ebx
0x49178b 7442 je     0x4917cf
0x49178d be01000000 mov    esi,0x1
0x491792 2bc6 sub    eax,esi
0x491794 7422 je     0x4917b8
0x491796 2bc6 sub    eax,esi
0x491798 756e jne    0x491808
0x49179a e8a187ffff call   0x489f40
0x49179f 89b04c4d0000 mov    DWORD PTR [eax+0x4d4c],esi
0x4917a5 e83688ffff call   0x489fe0
0x4917aa 89b0bc000000 mov    DWORD PTR [eax+0xbc],esi
0x4917b0 893530a8fb00 mov    DWORD PTR ds:0xfba830,esi
0x4917b6 eb4a jmp    0x491802
0x4917b8 e88387ffff call   0x489f40
0x4917bd 89984c4d0000 mov    DWORD PTR [eax+0x4d4c],ebx
0x4917c3 c70508f7fd0002000000 mov    DWORD PTR ds:0xfdf708,0x2
0x4917cd eb39 jmp    0x491808
0x4917cf 891d30a8fb00 mov    DWORD PTR ds:0xfba830,ebx
0x4917d5 e80688ffff call   0x489fe0
0x4917da 8998bc000000 mov    DWORD PTR [eax+0xbc],ebx
0x4917e0 c70508f7fd0001000000 mov    DWORD PTR ds:0xfdf708,0x1
0x4917ea eb1c jmp    0x491808
0x4917ec e84f87ffff call   0x489f40
0x4917f1 b901000000 mov    ecx,0x1
0x4917f6 89884c4d0000 mov    DWORD PTR [eax+0x4d4c],ecx
0x4917fc 890d30a8fb00 mov    DWORD PTR ds:0xfba830,ecx
0x491802 891d08f7fd00 mov    DWORD PTR ds:0xfdf708,ebx
0x491808 6a2c push   0x2c
0x49180a ff157824bd00 call   DWORD PTR ds:0xbd2478
0x491810 84c0 test   al,al
0x491812 0f8413010000 je     0x49192b
0x491818 8d442424 lea    eax,[esp+0x24]
0x49181c 50 push   eax
0x49181d ff15f820bd00 call   DWORD PTR ds:0xbd20f8
0x491823 53 push   ebx
0x491824 687c58c000 push   0xc0587c
0x491829 ff155022bd00 call   DWORD PTR ds:0xbd2250
0x49182f f6052888fb0001 test   BYTE PTR ds:0xfb8828,0x1
0x491836 752f jne    0x491867
0x491838 830d2888fb0001 or     DWORD PTR ds:0xfb8828,0x1
0x49183f c78424580300000a000000 mov    DWORD PTR [esp+0x358],0xa
0x49184a e801e00b00 call   0x54f850
0x49184f 6880d5bc00 push   0xbcd580
0x491854 e8c10a4000 call   0x89231a
0x491859 83c404 add    esp,0x4
0x49185c c7842458030000ffffffff mov    DWORD PTR [esp+0x358],0xffffffff
0x491867 803d2592fb0001 cmp    BYTE PTR ds:0xfb9225,0x1
0x49186e 0fb74c2430 movzx  ecx,WORD PTR [esp+0x30]
0x491873 0fb754242e movzx  edx,WORD PTR [esp+0x2e]
0x491878 0fb744242c movzx  eax,WORD PTR [esp+0x2c]
0x49187d 51 push   ecx
0x49187e 0fb74c242e movzx  ecx,WORD PTR [esp+0x2e]
0x491883 52 push   edx
0x491884 0fb754242e movzx  edx,WORD PTR [esp+0x2e]
0x491889 50 push   eax
0x49188a 0fb7442430 movzx  eax,WORD PTR [esp+0x30]
0x49188f 51 push   ecx
0x491890 52 push   edx
0x491891 50 push   eax
0x491892 7547 jne    0x4918db
0x491894 689858c000 push   0xc05898
0x491899 8d942458010000 lea    edx,[esp+0x158]
0x4918a0 e82b760000 call   0x498ed0
0x4918a5 8b4c243c mov    ecx,DWORD PTR [esp+0x3c]
0x4918a9 8b4110 mov    eax,DWORD PTR [ecx+0x10]
0x4918ac 83c41c add    esp,0x1c
0x4918af 8d4c2414 lea    ecx,[esp+0x14]
0x4918b3 51 push   ecx
0x4918b4 53 push   ebx
0x4918b5 53 push   ebx
0x4918b6 895c2420 mov    DWORD PTR [esp+0x20],ebx
0x4918ba 8b10 mov    edx,DWORD PTR [eax]
0x4918bc 8b5248 mov    edx,DWORD PTR [edx+0x48]
0x4918bf 53 push   ebx
0x4918c0 50 push   eax
0x4918c1 ffd2 call   edx
0x4918c3 8b442414 mov    eax,DWORD PTR [esp+0x14]
0x4918c7 53 push   ebx
0x4918c8 53 push   ebx
0x4918c9 50 push   eax
0x4918ca 53 push   ebx
0x4918cb 8d8c244c010000 lea    ecx,[esp+0x14c]
0x4918d2 51 push   ecx
0x4918d3 ff15f425bd00 call   DWORD PTR ds:0xbd25f4
0x4918d9 eb40 jmp    0x49191b
0x4918db 68dc58c000 push   0xc058dc
0x4918e0 8d542450 lea    edx,[esp+0x50]
0x4918e4 e8a704f7ff call   0x401d90
0x4918e9 8b74243c mov    esi,DWORD PTR [esp+0x3c]
0x4918ed 8b4610 mov    eax,DWORD PTR [esi+0x10]
0x4918f0 83c41c add    esp,0x1c
0x4918f3 8d542414 lea    edx,[esp+0x14]
0x4918f7 52 push   edx
0x4918f8 53 push   ebx
0x4918f9 53 push   ebx
0x4918fa 895c2420 mov    DWORD PTR [esp+0x20],ebx
0x4918fe 8b08 mov    ecx,DWORD PTR [eax]
0x491900 53 push   ebx
0x491901 50 push   eax
0x491902 8b4148 mov    eax,DWORD PTR [ecx+0x48]
0x491905 ffd0 call   eax
0x491907 8b542414 mov    edx,DWORD PTR [esp+0x14]
0x49190b 8d4c2434 lea    ecx,[esp+0x34]
0x49190f 51 push   ecx
0x491910 8b4e10 mov    ecx,DWORD PTR [esi+0x10]
0x491913 e8285f2400 call   0x6d7840
0x491918 83c404 add    esp,0x4
0x49191b 8b442414 mov    eax,DWORD PTR [esp+0x14]
0x49191f 3bc3 cmp    eax,ebx
0x491921 7408 je     0x49192b
0x491923 8b10 mov    edx,DWORD PTR [eax]
0x491925 50 push   eax
0x491926 8b4208 mov    eax,DWORD PTR [edx+0x8]
0x491929 ffd0 call   eax
0x49192b f605d0acfb0001 test   BYTE PTR ds:0xfbacd0,0x1
0x491932 753a jne    0x49196e
0x491934 830dd0acfb0001 or     DWORD PTR ds:0xfbacd0,0x1
0x49193b c78424580300000b000000 mov    DWORD PTR [esp+0x358],0xb
0x491946 891dd4acfb00 mov    DWORD PTR ds:0xfbacd4,ebx
0x49194c e8af492400 call   0x6d6300
0x491951 6870d6bc00 push   0xbcd670
0x491956 a3d4acfb00 mov    ds:0xfbacd4,eax
0x49195b e8ba094000 call   0x89231a
0x491960 83c404 add    esp,0x4
0x491963 c7842458030000ffffffff mov    DWORD PTR [esp+0x358],0xffffffff
0x49196e 8b0dd4acfb00 mov    ecx,DWORD PTR ds:0xfbacd4
0x491974 3bcb cmp    ecx,ebx
0x491976 7407 je     0x49197f
0x491978 8b11 mov    edx,DWORD PTR [ecx]
0x49197a 8b4208 mov    eax,DWORD PTR [edx+0x8]
0x49197d ffd0 call   eax
0x49197f 8b7c2420 mov    edi,DWORD PTR [esp+0x20]
0x491983 8d9f40010000 lea    ebx,[edi+0x140]
0x491989 53 push   ebx
0x49198a e8b12d3700 call   0x804740
0x49198f f605cc10fc0001 test   BYTE PTR ds:0xfc10cc,0x1
0x491996 752f jne    0x4919c7
0x491998 830dcc10fc0001 or     DWORD PTR ds:0xfc10cc,0x1
0x49199f c78424580300000c000000 mov    DWORD PTR [esp+0x358],0xc
0x4919aa e841263700 call   0x803ff0
0x4919af 6890dcbc00 push   0xbcdc90
0x4919b4 e861094000 call   0x89231a
0x4919b9 83c404 add    esp,0x4
0x4919bc c7842458030000ffffffff mov    DWORD PTR [esp+0x358],0xffffffff
0x4919c7 f605cc10fc0001 test   BYTE PTR ds:0xfc10cc,0x1
0x4919ce 0fb605fa11fc00 movzx  eax,BYTE PTR ds:0xfc11fa
0x4919d5 8d0c40 lea    ecx,[eax+eax*2]
0x4919d8 8b34cd4011fc00 mov    esi,DWORD PTR [ecx*8+0xfc1140]
0x4919df 752f jne    0x491a10
0x4919e1 830dcc10fc0001 or     DWORD PTR ds:0xfc10cc,0x1
0x4919e8 c78424580300000d000000 mov    DWORD PTR [esp+0x358],0xd
0x4919f3 e8f8253700 call   0x803ff0
0x4919f8 6890dcbc00 push   0xbcdc90
0x4919fd e818094000 call   0x89231a
0x491a02 83c404 add    esp,0x4
0x491a05 c7842458030000ffffffff mov    DWORD PTR [esp+0x358],0xffffffff
0x491a10 33c0 xor    eax,eax
0x491a12 3805fa11fc00 cmp    BYTE PTR ds:0xfc11fa,al
0x491a18 0f94c0 sete   al
0x491a1b 8d1440 lea    edx,[eax+eax*2]
0x491a1e 8b04d54011fc00 mov    eax,DWORD PTR [edx*8+0xfc1140]
0x491a25 03c6 add    eax,esi
0x491a27 83bf20c0000000 cmp    DWORD PTR [edi+0xc020],0x0
0x491a2e 8db720c00000 lea    esi,[edi+0xc020]
0x491a34 7403 je     0x491a39
0x491a36 014648 add    DWORD PTR [esi+0x48],eax
0x491a39 e8b2942400 call   0x6daef0
0x491a3e f6059043f90001 test   BYTE PTR ds:0xf94390,0x1
0x491a45 752f jne    0x491a76
0x491a47 830d9043f90001 or     DWORD PTR ds:0xf94390,0x1
0x491a4e c78424580300000e000000 mov    DWORD PTR [esp+0x358],0xe
0x491a59 e832fb0400 call   0x4e1590
0x491a5e 6880ccbc00 push   0xbccc80
0x491a63 e8b2084000 call   0x89231a
0x491a68 83c404 add    esp,0x4
0x491a6b c7842458030000ffffffff mov    DWORD PTR [esp+0x358],0xffffffff
0x491a76 833d3439f90005 cmp    DWORD PTR ds:0xf93934,0x5
0x491a7d 0f8cb7010000 jl     0x491c3a
0x491a83 f6059043f90001 test   BYTE PTR ds:0xf94390,0x1
0x491a8a 752f jne    0x491abb
0x491a8c 830d9043f90001 or     DWORD PTR ds:0xf94390,0x1
0x491a93 c78424580300000f000000 mov    DWORD PTR [esp+0x358],0xf
0x491a9e e8edfa0400 call   0x4e1590
0x491aa3 6880ccbc00 push   0xbccc80
0x491aa8 e86d084000 call   0x89231a
0x491aad 83c404 add    esp,0x4
0x491ab0 c7842458030000ffffffff mov    DWORD PTR [esp+0x358],0xffffffff
0x491abb 8b0d54a8fb00 mov    ecx,DWORD PTR ds:0xfba854
0x491ac1 c7053839f90001000000 mov    DWORD PTR ds:0xf93938,0x1
0x491acb 8b01 mov    eax,DWORD PTR [ecx]
0x491acd 8b5020 mov    edx,DWORD PTR [eax+0x20]
0x491ad0 6a01 push   0x1
0x491ad2 6a00 push   0x0
0x491ad4 ffd2 call   edx
0x491ad6 8b0d54a8fb00 mov    ecx,DWORD PTR ds:0xfba854
0x491adc 8b01 mov    eax,DWORD PTR [ecx]
0x491ade 8b5020 mov    edx,DWORD PTR [eax+0x20]
0x491ae1 6a01 push   0x1
0x491ae3 6a01 push   0x1
0x491ae5 ffd2 call   edx
0x491ae7 8b0d54a8fb00 mov    ecx,DWORD PTR ds:0xfba854
0x491aed 8b01 mov    eax,DWORD PTR [ecx]
0x491aef 8b5020 mov    edx,DWORD PTR [eax+0x20]
0x491af2 6a01 push   0x1
0x491af4 6a02 push   0x2
0x491af6 ffd2 call   edx
0x491af8 8bf7 mov    esi,edi
0x491afa e8a1d22400 call   0x6deda0
0x491aff 680059c000 push   0xc05900
0x491b04 e8f7c12500 call   0x6edd00
0x491b09 83c404 add    esp,0x4
0x491b0c e8bf882500 call   0x6ea3d0
0x491b11 f6052c5bfe0001 test   BYTE PTR ds:0xfe5b2c,0x1
0x491b18 8ad8 mov    bl,al
0x491b1a 7534 jne    0x491b50
0x491b1c 830d2c5bfe0001 or     DWORD PTR ds:0xfe5b2c,0x1
0x491b23 680c5bfe00 push   0xfe5b0c
0x491b28 c784245c03000010000000 mov    DWORD PTR [esp+0x35c],0x10
0x491b33 e808310f00 call   0x584c40
0x491b38 6870f3bc00 push   0xbcf370
0x491b3d e8d8074000 call   0x89231a
0x491b42 83c404 add    esp,0x4
0x491b45 c7842458030000ffffffff mov    DWORD PTR [esp+0x358],0xffffffff
0x491b50 8d44241c lea    eax,[esp+0x1c]
0x491b54 50 push   eax
0x491b55 8d44241c lea    eax,[esp+0x1c]
0x491b59 b90c5bfe00 mov    ecx,0xfe5b0c
0x491b5e c744242099010000 mov    DWORD PTR [esp+0x20],0x199
0x491b66 e885250e00 call   0x5740f0
0x491b6b 8b442418 mov    eax,DWORD PTR [esp+0x18]
0x491b6f 3b05105bfe00 cmp    eax,DWORD PTR ds:0xfe5b10
0x491b75 7410 je     0x491b87
0x491b77 83782408 cmp    DWORD PTR [eax+0x24],0x8
0x491b7b 7205 jb     0x491b82
0x491b7d 8b7010 mov    esi,DWORD PTR [eax+0x10]
0x491b80 eb0b jmp    0x491b8d
0x491b82 8d7010 lea    esi,[eax+0x10]
0x491b85 eb06 jmp    0x491b8d
0x491b87 cc int3
0x491b88 befcd1be00 mov    esi,0xbed1fc
0x491b8d f6052c5bfe0001 test   BYTE PTR ds:0xfe5b2c,0x1
0x491b94 7534 jne    0x491bca
0x491b96 830d2c5bfe0001 or     DWORD PTR ds:0xfe5b2c,0x1
0x491b9d 680c5bfe00 push   0xfe5b0c
0x491ba2 c784245c03000011000000 mov    DWORD PTR [esp+0x35c],0x11
0x491bad e88e300f00 call   0x584c40
0x491bb2 6870f3bc00 push   0xbcf370
0x491bb7 e85e074000 call   0x89231a
0x491bbc 83c404 add    esp,0x4
0x491bbf c7842458030000ffffffff mov    DWORD PTR [esp+0x358],0xffffffff
0x491bca 8d4c241c lea    ecx,[esp+0x1c]
0x491bce 51 push   ecx
0x491bcf 8d44241c lea    eax,[esp+0x1c]
0x491bd3 b90c5bfe00 mov    ecx,0xfe5b0c
0x491bd8 c74424208d010000 mov    DWORD PTR [esp+0x20],0x18d
0x491be0 e80b250e00 call   0x5740f0
0x491be5 8b442418 mov    eax,DWORD PTR [esp+0x18]
0x491be9 3b05105bfe00 cmp    eax,DWORD PTR ds:0xfe5b10
0x491bef 740d je     0x491bfe
0x491bf1 83c010 add    eax,0x10
0x491bf4 83781408 cmp    DWORD PTR [eax+0x14],0x8
0x491bf8 720a jb     0x491c04
0x491bfa 8b00 mov    eax,DWORD PTR [eax]
0x491bfc eb06 jmp    0x491c04
0x491bfe cc int3
0x491bff b8fcd1be00 mov    eax,0xbed1fc
0x491c04 33d2 xor    edx,edx
0x491c06 84db test   bl,bl
0x491c08 0f95c2 setne  dl
0x491c0b 4a dec    edx
0x491c0c 81e200000400 and    edx,0x40000
0x491c12 52 push   edx
0x491c13 56 push   esi
0x491c14 50 push   eax
0x491c15 e846e12400 call   0x6dfd60
0x491c1a 50 push   eax
0x491c1b ff158025bd00 call   DWORD PTR ds:0xbd2580
0x491c21 6a01 push   0x1
0x491c23 6a00 push   0x0
0x491c25 6a10 push   0x10
0x491c27 e834e12400 call   0x6dfd60
0x491c2c 50 push   eax
0x491c2d ff154c24bd00 call   DWORD PTR ds:0xbd244c
0x491c33 33c0 xor    eax,eax
0x491c35 e9bb030000 jmp    0x491ff5
0x491c3a 8b8768bf0000 mov    eax,DWORD PTR [edi+0xbf68]
0x491c40 33f6 xor    esi,esi
0x491c42 83f8ff cmp    eax,0xffffffff
0x491c45 7460 je     0x491ca7
0x491c47 3935aca7fb00 cmp    DWORD PTR ds:0xfba7ac,esi
0x491c4d 7458 je     0x491ca7
0x491c4f 83f821 cmp    eax,0x21
0x491c52 7f4a jg     0x491c9e
0x491c54 b810000000 mov    eax,0x10
0x491c59 c78768bf0000a00f0000 mov    DWORD PTR [edi+0xbf68],0xfa0
0x491c63 6689442414 mov    WORD PTR [esp+0x14],ax
0x491c68 393598a7fb00 cmp    DWORD PTR ds:0xfba798,esi
0x491c6e 7515 jne    0x491c85
0x491c70 8b0d54a8fb00 mov    ecx,DWORD PTR ds:0xfba854
0x491c76 8b11 mov    edx,DWORD PTR [ecx]
0x491c78 8b5210 mov    edx,DWORD PTR [edx+0x10]
0x491c7b 6a02 push   0x2
0x491c7d 8d442418 lea    eax,[esp+0x18]
0x491c81 50 push   eax
0x491c82 56 push   esi
0x491c83 ffd2 call   edx
0x491c85 ff15a025bd00 call   DWORD PTR ds:0xbd25a0
0x491c8b 898764bf0000 mov    DWORD PTR [edi+0xbf64],eax
0x491c91 e80a2ff7ff call   0x404ba0
0x491c96 ff80545f0000 inc    DWORD PTR [eax+0x5f54]
0x491c9c eb09 jmp    0x491ca7
0x491c9e 83c0df add    eax,0xffffffdf
0x491ca1 898768bf0000 mov    DWORD PTR [edi+0xbf68],eax
0x491ca7 39b7ccbf0000 cmp    DWORD PTR [edi+0xbfcc],esi
0x491cad 7554 jne    0x491d03
0x491caf e8acd3f7ff call   0x40f060
0x491cb4 8bc8 mov    ecx,eax
0x491cb6 e8a5e30400 call   0x4e0060
0x491cbb e8a07fffff call   0x489c60
0x491cc0 50 push   eax
0x491cc1 e86a78ffff call   0x489530
0x491cc6 e86524faff call   0x434130
0x491ccb 8b08 mov    ecx,DWORD PTR [eax]
0x491ccd 3bce cmp    ecx,esi
0x491ccf 7407 je     0x491cd8
0x491cd1 8b01 mov    eax,DWORD PTR [ecx]
0x491cd3 8b5014 mov    edx,DWORD PTR [eax+0x14]
0x491cd6 ffd2 call   edx
0x491cd8 e8d37fffff call   0x489cb0
0x491cdd 8b88ac5e0000 mov    ecx,DWORD PTR [eax+0x5eac]
0x491ce3 3bce cmp    ecx,esi
0x491ce5 740d je     0x491cf4
0x491ce7 8b01 mov    eax,DWORD PTR [ecx]
0x491ce9 8b5018 mov    edx,DWORD PTR [eax+0x18]
0x491cec ffd2 call   edx
0x491cee 89442418 mov    DWORD PTR [esp+0x18],eax
0x491cf2 eb04 jmp    0x491cf8
0x491cf4 89742418 mov    DWORD PTR [esp+0x18],esi
0x491cf8 e843940000 call   0x49b140
0x491cfd 50 push   eax
0x491cfe e8bdf10b00 call   0x550ec0
0x491d03 f605d894fd0001 test   BYTE PTR ds:0xfd94d8,0x1
0x491d0a 752f jne    0x491d3b
0x491d0c 830dd894fd0001 or     DWORD PTR ds:0xfd94d8,0x1
0x491d13 c784245803000012000000 mov    DWORD PTR [esp+0x358],0x12
0x491d1e e80d373200 call   0x7b5430
0x491d23 6860e6bc00 push   0xbce660
0x491d28 e8ed054000 call   0x89231a
0x491d2d 83c404 add    esp,0x4
0x491d30 c7842458030000ffffffff mov    DWORD PTR [esp+0x358],0xffffffff
0x491d3b 682094fd00 push   0xfd9420
0x491d40 e8eb453200 call   0x7b6330
0x491d45 f6050894fd0001 test   BYTE PTR ds:0xfd9408,0x1
0x491d4c 0f57c0 xorps  xmm0,xmm0
0x491d4f bf01000000 mov    edi,0x1
0x491d54 7522 jne    0x491d78
0x491d56 093d0894fd00 or     DWORD PTR ds:0xfd9408,edi
0x491d5c 89350c94fd00 mov    DWORD PTR ds:0xfd940c,esi
0x491d62 89351094fd00 mov    DWORD PTR ds:0xfd9410,esi
0x491d68 89351494fd00 mov    DWORD PTR ds:0xfd9414,esi
0x491d6e f30f11051894fd00 movss  DWORD PTR ds:0xfd9418,xmm0
0x491d76 eb0e jmp    0x491d86
0x491d78 39350c94fd00 cmp    DWORD PTR ds:0xfd940c,esi
0x491d7e 7e06 jle    0x491d86
0x491d80 ff0d0c94fd00 dec    DWORD PTR ds:0xfd940c
0x491d86 d9051894fd00 fld    DWORD PTR ds:0xfd9418
0x491d8c dc051058c500 fadd   QWORD PTR ds:0xc55810
0x491d92 d91d1894fd00 fstp   DWORD PTR ds:0xfd9418
0x491d98 d9050858c500 fld    DWORD PTR ds:0xc55808
0x491d9e d9051894fd00 fld    DWORD PTR ds:0xfd9418
0x491da4 dff1 fcomip st,st(1)
0x491da6 ddd8 fstp   st(0)
0x491da8 7208 jb     0x491db2
0x491daa f30f11051894fd00 movss  DWORD PTR ds:0xfd9418,xmm0
0x491db2 f605801cfc0001 test   BYTE PTR ds:0xfc1c80,0x1
0x491db9 752f jne    0x491dea
0x491dbb 093d801cfc00 or     DWORD PTR ds:0xfc1c80,edi
0x491dc1 c784245803000013000000 mov    DWORD PTR [esp+0x358],0x13
0x491dcc e8bf980d00 call   0x56b690
0x491dd1 6800e5bc00 push   0xbce500
0x491dd6 e83f054000 call   0x89231a
0x491ddb 83c404 add    esp,0x4
0x491dde 83ceff or     esi,0xffffffff
0x491de1 89b42458030000 mov    DWORD PTR [esp+0x358],esi
0x491de8 eb03 jmp    0x491ded
0x491dea 83ceff or     esi,0xffffffff
0x491ded 68841cfc00 push   0xfc1c84
0x491df2 e8999b0d00 call   0x56b990
0x491df7 f605c01afc0001 test   BYTE PTR ds:0xfc1ac0,0x1
0x491dfe 752a jne    0x491e2a
0x491e00 093dc01afc00 or     DWORD PTR ds:0xfc1ac0,edi
0x491e06 c784245803000014000000 mov    DWORD PTR [esp+0x358],0x14
0x491e11 e8ea620c00 call   0x558100
0x491e16 68a0debc00 push   0xbcdea0
0x491e1b e8fa044000 call   0x89231a
0x491e20 83c404 add    esp,0x4
0x491e23 89b42458030000 mov    DWORD PTR [esp+0x358],esi
0x491e2a 68c41afc00 push   0xfc1ac4
0x491e2f e89c640c00 call   0x5582d0
0x491e34 f6054c74fb0001 test   BYTE PTR ds:0xfb744c,0x1
0x491e3b 752a jne    0x491e67
0x491e3d 093d4c74fb00 or     DWORD PTR ds:0xfb744c,edi
0x491e43 c784245803000015000000 mov    DWORD PTR [esp+0x358],0x15
0x491e4e e80dce0500 call   0x4eec60
0x491e53 6840d1bc00 push   0xbcd140
0x491e58 e8bd044000 call   0x89231a
0x491e5d 83c404 add    esp,0x4
0x491e60 89b42458030000 mov    DWORD PTR [esp+0x358],esi
0x491e67 bf5074fb00 mov    edi,0xfb7450
0x491e6c e8efcc0500 call   0x4eeb60
0x491e71 8b442420 mov    eax,DWORD PTR [esp+0x20]
0x491e75 83b8ccbf000000 cmp    DWORD PTR [eax+0xbfcc],0x0
0x491e7c 0f85c1000000 jne    0x491f43
0x491e82 e84983ffff call   0x48a1d0
0x491e87 50 push   eax
0x491e88 e8f3900c00 call   0x55af80
0x491e8d e81e81ffff call   0x489fb0
0x491e92 50 push   eax
0x491e93 e878b00d00 call   0x56cf10
0x491e98 e803e1faff call   0x43ffa0
0x491e9d 8bf8 mov    edi,eax
0x491e9f 8b4f08 mov    ecx,DWORD PTR [edi+0x8]
0x491ea2 be01000000 mov    esi,0x1
0x491ea7 017740 add    DWORD PTR [edi+0x40],esi
0x491eaa 8b11 mov    edx,DWORD PTR [ecx]
0x491eac 8b4224 mov    eax,DWORD PTR [edx+0x24]
0x491eaf ffd0 call   eax
0x491eb1 8b473c mov    eax,DWORD PTR [edi+0x3c]
0x491eb4 85c0 test   eax,eax
0x491eb6 7e04 jle    0x491ebc
0x491eb8 48 dec    eax
0x491eb9 89473c mov    DWORD PTR [edi+0x3c],eax
0x491ebc 837f3c00 cmp    DWORD PTR [edi+0x3c],0x0
0x491ec0 750e jne    0x491ed0
0x491ec2 8b4f50 mov    ecx,DWORD PTR [edi+0x50]
0x491ec5 894f3c mov    DWORD PTR [edi+0x3c],ecx
0x491ec8 8b4f4c mov    ecx,DWORD PTR [edi+0x4c]
0x491ecb e860362a00 call   0x735530
0x491ed0 e86b10f9ff call   0x422f40
0x491ed5 8bc8 mov    ecx,eax
0x491ed7 e844f60c00 call   0x561520
0x491edc e8cf81ffff call   0x48a0b0
0x491ee1 e8eada0c00 call   0x55f9d0
0x491ee6 e83582ffff call   0x48a120
0x491eeb 8bc8 mov    ecx,eax
0x491eed e87e000f00 call   0x581f70
0x491ef2 f6050c8ffd0001 test   BYTE PTR ds:0xfd8f0c,0x1
0x491ef9 7518 jne    0x491f13
0x491efb 09350c8ffd00 or     DWORD PTR ds:0xfd8f0c,esi
0x491f01 e81a720c00 call   0x559120
0x491f06 6860dfbc00 push   0xbcdf60
0x491f0b e80a044000 call   0x89231a
0x491f10 83c404 add    esp,0x4
0x491f13 be108ffd00 mov    esi,0xfd8f10
0x491f18 e873740c00 call   0x559390
0x491f1d e86e82ffff call   0x48a190
0x491f22 e8b9220c00 call   0x5541e0
0x491f27 e8a40ff9ff call   0x422ed0
0x491f2c 50 push   eax
0x491f2d e8be180c00 call   0x5537f0
0x491f32 e8e927f8ff call   0x414720
0x491f37 8bf0 mov    esi,eax
0x491f39 e892f50d00 call   0x5714d0
0x491f3e e8fd27faff call   0x434740
0x491f43 f605a472fb0001 test   BYTE PTR ds:0xfb72a4,0x1
0x491f4a 752f jne    0x491f7b
0x491f4c 830da472fb0001 or     DWORD PTR ds:0xfb72a4,0x1
0x491f53 c784245803000016000000 mov    DWORD PTR [esp+0x358],0x16
0x491f5e e8edd80000 call   0x49f850
0x491f63 68e0cfbc00 push   0xbccfe0
0x491f68 e8ad034000 call   0x89231a
0x491f6d 83c404 add    esp,0x4
0x491f70 c7842458030000ffffffff mov    DWORD PTR [esp+0x358],0xffffffff
0x491f7b 68a872fb00 push   0xfb72a8
0x491f80 e8cbda0000 call   0x49fa50
0x491f85 f605d4b0fa0001 test   BYTE PTR ds:0xfab0d4,0x1
0x491f8c 752f jne    0x491fbd
0x491f8e 830dd4b0fa0001 or     DWORD PTR ds:0xfab0d4,0x1
0x491f95 c784245803000017000000 mov    DWORD PTR [esp+0x358],0x17
0x491fa0 e8fb833700 call   0x80a3a0
0x491fa5 68d0cdbc00 push   0xbccdd0
0x491faa e86b034000 call   0x89231a
0x491faf 83c404 add    esp,0x4
0x491fb2 c7842458030000ffffffff mov    DWORD PTR [esp+0x358],0xffffffff
0x491fbd 6828b0fa00 push   0xfab028
0x491fc2 e849943700 call   0x80b410
0x491fc7 e86433f9ff call   0x425330
0x491fcc 8bf0 mov    esi,eax
0x491fce e8ad4b0600 call   0x4f6b80
0x491fd3 80bb9000000000 cmp    BYTE PTR [ebx+0x90],0x0
0x491fda 7508 jne    0x491fe4
0x491fdc 53 push   ebx
0x491fdd e85e2a3700 call   0x804a40
0x491fe2 eb07 jmp    0x491feb
0x491fe4 8bf3 mov    esi,ebx
0x491fe6 e8852c3700 call   0x804c70
0x491feb 53 push   ebx
0x491fec e8cf2f3700 call   0x804fc0
0x491ff1 8b442418 mov    eax,DWORD PTR [esp+0x18]
0x491ff5 8b8c2450030000 mov    ecx,DWORD PTR [esp+0x350]
0x491ffc 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x492003 59 pop    ecx
0x492004 5f pop    edi
0x492005 5e pop    esi
0x492006 5b pop    ebx
0x492007 8b8c2438030000 mov    ecx,DWORD PTR [esp+0x338]
0x49200e 33cc xor    ecx,esp
0x492010 e8ecef3f00 call   0x891001
0x492015 8be5 mov    esp,ebp
0x492017 5d pop    ebp
0x492018 c20400 ret    0x4

; reused_q_end_target 0x561db0..0x5620aa raw=0x1611b0 sha256=7223d999bb2cbb1f717f5abc13332fde0f434450d5a8428bcc680ce276e3324b
0x561db0 55 push   ebp
0x561db1 8bec mov    ebp,esp
0x561db3 83e4f8 and    esp,0xfffffff8
0x561db6 6aff push   0xffffffff
0x561db8 6864fc9300 push   0x93fc64
0x561dbd 64a100000000 mov    eax,fs:0x0
0x561dc3 50 push   eax
0x561dc4 83ec10 sub    esp,0x10
0x561dc7 53 push   ebx
0x561dc8 56 push   esi
0x561dc9 57 push   edi
0x561dca a1201fd600 mov    eax,ds:0xd61f20
0x561dcf 33c4 xor    eax,esp
0x561dd1 50 push   eax
0x561dd2 8d442420 lea    eax,[esp+0x20]
0x561dd6 64a300000000 mov    fs:0x0,eax
0x561ddc 8bf9 mov    edi,ecx
0x561dde 33f6 xor    esi,esi
0x561de0 80bf8900000000 cmp    BYTE PTR [edi+0x89],0x0
0x561de7 0f8473010000 je     0x561f60
0x561ded 397728 cmp    DWORD PTR [edi+0x28],esi
0x561df0 0f84aa000000 je     0x561ea0
0x561df6 897728 mov    DWORD PTR [edi+0x28],esi
0x561df9 e85224edff call   0x434250
0x561dfe bb01000000 mov    ebx,0x1
0x561e03 895814 mov    DWORD PTR [eax+0x14],ebx
0x561e06 841dd4f3fd00 test   BYTE PTR ds:0xfdf3d4,bl
0x561e0c 7525 jne    0x561e33
0x561e0e 091dd4f3fd00 or     DWORD PTR ds:0xfdf3d4,ebx
0x561e14 89742428 mov    DWORD PTR [esp+0x28],esi
0x561e18 e863251900 call   0x6f4380
0x561e1d 68d0e6bc00 push   0xbce6d0
0x561e22 e8f3043300 call   0x89231a
0x561e27 83c404 add    esp,0x4
0x561e2a 83ceff or     esi,0xffffffff
0x561e2d 89742428 mov    DWORD PTR [esp+0x28],esi
0x561e31 eb03 jmp    0x561e36
0x561e33 83ceff or     esi,0xffffffff
0x561e36 68ec06c100 push   0xc106ec
0x561e3b 6a00 push   0x0
0x561e3d 68c8f3fd00 push   0xfdf3c8
0x561e42 e859b2f4ff call   0x4ad0a0
0x561e47 f605d4adfa0001 test   BYTE PTR ds:0xfaadd4,0x1
0x561e4e 7520 jne    0x561e70
0x561e50 091dd4adfa00 or     DWORD PTR ds:0xfaadd4,ebx
0x561e56 895c2428 mov    DWORD PTR [esp+0x28],ebx
0x561e5a e821560200 call   0x587480
0x561e5f 68c0ccbc00 push   0xbcccc0
0x561e64 e8b1043300 call   0x89231a
0x561e69 83c404 add    esp,0x4
0x561e6c 89742428 mov    DWORD PTR [esp+0x28],esi
0x561e70 d98784000000 fld    DWORD PTR [edi+0x84]
0x561e76 83ec08 sub    esp,0x8
0x561e79 d95c241c fstp   DWORD PTR [esp+0x1c]
0x561e7d d944241c fld    DWORD PTR [esp+0x1c]
0x561e81 d9542404 fst    DWORD PTR [esp+0x4]
0x561e85 d91c24 fstp   DWORD PTR [esp]
0x561e88 e8937b0200 call   0x589a20
0x561e8d 8a9f88000000 mov    bl,BYTE PTR [edi+0x88]
0x561e93 e8082deaff call   0x404ba0
0x561e98 8898c4680000 mov    BYTE PTR [eax+0x68c4],bl
0x561e9e eb03 jmp    0x561ea3
0x561ea0 83ceff or     esi,0xffffffff
0x561ea3 f605640ffc0001 test   BYTE PTR ds:0xfc0f64,0x1
0x561eaa 7525 jne    0x561ed1
0x561eac 830d640ffc0001 or     DWORD PTR ds:0xfc0f64,0x1
0x561eb3 c744242802000000 mov    DWORD PTR [esp+0x28],0x2
0x561ebb e820bef1ff call   0x47dce0
0x561ec0 68f0dabc00 push   0xbcdaf0
0x561ec5 e850043300 call   0x89231a
0x561eca 83c404 add    esp,0x4
0x561ecd 89742428 mov    DWORD PTR [esp+0x28],esi
0x561ed1 8b473c mov    eax,DWORD PTR [edi+0x3c]
0x561ed4 8b4f38 mov    ecx,DWORD PTR [edi+0x38]
0x561ed7 50 push   eax
0x561ed8 51 push   ecx
0x561ed9 68680ffc00 push   0xfc0f68
0x561ede e85dc7f1ff call   0x47e640
0x561ee3 33db xor    ebx,ebx
0x561ee5 89473c mov    DWORD PTR [edi+0x3c],eax
0x561ee8 3bc3 cmp    eax,ebx
0x561eea 741f je     0x561f0b
0x561eec 8b5738 mov    edx,DWORD PTR [edi+0x38]
0x561eef 50 push   eax
0x561ef0 52 push   edx
0x561ef1 8bf7 mov    esi,edi
0x561ef3 e828380000 call   0x565720
0x561ef8 8b4c2420 mov    ecx,DWORD PTR [esp+0x20]
0x561efc 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x561f03 59 pop    ecx
0x561f04 5f pop    edi
0x561f05 5e pop    esi
0x561f06 5b pop    ebx
0x561f07 8be5 mov    esp,ebp
0x561f09 5d pop    ebp
0x561f0a c3 ret
0x561f0b f605c00ffc0001 test   BYTE PTR ds:0xfc0fc0,0x1
0x561f12 7525 jne    0x561f39
0x561f14 830dc00ffc0001 or     DWORD PTR ds:0xfc0fc0,0x1
0x561f1b c744242803000000 mov    DWORD PTR [esp+0x28],0x3
0x561f23 e8286f1700 call   0x6d8e50
0x561f28 68b0dbbc00 push   0xbcdbb0
0x561f2d e8e8033300 call   0x89231a
0x561f32 83c404 add    esp,0x4
0x561f35 89742428 mov    DWORD PTR [esp+0x28],esi
0x561f39 8b4734 mov    eax,DWORD PTR [edi+0x34]
0x561f3c 50 push   eax
0x561f3d b9c80ffc00 mov    ecx,0xfc0fc8
0x561f42 e8e9741700 call   0x6d9430
0x561f47 895f38 mov    DWORD PTR [edi+0x38],ebx
0x561f4a 895f3c mov    DWORD PTR [edi+0x3c],ebx
0x561f4d 8b4c2420 mov    ecx,DWORD PTR [esp+0x20]
0x561f51 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x561f58 59 pop    ecx
0x561f59 5f pop    edi
0x561f5a 5e pop    esi
0x561f5b 5b pop    ebx
0x561f5c 8be5 mov    esp,ebp
0x561f5e 5d pop    ebp
0x561f5f c3 ret
0x561f60 397728 cmp    DWORD PTR [edi+0x28],esi
0x561f63 0f8428010000 je     0x562091
0x561f69 897728 mov    DWORD PTR [edi+0x28],esi
0x561f6c e8df22edff call   0x434250
0x561f71 bb01000000 mov    ebx,0x1
0x561f76 895814 mov    DWORD PTR [eax+0x14],ebx
0x561f79 397738 cmp    DWORD PTR [edi+0x38],esi
0x561f7c 7439 je     0x561fb7
0x561f7e 684403c100 push   0xc10344
0x561f83 53 push   ebx
0x561f84 e8a792f3ff call   0x49b230
0x561f89 50 push   eax
0x561f8a e811b1f4ff call   0x4ad0a0
0x561f8f 6aff push   0xffffffff
0x561f91 51 push   ecx
0x561f92 e89992f3ff call   0x49b230
0x561f97 83c404 add    esp,0x4
0x561f9a e8b10bf4ff call   0x4a2b50
0x561f9f 3bc3 cmp    eax,ebx
0x561fa1 754e jne    0x561ff1
0x561fa3 e8d826ebff call   0x414680
0x561fa8 8b4f3c mov    ecx,DWORD PTR [edi+0x3c]
0x561fab 8b5738 mov    edx,DWORD PTR [edi+0x38]
0x561fae 51 push   ecx
0x561faf 52 push   edx
0x561fb0 e8eb19f4ff call   0x4a39a0
0x561fb5 eb3a jmp    0x561ff1
0x561fb7 8d5f3c lea    ebx,[edi+0x3c]
0x561fba 8d7774 lea    esi,[edi+0x74]
0x561fbd 53 push   ebx
0x561fbe e87dbe1500 call   0x6bde40
0x561fc3 50 push   eax
0x561fc4 56 push   esi
0x561fc5 8d74241c lea    esi,[esp+0x1c]
0x561fc9 e8c248edff call   0x436890
0x561fce 57 push   edi
0x561fcf e8cc030000 call   0x5623a0
0x561fd4 e8a726ebff call   0x414680
0x561fd9 8b03 mov    eax,DWORD PTR [ebx]
0x561fdb 8b4f38 mov    ecx,DWORD PTR [edi+0x38]
0x561fde 50 push   eax
0x561fdf 51 push   ecx
0x561fe0 e8bb19f4ff call   0x4a39a0
0x561fe5 e8c6000000 call   0x5620b0
0x561fea bb01000000 mov    ebx,0x1
0x561fef 33f6 xor    esi,esi
0x561ff1 f605d4f3fd0001 test   BYTE PTR ds:0xfdf3d4,0x1
0x561ff8 7528 jne    0x562022
0x561ffa 091dd4f3fd00 or     DWORD PTR ds:0xfdf3d4,ebx
0x562000 c744242804000000 mov    DWORD PTR [esp+0x28],0x4
0x562008 e873231900 call   0x6f4380
0x56200d 68d0e6bc00 push   0xbce6d0
0x562012 e803033300 call   0x89231a
0x562017 83c404 add    esp,0x4
0x56201a c7442428ffffffff mov    DWORD PTR [esp+0x28],0xffffffff
0x562022 68ec06c100 push   0xc106ec
0x562027 56 push   esi
0x562028 68c8f3fd00 push   0xfdf3c8
0x56202d e86eb0f4ff call   0x4ad0a0
0x562032 f605d4adfa0001 test   BYTE PTR ds:0xfaadd4,0x1
0x562039 7528 jne    0x562063
0x56203b 091dd4adfa00 or     DWORD PTR ds:0xfaadd4,ebx
0x562041 c744242805000000 mov    DWORD PTR [esp+0x28],0x5
0x562049 e832540200 call   0x587480
0x56204e 68c0ccbc00 push   0xbcccc0
0x562053 e8c2023300 call   0x89231a
0x562058 83c404 add    esp,0x4
0x56205b c7442428ffffffff mov    DWORD PTR [esp+0x28],0xffffffff
0x562063 d98784000000 fld    DWORD PTR [edi+0x84]
0x562069 83ec08 sub    esp,0x8
0x56206c d95c241c fstp   DWORD PTR [esp+0x1c]
0x562070 d944241c fld    DWORD PTR [esp+0x1c]
0x562074 d9542404 fst    DWORD PTR [esp+0x4]
0x562078 d91c24 fstp   DWORD PTR [esp]
0x56207b e8a0790200 call   0x589a20
0x562080 8a9f88000000 mov    bl,BYTE PTR [edi+0x88]
0x562086 e8152beaff call   0x404ba0
0x56208b 8898c4680000 mov    BYTE PTR [eax+0x68c4],bl
0x562091 897738 mov    DWORD PTR [edi+0x38],esi
0x562094 89773c mov    DWORD PTR [edi+0x3c],esi
0x562097 8b4c2420 mov    ecx,DWORD PTR [esp+0x20]
0x56209b 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x5620a2 59 pop    ecx
0x5620a3 5f pop    edi
0x5620a4 5e pop    esi
0x5620a5 5b pop    ebx
0x5620a6 8be5 mov    esp,ebp
0x5620a8 5d pop    ebp
0x5620a9 c3 ret

; reused_input_wait_lock 0x5620b0..0x56224c raw=0x1614b0 sha256=73d8ac8b58f180f16ca6c5362243e76eb479c8e0629253055fd1e35ac6d03c29
0x5620b0 55 push   ebp
0x5620b1 8bec mov    ebp,esp
0x5620b3 6aff push   0xffffffff
0x5620b5 6852ec9200 push   0x92ec52
0x5620ba 64a100000000 mov    eax,fs:0x0
0x5620c0 50 push   eax
0x5620c1 83ec0c sub    esp,0xc
0x5620c4 53 push   ebx
0x5620c5 56 push   esi
0x5620c6 57 push   edi
0x5620c7 a1201fd600 mov    eax,ds:0xd61f20
0x5620cc 33c5 xor    eax,ebp
0x5620ce 50 push   eax
0x5620cf 8d45f4 lea    eax,[ebp-0xc]
0x5620d2 64a300000000 mov    fs:0x0,eax
0x5620d8 33db xor    ebx,ebx
0x5620da f605147cfb0001 test   BYTE PTR ds:0xfb7c14,0x1
0x5620e1 8d7b01 lea    edi,[ebx+0x1]
0x5620e4 7523 jne    0x562109
0x5620e6 093d147cfb00 or     DWORD PTR ds:0xfb7c14,edi
0x5620ec 895dfc mov    DWORD PTR [ebp-0x4],ebx
0x5620ef e85ce61600 call   0x6d0750
0x5620f4 6830d5bc00 push   0xbcd530
0x5620f9 e81c023300 call   0x89231a
0x5620fe 83c404 add    esp,0x4
0x562101 83ceff or     esi,0xffffffff
0x562104 8975fc mov    DWORD PTR [ebp-0x4],esi
0x562107 eb03 jmp    0x56210c
0x562109 83ceff or     esi,0xffffffff
0x56210c 830d3088fb0002 or     DWORD PTR ds:0xfb8830,0x2
0x562113 f605d4adfa0001 test   BYTE PTR ds:0xfaadd4,0x1
0x56211a 751e jne    0x56213a
0x56211c 093dd4adfa00 or     DWORD PTR ds:0xfaadd4,edi
0x562122 897dfc mov    DWORD PTR [ebp-0x4],edi
0x562125 e856530200 call   0x587480
0x56212a 68c0ccbc00 push   0xbcccc0
0x56212f e8e6013300 call   0x89231a
0x562134 83c404 add    esp,0x4
0x562137 8975fc mov    DWORD PTR [ebp-0x4],esi
0x56213a 6a14 push   0x14
0x56213c e827f13200 call   0x891268
0x562141 83c404 add    esp,0x4
0x562144 3bc3 cmp    eax,ebx
0x562146 7418 je     0x562160
0x562148 c7000c7bc400 mov    DWORD PTR [eax],0xc47b0c
0x56214e 897004 mov    DWORD PTR [eax+0x4],esi
0x562151 897008 mov    DWORD PTR [eax+0x8],esi
0x562154 89580c mov    DWORD PTR [eax+0xc],ebx
0x562157 c7401022430f00 mov    DWORD PTR [eax+0x10],0xf4322
0x56215e eb02 jmp    0x562162
0x562160 33c0 xor    eax,eax
0x562162 53 push   ebx
0x562163 50 push   eax
0x562164 83ec1c sub    esp,0x1c
0x562167 8bcc mov    ecx,esp
0x562169 8965e8 mov    DWORD PTR [ebp-0x18],esp
0x56216c 53 push   ebx
0x56216d bf07000000 mov    edi,0x7
0x562172 33c0 xor    eax,eax
0x562174 897914 mov    DWORD PTR [ecx+0x14],edi
0x562177 895910 mov    DWORD PTR [ecx+0x10],ebx
0x56217a 68fcd1be00 push   0xbed1fc
0x56217f 668901 mov    WORD PTR [ecx],ax
0x562182 e8d9ffe9ff call   0x402160
0x562187 c745fc02000000 mov    DWORD PTR [ebp-0x4],0x2
0x56218e f6052c5bfe0001 test   BYTE PTR ds:0xfe5b2c,0x1
0x562195 7526 jne    0x5621bd
0x562197 830d2c5bfe0001 or     DWORD PTR ds:0xfe5b2c,0x1
0x56219e 680c5bfe00 push   0xfe5b0c
0x5621a3 c645fc03 mov    BYTE PTR [ebp-0x4],0x3
0x5621a7 e8942a0200 call   0x584c40
0x5621ac 6870f3bc00 push   0xbcf370
0x5621b1 e864013300 call   0x89231a
0x5621b6 83c404 add    esp,0x4
0x5621b9 c645fc02 mov    BYTE PTR [ebp-0x4],0x2
0x5621bd 8d4df0 lea    ecx,[ebp-0x10]
0x5621c0 51 push   ecx
0x5621c1 8d45ec lea    eax,[ebp-0x14]
0x5621c4 b90c5bfe00 mov    ecx,0xfe5b0c
0x5621c9 c745f0be010000 mov    DWORD PTR [ebp-0x10],0x1be
0x5621d0 e81b1f0100 call   0x5740f0
0x5621d5 8b45ec mov    eax,DWORD PTR [ebp-0x14]
0x5621d8 3b05105bfe00 cmp    eax,DWORD PTR ds:0xfe5b10
0x5621de 740d je     0x5621ed
0x5621e0 83782408 cmp    DWORD PTR [eax+0x24],0x8
0x5621e4 8d7010 lea    esi,[eax+0x10]
0x5621e7 720a jb     0x5621f3
0x5621e9 8b36 mov    esi,DWORD PTR [esi]
0x5621eb eb06 jmp    0x5621f3
0x5621ed cc int3
0x5621ee befcd1be00 mov    esi,0xbed1fc
0x5621f3 83ec1c sub    esp,0x1c
0x5621f6 8bcc mov    ecx,esp
0x5621f8 897914 mov    DWORD PTR [ecx+0x14],edi
0x5621fb 33d2 xor    edx,edx
0x5621fd 8bc6 mov    eax,esi
0x5621ff 895910 mov    DWORD PTR [ecx+0x10],ebx
0x562202 8965ec mov    DWORD PTR [ebp-0x14],esp
0x562205 668911 mov    WORD PTR [ecx],dx
0x562208 8d7802 lea    edi,[eax+0x2]
0x56220b eb03 jmp    0x562210
0x56220d 8d4900 lea    ecx,[ecx+0x0]
0x562210 668b10 mov    dx,WORD PTR [eax]
0x562213 83c002 add    eax,0x2
0x562216 663bd3 cmp    dx,bx
0x562219 75f5 jne    0x562210
0x56221b 2bc7 sub    eax,edi
0x56221d d1f8 sar    eax,1
0x56221f 50 push   eax
0x562220 56 push   esi
0x562221 e83affe9ff call   0x402160
0x562226 68c8000000 push   0xc8
0x56222b c745fcffffffff mov    DWORD PTR [ebp-0x4],0xffffffff
0x562232 e839900200 call   0x58b270
0x562237 83c444 add    esp,0x44
0x56223a 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x56223d 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x562244 59 pop    ecx
0x562245 5f pop    edi
0x562246 5e pop    esi
0x562247 5b pop    ebx
0x562248 8be5 mov    esp,ebp
0x56224a 5d pop    ebp
0x56224b c3 ret

; reused_input_wait_unlock 0x562250..0x56231e raw=0x161650 sha256=0936ade31a9152c00b40a290733576e967e959a1f4ec19e1977a0d1767033dab
0x562250 55 push   ebp
0x562251 8bec mov    ebp,esp
0x562253 6aff push   0xffffffff
0x562255 687a739200 push   0x92737a
0x56225a 64a100000000 mov    eax,fs:0x0
0x562260 50 push   eax
0x562261 51 push   ecx
0x562262 53 push   ebx
0x562263 a1201fd600 mov    eax,ds:0xd61f20
0x562268 33c5 xor    eax,ebp
0x56226a 50 push   eax
0x56226b 8d45f4 lea    eax,[ebp-0xc]
0x56226e 64a300000000 mov    fs:0x0,eax
0x562274 bb01000000 mov    ebx,0x1
0x562279 841dd4adfa00 test   BYTE PTR ds:0xfaadd4,bl
0x56227f 7526 jne    0x5622a7
0x562281 091dd4adfa00 or     DWORD PTR ds:0xfaadd4,ebx
0x562287 c745fc00000000 mov    DWORD PTR [ebp-0x4],0x0
0x56228e e8ed510200 call   0x587480
0x562293 68c0ccbc00 push   0xbcccc0
0x562298 e87d003300 call   0x89231a
0x56229d 83c404 add    esp,0x4
0x5622a0 c745fcffffffff mov    DWORD PTR [ebp-0x4],0xffffffff
0x5622a7 841dd0adfa00 test   BYTE PTR ds:0xfaadd0,bl
0x5622ad 7522 jne    0x5622d1
0x5622af 091dd0adfa00 or     DWORD PTR ds:0xfaadd0,ebx
0x5622b5 895dfc mov    DWORD PTR [ebp-0x4],ebx
0x5622b8 e8d3b61e00 call   0x74d990
0x5622bd 6870ccbc00 push   0xbccc70
0x5622c2 e853003300 call   0x89231a
0x5622c7 83c404 add    esp,0x4
0x5622ca c745fcffffffff mov    DWORD PTR [ebp-0x4],0xffffffff
0x5622d1 6822430f00 push   0xf4322
0x5622d6 b81048f900 mov    eax,0xf94810
0x5622db e860111f00 call   0x753440
0x5622e0 841d147cfb00 test   BYTE PTR ds:0xfb7c14,bl
0x5622e6 751f jne    0x562307
0x5622e8 091d147cfb00 or     DWORD PTR ds:0xfb7c14,ebx
0x5622ee c745fc02000000 mov    DWORD PTR [ebp-0x4],0x2
0x5622f5 e856e41600 call   0x6d0750
0x5622fa 6830d5bc00 push   0xbcd530
0x5622ff e816003300 call   0x89231a
0x562304 83c404 add    esp,0x4
0x562307 83253088fb00fd and    DWORD PTR ds:0xfb8830,0xfffffffd
0x56230e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x562311 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x562318 59 pop    ecx
0x562319 5b pop    ebx
0x56231a 8be5 mov    esp,ebp
0x56231c 5d pop    ebp
0x56231d c3 ret

; reused_scene_manager_packet_entry 0x494360..0x4943ac raw=0x93760 sha256=0e40b5fca76c816b3677c994d5747405e088be2527a60e66ee39a059e9c8c323
0x494360 55 push   ebp
0x494361 8bec mov    ebp,esp
0x494363 b801000000 mov    eax,0x1
0x494368 8405f42cfd00 test   BYTE PTR ds:0xfd2cf4,al
0x49436e 752c jne    0x49439c
0x494370 0905f42cfd00 or     DWORD PTR ds:0xfd2cf4,eax
0x494376 c705f82cfd00b46ec000 mov    DWORD PTR ds:0xfd2cf8,0xc06eb4
0x494380 c705a48bfd0000000000 mov    DWORD PTR ds:0xfd8ba4,0x0
0x49438a e8313a0200 call   0x4b7dc0
0x49438f 68f0dcbc00 push   0xbcdcf0
0x494394 e881df3f00 call   0x89231a
0x494399 83c404 add    esp,0x4
0x49439c b9f82cfd00 mov    ecx,0xfd2cf8
0x4943a1 a1f82cfd00 mov    eax,ds:0xfd2cf8
0x4943a6 8b5004 mov    edx,DWORD PTR [eax+0x4]
0x4943a9 5d pop    ebp
0x4943aa ffe2 jmp    edx

; reused_scene_manager_callback_registration 0x4b7dc0..0x4b7ec0 raw=0xb71c0 sha256=fa48613974a308ddf6c2eb90bea82195fc9d77023c4c918585f5e6dc6bcb7f32
0x4b7dc0 b8002dfd00 mov    eax,0xfd2d00
0x4b7dc5 bac07e4b00 mov    edx,0x4b7ec0
0x4b7dca b97523bf00 mov    ecx,0xbf2375
0x4b7dcf 90 nop
0x4b7dd0 8950fc mov    DWORD PTR [eax-0x4],edx
0x4b7dd3 8908 mov    DWORD PTR [eax],ecx
0x4b7dd5 83c008 add    eax,0x8
0x4b7dd8 3da88bfd00 cmp    eax,0xfd8ba8
0x4b7ddd 7cf1 jl     0x4b7dd0
0x4b7ddf c7050c2dfd00007f4b00 mov    DWORD PTR ds:0xfd2d0c,0x4b7f00
0x4b7de9 890d102dfd00 mov    DWORD PTR ds:0xfd2d10,ecx
0x4b7def c7058c8bfd00c08d4b00 mov    DWORD PTR ds:0xfd8b8c,0x4b8dc0
0x4b7df9 890d908bfd00 mov    DWORD PTR ds:0xfd8b90,ecx
0x4b7dff c705fc2ffd00508f4b00 mov    DWORD PTR ds:0xfd2ffc,0x4b8f50
0x4b7e09 890d0030fd00 mov    DWORD PTR ds:0xfd3000,ecx
0x4b7e0f c7054430fd0090904b00 mov    DWORD PTR ds:0xfd3044,0x4b9090
0x4b7e19 890d4830fd00 mov    DWORD PTR ds:0xfd3048,ecx
0x4b7e1f c7056c30fd0060924b00 mov    DWORD PTR ds:0xfd306c,0x4b9260
0x4b7e29 890d7030fd00 mov    DWORD PTR ds:0xfd3070,ecx
0x4b7e2f c705c431fd0020934b00 mov    DWORD PTR ds:0xfd31c4,0x4b9320
0x4b7e39 890dc831fd00 mov    DWORD PTR ds:0xfd31c8,ecx
0x4b7e3f c7052c32fd0010944b00 mov    DWORD PTR ds:0xfd322c,0x4b9410
0x4b7e49 890d3032fd00 mov    DWORD PTR ds:0xfd3230,ecx
0x4b7e4f c7053c32fd0000954b00 mov    DWORD PTR ds:0xfd323c,0x4b9500
0x4b7e59 890d4032fd00 mov    DWORD PTR ds:0xfd3240,ecx
0x4b7e5f c705d431fd00909b4b00 mov    DWORD PTR ds:0xfd31d4,0x4b9b90
0x4b7e69 890dd831fd00 mov    DWORD PTR ds:0xfd31d8,ecx
0x4b7e6f c705e431fd00609c4b00 mov    DWORD PTR ds:0xfd31e4,0x4b9c60
0x4b7e79 890de831fd00 mov    DWORD PTR ds:0xfd31e8,ecx
0x4b7e7f c705d434fd00309d4b00 mov    DWORD PTR ds:0xfd34d4,0x4b9d30
0x4b7e89 890dd834fd00 mov    DWORD PTR ds:0xfd34d8,ecx
0x4b7e8f c705242dfd0030964b00 mov    DWORD PTR ds:0xfd2d24,0x4b9630
0x4b7e99 890d282dfd00 mov    DWORD PTR ds:0xfd2d28,ecx
0x4b7e9f c7050c2efd0070974b00 mov    DWORD PTR ds:0xfd2e0c,0x4b9770
0x4b7ea9 890d102efd00 mov    DWORD PTR ds:0xfd2e10,ecx
0x4b7eaf c705f42ffd00c0994b00 mov    DWORD PTR ds:0xfd2ff4,0x4b99c0
0x4b7eb9 890df82ffd00 mov    DWORD PTR ds:0xfd2ff8,ecx
0x4b7ebf c3 ret

; reused_scene_manager_forward_current 0x4b7ec0..0x4b7ef2 raw=0xb72c0 sha256=feb3d2486a8d0c83cbd7c53b7334ba0935c6a4e1c650c605030b7458927e9ec0
0x4b7ec0 55 push   ebp
0x4b7ec1 8bec mov    ebp,esp
0x4b7ec3 83b9ac5e000000 cmp    DWORD PTR [ecx+0x5eac],0x0
0x4b7eca 740e je     0x4b7eda
0x4b7ecc 8b89ac5e0000 mov    ecx,DWORD PTR [ecx+0x5eac]
0x4b7ed2 8b01 mov    eax,DWORD PTR [ecx]
0x4b7ed4 8b4004 mov    eax,DWORD PTR [eax+0x4]
0x4b7ed7 5d pop    ebp
0x4b7ed8 ffe0 jmp    eax
0x4b7eda 0fbf4d10 movsx  ecx,WORD PTR [ebp+0x10]
0x4b7ede 51 push   ecx
0x4b7edf 68f86dc000 push   0xc06df8
0x4b7ee4 e8775c2300 call   0x6edb60
0x4b7ee9 83c408 add    esp,0x8
0x4b7eec 33c0 xor    eax,eax
0x4b7eee 5d pop    ebp
0x4b7eef c20c00 ret    0xc

; reused_ordinary_secondary_dispatch 0x4c4670..0x4c46f0 raw=0xc3a70 sha256=2deecc04ff570b803612ebcd2157d86b0659367b80cc081f6a10de1a9c8c5223
0x4c4670 55 push   ebp
0x4c4671 8bec mov    ebp,esp
0x4c4673 8b4510 mov    eax,DWORD PTR [ebp+0x10]
0x4c4676 53 push   ebx
0x4c4677 56 push   esi
0x4c4678 57 push   edi
0x4c4679 0fbff8 movsx  edi,ax
0x4c467c 8bf1 mov    esi,ecx
0x4c467e 8b9cfeac5e0000 mov    ebx,DWORD PTR [esi+edi*8+0x5eac]
0x4c4685 85db test   ebx,ebx
0x4c4687 7517 jne    0x4c46a0
0x4c4689 8b4d08 mov    ecx,DWORD PTR [ebp+0x8]
0x4c468c 50 push   eax
0x4c468d 8b450c mov    eax,DWORD PTR [ebp+0xc]
0x4c4690 50 push   eax
0x4c4691 51 push   ecx
0x4c4692 8bce mov    ecx,esi
0x4c4694 e897930300 call   0x4fda30
0x4c4699 5f pop    edi
0x4c469a 5e pop    esi
0x4c469b 5b pop    ebx
0x4c469c 5d pop    ebp
0x4c469d c20c00 ret    0xc
0x4c46a0 8b94feb05e0000 mov    edx,DWORD PTR [esi+edi*8+0x5eb0]
0x4c46a7 6a06 push   0x6
0x4c46a9 686c6cbf00 push   0xbf6c6c
0x4c46ae 52 push   edx
0x4c46af e80ae23c00 call   0x8928be
0x4c46b4 8b4510 mov    eax,DWORD PTR [ebp+0x10]
0x4c46b7 8b4d0c mov    ecx,DWORD PTR [ebp+0xc]
0x4c46ba 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x4c46bd 83c40c add    esp,0xc
0x4c46c0 50 push   eax
0x4c46c1 51 push   ecx
0x4c46c2 52 push   edx
0x4c46c3 8bce mov    ecx,esi
0x4c46c5 ffd3 call   ebx
0x4c46c7 8bd8 mov    ebx,eax
0x4c46c9 81fb05400080 cmp    ebx,0x80004005
0x4c46cf 7516 jne    0x4c46e7
0x4c46d1 8b84feb05e0000 mov    eax,DWORD PTR [esi+edi*8+0x5eb0]
0x4c46d8 50 push   eax
0x4c46d9 57 push   edi
0x4c46da 68746cbf00 push   0xbf6c74
0x4c46df e87c942200 call   0x6edb60
0x4c46e4 83c40c add    esp,0xc
0x4c46e7 5f pop    edi
0x4c46e8 5e pop    esi
0x4c46e9 8bc3 mov    eax,ebx
0x4c46eb 5b pop    ebx
0x4c46ec 5d pop    ebp
0x4c46ed c20c00 ret    0xc

; reused_common_field_callback_registration 0x4add50..0x4ae380 raw=0xad150 sha256=f9cee5546de393ee1584d8c621e067d56f218559a800556f9b1bdcacc1a6d0f7
0x4add50 53 push   ebx
0x4add51 56 push   esi
0x4add52 8d5008 lea    edx,[eax+0x8]
0x4add55 bed50b0000 mov    esi,0xbd5
0x4add5a b97523bf00 mov    ecx,0xbf2375
0x4add5f 90 nop
0x4add60 c742fc407d4b00 mov    DWORD PTR [edx-0x4],0x4b7d40
0x4add67 890a mov    DWORD PTR [edx],ecx
0x4add69 83c208 add    edx,0x8
0x4add6c 4e dec    esi
0x4add6d 75f1 jne    0x4add60
0x4add6f ba80fb4a00 mov    edx,0x4afb80
0x4add74 c74034307d4b00 mov    DWORD PTR [eax+0x34],0x4b7d30
0x4add7b 894838 mov    DWORD PTR [eax+0x38],ecx
0x4add7e c7403cd0e44a00 mov    DWORD PTR [eax+0x3c],0x4ae4d0
0x4add85 894840 mov    DWORD PTR [eax+0x40],ecx
0x4add88 c780f4090000b0ed4a00 mov    DWORD PTR [eax+0x9f4],0x4aedb0
0x4add92 8988f8090000 mov    DWORD PTR [eax+0x9f8],ecx
0x4add98 c7404430f54a00 mov    DWORD PTR [eax+0x44],0x4af530
0x4add9f 894848 mov    DWORD PTR [eax+0x48],ecx
0x4adda2 c7405420f94a00 mov    DWORD PTR [eax+0x54],0x4af920
0x4adda9 894858 mov    DWORD PTR [eax+0x58],ecx
0x4addac c74004f0fa4a00 mov    DWORD PTR [eax+0x4],0x4afaf0
0x4addb3 894808 mov    DWORD PTR [eax+0x8],ecx
0x4addb6 89500c mov    DWORD PTR [eax+0xc],edx
0x4addb9 894810 mov    DWORD PTR [eax+0x10],ecx
0x4addbc c7405c60fe4a00 mov    DWORD PTR [eax+0x5c],0x4afe60
0x4addc3 894860 mov    DWORD PTR [eax+0x60],ecx
0x4addc6 c7406430014b00 mov    DWORD PTR [eax+0x64],0x4b0130
0x4addcd 894868 mov    DWORD PTR [eax+0x68],ecx
0x4addd0 c7406cc0014b00 mov    DWORD PTR [eax+0x6c],0x4b01c0
0x4addd7 894870 mov    DWORD PTR [eax+0x70],ecx
0x4addda c7807c050000d0034b00 mov    DWORD PTR [eax+0x57c],0x4b03d0
0x4adde4 898880050000 mov    DWORD PTR [eax+0x580],ecx
0x4addea c74074406c4300 mov    DWORD PTR [eax+0x74],0x436c40
0x4addf1 894878 mov    DWORD PTR [eax+0x78],ecx
0x4addf4 c780fc09000040194b00 mov    DWORD PTR [eax+0x9fc],0x4b1940
0x4addfe 8988000a0000 mov    DWORD PTR [eax+0xa00],ecx
0x4ade04 c7407cd0194b00 mov    DWORD PTR [eax+0x7c],0x4b19d0
0x4ade0b 898880000000 mov    DWORD PTR [eax+0x80],ecx
0x4ade11 c78084000000301a4b00 mov    DWORD PTR [eax+0x84],0x4b1a30
0x4ade1b 898888000000 mov    DWORD PTR [eax+0x88],ecx
0x4ade21 c7808c000000701a4b00 mov    DWORD PTR [eax+0x8c],0x4b1a70
0x4ade2b 898890000000 mov    DWORD PTR [eax+0x90],ecx
0x4ade31 c7801c020000901a4b00 mov    DWORD PTR [eax+0x21c],0x4b1a90
0x4ade3b 898820020000 mov    DWORD PTR [eax+0x220],ecx
0x4ade41 c78094000000f0244b00 mov    DWORD PTR [eax+0x94],0x4b24f0
0x4ade4b 898898000000 mov    DWORD PTR [eax+0x98],ecx
0x4ade51 c780a400000030594c00 mov    DWORD PTR [eax+0xa4],0x4c5930
0x4ade5b 8988a8000000 mov    DWORD PTR [eax+0xa8],ecx
0x4ade61 c780ac00000020264b00 mov    DWORD PTR [eax+0xac],0x4b2620
0x4ade6b 8988b0000000 mov    DWORD PTR [eax+0xb0],ecx
0x4ade71 8990b4000000 mov    DWORD PTR [eax+0xb4],edx
0x4ade77 8988b8000000 mov    DWORD PTR [eax+0xb8],ecx
0x4ade7d c780c400000030274b00 mov    DWORD PTR [eax+0xc4],0x4b2730
0x4ade87 8988c8000000 mov    DWORD PTR [eax+0xc8],ecx
0x4ade8d c780d4000000d0284b00 mov    DWORD PTR [eax+0xd4],0x4b28d0
0x4ade97 8988d8000000 mov    DWORD PTR [eax+0xd8],ecx
0x4ade9d c780dc00000080e34a00 mov    DWORD PTR [eax+0xdc],0x4ae380
0x4adea7 8988e0000000 mov    DWORD PTR [eax+0xe0],ecx
0x4adead c7803c010000f02a4b00 mov    DWORD PTR [eax+0x13c],0x4b2af0
0x4adeb7 898840010000 mov    DWORD PTR [eax+0x140],ecx
0x4adebd c78044020000e0324b00 mov    DWORD PTR [eax+0x244],0x4b32e0
0x4adec7 898848020000 mov    DWORD PTR [eax+0x248],ecx
0x4adecd c7800c010000d02c4b00 mov    DWORD PTR [eax+0x10c],0x4b2cd0
0x4aded7 898810010000 mov    DWORD PTR [eax+0x110],ecx
0x4adedd c7801401000040304b00 mov    DWORD PTR [eax+0x114],0x4b3040
0x4adee7 898818010000 mov    DWORD PTR [eax+0x118],ecx
0x4adeed c7803401000060304b00 mov    DWORD PTR [eax+0x134],0x4b3060
0x4adef7 898838010000 mov    DWORD PTR [eax+0x138],ecx
0x4adefd c780ec08000060304b00 mov    DWORD PTR [eax+0x8ec],0x4b3060
0x4adf07 8988f0080000 mov    DWORD PTR [eax+0x8f0],ecx
0x4adf0d c78044010000d01b4b00 mov    DWORD PTR [eax+0x144],0x4b1bd0
0x4adf17 898848010000 mov    DWORD PTR [eax+0x148],ecx
0x4adf1d c780a401000090304b00 mov    DWORD PTR [eax+0x1a4],0x4b3090
0x4adf27 8988a8010000 mov    DWORD PTR [eax+0x1a8],ecx
0x4adf2d c780c4010000f01b4b00 mov    DWORD PTR [eax+0x1c4],0x4b1bf0
0x4adf37 8988c8010000 mov    DWORD PTR [eax+0x1c8],ecx
0x4adf3d c7801402000090214b00 mov    DWORD PTR [eax+0x214],0x4b2190
0x4adf47 898818020000 mov    DWORD PTR [eax+0x218],ecx
0x4adf4d c7800c02000010234b00 mov    DWORD PTR [eax+0x20c],0x4b2310
0x4adf57 898810020000 mov    DWORD PTR [eax+0x210],ecx
0x4adf5d c780fc030000c0234b00 mov    DWORD PTR [eax+0x3fc],0x4b23c0
0x4adf67 898800040000 mov    DWORD PTR [eax+0x400],ecx
0x4adf6d c7804c02000050334b00 mov    DWORD PTR [eax+0x24c],0x4b3350
0x4adf77 898850020000 mov    DWORD PTR [eax+0x250],ecx
0x4adf7d c7805c020000f0344b00 mov    DWORD PTR [eax+0x25c],0x4b34f0
0x4adf87 898860020000 mov    DWORD PTR [eax+0x260],ecx
0x4adf8d c7806c02000010354b00 mov    DWORD PTR [eax+0x26c],0x4b3510
0x4adf97 898870020000 mov    DWORD PTR [eax+0x270],ecx
0x4adf9d c7807402000070354b00 mov    DWORD PTR [eax+0x274],0x4b3570
0x4adfa7 898878020000 mov    DWORD PTR [eax+0x278],ecx
0x4adfad c7808402000000364b00 mov    DWORD PTR [eax+0x284],0x4b3600
0x4adfb7 898888020000 mov    DWORD PTR [eax+0x288],ecx
0x4adfbd c7808c02000010374b00 mov    DWORD PTR [eax+0x28c],0x4b3710
0x4adfc7 898890020000 mov    DWORD PTR [eax+0x290],ecx
0x4adfcd c780a4040000f0f14a00 mov    DWORD PTR [eax+0x4a4],0x4af1f0
0x4adfd7 8988a8040000 mov    DWORD PTR [eax+0x4a8],ecx
0x4adfdd c780f4020000103c4b00 mov    DWORD PTR [eax+0x2f4],0x4b3c10
0x4adfe7 8988f8020000 mov    DWORD PTR [eax+0x2f8],ecx
0x4adfed c780e4020000a03d4b00 mov    DWORD PTR [eax+0x2e4],0x4b3da0
0x4adff7 8988e8020000 mov    DWORD PTR [eax+0x2e8],ecx
0x4adffd c7808401000060374b00 mov    DWORD PTR [eax+0x184],0x4b3760
0x4ae007 898888010000 mov    DWORD PTR [eax+0x188],ecx
0x4ae00d c7801c030000e03e4b00 mov    DWORD PTR [eax+0x31c],0x4b3ee0
0x4ae017 898820030000 mov    DWORD PTR [eax+0x320],ecx
0x4ae01d c7806403000050404b00 mov    DWORD PTR [eax+0x364],0x4b4050
0x4ae027 898868030000 mov    DWORD PTR [eax+0x368],ecx
0x4ae02d c7806c030000e0404b00 mov    DWORD PTR [eax+0x36c],0x4b40e0
0x4ae037 898870030000 mov    DWORD PTR [eax+0x370],ecx
0x4ae03d c780b403000080434b00 mov    DWORD PTR [eax+0x3b4],0x4b4380
0x4ae047 8988b8030000 mov    DWORD PTR [eax+0x3b8],ecx
0x4ae04d c7809c03000000444b00 mov    DWORD PTR [eax+0x39c],0x4b4400
0x4ae057 8988a0030000 mov    DWORD PTR [eax+0x3a0],ecx
0x4ae05d c780cc030000c0444b00 mov    DWORD PTR [eax+0x3cc],0x4b44c0
0x4ae067 8988d0030000 mov    DWORD PTR [eax+0x3d0],ecx
0x4ae06d c78014040000e0444b00 mov    DWORD PTR [eax+0x414],0x4b44e0
0x4ae077 898818040000 mov    DWORD PTR [eax+0x418],ecx
0x4ae07d c7808c040000b0454b00 mov    DWORD PTR [eax+0x48c],0x4b45b0
0x4ae087 898890040000 mov    DWORD PTR [eax+0x490],ecx
0x4ae08d c780d4050000d0494b00 mov    DWORD PTR [eax+0x5d4],0x4b49d0
0x4ae097 8988d8050000 mov    DWORD PTR [eax+0x5d8],ecx
0x4ae09d c780bc040000c04c4b00 mov    DWORD PTR [eax+0x4bc],0x4b4cc0
0x4ae0a7 8988c0040000 mov    DWORD PTR [eax+0x4c0],ecx
0x4ae0ad c780ac040000b01a4b00 mov    DWORD PTR [eax+0x4ac],0x4b1ab0
0x4ae0b7 8988b0040000 mov    DWORD PTR [eax+0x4b0],ecx
0x4ae0bd c780b4040000b01b4b00 mov    DWORD PTR [eax+0x4b4],0x4b1bb0
0x4ae0c7 8988b8040000 mov    DWORD PTR [eax+0x4b8],ecx
0x4ae0cd c78024050000804d4b00 mov    DWORD PTR [eax+0x524],0x4b4d80
0x4ae0d7 898828050000 mov    DWORD PTR [eax+0x528],ecx
0x4ae0dd c7802c050000f0534b00 mov    DWORD PTR [eax+0x52c],0x4b53f0
0x4ae0e7 898830050000 mov    DWORD PTR [eax+0x530],ecx
0x4ae0ed c7806c070000105c4b00 mov    DWORD PTR [eax+0x76c],0x4b5c10
0x4ae0f7 898870070000 mov    DWORD PTR [eax+0x770],ecx
0x4ae0fd c7808c080000c0444b00 mov    DWORD PTR [eax+0x88c],0x4b44c0
0x4ae107 898890080000 mov    DWORD PTR [eax+0x890],ecx
0x4ae10d c7808c05000000594b00 mov    DWORD PTR [eax+0x58c],0x4b5900
0x4ae117 898890050000 mov    DWORD PTR [eax+0x590],ecx
0x4ae11d c780b4050000d05d4b00 mov    DWORD PTR [eax+0x5b4],0x4b5dd0
0x4ae127 8988b8050000 mov    DWORD PTR [eax+0x5b8],ecx
0x4ae12d c780bc050000505e4b00 mov    DWORD PTR [eax+0x5bc],0x4b5e50
0x4ae137 8988c0050000 mov    DWORD PTR [eax+0x5c0],ecx
0x4ae13d c78054060000105f4b00 mov    DWORD PTR [eax+0x654],0x4b5f10
0x4ae147 898858060000 mov    DWORD PTR [eax+0x658],ecx
0x4ae14d c7805c060000305f4b00 mov    DWORD PTR [eax+0x65c],0x4b5f30
0x4ae157 898860060000 mov    DWORD PTR [eax+0x660],ecx
0x4ae15d c78044060000405f4b00 mov    DWORD PTR [eax+0x644],0x4b5f40
0x4ae167 898848060000 mov    DWORD PTR [eax+0x648],ecx
0x4ae16d c78064060000605f4b00 mov    DWORD PTR [eax+0x664],0x4b5f60
0x4ae177 898868060000 mov    DWORD PTR [eax+0x668],ecx
0x4ae17d c7804c060000805f4b00 mov    DWORD PTR [eax+0x64c],0x4b5f80
0x4ae187 898850060000 mov    DWORD PTR [eax+0x650],ecx
0x4ae18d c7803c060000a05f4b00 mov    DWORD PTR [eax+0x63c],0x4b5fa0
0x4ae197 898840060000 mov    DWORD PTR [eax+0x640],ecx
0x4ae19d c7806c060000d05f4b00 mov    DWORD PTR [eax+0x66c],0x4b5fd0
0x4ae1a7 898870060000 mov    DWORD PTR [eax+0x670],ecx
0x4ae1ad c78074060000f05f4b00 mov    DWORD PTR [eax+0x674],0x4b5ff0
0x4ae1b7 898878060000 mov    DWORD PTR [eax+0x678],ecx
0x4ae1bd c7807c06000010604b00 mov    DWORD PTR [eax+0x67c],0x4b6010
0x4ae1c7 898880060000 mov    DWORD PTR [eax+0x680],ecx
0x4ae1cd c7808406000030604b00 mov    DWORD PTR [eax+0x684],0x4b6030
0x4ae1d7 898888060000 mov    DWORD PTR [eax+0x688],ecx
0x4ae1dd c780c406000040604b00 mov    DWORD PTR [eax+0x6c4],0x4b6040
0x4ae1e7 8988c8060000 mov    DWORD PTR [eax+0x6c8],ecx
0x4ae1ed c780dc06000050604b00 mov    DWORD PTR [eax+0x6dc],0x4b6050
0x4ae1f7 8988e0060000 mov    DWORD PTR [eax+0x6e0],ecx
0x4ae1fd c7805c07000090614b00 mov    DWORD PTR [eax+0x75c],0x4b6190
0x4ae207 898860070000 mov    DWORD PTR [eax+0x760],ecx
0x4ae20d c7806407000000624b00 mov    DWORD PTR [eax+0x764],0x4b6200
0x4ae217 898868070000 mov    DWORD PTR [eax+0x768],ecx
0x4ae21d c7807407000090624b00 mov    DWORD PTR [eax+0x774],0x4b6290
0x4ae227 898878070000 mov    DWORD PTR [eax+0x778],ecx
0x4ae22d c780ac080000e0634b00 mov    DWORD PTR [eax+0x8ac],0x4b63e0
0x4ae237 8988b0080000 mov    DWORD PTR [eax+0x8b0],ecx
0x4ae23d c780b408000010664b00 mov    DWORD PTR [eax+0x8b4],0x4b6610
0x4ae247 8988b8080000 mov    DWORD PTR [eax+0x8b8],ecx
0x4ae24d c780bc08000080654b00 mov    DWORD PTR [eax+0x8bc],0x4b6580
0x4ae257 8988c0080000 mov    DWORD PTR [eax+0x8c0],ecx
0x4ae25d c780c4080000b0674b00 mov    DWORD PTR [eax+0x8c4],0x4b67b0
0x4ae267 8988c8080000 mov    DWORD PTR [eax+0x8c8],ecx
0x4ae26d c780ac03000040684b00 mov    DWORD PTR [eax+0x3ac],0x4b6840
0x4ae277 8988b0030000 mov    DWORD PTR [eax+0x3b0],ecx
0x4ae27d c780cc08000070524900 mov    DWORD PTR [eax+0x8cc],0x495270
0x4ae287 8988d0080000 mov    DWORD PTR [eax+0x8d0],ecx
0x4ae28d c78054090000001a4b00 mov    DWORD PTR [eax+0x954],0x4b1a00
0x4ae297 898858090000 mov    DWORD PTR [eax+0x958],ecx
0x4ae29d c780b4090000306a4b00 mov    DWORD PTR [eax+0x9b4],0x4b6a30
0x4ae2a7 8988b8090000 mov    DWORD PTR [eax+0x9b8],ecx
0x4ae2ad c7802c0a0000b06a4b00 mov    DWORD PTR [eax+0xa2c],0x4b6ab0
0x4ae2b7 8988300a0000 mov    DWORD PTR [eax+0xa30],ecx
0x4ae2bd c780e4040000906b4b00 mov    DWORD PTR [eax+0x4e4],0x4b6b90
0x4ae2c7 8988e8040000 mov    DWORD PTR [eax+0x4e8],ecx
0x4ae2cd c7804c0a0000006d4b00 mov    DWORD PTR [eax+0xa4c],0x4b6d00
0x4ae2d7 8988500a0000 mov    DWORD PTR [eax+0xa50],ecx
0x4ae2dd c780f404000000724b00 mov    DWORD PTR [eax+0x4f4],0x4b7200
0x4ae2e7 8988f8040000 mov    DWORD PTR [eax+0x4f8],ecx
0x4ae2ed c7808c0a0000e0724b00 mov    DWORD PTR [eax+0xa8c],0x4b72e0
0x4ae2f7 8988900a0000 mov    DWORD PTR [eax+0xa90],ecx
0x4ae2fd c780940a000040754b00 mov    DWORD PTR [eax+0xa94],0x4b7540
0x4ae307 8988980a0000 mov    DWORD PTR [eax+0xa98],ecx
0x4ae30d c780a40a000020764b00 mov    DWORD PTR [eax+0xaa4],0x4b7620
0x4ae317 8988a80a0000 mov    DWORD PTR [eax+0xaa8],ecx
0x4ae31d c780ac0a000090774b00 mov    DWORD PTR [eax+0xaac],0x4b7790
0x4ae327 8988b00a0000 mov    DWORD PTR [eax+0xab0],ecx
0x4ae32d c780b40a0000a0784b00 mov    DWORD PTR [eax+0xab4],0x4b78a0
0x4ae337 8988b80a0000 mov    DWORD PTR [eax+0xab8],ecx
0x4ae33d c7809c0a000050794b00 mov    DWORD PTR [eax+0xa9c],0x4b7950
0x4ae347 8988a00a0000 mov    DWORD PTR [eax+0xaa0],ecx
0x4ae34d c780c40a0000a07b4b00 mov    DWORD PTR [eax+0xac4],0x4b7ba0
0x4ae357 8988c80a0000 mov    DWORD PTR [eax+0xac8],ecx
0x4ae35d c7805c0a0000706f4b00 mov    DWORD PTR [eax+0xa5c],0x4b6f70
0x4ae367 8988600a0000 mov    DWORD PTR [eax+0xa60],ecx
0x4ae36d 5e pop    esi
0x4ae36e c7807c0a0000f06f4b00 mov    DWORD PTR [eax+0xa7c],0x4b6ff0
0x4ae378 8988800a0000 mov    DWORD PTR [eax+0xa80],ecx
0x4ae37e 5b pop    ebx
0x4ae37f c3 ret

; reused_ordinary_scenario_constructor 0x4c46f0..0x4c4745 raw=0xc3af0 sha256=4aa757af1b9bd22025f771de26027954c331490419556cbd697da66831bdf905
0x4c46f0 8bc6 mov    eax,esi
0x4c46f2 e85996feff call   0x4add50
0x4c46f7 68a85e0000 push   0x5ea8
0x4c46fc 8d86ac5e0000 lea    eax,[esi+0x5eac]
0x4c4702 6a00 push   0x0
0x4c4704 50 push   eax
0x4c4705 c706b473c000 mov    DWORD PTR [esi],0xc073b4
0x4c470b c70574a6d60046454353 mov    DWORD PTR ds:0xd6a674,0x53434546
0x4c4715 e846a13d00 call   0x89e860
0x4c471a b87523bf00 mov    eax,0xbf2375
0x4c471f 8986505f0000 mov    DWORD PTR [esi+0x5f50],eax
0x4c4725 8986205f0000 mov    DWORD PTR [esi+0x5f20],eax
0x4c472b 83c40c add    esp,0xc
0x4c472e c7864c5f000030594c00 mov    DWORD PTR [esi+0x5f4c],0x4c5930
0x4c4738 c7861c5f0000406c4300 mov    DWORD PTR [esi+0x5f1c],0x436c40
0x4c4742 8bc6 mov    eax,esi
0x4c4744 c3 ret

; reused_ordinary_mission_constructor 0x4bc6a0..0x4bc6db raw=0xbbaa0 sha256=ec1918b2c927f3630c004348f5a31849a315508fa4163d83059a31faa1b30ef5
0x4bc6a0 56 push   esi
0x4bc6a1 8bf0 mov    esi,eax
0x4bc6a3 e8a816ffff call   0x4add50
0x4bc6a8 f30f1005c056c500 movss  xmm0,DWORD PTR ds:0xc556c0
0x4bc6b0 c7065c70c000 mov    DWORD PTR [esi],0xc0705c
0x4bc6b6 c78654bd000000000000 mov    DWORD PTR [esi+0xbd54],0x0
0x4bc6c0 f30f118658bd0000 movss  DWORD PTR [esi+0xbd58],xmm0
0x4bc6c8 c70574a6d6004653494d mov    DWORD PTR ds:0xd6a674,0x4d495346
0x4bc6d2 e809000000 call   0x4bc6e0
0x4bc6d7 8bc6 mov    eax,esi
0x4bc6d9 5e pop    esi
0x4bc6da c3 ret

; reused_ordinary_mission_secondary_init 0x4bc6e0..0x4bc74c raw=0xbbae0 sha256=f01978556271c26c11f2c6f51b8b1537c3e7da8fcd497046a935ebaa03ea47db
0x4bc6e0 68a85e0000 push   0x5ea8
0x4bc6e5 8d86ac5e0000 lea    eax,[esi+0x5eac]
0x4bc6eb 6a00 push   0x0
0x4bc6ed 50 push   eax
0x4bc6ee e86d213e00 call   0x89e860
0x4bc6f3 b87523bf00 mov    eax,0xbf2375
0x4bc6f8 83c40c add    esp,0xc
0x4bc6fb c7864c5f000030594c00 mov    DWORD PTR [esi+0x5f4c],0x4c5930
0x4bc705 8986505f0000 mov    DWORD PTR [esi+0x5f50],eax
0x4bc70b c7867460000030c94b00 mov    DWORD PTR [esi+0x6074],0x4bc930
0x4bc715 898678600000 mov    DWORD PTR [esi+0x6078],eax
0x4bc71b c7867c600000a0584c00 mov    DWORD PTR [esi+0x607c],0x4c58a0
0x4bc725 898680600000 mov    DWORD PTR [esi+0x6080],eax
0x4bc72b c7863460000090ca4b00 mov    DWORD PTR [esi+0x6034],0x4bca90
0x4bc735 898638600000 mov    DWORD PTR [esi+0x6038],eax
0x4bc73b c7868460000090554c00 mov    DWORD PTR [esi+0x6084],0x4c5590
0x4bc745 898688600000 mov    DWORD PTR [esi+0x6088],eax
0x4bc74b c3 ret

; reused_unlock_packet_00eb 0x4b6190..0x4b61fd raw=0xb5590 sha256=efc68721b754fac970bec67ed378f48365fc8431ecf20889f3d7c5f6f0b08cf3
0x4b6190 55 push   ebp
0x4b6191 8bec mov    ebp,esp
0x4b6193 6aff push   0xffffffff
0x4b6195 68aeb29300 push   0x93b2ae
0x4b619a 64a100000000 mov    eax,fs:0x0
0x4b61a0 50 push   eax
0x4b61a1 a1201fd600 mov    eax,ds:0xd61f20
0x4b61a6 33c5 xor    eax,ebp
0x4b61a8 50 push   eax
0x4b61a9 8d45f4 lea    eax,[ebp-0xc]
0x4b61ac 64a300000000 mov    fs:0x0,eax
0x4b61b2 b801000000 mov    eax,0x1
0x4b61b7 8405b873fb00 test   BYTE PTR ds:0xfb73b8,al
0x4b61bd 7526 jne    0x4b61e5
0x4b61bf 0905b873fb00 or     DWORD PTR ds:0xfb73b8,eax
0x4b61c5 c745fc00000000 mov    DWORD PTR [ebp-0x4],0x0
0x4b61cc e89f9f0a00 call   0x560170
0x4b61d1 6810d1bc00 push   0xbcd110
0x4b61d6 e83fc13d00 call   0x89231a
0x4b61db 83c404 add    esp,0x4
0x4b61de c745fcffffffff mov    DWORD PTR [ebp-0x4],0xffffffff
0x4b61e5 e866c00a00 call   0x562250
0x4b61ea 33c0 xor    eax,eax
0x4b61ec 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4b61ef 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4b61f6 59 pop    ecx
0x4b61f7 8be5 mov    esp,ebp
0x4b61f9 5d pop    ebp
0x4b61fa c20c00 ret    0xc

; primary_index_dispatch 0x4fda30..0x4fdab3 raw=0xfce30 sha256=f972c684f3955a1d49c1e56eef445bb5f60fd3e4e16da15c654a51ef21054f88
0x4fda30 55 push   ebp
0x4fda31 8bec mov    ebp,esp
0x4fda33 51 push   ecx
0x4fda34 56 push   esi
0x4fda35 8bf1 mov    esi,ecx
0x4fda37 8b4d10 mov    ecx,DWORD PTR [ebp+0x10]
0x4fda3a 57 push   edi
0x4fda3b 0fbff9 movsx  edi,cx
0x4fda3e 8b44fe04 mov    eax,DWORD PTR [esi+edi*8+0x4]
0x4fda42 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4fda45 85c0 test   eax,eax
0x4fda47 751a jne    0x4fda63
0x4fda49 8b06 mov    eax,DWORD PTR [esi]
0x4fda4b 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x4fda4e 8b400c mov    eax,DWORD PTR [eax+0xc]
0x4fda51 51 push   ecx
0x4fda52 8b4d0c mov    ecx,DWORD PTR [ebp+0xc]
0x4fda55 51 push   ecx
0x4fda56 52 push   edx
0x4fda57 8bce mov    ecx,esi
0x4fda59 ffd0 call   eax
0x4fda5b 5f pop    edi
0x4fda5c 5e pop    esi
0x4fda5d 8be5 mov    esp,ebp
0x4fda5f 5d pop    ebp
0x4fda60 c20c00 ret    0xc
0x4fda63 8b4cfe08 mov    ecx,DWORD PTR [esi+edi*8+0x8]
0x4fda67 53 push   ebx
0x4fda68 6a06 push   0x6
0x4fda6a 8d5cfe08 lea    ebx,[esi+edi*8+0x8]
0x4fda6e 686c6cbf00 push   0xbf6c6c
0x4fda73 51 push   ecx
0x4fda74 e8454e3900 call   0x8928be
0x4fda79 8b5510 mov    edx,DWORD PTR [ebp+0x10]
0x4fda7c 8b450c mov    eax,DWORD PTR [ebp+0xc]
0x4fda7f 8b4d08 mov    ecx,DWORD PTR [ebp+0x8]
0x4fda82 83c40c add    esp,0xc
0x4fda85 52 push   edx
0x4fda86 50 push   eax
0x4fda87 51 push   ecx
0x4fda88 8bce mov    ecx,esi
0x4fda8a ff55fc call   DWORD PTR [ebp-0x4]
0x4fda8d 8bf0 mov    esi,eax
0x4fda8f 81fe05400080 cmp    esi,0x80004005
0x4fda95 7511 jne    0x4fdaa8
0x4fda97 8b13 mov    edx,DWORD PTR [ebx]
0x4fda99 52 push   edx
0x4fda9a 57 push   edi
0x4fda9b 68746cbf00 push   0xbf6c74
0x4fdaa0 e8bb001f00 call   0x6edb60
0x4fdaa5 83c40c add    esp,0xc
0x4fdaa8 5b pop    ebx
0x4fdaa9 5f pop    edi
0x4fdaaa 8bc6 mov    eax,esi
0x4fdaac 5e pop    esi
0x4fdaad 8be5 mov    esp,ebp
0x4fdaaf 5d pop    ebp
0x4fdab0 c20c00 ret    0xc

; client_tick_vtable 0xc05aa4..0xc05ad8 raw=0x8040a4 sha256=09b9d4385d9d4f1c5474dbd23f594aacd39d110df019202bdd29f945c41c50a7
e0ad490070ee4800f0ff48005005490010f948002008490090b7730040ed6d0050be480070c14800e0c6480030e64800e00f4900

; client_packet_vtable 0xc05aec..0xc05af0 raw=0x8040ec sha256=79915563bca914821b6fa94008f4f00f0bbc89315f77b58b1132fbfd4ac344fc
e0304900

; client_frontend_vtable 0xc05b04..0xc05b14 raw=0x804104 sha256=82d0437edfd3e7a0b37d0fa358a963e7133cd1dc91a0a299bc80567394af0769
f0ad4900d0aa480010284200f0274200

; scene_manager_vtable 0xc06eb4..0xc06ec4 raw=0x8054b4 sha256=b8618032de1668f61981711788613b6f7366e8a2384f3681fe9d06e49bcc90ac
40594c0030da4f0010284200f0274200

; scenario_field_vtable 0xc073b4..0xc073d0 raw=0x8059b4 sha256=fac029b913193c02c705fdb9e30b83a42aa4d39410499cac13b1b8e9e0497ab2
40594c0070464c0010284200f027420050474c00f0c28d0010db4a00

; mission_field_vtable 0xc0705c..0xc07078 raw=0x80565c sha256=6a3a6e3d9298b80c9de1c2ee2751f0b5961bb3d7e6a4b2efbe0149eeb8f110e1
40594c0070464c0010284200f027420050c74b0010bf4b0060304200

; network_manager_vtable 0xc51748..0xc51774 raw=0x84fd48 sha256=3affa031847b73fda12c01aaeff6b9c3e8e703489c54658d63e1a9ef836f86e8
70668000f06c800050688000b0688000a0698000006a8000d06a8000606f8000806f8000c06f800090708000
