
; B01 lb bootstrap: formal wrapper and 14 fixed member registrars
; VA 0x4a0950..0x4a0a21 raw 0x9fd50 len 209 SHA256 fb8718c27cd1337a724721509e47ef17af7a514ff0940599c39f778ce3210a72
004A0950 55                               push   ebp
004A0951 8bec                             mov    ebp,esp
004A0953 6aff                             push   0xffffffff
004A0955 68be4e9400                       push   0x944ebe
004A095A 64a100000000                     mov    eax,fs:0x0
004A0960 50                               push   eax
004A0961 83ec08                           sub    esp,0x8
004A0964 a1201fd600                       mov    eax,ds:0xd61f20
004A0969 33c5                             xor    eax,ebp
004A096B 50                               push   eax
004A096C 8d45f4                           lea    eax,[ebp-0xc]
004A096F 64a300000000                     mov    fs:0x0,eax
004A0975 b801000000                       mov    eax,0x1
004A097A 8405d4f3fd00                     test   BYTE PTR ds:0xfdf3d4,al
004A0980 7526                             jne    0x4a09a8
004A0982 0905d4f3fd00                     or     DWORD PTR ds:0xfdf3d4,eax
004A0988 c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
004A098F e8ec392500                       call   0x6f4380
004A0994 68d0e6bc00                       push   0xbce6d0
004A0999 e87c193f00                       call   0x89231a
004A099E 83c404                           add    esp,0x4
004A09A1 c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
004A09A8 8d45f0                           lea    eax,[ebp-0x10]
004A09AB 68c8f3fd00                       push   0xfdf3c8
004A09B0 50                               push   eax
004A09B1 e81a0b0000                       call   0x4a14d0
004A09B6 83c408                           add    esp,0x8
004A09B9 50                               push   eax
004A09BA e8f10b0000                       call   0x4a15b0
004A09BF 50                               push   eax
004A09C0 e88b0c0000                       call   0x4a1650
004A09C5 50                               push   eax
004A09C6 e8250d0000                       call   0x4a16f0
004A09CB 50                               push   eax
004A09CC e8bf0d0000                       call   0x4a1790
004A09D1 50                               push   eax
004A09D2 e8590e0000                       call   0x4a1830
004A09D7 50                               push   eax
004A09D8 e8f30e0000                       call   0x4a18d0
004A09DD 50                               push   eax
004A09DE e88d0f0000                       call   0x4a1970
004A09E3 50                               push   eax
004A09E4 e827100000                       call   0x4a1a10
004A09E9 50                               push   eax
004A09EA e8c1100000                       call   0x4a1ab0
004A09EF 50                               push   eax
004A09F0 e85b110000                       call   0x4a1b50
004A09F5 50                               push   eax
004A09F6 e8f5110000                       call   0x4a1bf0
004A09FB 50                               push   eax
004A09FC e88f120000                       call   0x4a1c90
004A0A01 50                               push   eax
004A0A02 e829130000                       call   0x4a1d30
004A0A07 50                               push   eax
004A0A08 e8c3130000                       call   0x4a1dd0
004A0A0D b82472fe00                       mov    eax,0xfe7224
004A0A12 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004A0A15 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004A0A1C 59                               pop    ecx
004A0A1D 8be5                             mov    esp,ebp
004A0A1F 5d                               pop    ebp
004A0A20 c3                               ret

; B02 Tutorial bootstrap: wrapper stored on owner and 31 member registrars
; VA 0x4a88e0..0x4a89bf raw 0xa7ce0 len 223 SHA256 c02c1bb33b21151db1ec5bbeffe4086005d24a77413a8d395d70428a8a528ff0
004A88E0 55                               push   ebp
004A88E1 8bec                             mov    ebp,esp
004A88E3 83ec08                           sub    esp,0x8
004A88E6 8d4dfc                           lea    ecx,[ebp-0x4]
004A88E9 56                               push   esi
004A88EA 51                               push   ecx
004A88EB 8930                             mov    DWORD PTR [eax],esi
004A88ED e8ae1c0000                       call   0x4aa5a0
004A88F2 83c408                           add    esp,0x8
004A88F5 50                               push   eax
004A88F6 e8851d0000                       call   0x4aa680
004A88FB 50                               push   eax
004A88FC e81f1e0000                       call   0x4aa720
004A8901 50                               push   eax
004A8902 e8b91e0000                       call   0x4aa7c0
004A8907 50                               push   eax
004A8908 e8531f0000                       call   0x4aa860
004A890D 50                               push   eax
004A890E e8ed1f0000                       call   0x4aa900
004A8913 50                               push   eax
004A8914 e887200000                       call   0x4aa9a0
004A8919 50                               push   eax
004A891A e821210000                       call   0x4aaa40
004A891F 50                               push   eax
004A8920 e8bb210000                       call   0x4aaae0
004A8925 50                               push   eax
004A8926 e855220000                       call   0x4aab80
004A892B 50                               push   eax
004A892C e8ef220000                       call   0x4aac20
004A8931 50                               push   eax
004A8932 e889230000                       call   0x4aacc0
004A8937 50                               push   eax
004A8938 e823240000                       call   0x4aad60
004A893D 50                               push   eax
004A893E e8bd240000                       call   0x4aae00
004A8943 50                               push   eax
004A8944 e857250000                       call   0x4aaea0
004A8949 50                               push   eax
004A894A e8f1250000                       call   0x4aaf40
004A894F 50                               push   eax
004A8950 e88b260000                       call   0x4aafe0
004A8955 50                               push   eax
004A8956 e825270000                       call   0x4ab080
004A895B 50                               push   eax
004A895C e8bf270000                       call   0x4ab120
004A8961 50                               push   eax
004A8962 e859280000                       call   0x4ab1c0
004A8967 50                               push   eax
004A8968 e8f3280000                       call   0x4ab260
004A896D 50                               push   eax
004A896E e88d290000                       call   0x4ab300
004A8973 50                               push   eax
004A8974 e8272a0000                       call   0x4ab3a0
004A8979 50                               push   eax
004A897A e8c12a0000                       call   0x4ab440
004A897F 50                               push   eax
004A8980 e85b2b0000                       call   0x4ab4e0
004A8985 50                               push   eax
004A8986 e8f52b0000                       call   0x4ab580
004A898B 50                               push   eax
004A898C e88f2c0000                       call   0x4ab620
004A8991 50                               push   eax
004A8992 e8292d0000                       call   0x4ab6c0
004A8997 50                               push   eax
004A8998 e8c32d0000                       call   0x4ab760
004A899D 50                               push   eax
004A899E e85d2e0000                       call   0x4ab800
004A89A3 50                               push   eax
004A89A4 e8f72e0000                       call   0x4ab8a0
004A89A9 50                               push   eax
004A89AA e8912f0000                       call   0x4ab940
004A89AF 686468c000                       push   0xc06864
004A89B4 8bce                             mov    ecx,esi
004A89B6 e895c02400                       call   0x6f4a50
004A89BB 8be5                             mov    esp,ebp
004A89BD 5d                               pop    ebp
004A89BE c3                               ret

; B03 RegisterSkipMessage binding
; VA 0x4ab080..0x4ab119 raw 0xaa480 len 153 SHA256 d05fc4aabaf0ca1382c5f345ebec335ed534eb401250aa0e1d299d34978436cd
004AB080 55                               push   ebp
004AB081 8bec                             mov    ebp,esp
004AB083 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB086 53                               push   ebx
004AB087 8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AB08D 56                               push   esi
004AB08E 8b33                             mov    esi,DWORD PTR [ebx]
004AB090 57                               push   edi
004AB091 8b38                             mov    edi,DWORD PTR [eax]
004AB093 b8eed8ffff                       mov    eax,0xffffd8ee
004AB098 c7054818fe00709b4a00             mov    DWORD PTR ds:0xfe1848,0x4a9b70
004AB0A2 e8d9a52400                       call   0x6f5680
004AB0A7 8b03                             mov    eax,DWORD PTR [ebx]
004AB0A9 8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AB0AC 83e810                           sub    eax,0x10
004AB0AF 3dc8bfc000                       cmp    eax,0xc0bfc8
004AB0B4 7406                             je     0x4ab0bc
004AB0B6 83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AB0BA 7414                             je     0x4ab0d0
004AB0BC 57                               push   edi
004AB0BD 68c426c400                       push   0xc426c4
004AB0C2 e8f67f3e00                       call   0x8930bd
004AB0C7 8b1b                             mov    ebx,DWORD PTR [ebx]
004AB0C9 83c408                           add    esp,0x8
004AB0CC 834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AB0D0 8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AB0D6 8b37                             mov    esi,DWORD PTR [edi]
004AB0D8 686cacd600                       push   0xd6ac6c
004AB0DD e82ea42400                       call   0x6f5510
004AB0E2 8b37                             mov    esi,DWORD PTR [edi]
004AB0E4 83c404                           add    esp,0x4
004AB0E7 6a00                             push   0x0
004AB0E9 68c0c44a00                       push   0x4ac4c0
004AB0EE e8bda42400                       call   0x6f55b0
004AB0F3 8b0f                             mov    ecx,DWORD PTR [edi]
004AB0F5 51                               push   ecx
004AB0F6 b8fdffffff                       mov    eax,0xfffffffd
004AB0FB e8f0a62400                       call   0x6f57f0
004AB100 8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AB106 8b02                             mov    eax,DWORD PTR [edx]
004AB108 83c40c                           add    esp,0xc
004AB10B 834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AB10F 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB112 5f                               pop    edi
004AB113 5e                               pop    esi
004AB114 5b                               pop    ebx
004AB115 5d                               pop    ebp
004AB116 c20400                           ret    0x4

; B04 RegisterScalingObject binding
; VA 0x4ab120..0x4ab1b9 raw 0xaa520 len 153 SHA256 671f028207ceb0fc0c4c90ca847dd2a12f8e4b0d1ebd1dfd59ae5f38643bebdd
004AB120 55                               push   ebp
004AB121 8bec                             mov    ebp,esp
004AB123 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB126 53                               push   ebx
004AB127 8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AB12D 56                               push   esi
004AB12E 8b33                             mov    esi,DWORD PTR [ebx]
004AB130 57                               push   edi
004AB131 8b38                             mov    edi,DWORD PTR [eax]
004AB133 b8eed8ffff                       mov    eax,0xffffd8ee
004AB138 c7054c18fe00809c4a00             mov    DWORD PTR ds:0xfe184c,0x4a9c80
004AB142 e839a52400                       call   0x6f5680
004AB147 8b03                             mov    eax,DWORD PTR [ebx]
004AB149 8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AB14C 83e810                           sub    eax,0x10
004AB14F 3dc8bfc000                       cmp    eax,0xc0bfc8
004AB154 7406                             je     0x4ab15c
004AB156 83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AB15A 7414                             je     0x4ab170
004AB15C 57                               push   edi
004AB15D 68c426c400                       push   0xc426c4
004AB162 e8567f3e00                       call   0x8930bd
004AB167 8b1b                             mov    ebx,DWORD PTR [ebx]
004AB169 83c408                           add    esp,0x8
004AB16C 834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AB170 8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AB176 8b37                             mov    esi,DWORD PTR [edi]
004AB178 6880acd600                       push   0xd6ac80
004AB17D e88ea32400                       call   0x6f5510
004AB182 8b37                             mov    esi,DWORD PTR [edi]
004AB184 83c404                           add    esp,0x4
004AB187 6a00                             push   0x0
004AB189 6820c54a00                       push   0x4ac520
004AB18E e81da42400                       call   0x6f55b0
004AB193 8b0f                             mov    ecx,DWORD PTR [edi]
004AB195 51                               push   ecx
004AB196 b8fdffffff                       mov    eax,0xfffffffd
004AB19B e850a62400                       call   0x6f57f0
004AB1A0 8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AB1A6 8b02                             mov    eax,DWORD PTR [edx]
004AB1A8 83c40c                           add    esp,0xc
004AB1AB 834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AB1AF 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB1B2 5f                               pop    edi
004AB1B3 5e                               pop    esi
004AB1B4 5b                               pop    ebx
004AB1B5 5d                               pop    ebp
004AB1B6 c20400                           ret    0x4

; B05 DestroyFlyingObjects binding
; VA 0x4ab1c0..0x4ab259 raw 0xaa5c0 len 153 SHA256 3c499e3b403a17881914451ead600d20c1ec02adf71c4bc11d2b84c0e2283cbe
004AB1C0 55                               push   ebp
004AB1C1 8bec                             mov    ebp,esp
004AB1C3 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB1C6 53                               push   ebx
004AB1C7 8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AB1CD 56                               push   esi
004AB1CE 8b33                             mov    esi,DWORD PTR [ebx]
004AB1D0 57                               push   edi
004AB1D1 8b38                             mov    edi,DWORD PTR [eax]
004AB1D3 b8eed8ffff                       mov    eax,0xffffd8ee
004AB1D8 c7055018fe00b09d4a00             mov    DWORD PTR ds:0xfe1850,0x4a9db0
004AB1E2 e899a42400                       call   0x6f5680
004AB1E7 8b03                             mov    eax,DWORD PTR [ebx]
004AB1E9 8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AB1EC 83e810                           sub    eax,0x10
004AB1EF 3dc8bfc000                       cmp    eax,0xc0bfc8
004AB1F4 7406                             je     0x4ab1fc
004AB1F6 83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AB1FA 7414                             je     0x4ab210
004AB1FC 57                               push   edi
004AB1FD 68c426c400                       push   0xc426c4
004AB202 e8b67e3e00                       call   0x8930bd
004AB207 8b1b                             mov    ebx,DWORD PTR [ebx]
004AB209 83c408                           add    esp,0x8
004AB20C 834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AB210 8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AB216 8b37                             mov    esi,DWORD PTR [edi]
004AB218 6898acd600                       push   0xd6ac98
004AB21D e8eea22400                       call   0x6f5510
004AB222 8b37                             mov    esi,DWORD PTR [edi]
004AB224 83c404                           add    esp,0x4
004AB227 6a00                             push   0x0
004AB229 6880c54a00                       push   0x4ac580
004AB22E e87da32400                       call   0x6f55b0
004AB233 8b0f                             mov    ecx,DWORD PTR [edi]
004AB235 51                               push   ecx
004AB236 b8fdffffff                       mov    eax,0xfffffffd
004AB23B e8b0a52400                       call   0x6f57f0
004AB240 8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AB246 8b02                             mov    eax,DWORD PTR [edx]
004AB248 83c40c                           add    esp,0xc
004AB24B 834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AB24F 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AB252 5f                               pop    edi
004AB253 5e                               pop    esi
004AB254 5b                               pop    ebx
004AB255 5d                               pop    ebp
004AB256 c20400                           ret    0x4

; B06 PostUIMessage_EmployChar binding
; VA 0x4aae00..0x4aae99 raw 0xaa200 len 153 SHA256 7d3dbfa242f7c099d5d1949b828fa4d23e499fbe77a9701cc2d515a499637e2b
004AAE00 55                               push   ebp
004AAE01 8bec                             mov    ebp,esp
004AAE03 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAE06 53                               push   ebx
004AAE07 8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AAE0D 56                               push   esi
004AAE0E 8b33                             mov    esi,DWORD PTR [ebx]
004AAE10 57                               push   edi
004AAE11 8b38                             mov    edi,DWORD PTR [eax]
004AAE13 b8eed8ffff                       mov    eax,0xffffd8ee
004AAE18 c7053818fe00d0984a00             mov    DWORD PTR ds:0xfe1838,0x4a98d0
004AAE22 e859a82400                       call   0x6f5680
004AAE27 8b03                             mov    eax,DWORD PTR [ebx]
004AAE29 8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AAE2C 83e810                           sub    eax,0x10
004AAE2F 3dc8bfc000                       cmp    eax,0xc0bfc8
004AAE34 7406                             je     0x4aae3c
004AAE36 83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AAE3A 7414                             je     0x4aae50
004AAE3C 57                               push   edi
004AAE3D 68c426c400                       push   0xc426c4
004AAE42 e876823e00                       call   0x8930bd
004AAE47 8b1b                             mov    ebx,DWORD PTR [ebx]
004AAE49 83c408                           add    esp,0x8
004AAE4C 834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AAE50 8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AAE56 8b37                             mov    esi,DWORD PTR [edi]
004AAE58 6824acd600                       push   0xd6ac24
004AAE5D e8aea62400                       call   0x6f5510
004AAE62 8b37                             mov    esi,DWORD PTR [edi]
004AAE64 83c404                           add    esp,0x4
004AAE67 6a00                             push   0x0
004AAE69 6840c34a00                       push   0x4ac340
004AAE6E e83da72400                       call   0x6f55b0
004AAE73 8b0f                             mov    ecx,DWORD PTR [edi]
004AAE75 51                               push   ecx
004AAE76 b8fdffffff                       mov    eax,0xfffffffd
004AAE7B e870a92400                       call   0x6f57f0
004AAE80 8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AAE86 8b02                             mov    eax,DWORD PTR [edx]
004AAE88 83c40c                           add    esp,0xc
004AAE8B 834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AAE8F 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAE92 5f                               pop    edi
004AAE93 5e                               pop    esi
004AAE94 5b                               pop    ebx
004AAE95 5d                               pop    ebp
004AAE96 c20400                           ret    0x4

; B07 PostUIMessage_TutoMsg binding
; VA 0x4aaea0..0x4aaf39 raw 0xaa2a0 len 153 SHA256 f6d9865126fa664a15b7cc898154250da0dd118e1405dfeb44d5f97c304e04e0
004AAEA0 55                               push   ebp
004AAEA1 8bec                             mov    ebp,esp
004AAEA3 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAEA6 53                               push   ebx
004AAEA7 8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
004AAEAD 56                               push   esi
004AAEAE 8b33                             mov    esi,DWORD PTR [ebx]
004AAEB0 57                               push   edi
004AAEB1 8b38                             mov    edi,DWORD PTR [eax]
004AAEB3 b8eed8ffff                       mov    eax,0xffffd8ee
004AAEB8 c7053c18fe0050994a00             mov    DWORD PTR ds:0xfe183c,0x4a9950
004AAEC2 e8b9a72400                       call   0x6f5680
004AAEC7 8b03                             mov    eax,DWORD PTR [ebx]
004AAEC9 8b4008                           mov    eax,DWORD PTR [eax+0x8]
004AAECC 83e810                           sub    eax,0x10
004AAECF 3dc8bfc000                       cmp    eax,0xc0bfc8
004AAED4 7406                             je     0x4aaedc
004AAED6 83780805                         cmp    DWORD PTR [eax+0x8],0x5
004AAEDA 7414                             je     0x4aaef0
004AAEDC 57                               push   edi
004AAEDD 68c426c400                       push   0xc426c4
004AAEE2 e8d6813e00                       call   0x8930bd
004AAEE7 8b1b                             mov    ebx,DWORD PTR [ebx]
004AAEE9 83c408                           add    esp,0x8
004AAEEC 834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
004AAEF0 8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
004AAEF6 8b37                             mov    esi,DWORD PTR [edi]
004AAEF8 6840acd600                       push   0xd6ac40
004AAEFD e80ea62400                       call   0x6f5510
004AAF02 8b37                             mov    esi,DWORD PTR [edi]
004AAF04 83c404                           add    esp,0x4
004AAF07 6a00                             push   0x0
004AAF09 68a0c34a00                       push   0x4ac3a0
004AAF0E e89da62400                       call   0x6f55b0
004AAF13 8b0f                             mov    ecx,DWORD PTR [edi]
004AAF15 51                               push   ecx
004AAF16 b8fdffffff                       mov    eax,0xfffffffd
004AAF1B e8d0a82400                       call   0x6f57f0
004AAF20 8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
004AAF26 8b02                             mov    eax,DWORD PTR [edx]
004AAF28 83c40c                           add    esp,0xc
004AAF2B 834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
004AAF2F 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AAF32 5f                               pop    edi
004AAF33 5e                               pop    esi
004AAF34 5b                               pop    ebx
004AAF35 5d                               pop    ebp
004AAF36 c20400                           ret    0x4

