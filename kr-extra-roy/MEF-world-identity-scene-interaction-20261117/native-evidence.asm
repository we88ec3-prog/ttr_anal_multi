
; lb_change_map 0x4a0ac0..0x4a0b3c raw=0x9fec0 SHA256=cc2def6a56400c5081242e16e2976bf5ec582ec296f9e4e1b5731f53f45ac382
0x4a0ac0     55                               push   ebp
0x4a0ac1     8bec                             mov    ebp,esp
0x4a0ac3     83e4f8                           and    esp,0xfffffff8
0x4a0ac6     6aff                             push   0xffffffff
0x4a0ac8     68ee619400                       push   0x9461ee
0x4a0acd     64a100000000                     mov    eax,fs:0x0
0x4a0ad3     50                               push   eax
0x4a0ad4     51                               push   ecx
0x4a0ad5     a1201fd600                       mov    eax,ds:0xd61f20
0x4a0ada     33c4                             xor    eax,esp
0x4a0adc     50                               push   eax
0x4a0add     8d442408                         lea    eax,[esp+0x8]
0x4a0ae1     64a300000000                     mov    fs:0x0,eax
0x4a0ae7     b801000000                       mov    eax,0x1
0x4a0aec     84052cb2fa00                     test   BYTE PTR ds:0xfab22c,al
0x4a0af2     7528                             jne    0x4a0b1c
0x4a0af4     09052cb2fa00                     or     DWORD PTR ds:0xfab22c,eax
0x4a0afa     c744241000000000                 mov    DWORD PTR [esp+0x10],0x0
0x4a0b02     e889e10300                       call   0x4dec90
0x4a0b07     6830cebc00                       push   0xbcce30
0x4a0b0c     e809183f00                       call   0x89231a
0x4a0b11     83c404                           add    esp,0x4
0x4a0b14     c7442410ffffffff                 mov    DWORD PTR [esp+0x10],0xffffffff
0x4a0b1c     8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a0b1f     50                               push   eax
0x4a0b20     6830b1fa00                       push   0xfab130
0x4a0b25     e8e6e90300                       call   0x4df510
0x4a0b2a     8b4c2408                         mov    ecx,DWORD PTR [esp+0x8]
0x4a0b2e     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4a0b35     59                               pop    ecx
0x4a0b36     8be5                             mov    esp,ebp
0x4a0b38     5d                               pop    ebp
0x4a0b39     c20400                           ret    0x4

; world_map_load 0x4df510..0x4dfa9d raw=0xde910 SHA256=1566cf3bbd17d702cd6fcd1ce3b31eccf20c5d771a02f6d2d3997e8ae3cb1513
0x4df510     55                               push   ebp
0x4df511     8bec                             mov    ebp,esp
0x4df513     6aff                             push   0xffffffff
0x4df515     68a4449400                       push   0x9444a4
0x4df51a     64a100000000                     mov    eax,fs:0x0
0x4df520     50                               push   eax
0x4df521     83ec14                           sub    esp,0x14
0x4df524     53                               push   ebx
0x4df525     56                               push   esi
0x4df526     57                               push   edi
0x4df527     a1201fd600                       mov    eax,ds:0xd61f20
0x4df52c     33c5                             xor    eax,ebp
0x4df52e     50                               push   eax
0x4df52f     8d45f4                           lea    eax,[ebp-0xc]
0x4df532     64a300000000                     mov    fs:0x0,eax
0x4df538     8b750c                           mov    esi,DWORD PTR [ebp+0xc]
0x4df53b     8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4df53e     397048                           cmp    DWORD PTR [eax+0x48],esi
0x4df541     0f84cc040000                     je     0x4dfa13
0x4df547     f605b075fb0001                   test   BYTE PTR ds:0xfb75b0,0x1
0x4df54e     897048                           mov    DWORD PTR [eax+0x48],esi
0x4df551     bf01000000                       mov    edi,0x1
0x4df556     7527                             jne    0x4df57f
0x4df558     093db075fb00                     or     DWORD PTR ds:0xfb75b0,edi
0x4df55e     c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x4df565     e816480100                       call   0x4f3d80
0x4df56a     68e0d1bc00                       push   0xbcd1e0
0x4df56f     e8a62d3b00                       call   0x89231a
0x4df574     83c404                           add    esp,0x4
0x4df577     83cbff                           or     ebx,0xffffffff
0x4df57a     895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x4df57d     eb03                             jmp    0x4df582
0x4df57f     83cbff                           or     ebx,0xffffffff
0x4df582     8d55f0                           lea    edx,[ebp-0x10]
0x4df585     b9c074fb00                       mov    ecx,0xfb74c0
0x4df58a     8975f0                           mov    DWORD PTR [ebp-0x10],esi
0x4df58d     e85e880100                       call   0x4f7df0
0x4df592     f605b075fb0001                   test   BYTE PTR ds:0xfb75b0,0x1
0x4df599     751e                             jne    0x4df5b9
0x4df59b     093db075fb00                     or     DWORD PTR ds:0xfb75b0,edi
0x4df5a1     897dfc                           mov    DWORD PTR [ebp-0x4],edi
0x4df5a4     e8d7470100                       call   0x4f3d80
0x4df5a9     68e0d1bc00                       push   0xbcd1e0
0x4df5ae     e8672d3b00                       call   0x89231a
0x4df5b3     83c404                           add    esp,0x4
0x4df5b6     895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x4df5b9     8d45f0                           lea    eax,[ebp-0x10]
0x4df5bc     50                               push   eax
0x4df5bd     8d45ec                           lea    eax,[ebp-0x14]
0x4df5c0     b9e074fb00                       mov    ecx,0xfb74e0
0x4df5c5     8975f0                           mov    DWORD PTR [ebp-0x10],esi
0x4df5c8     e82308faff                       call   0x47fdf0
0x4df5cd     8b45ec                           mov    eax,DWORD PTR [ebp-0x14]
0x4df5d0     3b05e474fb00                     cmp    eax,DWORD PTR ds:0xfb74e4
0x4df5d6     741c                             je     0x4df5f4
0x4df5d8     83c010                           add    eax,0x10
0x4df5db     83781410                         cmp    DWORD PTR [eax+0x14],0x10
0x4df5df     7202                             jb     0x4df5e3
0x4df5e1     8b00                             mov    eax,DWORD PTR [eax]
0x4df5e3     8bc8                             mov    ecx,eax
0x4df5e5     bf7074fb00                       mov    edi,0xfb7470
0x4df5ea     e891780100                       call   0x4f6e80
0x4df5ef     bf01000000                       mov    edi,0x1
0x4df5f4     f605b075fb0001                   test   BYTE PTR ds:0xfb75b0,0x1
0x4df5fb     7522                             jne    0x4df61f
0x4df5fd     093db075fb00                     or     DWORD PTR ds:0xfb75b0,edi
0x4df603     c745fc02000000                   mov    DWORD PTR [ebp-0x4],0x2
0x4df60a     e871470100                       call   0x4f3d80
0x4df60f     68e0d1bc00                       push   0xbcd1e0
0x4df614     e8012d3b00                       call   0x89231a
0x4df619     83c404                           add    esp,0x4
0x4df61c     895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x4df61f     8d55ec                           lea    edx,[ebp-0x14]
0x4df622     b9b074fb00                       mov    ecx,0xfb74b0
0x4df627     8975ec                           mov    DWORD PTR [ebp-0x14],esi
0x4df62a     e8c1870100                       call   0x4f7df0
0x4df62f     83781410                         cmp    DWORD PTR [eax+0x14],0x10
0x4df633     7204                             jb     0x4df639
0x4df635     8b30                             mov    esi,DWORD PTR [eax]
0x4df637     eb02                             jmp    0x4df63b
0x4df639     8bf0                             mov    esi,eax
0x4df63b     f605b075fb0001                   test   BYTE PTR ds:0xfb75b0,0x1
0x4df642     7523                             jne    0x4df667
0x4df644     830db075fb0001                   or     DWORD PTR ds:0xfb75b0,0x1
0x4df64b     c745fc03000000                   mov    DWORD PTR [ebp-0x4],0x3
0x4df652     e829470100                       call   0x4f3d80
0x4df657     68e0d1bc00                       push   0xbcd1e0
0x4df65c     e8b92c3b00                       call   0x89231a
0x4df661     83c404                           add    esp,0x4
0x4df664     895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x4df667     8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
0x4df66a     8d4dec                           lea    ecx,[ebp-0x14]
0x4df66d     51                               push   ecx
0x4df66e     8d45f0                           lea    eax,[ebp-0x10]
0x4df671     b9f074fb00                       mov    ecx,0xfb74f0
0x4df676     897dec                           mov    DWORD PTR [ebp-0x14],edi
0x4df679     e87207faff                       call   0x47fdf0
0x4df67e     8b45f0                           mov    eax,DWORD PTR [ebp-0x10]
0x4df681     3b05f474fb00                     cmp    eax,DWORD PTR ds:0xfb74f4
0x4df687     741a                             je     0x4df6a3
0x4df689     83c010                           add    eax,0x10
0x4df68c     83781410                         cmp    DWORD PTR [eax+0x14],0x10
0x4df690     7202                             jb     0x4df694
0x4df692     8b00                             mov    eax,DWORD PTR [eax]
0x4df694     8bc8                             mov    ecx,eax
0x4df696     bf7074fb00                       mov    edi,0xfb7470
0x4df69b     e8e0770100                       call   0x4f6e80
0x4df6a0     8b7d0c                           mov    edi,DWORD PTR [ebp+0xc]
0x4df6a3     f605dcf6fd0001                   test   BYTE PTR ds:0xfdf6dc,0x1
0x4df6aa     7523                             jne    0x4df6cf
0x4df6ac     830ddcf6fd0001                   or     DWORD PTR ds:0xfdf6dc,0x1
0x4df6b3     c745fc04000000                   mov    DWORD PTR [ebp-0x4],0x4
0x4df6ba     e861110700                       call   0x550820
0x4df6bf     68b0e6bc00                       push   0xbce6b0
0x4df6c4     e8512c3b00                       call   0x89231a
0x4df6c9     83c404                           add    esp,0x4
0x4df6cc     895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x4df6cf     6880f6fd00                       push   0xfdf680
0x4df6d4     e8872c0700                       call   0x552360
0x4df6d9     f605c00ffc0001                   test   BYTE PTR ds:0xfc0fc0,0x1
0x4df6e0     7523                             jne    0x4df705
0x4df6e2     830dc00ffc0001                   or     DWORD PTR ds:0xfc0fc0,0x1
0x4df6e9     c745fc05000000                   mov    DWORD PTR [ebp-0x4],0x5
0x4df6f0     e85b971f00                       call   0x6d8e50
0x4df6f5     68b0dbbc00                       push   0xbcdbb0
0x4df6fa     e81b2c3b00                       call   0x89231a
0x4df6ff     83c404                           add    esp,0x4
0x4df702     895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x4df705     57                               push   edi
0x4df706     b9c80ffc00                       mov    ecx,0xfc0fc8
0x4df70b     e8209d1f00                       call   0x6d9430
0x4df710     f605c00ffc0001                   test   BYTE PTR ds:0xfc0fc0,0x1
0x4df717     7523                             jne    0x4df73c
0x4df719     830dc00ffc0001                   or     DWORD PTR ds:0xfc0fc0,0x1
0x4df720     c745fc06000000                   mov    DWORD PTR [ebp-0x4],0x6
0x4df727     e824971f00                       call   0x6d8e50
0x4df72c     68b0dbbc00                       push   0xbcdbb0
0x4df731     e8e42b3b00                       call   0x89231a
0x4df736     83c404                           add    esp,0x4
0x4df739     895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x4df73c     57                               push   edi
0x4df73d     68c80ffc00                       push   0xfc0fc8
0x4df742     e8399e1f00                       call   0x6d9580
0x4df747     8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x4df74a     83c74c                           add    edi,0x4c
0x4df74d     8bce                             mov    ecx,esi
0x4df74f     8bc7                             mov    eax,edi
0x4df751     8a10                             mov    dl,BYTE PTR [eax]
0x4df753     3a11                             cmp    dl,BYTE PTR [ecx]
0x4df755     751a                             jne    0x4df771
0x4df757     84d2                             test   dl,dl
0x4df759     7412                             je     0x4df76d
0x4df75b     8a5001                           mov    dl,BYTE PTR [eax+0x1]
0x4df75e     3a5101                           cmp    dl,BYTE PTR [ecx+0x1]
0x4df761     750e                             jne    0x4df771
0x4df763     83c002                           add    eax,0x2
0x4df766     83c102                           add    ecx,0x2
0x4df769     84d2                             test   dl,dl
0x4df76b     75e4                             jne    0x4df751
0x4df76d     33c0                             xor    eax,eax
0x4df76f     eb04                             jmp    0x4df775
0x4df771     1bc0                             sbb    eax,eax
0x4df773     1bc3                             sbb    eax,ebx
0x4df775     85c0                             test   eax,eax
0x4df777     7416                             je     0x4df78f
0x4df779     56                               push   esi
0x4df77a     6a40                             push   0x40
0x4df77c     57                               push   edi
0x4df77d     e8d7433b00                       call   0x893b59
0x4df782     83c40c                           add    esp,0xc
0x4df785     6a01                             push   0x1
0x4df787     e874262e00                       call   0x7c1e00
0x4df78c     83c404                           add    esp,0x4
0x4df78f     a138a8fb00                       mov    eax,ds:0xfba838
0x4df794     8b5048                           mov    edx,DWORD PTR [eax+0x48]
0x4df797     2b5044                           sub    edx,DWORD PTR [eax+0x44]
0x4df79a     c1fa02                           sar    edx,0x2
0x4df79d     85d2                             test   edx,edx
0x4df79f     0f84d5010000                     je     0x4df97a
0x4df7a5     8b4044                           mov    eax,DWORD PTR [eax+0x44]
0x4df7a8     8b30                             mov    esi,DWORD PTR [eax]
0x4df7aa     85f6                             test   esi,esi
0x4df7ac     0f84c8010000                     je     0x4df97a
0x4df7b2     f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
0x4df7b9     8b4e08                           mov    ecx,DWORD PTR [esi+0x8]
0x4df7bc     8b3e                             mov    edi,DWORD PTR [esi]
0x4df7be     8b5e04                           mov    ebx,DWORD PTR [esi+0x4]
0x4df7c1     894de8                           mov    DWORD PTR [ebp-0x18],ecx
0x4df7c4     7527                             jne    0x4df7ed
0x4df7c6     830de879fb0001                   or     DWORD PTR ds:0xfb79e8,0x1
0x4df7cd     c745fc07000000                   mov    DWORD PTR [ebp-0x4],0x7
0x4df7d4     e807962b00                       call   0x798de0
0x4df7d9     68e0d2bc00                       push   0xbcd2e0
0x4df7de     e8372b3b00                       call   0x89231a
0x4df7e3     83c404                           add    esp,0x4
0x4df7e6     c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x4df7ed     a1e876fb00                       mov    eax,ds:0xfb76e8
0x4df7f2     8b55e8                           mov    edx,DWORD PTR [ebp-0x18]
0x4df7f5     89780c                           mov    DWORD PTR [eax+0xc],edi
0x4df7f8     33ff                             xor    edi,edi
0x4df7fa     895810                           mov    DWORD PTR [eax+0x10],ebx
0x4df7fd     8bc8                             mov    ecx,eax
0x4df7ff     8d5f01                           lea    ebx,[edi+0x1]
0x4df802     895014                           mov    DWORD PTR [eax+0x14],edx
0x4df805     89b9cc000000                     mov    DWORD PTR [ecx+0xcc],edi
0x4df80b     f30f104614                       movss  xmm0,DWORD PTR [esi+0x14]
0x4df810     f30f1145ec                       movss  DWORD PTR [ebp-0x14],xmm0
0x4df815     841de879fb00                     test   BYTE PTR ds:0xfb79e8,bl
0x4df81b     7526                             jne    0x4df843
0x4df81d     091de879fb00                     or     DWORD PTR ds:0xfb79e8,ebx
0x4df823     c745fc08000000                   mov    DWORD PTR [ebp-0x4],0x8
0x4df82a     e8b1952b00                       call   0x798de0
0x4df82f     68e0d2bc00                       push   0xbcd2e0
0x4df834     e8e12a3b00                       call   0x89231a
0x4df839     83c404                           add    esp,0x4
0x4df83c     c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x4df843     f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
0x4df84a     a1e876fb00                       mov    eax,ds:0xfb76e8
0x4df84f     f30f1045ec                       movss  xmm0,DWORD PTR [ebp-0x14]
0x4df854     f30f114020                       movss  DWORD PTR [eax+0x20],xmm0
0x4df859     89b8cc000000                     mov    DWORD PTR [eax+0xcc],edi
0x4df85f     f30f104624                       movss  xmm0,DWORD PTR [esi+0x24]
0x4df864     f30f1145ec                       movss  DWORD PTR [ebp-0x14],xmm0
0x4df869     752b                             jne    0x4df896
0x4df86b     091de879fb00                     or     DWORD PTR ds:0xfb79e8,ebx
0x4df871     c745fc09000000                   mov    DWORD PTR [ebp-0x4],0x9
0x4df878     e863952b00                       call   0x798de0
0x4df87d     68e0d2bc00                       push   0xbcd2e0
0x4df882     e8932a3b00                       call   0x89231a
0x4df887     c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x4df88e     f30f1045ec                       movss  xmm0,DWORD PTR [ebp-0x14]
0x4df893     83c404                           add    esp,0x4
0x4df896     a1e876fb00                       mov    eax,ds:0xfb76e8
0x4df89b     8bc8                             mov    ecx,eax
0x4df89d     8b00                             mov    eax,DWORD PTR [eax]
0x4df89f     3bc7                             cmp    eax,edi
0x4df8a1     7405                             je     0x4df8a8
0x4df8a3     f30f11407c                       movss  DWORD PTR [eax+0x7c],xmm0
0x4df8a8     f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
0x4df8af     f30f114130                       movss  DWORD PTR [ecx+0x30],xmm0
0x4df8b4     f30f104628                       movss  xmm0,DWORD PTR [esi+0x28]
0x4df8b9     f30f1145f0                       movss  DWORD PTR [ebp-0x10],xmm0
0x4df8be     7526                             jne    0x4df8e6
0x4df8c0     091de879fb00                     or     DWORD PTR ds:0xfb79e8,ebx
0x4df8c6     c745fc0a000000                   mov    DWORD PTR [ebp-0x4],0xa
0x4df8cd     e80e952b00                       call   0x798de0
0x4df8d2     68e0d2bc00                       push   0xbcd2e0
0x4df8d7     e83e2a3b00                       call   0x89231a
0x4df8dc     83c404                           add    esp,0x4
0x4df8df     c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x4df8e6     a1e876fb00                       mov    eax,ds:0xfb76e8
0x4df8eb     8b08                             mov    ecx,DWORD PTR [eax]
0x4df8ed     f30f1045f0                       movss  xmm0,DWORD PTR [ebp-0x10]
0x4df8f2     f30f114034                       movss  DWORD PTR [eax+0x34],xmm0
0x4df8f7     89b8cc000000                     mov    DWORD PTR [eax+0xcc],edi
0x4df8fd     3bcf                             cmp    ecx,edi
0x4df8ff     741e                             je     0x4df91f
0x4df901     d945f0                           fld    DWORD PTR [ebp-0x10]
0x4df904     dc35f056c500                     fdiv   QWORD PTR ds:0xc556f0
0x4df90a     d95dec                           fstp   DWORD PTR [ebp-0x14]
0x4df90d     d980bc000000                     fld    DWORD PTR [eax+0xbc]
0x4df913     d84dec                           fmul   DWORD PTR [ebp-0x14]
0x4df916     d95dec                           fstp   DWORD PTR [ebp-0x14]
0x4df919     d945ec                           fld    DWORD PTR [ebp-0x14]
0x4df91c     d95974                           fstp   DWORD PTR [ecx+0x74]
0x4df91f     393dd41bfe00                     cmp    DWORD PTR ds:0xfe1bd4,edi
0x4df925     7550                             jne    0x4df977
0x4df927     f30f10460c                       movss  xmm0,DWORD PTR [esi+0xc]
0x4df92c     f30f1145ec                       movss  DWORD PTR [ebp-0x14],xmm0
0x4df931     e80a4ef5ff                       call   0x434740
0x4df936     8b4040                           mov    eax,DWORD PTR [eax+0x40]
0x4df939     f30f1045ec                       movss  xmm0,DWORD PTR [ebp-0x14]
0x4df93e     33ff                             xor    edi,edi
0x4df940     f30f114018                       movss  DWORD PTR [eax+0x18],xmm0
0x4df945     89b8cc000000                     mov    DWORD PTR [eax+0xcc],edi
0x4df94b     f30f104618                       movss  xmm0,DWORD PTR [esi+0x18]
0x4df950     f30f1145ec                       movss  DWORD PTR [ebp-0x14],xmm0
0x4df955     e8e64df5ff                       call   0x434740
0x4df95a     8b4040                           mov    eax,DWORD PTR [eax+0x40]
0x4df95d     f30f1045ec                       movss  xmm0,DWORD PTR [ebp-0x14]
0x4df962     f30f114024                       movss  DWORD PTR [eax+0x24],xmm0
0x4df967     89b8cc000000                     mov    DWORD PTR [eax+0xcc],edi
0x4df96d     c705d41bfe0001000000             mov    DWORD PTR ds:0xfe1bd4,0x1
0x4df977     83cbff                           or     ebx,0xffffffff
0x4df97a     f605b075fb0001                   test   BYTE PTR ds:0xfb75b0,0x1
0x4df981     7523                             jne    0x4df9a6
0x4df983     830db075fb0001                   or     DWORD PTR ds:0xfb75b0,0x1
0x4df98a     c745fc0b000000                   mov    DWORD PTR [ebp-0x4],0xb
0x4df991     e8ea430100                       call   0x4f3d80
0x4df996     68e0d1bc00                       push   0xbcd1e0
0x4df99b     e87a293b00                       call   0x89231a
0x4df9a0     83c404                           add    esp,0x4
0x4df9a3     895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x4df9a6     8b750c                           mov    esi,DWORD PTR [ebp+0xc]
0x4df9a9     8d550c                           lea    edx,[ebp+0xc]
0x4df9ac     b9d074fb00                       mov    ecx,0xfb74d0
0x4df9b1     89750c                           mov    DWORD PTR [ebp+0xc],esi
0x4df9b4     e837840100                       call   0x4f7df0
0x4df9b9     83781410                         cmp    DWORD PTR [eax+0x14],0x10
0x4df9bd     7202                             jb     0x4df9c1
0x4df9bf     8b00                             mov    eax,DWORD PTR [eax]
0x4df9c1     8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x4df9c4     51                               push   ecx
0x4df9c5     8bc8                             mov    ecx,eax
0x4df9c7     e8d4f7ffff                       call   0x4df1a0
0x4df9cc     f605c0f3fd0001                   test   BYTE PTR ds:0xfdf3c0,0x1
0x4df9d3     751e                             jne    0x4df9f3
0x4df9d5     830dc0f3fd0001                   or     DWORD PTR ds:0xfdf3c0,0x1
0x4df9dc     6850dfbc00                       push   0xbcdf50
0x4df9e1     c705c4f3fd0000000000             mov    DWORD PTR ds:0xfdf3c4,0x0
0x4df9eb     e82a293b00                       call   0x89231a
0x4df9f0     83c404                           add    esp,0x4
0x4df9f3     8bce                             mov    ecx,esi
0x4df9f5     bfc4f3fd00                       mov    edi,0xfdf3c4
0x4df9fa     e811d30800                       call   0x56cd10
0x4df9ff     8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4dfa02     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4dfa09     59                               pop    ecx
0x4dfa0a     5f                               pop    edi
0x4dfa0b     5e                               pop    esi
0x4dfa0c     5b                               pop    ebx
0x4dfa0d     8be5                             mov    esp,ebp
0x4dfa0f     5d                               pop    ebp
0x4dfa10     c20800                           ret    0x8
0x4dfa13     f605c00ffc0001                   test   BYTE PTR ds:0xfc0fc0,0x1
0x4dfa1a     7527                             jne    0x4dfa43
0x4dfa1c     830dc00ffc0001                   or     DWORD PTR ds:0xfc0fc0,0x1
0x4dfa23     c745fc0c000000                   mov    DWORD PTR [ebp-0x4],0xc
0x4dfa2a     e821941f00                       call   0x6d8e50
0x4dfa2f     68b0dbbc00                       push   0xbcdbb0
0x4dfa34     e8e1283b00                       call   0x89231a
0x4dfa39     83c404                           add    esp,0x4
0x4dfa3c     c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x4dfa43     56                               push   esi
0x4dfa44     b9c80ffc00                       mov    ecx,0xfc0fc8
0x4dfa49     e8e2991f00                       call   0x6d9430
0x4dfa4e     f605c00ffc0001                   test   BYTE PTR ds:0xfc0fc0,0x1
0x4dfa55     7527                             jne    0x4dfa7e
0x4dfa57     830dc00ffc0001                   or     DWORD PTR ds:0xfc0fc0,0x1
0x4dfa5e     c745fc0d000000                   mov    DWORD PTR [ebp-0x4],0xd
0x4dfa65     e8e6931f00                       call   0x6d8e50
0x4dfa6a     68b0dbbc00                       push   0xbcdbb0
0x4dfa6f     e8a6283b00                       call   0x89231a
0x4dfa74     83c404                           add    esp,0x4
0x4dfa77     c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x4dfa7e     56                               push   esi
0x4dfa7f     68c80ffc00                       push   0xfc0fc8
0x4dfa84     e8f79a1f00                       call   0x6d9580
0x4dfa89     8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4dfa8c     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4dfa93     59                               pop    ecx
0x4dfa94     5f                               pop    edi
0x4dfa95     5e                               pop    esi
0x4dfa96     5b                               pop    ebx
0x4dfa97     8be5                             mov    esp,ebp
0x4dfa99     5d                               pop    ebp
0x4dfa9a     c20800                           ret    0x8

; s2c0012_map 0x4b24f0..0x4b2566 raw=0xb18f0 SHA256=e46c4fa6a9cd974b8aac6b803f4c73f3171bd803e70ca9cb69985eee8b7ac425
0x4b24f0     55                               push   ebp
0x4b24f1     8bec                             mov    ebp,esp
0x4b24f3     b901000000                       mov    ecx,0x1
0x4b24f8     840dec79fb00                     test   BYTE PTR ds:0xfb79ec,cl
0x4b24fe     7534                             jne    0x4b2534
0x4b2500     090dec79fb00                     or     DWORD PTR ds:0xfb79ec,ecx
0x4b2506     33c0                             xor    eax,eax
0x4b2508     6870d2bc00                       push   0xbcd270
0x4b250d     c705f079fb0068f8c000             mov    DWORD PTR ds:0xfb79f0,0xc0f868
0x4b2517     a3f479fb00                       mov    ds:0xfb79f4,eax
0x4b251c     a3f879fb00                       mov    ds:0xfb79f8,eax
0x4b2521     a3fc79fb00                       mov    ds:0xfb79fc,eax
0x4b2526     890d047afb00                     mov    DWORD PTR ds:0xfb7a04,ecx
0x4b252c     e8e9fd3d00                       call   0x89231a
0x4b2531     83c404                           add    esp,0x4
0x4b2534     57                               push   edi
0x4b2535     68f079fb00                       push   0xfb79f0
0x4b253a     e861240900                       call   0x5449a0
0x4b253f     8b3da4a7fb00                     mov    edi,DWORD PTR ds:0xfba7a4
0x4b2545     e8062a0900                       call   0x544f50
0x4b254a     8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4b254d     8b4802                           mov    ecx,DWORD PTR [eax+0x2]
0x4b2550     51                               push   ecx
0x4b2551     e80acbf5ff                       call   0x40f060
0x4b2556     50                               push   eax
0x4b2557     e8b4cf0200                       call   0x4df510
0x4b255c     b800010000                       mov    eax,0x100
0x4b2561     5f                               pop    edi
0x4b2562     5d                               pop    ebp
0x4b2563     c20c00                           ret    0xc

; world_erase 0x4dfbc0..0x4dfc2c raw=0xdefc0 SHA256=21ae8dd896a0efbf2fc1719b9b2af83daf1fc550fdb8d3c10097a2a4c642baf8
0x4dfbc0     55                               push   ebp
0x4dfbc1     8bec                             mov    ebp,esp
0x4dfbc3     51                               push   ecx
0x4dfbc4     53                               push   ebx
0x4dfbc5     56                               push   esi
0x4dfbc6     8bf0                             mov    esi,eax
0x4dfbc8     57                               push   edi
0x4dfbc9     8d4508                           lea    eax,[ebp+0x8]
0x4dfbcc     8d5e08                           lea    ebx,[esi+0x8]
0x4dfbcf     50                               push   eax
0x4dfbd0     8d45fc                           lea    eax,[ebp-0x4]
0x4dfbd3     8bcb                             mov    ecx,ebx
0x4dfbd5     e826f33400                       call   0x82ef00
0x4dfbda     8b7dfc                           mov    edi,DWORD PTR [ebp-0x4]
0x4dfbdd     3b7e0c                           cmp    edi,DWORD PTR [esi+0xc]
0x4dfbe0     7441                             je     0x4dfc23
0x4dfbe2     33f6                             xor    esi,esi
0x4dfbe4     8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4dfbea     8b11                             mov    edx,DWORD PTR [ecx]
0x4dfbec     8b421c                           mov    eax,DWORD PTR [edx+0x1c]
0x4dfbef     56                               push   esi
0x4dfbf0     ffd0                             call   eax
0x4dfbf2     46                               inc    esi
0x4dfbf3     83fe03                           cmp    esi,0x3
0x4dfbf6     7cec                             jl     0x4dfbe4
0x4dfbf8     8b4f10                           mov    ecx,DWORD PTR [edi+0x10]
0x4dfbfb     8b11                             mov    edx,DWORD PTR [ecx]
0x4dfbfd     8b4214                           mov    eax,DWORD PTR [edx+0x14]
0x4dfc00     ffd0                             call   eax
0x4dfc02     8b4f10                           mov    ecx,DWORD PTR [edi+0x10]
0x4dfc05     85c9                             test   ecx,ecx
0x4dfc07     740f                             je     0x4dfc18
0x4dfc09     8b11                             mov    edx,DWORD PTR [ecx]
0x4dfc0b     8b02                             mov    eax,DWORD PTR [edx]
0x4dfc0d     6a01                             push   0x1
0x4dfc0f     ffd0                             call   eax
0x4dfc11     c7471000000000                   mov    DWORD PTR [edi+0x10],0x0
0x4dfc18     57                               push   edi
0x4dfc19     8d4d08                           lea    ecx,[ebp+0x8]
0x4dfc1c     51                               push   ecx
0x4dfc1d     53                               push   ebx
0x4dfc1e     e86d6c2d00                       call   0x7b6890
0x4dfc23     5f                               pop    edi
0x4dfc24     5e                               pop    esi
0x4dfc25     5b                               pop    ebx
0x4dfc26     8be5                             mov    esp,ebp
0x4dfc28     5d                               pop    ebp
0x4dfc29     c20400                           ret    0x4

; world_clear 0x4dfe90..0x4dff23 raw=0xdf290 SHA256=5a5931599c04e6a52f0602868f4fbe48ff1d349acfd7124873a3870c3af92663
0x4dfe90     55                               push   ebp
0x4dfe91     8bec                             mov    ebp,esp
0x4dfe93     53                               push   ebx
0x4dfe94     8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x4dfe97     8b430c                           mov    eax,DWORD PTR [ebx+0xc]
0x4dfe9a     56                               push   esi
0x4dfe9b     8b30                             mov    esi,DWORD PTR [eax]
0x4dfe9d     57                               push   edi
0x4dfe9e     3bf0                             cmp    esi,eax
0x4dfea0     7465                             je     0x4dff07
0x4dfea2     8b7e10                           mov    edi,DWORD PTR [esi+0x10]
0x4dfea5     85ff                             test   edi,edi
0x4dfea7     7413                             je     0x4dfebc
0x4dfea9     8b07                             mov    eax,DWORD PTR [edi]
0x4dfeab     8b5014                           mov    edx,DWORD PTR [eax+0x14]
0x4dfeae     8bcf                             mov    ecx,edi
0x4dfeb0     ffd2                             call   edx
0x4dfeb2     8b07                             mov    eax,DWORD PTR [edi]
0x4dfeb4     8b10                             mov    edx,DWORD PTR [eax]
0x4dfeb6     6a01                             push   0x1
0x4dfeb8     8bcf                             mov    ecx,edi
0x4dfeba     ffd2                             call   edx
0x4dfebc     807e1500                         cmp    BYTE PTR [esi+0x15],0x0
0x4dfec0     7540                             jne    0x4dff02
0x4dfec2     8b4608                           mov    eax,DWORD PTR [esi+0x8]
0x4dfec5     80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x4dfec9     7516                             jne    0x4dfee1
0x4dfecb     8bf0                             mov    esi,eax
0x4dfecd     8b06                             mov    eax,DWORD PTR [esi]
0x4dfecf     80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x4dfed3     752d                             jne    0x4dff02
0x4dfed5     8bf0                             mov    esi,eax
0x4dfed7     8b06                             mov    eax,DWORD PTR [esi]
0x4dfed9     80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x4dfedd     74f6                             je     0x4dfed5
0x4dfedf     eb21                             jmp    0x4dff02
0x4dfee1     8b4604                           mov    eax,DWORD PTR [esi+0x4]
0x4dfee4     80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x4dfee8     7516                             jne    0x4dff00
0x4dfeea     8d9b00000000                     lea    ebx,[ebx+0x0]
0x4dfef0     3b7008                           cmp    esi,DWORD PTR [eax+0x8]
0x4dfef3     750b                             jne    0x4dff00
0x4dfef5     8bf0                             mov    esi,eax
0x4dfef7     8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x4dfefa     80781500                         cmp    BYTE PTR [eax+0x15],0x0
0x4dfefe     74f0                             je     0x4dfef0
0x4dff00     8bf0                             mov    esi,eax
0x4dff02     3b730c                           cmp    esi,DWORD PTR [ebx+0xc]
0x4dff05     759b                             jne    0x4dfea2
0x4dff07     8d7b08                           lea    edi,[ebx+0x8]
0x4dff0a     e841393400                       call   0x823850
0x4dff0f     8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4dff15     8b01                             mov    eax,DWORD PTR [ecx]
0x4dff17     8b5014                           mov    edx,DWORD PTR [eax+0x14]
0x4dff1a     ffd2                             call   edx
0x4dff1c     5f                               pop    edi
0x4dff1d     5e                               pop    esi
0x4dff1e     5b                               pop    ebx
0x4dff1f     5d                               pop    ebp
0x4dff20     c20400                           ret    0x4

; delete001a 0x4b28d0..0x4b2af0 raw=0xb1cd0 SHA256=77862701c7d9722afe96ff9681e24fa67fef370c922e6813f19e4a441fe13ff4
0x4b28d0     55                               push   ebp
0x4b28d1     8bec                             mov    ebp,esp
0x4b28d3     83e4f8                           and    esp,0xfffffff8
0x4b28d6     6aff                             push   0xffffffff
0x4b28d8     681c6d9300                       push   0x936d1c
0x4b28dd     64a100000000                     mov    eax,fs:0x0
0x4b28e3     50                               push   eax
0x4b28e4     83ec28                           sub    esp,0x28
0x4b28e7     53                               push   ebx
0x4b28e8     56                               push   esi
0x4b28e9     57                               push   edi
0x4b28ea     a1201fd600                       mov    eax,ds:0xd61f20
0x4b28ef     33c4                             xor    eax,esp
0x4b28f1     50                               push   eax
0x4b28f2     8d442438                         lea    eax,[esp+0x38]
0x4b28f6     64a300000000                     mov    fs:0x0,eax
0x4b28fc     8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x4b28ff     83f804                           cmp    eax,0x4
0x4b2902     7304                             jae    0x4b2908
0x4b2904     33c0                             xor    eax,eax
0x4b2906     eb05                             jmp    0x4b290d
0x4b2908     83c0fc                           add    eax,0xfffffffc
0x4b290b     d1e8                             shr    eax,1
0x4b290d     85c0                             test   eax,eax
0x4b290f     0f84c1010000                     je     0x4b2ad6
0x4b2915     8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x4b2918     83c104                           add    ecx,0x4
0x4b291b     894c2414                         mov    DWORD PTR [esp+0x14],ecx
0x4b291f     89442418                         mov    DWORD PTR [esp+0x18],eax
0x4b2923     bb01000000                       mov    ebx,0x1
0x4b2928     841d2cb2fa00                     test   BYTE PTR ds:0xfab22c,bl
0x4b292e     7528                             jne    0x4b2958
0x4b2930     091d2cb2fa00                     or     DWORD PTR ds:0xfab22c,ebx
0x4b2936     c744244000000000                 mov    DWORD PTR [esp+0x40],0x0
0x4b293e     e84dc30200                       call   0x4dec90
0x4b2943     6830cebc00                       push   0xbcce30
0x4b2948     e8cdf93d00                       call   0x89231a
0x4b294d     83c404                           add    esp,0x4
0x4b2950     c7442440ffffffff                 mov    DWORD PTR [esp+0x40],0xffffffff
0x4b2958     8b542414                         mov    edx,DWORD PTR [esp+0x14]
0x4b295c     0fb702                           movzx  eax,WORD PTR [edx]
0x4b295f     8d4c241c                         lea    ecx,[esp+0x1c]
0x4b2963     8944241c                         mov    DWORD PTR [esp+0x1c],eax
0x4b2967     51                               push   ecx
0x4b2968     8d442424                         lea    eax,[esp+0x24]
0x4b296c     b938b1fa00                       mov    ecx,0xfab138
0x4b2971     e88ac53700                       call   0x82ef00
0x4b2976     8b442420                         mov    eax,DWORD PTR [esp+0x20]
0x4b297a     3b053cb1fa00                     cmp    eax,DWORD PTR ds:0xfab13c
0x4b2980     7407                             je     0x4b2989
0x4b2982     8b7010                           mov    esi,DWORD PTR [eax+0x10]
0x4b2985     85f6                             test   esi,esi
0x4b2987     7512                             jne    0x4b299b
0x4b2989     68e06cc000                       push   0xc06ce0
0x4b298e     e8cdb12300                       call   0x6edb60
0x4b2993     83c404                           add    esp,0x4
0x4b2996     e92c010000                       jmp    0x4b2ac7
0x4b299b     0fb74604                         movzx  eax,WORD PTR [esi+0x4]
0x4b299f     3ac3                             cmp    al,bl
0x4b29a1     740c                             je     0x4b29af
0x4b29a3     3c06                             cmp    al,0x6
0x4b29a5     7408                             je     0x4b29af
0x4b29a7     84c0                             test   al,al
0x4b29a9     7404                             je     0x4b29af
0x4b29ab     3c07                             cmp    al,0x7
0x4b29ad     7566                             jne    0x4b2a15
0x4b29af     f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
0x4b29b7     8b865c010000                     mov    eax,DWORD PTR [esi+0x15c]
0x4b29bd     f30f11442424                     movss  DWORD PTR [esp+0x24],xmm0
0x4b29c3     f30f11442428                     movss  DWORD PTR [esp+0x28],xmm0
0x4b29c9     f30f1144242c                     movss  DWORD PTR [esp+0x2c],xmm0
0x4b29cf     f30f11442430                     movss  DWORD PTR [esp+0x30],xmm0
0x4b29d5     85c0                             test   eax,eax
0x4b29d7     743c                             je     0x4b2a15
0x4b29d9     83be7003000000                   cmp    DWORD PTR [esi+0x370],0x0
0x4b29e0     7433                             je     0x4b2a15
0x4b29e2     6a00                             push   0x0
0x4b29e4     50                               push   eax
0x4b29e5     e8d6522f00                       call   0x7a7cc0
0x4b29ea     8b542424                         mov    edx,DWORD PTR [esp+0x24]
0x4b29ee     8b865c010000                     mov    eax,DWORD PTR [esi+0x15c]
0x4b29f4     83ec10                           sub    esp,0x10
0x4b29f7     8bcc                             mov    ecx,esp
0x4b29f9     8911                             mov    DWORD PTR [ecx],edx
0x4b29fb     8b542438                         mov    edx,DWORD PTR [esp+0x38]
0x4b29ff     895104                           mov    DWORD PTR [ecx+0x4],edx
0x4b2a02     8b54243c                         mov    edx,DWORD PTR [esp+0x3c]
0x4b2a06     895108                           mov    DWORD PTR [ecx+0x8],edx
0x4b2a09     8b542440                         mov    edx,DWORD PTR [esp+0x40]
0x4b2a0d     89510c                           mov    DWORD PTR [ecx+0xc],edx
0x4b2a10     e8db512f00                       call   0x7a7bf0
0x4b2a15     0fb74604                         movzx  eax,WORD PTR [esi+0x4]
0x4b2a19     3c02                             cmp    al,0x2
0x4b2a1b     7408                             je     0x4b2a25
0x4b2a1d     3c08                             cmp    al,0x8
0x4b2a1f     7404                             je     0x4b2a25
0x4b2a21     3c09                             cmp    al,0x9
0x4b2a23     7531                             jne    0x4b2a56
0x4b2a25     83bef400000000                   cmp    DWORD PTR [esi+0xf4],0x0
0x4b2a2c     7428                             je     0x4b2a56
0x4b2a2e     83be2401000000                   cmp    DWORD PTR [esi+0x124],0x0
0x4b2a35     751f                             jne    0x4b2a56
0x4b2a37     d98634010000                     fld    DWORD PTR [esi+0x134]
0x4b2a3d     d8b630010000                     fdiv   DWORD PTR [esi+0x130]
0x4b2a43     dd05f057c500                     fld    QWORD PTR ds:0xc557f0
0x4b2a49     d9c9                             fxch   st(1)
0x4b2a4b     dff1                             fcomip st,st(1)
0x4b2a4d     ddd8                             fstp   st(0)
0x4b2a4f     7605                             jbe    0x4b2a56
0x4b2a51     e85a9e0100                       call   0x4cc8b0
0x4b2a56     8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4b2a5c     668b7604                         mov    si,WORD PTR [esi+0x4]
0x4b2a60     33c0                             xor    eax,eax
0x4b2a62     8d510c                           lea    edx,[ecx+0xc]
0x4b2a65     8b3a                             mov    edi,DWORD PTR [edx]
0x4b2a67     85ff                             test   edi,edi
0x4b2a69     7406                             je     0x4b2a71
0x4b2a6b     66397704                         cmp    WORD PTR [edi+0x4],si
0x4b2a6f     740c                             je     0x4b2a7d
0x4b2a71     03c3                             add    eax,ebx
0x4b2a73     83c20c                           add    edx,0xc
0x4b2a76     83f803                           cmp    eax,0x3
0x4b2a79     7cea                             jl     0x4b2a65
0x4b2a7b     eb0c                             jmp    0x4b2a89
0x4b2a7d     83f8ff                           cmp    eax,0xffffffff
0x4b2a80     7407                             je     0x4b2a89
0x4b2a82     8b01                             mov    eax,DWORD PTR [ecx]
0x4b2a84     8b5014                           mov    edx,DWORD PTR [eax+0x14]
0x4b2a87     ffd2                             call   edx
0x4b2a89     841d2cb2fa00                     test   BYTE PTR ds:0xfab22c,bl
0x4b2a8f     7524                             jne    0x4b2ab5
0x4b2a91     091d2cb2fa00                     or     DWORD PTR ds:0xfab22c,ebx
0x4b2a97     895c2440                         mov    DWORD PTR [esp+0x40],ebx
0x4b2a9b     e8f0c10200                       call   0x4dec90
0x4b2aa0     6830cebc00                       push   0xbcce30
0x4b2aa5     e870f83d00                       call   0x89231a
0x4b2aaa     83c404                           add    esp,0x4
0x4b2aad     c7442440ffffffff                 mov    DWORD PTR [esp+0x40],0xffffffff
0x4b2ab5     8b442414                         mov    eax,DWORD PTR [esp+0x14]
0x4b2ab9     0fb708                           movzx  ecx,WORD PTR [eax]
0x4b2abc     51                               push   ecx
0x4b2abd     b830b1fa00                       mov    eax,0xfab130
0x4b2ac2     e8f9d00200                       call   0x4dfbc0
0x4b2ac7     8344241402                       add    DWORD PTR [esp+0x14],0x2
0x4b2acc     295c2418                         sub    DWORD PTR [esp+0x18],ebx
0x4b2ad0     0f8552feffff                     jne    0x4b2928
0x4b2ad6     33c0                             xor    eax,eax
0x4b2ad8     8b4c2438                         mov    ecx,DWORD PTR [esp+0x38]
0x4b2adc     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4b2ae3     59                               pop    ecx
0x4b2ae4     5f                               pop    edi
0x4b2ae5     5e                               pop    esi
0x4b2ae6     5b                               pop    ebx
0x4b2ae7     8be5                             mov    esp,ebp
0x4b2ae9     5d                               pop    ebp
0x4b2aea     c20c00                           ret    0xc
0x4b2aed     cc                               int3
0x4b2aee     cc                               int3
0x4b2aef     cc                               int3

; controller_reset 0x544f50..0x54503a raw=0x144350 SHA256=dadd12921a65f34299f9506ece76e5b6675d37a07047a1566def018984b4daa1
0x544f50     55                               push   ebp
0x544f51     8bec                             mov    ebp,esp
0x544f53     83e4f8                           and    esp,0xfffffff8
0x544f56     6aff                             push   0xffffffff
0x544f58     68d8cf9000                       push   0x90cfd8
0x544f5d     64a100000000                     mov    eax,fs:0x0
0x544f63     50                               push   eax
0x544f64     83ec14                           sub    esp,0x14
0x544f67     53                               push   ebx
0x544f68     56                               push   esi
0x544f69     a1201fd600                       mov    eax,ds:0xd61f20
0x544f6e     33c4                             xor    eax,esp
0x544f70     50                               push   eax
0x544f71     8d442420                         lea    eax,[esp+0x20]
0x544f75     64a300000000                     mov    fs:0x0,eax
0x544f7b     33c0                             xor    eax,eax
0x544f7d     33db                             xor    ebx,ebx
0x544f7f     895f60                           mov    DWORD PTR [edi+0x60],ebx
0x544f82     89475c                           mov    DWORD PTR [edi+0x5c],eax
0x544f85     ff15a025bd00                     call   DWORD PTR ds:0xbd25a0
0x544f8b     894764                           mov    DWORD PTR [edi+0x64],eax
0x544f8e     895f40                           mov    DWORD PTR [edi+0x40],ebx
0x544f91     895f44                           mov    DWORD PTR [edi+0x44],ebx
0x544f94     c60548abfb0001                   mov    BYTE PTR ds:0xfbab48,0x1
0x544f9b     895c2410                         mov    DWORD PTR [esp+0x10],ebx
0x544f9f     8d7714                           lea    esi,[edi+0x14]
0x544fa2     8b17                             mov    edx,DWORD PTR [edi]
0x544fa4     8b442410                         mov    eax,DWORD PTR [esp+0x10]
0x544fa8     8b521c                           mov    edx,DWORD PTR [edx+0x1c]
0x544fab     50                               push   eax
0x544fac     8bcf                             mov    ecx,edi
0x544fae     ffd2                             call   edx
0x544fb0     3bc3                             cmp    eax,ebx
0x544fb2     7456                             je     0x54500a
0x544fb4     8d4c2414                         lea    ecx,[esp+0x14]
0x544fb8     e81374f5ff                       call   0x49c3d0
0x544fbd     895c2428                         mov    DWORD PTR [esp+0x28],ebx
0x544fc1     8b442414                         mov    eax,DWORD PTR [esp+0x14]
0x544fc5     3bc3                             cmp    eax,ebx
0x544fc7     7406                             je     0x544fcf
0x544fc9     50                               push   eax
0x544fca     e8c1282600                       call   0x7a7890
0x544fcf     c7442428ffffffff                 mov    DWORD PTR [esp+0x28],0xffffffff
0x544fd7     8b5c2418                         mov    ebx,DWORD PTR [esp+0x18]
0x544fdb     85db                             test   ebx,ebx
0x544fdd     7429                             je     0x545008
0x544fdf     8d4304                           lea    eax,[ebx+0x4]
0x544fe2     83c9ff                           or     ecx,0xffffffff
0x544fe5     f00fc108                         lock xadd DWORD PTR [eax],ecx
0x544fe9     751d                             jne    0x545008
0x544feb     8b13                             mov    edx,DWORD PTR [ebx]
0x544fed     8b02                             mov    eax,DWORD PTR [edx]
0x544fef     8bcb                             mov    ecx,ebx
0x544ff1     ffd0                             call   eax
0x544ff3     8d4b08                           lea    ecx,[ebx+0x8]
0x544ff6     83caff                           or     edx,0xffffffff
0x544ff9     f00fc111                         lock xadd DWORD PTR [ecx],edx
0x544ffd     7509                             jne    0x545008
0x544fff     8b03                             mov    eax,DWORD PTR [ebx]
0x545001     8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x545004     8bcb                             mov    ecx,ebx
0x545006     ffd2                             call   edx
0x545008     33db                             xor    ebx,ebx
0x54500a     8b442410                         mov    eax,DWORD PTR [esp+0x10]
0x54500e     40                               inc    eax
0x54500f     895ef8                           mov    DWORD PTR [esi-0x8],ebx
0x545012     895efc                           mov    DWORD PTR [esi-0x4],ebx
0x545015     c60601                           mov    BYTE PTR [esi],0x1
0x545018     83c60c                           add    esi,0xc
0x54501b     89442410                         mov    DWORD PTR [esp+0x10],eax
0x54501f     83f803                           cmp    eax,0x3
0x545022     0f8c7affffff                     jl     0x544fa2
0x545028     8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
0x54502c     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x545033     59                               pop    ecx
0x545034     5e                               pop    esi
0x545035     5b                               pop    ebx
0x545036     8be5                             mov    esp,ebp
0x545038     5d                               pop    ebp
0x545039     c3                               ret

; controller_clear 0x545210..0x54525b raw=0x144610 SHA256=e67566d1fbaaeed7c9f2a92d91d2887b09c9854fce3713f8341dfba04fc5f72d
0x545210     33c0                             xor    eax,eax
0x545212     89410c                           mov    DWORD PTR [ecx+0xc],eax
0x545215     894118                           mov    DWORD PTR [ecx+0x18],eax
0x545218     894110                           mov    DWORD PTR [ecx+0x10],eax
0x54521b     b201                             mov    dl,0x1
0x54521d     885114                           mov    BYTE PTR [ecx+0x14],dl
0x545220     89411c                           mov    DWORD PTR [ecx+0x1c],eax
0x545223     885120                           mov    BYTE PTR [ecx+0x20],dl
0x545226     894124                           mov    DWORD PTR [ecx+0x24],eax
0x545229     894128                           mov    DWORD PTR [ecx+0x28],eax
0x54522c     88512c                           mov    BYTE PTR [ecx+0x2c],dl
0x54522f     8b5130                           mov    edx,DWORD PTR [ecx+0x30]
0x545232     56                               push   esi
0x545233     8b7134                           mov    esi,DWORD PTR [ecx+0x34]
0x545236     3bd6                             cmp    edx,esi
0x545238     741f                             je     0x545259
0x54523a     8bc6                             mov    eax,esi
0x54523c     3bf6                             cmp    esi,esi
0x54523e     7416                             je     0x545256
0x545240     57                               push   edi
0x545241     8b38                             mov    edi,DWORD PTR [eax]
0x545243     893a                             mov    DWORD PTR [edx],edi
0x545245     8b7804                           mov    edi,DWORD PTR [eax+0x4]
0x545248     897a04                           mov    DWORD PTR [edx+0x4],edi
0x54524b     83c008                           add    eax,0x8
0x54524e     83c208                           add    edx,0x8
0x545251     3bc6                             cmp    eax,esi
0x545253     75ec                             jne    0x545241
0x545255     5f                               pop    edi
0x545256     895134                           mov    DWORD PTR [ecx+0x34],edx
0x545259     5e                               pop    esi
0x54525a     c3                               ret

; common_primary 0x4add50..0x4ae380 raw=0xad150 SHA256=f9cee5546de393ee1584d8c621e067d56f218559a800556f9b1bdcacc1a6d0f7
0x4add50     53                               push   ebx
0x4add51     56                               push   esi
0x4add52     8d5008                           lea    edx,[eax+0x8]
0x4add55     bed50b0000                       mov    esi,0xbd5
0x4add5a     b97523bf00                       mov    ecx,0xbf2375
0x4add5f     90                               nop
0x4add60     c742fc407d4b00                   mov    DWORD PTR [edx-0x4],0x4b7d40
0x4add67     890a                             mov    DWORD PTR [edx],ecx
0x4add69     83c208                           add    edx,0x8
0x4add6c     4e                               dec    esi
0x4add6d     75f1                             jne    0x4add60
0x4add6f     ba80fb4a00                       mov    edx,0x4afb80
0x4add74     c74034307d4b00                   mov    DWORD PTR [eax+0x34],0x4b7d30
0x4add7b     894838                           mov    DWORD PTR [eax+0x38],ecx
0x4add7e     c7403cd0e44a00                   mov    DWORD PTR [eax+0x3c],0x4ae4d0
0x4add85     894840                           mov    DWORD PTR [eax+0x40],ecx
0x4add88     c780f4090000b0ed4a00             mov    DWORD PTR [eax+0x9f4],0x4aedb0
0x4add92     8988f8090000                     mov    DWORD PTR [eax+0x9f8],ecx
0x4add98     c7404430f54a00                   mov    DWORD PTR [eax+0x44],0x4af530
0x4add9f     894848                           mov    DWORD PTR [eax+0x48],ecx
0x4adda2     c7405420f94a00                   mov    DWORD PTR [eax+0x54],0x4af920
0x4adda9     894858                           mov    DWORD PTR [eax+0x58],ecx
0x4addac     c74004f0fa4a00                   mov    DWORD PTR [eax+0x4],0x4afaf0
0x4addb3     894808                           mov    DWORD PTR [eax+0x8],ecx
0x4addb6     89500c                           mov    DWORD PTR [eax+0xc],edx
0x4addb9     894810                           mov    DWORD PTR [eax+0x10],ecx
0x4addbc     c7405c60fe4a00                   mov    DWORD PTR [eax+0x5c],0x4afe60
0x4addc3     894860                           mov    DWORD PTR [eax+0x60],ecx
0x4addc6     c7406430014b00                   mov    DWORD PTR [eax+0x64],0x4b0130
0x4addcd     894868                           mov    DWORD PTR [eax+0x68],ecx
0x4addd0     c7406cc0014b00                   mov    DWORD PTR [eax+0x6c],0x4b01c0
0x4addd7     894870                           mov    DWORD PTR [eax+0x70],ecx
0x4addda     c7807c050000d0034b00             mov    DWORD PTR [eax+0x57c],0x4b03d0
0x4adde4     898880050000                     mov    DWORD PTR [eax+0x580],ecx
0x4addea     c74074406c4300                   mov    DWORD PTR [eax+0x74],0x436c40
0x4addf1     894878                           mov    DWORD PTR [eax+0x78],ecx
0x4addf4     c780fc09000040194b00             mov    DWORD PTR [eax+0x9fc],0x4b1940
0x4addfe     8988000a0000                     mov    DWORD PTR [eax+0xa00],ecx
0x4ade04     c7407cd0194b00                   mov    DWORD PTR [eax+0x7c],0x4b19d0
0x4ade0b     898880000000                     mov    DWORD PTR [eax+0x80],ecx
0x4ade11     c78084000000301a4b00             mov    DWORD PTR [eax+0x84],0x4b1a30
0x4ade1b     898888000000                     mov    DWORD PTR [eax+0x88],ecx
0x4ade21     c7808c000000701a4b00             mov    DWORD PTR [eax+0x8c],0x4b1a70
0x4ade2b     898890000000                     mov    DWORD PTR [eax+0x90],ecx
0x4ade31     c7801c020000901a4b00             mov    DWORD PTR [eax+0x21c],0x4b1a90
0x4ade3b     898820020000                     mov    DWORD PTR [eax+0x220],ecx
0x4ade41     c78094000000f0244b00             mov    DWORD PTR [eax+0x94],0x4b24f0
0x4ade4b     898898000000                     mov    DWORD PTR [eax+0x98],ecx
0x4ade51     c780a400000030594c00             mov    DWORD PTR [eax+0xa4],0x4c5930
0x4ade5b     8988a8000000                     mov    DWORD PTR [eax+0xa8],ecx
0x4ade61     c780ac00000020264b00             mov    DWORD PTR [eax+0xac],0x4b2620
0x4ade6b     8988b0000000                     mov    DWORD PTR [eax+0xb0],ecx
0x4ade71     8990b4000000                     mov    DWORD PTR [eax+0xb4],edx
0x4ade77     8988b8000000                     mov    DWORD PTR [eax+0xb8],ecx
0x4ade7d     c780c400000030274b00             mov    DWORD PTR [eax+0xc4],0x4b2730
0x4ade87     8988c8000000                     mov    DWORD PTR [eax+0xc8],ecx
0x4ade8d     c780d4000000d0284b00             mov    DWORD PTR [eax+0xd4],0x4b28d0
0x4ade97     8988d8000000                     mov    DWORD PTR [eax+0xd8],ecx
0x4ade9d     c780dc00000080e34a00             mov    DWORD PTR [eax+0xdc],0x4ae380
0x4adea7     8988e0000000                     mov    DWORD PTR [eax+0xe0],ecx
0x4adead     c7803c010000f02a4b00             mov    DWORD PTR [eax+0x13c],0x4b2af0
0x4adeb7     898840010000                     mov    DWORD PTR [eax+0x140],ecx
0x4adebd     c78044020000e0324b00             mov    DWORD PTR [eax+0x244],0x4b32e0
0x4adec7     898848020000                     mov    DWORD PTR [eax+0x248],ecx
0x4adecd     c7800c010000d02c4b00             mov    DWORD PTR [eax+0x10c],0x4b2cd0
0x4aded7     898810010000                     mov    DWORD PTR [eax+0x110],ecx
0x4adedd     c7801401000040304b00             mov    DWORD PTR [eax+0x114],0x4b3040
0x4adee7     898818010000                     mov    DWORD PTR [eax+0x118],ecx
0x4adeed     c7803401000060304b00             mov    DWORD PTR [eax+0x134],0x4b3060
0x4adef7     898838010000                     mov    DWORD PTR [eax+0x138],ecx
0x4adefd     c780ec08000060304b00             mov    DWORD PTR [eax+0x8ec],0x4b3060
0x4adf07     8988f0080000                     mov    DWORD PTR [eax+0x8f0],ecx
0x4adf0d     c78044010000d01b4b00             mov    DWORD PTR [eax+0x144],0x4b1bd0
0x4adf17     898848010000                     mov    DWORD PTR [eax+0x148],ecx
0x4adf1d     c780a401000090304b00             mov    DWORD PTR [eax+0x1a4],0x4b3090
0x4adf27     8988a8010000                     mov    DWORD PTR [eax+0x1a8],ecx
0x4adf2d     c780c4010000f01b4b00             mov    DWORD PTR [eax+0x1c4],0x4b1bf0
0x4adf37     8988c8010000                     mov    DWORD PTR [eax+0x1c8],ecx
0x4adf3d     c7801402000090214b00             mov    DWORD PTR [eax+0x214],0x4b2190
0x4adf47     898818020000                     mov    DWORD PTR [eax+0x218],ecx
0x4adf4d     c7800c02000010234b00             mov    DWORD PTR [eax+0x20c],0x4b2310
0x4adf57     898810020000                     mov    DWORD PTR [eax+0x210],ecx
0x4adf5d     c780fc030000c0234b00             mov    DWORD PTR [eax+0x3fc],0x4b23c0
0x4adf67     898800040000                     mov    DWORD PTR [eax+0x400],ecx
0x4adf6d     c7804c02000050334b00             mov    DWORD PTR [eax+0x24c],0x4b3350
0x4adf77     898850020000                     mov    DWORD PTR [eax+0x250],ecx
0x4adf7d     c7805c020000f0344b00             mov    DWORD PTR [eax+0x25c],0x4b34f0
0x4adf87     898860020000                     mov    DWORD PTR [eax+0x260],ecx
0x4adf8d     c7806c02000010354b00             mov    DWORD PTR [eax+0x26c],0x4b3510
0x4adf97     898870020000                     mov    DWORD PTR [eax+0x270],ecx
0x4adf9d     c7807402000070354b00             mov    DWORD PTR [eax+0x274],0x4b3570
0x4adfa7     898878020000                     mov    DWORD PTR [eax+0x278],ecx
0x4adfad     c7808402000000364b00             mov    DWORD PTR [eax+0x284],0x4b3600
0x4adfb7     898888020000                     mov    DWORD PTR [eax+0x288],ecx
0x4adfbd     c7808c02000010374b00             mov    DWORD PTR [eax+0x28c],0x4b3710
0x4adfc7     898890020000                     mov    DWORD PTR [eax+0x290],ecx
0x4adfcd     c780a4040000f0f14a00             mov    DWORD PTR [eax+0x4a4],0x4af1f0
0x4adfd7     8988a8040000                     mov    DWORD PTR [eax+0x4a8],ecx
0x4adfdd     c780f4020000103c4b00             mov    DWORD PTR [eax+0x2f4],0x4b3c10
0x4adfe7     8988f8020000                     mov    DWORD PTR [eax+0x2f8],ecx
0x4adfed     c780e4020000a03d4b00             mov    DWORD PTR [eax+0x2e4],0x4b3da0
0x4adff7     8988e8020000                     mov    DWORD PTR [eax+0x2e8],ecx
0x4adffd     c7808401000060374b00             mov    DWORD PTR [eax+0x184],0x4b3760
0x4ae007     898888010000                     mov    DWORD PTR [eax+0x188],ecx
0x4ae00d     c7801c030000e03e4b00             mov    DWORD PTR [eax+0x31c],0x4b3ee0
0x4ae017     898820030000                     mov    DWORD PTR [eax+0x320],ecx
0x4ae01d     c7806403000050404b00             mov    DWORD PTR [eax+0x364],0x4b4050
0x4ae027     898868030000                     mov    DWORD PTR [eax+0x368],ecx
0x4ae02d     c7806c030000e0404b00             mov    DWORD PTR [eax+0x36c],0x4b40e0
0x4ae037     898870030000                     mov    DWORD PTR [eax+0x370],ecx
0x4ae03d     c780b403000080434b00             mov    DWORD PTR [eax+0x3b4],0x4b4380
0x4ae047     8988b8030000                     mov    DWORD PTR [eax+0x3b8],ecx
0x4ae04d     c7809c03000000444b00             mov    DWORD PTR [eax+0x39c],0x4b4400
0x4ae057     8988a0030000                     mov    DWORD PTR [eax+0x3a0],ecx
0x4ae05d     c780cc030000c0444b00             mov    DWORD PTR [eax+0x3cc],0x4b44c0
0x4ae067     8988d0030000                     mov    DWORD PTR [eax+0x3d0],ecx
0x4ae06d     c78014040000e0444b00             mov    DWORD PTR [eax+0x414],0x4b44e0
0x4ae077     898818040000                     mov    DWORD PTR [eax+0x418],ecx
0x4ae07d     c7808c040000b0454b00             mov    DWORD PTR [eax+0x48c],0x4b45b0
0x4ae087     898890040000                     mov    DWORD PTR [eax+0x490],ecx
0x4ae08d     c780d4050000d0494b00             mov    DWORD PTR [eax+0x5d4],0x4b49d0
0x4ae097     8988d8050000                     mov    DWORD PTR [eax+0x5d8],ecx
0x4ae09d     c780bc040000c04c4b00             mov    DWORD PTR [eax+0x4bc],0x4b4cc0
0x4ae0a7     8988c0040000                     mov    DWORD PTR [eax+0x4c0],ecx
0x4ae0ad     c780ac040000b01a4b00             mov    DWORD PTR [eax+0x4ac],0x4b1ab0
0x4ae0b7     8988b0040000                     mov    DWORD PTR [eax+0x4b0],ecx
0x4ae0bd     c780b4040000b01b4b00             mov    DWORD PTR [eax+0x4b4],0x4b1bb0
0x4ae0c7     8988b8040000                     mov    DWORD PTR [eax+0x4b8],ecx
0x4ae0cd     c78024050000804d4b00             mov    DWORD PTR [eax+0x524],0x4b4d80
0x4ae0d7     898828050000                     mov    DWORD PTR [eax+0x528],ecx
0x4ae0dd     c7802c050000f0534b00             mov    DWORD PTR [eax+0x52c],0x4b53f0
0x4ae0e7     898830050000                     mov    DWORD PTR [eax+0x530],ecx
0x4ae0ed     c7806c070000105c4b00             mov    DWORD PTR [eax+0x76c],0x4b5c10
0x4ae0f7     898870070000                     mov    DWORD PTR [eax+0x770],ecx
0x4ae0fd     c7808c080000c0444b00             mov    DWORD PTR [eax+0x88c],0x4b44c0
0x4ae107     898890080000                     mov    DWORD PTR [eax+0x890],ecx
0x4ae10d     c7808c05000000594b00             mov    DWORD PTR [eax+0x58c],0x4b5900
0x4ae117     898890050000                     mov    DWORD PTR [eax+0x590],ecx
0x4ae11d     c780b4050000d05d4b00             mov    DWORD PTR [eax+0x5b4],0x4b5dd0
0x4ae127     8988b8050000                     mov    DWORD PTR [eax+0x5b8],ecx
0x4ae12d     c780bc050000505e4b00             mov    DWORD PTR [eax+0x5bc],0x4b5e50
0x4ae137     8988c0050000                     mov    DWORD PTR [eax+0x5c0],ecx
0x4ae13d     c78054060000105f4b00             mov    DWORD PTR [eax+0x654],0x4b5f10
0x4ae147     898858060000                     mov    DWORD PTR [eax+0x658],ecx
0x4ae14d     c7805c060000305f4b00             mov    DWORD PTR [eax+0x65c],0x4b5f30
0x4ae157     898860060000                     mov    DWORD PTR [eax+0x660],ecx
0x4ae15d     c78044060000405f4b00             mov    DWORD PTR [eax+0x644],0x4b5f40
0x4ae167     898848060000                     mov    DWORD PTR [eax+0x648],ecx
0x4ae16d     c78064060000605f4b00             mov    DWORD PTR [eax+0x664],0x4b5f60
0x4ae177     898868060000                     mov    DWORD PTR [eax+0x668],ecx
0x4ae17d     c7804c060000805f4b00             mov    DWORD PTR [eax+0x64c],0x4b5f80
0x4ae187     898850060000                     mov    DWORD PTR [eax+0x650],ecx
0x4ae18d     c7803c060000a05f4b00             mov    DWORD PTR [eax+0x63c],0x4b5fa0
0x4ae197     898840060000                     mov    DWORD PTR [eax+0x640],ecx
0x4ae19d     c7806c060000d05f4b00             mov    DWORD PTR [eax+0x66c],0x4b5fd0
0x4ae1a7     898870060000                     mov    DWORD PTR [eax+0x670],ecx
0x4ae1ad     c78074060000f05f4b00             mov    DWORD PTR [eax+0x674],0x4b5ff0
0x4ae1b7     898878060000                     mov    DWORD PTR [eax+0x678],ecx
0x4ae1bd     c7807c06000010604b00             mov    DWORD PTR [eax+0x67c],0x4b6010
0x4ae1c7     898880060000                     mov    DWORD PTR [eax+0x680],ecx
0x4ae1cd     c7808406000030604b00             mov    DWORD PTR [eax+0x684],0x4b6030
0x4ae1d7     898888060000                     mov    DWORD PTR [eax+0x688],ecx
0x4ae1dd     c780c406000040604b00             mov    DWORD PTR [eax+0x6c4],0x4b6040
0x4ae1e7     8988c8060000                     mov    DWORD PTR [eax+0x6c8],ecx
0x4ae1ed     c780dc06000050604b00             mov    DWORD PTR [eax+0x6dc],0x4b6050
0x4ae1f7     8988e0060000                     mov    DWORD PTR [eax+0x6e0],ecx
0x4ae1fd     c7805c07000090614b00             mov    DWORD PTR [eax+0x75c],0x4b6190
0x4ae207     898860070000                     mov    DWORD PTR [eax+0x760],ecx
0x4ae20d     c7806407000000624b00             mov    DWORD PTR [eax+0x764],0x4b6200
0x4ae217     898868070000                     mov    DWORD PTR [eax+0x768],ecx
0x4ae21d     c7807407000090624b00             mov    DWORD PTR [eax+0x774],0x4b6290
0x4ae227     898878070000                     mov    DWORD PTR [eax+0x778],ecx
0x4ae22d     c780ac080000e0634b00             mov    DWORD PTR [eax+0x8ac],0x4b63e0
0x4ae237     8988b0080000                     mov    DWORD PTR [eax+0x8b0],ecx
0x4ae23d     c780b408000010664b00             mov    DWORD PTR [eax+0x8b4],0x4b6610
0x4ae247     8988b8080000                     mov    DWORD PTR [eax+0x8b8],ecx
0x4ae24d     c780bc08000080654b00             mov    DWORD PTR [eax+0x8bc],0x4b6580
0x4ae257     8988c0080000                     mov    DWORD PTR [eax+0x8c0],ecx
0x4ae25d     c780c4080000b0674b00             mov    DWORD PTR [eax+0x8c4],0x4b67b0
0x4ae267     8988c8080000                     mov    DWORD PTR [eax+0x8c8],ecx
0x4ae26d     c780ac03000040684b00             mov    DWORD PTR [eax+0x3ac],0x4b6840
0x4ae277     8988b0030000                     mov    DWORD PTR [eax+0x3b0],ecx
0x4ae27d     c780cc08000070524900             mov    DWORD PTR [eax+0x8cc],0x495270
0x4ae287     8988d0080000                     mov    DWORD PTR [eax+0x8d0],ecx
0x4ae28d     c78054090000001a4b00             mov    DWORD PTR [eax+0x954],0x4b1a00
0x4ae297     898858090000                     mov    DWORD PTR [eax+0x958],ecx
0x4ae29d     c780b4090000306a4b00             mov    DWORD PTR [eax+0x9b4],0x4b6a30
0x4ae2a7     8988b8090000                     mov    DWORD PTR [eax+0x9b8],ecx
0x4ae2ad     c7802c0a0000b06a4b00             mov    DWORD PTR [eax+0xa2c],0x4b6ab0
0x4ae2b7     8988300a0000                     mov    DWORD PTR [eax+0xa30],ecx
0x4ae2bd     c780e4040000906b4b00             mov    DWORD PTR [eax+0x4e4],0x4b6b90
0x4ae2c7     8988e8040000                     mov    DWORD PTR [eax+0x4e8],ecx
0x4ae2cd     c7804c0a0000006d4b00             mov    DWORD PTR [eax+0xa4c],0x4b6d00
0x4ae2d7     8988500a0000                     mov    DWORD PTR [eax+0xa50],ecx
0x4ae2dd     c780f404000000724b00             mov    DWORD PTR [eax+0x4f4],0x4b7200
0x4ae2e7     8988f8040000                     mov    DWORD PTR [eax+0x4f8],ecx
0x4ae2ed     c7808c0a0000e0724b00             mov    DWORD PTR [eax+0xa8c],0x4b72e0
0x4ae2f7     8988900a0000                     mov    DWORD PTR [eax+0xa90],ecx
0x4ae2fd     c780940a000040754b00             mov    DWORD PTR [eax+0xa94],0x4b7540
0x4ae307     8988980a0000                     mov    DWORD PTR [eax+0xa98],ecx
0x4ae30d     c780a40a000020764b00             mov    DWORD PTR [eax+0xaa4],0x4b7620
0x4ae317     8988a80a0000                     mov    DWORD PTR [eax+0xaa8],ecx
0x4ae31d     c780ac0a000090774b00             mov    DWORD PTR [eax+0xaac],0x4b7790
0x4ae327     8988b00a0000                     mov    DWORD PTR [eax+0xab0],ecx
0x4ae32d     c780b40a0000a0784b00             mov    DWORD PTR [eax+0xab4],0x4b78a0
0x4ae337     8988b80a0000                     mov    DWORD PTR [eax+0xab8],ecx
0x4ae33d     c7809c0a000050794b00             mov    DWORD PTR [eax+0xa9c],0x4b7950
0x4ae347     8988a00a0000                     mov    DWORD PTR [eax+0xaa0],ecx
0x4ae34d     c780c40a0000a07b4b00             mov    DWORD PTR [eax+0xac4],0x4b7ba0
0x4ae357     8988c80a0000                     mov    DWORD PTR [eax+0xac8],ecx
0x4ae35d     c7805c0a0000706f4b00             mov    DWORD PTR [eax+0xa5c],0x4b6f70
0x4ae367     8988600a0000                     mov    DWORD PTR [eax+0xa60],ecx
0x4ae36d     5e                               pop    esi
0x4ae36e     c7807c0a0000f06f4b00             mov    DWORD PTR [eax+0xa7c],0x4b6ff0
0x4ae378     8988800a0000                     mov    DWORD PTR [eax+0xa80],ecx
0x4ae37e     5b                               pop    ebx
0x4ae37f     c3                               ret

; frontend_callback 0x4930e0..0x493170 raw=0x924e0 SHA256=fa3ddb856a41b94391c879bdcbba36c988d543cfa1115304c8a327b37cdace8c
0x4930e0     55                               push   ebp
0x4930e1     8bec                             mov    ebp,esp
0x4930e3     51                               push   ecx
0x4930e4     8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x4930e7     53                               push   ebx
0x4930e8     8b5d10                           mov    ebx,DWORD PTR [ebp+0x10]
0x4930eb     56                               push   esi
0x4930ec     57                               push   edi
0x4930ed     0fb738                           movzx  edi,WORD PTR [eax]
0x4930f0     8bf1                             mov    esi,ecx
0x4930f2     c645ff00                         mov    BYTE PTR [ebp-0x1],0x0
0x4930f6     85db                             test   ebx,ebx
0x4930f8     750b                             jne    0x493105
0x4930fa     5f                               pop    edi
0x4930fb     5e                               pop    esi
0x4930fc     33c0                             xor    eax,eax
0x4930fe     5b                               pop    ebx
0x4930ff     8be5                             mov    esp,ebp
0x493101     5d                               pop    ebp
0x493102     c21000                           ret    0x10
0x493105     8b4514                           mov    eax,DWORD PTR [ebp+0x14]
0x493108     83e802                           sub    eax,0x2
0x49310b     7547                             jne    0x493154
0x49310d     53                               push   ebx
0x49310e     57                               push   edi
0x49310f     8d86e0be0000                     lea    eax,[esi+0xbee0]
0x493115     e8d6802400                       call   0x6db1f0
0x49311a     ff15a025bd00                     call   DWORD PTR ds:0xbd25a0
0x493120     8b96b8000000                     mov    edx,DWORD PTR [esi+0xb8]
0x493126     8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x493129     8b5204                           mov    edx,DWORD PTR [edx+0x4]
0x49312c     57                               push   edi
0x49312d     8d8eb8000000                     lea    ecx,[esi+0xb8]
0x493133     53                               push   ebx
0x493134     50                               push   eax
0x493135     ffd2                             call   edx
0x493137     8bf8                             mov    edi,eax
0x493139     ff15a025bd00                     call   DWORD PTR ds:0xbd25a0
0x49313f     81ff00010000                     cmp    edi,0x100
0x493145     750d                             jne    0x493154
0x493147     83be8cbe000000                   cmp    DWORD PTR [esi+0xbe8c],0x0
0x49314e     7404                             je     0x493154
0x493150     c645ff01                         mov    BYTE PTR [ebp-0x1],0x1
0x493154     0fb645ff                         movzx  eax,BYTE PTR [ebp-0x1]
0x493158     5f                               pop    edi
0x493159     5e                               pop    esi
0x49315a     5b                               pop    ebx
0x49315b     8be5                             mov    esp,ebp
0x49315d     5d                               pop    ebp
0x49315e     c21000                           ret    0x10
0x493161     cc                               int3
0x493162     cc                               int3
0x493163     cc                               int3
0x493164     cc                               int3
0x493165     cc                               int3
0x493166     cc                               int3
0x493167     cc                               int3
0x493168     cc                               int3
0x493169     cc                               int3
0x49316a     cc                               int3
0x49316b     cc                               int3
0x49316c     cc                               int3
0x49316d     cc                               int3
0x49316e     cc                               int3
0x49316f     cc                               int3

; s2c000a_binding 0x4af920..0x4afaf0 raw=0xaed20 SHA256=303719e82e2e738761415e7e564311bfc5daff03e823895f4e4b86e8c6551d17
0x4af920     55                               push   ebp
0x4af921     8bec                             mov    ebp,esp
0x4af923     83ec14                           sub    esp,0x14
0x4af926     53                               push   ebx
0x4af927     56                               push   esi
0x4af928     8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x4af92b     8b5e02                           mov    ebx,DWORD PTR [esi+0x2]
0x4af92e     57                               push   edi
0x4af92f     e82cf7f5ff                       call   0x40f060
0x4af934     8bf8                             mov    edi,eax
0x4af936     8d45f8                           lea    eax,[ebp-0x8]
0x4af939     50                               push   eax
0x4af93a     8d4f18                           lea    ecx,[edi+0x18]
0x4af93d     8d45fc                           lea    eax,[ebp-0x4]
0x4af940     895df8                           mov    DWORD PTR [ebp-0x8],ebx
0x4af943     e8783f3900                       call   0x8438c0
0x4af948     8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x4af94b     3b471c                           cmp    eax,DWORD PTR [edi+0x1c]
0x4af94e     740c                             je     0x4af95c
0x4af950     8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x4af953     33db                             xor    ebx,ebx
0x4af955     8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x4af958     3bc3                             cmp    eax,ebx
0x4af95a     751f                             jne    0x4af97b
0x4af95c     8b4e02                           mov    ecx,DWORD PTR [esi+0x2]
0x4af95f     51                               push   ecx
0x4af960     68406ac000                       push   0xc06a40
0x4af965     e8f6e12300                       call   0x6edb60
0x4af96a     83c408                           add    esp,0x8
0x4af96d     5f                               pop    edi
0x4af96e     5e                               pop    esi
0x4af96f     b805400080                       mov    eax,0x80004005
0x4af974     5b                               pop    ebx
0x4af975     8be5                             mov    esp,ebp
0x4af977     5d                               pop    ebp
0x4af978     c20c00                           ret    0xc
0x4af97b     895df8                           mov    DWORD PTR [ebp-0x8],ebx
0x4af97e     e81d52f5ff                       call   0x404ba0
0x4af983     8b5602                           mov    edx,DWORD PTR [esi+0x2]
0x4af986     3b90505f0000                     cmp    edx,DWORD PTR [eax+0x5f50]
0x4af98c     7521                             jne    0x4af9af
0x4af98e     8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4af994     8b01                             mov    eax,DWORD PTR [ecx]
0x4af996     8b5014                           mov    edx,DWORD PTR [eax+0x14]
0x4af999     ffd2                             call   edx
0x4af99b     8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4af9a1     8b01                             mov    eax,DWORD PTR [ecx]
0x4af9a3     8b500c                           mov    edx,DWORD PTR [eax+0xc]
0x4af9a6     ffd2                             call   edx
0x4af9a8     c745f801000000                   mov    DWORD PTR [ebp-0x8],0x1
0x4af9af     385e06                           cmp    BYTE PTR [esi+0x6],bl
0x4af9b2     0f8e0f010000                     jle    0x4afac7
0x4af9b8     eb08                             jmp    0x4af9c2
0x4af9ba     8d9b00000000                     lea    ebx,[ebx+0x0]
0x4af9c0     8bf1                             mov    esi,ecx
0x4af9c2     0fb7749e07                       movzx  esi,WORD PTR [esi+ebx*4+0x7]
0x4af9c7     8975f4                           mov    DWORD PTR [ebp-0xc],esi
0x4af9ca     e891f6f5ff                       call   0x40f060
0x4af9cf     8bf8                             mov    edi,eax
0x4af9d1     8d45f4                           lea    eax,[ebp-0xc]
0x4af9d4     50                               push   eax
0x4af9d5     8d4f08                           lea    ecx,[edi+0x8]
0x4af9d8     8d45f0                           lea    eax,[ebp-0x10]
0x4af9db     e820f53700                       call   0x82ef00
0x4af9e0     8b45f0                           mov    eax,DWORD PTR [ebp-0x10]
0x4af9e3     3b470c                           cmp    eax,DWORD PTR [edi+0xc]
0x4af9e6     7407                             je     0x4af9ef
0x4af9e8     8b7810                           mov    edi,DWORD PTR [eax+0x10]
0x4af9eb     85ff                             test   edi,edi
0x4af9ed     7512                             jne    0x4afa01
0x4af9ef     68706ac000                       push   0xc06a70
0x4af9f4     e867e12300                       call   0x6edb60
0x4af9f9     83c404                           add    esp,0x4
0x4af9fc     e9b6000000                       jmp    0x4afab7
0x4afa01     8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4afa04     668b4c9807                       mov    cx,WORD PTR [eax+ebx*4+0x7]
0x4afa09     663b4c9809                       cmp    cx,WORD PTR [eax+ebx*4+0x9]
0x4afa0e     7427                             je     0x4afa37
0x4afa10     837df800                         cmp    DWORD PTR [ebp-0x8],0x0
0x4afa14     7421                             je     0x4afa37
0x4afa16     e845f6f5ff                       call   0x40f060
0x4afa1b     8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4afa1e     8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4afa24     0fb7449809                       movzx  eax,WORD PTR [eax+ebx*4+0x9]
0x4afa29     8b11                             mov    edx,DWORD PTR [ecx]
0x4afa2b     8b5208                           mov    edx,DWORD PTR [edx+0x8]
0x4afa2e     57                               push   edi
0x4afa2f     50                               push   eax
0x4afa30     ffd2                             call   edx
0x4afa32     e980000000                       jmp    0x4afab7
0x4afa37     85db                             test   ebx,ebx
0x4afa39     7553                             jne    0x4afa8e
0x4afa3b     8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x4afa3e     c7879800000001000000             mov    DWORD PTR [edi+0x98],0x1
0x4afa48     897004                           mov    DWORD PTR [eax+0x4],esi
0x4afa4b     8975f4                           mov    DWORD PTR [ebp-0xc],esi
0x4afa4e     e80df6f5ff                       call   0x40f060
0x4afa53     8bf0                             mov    esi,eax
0x4afa55     8d4df4                           lea    ecx,[ebp-0xc]
0x4afa58     51                               push   ecx
0x4afa59     8d4e08                           lea    ecx,[esi+0x8]
0x4afa5c     8d45ec                           lea    eax,[ebp-0x14]
0x4afa5f     e89cf43700                       call   0x82ef00
0x4afa64     8b45ec                           mov    eax,DWORD PTR [ebp-0x14]
0x4afa67     3b460c                           cmp    eax,DWORD PTR [esi+0xc]
0x4afa6a     7416                             je     0x4afa82
0x4afa6c     8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x4afa6f     85c0                             test   eax,eax
0x4afa71     740f                             je     0x4afa82
0x4afa73     0fb79088000000                   movzx  edx,WORD PTR [eax+0x88]
0x4afa7a     8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x4afa7d     895008                           mov    DWORD PTR [eax+0x8],edx
0x4afa80     eb16                             jmp    0x4afa98
0x4afa82     8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
0x4afa85     c7410800000000                   mov    DWORD PTR [ecx+0x8],0x0
0x4afa8c     eb0a                             jmp    0x4afa98
0x4afa8e     c7879800000000000000             mov    DWORD PTR [edi+0x98],0x0
0x4afa98     837df800                         cmp    DWORD PTR [ebp-0x8],0x0
0x4afa9c     8b55fc                           mov    edx,DWORD PTR [ebp-0x4]
0x4afa9f     8b02                             mov    eax,DWORD PTR [edx]
0x4afaa1     89879c000000                     mov    DWORD PTR [edi+0x9c],eax
0x4afaa7     740e                             je     0x4afab7
0x4afaa9     8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4afaaf     8b11                             mov    edx,DWORD PTR [ecx]
0x4afab1     8b4204                           mov    eax,DWORD PTR [edx+0x4]
0x4afab4     57                               push   edi
0x4afab5     ffd0                             call   eax
0x4afab7     8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x4afaba     0fbe5106                         movsx  edx,BYTE PTR [ecx+0x6]
0x4afabe     43                               inc    ebx
0x4afabf     3bda                             cmp    ebx,edx
0x4afac1     0f8cf9feffff                     jl     0x4af9c0
0x4afac7     837df800                         cmp    DWORD PTR [ebp-0x8],0x0
0x4afacb     740d                             je     0x4afada
0x4afacd     8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4afad3     8b01                             mov    eax,DWORD PTR [ecx]
0x4afad5     8b5010                           mov    edx,DWORD PTR [eax+0x10]
0x4afad8     ffd2                             call   edx
0x4afada     5f                               pop    edi
0x4afadb     5e                               pop    esi
0x4afadc     b800010000                       mov    eax,0x100
0x4afae1     5b                               pop    ebx
0x4afae2     8be5                             mov    esp,ebp
0x4afae4     5d                               pop    ebp
0x4afae5     c20c00                           ret    0xc
0x4afae8     cc                               int3
0x4afae9     cc                               int3
0x4afaea     cc                               int3
0x4afaeb     cc                               int3
0x4afaec     cc                               int3
0x4afaed     cc                               int3
0x4afaee     cc                               int3
0x4afaef     cc                               int3

; map_resource_select 0x4df1a0..0x4df510 raw=0xde5a0 SHA256=0dfb0093212ace8a65251bec897b32ff3a2583bb2d51ac0efddcb63da7bca69a
0x4df1a0     55                               push   ebp
0x4df1a1     8bec                             mov    ebp,esp
0x4df1a3     83e4f8                           and    esp,0xfffffff8
0x4df1a6     6aff                             push   0xffffffff
0x4df1a8     6888059400                       push   0x940588
0x4df1ad     64a100000000                     mov    eax,fs:0x0
0x4df1b3     50                               push   eax
0x4df1b4     83ec68                           sub    esp,0x68
0x4df1b7     a1201fd600                       mov    eax,ds:0xd61f20
0x4df1bc     33c4                             xor    eax,esp
0x4df1be     89442460                         mov    DWORD PTR [esp+0x60],eax
0x4df1c2     53                               push   ebx
0x4df1c3     56                               push   esi
0x4df1c4     57                               push   edi
0x4df1c5     a1201fd600                       mov    eax,ds:0xd61f20
0x4df1ca     33c4                             xor    eax,esp
0x4df1cc     50                               push   eax
0x4df1cd     8d442478                         lea    eax,[esp+0x78]
0x4df1d1     64a300000000                     mov    fs:0x0,eax
0x4df1d7     8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x4df1da     8bb3a0000000                     mov    esi,DWORD PTR [ebx+0xa0]
0x4df1e0     895c241c                         mov    DWORD PTR [esp+0x1c],ebx
0x4df1e4     8bf9                             mov    edi,ecx
0x4df1e6     85f6                             test   esi,esi
0x4df1e8     7419                             je     0x4df203
0x4df1ea     56                               push   esi
0x4df1eb     e840db3400                       call   0x82cd30
0x4df1f0     56                               push   esi
0x4df1f1     e816203b00                       call   0x89120c
0x4df1f6     83c404                           add    esp,0x4
0x4df1f9     c783a000000000000000             mov    DWORD PTR [ebx+0xa0],0x0
0x4df203     8bc7                             mov    eax,edi
0x4df205     8d5001                           lea    edx,[eax+0x1]
0x4df208     8a08                             mov    cl,BYTE PTR [eax]
0x4df20a     40                               inc    eax
0x4df20b     84c9                             test   cl,cl
0x4df20d     75f9                             jne    0x4df208
0x4df20f     2bc2                             sub    eax,edx
0x4df211     0f844d020000                     je     0x4df464
0x4df217     68b0cec000                       push   0xc0ceb0
0x4df21c     8d442430                         lea    eax,[esp+0x30]
0x4df220     6a40                             push   0x40
0x4df222     50                               push   eax
0x4df223     e831493b00                       call   0x893b59
0x4df228     83c40c                           add    esp,0xc
0x4df22b     57                               push   edi
0x4df22c     8d4c2430                         lea    ecx,[esp+0x30]
0x4df230     6a40                             push   0x40
0x4df232     51                               push   ecx
0x4df233     e8cd693b00                       call   0x895c05
0x4df238     83c40c                           add    esp,0xc
0x4df23b     68c0cec000                       push   0xc0cec0
0x4df240     8d542430                         lea    edx,[esp+0x30]
0x4df244     6a40                             push   0x40
0x4df246     52                               push   edx
0x4df247     e8b9693b00                       call   0x895c05
0x4df24c     83c40c                           add    esp,0xc
0x4df24f     6838010000                       push   0x138
0x4df254     e80f203b00                       call   0x891268
0x4df259     83c404                           add    esp,0x4
0x4df25c     89442410                         mov    DWORD PTR [esp+0x10],eax
0x4df260     33ff                             xor    edi,edi
0x4df262     89bc2480000000                   mov    DWORD PTR [esp+0x80],edi
0x4df269     3bc7                             cmp    eax,edi
0x4df26b     7409                             je     0x4df276
0x4df26d     8bf0                             mov    esi,eax
0x4df26f     e8fc013500                       call   0x82f470
0x4df274     eb02                             jmp    0x4df278
0x4df276     33c0                             xor    eax,eax
0x4df278     50                               push   eax
0x4df279     8d442414                         lea    eax,[esp+0x14]
0x4df27d     83ceff                           or     esi,0xffffffff
0x4df280     89b42484000000                   mov    DWORD PTR [esp+0x84],esi
0x4df287     50                               push   eax
0x4df288     897c2418                         mov    DWORD PTR [esp+0x18],edi
0x4df28c     897c241c                         mov    DWORD PTR [esp+0x1c],edi
0x4df290     e89b1e0000                       call   0x4e1130
0x4df295     8d442410                         lea    eax,[esp+0x10]
0x4df299     8dbb98000000                     lea    edi,[ebx+0x98]
0x4df29f     c784248000000001000000           mov    DWORD PTR [esp+0x80],0x1
0x4df2aa     e8b11c0000                       call   0x4e0f60
0x4df2af     89b42480000000                   mov    DWORD PTR [esp+0x80],esi
0x4df2b6     8b7c2414                         mov    edi,DWORD PTR [esp+0x14]
0x4df2ba     85ff                             test   edi,edi
0x4df2bc     7425                             je     0x4df2e3
0x4df2be     8d4f04                           lea    ecx,[edi+0x4]
0x4df2c1     8bd6                             mov    edx,esi
0x4df2c3     f00fc111                         lock xadd DWORD PTR [ecx],edx
0x4df2c7     751a                             jne    0x4df2e3
0x4df2c9     8b07                             mov    eax,DWORD PTR [edi]
0x4df2cb     8b10                             mov    edx,DWORD PTR [eax]
0x4df2cd     8bcf                             mov    ecx,edi
0x4df2cf     ffd2                             call   edx
0x4df2d1     8d4708                           lea    eax,[edi+0x8]
0x4df2d4     f00fc130                         lock xadd DWORD PTR [eax],esi
0x4df2d8     7509                             jne    0x4df2e3
0x4df2da     8b17                             mov    edx,DWORD PTR [edi]
0x4df2dc     8b4204                           mov    eax,DWORD PTR [edx+0x4]
0x4df2df     8bcf                             mov    ecx,edi
0x4df2e1     ffd0                             call   eax
0x4df2e3     8b8398000000                     mov    eax,DWORD PTR [ebx+0x98]
0x4df2e9     50                               push   eax
0x4df2ea     8d7c2430                         lea    edi,[esp+0x30]
0x4df2ee     e84d0d3500                       call   0x830040
0x4df2f3     8b8b98000000                     mov    ecx,DWORD PTR [ebx+0x98]
0x4df2f9     89442410                         mov    DWORD PTR [esp+0x10],eax
0x4df2fd     e82e0f3500                       call   0x830230
0x4df302     8b8398000000                     mov    eax,DWORD PTR [ebx+0x98]
0x4df308     e833073500                       call   0x82fa40
0x4df30d     83ec08                           sub    esp,0x8
0x4df310     8bf4                             mov    esi,esp
0x4df312     c70600000000                     mov    DWORD PTR [esi],0x0
0x4df318     c7460400000000                   mov    DWORD PTR [esi+0x4],0x0
0x4df31f     8bbb9c000000                     mov    edi,DWORD PTR [ebx+0x9c]
0x4df325     8b8b98000000                     mov    ecx,DWORD PTR [ebx+0x98]
0x4df32b     89642420                         mov    DWORD PTR [esp+0x20],esp
0x4df32f     894c2420                         mov    DWORD PTR [esp+0x20],ecx
0x4df333     85ff                             test   edi,edi
0x4df335     7416                             je     0x4df34d
0x4df337     8bd7                             mov    edx,edi
0x4df339     e812cff9ff                       call   0x47c250
0x4df33e     84c0                             test   al,al
0x4df340     740b                             je     0x4df34d
0x4df342     8b542420                         mov    edx,DWORD PTR [esp+0x20]
0x4df346     57                               push   edi
0x4df347     52                               push   edx
0x4df348     e8733e2c00                       call   0x7a31c0
0x4df34d     e8be0b3500                       call   0x82ff10
0x4df352     8b742424                         mov    esi,DWORD PTR [esp+0x24]
0x4df356     8bbea4000000                     mov    edi,DWORD PTR [esi+0xa4]
0x4df35c     83c408                           add    esp,0x8
0x4df35f     8986a0000000                     mov    DWORD PTR [esi+0xa0],eax
0x4df365     85ff                             test   edi,edi
0x4df367     7419                             je     0x4df382
0x4df369     57                               push   edi
0x4df36a     e821dc3400                       call   0x82cf90
0x4df36f     57                               push   edi
0x4df370     e8971e3b00                       call   0x89120c
0x4df375     83c404                           add    esp,0x4
0x4df378     c786a400000000000000             mov    DWORD PTR [esi+0xa4],0x0
0x4df382     837c241000                       cmp    DWORD PTR [esp+0x10],0x0
0x4df387     0f84d7000000                     je     0x4df464
0x4df38d     e80e58f2ff                       call   0x404ba0
0x4df392     8b804c5f0000                     mov    eax,DWORD PTR [eax+0x5f4c]
0x4df398     83f802                           cmp    eax,0x2
0x4df39b     0f85c3000000                     jne    0x4df464
0x4df3a1     6a34                             push   0x34
0x4df3a3     e8c01e3b00                       call   0x891268
0x4df3a8     83c404                           add    esp,0x4
0x4df3ab     89442410                         mov    DWORD PTR [esp+0x10],eax
0x4df3af     c784248000000002000000           mov    DWORD PTR [esp+0x80],0x2
0x4df3ba     85c0                             test   eax,eax
0x4df3bc     7408                             je     0x4df3c6
0x4df3be     50                               push   eax
0x4df3bf     e81cdb3400                       call   0x82cee0
0x4df3c4     eb02                             jmp    0x4df3c8
0x4df3c6     33c0                             xor    eax,eax
0x4df3c8     83cfff                           or     edi,0xffffffff
0x4df3cb     89bc2480000000                   mov    DWORD PTR [esp+0x80],edi
0x4df3d2     83ec08                           sub    esp,0x8
0x4df3d5     8986a4000000                     mov    DWORD PTR [esi+0xa4],eax
0x4df3db     8d8398000000                     lea    eax,[ebx+0x98]
0x4df3e1     8bcc                             mov    ecx,esp
0x4df3e3     89642418                         mov    DWORD PTR [esp+0x18],esp
0x4df3e7     e8341b0000                       call   0x4e0f20
0x4df3ec     8d442428                         lea    eax,[esp+0x28]
0x4df3f0     50                               push   eax
0x4df3f1     e83a123500                       call   0x830630
0x4df3f6     c784248000000003000000           mov    DWORD PTR [esp+0x80],0x3
0x4df401     8b0d38a8fb00                     mov    ecx,DWORD PTR ds:0xfba838
0x4df407     8b4140                           mov    eax,DWORD PTR [ecx+0x40]
0x4df40a     8b9b98000000                     mov    ebx,DWORD PTR [ebx+0x98]
0x4df410     85c0                             test   eax,eax
0x4df412     740e                             je     0x4df422
0x4df414     8b9058010000                     mov    edx,DWORD PTR [eax+0x158]
0x4df41a     8b805c010000                     mov    eax,DWORD PTR [eax+0x15c]
0x4df420     eb17                             jmp    0x4df439
0x4df422     0f57c0                           xorps  xmm0,xmm0
0x4df425     f30f11442410                     movss  DWORD PTR [esp+0x10],xmm0
0x4df42b     8b542410                         mov    edx,DWORD PTR [esp+0x10]
0x4df42f     f30f11442414                     movss  DWORD PTR [esp+0x14],xmm0
0x4df435     8b442414                         mov    eax,DWORD PTR [esp+0x14]
0x4df439     8b8ea4000000                     mov    ecx,DWORD PTR [esi+0xa4]
0x4df43f     8b7308                           mov    esi,DWORD PTR [ebx+0x8]
0x4df442     56                               push   esi
0x4df443     8b7304                           mov    esi,DWORD PTR [ebx+0x4]
0x4df446     56                               push   esi
0x4df447     50                               push   eax
0x4df448     52                               push   edx
0x4df449     8d542430                         lea    edx,[esp+0x30]
0x4df44d     52                               push   edx
0x4df44e     e8fddb3400                       call   0x82d050
0x4df453     8d442420                         lea    eax,[esp+0x20]
0x4df457     50                               push   eax
0x4df458     89bc2484000000                   mov    DWORD PTR [esp+0x84],edi
0x4df45f     e82c000000                       call   0x4df490
0x4df464     8b4c2478                         mov    ecx,DWORD PTR [esp+0x78]
0x4df468     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4df46f     59                               pop    ecx
0x4df470     5f                               pop    edi
0x4df471     5e                               pop    esi
0x4df472     5b                               pop    ebx
0x4df473     8b4c2460                         mov    ecx,DWORD PTR [esp+0x60]
0x4df477     33cc                             xor    ecx,esp
0x4df479     e8831b3b00                       call   0x891001
0x4df47e     8be5                             mov    esp,ebp
0x4df480     5d                               pop    ebp
0x4df481     c20400                           ret    0x4
0x4df484     cc                               int3
0x4df485     cc                               int3
0x4df486     cc                               int3
0x4df487     cc                               int3
0x4df488     cc                               int3
0x4df489     cc                               int3
0x4df48a     cc                               int3
0x4df48b     cc                               int3
0x4df48c     cc                               int3
0x4df48d     cc                               int3
0x4df48e     cc                               int3
0x4df48f     cc                               int3
0x4df490     55                               push   ebp
0x4df491     8bec                             mov    ebp,esp
0x4df493     6aff                             push   0xffffffff
0x4df495     6868659000                       push   0x906568
0x4df49a     64a100000000                     mov    eax,fs:0x0
0x4df4a0     50                               push   eax
0x4df4a1     56                               push   esi
0x4df4a2     57                               push   edi
0x4df4a3     a1201fd600                       mov    eax,ds:0xd61f20
0x4df4a8     33c5                             xor    eax,ebp
0x4df4aa     50                               push   eax
0x4df4ab     8d45f4                           lea    eax,[ebp-0xc]
0x4df4ae     64a300000000                     mov    fs:0x0,eax
0x4df4b4     8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x4df4b7     c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x4df4be     8b7708                           mov    esi,DWORD PTR [edi+0x8]
0x4df4c1     85f6                             test   esi,esi
0x4df4c3     7429                             je     0x4df4ee
0x4df4c5     8d4604                           lea    eax,[esi+0x4]
0x4df4c8     83c9ff                           or     ecx,0xffffffff
0x4df4cb     f00fc108                         lock xadd DWORD PTR [eax],ecx
0x4df4cf     751d                             jne    0x4df4ee
0x4df4d1     8b16                             mov    edx,DWORD PTR [esi]
0x4df4d3     8b02                             mov    eax,DWORD PTR [edx]
0x4df4d5     8bce                             mov    ecx,esi
0x4df4d7     ffd0                             call   eax
0x4df4d9     8d4e08                           lea    ecx,[esi+0x8]
0x4df4dc     83caff                           or     edx,0xffffffff
0x4df4df     f00fc111                         lock xadd DWORD PTR [ecx],edx
0x4df4e3     7509                             jne    0x4df4ee
0x4df4e5     8b06                             mov    eax,DWORD PTR [esi]
0x4df4e7     8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x4df4ea     8bce                             mov    ecx,esi
0x4df4ec     ffd2                             call   edx
0x4df4ee     c70720cfc000                     mov    DWORD PTR [edi],0xc0cf20
0x4df4f4     8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4df4f7     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4df4fe     59                               pop    ecx
0x4df4ff     5f                               pop    edi
0x4df500     5e                               pop    esi
0x4df501     8be5                             mov    esp,ebp
0x4df503     5d                               pop    ebp
0x4df504     c20400                           ret    0x4
0x4df507     cc                               int3
0x4df508     cc                               int3
0x4df509     cc                               int3
0x4df50a     cc                               int3
0x4df50b     cc                               int3
0x4df50c     cc                               int3
0x4df50d     cc                               int3
0x4df50e     cc                               int3
0x4df50f     cc                               int3

; scenario_ready 0x4c4910..0x4c4919 raw=0xc3d10 SHA256=eae51a936685a059169cc316b6d2ad82fc3925d55cdaf06c139e453f776cb7ba
0x4c4910     55                               push   ebp
0x4c4911     8bec                             mov    ebp,esp
0x4c4913     5d                               pop    ebp
0x4c4914     e957dcfeff                       jmp    0x4b2570

; mission_ready 0x4230f0..0x42317a raw=0x224f0 SHA256=b4a47db0284c95a0ef0e53aae15e5e7a24eefce3a737eabc0f6a467f2344d5a5
0x4230f0     55                               push   ebp
0x4230f1     8bec                             mov    ebp,esp
0x4230f3     6aff                             push   0xffffffff
0x4230f5     689e799400                       push   0x94799e
0x4230fa     64a100000000                     mov    eax,fs:0x0
0x423100     50                               push   eax
0x423101     56                               push   esi
0x423102     a1201fd600                       mov    eax,ds:0xd61f20
0x423107     33c5                             xor    eax,ebp
0x423109     50                               push   eax
0x42310a     8d45f4                           lea    eax,[ebp-0xc]
0x42310d     64a300000000                     mov    fs:0x0,eax
0x423113     8b4510                           mov    eax,DWORD PTR [ebp+0x10]
0x423116     8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0x423119     50                               push   eax
0x42311a     8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x42311d     52                               push   edx
0x42311e     50                               push   eax
0x42311f     e84cf40800                       call   0x4b2570
0x423124     8bf0                             mov    esi,eax
0x423126     b801000000                       mov    eax,0x1
0x42312b     8405d4adfa00                     test   BYTE PTR ds:0xfaadd4,al
0x423131     7526                             jne    0x423159
0x423133     0905d4adfa00                     or     DWORD PTR ds:0xfaadd4,eax
0x423139     c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x423140     e83b431600                       call   0x587480
0x423145     68c0ccbc00                       push   0xbcccc0
0x42314a     e8cbf14600                       call   0x89231a
0x42314f     83c404                           add    esp,0x4
0x423152     c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x423159     6862420f00                       push   0xf4262
0x42315e     e86d791600                       call   0x58aad0
0x423163     83c404                           add    esp,0x4
0x423166     8bc6                             mov    eax,esi
0x423168     8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x42316b     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x423172     59                               pop    ecx
0x423173     5e                               pop    esi
0x423174     8be5                             mov    esp,ebp
0x423176     5d                               pop    ebp
0x423177     c20c00                           ret    0xc

; state_packet 0x4b0130..0x4b01bf raw=0xaf530 SHA256=8c455f0159324b40abd9ea1ca240572e9ef169f270961ce32d4e0e5c21d6147b
0x4b0130     55                               push   ebp
0x4b0131     8bec                             mov    ebp,esp
0x4b0133     8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x4b0136     83f802                           cmp    eax,0x2
0x4b0139     7304                             jae    0x4b013f
0x4b013b     33d2                             xor    edx,edx
0x4b013d     eb0c                             jmp    0x4b014b
0x4b013f     8d48fe                           lea    ecx,[eax-0x2]
0x4b0142     b8abaaaaaa                       mov    eax,0xaaaaaaab
0x4b0147     f7e1                             mul    ecx
0x4b0149     d1ea                             shr    edx,1
0x4b014b     85d2                             test   edx,edx
0x4b014d     746a                             je     0x4b01b9
0x4b014f     53                               push   ebx
0x4b0150     56                               push   esi
0x4b0151     8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x4b0154     57                               push   edi
0x4b0155     83c602                           add    esi,0x2
0x4b0158     8bda                             mov    ebx,edx
0x4b015a     8d9b00000000                     lea    ebx,[ebx+0x0]
0x4b0160     0fb716                           movzx  edx,WORD PTR [esi]
0x4b0163     89550c                           mov    DWORD PTR [ebp+0xc],edx
0x4b0166     e8f5eef5ff                       call   0x40f060
0x4b016b     8bf8                             mov    edi,eax
0x4b016d     8d450c                           lea    eax,[ebp+0xc]
0x4b0170     50                               push   eax
0x4b0171     8d4f08                           lea    ecx,[edi+0x8]
0x4b0174     8d4508                           lea    eax,[ebp+0x8]
0x4b0177     e884ed3700                       call   0x82ef00
0x4b017c     8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4b017f     3b470c                           cmp    eax,DWORD PTR [edi+0xc]
0x4b0182     7407                             je     0x4b018b
0x4b0184     8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x4b0187     85c0                             test   eax,eax
0x4b0189     750f                             jne    0x4b019a
0x4b018b     68fc6ac000                       push   0xc06afc
0x4b0190     e8cbd92300                       call   0x6edb60
0x4b0195     83c404                           add    esp,0x4
0x4b0198     eb16                             jmp    0x4b01b0
0x4b019a     8b90f0000000                     mov    edx,DWORD PTR [eax+0xf0]
0x4b01a0     8b5208                           mov    edx,DWORD PTR [edx+0x8]
0x4b01a3     8d88f0000000                     lea    ecx,[eax+0xf0]
0x4b01a9     0fbe4602                         movsx  eax,BYTE PTR [esi+0x2]
0x4b01ad     50                               push   eax
0x4b01ae     ffd2                             call   edx
0x4b01b0     83c603                           add    esi,0x3
0x4b01b3     4b                               dec    ebx
0x4b01b4     75aa                             jne    0x4b0160
0x4b01b6     5f                               pop    edi
0x4b01b7     5e                               pop    esi
0x4b01b8     5b                               pop    ebx
0x4b01b9     33c0                             xor    eax,eax
0x4b01bb     5d                               pop    ebp
0x4b01bc     c20c00                           ret    0xc

; fsm_transition 0x4ca060..0x4ca0ab raw=0xc9460 SHA256=2bef145cdcd604a8197d7838922ae2e06e3fe2822a9e8d2b4c682aeabe729231
0x4ca060     55                               push   ebp
0x4ca061     8bec                             mov    ebp,esp
0x4ca063     56                               push   esi
0x4ca064     57                               push   edi
0x4ca065     8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x4ca068     8bf1                             mov    esi,ecx
0x4ca06a     83ff1a                           cmp    edi,0x1a
0x4ca06d     7434                             je     0x4ca0a3
0x4ca06f     837cbe0400                       cmp    DWORD PTR [esi+edi*4+0x4],0x0
0x4ca074     742d                             je     0x4ca0a3
0x4ca076     8b4e68                           mov    ecx,DWORD PTR [esi+0x68]
0x4ca079     8b01                             mov    eax,DWORD PTR [ecx]
0x4ca07b     8b500c                           mov    edx,DWORD PTR [eax+0xc]
0x4ca07e     ffd2                             call   edx
0x4ca080     8b4668                           mov    eax,DWORD PTR [esi+0x68]
0x4ca083     8b5008                           mov    edx,DWORD PTR [eax+0x8]
0x4ca086     8b4cbe04                         mov    ecx,DWORD PTR [esi+edi*4+0x4]
0x4ca08a     89510c                           mov    DWORD PTR [ecx+0xc],edx
0x4ca08d     8b4cbe04                         mov    ecx,DWORD PTR [esi+edi*4+0x4]
0x4ca091     894e68                           mov    DWORD PTR [esi+0x68],ecx
0x4ca094     8b01                             mov    eax,DWORD PTR [ecx]
0x4ca096     8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x4ca099     ffd2                             call   edx
0x4ca09b     5f                               pop    edi
0x4ca09c     b001                             mov    al,0x1
0x4ca09e     5e                               pop    esi
0x4ca09f     5d                               pop    ebp
0x4ca0a0     c20400                           ret    0x4
0x4ca0a3     5f                               pop    edi
0x4ca0a4     32c0                             xor    al,al
0x4ca0a6     5e                               pop    esi
0x4ca0a7     5d                               pop    ebp
0x4ca0a8     c20400                           ret    0x4

; formation_clear 0x547750..0x54780a raw=0x146b50 SHA256=d7092631f921d0c23b6fd84b7aedd6a2c97797926c3bbdc350508086357c8cb1
0x547750     55                               push   ebp
0x547751     8bec                             mov    ebp,esp
0x547753     6aff                             push   0xffffffff
0x547755     687e839000                       push   0x90837e
0x54775a     64a100000000                     mov    eax,fs:0x0
0x547760     50                               push   eax
0x547761     53                               push   ebx
0x547762     56                               push   esi
0x547763     57                               push   edi
0x547764     a1201fd600                       mov    eax,ds:0xd61f20
0x547769     33c5                             xor    eax,ebp
0x54776b     50                               push   eax
0x54776c     8d45f4                           lea    eax,[ebp-0xc]
0x54776f     64a300000000                     mov    fs:0x0,eax
0x547775     33ff                             xor    edi,edi
0x547777     89790c                           mov    DWORD PTR [ecx+0xc],edi
0x54777a     897918                           mov    DWORD PTR [ecx+0x18],edi
0x54777d     897910                           mov    DWORD PTR [ecx+0x10],edi
0x547780     bb01000000                       mov    ebx,0x1
0x547785     885914                           mov    BYTE PTR [ecx+0x14],bl
0x547788     89791c                           mov    DWORD PTR [ecx+0x1c],edi
0x54778b     885920                           mov    BYTE PTR [ecx+0x20],bl
0x54778e     897924                           mov    DWORD PTR [ecx+0x24],edi
0x547791     897928                           mov    DWORD PTR [ecx+0x28],edi
0x547794     88592c                           mov    BYTE PTR [ecx+0x2c],bl
0x547797     8b7134                           mov    esi,DWORD PTR [ecx+0x34]
0x54779a     8b5130                           mov    edx,DWORD PTR [ecx+0x30]
0x54779d     3bd6                             cmp    edx,esi
0x54779f     7422                             je     0x5477c3
0x5477a1     8bc6                             mov    eax,esi
0x5477a3     3bf6                             cmp    esi,esi
0x5477a5     7419                             je     0x5477c0
0x5477a7     8b18                             mov    ebx,DWORD PTR [eax]
0x5477a9     891a                             mov    DWORD PTR [edx],ebx
0x5477ab     8b5804                           mov    ebx,DWORD PTR [eax+0x4]
0x5477ae     895a04                           mov    DWORD PTR [edx+0x4],ebx
0x5477b1     83c008                           add    eax,0x8
0x5477b4     83c208                           add    edx,0x8
0x5477b7     3bc6                             cmp    eax,esi
0x5477b9     75ec                             jne    0x5477a7
0x5477bb     bb01000000                       mov    ebx,0x1
0x5477c0     895134                           mov    DWORD PTR [ecx+0x34],edx
0x5477c3     841d207afb00                     test   BYTE PTR ds:0xfb7a20,bl
0x5477c9     751b                             jne    0x5477e6
0x5477cb     091d207afb00                     or     DWORD PTR ds:0xfb7a20,ebx
0x5477d1     897dfc                           mov    DWORD PTR [ebp-0x4],edi
0x5477d4     e8c7150000                       call   0x548da0
0x5477d9     6870d3bc00                       push   0xbcd370
0x5477de     e837ab3400                       call   0x89231a
0x5477e3     83c404                           add    esp,0x4
0x5477e6     893dd07afb00                     mov    DWORD PTR ds:0xfb7ad0,edi
0x5477ec     893de07afb00                     mov    DWORD PTR ds:0xfb7ae0,edi
0x5477f2     893df07afb00                     mov    DWORD PTR ds:0xfb7af0,edi
0x5477f8     8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x5477fb     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x547802     59                               pop    ecx
0x547803     5f                               pop    edi
0x547804     5e                               pop    esi
0x547805     5b                               pop    ebx
0x547806     8be5                             mov    esp,ebp
0x547808     5d                               pop    ebp
0x547809     c3                               ret

; field_ready_common 0x4b2570..0x4b2615 raw=0xb1970 SHA256=6b4339872f50c37744f41598488c54d23e36a7915d4c066bcbb59314acb04292
0x4b2570     55                               push   ebp
0x4b2571     8bec                             mov    ebp,esp
0x4b2573     6aff                             push   0xffffffff
0x4b2575     687cb29300                       push   0x93b27c
0x4b257a     64a100000000                     mov    eax,fs:0x0
0x4b2580     50                               push   eax
0x4b2581     53                               push   ebx
0x4b2582     a1201fd600                       mov    eax,ds:0xd61f20
0x4b2587     33c5                             xor    eax,ebp
0x4b2589     50                               push   eax
0x4b258a     8d45f4                           lea    eax,[ebp-0xc]
0x4b258d     64a300000000                     mov    fs:0x0,eax
0x4b2593     a1a4a7fb00                       mov    eax,ds:0xfba7a4
0x4b2598     bb01000000                       mov    ebx,0x1
0x4b259d     895804                           mov    DWORD PTR [eax+0x4],ebx
0x4b25a0     841db873fb00                     test   BYTE PTR ds:0xfb73b8,bl
0x4b25a6     7526                             jne    0x4b25ce
0x4b25a8     091db873fb00                     or     DWORD PTR ds:0xfb73b8,ebx
0x4b25ae     c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x4b25b5     e8b6db0a00                       call   0x560170
0x4b25ba     6810d1bc00                       push   0xbcd110
0x4b25bf     e856fd3d00                       call   0x89231a
0x4b25c4     83c404                           add    esp,0x4
0x4b25c7     c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x4b25ce     833de873fb0000                   cmp    DWORD PTR ds:0xfb73e8,0x0
0x4b25d5     752a                             jne    0x4b2601
0x4b25d7     841d147cfb00                     test   BYTE PTR ds:0xfb7c14,bl
0x4b25dd     751b                             jne    0x4b25fa
0x4b25df     091d147cfb00                     or     DWORD PTR ds:0xfb7c14,ebx
0x4b25e5     895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x4b25e8     e863e12100                       call   0x6d0750
0x4b25ed     6830d5bc00                       push   0xbcd530
0x4b25f2     e823fd3d00                       call   0x89231a
0x4b25f7     83c404                           add    esp,0x4
0x4b25fa     83253088fb00fe                   and    DWORD PTR ds:0xfb8830,0xfffffffe
0x4b2601     33c0                             xor    eax,eax
0x4b2603     8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4b2606     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4b260d     59                               pop    ecx
0x4b260e     5b                               pop    ebx
0x4b260f     8be5                             mov    esp,ebp
0x4b2611     5d                               pop    ebp
0x4b2612     c20c00                           ret    0xc

; q_loadmap 0x563c40..0x563fa0 raw=0x163040 SHA256=1e99c3897b57d900290b508aa83099f40754807af9713d75ee1435442f6a2fe0
0x563c40     55                               push   ebp
0x563c41     8bec                             mov    ebp,esp
0x563c43     83e4f8                           and    esp,0xfffffff8
0x563c46     6aff                             push   0xffffffff
0x563c48     68c0649300                       push   0x9364c0
0x563c4d     64a100000000                     mov    eax,fs:0x0
0x563c53     50                               push   eax
0x563c54     81ec28010000                     sub    esp,0x128
0x563c5a     a1201fd600                       mov    eax,ds:0xd61f20
0x563c5f     33c4                             xor    eax,esp
0x563c61     89842420010000                   mov    DWORD PTR [esp+0x120],eax
0x563c68     53                               push   ebx
0x563c69     56                               push   esi
0x563c6a     57                               push   edi
0x563c6b     a1201fd600                       mov    eax,ds:0xd61f20
0x563c70     33c4                             xor    eax,esp
0x563c72     50                               push   eax
0x563c73     8d842438010000                   lea    eax,[esp+0x138]
0x563c7a     64a300000000                     mov    fs:0x0,eax
0x563c80     8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x563c83     8bd9                             mov    ebx,ecx
0x563c85     89442414                         mov    DWORD PTR [esp+0x14],eax
0x563c89     85c0                             test   eax,eax
0x563c8b     0f84de020000                     je     0x563f6f
0x563c91     f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
0x563c98     752f                             jne    0x563cc9
0x563c9a     830de879fb0001                   or     DWORD PTR ds:0xfb79e8,0x1
0x563ca1     c784244001000000000000           mov    DWORD PTR [esp+0x140],0x0
0x563cac     e82f512300                       call   0x798de0
0x563cb1     68e0d2bc00                       push   0xbcd2e0
0x563cb6     e85fe63200                       call   0x89231a
0x563cbb     83c404                           add    esp,0x4
0x563cbe     c7842440010000ffffffff           mov    DWORD PTR [esp+0x140],0xffffffff
0x563cc9     8b35e876fb00                     mov    esi,DWORD PTR ds:0xfb76e8
0x563ccf     8b7b30                           mov    edi,DWORD PTR [ebx+0x30]
0x563cd2     83c60c                           add    esi,0xc
0x563cd5     f6052cb2fa0001                   test   BYTE PTR ds:0xfab22c,0x1
0x563cdc     b90b000000                       mov    ecx,0xb
0x563ce1     f3a5                             rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
0x563ce3     bf01000000                       mov    edi,0x1
0x563ce8     752a                             jne    0x563d14
0x563cea     093d2cb2fa00                     or     DWORD PTR ds:0xfab22c,edi
0x563cf0     89bc2440010000                   mov    DWORD PTR [esp+0x140],edi
0x563cf7     e894aff7ff                       call   0x4dec90
0x563cfc     6830cebc00                       push   0xbcce30
0x563d01     e814e63200                       call   0x89231a
0x563d06     83c404                           add    esp,0x4
0x563d09     c7842440010000ffffffff           mov    DWORD PTR [esp+0x140],0xffffffff
0x563d14     8b542414                         mov    edx,DWORD PTR [esp+0x14]
0x563d18     a178b1fa00                       mov    eax,ds:0xfab178
0x563d1d     6a00                             push   0x0
0x563d1f     6a00                             push   0x0
0x563d21     6804010000                       push   0x104
0x563d26     8d4c2430                         lea    ecx,[esp+0x30]
0x563d2a     51                               push   ecx
0x563d2b     6a00                             push   0x0
0x563d2d     6a00                             push   0x0
0x563d2f     6a00                             push   0x0
0x563d31     6a00                             push   0x0
0x563d33     52                               push   edx
0x563d34     894334                           mov    DWORD PTR [ebx+0x34],eax
0x563d37     e8a72b3300                       call   0x8968e3
0x563d3c     83c424                           add    esp,0x24
0x563d3f     6a00                             push   0x0
0x563d41     8d742428                         lea    esi,[esp+0x28]
0x563d45     e8b6e02500                       call   0x7c1e00
0x563d4a     83c404                           add    esp,0x4
0x563d4d     f605c00ffc0001                   test   BYTE PTR ds:0xfc0fc0,0x1
0x563d54     752e                             jne    0x563d84
0x563d56     093dc00ffc00                     or     DWORD PTR ds:0xfc0fc0,edi
0x563d5c     c784244001000002000000           mov    DWORD PTR [esp+0x140],0x2
0x563d67     e8e4501700                       call   0x6d8e50
0x563d6c     68b0dbbc00                       push   0xbcdbb0
0x563d71     e8a4e53200                       call   0x89231a
0x563d76     83c404                           add    esp,0x4
0x563d79     c7842440010000ffffffff           mov    DWORD PTR [esp+0x140],0xffffffff
0x563d84     b9c80ffc00                       mov    ecx,0xfc0fc8
0x563d89     e8f2591700                       call   0x6d9780
0x563d8e     a138a8fb00                       mov    eax,ds:0xfba838
0x563d93     8b4848                           mov    ecx,DWORD PTR [eax+0x48]
0x563d96     2b4844                           sub    ecx,DWORD PTR [eax+0x44]
0x563d99     c1f902                           sar    ecx,0x2
0x563d9c     85c9                             test   ecx,ecx
0x563d9e     0f84cb010000                     je     0x563f6f
0x563da4     8b5044                           mov    edx,DWORD PTR [eax+0x44]
0x563da7     8b32                             mov    esi,DWORD PTR [edx]
0x563da9     85f6                             test   esi,esi
0x563dab     0f84be010000                     je     0x563f6f
0x563db1     f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
0x563db8     8b4608                           mov    eax,DWORD PTR [esi+0x8]
0x563dbb     8b3e                             mov    edi,DWORD PTR [esi]
0x563dbd     8b5e04                           mov    ebx,DWORD PTR [esi+0x4]
0x563dc0     89442420                         mov    DWORD PTR [esp+0x20],eax
0x563dc4     752f                             jne    0x563df5
0x563dc6     830de879fb0001                   or     DWORD PTR ds:0xfb79e8,0x1
0x563dcd     c784244001000003000000           mov    DWORD PTR [esp+0x140],0x3
0x563dd8     e803502300                       call   0x798de0
0x563ddd     68e0d2bc00                       push   0xbcd2e0
0x563de2     e833e53200                       call   0x89231a
0x563de7     83c404                           add    esp,0x4
0x563dea     c7842440010000ffffffff           mov    DWORD PTR [esp+0x140],0xffffffff
0x563df5     a1e876fb00                       mov    eax,ds:0xfb76e8
0x563dfa     8b542420                         mov    edx,DWORD PTR [esp+0x20]
0x563dfe     89780c                           mov    DWORD PTR [eax+0xc],edi
0x563e01     33ff                             xor    edi,edi
0x563e03     895810                           mov    DWORD PTR [eax+0x10],ebx
0x563e06     8bc8                             mov    ecx,eax
0x563e08     8d5f01                           lea    ebx,[edi+0x1]
0x563e0b     895014                           mov    DWORD PTR [eax+0x14],edx
0x563e0e     89b9cc000000                     mov    DWORD PTR [ecx+0xcc],edi
0x563e14     f30f104614                       movss  xmm0,DWORD PTR [esi+0x14]
0x563e19     f30f11442414                     movss  DWORD PTR [esp+0x14],xmm0
0x563e1f     841de879fb00                     test   BYTE PTR ds:0xfb79e8,bl
0x563e25     752e                             jne    0x563e55
0x563e27     091de879fb00                     or     DWORD PTR ds:0xfb79e8,ebx
0x563e2d     c784244001000004000000           mov    DWORD PTR [esp+0x140],0x4
0x563e38     e8a34f2300                       call   0x798de0
0x563e3d     68e0d2bc00                       push   0xbcd2e0
0x563e42     e8d3e43200                       call   0x89231a
0x563e47     83c404                           add    esp,0x4
0x563e4a     c7842440010000ffffffff           mov    DWORD PTR [esp+0x140],0xffffffff
0x563e55     f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
0x563e5c     a1e876fb00                       mov    eax,ds:0xfb76e8
0x563e61     f30f10442414                     movss  xmm0,DWORD PTR [esp+0x14]
0x563e67     f30f114020                       movss  DWORD PTR [eax+0x20],xmm0
0x563e6c     89b8cc000000                     mov    DWORD PTR [eax+0xcc],edi
0x563e72     f30f104624                       movss  xmm0,DWORD PTR [esi+0x24]
0x563e77     f30f11442414                     movss  DWORD PTR [esp+0x14],xmm0
0x563e7d     7534                             jne    0x563eb3
0x563e7f     091de879fb00                     or     DWORD PTR ds:0xfb79e8,ebx
0x563e85     c784244001000005000000           mov    DWORD PTR [esp+0x140],0x5
0x563e90     e84b4f2300                       call   0x798de0
0x563e95     68e0d2bc00                       push   0xbcd2e0
0x563e9a     e87be43200                       call   0x89231a
0x563e9f     f30f10442418                     movss  xmm0,DWORD PTR [esp+0x18]
0x563ea5     83c404                           add    esp,0x4
0x563ea8     c7842440010000ffffffff           mov    DWORD PTR [esp+0x140],0xffffffff
0x563eb3     a1e876fb00                       mov    eax,ds:0xfb76e8
0x563eb8     8bc8                             mov    ecx,eax
0x563eba     8b00                             mov    eax,DWORD PTR [eax]
0x563ebc     3bc7                             cmp    eax,edi
0x563ebe     7405                             je     0x563ec5
0x563ec0     f30f11407c                       movss  DWORD PTR [eax+0x7c],xmm0
0x563ec5     f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
0x563ecc     f30f114130                       movss  DWORD PTR [ecx+0x30],xmm0
0x563ed1     f30f10460c                       movss  xmm0,DWORD PTR [esi+0xc]
0x563ed6     f30f11442414                     movss  DWORD PTR [esp+0x14],xmm0
0x563edc     752e                             jne    0x563f0c
0x563ede     091de879fb00                     or     DWORD PTR ds:0xfb79e8,ebx
0x563ee4     c784244001000006000000           mov    DWORD PTR [esp+0x140],0x6
0x563eef     e8ec4e2300                       call   0x798de0
0x563ef4     68e0d2bc00                       push   0xbcd2e0
0x563ef9     e81ce43200                       call   0x89231a
0x563efe     83c404                           add    esp,0x4
0x563f01     c7842440010000ffffffff           mov    DWORD PTR [esp+0x140],0xffffffff
0x563f0c     f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
0x563f13     a1e876fb00                       mov    eax,ds:0xfb76e8
0x563f18     f30f10442414                     movss  xmm0,DWORD PTR [esp+0x14]
0x563f1e     f30f114018                       movss  DWORD PTR [eax+0x18],xmm0
0x563f23     89b8cc000000                     mov    DWORD PTR [eax+0xcc],edi
0x563f29     f30f104618                       movss  xmm0,DWORD PTR [esi+0x18]
0x563f2e     f30f11442414                     movss  DWORD PTR [esp+0x14],xmm0
0x563f34     7523                             jne    0x563f59
0x563f36     091de879fb00                     or     DWORD PTR ds:0xfb79e8,ebx
0x563f3c     c784244001000007000000           mov    DWORD PTR [esp+0x140],0x7
0x563f47     e8944e2300                       call   0x798de0
0x563f4c     68e0d2bc00                       push   0xbcd2e0
0x563f51     e8c4e33200                       call   0x89231a
0x563f56     83c404                           add    esp,0x4
0x563f59     a1e876fb00                       mov    eax,ds:0xfb76e8
0x563f5e     f30f10442414                     movss  xmm0,DWORD PTR [esp+0x14]
0x563f64     f30f114024                       movss  DWORD PTR [eax+0x24],xmm0
0x563f69     89b8cc000000                     mov    DWORD PTR [eax+0xcc],edi
0x563f6f     8b8c2438010000                   mov    ecx,DWORD PTR [esp+0x138]
0x563f76     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x563f7d     59                               pop    ecx
0x563f7e     5f                               pop    edi
0x563f7f     5e                               pop    esi
0x563f80     5b                               pop    ebx
0x563f81     8b8c2420010000                   mov    ecx,DWORD PTR [esp+0x120]
0x563f88     33cc                             xor    ecx,esp
0x563f8a     e872d03200                       call   0x891001
0x563f8f     8be5                             mov    esp,ebp
0x563f91     5d                               pop    ebp
0x563f92     c20400                           ret    0x4
0x563f95     cc                               int3
0x563f96     cc                               int3
0x563f97     cc                               int3
0x563f98     cc                               int3
0x563f99     cc                               int3
0x563f9a     cc                               int3
0x563f9b     cc                               int3
0x563f9c     cc                               int3
0x563f9d     cc                               int3
0x563f9e     cc                               int3
0x563f9f     cc                               int3

; q_restoremap 0x563fa0..0x5643bd raw=0x1633a0 SHA256=693ed5e79dd68fbad0adacd08ab767ffc3f6e067155c862b58fe4f321fcbc5bf
0x563fa0     55                               push   ebp
0x563fa1     8bec                             mov    ebp,esp
0x563fa3     83e4f8                           and    esp,0xfffffff8
0x563fa6     6aff                             push   0xffffffff
0x563fa8     6822649300                       push   0x936422
0x563fad     64a100000000                     mov    eax,fs:0x0
0x563fb3     50                               push   eax
0x563fb4     83ec38                           sub    esp,0x38
0x563fb7     a1201fd600                       mov    eax,ds:0xd61f20
0x563fbc     33c4                             xor    eax,esp
0x563fbe     89442430                         mov    DWORD PTR [esp+0x30],eax
0x563fc2     53                               push   ebx
0x563fc3     56                               push   esi
0x563fc4     57                               push   edi
0x563fc5     a1201fd600                       mov    eax,ds:0xd61f20
0x563fca     33c4                             xor    eax,esp
0x563fcc     50                               push   eax
0x563fcd     8d442448                         lea    eax,[esp+0x48]
0x563fd1     64a300000000                     mov    fs:0x0,eax
0x563fd7     f605b075fb0001                   test   BYTE PTR ds:0xfb75b0,0x1
0x563fde     8bf1                             mov    esi,ecx
0x563fe0     8974241c                         mov    DWORD PTR [esp+0x1c],esi
0x563fe4     bf01000000                       mov    edi,0x1
0x563fe9     7528                             jne    0x564013
0x563feb     093db075fb00                     or     DWORD PTR ds:0xfb75b0,edi
0x563ff1     c744245000000000                 mov    DWORD PTR [esp+0x50],0x0
0x563ff9     e882fdf8ff                       call   0x4f3d80
0x563ffe     68e0d1bc00                       push   0xbcd1e0
0x564003     e812e33200                       call   0x89231a
0x564008     83c404                           add    esp,0x4
0x56400b     c7442450ffffffff                 mov    DWORD PTR [esp+0x50],0xffffffff
0x564013     8b4634                           mov    eax,DWORD PTR [esi+0x34]
0x564016     8d4c2418                         lea    ecx,[esp+0x18]
0x56401a     89442418                         mov    DWORD PTR [esp+0x18],eax
0x56401e     51                               push   ecx
0x56401f     8d442418                         lea    eax,[esp+0x18]
0x564023     b9e074fb00                       mov    ecx,0xfb74e0
0x564028     e8c3bdf1ff                       call   0x47fdf0
0x56402d     8b442414                         mov    eax,DWORD PTR [esp+0x14]
0x564031     bb10000000                       mov    ebx,0x10
0x564036     3b05e474fb00                     cmp    eax,DWORD PTR ds:0xfb74e4
0x56403c     741a                             je     0x564058
0x56403e     03c3                             add    eax,ebx
0x564040     395814                           cmp    DWORD PTR [eax+0x14],ebx
0x564043     7202                             jb     0x564047
0x564045     8b00                             mov    eax,DWORD PTR [eax]
0x564047     8bc8                             mov    ecx,eax
0x564049     bf7074fb00                       mov    edi,0xfb7470
0x56404e     e82d2ef9ff                       call   0x4f6e80
0x564053     bf01000000                       mov    edi,0x1
0x564058     f605b075fb0001                   test   BYTE PTR ds:0xfb75b0,0x1
0x56405f     7524                             jne    0x564085
0x564061     093db075fb00                     or     DWORD PTR ds:0xfb75b0,edi
0x564067     897c2450                         mov    DWORD PTR [esp+0x50],edi
0x56406b     e810fdf8ff                       call   0x4f3d80
0x564070     68e0d1bc00                       push   0xbcd1e0
0x564075     e8a0e23200                       call   0x89231a
0x56407a     83c404                           add    esp,0x4
0x56407d     c7442450ffffffff                 mov    DWORD PTR [esp+0x50],0xffffffff
0x564085     8b5634                           mov    edx,DWORD PTR [esi+0x34]
0x564088     89542414                         mov    DWORD PTR [esp+0x14],edx
0x56408c     8d542414                         lea    edx,[esp+0x14]
0x564090     b9b074fb00                       mov    ecx,0xfb74b0
0x564095     e8563df9ff                       call   0x4f7df0
0x56409a     395814                           cmp    DWORD PTR [eax+0x14],ebx
0x56409d     7202                             jb     0x5640a1
0x56409f     8b00                             mov    eax,DWORD PTR [eax]
0x5640a1     f605b075fb0001                   test   BYTE PTR ds:0xfb75b0,0x1
0x5640a8     89442418                         mov    DWORD PTR [esp+0x18],eax
0x5640ac     7528                             jne    0x5640d6
0x5640ae     093db075fb00                     or     DWORD PTR ds:0xfb75b0,edi
0x5640b4     c744245002000000                 mov    DWORD PTR [esp+0x50],0x2
0x5640bc     e8bffcf8ff                       call   0x4f3d80
0x5640c1     68e0d1bc00                       push   0xbcd1e0
0x5640c6     e84fe23200                       call   0x89231a
0x5640cb     83c404                           add    esp,0x4
0x5640ce     c7442450ffffffff                 mov    DWORD PTR [esp+0x50],0xffffffff
0x5640d6     8b4e34                           mov    ecx,DWORD PTR [esi+0x34]
0x5640d9     8d542414                         lea    edx,[esp+0x14]
0x5640dd     894c2414                         mov    DWORD PTR [esp+0x14],ecx
0x5640e1     52                               push   edx
0x5640e2     8d442424                         lea    eax,[esp+0x24]
0x5640e6     b9f074fb00                       mov    ecx,0xfb74f0
0x5640eb     e800bdf1ff                       call   0x47fdf0
0x5640f0     8b442420                         mov    eax,DWORD PTR [esp+0x20]
0x5640f4     3b05f474fb00                     cmp    eax,DWORD PTR ds:0xfb74f4
0x5640fa     741b                             je     0x564117
0x5640fc     83c010                           add    eax,0x10
0x5640ff     395814                           cmp    DWORD PTR [eax+0x14],ebx
0x564102     7202                             jb     0x564106
0x564104     8b00                             mov    eax,DWORD PTR [eax]
0x564106     8bc8                             mov    ecx,eax
0x564108     bf7074fb00                       mov    edi,0xfb7470
0x56410d     e86e2df9ff                       call   0x4f6e80
0x564112     bf01000000                       mov    edi,0x1
0x564117     837e5400                         cmp    DWORD PTR [esi+0x54],0x0
0x56411b     0f84bc010000                     je     0x5642dd
0x564121     6a06                             push   0x6
0x564123     683c07c100                       push   0xc1073c
0x564128     8d4c242c                         lea    ecx,[esp+0x2c]
0x56412c     c74424400f000000                 mov    DWORD PTR [esp+0x40],0xf
0x564134     c744243c00000000                 mov    DWORD PTR [esp+0x3c],0x0
0x56413c     c644242c00                       mov    BYTE PTR [esp+0x2c],0x0
0x564141     e82ae9e9ff                       call   0x402a70
0x564146     6aff                             push   0xffffffff
0x564148     6a00                             push   0x0
0x56414a     83c644                           add    esi,0x44
0x56414d     bb03000000                       mov    ebx,0x3
0x564152     56                               push   esi
0x564153     8d4c2430                         lea    ecx,[esp+0x30]
0x564157     895c245c                         mov    DWORD PTR [esp+0x5c],ebx
0x56415b     e870dde9ff                       call   0x401ed0
0x564160     f6052888fb0001                   test   BYTE PTR ds:0xfb8828,0x1
0x564167     7522                             jne    0x56418b
0x564169     830d2888fb0001                   or     DWORD PTR ds:0xfb8828,0x1
0x564170     c644245004                       mov    BYTE PTR [esp+0x50],0x4
0x564175     e8d6b6feff                       call   0x54f850
0x56417a     6880d5bc00                       push   0xbcd580
0x56417f     e896e13200                       call   0x89231a
0x564184     83c404                           add    esp,0x4
0x564187     885c2450                         mov    BYTE PTR [esp+0x50],bl
0x56418b     f6052888fb0001                   test   BYTE PTR ds:0xfb8828,0x1
0x564192     668b35ea90fb00                   mov    si,WORD PTR ds:0xfb90ea
0x564199     7522                             jne    0x5641bd
0x56419b     830d2888fb0001                   or     DWORD PTR ds:0xfb8828,0x1
0x5641a2     c644245005                       mov    BYTE PTR [esp+0x50],0x5
0x5641a7     e8a4b6feff                       call   0x54f850
0x5641ac     6880d5bc00                       push   0xbcd580
0x5641b1     e864e13200                       call   0x89231a
0x5641b6     83c404                           add    esp,0x4
0x5641b9     885c2450                         mov    BYTE PTR [esp+0x50],bl
0x5641bd     f605c00ffc0001                   test   BYTE PTR ds:0xfc0fc0,0x1
0x5641c4     f30f10055c93fb00                 movss  xmm0,DWORD PTR ds:0xfb935c
0x5641cc     f30f11442414                     movss  DWORD PTR [esp+0x14],xmm0
0x5641d2     7522                             jne    0x5641f6
0x5641d4     830dc00ffc0001                   or     DWORD PTR ds:0xfc0fc0,0x1
0x5641db     c644245006                       mov    BYTE PTR [esp+0x50],0x6
0x5641e0     e86b4c1700                       call   0x6d8e50
0x5641e5     68b0dbbc00                       push   0xbcdbb0
0x5641ea     e82be13200                       call   0x89231a
0x5641ef     83c404                           add    esp,0x4
0x5641f2     885c2450                         mov    BYTE PTR [esp+0x50],bl
0x5641f6     837c243810                       cmp    DWORD PTR [esp+0x38],0x10
0x5641fb     8b7c2424                         mov    edi,DWORD PTR [esp+0x24]
0x5641ff     7304                             jae    0x564205
0x564201     8d7c2424                         lea    edi,[esp+0x24]
0x564205     f605c00ffc0001                   test   BYTE PTR ds:0xfc0fc0,0x1
0x56420c     7522                             jne    0x564230
0x56420e     830dc00ffc0001                   or     DWORD PTR ds:0xfc0fc0,0x1
0x564215     c644245007                       mov    BYTE PTR [esp+0x50],0x7
0x56421a     e8314c1700                       call   0x6d8e50
0x56421f     68b0dbbc00                       push   0xbcdbb0
0x564224     e8f1e03200                       call   0x89231a
0x564229     83c404                           add    esp,0x4
0x56422c     885c2450                         mov    BYTE PTR [esp+0x50],bl
0x564230     0fbfc6                           movsx  eax,si
0x564233     89442420                         mov    DWORD PTR [esp+0x20],eax
0x564237     db442420                         fild   DWORD PTR [esp+0x20]
0x56423b     d84c2414                         fmul   DWORD PTR [esp+0x14]
0x56423f     e8ccaa3900                       call   0x8fed10
0x564244     e827681700                       call   0x6daa70
0x564249     e8c2aa3900                       call   0x8fed10
0x56424e     0fb7c0                           movzx  eax,ax
0x564251     50                               push   eax
0x564252     6a01                             push   0x1
0x564254     57                               push   edi
0x564255     68c80ffc00                       push   0xfc0fc8
0x56425a     b9fc0ffc00                       mov    ecx,0xfc0ffc
0x56425f     e8cc581700                       call   0x6d9b30
0x564264     f605c00ffc0001                   test   BYTE PTR ds:0xfc0fc0,0x1
0x56426b     7522                             jne    0x56428f
0x56426d     830dc00ffc0001                   or     DWORD PTR ds:0xfc0fc0,0x1
0x564274     c644245008                       mov    BYTE PTR [esp+0x50],0x8
0x564279     e8d24b1700                       call   0x6d8e50
0x56427e     68b0dbbc00                       push   0xbcdbb0
0x564283     e892e03200                       call   0x89231a
0x564288     83c404                           add    esp,0x4
0x56428b     885c2450                         mov    BYTE PTR [esp+0x50],bl
0x56428f     8b4c241c                         mov    ecx,DWORD PTR [esp+0x1c]
0x564293     8b5134                           mov    edx,DWORD PTR [ecx+0x34]
0x564296     52                               push   edx
0x564297     68c80ffc00                       push   0xfc0fc8
0x56429c     e8df521700                       call   0x6d9580
0x5642a1     c7442450ffffffff                 mov    DWORD PTR [esp+0x50],0xffffffff
0x5642a9     837c243810                       cmp    DWORD PTR [esp+0x38],0x10
0x5642ae     720d                             jb     0x5642bd
0x5642b0     8b442424                         mov    eax,DWORD PTR [esp+0x24]
0x5642b4     50                               push   eax
0x5642b5     e852cf3200                       call   0x89120c
0x5642ba     83c404                           add    esp,0x4
0x5642bd     8b74241c                         mov    esi,DWORD PTR [esp+0x1c]
0x5642c1     c74424380f000000                 mov    DWORD PTR [esp+0x38],0xf
0x5642c9     c744243400000000                 mov    DWORD PTR [esp+0x34],0x0
0x5642d1     c644242400                       mov    BYTE PTR [esp+0x24],0x0
0x5642d6     bf01000000                       mov    edi,0x1
0x5642db     eb3f                             jmp    0x56431c
0x5642dd     f605c00ffc0001                   test   BYTE PTR ds:0xfc0fc0,0x1
0x5642e4     7528                             jne    0x56430e
0x5642e6     093dc00ffc00                     or     DWORD PTR ds:0xfc0fc0,edi
0x5642ec     c744245009000000                 mov    DWORD PTR [esp+0x50],0x9
0x5642f4     e8574b1700                       call   0x6d8e50
0x5642f9     68b0dbbc00                       push   0xbcdbb0
0x5642fe     e817e03200                       call   0x89231a
0x564303     83c404                           add    esp,0x4
0x564306     c7442450ffffffff                 mov    DWORD PTR [esp+0x50],0xffffffff
0x56430e     8b4e34                           mov    ecx,DWORD PTR [esi+0x34]
0x564311     51                               push   ecx
0x564312     68c80ffc00                       push   0xfc0fc8
0x564317     e864521700                       call   0x6d9580
0x56431c     f6052cb2fa0001                   test   BYTE PTR ds:0xfab22c,0x1
0x564323     7528                             jne    0x56434d
0x564325     093d2cb2fa00                     or     DWORD PTR ds:0xfab22c,edi
0x56432b     c74424500a000000                 mov    DWORD PTR [esp+0x50],0xa
0x564333     e858a9f7ff                       call   0x4dec90
0x564338     6830cebc00                       push   0xbcce30
0x56433d     e8d8df3200                       call   0x89231a
0x564342     83c404                           add    esp,0x4
0x564345     c7442450ffffffff                 mov    DWORD PTR [esp+0x50],0xffffffff
0x56434d     8b1578b1fa00                     mov    edx,DWORD PTR ds:0xfab178
0x564353     895634                           mov    DWORD PTR [esi+0x34],edx
0x564356     8b742418                         mov    esi,DWORD PTR [esp+0x18]
0x56435a     6a00                             push   0x0
0x56435c     e89fda2500                       call   0x7c1e00
0x564361     83c404                           add    esp,0x4
0x564364     f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
0x56436b     7521                             jne    0x56438e
0x56436d     830de879fb0001                   or     DWORD PTR ds:0xfb79e8,0x1
0x564374     c74424500b000000                 mov    DWORD PTR [esp+0x50],0xb
0x56437c     e85f4a2300                       call   0x798de0
0x564381     68e0d2bc00                       push   0xbcd2e0
0x564386     e88fdf3200                       call   0x89231a
0x56438b     83c404                           add    esp,0x4
0x56438e     8b44241c                         mov    eax,DWORD PTR [esp+0x1c]
0x564392     8b4830                           mov    ecx,DWORD PTR [eax+0x30]
0x564395     a1e876fb00                       mov    eax,ds:0xfb76e8
0x56439a     e8d13f2300                       call   0x798370
0x56439f     8b4c2448                         mov    ecx,DWORD PTR [esp+0x48]
0x5643a3     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x5643aa     59                               pop    ecx
0x5643ab     5f                               pop    edi
0x5643ac     5e                               pop    esi
0x5643ad     5b                               pop    ebx
0x5643ae     8b4c2430                         mov    ecx,DWORD PTR [esp+0x30]
0x5643b2     33cc                             xor    ecx,esp
0x5643b4     e848cc3200                       call   0x891001
0x5643b9     8be5                             mov    esp,ebp
0x5643bb     5d                               pop    ebp
0x5643bc     c3                               ret

; graphics_map_load 0x7c1e00..0x7c2064 raw=0x3c1200 SHA256=672378b0519ad827520e0d67e1afcbc8ca86206a44b053ee77ee3329ba21fc66
0x7c1e00     55                               push   ebp
0x7c1e01     8bec                             mov    ebp,esp
0x7c1e03     6aff                             push   0xffffffff
0x7c1e05     68728a9100                       push   0x918a72
0x7c1e0a     64a100000000                     mov    eax,fs:0x0
0x7c1e10     50                               push   eax
0x7c1e11     81ec44010000                     sub    esp,0x144
0x7c1e17     a1201fd600                       mov    eax,ds:0xd61f20
0x7c1e1c     33c5                             xor    eax,ebp
0x7c1e1e     8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x7c1e21     53                               push   ebx
0x7c1e22     57                               push   edi
0x7c1e23     50                               push   eax
0x7c1e24     8d45f4                           lea    eax,[ebp-0xc]
0x7c1e27     64a300000000                     mov    fs:0x0,eax
0x7c1e2d     33db                             xor    ebx,ebx
0x7c1e2f     8bc6                             mov    eax,esi
0x7c1e31     c785c8feffff0f000000             mov    DWORD PTR [ebp-0x138],0xf
0x7c1e3b     899dc4feffff                     mov    DWORD PTR [ebp-0x13c],ebx
0x7c1e41     889db4feffff                     mov    BYTE PTR [ebp-0x14c],bl
0x7c1e47     8d5001                           lea    edx,[eax+0x1]
0x7c1e4a     8d9b00000000                     lea    ebx,[ebx+0x0]
0x7c1e50     8a08                             mov    cl,BYTE PTR [eax]
0x7c1e52     40                               inc    eax
0x7c1e53     3acb                             cmp    cl,bl
0x7c1e55     75f9                             jne    0x7c1e50
0x7c1e57     2bc2                             sub    eax,edx
0x7c1e59     50                               push   eax
0x7c1e5a     56                               push   esi
0x7c1e5b     8d8db4feffff                     lea    ecx,[ebp-0x14c]
0x7c1e61     e80a0cc4ff                       call   0x402a70
0x7c1e66     6a04                             push   0x4
0x7c1e68     6834fdc400                       push   0xc4fd34
0x7c1e6d     8d8db4feffff                     lea    ecx,[ebp-0x14c]
0x7c1e73     895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x7c1e76     e84501c4ff                       call   0x401fc0
0x7c1e7b     83bdc8feffff10                   cmp    DWORD PTR [ebp-0x138],0x10
0x7c1e82     8bbdb4feffff                     mov    edi,DWORD PTR [ebp-0x14c]
0x7c1e88     7306                             jae    0x7c1e90
0x7c1e8a     8dbdb4feffff                     lea    edi,[ebp-0x14c]
0x7c1e90     f605f81dfe0001                   test   BYTE PTR ds:0xfe1df8,0x1
0x7c1e97     7520                             jne    0x7c1eb9
0x7c1e99     830df81dfe0001                   or     DWORD PTR ds:0xfe1df8,0x1
0x7c1ea0     c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x7c1ea4     e8374df5ff                       call   0x716be0
0x7c1ea9     68a0f1bc00                       push   0xbcf1a0
0x7c1eae     e867040d00                       call   0x89231a
0x7c1eb3     83c404                           add    esp,0x4
0x7c1eb6     885dfc                           mov    BYTE PTR [ebp-0x4],bl
0x7c1eb9     57                               push   edi
0x7c1eba     b9e8f2c400                       mov    ecx,0xc4f2e8
0x7c1ebf     bafc1dfe00                       mov    edx,0xfe1dfc
0x7c1ec4     e87748f5ff                       call   0x716740
0x7c1ec9     85c0                             test   eax,eax
0x7c1ecb     0f84dc000000                     je     0x7c1fad
0x7c1ed1     8bc6                             mov    eax,esi
0x7c1ed3     c785e4feffff0f000000             mov    DWORD PTR [ebp-0x11c],0xf
0x7c1edd     899de0feffff                     mov    DWORD PTR [ebp-0x120],ebx
0x7c1ee3     889dd0feffff                     mov    BYTE PTR [ebp-0x130],bl
0x7c1ee9     8d5001                           lea    edx,[eax+0x1]
0x7c1eec     8d642400                         lea    esp,[esp+0x0]
0x7c1ef0     8a08                             mov    cl,BYTE PTR [eax]
0x7c1ef2     40                               inc    eax
0x7c1ef3     3acb                             cmp    cl,bl
0x7c1ef5     75f9                             jne    0x7c1ef0
0x7c1ef7     2bc2                             sub    eax,edx
0x7c1ef9     50                               push   eax
0x7c1efa     56                               push   esi
0x7c1efb     8d8dd0feffff                     lea    ecx,[ebp-0x130]
0x7c1f01     e86a0bc4ff                       call   0x402a70
0x7c1f06     6a04                             push   0x4
0x7c1f08     6834fdc400                       push   0xc4fd34
0x7c1f0d     8d8dd0feffff                     lea    ecx,[ebp-0x130]
0x7c1f13     c645fc02                         mov    BYTE PTR [ebp-0x4],0x2
0x7c1f17     e8a400c4ff                       call   0x401fc0
0x7c1f1c     8b85d0feffff                     mov    eax,DWORD PTR [ebp-0x130]
0x7c1f22     bf10000000                       mov    edi,0x10
0x7c1f27     39bde4feffff                     cmp    DWORD PTR [ebp-0x11c],edi
0x7c1f2d     7306                             jae    0x7c1f35
0x7c1f2f     8d85d0feffff                     lea    eax,[ebp-0x130]
0x7c1f35     50                               push   eax
0x7c1f36     683cfdc400                       push   0xc4fd3c
0x7c1f3b     e87d110d00                       call   0x8930bd
0x7c1f40     6a30                             push   0x30
0x7c1f42     e821f30c00                       call   0x891268
0x7c1f47     83c40c                           add    esp,0xc
0x7c1f4a     8985b0feffff                     mov    DWORD PTR [ebp-0x150],eax
0x7c1f50     c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x7c1f54     3bc3                             cmp    eax,ebx
0x7c1f56     741e                             je     0x7c1f76
0x7c1f58     39bde4feffff                     cmp    DWORD PTR [ebp-0x11c],edi
0x7c1f5e     8bbdd0feffff                     mov    edi,DWORD PTR [ebp-0x130]
0x7c1f64     7306                             jae    0x7c1f6c
0x7c1f66     8dbdd0feffff                     lea    edi,[ebp-0x130]
0x7c1f6c     50                               push   eax
0x7c1f6d     e87e800200                       call   0x7e9ff0
0x7c1f72     8bf8                             mov    edi,eax
0x7c1f74     eb02                             jmp    0x7c1f78
0x7c1f76     33ff                             xor    edi,edi
0x7c1f78     885dfc                           mov    BYTE PTR [ebp-0x4],bl
0x7c1f7b     83bde4feffff10                   cmp    DWORD PTR [ebp-0x11c],0x10
0x7c1f82     720f                             jb     0x7c1f93
0x7c1f84     8b85d0feffff                     mov    eax,DWORD PTR [ebp-0x130]
0x7c1f8a     50                               push   eax
0x7c1f8b     e87cf20c00                       call   0x89120c
0x7c1f90     83c404                           add    esp,0x4
0x7c1f93     c785e4feffff0f000000             mov    DWORD PTR [ebp-0x11c],0xf
0x7c1f9d     899de0feffff                     mov    DWORD PTR [ebp-0x120],ebx
0x7c1fa3     889dd0feffff                     mov    BYTE PTR [ebp-0x130],bl
0x7c1fa9     3bfb                             cmp    edi,ebx
0x7c1fab     750f                             jne    0x7c1fbc
0x7c1fad     685cfdc400                       push   0xc4fd5c
0x7c1fb2     e806110d00                       call   0x8930bd
0x7c1fb7     83c404                           add    esp,0x4
0x7c1fba     eb66                             jmp    0x7c2022
0x7c1fbc     a138a8fb00                       mov    eax,ds:0xfba838
0x7c1fc1     83c020                           add    eax,0x20
0x7c1fc4     83781410                         cmp    DWORD PTR [eax+0x14],0x10
0x7c1fc8     7202                             jb     0x7c1fcc
0x7c1fca     8b00                             mov    eax,DWORD PTR [eax]
0x7c1fcc     53                               push   ebx
0x7c1fcd     8d95ecfeffff                     lea    edx,[ebp-0x114]
0x7c1fd3     52                               push   edx
0x7c1fd4     53                               push   ebx
0x7c1fd5     53                               push   ebx
0x7c1fd6     50                               push   eax
0x7c1fd7     e860990d00                       call   0x89b93c
0x7c1fdc     8d85ecfeffff                     lea    eax,[ebp-0x114]
0x7c1fe2     56                               push   esi
0x7c1fe3     50                               push   eax
0x7c1fe4     e8c81c0d00                       call   0x893cb1
0x7c1fe9     83c41c                           add    esp,0x1c
0x7c1fec     85c0                             test   eax,eax
0x7c1fee     751f                             jne    0x7c200f
0x7c1ff0     687cfdc400                       push   0xc4fd7c
0x7c1ff5     e8c3100d00                       call   0x8930bd
0x7c1ffa     83c404                           add    esp,0x4
0x7c1ffd     395d08                           cmp    DWORD PTR [ebp+0x8],ebx
0x7c2000     7453                             je     0x7c2055
0x7c2002     689cfdc400                       push   0xc4fd9c
0x7c2007     e8b1100d00                       call   0x8930bd
0x7c200c     83c404                           add    esp,0x4
0x7c200f     8b17                             mov    edx,DWORD PTR [edi]
0x7c2011     8b4204                           mov    eax,DWORD PTR [edx+0x4]
0x7c2014     8bcf                             mov    ecx,edi
0x7c2016     ffd0                             call   eax
0x7c2018     8b17                             mov    edx,DWORD PTR [edi]
0x7c201a     8b02                             mov    eax,DWORD PTR [edx]
0x7c201c     6a01                             push   0x1
0x7c201e     8bcf                             mov    ecx,edi
0x7c2020     ffd0                             call   eax
0x7c2022     83bdc8feffff10                   cmp    DWORD PTR [ebp-0x138],0x10
0x7c2029     720f                             jb     0x7c203a
0x7c202b     8b8db4feffff                     mov    ecx,DWORD PTR [ebp-0x14c]
0x7c2031     51                               push   ecx
0x7c2032     e8d5f10c00                       call   0x89120c
0x7c2037     83c404                           add    esp,0x4
0x7c203a     8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x7c203d     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x7c2044     59                               pop    ecx
0x7c2045     5f                               pop    edi
0x7c2046     5b                               pop    ebx
0x7c2047     8b4df0                           mov    ecx,DWORD PTR [ebp-0x10]
0x7c204a     33cd                             xor    ecx,ebp
0x7c204c     e8b0ef0c00                       call   0x891001
0x7c2051     8be5                             mov    esp,ebp
0x7c2053     5d                               pop    ebp
0x7c2054     c3                               ret
0x7c2055     68b0fdc400                       push   0xc4fdb0
0x7c205a     e85e100d00                       call   0x8930bd
0x7c205f     83c404                           add    esp,0x4
0x7c2062     ebb4                             jmp    0x7c2018

; local_world_create 0x4a0f70..0x4a1230 raw=0xa0370 SHA256=19f1361623fcbd9d251539c9224d44fe10f5f6995b525a8748ac7c3909848d5e
0x4a0f70     55                               push   ebp
0x4a0f71     8bec                             mov    ebp,esp
0x4a0f73     83e4f8                           and    esp,0xfffffff8
0x4a0f76     6aff                             push   0xffffffff
0x4a0f78     686b9f9300                       push   0x939f6b
0x4a0f7d     64a100000000                     mov    eax,fs:0x0
0x4a0f83     50                               push   eax
0x4a0f84     83ec18                           sub    esp,0x18
0x4a0f87     53                               push   ebx
0x4a0f88     56                               push   esi
0x4a0f89     57                               push   edi
0x4a0f8a     a1201fd600                       mov    eax,ds:0xd61f20
0x4a0f8f     33c4                             xor    eax,esp
0x4a0f91     50                               push   eax
0x4a0f92     8d442428                         lea    eax,[esp+0x28]
0x4a0f96     64a300000000                     mov    fs:0x0,eax
0x4a0f9c     8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x4a0f9f     33f6                             xor    esi,esi
0x4a0fa1     33db                             xor    ebx,ebx
0x4a0fa3     83ff0a                           cmp    edi,0xa
0x4a0fa6     7c10                             jl     0x4a0fb8
0x4a0fa8     81ff10270000                     cmp    edi,0x2710
0x4a0fae     0f9ec3                           setle  bl
0x4a0fb1     4b                               dec    ebx
0x4a0fb2     83e305                           and    ebx,0x5
0x4a0fb5     43                               inc    ebx
0x4a0fb6     7527                             jne    0x4a0fdf
0x4a0fb8     6844040000                       push   0x444
0x4a0fbd     e8a6023f00                       call   0x891268
0x4a0fc2     83c404                           add    esp,0x4
0x4a0fc5     89442414                         mov    DWORD PTR [esp+0x14],eax
0x4a0fc9     c744243000000000                 mov    DWORD PTR [esp+0x30],0x0
0x4a0fd1     85c0                             test   eax,eax
0x4a0fd3     746e                             je     0x4a1043
0x4a0fd5     6a00                             push   0x0
0x4a0fd7     50                               push   eax
0x4a0fd8     e813c70200                       call   0x4cd6f0
0x4a0fdd     eb66                             jmp    0x4a1045
0x4a0fdf     83fb01                           cmp    ebx,0x1
0x4a0fe2     7535                             jne    0x4a1019
0x4a0fe4     6834040000                       push   0x434
0x4a0fe9     e87a023f00                       call   0x891268
0x4a0fee     83c404                           add    esp,0x4
0x4a0ff1     89442414                         mov    DWORD PTR [esp+0x14],eax
0x4a0ff5     895c2430                         mov    DWORD PTR [esp+0x30],ebx
0x4a0ff9     85c0                             test   eax,eax
0x4a0ffb     7408                             je     0x4a1005
0x4a0ffd     50                               push   eax
0x4a0ffe     e80d070300                       call   0x4d1710
0x4a1003     eb02                             jmp    0x4a1007
0x4a1005     33c0                             xor    eax,eax
0x4a1007     57                               push   edi
0x4a1008     c7442434ffffffff                 mov    DWORD PTR [esp+0x34],0xffffffff
0x4a1010     8bf0                             mov    esi,eax
0x4a1012     e8b9fdffff                       call   0x4a0dd0
0x4a1017     eb36                             jmp    0x4a104f
0x4a1019     83fb06                           cmp    ebx,0x6
0x4a101c     7531                             jne    0x4a104f
0x4a101e     682c040000                       push   0x42c
0x4a1023     e840023f00                       call   0x891268
0x4a1028     83c404                           add    esp,0x4
0x4a102b     89442414                         mov    DWORD PTR [esp+0x14],eax
0x4a102f     c744243002000000                 mov    DWORD PTR [esp+0x30],0x2
0x4a1037     85c0                             test   eax,eax
0x4a1039     7408                             je     0x4a1043
0x4a103b     50                               push   eax
0x4a103c     e8df100300                       call   0x4d2120
0x4a1041     eb02                             jmp    0x4a1045
0x4a1043     33c0                             xor    eax,eax
0x4a1045     8bf0                             mov    esi,eax
0x4a1047     c7442430ffffffff                 mov    DWORD PTR [esp+0x30],0xffffffff
0x4a104f     66a104def700                     mov    ax,ds:0xf7de04
0x4a1055     f30f10450c                       movss  xmm0,DWORD PTR [ebp+0xc]
0x4a105a     8b16                             mov    edx,DWORD PTR [esi]
0x4a105c     8b5244                           mov    edx,DWORD PTR [edx+0x44]
0x4a105f     66894604                         mov    WORD PTR [esi+0x4],ax
0x4a1063     6a01                             push   0x1
0x4a1065     8d442418                         lea    eax,[esp+0x18]
0x4a1069     f30f11442418                     movss  DWORD PTR [esp+0x18],xmm0
0x4a106f     f30f104510                       movss  xmm0,DWORD PTR [ebp+0x10]
0x4a1074     50                               push   eax
0x4a1075     8bce                             mov    ecx,esi
0x4a1077     f30f11442420                     movss  DWORD PTR [esp+0x20],xmm0
0x4a107d     ffd2                             call   edx
0x4a107f     8b4d18                           mov    ecx,DWORD PTR [ebp+0x18]
0x4a1082     8b06                             mov    eax,DWORD PTR [esi]
0x4a1084     8b5058                           mov    edx,DWORD PTR [eax+0x58]
0x4a1087     51                               push   ecx
0x4a1088     8bce                             mov    ecx,esi
0x4a108a     ffd2                             call   edx
0x4a108c     8b06                             mov    eax,DWORD PTR [esi]
0x4a108e     8b403c                           mov    eax,DWORD PTR [eax+0x3c]
0x4a1091     0fb6cb                           movzx  ecx,bl
0x4a1094     0fb7d7                           movzx  edx,di
0x4a1097     c1e118                           shl    ecx,0x18
0x4a109a     0bca                             or     ecx,edx
0x4a109c     51                               push   ecx
0x4a109d     8bce                             mov    ecx,esi
0x4a109f     ffd0                             call   eax
0x4a10a1     83ff0a                           cmp    edi,0xa
0x4a10a4     bf01000000                       mov    edi,0x1
0x4a10a9     7d24                             jge    0x4a10cf
0x4a10ab     8b865c010000                     mov    eax,DWORD PTR [esi+0x15c]
0x4a10b1     8bcf                             mov    ecx,edi
0x4a10b3     66898e88030000                   mov    WORD PTR [esi+0x388],cx
0x4a10ba     85c0                             test   eax,eax
0x4a10bc     7411                             je     0x4a10cf
0x4a10be     83be7003000000                   cmp    DWORD PTR [esi+0x370],0x0
0x4a10c5     7408                             je     0x4a10cf
0x4a10c7     57                               push   edi
0x4a10c8     57                               push   edi
0x4a10c9     50                               push   eax
0x4a10ca     e8d15d3000                       call   0x7a6ea0
0x4a10cf     8b16                             mov    edx,DWORD PTR [esi]
0x4a10d1     8b4230                           mov    eax,DWORD PTR [edx+0x30]
0x4a10d4     8bce                             mov    ecx,esi
0x4a10d6     ffd0                             call   eax
0x4a10d8     f6052888fb0001                   test   BYTE PTR ds:0xfb8828,0x1
0x4a10df     7528                             jne    0x4a1109
0x4a10e1     093d2888fb00                     or     DWORD PTR ds:0xfb8828,edi
0x4a10e7     c744243003000000                 mov    DWORD PTR [esp+0x30],0x3
0x4a10ef     e85ce70a00                       call   0x54f850
0x4a10f4     6880d5bc00                       push   0xbcd580
0x4a10f9     e81c123f00                       call   0x89231a
0x4a10fe     83c404                           add    esp,0x4
0x4a1101     c7442430ffffffff                 mov    DWORD PTR [esp+0x30],0xffffffff
0x4a1109     db4514                           fild   DWORD PTR [ebp+0x14]
0x4a110c     8b16                             mov    edx,DWORD PTR [esi]
0x4a110e     8b425c                           mov    eax,DWORD PTR [edx+0x5c]
0x4a1111     51                               push   ecx
0x4a1112     d80dbc90fb00                     fmul   DWORD PTR ds:0xfb90bc
0x4a1118     8bce                             mov    ecx,esi
0x4a111a     d95c2418                         fstp   DWORD PTR [esp+0x18]
0x4a111e     d9442418                         fld    DWORD PTR [esp+0x18]
0x4a1122     d91c24                           fstp   DWORD PTR [esp]
0x4a1125     ffd0                             call   eax
0x4a1127     f30f10450c                       movss  xmm0,DWORD PTR [ebp+0xc]
0x4a112c     8b16                             mov    edx,DWORD PTR [esi]
0x4a112e     8b5244                           mov    edx,DWORD PTR [edx+0x44]
0x4a1131     57                               push   edi
0x4a1132     8d442420                         lea    eax,[esp+0x20]
0x4a1136     f30f11442420                     movss  DWORD PTR [esp+0x20],xmm0
0x4a113c     f30f104510                       movss  xmm0,DWORD PTR [ebp+0x10]
0x4a1141     50                               push   eax
0x4a1142     8bce                             mov    ecx,esi
0x4a1144     f30f11442428                     movss  DWORD PTR [esp+0x28],xmm0
0x4a114a     ffd2                             call   edx
0x4a114c     8b86f0000000                     mov    eax,DWORD PTR [esi+0xf0]
0x4a1152     8b5008                           mov    edx,DWORD PTR [eax+0x8]
0x4a1155     8d8ef0000000                     lea    ecx,[esi+0xf0]
0x4a115b     57                               push   edi
0x4a115c     ffd2                             call   edx
0x4a115e     d9e8                             fld1
0x4a1160     8b06                             mov    eax,DWORD PTR [esi]
0x4a1162     8b5068                           mov    edx,DWORD PTR [eax+0x68]
0x4a1165     51                               push   ecx
0x4a1166     d91c24                           fstp   DWORD PTR [esp]
0x4a1169     57                               push   edi
0x4a116a     8bce                             mov    ecx,esi
0x4a116c     ffd2                             call   edx
0x4a116e     f6052cb2fa0001                   test   BYTE PTR ds:0xfab22c,0x1
0x4a1175     f30f1005b45ac500                 movss  xmm0,DWORD PTR ds:0xc55ab4
0x4a117d     f30f1186cc000000                 movss  DWORD PTR [esi+0xcc],xmm0
0x4a1185     7528                             jne    0x4a11af
0x4a1187     093d2cb2fa00                     or     DWORD PTR ds:0xfab22c,edi
0x4a118d     c744243004000000                 mov    DWORD PTR [esp+0x30],0x4
0x4a1195     e8f6da0300                       call   0x4dec90
0x4a119a     6830cebc00                       push   0xbcce30
0x4a119f     e876113f00                       call   0x89231a
0x4a11a4     83c404                           add    esp,0x4
0x4a11a7     c7442430ffffffff                 mov    DWORD PTR [esp+0x30],0xffffffff
0x4a11af     6830b1fa00                       push   0xfab130
0x4a11b4     8bc6                             mov    eax,esi
0x4a11b6     e875ed0300                       call   0x4dff30
0x4a11bb     013d04def700                     add    DWORD PTR ds:0xf7de04,edi
0x4a11c1     837d1c00                         cmp    DWORD PTR [ebp+0x1c],0x0
0x4a11c5     7451                             je     0x4a1218
0x4a11c7     8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4a11cd     8b01                             mov    eax,DWORD PTR [ecx]
0x4a11cf     8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x4a11d2     56                               push   esi
0x4a11d3     897904                           mov    DWORD PTR [ecx+0x4],edi
0x4a11d6     ffd2                             call   edx
0x4a11d8     8b0da4a7fb00                     mov    ecx,DWORD PTR ds:0xfba7a4
0x4a11de     8b01                             mov    eax,DWORD PTR [ecx]
0x4a11e0     8b5010                           mov    edx,DWORD PTR [eax+0x10]
0x4a11e3     ffd2                             call   edx
0x4a11e5     f605147cfb0001                   test   BYTE PTR ds:0xfb7c14,0x1
0x4a11ec     7520                             jne    0x4a120e
0x4a11ee     093d147cfb00                     or     DWORD PTR ds:0xfb7c14,edi
0x4a11f4     c744243005000000                 mov    DWORD PTR [esp+0x30],0x5
0x4a11fc     e84ff52200                       call   0x6d0750
0x4a1201     6830d5bc00                       push   0xbcd530
0x4a1206     e80f113f00                       call   0x89231a
0x4a120b     83c404                           add    esp,0x4
0x4a120e     c7053088fb0000000000             mov    DWORD PTR ds:0xfb8830,0x0
0x4a1218     8b4c2428                         mov    ecx,DWORD PTR [esp+0x28]
0x4a121c     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4a1223     59                               pop    ecx
0x4a1224     5f                               pop    edi
0x4a1225     5e                               pop    esi
0x4a1226     5b                               pop    ebx
0x4a1227     8be5                             mov    esp,ebp
0x4a1229     5d                               pop    ebp
0x4a122a     c21800                           ret    0x18
0x4a122d     cc                               int3
0x4a122e     cc                               int3
0x4a122f     cc                               int3

; client_loading_begin 0x494860..0x494a82 raw=0x93c60 SHA256=ac163a4174d54fdae80f9b16ed1e32e47fba6d59a4facf0fd77cea6fb8fc586b
0x494860     55                               push   ebp
0x494861     8bec                             mov    ebp,esp
0x494863     6aff                             push   0xffffffff
0x494865     684a119300                       push   0x93114a
0x49486a     64a100000000                     mov    eax,fs:0x0
0x494870     50                               push   eax
0x494871     53                               push   ebx
0x494872     56                               push   esi
0x494873     57                               push   edi
0x494874     a1201fd600                       mov    eax,ds:0xd61f20
0x494879     33c5                             xor    eax,ebp
0x49487b     50                               push   eax
0x49487c     8d45f4                           lea    eax,[ebp-0xc]
0x49487f     64a300000000                     mov    fs:0x0,eax
0x494885     8bf9                             mov    edi,ecx
0x494887     bb01000000                       mov    ebx,0x1
0x49488c     899fd4bf0000                     mov    DWORD PTR [edi+0xbfd4],ebx
0x494892     841dfc18fc00                     test   BYTE PTR ds:0xfc18fc,bl
0x494898     7526                             jne    0x4948c0
0x49489a     091dfc18fc00                     or     DWORD PTR ds:0xfc18fc,ebx
0x4948a0     c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x4948a7     e844000c00                       call   0x5548f0
0x4948ac     68d0dcbc00                       push   0xbcdcd0
0x4948b1     e864da3f00                       call   0x89231a
0x4948b6     83c404                           add    esp,0x4
0x4948b9     c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x4948c0     8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4948c3     0fbf4804                         movsx  ecx,WORD PTR [eax+0x4]
0x4948c7     0fbf5002                         movsx  edx,WORD PTR [eax+0x2]
0x4948cb     51                               push   ecx
0x4948cc     52                               push   edx
0x4948cd     680019fc00                       push   0xfc1900
0x4948d2     e809080c00                       call   0x5550e0
0x4948d7     ff15a025bd00                     call   DWORD PTR ds:0xbd25a0
0x4948dd     8b4708                           mov    eax,DWORD PTR [edi+0x8]
0x4948e0     8b4838                           mov    ecx,DWORD PTR [eax+0x38]
0x4948e3     8d7708                           lea    esi,[edi+0x8]
0x4948e6     56                               push   esi
0x4948e7     ffd1                             call   ecx
0x4948e9     8b4718                           mov    eax,DWORD PTR [edi+0x18]
0x4948ec     8b10                             mov    edx,DWORD PTR [eax]
0x4948ee     6a00                             push   0x0
0x4948f0     6a00                             push   0x0
0x4948f2     6a00                             push   0x0
0x4948f4     6a00                             push   0x0
0x4948f6     50                               push   eax
0x4948f7     8b4244                           mov    eax,DWORD PTR [edx+0x44]
0x4948fa     ffd0                             call   eax
0x4948fc     8b0e                             mov    ecx,DWORD PTR [esi]
0x4948fe     8b5138                           mov    edx,DWORD PTR [ecx+0x38]
0x494901     56                               push   esi
0x494902     ffd2                             call   edx
0x494904     8b7f18                           mov    edi,DWORD PTR [edi+0x18]
0x494907     8b07                             mov    eax,DWORD PTR [edi]
0x494909     8b4844                           mov    ecx,DWORD PTR [eax+0x44]
0x49490c     6a00                             push   0x0
0x49490e     6a00                             push   0x0
0x494910     6a00                             push   0x0
0x494912     6a00                             push   0x0
0x494914     57                               push   edi
0x494915     ffd1                             call   ecx
0x494917     841df02cfd00                     test   BYTE PTR ds:0xfd2cf0,bl
0x49491d     7518                             jne    0x494937
0x49491f     091df02cfd00                     or     DWORD PTR ds:0xfd2cf0,ebx
0x494925     e866372a00                       call   0x738090
0x49492a     6880e6bc00                       push   0xbce680
0x49492f     e8e6d93f00                       call   0x89231a
0x494934     83c404                           add    esp,0x4
0x494937     8b0dd02cfd00                     mov    ecx,DWORD PTR ds:0xfd2cd0
0x49493d     85c9                             test   ecx,ecx
0x49493f     742d                             je     0x49496e
0x494941     841df02cfd00                     test   BYTE PTR ds:0xfd2cf0,bl
0x494947     751e                             jne    0x494967
0x494949     091df02cfd00                     or     DWORD PTR ds:0xfd2cf0,ebx
0x49494f     e83c372a00                       call   0x738090
0x494954     6880e6bc00                       push   0xbce680
0x494959     e8bcd93f00                       call   0x89231a
0x49495e     8b0dd02cfd00                     mov    ecx,DWORD PTR ds:0xfd2cd0
0x494964     83c404                           add    esp,0x4
0x494967     8b11                             mov    edx,DWORD PTR [ecx]
0x494969     8b4208                           mov    eax,DWORD PTR [edx+0x8]
0x49496c     ffd0                             call   eax
0x49496e     e8cdb22400                       call   0x6dfc40
0x494973     8bf0                             mov    esi,eax
0x494975     e8c6b22400                       call   0x6dfc40
0x49497a     8b4818                           mov    ecx,DWORD PTR [eax+0x18]
0x49497d     51                               push   ecx
0x49497e     8b4e1c                           mov    ecx,DWORD PTR [esi+0x1c]
0x494981     e86afe2900                       call   0x7347f0
0x494986     83c404                           add    esp,0x4
0x494989     8bf0                             mov    esi,eax
0x49498b     841df02cfd00                     test   BYTE PTR ds:0xfd2cf0,bl
0x494991     7518                             jne    0x4949ab
0x494993     091df02cfd00                     or     DWORD PTR ds:0xfd2cf0,ebx
0x494999     e8f2362a00                       call   0x738090
0x49499e     6880e6bc00                       push   0xbce680
0x4949a3     e872d93f00                       call   0x89231a
0x4949a8     83c404                           add    esp,0x4
0x4949ab     8935d02cfd00                     mov    DWORD PTR ds:0xfd2cd0,esi
0x4949b1     85f6                             test   esi,esi
0x4949b3     7406                             je     0x4949bb
0x4949b5     891dd42cfd00                     mov    DWORD PTR ds:0xfd2cd4,ebx
0x4949bb     8b15e02cfd00                     mov    edx,DWORD PTR ds:0xfd2ce0
0x4949c1     a1e42cfd00                       mov    eax,ds:0xfd2ce4
0x4949c6     8915d82cfd00                     mov    DWORD PTR ds:0xfd2cd8,edx
0x4949cc     a3dc2cfd00                       mov    ds:0xfd2cdc,eax
0x4949d1     841df02cfd00                     test   BYTE PTR ds:0xfd2cf0,bl
0x4949d7     7518                             jne    0x4949f1
0x4949d9     091df02cfd00                     or     DWORD PTR ds:0xfd2cf0,ebx
0x4949df     e8ac362a00                       call   0x738090
0x4949e4     6880e6bc00                       push   0xbce680
0x4949e9     e82cd93f00                       call   0x89231a
0x4949ee     83c404                           add    esp,0x4
0x4949f1     891dec2cfd00                     mov    DWORD PTR ds:0xfd2cec,ebx
0x4949f7     ff15a025bd00                     call   DWORD PTR ds:0xbd25a0
0x4949fd     841dc00ffc00                     test   BYTE PTR ds:0xfc0fc0,bl
0x494a03     7522                             jne    0x494a27
0x494a05     091dc00ffc00                     or     DWORD PTR ds:0xfc0fc0,ebx
0x494a0b     895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x494a0e     e83d442400                       call   0x6d8e50
0x494a13     68b0dbbc00                       push   0xbcdbb0
0x494a18     e8fdd83f00                       call   0x89231a
0x494a1d     83c404                           add    esp,0x4
0x494a20     c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x494a27     bec80ffc00                       mov    esi,0xfc0fc8
0x494a2c     e84f4c2400                       call   0x6d9680
0x494a31     841dc00ffc00                     test   BYTE PTR ds:0xfc0fc0,bl
0x494a37     7526                             jne    0x494a5f
0x494a39     091dc00ffc00                     or     DWORD PTR ds:0xfc0fc0,ebx
0x494a3f     c745fc02000000                   mov    DWORD PTR [ebp-0x4],0x2
0x494a46     e805442400                       call   0x6d8e50
0x494a4b     68b0dbbc00                       push   0xbcdbb0
0x494a50     e8c5d83f00                       call   0x89231a
0x494a55     83c404                           add    esp,0x4
0x494a58     c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x494a5f     b9c80ffc00                       mov    ecx,0xfc0fc8
0x494a64     e8174d2400                       call   0x6d9780
0x494a69     b800010000                       mov    eax,0x100
0x494a6e     8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x494a71     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x494a78     59                               pop    ecx
0x494a79     5f                               pop    edi
0x494a7a     5e                               pop    esi
0x494a7b     5b                               pop    ebx
0x494a7c     8be5                             mov    esp,ebp
0x494a7e     5d                               pop    ebp
0x494a7f     c20c00                           ret    0xc

; client_loading_end 0x494a90..0x494c39 raw=0x93e90 SHA256=8a58a70ea2b9dceada8bb7b68044e52fc1e47213d8a63c59af73fdbbede5caf0
0x494a90     55                               push   ebp
0x494a91     8bec                             mov    ebp,esp
0x494a93     83e4f8                           and    esp,0xfffffff8
0x494a96     6aff                             push   0xffffffff
0x494a98     68f8709300                       push   0x9370f8
0x494a9d     64a100000000                     mov    eax,fs:0x0
0x494aa3     50                               push   eax
0x494aa4     83ec08                           sub    esp,0x8
0x494aa7     53                               push   ebx
0x494aa8     56                               push   esi
0x494aa9     57                               push   edi
0x494aaa     a1201fd600                       mov    eax,ds:0xd61f20
0x494aaf     33c4                             xor    eax,esp
0x494ab1     50                               push   eax
0x494ab2     8d442418                         lea    eax,[esp+0x18]
0x494ab6     64a300000000                     mov    fs:0x0,eax
0x494abc     894c2410                         mov    DWORD PTR [esp+0x10],ecx
0x494ac0     f605f02cfd0001                   test   BYTE PTR ds:0xfd2cf0,0x1
0x494ac7     be01000000                       mov    esi,0x1
0x494acc     7518                             jne    0x494ae6
0x494ace     0935f02cfd00                     or     DWORD PTR ds:0xfd2cf0,esi
0x494ad4     e8b7352a00                       call   0x738090
0x494ad9     6880e6bc00                       push   0xbce680
0x494ade     e837d83f00                       call   0x89231a
0x494ae3     83c404                           add    esp,0x4
0x494ae6     33db                             xor    ebx,ebx
0x494ae8     f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
0x494aef     891dec2cfd00                     mov    DWORD PTR ds:0xfd2cec,ebx
0x494af5     7525                             jne    0x494b1c
0x494af7     0935e879fb00                     or     DWORD PTR ds:0xfb79e8,esi
0x494afd     895c2420                         mov    DWORD PTR [esp+0x20],ebx
0x494b01     e8da423000                       call   0x798de0
0x494b06     68e0d2bc00                       push   0xbcd2e0
0x494b0b     e80ad83f00                       call   0x89231a
0x494b10     83c404                           add    esp,0x4
0x494b13     83cfff                           or     edi,0xffffffff
0x494b16     897c2420                         mov    DWORD PTR [esp+0x20],edi
0x494b1a     eb03                             jmp    0x494b1f
0x494b1c     83cfff                           or     edi,0xffffffff
0x494b1f     8b0de876fb00                     mov    ecx,DWORD PTR ds:0xfb76e8
0x494b25     3bcb                             cmp    ecx,ebx
0x494b27     7471                             je     0x494b9a
0x494b29     f605e879fb0001                   test   BYTE PTR ds:0xfb79e8,0x1
0x494b30     7526                             jne    0x494b58
0x494b32     0935e879fb00                     or     DWORD PTR ds:0xfb79e8,esi
0x494b38     89742420                         mov    DWORD PTR [esp+0x20],esi
0x494b3c     e89f423000                       call   0x798de0
0x494b41     68e0d2bc00                       push   0xbcd2e0
0x494b46     e8cfd73f00                       call   0x89231a
0x494b4b     897c2424                         mov    DWORD PTR [esp+0x24],edi
0x494b4f     8b0de876fb00                     mov    ecx,DWORD PTR ds:0xfb76e8
0x494b55     83c404                           add    esp,0x4
0x494b58     8b81a4000000                     mov    eax,DWORD PTR [ecx+0xa4]
0x494b5e     8db1a4000000                     lea    esi,[ecx+0xa4]
0x494b64     8b89a0000000                     mov    ecx,DWORD PTR [ecx+0xa0]
0x494b6a     3bc8                             cmp    ecx,eax
0x494b6c     7427                             je     0x494b95
0x494b6e     8b542410                         mov    edx,DWORD PTR [esp+0x10]
0x494b72     52                               push   edx
0x494b73     51                               push   ecx
0x494b74     50                               push   eax
0x494b75     50                               push   eax
0x494b76     e835403000                       call   0x798bb0
0x494b7b     8b3e                             mov    edi,DWORD PTR [esi]
0x494b7d     8bd8                             mov    ebx,eax
0x494b7f     8b442420                         mov    eax,DWORD PTR [esp+0x20]
0x494b83     50                               push   eax
0x494b84     8bc3                             mov    eax,ebx
0x494b86     e875403000                       call   0x798c00
0x494b8b     83c414                           add    esp,0x14
0x494b8e     891e                             mov    DWORD PTR [esi],ebx
0x494b90     83cfff                           or     edi,0xffffffff
0x494b93     33db                             xor    ebx,ebx
0x494b95     be01000000                       mov    esi,0x1
0x494b9a     f605fc18fc0001                   test   BYTE PTR ds:0xfc18fc,0x1
0x494ba1     7524                             jne    0x494bc7
0x494ba3     0935fc18fc00                     or     DWORD PTR ds:0xfc18fc,esi
0x494ba9     c744242002000000                 mov    DWORD PTR [esp+0x20],0x2
0x494bb1     e83afd0b00                       call   0x5548f0
0x494bb6     68d0dcbc00                       push   0xbcdcd0
0x494bbb     e85ad73f00                       call   0x89231a
0x494bc0     83c404                           add    esp,0x4
0x494bc3     897c2420                         mov    DWORD PTR [esp+0x20],edi
0x494bc7     391d8419fc00                     cmp    DWORD PTR ds:0xfc1984,ebx
0x494bcd     740f                             je     0x494bde
0x494bcf     be0019fc00                       mov    esi,0xfc1900
0x494bd4     e8e70c0c00                       call   0x5558c0
0x494bd9     be01000000                       mov    esi,0x1
0x494bde     8b4c2410                         mov    ecx,DWORD PTR [esp+0x10]
0x494be2     8999d4bf0000                     mov    DWORD PTR [ecx+0xbfd4],ebx
0x494be8     e833a42400                       call   0x6df020
0x494bed     f6052cb2fa0001                   test   BYTE PTR ds:0xfab22c,0x1
0x494bf4     7524                             jne    0x494c1a
0x494bf6     09352cb2fa00                     or     DWORD PTR ds:0xfab22c,esi
0x494bfc     c744242003000000                 mov    DWORD PTR [esp+0x20],0x3
0x494c04     e887a00400                       call   0x4dec90
0x494c09     6830cebc00                       push   0xbcce30
0x494c0e     e807d73f00                       call   0x89231a
0x494c13     83c404                           add    esp,0x4
0x494c16     897c2420                         mov    DWORD PTR [esp+0x20],edi
0x494c1a     e871b90400                       call   0x4e0590
0x494c1f     b800010000                       mov    eax,0x100
0x494c24     8b4c2418                         mov    ecx,DWORD PTR [esp+0x18]
0x494c28     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x494c2f     59                               pop    ecx
0x494c30     5f                               pop    edi
0x494c31     5e                               pop    esi
0x494c32     5b                               pop    ebx
0x494c33     8be5                             mov    esp,ebp
0x494c35     5d                               pop    ebp
0x494c36     c20c00                           ret    0xc

; tutorial_delete_object 0x4a9fe0..0x4aa06e raw=0xa93e0 SHA256=6cd9ae43af722042847b8a9c5f9972beac001a57c103cffbf2e67263c2c083c7
0x4a9fe0     55                               push   ebp
0x4a9fe1     8bec                             mov    ebp,esp
0x4a9fe3     83e4f8                           and    esp,0xfffffff8
0x4a9fe6     6aff                             push   0xffffffff
0x4a9fe8     68fe6e9300                       push   0x936efe
0x4a9fed     64a100000000                     mov    eax,fs:0x0
0x4a9ff3     50                               push   eax
0x4a9ff4     83ec0c                           sub    esp,0xc
0x4a9ff7     a1201fd600                       mov    eax,ds:0xd61f20
0x4a9ffc     33c4                             xor    eax,esp
0x4a9ffe     50                               push   eax
0x4a9fff     8d442410                         lea    eax,[esp+0x10]
0x4aa003     64a300000000                     mov    fs:0x0,eax
0x4aa009     8a4d08                           mov    cl,BYTE PTR [ebp+0x8]
0x4aa00c     33c0                             xor    eax,eax
0x4aa00e     6689442408                       mov    WORD PTR [esp+0x8],ax
0x4aa013     884c2409                         mov    BYTE PTR [esp+0x9],cl
0x4aa017     b901000000                       mov    ecx,0x1
0x4aa01c     88442408                         mov    BYTE PTR [esp+0x8],al
0x4aa020     840d2cb2fa00                     test   BYTE PTR ds:0xfab22c,cl
0x4aa026     7524                             jne    0x4aa04c
0x4aa028     090d2cb2fa00                     or     DWORD PTR ds:0xfab22c,ecx
0x4aa02e     89442418                         mov    DWORD PTR [esp+0x18],eax
0x4aa032     e8594c0300                       call   0x4dec90
0x4aa037     6830cebc00                       push   0xbcce30
0x4aa03c     e8d9823e00                       call   0x89231a
0x4aa041     83c404                           add    esp,0x4
0x4aa044     c7442418ffffffff                 mov    DWORD PTR [esp+0x18],0xffffffff
0x4aa04c     0fb7542408                       movzx  edx,WORD PTR [esp+0x8]
0x4aa051     52                               push   edx
0x4aa052     b830b1fa00                       mov    eax,0xfab130
0x4aa057     e8645b0300                       call   0x4dfbc0
0x4aa05c     8b4c2410                         mov    ecx,DWORD PTR [esp+0x10]
0x4aa060     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4aa067     59                               pop    ecx
0x4aa068     8be5                             mov    esp,ebp
0x4aa06a     5d                               pop    ebp
0x4aa06b     c20400                           ret    0x4

; world_avatar_api 0x4a0b80..0x4a0dd0 raw=0x9ff80 SHA256=6cb531ccc18a941ec688a5bba0d6f6ceb63681fffc724c6096370f055b9ad7c5
0x4a0b80     55                               push   ebp
0x4a0b81     8bec                             mov    ebp,esp
0x4a0b83     83e4f8                           and    esp,0xfffffff8
0x4a0b86     6aff                             push   0xffffffff
0x4a0b88     68fe6e9300                       push   0x936efe
0x4a0b8d     64a100000000                     mov    eax,fs:0x0
0x4a0b93     50                               push   eax
0x4a0b94     83ec0c                           sub    esp,0xc
0x4a0b97     a1201fd600                       mov    eax,ds:0xd61f20
0x4a0b9c     33c4                             xor    eax,esp
0x4a0b9e     50                               push   eax
0x4a0b9f     8d442410                         lea    eax,[esp+0x10]
0x4a0ba3     64a300000000                     mov    fs:0x0,eax
0x4a0ba9     b801000000                       mov    eax,0x1
0x4a0bae     84052cb2fa00                     test   BYTE PTR ds:0xfab22c,al
0x4a0bb4     7528                             jne    0x4a0bde
0x4a0bb6     09052cb2fa00                     or     DWORD PTR ds:0xfab22c,eax
0x4a0bbc     c744241800000000                 mov    DWORD PTR [esp+0x18],0x0
0x4a0bc4     e8c7e00300                       call   0x4dec90
0x4a0bc9     6830cebc00                       push   0xbcce30
0x4a0bce     e847173f00                       call   0x89231a
0x4a0bd3     83c404                           add    esp,0x4
0x4a0bd6     c7442418ffffffff                 mov    DWORD PTR [esp+0x18],0xffffffff
0x4a0bde     8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a0be1     8d4c2404                         lea    ecx,[esp+0x4]
0x4a0be5     89442404                         mov    DWORD PTR [esp+0x4],eax
0x4a0be9     51                               push   ecx
0x4a0bea     8d44240c                         lea    eax,[esp+0xc]
0x4a0bee     b938b1fa00                       mov    ecx,0xfab138
0x4a0bf3     e808e33800                       call   0x82ef00
0x4a0bf8     8b442408                         mov    eax,DWORD PTR [esp+0x8]
0x4a0bfc     3b053cb1fa00                     cmp    eax,DWORD PTR ds:0xfab13c
0x4a0c02     742f                             je     0x4a0c33
0x4a0c04     8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x4a0c07     85c0                             test   eax,eax
0x4a0c09     7428                             je     0x4a0c33
0x4a0c0b     8b885c010000                     mov    ecx,DWORD PTR [eax+0x15c]
0x4a0c11     8b5510                           mov    edx,DWORD PTR [ebp+0x10]
0x4a0c14     66899088030000                   mov    WORD PTR [eax+0x388],dx
0x4a0c1b     85c9                             test   ecx,ecx
0x4a0c1d     7414                             je     0x4a0c33
0x4a0c1f     83b87003000000                   cmp    DWORD PTR [eax+0x370],0x0
0x4a0c26     740b                             je     0x4a0c33
0x4a0c28     52                               push   edx
0x4a0c29     8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0x4a0c2c     52                               push   edx
0x4a0c2d     51                               push   ecx
0x4a0c2e     e86d623000                       call   0x7a6ea0
0x4a0c33     8b4c2410                         mov    ecx,DWORD PTR [esp+0x10]
0x4a0c37     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4a0c3e     59                               pop    ecx
0x4a0c3f     8be5                             mov    esp,ebp
0x4a0c41     5d                               pop    ebp
0x4a0c42     c20c00                           ret    0xc
0x4a0c45     cc                               int3
0x4a0c46     cc                               int3
0x4a0c47     cc                               int3
0x4a0c48     cc                               int3
0x4a0c49     cc                               int3
0x4a0c4a     cc                               int3
0x4a0c4b     cc                               int3
0x4a0c4c     cc                               int3
0x4a0c4d     cc                               int3
0x4a0c4e     cc                               int3
0x4a0c4f     cc                               int3
0x4a0c50     55                               push   ebp
0x4a0c51     8bec                             mov    ebp,esp
0x4a0c53     83e4f8                           and    esp,0xfffffff8
0x4a0c56     6aff                             push   0xffffffff
0x4a0c58     68fe6e9300                       push   0x936efe
0x4a0c5d     64a100000000                     mov    eax,fs:0x0
0x4a0c63     50                               push   eax
0x4a0c64     83ec0c                           sub    esp,0xc
0x4a0c67     a1201fd600                       mov    eax,ds:0xd61f20
0x4a0c6c     33c4                             xor    eax,esp
0x4a0c6e     50                               push   eax
0x4a0c6f     8d442410                         lea    eax,[esp+0x10]
0x4a0c73     64a300000000                     mov    fs:0x0,eax
0x4a0c79     b801000000                       mov    eax,0x1
0x4a0c7e     84052cb2fa00                     test   BYTE PTR ds:0xfab22c,al
0x4a0c84     7528                             jne    0x4a0cae
0x4a0c86     09052cb2fa00                     or     DWORD PTR ds:0xfab22c,eax
0x4a0c8c     c744241800000000                 mov    DWORD PTR [esp+0x18],0x0
0x4a0c94     e8f7df0300                       call   0x4dec90
0x4a0c99     6830cebc00                       push   0xbcce30
0x4a0c9e     e877163f00                       call   0x89231a
0x4a0ca3     83c404                           add    esp,0x4
0x4a0ca6     c7442418ffffffff                 mov    DWORD PTR [esp+0x18],0xffffffff
0x4a0cae     8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a0cb1     8d4c2404                         lea    ecx,[esp+0x4]
0x4a0cb5     89442404                         mov    DWORD PTR [esp+0x4],eax
0x4a0cb9     51                               push   ecx
0x4a0cba     8d44240c                         lea    eax,[esp+0xc]
0x4a0cbe     b938b1fa00                       mov    ecx,0xfab138
0x4a0cc3     e838e23800                       call   0x82ef00
0x4a0cc8     8b442408                         mov    eax,DWORD PTR [esp+0x8]
0x4a0ccc     3b053cb1fa00                     cmp    eax,DWORD PTR ds:0xfab13c
0x4a0cd2     7429                             je     0x4a0cfd
0x4a0cd4     8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x4a0cd7     85c0                             test   eax,eax
0x4a0cd9     7422                             je     0x4a0cfd
0x4a0cdb     8b885c010000                     mov    ecx,DWORD PTR [eax+0x15c]
0x4a0ce1     85c9                             test   ecx,ecx
0x4a0ce3     7418                             je     0x4a0cfd
0x4a0ce5     83b87003000000                   cmp    DWORD PTR [eax+0x370],0x0
0x4a0cec     740f                             je     0x4a0cfd
0x4a0cee     0fb7550c                         movzx  edx,WORD PTR [ebp+0xc]
0x4a0cf2     6a00                             push   0x0
0x4a0cf4     6a00                             push   0x0
0x4a0cf6     52                               push   edx
0x4a0cf7     51                               push   ecx
0x4a0cf8     e843653000                       call   0x7a7240
0x4a0cfd     8b4c2410                         mov    ecx,DWORD PTR [esp+0x10]
0x4a0d01     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4a0d08     59                               pop    ecx
0x4a0d09     8be5                             mov    esp,ebp
0x4a0d0b     5d                               pop    ebp
0x4a0d0c     c20800                           ret    0x8
0x4a0d0f     cc                               int3
0x4a0d10     55                               push   ebp
0x4a0d11     8bec                             mov    ebp,esp
0x4a0d13     83e4f8                           and    esp,0xfffffff8
0x4a0d16     6aff                             push   0xffffffff
0x4a0d18     68fe6e9300                       push   0x936efe
0x4a0d1d     64a100000000                     mov    eax,fs:0x0
0x4a0d23     50                               push   eax
0x4a0d24     83ec0c                           sub    esp,0xc
0x4a0d27     a1201fd600                       mov    eax,ds:0xd61f20
0x4a0d2c     33c4                             xor    eax,esp
0x4a0d2e     50                               push   eax
0x4a0d2f     8d442410                         lea    eax,[esp+0x10]
0x4a0d33     64a300000000                     mov    fs:0x0,eax
0x4a0d39     b801000000                       mov    eax,0x1
0x4a0d3e     84052cb2fa00                     test   BYTE PTR ds:0xfab22c,al
0x4a0d44     7528                             jne    0x4a0d6e
0x4a0d46     09052cb2fa00                     or     DWORD PTR ds:0xfab22c,eax
0x4a0d4c     c744241800000000                 mov    DWORD PTR [esp+0x18],0x0
0x4a0d54     e837df0300                       call   0x4dec90
0x4a0d59     6830cebc00                       push   0xbcce30
0x4a0d5e     e8b7153f00                       call   0x89231a
0x4a0d63     83c404                           add    esp,0x4
0x4a0d66     c7442418ffffffff                 mov    DWORD PTR [esp+0x18],0xffffffff
0x4a0d6e     8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4a0d71     8d4c2404                         lea    ecx,[esp+0x4]
0x4a0d75     89442404                         mov    DWORD PTR [esp+0x4],eax
0x4a0d79     51                               push   ecx
0x4a0d7a     8d44240c                         lea    eax,[esp+0xc]
0x4a0d7e     b938b1fa00                       mov    ecx,0xfab138
0x4a0d83     e878e13800                       call   0x82ef00
0x4a0d88     8b442408                         mov    eax,DWORD PTR [esp+0x8]
0x4a0d8c     3b053cb1fa00                     cmp    eax,DWORD PTR ds:0xfab13c
0x4a0d92     7424                             je     0x4a0db8
0x4a0d94     8b4010                           mov    eax,DWORD PTR [eax+0x10]
0x4a0d97     85c0                             test   eax,eax
0x4a0d99     741d                             je     0x4a0db8
0x4a0d9b     8b885c010000                     mov    ecx,DWORD PTR [eax+0x15c]
0x4a0da1     85c9                             test   ecx,ecx
0x4a0da3     7413                             je     0x4a0db8
0x4a0da5     83b87003000000                   cmp    DWORD PTR [eax+0x370],0x0
0x4a0dac     740a                             je     0x4a0db8
0x4a0dae     8b550c                           mov    edx,DWORD PTR [ebp+0xc]
0x4a0db1     52                               push   edx
0x4a0db2     51                               push   ecx
0x4a0db3     e868683000                       call   0x7a7620
0x4a0db8     8b4c2410                         mov    ecx,DWORD PTR [esp+0x10]
0x4a0dbc     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4a0dc3     59                               pop    ecx
0x4a0dc4     8be5                             mov    esp,ebp
0x4a0dc6     5d                               pop    ebp
0x4a0dc7     c20800                           ret    0x8
0x4a0dca     cc                               int3
0x4a0dcb     cc                               int3
0x4a0dcc     cc                               int3
0x4a0dcd     cc                               int3
0x4a0dce     cc                               int3
0x4a0dcf     cc                               int3

; actor_map_insert 0x4dff30..0x4dffaa raw=0xdf330 SHA256=3f117a1e4bbff0df9e40958c1e7d3af22bdfe8c05860d441437b37af52d18295
0x4dff30     55                               push   ebp
0x4dff31     8bec                             mov    ebp,esp
0x4dff33     83ec10                           sub    esp,0x10
0x4dff36     53                               push   ebx
0x4dff37     8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x4dff3a     56                               push   esi
0x4dff3b     57                               push   edi
0x4dff3c     8bf8                             mov    edi,eax
0x4dff3e     85ff                             test   edi,edi
0x4dff40     750a                             jne    0x4dff4c
0x4dff42     68d0cec000                       push   0xc0ced0
0x4dff47     e824dd2000                       call   0x6edc70
0x4dff4c     0fb74704                         movzx  eax,WORD PTR [edi+0x4]
0x4dff50     8d4d08                           lea    ecx,[ebp+0x8]
0x4dff53     894508                           mov    DWORD PTR [ebp+0x8],eax
0x4dff56     8d7308                           lea    esi,[ebx+0x8]
0x4dff59     51                               push   ecx
0x4dff5a     8d45f8                           lea    eax,[ebp-0x8]
0x4dff5d     8bce                             mov    ecx,esi
0x4dff5f     e89cef3400                       call   0x82ef00
0x4dff64     8b55f8                           mov    edx,DWORD PTR [ebp-0x8]
0x4dff67     3b530c                           cmp    edx,DWORD PTR [ebx+0xc]
0x4dff6a     7524                             jne    0x4dff90
0x4dff6c     8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4dff6f     897df8                           mov    DWORD PTR [ebp-0x8],edi
0x4dff72     8d7df4                           lea    edi,[ebp-0xc]
0x4dff75     8945f4                           mov    DWORD PTR [ebp-0xc],eax
0x4dff78     e8a3ef0900                       call   0x57ef20
0x4dff7d     50                               push   eax
0x4dff7e     56                               push   esi
0x4dff7f     8d75f4                           lea    esi,[ebp-0xc]
0x4dff82     e879f23400                       call   0x82f200
0x4dff87     5f                               pop    edi
0x4dff88     5e                               pop    esi
0x4dff89     5b                               pop    ebx
0x4dff8a     8be5                             mov    esp,ebp
0x4dff8c     5d                               pop    ebp
0x4dff8d     c20400                           ret    0x4
0x4dff90     8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x4dff93     51                               push   ecx
0x4dff94     68f0cec000                       push   0xc0cef0
0x4dff99     e8c2db2000                       call   0x6edb60
0x4dff9e     83c408                           add    esp,0x8
0x4dffa1     5f                               pop    edi
0x4dffa2     5e                               pop    esi
0x4dffa3     5b                               pop    ebx
0x4dffa4     8be5                             mov    esp,ebp
0x4dffa6     5d                               pop    ebp
0x4dffa7     c20400                           ret    0x4

; frontend_init 0x493170..0x494356 raw=0x92570 SHA256=4f0b7fa15699c519d70d8636e6478d15dc87f475fc71972e5bb41ad5d038d3ae
0x493170     53                               push   ebx
0x493171     56                               push   esi
0x493172     57                               push   edi
0x493173     bf60434900                       mov    edi,0x494360
0x493178     33db                             xor    ebx,ebx
0x49317a     8d9010020000                     lea    edx,[eax+0x210]
0x493180     bed50b0000                       mov    esi,0xbd5
0x493185     b97523bf00                       mov    ecx,0xbf2375
0x49318a     8d9b00000000                     lea    ebx,[ebx+0x0]
0x493190     897af8                           mov    DWORD PTR [edx-0x8],edi
0x493193     895afc                           mov    DWORD PTR [edx-0x4],ebx
0x493196     890a                             mov    DWORD PTR [edx],ecx
0x493198     83c210                           add    edx,0x10
0x49319b     4e                               dec    esi
0x49319c     75f2                             jne    0x493190
0x49319e     ba80474900                       mov    edx,0x494780
0x4931a3     899098030000                     mov    DWORD PTR [eax+0x398],edx
0x4931a9     bab0434900                       mov    edx,0x4943b0
0x4931ae     899048100000                     mov    DWORD PTR [eax+0x1048],edx
0x4931b4     bab0434900                       mov    edx,0x4943b0
0x4931b9     8990c8030000                     mov    DWORD PTR [eax+0x3c8],edx
0x4931bf     bab0434900                       mov    edx,0x4943b0
0x4931c4     899008040000                     mov    DWORD PTR [eax+0x408],edx
0x4931ca     ba60484900                       mov    edx,0x494860
0x4931cf     899038040000                     mov    DWORD PTR [eax+0x438],edx
0x4931d5     ba904a4900                       mov    edx,0x494a90
0x4931da     899048040000                     mov    DWORD PTR [eax+0x448],edx
0x4931e0     bad04c4900                       mov    edx,0x494cd0
0x4931e5     8990f8040000                     mov    DWORD PTR [eax+0x4f8],edx
0x4931eb     ba50474900                       mov    edx,0x494750
0x4931f0     899078090000                     mov    DWORD PTR [eax+0x978],edx
0x4931f6     baf0594900                       mov    edx,0x4959f0
0x4931fb     8990a80f0000                     mov    DWORD PTR [eax+0xfa8],edx
0x493201     ba605a4900                       mov    edx,0x495a60
0x493206     8990280f0000                     mov    DWORD PTR [eax+0xf28],edx
0x49320c     bab0434900                       mov    edx,0x4943b0
0x493211     899008090000                     mov    DWORD PTR [eax+0x908],edx
0x493217     bab0434900                       mov    edx,0x4943b0
0x49321c     899098040000                     mov    DWORD PTR [eax+0x498],edx
0x493222     bab0434900                       mov    edx,0x4943b0
0x493227     8990e8030000                     mov    DWORD PTR [eax+0x3e8],edx
0x49322d     bab0434900                       mov    edx,0x4943b0
0x493232     899048060000                     mov    DWORD PTR [eax+0x648],edx
0x493238     bab0434900                       mov    edx,0x4943b0
0x49323d     8990a8040000                     mov    DWORD PTR [eax+0x4a8],edx
0x493243     bab0434900                       mov    edx,0x4943b0
0x493248     8990c8040000                     mov    DWORD PTR [eax+0x4c8],edx
0x49324e     bab0434900                       mov    edx,0x4943b0
0x493253     899018150000                     mov    DWORD PTR [eax+0x1518],edx
0x493259     bab0434900                       mov    edx,0x4943b0
0x49325e     8990d8040000                     mov    DWORD PTR [eax+0x4d8],edx
0x493264     bab0434900                       mov    edx,0x4943b0
0x493269     899018080000                     mov    DWORD PTR [eax+0x818],edx
0x49326f     bab0434900                       mov    edx,0x4943b0
0x493274     899068080000                     mov    DWORD PTR [eax+0x868],edx
0x49327a     89b09c030000                     mov    DWORD PTR [eax+0x39c],esi
0x493280     8988a0030000                     mov    DWORD PTR [eax+0x3a0],ecx
0x493286     89b04c100000                     mov    DWORD PTR [eax+0x104c],esi
0x49328c     898850100000                     mov    DWORD PTR [eax+0x1050],ecx
0x493292     89b0cc030000                     mov    DWORD PTR [eax+0x3cc],esi
0x493298     8988d0030000                     mov    DWORD PTR [eax+0x3d0],ecx
0x49329e     89b00c040000                     mov    DWORD PTR [eax+0x40c],esi
0x4932a4     898810040000                     mov    DWORD PTR [eax+0x410],ecx
0x4932aa     89b03c040000                     mov    DWORD PTR [eax+0x43c],esi
0x4932b0     898840040000                     mov    DWORD PTR [eax+0x440],ecx
0x4932b6     89b04c040000                     mov    DWORD PTR [eax+0x44c],esi
0x4932bc     898850040000                     mov    DWORD PTR [eax+0x450],ecx
0x4932c2     89b0fc040000                     mov    DWORD PTR [eax+0x4fc],esi
0x4932c8     898800050000                     mov    DWORD PTR [eax+0x500],ecx
0x4932ce     89b07c090000                     mov    DWORD PTR [eax+0x97c],esi
0x4932d4     898880090000                     mov    DWORD PTR [eax+0x980],ecx
0x4932da     89b0ac0f0000                     mov    DWORD PTR [eax+0xfac],esi
0x4932e0     8988b00f0000                     mov    DWORD PTR [eax+0xfb0],ecx
0x4932e6     89b02c0f0000                     mov    DWORD PTR [eax+0xf2c],esi
0x4932ec     8988300f0000                     mov    DWORD PTR [eax+0xf30],ecx
0x4932f2     89b00c090000                     mov    DWORD PTR [eax+0x90c],esi
0x4932f8     898810090000                     mov    DWORD PTR [eax+0x910],ecx
0x4932fe     89b09c040000                     mov    DWORD PTR [eax+0x49c],esi
0x493304     8988a0040000                     mov    DWORD PTR [eax+0x4a0],ecx
0x49330a     89b0ec030000                     mov    DWORD PTR [eax+0x3ec],esi
0x493310     8988f0030000                     mov    DWORD PTR [eax+0x3f0],ecx
0x493316     89b04c060000                     mov    DWORD PTR [eax+0x64c],esi
0x49331c     898850060000                     mov    DWORD PTR [eax+0x650],ecx
0x493322     89b0ac040000                     mov    DWORD PTR [eax+0x4ac],esi
0x493328     8988b0040000                     mov    DWORD PTR [eax+0x4b0],ecx
0x49332e     89b0cc040000                     mov    DWORD PTR [eax+0x4cc],esi
0x493334     8988d0040000                     mov    DWORD PTR [eax+0x4d0],ecx
0x49333a     89b01c150000                     mov    DWORD PTR [eax+0x151c],esi
0x493340     898820150000                     mov    DWORD PTR [eax+0x1520],ecx
0x493346     89b0dc040000                     mov    DWORD PTR [eax+0x4dc],esi
0x49334c     8988e0040000                     mov    DWORD PTR [eax+0x4e0],ecx
0x493352     89b01c080000                     mov    DWORD PTR [eax+0x81c],esi
0x493358     898820080000                     mov    DWORD PTR [eax+0x820],ecx
0x49335e     89b06c080000                     mov    DWORD PTR [eax+0x86c],esi
0x493364     898870080000                     mov    DWORD PTR [eax+0x870],ecx
0x49336a     bab0434900                       mov    edx,0x4943b0
0x49336f     899078080000                     mov    DWORD PTR [eax+0x878],edx
0x493375     bab0434900                       mov    edx,0x4943b0
0x49337a     8990b8040000                     mov    DWORD PTR [eax+0x4b8],edx
0x493380     bab0434900                       mov    edx,0x4943b0
0x493385     8990c8050000                     mov    DWORD PTR [eax+0x5c8],edx
0x49338b     bab0434900                       mov    edx,0x4943b0
0x493390     8990b8090000                     mov    DWORD PTR [eax+0x9b8],edx
0x493396     bab0434900                       mov    edx,0x4943b0
0x49339b     899088090000                     mov    DWORD PTR [eax+0x988],edx
0x4933a1     bab0434900                       mov    edx,0x4943b0
0x4933a6     8990d8090000                     mov    DWORD PTR [eax+0x9d8],edx
0x4933ac     bab0434900                       mov    edx,0x4943b0
0x4933b1     8990180a0000                     mov    DWORD PTR [eax+0xa18],edx
0x4933b7     bab0434900                       mov    edx,0x4943b0
0x4933bc     8990380a0000                     mov    DWORD PTR [eax+0xa38],edx
0x4933c2     bab0434900                       mov    edx,0x4943b0
0x4933c7     8990980f0000                     mov    DWORD PTR [eax+0xf98],edx
0x4933cd     bab0434900                       mov    edx,0x4943b0
0x4933d2     8990e8090000                     mov    DWORD PTR [eax+0x9e8],edx
0x4933d8     bab0434900                       mov    edx,0x4943b0
0x4933dd     8990080a0000                     mov    DWORD PTR [eax+0xa08],edx
0x4933e3     bab0434900                       mov    edx,0x4943b0
0x4933e8     8990180e0000                     mov    DWORD PTR [eax+0xe18],edx
0x4933ee     bab0434900                       mov    edx,0x4943b0
0x4933f3     8990480a0000                     mov    DWORD PTR [eax+0xa48],edx
0x4933f9     bab0434900                       mov    edx,0x4943b0
0x4933fe     8990280b0000                     mov    DWORD PTR [eax+0xb28],edx
0x493404     bab0434900                       mov    edx,0x4943b0
0x493409     8990d80c0000                     mov    DWORD PTR [eax+0xcd8],edx
0x49340f     bab0434900                       mov    edx,0x4943b0
0x493414     8990e80c0000                     mov    DWORD PTR [eax+0xce8],edx
0x49341a     bab0434900                       mov    edx,0x4943b0
0x49341f     8990380b0000                     mov    DWORD PTR [eax+0xb38],edx
0x493425     bab0434900                       mov    edx,0x4943b0
0x49342a     8990280d0000                     mov    DWORD PTR [eax+0xd28],edx
0x493430     bab0434900                       mov    edx,0x4943b0
0x493435     8990080d0000                     mov    DWORD PTR [eax+0xd08],edx
0x49343b     bab0434900                       mov    edx,0x4943b0
0x493440     899078be0000                     mov    DWORD PTR [eax+0xbe78],edx
0x493446     bab0434900                       mov    edx,0x4943b0
0x49344b     89b07c080000                     mov    DWORD PTR [eax+0x87c],esi
0x493451     898880080000                     mov    DWORD PTR [eax+0x880],ecx
0x493457     89b0bc040000                     mov    DWORD PTR [eax+0x4bc],esi
0x49345d     8988c0040000                     mov    DWORD PTR [eax+0x4c0],ecx
0x493463     89b0cc050000                     mov    DWORD PTR [eax+0x5cc],esi
0x493469     8988d0050000                     mov    DWORD PTR [eax+0x5d0],ecx
0x49346f     89b0bc090000                     mov    DWORD PTR [eax+0x9bc],esi
0x493475     8988c0090000                     mov    DWORD PTR [eax+0x9c0],ecx
0x49347b     89b08c090000                     mov    DWORD PTR [eax+0x98c],esi
0x493481     898890090000                     mov    DWORD PTR [eax+0x990],ecx
0x493487     89b0dc090000                     mov    DWORD PTR [eax+0x9dc],esi
0x49348d     8988e0090000                     mov    DWORD PTR [eax+0x9e0],ecx
0x493493     89b01c0a0000                     mov    DWORD PTR [eax+0xa1c],esi
0x493499     8988200a0000                     mov    DWORD PTR [eax+0xa20],ecx
0x49349f     89b03c0a0000                     mov    DWORD PTR [eax+0xa3c],esi
0x4934a5     8988400a0000                     mov    DWORD PTR [eax+0xa40],ecx
0x4934ab     89b09c0f0000                     mov    DWORD PTR [eax+0xf9c],esi
0x4934b1     8988a00f0000                     mov    DWORD PTR [eax+0xfa0],ecx
0x4934b7     89b0ec090000                     mov    DWORD PTR [eax+0x9ec],esi
0x4934bd     8988f0090000                     mov    DWORD PTR [eax+0x9f0],ecx
0x4934c3     89b00c0a0000                     mov    DWORD PTR [eax+0xa0c],esi
0x4934c9     8988100a0000                     mov    DWORD PTR [eax+0xa10],ecx
0x4934cf     89b01c0e0000                     mov    DWORD PTR [eax+0xe1c],esi
0x4934d5     8988200e0000                     mov    DWORD PTR [eax+0xe20],ecx
0x4934db     89b04c0a0000                     mov    DWORD PTR [eax+0xa4c],esi
0x4934e1     8988500a0000                     mov    DWORD PTR [eax+0xa50],ecx
0x4934e7     89b02c0b0000                     mov    DWORD PTR [eax+0xb2c],esi
0x4934ed     8988300b0000                     mov    DWORD PTR [eax+0xb30],ecx
0x4934f3     89b0dc0c0000                     mov    DWORD PTR [eax+0xcdc],esi
0x4934f9     8988e00c0000                     mov    DWORD PTR [eax+0xce0],ecx
0x4934ff     89b0ec0c0000                     mov    DWORD PTR [eax+0xcec],esi
0x493505     8988f00c0000                     mov    DWORD PTR [eax+0xcf0],ecx
0x49350b     89b03c0b0000                     mov    DWORD PTR [eax+0xb3c],esi
0x493511     8988400b0000                     mov    DWORD PTR [eax+0xb40],ecx
0x493517     89b02c0d0000                     mov    DWORD PTR [eax+0xd2c],esi
0x49351d     8988300d0000                     mov    DWORD PTR [eax+0xd30],ecx
0x493523     89b00c0d0000                     mov    DWORD PTR [eax+0xd0c],esi
0x493529     8988100d0000                     mov    DWORD PTR [eax+0xd10],ecx
0x49352f     89b07cbe0000                     mov    DWORD PTR [eax+0xbe7c],esi
0x493535     898880be0000                     mov    DWORD PTR [eax+0xbe80],ecx
0x49353b     8990280e0000                     mov    DWORD PTR [eax+0xe28],edx
0x493541     89b02c0e0000                     mov    DWORD PTR [eax+0xe2c],esi
0x493547     8988300e0000                     mov    DWORD PTR [eax+0xe30],ecx
0x49354d     89b03c0e0000                     mov    DWORD PTR [eax+0xe3c],esi
0x493553     8988400e0000                     mov    DWORD PTR [eax+0xe40],ecx
0x493559     89b04c0e0000                     mov    DWORD PTR [eax+0xe4c],esi
0x49355f     8988500e0000                     mov    DWORD PTR [eax+0xe50],ecx
0x493565     89b06c0e0000                     mov    DWORD PTR [eax+0xe6c],esi
0x49356b     8988700e0000                     mov    DWORD PTR [eax+0xe70],ecx
0x493571     89b05c0e0000                     mov    DWORD PTR [eax+0xe5c],esi
0x493577     8988600e0000                     mov    DWORD PTR [eax+0xe60],ecx
0x49357d     89b0dc0f0000                     mov    DWORD PTR [eax+0xfdc],esi
0x493583     8988e00f0000                     mov    DWORD PTR [eax+0xfe0],ecx
0x493589     89b0fc0f0000                     mov    DWORD PTR [eax+0xffc],esi
0x49358f     898800100000                     mov    DWORD PTR [eax+0x1000],ecx
0x493595     89b02c100000                     mov    DWORD PTR [eax+0x102c],esi
0x49359b     898830100000                     mov    DWORD PTR [eax+0x1030],ecx
0x4935a1     bab0434900                       mov    edx,0x4943b0
0x4935a6     8990380e0000                     mov    DWORD PTR [eax+0xe38],edx
0x4935ac     bab0434900                       mov    edx,0x4943b0
0x4935b1     8990480e0000                     mov    DWORD PTR [eax+0xe48],edx
0x4935b7     bab0434900                       mov    edx,0x4943b0
0x4935bc     8990680e0000                     mov    DWORD PTR [eax+0xe68],edx
0x4935c2     bab0434900                       mov    edx,0x4943b0
0x4935c7     8990580e0000                     mov    DWORD PTR [eax+0xe58],edx
0x4935cd     bab0434900                       mov    edx,0x4943b0
0x4935d2     8990d80f0000                     mov    DWORD PTR [eax+0xfd8],edx
0x4935d8     bab0434900                       mov    edx,0x4943b0
0x4935dd     8990f80f0000                     mov    DWORD PTR [eax+0xff8],edx
0x4935e3     bab0434900                       mov    edx,0x4943b0
0x4935e8     899028100000                     mov    DWORD PTR [eax+0x1028],edx
0x4935ee     bab0434900                       mov    edx,0x4943b0
0x4935f3     899038100000                     mov    DWORD PTR [eax+0x1038],edx
0x4935f9     89b03c100000                     mov    DWORD PTR [eax+0x103c],esi
0x4935ff     898840100000                     mov    DWORD PTR [eax+0x1040],ecx
0x493605     bab0434900                       mov    edx,0x4943b0
0x49360a     899058100000                     mov    DWORD PTR [eax+0x1058],edx
0x493610     89b05c100000                     mov    DWORD PTR [eax+0x105c],esi
0x493616     898860100000                     mov    DWORD PTR [eax+0x1060],ecx
0x49361c     bab0434900                       mov    edx,0x4943b0
0x493621     899068100000                     mov    DWORD PTR [eax+0x1068],edx
0x493627     89b06c100000                     mov    DWORD PTR [eax+0x106c],esi
0x49362d     898870100000                     mov    DWORD PTR [eax+0x1070],ecx
0x493633     bab0434900                       mov    edx,0x4943b0
0x493638     899018140000                     mov    DWORD PTR [eax+0x1418],edx
0x49363e     89b01c140000                     mov    DWORD PTR [eax+0x141c],esi
0x493644     898820140000                     mov    DWORD PTR [eax+0x1420],ecx
0x49364a     bab0434900                       mov    edx,0x4943b0
0x49364f     899028140000                     mov    DWORD PTR [eax+0x1428],edx
0x493655     89b02c140000                     mov    DWORD PTR [eax+0x142c],esi
0x49365b     898830140000                     mov    DWORD PTR [eax+0x1430],ecx
0x493661     bab0434900                       mov    edx,0x4943b0
0x493666     899068120000                     mov    DWORD PTR [eax+0x1268],edx
0x49366c     89b06c120000                     mov    DWORD PTR [eax+0x126c],esi
0x493672     898870120000                     mov    DWORD PTR [eax+0x1270],ecx
0x493678     bab0434900                       mov    edx,0x4943b0
0x49367d     899078100000                     mov    DWORD PTR [eax+0x1078],edx
0x493683     89b07c100000                     mov    DWORD PTR [eax+0x107c],esi
0x493689     898880100000                     mov    DWORD PTR [eax+0x1080],ecx
0x49368f     ba40444900                       mov    edx,0x494440
0x493694     899008060000                     mov    DWORD PTR [eax+0x608],edx
0x49369a     89b00c060000                     mov    DWORD PTR [eax+0x60c],esi
0x4936a0     898810060000                     mov    DWORD PTR [eax+0x610],ecx
0x4936a6     ba40444900                       mov    edx,0x494440
0x4936ab     899058060000                     mov    DWORD PTR [eax+0x658],edx
0x4936b1     89b05c060000                     mov    DWORD PTR [eax+0x65c],esi
0x4936b7     898860060000                     mov    DWORD PTR [eax+0x660],ecx
0x4936bd     ba40444900                       mov    edx,0x494440
0x4936c2     899068060000                     mov    DWORD PTR [eax+0x668],edx
0x4936c8     89b06c060000                     mov    DWORD PTR [eax+0x66c],esi
0x4936ce     898870060000                     mov    DWORD PTR [eax+0x670],ecx
0x4936d4     ba40444900                       mov    edx,0x494440
0x4936d9     899078060000                     mov    DWORD PTR [eax+0x678],edx
0x4936df     89b07c060000                     mov    DWORD PTR [eax+0x67c],esi
0x4936e5     898880060000                     mov    DWORD PTR [eax+0x680],ecx
0x4936eb     ba40444900                       mov    edx,0x494440
0x4936f0     899048080000                     mov    DWORD PTR [eax+0x848],edx
0x4936f6     89b04c080000                     mov    DWORD PTR [eax+0x84c],esi
0x4936fc     898850080000                     mov    DWORD PTR [eax+0x850],ecx
0x493702     ba40444900                       mov    edx,0x494440
0x493707     899058080000                     mov    DWORD PTR [eax+0x858],edx
0x49370d     89b05c080000                     mov    DWORD PTR [eax+0x85c],esi
0x493713     898860080000                     mov    DWORD PTR [eax+0x860],ecx
0x493719     ba40444900                       mov    edx,0x494440
0x49371e     8990f8080000                     mov    DWORD PTR [eax+0x8f8],edx
0x493724     89b0fc080000                     mov    DWORD PTR [eax+0x8fc],esi
0x49372a     898800090000                     mov    DWORD PTR [eax+0x900],ecx
0x493730     ba40444900                       mov    edx,0x494440
0x493735     899028090000                     mov    DWORD PTR [eax+0x928],edx
0x49373b     89b02c090000                     mov    DWORD PTR [eax+0x92c],esi
0x493741     898830090000                     mov    DWORD PTR [eax+0x930],ecx
0x493747     ba40444900                       mov    edx,0x494440
0x49374c     899048090000                     mov    DWORD PTR [eax+0x948],edx
0x493752     89b04c090000                     mov    DWORD PTR [eax+0x94c],esi
0x493758     898850090000                     mov    DWORD PTR [eax+0x950],ecx
0x49375e     bad0444900                       mov    edx,0x4944d0
0x493763     8990580a0000                     mov    DWORD PTR [eax+0xa58],edx
0x493769     89b05c0a0000                     mov    DWORD PTR [eax+0xa5c],esi
0x49376f     8988600a0000                     mov    DWORD PTR [eax+0xa60],ecx
0x493775     bad0444900                       mov    edx,0x4944d0
0x49377a     8990680a0000                     mov    DWORD PTR [eax+0xa68],edx
0x493780     89b06c0a0000                     mov    DWORD PTR [eax+0xa6c],esi
0x493786     8988700a0000                     mov    DWORD PTR [eax+0xa70],ecx
0x49378c     bad0444900                       mov    edx,0x4944d0
0x493791     8990780a0000                     mov    DWORD PTR [eax+0xa78],edx
0x493797     89b07c0a0000                     mov    DWORD PTR [eax+0xa7c],esi
0x49379d     8988800a0000                     mov    DWORD PTR [eax+0xa80],ecx
0x4937a3     bad0444900                       mov    edx,0x4944d0
0x4937a8     899038070000                     mov    DWORD PTR [eax+0x738],edx
0x4937ae     89b03c070000                     mov    DWORD PTR [eax+0x73c],esi
0x4937b4     898840070000                     mov    DWORD PTR [eax+0x740],ecx
0x4937ba     bad0444900                       mov    edx,0x4944d0
0x4937bf     899048070000                     mov    DWORD PTR [eax+0x748],edx
0x4937c5     89b04c070000                     mov    DWORD PTR [eax+0x74c],esi
0x4937cb     898850070000                     mov    DWORD PTR [eax+0x750],ecx
0x4937d1     bad0444900                       mov    edx,0x4944d0
0x4937d6     899058070000                     mov    DWORD PTR [eax+0x758],edx
0x4937dc     89b05c070000                     mov    DWORD PTR [eax+0x75c],esi
0x4937e2     898860070000                     mov    DWORD PTR [eax+0x760],ecx
0x4937e8     bad0444900                       mov    edx,0x4944d0
0x4937ed     899068070000                     mov    DWORD PTR [eax+0x768],edx
0x4937f3     89b06c070000                     mov    DWORD PTR [eax+0x76c],esi
0x4937f9     898870070000                     mov    DWORD PTR [eax+0x770],ecx
0x4937ff     bad0444900                       mov    edx,0x4944d0
0x493804     899078070000                     mov    DWORD PTR [eax+0x778],edx
0x49380a     89b07c070000                     mov    DWORD PTR [eax+0x77c],esi
0x493810     898880070000                     mov    DWORD PTR [eax+0x780],ecx
0x493816     bad0444900                       mov    edx,0x4944d0
0x49381b     899088070000                     mov    DWORD PTR [eax+0x788],edx
0x493821     89b08c070000                     mov    DWORD PTR [eax+0x78c],esi
0x493827     898890070000                     mov    DWORD PTR [eax+0x790],ecx
0x49382d     bad0444900                       mov    edx,0x4944d0
0x493832     8990a8070000                     mov    DWORD PTR [eax+0x7a8],edx
0x493838     89b0ac070000                     mov    DWORD PTR [eax+0x7ac],esi
0x49383e     8988b0070000                     mov    DWORD PTR [eax+0x7b0],ecx
0x493844     ba60454900                       mov    edx,0x494560
0x493849     8990d80a0000                     mov    DWORD PTR [eax+0xad8],edx
0x49384f     89b0dc0a0000                     mov    DWORD PTR [eax+0xadc],esi
0x493855     8988e00a0000                     mov    DWORD PTR [eax+0xae0],ecx
0x49385b     ba60454900                       mov    edx,0x494560
0x493860     8990e80a0000                     mov    DWORD PTR [eax+0xae8],edx
0x493866     89b0ec0a0000                     mov    DWORD PTR [eax+0xaec],esi
0x49386c     8988f00a0000                     mov    DWORD PTR [eax+0xaf0],ecx
0x493872     ba60454900                       mov    edx,0x494560
0x493877     8990f80a0000                     mov    DWORD PTR [eax+0xaf8],edx
0x49387d     89b0fc0a0000                     mov    DWORD PTR [eax+0xafc],esi
0x493883     8988000b0000                     mov    DWORD PTR [eax+0xb00],ecx
0x493889     ba60454900                       mov    edx,0x494560
0x49388e     8990080b0000                     mov    DWORD PTR [eax+0xb08],edx
0x493894     89b00c0b0000                     mov    DWORD PTR [eax+0xb0c],esi
0x49389a     8988100b0000                     mov    DWORD PTR [eax+0xb10],ecx
0x4938a0     ba60454900                       mov    edx,0x494560
0x4938a5     8990880a0000                     mov    DWORD PTR [eax+0xa88],edx
0x4938ab     89b08c0a0000                     mov    DWORD PTR [eax+0xa8c],esi
0x4938b1     8988900a0000                     mov    DWORD PTR [eax+0xa90],ecx
0x4938b7     ba60454900                       mov    edx,0x494560
0x4938bc     8990980a0000                     mov    DWORD PTR [eax+0xa98],edx
0x4938c2     89b09c0a0000                     mov    DWORD PTR [eax+0xa9c],esi
0x4938c8     8988a00a0000                     mov    DWORD PTR [eax+0xaa0],ecx
0x4938ce     ba60454900                       mov    edx,0x494560
0x4938d3     8990a80a0000                     mov    DWORD PTR [eax+0xaa8],edx
0x4938d9     89b0ac0a0000                     mov    DWORD PTR [eax+0xaac],esi
0x4938df     8988b00a0000                     mov    DWORD PTR [eax+0xab0],ecx
0x4938e5     ba60454900                       mov    edx,0x494560
0x4938ea     8990b80a0000                     mov    DWORD PTR [eax+0xab8],edx
0x4938f0     89b0bc0a0000                     mov    DWORD PTR [eax+0xabc],esi
0x4938f6     8988c00a0000                     mov    DWORD PTR [eax+0xac0],ecx
0x4938fc     ba60454900                       mov    edx,0x494560
0x493901     8990c80a0000                     mov    DWORD PTR [eax+0xac8],edx
0x493907     89b0cc0a0000                     mov    DWORD PTR [eax+0xacc],esi
0x49390d     8988d00a0000                     mov    DWORD PTR [eax+0xad0],ecx
0x493913     ba80464900                       mov    edx,0x494680
0x493918     899098bd0000                     mov    DWORD PTR [eax+0xbd98],edx
0x49391e     89b09cbd0000                     mov    DWORD PTR [eax+0xbd9c],esi
0x493924     8988a0bd0000                     mov    DWORD PTR [eax+0xbda0],ecx
0x49392a     ba80464900                       mov    edx,0x494680
0x49392f     8990a8bd0000                     mov    DWORD PTR [eax+0xbda8],edx
0x493935     89b0acbd0000                     mov    DWORD PTR [eax+0xbdac],esi
0x49393b     8988b0bd0000                     mov    DWORD PTR [eax+0xbdb0],ecx
0x493941     ba80464900                       mov    edx,0x494680
0x493946     8990b8bd0000                     mov    DWORD PTR [eax+0xbdb8],edx
0x49394c     89b0bcbd0000                     mov    DWORD PTR [eax+0xbdbc],esi
0x493952     8988c0bd0000                     mov    DWORD PTR [eax+0xbdc0],ecx
0x493958     ba80464900                       mov    edx,0x494680
0x49395d     8990c8bd0000                     mov    DWORD PTR [eax+0xbdc8],edx
0x493963     89b0ccbd0000                     mov    DWORD PTR [eax+0xbdcc],esi
0x493969     8988d0bd0000                     mov    DWORD PTR [eax+0xbdd0],ecx
0x49396f     ba80464900                       mov    edx,0x494680
0x493974     899098be0000                     mov    DWORD PTR [eax+0xbe98],edx
0x49397a     89b09cbe0000                     mov    DWORD PTR [eax+0xbe9c],esi
0x493980     8988a0be0000                     mov    DWORD PTR [eax+0xbea0],ecx
0x493986     ba80464900                       mov    edx,0x494680
0x49398b     899088be0000                     mov    DWORD PTR [eax+0xbe88],edx
0x493991     89b08cbe0000                     mov    DWORD PTR [eax+0xbe8c],esi
0x493997     898890be0000                     mov    DWORD PTR [eax+0xbe90],ecx
0x49399d     ba80464900                       mov    edx,0x494680
0x4939a2     8990b8be0000                     mov    DWORD PTR [eax+0xbeb8],edx
0x4939a8     89b0bcbe0000                     mov    DWORD PTR [eax+0xbebc],esi
0x4939ae     8988c0be0000                     mov    DWORD PTR [eax+0xbec0],ecx
0x4939b4     ba80464900                       mov    edx,0x494680
0x4939b9     8990d8bd0000                     mov    DWORD PTR [eax+0xbdd8],edx
0x4939bf     89b0dcbd0000                     mov    DWORD PTR [eax+0xbddc],esi
0x4939c5     8988e0bd0000                     mov    DWORD PTR [eax+0xbde0],ecx
0x4939cb     ba80464900                       mov    edx,0x494680
0x4939d0     8990a8be0000                     mov    DWORD PTR [eax+0xbea8],edx
0x4939d6     89b0acbe0000                     mov    DWORD PTR [eax+0xbeac],esi
0x4939dc     8988b0be0000                     mov    DWORD PTR [eax+0xbeb0],ecx
0x4939e2     ba80464900                       mov    edx,0x494680
0x4939e7     8990e8bd0000                     mov    DWORD PTR [eax+0xbde8],edx
0x4939ed     89b0ecbd0000                     mov    DWORD PTR [eax+0xbdec],esi
0x4939f3     8988f0bd0000                     mov    DWORD PTR [eax+0xbdf0],ecx
0x4939f9     ba80464900                       mov    edx,0x494680
0x4939fe     8990f8bd0000                     mov    DWORD PTR [eax+0xbdf8],edx
0x493a04     89b0fcbd0000                     mov    DWORD PTR [eax+0xbdfc],esi
0x493a0a     898800be0000                     mov    DWORD PTR [eax+0xbe00],ecx
0x493a10     ba80464900                       mov    edx,0x494680
0x493a15     899008be0000                     mov    DWORD PTR [eax+0xbe08],edx
0x493a1b     89b00cbe0000                     mov    DWORD PTR [eax+0xbe0c],esi
0x493a21     898810be0000                     mov    DWORD PTR [eax+0xbe10],ecx
0x493a27     ba80464900                       mov    edx,0x494680
0x493a2c     899038be0000                     mov    DWORD PTR [eax+0xbe38],edx
0x493a32     89b03cbe0000                     mov    DWORD PTR [eax+0xbe3c],esi
0x493a38     898840be0000                     mov    DWORD PTR [eax+0xbe40],ecx
0x493a3e     ba80464900                       mov    edx,0x494680
0x493a43     8990380d0000                     mov    DWORD PTR [eax+0xd38],edx
0x493a49     89b03c0d0000                     mov    DWORD PTR [eax+0xd3c],esi
0x493a4f     8988400d0000                     mov    DWORD PTR [eax+0xd40],ecx
0x493a55     ba80464900                       mov    edx,0x494680
0x493a5a     899048be0000                     mov    DWORD PTR [eax+0xbe48],edx
0x493a60     89b04cbe0000                     mov    DWORD PTR [eax+0xbe4c],esi
0x493a66     898850be0000                     mov    DWORD PTR [eax+0xbe50],ecx
0x493a6c     ba80464900                       mov    edx,0x494680
0x493a71     899058be0000                     mov    DWORD PTR [eax+0xbe58],edx
0x493a77     89b05cbe0000                     mov    DWORD PTR [eax+0xbe5c],esi
0x493a7d     898860be0000                     mov    DWORD PTR [eax+0xbe60],ecx
0x493a83     ba80464900                       mov    edx,0x494680
0x493a88     899068be0000                     mov    DWORD PTR [eax+0xbe68],edx
0x493a8e     89b06cbe0000                     mov    DWORD PTR [eax+0xbe6c],esi
0x493a94     898870be0000                     mov    DWORD PTR [eax+0xbe70],ecx
0x493a9a     ba80464900                       mov    edx,0x494680
0x493a9f     899018be0000                     mov    DWORD PTR [eax+0xbe18],edx
0x493aa5     89b01cbe0000                     mov    DWORD PTR [eax+0xbe1c],esi
0x493aab     898820be0000                     mov    DWORD PTR [eax+0xbe20],ecx
0x493ab1     ba80464900                       mov    edx,0x494680
0x493ab6     899028be0000                     mov    DWORD PTR [eax+0xbe28],edx
0x493abc     89b02cbe0000                     mov    DWORD PTR [eax+0xbe2c],esi
0x493ac2     898830be0000                     mov    DWORD PTR [eax+0xbe30],ecx
0x493ac8     ba80464900                       mov    edx,0x494680
0x493acd     8990c8be0000                     mov    DWORD PTR [eax+0xbec8],edx
0x493ad3     89b0ccbe0000                     mov    DWORD PTR [eax+0xbecc],esi
0x493ad9     8988d0be0000                     mov    DWORD PTR [eax+0xbed0],ecx
0x493adf     ba80464900                       mov    edx,0x494680
0x493ae4     8990e8be0000                     mov    DWORD PTR [eax+0xbee8],edx
0x493aea     89b0ecbe0000                     mov    DWORD PTR [eax+0xbeec],esi
0x493af0     8988f0be0000                     mov    DWORD PTR [eax+0xbef0],ecx
0x493af6     ba80464900                       mov    edx,0x494680
0x493afb     8990d8be0000                     mov    DWORD PTR [eax+0xbed8],edx
0x493b01     89b0dcbe0000                     mov    DWORD PTR [eax+0xbedc],esi
0x493b07     8988e0be0000                     mov    DWORD PTR [eax+0xbee0],ecx
0x493b0d     ba80464900                       mov    edx,0x494680
0x493b12     899008100000                     mov    DWORD PTR [eax+0x1008],edx
0x493b18     89b00c100000                     mov    DWORD PTR [eax+0x100c],esi
0x493b1e     898810100000                     mov    DWORD PTR [eax+0x1010],ecx
0x493b24     ba10474900                       mov    edx,0x494710
0x493b29     8990080c0000                     mov    DWORD PTR [eax+0xc08],edx
0x493b2f     89b00c0c0000                     mov    DWORD PTR [eax+0xc0c],esi
0x493b35     8988100c0000                     mov    DWORD PTR [eax+0xc10],ecx
0x493b3b     ba10474900                       mov    edx,0x494710
0x493b40     8990f80b0000                     mov    DWORD PTR [eax+0xbf8],edx
0x493b46     89b0fc0b0000                     mov    DWORD PTR [eax+0xbfc],esi
0x493b4c     8988000c0000                     mov    DWORD PTR [eax+0xc00],ecx
0x493b52     ba10474900                       mov    edx,0x494710
0x493b57     8990180c0000                     mov    DWORD PTR [eax+0xc18],edx
0x493b5d     89b01c0c0000                     mov    DWORD PTR [eax+0xc1c],esi
0x493b63     8988200c0000                     mov    DWORD PTR [eax+0xc20],ecx
0x493b69     ba10474900                       mov    edx,0x494710
0x493b6e     8990380c0000                     mov    DWORD PTR [eax+0xc38],edx
0x493b74     89b03c0c0000                     mov    DWORD PTR [eax+0xc3c],esi
0x493b7a     8988400c0000                     mov    DWORD PTR [eax+0xc40],ecx
0x493b80     ba10474900                       mov    edx,0x494710
0x493b85     8990280c0000                     mov    DWORD PTR [eax+0xc28],edx
0x493b8b     89b02c0c0000                     mov    DWORD PTR [eax+0xc2c],esi
0x493b91     8988300c0000                     mov    DWORD PTR [eax+0xc30],ecx
0x493b97     ba70524900                       mov    edx,0x495270
0x493b9c     8990980d0000                     mov    DWORD PTR [eax+0xd98],edx
0x493ba2     89b09c0d0000                     mov    DWORD PTR [eax+0xd9c],esi
0x493ba8     8988a00d0000                     mov    DWORD PTR [eax+0xda0],ecx
0x493bae     ba70524900                       mov    edx,0x495270
0x493bb3     8990880d0000                     mov    DWORD PTR [eax+0xd88],edx
0x493bb9     89b08c0d0000                     mov    DWORD PTR [eax+0xd8c],esi
0x493bbf     8988900d0000                     mov    DWORD PTR [eax+0xd90],ecx
0x493bc5     ba80524900                       mov    edx,0x495280
0x493bca     8990b80d0000                     mov    DWORD PTR [eax+0xdb8],edx
0x493bd0     89b0bc0d0000                     mov    DWORD PTR [eax+0xdbc],esi
0x493bd6     8988c00d0000                     mov    DWORD PTR [eax+0xdc0],ecx
0x493bdc     bab0434900                       mov    edx,0x4943b0
0x493be1     8990480f0000                     mov    DWORD PTR [eax+0xf48],edx
0x493be7     89b04c0f0000                     mov    DWORD PTR [eax+0xf4c],esi
0x493bed     8988500f0000                     mov    DWORD PTR [eax+0xf50],ecx
0x493bf3     bab0434900                       mov    edx,0x4943b0
0x493bf8     8990f8be0000                     mov    DWORD PTR [eax+0xbef8],edx
0x493bfe     89b0fcbe0000                     mov    DWORD PTR [eax+0xbefc],esi
0x493c04     898800bf0000                     mov    DWORD PTR [eax+0xbf00],ecx
0x493c0a     bab0434900                       mov    edx,0x4943b0
0x493c0f     899048bf0000                     mov    DWORD PTR [eax+0xbf48],edx
0x493c15     89b04cbf0000                     mov    DWORD PTR [eax+0xbf4c],esi
0x493c1b     898850bf0000                     mov    DWORD PTR [eax+0xbf50],ecx
0x493c21     bab0434900                       mov    edx,0x4943b0
0x493c26     899008bf0000                     mov    DWORD PTR [eax+0xbf08],edx
0x493c2c     89b00cbf0000                     mov    DWORD PTR [eax+0xbf0c],esi
0x493c32     898810bf0000                     mov    DWORD PTR [eax+0xbf10],ecx
0x493c38     bab0434900                       mov    edx,0x4943b0
0x493c3d     8990780f0000                     mov    DWORD PTR [eax+0xf78],edx
0x493c43     89b07c0f0000                     mov    DWORD PTR [eax+0xf7c],esi
0x493c49     8988800f0000                     mov    DWORD PTR [eax+0xf80],ecx
0x493c4f     bab0434900                       mov    edx,0x4943b0
0x493c54     8990680f0000                     mov    DWORD PTR [eax+0xf68],edx
0x493c5a     89b06c0f0000                     mov    DWORD PTR [eax+0xf6c],esi
0x493c60     8988700f0000                     mov    DWORD PTR [eax+0xf70],ecx
0x493c66     bab0434900                       mov    edx,0x4943b0
0x493c6b     8990580f0000                     mov    DWORD PTR [eax+0xf58],edx
0x493c71     89b05c0f0000                     mov    DWORD PTR [eax+0xf5c],esi
0x493c77     bab0434900                       mov    edx,0x4943b0
0x493c7c     8988600f0000                     mov    DWORD PTR [eax+0xf60],ecx
0x493c82     899018100000                     mov    DWORD PTR [eax+0x1018],edx
0x493c88     89b01c100000                     mov    DWORD PTR [eax+0x101c],esi
0x493c8e     898820100000                     mov    DWORD PTR [eax+0x1020],ecx
0x493c94     ba805a4900                       mov    edx,0x495a80
0x493c99     8990c80f0000                     mov    DWORD PTR [eax+0xfc8],edx
0x493c9f     89b0cc0f0000                     mov    DWORD PTR [eax+0xfcc],esi
0x493ca5     8988d00f0000                     mov    DWORD PTR [eax+0xfd0],ecx
0x493cab     bab0434900                       mov    edx,0x4943b0
0x493cb0     899098100000                     mov    DWORD PTR [eax+0x1098],edx
0x493cb6     89b09c100000                     mov    DWORD PTR [eax+0x109c],esi
0x493cbc     8988a0100000                     mov    DWORD PTR [eax+0x10a0],ecx
0x493cc2     bab0434900                       mov    edx,0x4943b0
0x493cc7     899088100000                     mov    DWORD PTR [eax+0x1088],edx
0x493ccd     89b08c100000                     mov    DWORD PTR [eax+0x108c],esi
0x493cd3     898890100000                     mov    DWORD PTR [eax+0x1090],ecx
0x493cd9     bab0434900                       mov    edx,0x4943b0
0x493cde     8990a8100000                     mov    DWORD PTR [eax+0x10a8],edx
0x493ce4     89b0ac100000                     mov    DWORD PTR [eax+0x10ac],esi
0x493cea     8988b0100000                     mov    DWORD PTR [eax+0x10b0],ecx
0x493cf0     ba10474900                       mov    edx,0x494710
0x493cf5     8990f8100000                     mov    DWORD PTR [eax+0x10f8],edx
0x493cfb     89b0fc100000                     mov    DWORD PTR [eax+0x10fc],esi
0x493d01     898800110000                     mov    DWORD PTR [eax+0x1100],ecx
0x493d07     ba10474900                       mov    edx,0x494710
0x493d0c     899008110000                     mov    DWORD PTR [eax+0x1108],edx
0x493d12     89b00c110000                     mov    DWORD PTR [eax+0x110c],esi
0x493d18     898810110000                     mov    DWORD PTR [eax+0x1110],ecx
0x493d1e     ba10474900                       mov    edx,0x494710
0x493d23     899018110000                     mov    DWORD PTR [eax+0x1118],edx
0x493d29     89b01c110000                     mov    DWORD PTR [eax+0x111c],esi
0x493d2f     898820110000                     mov    DWORD PTR [eax+0x1120],ecx
0x493d35     ba10474900                       mov    edx,0x494710
0x493d3a     899028110000                     mov    DWORD PTR [eax+0x1128],edx
0x493d40     89b02c110000                     mov    DWORD PTR [eax+0x112c],esi
0x493d46     898830110000                     mov    DWORD PTR [eax+0x1130],ecx
0x493d4c     ba10474900                       mov    edx,0x494710
0x493d51     899038110000                     mov    DWORD PTR [eax+0x1138],edx
0x493d57     89b03c110000                     mov    DWORD PTR [eax+0x113c],esi
0x493d5d     898840110000                     mov    DWORD PTR [eax+0x1140],ecx
0x493d63     bab0434900                       mov    edx,0x4943b0
0x493d68     899048110000                     mov    DWORD PTR [eax+0x1148],edx
0x493d6e     89b04c110000                     mov    DWORD PTR [eax+0x114c],esi
0x493d74     898850110000                     mov    DWORD PTR [eax+0x1150],ecx
0x493d7a     ba905b4900                       mov    edx,0x495b90
0x493d7f     899058110000                     mov    DWORD PTR [eax+0x1158],edx
0x493d85     89b05c110000                     mov    DWORD PTR [eax+0x115c],esi
0x493d8b     898860110000                     mov    DWORD PTR [eax+0x1160],ecx
0x493d91     ba505c4900                       mov    edx,0x495c50
0x493d96     899068110000                     mov    DWORD PTR [eax+0x1168],edx
0x493d9c     89b06c110000                     mov    DWORD PTR [eax+0x116c],esi
0x493da2     898870110000                     mov    DWORD PTR [eax+0x1170],ecx
0x493da8     bae05f4900                       mov    edx,0x495fe0
0x493dad     899078110000                     mov    DWORD PTR [eax+0x1178],edx
0x493db3     89b07c110000                     mov    DWORD PTR [eax+0x117c],esi
0x493db9     898880110000                     mov    DWORD PTR [eax+0x1180],ecx
0x493dbf     baf05f4900                       mov    edx,0x495ff0
0x493dc4     899088110000                     mov    DWORD PTR [eax+0x1188],edx
0x493dca     89b08c110000                     mov    DWORD PTR [eax+0x118c],esi
0x493dd0     898890110000                     mov    DWORD PTR [eax+0x1190],ecx
0x493dd6     ba70624900                       mov    edx,0x496270
0x493ddb     8990a8110000                     mov    DWORD PTR [eax+0x11a8],edx
0x493de1     89b0ac110000                     mov    DWORD PTR [eax+0x11ac],esi
0x493de7     8988b0110000                     mov    DWORD PTR [eax+0x11b0],ecx
0x493ded     baf0624900                       mov    edx,0x4962f0
0x493df2     899098110000                     mov    DWORD PTR [eax+0x1198],edx
0x493df8     89b09c110000                     mov    DWORD PTR [eax+0x119c],esi
0x493dfe     8988a0110000                     mov    DWORD PTR [eax+0x11a0],ecx
0x493e04     ba70524900                       mov    edx,0x495270
0x493e09     8990e8110000                     mov    DWORD PTR [eax+0x11e8],edx
0x493e0f     89b0ec110000                     mov    DWORD PTR [eax+0x11ec],esi
0x493e15     8988f0110000                     mov    DWORD PTR [eax+0x11f0],ecx
0x493e1b     ba70524900                       mov    edx,0x495270
0x493e20     8990f8110000                     mov    DWORD PTR [eax+0x11f8],edx
0x493e26     89b0fc110000                     mov    DWORD PTR [eax+0x11fc],esi
0x493e2c     898800120000                     mov    DWORD PTR [eax+0x1200],ecx
0x493e32     ba70524900                       mov    edx,0x495270
0x493e37     899008120000                     mov    DWORD PTR [eax+0x1208],edx
0x493e3d     89b00c120000                     mov    DWORD PTR [eax+0x120c],esi
0x493e43     898810120000                     mov    DWORD PTR [eax+0x1210],ecx
0x493e49     ba80634900                       mov    edx,0x496380
0x493e4e     899058120000                     mov    DWORD PTR [eax+0x1258],edx
0x493e54     89b05c120000                     mov    DWORD PTR [eax+0x125c],esi
0x493e5a     898860120000                     mov    DWORD PTR [eax+0x1260],ecx
0x493e60     bab0434900                       mov    edx,0x4943b0
0x493e65     899078120000                     mov    DWORD PTR [eax+0x1278],edx
0x493e6b     89b07c120000                     mov    DWORD PTR [eax+0x127c],esi
0x493e71     898880120000                     mov    DWORD PTR [eax+0x1280],ecx
0x493e77     bab0434900                       mov    edx,0x4943b0
0x493e7c     899088120000                     mov    DWORD PTR [eax+0x1288],edx
0x493e82     89b08c120000                     mov    DWORD PTR [eax+0x128c],esi
0x493e88     898890120000                     mov    DWORD PTR [eax+0x1290],ecx
0x493e8e     baf0454900                       mov    edx,0x4945f0
0x493e93     899098120000                     mov    DWORD PTR [eax+0x1298],edx
0x493e99     89b09c120000                     mov    DWORD PTR [eax+0x129c],esi
0x493e9f     8988a0120000                     mov    DWORD PTR [eax+0x12a0],ecx
0x493ea5     baf0454900                       mov    edx,0x4945f0
0x493eaa     8990a8120000                     mov    DWORD PTR [eax+0x12a8],edx
0x493eb0     89b0ac120000                     mov    DWORD PTR [eax+0x12ac],esi
0x493eb6     8988b0120000                     mov    DWORD PTR [eax+0x12b0],ecx
0x493ebc     baf0454900                       mov    edx,0x4945f0
0x493ec1     8990b8120000                     mov    DWORD PTR [eax+0x12b8],edx
0x493ec7     89b0bc120000                     mov    DWORD PTR [eax+0x12bc],esi
0x493ecd     8988c0120000                     mov    DWORD PTR [eax+0x12c0],ecx
0x493ed3     baf0454900                       mov    edx,0x4945f0
0x493ed8     8990c8120000                     mov    DWORD PTR [eax+0x12c8],edx
0x493ede     89b0cc120000                     mov    DWORD PTR [eax+0x12cc],esi
0x493ee4     8988d0120000                     mov    DWORD PTR [eax+0x12d0],ecx
0x493eea     ba50654900                       mov    edx,0x496550
0x493eef     899018bf0000                     mov    DWORD PTR [eax+0xbf18],edx
0x493ef5     89b01cbf0000                     mov    DWORD PTR [eax+0xbf1c],esi
0x493efb     898820bf0000                     mov    DWORD PTR [eax+0xbf20],ecx
0x493f01     bab0654900                       mov    edx,0x4965b0
0x493f06     8990d8120000                     mov    DWORD PTR [eax+0x12d8],edx
0x493f0c     89b0dc120000                     mov    DWORD PTR [eax+0x12dc],esi
0x493f12     8988e0120000                     mov    DWORD PTR [eax+0x12e0],ecx
0x493f18     baa0664900                       mov    edx,0x4966a0
0x493f1d     8990e8120000                     mov    DWORD PTR [eax+0x12e8],edx
0x493f23     89b0ec120000                     mov    DWORD PTR [eax+0x12ec],esi
0x493f29     8988f0120000                     mov    DWORD PTR [eax+0x12f0],ecx
0x493f2f     ba206a4900                       mov    edx,0x496a20
0x493f34     899038130000                     mov    DWORD PTR [eax+0x1338],edx
0x493f3a     89b03c130000                     mov    DWORD PTR [eax+0x133c],esi
0x493f40     898840130000                     mov    DWORD PTR [eax+0x1340],ecx
0x493f46     ba407d4900                       mov    edx,0x497d40
0x493f4b     899048130000                     mov    DWORD PTR [eax+0x1348],edx
0x493f51     89b04c130000                     mov    DWORD PTR [eax+0x134c],esi
0x493f57     898850130000                     mov    DWORD PTR [eax+0x1350],ecx
0x493f5d     ba606f4900                       mov    edx,0x496f60
0x493f62     8990a8130000                     mov    DWORD PTR [eax+0x13a8],edx
0x493f68     89b0ac130000                     mov    DWORD PTR [eax+0x13ac],esi
0x493f6e     8988b0130000                     mov    DWORD PTR [eax+0x13b0],ecx
0x493f74     ba70524900                       mov    edx,0x495270
0x493f79     8990b8130000                     mov    DWORD PTR [eax+0x13b8],edx
0x493f7f     89b0bc130000                     mov    DWORD PTR [eax+0x13bc],esi
0x493f85     8988c0130000                     mov    DWORD PTR [eax+0x13c0],ecx
0x493f8b     ba70524900                       mov    edx,0x495270
0x493f90     8990c8130000                     mov    DWORD PTR [eax+0x13c8],edx
0x493f96     89b0cc130000                     mov    DWORD PTR [eax+0x13cc],esi
0x493f9c     8988d0130000                     mov    DWORD PTR [eax+0x13d0],ecx
0x493fa2     bae0704900                       mov    edx,0x4970e0
0x493fa7     8990e8130000                     mov    DWORD PTR [eax+0x13e8],edx
0x493fad     89b0ec130000                     mov    DWORD PTR [eax+0x13ec],esi
0x493fb3     8988f0130000                     mov    DWORD PTR [eax+0x13f0],ecx
0x493fb9     bab0434900                       mov    edx,0x4943b0
0x493fbe     8990f8130000                     mov    DWORD PTR [eax+0x13f8],edx
0x493fc4     89b0fc130000                     mov    DWORD PTR [eax+0x13fc],esi
0x493fca     898800140000                     mov    DWORD PTR [eax+0x1400],ecx
0x493fd0     bab0434900                       mov    edx,0x4943b0
0x493fd5     899008140000                     mov    DWORD PTR [eax+0x1408],edx
0x493fdb     89b00c140000                     mov    DWORD PTR [eax+0x140c],esi
0x493fe1     898810140000                     mov    DWORD PTR [eax+0x1410],ecx
0x493fe7     bab0434900                       mov    edx,0x4943b0
0x493fec     899038bf0000                     mov    DWORD PTR [eax+0xbf38],edx
0x493ff2     89b03cbf0000                     mov    DWORD PTR [eax+0xbf3c],esi
0x493ff8     898840bf0000                     mov    DWORD PTR [eax+0xbf40],ecx
0x493ffe     bab0434900                       mov    edx,0x4943b0
0x494003     899068140000                     mov    DWORD PTR [eax+0x1468],edx
0x494009     89b06c140000                     mov    DWORD PTR [eax+0x146c],esi
0x49400f     898870140000                     mov    DWORD PTR [eax+0x1470],ecx
0x494015     bab0434900                       mov    edx,0x4943b0
0x49401a     899078140000                     mov    DWORD PTR [eax+0x1478],edx
0x494020     89b07c140000                     mov    DWORD PTR [eax+0x147c],esi
0x494026     898880140000                     mov    DWORD PTR [eax+0x1480],ecx
0x49402c     bab0434900                       mov    edx,0x4943b0
0x494031     899088140000                     mov    DWORD PTR [eax+0x1488],edx
0x494037     89b08c140000                     mov    DWORD PTR [eax+0x148c],esi
0x49403d     898890140000                     mov    DWORD PTR [eax+0x1490],ecx
0x494043     bab0434900                       mov    edx,0x4943b0
0x494048     899098140000                     mov    DWORD PTR [eax+0x1498],edx
0x49404e     89b09c140000                     mov    DWORD PTR [eax+0x149c],esi
0x494054     8988a0140000                     mov    DWORD PTR [eax+0x14a0],ecx
0x49405a     bab0434900                       mov    edx,0x4943b0
0x49405f     899038140000                     mov    DWORD PTR [eax+0x1438],edx
0x494065     89b03c140000                     mov    DWORD PTR [eax+0x143c],esi
0x49406b     898840140000                     mov    DWORD PTR [eax+0x1440],ecx
0x494071     bab0434900                       mov    edx,0x4943b0
0x494076     899048140000                     mov    DWORD PTR [eax+0x1448],edx
0x49407c     89b04c140000                     mov    DWORD PTR [eax+0x144c],esi
0x494082     898850140000                     mov    DWORD PTR [eax+0x1450],ecx
0x494088     ba60434900                       mov    edx,0x494360
0x49408d     8990a8140000                     mov    DWORD PTR [eax+0x14a8],edx
0x494093     89b0ac140000                     mov    DWORD PTR [eax+0x14ac],esi
0x494099     8988b0140000                     mov    DWORD PTR [eax+0x14b0],ecx
0x49409f     bab0434900                       mov    edx,0x4943b0
0x4940a4     8990b8140000                     mov    DWORD PTR [eax+0x14b8],edx
0x4940aa     89b0bc140000                     mov    DWORD PTR [eax+0x14bc],esi
0x4940b0     8988c0140000                     mov    DWORD PTR [eax+0x14c0],ecx
0x4940b6     bab0434900                       mov    edx,0x4943b0
0x4940bb     8990c8140000                     mov    DWORD PTR [eax+0x14c8],edx
0x4940c1     89b0cc140000                     mov    DWORD PTR [eax+0x14cc],esi
0x4940c7     8988d0140000                     mov    DWORD PTR [eax+0x14d0],ecx
0x4940cd     bab0434900                       mov    edx,0x4943b0
0x4940d2     8990d8140000                     mov    DWORD PTR [eax+0x14d8],edx
0x4940d8     89b0dc140000                     mov    DWORD PTR [eax+0x14dc],esi
0x4940de     8988e0140000                     mov    DWORD PTR [eax+0x14e0],ecx
0x4940e4     bab0434900                       mov    edx,0x4943b0
0x4940e9     8990e8140000                     mov    DWORD PTR [eax+0x14e8],edx
0x4940ef     89b0ec140000                     mov    DWORD PTR [eax+0x14ec],esi
0x4940f5     8988f0140000                     mov    DWORD PTR [eax+0x14f0],ecx
0x4940fb     ba90774900                       mov    edx,0x497790
0x494100     8990f8140000                     mov    DWORD PTR [eax+0x14f8],edx
0x494106     89b0fc140000                     mov    DWORD PTR [eax+0x14fc],esi
0x49410c     898800150000                     mov    DWORD PTR [eax+0x1500],ecx
0x494112     bab0434900                       mov    edx,0x4943b0
0x494117     899008150000                     mov    DWORD PTR [eax+0x1508],edx
0x49411d     89b00c150000                     mov    DWORD PTR [eax+0x150c],esi
0x494123     898810150000                     mov    DWORD PTR [eax+0x1510],ecx
0x494129     bab0434900                       mov    edx,0x4943b0
0x49412e     899028150000                     mov    DWORD PTR [eax+0x1528],edx
0x494134     89b02c150000                     mov    DWORD PTR [eax+0x152c],esi
0x49413a     898830150000                     mov    DWORD PTR [eax+0x1530],ecx
0x494140     bab0434900                       mov    edx,0x4943b0
0x494145     899038150000                     mov    DWORD PTR [eax+0x1538],edx
0x49414b     89b03c150000                     mov    DWORD PTR [eax+0x153c],esi
0x494151     898840150000                     mov    DWORD PTR [eax+0x1540],ecx
0x494157     bab0434900                       mov    edx,0x4943b0
0x49415c     899048150000                     mov    DWORD PTR [eax+0x1548],edx
0x494162     89b04c150000                     mov    DWORD PTR [eax+0x154c],esi
0x494168     898850150000                     mov    DWORD PTR [eax+0x1550],ecx
0x49416e     bab0434900                       mov    edx,0x4943b0
0x494173     899078150000                     mov    DWORD PTR [eax+0x1578],edx
0x494179     89b07c150000                     mov    DWORD PTR [eax+0x157c],esi
0x49417f     898880150000                     mov    DWORD PTR [eax+0x1580],ecx
0x494185     bab0434900                       mov    edx,0x4943b0
0x49418a     899088150000                     mov    DWORD PTR [eax+0x1588],edx
0x494190     89b08c150000                     mov    DWORD PTR [eax+0x158c],esi
0x494196     898890150000                     mov    DWORD PTR [eax+0x1590],ecx
0x49419c     bab0434900                       mov    edx,0x4943b0
0x4941a1     899098150000                     mov    DWORD PTR [eax+0x1598],edx
0x4941a7     89b09c150000                     mov    DWORD PTR [eax+0x159c],esi
0x4941ad     8988a0150000                     mov    DWORD PTR [eax+0x15a0],ecx
0x4941b3     bab0434900                       mov    edx,0x4943b0
0x4941b8     8990a8150000                     mov    DWORD PTR [eax+0x15a8],edx
0x4941be     89b0ac150000                     mov    DWORD PTR [eax+0x15ac],esi
0x4941c4     8988b0150000                     mov    DWORD PTR [eax+0x15b0],ecx
0x4941ca     bab0434900                       mov    edx,0x4943b0
0x4941cf     899018160000                     mov    DWORD PTR [eax+0x1618],edx
0x4941d5     89b01c160000                     mov    DWORD PTR [eax+0x161c],esi
0x4941db     898820160000                     mov    DWORD PTR [eax+0x1620],ecx
0x4941e1     bab0434900                       mov    edx,0x4943b0
0x4941e6     899028160000                     mov    DWORD PTR [eax+0x1628],edx
0x4941ec     89b02c160000                     mov    DWORD PTR [eax+0x162c],esi
0x4941f2     898830160000                     mov    DWORD PTR [eax+0x1630],ecx
0x4941f8     bab0434900                       mov    edx,0x4943b0
0x4941fd     899008160000                     mov    DWORD PTR [eax+0x1608],edx
0x494203     89b00c160000                     mov    DWORD PTR [eax+0x160c],esi
0x494209     898810160000                     mov    DWORD PTR [eax+0x1610],ecx
0x49420f     bab0434900                       mov    edx,0x4943b0
0x494214     899058150000                     mov    DWORD PTR [eax+0x1558],edx
0x49421a     89b05c150000                     mov    DWORD PTR [eax+0x155c],esi
0x494220     898860150000                     mov    DWORD PTR [eax+0x1560],ecx
0x494226     bab0434900                       mov    edx,0x4943b0
0x49422b     899058140000                     mov    DWORD PTR [eax+0x1458],edx
0x494231     89b05c140000                     mov    DWORD PTR [eax+0x145c],esi
0x494237     898860140000                     mov    DWORD PTR [eax+0x1460],ecx
0x49423d     ba80464900                       mov    edx,0x494680
0x494242     899038160000                     mov    DWORD PTR [eax+0x1638],edx
0x494248     89b03c160000                     mov    DWORD PTR [eax+0x163c],esi
0x49424e     898840160000                     mov    DWORD PTR [eax+0x1640],ecx
0x494254     ba80464900                       mov    edx,0x494680
0x494259     899048160000                     mov    DWORD PTR [eax+0x1648],edx
0x49425f     89b04c160000                     mov    DWORD PTR [eax+0x164c],esi
0x494265     898850160000                     mov    DWORD PTR [eax+0x1650],ecx
0x49426b     bab0434900                       mov    edx,0x4943b0
0x494270     899068160000                     mov    DWORD PTR [eax+0x1668],edx
0x494276     89b06c160000                     mov    DWORD PTR [eax+0x166c],esi
0x49427c     898870160000                     mov    DWORD PTR [eax+0x1670],ecx
0x494282     bab0434900                       mov    edx,0x4943b0
0x494287     8990a8160000                     mov    DWORD PTR [eax+0x16a8],edx
0x49428d     89b0ac160000                     mov    DWORD PTR [eax+0x16ac],esi
0x494293     8988b0160000                     mov    DWORD PTR [eax+0x16b0],ecx
0x494299     bab0434900                       mov    edx,0x4943b0
0x49429e     899078160000                     mov    DWORD PTR [eax+0x1678],edx
0x4942a4     89b07c160000                     mov    DWORD PTR [eax+0x167c],esi
0x4942aa     898880160000                     mov    DWORD PTR [eax+0x1680],ecx
0x4942b0     bab0434900                       mov    edx,0x4943b0
0x4942b5     899088160000                     mov    DWORD PTR [eax+0x1688],edx
0x4942bb     89b08c160000                     mov    DWORD PTR [eax+0x168c],esi
0x4942c1     898890160000                     mov    DWORD PTR [eax+0x1690],ecx
0x4942c7     bab0434900                       mov    edx,0x4943b0
0x4942cc     8990c8160000                     mov    DWORD PTR [eax+0x16c8],edx
0x4942d2     89b0cc160000                     mov    DWORD PTR [eax+0x16cc],esi
0x4942d8     8988d0160000                     mov    DWORD PTR [eax+0x16d0],ecx
0x4942de     bab0434900                       mov    edx,0x4943b0
0x4942e3     8990d8160000                     mov    DWORD PTR [eax+0x16d8],edx
0x4942e9     89b0dc160000                     mov    DWORD PTR [eax+0x16dc],esi
0x4942ef     8988e0160000                     mov    DWORD PTR [eax+0x16e0],ecx
0x4942f5     bab0434900                       mov    edx,0x4943b0
0x4942fa     8990e8160000                     mov    DWORD PTR [eax+0x16e8],edx
0x494300     89b0ec160000                     mov    DWORD PTR [eax+0x16ec],esi
0x494306     8988f0160000                     mov    DWORD PTR [eax+0x16f0],ecx
0x49430c     bab0434900                       mov    edx,0x4943b0
0x494311     899008170000                     mov    DWORD PTR [eax+0x1708],edx
0x494317     89b00c170000                     mov    DWORD PTR [eax+0x170c],esi
0x49431d     898810170000                     mov    DWORD PTR [eax+0x1710],ecx
0x494323     bab0434900                       mov    edx,0x4943b0
0x494328     8990c8110000                     mov    DWORD PTR [eax+0x11c8],edx
0x49432e     89b0cc110000                     mov    DWORD PTR [eax+0x11cc],esi
0x494334     8988d0110000                     mov    DWORD PTR [eax+0x11d0],ecx
0x49433a     bab0434900                       mov    edx,0x4943b0
0x49433f     8990d8110000                     mov    DWORD PTR [eax+0x11d8],edx
0x494345     5f                               pop    edi
0x494346     89b0dc110000                     mov    DWORD PTR [eax+0x11dc],esi
0x49434c     5e                               pop    esi
0x49434d     8988e0110000                     mov    DWORD PTR [eax+0x11e0],ecx
0x494353     5b                               pop    ebx
0x494354     c3                               ret
0x494355     cc                               int3

; tutorial_delete_registrar 0x4ab580..0x4ab61a raw=0xaa980 SHA256=ff45e9a5d83abbd9aa78db593af45fcc6aee4efd78b021a3624112f7969eb78f
0x4ab580     55                               push   ebp
0x4ab581     8bec                             mov    ebp,esp
0x4ab583     8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4ab586     53                               push   ebx
0x4ab587     8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
0x4ab58d     56                               push   esi
0x4ab58e     8b33                             mov    esi,DWORD PTR [ebx]
0x4ab590     57                               push   edi
0x4ab591     8b38                             mov    edi,DWORD PTR [eax]
0x4ab593     b8eed8ffff                       mov    eax,0xffffd8ee
0x4ab598     c7056818fe00e09f4a00             mov    DWORD PTR ds:0xfe1868,0x4a9fe0
0x4ab5a2     e8d9a02400                       call   0x6f5680
0x4ab5a7     8b03                             mov    eax,DWORD PTR [ebx]
0x4ab5a9     8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x4ab5ac     83e810                           sub    eax,0x10
0x4ab5af     3dc8bfc000                       cmp    eax,0xc0bfc8
0x4ab5b4     7406                             je     0x4ab5bc
0x4ab5b6     83780805                         cmp    DWORD PTR [eax+0x8],0x5
0x4ab5ba     7414                             je     0x4ab5d0
0x4ab5bc     57                               push   edi
0x4ab5bd     68c426c400                       push   0xc426c4
0x4ab5c2     e8f67a3e00                       call   0x8930bd
0x4ab5c7     8b1b                             mov    ebx,DWORD PTR [ebx]
0x4ab5c9     83c408                           add    esp,0x8
0x4ab5cc     834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
0x4ab5d0     8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
0x4ab5d6     8b37                             mov    esi,DWORD PTR [edi]
0x4ab5d8     6814add600                       push   0xd6ad14
0x4ab5dd     e82e9f2400                       call   0x6f5510
0x4ab5e2     8b37                             mov    esi,DWORD PTR [edi]
0x4ab5e4     83c404                           add    esp,0x4
0x4ab5e7     6a00                             push   0x0
0x4ab5e9     68d0c74a00                       push   0x4ac7d0
0x4ab5ee     e8bd9f2400                       call   0x6f55b0
0x4ab5f3     8b0f                             mov    ecx,DWORD PTR [edi]
0x4ab5f5     51                               push   ecx
0x4ab5f6     b8fdffffff                       mov    eax,0xfffffffd
0x4ab5fb     e8f0a12400                       call   0x6f57f0
0x4ab600     8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
0x4ab606     8b02                             mov    eax,DWORD PTR [edx]
0x4ab608     83c40c                           add    esp,0xc
0x4ab60b     834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
0x4ab60f     8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4ab612     5f                               pop    edi
0x4ab613     5e                               pop    esi
0x4ab614     5b                               pop    ebx
0x4ab615     5d                               pop    ebp
0x4ab616     c20400                           ret    0x4
0x4ab619     cc                               int3

; tutorial_delete_closure 0x4ac7d0..0x4ac82c raw=0xabbd0 SHA256=c6506e7175fa2296ef07be9a992df0bebeedd6cdf0fd2ce6f2eadbed309c6d1c
0x4ac7d0     55                               push   ebp
0x4ac7d1     8bec                             mov    ebp,esp
0x4ac7d3     6aff                             push   0xffffffff
0x4ac7d5     68c8839300                       push   0x9383c8
0x4ac7da     64a100000000                     mov    eax,fs:0x0
0x4ac7e0     50                               push   eax
0x4ac7e1     83ec0c                           sub    esp,0xc
0x4ac7e4     a1201fd600                       mov    eax,ds:0xd61f20
0x4ac7e9     33c5                             xor    eax,ebp
0x4ac7eb     50                               push   eax
0x4ac7ec     8d45f4                           lea    eax,[ebp-0xc]
0x4ac7ef     64a300000000                     mov    fs:0x0,eax
0x4ac7f5     8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4ac7f8     8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x4ac7fb     33c0                             xor    eax,eax
0x4ac7fd     8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x4ac800     8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x4ac803     8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x4ac806     8b0d6818fe00                     mov    ecx,DWORD PTR ds:0xfe1868
0x4ac80c     51                               push   ecx
0x4ac80d     8d45e8                           lea    eax,[ebp-0x18]
0x4ac810     e85b030000                       call   0x4acb70
0x4ac815     83c404                           add    esp,0x4
0x4ac818     b801000000                       mov    eax,0x1
0x4ac81d     8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4ac820     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4ac827     59                               pop    ecx
0x4ac828     8be5                             mov    esp,ebp
0x4ac82a     5d                               pop    ebp
0x4ac82b     c3                               ret

; controller_slot_get 0x545290..0x5452ac raw=0x144690 SHA256=3655bd98c5647734210172057589ff991795bf2a451d8707908727dd660b9f4b
0x545290     55                               push   ebp
0x545291     8bec                             mov    ebp,esp
0x545293     8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x545296     83f802                           cmp    eax,0x2
0x545299     770b                             ja     0x5452a6
0x54529b     8d444003                         lea    eax,[eax+eax*2+0x3]
0x54529f     8b0481                           mov    eax,DWORD PTR [ecx+eax*4]
0x5452a2     5d                               pop    ebp
0x5452a3     c20400                           ret    0x4
0x5452a6     33c0                             xor    eax,eax
0x5452a8     5d                               pop    ebp
0x5452a9     c20400                           ret    0x4

; point_clear 0x5449a0..0x544a00 raw=0x143da0 SHA256=f6ad4aff258ed89dcd0611e6e7c6f766027b04bc35a56d782102c5ace3d795cf
0x5449a0     55                               push   ebp
0x5449a1     8bec                             mov    ebp,esp
0x5449a3     53                               push   ebx
0x5449a4     8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x5449a7     56                               push   esi
0x5449a8     8b7304                           mov    esi,DWORD PTR [ebx+0x4]
0x5449ab     3b7308                           cmp    esi,DWORD PTR [ebx+0x8]
0x5449ae     741f                             je     0x5449cf
0x5449b0     8b0e                             mov    ecx,DWORD PTR [esi]
0x5449b2     8b01                             mov    eax,DWORD PTR [ecx]
0x5449b4     8b5014                           mov    edx,DWORD PTR [eax+0x14]
0x5449b7     ffd2                             call   edx
0x5449b9     8b0e                             mov    ecx,DWORD PTR [esi]
0x5449bb     85c9                             test   ecx,ecx
0x5449bd     7408                             je     0x5449c7
0x5449bf     8b01                             mov    eax,DWORD PTR [ecx]
0x5449c1     8b10                             mov    edx,DWORD PTR [eax]
0x5449c3     6a01                             push   0x1
0x5449c5     ffd2                             call   edx
0x5449c7     83c604                           add    esi,0x4
0x5449ca     3b7308                           cmp    esi,DWORD PTR [ebx+0x8]
0x5449cd     75e1                             jne    0x5449b0
0x5449cf     8b4b08                           mov    ecx,DWORD PTR [ebx+0x8]
0x5449d2     8b7304                           mov    esi,DWORD PTR [ebx+0x4]
0x5449d5     3bf1                             cmp    esi,ecx
0x5449d7     7420                             je     0x5449f9
0x5449d9     8bc1                             mov    eax,ecx
0x5449db     2bc1                             sub    eax,ecx
0x5449dd     57                               push   edi
0x5449de     c1f802                           sar    eax,0x2
0x5449e1     8d3c8500000000                   lea    edi,[eax*4+0x0]
0x5449e8     57                               push   edi
0x5449e9     51                               push   ecx
0x5449ea     56                               push   esi
0x5449eb     e800c93400                       call   0x8912f0
0x5449f0     83c40c                           add    esp,0xc
0x5449f3     03fe                             add    edi,esi
0x5449f5     897b08                           mov    DWORD PTR [ebx+0x8],edi
0x5449f8     5f                               pop    edi
0x5449f9     5e                               pop    esi
0x5449fa     5b                               pop    ebx
0x5449fb     5d                               pop    ebp
0x5449fc     c20400                           ret    0x4
0x5449ff     cc                               int3

; state_dead_update 0x4cb710..0x4cb7d0 raw=0xcab10 SHA256=e93a33eba2c76f4a4e26266a34a1ba14f98f850f6b8cd550b9fdee86f74ae8e9
0x4cb710     55                               push   ebp
0x4cb711     8bec                             mov    ebp,esp
0x4cb713     83e4f8                           and    esp,0xfffffff8
0x4cb716     83ec18                           sub    esp,0x18
0x4cb719     56                               push   esi
0x4cb71a     57                               push   edi
0x4cb71b     8bf9                             mov    edi,ecx
0x4cb71d     8b7704                           mov    esi,DWORD PTR [edi+0x4]
0x4cb720     e88be3ffff                       call   0x4c9ab0
0x4cb725     dd052058c500                     fld    QWORD PTR ds:0xc55820
0x4cb72b     d9c9                             fxch   st(1)
0x4cb72d     dff1                             fcomip st,st(1)
0x4cb72f     ddd8                             fstp   st(0)
0x4cb731     0f868a000000                     jbe    0x4cb7c1
0x4cb737     d94738                           fld    DWORD PTR [edi+0x38]
0x4cb73a     f30f1005c056c400                 movss  xmm0,DWORD PTR ds:0xc456c0
0x4cb742     d84508                           fadd   DWORD PTR [ebp+0x8]
0x4cb745     d95c240c                         fstp   DWORD PTR [esp+0xc]
0x4cb749     d944240c                         fld    DWORD PTR [esp+0xc]
0x4cb74d     d95738                           fst    DWORD PTR [edi+0x38]
0x4cb750     d9e8                             fld1
0x4cb752     d9c9                             fxch   st(1)
0x4cb754     dff1                             fcomip st,st(1)
0x4cb756     ddd8                             fstp   st(0)
0x4cb758     7605                             jbe    0x4cb75f
0x4cb75a     f30f114738                       movss  DWORD PTR [edi+0x38],xmm0
0x4cb75f     f30f104f38                       movss  xmm1,DWORD PTR [edi+0x38]
0x4cb764     0f2f0d0c7dc000                   comiss xmm1,DWORD PTR ds:0xc07d0c
0x4cb76b     f30f114c240c                     movss  DWORD PTR [esp+0xc],xmm1
0x4cb771     764e                             jbe    0x4cb7c1
0x4cb773     d944240c                         fld    DWORD PTR [esp+0xc]
0x4cb777     8b7704                           mov    esi,DWORD PTR [edi+0x4]
0x4cb77a     dc25b056c500                     fsub   QWORD PTR ds:0xc556b0
0x4cb780     83ec10                           sub    esp,0x10
0x4cb783     8bc4                             mov    eax,esp
0x4cb785     f30f11442420                     movss  DWORD PTR [esp+0x20],xmm0
0x4cb78b     8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
0x4cb78f     dcc0                             fadd   st(0),st
0x4cb791     d9e8                             fld1
0x4cb793     8908                             mov    DWORD PTR [eax],ecx
0x4cb795     f30f11442424                     movss  DWORD PTR [esp+0x24],xmm0
0x4cb79b     dee1                             fsubrp st(1),st
0x4cb79d     8b542424                         mov    edx,DWORD PTR [esp+0x24]
0x4cb7a1     895004                           mov    DWORD PTR [eax+0x4],edx
0x4cb7a4     f30f11442428                     movss  DWORD PTR [esp+0x28],xmm0
0x4cb7aa     8b4c2428                         mov    ecx,DWORD PTR [esp+0x28]
0x4cb7ae     d95c242c                         fstp   DWORD PTR [esp+0x2c]
0x4cb7b2     8b54242c                         mov    edx,DWORD PTR [esp+0x2c]
0x4cb7b6     894808                           mov    DWORD PTR [eax+0x8],ecx
0x4cb7b9     89500c                           mov    DWORD PTR [eax+0xc],edx
0x4cb7bc     e89fe2ffff                       call   0x4c9a60
0x4cb7c1     5f                               pop    edi
0x4cb7c2     5e                               pop    esi
0x4cb7c3     8be5                             mov    esp,ebp
0x4cb7c5     5d                               pop    ebp
0x4cb7c6     c20400                           ret    0x4
0x4cb7c9     cc                               int3
0x4cb7ca     cc                               int3
0x4cb7cb     cc                               int3
0x4cb7cc     cc                               int3
0x4cb7cd     cc                               int3
0x4cb7ce     cc                               int3
0x4cb7cf     cc                               int3

; state_dead_enter 0x4cb590..0x4cb710 raw=0xca990 SHA256=9917db82c62b8039619de6749d575bad7cf2565c83f9c73d060d616f95827610
0x4cb590     55                               push   ebp
0x4cb591     8bec                             mov    ebp,esp
0x4cb593     6aff                             push   0xffffffff
0x4cb595     68ac9e9300                       push   0x939eac
0x4cb59a     64a100000000                     mov    eax,fs:0x0
0x4cb5a0     50                               push   eax
0x4cb5a1     83ec14                           sub    esp,0x14
0x4cb5a4     a1201fd600                       mov    eax,ds:0xd61f20
0x4cb5a9     33c5                             xor    eax,ebp
0x4cb5ab     8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x4cb5ae     53                               push   ebx
0x4cb5af     56                               push   esi
0x4cb5b0     57                               push   edi
0x4cb5b1     50                               push   eax
0x4cb5b2     8d45f4                           lea    eax,[ebp-0xc]
0x4cb5b5     64a300000000                     mov    fs:0x0,eax
0x4cb5bb     f60500b1fa0001                   test   BYTE PTR ds:0xfab100,0x1
0x4cb5c2     8bd9                             mov    ebx,ecx
0x4cb5c4     8b7304                           mov    esi,DWORD PTR [ebx+0x4]
0x4cb5c7     7527                             jne    0x4cb5f0
0x4cb5c9     830d00b1fa0001                   or     DWORD PTR ds:0xfab100,0x1
0x4cb5d0     c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x4cb5d7     e8c420fdff                       call   0x49d6a0
0x4cb5dc     6820cebc00                       push   0xbcce20
0x4cb5e1     e8346d3c00                       call   0x89231a
0x4cb5e6     83c404                           add    esp,0x4
0x4cb5e9     c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x4cb5f0     f60504b1fa0004                   test   BYTE PTR ds:0xfab104,0x4
0x4cb5f7     8bb688000000                     mov    esi,DWORD PTR [esi+0x88]
0x4cb5fd     7407                             je     0x4cb606
0x4cb5ff     8bfe                             mov    edi,esi
0x4cb601     e8da22fdff                       call   0x49d8e0
0x4cb606     8b4b04                           mov    ecx,DWORD PTR [ebx+0x4]
0x4cb609     d9e8                             fld1
0x4cb60b     8b01                             mov    eax,DWORD PTR [ecx]
0x4cb60d     8b5068                           mov    edx,DWORD PTR [eax+0x68]
0x4cb610     51                               push   ecx
0x4cb611     d91c24                           fstp   DWORD PTR [esp]
0x4cb614     6a07                             push   0x7
0x4cb616     ffd2                             call   edx
0x4cb618     8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0x4cb61b     50                               push   eax
0x4cb61c     e8efd9ffff                       call   0x4c9010
0x4cb621     0f57c0                           xorps  xmm0,xmm0
0x4cb624     8b4b04                           mov    ecx,DWORD PTR [ebx+0x4]
0x4cb627     f30f114338                       movss  DWORD PTR [ebx+0x38],xmm0
0x4cb62c     8b11                             mov    edx,DWORD PTR [ecx]
0x4cb62e     8b424c                           mov    eax,DWORD PTR [edx+0x4c]
0x4cb631     ffd0                             call   eax
0x4cb633     8b08                             mov    ecx,DWORD PTR [eax]
0x4cb635     894de4                           mov    DWORD PTR [ebp-0x1c],ecx
0x4cb638     8b5004                           mov    edx,DWORD PTR [eax+0x4]
0x4cb63b     8955e8                           mov    DWORD PTR [ebp-0x18],edx
0x4cb63e     8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x4cb641     8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x4cb644     8b4304                           mov    eax,DWORD PTR [ebx+0x4]
0x4cb647     8bb05c010000                     mov    esi,DWORD PTR [eax+0x15c]
0x4cb64d     85f6                             test   esi,esi
0x4cb64f     7413                             je     0x4cb664
0x4cb651     83b87003000000                   cmp    DWORD PTR [eax+0x370],0x0
0x4cb658     740a                             je     0x4cb664
0x4cb65a     e8a1ba2d00                       call   0x7a7100
0x4cb65f     d95de0                           fstp   DWORD PTR [ebp-0x20]
0x4cb662     eb08                             jmp    0x4cb66c
0x4cb664     0f57c0                           xorps  xmm0,xmm0
0x4cb667     f30f1145e0                       movss  DWORD PTR [ebp-0x20],xmm0
0x4cb66c     f605dcf6fd0001                   test   BYTE PTR ds:0xfdf6dc,0x1
0x4cb673     d945e0                           fld    DWORD PTR [ebp-0x20]
0x4cb676     dc0db056c500                     fmul   QWORD PTR ds:0xc556b0
0x4cb67c     8b4b04                           mov    ecx,DWORD PTR [ebx+0x4]
0x4cb67f     d845ec                           fadd   DWORD PTR [ebp-0x14]
0x4cb682     d95dec                           fstp   DWORD PTR [ebp-0x14]
0x4cb685     f30f1081b4000000                 movss  xmm0,DWORD PTR [ecx+0xb4]
0x4cb68d     f30f1145e0                       movss  DWORD PTR [ebp-0x20],xmm0
0x4cb692     7527                             jne    0x4cb6bb
0x4cb694     b801000000                       mov    eax,0x1
0x4cb699     0905dcf6fd00                     or     DWORD PTR ds:0xfdf6dc,eax
0x4cb69f     8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x4cb6a2     e879510800                       call   0x550820
0x4cb6a7     68b0e6bc00                       push   0xbce6b0
0x4cb6ac     e8696c3c00                       call   0x89231a
0x4cb6b1     83c404                           add    esp,0x4
0x4cb6b4     c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x4cb6bb     6aff                             push   0xffffffff
0x4cb6bd     6aff                             push   0xffffffff
0x4cb6bf     b97877c000                       mov    ecx,0xc07778
0x4cb6c4     ba80f6fd00                       mov    edx,0xfdf680
0x4cb6c9     e8b2640800                       call   0x551b80
0x4cb6ce     d945e0                           fld    DWORD PTR [ebp-0x20]
0x4cb6d1     6a01                             push   0x1
0x4cb6d3     83ec08                           sub    esp,0x8
0x4cb6d6     d95c2404                         fstp   DWORD PTR [esp+0x4]
0x4cb6da     8d55e4                           lea    edx,[ebp-0x1c]
0x4cb6dd     d9ee                             fldz
0x4cb6df     8bc8                             mov    ecx,eax
0x4cb6e1     d91c24                           fstp   DWORD PTR [esp]
0x4cb6e4     52                               push   edx
0x4cb6e5     6a00                             push   0x0
0x4cb6e7     6880f6fd00                       push   0xfdf680
0x4cb6ec     e8df660800                       call   0x551dd0
0x4cb6f1     8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4cb6f4     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4cb6fb     59                               pop    ecx
0x4cb6fc     5f                               pop    edi
0x4cb6fd     5e                               pop    esi
0x4cb6fe     5b                               pop    ebx
0x4cb6ff     8b4df0                           mov    ecx,DWORD PTR [ebp-0x10]
0x4cb702     33cd                             xor    ecx,ebp
0x4cb704     e8f8583c00                       call   0x891001
0x4cb709     8be5                             mov    esp,ebp
0x4cb70b     5d                               pop    ebp
0x4cb70c     c3                               ret
0x4cb70d     cc                               int3
0x4cb70e     cc                               int3
0x4cb70f     cc                               int3

; mission_secondary 0x4bc6e0..0x4bc750 raw=0xbbae0 SHA256=77cd615ad1ce0cae9c77d07298744ad097033ece2c14fceaed3e6a033967b874
0x4bc6e0     68a85e0000                       push   0x5ea8
0x4bc6e5     8d86ac5e0000                     lea    eax,[esi+0x5eac]
0x4bc6eb     6a00                             push   0x0
0x4bc6ed     50                               push   eax
0x4bc6ee     e86d213e00                       call   0x89e860
0x4bc6f3     b87523bf00                       mov    eax,0xbf2375
0x4bc6f8     83c40c                           add    esp,0xc
0x4bc6fb     c7864c5f000030594c00             mov    DWORD PTR [esi+0x5f4c],0x4c5930
0x4bc705     8986505f0000                     mov    DWORD PTR [esi+0x5f50],eax
0x4bc70b     c7867460000030c94b00             mov    DWORD PTR [esi+0x6074],0x4bc930
0x4bc715     898678600000                     mov    DWORD PTR [esi+0x6078],eax
0x4bc71b     c7867c600000a0584c00             mov    DWORD PTR [esi+0x607c],0x4c58a0
0x4bc725     898680600000                     mov    DWORD PTR [esi+0x6080],eax
0x4bc72b     c7863460000090ca4b00             mov    DWORD PTR [esi+0x6034],0x4bca90
0x4bc735     898638600000                     mov    DWORD PTR [esi+0x6038],eax
0x4bc73b     c7868460000090554c00             mov    DWORD PTR [esi+0x6084],0x4c5590
0x4bc745     898688600000                     mov    DWORD PTR [esi+0x6088],eax
0x4bc74b     c3                               ret
0x4bc74c     cc                               int3
0x4bc74d     cc                               int3
0x4bc74e     cc                               int3
0x4bc74f     cc                               int3

; scenario_secondary 0x4c46f0..0x4c4750 raw=0xc3af0 SHA256=8f998f48e982fbbe6256e2ee301e1f679f76032d55620b5f3b1c8c739840533b
0x4c46f0     8bc6                             mov    eax,esi
0x4c46f2     e85996feff                       call   0x4add50
0x4c46f7     68a85e0000                       push   0x5ea8
0x4c46fc     8d86ac5e0000                     lea    eax,[esi+0x5eac]
0x4c4702     6a00                             push   0x0
0x4c4704     50                               push   eax
0x4c4705     c706b473c000                     mov    DWORD PTR [esi],0xc073b4
0x4c470b     c70574a6d60046454353             mov    DWORD PTR ds:0xd6a674,0x53434546
0x4c4715     e846a13d00                       call   0x89e860
0x4c471a     b87523bf00                       mov    eax,0xbf2375
0x4c471f     8986505f0000                     mov    DWORD PTR [esi+0x5f50],eax
0x4c4725     8986205f0000                     mov    DWORD PTR [esi+0x5f20],eax
0x4c472b     83c40c                           add    esp,0xc
0x4c472e     c7864c5f000030594c00             mov    DWORD PTR [esi+0x5f4c],0x4c5930
0x4c4738     c7861c5f0000406c4300             mov    DWORD PTR [esi+0x5f1c],0x436c40
0x4c4742     8bc6                             mov    eax,esi
0x4c4744     c3                               ret
0x4c4745     cc                               int3
0x4c4746     cc                               int3
0x4c4747     cc                               int3
0x4c4748     cc                               int3
0x4c4749     cc                               int3
0x4c474a     cc                               int3
0x4c474b     cc                               int3
0x4c474c     cc                               int3
0x4c474d     cc                               int3
0x4c474e     cc                               int3
0x4c474f     cc                               int3

; field_dispatch 0x4c4670..0x4c46f0 raw=0xc3a70 SHA256=2deecc04ff570b803612ebcd2157d86b0659367b80cc081f6a10de1a9c8c5223
0x4c4670     55                               push   ebp
0x4c4671     8bec                             mov    ebp,esp
0x4c4673     8b4510                           mov    eax,DWORD PTR [ebp+0x10]
0x4c4676     53                               push   ebx
0x4c4677     56                               push   esi
0x4c4678     57                               push   edi
0x4c4679     0fbff8                           movsx  edi,ax
0x4c467c     8bf1                             mov    esi,ecx
0x4c467e     8b9cfeac5e0000                   mov    ebx,DWORD PTR [esi+edi*8+0x5eac]
0x4c4685     85db                             test   ebx,ebx
0x4c4687     7517                             jne    0x4c46a0
0x4c4689     8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x4c468c     50                               push   eax
0x4c468d     8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x4c4690     50                               push   eax
0x4c4691     51                               push   ecx
0x4c4692     8bce                             mov    ecx,esi
0x4c4694     e897930300                       call   0x4fda30
0x4c4699     5f                               pop    edi
0x4c469a     5e                               pop    esi
0x4c469b     5b                               pop    ebx
0x4c469c     5d                               pop    ebp
0x4c469d     c20c00                           ret    0xc
0x4c46a0     8b94feb05e0000                   mov    edx,DWORD PTR [esi+edi*8+0x5eb0]
0x4c46a7     6a06                             push   0x6
0x4c46a9     686c6cbf00                       push   0xbf6c6c
0x4c46ae     52                               push   edx
0x4c46af     e80ae23c00                       call   0x8928be
0x4c46b4     8b4510                           mov    eax,DWORD PTR [ebp+0x10]
0x4c46b7     8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0x4c46ba     8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0x4c46bd     83c40c                           add    esp,0xc
0x4c46c0     50                               push   eax
0x4c46c1     51                               push   ecx
0x4c46c2     52                               push   edx
0x4c46c3     8bce                             mov    ecx,esi
0x4c46c5     ffd3                             call   ebx
0x4c46c7     8bd8                             mov    ebx,eax
0x4c46c9     81fb05400080                     cmp    ebx,0x80004005
0x4c46cf     7516                             jne    0x4c46e7
0x4c46d1     8b84feb05e0000                   mov    eax,DWORD PTR [esi+edi*8+0x5eb0]
0x4c46d8     50                               push   eax
0x4c46d9     57                               push   edi
0x4c46da     68746cbf00                       push   0xbf6c74
0x4c46df     e87c942200                       call   0x6edb60
0x4c46e4     83c40c                           add    esp,0xc
0x4c46e7     5f                               pop    edi
0x4c46e8     5e                               pop    esi
0x4c46e9     8bc3                             mov    eax,ebx
0x4c46eb     5b                               pop    ebx
0x4c46ec     5d                               pop    ebp
0x4c46ed     c20c00                           ret    0xc

; common_ready_delegate 0x4c5930..0x4c5935 raw=0xc4d30 SHA256=87fdb8f5c96d84f261623daf2dcbc4e09b759ff4afac405e443e9d4cf0bb1554
0x4c5930     8b01                             mov    eax,DWORD PTR [ecx]
0x4c5932     ff602c                           jmp    DWORD PTR [eax+0x2c]

; world_accessor 0x40f060..0x40f0e5 raw=0xe460 SHA256=fc9bce48d1e1d8295f7cc3c0b4dc10bebd59e2434a2090ef5bc04993b43da480
0x40f060     55                               push   ebp
0x40f061     8bec                             mov    ebp,esp
0x40f063     83e4f8                           and    esp,0xfffffff8
0x40f066     6aff                             push   0xffffffff
0x40f068     68ee619400                       push   0x9461ee
0x40f06d     64a100000000                     mov    eax,fs:0x0
0x40f073     50                               push   eax
0x40f074     51                               push   ecx
0x40f075     a1201fd600                       mov    eax,ds:0xd61f20
0x40f07a     33c4                             xor    eax,esp
0x40f07c     50                               push   eax
0x40f07d     8d442408                         lea    eax,[esp+0x8]
0x40f081     64a300000000                     mov    fs:0x0,eax
0x40f087     b801000000                       mov    eax,0x1
0x40f08c     84052cb2fa00                     test   BYTE PTR ds:0xfab22c,al
0x40f092     7520                             jne    0x40f0b4
0x40f094     09052cb2fa00                     or     DWORD PTR ds:0xfab22c,eax
0x40f09a     c744241000000000                 mov    DWORD PTR [esp+0x10],0x0
0x40f0a2     e8e9fb0c00                       call   0x4dec90
0x40f0a7     6830cebc00                       push   0xbcce30
0x40f0ac     e869324800                       call   0x89231a
0x40f0b1     83c404                           add    esp,0x4
0x40f0b4     b830b1fa00                       mov    eax,0xfab130
0x40f0b9     8b4c2408                         mov    ecx,DWORD PTR [esp+0x8]
0x40f0bd     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x40f0c4     59                               pop    ecx
0x40f0c5     8be5                             mov    esp,ebp
0x40f0c7     5d                               pop    ebp
0x40f0c8     c3                               ret
0x40f0c9     cc                               int3
0x40f0ca     cc                               int3
0x40f0cb     cc                               int3
0x40f0cc     cc                               int3
0x40f0cd     cc                               int3
0x40f0ce     cc                               int3
0x40f0cf     cc                               int3
0x40f0d0     8bce                             mov    ecx,esi
0x40f0d2     e819613300                       call   0x7451f0
0x40f0d7     33c0                             xor    eax,eax
0x40f0d9     898680000000                     mov    DWORD PTR [esi+0x80],eax
0x40f0df     898684000000                     mov    DWORD PTR [esi+0x84],eax

; delete_numeric_converter 0x4acb70..0x4acbe3 raw=0xabf70 SHA256=3dc7ee03ab0c5cb15c58d7bede4c152112acd04d8aae1d2b3cf95671994f55be
0x4acb70     55                               push   ebp
0x4acb71     8bec                             mov    ebp,esp
0x4acb73     8b08                             mov    ecx,DWORD PTR [eax]
0x4acb75     83ec18                           sub    esp,0x18
0x4acb78     53                               push   ebx
0x4acb79     8b1d0418fe00                     mov    ebx,DWORD PTR ds:0xfe1804
0x4acb7f     83c8ff                           or     eax,0xffffffff
0x4acb82     e869852400                       call   0x6f50f0
0x4acb87     8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x4acb8a     83f903                           cmp    ecx,0x3
0x4acb8d     742a                             je     0x4acbb9
0x4acb8f     83f904                           cmp    ecx,0x4
0x4acb92     7540                             jne    0x4acbd4
0x4acb94     56                               push   esi
0x4acb95     8b30                             mov    esi,DWORD PTR [eax]
0x4acb97     57                               push   edi
0x4acb98     83c610                           add    esi,0x10
0x4acb9b     8d7df8                           lea    edi,[ebp-0x8]
0x4acb9e     e8bdab2400                       call   0x6f7760
0x4acba3     5f                               pop    edi
0x4acba4     5e                               pop    esi
0x4acba5     85c0                             test   eax,eax
0x4acba7     742b                             je     0x4acbd4
0x4acba9     dd45f8                           fld    QWORD PTR [ebp-0x8]
0x4acbac     c745f003000000                   mov    DWORD PTR [ebp-0x10],0x3
0x4acbb3     dd5de8                           fstp   QWORD PTR [ebp-0x18]
0x4acbb6     8d45e8                           lea    eax,[ebp-0x18]
0x4acbb9     dd00                             fld    QWORD PTR [eax]
0x4acbbb     dd5df0                           fstp   QWORD PTR [ebp-0x10]
0x4acbbe     dd45f0                           fld    QWORD PTR [ebp-0x10]
0x4acbc1     db5dfc                           fistp  DWORD PTR [ebp-0x4]
0x4acbc4     8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x4acbc7     50                               push   eax
0x4acbc8     8bcb                             mov    ecx,ebx
0x4acbca     ff5508                           call   DWORD PTR [ebp+0x8]
0x4acbcd     33c0                             xor    eax,eax
0x4acbcf     5b                               pop    ebx
0x4acbd0     8be5                             mov    esp,ebp
0x4acbd2     5d                               pop    ebp
0x4acbd3     c3                               ret
0x4acbd4     33c0                             xor    eax,eax
0x4acbd6     50                               push   eax
0x4acbd7     8bcb                             mov    ecx,ebx
0x4acbd9     ff5508                           call   DWORD PTR [ebp+0x8]
0x4acbdc     33c0                             xor    eax,eax
0x4acbde     5b                               pop    ebx
0x4acbdf     8be5                             mov    esp,ebp
0x4acbe1     5d                               pop    ebp
0x4acbe2     c3                               ret

; point_lookup_setter 0x544940..0x5449a0 raw=0x143d40 SHA256=6966d1baf8702cf64ad48e8d678062a598aed754c00fac42f746f77fb9891c03
0x544940     55                               push   ebp
0x544941     8bec                             mov    ebp,esp
0x544943     8b4208                           mov    eax,DWORD PTR [edx+0x8]
0x544946     2b4204                           sub    eax,DWORD PTR [edx+0x4]
0x544949     53                               push   ebx
0x54494a     c1f802                           sar    eax,0x2
0x54494d     56                               push   esi
0x54494e     33c9                             xor    ecx,ecx
0x544950     57                               push   edi
0x544951     85c0                             test   eax,eax
0x544953     7443                             je     0x544998
0x544955     8b5204                           mov    edx,DWORD PTR [edx+0x4]
0x544958     8bf2                             mov    esi,edx
0x54495a     8d9b00000000                     lea    ebx,[ebx+0x0]
0x544960     8b3e                             mov    edi,DWORD PTR [esi]
0x544962     668b9ff6000000                   mov    bx,WORD PTR [edi+0xf6]
0x544969     663b5d08                         cmp    bx,WORD PTR [ebp+0x8]
0x54496d     750e                             jne    0x54497d
0x54496f     660fbe5d0c                       movsx  bx,BYTE PTR [ebp+0xc]
0x544974     66399ff4000000                   cmp    WORD PTR [edi+0xf4],bx
0x54497b     740f                             je     0x54498c
0x54497d     41                               inc    ecx
0x54497e     83c604                           add    esi,0x4
0x544981     3bc8                             cmp    ecx,eax
0x544983     72db                             jb     0x544960
0x544985     5f                               pop    edi
0x544986     5e                               pop    esi
0x544987     5b                               pop    ebx
0x544988     5d                               pop    ebp
0x544989     c20c00                           ret    0xc
0x54498c     8b048a                           mov    eax,DWORD PTR [edx+ecx*4]
0x54498f     8a4d10                           mov    cl,BYTE PTR [ebp+0x10]
0x544992     50                               push   eax
0x544993     e898f1ffff                       call   0x543b30
0x544998     5f                               pop    edi
0x544999     5e                               pop    esi
0x54499a     5b                               pop    ebx
0x54499b     5d                               pop    ebp
0x54499c     c20c00                           ret    0xc
0x54499f     cc                               int3

; point_set_status 0x543b30..0x544020 raw=0x142f30 SHA256=b803c5f50cf0547d7bb9cee3986b63af5727d23422a7202b223312715404c904
0x543b30     55                               push   ebp
0x543b31     8bec                             mov    ebp,esp
0x543b33     83e4f8                           and    esp,0xfffffff8
0x543b36     6aff                             push   0xffffffff
0x543b38     68ac979200                       push   0x9297ac
0x543b3d     64a100000000                     mov    eax,fs:0x0
0x543b43     50                               push   eax
0x543b44     83ec38                           sub    esp,0x38
0x543b47     a1201fd600                       mov    eax,ds:0xd61f20
0x543b4c     33c4                             xor    eax,esp
0x543b4e     89442430                         mov    DWORD PTR [esp+0x30],eax
0x543b52     53                               push   ebx
0x543b53     56                               push   esi
0x543b54     57                               push   edi
0x543b55     a1201fd600                       mov    eax,ds:0xd61f20
0x543b5a     33c4                             xor    eax,esp
0x543b5c     50                               push   eax
0x543b5d     8d442448                         lea    eax,[esp+0x48]
0x543b61     64a300000000                     mov    fs:0x0,eax
0x543b67     8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x543b6a     0fb783f4000000                   movzx  eax,WORD PTR [ebx+0xf4]
0x543b71     33ff                             xor    edi,edi
0x543b73     884c2417                         mov    BYTE PTR [esp+0x17],cl
0x543b77     888b05010000                     mov    BYTE PTR [ebx+0x105],cl
0x543b7d     663bc7                           cmp    ax,di
0x543b80     0f853d040000                     jne    0x543fc3
0x543b86     8b83f0000000                     mov    eax,DWORD PTR [ebx+0xf0]
0x543b8c     3bc7                             cmp    eax,edi
0x543b8e     7432                             je     0x543bc2
0x543b90     397824                           cmp    DWORD PTR [eax+0x24],edi
0x543b93     8d7024                           lea    esi,[eax+0x24]
0x543b96     7409                             je     0x543ba1
0x543b98     e853aa2700                       call   0x7be5f0
0x543b9d     8a4c2417                         mov    cl,BYTE PTR [esp+0x17]
0x543ba1     8b83f0000000                     mov    eax,DWORD PTR [ebx+0xf0]
0x543ba7     3bc7                             cmp    eax,edi
0x543ba9     7417                             je     0x543bc2
0x543bab     8bf8                             mov    edi,eax
0x543bad     e8fe41f8ff                       call   0x4c7db0
0x543bb2     8a4c2417                         mov    cl,BYTE PTR [esp+0x17]
0x543bb6     c783f000000000000000             mov    DWORD PTR [ebx+0xf0],0x0
0x543bc0     33ff                             xor    edi,edi
0x543bc2     6a48                             push   0x48
0x543bc4     80f901                           cmp    cl,0x1
0x543bc7     0f8525020000                     jne    0x543df2
0x543bcd     80bbf800000000                   cmp    BYTE PTR [ebx+0xf8],0x0
0x543bd4     7566                             jne    0x543c3c
0x543bd6     e88dd63400                       call   0x891268
0x543bdb     8bf0                             mov    esi,eax
0x543bdd     83c404                           add    esp,0x4
0x543be0     89742418                         mov    DWORD PTR [esp+0x18],esi
0x543be4     897c2450                         mov    DWORD PTR [esp+0x50],edi
0x543be8     3bf7                             cmp    esi,edi
0x543bea     0f84df000000                     je     0x543ccf
0x543bf0     0fbf83f6000000                   movsx  eax,WORD PTR [ebx+0xf6]
0x543bf7     0f57c0                           xorps  xmm0,xmm0
0x543bfa     894604                           mov    DWORD PTR [esi+0x4],eax
0x543bfd     c70608000000                     mov    DWORD PTR [esi],0x8
0x543c03     c7460804000000                   mov    DWORD PTR [esi+0x8],0x4
0x543c0a     c6460c01                         mov    BYTE PTR [esi+0xc],0x1
0x543c0e     8b83a0000000                     mov    eax,DWORD PTR [ebx+0xa0]
0x543c14     894610                           mov    DWORD PTR [esi+0x10],eax
0x543c17     8b8ba4000000                     mov    ecx,DWORD PTR [ebx+0xa4]
0x543c1d     f30f1144241c                     movss  DWORD PTR [esp+0x1c],xmm0
0x543c23     8b54241c                         mov    edx,DWORD PTR [esp+0x1c]
0x543c27     f30f11442420                     movss  DWORD PTR [esp+0x20],xmm0
0x543c2d     8b442420                         mov    eax,DWORD PTR [esp+0x20]
0x543c31     894e14                           mov    DWORD PTR [esi+0x14],ecx
0x543c34     89561c                           mov    DWORD PTR [esi+0x1c],edx
0x543c37     894620                           mov    DWORD PTR [esi+0x20],eax
0x543c3a     eb64                             jmp    0x543ca0
0x543c3c     e827d63400                       call   0x891268
0x543c41     8bf0                             mov    esi,eax
0x543c43     83c404                           add    esp,0x4
0x543c46     89742418                         mov    DWORD PTR [esp+0x18],esi
0x543c4a     c744245001000000                 mov    DWORD PTR [esp+0x50],0x1
0x543c52     3bf7                             cmp    esi,edi
0x543c54     7479                             je     0x543ccf
0x543c56     0fbf83f6000000                   movsx  eax,WORD PTR [ebx+0xf6]
0x543c5d     0f57c0                           xorps  xmm0,xmm0
0x543c60     894604                           mov    DWORD PTR [esi+0x4],eax
0x543c63     c7060b000000                     mov    DWORD PTR [esi],0xb
0x543c69     c7460802000000                   mov    DWORD PTR [esi+0x8],0x2
0x543c70     c6460c01                         mov    BYTE PTR [esi+0xc],0x1
0x543c74     8b8ba0000000                     mov    ecx,DWORD PTR [ebx+0xa0]
0x543c7a     894e10                           mov    DWORD PTR [esi+0x10],ecx
0x543c7d     8b93a4000000                     mov    edx,DWORD PTR [ebx+0xa4]
0x543c83     f30f1144241c                     movss  DWORD PTR [esp+0x1c],xmm0
0x543c89     8b44241c                         mov    eax,DWORD PTR [esp+0x1c]
0x543c8d     f30f11442420                     movss  DWORD PTR [esp+0x20],xmm0
0x543c93     8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
0x543c97     895614                           mov    DWORD PTR [esi+0x14],edx
0x543c9a     89461c                           mov    DWORD PTR [esi+0x1c],eax
0x543c9d     894e20                           mov    DWORD PTR [esi+0x20],ecx
0x543ca0     8d4e24                           lea    ecx,[esi+0x24]
0x543ca3     f30f114618                       movss  DWORD PTR [esi+0x18],xmm0
0x543ca8     c7411407000000                   mov    DWORD PTR [ecx+0x14],0x7
0x543caf     57                               push   edi
0x543cb0     33d2                             xor    edx,edx
0x543cb2     897910                           mov    DWORD PTR [ecx+0x10],edi
0x543cb5     68fcd1be00                       push   0xbed1fc
0x543cba     668911                           mov    WORD PTR [ecx],dx
0x543cbd     e89ee4ebff                       call   0x402160
0x543cc2     0f57c0                           xorps  xmm0,xmm0
0x543cc5     897e40                           mov    DWORD PTR [esi+0x40],edi
0x543cc8     f30f114644                       movss  DWORD PTR [esi+0x44],xmm0
0x543ccd     eb02                             jmp    0x543cd1
0x543ccf     33f6                             xor    esi,esi
0x543cd1     c7442450ffffffff                 mov    DWORD PTR [esp+0x50],0xffffffff
0x543cd9     e8d262f4ff                       call   0x489fb0
0x543cde     8b00                             mov    eax,DWORD PTR [eax]
0x543ce0     56                               push   esi
0x543ce1     50                               push   eax
0x543ce2     e8d9b80200                       call   0x56f5c0
0x543ce7     80bbf800000000                   cmp    BYTE PTR [ebx+0xf8],0x0
0x543cee     bf10000000                       mov    edi,0x10
0x543cf3     756f                             jne    0x543d64
0x543cf5     68e8f7c000                       push   0xc0f7e8
0x543cfa     8d47fa                           lea    eax,[edi-0x6]
0x543cfd     8d4c2428                         lea    ecx,[esp+0x28]
0x543d01     c744243c0f000000                 mov    DWORD PTR [esp+0x3c],0xf
0x543d09     c744243800000000                 mov    DWORD PTR [esp+0x38],0x0
0x543d11     c644242800                       mov    BYTE PTR [esp+0x28],0x0
0x543d16     e8f575ecff                       call   0x40b310
0x543d1b     c744245002000000                 mov    DWORD PTR [esp+0x50],0x2
0x543d23     e8c876ecff                       call   0x40b3f0
0x543d28     50                               push   eax
0x543d29     8d4c2428                         lea    ecx,[esp+0x28]
0x543d2d     e8ce6d2c00                       call   0x80ab00
0x543d32     85c0                             test   eax,eax
0x543d34     7409                             je     0x543d3f
0x543d36     8b10                             mov    edx,DWORD PTR [eax]
0x543d38     8bc8                             mov    ecx,eax
0x543d3a     8b4214                           mov    eax,DWORD PTR [edx+0x14]
0x543d3d     ffd0                             call   eax
0x543d3f     c7442450ffffffff                 mov    DWORD PTR [esp+0x50],0xffffffff
0x543d47     397c2438                         cmp    DWORD PTR [esp+0x38],edi
0x543d4b     720d                             jb     0x543d5a
0x543d4d     8b4c2424                         mov    ecx,DWORD PTR [esp+0x24]
0x543d51     51                               push   ecx
0x543d52     e8b5d43400                       call   0x89120c
0x543d57     83c404                           add    esp,0x4
0x543d5a     e8419ff6ff                       call   0x4adca0
0x543d5f     e86cf50000                       call   0x5532d0
0x543d64     f605b075fb0001                   test   BYTE PTR ds:0xfb75b0,0x1
0x543d6b     be03000000                       mov    esi,0x3
0x543d70     7525                             jne    0x543d97
0x543d72     830db075fb0001                   or     DWORD PTR ds:0xfb75b0,0x1
0x543d79     89742450                         mov    DWORD PTR [esp+0x50],esi
0x543d7d     e8fefffaff                       call   0x4f3d80
0x543d82     68e0d1bc00                       push   0xbcd1e0
0x543d87     e88ee53400                       call   0x89231a
0x543d8c     83c404                           add    esp,0x4
0x543d8f     c7442450ffffffff                 mov    DWORD PTR [esp+0x50],0xffffffff
0x543d97     660fbe93f8000000                 movsx  dx,BYTE PTR [ebx+0xf8]
0x543d9f     0fb7c2                           movzx  eax,dx
0x543da2     c1e010                           shl    eax,0x10
0x543da5     83c801                           or     eax,0x1
0x543da8     8d542418                         lea    edx,[esp+0x18]
0x543dac     b93075fb00                       mov    ecx,0xfb7530
0x543db1     89442418                         mov    DWORD PTR [esp+0x18],eax
0x543db5     e8063ffbff                       call   0x4f7cc0
0x543dba     397814                           cmp    DWORD PTR [eax+0x14],edi
0x543dbd     7202                             jb     0x543dc1
0x543dbf     8b00                             mov    eax,DWORD PTR [eax]
0x543dc1     f605dcf6fd0001                   test   BYTE PTR ds:0xfdf6dc,0x1
0x543dc8     89742424                         mov    DWORD PTR [esp+0x24],esi
0x543dcc     c7442428bcd6c000                 mov    DWORD PTR [esp+0x28],0xc0d6bc
0x543dd4     89442434                         mov    DWORD PTR [esp+0x34],eax
0x543dd8     0f85b0010000                     jne    0x543f8e
0x543dde     830ddcf6fd0001                   or     DWORD PTR ds:0xfdf6dc,0x1
0x543de5     c744245004000000                 mov    DWORD PTR [esp+0x50],0x4
0x543ded     e982010000                       jmp    0x543f74
0x543df2     80bbf800000000                   cmp    BYTE PTR [ebx+0xf8],0x0
0x543df9     7538                             jne    0x543e33
0x543dfb     e868d43400                       call   0x891268
0x543e00     8bf0                             mov    esi,eax
0x543e02     83c404                           add    esp,0x4
0x543e05     89742418                         mov    DWORD PTR [esp+0x18],esi
0x543e09     c744245005000000                 mov    DWORD PTR [esp+0x50],0x5
0x543e11     bf07000000                       mov    edi,0x7
0x543e16     85f6                             test   esi,esi
0x543e18     0f84b1000000                     je     0x543ecf
0x543e1e     0fbf83f6000000                   movsx  eax,WORD PTR [ebx+0xf6]
0x543e25     8d4801                           lea    ecx,[eax+0x1]
0x543e28     c70608000000                     mov    DWORD PTR [esi],0x8
0x543e2e     894e08                           mov    DWORD PTR [esi+0x8],ecx
0x543e31     eb33                             jmp    0x543e66
0x543e33     e830d43400                       call   0x891268
0x543e38     8bf0                             mov    esi,eax
0x543e3a     83c404                           add    esp,0x4
0x543e3d     89742418                         mov    DWORD PTR [esp+0x18],esi
0x543e41     c744245006000000                 mov    DWORD PTR [esp+0x50],0x6
0x543e49     bf07000000                       mov    edi,0x7
0x543e4e     85f6                             test   esi,esi
0x543e50     747d                             je     0x543ecf
0x543e52     0fbf83f6000000                   movsx  eax,WORD PTR [ebx+0xf6]
0x543e59     c7060b000000                     mov    DWORD PTR [esi],0xb
0x543e5f     c7460801000000                   mov    DWORD PTR [esi+0x8],0x1
0x543e66     0f57c0                           xorps  xmm0,xmm0
0x543e69     894604                           mov    DWORD PTR [esi+0x4],eax
0x543e6c     c6460c01                         mov    BYTE PTR [esi+0xc],0x1
0x543e70     8b8ba0000000                     mov    ecx,DWORD PTR [ebx+0xa0]
0x543e76     894e10                           mov    DWORD PTR [esi+0x10],ecx
0x543e79     8b93a4000000                     mov    edx,DWORD PTR [ebx+0xa4]
0x543e7f     895614                           mov    DWORD PTR [esi+0x14],edx
0x543e82     f30f114618                       movss  DWORD PTR [esi+0x18],xmm0
0x543e87     f30f1144241c                     movss  DWORD PTR [esp+0x1c],xmm0
0x543e8d     8b44241c                         mov    eax,DWORD PTR [esp+0x1c]
0x543e91     89461c                           mov    DWORD PTR [esi+0x1c],eax
0x543e94     f30f11442420                     movss  DWORD PTR [esp+0x20],xmm0
0x543e9a     8b4c2420                         mov    ecx,DWORD PTR [esp+0x20]
0x543e9e     894e20                           mov    DWORD PTR [esi+0x20],ecx
0x543ea1     8d4e24                           lea    ecx,[esi+0x24]
0x543ea4     33d2                             xor    edx,edx
0x543ea6     897914                           mov    DWORD PTR [ecx+0x14],edi
0x543ea9     52                               push   edx
0x543eaa     c7411000000000                   mov    DWORD PTR [ecx+0x10],0x0
0x543eb1     68fcd1be00                       push   0xbed1fc
0x543eb6     668911                           mov    WORD PTR [ecx],dx
0x543eb9     e8a2e2ebff                       call   0x402160
0x543ebe     0f57c0                           xorps  xmm0,xmm0
0x543ec1     c7464000000000                   mov    DWORD PTR [esi+0x40],0x0
0x543ec8     f30f114644                       movss  DWORD PTR [esi+0x44],xmm0
0x543ecd     eb02                             jmp    0x543ed1
0x543ecf     33f6                             xor    esi,esi
0x543ed1     c7442450ffffffff                 mov    DWORD PTR [esp+0x50],0xffffffff
0x543ed9     e8d260f4ff                       call   0x489fb0
0x543ede     8b00                             mov    eax,DWORD PTR [eax]
0x543ee0     56                               push   esi
0x543ee1     50                               push   eax
0x543ee2     e8d9b60200                       call   0x56f5c0
0x543ee7     f605b075fb0001                   test   BYTE PTR ds:0xfb75b0,0x1
0x543eee     7525                             jne    0x543f15
0x543ef0     830db075fb0001                   or     DWORD PTR ds:0xfb75b0,0x1
0x543ef7     897c2450                         mov    DWORD PTR [esp+0x50],edi
0x543efb     e880fefaff                       call   0x4f3d80
0x543f00     68e0d1bc00                       push   0xbcd1e0
0x543f05     e810e43400                       call   0x89231a
0x543f0a     83c404                           add    esp,0x4
0x543f0d     c7442450ffffffff                 mov    DWORD PTR [esp+0x50],0xffffffff
0x543f15     660fbe8bf8000000                 movsx  cx,BYTE PTR [ebx+0xf8]
0x543f1d     660fbe442417                     movsx  ax,BYTE PTR [esp+0x17]
0x543f23     0fb7d1                           movzx  edx,cx
0x543f26     0fb7c8                           movzx  ecx,ax
0x543f29     c1e210                           shl    edx,0x10
0x543f2c     0bd1                             or     edx,ecx
0x543f2e     89542418                         mov    DWORD PTR [esp+0x18],edx
0x543f32     8d542418                         lea    edx,[esp+0x18]
0x543f36     b93075fb00                       mov    ecx,0xfb7530
0x543f3b     e8803dfbff                       call   0x4f7cc0
0x543f40     83781410                         cmp    DWORD PTR [eax+0x14],0x10
0x543f44     7202                             jb     0x543f48
0x543f46     8b00                             mov    eax,DWORD PTR [eax]
0x543f48     f605dcf6fd0001                   test   BYTE PTR ds:0xfdf6dc,0x1
0x543f4f     c744242403000000                 mov    DWORD PTR [esp+0x24],0x3
0x543f57     c7442428bcd6c000                 mov    DWORD PTR [esp+0x28],0xc0d6bc
0x543f5f     89442434                         mov    DWORD PTR [esp+0x34],eax
0x543f63     7529                             jne    0x543f8e
0x543f65     830ddcf6fd0001                   or     DWORD PTR ds:0xfdf6dc,0x1
0x543f6c     c744245008000000                 mov    DWORD PTR [esp+0x50],0x8
0x543f74     e8a7c80000                       call   0x550820
0x543f79     68b0e6bc00                       push   0xbce6b0
0x543f7e     e897e33400                       call   0x89231a
0x543f83     83c404                           add    esp,0x4
0x543f86     c7442450ffffffff                 mov    DWORD PTR [esp+0x50],0xffffffff
0x543f8e     d983b4000000                     fld    DWORD PTR [ebx+0xb4]
0x543f94     8b13                             mov    edx,DWORD PTR [ebx]
0x543f96     8b424c                           mov    eax,DWORD PTR [edx+0x4c]
0x543f99     83ec08                           sub    esp,0x8
0x543f9c     d95c2404                         fstp   DWORD PTR [esp+0x4]
0x543fa0     8bcb                             mov    ecx,ebx
0x543fa2     d9ee                             fldz
0x543fa4     d91c24                           fstp   DWORD PTR [esp]
0x543fa7     ffd0                             call   eax
0x543fa9     6a00                             push   0x0
0x543fab     8bf0                             mov    esi,eax
0x543fad     8d542430                         lea    edx,[esp+0x30]
0x543fb1     b980f6fd00                       mov    ecx,0xfdf680
0x543fb6     e8d5df0000                       call   0x551f90
0x543fbb     8983f0000000                     mov    DWORD PTR [ebx+0xf0],eax
0x543fc1     eb3c                             jmp    0x543fff
0x543fc3     6683f804                         cmp    ax,0x4
0x543fc7     7536                             jne    0x543fff
0x543fc9     84c9                             test   cl,cl
0x543fcb     7532                             jne    0x543fff
0x543fcd     8b83f0000000                     mov    eax,DWORD PTR [ebx+0xf0]
0x543fd3     3bc7                             cmp    eax,edi
0x543fd5     7428                             je     0x543fff
0x543fd7     397824                           cmp    DWORD PTR [eax+0x24],edi
0x543fda     8d7024                           lea    esi,[eax+0x24]
0x543fdd     7405                             je     0x543fe4
0x543fdf     e80ca62700                       call   0x7be5f0
0x543fe4     8b83f0000000                     mov    eax,DWORD PTR [ebx+0xf0]
0x543fea     3bc7                             cmp    eax,edi
0x543fec     7411                             je     0x543fff
0x543fee     8bf8                             mov    edi,eax
0x543ff0     e8bb3df8ff                       call   0x4c7db0
0x543ff5     c783f000000000000000             mov    DWORD PTR [ebx+0xf0],0x0
0x543fff     8b4c2448                         mov    ecx,DWORD PTR [esp+0x48]
0x544003     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x54400a     59                               pop    ecx
0x54400b     5f                               pop    edi
0x54400c     5e                               pop    esi
0x54400d     5b                               pop    ebx
0x54400e     8b4c2430                         mov    ecx,DWORD PTR [esp+0x30]
0x544012     33cc                             xor    ecx,esp
0x544014     e8e8cf3400                       call   0x891001
0x544019     8be5                             mov    esp,ebp
0x54401b     5d                               pop    ebp
0x54401c     c20400                           ret    0x4
0x54401f     cc                               int3

; checkpoint_delta_packet 0x4b32e0..0x4b3350 raw=0xb26e0 SHA256=d9d2c574eb94cbb8400c2d27f6a407b3fed47bcf58e61438515a2bff0d982a21
0x4b32e0     55                               push   ebp
0x4b32e1     8bec                             mov    ebp,esp
0x4b32e3     b901000000                       mov    ecx,0x1
0x4b32e8     840dec79fb00                     test   BYTE PTR ds:0xfb79ec,cl
0x4b32ee     7534                             jne    0x4b3324
0x4b32f0     090dec79fb00                     or     DWORD PTR ds:0xfb79ec,ecx
0x4b32f6     33c0                             xor    eax,eax
0x4b32f8     6870d2bc00                       push   0xbcd270
0x4b32fd     c705f079fb0068f8c000             mov    DWORD PTR ds:0xfb79f0,0xc0f868
0x4b3307     a3f479fb00                       mov    ds:0xfb79f4,eax
0x4b330c     a3f879fb00                       mov    ds:0xfb79f8,eax
0x4b3311     a3fc79fb00                       mov    ds:0xfb79fc,eax
0x4b3316     890d047afb00                     mov    DWORD PTR ds:0xfb7a04,ecx
0x4b331c     e8f9ef3d00                       call   0x89231a
0x4b3321     83c404                           add    esp,0x4
0x4b3324     8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4b3327     0fb64805                         movzx  ecx,BYTE PTR [eax+0x5]
0x4b332b     0fb65004                         movzx  edx,BYTE PTR [eax+0x4]
0x4b332f     0fb74002                         movzx  eax,WORD PTR [eax+0x2]
0x4b3333     51                               push   ecx
0x4b3334     52                               push   edx
0x4b3335     50                               push   eax
0x4b3336     baf079fb00                       mov    edx,0xfb79f0
0x4b333b     e800160900                       call   0x544940
0x4b3340     33c0                             xor    eax,eax
0x4b3342     5d                               pop    ebp
0x4b3343     c20c00                           ret    0xc
0x4b3346     cc                               int3
0x4b3347     cc                               int3
0x4b3348     cc                               int3
0x4b3349     cc                               int3
0x4b334a     cc                               int3
0x4b334b     cc                               int3
0x4b334c     cc                               int3
0x4b334d     cc                               int3
0x4b334e     cc                               int3
0x4b334f     cc                               int3

; map_audio_finalize 0x4e0590..0x4e0642 raw=0xdf990 SHA256=8b7e26adc92440d1182c2d37fb9cef81d28efff38fb53e01d3216bede170b02b
0x4e0590     55                               push   ebp
0x4e0591     8bec                             mov    ebp,esp
0x4e0593     6aff                             push   0xffffffff
0x4e0595     686e789100                       push   0x91786e
0x4e059a     64a100000000                     mov    eax,fs:0x0
0x4e05a0     50                               push   eax
0x4e05a1     a1201fd600                       mov    eax,ds:0xd61f20
0x4e05a6     33c5                             xor    eax,ebp
0x4e05a8     50                               push   eax
0x4e05a9     8d45f4                           lea    eax,[ebp-0xc]
0x4e05ac     64a300000000                     mov    fs:0x0,eax
0x4e05b2     f605c00ffc0001                   test   BYTE PTR ds:0xfc0fc0,0x1
0x4e05b9     7527                             jne    0x4e05e2
0x4e05bb     830dc00ffc0001                   or     DWORD PTR ds:0xfc0fc0,0x1
0x4e05c2     c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x4e05c9     e882881f00                       call   0x6d8e50
0x4e05ce     68b0dbbc00                       push   0xbcdbb0
0x4e05d3     e8421d3b00                       call   0x89231a
0x4e05d8     83c404                           add    esp,0x4
0x4e05db     c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x4e05e2     833de40ffc0000                   cmp    DWORD PTR ds:0xfc0fe4,0x0
0x4e05e9     7448                             je     0x4e0633
0x4e05eb     833ddc0ffc0010                   cmp    DWORD PTR ds:0xfc0fdc,0x10
0x4e05f2     a1c80ffc00                       mov    eax,ds:0xfc0fc8
0x4e05f7     7305                             jae    0x4e05fe
0x4e05f9     b8c80ffc00                       mov    eax,0xfc0fc8
0x4e05fe     0fb70d6c10fc00                   movzx  ecx,WORD PTR ds:0xfc106c
0x4e0605     51                               push   ecx
0x4e0606     6a01                             push   0x1
0x4e0608     50                               push   eax
0x4e0609     68c80ffc00                       push   0xfc0fc8
0x4e060e     b9fc0ffc00                       mov    ecx,0xfc0ffc
0x4e0613     e818951f00                       call   0x6d9b30
0x4e0618     6a00                             push   0x0
0x4e061a     687523bf00                       push   0xbf2375
0x4e061f     b9c80ffc00                       mov    ecx,0xfc0fc8
0x4e0624     c705e40ffc0000000000             mov    DWORD PTR ds:0xfc0fe4,0x0
0x4e062e     e83d24f2ff                       call   0x402a70
0x4e0633     8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4e0636     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4e063d     59                               pop    ecx
0x4e063e     8be5                             mov    esp,ebp
0x4e0640     5d                               pop    ebp
0x4e0641     c3                               ret

; monster_ctor 0x4d1710..0x4d18d0 raw=0xd0b10 SHA256=41cc95ca5aa7aac20573d3aea111d56f8c53b7c97bb1025dad2185dad5c51577
0x4d1710     55                               push   ebp
0x4d1711     8bec                             mov    ebp,esp
0x4d1713     6aff                             push   0xffffffff
0x4d1715     68b9089100                       push   0x9108b9
0x4d171a     64a100000000                     mov    eax,fs:0x0
0x4d1720     50                               push   eax
0x4d1721     51                               push   ecx
0x4d1722     53                               push   ebx
0x4d1723     56                               push   esi
0x4d1724     57                               push   edi
0x4d1725     a1201fd600                       mov    eax,ds:0xd61f20
0x4d172a     33c5                             xor    eax,ebp
0x4d172c     50                               push   eax
0x4d172d     8d45f4                           lea    eax,[ebp-0xc]
0x4d1730     64a300000000                     mov    fs:0x0,eax
0x4d1736     8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x4d1739     57                               push   edi
0x4d173a     e83159ffff                       call   0x4c7070
0x4d173f     33db                             xor    ebx,ebx
0x4d1741     895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x4d1744     0f57c0                           xorps  xmm0,xmm0
0x4d1747     6a3c                             push   0x3c
0x4d1749     c707dcc9c000                     mov    DWORD PTR [edi],0xc0c9dc
0x4d174f     c787f000000064cac000             mov    DWORD PTR [edi+0xf0],0xc0ca64
0x4d1759     899f20040000                     mov    DWORD PTR [edi+0x420],ebx
0x4d175f     899f28040000                     mov    DWORD PTR [edi+0x428],ebx
0x4d1765     f30f11872c040000                 movss  DWORD PTR [edi+0x42c],xmm0
0x4d176d     899f30040000                     mov    DWORD PTR [edi+0x430],ebx
0x4d1773     e8f0fa3b00                       call   0x891268
0x4d1778     8bf0                             mov    esi,eax
0x4d177a     83c404                           add    esp,0x4
0x4d177d     8975f0                           mov    DWORD PTR [ebp-0x10],esi
0x4d1780     c645fc01                         mov    BYTE PTR [ebp-0x4],0x1
0x4d1784     3bf3                             cmp    esi,ebx
0x4d1786     7419                             je     0x4d17a1
0x4d1788     8bc7                             mov    eax,edi
0x4d178a     8d4b03                           lea    ecx,[ebx+0x3]
0x4d178d     e89e9affff                       call   0x4cb230
0x4d1792     c706cc77c000                     mov    DWORD PTR [esi],0xc077cc
0x4d1798     c7463401000000                   mov    DWORD PTR [esi+0x34],0x1
0x4d179f     eb02                             jmp    0x4d17a3
0x4d17a1     33f6                             xor    esi,esi
0x4d17a3     c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
0x4d17a7     8b5e08                           mov    ebx,DWORD PTR [esi+0x8]
0x4d17aa     83bc9ff400000000                 cmp    DWORD PTR [edi+ebx*4+0xf4],0x0
0x4d17b2     740d                             je     0x4d17c1
0x4d17b4     683c75c000                       push   0xc0753c
0x4d17b9     e8a2c32100                       call   0x6edb60
0x4d17be     83c404                           add    esp,0x4
0x4d17c1     89b49ff4000000                   mov    DWORD PTR [edi+ebx*4+0xf4],esi
0x4d17c8     83bf5801000000                   cmp    DWORD PTR [edi+0x158],0x0
0x4d17cf     7506                             jne    0x4d17d7
0x4d17d1     89b758010000                     mov    DWORD PTR [edi+0x158],esi
0x4d17d7     6a38                             push   0x38
0x4d17d9     e88afa3b00                       call   0x891268
0x4d17de     8bf0                             mov    esi,eax
0x4d17e0     83c404                           add    esp,0x4
0x4d17e3     8975f0                           mov    DWORD PTR [ebp-0x10],esi
0x4d17e6     b902000000                       mov    ecx,0x2
0x4d17eb     884dfc                           mov    BYTE PTR [ebp-0x4],cl
0x4d17ee     85f6                             test   esi,esi
0x4d17f0     741d                             je     0x4d180f
0x4d17f2     8bc7                             mov    eax,edi
0x4d17f4     e8379affff                       call   0x4cb230
0x4d17f9     b801000000                       mov    eax,0x1
0x4d17fe     c706b477c000                     mov    DWORD PTR [esi],0xc077b4
0x4d1804     894628                           mov    DWORD PTR [esi+0x28],eax
0x4d1807     89462c                           mov    DWORD PTR [esi+0x2c],eax
0x4d180a     894630                           mov    DWORD PTR [esi+0x30],eax
0x4d180d     eb02                             jmp    0x4d1811
0x4d180f     33f6                             xor    esi,esi
0x4d1811     c645fc00                         mov    BYTE PTR [ebp-0x4],0x0
0x4d1815     8b5e08                           mov    ebx,DWORD PTR [esi+0x8]
0x4d1818     83bc9ff400000000                 cmp    DWORD PTR [edi+ebx*4+0xf4],0x0
0x4d1820     740d                             je     0x4d182f
0x4d1822     683c75c000                       push   0xc0753c
0x4d1827     e834c32100                       call   0x6edb60
0x4d182c     83c404                           add    esp,0x4
0x4d182f     89b49ff4000000                   mov    DWORD PTR [edi+ebx*4+0xf4],esi
0x4d1836     83bf5801000000                   cmp    DWORD PTR [edi+0x158],0x0
0x4d183d     7506                             jne    0x4d1845
0x4d183f     89b758010000                     mov    DWORD PTR [edi+0x158],esi
0x4d1845     6a3c                             push   0x3c
0x4d1847     e81cfa3b00                       call   0x891268
0x4d184c     8bf0                             mov    esi,eax
0x4d184e     83c404                           add    esp,0x4
0x4d1851     8975f0                           mov    DWORD PTR [ebp-0x10],esi
0x4d1854     c645fc03                         mov    BYTE PTR [ebp-0x4],0x3
0x4d1858     85f6                             test   esi,esi
0x4d185a     7422                             je     0x4d187e
0x4d185c     8bc7                             mov    eax,edi
0x4d185e     b905000000                       mov    ecx,0x5
0x4d1863     e8c899ffff                       call   0x4cb230
0x4d1868     c7463809000000                   mov    DWORD PTR [esi+0x38],0x9
0x4d186f     c706fc77c000                     mov    DWORD PTR [esi],0xc077fc
0x4d1875     c7462c01000000                   mov    DWORD PTR [esi+0x2c],0x1
0x4d187c     eb02                             jmp    0x4d1880
0x4d187e     33f6                             xor    esi,esi
0x4d1880     8b5e08                           mov    ebx,DWORD PTR [esi+0x8]
0x4d1883     83bc9ff400000000                 cmp    DWORD PTR [edi+ebx*4+0xf4],0x0
0x4d188b     740d                             je     0x4d189a
0x4d188d     683c75c000                       push   0xc0753c
0x4d1892     e8c9c22100                       call   0x6edb60
0x4d1897     83c404                           add    esp,0x4
0x4d189a     89b49ff4000000                   mov    DWORD PTR [edi+ebx*4+0xf4],esi
0x4d18a1     83bf5801000000                   cmp    DWORD PTR [edi+0x158],0x0
0x4d18a8     8bc7                             mov    eax,edi
0x4d18aa     7506                             jne    0x4d18b2
0x4d18ac     89b758010000                     mov    DWORD PTR [edi+0x158],esi
0x4d18b2     c7879c03000001000000             mov    DWORD PTR [edi+0x39c],0x1
0x4d18bc     8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4d18bf     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4d18c6     59                               pop    ecx
0x4d18c7     5f                               pop    edi
0x4d18c8     5e                               pop    esi
0x4d18c9     5b                               pop    ebx
0x4d18ca     8be5                             mov    esp,ebp
0x4d18cc     5d                               pop    ebp
0x4d18cd     c20400                           ret    0x4

; monster_delete 0x4d18d0..0x4d1901 raw=0xd0cd0 SHA256=2cf47102808191c44ba4d7c2f615c10bb0b0defa8c1a7fed2156648514092e0b
0x4d18d0     55                               push   ebp
0x4d18d1     8bec                             mov    ebp,esp
0x4d18d3     56                               push   esi
0x4d18d4     8bf1                             mov    esi,ecx
0x4d18d6     c706dcc9c000                     mov    DWORD PTR [esi],0xc0c9dc
0x4d18dc     c786f000000064cac000             mov    DWORD PTR [esi+0xf0],0xc0ca64
0x4d18e6     e8a562ffff                       call   0x4c7b90
0x4d18eb     f6450801                         test   BYTE PTR [ebp+0x8],0x1
0x4d18ef     7409                             je     0x4d18fa
0x4d18f1     56                               push   esi
0x4d18f2     e815f93b00                       call   0x89120c
0x4d18f7     83c404                           add    esp,0x4
0x4d18fa     8bc6                             mov    eax,esi
0x4d18fc     5e                               pop    esi
0x4d18fd     5d                               pop    ebp
0x4d18fe     c20400                           ret    0x4

; monster_cleanup 0x4d1f80..0x4d1f88 raw=0xd1380 SHA256=ffa540291c94665ee3eaf406cc0f5c54388c0bc0ad71a865bf179a53719187fb
0x4d1f80     e8db63ffff                       call   0x4c8360
0x4d1f85     33c0                             xor    eax,eax
0x4d1f87     c3                               ret

; minimap_dispatch 0x56cd10..0x56cf01 raw=0x16c110 SHA256=cfff3e355d897cf03d2c45a9103a19f5491af76ffd3bce7bf516f892e596e5b6
0x56cd10     55                               push   ebp
0x56cd11     8bec                             mov    ebp,esp
0x56cd13     83e4f8                           and    esp,0xfffffff8
0x56cd16     6aff                             push   0xffffffff
0x56cd18     6804869300                       push   0x938604
0x56cd1d     64a100000000                     mov    eax,fs:0x0
0x56cd23     50                               push   eax
0x56cd24     83ec34                           sub    esp,0x34
0x56cd27     a1201fd600                       mov    eax,ds:0xd61f20
0x56cd2c     33c4                             xor    eax,esp
0x56cd2e     8944242c                         mov    DWORD PTR [esp+0x2c],eax
0x56cd32     53                               push   ebx
0x56cd33     56                               push   esi
0x56cd34     a1201fd600                       mov    eax,ds:0xd61f20
0x56cd39     33c4                             xor    eax,esp
0x56cd3b     50                               push   eax
0x56cd3c     8d442440                         lea    eax,[esp+0x40]
0x56cd40     64a300000000                     mov    fs:0x0,eax
0x56cd46     bb01000000                       mov    ebx,0x1
0x56cd4b     8bf1                             mov    esi,ecx
0x56cd4d     841d2cb2fa00                     test   BYTE PTR ds:0xfab22c,bl
0x56cd53     7528                             jne    0x56cd7d
0x56cd55     091d2cb2fa00                     or     DWORD PTR ds:0xfab22c,ebx
0x56cd5b     c744244800000000                 mov    DWORD PTR [esp+0x48],0x0
0x56cd63     e8281ff7ff                       call   0x4dec90
0x56cd68     6830cebc00                       push   0xbcce30
0x56cd6d     e8a8553200                       call   0x89231a
0x56cd72     83c404                           add    esp,0x4
0x56cd75     c7442448ffffffff                 mov    DWORD PTR [esp+0x48],0xffffffff
0x56cd7d     a134b1fa00                       mov    eax,ds:0xfab134
0x56cd82     0fb64036                         movzx  eax,BYTE PTR [eax+0x36]
0x56cd86     83f805                           cmp    eax,0x5
0x56cd89     0f8492000000                     je     0x56ce21
0x56cd8f     85c0                             test   eax,eax
0x56cd91     0f848a000000                     je     0x56ce21
0x56cd97     c744241800000000                 mov    DWORD PTR [esp+0x18],0x0
0x56cd9f     b9cc07c100                       mov    ecx,0xc107cc
0x56cda4     8b07                             mov    eax,DWORD PTR [edi]
0x56cda6     83c020                           add    eax,0x20
0x56cda9     50                               push   eax
0x56cdaa     e831300000                       call   0x56fde0
0x56cdaf     6a0c                             push   0xc
0x56cdb1     68ec07c100                       push   0xc107ec
0x56cdb6     8d4c2424                         lea    ecx,[esp+0x24]
0x56cdba     c74424380f000000                 mov    DWORD PTR [esp+0x38],0xf
0x56cdc2     c744243400000000                 mov    DWORD PTR [esp+0x34],0x0
0x56cdca     c644242400                       mov    BYTE PTR [esp+0x24],0x0
0x56cdcf     e89c5ce9ff                       call   0x402a70
0x56cdd4     895c2448                         mov    DWORD PTR [esp+0x48],ebx
0x56cdd8     841db075fb00                     test   BYTE PTR ds:0xfb75b0,bl
0x56cdde     7521                             jne    0x56ce01
0x56cde0     091db075fb00                     or     DWORD PTR ds:0xfb75b0,ebx
0x56cde6     c644244802                       mov    BYTE PTR [esp+0x48],0x2
0x56cdeb     e8906ff8ff                       call   0x4f3d80
0x56cdf0     68e0d1bc00                       push   0xbcd1e0
0x56cdf5     e820553200                       call   0x89231a
0x56cdfa     83c404                           add    esp,0x4
0x56cdfd     885c2448                         mov    BYTE PTR [esp+0x48],bl
0x56ce01     8d542410                         lea    edx,[esp+0x10]
0x56ce05     b9d074fb00                       mov    ecx,0xfb74d0
0x56ce0a     89742410                         mov    DWORD PTR [esp+0x10],esi
0x56ce0e     e8ddaff8ff                       call   0x4f7df0
0x56ce13     bb10000000                       mov    ebx,0x10
0x56ce18     395814                           cmp    DWORD PTR [eax+0x14],ebx
0x56ce1b     7212                             jb     0x56ce2f
0x56ce1d     8b10                             mov    edx,DWORD PTR [eax]
0x56ce1f     eb10                             jmp    0x56ce31
0x56ce21     895c2418                         mov    DWORD PTR [esp+0x18],ebx
0x56ce25     b9b007c100                       mov    ecx,0xc107b0
0x56ce2a     e975ffffff                       jmp    0x56cda4
0x56ce2f     8bd0                             mov    edx,eax
0x56ce31     8bc2                             mov    eax,edx
0x56ce33     8d7001                           lea    esi,[eax+0x1]
0x56ce36     8a08                             mov    cl,BYTE PTR [eax]
0x56ce38     40                               inc    eax
0x56ce39     84c9                             test   cl,cl
0x56ce3b     75f9                             jne    0x56ce36
0x56ce3d     2bc6                             sub    eax,esi
0x56ce3f     7511                             jne    0x56ce52
0x56ce41     50                               push   eax
0x56ce42     687523bf00                       push   0xbf2375
0x56ce47     8d4c2424                         lea    ecx,[esp+0x24]
0x56ce4b     e8205ce9ff                       call   0x402a70
0x56ce50     eb29                             jmp    0x56ce7b
0x56ce52     8bc2                             mov    eax,edx
0x56ce54     8d7001                           lea    esi,[eax+0x1]
0x56ce57     8a08                             mov    cl,BYTE PTR [eax]
0x56ce59     40                               inc    eax
0x56ce5a     84c9                             test   cl,cl
0x56ce5c     75f9                             jne    0x56ce57
0x56ce5e     2bc6                             sub    eax,esi
0x56ce60     50                               push   eax
0x56ce61     52                               push   edx
0x56ce62     8d4c2424                         lea    ecx,[esp+0x24]
0x56ce66     e85551e9ff                       call   0x401fc0
0x56ce6b     6a04                             push   0x4
0x56ce6d     68fc07c100                       push   0xc107fc
0x56ce72     8d4c2424                         lea    ecx,[esp+0x24]
0x56ce76     e84551e9ff                       call   0x401fc0
0x56ce7b     8b44241c                         mov    eax,DWORD PTR [esp+0x1c]
0x56ce7f     395c2430                         cmp    DWORD PTR [esp+0x30],ebx
0x56ce83     7304                             jae    0x56ce89
0x56ce85     8d44241c                         lea    eax,[esp+0x1c]
0x56ce89     33c9                             xor    ecx,ecx
0x56ce8b     394c2418                         cmp    DWORD PTR [esp+0x18],ecx
0x56ce8f     0f94c1                           sete   cl
0x56ce92     51                               push   ecx
0x56ce93     8b0f                             mov    ecx,DWORD PTR [edi]
0x56ce95     50                               push   eax
0x56ce96     e8f5180000                       call   0x56e790
0x56ce9b     8b0f                             mov    ecx,DWORD PTR [edi]
0x56ce9d     e83e180000                       call   0x56e6e0
0x56cea2     8b1538a8fb00                     mov    edx,DWORD PTR ds:0xfba838
0x56cea8     8b4240                           mov    eax,DWORD PTR [edx+0x40]
0x56ceab     85c0                             test   eax,eax
0x56cead     741c                             je     0x56cecb
0x56ceaf     8b905c010000                     mov    edx,DWORD PTR [eax+0x15c]
0x56ceb5     8b8858010000                     mov    ecx,DWORD PTR [eax+0x158]
0x56cebb     89542414                         mov    DWORD PTR [esp+0x14],edx
0x56cebf     f30f10442414                     movss  xmm0,DWORD PTR [esp+0x14]
0x56cec5     894c2410                         mov    DWORD PTR [esp+0x10],ecx
0x56cec9     eb03                             jmp    0x56cece
0x56cecb     0f57c0                           xorps  xmm0,xmm0
0x56cece     8b07                             mov    eax,DWORD PTR [edi]
0x56ced0     f30f114064                       movss  DWORD PTR [eax+0x64],xmm0
0x56ced5     395c2430                         cmp    DWORD PTR [esp+0x30],ebx
0x56ced9     720d                             jb     0x56cee8
0x56cedb     8b4c241c                         mov    ecx,DWORD PTR [esp+0x1c]
0x56cedf     51                               push   ecx
0x56cee0     e827433200                       call   0x89120c
0x56cee5     83c404                           add    esp,0x4
0x56cee8     8b4c2440                         mov    ecx,DWORD PTR [esp+0x40]
0x56ceec     64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x56cef3     59                               pop    ecx
0x56cef4     5e                               pop    esi
0x56cef5     5b                               pop    ebx
0x56cef6     8b4c242c                         mov    ecx,DWORD PTR [esp+0x2c]
0x56cefa     33cc                             xor    ecx,esp
0x56cefc     e800413200                       call   0x891001
