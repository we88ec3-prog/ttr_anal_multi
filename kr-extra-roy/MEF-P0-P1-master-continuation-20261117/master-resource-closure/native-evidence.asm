; master_property_name_lookup | exact property name map lookup used for EncSetting; missing map entry returns zero
0x717410 55 push   ebp
0x717411 8bec mov    ebp,esp
0x717413 6aff push   0xffffffff
0x717415 68e8969100 push   0x9196e8
0x71741a 64a100000000 mov    eax,fs:0x0
0x717420 50 push   eax
0x717421 83ec28 sub    esp,0x28
0x717424 a1201fd600 mov    eax,ds:0xd61f20
0x717429 33c5 xor    eax,ebp
0x71742b 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x71742e 53 push   ebx
0x71742f 56 push   esi
0x717430 57 push   edi
0x717431 50 push   eax
0x717432 8d45f4 lea    eax,[ebp-0xc]
0x717435 64a300000000 mov    fs:0x0,eax
0x71743b 8bf9 mov    edi,ecx
0x71743d 8b4d08 mov    ecx,DWORD PTR [ebp+0x8]
0x717440 33db xor    ebx,ebx
0x717442 8bc1 mov    eax,ecx
0x717444 c745e80f000000 mov    DWORD PTR [ebp-0x18],0xf
0x71744b 895de4 mov    DWORD PTR [ebp-0x1c],ebx
0x71744e 885dd4 mov    BYTE PTR [ebp-0x2c],bl
0x717451 8d7001 lea    esi,[eax+0x1]
0x717454 8a10 mov    dl,BYTE PTR [eax]
0x717456 40 inc    eax
0x717457 3ad3 cmp    dl,bl
0x717459 75f9 jne    0x717454
0x71745b 51 push   ecx
0x71745c 2bc6 sub    eax,esi
0x71745e 8d4dd4 lea    ecx,[ebp-0x2c]
0x717461 e8aa3ecfff call   0x40b310
0x717466 8d45d4 lea    eax,[ebp-0x2c]
0x717469 50 push   eax
0x71746a 8d8720010000 lea    eax,[edi+0x120]
0x717470 895dfc mov    DWORD PTR [ebp-0x4],ebx
0x717473 e8484d0f00 call   0x80c1c0
0x717478 8945cc mov    DWORD PTR [ebp-0x34],eax
0x71747b 3b8724010000 cmp    eax,DWORD PTR [edi+0x124]
0x717481 7414 je     0x717497
0x717483 83c00c add    eax,0xc
0x717486 8d4dd4 lea    ecx,[ebp-0x2c]
0x717489 e812c2e2ff call   0x5436a0
0x71748e 84c0 test   al,al
0x717490 7505 jne    0x717497
0x717492 8d45cc lea    eax,[ebp-0x34]
0x717495 eb0c jmp    0x7174a3
0x717497 8b8f24010000 mov    ecx,DWORD PTR [edi+0x124]
0x71749d 894dd0 mov    DWORD PTR [ebp-0x30],ecx
0x7174a0 8d45d0 lea    eax,[ebp-0x30]
0x7174a3 837de810 cmp    DWORD PTR [ebp-0x18],0x10
0x7174a7 8b30 mov    esi,DWORD PTR [eax]
0x7174a9 720c jb     0x7174b7
0x7174ab 8b55d4 mov    edx,DWORD PTR [ebp-0x2c]
0x7174ae 52 push   edx
0x7174af e8589d1700 call   0x89120c
0x7174b4 83c404 add    esp,0x4
0x7174b7 c745e80f000000 mov    DWORD PTR [ebp-0x18],0xf
0x7174be 895de4 mov    DWORD PTR [ebp-0x1c],ebx
0x7174c1 885dd4 mov    BYTE PTR [ebp-0x2c],bl
0x7174c4 3bb724010000 cmp    esi,DWORD PTR [edi+0x124]
0x7174ca 7405 je     0x7174d1
0x7174cc 8b4628 mov    eax,DWORD PTR [esi+0x28]
0x7174cf eb02 jmp    0x7174d3
0x7174d1 33c0 xor    eax,eax
0x7174d3 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x7174d6 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x7174dd 59 pop    ecx
0x7174de 5f pop    edi
0x7174df 5e pop    esi
0x7174e0 5b pop    ebx
0x7174e1 8b4df0 mov    ecx,DWORD PTR [ebp-0x10]
0x7174e4 33cd xor    ecx,ebp
0x7174e6 e8169b1700 call   0x891001
0x7174eb 8be5 mov    esp,ebp
0x7174ed 5d pop    ebp
0x7174ee c20400 ret    0x4

; resource_probe_return_classes | mounted exact path returns3; accessible loose path1; 717B60-recognized source2; no accepted source0
0x714550 55 push   ebp
0x714551 8bec mov    ebp,esp
0x714553 6aff push   0xffffffff
0x714555 68b4159200 push   0x9215b4
0x71455a 64a100000000 mov    eax,fs:0x0
0x714560 50 push   eax
0x714561 83ec20 sub    esp,0x20
0x714564 a1201fd600 mov    eax,ds:0xd61f20
0x714569 33c5 xor    eax,ebp
0x71456b 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x71456e 53 push   ebx
0x71456f 56 push   esi
0x714570 57 push   edi
0x714571 50 push   eax
0x714572 8d45f4 lea    eax,[ebp-0xc]
0x714575 64a300000000 mov    fs:0x0,eax
0x71457b a114a8fb00 mov    eax,ds:0xfba814
0x714580 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x714583 85c0 test   eax,eax
0x714585 7419 je     0x7145a0
0x714587 6a00 push   0x0
0x714589 53 push   ebx
0x71458a 8d4804 lea    ecx,[eax+0x4]
0x71458d e8be060000 call   0x714c50
0x714592 85c0 test   eax,eax
0x714594 740a je     0x7145a0
0x714596 b803000000 mov    eax,0x3
0x71459b e9b0010000 jmp    0x714750
0x7145a0 83ceff or     esi,0xffffffff
0x7145a3 f605984cfe0001 test   BYTE PTR ds:0xfe4c98,0x1
0x7145aa 7523 jne    0x7145cf
0x7145ac 830d984cfe0001 or     DWORD PTR ds:0xfe4c98,0x1
0x7145b3 c745fc00000000 mov    DWORD PTR [ebp-0x4],0x0
0x7145ba e811fdffff call   0x7142d0
0x7145bf 686007bd00 push   0xbd0760
0x7145c4 e851dd1700 call   0x89231a
0x7145c9 83c404 add    esp,0x4
0x7145cc 8975fc mov    DWORD PTR [ebp-0x4],esi
0x7145cf 803d944cfe0000 cmp    BYTE PTR ds:0xfe4c94,0x0
0x7145d6 7451 je     0x714629
0x7145d8 f605984cfe0001 test   BYTE PTR ds:0xfe4c98,0x1
0x7145df 7523 jne    0x714604
0x7145e1 b801000000 mov    eax,0x1
0x7145e6 0905984cfe00 or     DWORD PTR ds:0xfe4c98,eax
0x7145ec 8945fc mov    DWORD PTR [ebp-0x4],eax
0x7145ef e8dcfcffff call   0x7142d0
0x7145f4 686007bd00 push   0xbd0760
0x7145f9 e81cdd1700 call   0x89231a
0x7145fe 83c404 add    esp,0x4
0x714601 8975fc mov    DWORD PTR [ebp-0x4],esi
0x714604 8bcb mov    ecx,ebx
0x714606 bf7c4cfe00 mov    edi,0xfe4c7c
0x71460b e8a0fdffff call   0x7143b0
0x714610 84c0 test   al,al
0x714612 7515 jne    0x714629
0x714614 e847fcffff call   0x714260
0x714619 50 push   eax
0x71461a 8bcb mov    ecx,ebx
0x71461c e84ffeffff call   0x714470
0x714621 84c0 test   al,al
0x714623 0f8425010000 je     0x71474e
0x714629 f6054c36fe0001 test   BYTE PTR ds:0xfe364c,0x1
0x714630 7522 jne    0x714654
0x714632 830d4c36fe0001 or     DWORD PTR ds:0xfe364c,0x1
0x714639 6800010000 push   0x100
0x71463e 6a00 push   0x0
0x714640 684835fe00 push   0xfe3548
0x714645 c6054836fe0000 mov    BYTE PTR ds:0xfe3648,0x0
0x71464c e80fa21800 call   0x89e860
0x714651 83c40c add    esp,0xc
0x714654 803d4836fe0000 cmp    BYTE PTR ds:0xfe3648,0x0
0x71465b 0f84c0000000 je     0x714721
0x714661 e88af9ffff call   0x713ff0
0x714666 8bc8 mov    ecx,eax
0x714668 c745e80f000000 mov    DWORD PTR [ebp-0x18],0xf
0x71466f c745e400000000 mov    DWORD PTR [ebp-0x1c],0x0
0x714676 c645d400 mov    BYTE PTR [ebp-0x2c],0x0
0x71467a 8d7101 lea    esi,[ecx+0x1]
0x71467d 8d4900 lea    ecx,[ecx+0x0]
0x714680 8a11 mov    dl,BYTE PTR [ecx]
0x714682 41 inc    ecx
0x714683 84d2 test   dl,dl
0x714685 75f9 jne    0x714680
0x714687 2bce sub    ecx,esi
0x714689 51 push   ecx
0x71468a 50 push   eax
0x71468b 8d4dd4 lea    ecx,[ebp-0x2c]
0x71468e e8dde3ceff call   0x402a70
0x714693 8bc3 mov    eax,ebx
0x714695 c745fc02000000 mov    DWORD PTR [ebp-0x4],0x2
0x71469c 8d5001 lea    edx,[eax+0x1]
0x71469f 90 nop
0x7146a0 8a08 mov    cl,BYTE PTR [eax]
0x7146a2 40 inc    eax
0x7146a3 84c9 test   cl,cl
0x7146a5 75f9 jne    0x7146a0
0x7146a7 2bc2 sub    eax,edx
0x7146a9 50 push   eax
0x7146aa 53 push   ebx
0x7146ab 8d4dd4 lea    ecx,[ebp-0x2c]
0x7146ae e80dd9ceff call   0x401fc0
0x7146b3 8b45d4 mov    eax,DWORD PTR [ebp-0x2c]
0x7146b6 be10000000 mov    esi,0x10
0x7146bb 3975e8 cmp    DWORD PTR [ebp-0x18],esi
0x7146be 7303 jae    0x7146c3
0x7146c0 8d45d4 lea    eax,[ebp-0x2c]
0x7146c3 e898340000 call   0x717b60
0x7146c8 85c0 test   eax,eax
0x7146ca 7418 je     0x7146e4
0x7146cc 3975e8 cmp    DWORD PTR [ebp-0x18],esi
0x7146cf 720c jb     0x7146dd
0x7146d1 8b45d4 mov    eax,DWORD PTR [ebp-0x2c]
0x7146d4 50 push   eax
0x7146d5 e832cb1700 call   0x89120c
0x7146da 83c404 add    esp,0x4
0x7146dd b802000000 mov    eax,0x2
0x7146e2 eb6c jmp    0x714750
0x7146e4 8b45d4 mov    eax,DWORD PTR [ebp-0x2c]
0x7146e7 3975e8 cmp    DWORD PTR [ebp-0x18],esi
0x7146ea 7303 jae    0x7146ef
0x7146ec 8d45d4 lea    eax,[ebp-0x2c]
0x7146ef 68e0d1be00 push   0xbed1e0
0x7146f4 50 push   eax
0x7146f5 e881d11700 call   0x89187b
0x7146fa 83c408 add    esp,0x8
0x7146fd 85c0 test   eax,eax
0x7146ff 7418 je     0x714719
0x714701 50 push   eax
0x714702 e8c2d51700 call   0x891cc9
0x714707 83c404 add    esp,0x4
0x71470a 8d4dd4 lea    ecx,[ebp-0x2c]
0x71470d e83ee5ceff call   0x402c50
0x714712 b801000000 mov    eax,0x1
0x714717 eb37 jmp    0x714750
0x714719 8d4dd4 lea    ecx,[ebp-0x2c]
0x71471c e82fe5ceff call   0x402c50
0x714721 8bc3 mov    eax,ebx
0x714723 e838340000 call   0x717b60
0x714728 85c0 test   eax,eax
0x71472a 75b1 jne    0x7146dd
0x71472c 68e0d1be00 push   0xbed1e0
0x714731 53 push   ebx
0x714732 e844d11700 call   0x89187b
0x714737 83c408 add    esp,0x8
0x71473a 85c0 test   eax,eax
0x71473c 7410 je     0x71474e
0x71473e 50 push   eax
0x71473f e885d51700 call   0x891cc9
0x714744 83c404 add    esp,0x4
0x714747 b801000000 mov    eax,0x1
0x71474c eb02 jmp    0x714750
0x71474e 33c0 xor    eax,eax
0x714750 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x714753 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x71475a 59 pop    ecx
0x71475b 5f pop    edi
0x71475c 5e pop    esi
0x71475d 5b pop    ebx
0x71475e 8b4df0 mov    ecx,DWORD PTR [ebp-0x10]
0x714761 33cd xor    ecx,ebp
0x714763 e899c81700 call   0x891001
0x714768 8be5 mov    esp,ebp
0x71476a 5d pop    ebp
0x71476b c3 ret

; mesh_path_policy | if manager+300 is nonzero and original probe=0, replace extension by .emf and return1; otherwise preserve original and return0
0x79bce0 55 push   ebp
0x79bce1 8bec mov    ebp,esp
0x79bce3 81ec54010000 sub    esp,0x154
0x79bce9 a1201fd600 mov    eax,ds:0xd61f20
0x79bcee 33c5 xor    eax,ebp
0x79bcf0 8945fc mov    DWORD PTR [ebp-0x4],eax
0x79bcf3 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x79bcf6 53 push   ebx
0x79bcf7 33db xor    ebx,ebx
0x79bcf9 399800030000 cmp    DWORD PTR [eax+0x300],ebx
0x79bcff 0f84c4000000 je     0x79bdc9
0x79bd05 56 push   esi
0x79bd06 e84588f7ff call   0x714550
0x79bd0b 83c404 add    esp,0x4
0x79bd0e 85c0 test   eax,eax
0x79bd10 7411 je     0x79bd23
0x79bd12 8bc6 mov    eax,esi
0x79bd14 8d5001 lea    edx,[eax+0x1]
0x79bd17 8a08 mov    cl,BYTE PTR [eax]
0x79bd19 40 inc    eax
0x79bd1a 84c9 test   cl,cl
0x79bd1c 75f9 jne    0x79bd17
0x79bd1e e9b4000000 jmp    0x79bdd7
0x79bd23 8d4df4 lea    ecx,[ebp-0xc]
0x79bd26 51 push   ecx
0x79bd27 8d55b4 lea    edx,[ebp-0x4c]
0x79bd2a 52 push   edx
0x79bd2b 8d85b0feffff lea    eax,[ebp-0x150]
0x79bd31 50 push   eax
0x79bd32 8d8dacfeffff lea    ecx,[ebp-0x154]
0x79bd38 51 push   ecx
0x79bd39 56 push   esi
0x79bd3a e8fdfb0f00 call   0x89b93c
0x79bd3f 8d85acfeffff lea    eax,[ebp-0x154]
0x79bd45 83c414 add    esp,0x14
0x79bd48 8d5001 lea    edx,[eax+0x1]
0x79bd4b eb03 jmp    0x79bd50
0x79bd4d 8d4900 lea    ecx,[ecx+0x0]
0x79bd50 8a08 mov    cl,BYTE PTR [eax]
0x79bd52 40 inc    eax
0x79bd53 84c9 test   cl,cl
0x79bd55 75f9 jne    0x79bd50
0x79bd57 2bc2 sub    eax,edx
0x79bd59 50 push   eax
0x79bd5a 8d95acfeffff lea    edx,[ebp-0x154]
0x79bd60 52 push   edx
0x79bd61 8bcf mov    ecx,edi
0x79bd63 e8086dc6ff call   0x402a70
0x79bd68 8d85b0feffff lea    eax,[ebp-0x150]
0x79bd6e 8d5001 lea    edx,[eax+0x1]
0x79bd71 8a08 mov    cl,BYTE PTR [eax]
0x79bd73 40 inc    eax
0x79bd74 84c9 test   cl,cl
0x79bd76 75f9 jne    0x79bd71
0x79bd78 2bc2 sub    eax,edx
0x79bd7a 50 push   eax
0x79bd7b 8d85b0feffff lea    eax,[ebp-0x150]
0x79bd81 50 push   eax
0x79bd82 8bcf mov    ecx,edi
0x79bd84 e83762c6ff call   0x401fc0
0x79bd89 8d45b4 lea    eax,[ebp-0x4c]
0x79bd8c 8d5001 lea    edx,[eax+0x1]
0x79bd8f 90 nop
0x79bd90 8a08 mov    cl,BYTE PTR [eax]
0x79bd92 40 inc    eax
0x79bd93 84c9 test   cl,cl
0x79bd95 75f9 jne    0x79bd90
0x79bd97 2bc2 sub    eax,edx
0x79bd99 50 push   eax
0x79bd9a 8d4db4 lea    ecx,[ebp-0x4c]
0x79bd9d 51 push   ecx
0x79bd9e 8bcf mov    ecx,edi
0x79bda0 e81b62c6ff call   0x401fc0
0x79bda5 6a04 push   0x4
0x79bda7 68680fc400 push   0xc40f68
0x79bdac 8bcf mov    ecx,edi
0x79bdae e80d62c6ff call   0x401fc0
0x79bdb3 b801000000 mov    eax,0x1
0x79bdb8 5b pop    ebx
0x79bdb9 8b4dfc mov    ecx,DWORD PTR [ebp-0x4]
0x79bdbc 33cd xor    ecx,ebp
0x79bdbe e83e520f00 call   0x891001
0x79bdc3 8be5 mov    esp,ebp
0x79bdc5 5d pop    ebp
0x79bdc6 c20400 ret    0x4
0x79bdc9 8bc6 mov    eax,esi
0x79bdcb 8d5001 lea    edx,[eax+0x1]
0x79bdce 8bff mov    edi,edi
0x79bdd0 8a08 mov    cl,BYTE PTR [eax]
0x79bdd2 40 inc    eax
0x79bdd3 84c9 test   cl,cl
0x79bdd5 75f9 jne    0x79bdd0
0x79bdd7 2bc2 sub    eax,edx
0x79bdd9 50 push   eax
0x79bdda 56 push   esi
0x79bddb 8bcf mov    ecx,edi
0x79bddd e88e6cc6ff call   0x402a70
0x79bde2 8b4dfc mov    ecx,DWORD PTR [ebp-0x4]
0x79bde5 8bc3 mov    eax,ebx
0x79bde7 33cd xor    ecx,ebp
0x79bde9 5b pop    ebx
0x79bdea e812520f00 call   0x891001
0x79bdef 8be5 mov    esp,ebp
0x79bdf1 5d pop    ebp
0x79bdf2 c20400 ret    0x4