; A01 Skip Lua closure calls fixed native slot through string converter
; VA 0x4ac4c0..0x4ac51c raw 0xab8c0 len 92 SHA256 1aedc70e979821e35bbab9ff7129e3160f1d333ae970be8f2771051ad023a9b0
004AC4C0 55                               push   ebp
004AC4C1 8bec                             mov    ebp,esp
004AC4C3 6aff                             push   0xffffffff
004AC4C5 68c8839300                       push   0x9383c8
004AC4CA 64a100000000                     mov    eax,fs:0x0
004AC4D0 50                               push   eax
004AC4D1 83ec0c                           sub    esp,0xc
004AC4D4 a1201fd600                       mov    eax,ds:0xd61f20
004AC4D9 33c5                             xor    eax,ebp
004AC4DB 50                               push   eax
004AC4DC 8d45f4                           lea    eax,[ebp-0xc]
004AC4DF 64a300000000                     mov    fs:0x0,eax
004AC4E5 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AC4E8 8945e8                           mov    DWORD PTR [ebp-0x18],eax
004AC4EB 33c0                             xor    eax,eax
004AC4ED 8945ec                           mov    DWORD PTR [ebp-0x14],eax
004AC4F0 8945f0                           mov    DWORD PTR [ebp-0x10],eax
004AC4F3 8945fc                           mov    DWORD PTR [ebp-0x4],eax
004AC4F6 8b0d4818fe00                     mov    ecx,DWORD PTR ds:0xfe1848
004AC4FC 51                               push   ecx
004AC4FD 8d45e8                           lea    eax,[ebp-0x18]
004AC500 e82b080000                       call   0x4acd30
004AC505 83c404                           add    esp,0x4
004AC508 b801000000                       mov    eax,0x1
004AC50D 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004AC510 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004AC517 59                               pop    ecx
004AC518 8be5                             mov    esp,ebp
004AC51A 5d                               pop    ebp
004AC51B c3                               ret

; A02 last Lua argument string/number-to-string; no function value retained
; VA 0x4acd30..0x4acd8c raw 0xac130 len 92 SHA256 5063eb847628214773abbe1e8b3d8ed88eef46df5ee854c2aa03d3d953ed0f67
004ACD30 55                               push   ebp
004ACD31 8bec                             mov    ebp,esp
004ACD33 53                               push   ebx
004ACD34 8b1d0418fe00                     mov    ebx,DWORD PTR ds:0xfe1804
004ACD3A 56                               push   esi
004ACD3B 57                               push   edi
004ACD3C 8b38                             mov    edi,DWORD PTR [eax]
004ACD3E 8b7708                           mov    esi,DWORD PTR [edi+0x8]
004ACD41 83ee10                           sub    esi,0x10
004ACD44 837e0804                         cmp    DWORD PTR [esi+0x8],0x4
004ACD48 7430                             je     0x4acd7a
004ACD4A e881e82400                       call   0x6fb5d0
004ACD4F 85c0                             test   eax,eax
004ACD51 750f                             jne    0x4acd62
004ACD53 33f6                             xor    esi,esi
004ACD55 56                               push   esi
004ACD56 8bcb                             mov    ecx,ebx
004ACD58 ff5508                           call   DWORD PTR [ebp+0x8]
004ACD5B 5f                               pop    edi
004ACD5C 5e                               pop    esi
004ACD5D 33c0                             xor    eax,eax
004ACD5F 5b                               pop    ebx
004ACD60 5d                               pop    ebp
004ACD61 c3                               ret
004ACD62 8b4710                           mov    eax,DWORD PTR [edi+0x10]
004ACD65 8b4844                           mov    ecx,DWORD PTR [eax+0x44]
004ACD68 3b4840                           cmp    ecx,DWORD PTR [eax+0x40]
004ACD6B 7207                             jb     0x4acd74
004ACD6D 8bc7                             mov    eax,edi
004ACD6F e82ce62400                       call   0x6fb3a0
004ACD74 8b7708                           mov    esi,DWORD PTR [edi+0x8]
004ACD77 83ee10                           sub    esi,0x10
004ACD7A 8b36                             mov    esi,DWORD PTR [esi]
004ACD7C 83c610                           add    esi,0x10
004ACD7F 56                               push   esi
004ACD80 8bcb                             mov    ecx,ebx
004ACD82 ff5508                           call   DWORD PTR [ebp+0x8]
004ACD85 5f                               pop    edi
004ACD86 5e                               pop    esi
004ACD87 33c0                             xor    eax,eax
004ACD89 5b                               pop    ebx
004ACD8A 5d                               pop    ebp
004ACD8B c3                               ret

; A03 Scaling Lua closure
; VA 0x4ac520..0x4ac576 raw 0xab920 len 86 SHA256 8601e7d4ccd054f44e9524afa8c023590f63c0201c48c493b2cd58c348323bf8
004AC520 55                               push   ebp
004AC521 8bec                             mov    ebp,esp
004AC523 6aff                             push   0xffffffff
004AC525 68c8839300                       push   0x9383c8
004AC52A 64a100000000                     mov    eax,fs:0x0
004AC530 50                               push   eax
004AC531 83ec0c                           sub    esp,0xc
004AC534 a1201fd600                       mov    eax,ds:0xd61f20
004AC539 33c5                             xor    eax,ebp
004AC53B 50                               push   eax
004AC53C 8d45f4                           lea    eax,[ebp-0xc]
004AC53F 64a300000000                     mov    fs:0x0,eax
004AC545 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AC548 8945e8                           mov    DWORD PTR [ebp-0x18],eax
004AC54B 33c0                             xor    eax,eax
004AC54D 8945ec                           mov    DWORD PTR [ebp-0x14],eax
004AC550 8945f0                           mov    DWORD PTR [ebp-0x10],eax
004AC553 8d4de8                           lea    ecx,[ebp-0x18]
004AC556 51                               push   ecx
004AC557 8945fc                           mov    DWORD PTR [ebp-0x4],eax
004AC55A e811090000                       call   0x4ace70
004AC55F 83c404                           add    esp,0x4
004AC562 b801000000                       mov    eax,0x1
004AC567 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004AC56A 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004AC571 59                               pop    ecx
004AC572 8be5                             mov    esp,ebp
004AC574 5d                               pop    ebp
004AC575 c3                               ret

; A04 Scaling arguments: -3 string, -2/-1 integer conversion
; VA 0x4ace70..0x4acf8b raw 0xac270 len 283 SHA256 f6ca3fe0cef18b0b04d3a6657c65bdff79f9df0c5c807b1dde119ec425a7a4a4
004ACE70 55                               push   ebp
004ACE71 8bec                             mov    ebp,esp
004ACE73 83ec20                           sub    esp,0x20
004ACE76 a14c18fe00                       mov    eax,ds:0xfe184c
004ACE7B 8b0d0418fe00                     mov    ecx,DWORD PTR ds:0xfe1804
004ACE81 53                               push   ebx
004ACE82 8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
004ACE85 56                               push   esi
004ACE86 8945e0                           mov    DWORD PTR [ebp-0x20],eax
004ACE89 894de4                           mov    DWORD PTR [ebp-0x1c],ecx
004ACE8C 8b0b                             mov    ecx,DWORD PTR [ebx]
004ACE8E 57                               push   edi
004ACE8F 83c8ff                           or     eax,0xffffffff
004ACE92 e859822400                       call   0x6f50f0
004ACE97 8b4808                           mov    ecx,DWORD PTR [eax+0x8]
004ACE9A 83f903                           cmp    ecx,0x3
004ACE9D 742e                             je     0x4acecd
004ACE9F 83f904                           cmp    ecx,0x4
004ACEA2 0f859c000000                     jne    0x4acf44
004ACEA8 8b30                             mov    esi,DWORD PTR [eax]
004ACEAA 83c610                           add    esi,0x10
004ACEAD 8d7df0                           lea    edi,[ebp-0x10]
004ACEB0 e8aba82400                       call   0x6f7760
004ACEB5 85c0                             test   eax,eax
004ACEB7 0f8487000000                     je     0x4acf44
004ACEBD dd45f0                           fld    QWORD PTR [ebp-0x10]
004ACEC0 c745f003000000                   mov    DWORD PTR [ebp-0x10],0x3
004ACEC7 dd5de8                           fstp   QWORD PTR [ebp-0x18]
004ACECA 8d45e8                           lea    eax,[ebp-0x18]
004ACECD dd00                             fld    QWORD PTR [eax]
004ACECF dd5df0                           fstp   QWORD PTR [ebp-0x10]
004ACED2 dd45f0                           fld    QWORD PTR [ebp-0x10]
004ACED5 db5d08                           fistp  DWORD PTR [ebp+0x8]
004ACED8 8b5508                           mov    edx,DWORD PTR [ebp+0x8]
004ACEDB 8955f8                           mov    DWORD PTR [ebp-0x8],edx
004ACEDE 8b0b                             mov    ecx,DWORD PTR [ebx]
004ACEE0 b8feffffff                       mov    eax,0xfffffffe
004ACEE5 e806822400                       call   0x6f50f0
004ACEEA 8b4808                           mov    ecx,DWORD PTR [eax+0x8]
004ACEED 83f903                           cmp    ecx,0x3
004ACEF0 7426                             je     0x4acf18
004ACEF2 83f904                           cmp    ecx,0x4
004ACEF5 7556                             jne    0x4acf4d
004ACEF7 8b30                             mov    esi,DWORD PTR [eax]
004ACEF9 83c610                           add    esi,0x10
004ACEFC 8d7df0                           lea    edi,[ebp-0x10]
004ACEFF e85ca82400                       call   0x6f7760
004ACF04 85c0                             test   eax,eax
004ACF06 7445                             je     0x4acf4d
004ACF08 dd45f0                           fld    QWORD PTR [ebp-0x10]
004ACF0B c745f003000000                   mov    DWORD PTR [ebp-0x10],0x3
004ACF12 dd5de8                           fstp   QWORD PTR [ebp-0x18]
004ACF15 8d45e8                           lea    eax,[ebp-0x18]
004ACF18 dd00                             fld    QWORD PTR [eax]
004ACF1A dd5df0                           fstp   QWORD PTR [ebp-0x10]
004ACF1D dd45f0                           fld    QWORD PTR [ebp-0x10]
004ACF20 db5dfc                           fistp  DWORD PTR [ebp-0x4]
004ACF23 8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
004ACF26 8945f4                           mov    DWORD PTR [ebp-0xc],eax
004ACF29 8b3b                             mov    edi,DWORD PTR [ebx]
004ACF2B 8b7708                           mov    esi,DWORD PTR [edi+0x8]
004ACF2E 83ee30                           sub    esi,0x30
004ACF31 837e0804                         cmp    DWORD PTR [esi+0x8],0x4
004ACF35 7437                             je     0x4acf6e
004ACF37 e894e62400                       call   0x6fb5d0
004ACF3C 85c0                             test   eax,eax
004ACF3E 7516                             jne    0x4acf56
004ACF40 33f6                             xor    esi,esi
004ACF42 eb2f                             jmp    0x4acf73
004ACF44 c745f800000000                   mov    DWORD PTR [ebp-0x8],0x0
004ACF4B eb91                             jmp    0x4acede
004ACF4D c745f400000000                   mov    DWORD PTR [ebp-0xc],0x0
004ACF54 ebd3                             jmp    0x4acf29
004ACF56 8b4710                           mov    eax,DWORD PTR [edi+0x10]
004ACF59 8b4844                           mov    ecx,DWORD PTR [eax+0x44]
004ACF5C 3b4840                           cmp    ecx,DWORD PTR [eax+0x40]
004ACF5F 7207                             jb     0x4acf68
004ACF61 8bc7                             mov    eax,edi
004ACF63 e838e42400                       call   0x6fb3a0
004ACF68 8b7708                           mov    esi,DWORD PTR [edi+0x8]
004ACF6B 83ee30                           sub    esi,0x30
004ACF6E 8b36                             mov    esi,DWORD PTR [esi]
004ACF70 83c610                           add    esi,0x10
004ACF73 8b55f8                           mov    edx,DWORD PTR [ebp-0x8]
004ACF76 8b45f4                           mov    eax,DWORD PTR [ebp-0xc]
004ACF79 8b4de4                           mov    ecx,DWORD PTR [ebp-0x1c]
004ACF7C 52                               push   edx
004ACF7D 50                               push   eax
004ACF7E 56                               push   esi
004ACF7F ff55e0                           call   DWORD PTR [ebp-0x20]
004ACF82 5f                               pop    edi
004ACF83 5e                               pop    esi
004ACF84 33c0                             xor    eax,eax
004ACF86 5b                               pop    ebx
004ACF87 8be5                             mov    esp,ebp
004ACF89 5d                               pop    ebp
004ACF8A c3                               ret

; A05 only tag3 number is converted to string by fallback
; VA 0x6fb5d0..0x6fb655 raw 0x2fa9d0 len 133 SHA256 f5b6289ee0224300b634ecb42ab84cecced05aae40249abcbdb709841f5ea073
006FB5D0 55                               push   ebp
006FB5D1 8bec                             mov    ebp,esp
006FB5D3 83e4c0                           and    esp,0xffffffc0
006FB5D6 83ec40                           sub    esp,0x40
006FB5D9 a1201fd600                       mov    eax,ds:0xd61f20
006FB5DE 33c4                             xor    eax,esp
006FB5E0 8944243c                         mov    DWORD PTR [esp+0x3c],eax
006FB5E4 837e0803                         cmp    DWORD PTR [esi+0x8],0x3
006FB5E8 7411                             je     0x6fb5fb
006FB5EA 33c0                             xor    eax,eax
006FB5EC 8b4c243c                         mov    ecx,DWORD PTR [esp+0x3c]
006FB5F0 33cc                             xor    ecx,esp
006FB5F2 e80a5a1900                       call   0x891001
006FB5F7 8be5                             mov    esp,ebp
006FB5F9 5d                               pop    ebp
006FB5FA c3                               ret
006FB5FB dd06                             fld    QWORD PTR [esi]
006FB5FD 83ec08                           sub    esp,0x8
006FB600 dd1c24                           fstp   QWORD PTR [esp]
006FB603 8d442424                         lea    eax,[esp+0x24]
006FB607 68102ac400                       push   0xc42a10
006FB60C 50                               push   eax
006FB60D e81d751900                       call   0x892b2f
006FB612 8d44242c                         lea    eax,[esp+0x2c]
006FB616 83c410                           add    esp,0x10
006FB619 8d5001                           lea    edx,[eax+0x1]
006FB61C 8d642400                         lea    esp,[esp+0x0]
006FB620 8a08                             mov    cl,BYTE PTR [eax]
006FB622 40                               inc    eax
006FB623 84c9                             test   cl,cl
006FB625 75f9                             jne    0x6fb620
006FB627 2bc2                             sub    eax,edx
006FB629 50                               push   eax
006FB62A 8d4c2420                         lea    ecx,[esp+0x20]
006FB62E 51                               push   ecx
006FB62F 57                               push   edi
006FB630 e83b360000                       call   0x6fec70
006FB635 8b4c2448                         mov    ecx,DWORD PTR [esp+0x48]
006FB639 83c40c                           add    esp,0xc
006FB63C 8906                             mov    DWORD PTR [esi],eax
006FB63E 33cc                             xor    ecx,esp
006FB640 c7460804000000                   mov    DWORD PTR [esi+0x8],0x4
006FB647 b801000000                       mov    eax,0x1
006FB64C e8b0591900                       call   0x891001
006FB651 8be5                             mov    esp,ebp
006FB653 5d                               pop    ebp
006FB654 c3                               ret

; A06 DestroyFlyingObjects Lua closure
; VA 0x4ac580..0x4ac5d6 raw 0xab980 len 86 SHA256 c2847520786c3415debb87a65d7d47eeef91ddc9d23493498af86db4b8566f67
004AC580 55                               push   ebp
004AC581 8bec                             mov    ebp,esp
004AC583 6aff                             push   0xffffffff
004AC585 68c8839300                       push   0x9383c8
004AC58A 64a100000000                     mov    eax,fs:0x0
004AC590 50                               push   eax
004AC591 83ec0c                           sub    esp,0xc
004AC594 a1201fd600                       mov    eax,ds:0xd61f20
004AC599 33c5                             xor    eax,ebp
004AC59B 50                               push   eax
004AC59C 8d45f4                           lea    eax,[ebp-0xc]
004AC59F 64a300000000                     mov    fs:0x0,eax
004AC5A5 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AC5A8 8945e8                           mov    DWORD PTR [ebp-0x18],eax
004AC5AB 33c0                             xor    eax,eax
004AC5AD 8945ec                           mov    DWORD PTR [ebp-0x14],eax
004AC5B0 8945f0                           mov    DWORD PTR [ebp-0x10],eax
004AC5B3 8945fc                           mov    DWORD PTR [ebp-0x4],eax
004AC5B6 8b0d0418fe00                     mov    ecx,DWORD PTR ds:0xfe1804
004AC5BC ff155018fe00                     call   DWORD PTR ds:0xfe1850
004AC5C2 b801000000                       mov    eax,0x1
004AC5C7 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004AC5CA 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004AC5D1 59                               pop    ecx
004AC5D2 8be5                             mov    esp,ebp
004AC5D4 5d                               pop    ebp
004AC5D5 c3                               ret

; F01 construct typed Skip display, add T tracking and global flying manager
; VA 0x4a9b70..0x4a9c78 raw 0xa8f70 len 264 SHA256 709dd824fcc4d8e364d2acb07919b423b3dd0ee4188da11b6cd165025f892e90
004A9B70 55                               push   ebp
004A9B71 8bec                             mov    ebp,esp
004A9B73 6aff                             push   0xffffffff
004A9B75 6889b69100                       push   0x91b689
004A9B7A 64a100000000                     mov    eax,fs:0x0
004A9B80 50                               push   eax
004A9B81 83ec0c                           sub    esp,0xc
004A9B84 56                               push   esi
004A9B85 57                               push   edi
004A9B86 a1201fd600                       mov    eax,ds:0xd61f20
004A9B8B 33c5                             xor    eax,ebp
004A9B8D 50                               push   eax
004A9B8E 8d45f4                           lea    eax,[ebp-0xc]
004A9B91 64a300000000                     mov    fs:0x0,eax
004A9B97 8bf1                             mov    esi,ecx
004A9B99 6a64                             push   0x64
004A9B9B e8c8763e00                       call   0x891268
004A9BA0 8bf8                             mov    edi,eax
004A9BA2 83c404                           add    esp,0x4
004A9BA5 897dec                           mov    DWORD PTR [ebp-0x14],edi
004A9BA8 c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
004A9BAF 85ff                             test   edi,edi
004A9BB1 7412                             je     0x4a9bc5
004A9BB3 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004A9BB6 50                               push   eax
004A9BB7 57                               push   edi
004A9BB8 e8d3a00a00                       call   0x553c90
004A9BBD c7074c69c000                     mov    DWORD PTR [edi],0xc0694c
004A9BC3 eb02                             jmp    0x4a9bc7
004A9BC5 33ff                             xor    edi,edi
004A9BC7 8d4d08                           lea    ecx,[ebp+0x8]
004A9BCA c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
004A9BD1 83c614                           add    esi,0x14
004A9BD4 51                               push   ecx
004A9BD5 897d08                           mov    DWORD PTR [ebp+0x8],edi
004A9BD8 e863422100                       call   0x6bde40
004A9BDD 50                               push   eax
004A9BDE 56                               push   esi
004A9BDF 8d75e8                           lea    esi,[ebp-0x18]
004A9BE2 e8e91ffaff                       call   0x44bbd0
004A9BE7 f6055473fb0001                   test   BYTE PTR ds:0xfb7354,0x1
004A9BEE 7527                             jne    0x4a9c17
004A9BF0 b801000000                       mov    eax,0x1
004A9BF5 09055473fb00                     or     DWORD PTR ds:0xfb7354,eax
004A9BFB 8945fc                           mov    DWORD PTR [ebp-0x4],eax
004A9BFE e8cd970a00                       call   0x5533d0
004A9C03 6800d1bc00                       push   0xbcd100
004A9C08 e80d873e00                       call   0x89231a
004A9C0D 83c404                           add    esp,0x4
004A9C10 c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
004A9C17 8b17                             mov    edx,DWORD PTR [edi]
004A9C19 8b4204                           mov    eax,DWORD PTR [edx+0x4]
004A9C1C 8bcf                             mov    ecx,edi
004A9C1E ffd0                             call   eax
004A9C20 a1b073fb00                       mov    eax,ds:0xfb73b0
004A9C25 8b0dac73fb00                     mov    ecx,DWORD PTR ds:0xfb73ac
004A9C2B 8b17                             mov    edx,DWORD PTR [edi]
004A9C2D 8b5220                           mov    edx,DWORD PTR [edx+0x20]
004A9C30 50                               push   eax
004A9C31 51                               push   ecx
004A9C32 8bcf                             mov    ecx,edi
004A9C34 ffd2                             call   edx
004A9C36 c7474000000000                   mov    DWORD PTR [edi+0x40],0x0
004A9C3D a19873fb00                       mov    eax,ds:0xfb7398
004A9C42 897dec                           mov    DWORD PTR [ebp-0x14],edi
004A9C45 8d7de8                           lea    edi,[ebp-0x18]
004A9C48 be5873fb00                       mov    esi,0xfb7358
004A9C4D 8945e8                           mov    DWORD PTR [ebp-0x18],eax
004A9C50 e8cb520d00                       call   0x57ef20
004A9C55 50                               push   eax
004A9C56 56                               push   esi
004A9C57 8d75e8                           lea    esi,[ebp-0x18]
004A9C5A e8a1553800                       call   0x82f200
004A9C5F ff059873fb00                     inc    DWORD PTR ds:0xfb7398
004A9C65 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004A9C68 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004A9C6F 59                               pop    ecx
004A9C70 5f                               pop    edi
004A9C71 5e                               pop    esi
004A9C72 8be5                             mov    esp,ebp
004A9C74 5d                               pop    ebp
004A9C75 c20400                           ret    0x4

