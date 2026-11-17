
# registration_8_A_C_D_E | new routing witnesses
004add50  53                                   push   ebx
004add51  56                                   push   esi
004add52  8d5008                               lea    edx,[eax+0x8]
004add55  bed50b0000                           mov    esi,0xbd5
004add5a  b97523bf00                           mov    ecx,0xbf2375
004add5f  90                                   nop
004add60  c742fc407d4b00                       mov    DWORD PTR [edx-0x4],0x4b7d40
004add67  890a                                 mov    DWORD PTR [edx],ecx
004add69  83c208                               add    edx,0x8
004add6c  4e                                   dec    esi
004add6d  75f1                                 jne    0x4add60
004add6f  ba80fb4a00                           mov    edx,0x4afb80
004add74  c74034307d4b00                       mov    DWORD PTR [eax+0x34],0x4b7d30
004add7b  894838                               mov    DWORD PTR [eax+0x38],ecx
004add7e  c7403cd0e44a00                       mov    DWORD PTR [eax+0x3c],0x4ae4d0
004add85  894840                               mov    DWORD PTR [eax+0x40],ecx
004add88  c780f4090000b0ed4a00                 mov    DWORD PTR [eax+0x9f4],0x4aedb0
004add92  8988f8090000                         mov    DWORD PTR [eax+0x9f8],ecx
004add98  c7404430f54a00                       mov    DWORD PTR [eax+0x44],0x4af530
004add9f  894848                               mov    DWORD PTR [eax+0x48],ecx
004adda2  c7405420f94a00                       mov    DWORD PTR [eax+0x54],0x4af920
004adda9  894858                               mov    DWORD PTR [eax+0x58],ecx
004addac  c74004f0fa4a00                       mov    DWORD PTR [eax+0x4],0x4afaf0
004addb3  894808                               mov    DWORD PTR [eax+0x8],ecx
004addb6  89500c                               mov    DWORD PTR [eax+0xc],edx
004addb9  894810                               mov    DWORD PTR [eax+0x10],ecx
004addbc  c7405c60fe4a00                       mov    DWORD PTR [eax+0x5c],0x4afe60
004addc3  894860                               mov    DWORD PTR [eax+0x60],ecx
004addc6  c7406430014b00                       mov    DWORD PTR [eax+0x64],0x4b0130
004addcd  894868                               mov    DWORD PTR [eax+0x68],ecx
004addd0  c7406cc0014b00                       mov    DWORD PTR [eax+0x6c],0x4b01c0
004addd7  894870                               mov    DWORD PTR [eax+0x70],ecx
004addda  c7807c050000d0034b00                 mov    DWORD PTR [eax+0x57c],0x4b03d0
004adde4  898880050000                         mov    DWORD PTR [eax+0x580],ecx
004addea  c74074406c4300                       mov    DWORD PTR [eax+0x74],0x436c40
004addf1  894878                               mov    DWORD PTR [eax+0x78],ecx

# relation_0008 | complete producer including raw field stores
004af530  55                                   push   ebp
004af531  8bec                                 mov    ebp,esp
004af533  83e4f8                               and    esp,0xfffffff8
004af536  6aff                                 push   0xffffffff
004af538  684a4e9400                           push   0x944e4a
004af53d  64a100000000                         mov    eax,fs:0x0
004af543  50                                   push   eax
004af544  83ec10                               sub    esp,0x10
004af547  53                                   push   ebx
004af548  56                                   push   esi
004af549  57                                   push   edi
004af54a  a1201fd600                           mov    eax,ds:0xd61f20
004af54f  33c4                                 xor    eax,esp
004af551  50                                   push   eax
004af552  8d442420                             lea    eax,[esp+0x20]
004af556  64a300000000                         mov    fs:0x0,eax
004af55c  8b5d08                               mov    ebx,DWORD PTR [ebp+0x8]
004af55f  33f6                                 xor    esi,esi
004af561  66397302                             cmp    WORD PTR [ebx+0x2],si
004af565  7441                                 je     0x4af5a8
004af567  f6052cb2fa0001                       test   BYTE PTR ds:0xfab22c,0x1
004af56e  7525                                 jne    0x4af595
004af570  830d2cb2fa0001                       or     DWORD PTR ds:0xfab22c,0x1
004af577  89742428                             mov    DWORD PTR [esp+0x28],esi
004af57b  e810f70200                           call   0x4dec90
004af580  6830cebc00                           push   0xbcce30
004af585  e8902d3e00                           call   0x89231a
004af58a  83c404                               add    esp,0x4
004af58d  c7442428ffffffff                     mov    DWORD PTR [esp+0x28],0xffffffff
004af595  6848b1fa00                           push   0xfab148
004af59a  893528b2fa00                         mov    DWORD PTR ds:0xfab228,esi
004af5a0  e8cb1a0300                           call   0x4e1070
004af5a5  83c404                               add    esp,0x4
004af5a8  8b450c                               mov    eax,DWORD PTR [ebp+0xc]
004af5ab  83f804                               cmp    eax,0x4
004af5ae  7304                                 jae    0x4af5b4
004af5b0  33d2                                 xor    edx,edx
004af5b2  eb0d                                 jmp    0x4af5c1
004af5b4  8d48fc                               lea    ecx,[eax-0x4]
004af5b7  b8a38b2eba                           mov    eax,0xba2e8ba3
004af5bc  f7e1                                 mul    ecx
004af5be  c1ea04                               shr    edx,0x4
004af5c1  3bd6                                 cmp    edx,esi
004af5c3  0f8639030000                         jbe    0x4af902
004af5c9  83c30a                               add    ebx,0xa
004af5cc  89542410                             mov    DWORD PTR [esp+0x10],edx
004af5d0  eb02                                 jmp    0x4af5d4
004af5d2  33f6                                 xor    esi,esi
004af5d4  f6052cb2fa0001                       test   BYTE PTR ds:0xfab22c,0x1
004af5db  7529                                 jne    0x4af606
004af5dd  b801000000                           mov    eax,0x1
004af5e2  09052cb2fa00                         or     DWORD PTR ds:0xfab22c,eax
004af5e8  89442428                             mov    DWORD PTR [esp+0x28],eax
004af5ec  e89ff60200                           call   0x4dec90
004af5f1  6830cebc00                           push   0xbcce30
004af5f6  e81f2d3e00                           call   0x89231a
004af5fb  83c404                               add    esp,0x4
004af5fe  c7442428ffffffff                     mov    DWORD PTR [esp+0x28],0xffffffff
004af606  8b53fa                               mov    edx,DWORD PTR [ebx-0x6]
004af609  8d442414                             lea    eax,[esp+0x14]
004af60d  50                                   push   eax
004af60e  8d44241c                             lea    eax,[esp+0x1c]
004af612  b948b1fa00                           mov    ecx,0xfab148
004af617  89542418                             mov    DWORD PTR [esp+0x18],edx
004af61b  e8a0423900                           call   0x8438c0
004af620  8b442418                             mov    eax,DWORD PTR [esp+0x18]
004af624  3b054cb1fa00                         cmp    eax,DWORD PTR ds:0xfab14c
004af62a  740b                                 je     0x4af637
004af62c  8b7810                               mov    edi,DWORD PTR [eax+0x10]
004af62f  3bfe                                 cmp    edi,esi
004af631  0f85ba000000                         jne    0x4af6f1
004af637  6a2c                                 push   0x2c
004af639  e82a1c3e00                           call   0x891268
004af63e  83c404                               add    esp,0x4
004af641  3bc6                                 cmp    eax,esi
004af643  7425                                 je     0x4af66a
004af645  33c9                                 xor    ecx,ecx
004af647  8930                                 mov    DWORD PTR [eax],esi
004af649  897004                               mov    DWORD PTR [eax+0x4],esi
004af64c  897008                               mov    DWORD PTR [eax+0x8],esi
004af64f  89700c                               mov    DWORD PTR [eax+0xc],esi
004af652  897010                               mov    DWORD PTR [eax+0x10],esi
004af655  894814                               mov    DWORD PTR [eax+0x14],ecx
004af658  89701c                               mov    DWORD PTR [eax+0x1c],esi
004af65b  c74024ffffffff                       mov    DWORD PTR [eax+0x24],0xffffffff
004af662  66894828                             mov    WORD PTR [eax+0x28],cx
004af666  8bf8                                 mov    edi,eax
004af668  eb02                                 jmp    0x4af66c
004af66a  33ff                                 xor    edi,edi
004af66c  f6059043f90001                       test   BYTE PTR ds:0xf94390,0x1
004af673  8b43fa                               mov    eax,DWORD PTR [ebx-0x6]
004af676  8907                                 mov    DWORD PTR [edi],eax
004af678  7529                                 jne    0x4af6a3
004af67a  830d9043f90001                       or     DWORD PTR ds:0xf94390,0x1
004af681  c744242802000000                     mov    DWORD PTR [esp+0x28],0x2
004af689  e8021f0300                           call   0x4e1590
004af68e  6880ccbc00                           push   0xbccc80
004af693  e8822c3e00                           call   0x89231a
004af698  83c404                               add    esp,0x4
004af69b  c7442428ffffffff                     mov    DWORD PTR [esp+0x28],0xffffffff
004af6a3  8b153039f900                         mov    edx,DWORD PTR ds:0xf93930
004af6a9  33c9                                 xor    ecx,ecx
004af6ab  3b17                                 cmp    edx,DWORD PTR [edi]
004af6ad  0f94c1                               sete   cl
004af6b0  f6052cb2fa0001                       test   BYTE PTR ds:0xfab22c,0x1
004af6b7  894f1c                               mov    DWORD PTR [edi+0x1c],ecx
004af6ba  7529                                 jne    0x4af6e5
004af6bc  830d2cb2fa0001                       or     DWORD PTR ds:0xfab22c,0x1
004af6c3  c744242803000000                     mov    DWORD PTR [esp+0x28],0x3
004af6cb  e8c0f50200                           call   0x4dec90
004af6d0  6830cebc00                           push   0xbcce30
004af6d5  e8402c3e00                           call   0x89231a
004af6da  83c404                               add    esp,0x4
004af6dd  c7442428ffffffff                     mov    DWORD PTR [esp+0x28],0xffffffff
004af6e5  6830b1fa00                           push   0xfab130
004af6ea  8bcf                                 mov    ecx,edi
004af6ec  e8bf080300                           call   0x4dffb0
004af6f1  f6059043f90001                       test   BYTE PTR ds:0xf94390,0x1
004af6f8  8b43fa                               mov    eax,DWORD PTR [ebx-0x6]
004af6fb  8907                                 mov    DWORD PTR [edi],eax
004af6fd  7529                                 jne    0x4af728
004af6ff  830d9043f90001                       or     DWORD PTR ds:0xf94390,0x1
004af706  c744242804000000                     mov    DWORD PTR [esp+0x28],0x4
004af70e  e87d1e0300                           call   0x4e1590
004af713  6880ccbc00                           push   0xbccc80
004af718  e8fd2b3e00                           call   0x89231a
004af71d  83c404                               add    esp,0x4
004af720  c7442428ffffffff                     mov    DWORD PTR [esp+0x28],0xffffffff
004af728  8b37                                 mov    esi,DWORD PTR [edi]
004af72a  33c9                                 xor    ecx,ecx
004af72c  39353039f900                         cmp    DWORD PTR ds:0xf93930,esi
004af732  0f94c1                               sete   cl
004af735  894f1c                               mov    DWORD PTR [edi+0x1c],ecx
004af738  8a43fe                               mov    al,BYTE PTR [ebx-0x2]
004af73b  884720                               mov    BYTE PTR [edi+0x20],al
004af73e  8b03                                 mov    eax,DWORD PTR [ebx]
004af740  89470c                               mov    DWORD PTR [edi+0xc],eax
004af743  0fb7430a                             movzx  eax,WORD PTR [ebx+0xa]
004af747  66894716                             mov    WORD PTR [edi+0x16],ax
004af74b  0fb74308                             movzx  eax,WORD PTR [ebx+0x8]
004af74f  66894714                             mov    WORD PTR [edi+0x14],ax
004af753  8b4304                               mov    eax,DWORD PTR [ebx+0x4]
004af756  894710                               mov    DWORD PTR [edi+0x10],eax
004af759  0fb7430c                             movzx  eax,WORD PTR [ebx+0xc]
004af75d  66894718                             mov    WORD PTR [edi+0x18],ax
004af761  8a43ff                               mov    al,BYTE PTR [ebx-0x1]
004af764  2401                                 and    al,0x1
004af766  884728                               mov    BYTE PTR [edi+0x28],al
004af769  8a43ff                               mov    al,BYTE PTR [ebx-0x1]
004af76c  d0e8                                 shr    al,1
004af76e  2401                                 and    al,0x1
004af770  f6059043f90001                       test   BYTE PTR ds:0xf94390,0x1
004af777  884729                               mov    BYTE PTR [edi+0x29],al
004af77a  0fb7430e                             movzx  eax,WORD PTR [ebx+0xe]
004af77e  0fbfd0                               movsx  edx,ax
004af781  895724                               mov    DWORD PTR [edi+0x24],edx
004af784  7529                                 jne    0x4af7af
004af786  830d9043f90001                       or     DWORD PTR ds:0xf94390,0x1
004af78d  c744242805000000                     mov    DWORD PTR [esp+0x28],0x5
004af795  e8f61d0300                           call   0x4e1590
004af79a  6880ccbc00                           push   0xbccc80
004af79f  e8762b3e00                           call   0x89231a
004af7a4  83c404                               add    esp,0x4
004af7a7  c7442428ffffffff                     mov    DWORD PTR [esp+0x28],0xffffffff
004af7af  3b353039f900                         cmp    esi,DWORD PTR ds:0xf93930
004af7b5  0f853a010000                         jne    0x4af8f5
004af7bb  f6052cb2fa0001                       test   BYTE PTR ds:0xfab22c,0x1
004af7c2  0fb77714                             movzx  esi,WORD PTR [edi+0x14]
004af7c6  89742414                             mov    DWORD PTR [esp+0x14],esi
004af7ca  7529                                 jne    0x4af7f5
004af7cc  830d2cb2fa0001                       or     DWORD PTR ds:0xfab22c,0x1
004af7d3  c744242806000000                     mov    DWORD PTR [esp+0x28],0x6
004af7db  e8b0f40200                           call   0x4dec90
004af7e0  6830cebc00                           push   0xbcce30
004af7e5  e8302b3e00                           call   0x89231a
004af7ea  83c404                               add    esp,0x4
004af7ed  c7442428ffffffff                     mov    DWORD PTR [esp+0x28],0xffffffff
004af7f5  f6057813fb0001                       test   BYTE PTR ds:0xfb1378,0x1
004af7fc  7529                                 jne    0x4af827
004af7fe  830d7813fb0001                       or     DWORD PTR ds:0xfb1378,0x1
004af805  c744242807000000                     mov    DWORD PTR [esp+0x28],0x7
004af80d  e80ea40800                           call   0x539c20
004af812  68b0cfbc00                           push   0xbccfb0
004af817  e8fe2a3e00                           call   0x89231a
004af81c  83c404                               add    esp,0x4
004af81f  c7442428ffffffff                     mov    DWORD PTR [esp+0x28],0xffffffff
004af827  56                                   push   esi
004af828  be8013fb00                           mov    esi,0xfb1380
004af82d  e89eb10800                           call   0x53a9d0
004af832  f605d4adfa0001                       test   BYTE PTR ds:0xfaadd4,0x1
004af839  a35872fb00                           mov    ds:0xfb7258,eax
004af83e  752a                                 jne    0x4af86a
004af840  830dd4adfa0001                       or     DWORD PTR ds:0xfaadd4,0x1
004af847  c744242808000000                     mov    DWORD PTR [esp+0x28],0x8
004af84f  e82c7c0d00                           call   0x587480
004af854  68c0ccbc00                           push   0xbcccc0
004af859  e8bc2a3e00                           call   0x89231a
004af85e  83c404                               add    esp,0x4
004af861  83ceff                               or     esi,0xffffffff
004af864  89742428                             mov    DWORD PTR [esp+0x28],esi
004af868  eb03                                 jmp    0x4af86d
004af86a  83ceff                               or     esi,0xffffffff
004af86d  6804440f00                           push   0xf4404
004af872  e859b20d00                           call   0x58aad0
004af877  668b442418                           mov    ax,WORD PTR [esp+0x18]
004af87c  83c404                               add    esp,0x4
004af87f  f6052cb2fa0001                       test   BYTE PTR ds:0xfab22c,0x1
004af886  66a320b2fa00                         mov    ds:0xfab220,ax
004af88c  8b7f10                               mov    edi,DWORD PTR [edi+0x10]
004af88f  7525                                 jne    0x4af8b6
004af891  830d2cb2fa0001                       or     DWORD PTR ds:0xfab22c,0x1
004af898  c744242809000000                     mov    DWORD PTR [esp+0x28],0x9
004af8a0  e8ebf30200                           call   0x4dec90
004af8a5  6830cebc00                           push   0xbcce30
004af8aa  e86b2a3e00                           call   0x89231a
004af8af  83c404                               add    esp,0x4
004af8b2  89742428                             mov    DWORD PTR [esp+0x28],esi
004af8b6  f6051c7ffc0001                       test   BYTE PTR ds:0xfc7f1c,0x1
004af8bd  7525                                 jne    0x4af8e4
004af8bf  830d1c7ffc0001                       or     DWORD PTR ds:0xfc7f1c,0x1
004af8c6  c74424280a000000                     mov    DWORD PTR [esp+0x28],0xa
004af8ce  e82dca0800                           call   0x53c300
004af8d3  68d0e1bc00                           push   0xbce1d0
004af8d8  e83d2a3e00                           call   0x89231a
004af8dd  83c404                               add    esp,0x4
004af8e0  89742428                             mov    DWORD PTR [esp+0x28],esi
004af8e4  57                                   push   edi
004af8e5  b9207ffc00                           mov    ecx,0xfc7f20
004af8ea  e8e1d50800                           call   0x53ced0
004af8ef  893d24b2fa00                         mov    DWORD PTR ds:0xfab224,edi
004af8f5  83c316                               add    ebx,0x16
004af8f8  ff4c2410                             dec    DWORD PTR [esp+0x10]
004af8fc  0f85d0fcffff                         jne    0x4af5d2
004af902  b800010000                           mov    eax,0x100
004af907  8b4c2420                             mov    ecx,DWORD PTR [esp+0x20]
004af90b  64890d00000000                       mov    DWORD PTR fs:0x0,ecx
004af912  59                                   pop    ecx
004af913  5f                                   pop    edi
004af914  5e                                   pop    esi
004af915  5b                                   pop    ebx
004af916  8be5                                 mov    esp,ebp
004af918  5d                                   pop    ebp
004af919  c20c00                               ret    0xc

