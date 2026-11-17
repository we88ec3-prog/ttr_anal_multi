; F_004A1E90 0x4a1e90..0x4a1eec
0x4a1e90 55 push   ebp
0x4a1e91 8bec mov    ebp,esp
0x4a1e93 6aff push   0xffffffff
0x4a1e95 68c8839300 push   0x9383c8
0x4a1e9a 64a100000000 mov    eax,fs:0x0
0x4a1ea0 50 push   eax
0x4a1ea1 83ec0c sub    esp,0xc
0x4a1ea4 a1201fd600 mov    eax,ds:0xd61f20
0x4a1ea9 33c5 xor    eax,ebp
0x4a1eab 50 push   eax
0x4a1eac 8d45f4 lea    eax,[ebp-0xc]
0x4a1eaf 64a300000000 mov    fs:0x0,eax
0x4a1eb5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4a1eb8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4a1ebb 33c0 xor    eax,eax
0x4a1ebd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4a1ec0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4a1ec3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4a1ec6 8b0d7c17fe00 mov    ecx,DWORD PTR ds:0xfe177c
0x4a1ecc 51 push   ecx
0x4a1ecd 8d45e8 lea    eax,[ebp-0x18]
0x4a1ed0 e80b050000 call   0x4a23e0
0x4a1ed5 83c404 add    esp,0x4
0x4a1ed8 b801000000 mov    eax,0x1
0x4a1edd 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4a1ee0 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4a1ee7 59 pop    ecx
0x4a1ee8 8be5 mov    esp,ebp
0x4a1eea 5d pop    ebp
0x4a1eeb c3 ret

; F_004A23E0 0x4a23e0..0x4a2453
0x4a23e0 55 push   ebp
0x4a23e1 8bec mov    ebp,esp
0x4a23e3 8b08 mov    ecx,DWORD PTR [eax]
0x4a23e5 83ec18 sub    esp,0x18
0x4a23e8 53 push   ebx
0x4a23e9 8b1d7817fe00 mov    ebx,DWORD PTR ds:0xfe1778
0x4a23ef 83c8ff or     eax,0xffffffff
0x4a23f2 e8f92c2500 call   0x6f50f0
0x4a23f7 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4a23fa 83f903 cmp    ecx,0x3
0x4a23fd 742a je     0x4a2429
0x4a23ff 83f904 cmp    ecx,0x4
0x4a2402 7540 jne    0x4a2444
0x4a2404 56 push   esi
0x4a2405 8b30 mov    esi,DWORD PTR [eax]
0x4a2407 57 push   edi
0x4a2408 83c610 add    esi,0x10
0x4a240b 8d7df8 lea    edi,[ebp-0x8]
0x4a240e e84d532500 call   0x6f7760
0x4a2413 5f pop    edi
0x4a2414 5e pop    esi
0x4a2415 85c0 test   eax,eax
0x4a2417 742b je     0x4a2444
0x4a2419 dd45f8 fld    QWORD PTR [ebp-0x8]
0x4a241c c745f003000000 mov    DWORD PTR [ebp-0x10],0x3
0x4a2423 dd5de8 fstp   QWORD PTR [ebp-0x18]
0x4a2426 8d45e8 lea    eax,[ebp-0x18]
0x4a2429 dd00 fld    QWORD PTR [eax]
0x4a242b dd5df0 fstp   QWORD PTR [ebp-0x10]
0x4a242e dd45f0 fld    QWORD PTR [ebp-0x10]
0x4a2431 db5dfc fistp  DWORD PTR [ebp-0x4]
0x4a2434 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x4a2437 50 push   eax
0x4a2438 8bcb mov    ecx,ebx
0x4a243a ff5508 call   DWORD PTR [ebp+0x8]
0x4a243d 33c0 xor    eax,eax
0x4a243f 5b pop    ebx
0x4a2440 8be5 mov    esp,ebp
0x4a2442 5d pop    ebp
0x4a2443 c3 ret
0x4a2444 33c0 xor    eax,eax
0x4a2446 50 push   eax
0x4a2447 8bcb mov    ecx,ebx
0x4a2449 ff5508 call   DWORD PTR [ebp+0x8]
0x4a244c 33c0 xor    eax,eax
0x4a244e 5b pop    ebx
0x4a244f 8be5 mov    esp,ebp
0x4a2451 5d pop    ebp
0x4a2452 c3 ret

; F_004A1EF0 0x4a1ef0..0x4a1f46
0x4a1ef0 55 push   ebp
0x4a1ef1 8bec mov    ebp,esp
0x4a1ef3 6aff push   0xffffffff
0x4a1ef5 68c8839300 push   0x9383c8
0x4a1efa 64a100000000 mov    eax,fs:0x0
0x4a1f00 50 push   eax
0x4a1f01 83ec0c sub    esp,0xc
0x4a1f04 a1201fd600 mov    eax,ds:0xd61f20
0x4a1f09 33c5 xor    eax,ebp
0x4a1f0b 50 push   eax
0x4a1f0c 8d45f4 lea    eax,[ebp-0xc]
0x4a1f0f 64a300000000 mov    fs:0x0,eax
0x4a1f15 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4a1f18 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4a1f1b 33c0 xor    eax,eax
0x4a1f1d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4a1f20 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4a1f23 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4a1f26 8b0d7817fe00 mov    ecx,DWORD PTR ds:0xfe1778
0x4a1f2c ff158017fe00 call   DWORD PTR ds:0xfe1780
0x4a1f32 b801000000 mov    eax,0x1
0x4a1f37 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4a1f3a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4a1f41 59 pop    ecx
0x4a1f42 8be5 mov    esp,ebp
0x4a1f44 5d pop    ebp
0x4a1f45 c3 ret

; F_004A1F50 0x4a1f50..0x4a1fac
0x4a1f50 55 push   ebp
0x4a1f51 8bec mov    ebp,esp
0x4a1f53 6aff push   0xffffffff
0x4a1f55 68c8839300 push   0x9383c8
0x4a1f5a 64a100000000 mov    eax,fs:0x0
0x4a1f60 50 push   eax
0x4a1f61 83ec0c sub    esp,0xc
0x4a1f64 a1201fd600 mov    eax,ds:0xd61f20
0x4a1f69 33c5 xor    eax,ebp
0x4a1f6b 50 push   eax
0x4a1f6c 8d45f4 lea    eax,[ebp-0xc]
0x4a1f6f 64a300000000 mov    fs:0x0,eax
0x4a1f75 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4a1f78 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4a1f7b 33c0 xor    eax,eax
0x4a1f7d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4a1f80 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4a1f83 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4a1f86 8b0d8417fe00 mov    ecx,DWORD PTR ds:0xfe1784
0x4a1f8c 51 push   ecx
0x4a1f8d 8d45e8 lea    eax,[ebp-0x18]
0x4a1f90 e84b040000 call   0x4a23e0
0x4a1f95 83c404 add    esp,0x4
0x4a1f98 b801000000 mov    eax,0x1
0x4a1f9d 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4a1fa0 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4a1fa7 59 pop    ecx
0x4a1fa8 8be5 mov    esp,ebp
0x4a1faa 5d pop    ebp
0x4a1fab c3 ret

; F_004A1FB0 0x4a1fb0..0x4a2006
0x4a1fb0 55 push   ebp
0x4a1fb1 8bec mov    ebp,esp
0x4a1fb3 6aff push   0xffffffff
0x4a1fb5 68c8839300 push   0x9383c8
0x4a1fba 64a100000000 mov    eax,fs:0x0
0x4a1fc0 50 push   eax
0x4a1fc1 83ec0c sub    esp,0xc
0x4a1fc4 a1201fd600 mov    eax,ds:0xd61f20
0x4a1fc9 33c5 xor    eax,ebp
0x4a1fcb 50 push   eax
0x4a1fcc 8d45f4 lea    eax,[ebp-0xc]
0x4a1fcf 64a300000000 mov    fs:0x0,eax
0x4a1fd5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4a1fd8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4a1fdb 33c0 xor    eax,eax
0x4a1fdd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4a1fe0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4a1fe3 8d4de8 lea    ecx,[ebp-0x18]
0x4a1fe6 51 push   ecx
0x4a1fe7 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4a1fea e871040000 call   0x4a2460
0x4a1fef 83c404 add    esp,0x4
0x4a1ff2 b801000000 mov    eax,0x1
0x4a1ff7 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4a1ffa 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4a2001 59 pop    ecx
0x4a2002 8be5 mov    esp,ebp
0x4a2004 5d pop    ebp
0x4a2005 c3 ret

; F_004A2460 0x4a2460..0x4a25ea
0x4a2460 55 push   ebp
0x4a2461 8bec mov    ebp,esp
0x4a2463 83ec34 sub    esp,0x34
0x4a2466 a18817fe00 mov    eax,ds:0xfe1788
0x4a246b 8b0d7817fe00 mov    ecx,DWORD PTR ds:0xfe1778
0x4a2471 53 push   ebx
0x4a2472 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x4a2475 56 push   esi
0x4a2476 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4a2479 894df0 mov    DWORD PTR [ebp-0x10],ecx
0x4a247c 8b0b mov    ecx,DWORD PTR [ebx]
0x4a247e 57 push   edi
0x4a247f 83c8ff or     eax,0xffffffff
0x4a2482 e8692c2500 call   0x6f50f0
0x4a2487 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4a248a 83f903 cmp    ecx,0x3
0x4a248d 742e je     0x4a24bd
0x4a248f 83f904 cmp    ecx,0x4
0x4a2492 0f8534010000 jne    0x4a25cc
0x4a2498 8b30 mov    esi,DWORD PTR [eax]
0x4a249a 83c610 add    esi,0x10
0x4a249d 8d7ddc lea    edi,[ebp-0x24]
0x4a24a0 e8bb522500 call   0x6f7760
0x4a24a5 85c0 test   eax,eax
0x4a24a7 0f841f010000 je     0x4a25cc
0x4a24ad dd45dc fld    QWORD PTR [ebp-0x24]
0x4a24b0 c745d403000000 mov    DWORD PTR [ebp-0x2c],0x3
0x4a24b7 dd5dcc fstp   QWORD PTR [ebp-0x34]
0x4a24ba 8d45cc lea    eax,[ebp-0x34]
0x4a24bd dd00 fld    QWORD PTR [eax]
0x4a24bf dd5ddc fstp   QWORD PTR [ebp-0x24]
0x4a24c2 dd45dc fld    QWORD PTR [ebp-0x24]
0x4a24c5 db5d08 fistp  DWORD PTR [ebp+0x8]
0x4a24c8 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x4a24cb 8955f4 mov    DWORD PTR [ebp-0xc],edx
0x4a24ce 8b03 mov    eax,DWORD PTR [ebx]
0x4a24d0 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x4a24d3 8b48e8 mov    ecx,DWORD PTR [eax-0x18]
0x4a24d6 83e820 sub    eax,0x20
0x4a24d9 83f903 cmp    ecx,0x3
0x4a24dc 742e je     0x4a250c
0x4a24de 83f904 cmp    ecx,0x4
0x4a24e1 0f85f1000000 jne    0x4a25d8
0x4a24e7 8b30 mov    esi,DWORD PTR [eax]
0x4a24e9 83c610 add    esi,0x10
0x4a24ec 8d7ddc lea    edi,[ebp-0x24]
0x4a24ef e86c522500 call   0x6f7760
0x4a24f4 85c0 test   eax,eax
0x4a24f6 0f84dc000000 je     0x4a25d8
0x4a24fc dd45dc fld    QWORD PTR [ebp-0x24]
0x4a24ff c745d403000000 mov    DWORD PTR [ebp-0x2c],0x3
0x4a2506 dd5dcc fstp   QWORD PTR [ebp-0x34]
0x4a2509 8d45cc lea    eax,[ebp-0x34]
0x4a250c dd00 fld    QWORD PTR [eax]
0x4a250e 8b03 mov    eax,DWORD PTR [ebx]
0x4a2510 dd5de4 fstp   QWORD PTR [ebp-0x1c]
0x4a2513 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x4a2516 8b48d8 mov    ecx,DWORD PTR [eax-0x28]
0x4a2519 83e830 sub    eax,0x30
0x4a251c 83f903 cmp    ecx,0x3
0x4a251f 742e je     0x4a254f
0x4a2521 83f904 cmp    ecx,0x4
0x4a2524 0f85b5000000 jne    0x4a25df
0x4a252a 8b30 mov    esi,DWORD PTR [eax]
0x4a252c 83c610 add    esi,0x10
0x4a252f 8d7ddc lea    edi,[ebp-0x24]
0x4a2532 e829522500 call   0x6f7760
0x4a2537 85c0 test   eax,eax
0x4a2539 0f84a0000000 je     0x4a25df
0x4a253f dd45dc fld    QWORD PTR [ebp-0x24]
0x4a2542 c745d403000000 mov    DWORD PTR [ebp-0x2c],0x3
0x4a2549 dd5dcc fstp   QWORD PTR [ebp-0x34]
0x4a254c 8d45cc lea    eax,[ebp-0x34]
0x4a254f dd00 fld    QWORD PTR [eax]
0x4a2551 8b0b mov    ecx,DWORD PTR [ebx]
0x4a2553 dd5ddc fstp   QWORD PTR [ebp-0x24]
0x4a2556 b8fcffffff mov    eax,0xfffffffc
0x4a255b e8902b2500 call   0x6f50f0
0x4a2560 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4a2563 83f903 cmp    ecx,0x3
0x4a2566 7426 je     0x4a258e
0x4a2568 83f904 cmp    ecx,0x4
0x4a256b 7579 jne    0x4a25e6
0x4a256d 8b30 mov    esi,DWORD PTR [eax]
0x4a256f 83c610 add    esi,0x10
0x4a2572 8d7df8 lea    edi,[ebp-0x8]
0x4a2575 e8e6512500 call   0x6f7760
0x4a257a 85c0 test   eax,eax
0x4a257c 7468 je     0x4a25e6
0x4a257e dd45f8 fld    QWORD PTR [ebp-0x8]
0x4a2581 c745d403000000 mov    DWORD PTR [ebp-0x2c],0x3
0x4a2588 dd5dcc fstp   QWORD PTR [ebp-0x34]
0x4a258b 8d45cc lea    eax,[ebp-0x34]
0x4a258e dd00 fld    QWORD PTR [eax]
0x4a2590 dd5dd4 fstp   QWORD PTR [ebp-0x2c]
0x4a2593 dd45d4 fld    QWORD PTR [ebp-0x2c]
0x4a2596 db5dfc fistp  DWORD PTR [ebp-0x4]
0x4a2599 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x4a259c 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4a259f dd45e4 fld    QWORD PTR [ebp-0x1c]
0x4a25a2 d95df4 fstp   DWORD PTR [ebp-0xc]
0x4a25a5 51 push   ecx
0x4a25a6 d945f4 fld    DWORD PTR [ebp-0xc]
0x4a25a9 8b4df0 mov    ecx,DWORD PTR [ebp-0x10]
0x4a25ac 83ec08 sub    esp,0x8
0x4a25af d95c2404 fstp   DWORD PTR [esp+0x4]
0x4a25b3 dd45dc fld    QWORD PTR [ebp-0x24]
0x4a25b6 d95df4 fstp   DWORD PTR [ebp-0xc]
0x4a25b9 d945f4 fld    DWORD PTR [ebp-0xc]
0x4a25bc d91c24 fstp   DWORD PTR [esp]
0x4a25bf 50 push   eax
0x4a25c0 ff55ec call   DWORD PTR [ebp-0x14]
0x4a25c3 5f pop    edi
0x4a25c4 5e pop    esi
0x4a25c5 33c0 xor    eax,eax
0x4a25c7 5b pop    ebx
0x4a25c8 8be5 mov    esp,ebp
0x4a25ca 5d pop    ebp
0x4a25cb c3 ret
0x4a25cc c745f400000000 mov    DWORD PTR [ebp-0xc],0x0
0x4a25d3 e9f6feffff jmp    0x4a24ce
0x4a25d8 d9ee fldz
0x4a25da e92fffffff jmp    0x4a250e
0x4a25df d9ee fldz
0x4a25e1 e96bffffff jmp    0x4a2551
0x4a25e6 33c0 xor    eax,eax
0x4a25e8 ebb2 jmp    0x4a259c

; F_004A2010 0x4a2010..0x4a2066
0x4a2010 55 push   ebp
0x4a2011 8bec mov    ebp,esp
0x4a2013 6aff push   0xffffffff
0x4a2015 68c8839300 push   0x9383c8
0x4a201a 64a100000000 mov    eax,fs:0x0
0x4a2020 50 push   eax
0x4a2021 83ec0c sub    esp,0xc
0x4a2024 a1201fd600 mov    eax,ds:0xd61f20
0x4a2029 33c5 xor    eax,ebp
0x4a202b 50 push   eax
0x4a202c 8d45f4 lea    eax,[ebp-0xc]
0x4a202f 64a300000000 mov    fs:0x0,eax
0x4a2035 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4a2038 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4a203b 33c0 xor    eax,eax
0x4a203d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4a2040 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4a2043 8d4de8 lea    ecx,[ebp-0x18]
0x4a2046 51 push   ecx
0x4a2047 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4a204a e8a1050000 call   0x4a25f0
0x4a204f 83c404 add    esp,0x4
0x4a2052 b801000000 mov    eax,0x1
0x4a2057 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4a205a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4a2061 59 pop    ecx
0x4a2062 8be5 mov    esp,ebp
0x4a2064 5d pop    ebp
0x4a2065 c3 ret

; F_004A25F0 0x4a25f0..0x4a2848
0x4a25f0 55 push   ebp
0x4a25f1 8bec mov    ebp,esp
0x4a25f3 83ec44 sub    esp,0x44
0x4a25f6 a18c17fe00 mov    eax,ds:0xfe178c
0x4a25fb 8b0d7817fe00 mov    ecx,DWORD PTR ds:0xfe1778
0x4a2601 53 push   ebx
0x4a2602 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x4a2605 56 push   esi
0x4a2606 8945dc mov    DWORD PTR [ebp-0x24],eax
0x4a2609 894de0 mov    DWORD PTR [ebp-0x20],ecx
0x4a260c 8b0b mov    ecx,DWORD PTR [ebx]
0x4a260e 57 push   edi
0x4a260f 83c8ff or     eax,0xffffffff
0x4a2612 e8d92a2500 call   0x6f50f0
0x4a2617 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4a261a 83f903 cmp    ecx,0x3
0x4a261d 742e je     0x4a264d
0x4a261f 83f904 cmp    ecx,0x4
0x4a2622 0f85ea010000 jne    0x4a2812
0x4a2628 8b30 mov    esi,DWORD PTR [eax]
0x4a262a 83c610 add    esi,0x10
0x4a262d 8d7dcc lea    edi,[ebp-0x34]
0x4a2630 e82b512500 call   0x6f7760
0x4a2635 85c0 test   eax,eax
0x4a2637 0f84d5010000 je     0x4a2812
0x4a263d dd45cc fld    QWORD PTR [ebp-0x34]
0x4a2640 c745c403000000 mov    DWORD PTR [ebp-0x3c],0x3
0x4a2647 dd5dbc fstp   QWORD PTR [ebp-0x44]
0x4a264a 8d45bc lea    eax,[ebp-0x44]
0x4a264d dd00 fld    QWORD PTR [eax]
0x4a264f dd5dcc fstp   QWORD PTR [ebp-0x34]
0x4a2652 dd45cc fld    QWORD PTR [ebp-0x34]
0x4a2655 db5d08 fistp  DWORD PTR [ebp+0x8]
0x4a2658 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x4a265b 8955ec mov    DWORD PTR [ebp-0x14],edx
0x4a265e 8b0b mov    ecx,DWORD PTR [ebx]
0x4a2660 b8feffffff mov    eax,0xfffffffe
0x4a2665 e8862a2500 call   0x6f50f0
0x4a266a 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4a266d 83f903 cmp    ecx,0x3
0x4a2670 742e je     0x4a26a0
0x4a2672 83f904 cmp    ecx,0x4
0x4a2675 0f85a3010000 jne    0x4a281e
0x4a267b 8b30 mov    esi,DWORD PTR [eax]
0x4a267d 83c610 add    esi,0x10
0x4a2680 8d7dcc lea    edi,[ebp-0x34]
0x4a2683 e8d8502500 call   0x6f7760
0x4a2688 85c0 test   eax,eax
0x4a268a 0f848e010000 je     0x4a281e
0x4a2690 dd45cc fld    QWORD PTR [ebp-0x34]
0x4a2693 c745c403000000 mov    DWORD PTR [ebp-0x3c],0x3
0x4a269a dd5dbc fstp   QWORD PTR [ebp-0x44]
0x4a269d 8d45bc lea    eax,[ebp-0x44]
0x4a26a0 dd00 fld    QWORD PTR [eax]
0x4a26a2 dd5dcc fstp   QWORD PTR [ebp-0x34]
0x4a26a5 dd45cc fld    QWORD PTR [ebp-0x34]
0x4a26a8 db5dfc fistp  DWORD PTR [ebp-0x4]
0x4a26ab 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x4a26ae 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4a26b1 8b0b mov    ecx,DWORD PTR [ebx]
0x4a26b3 b8fdffffff mov    eax,0xfffffffd
0x4a26b8 e8332a2500 call   0x6f50f0
0x4a26bd 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4a26c0 83f903 cmp    ecx,0x3
0x4a26c3 742e je     0x4a26f3
0x4a26c5 83f904 cmp    ecx,0x4
0x4a26c8 0f855c010000 jne    0x4a282a
0x4a26ce 8b30 mov    esi,DWORD PTR [eax]
0x4a26d0 83c610 add    esi,0x10
0x4a26d3 8d7dcc lea    edi,[ebp-0x34]
0x4a26d6 e885502500 call   0x6f7760
0x4a26db 85c0 test   eax,eax
0x4a26dd 0f8447010000 je     0x4a282a
0x4a26e3 dd45cc fld    QWORD PTR [ebp-0x34]
0x4a26e6 c745c403000000 mov    DWORD PTR [ebp-0x3c],0x3
0x4a26ed dd5dbc fstp   QWORD PTR [ebp-0x44]
0x4a26f0 8d45bc lea    eax,[ebp-0x44]
0x4a26f3 dd00 fld    QWORD PTR [eax]
0x4a26f5 dd5dcc fstp   QWORD PTR [ebp-0x34]
0x4a26f8 dd45cc fld    QWORD PTR [ebp-0x34]
0x4a26fb db5df8 fistp  DWORD PTR [ebp-0x8]
0x4a26fe 8b4df8 mov    ecx,DWORD PTR [ebp-0x8]
0x4a2701 894de4 mov    DWORD PTR [ebp-0x1c],ecx
0x4a2704 8b03 mov    eax,DWORD PTR [ebx]
0x4a2706 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x4a2709 8b48c8 mov    ecx,DWORD PTR [eax-0x38]
0x4a270c 83e840 sub    eax,0x40
0x4a270f 83f903 cmp    ecx,0x3
0x4a2712 742e je     0x4a2742
0x4a2714 83f904 cmp    ecx,0x4
0x4a2717 0f8519010000 jne    0x4a2836
0x4a271d 8b30 mov    esi,DWORD PTR [eax]
0x4a271f 83c610 add    esi,0x10
0x4a2722 8d7dcc lea    edi,[ebp-0x34]
0x4a2725 e836502500 call   0x6f7760
0x4a272a 85c0 test   eax,eax
0x4a272c 0f8404010000 je     0x4a2836
0x4a2732 dd45cc fld    QWORD PTR [ebp-0x34]
0x4a2735 c745c403000000 mov    DWORD PTR [ebp-0x3c],0x3
0x4a273c dd5dbc fstp   QWORD PTR [ebp-0x44]
0x4a273f 8d45bc lea    eax,[ebp-0x44]
0x4a2742 dd00 fld    QWORD PTR [eax]
0x4a2744 8b03 mov    eax,DWORD PTR [ebx]
0x4a2746 dd5dd4 fstp   QWORD PTR [ebp-0x2c]
0x4a2749 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x4a274c 8b48b8 mov    ecx,DWORD PTR [eax-0x48]
0x4a274f 83e850 sub    eax,0x50
0x4a2752 83f903 cmp    ecx,0x3
0x4a2755 742e je     0x4a2785
0x4a2757 83f904 cmp    ecx,0x4
0x4a275a 0f85dd000000 jne    0x4a283d
0x4a2760 8b30 mov    esi,DWORD PTR [eax]
0x4a2762 83c610 add    esi,0x10
0x4a2765 8d7dcc lea    edi,[ebp-0x34]
0x4a2768 e8f34f2500 call   0x6f7760
0x4a276d 85c0 test   eax,eax
0x4a276f 0f84c8000000 je     0x4a283d
0x4a2775 dd45cc fld    QWORD PTR [ebp-0x34]
0x4a2778 c745c403000000 mov    DWORD PTR [ebp-0x3c],0x3
0x4a277f dd5dbc fstp   QWORD PTR [ebp-0x44]
0x4a2782 8d45bc lea    eax,[ebp-0x44]
0x4a2785 dd00 fld    QWORD PTR [eax]
0x4a2787 8b0b mov    ecx,DWORD PTR [ebx]
0x4a2789 dd5dcc fstp   QWORD PTR [ebp-0x34]
0x4a278c b8faffffff mov    eax,0xfffffffa
0x4a2791 e85a292500 call   0x6f50f0
0x4a2796 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4a2799 83f903 cmp    ecx,0x3
0x4a279c 742e je     0x4a27cc
0x4a279e 83f904 cmp    ecx,0x4
0x4a27a1 0f859d000000 jne    0x4a2844
0x4a27a7 8b30 mov    esi,DWORD PTR [eax]
0x4a27a9 83c610 add    esi,0x10
0x4a27ac 8d7df0 lea    edi,[ebp-0x10]
0x4a27af e8ac4f2500 call   0x6f7760
0x4a27b4 85c0 test   eax,eax
0x4a27b6 0f8488000000 je     0x4a2844
0x4a27bc dd45f0 fld    QWORD PTR [ebp-0x10]
0x4a27bf c745c403000000 mov    DWORD PTR [ebp-0x3c],0x3
0x4a27c6 dd5dbc fstp   QWORD PTR [ebp-0x44]
0x4a27c9 8d45bc lea    eax,[ebp-0x44]
0x4a27cc dd00 fld    QWORD PTR [eax]
0x4a27ce dd5dc4 fstp   QWORD PTR [ebp-0x3c]
0x4a27d1 dd45c4 fld    QWORD PTR [ebp-0x3c]
0x4a27d4 db5df4 fistp  DWORD PTR [ebp-0xc]
0x4a27d7 8b45f4 mov    eax,DWORD PTR [ebp-0xc]
0x4a27da 8b55ec mov    edx,DWORD PTR [ebp-0x14]
0x4a27dd dd45d4 fld    QWORD PTR [ebp-0x2c]
0x4a27e0 8b4de8 mov    ecx,DWORD PTR [ebp-0x18]
0x4a27e3 52 push   edx
0x4a27e4 8b55e4 mov    edx,DWORD PTR [ebp-0x1c]
0x4a27e7 d95de4 fstp   DWORD PTR [ebp-0x1c]
0x4a27ea d945e4 fld    DWORD PTR [ebp-0x1c]
0x4a27ed 51 push   ecx
0x4a27ee 8b4de0 mov    ecx,DWORD PTR [ebp-0x20]
0x4a27f1 52 push   edx
0x4a27f2 83ec08 sub    esp,0x8
0x4a27f5 d95c2404 fstp   DWORD PTR [esp+0x4]
0x4a27f9 dd45cc fld    QWORD PTR [ebp-0x34]
0x4a27fc d95de4 fstp   DWORD PTR [ebp-0x1c]
0x4a27ff d945e4 fld    DWORD PTR [ebp-0x1c]
0x4a2802 d91c24 fstp   DWORD PTR [esp]
0x4a2805 50 push   eax
0x4a2806 ff55dc call   DWORD PTR [ebp-0x24]
0x4a2809 5f pop    edi
0x4a280a 5e pop    esi
0x4a280b 33c0 xor    eax,eax
0x4a280d 5b pop    ebx
0x4a280e 8be5 mov    esp,ebp
0x4a2810 5d pop    ebp
0x4a2811 c3 ret
0x4a2812 c745ec00000000 mov    DWORD PTR [ebp-0x14],0x0
0x4a2819 e940feffff jmp    0x4a265e
0x4a281e c745e800000000 mov    DWORD PTR [ebp-0x18],0x0
0x4a2825 e987feffff jmp    0x4a26b1
0x4a282a c745e400000000 mov    DWORD PTR [ebp-0x1c],0x0
0x4a2831 e9cefeffff jmp    0x4a2704
0x4a2836 d9ee fldz
0x4a2838 e907ffffff jmp    0x4a2744
0x4a283d d9ee fldz
0x4a283f e943ffffff jmp    0x4a2787
0x4a2844 33c0 xor    eax,eax
0x4a2846 eb92 jmp    0x4a27da

; F_004A2070 0x4a2070..0x4a20cd
0x4a2070 55 push   ebp
0x4a2071 8bec mov    ebp,esp
0x4a2073 6aff push   0xffffffff
0x4a2075 68c8839300 push   0x9383c8
0x4a207a 64a100000000 mov    eax,fs:0x0
0x4a2080 50 push   eax
0x4a2081 83ec0c sub    esp,0xc
0x4a2084 a1201fd600 mov    eax,ds:0xd61f20
0x4a2089 33c5 xor    eax,ebp
0x4a208b 50 push   eax
0x4a208c 8d45f4 lea    eax,[ebp-0xc]
0x4a208f 64a300000000 mov    fs:0x0,eax
0x4a2095 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4a2098 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4a209b 33c0 xor    eax,eax
0x4a209d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4a20a0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4a20a3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4a20a6 8b0d9017fe00 mov    ecx,DWORD PTR ds:0xfe1790
0x4a20ac 51 push   ecx
0x4a20ad 8d55e8 lea    edx,[ebp-0x18]
0x4a20b0 52 push   edx
0x4a20b1 e89a070000 call   0x4a2850
0x4a20b6 83c408 add    esp,0x8
0x4a20b9 b801000000 mov    eax,0x1
0x4a20be 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4a20c1 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4a20c8 59 pop    ecx
0x4a20c9 8be5 mov    esp,ebp
0x4a20cb 5d pop    ebp
0x4a20cc c3 ret

; F_004A2850 0x4a2850..0x4a2981
0x4a2850 55 push   ebp
0x4a2851 8bec mov    ebp,esp
0x4a2853 83ec2c sub    esp,0x2c
0x4a2856 a17817fe00 mov    eax,ds:0xfe1778
0x4a285b 53 push   ebx
0x4a285c 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x4a285f 8b0b mov    ecx,DWORD PTR [ebx]
0x4a2861 56 push   esi
0x4a2862 8945e4 mov    DWORD PTR [ebp-0x1c],eax
0x4a2865 57 push   edi
0x4a2866 83c8ff or     eax,0xffffffff
0x4a2869 e882282500 call   0x6f50f0
0x4a286e 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4a2871 83f903 cmp    ecx,0x3
0x4a2874 742e je     0x4a28a4
0x4a2876 83f904 cmp    ecx,0x4
0x4a2879 0f85e9000000 jne    0x4a2968
0x4a287f 8b30 mov    esi,DWORD PTR [eax]
0x4a2881 83c610 add    esi,0x10
0x4a2884 8d7de8 lea    edi,[ebp-0x18]
0x4a2887 e8d44e2500 call   0x6f7760
0x4a288c 85c0 test   eax,eax
0x4a288e 0f84d4000000 je     0x4a2968
0x4a2894 dd45e8 fld    QWORD PTR [ebp-0x18]
0x4a2897 c745dc03000000 mov    DWORD PTR [ebp-0x24],0x3
0x4a289e dd5dd4 fstp   QWORD PTR [ebp-0x2c]
0x4a28a1 8d45d4 lea    eax,[ebp-0x2c]
0x4a28a4 dd00 fld    QWORD PTR [eax]
0x4a28a6 dd5de8 fstp   QWORD PTR [ebp-0x18]
0x4a28a9 dd45e8 fld    QWORD PTR [ebp-0x18]
0x4a28ac db5d08 fistp  DWORD PTR [ebp+0x8]
0x4a28af 8b4d08 mov    ecx,DWORD PTR [ebp+0x8]
0x4a28b2 894df0 mov    DWORD PTR [ebp-0x10],ecx
0x4a28b5 8b0b mov    ecx,DWORD PTR [ebx]
0x4a28b7 b8feffffff mov    eax,0xfffffffe
0x4a28bc e82f282500 call   0x6f50f0
0x4a28c1 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4a28c4 83f903 cmp    ecx,0x3
0x4a28c7 742e je     0x4a28f7
0x4a28c9 83f904 cmp    ecx,0x4
0x4a28cc 0f85a2000000 jne    0x4a2974
0x4a28d2 8b30 mov    esi,DWORD PTR [eax]
0x4a28d4 83c610 add    esi,0x10
0x4a28d7 8d7de8 lea    edi,[ebp-0x18]
0x4a28da e8814e2500 call   0x6f7760
0x4a28df 85c0 test   eax,eax
0x4a28e1 0f848d000000 je     0x4a2974
0x4a28e7 dd45e8 fld    QWORD PTR [ebp-0x18]
0x4a28ea c745dc03000000 mov    DWORD PTR [ebp-0x24],0x3
0x4a28f1 dd5dd4 fstp   QWORD PTR [ebp-0x2c]
0x4a28f4 8d45d4 lea    eax,[ebp-0x2c]
0x4a28f7 dd00 fld    QWORD PTR [eax]
0x4a28f9 dd5de8 fstp   QWORD PTR [ebp-0x18]
0x4a28fc dd45e8 fld    QWORD PTR [ebp-0x18]
0x4a28ff db5dfc fistp  DWORD PTR [ebp-0x4]
0x4a2902 8b55fc mov    edx,DWORD PTR [ebp-0x4]
0x4a2905 8955ec mov    DWORD PTR [ebp-0x14],edx
0x4a2908 8b0b mov    ecx,DWORD PTR [ebx]
0x4a290a b8fdffffff mov    eax,0xfffffffd
0x4a290f e8dc272500 call   0x6f50f0
0x4a2914 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4a2917 83f903 cmp    ecx,0x3
0x4a291a 7426 je     0x4a2942
0x4a291c 83f904 cmp    ecx,0x4
0x4a291f 755c jne    0x4a297d
0x4a2921 8b30 mov    esi,DWORD PTR [eax]
0x4a2923 83c610 add    esi,0x10
0x4a2926 8d7df4 lea    edi,[ebp-0xc]
0x4a2929 e8324e2500 call   0x6f7760
0x4a292e 85c0 test   eax,eax
0x4a2930 744b je     0x4a297d
0x4a2932 dd45f4 fld    QWORD PTR [ebp-0xc]
0x4a2935 c745dc03000000 mov    DWORD PTR [ebp-0x24],0x3
0x4a293c dd5dd4 fstp   QWORD PTR [ebp-0x2c]
0x4a293f 8d45d4 lea    eax,[ebp-0x2c]
0x4a2942 dd00 fld    QWORD PTR [eax]
0x4a2944 dd5ddc fstp   QWORD PTR [ebp-0x24]
0x4a2947 dd45dc fld    QWORD PTR [ebp-0x24]
0x4a294a db5df8 fistp  DWORD PTR [ebp-0x8]
0x4a294d 8b45f8 mov    eax,DWORD PTR [ebp-0x8]
0x4a2950 8b4df0 mov    ecx,DWORD PTR [ebp-0x10]
0x4a2953 8b55ec mov    edx,DWORD PTR [ebp-0x14]
0x4a2956 51 push   ecx
0x4a2957 8b4de4 mov    ecx,DWORD PTR [ebp-0x1c]
0x4a295a 52 push   edx
0x4a295b 50 push   eax
0x4a295c ff550c call   DWORD PTR [ebp+0xc]
0x4a295f 5f pop    edi
0x4a2960 5e pop    esi
0x4a2961 33c0 xor    eax,eax
0x4a2963 5b pop    ebx
0x4a2964 8be5 mov    esp,ebp
0x4a2966 5d pop    ebp
0x4a2967 c3 ret
0x4a2968 c745f000000000 mov    DWORD PTR [ebp-0x10],0x0
0x4a296f e941ffffff jmp    0x4a28b5
0x4a2974 c745ec00000000 mov    DWORD PTR [ebp-0x14],0x0
0x4a297b eb8b jmp    0x4a2908
0x4a297d 33c0 xor    eax,eax
0x4a297f ebcf jmp    0x4a2950

; F_004A20D0 0x4a20d0..0x4a212d
0x4a20d0 55 push   ebp
0x4a20d1 8bec mov    ebp,esp
0x4a20d3 6aff push   0xffffffff
0x4a20d5 68c8839300 push   0x9383c8
0x4a20da 64a100000000 mov    eax,fs:0x0
0x4a20e0 50 push   eax
0x4a20e1 83ec0c sub    esp,0xc
0x4a20e4 a1201fd600 mov    eax,ds:0xd61f20
0x4a20e9 33c5 xor    eax,ebp
0x4a20eb 50 push   eax
0x4a20ec 8d45f4 lea    eax,[ebp-0xc]
0x4a20ef 64a300000000 mov    fs:0x0,eax
0x4a20f5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4a20f8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4a20fb 33c0 xor    eax,eax
0x4a20fd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4a2100 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4a2103 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4a2106 8b0d9417fe00 mov    ecx,DWORD PTR ds:0xfe1794
0x4a210c 51 push   ecx
0x4a210d 8d55e8 lea    edx,[ebp-0x18]
0x4a2110 52 push   edx
0x4a2111 e87a080000 call   0x4a2990
0x4a2116 83c408 add    esp,0x8
0x4a2119 b801000000 mov    eax,0x1
0x4a211e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4a2121 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4a2128 59 pop    ecx
0x4a2129 8be5 mov    esp,ebp
0x4a212b 5d pop    ebp
0x4a212c c3 ret

; F_004A2990 0x4a2990..0x4a2a6c
0x4a2990 55 push   ebp
0x4a2991 8bec mov    ebp,esp
0x4a2993 83ec24 sub    esp,0x24
0x4a2996 a17817fe00 mov    eax,ds:0xfe1778
0x4a299b 53 push   ebx
0x4a299c 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x4a299f 8b0b mov    ecx,DWORD PTR [ebx]
0x4a29a1 56 push   esi
0x4a29a2 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4a29a5 57 push   edi
0x4a29a6 83c8ff or     eax,0xffffffff
0x4a29a9 e842272500 call   0x6f50f0
0x4a29ae 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4a29b1 83f903 cmp    ecx,0x3
0x4a29b4 742a je     0x4a29e0
0x4a29b6 83f904 cmp    ecx,0x4
0x4a29b9 0f858e000000 jne    0x4a2a4d
0x4a29bf 8b30 mov    esi,DWORD PTR [eax]
0x4a29c1 83c610 add    esi,0x10
0x4a29c4 8d7df0 lea    edi,[ebp-0x10]
0x4a29c7 e8944d2500 call   0x6f7760
0x4a29cc 85c0 test   eax,eax
0x4a29ce 747d je     0x4a2a4d
0x4a29d0 dd45f0 fld    QWORD PTR [ebp-0x10]
0x4a29d3 c745e403000000 mov    DWORD PTR [ebp-0x1c],0x3
0x4a29da dd5ddc fstp   QWORD PTR [ebp-0x24]
0x4a29dd 8d45dc lea    eax,[ebp-0x24]
0x4a29e0 dd00 fld    QWORD PTR [eax]
0x4a29e2 dd5df0 fstp   QWORD PTR [ebp-0x10]
0x4a29e5 dd45f0 fld    QWORD PTR [ebp-0x10]
0x4a29e8 db5d08 fistp  DWORD PTR [ebp+0x8]
0x4a29eb 8b4d08 mov    ecx,DWORD PTR [ebp+0x8]
0x4a29ee 894df4 mov    DWORD PTR [ebp-0xc],ecx
0x4a29f1 8b0b mov    ecx,DWORD PTR [ebx]
0x4a29f3 b8feffffff mov    eax,0xfffffffe
0x4a29f8 e8f3262500 call   0x6f50f0
0x4a29fd 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4a2a00 83f903 cmp    ecx,0x3
0x4a2a03 7426 je     0x4a2a2b
0x4a2a05 83f904 cmp    ecx,0x4
0x4a2a08 754c jne    0x4a2a56
0x4a2a0a 8b30 mov    esi,DWORD PTR [eax]
0x4a2a0c 83c610 add    esi,0x10
0x4a2a0f 8d7df8 lea    edi,[ebp-0x8]
0x4a2a12 e8494d2500 call   0x6f7760
0x4a2a17 85c0 test   eax,eax
0x4a2a19 743b je     0x4a2a56
0x4a2a1b dd45f8 fld    QWORD PTR [ebp-0x8]
0x4a2a1e c745e403000000 mov    DWORD PTR [ebp-0x1c],0x3
0x4a2a25 dd5ddc fstp   QWORD PTR [ebp-0x24]
0x4a2a28 8d45dc lea    eax,[ebp-0x24]
0x4a2a2b dd00 fld    QWORD PTR [eax]
0x4a2a2d dd5de4 fstp   QWORD PTR [ebp-0x1c]
0x4a2a30 dd45e4 fld    QWORD PTR [ebp-0x1c]
0x4a2a33 db5dfc fistp  DWORD PTR [ebp-0x4]
0x4a2a36 8b55f4 mov    edx,DWORD PTR [ebp-0xc]
0x4a2a39 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x4a2a3c 8b4dec mov    ecx,DWORD PTR [ebp-0x14]
0x4a2a3f 52 push   edx
0x4a2a40 50 push   eax
0x4a2a41 ff550c call   DWORD PTR [ebp+0xc]
0x4a2a44 5f pop    edi
0x4a2a45 5e pop    esi
0x4a2a46 33c0 xor    eax,eax
0x4a2a48 5b pop    ebx
0x4a2a49 8be5 mov    esp,ebp
0x4a2a4b 5d pop    ebp
0x4a2a4c c3 ret
0x4a2a4d c745f400000000 mov    DWORD PTR [ebp-0xc],0x0
0x4a2a54 eb9b jmp    0x4a29f1
0x4a2a56 8b55f4 mov    edx,DWORD PTR [ebp-0xc]
0x4a2a59 8b4dec mov    ecx,DWORD PTR [ebp-0x14]
0x4a2a5c 33c0 xor    eax,eax
0x4a2a5e 52 push   edx
0x4a2a5f 50 push   eax
0x4a2a60 ff550c call   DWORD PTR [ebp+0xc]
0x4a2a63 5f pop    edi
0x4a2a64 5e pop    esi
0x4a2a65 33c0 xor    eax,eax
0x4a2a67 5b pop    ebx
0x4a2a68 8be5 mov    esp,ebp
0x4a2a6a 5d pop    ebp
0x4a2a6b c3 ret

; F_004A2130 0x4a2130..0x4a218d
0x4a2130 55 push   ebp
0x4a2131 8bec mov    ebp,esp
0x4a2133 6aff push   0xffffffff
0x4a2135 68c8839300 push   0x9383c8
0x4a213a 64a100000000 mov    eax,fs:0x0
0x4a2140 50 push   eax
0x4a2141 83ec0c sub    esp,0xc
0x4a2144 a1201fd600 mov    eax,ds:0xd61f20
0x4a2149 33c5 xor    eax,ebp
0x4a214b 50 push   eax
0x4a214c 8d45f4 lea    eax,[ebp-0xc]
0x4a214f 64a300000000 mov    fs:0x0,eax
0x4a2155 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4a2158 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4a215b 33c0 xor    eax,eax
0x4a215d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4a2160 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4a2163 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4a2166 8b0d9817fe00 mov    ecx,DWORD PTR ds:0xfe1798
0x4a216c 51 push   ecx
0x4a216d 8d55e8 lea    edx,[ebp-0x18]
0x4a2170 52 push   edx
0x4a2171 e81a080000 call   0x4a2990
0x4a2176 83c408 add    esp,0x8
0x4a2179 b801000000 mov    eax,0x1
0x4a217e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4a2181 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4a2188 59 pop    ecx
0x4a2189 8be5 mov    esp,ebp
0x4a218b 5d pop    ebp
0x4a218c c3 ret

; F_004A2190 0x4a2190..0x4a21fe
0x4a2190 55 push   ebp
0x4a2191 8bec mov    ebp,esp
0x4a2193 6aff push   0xffffffff
0x4a2195 68d8879300 push   0x9387d8
0x4a219a 64a100000000 mov    eax,fs:0x0
0x4a21a0 50 push   eax
0x4a21a1 83ec0c sub    esp,0xc
0x4a21a4 56 push   esi
0x4a21a5 a1201fd600 mov    eax,ds:0xd61f20
0x4a21aa 33c5 xor    eax,ebp
0x4a21ac 50 push   eax
0x4a21ad 8d45f4 lea    eax,[ebp-0xc]
0x4a21b0 64a300000000 mov    fs:0x0,eax
0x4a21b6 8b7508 mov    esi,DWORD PTR [ebp+0x8]
0x4a21b9 33c0 xor    eax,eax
0x4a21bb 8975e8 mov    DWORD PTR [ebp-0x18],esi
0x4a21be 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4a21c1 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4a21c4 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4a21c7 8b0d7817fe00 mov    ecx,DWORD PTR ds:0xfe1778
0x4a21cd ff159c17fe00 call   DWORD PTR ds:0xfe179c
0x4a21d3 894508 mov    DWORD PTR [ebp+0x8],eax
0x4a21d6 8b4608 mov    eax,DWORD PTR [esi+0x8]
0x4a21d9 db4508 fild   DWORD PTR [ebp+0x8]
0x4a21dc c7400803000000 mov    DWORD PTR [eax+0x8],0x3
0x4a21e3 dd18 fstp   QWORD PTR [eax]
0x4a21e5 83460810 add    DWORD PTR [esi+0x8],0x10
0x4a21e9 b801000000 mov    eax,0x1
0x4a21ee 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4a21f1 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4a21f8 59 pop    ecx
0x4a21f9 5e pop    esi
0x4a21fa 8be5 mov    esp,ebp
0x4a21fc 5d pop    ebp
0x4a21fd c3 ret

; F_004A2200 0x4a2200..0x4a2256
0x4a2200 55 push   ebp
0x4a2201 8bec mov    ebp,esp
0x4a2203 6aff push   0xffffffff
0x4a2205 68c8839300 push   0x9383c8
0x4a220a 64a100000000 mov    eax,fs:0x0
0x4a2210 50 push   eax
0x4a2211 83ec0c sub    esp,0xc
0x4a2214 a1201fd600 mov    eax,ds:0xd61f20
0x4a2219 33c5 xor    eax,ebp
0x4a221b 50 push   eax
0x4a221c 8d45f4 lea    eax,[ebp-0xc]
0x4a221f 64a300000000 mov    fs:0x0,eax
0x4a2225 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4a2228 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4a222b 33c0 xor    eax,eax
0x4a222d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4a2230 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4a2233 8d4de8 lea    ecx,[ebp-0x18]
0x4a2236 51 push   ecx
0x4a2237 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4a223a e831080000 call   0x4a2a70
0x4a223f 83c404 add    esp,0x4
0x4a2242 b801000000 mov    eax,0x1
0x4a2247 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4a224a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4a2251 59 pop    ecx
0x4a2252 8be5 mov    esp,ebp
0x4a2254 5d pop    ebp
0x4a2255 c3 ret

; F_004A2A70 0x4a2a70..0x4a2aee
0x4a2a70 55 push   ebp
0x4a2a71 8bec mov    ebp,esp
0x4a2a73 51 push   ecx
0x4a2a74 a1a017fe00 mov    eax,ds:0xfe17a0
0x4a2a79 8b0d7817fe00 mov    ecx,DWORD PTR ds:0xfe1778
0x4a2a7f 53 push   ebx
0x4a2a80 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x4a2a83 56 push   esi
0x4a2a84 57 push   edi
0x4a2a85 8b3b mov    edi,DWORD PTR [ebx]
0x4a2a87 8b7708 mov    esi,DWORD PTR [edi+0x8]
0x4a2a8a 83ee10 sub    esi,0x10
0x4a2a8d 837e0804 cmp    DWORD PTR [esi+0x8],0x4
0x4a2a91 894508 mov    DWORD PTR [ebp+0x8],eax
0x4a2a94 894dfc mov    DWORD PTR [ebp-0x4],ecx
0x4a2a97 7425 je     0x4a2abe
0x4a2a99 e8328b2500 call   0x6fb5d0
0x4a2a9e 85c0 test   eax,eax
0x4a2aa0 7504 jne    0x4a2aa6
0x4a2aa2 33f6 xor    esi,esi
0x4a2aa4 eb1d jmp    0x4a2ac3
0x4a2aa6 8b4710 mov    eax,DWORD PTR [edi+0x10]
0x4a2aa9 8b5044 mov    edx,DWORD PTR [eax+0x44]
0x4a2aac 3b5040 cmp    edx,DWORD PTR [eax+0x40]
0x4a2aaf 7207 jb     0x4a2ab8
0x4a2ab1 8bc7 mov    eax,edi
0x4a2ab3 e8e8882500 call   0x6fb3a0
0x4a2ab8 8b7708 mov    esi,DWORD PTR [edi+0x8]
0x4a2abb 83ee10 sub    esi,0x10
0x4a2abe 8b36 mov    esi,DWORD PTR [esi]
0x4a2ac0 83c610 add    esi,0x10
0x4a2ac3 8b4dfc mov    ecx,DWORD PTR [ebp-0x4]
0x4a2ac6 56 push   esi
0x4a2ac7 ff5508 call   DWORD PTR [ebp+0x8]
0x4a2aca 894508 mov    DWORD PTR [ebp+0x8],eax
0x4a2acd 8b03 mov    eax,DWORD PTR [ebx]
0x4a2acf db4508 fild   DWORD PTR [ebp+0x8]
0x4a2ad2 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4a2ad5 5f pop    edi
0x4a2ad6 dd19 fstp   QWORD PTR [ecx]
0x4a2ad8 c7410803000000 mov    DWORD PTR [ecx+0x8],0x3
0x4a2adf 83400810 add    DWORD PTR [eax+0x8],0x10
0x4a2ae3 5e pop    esi
0x4a2ae4 b801000000 mov    eax,0x1
0x4a2ae9 5b pop    ebx
0x4a2aea 8be5 mov    esp,ebp
0x4a2aec 5d pop    ebp
0x4a2aed c3 ret

; F_004A2260 0x4a2260..0x4a22b6
0x4a2260 55 push   ebp
0x4a2261 8bec mov    ebp,esp
0x4a2263 6aff push   0xffffffff
0x4a2265 68c8839300 push   0x9383c8
0x4a226a 64a100000000 mov    eax,fs:0x0
0x4a2270 50 push   eax
0x4a2271 83ec0c sub    esp,0xc
0x4a2274 a1201fd600 mov    eax,ds:0xd61f20
0x4a2279 33c5 xor    eax,ebp
0x4a227b 50 push   eax
0x4a227c 8d45f4 lea    eax,[ebp-0xc]
0x4a227f 64a300000000 mov    fs:0x0,eax
0x4a2285 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4a2288 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4a228b 33c0 xor    eax,eax
0x4a228d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4a2290 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4a2293 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4a2296 8b0d7817fe00 mov    ecx,DWORD PTR ds:0xfe1778
0x4a229c ff15a417fe00 call   DWORD PTR ds:0xfe17a4
0x4a22a2 b801000000 mov    eax,0x1
0x4a22a7 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4a22aa 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4a22b1 59 pop    ecx
0x4a22b2 8be5 mov    esp,ebp
0x4a22b4 5d pop    ebp
0x4a22b5 c3 ret

; F_004A22C0 0x4a22c0..0x4a231d
0x4a22c0 55 push   ebp
0x4a22c1 8bec mov    ebp,esp
0x4a22c3 6aff push   0xffffffff
0x4a22c5 68c8839300 push   0x9383c8
0x4a22ca 64a100000000 mov    eax,fs:0x0
0x4a22d0 50 push   eax
0x4a22d1 83ec0c sub    esp,0xc
0x4a22d4 a1201fd600 mov    eax,ds:0xd61f20
0x4a22d9 33c5 xor    eax,ebp
0x4a22db 50 push   eax
0x4a22dc 8d45f4 lea    eax,[ebp-0xc]
0x4a22df 64a300000000 mov    fs:0x0,eax
0x4a22e5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4a22e8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4a22eb 33c0 xor    eax,eax
0x4a22ed 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4a22f0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4a22f3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4a22f6 8b0da817fe00 mov    ecx,DWORD PTR ds:0xfe17a8
0x4a22fc 51 push   ecx
0x4a22fd 8d55e8 lea    edx,[ebp-0x18]
0x4a2300 52 push   edx
0x4a2301 e84a050000 call   0x4a2850
0x4a2306 83c408 add    esp,0x8
0x4a2309 b801000000 mov    eax,0x1
0x4a230e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4a2311 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4a2318 59 pop    ecx
0x4a2319 8be5 mov    esp,ebp
0x4a231b 5d pop    ebp
0x4a231c c3 ret

; F_004A2320 0x4a2320..0x4a237c
0x4a2320 55 push   ebp
0x4a2321 8bec mov    ebp,esp
0x4a2323 6aff push   0xffffffff
0x4a2325 68c8839300 push   0x9383c8
0x4a232a 64a100000000 mov    eax,fs:0x0
0x4a2330 50 push   eax
0x4a2331 83ec0c sub    esp,0xc
0x4a2334 a1201fd600 mov    eax,ds:0xd61f20
0x4a2339 33c5 xor    eax,ebp
0x4a233b 50 push   eax
0x4a233c 8d45f4 lea    eax,[ebp-0xc]
0x4a233f 64a300000000 mov    fs:0x0,eax
0x4a2345 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4a2348 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4a234b 33c0 xor    eax,eax
0x4a234d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4a2350 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4a2353 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4a2356 8b0dac17fe00 mov    ecx,DWORD PTR ds:0xfe17ac
0x4a235c 51 push   ecx
0x4a235d 8d45e8 lea    eax,[ebp-0x18]
0x4a2360 e87b000000 call   0x4a23e0
0x4a2365 83c404 add    esp,0x4
0x4a2368 b801000000 mov    eax,0x1
0x4a236d 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4a2370 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4a2377 59 pop    ecx
0x4a2378 8be5 mov    esp,ebp
0x4a237a 5d pop    ebp
0x4a237b c3 ret

; F_004A2380 0x4a2380..0x4a23dc
0x4a2380 55 push   ebp
0x4a2381 8bec mov    ebp,esp
0x4a2383 6aff push   0xffffffff
0x4a2385 68c8839300 push   0x9383c8
0x4a238a 64a100000000 mov    eax,fs:0x0
0x4a2390 50 push   eax
0x4a2391 83ec0c sub    esp,0xc
0x4a2394 a1201fd600 mov    eax,ds:0xd61f20
0x4a2399 33c5 xor    eax,ebp
0x4a239b 50 push   eax
0x4a239c 8d45f4 lea    eax,[ebp-0xc]
0x4a239f 64a300000000 mov    fs:0x0,eax
0x4a23a5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4a23a8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4a23ab 33c0 xor    eax,eax
0x4a23ad 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4a23b0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4a23b3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4a23b6 8b0db017fe00 mov    ecx,DWORD PTR ds:0xfe17b0
0x4a23bc 51 push   ecx
0x4a23bd 8d45e8 lea    eax,[ebp-0x18]
0x4a23c0 e81b000000 call   0x4a23e0
0x4a23c5 83c404 add    esp,0x4
0x4a23c8 b801000000 mov    eax,0x1
0x4a23cd 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4a23d0 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4a23d7 59 pop    ecx
0x4a23d8 8be5 mov    esp,ebp
0x4a23da 5d pop    ebp
0x4a23db c3 ret

; F_004ABEA0 0x4abea0..0x4abf0e
0x4abea0 55 push   ebp
0x4abea1 8bec mov    ebp,esp
0x4abea3 6aff push   0xffffffff
0x4abea5 68d8879300 push   0x9387d8
0x4abeaa 64a100000000 mov    eax,fs:0x0
0x4abeb0 50 push   eax
0x4abeb1 83ec0c sub    esp,0xc
0x4abeb4 56 push   esi
0x4abeb5 a1201fd600 mov    eax,ds:0xd61f20
0x4abeba 33c5 xor    eax,ebp
0x4abebc 50 push   eax
0x4abebd 8d45f4 lea    eax,[ebp-0xc]
0x4abec0 64a300000000 mov    fs:0x0,eax
0x4abec6 8b7508 mov    esi,DWORD PTR [ebp+0x8]
0x4abec9 33c0 xor    eax,eax
0x4abecb 8975e8 mov    DWORD PTR [ebp-0x18],esi
0x4abece 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4abed1 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4abed4 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4abed7 8b0d0418fe00 mov    ecx,DWORD PTR ds:0xfe1804
0x4abedd ff150818fe00 call   DWORD PTR ds:0xfe1808
0x4abee3 894508 mov    DWORD PTR [ebp+0x8],eax
0x4abee6 8b4608 mov    eax,DWORD PTR [esi+0x8]
0x4abee9 db4508 fild   DWORD PTR [ebp+0x8]
0x4abeec c7400803000000 mov    DWORD PTR [eax+0x8],0x3
0x4abef3 dd18 fstp   QWORD PTR [eax]
0x4abef5 83460810 add    DWORD PTR [esi+0x8],0x10
0x4abef9 b801000000 mov    eax,0x1
0x4abefe 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4abf01 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4abf08 59 pop    ecx
0x4abf09 5e pop    esi
0x4abf0a 8be5 mov    esp,ebp
0x4abf0c 5d pop    ebp
0x4abf0d c3 ret

; F_004ABF10 0x4abf10..0x4abf66
0x4abf10 55 push   ebp
0x4abf11 8bec mov    ebp,esp
0x4abf13 6aff push   0xffffffff
0x4abf15 68c8839300 push   0x9383c8
0x4abf1a 64a100000000 mov    eax,fs:0x0
0x4abf20 50 push   eax
0x4abf21 83ec0c sub    esp,0xc
0x4abf24 a1201fd600 mov    eax,ds:0xd61f20
0x4abf29 33c5 xor    eax,ebp
0x4abf2b 50 push   eax
0x4abf2c 8d45f4 lea    eax,[ebp-0xc]
0x4abf2f 64a300000000 mov    fs:0x0,eax
0x4abf35 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4abf38 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4abf3b 33c0 xor    eax,eax
0x4abf3d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4abf40 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4abf43 8d4de8 lea    ecx,[ebp-0x18]
0x4abf46 51 push   ecx
0x4abf47 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4abf4a e8510b0000 call   0x4acaa0
0x4abf4f 83c404 add    esp,0x4
0x4abf52 b801000000 mov    eax,0x1
0x4abf57 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4abf5a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4abf61 59 pop    ecx
0x4abf62 8be5 mov    esp,ebp
0x4abf64 5d pop    ebp
0x4abf65 c3 ret

; F_004ACAA0 0x4acaa0..0x4acb6d
0x4acaa0 55 push   ebp
0x4acaa1 8bec mov    ebp,esp
0x4acaa3 83ec18 sub    esp,0x18
0x4acaa6 a10c18fe00 mov    eax,ds:0xfe180c
0x4acaab 8b0d0418fe00 mov    ecx,DWORD PTR ds:0xfe1804
0x4acab1 53 push   ebx
0x4acab2 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x4acab5 56 push   esi
0x4acab6 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4acab9 894dec mov    DWORD PTR [ebp-0x14],ecx
0x4acabc 8b0b mov    ecx,DWORD PTR [ebx]
0x4acabe 57 push   edi
0x4acabf 83c8ff or     eax,0xffffffff
0x4acac2 e829862400 call   0x6f50f0
0x4acac7 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4acaca 83f903 cmp    ecx,0x3
0x4acacd 7426 je     0x4acaf5
0x4acacf 83f904 cmp    ecx,0x4
0x4acad2 755f jne    0x4acb33
0x4acad4 8b30 mov    esi,DWORD PTR [eax]
0x4acad6 83c610 add    esi,0x10
0x4acad9 8d7df8 lea    edi,[ebp-0x8]
0x4acadc e87fac2400 call   0x6f7760
0x4acae1 85c0 test   eax,eax
0x4acae3 744e je     0x4acb33
0x4acae5 dd45f8 fld    QWORD PTR [ebp-0x8]
0x4acae8 c745f803000000 mov    DWORD PTR [ebp-0x8],0x3
0x4acaef dd5df0 fstp   QWORD PTR [ebp-0x10]
0x4acaf2 8d45f0 lea    eax,[ebp-0x10]
0x4acaf5 dd00 fld    QWORD PTR [eax]
0x4acaf7 dd5df8 fstp   QWORD PTR [ebp-0x8]
0x4acafa dd45f8 fld    QWORD PTR [ebp-0x8]
0x4acafd db5d08 fistp  DWORD PTR [ebp+0x8]
0x4acb00 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x4acb03 8955fc mov    DWORD PTR [ebp-0x4],edx
0x4acb06 8b3b mov    edi,DWORD PTR [ebx]
0x4acb08 8b7708 mov    esi,DWORD PTR [edi+0x8]
0x4acb0b 83ee20 sub    esi,0x20
0x4acb0e 837e0804 cmp    DWORD PTR [esi+0x8],0x4
0x4acb12 7440 je     0x4acb54
0x4acb14 e8b7ea2400 call   0x6fb5d0
0x4acb19 85c0 test   eax,eax
0x4acb1b 751f jne    0x4acb3c
0x4acb1d 8b55fc mov    edx,DWORD PTR [ebp-0x4]
0x4acb20 8b4dec mov    ecx,DWORD PTR [ebp-0x14]
0x4acb23 52 push   edx
0x4acb24 33f6 xor    esi,esi
0x4acb26 56 push   esi
0x4acb27 ff55e8 call   DWORD PTR [ebp-0x18]
0x4acb2a 5f pop    edi
0x4acb2b 5e pop    esi
0x4acb2c 33c0 xor    eax,eax
0x4acb2e 5b pop    ebx
0x4acb2f 8be5 mov    esp,ebp
0x4acb31 5d pop    ebp
0x4acb32 c3 ret
0x4acb33 c745fc00000000 mov    DWORD PTR [ebp-0x4],0x0
0x4acb3a ebca jmp    0x4acb06
0x4acb3c 8b4710 mov    eax,DWORD PTR [edi+0x10]
0x4acb3f 8b4844 mov    ecx,DWORD PTR [eax+0x44]
0x4acb42 3b4840 cmp    ecx,DWORD PTR [eax+0x40]
0x4acb45 7207 jb     0x4acb4e
0x4acb47 8bc7 mov    eax,edi
0x4acb49 e852e82400 call   0x6fb3a0
0x4acb4e 8b7708 mov    esi,DWORD PTR [edi+0x8]
0x4acb51 83ee20 sub    esi,0x20
0x4acb54 8b36 mov    esi,DWORD PTR [esi]
0x4acb56 8b55fc mov    edx,DWORD PTR [ebp-0x4]
0x4acb59 8b4dec mov    ecx,DWORD PTR [ebp-0x14]
0x4acb5c 52 push   edx
0x4acb5d 83c610 add    esi,0x10
0x4acb60 56 push   esi
0x4acb61 ff55e8 call   DWORD PTR [ebp-0x18]
0x4acb64 5f pop    edi
0x4acb65 5e pop    esi
0x4acb66 33c0 xor    eax,eax
0x4acb68 5b pop    ebx
0x4acb69 8be5 mov    esp,ebp
0x4acb6b 5d pop    ebp
0x4acb6c c3 ret

; F_004ABF70 0x4abf70..0x4abfcc
0x4abf70 55 push   ebp
0x4abf71 8bec mov    ebp,esp
0x4abf73 6aff push   0xffffffff
0x4abf75 68c8839300 push   0x9383c8
0x4abf7a 64a100000000 mov    eax,fs:0x0
0x4abf80 50 push   eax
0x4abf81 83ec0c sub    esp,0xc
0x4abf84 a1201fd600 mov    eax,ds:0xd61f20
0x4abf89 33c5 xor    eax,ebp
0x4abf8b 50 push   eax
0x4abf8c 8d45f4 lea    eax,[ebp-0xc]
0x4abf8f 64a300000000 mov    fs:0x0,eax
0x4abf95 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4abf98 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4abf9b 33c0 xor    eax,eax
0x4abf9d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4abfa0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4abfa3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4abfa6 8b0d1018fe00 mov    ecx,DWORD PTR ds:0xfe1810
0x4abfac 51 push   ecx
0x4abfad 8d45e8 lea    eax,[ebp-0x18]
0x4abfb0 e8bb0b0000 call   0x4acb70
0x4abfb5 83c404 add    esp,0x4
0x4abfb8 b801000000 mov    eax,0x1
0x4abfbd 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4abfc0 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4abfc7 59 pop    ecx
0x4abfc8 8be5 mov    esp,ebp
0x4abfca 5d pop    ebp
0x4abfcb c3 ret

; F_004ACB70 0x4acb70..0x4acbe3
0x4acb70 55 push   ebp
0x4acb71 8bec mov    ebp,esp
0x4acb73 8b08 mov    ecx,DWORD PTR [eax]
0x4acb75 83ec18 sub    esp,0x18
0x4acb78 53 push   ebx
0x4acb79 8b1d0418fe00 mov    ebx,DWORD PTR ds:0xfe1804
0x4acb7f 83c8ff or     eax,0xffffffff
0x4acb82 e869852400 call   0x6f50f0
0x4acb87 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4acb8a 83f903 cmp    ecx,0x3
0x4acb8d 742a je     0x4acbb9
0x4acb8f 83f904 cmp    ecx,0x4
0x4acb92 7540 jne    0x4acbd4
0x4acb94 56 push   esi
0x4acb95 8b30 mov    esi,DWORD PTR [eax]
0x4acb97 57 push   edi
0x4acb98 83c610 add    esi,0x10
0x4acb9b 8d7df8 lea    edi,[ebp-0x8]
0x4acb9e e8bdab2400 call   0x6f7760
0x4acba3 5f pop    edi
0x4acba4 5e pop    esi
0x4acba5 85c0 test   eax,eax
0x4acba7 742b je     0x4acbd4
0x4acba9 dd45f8 fld    QWORD PTR [ebp-0x8]
0x4acbac c745f003000000 mov    DWORD PTR [ebp-0x10],0x3
0x4acbb3 dd5de8 fstp   QWORD PTR [ebp-0x18]
0x4acbb6 8d45e8 lea    eax,[ebp-0x18]
0x4acbb9 dd00 fld    QWORD PTR [eax]
0x4acbbb dd5df0 fstp   QWORD PTR [ebp-0x10]
0x4acbbe dd45f0 fld    QWORD PTR [ebp-0x10]
0x4acbc1 db5dfc fistp  DWORD PTR [ebp-0x4]
0x4acbc4 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x4acbc7 50 push   eax
0x4acbc8 8bcb mov    ecx,ebx
0x4acbca ff5508 call   DWORD PTR [ebp+0x8]
0x4acbcd 33c0 xor    eax,eax
0x4acbcf 5b pop    ebx
0x4acbd0 8be5 mov    esp,ebp
0x4acbd2 5d pop    ebp
0x4acbd3 c3 ret
0x4acbd4 33c0 xor    eax,eax
0x4acbd6 50 push   eax
0x4acbd7 8bcb mov    ecx,ebx
0x4acbd9 ff5508 call   DWORD PTR [ebp+0x8]
0x4acbdc 33c0 xor    eax,eax
0x4acbde 5b pop    ebx
0x4acbdf 8be5 mov    esp,ebp
0x4acbe1 5d pop    ebp
0x4acbe2 c3 ret

; F_004ABFD0 0x4abfd0..0x4ac026
0x4abfd0 55 push   ebp
0x4abfd1 8bec mov    ebp,esp
0x4abfd3 6aff push   0xffffffff
0x4abfd5 68c8839300 push   0x9383c8
0x4abfda 64a100000000 mov    eax,fs:0x0
0x4abfe0 50 push   eax
0x4abfe1 83ec0c sub    esp,0xc
0x4abfe4 a1201fd600 mov    eax,ds:0xd61f20
0x4abfe9 33c5 xor    eax,ebp
0x4abfeb 50 push   eax
0x4abfec 8d45f4 lea    eax,[ebp-0xc]
0x4abfef 64a300000000 mov    fs:0x0,eax
0x4abff5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4abff8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4abffb 33c0 xor    eax,eax
0x4abffd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac000 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac003 8d4de8 lea    ecx,[ebp-0x18]
0x4ac006 51 push   ecx
0x4ac007 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac00a e8e10b0000 call   0x4acbf0
0x4ac00f 83c404 add    esp,0x4
0x4ac012 b801000000 mov    eax,0x1
0x4ac017 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac01a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac021 59 pop    ecx
0x4ac022 8be5 mov    esp,ebp
0x4ac024 5d pop    ebp
0x4ac025 c3 ret

; F_004ACBF0 0x4acbf0..0x4acd2a
0x4acbf0 55 push   ebp
0x4acbf1 8bec mov    ebp,esp
0x4acbf3 83ec30 sub    esp,0x30
0x4acbf6 a11418fe00 mov    eax,ds:0xfe1814
0x4acbfb 8b0d0418fe00 mov    ecx,DWORD PTR ds:0xfe1804
0x4acc01 53 push   ebx
0x4acc02 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x4acc05 56 push   esi
0x4acc06 8945e0 mov    DWORD PTR [ebp-0x20],eax
0x4acc09 894de4 mov    DWORD PTR [ebp-0x1c],ecx
0x4acc0c 8b0b mov    ecx,DWORD PTR [ebx]
0x4acc0e 57 push   edi
0x4acc0f 83c8ff or     eax,0xffffffff
0x4acc12 e8d9842400 call   0x6f50f0
0x4acc17 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4acc1a 83f903 cmp    ecx,0x3
0x4acc1d 742e je     0x4acc4d
0x4acc1f 83f904 cmp    ecx,0x4
0x4acc22 0f85e9000000 jne    0x4acd11
0x4acc28 8b30 mov    esi,DWORD PTR [eax]
0x4acc2a 83c610 add    esi,0x10
0x4acc2d 8d7de8 lea    edi,[ebp-0x18]
0x4acc30 e82bab2400 call   0x6f7760
0x4acc35 85c0 test   eax,eax
0x4acc37 0f84d4000000 je     0x4acd11
0x4acc3d dd45e8 fld    QWORD PTR [ebp-0x18]
0x4acc40 c745d803000000 mov    DWORD PTR [ebp-0x28],0x3
0x4acc47 dd5dd0 fstp   QWORD PTR [ebp-0x30]
0x4acc4a 8d45d0 lea    eax,[ebp-0x30]
0x4acc4d dd00 fld    QWORD PTR [eax]
0x4acc4f dd5de8 fstp   QWORD PTR [ebp-0x18]
0x4acc52 dd45e8 fld    QWORD PTR [ebp-0x18]
0x4acc55 db5d08 fistp  DWORD PTR [ebp+0x8]
0x4acc58 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x4acc5b 8955f0 mov    DWORD PTR [ebp-0x10],edx
0x4acc5e 8b0b mov    ecx,DWORD PTR [ebx]
0x4acc60 b8feffffff mov    eax,0xfffffffe
0x4acc65 e886842400 call   0x6f50f0
0x4acc6a 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4acc6d 83f903 cmp    ecx,0x3
0x4acc70 742e je     0x4acca0
0x4acc72 83f904 cmp    ecx,0x4
0x4acc75 0f85a2000000 jne    0x4acd1d
0x4acc7b 8b30 mov    esi,DWORD PTR [eax]
0x4acc7d 83c610 add    esi,0x10
0x4acc80 8d7de8 lea    edi,[ebp-0x18]
0x4acc83 e8d8aa2400 call   0x6f7760
0x4acc88 85c0 test   eax,eax
0x4acc8a 0f848d000000 je     0x4acd1d
0x4acc90 dd45e8 fld    QWORD PTR [ebp-0x18]
0x4acc93 c745d803000000 mov    DWORD PTR [ebp-0x28],0x3
0x4acc9a dd5dd0 fstp   QWORD PTR [ebp-0x30]
0x4acc9d 8d45d0 lea    eax,[ebp-0x30]
0x4acca0 dd00 fld    QWORD PTR [eax]
0x4acca2 dd5de8 fstp   QWORD PTR [ebp-0x18]
0x4acca5 dd45e8 fld    QWORD PTR [ebp-0x18]
0x4acca8 db5dfc fistp  DWORD PTR [ebp-0x4]
0x4accab 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x4accae 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4accb1 8b0b mov    ecx,DWORD PTR [ebx]
0x4accb3 b8fdffffff mov    eax,0xfffffffd
0x4accb8 e833842400 call   0x6f50f0
0x4accbd 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4accc0 83f903 cmp    ecx,0x3
0x4accc3 7426 je     0x4acceb
0x4accc5 83f904 cmp    ecx,0x4
0x4accc8 755c jne    0x4acd26
0x4accca 8b30 mov    esi,DWORD PTR [eax]
0x4acccc 83c610 add    esi,0x10
0x4acccf 8d7df4 lea    edi,[ebp-0xc]
0x4accd2 e889aa2400 call   0x6f7760
0x4accd7 85c0 test   eax,eax
0x4accd9 744b je     0x4acd26
0x4accdb dd45f4 fld    QWORD PTR [ebp-0xc]
0x4accde c745d803000000 mov    DWORD PTR [ebp-0x28],0x3
0x4acce5 dd5dd0 fstp   QWORD PTR [ebp-0x30]
0x4acce8 8d45d0 lea    eax,[ebp-0x30]
0x4acceb dd00 fld    QWORD PTR [eax]
0x4acced dd5dd8 fstp   QWORD PTR [ebp-0x28]
0x4accf0 dd45d8 fld    QWORD PTR [ebp-0x28]
0x4accf3 db5df8 fistp  DWORD PTR [ebp-0x8]
0x4accf6 8b45f8 mov    eax,DWORD PTR [ebp-0x8]
0x4accf9 8b4df0 mov    ecx,DWORD PTR [ebp-0x10]
0x4accfc 8b55ec mov    edx,DWORD PTR [ebp-0x14]
0x4accff 51 push   ecx
0x4acd00 8b4de4 mov    ecx,DWORD PTR [ebp-0x1c]
0x4acd03 52 push   edx
0x4acd04 50 push   eax
0x4acd05 ff55e0 call   DWORD PTR [ebp-0x20]
0x4acd08 5f pop    edi
0x4acd09 5e pop    esi
0x4acd0a 33c0 xor    eax,eax
0x4acd0c 5b pop    ebx
0x4acd0d 8be5 mov    esp,ebp
0x4acd0f 5d pop    ebp
0x4acd10 c3 ret
0x4acd11 c745f000000000 mov    DWORD PTR [ebp-0x10],0x0
0x4acd18 e941ffffff jmp    0x4acc5e
0x4acd1d c745ec00000000 mov    DWORD PTR [ebp-0x14],0x0
0x4acd24 eb8b jmp    0x4accb1
0x4acd26 33c0 xor    eax,eax
0x4acd28 ebcf jmp    0x4accf9

; F_004AC030 0x4ac030..0x4ac08c
0x4ac030 55 push   ebp
0x4ac031 8bec mov    ebp,esp
0x4ac033 6aff push   0xffffffff
0x4ac035 68c8839300 push   0x9383c8
0x4ac03a 64a100000000 mov    eax,fs:0x0
0x4ac040 50 push   eax
0x4ac041 83ec0c sub    esp,0xc
0x4ac044 a1201fd600 mov    eax,ds:0xd61f20
0x4ac049 33c5 xor    eax,ebp
0x4ac04b 50 push   eax
0x4ac04c 8d45f4 lea    eax,[ebp-0xc]
0x4ac04f 64a300000000 mov    fs:0x0,eax
0x4ac055 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4ac058 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4ac05b 33c0 xor    eax,eax
0x4ac05d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac060 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac063 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac066 8b0d1818fe00 mov    ecx,DWORD PTR ds:0xfe1818
0x4ac06c 51 push   ecx
0x4ac06d 8d45e8 lea    eax,[ebp-0x18]
0x4ac070 e8fb0a0000 call   0x4acb70
0x4ac075 83c404 add    esp,0x4
0x4ac078 b801000000 mov    eax,0x1
0x4ac07d 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac080 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac087 59 pop    ecx
0x4ac088 8be5 mov    esp,ebp
0x4ac08a 5d pop    ebp
0x4ac08b c3 ret

; F_004AC090 0x4ac090..0x4ac0e6
0x4ac090 55 push   ebp
0x4ac091 8bec mov    ebp,esp
0x4ac093 6aff push   0xffffffff
0x4ac095 68c8839300 push   0x9383c8
0x4ac09a 64a100000000 mov    eax,fs:0x0
0x4ac0a0 50 push   eax
0x4ac0a1 83ec0c sub    esp,0xc
0x4ac0a4 a1201fd600 mov    eax,ds:0xd61f20
0x4ac0a9 33c5 xor    eax,ebp
0x4ac0ab 50 push   eax
0x4ac0ac 8d45f4 lea    eax,[ebp-0xc]
0x4ac0af 64a300000000 mov    fs:0x0,eax
0x4ac0b5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4ac0b8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4ac0bb 33c0 xor    eax,eax
0x4ac0bd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac0c0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac0c3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac0c6 8b0d0418fe00 mov    ecx,DWORD PTR ds:0xfe1804
0x4ac0cc ff151c18fe00 call   DWORD PTR ds:0xfe181c
0x4ac0d2 b801000000 mov    eax,0x1
0x4ac0d7 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac0da 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac0e1 59 pop    ecx
0x4ac0e2 8be5 mov    esp,ebp
0x4ac0e4 5d pop    ebp
0x4ac0e5 c3 ret

; F_004AC0F0 0x4ac0f0..0x4ac14c
0x4ac0f0 55 push   ebp
0x4ac0f1 8bec mov    ebp,esp
0x4ac0f3 6aff push   0xffffffff
0x4ac0f5 68c8839300 push   0x9383c8
0x4ac0fa 64a100000000 mov    eax,fs:0x0
0x4ac100 50 push   eax
0x4ac101 83ec0c sub    esp,0xc
0x4ac104 a1201fd600 mov    eax,ds:0xd61f20
0x4ac109 33c5 xor    eax,ebp
0x4ac10b 50 push   eax
0x4ac10c 8d45f4 lea    eax,[ebp-0xc]
0x4ac10f 64a300000000 mov    fs:0x0,eax
0x4ac115 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4ac118 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4ac11b 33c0 xor    eax,eax
0x4ac11d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac120 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac123 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac126 8b0d2018fe00 mov    ecx,DWORD PTR ds:0xfe1820
0x4ac12c 51 push   ecx
0x4ac12d 8d45e8 lea    eax,[ebp-0x18]
0x4ac130 e8fb0b0000 call   0x4acd30
0x4ac135 83c404 add    esp,0x4
0x4ac138 b801000000 mov    eax,0x1
0x4ac13d 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac140 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac147 59 pop    ecx
0x4ac148 8be5 mov    esp,ebp
0x4ac14a 5d pop    ebp
0x4ac14b c3 ret

; F_004ACD30 0x4acd30..0x4acd8c
0x4acd30 55 push   ebp
0x4acd31 8bec mov    ebp,esp
0x4acd33 53 push   ebx
0x4acd34 8b1d0418fe00 mov    ebx,DWORD PTR ds:0xfe1804
0x4acd3a 56 push   esi
0x4acd3b 57 push   edi
0x4acd3c 8b38 mov    edi,DWORD PTR [eax]
0x4acd3e 8b7708 mov    esi,DWORD PTR [edi+0x8]
0x4acd41 83ee10 sub    esi,0x10
0x4acd44 837e0804 cmp    DWORD PTR [esi+0x8],0x4
0x4acd48 7430 je     0x4acd7a
0x4acd4a e881e82400 call   0x6fb5d0
0x4acd4f 85c0 test   eax,eax
0x4acd51 750f jne    0x4acd62
0x4acd53 33f6 xor    esi,esi
0x4acd55 56 push   esi
0x4acd56 8bcb mov    ecx,ebx
0x4acd58 ff5508 call   DWORD PTR [ebp+0x8]
0x4acd5b 5f pop    edi
0x4acd5c 5e pop    esi
0x4acd5d 33c0 xor    eax,eax
0x4acd5f 5b pop    ebx
0x4acd60 5d pop    ebp
0x4acd61 c3 ret
0x4acd62 8b4710 mov    eax,DWORD PTR [edi+0x10]
0x4acd65 8b4844 mov    ecx,DWORD PTR [eax+0x44]
0x4acd68 3b4840 cmp    ecx,DWORD PTR [eax+0x40]
0x4acd6b 7207 jb     0x4acd74
0x4acd6d 8bc7 mov    eax,edi
0x4acd6f e82ce62400 call   0x6fb3a0
0x4acd74 8b7708 mov    esi,DWORD PTR [edi+0x8]
0x4acd77 83ee10 sub    esi,0x10
0x4acd7a 8b36 mov    esi,DWORD PTR [esi]
0x4acd7c 83c610 add    esi,0x10
0x4acd7f 56 push   esi
0x4acd80 8bcb mov    ecx,ebx
0x4acd82 ff5508 call   DWORD PTR [ebp+0x8]
0x4acd85 5f pop    edi
0x4acd86 5e pop    esi
0x4acd87 33c0 xor    eax,eax
0x4acd89 5b pop    ebx
0x4acd8a 5d pop    ebp
0x4acd8b c3 ret

; F_004AC150 0x4ac150..0x4ac1ac
0x4ac150 55 push   ebp
0x4ac151 8bec mov    ebp,esp
0x4ac153 6aff push   0xffffffff
0x4ac155 68c8839300 push   0x9383c8
0x4ac15a 64a100000000 mov    eax,fs:0x0
0x4ac160 50 push   eax
0x4ac161 83ec0c sub    esp,0xc
0x4ac164 a1201fd600 mov    eax,ds:0xd61f20
0x4ac169 33c5 xor    eax,ebp
0x4ac16b 50 push   eax
0x4ac16c 8d45f4 lea    eax,[ebp-0xc]
0x4ac16f 64a300000000 mov    fs:0x0,eax
0x4ac175 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4ac178 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4ac17b 33c0 xor    eax,eax
0x4ac17d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac180 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac183 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac186 8b0d2418fe00 mov    ecx,DWORD PTR ds:0xfe1824
0x4ac18c 51 push   ecx
0x4ac18d 8d45e8 lea    eax,[ebp-0x18]
0x4ac190 e89b0b0000 call   0x4acd30
0x4ac195 83c404 add    esp,0x4
0x4ac198 b801000000 mov    eax,0x1
0x4ac19d 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac1a0 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac1a7 59 pop    ecx
0x4ac1a8 8be5 mov    esp,ebp
0x4ac1aa 5d pop    ebp
0x4ac1ab c3 ret

; F_004AC1B0 0x4ac1b0..0x4ac206
0x4ac1b0 55 push   ebp
0x4ac1b1 8bec mov    ebp,esp
0x4ac1b3 6aff push   0xffffffff
0x4ac1b5 68c8839300 push   0x9383c8
0x4ac1ba 64a100000000 mov    eax,fs:0x0
0x4ac1c0 50 push   eax
0x4ac1c1 83ec0c sub    esp,0xc
0x4ac1c4 a1201fd600 mov    eax,ds:0xd61f20
0x4ac1c9 33c5 xor    eax,ebp
0x4ac1cb 50 push   eax
0x4ac1cc 8d45f4 lea    eax,[ebp-0xc]
0x4ac1cf 64a300000000 mov    fs:0x0,eax
0x4ac1d5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4ac1d8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4ac1db 33c0 xor    eax,eax
0x4ac1dd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac1e0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac1e3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac1e6 8b0d0418fe00 mov    ecx,DWORD PTR ds:0xfe1804
0x4ac1ec ff152818fe00 call   DWORD PTR ds:0xfe1828
0x4ac1f2 b801000000 mov    eax,0x1
0x4ac1f7 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac1fa 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac201 59 pop    ecx
0x4ac202 8be5 mov    esp,ebp
0x4ac204 5d pop    ebp
0x4ac205 c3 ret

; F_004AC210 0x4ac210..0x4ac26d
0x4ac210 55 push   ebp
0x4ac211 8bec mov    ebp,esp
0x4ac213 6aff push   0xffffffff
0x4ac215 68c8839300 push   0x9383c8
0x4ac21a 64a100000000 mov    eax,fs:0x0
0x4ac220 50 push   eax
0x4ac221 83ec0c sub    esp,0xc
0x4ac224 a1201fd600 mov    eax,ds:0xd61f20
0x4ac229 33c5 xor    eax,ebp
0x4ac22b 50 push   eax
0x4ac22c 8d45f4 lea    eax,[ebp-0xc]
0x4ac22f 64a300000000 mov    fs:0x0,eax
0x4ac235 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4ac238 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4ac23b 33c0 xor    eax,eax
0x4ac23d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac240 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac243 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac246 8b0d2c18fe00 mov    ecx,DWORD PTR ds:0xfe182c
0x4ac24c 51 push   ecx
0x4ac24d 8d55e8 lea    edx,[ebp-0x18]
0x4ac250 52 push   edx
0x4ac251 e83a0b0000 call   0x4acd90
0x4ac256 83c408 add    esp,0x8
0x4ac259 b801000000 mov    eax,0x1
0x4ac25e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac261 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac268 59 pop    ecx
0x4ac269 8be5 mov    esp,ebp
0x4ac26b 5d pop    ebp
0x4ac26c c3 ret

; F_004ACD90 0x4acd90..0x4ace6c
0x4acd90 55 push   ebp
0x4acd91 8bec mov    ebp,esp
0x4acd93 83ec24 sub    esp,0x24
0x4acd96 a10418fe00 mov    eax,ds:0xfe1804
0x4acd9b 53 push   ebx
0x4acd9c 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x4acd9f 8b0b mov    ecx,DWORD PTR [ebx]
0x4acda1 56 push   esi
0x4acda2 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4acda5 57 push   edi
0x4acda6 83c8ff or     eax,0xffffffff
0x4acda9 e842832400 call   0x6f50f0
0x4acdae 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4acdb1 83f903 cmp    ecx,0x3
0x4acdb4 742a je     0x4acde0
0x4acdb6 83f904 cmp    ecx,0x4
0x4acdb9 0f858e000000 jne    0x4ace4d
0x4acdbf 8b30 mov    esi,DWORD PTR [eax]
0x4acdc1 83c610 add    esi,0x10
0x4acdc4 8d7df0 lea    edi,[ebp-0x10]
0x4acdc7 e894a92400 call   0x6f7760
0x4acdcc 85c0 test   eax,eax
0x4acdce 747d je     0x4ace4d
0x4acdd0 dd45f0 fld    QWORD PTR [ebp-0x10]
0x4acdd3 c745e403000000 mov    DWORD PTR [ebp-0x1c],0x3
0x4acdda dd5ddc fstp   QWORD PTR [ebp-0x24]
0x4acddd 8d45dc lea    eax,[ebp-0x24]
0x4acde0 dd00 fld    QWORD PTR [eax]
0x4acde2 dd5df0 fstp   QWORD PTR [ebp-0x10]
0x4acde5 dd45f0 fld    QWORD PTR [ebp-0x10]
0x4acde8 db5d08 fistp  DWORD PTR [ebp+0x8]
0x4acdeb 8b4d08 mov    ecx,DWORD PTR [ebp+0x8]
0x4acdee 894df4 mov    DWORD PTR [ebp-0xc],ecx
0x4acdf1 8b0b mov    ecx,DWORD PTR [ebx]
0x4acdf3 b8feffffff mov    eax,0xfffffffe
0x4acdf8 e8f3822400 call   0x6f50f0
0x4acdfd 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4ace00 83f903 cmp    ecx,0x3
0x4ace03 7426 je     0x4ace2b
0x4ace05 83f904 cmp    ecx,0x4
0x4ace08 754c jne    0x4ace56
0x4ace0a 8b30 mov    esi,DWORD PTR [eax]
0x4ace0c 83c610 add    esi,0x10
0x4ace0f 8d7df8 lea    edi,[ebp-0x8]
0x4ace12 e849a92400 call   0x6f7760
0x4ace17 85c0 test   eax,eax
0x4ace19 743b je     0x4ace56
0x4ace1b dd45f8 fld    QWORD PTR [ebp-0x8]
0x4ace1e c745e403000000 mov    DWORD PTR [ebp-0x1c],0x3
0x4ace25 dd5ddc fstp   QWORD PTR [ebp-0x24]
0x4ace28 8d45dc lea    eax,[ebp-0x24]
0x4ace2b dd00 fld    QWORD PTR [eax]
0x4ace2d dd5de4 fstp   QWORD PTR [ebp-0x1c]
0x4ace30 dd45e4 fld    QWORD PTR [ebp-0x1c]
0x4ace33 db5dfc fistp  DWORD PTR [ebp-0x4]
0x4ace36 8b55f4 mov    edx,DWORD PTR [ebp-0xc]
0x4ace39 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x4ace3c 8b4dec mov    ecx,DWORD PTR [ebp-0x14]
0x4ace3f 52 push   edx
0x4ace40 50 push   eax
0x4ace41 ff550c call   DWORD PTR [ebp+0xc]
0x4ace44 5f pop    edi
0x4ace45 5e pop    esi
0x4ace46 33c0 xor    eax,eax
0x4ace48 5b pop    ebx
0x4ace49 8be5 mov    esp,ebp
0x4ace4b 5d pop    ebp
0x4ace4c c3 ret
0x4ace4d c745f400000000 mov    DWORD PTR [ebp-0xc],0x0
0x4ace54 eb9b jmp    0x4acdf1
0x4ace56 8b55f4 mov    edx,DWORD PTR [ebp-0xc]
0x4ace59 8b4dec mov    ecx,DWORD PTR [ebp-0x14]
0x4ace5c 33c0 xor    eax,eax
0x4ace5e 52 push   edx
0x4ace5f 50 push   eax
0x4ace60 ff550c call   DWORD PTR [ebp+0xc]
0x4ace63 5f pop    edi
0x4ace64 5e pop    esi
0x4ace65 33c0 xor    eax,eax
0x4ace67 5b pop    ebx
0x4ace68 8be5 mov    esp,ebp
0x4ace6a 5d pop    ebp
0x4ace6b c3 ret

; F_004AC270 0x4ac270..0x4ac2de
0x4ac270 55 push   ebp
0x4ac271 8bec mov    ebp,esp
0x4ac273 6aff push   0xffffffff
0x4ac275 68d8879300 push   0x9387d8
0x4ac27a 64a100000000 mov    eax,fs:0x0
0x4ac280 50 push   eax
0x4ac281 83ec0c sub    esp,0xc
0x4ac284 56 push   esi
0x4ac285 a1201fd600 mov    eax,ds:0xd61f20
0x4ac28a 33c5 xor    eax,ebp
0x4ac28c 50 push   eax
0x4ac28d 8d45f4 lea    eax,[ebp-0xc]
0x4ac290 64a300000000 mov    fs:0x0,eax
0x4ac296 8b7508 mov    esi,DWORD PTR [ebp+0x8]
0x4ac299 33c0 xor    eax,eax
0x4ac29b 8975e8 mov    DWORD PTR [ebp-0x18],esi
0x4ac29e 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac2a1 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac2a4 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac2a7 8b0d0418fe00 mov    ecx,DWORD PTR ds:0xfe1804
0x4ac2ad ff153018fe00 call   DWORD PTR ds:0xfe1830
0x4ac2b3 894508 mov    DWORD PTR [ebp+0x8],eax
0x4ac2b6 8b4608 mov    eax,DWORD PTR [esi+0x8]
0x4ac2b9 db4508 fild   DWORD PTR [ebp+0x8]
0x4ac2bc c7400803000000 mov    DWORD PTR [eax+0x8],0x3
0x4ac2c3 dd18 fstp   QWORD PTR [eax]
0x4ac2c5 83460810 add    DWORD PTR [esi+0x8],0x10
0x4ac2c9 b801000000 mov    eax,0x1
0x4ac2ce 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac2d1 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac2d8 59 pop    ecx
0x4ac2d9 5e pop    esi
0x4ac2da 8be5 mov    esp,ebp
0x4ac2dc 5d pop    ebp
0x4ac2dd c3 ret

; F_004AC2E0 0x4ac2e0..0x4ac336
0x4ac2e0 55 push   ebp
0x4ac2e1 8bec mov    ebp,esp
0x4ac2e3 6aff push   0xffffffff
0x4ac2e5 68c8839300 push   0x9383c8
0x4ac2ea 64a100000000 mov    eax,fs:0x0
0x4ac2f0 50 push   eax
0x4ac2f1 83ec0c sub    esp,0xc
0x4ac2f4 a1201fd600 mov    eax,ds:0xd61f20
0x4ac2f9 33c5 xor    eax,ebp
0x4ac2fb 50 push   eax
0x4ac2fc 8d45f4 lea    eax,[ebp-0xc]
0x4ac2ff 64a300000000 mov    fs:0x0,eax
0x4ac305 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4ac308 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4ac30b 33c0 xor    eax,eax
0x4ac30d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac310 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac313 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac316 8b0d0418fe00 mov    ecx,DWORD PTR ds:0xfe1804
0x4ac31c ff153418fe00 call   DWORD PTR ds:0xfe1834
0x4ac322 b801000000 mov    eax,0x1
0x4ac327 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac32a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac331 59 pop    ecx
0x4ac332 8be5 mov    esp,ebp
0x4ac334 5d pop    ebp
0x4ac335 c3 ret

; F_004AC340 0x4ac340..0x4ac39c
0x4ac340 55 push   ebp
0x4ac341 8bec mov    ebp,esp
0x4ac343 6aff push   0xffffffff
0x4ac345 68c8839300 push   0x9383c8
0x4ac34a 64a100000000 mov    eax,fs:0x0
0x4ac350 50 push   eax
0x4ac351 83ec0c sub    esp,0xc
0x4ac354 a1201fd600 mov    eax,ds:0xd61f20
0x4ac359 33c5 xor    eax,ebp
0x4ac35b 50 push   eax
0x4ac35c 8d45f4 lea    eax,[ebp-0xc]
0x4ac35f 64a300000000 mov    fs:0x0,eax
0x4ac365 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4ac368 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4ac36b 33c0 xor    eax,eax
0x4ac36d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac370 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac373 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac376 8b0d3818fe00 mov    ecx,DWORD PTR ds:0xfe1838
0x4ac37c 51 push   ecx
0x4ac37d 8d45e8 lea    eax,[ebp-0x18]
0x4ac380 e8eb070000 call   0x4acb70
0x4ac385 83c404 add    esp,0x4
0x4ac388 b801000000 mov    eax,0x1
0x4ac38d 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac390 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac397 59 pop    ecx
0x4ac398 8be5 mov    esp,ebp
0x4ac39a 5d pop    ebp
0x4ac39b c3 ret

; F_004AC3A0 0x4ac3a0..0x4ac3fd
0x4ac3a0 55 push   ebp
0x4ac3a1 8bec mov    ebp,esp
0x4ac3a3 6aff push   0xffffffff
0x4ac3a5 68c8839300 push   0x9383c8
0x4ac3aa 64a100000000 mov    eax,fs:0x0
0x4ac3b0 50 push   eax
0x4ac3b1 83ec0c sub    esp,0xc
0x4ac3b4 a1201fd600 mov    eax,ds:0xd61f20
0x4ac3b9 33c5 xor    eax,ebp
0x4ac3bb 50 push   eax
0x4ac3bc 8d45f4 lea    eax,[ebp-0xc]
0x4ac3bf 64a300000000 mov    fs:0x0,eax
0x4ac3c5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4ac3c8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4ac3cb 33c0 xor    eax,eax
0x4ac3cd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac3d0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac3d3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac3d6 8b0d3c18fe00 mov    ecx,DWORD PTR ds:0xfe183c
0x4ac3dc 51 push   ecx
0x4ac3dd 8d55e8 lea    edx,[ebp-0x18]
0x4ac3e0 52 push   edx
0x4ac3e1 e8aa090000 call   0x4acd90
0x4ac3e6 83c408 add    esp,0x8
0x4ac3e9 b801000000 mov    eax,0x1
0x4ac3ee 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac3f1 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac3f8 59 pop    ecx
0x4ac3f9 8be5 mov    esp,ebp
0x4ac3fb 5d pop    ebp
0x4ac3fc c3 ret

; F_004AC400 0x4ac400..0x4ac456
0x4ac400 55 push   ebp
0x4ac401 8bec mov    ebp,esp
0x4ac403 6aff push   0xffffffff
0x4ac405 68c8839300 push   0x9383c8
0x4ac40a 64a100000000 mov    eax,fs:0x0
0x4ac410 50 push   eax
0x4ac411 83ec0c sub    esp,0xc
0x4ac414 a1201fd600 mov    eax,ds:0xd61f20
0x4ac419 33c5 xor    eax,ebp
0x4ac41b 50 push   eax
0x4ac41c 8d45f4 lea    eax,[ebp-0xc]
0x4ac41f 64a300000000 mov    fs:0x0,eax
0x4ac425 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4ac428 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4ac42b 33c0 xor    eax,eax
0x4ac42d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac430 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac433 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac436 8b0d0418fe00 mov    ecx,DWORD PTR ds:0xfe1804
0x4ac43c ff154018fe00 call   DWORD PTR ds:0xfe1840
0x4ac442 b801000000 mov    eax,0x1
0x4ac447 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac44a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac451 59 pop    ecx
0x4ac452 8be5 mov    esp,ebp
0x4ac454 5d pop    ebp
0x4ac455 c3 ret

; F_004AC460 0x4ac460..0x4ac4b6
0x4ac460 55 push   ebp
0x4ac461 8bec mov    ebp,esp
0x4ac463 6aff push   0xffffffff
0x4ac465 68c8839300 push   0x9383c8
0x4ac46a 64a100000000 mov    eax,fs:0x0
0x4ac470 50 push   eax
0x4ac471 83ec0c sub    esp,0xc
0x4ac474 a1201fd600 mov    eax,ds:0xd61f20
0x4ac479 33c5 xor    eax,ebp
0x4ac47b 50 push   eax
0x4ac47c 8d45f4 lea    eax,[ebp-0xc]
0x4ac47f 64a300000000 mov    fs:0x0,eax
0x4ac485 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4ac488 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4ac48b 33c0 xor    eax,eax
0x4ac48d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac490 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac493 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac496 8b0d0418fe00 mov    ecx,DWORD PTR ds:0xfe1804
0x4ac49c ff154418fe00 call   DWORD PTR ds:0xfe1844
0x4ac4a2 b801000000 mov    eax,0x1
0x4ac4a7 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac4aa 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac4b1 59 pop    ecx
0x4ac4b2 8be5 mov    esp,ebp
0x4ac4b4 5d pop    ebp
0x4ac4b5 c3 ret

; F_004AC4C0 0x4ac4c0..0x4ac51c
0x4ac4c0 55 push   ebp
0x4ac4c1 8bec mov    ebp,esp
0x4ac4c3 6aff push   0xffffffff
0x4ac4c5 68c8839300 push   0x9383c8
0x4ac4ca 64a100000000 mov    eax,fs:0x0
0x4ac4d0 50 push   eax
0x4ac4d1 83ec0c sub    esp,0xc
0x4ac4d4 a1201fd600 mov    eax,ds:0xd61f20
0x4ac4d9 33c5 xor    eax,ebp
0x4ac4db 50 push   eax
0x4ac4dc 8d45f4 lea    eax,[ebp-0xc]
0x4ac4df 64a300000000 mov    fs:0x0,eax
0x4ac4e5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4ac4e8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4ac4eb 33c0 xor    eax,eax
0x4ac4ed 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac4f0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac4f3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac4f6 8b0d4818fe00 mov    ecx,DWORD PTR ds:0xfe1848
0x4ac4fc 51 push   ecx
0x4ac4fd 8d45e8 lea    eax,[ebp-0x18]
0x4ac500 e82b080000 call   0x4acd30
0x4ac505 83c404 add    esp,0x4
0x4ac508 b801000000 mov    eax,0x1
0x4ac50d 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac510 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac517 59 pop    ecx
0x4ac518 8be5 mov    esp,ebp
0x4ac51a 5d pop    ebp
0x4ac51b c3 ret

; F_004AC520 0x4ac520..0x4ac576
0x4ac520 55 push   ebp
0x4ac521 8bec mov    ebp,esp
0x4ac523 6aff push   0xffffffff
0x4ac525 68c8839300 push   0x9383c8
0x4ac52a 64a100000000 mov    eax,fs:0x0
0x4ac530 50 push   eax
0x4ac531 83ec0c sub    esp,0xc
0x4ac534 a1201fd600 mov    eax,ds:0xd61f20
0x4ac539 33c5 xor    eax,ebp
0x4ac53b 50 push   eax
0x4ac53c 8d45f4 lea    eax,[ebp-0xc]
0x4ac53f 64a300000000 mov    fs:0x0,eax
0x4ac545 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4ac548 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4ac54b 33c0 xor    eax,eax
0x4ac54d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac550 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac553 8d4de8 lea    ecx,[ebp-0x18]
0x4ac556 51 push   ecx
0x4ac557 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac55a e811090000 call   0x4ace70
0x4ac55f 83c404 add    esp,0x4
0x4ac562 b801000000 mov    eax,0x1
0x4ac567 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac56a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac571 59 pop    ecx
0x4ac572 8be5 mov    esp,ebp
0x4ac574 5d pop    ebp
0x4ac575 c3 ret

; F_004ACE70 0x4ace70..0x4acf8b
0x4ace70 55 push   ebp
0x4ace71 8bec mov    ebp,esp
0x4ace73 83ec20 sub    esp,0x20
0x4ace76 a14c18fe00 mov    eax,ds:0xfe184c
0x4ace7b 8b0d0418fe00 mov    ecx,DWORD PTR ds:0xfe1804
0x4ace81 53 push   ebx
0x4ace82 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x4ace85 56 push   esi
0x4ace86 8945e0 mov    DWORD PTR [ebp-0x20],eax
0x4ace89 894de4 mov    DWORD PTR [ebp-0x1c],ecx
0x4ace8c 8b0b mov    ecx,DWORD PTR [ebx]
0x4ace8e 57 push   edi
0x4ace8f 83c8ff or     eax,0xffffffff
0x4ace92 e859822400 call   0x6f50f0
0x4ace97 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4ace9a 83f903 cmp    ecx,0x3
0x4ace9d 742e je     0x4acecd
0x4ace9f 83f904 cmp    ecx,0x4
0x4acea2 0f859c000000 jne    0x4acf44
0x4acea8 8b30 mov    esi,DWORD PTR [eax]
0x4aceaa 83c610 add    esi,0x10
0x4acead 8d7df0 lea    edi,[ebp-0x10]
0x4aceb0 e8aba82400 call   0x6f7760
0x4aceb5 85c0 test   eax,eax
0x4aceb7 0f8487000000 je     0x4acf44
0x4acebd dd45f0 fld    QWORD PTR [ebp-0x10]
0x4acec0 c745f003000000 mov    DWORD PTR [ebp-0x10],0x3
0x4acec7 dd5de8 fstp   QWORD PTR [ebp-0x18]
0x4aceca 8d45e8 lea    eax,[ebp-0x18]
0x4acecd dd00 fld    QWORD PTR [eax]
0x4acecf dd5df0 fstp   QWORD PTR [ebp-0x10]
0x4aced2 dd45f0 fld    QWORD PTR [ebp-0x10]
0x4aced5 db5d08 fistp  DWORD PTR [ebp+0x8]
0x4aced8 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x4acedb 8955f8 mov    DWORD PTR [ebp-0x8],edx
0x4acede 8b0b mov    ecx,DWORD PTR [ebx]
0x4acee0 b8feffffff mov    eax,0xfffffffe
0x4acee5 e806822400 call   0x6f50f0
0x4aceea 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4aceed 83f903 cmp    ecx,0x3
0x4acef0 7426 je     0x4acf18
0x4acef2 83f904 cmp    ecx,0x4
0x4acef5 7556 jne    0x4acf4d
0x4acef7 8b30 mov    esi,DWORD PTR [eax]
0x4acef9 83c610 add    esi,0x10
0x4acefc 8d7df0 lea    edi,[ebp-0x10]
0x4aceff e85ca82400 call   0x6f7760
0x4acf04 85c0 test   eax,eax
0x4acf06 7445 je     0x4acf4d
0x4acf08 dd45f0 fld    QWORD PTR [ebp-0x10]
0x4acf0b c745f003000000 mov    DWORD PTR [ebp-0x10],0x3
0x4acf12 dd5de8 fstp   QWORD PTR [ebp-0x18]
0x4acf15 8d45e8 lea    eax,[ebp-0x18]
0x4acf18 dd00 fld    QWORD PTR [eax]
0x4acf1a dd5df0 fstp   QWORD PTR [ebp-0x10]
0x4acf1d dd45f0 fld    QWORD PTR [ebp-0x10]
0x4acf20 db5dfc fistp  DWORD PTR [ebp-0x4]
0x4acf23 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x4acf26 8945f4 mov    DWORD PTR [ebp-0xc],eax
0x4acf29 8b3b mov    edi,DWORD PTR [ebx]
0x4acf2b 8b7708 mov    esi,DWORD PTR [edi+0x8]
0x4acf2e 83ee30 sub    esi,0x30
0x4acf31 837e0804 cmp    DWORD PTR [esi+0x8],0x4
0x4acf35 7437 je     0x4acf6e
0x4acf37 e894e62400 call   0x6fb5d0
0x4acf3c 85c0 test   eax,eax
0x4acf3e 7516 jne    0x4acf56
0x4acf40 33f6 xor    esi,esi
0x4acf42 eb2f jmp    0x4acf73
0x4acf44 c745f800000000 mov    DWORD PTR [ebp-0x8],0x0
0x4acf4b eb91 jmp    0x4acede
0x4acf4d c745f400000000 mov    DWORD PTR [ebp-0xc],0x0
0x4acf54 ebd3 jmp    0x4acf29
0x4acf56 8b4710 mov    eax,DWORD PTR [edi+0x10]
0x4acf59 8b4844 mov    ecx,DWORD PTR [eax+0x44]
0x4acf5c 3b4840 cmp    ecx,DWORD PTR [eax+0x40]
0x4acf5f 7207 jb     0x4acf68
0x4acf61 8bc7 mov    eax,edi
0x4acf63 e838e42400 call   0x6fb3a0
0x4acf68 8b7708 mov    esi,DWORD PTR [edi+0x8]
0x4acf6b 83ee30 sub    esi,0x30
0x4acf6e 8b36 mov    esi,DWORD PTR [esi]
0x4acf70 83c610 add    esi,0x10
0x4acf73 8b55f8 mov    edx,DWORD PTR [ebp-0x8]
0x4acf76 8b45f4 mov    eax,DWORD PTR [ebp-0xc]
0x4acf79 8b4de4 mov    ecx,DWORD PTR [ebp-0x1c]
0x4acf7c 52 push   edx
0x4acf7d 50 push   eax
0x4acf7e 56 push   esi
0x4acf7f ff55e0 call   DWORD PTR [ebp-0x20]
0x4acf82 5f pop    edi
0x4acf83 5e pop    esi
0x4acf84 33c0 xor    eax,eax
0x4acf86 5b pop    ebx
0x4acf87 8be5 mov    esp,ebp
0x4acf89 5d pop    ebp
0x4acf8a c3 ret

; F_004AC580 0x4ac580..0x4ac5d6
0x4ac580 55 push   ebp
0x4ac581 8bec mov    ebp,esp
0x4ac583 6aff push   0xffffffff
0x4ac585 68c8839300 push   0x9383c8
0x4ac58a 64a100000000 mov    eax,fs:0x0
0x4ac590 50 push   eax
0x4ac591 83ec0c sub    esp,0xc
0x4ac594 a1201fd600 mov    eax,ds:0xd61f20
0x4ac599 33c5 xor    eax,ebp
0x4ac59b 50 push   eax
0x4ac59c 8d45f4 lea    eax,[ebp-0xc]
0x4ac59f 64a300000000 mov    fs:0x0,eax
0x4ac5a5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4ac5a8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4ac5ab 33c0 xor    eax,eax
0x4ac5ad 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac5b0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac5b3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac5b6 8b0d0418fe00 mov    ecx,DWORD PTR ds:0xfe1804
0x4ac5bc ff155018fe00 call   DWORD PTR ds:0xfe1850
0x4ac5c2 b801000000 mov    eax,0x1
0x4ac5c7 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac5ca 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac5d1 59 pop    ecx
0x4ac5d2 8be5 mov    esp,ebp
0x4ac5d4 5d pop    ebp
0x4ac5d5 c3 ret

; F_004AC5E0 0x4ac5e0..0x4ac63d
0x4ac5e0 55 push   ebp
0x4ac5e1 8bec mov    ebp,esp
0x4ac5e3 6aff push   0xffffffff
0x4ac5e5 68c8839300 push   0x9383c8
0x4ac5ea 64a100000000 mov    eax,fs:0x0
0x4ac5f0 50 push   eax
0x4ac5f1 83ec0c sub    esp,0xc
0x4ac5f4 a1201fd600 mov    eax,ds:0xd61f20
0x4ac5f9 33c5 xor    eax,ebp
0x4ac5fb 50 push   eax
0x4ac5fc 8d45f4 lea    eax,[ebp-0xc]
0x4ac5ff 64a300000000 mov    fs:0x0,eax
0x4ac605 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4ac608 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4ac60b 33c0 xor    eax,eax
0x4ac60d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac610 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac613 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac616 8b0d5418fe00 mov    ecx,DWORD PTR ds:0xfe1854
0x4ac61c 51 push   ecx
0x4ac61d 8d55e8 lea    edx,[ebp-0x18]
0x4ac620 52 push   edx
0x4ac621 e86a090000 call   0x4acf90
0x4ac626 83c408 add    esp,0x8
0x4ac629 b801000000 mov    eax,0x1
0x4ac62e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac631 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac638 59 pop    ecx
0x4ac639 8be5 mov    esp,ebp
0x4ac63b 5d pop    ebp
0x4ac63c c3 ret

; F_004ACF90 0x4acf90..0x4ad019
0x4acf90 55 push   ebp
0x4acf91 8bec mov    ebp,esp
0x4acf93 83ec14 sub    esp,0x14
0x4acf96 a10418fe00 mov    eax,ds:0xfe1804
0x4acf9b 53 push   ebx
0x4acf9c 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x4acf9f 8b0b mov    ecx,DWORD PTR [ebx]
0x4acfa1 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4acfa4 83c8ff or     eax,0xffffffff
0x4acfa7 e844812400 call   0x6f50f0
0x4acfac 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4acfaf 83f903 cmp    ecx,0x3
0x4acfb2 742a je     0x4acfde
0x4acfb4 83f904 cmp    ecx,0x4
0x4acfb7 755c jne    0x4ad015
0x4acfb9 56 push   esi
0x4acfba 8b30 mov    esi,DWORD PTR [eax]
0x4acfbc 57 push   edi
0x4acfbd 83c610 add    esi,0x10
0x4acfc0 8d7df4 lea    edi,[ebp-0xc]
0x4acfc3 e898a72400 call   0x6f7760
0x4acfc8 5f pop    edi
0x4acfc9 5e pop    esi
0x4acfca 85c0 test   eax,eax
0x4acfcc 7447 je     0x4ad015
0x4acfce dd45f4 fld    QWORD PTR [ebp-0xc]
0x4acfd1 c745f403000000 mov    DWORD PTR [ebp-0xc],0x3
0x4acfd8 dd5dec fstp   QWORD PTR [ebp-0x14]
0x4acfdb 8d45ec lea    eax,[ebp-0x14]
0x4acfde dd00 fld    QWORD PTR [eax]
0x4acfe0 dd5df4 fstp   QWORD PTR [ebp-0xc]
0x4acfe3 dd45f4 fld    QWORD PTR [ebp-0xc]
0x4acfe6 db5d08 fistp  DWORD PTR [ebp+0x8]
0x4acfe9 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4acfec 8b4dfc mov    ecx,DWORD PTR [ebp-0x4]
0x4acfef 50 push   eax
0x4acff0 ff550c call   DWORD PTR [ebp+0xc]
0x4acff3 89450c mov    DWORD PTR [ebp+0xc],eax
0x4acff6 8b03 mov    eax,DWORD PTR [ebx]
0x4acff8 db450c fild   DWORD PTR [ebp+0xc]
0x4acffb 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x4acffe c7410803000000 mov    DWORD PTR [ecx+0x8],0x3
0x4ad005 dd19 fstp   QWORD PTR [ecx]
0x4ad007 83400810 add    DWORD PTR [eax+0x8],0x10
0x4ad00b b801000000 mov    eax,0x1
0x4ad010 5b pop    ebx
0x4ad011 8be5 mov    esp,ebp
0x4ad013 5d pop    ebp
0x4ad014 c3 ret
0x4ad015 33c0 xor    eax,eax
0x4ad017 ebd3 jmp    0x4acfec

; F_004AC640 0x4ac640..0x4ac69d
0x4ac640 55 push   ebp
0x4ac641 8bec mov    ebp,esp
0x4ac643 6aff push   0xffffffff
0x4ac645 68c8839300 push   0x9383c8
0x4ac64a 64a100000000 mov    eax,fs:0x0
0x4ac650 50 push   eax
0x4ac651 83ec0c sub    esp,0xc
0x4ac654 a1201fd600 mov    eax,ds:0xd61f20
0x4ac659 33c5 xor    eax,ebp
0x4ac65b 50 push   eax
0x4ac65c 8d45f4 lea    eax,[ebp-0xc]
0x4ac65f 64a300000000 mov    fs:0x0,eax
0x4ac665 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4ac668 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4ac66b 33c0 xor    eax,eax
0x4ac66d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac670 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac673 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac676 8b0d5818fe00 mov    ecx,DWORD PTR ds:0xfe1858
0x4ac67c 51 push   ecx
0x4ac67d 8d55e8 lea    edx,[ebp-0x18]
0x4ac680 52 push   edx
0x4ac681 e80a070000 call   0x4acd90
0x4ac686 83c408 add    esp,0x8
0x4ac689 b801000000 mov    eax,0x1
0x4ac68e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac691 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac698 59 pop    ecx
0x4ac699 8be5 mov    esp,ebp
0x4ac69b 5d pop    ebp
0x4ac69c c3 ret

; F_004AC6A0 0x4ac6a0..0x4ac6fd
0x4ac6a0 55 push   ebp
0x4ac6a1 8bec mov    ebp,esp
0x4ac6a3 6aff push   0xffffffff
0x4ac6a5 68c8839300 push   0x9383c8
0x4ac6aa 64a100000000 mov    eax,fs:0x0
0x4ac6b0 50 push   eax
0x4ac6b1 83ec0c sub    esp,0xc
0x4ac6b4 a1201fd600 mov    eax,ds:0xd61f20
0x4ac6b9 33c5 xor    eax,ebp
0x4ac6bb 50 push   eax
0x4ac6bc 8d45f4 lea    eax,[ebp-0xc]
0x4ac6bf 64a300000000 mov    fs:0x0,eax
0x4ac6c5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4ac6c8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4ac6cb 33c0 xor    eax,eax
0x4ac6cd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac6d0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac6d3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac6d6 8b0d5c18fe00 mov    ecx,DWORD PTR ds:0xfe185c
0x4ac6dc 51 push   ecx
0x4ac6dd 8d55e8 lea    edx,[ebp-0x18]
0x4ac6e0 52 push   edx
0x4ac6e1 e8aa080000 call   0x4acf90
0x4ac6e6 83c408 add    esp,0x8
0x4ac6e9 b801000000 mov    eax,0x1
0x4ac6ee 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac6f1 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac6f8 59 pop    ecx
0x4ac6f9 8be5 mov    esp,ebp
0x4ac6fb 5d pop    ebp
0x4ac6fc c3 ret

; F_004AC700 0x4ac700..0x4ac76e
0x4ac700 55 push   ebp
0x4ac701 8bec mov    ebp,esp
0x4ac703 6aff push   0xffffffff
0x4ac705 68d8879300 push   0x9387d8
0x4ac70a 64a100000000 mov    eax,fs:0x0
0x4ac710 50 push   eax
0x4ac711 83ec0c sub    esp,0xc
0x4ac714 56 push   esi
0x4ac715 a1201fd600 mov    eax,ds:0xd61f20
0x4ac71a 33c5 xor    eax,ebp
0x4ac71c 50 push   eax
0x4ac71d 8d45f4 lea    eax,[ebp-0xc]
0x4ac720 64a300000000 mov    fs:0x0,eax
0x4ac726 8b7508 mov    esi,DWORD PTR [ebp+0x8]
0x4ac729 33c0 xor    eax,eax
0x4ac72b 8975e8 mov    DWORD PTR [ebp-0x18],esi
0x4ac72e 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac731 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac734 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac737 8b0d0418fe00 mov    ecx,DWORD PTR ds:0xfe1804
0x4ac73d ff156018fe00 call   DWORD PTR ds:0xfe1860
0x4ac743 894508 mov    DWORD PTR [ebp+0x8],eax
0x4ac746 8b4608 mov    eax,DWORD PTR [esi+0x8]
0x4ac749 db4508 fild   DWORD PTR [ebp+0x8]
0x4ac74c c7400803000000 mov    DWORD PTR [eax+0x8],0x3
0x4ac753 dd18 fstp   QWORD PTR [eax]
0x4ac755 83460810 add    DWORD PTR [esi+0x8],0x10
0x4ac759 b801000000 mov    eax,0x1
0x4ac75e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac761 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac768 59 pop    ecx
0x4ac769 5e pop    esi
0x4ac76a 8be5 mov    esp,ebp
0x4ac76c 5d pop    ebp
0x4ac76d c3 ret

; F_004AC770 0x4ac770..0x4ac7cc
0x4ac770 55 push   ebp
0x4ac771 8bec mov    ebp,esp
0x4ac773 6aff push   0xffffffff
0x4ac775 68c8839300 push   0x9383c8
0x4ac77a 64a100000000 mov    eax,fs:0x0
0x4ac780 50 push   eax
0x4ac781 83ec0c sub    esp,0xc
0x4ac784 a1201fd600 mov    eax,ds:0xd61f20
0x4ac789 33c5 xor    eax,ebp
0x4ac78b 50 push   eax
0x4ac78c 8d45f4 lea    eax,[ebp-0xc]
0x4ac78f 64a300000000 mov    fs:0x0,eax
0x4ac795 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4ac798 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4ac79b 33c0 xor    eax,eax
0x4ac79d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac7a0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac7a3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac7a6 8b0d6418fe00 mov    ecx,DWORD PTR ds:0xfe1864
0x4ac7ac 51 push   ecx
0x4ac7ad 8d45e8 lea    eax,[ebp-0x18]
0x4ac7b0 e8bb030000 call   0x4acb70
0x4ac7b5 83c404 add    esp,0x4
0x4ac7b8 b801000000 mov    eax,0x1
0x4ac7bd 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac7c0 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac7c7 59 pop    ecx
0x4ac7c8 8be5 mov    esp,ebp
0x4ac7ca 5d pop    ebp
0x4ac7cb c3 ret

; F_004AC7D0 0x4ac7d0..0x4ac82c
0x4ac7d0 55 push   ebp
0x4ac7d1 8bec mov    ebp,esp
0x4ac7d3 6aff push   0xffffffff
0x4ac7d5 68c8839300 push   0x9383c8
0x4ac7da 64a100000000 mov    eax,fs:0x0
0x4ac7e0 50 push   eax
0x4ac7e1 83ec0c sub    esp,0xc
0x4ac7e4 a1201fd600 mov    eax,ds:0xd61f20
0x4ac7e9 33c5 xor    eax,ebp
0x4ac7eb 50 push   eax
0x4ac7ec 8d45f4 lea    eax,[ebp-0xc]
0x4ac7ef 64a300000000 mov    fs:0x0,eax
0x4ac7f5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4ac7f8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4ac7fb 33c0 xor    eax,eax
0x4ac7fd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac800 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac803 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac806 8b0d6818fe00 mov    ecx,DWORD PTR ds:0xfe1868
0x4ac80c 51 push   ecx
0x4ac80d 8d45e8 lea    eax,[ebp-0x18]
0x4ac810 e85b030000 call   0x4acb70
0x4ac815 83c404 add    esp,0x4
0x4ac818 b801000000 mov    eax,0x1
0x4ac81d 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac820 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac827 59 pop    ecx
0x4ac828 8be5 mov    esp,ebp
0x4ac82a 5d pop    ebp
0x4ac82b c3 ret

; F_004AC830 0x4ac830..0x4ac886
0x4ac830 55 push   ebp
0x4ac831 8bec mov    ebp,esp
0x4ac833 6aff push   0xffffffff
0x4ac835 68c8839300 push   0x9383c8
0x4ac83a 64a100000000 mov    eax,fs:0x0
0x4ac840 50 push   eax
0x4ac841 83ec0c sub    esp,0xc
0x4ac844 a1201fd600 mov    eax,ds:0xd61f20
0x4ac849 33c5 xor    eax,ebp
0x4ac84b 50 push   eax
0x4ac84c 8d45f4 lea    eax,[ebp-0xc]
0x4ac84f 64a300000000 mov    fs:0x0,eax
0x4ac855 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4ac858 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4ac85b 33c0 xor    eax,eax
0x4ac85d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac860 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac863 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac866 8b0d0418fe00 mov    ecx,DWORD PTR ds:0xfe1804
0x4ac86c ff156c18fe00 call   DWORD PTR ds:0xfe186c
0x4ac872 b801000000 mov    eax,0x1
0x4ac877 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac87a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac881 59 pop    ecx
0x4ac882 8be5 mov    esp,ebp
0x4ac884 5d pop    ebp
0x4ac885 c3 ret

; F_004AC890 0x4ac890..0x4ac8fe
0x4ac890 55 push   ebp
0x4ac891 8bec mov    ebp,esp
0x4ac893 6aff push   0xffffffff
0x4ac895 68d8879300 push   0x9387d8
0x4ac89a 64a100000000 mov    eax,fs:0x0
0x4ac8a0 50 push   eax
0x4ac8a1 83ec0c sub    esp,0xc
0x4ac8a4 56 push   esi
0x4ac8a5 a1201fd600 mov    eax,ds:0xd61f20
0x4ac8aa 33c5 xor    eax,ebp
0x4ac8ac 50 push   eax
0x4ac8ad 8d45f4 lea    eax,[ebp-0xc]
0x4ac8b0 64a300000000 mov    fs:0x0,eax
0x4ac8b6 8b7508 mov    esi,DWORD PTR [ebp+0x8]
0x4ac8b9 33c0 xor    eax,eax
0x4ac8bb 8975e8 mov    DWORD PTR [ebp-0x18],esi
0x4ac8be 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac8c1 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac8c4 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac8c7 8b0d0418fe00 mov    ecx,DWORD PTR ds:0xfe1804
0x4ac8cd ff157018fe00 call   DWORD PTR ds:0xfe1870
0x4ac8d3 894508 mov    DWORD PTR [ebp+0x8],eax
0x4ac8d6 8b4608 mov    eax,DWORD PTR [esi+0x8]
0x4ac8d9 db4508 fild   DWORD PTR [ebp+0x8]
0x4ac8dc c7400803000000 mov    DWORD PTR [eax+0x8],0x3
0x4ac8e3 dd18 fstp   QWORD PTR [eax]
0x4ac8e5 83460810 add    DWORD PTR [esi+0x8],0x10
0x4ac8e9 b801000000 mov    eax,0x1
0x4ac8ee 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac8f1 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac8f8 59 pop    ecx
0x4ac8f9 5e pop    esi
0x4ac8fa 8be5 mov    esp,ebp
0x4ac8fc 5d pop    ebp
0x4ac8fd c3 ret

; F_004AC900 0x4ac900..0x4ac96e
0x4ac900 55 push   ebp
0x4ac901 8bec mov    ebp,esp
0x4ac903 6aff push   0xffffffff
0x4ac905 68d8879300 push   0x9387d8
0x4ac90a 64a100000000 mov    eax,fs:0x0
0x4ac910 50 push   eax
0x4ac911 83ec0c sub    esp,0xc
0x4ac914 56 push   esi
0x4ac915 a1201fd600 mov    eax,ds:0xd61f20
0x4ac91a 33c5 xor    eax,ebp
0x4ac91c 50 push   eax
0x4ac91d 8d45f4 lea    eax,[ebp-0xc]
0x4ac920 64a300000000 mov    fs:0x0,eax
0x4ac926 8b7508 mov    esi,DWORD PTR [ebp+0x8]
0x4ac929 33c0 xor    eax,eax
0x4ac92b 8975e8 mov    DWORD PTR [ebp-0x18],esi
0x4ac92e 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac931 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac934 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac937 8b0d0418fe00 mov    ecx,DWORD PTR ds:0xfe1804
0x4ac93d ff157418fe00 call   DWORD PTR ds:0xfe1874
0x4ac943 894508 mov    DWORD PTR [ebp+0x8],eax
0x4ac946 8b4608 mov    eax,DWORD PTR [esi+0x8]
0x4ac949 db4508 fild   DWORD PTR [ebp+0x8]
0x4ac94c c7400803000000 mov    DWORD PTR [eax+0x8],0x3
0x4ac953 dd18 fstp   QWORD PTR [eax]
0x4ac955 83460810 add    DWORD PTR [esi+0x8],0x10
0x4ac959 b801000000 mov    eax,0x1
0x4ac95e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac961 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac968 59 pop    ecx
0x4ac969 5e pop    esi
0x4ac96a 8be5 mov    esp,ebp
0x4ac96c 5d pop    ebp
0x4ac96d c3 ret

; F_004AC970 0x4ac970..0x4ac9de
0x4ac970 55 push   ebp
0x4ac971 8bec mov    ebp,esp
0x4ac973 6aff push   0xffffffff
0x4ac975 68d8879300 push   0x9387d8
0x4ac97a 64a100000000 mov    eax,fs:0x0
0x4ac980 50 push   eax
0x4ac981 83ec0c sub    esp,0xc
0x4ac984 56 push   esi
0x4ac985 a1201fd600 mov    eax,ds:0xd61f20
0x4ac98a 33c5 xor    eax,ebp
0x4ac98c 50 push   eax
0x4ac98d 8d45f4 lea    eax,[ebp-0xc]
0x4ac990 64a300000000 mov    fs:0x0,eax
0x4ac996 8b7508 mov    esi,DWORD PTR [ebp+0x8]
0x4ac999 33c0 xor    eax,eax
0x4ac99b 8975e8 mov    DWORD PTR [ebp-0x18],esi
0x4ac99e 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4ac9a1 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4ac9a4 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4ac9a7 8b0d0418fe00 mov    ecx,DWORD PTR ds:0xfe1804
0x4ac9ad ff157818fe00 call   DWORD PTR ds:0xfe1878
0x4ac9b3 894508 mov    DWORD PTR [ebp+0x8],eax
0x4ac9b6 8b4608 mov    eax,DWORD PTR [esi+0x8]
0x4ac9b9 db4508 fild   DWORD PTR [ebp+0x8]
0x4ac9bc c7400803000000 mov    DWORD PTR [eax+0x8],0x3
0x4ac9c3 dd18 fstp   QWORD PTR [eax]
0x4ac9c5 83460810 add    DWORD PTR [esi+0x8],0x10
0x4ac9c9 b801000000 mov    eax,0x1
0x4ac9ce 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4ac9d1 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4ac9d8 59 pop    ecx
0x4ac9d9 5e pop    esi
0x4ac9da 8be5 mov    esp,ebp
0x4ac9dc 5d pop    ebp
0x4ac9dd c3 ret

; F_004AC9E0 0x4ac9e0..0x4aca3c
0x4ac9e0 55 push   ebp
0x4ac9e1 8bec mov    ebp,esp
0x4ac9e3 6aff push   0xffffffff
0x4ac9e5 68c8839300 push   0x9383c8
0x4ac9ea 64a100000000 mov    eax,fs:0x0
0x4ac9f0 50 push   eax
0x4ac9f1 83ec0c sub    esp,0xc
0x4ac9f4 a1201fd600 mov    eax,ds:0xd61f20
0x4ac9f9 33c5 xor    eax,ebp
0x4ac9fb 50 push   eax
0x4ac9fc 8d45f4 lea    eax,[ebp-0xc]
0x4ac9ff 64a300000000 mov    fs:0x0,eax
0x4aca05 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4aca08 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4aca0b 33c0 xor    eax,eax
0x4aca0d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4aca10 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4aca13 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4aca16 8b0d7c18fe00 mov    ecx,DWORD PTR ds:0xfe187c
0x4aca1c 51 push   ecx
0x4aca1d 8d45e8 lea    eax,[ebp-0x18]
0x4aca20 e84b010000 call   0x4acb70
0x4aca25 83c404 add    esp,0x4
0x4aca28 b801000000 mov    eax,0x1
0x4aca2d 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4aca30 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4aca37 59 pop    ecx
0x4aca38 8be5 mov    esp,ebp
0x4aca3a 5d pop    ebp
0x4aca3b c3 ret

; F_004ACA40 0x4aca40..0x4aca9d
0x4aca40 55 push   ebp
0x4aca41 8bec mov    ebp,esp
0x4aca43 6aff push   0xffffffff
0x4aca45 68c8839300 push   0x9383c8
0x4aca4a 64a100000000 mov    eax,fs:0x0
0x4aca50 50 push   eax
0x4aca51 83ec0c sub    esp,0xc
0x4aca54 a1201fd600 mov    eax,ds:0xd61f20
0x4aca59 33c5 xor    eax,ebp
0x4aca5b 50 push   eax
0x4aca5c 8d45f4 lea    eax,[ebp-0xc]
0x4aca5f 64a300000000 mov    fs:0x0,eax
0x4aca65 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4aca68 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x4aca6b 33c0 xor    eax,eax
0x4aca6d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x4aca70 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x4aca73 8945fc mov    DWORD PTR [ebp-0x4],eax
0x4aca76 8b0d8018fe00 mov    ecx,DWORD PTR ds:0xfe1880
0x4aca7c 51 push   ecx
0x4aca7d 8d55e8 lea    edx,[ebp-0x18]
0x4aca80 52 push   edx
0x4aca81 e80a050000 call   0x4acf90
0x4aca86 83c408 add    esp,0x8
0x4aca89 b801000000 mov    eax,0x1
0x4aca8e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4aca91 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4aca98 59 pop    ecx
0x4aca99 8be5 mov    esp,ebp
0x4aca9b 5d pop    ebp
0x4aca9c c3 ret

; F_0054EE40 0x54ee40..0x54ee92
0x54ee40 55 push   ebp
0x54ee41 8bec mov    ebp,esp
0x54ee43 6aff push   0xffffffff
0x54ee45 68c8839300 push   0x9383c8
0x54ee4a 64a100000000 mov    eax,fs:0x0
0x54ee50 50 push   eax
0x54ee51 83ec0c sub    esp,0xc
0x54ee54 a1201fd600 mov    eax,ds:0xd61f20
0x54ee59 33c5 xor    eax,ebp
0x54ee5b 50 push   eax
0x54ee5c 8d45f4 lea    eax,[ebp-0xc]
0x54ee5f 64a300000000 mov    fs:0x0,eax
0x54ee65 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x54ee68 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x54ee6b 33c0 xor    eax,eax
0x54ee6d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x54ee70 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x54ee73 8d4de8 lea    ecx,[ebp-0x18]
0x54ee76 8945fc mov    DWORD PTR [ebp-0x4],eax
0x54ee79 e8b2010000 call   0x54f030
0x54ee7e b801000000 mov    eax,0x1
0x54ee83 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x54ee86 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x54ee8d 59 pop    ecx
0x54ee8e 8be5 mov    esp,ebp
0x54ee90 5d pop    ebp
0x54ee91 c3 ret

; F_0054F030 0x54f030..0x54f099
0x54f030 55 push   ebp
0x54f031 8bec mov    ebp,esp
0x54f033 51 push   ecx
0x54f034 a1281efe00 mov    eax,ds:0xfe1e28
0x54f039 53 push   ebx
0x54f03a 8b1d2c1efe00 mov    ebx,DWORD PTR ds:0xfe1e2c
0x54f040 56 push   esi
0x54f041 57 push   edi
0x54f042 8b39 mov    edi,DWORD PTR [ecx]
0x54f044 8b7708 mov    esi,DWORD PTR [edi+0x8]
0x54f047 83ee10 sub    esi,0x10
0x54f04a 837e0804 cmp    DWORD PTR [esi+0x8],0x4
0x54f04e 8945fc mov    DWORD PTR [ebp-0x4],eax
0x54f051 7432 je     0x54f085
0x54f053 e878c51a00 call   0x6fb5d0
0x54f058 85c0 test   eax,eax
0x54f05a 7511 jne    0x54f06d
0x54f05c 8b4dfc mov    ecx,DWORD PTR [ebp-0x4]
0x54f05f 33f6 xor    esi,esi
0x54f061 56 push   esi
0x54f062 ffd3 call   ebx
0x54f064 5f pop    edi
0x54f065 5e pop    esi
0x54f066 33c0 xor    eax,eax
0x54f068 5b pop    ebx
0x54f069 8be5 mov    esp,ebp
0x54f06b 5d pop    ebp
0x54f06c c3 ret
0x54f06d 8b4710 mov    eax,DWORD PTR [edi+0x10]
0x54f070 8b5044 mov    edx,DWORD PTR [eax+0x44]
0x54f073 3b5040 cmp    edx,DWORD PTR [eax+0x40]
0x54f076 7207 jb     0x54f07f
0x54f078 8bc7 mov    eax,edi
0x54f07a e821c31a00 call   0x6fb3a0
0x54f07f 8b7708 mov    esi,DWORD PTR [edi+0x8]
0x54f082 83ee10 sub    esi,0x10
0x54f085 8b36 mov    esi,DWORD PTR [esi]
0x54f087 8b4dfc mov    ecx,DWORD PTR [ebp-0x4]
0x54f08a 83c610 add    esi,0x10
0x54f08d 56 push   esi
0x54f08e ffd3 call   ebx
0x54f090 5f pop    edi
0x54f091 5e pop    esi
0x54f092 33c0 xor    eax,eax
0x54f094 5b pop    ebx
0x54f095 8be5 mov    esp,ebp
0x54f097 5d pop    ebp
0x54f098 c3 ret

; F_0054EEA0 0x54eea0..0x54eef6
0x54eea0 55 push   ebp
0x54eea1 8bec mov    ebp,esp
0x54eea3 6aff push   0xffffffff
0x54eea5 68c8839300 push   0x9383c8
0x54eeaa 64a100000000 mov    eax,fs:0x0
0x54eeb0 50 push   eax
0x54eeb1 83ec0c sub    esp,0xc
0x54eeb4 a1201fd600 mov    eax,ds:0xd61f20
0x54eeb9 33c5 xor    eax,ebp
0x54eebb 50 push   eax
0x54eebc 8d45f4 lea    eax,[ebp-0xc]
0x54eebf 64a300000000 mov    fs:0x0,eax
0x54eec5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x54eec8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x54eecb 33c0 xor    eax,eax
0x54eecd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x54eed0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x54eed3 8d4de8 lea    ecx,[ebp-0x18]
0x54eed6 51 push   ecx
0x54eed7 8945fc mov    DWORD PTR [ebp-0x4],eax
0x54eeda e8c1010000 call   0x54f0a0
0x54eedf 83c404 add    esp,0x4
0x54eee2 b801000000 mov    eax,0x1
0x54eee7 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x54eeea 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x54eef1 59 pop    ecx
0x54eef2 8be5 mov    esp,ebp
0x54eef4 5d pop    ebp
0x54eef5 c3 ret

; F_0054F0A0 0x54f0a0..0x54f1fa
0x54f0a0 55 push   ebp
0x54f0a1 8bec mov    ebp,esp
0x54f0a3 83ec28 sub    esp,0x28
0x54f0a6 a1301efe00 mov    eax,ds:0xfe1e30
0x54f0ab 8b0d281efe00 mov    ecx,DWORD PTR ds:0xfe1e28
0x54f0b1 53 push   ebx
0x54f0b2 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x54f0b5 8945f8 mov    DWORD PTR [ebp-0x8],eax
0x54f0b8 8b03 mov    eax,DWORD PTR [ebx]
0x54f0ba 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x54f0bd 83e810 sub    eax,0x10
0x54f0c0 894dfc mov    DWORD PTR [ebp-0x4],ecx
0x54f0c3 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x54f0c6 56 push   esi
0x54f0c7 57 push   edi
0x54f0c8 83f903 cmp    ecx,0x3
0x54f0cb 742e je     0x54f0fb
0x54f0cd 83f904 cmp    ecx,0x4
0x54f0d0 0f85bf000000 jne    0x54f195
0x54f0d6 8b30 mov    esi,DWORD PTR [eax]
0x54f0d8 83c610 add    esi,0x10
0x54f0db 8d7de0 lea    edi,[ebp-0x20]
0x54f0de e87d861a00 call   0x6f7760
0x54f0e3 85c0 test   eax,eax
0x54f0e5 0f84aa000000 je     0x54f195
0x54f0eb dd45e0 fld    QWORD PTR [ebp-0x20]
0x54f0ee c745e003000000 mov    DWORD PTR [ebp-0x20],0x3
0x54f0f5 dd5dd8 fstp   QWORD PTR [ebp-0x28]
0x54f0f8 8d45d8 lea    eax,[ebp-0x28]
0x54f0fb dd00 fld    QWORD PTR [eax]
0x54f0fd 8b03 mov    eax,DWORD PTR [ebx]
0x54f0ff dd5df0 fstp   QWORD PTR [ebp-0x10]
0x54f102 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x54f105 8b48e8 mov    ecx,DWORD PTR [eax-0x18]
0x54f108 83e820 sub    eax,0x20
0x54f10b 83f903 cmp    ecx,0x3
0x54f10e 742a je     0x54f13a
0x54f110 83f904 cmp    ecx,0x4
0x54f113 0f8583000000 jne    0x54f19c
0x54f119 8b30 mov    esi,DWORD PTR [eax]
0x54f11b 83c610 add    esi,0x10
0x54f11e 8d7de0 lea    edi,[ebp-0x20]
0x54f121 e83a861a00 call   0x6f7760
0x54f126 85c0 test   eax,eax
0x54f128 7472 je     0x54f19c
0x54f12a dd45e0 fld    QWORD PTR [ebp-0x20]
0x54f12d c745e003000000 mov    DWORD PTR [ebp-0x20],0x3
0x54f134 dd5dd8 fstp   QWORD PTR [ebp-0x28]
0x54f137 8d45d8 lea    eax,[ebp-0x28]
0x54f13a dd00 fld    QWORD PTR [eax]
0x54f13c 8b03 mov    eax,DWORD PTR [ebx]
0x54f13e dd5de8 fstp   QWORD PTR [ebp-0x18]
0x54f141 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x54f144 8b48d8 mov    ecx,DWORD PTR [eax-0x28]
0x54f147 83e830 sub    eax,0x30
0x54f14a 83f903 cmp    ecx,0x3
0x54f14d 7426 je     0x54f175
0x54f14f 83f904 cmp    ecx,0x4
0x54f152 754c jne    0x54f1a0
0x54f154 8b30 mov    esi,DWORD PTR [eax]
0x54f156 83c610 add    esi,0x10
0x54f159 8d7de0 lea    edi,[ebp-0x20]
0x54f15c e8ff851a00 call   0x6f7760
0x54f161 85c0 test   eax,eax
0x54f163 743b je     0x54f1a0
0x54f165 dd45e0 fld    QWORD PTR [ebp-0x20]
0x54f168 c745e003000000 mov    DWORD PTR [ebp-0x20],0x3
0x54f16f dd5dd8 fstp   QWORD PTR [ebp-0x28]
0x54f172 8d45d8 lea    eax,[ebp-0x28]
0x54f175 dd00 fld    QWORD PTR [eax]
0x54f177 8b3b mov    edi,DWORD PTR [ebx]
0x54f179 dd5de0 fstp   QWORD PTR [ebp-0x20]
0x54f17c 8b7708 mov    esi,DWORD PTR [edi+0x8]
0x54f17f 83ee40 sub    esi,0x40
0x54f182 837e0804 cmp    DWORD PTR [esi+0x8],0x4
0x54f186 7434 je     0x54f1bc
0x54f188 e843c41a00 call   0x6fb5d0
0x54f18d 85c0 test   eax,eax
0x54f18f 7513 jne    0x54f1a4
0x54f191 33f6 xor    esi,esi
0x54f193 eb2c jmp    0x54f1c1
0x54f195 d9ee fldz
0x54f197 e961ffffff jmp    0x54f0fd
0x54f19c d9ee fldz
0x54f19e eb9c jmp    0x54f13c
0x54f1a0 d9ee fldz
0x54f1a2 ebd3 jmp    0x54f177
0x54f1a4 8b4710 mov    eax,DWORD PTR [edi+0x10]
0x54f1a7 8b5044 mov    edx,DWORD PTR [eax+0x44]
0x54f1aa 3b5040 cmp    edx,DWORD PTR [eax+0x40]
0x54f1ad 7207 jb     0x54f1b6
0x54f1af 8bc7 mov    eax,edi
0x54f1b1 e8eac11a00 call   0x6fb3a0
0x54f1b6 8b7708 mov    esi,DWORD PTR [edi+0x8]
0x54f1b9 83ee40 sub    esi,0x40
0x54f1bc 8b36 mov    esi,DWORD PTR [esi]
0x54f1be 83c610 add    esi,0x10
0x54f1c1 dd45f0 fld    QWORD PTR [ebp-0x10]
0x54f1c4 8b4dfc mov    ecx,DWORD PTR [ebp-0x4]
0x54f1c7 d95d08 fstp   DWORD PTR [ebp+0x8]
0x54f1ca 83ec0c sub    esp,0xc
0x54f1cd d94508 fld    DWORD PTR [ebp+0x8]
0x54f1d0 d95c2408 fstp   DWORD PTR [esp+0x8]
0x54f1d4 dd45e8 fld    QWORD PTR [ebp-0x18]
0x54f1d7 d95d08 fstp   DWORD PTR [ebp+0x8]
0x54f1da d94508 fld    DWORD PTR [ebp+0x8]
0x54f1dd d95c2404 fstp   DWORD PTR [esp+0x4]
0x54f1e1 dd45e0 fld    QWORD PTR [ebp-0x20]
0x54f1e4 d95d08 fstp   DWORD PTR [ebp+0x8]
0x54f1e7 d94508 fld    DWORD PTR [ebp+0x8]
0x54f1ea d91c24 fstp   DWORD PTR [esp]
0x54f1ed 56 push   esi
0x54f1ee ff55f8 call   DWORD PTR [ebp-0x8]
0x54f1f1 5f pop    edi
0x54f1f2 5e pop    esi
0x54f1f3 33c0 xor    eax,eax
0x54f1f5 5b pop    ebx
0x54f1f6 8be5 mov    esp,ebp
0x54f1f8 5d pop    ebp
0x54f1f9 c3 ret

; F_0054EF00 0x54ef00..0x54ef56
0x54ef00 55 push   ebp
0x54ef01 8bec mov    ebp,esp
0x54ef03 6aff push   0xffffffff
0x54ef05 68c8839300 push   0x9383c8
0x54ef0a 64a100000000 mov    eax,fs:0x0
0x54ef10 50 push   eax
0x54ef11 83ec0c sub    esp,0xc
0x54ef14 a1201fd600 mov    eax,ds:0xd61f20
0x54ef19 33c5 xor    eax,ebp
0x54ef1b 50 push   eax
0x54ef1c 8d45f4 lea    eax,[ebp-0xc]
0x54ef1f 64a300000000 mov    fs:0x0,eax
0x54ef25 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x54ef28 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x54ef2b 33c0 xor    eax,eax
0x54ef2d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x54ef30 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x54ef33 8945fc mov    DWORD PTR [ebp-0x4],eax
0x54ef36 8b0d281efe00 mov    ecx,DWORD PTR ds:0xfe1e28
0x54ef3c ff15341efe00 call   DWORD PTR ds:0xfe1e34
0x54ef42 b801000000 mov    eax,0x1
0x54ef47 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x54ef4a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x54ef51 59 pop    ecx
0x54ef52 8be5 mov    esp,ebp
0x54ef54 5d pop    ebp
0x54ef55 c3 ret

; F_0054EF60 0x54ef60..0x54efb6
0x54ef60 55 push   ebp
0x54ef61 8bec mov    ebp,esp
0x54ef63 6aff push   0xffffffff
0x54ef65 68c8839300 push   0x9383c8
0x54ef6a 64a100000000 mov    eax,fs:0x0
0x54ef70 50 push   eax
0x54ef71 83ec0c sub    esp,0xc
0x54ef74 a1201fd600 mov    eax,ds:0xd61f20
0x54ef79 33c5 xor    eax,ebp
0x54ef7b 50 push   eax
0x54ef7c 8d45f4 lea    eax,[ebp-0xc]
0x54ef7f 64a300000000 mov    fs:0x0,eax
0x54ef85 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x54ef88 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x54ef8b 33c0 xor    eax,eax
0x54ef8d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x54ef90 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x54ef93 8945fc mov    DWORD PTR [ebp-0x4],eax
0x54ef96 8b0d281efe00 mov    ecx,DWORD PTR ds:0xfe1e28
0x54ef9c ff15381efe00 call   DWORD PTR ds:0xfe1e38
0x54efa2 b801000000 mov    eax,0x1
0x54efa7 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x54efaa 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x54efb1 59 pop    ecx
0x54efb2 8be5 mov    esp,ebp
0x54efb4 5d pop    ebp
0x54efb5 c3 ret

; F_0054EFC0 0x54efc0..0x54f02e
0x54efc0 55 push   ebp
0x54efc1 8bec mov    ebp,esp
0x54efc3 6aff push   0xffffffff
0x54efc5 68d8879300 push   0x9387d8
0x54efca 64a100000000 mov    eax,fs:0x0
0x54efd0 50 push   eax
0x54efd1 83ec0c sub    esp,0xc
0x54efd4 56 push   esi
0x54efd5 a1201fd600 mov    eax,ds:0xd61f20
0x54efda 33c5 xor    eax,ebp
0x54efdc 50 push   eax
0x54efdd 8d45f4 lea    eax,[ebp-0xc]
0x54efe0 64a300000000 mov    fs:0x0,eax
0x54efe6 8b7508 mov    esi,DWORD PTR [ebp+0x8]
0x54efe9 33c0 xor    eax,eax
0x54efeb 8975e8 mov    DWORD PTR [ebp-0x18],esi
0x54efee 8945ec mov    DWORD PTR [ebp-0x14],eax
0x54eff1 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x54eff4 8945fc mov    DWORD PTR [ebp-0x4],eax
0x54eff7 8b0d281efe00 mov    ecx,DWORD PTR ds:0xfe1e28
0x54effd ff153c1efe00 call   DWORD PTR ds:0xfe1e3c
0x54f003 894508 mov    DWORD PTR [ebp+0x8],eax
0x54f006 8b4608 mov    eax,DWORD PTR [esi+0x8]
0x54f009 db4508 fild   DWORD PTR [ebp+0x8]
0x54f00c c7400803000000 mov    DWORD PTR [eax+0x8],0x3
0x54f013 dd18 fstp   QWORD PTR [eax]
0x54f015 83460810 add    DWORD PTR [esi+0x8],0x10
0x54f019 b801000000 mov    eax,0x1
0x54f01e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x54f021 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x54f028 59 pop    ecx
0x54f029 5e pop    esi
0x54f02a 8be5 mov    esp,ebp
0x54f02c 5d pop    ebp
0x54f02d c3 ret

; F_0055EA90 0x55ea90..0x55eae6
0x55ea90 55 push   ebp
0x55ea91 8bec mov    ebp,esp
0x55ea93 6aff push   0xffffffff
0x55ea95 68c8839300 push   0x9383c8
0x55ea9a 64a100000000 mov    eax,fs:0x0
0x55eaa0 50 push   eax
0x55eaa1 83ec0c sub    esp,0xc
0x55eaa4 a1201fd600 mov    eax,ds:0xd61f20
0x55eaa9 33c5 xor    eax,ebp
0x55eaab 50 push   eax
0x55eaac 8d45f4 lea    eax,[ebp-0xc]
0x55eaaf 64a300000000 mov    fs:0x0,eax
0x55eab5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x55eab8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x55eabb 33c0 xor    eax,eax
0x55eabd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x55eac0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x55eac3 8d4de8 lea    ecx,[ebp-0x18]
0x55eac6 51 push   ecx
0x55eac7 8945fc mov    DWORD PTR [ebp-0x4],eax
0x55eaca e881000000 call   0x55eb50
0x55eacf 83c404 add    esp,0x4
0x55ead2 b801000000 mov    eax,0x1
0x55ead7 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x55eada 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x55eae1 59 pop    ecx
0x55eae2 8be5 mov    esp,ebp
0x55eae4 5d pop    ebp
0x55eae5 c3 ret

; F_0055EB50 0x55eb50..0x55ec35
0x55eb50 55 push   ebp
0x55eb51 8bec mov    ebp,esp
0x55eb53 83ec28 sub    esp,0x28
0x55eb56 a1341ffe00 mov    eax,ds:0xfe1f34
0x55eb5b 8b0d301ffe00 mov    ecx,DWORD PTR ds:0xfe1f30
0x55eb61 53 push   ebx
0x55eb62 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x55eb65 56 push   esi
0x55eb66 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x55eb69 894dec mov    DWORD PTR [ebp-0x14],ecx
0x55eb6c 8b0b mov    ecx,DWORD PTR [ebx]
0x55eb6e 57 push   edi
0x55eb6f 83c8ff or     eax,0xffffffff
0x55eb72 e879651900 call   0x6f50f0
0x55eb77 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x55eb7a 83f903 cmp    ecx,0x3
0x55eb7d 742a je     0x55eba9
0x55eb7f 83f904 cmp    ecx,0x4
0x55eb82 0f858e000000 jne    0x55ec16
0x55eb88 8b30 mov    esi,DWORD PTR [eax]
0x55eb8a 83c610 add    esi,0x10
0x55eb8d 8d7df0 lea    edi,[ebp-0x10]
0x55eb90 e8cb8b1900 call   0x6f7760
0x55eb95 85c0 test   eax,eax
0x55eb97 747d je     0x55ec16
0x55eb99 dd45f0 fld    QWORD PTR [ebp-0x10]
0x55eb9c c745e003000000 mov    DWORD PTR [ebp-0x20],0x3
0x55eba3 dd5dd8 fstp   QWORD PTR [ebp-0x28]
0x55eba6 8d45d8 lea    eax,[ebp-0x28]
0x55eba9 dd00 fld    QWORD PTR [eax]
0x55ebab dd5df0 fstp   QWORD PTR [ebp-0x10]
0x55ebae dd45f0 fld    QWORD PTR [ebp-0x10]
0x55ebb1 db5d08 fistp  DWORD PTR [ebp+0x8]
0x55ebb4 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x55ebb7 8955f4 mov    DWORD PTR [ebp-0xc],edx
0x55ebba 8b0b mov    ecx,DWORD PTR [ebx]
0x55ebbc b8feffffff mov    eax,0xfffffffe
0x55ebc1 e82a651900 call   0x6f50f0
0x55ebc6 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x55ebc9 83f903 cmp    ecx,0x3
0x55ebcc 7426 je     0x55ebf4
0x55ebce 83f904 cmp    ecx,0x4
0x55ebd1 754c jne    0x55ec1f
0x55ebd3 8b30 mov    esi,DWORD PTR [eax]
0x55ebd5 83c610 add    esi,0x10
0x55ebd8 8d7df8 lea    edi,[ebp-0x8]
0x55ebdb e8808b1900 call   0x6f7760
0x55ebe0 85c0 test   eax,eax
0x55ebe2 743b je     0x55ec1f
0x55ebe4 dd45f8 fld    QWORD PTR [ebp-0x8]
0x55ebe7 c745e003000000 mov    DWORD PTR [ebp-0x20],0x3
0x55ebee dd5dd8 fstp   QWORD PTR [ebp-0x28]
0x55ebf1 8d45d8 lea    eax,[ebp-0x28]
0x55ebf4 dd00 fld    QWORD PTR [eax]
0x55ebf6 dd5de0 fstp   QWORD PTR [ebp-0x20]
0x55ebf9 dd45e0 fld    QWORD PTR [ebp-0x20]
0x55ebfc db5dfc fistp  DWORD PTR [ebp-0x4]
0x55ebff 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x55ec02 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x55ec05 51 push   ecx
0x55ec06 8b4dec mov    ecx,DWORD PTR [ebp-0x14]
0x55ec09 50 push   eax
0x55ec0a ff55e8 call   DWORD PTR [ebp-0x18]
0x55ec0d 5f pop    edi
0x55ec0e 5e pop    esi
0x55ec0f 33c0 xor    eax,eax
0x55ec11 5b pop    ebx
0x55ec12 8be5 mov    esp,ebp
0x55ec14 5d pop    ebp
0x55ec15 c3 ret
0x55ec16 c745f400000000 mov    DWORD PTR [ebp-0xc],0x0
0x55ec1d eb9b jmp    0x55ebba
0x55ec1f 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x55ec22 51 push   ecx
0x55ec23 8b4dec mov    ecx,DWORD PTR [ebp-0x14]
0x55ec26 33c0 xor    eax,eax
0x55ec28 50 push   eax
0x55ec29 ff55e8 call   DWORD PTR [ebp-0x18]
0x55ec2c 5f pop    edi
0x55ec2d 5e pop    esi
0x55ec2e 33c0 xor    eax,eax
0x55ec30 5b pop    ebx
0x55ec31 8be5 mov    esp,ebp
0x55ec33 5d pop    ebp
0x55ec34 c3 ret

; F_0055EAF0 0x55eaf0..0x55eb42
0x55eaf0 55 push   ebp
0x55eaf1 8bec mov    ebp,esp
0x55eaf3 6aff push   0xffffffff
0x55eaf5 68c8839300 push   0x9383c8
0x55eafa 64a100000000 mov    eax,fs:0x0
0x55eb00 50 push   eax
0x55eb01 83ec0c sub    esp,0xc
0x55eb04 a1201fd600 mov    eax,ds:0xd61f20
0x55eb09 33c5 xor    eax,ebp
0x55eb0b 50 push   eax
0x55eb0c 8d45f4 lea    eax,[ebp-0xc]
0x55eb0f 64a300000000 mov    fs:0x0,eax
0x55eb15 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x55eb18 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x55eb1b 33c0 xor    eax,eax
0x55eb1d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x55eb20 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x55eb23 8d4de8 lea    ecx,[ebp-0x18]
0x55eb26 8945fc mov    DWORD PTR [ebp-0x4],eax
0x55eb29 e812010000 call   0x55ec40
0x55eb2e b801000000 mov    eax,0x1
0x55eb33 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x55eb36 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x55eb3d 59 pop    ecx
0x55eb3e 8be5 mov    esp,ebp
0x55eb40 5d pop    ebp
0x55eb41 c3 ret

; F_0055EC40 0x55ec40..0x55ecbb
0x55ec40 55 push   ebp
0x55ec41 8bec mov    ebp,esp
0x55ec43 83ec1c sub    esp,0x1c
0x55ec46 a1301ffe00 mov    eax,ds:0xfe1f30
0x55ec4b 8b09 mov    ecx,DWORD PTR [ecx]
0x55ec4d 8945f4 mov    DWORD PTR [ebp-0xc],eax
0x55ec50 53 push   ebx
0x55ec51 8b1d381ffe00 mov    ebx,DWORD PTR ds:0xfe1f38
0x55ec57 83c8ff or     eax,0xffffffff
0x55ec5a e891641900 call   0x6f50f0
0x55ec5f 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x55ec62 83f903 cmp    ecx,0x3
0x55ec65 742a je     0x55ec91
0x55ec67 83f904 cmp    ecx,0x4
0x55ec6a 7540 jne    0x55ecac
0x55ec6c 56 push   esi
0x55ec6d 8b30 mov    esi,DWORD PTR [eax]
0x55ec6f 57 push   edi
0x55ec70 83c610 add    esi,0x10
0x55ec73 8d7df8 lea    edi,[ebp-0x8]
0x55ec76 e8e58a1900 call   0x6f7760
0x55ec7b 5f pop    edi
0x55ec7c 5e pop    esi
0x55ec7d 85c0 test   eax,eax
0x55ec7f 742b je     0x55ecac
0x55ec81 dd45f8 fld    QWORD PTR [ebp-0x8]
0x55ec84 c745ec03000000 mov    DWORD PTR [ebp-0x14],0x3
0x55ec8b dd5de4 fstp   QWORD PTR [ebp-0x1c]
0x55ec8e 8d45e4 lea    eax,[ebp-0x1c]
0x55ec91 dd00 fld    QWORD PTR [eax]
0x55ec93 dd5dec fstp   QWORD PTR [ebp-0x14]
0x55ec96 dd45ec fld    QWORD PTR [ebp-0x14]
0x55ec99 db5dfc fistp  DWORD PTR [ebp-0x4]
0x55ec9c 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x55ec9f 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x55eca2 50 push   eax
0x55eca3 ffd3 call   ebx
0x55eca5 33c0 xor    eax,eax
0x55eca7 5b pop    ebx
0x55eca8 8be5 mov    esp,ebp
0x55ecaa 5d pop    ebp
0x55ecab c3 ret
0x55ecac 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x55ecaf 33c0 xor    eax,eax
0x55ecb1 50 push   eax
0x55ecb2 ffd3 call   ebx
0x55ecb4 33c0 xor    eax,eax
0x55ecb6 5b pop    ebx
0x55ecb7 8be5 mov    esp,ebp
0x55ecb9 5d pop    ebp
0x55ecba c3 ret

; F_0055FF10 0x55ff10..0x55ff66
0x55ff10 55 push   ebp
0x55ff11 8bec mov    ebp,esp
0x55ff13 6aff push   0xffffffff
0x55ff15 68c8839300 push   0x9383c8
0x55ff1a 64a100000000 mov    eax,fs:0x0
0x55ff20 50 push   eax
0x55ff21 83ec0c sub    esp,0xc
0x55ff24 a1201fd600 mov    eax,ds:0xd61f20
0x55ff29 33c5 xor    eax,ebp
0x55ff2b 50 push   eax
0x55ff2c 8d45f4 lea    eax,[ebp-0xc]
0x55ff2f 64a300000000 mov    fs:0x0,eax
0x55ff35 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x55ff38 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x55ff3b 33c0 xor    eax,eax
0x55ff3d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x55ff40 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x55ff43 8945fc mov    DWORD PTR [ebp-0x4],eax
0x55ff46 8b0d6827fe00 mov    ecx,DWORD PTR ds:0xfe2768
0x55ff4c ff156c27fe00 call   DWORD PTR ds:0xfe276c
0x55ff52 b801000000 mov    eax,0x1
0x55ff57 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x55ff5a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x55ff61 59 pop    ecx
0x55ff62 8be5 mov    esp,ebp
0x55ff64 5d pop    ebp
0x55ff65 c3 ret

; F_00568A30 0x568a30..0x568a8d
0x568a30 55 push   ebp
0x568a31 8bec mov    ebp,esp
0x568a33 6aff push   0xffffffff
0x568a35 68c8839300 push   0x9383c8
0x568a3a 64a100000000 mov    eax,fs:0x0
0x568a40 50 push   eax
0x568a41 83ec0c sub    esp,0xc
0x568a44 a1201fd600 mov    eax,ds:0xd61f20
0x568a49 33c5 xor    eax,ebp
0x568a4b 50 push   eax
0x568a4c 8d45f4 lea    eax,[ebp-0xc]
0x568a4f 64a300000000 mov    fs:0x0,eax
0x568a55 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x568a58 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x568a5b 33c0 xor    eax,eax
0x568a5d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x568a60 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x568a63 8945fc mov    DWORD PTR [ebp-0x4],eax
0x568a66 8b0d7c27fe00 mov    ecx,DWORD PTR ds:0xfe277c
0x568a6c 51 push   ecx
0x568a6d 8d55e8 lea    edx,[ebp-0x18]
0x568a70 52 push   edx
0x568a71 e8aa170000 call   0x56a220
0x568a76 83c408 add    esp,0x8
0x568a79 b801000000 mov    eax,0x1
0x568a7e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x568a81 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x568a88 59 pop    ecx
0x568a89 8be5 mov    esp,ebp
0x568a8b 5d pop    ebp
0x568a8c c3 ret

; F_0056A220 0x56a220..0x56a2fc
0x56a220 55 push   ebp
0x56a221 8bec mov    ebp,esp
0x56a223 83ec24 sub    esp,0x24
0x56a226 a17827fe00 mov    eax,ds:0xfe2778
0x56a22b 53 push   ebx
0x56a22c 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x56a22f 8b0b mov    ecx,DWORD PTR [ebx]
0x56a231 56 push   esi
0x56a232 8945ec mov    DWORD PTR [ebp-0x14],eax
0x56a235 57 push   edi
0x56a236 83c8ff or     eax,0xffffffff
0x56a239 e8b2ae1800 call   0x6f50f0
0x56a23e 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56a241 83f903 cmp    ecx,0x3
0x56a244 742a je     0x56a270
0x56a246 83f904 cmp    ecx,0x4
0x56a249 0f858e000000 jne    0x56a2dd
0x56a24f 8b30 mov    esi,DWORD PTR [eax]
0x56a251 83c610 add    esi,0x10
0x56a254 8d7df0 lea    edi,[ebp-0x10]
0x56a257 e804d51800 call   0x6f7760
0x56a25c 85c0 test   eax,eax
0x56a25e 747d je     0x56a2dd
0x56a260 dd45f0 fld    QWORD PTR [ebp-0x10]
0x56a263 c745e403000000 mov    DWORD PTR [ebp-0x1c],0x3
0x56a26a dd5ddc fstp   QWORD PTR [ebp-0x24]
0x56a26d 8d45dc lea    eax,[ebp-0x24]
0x56a270 dd00 fld    QWORD PTR [eax]
0x56a272 dd5df0 fstp   QWORD PTR [ebp-0x10]
0x56a275 dd45f0 fld    QWORD PTR [ebp-0x10]
0x56a278 db5d08 fistp  DWORD PTR [ebp+0x8]
0x56a27b 8b4d08 mov    ecx,DWORD PTR [ebp+0x8]
0x56a27e 894df4 mov    DWORD PTR [ebp-0xc],ecx
0x56a281 8b0b mov    ecx,DWORD PTR [ebx]
0x56a283 b8feffffff mov    eax,0xfffffffe
0x56a288 e863ae1800 call   0x6f50f0
0x56a28d 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56a290 83f903 cmp    ecx,0x3
0x56a293 7426 je     0x56a2bb
0x56a295 83f904 cmp    ecx,0x4
0x56a298 754c jne    0x56a2e6
0x56a29a 8b30 mov    esi,DWORD PTR [eax]
0x56a29c 83c610 add    esi,0x10
0x56a29f 8d7df8 lea    edi,[ebp-0x8]
0x56a2a2 e8b9d41800 call   0x6f7760
0x56a2a7 85c0 test   eax,eax
0x56a2a9 743b je     0x56a2e6
0x56a2ab dd45f8 fld    QWORD PTR [ebp-0x8]
0x56a2ae c745e403000000 mov    DWORD PTR [ebp-0x1c],0x3
0x56a2b5 dd5ddc fstp   QWORD PTR [ebp-0x24]
0x56a2b8 8d45dc lea    eax,[ebp-0x24]
0x56a2bb dd00 fld    QWORD PTR [eax]
0x56a2bd dd5de4 fstp   QWORD PTR [ebp-0x1c]
0x56a2c0 dd45e4 fld    QWORD PTR [ebp-0x1c]
0x56a2c3 db5dfc fistp  DWORD PTR [ebp-0x4]
0x56a2c6 8b55f4 mov    edx,DWORD PTR [ebp-0xc]
0x56a2c9 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x56a2cc 8b4dec mov    ecx,DWORD PTR [ebp-0x14]
0x56a2cf 52 push   edx
0x56a2d0 50 push   eax
0x56a2d1 ff550c call   DWORD PTR [ebp+0xc]
0x56a2d4 5f pop    edi
0x56a2d5 5e pop    esi
0x56a2d6 33c0 xor    eax,eax
0x56a2d8 5b pop    ebx
0x56a2d9 8be5 mov    esp,ebp
0x56a2db 5d pop    ebp
0x56a2dc c3 ret
0x56a2dd c745f400000000 mov    DWORD PTR [ebp-0xc],0x0
0x56a2e4 eb9b jmp    0x56a281
0x56a2e6 8b55f4 mov    edx,DWORD PTR [ebp-0xc]
0x56a2e9 8b4dec mov    ecx,DWORD PTR [ebp-0x14]
0x56a2ec 33c0 xor    eax,eax
0x56a2ee 52 push   edx
0x56a2ef 50 push   eax
0x56a2f0 ff550c call   DWORD PTR [ebp+0xc]
0x56a2f3 5f pop    edi
0x56a2f4 5e pop    esi
0x56a2f5 33c0 xor    eax,eax
0x56a2f7 5b pop    ebx
0x56a2f8 8be5 mov    esp,ebp
0x56a2fa 5d pop    ebp
0x56a2fb c3 ret

; F_00568A90 0x568a90..0x568ae6
0x568a90 55 push   ebp
0x568a91 8bec mov    ebp,esp
0x568a93 6aff push   0xffffffff
0x568a95 68c8839300 push   0x9383c8
0x568a9a 64a100000000 mov    eax,fs:0x0
0x568aa0 50 push   eax
0x568aa1 83ec0c sub    esp,0xc
0x568aa4 a1201fd600 mov    eax,ds:0xd61f20
0x568aa9 33c5 xor    eax,ebp
0x568aab 50 push   eax
0x568aac 8d45f4 lea    eax,[ebp-0xc]
0x568aaf 64a300000000 mov    fs:0x0,eax
0x568ab5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x568ab8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x568abb 33c0 xor    eax,eax
0x568abd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x568ac0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x568ac3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x568ac6 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x568acc ff158027fe00 call   DWORD PTR ds:0xfe2780
0x568ad2 b801000000 mov    eax,0x1
0x568ad7 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x568ada 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x568ae1 59 pop    ecx
0x568ae2 8be5 mov    esp,ebp
0x568ae4 5d pop    ebp
0x568ae5 c3 ret

; F_00568AF0 0x568af0..0x568b5e
0x568af0 55 push   ebp
0x568af1 8bec mov    ebp,esp
0x568af3 6aff push   0xffffffff
0x568af5 68d8879300 push   0x9387d8
0x568afa 64a100000000 mov    eax,fs:0x0
0x568b00 50 push   eax
0x568b01 83ec0c sub    esp,0xc
0x568b04 56 push   esi
0x568b05 a1201fd600 mov    eax,ds:0xd61f20
0x568b0a 33c5 xor    eax,ebp
0x568b0c 50 push   eax
0x568b0d 8d45f4 lea    eax,[ebp-0xc]
0x568b10 64a300000000 mov    fs:0x0,eax
0x568b16 8b7508 mov    esi,DWORD PTR [ebp+0x8]
0x568b19 33c0 xor    eax,eax
0x568b1b 8975e8 mov    DWORD PTR [ebp-0x18],esi
0x568b1e 8945ec mov    DWORD PTR [ebp-0x14],eax
0x568b21 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x568b24 8945fc mov    DWORD PTR [ebp-0x4],eax
0x568b27 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x568b2d ff158427fe00 call   DWORD PTR ds:0xfe2784
0x568b33 894508 mov    DWORD PTR [ebp+0x8],eax
0x568b36 8b4608 mov    eax,DWORD PTR [esi+0x8]
0x568b39 db4508 fild   DWORD PTR [ebp+0x8]
0x568b3c c7400803000000 mov    DWORD PTR [eax+0x8],0x3
0x568b43 dd18 fstp   QWORD PTR [eax]
0x568b45 83460810 add    DWORD PTR [esi+0x8],0x10
0x568b49 b801000000 mov    eax,0x1
0x568b4e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x568b51 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x568b58 59 pop    ecx
0x568b59 5e pop    esi
0x568b5a 8be5 mov    esp,ebp
0x568b5c 5d pop    ebp
0x568b5d c3 ret

; F_00568B60 0x568b60..0x568bbc
0x568b60 55 push   ebp
0x568b61 8bec mov    ebp,esp
0x568b63 6aff push   0xffffffff
0x568b65 68c8839300 push   0x9383c8
0x568b6a 64a100000000 mov    eax,fs:0x0
0x568b70 50 push   eax
0x568b71 83ec0c sub    esp,0xc
0x568b74 a1201fd600 mov    eax,ds:0xd61f20
0x568b79 33c5 xor    eax,ebp
0x568b7b 50 push   eax
0x568b7c 8d45f4 lea    eax,[ebp-0xc]
0x568b7f 64a300000000 mov    fs:0x0,eax
0x568b85 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x568b88 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x568b8b 33c0 xor    eax,eax
0x568b8d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x568b90 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x568b93 8945fc mov    DWORD PTR [ebp-0x4],eax
0x568b96 8b0d8827fe00 mov    ecx,DWORD PTR ds:0xfe2788
0x568b9c 51 push   ecx
0x568b9d 8d45e8 lea    eax,[ebp-0x18]
0x568ba0 e85b170000 call   0x56a300
0x568ba5 83c404 add    esp,0x4
0x568ba8 b801000000 mov    eax,0x1
0x568bad 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x568bb0 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x568bb7 59 pop    ecx
0x568bb8 8be5 mov    esp,ebp
0x568bba 5d pop    ebp
0x568bbb c3 ret

; F_0056A300 0x56a300..0x56a35c
0x56a300 55 push   ebp
0x56a301 8bec mov    ebp,esp
0x56a303 53 push   ebx
0x56a304 8b1d7827fe00 mov    ebx,DWORD PTR ds:0xfe2778
0x56a30a 56 push   esi
0x56a30b 57 push   edi
0x56a30c 8b38 mov    edi,DWORD PTR [eax]
0x56a30e 8b7708 mov    esi,DWORD PTR [edi+0x8]
0x56a311 83ee10 sub    esi,0x10
0x56a314 837e0804 cmp    DWORD PTR [esi+0x8],0x4
0x56a318 7430 je     0x56a34a
0x56a31a e8b1121900 call   0x6fb5d0
0x56a31f 85c0 test   eax,eax
0x56a321 750f jne    0x56a332
0x56a323 33f6 xor    esi,esi
0x56a325 56 push   esi
0x56a326 8bcb mov    ecx,ebx
0x56a328 ff5508 call   DWORD PTR [ebp+0x8]
0x56a32b 5f pop    edi
0x56a32c 5e pop    esi
0x56a32d 33c0 xor    eax,eax
0x56a32f 5b pop    ebx
0x56a330 5d pop    ebp
0x56a331 c3 ret
0x56a332 8b4710 mov    eax,DWORD PTR [edi+0x10]
0x56a335 8b4844 mov    ecx,DWORD PTR [eax+0x44]
0x56a338 3b4840 cmp    ecx,DWORD PTR [eax+0x40]
0x56a33b 7207 jb     0x56a344
0x56a33d 8bc7 mov    eax,edi
0x56a33f e85c101900 call   0x6fb3a0
0x56a344 8b7708 mov    esi,DWORD PTR [edi+0x8]
0x56a347 83ee10 sub    esi,0x10
0x56a34a 8b36 mov    esi,DWORD PTR [esi]
0x56a34c 83c610 add    esi,0x10
0x56a34f 56 push   esi
0x56a350 8bcb mov    ecx,ebx
0x56a352 ff5508 call   DWORD PTR [ebp+0x8]
0x56a355 5f pop    edi
0x56a356 5e pop    esi
0x56a357 33c0 xor    eax,eax
0x56a359 5b pop    ebx
0x56a35a 5d pop    ebp
0x56a35b c3 ret

; F_00568BC0 0x568bc0..0x568c16
0x568bc0 55 push   ebp
0x568bc1 8bec mov    ebp,esp
0x568bc3 6aff push   0xffffffff
0x568bc5 68c8839300 push   0x9383c8
0x568bca 64a100000000 mov    eax,fs:0x0
0x568bd0 50 push   eax
0x568bd1 83ec0c sub    esp,0xc
0x568bd4 a1201fd600 mov    eax,ds:0xd61f20
0x568bd9 33c5 xor    eax,ebp
0x568bdb 50 push   eax
0x568bdc 8d45f4 lea    eax,[ebp-0xc]
0x568bdf 64a300000000 mov    fs:0x0,eax
0x568be5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x568be8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x568beb 33c0 xor    eax,eax
0x568bed 8945ec mov    DWORD PTR [ebp-0x14],eax
0x568bf0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x568bf3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x568bf6 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x568bfc ff158c27fe00 call   DWORD PTR ds:0xfe278c
0x568c02 b801000000 mov    eax,0x1
0x568c07 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x568c0a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x568c11 59 pop    ecx
0x568c12 8be5 mov    esp,ebp
0x568c14 5d pop    ebp
0x568c15 c3 ret

; F_00568C20 0x568c20..0x568c76
0x568c20 55 push   ebp
0x568c21 8bec mov    ebp,esp
0x568c23 6aff push   0xffffffff
0x568c25 68c8839300 push   0x9383c8
0x568c2a 64a100000000 mov    eax,fs:0x0
0x568c30 50 push   eax
0x568c31 83ec0c sub    esp,0xc
0x568c34 a1201fd600 mov    eax,ds:0xd61f20
0x568c39 33c5 xor    eax,ebp
0x568c3b 50 push   eax
0x568c3c 8d45f4 lea    eax,[ebp-0xc]
0x568c3f 64a300000000 mov    fs:0x0,eax
0x568c45 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x568c48 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x568c4b 33c0 xor    eax,eax
0x568c4d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x568c50 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x568c53 8945fc mov    DWORD PTR [ebp-0x4],eax
0x568c56 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x568c5c ff159027fe00 call   DWORD PTR ds:0xfe2790
0x568c62 b801000000 mov    eax,0x1
0x568c67 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x568c6a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x568c71 59 pop    ecx
0x568c72 8be5 mov    esp,ebp
0x568c74 5d pop    ebp
0x568c75 c3 ret

; F_00568C80 0x568c80..0x568cdd
0x568c80 55 push   ebp
0x568c81 8bec mov    ebp,esp
0x568c83 6aff push   0xffffffff
0x568c85 68c8839300 push   0x9383c8
0x568c8a 64a100000000 mov    eax,fs:0x0
0x568c90 50 push   eax
0x568c91 83ec0c sub    esp,0xc
0x568c94 a1201fd600 mov    eax,ds:0xd61f20
0x568c99 33c5 xor    eax,ebp
0x568c9b 50 push   eax
0x568c9c 8d45f4 lea    eax,[ebp-0xc]
0x568c9f 64a300000000 mov    fs:0x0,eax
0x568ca5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x568ca8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x568cab 33c0 xor    eax,eax
0x568cad 8945ec mov    DWORD PTR [ebp-0x14],eax
0x568cb0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x568cb3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x568cb6 8b0d9427fe00 mov    ecx,DWORD PTR ds:0xfe2794
0x568cbc 51 push   ecx
0x568cbd 8d55e8 lea    edx,[ebp-0x18]
0x568cc0 52 push   edx
0x568cc1 e89a160000 call   0x56a360
0x568cc6 83c408 add    esp,0x8
0x568cc9 b801000000 mov    eax,0x1
0x568cce 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x568cd1 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x568cd8 59 pop    ecx
0x568cd9 8be5 mov    esp,ebp
0x568cdb 5d pop    ebp
0x568cdc c3 ret

; F_0056A360 0x56a360..0x56a424
0x56a360 55 push   ebp
0x56a361 8bec mov    ebp,esp
0x56a363 83ec14 sub    esp,0x14
0x56a366 a17827fe00 mov    eax,ds:0xfe2778
0x56a36b 53 push   ebx
0x56a36c 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x56a36f 8b0b mov    ecx,DWORD PTR [ebx]
0x56a371 56 push   esi
0x56a372 8945ec mov    DWORD PTR [ebp-0x14],eax
0x56a375 57 push   edi
0x56a376 83c8ff or     eax,0xffffffff
0x56a379 e872ad1800 call   0x6f50f0
0x56a37e 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56a381 83f903 cmp    ecx,0x3
0x56a384 7426 je     0x56a3ac
0x56a386 83f904 cmp    ecx,0x4
0x56a389 755f jne    0x56a3ea
0x56a38b 8b30 mov    esi,DWORD PTR [eax]
0x56a38d 83c610 add    esi,0x10
0x56a390 8d7df8 lea    edi,[ebp-0x8]
0x56a393 e8c8d31800 call   0x6f7760
0x56a398 85c0 test   eax,eax
0x56a39a 744e je     0x56a3ea
0x56a39c dd45f8 fld    QWORD PTR [ebp-0x8]
0x56a39f c745f803000000 mov    DWORD PTR [ebp-0x8],0x3
0x56a3a6 dd5df0 fstp   QWORD PTR [ebp-0x10]
0x56a3a9 8d45f0 lea    eax,[ebp-0x10]
0x56a3ac dd00 fld    QWORD PTR [eax]
0x56a3ae dd5df8 fstp   QWORD PTR [ebp-0x8]
0x56a3b1 dd45f8 fld    QWORD PTR [ebp-0x8]
0x56a3b4 db5d08 fistp  DWORD PTR [ebp+0x8]
0x56a3b7 8b4d08 mov    ecx,DWORD PTR [ebp+0x8]
0x56a3ba 894dfc mov    DWORD PTR [ebp-0x4],ecx
0x56a3bd 8b3b mov    edi,DWORD PTR [ebx]
0x56a3bf 8b7708 mov    esi,DWORD PTR [edi+0x8]
0x56a3c2 83ee20 sub    esi,0x20
0x56a3c5 837e0804 cmp    DWORD PTR [esi+0x8],0x4
0x56a3c9 7440 je     0x56a40b
0x56a3cb e800121900 call   0x6fb5d0
0x56a3d0 85c0 test   eax,eax
0x56a3d2 751f jne    0x56a3f3
0x56a3d4 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x56a3d7 8b4dec mov    ecx,DWORD PTR [ebp-0x14]
0x56a3da 50 push   eax
0x56a3db 33f6 xor    esi,esi
0x56a3dd 56 push   esi
0x56a3de ff550c call   DWORD PTR [ebp+0xc]
0x56a3e1 5f pop    edi
0x56a3e2 5e pop    esi
0x56a3e3 33c0 xor    eax,eax
0x56a3e5 5b pop    ebx
0x56a3e6 8be5 mov    esp,ebp
0x56a3e8 5d pop    ebp
0x56a3e9 c3 ret
0x56a3ea c745fc00000000 mov    DWORD PTR [ebp-0x4],0x0
0x56a3f1 ebca jmp    0x56a3bd
0x56a3f3 8b4710 mov    eax,DWORD PTR [edi+0x10]
0x56a3f6 8b5044 mov    edx,DWORD PTR [eax+0x44]
0x56a3f9 3b5040 cmp    edx,DWORD PTR [eax+0x40]
0x56a3fc 7207 jb     0x56a405
0x56a3fe 8bc7 mov    eax,edi
0x56a400 e89b0f1900 call   0x6fb3a0
0x56a405 8b7708 mov    esi,DWORD PTR [edi+0x8]
0x56a408 83ee20 sub    esi,0x20
0x56a40b 8b36 mov    esi,DWORD PTR [esi]
0x56a40d 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x56a410 8b4dec mov    ecx,DWORD PTR [ebp-0x14]
0x56a413 50 push   eax
0x56a414 83c610 add    esi,0x10
0x56a417 56 push   esi
0x56a418 ff550c call   DWORD PTR [ebp+0xc]
0x56a41b 5f pop    edi
0x56a41c 5e pop    esi
0x56a41d 33c0 xor    eax,eax
0x56a41f 5b pop    ebx
0x56a420 8be5 mov    esp,ebp
0x56a422 5d pop    ebp
0x56a423 c3 ret

; F_00568CE0 0x568ce0..0x568d3c
0x568ce0 55 push   ebp
0x568ce1 8bec mov    ebp,esp
0x568ce3 6aff push   0xffffffff
0x568ce5 68c8839300 push   0x9383c8
0x568cea 64a100000000 mov    eax,fs:0x0
0x568cf0 50 push   eax
0x568cf1 83ec0c sub    esp,0xc
0x568cf4 a1201fd600 mov    eax,ds:0xd61f20
0x568cf9 33c5 xor    eax,ebp
0x568cfb 50 push   eax
0x568cfc 8d45f4 lea    eax,[ebp-0xc]
0x568cff 64a300000000 mov    fs:0x0,eax
0x568d05 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x568d08 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x568d0b 33c0 xor    eax,eax
0x568d0d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x568d10 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x568d13 8945fc mov    DWORD PTR [ebp-0x4],eax
0x568d16 8b0d9827fe00 mov    ecx,DWORD PTR ds:0xfe2798
0x568d1c 51 push   ecx
0x568d1d 8d45e8 lea    eax,[ebp-0x18]
0x568d20 e80b170000 call   0x56a430
0x568d25 83c404 add    esp,0x4
0x568d28 b801000000 mov    eax,0x1
0x568d2d 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x568d30 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x568d37 59 pop    ecx
0x568d38 8be5 mov    esp,ebp
0x568d3a 5d pop    ebp
0x568d3b c3 ret

; F_0056A430 0x56a430..0x56a4a3
0x56a430 55 push   ebp
0x56a431 8bec mov    ebp,esp
0x56a433 8b08 mov    ecx,DWORD PTR [eax]
0x56a435 83ec18 sub    esp,0x18
0x56a438 53 push   ebx
0x56a439 8b1d7827fe00 mov    ebx,DWORD PTR ds:0xfe2778
0x56a43f 83c8ff or     eax,0xffffffff
0x56a442 e8a9ac1800 call   0x6f50f0
0x56a447 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56a44a 83f903 cmp    ecx,0x3
0x56a44d 742a je     0x56a479
0x56a44f 83f904 cmp    ecx,0x4
0x56a452 7540 jne    0x56a494
0x56a454 56 push   esi
0x56a455 8b30 mov    esi,DWORD PTR [eax]
0x56a457 57 push   edi
0x56a458 83c610 add    esi,0x10
0x56a45b 8d7df8 lea    edi,[ebp-0x8]
0x56a45e e8fdd21800 call   0x6f7760
0x56a463 5f pop    edi
0x56a464 5e pop    esi
0x56a465 85c0 test   eax,eax
0x56a467 742b je     0x56a494
0x56a469 dd45f8 fld    QWORD PTR [ebp-0x8]
0x56a46c c745f003000000 mov    DWORD PTR [ebp-0x10],0x3
0x56a473 dd5de8 fstp   QWORD PTR [ebp-0x18]
0x56a476 8d45e8 lea    eax,[ebp-0x18]
0x56a479 dd00 fld    QWORD PTR [eax]
0x56a47b dd5df0 fstp   QWORD PTR [ebp-0x10]
0x56a47e dd45f0 fld    QWORD PTR [ebp-0x10]
0x56a481 db5dfc fistp  DWORD PTR [ebp-0x4]
0x56a484 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x56a487 50 push   eax
0x56a488 8bcb mov    ecx,ebx
0x56a48a ff5508 call   DWORD PTR [ebp+0x8]
0x56a48d 33c0 xor    eax,eax
0x56a48f 5b pop    ebx
0x56a490 8be5 mov    esp,ebp
0x56a492 5d pop    ebp
0x56a493 c3 ret
0x56a494 33c0 xor    eax,eax
0x56a496 50 push   eax
0x56a497 8bcb mov    ecx,ebx
0x56a499 ff5508 call   DWORD PTR [ebp+0x8]
0x56a49c 33c0 xor    eax,eax
0x56a49e 5b pop    ebx
0x56a49f 8be5 mov    esp,ebp
0x56a4a1 5d pop    ebp
0x56a4a2 c3 ret

; F_00568D40 0x568d40..0x568d9d
0x568d40 55 push   ebp
0x568d41 8bec mov    ebp,esp
0x568d43 6aff push   0xffffffff
0x568d45 68c8839300 push   0x9383c8
0x568d4a 64a100000000 mov    eax,fs:0x0
0x568d50 50 push   eax
0x568d51 83ec0c sub    esp,0xc
0x568d54 a1201fd600 mov    eax,ds:0xd61f20
0x568d59 33c5 xor    eax,ebp
0x568d5b 50 push   eax
0x568d5c 8d45f4 lea    eax,[ebp-0xc]
0x568d5f 64a300000000 mov    fs:0x0,eax
0x568d65 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x568d68 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x568d6b 33c0 xor    eax,eax
0x568d6d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x568d70 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x568d73 8945fc mov    DWORD PTR [ebp-0x4],eax
0x568d76 8b0d9c27fe00 mov    ecx,DWORD PTR ds:0xfe279c
0x568d7c 51 push   ecx
0x568d7d 8d55e8 lea    edx,[ebp-0x18]
0x568d80 52 push   edx
0x568d81 e82a170000 call   0x56a4b0
0x568d86 83c408 add    esp,0x8
0x568d89 b801000000 mov    eax,0x1
0x568d8e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x568d91 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x568d98 59 pop    ecx
0x568d99 8be5 mov    esp,ebp
0x568d9b 5d pop    ebp
0x568d9c c3 ret

; F_0056A4B0 0x56a4b0..0x56a5e1
0x56a4b0 55 push   ebp
0x56a4b1 8bec mov    ebp,esp
0x56a4b3 83ec2c sub    esp,0x2c
0x56a4b6 a17827fe00 mov    eax,ds:0xfe2778
0x56a4bb 53 push   ebx
0x56a4bc 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x56a4bf 8b0b mov    ecx,DWORD PTR [ebx]
0x56a4c1 56 push   esi
0x56a4c2 8945e4 mov    DWORD PTR [ebp-0x1c],eax
0x56a4c5 57 push   edi
0x56a4c6 83c8ff or     eax,0xffffffff
0x56a4c9 e822ac1800 call   0x6f50f0
0x56a4ce 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56a4d1 83f903 cmp    ecx,0x3
0x56a4d4 742e je     0x56a504
0x56a4d6 83f904 cmp    ecx,0x4
0x56a4d9 0f85e9000000 jne    0x56a5c8
0x56a4df 8b30 mov    esi,DWORD PTR [eax]
0x56a4e1 83c610 add    esi,0x10
0x56a4e4 8d7de8 lea    edi,[ebp-0x18]
0x56a4e7 e874d21800 call   0x6f7760
0x56a4ec 85c0 test   eax,eax
0x56a4ee 0f84d4000000 je     0x56a5c8
0x56a4f4 dd45e8 fld    QWORD PTR [ebp-0x18]
0x56a4f7 c745dc03000000 mov    DWORD PTR [ebp-0x24],0x3
0x56a4fe dd5dd4 fstp   QWORD PTR [ebp-0x2c]
0x56a501 8d45d4 lea    eax,[ebp-0x2c]
0x56a504 dd00 fld    QWORD PTR [eax]
0x56a506 dd5de8 fstp   QWORD PTR [ebp-0x18]
0x56a509 dd45e8 fld    QWORD PTR [ebp-0x18]
0x56a50c db5d08 fistp  DWORD PTR [ebp+0x8]
0x56a50f 8b4d08 mov    ecx,DWORD PTR [ebp+0x8]
0x56a512 894df0 mov    DWORD PTR [ebp-0x10],ecx
0x56a515 8b0b mov    ecx,DWORD PTR [ebx]
0x56a517 b8feffffff mov    eax,0xfffffffe
0x56a51c e8cfab1800 call   0x6f50f0
0x56a521 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56a524 83f903 cmp    ecx,0x3
0x56a527 742e je     0x56a557
0x56a529 83f904 cmp    ecx,0x4
0x56a52c 0f85a2000000 jne    0x56a5d4
0x56a532 8b30 mov    esi,DWORD PTR [eax]
0x56a534 83c610 add    esi,0x10
0x56a537 8d7de8 lea    edi,[ebp-0x18]
0x56a53a e821d21800 call   0x6f7760
0x56a53f 85c0 test   eax,eax
0x56a541 0f848d000000 je     0x56a5d4
0x56a547 dd45e8 fld    QWORD PTR [ebp-0x18]
0x56a54a c745dc03000000 mov    DWORD PTR [ebp-0x24],0x3
0x56a551 dd5dd4 fstp   QWORD PTR [ebp-0x2c]
0x56a554 8d45d4 lea    eax,[ebp-0x2c]
0x56a557 dd00 fld    QWORD PTR [eax]
0x56a559 dd5de8 fstp   QWORD PTR [ebp-0x18]
0x56a55c dd45e8 fld    QWORD PTR [ebp-0x18]
0x56a55f db5dfc fistp  DWORD PTR [ebp-0x4]
0x56a562 8b55fc mov    edx,DWORD PTR [ebp-0x4]
0x56a565 8955ec mov    DWORD PTR [ebp-0x14],edx
0x56a568 8b0b mov    ecx,DWORD PTR [ebx]
0x56a56a b8fdffffff mov    eax,0xfffffffd
0x56a56f e87cab1800 call   0x6f50f0
0x56a574 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56a577 83f903 cmp    ecx,0x3
0x56a57a 7426 je     0x56a5a2
0x56a57c 83f904 cmp    ecx,0x4
0x56a57f 755c jne    0x56a5dd
0x56a581 8b30 mov    esi,DWORD PTR [eax]
0x56a583 83c610 add    esi,0x10
0x56a586 8d7df4 lea    edi,[ebp-0xc]
0x56a589 e8d2d11800 call   0x6f7760
0x56a58e 85c0 test   eax,eax
0x56a590 744b je     0x56a5dd
0x56a592 dd45f4 fld    QWORD PTR [ebp-0xc]
0x56a595 c745dc03000000 mov    DWORD PTR [ebp-0x24],0x3
0x56a59c dd5dd4 fstp   QWORD PTR [ebp-0x2c]
0x56a59f 8d45d4 lea    eax,[ebp-0x2c]
0x56a5a2 dd00 fld    QWORD PTR [eax]
0x56a5a4 dd5ddc fstp   QWORD PTR [ebp-0x24]
0x56a5a7 dd45dc fld    QWORD PTR [ebp-0x24]
0x56a5aa db5df8 fistp  DWORD PTR [ebp-0x8]
0x56a5ad 8b45f8 mov    eax,DWORD PTR [ebp-0x8]
0x56a5b0 8b4df0 mov    ecx,DWORD PTR [ebp-0x10]
0x56a5b3 8b55ec mov    edx,DWORD PTR [ebp-0x14]
0x56a5b6 51 push   ecx
0x56a5b7 8b4de4 mov    ecx,DWORD PTR [ebp-0x1c]
0x56a5ba 52 push   edx
0x56a5bb 50 push   eax
0x56a5bc ff550c call   DWORD PTR [ebp+0xc]
0x56a5bf 5f pop    edi
0x56a5c0 5e pop    esi
0x56a5c1 33c0 xor    eax,eax
0x56a5c3 5b pop    ebx
0x56a5c4 8be5 mov    esp,ebp
0x56a5c6 5d pop    ebp
0x56a5c7 c3 ret
0x56a5c8 c745f000000000 mov    DWORD PTR [ebp-0x10],0x0
0x56a5cf e941ffffff jmp    0x56a515
0x56a5d4 c745ec00000000 mov    DWORD PTR [ebp-0x14],0x0
0x56a5db eb8b jmp    0x56a568
0x56a5dd 33c0 xor    eax,eax
0x56a5df ebcf jmp    0x56a5b0

; F_00568DA0 0x568da0..0x568dfd
0x568da0 55 push   ebp
0x568da1 8bec mov    ebp,esp
0x568da3 6aff push   0xffffffff
0x568da5 68c8839300 push   0x9383c8
0x568daa 64a100000000 mov    eax,fs:0x0
0x568db0 50 push   eax
0x568db1 83ec0c sub    esp,0xc
0x568db4 a1201fd600 mov    eax,ds:0xd61f20
0x568db9 33c5 xor    eax,ebp
0x568dbb 50 push   eax
0x568dbc 8d45f4 lea    eax,[ebp-0xc]
0x568dbf 64a300000000 mov    fs:0x0,eax
0x568dc5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x568dc8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x568dcb 33c0 xor    eax,eax
0x568dcd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x568dd0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x568dd3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x568dd6 8b0da027fe00 mov    ecx,DWORD PTR ds:0xfe27a0
0x568ddc 51 push   ecx
0x568ddd 8d55e8 lea    edx,[ebp-0x18]
0x568de0 52 push   edx
0x568de1 e80a180000 call   0x56a5f0
0x568de6 83c408 add    esp,0x8
0x568de9 b801000000 mov    eax,0x1
0x568dee 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x568df1 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x568df8 59 pop    ecx
0x568df9 8be5 mov    esp,ebp
0x568dfb 5d pop    ebp
0x568dfc c3 ret

; F_0056A5F0 0x56a5f0..0x56a706
0x56a5f0 55 push   ebp
0x56a5f1 8bec mov    ebp,esp
0x56a5f3 83ec24 sub    esp,0x24
0x56a5f6 a17827fe00 mov    eax,ds:0xfe2778
0x56a5fb 53 push   ebx
0x56a5fc 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x56a5ff 8945fc mov    DWORD PTR [ebp-0x4],eax
0x56a602 8b03 mov    eax,DWORD PTR [ebx]
0x56a604 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x56a607 8b48f8 mov    ecx,DWORD PTR [eax-0x8]
0x56a60a 83e810 sub    eax,0x10
0x56a60d 56 push   esi
0x56a60e 57 push   edi
0x56a60f 83f903 cmp    ecx,0x3
0x56a612 742e je     0x56a642
0x56a614 83f904 cmp    ecx,0x4
0x56a617 0f85da000000 jne    0x56a6f7
0x56a61d 8b30 mov    esi,DWORD PTR [eax]
0x56a61f 83c610 add    esi,0x10
0x56a622 8d7dec lea    edi,[ebp-0x14]
0x56a625 e836d11800 call   0x6f7760
0x56a62a 85c0 test   eax,eax
0x56a62c 0f84c5000000 je     0x56a6f7
0x56a632 dd45ec fld    QWORD PTR [ebp-0x14]
0x56a635 c745e403000000 mov    DWORD PTR [ebp-0x1c],0x3
0x56a63c dd5ddc fstp   QWORD PTR [ebp-0x24]
0x56a63f 8d45dc lea    eax,[ebp-0x24]
0x56a642 dd00 fld    QWORD PTR [eax]
0x56a644 8b03 mov    eax,DWORD PTR [ebx]
0x56a646 dd5df4 fstp   QWORD PTR [ebp-0xc]
0x56a649 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x56a64c 8b48e8 mov    ecx,DWORD PTR [eax-0x18]
0x56a64f 83e820 sub    eax,0x20
0x56a652 83f903 cmp    ecx,0x3
0x56a655 742e je     0x56a685
0x56a657 83f904 cmp    ecx,0x4
0x56a65a 0f859e000000 jne    0x56a6fe
0x56a660 8b30 mov    esi,DWORD PTR [eax]
0x56a662 83c610 add    esi,0x10
0x56a665 8d7dec lea    edi,[ebp-0x14]
0x56a668 e8f3d01800 call   0x6f7760
0x56a66d 85c0 test   eax,eax
0x56a66f 0f8489000000 je     0x56a6fe
0x56a675 dd45ec fld    QWORD PTR [ebp-0x14]
0x56a678 c745e403000000 mov    DWORD PTR [ebp-0x1c],0x3
0x56a67f dd5ddc fstp   QWORD PTR [ebp-0x24]
0x56a682 8d45dc lea    eax,[ebp-0x24]
0x56a685 dd00 fld    QWORD PTR [eax]
0x56a687 8b1b mov    ebx,DWORD PTR [ebx]
0x56a689 dd5dec fstp   QWORD PTR [ebp-0x14]
0x56a68c 8b4308 mov    eax,DWORD PTR [ebx+0x8]
0x56a68f 8b48d8 mov    ecx,DWORD PTR [eax-0x28]
0x56a692 83e830 sub    eax,0x30
0x56a695 83f903 cmp    ecx,0x3
0x56a698 7426 je     0x56a6c0
0x56a69a 83f904 cmp    ecx,0x4
0x56a69d 7563 jne    0x56a702
0x56a69f 8b30 mov    esi,DWORD PTR [eax]
0x56a6a1 83c610 add    esi,0x10
0x56a6a4 8d7de4 lea    edi,[ebp-0x1c]
0x56a6a7 e8b4d01800 call   0x6f7760
0x56a6ac 85c0 test   eax,eax
0x56a6ae 7452 je     0x56a702
0x56a6b0 dd45e4 fld    QWORD PTR [ebp-0x1c]
0x56a6b3 c745e403000000 mov    DWORD PTR [ebp-0x1c],0x3
0x56a6ba dd5ddc fstp   QWORD PTR [ebp-0x24]
0x56a6bd 8d45dc lea    eax,[ebp-0x24]
0x56a6c0 dd00 fld    QWORD PTR [eax]
0x56a6c2 dd45f4 fld    QWORD PTR [ebp-0xc]
0x56a6c5 8b4dfc mov    ecx,DWORD PTR [ebp-0x4]
0x56a6c8 d95d08 fstp   DWORD PTR [ebp+0x8]
0x56a6cb 83ec0c sub    esp,0xc
0x56a6ce d94508 fld    DWORD PTR [ebp+0x8]
0x56a6d1 d95c2408 fstp   DWORD PTR [esp+0x8]
0x56a6d5 dd45ec fld    QWORD PTR [ebp-0x14]
0x56a6d8 d95d08 fstp   DWORD PTR [ebp+0x8]
0x56a6db d94508 fld    DWORD PTR [ebp+0x8]
0x56a6de d95c2404 fstp   DWORD PTR [esp+0x4]
0x56a6e2 d95d08 fstp   DWORD PTR [ebp+0x8]
0x56a6e5 d94508 fld    DWORD PTR [ebp+0x8]
0x56a6e8 d91c24 fstp   DWORD PTR [esp]
0x56a6eb ff550c call   DWORD PTR [ebp+0xc]
0x56a6ee 5f pop    edi
0x56a6ef 5e pop    esi
0x56a6f0 33c0 xor    eax,eax
0x56a6f2 5b pop    ebx
0x56a6f3 8be5 mov    esp,ebp
0x56a6f5 5d pop    ebp
0x56a6f6 c3 ret
0x56a6f7 d9ee fldz
0x56a6f9 e946ffffff jmp    0x56a644
0x56a6fe d9ee fldz
0x56a700 eb85 jmp    0x56a687
0x56a702 d9ee fldz
0x56a704 ebbc jmp    0x56a6c2

; F_00568E00 0x568e00..0x568e56
0x568e00 55 push   ebp
0x568e01 8bec mov    ebp,esp
0x568e03 6aff push   0xffffffff
0x568e05 68c8839300 push   0x9383c8
0x568e0a 64a100000000 mov    eax,fs:0x0
0x568e10 50 push   eax
0x568e11 83ec0c sub    esp,0xc
0x568e14 a1201fd600 mov    eax,ds:0xd61f20
0x568e19 33c5 xor    eax,ebp
0x568e1b 50 push   eax
0x568e1c 8d45f4 lea    eax,[ebp-0xc]
0x568e1f 64a300000000 mov    fs:0x0,eax
0x568e25 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x568e28 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x568e2b 33c0 xor    eax,eax
0x568e2d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x568e30 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x568e33 8d4de8 lea    ecx,[ebp-0x18]
0x568e36 51 push   ecx
0x568e37 8945fc mov    DWORD PTR [ebp-0x4],eax
0x568e3a e8d1180000 call   0x56a710
0x568e3f 83c404 add    esp,0x4
0x568e42 b801000000 mov    eax,0x1
0x568e47 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x568e4a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x568e51 59 pop    ecx
0x568e52 8be5 mov    esp,ebp
0x568e54 5d pop    ebp
0x568e55 c3 ret

; F_0056A710 0x56a710..0x56aa94
0x56a710 55 push   ebp
0x56a711 8bec mov    ebp,esp
0x56a713 83ec60 sub    esp,0x60
0x56a716 a1a427fe00 mov    eax,ds:0xfe27a4
0x56a71b 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x56a721 53 push   ebx
0x56a722 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x56a725 56 push   esi
0x56a726 8945c0 mov    DWORD PTR [ebp-0x40],eax
0x56a729 894dc4 mov    DWORD PTR [ebp-0x3c],ecx
0x56a72c 8b0b mov    ecx,DWORD PTR [ebx]
0x56a72e 57 push   edi
0x56a72f 83c8ff or     eax,0xffffffff
0x56a732 e8b9a91800 call   0x6f50f0
0x56a737 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56a73a 83f903 cmp    ecx,0x3
0x56a73d 742e je     0x56a76d
0x56a73f 83f904 cmp    ecx,0x4
0x56a742 0f85ef020000 jne    0x56aa37
0x56a748 8b30 mov    esi,DWORD PTR [eax]
0x56a74a 83c610 add    esi,0x10
0x56a74d 8d7db0 lea    edi,[ebp-0x50]
0x56a750 e80bd01800 call   0x6f7760
0x56a755 85c0 test   eax,eax
0x56a757 0f84da020000 je     0x56aa37
0x56a75d dd45b0 fld    QWORD PTR [ebp-0x50]
0x56a760 c745a803000000 mov    DWORD PTR [ebp-0x58],0x3
0x56a767 dd5da0 fstp   QWORD PTR [ebp-0x60]
0x56a76a 8d45a0 lea    eax,[ebp-0x60]
0x56a76d dd00 fld    QWORD PTR [eax]
0x56a76f dd5db0 fstp   QWORD PTR [ebp-0x50]
0x56a772 dd45b0 fld    QWORD PTR [ebp-0x50]
0x56a775 db5d08 fistp  DWORD PTR [ebp+0x8]
0x56a778 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x56a77b 8955e0 mov    DWORD PTR [ebp-0x20],edx
0x56a77e 8b0b mov    ecx,DWORD PTR [ebx]
0x56a780 b8feffffff mov    eax,0xfffffffe
0x56a785 e866a91800 call   0x6f50f0
0x56a78a 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56a78d 83f903 cmp    ecx,0x3
0x56a790 742e je     0x56a7c0
0x56a792 83f904 cmp    ecx,0x4
0x56a795 0f85a8020000 jne    0x56aa43
0x56a79b 8b30 mov    esi,DWORD PTR [eax]
0x56a79d 83c610 add    esi,0x10
0x56a7a0 8d7db0 lea    edi,[ebp-0x50]
0x56a7a3 e8b8cf1800 call   0x6f7760
0x56a7a8 85c0 test   eax,eax
0x56a7aa 0f8493020000 je     0x56aa43
0x56a7b0 dd45b0 fld    QWORD PTR [ebp-0x50]
0x56a7b3 c745a803000000 mov    DWORD PTR [ebp-0x58],0x3
0x56a7ba dd5da0 fstp   QWORD PTR [ebp-0x60]
0x56a7bd 8d45a0 lea    eax,[ebp-0x60]
0x56a7c0 dd00 fld    QWORD PTR [eax]
0x56a7c2 dd5db0 fstp   QWORD PTR [ebp-0x50]
0x56a7c5 dd45b0 fld    QWORD PTR [ebp-0x50]
0x56a7c8 db5dfc fistp  DWORD PTR [ebp-0x4]
0x56a7cb 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x56a7ce 8945dc mov    DWORD PTR [ebp-0x24],eax
0x56a7d1 8b0b mov    ecx,DWORD PTR [ebx]
0x56a7d3 b8fdffffff mov    eax,0xfffffffd
0x56a7d8 e813a91800 call   0x6f50f0
0x56a7dd 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56a7e0 83f903 cmp    ecx,0x3
0x56a7e3 742e je     0x56a813
0x56a7e5 83f904 cmp    ecx,0x4
0x56a7e8 0f8561020000 jne    0x56aa4f
0x56a7ee 8b30 mov    esi,DWORD PTR [eax]
0x56a7f0 83c610 add    esi,0x10
0x56a7f3 8d7db0 lea    edi,[ebp-0x50]
0x56a7f6 e865cf1800 call   0x6f7760
0x56a7fb 85c0 test   eax,eax
0x56a7fd 0f844c020000 je     0x56aa4f
0x56a803 dd45b0 fld    QWORD PTR [ebp-0x50]
0x56a806 c745a803000000 mov    DWORD PTR [ebp-0x58],0x3
0x56a80d dd5da0 fstp   QWORD PTR [ebp-0x60]
0x56a810 8d45a0 lea    eax,[ebp-0x60]
0x56a813 dd00 fld    QWORD PTR [eax]
0x56a815 dd5db0 fstp   QWORD PTR [ebp-0x50]
0x56a818 dd45b0 fld    QWORD PTR [ebp-0x50]
0x56a81b db5df8 fistp  DWORD PTR [ebp-0x8]
0x56a81e 8b4df8 mov    ecx,DWORD PTR [ebp-0x8]
0x56a821 894dd8 mov    DWORD PTR [ebp-0x28],ecx
0x56a824 8b0b mov    ecx,DWORD PTR [ebx]
0x56a826 b8fcffffff mov    eax,0xfffffffc
0x56a82b e8c0a81800 call   0x6f50f0
0x56a830 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56a833 83f903 cmp    ecx,0x3
0x56a836 742e je     0x56a866
0x56a838 83f904 cmp    ecx,0x4
0x56a83b 0f851a020000 jne    0x56aa5b
0x56a841 8b30 mov    esi,DWORD PTR [eax]
0x56a843 83c610 add    esi,0x10
0x56a846 8d7db0 lea    edi,[ebp-0x50]
0x56a849 e812cf1800 call   0x6f7760
0x56a84e 85c0 test   eax,eax
0x56a850 0f8405020000 je     0x56aa5b
0x56a856 dd45b0 fld    QWORD PTR [ebp-0x50]
0x56a859 c745a803000000 mov    DWORD PTR [ebp-0x58],0x3
0x56a860 dd5da0 fstp   QWORD PTR [ebp-0x60]
0x56a863 8d45a0 lea    eax,[ebp-0x60]
0x56a866 dd00 fld    QWORD PTR [eax]
0x56a868 dd5db0 fstp   QWORD PTR [ebp-0x50]
0x56a86b dd45b0 fld    QWORD PTR [ebp-0x50]
0x56a86e db5df4 fistp  DWORD PTR [ebp-0xc]
0x56a871 8b55f4 mov    edx,DWORD PTR [ebp-0xc]
0x56a874 8955d4 mov    DWORD PTR [ebp-0x2c],edx
0x56a877 8b0b mov    ecx,DWORD PTR [ebx]
0x56a879 b8fbffffff mov    eax,0xfffffffb
0x56a87e e86da81800 call   0x6f50f0
0x56a883 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56a886 83f903 cmp    ecx,0x3
0x56a889 742e je     0x56a8b9
0x56a88b 83f904 cmp    ecx,0x4
0x56a88e 0f85d3010000 jne    0x56aa67
0x56a894 8b30 mov    esi,DWORD PTR [eax]
0x56a896 83c610 add    esi,0x10
0x56a899 8d7db0 lea    edi,[ebp-0x50]
0x56a89c e8bfce1800 call   0x6f7760
0x56a8a1 85c0 test   eax,eax
0x56a8a3 0f84be010000 je     0x56aa67
0x56a8a9 dd45b0 fld    QWORD PTR [ebp-0x50]
0x56a8ac c745a803000000 mov    DWORD PTR [ebp-0x58],0x3
0x56a8b3 dd5da0 fstp   QWORD PTR [ebp-0x60]
0x56a8b6 8d45a0 lea    eax,[ebp-0x60]
0x56a8b9 dd00 fld    QWORD PTR [eax]
0x56a8bb dd5db0 fstp   QWORD PTR [ebp-0x50]
0x56a8be dd45b0 fld    QWORD PTR [ebp-0x50]
0x56a8c1 db5df0 fistp  DWORD PTR [ebp-0x10]
0x56a8c4 8b45f0 mov    eax,DWORD PTR [ebp-0x10]
0x56a8c7 8945d0 mov    DWORD PTR [ebp-0x30],eax
0x56a8ca 8b03 mov    eax,DWORD PTR [ebx]
0x56a8cc 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x56a8cf 8b48a8 mov    ecx,DWORD PTR [eax-0x58]
0x56a8d2 83e860 sub    eax,0x60
0x56a8d5 83f903 cmp    ecx,0x3
0x56a8d8 742e je     0x56a908
0x56a8da 83f904 cmp    ecx,0x4
0x56a8dd 0f8590010000 jne    0x56aa73
0x56a8e3 8b30 mov    esi,DWORD PTR [eax]
0x56a8e5 83c610 add    esi,0x10
0x56a8e8 8d7db0 lea    edi,[ebp-0x50]
0x56a8eb e870ce1800 call   0x6f7760
0x56a8f0 85c0 test   eax,eax
0x56a8f2 0f847b010000 je     0x56aa73
0x56a8f8 dd45b0 fld    QWORD PTR [ebp-0x50]
0x56a8fb c745a803000000 mov    DWORD PTR [ebp-0x58],0x3
0x56a902 dd5da0 fstp   QWORD PTR [ebp-0x60]
0x56a905 8d45a0 lea    eax,[ebp-0x60]
0x56a908 dd00 fld    QWORD PTR [eax]
0x56a90a 8b03 mov    eax,DWORD PTR [ebx]
0x56a90c dd5db8 fstp   QWORD PTR [ebp-0x48]
0x56a90f 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x56a912 8b4898 mov    ecx,DWORD PTR [eax-0x68]
0x56a915 83e870 sub    eax,0x70
0x56a918 83f903 cmp    ecx,0x3
0x56a91b 742e je     0x56a94b
0x56a91d 83f904 cmp    ecx,0x4
0x56a920 0f8554010000 jne    0x56aa7a
0x56a926 8b30 mov    esi,DWORD PTR [eax]
0x56a928 83c610 add    esi,0x10
0x56a92b 8d7db0 lea    edi,[ebp-0x50]
0x56a92e e82dce1800 call   0x6f7760
0x56a933 85c0 test   eax,eax
0x56a935 0f843f010000 je     0x56aa7a
0x56a93b dd45b0 fld    QWORD PTR [ebp-0x50]
0x56a93e c745a803000000 mov    DWORD PTR [ebp-0x58],0x3
0x56a945 dd5da0 fstp   QWORD PTR [ebp-0x60]
0x56a948 8d45a0 lea    eax,[ebp-0x60]
0x56a94b dd00 fld    QWORD PTR [eax]
0x56a94d 8b0b mov    ecx,DWORD PTR [ebx]
0x56a94f dd5db0 fstp   QWORD PTR [ebp-0x50]
0x56a952 b8f8ffffff mov    eax,0xfffffff8
0x56a957 e894a71800 call   0x6f50f0
0x56a95c 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56a95f 83f903 cmp    ecx,0x3
0x56a962 742e je     0x56a992
0x56a964 83f904 cmp    ecx,0x4
0x56a967 0f8514010000 jne    0x56aa81
0x56a96d 8b30 mov    esi,DWORD PTR [eax]
0x56a96f 83c610 add    esi,0x10
0x56a972 8d7dc8 lea    edi,[ebp-0x38]
0x56a975 e8e6cd1800 call   0x6f7760
0x56a97a 85c0 test   eax,eax
0x56a97c 0f84ff000000 je     0x56aa81
0x56a982 dd45c8 fld    QWORD PTR [ebp-0x38]
0x56a985 c745a803000000 mov    DWORD PTR [ebp-0x58],0x3
0x56a98c dd5da0 fstp   QWORD PTR [ebp-0x60]
0x56a98f 8d45a0 lea    eax,[ebp-0x60]
0x56a992 dd00 fld    QWORD PTR [eax]
0x56a994 dd5dc8 fstp   QWORD PTR [ebp-0x38]
0x56a997 dd45c8 fld    QWORD PTR [ebp-0x38]
0x56a99a db5dec fistp  DWORD PTR [ebp-0x14]
0x56a99d 8b4dec mov    ecx,DWORD PTR [ebp-0x14]
0x56a9a0 894dcc mov    DWORD PTR [ebp-0x34],ecx
0x56a9a3 8b0b mov    ecx,DWORD PTR [ebx]
0x56a9a5 b8f7ffffff mov    eax,0xfffffff7
0x56a9aa e841a71800 call   0x6f50f0
0x56a9af 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56a9b2 83f903 cmp    ecx,0x3
0x56a9b5 742e je     0x56a9e5
0x56a9b7 83f904 cmp    ecx,0x4
0x56a9ba 0f85cd000000 jne    0x56aa8d
0x56a9c0 8b30 mov    esi,DWORD PTR [eax]
0x56a9c2 83c610 add    esi,0x10
0x56a9c5 8d7de4 lea    edi,[ebp-0x1c]
0x56a9c8 e893cd1800 call   0x6f7760
0x56a9cd 85c0 test   eax,eax
0x56a9cf 0f84b8000000 je     0x56aa8d
0x56a9d5 dd45e4 fld    QWORD PTR [ebp-0x1c]
0x56a9d8 c745a803000000 mov    DWORD PTR [ebp-0x58],0x3
0x56a9df dd5da0 fstp   QWORD PTR [ebp-0x60]
0x56a9e2 8d45a0 lea    eax,[ebp-0x60]
0x56a9e5 dd00 fld    QWORD PTR [eax]
0x56a9e7 dd5da8 fstp   QWORD PTR [ebp-0x58]
0x56a9ea dd45a8 fld    QWORD PTR [ebp-0x58]
0x56a9ed db5de8 fistp  DWORD PTR [ebp-0x18]
0x56a9f0 8b45e8 mov    eax,DWORD PTR [ebp-0x18]
0x56a9f3 8b55e0 mov    edx,DWORD PTR [ebp-0x20]
0x56a9f6 dd45b8 fld    QWORD PTR [ebp-0x48]
0x56a9f9 8b4ddc mov    ecx,DWORD PTR [ebp-0x24]
0x56a9fc 52 push   edx
0x56a9fd 8b55d8 mov    edx,DWORD PTR [ebp-0x28]
0x56aa00 51 push   ecx
0x56aa01 8b4dd4 mov    ecx,DWORD PTR [ebp-0x2c]
0x56aa04 52 push   edx
0x56aa05 8b55d0 mov    edx,DWORD PTR [ebp-0x30]
0x56aa08 d95dd0 fstp   DWORD PTR [ebp-0x30]
0x56aa0b d945d0 fld    DWORD PTR [ebp-0x30]
0x56aa0e 51 push   ecx
0x56aa0f 8b4dcc mov    ecx,DWORD PTR [ebp-0x34]
0x56aa12 52 push   edx
0x56aa13 83ec08 sub    esp,0x8
0x56aa16 d95c2404 fstp   DWORD PTR [esp+0x4]
0x56aa1a dd45b0 fld    QWORD PTR [ebp-0x50]
0x56aa1d d95dd0 fstp   DWORD PTR [ebp-0x30]
0x56aa20 d945d0 fld    DWORD PTR [ebp-0x30]
0x56aa23 d91c24 fstp   DWORD PTR [esp]
0x56aa26 51 push   ecx
0x56aa27 8b4dc4 mov    ecx,DWORD PTR [ebp-0x3c]
0x56aa2a 50 push   eax
0x56aa2b ff55c0 call   DWORD PTR [ebp-0x40]
0x56aa2e 5f pop    edi
0x56aa2f 5e pop    esi
0x56aa30 33c0 xor    eax,eax
0x56aa32 5b pop    ebx
0x56aa33 8be5 mov    esp,ebp
0x56aa35 5d pop    ebp
0x56aa36 c3 ret
0x56aa37 c745e000000000 mov    DWORD PTR [ebp-0x20],0x0
0x56aa3e e93bfdffff jmp    0x56a77e
0x56aa43 c745dc00000000 mov    DWORD PTR [ebp-0x24],0x0
0x56aa4a e982fdffff jmp    0x56a7d1
0x56aa4f c745d800000000 mov    DWORD PTR [ebp-0x28],0x0
0x56aa56 e9c9fdffff jmp    0x56a824
0x56aa5b c745d400000000 mov    DWORD PTR [ebp-0x2c],0x0
0x56aa62 e910feffff jmp    0x56a877
0x56aa67 c745d000000000 mov    DWORD PTR [ebp-0x30],0x0
0x56aa6e e957feffff jmp    0x56a8ca
0x56aa73 d9ee fldz
0x56aa75 e990feffff jmp    0x56a90a
0x56aa7a d9ee fldz
0x56aa7c e9ccfeffff jmp    0x56a94d
0x56aa81 c745cc00000000 mov    DWORD PTR [ebp-0x34],0x0
0x56aa88 e916ffffff jmp    0x56a9a3
0x56aa8d 33c0 xor    eax,eax
0x56aa8f e95fffffff jmp    0x56a9f3

; F_00568E60 0x568e60..0x568eb6
0x568e60 55 push   ebp
0x568e61 8bec mov    ebp,esp
0x568e63 6aff push   0xffffffff
0x568e65 68c8839300 push   0x9383c8
0x568e6a 64a100000000 mov    eax,fs:0x0
0x568e70 50 push   eax
0x568e71 83ec0c sub    esp,0xc
0x568e74 a1201fd600 mov    eax,ds:0xd61f20
0x568e79 33c5 xor    eax,ebp
0x568e7b 50 push   eax
0x568e7c 8d45f4 lea    eax,[ebp-0xc]
0x568e7f 64a300000000 mov    fs:0x0,eax
0x568e85 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x568e88 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x568e8b 33c0 xor    eax,eax
0x568e8d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x568e90 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x568e93 8d4de8 lea    ecx,[ebp-0x18]
0x568e96 51 push   ecx
0x568e97 8945fc mov    DWORD PTR [ebp-0x4],eax
0x568e9a e8011c0000 call   0x56aaa0
0x568e9f 83c404 add    esp,0x4
0x568ea2 b801000000 mov    eax,0x1
0x568ea7 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x568eaa 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x568eb1 59 pop    ecx
0x568eb2 8be5 mov    esp,ebp
0x568eb4 5d pop    ebp
0x568eb5 c3 ret

; F_0056AAA0 0x56aaa0..0x56ac2a
0x56aaa0 55 push   ebp
0x56aaa1 8bec mov    ebp,esp
0x56aaa3 83ec34 sub    esp,0x34
0x56aaa6 a1a827fe00 mov    eax,ds:0xfe27a8
0x56aaab 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x56aab1 53 push   ebx
0x56aab2 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x56aab5 56 push   esi
0x56aab6 8945ec mov    DWORD PTR [ebp-0x14],eax
0x56aab9 894df0 mov    DWORD PTR [ebp-0x10],ecx
0x56aabc 8b0b mov    ecx,DWORD PTR [ebx]
0x56aabe 57 push   edi
0x56aabf 83c8ff or     eax,0xffffffff
0x56aac2 e829a61800 call   0x6f50f0
0x56aac7 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56aaca 83f903 cmp    ecx,0x3
0x56aacd 742e je     0x56aafd
0x56aacf 83f904 cmp    ecx,0x4
0x56aad2 0f8534010000 jne    0x56ac0c
0x56aad8 8b30 mov    esi,DWORD PTR [eax]
0x56aada 83c610 add    esi,0x10
0x56aadd 8d7ddc lea    edi,[ebp-0x24]
0x56aae0 e87bcc1800 call   0x6f7760
0x56aae5 85c0 test   eax,eax
0x56aae7 0f841f010000 je     0x56ac0c
0x56aaed dd45dc fld    QWORD PTR [ebp-0x24]
0x56aaf0 c745d403000000 mov    DWORD PTR [ebp-0x2c],0x3
0x56aaf7 dd5dcc fstp   QWORD PTR [ebp-0x34]
0x56aafa 8d45cc lea    eax,[ebp-0x34]
0x56aafd dd00 fld    QWORD PTR [eax]
0x56aaff dd5ddc fstp   QWORD PTR [ebp-0x24]
0x56ab02 dd45dc fld    QWORD PTR [ebp-0x24]
0x56ab05 db5d08 fistp  DWORD PTR [ebp+0x8]
0x56ab08 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x56ab0b 8955f4 mov    DWORD PTR [ebp-0xc],edx
0x56ab0e 8b03 mov    eax,DWORD PTR [ebx]
0x56ab10 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x56ab13 8b48e8 mov    ecx,DWORD PTR [eax-0x18]
0x56ab16 83e820 sub    eax,0x20
0x56ab19 83f903 cmp    ecx,0x3
0x56ab1c 742e je     0x56ab4c
0x56ab1e 83f904 cmp    ecx,0x4
0x56ab21 0f85f1000000 jne    0x56ac18
0x56ab27 8b30 mov    esi,DWORD PTR [eax]
0x56ab29 83c610 add    esi,0x10
0x56ab2c 8d7ddc lea    edi,[ebp-0x24]
0x56ab2f e82ccc1800 call   0x6f7760
0x56ab34 85c0 test   eax,eax
0x56ab36 0f84dc000000 je     0x56ac18
0x56ab3c dd45dc fld    QWORD PTR [ebp-0x24]
0x56ab3f c745d403000000 mov    DWORD PTR [ebp-0x2c],0x3
0x56ab46 dd5dcc fstp   QWORD PTR [ebp-0x34]
0x56ab49 8d45cc lea    eax,[ebp-0x34]
0x56ab4c dd00 fld    QWORD PTR [eax]
0x56ab4e 8b03 mov    eax,DWORD PTR [ebx]
0x56ab50 dd5de4 fstp   QWORD PTR [ebp-0x1c]
0x56ab53 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x56ab56 8b48d8 mov    ecx,DWORD PTR [eax-0x28]
0x56ab59 83e830 sub    eax,0x30
0x56ab5c 83f903 cmp    ecx,0x3
0x56ab5f 742e je     0x56ab8f
0x56ab61 83f904 cmp    ecx,0x4
0x56ab64 0f85b5000000 jne    0x56ac1f
0x56ab6a 8b30 mov    esi,DWORD PTR [eax]
0x56ab6c 83c610 add    esi,0x10
0x56ab6f 8d7ddc lea    edi,[ebp-0x24]
0x56ab72 e8e9cb1800 call   0x6f7760
0x56ab77 85c0 test   eax,eax
0x56ab79 0f84a0000000 je     0x56ac1f
0x56ab7f dd45dc fld    QWORD PTR [ebp-0x24]
0x56ab82 c745d403000000 mov    DWORD PTR [ebp-0x2c],0x3
0x56ab89 dd5dcc fstp   QWORD PTR [ebp-0x34]
0x56ab8c 8d45cc lea    eax,[ebp-0x34]
0x56ab8f dd00 fld    QWORD PTR [eax]
0x56ab91 8b0b mov    ecx,DWORD PTR [ebx]
0x56ab93 dd5ddc fstp   QWORD PTR [ebp-0x24]
0x56ab96 b8fcffffff mov    eax,0xfffffffc
0x56ab9b e850a51800 call   0x6f50f0
0x56aba0 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56aba3 83f903 cmp    ecx,0x3
0x56aba6 7426 je     0x56abce
0x56aba8 83f904 cmp    ecx,0x4
0x56abab 7579 jne    0x56ac26
0x56abad 8b30 mov    esi,DWORD PTR [eax]
0x56abaf 83c610 add    esi,0x10
0x56abb2 8d7df8 lea    edi,[ebp-0x8]
0x56abb5 e8a6cb1800 call   0x6f7760
0x56abba 85c0 test   eax,eax
0x56abbc 7468 je     0x56ac26
0x56abbe dd45f8 fld    QWORD PTR [ebp-0x8]
0x56abc1 c745d403000000 mov    DWORD PTR [ebp-0x2c],0x3
0x56abc8 dd5dcc fstp   QWORD PTR [ebp-0x34]
0x56abcb 8d45cc lea    eax,[ebp-0x34]
0x56abce dd00 fld    QWORD PTR [eax]
0x56abd0 dd5dd4 fstp   QWORD PTR [ebp-0x2c]
0x56abd3 dd45d4 fld    QWORD PTR [ebp-0x2c]
0x56abd6 db5dfc fistp  DWORD PTR [ebp-0x4]
0x56abd9 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x56abdc 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x56abdf dd45e4 fld    QWORD PTR [ebp-0x1c]
0x56abe2 d95df4 fstp   DWORD PTR [ebp-0xc]
0x56abe5 51 push   ecx
0x56abe6 d945f4 fld    DWORD PTR [ebp-0xc]
0x56abe9 8b4df0 mov    ecx,DWORD PTR [ebp-0x10]
0x56abec 83ec08 sub    esp,0x8
0x56abef d95c2404 fstp   DWORD PTR [esp+0x4]
0x56abf3 dd45dc fld    QWORD PTR [ebp-0x24]
0x56abf6 d95df4 fstp   DWORD PTR [ebp-0xc]
0x56abf9 d945f4 fld    DWORD PTR [ebp-0xc]
0x56abfc d91c24 fstp   DWORD PTR [esp]
0x56abff 50 push   eax
0x56ac00 ff55ec call   DWORD PTR [ebp-0x14]
0x56ac03 5f pop    edi
0x56ac04 5e pop    esi
0x56ac05 33c0 xor    eax,eax
0x56ac07 5b pop    ebx
0x56ac08 8be5 mov    esp,ebp
0x56ac0a 5d pop    ebp
0x56ac0b c3 ret
0x56ac0c c745f400000000 mov    DWORD PTR [ebp-0xc],0x0
0x56ac13 e9f6feffff jmp    0x56ab0e
0x56ac18 d9ee fldz
0x56ac1a e92fffffff jmp    0x56ab4e
0x56ac1f d9ee fldz
0x56ac21 e96bffffff jmp    0x56ab91
0x56ac26 33c0 xor    eax,eax
0x56ac28 ebb2 jmp    0x56abdc

; F_00568EC0 0x568ec0..0x568f1c
0x568ec0 55 push   ebp
0x568ec1 8bec mov    ebp,esp
0x568ec3 6aff push   0xffffffff
0x568ec5 68c8839300 push   0x9383c8
0x568eca 64a100000000 mov    eax,fs:0x0
0x568ed0 50 push   eax
0x568ed1 83ec0c sub    esp,0xc
0x568ed4 a1201fd600 mov    eax,ds:0xd61f20
0x568ed9 33c5 xor    eax,ebp
0x568edb 50 push   eax
0x568edc 8d45f4 lea    eax,[ebp-0xc]
0x568edf 64a300000000 mov    fs:0x0,eax
0x568ee5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x568ee8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x568eeb 33c0 xor    eax,eax
0x568eed 8945ec mov    DWORD PTR [ebp-0x14],eax
0x568ef0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x568ef3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x568ef6 8b0dac27fe00 mov    ecx,DWORD PTR ds:0xfe27ac
0x568efc 51 push   ecx
0x568efd 8d45e8 lea    eax,[ebp-0x18]
0x568f00 e82b150000 call   0x56a430
0x568f05 83c404 add    esp,0x4
0x568f08 b801000000 mov    eax,0x1
0x568f0d 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x568f10 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x568f17 59 pop    ecx
0x568f18 8be5 mov    esp,ebp
0x568f1a 5d pop    ebp
0x568f1b c3 ret

; F_00568F20 0x568f20..0x568f76
0x568f20 55 push   ebp
0x568f21 8bec mov    ebp,esp
0x568f23 6aff push   0xffffffff
0x568f25 68c8839300 push   0x9383c8
0x568f2a 64a100000000 mov    eax,fs:0x0
0x568f30 50 push   eax
0x568f31 83ec0c sub    esp,0xc
0x568f34 a1201fd600 mov    eax,ds:0xd61f20
0x568f39 33c5 xor    eax,ebp
0x568f3b 50 push   eax
0x568f3c 8d45f4 lea    eax,[ebp-0xc]
0x568f3f 64a300000000 mov    fs:0x0,eax
0x568f45 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x568f48 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x568f4b 33c0 xor    eax,eax
0x568f4d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x568f50 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x568f53 8945fc mov    DWORD PTR [ebp-0x4],eax
0x568f56 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x568f5c ff15b027fe00 call   DWORD PTR ds:0xfe27b0
0x568f62 b801000000 mov    eax,0x1
0x568f67 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x568f6a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x568f71 59 pop    ecx
0x568f72 8be5 mov    esp,ebp
0x568f74 5d pop    ebp
0x568f75 c3 ret

; F_00568F80 0x568f80..0x568fd6
0x568f80 55 push   ebp
0x568f81 8bec mov    ebp,esp
0x568f83 6aff push   0xffffffff
0x568f85 68c8839300 push   0x9383c8
0x568f8a 64a100000000 mov    eax,fs:0x0
0x568f90 50 push   eax
0x568f91 83ec0c sub    esp,0xc
0x568f94 a1201fd600 mov    eax,ds:0xd61f20
0x568f99 33c5 xor    eax,ebp
0x568f9b 50 push   eax
0x568f9c 8d45f4 lea    eax,[ebp-0xc]
0x568f9f 64a300000000 mov    fs:0x0,eax
0x568fa5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x568fa8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x568fab 33c0 xor    eax,eax
0x568fad 8945ec mov    DWORD PTR [ebp-0x14],eax
0x568fb0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x568fb3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x568fb6 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x568fbc ff15b427fe00 call   DWORD PTR ds:0xfe27b4
0x568fc2 b801000000 mov    eax,0x1
0x568fc7 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x568fca 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x568fd1 59 pop    ecx
0x568fd2 8be5 mov    esp,ebp
0x568fd4 5d pop    ebp
0x568fd5 c3 ret

; F_00568FE0 0x568fe0..0x569036
0x568fe0 55 push   ebp
0x568fe1 8bec mov    ebp,esp
0x568fe3 6aff push   0xffffffff
0x568fe5 68c8839300 push   0x9383c8
0x568fea 64a100000000 mov    eax,fs:0x0
0x568ff0 50 push   eax
0x568ff1 83ec0c sub    esp,0xc
0x568ff4 a1201fd600 mov    eax,ds:0xd61f20
0x568ff9 33c5 xor    eax,ebp
0x568ffb 50 push   eax
0x568ffc 8d45f4 lea    eax,[ebp-0xc]
0x568fff 64a300000000 mov    fs:0x0,eax
0x569005 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569008 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56900b 33c0 xor    eax,eax
0x56900d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569010 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569013 8d4de8 lea    ecx,[ebp-0x18]
0x569016 51 push   ecx
0x569017 8945fc mov    DWORD PTR [ebp-0x4],eax
0x56901a e871250000 call   0x56b590
0x56901f 83c404 add    esp,0x4
0x569022 b801000000 mov    eax,0x1
0x569027 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x56902a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569031 59 pop    ecx
0x569032 8be5 mov    esp,ebp
0x569034 5d pop    ebp
0x569035 c3 ret

; F_0056B590 0x56b590..0x56b622
0x56b590 55 push   ebp
0x56b591 8bec mov    ebp,esp
0x56b593 83ec18 sub    esp,0x18
0x56b596 a1b827fe00 mov    eax,ds:0xfe27b8
0x56b59b 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x56b5a1 53 push   ebx
0x56b5a2 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x56b5a5 8945f8 mov    DWORD PTR [ebp-0x8],eax
0x56b5a8 894dfc mov    DWORD PTR [ebp-0x4],ecx
0x56b5ab 8b0b mov    ecx,DWORD PTR [ebx]
0x56b5ad 83c8ff or     eax,0xffffffff
0x56b5b0 e83b9b1800 call   0x6f50f0
0x56b5b5 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56b5b8 83f903 cmp    ecx,0x3
0x56b5bb 742a je     0x56b5e7
0x56b5bd 83f904 cmp    ecx,0x4
0x56b5c0 755c jne    0x56b61e
0x56b5c2 56 push   esi
0x56b5c3 8b30 mov    esi,DWORD PTR [eax]
0x56b5c5 57 push   edi
0x56b5c6 83c610 add    esi,0x10
0x56b5c9 8d7df0 lea    edi,[ebp-0x10]
0x56b5cc e88fc11800 call   0x6f7760
0x56b5d1 5f pop    edi
0x56b5d2 5e pop    esi
0x56b5d3 85c0 test   eax,eax
0x56b5d5 7447 je     0x56b61e
0x56b5d7 dd45f0 fld    QWORD PTR [ebp-0x10]
0x56b5da c745f003000000 mov    DWORD PTR [ebp-0x10],0x3
0x56b5e1 dd5de8 fstp   QWORD PTR [ebp-0x18]
0x56b5e4 8d45e8 lea    eax,[ebp-0x18]
0x56b5e7 dd00 fld    QWORD PTR [eax]
0x56b5e9 dd5df0 fstp   QWORD PTR [ebp-0x10]
0x56b5ec dd45f0 fld    QWORD PTR [ebp-0x10]
0x56b5ef db5d08 fistp  DWORD PTR [ebp+0x8]
0x56b5f2 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x56b5f5 8b4dfc mov    ecx,DWORD PTR [ebp-0x4]
0x56b5f8 50 push   eax
0x56b5f9 ff55f8 call   DWORD PTR [ebp-0x8]
0x56b5fc d95df8 fstp   DWORD PTR [ebp-0x8]
0x56b5ff 8b03 mov    eax,DWORD PTR [ebx]
0x56b601 d945f8 fld    DWORD PTR [ebp-0x8]
0x56b604 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56b607 dd19 fstp   QWORD PTR [ecx]
0x56b609 c7410803000000 mov    DWORD PTR [ecx+0x8],0x3
0x56b610 83400810 add    DWORD PTR [eax+0x8],0x10
0x56b614 b801000000 mov    eax,0x1
0x56b619 5b pop    ebx
0x56b61a 8be5 mov    esp,ebp
0x56b61c 5d pop    ebp
0x56b61d c3 ret
0x56b61e 33c0 xor    eax,eax
0x56b620 ebd3 jmp    0x56b5f5

; F_00569040 0x569040..0x56909d
0x569040 55 push   ebp
0x569041 8bec mov    ebp,esp
0x569043 6aff push   0xffffffff
0x569045 68c8839300 push   0x9383c8
0x56904a 64a100000000 mov    eax,fs:0x0
0x569050 50 push   eax
0x569051 83ec0c sub    esp,0xc
0x569054 a1201fd600 mov    eax,ds:0xd61f20
0x569059 33c5 xor    eax,ebp
0x56905b 50 push   eax
0x56905c 8d45f4 lea    eax,[ebp-0xc]
0x56905f 64a300000000 mov    fs:0x0,eax
0x569065 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569068 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56906b 33c0 xor    eax,eax
0x56906d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569070 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569073 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569076 8b0dbc27fe00 mov    ecx,DWORD PTR ds:0xfe27bc
0x56907c 51 push   ecx
0x56907d 8d55e8 lea    edx,[ebp-0x18]
0x569080 52 push   edx
0x569081 e89a110000 call   0x56a220
0x569086 83c408 add    esp,0x8
0x569089 b801000000 mov    eax,0x1
0x56908e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569091 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569098 59 pop    ecx
0x569099 8be5 mov    esp,ebp
0x56909b 5d pop    ebp
0x56909c c3 ret

; F_005690A0 0x5690a0..0x5690fd
0x5690a0 55 push   ebp
0x5690a1 8bec mov    ebp,esp
0x5690a3 6aff push   0xffffffff
0x5690a5 68c8839300 push   0x9383c8
0x5690aa 64a100000000 mov    eax,fs:0x0
0x5690b0 50 push   eax
0x5690b1 83ec0c sub    esp,0xc
0x5690b4 a1201fd600 mov    eax,ds:0xd61f20
0x5690b9 33c5 xor    eax,ebp
0x5690bb 50 push   eax
0x5690bc 8d45f4 lea    eax,[ebp-0xc]
0x5690bf 64a300000000 mov    fs:0x0,eax
0x5690c5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x5690c8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x5690cb 33c0 xor    eax,eax
0x5690cd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x5690d0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x5690d3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x5690d6 8b0dc027fe00 mov    ecx,DWORD PTR ds:0xfe27c0
0x5690dc 51 push   ecx
0x5690dd 8d55e8 lea    edx,[ebp-0x18]
0x5690e0 52 push   edx
0x5690e1 e87a120000 call   0x56a360
0x5690e6 83c408 add    esp,0x8
0x5690e9 b801000000 mov    eax,0x1
0x5690ee 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x5690f1 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x5690f8 59 pop    ecx
0x5690f9 8be5 mov    esp,ebp
0x5690fb 5d pop    ebp
0x5690fc c3 ret

; F_00569100 0x569100..0x569156
0x569100 55 push   ebp
0x569101 8bec mov    ebp,esp
0x569103 6aff push   0xffffffff
0x569105 68c8839300 push   0x9383c8
0x56910a 64a100000000 mov    eax,fs:0x0
0x569110 50 push   eax
0x569111 83ec0c sub    esp,0xc
0x569114 a1201fd600 mov    eax,ds:0xd61f20
0x569119 33c5 xor    eax,ebp
0x56911b 50 push   eax
0x56911c 8d45f4 lea    eax,[ebp-0xc]
0x56911f 64a300000000 mov    fs:0x0,eax
0x569125 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569128 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56912b 33c0 xor    eax,eax
0x56912d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569130 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569133 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569136 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x56913c ff15c427fe00 call   DWORD PTR ds:0xfe27c4
0x569142 b801000000 mov    eax,0x1
0x569147 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x56914a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569151 59 pop    ecx
0x569152 8be5 mov    esp,ebp
0x569154 5d pop    ebp
0x569155 c3 ret

; F_00569160 0x569160..0x5691bc
0x569160 55 push   ebp
0x569161 8bec mov    ebp,esp
0x569163 6aff push   0xffffffff
0x569165 68c8839300 push   0x9383c8
0x56916a 64a100000000 mov    eax,fs:0x0
0x569170 50 push   eax
0x569171 83ec0c sub    esp,0xc
0x569174 a1201fd600 mov    eax,ds:0xd61f20
0x569179 33c5 xor    eax,ebp
0x56917b 50 push   eax
0x56917c 8d45f4 lea    eax,[ebp-0xc]
0x56917f 64a300000000 mov    fs:0x0,eax
0x569185 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569188 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56918b 33c0 xor    eax,eax
0x56918d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569190 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569193 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569196 8b0dc827fe00 mov    ecx,DWORD PTR ds:0xfe27c8
0x56919c 51 push   ecx
0x56919d 8d45e8 lea    eax,[ebp-0x18]
0x5691a0 e88b120000 call   0x56a430
0x5691a5 83c404 add    esp,0x4
0x5691a8 b801000000 mov    eax,0x1
0x5691ad 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x5691b0 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x5691b7 59 pop    ecx
0x5691b8 8be5 mov    esp,ebp
0x5691ba 5d pop    ebp
0x5691bb c3 ret

; F_005691C0 0x5691c0..0x56921c
0x5691c0 55 push   ebp
0x5691c1 8bec mov    ebp,esp
0x5691c3 6aff push   0xffffffff
0x5691c5 68c8839300 push   0x9383c8
0x5691ca 64a100000000 mov    eax,fs:0x0
0x5691d0 50 push   eax
0x5691d1 83ec0c sub    esp,0xc
0x5691d4 a1201fd600 mov    eax,ds:0xd61f20
0x5691d9 33c5 xor    eax,ebp
0x5691db 50 push   eax
0x5691dc 8d45f4 lea    eax,[ebp-0xc]
0x5691df 64a300000000 mov    fs:0x0,eax
0x5691e5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x5691e8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x5691eb 33c0 xor    eax,eax
0x5691ed 8945ec mov    DWORD PTR [ebp-0x14],eax
0x5691f0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x5691f3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x5691f6 8b0dcc27fe00 mov    ecx,DWORD PTR ds:0xfe27cc
0x5691fc 51 push   ecx
0x5691fd 8d45e8 lea    eax,[ebp-0x18]
0x569200 e82b120000 call   0x56a430
0x569205 83c404 add    esp,0x4
0x569208 b801000000 mov    eax,0x1
0x56920d 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569210 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569217 59 pop    ecx
0x569218 8be5 mov    esp,ebp
0x56921a 5d pop    ebp
0x56921b c3 ret

; F_00569220 0x569220..0x569276
0x569220 55 push   ebp
0x569221 8bec mov    ebp,esp
0x569223 6aff push   0xffffffff
0x569225 68c8839300 push   0x9383c8
0x56922a 64a100000000 mov    eax,fs:0x0
0x569230 50 push   eax
0x569231 83ec0c sub    esp,0xc
0x569234 a1201fd600 mov    eax,ds:0xd61f20
0x569239 33c5 xor    eax,ebp
0x56923b 50 push   eax
0x56923c 8d45f4 lea    eax,[ebp-0xc]
0x56923f 64a300000000 mov    fs:0x0,eax
0x569245 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569248 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56924b 33c0 xor    eax,eax
0x56924d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569250 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569253 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569256 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x56925c ff15d027fe00 call   DWORD PTR ds:0xfe27d0
0x569262 b801000000 mov    eax,0x1
0x569267 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x56926a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569271 59 pop    ecx
0x569272 8be5 mov    esp,ebp
0x569274 5d pop    ebp
0x569275 c3 ret

; F_00569280 0x569280..0x5692dd
0x569280 55 push   ebp
0x569281 8bec mov    ebp,esp
0x569283 6aff push   0xffffffff
0x569285 68c8839300 push   0x9383c8
0x56928a 64a100000000 mov    eax,fs:0x0
0x569290 50 push   eax
0x569291 83ec0c sub    esp,0xc
0x569294 a1201fd600 mov    eax,ds:0xd61f20
0x569299 33c5 xor    eax,ebp
0x56929b 50 push   eax
0x56929c 8d45f4 lea    eax,[ebp-0xc]
0x56929f 64a300000000 mov    fs:0x0,eax
0x5692a5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x5692a8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x5692ab 33c0 xor    eax,eax
0x5692ad 8945ec mov    DWORD PTR [ebp-0x14],eax
0x5692b0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x5692b3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x5692b6 8b0dd427fe00 mov    ecx,DWORD PTR ds:0xfe27d4
0x5692bc 51 push   ecx
0x5692bd 8d55e8 lea    edx,[ebp-0x18]
0x5692c0 52 push   edx
0x5692c1 e82a130000 call   0x56a5f0
0x5692c6 83c408 add    esp,0x8
0x5692c9 b801000000 mov    eax,0x1
0x5692ce 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x5692d1 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x5692d8 59 pop    ecx
0x5692d9 8be5 mov    esp,ebp
0x5692db 5d pop    ebp
0x5692dc c3 ret

; F_005692E0 0x5692e0..0x56933d
0x5692e0 55 push   ebp
0x5692e1 8bec mov    ebp,esp
0x5692e3 6aff push   0xffffffff
0x5692e5 68c8839300 push   0x9383c8
0x5692ea 64a100000000 mov    eax,fs:0x0
0x5692f0 50 push   eax
0x5692f1 83ec0c sub    esp,0xc
0x5692f4 a1201fd600 mov    eax,ds:0xd61f20
0x5692f9 33c5 xor    eax,ebp
0x5692fb 50 push   eax
0x5692fc 8d45f4 lea    eax,[ebp-0xc]
0x5692ff 64a300000000 mov    fs:0x0,eax
0x569305 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569308 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56930b 33c0 xor    eax,eax
0x56930d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569310 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569313 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569316 8b0dd827fe00 mov    ecx,DWORD PTR ds:0xfe27d8
0x56931c 51 push   ecx
0x56931d 8d55e8 lea    edx,[ebp-0x18]
0x569320 52 push   edx
0x569321 e8ca120000 call   0x56a5f0
0x569326 83c408 add    esp,0x8
0x569329 b801000000 mov    eax,0x1
0x56932e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569331 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569338 59 pop    ecx
0x569339 8be5 mov    esp,ebp
0x56933b 5d pop    ebp
0x56933c c3 ret

; F_00569340 0x569340..0x569396
0x569340 55 push   ebp
0x569341 8bec mov    ebp,esp
0x569343 6aff push   0xffffffff
0x569345 68c8839300 push   0x9383c8
0x56934a 64a100000000 mov    eax,fs:0x0
0x569350 50 push   eax
0x569351 83ec0c sub    esp,0xc
0x569354 a1201fd600 mov    eax,ds:0xd61f20
0x569359 33c5 xor    eax,ebp
0x56935b 50 push   eax
0x56935c 8d45f4 lea    eax,[ebp-0xc]
0x56935f 64a300000000 mov    fs:0x0,eax
0x569365 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569368 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56936b 33c0 xor    eax,eax
0x56936d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569370 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569373 8d4de8 lea    ecx,[ebp-0x18]
0x569376 51 push   ecx
0x569377 8945fc mov    DWORD PTR [ebp-0x4],eax
0x56937a e8b1180000 call   0x56ac30
0x56937f 83c404 add    esp,0x4
0x569382 b801000000 mov    eax,0x1
0x569387 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x56938a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569391 59 pop    ecx
0x569392 8be5 mov    esp,ebp
0x569394 5d pop    ebp
0x569395 c3 ret

; F_0056AC30 0x56ac30..0x56ae7e
0x56ac30 55 push   ebp
0x56ac31 8bec mov    ebp,esp
0x56ac33 83ec44 sub    esp,0x44
0x56ac36 a1dc27fe00 mov    eax,ds:0xfe27dc
0x56ac3b 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x56ac41 53 push   ebx
0x56ac42 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x56ac45 8945dc mov    DWORD PTR [ebp-0x24],eax
0x56ac48 8b03 mov    eax,DWORD PTR [ebx]
0x56ac4a 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x56ac4d 83e810 sub    eax,0x10
0x56ac50 894de0 mov    DWORD PTR [ebp-0x20],ecx
0x56ac53 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56ac56 56 push   esi
0x56ac57 57 push   edi
0x56ac58 83f903 cmp    ecx,0x3
0x56ac5b 742e je     0x56ac8b
0x56ac5d 83f904 cmp    ecx,0x4
0x56ac60 0f85e7010000 jne    0x56ae4d
0x56ac66 8b30 mov    esi,DWORD PTR [eax]
0x56ac68 83c610 add    esi,0x10
0x56ac6b 8d7dcc lea    edi,[ebp-0x34]
0x56ac6e e8edca1800 call   0x6f7760
0x56ac73 85c0 test   eax,eax
0x56ac75 0f84d2010000 je     0x56ae4d
0x56ac7b dd45cc fld    QWORD PTR [ebp-0x34]
0x56ac7e c745c403000000 mov    DWORD PTR [ebp-0x3c],0x3
0x56ac85 dd5dbc fstp   QWORD PTR [ebp-0x44]
0x56ac88 8d45bc lea    eax,[ebp-0x44]
0x56ac8b dd00 fld    QWORD PTR [eax]
0x56ac8d 8b0b mov    ecx,DWORD PTR [ebx]
0x56ac8f dd5de4 fstp   QWORD PTR [ebp-0x1c]
0x56ac92 b8feffffff mov    eax,0xfffffffe
0x56ac97 e854a41800 call   0x6f50f0
0x56ac9c 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56ac9f 83f903 cmp    ecx,0x3
0x56aca2 742e je     0x56acd2
0x56aca4 83f904 cmp    ecx,0x4
0x56aca7 0f85a7010000 jne    0x56ae54
0x56acad 8b30 mov    esi,DWORD PTR [eax]
0x56acaf 83c610 add    esi,0x10
0x56acb2 8d7dcc lea    edi,[ebp-0x34]
0x56acb5 e8a6ca1800 call   0x6f7760
0x56acba 85c0 test   eax,eax
0x56acbc 0f8492010000 je     0x56ae54
0x56acc2 dd45cc fld    QWORD PTR [ebp-0x34]
0x56acc5 c745c403000000 mov    DWORD PTR [ebp-0x3c],0x3
0x56accc dd5dbc fstp   QWORD PTR [ebp-0x44]
0x56accf 8d45bc lea    eax,[ebp-0x44]
0x56acd2 dd00 fld    QWORD PTR [eax]
0x56acd4 dd5dcc fstp   QWORD PTR [ebp-0x34]
0x56acd7 dd45cc fld    QWORD PTR [ebp-0x34]
0x56acda db5d08 fistp  DWORD PTR [ebp+0x8]
0x56acdd 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x56ace0 8955f0 mov    DWORD PTR [ebp-0x10],edx
0x56ace3 8b0b mov    ecx,DWORD PTR [ebx]
0x56ace5 b8fdffffff mov    eax,0xfffffffd
0x56acea e801a41800 call   0x6f50f0
0x56acef 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56acf2 83f903 cmp    ecx,0x3
0x56acf5 742e je     0x56ad25
0x56acf7 83f904 cmp    ecx,0x4
0x56acfa 0f8560010000 jne    0x56ae60
0x56ad00 8b30 mov    esi,DWORD PTR [eax]
0x56ad02 83c610 add    esi,0x10
0x56ad05 8d7dcc lea    edi,[ebp-0x34]
0x56ad08 e853ca1800 call   0x6f7760
0x56ad0d 85c0 test   eax,eax
0x56ad0f 0f844b010000 je     0x56ae60
0x56ad15 dd45cc fld    QWORD PTR [ebp-0x34]
0x56ad18 c745c403000000 mov    DWORD PTR [ebp-0x3c],0x3
0x56ad1f dd5dbc fstp   QWORD PTR [ebp-0x44]
0x56ad22 8d45bc lea    eax,[ebp-0x44]
0x56ad25 dd00 fld    QWORD PTR [eax]
0x56ad27 dd5dcc fstp   QWORD PTR [ebp-0x34]
0x56ad2a dd45cc fld    QWORD PTR [ebp-0x34]
0x56ad2d db5dfc fistp  DWORD PTR [ebp-0x4]
0x56ad30 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x56ad33 8945ec mov    DWORD PTR [ebp-0x14],eax
0x56ad36 8b03 mov    eax,DWORD PTR [ebx]
0x56ad38 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x56ad3b 8b48c8 mov    ecx,DWORD PTR [eax-0x38]
0x56ad3e 83e840 sub    eax,0x40
0x56ad41 83f903 cmp    ecx,0x3
0x56ad44 742e je     0x56ad74
0x56ad46 83f904 cmp    ecx,0x4
0x56ad49 0f851d010000 jne    0x56ae6c
0x56ad4f 8b30 mov    esi,DWORD PTR [eax]
0x56ad51 83c610 add    esi,0x10
0x56ad54 8d7dcc lea    edi,[ebp-0x34]
0x56ad57 e804ca1800 call   0x6f7760
0x56ad5c 85c0 test   eax,eax
0x56ad5e 0f8408010000 je     0x56ae6c
0x56ad64 dd45cc fld    QWORD PTR [ebp-0x34]
0x56ad67 c745c403000000 mov    DWORD PTR [ebp-0x3c],0x3
0x56ad6e dd5dbc fstp   QWORD PTR [ebp-0x44]
0x56ad71 8d45bc lea    eax,[ebp-0x44]
0x56ad74 dd00 fld    QWORD PTR [eax]
0x56ad76 8b03 mov    eax,DWORD PTR [ebx]
0x56ad78 dd5dd4 fstp   QWORD PTR [ebp-0x2c]
0x56ad7b 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x56ad7e 8b48b8 mov    ecx,DWORD PTR [eax-0x48]
0x56ad81 83e850 sub    eax,0x50
0x56ad84 83f903 cmp    ecx,0x3
0x56ad87 742e je     0x56adb7
0x56ad89 83f904 cmp    ecx,0x4
0x56ad8c 0f85e1000000 jne    0x56ae73
0x56ad92 8b30 mov    esi,DWORD PTR [eax]
0x56ad94 83c610 add    esi,0x10
0x56ad97 8d7dcc lea    edi,[ebp-0x34]
0x56ad9a e8c1c91800 call   0x6f7760
0x56ad9f 85c0 test   eax,eax
0x56ada1 0f84cc000000 je     0x56ae73
0x56ada7 dd45cc fld    QWORD PTR [ebp-0x34]
0x56adaa c745c403000000 mov    DWORD PTR [ebp-0x3c],0x3
0x56adb1 dd5dbc fstp   QWORD PTR [ebp-0x44]
0x56adb4 8d45bc lea    eax,[ebp-0x44]
0x56adb7 dd00 fld    QWORD PTR [eax]
0x56adb9 8b0b mov    ecx,DWORD PTR [ebx]
0x56adbb dd5dcc fstp   QWORD PTR [ebp-0x34]
0x56adbe b8faffffff mov    eax,0xfffffffa
0x56adc3 e828a31800 call   0x6f50f0
0x56adc8 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56adcb 83f903 cmp    ecx,0x3
0x56adce 742e je     0x56adfe
0x56add0 83f904 cmp    ecx,0x4
0x56add3 0f85a1000000 jne    0x56ae7a
0x56add9 8b30 mov    esi,DWORD PTR [eax]
0x56addb 83c610 add    esi,0x10
0x56adde 8d7df4 lea    edi,[ebp-0xc]
0x56ade1 e87ac91800 call   0x6f7760
0x56ade6 85c0 test   eax,eax
0x56ade8 0f848c000000 je     0x56ae7a
0x56adee dd45f4 fld    QWORD PTR [ebp-0xc]
0x56adf1 c745c403000000 mov    DWORD PTR [ebp-0x3c],0x3
0x56adf8 dd5dbc fstp   QWORD PTR [ebp-0x44]
0x56adfb 8d45bc lea    eax,[ebp-0x44]
0x56adfe dd00 fld    QWORD PTR [eax]
0x56ae00 dd5dc4 fstp   QWORD PTR [ebp-0x3c]
0x56ae03 dd45c4 fld    QWORD PTR [ebp-0x3c]
0x56ae06 db5df8 fistp  DWORD PTR [ebp-0x8]
0x56ae09 8b45f8 mov    eax,DWORD PTR [ebp-0x8]
0x56ae0c dd45e4 fld    QWORD PTR [ebp-0x1c]
0x56ae0f 8b55ec mov    edx,DWORD PTR [ebp-0x14]
0x56ae12 d95de8 fstp   DWORD PTR [ebp-0x18]
0x56ae15 51 push   ecx
0x56ae16 d945e8 fld    DWORD PTR [ebp-0x18]
0x56ae19 8b4df0 mov    ecx,DWORD PTR [ebp-0x10]
0x56ae1c d91c24 fstp   DWORD PTR [esp]
0x56ae1f 51 push   ecx
0x56ae20 dd45d4 fld    QWORD PTR [ebp-0x2c]
0x56ae23 8b4de0 mov    ecx,DWORD PTR [ebp-0x20]
0x56ae26 d95de8 fstp   DWORD PTR [ebp-0x18]
0x56ae29 52 push   edx
0x56ae2a d945e8 fld    DWORD PTR [ebp-0x18]
0x56ae2d 83ec08 sub    esp,0x8
0x56ae30 d95c2404 fstp   DWORD PTR [esp+0x4]
0x56ae34 dd45cc fld    QWORD PTR [ebp-0x34]
0x56ae37 d95de8 fstp   DWORD PTR [ebp-0x18]
0x56ae3a d945e8 fld    DWORD PTR [ebp-0x18]
0x56ae3d d91c24 fstp   DWORD PTR [esp]
0x56ae40 50 push   eax
0x56ae41 ff55dc call   DWORD PTR [ebp-0x24]
0x56ae44 5f pop    edi
0x56ae45 5e pop    esi
0x56ae46 33c0 xor    eax,eax
0x56ae48 5b pop    ebx
0x56ae49 8be5 mov    esp,ebp
0x56ae4b 5d pop    ebp
0x56ae4c c3 ret
0x56ae4d d9ee fldz
0x56ae4f e939feffff jmp    0x56ac8d
0x56ae54 c745f000000000 mov    DWORD PTR [ebp-0x10],0x0
0x56ae5b e983feffff jmp    0x56ace3
0x56ae60 c745ec00000000 mov    DWORD PTR [ebp-0x14],0x0
0x56ae67 e9cafeffff jmp    0x56ad36
0x56ae6c d9ee fldz
0x56ae6e e903ffffff jmp    0x56ad76
0x56ae73 d9ee fldz
0x56ae75 e93fffffff jmp    0x56adb9
0x56ae7a 33c0 xor    eax,eax
0x56ae7c eb8e jmp    0x56ae0c

; F_005693A0 0x5693a0..0x5693f6
0x5693a0 55 push   ebp
0x5693a1 8bec mov    ebp,esp
0x5693a3 6aff push   0xffffffff
0x5693a5 68c8839300 push   0x9383c8
0x5693aa 64a100000000 mov    eax,fs:0x0
0x5693b0 50 push   eax
0x5693b1 83ec0c sub    esp,0xc
0x5693b4 a1201fd600 mov    eax,ds:0xd61f20
0x5693b9 33c5 xor    eax,ebp
0x5693bb 50 push   eax
0x5693bc 8d45f4 lea    eax,[ebp-0xc]
0x5693bf 64a300000000 mov    fs:0x0,eax
0x5693c5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x5693c8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x5693cb 33c0 xor    eax,eax
0x5693cd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x5693d0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x5693d3 8d4de8 lea    ecx,[ebp-0x18]
0x5693d6 51 push   ecx
0x5693d7 8945fc mov    DWORD PTR [ebp-0x4],eax
0x5693da e8a11a0000 call   0x56ae80
0x5693df 83c404 add    esp,0x4
0x5693e2 b801000000 mov    eax,0x1
0x5693e7 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x5693ea 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x5693f1 59 pop    ecx
0x5693f2 8be5 mov    esp,ebp
0x5693f4 5d pop    ebp
0x5693f5 c3 ret

; F_0056AE80 0x56ae80..0x56b0d8
0x56ae80 55 push   ebp
0x56ae81 8bec mov    ebp,esp
0x56ae83 83ec44 sub    esp,0x44
0x56ae86 a1e027fe00 mov    eax,ds:0xfe27e0
0x56ae8b 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x56ae91 53 push   ebx
0x56ae92 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x56ae95 56 push   esi
0x56ae96 8945dc mov    DWORD PTR [ebp-0x24],eax
0x56ae99 894de0 mov    DWORD PTR [ebp-0x20],ecx
0x56ae9c 8b0b mov    ecx,DWORD PTR [ebx]
0x56ae9e 57 push   edi
0x56ae9f 83c8ff or     eax,0xffffffff
0x56aea2 e849a21800 call   0x6f50f0
0x56aea7 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56aeaa 83f903 cmp    ecx,0x3
0x56aead 742e je     0x56aedd
0x56aeaf 83f904 cmp    ecx,0x4
0x56aeb2 0f85ea010000 jne    0x56b0a2
0x56aeb8 8b30 mov    esi,DWORD PTR [eax]
0x56aeba 83c610 add    esi,0x10
0x56aebd 8d7dcc lea    edi,[ebp-0x34]
0x56aec0 e89bc81800 call   0x6f7760
0x56aec5 85c0 test   eax,eax
0x56aec7 0f84d5010000 je     0x56b0a2
0x56aecd dd45cc fld    QWORD PTR [ebp-0x34]
0x56aed0 c745c403000000 mov    DWORD PTR [ebp-0x3c],0x3
0x56aed7 dd5dbc fstp   QWORD PTR [ebp-0x44]
0x56aeda 8d45bc lea    eax,[ebp-0x44]
0x56aedd dd00 fld    QWORD PTR [eax]
0x56aedf dd5dcc fstp   QWORD PTR [ebp-0x34]
0x56aee2 dd45cc fld    QWORD PTR [ebp-0x34]
0x56aee5 db5d08 fistp  DWORD PTR [ebp+0x8]
0x56aee8 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x56aeeb 8955ec mov    DWORD PTR [ebp-0x14],edx
0x56aeee 8b0b mov    ecx,DWORD PTR [ebx]
0x56aef0 b8feffffff mov    eax,0xfffffffe
0x56aef5 e8f6a11800 call   0x6f50f0
0x56aefa 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56aefd 83f903 cmp    ecx,0x3
0x56af00 742e je     0x56af30
0x56af02 83f904 cmp    ecx,0x4
0x56af05 0f85a3010000 jne    0x56b0ae
0x56af0b 8b30 mov    esi,DWORD PTR [eax]
0x56af0d 83c610 add    esi,0x10
0x56af10 8d7dcc lea    edi,[ebp-0x34]
0x56af13 e848c81800 call   0x6f7760
0x56af18 85c0 test   eax,eax
0x56af1a 0f848e010000 je     0x56b0ae
0x56af20 dd45cc fld    QWORD PTR [ebp-0x34]
0x56af23 c745c403000000 mov    DWORD PTR [ebp-0x3c],0x3
0x56af2a dd5dbc fstp   QWORD PTR [ebp-0x44]
0x56af2d 8d45bc lea    eax,[ebp-0x44]
0x56af30 dd00 fld    QWORD PTR [eax]
0x56af32 dd5dcc fstp   QWORD PTR [ebp-0x34]
0x56af35 dd45cc fld    QWORD PTR [ebp-0x34]
0x56af38 db5dfc fistp  DWORD PTR [ebp-0x4]
0x56af3b 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x56af3e 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56af41 8b0b mov    ecx,DWORD PTR [ebx]
0x56af43 b8fdffffff mov    eax,0xfffffffd
0x56af48 e8a3a11800 call   0x6f50f0
0x56af4d 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56af50 83f903 cmp    ecx,0x3
0x56af53 742e je     0x56af83
0x56af55 83f904 cmp    ecx,0x4
0x56af58 0f855c010000 jne    0x56b0ba
0x56af5e 8b30 mov    esi,DWORD PTR [eax]
0x56af60 83c610 add    esi,0x10
0x56af63 8d7dcc lea    edi,[ebp-0x34]
0x56af66 e8f5c71800 call   0x6f7760
0x56af6b 85c0 test   eax,eax
0x56af6d 0f8447010000 je     0x56b0ba
0x56af73 dd45cc fld    QWORD PTR [ebp-0x34]
0x56af76 c745c403000000 mov    DWORD PTR [ebp-0x3c],0x3
0x56af7d dd5dbc fstp   QWORD PTR [ebp-0x44]
0x56af80 8d45bc lea    eax,[ebp-0x44]
0x56af83 dd00 fld    QWORD PTR [eax]
0x56af85 dd5dcc fstp   QWORD PTR [ebp-0x34]
0x56af88 dd45cc fld    QWORD PTR [ebp-0x34]
0x56af8b db5df8 fistp  DWORD PTR [ebp-0x8]
0x56af8e 8b4df8 mov    ecx,DWORD PTR [ebp-0x8]
0x56af91 894de4 mov    DWORD PTR [ebp-0x1c],ecx
0x56af94 8b03 mov    eax,DWORD PTR [ebx]
0x56af96 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x56af99 8b48c8 mov    ecx,DWORD PTR [eax-0x38]
0x56af9c 83e840 sub    eax,0x40
0x56af9f 83f903 cmp    ecx,0x3
0x56afa2 742e je     0x56afd2
0x56afa4 83f904 cmp    ecx,0x4
0x56afa7 0f8519010000 jne    0x56b0c6
0x56afad 8b30 mov    esi,DWORD PTR [eax]
0x56afaf 83c610 add    esi,0x10
0x56afb2 8d7dcc lea    edi,[ebp-0x34]
0x56afb5 e8a6c71800 call   0x6f7760
0x56afba 85c0 test   eax,eax
0x56afbc 0f8404010000 je     0x56b0c6
0x56afc2 dd45cc fld    QWORD PTR [ebp-0x34]
0x56afc5 c745c403000000 mov    DWORD PTR [ebp-0x3c],0x3
0x56afcc dd5dbc fstp   QWORD PTR [ebp-0x44]
0x56afcf 8d45bc lea    eax,[ebp-0x44]
0x56afd2 dd00 fld    QWORD PTR [eax]
0x56afd4 8b03 mov    eax,DWORD PTR [ebx]
0x56afd6 dd5dd4 fstp   QWORD PTR [ebp-0x2c]
0x56afd9 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x56afdc 8b48b8 mov    ecx,DWORD PTR [eax-0x48]
0x56afdf 83e850 sub    eax,0x50
0x56afe2 83f903 cmp    ecx,0x3
0x56afe5 742e je     0x56b015
0x56afe7 83f904 cmp    ecx,0x4
0x56afea 0f85dd000000 jne    0x56b0cd
0x56aff0 8b30 mov    esi,DWORD PTR [eax]
0x56aff2 83c610 add    esi,0x10
0x56aff5 8d7dcc lea    edi,[ebp-0x34]
0x56aff8 e863c71800 call   0x6f7760
0x56affd 85c0 test   eax,eax
0x56afff 0f84c8000000 je     0x56b0cd
0x56b005 dd45cc fld    QWORD PTR [ebp-0x34]
0x56b008 c745c403000000 mov    DWORD PTR [ebp-0x3c],0x3
0x56b00f dd5dbc fstp   QWORD PTR [ebp-0x44]
0x56b012 8d45bc lea    eax,[ebp-0x44]
0x56b015 dd00 fld    QWORD PTR [eax]
0x56b017 8b0b mov    ecx,DWORD PTR [ebx]
0x56b019 dd5dcc fstp   QWORD PTR [ebp-0x34]
0x56b01c b8faffffff mov    eax,0xfffffffa
0x56b021 e8caa01800 call   0x6f50f0
0x56b026 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56b029 83f903 cmp    ecx,0x3
0x56b02c 742e je     0x56b05c
0x56b02e 83f904 cmp    ecx,0x4
0x56b031 0f859d000000 jne    0x56b0d4
0x56b037 8b30 mov    esi,DWORD PTR [eax]
0x56b039 83c610 add    esi,0x10
0x56b03c 8d7df0 lea    edi,[ebp-0x10]
0x56b03f e81cc71800 call   0x6f7760
0x56b044 85c0 test   eax,eax
0x56b046 0f8488000000 je     0x56b0d4
0x56b04c dd45f0 fld    QWORD PTR [ebp-0x10]
0x56b04f c745c403000000 mov    DWORD PTR [ebp-0x3c],0x3
0x56b056 dd5dbc fstp   QWORD PTR [ebp-0x44]
0x56b059 8d45bc lea    eax,[ebp-0x44]
0x56b05c dd00 fld    QWORD PTR [eax]
0x56b05e dd5dc4 fstp   QWORD PTR [ebp-0x3c]
0x56b061 dd45c4 fld    QWORD PTR [ebp-0x3c]
0x56b064 db5df4 fistp  DWORD PTR [ebp-0xc]
0x56b067 8b45f4 mov    eax,DWORD PTR [ebp-0xc]
0x56b06a 8b55ec mov    edx,DWORD PTR [ebp-0x14]
0x56b06d dd45d4 fld    QWORD PTR [ebp-0x2c]
0x56b070 8b4de8 mov    ecx,DWORD PTR [ebp-0x18]
0x56b073 52 push   edx
0x56b074 8b55e4 mov    edx,DWORD PTR [ebp-0x1c]
0x56b077 d95de4 fstp   DWORD PTR [ebp-0x1c]
0x56b07a d945e4 fld    DWORD PTR [ebp-0x1c]
0x56b07d 51 push   ecx
0x56b07e 8b4de0 mov    ecx,DWORD PTR [ebp-0x20]
0x56b081 52 push   edx
0x56b082 83ec08 sub    esp,0x8
0x56b085 d95c2404 fstp   DWORD PTR [esp+0x4]
0x56b089 dd45cc fld    QWORD PTR [ebp-0x34]
0x56b08c d95de4 fstp   DWORD PTR [ebp-0x1c]
0x56b08f d945e4 fld    DWORD PTR [ebp-0x1c]
0x56b092 d91c24 fstp   DWORD PTR [esp]
0x56b095 50 push   eax
0x56b096 ff55dc call   DWORD PTR [ebp-0x24]
0x56b099 5f pop    edi
0x56b09a 5e pop    esi
0x56b09b 33c0 xor    eax,eax
0x56b09d 5b pop    ebx
0x56b09e 8be5 mov    esp,ebp
0x56b0a0 5d pop    ebp
0x56b0a1 c3 ret
0x56b0a2 c745ec00000000 mov    DWORD PTR [ebp-0x14],0x0
0x56b0a9 e940feffff jmp    0x56aeee
0x56b0ae c745e800000000 mov    DWORD PTR [ebp-0x18],0x0
0x56b0b5 e987feffff jmp    0x56af41
0x56b0ba c745e400000000 mov    DWORD PTR [ebp-0x1c],0x0
0x56b0c1 e9cefeffff jmp    0x56af94
0x56b0c6 d9ee fldz
0x56b0c8 e907ffffff jmp    0x56afd4
0x56b0cd d9ee fldz
0x56b0cf e943ffffff jmp    0x56b017
0x56b0d4 33c0 xor    eax,eax
0x56b0d6 eb92 jmp    0x56b06a

; F_00569400 0x569400..0x569456
0x569400 55 push   ebp
0x569401 8bec mov    ebp,esp
0x569403 6aff push   0xffffffff
0x569405 68c8839300 push   0x9383c8
0x56940a 64a100000000 mov    eax,fs:0x0
0x569410 50 push   eax
0x569411 83ec0c sub    esp,0xc
0x569414 a1201fd600 mov    eax,ds:0xd61f20
0x569419 33c5 xor    eax,ebp
0x56941b 50 push   eax
0x56941c 8d45f4 lea    eax,[ebp-0xc]
0x56941f 64a300000000 mov    fs:0x0,eax
0x569425 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569428 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56942b 33c0 xor    eax,eax
0x56942d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569430 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569433 8d4de8 lea    ecx,[ebp-0x18]
0x569436 51 push   ecx
0x569437 8945fc mov    DWORD PTR [ebp-0x4],eax
0x56943a e8a11c0000 call   0x56b0e0
0x56943f 83c404 add    esp,0x4
0x569442 b801000000 mov    eax,0x1
0x569447 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x56944a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569451 59 pop    ecx
0x569452 8be5 mov    esp,ebp
0x569454 5d pop    ebp
0x569455 c3 ret

; F_0056B0E0 0x56b0e0..0x56b210
0x56b0e0 55 push   ebp
0x56b0e1 8bec mov    ebp,esp
0x56b0e3 83ec30 sub    esp,0x30
0x56b0e6 a1e427fe00 mov    eax,ds:0xfe27e4
0x56b0eb 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x56b0f1 53 push   ebx
0x56b0f2 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x56b0f5 8945e0 mov    DWORD PTR [ebp-0x20],eax
0x56b0f8 8b03 mov    eax,DWORD PTR [ebx]
0x56b0fa 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x56b0fd 83e810 sub    eax,0x10
0x56b100 894de4 mov    DWORD PTR [ebp-0x1c],ecx
0x56b103 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56b106 56 push   esi
0x56b107 57 push   edi
0x56b108 83f903 cmp    ecx,0x3
0x56b10b 742e je     0x56b13b
0x56b10d 83f904 cmp    ecx,0x4
0x56b110 0f85e6000000 jne    0x56b1fc
0x56b116 8b30 mov    esi,DWORD PTR [eax]
0x56b118 83c610 add    esi,0x10
0x56b11b 8d7de8 lea    edi,[ebp-0x18]
0x56b11e e83dc61800 call   0x6f7760
0x56b123 85c0 test   eax,eax
0x56b125 0f84d1000000 je     0x56b1fc
0x56b12b dd45e8 fld    QWORD PTR [ebp-0x18]
0x56b12e c745d803000000 mov    DWORD PTR [ebp-0x28],0x3
0x56b135 dd5dd0 fstp   QWORD PTR [ebp-0x30]
0x56b138 8d45d0 lea    eax,[ebp-0x30]
0x56b13b dd00 fld    QWORD PTR [eax]
0x56b13d 8b0b mov    ecx,DWORD PTR [ebx]
0x56b13f dd5de8 fstp   QWORD PTR [ebp-0x18]
0x56b142 b8feffffff mov    eax,0xfffffffe
0x56b147 e8a49f1800 call   0x6f50f0
0x56b14c 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56b14f 83f903 cmp    ecx,0x3
0x56b152 742e je     0x56b182
0x56b154 83f904 cmp    ecx,0x4
0x56b157 0f85a6000000 jne    0x56b203
0x56b15d 8b30 mov    esi,DWORD PTR [eax]
0x56b15f 83c610 add    esi,0x10
0x56b162 8d7df0 lea    edi,[ebp-0x10]
0x56b165 e8f6c51800 call   0x6f7760
0x56b16a 85c0 test   eax,eax
0x56b16c 0f8491000000 je     0x56b203
0x56b172 dd45f0 fld    QWORD PTR [ebp-0x10]
0x56b175 c745d803000000 mov    DWORD PTR [ebp-0x28],0x3
0x56b17c dd5dd0 fstp   QWORD PTR [ebp-0x30]
0x56b17f 8d45d0 lea    eax,[ebp-0x30]
0x56b182 dd00 fld    QWORD PTR [eax]
0x56b184 dd5df0 fstp   QWORD PTR [ebp-0x10]
0x56b187 dd45f0 fld    QWORD PTR [ebp-0x10]
0x56b18a db5d08 fistp  DWORD PTR [ebp+0x8]
0x56b18d 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x56b190 8955f4 mov    DWORD PTR [ebp-0xc],edx
0x56b193 8b0b mov    ecx,DWORD PTR [ebx]
0x56b195 b8fdffffff mov    eax,0xfffffffd
0x56b19a e8519f1800 call   0x6f50f0
0x56b19f 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56b1a2 83f903 cmp    ecx,0x3
0x56b1a5 7426 je     0x56b1cd
0x56b1a7 83f904 cmp    ecx,0x4
0x56b1aa 7560 jne    0x56b20c
0x56b1ac 8b30 mov    esi,DWORD PTR [eax]
0x56b1ae 83c610 add    esi,0x10
0x56b1b1 8d7df8 lea    edi,[ebp-0x8]
0x56b1b4 e8a7c51800 call   0x6f7760
0x56b1b9 85c0 test   eax,eax
0x56b1bb 744f je     0x56b20c
0x56b1bd dd45f8 fld    QWORD PTR [ebp-0x8]
0x56b1c0 c745d803000000 mov    DWORD PTR [ebp-0x28],0x3
0x56b1c7 dd5dd0 fstp   QWORD PTR [ebp-0x30]
0x56b1ca 8d45d0 lea    eax,[ebp-0x30]
0x56b1cd dd00 fld    QWORD PTR [eax]
0x56b1cf dd5dd8 fstp   QWORD PTR [ebp-0x28]
0x56b1d2 dd45d8 fld    QWORD PTR [ebp-0x28]
0x56b1d5 db5dfc fistp  DWORD PTR [ebp-0x4]
0x56b1d8 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x56b1db dd45e8 fld    QWORD PTR [ebp-0x18]
0x56b1de 51 push   ecx
0x56b1df 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x56b1e2 d95dec fstp   DWORD PTR [ebp-0x14]
0x56b1e5 d945ec fld    DWORD PTR [ebp-0x14]
0x56b1e8 d91c24 fstp   DWORD PTR [esp]
0x56b1eb 51 push   ecx
0x56b1ec 8b4de4 mov    ecx,DWORD PTR [ebp-0x1c]
0x56b1ef 50 push   eax
0x56b1f0 ff55e0 call   DWORD PTR [ebp-0x20]
0x56b1f3 5f pop    edi
0x56b1f4 5e pop    esi
0x56b1f5 33c0 xor    eax,eax
0x56b1f7 5b pop    ebx
0x56b1f8 8be5 mov    esp,ebp
0x56b1fa 5d pop    ebp
0x56b1fb c3 ret
0x56b1fc d9ee fldz
0x56b1fe e93affffff jmp    0x56b13d
0x56b203 c745f400000000 mov    DWORD PTR [ebp-0xc],0x0
0x56b20a eb87 jmp    0x56b193
0x56b20c 33c0 xor    eax,eax
0x56b20e ebcb jmp    0x56b1db

; F_00569460 0x569460..0x5694bd
0x569460 55 push   ebp
0x569461 8bec mov    ebp,esp
0x569463 6aff push   0xffffffff
0x569465 68c8839300 push   0x9383c8
0x56946a 64a100000000 mov    eax,fs:0x0
0x569470 50 push   eax
0x569471 83ec0c sub    esp,0xc
0x569474 a1201fd600 mov    eax,ds:0xd61f20
0x569479 33c5 xor    eax,ebp
0x56947b 50 push   eax
0x56947c 8d45f4 lea    eax,[ebp-0xc]
0x56947f 64a300000000 mov    fs:0x0,eax
0x569485 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569488 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56948b 33c0 xor    eax,eax
0x56948d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569490 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569493 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569496 8b0de827fe00 mov    ecx,DWORD PTR ds:0xfe27e8
0x56949c 51 push   ecx
0x56949d 8d55e8 lea    edx,[ebp-0x18]
0x5694a0 52 push   edx
0x5694a1 e87a0d0000 call   0x56a220
0x5694a6 83c408 add    esp,0x8
0x5694a9 b801000000 mov    eax,0x1
0x5694ae 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x5694b1 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x5694b8 59 pop    ecx
0x5694b9 8be5 mov    esp,ebp
0x5694bb 5d pop    ebp
0x5694bc c3 ret

; F_005694C0 0x5694c0..0x56951d
0x5694c0 55 push   ebp
0x5694c1 8bec mov    ebp,esp
0x5694c3 6aff push   0xffffffff
0x5694c5 68c8839300 push   0x9383c8
0x5694ca 64a100000000 mov    eax,fs:0x0
0x5694d0 50 push   eax
0x5694d1 83ec0c sub    esp,0xc
0x5694d4 a1201fd600 mov    eax,ds:0xd61f20
0x5694d9 33c5 xor    eax,ebp
0x5694db 50 push   eax
0x5694dc 8d45f4 lea    eax,[ebp-0xc]
0x5694df 64a300000000 mov    fs:0x0,eax
0x5694e5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x5694e8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x5694eb 33c0 xor    eax,eax
0x5694ed 8945ec mov    DWORD PTR [ebp-0x14],eax
0x5694f0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x5694f3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x5694f6 8b0dec27fe00 mov    ecx,DWORD PTR ds:0xfe27ec
0x5694fc 51 push   ecx
0x5694fd 8d55e8 lea    edx,[ebp-0x18]
0x569500 52 push   edx
0x569501 e8aa0f0000 call   0x56a4b0
0x569506 83c408 add    esp,0x8
0x569509 b801000000 mov    eax,0x1
0x56950e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569511 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569518 59 pop    ecx
0x569519 8be5 mov    esp,ebp
0x56951b 5d pop    ebp
0x56951c c3 ret

; F_00569520 0x569520..0x569576
0x569520 55 push   ebp
0x569521 8bec mov    ebp,esp
0x569523 6aff push   0xffffffff
0x569525 68c8839300 push   0x9383c8
0x56952a 64a100000000 mov    eax,fs:0x0
0x569530 50 push   eax
0x569531 83ec0c sub    esp,0xc
0x569534 a1201fd600 mov    eax,ds:0xd61f20
0x569539 33c5 xor    eax,ebp
0x56953b 50 push   eax
0x56953c 8d45f4 lea    eax,[ebp-0xc]
0x56953f 64a300000000 mov    fs:0x0,eax
0x569545 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569548 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56954b 33c0 xor    eax,eax
0x56954d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569550 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569553 8d4de8 lea    ecx,[ebp-0x18]
0x569556 51 push   ecx
0x569557 8945fc mov    DWORD PTR [ebp-0x4],eax
0x56955a e8b11c0000 call   0x56b210
0x56955f 83c404 add    esp,0x4
0x569562 b801000000 mov    eax,0x1
0x569567 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x56956a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569571 59 pop    ecx
0x569572 8be5 mov    esp,ebp
0x569574 5d pop    ebp
0x569575 c3 ret

; F_0056B210 0x56b210..0x56b2d9
0x56b210 55 push   ebp
0x56b211 8bec mov    ebp,esp
0x56b213 83ec20 sub    esp,0x20
0x56b216 a1f027fe00 mov    eax,ds:0xfe27f0
0x56b21b 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x56b221 53 push   ebx
0x56b222 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x56b225 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x56b228 8b03 mov    eax,DWORD PTR [ebx]
0x56b22a 8b4008 mov    eax,DWORD PTR [eax+0x8]
0x56b22d 83e810 sub    eax,0x10
0x56b230 894df4 mov    DWORD PTR [ebp-0xc],ecx
0x56b233 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56b236 56 push   esi
0x56b237 57 push   edi
0x56b238 83f903 cmp    ecx,0x3
0x56b23b 742a je     0x56b267
0x56b23d 83f904 cmp    ecx,0x4
0x56b240 0f858b000000 jne    0x56b2d1
0x56b246 8b30 mov    esi,DWORD PTR [eax]
0x56b248 83c610 add    esi,0x10
0x56b24b 8d7df8 lea    edi,[ebp-0x8]
0x56b24e e80dc51800 call   0x6f7760
0x56b253 85c0 test   eax,eax
0x56b255 747a je     0x56b2d1
0x56b257 dd45f8 fld    QWORD PTR [ebp-0x8]
0x56b25a c745e803000000 mov    DWORD PTR [ebp-0x18],0x3
0x56b261 dd5de0 fstp   QWORD PTR [ebp-0x20]
0x56b264 8d45e0 lea    eax,[ebp-0x20]
0x56b267 dd00 fld    QWORD PTR [eax]
0x56b269 8b0b mov    ecx,DWORD PTR [ebx]
0x56b26b dd5df8 fstp   QWORD PTR [ebp-0x8]
0x56b26e b8feffffff mov    eax,0xfffffffe
0x56b273 e8789e1800 call   0x6f50f0
0x56b278 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56b27b 83f903 cmp    ecx,0x3
0x56b27e 7426 je     0x56b2a6
0x56b280 83f904 cmp    ecx,0x4
0x56b283 7550 jne    0x56b2d5
0x56b285 8b30 mov    esi,DWORD PTR [eax]
0x56b287 83c610 add    esi,0x10
0x56b28a 8d7de8 lea    edi,[ebp-0x18]
0x56b28d e8cec41800 call   0x6f7760
0x56b292 85c0 test   eax,eax
0x56b294 743f je     0x56b2d5
0x56b296 dd45e8 fld    QWORD PTR [ebp-0x18]
0x56b299 c745e803000000 mov    DWORD PTR [ebp-0x18],0x3
0x56b2a0 dd5de0 fstp   QWORD PTR [ebp-0x20]
0x56b2a3 8d45e0 lea    eax,[ebp-0x20]
0x56b2a6 dd00 fld    QWORD PTR [eax]
0x56b2a8 dd5de8 fstp   QWORD PTR [ebp-0x18]
0x56b2ab dd45e8 fld    QWORD PTR [ebp-0x18]
0x56b2ae db5d08 fistp  DWORD PTR [ebp+0x8]
0x56b2b1 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x56b2b4 dd45f8 fld    QWORD PTR [ebp-0x8]
0x56b2b7 51 push   ecx
0x56b2b8 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x56b2bb d95dfc fstp   DWORD PTR [ebp-0x4]
0x56b2be d945fc fld    DWORD PTR [ebp-0x4]
0x56b2c1 d91c24 fstp   DWORD PTR [esp]
0x56b2c4 50 push   eax
0x56b2c5 ff55f0 call   DWORD PTR [ebp-0x10]
0x56b2c8 5f pop    edi
0x56b2c9 5e pop    esi
0x56b2ca 33c0 xor    eax,eax
0x56b2cc 5b pop    ebx
0x56b2cd 8be5 mov    esp,ebp
0x56b2cf 5d pop    ebp
0x56b2d0 c3 ret
0x56b2d1 d9ee fldz
0x56b2d3 eb94 jmp    0x56b269
0x56b2d5 33c0 xor    eax,eax
0x56b2d7 ebdb jmp    0x56b2b4

; F_00569580 0x569580..0x5695dd
0x569580 55 push   ebp
0x569581 8bec mov    ebp,esp
0x569583 6aff push   0xffffffff
0x569585 68c8839300 push   0x9383c8
0x56958a 64a100000000 mov    eax,fs:0x0
0x569590 50 push   eax
0x569591 83ec0c sub    esp,0xc
0x569594 a1201fd600 mov    eax,ds:0xd61f20
0x569599 33c5 xor    eax,ebp
0x56959b 50 push   eax
0x56959c 8d45f4 lea    eax,[ebp-0xc]
0x56959f 64a300000000 mov    fs:0x0,eax
0x5695a5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x5695a8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x5695ab 33c0 xor    eax,eax
0x5695ad 8945ec mov    DWORD PTR [ebp-0x14],eax
0x5695b0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x5695b3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x5695b6 8b0df427fe00 mov    ecx,DWORD PTR ds:0xfe27f4
0x5695bc 51 push   ecx
0x5695bd 8d55e8 lea    edx,[ebp-0x18]
0x5695c0 52 push   edx
0x5695c1 e8ea0e0000 call   0x56a4b0
0x5695c6 83c408 add    esp,0x8
0x5695c9 b801000000 mov    eax,0x1
0x5695ce 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x5695d1 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x5695d8 59 pop    ecx
0x5695d9 8be5 mov    esp,ebp
0x5695db 5d pop    ebp
0x5695dc c3 ret

; F_005695E0 0x5695e0..0x56963c
0x5695e0 55 push   ebp
0x5695e1 8bec mov    ebp,esp
0x5695e3 6aff push   0xffffffff
0x5695e5 68c8839300 push   0x9383c8
0x5695ea 64a100000000 mov    eax,fs:0x0
0x5695f0 50 push   eax
0x5695f1 83ec0c sub    esp,0xc
0x5695f4 a1201fd600 mov    eax,ds:0xd61f20
0x5695f9 33c5 xor    eax,ebp
0x5695fb 50 push   eax
0x5695fc 8d45f4 lea    eax,[ebp-0xc]
0x5695ff 64a300000000 mov    fs:0x0,eax
0x569605 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569608 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56960b 33c0 xor    eax,eax
0x56960d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569610 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569613 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569616 8b0df827fe00 mov    ecx,DWORD PTR ds:0xfe27f8
0x56961c 51 push   ecx
0x56961d 8d45e8 lea    eax,[ebp-0x18]
0x569620 e80b0e0000 call   0x56a430
0x569625 83c404 add    esp,0x4
0x569628 b801000000 mov    eax,0x1
0x56962d 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569630 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569637 59 pop    ecx
0x569638 8be5 mov    esp,ebp
0x56963a 5d pop    ebp
0x56963b c3 ret

; F_00569640 0x569640..0x56969d
0x569640 55 push   ebp
0x569641 8bec mov    ebp,esp
0x569643 6aff push   0xffffffff
0x569645 68c8839300 push   0x9383c8
0x56964a 64a100000000 mov    eax,fs:0x0
0x569650 50 push   eax
0x569651 83ec0c sub    esp,0xc
0x569654 a1201fd600 mov    eax,ds:0xd61f20
0x569659 33c5 xor    eax,ebp
0x56965b 50 push   eax
0x56965c 8d45f4 lea    eax,[ebp-0xc]
0x56965f 64a300000000 mov    fs:0x0,eax
0x569665 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569668 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56966b 33c0 xor    eax,eax
0x56966d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569670 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569673 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569676 8b0dfc27fe00 mov    ecx,DWORD PTR ds:0xfe27fc
0x56967c 51 push   ecx
0x56967d 8d55e8 lea    edx,[ebp-0x18]
0x569680 52 push   edx
0x569681 e89a0b0000 call   0x56a220
0x569686 83c408 add    esp,0x8
0x569689 b801000000 mov    eax,0x1
0x56968e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569691 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569698 59 pop    ecx
0x569699 8be5 mov    esp,ebp
0x56969b 5d pop    ebp
0x56969c c3 ret

; F_005696A0 0x5696a0..0x5696fd
0x5696a0 55 push   ebp
0x5696a1 8bec mov    ebp,esp
0x5696a3 6aff push   0xffffffff
0x5696a5 68c8839300 push   0x9383c8
0x5696aa 64a100000000 mov    eax,fs:0x0
0x5696b0 50 push   eax
0x5696b1 83ec0c sub    esp,0xc
0x5696b4 a1201fd600 mov    eax,ds:0xd61f20
0x5696b9 33c5 xor    eax,ebp
0x5696bb 50 push   eax
0x5696bc 8d45f4 lea    eax,[ebp-0xc]
0x5696bf 64a300000000 mov    fs:0x0,eax
0x5696c5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x5696c8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x5696cb 33c0 xor    eax,eax
0x5696cd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x5696d0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x5696d3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x5696d6 8b0d0028fe00 mov    ecx,DWORD PTR ds:0xfe2800
0x5696dc 51 push   ecx
0x5696dd 8d55e8 lea    edx,[ebp-0x18]
0x5696e0 52 push   edx
0x5696e1 e8ca0d0000 call   0x56a4b0
0x5696e6 83c408 add    esp,0x8
0x5696e9 b801000000 mov    eax,0x1
0x5696ee 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x5696f1 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x5696f8 59 pop    ecx
0x5696f9 8be5 mov    esp,ebp
0x5696fb 5d pop    ebp
0x5696fc c3 ret

; F_00569700 0x569700..0x569756
0x569700 55 push   ebp
0x569701 8bec mov    ebp,esp
0x569703 6aff push   0xffffffff
0x569705 68c8839300 push   0x9383c8
0x56970a 64a100000000 mov    eax,fs:0x0
0x569710 50 push   eax
0x569711 83ec0c sub    esp,0xc
0x569714 a1201fd600 mov    eax,ds:0xd61f20
0x569719 33c5 xor    eax,ebp
0x56971b 50 push   eax
0x56971c 8d45f4 lea    eax,[ebp-0xc]
0x56971f 64a300000000 mov    fs:0x0,eax
0x569725 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569728 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56972b 33c0 xor    eax,eax
0x56972d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569730 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569733 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569736 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x56973c ff150428fe00 call   DWORD PTR ds:0xfe2804
0x569742 b801000000 mov    eax,0x1
0x569747 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x56974a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569751 59 pop    ecx
0x569752 8be5 mov    esp,ebp
0x569754 5d pop    ebp
0x569755 c3 ret

; F_00569760 0x569760..0x5697bc
0x569760 55 push   ebp
0x569761 8bec mov    ebp,esp
0x569763 6aff push   0xffffffff
0x569765 68c8839300 push   0x9383c8
0x56976a 64a100000000 mov    eax,fs:0x0
0x569770 50 push   eax
0x569771 83ec0c sub    esp,0xc
0x569774 a1201fd600 mov    eax,ds:0xd61f20
0x569779 33c5 xor    eax,ebp
0x56977b 50 push   eax
0x56977c 8d45f4 lea    eax,[ebp-0xc]
0x56977f 64a300000000 mov    fs:0x0,eax
0x569785 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569788 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56978b 33c0 xor    eax,eax
0x56978d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569790 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569793 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569796 8b0d0828fe00 mov    ecx,DWORD PTR ds:0xfe2808
0x56979c 51 push   ecx
0x56979d 8d45e8 lea    eax,[ebp-0x18]
0x5697a0 e85b0b0000 call   0x56a300
0x5697a5 83c404 add    esp,0x4
0x5697a8 b801000000 mov    eax,0x1
0x5697ad 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x5697b0 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x5697b7 59 pop    ecx
0x5697b8 8be5 mov    esp,ebp
0x5697ba 5d pop    ebp
0x5697bb c3 ret

; F_005697C0 0x5697c0..0x569816
0x5697c0 55 push   ebp
0x5697c1 8bec mov    ebp,esp
0x5697c3 6aff push   0xffffffff
0x5697c5 68c8839300 push   0x9383c8
0x5697ca 64a100000000 mov    eax,fs:0x0
0x5697d0 50 push   eax
0x5697d1 83ec0c sub    esp,0xc
0x5697d4 a1201fd600 mov    eax,ds:0xd61f20
0x5697d9 33c5 xor    eax,ebp
0x5697db 50 push   eax
0x5697dc 8d45f4 lea    eax,[ebp-0xc]
0x5697df 64a300000000 mov    fs:0x0,eax
0x5697e5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x5697e8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x5697eb 33c0 xor    eax,eax
0x5697ed 8945ec mov    DWORD PTR [ebp-0x14],eax
0x5697f0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x5697f3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x5697f6 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x5697fc ff150c28fe00 call   DWORD PTR ds:0xfe280c
0x569802 b801000000 mov    eax,0x1
0x569807 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x56980a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569811 59 pop    ecx
0x569812 8be5 mov    esp,ebp
0x569814 5d pop    ebp
0x569815 c3 ret

; F_00569820 0x569820..0x569876
0x569820 55 push   ebp
0x569821 8bec mov    ebp,esp
0x569823 6aff push   0xffffffff
0x569825 68c8839300 push   0x9383c8
0x56982a 64a100000000 mov    eax,fs:0x0
0x569830 50 push   eax
0x569831 83ec0c sub    esp,0xc
0x569834 a1201fd600 mov    eax,ds:0xd61f20
0x569839 33c5 xor    eax,ebp
0x56983b 50 push   eax
0x56983c 8d45f4 lea    eax,[ebp-0xc]
0x56983f 64a300000000 mov    fs:0x0,eax
0x569845 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569848 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56984b 33c0 xor    eax,eax
0x56984d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569850 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569853 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569856 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x56985c ff151028fe00 call   DWORD PTR ds:0xfe2810
0x569862 b801000000 mov    eax,0x1
0x569867 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x56986a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569871 59 pop    ecx
0x569872 8be5 mov    esp,ebp
0x569874 5d pop    ebp
0x569875 c3 ret

; F_00569880 0x569880..0x5698d6
0x569880 55 push   ebp
0x569881 8bec mov    ebp,esp
0x569883 6aff push   0xffffffff
0x569885 68c8839300 push   0x9383c8
0x56988a 64a100000000 mov    eax,fs:0x0
0x569890 50 push   eax
0x569891 83ec0c sub    esp,0xc
0x569894 a1201fd600 mov    eax,ds:0xd61f20
0x569899 33c5 xor    eax,ebp
0x56989b 50 push   eax
0x56989c 8d45f4 lea    eax,[ebp-0xc]
0x56989f 64a300000000 mov    fs:0x0,eax
0x5698a5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x5698a8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x5698ab 33c0 xor    eax,eax
0x5698ad 8945ec mov    DWORD PTR [ebp-0x14],eax
0x5698b0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x5698b3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x5698b6 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x5698bc ff151428fe00 call   DWORD PTR ds:0xfe2814
0x5698c2 b801000000 mov    eax,0x1
0x5698c7 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x5698ca 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x5698d1 59 pop    ecx
0x5698d2 8be5 mov    esp,ebp
0x5698d4 5d pop    ebp
0x5698d5 c3 ret

; F_005698E0 0x5698e0..0x56994e
0x5698e0 55 push   ebp
0x5698e1 8bec mov    ebp,esp
0x5698e3 6aff push   0xffffffff
0x5698e5 68d8879300 push   0x9387d8
0x5698ea 64a100000000 mov    eax,fs:0x0
0x5698f0 50 push   eax
0x5698f1 83ec0c sub    esp,0xc
0x5698f4 56 push   esi
0x5698f5 a1201fd600 mov    eax,ds:0xd61f20
0x5698fa 33c5 xor    eax,ebp
0x5698fc 50 push   eax
0x5698fd 8d45f4 lea    eax,[ebp-0xc]
0x569900 64a300000000 mov    fs:0x0,eax
0x569906 8b7508 mov    esi,DWORD PTR [ebp+0x8]
0x569909 33c0 xor    eax,eax
0x56990b 8975e8 mov    DWORD PTR [ebp-0x18],esi
0x56990e 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569911 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569914 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569917 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x56991d ff151828fe00 call   DWORD PTR ds:0xfe2818
0x569923 894508 mov    DWORD PTR [ebp+0x8],eax
0x569926 8b4608 mov    eax,DWORD PTR [esi+0x8]
0x569929 db4508 fild   DWORD PTR [ebp+0x8]
0x56992c c7400803000000 mov    DWORD PTR [eax+0x8],0x3
0x569933 dd18 fstp   QWORD PTR [eax]
0x569935 83460810 add    DWORD PTR [esi+0x8],0x10
0x569939 b801000000 mov    eax,0x1
0x56993e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569941 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569948 59 pop    ecx
0x569949 5e pop    esi
0x56994a 8be5 mov    esp,ebp
0x56994c 5d pop    ebp
0x56994d c3 ret

; F_00569950 0x569950..0x5699a6
0x569950 55 push   ebp
0x569951 8bec mov    ebp,esp
0x569953 6aff push   0xffffffff
0x569955 68c8839300 push   0x9383c8
0x56995a 64a100000000 mov    eax,fs:0x0
0x569960 50 push   eax
0x569961 83ec0c sub    esp,0xc
0x569964 a1201fd600 mov    eax,ds:0xd61f20
0x569969 33c5 xor    eax,ebp
0x56996b 50 push   eax
0x56996c 8d45f4 lea    eax,[ebp-0xc]
0x56996f 64a300000000 mov    fs:0x0,eax
0x569975 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569978 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56997b 33c0 xor    eax,eax
0x56997d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569980 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569983 8d4de8 lea    ecx,[ebp-0x18]
0x569986 51 push   ecx
0x569987 8945fc mov    DWORD PTR [ebp-0x4],eax
0x56998a e851190000 call   0x56b2e0
0x56998f 83c404 add    esp,0x4
0x569992 b801000000 mov    eax,0x1
0x569997 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x56999a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x5699a1 59 pop    ecx
0x5699a2 8be5 mov    esp,ebp
0x5699a4 5d pop    ebp
0x5699a5 c3 ret

; F_0056B2E0 0x56b2e0..0x56b58e
0x56b2e0 55 push   ebp
0x56b2e1 8bec mov    ebp,esp
0x56b2e3 83ec40 sub    esp,0x40
0x56b2e6 a11c28fe00 mov    eax,ds:0xfe281c
0x56b2eb 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x56b2f1 53 push   ebx
0x56b2f2 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x56b2f5 56 push   esi
0x56b2f6 8945c0 mov    DWORD PTR [ebp-0x40],eax
0x56b2f9 894dc4 mov    DWORD PTR [ebp-0x3c],ecx
0x56b2fc 8b0b mov    ecx,DWORD PTR [ebx]
0x56b2fe 57 push   edi
0x56b2ff 83c8ff or     eax,0xffffffff
0x56b302 e8e99d1800 call   0x6f50f0
0x56b307 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56b30a 83f903 cmp    ecx,0x3
0x56b30d 742e je     0x56b33d
0x56b30f 83f904 cmp    ecx,0x4
0x56b312 0f85ec010000 jne    0x56b504
0x56b318 8b30 mov    esi,DWORD PTR [eax]
0x56b31a 83c610 add    esi,0x10
0x56b31d 8d7dd0 lea    edi,[ebp-0x30]
0x56b320 e83bc41800 call   0x6f7760
0x56b325 85c0 test   eax,eax
0x56b327 0f84d7010000 je     0x56b504
0x56b32d dd45d0 fld    QWORD PTR [ebp-0x30]
0x56b330 c745d003000000 mov    DWORD PTR [ebp-0x30],0x3
0x56b337 dd5dc8 fstp   QWORD PTR [ebp-0x38]
0x56b33a 8d45c8 lea    eax,[ebp-0x38]
0x56b33d dd00 fld    QWORD PTR [eax]
0x56b33f dd5dd0 fstp   QWORD PTR [ebp-0x30]
0x56b342 dd45d0 fld    QWORD PTR [ebp-0x30]
0x56b345 db5d08 fistp  DWORD PTR [ebp+0x8]
0x56b348 8b5508 mov    edx,DWORD PTR [ebp+0x8]
0x56b34b 8955e8 mov    DWORD PTR [ebp-0x18],edx
0x56b34e 8b0b mov    ecx,DWORD PTR [ebx]
0x56b350 b8feffffff mov    eax,0xfffffffe
0x56b355 e8969d1800 call   0x6f50f0
0x56b35a 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56b35d 83f903 cmp    ecx,0x3
0x56b360 742e je     0x56b390
0x56b362 83f904 cmp    ecx,0x4
0x56b365 0f85a5010000 jne    0x56b510
0x56b36b 8b30 mov    esi,DWORD PTR [eax]
0x56b36d 83c610 add    esi,0x10
0x56b370 8d7dd0 lea    edi,[ebp-0x30]
0x56b373 e8e8c31800 call   0x6f7760
0x56b378 85c0 test   eax,eax
0x56b37a 0f8490010000 je     0x56b510
0x56b380 dd45d0 fld    QWORD PTR [ebp-0x30]
0x56b383 c745d003000000 mov    DWORD PTR [ebp-0x30],0x3
0x56b38a dd5dc8 fstp   QWORD PTR [ebp-0x38]
0x56b38d 8d45c8 lea    eax,[ebp-0x38]
0x56b390 dd00 fld    QWORD PTR [eax]
0x56b392 dd5dd0 fstp   QWORD PTR [ebp-0x30]
0x56b395 dd45d0 fld    QWORD PTR [ebp-0x30]
0x56b398 db5dfc fistp  DWORD PTR [ebp-0x4]
0x56b39b 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x56b39e 8945e4 mov    DWORD PTR [ebp-0x1c],eax
0x56b3a1 8b0b mov    ecx,DWORD PTR [ebx]
0x56b3a3 b8fdffffff mov    eax,0xfffffffd
0x56b3a8 e8439d1800 call   0x6f50f0
0x56b3ad 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56b3b0 83f903 cmp    ecx,0x3
0x56b3b3 742e je     0x56b3e3
0x56b3b5 83f904 cmp    ecx,0x4
0x56b3b8 0f855e010000 jne    0x56b51c
0x56b3be 8b30 mov    esi,DWORD PTR [eax]
0x56b3c0 83c610 add    esi,0x10
0x56b3c3 8d7dd0 lea    edi,[ebp-0x30]
0x56b3c6 e895c31800 call   0x6f7760
0x56b3cb 85c0 test   eax,eax
0x56b3cd 0f8449010000 je     0x56b51c
0x56b3d3 dd45d0 fld    QWORD PTR [ebp-0x30]
0x56b3d6 c745d003000000 mov    DWORD PTR [ebp-0x30],0x3
0x56b3dd dd5dc8 fstp   QWORD PTR [ebp-0x38]
0x56b3e0 8d45c8 lea    eax,[ebp-0x38]
0x56b3e3 dd00 fld    QWORD PTR [eax]
0x56b3e5 dd5dd0 fstp   QWORD PTR [ebp-0x30]
0x56b3e8 dd45d0 fld    QWORD PTR [ebp-0x30]
0x56b3eb db5df8 fistp  DWORD PTR [ebp-0x8]
0x56b3ee 8b4df8 mov    ecx,DWORD PTR [ebp-0x8]
0x56b3f1 894de0 mov    DWORD PTR [ebp-0x20],ecx
0x56b3f4 8b0b mov    ecx,DWORD PTR [ebx]
0x56b3f6 b8fcffffff mov    eax,0xfffffffc
0x56b3fb e8f09c1800 call   0x6f50f0
0x56b400 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56b403 83f903 cmp    ecx,0x3
0x56b406 742e je     0x56b436
0x56b408 83f904 cmp    ecx,0x4
0x56b40b 0f8517010000 jne    0x56b528
0x56b411 8b30 mov    esi,DWORD PTR [eax]
0x56b413 83c610 add    esi,0x10
0x56b416 8d7dd0 lea    edi,[ebp-0x30]
0x56b419 e842c31800 call   0x6f7760
0x56b41e 85c0 test   eax,eax
0x56b420 0f8402010000 je     0x56b528
0x56b426 dd45d0 fld    QWORD PTR [ebp-0x30]
0x56b429 c745d003000000 mov    DWORD PTR [ebp-0x30],0x3
0x56b430 dd5dc8 fstp   QWORD PTR [ebp-0x38]
0x56b433 8d45c8 lea    eax,[ebp-0x38]
0x56b436 dd00 fld    QWORD PTR [eax]
0x56b438 dd5dd0 fstp   QWORD PTR [ebp-0x30]
0x56b43b dd45d0 fld    QWORD PTR [ebp-0x30]
0x56b43e db5df4 fistp  DWORD PTR [ebp-0xc]
0x56b441 8b55f4 mov    edx,DWORD PTR [ebp-0xc]
0x56b444 8955dc mov    DWORD PTR [ebp-0x24],edx
0x56b447 8b0b mov    ecx,DWORD PTR [ebx]
0x56b449 b8fbffffff mov    eax,0xfffffffb
0x56b44e e89d9c1800 call   0x6f50f0
0x56b453 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56b456 83f903 cmp    ecx,0x3
0x56b459 742e je     0x56b489
0x56b45b 83f904 cmp    ecx,0x4
0x56b45e 0f85d0000000 jne    0x56b534
0x56b464 8b30 mov    esi,DWORD PTR [eax]
0x56b466 83c610 add    esi,0x10
0x56b469 8d7dd0 lea    edi,[ebp-0x30]
0x56b46c e8efc21800 call   0x6f7760
0x56b471 85c0 test   eax,eax
0x56b473 0f84bb000000 je     0x56b534
0x56b479 dd45d0 fld    QWORD PTR [ebp-0x30]
0x56b47c c745d003000000 mov    DWORD PTR [ebp-0x30],0x3
0x56b483 dd5dc8 fstp   QWORD PTR [ebp-0x38]
0x56b486 8d45c8 lea    eax,[ebp-0x38]
0x56b489 dd00 fld    QWORD PTR [eax]
0x56b48b dd5dd0 fstp   QWORD PTR [ebp-0x30]
0x56b48e dd45d0 fld    QWORD PTR [ebp-0x30]
0x56b491 db5df0 fistp  DWORD PTR [ebp-0x10]
0x56b494 8b45f0 mov    eax,DWORD PTR [ebp-0x10]
0x56b497 8945d8 mov    DWORD PTR [ebp-0x28],eax
0x56b49a 8b0b mov    ecx,DWORD PTR [ebx]
0x56b49c b8faffffff mov    eax,0xfffffffa
0x56b4a1 e84a9c1800 call   0x6f50f0
0x56b4a6 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56b4a9 83f903 cmp    ecx,0x3
0x56b4ac 742a je     0x56b4d8
0x56b4ae 83f904 cmp    ecx,0x4
0x56b4b1 0f8589000000 jne    0x56b540
0x56b4b7 8b30 mov    esi,DWORD PTR [eax]
0x56b4b9 83c610 add    esi,0x10
0x56b4bc 8d7dd0 lea    edi,[ebp-0x30]
0x56b4bf e89cc21800 call   0x6f7760
0x56b4c4 85c0 test   eax,eax
0x56b4c6 7478 je     0x56b540
0x56b4c8 dd45d0 fld    QWORD PTR [ebp-0x30]
0x56b4cb c745d003000000 mov    DWORD PTR [ebp-0x30],0x3
0x56b4d2 dd5dc8 fstp   QWORD PTR [ebp-0x38]
0x56b4d5 8d45c8 lea    eax,[ebp-0x38]
0x56b4d8 dd00 fld    QWORD PTR [eax]
0x56b4da dd5dd0 fstp   QWORD PTR [ebp-0x30]
0x56b4dd dd45d0 fld    QWORD PTR [ebp-0x30]
0x56b4e0 db5dec fistp  DWORD PTR [ebp-0x14]
0x56b4e3 8b4dec mov    ecx,DWORD PTR [ebp-0x14]
0x56b4e6 894dd4 mov    DWORD PTR [ebp-0x2c],ecx
0x56b4e9 8b3b mov    edi,DWORD PTR [ebx]
0x56b4eb 8b7708 mov    esi,DWORD PTR [edi+0x8]
0x56b4ee 83ee70 sub    esi,0x70
0x56b4f1 837e0804 cmp    DWORD PTR [esi+0x8],0x4
0x56b4f5 746a je     0x56b561
0x56b4f7 e8d4001900 call   0x6fb5d0
0x56b4fc 85c0 test   eax,eax
0x56b4fe 7549 jne    0x56b549
0x56b500 33f6 xor    esi,esi
0x56b502 eb62 jmp    0x56b566
0x56b504 c745e800000000 mov    DWORD PTR [ebp-0x18],0x0
0x56b50b e93efeffff jmp    0x56b34e
0x56b510 c745e400000000 mov    DWORD PTR [ebp-0x1c],0x0
0x56b517 e985feffff jmp    0x56b3a1
0x56b51c c745e000000000 mov    DWORD PTR [ebp-0x20],0x0
0x56b523 e9ccfeffff jmp    0x56b3f4
0x56b528 c745dc00000000 mov    DWORD PTR [ebp-0x24],0x0
0x56b52f e913ffffff jmp    0x56b447
0x56b534 c745d800000000 mov    DWORD PTR [ebp-0x28],0x0
0x56b53b e95affffff jmp    0x56b49a
0x56b540 c745d400000000 mov    DWORD PTR [ebp-0x2c],0x0
0x56b547 eba0 jmp    0x56b4e9
0x56b549 8b4710 mov    eax,DWORD PTR [edi+0x10]
0x56b54c 8b5044 mov    edx,DWORD PTR [eax+0x44]
0x56b54f 3b5040 cmp    edx,DWORD PTR [eax+0x40]
0x56b552 7207 jb     0x56b55b
0x56b554 8bc7 mov    eax,edi
0x56b556 e845fe1800 call   0x6fb3a0
0x56b55b 8b7708 mov    esi,DWORD PTR [edi+0x8]
0x56b55e 83ee70 sub    esi,0x70
0x56b561 8b36 mov    esi,DWORD PTR [esi]
0x56b563 83c610 add    esi,0x10
0x56b566 8b45e8 mov    eax,DWORD PTR [ebp-0x18]
0x56b569 8b4de4 mov    ecx,DWORD PTR [ebp-0x1c]
0x56b56c 8b55e0 mov    edx,DWORD PTR [ebp-0x20]
0x56b56f 50 push   eax
0x56b570 8b45dc mov    eax,DWORD PTR [ebp-0x24]
0x56b573 51 push   ecx
0x56b574 8b4dd8 mov    ecx,DWORD PTR [ebp-0x28]
0x56b577 52 push   edx
0x56b578 8b55d4 mov    edx,DWORD PTR [ebp-0x2c]
0x56b57b 50 push   eax
0x56b57c 51 push   ecx
0x56b57d 8b4dc4 mov    ecx,DWORD PTR [ebp-0x3c]
0x56b580 52 push   edx
0x56b581 56 push   esi
0x56b582 ff55c0 call   DWORD PTR [ebp-0x40]
0x56b585 5f pop    edi
0x56b586 5e pop    esi
0x56b587 33c0 xor    eax,eax
0x56b589 5b pop    ebx
0x56b58a 8be5 mov    esp,ebp
0x56b58c 5d pop    ebp
0x56b58d c3 ret

; F_005699B0 0x5699b0..0x569a06
0x5699b0 55 push   ebp
0x5699b1 8bec mov    ebp,esp
0x5699b3 6aff push   0xffffffff
0x5699b5 68c8839300 push   0x9383c8
0x5699ba 64a100000000 mov    eax,fs:0x0
0x5699c0 50 push   eax
0x5699c1 83ec0c sub    esp,0xc
0x5699c4 a1201fd600 mov    eax,ds:0xd61f20
0x5699c9 33c5 xor    eax,ebp
0x5699cb 50 push   eax
0x5699cc 8d45f4 lea    eax,[ebp-0xc]
0x5699cf 64a300000000 mov    fs:0x0,eax
0x5699d5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x5699d8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x5699db 33c0 xor    eax,eax
0x5699dd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x5699e0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x5699e3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x5699e6 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x5699ec ff152028fe00 call   DWORD PTR ds:0xfe2820
0x5699f2 b801000000 mov    eax,0x1
0x5699f7 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x5699fa 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569a01 59 pop    ecx
0x569a02 8be5 mov    esp,ebp
0x569a04 5d pop    ebp
0x569a05 c3 ret

; F_00569A10 0x569a10..0x569a66
0x569a10 55 push   ebp
0x569a11 8bec mov    ebp,esp
0x569a13 6aff push   0xffffffff
0x569a15 68c8839300 push   0x9383c8
0x569a1a 64a100000000 mov    eax,fs:0x0
0x569a20 50 push   eax
0x569a21 83ec0c sub    esp,0xc
0x569a24 a1201fd600 mov    eax,ds:0xd61f20
0x569a29 33c5 xor    eax,ebp
0x569a2b 50 push   eax
0x569a2c 8d45f4 lea    eax,[ebp-0xc]
0x569a2f 64a300000000 mov    fs:0x0,eax
0x569a35 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569a38 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x569a3b 33c0 xor    eax,eax
0x569a3d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569a40 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569a43 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569a46 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x569a4c ff152428fe00 call   DWORD PTR ds:0xfe2824
0x569a52 b801000000 mov    eax,0x1
0x569a57 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569a5a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569a61 59 pop    ecx
0x569a62 8be5 mov    esp,ebp
0x569a64 5d pop    ebp
0x569a65 c3 ret

; F_00569A70 0x569a70..0x569ac6
0x569a70 55 push   ebp
0x569a71 8bec mov    ebp,esp
0x569a73 6aff push   0xffffffff
0x569a75 68c8839300 push   0x9383c8
0x569a7a 64a100000000 mov    eax,fs:0x0
0x569a80 50 push   eax
0x569a81 83ec0c sub    esp,0xc
0x569a84 a1201fd600 mov    eax,ds:0xd61f20
0x569a89 33c5 xor    eax,ebp
0x569a8b 50 push   eax
0x569a8c 8d45f4 lea    eax,[ebp-0xc]
0x569a8f 64a300000000 mov    fs:0x0,eax
0x569a95 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569a98 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x569a9b 33c0 xor    eax,eax
0x569a9d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569aa0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569aa3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569aa6 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x569aac ff152828fe00 call   DWORD PTR ds:0xfe2828
0x569ab2 b801000000 mov    eax,0x1
0x569ab7 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569aba 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569ac1 59 pop    ecx
0x569ac2 8be5 mov    esp,ebp
0x569ac4 5d pop    ebp
0x569ac5 c3 ret

; F_00569AD0 0x569ad0..0x569b2c
0x569ad0 55 push   ebp
0x569ad1 8bec mov    ebp,esp
0x569ad3 6aff push   0xffffffff
0x569ad5 68c8839300 push   0x9383c8
0x569ada 64a100000000 mov    eax,fs:0x0
0x569ae0 50 push   eax
0x569ae1 83ec0c sub    esp,0xc
0x569ae4 a1201fd600 mov    eax,ds:0xd61f20
0x569ae9 33c5 xor    eax,ebp
0x569aeb 50 push   eax
0x569aec 8d45f4 lea    eax,[ebp-0xc]
0x569aef 64a300000000 mov    fs:0x0,eax
0x569af5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569af8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x569afb 33c0 xor    eax,eax
0x569afd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569b00 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569b03 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569b06 8b0d2c28fe00 mov    ecx,DWORD PTR ds:0xfe282c
0x569b0c 51 push   ecx
0x569b0d 8d45e8 lea    eax,[ebp-0x18]
0x569b10 e81b090000 call   0x56a430
0x569b15 83c404 add    esp,0x4
0x569b18 b801000000 mov    eax,0x1
0x569b1d 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569b20 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569b27 59 pop    ecx
0x569b28 8be5 mov    esp,ebp
0x569b2a 5d pop    ebp
0x569b2b c3 ret

; F_00569B30 0x569b30..0x569b9e
0x569b30 55 push   ebp
0x569b31 8bec mov    ebp,esp
0x569b33 6aff push   0xffffffff
0x569b35 68d8879300 push   0x9387d8
0x569b3a 64a100000000 mov    eax,fs:0x0
0x569b40 50 push   eax
0x569b41 83ec0c sub    esp,0xc
0x569b44 56 push   esi
0x569b45 a1201fd600 mov    eax,ds:0xd61f20
0x569b4a 33c5 xor    eax,ebp
0x569b4c 50 push   eax
0x569b4d 8d45f4 lea    eax,[ebp-0xc]
0x569b50 64a300000000 mov    fs:0x0,eax
0x569b56 8b7508 mov    esi,DWORD PTR [ebp+0x8]
0x569b59 33c0 xor    eax,eax
0x569b5b 8975e8 mov    DWORD PTR [ebp-0x18],esi
0x569b5e 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569b61 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569b64 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569b67 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x569b6d ff153028fe00 call   DWORD PTR ds:0xfe2830
0x569b73 894508 mov    DWORD PTR [ebp+0x8],eax
0x569b76 8b4608 mov    eax,DWORD PTR [esi+0x8]
0x569b79 db4508 fild   DWORD PTR [ebp+0x8]
0x569b7c c7400803000000 mov    DWORD PTR [eax+0x8],0x3
0x569b83 dd18 fstp   QWORD PTR [eax]
0x569b85 83460810 add    DWORD PTR [esi+0x8],0x10
0x569b89 b801000000 mov    eax,0x1
0x569b8e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569b91 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569b98 59 pop    ecx
0x569b99 5e pop    esi
0x569b9a 8be5 mov    esp,ebp
0x569b9c 5d pop    ebp
0x569b9d c3 ret

; F_00569BA0 0x569ba0..0x569bfc
0x569ba0 55 push   ebp
0x569ba1 8bec mov    ebp,esp
0x569ba3 6aff push   0xffffffff
0x569ba5 68c8839300 push   0x9383c8
0x569baa 64a100000000 mov    eax,fs:0x0
0x569bb0 50 push   eax
0x569bb1 83ec0c sub    esp,0xc
0x569bb4 a1201fd600 mov    eax,ds:0xd61f20
0x569bb9 33c5 xor    eax,ebp
0x569bbb 50 push   eax
0x569bbc 8d45f4 lea    eax,[ebp-0xc]
0x569bbf 64a300000000 mov    fs:0x0,eax
0x569bc5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569bc8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x569bcb 33c0 xor    eax,eax
0x569bcd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569bd0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569bd3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569bd6 8b0d3428fe00 mov    ecx,DWORD PTR ds:0xfe2834
0x569bdc 51 push   ecx
0x569bdd 8d45e8 lea    eax,[ebp-0x18]
0x569be0 e81b070000 call   0x56a300
0x569be5 83c404 add    esp,0x4
0x569be8 b801000000 mov    eax,0x1
0x569bed 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569bf0 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569bf7 59 pop    ecx
0x569bf8 8be5 mov    esp,ebp
0x569bfa 5d pop    ebp
0x569bfb c3 ret

; F_00569C00 0x569c00..0x569c5c
0x569c00 55 push   ebp
0x569c01 8bec mov    ebp,esp
0x569c03 6aff push   0xffffffff
0x569c05 68c8839300 push   0x9383c8
0x569c0a 64a100000000 mov    eax,fs:0x0
0x569c10 50 push   eax
0x569c11 83ec0c sub    esp,0xc
0x569c14 a1201fd600 mov    eax,ds:0xd61f20
0x569c19 33c5 xor    eax,ebp
0x569c1b 50 push   eax
0x569c1c 8d45f4 lea    eax,[ebp-0xc]
0x569c1f 64a300000000 mov    fs:0x0,eax
0x569c25 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569c28 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x569c2b 33c0 xor    eax,eax
0x569c2d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569c30 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569c33 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569c36 8b0d3828fe00 mov    ecx,DWORD PTR ds:0xfe2838
0x569c3c 51 push   ecx
0x569c3d 8d45e8 lea    eax,[ebp-0x18]
0x569c40 e8bb060000 call   0x56a300
0x569c45 83c404 add    esp,0x4
0x569c48 b801000000 mov    eax,0x1
0x569c4d 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569c50 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569c57 59 pop    ecx
0x569c58 8be5 mov    esp,ebp
0x569c5a 5d pop    ebp
0x569c5b c3 ret

; F_00569C60 0x569c60..0x569cbc
0x569c60 55 push   ebp
0x569c61 8bec mov    ebp,esp
0x569c63 6aff push   0xffffffff
0x569c65 68c8839300 push   0x9383c8
0x569c6a 64a100000000 mov    eax,fs:0x0
0x569c70 50 push   eax
0x569c71 83ec0c sub    esp,0xc
0x569c74 a1201fd600 mov    eax,ds:0xd61f20
0x569c79 33c5 xor    eax,ebp
0x569c7b 50 push   eax
0x569c7c 8d45f4 lea    eax,[ebp-0xc]
0x569c7f 64a300000000 mov    fs:0x0,eax
0x569c85 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569c88 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x569c8b 33c0 xor    eax,eax
0x569c8d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569c90 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569c93 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569c96 8b0d3c28fe00 mov    ecx,DWORD PTR ds:0xfe283c
0x569c9c 51 push   ecx
0x569c9d 8d45e8 lea    eax,[ebp-0x18]
0x569ca0 e88b070000 call   0x56a430
0x569ca5 83c404 add    esp,0x4
0x569ca8 b801000000 mov    eax,0x1
0x569cad 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569cb0 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569cb7 59 pop    ecx
0x569cb8 8be5 mov    esp,ebp
0x569cba 5d pop    ebp
0x569cbb c3 ret

; F_00569CC0 0x569cc0..0x569d1c
0x569cc0 55 push   ebp
0x569cc1 8bec mov    ebp,esp
0x569cc3 6aff push   0xffffffff
0x569cc5 68c8839300 push   0x9383c8
0x569cca 64a100000000 mov    eax,fs:0x0
0x569cd0 50 push   eax
0x569cd1 83ec0c sub    esp,0xc
0x569cd4 a1201fd600 mov    eax,ds:0xd61f20
0x569cd9 33c5 xor    eax,ebp
0x569cdb 50 push   eax
0x569cdc 8d45f4 lea    eax,[ebp-0xc]
0x569cdf 64a300000000 mov    fs:0x0,eax
0x569ce5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569ce8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x569ceb 33c0 xor    eax,eax
0x569ced 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569cf0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569cf3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569cf6 8b0d4028fe00 mov    ecx,DWORD PTR ds:0xfe2840
0x569cfc 51 push   ecx
0x569cfd 8d45e8 lea    eax,[ebp-0x18]
0x569d00 e82b070000 call   0x56a430
0x569d05 83c404 add    esp,0x4
0x569d08 b801000000 mov    eax,0x1
0x569d0d 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569d10 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569d17 59 pop    ecx
0x569d18 8be5 mov    esp,ebp
0x569d1a 5d pop    ebp
0x569d1b c3 ret

; F_00569D20 0x569d20..0x569d87
0x569d20 55 push   ebp
0x569d21 8bec mov    ebp,esp
0x569d23 6aff push   0xffffffff
0x569d25 6838869300 push   0x938638
0x569d2a 64a100000000 mov    eax,fs:0x0
0x569d30 50 push   eax
0x569d31 83ec0c sub    esp,0xc
0x569d34 56 push   esi
0x569d35 57 push   edi
0x569d36 a1201fd600 mov    eax,ds:0xd61f20
0x569d3b 33c5 xor    eax,ebp
0x569d3d 50 push   eax
0x569d3e 8d45f4 lea    eax,[ebp-0xc]
0x569d41 64a300000000 mov    fs:0x0,eax
0x569d47 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569d4a 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x569d4d 33c0 xor    eax,eax
0x569d4f 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569d52 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569d55 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569d58 8b354428fe00 mov    esi,DWORD PTR ds:0xfe2844
0x569d5e 8b3d7827fe00 mov    edi,DWORD PTR ds:0xfe2778
0x569d64 8d45e8 lea    eax,[ebp-0x18]
0x569d67 e8c4180000 call   0x56b630
0x569d6c 50 push   eax
0x569d6d 8bcf mov    ecx,edi
0x569d6f ffd6 call   esi
0x569d71 b801000000 mov    eax,0x1
0x569d76 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569d79 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569d80 59 pop    ecx
0x569d81 5f pop    edi
0x569d82 5e pop    esi
0x569d83 8be5 mov    esp,ebp
0x569d85 5d pop    ebp
0x569d86 c3 ret

; F_0056B630 0x56b630..0x56b68a
0x56b630 55 push   ebp
0x56b631 8bec mov    ebp,esp
0x56b633 8b08 mov    ecx,DWORD PTR [eax]
0x56b635 83ec18 sub    esp,0x18
0x56b638 83c8ff or     eax,0xffffffff
0x56b63b e8b09a1800 call   0x6f50f0
0x56b640 8b4808 mov    ecx,DWORD PTR [eax+0x8]
0x56b643 83f903 cmp    ecx,0x3
0x56b646 742a je     0x56b672
0x56b648 83f904 cmp    ecx,0x4
0x56b64b 7537 jne    0x56b684
0x56b64d 56 push   esi
0x56b64e 8b30 mov    esi,DWORD PTR [eax]
0x56b650 57 push   edi
0x56b651 83c610 add    esi,0x10
0x56b654 8d7df8 lea    edi,[ebp-0x8]
0x56b657 e804c11800 call   0x6f7760
0x56b65c 5f pop    edi
0x56b65d 5e pop    esi
0x56b65e 85c0 test   eax,eax
0x56b660 7422 je     0x56b684
0x56b662 dd45f8 fld    QWORD PTR [ebp-0x8]
0x56b665 c745f003000000 mov    DWORD PTR [ebp-0x10],0x3
0x56b66c dd5de8 fstp   QWORD PTR [ebp-0x18]
0x56b66f 8d45e8 lea    eax,[ebp-0x18]
0x56b672 dd00 fld    QWORD PTR [eax]
0x56b674 dd5df0 fstp   QWORD PTR [ebp-0x10]
0x56b677 dd45f0 fld    QWORD PTR [ebp-0x10]
0x56b67a db5dfc fistp  DWORD PTR [ebp-0x4]
0x56b67d 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x56b680 8be5 mov    esp,ebp
0x56b682 5d pop    ebp
0x56b683 c3 ret
0x56b684 33c0 xor    eax,eax
0x56b686 8be5 mov    esp,ebp
0x56b688 5d pop    ebp
0x56b689 c3 ret

; F_00569D90 0x569d90..0x569dec
0x569d90 55 push   ebp
0x569d91 8bec mov    ebp,esp
0x569d93 6aff push   0xffffffff
0x569d95 68c8839300 push   0x9383c8
0x569d9a 64a100000000 mov    eax,fs:0x0
0x569da0 50 push   eax
0x569da1 83ec0c sub    esp,0xc
0x569da4 a1201fd600 mov    eax,ds:0xd61f20
0x569da9 33c5 xor    eax,ebp
0x569dab 50 push   eax
0x569dac 8d45f4 lea    eax,[ebp-0xc]
0x569daf 64a300000000 mov    fs:0x0,eax
0x569db5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569db8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x569dbb 33c0 xor    eax,eax
0x569dbd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569dc0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569dc3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569dc6 8b0d4828fe00 mov    ecx,DWORD PTR ds:0xfe2848
0x569dcc 51 push   ecx
0x569dcd 8d45e8 lea    eax,[ebp-0x18]
0x569dd0 e85b060000 call   0x56a430
0x569dd5 83c404 add    esp,0x4
0x569dd8 b801000000 mov    eax,0x1
0x569ddd 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569de0 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569de7 59 pop    ecx
0x569de8 8be5 mov    esp,ebp
0x569dea 5d pop    ebp
0x569deb c3 ret

; F_00569DF0 0x569df0..0x569e4c
0x569df0 55 push   ebp
0x569df1 8bec mov    ebp,esp
0x569df3 6aff push   0xffffffff
0x569df5 68c8839300 push   0x9383c8
0x569dfa 64a100000000 mov    eax,fs:0x0
0x569e00 50 push   eax
0x569e01 83ec0c sub    esp,0xc
0x569e04 a1201fd600 mov    eax,ds:0xd61f20
0x569e09 33c5 xor    eax,ebp
0x569e0b 50 push   eax
0x569e0c 8d45f4 lea    eax,[ebp-0xc]
0x569e0f 64a300000000 mov    fs:0x0,eax
0x569e15 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569e18 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x569e1b 33c0 xor    eax,eax
0x569e1d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569e20 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569e23 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569e26 8b0d4c28fe00 mov    ecx,DWORD PTR ds:0xfe284c
0x569e2c 51 push   ecx
0x569e2d 8d45e8 lea    eax,[ebp-0x18]
0x569e30 e8fb050000 call   0x56a430
0x569e35 83c404 add    esp,0x4
0x569e38 b801000000 mov    eax,0x1
0x569e3d 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569e40 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569e47 59 pop    ecx
0x569e48 8be5 mov    esp,ebp
0x569e4a 5d pop    ebp
0x569e4b c3 ret

; F_00569E50 0x569e50..0x569ebe
0x569e50 55 push   ebp
0x569e51 8bec mov    ebp,esp
0x569e53 6aff push   0xffffffff
0x569e55 68d8879300 push   0x9387d8
0x569e5a 64a100000000 mov    eax,fs:0x0
0x569e60 50 push   eax
0x569e61 83ec0c sub    esp,0xc
0x569e64 56 push   esi
0x569e65 a1201fd600 mov    eax,ds:0xd61f20
0x569e6a 33c5 xor    eax,ebp
0x569e6c 50 push   eax
0x569e6d 8d45f4 lea    eax,[ebp-0xc]
0x569e70 64a300000000 mov    fs:0x0,eax
0x569e76 8b7508 mov    esi,DWORD PTR [ebp+0x8]
0x569e79 33c0 xor    eax,eax
0x569e7b 8975e8 mov    DWORD PTR [ebp-0x18],esi
0x569e7e 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569e81 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569e84 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569e87 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x569e8d ff155028fe00 call   DWORD PTR ds:0xfe2850
0x569e93 894508 mov    DWORD PTR [ebp+0x8],eax
0x569e96 8b4608 mov    eax,DWORD PTR [esi+0x8]
0x569e99 db4508 fild   DWORD PTR [ebp+0x8]
0x569e9c c7400803000000 mov    DWORD PTR [eax+0x8],0x3
0x569ea3 dd18 fstp   QWORD PTR [eax]
0x569ea5 83460810 add    DWORD PTR [esi+0x8],0x10
0x569ea9 b801000000 mov    eax,0x1
0x569eae 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569eb1 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569eb8 59 pop    ecx
0x569eb9 5e pop    esi
0x569eba 8be5 mov    esp,ebp
0x569ebc 5d pop    ebp
0x569ebd c3 ret

; F_00569EC0 0x569ec0..0x569f1d
0x569ec0 55 push   ebp
0x569ec1 8bec mov    ebp,esp
0x569ec3 6aff push   0xffffffff
0x569ec5 68c8839300 push   0x9383c8
0x569eca 64a100000000 mov    eax,fs:0x0
0x569ed0 50 push   eax
0x569ed1 83ec0c sub    esp,0xc
0x569ed4 a1201fd600 mov    eax,ds:0xd61f20
0x569ed9 33c5 xor    eax,ebp
0x569edb 50 push   eax
0x569edc 8d45f4 lea    eax,[ebp-0xc]
0x569edf 64a300000000 mov    fs:0x0,eax
0x569ee5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569ee8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x569eeb 33c0 xor    eax,eax
0x569eed 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569ef0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569ef3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569ef6 8b0d5428fe00 mov    ecx,DWORD PTR ds:0xfe2854
0x569efc 51 push   ecx
0x569efd 8d55e8 lea    edx,[ebp-0x18]
0x569f00 52 push   edx
0x569f01 e81a030000 call   0x56a220
0x569f06 83c408 add    esp,0x8
0x569f09 b801000000 mov    eax,0x1
0x569f0e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569f11 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569f18 59 pop    ecx
0x569f19 8be5 mov    esp,ebp
0x569f1b 5d pop    ebp
0x569f1c c3 ret

; F_00569F20 0x569f20..0x569f7d
0x569f20 55 push   ebp
0x569f21 8bec mov    ebp,esp
0x569f23 6aff push   0xffffffff
0x569f25 68c8839300 push   0x9383c8
0x569f2a 64a100000000 mov    eax,fs:0x0
0x569f30 50 push   eax
0x569f31 83ec0c sub    esp,0xc
0x569f34 a1201fd600 mov    eax,ds:0xd61f20
0x569f39 33c5 xor    eax,ebp
0x569f3b 50 push   eax
0x569f3c 8d45f4 lea    eax,[ebp-0xc]
0x569f3f 64a300000000 mov    fs:0x0,eax
0x569f45 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569f48 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x569f4b 33c0 xor    eax,eax
0x569f4d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569f50 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569f53 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569f56 8b0d5828fe00 mov    ecx,DWORD PTR ds:0xfe2858
0x569f5c 51 push   ecx
0x569f5d 8d55e8 lea    edx,[ebp-0x18]
0x569f60 52 push   edx
0x569f61 e84a050000 call   0x56a4b0
0x569f66 83c408 add    esp,0x8
0x569f69 b801000000 mov    eax,0x1
0x569f6e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569f71 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569f78 59 pop    ecx
0x569f79 8be5 mov    esp,ebp
0x569f7b 5d pop    ebp
0x569f7c c3 ret

; F_00569F80 0x569f80..0x569fdd
0x569f80 55 push   ebp
0x569f81 8bec mov    ebp,esp
0x569f83 6aff push   0xffffffff
0x569f85 68c8839300 push   0x9383c8
0x569f8a 64a100000000 mov    eax,fs:0x0
0x569f90 50 push   eax
0x569f91 83ec0c sub    esp,0xc
0x569f94 a1201fd600 mov    eax,ds:0xd61f20
0x569f99 33c5 xor    eax,ebp
0x569f9b 50 push   eax
0x569f9c 8d45f4 lea    eax,[ebp-0xc]
0x569f9f 64a300000000 mov    fs:0x0,eax
0x569fa5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x569fa8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x569fab 33c0 xor    eax,eax
0x569fad 8945ec mov    DWORD PTR [ebp-0x14],eax
0x569fb0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x569fb3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x569fb6 8b0d5c28fe00 mov    ecx,DWORD PTR ds:0xfe285c
0x569fbc 51 push   ecx
0x569fbd 8d55e8 lea    edx,[ebp-0x18]
0x569fc0 52 push   edx
0x569fc1 e85a020000 call   0x56a220
0x569fc6 83c408 add    esp,0x8
0x569fc9 b801000000 mov    eax,0x1
0x569fce 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x569fd1 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x569fd8 59 pop    ecx
0x569fd9 8be5 mov    esp,ebp
0x569fdb 5d pop    ebp
0x569fdc c3 ret

; F_00569FE0 0x569fe0..0x56a03d
0x569fe0 55 push   ebp
0x569fe1 8bec mov    ebp,esp
0x569fe3 6aff push   0xffffffff
0x569fe5 68c8839300 push   0x9383c8
0x569fea 64a100000000 mov    eax,fs:0x0
0x569ff0 50 push   eax
0x569ff1 83ec0c sub    esp,0xc
0x569ff4 a1201fd600 mov    eax,ds:0xd61f20
0x569ff9 33c5 xor    eax,ebp
0x569ffb 50 push   eax
0x569ffc 8d45f4 lea    eax,[ebp-0xc]
0x569fff 64a300000000 mov    fs:0x0,eax
0x56a005 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x56a008 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56a00b 33c0 xor    eax,eax
0x56a00d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x56a010 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x56a013 8945fc mov    DWORD PTR [ebp-0x4],eax
0x56a016 8b0d6028fe00 mov    ecx,DWORD PTR ds:0xfe2860
0x56a01c 51 push   ecx
0x56a01d 8d55e8 lea    edx,[ebp-0x18]
0x56a020 52 push   edx
0x56a021 e88a040000 call   0x56a4b0
0x56a026 83c408 add    esp,0x8
0x56a029 b801000000 mov    eax,0x1
0x56a02e 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x56a031 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x56a038 59 pop    ecx
0x56a039 8be5 mov    esp,ebp
0x56a03b 5d pop    ebp
0x56a03c c3 ret

; F_0056A040 0x56a040..0x56a09c
0x56a040 55 push   ebp
0x56a041 8bec mov    ebp,esp
0x56a043 6aff push   0xffffffff
0x56a045 68c8839300 push   0x9383c8
0x56a04a 64a100000000 mov    eax,fs:0x0
0x56a050 50 push   eax
0x56a051 83ec0c sub    esp,0xc
0x56a054 a1201fd600 mov    eax,ds:0xd61f20
0x56a059 33c5 xor    eax,ebp
0x56a05b 50 push   eax
0x56a05c 8d45f4 lea    eax,[ebp-0xc]
0x56a05f 64a300000000 mov    fs:0x0,eax
0x56a065 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x56a068 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56a06b 33c0 xor    eax,eax
0x56a06d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x56a070 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x56a073 8945fc mov    DWORD PTR [ebp-0x4],eax
0x56a076 8b0d6428fe00 mov    ecx,DWORD PTR ds:0xfe2864
0x56a07c 51 push   ecx
0x56a07d 8d45e8 lea    eax,[ebp-0x18]
0x56a080 e87b020000 call   0x56a300
0x56a085 83c404 add    esp,0x4
0x56a088 b801000000 mov    eax,0x1
0x56a08d 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x56a090 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x56a097 59 pop    ecx
0x56a098 8be5 mov    esp,ebp
0x56a09a 5d pop    ebp
0x56a09b c3 ret

; F_0056A0A0 0x56a0a0..0x56a0fc
0x56a0a0 55 push   ebp
0x56a0a1 8bec mov    ebp,esp
0x56a0a3 6aff push   0xffffffff
0x56a0a5 68c8839300 push   0x9383c8
0x56a0aa 64a100000000 mov    eax,fs:0x0
0x56a0b0 50 push   eax
0x56a0b1 83ec0c sub    esp,0xc
0x56a0b4 a1201fd600 mov    eax,ds:0xd61f20
0x56a0b9 33c5 xor    eax,ebp
0x56a0bb 50 push   eax
0x56a0bc 8d45f4 lea    eax,[ebp-0xc]
0x56a0bf 64a300000000 mov    fs:0x0,eax
0x56a0c5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x56a0c8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56a0cb 33c0 xor    eax,eax
0x56a0cd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x56a0d0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x56a0d3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x56a0d6 8b0d6828fe00 mov    ecx,DWORD PTR ds:0xfe2868
0x56a0dc 51 push   ecx
0x56a0dd 8d45e8 lea    eax,[ebp-0x18]
0x56a0e0 e84b030000 call   0x56a430
0x56a0e5 83c404 add    esp,0x4
0x56a0e8 b801000000 mov    eax,0x1
0x56a0ed 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x56a0f0 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x56a0f7 59 pop    ecx
0x56a0f8 8be5 mov    esp,ebp
0x56a0fa 5d pop    ebp
0x56a0fb c3 ret

; F_0056A100 0x56a100..0x56a15c
0x56a100 55 push   ebp
0x56a101 8bec mov    ebp,esp
0x56a103 6aff push   0xffffffff
0x56a105 68c8839300 push   0x9383c8
0x56a10a 64a100000000 mov    eax,fs:0x0
0x56a110 50 push   eax
0x56a111 83ec0c sub    esp,0xc
0x56a114 a1201fd600 mov    eax,ds:0xd61f20
0x56a119 33c5 xor    eax,ebp
0x56a11b 50 push   eax
0x56a11c 8d45f4 lea    eax,[ebp-0xc]
0x56a11f 64a300000000 mov    fs:0x0,eax
0x56a125 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x56a128 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56a12b 33c0 xor    eax,eax
0x56a12d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x56a130 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x56a133 8945fc mov    DWORD PTR [ebp-0x4],eax
0x56a136 8b0d6c28fe00 mov    ecx,DWORD PTR ds:0xfe286c
0x56a13c 51 push   ecx
0x56a13d 8d45e8 lea    eax,[ebp-0x18]
0x56a140 e8eb020000 call   0x56a430
0x56a145 83c404 add    esp,0x4
0x56a148 b801000000 mov    eax,0x1
0x56a14d 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x56a150 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x56a157 59 pop    ecx
0x56a158 8be5 mov    esp,ebp
0x56a15a 5d pop    ebp
0x56a15b c3 ret

; F_0056A160 0x56a160..0x56a1b6
0x56a160 55 push   ebp
0x56a161 8bec mov    ebp,esp
0x56a163 6aff push   0xffffffff
0x56a165 68c8839300 push   0x9383c8
0x56a16a 64a100000000 mov    eax,fs:0x0
0x56a170 50 push   eax
0x56a171 83ec0c sub    esp,0xc
0x56a174 a1201fd600 mov    eax,ds:0xd61f20
0x56a179 33c5 xor    eax,ebp
0x56a17b 50 push   eax
0x56a17c 8d45f4 lea    eax,[ebp-0xc]
0x56a17f 64a300000000 mov    fs:0x0,eax
0x56a185 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x56a188 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56a18b 33c0 xor    eax,eax
0x56a18d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x56a190 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x56a193 8945fc mov    DWORD PTR [ebp-0x4],eax
0x56a196 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x56a19c ff157028fe00 call   DWORD PTR ds:0xfe2870
0x56a1a2 b801000000 mov    eax,0x1
0x56a1a7 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x56a1aa 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x56a1b1 59 pop    ecx
0x56a1b2 8be5 mov    esp,ebp
0x56a1b4 5d pop    ebp
0x56a1b5 c3 ret

; F_0056A1C0 0x56a1c0..0x56a216
0x56a1c0 55 push   ebp
0x56a1c1 8bec mov    ebp,esp
0x56a1c3 6aff push   0xffffffff
0x56a1c5 68c8839300 push   0x9383c8
0x56a1ca 64a100000000 mov    eax,fs:0x0
0x56a1d0 50 push   eax
0x56a1d1 83ec0c sub    esp,0xc
0x56a1d4 a1201fd600 mov    eax,ds:0xd61f20
0x56a1d9 33c5 xor    eax,ebp
0x56a1db 50 push   eax
0x56a1dc 8d45f4 lea    eax,[ebp-0xc]
0x56a1df 64a300000000 mov    fs:0x0,eax
0x56a1e5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x56a1e8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x56a1eb 33c0 xor    eax,eax
0x56a1ed 8945ec mov    DWORD PTR [ebp-0x14],eax
0x56a1f0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x56a1f3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x56a1f6 8b0d7827fe00 mov    ecx,DWORD PTR ds:0xfe2778
0x56a1fc ff157428fe00 call   DWORD PTR ds:0xfe2874
0x56a202 b801000000 mov    eax,0x1
0x56a207 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x56a20a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x56a211 59 pop    ecx
0x56a212 8be5 mov    esp,ebp
0x56a214 5d pop    ebp
0x56a215 c3 ret

; F_006BDEB0 0x6bdeb0..0x6bdf06
0x6bdeb0 55 push   ebp
0x6bdeb1 8bec mov    ebp,esp
0x6bdeb3 6aff push   0xffffffff
0x6bdeb5 68c8839300 push   0x9383c8
0x6bdeba 64a100000000 mov    eax,fs:0x0
0x6bdec0 50 push   eax
0x6bdec1 83ec0c sub    esp,0xc
0x6bdec4 a1201fd600 mov    eax,ds:0xd61f20
0x6bdec9 33c5 xor    eax,ebp
0x6bdecb 50 push   eax
0x6bdecc 8d45f4 lea    eax,[ebp-0xc]
0x6bdecf 64a300000000 mov    fs:0x0,eax
0x6bded5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x6bded8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x6bdedb 33c0 xor    eax,eax
0x6bdedd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x6bdee0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x6bdee3 8d4de8 lea    ecx,[ebp-0x18]
0x6bdee6 51 push   ecx
0x6bdee7 8945fc mov    DWORD PTR [ebp-0x4],eax
0x6bdeea e8a1010000 call   0x6be090
0x6bdeef 83c404 add    esp,0x4
0x6bdef2 b801000000 mov    eax,0x1
0x6bdef7 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x6bdefa 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x6bdf01 59 pop    ecx
0x6bdf02 8be5 mov    esp,ebp
0x6bdf04 5d pop    ebp
0x6bdf05 c3 ret

; F_006BE090 0x6be090..0x6be191
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

; F_006BDF10 0x6bdf10..0x6bdf66
0x6bdf10 55 push   ebp
0x6bdf11 8bec mov    ebp,esp
0x6bdf13 6aff push   0xffffffff
0x6bdf15 68c8839300 push   0x9383c8
0x6bdf1a 64a100000000 mov    eax,fs:0x0
0x6bdf20 50 push   eax
0x6bdf21 83ec0c sub    esp,0xc
0x6bdf24 a1201fd600 mov    eax,ds:0xd61f20
0x6bdf29 33c5 xor    eax,ebp
0x6bdf2b 50 push   eax
0x6bdf2c 8d45f4 lea    eax,[ebp-0xc]
0x6bdf2f 64a300000000 mov    fs:0x0,eax
0x6bdf35 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x6bdf38 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x6bdf3b 33c0 xor    eax,eax
0x6bdf3d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x6bdf40 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x6bdf43 8945fc mov    DWORD PTR [ebp-0x4],eax
0x6bdf46 8b0d8031fe00 mov    ecx,DWORD PTR ds:0xfe3180
0x6bdf4c ff158831fe00 call   DWORD PTR ds:0xfe3188
0x6bdf52 b801000000 mov    eax,0x1
0x6bdf57 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x6bdf5a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x6bdf61 59 pop    ecx
0x6bdf62 8be5 mov    esp,ebp
0x6bdf64 5d pop    ebp
0x6bdf65 c3 ret

; F_006BDF70 0x6bdf70..0x6bdfc6
0x6bdf70 55 push   ebp
0x6bdf71 8bec mov    ebp,esp
0x6bdf73 6aff push   0xffffffff
0x6bdf75 68c8839300 push   0x9383c8
0x6bdf7a 64a100000000 mov    eax,fs:0x0
0x6bdf80 50 push   eax
0x6bdf81 83ec0c sub    esp,0xc
0x6bdf84 a1201fd600 mov    eax,ds:0xd61f20
0x6bdf89 33c5 xor    eax,ebp
0x6bdf8b 50 push   eax
0x6bdf8c 8d45f4 lea    eax,[ebp-0xc]
0x6bdf8f 64a300000000 mov    fs:0x0,eax
0x6bdf95 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x6bdf98 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x6bdf9b 33c0 xor    eax,eax
0x6bdf9d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x6bdfa0 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x6bdfa3 8945fc mov    DWORD PTR [ebp-0x4],eax
0x6bdfa6 8b0d8031fe00 mov    ecx,DWORD PTR ds:0xfe3180
0x6bdfac ff158c31fe00 call   DWORD PTR ds:0xfe318c
0x6bdfb2 b801000000 mov    eax,0x1
0x6bdfb7 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x6bdfba 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x6bdfc1 59 pop    ecx
0x6bdfc2 8be5 mov    esp,ebp
0x6bdfc4 5d pop    ebp
0x6bdfc5 c3 ret

; F_006BDFD0 0x6bdfd0..0x6be026
0x6bdfd0 55 push   ebp
0x6bdfd1 8bec mov    ebp,esp
0x6bdfd3 6aff push   0xffffffff
0x6bdfd5 68c8839300 push   0x9383c8
0x6bdfda 64a100000000 mov    eax,fs:0x0
0x6bdfe0 50 push   eax
0x6bdfe1 83ec0c sub    esp,0xc
0x6bdfe4 a1201fd600 mov    eax,ds:0xd61f20
0x6bdfe9 33c5 xor    eax,ebp
0x6bdfeb 50 push   eax
0x6bdfec 8d45f4 lea    eax,[ebp-0xc]
0x6bdfef 64a300000000 mov    fs:0x0,eax
0x6bdff5 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x6bdff8 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x6bdffb 33c0 xor    eax,eax
0x6bdffd 8945ec mov    DWORD PTR [ebp-0x14],eax
0x6be000 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x6be003 8945fc mov    DWORD PTR [ebp-0x4],eax
0x6be006 8b0d8031fe00 mov    ecx,DWORD PTR ds:0xfe3180
0x6be00c ff159031fe00 call   DWORD PTR ds:0xfe3190
0x6be012 b801000000 mov    eax,0x1
0x6be017 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x6be01a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x6be021 59 pop    ecx
0x6be022 8be5 mov    esp,ebp
0x6be024 5d pop    ebp
0x6be025 c3 ret

; F_006BE030 0x6be030..0x6be086
0x6be030 55 push   ebp
0x6be031 8bec mov    ebp,esp
0x6be033 6aff push   0xffffffff
0x6be035 68c8839300 push   0x9383c8
0x6be03a 64a100000000 mov    eax,fs:0x0
0x6be040 50 push   eax
0x6be041 83ec0c sub    esp,0xc
0x6be044 a1201fd600 mov    eax,ds:0xd61f20
0x6be049 33c5 xor    eax,ebp
0x6be04b 50 push   eax
0x6be04c 8d45f4 lea    eax,[ebp-0xc]
0x6be04f 64a300000000 mov    fs:0x0,eax
0x6be055 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x6be058 8945e8 mov    DWORD PTR [ebp-0x18],eax
0x6be05b 33c0 xor    eax,eax
0x6be05d 8945ec mov    DWORD PTR [ebp-0x14],eax
0x6be060 8945f0 mov    DWORD PTR [ebp-0x10],eax
0x6be063 8945fc mov    DWORD PTR [ebp-0x4],eax
0x6be066 8b0d8031fe00 mov    ecx,DWORD PTR ds:0xfe3180
0x6be06c ff159431fe00 call   DWORD PTR ds:0xfe3194
0x6be072 b801000000 mov    eax,0x1
0x6be077 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x6be07a 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x6be081 59 pop    ecx
0x6be082 8be5 mov    esp,ebp
0x6be084 5d pop    ebp
0x6be085 c3 ret

; F_006F50F0 0x6f50f0..0x6f516c
0x6f50f0 85c0 test   eax,eax
0x6f50f2 7e14 jle    0x6f5108
0x6f50f4 8b510c mov    edx,DWORD PTR [ecx+0xc]
0x6f50f7 03c0 add    eax,eax
0x6f50f9 8d44c2f0 lea    eax,[edx+eax*8-0x10]
0x6f50fd 3b4108 cmp    eax,DWORD PTR [ecx+0x8]
0x6f5100 7269 jb     0x6f516b
0x6f5102 b8c8bfc000 mov    eax,0xc0bfc8
0x6f5107 c3 ret
0x6f5108 3df0d8ffff cmp    eax,0xffffd8f0
0x6f510d 7e07 jle    0x6f5116
0x6f510f c1e004 shl    eax,0x4
0x6f5112 034108 add    eax,DWORD PTR [ecx+0x8]
0x6f5115 c3 ret
0x6f5116 3deed8ffff cmp    eax,0xffffd8ee
0x6f511b 744b je     0x6f5168
0x6f511d 3defd8ffff cmp    eax,0xffffd8ef
0x6f5122 742c je     0x6f5150
0x6f5124 3df0d8ffff cmp    eax,0xffffd8f0
0x6f5129 741e je     0x6f5149
0x6f512b 8b4914 mov    ecx,DWORD PTR [ecx+0x14]
0x6f512e 8b5104 mov    edx,DWORD PTR [ecx+0x4]
0x6f5131 8b12 mov    edx,DWORD PTR [edx]
0x6f5133 b9eed8ffff mov    ecx,0xffffd8ee
0x6f5138 2bc8 sub    ecx,eax
0x6f513a 0fb64207 movzx  eax,BYTE PTR [edx+0x7]
0x6f513e 3bc8 cmp    ecx,eax
0x6f5140 7fc0 jg     0x6f5102
0x6f5142 03c9 add    ecx,ecx
0x6f5144 8d44ca08 lea    eax,[edx+ecx*8+0x8]
0x6f5148 c3 ret
0x6f5149 8b4110 mov    eax,DWORD PTR [ecx+0x10]
0x6f514c 83c060 add    eax,0x60
0x6f514f c3 ret
0x6f5150 8d4158 lea    eax,[ecx+0x58]
0x6f5153 8b4914 mov    ecx,DWORD PTR [ecx+0x14]
0x6f5156 8b5104 mov    edx,DWORD PTR [ecx+0x4]
0x6f5159 8b0a mov    ecx,DWORD PTR [edx]
0x6f515b 8b510c mov    edx,DWORD PTR [ecx+0xc]
0x6f515e 8910 mov    DWORD PTR [eax],edx
0x6f5160 c7400805000000 mov    DWORD PTR [eax+0x8],0x5
0x6f5167 c3 ret
0x6f5168 8d4148 lea    eax,[ecx+0x48]
0x6f516b c3 ret

; F_006F7760 0x6f7760..0x6f77f6
0x6f7760 55 push   ebp
0x6f7761 8bec mov    ebp,esp
0x6f7763 83ec08 sub    esp,0x8
0x6f7766 8d45fc lea    eax,[ebp-0x4]
0x6f7769 50 push   eax
0x6f776a 56 push   esi
0x6f776b e8cf121a00 call   0x898a3f
0x6f7770 dd1f fstp   QWORD PTR [edi]
0x6f7772 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x6f7775 83c408 add    esp,0x8
0x6f7778 3bc6 cmp    eax,esi
0x6f777a 7506 jne    0x6f7782
0x6f777c 33c0 xor    eax,eax
0x6f777e 8be5 mov    esp,ebp
0x6f7780 5d pop    ebp
0x6f7781 c3 ret
0x6f7782 8a08 mov    cl,BYTE PTR [eax]
0x6f7784 80f978 cmp    cl,0x78
0x6f7787 7405 je     0x6f778e
0x6f7789 80f958 cmp    cl,0x58
0x6f778c 7524 jne    0x6f77b2
0x6f778e 6a10 push   0x10
0x6f7790 8d4dfc lea    ecx,[ebp-0x4]
0x6f7793 51 push   ecx
0x6f7794 56 push   esi
0x6f7795 e880171a00 call   0x898f1a
0x6f779a 83c40c add    esp,0xc
0x6f779d 8945f8 mov    DWORD PTR [ebp-0x8],eax
0x6f77a0 db45f8 fild   DWORD PTR [ebp-0x8]
0x6f77a3 85c0 test   eax,eax
0x6f77a5 7906 jns    0x6f77ad
0x6f77a7 dc052057c500 fadd   QWORD PTR ds:0xc55720
0x6f77ad 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x6f77b0 dd1f fstp   QWORD PTR [edi]
0x6f77b2 8a00 mov    al,BYTE PTR [eax]
0x6f77b4 84c0 test   al,al
0x6f77b6 7509 jne    0x6f77c1
0x6f77b8 b801000000 mov    eax,0x1
0x6f77bd 8be5 mov    esp,ebp
0x6f77bf 5d pop    ebp
0x6f77c0 c3 ret
0x6f77c1 0fb6d0 movzx  edx,al
0x6f77c4 52 push   edx
0x6f77c5 e866dd1900 call   0x895530
0x6f77ca 83c404 add    esp,0x4
0x6f77cd 85c0 test   eax,eax
0x6f77cf 7417 je     0x6f77e8
0x6f77d1 8b45fc mov    eax,DWORD PTR [ebp-0x4]
0x6f77d4 40 inc    eax
0x6f77d5 8945fc mov    DWORD PTR [ebp-0x4],eax
0x6f77d8 0fb600 movzx  eax,BYTE PTR [eax]
0x6f77db 50 push   eax
0x6f77dc e84fdd1900 call   0x895530
0x6f77e1 83c404 add    esp,0x4
0x6f77e4 85c0 test   eax,eax
0x6f77e6 75e9 jne    0x6f77d1
0x6f77e8 8b4dfc mov    ecx,DWORD PTR [ebp-0x4]
0x6f77eb 33c0 xor    eax,eax
0x6f77ed 3801 cmp    BYTE PTR [ecx],al
0x6f77ef 0f94c0 sete   al
0x6f77f2 8be5 mov    esp,ebp
0x6f77f4 5d pop    ebp
0x6f77f5 c3 ret

; F_006FB5D0 0x6fb5d0..0x6fb655
0x6fb5d0 55 push   ebp
0x6fb5d1 8bec mov    ebp,esp
0x6fb5d3 83e4c0 and    esp,0xffffffc0
0x6fb5d6 83ec40 sub    esp,0x40
0x6fb5d9 a1201fd600 mov    eax,ds:0xd61f20
0x6fb5de 33c4 xor    eax,esp
0x6fb5e0 8944243c mov    DWORD PTR [esp+0x3c],eax
0x6fb5e4 837e0803 cmp    DWORD PTR [esi+0x8],0x3
0x6fb5e8 7411 je     0x6fb5fb
0x6fb5ea 33c0 xor    eax,eax
0x6fb5ec 8b4c243c mov    ecx,DWORD PTR [esp+0x3c]
0x6fb5f0 33cc xor    ecx,esp
0x6fb5f2 e80a5a1900 call   0x891001
0x6fb5f7 8be5 mov    esp,ebp
0x6fb5f9 5d pop    ebp
0x6fb5fa c3 ret
0x6fb5fb dd06 fld    QWORD PTR [esi]
0x6fb5fd 83ec08 sub    esp,0x8
0x6fb600 dd1c24 fstp   QWORD PTR [esp]
0x6fb603 8d442424 lea    eax,[esp+0x24]
0x6fb607 68102ac400 push   0xc42a10
0x6fb60c 50 push   eax
0x6fb60d e81d751900 call   0x892b2f
0x6fb612 8d44242c lea    eax,[esp+0x2c]
0x6fb616 83c410 add    esp,0x10
0x6fb619 8d5001 lea    edx,[eax+0x1]
0x6fb61c 8d642400 lea    esp,[esp+0x0]
0x6fb620 8a08 mov    cl,BYTE PTR [eax]
0x6fb622 40 inc    eax
0x6fb623 84c9 test   cl,cl
0x6fb625 75f9 jne    0x6fb620
0x6fb627 2bc2 sub    eax,edx
0x6fb629 50 push   eax
0x6fb62a 8d4c2420 lea    ecx,[esp+0x20]
0x6fb62e 51 push   ecx
0x6fb62f 57 push   edi
0x6fb630 e83b360000 call   0x6fec70
0x6fb635 8b4c2448 mov    ecx,DWORD PTR [esp+0x48]
0x6fb639 83c40c add    esp,0xc
0x6fb63c 8906 mov    DWORD PTR [esi],eax
0x6fb63e 33cc xor    ecx,esp
0x6fb640 c7460804000000 mov    DWORD PTR [esi+0x8],0x4
0x6fb647 b801000000 mov    eax,0x1
0x6fb64c e8b0591900 call   0x891001
0x6fb651 8be5 mov    esp,ebp
0x6fb653 5d pop    ebp
0x6fb654 c3 ret

; F_004A1230 0x4a1230..0x4a132c
0x4a1230 55 push   ebp
0x4a1231 8bec mov    ebp,esp
0x4a1233 6aff push   0xffffffff
0x4a1235 687ea99300 push   0x93a97e
0x4a123a 64a100000000 mov    eax,fs:0x0
0x4a1240 50 push   eax
0x4a1241 53 push   ebx
0x4a1242 56 push   esi
0x4a1243 57 push   edi
0x4a1244 a1201fd600 mov    eax,ds:0xd61f20
0x4a1249 33c5 xor    eax,ebp
0x4a124b 50 push   eax
0x4a124c 8d45f4 lea    eax,[ebp-0xc]
0x4a124f 64a300000000 mov    fs:0x0,eax
0x4a1255 8b4508 mov    eax,DWORD PTR [ebp+0x8]
0x4a1258 68e0d1be00 push   0xbed1e0
0x4a125d 50 push   eax
0x4a125e e80d352700 call   0x714770
0x4a1263 8bf0 mov    esi,eax
0x4a1265 83c408 add    esp,0x8
0x4a1268 85f6 test   esi,esi
0x4a126a 0f84a6000000 je     0x4a1316
0x4a1270 8b16 mov    edx,DWORD PTR [esi]
0x4a1272 8b422c mov    eax,DWORD PTR [edx+0x2c]
0x4a1275 8bce mov    ecx,esi
0x4a1277 ffd0 call   eax
0x4a1279 8bf8 mov    edi,eax
0x4a127b 8d4f01 lea    ecx,[edi+0x1]
0x4a127e 51 push   ecx
0x4a127f e8b9c93d00 call   0x87dc3d
0x4a1284 8b16 mov    edx,DWORD PTR [esi]
0x4a1286 83c404 add    esp,0x4
0x4a1289 8bd8 mov    ebx,eax
0x4a128b 8b4238 mov    eax,DWORD PTR [edx+0x38]
0x4a128e 57 push   edi
0x4a128f 8bce mov    ecx,esi
0x4a1291 ffd0 call   eax
0x4a1293 50 push   eax
0x4a1294 53 push   ebx
0x4a1295 e836c93f00 call   0x89dbd0
0x4a129a c6041f00 mov    BYTE PTR [edi+ebx*1],0x0
0x4a129e 8b16 mov    edx,DWORD PTR [esi]
0x4a12a0 8b422c mov    eax,DWORD PTR [edx+0x2c]
0x4a12a3 83c40c add    esp,0xc
0x4a12a6 8bce mov    ecx,esi
0x4a12a8 ffd0 call   eax
0x4a12aa 8bf8 mov    edi,eax
0x4a12ac b801000000 mov    eax,0x1
0x4a12b1 8405d4f3fd00 test   BYTE PTR ds:0xfdf3d4,al
0x4a12b7 7526 jne    0x4a12df
0x4a12b9 0905d4f3fd00 or     DWORD PTR ds:0xfdf3d4,eax
0x4a12bf c745fc00000000 mov    DWORD PTR [ebp-0x4],0x0
0x4a12c6 e8b5302500 call   0x6f4380
0x4a12cb 68d0e6bc00 push   0xbce6d0
0x4a12d0 e845103f00 call   0x89231a
0x4a12d5 83c404 add    esp,0x4
0x4a12d8 c745fcffffffff mov    DWORD PTR [ebp-0x4],0xffffffff
0x4a12df 8bcf mov    ecx,edi
0x4a12e1 53 push   ebx
0x4a12e2 bfc8f3fd00 mov    edi,0xfdf3c8
0x4a12e7 e834392500 call   0x6f4c20
0x4a12ec 8b16 mov    edx,DWORD PTR [esi]
0x4a12ee 8bf8 mov    edi,eax
0x4a12f0 8b4204 mov    eax,DWORD PTR [edx+0x4]
0x4a12f3 8bce mov    ecx,esi
0x4a12f5 ffd0 call   eax
0x4a12f7 53 push   ebx
0x4a12f8 e8400a3f00 call   0x891d3d
0x4a12fd 83c404 add    esp,0x4
0x4a1300 8bc7 mov    eax,edi
0x4a1302 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4a1305 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4a130c 59 pop    ecx
0x4a130d 5f pop    edi
0x4a130e 5e pop    esi
0x4a130f 5b pop    ebx
0x4a1310 8be5 mov    esp,ebp
0x4a1312 5d pop    ebp
0x4a1313 c20400 ret    0x4
0x4a1316 33c0 xor    eax,eax
0x4a1318 8b4df4 mov    ecx,DWORD PTR [ebp-0xc]
0x4a131b 64890d00000000 mov    DWORD PTR fs:0x0,ecx
0x4a1322 59 pop    ecx
0x4a1323 5f pop    edi
0x4a1324 5e pop    esi
0x4a1325 5b pop    ebx
0x4a1326 8be5 mov    esp,ebp
0x4a1328 5d pop    ebp
0x4a1329 c20400 ret    0x4

; F_006F4C20 0x6f4c20..0x6f4cca
0x6f4c20 55 push   ebp
0x6f4c21 8bec mov    ebp,esp
0x6f4c23 83e4f8 and    esp,0xfffffff8
0x6f4c26 83ec20 sub    esp,0x20
0x6f4c29 8b07 mov    eax,DWORD PTR [edi]
0x6f4c2b 53 push   ebx
0x6f4c2c 8b5d08 mov    ebx,DWORD PTR [ebp+0x8]
0x6f4c2f 894c240c mov    DWORD PTR [esp+0xc],ecx
0x6f4c33 33c9 xor    ecx,ecx
0x6f4c35 56 push   esi
0x6f4c36 89442424 mov    DWORD PTR [esp+0x24],eax
0x6f4c3a 8d54240c lea    edx,[esp+0xc]
0x6f4c3e 894c2414 mov    DWORD PTR [esp+0x14],ecx
0x6f4c42 894c2418 mov    DWORD PTR [esp+0x18],ecx
0x6f4c46 50 push   eax
0x6f4c47 b90027c400 mov    ecx,0xc42700
0x6f4c4c 8d442418 lea    eax,[esp+0x18]
0x6f4c50 895c2410 mov    DWORD PTR [esp+0x10],ebx
0x6f4c54 c7442420e0706f00 mov    DWORD PTR [esp+0x20],0x6f70e0
0x6f4c5c 89542424 mov    DWORD PTR [esp+0x24],edx
0x6f4c60 e82b9d0000 call   0x6fe990
0x6f4c65 83c404 add    esp,0x4
0x6f4c68 85c0 test   eax,eax
0x6f4c6a 7548 jne    0x6f4cb4
0x6f4c6c 8b37 mov    esi,DWORD PTR [edi]
0x6f4c6e 8b4608 mov    eax,DWORD PTR [esi+0x8]
0x6f4c71 83e810 sub    eax,0x10
0x6f4c74 8944240c mov    DWORD PTR [esp+0xc],eax
0x6f4c78 2b4620 sub    eax,DWORD PTR [esi+0x20]
0x6f4c7b 33d2 xor    edx,edx
0x6f4c7d 50 push   eax
0x6f4c7e 8d442410 lea    eax,[esp+0x10]
0x6f4c82 50 push   eax
0x6f4c83 68505a6f00 push   0x6f5a50
0x6f4c88 8bc6 mov    eax,esi
0x6f4c8a c744241cffffffff mov    DWORD PTR [esp+0x1c],0xffffffff
0x6f4c92 e8d99a0000 call   0x6fe770
0x6f4c97 8b4e14 mov    ecx,DWORD PTR [esi+0x14]
0x6f4c9a 8b7608 mov    esi,DWORD PTR [esi+0x8]
0x6f4c9d 83c40c add    esp,0xc
0x6f4ca0 3b7108 cmp    esi,DWORD PTR [ecx+0x8]
0x6f4ca3 7203 jb     0x6f4ca8
0x6f4ca5 897108 mov    DWORD PTR [ecx+0x8],esi
0x6f4ca8 85c0 test   eax,eax
0x6f4caa 7508 jne    0x6f4cb4
0x6f4cac 5e pop    esi
0x6f4cad 5b pop    ebx
0x6f4cae 8be5 mov    esp,ebp
0x6f4cb0 5d pop    ebp
0x6f4cb1 c20400 ret    0x4
0x6f4cb4 53 push   ebx
0x6f4cb5 57 push   edi
0x6f4cb6 be01000000 mov    esi,0x1
0x6f4cbb e8e0faffff call   0x6f47a0
0x6f4cc0 8bc6 mov    eax,esi
0x6f4cc2 5e pop    esi
0x6f4cc3 5b pop    ebx
0x6f4cc4 8be5 mov    esp,ebp
0x6f4cc6 5d pop    ebp
0x6f4cc7 c20400 ret    0x4