; F02 construct Scaling display, save width/height, add both owners
; VA 0x4a9c80..0x4a9da1 raw 0xa9080 len 289 SHA256 c87cba7ca70ea6260778a8e1079f0b7b9d0c9463b1d721f205612d6aac4415aa
004A9C80 55                               push   ebp
004A9C81 8bec                             mov    ebp,esp
004A9C83 6aff                             push   0xffffffff
004A9C85 6889b69100                       push   0x91b689
004A9C8A 64a100000000                     mov    eax,fs:0x0
004A9C90 50                               push   eax
004A9C91 83ec0c                           sub    esp,0xc
004A9C94 56                               push   esi
004A9C95 57                               push   edi
004A9C96 a1201fd600                       mov    eax,ds:0xd61f20
004A9C9B 33c5                             xor    eax,ebp
004A9C9D 50                               push   eax
004A9C9E 8d45f4                           lea    eax,[ebp-0xc]
004A9CA1 64a300000000                     mov    fs:0x0,eax
004A9CA7 8bf1                             mov    esi,ecx
004A9CA9 6a74                             push   0x74
004A9CAB e8b8753e00                       call   0x891268
004A9CB0 8bf8                             mov    edi,eax
004A9CB2 83c404                           add    esp,0x4
004A9CB5 897dec                           mov    DWORD PTR [ebp-0x14],edi
004A9CB8 c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
004A9CBF 85ff                             test   edi,edi
004A9CC1 742b                             je     0x4a9cee
004A9CC3 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004A9CC6 50                               push   eax
004A9CC7 57                               push   edi
004A9CC8 e8c39f0a00                       call   0x553c90
004A9CCD 8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
004A9CD0 8b5510                           mov    edx,DWORD PTR [ebp+0x10]
004A9CD3 0f57c0                           xorps  xmm0,xmm0
004A9CD6 c7077c69c000                     mov    DWORD PTR [edi],0xc0697c
004A9CDC 894f64                           mov    DWORD PTR [edi+0x64],ecx
004A9CDF 895768                           mov    DWORD PTR [edi+0x68],edx
004A9CE2 f30f11476c                       movss  DWORD PTR [edi+0x6c],xmm0
004A9CE7 f30f114770                       movss  DWORD PTR [edi+0x70],xmm0
004A9CEC eb02                             jmp    0x4a9cf0
004A9CEE 33ff                             xor    edi,edi
004A9CF0 8d4508                           lea    eax,[ebp+0x8]
004A9CF3 c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
004A9CFA 83c614                           add    esi,0x14
004A9CFD 50                               push   eax
004A9CFE 897d08                           mov    DWORD PTR [ebp+0x8],edi
004A9D01 e83a412100                       call   0x6bde40
004A9D06 50                               push   eax
004A9D07 56                               push   esi
004A9D08 8d75e8                           lea    esi,[ebp-0x18]
004A9D0B e8c01efaff                       call   0x44bbd0
004A9D10 f6055473fb0001                   test   BYTE PTR ds:0xfb7354,0x1
004A9D17 7527                             jne    0x4a9d40
004A9D19 b801000000                       mov    eax,0x1
004A9D1E 09055473fb00                     or     DWORD PTR ds:0xfb7354,eax
004A9D24 8945fc                           mov    DWORD PTR [ebp-0x4],eax
004A9D27 e8a4960a00                       call   0x5533d0
004A9D2C 6800d1bc00                       push   0xbcd100
004A9D31 e8e4853e00                       call   0x89231a
004A9D36 83c404                           add    esp,0x4
004A9D39 c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
004A9D40 8b17                             mov    edx,DWORD PTR [edi]
004A9D42 8b4204                           mov    eax,DWORD PTR [edx+0x4]
004A9D45 8bcf                             mov    ecx,edi
004A9D47 ffd0                             call   eax
004A9D49 a1b073fb00                       mov    eax,ds:0xfb73b0
004A9D4E 8b0dac73fb00                     mov    ecx,DWORD PTR ds:0xfb73ac
004A9D54 8b17                             mov    edx,DWORD PTR [edi]
004A9D56 8b5220                           mov    edx,DWORD PTR [edx+0x20]
004A9D59 50                               push   eax
004A9D5A 51                               push   ecx
004A9D5B 8bcf                             mov    ecx,edi
004A9D5D ffd2                             call   edx
004A9D5F c7474000000000                   mov    DWORD PTR [edi+0x40],0x0
004A9D66 a19873fb00                       mov    eax,ds:0xfb7398
004A9D6B 897dec                           mov    DWORD PTR [ebp-0x14],edi
004A9D6E 8d7de8                           lea    edi,[ebp-0x18]
004A9D71 be5873fb00                       mov    esi,0xfb7358
004A9D76 8945e8                           mov    DWORD PTR [ebp-0x18],eax
004A9D79 e8a2510d00                       call   0x57ef20
004A9D7E 50                               push   eax
004A9D7F 56                               push   esi
004A9D80 8d75e8                           lea    esi,[ebp-0x18]
004A9D83 e878543800                       call   0x82f200
004A9D88 ff059873fb00                     inc    DWORD PTR ds:0xfb7398
004A9D8E 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004A9D91 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004A9D98 59                               pop    ecx
004A9D99 5f                               pop    edi
004A9D9A 5e                               pop    esi
004A9D9B 8be5                             mov    esp,ebp
004A9D9D 5d                               pop    ebp
004A9D9E c20c00                           ret    0xc

; F03 CSimpleObject stores texture string and lifetime flag
; VA 0x553c90..0x553d41 raw 0x153090 len 177 SHA256 9fd71fed438439efa14c9058a9dbd4669e0956f6759beed47a6c8867bff35455
00553C90 55                               push   ebp
00553C91 8bec                             mov    ebp,esp
00553C93 6aff                             push   0xffffffff
00553C95 68086d9100                       push   0x916d08
00553C9A 64a100000000                     mov    eax,fs:0x0
00553CA0 50                               push   eax
00553CA1 53                               push   ebx
00553CA2 56                               push   esi
00553CA3 57                               push   edi
00553CA4 a1201fd600                       mov    eax,ds:0xd61f20
00553CA9 33c5                             xor    eax,ebp
00553CAB 50                               push   eax
00553CAC 8d45f4                           lea    eax,[ebp-0xc]
00553CAF 64a300000000                     mov    fs:0x0,eax
00553CB5 8b5d0c                           mov    ebx,DWORD PTR [ebp+0xc]
00553CB8 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
00553CBB 33c0                             xor    eax,eax
00553CBD 894604                           mov    DWORD PTR [esi+0x4],eax
00553CC0 894608                           mov    DWORD PTR [esi+0x8],eax
00553CC3 894618                           mov    DWORD PTR [esi+0x18],eax
00553CC6 89461c                           mov    DWORD PTR [esi+0x1c],eax
00553CC9 894620                           mov    DWORD PTR [esi+0x20],eax
00553CCC 894624                           mov    DWORD PTR [esi+0x24],eax
00553CCF 894628                           mov    DWORD PTR [esi+0x28],eax
00553CD2 89462c                           mov    DWORD PTR [esi+0x2c],eax
00553CD5 894630                           mov    DWORD PTR [esi+0x30],eax
00553CD8 894634                           mov    DWORD PTR [esi+0x34],eax
00553CDB 884638                           mov    BYTE PTR [esi+0x38],al
00553CDE 894610                           mov    DWORD PTR [esi+0x10],eax
00553CE1 89460c                           mov    DWORD PTR [esi+0xc],eax
00553CE4 c7461401000000                   mov    DWORD PTR [esi+0x14],0x1
00553CEB 8945fc                           mov    DWORD PTR [ebp-0x4],eax
00553CEE c70664ffc000                     mov    DWORD PTR [esi],0xc0ff64
00553CF4 894644                           mov    DWORD PTR [esi+0x44],eax
00553CF7 8bd3                             mov    edx,ebx
00553CF9 8d4a01                           lea    ecx,[edx+0x1]
00553CFC c7465c0f000000                   mov    DWORD PTR [esi+0x5c],0xf
00553D03 894658                           mov    DWORD PTR [esi+0x58],eax
00553D06 884648                           mov    BYTE PTR [esi+0x48],al
00553D09 894d0c                           mov    DWORD PTR [ebp+0xc],ecx
00553D0C 8d642400                         lea    esp,[esp+0x0]
00553D10 8a0a                             mov    cl,BYTE PTR [edx]
00553D12 42                               inc    edx
00553D13 3ac8                             cmp    cl,al
00553D15 75f9                             jne    0x553d10
00553D17 2b550c                           sub    edx,DWORD PTR [ebp+0xc]
00553D1A 8d4e48                           lea    ecx,[esi+0x48]
00553D1D 52                               push   edx
00553D1E 53                               push   ebx
00553D1F e84cedeaff                       call   0x402a70
00553D24 c7461401000000                   mov    DWORD PTR [esi+0x14],0x1
00553D2B 8bc6                             mov    eax,esi
00553D2D 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
00553D30 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00553D37 59                               pop    ecx
00553D38 5f                               pop    edi
00553D39 5e                               pop    esi
00553D3A 5b                               pop    ebx
00553D3B 8be5                             mov    esp,ebp
00553D3D 5d                               pop    ebp
00553D3E c20800                           ret    0x8

; F04 Skip texture loader
; VA 0x553da0..0x553dde raw 0x1531a0 len 62 SHA256 2446428be0bc16807e68f28619eb5456ac8cc0c231f8363582b38aaf26bbbdea
00553DA0 56                               push   esi
00553DA1 57                               push   edi
00553DA2 8bf9                             mov    edi,ecx
00553DA4 837f5c10                         cmp    DWORD PTR [edi+0x5c],0x10
00553DA8 8d7748                           lea    esi,[edi+0x48]
00553DAB 7204                             jb     0x553db1
00553DAD 8b06                             mov    eax,DWORD PTR [esi]
00553DAF eb02                             jmp    0x553db3
00553DB1 8bc6                             mov    eax,esi
00553DB3 6a00                             push   0x0
00553DB5 50                               push   eax
00553DB6 e875051e00                       call   0x734330
00553DBB 83c408                           add    esp,0x8
00553DBE 894744                           mov    DWORD PTR [edi+0x44],eax
00553DC1 85c0                             test   eax,eax
00553DC3 7516                             jne    0x553ddb
00553DC5 837e1410                         cmp    DWORD PTR [esi+0x14],0x10
00553DC9 7202                             jb     0x553dcd
00553DCB 8b36                             mov    esi,DWORD PTR [esi]
00553DCD 56                               push   esi
00553DCE 68e8fec000                       push   0xc0fee8
00553DD3 e8889d1900                       call   0x6edb60
00553DD8 83c408                           add    esp,0x8
00553DDB 5f                               pop    edi
00553DDC 5e                               pop    esi
00553DDD c3                               ret

; F05 Scaling texture loader computes width/height ratios
; VA 0x4a8830..0x4a88ae raw 0xa7c30 len 126 SHA256 33b5c26d5fa83f4cc547e4ce70b0fffffd8f9c821a46bc259eeb59e87510352a
004A8830 55                               push   ebp
004A8831 8bec                             mov    ebp,esp
004A8833 83ec08                           sub    esp,0x8
004A8836 56                               push   esi
004A8837 8bf1                             mov    esi,ecx
004A8839 837e5c10                         cmp    DWORD PTR [esi+0x5c],0x10
004A883D 57                               push   edi
004A883E 8d7e48                           lea    edi,[esi+0x48]
004A8841 7204                             jb     0x4a8847
004A8843 8b07                             mov    eax,DWORD PTR [edi]
004A8845 eb02                             jmp    0x4a8849
004A8847 8bc7                             mov    eax,edi
004A8849 6a00                             push   0x0
004A884B 50                               push   eax
004A884C e8dfba2800                       call   0x734330
004A8851 83c408                           add    esp,0x8
004A8854 894644                           mov    DWORD PTR [esi+0x44],eax
004A8857 85c0                             test   eax,eax
004A8859 7516                             jne    0x4a8871
004A885B 837f1410                         cmp    DWORD PTR [edi+0x14],0x10
004A885F 7202                             jb     0x4a8863
004A8861 8b3f                             mov    edi,DWORD PTR [edi]
004A8863 57                               push   edi
004A8864 68e8fec000                       push   0xc0fee8
004A8869 e8f2522400                       call   0x6edb60
004A886E 83c408                           add    esp,0x8
004A8871 8b4644                           mov    eax,DWORD PTR [esi+0x44]
004A8874 85c0                             test   eax,eax
004A8876 7430                             je     0x4a88a8
004A8878 837e6400                         cmp    DWORD PTR [esi+0x64],0x0
004A887C 8b480c                           mov    ecx,DWORD PTR [eax+0xc]
004A887F 8b4010                           mov    eax,DWORD PTR [eax+0x10]
004A8882 894dfc                           mov    DWORD PTR [ebp-0x4],ecx
004A8885 8945f8                           mov    DWORD PTR [ebp-0x8],eax
004A8888 750c                             jne    0x4a8896
004A888A 837e6800                         cmp    DWORD PTR [esi+0x68],0x0
004A888E 7506                             jne    0x4a8896
004A8890 894e64                           mov    DWORD PTR [esi+0x64],ecx
004A8893 894668                           mov    DWORD PTR [esi+0x68],eax
004A8896 db4664                           fild   DWORD PTR [esi+0x64]
004A8899 da75fc                           fidiv  DWORD PTR [ebp-0x4]
004A889C d95e6c                           fstp   DWORD PTR [esi+0x6c]
004A889F db4668                           fild   DWORD PTR [esi+0x68]
004A88A2 da75f8                           fidiv  DWORD PTR [ebp-0x8]
004A88A5 d95e70                           fstp   DWORD PTR [esi+0x70]
004A88A8 5f                               pop    edi
004A88A9 5e                               pop    esi
004A88AA 8be5                             mov    esp,ebp
004A88AC 5d                               pop    ebp
004A88AD c3                               ret

; F06 Skip position is fixed (32,32)
; VA 0x4a87d0..0x4a87dc raw 0xa7bd0 len 12 SHA256 ec6d1a3dcf664c3b3ac7f76ac7afe016072154fe896ac48887a65eff2017c052
004A87D0 b820000000                       mov    eax,0x20
004A87D5 89410c                           mov    DWORD PTR [ecx+0xc],eax
004A87D8 894110                           mov    DWORD PTR [ecx+0x10],eax
004A87DB c3                               ret

; F07 Scaling position derives from viewport size
; VA 0x4a8810..0x4a882a raw 0xa7c10 len 26 SHA256 559d82d73f6877fb7d39377da013d01461e71b614628bfc43a84cf85d339755d
004A8810 8b4104                           mov    eax,DWORD PTR [ecx+0x4]
004A8813 99                               cdq
004A8814 2bc2                             sub    eax,edx
004A8816 d1f8                             sar    eax,1
004A8818 89410c                           mov    DWORD PTR [ecx+0xc],eax
004A881B 8b4108                           mov    eax,DWORD PTR [ecx+0x8]
004A881E 99                               cdq
004A881F 2bc2                             sub    eax,edx
004A8821 d1f8                             sar    eax,1
004A8823 83e83c                           sub    eax,0x3c
004A8826 894110                           mov    DWORD PTR [ecx+0x10],eax
004A8829 c3                               ret

; F08 Skip drawing consumer; texture virtual call
; VA 0x4a87e0..0x4a880b raw 0xa7be0 len 43 SHA256 765c15cba798d8194532b9c3c625e6112ac22b309385d5044620e691c1a037a8
004A87E0 8bc1                             mov    eax,ecx
004A87E2 83784400                         cmp    DWORD PTR [eax+0x44],0x0
004A87E6 7422                             je     0x4a880a
004A87E8 8b4844                           mov    ecx,DWORD PTR [eax+0x44]
004A87EB d9ee                             fldz
004A87ED 8b11                             mov    edx,DWORD PTR [ecx]
004A87EF 8b5224                           mov    edx,DWORD PTR [edx+0x24]
004A87F2 56                               push   esi
004A87F3 8b7010                           mov    esi,DWORD PTR [eax+0x10]
004A87F6 8b400c                           mov    eax,DWORD PTR [eax+0xc]
004A87F9 6aff                             push   0xffffffff
004A87FB 51                               push   ecx
004A87FC d91c24                           fstp   DWORD PTR [esp]
004A87FF 6a00                             push   0x0
004A8801 6a00                             push   0x0
004A8803 6a00                             push   0x0
004A8805 56                               push   esi
004A8806 50                               push   eax
004A8807 ffd2                             call   edx
004A8809 5e                               pop    esi
004A880A c3                               ret

; F09 Scaling drawing consumer; scale pointer to texture renderer
; VA 0x4a88b0..0x4a88dd raw 0xa7cb0 len 45 SHA256 7841c1fdc5bbca80560fd760dc3ef256fb8e6a2d8b526919e545458b8284e97e
004A88B0 8bc1                             mov    eax,ecx
004A88B2 83784400                         cmp    DWORD PTR [eax+0x44],0x0
004A88B6 7424                             je     0x4a88dc
004A88B8 8b4844                           mov    ecx,DWORD PTR [eax+0x44]
004A88BB d9ee                             fldz
004A88BD 8b11                             mov    edx,DWORD PTR [ecx]
004A88BF 8b5224                           mov    edx,DWORD PTR [edx+0x24]
004A88C2 56                               push   esi
004A88C3 6aff                             push   0xffffffff
004A88C5 51                               push   ecx
004A88C6 d91c24                           fstp   DWORD PTR [esp]
004A88C9 6a01                             push   0x1
004A88CB 8d706c                           lea    esi,[eax+0x6c]
004A88CE 56                               push   esi
004A88CF 8b7010                           mov    esi,DWORD PTR [eax+0x10]
004A88D2 8b400c                           mov    eax,DWORD PTR [eax+0xc]
004A88D5 6a00                             push   0x0
004A88D7 56                               push   esi
004A88D8 50                               push   eax
004A88D9 ffd2                             call   edx
004A88DB 5e                               pop    esi
004A88DC c3                               ret

