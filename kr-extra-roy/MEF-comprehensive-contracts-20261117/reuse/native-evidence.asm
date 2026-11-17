; q_start [REUSED_BODY_NEW_CROSS_RUN_JOIN] 0x561760..0x561da6 exclusive
00561760  55                               push   ebp
00561761  8bec                             mov    ebp,esp
00561763  83e4f8                           and    esp,0xfffffff8
00561766  6aff                             push   0xffffffff
00561768  682cfd9300                       push   0x93fd2c
0056176D  64a100000000                     mov    eax,fs:0x0
00561773  50                               push   eax
00561774  83ec50                           sub    esp,0x50
00561777  a1201fd600                       mov    eax,ds:0xd61f20
0056177C  33c4                             xor    eax,esp
0056177E  89442448                         mov    DWORD PTR [esp+0x48],eax
00561782  53                               push   ebx
00561783  56                               push   esi
00561784  57                               push   edi
00561785  a1201fd600                       mov    eax,ds:0xd61f20
0056178A  33c4                             xor    eax,esp
0056178C  50                               push   eax
0056178D  8d442460                         lea    eax,[esp+0x60]
00561791  64a300000000                     mov    fs:0x0,eax
00561797  833d18abfb0000                   cmp    DWORD PTR ds:0xfbab18,0x0
0056179E  8bd9                             mov    ebx,ecx
005617A0  7420                             je     0x5617c2
005617A2  0f57c0                           xorps  xmm0,xmm0
005617A5  f30f110524abfb00                 movss  DWORD PTR ds:0xfbab24,xmm0
005617AD  e8aed8eaff                       call   0x40f060
005617B2  f30f10057059c500                 movss  xmm0,DWORD PTR ds:0xc55970
005617BA  f30f1180ac000000                 movss  DWORD PTR [eax+0xac],xmm0
005617C2  837b2800                         cmp    DWORD PTR [ebx+0x28],0x0
005617C6  c6838900000000                   mov    BYTE PTR [ebx+0x89],0x0
005617CD  741a                             je     0x5617e9
005617CF  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
005617D2  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
005617D5  50                               push   eax
005617D6  51                               push   ecx
005617D7  68ac06c100                       push   0xc106ac
005617DC  e87fc31800                       call   0x6edb60
005617E1  83c40c                           add    esp,0xc
005617E4  e99d050000                       jmp    0x561d86
005617E9  f6052888fb0001                   test   BYTE PTR ds:0xfb8828,0x1
005617F0  be01000000                       mov    esi,0x1
005617F5  7529                             jne    0x561820
005617F7  09352888fb00                     or     DWORD PTR ds:0xfb8828,esi
005617FD  c744246800000000                 mov    DWORD PTR [esp+0x68],0x0
00561805  e846e0feff                       call   0x54f850
0056180A  6880d5bc00                       push   0xbcd580
0056180F  e8060b3300                       call   0x89231a
00561814  83c404                           add    esp,0x4
00561817  83cfff                           or     edi,0xffffffff
0056181A  897c2468                         mov    DWORD PTR [esp+0x68],edi
0056181E  eb03                             jmp    0x561823
00561820  83cfff                           or     edi,0xffffffff
00561823  803df192fb0000                   cmp    BYTE PTR ds:0xfb92f1,0x0
0056182A  0f84ac000000                     je     0x5618dc
00561830  837d0800                         cmp    DWORD PTR [ebp+0x8],0x0
00561834  0f85a2000000                     jne    0x5618dc
0056183A  e86133eaff                       call   0x404ba0
0056183F  83b84c5f000009                   cmp    DWORD PTR [eax+0x5f4c],0x9
00561846  741c                             je     0x561864
00561848  e85333eaff                       call   0x404ba0
0056184D  83b84c5f000004                   cmp    DWORD PTR [eax+0x5f4c],0x4
00561854  740e                             je     0x561864
00561856  e84533eaff                       call   0x404ba0
0056185B  83b84c5f000019                   cmp    DWORD PTR [eax+0x5f4c],0x19
00561862  7578                             jne    0x5618dc
00561864  8b7378                           mov    esi,DWORD PTR [ebx+0x78]
00561867  8d550c                           lea    edx,[ebp+0xc]
0056186A  52                               push   edx
0056186B  8d4b74                           lea    ecx,[ebx+0x74]
0056186E  8d442414                         lea    eax,[esp+0x14]
00561872  e8494cedff                       call   0x4364c0
00561877  3930                             cmp    DWORD PTR [eax],esi
00561879  745c                             je     0x5618d7
0056187B  6a0f                             push   0xf
0056187D  e82e3d0200                       call   0x5855b0
00561882  8bf0                             mov    esi,eax
00561884  e8a73a0200                       call   0x585330
00561889  50                               push   eax
0056188A  8d4c2440                         lea    ecx,[esp+0x40]
0056188E  e8bd09eaff                       call   0x402250
00561893  8d44243c                         lea    eax,[esp+0x3c]
00561897  50                               push   eax
00561898  c744246c01000000                 mov    DWORD PTR [esp+0x6c],0x1
005618A0  e81be0eaff                       call   0x40f8c0
005618A5  8bf8                             mov    edi,eax
005618A7  e88452f7ff                       call   0x4d6b30
005618AC  8d4c243c                         lea    ecx,[esp+0x3c]
005618B0  c7442468ffffffff                 mov    DWORD PTR [esp+0x68],0xffffffff
005618B8  e8838bf9ff                       call   0x4fa440
005618BD  e8be2debff                       call   0x414680
005618C2  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
005618C5  51                               push   ecx
005618C6  6a00                             push   0x0
005618C8  e8d320f4ff                       call   0x4a39a0
005618CD  e8de070000                       call   0x5620b0
005618D2  e9af040000                       jmp    0x561d86
005618D7  be01000000                       mov    esi,0x1
005618DC  f605d4adfa0001                   test   BYTE PTR ds:0xfaadd4,0x1
005618E3  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
005618E6  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
005618E9  895338                           mov    DWORD PTR [ebx+0x38],edx
005618EC  89433c                           mov    DWORD PTR [ebx+0x3c],eax
005618EF  897328                           mov    DWORD PTR [ebx+0x28],esi
005618F2  7524                             jne    0x561918
005618F4  0935d4adfa00                     or     DWORD PTR ds:0xfaadd4,esi
005618FA  c744246802000000                 mov    DWORD PTR [esp+0x68],0x2
00561902  e8795b0200                       call   0x587480
00561907  68c0ccbc00                       push   0xbcccc0
0056190C  e8090a3300                       call   0x89231a
00561911  83c404                           add    esp,0x4
00561914  897c2468                         mov    DWORD PTR [esp+0x68],edi
00561918  f605d0adfa0001                   test   BYTE PTR ds:0xfaadd0,0x1
0056191F  7524                             jne    0x561945
00561921  0935d0adfa00                     or     DWORD PTR ds:0xfaadd0,esi
00561927  c744246803000000                 mov    DWORD PTR [esp+0x68],0x3
0056192F  e85cc01e00                       call   0x74d990
00561934  6870ccbc00                       push   0xbccc70
00561939  e8dc093300                       call   0x89231a
0056193E  83c404                           add    esp,0x4
00561941  897c2468                         mov    DWORD PTR [esp+0x68],edi
00561945  f6059043f90001                   test   BYTE PTR ds:0xf94390,0x1
0056194C  8b0dbc5bf900                     mov    ecx,DWORD PTR ds:0xf95bbc
00561952  8b15c05bf900                     mov    edx,DWORD PTR ds:0xf95bc0
00561958  894c2414                         mov    DWORD PTR [esp+0x14],ecx
0056195C  f30f10442414                     movss  xmm0,DWORD PTR [esp+0x14]
00561962  89542418                         mov    DWORD PTR [esp+0x18],edx
00561966  f30f118384000000                 movss  DWORD PTR [ebx+0x84],xmm0
0056196E  7524                             jne    0x561994
00561970  09359043f900                     or     DWORD PTR ds:0xf94390,esi
00561976  c744246804000000                 mov    DWORD PTR [esp+0x68],0x4
0056197E  e80dfcf7ff                       call   0x4e1590
00561983  6880ccbc00                       push   0xbccc80
00561988  e88d093300                       call   0x89231a
0056198D  83c404                           add    esp,0x4
00561990  897c2468                         mov    DWORD PTR [esp+0x68],edi
00561994  f605d4adfa0001                   test   BYTE PTR ds:0xfaadd4,0x1
0056199B  a0a442f900                       mov    al,ds:0xf942a4
005619A0  888388000000                     mov    BYTE PTR [ebx+0x88],al
005619A6  7524                             jne    0x5619cc
005619A8  0935d4adfa00                     or     DWORD PTR ds:0xfaadd4,esi
005619AE  c744246805000000                 mov    DWORD PTR [esp+0x68],0x5
005619B6  e8c55a0200                       call   0x587480
005619BB  68c0ccbc00                       push   0xbcccc0
005619C0  e855093300                       call   0x89231a
005619C5  83c404                           add    esp,0x4
005619C8  897c2468                         mov    DWORD PTR [esp+0x68],edi
005619CC  6858430f00                       push   0xf4358
005619D1  e8fa900200                       call   0x58aad0
005619D6  83c404                           add    esp,0x4
005619D9  f6059043f90001                   test   BYTE PTR ds:0xf94390,0x1
005619E0  7524                             jne    0x561a06
005619E2  09359043f900                     or     DWORD PTR ds:0xf94390,esi
005619E8  c744246806000000                 mov    DWORD PTR [esp+0x68],0x6
005619F0  e89bfbf7ff                       call   0x4e1590
005619F5  6880ccbc00                       push   0xbccc80
005619FA  e81b093300                       call   0x89231a
005619FF  83c404                           add    esp,0x4
00561A02  897c2468                         mov    DWORD PTR [esp+0x68],edi
00561A06  6a00                             push   0x0
00561A08  687523bf00                       push   0xbf2375
00561A0D  8d4b44                           lea    ecx,[ebx+0x44]
00561A10  c605a442f90001                   mov    BYTE PTR ds:0xf942a4,0x1
00561A17  e85410eaff                       call   0x402a70
00561A1C  8b730c                           mov    esi,DWORD PTR [ebx+0xc]
00561A1F  8b4604                           mov    eax,DWORD PTR [esi+0x4]
00561A22  80783100                         cmp    BYTE PTR [eax+0x31],0x0
00561A26  8bd6                             mov    edx,esi
00561A28  752c                             jne    0x561a56
00561A2A  8d9b00000000                     lea    ebx,[ebx+0x0]
00561A30  8b480c                           mov    ecx,DWORD PTR [eax+0xc]
00561A33  8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
00561A36  3bf9                             cmp    edi,ecx
00561A38  7f0a                             jg     0x561a44
00561A3A  7c0d                             jl     0x561a49
00561A3C  8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
00561A3F  394810                           cmp    DWORD PTR [eax+0x10],ecx
00561A42  7d05                             jge    0x561a49
00561A44  8b4008                           mov    eax,DWORD PTR [eax+0x8]
00561A47  eb04                             jmp    0x561a4d
00561A49  8bd0                             mov    edx,eax
00561A4B  8b00                             mov    eax,DWORD PTR [eax]
00561A4D  80783100                         cmp    BYTE PTR [eax+0x31],0x0
00561A51  74dd                             je     0x561a30
00561A53  83cfff                           or     edi,0xffffffff
00561A56  8954241c                         mov    DWORD PTR [esp+0x1c],edx
00561A5A  3bd6                             cmp    edx,esi
00561A5C  741a                             je     0x561a78
00561A5E  8b420c                           mov    eax,DWORD PTR [edx+0xc]
00561A61  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
00561A64  3bc1                             cmp    eax,ecx
00561A66  7f10                             jg     0x561a78
00561A68  7c08                             jl     0x561a72
00561A6A  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
00561A6D  3b4210                           cmp    eax,DWORD PTR [edx+0x10]
00561A70  7c06                             jl     0x561a78
00561A72  8d44241c                         lea    eax,[esp+0x1c]
00561A76  eb08                             jmp    0x561a80
00561A78  89742410                         mov    DWORD PTR [esp+0x10],esi
00561A7C  8d442410                         lea    eax,[esp+0x10]
00561A80  8b30                             mov    esi,DWORD PTR [eax]
00561A82  3b730c                           cmp    esi,DWORD PTR [ebx+0xc]
00561A85  0f84f4020000                     je     0x561d7f
00561A8B  6a10                             push   0x10
00561A8D  68d006c100                       push   0xc106d0
00561A92  8d4c2428                         lea    ecx,[esp+0x28]
00561A96  c744243c0f000000                 mov    DWORD PTR [esp+0x3c],0xf
00561A9E  c744243800000000                 mov    DWORD PTR [esp+0x38],0x0
00561AA6  c644242800                       mov    BYTE PTR [esp+0x28],0x0
00561AAB  e8c00feaff                       call   0x402a70
00561AB0  8d4614                           lea    eax,[esi+0x14]
00561AB3  57                               push   edi
00561AB4  33f6                             xor    esi,esi
00561AB6  56                               push   esi
00561AB7  50                               push   eax
00561AB8  8d4c242c                         lea    ecx,[esp+0x2c]
00561ABC  c744247407000000                 mov    DWORD PTR [esp+0x74],0x7
00561AC4  e80704eaff                       call   0x401ed0
00561AC9  6a04                             push   0x4
00561ACB  68e406c100                       push   0xc106e4
00561AD0  8d4c2428                         lea    ecx,[esp+0x28]
00561AD4  e8e704eaff                       call   0x401fc0
00561AD9  837c243410                       cmp    DWORD PTR [esp+0x34],0x10
00561ADE  8b442420                         mov    eax,DWORD PTR [esp+0x20]
00561AE2  7304                             jae    0x561ae8
00561AE4  8d442420                         lea    eax,[esp+0x20]
00561AE8  50                               push   eax
00561AE9  51                               push   ecx
00561AEA  e8b1aaffff                       call   0x55c5a0
00561AEF  83c404                           add    esp,0x4
00561AF2  50                               push   eax
00561AF3  e8a8bbffff                       call   0x55d6a0
00561AF8  6a1c                             push   0x1c
00561AFA  894370                           mov    DWORD PTR [ebx+0x70],eax
00561AFD  e866f73200                       call   0x891268
00561B02  83c404                           add    esp,0x4
00561B05  3bc6                             cmp    eax,esi
00561B07  7411                             je     0x561b1a
00561B09  8930                             mov    DWORD PTR [eax],esi
00561B0B  c6400801                         mov    BYTE PTR [eax+0x8],0x1
00561B0F  89700c                           mov    DWORD PTR [eax+0xc],esi
00561B12  897010                           mov    DWORD PTR [eax+0x10],esi
00561B15  897014                           mov    DWORD PTR [eax+0x14],esi
00561B18  eb02                             jmp    0x561b1c
00561B1A  33c0                             xor    eax,eax
00561B1C  50                               push   eax
00561B1D  8d4c2418                         lea    ecx,[esp+0x18]
00561B21  51                               push   ecx
00561B22  8974241c                         mov    DWORD PTR [esp+0x1c],esi
00561B26  89742420                         mov    DWORD PTR [esp+0x20],esi
00561B2A  e8a1a5f1ff                       call   0x47c0d0
00561B2F  c644246808                       mov    BYTE PTR [esp+0x68],0x8
00561B34  8b742414                         mov    esi,DWORD PTR [esp+0x14]
00561B38  c7460403000000                   mov    DWORD PTR [esi+0x4],0x3
00561B3F  c6460801                         mov    BYTE PTR [esi+0x8],0x1
00561B43  8b4b70                           mov    ecx,DWORD PTR [ebx+0x70]
00561B46  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
00561B49  8b00                             mov    eax,DWORD PTR [eax]
00561B4B  8944241c                         mov    DWORD PTR [esp+0x1c],eax
00561B4F  3b4104                           cmp    eax,DWORD PTR [ecx+0x4]
00561B52  7436                             je     0x561b8a
00561B54  8d7e0c                           lea    edi,[esi+0xc]
00561B57  eb07                             jmp    0x561b60
00561B59  8da42400000000                   lea    esp,[esp+0x0]
00561B60  8b5010                           mov    edx,DWORD PTR [eax+0x10]
00561B63  0fb702                           movzx  eax,WORD PTR [edx]
00561B66  89442410                         mov    DWORD PTR [esp+0x10],eax
00561B6A  8d442410                         lea    eax,[esp+0x10]
00561B6E  e80d6bf4ff                       call   0x4a8680
00561B73  8d44241c                         lea    eax,[esp+0x1c]
00561B77  e824cbf3ff                       call   0x49e6a0
00561B7C  8b4370                           mov    eax,DWORD PTR [ebx+0x70]
00561B7F  8b4804                           mov    ecx,DWORD PTR [eax+0x4]
00561B82  8b44241c                         mov    eax,DWORD PTR [esp+0x1c]
00561B86  3bc1                             cmp    eax,ecx
00561B88  75d6                             jne    0x561b60
00561B8A  8b542418                         mov    edx,DWORD PTR [esp+0x18]
00561B8E  83ec08                           sub    esp,0x8
00561B91  8bfc                             mov    edi,esp
00561B93  89642418                         mov    DWORD PTR [esp+0x18],esp
00561B97  c70700000000                     mov    DWORD PTR [edi],0x0
00561B9D  c7470400000000                   mov    DWORD PTR [edi+0x4],0x0
00561BA4  85d2                             test   edx,edx
00561BA6  7416                             je     0x561bbe
00561BA8  e8a3a6f1ff                       call   0x47c250
00561BAD  84c0                             test   al,al
00561BAF  740d                             je     0x561bbe
00561BB1  8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
00561BB5  51                               push   ecx
00561BB6  56                               push   esi
00561BB7  8bf7                             mov    esi,edi
00561BB9  e802162400                       call   0x7a31c0
00561BBE  c644247009                       mov    BYTE PTR [esp+0x70],0x9
00561BC3  f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
00561BCA  7523                             jne    0x561bef
00561BCC  830d600ffc0001                   or     DWORD PTR ds:0xfc0f60,0x1
00561BD3  c64424700a                       mov    BYTE PTR [esp+0x70],0xa
00561BD8  e863b32300                       call   0x79cf40
00561BDD  6880dbbc00                       push   0xbcdb80
00561BE2  e833073300                       call   0x89231a
00561BE7  83c404                           add    esp,0x4
00561BEA  c644247009                       mov    BYTE PTR [esp+0x70],0x9
00561BEF  b9900efc00                       mov    ecx,0xfc0e90
00561BF4  c644247008                       mov    BYTE PTR [esp+0x70],0x8
00561BF9  e8e2c02300                       call   0x79dce0
00561BFE  8bf0                             mov    esi,eax
00561C00  6aff                             push   0xffffffff
00561C02  56                               push   esi
00561C03  ff15fc20bd00                     call   DWORD PTR ds:0xbd20fc
00561C09  56                               push   esi
00561C0A  ff15c821bd00                     call   DWORD PTR ds:0xbd21c8
00561C10  f6057017fe0001                   test   BYTE PTR ds:0xfe1770,0x1
00561C17  7523                             jne    0x561c3c
00561C19  830d7017fe0001                   or     DWORD PTR ds:0xfe1770,0x1
00561C20  c64424680b                       mov    BYTE PTR [esp+0x68],0xb
00561C25  e876612500                       call   0x7b7da0
00561C2A  6890e7bc00                       push   0xbce790
00561C2F  e8e6063300                       call   0x89231a
00561C34  83c404                           add    esp,0x4
00561C37  c644246808                       mov    BYTE PTR [esp+0x68],0x8
00561C3C  8b3d3c17fe00                     mov    edi,DWORD PTR ds:0xfe173c
00561C42  8b4704                           mov    eax,DWORD PTR [edi+0x4]
00561C45  8b30                             mov    esi,DWORD PTR [eax]
00561C47  3bf0                             cmp    esi,eax
00561C49  741c                             je     0x561c67
00561C4B  eb03                             jmp    0x561c50
00561C4D  8d4900                           lea    ecx,[ecx+0x0]
00561C50  8b4e24                           mov    ecx,DWORD PTR [esi+0x24]
00561C53  83790400                         cmp    DWORD PTR [ecx+0x4],0x0
00561C57  7507                             jne    0x561c60
00561C59  8b11                             mov    edx,DWORD PTR [ecx]
00561C5B  8b4204                           mov    eax,DWORD PTR [edx+0x4]
00561C5E  ffd0                             call   eax
00561C60  8b36                             mov    esi,DWORD PTR [esi]
00561C62  3b7704                           cmp    esi,DWORD PTR [edi+0x4]
00561C65  75e9                             jne    0x561c50
00561C67  8b442420                         mov    eax,DWORD PTR [esp+0x20]
00561C6B  bf10000000                       mov    edi,0x10
00561C70  397c2434                         cmp    DWORD PTR [esp+0x34],edi
00561C74  7304                             jae    0x561c7a
00561C76  8d442420                         lea    eax,[esp+0x20]
00561C7A  8b0b                             mov    ecx,DWORD PTR [ebx]
00561C7C  50                               push   eax
00561C7D  e8ce2d1900                       call   0x6f4a50
00561C82  33db                             xor    ebx,ebx
00561C84  f605ec79fb0001                   test   BYTE PTR ds:0xfb79ec,0x1
00561C8B  be01000000                       mov    esi,0x1
00561C90  7535                             jne    0x561cc7
00561C92  0935ec79fb00                     or     DWORD PTR ds:0xfb79ec,esi
00561C98  6870d2bc00                       push   0xbcd270
00561C9D  c705f079fb0068f8c000             mov    DWORD PTR ds:0xfb79f0,0xc0f868
00561CA7  891df479fb00                     mov    DWORD PTR ds:0xfb79f4,ebx
00561CAD  891df879fb00                     mov    DWORD PTR ds:0xfb79f8,ebx
00561CB3  891dfc79fb00                     mov    DWORD PTR ds:0xfb79fc,ebx
00561CB9  8935047afb00                     mov    DWORD PTR ds:0xfb7a04,esi
00561CBF  e856063300                       call   0x89231a
00561CC4  83c404                           add    esp,0x4
00561CC7  f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
00561CCE  891d047afb00                     mov    DWORD PTR ds:0xfb7a04,ebx
00561CD4  7522                             jne    0x561cf8
00561CD6  0935600ffc00                     or     DWORD PTR ds:0xfc0f60,esi
00561CDC  c64424680c                       mov    BYTE PTR [esp+0x68],0xc
00561CE1  e85ab22300                       call   0x79cf40
00561CE6  6880dbbc00                       push   0xbcdb80
00561CEB  e82a063300                       call   0x89231a
00561CF0  83c404                           add    esp,0x4
00561CF3  c644246808                       mov    BYTE PTR [esp+0x68],0x8
00561CF8  6a02                             push   0x2
00561CFA  68900efc00                       push   0xfc0e90
00561CFF  e8bcbc2300                       call   0x79d9c0
00561D04  f605d894fd0001                   test   BYTE PTR ds:0xfd94d8,0x1
00561D0B  751d                             jne    0x561d2a
00561D0D  0935d894fd00                     or     DWORD PTR ds:0xfd94d8,esi
00561D13  c64424680d                       mov    BYTE PTR [esp+0x68],0xd
00561D18  e813372500                       call   0x7b5430
00561D1D  6860e6bc00                       push   0xbce660
00561D22  e8f3053300                       call   0x89231a
00561D27  83c404                           add    esp,0x4
00561D2A  c644246807                       mov    BYTE PTR [esp+0x68],0x7
00561D2F  8b742418                         mov    esi,DWORD PTR [esp+0x18]
00561D33  c705b094fd0002000000             mov    DWORD PTR ds:0xfd94b0,0x2
00561D3D  3bf3                             cmp    esi,ebx
00561D3F  7429                             je     0x561d6a
00561D41  8d4e04                           lea    ecx,[esi+0x4]
00561D44  83caff                           or     edx,0xffffffff
00561D47  f00fc111                         lock xadd DWORD PTR [ecx],edx
00561D4B  751d                             jne    0x561d6a
00561D4D  8b06                             mov    eax,DWORD PTR [esi]
00561D4F  8b10                             mov    edx,DWORD PTR [eax]
00561D51  8bce                             mov    ecx,esi
00561D53  ffd2                             call   edx
00561D55  8d4608                           lea    eax,[esi+0x8]
00561D58  83c9ff                           or     ecx,0xffffffff
00561D5B  f00fc108                         lock xadd DWORD PTR [eax],ecx
00561D5F  7509                             jne    0x561d6a
00561D61  8b16                             mov    edx,DWORD PTR [esi]
00561D63  8b4204                           mov    eax,DWORD PTR [edx+0x4]
00561D66  8bce                             mov    ecx,esi
00561D68  ffd0                             call   eax
00561D6A  397c2434                         cmp    DWORD PTR [esp+0x34],edi
00561D6E  7216                             jb     0x561d86
00561D70  8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
00561D74  51                               push   ecx
00561D75  e892f43200                       call   0x89120c
00561D7A  83c404                           add    esp,0x4
00561D7D  eb07                             jmp    0x561d86
00561D7F  8bcb                             mov    ecx,ebx
00561D81  e82a000000                       call   0x561db0
00561D86  8b4c2460                         mov    ecx,DWORD PTR [esp+0x60]
00561D8A  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00561D91  59                               pop    ecx
00561D92  5f                               pop    edi
00561D93  5e                               pop    esi
00561D94  5b                               pop    ebx
00561D95  8b4c2448                         mov    ecx,DWORD PTR [esp+0x48]
00561D99  33cc                             xor    ecx,esp
00561D9B  e861f23200                       call   0x891001
00561DA0  8be5                             mov    esp,ebp
00561DA2  5d                               pop    ebp
00561DA3  c20800                           ret    0x8