# binding_000A | complete binder, reused as consumer
004af920  55                                   push   ebp
004af921  8bec                                 mov    ebp,esp
004af923  83ec14                               sub    esp,0x14
004af926  53                                   push   ebx
004af927  56                                   push   esi
004af928  8b7508                               mov    esi,DWORD PTR [ebp+0x8]
004af92b  8b5e02                               mov    ebx,DWORD PTR [esi+0x2]
004af92e  57                                   push   edi
004af92f  e82cf7f5ff                           call   0x40f060
004af934  8bf8                                 mov    edi,eax
004af936  8d45f8                               lea    eax,[ebp-0x8]
004af939  50                                   push   eax
004af93a  8d4f18                               lea    ecx,[edi+0x18]
004af93d  8d45fc                               lea    eax,[ebp-0x4]
004af940  895df8                               mov    DWORD PTR [ebp-0x8],ebx
004af943  e8783f3900                           call   0x8438c0
004af948  8b45fc                               mov    eax,DWORD PTR [ebp-0x4]
004af94b  3b471c                               cmp    eax,DWORD PTR [edi+0x1c]
004af94e  740c                                 je     0x4af95c
004af950  8b4010                               mov    eax,DWORD PTR [eax+0x10]
004af953  33db                                 xor    ebx,ebx
004af955  8945fc                               mov    DWORD PTR [ebp-0x4],eax
004af958  3bc3                                 cmp    eax,ebx
004af95a  751f                                 jne    0x4af97b
004af95c  8b4e02                               mov    ecx,DWORD PTR [esi+0x2]
004af95f  51                                   push   ecx
004af960  68406ac000                           push   0xc06a40
004af965  e8f6e12300                           call   0x6edb60
004af96a  83c408                               add    esp,0x8
004af96d  5f                                   pop    edi
004af96e  5e                                   pop    esi
004af96f  b805400080                           mov    eax,0x80004005
004af974  5b                                   pop    ebx
004af975  8be5                                 mov    esp,ebp
004af977  5d                                   pop    ebp
004af978  c20c00                               ret    0xc
004af97b  895df8                               mov    DWORD PTR [ebp-0x8],ebx
004af97e  e81d52f5ff                           call   0x404ba0
004af983  8b5602                               mov    edx,DWORD PTR [esi+0x2]
004af986  3b90505f0000                         cmp    edx,DWORD PTR [eax+0x5f50]
004af98c  7521                                 jne    0x4af9af
004af98e  8b0da4a7fb00                         mov    ecx,DWORD PTR ds:0xfba7a4
004af994  8b01                                 mov    eax,DWORD PTR [ecx]
004af996  8b5014                               mov    edx,DWORD PTR [eax+0x14]
004af999  ffd2                                 call   edx
004af99b  8b0da4a7fb00                         mov    ecx,DWORD PTR ds:0xfba7a4
004af9a1  8b01                                 mov    eax,DWORD PTR [ecx]
004af9a3  8b500c                               mov    edx,DWORD PTR [eax+0xc]
004af9a6  ffd2                                 call   edx
004af9a8  c745f801000000                       mov    DWORD PTR [ebp-0x8],0x1
004af9af  385e06                               cmp    BYTE PTR [esi+0x6],bl
004af9b2  0f8e0f010000                         jle    0x4afac7
004af9b8  eb08                                 jmp    0x4af9c2
004af9ba  8d9b00000000                         lea    ebx,[ebx+0x0]
004af9c0  8bf1                                 mov    esi,ecx
004af9c2  0fb7749e07                           movzx  esi,WORD PTR [esi+ebx*4+0x7]
004af9c7  8975f4                               mov    DWORD PTR [ebp-0xc],esi
004af9ca  e891f6f5ff                           call   0x40f060
004af9cf  8bf8                                 mov    edi,eax
004af9d1  8d45f4                               lea    eax,[ebp-0xc]
004af9d4  50                                   push   eax
004af9d5  8d4f08                               lea    ecx,[edi+0x8]
004af9d8  8d45f0                               lea    eax,[ebp-0x10]
004af9db  e820f53700                           call   0x82ef00
004af9e0  8b45f0                               mov    eax,DWORD PTR [ebp-0x10]
004af9e3  3b470c                               cmp    eax,DWORD PTR [edi+0xc]
004af9e6  7407                                 je     0x4af9ef
004af9e8  8b7810                               mov    edi,DWORD PTR [eax+0x10]
004af9eb  85ff                                 test   edi,edi
004af9ed  7512                                 jne    0x4afa01
004af9ef  68706ac000                           push   0xc06a70
004af9f4  e867e12300                           call   0x6edb60
004af9f9  83c404                               add    esp,0x4
004af9fc  e9b6000000                           jmp    0x4afab7
004afa01  8b4508                               mov    eax,DWORD PTR [ebp+0x8]
004afa04  668b4c9807                           mov    cx,WORD PTR [eax+ebx*4+0x7]
004afa09  663b4c9809                           cmp    cx,WORD PTR [eax+ebx*4+0x9]
004afa0e  7427                                 je     0x4afa37
004afa10  837df800                             cmp    DWORD PTR [ebp-0x8],0x0
004afa14  7421                                 je     0x4afa37
004afa16  e845f6f5ff                           call   0x40f060
004afa1b  8b4508                               mov    eax,DWORD PTR [ebp+0x8]
004afa1e  8b0da4a7fb00                         mov    ecx,DWORD PTR ds:0xfba7a4
004afa24  0fb7449809                           movzx  eax,WORD PTR [eax+ebx*4+0x9]
004afa29  8b11                                 mov    edx,DWORD PTR [ecx]
004afa2b  8b5208                               mov    edx,DWORD PTR [edx+0x8]
004afa2e  57                                   push   edi
004afa2f  50                                   push   eax
004afa30  ffd2                                 call   edx
004afa32  e980000000                           jmp    0x4afab7
004afa37  85db                                 test   ebx,ebx
004afa39  7553                                 jne    0x4afa8e
004afa3b  8b45fc                               mov    eax,DWORD PTR [ebp-0x4]
004afa3e  c7879800000001000000                 mov    DWORD PTR [edi+0x98],0x1
004afa48  897004                               mov    DWORD PTR [eax+0x4],esi
004afa4b  8975f4                               mov    DWORD PTR [ebp-0xc],esi
004afa4e  e80df6f5ff                           call   0x40f060
004afa53  8bf0                                 mov    esi,eax
004afa55  8d4df4                               lea    ecx,[ebp-0xc]
004afa58  51                                   push   ecx
004afa59  8d4e08                               lea    ecx,[esi+0x8]
004afa5c  8d45ec                               lea    eax,[ebp-0x14]
004afa5f  e89cf43700                           call   0x82ef00
004afa64  8b45ec                               mov    eax,DWORD PTR [ebp-0x14]
004afa67  3b460c                               cmp    eax,DWORD PTR [esi+0xc]
004afa6a  7416                                 je     0x4afa82
004afa6c  8b4010                               mov    eax,DWORD PTR [eax+0x10]
004afa6f  85c0                                 test   eax,eax
004afa71  740f                                 je     0x4afa82
004afa73  0fb79088000000                       movzx  edx,WORD PTR [eax+0x88]
004afa7a  8b45fc                               mov    eax,DWORD PTR [ebp-0x4]
004afa7d  895008                               mov    DWORD PTR [eax+0x8],edx
004afa80  eb16                                 jmp    0x4afa98
004afa82  8b4dfc                               mov    ecx,DWORD PTR [ebp-0x4]
004afa85  c7410800000000                       mov    DWORD PTR [ecx+0x8],0x0
004afa8c  eb0a                                 jmp    0x4afa98
004afa8e  c7879800000000000000                 mov    DWORD PTR [edi+0x98],0x0
004afa98  837df800                             cmp    DWORD PTR [ebp-0x8],0x0
004afa9c  8b55fc                               mov    edx,DWORD PTR [ebp-0x4]
004afa9f  8b02                                 mov    eax,DWORD PTR [edx]
004afaa1  89879c000000                         mov    DWORD PTR [edi+0x9c],eax
004afaa7  740e                                 je     0x4afab7
004afaa9  8b0da4a7fb00                         mov    ecx,DWORD PTR ds:0xfba7a4
004afaaf  8b11                                 mov    edx,DWORD PTR [ecx]
004afab1  8b4204                               mov    eax,DWORD PTR [edx+0x4]
004afab4  57                                   push   edi
004afab5  ffd0                                 call   eax
004afab7  8b4d08                               mov    ecx,DWORD PTR [ebp+0x8]
004afaba  0fbe5106                             movsx  edx,BYTE PTR [ecx+0x6]
004afabe  43                                   inc    ebx
004afabf  3bda                                 cmp    ebx,edx
004afac1  0f8cf9feffff                         jl     0x4af9c0
004afac7  837df800                             cmp    DWORD PTR [ebp-0x8],0x0
004afacb  740d                                 je     0x4afada
004afacd  8b0da4a7fb00                         mov    ecx,DWORD PTR ds:0xfba7a4
004afad3  8b01                                 mov    eax,DWORD PTR [ecx]
004afad5  8b5010                               mov    edx,DWORD PTR [eax+0x10]
004afad8  ffd2                                 call   edx
004afada  5f                                   pop    edi
004afadb  5e                                   pop    esi
004afadc  b800010000                           mov    eax,0x100
004afae1  5b                                   pop    ebx
004afae2  8be5                                 mov    esp,ebp
004afae4  5d                                   pop    ebp
004afae5  c20c00                               ret    0xc