; mesh_acquire_render_loader | existing resident resource can return before file probe; first read 79BCE0 then packed7CBF70/original7CBEE0
0x7d0920 55 push   ebp
0x7d0921 8bec mov    ebp,esp
0x7d0923 6aff push   0xffffffff
0x7d0925 6882239300 push   0x932382
0x7d092a 64a100000000 mov    eax,fs:0x0
0x7d0930 50 push   eax
0x7d0931 81ec80000000 sub    esp,0x80
0x7d0937 a1201fd600 mov    eax,ds:0xd61f20
0x7d093c 33c5 xor    eax,ebp
0x7d093e 8945ec mov    DWORD PTR [ebp-0x14],eax
0x7d0941 53 push   ebx
0x7d0942 56 push   esi
0x7d0943 57 push   edi
0x7d0944 50 push   eax
0x7d0945 8d45f4 lea    eax,[ebp-0xc]
0x7d0948 64a300000000 mov    fs:0x0,eax
0x7d094e 33db xor    ebx,ebx
0x7d0950 8bf1 mov    esi,ecx
0x7d0952 8bfa mov    edi,edx
0x7d0954 895d8c mov    DWORD PTR [ebp-0x74],ebx
0x7d0957 6864abfb00 push   0xfbab64
0x7d095c 89b578ffffff mov    DWORD PTR [ebp-0x88],esi
0x7d0962 897d88 mov    DWORD PTR [ebp-0x78],edi
0x7d0965 895d90 mov    DWORD PTR [ebp-0x70],ebx
0x7d0968 c7458464abfb00 mov    DWORD PTR [ebp-0x7c],0xfbab64
0x7d096f ff154c22bd00 call   DWORD PTR ds:0xbd224c
0x7d0975 895dfc mov    DWORD PTR [ebp-0x4],ebx
0x7d0978 8bc7 mov    eax,edi
0x7d097a c745c80f000000 mov    DWORD PTR [ebp-0x38],0xf
0x7d0981 895dc4 mov    DWORD PTR [ebp-0x3c],ebx
0x7d0984 885db4 mov    BYTE PTR [ebp-0x4c],bl
0x7d0987 8d4801 lea    ecx,[eax+0x1]
0x7d098a 8d9b00000000 lea    ebx,[ebx+0x0]
0x7d0990 8a10 mov    dl,BYTE PTR [eax]
0x7d0992 40 inc    eax
0x7d0993 84d2 test   dl,dl
0x7d0995 75f9 jne    0x7d0990
0x7d0997 2bc1 sub    eax,ecx
0x7d0999 50 push   eax
0x7d099a 57 push   edi
0x7d099b 8d4db4 lea    ecx,[ebp-0x4c]
0x7d099e e8cd20c3ff call   0x402a70
0x7d09a3 8d45b4 lea    eax,[ebp-0x4c]
0x7d09a6 50 push   eax
0x7d09a7 8d4d80 lea    ecx,[ebp-0x80]
0x7d09aa 51 push   ecx
0x7d09ab 8bc6 mov    eax,esi
0x7d09ad c645fc01 mov    BYTE PTR [ebp-0x4],0x1
0x7d09b1 e83a7dfeff call   0x7b86f0
0x7d09b6 c645fc00 mov    BYTE PTR [ebp-0x4],0x0
0x7d09ba 837dc810 cmp    DWORD PTR [ebp-0x38],0x10
0x7d09be 720c jb     0x7d09cc
0x7d09c0 8b55b4 mov    edx,DWORD PTR [ebp-0x4c]
0x7d09c3 52 push   edx
0x7d09c4 e843080c00 call   0x89120c
0x7d09c9 83c404 add    esp,0x4
0x7d09cc 8b4d80 mov    ecx,DWORD PTR [ebp-0x80]
0x7d09cf 3b4e04 cmp    ecx,DWORD PTR [esi+0x4]
0x7d09d2 740b je     0x7d09df
0x7d09d4 8b5924 mov    ebx,DWORD PTR [ecx+0x24]
0x7d09d7 ff4304 inc    DWORD PTR [ebx+0x4]
0x7d09da e9c9000000 jmp    0x7d0aa8
0x7d09df 6a0c push   0xc
0x7d09e1 e882080c00 call   0x891268
0x7d09e6 83c404 add    esp,0x4
0x7d09e9 3bc3 cmp    eax,ebx
0x7d09eb 740c je     0x7d09f9
0x7d09ed 8918 mov    DWORD PTR [eax],ebx
0x7d09ef 895804 mov    DWORD PTR [eax+0x4],ebx
0x7d09f2 895808 mov    DWORD PTR [eax+0x8],ebx
0x7d09f5 8bf8 mov    edi,eax
0x7d09f7 eb02 jmp    0x7d09fb
0x7d09f9 33ff xor    edi,edi
0x7d09fb b801000000 mov    eax,0x1
0x7d0a00 894704 mov    DWORD PTR [edi+0x4],eax
0x7d0a03 894590 mov    DWORD PTR [ebp-0x70],eax
0x7d0a06 8b4588 mov    eax,DWORD PTR [ebp-0x78]
0x7d0a09 8bdf mov    ebx,edi
0x7d0a0b c70700000000 mov    DWORD PTR [edi],0x0
0x7d0a11 c745a80f000000 mov    DWORD PTR [ebp-0x58],0xf
0x7d0a18 c745a400000000 mov    DWORD PTR [ebp-0x5c],0x0
0x7d0a1f c6459400 mov    BYTE PTR [ebp-0x6c],0x0
0x7d0a23 8d4801 lea    ecx,[eax+0x1]
0x7d0a26 8a10 mov    dl,BYTE PTR [eax]
0x7d0a28 40 inc    eax
0x7d0a29 84d2 test   dl,dl
0x7d0a2b 75f9 jne    0x7d0a26
0x7d0a2d 2bc1 sub    eax,ecx
0x7d0a2f 50 push   eax
0x7d0a30 8b4588 mov    eax,DWORD PTR [ebp-0x78]
0x7d0a33 50 push   eax
0x7d0a34 8d4d94 lea    ecx,[ebp-0x6c]
0x7d0a37 e83420c3ff call   0x402a70
0x7d0a3c 897db0 mov    DWORD PTR [ebp-0x50],edi
0x7d0a3f c645fc02 mov    BYTE PTR [ebp-0x4],0x2
0x7d0a43 8b4604 mov    eax,DWORD PTR [esi+0x4]
0x7d0a46 8b38 mov    edi,DWORD PTR [eax]
0x7d0a48 8b5704 mov    edx,DWORD PTR [edi+0x4]
0x7d0a4b 8d4d94 lea    ecx,[ebp-0x6c]
0x7d0a4e 51 push   ecx
0x7d0a4f 52 push   edx
0x7d0a50 57 push   edi
0x7d0a51 e83a91f4ff call   0x719b90
0x7d0a56 8b4e08 mov    ecx,DWORD PTR [esi+0x8]
0x7d0a59 bafeffff07 mov    edx,0x7fffffe
0x7d0a5e 2bd1 sub    edx,ecx
0x7d0a60 83fa01 cmp    edx,0x1
0x7d0a63 730a jae    0x7d0a6f
0x7d0a65 683420bf00 push   0xbf2034
0x7d0a6a e8c1d00a00 call   0x87db30
0x7d0a6f 41 inc    ecx
0x7d0a70 894e08 mov    DWORD PTR [esi+0x8],ecx
0x7d0a73 894704 mov    DWORD PTR [edi+0x4],eax
0x7d0a76 8b4804 mov    ecx,DWORD PTR [eax+0x4]
0x7d0a79 8901 mov    DWORD PTR [ecx],eax
0x7d0a7b 8b4604 mov    eax,DWORD PTR [esi+0x4]
0x7d0a7e 8b08 mov    ecx,DWORD PTR [eax]
0x7d0a80 51 push   ecx
0x7d0a81 8d4108 lea    eax,[ecx+0x8]
0x7d0a84 50 push   eax
0x7d0a85 8d857cffffff lea    eax,[ebp-0x84]
0x7d0a8b 50 push   eax
0x7d0a8c 8bce mov    ecx,esi
0x7d0a8e e8ed050000 call   0x7d1080
0x7d0a93 837da810 cmp    DWORD PTR [ebp-0x58],0x10
0x7d0a97 720c jb     0x7d0aa5
0x7d0a99 8b4d94 mov    ecx,DWORD PTR [ebp-0x6c]
0x7d0a9c 51 push   ecx
0x7d0a9d e86a070c00 call   0x89120c
0x7d0aa2 83c404 add    esp,0x4
0x7d0aa5 8b7d88 mov    edi,DWORD PTR [ebp-0x78]
0x7d0aa8 6864abfb00 push   0xfbab64
0x7d0aad c745fcffffffff mov    DWORD PTR [ebp-0x4],0xffffffff
0x7d0ab4 ff154822bd00 call   DWORD PTR ds:0xbd2248
0x7d0aba 8b03 mov    eax,DWORD PTR [ebx]
0x7d0abc 83f801 cmp    eax,0x1
0x7d0abf 7568 jne    0x7d0b29
0x7d0ac1 837b0800 cmp    DWORD PTR [ebx+0x8],0x0
0x7d0ac5 7462 je     0x7d0b29
0x7d0ac7 6804010000 push   0x104
0x7d0acc e897070c00 call   0x891268
0x7d0ad1 8bf0 mov    esi,eax
0x7d0ad3 83c404 add    esp,0x4
0x7d0ad6 897584 mov    DWORD PTR [ebp-0x7c],esi
0x7d0ad9 c745fc03000000 mov    DWORD PTR [ebp-0x4],0x3
0x7d0ae0 85f6 test   esi,esi
0x7d0ae2 7426 je     0x7d0b0a
0x7d0ae4 57 push   edi
0x7d0ae5 8d4d98 lea    ecx,[ebp-0x68]
0x7d0ae8 e88320c3ff call   0x402b70
0x7d0aed c645fc04 mov    BYTE PTR [ebp-0x4],0x4
0x7d0af1 8b4308 mov    eax,DWORD PTR [ebx+0x8]
0x7d0af4 8d5598 lea    edx,[ebp-0x68]
0x7d0af7 52 push   edx
0x7d0af8 50 push   eax
0x7d0af9 56 push   esi
0x7d0afa c7458c01000000 mov    DWORD PTR [ebp-0x74],0x1
0x7d0b01 e85afbffff call   0x7d0660
0x7d0b06 8bf0 mov    esi,eax
0x7d0b08 eb02 jmp    0x7d0b0c
0x7d0b0a 33f6 xor    esi,esi
0x7d0b0c f6458c01 test   BYTE PTR [ebp-0x74],0x1
0x7d0b10 0f84d9020000 je     0x7d0def
0x7d0b16 837dac10 cmp    DWORD PTR [ebp-0x54],0x10
0x7d0b1a 0f82cf020000 jb     0x7d0def
0x7d0b20 8b4d98 mov    ecx,DWORD PTR [ebp-0x68]
0x7d0b23 51 push   ecx
0x7d0b24 e9be020000 jmp    0x7d0de7
0x7d0b29 837d9000 cmp    DWORD PTR [ebp-0x70],0x0
0x7d0b2d 0f8589000000 jne    0x7d0bbc
0x7d0b33 83f803 cmp    eax,0x3
0x7d0b36 7418 je     0x7d0b50
0x7d0b38 833b01 cmp    DWORD PTR [ebx],0x1
0x7d0b3b 7506 jne    0x7d0b43
0x7d0b3d 837b0800 cmp    DWORD PTR [ebx+0x8],0x0
0x7d0b41 751d jne    0x7d0b60
0x7d0b43 6a0a push   0xa
0x7d0b45 ff150423bd00 call   DWORD PTR ds:0xbd2304
0x7d0b4b 833b03 cmp    DWORD PTR [ebx],0x3
0x7d0b4e 75e8 jne    0x7d0b38
0x7d0b50 8bd7 mov    edx,edi
0x7d0b52 8bce mov    ecx,esi
0x7d0b54 e8b7020000 call   0x7d0e10
0x7d0b59 33c0 xor    eax,eax
0x7d0b5b e991020000 jmp    0x7d0df1
0x7d0b60 6804010000 push   0x104
0x7d0b65 e8fe060c00 call   0x891268
0x7d0b6a 8bf0 mov    esi,eax
0x7d0b6c 83c404 add    esp,0x4
0x7d0b6f 897584 mov    DWORD PTR [ebp-0x7c],esi
0x7d0b72 c745fc06000000 mov    DWORD PTR [ebp-0x4],0x6
0x7d0b79 85f6 test   esi,esi
0x7d0b7b 7426 je     0x7d0ba3
0x7d0b7d 57 push   edi
0x7d0b7e 8d4d98 lea    ecx,[ebp-0x68]
0x7d0b81 e8ea1fc3ff call   0x402b70
0x7d0b86 c645fc07 mov    BYTE PTR [ebp-0x4],0x7
0x7d0b8a 8b4308 mov    eax,DWORD PTR [ebx+0x8]
0x7d0b8d 8d5598 lea    edx,[ebp-0x68]
0x7d0b90 52 push   edx
0x7d0b91 50 push   eax
0x7d0b92 56 push   esi
0x7d0b93 c7458c02000000 mov    DWORD PTR [ebp-0x74],0x2
0x7d0b9a e8c1faffff call   0x7d0660
0x7d0b9f 8bf0 mov    esi,eax
0x7d0ba1 eb02 jmp    0x7d0ba5
0x7d0ba3 33f6 xor    esi,esi
0x7d0ba5 f6458c02 test   BYTE PTR [ebp-0x74],0x2
0x7d0ba9 0f8440020000 je     0x7d0def
0x7d0baf 8d4d98 lea    ecx,[ebp-0x68]
0x7d0bb2 e89920c3ff call   0x402c50
0x7d0bb7 e933020000 jmp    0x7d0def
0x7d0bbc f605e879fb0001 test   BYTE PTR ds:0xfb79e8,0x1
0x7d0bc3 7520 jne    0x7d0be5
0x7d0bc5 830de879fb0001 or     DWORD PTR ds:0xfb79e8,0x1
0x7d0bcc c745fc09000000 mov    DWORD PTR [ebp-0x4],0x9
0x7d0bd3 e80882fcff call   0x798de0
0x7d0bd8 68e0d2bc00 push   0xbcd2e0
0x7d0bdd e838170c00 call   0x89231a
0x7d0be2 83c404 add    esp,0x4
0x7d0be5 f605e879fb0001 test   BYTE PTR ds:0xfb79e8,0x1
0x7d0bec 8b0da876fb00 mov    ecx,DWORD PTR ds:0xfb76a8
0x7d0bf2 894d90 mov    DWORD PTR [ebp-0x70],ecx
0x7d0bf5 c7458000000000 mov    DWORD PTR [ebp-0x80],0x0
0x7d0bfc 7520 jne    0x7d0c1e
0x7d0bfe 830de879fb0001 or     DWORD PTR ds:0xfb79e8,0x1
0x7d0c05 c745fc0a000000 mov    DWORD PTR [ebp-0x4],0xa
0x7d0c0c e8cf81fcff call   0x798de0
0x7d0c11 68e0d2bc00 push   0xbcd2e0
0x7d0c16 e8ff160c00 call   0x89231a
0x7d0c1b 83c404 add    esp,0x4
0x7d0c1e 68ec76fb00 push   0xfb76ec
0x7d0c23 ff154c22bd00 call   DWORD PTR ds:0xbd224c
0x7d0c29 c745e40f000000 mov    DWORD PTR [ebp-0x1c],0xf
0x7d0c30 c745e000000000 mov    DWORD PTR [ebp-0x20],0x0
0x7d0c37 c645d000 mov    BYTE PTR [ebp-0x30],0x0
0x7d0c3b c745fc0b000000 mov    DWORD PTR [ebp-0x4],0xb
0x7d0c42 f605e879fb0001 test   BYTE PTR ds:0xfb79e8,0x1
0x7d0c49 7521 jne    0x7d0c6c
0x7d0c4b 830de879fb0001 or     DWORD PTR ds:0xfb79e8,0x1
0x7d0c52 c645fc0c mov    BYTE PTR [ebp-0x4],0xc
0x7d0c56 e88581fcff call   0x798de0
0x7d0c5b 68e0d2bc00 push   0xbcd2e0
0x7d0c60 e8b5160c00 call   0x89231a
0x7d0c65 83c404 add    esp,0x4
0x7d0c68 c645fc0b mov    BYTE PTR [ebp-0x4],0xb
0x7d0c6c 8bf7 mov    esi,edi
0x7d0c6e 68a876fb00 push   0xfb76a8
0x7d0c73 8d7dd0 lea    edi,[ebp-0x30]
0x7d0c76 e865b0fcff call   0x79bce0
0x7d0c7b 85c0 test   eax,eax
0x7d0c7d 8b45d0 mov    eax,DWORD PTR [ebp-0x30]
0x7d0c80 741c je     0x7d0c9e
0x7d0c82 bf10000000 mov    edi,0x10
0x7d0c87 397de4 cmp    DWORD PTR [ebp-0x1c],edi
0x7d0c8a 7303 jae    0x7d0c8f
0x7d0c8c 8d45d0 lea    eax,[ebp-0x30]
0x7d0c8f 8b4d90 mov    ecx,DWORD PTR [ebp-0x70]
0x7d0c92 8d5580 lea    edx,[ebp-0x80]
0x7d0c95 52 push   edx
0x7d0c96 51 push   ecx
0x7d0c97 e8d4b2ffff call   0x7cbf70
0x7d0c9c eb1b jmp    0x7d0cb9
0x7d0c9e 837de410 cmp    DWORD PTR [ebp-0x1c],0x10
0x7d0ca2 7303 jae    0x7d0ca7
0x7d0ca4 8d45d0 lea    eax,[ebp-0x30]
0x7d0ca7 8b4d90 mov    ecx,DWORD PTR [ebp-0x70]
0x7d0caa 8d5580 lea    edx,[ebp-0x80]
0x7d0cad 52 push   edx
0x7d0cae 51 push   ecx
0x7d0caf e82cb2ffff call   0x7cbee0
0x7d0cb4 bf10000000 mov    edi,0x10
0x7d0cb9 83c408 add    esp,0x8
0x7d0cbc 85c0 test   eax,eax
0x7d0cbe 7561 jne    0x7d0d21
0x7d0cc0 f605e879fb0001 test   BYTE PTR ds:0xfb79e8,0x1
0x7d0cc7 7521 jne    0x7d0cea
0x7d0cc9 830de879fb0001 or     DWORD PTR ds:0xfb79e8,0x1
0x7d0cd0 c645fc0d mov    BYTE PTR [ebp-0x4],0xd
0x7d0cd4 e80781fcff call   0x798de0
0x7d0cd9 68e0d2bc00 push   0xbcd2e0
0x7d0cde e837160c00 call   0x89231a
0x7d0ce3 83c404 add    esp,0x4
0x7d0ce6 c645fc0b mov    BYTE PTR [ebp-0x4],0xb
0x7d0cea 68ec76fb00 push   0xfb76ec
0x7d0cef ff154822bd00 call   DWORD PTR ds:0xbd2248
0x7d0cf5 8b5588 mov    edx,DWORD PTR [ebp-0x78]
0x7d0cf8 8b8d78ffffff mov    ecx,DWORD PTR [ebp-0x88]
0x7d0cfe c70303000000 mov    DWORD PTR [ebx],0x3
0x7d0d04 e807010000 call   0x7d0e10
0x7d0d09 397de4 cmp    DWORD PTR [ebp-0x1c],edi
0x7d0d0c 720c jb     0x7d0d1a
0x7d0d0e 8b55d0 mov    edx,DWORD PTR [ebp-0x30]
0x7d0d11 52 push   edx
0x7d0d12 e8f5040c00 call   0x89120c
0x7d0d17 83c404 add    esp,0x4
0x7d0d1a 33c0 xor    eax,eax
0x7d0d1c e9d0000000 jmp    0x7d0df1
0x7d0d21 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x7d0d24 8b7580 mov    esi,DWORD PTR [ebp-0x80]
0x7d0d27 8b4d90 mov    ecx,DWORD PTR [ebp-0x70]
0x7d0d2a 50 push   eax
0x7d0d2b 56 push   esi
0x7d0d2c 51 push   ecx
0x7d0d2d e8aefaffff call   0x7d07e0
0x7d0d32 f605e879fb0001 test   BYTE PTR ds:0xfb79e8,0x1
0x7d0d39 7521 jne    0x7d0d5c
0x7d0d3b 830de879fb0001 or     DWORD PTR ds:0xfb79e8,0x1
0x7d0d42 c645fc0e mov    BYTE PTR [ebp-0x4],0xe
0x7d0d46 e89580fcff call   0x798de0
0x7d0d4b 68e0d2bc00 push   0xbcd2e0
0x7d0d50 e8c5150c00 call   0x89231a
0x7d0d55 83c404 add    esp,0x4
0x7d0d58 c645fc0b mov    BYTE PTR [ebp-0x4],0xb
0x7d0d5c 68ec76fb00 push   0xfb76ec
0x7d0d61 ff154822bd00 call   DWORD PTR ds:0xbd2248
0x7d0d67 6804010000 push   0x104
0x7d0d6c 897308 mov    DWORD PTR [ebx+0x8],esi
0x7d0d6f c70301000000 mov    DWORD PTR [ebx],0x1
0x7d0d75 e8ee040c00 call   0x891268
0x7d0d7a 8bf0 mov    esi,eax
0x7d0d7c 83c404 add    esp,0x4
0x7d0d7f 897584 mov    DWORD PTR [ebp-0x7c],esi
0x7d0d82 c645fc0f mov    BYTE PTR [ebp-0x4],0xf
0x7d0d86 85f6 test   esi,esi
0x7d0d88 7429 je     0x7d0db3
0x7d0d8a 8b5588 mov    edx,DWORD PTR [ebp-0x78]
0x7d0d8d 52 push   edx
0x7d0d8e 8d4db4 lea    ecx,[ebp-0x4c]
0x7d0d91 e8da1dc3ff call   0x402b70
0x7d0d96 c645fc10 mov    BYTE PTR [ebp-0x4],0x10
0x7d0d9a 8b4b08 mov    ecx,DWORD PTR [ebx+0x8]
0x7d0d9d 8d45b4 lea    eax,[ebp-0x4c]
0x7d0da0 50 push   eax
0x7d0da1 51 push   ecx
0x7d0da2 56 push   esi
0x7d0da3 c7458c04000000 mov    DWORD PTR [ebp-0x74],0x4
0x7d0daa e8b1f8ffff call   0x7d0660
0x7d0daf 8bf0 mov    esi,eax
0x7d0db1 eb02 jmp    0x7d0db5
0x7d0db3 33f6 xor    esi,esi
0x7d0db5 f6458c04 test   BYTE PTR [ebp-0x74],0x4
0x7d0db9 7423 je     0x7d0dde
0x7d0dbb 397dc8 cmp    DWORD PTR [ebp-0x38],edi
0x7d0dbe 720c jb     0x7d0dcc
0x7d0dc0 8b55b4 mov    edx,DWORD PTR [ebp-0x4c]
0x7d0dc3 52 push   edx
0x7d0dc4 e843040c00 call   0x89120c
0x7d0dc9 83c404 add    esp,0x4
0x7d0dcc c745c80f000000 mov    DWORD PTR [ebp-0x38],0xf
0x7d0dd3 c745c400000000 mov    DWORD PTR [ebp-0x3c],0x0
0x7d0dda c645b400 mov    BYTE PTR [ebp-0x4c],0x0
0x7d0dde 397de4 cmp    DWORD PTR [ebp-0x1c],edi
0x7d0de1 720c jb     0x7d0def
0x7d0de3 8b45d0 mov    eax,DWORD PTR [ebp-0x30]
0x7d0de6 50 push   eax
0x7d0de7 e820040c00 call   0x89120c
0x7d0dec 83c404 add    esp,0x4
0x7d0def 8bc6 mov    eax,esi
0x7d0df1 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x7d0df4 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x7d0dfb 59 pop    ecx
0x7d0dfc 5f pop    edi
0x7d0dfd 5e pop    esi
0x7d0dfe 5b pop    ebx
0x7d0dff 8b4dec mov    ecx,DWORD PTR [ebp-0x14]
0x7d0e02 33cd xor    ecx,ebp
0x7d0e04 e8f8010c00 call   0x891001
0x7d0e09 8be5 mov    esp,ebp
0x7d0e0b 5d pop    ebp
0x7d0e0c c20400 ret    0x4