; F10 CClient loaded-frame gate and global flying manager update after Q tick
; VA 0x491e71..0x491f43 raw 0x91271 len 210 SHA256 c3e6dc2ded648e89faa41952858fac4c37da4afd61923fe05e8369fe78cb767c
00491E71 8b442420                         mov    eax,DWORD PTR [esp+0x20]
00491E75 83b8ccbf000000                   cmp    DWORD PTR [eax+0xbfcc],0x0
00491E7C 0f85c1000000                     jne    0x491f43
00491E82 e84983ffff                       call   0x48a1d0
00491E87 50                               push   eax
00491E88 e8f3900c00                       call   0x55af80
00491E8D e81e81ffff                       call   0x489fb0
00491E92 50                               push   eax
00491E93 e878b00d00                       call   0x56cf10
00491E98 e803e1faff                       call   0x43ffa0
00491E9D 8bf8                             mov    edi,eax
00491E9F 8b4f08                           mov    ecx,DWORD PTR [edi+0x8]
00491EA2 be01000000                       mov    esi,0x1
00491EA7 017740                           add    DWORD PTR [edi+0x40],esi
00491EAA 8b11                             mov    edx,DWORD PTR [ecx]
00491EAC 8b4224                           mov    eax,DWORD PTR [edx+0x24]
00491EAF ffd0                             call   eax
00491EB1 8b473c                           mov    eax,DWORD PTR [edi+0x3c]
00491EB4 85c0                             test   eax,eax
00491EB6 7e04                             jle    0x491ebc
00491EB8 48                               dec    eax
00491EB9 89473c                           mov    DWORD PTR [edi+0x3c],eax
00491EBC 837f3c00                         cmp    DWORD PTR [edi+0x3c],0x0
00491EC0 750e                             jne    0x491ed0
00491EC2 8b4f50                           mov    ecx,DWORD PTR [edi+0x50]
00491EC5 894f3c                           mov    DWORD PTR [edi+0x3c],ecx
00491EC8 8b4f4c                           mov    ecx,DWORD PTR [edi+0x4c]
00491ECB e860362a00                       call   0x735530
00491ED0 e86b10f9ff                       call   0x422f40
00491ED5 8bc8                             mov    ecx,eax
00491ED7 e844f60c00                       call   0x561520
00491EDC e8cf81ffff                       call   0x48a0b0
00491EE1 e8eada0c00                       call   0x55f9d0
00491EE6 e83582ffff                       call   0x48a120
00491EEB 8bc8                             mov    ecx,eax
00491EED e87e000f00                       call   0x581f70
00491EF2 f6050c8ffd0001                   test   BYTE PTR ds:0xfd8f0c,0x1
00491EF9 7518                             jne    0x491f13
00491EFB 09350c8ffd00                     or     DWORD PTR ds:0xfd8f0c,esi
00491F01 e81a720c00                       call   0x559120
00491F06 6860dfbc00                       push   0xbcdf60
00491F0B e80a044000                       call   0x89231a
00491F10 83c404                           add    esp,0x4
00491F13 be108ffd00                       mov    esi,0xfd8f10
00491F18 e873740c00                       call   0x559390
00491F1D e86e82ffff                       call   0x48a190
00491F22 e8b9220c00                       call   0x5541e0
00491F27 e8a40ff9ff                       call   0x422ed0
00491F2C 50                               push   eax
00491F2D e8be180c00                       call   0x5537f0
00491F32 e8e927f8ff                       call   0x414720
00491F37 8bf0                             mov    esi,eax
00491F39 e892f50d00                       call   0x5714d0
00491F3E e8fd27faff                       call   0x434740

; F11 four-tree per-frame update; virtual +14 then +24 lifetime predicate
; VA 0x5537f0..0x553991 raw 0x152bf0 len 417 SHA256 4e325989863bc8a60288bc728364ee33ea7be8ce0141af7980c0c37043119bdb
005537F0 55                               push   ebp
005537F1 8bec                             mov    ebp,esp
005537F3 83ec10                           sub    esp,0x10
005537F6 53                               push   ebx
005537F7 56                               push   esi
005537F8 33c0                             xor    eax,eax
005537FA 57                               push   edi
005537FB 33db                             xor    ebx,ebx
005537FD eb03                             jmp    0x553802
005537FF 90                               nop
00553800 33c0                             xor    eax,eax
00553802 8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
00553805 8945f4                           mov    DWORD PTR [ebp-0xc],eax
00553808 8945f8                           mov    DWORD PTR [ebp-0x8],eax
0055380B b901000000                       mov    ecx,0x1
00553810 3bd8                             cmp    ebx,eax
00553812 7e09                             jle    0x55381d
00553814 39449f40                         cmp    DWORD PTR [edi+ebx*4+0x40],eax
00553818 7403                             je     0x55381d
0055381A 894df4                           mov    DWORD PTR [ebp-0xc],ecx
0055381D 8bd3                             mov    edx,ebx
0055381F c1e204                           shl    edx,0x4
00553822 8b443a04                         mov    eax,DWORD PTR [edx+edi*1+0x4]
00553826 8b30                             mov    esi,DWORD PTR [eax]
00553828 03d7                             add    edx,edi
0055382A 8955fc                           mov    DWORD PTR [ebp-0x4],edx
0055382D 3bf0                             cmp    esi,eax
0055382F 0f84d3000000                     je     0x553908
00553835 eb0e                             jmp    0x553845
00553837 eb07                             jmp    0x553840
00553839 8da42400000000                   lea    esp,[esp+0x0]
00553840 b901000000                       mov    ecx,0x1
00553845 8b5204                           mov    edx,DWORD PTR [edx+0x4]
00553848 8b02                             mov    eax,DWORD PTR [edx]
0055384A 8b7e10                           mov    edi,DWORD PTR [esi+0x10]
0055384D 3bf0                             cmp    esi,eax
0055384F 7415                             je     0x553866
00553851 8b4010                           mov    eax,DWORD PTR [eax+0x10]
00553854 83783c00                         cmp    DWORD PTR [eax+0x3c],0x0
00553858 7503                             jne    0x55385d
0055385A 894df8                           mov    DWORD PTR [ebp-0x8],ecx
0055385D 837f3c00                         cmp    DWORD PTR [edi+0x3c],0x0
00553861 7503                             jne    0x553866
00553863 894df8                           mov    DWORD PTR [ebp-0x8],ecx
00553866 837df400                         cmp    DWORD PTR [ebp-0xc],0x0
0055386A 7506                             jne    0x553872
0055386C 837df800                         cmp    DWORD PTR [ebp-0x8],0x0
00553870 7403                             je     0x553875
00553872 014f24                           add    DWORD PTR [edi+0x24],ecx
00553875 8b17                             mov    edx,DWORD PTR [edi]
00553877 8b4214                           mov    eax,DWORD PTR [edx+0x14]
0055387A 8bcf                             mov    ecx,edi
0055387C ffd0                             call   eax
0055387E 8b17                             mov    edx,DWORD PTR [edi]
00553880 8b4224                           mov    eax,DWORD PTR [edx+0x24]
00553883 8bcf                             mov    ecx,edi
00553885 ffd0                             call   eax
00553887 85c0                             test   eax,eax
00553889 7525                             jne    0x5538b0
0055388B 8b17                             mov    edx,DWORD PTR [edi]
0055388D 8b4208                           mov    eax,DWORD PTR [edx+0x8]
00553890 8bcf                             mov    ecx,edi
00553892 ffd0                             call   eax
00553894 8b17                             mov    edx,DWORD PTR [edi]
00553896 8b02                             mov    eax,DWORD PTR [edx]
00553898 6a01                             push   0x1
0055389A 8bcf                             mov    ecx,edi
0055389C ffd0                             call   eax
0055389E 8b55fc                           mov    edx,DWORD PTR [ebp-0x4]
005538A1 56                               push   esi
005538A2 8d4df0                           lea    ecx,[ebp-0x10]
005538A5 51                               push   ecx
005538A6 52                               push   edx
005538A7 e8e42f2600                       call   0x7b6890
005538AC 8b30                             mov    esi,DWORD PTR [eax]
005538AE eb47                             jmp    0x5538f7
005538B0 807e1500                         cmp    BYTE PTR [esi+0x15],0x0
005538B4 7541                             jne    0x5538f7
005538B6 8b4608                           mov    eax,DWORD PTR [esi+0x8]
005538B9 80781500                         cmp    BYTE PTR [eax+0x15],0x0
005538BD 751d                             jne    0x5538dc
005538BF 8bf0                             mov    esi,eax
005538C1 8b06                             mov    eax,DWORD PTR [esi]
005538C3 80781500                         cmp    BYTE PTR [eax+0x15],0x0
005538C7 752e                             jne    0x5538f7
005538C9 8da42400000000                   lea    esp,[esp+0x0]
005538D0 8bf0                             mov    esi,eax
005538D2 8b06                             mov    eax,DWORD PTR [esi]
005538D4 80781500                         cmp    BYTE PTR [eax+0x15],0x0
005538D8 74f6                             je     0x5538d0
005538DA eb1b                             jmp    0x5538f7
005538DC 8b4604                           mov    eax,DWORD PTR [esi+0x4]
005538DF 80781500                         cmp    BYTE PTR [eax+0x15],0x0
005538E3 7510                             jne    0x5538f5
005538E5 3b7008                           cmp    esi,DWORD PTR [eax+0x8]
005538E8 750b                             jne    0x5538f5
005538EA 8bf0                             mov    esi,eax
005538EC 8b4004                           mov    eax,DWORD PTR [eax+0x4]
005538EF 80781500                         cmp    BYTE PTR [eax+0x15],0x0
005538F3 74f0                             je     0x5538e5
005538F5 8bf0                             mov    esi,eax
005538F7 8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
005538FA 8bd0                             mov    edx,eax
005538FC 3b7004                           cmp    esi,DWORD PTR [eax+0x4]
005538FF 0f853bffffff                     jne    0x553840
00553905 8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
00553908 85db                             test   ebx,ebx
0055390A 7504                             jne    0x553910
0055390C 33c0                             xor    eax,eax
0055390E eb04                             jmp    0x553914
00553910 8b449f40                         mov    eax,DWORD PTR [edi+ebx*4+0x40]
00553914 89449f44                         mov    DWORD PTR [edi+ebx*4+0x44],eax
00553918 8b4204                           mov    eax,DWORD PTR [edx+0x4]
0055391B 8b08                             mov    ecx,DWORD PTR [eax]
0055391D 3bc8                             cmp    ecx,eax
0055391F 7456                             je     0x553977
00553921 8b4110                           mov    eax,DWORD PTR [ecx+0x10]
00553924 83783404                         cmp    DWORD PTR [eax+0x34],0x4
00553928 7d04                             jge    0x55392e
0055392A ff449f44                         inc    DWORD PTR [edi+ebx*4+0x44]
0055392E 80791500                         cmp    BYTE PTR [ecx+0x15],0x0
00553932 753e                             jne    0x553972
00553934 8b4108                           mov    eax,DWORD PTR [ecx+0x8]
00553937 80781500                         cmp    BYTE PTR [eax+0x15],0x0
0055393B 7516                             jne    0x553953
0055393D 8bc8                             mov    ecx,eax
0055393F 8b01                             mov    eax,DWORD PTR [ecx]
00553941 80781500                         cmp    BYTE PTR [eax+0x15],0x0
00553945 752b                             jne    0x553972
00553947 8bc8                             mov    ecx,eax
00553949 8b01                             mov    eax,DWORD PTR [ecx]
0055394B 80781500                         cmp    BYTE PTR [eax+0x15],0x0
0055394F 74f6                             je     0x553947
00553951 eb1f                             jmp    0x553972
00553953 8b4104                           mov    eax,DWORD PTR [ecx+0x4]
00553956 80781500                         cmp    BYTE PTR [eax+0x15],0x0
0055395A 7514                             jne    0x553970
0055395C 8d642400                         lea    esp,[esp+0x0]
00553960 3b4808                           cmp    ecx,DWORD PTR [eax+0x8]
00553963 750b                             jne    0x553970
00553965 8bc8                             mov    ecx,eax
00553967 8b4004                           mov    eax,DWORD PTR [eax+0x4]
0055396A 80781500                         cmp    BYTE PTR [eax+0x15],0x0
0055396E 74f0                             je     0x553960
00553970 8bc8                             mov    ecx,eax
00553972 3b4a04                           cmp    ecx,DWORD PTR [edx+0x4]
00553975 75aa                             jne    0x553921
00553977 8b4a08                           mov    ecx,DWORD PTR [edx+0x8]
0055397A 014c9f44                         add    DWORD PTR [edi+ebx*4+0x44],ecx
0055397E 43                               inc    ebx
0055397F 83fb04                           cmp    ebx,0x4
00553982 0f8c78feffff                     jl     0x553800
00553988 5f                               pop    edi
00553989 5e                               pop    esi
0055398A 5b                               pop    ebx
0055398B 8be5                             mov    esp,ebp
0055398D 5d                               pop    ebp
0055398E c20400                           ret    0x4

; F12 selective sweep; virtual +28 predicate then +10/destructor/erase
; VA 0x553740..0x5537ed raw 0x152b40 len 173 SHA256 a37664fa0059f64e96b8cff86f9b82047a0b13a1ab611c03a3cf69d536f219bc
00553740 55                               push   ebp
00553741 8bec                             mov    ebp,esp
00553743 83ec08                           sub    esp,0x8
00553746 53                               push   ebx
00553747 56                               push   esi
00553748 57                               push   edi
00553749 8d7804                           lea    edi,[eax+0x4]
0055374C c745fc04000000                   mov    DWORD PTR [ebp-0x4],0x4
00553753 33db                             xor    ebx,ebx
00553755 8b07                             mov    eax,DWORD PTR [edi]
00553757 8b30                             mov    esi,DWORD PTR [eax]
00553759 3bf0                             cmp    esi,eax
0055375B 747d                             je     0x5537da
0055375D 8d4900                           lea    ecx,[ecx+0x0]
00553760 8b4e10                           mov    ecx,DWORD PTR [esi+0x10]
00553763 8b01                             mov    eax,DWORD PTR [ecx]
00553765 8b5028                           mov    edx,DWORD PTR [eax+0x28]
00553768 ffd2                             call   edx
0055376A 85c0                             test   eax,eax
0055376C 752e                             jne    0x55379c
0055376E 8b4e10                           mov    ecx,DWORD PTR [esi+0x10]
00553771 8b01                             mov    eax,DWORD PTR [ecx]
00553773 8b5010                           mov    edx,DWORD PTR [eax+0x10]
00553776 ffd2                             call   edx
00553778 8b4e10                           mov    ecx,DWORD PTR [esi+0x10]
0055377B 3bcb                             cmp    ecx,ebx
0055377D 740b                             je     0x55378a
0055377F 8b01                             mov    eax,DWORD PTR [ecx]
00553781 8b10                             mov    edx,DWORD PTR [eax]
00553783 6a01                             push   0x1
00553785 ffd2                             call   edx
00553787 895e10                           mov    DWORD PTR [esi+0x10],ebx
0055378A 56                               push   esi
0055378B 8d45f8                           lea    eax,[ebp-0x8]
0055378E 50                               push   eax
0055378F 8d4ffc                           lea    ecx,[edi-0x4]
00553792 51                               push   ecx
00553793 e8f8302600                       call   0x7b6890
00553798 8b30                             mov    esi,DWORD PTR [eax]
0055379A eb3a                             jmp    0x5537d6
0055379C 385e15                           cmp    BYTE PTR [esi+0x15],bl
0055379F 7535                             jne    0x5537d6
005537A1 8b4608                           mov    eax,DWORD PTR [esi+0x8]
005537A4 385815                           cmp    BYTE PTR [eax+0x15],bl
005537A7 7514                             jne    0x5537bd
005537A9 8bf0                             mov    esi,eax
005537AB 8b06                             mov    eax,DWORD PTR [esi]
005537AD 385815                           cmp    BYTE PTR [eax+0x15],bl
005537B0 7524                             jne    0x5537d6
005537B2 8bf0                             mov    esi,eax
005537B4 8b06                             mov    eax,DWORD PTR [esi]
005537B6 385815                           cmp    BYTE PTR [eax+0x15],bl
005537B9 74f7                             je     0x5537b2
005537BB eb19                             jmp    0x5537d6
005537BD 8b4604                           mov    eax,DWORD PTR [esi+0x4]
005537C0 385815                           cmp    BYTE PTR [eax+0x15],bl
005537C3 750f                             jne    0x5537d4
005537C5 3b7008                           cmp    esi,DWORD PTR [eax+0x8]
005537C8 750a                             jne    0x5537d4
005537CA 8bf0                             mov    esi,eax
005537CC 8b4004                           mov    eax,DWORD PTR [eax+0x4]
005537CF 385815                           cmp    BYTE PTR [eax+0x15],bl
005537D2 74f1                             je     0x5537c5
005537D4 8bf0                             mov    esi,eax
005537D6 3b37                             cmp    esi,DWORD PTR [edi]
005537D8 7586                             jne    0x553760
005537DA 83c710                           add    edi,0x10
005537DD ff4dfc                           dec    DWORD PTR [ebp-0x4]
005537E0 0f856fffffff                     jne    0x553755
005537E6 5f                               pop    edi
005537E7 5e                               pop    esi
005537E8 5b                               pop    ebx
005537E9 8be5                             mov    esp,ebp
005537EB 5d                               pop    ebp
005537EC c3                               ret