# avatar_action | complete ordinary world lookup and avatar action
004a0b80  55                                   push   ebp
004a0b81  8bec                                 mov    ebp,esp
004a0b83  83e4f8                               and    esp,0xfffffff8
004a0b86  6aff                                 push   0xffffffff
004a0b88  68fe6e9300                           push   0x936efe
004a0b8d  64a100000000                         mov    eax,fs:0x0
004a0b93  50                                   push   eax
004a0b94  83ec0c                               sub    esp,0xc
004a0b97  a1201fd600                           mov    eax,ds:0xd61f20
004a0b9c  33c4                                 xor    eax,esp
004a0b9e  50                                   push   eax
004a0b9f  8d442410                             lea    eax,[esp+0x10]
004a0ba3  64a300000000                         mov    fs:0x0,eax
004a0ba9  b801000000                           mov    eax,0x1
004a0bae  84052cb2fa00                         test   BYTE PTR ds:0xfab22c,al
004a0bb4  7528                                 jne    0x4a0bde
004a0bb6  09052cb2fa00                         or     DWORD PTR ds:0xfab22c,eax
004a0bbc  c744241800000000                     mov    DWORD PTR [esp+0x18],0x0
004a0bc4  e8c7e00300                           call   0x4dec90
004a0bc9  6830cebc00                           push   0xbcce30
004a0bce  e847173f00                           call   0x89231a
004a0bd3  83c404                               add    esp,0x4
004a0bd6  c7442418ffffffff                     mov    DWORD PTR [esp+0x18],0xffffffff
004a0bde  8b4508                               mov    eax,DWORD PTR [ebp+0x8]
004a0be1  8d4c2404                             lea    ecx,[esp+0x4]
004a0be5  89442404                             mov    DWORD PTR [esp+0x4],eax
004a0be9  51                                   push   ecx
004a0bea  8d44240c                             lea    eax,[esp+0xc]
004a0bee  b938b1fa00                           mov    ecx,0xfab138
004a0bf3  e808e33800                           call   0x82ef00
004a0bf8  8b442408                             mov    eax,DWORD PTR [esp+0x8]
004a0bfc  3b053cb1fa00                         cmp    eax,DWORD PTR ds:0xfab13c
004a0c02  742f                                 je     0x4a0c33
004a0c04  8b4010                               mov    eax,DWORD PTR [eax+0x10]
004a0c07  85c0                                 test   eax,eax
004a0c09  7428                                 je     0x4a0c33
004a0c0b  8b885c010000                         mov    ecx,DWORD PTR [eax+0x15c]
004a0c11  8b5510                               mov    edx,DWORD PTR [ebp+0x10]
004a0c14  66899088030000                       mov    WORD PTR [eax+0x388],dx
004a0c1b  85c9                                 test   ecx,ecx
004a0c1d  7414                                 je     0x4a0c33
004a0c1f  83b87003000000                       cmp    DWORD PTR [eax+0x370],0x0
004a0c26  740b                                 je     0x4a0c33
004a0c28  52                                   push   edx
004a0c29  8b550c                               mov    edx,DWORD PTR [ebp+0xc]
004a0c2c  52                                   push   edx
004a0c2d  51                                   push   ecx
004a0c2e  e86d623000                           call   0x7a6ea0
004a0c33  8b4c2410                             mov    ecx,DWORD PTR [esp+0x10]
004a0c37  64890d00000000                       mov    DWORD PTR fs:0x0,ecx
004a0c3e  59                                   pop    ecx
004a0c3f  8be5                                 mov    esp,ebp
004a0c41  5d                                   pop    ebp
004a0c42  c20c00                               ret    0xc

# attach_action | complete attachment wrapper; descriptor downstream reused
004a0c50  55                                   push   ebp
004a0c51  8bec                                 mov    ebp,esp
004a0c53  83e4f8                               and    esp,0xfffffff8
004a0c56  6aff                                 push   0xffffffff
004a0c58  68fe6e9300                           push   0x936efe
004a0c5d  64a100000000                         mov    eax,fs:0x0
004a0c63  50                                   push   eax
004a0c64  83ec0c                               sub    esp,0xc
004a0c67  a1201fd600                           mov    eax,ds:0xd61f20
004a0c6c  33c4                                 xor    eax,esp
004a0c6e  50                                   push   eax
004a0c6f  8d442410                             lea    eax,[esp+0x10]
004a0c73  64a300000000                         mov    fs:0x0,eax
004a0c79  b801000000                           mov    eax,0x1
004a0c7e  84052cb2fa00                         test   BYTE PTR ds:0xfab22c,al
004a0c84  7528                                 jne    0x4a0cae
004a0c86  09052cb2fa00                         or     DWORD PTR ds:0xfab22c,eax
004a0c8c  c744241800000000                     mov    DWORD PTR [esp+0x18],0x0
004a0c94  e8f7df0300                           call   0x4dec90
004a0c99  6830cebc00                           push   0xbcce30
004a0c9e  e877163f00                           call   0x89231a
004a0ca3  83c404                               add    esp,0x4
004a0ca6  c7442418ffffffff                     mov    DWORD PTR [esp+0x18],0xffffffff
004a0cae  8b4508                               mov    eax,DWORD PTR [ebp+0x8]
004a0cb1  8d4c2404                             lea    ecx,[esp+0x4]
004a0cb5  89442404                             mov    DWORD PTR [esp+0x4],eax
004a0cb9  51                                   push   ecx
004a0cba  8d44240c                             lea    eax,[esp+0xc]
004a0cbe  b938b1fa00                           mov    ecx,0xfab138
004a0cc3  e838e23800                           call   0x82ef00
004a0cc8  8b442408                             mov    eax,DWORD PTR [esp+0x8]
004a0ccc  3b053cb1fa00                         cmp    eax,DWORD PTR ds:0xfab13c
004a0cd2  7429                                 je     0x4a0cfd
004a0cd4  8b4010                               mov    eax,DWORD PTR [eax+0x10]
004a0cd7  85c0                                 test   eax,eax
004a0cd9  7422                                 je     0x4a0cfd
004a0cdb  8b885c010000                         mov    ecx,DWORD PTR [eax+0x15c]
004a0ce1  85c9                                 test   ecx,ecx
004a0ce3  7418                                 je     0x4a0cfd
004a0ce5  83b87003000000                       cmp    DWORD PTR [eax+0x370],0x0
004a0cec  740f                                 je     0x4a0cfd
004a0cee  0fb7550c                             movzx  edx,WORD PTR [ebp+0xc]
004a0cf2  6a00                                 push   0x0
004a0cf4  6a00                                 push   0x0
004a0cf6  52                                   push   edx
004a0cf7  51                                   push   ecx
004a0cf8  e843653000                           call   0x7a7240
004a0cfd  8b4c2410                             mov    ecx,DWORD PTR [esp+0x10]
004a0d01  64890d00000000                       mov    DWORD PTR fs:0x0,ecx
004a0d08  59                                   pop    ecx
004a0d09  8be5                                 mov    esp,ebp
004a0d0b  5d                                   pop    ebp
004a0d0c  c20800                               ret    0x8

# detach_action | complete detach wrapper; paired-slot downstream reused
004a0d10  55                                   push   ebp
004a0d11  8bec                                 mov    ebp,esp
004a0d13  83e4f8                               and    esp,0xfffffff8
004a0d16  6aff                                 push   0xffffffff
004a0d18  68fe6e9300                           push   0x936efe
004a0d1d  64a100000000                         mov    eax,fs:0x0
004a0d23  50                                   push   eax
004a0d24  83ec0c                               sub    esp,0xc
004a0d27  a1201fd600                           mov    eax,ds:0xd61f20
004a0d2c  33c4                                 xor    eax,esp
004a0d2e  50                                   push   eax
004a0d2f  8d442410                             lea    eax,[esp+0x10]
004a0d33  64a300000000                         mov    fs:0x0,eax
004a0d39  b801000000                           mov    eax,0x1
004a0d3e  84052cb2fa00                         test   BYTE PTR ds:0xfab22c,al
004a0d44  7528                                 jne    0x4a0d6e
004a0d46  09052cb2fa00                         or     DWORD PTR ds:0xfab22c,eax
004a0d4c  c744241800000000                     mov    DWORD PTR [esp+0x18],0x0
004a0d54  e837df0300                           call   0x4dec90
004a0d59  6830cebc00                           push   0xbcce30
004a0d5e  e8b7153f00                           call   0x89231a
004a0d63  83c404                               add    esp,0x4
004a0d66  c7442418ffffffff                     mov    DWORD PTR [esp+0x18],0xffffffff
004a0d6e  8b4508                               mov    eax,DWORD PTR [ebp+0x8]
004a0d71  8d4c2404                             lea    ecx,[esp+0x4]
004a0d75  89442404                             mov    DWORD PTR [esp+0x4],eax
004a0d79  51                                   push   ecx
004a0d7a  8d44240c                             lea    eax,[esp+0xc]
004a0d7e  b938b1fa00                           mov    ecx,0xfab138
004a0d83  e878e13800                           call   0x82ef00
004a0d88  8b442408                             mov    eax,DWORD PTR [esp+0x8]
004a0d8c  3b053cb1fa00                         cmp    eax,DWORD PTR ds:0xfab13c
004a0d92  7424                                 je     0x4a0db8
004a0d94  8b4010                               mov    eax,DWORD PTR [eax+0x10]
004a0d97  85c0                                 test   eax,eax
004a0d99  741d                                 je     0x4a0db8
004a0d9b  8b885c010000                         mov    ecx,DWORD PTR [eax+0x15c]
004a0da1  85c9                                 test   ecx,ecx
004a0da3  7413                                 je     0x4a0db8
004a0da5  83b87003000000                       cmp    DWORD PTR [eax+0x370],0x0
004a0dac  740a                                 je     0x4a0db8
004a0dae  8b550c                               mov    edx,DWORD PTR [ebp+0xc]
004a0db1  52                                   push   edx
004a0db2  51                                   push   ecx
004a0db3  e868683000                           call   0x7a7620
004a0db8  8b4c2410                             mov    ecx,DWORD PTR [esp+0x10]
004a0dbc  64890d00000000                       mov    DWORD PTR fs:0x0,ecx
004a0dc3  59                                   pop    ecx
004a0dc4  8be5                                 mov    esp,ebp
004a0dc6  5d                                   pop    ebp
004a0dc7  c20800                               ret    0x8