; prepass_load [REUSED_BODY_NEW_CROSS_RUN_JOIN] 0x55d6a0..0x55d7d3 exclusive
0055D6A0  55                               push   ebp
0055D6A1  8bec                             mov    ebp,esp
0055D6A3  51                               push   ecx
0055D6A4  53                               push   ebx
0055D6A5  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0055D6A8  56                               push   esi
0055D6A9  8d4308                           lea    eax,[ebx+0x8]
0055D6AC  57                               push   edi
0055D6AD  50                               push   eax
0055D6AE  8945fc                           mov    DWORD PTR [ebp-0x4],eax
0055D6B1  e82a0c0000                       call   0x55e2e0
0055D6B6  83c404                           add    esp,0x4
0055D6B9  6a00                             push   0x0
0055D6BB  687523bf00                       push   0xbf2375
0055D6C0  8d4b18                           lea    ecx,[ebx+0x18]
0055D6C3  e8a853eaff                       call   0x402a70
0055D6C8  8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0055D6CB  8b30                             mov    esi,DWORD PTR [eax]
0055D6CD  6a00                             push   0x0
0055D6CF  6840c95500                       push   0x55c940
0055D6D4  894508                           mov    DWORD PTR [ebp+0x8],eax
0055D6D7  e8d47e1900                       call   0x6f55b0
0055D6DC  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0055D6DF  8b31                             mov    esi,DWORD PTR [ecx]
0055D6E1  bf3002c100                       mov    edi,0xc10230
0055D6E6  b8eed8ffff                       mov    eax,0xffffd8ee
0055D6EB  e8a0801900                       call   0x6f5790
0055D6F0  8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0055D6F3  8b30                             mov    esi,DWORD PTR [eax]
0055D6F5  6a00                             push   0x0
0055D6F7  68e0cc5500                       push   0x55cce0
0055D6FC  894508                           mov    DWORD PTR [ebp+0x8],eax
0055D6FF  e8ac7e1900                       call   0x6f55b0
0055D704  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0055D707  8b32                             mov    esi,DWORD PTR [edx]
0055D709  bf4002c100                       mov    edi,0xc10240
0055D70E  b8eed8ffff                       mov    eax,0xffffd8ee
0055D713  e878801900                       call   0x6f5790
0055D718  8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0055D71B  8b30                             mov    esi,DWORD PTR [eax]
0055D71D  6a00                             push   0x0
0055D71F  68d0ce5500                       push   0x55ced0
0055D724  894508                           mov    DWORD PTR [ebp+0x8],eax
0055D727  e8847e1900                       call   0x6f55b0
0055D72C  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0055D72F  8b31                             mov    esi,DWORD PTR [ecx]
0055D731  bf4c02c100                       mov    edi,0xc1024c
0055D736  b8eed8ffff                       mov    eax,0xffffd8ee
0055D73B  e850801900                       call   0x6f5790
0055D740  8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0055D743  8b30                             mov    esi,DWORD PTR [eax]
0055D745  6a00                             push   0x0
0055D747  6820d25500                       push   0x55d220
0055D74C  894508                           mov    DWORD PTR [ebp+0x8],eax
0055D74F  e85c7e1900                       call   0x6f55b0
0055D754  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0055D757  8b32                             mov    esi,DWORD PTR [edx]
0055D759  bf5802c100                       mov    edi,0xc10258
0055D75E  b8eed8ffff                       mov    eax,0xffffd8ee
0055D763  e828801900                       call   0x6f5790
0055D768  8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0055D76B  8b30                             mov    esi,DWORD PTR [eax]
0055D76D  6a00                             push   0x0
0055D76F  6860d55500                       push   0x55d560
0055D774  894508                           mov    DWORD PTR [ebp+0x8],eax
0055D777  e8347e1900                       call   0x6f55b0
0055D77C  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0055D77F  8b31                             mov    esi,DWORD PTR [ecx]
0055D781  bf6402c100                       mov    edi,0xc10264
0055D786  b8eed8ffff                       mov    eax,0xffffd8ee
0055D78B  e800801900                       call   0x6f5790
0055D790  8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0055D793  8b30                             mov    esi,DWORD PTR [eax]
0055D795  6a00                             push   0x0
0055D797  68e0d55500                       push   0x55d5e0
0055D79C  894508                           mov    DWORD PTR [ebp+0x8],eax
0055D79F  e80c7e1900                       call   0x6f55b0
0055D7A4  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0055D7A7  8b32                             mov    esi,DWORD PTR [edx]
0055D7A9  83c430                           add    esp,0x30
0055D7AC  bf7002c100                       mov    edi,0xc10270
0055D7B1  b8eed8ffff                       mov    eax,0xffffd8ee
0055D7B6  e8d57f1900                       call   0x6f5790
0055D7BB  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0055D7BE  8b4b04                           mov    ecx,DWORD PTR [ebx+0x4]
0055D7C1  50                               push   eax
0055D7C2  e889721900                       call   0x6f4a50
0055D7C7  8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0055D7CA  5f                               pop    edi
0055D7CB  5e                               pop    esi
0055D7CC  5b                               pop    ebx
0055D7CD  8be5                             mov    esp,ebp
0055D7CF  5d                               pop    ebp
0055D7D0  c20800                           ret    0x8

; prepass_register [REUSED_BOUNDARY] 0x55d560..0x55d5de exclusive
0055D560  55                               push   ebp
0055D561  8bec                             mov    ebp,esp
0055D563  83e4f8                           and    esp,0xfffffff8
0055D566  83ec08                           sub    esp,0x8
0055D569  56                               push   esi
0055D56A  57                               push   edi
0055D56B  8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0055D56E  8b4708                           mov    eax,DWORD PTR [edi+0x8]
0055D571  83c0f0                           add    eax,0xfffffff0
0055D574  3dc8bfc000                       cmp    eax,0xc0bfc8
0055D579  745b                             je     0x55d5d6
0055D57B  83780806                         cmp    DWORD PTR [eax+0x8],0x6
0055D57F  7555                             jne    0x55d5d6
0055D581  89442408                         mov    DWORD PTR [esp+0x8],eax
0055D585  2b4720                           sub    eax,DWORD PTR [edi+0x20]
0055D588  33d2                             xor    edx,edx
0055D58A  50                               push   eax
0055D58B  8d44240c                         lea    eax,[esp+0xc]
0055D58F  50                               push   eax
0055D590  68505a6f00                       push   0x6f5a50
0055D595  8bc7                             mov    eax,edi
0055D597  c744241800000000                 mov    DWORD PTR [esp+0x18],0x0
0055D59F  e8cc111a00                       call   0x6fe770
0055D5A4  83c40c                           add    esp,0xc
0055D5A7  85c0                             test   eax,eax
0055D5A9  742b                             je     0x55d5d6
0055D5AB  8b7708                           mov    esi,DWORD PTR [edi+0x8]
0055D5AE  83ee10                           sub    esi,0x10
0055D5B1  837e0804                         cmp    DWORD PTR [esi+0x8],0x4
0055D5B5  741b                             je     0x55d5d2
0055D5B7  e814e01900                       call   0x6fb5d0
0055D5BC  85c0                             test   eax,eax
0055D5BE  7412                             je     0x55d5d2
0055D5C0  8b4710                           mov    eax,DWORD PTR [edi+0x10]
0055D5C3  8b4844                           mov    ecx,DWORD PTR [eax+0x44]
0055D5C6  3b4840                           cmp    ecx,DWORD PTR [eax+0x40]
0055D5C9  7207                             jb     0x55d5d2
0055D5CB  8bc7                             mov    eax,edi
0055D5CD  e8cedd1900                       call   0x6fb3a0
0055D5D2  834708f0                         add    DWORD PTR [edi+0x8],0xfffffff0
0055D5D6  5f                               pop    edi
0055D5D7  33c0                             xor    eax,eax
0055D5D9  5e                               pop    esi
0055D5DA  8be5                             mov    esp,ebp
0055D5DC  5d                               pop    ebp
0055D5DD  c3                               ret