; mesh_original_and_packed_read | both selected paths open714770; original calls862450; packed calls7CC000
0x7cbee0 55 push   ebp
0x7cbee1 8bec mov    ebp,esp
0x7cbee3 51 push   ecx
0x7cbee4 53 push   ebx
0x7cbee5 56 push   esi
0x7cbee6 57 push   edi
0x7cbee7 68e0d1be00 push   0xbed1e0
0x7cbeec 50 push   eax
0x7cbeed e87e88f4ff call   0x714770
0x7cbef2 8bf0 mov    esi,eax
0x7cbef4 83c408 add    esp,0x8
0x7cbef7 85f6 test   esi,esi
0x7cbef9 7506 jne    0x7cbf01
0x7cbefb 5f pop    edi
0x7cbefc 5e pop    esi
0x7cbefd 5b pop    ebx
0x7cbefe 59 pop    ecx
0x7cbeff 5d pop    ebp
0x7cbf00 c3 ret
0x7cbf01 8b16 mov    edx,DWORD PTR [esi]
0x7cbf03 8b422c mov    eax,DWORD PTR [edx+0x2c]
0x7cbf06 8bce mov    ecx,esi
0x7cbf08 ffd0 call   eax
0x7cbf0a 8bf8 mov    edi,eax
0x7cbf0c 57 push   edi
0x7cbf0d e82b1d0b00 call   0x87dc3d
0x7cbf12 8b16 mov    edx,DWORD PTR [esi]
0x7cbf14 83c404 add    esp,0x4
0x7cbf17 6a00 push   0x0
0x7cbf19 8bd8 mov    ebx,eax
0x7cbf1b 8b4234 mov    eax,DWORD PTR [edx+0x34]
0x7cbf1e 6a00 push   0x0
0x7cbf20 8bce mov    ecx,esi
0x7cbf22 ffd0 call   eax
0x7cbf24 8b16 mov    edx,DWORD PTR [esi]
0x7cbf26 8b4210 mov    eax,DWORD PTR [edx+0x10]
0x7cbf29 6a01 push   0x1
0x7cbf2b 57 push   edi
0x7cbf2c 53 push   ebx
0x7cbf2d 8bce mov    ecx,esi
0x7cbf2f ffd0 call   eax
0x7cbf31 8b4d08 mov    ecx,DWORD PTR [ebp+0x8]
0x7cbf34 57 push   edi
0x7cbf35 8b7d0c mov    edi,DWORD PTR [ebp+0xc]
0x7cbf38 51 push   ecx
0x7cbf39 8bcb mov    ecx,ebx
0x7cbf3b e810650900 call   0x862450
0x7cbf40 83c408 add    esp,0x8
0x7cbf43 0fb6f8 movzx  edi,al
0x7cbf46 85db test   ebx,ebx
0x7cbf48 7409 je     0x7cbf53
0x7cbf4a 53 push   ebx
0x7cbf4b e8ed5d0c00 call   0x891d3d
0x7cbf50 83c404 add    esp,0x4
0x7cbf53 8b16 mov    edx,DWORD PTR [esi]
0x7cbf55 8b4204 mov    eax,DWORD PTR [edx+0x4]
0x7cbf58 8bce mov    ecx,esi
0x7cbf5a ffd0 call   eax
0x7cbf5c 8bc7 mov    eax,edi
0x7cbf5e 5f pop    edi
0x7cbf5f 5e pop    esi
0x7cbf60 5b pop    ebx
0x7cbf61 59 pop    ecx
0x7cbf62 5d pop    ebp
0x7cbf63 c3 ret
0x7cbf64 cc int3
0x7cbf65 cc int3
0x7cbf66 cc int3
0x7cbf67 cc int3
0x7cbf68 cc int3
0x7cbf69 cc int3
0x7cbf6a cc int3
0x7cbf6b cc int3
0x7cbf6c cc int3
0x7cbf6d cc int3
0x7cbf6e cc int3
0x7cbf6f cc int3
0x7cbf70 55 push   ebp
0x7cbf71 8bec mov    ebp,esp
0x7cbf73 51 push   ecx
0x7cbf74 53 push   ebx
0x7cbf75 56 push   esi
0x7cbf76 57 push   edi
0x7cbf77 68e0d1be00 push   0xbed1e0
0x7cbf7c 50 push   eax
0x7cbf7d e8ee87f4ff call   0x714770
0x7cbf82 8bf0 mov    esi,eax
0x7cbf84 83c408 add    esp,0x8
0x7cbf87 85f6 test   esi,esi
0x7cbf89 7506 jne    0x7cbf91
0x7cbf8b 5f pop    edi
0x7cbf8c 5e pop    esi
0x7cbf8d 5b pop    ebx
0x7cbf8e 59 pop    ecx
0x7cbf8f 5d pop    ebp
0x7cbf90 c3 ret
0x7cbf91 8b16 mov    edx,DWORD PTR [esi]
0x7cbf93 8b422c mov    eax,DWORD PTR [edx+0x2c]
0x7cbf96 8bce mov    ecx,esi
0x7cbf98 ffd0 call   eax
0x7cbf9a 8bd8 mov    ebx,eax
0x7cbf9c 53 push   ebx
0x7cbf9d e89b1c0b00 call   0x87dc3d
0x7cbfa2 8b16 mov    edx,DWORD PTR [esi]
0x7cbfa4 83c404 add    esp,0x4
0x7cbfa7 6a00 push   0x0
0x7cbfa9 8bf8 mov    edi,eax
0x7cbfab 8b4234 mov    eax,DWORD PTR [edx+0x34]
0x7cbfae 6a00 push   0x0
0x7cbfb0 8bce mov    ecx,esi
0x7cbfb2 ffd0 call   eax
0x7cbfb4 8b16 mov    edx,DWORD PTR [esi]
0x7cbfb6 8b4210 mov    eax,DWORD PTR [edx+0x10]
0x7cbfb9 6a01 push   0x1
0x7cbfbb 53 push   ebx
0x7cbfbc 57 push   edi
0x7cbfbd 8bce mov    ecx,esi
0x7cbfbf ffd0 call   eax
0x7cbfc1 8b4d0c mov    ecx,DWORD PTR [ebp+0xc]
0x7cbfc4 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x7cbfc7 51 push   ecx
0x7cbfc8 52 push   edx
0x7cbfc9 8bc3 mov    eax,ebx
0x7cbfcb 8bcf mov    ecx,edi
0x7cbfcd e82e000000 call   0x7cc000
0x7cbfd2 83c408 add    esp,0x8
0x7cbfd5 8bd8 mov    ebx,eax
0x7cbfd7 85ff test   edi,edi
0x7cbfd9 7409 je     0x7cbfe4
0x7cbfdb 57 push   edi
0x7cbfdc e85c5d0c00 call   0x891d3d
0x7cbfe1 83c404 add    esp,0x4
0x7cbfe4 8b06 mov    eax,DWORD PTR [esi]
0x7cbfe6 8b5004 mov    edx,DWORD PTR [eax+0x4]
0x7cbfe9 8bce mov    ecx,esi
0x7cbfeb ffd2 call   edx
0x7cbfed 5f pop    edi
0x7cbfee 5e pop    esi
0x7cbfef 8bc3 mov    eax,ebx
0x7cbff1 5b pop    ebx
0x7cbff2 59 pop    ecx
0x7cbff3 5d pop    ebp
0x7cbff4 c3 ret
0x7cbff5 cc int3
0x7cbff6 cc int3
0x7cbff7 cc int3
0x7cbff8 cc int3
0x7cbff9 cc int3
0x7cbffa cc int3
0x7cbffb cc int3
0x7cbffc cc int3
0x7cbffd cc int3
0x7cbffe cc int3
0x7cbfff cc int3

; cache_state_normal_init | normal initialization sets FB79A8 based on716440 result; flag is manager+300; exceptional allocation branches beyond this window unclaimed
0x798de0 55 push   ebp
0x798de1 8bec mov    ebp,esp
0x798de3 6aff push   0xffffffff
0x798de5 68c2a69200 push   0x92a6c2
0x798dea 64a100000000 mov    eax,fs:0x0
0x798df0 50 push   eax
0x798df1 83ec48 sub    esp,0x48
0x798df4 53 push   ebx
0x798df5 56 push   esi
0x798df6 57 push   edi
0x798df7 a1201fd600 mov    eax,ds:0xd61f20
0x798dfc 33c5 xor    eax,ebp
0x798dfe 50 push   eax
0x798dff 8d45f4 lea    eax,[ebp-0xc]
0x798e02 64a300000000 mov    fs:0x0,eax
0x798e08 33db xor    ebx,ebx
0x798e0a 6a10 push   0x10
0x798e0c c745e8a876fb00 mov    DWORD PTR [ebp-0x18],0xfb76a8
0x798e13 891da876fb00 mov    DWORD PTR ds:0xfb76a8,ebx
0x798e19 e84a840f00 call   0x891268
0x798e1e d9ee fldz
0x798e20 83c404 add    esp,0x4
0x798e23 3bc3 cmp    eax,ebx
0x798e25 740f je     0x798e36
0x798e27 d910 fst    DWORD PTR [eax]
0x798e29 d95004 fst    DWORD PTR [eax+0x4]
0x798e2c d95808 fstp   DWORD PTR [eax+0x8]
0x798e2f d9e8 fld1
0x798e31 d9580c fstp   DWORD PTR [eax+0xc]
0x798e34 eb04 jmp    0x798e3a
0x798e36 ddd8 fstp   st(0)
0x798e38 33c0 xor    eax,eax
0x798e3a 6a60 push   0x60
0x798e3c a3ac76fb00 mov    ds:0xfb76ac,eax
0x798e41 e822840f00 call   0x891268
0x798e46 83c404 add    esp,0x4
0x798e49 3bc3 cmp    eax,ebx
0x798e4b 744b je     0x798e98
0x798e4d d9ee fldz
0x798e4f d910 fst    DWORD PTR [eax]
0x798e51 d95004 fst    DWORD PTR [eax+0x4]
0x798e54 d95008 fst    DWORD PTR [eax+0x8]
0x798e57 d9500c fst    DWORD PTR [eax+0xc]
0x798e5a d95010 fst    DWORD PTR [eax+0x10]
0x798e5d d95014 fst    DWORD PTR [eax+0x14]
0x798e60 d95018 fst    DWORD PTR [eax+0x18]
0x798e63 d9501c fst    DWORD PTR [eax+0x1c]
0x798e66 d95020 fst    DWORD PTR [eax+0x20]
0x798e69 d95024 fst    DWORD PTR [eax+0x24]
0x798e6c d95028 fst    DWORD PTR [eax+0x28]
0x798e6f d9502c fst    DWORD PTR [eax+0x2c]
0x798e72 d95030 fst    DWORD PTR [eax+0x30]
0x798e75 d95034 fst    DWORD PTR [eax+0x34]
0x798e78 d95038 fst    DWORD PTR [eax+0x38]
0x798e7b d9503c fst    DWORD PTR [eax+0x3c]
0x798e7e d95040 fst    DWORD PTR [eax+0x40]
0x798e81 d95044 fst    DWORD PTR [eax+0x44]
0x798e84 d95048 fst    DWORD PTR [eax+0x48]
0x798e87 d9504c fst    DWORD PTR [eax+0x4c]
0x798e8a d95050 fst    DWORD PTR [eax+0x50]
0x798e8d d95054 fst    DWORD PTR [eax+0x54]
0x798e90 d95058 fst    DWORD PTR [eax+0x58]
0x798e93 d9585c fstp   DWORD PTR [eax+0x5c]
0x798e96 eb02 jmp    0x798e9a
0x798e98 33c0 xor    eax,eax
0x798e9a 6a30 push   0x30
0x798e9c a3b076fb00 mov    ds:0xfb76b0,eax
0x798ea1 891db476fb00 mov    DWORD PTR ds:0xfb76b4,ebx
0x798ea7 891db876fb00 mov    DWORD PTR ds:0xfb76b8,ebx
0x798ead 891dbc76fb00 mov    DWORD PTR ds:0xfb76bc,ebx
0x798eb3 891dc876fb00 mov    DWORD PTR ds:0xfb76c8,ebx
0x798eb9 e8aa830f00 call   0x891268
0x798ebe 83c404 add    esp,0x4
0x798ec1 3bc3 cmp    eax,ebx
0x798ec3 0f8416060000 je     0x7994df
0x798ec9 a3c476fb00 mov    ds:0xfb76c4,eax
0x798ece 8900 mov    DWORD PTR [eax],eax
0x798ed0 a1c476fb00 mov    eax,ds:0xfb76c4
0x798ed5 894004 mov    DWORD PTR [eax+0x4],eax
0x798ed8 a1c476fb00 mov    eax,ds:0xfb76c4
0x798edd 894008 mov    DWORD PTR [eax+0x8],eax
0x798ee0 a1c476fb00 mov    eax,ds:0xfb76c4
0x798ee5 c6402c01 mov    BYTE PTR [eax+0x2c],0x1
0x798ee9 8b0dc476fb00 mov    ecx,DWORD PTR ds:0xfb76c4
0x798eef c6412d01 mov    BYTE PTR [ecx+0x2d],0x1
0x798ef3 895dfc mov    DWORD PTR [ebp-0x4],ebx
0x798ef6 6a0c push   0xc
0x798ef8 891dd476fb00 mov    DWORD PTR ds:0xfb76d4,ebx
0x798efe e865830f00 call   0x891268
0x798f03 83c404 add    esp,0x4
0x798f06 3bc3 cmp    eax,ebx
0x798f08 0f84ad050000 je     0x7994bb
0x798f0e a3d076fb00 mov    ds:0xfb76d0,eax
0x798f13 8900 mov    DWORD PTR [eax],eax
0x798f15 a1d076fb00 mov    eax,ds:0xfb76d0
0x798f1a 894004 mov    DWORD PTR [eax+0x4],eax
0x798f1d c645fc01 mov    BYTE PTR [ebp-0x4],0x1
0x798f21 bf01000000 mov    edi,0x1
0x798f26 6858c00200 push   0x2c058
0x798f2b 891ddc76fb00 mov    DWORD PTR ds:0xfb76dc,ebx
0x798f31 891de076fb00 mov    DWORD PTR ds:0xfb76e0,ebx
0x798f37 893de476fb00 mov    DWORD PTR ds:0xfb76e4,edi
0x798f3d 891de876fb00 mov    DWORD PTR ds:0xfb76e8,ebx
0x798f43 891d3477fb00 mov    DWORD PTR ds:0xfb7734,ebx
0x798f49 891d3877fb00 mov    DWORD PTR ds:0xfb7738,ebx
0x798f4f e814830f00 call   0x891268
0x798f54 83c404 add    esp,0x4
0x798f57 3bc3 cmp    eax,ebx
0x798f59 7419 je     0x798f74
0x798f5b ba15000000 mov    edx,0x15
0x798f60 8d8800200000 lea    ecx,[eax+0x2000]
0x798f66 8919 mov    DWORD PTR [ecx],ebx
0x798f68 81c104200000 add    ecx,0x2004
0x798f6e 2bd7 sub    edx,edi
0x798f70 79f4 jns    0x798f66
0x798f72 eb02 jmp    0x798f76
0x798f74 33c0 xor    eax,eax
0x798f76 6a10 push   0x10
0x798f78 a34077fb00 mov    ds:0xfb7740,eax
0x798f7d e8e6820f00 call   0x891268
0x798f82 83c404 add    esp,0x4
0x798f85 3bc3 cmp    eax,ebx
0x798f87 740a je     0x798f93
0x798f89 8918 mov    DWORD PTR [eax],ebx
0x798f8b 895804 mov    DWORD PTR [eax+0x4],ebx
0x798f8e 895808 mov    DWORD PTR [eax+0x8],ebx
0x798f91 eb02 jmp    0x798f95
0x798f93 33c0 xor    eax,eax
0x798f95 6a14 push   0x14
0x798f97 a34477fb00 mov    ds:0xfb7744,eax
0x798f9c 891d4877fb00 mov    DWORD PTR ds:0xfb7748,ebx
0x798fa2 891d4c77fb00 mov    DWORD PTR ds:0xfb774c,ebx
0x798fa8 891d5077fb00 mov    DWORD PTR ds:0xfb7750,ebx
0x798fae 891d5c77fb00 mov    DWORD PTR ds:0xfb775c,ebx
0x798fb4 e8af820f00 call   0x891268
0x798fb9 83c404 add    esp,0x4
0x798fbc 3bc3 cmp    eax,ebx
0x798fbe 0f84d3040000 je     0x799497
0x798fc4 a35877fb00 mov    ds:0xfb7758,eax
0x798fc9 8900 mov    DWORD PTR [eax],eax
0x798fcb a15877fb00 mov    eax,ds:0xfb7758
0x798fd0 894004 mov    DWORD PTR [eax+0x4],eax
0x798fd3 a15877fb00 mov    eax,ds:0xfb7758
0x798fd8 894008 mov    DWORD PTR [eax+0x8],eax
0x798fdb 8b155877fb00 mov    edx,DWORD PTR ds:0xfb7758
0x798fe1 c6421001 mov    BYTE PTR [edx+0x10],0x1
0x798fe5 a15877fb00 mov    eax,ds:0xfb7758
0x798fea c6401101 mov    BYTE PTR [eax+0x11],0x1
0x798fee c645fc02 mov    BYTE PTR [ebp-0x4],0x2
0x798ff2 6a14 push   0x14
0x798ff4 891d6c77fb00 mov    DWORD PTR ds:0xfb776c,ebx
0x798ffa e869820f00 call   0x891268
0x798fff 83c404 add    esp,0x4
0x799002 3bc3 cmp    eax,ebx
0x799004 0f8469040000 je     0x799473
0x79900a a36877fb00 mov    ds:0xfb7768,eax
0x79900f 8900 mov    DWORD PTR [eax],eax
0x799011 a16877fb00 mov    eax,ds:0xfb7768
0x799016 894004 mov    DWORD PTR [eax+0x4],eax
0x799019 a16877fb00 mov    eax,ds:0xfb7768
0x79901e 894008 mov    DWORD PTR [eax+0x8],eax
0x799021 8b0d6877fb00 mov    ecx,DWORD PTR ds:0xfb7768
0x799027 c6411001 mov    BYTE PTR [ecx+0x10],0x1
0x79902b 8b156877fb00 mov    edx,DWORD PTR ds:0xfb7768
0x799031 c6421101 mov    BYTE PTR [edx+0x11],0x1
0x799035 6890824100 push   0x418290
0x79903a 6830936800 push   0x689330
0x79903f 6a20 push   0x20
0x799041 6a10 push   0x10
0x799043 687477fb00 push   0xfb7774
0x799048 c645fc03 mov    BYTE PTR [ebp-0x4],0x3
0x79904c e8b28f0f00 call   0x892003
0x799051 891d7479fb00 mov    DWORD PTR ds:0xfb7974,ebx
0x799057 891d7879fb00 mov    DWORD PTR ds:0xfb7978,ebx
0x79905d 891d7c79fb00 mov    DWORD PTR ds:0xfb797c,ebx
0x799063 d9ee fldz
0x799065 d9159479fb00 fst    DWORD PTR ds:0xfb7994
0x79906b 891d8479fb00 mov    DWORD PTR ds:0xfb7984,ebx
0x799071 d9159879fb00 fst    DWORD PTR ds:0xfb7998
0x799077 891d8879fb00 mov    DWORD PTR ds:0xfb7988,ebx
0x79907d d9159c79fb00 fst    DWORD PTR ds:0xfb799c
0x799083 893d8c79fb00 mov    DWORD PTR ds:0xfb798c,edi
0x799089 d91da079fb00 fstp   DWORD PTR ds:0xfb79a0
0x79908f 891d9079fb00 mov    DWORD PTR ds:0xfb7990,ebx
0x799095 c705a479fb00cb7080ff mov    DWORD PTR ds:0xfb79a4,0xff8070cb
0x79909f 891da879fb00 mov    DWORD PTR ds:0xfb79a8,ebx
0x7990a5 66891dac79fb00 mov    WORD PTR ds:0xfb79ac,bx
0x7990ac 891db079fb00 mov    DWORD PTR ds:0xfb79b0,ebx
0x7990b2 891db479fb00 mov    DWORD PTR ds:0xfb79b4,ebx
0x7990b8 891db879fb00 mov    DWORD PTR ds:0xfb79b8,ebx
0x7990be 891dc079fb00 mov    DWORD PTR ds:0xfb79c0,ebx
0x7990c4 891dc479fb00 mov    DWORD PTR ds:0xfb79c4,ebx
0x7990ca 891dc879fb00 mov    DWORD PTR ds:0xfb79c8,ebx
0x7990d0 891dd079fb00 mov    DWORD PTR ds:0xfb79d0,ebx
0x7990d6 891dd479fb00 mov    DWORD PTR ds:0xfb79d4,ebx
0x7990dc 891dd879fb00 mov    DWORD PTR ds:0xfb79d8,ebx
0x7990e2 891de079fb00 mov    DWORD PTR ds:0xfb79e0,ebx
0x7990e8 c645fc06 mov    BYTE PTR [ebp-0x4],0x6
0x7990ec 8b35ec22bd00 mov    esi,DWORD PTR ds:0xbd22ec
0x7990f2 68ec76fb00 push   0xfb76ec
0x7990f7 ffd6 call   esi
0x7990f9 680477fb00 push   0xfb7704
0x7990fe ffd6 call   esi
0x799100 681c77fb00 push   0xfb771c
0x799105 ffd6 call   esi
0x799107 8d45ac lea    eax,[ebp-0x54]
0x79910a 50 push   eax
0x79910b 895dac mov    DWORD PTR [ebp-0x54],ebx
0x79910e 895db0 mov    DWORD PTR [ebp-0x50],ebx
0x799111 895db4 mov    DWORD PTR [ebp-0x4c],ebx
0x799114 895db8 mov    DWORD PTR [ebp-0x48],ebx
0x799117 895dbc mov    DWORD PTR [ebp-0x44],ebx
0x79911a 895dc0 mov    DWORD PTR [ebp-0x40],ebx
0x79911d 895dc4 mov    DWORD PTR [ebp-0x3c],ebx
0x799120 895dc8 mov    DWORD PTR [ebp-0x38],ebx
0x799123 895dcc mov    DWORD PTR [ebp-0x34],ebx
0x799126 ff151821bd00 call   DWORD PTR ds:0xbd2118
0x79912c b804000000 mov    eax,0x4
0x799131 68ac79fb00 push   0xfb79ac
0x799136 3945c0 cmp    DWORD PTR [ebp-0x40],eax
0x799139 7202 jb     0x79913d
0x79913b b008 mov    al,0x8
0x79913d e83e52f5ff call   0x6ee380
0x799142 f605f81dfe0001 test   BYTE PTR ds:0xfe1df8,0x1
0x799149 7520 jne    0x79916b
0x79914b 093df81dfe00 or     DWORD PTR ds:0xfe1df8,edi
0x799151 c645fc07 mov    BYTE PTR [ebp-0x4],0x7
0x799155 e886daf7ff call   0x716be0
0x79915a 68a0f1bc00 push   0xbcf1a0
0x79915f e8b6910f00 call   0x89231a
0x799164 83c404 add    esp,0x4
0x799167 c645fc06 mov    BYTE PTR [ebp-0x4],0x6
0x79916b 68fc1dfe00 push   0xfe1dfc
0x799170 e8cbd2f7ff call   0x716440
0x799175 85c0 test   eax,eax
0x799177 0f85d9020000 jne    0x799456
0x79917d f605f81dfe0001 test   BYTE PTR ds:0xfe1df8,0x1
0x799184 891da879fb00 mov    DWORD PTR ds:0xfb79a8,ebx
0x79918a 7520 jne    0x7991ac
0x79918c 093df81dfe00 or     DWORD PTR ds:0xfe1df8,edi
0x799192 c645fc08 mov    BYTE PTR [ebp-0x4],0x8
0x799196 e845daf7ff call   0x716be0
0x79919b 68a0f1bc00 push   0xbcf1a0
0x7991a0 e875910f00 call   0x89231a
0x7991a5 83c404 add    esp,0x4
0x7991a8 c645fc06 mov    BYTE PTR [ebp-0x4],0x6
0x7991ac 57 push   edi
0x7991ad 6870f2c400 push   0xc4f270
0x7991b2 6870f5c000 push   0xc0f570
0x7991b7 b964f2c400 mov    ecx,0xc4f264
0x7991bc bafc1dfe00 mov    edx,0xfe1dfc
0x7991c1 e87acef7ff call   0x716040
0x7991c6 f605f81dfe0001 test   BYTE PTR ds:0xfe1df8,0x1
0x7991cd 7520 jne    0x7991ef
0x7991cf 093df81dfe00 or     DWORD PTR ds:0xfe1df8,edi
0x7991d5 c645fc09 mov    BYTE PTR [ebp-0x4],0x9
0x7991d9 e802daf7ff call   0x716be0
0x7991de 68a0f1bc00 push   0xbcf1a0
0x7991e3 e832910f00 call   0x89231a
0x7991e8 83c404 add    esp,0x4
0x7991eb c645fc06 mov    BYTE PTR [ebp-0x4],0x6
0x7991ef 57 push   edi
0x7991f0 6884f2c400 push   0xc4f284
0x7991f5 688cf2c400 push   0xc4f28c
0x7991fa b978f2c400 mov    ecx,0xc4f278
0x7991ff bafc1dfe00 mov    edx,0xfe1dfc
0x799204 e837cef7ff call   0x716040
0x799209 f605f81dfe0001 test   BYTE PTR ds:0xfe1df8,0x1
0x799210 7520 jne    0x799232
0x799212 093df81dfe00 or     DWORD PTR ds:0xfe1df8,edi
0x799218 c645fc0a mov    BYTE PTR [ebp-0x4],0xa
0x79921c e8bfd9f7ff call   0x716be0
0x799221 68a0f1bc00 push   0xbcf1a0
0x799226 e8ef900f00 call   0x89231a
0x79922b 83c404 add    esp,0x4
0x79922e c645fc06 mov    BYTE PTR [ebp-0x4],0x6
0x799232 57 push   edi
0x799233 6894f2c400 push   0xc4f294
0x799238 689cf2c400 push   0xc4f29c
0x79923d b9c8cec000 mov    ecx,0xc0cec8
0x799242 bafc1dfe00 mov    edx,0xfe1dfc
0x799247 e8f4cdf7ff call   0x716040
0x79924c f605f81dfe0001 test   BYTE PTR ds:0xfe1df8,0x1
0x799253 7520 jne    0x799275
0x799255 093df81dfe00 or     DWORD PTR ds:0xfe1df8,edi
0x79925b c645fc0b mov    BYTE PTR [ebp-0x4],0xb
0x79925f e87cd9f7ff call   0x716be0
0x799264 68a0f1bc00 push   0xbcf1a0
0x799269 e8ac900f00 call   0x89231a
0x79926e 83c404 add    esp,0x4
0x799271 c645fc06 mov    BYTE PTR [ebp-0x4],0x6
0x799275 57 push   edi
0x799276 68a4f2c400 push   0xc4f2a4
0x79927b 68acf2c400 push   0xc4f2ac
0x799280 b978f2c400 mov    ecx,0xc4f278
0x799285 bafc1dfe00 mov    edx,0xfe1dfc
0x79928a e8b1cdf7ff call   0x716040
0x79928f f605f81dfe0001 test   BYTE PTR ds:0xfe1df8,0x1
0x799296 7520 jne    0x7992b8
0x799298 093df81dfe00 or     DWORD PTR ds:0xfe1df8,edi
0x79929e c645fc0c mov    BYTE PTR [ebp-0x4],0xc
0x7992a2 e839d9f7ff call   0x716be0
0x7992a7 68a0f1bc00 push   0xbcf1a0
0x7992ac e869900f00 call   0x89231a
0x7992b1 83c404 add    esp,0x4
0x7992b4 c645fc06 mov    BYTE PTR [ebp-0x4],0x6
0x7992b8 57 push   edi
0x7992b9 68b4f2c400 push   0xc4f2b4
0x7992be 68bcf2c400 push   0xc4f2bc
0x7992c3 b978f2c400 mov    ecx,0xc4f278
0x7992c8 bafc1dfe00 mov    edx,0xfe1dfc
0x7992cd e86ecdf7ff call   0x716040
0x7992d2 f605f81dfe0001 test   BYTE PTR ds:0xfe1df8,0x1
0x7992d9 7520 jne    0x7992fb
0x7992db 093df81dfe00 or     DWORD PTR ds:0xfe1df8,edi
0x7992e1 c645fc0d mov    BYTE PTR [ebp-0x4],0xd
0x7992e5 e8f6d8f7ff call   0x716be0
0x7992ea 68a0f1bc00 push   0xbcf1a0
0x7992ef e826900f00 call   0x89231a
0x7992f4 83c404 add    esp,0x4
0x7992f7 c645fc06 mov    BYTE PTR [ebp-0x4],0x6
0x7992fb 57 push   edi
0x7992fc 68d0f2c400 push   0xc4f2d0
0x799301 68d8f2c400 push   0xc4f2d8
0x799306 b9c4f2c400 mov    ecx,0xc4f2c4
0x79930b bafc1dfe00 mov    edx,0xfe1dfc
0x799310 e82bcdf7ff call   0x716040
0x799315 f605f81dfe0001 test   BYTE PTR ds:0xfe1df8,0x1
0x79931c 7520 jne    0x79933e
0x79931e 093df81dfe00 or     DWORD PTR ds:0xfe1df8,edi
0x799324 c645fc0e mov    BYTE PTR [ebp-0x4],0xe
0x799328 e8b3d8f7ff call   0x716be0
0x79932d 68a0f1bc00 push   0xbcf1a0
0x799332 e8e38f0f00 call   0x89231a
0x799337 83c404 add    esp,0x4
0x79933a c645fc06 mov    BYTE PTR [ebp-0x4],0x6
0x79933e 57 push   edi
0x79933f 68e0f2c400 push   0xc4f2e0
0x799344 68e8f2c400 push   0xc4f2e8
0x799349 b9c4f2c400 mov    ecx,0xc4f2c4
0x79934e bafc1dfe00 mov    edx,0xfe1dfc
0x799353 e8e8ccf7ff call   0x716040
0x799358 f605f81dfe0001 test   BYTE PTR ds:0xfe1df8,0x1
0x79935f 7520 jne    0x799381
0x799361 093df81dfe00 or     DWORD PTR ds:0xfe1df8,edi
0x799367 c645fc0f mov    BYTE PTR [ebp-0x4],0xf
0x79936b e870d8f7ff call   0x716be0
0x799370 68a0f1bc00 push   0xbcf1a0
0x799375 e8a08f0f00 call   0x89231a
0x79937a 83c404 add    esp,0x4
0x79937d c645fc06 mov    BYTE PTR [ebp-0x4],0x6
0x799381 57 push   edi
0x799382 68f0f2c400 push   0xc4f2f0
0x799387 68f8f2c400 push   0xc4f2f8
0x79938c b948f5c000 mov    ecx,0xc0f548
0x799391 bafc1dfe00 mov    edx,0xfe1dfc
0x799396 e8a5ccf7ff call   0x716040
0x79939b f605f81dfe0001 test   BYTE PTR ds:0xfe1df8,0x1
0x7993a2 7520 jne    0x7993c4
0x7993a4 093df81dfe00 or     DWORD PTR ds:0xfe1df8,edi
0x7993aa c645fc10 mov    BYTE PTR [ebp-0x4],0x10
0x7993ae e82dd8f7ff call   0x716be0
0x7993b3 68a0f1bc00 push   0xbcf1a0
0x7993b8 e85d8f0f00 call   0x89231a
0x7993bd 83c404 add    esp,0x4
0x7993c0 c645fc06 mov    BYTE PTR [ebp-0x4],0x6
0x7993c4 57 push   edi
0x7993c5 68b4f2c400 push   0xc4f2b4
0x7993ca 6810f3c400 push   0xc4f310
0x7993cf b900f3c400 mov    ecx,0xc4f300
0x7993d4 bafc1dfe00 mov    edx,0xfe1dfc
0x7993d9 e862ccf7ff call   0x716040
0x7993de f605f81dfe0001 test   BYTE PTR ds:0xfe1df8,0x1
0x7993e5 7520 jne    0x799407
0x7993e7 093df81dfe00 or     DWORD PTR ds:0xfe1df8,edi
0x7993ed c645fc11 mov    BYTE PTR [ebp-0x4],0x11
0x7993f1 e8ead7f7ff call   0x716be0
0x7993f6 68a0f1bc00 push   0xbcf1a0
0x7993fb e81a8f0f00 call   0x89231a
0x799400 83c404 add    esp,0x4
0x799403 c645fc06 mov    BYTE PTR [ebp-0x4],0x6
0x799407 57 push   edi
0x799408 68b4f2c400 push   0xc4f2b4
0x79940d 6820f3c400 push   0xc4f320
0x799412 b918f3c400 mov    ecx,0xc4f318
0x799417 bafc1dfe00 mov    edx,0xfe1dfc
0x79941c e81fccf7ff call   0x716040
0x799421 f605f81dfe0001 test   BYTE PTR ds:0xfe1df8,0x1
0x799428 7520 jne    0x79944a
0x79942a 093df81dfe00 or     DWORD PTR ds:0xfe1df8,edi
0x799430 c645fc12 mov    BYTE PTR [ebp-0x4],0x12
0x799434 e8a7d7f7ff call   0x716be0
0x799439 68a0f1bc00 push   0xbcf1a0
0x79943e e8d78e0f00 call   0x89231a
0x799443 83c404 add    esp,0x4
0x799446 c645fc06 mov    BYTE PTR [ebp-0x4],0x6
0x79944a 68fc1dfe00 push   0xfe1dfc
0x79944f e8eccdf7ff call   0x716240
0x799454 eb06 jmp    0x79945c
0x799456 893da879fb00 mov    DWORD PTR ds:0xfb79a8,edi
0x79945c b8a876fb00 mov    eax,0xfb76a8
0x799461 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x799464 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x79946b 59 pop    ecx
0x79946c 5f pop    edi
0x79946d 5e pop    esi
0x79946e 5b pop    ebx
0x79946f 8be5 mov    esp,ebp
0x799471 5d pop    ebp
0x799472 c3 ret