# doll_avatar_selection | complete catalog/gate and avatar map update
007a6ea0  55                                   push   ebp
007a6ea1  8bec                                 mov    ebp,esp
007a6ea3  6aff                                 push   0xffffffff
007a6ea5  685e919300                           push   0x93915e
007a6eaa  64a100000000                         mov    eax,fs:0x0
007a6eb0  50                                   push   eax
007a6eb1  83ec08                               sub    esp,0x8
007a6eb4  53                                   push   ebx
007a6eb5  56                                   push   esi
007a6eb6  57                                   push   edi
007a6eb7  a1201fd600                           mov    eax,ds:0xd61f20
007a6ebc  33c5                                 xor    eax,ebp
007a6ebe  50                                   push   eax
007a6ebf  8d45f4                               lea    eax,[ebp-0xc]
007a6ec2  64a300000000                         mov    fs:0x0,eax
007a6ec8  8b5d08                               mov    ebx,DWORD PTR [ebp+0x8]
007a6ecb  f605600ffc0001                       test   BYTE PTR ds:0xfc0f60,0x1
007a6ed2  7527                                 jne    0x7a6efb
007a6ed4  830d600ffc0001                       or     DWORD PTR ds:0xfc0f60,0x1
007a6edb  c745fc00000000                       mov    DWORD PTR [ebp-0x4],0x0
007a6ee2  e85960ffff                           call   0x79cf40
007a6ee7  6880dbbc00                           push   0xbcdb80
007a6eec  e829b40e00                           call   0x89231a
007a6ef1  83c404                               add    esp,0x4
007a6ef4  c745fcffffffff                       mov    DWORD PTR [ebp-0x4],0xffffffff
007a6efb  8b4318                               mov    eax,DWORD PTR [ebx+0x18]
007a6efe  8d4d08                               lea    ecx,[ebp+0x8]
007a6f01  894508                               mov    DWORD PTR [ebp+0x8],eax
007a6f04  51                                   push   ecx
007a6f05  8d45f0                               lea    eax,[ebp-0x10]
007a6f08  b9900efc00                           mov    ecx,0xfc0e90
007a6f0d  e87ee8d6ff                           call   0x515790
007a6f12  8b45f0                               mov    eax,DWORD PTR [ebp-0x10]
007a6f15  3b05940efc00                         cmp    eax,DWORD PTR ds:0xfc0e94
007a6f1b  7413                                 je     0x7a6f30
007a6f1d  8b5010                               mov    edx,DWORD PTR [eax+0x10]
007a6f20  8b4254                               mov    eax,DWORD PTR [edx+0x54]
007a6f23  85c0                                 test   eax,eax
007a6f25  7409                                 je     0x7a6f30
007a6f27  83b8bc00000000                       cmp    DWORD PTR [eax+0xbc],0x0
007a6f2e  745f                                 je     0x7a6f8f
007a6f30  8d450c                               lea    eax,[ebp+0xc]
007a6f33  50                                   push   eax
007a6f34  8d4508                               lea    eax,[ebp+0x8]
007a6f37  8d4b4c                               lea    ecx,[ebx+0x4c]
007a6f3a  e8d19bffff                           call   0x7a0b10
007a6f3f  8b4508                               mov    eax,DWORD PTR [ebp+0x8]
007a6f42  3b4350                               cmp    eax,DWORD PTR [ebx+0x50]
007a6f45  740a                                 je     0x7a6f51
007a6f47  668b4d10                             mov    cx,WORD PTR [ebp+0x10]
007a6f4b  6639480e                             cmp    WORD PTR [eax+0xe],cx
007a6f4f  743e                                 je     0x7a6f8f
007a6f51  8d550c                               lea    edx,[ebp+0xc]
007a6f54  52                                   push   edx
007a6f55  8d45ec                               lea    eax,[ebp-0x14]
007a6f58  50                                   push   eax
007a6f59  8d434c                               lea    eax,[ebx+0x4c]
007a6f5c  e86fa6ffff                           call   0x7a15d0
007a6f61  8b4df0                               mov    ecx,DWORD PTR [ebp-0x10]
007a6f64  8b55ec                               mov    edx,DWORD PTR [ebp-0x14]
007a6f67  51                                   push   ecx
007a6f68  52                                   push   edx
007a6f69  8d7508                               lea    esi,[ebp+0x8]
007a6f6c  8d434c                               lea    eax,[ebx+0x4c]
007a6f6f  e8ec31d2ff                           call   0x4ca160
007a6f74  668b7510                             mov    si,WORD PTR [ebp+0x10]
007a6f78  6685f6                               test   si,si
007a6f7b  740e                                 je     0x7a6f8b
007a6f7d  8d550c                               lea    edx,[ebp+0xc]
007a6f80  8d434c                               lea    eax,[ebx+0x4c]
007a6f83  e8089bffff                           call   0x7a0a90
007a6f88  668930                               mov    WORD PTR [eax],si
007a6f8b  c6432801                             mov    BYTE PTR [ebx+0x28],0x1
007a6f8f  8b4df4                               mov    ecx,DWORD PTR [ebp-0xc]
007a6f92  64890d00000000                       mov    DWORD PTR fs:0x0,ecx
007a6f99  59                                   pop    ecx
007a6f9a  5f                                   pop    edi
007a6f9b  5e                                   pop    esi
007a6f9c  5b                                   pop    ebx
007a6f9d  8be5                                 mov    esp,ebp
007a6f9f  5d                                   pop    ebp
007a6fa0  c20c00                               ret    0xc

# field_result_virtual | complete dispatch thunk
00436c40  8b01                                 mov    eax,DWORD PTR [ecx]
00436c42  ff6028                               jmp    DWORD PTR [eax+0x28]

# scenario_result_wrapper | complete ordinary Scenario wrapper
004c4920  55                                   push   ebp
004c4921  8bec                                 mov    ebp,esp
004c4923  6aff                                 push   0xffffffff
004c4925  68ea449400                           push   0x9444ea
004c492a  64a100000000                         mov    eax,fs:0x0
004c4930  50                                   push   eax
004c4931  53                                   push   ebx
004c4932  56                                   push   esi
004c4933  57                                   push   edi
004c4934  a1201fd600                           mov    eax,ds:0xd61f20
004c4939  33c5                                 xor    eax,ebp
004c493b  50                                   push   eax
004c493c  8d45f4                               lea    eax,[ebp-0xc]
004c493f  64a300000000                         mov    fs:0x0,eax
004c4945  8b4510                               mov    eax,DWORD PTR [ebp+0x10]
004c4948  8b750c                               mov    esi,DWORD PTR [ebp+0xc]
004c494b  8b7d08                               mov    edi,DWORD PTR [ebp+0x8]
004c494e  50                                   push   eax
004c494f  56                                   push   esi
004c4950  57                                   push   edi
004c4951  e8eabcfeff                           call   0x4b0640
004c4956  33db                                 xor    ebx,ebx
004c4958  894510                               mov    DWORD PTR [ebp+0x10],eax
004c495b  3bc3                                 cmp    eax,ebx
004c495d  0f8543010000                         jne    0x4c4aa6
004c4963  83fe02                               cmp    esi,0x2
004c4966  7304                                 jae    0x4c496c
004c4968  33f6                                 xor    esi,esi
004c496a  eb0f                                 jmp    0x4c497b
004c496c  83c6fe                               add    esi,0xfffffffe
004c496f  b84fecc44e                           mov    eax,0x4ec4ec4f
004c4974  f7e6                                 mul    esi
004c4976  8bf2                                 mov    esi,edx
004c4978  c1ee02                               shr    esi,0x2
004c497b  f605207afb0001                       test   BYTE PTR ds:0xfb7a20,0x1
004c4982  7523                                 jne    0x4c49a7
004c4984  830d207afb0001                       or     DWORD PTR ds:0xfb7a20,0x1
004c498b  895dfc                               mov    DWORD PTR [ebp-0x4],ebx
004c498e  e80d440800                           call   0x548da0
004c4993  6870d3bc00                           push   0xbcd370
004c4998  e87dd93c00                           call   0x89231a
004c499d  83c404                               add    esp,0x4
004c49a0  c745fcffffffff                       mov    DWORD PTR [ebp-0x4],0xffffffff
004c49a7  e8b4a6f4ff                           call   0x40f060
004c49ac  8b0da4a7fb00                         mov    ecx,DWORD PTR ds:0xfba7a4
004c49b2  8b11                                 mov    edx,DWORD PTR [ecx]
004c49b4  8b421c                               mov    eax,DWORD PTR [edx+0x1c]
004c49b7  53                                   push   ebx
004c49b8  ffd0                                 call   eax
004c49ba  a37c7afb00                           mov    ds:0xfb7a7c,eax
004c49bf  e89ca6f4ff                           call   0x40f060
004c49c4  8b0da4a7fb00                         mov    ecx,DWORD PTR ds:0xfba7a4
004c49ca  8b11                                 mov    edx,DWORD PTR [ecx]
004c49cc  8b421c                               mov    eax,DWORD PTR [edx+0x1c]
004c49cf  6a01                                 push   0x1
004c49d1  ffd0                                 call   eax
004c49d3  a3787afb00                           mov    ds:0xfb7a78,eax
004c49d8  e883a6f4ff                           call   0x40f060
004c49dd  8b0da4a7fb00                         mov    ecx,DWORD PTR ds:0xfba7a4
004c49e3  8b11                                 mov    edx,DWORD PTR [ecx]
004c49e5  8b421c                               mov    eax,DWORD PTR [edx+0x1c]
004c49e8  6a02                                 push   0x2
004c49ea  ffd0                                 call   eax
004c49ec  a3807afb00                           mov    ds:0xfb7a80,eax
004c49f1  891d847afb00                         mov    DWORD PTR ds:0xfb7a84,ebx
004c49f7  891d887afb00                         mov    DWORD PTR ds:0xfb7a88,ebx
004c49fd  3bf3                                 cmp    esi,ebx
004c49ff  765b                                 jbe    0x4c4a5c
004c4a01  83c704                               add    edi,0x4
004c4a04  8bde                                 mov    ebx,esi
004c4a06  8a4702                               mov    al,BYTE PTR [edi+0x2]
004c4a09  84c0                                 test   al,al
004c4a0b  7406                                 je     0x4c4a13
004c4a0d  2c02                                 sub    al,0x2
004c4a0f  3c01                                 cmp    al,0x1
004c4a11  7743                                 ja     0x4c4a56
004c4a13  f605207afb0001                       test   BYTE PTR ds:0xfb7a20,0x1
004c4a1a  7527                                 jne    0x4c4a43
004c4a1c  b801000000                           mov    eax,0x1
004c4a21  0905207afb00                         or     DWORD PTR ds:0xfb7a20,eax
004c4a27  8945fc                               mov    DWORD PTR [ebp-0x4],eax
004c4a2a  e871430800                           call   0x548da0
004c4a2f  6870d3bc00                           push   0xbcd370
004c4a34  e8e1d83c00                           call   0x89231a
004c4a39  83c404                               add    esp,0x4
004c4a3c  c745fcffffffff                       mov    DWORD PTR [ebp-0x4],0xffffffff
004c4a43  0fb70f                               movzx  ecx,WORD PTR [edi]
004c4a46  0fb757fe                             movzx  edx,WORD PTR [edi-0x2]
004c4a4a  51                                   push   ecx
004c4a4b  52                                   push   edx
004c4a4c  be287afb00                           mov    esi,0xfb7a28
004c4a51  e89a5e0800                           call   0x54a8f0
004c4a56  83c70d                               add    edi,0xd
004c4a59  4b                                   dec    ebx
004c4a5a  75aa                                 jne    0x4c4a06
004c4a5c  f605207afb0001                       test   BYTE PTR ds:0xfb7a20,0x1
004c4a63  7520                                 jne    0x4c4a85
004c4a65  830d207afb0001                       or     DWORD PTR ds:0xfb7a20,0x1
004c4a6c  c745fc02000000                       mov    DWORD PTR [ebp-0x4],0x2
004c4a73  e828430800                           call   0x548da0
004c4a78  6870d3bc00                           push   0xbcd370
004c4a7d  e898d83c00                           call   0x89231a
004c4a82  83c404                               add    esp,0x4
004c4a85  8b4510                               mov    eax,DWORD PTR [ebp+0x10]
004c4a88  891d7c7afb00                         mov    DWORD PTR ds:0xfb7a7c,ebx
004c4a8e  891d787afb00                         mov    DWORD PTR ds:0xfb7a78,ebx
004c4a94  891d807afb00                         mov    DWORD PTR ds:0xfb7a80,ebx
004c4a9a  891d847afb00                         mov    DWORD PTR ds:0xfb7a84,ebx
004c4aa0  891d887afb00                         mov    DWORD PTR ds:0xfb7a88,ebx
004c4aa6  8b4df4                               mov    ecx,DWORD PTR [ebp-0xc]
004c4aa9  64890d00000000                       mov    DWORD PTR fs:0x0,ecx
004c4ab0  59                                   pop    ecx
004c4ab1  5f                                   pop    edi
004c4ab2  5e                                   pop    esi
004c4ab3  5b                                   pop    ebx
004c4ab4  8be5                                 mov    esp,ebp
004c4ab6  5d                                   pop    ebp
004c4ab7  c20c00                               ret    0xc