; q_delete_all [REUSED_BODY_NEW_CROSS_RUN_JOIN] 0x563a70..0x563c37 exclusive
00563A70  55                               push   ebp
00563A71  8bec                             mov    ebp,esp
00563A73  83e4f8                           and    esp,0xfffffff8
00563A76  6aff                             push   0xffffffff
00563A78  683e939300                       push   0x93933e
00563A7D  64a100000000                     mov    eax,fs:0x0
00563A83  50                               push   eax
00563A84  83ec18                           sub    esp,0x18
00563A87  53                               push   ebx
00563A88  56                               push   esi
00563A89  57                               push   edi
00563A8A  a1201fd600                       mov    eax,ds:0xd61f20
00563A8F  33c4                             xor    eax,esp
00563A91  50                               push   eax
00563A92  8d442428                         lea    eax,[esp+0x28]
00563A96  64a300000000                     mov    fs:0x0,eax
00563A9C  894c2414                         mov    DWORD PTR [esp+0x14],ecx
00563AA0  8b411c                           mov    eax,DWORD PTR [ecx+0x1c]
00563AA3  8b30                             mov    esi,DWORD PTR [eax]
00563AA5  3bf0                             cmp    esi,eax
00563AA7  746f                             je     0x563b18
00563AA9  8da42400000000                   lea    esp,[esp+0x0]
00563AB0  8b7e10                           mov    edi,DWORD PTR [esi+0x10]
00563AB3  33db                             xor    ebx,ebx
00563AB5  3bfb                             cmp    edi,ebx
00563AB7  7417                             je     0x563ad0
00563AB9  8b07                             mov    eax,DWORD PTR [edi]
00563ABB  8b5014                           mov    edx,DWORD PTR [eax+0x14]
00563ABE  8bcf                             mov    ecx,edi
00563AC0  ffd2                             call   edx
00563AC2  8b07                             mov    eax,DWORD PTR [edi]
00563AC4  8b10                             mov    edx,DWORD PTR [eax]
00563AC6  6a01                             push   0x1
00563AC8  8bcf                             mov    ecx,edi
00563ACA  ffd2                             call   edx
00563ACC  8b4c2414                         mov    ecx,DWORD PTR [esp+0x14]
00563AD0  385e15                           cmp    BYTE PTR [esi+0x15],bl
00563AD3  753c                             jne    0x563b11
00563AD5  8b4608                           mov    eax,DWORD PTR [esi+0x8]
00563AD8  385815                           cmp    BYTE PTR [eax+0x15],bl
00563ADB  7514                             jne    0x563af1
00563ADD  8bf0                             mov    esi,eax
00563ADF  8b06                             mov    eax,DWORD PTR [esi]
00563AE1  385815                           cmp    BYTE PTR [eax+0x15],bl
00563AE4  752b                             jne    0x563b11
00563AE6  8bf0                             mov    esi,eax
00563AE8  8b06                             mov    eax,DWORD PTR [esi]
00563AEA  385815                           cmp    BYTE PTR [eax+0x15],bl
00563AED  74f7                             je     0x563ae6
00563AEF  eb20                             jmp    0x563b11
00563AF1  8b4604                           mov    eax,DWORD PTR [esi+0x4]
00563AF4  385815                           cmp    BYTE PTR [eax+0x15],bl
00563AF7  7516                             jne    0x563b0f
00563AF9  8da42400000000                   lea    esp,[esp+0x0]
00563B00  3b7008                           cmp    esi,DWORD PTR [eax+0x8]
00563B03  750a                             jne    0x563b0f
00563B05  8bf0                             mov    esi,eax
00563B07  8b4004                           mov    eax,DWORD PTR [eax+0x4]
00563B0A  385815                           cmp    BYTE PTR [eax+0x15],bl
00563B0D  74f1                             je     0x563b00
00563B0F  8bf0                             mov    esi,eax
00563B11  3b711c                           cmp    esi,DWORD PTR [ecx+0x1c]
00563B14  759a                             jne    0x563ab0
00563B16  eb02                             jmp    0x563b1a
00563B18  33db                             xor    ebx,ebx
00563B1A  8d7918                           lea    edi,[ecx+0x18]
00563B1D  e82efd2b00                       call   0x823850
00563B22  6a1c                             push   0x1c
00563B24  e83fd73200                       call   0x891268
00563B29  83c404                           add    esp,0x4
00563B2C  3bc3                             cmp    eax,ebx
00563B2E  7411                             je     0x563b41
00563B30  8918                             mov    DWORD PTR [eax],ebx
00563B32  c6400801                         mov    BYTE PTR [eax+0x8],0x1
00563B36  89580c                           mov    DWORD PTR [eax+0xc],ebx
00563B39  895810                           mov    DWORD PTR [eax+0x10],ebx
00563B3C  895814                           mov    DWORD PTR [eax+0x14],ebx
00563B3F  eb02                             jmp    0x563b43
00563B41  33c0                             xor    eax,eax
00563B43  50                               push   eax
00563B44  8d442420                         lea    eax,[esp+0x20]
00563B48  50                               push   eax
00563B49  895c2424                         mov    DWORD PTR [esp+0x24],ebx
00563B4D  895c2428                         mov    DWORD PTR [esp+0x28],ebx
00563B51  e87a85f1ff                       call   0x47c0d0
00563B56  895c2430                         mov    DWORD PTR [esp+0x30],ebx
00563B5A  8b7c241c                         mov    edi,DWORD PTR [esp+0x1c]
00563B5E  83ec08                           sub    esp,0x8
00563B61  c6470801                         mov    BYTE PTR [edi+0x8],0x1
00563B65  8bf4                             mov    esi,esp
00563B67  c7470403000000                   mov    DWORD PTR [edi+0x4],0x3
00563B6E  891e                             mov    DWORD PTR [esi],ebx
00563B70  895e04                           mov    DWORD PTR [esi+0x4],ebx
00563B73  8b5c2428                         mov    ebx,DWORD PTR [esp+0x28]
00563B77  89642420                         mov    DWORD PTR [esp+0x20],esp
00563B7B  85db                             test   ebx,ebx
00563B7D  7412                             je     0x563b91
00563B7F  8bd3                             mov    edx,ebx
00563B81  e8ca86f1ff                       call   0x47c250
00563B86  84c0                             test   al,al
00563B88  7407                             je     0x563b91
00563B8A  53                               push   ebx
00563B8B  57                               push   edi
00563B8C  e82ff62300                       call   0x7a31c0
00563B91  c644243801                       mov    BYTE PTR [esp+0x38],0x1
00563B96  f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
00563B9D  7523                             jne    0x563bc2
00563B9F  830d600ffc0001                   or     DWORD PTR ds:0xfc0f60,0x1
00563BA6  c644243802                       mov    BYTE PTR [esp+0x38],0x2
00563BAB  e890932300                       call   0x79cf40
00563BB0  6880dbbc00                       push   0xbcdb80
00563BB5  e860e73200                       call   0x89231a
00563BBA  83c404                           add    esp,0x4
00563BBD  c644243801                       mov    BYTE PTR [esp+0x38],0x1
00563BC2  b9900efc00                       mov    ecx,0xfc0e90
00563BC7  c644243800                       mov    BYTE PTR [esp+0x38],0x0
00563BCC  e80fa12300                       call   0x79dce0
00563BD1  8bf0                             mov    esi,eax
00563BD3  6aff                             push   0xffffffff
00563BD5  56                               push   esi
00563BD6  ff15fc20bd00                     call   DWORD PTR ds:0xbd20fc
00563BDC  56                               push   esi
00563BDD  ff15c821bd00                     call   DWORD PTR ds:0xbd21c8
00563BE3  8b7c2414                         mov    edi,DWORD PTR [esp+0x14]
00563BE7  83c760                           add    edi,0x60
00563BEA  e831d82e00                       call   0x851420
00563BEF  c7442430ffffffff                 mov    DWORD PTR [esp+0x30],0xffffffff
00563BF7  85db                             test   ebx,ebx
00563BF9  7429                             je     0x563c24
00563BFB  8d4b04                           lea    ecx,[ebx+0x4]
00563BFE  83caff                           or     edx,0xffffffff
00563C01  f00fc111                         lock xadd DWORD PTR [ecx],edx
00563C05  751d                             jne    0x563c24
00563C07  8b03                             mov    eax,DWORD PTR [ebx]
00563C09  8b10                             mov    edx,DWORD PTR [eax]
00563C0B  8bcb                             mov    ecx,ebx
00563C0D  ffd2                             call   edx
00563C0F  8d4308                           lea    eax,[ebx+0x8]
00563C12  83c9ff                           or     ecx,0xffffffff
00563C15  f00fc108                         lock xadd DWORD PTR [eax],ecx
00563C19  7509                             jne    0x563c24
00563C1B  8b13                             mov    edx,DWORD PTR [ebx]
00563C1D  8b4204                           mov    eax,DWORD PTR [edx+0x4]
00563C20  8bcb                             mov    ecx,ebx
00563C22  ffd0                             call   eax
00563C24  8b4c2428                         mov    ecx,DWORD PTR [esp+0x28]
00563C28  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00563C2F  59                               pop    ecx
00563C30  5f                               pop    edi
00563C31  5e                               pop    esi
00563C32  5b                               pop    ebx
00563C33  8be5                             mov    esp,ebp
00563C35  5d                               pop    ebp
00563C36  c3                               ret