; F13 Tutorial cancel marks tracked display lifetime zero, clears T tree, invokes sweep
; VA 0x4a9db0..0x4a9efa raw 0xa91b0 len 330 SHA256 99a168b4cc82f638fdb4b4702f8dc62513907087b990d21657276906fc77351e
004A9DB0 55                               push   ebp
004A9DB1 8bec                             mov    ebp,esp
004A9DB3 6aff                             push   0xffffffff
004A9DB5 68eece9000                       push   0x90ceee
004A9DBA 64a100000000                     mov    eax,fs:0x0
004A9DC0 50                               push   eax
004A9DC1 53                               push   ebx
004A9DC2 56                               push   esi
004A9DC3 57                               push   edi
004A9DC4 a1201fd600                       mov    eax,ds:0xd61f20
004A9DC9 33c5                             xor    eax,ebp
004A9DCB 50                               push   eax
004A9DCC 8d45f4                           lea    eax,[ebp-0xc]
004A9DCF 64a300000000                     mov    fs:0x0,eax
004A9DD5 8b5118                           mov    edx,DWORD PTR [ecx+0x18]
004A9DD8 8d5914                           lea    ebx,[ecx+0x14]
004A9DDB 8b0a                             mov    ecx,DWORD PTR [edx]
004A9DDD 3bca                             cmp    ecx,edx
004A9DDF 7455                             je     0x4a9e36
004A9DE1 8b410c                           mov    eax,DWORD PTR [ecx+0xc]
004A9DE4 c7401400000000                   mov    DWORD PTR [eax+0x14],0x0
004A9DEB 80791100                         cmp    BYTE PTR [ecx+0x11],0x0
004A9DEF 7541                             jne    0x4a9e32
004A9DF1 8b4108                           mov    eax,DWORD PTR [ecx+0x8]
004A9DF4 80781100                         cmp    BYTE PTR [eax+0x11],0x0
004A9DF8 7516                             jne    0x4a9e10
004A9DFA 8bc8                             mov    ecx,eax
004A9DFC 8b01                             mov    eax,DWORD PTR [ecx]
004A9DFE 80781100                         cmp    BYTE PTR [eax+0x11],0x0
004A9E02 752e                             jne    0x4a9e32
004A9E04 8bc8                             mov    ecx,eax
004A9E06 8b01                             mov    eax,DWORD PTR [ecx]
004A9E08 80781100                         cmp    BYTE PTR [eax+0x11],0x0
004A9E0C 74f6                             je     0x4a9e04
004A9E0E eb22                             jmp    0x4a9e32
004A9E10 8b4104                           mov    eax,DWORD PTR [ecx+0x4]
004A9E13 80781100                         cmp    BYTE PTR [eax+0x11],0x0
004A9E17 7517                             jne    0x4a9e30
004A9E19 8da42400000000                   lea    esp,[esp+0x0]
004A9E20 3b4808                           cmp    ecx,DWORD PTR [eax+0x8]
004A9E23 750b                             jne    0x4a9e30
004A9E25 8bc8                             mov    ecx,eax
004A9E27 8b4004                           mov    eax,DWORD PTR [eax+0x4]
004A9E2A 80781100                         cmp    BYTE PTR [eax+0x11],0x0
004A9E2E 74f0                             je     0x4a9e20
004A9E30 8bc8                             mov    ecx,eax
004A9E32 3bca                             cmp    ecx,edx
004A9E34 75ab                             jne    0x4a9de1
004A9E36 8b4304                           mov    eax,DWORD PTR [ebx+0x4]
004A9E39 8b7804                           mov    edi,DWORD PTR [eax+0x4]
004A9E3C 807f1100                         cmp    BYTE PTR [edi+0x11],0x0
004A9E40 8bf7                             mov    esi,edi
004A9E42 751e                             jne    0x4a9e62
004A9E44 8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
004A9E47 51                               push   ecx
004A9E48 8bcb                             mov    ecx,ebx
004A9E4A e8d1813a00                       call   0x852020
004A9E4F 8b36                             mov    esi,DWORD PTR [esi]
004A9E51 57                               push   edi
004A9E52 e8b5733e00                       call   0x89120c
004A9E57 83c404                           add    esp,0x4
004A9E5A 807e1100                         cmp    BYTE PTR [esi+0x11],0x0
004A9E5E 8bfe                             mov    edi,esi
004A9E60 74e2                             je     0x4a9e44
004A9E62 8b4304                           mov    eax,DWORD PTR [ebx+0x4]
004A9E65 894004                           mov    DWORD PTR [eax+0x4],eax
004A9E68 8b4304                           mov    eax,DWORD PTR [ebx+0x4]
004A9E6B 8900                             mov    DWORD PTR [eax],eax
004A9E6D 8b4304                           mov    eax,DWORD PTR [ebx+0x4]
004A9E70 894008                           mov    DWORD PTR [eax+0x8],eax
004A9E73 33c0                             xor    eax,eax
004A9E75 894308                           mov    DWORD PTR [ebx+0x8],eax
004A9E78 bb01000000                       mov    ebx,0x1
004A9E7D 841d5473fb00                     test   BYTE PTR ds:0xfb7354,bl
004A9E83 7559                             jne    0x4a9ede
004A9E85 091d5473fb00                     or     DWORD PTR ds:0xfb7354,ebx
004A9E8B 6820308400                       push   0x843020
004A9E90 6850405500                       push   0x554050
004A9E95 6a04                             push   0x4
004A9E97 6a10                             push   0x10
004A9E99 685873fb00                       push   0xfb7358
004A9E9E 8945fc                           mov    DWORD PTR [ebp-0x4],eax
004A9EA1 e85d813e00                       call   0x892003
004A9EA6 6800d1bc00                       push   0xbcd100
004A9EAB c7059873fb0000000000             mov    DWORD PTR ds:0xfb7398,0x0
004A9EB5 c705ac73fb0000040000             mov    DWORD PTR ds:0xfb73ac,0x400
004A9EBF c705b073fb0000030000             mov    DWORD PTR ds:0xfb73b0,0x300
004A9EC9 891db473fb00                     mov    DWORD PTR ds:0xfb73b4,ebx
004A9ECF e846843e00                       call   0x89231a
004A9ED4 83c404                           add    esp,0x4
004A9ED7 c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
004A9EDE b85873fb00                       mov    eax,0xfb7358
004A9EE3 e858980a00                       call   0x553740
004A9EE8 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004A9EEB 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004A9EF2 59                               pop    ecx
004A9EF3 5f                               pop    edi
004A9EF4 5e                               pop    esi
004A9EF5 5b                               pop    ebx
004A9EF6 8be5                             mov    esp,ebp
004A9EF8 5d                               pop    ebp
004A9EF9 c3                               ret

; F14 lifetime predicate returns object+14
; VA 0x80f010..0x80f014 raw 0x40e410 len 4 SHA256 01d3abacb68aac3537badfe563d0e21d0244fb61db1d805bcef8f455407fad96
0080F010 8b4114                           mov    eax,DWORD PTR [ecx+0x14]
0080F013 c3                               ret

; F15 Skip/Scaling selective-sweep predicate always returns1
; VA 0x87af60..0x87af66 raw 0x47a360 len 6 SHA256 2db31f4e09597946e56e859813bfdad7046d457c32332c3a882654d1e3ffdf67
0087AF60 b801000000                       mov    eax,0x1
0087AF65 c3                               ret

; F16 Skip/Scaling update virtual is ret
; VA 0x5f5d10..0x5f5d11 raw 0x1f5110 len 1 SHA256 ae3f4619b0413d70d3004b9131c3752153074e45725be13b9a148978895e359e
005F5D10 c3                               ret

; F17 texture release virtual
; VA 0x553de0..0x553dfa raw 0x1531e0 len 26 SHA256 ec2c067f34a2e5871b1eae876a76e5f8afbb765316c8f1d0d495f387898cdc61
00553DE0 56                               push   esi
00553DE1 8bf1                             mov    esi,ecx
00553DE3 8b4e44                           mov    ecx,DWORD PTR [esi+0x44]
00553DE6 85c9                             test   ecx,ecx
00553DE8 740e                             je     0x553df8
00553DEA 8b01                             mov    eax,DWORD PTR [ecx]
00553DEC 8b5008                           mov    edx,DWORD PTR [eax+0x8]
00553DEF ffd2                             call   edx
00553DF1 c7464400000000                   mov    DWORD PTR [esi+0x44],0x0
00553DF8 5e                               pop    esi
00553DF9 c3                               ret

; F18 string/object deleting destructor
; VA 0x553d50..0x553d93 raw 0x153150 len 67 SHA256 722220b9c71bba7ad0b49b0a37a7fcf38cfd590eb46651a366e74506262e1827
00553D50 55                               push   ebp
00553D51 8bec                             mov    ebp,esp
00553D53 56                               push   esi
00553D54 8bf1                             mov    esi,ecx
00553D56 837e5c10                         cmp    DWORD PTR [esi+0x5c],0x10
00553D5A 720c                             jb     0x553d68
00553D5C 8b4648                           mov    eax,DWORD PTR [esi+0x48]
00553D5F 50                               push   eax
00553D60 e8a7d43300                       call   0x89120c
00553D65 83c404                           add    esp,0x4
00553D68 33c0                             xor    eax,eax
00553D6A f6450801                         test   BYTE PTR [ebp+0x8],0x1
00553D6E c7465c0f000000                   mov    DWORD PTR [esi+0x5c],0xf
00553D75 894658                           mov    DWORD PTR [esi+0x58],eax
00553D78 884648                           mov    BYTE PTR [esi+0x48],al
00553D7B c70634ffc000                     mov    DWORD PTR [esi],0xc0ff34
00553D81 7409                             je     0x553d8c
00553D83 56                               push   esi
00553D84 e883d43300                       call   0x89120c
00553D89 83c404                           add    esp,0x4
00553D8C 8bc6                             mov    eax,esi
00553D8E 5e                               pop    esi
00553D8F 5d                               pop    ebp
00553D90 c20400                           ret    0x4

; F19 selective-sweep shutdown wrapper invokes texture release
; VA 0x553e00..0x553e0d raw 0x153200 len 13 SHA256 5db189311c8d5cc9baf9db3a1c071c2c10ffe00873767a7e9e1dee18db432f29
00553E00 8b01                             mov    eax,DWORD PTR [ecx]
00553E02 8b5008                           mov    edx,DWORD PTR [eax+0x8]
00553E05 ffd2                             call   edx
00553E07 b801000000                       mov    eax,0x1
00553E0C c3                               ret

; F20 four trees, key counter, viewport defaults and visible flag initialize
; VA 0x5533d0..0x553416 raw 0x1527d0 len 70 SHA256 476f3b5c9ca2fe05c628dc1cd0f3d433ddfe152973b65eb10ef18399ec009b42
005533D0 6820308400                       push   0x843020
005533D5 6850405500                       push   0x554050
005533DA 6a04                             push   0x4
005533DC 6a10                             push   0x10
005533DE 685873fb00                       push   0xfb7358
005533E3 e81bec3300                       call   0x892003
005533E8 c7059873fb0000000000             mov    DWORD PTR ds:0xfb7398,0x0
005533F2 c705ac73fb0000040000             mov    DWORD PTR ds:0xfb73ac,0x400
005533FC c705b073fb0000030000             mov    DWORD PTR ds:0xfb73b0,0x300
00553406 c705b473fb0001000000             mov    DWORD PTR ds:0xfb73b4,0x1
00553410 b85873fb00                       mov    eax,0xfb7358
00553415 c3                               ret

; F21 global flying manager getter
; VA 0x422ed0..0x422f32 raw 0x222d0 len 98 SHA256 54452ca1eb85a7d080ec00109d798ae3ac5e4288afe2a93e36945f751078dc0c
00422ED0 55                               push   ebp
00422ED1 8bec                             mov    ebp,esp
00422ED3 6aff                             push   0xffffffff
00422ED5 680edb9000                       push   0x90db0e
00422EDA 64a100000000                     mov    eax,fs:0x0
00422EE0 50                               push   eax
00422EE1 a1201fd600                       mov    eax,ds:0xd61f20
00422EE6 33c5                             xor    eax,ebp
00422EE8 50                               push   eax
00422EE9 8d45f4                           lea    eax,[ebp-0xc]
00422EEC 64a300000000                     mov    fs:0x0,eax
00422EF2 b801000000                       mov    eax,0x1
00422EF7 84055473fb00                     test   BYTE PTR ds:0xfb7354,al
00422EFD 751f                             jne    0x422f1e
00422EFF 09055473fb00                     or     DWORD PTR ds:0xfb7354,eax
00422F05 c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
00422F0C e8bf041300                       call   0x5533d0
00422F11 6800d1bc00                       push   0xbcd100
00422F16 e8fff34600                       call   0x89231a
00422F1B 83c404                           add    esp,0x4
00422F1E b85873fb00                       mov    eax,0xfb7358
00422F23 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
00422F26 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00422F2D 59                               pop    ecx
00422F2E 8be5                             mov    esp,ebp
00422F30 5d                               pop    ebp
00422F31 c3                               ret

; F22 draw loop checks manager visibility and per-object pass then virtual+18
; VA 0x5539a0..0x553ae8 raw 0x152da0 len 328 SHA256 032abeb2e3fea7ab65722c502e653c65e5b19f71234e6f052b845884cf0ea4ba
005539A0 55                               push   ebp
005539A1 8bec                             mov    ebp,esp
005539A3 83785c00                         cmp    DWORD PTR [eax+0x5c],0x0
005539A7 0f8437010000                     je     0x553ae4
005539AD 53                               push   ebx
005539AE 56                               push   esi
005539AF 57                               push   edi
005539B0 bb03000000                       mov    ebx,0x3
005539B5 8d7834                           lea    edi,[eax+0x34]
005539B8 eb06                             jmp    0x5539c0
005539BA 8d9b00000000                     lea    ebx,[ebx+0x0]
005539C0 8b37                             mov    esi,DWORD PTR [edi]
005539C2 3b36                             cmp    esi,DWORD PTR [esi]
005539C4 0f840d010000                     je     0x553ad7
005539CA 8d9b00000000                     lea    ebx,[ebx+0x0]
005539D0 8a5615                           mov    dl,BYTE PTR [esi+0x15]
005539D3 8bce                             mov    ecx,esi
005539D5 84d2                             test   dl,dl
005539D7 7405                             je     0x5539de
005539D9 8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
005539DC eb40                             jmp    0x553a1e
005539DE 8b06                             mov    eax,DWORD PTR [esi]
005539E0 80781500                         cmp    BYTE PTR [eax+0x15],0x0
005539E4 7518                             jne    0x5539fe
005539E6 8bc8                             mov    ecx,eax
005539E8 8b4108                           mov    eax,DWORD PTR [ecx+0x8]
005539EB 80781500                         cmp    BYTE PTR [eax+0x15],0x0
005539EF 752d                             jne    0x553a1e
005539F1 8bc8                             mov    ecx,eax
005539F3 8b4108                           mov    eax,DWORD PTR [ecx+0x8]
005539F6 80781500                         cmp    BYTE PTR [eax+0x15],0x0
005539FA 74f5                             je     0x5539f1
005539FC eb20                             jmp    0x553a1e
005539FE 8b4604                           mov    eax,DWORD PTR [esi+0x4]
00553A01 80781500                         cmp    BYTE PTR [eax+0x15],0x0
00553A05 750f                             jne    0x553a16
00553A07 3b08                             cmp    ecx,DWORD PTR [eax]
00553A09 750b                             jne    0x553a16
00553A0B 8bc8                             mov    ecx,eax
00553A0D 8b4004                           mov    eax,DWORD PTR [eax+0x4]
00553A10 80781500                         cmp    BYTE PTR [eax+0x15],0x0
00553A14 74f1                             je     0x553a07
00553A16 80791500                         cmp    BYTE PTR [ecx+0x15],0x0
00553A1A 7502                             jne    0x553a1e
00553A1C 8bc8                             mov    ecx,eax
00553A1E 8b4110                           mov    eax,DWORD PTR [ecx+0x10]
00553A21 8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
00553A24 394840                           cmp    DWORD PTR [eax+0x40],ecx
00553A27 7558                             jne    0x553a81
00553A29 8bce                             mov    ecx,esi
00553A2B 84d2                             test   dl,dl
00553A2D 7405                             je     0x553a34
00553A2F 8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
00553A32 eb43                             jmp    0x553a77
00553A34 8b06                             mov    eax,DWORD PTR [esi]
00553A36 80781500                         cmp    BYTE PTR [eax+0x15],0x0
00553A3A 7518                             jne    0x553a54
00553A3C 8bc8                             mov    ecx,eax
00553A3E 8b4108                           mov    eax,DWORD PTR [ecx+0x8]
00553A41 80781500                         cmp    BYTE PTR [eax+0x15],0x0
00553A45 7530                             jne    0x553a77
00553A47 8bc8                             mov    ecx,eax
00553A49 8b4108                           mov    eax,DWORD PTR [ecx+0x8]
00553A4C 80781500                         cmp    BYTE PTR [eax+0x15],0x0
00553A50 74f5                             je     0x553a47
00553A52 eb23                             jmp    0x553a77
00553A54 8b4604                           mov    eax,DWORD PTR [esi+0x4]
00553A57 80781500                         cmp    BYTE PTR [eax+0x15],0x0
00553A5B 7512                             jne    0x553a6f
00553A5D 8d4900                           lea    ecx,[ecx+0x0]
00553A60 3b08                             cmp    ecx,DWORD PTR [eax]
00553A62 750b                             jne    0x553a6f
00553A64 8bc8                             mov    ecx,eax
00553A66 8b4004                           mov    eax,DWORD PTR [eax+0x4]
00553A69 80781500                         cmp    BYTE PTR [eax+0x15],0x0
00553A6D 74f1                             je     0x553a60
00553A6F 80791500                         cmp    BYTE PTR [ecx+0x15],0x0
00553A73 7502                             jne    0x553a77
00553A75 8bc8                             mov    ecx,eax
00553A77 8b4910                           mov    ecx,DWORD PTR [ecx+0x10]
00553A7A 8b11                             mov    edx,DWORD PTR [ecx]
00553A7C 8b4218                           mov    eax,DWORD PTR [edx+0x18]
00553A7F ffd0                             call   eax
00553A81 807e1500                         cmp    BYTE PTR [esi+0x15],0x0
00553A85 7405                             je     0x553a8c
00553A87 8b7608                           mov    esi,DWORD PTR [esi+0x8]
00553A8A eb41                             jmp    0x553acd
00553A8C 8b06                             mov    eax,DWORD PTR [esi]
00553A8E 80781500                         cmp    BYTE PTR [eax+0x15],0x0
00553A92 7519                             jne    0x553aad
00553A94 8bf0                             mov    esi,eax
00553A96 8b4608                           mov    eax,DWORD PTR [esi+0x8]
00553A99 80781500                         cmp    BYTE PTR [eax+0x15],0x0
00553A9D 752e                             jne    0x553acd
00553A9F 90                               nop
00553AA0 8bf0                             mov    esi,eax
00553AA2 8b4608                           mov    eax,DWORD PTR [esi+0x8]
00553AA5 80781500                         cmp    BYTE PTR [eax+0x15],0x0
00553AA9 74f5                             je     0x553aa0
00553AAB eb20                             jmp    0x553acd
00553AAD 8b4604                           mov    eax,DWORD PTR [esi+0x4]
00553AB0 80781500                         cmp    BYTE PTR [eax+0x15],0x0
00553AB4 750f                             jne    0x553ac5
00553AB6 3b30                             cmp    esi,DWORD PTR [eax]
00553AB8 750b                             jne    0x553ac5
00553ABA 8bf0                             mov    esi,eax
00553ABC 8b4004                           mov    eax,DWORD PTR [eax+0x4]
00553ABF 80781500                         cmp    BYTE PTR [eax+0x15],0x0
00553AC3 74f1                             je     0x553ab6
00553AC5 807e1500                         cmp    BYTE PTR [esi+0x15],0x0
00553AC9 7502                             jne    0x553acd
00553ACB 8bf0                             mov    esi,eax
00553ACD 8b0f                             mov    ecx,DWORD PTR [edi]
00553ACF 3b31                             cmp    esi,DWORD PTR [ecx]
00553AD1 0f85f9feffff                     jne    0x5539d0
00553AD7 83ef10                           sub    edi,0x10
00553ADA 4b                               dec    ebx
00553ADB 0f89dffeffff                     jns    0x5539c0
00553AE1 5f                               pop    edi
00553AE2 5e                               pop    esi
00553AE3 5b                               pop    ebx
00553AE4 5d                               pop    ebp
00553AE5 c20400                           ret    0x4

; F23 Client render pass0 calls flying draw
; VA 0x492ee5..0x492eff raw 0x922e5 len 26 SHA256 92f4647afe32caf0fddc550b020bb8e98b16be4acc1e3352af3f8982dfc0a346
00492EE5 85c0                             test   eax,eax
00492EE7 7830                             js     0x492f19
00492EE9 e85200f9ff                       call   0x422f40
00492EEE e8ed170d00                       call   0x5646e0
00492EF3 6a00                             push   0x0
00492EF5 e8d6fff8ff                       call   0x422ed0
00492EFA e8a10a0c00                       call   0x5539a0

; F24 resize writes viewport and calls fixed position virtual
; VA 0x553c70..0x553c8a raw 0x153070 len 26 SHA256 ec38bda98cf78adc101db84ef0e98b0e198ed10657ec7bbb75739589864dcfb1
00553C70 55                               push   ebp
00553C71 8bec                             mov    ebp,esp
00553C73 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00553C76 8b550c                           mov    edx,DWORD PTR [ebp+0xc]
00553C79 894104                           mov    DWORD PTR [ecx+0x4],eax
00553C7C 8b01                             mov    eax,DWORD PTR [ecx]
00553C7E 895108                           mov    DWORD PTR [ecx+0x8],edx
00553C81 8b501c                           mov    edx,DWORD PTR [eax+0x1c]
00553C84 ffd2                             call   edx
00553C86 5d                               pop    ebp
00553C87 c20800                           ret    0x8

