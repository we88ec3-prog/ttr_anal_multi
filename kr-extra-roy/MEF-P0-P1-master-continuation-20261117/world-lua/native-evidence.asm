; result_000E [0x4b0640,0x4b1914) 完整函式指令；結果欄位/副作用/九個分支，callee 依下述有界證據與 T12 既有報告分流
004b0640  55                                 push   ebp
004b0641  8bec                               mov    ebp,esp
004b0643  83e4f8                             and    esp,0xfffffff8
004b0646  6aff                               push   0xffffffff
004b0648  68bf0b9400                         push   0x940bbf
004b064d  64a100000000                       mov    eax,fs:0x0
004b0653  50                                 push   eax
004b0654  81ec98010000                       sub    esp,0x198
004b065a  a1201fd600                         mov    eax,ds:0xd61f20
004b065f  33c4                               xor    eax,esp
004b0661  89842490010000                     mov    DWORD PTR [esp+0x190],eax
004b0668  53                                 push   ebx
004b0669  56                                 push   esi
004b066a  57                                 push   edi
004b066b  a1201fd600                         mov    eax,ds:0xd61f20
004b0670  33c4                               xor    eax,esp
004b0672  50                                 push   eax
004b0673  8d8424a8010000                     lea    eax,[esp+0x1a8]
004b067a  64a300000000                       mov    fs:0x0,eax
004b0680  8b4508                             mov    eax,DWORD PTR [ebp+0x8]
004b0683  bb01000000                         mov    ebx,0x1
004b0688  83cfff                             or     edi,0xffffffff
004b068b  89442444                           mov    DWORD PTR [esp+0x44],eax
004b068f  841d9043f900                       test   BYTE PTR ds:0xf94390,bl
004b0695  752a                               jne    0x4b06c1
004b0697  091d9043f900                       or     DWORD PTR ds:0xf94390,ebx
004b069d  c78424b001000000000000             mov    DWORD PTR [esp+0x1b0],0x0
004b06a8  e8e30e0300                         call   0x4e1590
004b06ad  6880ccbc00                         push   0xbccc80
004b06b2  e8631c3e00                         call   0x89231a
004b06b7  83c404                             add    esp,0x4
004b06ba  89bc24b0010000                     mov    DWORD PTR [esp+0x1b0],edi
004b06c1  f6052cb2fa0001                     test   BYTE PTR ds:0xfab22c,0x1
004b06c8  8b353039f900                       mov    esi,DWORD PTR ds:0xf93930
004b06ce  7526                               jne    0x4b06f6
004b06d0  091d2cb2fa00                       or     DWORD PTR ds:0xfab22c,ebx
004b06d6  899c24b0010000                     mov    DWORD PTR [esp+0x1b0],ebx
004b06dd  e8aee50200                         call   0x4dec90
004b06e2  6830cebc00                         push   0xbcce30
004b06e7  e82e1c3e00                         call   0x89231a
004b06ec  83c404                             add    esp,0x4
004b06ef  89bc24b0010000                     mov    DWORD PTR [esp+0x1b0],edi
004b06f6  8d4c2434                           lea    ecx,[esp+0x34]
004b06fa  51                                 push   ecx
004b06fb  8d442434                           lea    eax,[esp+0x34]
004b06ff  b948b1fa00                         mov    ecx,0xfab148
004b0704  89742438                           mov    DWORD PTR [esp+0x38],esi
004b0708  e8b3313900                         call   0x8438c0
004b070d  8b442430                           mov    eax,DWORD PTR [esp+0x30]
004b0711  3b054cb1fa00                       cmp    eax,DWORD PTR ds:0xfab14c
004b0717  7406                               je     0x4b071f
004b0719  83781000                           cmp    DWORD PTR [eax+0x10],0x0
004b071d  7517                               jne    0x4b0736
004b071f  68506bc000                         push   0xc06b50
004b0724  e837d42300                         call   0x6edb60
004b0729  83c404                             add    esp,0x4
004b072c  b805400080                         mov    eax,0x80004005
004b0731  e9b8110000                         jmp    0x4b18ee
004b0736  8b450c                             mov    eax,DWORD PTR [ebp+0xc]
004b0739  83f802                             cmp    eax,0x2
004b073c  7304                               jae    0x4b0742
004b073e  33d2                               xor    edx,edx
004b0740  eb0d                               jmp    0x4b074f
004b0742  8d50fe                             lea    edx,[eax-0x2]
004b0745  b84fecc44e                         mov    eax,0x4ec4ec4f
004b074a  f7e2                               mul    edx
004b074c  c1ea02                             shr    edx,0x2
004b074f  89542434                           mov    DWORD PTR [esp+0x34],edx
004b0753  c744243800000000                   mov    DWORD PTR [esp+0x38],0x0
004b075b  85d2                               test   edx,edx
004b075d  0f8489110000                       je     0x4b18ec
004b0763  eb03                               jmp    0x4b0768
004b0765  83cfff                             or     edi,0xffffffff
004b0768  8b442438                           mov    eax,DWORD PTR [esp+0x38]
004b076c  8b4c2444                           mov    ecx,DWORD PTR [esp+0x44]
004b0770  6bc00d                             imul   eax,eax,0xd
004b0773  f6052cb2fa0001                     test   BYTE PTR ds:0xfab22c,0x1
004b077a  be01000000                         mov    esi,0x1
004b077f  8d5c0802                           lea    ebx,[eax+ecx*1+0x2]
004b0783  752a                               jne    0x4b07af
004b0785  09352cb2fa00                       or     DWORD PTR ds:0xfab22c,esi
004b078b  c78424b001000002000000             mov    DWORD PTR [esp+0x1b0],0x2
004b0796  e8f5e40200                         call   0x4dec90
004b079b  6830cebc00                         push   0xbcce30
004b07a0  e8751b3e00                         call   0x89231a
004b07a5  83c404                             add    esp,0x4
004b07a8  89bc24b0010000                     mov    DWORD PTR [esp+0x1b0],edi
004b07af  0fb713                             movzx  edx,WORD PTR [ebx]
004b07b2  8d442420                           lea    eax,[esp+0x20]
004b07b6  50                                 push   eax
004b07b7  8d44245c                           lea    eax,[esp+0x5c]
004b07bb  b938b1fa00                         mov    ecx,0xfab138
004b07c0  89542424                           mov    DWORD PTR [esp+0x24],edx
004b07c4  e837e73700                         call   0x82ef00
004b07c9  8b442458                           mov    eax,DWORD PTR [esp+0x58]
004b07cd  3b053cb1fa00                       cmp    eax,DWORD PTR ds:0xfab13c
004b07d3  750a                               jne    0x4b07df
004b07d5  c744242800000000                   mov    DWORD PTR [esp+0x28],0x0
004b07dd  eb07                               jmp    0x4b07e6
004b07df  8b4810                             mov    ecx,DWORD PTR [eax+0x10]
004b07e2  894c2428                           mov    DWORD PTR [esp+0x28],ecx
004b07e6  f6052cb2fa0001                     test   BYTE PTR ds:0xfab22c,0x1
004b07ed  752a                               jne    0x4b0819
004b07ef  09352cb2fa00                       or     DWORD PTR ds:0xfab22c,esi
004b07f5  c78424b001000003000000             mov    DWORD PTR [esp+0x1b0],0x3
004b0800  e88be40200                         call   0x4dec90
004b0805  6830cebc00                         push   0xbcce30
004b080a  e80b1b3e00                         call   0x89231a
004b080f  83c404                             add    esp,0x4
004b0812  89bc24b0010000                     mov    DWORD PTR [esp+0x1b0],edi
004b0819  0fb75302                           movzx  edx,WORD PTR [ebx+0x2]
004b081d  8d442420                           lea    eax,[esp+0x20]
004b0821  50                                 push   eax
004b0822  8d442444                           lea    eax,[esp+0x44]
004b0826  b938b1fa00                         mov    ecx,0xfab138
004b082b  89542424                           mov    DWORD PTR [esp+0x24],edx
004b082f  e8cce63700                         call   0x82ef00
004b0834  8b442440                           mov    eax,DWORD PTR [esp+0x40]
004b0838  3b053cb1fa00                       cmp    eax,DWORD PTR ds:0xfab13c
004b083e  7504                               jne    0x4b0844
004b0840  33ff                               xor    edi,edi
004b0842  eb03                               jmp    0x4b0847
004b0844  8b7810                             mov    edi,DWORD PTR [eax+0x10]
004b0847  837c242800                         cmp    DWORD PTR [esp+0x28],0x0
004b084c  897c2420                           mov    DWORD PTR [esp+0x20],edi
004b0850  7512                               jne    0x4b0864
004b0852  68686bc000                         push   0xc06b68
004b0857  e804d32300                         call   0x6edb60
004b085c  83c404                             add    esp,0x4
004b085f  e975100000                         jmp    0x4b18d9
004b0864  85ff                               test   edi,edi
004b0866  7512                               jne    0x4b087a
004b0868  68946bc000                         push   0xc06b94
004b086d  e8eed22300                         call   0x6edb60
004b0872  83c404                             add    esp,0x4
004b0875  e95f100000                         jmp    0x4b18d9
004b087a  f6059043f90001                     test   BYTE PTR ds:0xf94390,0x1
004b0881  8bb79c000000                       mov    esi,DWORD PTR [edi+0x9c]
004b0887  752f                               jne    0x4b08b8
004b0889  830d9043f90001                     or     DWORD PTR ds:0xf94390,0x1
004b0890  c78424b001000004000000             mov    DWORD PTR [esp+0x1b0],0x4
004b089b  e8f00c0300                         call   0x4e1590
004b08a0  6880ccbc00                         push   0xbccc80
004b08a5  e8701a3e00                         call   0x89231a
004b08aa  83c404                             add    esp,0x4
004b08ad  c78424b0010000ffffffff             mov    DWORD PTR [esp+0x1b0],0xffffffff
004b08b8  3b353039f900                       cmp    esi,DWORD PTR ds:0xf93930
004b08be  7529                               jne    0x4b08e9
004b08c0  833d18abfb0000                     cmp    DWORD PTR ds:0xfbab18,0x0
004b08c7  7420                               je     0x4b08e9
004b08c9  0f57c0                             xorps  xmm0,xmm0
004b08cc  f30f110524abfb00                   movss  DWORD PTR ds:0xfbab24,xmm0
004b08d4  e887e7f5ff                         call   0x40f060
004b08d9  f30f10057059c500                   movss  xmm0,DWORD PTR ds:0xc55970
004b08e1  f30f1180ac000000                   movss  DWORD PTR [eax+0xac],xmm0
004b08e9  8bb75c010000                       mov    esi,DWORD PTR [edi+0x15c]
004b08ef  f30f1097a8000000                   movss  xmm2,DWORD PTR [edi+0xa8]
004b08f7  f30f1087a0000000                   movss  xmm0,DWORD PTR [edi+0xa0]
004b08ff  f30f108fa4000000                   movss  xmm1,DWORD PTR [edi+0xa4]
004b0907  f30f1154242c                       movss  DWORD PTR [esp+0x2c],xmm2
004b090d  f30f1144245c                       movss  DWORD PTR [esp+0x5c],xmm0
004b0913  f30f114c2460                       movss  DWORD PTR [esp+0x60],xmm1
004b0919  f30f11442414                       movss  DWORD PTR [esp+0x14],xmm0
004b091f  f30f114c2418                       movss  DWORD PTR [esp+0x18],xmm1
004b0925  f30f1154241c                       movss  DWORD PTR [esp+0x1c],xmm2
004b092b  85f6                               test   esi,esi
004b092d  7420                               je     0x4b094f
004b092f  83bf7003000000                     cmp    DWORD PTR [edi+0x370],0x0
004b0936  7417                               je     0x4b094f
004b0938  e8c3672f00                         call   0x7a7100
004b093d  d95c2430                           fstp   DWORD PTR [esp+0x30]
004b0941  f30f104c2460                       movss  xmm1,DWORD PTR [esp+0x60]
004b0947  f30f1044245c                       movss  xmm0,DWORD PTR [esp+0x5c]
004b094d  eb09                               jmp    0x4b0958
004b094f  0f57d2                             xorps  xmm2,xmm2
004b0952  f30f11542430                       movss  DWORD PTR [esp+0x30],xmm2
004b0958  d9442430                           fld    DWORD PTR [esp+0x30]
004b095c  8a4304                             mov    al,BYTE PTR [ebx+0x4]
004b095f  dc0db056c500                       fmul   QWORD PTR ds:0xc556b0
004b0965  f30f118424b4000000                 movss  DWORD PTR [esp+0xb4],xmm0
004b096e  f30f118c24b8000000                 movss  DWORD PTR [esp+0xb8],xmm1
004b0977  d844242c                           fadd   DWORD PTR [esp+0x2c]
004b097b  d95c243c                           fstp   DWORD PTR [esp+0x3c]
004b097f  d944243c                           fld    DWORD PTR [esp+0x3c]
004b0983  d99c24bc000000                     fstp   DWORD PTR [esp+0xbc]
004b098a  84c0                               test   al,al
004b098c  740c                               je     0x4b099a
004b098e  3c02                               cmp    al,0x2
004b0990  7408                               je     0x4b099a
004b0992  3c01                               cmp    al,0x1
004b0994  0f85e4000000                       jne    0x4b0a7e
004b099a  8b0da4a7fb00                       mov    ecx,DWORD PTR ds:0xfba7a4
004b09a0  668b33                             mov    si,WORD PTR [ebx]
004b09a3  33c0                               xor    eax,eax
004b09a5  83c10c                             add    ecx,0xc
004b09a8  8b11                               mov    edx,DWORD PTR [ecx]
004b09aa  85d2                               test   edx,edx
004b09ac  7406                               je     0x4b09b4
004b09ae  66397204                           cmp    WORD PTR [edx+0x4],si
004b09b2  740e                               je     0x4b09c2
004b09b4  40                                 inc    eax
004b09b5  83c10c                             add    ecx,0xc
004b09b8  83f803                             cmp    eax,0x3
004b09bb  7ceb                               jl     0x4b09a8
004b09bd  e9bc000000                         jmp    0x4b0a7e
004b09c2  83f8ff                             cmp    eax,0xffffffff
004b09c5  0f84b3000000                       je     0x4b0a7e
004b09cb  f6052cb2fa0001                     test   BYTE PTR ds:0xfab22c,0x1
004b09d2  752f                               jne    0x4b0a03
004b09d4  830d2cb2fa0001                     or     DWORD PTR ds:0xfab22c,0x1
004b09db  c78424b001000005000000             mov    DWORD PTR [esp+0x1b0],0x5
004b09e6  e8a5e20200                         call   0x4dec90
004b09eb  6830cebc00                         push   0xbcce30
004b09f0  e825193e00                         call   0x89231a
004b09f5  83c404                             add    esp,0x4
004b09f8  c78424b0010000ffffffff             mov    DWORD PTR [esp+0x1b0],0xffffffff
004b0a03  8b0d34b1fa00                       mov    ecx,DWORD PTR ds:0xfab134
004b0a09  8b5124                             mov    edx,DWORD PTR [ecx+0x24]
004b0a0c  2b5120                             sub    edx,DWORD PTR [ecx+0x20]
004b0a0f  33c0                               xor    eax,eax
004b0a11  d1fa                               sar    edx,1
004b0a13  c644242700                         mov    BYTE PTR [esp+0x27],0x0
004b0a18  7464                               je     0x4b0a7e
004b0a1a  8b7120                             mov    esi,DWORD PTR [ecx+0x20]
004b0a1d  8d4900                             lea    ecx,[ecx+0x0]
004b0a20  0fb75302                           movzx  edx,WORD PTR [ebx+0x2]
004b0a24  663916                             cmp    WORD PTR [esi],dx
004b0a27  7505                               jne    0x4b0a2e
004b0a29  c644242701                         mov    BYTE PTR [esp+0x27],0x1
004b0a2e  8b5124                             mov    edx,DWORD PTR [ecx+0x24]
004b0a31  2b5120                             sub    edx,DWORD PTR [ecx+0x20]
004b0a34  40                                 inc    eax
004b0a35  d1fa                               sar    edx,1
004b0a37  83c602                             add    esi,0x2
004b0a3a  3bc2                               cmp    eax,edx
004b0a3c  72e2                               jb     0x4b0a20
004b0a3e  807c242700                         cmp    BYTE PTR [esp+0x27],0x0
004b0a43  7439                               je     0x4b0a7e
004b0a45  e816e6f5ff                         call   0x40f060
004b0a4a  8b5004                             mov    edx,DWORD PTR [eax+0x4]
004b0a4d  8b4a24                             mov    ecx,DWORD PTR [edx+0x24]
004b0a50  2b4a20                             sub    ecx,DWORD PTR [edx+0x20]
004b0a53  0fb77b02                           movzx  edi,WORD PTR [ebx+0x2]
004b0a57  33c0                               xor    eax,eax
004b0a59  d1f9                               sar    ecx,1
004b0a5b  741d                               je     0x4b0a7a
004b0a5d  8b7220                             mov    esi,DWORD PTR [edx+0x20]
004b0a60  66393e                             cmp    WORD PTR [esi],di
004b0a63  740a                               je     0x4b0a6f
004b0a65  40                                 inc    eax
004b0a66  83c602                             add    esi,0x2
004b0a69  3bc1                               cmp    eax,ecx
004b0a6b  72f3                               jb     0x4b0a60
004b0a6d  eb0b                               jmp    0x4b0a7a
004b0a6f  8b4a20                             mov    ecx,DWORD PTR [edx+0x20]
004b0a72  668b0441                           mov    ax,WORD PTR [ecx+eax*2]
004b0a76  66894230                           mov    WORD PTR [edx+0x30],ax
004b0a7a  8b7c2420                           mov    edi,DWORD PTR [esp+0x20]
004b0a7e  f6052cb2fa0001                     test   BYTE PTR ds:0xfab22c,0x1
004b0a85  752f                               jne    0x4b0ab6
004b0a87  830d2cb2fa0001                     or     DWORD PTR ds:0xfab22c,0x1
004b0a8e  c78424b001000006000000             mov    DWORD PTR [esp+0x1b0],0x6
004b0a99  e8f2e10200                         call   0x4dec90
004b0a9e  6830cebc00                         push   0xbcce30
004b0aa3  e872183e00                         call   0x89231a
004b0aa8  83c404                             add    esp,0x4
004b0aab  c78424b0010000ffffffff             mov    DWORD PTR [esp+0x1b0],0xffffffff
004b0ab6  8b1534b1fa00                       mov    edx,DWORD PTR ds:0xfab134
004b0abc  8b7224                             mov    esi,DWORD PTR [edx+0x24]
004b0abf  2b7220                             sub    esi,DWORD PTR [edx+0x20]
004b0ac2  32c9                               xor    cl,cl
004b0ac4  33c0                               xor    eax,eax
004b0ac6  d1fe                               sar    esi,1
004b0ac8  0f8485000000                       je     0x4b0b53
004b0ace  8b7220                             mov    esi,DWORD PTR [edx+0x20]
004b0ad1  0fb77b02                           movzx  edi,WORD PTR [ebx+0x2]
004b0ad5  66393e                             cmp    WORD PTR [esi],di
004b0ad8  7502                               jne    0x4b0adc
004b0ada  b101                               mov    cl,0x1
004b0adc  8b7a24                             mov    edi,DWORD PTR [edx+0x24]
004b0adf  2b7a20                             sub    edi,DWORD PTR [edx+0x20]
004b0ae2  40                                 inc    eax
004b0ae3  d1ff                               sar    edi,1
004b0ae5  83c602                             add    esi,0x2
004b0ae8  3bc7                               cmp    eax,edi
004b0aea  72e5                               jb     0x4b0ad1
004b0aec  84c9                               test   cl,cl
004b0aee  745f                               je     0x4b0b4f
004b0af0  807b0401                           cmp    BYTE PTR [ebx+0x4],0x1
004b0af4  7508                               jne    0x4b0afe
004b0af6  8b4306                             mov    eax,DWORD PTR [ebx+0x6]
004b0af9  f7d8                               neg    eax
004b0afb  894306                             mov    DWORD PTR [ebx+0x6],eax
004b0afe  f6059043f90001                     test   BYTE PTR ds:0xf94390,0x1
004b0b05  752f                               jne    0x4b0b36
004b0b07  830d9043f90001                     or     DWORD PTR ds:0xf94390,0x1
004b0b0e  c78424b001000007000000             mov    DWORD PTR [esp+0x1b0],0x7
004b0b19  e8720a0300                         call   0x4e1590
004b0b1e  6880ccbc00                         push   0xbccc80
004b0b23  e8f2173e00                         call   0x89231a
004b0b28  83c404                             add    esp,0x4
004b0b2b  c78424b0010000ffffffff             mov    DWORD PTR [esp+0x1b0],0xffffffff
004b0b36  8b4b06                             mov    ecx,DWORD PTR [ebx+0x6]
004b0b39  8b7c2420                           mov    edi,DWORD PTR [esp+0x20]
004b0b3d  33f6                               xor    esi,esi
004b0b3f  010dc442f900                       add    DWORD PTR ds:0xf942c4,ecx
004b0b45  790e                               jns    0x4b0b55
004b0b47  8935c442f900                       mov    DWORD PTR ds:0xf942c4,esi
004b0b4d  eb06                               jmp    0x4b0b55
004b0b4f  8b7c2420                           mov    edi,DWORD PTR [esp+0x20]
004b0b53  33f6                               xor    esi,esi
004b0b55  0fbe4304                           movsx  eax,BYTE PTR [ebx+0x4]
004b0b59  83f808                             cmp    eax,0x8
004b0b5c  0f87770d0000                       ja     0x4b18d9
004b0b62  ff248514194b00                     jmp    DWORD PTR [eax*4+0x4b1914]
004b0b69  8b542428                           mov    edx,DWORD PTR [esp+0x28]
004b0b6d  668b4a04                           mov    cx,WORD PTR [edx+0x4]
004b0b71  0fbe530c                           movsx  edx,BYTE PTR [ebx+0xc]
004b0b75  0fb74704                           movzx  eax,WORD PTR [edi+0x4]
004b0b79  52                                 push   edx
004b0b7a  0fbe5305                           movsx  edx,BYTE PTR [ebx+0x5]
004b0b7e  52                                 push   edx
004b0b7f  50                                 push   eax
004b0b80  33c0                               xor    eax,eax
004b0b82  80f901                             cmp    cl,0x1
004b0b85  0f94c0                             sete   al
004b0b88  8d9424c0000000                     lea    edx,[esp+0xc0]
004b0b8f  52                                 push   edx
004b0b90  50                                 push   eax
004b0b91  e8aaa5feff                         call   0x49b140
004b0b96  50                                 push   eax
004b0b97  e834160a00                         call   0x5521d0
004b0b9c  d944242c                           fld    DWORD PTR [esp+0x2c]
004b0ba0  dc05205dc500                       fadd   QWORD PTR ds:0xc55d20
004b0ba6  b806000000                         mov    eax,0x6
004b0bab  89b70c040000                       mov    DWORD PTR [edi+0x40c],esi
004b0bb1  8b35a4a7fb00                       mov    esi,DWORD PTR ds:0xfba7a4
004b0bb7  898714040000                       mov    DWORD PTR [edi+0x414],eax
004b0bbd  d95c241c                           fstp   DWORD PTR [esp+0x1c]
004b0bc1  898710040000                       mov    DWORD PTR [edi+0x410],eax
004b0bc7  0fb70b                             movzx  ecx,WORD PTR [ebx]
004b0bca  51                                 push   ecx
004b0bcb  8bd6                               mov    edx,esi
004b0bcd  e88e460900                         call   0x545260
004b0bd2  83f8ff                             cmp    eax,0xffffffff
004b0bd5  7446                               je     0x4b0c1d
004b0bd7  8b542414                           mov    edx,DWORD PTR [esp+0x14]
004b0bdb  8b4c2418                           mov    ecx,DWORD PTR [esp+0x18]
004b0bdf  83ec0c                             sub    esp,0xc
004b0be2  8bc4                               mov    eax,esp
004b0be4  8910                               mov    DWORD PTR [eax],edx
004b0be6  8b542428                           mov    edx,DWORD PTR [esp+0x28]
004b0bea  894804                             mov    DWORD PTR [eax+0x4],ecx
004b0bed  6a01                               push   0x1
004b0bef  895008                             mov    DWORD PTR [eax+0x8],edx
004b0bf2  e8d9a4feff                         call   0x49b0d0
004b0bf7  8b4b06                             mov    ecx,DWORD PTR [ebx+0x6]
004b0bfa  8bd0                               mov    edx,eax
004b0bfc  e8cfb02f00                         call   0x7abcd0
004b0c01  8b4306                             mov    eax,DWORD PTR [ebx+0x6]
004b0c04  50                                 push   eax
004b0c05  68c06bc000                         push   0xc06bc0
004b0c0a  e871c3f5ff                         call   0x40cf80
004b0c0f  50                                 push   eax
004b0c10  e83bccfeff                         call   0x49d850
004b0c15  83c40c                             add    esp,0xc
004b0c18  e9b9000000                         jmp    0x4b0cd6
004b0c1d  0fb74b02                           movzx  ecx,WORD PTR [ebx+0x2]
004b0c21  51                                 push   ecx
004b0c22  8bd6                               mov    edx,esi
004b0c24  e837460900                         call   0x545260
004b0c29  83f8ff                             cmp    eax,0xffffffff
004b0c2c  0f84a4000000                       je     0x4b0cd6
004b0c32  8b542414                           mov    edx,DWORD PTR [esp+0x14]
004b0c36  8b4c2418                           mov    ecx,DWORD PTR [esp+0x18]
004b0c3a  83ec0c                             sub    esp,0xc
004b0c3d  8bc4                               mov    eax,esp
004b0c3f  8910                               mov    DWORD PTR [eax],edx
004b0c41  8b542428                           mov    edx,DWORD PTR [esp+0x28]
004b0c45  894804                             mov    DWORD PTR [eax+0x4],ecx
004b0c48  6a00                               push   0x0
004b0c4a  895008                             mov    DWORD PTR [eax+0x8],edx
004b0c4d  e87ea4feff                         call   0x49b0d0
004b0c52  8b4b06                             mov    ecx,DWORD PTR [ebx+0x6]
004b0c55  8bd0                               mov    edx,eax
004b0c57  e874b02f00                         call   0x7abcd0
004b0c5c  8b4306                             mov    eax,DWORD PTR [ebx+0x6]
004b0c5f  50                                 push   eax
004b0c60  68e06bc000                         push   0xc06be0
004b0c65  e816c3f5ff                         call   0x40cf80
004b0c6a  50                                 push   eax
004b0c6b  e8e0cbfeff                         call   0x49d850
004b0c70  83c40c                             add    esp,0xc
004b0c73  e86893fdff                         call   0x489fe0
004b0c78  8bf0                               mov    esi,eax
004b0c7a  e8d18d0a00                         call   0x559a50
004b0c7f  e8dc8ffdff                         call   0x489c60
004b0c84  33c9                               xor    ecx,ecx
004b0c86  8bd0                               mov    edx,eax
004b0c88  833a04                             cmp    DWORD PTR [edx],0x4
004b0c8b  7f49                               jg     0x4b0cd6
004b0c8d  41                                 inc    ecx
004b0c8e  83c214                             add    edx,0x14
004b0c91  83f920                             cmp    ecx,0x20
004b0c94  7cf2                               jl     0x4b0c88
004b0c96  33f6                               xor    esi,esi
004b0c98  33c9                               xor    ecx,ecx
004b0c9a  8bd0                               mov    edx,eax
004b0c9c  8d642400                           lea    esp,[esp+0x0]
004b0ca0  3932                               cmp    DWORD PTR [edx],esi
004b0ca2  740b                               je     0x4b0caf
004b0ca4  41                                 inc    ecx
004b0ca5  83c214                             add    edx,0x14
004b0ca8  83f920                             cmp    ecx,0x20
004b0cab  7cf3                               jl     0x4b0ca0
004b0cad  eb27                               jmp    0x4b0cd6
004b0caf  0f57c0                             xorps  xmm0,xmm0
004b0cb2  8d0c89                             lea    ecx,[ecx+ecx*4]
004b0cb5  8d0488                             lea    eax,[eax+ecx*4]
004b0cb8  f30f114004                         movss  DWORD PTR [eax+0x4],xmm0
004b0cbd  f30f10050858c500                   movss  xmm0,DWORD PTR ds:0xc55808
004b0cc5  c70004000000                       mov    DWORD PTR [eax],0x4
004b0ccb  f30f114008                         movss  DWORD PTR [eax+0x8],xmm0
004b0cd0  89700c                             mov    DWORD PTR [eax+0xc],esi
004b0cd3  897010                             mov    DWORD PTR [eax+0x10],esi
004b0cd6  8b442428                           mov    eax,DWORD PTR [esp+0x28]
004b0cda  8bb05c010000                       mov    esi,DWORD PTR [eax+0x15c]
004b0ce0  85f6                               test   esi,esi
004b0ce2  0f84c30b0000                       je     0x4b18ab
004b0ce8  83b87003000000                     cmp    DWORD PTR [eax+0x370],0x0
004b0cef  0f84b60b0000                       je     0x4b18ab
004b0cf5  83beac00000000                     cmp    DWORD PTR [esi+0xac],0x0
004b0cfc  0f84a90b0000                       je     0x4b18ab
004b0d02  8b8eac000000                       mov    ecx,DWORD PTR [esi+0xac]
004b0d08  8b11                               mov    edx,DWORD PTR [ecx]
004b0d0a  8b4230                             mov    eax,DWORD PTR [edx+0x30]
004b0d0d  ffd0                               call   eax
004b0d0f  e9860b0000                         jmp    0x4b189a
004b0d14  d9e8                               fld1
004b0d16  0fb75704                           movzx  edx,WORD PTR [edi+0x4]
004b0d1a  83ec08                             sub    esp,0x8
004b0d1d  83c9ff                             or     ecx,0xffffffff
004b0d20  898c249c000000                     mov    DWORD PTR [esp+0x9c],ecx
004b0d27  d95c2404                           fstp   DWORD PTR [esp+0x4]
004b0d2b  898c24a0000000                     mov    DWORD PTR [esp+0xa0],ecx
004b0d32  d9ee                               fldz
004b0d34  8d8c24bc000000                     lea    ecx,[esp+0xbc]
004b0d3b  d91c24                             fstp   DWORD PTR [esp]
004b0d3e  51                                 push   ecx
004b0d3f  52                                 push   edx
004b0d40  c784249c00000002000000             mov    DWORD PTR [esp+0x9c],0x2
004b0d4b  c78424a0000000046cc000             mov    DWORD PTR [esp+0xa0],0xc06c04
004b0d56  89b424ac000000                     mov    DWORD PTR [esp+0xac],esi
004b0d5d  e8dea3feff                         call   0x49b140
004b0d62  8d94249c000000                     lea    edx,[esp+0x9c]
004b0d69  8bc8                               mov    ecx,eax
004b0d6b  e8b0110a00                         call   0x551f20
004b0d70  d944242c                           fld    DWORD PTR [esp+0x2c]
004b0d74  b806000000                         mov    eax,0x6
004b0d79  dc05205dc500                       fadd   QWORD PTR ds:0xc55d20
004b0d7f  89b70c040000                       mov    DWORD PTR [edi+0x40c],esi
004b0d85  8b35a4a7fb00                       mov    esi,DWORD PTR ds:0xfba7a4
004b0d8b  898714040000                       mov    DWORD PTR [edi+0x414],eax
004b0d91  898710040000                       mov    DWORD PTR [edi+0x410],eax
004b0d97  d95c241c                           fstp   DWORD PTR [esp+0x1c]
004b0d9b  0fb703                             movzx  eax,WORD PTR [ebx]
004b0d9e  50                                 push   eax
004b0d9f  8bd6                               mov    edx,esi
004b0da1  e8ba440900                         call   0x545260
004b0da6  83f8ff                             cmp    eax,0xffffffff
004b0da9  7511                               jne    0x4b0dbc
004b0dab  0fb75302                           movzx  edx,WORD PTR [ebx+0x2]
004b0daf  52                                 push   edx
004b0db0  8bd6                               mov    edx,esi
004b0db2  e8a9440900                         call   0x545260
004b0db7  83f8ff                             cmp    eax,0xffffffff
004b0dba  7429                               je     0x4b0de5
004b0dbc  8b4c2414                           mov    ecx,DWORD PTR [esp+0x14]
004b0dc0  8b542418                           mov    edx,DWORD PTR [esp+0x18]
004b0dc4  83ec0c                             sub    esp,0xc
004b0dc7  8bc4                               mov    eax,esp
004b0dc9  8908                               mov    DWORD PTR [eax],ecx
004b0dcb  8b4c2428                           mov    ecx,DWORD PTR [esp+0x28]
004b0dcf  895004                             mov    DWORD PTR [eax+0x4],edx
004b0dd2  894808                             mov    DWORD PTR [eax+0x8],ecx
004b0dd5  e8f6a2feff                         call   0x49b0d0
004b0dda  50                                 push   eax
004b0ddb  b801000000                         mov    eax,0x1
004b0de0  e84bb22f00                         call   0x7ac030
004b0de5  8bb75c010000                       mov    esi,DWORD PTR [edi+0x15c]
004b0deb  85f6                               test   esi,esi
004b0ded  7433                               je     0x4b0e22
004b0def  83bf7003000000                     cmp    DWORD PTR [edi+0x370],0x0
004b0df6  742a                               je     0x4b0e22
004b0df8  83beac00000000                     cmp    DWORD PTR [esi+0xac],0x0
004b0dff  7421                               je     0x4b0e22
004b0e01  8b8eac000000                       mov    ecx,DWORD PTR [esi+0xac]
004b0e07  8b11                               mov    edx,DWORD PTR [ecx]
004b0e09  8b4230                             mov    eax,DWORD PTR [edx+0x30]
004b0e0c  ffd0                               call   eax
004b0e0e  81c6b4000000                       add    esi,0xb4
004b0e14  0fb6c8                             movzx  ecx,al
004b0e17  56                                 push   esi
004b0e18  ba01000000                         mov    edx,0x1
004b0e1d  e8be1a3200                         call   0x7d28e0
004b0e22  8b4c2428                           mov    ecx,DWORD PTR [esp+0x28]
004b0e26  8b815c010000                       mov    eax,DWORD PTR [ecx+0x15c]
004b0e2c  85c0                               test   eax,eax
004b0e2e  0f84a50a0000                       je     0x4b18d9
004b0e34  8bd1                               mov    edx,ecx
004b0e36  83ba7003000000                     cmp    DWORD PTR [edx+0x370],0x0
004b0e3d  0f84960a0000                       je     0x4b18d9
004b0e43  83b8ac00000000                     cmp    DWORD PTR [eax+0xac],0x0
004b0e4a  0f84890a0000                       je     0x4b18d9
004b0e50  ba01000000                         mov    edx,0x1
004b0e55  e96f0a0000                         jmp    0x4b18c9
004b0e5a  d944242c                           fld    DWORD PTR [esp+0x2c]
004b0e5e  0fb703                             movzx  eax,WORD PTR [ebx]
004b0e61  dc05205dc500                       fadd   QWORD PTR ds:0xc55d20
004b0e67  8b35a4a7fb00                       mov    esi,DWORD PTR ds:0xfba7a4
004b0e6d  50                                 push   eax
004b0e6e  8bd6                               mov    edx,esi
004b0e70  d95c2420                           fstp   DWORD PTR [esp+0x20]
004b0e74  e8e7430900                         call   0x545260
004b0e79  83f8ff                             cmp    eax,0xffffffff
004b0e7c  742b                               je     0x4b0ea9
004b0e7e  8b4c2414                           mov    ecx,DWORD PTR [esp+0x14]
004b0e82  8b542418                           mov    edx,DWORD PTR [esp+0x18]
004b0e86  83ec0c                             sub    esp,0xc
004b0e89  8bc4                               mov    eax,esp
004b0e8b  8908                               mov    DWORD PTR [eax],ecx
004b0e8d  8b4c2428                           mov    ecx,DWORD PTR [esp+0x28]
004b0e91  895004                             mov    DWORD PTR [eax+0x4],edx
004b0e94  894808                             mov    DWORD PTR [eax+0x8],ecx
004b0e97  e834a2feff                         call   0x49b0d0
004b0e9c  50                                 push   eax
004b0e9d  33c0                               xor    eax,eax
004b0e9f  e88cb12f00                         call   0x7ac030
004b0ea4  e9300a0000                         jmp    0x4b18d9
004b0ea9  0fb75302                           movzx  edx,WORD PTR [ebx+0x2]
004b0ead  52                                 push   edx
004b0eae  8bd6                               mov    edx,esi
004b0eb0  e8ab430900                         call   0x545260
004b0eb5  83f8ff                             cmp    eax,0xffffffff
004b0eb8  0f841b0a0000                       je     0x4b18d9
004b0ebe  8b4c2414                           mov    ecx,DWORD PTR [esp+0x14]
004b0ec2  8b542418                           mov    edx,DWORD PTR [esp+0x18]
004b0ec6  83ec0c                             sub    esp,0xc
004b0ec9  8bc4                               mov    eax,esp
004b0ecb  8908                               mov    DWORD PTR [eax],ecx
004b0ecd  8b4c2428                           mov    ecx,DWORD PTR [esp+0x28]
004b0ed1  895004                             mov    DWORD PTR [eax+0x4],edx
004b0ed4  894808                             mov    DWORD PTR [eax+0x8],ecx
004b0ed7  e8f4a1feff                         call   0x49b0d0
004b0edc  50                                 push   eax
004b0edd  b802000000                         mov    eax,0x2
004b0ee2  e849b12f00                         call   0x7ac030
004b0ee7  e9ed090000                         jmp    0x4b18d9
004b0eec  d9e8                               fld1
004b0eee  0fb74704                           movzx  eax,WORD PTR [edi+0x4]
004b0ef2  83ec08                             sub    esp,0x8
004b0ef5  8d9424bc000000                     lea    edx,[esp+0xbc]
004b0efc  83c9ff                             or     ecx,0xffffffff
004b0eff  d95c2404                           fstp   DWORD PTR [esp+0x4]
004b0f03  c784248000000002000000             mov    DWORD PTR [esp+0x80],0x2
004b0f0e  d9ee                               fldz
004b0f10  c78424840000000c6cc000             mov    DWORD PTR [esp+0x84],0xc06c0c
004b0f1b  d91c24                             fstp   DWORD PTR [esp]
004b0f1e  52                                 push   edx
004b0f1f  50                                 push   eax
004b0f20  898c2490000000                     mov    DWORD PTR [esp+0x90],ecx
004b0f27  898c2494000000                     mov    DWORD PTR [esp+0x94],ecx
004b0f2e  89b42498000000                     mov    DWORD PTR [esp+0x98],esi
004b0f35  e806a2feff                         call   0x49b140
004b0f3a  8d942488000000                     lea    edx,[esp+0x88]
004b0f41  8bc8                               mov    ecx,eax
004b0f43  e8d80f0a00                         call   0x551f20
004b0f48  d944242c                           fld    DWORD PTR [esp+0x2c]
004b0f4c  b806000000                         mov    eax,0x6
004b0f51  dc05205dc500                       fadd   QWORD PTR ds:0xc55d20
004b0f57  89b70c040000                       mov    DWORD PTR [edi+0x40c],esi
004b0f5d  8b35a4a7fb00                       mov    esi,DWORD PTR ds:0xfba7a4
004b0f63  898714040000                       mov    DWORD PTR [edi+0x414],eax
004b0f69  898710040000                       mov    DWORD PTR [edi+0x410],eax
004b0f6f  d95c241c                           fstp   DWORD PTR [esp+0x1c]
004b0f73  0fb70b                             movzx  ecx,WORD PTR [ebx]
004b0f76  51                                 push   ecx
004b0f77  8bd6                               mov    edx,esi
004b0f79  e8e2420900                         call   0x545260
004b0f7e  83f8ff                             cmp    eax,0xffffffff
004b0f81  0f84d4000000                       je     0x4b105b
004b0f87  8b542414                           mov    edx,DWORD PTR [esp+0x14]
004b0f8b  8b4c2418                           mov    ecx,DWORD PTR [esp+0x18]
004b0f8f  83ec0c                             sub    esp,0xc
004b0f92  8bc4                               mov    eax,esp
004b0f94  8910                               mov    DWORD PTR [eax],edx
004b0f96  8b542428                           mov    edx,DWORD PTR [esp+0x28]
004b0f9a  894804                             mov    DWORD PTR [eax+0x4],ecx
004b0f9d  6a05                               push   0x5
004b0f9f  895008                             mov    DWORD PTR [eax+0x8],edx
004b0fa2  e829a1feff                         call   0x49b0d0
004b0fa7  8b4b06                             mov    ecx,DWORD PTR [ebx+0x6]
004b0faa  8bd0                               mov    edx,eax
004b0fac  e81fad2f00                         call   0x7abcd0
004b0fb1  8b4306                             mov    eax,DWORD PTR [ebx+0x6]
004b0fb4  50                                 push   eax
004b0fb5  68186cc000                         push   0xc06c18
004b0fba  e8c1bff5ff                         call   0x40cf80
004b0fbf  50                                 push   eax
004b0fc0  e88bc8feff                         call   0x49d850
004b0fc5  83c40c                             add    esp,0xc
004b0fc8  e81390fdff                         call   0x489fe0
004b0fcd  f30f1005c056c400                   movss  xmm0,DWORD PTR ds:0xc456c0
004b0fd5  f30f100dd057c500                   movss  xmm1,DWORD PTR ds:0xc557d0
004b0fdd  c7405424000000                     mov    DWORD PTR [eax+0x54],0x24
004b0fe4  f30f11404c                         movss  DWORD PTR [eax+0x4c],xmm0
004b0fe9  f30f114850                         movss  DWORD PTR [eax+0x50],xmm1
004b0fee  c740740e000000                     mov    DWORD PTR [eax+0x74],0xe
004b0ff5  f30f11406c                         movss  DWORD PTR [eax+0x6c],xmm0
004b0ffa  f30f114870                         movss  DWORD PTR [eax+0x70],xmm1
004b0fff  e8cc3af9ff                         call   0x444ad0
004b1004  80b88d01000000                     cmp    BYTE PTR [eax+0x18d],0x0
004b100b  0f8505010000                       jne    0x4b1116
004b1011  e84a8cfdff                         call   0x489c60
004b1016  33c9                               xor    ecx,ecx
004b1018  8bd0                               mov    edx,eax
004b101a  8d9b00000000                       lea    ebx,[ebx+0x0]
004b1020  833a05                             cmp    DWORD PTR [edx],0x5
004b1023  0f8fed000000                       jg     0x4b1116
004b1029  41                                 inc    ecx
004b102a  83c214                             add    edx,0x14
004b102d  83f920                             cmp    ecx,0x20
004b1030  7cee                               jl     0x4b1020
004b1032  33f6                               xor    esi,esi
004b1034  33c9                               xor    ecx,ecx
004b1036  8bd0                               mov    edx,eax
004b1038  3932                               cmp    DWORD PTR [edx],esi
004b103a  740e                               je     0x4b104a
004b103c  41                                 inc    ecx
004b103d  83c214                             add    edx,0x14
004b1040  83f920                             cmp    ecx,0x20
004b1043  7cf3                               jl     0x4b1038
004b1045  e9cc000000                         jmp    0x4b1116
004b104a  8d0c89                             lea    ecx,[ecx+ecx*4]
004b104d  8d0488                             lea    eax,[eax+ecx*4]
004b1050  c70005000000                       mov    DWORD PTR [eax],0x5
004b1056  e9a0000000                         jmp    0x4b10fb
004b105b  0fb75302                           movzx  edx,WORD PTR [ebx+0x2]
004b105f  52                                 push   edx
004b1060  8bd6                               mov    edx,esi
004b1062  e8f9410900                         call   0x545260
004b1067  83f8ff                             cmp    eax,0xffffffff
004b106a  0f84a6000000                       je     0x4b1116
004b1070  8b4c2414                           mov    ecx,DWORD PTR [esp+0x14]
004b1074  8b542418                           mov    edx,DWORD PTR [esp+0x18]
004b1078  83ec0c                             sub    esp,0xc
004b107b  8bc4                               mov    eax,esp
004b107d  8908                               mov    DWORD PTR [eax],ecx
004b107f  8b4c2428                           mov    ecx,DWORD PTR [esp+0x28]
004b1083  895004                             mov    DWORD PTR [eax+0x4],edx
004b1086  6a05                               push   0x5
004b1088  894808                             mov    DWORD PTR [eax+0x8],ecx
004b108b  e840a0feff                         call   0x49b0d0
004b1090  8b4b06                             mov    ecx,DWORD PTR [ebx+0x6]
004b1093  8bd0                               mov    edx,eax
004b1095  e836ac2f00                         call   0x7abcd0
004b109a  8b5306                             mov    edx,DWORD PTR [ebx+0x6]
004b109d  52                                 push   edx
004b109e  68446cc000                         push   0xc06c44
004b10a3  e8d8bef5ff                         call   0x40cf80
004b10a8  50                                 push   eax
004b10a9  e8a2c7feff                         call   0x49d850
004b10ae  83c40c                             add    esp,0xc
004b10b1  e82a8ffdff                         call   0x489fe0
004b10b6  8bf0                               mov    esi,eax
004b10b8  e893890a00                         call   0x559a50
004b10bd  e89e8bfdff                         call   0x489c60
004b10c2  33c9                               xor    ecx,ecx
004b10c4  8bd0                               mov    edx,eax
004b10c6  833a04                             cmp    DWORD PTR [edx],0x4
004b10c9  7f4b                               jg     0x4b1116
004b10cb  41                                 inc    ecx
004b10cc  83c214                             add    edx,0x14
004b10cf  83f920                             cmp    ecx,0x20
004b10d2  7cf2                               jl     0x4b10c6
004b10d4  33f6                               xor    esi,esi
004b10d6  33c9                               xor    ecx,ecx
004b10d8  8bd0                               mov    edx,eax
004b10da  8d9b00000000                       lea    ebx,[ebx+0x0]
004b10e0  3932                               cmp    DWORD PTR [edx],esi
004b10e2  740b                               je     0x4b10ef
004b10e4  41                                 inc    ecx
004b10e5  83c214                             add    edx,0x14
004b10e8  83f920                             cmp    ecx,0x20
004b10eb  7cf3                               jl     0x4b10e0
004b10ed  eb27                               jmp    0x4b1116
004b10ef  8d0c89                             lea    ecx,[ecx+ecx*4]
004b10f2  8d0488                             lea    eax,[eax+ecx*4]
004b10f5  c70004000000                       mov    DWORD PTR [eax],0x4
004b10fb  0f57c0                             xorps  xmm0,xmm0
004b10fe  f30f114004                         movss  DWORD PTR [eax+0x4],xmm0
004b1103  f30f10050858c500                   movss  xmm0,DWORD PTR ds:0xc55808
004b110b  897010                             mov    DWORD PTR [eax+0x10],esi
004b110e  89700c                             mov    DWORD PTR [eax+0xc],esi
004b1111  f30f114008                         movss  DWORD PTR [eax+0x8],xmm0
004b1116  8bb75c010000                       mov    esi,DWORD PTR [edi+0x15c]
004b111c  85f6                               test   esi,esi
004b111e  7433                               je     0x4b1153
004b1120  83bf7003000000                     cmp    DWORD PTR [edi+0x370],0x0
004b1127  742a                               je     0x4b1153
004b1129  83beac00000000                     cmp    DWORD PTR [esi+0xac],0x0
004b1130  7421                               je     0x4b1153
004b1132  8b8eac000000                       mov    ecx,DWORD PTR [esi+0xac]
004b1138  8b11                               mov    edx,DWORD PTR [ecx]
004b113a  8b4230                             mov    eax,DWORD PTR [edx+0x30]
004b113d  ffd0                               call   eax
004b113f  81c6b4000000                       add    esi,0xb4
004b1145  0fb6c8                             movzx  ecx,al
004b1148  56                                 push   esi
004b1149  ba02000000                         mov    edx,0x2
004b114e  e88d173200                         call   0x7d28e0
004b1153  8b4c2428                           mov    ecx,DWORD PTR [esp+0x28]
004b1157  8b815c010000                       mov    eax,DWORD PTR [ecx+0x15c]
004b115d  85c0                               test   eax,eax
004b115f  0f8474070000                       je     0x4b18d9
004b1165  8bd1                               mov    edx,ecx
004b1167  83ba7003000000                     cmp    DWORD PTR [edx+0x370],0x0
004b116e  0f8465070000                       je     0x4b18d9
004b1174  83b8ac00000000                     cmp    DWORD PTR [eax+0xac],0x0
004b117b  0f8458070000                       je     0x4b18d9
004b1181  ba02000000                         mov    edx,0x2
004b1186  e93e070000                         jmp    0x4b18c9
004b118b  0fbe4b05                           movsx  ecx,BYTE PTR [ebx+0x5]
004b118f  d9e8                               fld1
004b1191  0fb75704                           movzx  edx,WORD PTR [edi+0x4]
004b1195  83ec08                             sub    esp,0x8
004b1198  898c24b4000000                     mov    DWORD PTR [esp+0xb4],ecx
004b119f  8d8c24bc000000                     lea    ecx,[esp+0xbc]
004b11a6  d95c2404                           fstp   DWORD PTR [esp+0x4]
004b11aa  89b424a8000000                     mov    DWORD PTR [esp+0xa8],esi
004b11b1  d9ee                               fldz
004b11b3  c78424ac000000706cc000             mov    DWORD PTR [esp+0xac],0xc06c70
004b11be  d91c24                             fstp   DWORD PTR [esp]
004b11c1  51                                 push   ecx
004b11c2  52                                 push   edx
004b11c3  89b424b8000000                     mov    DWORD PTR [esp+0xb8],esi
004b11ca  89b424c0000000                     mov    DWORD PTR [esp+0xc0],esi
004b11d1  e86a9ffeff                         call   0x49b140
004b11d6  8d9424b0000000                     lea    edx,[esp+0xb0]
004b11dd  8bc8                               mov    ecx,eax
004b11df  e83c0d0a00                         call   0x551f20
004b11e4  d944242c                           fld    DWORD PTR [esp+0x2c]
004b11e8  0fb703                             movzx  eax,WORD PTR [ebx]
004b11eb  dc05505cc500                       fadd   QWORD PTR ds:0xc55c50
004b11f1  8b35a4a7fb00                       mov    esi,DWORD PTR ds:0xfba7a4
004b11f7  50                                 push   eax
004b11f8  8bd6                               mov    edx,esi
004b11fa  d95c2420                           fstp   DWORD PTR [esp+0x20]
004b11fe  e85d400900                         call   0x545260
004b1203  83f8ff                             cmp    eax,0xffffffff
004b1206  7515                               jne    0x4b121d
004b1208  0fb74b02                           movzx  ecx,WORD PTR [ebx+0x2]
004b120c  51                                 push   ecx
004b120d  8bd6                               mov    edx,esi
004b120f  e84c400900                         call   0x545260
004b1214  83f8ff                             cmp    eax,0xffffffff
004b1217  0f84bc060000                       je     0x4b18d9
004b121d  0fbe4305                           movsx  eax,BYTE PTR [ebx+0x5]
004b1221  83e800                             sub    eax,0x0
004b1224  8b74241c                           mov    esi,DWORD PTR [esp+0x1c]
004b1228  8b7c2418                           mov    edi,DWORD PTR [esp+0x18]
004b122c  741e                               je     0x4b124c
004b122e  48                                 dec    eax
004b122f  740c                               je     0x4b123d
004b1231  48                                 dec    eax
004b1232  753a                               jne    0x4b126e
004b1234  83ec0c                             sub    esp,0xc
004b1237  8bc4                               mov    eax,esp
004b1239  6a04                               push   0x4
004b123b  eb16                               jmp    0x4b1253
004b123d  8b4c2414                           mov    ecx,DWORD PTR [esp+0x14]
004b1241  83ec0c                             sub    esp,0xc
004b1244  8bc4                               mov    eax,esp
004b1246  8908                               mov    DWORD PTR [eax],ecx
004b1248  6a03                               push   0x3
004b124a  eb0d                               jmp    0x4b1259
004b124c  83ec0c                             sub    esp,0xc
004b124f  8bc4                               mov    eax,esp
004b1251  6a02                               push   0x2
004b1253  8b542424                           mov    edx,DWORD PTR [esp+0x24]
004b1257  8910                               mov    DWORD PTR [eax],edx
004b1259  897804                             mov    DWORD PTR [eax+0x4],edi
004b125c  897008                             mov    DWORD PTR [eax+0x8],esi
004b125f  e86c9efeff                         call   0x49b0d0
004b1264  8b4b06                             mov    ecx,DWORD PTR [ebx+0x6]
004b1267  8bd0                               mov    edx,eax
004b1269  e862aa2f00                         call   0x7abcd0
004b126e  8b4c2414                           mov    ecx,DWORD PTR [esp+0x14]
004b1272  83ec0c                             sub    esp,0xc
004b1275  8bc4                               mov    eax,esp
004b1277  8908                               mov    DWORD PTR [eax],ecx
004b1279  897804                             mov    DWORD PTR [eax+0x4],edi
004b127c  6a02                               push   0x2
004b127e  897008                             mov    DWORD PTR [eax+0x8],esi
004b1281  e84a9efeff                         call   0x49b0d0
004b1286  8b4b06                             mov    ecx,DWORD PTR [ebx+0x6]
004b1289  8bd0                               mov    edx,eax
004b128b  e840aa2f00                         call   0x7abcd0
004b1290  6a03                               push   0x3
004b1292  e819430d00                         call   0x5855b0
004b1297  8bf0                               mov    esi,eax
004b1299  e892400d00                         call   0x585330
004b129e  8bc8                               mov    ecx,eax
004b12a0  8b4306                             mov    eax,DWORD PTR [ebx+0x6]
004b12a3  8db42430010000                     lea    esi,[esp+0x130]
004b12aa  e84156f5ff                         call   0x4068f0
004b12af  b908000000                         mov    ecx,0x8
004b12b4  898c24b0010000                     mov    DWORD PTR [esp+0x1b0],ecx
004b12bb  394814                             cmp    DWORD PTR [eax+0x14],ecx
004b12be  7202                               jb     0x4b12c2
004b12c0  8b00                               mov    eax,DWORD PTR [eax]
004b12c2  50                                 push   eax
004b12c3  8d8c2418010000                     lea    ecx,[esp+0x118]
004b12ca  e8810ff5ff                         call   0x402250
004b12cf  8d942414010000                     lea    edx,[esp+0x114]
004b12d6  52                                 push   edx
004b12d7  c68424b401000009                   mov    BYTE PTR [esp+0x1b4],0x9
004b12df  e8dce5f5ff                         call   0x40f8c0
004b12e4  8bf8                               mov    edi,eax
004b12e6  e845580200                         call   0x4d6b30
004b12eb  8d8c2414010000                     lea    ecx,[esp+0x114]
004b12f2  e849910400                         call   0x4fa440
004b12f7  8d8c2430010000                     lea    ecx,[esp+0x130]
004b12fe  c78424b0010000ffffffff             mov    DWORD PTR [esp+0x1b0],0xffffffff
004b1309  e832910400                         call   0x4fa440
004b130e  e9c6050000                         jmp    0x4b18d9
004b1313  0fbe4b05                           movsx  ecx,BYTE PTR [ebx+0x5]
004b1317  d9e8                               fld1
004b1319  0fb75704                           movzx  edx,WORD PTR [edi+0x4]
004b131d  83ec08                             sub    esp,0x8
004b1320  894c2478                           mov    DWORD PTR [esp+0x78],ecx
004b1324  8d8c24bc000000                     lea    ecx,[esp+0xbc]
004b132b  d95c2404                           fstp   DWORD PTR [esp+0x4]
004b132f  8974246c                           mov    DWORD PTR [esp+0x6c],esi
004b1333  d9ee                               fldz
004b1335  c74424707c6cc000                   mov    DWORD PTR [esp+0x70],0xc06c7c
004b133d  d91c24                             fstp   DWORD PTR [esp]
004b1340  51                                 push   ecx
004b1341  52                                 push   edx
004b1342  8974247c                           mov    DWORD PTR [esp+0x7c],esi
004b1346  89b42484000000                     mov    DWORD PTR [esp+0x84],esi
004b134d  e8ee9dfeff                         call   0x49b140
004b1352  8d542474                           lea    edx,[esp+0x74]
004b1356  8bc8                               mov    ecx,eax
004b1358  e8c30b0a00                         call   0x551f20
004b135d  d944242c                           fld    DWORD PTR [esp+0x2c]
004b1361  0fb703                             movzx  eax,WORD PTR [ebx]
004b1364  dc05505cc500                       fadd   QWORD PTR ds:0xc55c50
004b136a  8b3da4a7fb00                       mov    edi,DWORD PTR ds:0xfba7a4
004b1370  50                                 push   eax
004b1371  8bd7                               mov    edx,edi
004b1373  d95c2420                           fstp   DWORD PTR [esp+0x20]
004b1377  e8e43e0900                         call   0x545260
004b137c  83f8ff                             cmp    eax,0xffffffff
004b137f  7515                               jne    0x4b1396
004b1381  0fb74b02                           movzx  ecx,WORD PTR [ebx+0x2]
004b1385  51                                 push   ecx
004b1386  8bd7                               mov    edx,edi
004b1388  e8d33e0900                         call   0x545260
004b138d  83f8ff                             cmp    eax,0xffffffff
004b1390  0f8443050000                       je     0x4b18d9
004b1396  0fbe4305                           movsx  eax,BYTE PTR [ebx+0x5]
004b139a  2bc6                               sub    eax,esi
004b139c  0f8468010000                       je     0x4b150a
004b13a2  48                                 dec    eax
004b13a3  0f84b4000000                       je     0x4b145d
004b13a9  48                                 dec    eax
004b13aa  0f8529050000                       jne    0x4b18d9
004b13b0  6a05                               push   0x5
004b13b2  e8f9410d00                         call   0x5855b0
004b13b7  8bf0                               mov    esi,eax
004b13b9  e8723f0d00                         call   0x585330
004b13be  8bc8                               mov    ecx,eax
004b13c0  8b4306                             mov    eax,DWORD PTR [ebx+0x6]
004b13c3  8db42468010000                     lea    esi,[esp+0x168]
004b13ca  e82155f5ff                         call   0x4068f0
004b13cf  c78424b00100000e000000             mov    DWORD PTR [esp+0x1b0],0xe
004b13da  83781408                           cmp    DWORD PTR [eax+0x14],0x8
004b13de  7202                               jb     0x4b13e2
004b13e0  8b00                               mov    eax,DWORD PTR [eax]
004b13e2  50                                 push   eax
004b13e3  8d8c24fc000000                     lea    ecx,[esp+0xfc]
004b13ea  e8610ef5ff                         call   0x402250
004b13ef  8d9424f8000000                     lea    edx,[esp+0xf8]
004b13f6  52                                 push   edx
004b13f7  c68424b40100000f                   mov    BYTE PTR [esp+0x1b4],0xf
004b13ff  e8bce4f5ff                         call   0x40f8c0
004b1404  8bf8                               mov    edi,eax
004b1406  e825570200                         call   0x4d6b30
004b140b  8d8c24f8000000                     lea    ecx,[esp+0xf8]
004b1412  e829900400                         call   0x4fa440
004b1417  8d8c2468010000                     lea    ecx,[esp+0x168]
004b141e  c78424b0010000ffffffff             mov    DWORD PTR [esp+0x1b0],0xffffffff
004b1429  e812900400                         call   0x4fa440
004b142e  8b4c2414                           mov    ecx,DWORD PTR [esp+0x14]
004b1432  8b542418                           mov    edx,DWORD PTR [esp+0x18]
004b1436  83ec0c                             sub    esp,0xc
004b1439  8bc4                               mov    eax,esp
004b143b  8908                               mov    DWORD PTR [eax],ecx
004b143d  8b4c2428                           mov    ecx,DWORD PTR [esp+0x28]
004b1441  895004                             mov    DWORD PTR [eax+0x4],edx
004b1444  6a04                               push   0x4
004b1446  894808                             mov    DWORD PTR [eax+0x8],ecx
004b1449  e8829cfeff                         call   0x49b0d0
004b144e  8b4b06                             mov    ecx,DWORD PTR [ebx+0x6]
004b1451  8bd0                               mov    edx,eax
004b1453  e878a82f00                         call   0x7abcd0
004b1458  e97c040000                         jmp    0x4b18d9
004b145d  6a04                               push   0x4
004b145f  e84c410d00                         call   0x5855b0
004b1464  8bf0                               mov    esi,eax
004b1466  e8c53e0d00                         call   0x585330
004b146b  8bc8                               mov    ecx,eax
004b146d  8b4306                             mov    eax,DWORD PTR [ebx+0x6]
004b1470  8db4244c010000                     lea    esi,[esp+0x14c]
004b1477  e87454f5ff                         call   0x4068f0
004b147c  c78424b00100000c000000             mov    DWORD PTR [esp+0x1b0],0xc
004b1487  83781408                           cmp    DWORD PTR [eax+0x14],0x8
004b148b  7202                               jb     0x4b148f
004b148d  8b00                               mov    eax,DWORD PTR [eax]
004b148f  50                                 push   eax
004b1490  8d8c24e0000000                     lea    ecx,[esp+0xe0]
004b1497  e8b40df5ff                         call   0x402250
004b149c  8d9424dc000000                     lea    edx,[esp+0xdc]
004b14a3  52                                 push   edx
004b14a4  c68424b40100000d                   mov    BYTE PTR [esp+0x1b4],0xd
004b14ac  e80fe4f5ff                         call   0x40f8c0
004b14b1  8bf8                               mov    edi,eax
004b14b3  e878560200                         call   0x4d6b30
004b14b8  8d8c24dc000000                     lea    ecx,[esp+0xdc]
004b14bf  e87c8f0400                         call   0x4fa440
004b14c4  8d8c244c010000                     lea    ecx,[esp+0x14c]
004b14cb  c78424b0010000ffffffff             mov    DWORD PTR [esp+0x1b0],0xffffffff
004b14d6  e8658f0400                         call   0x4fa440
004b14db  8b4c2414                           mov    ecx,DWORD PTR [esp+0x14]
004b14df  8b542418                           mov    edx,DWORD PTR [esp+0x18]
004b14e3  83ec0c                             sub    esp,0xc
004b14e6  8bc4                               mov    eax,esp
004b14e8  8908                               mov    DWORD PTR [eax],ecx
004b14ea  8b4c2428                           mov    ecx,DWORD PTR [esp+0x28]
004b14ee  895004                             mov    DWORD PTR [eax+0x4],edx
004b14f1  6a03                               push   0x3
004b14f3  894808                             mov    DWORD PTR [eax+0x8],ecx
004b14f6  e8d59bfeff                         call   0x49b0d0
004b14fb  8b4b06                             mov    ecx,DWORD PTR [ebx+0x6]
004b14fe  8bd0                               mov    edx,eax
004b1500  e8cba72f00                         call   0x7abcd0
004b1505  e9cf030000                         jmp    0x4b18d9
004b150a  6a03                               push   0x3
004b150c  e89f400d00                         call   0x5855b0
004b1511  8bf0                               mov    esi,eax
004b1513  e8183e0d00                         call   0x585330
004b1518  8bc8                               mov    ecx,eax
004b151a  8b4306                             mov    eax,DWORD PTR [ebx+0x6]
004b151d  8db42484010000                     lea    esi,[esp+0x184]
004b1524  e8c753f5ff                         call   0x4068f0
004b1529  c78424b00100000a000000             mov    DWORD PTR [esp+0x1b0],0xa
004b1534  83781408                           cmp    DWORD PTR [eax+0x14],0x8
004b1538  7202                               jb     0x4b153c
004b153a  8b00                               mov    eax,DWORD PTR [eax]
004b153c  50                                 push   eax
004b153d  8d8c24c4000000                     lea    ecx,[esp+0xc4]
004b1544  e8070df5ff                         call   0x402250
004b1549  8d9424c0000000                     lea    edx,[esp+0xc0]
004b1550  52                                 push   edx
004b1551  c68424b40100000b                   mov    BYTE PTR [esp+0x1b4],0xb
004b1559  e862e3f5ff                         call   0x40f8c0
004b155e  8bf8                               mov    edi,eax
004b1560  e8cb550200                         call   0x4d6b30
004b1565  8d8c24c0000000                     lea    ecx,[esp+0xc0]
004b156c  e8cf8e0400                         call   0x4fa440
004b1571  8d8c2484010000                     lea    ecx,[esp+0x184]
004b1578  c78424b0010000ffffffff             mov    DWORD PTR [esp+0x1b0],0xffffffff
004b1583  e8b88e0400                         call   0x4fa440
004b1588  8b4c2414                           mov    ecx,DWORD PTR [esp+0x14]
004b158c  8b542418                           mov    edx,DWORD PTR [esp+0x18]
004b1590  83ec0c                             sub    esp,0xc
004b1593  8bc4                               mov    eax,esp
004b1595  8908                               mov    DWORD PTR [eax],ecx
004b1597  8b4c2428                           mov    ecx,DWORD PTR [esp+0x28]
004b159b  895004                             mov    DWORD PTR [eax+0x4],edx
004b159e  6a02                               push   0x2
004b15a0  894808                             mov    DWORD PTR [eax+0x8],ecx
004b15a3  e8289bfeff                         call   0x49b0d0
004b15a8  8b4b06                             mov    ecx,DWORD PTR [ebx+0x6]
004b15ab  8bd0                               mov    edx,eax
004b15ad  e81ea72f00                         call   0x7abcd0
004b15b2  e922030000                         jmp    0x4b18d9
004b15b7  0fb75302                           movzx  edx,WORD PTR [ebx+0x2]
004b15bb  d944242c                           fld    DWORD PTR [esp+0x2c]
004b15bf  dc05205dc500                       fadd   QWORD PTR ds:0xc55d20
004b15c5  52                                 push   edx
004b15c6  8b15a4a7fb00                       mov    edx,DWORD PTR ds:0xfba7a4
004b15cc  d95c2420                           fstp   DWORD PTR [esp+0x20]
004b15d0  e88b3c0900                         call   0x545260
004b15d5  83f8ff                             cmp    eax,0xffffffff
004b15d8  7474                               je     0x4b164e
004b15da  0fbe4305                           movsx  eax,BYTE PTR [ebx+0x5]
004b15de  2bc6                               sub    eax,esi
004b15e0  742c                               je     0x4b160e
004b15e2  48                                 dec    eax
004b15e3  740c                               je     0x4b15f1
004b15e5  48                                 dec    eax
004b15e6  754f                               jne    0x4b1637
004b15e8  83ec0c                             sub    esp,0xc
004b15eb  8bc4                               mov    eax,esp
004b15ed  6a04                               push   0x4
004b15ef  eb23                               jmp    0x4b1614
004b15f1  8b542414                           mov    edx,DWORD PTR [esp+0x14]
004b15f5  8b4c2418                           mov    ecx,DWORD PTR [esp+0x18]
004b15f9  83ec0c                             sub    esp,0xc
004b15fc  8bc4                               mov    eax,esp
004b15fe  8910                               mov    DWORD PTR [eax],edx
004b1600  8b542428                           mov    edx,DWORD PTR [esp+0x28]
004b1604  894804                             mov    DWORD PTR [eax+0x4],ecx
004b1607  895008                             mov    DWORD PTR [eax+0x8],edx
004b160a  6a03                               push   0x3
004b160c  eb1a                               jmp    0x4b1628
004b160e  83ec0c                             sub    esp,0xc
004b1611  8bc4                               mov    eax,esp
004b1613  56                                 push   esi
004b1614  8b4c2424                           mov    ecx,DWORD PTR [esp+0x24]
004b1618  8b542428                           mov    edx,DWORD PTR [esp+0x28]
004b161c  8908                               mov    DWORD PTR [eax],ecx
004b161e  8b4c242c                           mov    ecx,DWORD PTR [esp+0x2c]
004b1622  895004                             mov    DWORD PTR [eax+0x4],edx
004b1625  894808                             mov    DWORD PTR [eax+0x8],ecx
004b1628  e8a39afeff                         call   0x49b0d0
004b162d  8b4b06                             mov    ecx,DWORD PTR [ebx+0x6]
004b1630  8bd0                               mov    edx,eax
004b1632  e899a62f00                         call   0x7abcd0
004b1637  8b5306                             mov    edx,DWORD PTR [ebx+0x6]
004b163a  52                                 push   edx
004b163b  68886cc000                         push   0xc06c88
004b1640  e83bb9f5ff                         call   0x40cf80
004b1645  50                                 push   eax
004b1646  e805c2feff                         call   0x49d850
004b164b  83c40c                             add    esp,0xc
004b164e  8b875c010000                       mov    eax,DWORD PTR [edi+0x15c]
004b1654  3bc6                               cmp    eax,esi
004b1656  0f847d020000                       je     0x4b18d9
004b165c  39b770030000                       cmp    DWORD PTR [edi+0x370],esi
004b1662  0f8471020000                       je     0x4b18d9
004b1668  39b0ac000000                       cmp    DWORD PTR [eax+0xac],esi
004b166e  e952020000                         jmp    0x4b18c5
004b1673  0fbe530c                           movsx  edx,BYTE PTR [ebx+0xc]
004b1677  0fb74704                           movzx  eax,WORD PTR [edi+0x4]
004b167b  8b4c2428                           mov    ecx,DWORD PTR [esp+0x28]
004b167f  668b4904                           mov    cx,WORD PTR [ecx+0x4]
004b1683  52                                 push   edx
004b1684  0fbe5305                           movsx  edx,BYTE PTR [ebx+0x5]
004b1688  52                                 push   edx
004b1689  50                                 push   eax
004b168a  33c0                               xor    eax,eax
004b168c  80f901                             cmp    cl,0x1
004b168f  0f94c0                             sete   al
004b1692  8d9424c0000000                     lea    edx,[esp+0xc0]
004b1699  52                                 push   edx
004b169a  50                                 push   eax
004b169b  e8a09afeff                         call   0x49b140
004b16a0  50                                 push   eax
004b16a1  e82a0b0a00                         call   0x5521d0
004b16a6  d944242c                           fld    DWORD PTR [esp+0x2c]
004b16aa  dc05205dc500                       fadd   QWORD PTR ds:0xc55d20
004b16b0  8b35a4a7fb00                       mov    esi,DWORD PTR ds:0xfba7a4
004b16b6  b806000000                         mov    eax,0x6
004b16bb  898714040000                       mov    DWORD PTR [edi+0x414],eax
004b16c1  898710040000                       mov    DWORD PTR [edi+0x410],eax
004b16c7  d95c241c                           fstp   DWORD PTR [esp+0x1c]
004b16cb  c7870c04000000000000               mov    DWORD PTR [edi+0x40c],0x0
004b16d5  0fb70b                             movzx  ecx,WORD PTR [ebx]
004b16d8  51                                 push   ecx
004b16d9  8bd6                               mov    edx,esi
004b16db  e8803b0900                         call   0x545260
004b16e0  83f8ff                             cmp    eax,0xffffffff
004b16e3  7446                               je     0x4b172b
004b16e5  8b542414                           mov    edx,DWORD PTR [esp+0x14]
004b16e9  8b4c2418                           mov    ecx,DWORD PTR [esp+0x18]
004b16ed  83ec0c                             sub    esp,0xc
004b16f0  8bc4                               mov    eax,esp
004b16f2  8910                               mov    DWORD PTR [eax],edx
004b16f4  8b542428                           mov    edx,DWORD PTR [esp+0x28]
004b16f8  894804                             mov    DWORD PTR [eax+0x4],ecx
004b16fb  6a01                               push   0x1
004b16fd  895008                             mov    DWORD PTR [eax+0x8],edx
004b1700  e8cb99feff                         call   0x49b0d0
004b1705  8b4b06                             mov    ecx,DWORD PTR [ebx+0x6]
004b1708  8bd0                               mov    edx,eax
004b170a  e8c1a52f00                         call   0x7abcd0
004b170f  8b4306                             mov    eax,DWORD PTR [ebx+0x6]
004b1712  50                                 push   eax
004b1713  68c06bc000                         push   0xc06bc0
004b1718  e863b8f5ff                         call   0x40cf80
004b171d  50                                 push   eax
004b171e  e82dc1feff                         call   0x49d850
004b1723  83c40c                             add    esp,0xc
004b1726  e9bb000000                         jmp    0x4b17e6
004b172b  0fb74b02                           movzx  ecx,WORD PTR [ebx+0x2]
004b172f  51                                 push   ecx
004b1730  8bd6                               mov    edx,esi
004b1732  e8293b0900                         call   0x545260
004b1737  83f8ff                             cmp    eax,0xffffffff
004b173a  0f84a6000000                       je     0x4b17e6
004b1740  8b542414                           mov    edx,DWORD PTR [esp+0x14]
004b1744  8b4c2418                           mov    ecx,DWORD PTR [esp+0x18]
004b1748  83ec0c                             sub    esp,0xc
004b174b  8bc4                               mov    eax,esp
004b174d  8910                               mov    DWORD PTR [eax],edx
004b174f  8b542428                           mov    edx,DWORD PTR [esp+0x28]
004b1753  894804                             mov    DWORD PTR [eax+0x4],ecx
004b1756  6a00                               push   0x0
004b1758  895008                             mov    DWORD PTR [eax+0x8],edx
004b175b  e87099feff                         call   0x49b0d0
004b1760  8b4b06                             mov    ecx,DWORD PTR [ebx+0x6]
004b1763  8bd0                               mov    edx,eax
004b1765  e866a52f00                         call   0x7abcd0
004b176a  8b4306                             mov    eax,DWORD PTR [ebx+0x6]
004b176d  50                                 push   eax
004b176e  68e06bc000                         push   0xc06be0
004b1773  e808b8f5ff                         call   0x40cf80
004b1778  50                                 push   eax
004b1779  e8d2c0feff                         call   0x49d850
004b177e  83c40c                             add    esp,0xc
004b1781  e85a88fdff                         call   0x489fe0
004b1786  8bf0                               mov    esi,eax
004b1788  e8c3820a00                         call   0x559a50
004b178d  e8ce84fdff                         call   0x489c60
004b1792  33c9                               xor    ecx,ecx
004b1794  8bd0                               mov    edx,eax
004b1796  833a04                             cmp    DWORD PTR [edx],0x4
004b1799  7f4b                               jg     0x4b17e6
004b179b  41                                 inc    ecx
004b179c  83c214                             add    edx,0x14
004b179f  83f920                             cmp    ecx,0x20
004b17a2  7cf2                               jl     0x4b1796
004b17a4  33f6                               xor    esi,esi
004b17a6  33c9                               xor    ecx,ecx
004b17a8  8bd0                               mov    edx,eax
004b17aa  8d9b00000000                       lea    ebx,[ebx+0x0]
004b17b0  3932                               cmp    DWORD PTR [edx],esi
004b17b2  740b                               je     0x4b17bf
004b17b4  41                                 inc    ecx
004b17b5  83c214                             add    edx,0x14
004b17b8  83f920                             cmp    ecx,0x20
004b17bb  7cf3                               jl     0x4b17b0
004b17bd  eb27                               jmp    0x4b17e6
004b17bf  0f57c0                             xorps  xmm0,xmm0
004b17c2  8d0c89                             lea    ecx,[ecx+ecx*4]
004b17c5  8d0488                             lea    eax,[eax+ecx*4]
004b17c8  f30f114004                         movss  DWORD PTR [eax+0x4],xmm0
004b17cd  f30f10050858c500                   movss  xmm0,DWORD PTR ds:0xc55808
004b17d5  c70004000000                       mov    DWORD PTR [eax],0x4
004b17db  f30f114008                         movss  DWORD PTR [eax+0x8],xmm0
004b17e0  89700c                             mov    DWORD PTR [eax+0xc],esi
004b17e3  897010                             mov    DWORD PTR [eax+0x10],esi
004b17e6  f30f1005f8c7c000                   movss  xmm0,DWORD PTR ds:0xc0c7f8
004b17ee  d9056c59c500                       fld    DWORD PTR ds:0xc5596c
004b17f4  668b4f04                           mov    cx,WORD PTR [edi+0x4]
004b17f8  d95c243c                           fstp   DWORD PTR [esp+0x3c]
004b17fc  8b5c2428                           mov    ebx,DWORD PTR [esp+0x28]
004b1800  f30f11442448                       movss  DWORD PTR [esp+0x48],xmm0
004b1806  f30f1005245ac500                   movss  xmm0,DWORD PTR ds:0xc55a24
004b180e  8b542448                           mov    edx,DWORD PTR [esp+0x48]
004b1812  83ec10                             sub    esp,0x10
004b1815  8bc4                               mov    eax,esp
004b1817  8910                               mov    DWORD PTR [eax],edx
004b1819  f30f1144245c                       movss  DWORD PTR [esp+0x5c],xmm0
004b181f  8b54245c                           mov    edx,DWORD PTR [esp+0x5c]
004b1823  895004                             mov    DWORD PTR [eax+0x4],edx
004b1826  f30f11442460                       movss  DWORD PTR [esp+0x60],xmm0
004b182c  8b542460                           mov    edx,DWORD PTR [esp+0x60]
004b1830  f30f1005f05cc500                   movss  xmm0,DWORD PTR ds:0xc55cf0
004b1838  895008                             mov    DWORD PTR [eax+0x8],edx
004b183b  51                                 push   ecx
004b183c  f30f11442468                       movss  DWORD PTR [esp+0x68],xmm0
004b1842  8b542468                           mov    edx,DWORD PTR [esp+0x68]
004b1846  89500c                             mov    DWORD PTR [eax+0xc],edx
004b1849  8bc4                               mov    eax,esp
004b184b  89642434                           mov    DWORD PTR [esp+0x34],esp
004b184f  668908                             mov    WORD PTR [eax],cx
004b1852  668b4304                           mov    ax,WORD PTR [ebx+0x4]
004b1856  51                                 push   ecx
004b1857  8bcc                               mov    ecx,esp
004b1859  89642438                           mov    DWORD PTR [esp+0x38],esp
004b185d  668901                             mov    WORD PTR [ecx],ax
004b1860  e89b8bfdff                         call   0x48a400
004b1865  f30f10442454                       movss  xmm0,DWORD PTR [esp+0x54]
004b186b  50                                 push   eax
004b186c  e84f712200                         call   0x6d89c0
004b1871  8bb35c010000                       mov    esi,DWORD PTR [ebx+0x15c]
004b1877  85f6                               test   esi,esi
004b1879  7430                               je     0x4b18ab
004b187b  83bb7003000000                     cmp    DWORD PTR [ebx+0x370],0x0
004b1882  7427                               je     0x4b18ab
004b1884  83beac00000000                     cmp    DWORD PTR [esi+0xac],0x0
004b188b  741e                               je     0x4b18ab
004b188d  8b8eac000000                       mov    ecx,DWORD PTR [esi+0xac]
004b1893  8b01                               mov    eax,DWORD PTR [ecx]
004b1895  8b5030                             mov    edx,DWORD PTR [eax+0x30]
004b1898  ffd2                               call   edx
004b189a  81c6b4000000                       add    esi,0xb4
004b18a0  0fb6c8                             movzx  ecx,al
004b18a3  56                                 push   esi
004b18a4  33d2                               xor    edx,edx
004b18a6  e835103200                         call   0x7d28e0
004b18ab  8b875c010000                       mov    eax,DWORD PTR [edi+0x15c]
004b18b1  85c0                               test   eax,eax
004b18b3  7424                               je     0x4b18d9
004b18b5  83bf7003000000                     cmp    DWORD PTR [edi+0x370],0x0
004b18bc  741b                               je     0x4b18d9
004b18be  83b8ac00000000                     cmp    DWORD PTR [eax+0xac],0x0
004b18c5  7412                               je     0x4b18d9
004b18c7  33d2                               xor    edx,edx
004b18c9  05b4000000                         add    eax,0xb4
004b18ce  50                                 push   eax
004b18cf  b904000000                         mov    ecx,0x4
004b18d4  e807103200                         call   0x7d28e0
004b18d9  8b442438                           mov    eax,DWORD PTR [esp+0x38]
004b18dd  40                                 inc    eax
004b18de  89442438                           mov    DWORD PTR [esp+0x38],eax
004b18e2  3b442434                           cmp    eax,DWORD PTR [esp+0x34]
004b18e6  0f8279eeffff                       jb     0x4b0765
004b18ec  33c0                               xor    eax,eax
004b18ee  8b8c24a8010000                     mov    ecx,DWORD PTR [esp+0x1a8]
004b18f5  64890d00000000                     mov    DWORD PTR fs:0x0,ecx
004b18fc  59                                 pop    ecx
004b18fd  5f                                 pop    edi
004b18fe  5e                                 pop    esi
004b18ff  5b                                 pop    ebx
004b1900  8b8c2490010000                     mov    ecx,DWORD PTR [esp+0x190]
004b1907  33cc                               xor    ecx,esp
004b1909  e8f3f63d00                         call   0x891001
004b190e  8be5                               mov    esp,ebp
004b1910  5d                                 pop    ebp
004b1911  c20c00                             ret    0xc
; parameter_0000 [0x4afaf0,0x4afb7a) 完整；6-byte row、world lookup、v+2C
004afaf0  55                                 push   ebp
004afaf1  8bec                               mov    ebp,esp
004afaf3  8b450c                             mov    eax,DWORD PTR [ebp+0xc]
004afaf6  83f802                             cmp    eax,0x2
004afaf9  7304                               jae    0x4afaff
004afafb  33d2                               xor    edx,edx
004afafd  eb0d                               jmp    0x4afb0c
004afaff  8d48fe                             lea    ecx,[eax-0x2]
004afb02  b8abaaaaaa                         mov    eax,0xaaaaaaab
004afb07  f7e1                               mul    ecx
004afb09  c1ea02                             shr    edx,0x2
004afb0c  85d2                               test   edx,edx
004afb0e  7464                               je     0x4afb74
004afb10  53                                 push   ebx
004afb11  56                                 push   esi
004afb12  8b7508                             mov    esi,DWORD PTR [ebp+0x8]
004afb15  57                                 push   edi
004afb16  83c604                             add    esi,0x4
004afb19  8bda                               mov    ebx,edx
004afb1b  eb03                               jmp    0x4afb20
004afb1d  8d4900                             lea    ecx,[ecx+0x0]
004afb20  0fb756fe                           movzx  edx,WORD PTR [esi-0x2]
004afb24  89550c                             mov    DWORD PTR [ebp+0xc],edx
004afb27  e834f5f5ff                         call   0x40f060
004afb2c  8bf8                               mov    edi,eax
004afb2e  8d450c                             lea    eax,[ebp+0xc]
004afb31  50                                 push   eax
004afb32  8d4f08                             lea    ecx,[edi+0x8]
004afb35  8d4508                             lea    eax,[ebp+0x8]
004afb38  e8c3f33700                         call   0x82ef00
004afb3d  8b4508                             mov    eax,DWORD PTR [ebp+0x8]
004afb40  3b470c                             cmp    eax,DWORD PTR [edi+0xc]
004afb43  7407                               je     0x4afb4c
004afb45  8b4810                             mov    ecx,DWORD PTR [eax+0x10]
004afb48  85c9                               test   ecx,ecx
004afb4a  750f                               jne    0x4afb5b
004afb4c  68886ac000                         push   0xc06a88
004afb51  e80ae02300                         call   0x6edb60
004afb56  83c404                             add    esp,0x4
004afb59  eb10                               jmp    0x4afb6b
004afb5b  0fb74602                           movzx  eax,WORD PTR [esi+0x2]
004afb5f  8b11                               mov    edx,DWORD PTR [ecx]
004afb61  8b522c                             mov    edx,DWORD PTR [edx+0x2c]
004afb64  50                                 push   eax
004afb65  0fb706                             movzx  eax,WORD PTR [esi]
004afb68  50                                 push   eax
004afb69  ffd2                               call   edx
004afb6b  83c606                             add    esi,0x6
004afb6e  4b                                 dec    ebx
004afb6f  75af                               jne    0x4afb20
004afb71  5f                                 pop    edi
004afb72  5e                                 pop    esi
004afb73  5b                                 pop    ebx
004afb74  33c0                               xor    eax,eax
004afb76  5d                                 pop    ebp
004afb77  c20c00                             ret    0xc
; monster_parameter [0x4d1e10,0x4d1f32) 完整程式，不含後方資料表；case1 比例、其餘 case 排除為生命期事件
004d1e10  55                                 push   ebp
004d1e11  8bec                               mov    ebp,esp
004d1e13  56                                 push   esi
004d1e14  8bf1                               mov    esi,ecx
004d1e16  0fbf4d08                           movsx  ecx,WORD PTR [ebp+0x8]
004d1e1a  8d41ff                             lea    eax,[ecx-0x1]
004d1e1d  83f81c                             cmp    eax,0x1c
004d1e20  0f87f4000000                       ja     0x4d1f1a
004d1e26  0fb6804c1f4d00                     movzx  eax,BYTE PTR [eax+0x4d1f4c]
004d1e2d  ff2485341f4d00                     jmp    DWORD PTR [eax*4+0x4d1f34]
004d1e34  0fbf450c                           movsx  eax,WORD PTR [ebp+0xc]
004d1e38  89450c                             mov    DWORD PTR [ebp+0xc],eax
004d1e3b  8986b0030000                       mov    DWORD PTR [esi+0x3b0],eax
004d1e41  db450c                             fild   DWORD PTR [ebp+0xc]
004d1e44  8bb668030000                       mov    esi,DWORD PTR [esi+0x368]
004d1e4a  56                                 push   esi
004d1e4b  8d450c                             lea    eax,[ebp+0xc]
004d1e4e  dc0dd856c500                       fmul   QWORD PTR ds:0xc556d8
004d1e54  c6450c00                           mov    BYTE PTR [ebp+0xc],0x0
004d1e58  d95d08                             fstp   DWORD PTR [ebp+0x8]
004d1e5b  e870302e00                         call   0x7b4ed0
004d1e60  d94508                             fld    DWORD PTR [ebp+0x8]
004d1e63  5e                                 pop    esi
004d1e64  d9580c                             fstp   DWORD PTR [eax+0xc]
004d1e67  5d                                 pop    ebp
004d1e68  c20800                             ret    0x8
004d1e6b  0fbf4d0c                           movsx  ecx,WORD PTR [ebp+0xc]
004d1e6f  8b9688000000                       mov    edx,DWORD PTR [esi+0x88]
004d1e75  898ed4030000                       mov    DWORD PTR [esi+0x3d4],ecx
004d1e7b  89550c                             mov    DWORD PTR [ebp+0xc],edx
004d1e7e  e8ad34f5ff                         call   0x425330
004d1e83  8d550c                             lea    edx,[ebp+0xc]
004d1e86  8bc8                               mov    ecx,eax
004d1e88  e8e35b0200                         call   0x4f7a70
004d1e8d  83c01c                             add    eax,0x1c
004d1e90  83781408                           cmp    DWORD PTR [eax+0x14],0x8
004d1e94  7202                               jb     0x4d1e98
004d1e96  8b00                               mov    eax,DWORD PTR [eax]
004d1e98  50                                 push   eax
004d1e99  8b86d4030000                       mov    eax,DWORD PTR [esi+0x3d4]
004d1e9f  50                                 push   eax
004d1ea0  6884c9c000                         push   0xc0c984
004d1ea5  8d5606                             lea    edx,[esi+0x6]
004d1ea8  e833f8ffff                         call   0x4d16e0
004d1ead  83c40c                             add    esp,0xc
004d1eb0  5e                                 pop    esi
004d1eb1  5d                                 pop    ebp
004d1eb2  c20800                             ret    0x8
004d1eb5  83be2004000000                     cmp    DWORD PTR [esi+0x420],0x0
004d1ebc  0fbf4d0c                           movsx  ecx,WORD PTR [ebp+0xc]
004d1ec0  0f57c0                             xorps  xmm0,xmm0
004d1ec3  f30f2ac1                           cvtsi2ss xmm0,ecx
004d1ec7  f30f11450c                         movss  DWORD PTR [ebp+0xc],xmm0
004d1ecc  f30f1186cc000000                   movss  DWORD PTR [esi+0xcc],xmm0
004d1ed4  7512                               jne    0x4d1ee8
004d1ed6  f30f118694030000                   movss  DWORD PTR [esi+0x394],xmm0
004d1ede  c7862004000001000000               mov    DWORD PTR [esi+0x420],0x1
004d1ee8  d9450c                             fld    DWORD PTR [ebp+0xc]
004d1eeb  d8b694030000                       fdiv   DWORD PTR [esi+0x394]
004d1ef1  d99e98030000                       fstp   DWORD PTR [esi+0x398]
004d1ef7  5e                                 pop    esi
004d1ef8  5d                                 pop    ebp
004d1ef9  c20800                             ret    0x8
004d1efc  0fbf550c                           movsx  edx,WORD PTR [ebp+0xc]
004d1f00  8996d0000000                       mov    DWORD PTR [esi+0xd0],edx
004d1f06  5e                                 pop    esi
004d1f07  5d                                 pop    ebp
004d1f08  c20800                             ret    0x8
004d1f0b  0fbf450c                           movsx  eax,WORD PTR [ebp+0xc]
004d1f0f  898690000000                       mov    DWORD PTR [esi+0x90],eax
004d1f15  5e                                 pop    esi
004d1f16  5d                                 pop    ebp
004d1f17  c20800                             ret    0x8
004d1f1a  0fbf550c                           movsx  edx,WORD PTR [ebp+0xc]
004d1f1e  52                                 push   edx
004d1f1f  51                                 push   ecx
004d1f20  6898c9c000                         push   0xc0c998
004d1f25  e836bc2100                         call   0x6edb60
004d1f2a  83c40c                             add    esp,0xc
004d1f2d  5e                                 pop    esi
004d1f2e  5d                                 pop    ebp
004d1f2f  c20800                             ret    0x8
; character_parameter [0x4ce7f0,0x4ceb5c) 完整程式，不含後方資料表；case1/2/3 對應比例通道
004ce7f0  55                                 push   ebp
004ce7f1  8bec                               mov    ebp,esp
004ce7f3  6aff                               push   0xffffffff
004ce7f5  68e8059400                         push   0x9405e8
004ce7fa  64a100000000                       mov    eax,fs:0x0
004ce800  50                                 push   eax
004ce801  83ec3c                             sub    esp,0x3c
004ce804  a1201fd600                         mov    eax,ds:0xd61f20
004ce809  33c5                               xor    eax,ebp
004ce80b  8945f0                             mov    DWORD PTR [ebp-0x10],eax
004ce80e  53                                 push   ebx
004ce80f  56                                 push   esi
004ce810  57                                 push   edi
004ce811  50                                 push   eax
004ce812  8d45f4                             lea    eax,[ebp-0xc]
004ce815  64a300000000                       mov    fs:0x0,eax
004ce81b  8bd9                               mov    ebx,ecx
004ce81d  0fbf4d08                           movsx  ecx,WORD PTR [ebp+0x8]
004ce821  8d41ff                             lea    eax,[ecx-0x1]
004ce824  83f81d                             cmp    eax,0x1d
004ce827  0f87fe020000                       ja     0x4ceb2b
004ce82d  0fb68088eb4c00                     movzx  eax,BYTE PTR [eax+0x4ceb88]
004ce834  ff24855ceb4c00                     jmp    DWORD PTR [eax*4+0x4ceb5c]
004ce83b  0fbf450c                           movsx  eax,WORD PTR [ebp+0xc]
004ce83f  8983b0030000                       mov    DWORD PTR [ebx+0x3b0],eax
004ce845  8b9b68030000                       mov    ebx,DWORD PTR [ebx+0x368]
004ce84b  8945cc                             mov    DWORD PTR [ebp-0x34],eax
004ce84e  85db                               test   ebx,ebx
004ce850  0f84e8020000                       je     0x4ceb3e
004ce856  db45cc                             fild   DWORD PTR [ebp-0x34]
004ce859  53                                 push   ebx
004ce85a  8d45d0                             lea    eax,[ebp-0x30]
004ce85d  c645d000                           mov    BYTE PTR [ebp-0x30],0x0
004ce861  dc0dd856c500                       fmul   QWORD PTR ds:0xc556d8
004ce867  d95dcc                             fstp   DWORD PTR [ebp-0x34]
004ce86a  d945cc                             fld    DWORD PTR [ebp-0x34]
004ce86d  d95dcc                             fstp   DWORD PTR [ebp-0x34]
004ce870  e85b662e00                         call   0x7b4ed0
004ce875  d945cc                             fld    DWORD PTR [ebp-0x34]
004ce878  d9580c                             fstp   DWORD PTR [eax+0xc]
004ce87b  e9be020000                         jmp    0x4ceb3e
004ce880  0fbf450c                           movsx  eax,WORD PTR [ebp+0xc]
004ce884  8983b4030000                       mov    DWORD PTR [ebx+0x3b4],eax
004ce88a  8b9b68030000                       mov    ebx,DWORD PTR [ebx+0x368]
004ce890  8945cc                             mov    DWORD PTR [ebp-0x34],eax
004ce893  85db                               test   ebx,ebx
004ce895  0f84a3020000                       je     0x4ceb3e
004ce89b  db45cc                             fild   DWORD PTR [ebp-0x34]
004ce89e  53                                 push   ebx
004ce89f  8d45d0                             lea    eax,[ebp-0x30]
004ce8a2  c645d001                           mov    BYTE PTR [ebp-0x30],0x1
004ce8a6  dc35e857c500                       fdiv   QWORD PTR ds:0xc557e8
004ce8ac  d95dcc                             fstp   DWORD PTR [ebp-0x34]
004ce8af  d945cc                             fld    DWORD PTR [ebp-0x34]
004ce8b2  d95dcc                             fstp   DWORD PTR [ebp-0x34]
004ce8b5  e816662e00                         call   0x7b4ed0
004ce8ba  d945cc                             fld    DWORD PTR [ebp-0x34]
004ce8bd  d9580c                             fstp   DWORD PTR [eax+0xc]
004ce8c0  e979020000                         jmp    0x4ceb3e
004ce8c5  0fbf450c                           movsx  eax,WORD PTR [ebp+0xc]
004ce8c9  8983b8030000                       mov    DWORD PTR [ebx+0x3b8],eax
004ce8cf  8b9b68030000                       mov    ebx,DWORD PTR [ebx+0x368]
004ce8d5  8945cc                             mov    DWORD PTR [ebp-0x34],eax
004ce8d8  85db                               test   ebx,ebx
004ce8da  0f845e020000                       je     0x4ceb3e
004ce8e0  db45cc                             fild   DWORD PTR [ebp-0x34]
004ce8e3  53                                 push   ebx
004ce8e4  8d45d0                             lea    eax,[ebp-0x30]
004ce8e7  c645d002                           mov    BYTE PTR [ebp-0x30],0x2
004ce8eb  dc35e857c500                       fdiv   QWORD PTR ds:0xc557e8
004ce8f1  d95dcc                             fstp   DWORD PTR [ebp-0x34]
004ce8f4  d945cc                             fld    DWORD PTR [ebp-0x34]
004ce8f7  d95dcc                             fstp   DWORD PTR [ebp-0x34]
004ce8fa  e8d1652e00                         call   0x7b4ed0
004ce8ff  d945cc                             fld    DWORD PTR [ebp-0x34]
004ce902  d9580c                             fstp   DWORD PTR [eax+0xc]
004ce905  e934020000                         jmp    0x4ceb3e
004ce90a  0fbf4d0c                           movsx  ecx,WORD PTR [ebp+0xc]
004ce90e  8b8364030000                       mov    eax,DWORD PTR [ebx+0x364]
004ce914  898be8030000                       mov    DWORD PTR [ebx+0x3e8],ecx
004ce91a  85c0                               test   eax,eax
004ce91c  7427                               je     0x4ce945
004ce91e  83782400                           cmp    DWORD PTR [eax+0x24],0x0
004ce922  8d7024                             lea    esi,[eax+0x24]
004ce925  7405                               je     0x4ce92c
004ce927  e8c4fc2e00                         call   0x7be5f0
004ce92c  8bbb64030000                       mov    edi,DWORD PTR [ebx+0x364]
004ce932  85ff                               test   edi,edi
004ce934  740f                               je     0x4ce945
004ce936  e87594ffff                         call   0x4c7db0
004ce93b  c7836403000000000000               mov    DWORD PTR [ebx+0x364],0x0
004ce945  83bbe803000001                     cmp    DWORD PTR [ebx+0x3e8],0x1
004ce94c  0f85ec010000                       jne    0x4ceb3e
004ce952  d9e8                               fld1
004ce954  8b13                               mov    edx,DWORD PTR [ebx]
004ce956  8b424c                             mov    eax,DWORD PTR [edx+0x4c]
004ce959  83ec08                             sub    esp,0x8
004ce95c  d95c2404                           fstp   DWORD PTR [esp+0x4]
004ce960  83cfff                             or     edi,0xffffffff
004ce963  d9ee                               fldz
004ce965  8bcb                               mov    ecx,ebx
004ce967  d91c24                             fstp   DWORD PTR [esp]
004ce96a  c745b802000000                     mov    DWORD PTR [ebp-0x48],0x2
004ce971  c745bcec7ac000                     mov    DWORD PTR [ebp-0x44],0xc07aec
004ce978  897dc0                             mov    DWORD PTR [ebp-0x40],edi
004ce97b  897dc4                             mov    DWORD PTR [ebp-0x3c],edi
004ce97e  c745c800000000                     mov    DWORD PTR [ebp-0x38],0x0
004ce985  ffd0                               call   eax
004ce987  0fb74b04                           movzx  ecx,WORD PTR [ebx+0x4]
004ce98b  51                                 push   ecx
004ce98c  8bf0                               mov    esi,eax
004ce98e  e8adc7fcff                         call   0x49b140
004ce993  8d55b8                             lea    edx,[ebp-0x48]
004ce996  8bc8                               mov    ecx,eax
004ce998  e8f3350800                         call   0x551f90
004ce99d  898364030000                       mov    DWORD PTR [ebx+0x364],eax
004ce9a3  e996010000                         jmp    0x4ceb3e
004ce9a8  0fbf550c                           movsx  edx,WORD PTR [ebp+0xc]
004ce9ac  0f57c0                             xorps  xmm0,xmm0
004ce9af  f30f2ac2                           cvtsi2ss xmm0,edx
004ce9b3  f30f1183cc000000                   movss  DWORD PTR [ebx+0xcc],xmm0
004ce9bb  e97e010000                         jmp    0x4ceb3e
004ce9c0  0fbf450c                           movsx  eax,WORD PTR [ebp+0xc]
004ce9c4  8983d0000000                       mov    DWORD PTR [ebx+0xd0],eax
004ce9ca  e96f010000                         jmp    0x4ceb3e
004ce9cf  0fbf4d0c                           movsx  ecx,WORD PTR [ebp+0xc]
004ce9d3  898b90000000                       mov    DWORD PTR [ebx+0x90],ecx
004ce9d9  e960010000                         jmp    0x4ceb3e
004ce9de  0fbf450c                           movsx  eax,WORD PTR [ebp+0xc]
004ce9e2  3b83d4030000                       cmp    eax,DWORD PTR [ebx+0x3d4]
004ce9e8  0f84aa000000                       je     0x4cea98
004ce9ee  8b0da4a7fb00                       mov    ecx,DWORD PTR ds:0xfba7a4
004ce9f4  8b11                               mov    edx,DWORD PTR [ecx]
004ce9f6  8b4220                             mov    eax,DWORD PTR [edx+0x20]
004ce9f9  ffd0                               call   eax
004ce9fb  83cfff                             or     edi,0xffffffff
004ce9fe  3bd8                               cmp    ebx,eax
004cea00  7546                               jne    0x4cea48
004cea02  83bbd403000000                     cmp    DWORD PTR [ebx+0x3d4],0x0
004cea09  0f8489000000                       je     0x4cea98
004cea0f  baf47ac000                         mov    edx,0xc07af4
004cea14  8d75d4                             lea    esi,[ebp-0x2c]
004cea17  e8a4c9f3ff                         call   0x40b3c0
004cea1c  c745fc00000000                     mov    DWORD PTR [ebp-0x4],0x0
004cea23  e8c8c9f3ff                         call   0x40b3f0
004cea28  50                                 push   eax
004cea29  8bce                               mov    ecx,esi
004cea2b  e8d0c03300                         call   0x80ab00
004cea30  85c0                               test   eax,eax
004cea32  7409                               je     0x4cea3d
004cea34  8b10                               mov    edx,DWORD PTR [eax]
004cea36  8bc8                               mov    ecx,eax
004cea38  8b4214                             mov    eax,DWORD PTR [edx+0x14]
004cea3b  ffd0                               call   eax
004cea3d  8d75d4                             lea    esi,[ebp-0x2c]
004cea40  897dfc                             mov    DWORD PTR [ebp-0x4],edi
004cea43  e8080a3000                         call   0x7cf450
004cea48  83bbd403000000                     cmp    DWORD PTR [ebx+0x3d4],0x0
004cea4f  7447                               je     0x4cea98
004cea51  d9e8                               fld1
004cea53  8b13                               mov    edx,DWORD PTR [ebx]
004cea55  8b424c                             mov    eax,DWORD PTR [edx+0x4c]
004cea58  83ec08                             sub    esp,0x8
004cea5b  d95c2404                           fstp   DWORD PTR [esp+0x4]
004cea5f  8bcb                               mov    ecx,ebx
004cea61  d9ee                               fldz
004cea63  c745b802000000                     mov    DWORD PTR [ebp-0x48],0x2
004cea6a  d91c24                             fstp   DWORD PTR [esp]
004cea6d  c745bcf47ac000                     mov    DWORD PTR [ebp-0x44],0xc07af4
004cea74  897dc0                             mov    DWORD PTR [ebp-0x40],edi
004cea77  897dc4                             mov    DWORD PTR [ebp-0x3c],edi
004cea7a  c745c800000000                     mov    DWORD PTR [ebp-0x38],0x0
004cea81  ffd0                               call   eax
004cea83  0fb74b04                           movzx  ecx,WORD PTR [ebx+0x4]
004cea87  50                                 push   eax
004cea88  51                                 push   ecx
004cea89  e8b2c6fcff                         call   0x49b140
004cea8e  8d55b8                             lea    edx,[ebp-0x48]
004cea91  8bc8                               mov    ecx,eax
004cea93  e888340800                         call   0x551f20
004cea98  0fbf450c                           movsx  eax,WORD PTR [ebp+0xc]
004cea9c  8983d4030000                       mov    DWORD PTR [ebx+0x3d4],eax
004ceaa2  e997000000                         jmp    0x4ceb3e
004ceaa7  e834b5fbff                         call   0x489fe0
004ceaac  f30f1005c056c400                   movss  xmm0,DWORD PTR ds:0xc456c0
004ceab4  0fbf550c                           movsx  edx,WORD PTR [ebp+0xc]
004ceab8  f30f114024                         movss  DWORD PTR [eax+0x24],xmm0
004ceabd  f30f1005d057c500                   movss  xmm0,DWORD PTR ds:0xc557d0
004ceac5  c7402c3c000000                     mov    DWORD PTR [eax+0x2c],0x3c
004ceacc  f30f114028                         movss  DWORD PTR [eax+0x28],xmm0
004cead1  895034                             mov    DWORD PTR [eax+0x34],edx
004cead4  eb68                               jmp    0x4ceb3e
004cead6  8b0da4a7fb00                       mov    ecx,DWORD PTR ds:0xfba7a4
004ceadc  8b01                               mov    eax,DWORD PTR [ecx]
004ceade  8b5020                             mov    edx,DWORD PTR [eax+0x20]
004ceae1  ffd2                               call   edx
004ceae3  3bd8                               cmp    ebx,eax
004ceae5  7557                               jne    0x4ceb3e
004ceae7  0fb7b388000000                     movzx  esi,WORD PTR [ebx+0x88]
004ceaee  e8ad60f3ff                         call   0x404ba0
004ceaf3  8b8824690000                       mov    ecx,DWORD PTR [eax+0x6924]
004ceaf9  8bc6                               mov    eax,esi
004ceafb  83f809                             cmp    eax,0x9
004ceafe  771d                               ja     0x4ceb1d
004ceb00  69c010020000                       imul   eax,eax,0x210
004ceb06  03c8                               add    ecx,eax
004ceb08  8b415c                             mov    eax,DWORD PTR [ecx+0x5c]
004ceb0b  f7d8                               neg    eax
004ceb0d  1bc0                               sbb    eax,eax
004ceb0f  23c1                               and    eax,ecx
004ceb11  0fbf4d0c                           movsx  ecx,WORD PTR [ebp+0xc]
004ceb15  8988dc000000                       mov    DWORD PTR [eax+0xdc],ecx
004ceb1b  eb21                               jmp    0x4ceb3e
004ceb1d  0fbf4d0c                           movsx  ecx,WORD PTR [ebp+0xc]
004ceb21  33c0                               xor    eax,eax
004ceb23  8988dc000000                       mov    DWORD PTR [eax+0xdc],ecx
004ceb29  eb13                               jmp    0x4ceb3e
004ceb2b  0fbf550c                           movsx  edx,WORD PTR [ebp+0xc]
004ceb2f  52                                 push   edx
004ceb30  51                                 push   ecx
004ceb31  68fc7ac000                         push   0xc07afc
004ceb36  e825f02100                         call   0x6edb60
004ceb3b  83c40c                             add    esp,0xc
004ceb3e  8b4df4                             mov    ecx,DWORD PTR [ebp-0xc]
004ceb41  64890d00000000                     mov    DWORD PTR fs:0x0,ecx
004ceb48  59                                 pop    ecx
004ceb49  5f                                 pop    edi
004ceb4a  5e                                 pop    esi
004ceb4b  5b                                 pop    ebx
004ceb4c  8b4df0                             mov    ecx,DWORD PTR [ebp-0x10]
004ceb4f  33cd                               xor    ecx,ebp
004ceb51  e8ab243c00                         call   0x891001
004ceb56  8be5                               mov    esp,ebp
004ceb58  5d                                 pop    ebp
004ceb59  c20800                             ret    0x8
; resource_0034 [0x4b3090,0x4b32d1) 完整；typed actor/roster guards、三組 max/current writer、mode1另域
004b3090  55                                 push   ebp
004b3091  8bec                               mov    ebp,esp
004b3093  51                                 push   ecx
004b3094  8b450c                             mov    eax,DWORD PTR [ebp+0xc]
004b3097  83f802                             cmp    eax,0x2
004b309a  7304                               jae    0x4b30a0
004b309c  33d2                               xor    edx,edx
004b309e  eb0d                               jmp    0x4b30ad
004b30a0  8d48fe                             lea    ecx,[eax-0x2]
004b30a3  b8398ee338                         mov    eax,0x38e38e39
004b30a8  f7e1                               mul    ecx
004b30aa  c1ea02                             shr    edx,0x2
004b30ad  85d2                               test   edx,edx
004b30af  0f8414020000                       je     0x4b32c9
004b30b5  53                                 push   ebx
004b30b6  56                                 push   esi
004b30b7  8b7508                             mov    esi,DWORD PTR [ebp+0x8]
004b30ba  57                                 push   edi
004b30bb  83c608                             add    esi,0x8
004b30be  895508                             mov    DWORD PTR [ebp+0x8],edx
004b30c1  0fb756fe                           movzx  edx,WORD PTR [esi-0x2]
004b30c5  89550c                             mov    DWORD PTR [ebp+0xc],edx
004b30c8  e893bff5ff                         call   0x40f060
004b30cd  8bf8                               mov    edi,eax
004b30cf  8d450c                             lea    eax,[ebp+0xc]
004b30d2  50                                 push   eax
004b30d3  8d4f08                             lea    ecx,[edi+0x8]
004b30d6  8d45fc                             lea    eax,[ebp-0x4]
004b30d9  e822be3700                         call   0x82ef00
004b30de  8b45fc                             mov    eax,DWORD PTR [ebp-0x4]
004b30e1  3b470c                             cmp    eax,DWORD PTR [edi+0xc]
004b30e4  0f84d0010000                       je     0x4b32ba
004b30ea  8b7810                             mov    edi,DWORD PTR [eax+0x10]
004b30ed  85ff                               test   edi,edi
004b30ef  0f84c5010000                       je     0x4b32ba
004b30f5  bb01000000                         mov    ebx,0x1
004b30fa  399f9c030000                       cmp    DWORD PTR [edi+0x39c],ebx
004b3100  7551                               jne    0x4b3153
004b3102  8b46fa                             mov    eax,DWORD PTR [esi-0x6]
004b3105  83e802                             sub    eax,0x2
004b3108  0f85ac010000                       jne    0x4b32ba
004b310e  50                                 push   eax
004b310f  68acdff700                         push   0xf7dfac
004b3114  6894dff700                         push   0xf7df94
004b3119  50                                 push   eax
004b311a  57                                 push   edi
004b311b  e855cf4400                         call   0x900075
004b3120  83c414                             add    esp,0x14
004b3123  85c0                               test   eax,eax
004b3125  0f848f010000                       je     0x4b32ba
004b312b  8b4efa                             mov    ecx,DWORD PTR [esi-0x6]
004b312e  83e902                             sub    ecx,0x2
004b3131  0f8583010000                       jne    0x4b32ba
004b3137  8b4e08                             mov    ecx,DWORD PTR [esi+0x8]
004b313a  8b16                               mov    edx,DWORD PTR [esi]
004b313c  8990bc030000                       mov    DWORD PTR [eax+0x3bc],edx
004b3142  8988c8030000                       mov    DWORD PTR [eax+0x3c8],ecx
004b3148  899830040000                       mov    DWORD PTR [eax+0x430],ebx
004b314e  e967010000                         jmp    0x4b32ba
004b3153  8b9f9c000000                       mov    ebx,DWORD PTR [edi+0x9c]
004b3159  e8421af5ff                         call   0x404ba0
004b315e  33c9                               xor    ecx,ecx
004b3160  3b98505f0000                       cmp    ebx,DWORD PTR [eax+0x5f50]
004b3166  8b46fa                             mov    eax,DWORD PTR [esi-0x6]
004b3169  0f94c1                             sete   cl
004b316c  894d0c                             mov    DWORD PTR [ebp+0xc],ecx
004b316f  83f801                             cmp    eax,0x1
004b3172  0f84d9000000                       je     0x4b3251
004b3178  83c0fe                             add    eax,0xfffffffe
004b317b  83f802                             cmp    eax,0x2
004b317e  0f8736010000                       ja     0x4b32ba
004b3184  6a00                               push   0x0
004b3186  68c4dff700                         push   0xf7dfc4
004b318b  6894dff700                         push   0xf7df94
004b3190  6a00                               push   0x0
004b3192  57                                 push   edi
004b3193  e8ddce4400                         call   0x900075
004b3198  8bf8                               mov    edi,eax
004b319a  83c414                             add    esp,0x14
004b319d  85ff                               test   edi,edi
004b319f  0f8415010000                       je     0x4b32ba
004b31a5  0fb79f88000000                     movzx  ebx,WORD PTR [edi+0x88]
004b31ac  e8ef19f5ff                         call   0x404ba0
004b31b1  8bcb                               mov    ecx,ebx
004b31b3  83f909                             cmp    ecx,0x9
004b31b6  0f87fe000000                       ja     0x4b32ba
004b31bc  69c910020000                       imul   ecx,ecx,0x210
004b31c2  038824690000                       add    ecx,DWORD PTR [eax+0x6924]
004b31c8  0f84ec000000                       je     0x4b32ba
004b31ce  8b46fa                             mov    eax,DWORD PTR [esi-0x6]
004b31d1  83e802                             sub    eax,0x2
004b31d4  7457                               je     0x4b322d
004b31d6  48                                 dec    eax
004b31d7  742d                               je     0x4b3206
004b31d9  48                                 dec    eax
004b31da  0f85da000000                       jne    0x4b32ba
004b31e0  39450c                             cmp    DWORD PTR [ebp+0xc],eax
004b31e3  740b                               je     0x4b31f0
004b31e5  8b06                               mov    eax,DWORD PTR [esi]
004b31e7  894148                             mov    DWORD PTR [ecx+0x48],eax
004b31ea  8b5608                             mov    edx,DWORD PTR [esi+0x8]
004b31ed  89513c                             mov    DWORD PTR [ecx+0x3c],edx
004b31f0  8b06                               mov    eax,DWORD PTR [esi]
004b31f2  8b4e08                             mov    ecx,DWORD PTR [esi+0x8]
004b31f5  8987c4030000                       mov    DWORD PTR [edi+0x3c4],eax
004b31fb  898fd0030000                       mov    DWORD PTR [edi+0x3d0],ecx
004b3201  e9b4000000                         jmp    0x4b32ba
004b3206  837d0c00                           cmp    DWORD PTR [ebp+0xc],0x0
004b320a  740b                               je     0x4b3217
004b320c  8b06                               mov    eax,DWORD PTR [esi]
004b320e  894144                             mov    DWORD PTR [ecx+0x44],eax
004b3211  8b5608                             mov    edx,DWORD PTR [esi+0x8]
004b3214  895138                             mov    DWORD PTR [ecx+0x38],edx
004b3217  8b06                               mov    eax,DWORD PTR [esi]
004b3219  8b4e08                             mov    ecx,DWORD PTR [esi+0x8]
004b321c  8987c0030000                       mov    DWORD PTR [edi+0x3c0],eax
004b3222  898fcc030000                       mov    DWORD PTR [edi+0x3cc],ecx
004b3228  e98d000000                         jmp    0x4b32ba
004b322d  837d0c00                           cmp    DWORD PTR [ebp+0xc],0x0
004b3231  740b                               je     0x4b323e
004b3233  8b06                               mov    eax,DWORD PTR [esi]
004b3235  894140                             mov    DWORD PTR [ecx+0x40],eax
004b3238  8b5608                             mov    edx,DWORD PTR [esi+0x8]
004b323b  895134                             mov    DWORD PTR [ecx+0x34],edx
004b323e  8b06                               mov    eax,DWORD PTR [esi]
004b3240  8b4e08                             mov    ecx,DWORD PTR [esi+0x8]
004b3243  8987bc030000                       mov    DWORD PTR [edi+0x3bc],eax
004b3249  898fc8030000                       mov    DWORD PTR [edi+0x3c8],ecx
004b324f  eb69                               jmp    0x4b32ba
004b3251  85c9                               test   ecx,ecx
004b3253  743c                               je     0x4b3291
004b3255  0fb79f88000000                     movzx  ebx,WORD PTR [edi+0x88]
004b325c  e83f19f5ff                         call   0x404ba0
004b3261  8b8824690000                       mov    ecx,DWORD PTR [eax+0x6924]
004b3267  8bc3                               mov    eax,ebx
004b3269  83f809                             cmp    eax,0x9
004b326c  7723                               ja     0x4b3291
004b326e  69c010020000                       imul   eax,eax,0x210
004b3274  03c1                               add    eax,ecx
004b3276  83785c00                           cmp    DWORD PTR [eax+0x5c],0x0
004b327a  7415                               je     0x4b3291
004b327c  85c0                               test   eax,eax
004b327e  7411                               je     0x4b3291
004b3280  8b4e04                             mov    ecx,DWORD PTR [esi+0x4]
004b3283  894854                             mov    DWORD PTR [eax+0x54],ecx
004b3286  8b16                               mov    edx,DWORD PTR [esi]
004b3288  895058                             mov    DWORD PTR [eax+0x58],edx
004b328b  8b4e08                             mov    ecx,DWORD PTR [esi+0x8]
004b328e  894850                             mov    DWORD PTR [eax+0x50],ecx
004b3291  8b17                               mov    edx,DWORD PTR [edi]
004b3293  8b4604                             mov    eax,DWORD PTR [esi+0x4]
004b3296  8b527c                             mov    edx,DWORD PTR [edx+0x7c]
004b3299  50                                 push   eax
004b329a  8bcf                               mov    ecx,edi
004b329c  ffd2                               call   edx
004b329e  8b0e                               mov    ecx,DWORD PTR [esi]
004b32a0  8b07                               mov    eax,DWORD PTR [edi]
004b32a2  8b9080000000                       mov    edx,DWORD PTR [eax+0x80]
004b32a8  51                                 push   ecx
004b32a9  8bcf                               mov    ecx,edi
004b32ab  ffd2                               call   edx
004b32ad  8b4e08                             mov    ecx,DWORD PTR [esi+0x8]
004b32b0  8b07                               mov    eax,DWORD PTR [edi]
004b32b2  8b5078                             mov    edx,DWORD PTR [eax+0x78]
004b32b5  51                                 push   ecx
004b32b6  8bcf                               mov    ecx,edi
004b32b8  ffd2                               call   edx
004b32ba  83c612                             add    esi,0x12
004b32bd  ff4d08                             dec    DWORD PTR [ebp+0x8]
004b32c0  0f85fbfdffff                       jne    0x4b30c1
004b32c6  5f                                 pop    edi
004b32c7  5e                                 pop    esi
004b32c8  5b                                 pop    ebx
004b32c9  33c0                               xor    eax,eax
004b32cb  8be5                               mov    esp,ebp
004b32cd  5d                                 pop    ebp
004b32ce  c20c00                             ret    0xc
; monster_caption [0x4d1b90,0x4d1e01) 完整；+430 gate 與兩數字顯示；不展開所有字型/圖形 callee
004d1b90  55                                 push   ebp
004d1b91  8bec                               mov    ebp,esp
004d1b93  83e4f8                             and    esp,0xfffffff8
004d1b96  6aff                               push   0xffffffff
004d1b98  68e6a29300                         push   0x93a2e6
004d1b9d  64a100000000                       mov    eax,fs:0x0
004d1ba3  50                                 push   eax
004d1ba4  83ec70                             sub    esp,0x70
004d1ba7  a1201fd600                         mov    eax,ds:0xd61f20
004d1bac  33c4                               xor    eax,esp
004d1bae  89442468                           mov    DWORD PTR [esp+0x68],eax
004d1bb2  53                                 push   ebx
004d1bb3  56                                 push   esi
004d1bb4  57                                 push   edi
004d1bb5  a1201fd600                         mov    eax,ds:0xd61f20
004d1bba  33c4                               xor    eax,esp
004d1bbc  50                                 push   eax
004d1bbd  8d842480000000                     lea    eax,[esp+0x80]
004d1bc4  64a300000000                       mov    fs:0x0,eax
004d1bca  f605e879fb0001                     test   BYTE PTR ds:0xfb79e8,0x1
004d1bd1  8bf1                               mov    esi,ecx
004d1bd3  752f                               jne    0x4d1c04
004d1bd5  830de879fb0001                     or     DWORD PTR ds:0xfb79e8,0x1
004d1bdc  c784248800000000000000             mov    DWORD PTR [esp+0x88],0x0
004d1be7  e8f4712c00                         call   0x798de0
004d1bec  68e0d2bc00                         push   0xbcd2e0
004d1bf1  e824073c00                         call   0x89231a
004d1bf6  83c404                             add    esp,0x4
004d1bf9  c7842488000000ffffffff             mov    DWORD PTR [esp+0x88],0xffffffff
004d1c04  a1e876fb00                         mov    eax,ds:0xfb76e8
004d1c09  8b4804                             mov    ecx,DWORD PTR [eax+0x4]
004d1c0c  8b11                               mov    edx,DWORD PTR [ecx]
004d1c0e  8b5224                             mov    edx,DWORD PTR [edx+0x24]
004d1c11  8d442430                           lea    eax,[esp+0x30]
004d1c15  50                                 push   eax
004d1c16  ffd2                               call   edx
004d1c18  8b5004                             mov    edx,DWORD PTR [eax+0x4]
004d1c1b  8b08                               mov    ecx,DWORD PTR [eax]
004d1c1d  8b4008                             mov    eax,DWORD PTR [eax+0x8]
004d1c20  8954241c                           mov    DWORD PTR [esp+0x1c],edx
004d1c24  8b16                               mov    edx,DWORD PTR [esi]
004d1c26  894c2418                           mov    DWORD PTR [esp+0x18],ecx
004d1c2a  89442420                           mov    DWORD PTR [esp+0x20],eax
004d1c2e  8b424c                             mov    eax,DWORD PTR [edx+0x4c]
004d1c31  8bce                               mov    ecx,esi
004d1c33  ffd0                               call   eax
004d1c35  d9442418                           fld    DWORD PTR [esp+0x18]
004d1c39  d820                               fsub   DWORD PTR [eax]
004d1c3b  d95c2424                           fstp   DWORD PTR [esp+0x24]
004d1c3f  d944241c                           fld    DWORD PTR [esp+0x1c]
004d1c43  d86004                             fsub   DWORD PTR [eax+0x4]
004d1c46  d95c242c                           fstp   DWORD PTR [esp+0x2c]
004d1c4a  d9442420                           fld    DWORD PTR [esp+0x20]
004d1c4e  d86008                             fsub   DWORD PTR [eax+0x8]
004d1c51  d95c2414                           fstp   DWORD PTR [esp+0x14]
004d1c55  d944242c                           fld    DWORD PTR [esp+0x2c]
004d1c59  d9442424                           fld    DWORD PTR [esp+0x24]
004d1c5d  d9442414                           fld    DWORD PTR [esp+0x14]
004d1c61  d9c1                               fld    st(1)
004d1c63  deca                               fmulp  st(2),st
004d1c65  d9c2                               fld    st(2)
004d1c67  decb                               fmulp  st(3),st
004d1c69  d9c9                               fxch   st(1)
004d1c6b  dec2                               faddp  st(2),st
004d1c6d  dcc8                               fmul   st(0),st
004d1c6f  dec1                               faddp  st(1),st
004d1c71  d95c2414                           fstp   DWORD PTR [esp+0x14]
004d1c75  d9442414                           fld    DWORD PTR [esp+0x14]
004d1c79  e8f2db4200                         call   0x8ff870
004d1c7e  d95c2414                           fstp   DWORD PTR [esp+0x14]
004d1c82  d9442414                           fld    DWORD PTR [esp+0x14]
004d1c86  d95c2414                           fstp   DWORD PTR [esp+0x14]
004d1c8a  d905c45ac500                       fld    DWORD PTR ds:0xc55ac4
004d1c90  d9442414                           fld    DWORD PTR [esp+0x14]
004d1c94  dff1                               fcomip st,st(1)
004d1c96  ddd8                               fstp   st(0)
004d1c98  7607                               jbe    0x4d1ca1
004d1c9a  33c0                               xor    eax,eax
004d1c9c  e940010000                         jmp    0x4d1de1
004d1ca1  8bce                               mov    ecx,esi
004d1ca3  e8486cffff                         call   0x4c88f0
004d1ca8  83be7003000000                     cmp    DWORD PTR [esi+0x370],0x0
004d1caf  89442414                           mov    DWORD PTR [esp+0x14],eax
004d1cb3  0f8424010000                       je     0x4d1ddd
004d1cb9  83be1c04000000                     cmp    DWORD PTR [esi+0x41c],0x0
004d1cc0  0f8417010000                       je     0x4d1ddd
004d1cc6  d9e8                               fld1
004d1cc8  51                                 push   ecx
004d1cc9  8d54241c                           lea    edx,[esp+0x1c]
004d1ccd  d91c24                             fstp   DWORD PTR [esp]
004d1cd0  52                                 push   edx
004d1cd1  8d8ea0000000                       lea    ecx,[esi+0xa0]
004d1cd7  8bd6                               mov    edx,esi
004d1cd9  e8127bffff                         call   0x4c97f0
004d1cde  56                                 push   esi
004d1cdf  bfffbbbbff                         mov    edi,0xffbbbbff
004d1ce4  e89778ffff                         call   0x4c9580
004d1ce9  83f810                             cmp    eax,0x10
004d1cec  7507                               jne    0x4d1cf5
004d1cee  bf6cff00ff                         mov    edi,0xff00ff6c
004d1cf3  eb3a                               jmp    0x4d1d2f
004d1cf5  83f811                             cmp    eax,0x11
004d1cf8  7507                               jne    0x4d1d01
004d1cfa  bf6cff00ff                         mov    edi,0xff00ff6c
004d1cff  eb2e                               jmp    0x4d1d2f
004d1d01  83f812                             cmp    eax,0x12
004d1d04  7529                               jne    0x4d1d2f
004d1d06  83be2804000000                     cmp    DWORD PTR [esi+0x428],0x0
004d1d0d  7407                               je     0x4d1d16
004d1d0f  bf5500ffff                         mov    edi,0xffff0055
004d1d14  eb19                               jmp    0x4d1d2f
004d1d16  8bbe24040000                       mov    edi,DWORD PTR [esi+0x424]
004d1d1c  83ef03                             sub    edi,0x3
004d1d1f  f7df                               neg    edi
004d1d21  1bff                               sbb    edi,edi
004d1d23  81e733800000                       and    edi,0x8033
004d1d29  81c79919ffff                       add    edi,0xffff1999
004d1d2f  8b5c241c                           mov    ebx,DWORD PTR [esp+0x1c]
004d1d33  8b4c2420                           mov    ecx,DWORD PTR [esp+0x20]
004d1d37  6a00                               push   0x0
004d1d39  68000000ff                         push   0xff000000
004d1d3e  57                                 push   edi
004d1d3f  8b7c2424                           mov    edi,DWORD PTR [esp+0x24]
004d1d43  83ec0c                             sub    esp,0xc
004d1d46  8bc4                               mov    eax,esp
004d1d48  8938                               mov    DWORD PTR [eax],edi
004d1d4a  895804                             mov    DWORD PTR [eax+0x4],ebx
004d1d4d  8d5606                             lea    edx,[esi+0x6]
004d1d50  894808                             mov    DWORD PTR [eax+0x8],ecx
004d1d53  52                                 push   edx
004d1d54  33c9                               xor    ecx,ecx
004d1d56  e8057effff                         call   0x4c9b60
004d1d5b  83c41c                             add    esp,0x1c
004d1d5e  83be3004000000                     cmp    DWORD PTR [esi+0x430],0x0
004d1d65  7476                               je     0x4d1ddd
004d1d67  8b86bc030000                       mov    eax,DWORD PTR [esi+0x3bc]
004d1d6d  8b8ec8030000                       mov    ecx,DWORD PTR [esi+0x3c8]
004d1d73  6870c9c000                         push   0xc0c970
004d1d78  8d742460                           lea    esi,[esp+0x60]
004d1d7c  c744242800000000                   mov    DWORD PTR [esp+0x28],0x0
004d1d84  c744242cecffffff                   mov    DWORD PTR [esp+0x2c],0xffffffec
004d1d8c  e8cfc6f3ff                         call   0x40e460
004d1d91  83c404                             add    esp,0x4
004d1d94  c784248800000001000000             mov    DWORD PTR [esp+0x88],0x1
004d1d9f  837c247008                         cmp    DWORD PTR [esp+0x70],0x8
004d1da4  8b4c245c                           mov    ecx,DWORD PTR [esp+0x5c]
004d1da8  7302                               jae    0x4d1dac
004d1daa  8bce                               mov    ecx,esi
004d1dac  8b542420                           mov    edx,DWORD PTR [esp+0x20]
004d1db0  8d442424                           lea    eax,[esp+0x24]
004d1db4  50                                 push   eax
004d1db5  68000000ff                         push   0xff000000
004d1dba  6aff                               push   0xffffffff
004d1dbc  83ec0c                             sub    esp,0xc
004d1dbf  8bc4                               mov    eax,esp
004d1dc1  8938                               mov    DWORD PTR [eax],edi
004d1dc3  51                                 push   ecx
004d1dc4  895804                             mov    DWORD PTR [eax+0x4],ebx
004d1dc7  33c9                               xor    ecx,ecx
004d1dc9  895008                             mov    DWORD PTR [eax+0x8],edx
004d1dcc  e88f7dffff                         call   0x4c9b60
004d1dd1  83c41c                             add    esp,0x1c
004d1dd4  8d4c245c                           lea    ecx,[esp+0x5c]
004d1dd8  e863860200                         call   0x4fa440
004d1ddd  8b442414                           mov    eax,DWORD PTR [esp+0x14]
004d1de1  8b8c2480000000                     mov    ecx,DWORD PTR [esp+0x80]
004d1de8  64890d00000000                     mov    DWORD PTR fs:0x0,ecx
004d1def  59                                 pop    ecx
004d1df0  5f                                 pop    edi
004d1df1  5e                                 pop    esi
004d1df2  5b                                 pop    ebx
004d1df3  8b4c2468                           mov    ecx,DWORD PTR [esp+0x68]
004d1df7  33cc                               xor    ecx,esp
004d1df9  e803f23b00                         call   0x891001
004d1dfe  8be5                               mov    esp,ebp
004d1e00  5d                                 pop    ebp
; hud_resource_update [0x5d1bf0,0x5d2120) 完整；current/max 與 state+34 分流；UI下層非完整圖形還原
005d1bf0  55                                 push   ebp
005d1bf1  8bec                               mov    ebp,esp
005d1bf3  83e4f8                             and    esp,0xfffffff8
005d1bf6  6aff                               push   0xffffffff
005d1bf8  68f6379400                         push   0x9437f6
005d1bfd  64a100000000                       mov    eax,fs:0x0
005d1c03  50                                 push   eax
005d1c04  83ec2c                             sub    esp,0x2c
005d1c07  a1201fd600                         mov    eax,ds:0xd61f20
005d1c0c  33c4                               xor    eax,esp
005d1c0e  89442424                           mov    DWORD PTR [esp+0x24],eax
005d1c12  53                                 push   ebx
005d1c13  56                                 push   esi
005d1c14  a1201fd600                         mov    eax,ds:0xd61f20
005d1c19  33c4                               xor    eax,esp
005d1c1b  50                                 push   eax
005d1c1c  8d442438                           lea    eax,[esp+0x38]
005d1c20  64a300000000                       mov    fs:0x0,eax
005d1c26  f6052cb2fa0001                     test   BYTE PTR ds:0xfab22c,0x1
005d1c2d  7529                               jne    0x5d1c58
005d1c2f  830d2cb2fa0001                     or     DWORD PTR ds:0xfab22c,0x1
005d1c36  c744244000000000                   mov    DWORD PTR [esp+0x40],0x0
005d1c3e  e84dd0f0ff                         call   0x4dec90
005d1c43  6830cebc00                         push   0xbcce30
005d1c48  e8cd062c00                         call   0x89231a
005d1c4d  83c404                             add    esp,0x4
005d1c50  c7442440ffffffff                   mov    DWORD PTR [esp+0x40],0xffffffff
005d1c58  8b0da4a7fb00                       mov    ecx,DWORD PTR ds:0xfba7a4
005d1c5e  85c9                               test   ecx,ecx
005d1c60  0f849d040000                       je     0x5d2103
005d1c66  8b01                               mov    eax,DWORD PTR [ecx]
005d1c68  8b5020                             mov    edx,DWORD PTR [eax+0x20]
005d1c6b  ffd2                               call   edx
005d1c6d  8bd8                               mov    ebx,eax
005d1c6f  85db                               test   ebx,ebx
005d1c71  0f848c040000                       je     0x5d2103
005d1c77  8b8358010000                       mov    eax,DWORD PTR [ebx+0x158]
005d1c7d  85c0                               test   eax,eax
005d1c7f  740a                               je     0x5d1c8b
005d1c81  83783400                           cmp    DWORD PTR [eax+0x34],0x0
005d1c85  0f8450010000                       je     0x5d1ddb
005d1c8b  80bf8000000000                     cmp    BYTE PTR [edi+0x80],0x0
005d1c92  0f8575030000                       jne    0x5d200d
005d1c98  8b83bc030000                       mov    eax,DWORD PTR [ebx+0x3bc]
005d1c9e  83ec1c                             sub    esp,0x1c
005d1ca1  8bf4                               mov    esi,esp
005d1ca3  89642428                           mov    DWORD PTR [esp+0x28],esp
005d1ca7  68f82bbf00                         push   0xbf2bf8
005d1cac  33c9                               xor    ecx,ecx
005d1cae  e8adc7e3ff                         call   0x40e460
005d1cb3  8b87a4000000                       mov    eax,DWORD PTR [edi+0xa4]
005d1cb9  83c404                             add    esp,0x4
005d1cbc  50                                 push   eax
005d1cbd  e82ed3e3ff                         call   0x40eff0
005d1cc2  8b8fa4000000                       mov    ecx,DWORD PTR [edi+0xa4]
005d1cc8  8b11                               mov    edx,DWORD PTR [ecx]
005d1cca  0f57c0                             xorps  xmm0,xmm0
005d1ccd  8b8228010000                       mov    eax,DWORD PTR [edx+0x128]
005d1cd3  f30f1181d0000000                   movss  DWORD PTR [ecx+0xd0],xmm0
005d1cdb  ffd0                               call   eax
005d1cdd  8b8fa4000000                       mov    ecx,DWORD PTR [edi+0xa4]
005d1ce3  8b11                               mov    edx,DWORD PTR [ecx]
005d1ce5  8b82c8000000                       mov    eax,DWORD PTR [edx+0xc8]
005d1ceb  ffd0                               call   eax
005d1ced  8b83c0030000                       mov    eax,DWORD PTR [ebx+0x3c0]
005d1cf3  83ec1c                             sub    esp,0x1c
005d1cf6  8bf4                               mov    esi,esp
005d1cf8  89642428                           mov    DWORD PTR [esp+0x28],esp
005d1cfc  68f82bbf00                         push   0xbf2bf8
005d1d01  33c9                               xor    ecx,ecx
005d1d03  e858c7e3ff                         call   0x40e460
005d1d08  8b8fa8000000                       mov    ecx,DWORD PTR [edi+0xa8]
005d1d0e  83c404                             add    esp,0x4
005d1d11  51                                 push   ecx
005d1d12  e8d9d2e3ff                         call   0x40eff0
005d1d17  8b8fa8000000                       mov    ecx,DWORD PTR [edi+0xa8]
005d1d1d  8b11                               mov    edx,DWORD PTR [ecx]
005d1d1f  0f57c0                             xorps  xmm0,xmm0
005d1d22  8b8228010000                       mov    eax,DWORD PTR [edx+0x128]
005d1d28  f30f1181d0000000                   movss  DWORD PTR [ecx+0xd0],xmm0
005d1d30  ffd0                               call   eax
005d1d32  8b8fa8000000                       mov    ecx,DWORD PTR [edi+0xa8]
005d1d38  8b11                               mov    edx,DWORD PTR [ecx]
005d1d3a  8b82c8000000                       mov    eax,DWORD PTR [edx+0xc8]
005d1d40  ffd0                               call   eax
005d1d42  8b83c4030000                       mov    eax,DWORD PTR [ebx+0x3c4]
005d1d48  83ec1c                             sub    esp,0x1c
005d1d4b  8bf4                               mov    esi,esp
005d1d4d  89642428                           mov    DWORD PTR [esp+0x28],esp
005d1d51  68f82bbf00                         push   0xbf2bf8
005d1d56  33c9                               xor    ecx,ecx
005d1d58  e803c7e3ff                         call   0x40e460
005d1d5d  8b8fac000000                       mov    ecx,DWORD PTR [edi+0xac]
005d1d63  83c404                             add    esp,0x4
005d1d66  51                                 push   ecx
005d1d67  e884d2e3ff                         call   0x40eff0
005d1d6c  8b8fac000000                       mov    ecx,DWORD PTR [edi+0xac]
005d1d72  8b11                               mov    edx,DWORD PTR [ecx]
005d1d74  0f57c0                             xorps  xmm0,xmm0
005d1d77  8b8228010000                       mov    eax,DWORD PTR [edx+0x128]
005d1d7d  f30f1181d0000000                   movss  DWORD PTR [ecx+0xd0],xmm0
005d1d85  ffd0                               call   eax
005d1d87  8b8fac000000                       mov    ecx,DWORD PTR [edi+0xac]
005d1d8d  8b11                               mov    edx,DWORD PTR [ecx]
005d1d8f  8b82c8000000                       mov    eax,DWORD PTR [edx+0xc8]
005d1d95  ffd0                               call   eax
005d1d97  33c0                               xor    eax,eax
005d1d99  c6878000000001                     mov    BYTE PTR [edi+0x80],0x1
005d1da0  89878c000000                       mov    DWORD PTR [edi+0x8c],eax
005d1da6  898790000000                       mov    DWORD PTR [edi+0x90],eax
005d1dac  898794000000                       mov    DWORD PTR [edi+0x94],eax
005d1db2  8b83bc030000                       mov    eax,DWORD PTR [ebx+0x3bc]
005d1db8  898798000000                       mov    DWORD PTR [edi+0x98],eax
005d1dbe  8b83c0030000                       mov    eax,DWORD PTR [ebx+0x3c0]
005d1dc4  89879c000000                       mov    DWORD PTR [edi+0x9c],eax
005d1dca  8b83c4030000                       mov    eax,DWORD PTR [ebx+0x3c4]
005d1dd0  8987a0000000                       mov    DWORD PTR [edi+0xa0],eax
005d1dd6  e932020000                         jmp    0x5d200d
005d1ddb  8b8bc8030000                       mov    ecx,DWORD PTR [ebx+0x3c8]
005d1de1  398f8c000000                       cmp    DWORD PTR [edi+0x8c],ecx
005d1de7  7512                               jne    0x5d1dfb
005d1de9  8b83bc030000                       mov    eax,DWORD PTR [ebx+0x3bc]
005d1def  398798000000                       cmp    DWORD PTR [edi+0x98],eax
005d1df5  0f8499000000                       je     0x5d1e94
005d1dfb  8b83bc030000                       mov    eax,DWORD PTR [ebx+0x3bc]
005d1e01  85c0                               test   eax,eax
005d1e03  7e1e                               jle    0x5d1e23
005d1e05  894c2410                           mov    DWORD PTR [esp+0x10],ecx
005d1e09  db442410                           fild   DWORD PTR [esp+0x10]
005d1e0d  8944240c                           mov    DWORD PTR [esp+0xc],eax
005d1e11  8b8fa4000000                       mov    ecx,DWORD PTR [edi+0xa4]
005d1e17  da74240c                           fidiv  DWORD PTR [esp+0xc]
005d1e1b  d999d0000000                       fstp   DWORD PTR [ecx+0xd0]
005d1e21  eb11                               jmp    0x5d1e34
005d1e23  8b8fa4000000                       mov    ecx,DWORD PTR [edi+0xa4]
005d1e29  0f57c0                             xorps  xmm0,xmm0
005d1e2c  f30f1181d0000000                   movss  DWORD PTR [ecx+0xd0],xmm0
005d1e34  8b11                               mov    edx,DWORD PTR [ecx]
005d1e36  8b8228010000                       mov    eax,DWORD PTR [edx+0x128]
005d1e3c  ffd0                               call   eax
005d1e3e  8b83bc030000                       mov    eax,DWORD PTR [ebx+0x3bc]
005d1e44  8b8bc8030000                       mov    ecx,DWORD PTR [ebx+0x3c8]
005d1e4a  83ec1c                             sub    esp,0x1c
005d1e4d  8bf4                               mov    esi,esp
005d1e4f  89642428                           mov    DWORD PTR [esp+0x28],esp
005d1e53  68f82bbf00                         push   0xbf2bf8
005d1e58  e803c6e3ff                         call   0x40e460
005d1e5d  8b8fa4000000                       mov    ecx,DWORD PTR [edi+0xa4]
005d1e63  83c404                             add    esp,0x4
005d1e66  51                                 push   ecx
005d1e67  e884d1e3ff                         call   0x40eff0
005d1e6c  8b8fa4000000                       mov    ecx,DWORD PTR [edi+0xa4]
005d1e72  8b11                               mov    edx,DWORD PTR [ecx]
005d1e74  8b82c8000000                       mov    eax,DWORD PTR [edx+0xc8]
005d1e7a  ffd0                               call   eax
005d1e7c  8b8bc8030000                       mov    ecx,DWORD PTR [ebx+0x3c8]
005d1e82  898f8c000000                       mov    DWORD PTR [edi+0x8c],ecx
005d1e88  8b83bc030000                       mov    eax,DWORD PTR [ebx+0x3bc]
005d1e8e  898798000000                       mov    DWORD PTR [edi+0x98],eax
005d1e94  8b8bcc030000                       mov    ecx,DWORD PTR [ebx+0x3cc]
005d1e9a  398f90000000                       cmp    DWORD PTR [edi+0x90],ecx
005d1ea0  7512                               jne    0x5d1eb4
005d1ea2  8b83c0030000                       mov    eax,DWORD PTR [ebx+0x3c0]
005d1ea8  39879c000000                       cmp    DWORD PTR [edi+0x9c],eax
005d1eae  0f8499000000                       je     0x5d1f4d
005d1eb4  8b83c0030000                       mov    eax,DWORD PTR [ebx+0x3c0]
005d1eba  85c0                               test   eax,eax
005d1ebc  7e1e                               jle    0x5d1edc
005d1ebe  894c240c                           mov    DWORD PTR [esp+0xc],ecx
005d1ec2  db44240c                           fild   DWORD PTR [esp+0xc]
005d1ec6  89442410                           mov    DWORD PTR [esp+0x10],eax
005d1eca  8b8fa8000000                       mov    ecx,DWORD PTR [edi+0xa8]
005d1ed0  da742410                           fidiv  DWORD PTR [esp+0x10]
005d1ed4  d999d0000000                       fstp   DWORD PTR [ecx+0xd0]
005d1eda  eb11                               jmp    0x5d1eed
005d1edc  8b8fa8000000                       mov    ecx,DWORD PTR [edi+0xa8]
005d1ee2  0f57c0                             xorps  xmm0,xmm0
005d1ee5  f30f1181d0000000                   movss  DWORD PTR [ecx+0xd0],xmm0
005d1eed  8b11                               mov    edx,DWORD PTR [ecx]
005d1eef  8b8228010000                       mov    eax,DWORD PTR [edx+0x128]
005d1ef5  ffd0                               call   eax
005d1ef7  8b83c0030000                       mov    eax,DWORD PTR [ebx+0x3c0]
005d1efd  8b8bcc030000                       mov    ecx,DWORD PTR [ebx+0x3cc]
005d1f03  83ec1c                             sub    esp,0x1c
005d1f06  8bf4                               mov    esi,esp
005d1f08  89642428                           mov    DWORD PTR [esp+0x28],esp
005d1f0c  68f82bbf00                         push   0xbf2bf8
005d1f11  e84ac5e3ff                         call   0x40e460
005d1f16  8b8fa8000000                       mov    ecx,DWORD PTR [edi+0xa8]
005d1f1c  83c404                             add    esp,0x4
005d1f1f  51                                 push   ecx
005d1f20  e8cbd0e3ff                         call   0x40eff0
005d1f25  8b8fa8000000                       mov    ecx,DWORD PTR [edi+0xa8]
005d1f2b  8b11                               mov    edx,DWORD PTR [ecx]
005d1f2d  8b82c8000000                       mov    eax,DWORD PTR [edx+0xc8]
005d1f33  ffd0                               call   eax
005d1f35  8b8bcc030000                       mov    ecx,DWORD PTR [ebx+0x3cc]
005d1f3b  898f90000000                       mov    DWORD PTR [edi+0x90],ecx
005d1f41  8b83c0030000                       mov    eax,DWORD PTR [ebx+0x3c0]
005d1f47  89879c000000                       mov    DWORD PTR [edi+0x9c],eax
005d1f4d  8b8bd0030000                       mov    ecx,DWORD PTR [ebx+0x3d0]
005d1f53  398f94000000                       cmp    DWORD PTR [edi+0x94],ecx
005d1f59  7512                               jne    0x5d1f6d
005d1f5b  8b83c4030000                       mov    eax,DWORD PTR [ebx+0x3c4]
005d1f61  3987a0000000                       cmp    DWORD PTR [edi+0xa0],eax
005d1f67  0f8499000000                       je     0x5d2006
005d1f6d  8b83c4030000                       mov    eax,DWORD PTR [ebx+0x3c4]
005d1f73  85c0                               test   eax,eax
005d1f75  7e1e                               jle    0x5d1f95
005d1f77  894c240c                           mov    DWORD PTR [esp+0xc],ecx
005d1f7b  db44240c                           fild   DWORD PTR [esp+0xc]
005d1f7f  89442410                           mov    DWORD PTR [esp+0x10],eax
005d1f83  8b8fac000000                       mov    ecx,DWORD PTR [edi+0xac]
005d1f89  da742410                           fidiv  DWORD PTR [esp+0x10]
005d1f8d  d999d0000000                       fstp   DWORD PTR [ecx+0xd0]
005d1f93  eb11                               jmp    0x5d1fa6
005d1f95  8b8fac000000                       mov    ecx,DWORD PTR [edi+0xac]
005d1f9b  0f57c0                             xorps  xmm0,xmm0
005d1f9e  f30f1181d0000000                   movss  DWORD PTR [ecx+0xd0],xmm0
005d1fa6  8b11                               mov    edx,DWORD PTR [ecx]
005d1fa8  8b8228010000                       mov    eax,DWORD PTR [edx+0x128]
005d1fae  ffd0                               call   eax
005d1fb0  8b83c4030000                       mov    eax,DWORD PTR [ebx+0x3c4]
005d1fb6  8b8bd0030000                       mov    ecx,DWORD PTR [ebx+0x3d0]
005d1fbc  83ec1c                             sub    esp,0x1c
005d1fbf  8bf4                               mov    esi,esp
005d1fc1  89642428                           mov    DWORD PTR [esp+0x28],esp
005d1fc5  68f82bbf00                         push   0xbf2bf8
005d1fca  e891c4e3ff                         call   0x40e460
005d1fcf  8b8fac000000                       mov    ecx,DWORD PTR [edi+0xac]
005d1fd5  83c404                             add    esp,0x4
005d1fd8  51                                 push   ecx
005d1fd9  e812d0e3ff                         call   0x40eff0
005d1fde  8b8fac000000                       mov    ecx,DWORD PTR [edi+0xac]
005d1fe4  8b11                               mov    edx,DWORD PTR [ecx]
005d1fe6  8b82c8000000                       mov    eax,DWORD PTR [edx+0xc8]
005d1fec  ffd0                               call   eax
005d1fee  8b8bd0030000                       mov    ecx,DWORD PTR [ebx+0x3d0]
005d1ff4  898f94000000                       mov    DWORD PTR [edi+0x94],ecx
005d1ffa  8b83c4030000                       mov    eax,DWORD PTR [ebx+0x3c4]
005d2000  8987a0000000                       mov    DWORD PTR [edi+0xa0],eax
005d2006  c6878000000000                     mov    BYTE PTR [edi+0x80],0x0
005d200d  0fb7b388000000                     movzx  esi,WORD PTR [ebx+0x88]
005d2014  8974240c                           mov    DWORD PTR [esp+0xc],esi
005d2018  39b784000000                       cmp    DWORD PTR [edi+0x84],esi
005d201e  742e                               je     0x5d204e
005d2020  e84b14e3ff                         call   0x403470
005d2025  8b74b058                           mov    esi,DWORD PTR [eax+esi*4+0x58]
005d2029  8b87b8000000                       mov    eax,DWORD PTR [edi+0xb8]
005d202f  e8cc301700                         call   0x745100
005d2034  8b8fb8000000                       mov    ecx,DWORD PTR [edi+0xb8]
005d203a  8b11                               mov    edx,DWORD PTR [ecx]
005d203c  8b82c8000000                       mov    eax,DWORD PTR [edx+0xc8]
005d2042  ffd0                               call   eax
005d2044  8b4c240c                           mov    ecx,DWORD PTR [esp+0xc]
005d2048  898f84000000                       mov    DWORD PTR [edi+0x84],ecx
005d204e  8b9bd4030000                       mov    ebx,DWORD PTR [ebx+0x3d4]
005d2054  399f88000000                       cmp    DWORD PTR [edi+0x88],ebx
005d205a  746e                               je     0x5d20ca
005d205c  8bcb                               mov    ecx,ebx
005d205e  8d742414                           lea    esi,[esp+0x14]
005d2062  e819cfe3ff                         call   0x40ef80
005d2067  c744244001000000                   mov    DWORD PTR [esp+0x40],0x1
005d206f  8bb7b0000000                       mov    esi,DWORD PTR [edi+0xb0]
005d2075  50                                 push   eax
005d2076  8db6e8000000                       lea    esi,[esi+0xe8]
005d207c  e87f571800                         call   0x757800
005d2081  c7442440ffffffff                   mov    DWORD PTR [esp+0x40],0xffffffff
005d2089  837c242808                         cmp    DWORD PTR [esp+0x28],0x8
005d208e  720d                               jb     0x5d209d
005d2090  8b542414                           mov    edx,DWORD PTR [esp+0x14]
005d2094  52                                 push   edx
005d2095  e872f12b00                         call   0x89120c
005d209a  83c404                             add    esp,0x4
005d209d  8b8fb0000000                       mov    ecx,DWORD PTR [edi+0xb0]
005d20a3  8b11                               mov    edx,DWORD PTR [ecx]
005d20a5  33c0                               xor    eax,eax
005d20a7  6689442414                         mov    WORD PTR [esp+0x14],ax
005d20ac  8b82c8000000                       mov    eax,DWORD PTR [edx+0xc8]
005d20b2  c744242807000000                   mov    DWORD PTR [esp+0x28],0x7
005d20ba  c744242400000000                   mov    DWORD PTR [esp+0x24],0x0
005d20c2  ffd0                               call   eax
005d20c4  899f88000000                       mov    DWORD PTR [edi+0x88],ebx
005d20ca  e891cfe3ff                         call   0x40f060
005d20cf  8b80f8000000                       mov    eax,DWORD PTR [eax+0xf8]
005d20d5  85c0                               test   eax,eax
005d20d7  740a                               je     0x5d20e3
005d20d9  80782800                           cmp    BYTE PTR [eax+0x28],0x0
005d20dd  7404                               je     0x5d20e3
005d20df  b001                               mov    al,0x1
005d20e1  eb02                               jmp    0x5d20e5
005d20e3  32c0                               xor    al,al
005d20e5  8b8fb4000000                       mov    ecx,DWORD PTR [edi+0xb4]
005d20eb  8b11                               mov    edx,DWORD PTR [ecx]
005d20ed  50                                 push   eax
005d20ee  8b8294000000                       mov    eax,DWORD PTR [edx+0x94]
005d20f4  ffd0                               call   eax
005d20f6  57                                 push   edi
005d20f7  e8d4f9ffff                         call   0x5d1ad0
005d20fc  8bf7                               mov    esi,edi
005d20fe  e80d010000                         call   0x5d2210
005d2103  8b4c2438                           mov    ecx,DWORD PTR [esp+0x38]
005d2107  64890d00000000                     mov    DWORD PTR fs:0x0,ecx
005d210e  59                                 pop    ecx
005d210f  5e                                 pop    esi
005d2110  5b                                 pop    ebx
005d2111  8b4c2424                           mov    ecx,DWORD PTR [esp+0x24]
005d2115  33cc                               xor    ecx,esp
005d2117  e8e5ee2b00                         call   0x891001
005d211c  8be5                               mov    esp,ebp
005d211e  5d                                 pop    ebp
005d211f  c3                                 ret
; field_hud_caller [0x5d4780,0x5d4797) 完整；普通場景 concrete UI caller
005d4780  56                                 push   esi
005d4781  57                                 push   edi
005d4782  8bf1                               mov    esi,ecx
005d4784  e827a3ffff                         call   0x5ceab0
005d4789  8bbe80030000                       mov    edi,DWORD PTR [esi+0x380]
005d478f  e85cd4ffff                         call   0x5d1bf0
005d4794  5f                                 pop    edi
005d4795  5e                                 pop    esi
005d4796  c3                                 ret
; native_skill_check [0x549980,0x549c51) 完整；HP/SP/MP成本比較；不是傷害公式/死亡判決
00549980  55                                 push   ebp
00549981  8bec                               mov    ebp,esp
00549983  83e4f8                             and    esp,0xfffffff8
00549986  6aff                               push   0xffffffff
00549988  687cfd9300                         push   0x93fd7c
0054998d  64a100000000                       mov    eax,fs:0x0
00549993  50                                 push   eax
00549994  83ec20                             sub    esp,0x20
00549997  53                                 push   ebx
00549998  56                                 push   esi
00549999  57                                 push   edi
0054999a  a1201fd600                         mov    eax,ds:0xd61f20
0054999f  33c4                               xor    eax,esp
005499a1  50                                 push   eax
005499a2  8d442430                           lea    eax,[esp+0x30]
005499a6  64a300000000                       mov    fs:0x0,eax
005499ac  8b4508                             mov    eax,DWORD PTR [ebp+0x8]
005499af  8b4050                             mov    eax,DWORD PTR [eax+0x50]
005499b2  33c9                               xor    ecx,ecx
005499b4  894c2418                           mov    DWORD PTR [esp+0x18],ecx
005499b8  3bc1                               cmp    eax,ecx
005499ba  0f8478020000                       je     0x549c38
005499c0  0fb7b888000000                     movzx  edi,WORD PTR [eax+0x88]
005499c7  83cbff                             or     ebx,0xffffffff
005499ca  f6059043f90001                     test   BYTE PTR ds:0xf94390,0x1
005499d1  7521                               jne    0x5499f4
005499d3  830d9043f90001                     or     DWORD PTR ds:0xf94390,0x1
005499da  894c2438                           mov    DWORD PTR [esp+0x38],ecx
005499de  e8ad7bf9ff                         call   0x4e1590
005499e3  6880ccbc00                         push   0xbccc80
005499e8  e82d893400                         call   0x89231a
005499ed  83c404                             add    esp,0x4
005499f0  895c2438                           mov    DWORD PTR [esp+0x38],ebx
005499f4  83ff09                             cmp    edi,0x9
005499f7  7727                               ja     0x549a20
005499f9  8b0d0443f900                       mov    ecx,DWORD PTR ds:0xf94304
005499ff  8bf7                               mov    esi,edi
00549a01  69f610020000                       imul   esi,esi,0x210
00549a07  837c0e5c00                         cmp    DWORD PTR [esi+ecx*1+0x5c],0x0
00549a0c  8d040e                             lea    eax,[esi+ecx*1]
00549a0f  740f                               je     0x549a20
00549a11  85c0                               test   eax,eax
00549a13  740b                               je     0x549a20
00549a15  05f4010000                         add    eax,0x1f4
00549a1a  89442428                           mov    DWORD PTR [esp+0x28],eax
00549a1e  7517                               jne    0x549a37
00549a20  33c0                               xor    eax,eax
00549a22  8b4c2430                           mov    ecx,DWORD PTR [esp+0x30]
00549a26  64890d00000000                     mov    DWORD PTR fs:0x0,ecx
00549a2d  59                                 pop    ecx
00549a2e  5f                                 pop    edi
00549a2f  5e                                 pop    esi
00549a30  5b                                 pop    ebx
00549a31  8be5                               mov    esp,ebp
00549a33  5d                                 pop    ebp
00549a34  c21000                             ret    0x10
00549a37  33d2                               xor    edx,edx
00549a39  385002                             cmp    BYTE PTR [eax+0x2],dl
00549a3c  0f95c2                             setne  dl
00549a3f  f60578b2fa0001                     test   BYTE PTR ds:0xfab278,0x1
00549a46  8a0402                             mov    al,BYTE PTR [edx+eax*1]
00549a49  8844241c                           mov    BYTE PTR [esp+0x1c],al
00549a4d  7525                               jne    0x549a74
00549a4f  b801000000                         mov    eax,0x1
00549a54  090578b2fa00                       or     DWORD PTR ds:0xfab278,eax
00549a5a  89442438                           mov    DWORD PTR [esp+0x38],eax
00549a5e  e83de32c00                         call   0x817da0
00549a63  68d0cebc00                         push   0xbcced0
00549a68  e8ad883400                         call   0x89231a
00549a6d  83c404                             add    esp,0x4
00549a70  895c2438                           mov    DWORD PTR [esp+0x38],ebx
00549a74  8b4c241c                           mov    ecx,DWORD PTR [esp+0x1c]
00549a78  51                                 push   ecx
00549a79  57                                 push   edi
00549a7a  b87cb2fa00                         mov    eax,0xfab27c
00549a7f  e89cf72c00                         call   0x819220
00549a84  89442420                           mov    DWORD PTR [esp+0x20],eax
00549a88  85c0                               test   eax,eax
00549a8a  7494                               je     0x549a20
00549a8c  8a550c                             mov    dl,BYTE PTR [ebp+0xc]
00549a8f  80fa04                             cmp    dl,0x4
00549a92  0f83a0010000                       jae    0x549c38
00549a98  8a4d10                             mov    cl,BYTE PTR [ebp+0x10]
00549a9b  80f90b                             cmp    cl,0xb
00549a9e  0f8394010000                       jae    0x549c38
00549aa4  0fb6d2                             movzx  edx,dl
00549aa7  6bd20b                             imul   edx,edx,0xb
00549aaa  0fb6c9                             movzx  ecx,cl
00549aad  03d1                               add    edx,ecx
00549aaf  0fb77c5004                         movzx  edi,WORD PTR [eax+edx*2+0x4]
00549ab4  6685ff                             test   di,di
00549ab7  0f847b010000                       je     0x549c38
00549abd  e8deb0ebff                         call   0x404ba0
00549ac2  8b8024690000                       mov    eax,DWORD PTR [eax+0x6924]
00549ac8  03c6                               add    eax,esi
00549aca  83785c00                           cmp    DWORD PTR [eax+0x5c],0x0
00549ace  740c                               je     0x549adc
00549ad0  85c0                               test   eax,eax
00549ad2  7408                               je     0x549adc
00549ad4  8db0d4010000                       lea    esi,[eax+0x1d4]
00549ada  eb02                               jmp    0x549ade
00549adc  33f6                               xor    esi,esi
00549ade  57                                 push   edi
00549adf  89742420                           mov    DWORD PTR [esp+0x20],esi
00549ae3  e888c42d00                         call   0x825f70
00549ae8  8bf0                               mov    esi,eax
00549aea  85f6                               test   esi,esi
00549aec  0f8446010000                       je     0x549c38
00549af2  0fb75e04                           movzx  ebx,WORD PTR [esi+0x4]
00549af6  e8b5b3f3ff                         call   0x484eb0
00549afb  50                                 push   eax
00549afc  8bc3                               mov    eax,ebx
00549afe  8bcf                               mov    ecx,edi
00549b00  e82b6afeff                         call   0x530530
00549b05  0fb75e04                           movzx  ebx,WORD PTR [esi+0x4]
00549b09  89442410                           mov    DWORD PTR [esp+0x10],eax
00549b0d  e89eb3f3ff                         call   0x484eb0
00549b12  50                                 push   eax
00549b13  8bc3                               mov    eax,ebx
00549b15  8bcf                               mov    ecx,edi
00549b17  e8a46afeff                         call   0x5305c0
00549b1c  0fb77604                           movzx  esi,WORD PTR [esi+0x4]
00549b20  8bd8                               mov    ebx,eax
00549b22  895c2424                           mov    DWORD PTR [esp+0x24],ebx
00549b26  e885b3f3ff                         call   0x484eb0
00549b2b  50                                 push   eax
00549b2c  8bc6                               mov    eax,esi
00549b2e  8bcf                               mov    ecx,edi
00549b30  e81b6bfeff                         call   0x530650
00549b35  89442414                           mov    DWORD PTR [esp+0x14],eax
00549b39  b801000000                         mov    eax,0x1
00549b3e  39450c                             cmp    DWORD PTR [ebp+0xc],eax
00549b41  756d                               jne    0x549bb0
00549b43  8b5508                             mov    edx,DWORD PTR [ebp+0x8]
00549b46  8b4a50                             mov    ecx,DWORD PTR [edx+0x50]
00549b49  3981e8030000                       cmp    DWORD PTR [ecx+0x3e8],eax
00549b4f  745f                               je     0x549bb0
00549b51  8b542420                           mov    edx,DWORD PTR [esp+0x20]
00549b55  0fb77a12                           movzx  edi,WORD PTR [edx+0x12]
00549b59  8b74241c                           mov    esi,DWORD PTR [esp+0x1c]
00549b5d  57                                 push   edi
00549b5e  e80dc42d00                         call   0x825f70
00549b63  8bf0                               mov    esi,eax
00549b65  85f6                               test   esi,esi
00549b67  7447                               je     0x549bb0
00549b69  0fb75e04                           movzx  ebx,WORD PTR [esi+0x4]
00549b6d  e83eb3f3ff                         call   0x484eb0
00549b72  50                                 push   eax
00549b73  8bc3                               mov    eax,ebx
00549b75  8bcf                               mov    ecx,edi
00549b77  e8b469feff                         call   0x530530
00549b7c  01442410                           add    DWORD PTR [esp+0x10],eax
00549b80  0fb75e04                           movzx  ebx,WORD PTR [esi+0x4]
00549b84  e827b3f3ff                         call   0x484eb0
00549b89  50                                 push   eax
00549b8a  8bc3                               mov    eax,ebx
00549b8c  8bcf                               mov    ecx,edi
00549b8e  e82d6afeff                         call   0x5305c0
00549b93  8b5c2424                           mov    ebx,DWORD PTR [esp+0x24]
00549b97  0fb77604                           movzx  esi,WORD PTR [esi+0x4]
00549b9b  03d8                               add    ebx,eax
00549b9d  e80eb3f3ff                         call   0x484eb0
00549ba2  50                                 push   eax
00549ba3  8bc6                               mov    eax,esi
00549ba5  8bcf                               mov    ecx,edi
00549ba7  e8a46afeff                         call   0x530650
00549bac  01442414                           add    DWORD PTR [esp+0x14],eax
00549bb0  8b7508                             mov    esi,DWORD PTR [ebp+0x8]
00549bb3  8b4650                             mov    eax,DWORD PTR [esi+0x50]
00549bb6  8b88c8030000                       mov    ecx,DWORD PTR [eax+0x3c8]
00549bbc  034c2410                           add    ecx,DWORD PTR [esp+0x10]
00549bc0  7876                               js     0x549c38
00549bc2  8b90cc030000                       mov    edx,DWORD PTR [eax+0x3cc]
00549bc8  03d3                               add    edx,ebx
00549bca  786c                               js     0x549c38
00549bcc  8b80d0030000                       mov    eax,DWORD PTR [eax+0x3d0]
00549bd2  03442414                           add    eax,DWORD PTR [esp+0x14]
00549bd6  7860                               js     0x549c38
00549bd8  8b4660                             mov    eax,DWORD PTR [esi+0x60]
00549bdb  8b15a4a7fb00                       mov    edx,DWORD PTR ds:0xfba7a4
00549be1  8d0c40                             lea    ecx,[eax+eax*2]
00549be4  8b548a10                           mov    edx,DWORD PTR [edx+ecx*4+0x10]
00549be8  8b442428                           mov    eax,DWORD PTR [esp+0x28]
00549bec  33c9                               xor    ecx,ecx
00549bee  384802                             cmp    BYTE PTR [eax+0x2],cl
00549bf1  0f95c1                             setne  cl
00549bf4  8a0401                             mov    al,BYTE PTR [ecx+eax*1]
00549bf7  8b4d10                             mov    ecx,DWORD PTR [ebp+0x10]
00549bfa  88442428                           mov    BYTE PTR [esp+0x28],al
00549bfe  e81df1ffff                         call   0x548d20
00549c03  8b7d0c                             mov    edi,DWORD PTR [ebp+0xc]
00549c06  8b4c2428                           mov    ecx,DWORD PTR [esp+0x28]
00549c0a  57                                 push   edi
00549c0b  51                                 push   ecx
00549c0c  8bca                               mov    ecx,edx
00549c0e  e85d560000                         call   0x54f270
00549c13  85c0                               test   eax,eax
00549c15  7421                               je     0x549c38
00549c17  837d1400                           cmp    DWORD PTR [ebp+0x14],0x0
00549c1b  c744241801000000                   mov    DWORD PTR [esp+0x18],0x1
00549c23  7413                               je     0x549c38
00549c25  8b5650                             mov    edx,DWORD PTR [esi+0x50]
00549c28  39bae8030000                       cmp    DWORD PTR [edx+0x3e8],edi
00549c2e  7408                               je     0x549c38
00549c30  c744241800000000                   mov    DWORD PTR [esp+0x18],0x0
00549c38  8b442418                           mov    eax,DWORD PTR [esp+0x18]
00549c3c  8b4c2430                           mov    ecx,DWORD PTR [esp+0x30]
00549c40  64890d00000000                     mov    DWORD PTR fs:0x0,ecx
00549c47  59                                 pop    ecx
00549c48  5f                                 pop    edi
00549c49  5e                                 pop    esi
00549c4a  5b                                 pop    ebx
00549c4b  8be5                               mov    esp,ebp
00549c4d  5d                                 pop    ebp
00549c4e  c21000                             ret    0x10
; native_skill_condition [0x54ae70,0x54ae92) 完整；SubAI::CSkillCheckCondition v+4 bool
0054ae70  55                                 push   ebp
0054ae71  8bec                               mov    ebp,esp
0054ae73  8b410c                             mov    eax,DWORD PTR [ecx+0xc]
0054ae76  8b5108                             mov    edx,DWORD PTR [ecx+0x8]
0054ae79  50                                 push   eax
0054ae7a  8b4104                             mov    eax,DWORD PTR [ecx+0x4]
0054ae7d  8b4d08                             mov    ecx,DWORD PTR [ebp+0x8]
0054ae80  52                                 push   edx
0054ae81  50                                 push   eax
0054ae82  51                                 push   ecx
0054ae83  e8f8eaffff                         call   0x549980
0054ae88  f7d8                               neg    eax
0054ae8a  1bc0                               sbb    eax,eax
0054ae8c  f7d8                               neg    eax
0054ae8e  5d                                 pop    ebp
0054ae8f  c20400                             ret    0x4
; skill_cost_parser [0x530890,0x5316c3) 完整機械解碼；語意僅 hp/sp/mp 欄位到16-byte level record與容器+60；不宣稱完整技能格式
00530890  55                                 push   ebp
00530891  8bec                               mov    ebp,esp
00530893  6aff                               push   0xffffffff
00530895  68fd359200                         push   0x9235fd
0053089a  64a100000000                       mov    eax,fs:0x0
005308a0  50                                 push   eax
005308a1  81ec48010000                       sub    esp,0x148
005308a7  a1201fd600                         mov    eax,ds:0xd61f20
005308ac  33c5                               xor    eax,ebp
005308ae  8945ec                             mov    DWORD PTR [ebp-0x14],eax
005308b1  53                                 push   ebx
005308b2  56                                 push   esi
005308b3  57                                 push   edi
005308b4  50                                 push   eax
005308b5  8d45f4                             lea    eax,[ebp-0xc]
005308b8  64a300000000                       mov    fs:0x0,eax
005308be  8b4508                             mov    eax,DWORD PTR [ebp+0x8]
005308c1  8d8d04ffffff                       lea    ecx,[ebp-0xfc]
005308c7  51                                 push   ecx
005308c8  b9d0efc000                         mov    ecx,0xc0efd0
005308cd  8985c0feffff                       mov    DWORD PTR [ebp-0x140],eax
005308d3  e858e51f00                         call   0x72ee30
005308d8  33ff                               xor    edi,edi
005308da  897dfc                             mov    DWORD PTR [ebp-0x4],edi
005308dd  8b8d24ffffff                       mov    ecx,DWORD PTR [ebp-0xdc]
005308e3  bb10000000                         mov    ebx,0x10
005308e8  399d38ffffff                       cmp    DWORD PTR [ebp-0xc8],ebx
005308ee  7306                               jae    0x5308f6
005308f0  8d8d24ffffff                       lea    ecx,[ebp-0xdc]
005308f6  57                                 push   edi
005308f7  8db504ffffff                       lea    esi,[ebp-0xfc]
005308fd  e80ee81f00                         call   0x72f110
00530902  80bd48ffffff00                     cmp    BYTE PTR [ebp-0xb8],0x0
00530909  7451                               je     0x53095c
0053090b  c745fcffffffff                     mov    DWORD PTR [ebp-0x4],0xffffffff
00530912  c78504ffffff9423bf00               mov    DWORD PTR [ebp-0xfc],0xbf2394
0053091c  399d64ffffff                       cmp    DWORD PTR [ebp-0x9c],ebx
00530922  720f                               jb     0x530933
00530924  8b9550ffffff                       mov    edx,DWORD PTR [ebp-0xb0]
0053092a  52                                 push   edx
0053092b  e8dc083600                         call   0x89120c
00530930  83c404                             add    esp,0x4
00530933  8d8d04ffffff                       lea    ecx,[ebp-0xfc]
00530939  c78564ffffff0f000000               mov    DWORD PTR [ebp-0x9c],0xf
00530943  89bd60ffffff                       mov    DWORD PTR [ebp-0xa0],edi
00530949  c68550ffffff00                     mov    BYTE PTR [ebp-0xb0],0x0
00530950  e8ebd61f00                         call   0x72e040
00530955  33c0                               xor    eax,eax
00530957  e93f0d0000                         jmp    0x53169b
0053095c  681cf0c000                         push   0xc0f01c
00530961  8d8504ffffff                       lea    eax,[ebp-0xfc]
00530967  e874d91f00                         call   0x72e2e0
0053096c  3bc7                               cmp    eax,edi
0053096e  7522                               jne    0x530992
00530970  c745fcffffffff                     mov    DWORD PTR [ebp-0x4],0xffffffff
00530977  c78504ffffff9423bf00               mov    DWORD PTR [ebp-0xfc],0xbf2394
00530981  399d64ffffff                       cmp    DWORD PTR [ebp-0x9c],ebx
00530987  72aa                               jb     0x530933
00530989  8b8550ffffff                       mov    eax,DWORD PTR [ebp-0xb0]
0053098f  50                                 push   eax
00530990  eb99                               jmp    0x53092b
00530992  b907000000                         mov    ecx,0x7
00530997  33d2                               xor    edx,edx
00530999  894dd4                             mov    DWORD PTR [ebp-0x2c],ecx
0053099c  897dd0                             mov    DWORD PTR [ebp-0x30],edi
0053099f  668955c0                           mov    WORD PTR [ebp-0x40],dx
005309a3  894db8                             mov    DWORD PTR [ebp-0x48],ecx
005309a6  33c9                               xor    ecx,ecx
005309a8  897db4                             mov    DWORD PTR [ebp-0x4c],edi
005309ab  66894da4                           mov    WORD PTR [ebp-0x5c],cx
005309af  c645fc02                           mov    BYTE PTR [ebp-0x4],0x2
005309b3  8b4018                             mov    eax,DWORD PTR [eax+0x18]
005309b6  8955e4                             mov    DWORD PTR [ebp-0x1c],edx
005309b9  8955e8                             mov    DWORD PTR [ebp-0x18],edx
005309bc  8985d0feffff                       mov    DWORD PTR [ebp-0x130],eax
005309c2  3bc7                               cmp    eax,edi
005309c4  0f846f0c0000                       je     0x531639
005309ca  8d9b00000000                       lea    ebx,[ebx+0x0]
005309d0  8b8dd0feffff                       mov    ecx,DWORD PTR [ebp-0x130]
005309d6  8b11                               mov    edx,DWORD PTR [ecx]
005309d8  8b4214                             mov    eax,DWORD PTR [edx+0x14]
005309db  ffd0                               call   eax
005309dd  8d7844                             lea    edi,[eax+0x44]
005309e0  685cafbf00                         push   0xbfaf5c
005309e5  8985d8feffff                       mov    DWORD PTR [ebp-0x128],eax
005309eb  e8b0f61f00                         call   0x7300a0
005309f0  33db                               xor    ebx,ebx
005309f2  8d7310                             lea    esi,[ebx+0x10]
005309f5  3bc3                               cmp    eax,ebx
005309f7  741f                               je     0x530a18
005309f9  83c030                             add    eax,0x30
005309fc  397014                             cmp    DWORD PTR [eax+0x14],esi
005309ff  7202                               jb     0x530a03
00530a01  8b00                               mov    eax,DWORD PTR [eax]
00530a03  3bc3                               cmp    eax,ebx
00530a05  7411                               je     0x530a18
00530a07  50                                 push   eax
00530a08  e8a70d3600                         call   0x8917b4
00530a0d  83c404                             add    esp,0x4
00530a10  8985ccfeffff                       mov    DWORD PTR [ebp-0x134],eax
00530a16  eb06                               jmp    0x530a1e
00530a18  899dccfeffff                       mov    DWORD PTR [ebp-0x134],ebx
00530a1e  6830f0c000                         push   0xc0f030
00530a23  e878f61f00                         call   0x7300a0
00530a28  3bc3                               cmp    eax,ebx
00530a2a  741f                               je     0x530a4b
00530a2c  83c030                             add    eax,0x30
00530a2f  397014                             cmp    DWORD PTR [eax+0x14],esi
00530a32  7202                               jb     0x530a36
00530a34  8b00                               mov    eax,DWORD PTR [eax]
00530a36  3bc3                               cmp    eax,ebx
00530a38  7411                               je     0x530a4b
00530a3a  50                                 push   eax
00530a3b  e8740d3600                         call   0x8917b4
00530a40  83c404                             add    esp,0x4
00530a43  8985e0feffff                       mov    DWORD PTR [ebp-0x120],eax
00530a49  eb06                               jmp    0x530a51
00530a4b  899de0feffff                       mov    DWORD PTR [ebp-0x120],ebx
00530a51  6838f0c000                         push   0xc0f038
00530a56  e845f61f00                         call   0x7300a0
00530a5b  3bc3                               cmp    eax,ebx
00530a5d  741f                               je     0x530a7e
00530a5f  83c030                             add    eax,0x30
00530a62  397014                             cmp    DWORD PTR [eax+0x14],esi
00530a65  7202                               jb     0x530a69
00530a67  8b00                               mov    eax,DWORD PTR [eax]
00530a69  3bc3                               cmp    eax,ebx
00530a6b  7411                               je     0x530a7e
00530a6d  50                                 push   eax
00530a6e  e8410d3600                         call   0x8917b4
00530a73  83c404                             add    esp,0x4
00530a76  8985d4feffff                       mov    DWORD PTR [ebp-0x12c],eax
00530a7c  eb06                               jmp    0x530a84
00530a7e  899dd4feffff                       mov    DWORD PTR [ebp-0x12c],ebx
00530a84  6838eac000                         push   0xc0ea38
00530a89  e812f61f00                         call   0x7300a0
00530a8e  3bc3                               cmp    eax,ebx
00530a90  7417                               je     0x530aa9
00530a92  83c030                             add    eax,0x30
00530a95  397014                             cmp    DWORD PTR [eax+0x14],esi
00530a98  7202                               jb     0x530a9c
00530a9a  8b00                               mov    eax,DWORD PTR [eax]
00530a9c  3bc3                               cmp    eax,ebx
00530a9e  7409                               je     0x530aa9
00530aa0  50                                 push   eax
00530aa1  e80e0d3600                         call   0x8917b4
00530aa6  83c404                             add    esp,0x4
00530aa9  6808b8bf00                         push   0xbfb808
00530aae  e8edf51f00                         call   0x7300a0
00530ab3  3bc3                               cmp    eax,ebx
00530ab5  741f                               je     0x530ad6
00530ab7  83c030                             add    eax,0x30
00530aba  397014                             cmp    DWORD PTR [eax+0x14],esi
00530abd  7202                               jb     0x530ac1
00530abf  8b00                               mov    eax,DWORD PTR [eax]
00530ac1  3bc3                               cmp    eax,ebx
00530ac3  7411                               je     0x530ad6
00530ac5  50                                 push   eax
00530ac6  e8e90c3600                         call   0x8917b4
00530acb  83c404                             add    esp,0x4
00530ace  8985dcfeffff                       mov    DWORD PTR [ebp-0x124],eax
00530ad4  eb06                               jmp    0x530adc
00530ad6  899ddcfeffff                       mov    DWORD PTR [ebp-0x124],ebx
00530adc  683cf0c000                         push   0xc0f03c
00530ae1  e8baf51f00                         call   0x7300a0
00530ae6  3bc3                               cmp    eax,ebx
00530ae8  741f                               je     0x530b09
00530aea  83c030                             add    eax,0x30
00530aed  397014                             cmp    DWORD PTR [eax+0x14],esi
00530af0  7202                               jb     0x530af4
00530af2  8b00                               mov    eax,DWORD PTR [eax]
00530af4  3bc3                               cmp    eax,ebx
00530af6  7411                               je     0x530b09
00530af8  50                                 push   eax
00530af9  e8b60c3600                         call   0x8917b4
00530afe  83c404                             add    esp,0x4
00530b01  8985c4feffff                       mov    DWORD PTR [ebp-0x13c],eax
00530b07  eb06                               jmp    0x530b0f
00530b09  899dc4feffff                       mov    DWORD PTR [ebp-0x13c],ebx
00530b0f  6838e0c000                         push   0xc0e038
00530b14  e887f51f00                         call   0x7300a0
00530b19  3bc3                               cmp    eax,ebx
00530b1b  741f                               je     0x530b3c
00530b1d  83c030                             add    eax,0x30
00530b20  397014                             cmp    DWORD PTR [eax+0x14],esi
00530b23  7202                               jb     0x530b27
00530b25  8b00                               mov    eax,DWORD PTR [eax]
00530b27  3bc3                               cmp    eax,ebx
00530b29  7411                               je     0x530b3c
00530b2b  50                                 push   eax
00530b2c  e8830c3600                         call   0x8917b4
00530b31  83c404                             add    esp,0x4
00530b34  8985c8feffff                       mov    DWORD PTR [ebp-0x138],eax
00530b3a  eb06                               jmp    0x530b42
00530b3c  899dc8feffff                       mov    DWORD PTR [ebp-0x138],ebx
00530b42  6844f0c000                         push   0xc0f044
00530b47  e854f51f00                         call   0x7300a0
00530b4c  3bc3                               cmp    eax,ebx
00530b4e  741f                               je     0x530b6f
00530b50  83c030                             add    eax,0x30
00530b53  397014                             cmp    DWORD PTR [eax+0x14],esi
00530b56  7202                               jb     0x530b5a
00530b58  8b00                               mov    eax,DWORD PTR [eax]
00530b5a  3bc3                               cmp    eax,ebx
00530b5c  7411                               je     0x530b6f
00530b5e  50                                 push   eax
00530b5f  e8500c3600                         call   0x8917b4
00530b64  83c404                             add    esp,0x4
00530b67  8985e4feffff                       mov    DWORD PTR [ebp-0x11c],eax
00530b6d  eb06                               jmp    0x530b75
00530b6f  899de4feffff                       mov    DWORD PTR [ebp-0x11c],ebx
00530b75  6850f0c000                         push   0xc0f050
00530b7a  e821f51f00                         call   0x7300a0
00530b7f  3bc3                               cmp    eax,ebx
00530b81  741b                               je     0x530b9e
00530b83  83c030                             add    eax,0x30
00530b86  397014                             cmp    DWORD PTR [eax+0x14],esi
00530b89  7202                               jb     0x530b8d
00530b8b  8b00                               mov    eax,DWORD PTR [eax]
00530b8d  3bc3                               cmp    eax,ebx
00530b8f  740d                               je     0x530b9e
00530b91  50                                 push   eax
00530b92  e81d0c3600                         call   0x8917b4
00530b97  83c404                             add    esp,0x4
00530b9a  8bf8                               mov    edi,eax
00530b9c  eb02                               jmp    0x530ba0
00530b9e  33ff                               xor    edi,edi
00530ba0  6a04                               push   0x4
00530ba2  bb0f000000                         mov    ebx,0xf
00530ba7  68d4d1be00                         push   0xbed1d4
00530bac  8d8d7cffffff                       lea    ecx,[ebp-0x84]
00530bb2  895d90                             mov    DWORD PTR [ebp-0x70],ebx
00530bb5  c7458c00000000                     mov    DWORD PTR [ebp-0x74],0x0
00530bbc  c6857cffffff00                     mov    BYTE PTR [ebp-0x84],0x0
00530bc3  e8a81eedff                         call   0x402a70
00530bc8  c645fc03                           mov    BYTE PTR [ebp-0x4],0x3
00530bcc  8b8dd8feffff                       mov    ecx,DWORD PTR [ebp-0x128]
00530bd2  687523bf00                         push   0xbf2375
00530bd7  8d857cffffff                       lea    eax,[ebp-0x84]
00530bdd  8db5e8feffff                       lea    esi,[ebp-0x118]
00530be3  e808e11f00                         call   0x72ecf0
00530be8  50                                 push   eax
00530be9  8d45c0                             lea    eax,[ebp-0x40]
00530bec  c645fc04                           mov    BYTE PTR [ebp-0x4],0x4
00530bf0  e83bf5f0ff                         call   0x440130
00530bf5  83c404                             add    esp,0x4
00530bf8  83bdfcfeffff10                     cmp    DWORD PTR [ebp-0x104],0x10
00530bff  720f                               jb     0x530c10
00530c01  8b8de8feffff                       mov    ecx,DWORD PTR [ebp-0x118]
00530c07  51                                 push   ecx
00530c08  e8ff053600                         call   0x89120c
00530c0d  83c404                             add    esp,0x4
00530c10  c645fc02                           mov    BYTE PTR [ebp-0x4],0x2
00530c14  837d9010                           cmp    DWORD PTR [ebp-0x70],0x10
00530c18  899dfcfeffff                       mov    DWORD PTR [ebp-0x104],ebx
00530c1e  c785f8feffff00000000               mov    DWORD PTR [ebp-0x108],0x0
00530c28  c685e8feffff00                     mov    BYTE PTR [ebp-0x118],0x0
00530c2f  720f                               jb     0x530c40
00530c31  8b957cffffff                       mov    edx,DWORD PTR [ebp-0x84]
00530c37  52                                 push   edx
00530c38  e8cf053600                         call   0x89120c
00530c3d  83c404                             add    esp,0x4
00530c40  8b85dcfeffff                       mov    eax,DWORD PTR [ebp-0x124]
00530c46  48                                 dec    eax
00530c47  83f809                             cmp    eax,0x9
00530c4a  0f879a000000                       ja     0x530cea
00530c50  0fb680cc165300                     movzx  eax,BYTE PTR [eax+0x5316cc]
00530c57  ff2485c4165300                     jmp    DWORD PTR [eax*4+0x5316c4]
00530c5e  688c000000                         push   0x8c
00530c63  e800063600                         call   0x891268
00530c68  8bf0                               mov    esi,eax
00530c6a  83c404                             add    esp,0x4
00530c6d  89b5d8feffff                       mov    DWORD PTR [ebp-0x128],esi
00530c73  c645fc05                           mov    BYTE PTR [ebp-0x4],0x5
00530c77  85f6                               test   esi,esi
00530c79  7465                               je     0x530ce0
00530c7b  837dd408                           cmp    DWORD PTR [ebp-0x2c],0x8
00530c7f  8b55c0                             mov    edx,DWORD PTR [ebp-0x40]
00530c82  7303                               jae    0x530c87
00530c84  8d55c0                             lea    edx,[ebp-0x40]
00530c87  8b8de0feffff                       mov    ecx,DWORD PTR [ebp-0x120]
00530c8d  8b85d4feffff                       mov    eax,DWORD PTR [ebp-0x12c]
00530c93  51                                 push   ecx
00530c94  8b8de4feffff                       mov    ecx,DWORD PTR [ebp-0x11c]
00530c9a  50                                 push   eax
00530c9b  8b85dcfeffff                       mov    eax,DWORD PTR [ebp-0x124]
00530ca1  57                                 push   edi
00530ca2  51                                 push   ecx
00530ca3  50                                 push   eax
00530ca4  8b85ccfeffff                       mov    eax,DWORD PTR [ebp-0x134]
00530caa  e801eaffff                         call   0x52f6b0
00530caf  668b8dc4feffff                     mov    cx,WORD PTR [ebp-0x13c]
00530cb6  668b95c8feffff                     mov    dx,WORD PTR [ebp-0x138]
00530cbd  c70618f1c000                       mov    DWORD PTR [esi],0xc0f118
00530cc3  c7464c20f1c000                     mov    DWORD PTR [esi+0x4c],0xc0f120
00530cca  66898e88000000                     mov    WORD PTR [esi+0x88],cx
00530cd1  6689968a000000                     mov    WORD PTR [esi+0x8a],dx
00530cd8  89b5dcfeffff                       mov    DWORD PTR [ebp-0x124],esi
00530cde  eb65                               jmp    0x530d45
00530ce0  33f6                               xor    esi,esi
00530ce2  89b5dcfeffff                       mov    DWORD PTR [ebp-0x124],esi
00530ce8  eb5b                               jmp    0x530d45
00530cea  6888000000                         push   0x88
00530cef  e874053600                         call   0x891268
00530cf4  8bf0                               mov    esi,eax
00530cf6  83c404                             add    esp,0x4
00530cf9  89b5d8feffff                       mov    DWORD PTR [ebp-0x128],esi
00530cff  c645fc06                           mov    BYTE PTR [ebp-0x4],0x6
00530d03  85f6                               test   esi,esi
00530d05  7436                               je     0x530d3d
00530d07  837dd408                           cmp    DWORD PTR [ebp-0x2c],0x8
00530d0b  8b55c0                             mov    edx,DWORD PTR [ebp-0x40]
00530d0e  7303                               jae    0x530d13
00530d10  8d55c0                             lea    edx,[ebp-0x40]
00530d13  8b85e0feffff                       mov    eax,DWORD PTR [ebp-0x120]
00530d19  8b8dd4feffff                       mov    ecx,DWORD PTR [ebp-0x12c]
00530d1f  50                                 push   eax
00530d20  8b85e4feffff                       mov    eax,DWORD PTR [ebp-0x11c]
00530d26  51                                 push   ecx
00530d27  8b8ddcfeffff                       mov    ecx,DWORD PTR [ebp-0x124]
00530d2d  57                                 push   edi
00530d2e  50                                 push   eax
00530d2f  8b85ccfeffff                       mov    eax,DWORD PTR [ebp-0x134]
00530d35  51                                 push   ecx
00530d36  e875e9ffff                         call   0x52f6b0
00530d3b  eb02                               jmp    0x530d3f
00530d3d  33c0                               xor    eax,eax
00530d3f  8985dcfeffff                       mov    DWORD PTR [ebp-0x124],eax
00530d45  8b85d0feffff                       mov    eax,DWORD PTR [ebp-0x130]
00530d4b  685cecc000                         push   0xc0ec5c
00530d50  c645fc02                           mov    BYTE PTR [ebp-0x4],0x2
00530d54  e887d51f00                         call   0x72e2e0
00530d59  85c0                               test   eax,eax
00530d5b  0f840d010000                       je     0x530e6e
00530d61  8b4018                             mov    eax,DWORD PTR [eax+0x18]
00530d64  8985d4feffff                       mov    DWORD PTR [ebp-0x12c],eax
00530d6a  85c0                               test   eax,eax
00530d6c  0f84fc000000                       je     0x530e6e
00530d72  8bbddcfeffff                       mov    edi,DWORD PTR [ebp-0x124]
00530d78  eb06                               jmp    0x530d80
00530d7a  8d9b00000000                       lea    ebx,[ebx+0x0]
00530d80  8b8dd4feffff                       mov    ecx,DWORD PTR [ebp-0x12c]
00530d86  8b11                               mov    edx,DWORD PTR [ecx]
00530d88  8b4214                             mov    eax,DWORD PTR [edx+0x14]
00530d8b  ffd0                               call   eax
00530d8d  8bb094000000                       mov    esi,DWORD PTR [eax+0x94]
00530d93  8d5844                             lea    ebx,[eax+0x44]
00530d96  3bf3                               cmp    esi,ebx
00530d98  742a                               je     0x530dc4
00530d9a  8d9b00000000                       lea    ebx,[ebx+0x0]
00530da0  837e2810                           cmp    DWORD PTR [esi+0x28],0x10
00530da4  8d4614                             lea    eax,[esi+0x14]
00530da7  7202                               jb     0x530dab
00530da9  8b00                               mov    eax,DWORD PTR [eax]
00530dab  685cafbf00                         push   0xbfaf5c
00530db0  50                                 push   eax
00530db1  e8fb2e3600                         call   0x893cb1
00530db6  83c408                             add    esp,0x8
00530db9  85c0                               test   eax,eax
00530dbb  7458                               je     0x530e15
00530dbd  8b7650                             mov    esi,DWORD PTR [esi+0x50]
00530dc0  3bf3                               cmp    esi,ebx
00530dc2  75dc                               jne    0x530da0
00530dc4  33f6                               xor    esi,esi
00530dc6  8b477c                             mov    eax,DWORD PTR [edi+0x7c]
00530dc9  8d8de4feffff                       lea    ecx,[ebp-0x11c]
00530dcf  89b5e4feffff                       mov    DWORD PTR [ebp-0x11c],esi
00530dd5  3bc8                               cmp    ecx,eax
00530dd7  735c                               jae    0x530e35
00530dd9  8b4f78                             mov    ecx,DWORD PTR [edi+0x78]
00530ddc  8d95e4feffff                       lea    edx,[ebp-0x11c]
00530de2  3bca                               cmp    ecx,edx
00530de4  774f                               ja     0x530e35
00530de6  8bf2                               mov    esi,edx
00530de8  2bf1                               sub    esi,ecx
00530dea  c1fe02                             sar    esi,0x2
00530ded  3b8780000000                       cmp    eax,DWORD PTR [edi+0x80]
00530df3  750d                               jne    0x530e02
00530df5  b901000000                         mov    ecx,0x1
00530dfa  8d4778                             lea    eax,[edi+0x78]
00530dfd  e83e541a00                         call   0x6d6240
00530e02  8b4778                             mov    eax,DWORD PTR [edi+0x78]
00530e05  8d0cb0                             lea    ecx,[eax+esi*4]
00530e08  8b477c                             mov    eax,DWORD PTR [edi+0x7c]
00530e0b  85c0                               test   eax,eax
00530e0d  7444                               je     0x530e53
00530e0f  8b09                               mov    ecx,DWORD PTR [ecx]
00530e11  8908                               mov    DWORD PTR [eax],ecx
00530e13  eb3e                               jmp    0x530e53
00530e15  85f6                               test   esi,esi
00530e17  74ab                               je     0x530dc4
00530e19  837e4410                           cmp    DWORD PTR [esi+0x44],0x10
00530e1d  8d4630                             lea    eax,[esi+0x30]
00530e20  7202                               jb     0x530e24
00530e22  8b00                               mov    eax,DWORD PTR [eax]
00530e24  85c0                               test   eax,eax
00530e26  749c                               je     0x530dc4
00530e28  50                                 push   eax
00530e29  e886093600                         call   0x8917b4
00530e2e  83c404                             add    esp,0x4
00530e31  8bf0                               mov    esi,eax
00530e33  eb91                               jmp    0x530dc6
00530e35  3b8780000000                       cmp    eax,DWORD PTR [edi+0x80]
00530e3b  750d                               jne    0x530e4a
00530e3d  b901000000                         mov    ecx,0x1
00530e42  8d4778                             lea    eax,[edi+0x78]
00530e45  e8f6531a00                         call   0x6d6240
00530e4a  8b477c                             mov    eax,DWORD PTR [edi+0x7c]
00530e4d  85c0                               test   eax,eax
00530e4f  7402                               je     0x530e53
00530e51  8930                               mov    DWORD PTR [eax],esi
00530e53  8b95d4feffff                       mov    edx,DWORD PTR [ebp-0x12c]
00530e59  83477c04                           add    DWORD PTR [edi+0x7c],0x4
00530e5d  8b4240                             mov    eax,DWORD PTR [edx+0x40]
00530e60  8985d4feffff                       mov    DWORD PTR [ebp-0x12c],eax
00530e66  85c0                               test   eax,eax
00530e68  0f8512ffffff                       jne    0x530d80
00530e6e  8b85d0feffff                       mov    eax,DWORD PTR [ebp-0x130]
00530e74  8b7018                             mov    esi,DWORD PTR [eax+0x18]
00530e77  85f6                               test   esi,esi
00530e79  7428                               je     0x530ea3
00530e7b  bf10000000                         mov    edi,0x10
00530e80  397e34                             cmp    DWORD PTR [esi+0x34],edi
00530e83  8d4620                             lea    eax,[esi+0x20]
00530e86  7202                               jb     0x530e8a
00530e88  8b00                               mov    eax,DWORD PTR [eax]
00530e8a  68fccfbf00                         push   0xbfcffc
00530e8f  50                                 push   eax
00530e90  e81c2e3600                         call   0x893cb1
00530e95  83c408                             add    esp,0x8
00530e98  85c0                               test   eax,eax
00530e9a  7409                               je     0x530ea5
00530e9c  8b7640                             mov    esi,DWORD PTR [esi+0x40]
00530e9f  85f6                               test   esi,esi
00530ea1  75dd                               jne    0x530e80
00530ea3  33f6                               xor    esi,esi
00530ea5  89b5e0feffff                       mov    DWORD PTR [ebp-0x120],esi
00530eab  85f6                               test   esi,esi
00530ead  0f84b3060000                       je     0x531566
00530eb3  8b85dcfeffff                       mov    eax,DWORD PTR [ebp-0x124]
00530eb9  8d4850                             lea    ecx,[eax+0x50]
00530ebc  83c060                             add    eax,0x60
00530ebf  898dd8feffff                       mov    DWORD PTR [ebp-0x128],ecx
00530ec5  8985e4feffff                       mov    DWORD PTR [ebp-0x11c],eax
00530ecb  bb10000000                         mov    ebx,0x10
00530ed0  8bb5e0feffff                       mov    esi,DWORD PTR [ebp-0x120]
00530ed6  8b16                               mov    edx,DWORD PTR [esi]
00530ed8  8b4214                             mov    eax,DWORD PTR [edx+0x14]
00530edb  8bce                               mov    ecx,esi
00530edd  ffd0                               call   eax
00530edf  33c9                               xor    ecx,ecx
00530ee1  33c0                               xor    eax,eax
00530ee3  33d2                               xor    edx,edx
00530ee5  837db808                           cmp    DWORD PTR [ebp-0x48],0x8
00530ee9  8945e0                             mov    DWORD PTR [ebp-0x20],eax
00530eec  8b45a4                             mov    eax,DWORD PTR [ebp-0x5c]
00530eef  894ddc                             mov    DWORD PTR [ebp-0x24],ecx
00530ef2  8955e4                             mov    DWORD PTR [ebp-0x1c],edx
00530ef5  894de8                             mov    DWORD PTR [ebp-0x18],ecx
00530ef8  894d98                             mov    DWORD PTR [ebp-0x68],ecx
00530efb  894d9c                             mov    DWORD PTR [ebp-0x64],ecx
00530efe  894da0                             mov    DWORD PTR [ebp-0x60],ecx
00530f01  894db4                             mov    DWORD PTR [ebp-0x4c],ecx
00530f04  7303                               jae    0x530f09
00530f06  8d45a4                             lea    eax,[ebp-0x5c]
00530f09  33d2                               xor    edx,edx
00530f0b  668910                             mov    WORD PTR [eax],dx
00530f0e  8b7618                             mov    esi,DWORD PTR [esi+0x18]
00530f11  3bf1                               cmp    esi,ecx
00530f13  0f84ea000000                       je     0x531003
00530f19  8da42400000000                     lea    esp,[esp+0x0]
00530f20  395e34                             cmp    DWORD PTR [esi+0x34],ebx
00530f23  8d4620                             lea    eax,[esi+0x20]
00530f26  7202                               jb     0x530f2a
00530f28  8b00                               mov    eax,DWORD PTR [eax]
00530f2a  685cf0c000                         push   0xc0f05c
00530f2f  50                                 push   eax
00530f30  e87c2d3600                         call   0x893cb1
00530f35  83c408                             add    esp,0x8
00530f38  85c0                               test   eax,eax
00530f3a  740c                               je     0x530f48
00530f3c  8b7640                             mov    esi,DWORD PTR [esi+0x40]
00530f3f  85f6                               test   esi,esi
00530f41  75dd                               jne    0x530f20
00530f43  e9bb000000                         jmp    0x531003
00530f48  85f6                               test   esi,esi
00530f4a  0f84b3000000                       je     0x531003
00530f50  8b06                               mov    eax,DWORD PTR [esi]
00530f52  8b5014                             mov    edx,DWORD PTR [eax+0x14]
00530f55  8bce                               mov    ecx,esi
00530f57  ffd2                               call   edx
00530f59  8bb094000000                       mov    esi,DWORD PTR [eax+0x94]
00530f5f  8d7844                             lea    edi,[eax+0x44]
00530f62  3bf7                               cmp    esi,edi
00530f64  7427                               je     0x530f8d
00530f66  395e28                             cmp    DWORD PTR [esi+0x28],ebx
00530f69  8d4614                             lea    eax,[esi+0x14]
00530f6c  7202                               jb     0x530f70
00530f6e  8b00                               mov    eax,DWORD PTR [eax]
00530f70  686cf0c000                         push   0xc0f06c
00530f75  50                                 push   eax
00530f76  e8362d3600                         call   0x893cb1
00530f7b  83c408                             add    esp,0x8
00530f7e  85c0                               test   eax,eax
00530f80  0f84ba000000                       je     0x531040
00530f86  8b7650                             mov    esi,DWORD PTR [esi+0x50]
00530f89  3bf7                               cmp    esi,edi
00530f8b  75d9                               jne    0x530f66
00530f8d  c7459800000000                     mov    DWORD PTR [ebp-0x68],0x0
00530f94  8b7750                             mov    esi,DWORD PTR [edi+0x50]
00530f97  3bf7                               cmp    esi,edi
00530f99  742c                               je     0x530fc7
00530f9b  eb03                               jmp    0x530fa0
00530f9d  8d4900                             lea    ecx,[ecx+0x0]
00530fa0  395e28                             cmp    DWORD PTR [esi+0x28],ebx
00530fa3  8d4614                             lea    eax,[esi+0x14]
00530fa6  7202                               jb     0x530faa
00530fa8  8b00                               mov    eax,DWORD PTR [eax]
00530faa  6878f0c000                         push   0xc0f078
00530faf  50                                 push   eax
00530fb0  e8fc2c3600                         call   0x893cb1
00530fb5  83c408                             add    esp,0x8
00530fb8  85c0                               test   eax,eax
00530fba  0f84ab000000                       je     0x53106b
00530fc0  8b7650                             mov    esi,DWORD PTR [esi+0x50]
00530fc3  3bf7                               cmp    esi,edi
00530fc5  75d9                               jne    0x530fa0
00530fc7  c7459c00000000                     mov    DWORD PTR [ebp-0x64],0x0
00530fce  8b7750                             mov    esi,DWORD PTR [edi+0x50]
00530fd1  3bf7                               cmp    esi,edi
00530fd3  7427                               je     0x530ffc
00530fd5  395e28                             cmp    DWORD PTR [esi+0x28],ebx
00530fd8  8d4614                             lea    eax,[esi+0x14]
00530fdb  7202                               jb     0x530fdf
00530fdd  8b00                               mov    eax,DWORD PTR [eax]
00530fdf  6884f0c000                         push   0xc0f084
00530fe4  50                                 push   eax
00530fe5  e8c72c3600                         call   0x893cb1
00530fea  83c408                             add    esp,0x8
00530fed  85c0                               test   eax,eax
00530fef  0f84a1000000                       je     0x531096
00530ff5  8b7650                             mov    esi,DWORD PTR [esi+0x50]
00530ff8  3bf7                               cmp    esi,edi
00530ffa  75d9                               jne    0x530fd5
00530ffc  c745a000000000                     mov    DWORD PTR [ebp-0x60],0x0
00531003  8b85e0feffff                       mov    eax,DWORD PTR [ebp-0x120]
00531009  8b7018                             mov    esi,DWORD PTR [eax+0x18]
0053100c  85f6                               test   esi,esi
0053100e  0f8499010000                       je     0x5311ad
00531014  395e34                             cmp    DWORD PTR [esi+0x34],ebx
00531017  8d4620                             lea    eax,[esi+0x20]
0053101a  7202                               jb     0x53101e
0053101c  8b00                               mov    eax,DWORD PTR [eax]
0053101e  6890f0c000                         push   0xc0f090
00531023  50                                 push   eax
00531024  e8882c3600                         call   0x893cb1
00531029  83c408                             add    esp,0x8
0053102c  85c0                               test   eax,eax
0053102e  0f848d000000                       je     0x5310c1
00531034  8b7640                             mov    esi,DWORD PTR [esi+0x40]
00531037  85f6                               test   esi,esi
00531039  75d9                               jne    0x531014
0053103b  e96d010000                         jmp    0x5311ad
00531040  85f6                               test   esi,esi
00531042  0f8445ffffff                       je     0x530f8d
00531048  395e44                             cmp    DWORD PTR [esi+0x44],ebx
0053104b  8d4630                             lea    eax,[esi+0x30]
0053104e  7202                               jb     0x531052
00531050  8b00                               mov    eax,DWORD PTR [eax]
00531052  85c0                               test   eax,eax
00531054  0f8433ffffff                       je     0x530f8d
0053105a  50                                 push   eax
0053105b  e854073600                         call   0x8917b4
00531060  83c404                             add    esp,0x4
00531063  894598                             mov    DWORD PTR [ebp-0x68],eax
00531066  e929ffffff                         jmp    0x530f94
0053106b  85f6                               test   esi,esi
0053106d  0f8454ffffff                       je     0x530fc7
00531073  395e44                             cmp    DWORD PTR [esi+0x44],ebx
00531076  8d4630                             lea    eax,[esi+0x30]
00531079  7202                               jb     0x53107d
0053107b  8b00                               mov    eax,DWORD PTR [eax]
0053107d  85c0                               test   eax,eax
0053107f  0f8442ffffff                       je     0x530fc7
00531085  50                                 push   eax
00531086  e829073600                         call   0x8917b4
0053108b  83c404                             add    esp,0x4
0053108e  89459c                             mov    DWORD PTR [ebp-0x64],eax
00531091  e938ffffff                         jmp    0x530fce
00531096  85f6                               test   esi,esi
00531098  0f845effffff                       je     0x530ffc
0053109e  395e44                             cmp    DWORD PTR [esi+0x44],ebx
005310a1  8d4630                             lea    eax,[esi+0x30]
005310a4  7202                               jb     0x5310a8
005310a6  8b00                               mov    eax,DWORD PTR [eax]
005310a8  85c0                               test   eax,eax
005310aa  0f844cffffff                       je     0x530ffc
005310b0  50                                 push   eax
005310b1  e8fe063600                         call   0x8917b4
005310b6  83c404                             add    esp,0x4
005310b9  8945a0                             mov    DWORD PTR [ebp-0x60],eax
005310bc  e942ffffff                         jmp    0x531003
005310c1  85f6                               test   esi,esi
005310c3  0f84e4000000                       je     0x5311ad
005310c9  8b16                               mov    edx,DWORD PTR [esi]
005310cb  8b4214                             mov    eax,DWORD PTR [edx+0x14]
005310ce  8bce                               mov    ecx,esi
005310d0  ffd0                               call   eax
005310d2  8bb094000000                       mov    esi,DWORD PTR [eax+0x94]
005310d8  8d7844                             lea    edi,[eax+0x44]
005310db  3bf7                               cmp    esi,edi
005310dd  7428                               je     0x531107
005310df  90                                 nop
005310e0  395e28                             cmp    DWORD PTR [esi+0x28],ebx
005310e3  8d4614                             lea    eax,[esi+0x14]
005310e6  7202                               jb     0x5310ea
005310e8  8b00                               mov    eax,DWORD PTR [eax]
005310ea  689cf0c000                         push   0xc0f09c
005310ef  50                                 push   eax
005310f0  e8bc2b3600                         call   0x893cb1
005310f5  83c408                             add    esp,0x8
005310f8  85c0                               test   eax,eax
005310fa  0f842c020000                       je     0x53132c
00531100  8b7650                             mov    esi,DWORD PTR [esi+0x50]
00531103  3bf7                               cmp    esi,edi
00531105  75d9                               jne    0x5310e0
00531107  33c9                               xor    ecx,ecx
00531109  66894ddc                           mov    WORD PTR [ebp-0x24],cx
0053110d  8b7750                             mov    esi,DWORD PTR [edi+0x50]
00531110  3bf7                               cmp    esi,edi
00531112  7427                               je     0x53113b
00531114  395e28                             cmp    DWORD PTR [esi+0x28],ebx
00531117  8d4614                             lea    eax,[esi+0x14]
0053111a  7202                               jb     0x53111e
0053111c  8b00                               mov    eax,DWORD PTR [eax]
0053111e  68a0f0c000                         push   0xc0f0a0
00531123  50                                 push   eax
00531124  e8882b3600                         call   0x893cb1
00531129  83c408                             add    esp,0x8
0053112c  85c0                               test   eax,eax
0053112e  0f8424020000                       je     0x531358
00531134  8b7650                             mov    esi,DWORD PTR [esi+0x50]
00531137  3bf7                               cmp    esi,edi
00531139  75d9                               jne    0x531114
0053113b  33d2                               xor    edx,edx
0053113d  668955de                           mov    WORD PTR [ebp-0x22],dx
00531141  8b7750                             mov    esi,DWORD PTR [edi+0x50]
00531144  3bf7                               cmp    esi,edi
00531146  7427                               je     0x53116f
00531148  395e28                             cmp    DWORD PTR [esi+0x28],ebx
0053114b  8d4614                             lea    eax,[esi+0x14]
0053114e  7202                               jb     0x531152
00531150  8b00                               mov    eax,DWORD PTR [eax]
00531152  68a4f0c000                         push   0xc0f0a4
00531157  50                                 push   eax
00531158  e8542b3600                         call   0x893cb1
0053115d  83c408                             add    esp,0x8
00531160  85c0                               test   eax,eax
00531162  0f841c020000                       je     0x531384
00531168  8b7650                             mov    esi,DWORD PTR [esi+0x50]
0053116b  3bf7                               cmp    esi,edi
0053116d  75d9                               jne    0x531148
0053116f  33c0                               xor    eax,eax
00531171  8b7750                             mov    esi,DWORD PTR [edi+0x50]
00531174  668945e0                           mov    WORD PTR [ebp-0x20],ax
00531178  3bf7                               cmp    esi,edi
0053117a  742b                               je     0x5311a7
0053117c  8d642400                           lea    esp,[esp+0x0]
00531180  395e28                             cmp    DWORD PTR [esi+0x28],ebx
00531183  8d4614                             lea    eax,[esi+0x14]
00531186  7202                               jb     0x53118a
00531188  8b00                               mov    eax,DWORD PTR [eax]
0053118a  68a8f0c000                         push   0xc0f0a8
0053118f  50                                 push   eax
00531190  e81c2b3600                         call   0x893cb1
00531195  83c408                             add    esp,0x8
00531198  85c0                               test   eax,eax
0053119a  0f840c020000                       je     0x5313ac
005311a0  8b7650                             mov    esi,DWORD PTR [esi+0x50]
005311a3  3bf7                               cmp    esi,edi
005311a5  75d9                               jne    0x531180
005311a7  33c9                               xor    ecx,ecx
005311a9  66894de2                           mov    WORD PTR [ebp-0x1e],cx
005311ad  8b85e0feffff                       mov    eax,DWORD PTR [ebp-0x120]
005311b3  bf00d6c000                         mov    edi,0xc0d600
005311b8  e8a3d11f00                         call   0x72e360
005311bd  85c0                               test   eax,eax
005311bf  7470                               je     0x531231
005311c1  8bb094000000                       mov    esi,DWORD PTR [eax+0x94]
005311c7  8d7844                             lea    edi,[eax+0x44]
005311ca  3bf7                               cmp    esi,edi
005311cc  7429                               je     0x5311f7
005311ce  8bff                               mov    edi,edi
005311d0  395e28                             cmp    DWORD PTR [esi+0x28],ebx
005311d3  8d4614                             lea    eax,[esi+0x14]
005311d6  7202                               jb     0x5311da
005311d8  8b00                               mov    eax,DWORD PTR [eax]
005311da  68b4f0c000                         push   0xc0f0b4
005311df  50                                 push   eax
005311e0  e8cc2a3600                         call   0x893cb1
005311e5  83c408                             add    esp,0x8
005311e8  85c0                               test   eax,eax
005311ea  0f84e8010000                       je     0x5313d8
005311f0  8b7650                             mov    esi,DWORD PTR [esi+0x50]
005311f3  3bf7                               cmp    esi,edi
005311f5  75d9                               jne    0x5311d0
005311f7  33d2                               xor    edx,edx
005311f9  668955e4                           mov    WORD PTR [ebp-0x1c],dx
005311fd  8b7750                             mov    esi,DWORD PTR [edi+0x50]
00531200  3bf7                               cmp    esi,edi
00531202  7427                               je     0x53122b
00531204  395e28                             cmp    DWORD PTR [esi+0x28],ebx
00531207  8d4614                             lea    eax,[esi+0x14]
0053120a  7202                               jb     0x53120e
0053120c  8b00                               mov    eax,DWORD PTR [eax]
0053120e  68bcf0c000                         push   0xc0f0bc
00531213  50                                 push   eax
00531214  e8982a3600                         call   0x893cb1
00531219  83c408                             add    esp,0x8
0053121c  85c0                               test   eax,eax
0053121e  0f84e0010000                       je     0x531404
00531224  8b7650                             mov    esi,DWORD PTR [esi+0x50]
00531227  3bf7                               cmp    esi,edi
00531229  75d9                               jne    0x531204
0053122b  33c0                               xor    eax,eax
0053122d  668945e6                           mov    WORD PTR [ebp-0x1a],ax
00531231  8b85e0feffff                       mov    eax,DWORD PTR [ebp-0x120]
00531237  bfc0f0c000                         mov    edi,0xc0f0c0
0053123c  e81fd11f00                         call   0x72e360
00531241  85c0                               test   eax,eax
00531243  746e                               je     0x5312b3
00531245  8bb094000000                       mov    esi,DWORD PTR [eax+0x94]
0053124b  8d7844                             lea    edi,[eax+0x44]
0053124e  3bf7                               cmp    esi,edi
00531250  7427                               je     0x531279
00531252  395e28                             cmp    DWORD PTR [esi+0x28],ebx
00531255  8d4614                             lea    eax,[esi+0x14]
00531258  7202                               jb     0x53125c
0053125a  8b00                               mov    eax,DWORD PTR [eax]
0053125c  68b4f0c000                         push   0xc0f0b4
00531261  50                                 push   eax
00531262  e84a2a3600                         call   0x893cb1
00531267  83c408                             add    esp,0x8
0053126a  85c0                               test   eax,eax
0053126c  0f84ba010000                       je     0x53142c
00531272  8b7650                             mov    esi,DWORD PTR [esi+0x50]
00531275  3bf7                               cmp    esi,edi
00531277  75d9                               jne    0x531252
00531279  33c9                               xor    ecx,ecx
0053127b  66894de8                           mov    WORD PTR [ebp-0x18],cx
0053127f  8b7750                             mov    esi,DWORD PTR [edi+0x50]
00531282  3bf7                               cmp    esi,edi
00531284  7427                               je     0x5312ad
00531286  395e28                             cmp    DWORD PTR [esi+0x28],ebx
00531289  8d4614                             lea    eax,[esi+0x14]
0053128c  7202                               jb     0x531290
0053128e  8b00                               mov    eax,DWORD PTR [eax]
00531290  68bcf0c000                         push   0xc0f0bc
00531295  50                                 push   eax
00531296  e8162a3600                         call   0x893cb1
0053129b  83c408                             add    esp,0x8
0053129e  85c0                               test   eax,eax
005312a0  0f84b2010000                       je     0x531458
005312a6  8b7650                             mov    esi,DWORD PTR [esi+0x50]
005312a9  3bf7                               cmp    esi,edi
005312ab  75d9                               jne    0x531286
005312ad  33d2                               xor    edx,edx
005312af  668955ea                           mov    WORD PTR [ebp-0x16],dx
005312b3  8bbdd8feffff                       mov    edi,DWORD PTR [ebp-0x128]
005312b9  8d4d98                             lea    ecx,[ebp-0x68]
005312bc  e85f77fdff                         call   0x508a20
005312c1  8bb5e4feffff                       mov    esi,DWORD PTR [ebp-0x11c]
005312c7  8b4604                             mov    eax,DWORD PTR [esi+0x4]
005312ca  8d4ddc                             lea    ecx,[ebp-0x24]
005312cd  3bc8                               cmp    ecx,eax
005312cf  0f83eb010000                       jae    0x5314c0
005312d5  8b16                               mov    edx,DWORD PTR [esi]
005312d7  3bd1                               cmp    edx,ecx
005312d9  0f87e1010000                       ja     0x5314c0
005312df  8bbde4feffff                       mov    edi,DWORD PTR [ebp-0x11c]
005312e5  8bf1                               mov    esi,ecx
005312e7  8b4f08                             mov    ecx,DWORD PTR [edi+0x8]
005312ea  2bf2                               sub    esi,edx
005312ec  3bc1                               cmp    eax,ecx
005312ee  0f85a5010000                       jne    0x531499
005312f4  2bc2                               sub    eax,edx
005312f6  c1f804                             sar    eax,0x4
005312f9  3dfeffff0f                         cmp    eax,0xffffffe
005312fe  0f87b5030000                       ja     0x5316b9
00531304  2bca                               sub    ecx,edx
00531306  40                                 inc    eax
00531307  c1f904                             sar    ecx,0x4
0053130a  3bc1                               cmp    eax,ecx
0053130c  0f8687010000                       jbe    0x531499
00531312  8bd1                               mov    edx,ecx
00531314  d1ea                               shr    edx,1
00531316  bfffffff0f                         mov    edi,0xfffffff
0053131b  2bfa                               sub    edi,edx
0053131d  3bf9                               cmp    edi,ecx
0053131f  0f835f010000                       jae    0x531484
00531325  33c9                               xor    ecx,ecx
00531327  e95a010000                         jmp    0x531486
0053132c  85f6                               test   esi,esi
0053132e  0f84d3fdffff                       je     0x531107
00531334  395e44                             cmp    DWORD PTR [esi+0x44],ebx
00531337  8d4630                             lea    eax,[esi+0x30]
0053133a  7202                               jb     0x53133e
0053133c  8b00                               mov    eax,DWORD PTR [eax]
0053133e  85c0                               test   eax,eax
00531340  0f84c1fdffff                       je     0x531107
00531346  50                                 push   eax
00531347  e868043600                         call   0x8917b4
0053134c  83c404                             add    esp,0x4
0053134f  668945dc                           mov    WORD PTR [ebp-0x24],ax
00531353  e9b5fdffff                         jmp    0x53110d
00531358  85f6                               test   esi,esi
0053135a  0f84dbfdffff                       je     0x53113b
00531360  395e44                             cmp    DWORD PTR [esi+0x44],ebx
00531363  8d4630                             lea    eax,[esi+0x30]
00531366  7202                               jb     0x53136a
00531368  8b00                               mov    eax,DWORD PTR [eax]
0053136a  85c0                               test   eax,eax
0053136c  0f84c9fdffff                       je     0x53113b
00531372  50                                 push   eax
00531373  e83c043600                         call   0x8917b4
00531378  83c404                             add    esp,0x4
0053137b  668945de                           mov    WORD PTR [ebp-0x22],ax
0053137f  e9bdfdffff                         jmp    0x531141
00531384  85f6                               test   esi,esi
00531386  0f84e3fdffff                       je     0x53116f
0053138c  395e44                             cmp    DWORD PTR [esi+0x44],ebx
0053138f  8d4630                             lea    eax,[esi+0x30]
00531392  7202                               jb     0x531396
00531394  8b00                               mov    eax,DWORD PTR [eax]
00531396  85c0                               test   eax,eax
00531398  0f84d1fdffff                       je     0x53116f
0053139e  50                                 push   eax
0053139f  e810043600                         call   0x8917b4
005313a4  83c404                             add    esp,0x4
005313a7  e9c5fdffff                         jmp    0x531171
005313ac  85f6                               test   esi,esi
005313ae  0f84f3fdffff                       je     0x5311a7
005313b4  395e44                             cmp    DWORD PTR [esi+0x44],ebx
005313b7  8d4630                             lea    eax,[esi+0x30]
005313ba  7202                               jb     0x5313be
005313bc  8b00                               mov    eax,DWORD PTR [eax]
005313be  85c0                               test   eax,eax
005313c0  0f84e1fdffff                       je     0x5311a7
005313c6  50                                 push   eax
005313c7  e8e8033600                         call   0x8917b4
005313cc  83c404                             add    esp,0x4
005313cf  668945e2                           mov    WORD PTR [ebp-0x1e],ax
005313d3  e9d5fdffff                         jmp    0x5311ad
005313d8  85f6                               test   esi,esi
005313da  0f8417feffff                       je     0x5311f7
005313e0  395e44                             cmp    DWORD PTR [esi+0x44],ebx
005313e3  8d4630                             lea    eax,[esi+0x30]
005313e6  7202                               jb     0x5313ea
005313e8  8b00                               mov    eax,DWORD PTR [eax]
005313ea  85c0                               test   eax,eax
005313ec  0f8405feffff                       je     0x5311f7
005313f2  50                                 push   eax
005313f3  e8bc033600                         call   0x8917b4
005313f8  83c404                             add    esp,0x4
005313fb  668945e4                           mov    WORD PTR [ebp-0x1c],ax
005313ff  e9f9fdffff                         jmp    0x5311fd
00531404  85f6                               test   esi,esi
00531406  0f841ffeffff                       je     0x53122b
0053140c  395e44                             cmp    DWORD PTR [esi+0x44],ebx
0053140f  8d4630                             lea    eax,[esi+0x30]
00531412  7202                               jb     0x531416
00531414  8b00                               mov    eax,DWORD PTR [eax]
00531416  85c0                               test   eax,eax
00531418  0f840dfeffff                       je     0x53122b
0053141e  50                                 push   eax
0053141f  e890033600                         call   0x8917b4
00531424  83c404                             add    esp,0x4
00531427  e901feffff                         jmp    0x53122d
0053142c  85f6                               test   esi,esi
0053142e  0f8445feffff                       je     0x531279
00531434  395e44                             cmp    DWORD PTR [esi+0x44],ebx
00531437  8d4630                             lea    eax,[esi+0x30]
0053143a  7202                               jb     0x53143e
0053143c  8b00                               mov    eax,DWORD PTR [eax]
0053143e  85c0                               test   eax,eax
00531440  0f8433feffff                       je     0x531279
00531446  50                                 push   eax
00531447  e868033600                         call   0x8917b4
0053144c  83c404                             add    esp,0x4
0053144f  668945e8                           mov    WORD PTR [ebp-0x18],ax
00531453  e927feffff                         jmp    0x53127f
00531458  85f6                               test   esi,esi
0053145a  0f844dfeffff                       je     0x5312ad
00531460  395e44                             cmp    DWORD PTR [esi+0x44],ebx
00531463  8d4630                             lea    eax,[esi+0x30]
00531466  7202                               jb     0x53146a
00531468  8b00                               mov    eax,DWORD PTR [eax]
0053146a  85c0                               test   eax,eax
0053146c  0f843bfeffff                       je     0x5312ad
00531472  50                                 push   eax
00531473  e83c033600                         call   0x8917b4
00531478  83c404                             add    esp,0x4
0053147b  668945ea                           mov    WORD PTR [ebp-0x16],ax
0053147f  e92ffeffff                         jmp    0x5312b3
00531484  03ca                               add    ecx,edx
00531486  8bbde4feffff                       mov    edi,DWORD PTR [ebp-0x11c]
0053148c  3bc8                               cmp    ecx,eax
0053148e  0f42c8                             cmovb  ecx,eax
00531491  51                                 push   ecx
00531492  8bcf                               mov    ecx,edi
00531494  e8c7030000                         call   0x531860
00531499  8b4704                             mov    eax,DWORD PTR [edi+0x4]
0053149c  83e6f0                             and    esi,0xfffffff0
0053149f  0337                               add    esi,DWORD PTR [edi]
005314a1  85c0                               test   eax,eax
005314a3  7416                               je     0x5314bb
005314a5  8b16                               mov    edx,DWORD PTR [esi]
005314a7  8910                               mov    DWORD PTR [eax],edx
005314a9  8b4e04                             mov    ecx,DWORD PTR [esi+0x4]
005314ac  894804                             mov    DWORD PTR [eax+0x4],ecx
005314af  8b5608                             mov    edx,DWORD PTR [esi+0x8]
005314b2  895008                             mov    DWORD PTR [eax+0x8],edx
005314b5  8b4e0c                             mov    ecx,DWORD PTR [esi+0xc]
005314b8  89480c                             mov    DWORD PTR [eax+0xc],ecx
005314bb  015f04                             add    DWORD PTR [edi+0x4],ebx
005314be  eb66                               jmp    0x531526
005314c0  8b4e08                             mov    ecx,DWORD PTR [esi+0x8]
005314c3  3bc1                               cmp    eax,ecx
005314c5  753e                               jne    0x531505
005314c7  8b16                               mov    edx,DWORD PTR [esi]
005314c9  2bc2                               sub    eax,edx
005314cb  c1f804                             sar    eax,0x4
005314ce  3dfeffff0f                         cmp    eax,0xffffffe
005314d3  0f87e0010000                       ja     0x5316b9
005314d9  2bca                               sub    ecx,edx
005314db  40                                 inc    eax
005314dc  c1f904                             sar    ecx,0x4
005314df  3bc1                               cmp    eax,ecx
005314e1  7622                               jbe    0x531505
005314e3  8bd1                               mov    edx,ecx
005314e5  d1ea                               shr    edx,1
005314e7  bfffffff0f                         mov    edi,0xfffffff
005314ec  2bfa                               sub    edi,edx
005314ee  3bf9                               cmp    edi,ecx
005314f0  7304                               jae    0x5314f6
005314f2  33c9                               xor    ecx,ecx
005314f4  eb02                               jmp    0x5314f8
005314f6  03ca                               add    ecx,edx
005314f8  3bc8                               cmp    ecx,eax
005314fa  0f42c8                             cmovb  ecx,eax
005314fd  51                                 push   ecx
005314fe  8bce                               mov    ecx,esi
00531500  e85b030000                         call   0x531860
00531505  8b4604                             mov    eax,DWORD PTR [esi+0x4]
00531508  85c0                               test   eax,eax
0053150a  7417                               je     0x531523
0053150c  8b55dc                             mov    edx,DWORD PTR [ebp-0x24]
0053150f  8b4de0                             mov    ecx,DWORD PTR [ebp-0x20]
00531512  8910                               mov    DWORD PTR [eax],edx
00531514  8b55e4                             mov    edx,DWORD PTR [ebp-0x1c]
00531517  894804                             mov    DWORD PTR [eax+0x4],ecx
0053151a  8b4de8                             mov    ecx,DWORD PTR [ebp-0x18]
0053151d  895008                             mov    DWORD PTR [eax+0x8],edx
00531520  89480c                             mov    DWORD PTR [eax+0xc],ecx
00531523  015e04                             add    DWORD PTR [esi+0x4],ebx
00531526  8b95e0feffff                       mov    edx,DWORD PTR [ebp-0x120]
0053152c  8b7240                             mov    esi,DWORD PTR [edx+0x40]
0053152f  85f6                               test   esi,esi
00531531  7423                               je     0x531556
00531533  395e34                             cmp    DWORD PTR [esi+0x34],ebx
00531536  8d4620                             lea    eax,[esi+0x20]
00531539  7202                               jb     0x53153d
0053153b  8b00                               mov    eax,DWORD PTR [eax]
0053153d  68fccfbf00                         push   0xbfcffc
00531542  50                                 push   eax
00531543  e869273600                         call   0x893cb1
00531548  83c408                             add    esp,0x8
0053154b  85c0                               test   eax,eax
0053154d  7409                               je     0x531558
0053154f  8b7640                             mov    esi,DWORD PTR [esi+0x40]
00531552  85f6                               test   esi,esi
00531554  75dd                               jne    0x531533
00531556  33f6                               xor    esi,esi
00531558  89b5e0feffff                       mov    DWORD PTR [ebp-0x120],esi
0053155e  85f6                               test   esi,esi
00531560  0f856af9ffff                       jne    0x530ed0
00531566  8bb5c0feffff                       mov    esi,DWORD PTR [ebp-0x140]
0053156c  8b5604                             mov    edx,DWORD PTR [esi+0x4]
0053156f  8b4204                             mov    eax,DWORD PTR [edx+0x4]
00531572  80781500                           cmp    BYTE PTR [eax+0x15],0x0
00531576  8bbdccfeffff                       mov    edi,DWORD PTR [ebp-0x134]
0053157c  8bca                               mov    ecx,edx
0053157e  7514                               jne    0x531594
00531580  39780c                             cmp    DWORD PTR [eax+0xc],edi
00531583  7d05                               jge    0x53158a
00531585  8b4008                             mov    eax,DWORD PTR [eax+0x8]
00531588  eb04                               jmp    0x53158e
0053158a  8bc8                               mov    ecx,eax
0053158c  8b00                               mov    eax,DWORD PTR [eax]
0053158e  80781500                           cmp    BYTE PTR [eax+0x15],0x0
00531592  74ec                               je     0x531580
00531594  8bc2                               mov    eax,edx
00531596  898dd8feffff                       mov    DWORD PTR [ebp-0x128],ecx
0053159c  3bc8                               cmp    ecx,eax
0053159e  740d                               je     0x5315ad
005315a0  3b790c                             cmp    edi,DWORD PTR [ecx+0xc]
005315a3  7c08                               jl     0x5315ad
005315a5  8d85d8feffff                       lea    eax,[ebp-0x128]
005315ab  eb0c                               jmp    0x5315b9
005315ad  8985bcfeffff                       mov    DWORD PTR [ebp-0x144],eax
005315b3  8d85bcfeffff                       lea    eax,[ebp-0x144]
005315b9  3910                               cmp    DWORD PTR [eax],edx
005315bb  7414                               je     0x5315d1
005315bd  8b8ddcfeffff                       mov    ecx,DWORD PTR [ebp-0x124]
005315c3  85c9                               test   ecx,ecx
005315c5  7434                               je     0x5315fb
005315c7  8b01                               mov    eax,DWORD PTR [ecx]
005315c9  8b10                               mov    edx,DWORD PTR [eax]
005315cb  6a01                               push   0x1
005315cd  ffd2                               call   edx
005315cf  eb2a                               jmp    0x5315fb
005315d1  8b85dcfeffff                       mov    eax,DWORD PTR [ebp-0x124]
005315d7  89bdb4feffff                       mov    DWORD PTR [ebp-0x14c],edi
005315dd  8dbdb4feffff                       lea    edi,[ebp-0x14c]
005315e3  8985b8feffff                       mov    DWORD PTR [ebp-0x148],eax
005315e9  e832d90400                         call   0x57ef20
005315ee  50                                 push   eax
005315ef  56                                 push   esi
005315f0  8db5acfeffff                       lea    esi,[ebp-0x154]
005315f6  e855d20400                         call   0x57e850
005315fb  8b8dd0feffff                       mov    ecx,DWORD PTR [ebp-0x130]
00531601  8b4140                             mov    eax,DWORD PTR [ecx+0x40]
00531604  8985d0feffff                       mov    DWORD PTR [ebp-0x130],eax
0053160a  85c0                               test   eax,eax
0053160c  0f85bef3ffff                       jne    0x5309d0
00531612  be08000000                         mov    esi,0x8
00531617  3975b8                             cmp    DWORD PTR [ebp-0x48],esi
0053161a  720c                               jb     0x531628
0053161c  8b55a4                             mov    edx,DWORD PTR [ebp-0x5c]
0053161f  52                                 push   edx
00531620  e8e7fb3500                         call   0x89120c
00531625  83c404                             add    esp,0x4
00531628  3975d4                             cmp    DWORD PTR [ebp-0x2c],esi
0053162b  720c                               jb     0x531639
0053162d  8b45c0                             mov    eax,DWORD PTR [ebp-0x40]
00531630  50                                 push   eax
00531631  e8d6fb3500                         call   0x89120c
00531636  83c404                             add    esp,0x4
00531639  33f6                               xor    esi,esi
0053163b  33c9                               xor    ecx,ecx
0053163d  c745fcffffffff                     mov    DWORD PTR [ebp-0x4],0xffffffff
00531644  83bd64ffffff10                     cmp    DWORD PTR [ebp-0x9c],0x10
0053164b  c745d407000000                     mov    DWORD PTR [ebp-0x2c],0x7
00531652  8975d0                             mov    DWORD PTR [ebp-0x30],esi
00531655  66894dc0                           mov    WORD PTR [ebp-0x40],cx
00531659  c78504ffffff9423bf00               mov    DWORD PTR [ebp-0xfc],0xbf2394
00531663  720f                               jb     0x531674
00531665  8b9550ffffff                       mov    edx,DWORD PTR [ebp-0xb0]
0053166b  52                                 push   edx
0053166c  e89bfb3500                         call   0x89120c
00531671  83c404                             add    esp,0x4
00531674  8d8d04ffffff                       lea    ecx,[ebp-0xfc]
0053167a  c78564ffffff0f000000               mov    DWORD PTR [ebp-0x9c],0xf
00531684  89b560ffffff                       mov    DWORD PTR [ebp-0xa0],esi
0053168a  c68550ffffff00                     mov    BYTE PTR [ebp-0xb0],0x0
00531691  e8aac91f00                         call   0x72e040
00531696  b801000000                         mov    eax,0x1
0053169b  8b4df4                             mov    ecx,DWORD PTR [ebp-0xc]
0053169e  64890d00000000                     mov    DWORD PTR fs:0x0,ecx
005316a5  59                                 pop    ecx
005316a6  5f                                 pop    edi
005316a7  5e                                 pop    esi
005316a8  5b                                 pop    ebx
005316a9  8b4dec                             mov    ecx,DWORD PTR [ebp-0x14]
005316ac  33cd                               xor    ecx,ebp
005316ae  e84ef93500                         call   0x891001
005316b3  8be5                               mov    esp,ebp
005316b5  5d                                 pop    ebp
005316b6  c20400                             ret    0x4
005316b9  687823bf00                         push   0xbf2378
005316be  e86dc43400                         call   0x87db30
; hp_cost_reader [0x530530,0x5305b3) 完整；有號WORD offset0
00530530  55                                 push   ebp
00530531  8bec                               mov    ebp,esp
00530533  51                                 push   ecx
00530534  56                                 push   esi
00530535  8b7508                             mov    esi,DWORD PTR [ebp+0x8]
00530538  57                                 push   edi
00530539  8bf8                               mov    edi,eax
0053053b  8b4630                             mov    eax,DWORD PTR [esi+0x30]
0053053e  85c0                               test   eax,eax
00530540  740c                               je     0x53054e
00530542  394804                             cmp    DWORD PTR [eax+0x4],ecx
00530545  7407                               je     0x53054e
00530547  c7463000000000                     mov    DWORD PTR [esi+0x30],0x0
0053054e  837e3000                           cmp    DWORD PTR [esi+0x30],0x0
00530552  7523                               jne    0x530577
00530554  8d4508                             lea    eax,[ebp+0x8]
00530557  894d08                             mov    DWORD PTR [ebp+0x8],ecx
0053055a  50                                 push   eax
0053055b  8d45fc                             lea    eax,[ebp-0x4]
0053055e  8bce                               mov    ecx,esi
00530560  e85b333100                         call   0x8438c0
00530565  8b45fc                             mov    eax,DWORD PTR [ebp-0x4]
00530568  3b4604                             cmp    eax,DWORD PTR [esi+0x4]
0053056b  7405                               je     0x530572
0053056d  8b4010                             mov    eax,DWORD PTR [eax+0x10]
00530570  eb02                               jmp    0x530574
00530572  33c0                               xor    eax,eax
00530574  894630                             mov    DWORD PTR [esi+0x30],eax
00530577  8b7630                             mov    esi,DWORD PTR [esi+0x30]
0053057a  85f6                               test   esi,esi
0053057c  742b                               je     0x5305a9
0053057e  807e2401                           cmp    BYTE PTR [esi+0x24],0x1
00530582  7525                               jne    0x5305a9
00530584  8b4e64                             mov    ecx,DWORD PTR [esi+0x64]
00530587  2b4e60                             sub    ecx,DWORD PTR [esi+0x60]
0053058a  c1f904                             sar    ecx,0x4
0053058d  3bf9                               cmp    edi,ecx
0053058f  7718                               ja     0x5305a9
00530591  8b5660                             mov    edx,DWORD PTR [esi+0x60]
00530594  03ff                               add    edi,edi
00530596  8d44faf0                           lea    eax,[edx+edi*8-0x10]
0053059a  85c0                               test   eax,eax
0053059c  740b                               je     0x5305a9
0053059e  0fbf00                             movsx  eax,WORD PTR [eax]
005305a1  5f                                 pop    edi
005305a2  5e                                 pop    esi
005305a3  8be5                               mov    esp,ebp
005305a5  5d                                 pop    ebp
005305a6  c20400                             ret    0x4
005305a9  5f                                 pop    edi
005305aa  33c0                               xor    eax,eax
005305ac  5e                                 pop    esi
005305ad  8be5                               mov    esp,ebp
005305af  5d                                 pop    ebp
005305b0  c20400                             ret    0x4
; sp_cost_reader [0x5305c0,0x530644) 完整；有號WORD offset2
005305c0  55                                 push   ebp
005305c1  8bec                               mov    ebp,esp
005305c3  51                                 push   ecx
005305c4  56                                 push   esi
005305c5  8b7508                             mov    esi,DWORD PTR [ebp+0x8]
005305c8  57                                 push   edi
005305c9  8bf8                               mov    edi,eax
005305cb  8b4630                             mov    eax,DWORD PTR [esi+0x30]
005305ce  85c0                               test   eax,eax
005305d0  740c                               je     0x5305de
005305d2  394804                             cmp    DWORD PTR [eax+0x4],ecx
005305d5  7407                               je     0x5305de
005305d7  c7463000000000                     mov    DWORD PTR [esi+0x30],0x0
005305de  837e3000                           cmp    DWORD PTR [esi+0x30],0x0
005305e2  7523                               jne    0x530607
005305e4  8d4508                             lea    eax,[ebp+0x8]
005305e7  894d08                             mov    DWORD PTR [ebp+0x8],ecx
005305ea  50                                 push   eax
005305eb  8d45fc                             lea    eax,[ebp-0x4]
005305ee  8bce                               mov    ecx,esi
005305f0  e8cb323100                         call   0x8438c0
005305f5  8b45fc                             mov    eax,DWORD PTR [ebp-0x4]
005305f8  3b4604                             cmp    eax,DWORD PTR [esi+0x4]
005305fb  7405                               je     0x530602
005305fd  8b4010                             mov    eax,DWORD PTR [eax+0x10]
00530600  eb02                               jmp    0x530604
00530602  33c0                               xor    eax,eax
00530604  894630                             mov    DWORD PTR [esi+0x30],eax
00530607  8b7630                             mov    esi,DWORD PTR [esi+0x30]
0053060a  85f6                               test   esi,esi
0053060c  742c                               je     0x53063a
0053060e  807e2401                           cmp    BYTE PTR [esi+0x24],0x1
00530612  7526                               jne    0x53063a
00530614  8b4e64                             mov    ecx,DWORD PTR [esi+0x64]
00530617  2b4e60                             sub    ecx,DWORD PTR [esi+0x60]
0053061a  c1f904                             sar    ecx,0x4
0053061d  3bf9                               cmp    edi,ecx
0053061f  7719                               ja     0x53063a
00530621  8b5660                             mov    edx,DWORD PTR [esi+0x60]
00530624  03ff                               add    edi,edi
00530626  8d44faf0                           lea    eax,[edx+edi*8-0x10]
0053062a  85c0                               test   eax,eax
0053062c  740c                               je     0x53063a
0053062e  0fbf4002                           movsx  eax,WORD PTR [eax+0x2]
00530632  5f                                 pop    edi
00530633  5e                                 pop    esi
00530634  8be5                               mov    esp,ebp
00530636  5d                                 pop    ebp
00530637  c20400                             ret    0x4
0053063a  5f                                 pop    edi
0053063b  33c0                               xor    eax,eax
0053063d  5e                                 pop    esi
0053063e  8be5                               mov    esp,ebp
00530640  5d                                 pop    ebp
00530641  c20400                             ret    0x4
; mp_cost_reader [0x530650,0x5306d4) 完整；有號WORD offset4
00530650  55                                 push   ebp
00530651  8bec                               mov    ebp,esp
00530653  51                                 push   ecx
00530654  56                                 push   esi
00530655  8b7508                             mov    esi,DWORD PTR [ebp+0x8]
00530658  57                                 push   edi
00530659  8bf8                               mov    edi,eax
0053065b  8b4630                             mov    eax,DWORD PTR [esi+0x30]
0053065e  85c0                               test   eax,eax
00530660  740c                               je     0x53066e
00530662  394804                             cmp    DWORD PTR [eax+0x4],ecx
00530665  7407                               je     0x53066e
00530667  c7463000000000                     mov    DWORD PTR [esi+0x30],0x0
0053066e  837e3000                           cmp    DWORD PTR [esi+0x30],0x0
00530672  7523                               jne    0x530697
00530674  8d4508                             lea    eax,[ebp+0x8]
00530677  894d08                             mov    DWORD PTR [ebp+0x8],ecx
0053067a  50                                 push   eax
0053067b  8d45fc                             lea    eax,[ebp-0x4]
0053067e  8bce                               mov    ecx,esi
00530680  e83b323100                         call   0x8438c0
00530685  8b45fc                             mov    eax,DWORD PTR [ebp-0x4]
00530688  3b4604                             cmp    eax,DWORD PTR [esi+0x4]
0053068b  7405                               je     0x530692
0053068d  8b4010                             mov    eax,DWORD PTR [eax+0x10]
00530690  eb02                               jmp    0x530694
00530692  33c0                               xor    eax,eax
00530694  894630                             mov    DWORD PTR [esi+0x30],eax
00530697  8b7630                             mov    esi,DWORD PTR [esi+0x30]
0053069a  85f6                               test   esi,esi
0053069c  742c                               je     0x5306ca
0053069e  807e2401                           cmp    BYTE PTR [esi+0x24],0x1
005306a2  7526                               jne    0x5306ca
005306a4  8b4e64                             mov    ecx,DWORD PTR [esi+0x64]
005306a7  2b4e60                             sub    ecx,DWORD PTR [esi+0x60]
005306aa  c1f904                             sar    ecx,0x4
005306ad  3bf9                               cmp    edi,ecx
005306af  7719                               ja     0x5306ca
005306b1  8b5660                             mov    edx,DWORD PTR [esi+0x60]
005306b4  03ff                               add    edi,edi
005306b6  8d44faf0                           lea    eax,[edx+edi*8-0x10]
005306ba  85c0                               test   eax,eax
005306bc  740c                               je     0x5306ca
005306be  0fbf4004                           movsx  eax,WORD PTR [eax+0x4]
005306c2  5f                                 pop    edi
005306c3  5e                                 pop    esi
005306c4  8be5                               mov    esp,ebp
005306c6  5d                                 pop    ebp
005306c7  c20400                             ret    0x4
005306ca  5f                                 pop    edi
005306cb  33c0                               xor    eax,eax
005306cd  5e                                 pop    esi
005306ce  8be5                               mov    esp,ebp
005306d0  5d                                 pop    ebp
005306d1  c20400                             ret    0x4
; pair_store_accessor [0x48a400,0x48a437) 完整；唯一 singleton FD9278，三指標容器
0048a400  b801000000                         mov    eax,0x1
0048a405  84057492fd00                       test   BYTE PTR ds:0xfd9274,al
0048a40b  7524                               jne    0x48a431
0048a40d  09057492fd00                       or     DWORD PTR ds:0xfd9274,eax
0048a413  33c0                               xor    eax,eax
0048a415  68d0e2bc00                         push   0xbce2d0
0048a41a  a37892fd00                         mov    ds:0xfd9278,eax
0048a41f  a37c92fd00                         mov    ds:0xfd927c,eax
0048a424  a38092fd00                         mov    ds:0xfd9280,eax
0048a429  e8ec7e4000                         call   0x89231a
0048a42e  83c404                             add    esp,0x4
0048a431  b87892fd00                         mov    eax,0xfd9278
0048a436  c3                                 ret
; pair_store_constructor [0x6d89c0,0x6d8a0a) 完整；兩WORD、四float、total/remaining；stack 7args + XMM0
006d89c0  55                                 push   ebp
006d89c1  8bec                               mov    ebp,esp
006d89c3  83ec1c                             sub    esp,0x1c
006d89c6  8b4514                             mov    eax,DWORD PTR [ebp+0x14]
006d89c9  8b4d18                             mov    ecx,DWORD PTR [ebp+0x18]
006d89cc  8b551c                             mov    edx,DWORD PTR [ebp+0x1c]
006d89cf  8945e8                             mov    DWORD PTR [ebp-0x18],eax
006d89d2  8b4520                             mov    eax,DWORD PTR [ebp+0x20]
006d89d5  8945f4                             mov    DWORD PTR [ebp-0xc],eax
006d89d8  8b4508                             mov    eax,DWORD PTR [ebp+0x8]
006d89db  894dec                             mov    DWORD PTR [ebp-0x14],ecx
006d89de  668b4d10                           mov    cx,WORD PTR [ebp+0x10]
006d89e2  8955f0                             mov    DWORD PTR [ebp-0x10],edx
006d89e5  668b550c                           mov    dx,WORD PTR [ebp+0xc]
006d89e9  50                                 push   eax
006d89ea  8d45e4                             lea    eax,[ebp-0x1c]
006d89ed  f30f1145fc                         movss  DWORD PTR [ebp-0x4],xmm0
006d89f2  f30f1145f8                         movss  DWORD PTR [ebp-0x8],xmm0
006d89f7  66894de6                           mov    WORD PTR [ebp-0x1a],cx
006d89fb  668955e4                           mov    WORD PTR [ebp-0x1c],dx
006d89ff  e80c000000                         call   0x6d8a10
006d8a04  8be5                               mov    esp,ebp
006d8a06  5d                                 pop    ebp
006d8a07  c21c00                             ret    0x1c
; pair_store_append [0x6d8a10,0x6d8a7e) 完整；28-byte複製/append；增容callee不作事件語意
006d8a10  55                                 push   ebp
006d8a11  8bec                               mov    ebp,esp
006d8a13  53                                 push   ebx
006d8a14  8b5d08                             mov    ebx,DWORD PTR [ebp+0x8]
006d8a17  8b4b04                             mov    ecx,DWORD PTR [ebx+0x4]
006d8a1a  56                                 push   esi
006d8a1b  8bf0                               mov    esi,eax
006d8a1d  57                                 push   edi
006d8a1e  3bf1                               cmp    esi,ecx
006d8a20  7337                               jae    0x6d8a59
006d8a22  8b03                               mov    eax,DWORD PTR [ebx]
006d8a24  3bc6                               cmp    eax,esi
006d8a26  7731                               ja     0x6d8a59
006d8a28  2bf0                               sub    esi,eax
006d8a2a  b893244992                         mov    eax,0x92492493
006d8a2f  f7ee                               imul   esi
006d8a31  03d6                               add    edx,esi
006d8a33  c1fa04                             sar    edx,0x4
006d8a36  8bf2                               mov    esi,edx
006d8a38  c1ee1f                             shr    esi,0x1f
006d8a3b  03f2                               add    esi,edx
006d8a3d  3b4b08                             cmp    ecx,DWORD PTR [ebx+0x8]
006d8a40  7507                               jne    0x6d8a49
006d8a42  8bcb                               mov    ecx,ebx
006d8a44  e837000000                         call   0x6d8a80
006d8a49  8b0b                               mov    ecx,DWORD PTR [ebx]
006d8a4b  8d04f500000000                     lea    eax,[esi*8+0x0]
006d8a52  2bc6                               sub    eax,esi
006d8a54  8d3481                             lea    esi,[ecx+eax*4]
006d8a57  eb0c                               jmp    0x6d8a65
006d8a59  3b4b08                             cmp    ecx,DWORD PTR [ebx+0x8]
006d8a5c  7507                               jne    0x6d8a65
006d8a5e  8bcb                               mov    ecx,ebx
006d8a60  e81b000000                         call   0x6d8a80
006d8a65  8b7b04                             mov    edi,DWORD PTR [ebx+0x4]
006d8a68  85ff                               test   edi,edi
006d8a6a  7407                               je     0x6d8a73
006d8a6c  b907000000                         mov    ecx,0x7
006d8a71  f3a5                               rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
006d8a73  8343041c                           add    DWORD PTR [ebx+0x4],0x1c
006d8a77  5f                                 pop    edi
006d8a78  5e                                 pop    esi
006d8a79  5b                                 pop    ebx
006d8a7a  5d                                 pop    ebp
006d8a7b  c20400                             ret    0x4
; pair_store_tick [0x6d8480,0x6d865b) 完整；live world ID查找、缺actor/到期erase
006d8480  55                                 push   ebp
006d8481  8bec                               mov    ebp,esp
006d8483  83e4f8                             and    esp,0xfffffff8
006d8486  6aff                               push   0xffffffff
006d8488  680e8a9300                         push   0x938a0e
006d848d  64a100000000                       mov    eax,fs:0x0
006d8493  50                                 push   eax
006d8494  83ec20                             sub    esp,0x20
006d8497  53                                 push   ebx
006d8498  56                                 push   esi
006d8499  57                                 push   edi
006d849a  a1201fd600                         mov    eax,ds:0xd61f20
006d849f  33c4                               xor    eax,esp
006d84a1  50                                 push   eax
006d84a2  8d442430                           lea    eax,[esp+0x30]
006d84a6  64a300000000                       mov    fs:0x0,eax
006d84ac  b801000000                         mov    eax,0x1
006d84b1  84052cb2fa00                       test   BYTE PTR ds:0xfab22c,al
006d84b7  7520                               jne    0x6d84d9
006d84b9  09052cb2fa00                       or     DWORD PTR ds:0xfab22c,eax
006d84bf  c744243800000000                   mov    DWORD PTR [esp+0x38],0x0
006d84c7  e8c467e0ff                         call   0x4dec90
006d84cc  6830cebc00                         push   0xbcce30
006d84d1  e8449e1b00                         call   0x89231a
006d84d6  83c404                             add    esp,0x4
006d84d9  8b4d08                             mov    ecx,DWORD PTR [ebp+0x8]
006d84dc  8b01                               mov    eax,DWORD PTR [ecx]
006d84de  8b4904                             mov    ecx,DWORD PTR [ecx+0x4]
006d84e1  89442414                           mov    DWORD PTR [esp+0x14],eax
006d84e5  894c241c                           mov    DWORD PTR [esp+0x1c],ecx
006d84e9  3bc1                               cmp    eax,ecx
006d84eb  0f8455010000                       je     0x6d8646
006d84f1  d9450c                             fld    DWORD PTR [ebp+0xc]
006d84f4  8bd0                               mov    edx,eax
006d84f6  d9ee                               fldz
006d84f8  89542418                           mov    DWORD PTR [esp+0x18],edx
006d84fc  eb04                               jmp    0x6d8502
006d84fe  8b442414                           mov    eax,DWORD PTR [esp+0x14]
006d8502  8b353cb1fa00                       mov    esi,DWORD PTR ds:0xfab13c
006d8508  0fb718                             movzx  ebx,WORD PTR [eax]
006d850b  8b4604                             mov    eax,DWORD PTR [esi+0x4]
006d850e  8bc8                               mov    ecx,eax
006d8510  80791500                           cmp    BYTE PTR [ecx+0x15],0x0
006d8514  8bfe                               mov    edi,esi
006d8516  7514                               jne    0x6d852c
006d8518  39590c                             cmp    DWORD PTR [ecx+0xc],ebx
006d851b  7305                               jae    0x6d8522
006d851d  8b4908                             mov    ecx,DWORD PTR [ecx+0x8]
006d8520  eb04                               jmp    0x6d8526
006d8522  8bf9                               mov    edi,ecx
006d8524  8b09                               mov    ecx,DWORD PTR [ecx]
006d8526  80791500                           cmp    BYTE PTR [ecx+0x15],0x0
006d852a  74ec                               je     0x6d8518
006d852c  897c2420                           mov    DWORD PTR [esp+0x20],edi
006d8530  3bfe                               cmp    edi,esi
006d8532  740b                               je     0x6d853f
006d8534  3b5f0c                             cmp    ebx,DWORD PTR [edi+0xc]
006d8537  7206                               jb     0x6d853f
006d8539  8d4c2420                           lea    ecx,[esp+0x20]
006d853d  eb08                               jmp    0x6d8547
006d853f  89742424                           mov    DWORD PTR [esp+0x24],esi
006d8543  8d4c2424                           lea    ecx,[esp+0x24]
006d8547  8b09                               mov    ecx,DWORD PTR [ecx]
006d8549  3bce                               cmp    ecx,esi
006d854b  7504                               jne    0x6d8551
006d854d  33db                               xor    ebx,ebx
006d854f  eb03                               jmp    0x6d8554
006d8551  8b5910                             mov    ebx,DWORD PTR [ecx+0x10]
006d8554  80781500                           cmp    BYTE PTR [eax+0x15],0x0
006d8558  0fb77a02                           movzx  edi,WORD PTR [edx+0x2]
006d855c  8bce                               mov    ecx,esi
006d855e  7514                               jne    0x6d8574
006d8560  39780c                             cmp    DWORD PTR [eax+0xc],edi
006d8563  7305                               jae    0x6d856a
006d8565  8b4008                             mov    eax,DWORD PTR [eax+0x8]
006d8568  eb04                               jmp    0x6d856e
006d856a  8bc8                               mov    ecx,eax
006d856c  8b00                               mov    eax,DWORD PTR [eax]
006d856e  80781500                           cmp    BYTE PTR [eax+0x15],0x0
006d8572  74ec                               je     0x6d8560
006d8574  894c2420                           mov    DWORD PTR [esp+0x20],ecx
006d8578  3bce                               cmp    ecx,esi
006d857a  740b                               je     0x6d8587
006d857c  3b790c                             cmp    edi,DWORD PTR [ecx+0xc]
006d857f  7206                               jb     0x6d8587
006d8581  8d442420                           lea    eax,[esp+0x20]
006d8585  eb08                               jmp    0x6d858f
006d8587  89742428                           mov    DWORD PTR [esp+0x28],esi
006d858b  8d442428                           lea    eax,[esp+0x28]
006d858f  8b00                               mov    eax,DWORD PTR [eax]
006d8591  3bc6                               cmp    eax,esi
006d8593  7504                               jne    0x6d8599
006d8595  33c0                               xor    eax,eax
006d8597  eb03                               jmp    0x6d859c
006d8599  8b4010                             mov    eax,DWORD PTR [eax+0x10]
006d859c  85db                               test   ebx,ebx
006d859e  7460                               je     0x6d8600
006d85a0  85c0                               test   eax,eax
006d85a2  745c                               je     0x6d8600
006d85a4  d94218                             fld    DWORD PTR [edx+0x18]
006d85a7  d8e2                               fsub   st,st(2)
006d85a9  d95c2420                           fstp   DWORD PTR [esp+0x20]
006d85ad  d9442420                           fld    DWORD PTR [esp+0x20]
006d85b1  d95218                             fst    DWORD PTR [edx+0x18]
006d85b4  d9c9                               fxch   st(1)
006d85b6  dbf1                               fcomi  st,st(1)
006d85b8  ddd9                               fstp   st(1)
006d85ba  7236                               jb     0x6d85f2
006d85bc  8b4d08                             mov    ecx,DWORD PTR [ebp+0x8]
006d85bf  8b5904                             mov    ebx,DWORD PTR [ecx+0x4]
006d85c2  8d421c                             lea    eax,[edx+0x1c]
006d85c5  3bc3                               cmp    eax,ebx
006d85c7  741c                               je     0x6d85e5
006d85c9  8bf0                               mov    esi,eax
006d85cb  8bfa                               mov    edi,edx
006d85cd  83c01c                             add    eax,0x1c
006d85d0  b907000000                         mov    ecx,0x7
006d85d5  83c21c                             add    edx,0x1c
006d85d8  f3a5                               rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
006d85da  3bc3                               cmp    eax,ebx
006d85dc  75eb                               jne    0x6d85c9
006d85de  8b542418                           mov    edx,DWORD PTR [esp+0x18]
006d85e2  8b4d08                             mov    ecx,DWORD PTR [ebp+0x8]
006d85e5  834104e4                           add    DWORD PTR [ecx+0x4],0xffffffe4
006d85e9  8b4104                             mov    eax,DWORD PTR [ecx+0x4]
006d85ec  8944241c                           mov    DWORD PTR [esp+0x1c],eax
006d85f0  eb42                               jmp    0x6d8634
006d85f2  834424141c                         add    DWORD PTR [esp+0x14],0x1c
006d85f7  83c21c                             add    edx,0x1c
006d85fa  89542418                           mov    DWORD PTR [esp+0x18],edx
006d85fe  eb34                               jmp    0x6d8634
006d8600  8b4d08                             mov    ecx,DWORD PTR [ebp+0x8]
006d8603  8b5904                             mov    ebx,DWORD PTR [ecx+0x4]
006d8606  8d421c                             lea    eax,[edx+0x1c]
006d8609  3bc3                               cmp    eax,ebx
006d860b  741c                               je     0x6d8629
006d860d  8bf0                               mov    esi,eax
006d860f  8bfa                               mov    edi,edx
006d8611  83c01c                             add    eax,0x1c
006d8614  b907000000                         mov    ecx,0x7
006d8619  83c21c                             add    edx,0x1c
006d861c  f3a5                               rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
006d861e  3bc3                               cmp    eax,ebx
006d8620  75eb                               jne    0x6d860d
006d8622  8b542418                           mov    edx,DWORD PTR [esp+0x18]
006d8626  8b4d08                             mov    ecx,DWORD PTR [ebp+0x8]
006d8629  834104e4                           add    DWORD PTR [ecx+0x4],0xffffffe4
006d862d  8b4904                             mov    ecx,DWORD PTR [ecx+0x4]
006d8630  894c241c                           mov    DWORD PTR [esp+0x1c],ecx
006d8634  8b44241c                           mov    eax,DWORD PTR [esp+0x1c]
006d8638  39442414                           cmp    DWORD PTR [esp+0x14],eax
006d863c  0f85bcfeffff                       jne    0x6d84fe
006d8642  ddd9                               fstp   st(1)
006d8644  ddd8                               fstp   st(0)
006d8646  8b4c2430                           mov    ecx,DWORD PTR [esp+0x30]
006d864a  64890d00000000                     mov    DWORD PTR fs:0x0,ecx
006d8651  59                                 pop    ecx
006d8652  5f                                 pop    edi
006d8653  5e                                 pop    esi
006d8654  5b                                 pop    ebx
006d8655  8be5                               mov    esp,ebp
006d8657  5d                                 pop    ebp
006d8658  c20800                             ret    0x8
; pair_store_draw [0x6d8660,0x6d89bc) 完整；同live ID重查、ARGB衰減、位置→7CCC00
006d8660  55                                 push   ebp
006d8661  8bec                               mov    ebp,esp
006d8663  83e4f8                             and    esp,0xfffffff8
006d8666  6aff                               push   0xffffffff
006d8668  68cc569300                         push   0x9356cc
006d866d  64a100000000                       mov    eax,fs:0x0
006d8673  50                                 push   eax
006d8674  83ec50                             sub    esp,0x50
006d8677  a1201fd600                         mov    eax,ds:0xd61f20
006d867c  33c4                               xor    eax,esp
006d867e  89442448                           mov    DWORD PTR [esp+0x48],eax
006d8682  53                                 push   ebx
006d8683  56                                 push   esi
006d8684  57                                 push   edi
006d8685  a1201fd600                         mov    eax,ds:0xd61f20
006d868a  33c4                               xor    eax,esp
006d868c  50                                 push   eax
006d868d  8d442460                           lea    eax,[esp+0x60]
006d8691  64a300000000                       mov    fs:0x0,eax
006d8697  bb01000000                         mov    ebx,0x1
006d869c  83cfff                             or     edi,0xffffffff
006d869f  8bf1                               mov    esi,ecx
006d86a1  841d2cb2fa00                       test   BYTE PTR ds:0xfab22c,bl
006d86a7  7524                               jne    0x6d86cd
006d86a9  091d2cb2fa00                       or     DWORD PTR ds:0xfab22c,ebx
006d86af  c744246800000000                   mov    DWORD PTR [esp+0x68],0x0
006d86b7  e8d465e0ff                         call   0x4dec90
006d86bc  6830cebc00                         push   0xbcce30
006d86c1  e8549c1b00                         call   0x89231a
006d86c6  83c404                             add    esp,0x4
006d86c9  897c2468                           mov    DWORD PTR [esp+0x68],edi
006d86cd  841de879fb00                       test   BYTE PTR ds:0xfb79e8,bl
006d86d3  7520                               jne    0x6d86f5
006d86d5  091de879fb00                       or     DWORD PTR ds:0xfb79e8,ebx
006d86db  895c2468                           mov    DWORD PTR [esp+0x68],ebx
006d86df  e8fc060c00                         call   0x798de0
006d86e4  68e0d2bc00                         push   0xbcd2e0
006d86e9  e82c9c1b00                         call   0x89231a
006d86ee  83c404                             add    esp,0x4
006d86f1  897c2468                           mov    DWORD PTR [esp+0x68],edi
006d86f5  68a876fb00                         push   0xfb76a8
006d86fa  e8f11e0c00                         call   0x79a5f0
006d86ff  8b1e                               mov    ebx,DWORD PTR [esi]
006d8701  8b7604                             mov    esi,DWORD PTR [esi+0x4]
006d8704  89442430                           mov    DWORD PTR [esp+0x30],eax
006d8708  89742434                           mov    DWORD PTR [esp+0x34],esi
006d870c  3bde                               cmp    ebx,esi
006d870e  0f848a020000                       je     0x6d899e
006d8714  dd058856c500                       fld    QWORD PTR ds:0xc55688
006d871a  f30f1015c056c400                   movss  xmm2,DWORD PTR ds:0xc456c0
006d8722  0f57c9                             xorps  xmm1,xmm1
006d8725  dd05b056c500                       fld    QWORD PTR ds:0xc556b0
006d872b  8b3d3cb1fa00                       mov    edi,DWORD PTR ds:0xfab13c
006d8731  8b4704                             mov    eax,DWORD PTR [edi+0x4]
006d8734  0fb733                             movzx  esi,WORD PTR [ebx]
006d8737  8bc8                               mov    ecx,eax
006d8739  80791500                           cmp    BYTE PTR [ecx+0x15],0x0
006d873d  8bd7                               mov    edx,edi
006d873f  7514                               jne    0x6d8755
006d8741  39710c                             cmp    DWORD PTR [ecx+0xc],esi
006d8744  7305                               jae    0x6d874b
006d8746  8b4908                             mov    ecx,DWORD PTR [ecx+0x8]
006d8749  eb04                               jmp    0x6d874f
006d874b  8bd1                               mov    edx,ecx
006d874d  8b09                               mov    ecx,DWORD PTR [ecx]
006d874f  80791500                           cmp    BYTE PTR [ecx+0x15],0x0
006d8753  74ec                               je     0x6d8741
006d8755  8954241c                           mov    DWORD PTR [esp+0x1c],edx
006d8759  3bd7                               cmp    edx,edi
006d875b  740b                               je     0x6d8768
006d875d  3b720c                             cmp    esi,DWORD PTR [edx+0xc]
006d8760  7206                               jb     0x6d8768
006d8762  8d4c241c                           lea    ecx,[esp+0x1c]
006d8766  eb08                               jmp    0x6d8770
006d8768  897c243c                           mov    DWORD PTR [esp+0x3c],edi
006d876c  8d4c243c                           lea    ecx,[esp+0x3c]
006d8770  8b09                               mov    ecx,DWORD PTR [ecx]
006d8772  3bcf                               cmp    ecx,edi
006d8774  750a                               jne    0x6d8780
006d8776  c744241c00000000                   mov    DWORD PTR [esp+0x1c],0x0
006d877e  eb07                               jmp    0x6d8787
006d8780  8b4910                             mov    ecx,DWORD PTR [ecx+0x10]
006d8783  894c241c                           mov    DWORD PTR [esp+0x1c],ecx
006d8787  80781500                           cmp    BYTE PTR [eax+0x15],0x0
006d878b  0fb75302                           movzx  edx,WORD PTR [ebx+0x2]
006d878f  8bcf                               mov    ecx,edi
006d8791  7514                               jne    0x6d87a7
006d8793  39500c                             cmp    DWORD PTR [eax+0xc],edx
006d8796  7305                               jae    0x6d879d
006d8798  8b4008                             mov    eax,DWORD PTR [eax+0x8]
006d879b  eb04                               jmp    0x6d87a1
006d879d  8bc8                               mov    ecx,eax
006d879f  8b00                               mov    eax,DWORD PTR [eax]
006d87a1  80781500                           cmp    BYTE PTR [eax+0x15],0x0
006d87a5  74ec                               je     0x6d8793
006d87a7  894c2410                           mov    DWORD PTR [esp+0x10],ecx
006d87ab  3bcf                               cmp    ecx,edi
006d87ad  740b                               je     0x6d87ba
006d87af  3b510c                             cmp    edx,DWORD PTR [ecx+0xc]
006d87b2  7206                               jb     0x6d87ba
006d87b4  8d442410                           lea    eax,[esp+0x10]
006d87b8  eb08                               jmp    0x6d87c2
006d87ba  897c2438                           mov    DWORD PTR [esp+0x38],edi
006d87be  8d442438                           lea    eax,[esp+0x38]
006d87c2  8b00                               mov    eax,DWORD PTR [eax]
006d87c4  3bc7                               cmp    eax,edi
006d87c6  7504                               jne    0x6d87cc
006d87c8  33c9                               xor    ecx,ecx
006d87ca  eb03                               jmp    0x6d87cf
006d87cc  8b4810                             mov    ecx,DWORD PTR [eax+0x10]
006d87cf  837c241c00                         cmp    DWORD PTR [esp+0x1c],0x0
006d87d4  0f84b3010000                       je     0x6d898d
006d87da  85c9                               test   ecx,ecx
006d87dc  0f84ab010000                       je     0x6d898d
006d87e2  d94318                             fld    DWORD PTR [ebx+0x18]
006d87e5  d87314                             fdiv   DWORD PTR [ebx+0x14]
006d87e8  d95c2410                           fstp   DWORD PTR [esp+0x10]
006d87ec  d94304                             fld    DWORD PTR [ebx+0x4]
006d87ef  d9442410                           fld    DWORD PTR [esp+0x10]
006d87f3  d9c0                               fld    st(0)
006d87f5  deca                               fmulp  st(2),st
006d87f7  d9c9                               fxch   st(1)
006d87f9  d95c2420                           fstp   DWORD PTR [esp+0x20]
006d87fd  d94308                             fld    DWORD PTR [ebx+0x8]
006d8800  d8c9                               fmul   st,st(1)
006d8802  d95c2424                           fstp   DWORD PTR [esp+0x24]
006d8806  d9430c                             fld    DWORD PTR [ebx+0xc]
006d8809  d8c9                               fmul   st,st(1)
006d880b  d95c2428                           fstp   DWORD PTR [esp+0x28]
006d880f  d84b10                             fmul   DWORD PTR [ebx+0x10]
006d8812  d95c242c                           fstp   DWORD PTR [esp+0x2c]
006d8816  d9e8                               fld1
006d8818  d9442420                           fld    DWORD PTR [esp+0x20]
006d881c  dbf1                               fcomi  st,st(1)
006d881e  ddd9                               fstp   st(1)
006d8820  7209                               jb     0x6d882b
006d8822  ddd8                               fstp   st(0)
006d8824  beff000000                         mov    esi,0xff
006d8829  eb33                               jmp    0x6d885e
006d882b  0f2f4c2420                         comiss xmm1,DWORD PTR [esp+0x20]
006d8830  7206                               jb     0x6d8838
006d8832  ddd8                               fstp   st(0)
006d8834  33f6                               xor    esi,esi
006d8836  eb26                               jmp    0x6d885e
006d8838  d97c2410                           fnstcw WORD PTR [esp+0x10]
006d883c  0fb7442410                         movzx  eax,WORD PTR [esp+0x10]
006d8841  d8ca                               fmul   st,st(2)
006d8843  0d000c0000                         or     eax,0xc00
006d8848  89442414                           mov    DWORD PTR [esp+0x14],eax
006d884c  d8c1                               fadd   st,st(1)
006d884e  d96c2414                           fldcw  WORD PTR [esp+0x14]
006d8852  df7c2414                           fistp  QWORD PTR [esp+0x14]
006d8856  8b742414                           mov    esi,DWORD PTR [esp+0x14]
006d885a  d96c2410                           fldcw  WORD PTR [esp+0x10]
006d885e  f30f10442424                       movss  xmm0,DWORD PTR [esp+0x24]
006d8864  0f2fc2                             comiss xmm0,xmm2
006d8867  7207                               jb     0x6d8870
006d8869  bfff000000                         mov    edi,0xff
006d886e  eb33                               jmp    0x6d88a3
006d8870  0f2fc8                             comiss xmm1,xmm0
006d8873  7204                               jb     0x6d8879
006d8875  33ff                               xor    edi,edi
006d8877  eb2a                               jmp    0x6d88a3
006d8879  d9442424                           fld    DWORD PTR [esp+0x24]
006d887d  d97c2410                           fnstcw WORD PTR [esp+0x10]
006d8881  0fb7442410                         movzx  eax,WORD PTR [esp+0x10]
006d8886  d8ca                               fmul   st,st(2)
006d8888  0d000c0000                         or     eax,0xc00
006d888d  89442414                           mov    DWORD PTR [esp+0x14],eax
006d8891  d8c1                               fadd   st,st(1)
006d8893  d96c2414                           fldcw  WORD PTR [esp+0x14]
006d8897  df7c2414                           fistp  QWORD PTR [esp+0x14]
006d889b  8b7c2414                           mov    edi,DWORD PTR [esp+0x14]
006d889f  d96c2410                           fldcw  WORD PTR [esp+0x10]
006d88a3  f30f10442428                       movss  xmm0,DWORD PTR [esp+0x28]
006d88a9  0f2fc2                             comiss xmm0,xmm2
006d88ac  7207                               jb     0x6d88b5
006d88ae  baff000000                         mov    edx,0xff
006d88b3  eb33                               jmp    0x6d88e8
006d88b5  0f2fc8                             comiss xmm1,xmm0
006d88b8  7204                               jb     0x6d88be
006d88ba  33d2                               xor    edx,edx
006d88bc  eb2a                               jmp    0x6d88e8
006d88be  d9442428                           fld    DWORD PTR [esp+0x28]
006d88c2  d97c2410                           fnstcw WORD PTR [esp+0x10]
006d88c6  0fb7442410                         movzx  eax,WORD PTR [esp+0x10]
006d88cb  d8ca                               fmul   st,st(2)
006d88cd  0d000c0000                         or     eax,0xc00
006d88d2  89442414                           mov    DWORD PTR [esp+0x14],eax
006d88d6  d8c1                               fadd   st,st(1)
006d88d8  d96c2414                           fldcw  WORD PTR [esp+0x14]
006d88dc  df7c2414                           fistp  QWORD PTR [esp+0x14]
006d88e0  8b542414                           mov    edx,DWORD PTR [esp+0x14]
006d88e4  d96c2410                           fldcw  WORD PTR [esp+0x10]
006d88e8  f30f1044242c                       movss  xmm0,DWORD PTR [esp+0x2c]
006d88ee  0f2fc2                             comiss xmm0,xmm2
006d88f1  720b                               jb     0x6d88fe
006d88f3  ddd9                               fstp   st(1)
006d88f5  b8ff000000                         mov    eax,0xff
006d88fa  ddd8                               fstp   st(0)
006d88fc  eb37                               jmp    0x6d8935
006d88fe  0f2fc8                             comiss xmm1,xmm0
006d8901  7208                               jb     0x6d890b
006d8903  ddd9                               fstp   st(1)
006d8905  33c0                               xor    eax,eax
006d8907  ddd8                               fstp   st(0)
006d8909  eb2a                               jmp    0x6d8935
006d890b  d944242c                           fld    DWORD PTR [esp+0x2c]
006d890f  d97c2410                           fnstcw WORD PTR [esp+0x10]
006d8913  0fb7442410                         movzx  eax,WORD PTR [esp+0x10]
006d8918  deca                               fmulp  st(2),st
006d891a  0d000c0000                         or     eax,0xc00
006d891f  89442414                           mov    DWORD PTR [esp+0x14],eax
006d8923  dec1                               faddp  st(1),st
006d8925  d96c2414                           fldcw  WORD PTR [esp+0x14]
006d8929  df7c2414                           fistp  QWORD PTR [esp+0x14]
006d892d  8b442414                           mov    eax,DWORD PTR [esp+0x14]
006d8931  d96c2410                           fldcw  WORD PTR [esp+0x10]
006d8935  c1e008                             shl    eax,0x8
006d8938  0bc6                               or     eax,esi
006d893a  c1e008                             shl    eax,0x8
006d893d  0bc7                               or     eax,edi
006d893f  c1e008                             shl    eax,0x8
006d8942  0bc2                               or     eax,edx
006d8944  8b11                               mov    edx,DWORD PTR [ecx]
006d8946  8b5250                             mov    edx,DWORD PTR [edx+0x50]
006d8949  50                                 push   eax
006d894a  8d442444                           lea    eax,[esp+0x44]
006d894e  50                                 push   eax
006d894f  ffd2                               call   edx
006d8951  8b4c2420                           mov    ecx,DWORD PTR [esp+0x20]
006d8955  50                                 push   eax
006d8956  8b01                               mov    eax,DWORD PTR [ecx]
006d8958  8b4050                             mov    eax,DWORD PTR [eax+0x50]
006d895b  8d542454                           lea    edx,[esp+0x54]
006d895f  52                                 push   edx
006d8960  ffd0                               call   eax
006d8962  8b742438                           mov    esi,DWORD PTR [esp+0x38]
006d8966  8bf8                               mov    edi,eax
006d8968  e893420f00                         call   0x7ccc00
006d896d  dd058856c500                       fld    QWORD PTR ds:0xc55688
006d8973  8b3d3cb1fa00                       mov    edi,DWORD PTR ds:0xfab13c
006d8979  dd05b056c500                       fld    QWORD PTR ds:0xc556b0
006d897f  0f57c9                             xorps  xmm1,xmm1
006d8982  f30f1015c056c400                   movss  xmm2,DWORD PTR ds:0xc456c0
006d898a  83c408                             add    esp,0x8
006d898d  83c31c                             add    ebx,0x1c
006d8990  3b5c2434                           cmp    ebx,DWORD PTR [esp+0x34]
006d8994  0f8597fdffff                       jne    0x6d8731
006d899a  ddd9                               fstp   st(1)
006d899c  ddd8                               fstp   st(0)
006d899e  8b4c2460                           mov    ecx,DWORD PTR [esp+0x60]
006d89a2  64890d00000000                     mov    DWORD PTR fs:0x0,ecx
006d89a9  59                                 pop    ecx
006d89aa  5f                                 pop    edi
006d89ab  5e                                 pop    esi
006d89ac  5b                                 pop    ebx
006d89ad  8b4c2448                           mov    ecx,DWORD PTR [esp+0x48]
006d89b1  33cc                               xor    ecx,esp
006d89b3  e849861b00                         call   0x891001
006d89b8  8be5                               mov    esp,ebp
006d89ba  5d                                 pop    ebp
006d89bb  c3                                 ret
; update_prefix [0x492040,0x4928ad) rooted prefix至pair tick call返回；只判定既定主更新caller，不宣稱整個ClientLoop
00492040  55                                 push   ebp
00492041  8bec                               mov    ebp,esp
00492043  83e4f8                             and    esp,0xfffffff8
00492046  6aff                               push   0xffffffff
00492048  6856979400                         push   0x949756
0049204d  64a100000000                       mov    eax,fs:0x0
00492053  50                                 push   eax
00492054  83ec20                             sub    esp,0x20
00492057  53                                 push   ebx
00492058  56                                 push   esi
00492059  57                                 push   edi
0049205a  a1201fd600                         mov    eax,ds:0xd61f20
0049205f  33c4                               xor    eax,esp
00492061  50                                 push   eax
00492062  8d442430                           lea    eax,[esp+0x30]
00492066  64a300000000                       mov    fs:0x0,eax
0049206c  8b7d08                             mov    edi,DWORD PTR [ebp+0x8]
0049206f  83bf10c0000000                     cmp    DWORD PTR [edi+0xc010],0x0
00492076  7442                               je     0x4920ba
00492078  8b8708c00000                       mov    eax,DWORD PTR [edi+0xc008]
0049207e  8b9f04c00000                       mov    ebx,DWORD PTR [edi+0xc004]
00492084  8db704c00000                       lea    esi,[edi+0xc004]
0049208a  56                                 push   esi
0049208b  8944242c                           mov    DWORD PTR [esp+0x2c],eax
0049208f  ff157c24bd00                       call   DWORD PTR ds:0xbd247c
00492095  8b4708                             mov    eax,DWORD PTR [edi+0x8]
00492098  56                                 push   esi
00492099  50                                 push   eax
0049209a  ff158024bd00                       call   DWORD PTR ds:0xbd2480
004920a0  3b1e                               cmp    ebx,DWORD PTR [esi]
004920a2  750c                               jne    0x4920b0
004920a4  8b4c2428                           mov    ecx,DWORD PTR [esp+0x28]
004920a8  3b8f08c00000                       cmp    ecx,DWORD PTR [edi+0xc008]
004920ae  740a                               je     0x4920ba
004920b0  c7870cc0000001000000               mov    DWORD PTR [edi+0xc00c],0x1
004920ba  33f6                               xor    esi,esi
004920bc  39b70cc00000                       cmp    DWORD PTR [edi+0xc00c],esi
004920c2  0f84cd000000                       je     0x492195
004920c8  f605341afc0001                     test   BYTE PTR ds:0xfc1a34,0x1
004920cf  89b70cc00000                       mov    DWORD PTR [edi+0xc00c],esi
004920d5  7526                               jne    0x4920fd
004920d7  830d341afc0001                     or     DWORD PTR ds:0xfc1a34,0x1
004920de  89742438                           mov    DWORD PTR [esp+0x38],esi
004920e2  e829512a00                         call   0x737210
004920e7  6800e0bc00                         push   0xbce000
004920ec  e829024000                         call   0x89231a
004920f1  83c404                             add    esp,0x4
004920f4  83cbff                             or     ebx,0xffffffff
004920f7  895c2438                           mov    DWORD PTR [esp+0x38],ebx
004920fb  eb03                               jmp    0x492100
004920fd  83cbff                             or     ebx,0xffffffff
00492100  f6051c13fb0001                     test   BYTE PTR ds:0xfb131c,0x1
00492107  8b8708c00000                       mov    eax,DWORD PTR [edi+0xc008]
0049210d  8b9704c00000                       mov    edx,DWORD PTR [edi+0xc004]
00492113  89153c1afc00                       mov    DWORD PTR ds:0xfc1a3c,edx
00492119  a3401afc00                         mov    ds:0xfc1a40,eax
0049211e  7525                               jne    0x492145
00492120  b801000000                         mov    eax,0x1
00492125  09051c13fb00                       or     DWORD PTR ds:0xfb131c,eax
0049212b  89442438                           mov    DWORD PTR [esp+0x38],eax
0049212f  e88ced0d00                         call   0x570ec0
00492134  6850cfbc00                         push   0xbccf50
00492139  e8dc014000                         call   0x89231a
0049213e  83c404                             add    esp,0x4
00492141  895c2438                           mov    DWORD PTR [esp+0x38],ebx
00492145  8b0d2c13fb00                       mov    ecx,DWORD PTR ds:0xfb132c
0049214b  8b8708c00000                       mov    eax,DWORD PTR [edi+0xc008]
00492151  8bbf04c00000                       mov    edi,DWORD PTR [edi+0xc004]
00492157  3bce                               cmp    ecx,esi
00492159  740a                               je     0x492165
0049215b  8b11                               mov    edx,DWORD PTR [ecx]
0049215d  56                                 push   esi
0049215e  50                                 push   eax
0049215f  8b4224                             mov    eax,DWORD PTR [edx+0x24]
00492162  57                                 push   edi
00492163  ffd0                               call   eax
00492165  f6052cb2fa0001                     test   BYTE PTR ds:0xfab22c,0x1
0049216c  7558                               jne    0x4921c6
0049216e  830d2cb2fa0001                     or     DWORD PTR ds:0xfab22c,0x1
00492175  c744243802000000                   mov    DWORD PTR [esp+0x38],0x2
0049217d  e80ecb0400                         call   0x4dec90
00492182  6830cebc00                         push   0xbcce30
00492187  e88e014000                         call   0x89231a
0049218c  83c404                             add    esp,0x4
0049218f  895c2438                           mov    DWORD PTR [esp+0x38],ebx
00492193  eb03                               jmp    0x492198
00492195  83cbff                             or     ebx,0xffffffff
00492198  f6052cb2fa0001                     test   BYTE PTR ds:0xfab22c,0x1
0049219f  7525                               jne    0x4921c6
004921a1  830d2cb2fa0001                     or     DWORD PTR ds:0xfab22c,0x1
004921a8  c744243803000000                   mov    DWORD PTR [esp+0x38],0x3
004921b0  e8dbca0400                         call   0x4dec90
004921b5  6830cebc00                         push   0xbcce30
004921ba  e85b014000                         call   0x89231a
004921bf  83c404                             add    esp,0x4
004921c2  895c2438                           mov    DWORD PTR [esp+0x38],ebx
004921c6  f605d0adfa0001                     test   BYTE PTR ds:0xfaadd0,0x1
004921cd  8b3de4b1fa00                       mov    edi,DWORD PTR ds:0xfab1e4
004921d3  8935e4b1fa00                       mov    DWORD PTR ds:0xfab1e4,esi
004921d9  7525                               jne    0x492200
004921db  830dd0adfa0001                     or     DWORD PTR ds:0xfaadd0,0x1
004921e2  c744243804000000                   mov    DWORD PTR [esp+0x38],0x4
004921ea  e8a1b72b00                         call   0x74d990
004921ef  6870ccbc00                         push   0xbccc70
004921f4  e821014000                         call   0x89231a
004921f9  83c404                             add    esp,0x4
004921fc  895c2438                           mov    DWORD PTR [esp+0x38],ebx
00492200  8b35d05cf900                       mov    esi,DWORD PTR ds:0xf95cd0
00492206  85f6                               test   esi,esi
00492208  743e                               je     0x492248
0049220a  f605341afc0001                     test   BYTE PTR ds:0xfc1a34,0x1
00492211  7525                               jne    0x492238
00492213  830d341afc0001                     or     DWORD PTR ds:0xfc1a34,0x1
0049221a  c744243805000000                   mov    DWORD PTR [esp+0x38],0x5
00492222  e8e94f2a00                         call   0x737210
00492227  6800e0bc00                         push   0xbce000
0049222c  e8e9004000                         call   0x89231a
00492231  83c404                             add    esp,0x4
00492234  895c2438                           mov    DWORD PTR [esp+0x38],ebx
00492238  56                                 push   esi
00492239  be381afc00                         mov    esi,0xfc1a38
0049223e  e8ed572a00                         call   0x737a30
00492243  e912010000                         jmp    0x49235a
00492248  8b0da4a7fb00                       mov    ecx,DWORD PTR ds:0xfba7a4
0049224e  83797c00                           cmp    DWORD PTR [ecx+0x7c],0x0
00492252  0f8493000000                       je     0x4922eb
00492258  f605341afc0001                     test   BYTE PTR ds:0xfc1a34,0x1
0049225f  7525                               jne    0x492286
00492261  830d341afc0001                     or     DWORD PTR ds:0xfc1a34,0x1
00492268  c744243806000000                   mov    DWORD PTR [esp+0x38],0x6
00492270  e89b4f2a00                         call   0x737210
00492275  6800e0bc00                         push   0xbce000
0049227a  e89b004000                         call   0x89231a
0049227f  83c404                             add    esp,0x4
00492282  895c2438                           mov    DWORD PTR [esp+0x38],ebx
00492286  b864000000                         mov    eax,0x64
0049228b  89442410                           mov    DWORD PTR [esp+0x10],eax
0049228f  3905541afc00                       cmp    DWORD PTR ds:0xfc1a54,eax
00492295  0f84bf000000                       je     0x49235a
0049229b  8d542410                           lea    edx,[esp+0x10]
0049229f  a3541afc00                         mov    ds:0xfc1a54,eax
004922a4  52                                 push   edx
004922a5  8d442418                           lea    eax,[esp+0x18]
004922a9  b9441afc00                         mov    ecx,0xfc1a44
004922ae  c7055c1afc0001000000               mov    DWORD PTR ds:0xfc1a5c,0x1
004922b8  e803163b00                         call   0x8438c0
004922bd  8b442414                           mov    eax,DWORD PTR [esp+0x14]
004922c1  3b05481afc00                       cmp    eax,DWORD PTR ds:0xfc1a48
004922c7  740f                               je     0x4922d8
004922c9  8b4010                             mov    eax,DWORD PTR [eax+0x10]
004922cc  a3581afc00                         mov    ds:0xfc1a58,eax
004922d1  b8381afc00                         mov    eax,0xfc1a38
004922d6  eb7d                               jmp    0x492355
004922d8  33c0                               xor    eax,eax
004922da  a35c1afc00                         mov    ds:0xfc1a5c,eax
004922df  a3581afc00                         mov    ds:0xfc1a58,eax
004922e4  b8381afc00                         mov    eax,0xfc1a38
004922e9  eb6a                               jmp    0x492355
004922eb  85ff                               test   edi,edi
004922ed  741b                               je     0x49230a
004922ef  e84c0cf9ff                         call   0x422f40
004922f4  83782800                           cmp    DWORD PTR [eax+0x28],0x0
004922f8  7510                               jne    0x49230a
004922fa  6a66                               push   0x66
004922fc  e83f7fffff                         call   0x48a240
00492301  8bf0                               mov    esi,eax
00492303  e828572a00                         call   0x737a30
00492308  eb50                               jmp    0x49235a
0049230a  c744241400000000                   mov    DWORD PTR [esp+0x14],0x0
00492312  e8297fffff                         call   0x48a240
00492317  8bf0                               mov    esi,eax
00492319  837e1c00                           cmp    DWORD PTR [esi+0x1c],0x0
0049231d  743b                               je     0x49235a
0049231f  8d4c2414                           lea    ecx,[esp+0x14]
00492323  51                                 push   ecx
00492324  33ff                               xor    edi,edi
00492326  8d4e0c                             lea    ecx,[esi+0xc]
00492329  8d442414                           lea    eax,[esp+0x14]
0049232d  897e1c                             mov    DWORD PTR [esi+0x1c],edi
00492330  c7462401000000                     mov    DWORD PTR [esi+0x24],0x1
00492337  e884153b00                         call   0x8438c0
0049233c  8b4c2410                           mov    ecx,DWORD PTR [esp+0x10]
00492340  3b4e10                             cmp    ecx,DWORD PTR [esi+0x10]
00492343  7408                               je     0x49234d
00492345  8b5110                             mov    edx,DWORD PTR [ecx+0x10]
00492348  895620                             mov    DWORD PTR [esi+0x20],edx
0049234b  eb06                               jmp    0x492353
0049234d  897e24                             mov    DWORD PTR [esi+0x24],edi
00492350  897e20                             mov    DWORD PTR [esi+0x20],edi
00492353  8bc6                               mov    eax,esi
00492355  e8f6502a00                         call   0x737450
0049235a  f6055c12fc0001                     test   BYTE PTR ds:0xfc125c,0x1
00492361  7525                               jne    0x492388
00492363  830d5c12fc0001                     or     DWORD PTR ds:0xfc125c,0x1
0049236a  c744243807000000                   mov    DWORD PTR [esp+0x38],0x7
00492372  e8e94e3200                         call   0x7b7260
00492377  6850e6bc00                         push   0xbce650
0049237c  e899ff3f00                         call   0x89231a
00492381  83c404                             add    esp,0x4
00492384  895c2438                           mov    DWORD PTR [esp+0x38],ebx
00492388  d9450c                             fld    DWORD PTR [ebp+0xc]
0049238b  51                                 push   ecx
0049238c  bf6012fc00                         mov    edi,0xfc1260
00492391  d91c24                             fstp   DWORD PTR [esp]
00492394  e827543200                         call   0x7b77c0
00492399  f605f02cfd0001                     test   BYTE PTR ds:0xfd2cf0,0x1
004923a0  bf01000000                         mov    edi,0x1
004923a5  7518                               jne    0x4923bf
004923a7  093df02cfd00                       or     DWORD PTR ds:0xfd2cf0,edi
004923ad  e8de5c2a00                         call   0x738090
004923b2  6880e6bc00                         push   0xbce680
004923b7  e85eff3f00                         call   0x89231a
004923bc  83c404                             add    esp,0x4
004923bf  d9450c                             fld    DWORD PTR [ebp+0xc]
004923c2  51                                 push   ecx
004923c3  beb82bfd00                         mov    esi,0xfd2bb8
004923c8  d91c24                             fstp   DWORD PTR [esp]
004923cb  e8905d2a00                         call   0x738160
004923d0  833d34abfb0000                     cmp    DWORD PTR ds:0xfbab34,0x0
004923d7  750a                               jne    0x4923e3
004923d9  68f8aafb00                         push   0xfbaaf8
004923de  e83db00b00                         call   0x54d420
004923e3  f6051c76fb0001                     test   BYTE PTR ds:0xfb761c,0x1
004923ea  7524                               jne    0x492410
004923ec  093d1c76fb00                       or     DWORD PTR ds:0xfb761c,edi
004923f2  c744243808000000                   mov    DWORD PTR [esp+0x38],0x8
004923fa  e851c30b00                         call   0x54e750
004923ff  6860d2bc00                         push   0xbcd260
00492404  e811ff3f00                         call   0x89231a
00492409  83c404                             add    esp,0x4
0049240c  895c2438                           mov    DWORD PTR [esp+0x38],ebx
00492410  8b0d2076fb00                       mov    ecx,DWORD PTR ds:0xfb7620
00492416  85c9                               test   ecx,ecx
00492418  740e                               je     0x492428
0049241a  8b01                               mov    eax,DWORD PTR [ecx]
0049241c  d9450c                             fld    DWORD PTR [ebp+0xc]
0049241f  8b5010                             mov    edx,DWORD PTR [eax+0x10]
00492422  51                                 push   ecx
00492423  d91c24                             fstp   DWORD PTR [esp]
00492426  ffd2                               call   edx
00492428  f605f42cfd0001                     test   BYTE PTR ds:0xfd2cf4,0x1
0049242f  752c                               jne    0x49245d
00492431  093df42cfd00                       or     DWORD PTR ds:0xfd2cf4,edi
00492437  c705f82cfd00b46ec000               mov    DWORD PTR ds:0xfd2cf8,0xc06eb4
00492441  c705a48bfd0000000000               mov    DWORD PTR ds:0xfd8ba4,0x0
0049244b  e870590200                         call   0x4b7dc0
00492450  68f0dcbc00                         push   0xbcdcf0
00492455  e8c0fe3f00                         call   0x89231a
0049245a  83c404                             add    esp,0x4
0049245d  8b0da48bfd00                       mov    ecx,DWORD PTR ds:0xfd8ba4
00492463  85c9                               test   ecx,ecx
00492465  740e                               je     0x492475
00492467  8b01                               mov    eax,DWORD PTR [ecx]
00492469  d9450c                             fld    DWORD PTR [ebp+0xc]
0049246c  8b501c                             mov    edx,DWORD PTR [eax+0x1c]
0049246f  51                                 push   ecx
00492470  d91c24                             fstp   DWORD PTR [esp]
00492473  ffd2                               call   edx
00492475  f605e879fb0001                     test   BYTE PTR ds:0xfb79e8,0x1
0049247c  7524                               jne    0x4924a2
0049247e  093de879fb00                       or     DWORD PTR ds:0xfb79e8,edi
00492484  c744243809000000                   mov    DWORD PTR [esp+0x38],0x9
0049248c  e84f693000                         call   0x798de0
00492491  68e0d2bc00                         push   0xbcd2e0
00492496  e87ffe3f00                         call   0x89231a
0049249b  83c404                             add    esp,0x4
0049249e  895c2438                           mov    DWORD PTR [esp+0x38],ebx
004924a2  8b3de876fb00                       mov    edi,DWORD PTR ds:0xfb76e8
004924a8  e8135a3000                         call   0x797ec0
004924ad  f605b873fb0001                     test   BYTE PTR ds:0xfb73b8,0x1
004924b4  bf01000000                         mov    edi,0x1
004924b9  7524                               jne    0x4924df
004924bb  093db873fb00                       or     DWORD PTR ds:0xfb73b8,edi
004924c1  c74424380a000000                   mov    DWORD PTR [esp+0x38],0xa
004924c9  e8a2dc0c00                         call   0x560170
004924ce  6810d1bc00                         push   0xbcd110
004924d3  e842fe3f00                         call   0x89231a
004924d8  83c404                             add    esp,0x4
004924db  895c2438                           mov    DWORD PTR [esp+0x38],ebx
004924df  d9450c                             fld    DWORD PTR [ebp+0xc]
004924e2  51                                 push   ecx
004924e3  b8c073fb00                         mov    eax,0xfb73c0
004924e8  d91c24                             fstp   DWORD PTR [esp]
004924eb  e890f10c00                         call   0x561680
004924f0  f6054492fd0001                     test   BYTE PTR ds:0xfd9244,0x1
004924f7  7524                               jne    0x49251d
004924f9  093d4492fd00                       or     DWORD PTR ds:0xfd9244,edi
004924ff  c74424380b000000                   mov    DWORD PTR [esp+0x38],0xb
00492507  e8041f0c00                         call   0x554410
0049250c  68c0dfbc00                         push   0xbcdfc0
00492511  e804fe3f00                         call   0x89231a
00492516  83c404                             add    esp,0x4
00492519  895c2438                           mov    DWORD PTR [esp+0x38],ebx
0049251d  d9450c                             fld    DWORD PTR [ebp+0xc]
00492520  51                                 push   ecx
00492521  be4892fd00                         mov    esi,0xfd9248
00492526  d91c24                             fstp   DWORD PTR [esp]
00492529  e8821f0c00                         call   0x5544b0
0049252e  f605e879fb0001                     test   BYTE PTR ds:0xfb79e8,0x1
00492535  7524                               jne    0x49255b
00492537  093de879fb00                       or     DWORD PTR ds:0xfb79e8,edi
0049253d  c74424380c000000                   mov    DWORD PTR [esp+0x38],0xc
00492545  e896683000                         call   0x798de0
0049254a  68e0d2bc00                         push   0xbcd2e0
0049254f  e8c6fd3f00                         call   0x89231a
00492554  83c404                             add    esp,0x4
00492557  895c2438                           mov    DWORD PTR [esp+0x38],ebx
0049255b  d9450c                             fld    DWORD PTR [ebp+0xc]
0049255e  51                                 push   ecx
0049255f  d91c24                             fstp   DWORD PTR [esp]
00492562  68a876fb00                         push   0xfb76a8
00492567  e8b4773000                         call   0x799d20
0049256c  f6052cb2fa0001                     test   BYTE PTR ds:0xfab22c,0x1
00492573  7524                               jne    0x492599
00492575  093d2cb2fa00                       or     DWORD PTR ds:0xfab22c,edi
0049257b  c74424380d000000                   mov    DWORD PTR [esp+0x38],0xd
00492583  e808c70400                         call   0x4dec90
00492588  6830cebc00                         push   0xbcce30
0049258d  e888fd3f00                         call   0x89231a
00492592  83c404                             add    esp,0x4
00492595  895c2438                           mov    DWORD PTR [esp+0x38],ebx
00492599  d9450c                             fld    DWORD PTR [ebp+0xc]
0049259c  51                                 push   ecx
0049259d  d91c24                             fstp   DWORD PTR [esp]
004925a0  6830b1fa00                         push   0xfab130
004925a5  e856dc0400                         call   0x4e0200
004925aa  f605f093fd0001                     test   BYTE PTR ds:0xfd93f0,0x1
004925b1  89442418                           mov    DWORD PTR [esp+0x18],eax
004925b5  7524                               jne    0x4925db
004925b7  093df093fd00                       or     DWORD PTR ds:0xfd93f0,edi
004925bd  c74424380e000000                   mov    DWORD PTR [esp+0x38],0xe
004925c5  e8168f3100                         call   0x7ab4e0
004925ca  68a0e6bc00                         push   0xbce6a0
004925cf  e846fd3f00                         call   0x89231a
004925d4  83c404                             add    esp,0x4
004925d7  895c2438                           mov    DWORD PTR [esp+0x38],ebx
004925db  d9450c                             fld    DWORD PTR [ebp+0xc]
004925de  51                                 push   ecx
004925df  d91c24                             fstp   DWORD PTR [esp]
004925e2  68a092fd00                         push   0xfd92a0
004925e7  e8449c3100                         call   0x7ac230
004925ec  f605dcf6fd0001                     test   BYTE PTR ds:0xfdf6dc,0x1
004925f3  7524                               jne    0x492619
004925f5  093ddcf6fd00                       or     DWORD PTR ds:0xfdf6dc,edi
004925fb  c74424380f000000                   mov    DWORD PTR [esp+0x38],0xf
00492603  e818e20b00                         call   0x550820
00492608  68b0e6bc00                         push   0xbce6b0
0049260d  e808fd3f00                         call   0x89231a
00492612  83c404                             add    esp,0x4
00492615  895c2438                           mov    DWORD PTR [esp+0x38],ebx
00492619  d9450c                             fld    DWORD PTR [ebp+0xc]
0049261c  51                                 push   ecx
0049261d  d91c24                             fstp   DWORD PTR [esp]
00492620  6880f6fd00                         push   0xfdf680
00492625  e846e90b00                         call   0x550f70
0049262a  f605c0f3fd0001                     test   BYTE PTR ds:0xfdf3c0,0x1
00492631  751d                               jne    0x492650
00492633  093dc0f3fd00                       or     DWORD PTR ds:0xfdf3c0,edi
00492639  6850dfbc00                         push   0xbcdf50
0049263e  c705c4f3fd0000000000               mov    DWORD PTR ds:0xfdf3c4,0x0
00492648  e8cdfc3f00                         call   0x89231a
0049264d  83c404                             add    esp,0x4
00492650  a1c4f3fd00                         mov    eax,ds:0xfdf3c4
00492655  50                                 push   eax
00492656  e8d5ca0d00                         call   0x56f130
0049265b  f605a88efd0001                     test   BYTE PTR ds:0xfd8ea8,0x1
00492662  7524                               jne    0x492688
00492664  093da88efd00                       or     DWORD PTR ds:0xfd8ea8,edi
0049266a  c744243810000000                   mov    DWORD PTR [esp+0x38],0x10
00492672  e899850c00                         call   0x55ac10
00492677  68e0dfbc00                         push   0xbcdfe0
0049267c  e899fc3f00                         call   0x89231a
00492681  83c404                             add    esp,0x4
00492684  895c2438                           mov    DWORD PTR [esp+0x38],ebx
00492688  8b1db08efd00                       mov    ebx,DWORD PTR ds:0xfd8eb0
0049268e  8b3b                               mov    edi,DWORD PTR [ebx]
00492690  3bfb                               cmp    edi,ebx
00492692  7412                               je     0x4926a6
00492694  8b7708                             mov    esi,DWORD PTR [edi+0x8]
00492697  8d4e3c                             lea    ecx,[esi+0x3c]
0049269a  51                                 push   ecx
0049269b  e8e07a0c00                         call   0x55a180
004926a0  8b3f                               mov    edi,DWORD PTR [edi]
004926a2  3bfb                               cmp    edi,ebx
004926a4  75ee                               jne    0x492694
004926a6  d9450c                             fld    DWORD PTR [ebp+0xc]
004926a9  51                                 push   ecx
004926aa  d91c24                             fstp   DWORD PTR [esp]
004926ad  e85e79ffff                         call   0x48a010
004926b2  8bd0                               mov    edx,eax
004926b4  e8b7baf8ff                         call   0x41e170
004926b9  8b0da4a7fb00                       mov    ecx,DWORD PTR ds:0xfba7a4
004926bf  33ff                               xor    edi,edi
004926c1  39797c                             cmp    DWORD PTR [ecx+0x7c],edi
004926c4  0f8418010000                       je     0x4927e2
004926ca  8b11                               mov    edx,DWORD PTR [ecx]
004926cc  8b4220                             mov    eax,DWORD PTR [edx+0x20]
004926cf  ffd0                               call   eax
004926d1  85c0                               test   eax,eax
004926d3  0f8409010000                       je     0x4927e2
004926d9  8b0da4a7fb00                       mov    ecx,DWORD PTR ds:0xfba7a4
004926df  8b11                               mov    edx,DWORD PTR [ecx]
004926e1  8b4220                             mov    eax,DWORD PTR [edx+0x20]
004926e4  ffd0                               call   eax
004926e6  8b10                               mov    edx,DWORD PTR [eax]
004926e8  8bc8                               mov    ecx,eax
004926ea  8b424c                             mov    eax,DWORD PTR [edx+0x4c]
004926ed  ffd0                               call   eax
004926ef  f605e879fb0001                     test   BYTE PTR ds:0xfb79e8,0x1
004926f6  8bf0                               mov    esi,eax
004926f8  752a                               jne    0x492724
004926fa  830de879fb0001                     or     DWORD PTR ds:0xfb79e8,0x1
00492701  c744243811000000                   mov    DWORD PTR [esp+0x38],0x11
00492709  e8d2663000                         call   0x798de0
0049270e  68e0d2bc00                         push   0xbcd2e0
00492713  e802fc3f00                         call   0x89231a
00492718  83c404                             add    esp,0x4
0049271b  83cbff                             or     ebx,0xffffffff
0049271e  895c2438                           mov    DWORD PTR [esp+0x38],ebx
00492722  eb03                               jmp    0x492727
00492724  83cbff                             or     ebx,0xffffffff
00492727  56                                 push   esi
00492728  68a876fb00                         push   0xfb76a8
0049272d  8d7c242c                           lea    edi,[esp+0x2c]
00492731  e87a7f3000                         call   0x79a6b0
00492736  8b7508                             mov    esi,DWORD PTR [ebp+0x8]
00492739  db8604c00000                       fild   DWORD PTR [esi+0xc004]
0049273f  8d4c241c                           lea    ecx,[esp+0x1c]
00492743  51                                 push   ecx
00492744  8bd1                               mov    edx,ecx
00492746  d95c2418                           fstp   DWORD PTR [esp+0x18]
0049274a  52                                 push   edx
0049274b  db8608c00000                       fild   DWORD PTR [esi+0xc008]
00492751  d95c2418                           fstp   DWORD PTR [esp+0x18]
00492755  d944241c                           fld    DWORD PTR [esp+0x1c]
00492759  d864242c                           fsub   DWORD PTR [esp+0x2c]
0049275d  d95c241c                           fstp   DWORD PTR [esp+0x1c]
00492761  d9442418                           fld    DWORD PTR [esp+0x18]
00492765  d8642430                           fsub   DWORD PTR [esp+0x30]
00492769  d95c2418                           fstp   DWORD PTR [esp+0x18]
0049276d  d944241c                           fld    DWORD PTR [esp+0x1c]
00492771  d95c2424                           fstp   DWORD PTR [esp+0x24]
00492775  d9442418                           fld    DWORD PTR [esp+0x18]
00492779  d95c2428                           fstp   DWORD PTR [esp+0x28]
0049277d  ff15f825bd00                       call   DWORD PTR ds:0xbd25f8
00492783  d9442420                           fld    DWORD PTR [esp+0x20]
00492787  d944241c                           fld    DWORD PTR [esp+0x1c]
0049278b  e83ac64600                         call   0x8fedca
00492790  d95c2414                           fstp   DWORD PTR [esp+0x14]
00492794  f605341afc0001                     test   BYTE PTR ds:0xfc1a34,0x1
0049279b  d9442414                           fld    DWORD PTR [esp+0x14]
0049279f  dc052858c500                       fadd   QWORD PTR ds:0xc55828
004927a5  d95c2414                           fstp   DWORD PTR [esp+0x14]
004927a9  7525                               jne    0x4927d0
004927ab  830d341afc0001                     or     DWORD PTR ds:0xfc1a34,0x1
004927b2  c744243812000000                   mov    DWORD PTR [esp+0x38],0x12
004927ba  e8514a2a00                         call   0x737210
004927bf  6800e0bc00                         push   0xbce000
004927c4  e851fb3f00                         call   0x89231a
004927c9  83c404                             add    esp,0x4
004927cc  895c2438                           mov    DWORD PTR [esp+0x38],ebx
004927d0  f30f10442414                       movss  xmm0,DWORD PTR [esp+0x14]
004927d6  f30f1105681afc00                   movss  DWORD PTR ds:0xfc1a68,xmm0
004927de  33ff                               xor    edi,edi
004927e0  eb06                               jmp    0x4927e8
004927e2  8b7508                             mov    esi,DWORD PTR [ebp+0x8]
004927e5  83cbff                             or     ebx,0xffffffff
004927e8  f605f41bfc0001                     test   BYTE PTR ds:0xfc1bf4,0x1
004927ef  7525                               jne    0x492816
004927f1  830df41bfc0001                     or     DWORD PTR ds:0xfc1bf4,0x1
004927f8  c744243813000000                   mov    DWORD PTR [esp+0x38],0x13
00492800  e88bc70e00                         call   0x57ef90
00492805  68b0dfbc00                         push   0xbcdfb0
0049280a  e80bfb3f00                         call   0x89231a
0049280f  83c404                             add    esp,0x4
00492812  895c2438                           mov    DWORD PTR [esp+0x38],ebx
00492816  d9450c                             fld    DWORD PTR [ebp+0xc]
00492819  51                                 push   ecx
0049281a  d91c24                             fstp   DWORD PTR [esp]
0049281d  68f81bfc00                         push   0xfc1bf8
00492822  e819d20e00                         call   0x57fa40
00492827  f6051c13fb0001                     test   BYTE PTR ds:0xfb131c,0x1
0049282e  7525                               jne    0x492855
00492830  830d1c13fb0001                     or     DWORD PTR ds:0xfb131c,0x1
00492837  c744243814000000                   mov    DWORD PTR [esp+0x38],0x14
0049283f  e87ce60d00                         call   0x570ec0
00492844  6850cfbc00                         push   0xbccf50
00492849  e8ccfa3f00                         call   0x89231a
0049284e  83c404                             add    esp,0x4
00492851  895c2438                           mov    DWORD PTR [esp+0x38],ebx
00492855  8b0d2c13fb00                       mov    ecx,DWORD PTR ds:0xfb132c
0049285b  3bcf                               cmp    ecx,edi
0049285d  740e                               je     0x49286d
0049285f  8b01                               mov    eax,DWORD PTR [ecx]
00492861  d9450c                             fld    DWORD PTR [ebp+0xc]
00492864  8b5018                             mov    edx,DWORD PTR [eax+0x18]
00492867  51                                 push   ecx
00492868  d91c24                             fstp   DWORD PTR [esp]
0049286b  ffd2                               call   edx
0049286d  f6057492fd0001                     test   BYTE PTR ds:0xfd9274,0x1
00492874  7526                               jne    0x49289c
00492876  830d7492fd0001                     or     DWORD PTR ds:0xfd9274,0x1
0049287d  68d0e2bc00                         push   0xbce2d0
00492882  893d7892fd00                       mov    DWORD PTR ds:0xfd9278,edi
00492888  893d7c92fd00                       mov    DWORD PTR ds:0xfd927c,edi
0049288e  893d8092fd00                       mov    DWORD PTR ds:0xfd9280,edi
00492894  e881fa3f00                         call   0x89231a
00492899  83c404                             add    esp,0x4
0049289c  d9450c                             fld    DWORD PTR [ebp+0xc]
0049289f  51                                 push   ecx
004928a0  d91c24                             fstp   DWORD PTR [esp]
004928a3  687892fd00                         push   0xfd9278
004928a8  e8d35b2400                         call   0x6d8480
; draw_prefix [0x492900,0x492ec2) rooted prefix至pair draw call返回；只判定既定繪圖caller
00492900  55                                 push   ebp
00492901  8bec                               mov    ebp,esp
00492903  83e4f8                             and    esp,0xfffffff8
00492906  6aff                               push   0xffffffff
00492908  6810969400                         push   0x949610
0049290d  64a100000000                       mov    eax,fs:0x0
00492913  50                                 push   eax
00492914  83ec08                             sub    esp,0x8
00492917  53                                 push   ebx
00492918  56                                 push   esi
00492919  57                                 push   edi
0049291a  a1201fd600                         mov    eax,ds:0xd61f20
0049291f  33c4                               xor    eax,esp
00492921  50                                 push   eax
00492922  8d442418                           lea    eax,[esp+0x18]
00492926  64a300000000                       mov    fs:0x0,eax
0049292c  8b5d08                             mov    ebx,DWORD PTR [ebp+0x8]
0049292f  83bbccbf000000                     cmp    DWORD PTR [ebx+0xbfcc],0x0
00492936  7425                               je     0x49295d
00492938  8b4310                             mov    eax,DWORD PTR [ebx+0x10]
0049293b  d9e8                               fld1
0049293d  8b08                               mov    ecx,DWORD PTR [eax]
0049293f  8b91ac000000                       mov    edx,DWORD PTR [ecx+0xac]
00492945  6a00                               push   0x0
00492947  51                                 push   ecx
00492948  d91c24                             fstp   DWORD PTR [esp]
0049294b  6a00                               push   0x0
0049294d  6a03                               push   0x3
0049294f  6a00                               push   0x0
00492951  6a00                               push   0x0
00492953  50                                 push   eax
00492954  ffd2                               call   edx
00492956  bf01000000                         mov    edi,0x1
0049295b  eb60                               jmp    0x4929bd
0049295d  f605e879fb0001                     test   BYTE PTR ds:0xfb79e8,0x1
00492964  bf01000000                         mov    edi,0x1
00492969  7528                               jne    0x492993
0049296b  093de879fb00                       or     DWORD PTR ds:0xfb79e8,edi
00492971  c744242000000000                   mov    DWORD PTR [esp+0x20],0x0
00492979  e862643000                         call   0x798de0
0049297e  68e0d2bc00                         push   0xbcd2e0
00492983  e892f93f00                         call   0x89231a
00492988  83c404                             add    esp,0x4
0049298b  c7442420ffffffff                   mov    DWORD PTR [esp+0x20],0xffffffff
00492993  68a876fb00                         push   0xfb76a8
00492998  e8537c3000                         call   0x79a5f0
0049299d  d9e8                               fld1
0049299f  8b08                               mov    ecx,DWORD PTR [eax]
004929a1  8b15a479fb00                       mov    edx,DWORD PTR ds:0xfb79a4
004929a7  6a00                               push   0x0
004929a9  51                                 push   ecx
004929aa  d91c24                             fstp   DWORD PTR [esp]
004929ad  52                                 push   edx
004929ae  6a07                               push   0x7
004929b0  6a00                               push   0x0
004929b2  6a00                               push   0x0
004929b4  50                                 push   eax
004929b5  8b81ac000000                       mov    eax,DWORD PTR [ecx+0xac]
004929bb  ffd0                               call   eax
004929bd  8b4310                             mov    eax,DWORD PTR [ebx+0x10]
004929c0  8b08                               mov    ecx,DWORD PTR [eax]
004929c2  8b91a4000000                       mov    edx,DWORD PTR [ecx+0xa4]
004929c8  50                                 push   eax
004929c9  ffd2                               call   edx
004929cb  8bf0                               mov    esi,eax
004929cd  85f6                               test   esi,esi
004929cf  0f88c6060000                       js     0x49309b
004929d5  83bbccbf000000                     cmp    DWORD PTR [ebx+0xbfcc],0x0
004929dc  7451                               je     0x492a2f
004929de  8b8350bf0000                       mov    eax,DWORD PTR [ebx+0xbf50]
004929e4  8b08                               mov    ecx,DWORD PTR [eax]
004929e6  8b5120                             mov    edx,DWORD PTR [ecx+0x20]
004929e9  6a10                               push   0x10
004929eb  50                                 push   eax
004929ec  ffd2                               call   edx
004929ee  85c0                               test   eax,eax
004929f0  781a                               js     0x492a0c
004929f2  e8f971ffff                         call   0x489bf0
004929f7  8bf0                               mov    esi,eax
004929f9  e852290c00                         call   0x555350
004929fe  8b8350bf0000                       mov    eax,DWORD PTR [ebx+0xbf50]
00492a04  8b08                               mov    ecx,DWORD PTR [eax]
00492a06  8b512c                             mov    edx,DWORD PTR [ecx+0x2c]
00492a09  50                                 push   eax
00492a0a  ffd2                               call   edx
00492a0c  8b4310                             mov    eax,DWORD PTR [ebx+0x10]
00492a0f  8b08                               mov    ecx,DWORD PTR [eax]
00492a11  8b91a8000000                       mov    edx,DWORD PTR [ecx+0xa8]
00492a17  50                                 push   eax
00492a18  ffd2                               call   edx
00492a1a  8b4c2418                           mov    ecx,DWORD PTR [esp+0x18]
00492a1e  64890d00000000                     mov    DWORD PTR fs:0x0,ecx
00492a25  59                                 pop    ecx
00492a26  5f                                 pop    edi
00492a27  5e                                 pop    esi
00492a28  5b                                 pop    ebx
00492a29  8be5                               mov    esp,ebp
00492a2b  5d                                 pop    ebp
00492a2c  c20400                             ret    0x4
00492a2f  f605f4f6fd0001                     test   BYTE PTR ds:0xfdf6f4,0x1
00492a36  7517                               jne    0x492a4f
00492a38  093df4f6fd00                       or     DWORD PTR ds:0xfdf6f4,edi
00492a3e  897c2420                           mov    DWORD PTR [esp+0x20],edi
00492a42  e8498a0000                         call   0x49b490
00492a47  c7442420ffffffff                   mov    DWORD PTR [esp+0x20],0xffffffff
00492a4f  f605d848fe0001                     test   BYTE PTR ds:0xfe48d8,0x1
00492a56  750b                               jne    0x492a63
00492a58  093dd848fe00                       or     DWORD PTR ds:0xfe48d8,edi
00492a5e  e8ad880000                         call   0x49b310
00492a63  be3037fe00                         mov    esi,0xfe3730
00492a68  e8a3890000                         call   0x49b410
00492a6d  f6052888fb0001                     test   BYTE PTR ds:0xfb8828,0x1
00492a74  7528                               jne    0x492a9e
00492a76  093d2888fb00                       or     DWORD PTR ds:0xfb8828,edi
00492a7c  c744242002000000                   mov    DWORD PTR [esp+0x20],0x2
00492a84  e8c7cd0b00                         call   0x54f850
00492a89  6880d5bc00                         push   0xbcd580
00492a8e  e887f83f00                         call   0x89231a
00492a93  83c404                             add    esp,0x4
00492a96  c7442420ffffffff                   mov    DWORD PTR [esp+0x20],0xffffffff
00492a9e  8bb3dcbf0000                       mov    esi,DWORD PTR [ebx+0xbfdc]
00492aa4  33c0                               xor    eax,eax
00492aa6  3805f990fb00                       cmp    BYTE PTR ds:0xfb90f9,al
00492aac  0f95c0                             setne  al
00492aaf  8bf8                               mov    edi,eax
00492ab1  3b7e1c                             cmp    edi,DWORD PTR [esi+0x1c]
00492ab4  740e                               je     0x492ac4
00492ab6  837e2000                           cmp    DWORD PTR [esi+0x20],0x0
00492aba  897e1c                             mov    DWORD PTR [esi+0x1c],edi
00492abd  7505                               jne    0x492ac4
00492abf  e85c362400                         call   0x6d6120
00492ac4  8b83dcbf0000                       mov    eax,DWORD PTR [ebx+0xbfdc]
00492aca  8b4818                             mov    ecx,DWORD PTR [eax+0x18]
00492acd  8b11                               mov    edx,DWORD PTR [ecx]
00492acf  8b4218                             mov    eax,DWORD PTR [edx+0x18]
00492ad2  ffd0                               call   eax
00492ad4  f605e879fb0001                     test   BYTE PTR ds:0xfb79e8,0x1
00492adb  bf01000000                         mov    edi,0x1
00492ae0  7529                               jne    0x492b0b
00492ae2  093de879fb00                       or     DWORD PTR ds:0xfb79e8,edi
00492ae8  c744242003000000                   mov    DWORD PTR [esp+0x20],0x3
00492af0  e8eb623000                         call   0x798de0
00492af5  68e0d2bc00                         push   0xbcd2e0
00492afa  e81bf83f00                         call   0x89231a
00492aff  83c404                             add    esp,0x4
00492b02  83cbff                             or     ebx,0xffffffff
00492b05  895c2420                           mov    DWORD PTR [esp+0x20],ebx
00492b09  eb03                               jmp    0x492b0e
00492b0b  83cbff                             or     ebx,0xffffffff
00492b0e  68ec76fb00                         push   0xfb76ec
00492b13  ff154c22bd00                       call   DWORD PTR ds:0xbd224c
00492b19  e842c5f7ff                         call   0x40f060
00492b1e  8bf0                               mov    esi,eax
00492b20  e81bda0400                         call   0x4e0540
00492b25  f605b873fb0001                     test   BYTE PTR ds:0xfb73b8,0x1
00492b2c  7524                               jne    0x492b52
00492b2e  093db873fb00                       or     DWORD PTR ds:0xfb73b8,edi
00492b34  c744242004000000                   mov    DWORD PTR [esp+0x20],0x4
00492b3c  e82fd60c00                         call   0x560170
00492b41  6810d1bc00                         push   0xbcd110
00492b46  e8cff73f00                         call   0x89231a
00492b4b  83c404                             add    esp,0x4
00492b4e  895c2420                           mov    DWORD PTR [esp+0x20],ebx
00492b52  b8c073fb00                         mov    eax,0xfb73c0
00492b57  e894eb0c00                         call   0x5616f0
00492b5c  e84f71ffff                         call   0x489cb0
00492b61  83b8ac5e000000                     cmp    DWORD PTR [eax+0x5eac],0x0
00492b68  740d                               je     0x492b77
00492b6a  8b88ac5e0000                       mov    ecx,DWORD PTR [eax+0x5eac]
00492b70  8b11                               mov    edx,DWORD PTR [ecx]
00492b72  8b4220                             mov    eax,DWORD PTR [edx+0x20]
00492b75  ffd0                               call   eax
00492b77  f605f093fd0001                     test   BYTE PTR ds:0xfd93f0,0x1
00492b7e  7524                               jne    0x492ba4
00492b80  093df093fd00                       or     DWORD PTR ds:0xfd93f0,edi
00492b86  c744242005000000                   mov    DWORD PTR [esp+0x20],0x5
00492b8e  e84d893100                         call   0x7ab4e0
00492b93  68a0e6bc00                         push   0xbce6a0
00492b98  e87df73f00                         call   0x89231a
00492b9d  83c404                             add    esp,0x4
00492ba0  895c2420                           mov    DWORD PTR [esp+0x20],ebx
00492ba4  a1a092fd00                         mov    eax,ds:0xfd92a0
00492ba9  8b30                               mov    esi,DWORD PTR [eax]
00492bab  3bf0                               cmp    esi,eax
00492bad  7415                               je     0x492bc4
00492baf  90                                 nop
00492bb0  8b4e08                             mov    ecx,DWORD PTR [esi+0x8]
00492bb3  8b11                               mov    edx,DWORD PTR [ecx]
00492bb5  8b4208                             mov    eax,DWORD PTR [edx+0x8]
00492bb8  ffd0                               call   eax
00492bba  8b36                               mov    esi,DWORD PTR [esi]
00492bbc  3b35a092fd00                       cmp    esi,DWORD PTR ds:0xfd92a0
00492bc2  75ec                               jne    0x492bb0
00492bc4  f605dcf6fd0001                     test   BYTE PTR ds:0xfdf6dc,0x1
00492bcb  7524                               jne    0x492bf1
00492bcd  093ddcf6fd00                       or     DWORD PTR ds:0xfdf6dc,edi
00492bd3  c744242006000000                   mov    DWORD PTR [esp+0x20],0x6
00492bdb  e840dc0b00                         call   0x550820
00492be0  68b0e6bc00                         push   0xbce6b0
00492be5  e830f73f00                         call   0x89231a
00492bea  83c404                             add    esp,0x4
00492bed  895c2420                           mov    DWORD PTR [esp+0x20],ebx
00492bf1  a184f6fd00                         mov    eax,ds:0xfdf684
00492bf6  8b30                               mov    esi,DWORD PTR [eax]
00492bf8  8bf8                               mov    edi,eax
00492bfa  3bf7                               cmp    esi,edi
00492bfc  7418                               je     0x492c16
00492bfe  8bff                               mov    edi,edi
00492c00  8b4608                             mov    eax,DWORD PTR [esi+0x8]
00492c03  8b4024                             mov    eax,DWORD PTR [eax+0x24]
00492c06  85c0                               test   eax,eax
00492c08  7406                               je     0x492c10
00492c0a  50                                 push   eax
00492c0b  e830b33200                         call   0x7bdf40
00492c10  8b36                               mov    esi,DWORD PTR [esi]
00492c12  3bf7                               cmp    esi,edi
00492c14  75ea                               jne    0x492c00
00492c16  f6055c12fc0001                     test   BYTE PTR ds:0xfc125c,0x1
00492c1d  7525                               jne    0x492c44
00492c1f  830d5c12fc0001                     or     DWORD PTR ds:0xfc125c,0x1
00492c26  c744242007000000                   mov    DWORD PTR [esp+0x20],0x7
00492c2e  e82d463200                         call   0x7b7260
00492c33  6850e6bc00                         push   0xbce650
00492c38  e8ddf63f00                         call   0x89231a
00492c3d  83c404                             add    esp,0x4
00492c40  895c2420                           mov    DWORD PTR [esp+0x20],ebx
00492c44  33f6                               xor    esi,esi
00492c46  39358816fc00                       cmp    DWORD PTR ds:0xfc1688,esi
00492c4c  7e19                               jle    0x492c67
00492c4e  8bff                               mov    edi,edi
00492c50  8b0cb58812fc00                     mov    ecx,DWORD PTR [esi*4+0xfc1288]
00492c57  8b11                               mov    edx,DWORD PTR [ecx]
00492c59  8b4208                             mov    eax,DWORD PTR [edx+0x8]
00492c5c  ffd0                               call   eax
00492c5e  46                                 inc    esi
00492c5f  3b358816fc00                       cmp    esi,DWORD PTR ds:0xfc1688
00492c65  7ce9                               jl     0x492c50
00492c67  f605f41bfc0001                     test   BYTE PTR ds:0xfc1bf4,0x1
00492c6e  bb08000000                         mov    ebx,0x8
00492c73  7526                               jne    0x492c9b
00492c75  830df41bfc0001                     or     DWORD PTR ds:0xfc1bf4,0x1
00492c7c  895c2420                           mov    DWORD PTR [esp+0x20],ebx
00492c80  e80bc30e00                         call   0x57ef90
00492c85  68b0dfbc00                         push   0xbcdfb0
00492c8a  e88bf63f00                         call   0x89231a
00492c8f  83c404                             add    esp,0x4
00492c92  83cfff                             or     edi,0xffffffff
00492c95  897c2420                           mov    DWORD PTR [esp+0x20],edi
00492c99  eb03                               jmp    0x492c9e
00492c9b  83cfff                             or     edi,0xffffffff
00492c9e  833d6c1cfc0000                     cmp    DWORD PTR ds:0xfc1c6c,0x0
00492ca5  7411                               je     0x492cb8
00492ca7  8b0d4c1cfc00                       mov    ecx,DWORD PTR ds:0xfc1c4c
00492cad  85c9                               test   ecx,ecx
00492caf  7407                               je     0x492cb8
00492cb1  8b11                               mov    edx,DWORD PTR [ecx]
00492cb3  8b4210                             mov    eax,DWORD PTR [edx+0x10]
00492cb6  ffd0                               call   eax
00492cb8  f6054492fd0001                     test   BYTE PTR ds:0xfd9244,0x1
00492cbf  7525                               jne    0x492ce6
00492cc1  830d4492fd0001                     or     DWORD PTR ds:0xfd9244,0x1
00492cc8  c744242009000000                   mov    DWORD PTR [esp+0x20],0x9
00492cd0  e83b170c00                         call   0x554410
00492cd5  68c0dfbc00                         push   0xbcdfc0
00492cda  e83bf63f00                         call   0x89231a
00492cdf  83c404                             add    esp,0x4
00492ce2  897c2420                           mov    DWORD PTR [esp+0x20],edi
00492ce6  be4892fd00                         mov    esi,0xfd9248
00492ceb  e8601b0c00                         call   0x554850
00492cf0  f60500b1fa0001                     test   BYTE PTR ds:0xfab100,0x1
00492cf7  be01000000                         mov    esi,0x1
00492cfc  7524                               jne    0x492d22
00492cfe  093500b1fa00                       or     DWORD PTR ds:0xfab100,esi
00492d04  c74424200a000000                   mov    DWORD PTR [esp+0x20],0xa
00492d0c  e88fa90000                         call   0x49d6a0
00492d11  6820cebc00                         push   0xbcce20
00492d16  e8fff53f00                         call   0x89231a
00492d1b  83c404                             add    esp,0x4
00492d1e  897c2420                           mov    DWORD PTR [esp+0x20],edi
00492d22  841d04b1fa00                       test   BYTE PTR ds:0xfab104,bl
00492d28  7405                               je     0x492d2f
00492d2a  e891ac0000                         call   0x49d9c0
00492d2f  f6057072fe0001                     test   BYTE PTR ds:0xfe7270,0x1
00492d36  bb0f000000                         mov    ebx,0xf
00492d3b  7547                               jne    0x492d84
00492d3d  09357072fe00                       or     DWORD PTR ds:0xfe7270,esi
00492d43  c74424200b000000                   mov    DWORD PTR [esp+0x20],0xb
00492d4b  6a00                               push   0x0
00492d4d  687523bf00                         push   0xbf2375
00492d52  b92872fe00                         mov    ecx,0xfe7228
00492d57  891d3c72fe00                       mov    DWORD PTR ds:0xfe723c,ebx
00492d5d  c7053872fe0000000000               mov    DWORD PTR ds:0xfe7238,0x0
00492d67  c6052872fe0000                     mov    BYTE PTR ds:0xfe7228,0x0
00492d6e  e8fdfcf6ff                         call   0x402a70
00492d73  6820e6bc00                         push   0xbce620
00492d78  e89df53f00                         call   0x89231a
00492d7d  83c404                             add    esp,0x4
00492d80  897c2420                           mov    DWORD PTR [esp+0x20],edi
00492d84  833d0cf7fd0000                     cmp    DWORD PTR ds:0xfdf70c,0x0
00492d8b  7538                               jne    0x492dc5
00492d8d  833d3c72fe0010                     cmp    DWORD PTR ds:0xfe723c,0x10
00492d94  a12872fe00                         mov    eax,ds:0xfe7228
00492d99  c7053872fe0000000000               mov    DWORD PTR ds:0xfe7238,0x0
00492da3  7305                               jae    0x492daa
00492da5  b82872fe00                         mov    eax,0xfe7228
00492daa  c60000                             mov    BYTE PTR [eax],0x0
00492dad  e88e19faff                         call   0x434740
00492db2  8bc8                               mov    ecx,eax
00492db4  e8778c3000                         call   0x79ba30
00492db9  c7050cf7fd001e000000               mov    DWORD PTR ds:0xfdf70c,0x1e
00492dc3  eb06                               jmp    0x492dcb
00492dc5  29350cf7fd00                       sub    DWORD PTR ds:0xfdf70c,esi
00492dcb  f605e879fb0001                     test   BYTE PTR ds:0xfb79e8,0x1
00492dd2  7524                               jne    0x492df8
00492dd4  0935e879fb00                       or     DWORD PTR ds:0xfb79e8,esi
00492dda  c74424200c000000                   mov    DWORD PTR [esp+0x20],0xc
00492de2  e8f95f3000                         call   0x798de0
00492de7  68e0d2bc00                         push   0xbcd2e0
00492dec  e829f53f00                         call   0x89231a
00492df1  83c404                             add    esp,0x4
00492df4  897c2420                           mov    DWORD PTR [esp+0x20],edi
00492df8  bfa876fb00                         mov    edi,0xfb76a8
00492dfd  e81e713000                         call   0x799f20
00492e02  f605e879fb0001                     test   BYTE PTR ds:0xfb79e8,0x1
00492e09  bf01000000                         mov    edi,0x1
00492e0e  7529                               jne    0x492e39
00492e10  093de879fb00                       or     DWORD PTR ds:0xfb79e8,edi
00492e16  c74424200d000000                   mov    DWORD PTR [esp+0x20],0xd
00492e1e  e8bd5f3000                         call   0x798de0
00492e23  68e0d2bc00                         push   0xbcd2e0
00492e28  e8edf43f00                         call   0x89231a
00492e2d  83c404                             add    esp,0x4
00492e30  83ceff                             or     esi,0xffffffff
00492e33  89742420                           mov    DWORD PTR [esp+0x20],esi
00492e37  eb03                               jmp    0x492e3c
00492e39  83ceff                             or     esi,0xffffffff
00492e3c  68ec76fb00                         push   0xfb76ec
00492e41  ff154822bd00                       call   DWORD PTR ds:0xbd2248
00492e47  e854123200                         call   0x7b40a0
00492e4c  f60544defc0001                     test   BYTE PTR ds:0xfcde44,0x1
00492e53  7524                               jne    0x492e79
00492e55  093d44defc00                       or     DWORD PTR ds:0xfcde44,edi
00492e5b  c74424200e000000                   mov    DWORD PTR [esp+0x20],0xe
00492e63  e8388a0c00                         call   0x55b8a0
00492e68  68f0debc00                         push   0xbcdef0
00492e6d  e8a8f43f00                         call   0x89231a
00492e72  83c404                             add    esp,0x4
00492e75  89742420                           mov    DWORD PTR [esp+0x20],esi
00492e79  b948defc00                         mov    ecx,0xfcde48
00492e7e  e85d8e0c00                         call   0x55bce0
00492e83  f605a88efd0001                     test   BYTE PTR ds:0xfd8ea8,0x1
00492e8a  7520                               jne    0x492eac
00492e8c  093da88efd00                       or     DWORD PTR ds:0xfd8ea8,edi
00492e92  895c2420                           mov    DWORD PTR [esp+0x20],ebx
00492e96  e8757d0c00                         call   0x55ac10
00492e9b  68e0dfbc00                         push   0xbcdfe0
00492ea0  e875f43f00                         call   0x89231a
00492ea5  83c404                             add    esp,0x4
00492ea8  89742420                           mov    DWORD PTR [esp+0x20],esi
00492eac  68b08efd00                         push   0xfd8eb0
00492eb1  e8fa810c00                         call   0x55b0b0
00492eb6  e84575ffff                         call   0x48a400
00492ebb  8bc8                               mov    ecx,eax
00492ebd  e89e572400                         call   0x6d8660
; actor_effect_position [0x4c8fa0,0x4c900d) 完整；模型slot0位置或actor A0/A4/A8 fallback
004c8fa0  55                                 push   ebp
004c8fa1  8bec                               mov    ebp,esp
004c8fa3  83ec0c                             sub    esp,0xc
004c8fa6  56                                 push   esi
004c8fa7  8bf1                               mov    esi,ecx
004c8fa9  57                                 push   edi
004c8faa  8bbe5c010000                       mov    edi,DWORD PTR [esi+0x15c]
004c8fb0  85ff                               test   edi,edi
004c8fb2  7434                               je     0x4c8fe8
004c8fb4  83be7003000000                     cmp    DWORD PTR [esi+0x370],0x0
004c8fbb  742b                               je     0x4c8fe8
004c8fbd  6a00                               push   0x0
004c8fbf  8d45f4                             lea    eax,[ebp-0xc]
004c8fc2  50                                 push   eax
004c8fc3  e868eb2d00                         call   0x7a7b30
004c8fc8  85c0                               test   eax,eax
004c8fca  741c                               je     0x4c8fe8
004c8fcc  8b4508                             mov    eax,DWORD PTR [ebp+0x8]
004c8fcf  8b4df4                             mov    ecx,DWORD PTR [ebp-0xc]
004c8fd2  8b55f8                             mov    edx,DWORD PTR [ebp-0x8]
004c8fd5  8908                               mov    DWORD PTR [eax],ecx
004c8fd7  8b4dfc                             mov    ecx,DWORD PTR [ebp-0x4]
004c8fda  5f                                 pop    edi
004c8fdb  895004                             mov    DWORD PTR [eax+0x4],edx
004c8fde  894808                             mov    DWORD PTR [eax+0x8],ecx
004c8fe1  5e                                 pop    esi
004c8fe2  8be5                               mov    esp,ebp
004c8fe4  5d                                 pop    ebp
004c8fe5  c20400                             ret    0x4
004c8fe8  8b96a0000000                       mov    edx,DWORD PTR [esi+0xa0]
004c8fee  8b4508                             mov    eax,DWORD PTR [ebp+0x8]
004c8ff1  8b8ea4000000                       mov    ecx,DWORD PTR [esi+0xa4]
004c8ff7  8910                               mov    DWORD PTR [eax],edx
004c8ff9  8b96a8000000                       mov    edx,DWORD PTR [esi+0xa8]
004c8fff  5f                                 pop    edi
004c9000  894804                             mov    DWORD PTR [eax+0x4],ecx
004c9003  895008                             mov    DWORD PTR [eax+0x8],edx
004c9006  5e                                 pop    esi
004c9007  8be5                               mov    esp,ebp
004c9009  5d                                 pop    ebp
004c900a  c20400                             ret    0x4
; pair_graphics_sink [0x7ccc00,0x7cce36) 完整本機body；外部圖形介面虛呼叫保留接點，不展開DLL
007ccc00  55                                 push   ebp
007ccc01  8bec                               mov    ebp,esp
007ccc03  83e4f8                             and    esp,0xfffffff8
007ccc06  81ec84000000                       sub    esp,0x84
007ccc0c  a1201fd600                         mov    eax,ds:0xd61f20
007ccc11  33c4                               xor    eax,esp
007ccc13  89842480000000                     mov    DWORD PTR [esp+0x80],eax
007ccc1a  8b06                               mov    eax,DWORD PTR [esi]
007ccc1c  8b90e8000000                       mov    edx,DWORD PTR [eax+0xe8]
007ccc22  53                                 push   ebx
007ccc23  8b5d08                             mov    ebx,DWORD PTR [ebp+0x8]
007ccc26  8d4c2408                           lea    ecx,[esp+0x8]
007ccc2a  51                                 push   ecx
007ccc2b  6a17                               push   0x17
007ccc2d  56                                 push   esi
007ccc2e  ffd2                               call   edx
007ccc30  8b06                               mov    eax,DWORD PTR [esi]
007ccc32  8b90e8000000                       mov    edx,DWORD PTR [eax+0xe8]
007ccc38  8d4c2418                           lea    ecx,[esp+0x18]
007ccc3c  51                                 push   ecx
007ccc3d  6a1b                               push   0x1b
007ccc3f  56                                 push   esi
007ccc40  ffd2                               call   edx
007ccc42  8b06                               mov    eax,DWORD PTR [esi]
007ccc44  8b9008010000                       mov    edx,DWORD PTR [eax+0x108]
007ccc4a  8d4c2410                           lea    ecx,[esp+0x10]
007ccc4e  51                                 push   ecx
007ccc4f  6a01                               push   0x1
007ccc51  6a00                               push   0x0
007ccc53  56                                 push   esi
007ccc54  ffd2                               call   edx
007ccc56  8b06                               mov    eax,DWORD PTR [esi]
007ccc58  8b9008010000                       mov    edx,DWORD PTR [eax+0x108]
007ccc5e  8d4c241c                           lea    ecx,[esp+0x1c]
007ccc62  51                                 push   ecx
007ccc63  6a02                               push   0x2
007ccc65  6a00                               push   0x0
007ccc67  56                                 push   esi
007ccc68  ffd2                               call   edx
007ccc6a  8b06                               mov    eax,DWORD PTR [esi]
007ccc6c  8b90e8000000                       mov    edx,DWORD PTR [eax+0xe8]
007ccc72  8d4c240c                           lea    ecx,[esp+0xc]
007ccc76  51                                 push   ecx
007ccc77  6a13                               push   0x13
007ccc79  56                                 push   esi
007ccc7a  ffd2                               call   edx
007ccc7c  8b06                               mov    eax,DWORD PTR [esi]
007ccc7e  8b90e8000000                       mov    edx,DWORD PTR [eax+0xe8]
007ccc84  8d4c2414                           lea    ecx,[esp+0x14]
007ccc88  51                                 push   ecx
007ccc89  6a14                               push   0x14
007ccc8b  56                                 push   esi
007ccc8c  ffd2                               call   edx
007ccc8e  8b06                               mov    eax,DWORD PTR [esi]
007ccc90  8b88e4000000                       mov    ecx,DWORD PTR [eax+0xe4]
007ccc96  6a01                               push   0x1
007ccc98  6a1b                               push   0x1b
007ccc9a  56                                 push   esi
007ccc9b  ffd1                               call   ecx
007ccc9d  8b16                               mov    edx,DWORD PTR [esi]
007ccc9f  8b82e4000000                       mov    eax,DWORD PTR [edx+0xe4]
007ccca5  6a05                               push   0x5
007ccca7  6a13                               push   0x13
007ccca9  56                                 push   esi
007cccaa  ffd0                               call   eax
007cccac  8b0e                               mov    ecx,DWORD PTR [esi]
007cccae  8b91e4000000                       mov    edx,DWORD PTR [ecx+0xe4]
007cccb4  6a06                               push   0x6
007cccb6  6a14                               push   0x14
007cccb8  56                                 push   esi
007cccb9  ffd2                               call   edx
007cccbb  8b06                               mov    eax,DWORD PTR [esi]
007cccbd  8b880c010000                       mov    ecx,DWORD PTR [eax+0x10c]
007cccc3  6a02                               push   0x2
007cccc5  6a01                               push   0x1
007cccc7  6a00                               push   0x0
007cccc9  56                                 push   esi
007cccca  ffd1                               call   ecx
007ccccc  8b16                               mov    edx,DWORD PTR [esi]
007cccce  8b820c010000                       mov    eax,DWORD PTR [edx+0x10c]
007cccd4  6a00                               push   0x0
007cccd6  6a02                               push   0x2
007cccd8  6a00                               push   0x0
007cccda  56                                 push   esi
007cccdb  ffd0                               call   eax
007cccdd  d9ee                               fldz
007cccdf  d9542458                           fst    DWORD PTR [esp+0x58]
007ccce3  d9542454                           fst    DWORD PTR [esp+0x54]
007ccce7  8b0e                               mov    ecx,DWORD PTR [esi]
007ccce9  d9542450                           fst    DWORD PTR [esp+0x50]
007ccced  8b81b0000000                       mov    eax,DWORD PTR [ecx+0xb0]
007cccf3  d954244c                           fst    DWORD PTR [esp+0x4c]
007cccf7  d9542444                           fst    DWORD PTR [esp+0x44]
007cccfb  8d542420                           lea    edx,[esp+0x20]
007cccff  d9542440                           fst    DWORD PTR [esp+0x40]
007ccd03  52                                 push   edx
007ccd04  d9542440                           fst    DWORD PTR [esp+0x40]
007ccd08  6800010000                         push   0x100
007ccd0d  d9542440                           fst    DWORD PTR [esp+0x40]
007ccd11  56                                 push   esi
007ccd12  d954243c                           fst    DWORD PTR [esp+0x3c]
007ccd16  d9542438                           fst    DWORD PTR [esp+0x38]
007ccd1a  d9542434                           fst    DWORD PTR [esp+0x34]
007ccd1e  d95c2430                           fstp   DWORD PTR [esp+0x30]
007ccd22  d9e8                               fld1
007ccd24  d9542468                           fst    DWORD PTR [esp+0x68]
007ccd28  d9542454                           fst    DWORD PTR [esp+0x54]
007ccd2c  d9542440                           fst    DWORD PTR [esp+0x40]
007ccd30  d95c242c                           fstp   DWORD PTR [esp+0x2c]
007ccd34  ffd0                               call   eax
007ccd36  8b0e                               mov    ecx,DWORD PTR [esi]
007ccd38  8b9104010000                       mov    edx,DWORD PTR [ecx+0x104]
007ccd3e  6a00                               push   0x0
007ccd40  6a00                               push   0x0
007ccd42  56                                 push   esi
007ccd43  ffd2                               call   edx
007ccd45  d907                               fld    DWORD PTR [edi]
007ccd47  8b450c                             mov    eax,DWORD PTR [ebp+0xc]
007ccd4a  d95c2464                           fstp   DWORD PTR [esp+0x64]
007ccd4e  d94704                             fld    DWORD PTR [edi+0x4]
007ccd51  89442470                           mov    DWORD PTR [esp+0x70],eax
007ccd55  d95c2468                           fstp   DWORD PTR [esp+0x68]
007ccd59  89842480000000                     mov    DWORD PTR [esp+0x80],eax
007ccd60  d94708                             fld    DWORD PTR [edi+0x8]
007ccd63  8b06                               mov    eax,DWORD PTR [esi]
007ccd65  8b8864010000                       mov    ecx,DWORD PTR [eax+0x164]
007ccd6b  d95c246c                           fstp   DWORD PTR [esp+0x6c]
007ccd6f  d903                               fld    DWORD PTR [ebx]
007ccd71  6a42                               push   0x42
007ccd73  d95c2478                           fstp   DWORD PTR [esp+0x78]
007ccd77  56                                 push   esi
007ccd78  d94304                             fld    DWORD PTR [ebx+0x4]
007ccd7b  d99c2480000000                     fstp   DWORD PTR [esp+0x80]
007ccd82  d94308                             fld    DWORD PTR [ebx+0x8]
007ccd85  d99c2484000000                     fstp   DWORD PTR [esp+0x84]
007ccd8c  ffd1                               call   ecx
007ccd8e  8b16                               mov    edx,DWORD PTR [esi]
007ccd90  8b8a4c010000                       mov    ecx,DWORD PTR [edx+0x14c]
007ccd96  6a10                               push   0x10
007ccd98  8d442468                           lea    eax,[esp+0x68]
007ccd9c  50                                 push   eax
007ccd9d  6a01                               push   0x1
007ccd9f  6a02                               push   0x2
007ccda1  56                                 push   esi
007ccda2  ffd1                               call   ecx
007ccda4  8b442418                           mov    eax,DWORD PTR [esp+0x18]
007ccda8  8b16                               mov    edx,DWORD PTR [esi]
007ccdaa  8b8ae4000000                       mov    ecx,DWORD PTR [edx+0xe4]
007ccdb0  50                                 push   eax
007ccdb1  6a1b                               push   0x1b
007ccdb3  56                                 push   esi
007ccdb4  ffd1                               call   ecx
007ccdb6  8b442410                           mov    eax,DWORD PTR [esp+0x10]
007ccdba  8b16                               mov    edx,DWORD PTR [esi]
007ccdbc  8b8a0c010000                       mov    ecx,DWORD PTR [edx+0x10c]
007ccdc2  50                                 push   eax
007ccdc3  6a01                               push   0x1
007ccdc5  6a00                               push   0x0
007ccdc7  56                                 push   esi
007ccdc8  ffd1                               call   ecx
007ccdca  8b44241c                           mov    eax,DWORD PTR [esp+0x1c]
007ccdce  8b16                               mov    edx,DWORD PTR [esi]
007ccdd0  8b8a0c010000                       mov    ecx,DWORD PTR [edx+0x10c]
007ccdd6  50                                 push   eax
007ccdd7  6a02                               push   0x2
007ccdd9  6a00                               push   0x0
007ccddb  56                                 push   esi
007ccddc  ffd1                               call   ecx
007ccdde  8b16                               mov    edx,DWORD PTR [esi]
007ccde0  8b442408                           mov    eax,DWORD PTR [esp+0x8]
007ccde4  8b8ae4000000                       mov    ecx,DWORD PTR [edx+0xe4]
007ccdea  50                                 push   eax
007ccdeb  6a17                               push   0x17
007ccded  56                                 push   esi
007ccdee  ffd1                               call   ecx
007ccdf0  8b44240c                           mov    eax,DWORD PTR [esp+0xc]
007ccdf4  8b16                               mov    edx,DWORD PTR [esi]
007ccdf6  8b8ae4000000                       mov    ecx,DWORD PTR [edx+0xe4]
007ccdfc  50                                 push   eax
007ccdfd  6a13                               push   0x13
007ccdff  56                                 push   esi
007cce00  ffd1                               call   ecx
007cce02  8b442414                           mov    eax,DWORD PTR [esp+0x14]
007cce06  8b16                               mov    edx,DWORD PTR [esi]
007cce08  8b8ae4000000                       mov    ecx,DWORD PTR [edx+0xe4]
007cce0e  50                                 push   eax
007cce0f  6a14                               push   0x14
007cce11  56                                 push   esi
007cce12  ffd1                               call   ecx
007cce14  8b16                               mov    edx,DWORD PTR [esi]
007cce16  8b82e4000000                       mov    eax,DWORD PTR [edx+0xe4]
007cce1c  6a01                               push   0x1
007cce1e  6a07                               push   0x7
007cce20  56                                 push   esi
007cce21  ffd0                               call   eax
007cce23  8b8c2484000000                     mov    ecx,DWORD PTR [esp+0x84]
007cce2a  5b                                 pop    ebx
007cce2b  33cc                               xor    ecx,esp
007cce2d  e8cf410c00                         call   0x891001
007cce32  8be5                               mov    esp,ebp
007cce34  5d                                 pop    ebp
007cce35  c3                                 ret
; bar_record_access [0x7b4ed0,0x7b4f76) 完整；bar key0取record+0C
007b4ed0  55                                 push   ebp
007b4ed1  8bec                               mov    ebp,esp
007b4ed3  83ec30                             sub    esp,0x30
007b4ed6  53                                 push   ebx
007b4ed7  8b5d08                             mov    ebx,DWORD PTR [ebp+0x8]
007b4eda  8b4b04                             mov    ecx,DWORD PTR [ebx+0x4]
007b4edd  56                                 push   esi
007b4ede  57                                 push   edi
007b4edf  8bf8                               mov    edi,eax
007b4ee1  8b4104                             mov    eax,DWORD PTR [ecx+0x4]
007b4ee4  80782500                           cmp    BYTE PTR [eax+0x25],0x0
007b4ee8  8bf1                               mov    esi,ecx
007b4eea  7518                               jne    0x7b4f04
007b4eec  8a0f                               mov    cl,BYTE PTR [edi]
007b4eee  8bff                               mov    edi,edi
007b4ef0  38480c                             cmp    BYTE PTR [eax+0xc],cl
007b4ef3  7305                               jae    0x7b4efa
007b4ef5  8b4008                             mov    eax,DWORD PTR [eax+0x8]
007b4ef8  eb04                               jmp    0x7b4efe
007b4efa  8bf0                               mov    esi,eax
007b4efc  8b00                               mov    eax,DWORD PTR [eax]
007b4efe  80782500                           cmp    BYTE PTR [eax+0x25],0x0
007b4f02  74ec                               je     0x7b4ef0
007b4f04  3b7304                             cmp    esi,DWORD PTR [ebx+0x4]
007b4f07  7407                               je     0x7b4f10
007b4f09  8a07                               mov    al,BYTE PTR [edi]
007b4f0b  3a460c                             cmp    al,BYTE PTR [esi+0xc]
007b4f0e  735a                               jae    0x7b4f6a
007b4f10  d9e8                               fld1
007b4f12  8a17                               mov    dl,BYTE PTR [edi]
007b4f14  d955f0                             fst    DWORD PTR [ebp-0x10]
007b4f17  b801000000                         mov    eax,0x1
007b4f1c  d95df4                             fstp   DWORD PTR [ebp-0xc]
007b4f1f  33c9                               xor    ecx,ecx
007b4f21  d905e856c500                       fld    DWORD PTR ds:0xc556e8
007b4f27  8945d4                             mov    DWORD PTR [ebp-0x2c],eax
007b4f2a  8b45f0                             mov    eax,DWORD PTR [ebp-0x10]
007b4f2d  d95df8                             fstp   DWORD PTR [ebp-0x8]
007b4f30  8855d0                             mov    BYTE PTR [ebp-0x30],dl
007b4f33  8b55f8                             mov    edx,DWORD PTR [ebp-0x8]
007b4f36  894dd8                             mov    DWORD PTR [ebp-0x28],ecx
007b4f39  8b4df4                             mov    ecx,DWORD PTR [ebp-0xc]
007b4f3c  8945dc                             mov    DWORD PTR [ebp-0x24],eax
007b4f3f  8d7dd0                             lea    edi,[ebp-0x30]
007b4f42  8bc3                               mov    eax,ebx
007b4f44  894de0                             mov    DWORD PTR [ebp-0x20],ecx
007b4f47  8955e4                             mov    DWORD PTR [ebp-0x1c],edx
007b4f4a  e851040000                         call   0x7b53a0
007b4f4f  56                                 push   esi
007b4f50  8d4d08                             lea    ecx,[ebp+0x8]
007b4f53  51                                 push   ecx
007b4f54  8bcb                               mov    ecx,ebx
007b4f56  e8e5010000                         call   0x7b5140
007b4f5b  8b4508                             mov    eax,DWORD PTR [ebp+0x8]
007b4f5e  83c010                             add    eax,0x10
007b4f61  5f                                 pop    edi
007b4f62  5e                                 pop    esi
007b4f63  5b                                 pop    ebx
007b4f64  8be5                               mov    esp,ebp
007b4f66  5d                                 pop    ebp
007b4f67  c20400                             ret    0x4
007b4f6a  5f                                 pop    edi
007b4f6b  8d4610                             lea    eax,[esi+0x10]
007b4f6e  5e                                 pop    esi
007b4f6f  5b                                 pop    ebx
007b4f70  8be5                               mov    esp,ebp
007b4f72  5d                                 pop    ebp
007b4f73  c20400                             ret    0x4
; monster_percent_reader [0x4c7040,0x4c7051) 完整tail thunk；+3B0乘0.01後轉整數
004c7040  db81b0030000                       fild   DWORD PTR [ecx+0x3b0]
004c7046  dc0df857c500                       fmul   QWORD PTR ds:0xc557f8
004c704c  e9bf7c4300                         jmp    0x8fed10
; character_percent_reader [0x4cd010,0x4cd027) 完整tail thunk；current/max乘100後轉整數
004cd010  db81c8030000                       fild   DWORD PTR [ecx+0x3c8]
004cd016  dab1bc030000                       fidiv  DWORD PTR [ecx+0x3bc]
004cd01c  dc0de857c500                       fmul   QWORD PTR ds:0xc557e8
004cd022  e9e91c4300                         jmp    0x8fed10
; raw_ratio_reader [0x4c7060,0x4c7067) 完整；返回+3B0，並非Lua binding
004c7060  8b81b0030000                       mov    eax,DWORD PTR [ecx+0x3b0]
004c7066  c3                                 ret
; bar_submit [0x4c88f0,0x4c89a0) 完整；模型/ratio/可見條件→native bar提交
004c88f0  55                                 push   ebp
004c88f1  8bec                               mov    ebp,esp
004c88f3  51                                 push   ecx
004c88f4  53                                 push   ebx
004c88f5  56                                 push   esi
004c88f6  57                                 push   edi
004c88f7  8bf9                               mov    edi,ecx
004c88f9  83bf7003000000                     cmp    DWORD PTR [edi+0x370],0x0
004c8900  0f8491000000                       je     0x4c8997
004c8906  8b8f5c010000                       mov    ecx,DWORD PTR [edi+0x15c]
004c890c  85c9                               test   ecx,ecx
004c890e  7407                               je     0x4c8917
004c8910  8b01                               mov    eax,DWORD PTR [ecx]
004c8912  8b5008                             mov    edx,DWORD PTR [eax+0x8]
004c8915  ffd2                               call   edx
004c8917  8b8764030000                       mov    eax,DWORD PTR [edi+0x364]
004c891d  85c0                               test   eax,eax
004c891f  740d                               je     0x4c892e
004c8921  8b4024                             mov    eax,DWORD PTR [eax+0x24]
004c8924  85c0                               test   eax,eax
004c8926  7406                               je     0x4c892e
004c8928  50                                 push   eax
004c8929  e812562f00                         call   0x7bdf40
004c892e  8db764010000                       lea    esi,[edi+0x164]
004c8934  bb80000000                         mov    ebx,0x80
004c8939  8da42400000000                     lea    esp,[esp+0x0]
004c8940  8b06                               mov    eax,DWORD PTR [esi]
004c8942  85c0                               test   eax,eax
004c8944  740d                               je     0x4c8953
004c8946  8b4024                             mov    eax,DWORD PTR [eax+0x24]
004c8949  85c0                               test   eax,eax
004c894b  7406                               je     0x4c8953
004c894d  50                                 push   eax
004c894e  e8ed552f00                         call   0x7bdf40
004c8953  83c604                             add    esi,0x4
004c8956  4b                                 dec    ebx
004c8957  75e7                               jne    0x4c8940
004c8959  399f68030000                       cmp    DWORD PTR [edi+0x368],ebx
004c895f  7436                               je     0x4c8997
004c8961  57                                 push   edi
004c8962  e8190c0000                         call   0x4c9580
004c8967  8b07                               mov    eax,DWORD PTR [edi]
004c8969  8b5070                             mov    edx,DWORD PTR [eax+0x70]
004c896c  8bcf                               mov    ecx,edi
004c896e  ffd2                               call   edx
004c8970  83f864                             cmp    eax,0x64
004c8973  7c0b                               jl     0x4c8980
004c8975  8b8768030000                       mov    eax,DWORD PTR [edi+0x368]
004c897b  395828                             cmp    DWORD PTR [eax+0x28],ebx
004c897e  7417                               je     0x4c8997
004c8980  8bbf68030000                       mov    edi,DWORD PTR [edi+0x368]
004c8986  837f2400                           cmp    DWORD PTR [edi+0x24],0x0
004c898a  740b                               je     0x4c8997
004c898c  8d45fc                             lea    eax,[ebp-0x4]
004c898f  897dfc                             mov    DWORD PTR [ebp-0x4],edi
004c8992  e8e9c52e00                         call   0x7b4f80
004c8997  5f                                 pop    edi
004c8998  5e                                 pop    esi
004c8999  33c0                               xor    eax,eax
004c899b  5b                                 pop    ebx
004c899c  8be5                               mov    esp,ebp
004c899e  5d                                 pop    ebp
004c899f  c3                                 ret
; skill_response_000F [0x4b19d0,0x4b19f2) 完整；current controller v+3C delegate
004b19d0  55                                 push   ebp
004b19d1  8bec                               mov    ebp,esp
004b19d3  8b5510                             mov    edx,DWORD PTR [ebp+0x10]
004b19d6  8b0da4a7fb00                       mov    ecx,DWORD PTR ds:0xfba7a4
004b19dc  8b01                               mov    eax,DWORD PTR [ecx]
004b19de  8b403c                             mov    eax,DWORD PTR [eax+0x3c]
004b19e1  52                                 push   edx
004b19e2  8b550c                             mov    edx,DWORD PTR [ebp+0xc]
004b19e5  52                                 push   edx
004b19e6  8b5508                             mov    edx,DWORD PTR [ebp+0x8]
004b19e9  52                                 push   edx
004b19ea  ffd0                               call   eax
004b19ec  33c0                               xor    eax,eax
004b19ee  5d                                 pop    ebp
004b19ef  c20c00                             ret    0xc
; skill_response_ui [0x545c50,0x545e19) 完整；op0F錯誤/資源不足UI，不是HP snapshot producer
00545c50  55                                 push   ebp
00545c51  8bec                               mov    ebp,esp
00545c53  6aff                               push   0xffffffff
00545c55  68eeef9200                         push   0x92efee
00545c5a  64a100000000                       mov    eax,fs:0x0
00545c60  50                                 push   eax
00545c61  83ec3c                             sub    esp,0x3c
00545c64  a1201fd600                         mov    eax,ds:0xd61f20
00545c69  33c5                               xor    eax,ebp
00545c6b  8945f0                             mov    DWORD PTR [ebp-0x10],eax
00545c6e  53                                 push   ebx
00545c6f  56                                 push   esi
00545c70  57                                 push   edi
00545c71  50                                 push   eax
00545c72  8d45f4                             lea    eax,[ebp-0xc]
00545c75  64a300000000                       mov    fs:0x0,eax
00545c7b  b80f000000                         mov    eax,0xf
00545c80  66394510                           cmp    WORD PTR [ebp+0x10],ax
00545c84  0f8571010000                       jne    0x545dfb
00545c8a  8b7508                             mov    esi,DWORD PTR [ebp+0x8]
00545c8d  33db                               xor    ebx,ebx
00545c8f  385e07                             cmp    BYTE PTR [esi+0x7],bl
00545c92  7478                               je     0x545d0c
00545c94  8945e8                             mov    DWORD PTR [ebp-0x18],eax
00545c97  6828f9c000                         push   0xc0f928
00545c9c  8d4310                             lea    eax,[ebx+0x10]
00545c9f  8d4dd4                             lea    ecx,[ebp-0x2c]
00545ca2  895de4                             mov    DWORD PTR [ebp-0x1c],ebx
00545ca5  885dd4                             mov    BYTE PTR [ebp-0x2c],bl
00545ca8  e86356ecff                         call   0x40b310
00545cad  895dfc                             mov    DWORD PTR [ebp-0x4],ebx
00545cb0  f605d4b0fa0001                     test   BYTE PTR ds:0xfab0d4,0x1
00545cb7  7520                               jne    0x545cd9
00545cb9  830dd4b0fa0001                     or     DWORD PTR ds:0xfab0d4,0x1
00545cc0  c645fc01                           mov    BYTE PTR [ebp-0x4],0x1
00545cc4  e8d7462c00                         call   0x80a3a0
00545cc9  68d0cdbc00                         push   0xbccdd0
00545cce  e847c63400                         call   0x89231a
00545cd3  83c404                             add    esp,0x4
00545cd6  885dfc                             mov    BYTE PTR [ebp-0x4],bl
00545cd9  6828b0fa00                         push   0xfab028
00545cde  8d4dd4                             lea    ecx,[ebp-0x2c]
00545ce1  e81a4e2c00                         call   0x80ab00
00545ce6  3bc3                               cmp    eax,ebx
00545ce8  7409                               je     0x545cf3
00545cea  8b10                               mov    edx,DWORD PTR [eax]
00545cec  8bc8                               mov    ecx,eax
00545cee  8b4214                             mov    eax,DWORD PTR [edx+0x14]
00545cf1  ffd0                               call   eax
00545cf3  c745fcffffffff                     mov    DWORD PTR [ebp-0x4],0xffffffff
00545cfa  837de810                           cmp    DWORD PTR [ebp-0x18],0x10
00545cfe  720c                               jb     0x545d0c
00545d00  8b4dd4                             mov    ecx,DWORD PTR [ebp-0x2c]
00545d03  51                                 push   ecx
00545d04  e803b53400                         call   0x89120c
00545d09  83c404                             add    esp,0x4
00545d0c  807e0701                           cmp    BYTE PTR [esi+0x7],0x1
00545d10  0f85e5000000                       jne    0x545dfb
00545d16  f6460801                           test   BYTE PTR [esi+0x8],0x1
00545d1a  7446                               je     0x545d62
00545d1c  53                                 push   ebx
00545d1d  e88ef80300                         call   0x5855b0
00545d22  8bf0                               mov    esi,eax
00545d24  e807f60300                         call   0x585330
00545d29  50                                 push   eax
00545d2a  8d4dd4                             lea    ecx,[ebp-0x2c]
00545d2d  e81ec5ebff                         call   0x402250
00545d32  8d55d4                             lea    edx,[ebp-0x2c]
00545d35  52                                 push   edx
00545d36  c745fc02000000                     mov    DWORD PTR [ebp-0x4],0x2
00545d3d  e87e9becff                         call   0x40f8c0
00545d42  8bf8                               mov    edi,eax
00545d44  e8e70df9ff                         call   0x4d6b30
00545d49  c745fcffffffff                     mov    DWORD PTR [ebp-0x4],0xffffffff
00545d50  837de808                           cmp    DWORD PTR [ebp-0x18],0x8
00545d54  720c                               jb     0x545d62
00545d56  8b45d4                             mov    eax,DWORD PTR [ebp-0x2c]
00545d59  50                                 push   eax
00545d5a  e8adb43400                         call   0x89120c
00545d5f  83c404                             add    esp,0x4
00545d62  8b4d08                             mov    ecx,DWORD PTR [ebp+0x8]
00545d65  bb04000000                         mov    ebx,0x4
00545d6a  845908                             test   BYTE PTR [ecx+0x8],bl
00545d6d  7447                               je     0x545db6
00545d6f  6a01                               push   0x1
00545d71  e83af80300                         call   0x5855b0
00545d76  8bf0                               mov    esi,eax
00545d78  e8b3f50300                         call   0x585330
00545d7d  50                                 push   eax
00545d7e  8d4dd4                             lea    ecx,[ebp-0x2c]
00545d81  e8cac4ebff                         call   0x402250
00545d86  8d55d4                             lea    edx,[ebp-0x2c]
00545d89  52                                 push   edx
00545d8a  c745fc03000000                     mov    DWORD PTR [ebp-0x4],0x3
00545d91  e82a9becff                         call   0x40f8c0
00545d96  8bf8                               mov    edi,eax
00545d98  e8930df9ff                         call   0x4d6b30
00545d9d  c745fcffffffff                     mov    DWORD PTR [ebp-0x4],0xffffffff
00545da4  837de808                           cmp    DWORD PTR [ebp-0x18],0x8
00545da8  720c                               jb     0x545db6
00545daa  8b45d4                             mov    eax,DWORD PTR [ebp-0x2c]
00545dad  50                                 push   eax
00545dae  e859b43400                         call   0x89120c
00545db3  83c404                             add    esp,0x4
00545db6  8b4d08                             mov    ecx,DWORD PTR [ebp+0x8]
00545db9  f6410802                           test   BYTE PTR [ecx+0x8],0x2
00545dbd  743c                               je     0x545dfb
00545dbf  6a02                               push   0x2
00545dc1  e8eaf70300                         call   0x5855b0
00545dc6  8bf0                               mov    esi,eax
00545dc8  e863f50300                         call   0x585330
00545dcd  50                                 push   eax
00545dce  8d4db8                             lea    ecx,[ebp-0x48]
00545dd1  e87ac4ebff                         call   0x402250
00545dd6  8d55b8                             lea    edx,[ebp-0x48]
00545dd9  52                                 push   edx
00545dda  895dfc                             mov    DWORD PTR [ebp-0x4],ebx
00545ddd  e8de9aecff                         call   0x40f8c0
00545de2  8bf8                               mov    edi,eax
00545de4  e8470df9ff                         call   0x4d6b30
00545de9  837dcc08                           cmp    DWORD PTR [ebp-0x34],0x8
00545ded  720c                               jb     0x545dfb
00545def  8b45b8                             mov    eax,DWORD PTR [ebp-0x48]
00545df2  50                                 push   eax
00545df3  e814b43400                         call   0x89120c
00545df8  83c404                             add    esp,0x4
00545dfb  8b4df4                             mov    ecx,DWORD PTR [ebp-0xc]
00545dfe  64890d00000000                     mov    DWORD PTR fs:0x0,ecx
00545e05  59                                 pop    ecx
00545e06  5f                                 pop    edi
00545e07  5e                                 pop    esi
00545e08  5b                                 pop    ebx
00545e09  8b4df0                             mov    ecx,DWORD PTR [ebp-0x10]
00545e0c  33cd                               xor    ecx,ebp
00545e0e  e8eeb13400                         call   0x891001
00545e13  8be5                               mov    esp,ebp
00545e15  5d                                 pop    ebp
00545e16  c20c00                             ret    0xc
; aggregate_display [0x458850,0x458bd5) 完整；F942C4→native十進位UI，不保留EntityId事件
00458850  55                                 push   ebp
00458851  8bec                               mov    ebp,esp
00458853  83e4f8                             and    esp,0xfffffff8
00458856  6aff                               push   0xffffffff
00458858  68be179400                         push   0x9417be
0045885d  64a100000000                       mov    eax,fs:0x0
00458863  50                                 push   eax
00458864  83ec30                             sub    esp,0x30
00458867  a1201fd600                         mov    eax,ds:0xd61f20
0045886c  33c4                               xor    eax,esp
0045886e  89442428                           mov    DWORD PTR [esp+0x28],eax
00458872  53                                 push   ebx
00458873  56                                 push   esi
00458874  57                                 push   edi
00458875  a1201fd600                         mov    eax,ds:0xd61f20
0045887a  33c4                               xor    eax,esp
0045887c  50                                 push   eax
0045887d  8d442440                           lea    eax,[esp+0x40]
00458881  64a300000000                       mov    fs:0x0,eax
00458887  f6059043f90001                     test   BYTE PTR ds:0xf94390,0x1
0045888e  8b5d08                             mov    ebx,DWORD PTR [ebp+0x8]
00458891  7529                               jne    0x4588bc
00458893  830d9043f90001                     or     DWORD PTR ds:0xf94390,0x1
0045889a  c744244800000000                   mov    DWORD PTR [esp+0x48],0x0
004588a2  e8e98c0800                         call   0x4e1590
004588a7  6880ccbc00                         push   0xbccc80
004588ac  e8699a4300                         call   0x89231a
004588b1  83c404                             add    esp,0x4
004588b4  c7442448ffffffff                   mov    DWORD PTR [esp+0x48],0xffffffff
004588bc  a1c442f900                         mov    eax,ds:0xf942c4
004588c1  8983dc000000                       mov    DWORD PTR [ebx+0xdc],eax
004588c7  85c0                               test   eax,eax
004588c9  0f8506010000                       jne    0x4589d5
004588cf  8db380000000                       lea    esi,[ebx+0x80]
004588d5  8d7809                             lea    edi,[eax+0x9]
004588d8  eb06                               jmp    0x4588e0
004588da  8d9b00000000                       lea    ebx,[ebx+0x0]
004588e0  8b0e                               mov    ecx,DWORD PTR [esi]
004588e2  8b11                               mov    edx,DWORD PTR [ecx]
004588e4  8b8294000000                       mov    eax,DWORD PTR [edx+0x94]
004588ea  6a00                               push   0x0
004588ec  ffd0                               call   eax
004588ee  83c604                             add    esi,0x4
004588f1  4f                                 dec    edi
004588f2  75ec                               jne    0x4588e0
004588f4  8db3d0000000                       lea    esi,[ebx+0xd0]
004588fa  bf03000000                         mov    edi,0x3
004588ff  90                                 nop
00458900  8b0e                               mov    ecx,DWORD PTR [esi]
00458902  8b11                               mov    edx,DWORD PTR [ecx]
00458904  8b8294000000                       mov    eax,DWORD PTR [edx+0x94]
0045890a  6a00                               push   0x0
0045890c  ffd0                               call   eax
0045890e  8b0e                               mov    ecx,DWORD PTR [esi]
00458910  8b11                               mov    edx,DWORD PTR [ecx]
00458912  8b82c8000000                       mov    eax,DWORD PTR [edx+0xc8]
00458918  ffd0                               call   eax
0045891a  83c604                             add    esi,0x4
0045891d  4f                                 dec    edi
0045891e  75e0                               jne    0x458900
00458920  8b8ba4000000                       mov    ecx,DWORD PTR [ebx+0xa4]
00458926  8b11                               mov    edx,DWORD PTR [ecx]
00458928  8b8294000000                       mov    eax,DWORD PTR [edx+0x94]
0045892e  6a01                               push   0x1
00458930  ffd0                               call   eax
00458932  8bb3a4000000                       mov    esi,DWORD PTR [ebx+0xa4]
00458938  80bea400000000                     cmp    BYTE PTR [esi+0xa4],0x0
0045893f  8bbba8000000                       mov    edi,DWORD PTR [ebx+0xa8]
00458945  746d                               je     0x4589b4
00458947  83be9400000000                     cmp    DWORD PTR [esi+0x94],0x0
0045894e  7464                               je     0x4589b4
00458950  8b8e94000000                       mov    ecx,DWORD PTR [esi+0x94]
00458956  8b11                               mov    edx,DWORD PTR [ecx]
00458958  8b4204                             mov    eax,DWORD PTR [edx+0x4]
0045895b  ffd0                               call   eax
0045895d  3d6bbf0000                         cmp    eax,0xbf6b
00458962  7550                               jne    0x4589b4
00458964  8bb694000000                       mov    esi,DWORD PTR [esi+0x94]
0045896a  397e10                             cmp    DWORD PTR [esi+0x10],edi
0045896d  7445                               je     0x4589b4
0045896f  85ff                               test   edi,edi
00458971  7421                               je     0x458994
00458973  8b4f08                             mov    ecx,DWORD PTR [edi+0x8]
00458976  85c9                               test   ecx,ecx
00458978  741a                               je     0x458994
0045897a  b801000000                         mov    eax,0x1
0045897f  01819c000000                       add    DWORD PTR [ecx+0x9c],eax
00458985  39819c000000                       cmp    DWORD PTR [ecx+0x9c],eax
0045898b  7507                               jne    0x458994
0045898d  8b11                               mov    edx,DWORD PTR [ecx]
0045898f  8b4224                             mov    eax,DWORD PTR [edx+0x24]
00458992  ffd0                               call   eax
00458994  8b4610                             mov    eax,DWORD PTR [esi+0x10]
00458997  85c0                               test   eax,eax
00458999  7416                               je     0x4589b1
0045899b  8b4808                             mov    ecx,DWORD PTR [eax+0x8]
0045899e  85c9                               test   ecx,ecx
004589a0  740f                               je     0x4589b1
004589a2  ff899c000000                       dec    DWORD PTR [ecx+0x9c]
004589a8  7507                               jne    0x4589b1
004589aa  8b11                               mov    edx,DWORD PTR [ecx]
004589ac  8b4228                             mov    eax,DWORD PTR [edx+0x28]
004589af  ffd0                               call   eax
004589b1  897e10                             mov    DWORD PTR [esi+0x10],edi
004589b4  8b8ba4000000                       mov    ecx,DWORD PTR [ebx+0xa4]
004589ba  8b11                               mov    edx,DWORD PTR [ecx]
004589bc  8b82c8000000                       mov    eax,DWORD PTR [edx+0xc8]
004589c2  ffd0                               call   eax
004589c4  8b8be4000000                       mov    ecx,DWORD PTR [ebx+0xe4]
004589ca  6a00                               push   0x0
004589cc  83e90f                             sub    ecx,0xf
004589cf  51                                 push   ecx
004589d0  e9c3010000                         jmp    0x458b98
004589d5  796d                               jns    0x458a44
004589d7  8b8ba4000000                       mov    ecx,DWORD PTR [ebx+0xa4]
004589dd  8b11                               mov    edx,DWORD PTR [ecx]
004589df  8b8294000000                       mov    eax,DWORD PTR [edx+0x94]
004589e5  6a01                               push   0x1
004589e7  ffd0                               call   eax
004589e9  8bbba4000000                       mov    edi,DWORD PTR [ebx+0xa4]
004589ef  80bfa400000000                     cmp    BYTE PTR [edi+0xa4],0x0
004589f6  8bb3a8000000                       mov    esi,DWORD PTR [ebx+0xa8]
004589fc  7428                               je     0x458a26
004589fe  83bf9400000000                     cmp    DWORD PTR [edi+0x94],0x0
00458a05  741f                               je     0x458a26
00458a07  8b8f94000000                       mov    ecx,DWORD PTR [edi+0x94]
00458a0d  8b11                               mov    edx,DWORD PTR [ecx]
00458a0f  8b4204                             mov    eax,DWORD PTR [edx+0x4]
00458a12  ffd0                               call   eax
00458a14  3d6bbf0000                         cmp    eax,0xbf6b
00458a19  750b                               jne    0x458a26
00458a1b  8bbf94000000                       mov    edi,DWORD PTR [edi+0x94]
00458a21  e8da273200                         call   0x77b200
00458a26  8b8ba4000000                       mov    ecx,DWORD PTR [ebx+0xa4]
00458a2c  8b11                               mov    edx,DWORD PTR [ecx]
00458a2e  8b82c8000000                       mov    eax,DWORD PTR [edx+0xc8]
00458a34  ffd0                               call   eax
00458a36  8b8be4000000                       mov    ecx,DWORD PTR [ebx+0xe4]
00458a3c  6a00                               push   0x0
00458a3e  51                                 push   ecx
00458a3f  e954010000                         jmp    0x458b98
00458a44  33ff                               xor    edi,edi
00458a46  99                                 cdq
00458a47  b90a000000                         mov    ecx,0xa
00458a4c  f7f9                               idiv   ecx
00458a4e  47                                 inc    edi
00458a4f  6689547c22                         mov    WORD PTR [esp+edi*2+0x22],dx
00458a54  8bf0                               mov    esi,eax
00458a56  85f6                               test   esi,esi
00458a58  75ec                               jne    0x458a46
00458a5a  89b3dc000000                       mov    DWORD PTR [ebx+0xdc],esi
00458a60  8bc1                               mov    eax,ecx
00458a62  8d542436                           lea    edx,[esp+0x36]
00458a66  8db380000000                       lea    esi,[ebx+0x80]
00458a6c  897c241c                           mov    DWORD PTR [esp+0x1c],edi
00458a70  89442420                           mov    DWORD PTR [esp+0x20],eax
00458a74  89542418                           mov    DWORD PTR [esp+0x18],edx
00458a78  89742410                           mov    DWORD PTR [esp+0x10],esi
00458a7c  8d642400                           lea    esp,[esp+0x0]
00458a80  3bc7                               cmp    eax,edi
00458a82  7e1c                               jle    0x458aa0
00458a84  8b0e                               mov    ecx,DWORD PTR [esi]
00458a86  8b01                               mov    eax,DWORD PTR [ecx]
00458a88  8b9094000000                       mov    edx,DWORD PTR [eax+0x94]
00458a8e  6a00                               push   0x0
00458a90  ffd2                               call   edx
00458a92  8b0e                               mov    ecx,DWORD PTR [esi]
00458a94  8b01                               mov    eax,DWORD PTR [ecx]
00458a96  8b90c8000000                       mov    edx,DWORD PTR [eax+0xc8]
00458a9c  ffd2                               call   edx
00458a9e  eb79                               jmp    0x458b19
00458aa0  8b442418                           mov    eax,DWORD PTR [esp+0x18]
00458aa4  0fb700                             movzx  eax,WORD PTR [eax]
00458aa7  89442414                           mov    DWORD PTR [esp+0x14],eax
00458aab  6685c0                             test   ax,ax
00458aae  7869                               js     0x458b19
00458ab0  8b0e                               mov    ecx,DWORD PTR [esi]
00458ab2  8b11                               mov    edx,DWORD PTR [ecx]
00458ab4  8b8294000000                       mov    eax,DWORD PTR [edx+0x94]
00458aba  6a01                               push   0x1
00458abc  ffd0                               call   eax
00458abe  0fbf4c2414                         movsx  ecx,WORD PTR [esp+0x14]
00458ac3  8b3e                               mov    edi,DWORD PTR [esi]
00458ac5  80bfa400000000                     cmp    BYTE PTR [edi+0xa4],0x0
00458acc  8b948ba8000000                     mov    edx,DWORD PTR [ebx+ecx*4+0xa8]
00458ad3  89542414                           mov    DWORD PTR [esp+0x14],edx
00458ad7  7430                               je     0x458b09
00458ad9  83bf9400000000                     cmp    DWORD PTR [edi+0x94],0x0
00458ae0  7427                               je     0x458b09
00458ae2  8b8f94000000                       mov    ecx,DWORD PTR [edi+0x94]
00458ae8  8b01                               mov    eax,DWORD PTR [ecx]
00458aea  8b5004                             mov    edx,DWORD PTR [eax+0x4]
00458aed  ffd2                               call   edx
00458aef  3d6bbf0000                         cmp    eax,0xbf6b
00458af4  7513                               jne    0x458b09
00458af6  8b742414                           mov    esi,DWORD PTR [esp+0x14]
00458afa  8bbf94000000                       mov    edi,DWORD PTR [edi+0x94]
00458b00  e8fb263200                         call   0x77b200
00458b05  8b742410                           mov    esi,DWORD PTR [esp+0x10]
00458b09  8b0e                               mov    ecx,DWORD PTR [esi]
00458b0b  8b01                               mov    eax,DWORD PTR [ecx]
00458b0d  8b90c8000000                       mov    edx,DWORD PTR [eax+0xc8]
00458b13  ffd2                               call   edx
00458b15  8b7c241c                           mov    edi,DWORD PTR [esp+0x1c]
00458b19  8b442420                           mov    eax,DWORD PTR [esp+0x20]
00458b1d  836c241802                         sub    DWORD PTR [esp+0x18],0x2
00458b22  48                                 dec    eax
00458b23  83c604                             add    esi,0x4
00458b26  89442420                           mov    DWORD PTR [esp+0x20],eax
00458b2a  89742410                           mov    DWORD PTR [esp+0x10],esi
00458b2e  85c0                               test   eax,eax
00458b30  0f8f4affffff                       jg     0x458a80
00458b36  8d4fff                             lea    ecx,[edi-0x1]
00458b39  b856555555                         mov    eax,0x55555556
00458b3e  f7e9                               imul   ecx
00458b40  8bfa                               mov    edi,edx
00458b42  c1ef1f                             shr    edi,0x1f
00458b45  03fa                               add    edi,edx
00458b47  85ff                               test   edi,edi
00458b49  7e2d                               jle    0x458b78
00458b4b  8db3d0000000                       lea    esi,[ebx+0xd0]
00458b51  897c2410                           mov    DWORD PTR [esp+0x10],edi
00458b55  8b0e                               mov    ecx,DWORD PTR [esi]
00458b57  8b01                               mov    eax,DWORD PTR [ecx]
00458b59  8b9094000000                       mov    edx,DWORD PTR [eax+0x94]
00458b5f  6a01                               push   0x1
00458b61  ffd2                               call   edx
00458b63  8b0e                               mov    ecx,DWORD PTR [esi]
00458b65  8b01                               mov    eax,DWORD PTR [ecx]
00458b67  8b90c8000000                       mov    edx,DWORD PTR [eax+0xc8]
00458b6d  ffd2                               call   edx
00458b6f  83c604                             add    esi,0x4
00458b72  ff4c2410                           dec    DWORD PTR [esp+0x10]
00458b76  75dd                               jne    0x458b55
00458b78  8b44241c                           mov    eax,DWORD PTR [esp+0x1c]
00458b7c  6bff0d                             imul   edi,edi,0xd
00458b7f  8bc8                               mov    ecx,eax
00458b81  c1e104                             shl    ecx,0x4
00458b84  2bc8                               sub    ecx,eax
00458b86  8d444fe2                           lea    eax,[edi+ecx*2-0x1e]
00458b8a  99                                 cdq
00458b8b  2bc2                               sub    eax,edx
00458b8d  d1f8                               sar    eax,1
00458b8f  0383e4000000                       add    eax,DWORD PTR [ebx+0xe4]
00458b95  6a00                               push   0x0
00458b97  50                                 push   eax
00458b98  8bb3e0000000                       mov    esi,DWORD PTR [ebx+0xe0]
00458b9e  e85d0e2f00                         call   0x749a00
00458ba3  8b9be0000000                       mov    ebx,DWORD PTR [ebx+0xe0]
00458ba9  8b13                               mov    edx,DWORD PTR [ebx]
00458bab  8b82c8000000                       mov    eax,DWORD PTR [edx+0xc8]
00458bb1  8bcb                               mov    ecx,ebx
00458bb3  ffd0                               call   eax
00458bb5  8b4c2440                           mov    ecx,DWORD PTR [esp+0x40]
00458bb9  64890d00000000                     mov    DWORD PTR fs:0x0,ecx
00458bc0  59                                 pop    ecx
00458bc1  5f                                 pop    edi
00458bc2  5e                                 pop    esi
00458bc3  5b                                 pop    ebx
00458bc4  8b4c2428                           mov    ecx,DWORD PTR [esp+0x28]
00458bc8  33cc                               xor    ecx,esp
00458bca  e832844300                         call   0x891001
00458bcf  8be5                               mov    esp,ebp
00458bd1  5d                                 pop    ebp
00458bd2  c20400                             ret    0x4
