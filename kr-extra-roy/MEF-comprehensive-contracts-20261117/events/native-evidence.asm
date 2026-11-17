; get_time [0x4a0b70,0x4a0b76)
0x4a0b70 ff25a025bd00 jmp    DWORD PTR ds:0xbd25a0

; synopsis_skipped [0x4a9320,0x4a9326)
0x4a9320 a1a0a7fb00 mov    eax,ds:0xfba7a0
0x4a9325 c3 ret

; tutorial_q_running [0x4a97b0,0x4a9812)
0x4a97b0 55 push   ebp
0x4a97b1 8bec mov    ebp,esp
0x4a97b3 6aff push   0xffffffff
0x4a97b5 68aeb29300 push   0x93b2ae
0x4a97ba 64a100000000 mov    eax,fs:0x0
0x4a97c0 50 push   eax
0x4a97c1 a1201fd600 mov    eax,ds:0xd61f20
0x4a97c6 33c5 xor    eax,ebp
0x4a97c8 50 push   eax
0x4a97c9 8d45f4 lea    eax,[ebp-0xc]
0x4a97cc 64a300000000 mov    fs:0x0,eax
0x4a97d2 b801000000 mov    eax,0x1
0x4a97d7 8405b873fb00 test   BYTE PTR ds:0xfb73b8,al
0x4a97dd 751f jne    0x4a97fe
0x4a97df 0905b873fb00 or     DWORD PTR ds:0xfb73b8,eax
0x4a97e5 c745fc00000000 mov    DWORD PTR [ebp-0x4],0x0
0x4a97ec e87f690b00 call   0x560170
0x4a97f1 6810d1bc00 push   0xbcd110
0x4a97f6 e81f8b3e00 call   0x89231a
0x4a97fb 83c404 add    esp,0x4
0x4a97fe a1e873fb00 mov    eax,ds:0xfb73e8
0x4a9803 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4a9806 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4a980d 59 pop    ecx
0x4a980e 8be5 mov    esp,ebp
0x4a9810 5d pop    ebp
0x4a9811 c3 ret

; character_available_fixed [0x4a9f00,0x4a9f86)
0x4a9f00 55 push   ebp
0x4a9f01 8bec mov    ebp,esp
0x4a9f03 83e4f8 and    esp,0xfffffff8
0x4a9f06 6aff push   0xffffffff
0x4a9f08 680ef89300 push   0x93f80e
0x4a9f0d 64a100000000 mov    eax,fs:0x0
0x4a9f13 50 push   eax
0x4a9f14 51 push   ecx
0x4a9f15 a1201fd600 mov    eax,ds:0xd61f20
0x4a9f1a 33c4 xor    eax,esp
0x4a9f1c 50 push   eax
0x4a9f1d 8d442408 lea    eax,[esp+0x8]
0x4a9f21 64a300000000 mov    fs:0x0,eax
0x4a9f27 b801000000 mov    eax,0x1
0x4a9f2c 84059043f900 test   BYTE PTR ds:0xf94390,al
0x4a9f32 7520 jne    0x4a9f54
0x4a9f34 09059043f900 or     DWORD PTR ds:0xf94390,eax
0x4a9f3a c744241000000000 mov    DWORD PTR [esp+0x10],0x0
0x4a9f42 e849760300 call   0x4e1590
0x4a9f47 6880ccbc00 push   0xbccc80
0x4a9f4c e8c9833e00 call   0x89231a
0x4a9f51 83c404 add    esp,0x4
0x4a9f54 a10443f900 mov    eax,ds:0xf94304
0x4a9f59 83b87c04000000 cmp    DWORD PTR [eax+0x47c],0x0
0x4a9f60 7504 jne    0x4a9f66
0x4a9f62 33c0 xor    eax,eax
0x4a9f64 eb05 jmp    0x4a9f6b
0x4a9f66 0520040000 add    eax,0x420
0x4a9f6b 33c9 xor    ecx,ecx
0x4a9f6d 85c0 test   eax,eax
0x4a9f6f 0f95c1 setne  cl
0x4a9f72 8bc1 mov    eax,ecx
0x4a9f74 8b4c2408 mov    ecx,DWORD PTR [esp+0x8]
0x4a9f78 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4a9f7f 59 pop    ecx
0x4a9f80 8be5 mov    esp,ebp
0x4a9f82 5d pop    ebp
0x4a9f83 c20400 ret    0x4

; control_progress [0x4a9fb0,0x4a9fc7)
0x4a9fb0 55 push   ebp
0x4a9fb1 8bec mov    ebp,esp
0x4a9fb3 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4a9fb6 8b0da4a7fb00 mov    ecx,DWORD PTR ds:0xfba7a4
0x4a9fbc 8b8481b4000000 mov    eax,DWORD PTR [ecx+eax*4+0xb4]
0x4a9fc3 5d pop    ebp
0x4a9fc4 c20400 ret    0x4

; tutorial_state [0x4a9fd0,0x4a9fdc)
0x4a9fd0 a1a4a7fb00 mov    eax,ds:0xfba7a4
0x4a9fd5 8b8034010000 mov    eax,DWORD PTR [eax+0x134]
0x4a9fdb c3 ret

; isilia_fixed_visibility [0x4aa240,0x4aa49a)
0x4aa240 55 push   ebp
0x4aa241 8bec mov    ebp,esp
0x4aa243 83e4f8 and    esp,0xfffffff8
0x4aa246 6aff push   0xffffffff
0x4aa248 68ca6e9300 push   0x936eca
0x4aa24d 64a100000000 mov    eax,fs:0x0
0x4aa253 50 push   eax
0x4aa254 83ec4c sub    esp,0x4c
0x4aa257 56 push   esi
0x4aa258 57 push   edi
0x4aa259 a1201fd600 mov    eax,ds:0xd61f20
0x4aa25e 33c4 xor    eax,esp
0x4aa260 50 push   eax
0x4aa261 8d442458 lea    eax,[esp+0x58]
0x4aa265 64a300000000 mov    fs:0x0,eax
0x4aa26b 33c0 xor    eax,eax
0x4aa26d 83cfff or     edi,0xffffffff
0x4aa270 f6052cb2fa0001 test   BYTE PTR ds:0xfab22c,0x1
0x4aa277 668944240c mov    WORD PTR [esp+0xc],ax
0x4aa27c 66c744240c00f0 mov    WORD PTR [esp+0xc],0xf000
0x4aa283 7521 jne    0x4aa2a6
0x4aa285 830d2cb2fa0001 or     DWORD PTR ds:0xfab22c,0x1
0x4aa28c 89442460 mov    DWORD PTR [esp+0x60],eax
0x4aa290 e8fb490300 call   0x4dec90
0x4aa295 6830cebc00 push   0xbcce30
0x4aa29a e87b803e00 call   0x89231a
0x4aa29f 83c404 add    esp,0x4
0x4aa2a2 897c2460 mov    DWORD PTR [esp+0x60],edi
0x4aa2a6 0fb74c240c movzx  ecx,WORD PTR [esp+0xc]
0x4aa2ab 8d54240c lea    edx,[esp+0xc]
0x4aa2af 894c240c mov    DWORD PTR [esp+0xc],ecx
0x4aa2b3 52 push   edx
0x4aa2b4 8d442414 lea    eax,[esp+0x14]
0x4aa2b8 b938b1fa00 mov    ecx,0xfab138
0x4aa2bd e83e4c3800 call   0x82ef00
0x4aa2c2 8b442410 mov    eax,DWORD PTR [esp+0x10]
0x4aa2c6 3b053cb1fa00 cmp    eax,DWORD PTR ds:0xfab13c
0x4aa2cc 0f84b4010000 je     0x4aa486
0x4aa2d2 8b4810 mov    ecx,DWORD PTR [eax+0x10]
0x4aa2d5 85c9 test   ecx,ecx
0x4aa2d7 0f84a9010000 je     0x4aa486
0x4aa2dd 8b01 mov    eax,DWORD PTR [ecx]
0x4aa2df 8b504c mov    edx,DWORD PTR [eax+0x4c]
0x4aa2e2 ffd2 call   edx
0x4aa2e4 f605e879fb0001 test   BYTE PTR ds:0xfb79e8,0x1
0x4aa2eb 8bf0 mov    esi,eax
0x4aa2ed 7525 jne    0x4aa314
0x4aa2ef b801000000 mov    eax,0x1
0x4aa2f4 0905e879fb00 or     DWORD PTR ds:0xfb79e8,eax
0x4aa2fa 89442460 mov    DWORD PTR [esp+0x60],eax
0x4aa2fe e8ddea2e00 call   0x798de0
0x4aa303 68e0d2bc00 push   0xbcd2e0
0x4aa308 e80d803e00 call   0x89231a
0x4aa30d 83c404 add    esp,0x4
0x4aa310 897c2460 mov    DWORD PTR [esp+0x60],edi
0x4aa314 833de476fb0000 cmp    DWORD PTR ds:0xfb76e4,0x0
0x4aa31b 7429 je     0x4aa346
0x4aa31d d94608 fld    DWORD PTR [esi+0x8]
0x4aa320 8b15b076fb00 mov    edx,DWORD PTR ds:0xfb76b0
0x4aa326 83ec0c sub    esp,0xc
0x4aa329 d95c2408 fstp   DWORD PTR [esp+0x8]
0x4aa32d d94604 fld    DWORD PTR [esi+0x4]
0x4aa330 d95c2404 fstp   DWORD PTR [esp+0x4]
0x4aa334 d906 fld    DWORD PTR [esi]
0x4aa336 d91c24 fstp   DWORD PTR [esp]
0x4aa339 e8c2e43800 call   0x838800
0x4aa33e 85c0 test   eax,eax
0x4aa340 0f8440010000 je     0x4aa486
0x4aa346 f605e879fb0001 test   BYTE PTR ds:0xfb79e8,0x1
0x4aa34d 7525 jne    0x4aa374
0x4aa34f 830de879fb0001 or     DWORD PTR ds:0xfb79e8,0x1
0x4aa356 c744246002000000 mov    DWORD PTR [esp+0x60],0x2
0x4aa35e e87dea2e00 call   0x798de0
0x4aa363 68e0d2bc00 push   0xbcd2e0
0x4aa368 e8ad7f3e00 call   0x89231a
0x4aa36d 83c404 add    esp,0x4
0x4aa370 897c2460 mov    DWORD PTR [esp+0x60],edi
0x4aa374 a1e876fb00 mov    eax,ds:0xfb76e8
0x4aa379 8b4804 mov    ecx,DWORD PTR [eax+0x4]
0x4aa37c 8b11 mov    edx,DWORD PTR [ecx]
0x4aa37e 8b5224 mov    edx,DWORD PTR [edx+0x24]
0x4aa381 8d442428 lea    eax,[esp+0x28]
0x4aa385 50 push   eax
0x4aa386 ffd2 call   edx
0x4aa388 8b08 mov    ecx,DWORD PTR [eax]
0x4aa38a 8b5004 mov    edx,DWORD PTR [eax+0x4]
0x4aa38d 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x4aa390 894c2410 mov    DWORD PTR [esp+0x10],ecx
0x4aa394 d9442410 fld    DWORD PTR [esp+0x10]
0x4aa398 d826 fsub   DWORD PTR [esi]
0x4aa39a 89542414 mov    DWORD PTR [esp+0x14],edx
0x4aa39e 89442418 mov    DWORD PTR [esp+0x18],eax
0x4aa3a2 d95c241c fstp   DWORD PTR [esp+0x1c]
0x4aa3a6 d9442414 fld    DWORD PTR [esp+0x14]
0x4aa3aa d86604 fsub   DWORD PTR [esi+0x4]
0x4aa3ad d95c2420 fstp   DWORD PTR [esp+0x20]
0x4aa3b1 d9442418 fld    DWORD PTR [esp+0x18]
0x4aa3b5 d86608 fsub   DWORD PTR [esi+0x8]
0x4aa3b8 d95c2424 fstp   DWORD PTR [esp+0x24]
0x4aa3bc d9442420 fld    DWORD PTR [esp+0x20]
0x4aa3c0 d944241c fld    DWORD PTR [esp+0x1c]
0x4aa3c4 d9442424 fld    DWORD PTR [esp+0x24]
0x4aa3c8 d9c1 fld    st(1)
0x4aa3ca deca fmulp  st(2),st
0x4aa3cc d9c2 fld    st(2)
0x4aa3ce decb fmulp  st(3),st
0x4aa3d0 d9c9 fxch   st(1)
0x4aa3d2 dec2 faddp  st(2),st
0x4aa3d4 dcc8 fmul   st(0),st
0x4aa3d6 dec1 faddp  st(1),st
0x4aa3d8 d95c2410 fstp   DWORD PTR [esp+0x10]
0x4aa3dc d9442410 fld    DWORD PTR [esp+0x10]
0x4aa3e0 e88b544500 call   0x8ff870
0x4aa3e5 d95c2410 fstp   DWORD PTR [esp+0x10]
0x4aa3e9 d9442410 fld    DWORD PTR [esp+0x10]
0x4aa3ed d9057057c500 fld    DWORD PTR ds:0xc55770
0x4aa3f3 dff1 fcomip st,st(1)
0x4aa3f5 ddd8 fstp   st(0)
0x4aa3f7 0f8689000000 jbe    0x4aa486
0x4aa3fd 56 push   esi
0x4aa3fe 51 push   ecx
0x4aa3ff e83ca3f8ff call   0x434740
0x4aa404 83c404 add    esp,0x4
0x4aa407 50 push   eax
0x4aa408 8d7c2418 lea    edi,[esp+0x18]
0x4aa40c e89f022f00 call   0x79a6b0
0x4aa411 e82a582300 call   0x6dfc40
0x4aa416 8b7018 mov    esi,DWORD PTR [eax+0x18]
0x4aa419 e822582300 call   0x6dfc40
0x4aa41e dd05e857c500 fld    QWORD PTR ds:0xc557e8
0x4aa424 d9442410 fld    DWORD PTR [esp+0x10]
0x4aa428 8b481c mov    ecx,DWORD PTR [eax+0x1c]
0x4aa42b dbf1 fcomi  st,st(1)
0x4aa42d 7653 jbe    0x4aa482
0x4aa42f d9442414 fld    DWORD PTR [esp+0x14]
0x4aa433 dbf2 fcomi  st,st(2)
0x4aa435 ddda fstp   st(2)
0x4aa437 7649 jbe    0x4aa482
0x4aa439 83c69c add    esi,0xffffff9c
0x4aa43c 89742410 mov    DWORD PTR [esp+0x10],esi
0x4aa440 db442410 fild   DWORD PTR [esp+0x10]
0x4aa444 7906 jns    0x4aa44c
0x4aa446 d8058056c500 fadd   DWORD PTR ds:0xc55680
0x4aa44c dff1 fcomip st,st(1)
0x4aa44e ddd8 fstp   st(0)
0x4aa450 7632 jbe    0x4aa484
0x4aa452 83c19c add    ecx,0xffffff9c
0x4aa455 894c2410 mov    DWORD PTR [esp+0x10],ecx
0x4aa459 db442410 fild   DWORD PTR [esp+0x10]
0x4aa45d 7906 jns    0x4aa465
0x4aa45f d8058056c500 fadd   DWORD PTR ds:0xc55680
0x4aa465 dff1 fcomip st,st(1)
0x4aa467 ddd8 fstp   st(0)
0x4aa469 761b jbe    0x4aa486
0x4aa46b b801000000 mov    eax,0x1
0x4aa470 8b4c2458 mov    ecx,DWORD PTR [esp+0x58]
0x4aa474 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4aa47b 59 pop    ecx
0x4aa47c 5f pop    edi
0x4aa47d 5e pop    esi
0x4aa47e 8be5 mov    esp,ebp
0x4aa480 5d pop    ebp
0x4aa481 c3 ret
0x4aa482 ddd9 fstp   st(1)
0x4aa484 ddd8 fstp   st(0)
0x4aa486 33c0 xor    eax,eax
0x4aa488 8b4c2458 mov    ecx,DWORD PTR [esp+0x58]
0x4aa48c 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4aa493 59 pop    ecx
0x4aa494 5f pop    edi
0x4aa495 5e pop    esi
0x4aa496 8be5 mov    esp,ebp
0x4aa498 5d pop    ebp
0x4aa499 c3 ret