; U01 EmployChar closure: one numeric argument converter
; VA 0x4ac340..0x4ac39c raw 0xab740 len 92 SHA256 39e71bb8878a8270e8f1964981c321cf9fb1e91c4e77a253d86fe5d8561a4998
004AC340 55                               push   ebp
004AC341 8bec                             mov    ebp,esp
004AC343 6aff                             push   0xffffffff
004AC345 68c8839300                       push   0x9383c8
004AC34A 64a100000000                     mov    eax,fs:0x0
004AC350 50                               push   eax
004AC351 83ec0c                           sub    esp,0xc
004AC354 a1201fd600                       mov    eax,ds:0xd61f20
004AC359 33c5                             xor    eax,ebp
004AC35B 50                               push   eax
004AC35C 8d45f4                           lea    eax,[ebp-0xc]
004AC35F 64a300000000                     mov    fs:0x0,eax
004AC365 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AC368 8945e8                           mov    DWORD PTR [ebp-0x18],eax
004AC36B 33c0                             xor    eax,eax
004AC36D 8945ec                           mov    DWORD PTR [ebp-0x14],eax
004AC370 8945f0                           mov    DWORD PTR [ebp-0x10],eax
004AC373 8945fc                           mov    DWORD PTR [ebp-0x4],eax
004AC376 8b0d3818fe00                     mov    ecx,DWORD PTR ds:0xfe1838
004AC37C 51                               push   ecx
004AC37D 8d45e8                           lea    eax,[ebp-0x18]
004AC380 e8eb070000                       call   0x4acb70
004AC385 83c404                           add    esp,0x4
004AC388 b801000000                       mov    eax,0x1
004AC38D 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004AC390 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004AC397 59                               pop    ecx
004AC398 8be5                             mov    esp,ebp
004AC39A 5d                               pop    ebp
004AC39B c3                               ret

; U02 TutoMsg closure: two numeric argument converter
; VA 0x4ac3a0..0x4ac3fd raw 0xab7a0 len 93 SHA256 86ba991216fae17258fca6b56dc1890f95a021d1f7cf8f296e79452476a529d4
004AC3A0 55                               push   ebp
004AC3A1 8bec                             mov    ebp,esp
004AC3A3 6aff                             push   0xffffffff
004AC3A5 68c8839300                       push   0x9383c8
004AC3AA 64a100000000                     mov    eax,fs:0x0
004AC3B0 50                               push   eax
004AC3B1 83ec0c                           sub    esp,0xc
004AC3B4 a1201fd600                       mov    eax,ds:0xd61f20
004AC3B9 33c5                             xor    eax,ebp
004AC3BB 50                               push   eax
004AC3BC 8d45f4                           lea    eax,[ebp-0xc]
004AC3BF 64a300000000                     mov    fs:0x0,eax
004AC3C5 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004AC3C8 8945e8                           mov    DWORD PTR [ebp-0x18],eax
004AC3CB 33c0                             xor    eax,eax
004AC3CD 8945ec                           mov    DWORD PTR [ebp-0x14],eax
004AC3D0 8945f0                           mov    DWORD PTR [ebp-0x10],eax
004AC3D3 8945fc                           mov    DWORD PTR [ebp-0x4],eax
004AC3D6 8b0d3c18fe00                     mov    ecx,DWORD PTR ds:0xfe183c
004AC3DC 51                               push   ecx
004AC3DD 8d55e8                           lea    edx,[ebp-0x18]
004AC3E0 52                               push   edx
004AC3E1 e8aa090000                       call   0x4acd90
004AC3E6 83c408                           add    esp,0x8
004AC3E9 b801000000                       mov    eax,0x1
004AC3EE 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004AC3F1 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004AC3F8 59                               pop    ecx
004AC3F9 8be5                             mov    esp,ebp
004AC3FB 5d                               pop    ebp
004AC3FC c3                               ret

; U03 two-numeric conversion for fixed native member
; VA 0x4acd90..0x4ace6c raw 0xac190 len 220 SHA256 bea0a0723cf9924526c143c0672939bd5f5e7ae1287da4e8768de9a50feabd85
004ACD90 55                               push   ebp
004ACD91 8bec                             mov    ebp,esp
004ACD93 83ec24                           sub    esp,0x24
004ACD96 a10418fe00                       mov    eax,ds:0xfe1804
004ACD9B 53                               push   ebx
004ACD9C 8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
004ACD9F 8b0b                             mov    ecx,DWORD PTR [ebx]
004ACDA1 56                               push   esi
004ACDA2 8945ec                           mov    DWORD PTR [ebp-0x14],eax
004ACDA5 57                               push   edi
004ACDA6 83c8ff                           or     eax,0xffffffff
004ACDA9 e842832400                       call   0x6f50f0
004ACDAE 8b4808                           mov    ecx,DWORD PTR [eax+0x8]
004ACDB1 83f903                           cmp    ecx,0x3
004ACDB4 742a                             je     0x4acde0
004ACDB6 83f904                           cmp    ecx,0x4
004ACDB9 0f858e000000                     jne    0x4ace4d
004ACDBF 8b30                             mov    esi,DWORD PTR [eax]
004ACDC1 83c610                           add    esi,0x10
004ACDC4 8d7df0                           lea    edi,[ebp-0x10]
004ACDC7 e894a92400                       call   0x6f7760
004ACDCC 85c0                             test   eax,eax
004ACDCE 747d                             je     0x4ace4d
004ACDD0 dd45f0                           fld    QWORD PTR [ebp-0x10]
004ACDD3 c745e403000000                   mov    DWORD PTR [ebp-0x1c],0x3
004ACDDA dd5ddc                           fstp   QWORD PTR [ebp-0x24]
004ACDDD 8d45dc                           lea    eax,[ebp-0x24]
004ACDE0 dd00                             fld    QWORD PTR [eax]
004ACDE2 dd5df0                           fstp   QWORD PTR [ebp-0x10]
004ACDE5 dd45f0                           fld    QWORD PTR [ebp-0x10]
004ACDE8 db5d08                           fistp  DWORD PTR [ebp+0x8]
004ACDEB 8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
004ACDEE 894df4                           mov    DWORD PTR [ebp-0xc],ecx
004ACDF1 8b0b                             mov    ecx,DWORD PTR [ebx]
004ACDF3 b8feffffff                       mov    eax,0xfffffffe
004ACDF8 e8f3822400                       call   0x6f50f0
004ACDFD 8b4808                           mov    ecx,DWORD PTR [eax+0x8]
004ACE00 83f903                           cmp    ecx,0x3
004ACE03 7426                             je     0x4ace2b
004ACE05 83f904                           cmp    ecx,0x4
004ACE08 754c                             jne    0x4ace56
004ACE0A 8b30                             mov    esi,DWORD PTR [eax]
004ACE0C 83c610                           add    esi,0x10
004ACE0F 8d7df8                           lea    edi,[ebp-0x8]
004ACE12 e849a92400                       call   0x6f7760
004ACE17 85c0                             test   eax,eax
004ACE19 743b                             je     0x4ace56
004ACE1B dd45f8                           fld    QWORD PTR [ebp-0x8]
004ACE1E c745e403000000                   mov    DWORD PTR [ebp-0x1c],0x3
004ACE25 dd5ddc                           fstp   QWORD PTR [ebp-0x24]
004ACE28 8d45dc                           lea    eax,[ebp-0x24]
004ACE2B dd00                             fld    QWORD PTR [eax]
004ACE2D dd5de4                           fstp   QWORD PTR [ebp-0x1c]
004ACE30 dd45e4                           fld    QWORD PTR [ebp-0x1c]
004ACE33 db5dfc                           fistp  DWORD PTR [ebp-0x4]
004ACE36 8b55f4                           mov    edx,DWORD PTR [ebp-0xc]
004ACE39 8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
004ACE3C 8b4dec                           mov    ecx,DWORD PTR [ebp-0x14]
004ACE3F 52                               push   edx
004ACE40 50                               push   eax
004ACE41 ff550c                           call   DWORD PTR [ebp+0xc]
004ACE44 5f                               pop    edi
004ACE45 5e                               pop    esi
004ACE46 33c0                             xor    eax,eax
004ACE48 5b                               pop    ebx
004ACE49 8be5                             mov    esp,ebp
004ACE4B 5d                               pop    ebp
004ACE4C c3                               ret
004ACE4D c745f400000000                   mov    DWORD PTR [ebp-0xc],0x0
004ACE54 eb9b                             jmp    0x4acdf1
004ACE56 8b55f4                           mov    edx,DWORD PTR [ebp-0xc]
004ACE59 8b4dec                           mov    ecx,DWORD PTR [ebp-0x14]
004ACE5C 33c0                             xor    eax,eax
004ACE5E 52                               push   edx
004ACE5F 50                               push   eax
004ACE60 ff550c                           call   DWORD PTR [ebp+0xc]
004ACE63 5f                               pop    edi
004ACE64 5e                               pop    esi
004ACE65 33c0                             xor    eax,eax
004ACE67 5b                               pop    ebx
004ACE68 8be5                             mov    esp,ebp
004ACE6A 5d                               pop    ebp
004ACE6B c3                               ret

; U04 EmployChar posts fixed event F431F and integer payload
; VA 0x4a98d0..0x4a9948 raw 0xa8cd0 len 120 SHA256 6d9bbc7f9c9412a62acf969ac5aef63fe6427402114425d40192aa6c5f370cbe
004A98D0 55                               push   ebp
004A98D1 8bec                             mov    ebp,esp
004A98D3 6aff                             push   0xffffffff
004A98D5 686e279300                       push   0x93276e
004A98DA 64a100000000                     mov    eax,fs:0x0
004A98E0 50                               push   eax
004A98E1 a1201fd600                       mov    eax,ds:0xd61f20
004A98E6 51                               push   ecx
004A98E7 33c5                             xor    eax,ebp
004A98E9 50                               push   eax
004A98EA 8d45f4                           lea    eax,[ebp-0xc]
004A98ED 64a300000000                     mov    fs:0x0,eax
004A98F3 b801000000                       mov    eax,0x1
004A98F8 8405d4adfa00                     test   BYTE PTR ds:0xfaadd4,al
004A98FE 7526                             jne    0x4a9926
004A9900 0905d4adfa00                     or     DWORD PTR ds:0xfaadd4,eax
004A9906 c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
004A990D e86edb0d00                       call   0x587480
004A9912 68c0ccbc00                       push   0xbcccc0
004A9917 e8fe893e00                       call   0x89231a
004A991C 83c404                           add    esp,0x4
004A991F c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
004A9926 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
004A9929 50                               push   eax
004A992A 681f430f00                       push   0xf431f
004A992F e84c120e00                       call   0x58ab80
004A9934 83c408                           add    esp,0x8
004A9937 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004A993A 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004A9941 59                               pop    ecx
004A9942 8be5                             mov    esp,ebp
004A9944 5d                               pop    ebp
004A9945 c20400                           ret    0x4

; U05 TutoMsg posts fixed event F43FD and two integer payloads
; VA 0x4a9950..0x4a99cb raw 0xa8d50 len 123 SHA256 ff72ad9cead36250a8407584b8efd19067ee4ac1b77fa0c4866cd8d733bfac49
004A9950 55                               push   ebp
004A9951 8bec                             mov    ebp,esp
004A9953 6aff                             push   0xffffffff
004A9955 689e4d9200                       push   0x924d9e
004A995A 64a100000000                     mov    eax,fs:0x0
004A9960 50                               push   eax
004A9961 a1201fd600                       mov    eax,ds:0xd61f20
004A9966 33c5                             xor    eax,ebp
004A9968 50                               push   eax
004A9969 8d45f4                           lea    eax,[ebp-0xc]
004A996C 64a300000000                     mov    fs:0x0,eax
004A9972 b801000000                       mov    eax,0x1
004A9977 8405d4adfa00                     test   BYTE PTR ds:0xfaadd4,al
004A997D 7526                             jne    0x4a99a5
004A997F 0905d4adfa00                     or     DWORD PTR ds:0xfaadd4,eax
004A9985 c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
004A998C e8efda0d00                       call   0x587480
004A9991 68c0ccbc00                       push   0xbcccc0
004A9996 e87f893e00                       call   0x89231a
004A999B 83c404                           add    esp,0x4
004A999E c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
004A99A5 8b450c                           mov    eax,DWORD PTR [ebp+0xc]
004A99A8 8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
004A99AB 50                               push   eax
004A99AC 51                               push   ecx
004A99AD 68fd430f00                       push   0xf43fd
004A99B2 e879120e00                       call   0x58ac30
004A99B7 83c40c                           add    esp,0xc
004A99BA 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004A99BD 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004A99C4 59                               pop    ecx
004A99C5 8be5                             mov    esp,ebp
004A99C7 5d                               pop    ebp
004A99C8 c20800                           ret    0x8

; U06 FXUIEventI1 allocation and queue insertion
; VA 0x58ab80..0x58ac2d raw 0x189f80 len 173 SHA256 2d2645de4c5df452d6832e9f2844e3a454c1d08d8eb8fd11acbd9a0cab1f4071
0058AB80 55                               push   ebp
0058AB81 8bec                             mov    ebp,esp
0058AB83 6aff                             push   0xffffffff
0058AB85 68ee699100                       push   0x9169ee
0058AB8A 64a100000000                     mov    eax,fs:0x0
0058AB90 50                               push   eax
0058AB91 51                               push   ecx
0058AB92 56                               push   esi
0058AB93 a1201fd600                       mov    eax,ds:0xd61f20
0058AB98 33c5                             xor    eax,ebp
0058AB9A 50                               push   eax
0058AB9B 8d45f4                           lea    eax,[ebp-0xc]
0058AB9E 64a300000000                     mov    fs:0x0,eax
0058ABA4 6a18                             push   0x18
0058ABA6 e8bd663000                       call   0x891268
0058ABAB 33c9                             xor    ecx,ecx
0058ABAD 83c404                           add    esp,0x4
0058ABB0 3bc1                             cmp    eax,ecx
0058ABB2 7427                             je     0x58abdb
0058ABB4 8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0058ABB7 895010                           mov    DWORD PTR [eax+0x10],edx
0058ABBA 8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0058ABBD c74004ffffffff                   mov    DWORD PTR [eax+0x4],0xffffffff
0058ABC4 c74008ffffffff                   mov    DWORD PTR [eax+0x8],0xffffffff
0058ABCB 89480c                           mov    DWORD PTR [eax+0xc],ecx
0058ABCE c700ac67c400                     mov    DWORD PTR [eax],0xc467ac
0058ABD4 895014                           mov    DWORD PTR [eax+0x14],edx
0058ABD7 8bf0                             mov    esi,eax
0058ABD9 eb02                             jmp    0x58abdd
0058ABDB 33f6                             xor    esi,esi
0058ABDD b801000000                       mov    eax,0x1
0058ABE2 8405d0adfa00                     test   BYTE PTR ds:0xfaadd0,al
0058ABE8 7522                             jne    0x58ac0c
0058ABEA 0905d0adfa00                     or     DWORD PTR ds:0xfaadd0,eax
0058ABF0 894dfc                           mov    DWORD PTR [ebp-0x4],ecx
0058ABF3 e8982d1c00                       call   0x74d990
0058ABF8 6870ccbc00                       push   0xbccc70
0058ABFD e818773000                       call   0x89231a
0058AC02 83c404                           add    esp,0x4
0058AC05 c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0058AC0C 8d45f0                           lea    eax,[ebp-0x10]
0058AC0F 8975f0                           mov    DWORD PTR [ebp-0x10],esi
0058AC12 50                               push   eax
0058AC13 be6c5cf900                       mov    esi,0xf95c6c
0058AC18 e843962700                       call   0x804260
0058AC1D 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0058AC20 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0058AC27 59                               pop    ecx
0058AC28 5e                               pop    esi
0058AC29 8be5                             mov    esp,ebp
0058AC2B 5d                               pop    ebp
0058AC2C c3                               ret

; U07 FXUIEventI2 allocation and queue insertion
; VA 0x58ac30..0x58ace5 raw 0x18a030 len 181 SHA256 d41861fd4d78af40f4d73cc06cd2b0fa784f4acd1a61ebb966620db924d701bf
0058AC30 55                               push   ebp
0058AC31 8bec                             mov    ebp,esp
0058AC33 6aff                             push   0xffffffff
0058AC35 68eef89100                       push   0x91f8ee
0058AC3A 64a100000000                     mov    eax,fs:0x0
0058AC40 50                               push   eax
0058AC41 83ec08                           sub    esp,0x8
0058AC44 56                               push   esi
0058AC45 a1201fd600                       mov    eax,ds:0xd61f20
0058AC4A 33c5                             xor    eax,ebp
0058AC4C 50                               push   eax
0058AC4D 8d45f4                           lea    eax,[ebp-0xc]
0058AC50 64a300000000                     mov    fs:0x0,eax
0058AC56 6a1c                             push   0x1c
0058AC58 e80b663000                       call   0x891268
0058AC5D 33c9                             xor    ecx,ecx
0058AC5F 83c404                           add    esp,0x4
0058AC62 3bc1                             cmp    eax,ecx
0058AC64 742d                             je     0x58ac93
0058AC66 8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0058AC69 895010                           mov    DWORD PTR [eax+0x10],edx
0058AC6C 8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0058AC6F 895014                           mov    DWORD PTR [eax+0x14],edx
0058AC72 8b5510                           mov    edx,DWORD PTR [ebp+0x10]
0058AC75 c74004ffffffff                   mov    DWORD PTR [eax+0x4],0xffffffff
0058AC7C c74008ffffffff                   mov    DWORD PTR [eax+0x8],0xffffffff
0058AC83 89480c                           mov    DWORD PTR [eax+0xc],ecx
0058AC86 c700cc7bc400                     mov    DWORD PTR [eax],0xc47bcc
0058AC8C 895018                           mov    DWORD PTR [eax+0x18],edx
0058AC8F 8bf0                             mov    esi,eax
0058AC91 eb02                             jmp    0x58ac95
0058AC93 33f6                             xor    esi,esi
0058AC95 b801000000                       mov    eax,0x1
0058AC9A 8405d0adfa00                     test   BYTE PTR ds:0xfaadd0,al
0058ACA0 7522                             jne    0x58acc4
0058ACA2 0905d0adfa00                     or     DWORD PTR ds:0xfaadd0,eax
0058ACA8 894dfc                           mov    DWORD PTR [ebp-0x4],ecx
0058ACAB e8e02c1c00                       call   0x74d990
0058ACB0 6870ccbc00                       push   0xbccc70
0058ACB5 e860763000                       call   0x89231a
0058ACBA 83c404                           add    esp,0x4
0058ACBD c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0058ACC4 8d45f0                           lea    eax,[ebp-0x10]
0058ACC7 8975f0                           mov    DWORD PTR [ebp-0x10],esi
0058ACCA 50                               push   eax
0058ACCB be6c5cf900                       mov    esi,0xf95c6c
0058ACD0 e88b952700                       call   0x804260
0058ACD5 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0058ACD8 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0058ACDF 59                               pop    ecx
0058ACE0 5e                               pop    esi
0058ACE1 8be5                             mov    esp,ebp
0058ACE3 5d                               pop    ebp
0058ACE4 c3                               ret

; U08 page router: F431F -> +18C, F43FD -> +198
; VA 0x595d20..0x595d9d raw 0x195120 len 125 SHA256 921b4dd057cd320115685a183a87ab200062a8429cb73923e250f0e3920cfb1a
00595D20 55                               push   ebp
00595D21 8bec                             mov    ebp,esp
00595D23 8b5508                           mov    edx,DWORD PTR [ebp+0x8]
00595D26 8b4210                           mov    eax,DWORD PTR [edx+0x10]
00595D29 3dd7420f00                       cmp    eax,0xf42d7
00595D2E 7616                             jbe    0x595d46
00595D30 3d4a430f00                       cmp    eax,0xf434a
00595D35 7314                             jae    0x595d4b
00595D37 8b01                             mov    eax,DWORD PTR [ecx]
00595D39 52                               push   edx
00595D3A 8b908c010000                     mov    edx,DWORD PTR [eax+0x18c]
00595D40 ffd2                             call   edx
00595D42 5d                               pop    ebp
00595D43 c20400                           ret    0x4
00595D46 3d4a430f00                       cmp    eax,0xf434a
00595D4B 7616                             jbe    0x595d63
00595D4D 3d5c430f00                       cmp    eax,0xf435c
00595D52 730f                             jae    0x595d63
00595D54 8b01                             mov    eax,DWORD PTR [ecx]
00595D56 52                               push   edx
00595D57 8b9090010000                     mov    edx,DWORD PTR [eax+0x190]
00595D5D ffd2                             call   edx
00595D5F 5d                               pop    ebp
00595D60 c20400                           ret    0x4
00595D63 3d40420f00                       cmp    eax,0xf4240
00595D68 7616                             jbe    0x595d80
00595D6A 3dd7420f00                       cmp    eax,0xf42d7
00595D6F 730f                             jae    0x595d80
00595D71 8b01                             mov    eax,DWORD PTR [ecx]
00595D73 52                               push   edx
00595D74 8b9094010000                     mov    edx,DWORD PTR [eax+0x194]
00595D7A ffd2                             call   edx
00595D7C 5d                               pop    ebp
00595D7D c20400                           ret    0x4
00595D80 3d5c430f00                       cmp    eax,0xf435c
00595D85 7612                             jbe    0x595d99
00595D87 3d42440f00                       cmp    eax,0xf4442
00595D8C 730b                             jae    0x595d99
00595D8E 8b01                             mov    eax,DWORD PTR [ecx]
00595D90 52                               push   edx
00595D91 8b9098010000                     mov    edx,DWORD PTR [eax+0x198]
00595D97 ffd2                             call   edx
00595D99 5d                               pop    ebp
00595D9A c20400                           ret    0x4