; q_create_actor [REUSED_BOUNDARY] 0x562ec0..0x5632c5 exclusive
00562EC0  55                               push   ebp
00562EC1  8bec                             mov    ebp,esp
00562EC3  83e4f8                           and    esp,0xfffffff8
00562EC6  6aff                             push   0xffffffff
00562EC8  6803a19300                       push   0x93a103
00562ECD  64a100000000                     mov    eax,fs:0x0
00562ED3  50                               push   eax
00562ED4  83ec20                           sub    esp,0x20
00562ED7  53                               push   ebx
00562ED8  56                               push   esi
00562ED9  57                               push   edi
00562EDA  a1201fd600                       mov    eax,ds:0xd61f20
00562EDF  33c4                             xor    eax,esp
00562EE1  50                               push   eax
00562EE2  8d442430                         lea    eax,[esp+0x30]
00562EE6  64a300000000                     mov    fs:0x0,eax
00562EEC  894c2418                         mov    DWORD PTR [esp+0x18],ecx
00562EF0  8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
00562EF3  33c0                             xor    eax,eax
00562EF5  6689442414                       mov    WORD PTR [esp+0x14],ax
00562EFA  83ff0a                           cmp    edi,0xa
00562EFD  7d06                             jge    0x562f05
00562EFF  88442414                         mov    BYTE PTR [esp+0x14],al
00562F03  eb40                             jmp    0x562f45
00562F05  81ff10270000                     cmp    edi,0x2710
00562F0B  7d07                             jge    0x562f14
00562F0D  c644241401                       mov    BYTE PTR [esp+0x14],0x1
00562F12  eb31                             jmp    0x562f45
00562F14  81fff82a0000                     cmp    edi,0x2af8
00562F1A  7d07                             jge    0x562f23
00562F1C  c644241406                       mov    BYTE PTR [esp+0x14],0x6
00562F21  eb22                             jmp    0x562f45
00562F23  81ff08520000                     cmp    edi,0x5208
00562F29  7d07                             jge    0x562f32
00562F2B  c644241407                       mov    BYTE PTR [esp+0x14],0x7
00562F30  eb13                             jmp    0x562f45
00562F32  57                               push   edi
00562F33  681807c100                       push   0xc10718
00562F38  e823ac1800                       call   0x6edb60
00562F3D  83c408                           add    esp,0x8
00562F40  c644241400                       mov    BYTE PTR [esp+0x14],0x0
00562F45  8a4d08                           mov    cl,BYTE PTR [ebp+0x8]
00562F48  6838040000                       push   0x438
00562F4D  884c2419                         mov    BYTE PTR [esp+0x19],cl
00562F51  e812e33200                       call   0x891268
00562F56  83c404                           add    esp,0x4
00562F59  89442424                         mov    DWORD PTR [esp+0x24],eax
00562F5D  33db                             xor    ebx,ebx
00562F5F  895c2438                         mov    DWORD PTR [esp+0x38],ebx
00562F63  3bc3                             cmp    eax,ebx
00562F65  7408                             je     0x562f6f
00562F67  50                               push   eax
00562F68  e813dcf6ff                       call   0x4d0b80
00562F6D  8bd8                             mov    ebx,eax
00562F6F  c7442438ffffffff                 mov    DWORD PTR [esp+0x38],0xffffffff
00562F77  668b542414                       mov    dx,WORD PTR [esp+0x14]
00562F7C  0fb6f2                           movzx  esi,dl
00562F7F  0fb7c7                           movzx  eax,di
00562F82  66895304                         mov    WORD PTR [ebx+0x4],dx
00562F86  8b13                             mov    edx,DWORD PTR [ebx]
00562F88  c1e618                           shl    esi,0x18
00562F8B  0bf0                             or     esi,eax
00562F8D  8b423c                           mov    eax,DWORD PTR [edx+0x3c]
00562F90  56                               push   esi
00562F91  8bcb                             mov    ecx,ebx
00562F93  c7839000000010000000             mov    DWORD PTR [ebx+0x90],0x10
00562F9D  ffd0                             call   eax
00562F9F  f30f104510                       movss  xmm0,DWORD PTR [ebp+0x10]
00562FA4  8b13                             mov    edx,DWORD PTR [ebx]
00562FA6  8b5244                           mov    edx,DWORD PTR [edx+0x44]
00562FA9  6a01                             push   0x1
00562FAB  8d442428                         lea    eax,[esp+0x28]
00562FAF  f30f11442428                     movss  DWORD PTR [esp+0x28],xmm0
00562FB5  f30f104514                       movss  xmm0,DWORD PTR [ebp+0x14]
00562FBA  50                               push   eax
00562FBB  8bcb                             mov    ecx,ebx
00562FBD  f30f11442430                     movss  DWORD PTR [esp+0x30],xmm0
00562FC3  ffd2                             call   edx
00562FC5  8b4d18                           mov    ecx,DWORD PTR [ebp+0x18]
00562FC8  8b03                             mov    eax,DWORD PTR [ebx]
00562FCA  8b5058                           mov    edx,DWORD PTR [eax+0x58]
00562FCD  51                               push   ecx
00562FCE  8bcb                             mov    ecx,ebx
00562FD0  ffd2                             call   edx
00562FD2  f605b075fb0001                   test   BYTE PTR ds:0xfb75b0,0x1
00562FD9  7529                             jne    0x563004
00562FDB  b801000000                       mov    eax,0x1
00562FE0  0905b075fb00                     or     DWORD PTR ds:0xfb75b0,eax
00562FE6  89442438                         mov    DWORD PTR [esp+0x38],eax
00562FEA  e8910df9ff                       call   0x4f3d80
00562FEF  68e0d1bc00                       push   0xbcd1e0
00562FF4  e821f33200                       call   0x89231a
00562FF9  83c404                           add    esp,0x4
00562FFC  c7442438ffffffff                 mov    DWORD PTR [esp+0x38],0xffffffff
00563004  8d54241c                         lea    edx,[esp+0x1c]
00563008  b97074fb00                       mov    ecx,0xfb7470
0056300D  8974241c                         mov    DWORD PTR [esp+0x1c],esi
00563011  e85a4af9ff                       call   0x4f7a70
00563016  d9405c                           fld    DWORD PTR [eax+0x5c]
00563019  8b03                             mov    eax,DWORD PTR [ebx]
0056301B  d95c241c                         fstp   DWORD PTR [esp+0x1c]
0056301F  d944241c                         fld    DWORD PTR [esp+0x1c]
00563023  8b505c                           mov    edx,DWORD PTR [eax+0x5c]
00563026  51                               push   ecx
00563027  8bcb                             mov    ecx,ebx
00563029  d91c24                           fstp   DWORD PTR [esp]
0056302C  ffd2                             call   edx
0056302E  8b4d24                           mov    ecx,DWORD PTR [ebp+0x24]
00563031  83ff0a                           cmp    edi,0xa
00563034  7d09                             jge    0x56303f
00563036  85c9                             test   ecx,ecx
00563038  7505                             jne    0x56303f
0056303A  b901000000                       mov    ecx,0x1
0056303F  8b835c010000                     mov    eax,DWORD PTR [ebx+0x15c]
00563045  66898b88030000                   mov    WORD PTR [ebx+0x388],cx
0056304C  85c0                             test   eax,eax
0056304E  7412                             je     0x563062
00563050  83bb7003000000                   cmp    DWORD PTR [ebx+0x370],0x0
00563057  7409                             je     0x563062
00563059  51                               push   ecx
0056305A  6a01                             push   0x1
0056305C  50                               push   eax
0056305D  e83e3e2400                       call   0x7a6ea0
00563062  f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
00563069  7529                             jne    0x563094
0056306B  830d600ffc0001                   or     DWORD PTR ds:0xfc0f60,0x1
00563072  c744243802000000                 mov    DWORD PTR [esp+0x38],0x2
0056307A  e8c19e2300                       call   0x79cf40
0056307F  6880dbbc00                       push   0xbcdb80
00563084  e891f23200                       call   0x89231a
00563089  83c404                           add    esp,0x4
0056308C  c7442438ffffffff                 mov    DWORD PTR [esp+0x38],0xffffffff
00563094  8d44241c                         lea    eax,[esp+0x1c]
00563098  50                               push   eax
00563099  8d442418                         lea    eax,[esp+0x18]
0056309D  b9900efc00                       mov    ecx,0xfc0e90
005630A2  897c2420                         mov    DWORD PTR [esp+0x20],edi
005630A6  e8e526fbff                       call   0x515790
005630AB  8b442414                         mov    eax,DWORD PTR [esp+0x14]
005630AF  3b05940efc00                     cmp    eax,DWORD PTR ds:0xfc0e94
005630B5  7409                             je     0x5630c0
005630B7  8b4010                           mov    eax,DWORD PTR [eax+0x10]
005630BA  83785400                         cmp    DWORD PTR [eax+0x54],0x0
005630BE  7553                             jne    0x563113
005630C0  8b742418                         mov    esi,DWORD PTR [esp+0x18]
005630C4  8d4d0c                           lea    ecx,[ebp+0xc]
005630C7  83c660                           add    esi,0x60
005630CA  51                               push   ecx
005630CB  e870ad1500                       call   0x6bde40
005630D0  50                               push   eax
005630D1  56                               push   esi
005630D2  8d74242c                         lea    esi,[esp+0x2c]
005630D6  e8f58aeeff                       call   0x44bbd0
005630DB  f605400efc0001                   test   BYTE PTR ds:0xfc0e40,0x1
005630E2  7529                             jne    0x56310d
005630E4  830d400efc0001                   or     DWORD PTR ds:0xfc0e40,0x1
005630EB  c744243803000000                 mov    DWORD PTR [esp+0x38],0x3
005630F3  e878d6fdff                       call   0x540770
005630F8  6860dbbc00                       push   0xbcdb60
005630FD  e818f23200                       call   0x89231a
00563102  83c404                           add    esp,0x4
00563105  c7442438ffffffff                 mov    DWORD PTR [esp+0x38],0xffffffff
0056310D  57                               push   edi
0056310E  e8fde4fdff                       call   0x541610
00563113  8b542418                         mov    edx,DWORD PTR [esp+0x18]
00563117  837a7000                         cmp    DWORD PTR [edx+0x70],0x0
0056311B  0f840b010000                     je     0x56322c
00563121  f605600ffc0001                   test   BYTE PTR ds:0xfc0f60,0x1
00563128  7529                             jne    0x563153
0056312A  830d600ffc0001                   or     DWORD PTR ds:0xfc0f60,0x1
00563131  c744243804000000                 mov    DWORD PTR [esp+0x38],0x4
00563139  e8029e2300                       call   0x79cf40
0056313E  6880dbbc00                       push   0xbcdb80
00563143  e8d2f13200                       call   0x89231a
00563148  83c404                           add    esp,0x4
0056314B  c7442438ffffffff                 mov    DWORD PTR [esp+0x38],0xffffffff
00563153  8d44241c                         lea    eax,[esp+0x1c]
00563157  50                               push   eax
00563158  8d442418                         lea    eax,[esp+0x18]
0056315C  b9900efc00                       mov    ecx,0xfc0e90
00563161  897c2420                         mov    DWORD PTR [esp+0x20],edi
00563165  e82626fbff                       call   0x515790
0056316A  8b442414                         mov    eax,DWORD PTR [esp+0x14]
0056316E  3b05940efc00                     cmp    eax,DWORD PTR ds:0xfc0e94
00563174  0f84b2000000                     je     0x56322c
0056317A  8b4810                           mov    ecx,DWORD PTR [eax+0x10]
0056317D  8b7154                           mov    esi,DWORD PTR [ecx+0x54]
00563180  85f6                             test   esi,esi
00563182  0f84a4000000                     je     0x56322c
00563188  6a01                             push   0x1
0056318A  8bfe                             mov    edi,esi
0056318C  e85f262600                       call   0x7c57f0
00563191  6a04                             push   0x4
00563193  e858262600                       call   0x7c57f0
00563198  8b442418                         mov    eax,DWORD PTR [esp+0x18]
0056319C  0fb75508                         movzx  edx,WORD PTR [ebp+0x8]
005631A0  8b7870                           mov    edi,DWORD PTR [eax+0x70]
005631A3  8d4c241c                         lea    ecx,[esp+0x1c]
005631A7  51                               push   ecx
005631A8  8d442418                         lea    eax,[esp+0x18]
005631AC  8bcf                             mov    ecx,edi
005631AE  89542420                         mov    DWORD PTR [esp+0x20],edx
005631B2  e8c9302c00                       call   0x826280
005631B7  8b442414                         mov    eax,DWORD PTR [esp+0x14]
005631BB  3b4704                           cmp    eax,DWORD PTR [edi+0x4]
005631BE  746c                             je     0x56322c
005631C0  8b4010                           mov    eax,DWORD PTR [eax+0x10]
005631C3  8b4808                           mov    ecx,DWORD PTR [eax+0x8]
005631C6  89442424                         mov    DWORD PTR [esp+0x24],eax
005631CA  8b01                             mov    eax,DWORD PTR [ecx]
005631CC  8944241c                         mov    DWORD PTR [esp+0x1c],eax
005631D0  3bc1                             cmp    eax,ecx
005631D2  7458                             je     0x56322c
005631D4  0fb7500c                         movzx  edx,WORD PTR [eax+0xc]
005631D8  8d442414                         lea    eax,[esp+0x14]
005631DC  50                               push   eax
005631DD  8d442424                         lea    eax,[esp+0x24]
005631E1  8d8ed4000000                     lea    ecx,[esi+0xd4]
005631E7  89542418                         mov    DWORD PTR [esp+0x18],edx
005631EB  e810bd2c00                       call   0x82ef00
005631F0  8b7c2420                         mov    edi,DWORD PTR [esp+0x20]
005631F4  3bbed8000000                     cmp    edi,DWORD PTR [esi+0xd8]
005631FA  741a                             je     0x563216
005631FC  8b4f10                           mov    ecx,DWORD PTR [edi+0x10]
005631FF  8b11                             mov    edx,DWORD PTR [ecx]
00563201  8b4208                           mov    eax,DWORD PTR [edx+0x8]
00563204  ffd0                             call   eax
00563206  3b442414                         cmp    eax,DWORD PTR [esp+0x14]
0056320A  750a                             jne    0x563216
0056320C  8b4f10                           mov    ecx,DWORD PTR [edi+0x10]
0056320F  8b11                             mov    edx,DWORD PTR [ecx]
00563211  8b4224                           mov    eax,DWORD PTR [edx+0x24]
00563214  ffd0                             call   eax
00563216  8d44241c                         lea    eax,[esp+0x1c]
0056321A  e831a62b00                       call   0x81d850
0056321F  8b44241c                         mov    eax,DWORD PTR [esp+0x1c]
00563223  8b4c2424                         mov    ecx,DWORD PTR [esp+0x24]
00563227  3b4108                           cmp    eax,DWORD PTR [ecx+0x8]
0056322A  75a8                             jne    0x5631d4
0056322C  8bf3                             mov    esi,ebx
0056322E  e8adddf6ff                       call   0x4d0fe0
00563233  8b93f0000000                     mov    edx,DWORD PTR [ebx+0xf0]
00563239  8b4208                           mov    eax,DWORD PTR [edx+0x8]
0056323C  8d8bf0000000                     lea    ecx,[ebx+0xf0]
00563242  6a14                             push   0x14
00563244  ffd0                             call   eax
00563246  d9e8                             fld1
00563248  8b13                             mov    edx,DWORD PTR [ebx]
0056324A  8b451c                           mov    eax,DWORD PTR [ebp+0x1c]
0056324D  8b5268                           mov    edx,DWORD PTR [edx+0x68]
00563250  51                               push   ecx
00563251  d91c24                           fstp   DWORD PTR [esp]
00563254  50                               push   eax
00563255  8bcb                             mov    ecx,ebx
00563257  ffd2                             call   edx
00563259  8b4d28                           mov    ecx,DWORD PTR [ebp+0x28]
0056325C  85c9                             test   ecx,ecx
0056325E  7421                             je     0x563281
00563260  8b835c010000                     mov    eax,DWORD PTR [ebx+0x15c]
00563266  85c0                             test   eax,eax
00563268  7417                             je     0x563281
0056326A  83bb7003000000                   cmp    DWORD PTR [ebx+0x370],0x0
00563271  740e                             je     0x563281
00563273  6a00                             push   0x0
00563275  0fb7c9                           movzx  ecx,cx
00563278  6a00                             push   0x0
0056327A  51                               push   ecx
0056327B  50                               push   eax
0056327C  e8bf3f2400                       call   0x7a7240
00563281  8b5520                           mov    edx,DWORD PTR [ebp+0x20]
00563284  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
00563287  8b742418                         mov    esi,DWORD PTR [esp+0x18]
0056328B  83c618                           add    esi,0x18
0056328E  8d7c2424                         lea    edi,[esp+0x24]
00563292  89932c040000                     mov    DWORD PTR [ebx+0x42c],edx
00563298  89442424                         mov    DWORD PTR [esp+0x24],eax
0056329C  895c2428                         mov    DWORD PTR [esp+0x28],ebx
005632A0  e87bbc0100                       call   0x57ef20
005632A5  50                               push   eax
005632A6  56                               push   esi
005632A7  8d74242c                         lea    esi,[esp+0x2c]
005632AB  e850bf2c00                       call   0x82f200
005632B0  8b4c2430                         mov    ecx,DWORD PTR [esp+0x30]
005632B4  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
005632BB  59                               pop    ecx
005632BC  5f                               pop    edi
005632BD  5e                               pop    esi
005632BE  5b                               pop    ebx
005632BF  8be5                             mov    esp,ebp
005632C1  5d                               pop    ebp
005632C2  c22400                           ret    0x24

; q_flying_create [ERRATUM_REJOIN] 0x564940..0x564a5b exclusive
00564940  55                               push   ebp
00564941  8bec                             mov    ebp,esp
00564943  6aff                             push   0xffffffff
00564945  68b9de9100                       push   0x91deb9
0056494A  64a100000000                     mov    eax,fs:0x0
00564950  50                               push   eax
00564951  83ec10                           sub    esp,0x10
00564954  53                               push   ebx
00564955  56                               push   esi
00564956  57                               push   edi
00564957  a1201fd600                       mov    eax,ds:0xd61f20
0056495C  33c5                             xor    eax,ebp
0056495E  50                               push   eax
0056495F  8d45f4                           lea    eax,[ebp-0xc]
00564962  64a300000000                     mov    fs:0x0,eax
00564968  8bd9                             mov    ebx,ecx
0056496A  e8f1000000                       call   0x564a60
0056496F  6a70                             push   0x70
00564971  e8f2c83200                       call   0x891268
00564976  8bf0                             mov    esi,eax
00564978  83c404                           add    esp,0x4
0056497B  8975ec                           mov    DWORD PTR [ebp-0x14],esi
0056497E  33ff                             xor    edi,edi
00564980  897dfc                           mov    DWORD PTR [ebp-0x4],edi
00564983  3bf7                             cmp    esi,edi
00564985  7433                             je     0x5649ba
00564987  397d20                           cmp    DWORD PTR [ebp+0x20],edi
0056498A  7405                             je     0x564991
0056498C  83c8ff                           or     eax,0xffffffff
0056498F  eb03                             jmp    0x564994
00564991  8b4518                           mov    eax,DWORD PTR [ebp+0x18]
00564994  8b4d1c                           mov    ecx,DWORD PTR [ebp+0x1c]
00564997  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0056499A  57                               push   edi
0056499B  51                               push   ecx
0056499C  8b4d14                           mov    ecx,DWORD PTR [ebp+0x14]
0056499F  50                               push   eax
005649A0  56                               push   esi
005649A1  e8eaf4feff                       call   0x553e90
005649A6  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
005649A9  8b4510                           mov    eax,DWORD PTR [ebp+0x10]
005649AC  c7064807c100                     mov    DWORD PTR [esi],0xc10748
005649B2  895668                           mov    DWORD PTR [esi+0x68],edx
005649B5  89466c                           mov    DWORD PTR [esi+0x6c],eax
005649B8  eb02                             jmp    0x5649bc
005649BA  33f6                             xor    esi,esi
005649BC  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
005649C3  f6055473fb0001                   test   BYTE PTR ds:0xfb7354,0x1
005649CA  7527                             jne    0x5649f3
005649CC  b801000000                       mov    eax,0x1
005649D1  09055473fb00                     or     DWORD PTR ds:0xfb7354,eax
005649D7  8945fc                           mov    DWORD PTR [ebp-0x4],eax
005649DA  e8f1e9feff                       call   0x5533d0
005649DF  6800d1bc00                       push   0xbcd100
005649E4  e831d93200                       call   0x89231a
005649E9  83c404                           add    esp,0x4
005649EC  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
005649F3  8b16                             mov    edx,DWORD PTR [esi]
005649F5  8b4204                           mov    eax,DWORD PTR [edx+0x4]
005649F8  8bce                             mov    ecx,esi
005649FA  ffd0                             call   eax
005649FC  a1b073fb00                       mov    eax,ds:0xfb73b0
00564A01  8b0dac73fb00                     mov    ecx,DWORD PTR ds:0xfb73ac
00564A07  8b16                             mov    edx,DWORD PTR [esi]
00564A09  8b5220                           mov    edx,DWORD PTR [edx+0x20]
00564A0C  50                               push   eax
00564A0D  51                               push   ecx
00564A0E  8bce                             mov    ecx,esi
00564A10  ffd2                             call   edx
00564A12  897e40                           mov    DWORD PTR [esi+0x40],edi
00564A15  a19873fb00                       mov    eax,ds:0xfb7398
00564A1A  8975ec                           mov    DWORD PTR [ebp-0x14],esi
00564A1D  8d7de8                           lea    edi,[ebp-0x18]
00564A20  be5873fb00                       mov    esi,0xfb7358
00564A25  8945e8                           mov    DWORD PTR [ebp-0x18],eax
00564A28  e8f3a40100                       call   0x57ef20
00564A2D  50                               push   eax
00564A2E  56                               push   esi
00564A2F  8d75e8                           lea    esi,[ebp-0x18]
00564A32  e8c9a72c00                       call   0x82f200
00564A37  a19873fb00                       mov    eax,ds:0xfb7398
00564A3C  8bc8                             mov    ecx,eax
00564A3E  40                               inc    eax
00564A3F  a39873fb00                       mov    ds:0xfb7398,eax
00564A44  894b40                           mov    DWORD PTR [ebx+0x40],ecx
00564A47  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
00564A4A  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00564A51  59                               pop    ecx
00564A52  5f                               pop    edi
00564A53  5e                               pop    esi
00564A54  5b                               pop    ebx
00564A55  8be5                             mov    esp,ebp
00564A57  5d                               pop    ebp
00564A58  c21c00                           ret    0x1c