; leader_model_three [0x4aa4a0,0x4aa4c4)
0x4aa4a0 8b0da4a7fb00 mov    ecx,DWORD PTR ds:0xfba7a4
0x4aa4a6 8b01 mov    eax,DWORD PTR [ecx]
0x4aa4a8 8b5020 mov    edx,DWORD PTR [eax+0x20]
0x4aa4ab ffd2 call   edx
0x4aa4ad 85c0 test   eax,eax
0x4aa4af 7410 je     0x4aa4c1
0x4aa4b1 6683b88800000003 cmp    WORD PTR [eax+0x88],0x3
0x4aa4b9 7506 jne    0x4aa4c1
0x4aa4bb b801000000 mov    eax,0x1
0x4aa4c0 c3 ret
0x4aa4c1 33c0 xor    eax,eax
0x4aa4c3 c3 ret

; leader_dialog_latch [0x54e740,0x54e744)
0x54e740 8b4138 mov    eax,DWORD PTR [ecx+0x38]
0x54e743 c3 ret

; scenario_latch [0x4aa510,0x4aa524)
0x4aa510 55 push   ebp
0x4aa511 8bec mov    ebp,esp
0x4aa513 8d4104 lea    eax,[ecx+0x4]
0x4aa516 8d5508 lea    edx,[ebp+0x8]
0x4aa519 e862830100 call   0x4c2880
0x4aa51e 8b00 mov    eax,DWORD PTR [eax]
0x4aa520 5d pop    ebp
0x4aa521 c20400 ret    0x4

; camera_completion [0x54ea00,0x54ea13)
0x54ea00 8b09 mov    ecx,DWORD PTR [ecx]
0x54ea02 85c9 test   ecx,ecx
0x54ea04 7407 je     0x54ea0d
0x54ea06 8b01 mov    eax,DWORD PTR [ecx]
0x54ea08 8b5020 mov    edx,DWORD PTR [eax+0x20]
0x54ea0b ffe2 jmp    edx
0x54ea0d b801000000 mov    eax,0x1
0x54ea12 c3 ret

; q_running [0x489cf0,0x489cf4)
0x489cf0 8b4128 mov    eax,DWORD PTR [ecx+0x28]
0x489cf3 c3 ret

; leader_position_component [0x564610,0x564697)
0x564610 55 push   ebp
0x564611 8bec mov    ebp,esp
0x564613 83ec10 sub    esp,0x10
0x564616 a1201fd600 mov    eax,ds:0xd61f20
0x56461b 33c5 xor    eax,ebp
0x56461d 8945fc mov    DWORD PTR [ebp-0x4],eax
0x564620 8b0da4a7fb00 mov    ecx,DWORD PTR ds:0xfba7a4
0x564626 8b01 mov    eax,DWORD PTR [ecx]
0x564628 8b5020 mov    edx,DWORD PTR [eax+0x20]
0x56462b ffd2 call   edx
0x56462d 85c0 test   eax,eax
0x56462f 7454 je     0x564685
0x564631 8b10 mov    edx,DWORD PTR [eax]
0x564633 8b5250 mov    edx,DWORD PTR [edx+0x50]
0x564636 8d4df0 lea    ecx,[ebp-0x10]
0x564639 51 push   ecx
0x56463a 8bc8 mov    ecx,eax
0x56463c ffd2 call   edx
0x56463e 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x564641 83e800 sub    eax,0x0
0x564644 742c je     0x564672
0x564646 48 dec    eax
0x564647 7416 je     0x56465f
0x564649 48 dec    eax
0x56464a 7539 jne    0x564685
0x56464c d945f8 fld    DWORD PTR [ebp-0x8]
0x56464f 8b4dfc mov    ecx,DWORD PTR [ebp-0x4]
0x564652 33cd xor    ecx,ebp
0x564654 e8a8c93200 call   0x891001
0x564659 8be5 mov    esp,ebp
0x56465b 5d pop    ebp
0x56465c c20400 ret    0x4
0x56465f d945f4 fld    DWORD PTR [ebp-0xc]
0x564662 8b4dfc mov    ecx,DWORD PTR [ebp-0x4]
0x564665 33cd xor    ecx,ebp
0x564667 e895c93200 call   0x891001
0x56466c 8be5 mov    esp,ebp
0x56466e 5d pop    ebp
0x56466f c20400 ret    0x4
0x564672 d945f0 fld    DWORD PTR [ebp-0x10]
0x564675 8b4dfc mov    ecx,DWORD PTR [ebp-0x4]
0x564678 33cd xor    ecx,ebp
0x56467a e882c93200 call   0x891001
0x56467f 8be5 mov    esp,ebp
0x564681 5d pop    ebp
0x564682 c20400 ret    0x4
0x564685 8b4dfc mov    ecx,DWORD PTR [ebp-0x4]
0x564688 d9ee fldz
0x56468a 33cd xor    ecx,ebp
0x56468c e870c93200 call   0x891001
0x564691 8be5 mov    esp,ebp
0x564693 5d pop    ebp
0x564694 c20400 ret    0x4

; q_all_stopped [0x564880,0x5648f6)
0x564880 8b511c mov    edx,DWORD PTR [ecx+0x1c]
0x564883 8b0a mov    ecx,DWORD PTR [edx]
0x564885 56 push   esi
0x564886 3bca cmp    ecx,edx
0x564888 7461 je     0x5648eb
0x56488a 8d9b00000000 lea    ebx,[ebx+0x0]
0x564890 8b4110 mov    eax,DWORD PTR [ecx+0x10]
0x564893 be00800000 mov    esi,0x8000
0x564898 6685b0e2000000 test   WORD PTR [eax+0xe2],si
0x56489f 7551 jne    0x5648f2
0x5648a1 80791500 cmp    BYTE PTR [ecx+0x15],0x0
0x5648a5 7540 jne    0x5648e7
0x5648a7 8b4108 mov    eax,DWORD PTR [ecx+0x8]
0x5648aa 80781500 cmp    BYTE PTR [eax+0x15],0x0
0x5648ae 751c jne    0x5648cc
0x5648b0 8bc8 mov    ecx,eax
0x5648b2 8b01 mov    eax,DWORD PTR [ecx]
0x5648b4 80781500 cmp    BYTE PTR [eax+0x15],0x0
0x5648b8 752d jne    0x5648e7
0x5648ba 8d9b00000000 lea    ebx,[ebx+0x0]
0x5648c0 8bc8 mov    ecx,eax
0x5648c2 8b01 mov    eax,DWORD PTR [ecx]
0x5648c4 80781500 cmp    BYTE PTR [eax+0x15],0x0
0x5648c8 74f6 je     0x5648c0
0x5648ca eb1b jmp    0x5648e7
0x5648cc 8b4104 mov    eax,DWORD PTR [ecx+0x4]
0x5648cf 80781500 cmp    BYTE PTR [eax+0x15],0x0
0x5648d3 7510 jne    0x5648e5
0x5648d5 3b4808 cmp    ecx,DWORD PTR [eax+0x8]
0x5648d8 750b jne    0x5648e5
0x5648da 8bc8 mov    ecx,eax
0x5648dc 8b4004 mov    eax,DWORD PTR [eax+0x4]
0x5648df 80781500 cmp    BYTE PTR [eax+0x15],0x0
0x5648e3 74f0 je     0x5648d5
0x5648e5 8bc8 mov    ecx,eax
0x5648e7 3bca cmp    ecx,edx
0x5648e9 75a5 jne    0x564890
0x5648eb b801000000 mov    eax,0x1
0x5648f0 5e pop    esi
0x5648f1 c3 ret
0x5648f2 33c0 xor    eax,eax
0x5648f4 5e pop    esi
0x5648f5 c3 ret

; prolog_running [0x564c50,0x564cb2)
0x564c50 55 push   ebp
0x564c51 8bec mov    ebp,esp
0x564c53 6aff push   0xffffffff
0x564c55 68aea99300 push   0x93a9ae
0x564c5a 64a100000000 mov    eax,fs:0x0
0x564c60 50 push   eax
0x564c61 a1201fd600 mov    eax,ds:0xd61f20
0x564c66 33c5 xor    eax,ebp
0x564c68 50 push   eax
0x564c69 8d45f4 lea    eax,[ebp-0xc]
0x564c6c 64a300000000 mov    fs:0x0,eax
0x564c72 b801000000 mov    eax,0x1
0x564c77 8405141bfc00 test   BYTE PTR ds:0xfc1b14,al
0x564c7d 751f jne    0x564c9e
0x564c7f 0905141bfc00 or     DWORD PTR ds:0xfc1b14,eax
0x564c85 c745fc00000000 mov    DWORD PTR [ebp-0x4],0x0
0x564c8c e8ffa1ffff call   0x55ee90
0x564c91 6890dfbc00 push   0xbcdf90
0x564c96 e87fd63200 call   0x89231a
0x564c9b 83c404 add    esp,0x4
0x564c9e a1181bfc00 mov    eax,ds:0xfc1b18
0x564ca3 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x564ca6 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x564cad 59 pop    ecx
0x564cae 8be5 mov    esp,ebp
0x564cb0 5d pop    ebp
0x564cb1 c3 ret

; book_running [0x565270,0x5652d2)
0x565270 55 push   ebp
0x565271 8bec mov    ebp,esp
0x565273 6aff push   0xffffffff
0x565275 68ee2e9200 push   0x922eee
0x56527a 64a100000000 mov    eax,fs:0x0
0x565280 50 push   eax
0x565281 a1201fd600 mov    eax,ds:0xd61f20
0x565286 33c5 xor    eax,ebp
0x565288 50 push   eax
0x565289 8d45f4 lea    eax,[ebp-0xc]
0x56528c 64a300000000 mov    fs:0x0,eax
0x565292 b801000000 mov    eax,0x1
0x565297 8405f41bfc00 test   BYTE PTR ds:0xfc1bf4,al
0x56529d 751f jne    0x5652be
0x56529f 0905f41bfc00 or     DWORD PTR ds:0xfc1bf4,eax
0x5652a5 c745fc00000000 mov    DWORD PTR [ebp-0x4],0x0
0x5652ac e8df9c0100 call   0x57ef90
0x5652b1 68b0dfbc00 push   0xbcdfb0
0x5652b6 e85fd03200 call   0x89231a
0x5652bb 83c404 add    esp,0x4
0x5652be a16c1cfc00 mov    eax,ds:0xfc1c6c
0x5652c3 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x5652c6 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x5652cd 59 pop    ecx
0x5652ce 8be5 mov    esp,ebp
0x5652d0 5d pop    ebp
0x5652d1 c3 ret

; synopsis_entry_reset_prefix [0x4a89c0,0x4a89f5)
0x4a89c0 55 push   ebp
0x4a89c1 8bec mov    ebp,esp
0x4a89c3 6aff push   0xffffffff
0x4a89c5 687ea49300 push   0x93a47e
0x4a89ca 64a100000000 mov    eax,fs:0x0
0x4a89d0 50 push   eax
0x4a89d1 57 push   edi
0x4a89d2 a1201fd600 mov    eax,ds:0xd61f20
0x4a89d7 33c5 xor    eax,ebp
0x4a89d9 50 push   eax
0x4a89da 8d45f4 lea    eax,[ebp-0xc]
0x4a89dd 64a300000000 mov    fs:0x0,eax
0x4a89e3 8d7e14 lea    edi,[esi+0x14]
0x4a89e6 c705a0a7fb0000000000 mov    DWORD PTR ds:0xfba7a0,0x0
0x4a89f0 e82b8a3a00 call   0x851420

; tutorial_entry_reset_prefix [0x4a8a60,0x4a8a99)
0x4a8a60 55 push   ebp
0x4a8a61 8bec mov    ebp,esp
0x4a8a63 6aff push   0xffffffff
0x4a8a65 684ca49300 push   0x93a44c
0x4a8a6a 64a100000000 mov    eax,fs:0x0
0x4a8a70 50 push   eax
0x4a8a71 83ec08 sub    esp,0x8
0x4a8a74 53 push   ebx
0x4a8a75 57 push   edi
0x4a8a76 a1201fd600 mov    eax,ds:0xd61f20
0x4a8a7b 33c5 xor    eax,ebp
0x4a8a7d 50 push   eax
0x4a8a7e 8d45f4 lea    eax,[ebp-0xc]
0x4a8a81 64a300000000 mov    fs:0x0,eax
0x4a8a87 8d7e04 lea    edi,[esi+0x4]
0x4a8a8a c705a0a7fb0000000000 mov    DWORD PTR ds:0xfba7a0,0x0
0x4a8a94 e8b7ad3700 call   0x823850