; U09 ordinary +18C delegates base; only special event F42F1
; VA 0x5ac590..0x5ac5b4 raw 0x1ab990 len 36 SHA256 6a1358789890eb3e5dde348c64bd8fda4aa29857fec686f1b7dfea7a78e50584
005AC590 55                               push   ebp
005AC591 8bec                             mov    ebp,esp
005AC593 56                               push   esi
005AC594 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
005AC597 57                               push   edi
005AC598 56                               push   esi
005AC599 8bf9                             mov    edi,ecx
005AC59B e880eefeff                       call   0x59b420
005AC5A0 817e10f1420f00                   cmp    DWORD PTR [esi+0x10],0xf42f1
005AC5A7 7505                             jne    0x5ac5ae
005AC5A9 e8a2020000                       call   0x5ac850
005AC5AE 5f                               pop    edi
005AC5AF 5e                               pop    esi
005AC5B0 5d                               pop    ebp
005AC5B1 c20400                           ret    0x4

; U10 base +18C switch selector
; VA 0x59b420..0x59b46b raw 0x19a820 len 75 SHA256 ab974409a9be5ca8e7dba9ffea1980e5661eab8d4f2e39a1a4dca661ba988560
0059B420 55                               push   ebp
0059B421 8bec                             mov    ebp,esp
0059B423 53                               push   ebx
0059B424 56                               push   esi
0059B425 57                               push   edi
0059B426 8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0059B429 8b4710                           mov    eax,DWORD PTR [edi+0x10]
0059B42C 2d1d430f00                       sub    eax,0xf431d
0059B431 8bd9                             mov    ebx,ecx
0059B433 740e                             je     0x59b443
0059B435 83e80b                           sub    eax,0xb
0059B438 7512                             jne    0x59b44c
0059B43A 8bf3                             mov    esi,ebx
0059B43C e88fa30000                       call   0x5a57d0
0059B441 eb09                             jmp    0x59b44c
0059B443 8bcf                             mov    ecx,edi
0059B445 8bd3                             mov    edx,ebx
0059B447 e894a50000                       call   0x5a59e0
0059B44C 8b4710                           mov    eax,DWORD PTR [edi+0x10]
0059B44F 0528bdf0ff                       add    eax,0xfff0bd28
0059B454 83f868                           cmp    eax,0x68
0059B457 0f8738030000                     ja     0x59b795
0059B45D 0fb68054b85900                   movzx  eax,BYTE PTR [eax+0x59b854]
0059B464 ff24859cb75900                   jmp    DWORD PTR [eax*4+0x59b79c]

; U11 base +18C selected default epilogue
; VA 0x59b795..0x59b79c raw 0x19ab95 len 7 SHA256 8e28d73e6a5d141175d2ca376427172fa08a33c5564da56df61ddb67248fc296
0059B795 5f                               pop    edi
0059B796 5e                               pop    esi
0059B797 5b                               pop    ebx
0059B798 5d                               pop    ebp
0059B799 c20400                           ret    0x4

; U12 Mission +198 delegates base; other finite event keys
; VA 0x5ad630..0x5ad68e raw 0x1aca30 len 94 SHA256 17e0ce3e303ef36fd9d52899d48f5f8bc582fb2a4b932bdffafb7f4e378b193c
005AD630 55                               push   ebp
005AD631 8bec                             mov    ebp,esp
005AD633 56                               push   esi
005AD634 57                               push   edi
005AD635 8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
005AD638 57                               push   edi
005AD639 8bf1                             mov    esi,ecx
005AD63B e840e7feff                       call   0x59bd80
005AD640 817f1006440f00                   cmp    DWORD PTR [edi+0x10],0xf4406
005AD647 7506                             jne    0x5ad64f
005AD649 56                               push   esi
005AD64A e891f0ffff                       call   0x5ac6e0
005AD64F 8b4710                           mov    eax,DWORD PTR [edi+0x10]
005AD652 2d63430f00                       sub    eax,0xf4363
005AD657 742a                             je     0x5ad683
005AD659 83e83e                           sub    eax,0x3e
005AD65C 7418                             je     0x5ad676
005AD65E 2d86000000                       sub    eax,0x86
005AD663 7523                             jne    0x5ad688
005AD665 8b8e48020000                     mov    ecx,DWORD PTR [esi+0x248]
005AD66B e8d014ebff                       call   0x45eb40
005AD670 5f                               pop    edi
005AD671 5e                               pop    esi
005AD672 5d                               pop    ebp
005AD673 c20400                           ret    0x4
005AD676 8bf7                             mov    esi,edi
005AD678 e8a3faffff                       call   0x5ad120
005AD67D 5f                               pop    edi
005AD67E 5e                               pop    esi
005AD67F 5d                               pop    ebp
005AD680 c20400                           ret    0x4
005AD683 e838feffff                       call   0x5ad4c0
005AD688 5f                               pop    edi
005AD689 5e                               pop    esi
005AD68A 5d                               pop    ebp
005AD68B c20400                           ret    0x4

; U13 Scenario +198 delegates base; other finite event keys
; VA 0x5afe70..0x5afeae raw 0x1af270 len 62 SHA256 b8c2f624756ec75e5ddb37e99e042b3cb0f277401ef245a72901504dc673f142
005AFE70 55                               push   ebp
005AFE71 8bec                             mov    ebp,esp
005AFE73 56                               push   esi
005AFE74 57                               push   edi
005AFE75 8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
005AFE78 57                               push   edi
005AFE79 8bf1                             mov    esi,ecx
005AFE7B e800bffeff                       call   0x59bd80
005AFE80 817f1006440f00                   cmp    DWORD PTR [edi+0x10],0xf4406
005AFE87 7506                             jne    0x5afe8f
005AFE89 56                               push   esi
005AFE8A e851c8ffff                       call   0x5ac6e0
005AFE8F 817f1001440f00                   cmp    DWORD PTR [edi+0x10],0xf4401
005AFE96 7510                             jne    0x5afea8
005AFE98 8b4714                           mov    eax,DWORD PTR [edi+0x14]
005AFE9B 8b8e2c020000                     mov    ecx,DWORD PTR [esi+0x22c]
005AFEA1 50                               push   eax
005AFEA2 51                               push   ecx
005AFEA3 e8e8a91000                       call   0x6ba890
005AFEA8 5f                               pop    edi
005AFEA9 5e                               pop    esi
005AFEAA 5d                               pop    ebp
005AFEAB c20400                           ret    0x4

; U14 base +198 calls shared handler and dispatches key
; VA 0x59bd80..0x59bdb6 raw 0x19b180 len 54 SHA256 1a6b855d60818d2d0cae0e9a2e85fa52fed539f01fb65dfd9558756fedd4a51b
0059BD80 55                               push   ebp
0059BD81 8bec                             mov    ebp,esp
0059BD83 83e4f8                           and    esp,0xfffffff8
0059BD86 51                               push   ecx
0059BD87 53                               push   ebx
0059BD88 56                               push   esi
0059BD89 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0059BD8C 57                               push   edi
0059BD8D 56                               push   esi
0059BD8E 8bf9                             mov    edi,ecx
0059BD90 e87b850000                       call   0x5a4310
0059BD95 8b4610                           mov    eax,DWORD PTR [esi+0x10]
0059BD98 059fbcf0ff                       add    eax,0xfff0bc9f
0059BD9D 3dd8000000                       cmp    eax,0xd8
0059BDA2 0f87af020000                     ja     0x59c057
0059BDA8 0fb680ccc05900                   movzx  eax,BYTE PTR [eax+0x59c0cc]
0059BDAF ff248560c05900                   jmp    DWORD PTR [eax*4+0x59c060]

; U15 base +198 selected default epilogue
; VA 0x59c057..0x59c060 raw 0x19b457 len 9 SHA256 7fbbb93cd553dee0aafd8869520a1bc81fdb80ae47e4f0ec343cae1ae63c6f5f
0059C057 5f                               pop    edi
0059C058 5e                               pop    esi
0059C059 5b                               pop    ebx
0059C05A 8be5                             mov    esp,ebp
0059C05C 5d                               pop    ebp
0059C05D c20400                           ret    0x4

; U16 shared handler: F43FD first switch default and second out-of-range
; VA 0x5a4310..0x5a43f7 raw 0x1a3710 len 231 SHA256 2bea02abe749fdcaa7c16a4b18e68cfdd917ce652eb023e9670e7ea6075d713c
005A4310 55                               push   ebp
005A4311 8bec                             mov    ebp,esp
005A4313 51                               push   ecx
005A4314 56                               push   esi
005A4315 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
005A4318 8b4610                           mov    eax,DWORD PTR [esi+0x10]
005A431B 0525bcf0ff                       add    eax,0xfff0bc25
005A4320 57                               push   edi
005A4321 8bf9                             mov    edi,ecx
005A4323 83f824                           cmp    eax,0x24
005A4326 772f                             ja     0x5a4357
005A4328 0fb6800c445a00                   movzx  eax,BYTE PTR [eax+0x5a440c]
005A432F ff2485f8435a00                   jmp    DWORD PTR [eax*4+0x5a43f8]
005A4336 e88523ffff                       call   0x5966c0
005A433B eb1a                             jmp    0x5a4357
005A433D 57                               push   edi
005A433E e8ed24ffff                       call   0x596830
005A4343 eb12                             jmp    0x5a4357
005A4345 6a00                             push   0x0
005A4347 57                               push   edi
005A4348 e88331ffff                       call   0x5974d0
005A434D eb08                             jmp    0x5a4357
005A434F 57                               push   edi
005A4350 8bc6                             mov    eax,esi
005A4352 e87935ffff                       call   0x5978d0
005A4357 8b4610                           mov    eax,DWORD PTR [esi+0x10]
005A435A 059abcf0ff                       add    eax,0xfff0bc9a
005A435F 3d80000000                       cmp    eax,0x80
005A4364 0f8786000000                     ja     0x5a43f0
005A436A 0fb6885c445a00                   movzx  ecx,BYTE PTR [eax+0x5a445c]
005A4371 ff248d34445a00                   jmp    DWORD PTR [ecx*4+0x5a4434]
005A4378 8bcf                             mov    ecx,edi
005A437A e891faffff                       call   0x5a3e10
005A437F 5f                               pop    edi
005A4380 5e                               pop    esi
005A4381 59                               pop    ecx
005A4382 5d                               pop    ebp
005A4383 c20400                           ret    0x4
005A4386 8bcf                             mov    ecx,edi
005A4388 e8b30e0000                       call   0x5a5240
005A438D 5f                               pop    edi
005A438E 5e                               pop    esi
005A438F 59                               pop    ecx
005A4390 5d                               pop    ebp
005A4391 c20400                           ret    0x4
005A4394 57                               push   edi
005A4395 8bce                             mov    ecx,esi
005A4397 e804fdffff                       call   0x5a40a0
005A439C 5f                               pop    edi
005A439D 5e                               pop    esi
005A439E 59                               pop    ecx
005A439F 5d                               pop    ebp
005A43A0 c20400                           ret    0x4
005A43A3 57                               push   edi
005A43A4 8bce                             mov    ecx,esi
005A43A6 e8f5fdffff                       call   0x5a41a0
005A43AB 5f                               pop    edi
005A43AC 5e                               pop    esi
005A43AD 59                               pop    ecx
005A43AE 5d                               pop    ebp
005A43AF c20400                           ret    0x4
005A43B2 8bf7                             mov    esi,edi
005A43B4 e887050000                       call   0x5a4940
005A43B9 5f                               pop    edi
005A43BA 5e                               pop    esi
005A43BB 59                               pop    ecx
005A43BC 5d                               pop    ebp
005A43BD c20400                           ret    0x4
005A43C0 8bf7                             mov    esi,edi
005A43C2 e819060000                       call   0x5a49e0
005A43C7 5f                               pop    edi
005A43C8 5e                               pop    esi
005A43C9 59                               pop    ecx
005A43CA 5d                               pop    ebp
005A43CB c20400                           ret    0x4
005A43CE 8bcf                             mov    ecx,edi
005A43D0 e81b070000                       call   0x5a4af0
005A43D5 5f                               pop    edi
005A43D6 5e                               pop    esi
005A43D7 59                               pop    ecx
005A43D8 5d                               pop    ebp
005A43D9 c20400                           ret    0x4
005A43DC 8bf7                             mov    esi,edi
005A43DE e80dfbffff                       call   0x5a3ef0
005A43E3 5f                               pop    edi
005A43E4 5e                               pop    esi
005A43E5 59                               pop    ecx
005A43E6 5d                               pop    ebp
005A43E7 c20400                           ret    0x4
005A43EA 57                               push   edi
005A43EB e8b0160000                       call   0x5a5aa0
005A43F0 5f                               pop    edi
005A43F1 5e                               pop    esi
005A43F2 59                               pop    ecx
005A43F3 5d                               pop    ebp
005A43F4 c20400                           ret    0x4

; U17 ScenarioResult positive F431F UI route
; VA 0x5aae80..0x5aaf37 raw 0x1aa280 len 183 SHA256 e178ffbda4ba0ed135905cbd2d14703ed4ffa9581c528d57c9ae67e3484e0369
005AAE80 55                               push   ebp
005AAE81 8bec                             mov    ebp,esp
005AAE83 56                               push   esi
005AAE84 57                               push   edi
005AAE85 8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
005AAE88 8b4710                           mov    eax,DWORD PTR [edi+0x10]
005AAE8B 2d1d430f00                       sub    eax,0xf431d
005AAE90 8bf1                             mov    esi,ecx
005AAE92 740c                             je     0x5aaea0
005AAE94 83e80b                           sub    eax,0xb
005AAE97 7510                             jne    0x5aaea9
005AAE99 e832a9ffff                       call   0x5a57d0
005AAE9E eb09                             jmp    0x5aaea9
005AAEA0 8bcf                             mov    ecx,edi
005AAEA2 8bd6                             mov    edx,esi
005AAEA4 e837abffff                       call   0x5a59e0
005AAEA9 817f101f430f00                   cmp    DWORD PTR [edi+0x10],0xf431f
005AAEB0 757f                             jne    0x5aaf31
005AAEB2 837f1400                         cmp    DWORD PTR [edi+0x14],0x0
005AAEB6 7432                             je     0x5aaeea
005AAEB8 8b8e64010000                     mov    ecx,DWORD PTR [esi+0x164]
005AAEBE 8b01                             mov    eax,DWORD PTR [ecx]
005AAEC0 8b90d4000000                     mov    edx,DWORD PTR [eax+0xd4]
005AAEC6 ffd2                             call   edx
005AAEC8 8b8668010000                     mov    eax,DWORD PTR [esi+0x168]
005AAECE 8b4f14                           mov    ecx,DWORD PTR [edi+0x14]
005AAED1 50                               push   eax
005AAED2 e839441100                       call   0x6bf310
005AAED7 8b8e68010000                     mov    ecx,DWORD PTR [esi+0x168]
005AAEDD 51                               push   ecx
005AAEDE 56                               push   esi
005AAEDF e81cbffeff                       call   0x596e00
005AAEE4 5f                               pop    edi
005AAEE5 5e                               pop    esi
005AAEE6 5d                               pop    ebp
005AAEE7 c20400                           ret    0x4
005AAEEA b801000000                       mov    eax,0x1
005AAEEF 84051413fb00                     test   BYTE PTR ds:0xfb1314,al
005AAEF5 7513                             jne    0x5aaf0a
005AAEF7 09051413fb00                     or     DWORD PTR ds:0xfb1314,eax
005AAEFD 6810cfbc00                       push   0xbccf10
005AAF02 e813742e00                       call   0x89231a
005AAF07 83c404                           add    esp,0x4
005AAF0A 833d98a7fb0000                   cmp    DWORD PTR ds:0xfba798,0x0
005AAF11 ba33000000                       mov    edx,0x33
005AAF16 6689550a                         mov    WORD PTR [ebp+0xa],dx
005AAF1A 7515                             jne    0x5aaf31
005AAF1C 8b0d54a8fb00                     mov    ecx,DWORD PTR ds:0xfba854
005AAF22 8b01                             mov    eax,DWORD PTR [ecx]
005AAF24 8b4010                           mov    eax,DWORD PTR [eax+0x10]
005AAF27 6a02                             push   0x2
005AAF29 8d550a                           lea    edx,[ebp+0xa]
005AAF2C 52                               push   edx
005AAF2D 6a00                             push   0x0
005AAF2F ffd0                             call   eax
005AAF31 5f                               pop    edi
005AAF32 5e                               pop    esi
005AAF33 5d                               pop    ebp
005AAF34 c20400                           ret    0x4

; U18 Tutorial positive F431F page route
; VA 0x5c32d0..0x5c3346 raw 0x1c26d0 len 118 SHA256 b45dd5cc8b0972f75deaa6175fcf1c5ab95bde4ce2b082c9e2f817a27489284a
005C32D0 55                               push   ebp
005C32D1 8bec                             mov    ebp,esp
005C32D3 56                               push   esi
005C32D4 57                               push   edi
005C32D5 8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
005C32D8 57                               push   edi
005C32D9 8bf1                             mov    esi,ecx
005C32DB e84081fdff                       call   0x59b420
005C32E0 8b4710                           mov    eax,DWORD PTR [edi+0x10]
005C32E3 2ddb420f00                       sub    eax,0xf42db
005C32E8 7424                             je     0x5c330e
005C32EA 83e802                           sub    eax,0x2
005C32ED 7412                             je     0x5c3301
005C32EF 83e842                           sub    eax,0x42
005C32F2 754c                             jne    0x5c3340
005C32F4 8bc7                             mov    eax,edi
005C32F6 e8d5030000                       call   0x5c36d0
005C32FB 5f                               pop    edi
005C32FC 5e                               pop    esi
005C32FD 5d                               pop    ebp
005C32FE c20400                           ret    0x4
005C3301 8bce                             mov    ecx,esi
005C3303 e8a8010000                       call   0x5c34b0
005C3308 5f                               pop    edi
005C3309 5e                               pop    esi
005C330A 5d                               pop    ebp
005C330B c20400                           ret    0x4
005C330E 8b8e20020000                     mov    ecx,DWORD PTR [esi+0x220]
005C3314 8b4128                           mov    eax,DWORD PTR [ecx+0x28]
005C3317 c1e808                           shr    eax,0x8
005C331A a801                             test   al,0x1
005C331C 741b                             je     0x5c3339
005C331E 8b5128                           mov    edx,DWORD PTR [ecx+0x28]
005C3321 c1ea08                           shr    edx,0x8
005C3324 f6c201                           test   dl,0x1
005C3327 7417                             je     0x5c3340
005C3329 8b01                             mov    eax,DWORD PTR [ecx]
005C332B 8b90d4000000                     mov    edx,DWORD PTR [eax+0xd4]
005C3331 ffd2                             call   edx
005C3333 5f                               pop    edi
005C3334 5e                               pop    esi
005C3335 5d                               pop    ebp
005C3336 c20400                           ret    0x4
005C3339 51                               push   ecx
005C333A 56                               push   esi
005C333B e8c03afdff                       call   0x596e00
005C3340 5f                               pop    edi
005C3341 5e                               pop    esi
005C3342 5d                               pop    ebp
005C3343 c20400                           ret    0x4