; q_flying_cancel [ERRATUM_REJOIN] 0x564a60..0x564afb exclusive
00564A60  55                               push   ebp
00564A61  8bec                             mov    ebp,esp
00564A63  6aff                             push   0xffffffff
00564A65  68eece9000                       push   0x90ceee
00564A6A  64a100000000                     mov    eax,fs:0x0
00564A70  50                               push   eax
00564A71  83ec08                           sub    esp,0x8
00564A74  56                               push   esi
00564A75  a1201fd600                       mov    eax,ds:0xd61f20
00564A7A  33c5                             xor    eax,ebp
00564A7C  50                               push   eax
00564A7D  8d45f4                           lea    eax,[ebp-0xc]
00564A80  64a300000000                     mov    fs:0x0,eax
00564A86  8bf1                             mov    esi,ecx
00564A88  b801000000                       mov    eax,0x1
00564A8D  84055473fb00                     test   BYTE PTR ds:0xfb7354,al
00564A93  751f                             jne    0x564ab4
00564A95  09055473fb00                     or     DWORD PTR ds:0xfb7354,eax
00564A9B  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
00564AA2  e829e9feff                       call   0x5533d0
00564AA7  6800d1bc00                       push   0xbcd100
00564AAC  e869d83200                       call   0x89231a
00564AB1  83c404                           add    esp,0x4
00564AB4  8b4640                           mov    eax,DWORD PTR [esi+0x40]
00564AB7  8d4df0                           lea    ecx,[ebp-0x10]
00564ABA  8945f0                           mov    DWORD PTR [ebp-0x10],eax
00564ABD  51                               push   ecx
00564ABE  8d45ec                           lea    eax,[ebp-0x14]
00564AC1  b95873fb00                       mov    ecx,0xfb7358
00564AC6  e835a42c00                       call   0x82ef00
00564ACB  8b45ec                           mov    eax,DWORD PTR [ebp-0x14]
00564ACE  3b055c73fb00                     cmp    eax,DWORD PTR ds:0xfb735c
00564AD4  740e                             je     0x564ae4
00564AD6  8b4010                           mov    eax,DWORD PTR [eax+0x10]
00564AD9  85c0                             test   eax,eax
00564ADB  7407                             je     0x564ae4
00564ADD  c7401400000000                   mov    DWORD PTR [eax+0x14],0x0
00564AE4  c74640ffffffff                   mov    DWORD PTR [esi+0x40],0xffffffff
00564AEB  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
00564AEE  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
00564AF5  59                               pop    ecx
00564AF6  5e                               pop    esi
00564AF7  8be5                             mov    esp,ebp
00564AF9  5d                               pop    ebp
00564AFA  c3                               ret