; skip_writer_before_active_prefix [0x5624b0,0x562527)
0x5624b0 55 push   ebp
0x5624b1 8bec mov    ebp,esp
0x5624b3 83e4f8 and    esp,0xfffffff8
0x5624b6 6aff push   0xffffffff
0x5624b8 68603d9400 push   0x943d60
0x5624bd 64a100000000 mov    eax,fs:0x0
0x5624c3 50 push   eax
0x5624c4 83ec28 sub    esp,0x28
0x5624c7 a1201fd600 mov    eax,ds:0xd61f20
0x5624cc 33c4 xor    eax,esp
0x5624ce 89442420 mov    DWORD PTR [esp+0x20],eax
0x5624d2 53 push   ebx
0x5624d3 56 push   esi
0x5624d4 57 push   edi
0x5624d5 a1201fd600 mov    eax,ds:0xd61f20
0x5624da 33c4 xor    eax,esp
0x5624dc 50 push   eax
0x5624dd 8d442438 lea    eax,[esp+0x38]
0x5624e1 64a300000000 mov    fs:0x0,eax
0x5624e7 33f6 xor    esi,esi
0x5624e9 8bf9 mov    edi,ecx
0x5624eb 897c2410 mov    DWORD PTR [esp+0x10],edi
0x5624ef 397508 cmp    DWORD PTR [ebp+0x8],esi
0x5624f2 742a je     0x56251e
0x5624f4 817f38e8030000 cmp    DWORD PTR [edi+0x38],0x3e8
0x5624fb 7521 jne    0x56251e
0x5624fd 8b473c mov    eax,DWORD PTR [edi+0x3c]
0x562500 83f80f cmp    eax,0xf
0x562503 740f je     0x562514
0x562505 83f810 cmp    eax,0x10
0x562508 740a je     0x562514
0x56250a 83f811 cmp    eax,0x11
0x56250d 7405 je     0x562514
0x56250f 83f812 cmp    eax,0x12
0x562512 750a jne    0x56251e
0x562514 c705a0a7fb0001000000 mov    DWORD PTR ds:0xfba7a0,0x1
0x56251e 397728 cmp    DWORD PTR [edi+0x28],esi
0x562521 0f846a030000 je     0x562891

; ai_direction_consumer [0x549660,0x5498b9)
0x549660 55 push   ebp
0x549661 8bec mov    ebp,esp
0x549663 83e4f8 and    esp,0xfffffff8
0x549666 83ec20 sub    esp,0x20
0x549669 8b4650 mov    eax,DWORD PTR [esi+0x50]
0x54966c 8a88b0000000 mov    cl,BYTE PTR [eax+0xb0]
0x549672 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x549675 53 push   ebx
0x549676 8b5d0c mov    ebx,DWORD PTR [ebp+0xc]
0x549679 57 push   edi
0x54967a 884c240e mov    BYTE PTR [esp+0xe],cl
0x54967e 53 push   ebx
0x54967f 8bce mov    ecx,esi
0x549681 c644241301 mov    BYTE PTR [esp+0x13],0x1
0x549686 e8d5130000 call   0x54aa60
0x54968b 8bf8 mov    edi,eax
0x54968d 85ff test   edi,edi
0x54968f 0f84d3000000 je     0x549768
0x549695 837d0804 cmp    DWORD PTR [ebp+0x8],0x4
0x549699 0f85fa000000 jne    0x549799
0x54969f 85db test   ebx,ebx
0x5496a1 0f85f2000000 jne    0x549799
0x5496a7 8b4650 mov    eax,DWORD PTR [esi+0x50]
0x5496aa d94664 fld    DWORD PTR [esi+0x64]
0x5496ad d8a0a0000000 fsub   DWORD PTR [eax+0xa0]
0x5496b3 d95c2418 fstp   DWORD PTR [esp+0x18]
0x5496b7 d94668 fld    DWORD PTR [esi+0x68]
0x5496ba d8a0a4000000 fsub   DWORD PTR [eax+0xa4]
0x5496c0 d95c241c fstp   DWORD PTR [esp+0x1c]
0x5496c4 d944241c fld    DWORD PTR [esp+0x1c]
0x5496c8 d9442418 fld    DWORD PTR [esp+0x18]
0x5496cc dcc8 fmul   st(0),st
0x5496ce d9c1 fld    st(1)
0x5496d0 deca fmulp  st(2),st
0x5496d2 dec1 faddp  st(1),st
0x5496d4 d95c2410 fstp   DWORD PTR [esp+0x10]
0x5496d8 d905d058c500 fld    DWORD PTR ds:0xc558d0
0x5496de d9442410 fld    DWORD PTR [esp+0x10]
0x5496e2 dff1 fcomip st,st(1)
0x5496e4 ddd8 fstp   st(0)
0x5496e6 7673 jbe    0x54975b
0x5496e8 e87359ecff call   0x40f060
0x5496ed 8b88a4000000 mov    ecx,DWORD PTR [eax+0xa4]
0x5496f3 85c9 test   ecx,ecx
0x5496f5 7449 je     0x549740
0x5496f7 8b5668 mov    edx,DWORD PTR [esi+0x68]
0x5496fa 8b4650 mov    eax,DWORD PTR [esi+0x50]
0x5496fd 52 push   edx
0x5496fe 8b5664 mov    edx,DWORD PTR [esi+0x64]
0x549701 52 push   edx
0x549702 8b90a4000000 mov    edx,DWORD PTR [eax+0xa4]
0x549708 8b80a0000000 mov    eax,DWORD PTR [eax+0xa0]
0x54970e 52 push   edx
0x54970f 50 push   eax
0x549710 8d542420 lea    edx,[esp+0x20]
0x549714 52 push   edx
0x549715 51 push   ecx
0x549716 e875402e00 call   0x82d790
0x54971b 85c0 test   eax,eax
0x54971d 7421 je     0x549740
0x54971f 48 dec    eax
0x549720 83f802 cmp    eax,0x2
0x549723 7748 ja     0x54976d
0x549725 8d442410 lea    eax,[esp+0x10]
0x549729 e88217f5ff call   0x49aeb0
0x54972e 51 push   ecx
0x54972f d91c24 fstp   DWORD PTR [esp]
0x549732 e8191df7ff call   0x4bb450
0x549737 83c404 add    esp,0x4
0x54973a 8844240e mov    BYTE PTR [esp+0xe],al
0x54973e eb2d jmp    0x54976d
0x549740 8d442418 lea    eax,[esp+0x18]
0x549744 e86717f5ff call   0x49aeb0
0x549749 51 push   ecx
0x54974a d91c24 fstp   DWORD PTR [esp]
0x54974d e8fe1cf7ff call   0x4bb450
0x549752 83c404 add    esp,0x4
0x549755 8844240e mov    BYTE PTR [esp+0xe],al
0x549759 eb12 jmp    0x54976d
0x54975b 8b4654 mov    eax,DWORD PTR [esi+0x54]
0x54975e 8a88b0000000 mov    cl,BYTE PTR [eax+0xb0]
0x549764 884c240e mov    BYTE PTR [esp+0xe],cl
0x549768 c644240f00 mov    BYTE PTR [esp+0xf],0x0
0x54976d 837d1000 cmp    DWORD PTR [ebp+0x10],0x0
0x549771 7405 je     0x549778
0x549773 806c240e80 sub    BYTE PTR [esp+0xe],0x80
0x549778 8a44240f mov    al,BYTE PTR [esp+0xf]
0x54977c 8a54240e mov    dl,BYTE PTR [esp+0xe]
0x549780 0fb6c8 movzx  ecx,al
0x549783 66c1e10f shl    cx,0xf
0x549787 5f pop    edi
0x549788 66894e72 mov    WORD PTR [esi+0x72],cx
0x54978c 885674 mov    BYTE PTR [esi+0x74],dl
0x54978f 0fb6c0 movzx  eax,al
0x549792 5b pop    ebx
0x549793 8be5 mov    esp,ebp
0x549795 5d pop    ebp
0x549796 c20c00 ret    0xc
0x549799 8b4650 mov    eax,DWORD PTR [esi+0x50]
0x54979c d987a0000000 fld    DWORD PTR [edi+0xa0]
0x5497a2 d8a0a0000000 fsub   DWORD PTR [eax+0xa0]
0x5497a8 d95c2418 fstp   DWORD PTR [esp+0x18]
0x5497ac d987a4000000 fld    DWORD PTR [edi+0xa4]
0x5497b2 d8a0a4000000 fsub   DWORD PTR [eax+0xa4]
0x5497b8 d95c241c fstp   DWORD PTR [esp+0x1c]
0x5497bc d944241c fld    DWORD PTR [esp+0x1c]
0x5497c0 d9442418 fld    DWORD PTR [esp+0x18]
0x5497c4 dcc8 fmul   st(0),st
0x5497c6 d9c1 fld    st(1)
0x5497c8 deca fmulp  st(2),st
0x5497ca dec1 faddp  st(1),st
0x5497cc d95c2410 fstp   DWORD PTR [esp+0x10]
0x5497d0 d9442410 fld    DWORD PTR [esp+0x10]
0x5497d4 dd05385dc500 fld    QWORD PTR ds:0xc55d38
0x5497da dff1 fcomip st,st(1)
0x5497dc ddd8 fstp   st(0)
0x5497de 7388 jae    0x549768
0x5497e0 e87b58ecff call   0x40f060
0x5497e5 8b88a4000000 mov    ecx,DWORD PTR [eax+0xa4]
0x5497eb 85c9 test   ecx,ecx
0x5497ed 0f848e000000 je     0x549881
0x5497f3 8b97a4000000 mov    edx,DWORD PTR [edi+0xa4]
0x5497f9 8b4650 mov    eax,DWORD PTR [esi+0x50]
0x5497fc 52 push   edx
0x5497fd 8b97a0000000 mov    edx,DWORD PTR [edi+0xa0]
0x549803 52 push   edx
0x549804 8b90a4000000 mov    edx,DWORD PTR [eax+0xa4]
0x54980a 8b80a0000000 mov    eax,DWORD PTR [eax+0xa0]
0x549810 52 push   edx
0x549811 50 push   eax
0x549812 8d542430 lea    edx,[esp+0x30]
0x549816 52 push   edx
0x549817 51 push   ecx
0x549818 e8733f2e00 call   0x82d790
0x54981d 85c0 test   eax,eax
0x54981f 7428 je     0x549849
0x549821 48 dec    eax
0x549822 83f802 cmp    eax,0x2
0x549825 0f8742ffffff ja     0x54976d
0x54982b 8d442420 lea    eax,[esp+0x20]
0x54982f e87c16f5ff call   0x49aeb0
0x549834 51 push   ecx
0x549835 d91c24 fstp   DWORD PTR [esp]
0x549838 e8131cf7ff call   0x4bb450
0x54983d 83c404 add    esp,0x4
0x549840 8844240e mov    BYTE PTR [esp+0xe],al
0x549844 e924ffffff jmp    0x54976d
0x549849 d944241c fld    DWORD PTR [esp+0x1c]
0x54984d d9442418 fld    DWORD PTR [esp+0x18]
0x549851 e874553b00 call   0x8fedca
0x549856 d95c2410 fstp   DWORD PTR [esp+0x10]
0x54985a d9442410 fld    DWORD PTR [esp+0x10]
0x54985e 51 push   ecx
0x54985f dc052858c500 fadd   QWORD PTR ds:0xc55828
0x549865 d95c2414 fstp   DWORD PTR [esp+0x14]
0x549869 d9442414 fld    DWORD PTR [esp+0x14]
0x54986d d91c24 fstp   DWORD PTR [esp]
0x549870 e8db1bf7ff call   0x4bb450
0x549875 83c404 add    esp,0x4
0x549878 8844240e mov    BYTE PTR [esp+0xe],al
0x54987c e9ecfeffff jmp    0x54976d
0x549881 d944241c fld    DWORD PTR [esp+0x1c]
0x549885 d9442418 fld    DWORD PTR [esp+0x18]
0x549889 e83c553b00 call   0x8fedca
0x54988e d95c2410 fstp   DWORD PTR [esp+0x10]
0x549892 d9442410 fld    DWORD PTR [esp+0x10]
0x549896 51 push   ecx
0x549897 dc052858c500 fadd   QWORD PTR ds:0xc55828
0x54989d d95c2414 fstp   DWORD PTR [esp+0x14]
0x5498a1 d9442414 fld    DWORD PTR [esp+0x14]
0x5498a5 d91c24 fstp   DWORD PTR [esp]
0x5498a8 e8a31bf7ff call   0x4bb450
0x5498ad 83c404 add    esp,0x4
0x5498b0 8844240e mov    BYTE PTR [esp+0xe],al
0x5498b4 e9b4feffff jmp    0x54976d