; cache_file_reader | fcs.flu open; native cache reader populates groups and entries; normal return differs from absence
0x716440 55 push   ebp
0x716441 8bec mov    ebp,esp
0x716443 83e4f8 and    esp,0xfffffff8
0x716446 6aff push   0xffffffff
0x716448 68587e9100 push   0x917e58
0x71644d 64a100000000 mov    eax,fs:0x0
0x716453 50 push   eax
0x716454 83ec48 sub    esp,0x48
0x716457 a1201fd600 mov    eax,ds:0xd61f20
0x71645c 33c4 xor    eax,esp
0x71645e 89442440 mov    DWORD PTR [esp+0x40],eax
0x716462 53 push   ebx
0x716463 56 push   esi
0x716464 57 push   edi
0x716465 a1201fd600 mov    eax,ds:0xd61f20
0x71646a 33c4 xor    eax,esp
0x71646c 50 push   eax
0x71646d 8d442458 lea    eax,[esp+0x58]
0x716471 64a300000000 mov    fs:0x0,eax
0x716477 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x71647a 68e0d1be00 push   0xbed1e0
0x71647f 685cf2c400 push   0xc4f25c
0x716484 895c2430 mov    DWORD PTR [esp+0x30],ebx
0x716488 e8eeb31700 call   0x89187b
0x71648d 33c9 xor    ecx,ecx
0x71648f 83c408 add    esp,0x8
0x716492 89442420 mov    DWORD PTR [esp+0x20],eax
0x716496 3bc1 cmp    eax,ecx
0x716498 7507 jne    0x7164a1
0x71649a 33c0 xor    eax,eax
0x71649c e970020000 jmp    0x716711
0x7164a1 50 push   eax
0x7164a2 6a01 push   0x1
0x7164a4 8d442418 lea    eax,[esp+0x18]
0x7164a8 6a08 push   0x8
0x7164aa 50 push   eax
0x7164ab 894c2420 mov    DWORD PTR [esp+0x20],ecx
0x7164af 894c2424 mov    DWORD PTR [esp+0x24],ecx
0x7164b3 e887b71700 call   0x891c3f
0x7164b8 8b442420 mov    eax,DWORD PTR [esp+0x20]
0x7164bc 33c9 xor    ecx,ecx
0x7164be 8bf8 mov    edi,eax
0x7164c0 ba58010000 mov    edx,0x158
0x7164c5 f7e2 mul    edx
0x7164c7 0f90c1 seto   cl
0x7164ca f7d9 neg    ecx
0x7164cc 0bc8 or     ecx,eax
0x7164ce 51 push   ecx
0x7164cf e869771600 call   0x87dc3d
0x7164d4 8bf0 mov    esi,eax
0x7164d6 83c414 add    esp,0x14
0x7164d9 85f6 test   esi,esi
0x7164db 741c je     0x7164f9
0x7164dd 4f dec    edi
0x7164de 7813 js     0x7164f3
0x7164e0 47 inc    edi
0x7164e1 69ff58010000 imul   edi,edi,0x158
0x7164e7 57 push   edi
0x7164e8 6a00 push   0x0
0x7164ea 56 push   esi
0x7164eb e870831800 call   0x89e860
0x7164f0 83c40c add    esp,0xc
0x7164f3 8974241c mov    DWORD PTR [esp+0x1c],esi
0x7164f7 eb08 jmp    0x716501
0x7164f9 c744241c00000000 mov    DWORD PTR [esp+0x1c],0x0
0x716501 8b442414 mov    eax,DWORD PTR [esp+0x14]
0x716505 33c9 xor    ecx,ecx
0x716507 8bf8 mov    edi,eax
0x716509 ba18020000 mov    edx,0x218
0x71650e f7e2 mul    edx
0x716510 0f90c1 seto   cl
0x716513 f7d9 neg    ecx
0x716515 0bc8 or     ecx,eax
0x716517 51 push   ecx
0x716518 e820771600 call   0x87dc3d
0x71651d 8bf0 mov    esi,eax
0x71651f 83c404 add    esp,0x4
0x716522 85f6 test   esi,esi
0x716524 7420 je     0x716546
0x716526 8d47ff lea    eax,[edi-0x1]
0x716529 85c0 test   eax,eax
0x71652b 7813 js     0x716540
0x71652d 40 inc    eax
0x71652e 69c018020000 imul   eax,eax,0x218
0x716534 50 push   eax
0x716535 6a00 push   0x0
0x716537 56 push   esi
0x716538 e823831800 call   0x89e860
0x71653d 83c40c add    esp,0xc
0x716540 89742418 mov    DWORD PTR [esp+0x18],esi
0x716544 eb08 jmp    0x71654e
0x716546 c744241800000000 mov    DWORD PTR [esp+0x18],0x0
0x71654e 8b7c2420 mov    edi,DWORD PTR [esp+0x20]
0x716552 8b442410 mov    eax,DWORD PTR [esp+0x10]
0x716556 8b74241c mov    esi,DWORD PTR [esp+0x1c]
0x71655a 57 push   edi
0x71655b 50 push   eax
0x71655c 6858010000 push   0x158
0x716561 56 push   esi
0x716562 e8d8b61700 call   0x891c3f
0x716567 8b4c2424 mov    ecx,DWORD PTR [esp+0x24]
0x71656b 8b542428 mov    edx,DWORD PTR [esp+0x28]
0x71656f 57 push   edi
0x716570 51 push   ecx
0x716571 6818020000 push   0x218
0x716576 52 push   edx
0x716577 e8c3b61700 call   0x891c3f
0x71657c 33ff xor    edi,edi
0x71657e 83c420 add    esp,0x20
0x716581 397c2410 cmp    DWORD PTR [esp+0x10],edi
0x716585 7e2e jle    0x7165b5
0x716587 83c650 add    esi,0x50
0x71658a 8d9b00000000 lea    ebx,[ebx+0x0]
0x716590 8b8604010000 mov    eax,DWORD PTR [esi+0x104]
0x716596 50 push   eax
0x716597 8d4ec0 lea    ecx,[esi-0x40]
0x71659a 51 push   ecx
0x71659b 8d56b0 lea    edx,[esi-0x50]
0x71659e 52 push   edx
0x71659f 8bce mov    ecx,esi
0x7165a1 8bd3 mov    edx,ebx
0x7165a3 e898faffff call   0x716040
0x7165a8 47 inc    edi
0x7165a9 81c658010000 add    esi,0x158
0x7165af 3b7c2410 cmp    edi,DWORD PTR [esp+0x10]
0x7165b3 7cdb jl     0x716590
0x7165b5 837c241400 cmp    DWORD PTR [esp+0x14],0x0
0x7165ba c744242400000000 mov    DWORD PTR [esp+0x24],0x0
0x7165c2 0f8e1d010000 jle    0x7166e5
0x7165c8 8b7c2418 mov    edi,DWORD PTR [esp+0x18]
0x7165cc 8bc7 mov    eax,edi
0x7165ce c74424480f000000 mov    DWORD PTR [esp+0x48],0xf
0x7165d6 c744244400000000 mov    DWORD PTR [esp+0x44],0x0
0x7165de c644243400 mov    BYTE PTR [esp+0x34],0x0
0x7165e3 8d5001 lea    edx,[eax+0x1]
0x7165e6 8a08 mov    cl,BYTE PTR [eax]
0x7165e8 40 inc    eax
0x7165e9 84c9 test   cl,cl
0x7165eb 75f9 jne    0x7165e6
0x7165ed 2bc2 sub    eax,edx
0x7165ef 50 push   eax
0x7165f0 57 push   edi
0x7165f1 8d4c243c lea    ecx,[esp+0x3c]
0x7165f5 e876c4ceff call   0x402a70
0x7165fa 8d442434 lea    eax,[esp+0x34]
0x7165fe 50 push   eax
0x7165ff 8bc3 mov    eax,ebx
0x716601 c744246400000000 mov    DWORD PTR [esp+0x64],0x0
0x716609 e822090a00 call   0x7b6f30
0x71660e 89442430 mov    DWORD PTR [esp+0x30],eax
0x716612 3b4304 cmp    eax,DWORD PTR [ebx+0x4]
0x716615 7462 je     0x716679
0x716617 8b581c mov    ebx,DWORD PTR [eax+0x1c]
0x71661a 83c00c add    eax,0xc
0x71661d b910000000 mov    ecx,0x10
0x716622 394814 cmp    DWORD PTR [eax+0x14],ecx
0x716625 7202 jb     0x716629
0x716627 8b00 mov    eax,DWORD PTR [eax]
0x716629 8b742444 mov    esi,DWORD PTR [esp+0x44]
0x71662d 3bf3 cmp    esi,ebx
0x71662f 7202 jb     0x716633
0x716631 8bf3 mov    esi,ebx
0x716633 8b542434 mov    edx,DWORD PTR [esp+0x34]
0x716637 394c2448 cmp    DWORD PTR [esp+0x48],ecx
0x71663b 7304 jae    0x716641
0x71663d 8d542434 lea    edx,[esp+0x34]
0x716641 56 push   esi
0x716642 8bc8 mov    ecx,eax
0x716644 e82718cfff call   0x407e70
0x716649 83c404 add    esp,0x4
0x71664c 85c0 test   eax,eax
0x71664e 7518 jne    0x716668
0x716650 8b442444 mov    eax,DWORD PTR [esp+0x44]
0x716654 3bc3 cmp    eax,ebx
0x716656 7305 jae    0x71665d
0x716658 83c8ff or     eax,0xffffffff
0x71665b eb09 jmp    0x716666
0x71665d 33c9 xor    ecx,ecx
0x71665f 3bc3 cmp    eax,ebx
0x716661 0f95c1 setne  cl
0x716664 8bc1 mov    eax,ecx
0x716666 85c0 test   eax,eax
0x716668 8b5c2428 mov    ebx,DWORD PTR [esp+0x28]
0x71666c 0f98c0 sets   al
0x71666f 84c0 test   al,al
0x716671 7506 jne    0x716679
0x716673 8d442430 lea    eax,[esp+0x30]
0x716677 eb0b jmp    0x716684
0x716679 8b4304 mov    eax,DWORD PTR [ebx+0x4]
0x71667c 8944242c mov    DWORD PTR [esp+0x2c],eax
0x716680 8d44242c lea    eax,[esp+0x2c]
0x716684 8b30 mov    esi,DWORD PTR [eax]
0x716686 c7442460ffffffff mov    DWORD PTR [esp+0x60],0xffffffff
0x71668e 837c244810 cmp    DWORD PTR [esp+0x48],0x10
0x716693 720d jb     0x7166a2
0x716695 8b542434 mov    edx,DWORD PTR [esp+0x34]
0x716699 52 push   edx
0x71669a e86dab1700 call   0x89120c
0x71669f 83c404 add    esp,0x4
0x7166a2 c74424480f000000 mov    DWORD PTR [esp+0x48],0xf
0x7166aa c744244400000000 mov    DWORD PTR [esp+0x44],0x0
0x7166b2 c644243400 mov    BYTE PTR [esp+0x34],0x0
0x7166b7 8b4628 mov    eax,DWORD PTR [esi+0x28]
0x7166ba 8d4f10 lea    ecx,[edi+0x10]
0x7166bd 83c03c add    eax,0x3c
0x7166c0 8d9104010000 lea    edx,[ecx+0x104]
0x7166c6 50 push   eax
0x7166c7 e824320000 call   0x7198f0
0x7166cc 8b442424 mov    eax,DWORD PTR [esp+0x24]
0x7166d0 40 inc    eax
0x7166d1 81c718020000 add    edi,0x218
0x7166d7 89442424 mov    DWORD PTR [esp+0x24],eax
0x7166db 3b442414 cmp    eax,DWORD PTR [esp+0x14]
0x7166df 0f8ce7feffff jl     0x7165cc
0x7166e5 8b4c241c mov    ecx,DWORD PTR [esp+0x1c]
0x7166e9 51 push   ecx
0x7166ea e84eb61700 call   0x891d3d
0x7166ef 8b54241c mov    edx,DWORD PTR [esp+0x1c]
0x7166f3 83c404 add    esp,0x4
0x7166f6 52 push   edx
0x7166f7 e841b61700 call   0x891d3d
0x7166fc 8b442424 mov    eax,DWORD PTR [esp+0x24]
0x716700 83c404 add    esp,0x4
0x716703 50 push   eax
0x716704 e8c0b51700 call   0x891cc9
0x716709 83c404 add    esp,0x4
0x71670c b801000000 mov    eax,0x1
0x716711 8b4c2458 mov    ecx,DWORD PTR [esp+0x58]
0x716715 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x71671c 59 pop    ecx
0x71671d 5f pop    edi
0x71671e 5e pop    esi
0x71671f 5b pop    ebx
0x716720 8b4c2440 mov    ecx,DWORD PTR [esp+0x40]
0x716724 33cc xor    ecx,esp
0x716726 e8d6a81700 call   0x891001
0x71672b 8be5 mov    esp,ebp
0x71672d 5d pop    ebp
0x71672e c20400 ret    0x4

; image_texture_object_construct | image ctor supplies typed vtables; initial call via secondary interface+4 is73ABE0
0x736b00 55 push   ebp
0x736b01 8bec mov    ebp,esp
0x736b03 83e4f8 and    esp,0xfffffff8
0x736b06 6aff push   0xffffffff
0x736b08 6873f19000 push   0x90f173
0x736b0d 64a100000000 mov    eax,fs:0x0
0x736b13 50 push   eax
0x736b14 83ec30 sub    esp,0x30
0x736b17 a1201fd600 mov    eax,ds:0xd61f20
0x736b1c 33c4 xor    eax,esp
0x736b1e 89442428 mov    DWORD PTR [esp+0x28],eax
0x736b22 53 push   ebx
0x736b23 56 push   esi
0x736b24 57 push   edi
0x736b25 a1201fd600 mov    eax,ds:0xd61f20
0x736b2a 33c4 xor    eax,esp
0x736b2c 50 push   eax
0x736b2d 8d442440 lea    eax,[esp+0x40]
0x736b31 64a300000000 mov    fs:0x0,eax
0x736b37 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x736b3a 8d442410 lea    eax,[esp+0x10]
0x736b3e 8bf9 mov    edi,ecx
0x736b40 50 push   eax
0x736b41 8d7708 lea    esi,[edi+0x8]
0x736b44 8bc3 mov    eax,ebx
0x736b46 e8f5030000 call   0x736f40
0x736b4b 8b7f0c mov    edi,DWORD PTR [edi+0xc]
0x736b4e 397c2410 cmp    DWORD PTR [esp+0x10],edi
0x736b52 0f85ea000000 jne    0x736c42
0x736b58 6a4c push   0x4c
0x736b5a e809a71500 call   0x891268
0x736b5f 8bf8 mov    edi,eax
0x736b61 83c404 add    esp,0x4
0x736b64 897c2410 mov    DWORD PTR [esp+0x10],edi
0x736b68 c744244800000000 mov    DWORD PTR [esp+0x48],0x0
0x736b70 85ff test   edi,edi
0x736b72 7426 je     0x736b9a
0x736b74 57 push   edi
0x736b75 8bd3 mov    edx,ebx
0x736b77 e814450000 call   0x73b090
0x736b7c 33c0 xor    eax,eax
0x736b7e c707f457c400 mov    DWORD PTR [edi],0xc457f4
0x736b84 c747043c58c400 mov    DWORD PTR [edi+0x4],0xc4583c
0x736b8b c747084c58c400 mov    DWORD PTR [edi+0x8],0xc4584c
0x736b92 894744 mov    DWORD PTR [edi+0x44],eax
0x736b95 894748 mov    DWORD PTR [edi+0x48],eax
0x736b98 eb02 jmp    0x736b9c
0x736b9a 33ff xor    edi,edi
0x736b9c c7442448ffffffff mov    DWORD PTR [esp+0x48],0xffffffff
0x736ba4 8b5704 mov    edx,DWORD PTR [edi+0x4]
0x736ba7 8b4204 mov    eax,DWORD PTR [edx+0x4]
0x736baa 8d4f04 lea    ecx,[edi+0x4]
0x736bad ffd0 call   eax
0x736baf 8b5708 mov    edx,DWORD PTR [edi+0x8]
0x736bb2 8b4204 mov    eax,DWORD PTR [edx+0x4]
0x736bb5 8d4f08 lea    ecx,[edi+0x8]
0x736bb8 ffd0 call   eax
0x736bba 33c9 xor    ecx,ecx
0x736bbc 6aff push   0xffffffff
0x736bbe 51 push   ecx
0x736bbf 66894c2420 mov    WORD PTR [esp+0x20],cx
0x736bc4 53 push   ebx
0x736bc5 8d4c2424 lea    ecx,[esp+0x24]
0x736bc9 c744243807000000 mov    DWORD PTR [esp+0x38],0x7
0x736bd1 c744243400000000 mov    DWORD PTR [esp+0x34],0x0
0x736bd9 e802bbccff call   0x4026e0
0x736bde 897c2434 mov    DWORD PTR [esp+0x34],edi
0x736be2 8d542418 lea    edx,[esp+0x18]
0x736be6 52 push   edx
0x736be7 8bce mov    ecx,esi
0x736be9 c744244c01000000 mov    DWORD PTR [esp+0x4c],0x1
0x736bf1 e83a050000 call   0x737130
0x736bf6 50 push   eax
0x736bf7 8d442414 lea    eax,[esp+0x14]
0x736bfb 50 push   eax
0x736bfc 56 push   esi
0x736bfd e82e8fd1ff call   0x44fb30
0x736c02 c7442448ffffffff mov    DWORD PTR [esp+0x48],0xffffffff
0x736c0a 837c242c08 cmp    DWORD PTR [esp+0x2c],0x8
0x736c0f 720d jb     0x736c1e
0x736c11 8b4c2418 mov    ecx,DWORD PTR [esp+0x18]
0x736c15 51 push   ecx
0x736c16 e8f1a51500 call   0x89120c
0x736c1b 83c404 add    esp,0x4
0x736c1e 8b07 mov    eax,DWORD PTR [edi]
0x736c20 33d2 xor    edx,edx
0x736c22 6689542418 mov    WORD PTR [esp+0x18],dx
0x736c27 8b5004 mov    edx,DWORD PTR [eax+0x4]
0x736c2a 8bcf mov    ecx,edi
0x736c2c c744242c07000000 mov    DWORD PTR [esp+0x2c],0x7
0x736c34 c744242800000000 mov    DWORD PTR [esp+0x28],0x0
0x736c3c ffd2 call   edx
0x736c3e 8bc7 mov    eax,edi
0x736c40 eb02 jmp    0x736c44
0x736c42 33c0 xor    eax,eax
0x736c44 8b4c2440 mov    ecx,DWORD PTR [esp+0x40]
0x736c48 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x736c4f 59 pop    ecx
0x736c50 5f pop    edi
0x736c51 5e pop    esi
0x736c52 5b pop    ebx
0x736c53 8b4c2428 mov    ecx,DWORD PTR [esp+0x28]
0x736c57 33cc xor    ecx,esp
0x736c59 e8a3a31500 call   0x891001
0x736c5e 8be5 mov    esp,ebp
0x736c60 5d pop    ebp
0x736c61 c20400 ret    0x4