; model_replace_worker [NEW_DOWNSTREAM_JOIN] 0x7a03b0..0x7a0a85 exclusive
007A03B0  55                               push   ebp
007A03B1  8bec                             mov    ebp,esp
007A03B3  6aff                             push   0xffffffff
007A03B5  681a8e9300                       push   0x938e1a
007A03BA  64a100000000                     mov    eax,fs:0x0
007A03C0  50                               push   eax
007A03C1  83ec68                           sub    esp,0x68
007A03C4  53                               push   ebx
007A03C5  56                               push   esi
007A03C6  57                               push   edi
007A03C7  a1201fd600                       mov    eax,ds:0xd61f20
007A03CC  33c5                             xor    eax,ebp
007A03CE  50                               push   eax
007A03CF  8d45f4                           lea    eax,[ebp-0xc]
007A03D2  64a300000000                     mov    fs:0x0,eax
007A03D8  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
007A03DB  33f6                             xor    esi,esi
007A03DD  8975fc                           mov    DWORD PTR [ebp-0x4],esi
007A03E0  8975e8                           mov    DWORD PTR [ebp-0x18],esi
007A03E3  397048                           cmp    DWORD PTR [eax+0x48],esi
007A03E6  7403                             je     0x7a03eb
007A03E8  8975e8                           mov    DWORD PTR [ebp-0x18],esi
007A03EB  397050                           cmp    DWORD PTR [eax+0x50],esi
007A03EE  7407                             je     0x7a03f7
007A03F0  c745e801000000                   mov    DWORD PTR [ebp-0x18],0x1
007A03F7  397058                           cmp    DWORD PTR [eax+0x58],esi
007A03FA  7407                             je     0x7a0403
007A03FC  c745e802000000                   mov    DWORD PTR [ebp-0x18],0x2
007A0403  8b4060                           mov    eax,DWORD PTR [eax+0x60]
007A0406  3bc6                             cmp    eax,esi
007A0408  7407                             je     0x7a0411
007A040A  c745e803000000                   mov    DWORD PTR [ebp-0x18],0x3
007A0411  6a14                             push   0x14
007A0413  897594                           mov    DWORD PTR [ebp-0x6c],esi
007A0416  e84d0e0f00                       call   0x891268
007A041B  83c404                           add    esp,0x4
007A041E  3bc6                             cmp    eax,esi
007A0420  0f843b060000                     je     0x7a0a61
007A0426  894590                           mov    DWORD PTR [ebp-0x70],eax
007A0429  8900                             mov    DWORD PTR [eax],eax
007A042B  8b4590                           mov    eax,DWORD PTR [ebp-0x70]
007A042E  894004                           mov    DWORD PTR [eax+0x4],eax
007A0431  8b4590                           mov    eax,DWORD PTR [ebp-0x70]
007A0434  894008                           mov    DWORD PTR [eax+0x8],eax
007A0437  8b4590                           mov    eax,DWORD PTR [ebp-0x70]
007A043A  c6401001                         mov    BYTE PTR [eax+0x10],0x1
007A043E  8b4d90                           mov    ecx,DWORD PTR [ebp-0x70]
007A0441  c6411101                         mov    BYTE PTR [ecx+0x11],0x1
007A0445  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
007A0449  8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
007A044C  807f0800                         cmp    BYTE PTR [edi+0x8],0x0
007A0450  0f8474010000                     je     0x7a05ca
007A0456  8b7f04                           mov    edi,DWORD PTR [edi+0x4]
007A0459  81ffff000000                     cmp    edi,0xff
007A045F  7508                             jne    0x7a0469
007A0461  8b55e8                           mov    edx,DWORD PTR [ebp-0x18]
007A0464  8955e0                           mov    DWORD PTR [ebp-0x20],edx
007A0467  eb03                             jmp    0x7a046c
007A0469  897de0                           mov    DWORD PTR [ebp-0x20],edi
007A046C  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
007A046F  83c048                           add    eax,0x48
007A0472  c745e400000000                   mov    DWORD PTR [ebp-0x1c],0x0
007A0479  8945ec                           mov    DWORD PTR [ebp-0x14],eax
007A047C  8d642400                         lea    esp,[esp+0x0]
007A0480  8b45ec                           mov    eax,DWORD PTR [ebp-0x14]
007A0483  8b00                             mov    eax,DWORD PTR [eax]
007A0485  85c0                             test   eax,eax
007A0487  0f8426010000                     je     0x7a05b3
007A048D  8b4de0                           mov    ecx,DWORD PTR [ebp-0x20]
007A0490  394de4                           cmp    DWORD PTR [ebp-0x1c],ecx
007A0493  0f821a010000                     jb     0x7a05b3
007A0499  8b5010                           mov    edx,DWORD PTR [eax+0x10]
007A049C  2b500c                           sub    edx,DWORD PTR [eax+0xc]
007A049F  33db                             xor    ebx,ebx
007A04A1  c1fa02                           sar    edx,0x2
007A04A4  85d2                             test   edx,edx
007A04A6  0f84b6000000                     je     0x7a0562
007A04AC  8d642400                         lea    esp,[esp+0x0]
007A04B0  8b400c                           mov    eax,DWORD PTR [eax+0xc]
007A04B3  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
007A04B6  8b4904                           mov    ecx,DWORD PTR [ecx+0x4]
007A04B9  8d3c9d00000000                   lea    edi,[ebx*4+0x0]
007A04C0  8b3407                           mov    esi,DWORD PTR [edi+eax*1]
007A04C3  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
007A04C6  80781900                         cmp    BYTE PTR [eax+0x19],0x0
007A04CA  8bd1                             mov    edx,ecx
007A04CC  7516                             jne    0x7a04e4
007A04CE  8bff                             mov    edi,edi
007A04D0  39700c                           cmp    DWORD PTR [eax+0xc],esi
007A04D3  7305                             jae    0x7a04da
007A04D5  8b4008                           mov    eax,DWORD PTR [eax+0x8]
007A04D8  eb04                             jmp    0x7a04de
007A04DA  8bd0                             mov    edx,eax
007A04DC  8b00                             mov    eax,DWORD PTR [eax]
007A04DE  80781900                         cmp    BYTE PTR [eax+0x19],0x0
007A04E2  74ec                             je     0x7a04d0
007A04E4  8955dc                           mov    DWORD PTR [ebp-0x24],edx
007A04E7  3bd1                             cmp    edx,ecx
007A04E9  740a                             je     0x7a04f5
007A04EB  3b720c                           cmp    esi,DWORD PTR [edx+0xc]
007A04EE  7205                             jb     0x7a04f5
007A04F0  8d45dc                           lea    eax,[ebp-0x24]
007A04F3  eb06                             jmp    0x7a04fb
007A04F5  894dd8                           mov    DWORD PTR [ebp-0x28],ecx
007A04F8  8d45d8                           lea    eax,[ebp-0x28]
007A04FB  8b00                             mov    eax,DWORD PTR [eax]
007A04FD  3bc1                             cmp    eax,ecx
007A04FF  742b                             je     0x7a052c
007A0501  8b4010                           mov    eax,DWORD PTR [eax+0x10]
007A0504  8b7054                           mov    esi,DWORD PTR [eax+0x54]
007A0507  85f6                             test   esi,esi
007A0509  7421                             je     0x7a052c
007A050B  837e5010                         cmp    DWORD PTR [esi+0x50],0x10
007A050F  8d463c                           lea    eax,[esi+0x3c]
007A0512  7202                             jb     0x7a0516
007A0514  8b00                             mov    eax,DWORD PTR [eax]
007A0516  8b565c                           mov    edx,DWORD PTR [esi+0x5c]
007A0519  4a                               dec    edx
007A051A  52                               push   edx
007A051B  50                               push   eax
007A051C  6834fec400                       push   0xc4fe34
007A0521  e8972b0f00                       call   0x8930bd
007A0526  83c40c                           add    esp,0xc
007A0529  ff4e5c                           dec    DWORD PTR [esi+0x5c]
007A052C  8b45ec                           mov    eax,DWORD PTR [ebp-0x14]
007A052F  8b00                             mov    eax,DWORD PTR [eax]
007A0531  8b400c                           mov    eax,DWORD PTR [eax+0xc]
007A0534  03c7                             add    eax,edi
007A0536  50                               push   eax
007A0537  8d758c                           lea    esi,[ebp-0x74]
007A053A  e801d9f1ff                       call   0x6bde40
007A053F  8bce                             mov    ecx,esi
007A0541  50                               push   eax
007A0542  51                               push   ecx
007A0543  8d75b0                           lea    esi,[ebp-0x50]
007A0546  e885b6caff                       call   0x44bbd0
007A054B  8b55ec                           mov    edx,DWORD PTR [ebp-0x14]
007A054E  8b02                             mov    eax,DWORD PTR [edx]
007A0550  8b4810                           mov    ecx,DWORD PTR [eax+0x10]
007A0553  2b480c                           sub    ecx,DWORD PTR [eax+0xc]
007A0556  43                               inc    ebx
007A0557  c1f902                           sar    ecx,0x2
007A055A  3bd9                             cmp    ebx,ecx
007A055C  0f824effffff                     jb     0x7a04b0
007A0562  8b55e4                           mov    edx,DWORD PTR [ebp-0x1c]
007A0565  52                               push   edx
007A0566  68f0f4c400                       push   0xc4f4f0
007A056B  e84d2b0f00                       call   0x8930bd
007A0570  8b45ec                           mov    eax,DWORD PTR [ebp-0x14]
007A0573  8b7004                           mov    esi,DWORD PTR [eax+0x4]
007A0576  83c408                           add    esp,0x8
007A0579  c7400400000000                   mov    DWORD PTR [eax+0x4],0x0
007A0580  c70000000000                     mov    DWORD PTR [eax],0x0
007A0586  85f6                             test   esi,esi
007A0588  7429                             je     0x7a05b3
007A058A  8d4604                           lea    eax,[esi+0x4]
007A058D  83c9ff                           or     ecx,0xffffffff
007A0590  f00fc108                         lock xadd DWORD PTR [eax],ecx
007A0594  751d                             jne    0x7a05b3
007A0596  8b16                             mov    edx,DWORD PTR [esi]
007A0598  8b02                             mov    eax,DWORD PTR [edx]
007A059A  8bce                             mov    ecx,esi
007A059C  ffd0                             call   eax
007A059E  8d4e08                           lea    ecx,[esi+0x8]
007A05A1  83caff                           or     edx,0xffffffff
007A05A4  f00fc111                         lock xadd DWORD PTR [ecx],edx
007A05A8  7509                             jne    0x7a05b3
007A05AA  8b06                             mov    eax,DWORD PTR [esi]
007A05AC  8b5004                           mov    edx,DWORD PTR [eax+0x4]
007A05AF  8bce                             mov    ecx,esi
007A05B1  ffd2                             call   edx
007A05B3  8b45e4                           mov    eax,DWORD PTR [ebp-0x1c]
007A05B6  8345ec08                         add    DWORD PTR [ebp-0x14],0x8
007A05BA  40                               inc    eax
007A05BB  8945e4                           mov    DWORD PTR [ebp-0x1c],eax
007A05BE  83f804                           cmp    eax,0x4
007A05C1  0f82b9feffff                     jb     0x7a0480
007A05C7  8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
007A05CA  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
007A05CD  83784800                         cmp    DWORD PTR [eax+0x48],0x0
007A05D1  7404                             je     0x7a05d7
007A05D3  33c9                             xor    ecx,ecx
007A05D5  eb03                             jmp    0x7a05da
007A05D7  8b4de8                           mov    ecx,DWORD PTR [ebp-0x18]
007A05DA  83785000                         cmp    DWORD PTR [eax+0x50],0x0
007A05DE  7405                             je     0x7a05e5
007A05E0  b901000000                       mov    ecx,0x1
007A05E5  83785800                         cmp    DWORD PTR [eax+0x58],0x0
007A05E9  7405                             je     0x7a05f0
007A05EB  b902000000                       mov    ecx,0x2
007A05F0  83786000                         cmp    DWORD PTR [eax+0x60],0x0
007A05F4  7405                             je     0x7a05fb
007A05F6  b903000000                       mov    ecx,0x3
007A05FB  8b4704                           mov    eax,DWORD PTR [edi+0x4]
007A05FE  894dec                           mov    DWORD PTR [ebp-0x14],ecx
007A0601  3dff000000                       cmp    eax,0xff
007A0606  7403                             je     0x7a060b
007A0608  8945ec                           mov    DWORD PTR [ebp-0x14],eax
007A060B  8b4710                           mov    eax,DWORD PTR [edi+0x10]
007A060E  2b470c                           sub    eax,DWORD PTR [edi+0xc]
007A0611  33db                             xor    ebx,ebx
007A0613  c1f802                           sar    eax,0x2
007A0616  895de0                           mov    DWORD PTR [ebp-0x20],ebx
007A0619  85c0                             test   eax,eax
007A061B  0f841f010000                     je     0x7a0740
007A0621  8b4f0c                           mov    ecx,DWORD PTR [edi+0xc]
007A0624  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
007A0627  8d3499                           lea    esi,[ecx+ebx*4]
007A062A  8b4a04                           mov    ecx,DWORD PTR [edx+0x4]
007A062D  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
007A0630  80781900                         cmp    BYTE PTR [eax+0x19],0x0
007A0634  8bd1                             mov    edx,ecx
007A0636  751f                             jne    0x7a0657
007A0638  8b1e                             mov    ebx,DWORD PTR [esi]
007A063A  8d9b00000000                     lea    ebx,[ebx+0x0]
007A0640  39580c                           cmp    DWORD PTR [eax+0xc],ebx
007A0643  7305                             jae    0x7a064a
007A0645  8b4008                           mov    eax,DWORD PTR [eax+0x8]
007A0648  eb04                             jmp    0x7a064e
007A064A  8bd0                             mov    edx,eax
007A064C  8b00                             mov    eax,DWORD PTR [eax]
007A064E  80781900                         cmp    BYTE PTR [eax+0x19],0x0
007A0652  74ec                             je     0x7a0640
007A0654  8b5de0                           mov    ebx,DWORD PTR [ebp-0x20]
007A0657  8955e0                           mov    DWORD PTR [ebp-0x20],edx
007A065A  3bd1                             cmp    edx,ecx
007A065C  740c                             je     0x7a066a
007A065E  8b06                             mov    eax,DWORD PTR [esi]
007A0660  3b420c                           cmp    eax,DWORD PTR [edx+0xc]
007A0663  7205                             jb     0x7a066a
007A0665  8d45e0                           lea    eax,[ebp-0x20]
007A0668  eb06                             jmp    0x7a0670
007A066A  894de4                           mov    DWORD PTR [ebp-0x1c],ecx
007A066D  8d45e4                           lea    eax,[ebp-0x1c]
007A0670  8b00                             mov    eax,DWORD PTR [eax]
007A0672  3bc1                             cmp    eax,ecx
007A0674  0f84b1000000                     je     0x7a072b
007A067A  8b4010                           mov    eax,DWORD PTR [eax+0x10]
007A067D  83785400                         cmp    DWORD PTR [eax+0x54],0x0
007A0681  750e                             jne    0x7a0691
007A0683  8b0e                             mov    ecx,DWORD PTR [esi]
007A0685  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
007A0688  51                               push   ecx
007A0689  e8e2ceffff                       call   0x79d570
007A068E  8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
007A0691  8b4508                           mov    eax,DWORD PTR [ebp+0x8]
007A0694  8b4804                           mov    ecx,DWORD PTR [eax+0x4]
007A0697  8b570c                           mov    edx,DWORD PTR [edi+0xc]
007A069A  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
007A069D  80781900                         cmp    BYTE PTR [eax+0x19],0x0
007A06A1  8b349a                           mov    esi,DWORD PTR [edx+ebx*4]
007A06A4  8bd1                             mov    edx,ecx
007A06A6  7514                             jne    0x7a06bc
007A06A8  39700c                           cmp    DWORD PTR [eax+0xc],esi
007A06AB  7305                             jae    0x7a06b2
007A06AD  8b4008                           mov    eax,DWORD PTR [eax+0x8]
007A06B0  eb04                             jmp    0x7a06b6
007A06B2  8bd0                             mov    edx,eax
007A06B4  8b00                             mov    eax,DWORD PTR [eax]
007A06B6  80781900                         cmp    BYTE PTR [eax+0x19],0x0
007A06BA  74ec                             je     0x7a06a8
007A06BC  8955e8                           mov    DWORD PTR [ebp-0x18],edx
007A06BF  3bd1                             cmp    edx,ecx
007A06C1  740a                             je     0x7a06cd
007A06C3  3b720c                           cmp    esi,DWORD PTR [edx+0xc]
007A06C6  7205                             jb     0x7a06cd
007A06C8  8d45e8                           lea    eax,[ebp-0x18]
007A06CB  eb06                             jmp    0x7a06d3
007A06CD  894dd4                           mov    DWORD PTR [ebp-0x2c],ecx
007A06D0  8d45d4                           lea    eax,[ebp-0x2c]
007A06D3  8b00                             mov    eax,DWORD PTR [eax]
007A06D5  3bc1                             cmp    eax,ecx
007A06D7  742e                             je     0x7a0707
007A06D9  8b4010                           mov    eax,DWORD PTR [eax+0x10]
007A06DC  8b7054                           mov    esi,DWORD PTR [eax+0x54]
007A06DF  85f6                             test   esi,esi
007A06E1  7424                             je     0x7a0707
007A06E3  837e5010                         cmp    DWORD PTR [esi+0x50],0x10
007A06E7  8d463c                           lea    eax,[esi+0x3c]
007A06EA  7202                             jb     0x7a06ee
007A06EC  8b00                             mov    eax,DWORD PTR [eax]
007A06EE  8b4e5c                           mov    ecx,DWORD PTR [esi+0x5c]
007A06F1  41                               inc    ecx
007A06F2  51                               push   ecx
007A06F3  50                               push   eax
007A06F4  6824fec400                       push   0xc4fe24
007A06F9  e8bf290f00                       call   0x8930bd
007A06FE  83c40c                           add    esp,0xc
007A0701  ff465c                           inc    DWORD PTR [esi+0x5c]
007A0704  8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
007A0707  8b470c                           mov    eax,DWORD PTR [edi+0xc]
007A070A  8d0c9d00000000                   lea    ecx,[ebx*4+0x0]
007A0711  03c1                             add    eax,ecx
007A0713  50                               push   eax
007A0714  8d758c                           lea    esi,[ebp-0x74]
007A0717  e824d7f1ff                       call   0x6bde40
007A071C  8bd6                             mov    edx,esi
007A071E  50                               push   eax
007A071F  52                               push   edx
007A0720  8d75a8                           lea    esi,[ebp-0x58]
007A0723  e8a8b4caff                       call   0x44bbd0
007A0728  8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
007A072B  8b4710                           mov    eax,DWORD PTR [edi+0x10]
007A072E  2b470c                           sub    eax,DWORD PTR [edi+0xc]
007A0731  43                               inc    ebx
007A0732  c1f802                           sar    eax,0x2
007A0735  895de0                           mov    DWORD PTR [ebp-0x20],ebx
007A0738  3bd8                             cmp    ebx,eax
007A073A  0f82e1feffff                     jb     0x7a0621
007A0740  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
007A0743  8b55ec                           mov    edx,DWORD PTR [ebp-0x14]
007A0746  837cd14800                       cmp    DWORD PTR [ecx+edx*8+0x48],0x0
007A074B  0f8449010000                     je     0x7a089a
007A0751  8b4f10                           mov    ecx,DWORD PTR [edi+0x10]
007A0754  2b4f0c                           sub    ecx,DWORD PTR [edi+0xc]
007A0757  8d470c                           lea    eax,[edi+0xc]
007A075A  33db                             xor    ebx,ebx
007A075C  c1f902                           sar    ecx,0x2
007A075F  895de4                           mov    DWORD PTR [ebp-0x1c],ebx
007A0762  85c9                             test   ecx,ecx
007A0764  0f840d010000                     je     0x7a0877
007A076A  8b4dec                           mov    ecx,DWORD PTR [ebp-0x14]
007A076D  8b5508                           mov    edx,DWORD PTR [ebp+0x8]
007A0770  8b74ca48                         mov    esi,DWORD PTR [edx+ecx*8+0x48]
007A0774  8b38                             mov    edi,DWORD PTR [eax]
007A0776  8b4610                           mov    eax,DWORD PTR [esi+0x10]
007A0779  83c60c                           add    esi,0xc
007A077C  8d0c9d00000000                   lea    ecx,[ebx*4+0x0]
007A0783  03f9                             add    edi,ecx
007A0785  3bf8                             cmp    edi,eax
007A0787  7362                             jae    0x7a07eb
007A0789  8b16                             mov    edx,DWORD PTR [esi]
007A078B  3bd7                             cmp    edx,edi
007A078D  775c                             ja     0x7a07eb
007A078F  8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
007A0792  2bfa                             sub    edi,edx
007A0794  c1ff02                           sar    edi,0x2
007A0797  3bc1                             cmp    eax,ecx
007A0799  753e                             jne    0x7a07d9
007A079B  2bc2                             sub    eax,edx
007A079D  c1f802                           sar    eax,0x2
007A07A0  3dfeffff3f                       cmp    eax,0x3ffffffe
007A07A5  0f87e5000000                     ja     0x7a0890
007A07AB  2bca                             sub    ecx,edx
007A07AD  40                               inc    eax
007A07AE  c1f902                           sar    ecx,0x2
007A07B1  3bc1                             cmp    eax,ecx
007A07B3  7624                             jbe    0x7a07d9
007A07B5  8bd1                             mov    edx,ecx
007A07B7  d1ea                             shr    edx,1
007A07B9  bbffffff3f                       mov    ebx,0x3fffffff
007A07BE  2bda                             sub    ebx,edx
007A07C0  3bd9                             cmp    ebx,ecx
007A07C2  7304                             jae    0x7a07c8
007A07C4  33c9                             xor    ecx,ecx
007A07C6  eb02                             jmp    0x7a07ca
007A07C8  03ca                             add    ecx,edx
007A07CA  3bc8                             cmp    ecx,eax
007A07CC  7302                             jae    0x7a07d0
007A07CE  8bc8                             mov    ecx,eax
007A07D0  51                               push   ecx
007A07D1  e8aa71ffff                       call   0x797980
007A07D6  8b5de4                           mov    ebx,DWORD PTR [ebp-0x1c]
007A07D9  8b4604                           mov    eax,DWORD PTR [esi+0x4]
007A07DC  8b16                             mov    edx,DWORD PTR [esi]
007A07DE  8d0cba                           lea    ecx,[edx+edi*4]
007A07E1  85c0                             test   eax,eax
007A07E3  7458                             je     0x7a083d
007A07E5  8b09                             mov    ecx,DWORD PTR [ecx]
007A07E7  8908                             mov    DWORD PTR [eax],ecx
007A07E9  eb52                             jmp    0x7a083d
007A07EB  8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
007A07EE  3bc1                             cmp    eax,ecx
007A07F0  7540                             jne    0x7a0832
007A07F2  8b16                             mov    edx,DWORD PTR [esi]
007A07F4  2bc2                             sub    eax,edx
007A07F6  c1f802                           sar    eax,0x2
007A07F9  3dfeffff3f                       cmp    eax,0x3ffffffe
007A07FE  0f878c000000                     ja     0x7a0890
007A0804  2bca                             sub    ecx,edx
007A0806  40                               inc    eax
007A0807  c1f902                           sar    ecx,0x2
007A080A  3bc1                             cmp    eax,ecx
007A080C  7624                             jbe    0x7a0832
007A080E  8bd1                             mov    edx,ecx
007A0810  d1ea                             shr    edx,1
007A0812  bbffffff3f                       mov    ebx,0x3fffffff
007A0817  2bda                             sub    ebx,edx
007A0819  3bd9                             cmp    ebx,ecx
007A081B  7304                             jae    0x7a0821
007A081D  33c9                             xor    ecx,ecx
007A081F  eb02                             jmp    0x7a0823
007A0821  03ca                             add    ecx,edx
007A0823  3bc8                             cmp    ecx,eax
007A0825  7302                             jae    0x7a0829
007A0827  8bc8                             mov    ecx,eax
007A0829  51                               push   ecx
007A082A  e85171ffff                       call   0x797980
007A082F  8b5de4                           mov    ebx,DWORD PTR [ebp-0x1c]
007A0832  8b4604                           mov    eax,DWORD PTR [esi+0x4]
007A0835  85c0                             test   eax,eax
007A0837  7404                             je     0x7a083d
007A0839  8b17                             mov    edx,DWORD PTR [edi]
007A083B  8910                             mov    DWORD PTR [eax],edx
007A083D  83460404                         add    DWORD PTR [esi+0x4],0x4
007A0841  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
007A0844  8b480c                           mov    ecx,DWORD PTR [eax+0xc]
007A0847  8b1499                           mov    edx,DWORD PTR [ecx+ebx*4]
007A084A  8b45ec                           mov    eax,DWORD PTR [ebp-0x14]
007A084D  52                               push   edx
007A084E  50                               push   eax
007A084F  680cf5c400                       push   0xc4f50c
007A0854  e864280f00                       call   0x8930bd
007A0859  8b450c                           mov    eax,DWORD PTR [ebp+0xc]
007A085C  8b4810                           mov    ecx,DWORD PTR [eax+0x10]
007A085F  2b480c                           sub    ecx,DWORD PTR [eax+0xc]
007A0862  83c00c                           add    eax,0xc
007A0865  43                               inc    ebx
007A0866  c1f902                           sar    ecx,0x2
007A0869  83c40c                           add    esp,0xc
007A086C  895de4                           mov    DWORD PTR [ebp-0x1c],ebx
007A086F  3bd9                             cmp    ebx,ecx
007A0871  0f82f3feffff                     jb     0x7a076a
007A0877  8b55ec                           mov    edx,DWORD PTR [ebp-0x14]
007A087A  52                               push   edx
007A087B  6828f5c400                       push   0xc4f528
007A0880  e838280f00                       call   0x8930bd
007A0885  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
007A0888  83c408                           add    esp,0x8
007A088B  e9a5000000                       jmp    0x7a0935
007A0890  687823bf00                       push   0xbf2378
007A0895  e896d20d00                       call   0x87db30
007A089A  8b7dec                           mov    edi,DWORD PTR [ebp-0x14]
007A089D  57                               push   edi
007A089E  6840f5c400                       push   0xc4f540
007A08A3  e815280f00                       call   0x8930bd
007A08A8  8b4510                           mov    eax,DWORD PTR [ebp+0x10]
007A08AB  8b550c                           mov    edx,DWORD PTR [ebp+0xc]
007A08AE  33c9                             xor    ecx,ecx
007A08B0  83c408                           add    esp,0x8
007A08B3  894db8                           mov    DWORD PTR [ebp-0x48],ecx
007A08B6  894dbc                           mov    DWORD PTR [ebp-0x44],ecx
007A08B9  8bf0                             mov    esi,eax
007A08BB  8955d0                           mov    DWORD PTR [ebp-0x30],edx
007A08BE  3bc1                             cmp    eax,ecx
007A08C0  7431                             je     0x7a08f3
007A08C2  8b4804                           mov    ecx,DWORD PTR [eax+0x4]
007A08C5  8d5004                           lea    edx,[eax+0x4]
007A08C8  85c9                             test   ecx,ecx
007A08CA  7427                             je     0x7a08f3
007A08CC  8d642400                         lea    esp,[esp+0x0]
007A08D0  8d7901                           lea    edi,[ecx+0x1]
007A08D3  8bda                             mov    ebx,edx
007A08D5  8bc1                             mov    eax,ecx
007A08D7  f00fb13b                         lock cmpxchg DWORD PTR [ebx],edi
007A08DB  3bc1                             cmp    eax,ecx
007A08DD  7408                             je     0x7a08e7
007A08DF  8b0a                             mov    ecx,DWORD PTR [edx]
007A08E1  85c9                             test   ecx,ecx
007A08E3  75eb                             jne    0x7a08d0
007A08E5  eb09                             jmp    0x7a08f0
007A08E7  8b4dd0                           mov    ecx,DWORD PTR [ebp-0x30]
007A08EA  8975bc                           mov    DWORD PTR [ebp-0x44],esi
007A08ED  894db8                           mov    DWORD PTR [ebp-0x48],ecx
007A08F0  8b7dec                           mov    edi,DWORD PTR [ebp-0x14]
007A08F3  8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
007A08F6  8b74fb4c                         mov    esi,DWORD PTR [ebx+edi*8+0x4c]
007A08FA  8b45bc                           mov    eax,DWORD PTR [ebp-0x44]
007A08FD  8b55b8                           mov    edx,DWORD PTR [ebp-0x48]
007A0900  8944fb4c                         mov    DWORD PTR [ebx+edi*8+0x4c],eax
007A0904  8954fb48                         mov    DWORD PTR [ebx+edi*8+0x48],edx
007A0908  85f6                             test   esi,esi
007A090A  7429                             je     0x7a0935
007A090C  8d4604                           lea    eax,[esi+0x4]
007A090F  83c9ff                           or     ecx,0xffffffff
007A0912  f00fc108                         lock xadd DWORD PTR [eax],ecx
007A0916  751d                             jne    0x7a0935
007A0918  8b16                             mov    edx,DWORD PTR [esi]
007A091A  8b02                             mov    eax,DWORD PTR [edx]
007A091C  8bce                             mov    ecx,esi
007A091E  ffd0                             call   eax
007A0920  8d4e08                           lea    ecx,[esi+0x8]
007A0923  83caff                           or     edx,0xffffffff
007A0926  f00fc111                         lock xadd DWORD PTR [ecx],edx
007A092A  7509                             jne    0x7a0935
007A092C  8b06                             mov    eax,DWORD PTR [esi]
007A092E  8b5004                           mov    edx,DWORD PTR [eax+0x4]
007A0931  8bce                             mov    ecx,esi
007A0933  ffd2                             call   edx
007A0935  8b4590                           mov    eax,DWORD PTR [ebp-0x70]
007A0938  8b30                             mov    esi,DWORD PTR [eax]
007A093A  3bf0                             cmp    esi,eax
007A093C  0f84b0000000                     je     0x7a09f2
007A0942  8b4b04                           mov    ecx,DWORD PTR [ebx+0x4]
007A0945  8b4104                           mov    eax,DWORD PTR [ecx+0x4]
007A0948  80781900                         cmp    BYTE PTR [eax+0x19],0x0
007A094C  8b7e0c                           mov    edi,DWORD PTR [esi+0xc]
007A094F  8bd1                             mov    edx,ecx
007A0951  7514                             jne    0x7a0967
007A0953  39780c                           cmp    DWORD PTR [eax+0xc],edi
007A0956  7305                             jae    0x7a095d
007A0958  8b4008                           mov    eax,DWORD PTR [eax+0x8]
007A095B  eb04                             jmp    0x7a0961
007A095D  8bd0                             mov    edx,eax
007A095F  8b00                             mov    eax,DWORD PTR [eax]
007A0961  80781900                         cmp    BYTE PTR [eax+0x19],0x0
007A0965  74ec                             je     0x7a0953
007A0967  8955cc                           mov    DWORD PTR [ebp-0x34],edx
007A096A  3bd1                             cmp    edx,ecx
007A096C  740a                             je     0x7a0978
007A096E  3b7a0c                           cmp    edi,DWORD PTR [edx+0xc]
007A0971  7205                             jb     0x7a0978
007A0973  8d45cc                           lea    eax,[ebp-0x34]
007A0976  eb06                             jmp    0x7a097e
007A0978  894dc8                           mov    DWORD PTR [ebp-0x38],ecx
007A097B  8d45c8                           lea    eax,[ebp-0x38]
007A097E  8b00                             mov    eax,DWORD PTR [eax]
007A0980  3bc1                             cmp    eax,ecx
007A0982  7423                             je     0x7a09a7
007A0984  8b4010                           mov    eax,DWORD PTR [eax+0x10]
007A0987  8b4854                           mov    ecx,DWORD PTR [eax+0x54]
007A098A  85c9                             test   ecx,ecx
007A098C  7419                             je     0x7a09a7
007A098E  8b415c                           mov    eax,DWORD PTR [ecx+0x5c]
007A0991  85c0                             test   eax,eax
007A0993  7407                             je     0x7a099c
007A0995  e846520200                       call   0x7c5be0
007A099A  eb0b                             jmp    0x7a09a7
007A099C  80796000                         cmp    BYTE PTR [ecx+0x60],0x0
007A09A0  7405                             je     0x7a09a7
007A09A2  e849460200                       call   0x7c4ff0
007A09A7  807e1100                         cmp    BYTE PTR [esi+0x11],0x0
007A09AB  753c                             jne    0x7a09e9
007A09AD  8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
007A09B0  80791100                         cmp    BYTE PTR [ecx+0x11],0x0
007A09B4  7518                             jne    0x7a09ce
007A09B6  8b01                             mov    eax,DWORD PTR [ecx]
007A09B8  80781100                         cmp    BYTE PTR [eax+0x11],0x0
007A09BC  750c                             jne    0x7a09ca
007A09BE  8bff                             mov    edi,edi
007A09C0  8bc8                             mov    ecx,eax
007A09C2  8b01                             mov    eax,DWORD PTR [ecx]
007A09C4  80781100                         cmp    BYTE PTR [eax+0x11],0x0
007A09C8  74f6                             je     0x7a09c0
007A09CA  8bf1                             mov    esi,ecx
007A09CC  eb1b                             jmp    0x7a09e9
007A09CE  8b4604                           mov    eax,DWORD PTR [esi+0x4]
007A09D1  80781100                         cmp    BYTE PTR [eax+0x11],0x0
007A09D5  7510                             jne    0x7a09e7
007A09D7  3b7008                           cmp    esi,DWORD PTR [eax+0x8]
007A09DA  750b                             jne    0x7a09e7
007A09DC  8bf0                             mov    esi,eax
007A09DE  8b4004                           mov    eax,DWORD PTR [eax+0x4]
007A09E1  80781100                         cmp    BYTE PTR [eax+0x11],0x0
007A09E5  74f0                             je     0x7a09d7
007A09E7  8bf0                             mov    esi,eax
007A09E9  3b7590                           cmp    esi,DWORD PTR [ebp-0x70]
007A09EC  0f8550ffffff                     jne    0x7a0942
007A09F2  c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
007A09F6  8b4d90                           mov    ecx,DWORD PTR [ebp-0x70]
007A09F9  8b01                             mov    eax,DWORD PTR [ecx]
007A09FB  51                               push   ecx
007A09FC  50                               push   eax
007A09FD  8d75c0                           lea    esi,[ebp-0x40]
007A0A00  8d458c                           lea    eax,[ebp-0x74]
007A0A03  e85897d2ff                       call   0x4ca160
007A0A08  8b4590                           mov    eax,DWORD PTR [ebp-0x70]
007A0A0B  50                               push   eax
007A0A0C  e8fb070f00                       call   0x89120c
007A0A11  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
007A0A18  8b4510                           mov    eax,DWORD PTR [ebp+0x10]
007A0A1B  83c404                           add    esp,0x4
007A0A1E  85c0                             test   eax,eax
007A0A20  742b                             je     0x7a0a4d
007A0A22  8bf0                             mov    esi,eax
007A0A24  83c004                           add    eax,0x4
007A0A27  83c9ff                           or     ecx,0xffffffff
007A0A2A  f00fc108                         lock xadd DWORD PTR [eax],ecx
007A0A2E  751d                             jne    0x7a0a4d
007A0A30  8b16                             mov    edx,DWORD PTR [esi]
007A0A32  8b02                             mov    eax,DWORD PTR [edx]
007A0A34  8bce                             mov    ecx,esi
007A0A36  ffd0                             call   eax
007A0A38  8d4e08                           lea    ecx,[esi+0x8]
007A0A3B  83caff                           or     edx,0xffffffff
007A0A3E  f00fc111                         lock xadd DWORD PTR [ecx],edx
007A0A42  7509                             jne    0x7a0a4d
007A0A44  8b06                             mov    eax,DWORD PTR [esi]
007A0A46  8b5004                           mov    edx,DWORD PTR [eax+0x4]
007A0A49  8bce                             mov    ecx,esi
007A0A4B  ffd2                             call   edx
007A0A4D  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
007A0A50  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
007A0A57  59                               pop    ecx
007A0A58  5f                               pop    edi
007A0A59  5e                               pop    esi
007A0A5A  5b                               pop    ebx
007A0A5B  8be5                             mov    esp,ebp
007A0A5D  5d                               pop    ebp
007A0A5E  c20c00                           ret    0xc
007A0A61  8d45c4                           lea    eax,[ebp-0x3c]
007A0A64  50                               push   eax
007A0A65  8d4d9c                           lea    ecx,[ebp-0x64]
007A0A68  8975c4                           mov    DWORD PTR [ebp-0x3c],esi
007A0A6B  e839060f00                       call   0x8910a9
007A0A70  68a857c800                       push   0xc857a8
007A0A75  8d4d9c                           lea    ecx,[ebp-0x64]
007A0A78  51                               push   ecx
007A0A79  c7459ca42cbd00                   mov    DWORD PTR [ebp-0x64],0xbd2ca4
007A0A80  e86bbf0f00                       call   0x89c9f0