; ai_action_consumer [0x549c60,0x549e07)
0x549c60 55 push   ebp
0x549c61 8bec mov    ebp,esp
0x549c63 83e4f8 and    esp,0xfffffff8
0x549c66 6aff push   0xffffffff
0x549c68 68deed9300 push   0x93edde
0x549c6d 64a100000000 mov    eax,fs:0x0
0x549c73 50 push   eax
0x549c74 83ec14 sub    esp,0x14
0x549c77 53 push   ebx
0x549c78 57 push   edi
0x549c79 a1201fd600 mov    eax,ds:0xd61f20
0x549c7e 33c4 xor    eax,esp
0x549c80 50 push   eax
0x549c81 8d442420 lea    eax,[esp+0x20]
0x549c85 64a300000000 mov    fs:0x0,eax
0x549c8b 8b450c mov    eax,DWORD PTR [ebp+0xc]
0x549c8e 50 push   eax
0x549c8f 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x549c92 8bce mov    ecx,esi
0x549c94 e8c70d0000 call   0x54aa60
0x549c99 8b4d14 mov    ecx,DWORD PTR [ebp+0x14]
0x549c9c 33d2 xor    edx,edx
0x549c9e 89442418 mov    DWORD PTR [esp+0x18],eax
0x549ca2 89542414 mov    DWORD PTR [esp+0x14],edx
0x549ca6 e875f0ffff call   0x548d20
0x549cab f6059043f90001 test   BYTE PTR ds:0xf94390,0x1
0x549cb2 0fb7f8 movzx  edi,ax
0x549cb5 8b4660 mov    eax,DWORD PTR [esi+0x60]
0x549cb8 8d0c40 lea    ecx,[eax+eax*2]
0x549cbb a1a4a7fb00 mov    eax,ds:0xfba7a4
0x549cc0 8b5c8810 mov    ebx,DWORD PTR [eax+ecx*4+0x10]
0x549cc4 7525 jne    0x549ceb
0x549cc6 830d9043f90001 or     DWORD PTR ds:0xf94390,0x1
0x549ccd 89542428 mov    DWORD PTR [esp+0x28],edx
0x549cd1 e8ba78f9ff call   0x4e1590
0x549cd6 6880ccbc00 push   0xbccc80
0x549cdb e83a863400 call   0x89231a
0x549ce0 83c404 add    esp,0x4
0x549ce3 c7442428ffffffff mov    DWORD PTR [esp+0x28],0xffffffff
0x549ceb 8b5650 mov    edx,DWORD PTR [esi+0x50]
0x549cee 0fb78288000000 movzx  eax,WORD PTR [edx+0x88]
0x549cf5 8b0d0443f900 mov    ecx,DWORD PTR ds:0xf94304
0x549cfb 83f809 cmp    eax,0x9
0x549cfe 0f87ef000000 ja     0x549df3
0x549d04 69c010020000 imul   eax,eax,0x210
0x549d0a 03c1 add    eax,ecx
0x549d0c 83785c00 cmp    DWORD PTR [eax+0x5c],0x0
0x549d10 0f84dd000000 je     0x549df3
0x549d16 85c0 test   eax,eax
0x549d18 0f84d5000000 je     0x549df3
0x549d1e 05f4010000 add    eax,0x1f4
0x549d23 0f84ca000000 je     0x549df3
0x549d29 837d10ff cmp    DWORD PTR [ebp+0x10],0xffffffff
0x549d2d 7509 jne    0x549d38
0x549d2f 8b8ae8030000 mov    ecx,DWORD PTR [edx+0x3e8]
0x549d35 894d10 mov    DWORD PTR [ebp+0x10],ecx
0x549d38 8b4d10 mov    ecx,DWORD PTR [ebp+0x10]
0x549d3b 33d2 xor    edx,edx
0x549d3d 385002 cmp    BYTE PTR [eax+0x2],dl
0x549d40 51 push   ecx
0x549d41 0f95c2 setne  dl
0x549d44 8bcb mov    ecx,ebx
0x549d46 8a0402 mov    al,BYTE PTR [edx+eax*1]
0x549d49 88442414 mov    BYTE PTR [esp+0x14],al
0x549d4d 8b542414 mov    edx,DWORD PTR [esp+0x14]
0x549d51 52 push   edx
0x549d52 8bc7 mov    eax,edi
0x549d54 e817550000 call   0x54f270
0x549d59 85c0 test   eax,eax
0x549d5b 742d je     0x549d8a
0x549d5d 668b4672 mov    ax,WORD PTR [esi+0x72]
0x549d61 8b9608010000 mov    edx,DWORD PTR [esi+0x108]
0x549d67 6633c7 xor    ax,di
0x549d6a b9ff7f0000 mov    ecx,0x7fff
0x549d6f 6623c1 and    ax,cx
0x549d72 66314672 xor    WORD PTR [esi+0x72],ax
0x549d76 03d2 add    edx,edx
0x549d78 b801000000 mov    eax,0x1
0x549d7d c784d6ac00000004000000 mov    DWORD PTR [esi+edx*8+0xac],0x4
0x549d88 eb04 jmp    0x549d8e
0x549d8a 8b442414 mov    eax,DWORD PTR [esp+0x14]
0x549d8e 8b4c2418 mov    ecx,DWORD PTR [esp+0x18]
0x549d92 85c9 test   ecx,ecx
0x549d94 745d je     0x549df3
0x549d96 85c0 test   eax,eax
0x549d98 7459 je     0x549df3
0x549d9a 8b4650 mov    eax,DWORD PTR [esi+0x50]
0x549d9d d981a4000000 fld    DWORD PTR [ecx+0xa4]
0x549da3 d8a0a4000000 fsub   DWORD PTR [eax+0xa4]
0x549da9 d95c2418 fstp   DWORD PTR [esp+0x18]
0x549dad d981a0000000 fld    DWORD PTR [ecx+0xa0]
0x549db3 d8a0a0000000 fsub   DWORD PTR [eax+0xa0]
0x549db9 d95c2414 fstp   DWORD PTR [esp+0x14]
0x549dbd d9442418 fld    DWORD PTR [esp+0x18]
0x549dc1 d9442414 fld    DWORD PTR [esp+0x14]
0x549dc5 e800503b00 call   0x8fedca
0x549dca d95c2418 fstp   DWORD PTR [esp+0x18]
0x549dce d9442418 fld    DWORD PTR [esp+0x18]
0x549dd2 51 push   ecx
0x549dd3 dc052858c500 fadd   QWORD PTR ds:0xc55828
0x549dd9 d95c241c fstp   DWORD PTR [esp+0x1c]
0x549ddd d944241c fld    DWORD PTR [esp+0x1c]
0x549de1 d91c24 fstp   DWORD PTR [esp]
0x549de4 e86716f7ff call   0x4bb450
0x549de9 83c404 add    esp,0x4
0x549dec 884674 mov    BYTE PTR [esi+0x74],al
0x549def c6464c00 mov    BYTE PTR [esi+0x4c],0x0
0x549df3 8b4c2420 mov    ecx,DWORD PTR [esp+0x20]
0x549df7 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x549dfe 59 pop    ecx
0x549dff 5f pop    edi
0x549e00 5b pop    ebx
0x549e01 8be5 mov    esp,ebp
0x549e03 5d pop    ebp
0x549e04 c21000 ret    0x10

; talk_ctor [0x6bce70,0x6bcf51)
0x6bce70 55 push   ebp
0x6bce71 8bec mov    ebp,esp
0x6bce73 6aff push   0xffffffff
0x6bce75 68b6a79300 push   0x93a7b6
0x6bce7a 64a100000000 mov    eax,fs:0x0
0x6bce80 50 push   eax
0x6bce81 51 push   ecx
0x6bce82 53 push   ebx
0x6bce83 56 push   esi
0x6bce84 a1201fd600 mov    eax,ds:0xd61f20
0x6bce89 33c5 xor    eax,ebp
0x6bce8b 50 push   eax
0x6bce8c 8d45f4 lea    eax,[ebp-0xc]
0x6bce8f 64a300000000 mov    fs:0x0,eax
0x6bce95 8b7508 mov    esi,DWORD PTR [ebp+0x8]
0x6bce98 8bce mov    ecx,esi
0x6bce9a e851830800 call   0x7451f0
0x6bce9f 33db xor    ebx,ebx
0x6bcea1 895dfc mov    DWORD PTR [ebp-0x4],ebx
0x6bcea4 b801000000 mov    eax,0x1
0x6bcea9 c70644ebc300 mov    DWORD PTR [esi],0xc3eb44
0x6bceaf 899e80000000 mov    DWORD PTR [esi+0x80],ebx
0x6bceb5 899e84000000 mov    DWORD PTR [esi+0x84],ebx
0x6bcebb 899e88000000 mov    DWORD PTR [esi+0x88],ebx
0x6bcec1 899e8c000000 mov    DWORD PTR [esi+0x8c],ebx
0x6bcec7 899e90000000 mov    DWORD PTR [esi+0x90],ebx
0x6bcecd 899e94000000 mov    DWORD PTR [esi+0x94],ebx
0x6bced3 899e98000000 mov    DWORD PTR [esi+0x98],ebx
0x6bced9 899e9c000000 mov    DWORD PTR [esi+0x9c],ebx
0x6bcedf 899ea0000000 mov    DWORD PTR [esi+0xa0],ebx
0x6bcee5 8405d4f3fd00 test   BYTE PTR ds:0xfdf3d4,al
0x6bceeb 751e jne    0x6bcf0b
0x6bceed 0905d4f3fd00 or     DWORD PTR ds:0xfdf3d4,eax
0x6bcef3 8845fc mov    BYTE PTR [ebp-0x4],al
0x6bcef6 e885740300 call   0x6f4380
0x6bcefb 68d0e6bc00 push   0xbce6d0
0x6bcf00 e815541d00 call   0x89231a
0x6bcf05 83c404 add    esp,0x4
0x6bcf08 885dfc mov    BYTE PTR [ebp-0x4],bl
0x6bcf0b 8d45f0 lea    eax,[ebp-0x10]
0x6bcf0e 68c8f3fd00 push   0xfdf3c8
0x6bcf13 50 push   eax
0x6bcf14 8bc6 mov    eax,esi
0x6bcf16 e8050b0000 call   0x6bda20
0x6bcf1b 83c408 add    esp,0x8
0x6bcf1e 50 push   eax
0x6bcf1f e8dc0b0000 call   0x6bdb00
0x6bcf24 50 push   eax
0x6bcf25 e8760c0000 call   0x6bdba0
0x6bcf2a 50 push   eax
0x6bcf2b e8100d0000 call   0x6bdc40
0x6bcf30 50 push   eax
0x6bcf31 e8aa0d0000 call   0x6bdce0
0x6bcf36 50 push   eax
0x6bcf37 e8440e0000 call   0x6bdd80
0x6bcf3c 8bc6 mov    eax,esi
0x6bcf3e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x6bcf41 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x6bcf48 59 pop    ecx
0x6bcf49 5e pop    esi
0x6bcf4a 5b pop    ebx
0x6bcf4b 8be5 mov    esp,ebp
0x6bcf4d 5d pop    ebp
0x6bcf4e c20400 ret    0x4

; talk_deleting_dtor [0x6bcf60,0x6bcf82)
0x6bcf60 55 push   ebp
0x6bcf61 8bec mov    ebp,esp
0x6bcf63 56 push   esi
0x6bcf64 8bf1 mov    esi,ecx
0x6bcf66 56 push   esi
0x6bcf67 e824000000 call   0x6bcf90
0x6bcf6c f6450801 test   BYTE PTR [ebp+0x8],0x1
0x6bcf70 7409 je     0x6bcf7b
0x6bcf72 56 push   esi
0x6bcf73 e884511d00 call   0x8920fc
0x6bcf78 83c404 add    esp,0x4
0x6bcf7b 8bc6 mov    eax,esi
0x6bcf7d 5e pop    esi
0x6bcf7e 5d pop    ebp
0x6bcf7f c20400 ret    0x4

; talk_dtor [0x6bcf90,0x6bd047)
0x6bcf90 55 push   ebp
0x6bcf91 8bec mov    ebp,esp
0x6bcf93 6aff push   0xffffffff
0x6bcf95 68b6a79300 push   0x93a7b6
0x6bcf9a 64a100000000 mov    eax,fs:0x0
0x6bcfa0 50 push   eax
0x6bcfa1 53 push   ebx
0x6bcfa2 56 push   esi
0x6bcfa3 57 push   edi
0x6bcfa4 a1201fd600 mov    eax,ds:0xd61f20
0x6bcfa9 33c5 xor    eax,ebp
0x6bcfab 50 push   eax
0x6bcfac 8d45f4 lea    eax,[ebp-0xc]
0x6bcfaf 64a300000000 mov    fs:0x0,eax
0x6bcfb5 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x6bcfb8 c70344ebc300 mov    DWORD PTR [ebx],0xc3eb44
0x6bcfbe 33f6 xor    esi,esi
0x6bcfc0 b801000000 mov    eax,0x1
0x6bcfc5 8975fc mov    DWORD PTR [ebp-0x4],esi
0x6bcfc8 8405d4f3fd00 test   BYTE PTR ds:0xfdf3d4,al
0x6bcfce 751f jne    0x6bcfef
0x6bcfd0 0905d4f3fd00 or     DWORD PTR ds:0xfdf3d4,eax
0x6bcfd6 8845fc mov    BYTE PTR [ebp-0x4],al
0x6bcfd9 e8a2730300 call   0x6f4380
0x6bcfde 68d0e6bc00 push   0xbce6d0
0x6bcfe3 e832531d00 call   0x89231a
0x6bcfe8 83c404 add    esp,0x4
0x6bcfeb c645fc00 mov    BYTE PTR [ebp-0x4],0x0
0x6bcfef a1c8f3fd00 mov    eax,ds:0xfdf3c8
0x6bcff4 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x6bcff7 897108 mov    DWORD PTR [ecx+0x8],esi
0x6bcffa 83400810 add    DWORD PTR [eax+0x8],0x10
0x6bcffe 89357c31fe00 mov    DWORD PTR ds:0xfe317c,esi
0x6bd004 89358031fe00 mov    DWORD PTR ds:0xfe3180,esi
0x6bd00a 8b35c8f3fd00 mov    esi,DWORD PTR ds:0xfdf3c8
0x6bd010 bf28ebc300 mov    edi,0xc3eb28
0x6bd015 b8eed8ffff mov    eax,0xffffd8ee
0x6bd01a e871870300 call   0x6f5790
0x6bd01f c745fcffffffff mov    DWORD PTR [ebp-0x4],0xffffffff
0x6bd026 8bcb mov    ecx,ebx
0x6bd028 c7039c90c400 mov    DWORD PTR [ebx],0xc4909c
0x6bd02e e84d830800 call   0x745380
0x6bd033 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x6bd036 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x6bd03d 59 pop    ecx
0x6bd03e 5f pop    edi
0x6bd03f 5e pop    esi
0x6bd040 5b pop    ebx
0x6bd041 8be5 mov    esp,ebp
0x6bd043 5d pop    ebp
0x6bd044 c20400 ret    0x4