; image_texture_load | original name to GetImageInfo adapter737D40, then nonnegative result permits737F40 load
0x73abe0 55 push   ebp
0x73abe1 8bec mov    ebp,esp
0x73abe3 83e4f8 and    esp,0xfffffff8
0x73abe6 6aff push   0xffffffff
0x73abe8 686e889200 push   0x92886e
0x73abed 64a100000000 mov    eax,fs:0x0
0x73abf3 50 push   eax
0x73abf4 81ec20010000 sub    esp,0x120
0x73abfa a1201fd600 mov    eax,ds:0xd61f20
0x73abff 33c4 xor    eax,esp
0x73ac01 89842418010000 mov    DWORD PTR [esp+0x118],eax
0x73ac08 53 push   ebx
0x73ac09 56 push   esi
0x73ac0a 57 push   edi
0x73ac0b a1201fd600 mov    eax,ds:0xd61f20
0x73ac10 33c4 xor    eax,esp
0x73ac12 50 push   eax
0x73ac13 8d842430010000 lea    eax,[esp+0x130]
0x73ac1a 64a300000000 mov    fs:0x0,eax
0x73ac20 b801000000 mov    eax,0x1
0x73ac25 8bf9 mov    edi,ecx
0x73ac27 840540defc00 test   BYTE PTR ds:0xfcde40,al
0x73ac2d 752e jne    0x73ac5d
0x73ac2f 090540defc00 or     DWORD PTR ds:0xfcde40,eax
0x73ac35 c784243801000000000000 mov    DWORD PTR [esp+0x138],0x0
0x73ac40 e83bbcffff call   0x736880
0x73ac45 68f0e6bc00 push   0xbce6f0
0x73ac4a e8cb761500 call   0x89231a
0x73ac4f 83c404 add    esp,0x4
0x73ac52 c7842438010000ffffffff mov    DWORD PTR [esp+0x138],0xffffffff
0x73ac5d 8b1d2cdefc00 mov    ebx,DWORD PTR ds:0xfcde2c
0x73ac63 85db test   ebx,ebx
0x73ac65 0f8484000000 je     0x73acef
0x73ac6b 837f3808 cmp    DWORD PTR [edi+0x38],0x8
0x73ac6f 8d4724 lea    eax,[edi+0x24]
0x73ac72 7202 jb     0x73ac76
0x73ac74 8b00 mov    eax,DWORD PTR [eax]
0x73ac76 85c0 test   eax,eax
0x73ac78 7507 jne    0x73ac81
0x73ac7a b87523bf00 mov    eax,0xbf2375
0x73ac7f eb20 jmp    0x73aca1
0x73ac81 6a00 push   0x0
0x73ac83 6a00 push   0x0
0x73ac85 6800040000 push   0x400
0x73ac8a 6810f7fd00 push   0xfdf710
0x73ac8f 6aff push   0xffffffff
0x73ac91 50 push   eax
0x73ac92 6a00 push   0x0
0x73ac94 6a00 push   0x0
0x73ac96 ff15cc21bd00 call   DWORD PTR ds:0xbd21cc
0x73ac9c b810f7fd00 mov    eax,0xfdf710
0x73aca1 50 push   eax
0x73aca2 8d442420 lea    eax,[esp+0x20]
0x73aca6 6804010000 push   0x104
0x73acab 50 push   eax
0x73acac e8a88e1500 call   0x893b59
0x73acb1 8d7708 lea    esi,[edi+0x8]
0x73acb4 83c40c add    esp,0xc
0x73acb7 8d54241c lea    edx,[esp+0x1c]
0x73acbb 8d4c2414 lea    ecx,[esp+0x14]
0x73acbf c74424141056c400 mov    DWORD PTR [esp+0x14],0xc45610
0x73acc7 89742418 mov    DWORD PTR [esp+0x18],esi
0x73accb e870d0ffff call   0x737d40
0x73acd0 85c0 test   eax,eax
0x73acd2 781b js     0x73acef
0x73acd4 8b570c mov    edx,DWORD PTR [edi+0xc]
0x73acd7 8d4f44 lea    ecx,[edi+0x44]
0x73acda 51 push   ecx
0x73acdb 8b0e mov    ecx,DWORD PTR [esi]
0x73acdd 6a00 push   0x0
0x73acdf 52 push   edx
0x73ace0 8d442428 lea    eax,[esp+0x28]
0x73ace4 50 push   eax
0x73ace5 8bc3 mov    eax,ebx
0x73ace7 e854d2ffff call   0x737f40
0x73acec 83c410 add    esp,0x10
0x73acef 8b8c2430010000 mov    ecx,DWORD PTR [esp+0x130]
0x73acf6 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x73acfd 59 pop    ecx
0x73acfe 5f pop    edi
0x73acff 5e pop    esi
0x73ad00 5b pop    ebx
0x73ad01 8b8c2418010000 mov    ecx,DWORD PTR [esp+0x118]
0x73ad08 33cc xor    ecx,esp
0x73ad0a e8f2621500 call   0x891001
0x73ad0f 8be5 mov    esp,ebp
0x73ad11 5d pop    ebp
0x73ad12 c3 ret

; flying_image_texture_factory | FlyingImage actual path and second argument0 enter7340C0 with new texture object
0x734330 55 push   ebp
0x734331 8bec mov    ebp,esp
0x734333 6aff push   0xffffffff
0x734335 68dbc09100 push   0x91c0db
0x73433a 64a100000000 mov    eax,fs:0x0
0x734340 50 push   eax
0x734341 51 push   ecx
0x734342 56 push   esi
0x734343 a1201fd600 mov    eax,ds:0xd61f20
0x734348 33c5 xor    eax,ebp
0x73434a 50 push   eax
0x73434b 8d45f4 lea    eax,[ebp-0xc]
0x73434e 64a300000000 mov    fs:0x0,eax
0x734354 6a48 push   0x48
0x734356 e80dcf1500 call   0x891268
0x73435b 83c404 add    esp,0x4
0x73435e 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x734361 c745fc00000000 mov    DWORD PTR [ebp-0x4],0x0
0x734368 85c0 test   eax,eax
0x73436a 740b je     0x734377
0x73436c 8bf0 mov    esi,eax
0x73436e e89dfcffff call   0x734010
0x734373 8bf0 mov    esi,eax
0x734375 eb02 jmp    0x734379
0x734377 33f6 xor    esi,esi
0x734379 8b4d0c mov    ecx,DWORD PTR [ebp+0xc]
0x73437c 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x73437f 56 push   esi
0x734380 c745fcffffffff mov    DWORD PTR [ebp-0x4],0xffffffff
0x734387 e834fdffff call   0x7340c0
0x73438c 85c0 test   eax,eax
0x73438e 7920 jns    0x7343b0
0x734390 85f6 test   esi,esi
0x734392 740a je     0x73439e
0x734394 8b06 mov    eax,DWORD PTR [esi]
0x734396 8b10 mov    edx,DWORD PTR [eax]
0x734398 6a01 push   0x1
0x73439a 8bce mov    ecx,esi
0x73439c ffd2 call   edx
0x73439e 33c0 xor    eax,eax
0x7343a0 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x7343a3 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x7343aa 59 pop    ecx
0x7343ab 5e pop    esi
0x7343ac 8be5 mov    esp,ebp
0x7343ae 5d pop    ebp
0x7343af c3 ret
0x7343b0 8bc6 mov    eax,esi
0x7343b2 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x7343b5 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x7343bc 59 pop    ecx
0x7343bd 5e pop    esi
0x7343be 8be5 mov    esp,ebp
0x7343c0 5d pop    ebp
0x7343c1 c3 ret

; flying_image_texture_load | FlyingImage enters737D40 image-info and737F40 texture-create; no nonnegative-info gate like73ABE0
0x7340c0 55 push   ebp
0x7340c1 8bec mov    ebp,esp
0x7340c3 83e4f8 and    esp,0xfffffff8
0x7340c6 6aff push   0xffffffff
0x7340c8 6856679200 push   0x926756
0x7340cd 64a100000000 mov    eax,fs:0x0
0x7340d3 50 push   eax
0x7340d4 83ec50 sub    esp,0x50
0x7340d7 a1201fd600 mov    eax,ds:0xd61f20
0x7340dc 33c4 xor    eax,esp
0x7340de 89442448 mov    DWORD PTR [esp+0x48],eax
0x7340e2 53 push   ebx
0x7340e3 56 push   esi
0x7340e4 57 push   edi
0x7340e5 a1201fd600 mov    eax,ds:0xd61f20
0x7340ea 33c4 xor    eax,esp
0x7340ec 50 push   eax
0x7340ed 8d442460 lea    eax,[esp+0x60]
0x7340f1 64a300000000 mov    fs:0x0,eax
0x7340f7 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x7340fa 89442414 mov    DWORD PTR [esp+0x14],eax
0x7340fe 33c0 xor    eax,eax
0x734100 8bf2 mov    esi,edx
0x734102 c74424340f000000 mov    DWORD PTR [esp+0x34],0xf
0x73410a 89442430 mov    DWORD PTR [esp+0x30],eax
0x73410e 88442420 mov    BYTE PTR [esp+0x20],al
0x734112 89442468 mov    DWORD PTR [esp+0x68],eax
0x734116 3bc8 cmp    ecx,eax
0x734118 751f jne    0x734139
0x73411a 8bc6 mov    eax,esi
0x73411c 8d5001 lea    edx,[eax+0x1]
0x73411f 90 nop
0x734120 8a08 mov    cl,BYTE PTR [eax]
0x734122 40 inc    eax
0x734123 84c9 test   cl,cl
0x734125 75f9 jne    0x734120
0x734127 2bc2 sub    eax,edx
0x734129 50 push   eax
0x73412a 56 push   esi
0x73412b 8d4c2428 lea    ecx,[esp+0x28]
0x73412f e83ce9ccff call   0x402a70
0x734134 e9cb000000 jmp    0x734204
0x734139 803900 cmp    BYTE PTR [ecx],0x0
0x73413c 751e jne    0x73415c
0x73413e 8bc6 mov    eax,esi
0x734140 8d5001 lea    edx,[eax+0x1]
0x734143 8a08 mov    cl,BYTE PTR [eax]
0x734145 40 inc    eax
0x734146 84c9 test   cl,cl
0x734148 75f9 jne    0x734143
0x73414a 2bc2 sub    eax,edx
0x73414c 50 push   eax
0x73414d 56 push   esi
0x73414e 8d4c2428 lea    ecx,[esp+0x28]
0x734152 e819e9ccff call   0x402a70
0x734157 e9a8000000 jmp    0x734204
0x73415c 8bc1 mov    eax,ecx
0x73415e 8d7801 lea    edi,[eax+0x1]
0x734161 8a10 mov    dl,BYTE PTR [eax]
0x734163 40 inc    eax
0x734164 84d2 test   dl,dl
0x734166 75f9 jne    0x734161
0x734168 2bc7 sub    eax,edi
0x73416a 807c08ff2f cmp    BYTE PTR [eax+ecx*1-0x1],0x2f
0x73416f 7458 je     0x7341c9
0x734171 8bc1 mov    eax,ecx
0x734173 8d7801 lea    edi,[eax+0x1]
0x734176 8a10 mov    dl,BYTE PTR [eax]
0x734178 40 inc    eax
0x734179 84d2 test   dl,dl
0x73417b 75f9 jne    0x734176
0x73417d 2bc7 sub    eax,edi
0x73417f 807c08ff5c cmp    BYTE PTR [eax+ecx*1-0x1],0x5c
0x734184 7443 je     0x7341c9
0x734186 8bc1 mov    eax,ecx
0x734188 8d7801 lea    edi,[eax+0x1]
0x73418b eb03 jmp    0x734190
0x73418d 8d4900 lea    ecx,[ecx+0x0]
0x734190 8a10 mov    dl,BYTE PTR [eax]
0x734192 40 inc    eax
0x734193 84d2 test   dl,dl
0x734195 75f9 jne    0x734190
0x734197 2bc7 sub    eax,edi
0x734199 50 push   eax
0x73419a 51 push   ecx
0x73419b 8d4c2428 lea    ecx,[esp+0x28]
0x73419f e8cce8ccff call   0x402a70
0x7341a4 6a01 push   0x1
0x7341a6 68e4d1be00 push   0xbed1e4
0x7341ab 8d4c2428 lea    ecx,[esp+0x28]
0x7341af e80cdeccff call   0x401fc0
0x7341b4 8bc6 mov    eax,esi
0x7341b6 8d5001 lea    edx,[eax+0x1]
0x7341b9 8da42400000000 lea    esp,[esp+0x0]
0x7341c0 8a08 mov    cl,BYTE PTR [eax]
0x7341c2 40 inc    eax
0x7341c3 84c9 test   cl,cl
0x7341c5 75f9 jne    0x7341c0
0x7341c7 eb2e jmp    0x7341f7
0x7341c9 8bc1 mov    eax,ecx
0x7341cb 8d7801 lea    edi,[eax+0x1]
0x7341ce 8bff mov    edi,edi
0x7341d0 8a10 mov    dl,BYTE PTR [eax]
0x7341d2 40 inc    eax
0x7341d3 84d2 test   dl,dl
0x7341d5 75f9 jne    0x7341d0
0x7341d7 2bc7 sub    eax,edi
0x7341d9 50 push   eax
0x7341da 51 push   ecx
0x7341db 8d4c2428 lea    ecx,[esp+0x28]
0x7341df e88ce8ccff call   0x402a70
0x7341e4 8bc6 mov    eax,esi
0x7341e6 8d5001 lea    edx,[eax+0x1]
0x7341e9 8da42400000000 lea    esp,[esp+0x0]
0x7341f0 8a08 mov    cl,BYTE PTR [eax]
0x7341f2 40 inc    eax
0x7341f3 84c9 test   cl,cl
0x7341f5 75f9 jne    0x7341f0
0x7341f7 2bc2 sub    eax,edx
0x7341f9 50 push   eax
0x7341fa 56 push   esi
0x7341fb 8d4c2428 lea    ecx,[esp+0x28]
0x7341ff e8bcddccff call   0x401fc0
0x734204 8b542420 mov    edx,DWORD PTR [esp+0x20]
0x734208 bb10000000 mov    ebx,0x10
0x73420d 395c2434 cmp    DWORD PTR [esp+0x34],ebx
0x734211 7304 jae    0x734217
0x734213 8d542420 lea    edx,[esp+0x20]
0x734217 8d4c243c lea    ecx,[esp+0x3c]
0x73421b 894c241c mov    DWORD PTR [esp+0x1c],ecx
0x73421f 8d4c2418 lea    ecx,[esp+0x18]
0x734223 c74424181056c400 mov    DWORD PTR [esp+0x18],0xc45610
0x73422b e8103b0000 call   0x737d40
0x734230 8b54244c mov    edx,DWORD PTR [esp+0x4c]
0x734234 52 push   edx
0x734235 68e453c400 push   0xc453e4
0x73423a e8d198fbff call   0x6edb10
0x73423f 83c408 add    esp,0x8
0x734242 837c244c19 cmp    DWORD PTR [esp+0x4c],0x19
0x734247 7508 jne    0x734251
0x734249 c744244c17000000 mov    DWORD PTR [esp+0x4c],0x17
0x734251 8b7c2414 mov    edi,DWORD PTR [esp+0x14]
0x734255 83c70c add    edi,0xc
0x734258 b907000000 mov    ecx,0x7
0x73425d 8d74243c lea    esi,[esp+0x3c]
0x734261 f3a5 rep movs DWORD PTR es:[edi],DWORD PTR ds:[esi]
0x734263 8b742420 mov    esi,DWORD PTR [esp+0x20]
0x734267 395c2434 cmp    DWORD PTR [esp+0x34],ebx
0x73426b 7304 jae    0x734271
0x73426d 8d742420 lea    esi,[esp+0x20]
0x734271 f60540defc0001 test   BYTE PTR ds:0xfcde40,0x1
0x734278 7523 jne    0x73429d
0x73427a 830d40defc0001 or     DWORD PTR ds:0xfcde40,0x1
0x734281 c644246801 mov    BYTE PTR [esp+0x68],0x1
0x734286 e8f5250000 call   0x736880
0x73428b 68f0e6bc00 push   0xbce6f0
0x734290 e885e01500 call   0x89231a
0x734295 83c404 add    esp,0x4
0x734298 c644246800 mov    BYTE PTR [esp+0x68],0x0
0x73429d 8b442414 mov    eax,DWORD PTR [esp+0x14]
0x7342a1 83c044 add    eax,0x44
0x7342a4 50 push   eax
0x7342a5 a12cdefc00 mov    eax,ds:0xfcde2c
0x7342aa 6a00 push   0x0
0x7342ac 6aff push   0xffffffff
0x7342ae 56 push   esi
0x7342af 83c9ff or     ecx,0xffffffff
0x7342b2 e8893c0000 call   0x737f40
0x7342b7 8bf0 mov    esi,eax
0x7342b9 83c410 add    esp,0x10
0x7342bc 85f6 test   esi,esi
0x7342be 792c jns    0x7342ec
0x7342c0 68f053c400 push   0xc453f0
0x7342c5 e84698fbff call   0x6edb10
0x7342ca 6a00 push   0x0
0x7342cc 56 push   esi
0x7342cd e8befcffff call   0x733f90
0x7342d2 83c40c add    esp,0xc
0x7342d5 395c2434 cmp    DWORD PTR [esp+0x34],ebx
0x7342d9 720d jb     0x7342e8
0x7342db 8b4c2420 mov    ecx,DWORD PTR [esp+0x20]
0x7342df 51 push   ecx
0x7342e0 e827cf1500 call   0x89120c
0x7342e5 83c404 add    esp,0x4
0x7342e8 8bc6 mov    eax,esi
0x7342ea eb15 jmp    0x734301
0x7342ec 395c2434 cmp    DWORD PTR [esp+0x34],ebx
0x7342f0 720d jb     0x7342ff
0x7342f2 8b542420 mov    edx,DWORD PTR [esp+0x20]
0x7342f6 52 push   edx
0x7342f7 e810cf1500 call   0x89120c
0x7342fc 83c404 add    esp,0x4
0x7342ff 33c0 xor    eax,eax
0x734301 8b4c2460 mov    ecx,DWORD PTR [esp+0x60]
0x734305 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x73430c 59 pop    ecx
0x73430d 5f pop    edi
0x73430e 5e pop    esi
0x73430f 5b pop    ebx
0x734310 8b4c2448 mov    ecx,DWORD PTR [esp+0x48]
0x734314 33cc xor    ecx,esp
0x734316 e8e6cc1500 call   0x891001
0x73431b 8be5 mov    esp,ebp
0x73431d 5d pop    ebp
0x73431e c20400 ret    0x4