# alternate_result_wrapper | complete second writer caller; context not newly closed
00436b70  55                                   push   ebp
00436b71  8bec                                 mov    ebp,esp
00436b73  6aff                                 push   0xffffffff
00436b75  689e1a9400                           push   0x941a9e
00436b7a  64a100000000                         mov    eax,fs:0x0
00436b80  50                                   push   eax
00436b81  53                                   push   ebx
00436b82  56                                   push   esi
00436b83  57                                   push   edi
00436b84  a1201fd600                           mov    eax,ds:0xd61f20
00436b89  33c5                                 xor    eax,ebp
00436b8b  50                                   push   eax
00436b8c  8d45f4                               lea    eax,[ebp-0xc]
00436b8f  64a300000000                         mov    fs:0x0,eax
00436b95  8b4510                               mov    eax,DWORD PTR [ebp+0x10]
00436b98  8b750c                               mov    esi,DWORD PTR [ebp+0xc]
00436b9b  8b7d08                               mov    edi,DWORD PTR [ebp+0x8]
00436b9e  50                                   push   eax
00436b9f  56                                   push   esi
00436ba0  57                                   push   edi
00436ba1  e89a9a0700                           call   0x4b0640
00436ba6  8bc8                                 mov    ecx,eax
00436ba8  894d10                               mov    DWORD PTR [ebp+0x10],ecx
00436bab  85c9                                 test   ecx,ecx
00436bad  757c                                 jne    0x436c2b
00436baf  83fe02                               cmp    esi,0x2
00436bb2  7304                                 jae    0x436bb8
00436bb4  33d2                                 xor    edx,edx
00436bb6  eb0d                                 jmp    0x436bc5
00436bb8  83c6fe                               add    esi,0xfffffffe
00436bbb  b84fecc44e                           mov    eax,0x4ec4ec4f
00436bc0  f7e6                                 mul    esi
00436bc2  c1ea02                               shr    edx,0x2
00436bc5  85d2                                 test   edx,edx
00436bc7  7460                                 je     0x436c29
00436bc9  83c704                               add    edi,0x4
00436bcc  8bda                                 mov    ebx,edx
00436bce  8bff                                 mov    edi,edi
00436bd0  8a4702                               mov    al,BYTE PTR [edi+0x2]
00436bd3  84c0                                 test   al,al
00436bd5  7406                                 je     0x436bdd
00436bd7  2c02                                 sub    al,0x2
00436bd9  3c01                                 cmp    al,0x1
00436bdb  7746                                 ja     0x436c23
00436bdd  f605207afb0001                       test   BYTE PTR ds:0xfb7a20,0x1
00436be4  7527                                 jne    0x436c0d
00436be6  830d207afb0001                       or     DWORD PTR ds:0xfb7a20,0x1
00436bed  c745fc00000000                       mov    DWORD PTR [ebp-0x4],0x0
00436bf4  e8a7211100                           call   0x548da0
00436bf9  6870d3bc00                           push   0xbcd370
00436bfe  e817b74500                           call   0x89231a
00436c03  83c404                               add    esp,0x4
00436c06  c745fcffffffff                       mov    DWORD PTR [ebp-0x4],0xffffffff
00436c0d  0fb70f                               movzx  ecx,WORD PTR [edi]
00436c10  0fb757fe                             movzx  edx,WORD PTR [edi-0x2]
00436c14  51                                   push   ecx
00436c15  52                                   push   edx
00436c16  be287afb00                           mov    esi,0xfb7a28
00436c1b  e8d03c1100                           call   0x54a8f0
00436c20  8b4d10                               mov    ecx,DWORD PTR [ebp+0x10]
00436c23  83c70d                               add    edi,0xd
00436c26  4b                                   dec    ebx
00436c27  75a7                                 jne    0x436bd0
00436c29  8bc1                                 mov    eax,ecx
00436c2b  8b4df4                               mov    ecx,DWORD PTR [ebp-0xc]
00436c2e  64890d00000000                       mov    DWORD PTR fs:0x0,ecx
00436c35  59                                   pop    ecx
00436c36  5f                                   pop    edi
00436c37  5e                                   pop    esi
00436c38  5b                                   pop    ebx
00436c39  8be5                                 mov    esp,ebp
00436c3b  5d                                   pop    ebp
00436c3c  c20c00                               ret    0xc

# common_result_identity_prefix | selected prefix; rest of combat handler not claimed closed
004b0640  55                                   push   ebp
004b0641  8bec                                 mov    ebp,esp
004b0643  83e4f8                               and    esp,0xfffffff8
004b0646  6aff                                 push   0xffffffff
004b0648  68bf0b9400                           push   0x940bbf
004b064d  64a100000000                         mov    eax,fs:0x0
004b0653  50                                   push   eax
004b0654  81ec98010000                         sub    esp,0x198
004b065a  a1201fd600                           mov    eax,ds:0xd61f20
004b065f  33c4                                 xor    eax,esp
004b0661  89842490010000                       mov    DWORD PTR [esp+0x190],eax
004b0668  53                                   push   ebx
004b0669  56                                   push   esi
004b066a  57                                   push   edi
004b066b  a1201fd600                           mov    eax,ds:0xd61f20
004b0670  33c4                                 xor    eax,esp
004b0672  50                                   push   eax
004b0673  8d8424a8010000                       lea    eax,[esp+0x1a8]
004b067a  64a300000000                         mov    fs:0x0,eax
004b0680  8b4508                               mov    eax,DWORD PTR [ebp+0x8]
004b0683  bb01000000                           mov    ebx,0x1
004b0688  83cfff                               or     edi,0xffffffff
004b068b  89442444                             mov    DWORD PTR [esp+0x44],eax
004b068f  841d9043f900                         test   BYTE PTR ds:0xf94390,bl
004b0695  752a                                 jne    0x4b06c1
004b0697  091d9043f900                         or     DWORD PTR ds:0xf94390,ebx
004b069d  c78424b001000000000000               mov    DWORD PTR [esp+0x1b0],0x0
004b06a8  e8e30e0300                           call   0x4e1590
004b06ad  6880ccbc00                           push   0xbccc80
004b06b2  e8631c3e00                           call   0x89231a
004b06b7  83c404                               add    esp,0x4
004b06ba  89bc24b0010000                       mov    DWORD PTR [esp+0x1b0],edi
004b06c1  f6052cb2fa0001                       test   BYTE PTR ds:0xfab22c,0x1
004b06c8  8b353039f900                         mov    esi,DWORD PTR ds:0xf93930
004b06ce  7526                                 jne    0x4b06f6
004b06d0  091d2cb2fa00                         or     DWORD PTR ds:0xfab22c,ebx
004b06d6  899c24b0010000                       mov    DWORD PTR [esp+0x1b0],ebx
004b06dd  e8aee50200                           call   0x4dec90
004b06e2  6830cebc00                           push   0xbcce30
004b06e7  e82e1c3e00                           call   0x89231a
004b06ec  83c404                               add    esp,0x4
004b06ef  89bc24b0010000                       mov    DWORD PTR [esp+0x1b0],edi
004b06f6  8d4c2434                             lea    ecx,[esp+0x34]
004b06fa  51                                   push   ecx
004b06fb  8d442434                             lea    eax,[esp+0x34]
004b06ff  b948b1fa00                           mov    ecx,0xfab148
004b0704  89742438                             mov    DWORD PTR [esp+0x38],esi
004b0708  e8b3313900                           call   0x8438c0
004b070d  8b442430                             mov    eax,DWORD PTR [esp+0x30]
004b0711  3b054cb1fa00                         cmp    eax,DWORD PTR ds:0xfab14c
004b0717  7406                                 je     0x4b071f
004b0719  83781000                             cmp    DWORD PTR [eax+0x10],0x0
004b071d  7517                                 jne    0x4b0736
004b071f  68506bc000                           push   0xc06b50
004b0724  e837d42300                           call   0x6edb60
004b0729  83c404                               add    esp,0x4
004b072c  b805400080                           mov    eax,0x80004005
004b0731  e9b8110000                           jmp    0x4b18ee
004b0736  8b450c                               mov    eax,DWORD PTR [ebp+0xc]
004b0739  83f802                               cmp    eax,0x2
004b073c  7304                                 jae    0x4b0742
004b073e  33d2                                 xor    edx,edx
004b0740  eb0d                                 jmp    0x4b074f
004b0742  8d50fe                               lea    edx,[eax-0x2]
004b0745  b84fecc44e                           mov    eax,0x4ec4ec4f
004b074a  f7e2                                 mul    edx
004b074c  c1ea02                               shr    edx,0x2
004b074f  89542434                             mov    DWORD PTR [esp+0x34],edx
004b0753  c744243800000000                     mov    DWORD PTR [esp+0x38],0x0
004b075b  85d2                                 test   edx,edx
004b075d  0f8489110000                         je     0x4b18ec
004b0763  eb03                                 jmp    0x4b0768
004b0765  83cfff                               or     edi,0xffffffff
004b0768  8b442438                             mov    eax,DWORD PTR [esp+0x38]
004b076c  8b4c2444                             mov    ecx,DWORD PTR [esp+0x44]
004b0770  6bc00d                               imul   eax,eax,0xd
004b0773  f6052cb2fa0001                       test   BYTE PTR ds:0xfab22c,0x1
004b077a  be01000000                           mov    esi,0x1
004b077f  8d5c0802                             lea    ebx,[eax+ecx*1+0x2]
004b0783  752a                                 jne    0x4b07af
004b0785  09352cb2fa00                         or     DWORD PTR ds:0xfab22c,esi
004b078b  c78424b001000002000000               mov    DWORD PTR [esp+0x1b0],0x2
004b0796  e8f5e40200                           call   0x4dec90
004b079b  6830cebc00                           push   0xbcce30
004b07a0  e8751b3e00                           call   0x89231a
004b07a5  83c404                               add    esp,0x4
004b07a8  89bc24b0010000                       mov    DWORD PTR [esp+0x1b0],edi
004b07af  0fb713                               movzx  edx,WORD PTR [ebx]
004b07b2  8d442420                             lea    eax,[esp+0x20]
004b07b6  50                                   push   eax
004b07b7  8d44245c                             lea    eax,[esp+0x5c]
004b07bb  b938b1fa00                           mov    ecx,0xfab138
004b07c0  89542424                             mov    DWORD PTR [esp+0x24],edx
004b07c4  e837e73700                           call   0x82ef00
004b07c9  8b442458                             mov    eax,DWORD PTR [esp+0x58]
004b07cd  3b053cb1fa00                         cmp    eax,DWORD PTR ds:0xfab13c
004b07d3  750a                                 jne    0x4b07df
004b07d5  c744242800000000                     mov    DWORD PTR [esp+0x28],0x0
004b07dd  eb07                                 jmp    0x4b07e6
004b07df  8b4810                               mov    ecx,DWORD PTR [eax+0x10]
004b07e2  894c2428                             mov    DWORD PTR [esp+0x28],ecx
004b07e6  f6052cb2fa0001                       test   BYTE PTR ds:0xfab22c,0x1
004b07ed  752a                                 jne    0x4b0819
004b07ef  09352cb2fa00                         or     DWORD PTR ds:0xfab22c,esi
004b07f5  c78424b001000003000000               mov    DWORD PTR [esp+0x1b0],0x3
004b0800  e88be40200                           call   0x4dec90
004b0805  6830cebc00                           push   0xbcce30
004b080a  e80b1b3e00                           call   0x89231a
004b080f  83c404                               add    esp,0x4
004b0812  89bc24b0010000                       mov    DWORD PTR [esp+0x1b0],edi
004b0819  0fb75302                             movzx  edx,WORD PTR [ebx+0x2]
004b081d  8d442420                             lea    eax,[esp+0x20]
004b0821  50                                   push   eax
004b0822  8d442444                             lea    eax,[esp+0x44]
004b0826  b938b1fa00                           mov    ecx,0xfab138
004b082b  89542424                             mov    DWORD PTR [esp+0x24],edx
004b082f  e8cce63700                           call   0x82ef00
004b0834  8b442440                             mov    eax,DWORD PTR [esp+0x40]
004b0838  3b053cb1fa00                         cmp    eax,DWORD PTR ds:0xfab13c
004b083e  7504                                 jne    0x4b0844
004b0840  33ff                                 xor    edi,edi
004b0842  eb03                                 jmp    0x4b0847
004b0844  8b7810                               mov    edi,DWORD PTR [eax+0x10]
004b0847  837c242800                           cmp    DWORD PTR [esp+0x28],0x0
004b084c  897c2420                             mov    DWORD PTR [esp+0x20],edi
004b0850  7512                                 jne    0x4b0864
004b0852  68686bc000                           push   0xc06b68
004b0857  e804d32300                           call   0x6edb60
004b085c  83c404                               add    esp,0x4
004b085f  e975100000                           jmp    0x4b18d9
004b0864  85ff                                 test   edi,edi
004b0866  7512                                 jne    0x4b087a
004b0868  68946bc000                           push   0xc06b94
004b086d  e8eed22300                           call   0x6edb60
004b0872  83c404                               add    esp,0x4
004b0875  e95f100000                           jmp    0x4b18d9