; talk_row_render [0x6bd050,0x6bd3f7)
0x6bd050 55 push   ebp
0x6bd051 8bec mov    ebp,esp
0x6bd053 6aff push   0xffffffff
0x6bd055 6842bf9200 push   0x92bf42
0x6bd05a 64a100000000 mov    eax,fs:0x0
0x6bd060 50 push   eax
0x6bd061 83ec30 sub    esp,0x30
0x6bd064 a1201fd600 mov    eax,ds:0xd61f20
0x6bd069 33c5 xor    eax,ebp
0x6bd06b 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x6bd06e 53 push   ebx
0x6bd06f 56 push   esi
0x6bd070 57 push   edi
0x6bd071 50 push   eax
0x6bd072 8d45f4 lea    eax,[ebp-0xc]
0x6bd075 64a300000000 mov    fs:0x0,eax
0x6bd07b 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x6bd07e 83bba000000000 cmp    DWORD PTR [ebx+0xa0],0x0
0x6bd085 0f84e8010000 je     0x6bd273
0x6bd08b f6059443f90001 test   BYTE PTR ds:0xf94394,0x1
0x6bd092 7527 jne    0x6bd0bb
0x6bd094 830d9443f90001 or     DWORD PTR ds:0xf94394,0x1
0x6bd09b c745fc00000000 mov    DWORD PTR [ebp-0x4],0x0
0x6bd0a2 e8396df0ff call   0x5c3de0
0x6bd0a7 6830ccbc00 push   0xbccc30
0x6bd0ac e869521d00 call   0x89231a
0x6bd0b1 83c404 add    esp,0x4
0x6bd0b4 c745fcffffffff mov    DWORD PTR [ebp-0x4],0xffffffff
0x6bd0bb 8b83a0000000 mov    eax,DWORD PTR [ebx+0xa0]
0x6bd0c1 8b30 mov    esi,DWORD PTR [eax]
0x6bd0c3 bad0ecc000 mov    edx,0xc0ecd0
0x6bd0c8 bf9843f900 mov    edi,0xf94398
0x6bd0cd e8bea0f0ff call   0x5c7190
0x6bd0d2 8bf8 mov    edi,eax
0x6bd0d4 85ff test   edi,edi
0x6bd0d6 7421 je     0x6bd0f9
0x6bd0d8 8d4dcc lea    ecx,[ebp-0x34]
0x6bd0db 51 push   ecx
0x6bd0dc 8d4f08 lea    ecx,[edi+0x8]
0x6bd0df 8d45d0 lea    eax,[ebp-0x30]
0x6bd0e2 8975cc mov    DWORD PTR [ebp-0x34],esi
0x6bd0e5 e8161e1700 call   0x82ef00
0x6bd0ea 8b7f0c mov    edi,DWORD PTR [edi+0xc]
0x6bd0ed 8b45d0 mov    eax,DWORD PTR [ebp-0x30]
0x6bd0f0 3bc7 cmp    eax,edi
0x6bd0f2 7405 je     0x6bd0f9
0x6bd0f4 8b4010 mov    eax,DWORD PTR [eax+0x10]
0x6bd0f7 eb02 jmp    0x6bd0fb
0x6bd0f9 33c0 xor    eax,eax
0x6bd0fb 8b8b88000000 mov    ecx,DWORD PTR [ebx+0x88]
0x6bd101 e85a7f0800 call   0x745060
0x6bd106 8b8b88000000 mov    ecx,DWORD PTR [ebx+0x88]
0x6bd10c 8b11 mov    edx,DWORD PTR [ecx]
0x6bd10e 8b82c8000000 mov    eax,DWORD PTR [edx+0xc8]
0x6bd114 ffd0 call   eax
0x6bd116 8b8ba0000000 mov    ecx,DWORD PTR [ebx+0xa0]
0x6bd11c 8b5104 mov    edx,DWORD PTR [ecx+0x4]
0x6bd11f 8b35d01bfe00 mov    esi,DWORD PTR ds:0xfe1bd0
0x6bd125 8d45cc lea    eax,[ebp-0x34]
0x6bd128 50 push   eax
0x6bd129 8d4e18 lea    ecx,[esi+0x18]
0x6bd12c 8d45d0 lea    eax,[ebp-0x30]
0x6bd12f 8955cc mov    DWORD PTR [ebp-0x34],edx
0x6bd132 e899a3e6ff call   0x5274d0
0x6bd137 8b4dd0 mov    ecx,DWORD PTR [ebp-0x30]
0x6bd13a 3b4e1c cmp    ecx,DWORD PTR [esi+0x1c]
0x6bd13d 0f844e010000 je     0x6bd291
0x6bd143 8d4110 lea    eax,[ecx+0x10]
0x6bd146 8945cc mov    DWORD PTR [ebp-0x34],eax
0x6bd149 85c0 test   eax,eax
0x6bd14b 742b je     0x6bd178
0x6bd14d 8b8b84000000 mov    ecx,DWORD PTR [ebx+0x84]
0x6bd153 81c1e8000000 add    ecx,0xe8
0x6bd159 83c028 add    eax,0x28
0x6bd15c 51 push   ecx
0x6bd15d e89e81d4ff call   0x405300
0x6bd162 8b8b84000000 mov    ecx,DWORD PTR [ebx+0x84]
0x6bd168 8b11 mov    edx,DWORD PTR [ecx]
0x6bd16a 8b82c8000000 mov    eax,DWORD PTR [edx+0xc8]
0x6bd170 ffd0 call   eax
0x6bd172 8b35d01bfe00 mov    esi,DWORD PTR ds:0xfe1bd0
0x6bd178 8b8ba0000000 mov    ecx,DWORD PTR [ebx+0xa0]
0x6bd17e 8b11 mov    edx,DWORD PTR [ecx]
0x6bd180 8d45d0 lea    eax,[ebp-0x30]
0x6bd183 50 push   eax
0x6bd184 8d4e08 lea    ecx,[esi+0x8]
0x6bd187 8d45c8 lea    eax,[ebp-0x38]
0x6bd18a 8955d0 mov    DWORD PTR [ebp-0x30],edx
0x6bd18d e82e671800 call   0x8438c0
0x6bd192 8b4dc8 mov    ecx,DWORD PTR [ebp-0x38]
0x6bd195 3b4e0c cmp    ecx,DWORD PTR [esi+0xc]
0x6bd198 0f84ff000000 je     0x6bd29d
0x6bd19e 8b7910 mov    edi,DWORD PTR [ecx+0x10]
0x6bd1a1 85ff test   edi,edi
0x6bd1a3 742b je     0x6bd1d0
0x6bd1a5 8bb380000000 mov    esi,DWORD PTR [ebx+0x80]
0x6bd1ab 8d4f04 lea    ecx,[edi+0x4]
0x6bd1ae 51 push   ecx
0x6bd1af 8db6e8000000 lea    esi,[esi+0xe8]
0x6bd1b5 e846a60900 call   0x757800
0x6bd1ba 8b8b80000000 mov    ecx,DWORD PTR [ebx+0x80]
0x6bd1c0 8b11 mov    edx,DWORD PTR [ecx]
0x6bd1c2 8b82c8000000 mov    eax,DWORD PTR [edx+0xc8]
0x6bd1c8 ffd0 call   eax
0x6bd1ca 8b35d01bfe00 mov    esi,DWORD PTR ds:0xfe1bd0
0x6bd1d0 8b4dcc mov    ecx,DWORD PTR [ebp-0x34]
0x6bd1d3 8b5124 mov    edx,DWORD PTR [ecx+0x24]
0x6bd1d6 8b83a0000000 mov    eax,DWORD PTR [ebx+0xa0]
0x6bd1dc 8b08 mov    ecx,DWORD PTR [eax]
0x6bd1de 8955c4 mov    DWORD PTR [ebp-0x3c],edx
0x6bd1e1 8d55c8 lea    edx,[ebp-0x38]
0x6bd1e4 894dc8 mov    DWORD PTR [ebp-0x38],ecx
0x6bd1e7 52 push   edx
0x6bd1e8 8d4e08 lea    ecx,[esi+0x8]
0x6bd1eb 8d45d0 lea    eax,[ebp-0x30]
0x6bd1ee e8cd661800 call   0x8438c0
0x6bd1f3 8b760c mov    esi,DWORD PTR [esi+0xc]
0x6bd1f6 8b45d0 mov    eax,DWORD PTR [ebp-0x30]
0x6bd1f9 3bc6 cmp    eax,esi
0x6bd1fb 7425 je     0x6bd222
0x6bd1fd 8b4010 mov    eax,DWORD PTR [eax+0x10]
0x6bd200 85c0 test   eax,eax
0x6bd202 741e je     0x6bd222
0x6bd204 8b706c mov    esi,DWORD PTR [eax+0x6c]
0x6bd207 8b4070 mov    eax,DWORD PTR [eax+0x70]
0x6bd20a 3bf0 cmp    esi,eax
0x6bd20c 7414 je     0x6bd222
0x6bd20e 8bff mov    edi,edi
0x6bd210 8b4dc4 mov    ecx,DWORD PTR [ebp-0x3c]
0x6bd213 390e cmp    DWORD PTR [esi],ecx
0x6bd215 0f8489000000 je     0x6bd2a4
0x6bd21b 83c610 add    esi,0x10
0x6bd21e 3bf0 cmp    esi,eax
0x6bd220 75ee jne    0x6bd210
0x6bd222 8b9b8c000000 mov    ebx,DWORD PTR [ebx+0x8c]
0x6bd228 8b13 mov    edx,DWORD PTR [ebx]
0x6bd22a 8b82d4000000 mov    eax,DWORD PTR [edx+0xd4]
0x6bd230 8bcb mov    ecx,ebx
0x6bd232 ffd0 call   eax
0x6bd234 f605a472fb0001 test   BYTE PTR ds:0xfb72a4,0x1
0x6bd23b 7527 jne    0x6bd264
0x6bd23d 830da472fb0001 or     DWORD PTR ds:0xfb72a4,0x1
0x6bd244 c745fc03000000 mov    DWORD PTR [ebp-0x4],0x3
0x6bd24b e80026deff call   0x49f850
0x6bd250 68e0cfbc00 push   0xbccfe0
0x6bd255 e8c0501d00 call   0x89231a
0x6bd25a 83c404 add    esp,0x4
0x6bd25d c745fcffffffff mov    DWORD PTR [ebp-0x4],0xffffffff
0x6bd264 8b4dcc mov    ecx,DWORD PTR [ebp-0x34]
0x6bd267 8b09 mov    ecx,DWORD PTR [ecx]
0x6bd269 68a872fb00 push   0xfb72a8
0x6bd26e e85d2cdeff call   0x49fed0
0x6bd273 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x6bd276 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x6bd27d 59 pop    ecx
0x6bd27e 5f pop    edi
0x6bd27f 5e pop    esi
0x6bd280 5b pop    ebx
0x6bd281 8b4df0 mov    ecx,DWORD PTR [ebp-0x10]
0x6bd284 33cd xor    ecx,ebp
0x6bd286 e8763d1d00 call   0x891001
0x6bd28b 8be5 mov    esp,ebp
0x6bd28d 5d pop    ebp
0x6bd28e c20400 ret    0x4
0x6bd291 c745cc00000000 mov    DWORD PTR [ebp-0x34],0x0
0x6bd298 e9dbfeffff jmp    0x6bd178
0x6bd29d 33ff xor    edi,edi
0x6bd29f e92cffffff jmp    0x6bd1d0
0x6bd2a4 8b8b8c000000 mov    ecx,DWORD PTR [ebx+0x8c]
0x6bd2aa 8b11 mov    edx,DWORD PTR [ecx]
0x6bd2ac 8b82d0000000 mov    eax,DWORD PTR [edx+0xd0]
0x6bd2b2 8975d0 mov    DWORD PTR [ebp-0x30],esi
0x6bd2b5 ffd0 call   eax
0x6bd2b7 83ec1c sub    esp,0x1c
0x6bd2ba 8bcc mov    ecx,esp
0x6bd2bc 8965c4 mov    DWORD PTR [ebp-0x3c],esp
0x6bd2bf 6aff push   0xffffffff
0x6bd2c1 6a00 push   0x0
0x6bd2c3 83c750 add    edi,0x50
0x6bd2c6 c741140f000000 mov    DWORD PTR [ecx+0x14],0xf
0x6bd2cd c7411000000000 mov    DWORD PTR [ecx+0x10],0x0
0x6bd2d4 57 push   edi
0x6bd2d5 c60100 mov    BYTE PTR [ecx],0x0
0x6bd2d8 e8635dd4ff call   0x403040
0x6bd2dd 8d4dd4 lea    ecx,[ebp-0x2c]
0x6bd2e0 e8db10dbff call   0x46e3c0
0x6bd2e5 83c41c add    esp,0x1c
0x6bd2e8 b901000000 mov    ecx,0x1
0x6bd2ed 894dfc mov    DWORD PTR [ebp-0x4],ecx
0x6bd2f0 83781408 cmp    DWORD PTR [eax+0x14],0x8
0x6bd2f4 7204 jb     0x6bd2fa
0x6bd2f6 8b38 mov    edi,DWORD PTR [eax]
0x6bd2f8 eb02 jmp    0x6bd2fc
0x6bd2fa 8bf8 mov    edi,eax
0x6bd2fc 840d9443f900 test   BYTE PTR ds:0xf94394,cl
0x6bd302 7520 jne    0x6bd324
0x6bd304 090d9443f900 or     DWORD PTR ds:0xf94394,ecx
0x6bd30a c645fc02 mov    BYTE PTR [ebp-0x4],0x2
0x6bd30e e8cd6af0ff call   0x5c3de0
0x6bd313 6830ccbc00 push   0xbccc30
0x6bd318 e8fd4f1d00 call   0x89231a
0x6bd31d 83c404 add    esp,0x4
0x6bd320 c645fc01 mov    BYTE PTR [ebp-0x4],0x1
0x6bd324 8b760c mov    esi,DWORD PTR [esi+0xc]
0x6bd327 8bd7 mov    edx,edi
0x6bd329 bf9843f900 mov    edi,0xf94398
0x6bd32e e85d9ef0ff call   0x5c7190
0x6bd333 8bf8 mov    edi,eax
0x6bd335 85ff test   edi,edi
0x6bd337 7421 je     0x6bd35a
0x6bd339 8d4dc4 lea    ecx,[ebp-0x3c]
0x6bd33c 51 push   ecx
0x6bd33d 8d4f08 lea    ecx,[edi+0x8]
0x6bd340 8d45c8 lea    eax,[ebp-0x38]
0x6bd343 8975c4 mov    DWORD PTR [ebp-0x3c],esi
0x6bd346 e8b51b1700 call   0x82ef00
0x6bd34b 8b7f0c mov    edi,DWORD PTR [edi+0xc]
0x6bd34e 8b45c8 mov    eax,DWORD PTR [ebp-0x38]
0x6bd351 3bc7 cmp    eax,edi
0x6bd353 7405 je     0x6bd35a
0x6bd355 8b4010 mov    eax,DWORD PTR [eax+0x10]
0x6bd358 eb02 jmp    0x6bd35c
0x6bd35a 33c0 xor    eax,eax
0x6bd35c 8b8b8c000000 mov    ecx,DWORD PTR [ebx+0x8c]
0x6bd362 e8f97c0800 call   0x745060
0x6bd367 c745fcffffffff mov    DWORD PTR [ebp-0x4],0xffffffff
0x6bd36e 837de808 cmp    DWORD PTR [ebp-0x18],0x8
0x6bd372 720c jb     0x6bd380
0x6bd374 8b55d4 mov    edx,DWORD PTR [ebp-0x2c]
0x6bd377 52 push   edx
0x6bd378 e88f3e1d00 call   0x89120c
0x6bd37d 83c404 add    esp,0x4
0x6bd380 8b8b88000000 mov    ecx,DWORD PTR [ebx+0x88]
0x6bd386 8bb38c000000 mov    esi,DWORD PTR [ebx+0x8c]
0x6bd38c 33c0 xor    eax,eax
0x6bd38e 668945d4 mov    WORD PTR [ebp-0x2c],ax
0x6bd392 8b4110 mov    eax,DWORD PTR [ecx+0x10]
0x6bd395 2b4108 sub    eax,DWORD PTR [ecx+0x8]
0x6bd398 c745e807000000 mov    DWORD PTR [ebp-0x18],0x7
0x6bd39f c745e400000000 mov    DWORD PTR [ebp-0x1c],0x0
0x6bd3a6 e8a5c80800 call   0x749c50
0x6bd3ab 8b8b88000000 mov    ecx,DWORD PTR [ebx+0x88]
0x6bd3b1 8b4114 mov    eax,DWORD PTR [ecx+0x14]
0x6bd3b4 2b410c sub    eax,DWORD PTR [ecx+0xc]
0x6bd3b7 8bb38c000000 mov    esi,DWORD PTR [ebx+0x8c]
0x6bd3bd e83ec90800 call   0x749d00
0x6bd3c2 8b8388000000 mov    eax,DWORD PTR [ebx+0x88]
0x6bd3c8 8b500c mov    edx,DWORD PTR [eax+0xc]
0x6bd3cb 8b4dd0 mov    ecx,DWORD PTR [ebp-0x30]
0x6bd3ce 035108 add    edx,DWORD PTR [ecx+0x8]
0x6bd3d1 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x6bd3d4 034104 add    eax,DWORD PTR [ecx+0x4]
0x6bd3d7 8bb38c000000 mov    esi,DWORD PTR [ebx+0x8c]
0x6bd3dd 52 push   edx
0x6bd3de 50 push   eax
0x6bd3df e81cc60800 call   0x749a00
0x6bd3e4 8b9b8c000000 mov    ebx,DWORD PTR [ebx+0x8c]
0x6bd3ea 8b13 mov    edx,DWORD PTR [ebx]
0x6bd3ec 8b82c8000000 mov    eax,DWORD PTR [edx+0xc8]
0x6bd3f2 e939feffff jmp    0x6bd230