; texture_name_rewrite | split original path; preserve drive directory stem; append .etf
0x714970 55 push   ebp
0x714971 8bec mov    ebp,esp
0x714973 6aff push   0xffffffff
0x714975 68225d9100 push   0x915d22
0x71497a 64a100000000 mov    eax,fs:0x0
0x714980 50 push   eax
0x714981 81ecb4010000 sub    esp,0x1b4
0x714987 a1201fd600 mov    eax,ds:0xd61f20
0x71498c 33c5 xor    eax,ebp
0x71498e 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x714991 50 push   eax
0x714992 8d45f4 lea    eax,[ebp-0xc]
0x714995 64a300000000 mov    fs:0x0,eax
0x71499b 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x71499e c78544feffff00000000 mov    DWORD PTR [ebp-0x1bc],0x0
0x7149a8 83781410 cmp    DWORD PTR [eax+0x14],0x10
0x7149ac 89b540feffff mov    DWORD PTR [ebp-0x1c0],esi
0x7149b2 7202 jb     0x7149b6
0x7149b4 8b00 mov    eax,DWORD PTR [eax]
0x7149b6 6a20 push   0x20
0x7149b8 8d4dd0 lea    ecx,[ebp-0x30]
0x7149bb 51 push   ecx
0x7149bc 6880000000 push   0x80
0x7149c1 8d9550ffffff lea    edx,[ebp-0xb0]
0x7149c7 52 push   edx
0x7149c8 6804010000 push   0x104
0x7149cd 8d8d4cfeffff lea    ecx,[ebp-0x1b4]
0x7149d3 51 push   ecx
0x7149d4 6a02 push   0x2
0x7149d6 8d9548feffff lea    edx,[ebp-0x1b8]
0x7149dc 52 push   edx
0x7149dd 50 push   eax
0x7149de e8001f1800 call   0x8968e3
0x7149e3 c746140f000000 mov    DWORD PTR [esi+0x14],0xf
0x7149ea c7461000000000 mov    DWORD PTR [esi+0x10],0x0
0x7149f1 83c424 add    esp,0x24
0x7149f4 c60600 mov    BYTE PTR [esi],0x0
0x7149f7 8d8548feffff lea    eax,[ebp-0x1b8]
0x7149fd c745fc00000000 mov    DWORD PTR [ebp-0x4],0x0
0x714a04 c78544feffff01000000 mov    DWORD PTR [ebp-0x1bc],0x1
0x714a0e 8d5001 lea    edx,[eax+0x1]
0x714a11 8a08 mov    cl,BYTE PTR [eax]
0x714a13 40 inc    eax
0x714a14 84c9 test   cl,cl
0x714a16 75f9 jne    0x714a11
0x714a18 2bc2 sub    eax,edx
0x714a1a 50 push   eax
0x714a1b 8d8548feffff lea    eax,[ebp-0x1b8]
0x714a21 50 push   eax
0x714a22 8bce mov    ecx,esi
0x714a24 e897d5ceff call   0x401fc0
0x714a29 8d854cfeffff lea    eax,[ebp-0x1b4]
0x714a2f 8d5001 lea    edx,[eax+0x1]
0x714a32 8a08 mov    cl,BYTE PTR [eax]
0x714a34 40 inc    eax
0x714a35 84c9 test   cl,cl
0x714a37 75f9 jne    0x714a32
0x714a39 2bc2 sub    eax,edx
0x714a3b 50 push   eax
0x714a3c 8d8d4cfeffff lea    ecx,[ebp-0x1b4]
0x714a42 51 push   ecx
0x714a43 8bce mov    ecx,esi
0x714a45 e876d5ceff call   0x401fc0
0x714a4a 8d8550ffffff lea    eax,[ebp-0xb0]
0x714a50 8d5001 lea    edx,[eax+0x1]
0x714a53 8a08 mov    cl,BYTE PTR [eax]
0x714a55 40 inc    eax
0x714a56 84c9 test   cl,cl
0x714a58 75f9 jne    0x714a53
0x714a5a 2bc2 sub    eax,edx
0x714a5c 50 push   eax
0x714a5d 8d9550ffffff lea    edx,[ebp-0xb0]
0x714a63 52 push   edx
0x714a64 8bce mov    ecx,esi
0x714a66 e855d5ceff call   0x401fc0
0x714a6b 6a04 push   0x4
0x714a6d 680801c100 push   0xc10108
0x714a72 8bce mov    ecx,esi
0x714a74 e847d5ceff call   0x401fc0
0x714a79 8bc6 mov    eax,esi
0x714a7b 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x714a7e 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x714a85 59 pop    ecx
0x714a86 8b4df0 mov    ecx,DWORD PTR [ebp-0x10]
0x714a89 33cd xor    ecx,ebp
0x714a8b e871c51700 call   0x891001
0x714a90 8be5 mov    esp,ebp
0x714a92 5d pop    ebp
0x714a93 c3 ret

; texture_name_rewrite_wrapper | 737D40 wrapper to714970
0x714aa0 55 push   ebp
0x714aa1 8bec mov    ebp,esp
0x714aa3 51 push   ecx
0x714aa4 56 push   esi
0x714aa5 8bf1 mov    esi,ecx
0x714aa7 50 push   eax
0x714aa8 c745fc00000000 mov    DWORD PTR [ebp-0x4],0x0
0x714aaf e8bcfeffff call   0x714970
0x714ab4 83c404 add    esp,0x4
0x714ab7 8bc6 mov    eax,esi
0x714ab9 5e pop    esi
0x714aba 8be5 mov    esp,ebp
0x714abc 5d pop    ebp
0x714abd c3 ret

; texture_common_read | original probe nonzero -> file adapter; zero -> .etf,714770,optionalEX decode,transform,buffer+8 adapter
0x737d40 55 push   ebp
0x737d41 8bec mov    ebp,esp
0x737d43 6aff push   0xffffffff
0x737d45 6870279200 push   0x922770
0x737d4a 64a100000000 mov    eax,fs:0x0
0x737d50 50 push   eax
0x737d51 83ec48 sub    esp,0x48
0x737d54 a1201fd600 mov    eax,ds:0xd61f20
0x737d59 33c5 xor    eax,ebp
0x737d5b 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x737d5e 53 push   ebx
0x737d5f 56 push   esi
0x737d60 57 push   edi
0x737d61 50 push   eax
0x737d62 8d45f4 lea    eax,[ebp-0xc]
0x737d65 64a300000000 mov    fs:0x0,eax
0x737d6b 8bf2 mov    esi,edx
0x737d6d 8bf9 mov    edi,ecx
0x737d6f 56 push   esi
0x737d70 897db0 mov    DWORD PTR [ebp-0x50],edi
0x737d73 e8d8c7fdff call   0x714550
0x737d78 83c404 add    esp,0x4
0x737d7b 85c0 test   eax,eax
0x737d7d 740e je     0x737d8d
0x737d7f 8b07 mov    eax,DWORD PTR [edi]
0x737d81 8b10 mov    edx,DWORD PTR [eax]
0x737d83 56 push   esi
0x737d84 8bcf mov    ecx,edi
0x737d86 ffd2 call   edx
0x737d88 e936010000 jmp    0x737ec3
0x737d8d 33ff xor    edi,edi
0x737d8f 8bc6 mov    eax,esi
0x737d91 c745e80f000000 mov    DWORD PTR [ebp-0x18],0xf
0x737d98 897de4 mov    DWORD PTR [ebp-0x1c],edi
0x737d9b c645d400 mov    BYTE PTR [ebp-0x2c],0x0
0x737d9f 8d5001 lea    edx,[eax+0x1]
0x737da2 8a08 mov    cl,BYTE PTR [eax]
0x737da4 40 inc    eax
0x737da5 84c9 test   cl,cl
0x737da7 75f9 jne    0x737da2
0x737da9 2bc2 sub    eax,edx
0x737dab 50 push   eax
0x737dac 56 push   esi
0x737dad 8d4dd4 lea    ecx,[ebp-0x2c]
0x737db0 e8bbacccff call   0x402a70
0x737db5 8d45d4 lea    eax,[ebp-0x2c]
0x737db8 8d4db8 lea    ecx,[ebp-0x48]
0x737dbb 897dfc mov    DWORD PTR [ebp-0x4],edi
0x737dbe e8ddccfdff call   0x714aa0
0x737dc3 bb10000000 mov    ebx,0x10
0x737dc8 c645fc02 mov    BYTE PTR [ebp-0x4],0x2
0x737dcc 395de8 cmp    DWORD PTR [ebp-0x18],ebx
0x737dcf 720c jb     0x737ddd
0x737dd1 8b45d4 mov    eax,DWORD PTR [ebp-0x2c]
0x737dd4 50 push   eax
0x737dd5 e832941500 call   0x89120c
0x737dda 83c404 add    esp,0x4
0x737ddd 8b45b8 mov    eax,DWORD PTR [ebp-0x48]
0x737de0 c745e80f000000 mov    DWORD PTR [ebp-0x18],0xf
0x737de7 897de4 mov    DWORD PTR [ebp-0x1c],edi
0x737dea c645d400 mov    BYTE PTR [ebp-0x2c],0x0
0x737dee 395dcc cmp    DWORD PTR [ebp-0x34],ebx
0x737df1 7303 jae    0x737df6
0x737df3 8d45b8 lea    eax,[ebp-0x48]
0x737df6 68e0d1be00 push   0xbed1e0
0x737dfb 50 push   eax
0x737dfc e86fc9fdff call   0x714770
0x737e01 8bf0 mov    esi,eax
0x737e03 83c408 add    esp,0x8
0x737e06 3bf7 cmp    esi,edi
0x737e08 751b jne    0x737e25
0x737e0a 395dcc cmp    DWORD PTR [ebp-0x34],ebx
0x737e0d 720c jb     0x737e1b
0x737e0f 8b4db8 mov    ecx,DWORD PTR [ebp-0x48]
0x737e12 51 push   ecx
0x737e13 e8f4931500 call   0x89120c
0x737e18 83c404 add    esp,0x4
0x737e1b b86a087688 mov    eax,0x8876086a
0x737e20 e99e000000 jmp    0x737ec3
0x737e25 8b16 mov    edx,DWORD PTR [esi]
0x737e27 8b422c mov    eax,DWORD PTR [edx+0x2c]
0x737e2a 8bce mov    ecx,esi
0x737e2c ffd0 call   eax
0x737e2e 8bd8 mov    ebx,eax
0x737e30 53 push   ebx
0x737e31 e8075e1400 call   0x87dc3d
0x737e36 8b16 mov    edx,DWORD PTR [esi]
0x737e38 83c404 add    esp,0x4
0x737e3b 6a01 push   0x1
0x737e3d 8bf8 mov    edi,eax
0x737e3f 8b4210 mov    eax,DWORD PTR [edx+0x10]
0x737e42 53 push   ebx
0x737e43 57 push   edi
0x737e44 8bce mov    ecx,esi
0x737e46 ffd0 call   eax
0x737e48 8b16 mov    edx,DWORD PTR [esi]
0x737e4a 8b4204 mov    eax,DWORD PTR [edx+0x4]
0x737e4d 8bce mov    ecx,esi
0x737e4f ffd0 call   eax
0x737e51 8d4dac lea    ecx,[ebp-0x54]
0x737e54 51 push   ecx
0x737e55 8d55b4 lea    edx,[ebp-0x4c]
0x737e58 52 push   edx
0x737e59 53 push   ebx
0x737e5a 57 push   edi
0x737e5b c745b400000000 mov    DWORD PTR [ebp-0x4c],0x0
0x737e62 e849f0fdff call   0x716eb0
0x737e67 83c410 add    esp,0x10
0x737e6a 85c0 test   eax,eax
0x737e6c 7904 jns    0x737e72
0x737e6e 8bf7 mov    esi,edi
0x737e70 eb06 jmp    0x737e78
0x737e72 8b75b4 mov    esi,DWORD PTR [ebp-0x4c]
0x737e75 8b5dac mov    ebx,DWORD PTR [ebp-0x54]
0x737e78 53 push   ebx
0x737e79 e8e2bfffff call   0x733e60
0x737e7e 8b4db0 mov    ecx,DWORD PTR [ebp-0x50]
0x737e81 8b01 mov    eax,DWORD PTR [ecx]
0x737e83 8b5004 mov    edx,DWORD PTR [eax+0x4]
0x737e86 83c3f8 add    ebx,0xfffffff8
0x737e89 53 push   ebx
0x737e8a 83c608 add    esi,0x8
0x737e8d 56 push   esi
0x737e8e ffd2 call   edx
0x737e90 8bf0 mov    esi,eax
0x737e92 85ff test   edi,edi
0x737e94 7409 je     0x737e9f
0x737e96 57 push   edi
0x737e97 e8a19e1500 call   0x891d3d
0x737e9c 83c404 add    esp,0x4
0x737e9f 8b45b4 mov    eax,DWORD PTR [ebp-0x4c]
0x737ea2 85c0 test   eax,eax
0x737ea4 7409 je     0x737eaf
0x737ea6 50 push   eax
0x737ea7 e8919e1500 call   0x891d3d
0x737eac 83c404 add    esp,0x4
0x737eaf 837dcc10 cmp    DWORD PTR [ebp-0x34],0x10
0x737eb3 720c jb     0x737ec1
0x737eb5 8b45b8 mov    eax,DWORD PTR [ebp-0x48]
0x737eb8 50 push   eax
0x737eb9 e84e931500 call   0x89120c
0x737ebe 83c404 add    esp,0x4
0x737ec1 8bc6 mov    eax,esi
0x737ec3 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x737ec6 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x737ecd 59 pop    ecx
0x737ece 5f pop    edi
0x737ecf 5e pop    esi
0x737ed0 5b pop    ebx
0x737ed1 8b4df0 mov    ecx,DWORD PTR [ebp-0x10]
0x737ed4 33cd xor    ecx,ebp
0x737ed6 e826911500 call   0x891001
0x737edb 8be5 mov    esp,ebp
0x737edd 5d pop    ebp
0x737ede c3 ret

; texture_create_adapter | texture create adapter enters same737D40 read policy
0x737f40 55 push   ebp
0x737f41 8bec mov    ebp,esp
0x737f43 83e4f8 and    esp,0xfffffff8
0x737f46 83ec38 sub    esp,0x38
0x737f49 8b550c mov    edx,DWORD PTR [ebp+0xc]
0x737f4c 894c2408 mov    DWORD PTR [esp+0x8],ecx
0x737f50 8954240c mov    DWORD PTR [esp+0xc],edx
0x737f54 83caff or     edx,0xffffffff
0x737f57 b901000000 mov    ecx,0x1
0x737f5c 89542410 mov    DWORD PTR [esp+0x10],edx
0x737f60 894c241c mov    DWORD PTR [esp+0x1c],ecx
0x737f64 894c2420 mov    DWORD PTR [esp+0x20],ecx
0x737f68 8b4d10 mov    ecx,DWORD PTR [ebp+0x10]
0x737f6b 89542424 mov    DWORD PTR [esp+0x24],edx
0x737f6f 8b5514 mov    edx,DWORD PTR [ebp+0x14]
0x737f72 89442404 mov    DWORD PTR [esp+0x4],eax
0x737f76 33c0 xor    eax,eax
0x737f78 894c2428 mov    DWORD PTR [esp+0x28],ecx
0x737f7c 89542434 mov    DWORD PTR [esp+0x34],edx
0x737f80 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x737f83 8d0c24 lea    ecx,[esp]
0x737f86 c704240456c400 mov    DWORD PTR [esp],0xc45604
0x737f8d 89442414 mov    DWORD PTR [esp+0x14],eax
0x737f91 89442418 mov    DWORD PTR [esp+0x18],eax
0x737f95 8944242c mov    DWORD PTR [esp+0x2c],eax
0x737f99 89442430 mov    DWORD PTR [esp+0x30],eax
0x737f9d e89efdffff call   0x737d40
0x737fa2 8be5 mov    esp,ebp
0x737fa4 5d pop    ebp
0x737fa5 c3 ret

; model_texture_manager_init | normal initialized FE1AE0 function pointer is7BC2C0
0x7bb970 55 push   ebp
0x7bb971 8bec mov    ebp,esp
0x7bb973 6aff push   0xffffffff
0x7bb975 687d509300 push   0x93507d
0x7bb97a 64a100000000 mov    eax,fs:0x0
0x7bb980 50 push   eax
0x7bb981 83ec24 sub    esp,0x24
0x7bb984 56 push   esi
0x7bb985 a1201fd600 mov    eax,ds:0xd61f20
0x7bb98a 33c5 xor    eax,ebp
0x7bb98c 50 push   eax
0x7bb98d 8d45f4 lea    eax,[ebp-0xc]
0x7bb990 64a300000000 mov    fs:0x0,eax
0x7bb996 33f6 xor    esi,esi
0x7bb998 6a30 push   0x30
0x7bb99a c745e8c81afe00 mov    DWORD PTR [ebp-0x18],0xfe1ac8
0x7bb9a1 c705c81afe00e8fcc400 mov    DWORD PTR ds:0xfe1ac8,0xc4fce8
0x7bb9ab 8935f41afe00 mov    DWORD PTR ds:0xfe1af4,esi
0x7bb9b1 e8b2580d00 call   0x891268
0x7bb9b6 83c404 add    esp,0x4
0x7bb9b9 3bc6 cmp    eax,esi
0x7bb9bb 0f84ea000000 je     0x7bbaab
0x7bb9c1 a3f01afe00 mov    ds:0xfe1af0,eax
0x7bb9c6 8900 mov    DWORD PTR [eax],eax
0x7bb9c8 a1f01afe00 mov    eax,ds:0xfe1af0
0x7bb9cd 894004 mov    DWORD PTR [eax+0x4],eax
0x7bb9d0 a1f01afe00 mov    eax,ds:0xfe1af0
0x7bb9d5 894008 mov    DWORD PTR [eax+0x8],eax
0x7bb9d8 8b0df01afe00 mov    ecx,DWORD PTR ds:0xfe1af0
0x7bb9de b001 mov    al,0x1
0x7bb9e0 88412c mov    BYTE PTR [ecx+0x2c],al
0x7bb9e3 8b15f01afe00 mov    edx,DWORD PTR ds:0xfe1af0
0x7bb9e9 88422d mov    BYTE PTR [edx+0x2d],al
0x7bb9ec 8975fc mov    DWORD PTR [ebp-0x4],esi
0x7bb9ef 6a50 push   0x50
0x7bb9f1 8935001bfe00 mov    DWORD PTR ds:0xfe1b00,esi
0x7bb9f7 e86c580d00 call   0x891268
0x7bb9fc 83c404 add    esp,0x4
0x7bb9ff 3bc6 cmp    eax,esi
0x7bba01 0f8480000000 je     0x7bba87
0x7bba07 a3fc1afe00 mov    ds:0xfe1afc,eax
0x7bba0c 8900 mov    DWORD PTR [eax],eax
0x7bba0e a1fc1afe00 mov    eax,ds:0xfe1afc
0x7bba13 68081bfe00 push   0xfe1b08
0x7bba18 894004 mov    DWORD PTR [eax+0x4],eax
0x7bba1b ff15ec22bd00 call   DWORD PTR ds:0xbd22ec
0x7bba21 56 push   esi
0x7bba22 56 push   esi
0x7bba23 56 push   esi
0x7bba24 56 push   esi
0x7bba25 ff15cc20bd00 call   DWORD PTR ds:0xbd20cc
0x7bba2b a32c1bfe00 mov    ds:0xfe1b2c,eax
0x7bba30 b8e0c67b00 mov    eax,0x7bc6e0
0x7bba35 be60c07b00 mov    esi,0x7bc060
0x7bba3a bac0c27b00 mov    edx,0x7bc2c0
0x7bba3f b9d0c47b00 mov    ecx,0x7bc4d0
0x7bba44 a3d81afe00 mov    ds:0xfe1ad8,eax
0x7bba49 a3e81afe00 mov    ds:0xfe1ae8,eax
0x7bba4e 8935cc1afe00 mov    DWORD PTR ds:0xfe1acc,esi
0x7bba54 8915d01afe00 mov    DWORD PTR ds:0xfe1ad0,edx
0x7bba5a 890dd41afe00 mov    DWORD PTR ds:0xfe1ad4,ecx
0x7bba60 8935dc1afe00 mov    DWORD PTR ds:0xfe1adc,esi
0x7bba66 8915e01afe00 mov    DWORD PTR ds:0xfe1ae0,edx
0x7bba6c 890de41afe00 mov    DWORD PTR ds:0xfe1ae4,ecx
0x7bba72 b8c81afe00 mov    eax,0xfe1ac8
0x7bba77 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x7bba7a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x7bba81 59 pop    ecx
0x7bba82 5e pop    esi
0x7bba83 8be5 mov    esp,ebp
0x7bba85 5d pop    ebp
0x7bba86 c3 ret