; U19 Tutorial F431F displays character panel, then fixed TutoMsg payload
; VA 0x5c36d0..0x5c3745 raw 0x1c2ad0 len 117 SHA256 49013106f9e5558c31af5644d816f76d79ec7334d1f2f0a4cdbf3fbedd689322
005C36D0 8b4814                           mov    ecx,DWORD PTR [eax+0x14]
005C36D3 85c9                             test   ecx,ecx
005C36D5 746d                             je     0x5c3744
005C36D7 8b9630020000                     mov    edx,DWORD PTR [esi+0x230]
005C36DD 52                               push   edx
005C36DE e82dbc0f00                       call   0x6bf310
005C36E3 8b8630020000                     mov    eax,DWORD PTR [esi+0x230]
005C36E9 50                               push   eax
005C36EA 56                               push   esi
005C36EB e81037fdff                       call   0x596e00
005C36F0 6a1c                             push   0x1c
005C36F2 e871db2c00                       call   0x891268
005C36F7 83c404                           add    esp,0x4
005C36FA 85c0                             test   eax,eax
005C36FC 7438                             je     0x5c3736
005C36FE 83c9ff                           or     ecx,0xffffffff
005C3701 894804                           mov    DWORD PTR [eax+0x4],ecx
005C3704 894808                           mov    DWORD PTR [eax+0x8],ecx
005C3707 c7400c00000000                   mov    DWORD PTR [eax+0xc],0x0
005C370E c74010fd430f00                   mov    DWORD PTR [eax+0x10],0xf43fd
005C3715 c700cc7bc400                     mov    DWORD PTR [eax],0xc47bcc
005C371B c7401400000000                   mov    DWORD PTR [eax+0x14],0x0
005C3722 c740180a000000                   mov    DWORD PTR [eax+0x18],0xa
005C3729 8b8e28020000                     mov    ecx,DWORD PTR [esi+0x228]
005C372F 50                               push   eax
005C3730 e83bca0f00                       call   0x6c0170
005C3735 c3                               ret
005C3736 8b8e28020000                     mov    ecx,DWORD PTR [esi+0x228]
005C373C 33c0                             xor    eax,eax
005C373E 50                               push   eax
005C373F e82cca0f00                       call   0x6c0170
005C3744 c3                               ret

; U20 Tutorial positive F43FD route to TutoMsg handler
; VA 0x5c3370..0x5c33ac raw 0x1c2770 len 60 SHA256 ad0f4a37891aac57f283d3a5b80f4b252fee210362729c159b15a8e18a5767ab
005C3370 55                               push   ebp
005C3371 8bec                             mov    ebp,esp
005C3373 56                               push   esi
005C3374 57                               push   edi
005C3375 8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
005C3378 57                               push   edi
005C3379 8bf1                             mov    esi,ecx
005C337B e8008afdff                       call   0x59bd80
005C3380 8b4710                           mov    eax,DWORD PTR [edi+0x10]
005C3383 2dda430f00                       sub    eax,0xf43da
005C3388 7417                             je     0x5c33a1
005C338A 83e823                           sub    eax,0x23
005C338D 7517                             jne    0x5c33a6
005C338F 8b8e28020000                     mov    ecx,DWORD PTR [esi+0x228]
005C3395 57                               push   edi
005C3396 e8d5cd0f00                       call   0x6c0170
005C339B 5f                               pop    edi
005C339C 5e                               pop    esi
005C339D 5d                               pop    ebp
005C339E c20400                           ret    0x4
005C33A1 e86a020000                       call   0x5c3610
005C33A6 5f                               pop    edi
005C33A7 5e                               pop    esi
005C33A8 5d                               pop    ebp
005C33A9 c20400                           ret    0x4

; U21 TutorialField positive F43FD route
; VA 0x5affb0..0x5affdb raw 0x1af3b0 len 43 SHA256 fe96bddec664f571de5eac36016d645d2c352c0fc2234828151bbe9e8839f63a
005AFFB0 55                               push   ebp
005AFFB1 8bec                             mov    ebp,esp
005AFFB3 56                               push   esi
005AFFB4 57                               push   edi
005AFFB5 8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
005AFFB8 57                               push   edi
005AFFB9 8bf1                             mov    esi,ecx
005AFFBB e8c0bdfeff                       call   0x59bd80
005AFFC0 817f10fd430f00                   cmp    DWORD PTR [edi+0x10],0xf43fd
005AFFC7 750c                             jne    0x5affd5
005AFFC9 8b8e28020000                     mov    ecx,DWORD PTR [esi+0x228]
005AFFCF 57                               push   edi
005AFFD0 e89b011100                       call   0x6c0170
005AFFD5 5f                               pop    edi
005AFFD6 5e                               pop    esi
005AFFD7 5d                               pop    ebp
005AFFD8 c20400                           ret    0x4

; U22 SetUIPage uses fixed page15, not arbitrary callback owner
; VA 0x4a9ae0..0x4a9b6a raw 0xa8ee0 len 138 SHA256 a08ef0648b44fa11c2290395067c318657e53f9575a29a87a8b39703b683c71e
004A9AE0 55                               push   ebp
004A9AE1 8bec                             mov    ebp,esp
004A9AE3 6aff                             push   0xffffffff
004A9AE5 689e4d9200                       push   0x924d9e
004A9AEA 64a100000000                     mov    eax,fs:0x0
004A9AF0 50                               push   eax
004A9AF1 a1201fd600                       mov    eax,ds:0xd61f20
004A9AF6 33c5                             xor    eax,ebp
004A9AF8 50                               push   eax
004A9AF9 8d45f4                           lea    eax,[ebp-0xc]
004A9AFC 64a300000000                     mov    fs:0x0,eax
004A9B02 b801000000                       mov    eax,0x1
004A9B07 8405d4adfa00                     test   BYTE PTR ds:0xfaadd4,al
004A9B0D 7526                             jne    0x4a9b35
004A9B0F 0905d4adfa00                     or     DWORD PTR ds:0xfaadd4,eax
004A9B15 c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
004A9B1C e85fd90d00                       call   0x587480
004A9B21 68c0ccbc00                       push   0xbcccc0
004A9B26 e8ef873e00                       call   0x89231a
004A9B2B 83c404                           add    esp,0x4
004A9B2E c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
004A9B35 b80f000000                       mov    eax,0xf
004A9B3A 3905ecadfa00                     cmp    DWORD PTR ds:0xfaadec,eax
004A9B40 7414                             je     0x4a9b56
004A9B42 a3f0adfa00                       mov    ds:0xfaadf0,eax
004A9B47 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004A9B4A 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004A9B51 59                               pop    ecx
004A9B52 8be5                             mov    esp,ebp
004A9B54 5d                               pop    ebp
004A9B55 c3                               ret
004A9B56 e8450e0e00                       call   0x58a9a0
004A9B5B 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
004A9B5E 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
004A9B65 59                               pop    ecx
004A9B66 8be5                             mov    esp,ebp
004A9B68 5d                               pop    ebp
004A9B69 c3                               ret

; VT_Skip vtable and selected slot extent
; VA 0xc06948..0xc06978 raw 0x804f48 len 48 SHA256 74c0dabc11e2ee4b2867778c28b11459616142a8889459f8aa7a9cdee2cd6acf
2c98c600503d5500a03d5500e03d5500903f5500003e5500105d5f00e0874a00d0874a00703c550010f0800060af8700

; COL_Skip MSVC RTTI COL
; VA 0xc6982c..0xc69840 raw 0x867e2c len 20 SHA256 c6550f0664173e0de9fad6a871f161e9f6a90f8fdcb715ae5490408d2c1ec6b0
00000000000000000000000000dff7004098c600

; TYPE_Skip MSVC RTTI type name
; VA 0xf7df00..0xf7df1b raw 0xb7b700 len 27 SHA256 1e760d225dbc08ff2c313832d3420db3b3783445bb79b75b584062a8c61daaab
f435bd00000000002e3f415643536b69704d657373616765404000

; VT_Scaling vtable and selected slot extent
; VA 0xc06978..0xc069a8 raw 0x804f78 len 48 SHA256 8d13b70503baaba3cdb607a8d16b55deed3ae0c28f15b009715ea125620b26b7
dc97c600503d550030884a00e03d5500903f5500003e5500105d5f00b0884a0010884a00703c550010f0800060af8700

; COL_Scaling MSVC RTTI COL
; VA 0xc697dc..0xc697f0 raw 0x867ddc len 20 SHA256 0fa3618c259173d022638af10d43bb53dc667dbfb76c6b059a8d4545f7b239a1
000000000000000000000000b4def700f097c600

; TYPE_Scaling MSVC RTTI type name
; VA 0xf7deb4..0xf7ded1 raw 0xb7b6b4 len 29 SHA256 13dbe94c3fefdabad384b15996aab1cbdd0e93b758a8b967e04cce3a1bf3bffe
f435bd00000000002e3f4156435363616c696e674f626a656374404000

; VT_Mission vtable and selected slot extent
; VA 0xc1d1a8..0xc1d348 raw 0x81b7a8 len 416 SHA256 aebdb864e9fce8942bb491a08564b6a5be917b3bdcd8c29e4e7a597acc64d71d
e8fbc600203f4200103f4200103f4200003f4200e03d4000408c74006094740000ce5a00903e4200e03d4200603d4200f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f0070017700d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b7400800f7600703d4000d05a7400205b7400c059740030597400f0a07400503d4000b03d4000403d40005004550080d85a00e0674000d0877400f08774001088740010887400105d5f00a0ce5a0050d05a0010ae4900105d5f00f0ab590070ad5900f0ae590070b0590030d25900105d5f00105d5f0050045500d06f400020a17400306447003064470030644700e0674000e06740003064470030644700205d590030ed4000b03d4000e0674000c061590050395a00305e5900a05d5900c05e590010ae4900a0d65a00806b590090c55a00c0c55a0010d55a0030d65a00

; COL_Mission MSVC RTTI COL
; VA 0xc6fbe8..0xc6fbfc raw 0x86e1e8 len 20 SHA256 1a02c243a5866c24cb623d3b824cc8c3f7a4cc2997c74a47b651f8fe2ee1c177
0000000000000000000000009818f800fcfbc600

; TYPE_Mission MSVC RTTI type name
; VA 0xf81898..0xf818bc raw 0xb7f098 len 36 SHA256 68e02dd91919b515d5e7ea05e1fea1787f2a7d4ff0114141aff24640a7fd6315
f435bd00000000002e3f4156434d697373696f6e4669656c645061676540465549404000

; VT_Scenario vtable and selected slot extent
; VA 0xc1d628..0xc1d7c8 raw 0x81bc28 len 416 SHA256 831e5c03ca931b2e557ebb44ddb0d1a1cdf6bfda2db76c0b78cd4834ebeae9c5
2cfec600203f4200103f4200103f4200003f4200e03d4000408c74006094740020ea5a00903e4200e03d4200603d4200f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f0070017700d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b7400800f7600703d4000d05a7400205b7400c059740030597400f0a07400503d4000b03d4000403d40005004550010ff5a00e0674000d0877400f08774001088740010887400105d5f0030fc5a00c0fd5a0010ae4900105d5f00f0ab590070ad5900f0ae590070b0590030d25900105d5f00105d5f0050045500d06f400020a17400306447003064470030644700e0674000e06740003064470030644700205d590030ed4000b03d4000e0674000c061590050395a00305e5900a05d5900c05e590010ae4900b0fe5a00806b590090c55a00c0c55a0060fe5a0070fe5a00

; COL_Scenario MSVC RTTI COL
; VA 0xc6fe2c..0xc6fe40 raw 0x86e42c len 20 SHA256 7e496ac560476a542bf82d8ed3a00be9f5d258221a61de033783bc7a648f0f98
000000000000000000000000281af80040fec600

; TYPE_Scenario MSVC RTTI type name
; VA 0xf81a28..0xf81a4d raw 0xb7f228 len 37 SHA256 c4fea19adb1af17d587e6645283bbb22f83696b37c108fbd9a9d21cf2653ef64
f435bd00000000002e3f4156435363656e6172696f4669656c645061676540465549404000

; VT_Tutorial vtable and selected slot extent
; VA 0xc1f5f0..0xc1f790 raw 0x81dbf0 len 416 SHA256 799f34fdf4ce10c6e665376c95b3912fdc755d922415e774b50a9c840cc4ee0c
e017c700203f4200103f4200103f4200003f4200e03d4000408c74006094740020ea5a00903e4200e03d4200603d4200f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f0070017700d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b7400800f7600703d4000d05a7400205b7400c059740030597400f0a07400503d4000b03d4000403d40005004550050375c00e0674000d0877400f08774001088740010887400105d5f0040305c0010325c0010ae4900105d5f00f0ab590070ad5900f0ae590070b05900b0395c00105d5f00105d5f0050045500d06f400020a17400306447003064470030644700e0674000e06740003064470030644700205d590030ed4000b03d4000e0674000c061590050395a00305e5900a05d5900c05e590010ae4900b0335c00806b5900d0325c0050335c0060335c0070335c00

; COL_Tutorial MSVC RTTI COL
; VA 0xc717e0..0xc717f4 raw 0x86fde0 len 20 SHA256 1fae9825d9901f59aca4dba3c2acee5eb814480bdd3575d532bbd2942ed1a4d7
000000000000000000000000c82ef800f417c700

; TYPE_Tutorial MSVC RTTI type name
; VA 0xf82ec8..0xf82ee8 raw 0xb806c8 len 32 SHA256 6c5557d2262c20a85df11f0b9a605b9896ca2ec3f2ef25f23d431b16a7fa387f
f435bd00000000002e3f4156435475746f7269616c5061676540465549404000

; VT_ScenarioResult vtable and selected slot extent
; VA 0xc1cba8..0xc1cd48 raw 0x81b1a8 len 416 SHA256 c7c2802c1473c40cb89ff102b4573f988239fea4abb8cc8e34e69868cb3e0a75
98f6c600203f4200103f4200103f4200003f4200e03d4000408c74006094740020ea5a00903e4200e03d4200603d4200f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f0070017700d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b7400800f7600703d4000d05a7400205b7400c059740030597400f0a07400503d4000b03d4000403d400050045500904b5a00e0674000d0877400f08774001088740010887400105d5f00a0ac5a0090ad5a0010ae4900105d5f0000a15a0050a15a00a0a15a00f0a15a00805f5900105d5f00105d5f0050045500d06f400020a17400306447003064470030644700e0674000e06740003064470030644700205d590030ed4000b03d4000e0674000c061590050395a00305e5900a05d5900c05e590010ae4900d0c94300806b590080ae5a00d065590050ae5a0010435a00

; COL_ScenarioResult MSVC RTTI COL
; VA 0xc6f698..0xc6f6ac raw 0x86dc98 len 20 SHA256 d0ff4e871c0e6d928674b1db0586a04176eccba46805c68fe783dd562906b9d1
0000000000000000000000006414f800acf6c600

; TYPE_ScenarioResult MSVC RTTI type name
; VA 0xf81464..0xf8148a raw 0xb7ec64 len 38 SHA256 f84fb5f8f689eee9bcb3c3a52ef478b38319303c986283190dd7da7e8399add8
f435bd00000000002e3f4156435363656e6172696f526573756c745061676540465549404000

; VT_TutorialField vtable and selected slot extent
; VA 0xc1d7d8..0xc1d978 raw 0x81bdd8 len 416 SHA256 69bd705eefb557f0c62afa644208dd3f5597b0cbeca86425a1283d2a1966d7b6
dcfec600203f4200103f4200103f4200003f4200e03d4000408c74006094740020ea5a00903e4200e03d4200603d4200f0ea400030557400f0567400505a7400205a7400705b7400d03d4000a06d4600b03d400090987400e0987400c03d4000105d5f0070017700d06f740000867400708674004066740000677400b03d4000b03d4000b03d4000b03d4000b03d4000803d400080607400e060740030617400f061740080627400e062740050637400b0637400105d5f00805c7400606c7400509b7400800f7600703d4000d05a7400205b7400c059740030597400f0a07400503d4000b03d4000403d400050045500e0015b00e0674000d0877400f08774001088740010887400105d5f00e0ff5a00d0005b0010ae4900105d5f00f0ab590070ad5900f0ae590070b0590030d25900105d5f00105d5f0050045500d06f400020a17400306447003064470030644700e0674000e06740003064470030644700205d590030ed4000b03d4000e0674000c061590050395a00305e5900a05d5900c05e590010ae490070015b00806b590090c55a00c0c55a0000c65a00b0ff5a00

; COL_TutorialField MSVC RTTI COL
; VA 0xc6fedc..0xc6fef0 raw 0x86e4dc len 20 SHA256 367d0a4d9726a32c0c103a2fdca274326c6300438d4bd1de8f12661e85ffd033
000000000000000000000000901af800f0fec600

; TYPE_TutorialField MSVC RTTI type name
; VA 0xf81a90..0xf81ab5 raw 0xb7f290 len 37 SHA256 2f92c5c2c29e0eca11b67bf5cb446c73a4f89b40917c950a1f9a51140d9ecd2c
f435bd00000000002e3f4156435475746f7269616c4669656c645061676540465549404000

; MAP_EmployOrdinary selected switch map byte
; VA 0x59b89b..0x59b89c raw 0x19ac9b len 1 SHA256 3973e022e93220f9212c18d0d0c543ae7c309e46640da93a4a0314de999f5112
2d

; DST_EmployOrdinary selected switch destination
; VA 0x59b850..0x59b854 raw 0x19ac50 len 4 SHA256 5f88d05232954d31ab0563a66997287409424f1a34aae1dffc7ec194e630d8d9
95b75900

; MAP_TutoOrdinary selected switch map byte
; VA 0x59c168..0x59c169 raw 0x19b568 len 1 SHA256 58f7b0780592032e4d8602a3e8690fb2c701b2e1dd546e703445aabd6469734d
1a

; DST_TutoOrdinary selected switch destination
; VA 0x59c0c8..0x59c0cc raw 0x19b4c8 len 4 SHA256 47c85af19cb35b9a36755503cc44e86fab37f2c836d5a4694fed4f64dd684a58
57c05900

; MAP_TutoCommonFirst selected switch map byte
; VA 0x5a442e..0x5a442f raw 0x1a382e len 1 SHA256 e52d9c508c502347344d8c07ad91cbd6068afc75ff6292f062a09ca381c89e71
04

; DST_TutoCommonFirst selected switch destination
; VA 0x5a4408..0x5a440c raw 0x1a3808 len 4 SHA256 cf08c533267e958085cb755bc3f477a9b4a596b6eaad46bcd8bf1fd2e46bfe3f
57435a00

; STR_Skip RegisterSkipMessage
; VA 0xd6ac6c..0xd6ac80 raw 0x96846c len 20 SHA256 a6d6d916642afb9eca1693d00c863d32cf4b37d516681df48bfc593e6a9056d9
5265676973746572536b69704d65737361676500

; STR_Scaling RegisterScalingObject
; VA 0xd6ac80..0xd6ac96 raw 0x968480 len 22 SHA256 ea5c9349e7f44a8d08c19780f5b5c7c8b56ffc3f0d61ab04b0c4dc0481289ca8
52656769737465725363616c696e674f626a65637400

; STR_Destroy DestroyFlyingObjects
; VA 0xd6ac98..0xd6acad raw 0x968498 len 21 SHA256 789946de6d57860094ad67fe4873dda984c78d0600c306d53d52f8a733444b9c
44657374726f79466c79696e674f626a6563747300

; STR_Employ PostUIMessage_EmployChar
; VA 0xd6ac24..0xd6ac3d raw 0x968424 len 25 SHA256 b0b072ad925e4058be1a94c631e9009a0ac83c78bb8ae6f2d6d0d88abd81dbb3
506f737455494d6573736167655f456d706c6f794368617200

; STR_Tuto PostUIMessage_TutoMsg
; VA 0xd6ac40..0xd6ac56 raw 0x968440 len 22 SHA256 66886dd2eb3331de02debd69bc1c3cc593f206d3dee7912118cf7fe490d9702f
506f737455494d6573736167655f5475746f4d736700