; talk_next [0x6bd400,0x6bd4bb)
0x6bd400 51 push   ecx
0x6bd401 8b879c000000 mov    eax,DWORD PTR [edi+0x9c]
0x6bd407 53 push   ebx
0x6bd408 56 push   esi
0x6bd409 85c0 test   eax,eax
0x6bd40b 0f84a6000000 je     0x6bd4b7
0x6bd411 83bf9400000000 cmp    DWORD PTR [edi+0x94],0x0
0x6bd418 7456 je     0x6bd470
0x6bd41a 83780801 cmp    DWORD PTR [eax+0x8],0x1
0x6bd41e 7545 jne    0x6bd465
0x6bd420 8b400c mov    eax,DWORD PTR [eax+0xc]
0x6bd423 85c0 test   eax,eax
0x6bd425 742e je     0x6bd455
0x6bd427 8b35d01bfe00 mov    esi,DWORD PTR ds:0xfe1bd0
0x6bd42d 50 push   eax
0x6bd42e e80d9ce6ff call   0x527040
0x6bd433 85c0 test   eax,eax
0x6bd435 741e je     0x6bd455
0x6bd437 83c004 add    eax,0x4
0x6bd43a 83781408 cmp    DWORD PTR [eax+0x14],0x8
0x6bd43e 7202 jb     0x6bd442
0x6bd440 8b00 mov    eax,DWORD PTR [eax]
0x6bd442 8bb784000000 mov    esi,DWORD PTR [edi+0x84]
0x6bd448 81c6e8000000 add    esi,0xe8
0x6bd44e 8bc8 mov    ecx,eax
0x6bd450 e8bba20900 call   0x757710
0x6bd455 8b07 mov    eax,DWORD PTR [edi]
0x6bd457 8b90d0000000 mov    edx,DWORD PTR [eax+0xd0]
0x6bd45d 8bcf mov    ecx,edi
0x6bd45f ffd2 call   edx
0x6bd461 5e pop    esi
0x6bd462 5b pop    ebx
0x6bd463 59 pop    ecx
0x6bd464 c3 ret
0x6bd465 8bcf mov    ecx,edi
0x6bd467 e8b4020000 call   0x6bd720
0x6bd46c 5e pop    esi
0x6bd46d 5b pop    ebx
0x6bd46e 59 pop    ecx
0x6bd46f c3 ret
0x6bd470 be01000000 mov    esi,0x1
0x6bd475 01b798000000 add    DWORD PTR [edi+0x98],esi
0x6bd47b 8b5810 mov    ebx,DWORD PTR [eax+0x10]
0x6bd47e 8b8f98000000 mov    ecx,DWORD PTR [edi+0x98]
0x6bd484 8d1449 lea    edx,[ecx+ecx*2]
0x6bd487 8d1493 lea    edx,[ebx+edx*4]
0x6bd48a 8997a0000000 mov    DWORD PTR [edi+0xa0],edx
0x6bd490 8b5014 mov    edx,DWORD PTR [eax+0x14]
0x6bd493 2b5010 sub    edx,DWORD PTR [eax+0x10]
0x6bd496 b8abaaaa2a mov    eax,0x2aaaaaab
0x6bd49b f7ea imul   edx
0x6bd49d d1fa sar    edx,1
0x6bd49f 8bc2 mov    eax,edx
0x6bd4a1 c1e81f shr    eax,0x1f
0x6bd4a4 03c2 add    eax,edx
0x6bd4a6 41 inc    ecx
0x6bd4a7 3bc1 cmp    eax,ecx
0x6bd4a9 7f06 jg     0x6bd4b1
0x6bd4ab 89b794000000 mov    DWORD PTR [edi+0x94],esi
0x6bd4b1 57 push   edi
0x6bd4b2 e899fbffff call   0x6bd050
0x6bd4b7 5e pop    esi
0x6bd4b8 5b pop    ebx
0x6bd4b9 59 pop    ecx
0x6bd4ba c3 ret

; talk_event [0x6bd4c0,0x6bd4e2)
0x6bd4c0 55 push   ebp
0x6bd4c1 8bec mov    ebp,esp
0x6bd4c3 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x6bd4c6 83781064 cmp    DWORD PTR [eax+0x10],0x64
0x6bd4ca 7512 jne    0x6bd4de
0x6bd4cc 80b9a800000000 cmp    BYTE PTR [ecx+0xa8],0x0
0x6bd4d3 7409 je     0x6bd4de
0x6bd4d5 57 push   edi
0x6bd4d6 8bf9 mov    edi,ecx
0x6bd4d8 e823ffffff call   0x6bd400
0x6bd4dd 5f pop    edi
0x6bd4de 5d pop    ebp
0x6bd4df c20400 ret    0x4

; talk_initialize [0x6bd4f0,0x6bd540)
0x6bd4f0 56 push   esi
0x6bd4f1 57 push   edi
0x6bd4f2 8bf1 mov    esi,ecx
0x6bd4f4 684c040000 push   0x44c
0x6bd4f9 8dbe84000000 lea    edi,[esi+0x84]
0x6bd4ff e86cf0d7ff call   0x43c570
0x6bd504 68b0040000 push   0x4b0
0x6bd509 8dbe80000000 lea    edi,[esi+0x80]
0x6bd50f 8bce mov    ecx,esi
0x6bd511 e85af0d7ff call   0x43c570
0x6bd516 68d0070000 push   0x7d0
0x6bd51b 8dbe88000000 lea    edi,[esi+0x88]
0x6bd521 8bce mov    ecx,esi
0x6bd523 e8c8e1daff call   0x46b6f0
0x6bd528 6834080000 push   0x834
0x6bd52d 8dbe8c000000 lea    edi,[esi+0x8c]
0x6bd533 8bce mov    ecx,esi
0x6bd535 e8b6e1daff call   0x46b6f0
0x6bd53a 83c410 add    esp,0x10
0x6bd53d 5f pop    edi
0x6bd53e 5e pop    esi
0x6bd53f c3 ret

; talk_child_style [0x6bd540,0x6bd592)
0x6bd540 56 push   esi
0x6bd541 8bf1 mov    esi,ecx
0x6bd543 57 push   edi
0x6bd544 8bbe88000000 mov    edi,DWORD PTR [esi+0x88]
0x6bd54a 686bbf0000 push   0xbf6b
0x6bd54f b802000000 mov    eax,0x2
0x6bd554 8bcf mov    ecx,edi
0x6bd556 e8556f0800 call   0x7444b0
0x6bd55b c687a400000001 mov    BYTE PTR [edi+0xa4],0x1
0x6bd562 8bbe8c000000 mov    edi,DWORD PTR [esi+0x8c]
0x6bd568 686bbf0000 push   0xbf6b
0x6bd56d b802000000 mov    eax,0x2
0x6bd572 8bcf mov    ecx,edi
0x6bd574 e8376f0800 call   0x7444b0
0x6bd579 c687a400000001 mov    BYTE PTR [edi+0xa4],0x1
0x6bd580 8b8e88000000 mov    ecx,DWORD PTR [esi+0x88]
0x6bd586 8b01 mov    eax,DWORD PTR [ecx]
0x6bd588 8b90d0000000 mov    edx,DWORD PTR [eax+0xd0]
0x6bd58e 5f pop    edi
0x6bd58f 5e pop    esi
0x6bd590 ffe2 jmp    edx

; talk_key [0x6bd5a0,0x6bd61b)
0x6bd5a0 55 push   ebp
0x6bd5a1 8bec mov    ebp,esp
0x6bd5a3 80b9a800000000 cmp    BYTE PTR [ecx+0xa8],0x0
0x6bd5aa 7469 je     0x6bd615
0x6bd5ac 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x6bd5af 83f80d cmp    eax,0xd
0x6bd5b2 7458 je     0x6bd60c
0x6bd5b4 3dfa2a0000 cmp    eax,0x2afa
0x6bd5b9 7406 je     0x6bd5c1
0x6bd5bb 32c0 xor    al,al
0x6bd5bd 5d pop    ebp
0x6bd5be c20400 ret    0x4
0x6bd5c1 6a14 push   0x14
0x6bd5c3 e8a03c1d00 call   0x891268
0x6bd5c8 83c404 add    esp,0x4
0x6bd5cb 85c0 test   eax,eax
0x6bd5cd 742c je     0x6bd5fb
0x6bd5cf 83c9ff or     ecx,0xffffffff
0x6bd5d2 56 push   esi
0x6bd5d3 8bf0 mov    esi,eax
0x6bd5d5 c7000c7bc400 mov    DWORD PTR [eax],0xc47b0c
0x6bd5db 894804 mov    DWORD PTR [eax+0x4],ecx
0x6bd5de 894808 mov    DWORD PTR [eax+0x8],ecx
0x6bd5e1 c7400c00000000 mov    DWORD PTR [eax+0xc],0x0
0x6bd5e8 c74010e5430f00 mov    DWORD PTR [eax+0x10],0xf43e5
0x6bd5ef e8ac9cd4ff call   0x4072a0
0x6bd5f4 5e pop    esi
0x6bd5f5 b001 mov    al,0x1
0x6bd5f7 5d pop    ebp
0x6bd5f8 c20400 ret    0x4
0x6bd5fb 33c0 xor    eax,eax
0x6bd5fd 56 push   esi
0x6bd5fe 8bf0 mov    esi,eax
0x6bd600 e89b9cd4ff call   0x4072a0
0x6bd605 5e pop    esi
0x6bd606 b001 mov    al,0x1
0x6bd608 5d pop    ebp
0x6bd609 c20400 ret    0x4
0x6bd60c 57 push   edi
0x6bd60d 8bf9 mov    edi,ecx
0x6bd60f e8ecfdffff call   0x6bd400
0x6bd614 5f pop    edi
0x6bd615 b001 mov    al,0x1
0x6bd617 5d pop    ebp
0x6bd618 c20400 ret    0x4