; model_texture_enqueue | key/path copied to request type0 subtype1 state0; queue member+34
0x7bc2c0 55 push   ebp
0x7bc2c1 8bec mov    ebp,esp
0x7bc2c3 83e4f8 and    esp,0xfffffff8
0x7bc2c6 6aff push   0xffffffff
0x7bc2c8 68334e9100 push   0x914e33
0x7bc2cd 64a100000000 mov    eax,fs:0x0
0x7bc2d3 50 push   eax
0x7bc2d4 81ec90000000 sub    esp,0x90
0x7bc2da a1201fd600 mov    eax,ds:0xd61f20
0x7bc2df 33c4 xor    eax,esp
0x7bc2e1 89842488000000 mov    DWORD PTR [esp+0x88],eax
0x7bc2e8 53 push   ebx
0x7bc2e9 56 push   esi
0x7bc2ea 57 push   edi
0x7bc2eb a1201fd600 mov    eax,ds:0xd61f20
0x7bc2f0 33c4 xor    eax,esp
0x7bc2f2 50 push   eax
0x7bc2f3 8d8424a0000000 lea    eax,[esp+0xa0]
0x7bc2fa 64a300000000 mov    fs:0x0,eax
0x7bc300 8b750c mov    esi,DWORD PTR [ebp+0xc]
0x7bc303 8b7d08 mov    edi,DWORD PTR [ebp+0x8]
0x7bc306 33db xor    ebx,ebx
0x7bc308 8bc6 mov    eax,esi
0x7bc30a 894c2410 mov    DWORD PTR [esp+0x10],ecx
0x7bc30e c74424440f000000 mov    DWORD PTR [esp+0x44],0xf
0x7bc316 895c2440 mov    DWORD PTR [esp+0x40],ebx
0x7bc31a 885c2430 mov    BYTE PTR [esp+0x30],bl
0x7bc31e 8d4801 lea    ecx,[eax+0x1]
0x7bc321 8a10 mov    dl,BYTE PTR [eax]
0x7bc323 40 inc    eax
0x7bc324 3ad3 cmp    dl,bl
0x7bc326 75f9 jne    0x7bc321
0x7bc328 2bc1 sub    eax,ecx
0x7bc32a 50 push   eax
0x7bc32b 56 push   esi
0x7bc32c 8d4c2438 lea    ecx,[esp+0x38]
0x7bc330 e83b67c4ff call   0x402a70
0x7bc335 899c24a8000000 mov    DWORD PTR [esp+0xa8],ebx
0x7bc33c be0f000000 mov    esi,0xf
0x7bc341 8bc7 mov    eax,edi
0x7bc343 89742428 mov    DWORD PTR [esp+0x28],esi
0x7bc347 895c2424 mov    DWORD PTR [esp+0x24],ebx
0x7bc34b 885c2414 mov    BYTE PTR [esp+0x14],bl
0x7bc34f 8d4801 lea    ecx,[eax+0x1]
0x7bc352 8a10 mov    dl,BYTE PTR [eax]
0x7bc354 40 inc    eax
0x7bc355 3ad3 cmp    dl,bl
0x7bc357 75f9 jne    0x7bc352
0x7bc359 2bc1 sub    eax,ecx
0x7bc35b 50 push   eax
0x7bc35c 57 push   edi
0x7bc35d 8d4c241c lea    ecx,[esp+0x1c]
0x7bc361 e80a67c4ff call   0x402a70
0x7bc366 c68424a800000001 mov    BYTE PTR [esp+0xa8],0x1
0x7bc36e 6aff push   0xffffffff
0x7bc370 53 push   ebx
0x7bc371 8d44241c lea    eax,[esp+0x1c]
0x7bc375 50 push   eax
0x7bc376 8d4c2464 lea    ecx,[esp+0x64]
0x7bc37a 895c2458 mov    DWORD PTR [esp+0x58],ebx
0x7bc37e c744245c01000000 mov    DWORD PTR [esp+0x5c],0x1
0x7bc386 895c2460 mov    DWORD PTR [esp+0x60],ebx
0x7bc38a 89742478 mov    DWORD PTR [esp+0x78],esi
0x7bc38e 895c2474 mov    DWORD PTR [esp+0x74],ebx
0x7bc392 885c2464 mov    BYTE PTR [esp+0x64],bl
0x7bc396 e8a56cc4ff call   0x403040
0x7bc39b 6aff push   0xffffffff
0x7bc39d 53 push   ebx
0x7bc39e 8d4c2438 lea    ecx,[esp+0x38]
0x7bc3a2 c68424b000000002 mov    BYTE PTR [esp+0xb0],0x2
0x7bc3aa 51 push   ecx
0x7bc3ab 8d8c2480000000 lea    ecx,[esp+0x80]
0x7bc3b2 89b42494000000 mov    DWORD PTR [esp+0x94],esi
0x7bc3b9 899c2490000000 mov    DWORD PTR [esp+0x90],ebx
0x7bc3c0 889c2480000000 mov    BYTE PTR [esp+0x80],bl
0x7bc3c7 e8746cc4ff call   0x403040
0x7bc3cc 899c2490000000 mov    DWORD PTR [esp+0x90],ebx
0x7bc3d3 bf10000000 mov    edi,0x10
0x7bc3d8 397c2428 cmp    DWORD PTR [esp+0x28],edi
0x7bc3dc 720d jb     0x7bc3eb
0x7bc3de 8b542414 mov    edx,DWORD PTR [esp+0x14]
0x7bc3e2 52 push   edx
0x7bc3e3 e8244e0d00 call   0x89120c
0x7bc3e8 83c404 add    esp,0x4
0x7bc3eb 89742428 mov    DWORD PTR [esp+0x28],esi
0x7bc3ef 895c2424 mov    DWORD PTR [esp+0x24],ebx
0x7bc3f3 885c2414 mov    BYTE PTR [esp+0x14],bl
0x7bc3f7 c68424a800000005 mov    BYTE PTR [esp+0xa8],0x5
0x7bc3ff 397c2444 cmp    DWORD PTR [esp+0x44],edi
0x7bc403 720d jb     0x7bc412
0x7bc405 8b442430 mov    eax,DWORD PTR [esp+0x30]
0x7bc409 50 push   eax
0x7bc40a e8fd4d0d00 call   0x89120c
0x7bc40f 83c404 add    esp,0x4
0x7bc412 8b7c2410 mov    edi,DWORD PTR [esp+0x10]
0x7bc416 89742444 mov    DWORD PTR [esp+0x44],esi
0x7bc41a 8b7734 mov    esi,DWORD PTR [edi+0x34]
0x7bc41d 8b5604 mov    edx,DWORD PTR [esi+0x4]
0x7bc420 8d4c244c lea    ecx,[esp+0x4c]
0x7bc424 51 push   ecx
0x7bc425 52 push   edx
0x7bc426 56 push   esi
0x7bc427 895c244c mov    DWORD PTR [esp+0x4c],ebx
0x7bc42b 885c243c mov    BYTE PTR [esp+0x3c],bl
0x7bc42f e84c120000 call   0x7bd680
0x7bc434 8b4f38 mov    ecx,DWORD PTR [edi+0x38]
0x7bc437 bae2388e03 mov    edx,0x38e38e2
0x7bc43c 2bd1 sub    edx,ecx
0x7bc43e 83fa01 cmp    edx,0x1
0x7bc441 730a jae    0x7bc44d
0x7bc443 683420bf00 push   0xbf2034
0x7bc448 e8e3160c00 call   0x87db30
0x7bc44d 41 inc    ecx
0x7bc44e 894f38 mov    DWORD PTR [edi+0x38],ecx
0x7bc451 894604 mov    DWORD PTR [esi+0x4],eax
0x7bc454 8b4804 mov    ecx,DWORD PTR [eax+0x4]
0x7bc457 be10000000 mov    esi,0x10
0x7bc45c 8901 mov    DWORD PTR [ecx],eax
0x7bc45e 39b42488000000 cmp    DWORD PTR [esp+0x88],esi
0x7bc465 720d jb     0x7bc474
0x7bc467 8b542474 mov    edx,DWORD PTR [esp+0x74]
0x7bc46b 52 push   edx
0x7bc46c e89b4d0d00 call   0x89120c
0x7bc471 83c404 add    esp,0x4
0x7bc474 c78424880000000f000000 mov    DWORD PTR [esp+0x88],0xf
0x7bc47f 899c2484000000 mov    DWORD PTR [esp+0x84],ebx
0x7bc486 885c2474 mov    BYTE PTR [esp+0x74],bl
0x7bc48a 3974246c cmp    DWORD PTR [esp+0x6c],esi
0x7bc48e 720d jb     0x7bc49d
0x7bc490 8b442458 mov    eax,DWORD PTR [esp+0x58]
0x7bc494 50 push   eax
0x7bc495 e8724d0d00 call   0x89120c
0x7bc49a 83c404 add    esp,0x4
0x7bc49d b801000000 mov    eax,0x1
0x7bc4a2 8b8c24a0000000 mov    ecx,DWORD PTR [esp+0xa0]
0x7bc4a9 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x7bc4b0 59 pop    ecx
0x7bc4b1 5f pop    edi
0x7bc4b2 5e pop    esi
0x7bc4b3 5b pop    ebx
0x7bc4b4 8b8c2488000000 mov    ecx,DWORD PTR [esp+0x88]
0x7bc4bb 33cc xor    ecx,esp
0x7bc4bd e83f4b0d00 call   0x891001
0x7bc4c2 8be5 mov    esp,ebp
0x7bc4c4 5d pop    ebp
0x7bc4c5 c20800 ret    0x8

; model_texture_worker_start | normal start launches7BCA20 with same manager
0x7bbb90 55 push   ebp
0x7bbb91 8bec mov    ebp,esp
0x7bbb93 6aff push   0xffffffff
0x7bbb95 68867f9300 push   0x937f86
0x7bbb9a 64a100000000 mov    eax,fs:0x0
0x7bbba0 50 push   eax
0x7bbba1 83ec1c sub    esp,0x1c
0x7bbba4 53 push   ebx
0x7bbba5 56 push   esi
0x7bbba6 57 push   edi
0x7bbba7 a1201fd600 mov    eax,ds:0xd61f20
0x7bbbac 33c5 xor    eax,ebp
0x7bbbae 50 push   eax
0x7bbbaf 8d45f4 lea    eax,[ebp-0xc]
0x7bbbb2 64a300000000 mov    fs:0x0,eax
0x7bbbb8 f605e879fb0001 test   BYTE PTR ds:0xfb79e8,0x1
0x7bbbbf be01000000 mov    esi,0x1
0x7bbbc4 7527 jne    0x7bbbed
0x7bbbc6 0935e879fb00 or     DWORD PTR ds:0xfb79e8,esi
0x7bbbcc c745fc00000000 mov    DWORD PTR [ebp-0x4],0x0
0x7bbbd3 e808d2fdff call   0x798de0
0x7bbbd8 68e0d2bc00 push   0xbcd2e0
0x7bbbdd e838670d00 call   0x89231a
0x7bbbe2 83c404 add    esp,0x4
0x7bbbe5 83cbff or     ebx,0xffffffff
0x7bbbe8 895dfc mov    DWORD PTR [ebp-0x4],ebx
0x7bbbeb eb03 jmp    0x7bbbf0
0x7bbbed 83cbff or     ebx,0xffffffff
0x7bbbf0 68a876fb00 push   0xfb76a8
0x7bbbf5 e8f6e9fdff call   0x79a5f0
0x7bbbfa f605e879fb0001 test   BYTE PTR ds:0xfb79e8,0x1
0x7bbc01 8b7d08 mov    edi,DWORD PTR [ebp+0x8]
0x7bbc04 894758 mov    DWORD PTR [edi+0x58],eax
0x7bbc07 751e jne    0x7bbc27
0x7bbc09 0935e879fb00 or     DWORD PTR ds:0xfb79e8,esi
0x7bbc0f 8975fc mov    DWORD PTR [ebp-0x4],esi
0x7bbc12 e8c9d1fdff call   0x798de0
0x7bbc17 68e0d2bc00 push   0xbcd2e0
0x7bbc1c e8f9660d00 call   0x89231a
0x7bbc21 83c404 add    esp,0x4
0x7bbc24 895dfc mov    DWORD PTR [ebp-0x4],ebx
0x7bbc27 8b4f58 mov    ecx,DWORD PTR [edi+0x58]
0x7bbc2a a1a876fb00 mov    eax,ds:0xfb76a8
0x7bbc2f 8d775c lea    esi,[edi+0x5c]
0x7bbc32 56 push   esi
0x7bbc33 6a01 push   0x1
0x7bbc35 6a1a push   0x1a
0x7bbc37 6a00 push   0x0
0x7bbc39 6a00 push   0x0
0x7bbc3b 6800010000 push   0x100
0x7bbc40 6800010000 push   0x100
0x7bbc45 51 push   ecx
0x7bbc46 8945ec mov    DWORD PTR [ebp-0x14],eax
0x7bbc49 ff151826bd00 call   DWORD PTR ds:0xbd2618
0x7bbc4f 8b16 mov    edx,DWORD PTR [esi]
0x7bbc51 6a00 push   0x0
0x7bbc53 68004d7e00 push   0x7e4d00
0x7bbc58 52 push   edx
0x7bbc59 ff155426bd00 call   DWORD PTR ds:0xbd2654
0x7bbc5f f605e879fb0001 test   BYTE PTR ds:0xfb79e8,0x1
0x7bbc66 7523 jne    0x7bbc8b
0x7bbc68 830de879fb0001 or     DWORD PTR ds:0xfb79e8,0x1
0x7bbc6f c745fc02000000 mov    DWORD PTR [ebp-0x4],0x2
0x7bbc76 e865d1fdff call   0x798de0
0x7bbc7b 68e0d2bc00 push   0xbcd2e0
0x7bbc80 e895660d00 call   0x89231a
0x7bbc85 83c404 add    esp,0x4
0x7bbc88 895dfc mov    DWORD PTR [ebp-0x4],ebx
0x7bbc8b 68ec76fb00 push   0xfb76ec
0x7bbc90 ff154c22bd00 call   DWORD PTR ds:0xbd224c
0x7bbc96 8b4728 mov    eax,DWORD PTR [edi+0x28]
0x7bbc99 8b30 mov    esi,DWORD PTR [eax]
0x7bbc9b 3bf0 cmp    esi,eax
0x7bbc9d 0f84f5000000 je     0x7bbd98
0x7bbca3 837e2010 cmp    DWORD PTR [esi+0x20],0x10
0x7bbca7 8b4628 mov    eax,DWORD PTR [esi+0x28]
0x7bbcaa 8d7e0c lea    edi,[esi+0xc]
0x7bbcad 8945e4 mov    DWORD PTR [ebp-0x1c],eax
0x7bbcb0 c745f000000000 mov    DWORD PTR [ebp-0x10],0x0
0x7bbcb7 7204 jb     0x7bbcbd
0x7bbcb9 8b1f mov    ebx,DWORD PTR [edi]
0x7bbcbb eb02 jmp    0x7bbcbf
0x7bbcbd 8bdf mov    ebx,edi
0x7bbcbf f605e879fb0001 test   BYTE PTR ds:0xfb79e8,0x1
0x7bbcc6 7527 jne    0x7bbcef
0x7bbcc8 830de879fb0001 or     DWORD PTR ds:0xfb79e8,0x1
0x7bbccf c745fc03000000 mov    DWORD PTR [ebp-0x4],0x3
0x7bbcd6 e805d1fdff call   0x798de0
0x7bbcdb 68e0d2bc00 push   0xbcd2e0
0x7bbce0 e835660d00 call   0x89231a
0x7bbce5 83c404 add    esp,0x4
0x7bbce8 c745fcffffffff mov    DWORD PTR [ebp-0x4],0xffffffff
0x7bbcef 68a876fb00 push   0xfb76a8
0x7bbcf4 e8f7e8fdff call   0x79a5f0
0x7bbcf9 8d4df0 lea    ecx,[ebp-0x10]
0x7bbcfc 894de0 mov    DWORD PTR [ebp-0x20],ecx
0x7bbcff 8bd3 mov    edx,ebx
0x7bbd01 8d4dd8 lea    ecx,[ebp-0x28]
0x7bbd04 c745d8f855c400 mov    DWORD PTR [ebp-0x28],0xc455f8
0x7bbd0b 8945dc mov    DWORD PTR [ebp-0x24],eax
0x7bbd0e e82dc0f7ff call   0x737d40
0x7bbd13 85c0 test   eax,eax
0x7bbd15 7529 jne    0x7bbd40
0x7bbd17 837f1410 cmp    DWORD PTR [edi+0x14],0x10
0x7bbd1b 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x7bbd1e 7202 jb     0x7bbd22
0x7bbd20 8b3f mov    edi,DWORD PTR [edi]
0x7bbd22 8b4dec mov    ecx,DWORD PTR [ebp-0x14]
0x7bbd25 8b11 mov    edx,DWORD PTR [ecx]
0x7bbd27 8b5250 mov    edx,DWORD PTR [edx+0x50]
0x7bbd2a 8d45e8 lea    eax,[ebp-0x18]
0x7bbd2d 50 push   eax
0x7bbd2e 8b45f0 mov    eax,DWORD PTR [ebp-0x10]
0x7bbd31 50 push   eax
0x7bbd32 57 push   edi
0x7bbd33 ffd2 call   edx
0x7bbd35 8b45f0 mov    eax,DWORD PTR [ebp-0x10]
0x7bbd38 8b08 mov    ecx,DWORD PTR [eax]
0x7bbd3a 8b5108 mov    edx,DWORD PTR [ecx+0x8]
0x7bbd3d 50 push   eax
0x7bbd3e ffd2 call   edx
0x7bbd40 8b45e4 mov    eax,DWORD PTR [ebp-0x1c]
0x7bbd43 c7401c01000000 mov    DWORD PTR [eax+0x1c],0x1
0x7bbd4a 807e2d00 cmp    BYTE PTR [esi+0x2d],0x0
0x7bbd4e 753a jne    0x7bbd8a
0x7bbd50 8b4608 mov    eax,DWORD PTR [esi+0x8]
0x7bbd53 80782d00 cmp    BYTE PTR [eax+0x2d],0x0
0x7bbd57 7516 jne    0x7bbd6f
0x7bbd59 8bf0 mov    esi,eax
0x7bbd5b 8b06 mov    eax,DWORD PTR [esi]
0x7bbd5d 80782d00 cmp    BYTE PTR [eax+0x2d],0x0
0x7bbd61 7527 jne    0x7bbd8a
0x7bbd63 8bf0 mov    esi,eax
0x7bbd65 8b06 mov    eax,DWORD PTR [esi]
0x7bbd67 80782d00 cmp    BYTE PTR [eax+0x2d],0x0
0x7bbd6b 74f6 je     0x7bbd63
0x7bbd6d eb1b jmp    0x7bbd8a
0x7bbd6f 8b4604 mov    eax,DWORD PTR [esi+0x4]
0x7bbd72 80782d00 cmp    BYTE PTR [eax+0x2d],0x0
0x7bbd76 7510 jne    0x7bbd88
0x7bbd78 3b7008 cmp    esi,DWORD PTR [eax+0x8]
0x7bbd7b 750b jne    0x7bbd88
0x7bbd7d 8bf0 mov    esi,eax
0x7bbd7f 8b4004 mov    eax,DWORD PTR [eax+0x4]
0x7bbd82 80782d00 cmp    BYTE PTR [eax+0x2d],0x0
0x7bbd86 74f0 je     0x7bbd78
0x7bbd88 8bf0 mov    esi,eax
0x7bbd8a 8b4d08 mov    ecx,DWORD PTR [ebp+0x8]
0x7bbd8d 3b7128 cmp    esi,DWORD PTR [ecx+0x28]
0x7bbd90 0f850dffffff jne    0x7bbca3
0x7bbd96 8bf9 mov    edi,ecx
0x7bbd98 f605e879fb0001 test   BYTE PTR ds:0xfb79e8,0x1
0x7bbd9f 7520 jne    0x7bbdc1
0x7bbda1 830de879fb0001 or     DWORD PTR ds:0xfb79e8,0x1
0x7bbda8 c745fc04000000 mov    DWORD PTR [ebp-0x4],0x4
0x7bbdaf e82cd0fdff call   0x798de0
0x7bbdb4 68e0d2bc00 push   0xbcd2e0
0x7bbdb9 e85c650d00 call   0x89231a
0x7bbdbe 83c404 add    esp,0x4
0x7bbdc1 68ec76fb00 push   0xfb76ec
0x7bbdc6 ff154822bd00 call   DWORD PTR ds:0xbd2248
0x7bbdcc 6a00 push   0x0
0x7bbdce 6a00 push   0x0
0x7bbdd0 6a00 push   0x0
0x7bbdd2 6a00 push   0x0
0x7bbdd4 ff15cc20bd00 call   DWORD PTR ds:0xbd20cc
0x7bbdda 57 push   edi
0x7bbddb 6a00 push   0x0
0x7bbddd 6820ca7b00 push   0x7bca20
0x7bbde2 a36c3cd600 mov    ds:0xd63c6c,eax
0x7bbde7 c705683cd60001000000 mov    DWORD PTR ds:0xd63c68,0x1
0x7bbdf1 e8439f0d00 call   0x895d39
0x7bbdf6 83c40c add    esp,0xc
0x7bbdf9 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x7bbdfc 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x7bbe03 59 pop    ecx
0x7bbe04 5f pop    edi
0x7bbe05 5e pop    esi
0x7bbe06 5b pop    ebx
0x7bbe07 8be5 mov    esp,ebp
0x7bbe09 5d pop    ebp
0x7bbe0a c20400 ret    0x4
0x7bbe0d cc int3
0x7bbe0e cc int3
0x7bbe0f cc int3

; model_texture_init_and_start_caller | 7AAD40 checks FE1AC0 init flag, calls7BB970 if needed, then passes FE1AC8 to7BBB90
0x7aae50 f605c01afe0001 test   BYTE PTR ds:0xfe1ac0,0x1
0x7aae57 7522 jne    0x7aae7b
0x7aae59 093dc01afe00 or     DWORD PTR ds:0xfe1ac0,edi
0x7aae5f c745fc04000000 mov    DWORD PTR [ebp-0x4],0x4
0x7aae66 e8050b0100 call   0x7bb970
0x7aae6b 68c0eabc00 push   0xbceac0
0x7aae70 e8a5740e00 call   0x89231a
0x7aae75 83c404 add    esp,0x4
0x7aae78 895dfc mov    DWORD PTR [ebp-0x4],ebx
0x7aae7b 68c81afe00 push   0xfe1ac8
0x7aae80 e80b0d0100 call   0x7bbb90