# native_AI_owner_constructor | complete CAIControl constructor
00548da0  55                                   push   ebp
00548da1  8bec                                 mov    ebp,esp
00548da3  6aff                                 push   0xffffffff
00548da5  68e8629000                           push   0x9062e8
00548daa  64a100000000                         mov    eax,fs:0x0
00548db0  50                                   push   eax
00548db1  51                                   push   ecx
00548db2  53                                   push   ebx
00548db3  a1201fd600                           mov    eax,ds:0xd61f20
00548db8  33c5                                 xor    eax,ebp
00548dba  50                                   push   eax
00548dbb  8d45f4                               lea    eax,[ebp-0xc]
00548dbe  64a300000000                         mov    fs:0x0,eax
00548dc4  c745f0287afb00                       mov    DWORD PTR [ebp-0x10],0xfb7a28
00548dcb  6890824100                           push   0x418290
00548dd0  6830936800                           push   0x689330
00548dd5  6a03                                 push   0x3
00548dd7  6a10                                 push   0x10
00548dd9  33db                                 xor    ebx,ebx
00548ddb  895dfc                               mov    DWORD PTR [ebp-0x4],ebx
00548dde  68387afb00                           push   0xfb7a38
00548de3  c705287afb0070fbc000                 mov    DWORD PTR ds:0xfb7a28,0xc0fb70
00548ded  e811923400                           call   0x892003
00548df2  0f57c0                               xorps  xmm0,xmm0
00548df5  f30f100d4c5ac500                     movss  xmm1,DWORD PTR ds:0xc55a4c
00548dfd  b801000000                           mov    eax,0x1
00548e02  33c9                                 xor    ecx,ecx
00548e04  f30f11058c7afb00                     movss  DWORD PTR ds:0xfb7a8c,xmm0
00548e0c  f30f1105907afb00                     movss  DWORD PTR ds:0xfb7a90,xmm0
00548e14  f30f110da07afb00                     movss  DWORD PTR ds:0xfb7aa0,xmm1
00548e1c  f30f100d485ac500                     movss  xmm1,DWORD PTR ds:0xc55a48
00548e24  f30f1105b07afb00                     movss  DWORD PTR ds:0xfb7ab0,xmm0
00548e2c  f30f1105c07afb00                     movss  DWORD PTR ds:0xfb7ac0,xmm0
00548e34  f30f1005445ac500                     movss  xmm0,DWORD PTR ds:0xc55a44
00548e3c  a2747afb00                           mov    ds:0xfb7a74,al
00548e41  66890d987afb00                       mov    WORD PTR ds:0xfb7a98,cx
00548e48  a3d47afb00                           mov    ds:0xfb7ad4,eax
00548e4d  a3e47afb00                           mov    ds:0xfb7ae4,eax
00548e52  a3f47afb00                           mov    ds:0xfb7af4,eax
00548e57  a3047bfb00                           mov    ds:0xfb7b04,eax
00548e5c  a3147bfb00                           mov    ds:0xfb7b14,eax
00548e61  a3247bfb00                           mov    ds:0xfb7b24,eax
00548e66  a2cc7afb00                           mov    ds:0xfb7acc,al
00548e6b  891d787afb00                         mov    DWORD PTR ds:0xfb7a78,ebx
00548e71  891d7c7afb00                         mov    DWORD PTR ds:0xfb7a7c,ebx
00548e77  891d807afb00                         mov    DWORD PTR ds:0xfb7a80,ebx
00548e7d  891d847afb00                         mov    DWORD PTR ds:0xfb7a84,ebx
00548e83  891d887afb00                         mov    DWORD PTR ds:0xfb7a88,ebx
00548e89  891d947afb00                         mov    DWORD PTR ds:0xfb7a94,ebx
00548e8f  891dd07afb00                         mov    DWORD PTR ds:0xfb7ad0,ebx
00548e95  891dd87afb00                         mov    DWORD PTR ds:0xfb7ad8,ebx
00548e9b  891ddc7afb00                         mov    DWORD PTR ds:0xfb7adc,ebx
00548ea1  891de07afb00                         mov    DWORD PTR ds:0xfb7ae0,ebx
00548ea7  891de87afb00                         mov    DWORD PTR ds:0xfb7ae8,ebx
00548ead  891dec7afb00                         mov    DWORD PTR ds:0xfb7aec,ebx
00548eb3  891df07afb00                         mov    DWORD PTR ds:0xfb7af0,ebx
00548eb9  891df87afb00                         mov    DWORD PTR ds:0xfb7af8,ebx
00548ebf  891dfc7afb00                         mov    DWORD PTR ds:0xfb7afc,ebx
00548ec5  891d007bfb00                         mov    DWORD PTR ds:0xfb7b00,ebx
00548ecb  891d087bfb00                         mov    DWORD PTR ds:0xfb7b08,ebx
00548ed1  891d0c7bfb00                         mov    DWORD PTR ds:0xfb7b0c,ebx
00548ed7  891d107bfb00                         mov    DWORD PTR ds:0xfb7b10,ebx
00548edd  891d187bfb00                         mov    DWORD PTR ds:0xfb7b18,ebx
00548ee3  891d1c7bfb00                         mov    DWORD PTR ds:0xfb7b1c,ebx
00548ee9  891d207bfb00                         mov    DWORD PTR ds:0xfb7b20,ebx
00548eef  891d287bfb00                         mov    DWORD PTR ds:0xfb7b28,ebx
00548ef5  891d2c7bfb00                         mov    DWORD PTR ds:0xfb7b2c,ebx
00548efb  891d307bfb00                         mov    DWORD PTR ds:0xfb7b30,ebx
00548f01  891d347bfb00                         mov    DWORD PTR ds:0xfb7b34,ebx
00548f07  890d987afb00                         mov    DWORD PTR ds:0xfb7a98,ecx
00548f0d  880d9c7afb00                         mov    BYTE PTR ds:0xfb7a9c,cl
00548f13  f30f110da47afb00                     movss  DWORD PTR ds:0xfb7aa4,xmm1
00548f1b  c705a87afb00461e021e                 mov    DWORD PTR ds:0xfb7aa8,0x1e021e46
00548f25  c605ac7afb0002                       mov    BYTE PTR ds:0xfb7aac,0x2
00548f2c  f30f110db47afb00                     movss  DWORD PTR ds:0xfb7ab4,xmm1
00548f34  c705b87afb00321e001e                 mov    DWORD PTR ds:0xfb7ab8,0x1e001e32
00548f3e  c605bc7afb0003                       mov    BYTE PTR ds:0xfb7abc,0x3
00548f45  f30f1105c47afb00                     movss  DWORD PTR ds:0xfb7ac4,xmm0
00548f4d  c705c87afb0050460046                 mov    DWORD PTR ds:0xfb7ac8,0x46004650
00548f57  b8287afb00                           mov    eax,0xfb7a28
00548f5c  8b4df4                               mov    ecx,DWORD PTR [ebp-0xc]
00548f5f  64890d00000000                       mov    DWORD PTR fs:0x0,ecx
00548f66  59                                   pop    ecx
00548f67  5b                                   pop    ebx
00548f68  8be5                                 mov    esp,ebp
00548f6a  5d                                   pop    ebp
00548f6b  c3                                   ret

# native_AI_pair_writer | complete selected actor-pair target writer
0054a8f0  55                                   push   ebp
0054a8f1  8bec                                 mov    ebp,esp
0054a8f3  51                                   push   ecx
0054a8f4  53                                   push   ebx
0054a8f5  83cbff                               or     ebx,0xffffffff
0054a8f8  57                                   push   edi
0054a8f9  895dfc                               mov    DWORD PTR [ebp-0x4],ebx
0054a8fc  33c0                                 xor    eax,eax
0054a8fe  8d8ea8000000                         lea    ecx,[esi+0xa8]
0054a904  8b7d08                               mov    edi,DWORD PTR [ebp+0x8]
0054a907  3939                                 cmp    DWORD PTR [ecx],edi
0054a909  740b                                 je     0x54a916
0054a90b  40                                   inc    eax
0054a90c  83c110                               add    ecx,0x10
0054a90f  83f803                               cmp    eax,0x3
0054a912  7cf0                                 jl     0x54a904
0054a914  eb03                                 jmp    0x54a919
0054a916  8945fc                               mov    DWORD PTR [ebp-0x4],eax
0054a919  33c0                                 xor    eax,eax
0054a91b  8d8ea8000000                         lea    ecx,[esi+0xa8]
0054a921  8b550c                               mov    edx,DWORD PTR [ebp+0xc]
0054a924  3911                                 cmp    DWORD PTR [ecx],edx
0054a926  740b                                 je     0x54a933
0054a928  40                                   inc    eax
0054a929  83c110                               add    ecx,0x10
0054a92c  83f803                               cmp    eax,0x3
0054a92f  7cf0                                 jl     0x54a921
0054a931  eb02                                 jmp    0x54a935
0054a933  8bd8                                 mov    ebx,eax
0054a935  8b55fc                               mov    edx,DWORD PTR [ebp-0x4]
0054a938  83faff                               cmp    edx,0xffffffff
0054a93b  0f84a0000000                         je     0x54a9e1
0054a941  8b466c                               mov    eax,DWORD PTR [esi+0x6c]
0054a944  33c9                                 xor    ecx,ecx
0054a946  2bc1                                 sub    eax,ecx
0054a948  740b                                 je     0x54a955
0054a94a  48                                   dec    eax
0054a94b  7403                                 je     0x54a950
0054a94d  48                                   dec    eax
0054a94e  752b                                 jne    0x54a97b
0054a950  8b4650                               mov    eax,DWORD PTR [esi+0x50]
0054a953  eb03                                 jmp    0x54a958
0054a955  8b4654                               mov    eax,DWORD PTR [esi+0x54]
0054a958  85c0                                 test   eax,eax
0054a95a  0f84f0000000                         je     0x54aa50
0054a960  56                                   push   esi
0054a961  e88aecffff                           call   0x5495f0
0054a966  83f8ff                               cmp    eax,0xffffffff
0054a969  0f84e1000000                         je     0x54aa50
0054a96f  8b55fc                               mov    edx,DWORD PTR [ebp-0x4]
0054a972  03c0                                 add    eax,eax
0054a974  8d8cc6a8000000                       lea    ecx,[esi+eax*8+0xa8]
0054a97b  85c9                                 test   ecx,ecx
0054a97d  0f84cd000000                         je     0x54aa50
0054a983  8bc2                                 mov    eax,edx
0054a985  03c0                                 add    eax,eax
0054a987  8b84c6a8000000                       mov    eax,DWORD PTR [esi+eax*8+0xa8]
0054a98e  3b01                                 cmp    eax,DWORD PTR [ecx]
0054a990  0f85ba000000                         jne    0x54aa50
0054a996  85d2                                 test   edx,edx
0054a998  7409                                 je     0x54a9a3
0054a99a  83beb000000000                       cmp    DWORD PTR [esi+0xb0],0x0
0054a9a1  750b                                 jne    0x54a9ae
0054a9a3  8b450c                               mov    eax,DWORD PTR [ebp+0xc]
0054a9a6  8986b0000000                         mov    DWORD PTR [esi+0xb0],eax
0054a9ac  eb03                                 jmp    0x54a9b1
0054a9ae  8b450c                               mov    eax,DWORD PTR [ebp+0xc]
0054a9b1  83fa01                               cmp    edx,0x1
0054a9b4  7409                                 je     0x54a9bf
0054a9b6  83bec000000000                       cmp    DWORD PTR [esi+0xc0],0x0
0054a9bd  7506                                 jne    0x54a9c5
0054a9bf  8986c0000000                         mov    DWORD PTR [esi+0xc0],eax
0054a9c5  83fa02                               cmp    edx,0x2
0054a9c8  7409                                 je     0x54a9d3
0054a9ca  83bed000000000                       cmp    DWORD PTR [esi+0xd0],0x0
0054a9d1  757d                                 jne    0x54aa50
0054a9d3  5f                                   pop    edi
0054a9d4  8986d0000000                         mov    DWORD PTR [esi+0xd0],eax
0054a9da  5b                                   pop    ebx
0054a9db  8be5                                 mov    esp,ebp
0054a9dd  5d                                   pop    ebp
0054a9de  c20800                               ret    0x8
0054a9e1  83fbff                               cmp    ebx,0xffffffff
0054a9e4  746a                                 je     0x54aa50
0054a9e6  897d0c                               mov    DWORD PTR [ebp+0xc],edi
0054a9e9  e87246ecff                           call   0x40f060
0054a9ee  8bf8                                 mov    edi,eax
0054a9f0  8d4d0c                               lea    ecx,[ebp+0xc]
0054a9f3  51                                   push   ecx
0054a9f4  8d4f08                               lea    ecx,[edi+0x8]
0054a9f7  8d45fc                               lea    eax,[ebp-0x4]
0054a9fa  e801452e00                           call   0x82ef00
0054a9ff  8b45fc                               mov    eax,DWORD PTR [ebp-0x4]
0054aa02  3b470c                               cmp    eax,DWORD PTR [edi+0xc]
0054aa05  7504                                 jne    0x54aa0b
0054aa07  33ff                                 xor    edi,edi
0054aa09  eb03                                 jmp    0x54aa0e
0054aa0b  8b7810                               mov    edi,DWORD PTR [eax+0x10]
0054aa0e  668b4704                             mov    ax,WORD PTR [edi+0x4]
0054aa12  3c01                                 cmp    al,0x1
0054aa14  7404                                 je     0x54aa1a
0054aa16  84c0                                 test   al,al
0054aa18  7536                                 jne    0x54aa50
0054aa1a  57                                   push   edi
0054aa1b  e890ecf7ff                           call   0x4c96b0
0054aa20  84c0                                 test   al,al
0054aa22  742c                                 je     0x54aa50
0054aa24  8bbf58010000                         mov    edi,DWORD PTR [edi+0x158]
0054aa2a  85ff                                 test   edi,edi
0054aa2c  7422                                 je     0x54aa50
0054aa2e  837f3400                             cmp    DWORD PTR [edi+0x34],0x0
0054aa32  751c                                 jne    0x54aa50
0054aa34  8b4d08                               mov    ecx,DWORD PTR [ebp+0x8]
0054aa37  8d430b                               lea    eax,[ebx+0xb]
0054aa3a  8bd3                                 mov    edx,ebx
0054aa3c  03d2                                 add    edx,edx
0054aa3e  03c0                                 add    eax,eax
0054aa40  833cc600                             cmp    DWORD PTR [esi+eax*8],0x0
0054aa44  898cd6b4000000                       mov    DWORD PTR [esi+edx*8+0xb4],ecx
0054aa4b  7503                                 jne    0x54aa50
0054aa4d  890cc6                               mov    DWORD PTR [esi+eax*8],ecx
0054aa50  5f                                   pop    edi
0054aa51  5b                                   pop    ebx
0054aa52  8be5                                 mov    esp,ebp
0054aa54  5d                                   pop    ebp
0054aa55  c20800                               ret    0x8