; resource_unload [NEW_DOWNSTREAM_JOIN] 0x7c4ff0..0x7c50f3 exclusive
007C4FF0  55                               push   ebp
007C4FF1  8bec                             mov    ebp,esp
007C4FF3  6aff                             push   0xffffffff
007C4FF5  68ae8a9300                       push   0x938aae
007C4FFA  64a100000000                     mov    eax,fs:0x0
007C5000  50                               push   eax
007C5001  51                               push   ecx
007C5002  53                               push   ebx
007C5003  56                               push   esi
007C5004  57                               push   edi
007C5005  a1201fd600                       mov    eax,ds:0xd61f20
007C500A  33c5                             xor    eax,ebp
007C500C  50                               push   eax
007C500D  8d45f4                           lea    eax,[ebp-0xc]
007C5010  64a300000000                     mov    fs:0x0,eax
007C5016  8bf9                             mov    edi,ecx
007C5018  837f5801                         cmp    DWORD PTR [edi+0x58],0x1
007C501C  0f85bf000000                     jne    0x7c50e1
007C5022  8b8fc8000000                     mov    ecx,DWORD PTR [edi+0xc8]
007C5028  2b8fc4000000                     sub    ecx,DWORD PTR [edi+0xc4]
007C502E  b893244992                       mov    eax,0x92492493
007C5033  f7e9                             imul   ecx
007C5035  03d1                             add    edx,ecx
007C5037  c1fa05                           sar    edx,0x5
007C503A  8bc2                             mov    eax,edx
007C503C  c1e81f                           shr    eax,0x1f
007C503F  33f6                             xor    esi,esi
007C5041  03c2                             add    eax,edx
007C5043  747e                             je     0x7c50c3
007C5045  8975f0                           mov    DWORD PTR [ebp-0x10],esi
007C5048  8b87c4000000                     mov    eax,DWORD PTR [edi+0xc4]
007C504E  0345f0                           add    eax,DWORD PTR [ebp-0x10]
007C5051  83783010                         cmp    DWORD PTR [eax+0x30],0x10
007C5055  7205                             jb     0x7c505c
007C5057  8b581c                           mov    ebx,DWORD PTR [eax+0x1c]
007C505A  eb03                             jmp    0x7c505f
007C505C  8d581c                           lea    ebx,[eax+0x1c]
007C505F  f6054c32fe0001                   test   BYTE PTR ds:0xfe324c,0x1
007C5066  7527                             jne    0x7c508f
007C5068  830d4c32fe0001                   or     DWORD PTR ds:0xfe324c,0x1
007C506F  c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
007C5076  e8358e0000                       call   0x7cdeb0
007C507B  68b009bd00                       push   0xbd09b0
007C5080  e895d20c00                       call   0x89231a
007C5085  83c404                           add    esp,0x4
007C5088  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
007C508F  8bcb                             mov    ecx,ebx
007C5091  ba5032fe00                       mov    edx,0xfe3250
007C5096  e8e5a30000                       call   0x7cf480
007C509B  8b8fc8000000                     mov    ecx,DWORD PTR [edi+0xc8]
007C50A1  2b8fc4000000                     sub    ecx,DWORD PTR [edi+0xc4]
007C50A7  8345f038                         add    DWORD PTR [ebp-0x10],0x38
007C50AB  b893244992                       mov    eax,0x92492493
007C50B0  f7e9                             imul   ecx
007C50B2  03d1                             add    edx,ecx
007C50B4  c1fa05                           sar    edx,0x5
007C50B7  8bca                             mov    ecx,edx
007C50B9  c1e91f                           shr    ecx,0x1f
007C50BC  46                               inc    esi
007C50BD  03ca                             add    ecx,edx
007C50BF  3bf1                             cmp    esi,ecx
007C50C1  7285                             jb     0x7c5048
007C50C3  e8d8f1ffff                       call   0x7c42a0
007C50C8  e8f3eeffff                       call   0x7c3fc0
007C50CD  57                               push   edi
007C50CE  e82df0ffff                       call   0x7c4100
007C50D3  8bcf                             mov    ecx,edi
007C50D5  e866f8ffff                       call   0x7c4940
007C50DA  c7475800000000                   mov    DWORD PTR [edi+0x58],0x0
007C50E1  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
007C50E4  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
007C50EB  59                               pop    ecx
007C50EC  5f                               pop    edi
007C50ED  5e                               pop    esi
007C50EE  5b                               pop    ebx
007C50EF  8be5                             mov    esp,ebp
007C50F1  5d                               pop    ebp
007C50F2  c3                               ret

; resource_child_delete [NEW_DOWNSTREAM_JOIN] 0x7c4100..0x7c4217 exclusive
007C4100  55                               push   ebp
007C4101  8bec                             mov    ebp,esp
007C4103  83ec08                           sub    esp,0x8
007C4106  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
007C4109  8b81a8000000                     mov    eax,DWORD PTR [ecx+0xa8]
007C410F  2b81a4000000                     sub    eax,DWORD PTR [ecx+0xa4]
007C4115  33d2                             xor    edx,edx
007C4117  c1f802                           sar    eax,0x2
007C411A  8955f8                           mov    DWORD PTR [ebp-0x8],edx
007C411D  85c0                             test   eax,eax
007C411F  0f84ec000000                     je     0x7c4211
007C4125  53                               push   ebx
007C4126  56                               push   esi
007C4127  57                               push   edi
007C4128  eb06                             jmp    0x7c4130
007C412A  8d9b00000000                     lea    ebx,[ebx+0x0]
007C4130  8b81a4000000                     mov    eax,DWORD PTR [ecx+0xa4]
007C4136  8b0490                           mov    eax,DWORD PTR [eax+edx*4]
007C4139  8b7024                           mov    esi,DWORD PTR [eax+0x24]
007C413C  2b7020                           sub    esi,DWORD PTR [eax+0x20]
007C413F  83c020                           add    eax,0x20
007C4142  33db                             xor    ebx,ebx
007C4144  c1fe02                           sar    esi,0x2
007C4147  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
007C414A  85f6                             test   esi,esi
007C414C  0f84a1000000                     je     0x7c41f3
007C4152  8b08                             mov    ecx,DWORD PTR [eax]
007C4154  8b3499                           mov    esi,DWORD PTR [ecx+ebx*4]
007C4157  8b5648                           mov    edx,DWORD PTR [esi+0x48]
007C415A  2b5644                           sub    edx,DWORD PTR [esi+0x44]
007C415D  33ff                             xor    edi,edi
007C415F  c1fa02                           sar    edx,0x2
007C4162  85d2                             test   edx,edx
007C4164  743b                             je     0x7c41a1
007C4166  8b4644                           mov    eax,DWORD PTR [esi+0x44]
007C4169  833cb800                         cmp    DWORD PTR [eax+edi*4],0x0
007C416D  8d04b8                           lea    eax,[eax+edi*4]
007C4170  741a                             je     0x7c418c
007C4172  8b00                             mov    eax,DWORD PTR [eax]
007C4174  85c0                             test   eax,eax
007C4176  740a                             je     0x7c4182
007C4178  8b10                             mov    edx,DWORD PTR [eax]
007C417A  8bc8                             mov    ecx,eax
007C417C  8b02                             mov    eax,DWORD PTR [edx]
007C417E  6a01                             push   0x1
007C4180  ffd0                             call   eax
007C4182  8b4e44                           mov    ecx,DWORD PTR [esi+0x44]
007C4185  c704b900000000                   mov    DWORD PTR [ecx+edi*4],0x0
007C418C  c7465800000000                   mov    DWORD PTR [esi+0x58],0x0
007C4193  8b5648                           mov    edx,DWORD PTR [esi+0x48]
007C4196  2b5644                           sub    edx,DWORD PTR [esi+0x44]
007C4199  47                               inc    edi
007C419A  c1fa02                           sar    edx,0x2
007C419D  3bfa                             cmp    edi,edx
007C419F  72c5                             jb     0x7c4166
007C41A1  8b4e48                           mov    ecx,DWORD PTR [esi+0x48]
007C41A4  8b7e44                           mov    edi,DWORD PTR [esi+0x44]
007C41A7  3bf9                             cmp    edi,ecx
007C41A9  7421                             je     0x7c41cc
007C41AB  8bc1                             mov    eax,ecx
007C41AD  2bc1                             sub    eax,ecx
007C41AF  c1f802                           sar    eax,0x2
007C41B2  8d1c8500000000                   lea    ebx,[eax*4+0x0]
007C41B9  53                               push   ebx
007C41BA  51                               push   ecx
007C41BB  57                               push   edi
007C41BC  e82fd10c00                       call   0x8912f0
007C41C1  83c40c                           add    esp,0xc
007C41C4  03df                             add    ebx,edi
007C41C6  895e48                           mov    DWORD PTR [esi+0x48],ebx
007C41C9  8b5dfc                           mov    ebx,DWORD PTR [ebp-0x4]
007C41CC  8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
007C41CF  8b81a4000000                     mov    eax,DWORD PTR [ecx+0xa4]
007C41D5  8b55f8                           mov    edx,DWORD PTR [ebp-0x8]
007C41D8  8b0490                           mov    eax,DWORD PTR [eax+edx*4]
007C41DB  8b7024                           mov    esi,DWORD PTR [eax+0x24]
007C41DE  2b7020                           sub    esi,DWORD PTR [eax+0x20]
007C41E1  83c020                           add    eax,0x20
007C41E4  43                               inc    ebx
007C41E5  c1fe02                           sar    esi,0x2
007C41E8  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
007C41EB  3bde                             cmp    ebx,esi
007C41ED  0f825fffffff                     jb     0x7c4152
007C41F3  8b81a8000000                     mov    eax,DWORD PTR [ecx+0xa8]
007C41F9  2b81a4000000                     sub    eax,DWORD PTR [ecx+0xa4]
007C41FF  42                               inc    edx
007C4200  c1f802                           sar    eax,0x2
007C4203  8955f8                           mov    DWORD PTR [ebp-0x8],edx
007C4206  3bd0                             cmp    edx,eax
007C4208  0f8222ffffff                     jb     0x7c4130
007C420E  5f                               pop    edi
007C420F  5e                               pop    esi
007C4210  5b                               pop    ebx
007C4211  8be5                             mov    esp,ebp
007C4213  5d                               pop    ebp
007C4214  c20400                           ret    0x4