; talk_open [0x6bd620,0x6bd6af)
0x6bd620 55 push   ebp
0x6bd621 8bec mov    ebp,esp
0x6bd623 53 push   ebx
0x6bd624 b801000000 mov    eax,0x1
0x6bd629 56 push   esi
0x6bd62a 57 push   edi
0x6bd62b 8bd9 mov    ebx,ecx
0x6bd62d 8405ec1afc00 test   BYTE PTR ds:0xfc1aec,al
0x6bd633 7524 jne    0x6bd659
0x6bd635 0905ec1afc00 or     DWORD PTR ds:0xfc1aec,eax
0x6bd63b 33c0 xor    eax,eax
0x6bd63d 6810ddbc00 push   0xbcdd10
0x6bd642 a3f01afc00 mov    ds:0xfc1af0,eax
0x6bd647 a3f41afc00 mov    ds:0xfc1af4,eax
0x6bd64c a3f81afc00 mov    ds:0xfc1af8,eax
0x6bd651 e8c44c1d00 call   0x89231a
0x6bd656 83c404 add    esp,0x4
0x6bd659 8b0df41afc00 mov    ecx,DWORD PTR ds:0xfc1af4
0x6bd65f a1f01afc00 mov    eax,ds:0xfc1af0
0x6bd664 33d2 xor    edx,edx
0x6bd666 3bc1 cmp    eax,ecx
0x6bd668 7418 je     0x6bd682
0x6bd66a 8b750c mov    esi,DWORD PTR [ebp+0xc]
0x6bd66d 8b7d08 mov    edi,DWORD PTR [ebp+0x8]
0x6bd670 3938 cmp    DWORD PTR [eax],edi
0x6bd672 7507 jne    0x6bd67b
0x6bd674 397004 cmp    DWORD PTR [eax+0x4],esi
0x6bd677 7502 jne    0x6bd67b
0x6bd679 8bd0 mov    edx,eax
0x6bd67b 83c020 add    eax,0x20
0x6bd67e 3bc1 cmp    eax,ecx
0x6bd680 75ee jne    0x6bd670
0x6bd682 89939c000000 mov    DWORD PTR [ebx+0x9c],edx
0x6bd688 85d2 test   edx,edx
0x6bd68a 741c je     0x6bd6a8
0x6bd68c 8a4510 mov    al,BYTE PTR [ebp+0x10]
0x6bd68f 8883a8000000 mov    BYTE PTR [ebx+0xa8],al
0x6bd695 ff15a025bd00 call   DWORD PTR ds:0xbd25a0
0x6bd69b 8bcb mov    ecx,ebx
0x6bd69d 8983a4000000 mov    DWORD PTR [ebx+0xa4],eax
0x6bd6a3 e808000000 call   0x6bd6b0
0x6bd6a8 5f pop    edi
0x6bd6a9 5e pop    esi
0x6bd6aa 5b pop    ebx
0x6bd6ab 5d pop    ebp
0x6bd6ac c20c00 ret    0xc

; talk_start [0x6bd6b0,0x6bd716)
0x6bd6b0 56 push   esi
0x6bd6b1 8bf1 mov    esi,ecx
0x6bd6b3 83be9c00000000 cmp    DWORD PTR [esi+0x9c],0x0
0x6bd6ba 7458 je     0x6bd714
0x6bd6bc 8b06 mov    eax,DWORD PTR [esi]
0x6bd6be 8b90d0000000 mov    edx,DWORD PTR [eax+0xd0]
0x6bd6c4 ffd2 call   edx
0x6bd6c6 8b869c000000 mov    eax,DWORD PTR [esi+0x9c]
0x6bd6cc c7869800000000000000 mov    DWORD PTR [esi+0x98],0x0
0x6bd6d6 c7869400000000000000 mov    DWORD PTR [esi+0x94],0x0
0x6bd6e0 8b4810 mov    ecx,DWORD PTR [eax+0x10]
0x6bd6e3 898ea0000000 mov    DWORD PTR [esi+0xa0],ecx
0x6bd6e9 8b4814 mov    ecx,DWORD PTR [eax+0x14]
0x6bd6ec 2b4810 sub    ecx,DWORD PTR [eax+0x10]
0x6bd6ef b8abaaaa2a mov    eax,0x2aaaaaab
0x6bd6f4 f7e9 imul   ecx
0x6bd6f6 d1fa sar    edx,1
0x6bd6f8 8bc2 mov    eax,edx
0x6bd6fa c1e81f shr    eax,0x1f
0x6bd6fd 03c2 add    eax,edx
0x6bd6ff 83f801 cmp    eax,0x1
0x6bd702 7f0a jg     0x6bd70e
0x6bd704 c7869400000001000000 mov    DWORD PTR [esi+0x94],0x1
0x6bd70e 56 push   esi
0x6bd70f e83cf9ffff call   0x6bd050
0x6bd714 5e pop    esi
0x6bd715 c3 ret

; talk_hide [0x6bd720,0x6bd7e7)
0x6bd720 55 push   ebp
0x6bd721 8bec mov    ebp,esp
0x6bd723 6aff push   0xffffffff
0x6bd725 687ca79300 push   0x93a77c
0x6bd72a 64a100000000 mov    eax,fs:0x0
0x6bd730 50 push   eax
0x6bd731 51 push   ecx
0x6bd732 56 push   esi
0x6bd733 a1201fd600 mov    eax,ds:0xd61f20
0x6bd738 33c5 xor    eax,ebp
0x6bd73a 50 push   eax
0x6bd73b 8d45f4 lea    eax,[ebp-0xc]
0x6bd73e 64a300000000 mov    fs:0x0,eax
0x6bd744 8bf1 mov    esi,ecx
0x6bd746 f605a472fb0001 test   BYTE PTR ds:0xfb72a4,0x1
0x6bd74d 7527 jne    0x6bd776
0x6bd74f 830da472fb0001 or     DWORD PTR ds:0xfb72a4,0x1
0x6bd756 c745fc00000000 mov    DWORD PTR [ebp-0x4],0x0
0x6bd75d e8ee20deff call   0x49f850
0x6bd762 68e0cfbc00 push   0xbccfe0
0x6bd767 e8ae4b1d00 call   0x89231a
0x6bd76c 83c404 add    esp,0x4
0x6bd76f c745fcffffffff mov    DWORD PTR [ebp-0x4],0xffffffff
0x6bd776 baa872fb00 mov    edx,0xfb72a8
0x6bd77b e8c02ddeff call   0x4a0540
0x6bd780 f605d4f3fd0001 test   BYTE PTR ds:0xfdf3d4,0x1
0x6bd787 7527 jne    0x6bd7b0
0x6bd789 b801000000 mov    eax,0x1
0x6bd78e 0905d4f3fd00 or     DWORD PTR ds:0xfdf3d4,eax
0x6bd794 8945fc mov    DWORD PTR [ebp-0x4],eax
0x6bd797 e8e46b0300 call   0x6f4380
0x6bd79c 68d0e6bc00 push   0xbce6d0
0x6bd7a1 e8744b1d00 call   0x89231a
0x6bd7a6 83c404 add    esp,0x4
0x6bd7a9 c745fcffffffff mov    DWORD PTR [ebp-0x4],0xffffffff
0x6bd7b0 68ac02c100 push   0xc102ac
0x6bd7b5 6a00 push   0x0
0x6bd7b7 68c8f3fd00 push   0xfdf3c8
0x6bd7bc e8dff8deff call   0x4ad0a0
0x6bd7c1 8b06 mov    eax,DWORD PTR [esi]
0x6bd7c3 8b90d4000000 mov    edx,DWORD PTR [eax+0xd4]
0x6bd7c9 8bce mov    ecx,esi
0x6bd7cb ffd2 call   edx
0x6bd7cd c7869c00000000000000 mov    DWORD PTR [esi+0x9c],0x0
0x6bd7d7 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x6bd7da 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x6bd7e1 59 pop    ecx
0x6bd7e2 5e pop    esi
0x6bd7e3 8be5 mov    esp,ebp
0x6bd7e5 5d pop    ebp
0x6bd7e6 c3 ret

; talk_hide_other_ui [0x6bd7f0,0x6bd9a5)
0x6bd7f0 55 push   ebp
0x6bd7f1 8bec mov    ebp,esp
0x6bd7f3 83e4f8 and    esp,0xfffffff8
0x6bd7f6 6aff push   0xffffffff
0x6bd7f8 68b02a9200 push   0x922ab0
0x6bd7fd 64a100000000 mov    eax,fs:0x0
0x6bd803 50 push   eax
0x6bd804 83ec2c sub    esp,0x2c
0x6bd807 53 push   ebx
0x6bd808 56 push   esi
0x6bd809 a1201fd600 mov    eax,ds:0xd61f20
0x6bd80e 33c4 xor    eax,esp
0x6bd810 50 push   eax
0x6bd811 8d442438 lea    eax,[esp+0x38]
0x6bd815 64a300000000 mov    fs:0x0,eax
0x6bd81b 33f6 xor    esi,esi
0x6bd81d 6a14 push   0x14
0x6bd81f 89742430 mov    DWORD PTR [esp+0x30],esi
0x6bd823 e8403a1d00 call   0x891268
0x6bd828 83c404 add    esp,0x4
0x6bd82b 3bc6 cmp    eax,esi
0x6bd82d 0f8449010000 je     0x6bd97c
0x6bd833 89442428 mov    DWORD PTR [esp+0x28],eax
0x6bd837 8900 mov    DWORD PTR [eax],eax
0x6bd839 8b442428 mov    eax,DWORD PTR [esp+0x28]
0x6bd83d 894004 mov    DWORD PTR [eax+0x4],eax
0x6bd840 8b442428 mov    eax,DWORD PTR [esp+0x28]
0x6bd844 894008 mov    DWORD PTR [eax+0x8],eax
0x6bd847 8b442428 mov    eax,DWORD PTR [esp+0x28]
0x6bd84b bb01000000 mov    ebx,0x1
0x6bd850 885810 mov    BYTE PTR [eax+0x10],bl
0x6bd853 8b4c2428 mov    ecx,DWORD PTR [esp+0x28]
0x6bd857 885911 mov    BYTE PTR [ecx+0x11],bl
0x6bd85a 89742440 mov    DWORD PTR [esp+0x40],esi
0x6bd85e 8d54240c lea    edx,[esp+0xc]
0x6bd862 52 push   edx
0x6bd863 8d742428 lea    esi,[esp+0x28]
0x6bd867 c7442410d4000000 mov    DWORD PTR [esp+0x10],0xd4
0x6bd86f e8cc050000 call   0x6bde40
0x6bd874 50 push   eax
0x6bd875 8bc6 mov    eax,esi
0x6bd877 50 push   eax
0x6bd878 8d742414 lea    esi,[esp+0x14]
0x6bd87c e84fe3d8ff call   0x44bbd0
0x6bd881 8d4c240c lea    ecx,[esp+0xc]
0x6bd885 51 push   ecx
0x6bd886 8d742428 lea    esi,[esp+0x28]
0x6bd88a c7442410d3000000 mov    DWORD PTR [esp+0x10],0xd3
0x6bd892 e8a9050000 call   0x6bde40
0x6bd897 8bd6 mov    edx,esi
0x6bd899 50 push   eax
0x6bd89a 52 push   edx
0x6bd89b 8d742414 lea    esi,[esp+0x14]
0x6bd89f e82ce3d8ff call   0x44bbd0
0x6bd8a4 8d44240c lea    eax,[esp+0xc]
0x6bd8a8 50 push   eax
0x6bd8a9 8d742428 lea    esi,[esp+0x28]
0x6bd8ad c744241093000000 mov    DWORD PTR [esp+0x10],0x93
0x6bd8b5 e886050000 call   0x6bde40
0x6bd8ba 8bce mov    ecx,esi
0x6bd8bc 50 push   eax
0x6bd8bd 51 push   ecx
0x6bd8be 8d742414 lea    esi,[esp+0x14]
0x6bd8c2 e809e3d8ff call   0x44bbd0
0x6bd8c7 8d54240c lea    edx,[esp+0xc]
0x6bd8cb 52 push   edx
0x6bd8cc 8d742428 lea    esi,[esp+0x28]
0x6bd8d0 c744241092000000 mov    DWORD PTR [esp+0x10],0x92
0x6bd8d8 e863050000 call   0x6bde40
0x6bd8dd 50 push   eax
0x6bd8de 8bc6 mov    eax,esi
0x6bd8e0 50 push   eax
0x6bd8e1 8d742414 lea    esi,[esp+0x14]
0x6bd8e5 e8e6e2d8ff call   0x44bbd0
0x6bd8ea 8d4c240c lea    ecx,[esp+0xc]
0x6bd8ee 51 push   ecx
0x6bd8ef 8d742428 lea    esi,[esp+0x28]
0x6bd8f3 c74424101c010000 mov    DWORD PTR [esp+0x10],0x11c
0x6bd8fb e840050000 call   0x6bde40
0x6bd900 8bd6 mov    edx,esi
0x6bd902 50 push   eax
0x6bd903 52 push   edx
0x6bd904 8d742414 lea    esi,[esp+0x14]
0x6bd908 e8c3e2d8ff call   0x44bbd0
0x6bd90d 841dd4adfa00 test   BYTE PTR ds:0xfaadd4,bl
0x6bd913 7521 jne    0x6bd936
0x6bd915 091dd4adfa00 or     DWORD PTR ds:0xfaadd4,ebx
0x6bd91b 885c2440 mov    BYTE PTR [esp+0x40],bl
0x6bd91f e85c9becff call   0x587480
0x6bd924 68c0ccbc00 push   0xbcccc0
0x6bd929 e8ec491d00 call   0x89231a
0x6bd92e 83c404 add    esp,0x4
0x6bd931 c644244000 mov    BYTE PTR [esp+0x40],0x0
0x6bd936 8d442424 lea    eax,[esp+0x24]
0x6bd93a 50 push   eax
0x6bd93b e810dbecff call   0x58b450
0x6bd940 c744244002000000 mov    DWORD PTR [esp+0x40],0x2
0x6bd948 8b442428 mov    eax,DWORD PTR [esp+0x28]
0x6bd94c 8b08 mov    ecx,DWORD PTR [eax]
0x6bd94e 50 push   eax
0x6bd94f 51 push   ecx
0x6bd950 8d74241c lea    esi,[esp+0x1c]
0x6bd954 8d44242c lea    eax,[esp+0x2c]
0x6bd958 e803c8e0ff call   0x4ca160
0x6bd95d 8b4c2428 mov    ecx,DWORD PTR [esp+0x28]
0x6bd961 51 push   ecx
0x6bd962 e8a5381d00 call   0x89120c
0x6bd967 83c404 add    esp,0x4
0x6bd96a 8b4c2438 mov    ecx,DWORD PTR [esp+0x38]
0x6bd96e 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x6bd975 59 pop    ecx
0x6bd976 5e pop    esi
0x6bd977 5b pop    ebx
0x6bd978 8be5 mov    esp,ebp
0x6bd97a 5d pop    ebp
0x6bd97b c3 ret
0x6bd97c 8d542414 lea    edx,[esp+0x14]
0x6bd980 52 push   edx
0x6bd981 8d4c241c lea    ecx,[esp+0x1c]
0x6bd985 89742418 mov    DWORD PTR [esp+0x18],esi
0x6bd989 e81b371d00 call   0x8910a9
0x6bd98e 68a857c800 push   0xc857a8
0x6bd993 8d44241c lea    eax,[esp+0x1c]
0x6bd997 50 push   eax
0x6bd998 c7442420a42cbd00 mov    DWORD PTR [esp+0x20],0xbd2ca4
0x6bd9a0 e84bf01d00 call   0x89c9f0