# writer_relation_predicate | complete relation predicate; not an alive getter
004c96b0  55                                   push   ebp
004c96b1  8bec                                 mov    ebp,esp
004c96b3  83e4f8                               and    esp,0xfffffff8
004c96b6  6aff                                 push   0xffffffff
004c96b8  685c6a9300                           push   0x936a5c
004c96bd  64a100000000                         mov    eax,fs:0x0
004c96c3  50                                   push   eax
004c96c4  51                                   push   ecx
004c96c5  53                                   push   ebx
004c96c6  56                                   push   esi
004c96c7  a1201fd600                           mov    eax,ds:0xd61f20
004c96cc  33c4                                 xor    eax,esp
004c96ce  50                                   push   eax
004c96cf  8d442410                             lea    eax,[esp+0x10]
004c96d3  64a300000000                         mov    fs:0x0,eax
004c96d9  8b0da4a7fb00                         mov    ecx,DWORD PTR ds:0xfba7a4
004c96df  8b01                                 mov    eax,DWORD PTR [ecx]
004c96e1  8b5020                               mov    edx,DWORD PTR [eax+0x20]
004c96e4  ffd2                                 call   edx
004c96e6  85c0                                 test   eax,eax
004c96e8  0f84dd000000                         je     0x4c97cb
004c96ee  8bb090000000                         mov    esi,DWORD PTR [eax+0x90]
004c96f4  bb01000000                           mov    ebx,0x1
004c96f9  841d2cb2fa00                         test   BYTE PTR ds:0xfab22c,bl
004c96ff  7528                                 jne    0x4c9729
004c9701  091d2cb2fa00                         or     DWORD PTR ds:0xfab22c,ebx
004c9707  c744241800000000                     mov    DWORD PTR [esp+0x18],0x0
004c970f  e87c550100                           call   0x4dec90
004c9714  6830cebc00                           push   0xbcce30
004c9719  e8fc8b3c00                           call   0x89231a
004c971e  83c404                               add    esp,0x4
004c9721  c7442418ffffffff                     mov    DWORD PTR [esp+0x18],0xffffffff
004c9729  8bc6                                 mov    eax,esi
004c972b  99                                   cdq
004c972c  83e207                               and    edx,0x7
004c972f  03c2                                 add    eax,edx
004c9731  c1f803                               sar    eax,0x3
004c9734  85c0                                 test   eax,eax
004c9736  7404                                 je     0x4c973c
004c9738  33f6                                 xor    esi,esi
004c973a  eb07                                 jmp    0x4c9743
004c973c  8db476e8b1fa00                       lea    esi,[esi+esi*2+0xfab1e8]
004c9743  841d2cb2fa00                         test   BYTE PTR ds:0xfab22c,bl
004c9749  751c                                 jne    0x4c9767
004c974b  091d2cb2fa00                         or     DWORD PTR ds:0xfab22c,ebx
004c9751  895c2418                             mov    DWORD PTR [esp+0x18],ebx
004c9755  e836550100                           call   0x4dec90
004c975a  6830cebc00                           push   0xbcce30
004c975f  e8b68b3c00                           call   0x89231a
004c9764  83c404                               add    esp,0x4
004c9767  8b4508                               mov    eax,DWORD PTR [ebp+0x8]
004c976a  8b8890000000                         mov    ecx,DWORD PTR [eax+0x90]
004c9770  8bc1                                 mov    eax,ecx
004c9772  99                                   cdq
004c9773  83e207                               and    edx,0x7
004c9776  03c2                                 add    eax,edx
004c9778  c1f803                               sar    eax,0x3
004c977b  85c0                                 test   eax,eax
004c977d  7404                                 je     0x4c9783
004c977f  33c0                                 xor    eax,eax
004c9781  eb07                                 jmp    0x4c978a
004c9783  8d8449e8b1fa00                       lea    eax,[ecx+ecx*2+0xfab1e8]
004c978a  85f6                                 test   esi,esi
004c978c  7427                                 je     0x4c97b5
004c978e  85c0                                 test   eax,eax
004c9790  7423                                 je     0x4c97b5
004c9792  8bd6                                 mov    edx,esi
004c9794  e8c7d7ffff                           call   0x4c6f60
004c9799  33c9                                 xor    ecx,ecx
004c979b  83f812                               cmp    eax,0x12
004c979e  0f94c0                               sete   al
004c97a1  8b4c2410                             mov    ecx,DWORD PTR [esp+0x10]
004c97a5  64890d00000000                       mov    DWORD PTR fs:0x0,ecx
004c97ac  59                                   pop    ecx
004c97ad  5e                                   pop    esi
004c97ae  5b                                   pop    ebx
004c97af  8be5                                 mov    esp,ebp
004c97b1  5d                                   pop    ebp
004c97b2  c20400                               ret    0x4
004c97b5  8ac3                                 mov    al,bl
004c97b7  8b4c2410                             mov    ecx,DWORD PTR [esp+0x10]
004c97bb  64890d00000000                       mov    DWORD PTR fs:0x0,ecx
004c97c2  59                                   pop    ecx
004c97c3  5e                                   pop    esi
004c97c4  5b                                   pop    ebx
004c97c5  8be5                                 mov    esp,ebp
004c97c7  5d                                   pop    ebp
004c97c8  c20400                               ret    0x4
004c97cb  32c0                                 xor    al,al
004c97cd  8b4c2410                             mov    ecx,DWORD PTR [esp+0x10]
004c97d1  64890d00000000                       mov    DWORD PTR fs:0x0,ecx
004c97d8  59                                   pop    ecx
004c97d9  5e                                   pop    esi
004c97da  5b                                   pop    ebx
004c97db  8be5                                 mov    esp,ebp
004c97dd  5d                                   pop    ebp
004c97de  c20400                               ret    0x4

# native_AI_pair_reader | complete reader code excluding switch table
0054aa60  55                                   push   ebp
0054aa61  8bec                                 mov    ebp,esp
0054aa63  51                                   push   ecx
0054aa64  53                                   push   ebx
0054aa65  56                                   push   esi
0054aa66  33db                                 xor    ebx,ebx
0054aa68  57                                   push   edi
0054aa69  8bf1                                 mov    esi,ecx
0054aa6b  83f804                               cmp    eax,0x4
0054aa6e  0f87db000000                         ja     0x54ab4f
0054aa74  ff24855cab5400                       jmp    DWORD PTR [eax*4+0x54ab5c]
0054aa7b  8b8608010000                         mov    eax,DWORD PTR [esi+0x108]
0054aa81  03c0                                 add    eax,eax
0054aa83  8d84c6a8000000                       lea    eax,[esi+eax*8+0xa8]
0054aa8a  eb5d                                 jmp    0x54aae9
0054aa8c  8b4654                               mov    eax,DWORD PTR [esi+0x54]
0054aa8f  56                                   push   esi
0054aa90  e85bebffff                           call   0x5495f0
0054aa95  83f8ff                               cmp    eax,0xffffffff
0054aa98  0f84b1000000                         je     0x54ab4f
0054aa9e  03c0                                 add    eax,eax
0054aaa0  8d84c6a8000000                       lea    eax,[esi+eax*8+0xa8]
0054aaa7  eb40                                 jmp    0x54aae9
0054aaa9  8b466c                               mov    eax,DWORD PTR [esi+0x6c]
0054aaac  33ff                                 xor    edi,edi
0054aaae  2bc7                                 sub    eax,edi
0054aab0  745c                                 je     0x54ab0e
0054aab2  48                                   dec    eax
0054aab3  7403                                 je     0x54aab8
0054aab5  48                                   dec    eax
0054aab6  752f                                 jne    0x54aae7
0054aab8  8b4650                               mov    eax,DWORD PTR [esi+0x50]
0054aabb  eb12                                 jmp    0x54aacf
0054aabd  8b466c                               mov    eax,DWORD PTR [esi+0x6c]
0054aac0  33ff                                 xor    edi,edi
0054aac2  2bc7                                 sub    eax,edi
0054aac4  74f2                                 je     0x54aab8
0054aac6  48                                   dec    eax
0054aac7  7445                                 je     0x54ab0e
0054aac9  48                                   dec    eax
0054aaca  751b                                 jne    0x54aae7
0054aacc  8b4658                               mov    eax,DWORD PTR [esi+0x58]
0054aacf  85c0                                 test   eax,eax
0054aad1  7414                                 je     0x54aae7
0054aad3  56                                   push   esi
0054aad4  e817ebffff                           call   0x5495f0
0054aad9  83f8ff                               cmp    eax,0xffffffff
0054aadc  7409                                 je     0x54aae7
0054aade  03c0                                 add    eax,eax
0054aae0  8dbcc6a8000000                       lea    edi,[esi+eax*8+0xa8]
0054aae7  8bc7                                 mov    eax,edi
0054aae9  85c0                                 test   eax,eax
0054aaeb  7462                                 je     0x54ab4f
0054aaed  8b4d08                               mov    ecx,DWORD PTR [ebp+0x8]
0054aaf0  2bcb                                 sub    ecx,ebx
0054aaf2  7424                                 je     0x54ab18
0054aaf4  49                                   dec    ecx
0054aaf5  741c                                 je     0x54ab13
0054aaf7  49                                   dec    ecx
0054aaf8  7555                                 jne    0x54ab4f
0054aafa  8b400c                               mov    eax,DWORD PTR [eax+0xc]
0054aafd  eb1b                                 jmp    0x54ab1a
0054aaff  8b466c                               mov    eax,DWORD PTR [esi+0x6c]
0054ab02  33ff                                 xor    edi,edi
0054ab04  2bc7                                 sub    eax,edi
0054ab06  74c4                                 je     0x54aacc
0054ab08  48                                   dec    eax
0054ab09  74c1                                 je     0x54aacc
0054ab0b  48                                   dec    eax
0054ab0c  75d9                                 jne    0x54aae7
0054ab0e  8b4654                               mov    eax,DWORD PTR [esi+0x54]
0054ab11  ebbc                                 jmp    0x54aacf
0054ab13  8b4008                               mov    eax,DWORD PTR [eax+0x8]
0054ab16  eb02                                 jmp    0x54ab1a
0054ab18  8b00                                 mov    eax,DWORD PTR [eax]
0054ab1a  85c0                                 test   eax,eax
0054ab1c  7431                                 je     0x54ab4f
0054ab1e  894508                               mov    DWORD PTR [ebp+0x8],eax
0054ab21  e83a45ecff                           call   0x40f060
0054ab26  8bf0                                 mov    esi,eax
0054ab28  8d4d08                               lea    ecx,[ebp+0x8]
0054ab2b  51                                   push   ecx
0054ab2c  8d4e08                               lea    ecx,[esi+0x8]
0054ab2f  8d45fc                               lea    eax,[ebp-0x4]
0054ab32  e8c9432e00                           call   0x82ef00
0054ab37  8b45fc                               mov    eax,DWORD PTR [ebp-0x4]
0054ab3a  3b460c                               cmp    eax,DWORD PTR [esi+0xc]
0054ab3d  750d                                 jne    0x54ab4c
0054ab3f  33db                                 xor    ebx,ebx
0054ab41  8bc3                                 mov    eax,ebx
0054ab43  5f                                   pop    edi
0054ab44  5e                                   pop    esi
0054ab45  5b                                   pop    ebx
0054ab46  8be5                                 mov    esp,ebp
0054ab48  5d                                   pop    ebp
0054ab49  c20400                               ret    0x4
0054ab4c  8b5810                               mov    ebx,DWORD PTR [eax+0x10]
0054ab4f  5f                                   pop    edi
0054ab50  5e                                   pop    esi
0054ab51  8bc3                                 mov    eax,ebx
0054ab53  5b                                   pop    ebx
0054ab54  8be5                                 mov    esp,ebp
0054ab56  5d                                   pop    ebp
0054ab57  c20400                               ret    0x4

# pair_reader_caller_1 | caller prefix only; native return use
00549660  55                                   push   ebp
00549661  8bec                                 mov    ebp,esp
00549663  83e4f8                               and    esp,0xfffffff8
00549666  83ec20                               sub    esp,0x20
00549669  8b4650                               mov    eax,DWORD PTR [esi+0x50]
0054966c  8a88b0000000                         mov    cl,BYTE PTR [eax+0xb0]
00549672  8b4508                               mov    eax,DWORD PTR [ebp+0x8]
00549675  53                                   push   ebx
00549676  8b5d0c                               mov    ebx,DWORD PTR [ebp+0xc]
00549679  57                                   push   edi
0054967a  884c240e                             mov    BYTE PTR [esp+0xe],cl
0054967e  53                                   push   ebx
0054967f  8bce                                 mov    ecx,esi
00549681  c644241301                           mov    BYTE PTR [esp+0x13],0x1
00549686  e8d5130000                           call   0x54aa60
0054968b  8bf8                                 mov    edi,eax
0054968d  85ff                                 test   edi,edi
0054968f  0f84d3000000                         je     0x549768