; model_texture_worker | same queue+34 consumes path and calls737D40; processed flag set even after unsuccessful load; no success ACK
0x7bca20 55 push   ebp
0x7bca21 8bec mov    ebp,esp
0x7bca23 83e4f8 and    esp,0xfffffff8
0x7bca26 6aff push   0xffffffff
0x7bca28 68157f9300 push   0x937f15
0x7bca2d 64a100000000 mov    eax,fs:0x0
0x7bca33 50 push   eax
0x7bca34 83ec58 sub    esp,0x58
0x7bca37 a1201fd600 mov    eax,ds:0xd61f20
0x7bca3c 33c4 xor    eax,esp
0x7bca3e 89442450 mov    DWORD PTR [esp+0x50],eax
0x7bca42 53 push   ebx
0x7bca43 56 push   esi
0x7bca44 57 push   edi
0x7bca45 a1201fd600 mov    eax,ds:0xd61f20
0x7bca4a 33c4 xor    eax,esp
0x7bca4c 50 push   eax
0x7bca4d 8d442468 lea    eax,[esp+0x68]
0x7bca51 64a300000000 mov    fs:0x0,eax
0x7bca57 8b7d08 mov    edi,DWORD PTR [ebp+0x8]
0x7bca5a 33db xor    ebx,ebx
0x7bca5c 897c2410 mov    DWORD PTR [esp+0x10],edi
0x7bca60 391d683cd600 cmp    DWORD PTR ds:0xd63c68,ebx
0x7bca66 0f8492000000 je     0x7bcafe
0x7bca6c 8d7740 lea    esi,[edi+0x40]
0x7bca6f 90 nop
0x7bca70 f605e879fb0001 test   BYTE PTR ds:0xfb79e8,0x1
0x7bca77 7557 jne    0x7bcad0
0x7bca79 830de879fb0001 or     DWORD PTR ds:0xfb79e8,0x1
0x7bca80 895c2470 mov    DWORD PTR [esp+0x70],ebx
0x7bca84 e857c3fdff call   0x798de0
0x7bca89 68e0d2bc00 push   0xbcd2e0
0x7bca8e e887580d00 call   0x89231a
0x7bca93 83c404 add    esp,0x4
0x7bca96 c7442470ffffffff mov    DWORD PTR [esp+0x70],0xffffffff
0x7bca9e f605e879fb0001 test   BYTE PTR ds:0xfb79e8,0x1
0x7bcaa5 7529 jne    0x7bcad0
0x7bcaa7 b801000000 mov    eax,0x1
0x7bcaac 0905e879fb00 or     DWORD PTR ds:0xfb79e8,eax
0x7bcab2 89442470 mov    DWORD PTR [esp+0x70],eax
0x7bcab6 e825c3fdff call   0x798de0
0x7bcabb 68e0d2bc00 push   0xbcd2e0
0x7bcac0 e855580d00 call   0x89231a
0x7bcac5 83c404 add    esp,0x4
0x7bcac8 c7442470ffffffff mov    DWORD PTR [esp+0x70],0xffffffff
0x7bcad0 56 push   esi
0x7bcad1 ff154c22bd00 call   DWORD PTR ds:0xbd224c
0x7bcad7 395f38 cmp    DWORD PTR [edi+0x38],ebx
0x7bcada 7552 jne    0x7bcb2e
0x7bcadc 56 push   esi
0x7bcadd ff154822bd00 call   DWORD PTR ds:0xbd2248
0x7bcae3 8b4f64 mov    ecx,DWORD PTR [edi+0x64]
0x7bcae6 6810270000 push   0x2710
0x7bcaeb 51 push   ecx
0x7bcaec ff15fc20bd00 call   DWORD PTR ds:0xbd20fc
0x7bcaf2 391d683cd600 cmp    DWORD PTR ds:0xd63c68,ebx
0x7bcaf8 0f8572ffffff jne    0x7bca70
0x7bcafe 8b156c3cd600 mov    edx,DWORD PTR ds:0xd63c6c
0x7bcb04 52 push   edx
0x7bcb05 ff15d020bd00 call   DWORD PTR ds:0xbd20d0
0x7bcb0b e862910d00 call   0x895c72
0x7bcb10 8b4c2468 mov    ecx,DWORD PTR [esp+0x68]
0x7bcb14 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x7bcb1b 59 pop    ecx
0x7bcb1c 5f pop    edi
0x7bcb1d 5e pop    esi
0x7bcb1e 5b pop    ebx
0x7bcb1f 8b4c2450 mov    ecx,DWORD PTR [esp+0x50]
0x7bcb23 33cc xor    ecx,esp
0x7bcb25 e8d7440d00 call   0x891001
0x7bcb2a 8be5 mov    esp,ebp
0x7bcb2c 5d pop    ebp
0x7bcb2d c3 ret
0x7bcb2e 8b4734 mov    eax,DWORD PTR [edi+0x34]
0x7bcb31 8b30 mov    esi,DWORD PTR [eax]
0x7bcb33 8944241c mov    DWORD PTR [esp+0x1c],eax
0x7bcb37 895c2414 mov    DWORD PTR [esp+0x14],ebx
0x7bcb3b 3bf0 cmp    esi,eax
0x7bcb3d 7471 je     0x7bcbb0
0x7bcb3f eb02 jmp    0x7bcb43
0x7bcb41 33db xor    ebx,ebx
0x7bcb43 8b4610 mov    eax,DWORD PTR [esi+0x10]
0x7bcb46 b901000000 mov    ecx,0x1
0x7bcb4b 394e08 cmp    DWORD PTR [esi+0x8],ecx
0x7bcb4e 757f jne    0x7bcbcf
0x7bcb50 2bc3 sub    eax,ebx
0x7bcb52 742b je     0x7bcb7f
0x7bcb54 83e802 sub    eax,0x2
0x7bcb57 7547 jne    0x7bcba0
0x7bcb59 8b460c mov    eax,DWORD PTR [esi+0xc]
0x7bcb5c 83f803 cmp    eax,0x3
0x7bcb5f 7509 jne    0x7bcb6a
0x7bcb61 c7460c02000000 mov    DWORD PTR [esi+0xc],0x2
0x7bcb68 eb15 jmp    0x7bcb7f
0x7bcb6a 83f802 cmp    eax,0x2
0x7bcb6d 7505 jne    0x7bcb74
0x7bcb6f 894e0c mov    DWORD PTR [esi+0xc],ecx
0x7bcb72 eb0b jmp    0x7bcb7f
0x7bcb74 3bc1 cmp    eax,ecx
0x7bcb76 0f855b030000 jne    0x7bced7
0x7bcb7c 895e0c mov    DWORD PTR [esi+0xc],ebx
0x7bcb7f 837e2810 cmp    DWORD PTR [esi+0x28],0x10
0x7bcb83 8d4614 lea    eax,[esi+0x14]
0x7bcb86 7202 jb     0x7bcb8a
0x7bcb88 8b00 mov    eax,DWORD PTR [eax]
0x7bcb8a 8bc8 mov    ecx,eax
0x7bcb8c e8df060000 call   0x7bd270
0x7bcb91 85c0 test   eax,eax
0x7bcb93 7532 jne    0x7bcbc7
0x7bcb95 c7461002000000 mov    DWORD PTR [esi+0x10],0x2
0x7bcb9c 8b7c2410 mov    edi,DWORD PTR [esp+0x10]
0x7bcba0 8b36 mov    esi,DWORD PTR [esi]
0x7bcba2 3b74241c cmp    esi,DWORD PTR [esp+0x1c]
0x7bcba6 7599 jne    0x7bcb41
0x7bcba8 57 push   edi
0x7bcba9 e892070000 call   0x7bd340
0x7bcbae 33db xor    ebx,ebx
0x7bcbb0 8d7740 lea    esi,[edi+0x40]
0x7bcbb3 56 push   esi
0x7bcbb4 ff154822bd00 call   DWORD PTR ds:0xbd2248
0x7bcbba 6a14 push   0x14
0x7bcbbc ff150423bd00 call   DWORD PTR ds:0xbd2304
0x7bcbc2 e92bffffff jmp    0x7bcaf2
0x7bcbc7 ff4824 dec    DWORD PTR [eax+0x24]
0x7bcbca e908030000 jmp    0x7bced7
0x7bcbcf 2bc3 sub    eax,ebx
0x7bcbd1 7424 je     0x7bcbf7
0x7bcbd3 2bc1 sub    eax,ecx
0x7bcbd5 75c9 jne    0x7bcba0
0x7bcbd7 837e2810 cmp    DWORD PTR [esi+0x28],0x10
0x7bcbdb 8d4e14 lea    ecx,[esi+0x14]
0x7bcbde 7202 jb     0x7bcbe2
0x7bcbe0 8b09 mov    ecx,DWORD PTR [ecx]
0x7bcbe2 e889060000 call   0x7bd270
0x7bcbe7 89464c mov    DWORD PTR [esi+0x4c],eax
0x7bcbea 85c0 test   eax,eax
0x7bcbec 0f84e5020000 je     0x7bced7
0x7bcbf2 e93c010000 jmp    0x7bcd33
0x7bcbf7 8d4614 lea    eax,[esi+0x14]
0x7bcbfa bb10000000 mov    ebx,0x10
0x7bcbff 395814 cmp    DWORD PTR [eax+0x14],ebx
0x7bcc02 7202 jb     0x7bcc06
0x7bcc04 8b00 mov    eax,DWORD PTR [eax]
0x7bcc06 8bc8 mov    ecx,eax
0x7bcc08 e863060000 call   0x7bd270
0x7bcc0d 89464c mov    DWORD PTR [esi+0x4c],eax
0x7bcc10 85c0 test   eax,eax
0x7bcc12 0f850d010000 jne    0x7bcd25
0x7bcc18 6a28 push   0x28
0x7bcc1a e849460d00 call   0x891268
0x7bcc1f 8bf8 mov    edi,eax
0x7bcc21 83c404 add    esp,0x4
0x7bcc24 897c2434 mov    DWORD PTR [esp+0x34],edi
0x7bcc28 c744247002000000 mov    DWORD PTR [esp+0x70],0x2
0x7bcc30 85ff test   edi,edi
0x7bcc32 744f je     0x7bcc83
0x7bcc34 395e44 cmp    DWORD PTR [esi+0x44],ebx
0x7bcc37 8d4e30 lea    ecx,[esi+0x30]
0x7bcc3a 7202 jb     0x7bcc3e
0x7bcc3c 8b09 mov    ecx,DWORD PTR [ecx]
0x7bcc3e 8b5e0c mov    ebx,DWORD PTR [esi+0xc]
0x7bcc41 8bc1 mov    eax,ecx
0x7bcc43 8d5001 lea    edx,[eax+0x1]
0x7bcc46 c747140f000000 mov    DWORD PTR [edi+0x14],0xf
0x7bcc4d c7471000000000 mov    DWORD PTR [edi+0x10],0x0
0x7bcc54 c60700 mov    BYTE PTR [edi],0x0
0x7bcc57 89542420 mov    DWORD PTR [esp+0x20],edx
0x7bcc5b eb03 jmp    0x7bcc60
0x7bcc5d 8d4900 lea    ecx,[ecx+0x0]
0x7bcc60 8a10 mov    dl,BYTE PTR [eax]
0x7bcc62 40 inc    eax
0x7bcc63 84d2 test   dl,dl
0x7bcc65 75f9 jne    0x7bcc60
0x7bcc67 2b442420 sub    eax,DWORD PTR [esp+0x20]
0x7bcc6b 50 push   eax
0x7bcc6c 51 push   ecx
0x7bcc6d 8bcf mov    ecx,edi
0x7bcc6f e8fc5dc4ff call   0x402a70
0x7bcc74 33c0 xor    eax,eax
0x7bcc76 895f20 mov    DWORD PTR [edi+0x20],ebx
0x7bcc79 89471c mov    DWORD PTR [edi+0x1c],eax
0x7bcc7c 894724 mov    DWORD PTR [edi+0x24],eax
0x7bcc7f 8bdf mov    ebx,edi
0x7bcc81 eb02 jmp    0x7bcc85
0x7bcc83 33db xor    ebx,ebx
0x7bcc85 8d4e14 lea    ecx,[esi+0x14]
0x7bcc88 c7442470ffffffff mov    DWORD PTR [esp+0x70],0xffffffff
0x7bcc90 83791410 cmp    DWORD PTR [ecx+0x14],0x10
0x7bcc94 7202 jb     0x7bcc98
0x7bcc96 8b09 mov    ecx,DWORD PTR [ecx]
0x7bcc98 8bc1 mov    eax,ecx
0x7bcc9a c74424540f000000 mov    DWORD PTR [esp+0x54],0xf
0x7bcca2 c744245000000000 mov    DWORD PTR [esp+0x50],0x0
0x7bccaa c644244000 mov    BYTE PTR [esp+0x40],0x0
0x7bccaf 8d7801 lea    edi,[eax+0x1]
0x7bccb2 8a10 mov    dl,BYTE PTR [eax]
0x7bccb4 40 inc    eax
0x7bccb5 84d2 test   dl,dl
0x7bccb7 75f9 jne    0x7bccb2
0x7bccb9 2bc7 sub    eax,edi
0x7bccbb 50 push   eax
0x7bccbc 51 push   ecx
0x7bccbd 8d4c2448 lea    ecx,[esp+0x48]
0x7bccc1 e8aa5dc4ff call   0x402a70
0x7bccc6 895c245c mov    DWORD PTR [esp+0x5c],ebx
0x7bccca 8b7c2410 mov    edi,DWORD PTR [esp+0x10]
0x7bccce 8d442440 lea    eax,[esp+0x40]
0x7bccd2 83c724 add    edi,0x24
0x7bccd5 50 push   eax
0x7bccd6 8bcf mov    ecx,edi
0x7bccd8 c744247403000000 mov    DWORD PTR [esp+0x74],0x3
0x7bcce0 e8fb60d9ff call   0x552de0
0x7bcce5 50 push   eax
0x7bcce6 8d4c243c lea    ecx,[esp+0x3c]
0x7bccea 51 push   ecx
0x7bcceb 57 push   edi
0x7bccec e81f5c0200 call   0x7e2910
0x7bccf1 c7442470ffffffff mov    DWORD PTR [esp+0x70],0xffffffff
0x7bccf9 837c245410 cmp    DWORD PTR [esp+0x54],0x10
0x7bccfe 720d jb     0x7bcd0d
0x7bcd00 8b542440 mov    edx,DWORD PTR [esp+0x40]
0x7bcd04 52 push   edx
0x7bcd05 e802450d00 call   0x89120c
0x7bcd0a 83c404 add    esp,0x4
0x7bcd0d c74424540f000000 mov    DWORD PTR [esp+0x54],0xf
0x7bcd15 c744245000000000 mov    DWORD PTR [esp+0x50],0x0
0x7bcd1d c644244000 mov    BYTE PTR [esp+0x40],0x0
0x7bcd22 895e4c mov    DWORD PTR [esi+0x4c],ebx
0x7bcd25 8b464c mov    eax,DWORD PTR [esi+0x4c]
0x7bcd28 b901000000 mov    ecx,0x1
0x7bcd2d 014824 add    DWORD PTR [eax+0x24],ecx
0x7bcd30 894e10 mov    DWORD PTR [esi+0x10],ecx
0x7bcd33 837c241404 cmp    DWORD PTR [esp+0x14],0x4
0x7bcd38 0f835efeffff jae    0x7bcb9c
0x7bcd3e 8b4e4c mov    ecx,DWORD PTR [esi+0x4c]
0x7bcd41 33c0 xor    eax,eax
0x7bcd43 39411c cmp    DWORD PTR [ecx+0x1c],eax
0x7bcd46 0f858b010000 jne    0x7bced7
0x7bcd4c b901000000 mov    ecx,0x1
0x7bcd51 014c2414 add    DWORD PTR [esp+0x14],ecx
0x7bcd55 837e4410 cmp    DWORD PTR [esi+0x44],0x10
0x7bcd59 89442424 mov    DWORD PTR [esp+0x24],eax
0x7bcd5d 89442418 mov    DWORD PTR [esp+0x18],eax
0x7bcd61 7205 jb     0x7bcd68
0x7bcd63 8b7e30 mov    edi,DWORD PTR [esi+0x30]
0x7bcd66 eb03 jmp    0x7bcd6b
0x7bcd68 8d7e30 lea    edi,[esi+0x30]
0x7bcd6b 840de879fb00 test   BYTE PTR ds:0xfb79e8,cl
0x7bcd71 7529 jne    0x7bcd9c
0x7bcd73 090de879fb00 or     DWORD PTR ds:0xfb79e8,ecx
0x7bcd79 c744247004000000 mov    DWORD PTR [esp+0x70],0x4
0x7bcd81 e85ac0fdff call   0x798de0
0x7bcd86 68e0d2bc00 push   0xbcd2e0
0x7bcd8b e88a550d00 call   0x89231a
0x7bcd90 83c404 add    esp,0x4
0x7bcd93 83cbff or     ebx,0xffffffff
0x7bcd96 895c2470 mov    DWORD PTR [esp+0x70],ebx
0x7bcd9a eb03 jmp    0x7bcd9f
0x7bcd9c 83cbff or     ebx,0xffffffff
0x7bcd9f 68a876fb00 push   0xfb76a8
0x7bcda4 e847d8fdff call   0x79a5f0
0x7bcda9 8d542418 lea    edx,[esp+0x18]
0x7bcdad 89542430 mov    DWORD PTR [esp+0x30],edx
0x7bcdb1 8bd7 mov    edx,edi
0x7bcdb3 8d4c2428 lea    ecx,[esp+0x28]
0x7bcdb7 c7442428f855c400 mov    DWORD PTR [esp+0x28],0xc455f8
0x7bcdbf 8944242c mov    DWORD PTR [esp+0x2c],eax
0x7bcdc3 e878aff7ff call   0x737d40
0x7bcdc8 85c0 test   eax,eax
0x7bcdca 0f85fd000000 jne    0x7bcecd
0x7bcdd0 f605e879fb0001 test   BYTE PTR ds:0xfb79e8,0x1
0x7bcdd7 8d7801 lea    edi,[eax+0x1]
0x7bcdda 7524 jne    0x7bce00
0x7bcddc 093de879fb00 or     DWORD PTR ds:0xfb79e8,edi
0x7bcde2 c744247005000000 mov    DWORD PTR [esp+0x70],0x5
0x7bcdea e8f1bffdff call   0x798de0
0x7bcdef 68e0d2bc00 push   0xbcd2e0
0x7bcdf4 e821550d00 call   0x89231a
0x7bcdf9 83c404 add    esp,0x4
0x7bcdfc 895c2470 mov    DWORD PTR [esp+0x70],ebx
0x7bce00 68ec76fb00 push   0xfb76ec
0x7bce05 ff154c22bd00 call   DWORD PTR ds:0xbd224c
0x7bce0b f605e879fb0001 test   BYTE PTR ds:0xfb79e8,0x1
0x7bce12 7551 jne    0x7bce65
0x7bce14 093de879fb00 or     DWORD PTR ds:0xfb79e8,edi
0x7bce1a c744247006000000 mov    DWORD PTR [esp+0x70],0x6
0x7bce22 e8b9bffdff call   0x798de0
0x7bce27 68e0d2bc00 push   0xbcd2e0
0x7bce2c e8e9540d00 call   0x89231a
0x7bce31 83c404 add    esp,0x4
0x7bce34 895c2470 mov    DWORD PTR [esp+0x70],ebx
0x7bce38 f605e879fb0001 test   BYTE PTR ds:0xfb79e8,0x1
0x7bce3f 7524 jne    0x7bce65
0x7bce41 093de879fb00 or     DWORD PTR ds:0xfb79e8,edi
0x7bce47 c744247007000000 mov    DWORD PTR [esp+0x70],0x7
0x7bce4f e88cbffdff call   0x798de0
0x7bce54 68e0d2bc00 push   0xbcd2e0
0x7bce59 e8bc540d00 call   0x89231a
0x7bce5e 83c404 add    esp,0x4
0x7bce61 895c2470 mov    DWORD PTR [esp+0x70],ebx
0x7bce65 837e2810 cmp    DWORD PTR [esi+0x28],0x10
0x7bce69 8b0da876fb00 mov    ecx,DWORD PTR ds:0xfb76a8
0x7bce6f 8d4614 lea    eax,[esi+0x14]
0x7bce72 7202 jb     0x7bce76
0x7bce74 8b00 mov    eax,DWORD PTR [eax]
0x7bce76 8b11 mov    edx,DWORD PTR [ecx]
0x7bce78 8d7c2424 lea    edi,[esp+0x24]
0x7bce7c 57 push   edi
0x7bce7d 8b7c241c mov    edi,DWORD PTR [esp+0x1c]
0x7bce81 57 push   edi
0x7bce82 50 push   eax
0x7bce83 8b4250 mov    eax,DWORD PTR [edx+0x50]
0x7bce86 ffd0 call   eax
0x7bce88 8b442418 mov    eax,DWORD PTR [esp+0x18]
0x7bce8c 8b08 mov    ecx,DWORD PTR [eax]
0x7bce8e 8b5108 mov    edx,DWORD PTR [ecx+0x8]
0x7bce91 50 push   eax
0x7bce92 ffd2 call   edx
0x7bce94 f605e879fb0001 test   BYTE PTR ds:0xfb79e8,0x1
0x7bce9b 7525 jne    0x7bcec2
0x7bce9d 830de879fb0001 or     DWORD PTR ds:0xfb79e8,0x1
0x7bcea4 c744247008000000 mov    DWORD PTR [esp+0x70],0x8
0x7bceac e82fbffdff call   0x798de0
0x7bceb1 68e0d2bc00 push   0xbcd2e0
0x7bceb6 e85f540d00 call   0x89231a
0x7bcebb 83c404 add    esp,0x4
0x7bcebe 895c2470 mov    DWORD PTR [esp+0x70],ebx
0x7bcec2 68ec76fb00 push   0xfb76ec
0x7bcec7 ff154822bd00 call   DWORD PTR ds:0xbd2248
0x7bcecd 8b464c mov    eax,DWORD PTR [esi+0x4c]
0x7bced0 c7401c01000000 mov    DWORD PTR [eax+0x1c],0x1
0x7bced7 8b5c2410 mov    ebx,DWORD PTR [esp+0x10]
0x7bcedb 8b3e mov    edi,DWORD PTR [esi]
0x7bcedd 3b7334 cmp    esi,DWORD PTR [ebx+0x34]
0x7bcee0 7461 je     0x7bcf43
0x7bcee2 8b4e04 mov    ecx,DWORD PTR [esi+0x4]
0x7bcee5 8939 mov    DWORD PTR [ecx],edi
0x7bcee7 8b16 mov    edx,DWORD PTR [esi]
0x7bcee9 8b4604 mov    eax,DWORD PTR [esi+0x4]
0x7bceec 894204 mov    DWORD PTR [edx+0x4],eax
0x7bceef 837e4410 cmp    DWORD PTR [esi+0x44],0x10
0x7bcef3 720c jb     0x7bcf01
0x7bcef5 8b4e30 mov    ecx,DWORD PTR [esi+0x30]
0x7bcef8 51 push   ecx
0x7bcef9 e80e430d00 call   0x89120c
0x7bcefe 83c404 add    esp,0x4
0x7bcf01 c746440f000000 mov    DWORD PTR [esi+0x44],0xf
0x7bcf08 c7464000000000 mov    DWORD PTR [esi+0x40],0x0
0x7bcf0f c6463000 mov    BYTE PTR [esi+0x30],0x0
0x7bcf13 837e2810 cmp    DWORD PTR [esi+0x28],0x10
0x7bcf17 720c jb     0x7bcf25
0x7bcf19 8b5614 mov    edx,DWORD PTR [esi+0x14]
0x7bcf1c 52 push   edx
0x7bcf1d e8ea420d00 call   0x89120c
0x7bcf22 83c404 add    esp,0x4
0x7bcf25 c746280f000000 mov    DWORD PTR [esi+0x28],0xf
0x7bcf2c c7462400000000 mov    DWORD PTR [esi+0x24],0x0
0x7bcf33 56 push   esi
0x7bcf34 c6461400 mov    BYTE PTR [esi+0x14],0x0
0x7bcf38 e8cf420d00 call   0x89120c
0x7bcf3d 83c404 add    esp,0x4
0x7bcf40 ff4b38 dec    DWORD PTR [ebx+0x38]
0x7bcf43 8b4334 mov    eax,DWORD PTR [ebx+0x34]
0x7bcf46 8bf7 mov    esi,edi
0x7bcf48 8944241c mov    DWORD PTR [esp+0x1c],eax
0x7bcf4c 8bfb mov    edi,ebx
0x7bcf4e e94ffcffff jmp    0x7bcba2
0x7bcf53 cc int3
0x7bcf54 cc int3
0x7bcf55 cc int3
0x7bcf56 cc int3
0x7bcf57 cc int3
0x7bcf58 cc int3
0x7bcf59 cc int3
0x7bcf5a cc int3
0x7bcf5b cc int3
0x7bcf5c cc int3
0x7bcf5d cc int3
0x7bcf5e cc int3
0x7bcf5f cc int3

; model_texture_memory_adapter | C455F8+4; adapter device/output fields and input buffer/length -> IAT BD2624 texture creation
0x737f00 55 push   ebp
0x737f01 8bec mov    ebp,esp
0x737f03 8b4108 mov    eax,DWORD PTR [ecx+0x8]
0x737f06 50 push   eax
0x737f07 a124a8fb00 mov    eax,ds:0xfba824
0x737f0c 6a00 push   0x0
0x737f0e 8b550c mov    edx,DWORD PTR [ebp+0xc]
0x737f11 6a00 push   0x0
0x737f13 8b4904 mov    ecx,DWORD PTR [ecx+0x4]
0x737f16 6a00 push   0x0
0x737f18 6aff push   0xffffffff
0x737f1a 6aff push   0xffffffff
0x737f1c 6a01 push   0x1
0x737f1e 6a00 push   0x0
0x737f20 6a00 push   0x0
0x737f22 50 push   eax
0x737f23 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x737f26 6aff push   0xffffffff
0x737f28 6aff push   0xffffffff
0x737f2a 52 push   edx
0x737f2b 50 push   eax
0x737f2c 51 push   ecx
0x737f2d ff152426bd00 call   DWORD PTR ds:0xbd2624
0x737f33 5d pop    ebp
0x737f34 c20800 ret    0x8

; image_texture_memory_adapter | C45604+4; adapter fields and input buffer/length -> IAT BD2624 texture creation
0x738000 55 push   ebp
0x738001 8bec mov    ebp,esp
0x738003 8b4134 mov    eax,DWORD PTR [ecx+0x34]
0x738006 8b5130 mov    edx,DWORD PTR [ecx+0x30]
0x738009 50 push   eax
0x73800a 8b412c mov    eax,DWORD PTR [ecx+0x2c]
0x73800d 52 push   edx
0x73800e 8b5128 mov    edx,DWORD PTR [ecx+0x28]
0x738011 50 push   eax
0x738012 8b4124 mov    eax,DWORD PTR [ecx+0x24]
0x738015 52 push   edx
0x738016 8b5120 mov    edx,DWORD PTR [ecx+0x20]
0x738019 50 push   eax
0x73801a 8b411c mov    eax,DWORD PTR [ecx+0x1c]
0x73801d 52 push   edx
0x73801e 8b5118 mov    edx,DWORD PTR [ecx+0x18]
0x738021 50 push   eax
0x738022 8b4114 mov    eax,DWORD PTR [ecx+0x14]
0x738025 52 push   edx
0x738026 8b5110 mov    edx,DWORD PTR [ecx+0x10]
0x738029 50 push   eax
0x73802a 8b410c mov    eax,DWORD PTR [ecx+0xc]
0x73802d 52 push   edx
0x73802e 8b5108 mov    edx,DWORD PTR [ecx+0x8]
0x738031 50 push   eax
0x738032 8b450c mov    eax,DWORD PTR [ebp+0xc]
0x738035 52 push   edx
0x738036 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x738039 50 push   eax
0x73803a 8b4104 mov    eax,DWORD PTR [ecx+0x4]
0x73803d 52 push   edx
0x73803e 50 push   eax
0x73803f ff152426bd00 call   DWORD PTR ds:0xbd2624
0x738045 5d pop    ebp
0x738046 c20800 ret    0x8

; image_info_memory_adapter | C45610+4; input buffer/length/output image-info -> IAT BD2628 image information
0x738070 55 push   ebp
0x738071 8bec mov    ebp,esp
0x738073 8b4104 mov    eax,DWORD PTR [ecx+0x4]
0x738076 8b4d0c mov    ecx,DWORD PTR [ebp+0xc]
0x738079 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x73807c 50 push   eax
0x73807d 51 push   ecx
0x73807e 52 push   edx
0x73807f ff152826bd00 call   DWORD PTR ds:0xbd2628
0x738085 5d pop    ebp
0x738086 c20800 ret    0x8