; talk_show_other_ui [0x6bd9b0,0x6bda19)
0x6bd9b0 55 push   ebp
0x6bd9b1 8bec mov    ebp,esp
0x6bd9b3 6aff push   0xffffffff
0x6bd9b5 689e4d9200 push   0x924d9e
0x6bd9ba 64a100000000 mov    eax,fs:0x0
0x6bd9c0 50 push   eax
0x6bd9c1 a1201fd600 mov    eax,ds:0xd61f20
0x6bd9c6 33c5 xor    eax,ebp
0x6bd9c8 50 push   eax
0x6bd9c9 8d45f4 lea    eax,[ebp-0xc]
0x6bd9cc 64a300000000 mov    fs:0x0,eax
0x6bd9d2 b801000000 mov    eax,0x1
0x6bd9d7 8405d4adfa00 test   BYTE PTR ds:0xfaadd4,al
0x6bd9dd 7526 jne    0x6bda05
0x6bd9df 0905d4adfa00 or     DWORD PTR ds:0xfaadd4,eax
0x6bd9e5 c745fc00000000 mov    DWORD PTR [ebp-0x4],0x0
0x6bd9ec e88f9aecff call   0x587480
0x6bd9f1 68c0ccbc00 push   0xbcccc0
0x6bd9f6 e81f491d00 call   0x89231a
0x6bd9fb 83c404 add    esp,0x4
0x6bd9fe c745fcffffffff mov    DWORD PTR [ebp-0x4],0xffffffff
0x6bda05 e806dbecff call   0x58b510
0x6bda0a 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x6bda0d 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x6bda14 59 pop    ecx
0x6bda15 8be5 mov    esp,ebp
0x6bda17 5d pop    ebp
0x6bda18 c3 ret

; talk_register_receiver [0x6bda20,0x6bdaf5)
0x6bda20 55 push   ebp
0x6bda21 8bec mov    ebp,esp
0x6bda23 51 push   ecx
0x6bda24 53 push   ebx
0x6bda25 8b5d0c mov    ebx,DWORD PTR [ebp+0xc]
0x6bda28 56 push   esi
0x6bda29 8b33 mov    esi,DWORD PTR [ebx]
0x6bda2b a38031fe00 mov    ds:0xfe3180,eax
0x6bda30 8b4610 mov    eax,DWORD PTR [esi+0x10]
0x6bda33 8b4844 mov    ecx,DWORD PTR [eax+0x44]
0x6bda36 57 push   edi
0x6bda37 891d7c31fe00 mov    DWORD PTR ds:0xfe317c,ebx
0x6bda3d 3b4840 cmp    ecx,DWORD PTR [eax+0x40]
0x6bda40 7207 jb     0x6bda49
0x6bda42 8bc6 mov    eax,esi
0x6bda44 e857d90300 call   0x6fb3a0
0x6bda49 8b7e08 mov    edi,DWORD PTR [esi+0x8]
0x6bda4c 6a00 push   0x0
0x6bda4e 6a00 push   0x0
0x6bda50 56 push   esi
0x6bda51 e84abf0300 call   0x6f99a0
0x6bda56 8907 mov    DWORD PTR [edi],eax
0x6bda58 c7470805000000 mov    DWORD PTR [edi+0x8],0x5
0x6bda5f 83460810 add    DWORD PTR [esi+0x8],0x10
0x6bda63 8b33 mov    esi,DWORD PTR [ebx]
0x6bda65 83c40c add    esp,0xc
0x6bda68 bf28ebc300 mov    edi,0xc3eb28
0x6bda6d b8eed8ffff mov    eax,0xffffd8ee
0x6bda72 e8197d0300 call   0x6f5790
0x6bda77 8b33 mov    esi,DWORD PTR [ebx]
0x6bda79 b8eed8ffff mov    eax,0xffffd8ee
0x6bda7e e8fd7b0300 call   0x6f5680
0x6bda83 8b03 mov    eax,DWORD PTR [ebx]
0x6bda85 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x6bda88 83e810 sub    eax,0x10
0x6bda8b bff0ffffff mov    edi,0xfffffff0
0x6bda90 3dc8bfc000 cmp    eax,0xc0bfc8
0x6bda95 7406 je     0x6bda9d
0x6bda97 83780805 cmp    DWORD PTR [eax+0x8],0x5
0x6bda9b 7417 je     0x6bdab4
0x6bda9d 6828ebc300 push   0xc3eb28
0x6bdaa2 68c426c400 push   0xc426c4
0x6bdaa7 e811561d00 call   0x8930bd
0x6bdaac 8b03 mov    eax,DWORD PTR [ebx]
0x6bdaae 83c408 add    esp,0x8
0x6bdab1 017808 add    DWORD PTR [eax+0x8],edi
0x6bdab4 8b33 mov    esi,DWORD PTR [ebx]
0x6bdab6 682462c000 push   0xc06224
0x6bdabb e8507a0300 call   0x6f5510
0x6bdac0 8b33 mov    esi,DWORD PTR [ebx]
0x6bdac2 83c404 add    esp,0x4
0x6bdac5 6a00 push   0x0
0x6bdac7 6820de6b00 push   0x6bde20
0x6bdacc e8df7a0300 call   0x6f55b0
0x6bdad1 8b13 mov    edx,DWORD PTR [ebx]
0x6bdad3 52 push   edx
0x6bdad4 b8fdffffff mov    eax,0xfffffffd
0x6bdad9 e8127d0300 call   0x6f57f0
0x6bdade 8b1b mov    ebx,DWORD PTR [ebx]
0x6bdae0 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x6bdae3 83c40c add    esp,0xc
0x6bdae6 017b08 add    DWORD PTR [ebx+0x8],edi
0x6bdae9 5f pop    edi
0x6bdaea 5e pop    esi
0x6bdaeb c70028ebc300 mov    DWORD PTR [eax],0xc3eb28
0x6bdaf1 5b pop    ebx
0x6bdaf2 59 pop    ecx
0x6bdaf3 5d pop    ebp
0x6bdaf4 c3 ret

; talk_rebind [0x6bde20,0x6bde32)
0x6bde20 a17c31fe00 mov    eax,ds:0xfe317c
0x6bde25 e8864ddeff call   0x4a2bb0
0x6bde2a a38031fe00 mov    ds:0xfe3180,eax
0x6bde2f 33c0 xor    eax,eax
0x6bde31 c3 ret

; talk_open_marshaller [0x6be090,0x6be191)
0x6be090 55 push   ebp
0x6be091 8bec mov    ebp,esp
0x6be093 83ec24 sub    esp,0x24
0x6be096 8b0d8031fe00 mov    ecx,DWORD PTR ds:0xfe3180
0x6be09c 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x6be09f a18431fe00 mov    eax,ds:0xfe3184
0x6be0a4 894df0 mov    DWORD PTR [ebp-0x10],ecx
0x6be0a7 8b0a mov    ecx,DWORD PTR [edx]
0x6be0a9 8945ec mov    DWORD PTR [ebp-0x14],eax
0x6be0ac 8b4108 mov    eax,DWORD PTR [ecx+0x8]
0x6be0af 8b50f8 mov    edx,DWORD PTR [eax-0x8]
0x6be0b2 85d2 test   edx,edx
0x6be0b4 7414 je     0x6be0ca
0x6be0b6 83fa01 cmp    edx,0x1
0x6be0b9 7506 jne    0x6be0c1
0x6be0bb 8378f000 cmp    DWORD PTR [eax-0x10],0x0
0x6be0bf 7409 je     0x6be0ca
0x6be0c1 c745f401000000 mov    DWORD PTR [ebp-0xc],0x1
0x6be0c8 eb07 jmp    0x6be0d1
0x6be0ca c745f400000000 mov    DWORD PTR [ebp-0xc],0x0
0x6be0d1 53 push   ebx
0x6be0d2 56 push   esi
0x6be0d3 57 push   edi
0x6be0d4 b8feffffff mov    eax,0xfffffffe
0x6be0d9 e812700300 call   0x6f50f0
0x6be0de 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x6be0e1 83f903 cmp    ecx,0x3
0x6be0e4 742e je     0x6be114
0x6be0e6 83f904 cmp    ecx,0x4
0x6be0e9 0f859a000000 jne    0x6be189
0x6be0ef 8b30 mov    esi,DWORD PTR [eax]
0x6be0f1 83c610 add    esi,0x10
0x6be0f4 8d7df8 lea    edi,[ebp-0x8]
0x6be0f7 e864960300 call   0x6f7760
0x6be0fc 85c0 test   eax,eax
0x6be0fe 0f8485000000 je     0x6be189
0x6be104 dd45f8 fld    QWORD PTR [ebp-0x8]
0x6be107 c745e403000000 mov    DWORD PTR [ebp-0x1c],0x3
0x6be10e dd5ddc fstp   QWORD PTR [ebp-0x24]
0x6be111 8d45dc lea    eax,[ebp-0x24]
0x6be114 dd00 fld    QWORD PTR [eax]
0x6be116 dd5de4 fstp   QWORD PTR [ebp-0x1c]
0x6be119 dd45e4 fld    QWORD PTR [ebp-0x1c]
0x6be11c db5dfc fistp  DWORD PTR [ebp-0x4]
0x6be11f 8b5dfc mov    ebx,DWORD PTR [ebp-0x4]
0x6be122 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x6be125 8b08 mov    ecx,DWORD PTR [eax]
0x6be127 b8fdffffff mov    eax,0xfffffffd
0x6be12c e8bf6f0300 call   0x6f50f0
0x6be131 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x6be134 83f903 cmp    ecx,0x3
0x6be137 7426 je     0x6be15f
0x6be139 83f904 cmp    ecx,0x4
0x6be13c 754f jne    0x6be18d
0x6be13e 8b30 mov    esi,DWORD PTR [eax]
0x6be140 83c610 add    esi,0x10
0x6be143 8d7de4 lea    edi,[ebp-0x1c]
0x6be146 e815960300 call   0x6f7760
0x6be14b 85c0 test   eax,eax
0x6be14d 743e je     0x6be18d
0x6be14f dd45e4 fld    QWORD PTR [ebp-0x1c]
0x6be152 c745e403000000 mov    DWORD PTR [ebp-0x1c],0x3
0x6be159 dd5ddc fstp   QWORD PTR [ebp-0x24]
0x6be15c 8d45dc lea    eax,[ebp-0x24]
0x6be15f dd00 fld    QWORD PTR [eax]
0x6be161 dd5de4 fstp   QWORD PTR [ebp-0x1c]
0x6be164 dd45e4 fld    QWORD PTR [ebp-0x1c]
0x6be167 db5d08 fistp  DWORD PTR [ebp+0x8]
0x6be16a 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x6be16d 837df400 cmp    DWORD PTR [ebp-0xc],0x0
0x6be171 0f95c1 setne  cl
0x6be174 0fb6d1 movzx  edx,cl
0x6be177 8b4df0 mov    ecx,DWORD PTR [ebp-0x10]
0x6be17a 52 push   edx
0x6be17b 53 push   ebx
0x6be17c 50 push   eax
0x6be17d ff55ec call   DWORD PTR [ebp-0x14]
0x6be180 5f pop    edi
0x6be181 5e pop    esi
0x6be182 33c0 xor    eax,eax
0x6be184 5b pop    ebx
0x6be185 8be5 mov    esp,ebp
0x6be187 5d pop    ebp
0x6be188 c3 ret
0x6be189 33db xor    ebx,ebx
0x6be18b eb95 jmp    0x6be122
0x6be18d 33c0 xor    eax,eax
0x6be18f ebdc jmp    0x6be16d

; talk_rect_override [0x636f20,0x636f6d)
0x636f20 55 push   ebp
0x636f21 8bec mov    ebp,esp
0x636f23 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x636f26 56 push   esi
0x636f27 8b7510 mov    esi,DWORD PTR [ebp+0x10]
0x636f2a 8bd6 mov    edx,esi
0x636f2c 2bd0 sub    edx,eax
0x636f2e 81fa00080000 cmp    edx,0x800
0x636f34 7e17 jle    0x636f4d
0x636f36 8d8200f8ffff lea    eax,[edx-0x800]
0x636f3c 99 cdq
0x636f3d 2bc2 sub    eax,edx
0x636f3f d1f8 sar    eax,1
0x636f41 8db000080000 lea    esi,[eax+0x800]
0x636f47 894508 mov    DWORD PTR [ebp+0x8],eax
0x636f4a 897510 mov    DWORD PTR [ebp+0x10],esi
0x636f4d 83ec10 sub    esp,0x10
0x636f50 8bd4 mov    edx,esp
0x636f52 8902 mov    DWORD PTR [edx],eax
0x636f54 8b450c mov    eax,DWORD PTR [ebp+0xc]
0x636f57 894204 mov    DWORD PTR [edx+0x4],eax
0x636f5a 8b4514 mov    eax,DWORD PTR [ebp+0x14]
0x636f5d 897208 mov    DWORD PTR [edx+0x8],esi
0x636f60 89420c mov    DWORD PTR [edx+0xc],eax
0x636f63 e8e82b1100 call   0x749b50
0x636f68 5e pop    esi
0x636f69 5d pop    ebp
0x636f6a c21000 ret    0x10