# pair_reader_caller_2 | caller prefix only; native return use
00549c60  55                                   push   ebp
00549c61  8bec                                 mov    ebp,esp
00549c63  83e4f8                               and    esp,0xfffffff8
00549c66  6aff                                 push   0xffffffff
00549c68  68deed9300                           push   0x93edde
00549c6d  64a100000000                         mov    eax,fs:0x0
00549c73  50                                   push   eax
00549c74  83ec14                               sub    esp,0x14
00549c77  53                                   push   ebx
00549c78  57                                   push   edi
00549c79  a1201fd600                           mov    eax,ds:0xd61f20
00549c7e  33c4                                 xor    eax,esp
00549c80  50                                   push   eax
00549c81  8d442420                             lea    eax,[esp+0x20]
00549c85  64a300000000                         mov    fs:0x0,eax
00549c8b  8b450c                               mov    eax,DWORD PTR [ebp+0xc]
00549c8e  50                                   push   eax
00549c8f  8b4508                               mov    eax,DWORD PTR [ebp+0x8]
00549c92  8bce                                 mov    ecx,esi
00549c94  e8c70d0000                           call   0x54aa60
00549c99  8b4d14                               mov    ecx,DWORD PTR [ebp+0x14]
00549c9c  33d2                                 xor    edx,edx
00549c9e  89442418                             mov    DWORD PTR [esp+0x18],eax
00549ca2  89542414                             mov    DWORD PTR [esp+0x14],edx
00549ca6  e875f0ffff                           call   0x548d20

# quest_intent_builder | complete 00DF producer; not death/Lua ACK
00501650  55                                   push   ebp
00501651  8bec                                 mov    ebp,esp
00501653  83ec08                               sub    esp,0x8
00501656  53                                   push   ebx
00501657  668b5d08                             mov    bx,WORD PTR [ebp+0x8]
0050165b  56                                   push   esi
0050165c  57                                   push   edi
0050165d  33ff                                 xor    edi,edi
0050165f  e8fcd9f0ff                           call   0x40f060
00501664  8b4004                               mov    eax,DWORD PTR [eax+0x4]
00501667  8b7010                               mov    esi,DWORD PTR [eax+0x10]
0050166a  8b4814                               mov    ecx,DWORD PTR [eax+0x14]
0050166d  2bce                                 sub    ecx,esi
0050166f  b8abaaaa2a                           mov    eax,0x2aaaaaab
00501674  f7e9                                 imul   ecx
00501676  c1fa02                               sar    edx,0x2
00501679  8bc2                                 mov    eax,edx
0050167b  c1e81f                               shr    eax,0x1f
0050167e  03c2                                 add    eax,edx
00501680  7463                                 je     0x5016e5
00501682  8d4e0c                               lea    ecx,[esi+0xc]
00501685  ba0b000000                           mov    edx,0xb
0050168a  8d9b00000000                         lea    ebx,[ebx+0x0]
00501690  663951f8                             cmp    WORD PTR [ecx-0x8],dx
00501694  7515                                 jne    0x5016ab
00501696  0fb7f3                               movzx  esi,bx
00501699  3931                                 cmp    DWORD PTR [ecx],esi
0050169b  750e                                 jne    0x5016ab
0050169d  668b71fc                             mov    si,WORD PTR [ecx-0x4]
005016a1  663b71fa                             cmp    si,WORD PTR [ecx-0x6]
005016a5  7d04                                 jge    0x5016ab
005016a7  0fb77908                             movzx  edi,WORD PTR [ecx+0x8]
005016ab  83c118                               add    ecx,0x18
005016ae  48                                   dec    eax
005016af  75df                                 jne    0x501690
005016b1  6685ff                               test   di,di
005016b4  742f                                 je     0x5016e5
005016b6  833d98a7fb0000                       cmp    DWORD PTR ds:0xfba798,0x0
005016bd  b8df000000                           mov    eax,0xdf
005016c2  668945f8                             mov    WORD PTR [ebp-0x8],ax
005016c6  66897dfa                             mov    WORD PTR [ebp-0x6],di
005016ca  66895dfc                             mov    WORD PTR [ebp-0x4],bx
005016ce  7515                                 jne    0x5016e5
005016d0  8b0d54a8fb00                         mov    ecx,DWORD PTR ds:0xfba854
005016d6  8b11                                 mov    edx,DWORD PTR [ecx]
005016d8  8b5210                               mov    edx,DWORD PTR [edx+0x10]
005016db  6a06                                 push   0x6
005016dd  8d45f8                               lea    eax,[ebp-0x8]
005016e0  50                                   push   eax
005016e1  6a00                                 push   0x0
005016e3  ffd2                                 call   edx
005016e5  5f                                   pop    edi
005016e6  5e                                   pop    esi
005016e7  5b                                   pop    ebx
005016e8  8be5                                 mov    esp,ebp
005016ea  5d                                   pop    ebp
005016eb  c20400                               ret    0x4

# skill_event_trigger | complete selected skill-event producer, not full skill consumer
004b01c0  55                                   push   ebp
004b01c1  8bec                                 mov    ebp,esp
004b01c3  83e4f8                               and    esp,0xfffffff8
004b01c6  6aff                                 push   0xffffffff
004b01c8  68ca7d9400                           push   0x947dca
004b01cd  64a100000000                         mov    eax,fs:0x0
004b01d3  50                                   push   eax
004b01d4  83ec18                               sub    esp,0x18
004b01d7  53                                   push   ebx
004b01d8  56                                   push   esi
004b01d9  57                                   push   edi
004b01da  a1201fd600                           mov    eax,ds:0xd61f20
004b01df  33c4                                 xor    eax,esp
004b01e1  50                                   push   eax
004b01e2  8d442428                             lea    eax,[esp+0x28]
004b01e6  64a300000000                         mov    fs:0x0,eax
004b01ec  8b450c                               mov    eax,DWORD PTR [ebp+0xc]
004b01ef  83f802                               cmp    eax,0x2
004b01f2  7304                                 jae    0x4b01f8
004b01f4  33d2                                 xor    edx,edx
004b01f6  eb0c                                 jmp    0x4b0204
004b01f8  8d48fe                               lea    ecx,[eax-0x2]
004b01fb  b8398ee338                           mov    eax,0x38e38e39
004b0200  f7e1                                 mul    ecx
004b0202  d1ea                                 shr    edx,1
004b0204  33db                                 xor    ebx,ebx
004b0206  3bd3                                 cmp    edx,ebx
004b0208  0f86a1010000                         jbe    0x4b03af
004b020e  8b7d08                               mov    edi,DWORD PTR [ebp+0x8]
004b0211  83c705                               add    edi,0x5
004b0214  897c2414                             mov    DWORD PTR [esp+0x14],edi
004b0218  89542418                             mov    DWORD PTR [esp+0x18],edx
004b021c  eb04                                 jmp    0x4b0222
004b021e  8bff                                 mov    edi,edi
004b0220  33db                                 xor    ebx,ebx
004b0222  f6052cb2fa0001                       test   BYTE PTR ds:0xfab22c,0x1
004b0229  7525                                 jne    0x4b0250
004b022b  830d2cb2fa0001                       or     DWORD PTR ds:0xfab22c,0x1
004b0232  895c2430                             mov    DWORD PTR [esp+0x30],ebx
004b0236  e855ea0200                           call   0x4dec90
004b023b  6830cebc00                           push   0xbcce30
004b0240  e8d5203e00                           call   0x89231a
004b0245  83c404                               add    esp,0x4
004b0248  c7442430ffffffff                     mov    DWORD PTR [esp+0x30],0xffffffff
004b0250  0fb757fd                             movzx  edx,WORD PTR [edi-0x3]
004b0254  8d44241c                             lea    eax,[esp+0x1c]
004b0258  50                                   push   eax
004b0259  8d442424                             lea    eax,[esp+0x24]
004b025d  b938b1fa00                           mov    ecx,0xfab138
004b0262  89542420                             mov    DWORD PTR [esp+0x20],edx
004b0266  e895ec3700                           call   0x82ef00
004b026b  8b442420                             mov    eax,DWORD PTR [esp+0x20]
004b026f  3b053cb1fa00                         cmp    eax,DWORD PTR ds:0xfab13c
004b0275  7407                                 je     0x4b027e
004b0277  8b7010                               mov    esi,DWORD PTR [eax+0x10]
004b027a  3bf3                                 cmp    esi,ebx
004b027c  7512                                 jne    0x4b0290
004b027e  68246bc000                           push   0xc06b24
004b0283  e8d8d82300                           call   0x6edb60
004b0288  83c404                               add    esp,0x4
004b028b  e90e010000                           jmp    0x4b039e
004b0290  0fb647ff                             movzx  eax,BYTE PTR [edi-0x1]
004b0294  8b16                                 mov    edx,DWORD PTR [esi]
004b0296  8b5258                               mov    edx,DWORD PTR [edx+0x58]
004b0299  50                                   push   eax
004b029a  8bce                                 mov    ecx,esi
004b029c  ffd2                                 call   edx
004b029e  399ea8030000                         cmp    DWORD PTR [esi+0x3a8],ebx
004b02a4  7406                                 je     0x4b02ac
004b02a6  899ea8030000                         mov    DWORD PTR [esi+0x3a8],ebx
004b02ac  83bea803000000                       cmp    DWORD PTR [esi+0x3a8],0x0
004b02b3  8a9eb0000000                         mov    bl,BYTE PTR [esi+0xb0]
004b02b9  7554                                 jne    0x4b030f
004b02bb  83be7003000000                       cmp    DWORD PTR [esi+0x370],0x0
004b02c2  889ea4030000                         mov    BYTE PTR [esi+0x3a4],bl
004b02c8  7445                                 je     0x4b030f
004b02ca  8b865c010000                         mov    eax,DWORD PTR [esi+0x15c]
004b02d0  85c0                                 test   eax,eax
004b02d2  743b                                 je     0x4b030f
004b02d4  f605187cfb0001                       test   BYTE PTR ds:0xfb7c18,0x1
004b02db  8d7804                               lea    edi,[eax+0x4]
004b02de  750c                                 jne    0x4b02ec
004b02e0  830d187cfb0001                       or     DWORD PTR ds:0xfb7c18,0x1
004b02e7  e8e446f9ff                           call   0x4449d0
004b02ec  8b17                                 mov    edx,DWORD PTR [edi]
004b02ee  0fb6c3                               movzx  eax,bl
004b02f1  51                                   push   ecx
004b02f2  8bcf                                 mov    ecx,edi
004b02f4  d90485207cfb00                       fld    DWORD PTR [eax*4+0xfb7c20]
004b02fb  8b420c                               mov    eax,DWORD PTR [edx+0xc]
004b02fe  d95c2420                             fstp   DWORD PTR [esp+0x20]
004b0302  d9442420                             fld    DWORD PTR [esp+0x20]
004b0306  d91c24                               fstp   DWORD PTR [esp]
004b0309  ffd0                                 call   eax
004b030b  8b7c2414                             mov    edi,DWORD PTR [esp+0x14]
004b030f  d94702                               fld    DWORD PTR [edi+0x2]
004b0312  51                                   push   ecx
004b0313  0fb70f                               movzx  ecx,WORD PTR [edi]
004b0316  d91c24                               fstp   DWORD PTR [esp]
004b0319  51                                   push   ecx
004b031a  e871870100                           call   0x4c8a90
004b031f  f6059043f90001                       test   BYTE PTR ds:0xf94390,0x1
004b0326  8bb69c000000                         mov    esi,DWORD PTR [esi+0x9c]
004b032c  7529                                 jne    0x4b0357
004b032e  b801000000                           mov    eax,0x1
004b0333  09059043f900                         or     DWORD PTR ds:0xf94390,eax
004b0339  89442430                             mov    DWORD PTR [esp+0x30],eax
004b033d  e84e120300                           call   0x4e1590
004b0342  6880ccbc00                           push   0xbccc80
004b0347  e8ce1f3e00                           call   0x89231a
004b034c  83c404                               add    esp,0x4
004b034f  c7442430ffffffff                     mov    DWORD PTR [esp+0x30],0xffffffff
004b0357  3b353039f900                         cmp    esi,DWORD PTR ds:0xf93930
004b035d  753f                                 jne    0x4b039e
004b035f  66833f12                             cmp    WORD PTR [edi],0x12
004b0363  7539                                 jne    0x4b039e
004b0365  f6059cb2fa0001                       test   BYTE PTR ds:0xfab29c,0x1
004b036c  7529                                 jne    0x4b0397
004b036e  830d9cb2fa0001                       or     DWORD PTR ds:0xfab29c,0x1
004b0375  c744243002000000                     mov    DWORD PTR [esp+0x30],0x2
004b037d  e8defa0400                           call   0x4ffe60
004b0382  6800cfbc00                           push   0xbccf00
004b0387  e88e1f3e00                           call   0x89231a
004b038c  83c404                               add    esp,0x4
004b038f  c7442430ffffffff                     mov    DWORD PTR [esp+0x30],0xffffffff
004b0397  6a0a                                 push   0xa
004b0399  e8b2120500                           call   0x501650
004b039e  83c709                               add    edi,0x9
004b03a1  ff4c2418                             dec    DWORD PTR [esp+0x18]
004b03a5  897c2414                             mov    DWORD PTR [esp+0x14],edi
004b03a9  0f8571feffff                         jne    0x4b0220
004b03af  33c0                                 xor    eax,eax
004b03b1  8b4c2428                             mov    ecx,DWORD PTR [esp+0x28]
004b03b5  64890d00000000                       mov    DWORD PTR fs:0x0,ecx
004b03bc  59                                   pop    ecx
004b03bd  5f                                   pop    edi
004b03be  5e                                   pop    esi
004b03bf  5b                                   pop    ebx
004b03c0  8be5                                 mov    esp,ebp
004b03c2  5d                                   pop    ebp
004b03c3  c20c00                               ret    0xc