; resource_residency_cleanup [NEW_DOWNSTREAM_JOIN] 0x7c4940..0x7c4ae3 exclusive
007C4940  55                               push   ebp
007C4941  8bec                             mov    ebp,esp
007C4943  83e4f8                           and    esp,0xfffffff8
007C4946  6aff                             push   0xffffffff
007C4948  688e7c9300                       push   0x937c8e
007C494D  64a100000000                     mov    eax,fs:0x0
007C4953  50                               push   eax
007C4954  83ec48                           sub    esp,0x48
007C4957  a1201fd600                       mov    eax,ds:0xd61f20
007C495C  33c4                             xor    eax,esp
007C495E  89442440                         mov    DWORD PTR [esp+0x40],eax
007C4962  53                               push   ebx
007C4963  56                               push   esi
007C4964  57                               push   edi
007C4965  a1201fd600                       mov    eax,ds:0xd61f20
007C496A  33c4                             xor    eax,esp
007C496C  50                               push   eax
007C496D  8d442458                         lea    eax,[esp+0x58]
007C4971  64a300000000                     mov    fs:0x0,eax
007C4977  8bf9                             mov    edi,ecx
007C4979  33db                             xor    ebx,ebx
007C497B  897c2410                         mov    DWORD PTR [esp+0x10],edi
007C497F  385f60                           cmp    BYTE PTR [edi+0x60],bl
007C4982  0f843d010000                     je     0x7c4ac5
007C4988  8b4778                           mov    eax,DWORD PTR [edi+0x78]
007C498B  8b7774                           mov    esi,DWORD PTR [edi+0x74]
007C498E  89442414                         mov    DWORD PTR [esp+0x14],eax
007C4992  3bf0                             cmp    esi,eax
007C4994  0f8405010000                     je     0x7c4a9f
007C499A  8d9b00000000                     lea    ebx,[ebx+0x0]
007C49A0  6aff                             push   0xffffffff
007C49A2  53                               push   ebx
007C49A3  56                               push   esi
007C49A4  8d4c2424                         lea    ecx,[esp+0x24]
007C49A8  c74424380f000000                 mov    DWORD PTR [esp+0x38],0xf
007C49B0  895c2434                         mov    DWORD PTR [esp+0x34],ebx
007C49B4  885c2424                         mov    BYTE PTR [esp+0x24],bl
007C49B8  e883e6c3ff                       call   0x403040
007C49BD  8d442434                         lea    eax,[esp+0x34]
007C49C1  50                               push   eax
007C49C2  8bcf                             mov    ecx,edi
007C49C4  895c2464                         mov    DWORD PTR [esp+0x64],ebx
007C49C8  e8330c0000                       call   0x7c5600
007C49CD  c644246001                       mov    BYTE PTR [esp+0x60],0x1
007C49D2  837c242c10                       cmp    DWORD PTR [esp+0x2c],0x10
007C49D7  8b542418                         mov    edx,DWORD PTR [esp+0x18]
007C49DB  7304                             jae    0x7c49e1
007C49DD  8d542418                         lea    edx,[esp+0x18]
007C49E1  8bc2                             mov    eax,edx
007C49E3  8d7801                           lea    edi,[eax+0x1]
007C49E6  8a08                             mov    cl,BYTE PTR [eax]
007C49E8  40                               inc    eax
007C49E9  3acb                             cmp    cl,bl
007C49EB  75f9                             jne    0x7c49e6
007C49ED  2bc7                             sub    eax,edi
007C49EF  50                               push   eax
007C49F0  52                               push   edx
007C49F1  8d4c243c                         lea    ecx,[esp+0x3c]
007C49F5  e8c6d5c3ff                       call   0x401fc0
007C49FA  837c242c10                       cmp    DWORD PTR [esp+0x2c],0x10
007C49FF  8b7c2418                         mov    edi,DWORD PTR [esp+0x18]
007C4A03  7304                             jae    0x7c4a09
007C4A05  8d7c2418                         lea    edi,[esp+0x18]
007C4A09  f605c01afe0001                   test   BYTE PTR ds:0xfe1ac0,0x1
007C4A10  7523                             jne    0x7c4a35
007C4A12  830dc01afe0001                   or     DWORD PTR ds:0xfe1ac0,0x1
007C4A19  c644246002                       mov    BYTE PTR [esp+0x60],0x2
007C4A1E  e84d6fffff                       call   0x7bb970
007C4A23  68c0eabc00                       push   0xbceac0
007C4A28  e8edd80c00                       call   0x89231a
007C4A2D  83c404                           add    esp,0x4
007C4A30  c644246001                       mov    BYTE PTR [esp+0x60],0x1
007C4A35  8bcf                             mov    ecx,edi
007C4A37  bfc81afe00                       mov    edi,0xfe1ac8
007C4A3C  e81f85ffff                       call   0x7bcf60
007C4A41  837c244810                       cmp    DWORD PTR [esp+0x48],0x10
007C4A46  720d                             jb     0x7c4a55
007C4A48  8b4c2434                         mov    ecx,DWORD PTR [esp+0x34]
007C4A4C  51                               push   ecx
007C4A4D  e8bac70c00                       call   0x89120c
007C4A52  83c404                           add    esp,0x4
007C4A55  bf0f000000                       mov    edi,0xf
007C4A5A  c7442460ffffffff                 mov    DWORD PTR [esp+0x60],0xffffffff
007C4A62  837c242c10                       cmp    DWORD PTR [esp+0x2c],0x10
007C4A67  897c2448                         mov    DWORD PTR [esp+0x48],edi
007C4A6B  895c2444                         mov    DWORD PTR [esp+0x44],ebx
007C4A6F  885c2434                         mov    BYTE PTR [esp+0x34],bl
007C4A73  720d                             jb     0x7c4a82
007C4A75  8b542418                         mov    edx,DWORD PTR [esp+0x18]
007C4A79  52                               push   edx
007C4A7A  e88dc70c00                       call   0x89120c
007C4A7F  83c404                           add    esp,0x4
007C4A82  83c61c                           add    esi,0x1c
007C4A85  897c242c                         mov    DWORD PTR [esp+0x2c],edi
007C4A89  8b7c2410                         mov    edi,DWORD PTR [esp+0x10]
007C4A8D  895c2428                         mov    DWORD PTR [esp+0x28],ebx
007C4A91  885c2418                         mov    BYTE PTR [esp+0x18],bl
007C4A95  3b742414                         cmp    esi,DWORD PTR [esp+0x14]
007C4A99  0f8501ffffff                     jne    0x7c49a0
007C4A9F  8b87e4000000                     mov    eax,DWORD PTR [edi+0xe4]
007C4AA5  e856170100                       call   0x7d6200
007C4AAA  8b8fec000000                     mov    ecx,DWORD PTR [edi+0xec]
007C4AB0  3bcb                             cmp    ecx,ebx
007C4AB2  740e                             je     0x7c4ac2
007C4AB4  8b01                             mov    eax,DWORD PTR [ecx]
007C4AB6  8b10                             mov    edx,DWORD PTR [eax]
007C4AB8  6a01                             push   0x1
007C4ABA  ffd2                             call   edx
007C4ABC  899fec000000                     mov    DWORD PTR [edi+0xec],ebx
007C4AC2  885f60                           mov    BYTE PTR [edi+0x60],bl
007C4AC5  8b4c2458                         mov    ecx,DWORD PTR [esp+0x58]
007C4AC9  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
007C4AD0  59                               pop    ecx
007C4AD1  5f                               pop    edi
007C4AD2  5e                               pop    esi
007C4AD3  5b                               pop    ebx
007C4AD4  8b4c2440                         mov    ecx,DWORD PTR [esp+0x40]
007C4AD8  33cc                             xor    ecx,esp
007C4ADA  e822c50c00                       call   0x891001
007C4ADF  8be5                             mov    esp,ebp
007C4AE1  5d                               pop    ebp
007C4AE2  c3                               ret

; resource_reload [NEW_DOWNSTREAM_JOIN] 0x7c5be0..0x7c5dc3 exclusive
007C5BE0  55                               push   ebp
007C5BE1  8bec                             mov    ebp,esp
007C5BE3  6aff                             push   0xffffffff
007C5BE5  687e999300                       push   0x93997e
007C5BEA  64a100000000                     mov    eax,fs:0x0
007C5BF0  50                               push   eax
007C5BF1  83ec44                           sub    esp,0x44
007C5BF4  a1201fd600                       mov    eax,ds:0xd61f20
007C5BF9  33c5                             xor    eax,ebp
007C5BFB  8945f0                           mov    DWORD PTR [ebp-0x10],eax
007C5BFE  53                               push   ebx
007C5BFF  56                               push   esi
007C5C00  57                               push   edi
007C5C01  50                               push   eax
007C5C02  8d45f4                           lea    eax,[ebp-0xc]
007C5C05  64a300000000                     mov    fs:0x0,eax
007C5C0B  8bf1                             mov    esi,ecx
007C5C0D  33db                             xor    ebx,ebx
007C5C0F  395e5c                           cmp    DWORD PTR [esi+0x5c],ebx
007C5C12  0f848a010000                     je     0x7c5da2
007C5C18  385e60                           cmp    BYTE PTR [esi+0x60],bl
007C5C1B  0f8581010000                     jne    0x7c5da2
007C5C21  8d45b8                           lea    eax,[ebp-0x48]
007C5C24  50                               push   eax
007C5C25  e846faffff                       call   0x7c5670
007C5C2A  8d4e3c                           lea    ecx,[esi+0x3c]
007C5C2D  bf10000000                       mov    edi,0x10
007C5C32  895dfc                           mov    DWORD PTR [ebp-0x4],ebx
007C5C35  397914                           cmp    DWORD PTR [ecx+0x14],edi
007C5C38  7202                             jb     0x7c5c3c
007C5C3A  8b09                             mov    ecx,DWORD PTR [ecx]
007C5C3C  397814                           cmp    DWORD PTR [eax+0x14],edi
007C5C3F  7202                             jb     0x7c5c43
007C5C41  8b00                             mov    eax,DWORD PTR [eax]
007C5C43  8bd1                             mov    edx,ecx
007C5C45  56                               push   esi
007C5C46  8bc8                             mov    ecx,eax
007C5C48  e8c3e6ffff                       call   0x7c4310
007C5C4D  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
007C5C54  397dcc                           cmp    DWORD PTR [ebp-0x34],edi
007C5C57  720c                             jb     0x7c5c65
007C5C59  8b4db8                           mov    ecx,DWORD PTR [ebp-0x48]
007C5C5C  51                               push   ecx
007C5C5D  e8aab50c00                       call   0x89120c
007C5C62  83c404                           add    esp,0x4
007C5C65  8bce                             mov    ecx,esi
007C5C67  e8d4e2ffff                       call   0x7c3f40
007C5C6C  8b8ec8000000                     mov    ecx,DWORD PTR [esi+0xc8]
007C5C72  2b8ec4000000                     sub    ecx,DWORD PTR [esi+0xc4]
007C5C78  b893244992                       mov    eax,0x92492493
007C5C7D  f7e9                             imul   ecx
007C5C7F  03d1                             add    edx,ecx
007C5C81  c1fa05                           sar    edx,0x5
007C5C84  8bc2                             mov    eax,edx
007C5C86  c1e81f                           shr    eax,0x1f
007C5C89  03c2                             add    eax,edx
007C5C8B  0f840a010000                     je     0x7c5d9b
007C5C91  33ff                             xor    edi,edi
007C5C93  8b86c4000000                     mov    eax,DWORD PTR [esi+0xc4]
007C5C99  6aff                             push   0xffffffff
007C5C9B  03c7                             add    eax,edi
007C5C9D  6a00                             push   0x0
007C5C9F  50                               push   eax
007C5CA0  8d4dd4                           lea    ecx,[ebp-0x2c]
007C5CA3  c745e80f000000                   mov    DWORD PTR [ebp-0x18],0xf
007C5CAA  c745e400000000                   mov    DWORD PTR [ebp-0x1c],0x0
007C5CB1  c645d400                         mov    BYTE PTR [ebp-0x2c],0x0
007C5CB5  e886d3c3ff                       call   0x403040
007C5CBA  c745fc01000000                   mov    DWORD PTR [ebp-0x4],0x1
007C5CC1  8b8ec4000000                     mov    ecx,DWORD PTR [esi+0xc4]
007C5CC7  6aff                             push   0xffffffff
007C5CC9  8d440f1c                         lea    eax,[edi+ecx*1+0x1c]
007C5CCD  6a00                             push   0x0
007C5CCF  50                               push   eax
007C5CD0  8d4dd4                           lea    ecx,[ebp-0x2c]
007C5CD3  e8f8c1c3ff                       call   0x401ed0
007C5CD8  b910000000                       mov    ecx,0x10
007C5CDD  394de8                           cmp    DWORD PTR [ebp-0x18],ecx
007C5CE0  7208                             jb     0x7c5cea
007C5CE2  8b55d4                           mov    edx,DWORD PTR [ebp-0x2c]
007C5CE5  8955b0                           mov    DWORD PTR [ebp-0x50],edx
007C5CE8  eb06                             jmp    0x7c5cf0
007C5CEA  8d45d4                           lea    eax,[ebp-0x2c]
007C5CED  8945b0                           mov    DWORD PTR [ebp-0x50],eax
007C5CF0  8b86c4000000                     mov    eax,DWORD PTR [esi+0xc4]
007C5CF6  03c7                             add    eax,edi
007C5CF8  83c01c                           add    eax,0x1c
007C5CFB  394814                           cmp    DWORD PTR [eax+0x14],ecx
007C5CFE  7207                             jb     0x7c5d07
007C5D00  8b08                             mov    ecx,DWORD PTR [eax]
007C5D02  894db4                           mov    DWORD PTR [ebp-0x4c],ecx
007C5D05  eb03                             jmp    0x7c5d0a
007C5D07  8945b4                           mov    DWORD PTR [ebp-0x4c],eax
007C5D0A  f6054c32fe0001                   test   BYTE PTR ds:0xfe324c,0x1
007C5D11  7521                             jne    0x7c5d34
007C5D13  830d4c32fe0001                   or     DWORD PTR ds:0xfe324c,0x1
007C5D1A  c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
007C5D1E  e88d810000                       call   0x7cdeb0
007C5D23  68b009bd00                       push   0xbd09b0
007C5D28  e8edc50c00                       call   0x89231a
007C5D2D  83c404                           add    esp,0x4
007C5D30  c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
007C5D34  8b55b0                           mov    edx,DWORD PTR [ebp-0x50]
007C5D37  8b4db4                           mov    ecx,DWORD PTR [ebp-0x4c]
007C5D3A  52                               push   edx
007C5D3B  685032fe00                       push   0xfe3250
007C5D40  e89b850000                       call   0x7ce2e0
007C5D45  c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
007C5D4C  837de810                         cmp    DWORD PTR [ebp-0x18],0x10
007C5D50  720c                             jb     0x7c5d5e
007C5D52  8b45d4                           mov    eax,DWORD PTR [ebp-0x2c]
007C5D55  50                               push   eax
007C5D56  e8b1b40c00                       call   0x89120c
007C5D5B  83c404                           add    esp,0x4
007C5D5E  8b8ec8000000                     mov    ecx,DWORD PTR [esi+0xc8]
007C5D64  2b8ec4000000                     sub    ecx,DWORD PTR [esi+0xc4]
007C5D6A  b893244992                       mov    eax,0x92492493
007C5D6F  f7e9                             imul   ecx
007C5D71  03d1                             add    edx,ecx
007C5D73  c1fa05                           sar    edx,0x5
007C5D76  8bca                             mov    ecx,edx
007C5D78  c1e91f                           shr    ecx,0x1f
007C5D7B  43                               inc    ebx
007C5D7C  03ca                             add    ecx,edx
007C5D7E  83c738                           add    edi,0x38
007C5D81  c745e80f000000                   mov    DWORD PTR [ebp-0x18],0xf
007C5D88  c745e400000000                   mov    DWORD PTR [ebp-0x1c],0x0
007C5D8F  c645d400                         mov    BYTE PTR [ebp-0x2c],0x0
007C5D93  3bd9                             cmp    ebx,ecx
007C5D95  0f82f8feffff                     jb     0x7c5c93
007C5D9B  c7465801000000                   mov    DWORD PTR [esi+0x58],0x1
007C5DA2  e899e2ffff                       call   0x7c4040
007C5DA7  8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
007C5DAA  64890d00000000                   mov    DWORD PTR fs:0x0,ecx
007C5DB1  59                               pop    ecx
007C5DB2  5f                               pop    edi
007C5DB3  5e                               pop    esi
007C5DB4  5b                               pop    ebx
007C5DB5  8b4df0                           mov    ecx,DWORD PTR [ebp-0x10]
007C5DB8  33cd                             xor    ecx,ebp
007C5DBA  e842b20c00                       call   0x891001
007C5DBF  8be5                             mov    esp,ebp
007C5DC1  5d                               pop    ebp
007C5DC2  c3                               ret
