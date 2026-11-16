; lb_time_import_thunk | finite getter classification: tailcall original timeGetTime import
; VA 0x4a0b70..0x4a0b76 RAW 0x9ff70 len 6 SHA256 1e05d35a243922405ca3eba158b4de07e454da4919db9eb54ebbbeea5e0e181a
0x4a0b70 raw=0x9ff70  ff25a025bd00                   jmp    DWORD PTR ds:0xbd25a0

; tutorial_skip_read | finite getter classification: fixed global FBA7A0, producer not re-closed here
; VA 0x4a9320..0x4a9326 RAW 0xa8720 len 6 SHA256 7ad95713283e97cf3646a0d1c3b7c3eaa33fd989109bc7af4e9d5854f4ff4f62
0x4a9320 raw=0xa8720  a1a0a7fb00                     mov    eax,ds:0xfba7a0
0x4a9325 raw=0xa8725  c3                             ret

; tutorial_cutscene_read | finite getter classification: Q singleton+28
; VA 0x4a97b0..0x4a9812 RAW 0xa8bb0 len 98 SHA256 9274b6d026a2b6a1910bee389b8f6027932a7dcd629e5ec66f0f114543a42cb6
0x4a97b0 raw=0xa8bb0  55                             push   ebp
0x4a97b1 raw=0xa8bb1  8bec                           mov    ebp,esp
0x4a97b3 raw=0xa8bb3  6aff                           push   0xffffffff
0x4a97b5 raw=0xa8bb5  68aeb29300                     push   0x93b2ae
0x4a97ba raw=0xa8bba  64a100000000                   mov    eax,fs:0x0
0x4a97c0 raw=0xa8bc0  50                             push   eax
0x4a97c1 raw=0xa8bc1  a1201fd600                     mov    eax,ds:0xd61f20
0x4a97c6 raw=0xa8bc6  33c5                           xor    eax,ebp
0x4a97c8 raw=0xa8bc8  50                             push   eax
0x4a97c9 raw=0xa8bc9  8d45f4                         lea    eax,[ebp-0xc]
0x4a97cc raw=0xa8bcc  64a300000000                   mov    fs:0x0,eax
0x4a97d2 raw=0xa8bd2  b801000000                     mov    eax,0x1
0x4a97d7 raw=0xa8bd7  8405b873fb00                   test   BYTE PTR ds:0xfb73b8,al
0x4a97dd raw=0xa8bdd  751f                           jne    0x4a97fe
0x4a97df raw=0xa8bdf  0905b873fb00                   or     DWORD PTR ds:0xfb73b8,eax
0x4a97e5 raw=0xa8be5  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
0x4a97ec raw=0xa8bec  e87f690b00                     call   0x560170
0x4a97f1 raw=0xa8bf1  6810d1bc00                     push   0xbcd110
0x4a97f6 raw=0xa8bf6  e81f8b3e00                     call   0x89231a
0x4a97fb raw=0xa8bfb  83c404                         add    esp,0x4
0x4a97fe raw=0xa8bfe  a1e873fb00                     mov    eax,ds:0xfb73e8
0x4a9803 raw=0xa8c03  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x4a9806 raw=0xa8c06  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x4a980d raw=0xa8c0d  59                             pop    ecx
0x4a980e raw=0xa8c0e  8be5                           mov    esp,ebp
0x4a9810 raw=0xa8c10  5d                             pop    ebp
0x4a9811 raw=0xa8c11  c3                             ret

; q_cutscene_read | finite getter classification: receiver+28
; VA 0x489cf0..0x489cf4 RAW 0x890f0 len 4 SHA256 f9ab56c764100f6de974a6afa5ca5ea00146ab6bd602328393ec5e4228c34b90
0x489cf0 raw=0x890f0  8b4128                         mov    eax,DWORD PTR [ecx+0x28]
0x489cf3 raw=0x890f3  c3                             ret

; q_cutscene_closure | normal receiver FE2778 and numeric value push
; VA 0x568af0..0x568b5e RAW 0x167ef0 len 110 SHA256 9706651dd69d0fcdb94ad1b562c98cc38010613d85b2211efab1ca3f57975c45
0x568af0 raw=0x167ef0  55                             push   ebp
0x568af1 raw=0x167ef1  8bec                           mov    ebp,esp
0x568af3 raw=0x167ef3  6aff                           push   0xffffffff
0x568af5 raw=0x167ef5  68d8879300                     push   0x9387d8
0x568afa raw=0x167efa  64a100000000                   mov    eax,fs:0x0
0x568b00 raw=0x167f00  50                             push   eax
0x568b01 raw=0x167f01  83ec0c                         sub    esp,0xc
0x568b04 raw=0x167f04  56                             push   esi
0x568b05 raw=0x167f05  a1201fd600                     mov    eax,ds:0xd61f20
0x568b0a raw=0x167f0a  33c5                           xor    eax,ebp
0x568b0c raw=0x167f0c  50                             push   eax
0x568b0d raw=0x167f0d  8d45f4                         lea    eax,[ebp-0xc]
0x568b10 raw=0x167f10  64a300000000                   mov    fs:0x0,eax
0x568b16 raw=0x167f16  8b7508                         mov    esi,DWORD PTR [ebp+0x8]
0x568b19 raw=0x167f19  33c0                           xor    eax,eax
0x568b1b raw=0x167f1b  8975e8                         mov    DWORD PTR [ebp-0x18],esi
0x568b1e raw=0x167f1e  8945ec                         mov    DWORD PTR [ebp-0x14],eax
0x568b21 raw=0x167f21  8945f0                         mov    DWORD PTR [ebp-0x10],eax
0x568b24 raw=0x167f24  8945fc                         mov    DWORD PTR [ebp-0x4],eax
0x568b27 raw=0x167f27  8b0d7827fe00                   mov    ecx,DWORD PTR ds:0xfe2778
0x568b2d raw=0x167f2d  ff158427fe00                   call   DWORD PTR ds:0xfe2784
0x568b33 raw=0x167f33  894508                         mov    DWORD PTR [ebp+0x8],eax
0x568b36 raw=0x167f36  8b4608                         mov    eax,DWORD PTR [esi+0x8]
0x568b39 raw=0x167f39  db4508                         fild   DWORD PTR [ebp+0x8]
0x568b3c raw=0x167f3c  c7400803000000                 mov    DWORD PTR [eax+0x8],0x3
0x568b43 raw=0x167f43  dd18                           fstp   QWORD PTR [eax]
0x568b45 raw=0x167f45  83460810                       add    DWORD PTR [esi+0x8],0x10
0x568b49 raw=0x167f49  b801000000                     mov    eax,0x1
0x568b4e raw=0x167f4e  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x568b51 raw=0x167f51  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x568b58 raw=0x167f58  59                             pop    ecx
0x568b59 raw=0x167f59  5e                             pop    esi
0x568b5a raw=0x167f5a  8be5                           mov    esp,ebp
0x568b5c raw=0x167f5c  5d                             pop    ebp
0x568b5d raw=0x167f5d  c3                             ret

; binding_lb_root | lb normal 14 registrar calls, shared Lua wrapper FDF3C8
; VA 0x4a0950..0x4a0a21 RAW 0x9fd50 len 209 SHA256 fb8718c27cd1337a724721509e47ef17af7a514ff0940599c39f778ce3210a72
0x4a0950 raw=0x9fd50  55                             push   ebp
0x4a0951 raw=0x9fd51  8bec                           mov    ebp,esp
0x4a0953 raw=0x9fd53  6aff                           push   0xffffffff
0x4a0955 raw=0x9fd55  68be4e9400                     push   0x944ebe
0x4a095a raw=0x9fd5a  64a100000000                   mov    eax,fs:0x0
0x4a0960 raw=0x9fd60  50                             push   eax
0x4a0961 raw=0x9fd61  83ec08                         sub    esp,0x8
0x4a0964 raw=0x9fd64  a1201fd600                     mov    eax,ds:0xd61f20
0x4a0969 raw=0x9fd69  33c5                           xor    eax,ebp
0x4a096b raw=0x9fd6b  50                             push   eax
0x4a096c raw=0x9fd6c  8d45f4                         lea    eax,[ebp-0xc]
0x4a096f raw=0x9fd6f  64a300000000                   mov    fs:0x0,eax
0x4a0975 raw=0x9fd75  b801000000                     mov    eax,0x1
0x4a097a raw=0x9fd7a  8405d4f3fd00                   test   BYTE PTR ds:0xfdf3d4,al
0x4a0980 raw=0x9fd80  7526                           jne    0x4a09a8
0x4a0982 raw=0x9fd82  0905d4f3fd00                   or     DWORD PTR ds:0xfdf3d4,eax
0x4a0988 raw=0x9fd88  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
0x4a098f raw=0x9fd8f  e8ec392500                     call   0x6f4380
0x4a0994 raw=0x9fd94  68d0e6bc00                     push   0xbce6d0
0x4a0999 raw=0x9fd99  e87c193f00                     call   0x89231a
0x4a099e raw=0x9fd9e  83c404                         add    esp,0x4
0x4a09a1 raw=0x9fda1  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
0x4a09a8 raw=0x9fda8  8d45f0                         lea    eax,[ebp-0x10]
0x4a09ab raw=0x9fdab  68c8f3fd00                     push   0xfdf3c8
0x4a09b0 raw=0x9fdb0  50                             push   eax
0x4a09b1 raw=0x9fdb1  e81a0b0000                     call   0x4a14d0
0x4a09b6 raw=0x9fdb6  83c408                         add    esp,0x8
0x4a09b9 raw=0x9fdb9  50                             push   eax
0x4a09ba raw=0x9fdba  e8f10b0000                     call   0x4a15b0
0x4a09bf raw=0x9fdbf  50                             push   eax
0x4a09c0 raw=0x9fdc0  e88b0c0000                     call   0x4a1650
0x4a09c5 raw=0x9fdc5  50                             push   eax
0x4a09c6 raw=0x9fdc6  e8250d0000                     call   0x4a16f0
0x4a09cb raw=0x9fdcb  50                             push   eax
0x4a09cc raw=0x9fdcc  e8bf0d0000                     call   0x4a1790
0x4a09d1 raw=0x9fdd1  50                             push   eax
0x4a09d2 raw=0x9fdd2  e8590e0000                     call   0x4a1830
0x4a09d7 raw=0x9fdd7  50                             push   eax
0x4a09d8 raw=0x9fdd8  e8f30e0000                     call   0x4a18d0
0x4a09dd raw=0x9fddd  50                             push   eax
0x4a09de raw=0x9fdde  e88d0f0000                     call   0x4a1970
0x4a09e3 raw=0x9fde3  50                             push   eax
0x4a09e4 raw=0x9fde4  e827100000                     call   0x4a1a10
0x4a09e9 raw=0x9fde9  50                             push   eax
0x4a09ea raw=0x9fdea  e8c1100000                     call   0x4a1ab0
0x4a09ef raw=0x9fdef  50                             push   eax
0x4a09f0 raw=0x9fdf0  e85b110000                     call   0x4a1b50
0x4a09f5 raw=0x9fdf5  50                             push   eax
0x4a09f6 raw=0x9fdf6  e8f5110000                     call   0x4a1bf0
0x4a09fb raw=0x9fdfb  50                             push   eax
0x4a09fc raw=0x9fdfc  e88f120000                     call   0x4a1c90
0x4a0a01 raw=0x9fe01  50                             push   eax
0x4a0a02 raw=0x9fe02  e829130000                     call   0x4a1d30
0x4a0a07 raw=0x9fe07  50                             push   eax
0x4a0a08 raw=0x9fe08  e8c3130000                     call   0x4a1dd0
0x4a0a0d raw=0x9fe0d  b82472fe00                     mov    eax,0xfe7224
0x4a0a12 raw=0x9fe12  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x4a0a15 raw=0x9fe15  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x4a0a1c raw=0x9fe1c  59                             pop    ecx
0x4a0a1d raw=0x9fe1d  8be5                           mov    esp,ebp
0x4a0a1f raw=0x9fe1f  5d                             pop    ebp
0x4a0a20 raw=0x9fe20  c3                             ret

; binding_tutorial_root | Tutorial normal 31 registrar calls; reuse prior semantic proofs
; VA 0x4a88e0..0x4a89bf RAW 0xa7ce0 len 223 SHA256 c02c1bb33b21151db1ec5bbeffe4086005d24a77413a8d395d70428a8a528ff0
0x4a88e0 raw=0xa7ce0  55                             push   ebp
0x4a88e1 raw=0xa7ce1  8bec                           mov    ebp,esp
0x4a88e3 raw=0xa7ce3  83ec08                         sub    esp,0x8
0x4a88e6 raw=0xa7ce6  8d4dfc                         lea    ecx,[ebp-0x4]
0x4a88e9 raw=0xa7ce9  56                             push   esi
0x4a88ea raw=0xa7cea  51                             push   ecx
0x4a88eb raw=0xa7ceb  8930                           mov    DWORD PTR [eax],esi
0x4a88ed raw=0xa7ced  e8ae1c0000                     call   0x4aa5a0
0x4a88f2 raw=0xa7cf2  83c408                         add    esp,0x8
0x4a88f5 raw=0xa7cf5  50                             push   eax
0x4a88f6 raw=0xa7cf6  e8851d0000                     call   0x4aa680
0x4a88fb raw=0xa7cfb  50                             push   eax
0x4a88fc raw=0xa7cfc  e81f1e0000                     call   0x4aa720
0x4a8901 raw=0xa7d01  50                             push   eax
0x4a8902 raw=0xa7d02  e8b91e0000                     call   0x4aa7c0
0x4a8907 raw=0xa7d07  50                             push   eax
0x4a8908 raw=0xa7d08  e8531f0000                     call   0x4aa860
0x4a890d raw=0xa7d0d  50                             push   eax
0x4a890e raw=0xa7d0e  e8ed1f0000                     call   0x4aa900
0x4a8913 raw=0xa7d13  50                             push   eax
0x4a8914 raw=0xa7d14  e887200000                     call   0x4aa9a0
0x4a8919 raw=0xa7d19  50                             push   eax
0x4a891a raw=0xa7d1a  e821210000                     call   0x4aaa40
0x4a891f raw=0xa7d1f  50                             push   eax
0x4a8920 raw=0xa7d20  e8bb210000                     call   0x4aaae0
0x4a8925 raw=0xa7d25  50                             push   eax
0x4a8926 raw=0xa7d26  e855220000                     call   0x4aab80
0x4a892b raw=0xa7d2b  50                             push   eax
0x4a892c raw=0xa7d2c  e8ef220000                     call   0x4aac20
0x4a8931 raw=0xa7d31  50                             push   eax
0x4a8932 raw=0xa7d32  e889230000                     call   0x4aacc0
0x4a8937 raw=0xa7d37  50                             push   eax
0x4a8938 raw=0xa7d38  e823240000                     call   0x4aad60
0x4a893d raw=0xa7d3d  50                             push   eax
0x4a893e raw=0xa7d3e  e8bd240000                     call   0x4aae00
0x4a8943 raw=0xa7d43  50                             push   eax
0x4a8944 raw=0xa7d44  e857250000                     call   0x4aaea0
0x4a8949 raw=0xa7d49  50                             push   eax
0x4a894a raw=0xa7d4a  e8f1250000                     call   0x4aaf40
0x4a894f raw=0xa7d4f  50                             push   eax
0x4a8950 raw=0xa7d50  e88b260000                     call   0x4aafe0
0x4a8955 raw=0xa7d55  50                             push   eax
0x4a8956 raw=0xa7d56  e825270000                     call   0x4ab080
0x4a895b raw=0xa7d5b  50                             push   eax
0x4a895c raw=0xa7d5c  e8bf270000                     call   0x4ab120
0x4a8961 raw=0xa7d61  50                             push   eax
0x4a8962 raw=0xa7d62  e859280000                     call   0x4ab1c0
0x4a8967 raw=0xa7d67  50                             push   eax
0x4a8968 raw=0xa7d68  e8f3280000                     call   0x4ab260
0x4a896d raw=0xa7d6d  50                             push   eax
0x4a896e raw=0xa7d6e  e88d290000                     call   0x4ab300
0x4a8973 raw=0xa7d73  50                             push   eax
0x4a8974 raw=0xa7d74  e8272a0000                     call   0x4ab3a0
0x4a8979 raw=0xa7d79  50                             push   eax
0x4a897a raw=0xa7d7a  e8c12a0000                     call   0x4ab440
0x4a897f raw=0xa7d7f  50                             push   eax
0x4a8980 raw=0xa7d80  e85b2b0000                     call   0x4ab4e0
0x4a8985 raw=0xa7d85  50                             push   eax
0x4a8986 raw=0xa7d86  e8f52b0000                     call   0x4ab580
0x4a898b raw=0xa7d8b  50                             push   eax
0x4a898c raw=0xa7d8c  e88f2c0000                     call   0x4ab620
0x4a8991 raw=0xa7d91  50                             push   eax
0x4a8992 raw=0xa7d92  e8292d0000                     call   0x4ab6c0
0x4a8997 raw=0xa7d97  50                             push   eax
0x4a8998 raw=0xa7d98  e8c32d0000                     call   0x4ab760
0x4a899d raw=0xa7d9d  50                             push   eax
0x4a899e raw=0xa7d9e  e85d2e0000                     call   0x4ab800
0x4a89a3 raw=0xa7da3  50                             push   eax
0x4a89a4 raw=0xa7da4  e8f72e0000                     call   0x4ab8a0
0x4a89a9 raw=0xa7da9  50                             push   eax
0x4a89aa raw=0xa7daa  e8912f0000                     call   0x4ab940
0x4a89af raw=0xa7daf  686468c000                     push   0xc06864
0x4a89b4 raw=0xa7db4  8bce                           mov    ecx,esi
0x4a89b6 raw=0xa7db6  e895c02400                     call   0x6f4a50
0x4a89bb raw=0xa7dbb  8be5                           mov    esp,ebp
0x4a89bd raw=0xa7dbd  5d                             pop    ebp
0x4a89be raw=0xa7dbe  c3                             ret

; binding_q_root | Q normal 63 registrar calls and original qbase load
; VA 0x560600..0x5607c3 RAW 0x15fa00 len 451 SHA256 a3c5450ea3251f3054ea3867396b36851b2743317f2b9d645a2b1711a009dc61
0x560600 raw=0x15fa00  55                             push   ebp
0x560601 raw=0x15fa01  8bec                           mov    ebp,esp
0x560603 raw=0x15fa03  83ec08                         sub    esp,0x8
0x560606 raw=0x15fa06  8d4dfc                         lea    ecx,[ebp-0x4]
0x560609 raw=0x15fa09  56                             push   esi
0x56060a raw=0x15fa0a  51                             push   ecx
0x56060b raw=0x15fa0b  8930                           mov    DWORD PTR [eax],esi
0x56060d raw=0x15fa0d  e82e580000                     call   0x565e40
0x560612 raw=0x15fa12  83c408                         add    esp,0x8
0x560615 raw=0x15fa15  50                             push   eax
0x560616 raw=0x15fa16  e805590000                     call   0x565f20
0x56061b raw=0x15fa1b  50                             push   eax
0x56061c raw=0x15fa1c  e89f590000                     call   0x565fc0
0x560621 raw=0x15fa21  50                             push   eax
0x560622 raw=0x15fa22  e8395a0000                     call   0x566060
0x560627 raw=0x15fa27  50                             push   eax
0x560628 raw=0x15fa28  e8d35a0000                     call   0x566100
0x56062d raw=0x15fa2d  50                             push   eax
0x56062e raw=0x15fa2e  e86d5b0000                     call   0x5661a0
0x560633 raw=0x15fa33  50                             push   eax
0x560634 raw=0x15fa34  e8075c0000                     call   0x566240
0x560639 raw=0x15fa39  50                             push   eax
0x56063a raw=0x15fa3a  e8a15c0000                     call   0x5662e0
0x56063f raw=0x15fa3f  50                             push   eax
0x560640 raw=0x15fa40  e83b5d0000                     call   0x566380
0x560645 raw=0x15fa45  50                             push   eax
0x560646 raw=0x15fa46  e8d55d0000                     call   0x566420
0x56064b raw=0x15fa4b  50                             push   eax
0x56064c raw=0x15fa4c  e86f5e0000                     call   0x5664c0
0x560651 raw=0x15fa51  50                             push   eax
0x560652 raw=0x15fa52  e8095f0000                     call   0x566560
0x560657 raw=0x15fa57  50                             push   eax
0x560658 raw=0x15fa58  e8a35f0000                     call   0x566600
0x56065d raw=0x15fa5d  50                             push   eax
0x56065e raw=0x15fa5e  e83d600000                     call   0x5666a0
0x560663 raw=0x15fa63  50                             push   eax
0x560664 raw=0x15fa64  e8d7600000                     call   0x566740
0x560669 raw=0x15fa69  50                             push   eax
0x56066a raw=0x15fa6a  e871610000                     call   0x5667e0
0x56066f raw=0x15fa6f  50                             push   eax
0x560670 raw=0x15fa70  e80b620000                     call   0x566880
0x560675 raw=0x15fa75  50                             push   eax
0x560676 raw=0x15fa76  e8a5620000                     call   0x566920
0x56067b raw=0x15fa7b  50                             push   eax
0x56067c raw=0x15fa7c  e83f630000                     call   0x5669c0
0x560681 raw=0x15fa81  50                             push   eax
0x560682 raw=0x15fa82  e8d9630000                     call   0x566a60
0x560687 raw=0x15fa87  50                             push   eax
0x560688 raw=0x15fa88  e873640000                     call   0x566b00
0x56068d raw=0x15fa8d  50                             push   eax
0x56068e raw=0x15fa8e  e80d650000                     call   0x566ba0
0x560693 raw=0x15fa93  50                             push   eax
0x560694 raw=0x15fa94  e8a7650000                     call   0x566c40
0x560699 raw=0x15fa99  50                             push   eax
0x56069a raw=0x15fa9a  e841660000                     call   0x566ce0
0x56069f raw=0x15fa9f  50                             push   eax
0x5606a0 raw=0x15faa0  e8db660000                     call   0x566d80
0x5606a5 raw=0x15faa5  50                             push   eax
0x5606a6 raw=0x15faa6  e875670000                     call   0x566e20
0x5606ab raw=0x15faab  50                             push   eax
0x5606ac raw=0x15faac  e80f680000                     call   0x566ec0
0x5606b1 raw=0x15fab1  50                             push   eax
0x5606b2 raw=0x15fab2  e8a9680000                     call   0x566f60
0x5606b7 raw=0x15fab7  50                             push   eax
0x5606b8 raw=0x15fab8  e843690000                     call   0x567000
0x5606bd raw=0x15fabd  50                             push   eax
0x5606be raw=0x15fabe  e8dd690000                     call   0x5670a0
0x5606c3 raw=0x15fac3  50                             push   eax
0x5606c4 raw=0x15fac4  e8776a0000                     call   0x567140
0x5606c9 raw=0x15fac9  50                             push   eax
0x5606ca raw=0x15faca  e8116b0000                     call   0x5671e0
0x5606cf raw=0x15facf  50                             push   eax
0x5606d0 raw=0x15fad0  e8ab6b0000                     call   0x567280
0x5606d5 raw=0x15fad5  50                             push   eax
0x5606d6 raw=0x15fad6  e8456c0000                     call   0x567320
0x5606db raw=0x15fadb  50                             push   eax
0x5606dc raw=0x15fadc  e8df6c0000                     call   0x5673c0
0x5606e1 raw=0x15fae1  50                             push   eax
0x5606e2 raw=0x15fae2  e8796d0000                     call   0x567460
0x5606e7 raw=0x15fae7  50                             push   eax
0x5606e8 raw=0x15fae8  e8136e0000                     call   0x567500
0x5606ed raw=0x15faed  50                             push   eax
0x5606ee raw=0x15faee  e8ad6e0000                     call   0x5675a0
0x5606f3 raw=0x15faf3  50                             push   eax
0x5606f4 raw=0x15faf4  e8476f0000                     call   0x567640
0x5606f9 raw=0x15faf9  50                             push   eax
0x5606fa raw=0x15fafa  e8e16f0000                     call   0x5676e0
0x5606ff raw=0x15faff  50                             push   eax
0x560700 raw=0x15fb00  e87b700000                     call   0x567780
0x560705 raw=0x15fb05  50                             push   eax
0x560706 raw=0x15fb06  e815710000                     call   0x567820
0x56070b raw=0x15fb0b  50                             push   eax
0x56070c raw=0x15fb0c  e8af710000                     call   0x5678c0
0x560711 raw=0x15fb11  50                             push   eax
0x560712 raw=0x15fb12  e849720000                     call   0x567960
0x560717 raw=0x15fb17  50                             push   eax
0x560718 raw=0x15fb18  e8e3720000                     call   0x567a00
0x56071d raw=0x15fb1d  50                             push   eax
0x56071e raw=0x15fb1e  e87d730000                     call   0x567aa0
0x560723 raw=0x15fb23  50                             push   eax
0x560724 raw=0x15fb24  e817740000                     call   0x567b40
0x560729 raw=0x15fb29  50                             push   eax
0x56072a raw=0x15fb2a  e8b1740000                     call   0x567be0
0x56072f raw=0x15fb2f  50                             push   eax
0x560730 raw=0x15fb30  e84b750000                     call   0x567c80
0x560735 raw=0x15fb35  50                             push   eax
0x560736 raw=0x15fb36  e8e5750000                     call   0x567d20
0x56073b raw=0x15fb3b  50                             push   eax
0x56073c raw=0x15fb3c  e87f760000                     call   0x567dc0
0x560741 raw=0x15fb41  50                             push   eax
0x560742 raw=0x15fb42  e819770000                     call   0x567e60
0x560747 raw=0x15fb47  50                             push   eax
0x560748 raw=0x15fb48  e8b3770000                     call   0x567f00
0x56074d raw=0x15fb4d  50                             push   eax
0x56074e raw=0x15fb4e  e84d780000                     call   0x567fa0
0x560753 raw=0x15fb53  50                             push   eax
0x560754 raw=0x15fb54  e8e7780000                     call   0x568040
0x560759 raw=0x15fb59  50                             push   eax
0x56075a raw=0x15fb5a  e881790000                     call   0x5680e0
0x56075f raw=0x15fb5f  50                             push   eax
0x560760 raw=0x15fb60  e81b7a0000                     call   0x568180
0x560765 raw=0x15fb65  50                             push   eax
0x560766 raw=0x15fb66  e8b57a0000                     call   0x568220
0x56076b raw=0x15fb6b  50                             push   eax
0x56076c raw=0x15fb6c  e84f7b0000                     call   0x5682c0
0x560771 raw=0x15fb71  50                             push   eax
0x560772 raw=0x15fb72  e8e97b0000                     call   0x568360
0x560777 raw=0x15fb77  50                             push   eax
0x560778 raw=0x15fb78  e8837c0000                     call   0x568400
0x56077d raw=0x15fb7d  50                             push   eax
0x56077e raw=0x15fb7e  e81d7d0000                     call   0x5684a0
0x560783 raw=0x15fb83  50                             push   eax
0x560784 raw=0x15fb84  e8b77d0000                     call   0x568540
0x560789 raw=0x15fb89  50                             push   eax
0x56078a raw=0x15fb8a  e8517e0000                     call   0x5685e0
0x56078f raw=0x15fb8f  68c855c000                     push   0xc055c8
0x560794 raw=0x15fb94  8bce                           mov    ecx,esi
0x560796 raw=0x15fb96  e8b5421900                     call   0x6f4a50
0x56079b raw=0x15fb9b  68b055c000                     push   0xc055b0
0x5607a0 raw=0x15fba0  8bce                           mov    ecx,esi
0x5607a2 raw=0x15fba2  e8a9421900                     call   0x6f4a50
0x5607a7 raw=0x15fba7  68bc55c000                     push   0xc055bc
0x5607ac raw=0x15fbac  8bce                           mov    ecx,esi
0x5607ae raw=0x15fbae  e89d421900                     call   0x6f4a50
0x5607b3 raw=0x15fbb3  685806c100                     push   0xc10658
0x5607b8 raw=0x15fbb8  8bce                           mov    ecx,esi
0x5607ba raw=0x15fbba  e891421900                     call   0x6f4a50
0x5607bf raw=0x15fbbf  8be5                           mov    esp,ebp
0x5607c1 raw=0x15fbc1  5d                             pop    ebp
0x5607c2 raw=0x15fbc2  c3                             ret

; binding_q_namespace | normal Q owner FE2778 and VM wrapper FE2774; Rebind not used
; VA 0x565e40..0x565f15 RAW 0x165240 len 213 SHA256 8799844b6771a4b2652be2e4442053f1058ba8213881942a991e94945038efdb
0x565e40 raw=0x165240  55                             push   ebp
0x565e41 raw=0x165241  8bec                           mov    ebp,esp
0x565e43 raw=0x165243  51                             push   ecx
0x565e44 raw=0x165244  53                             push   ebx
0x565e45 raw=0x165245  8b5d0c                         mov    ebx,DWORD PTR [ebp+0xc]
0x565e48 raw=0x165248  56                             push   esi
0x565e49 raw=0x165249  8b33                           mov    esi,DWORD PTR [ebx]
0x565e4b raw=0x16524b  a37827fe00                     mov    ds:0xfe2778,eax
0x565e50 raw=0x165250  8b4610                         mov    eax,DWORD PTR [esi+0x10]
0x565e53 raw=0x165253  8b4844                         mov    ecx,DWORD PTR [eax+0x44]
0x565e56 raw=0x165256  57                             push   edi
0x565e57 raw=0x165257  891d7427fe00                   mov    DWORD PTR ds:0xfe2774,ebx
0x565e5d raw=0x16525d  3b4840                         cmp    ecx,DWORD PTR [eax+0x40]
0x565e60 raw=0x165260  7207                           jb     0x565e69
0x565e62 raw=0x165262  8bc6                           mov    eax,esi
0x565e64 raw=0x165264  e837551900                     call   0x6fb3a0
0x565e69 raw=0x165269  8b7e08                         mov    edi,DWORD PTR [esi+0x8]
0x565e6c raw=0x16526c  6a00                           push   0x0
0x565e6e raw=0x16526e  6a00                           push   0x0
0x565e70 raw=0x165270  56                             push   esi
0x565e71 raw=0x165271  e82a3b1900                     call   0x6f99a0
0x565e76 raw=0x165276  8907                           mov    DWORD PTR [edi],eax
0x565e78 raw=0x165278  c7470805000000                 mov    DWORD PTR [edi+0x8],0x5
0x565e7f raw=0x16527f  83460810                       add    DWORD PTR [esi+0x8],0x10
0x565e83 raw=0x165283  8b33                           mov    esi,DWORD PTR [ebx]
0x565e85 raw=0x165285  83c40c                         add    esp,0xc
0x565e88 raw=0x165288  bf0406c100                     mov    edi,0xc10604
0x565e8d raw=0x16528d  b8eed8ffff                     mov    eax,0xffffd8ee
0x565e92 raw=0x165292  e8f9f81800                     call   0x6f5790
0x565e97 raw=0x165297  8b33                           mov    esi,DWORD PTR [ebx]
0x565e99 raw=0x165299  b8eed8ffff                     mov    eax,0xffffd8ee
0x565e9e raw=0x16529e  e8ddf71800                     call   0x6f5680
0x565ea3 raw=0x1652a3  8b03                           mov    eax,DWORD PTR [ebx]
0x565ea5 raw=0x1652a5  8b4008                         mov    eax,DWORD PTR [eax+0x8]
0x565ea8 raw=0x1652a8  83e810                         sub    eax,0x10
0x565eab raw=0x1652ab  bff0ffffff                     mov    edi,0xfffffff0
0x565eb0 raw=0x1652b0  3dc8bfc000                     cmp    eax,0xc0bfc8
0x565eb5 raw=0x1652b5  7406                           je     0x565ebd
0x565eb7 raw=0x1652b7  83780805                       cmp    DWORD PTR [eax+0x8],0x5
0x565ebb raw=0x1652bb  7417                           je     0x565ed4
0x565ebd raw=0x1652bd  680406c100                     push   0xc10604
0x565ec2 raw=0x1652c2  68c426c400                     push   0xc426c4
0x565ec7 raw=0x1652c7  e8f1d13200                     call   0x8930bd
0x565ecc raw=0x1652cc  8b03                           mov    eax,DWORD PTR [ebx]
0x565ece raw=0x1652ce  83c408                         add    esp,0x8
0x565ed1 raw=0x1652d1  017808                         add    DWORD PTR [eax+0x8],edi
0x565ed4 raw=0x1652d4  8b33                           mov    esi,DWORD PTR [ebx]
0x565ed6 raw=0x1652d6  682462c000                     push   0xc06224
0x565edb raw=0x1652db  e830f61800                     call   0x6f5510
0x565ee0 raw=0x1652e0  8b33                           mov    esi,DWORD PTR [ebx]
0x565ee2 raw=0x1652e2  83c404                         add    esp,0x4
0x565ee5 raw=0x1652e5  6a00                           push   0x0
0x565ee7 raw=0x1652e7  6890875600                     push   0x568790
0x565eec raw=0x1652ec  e8bff61800                     call   0x6f55b0
0x565ef1 raw=0x1652f1  8b13                           mov    edx,DWORD PTR [ebx]
0x565ef3 raw=0x1652f3  52                             push   edx
0x565ef4 raw=0x1652f4  b8fdffffff                     mov    eax,0xfffffffd
0x565ef9 raw=0x1652f9  e8f2f81800                     call   0x6f57f0
0x565efe raw=0x1652fe  8b1b                           mov    ebx,DWORD PTR [ebx]
0x565f00 raw=0x165300  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x565f03 raw=0x165303  83c40c                         add    esp,0xc
0x565f06 raw=0x165306  017b08                         add    DWORD PTR [ebx+0x8],edi
0x565f09 raw=0x165309  5f                             pop    edi
0x565f0a raw=0x16530a  5e                             pop    esi
0x565f0b raw=0x16530b  c7000406c100                   mov    DWORD PTR [eax],0xc10604
0x565f11 raw=0x165311  5b                             pop    ebx
0x565f12 raw=0x165312  59                             pop    ecx
0x565f13 raw=0x165313  5d                             pop    ebp
0x565f14 raw=0x165314  c3                             ret

; binding_prolog_namespace | Prolog owner FE2768=FC1B18; namespace binds shared wrapper
; VA 0x55fd70..0x55fe4a RAW 0x15f170 len 218 SHA256 a28b1f52e399e4e3862d8fc050c9c26117ed32943a1a13024949fb6d58f5c0e2
0x55fd70 raw=0x15f170  55                             push   ebp
0x55fd71 raw=0x15f171  8bec                           mov    ebp,esp
0x55fd73 raw=0x15f173  51                             push   ecx
0x55fd74 raw=0x15f174  53                             push   ebx
0x55fd75 raw=0x15f175  8b5d0c                         mov    ebx,DWORD PTR [ebp+0xc]
0x55fd78 raw=0x15f178  56                             push   esi
0x55fd79 raw=0x15f179  8b33                           mov    esi,DWORD PTR [ebx]
0x55fd7b raw=0x15f17b  8b4610                         mov    eax,DWORD PTR [esi+0x10]
0x55fd7e raw=0x15f17e  8b4844                         mov    ecx,DWORD PTR [eax+0x44]
0x55fd81 raw=0x15f181  57                             push   edi
0x55fd82 raw=0x15f182  891d6427fe00                   mov    DWORD PTR ds:0xfe2764,ebx
0x55fd88 raw=0x15f188  c7056827fe00181bfc00           mov    DWORD PTR ds:0xfe2768,0xfc1b18
0x55fd92 raw=0x15f192  3b4840                         cmp    ecx,DWORD PTR [eax+0x40]
0x55fd95 raw=0x15f195  7207                           jb     0x55fd9e
0x55fd97 raw=0x15f197  8bc6                           mov    eax,esi
0x55fd99 raw=0x15f199  e802b61900                     call   0x6fb3a0
0x55fd9e raw=0x15f19e  8b7e08                         mov    edi,DWORD PTR [esi+0x8]
0x55fda1 raw=0x15f1a1  6a00                           push   0x0
0x55fda3 raw=0x15f1a3  6a00                           push   0x0
0x55fda5 raw=0x15f1a5  56                             push   esi
0x55fda6 raw=0x15f1a6  e8f59b1900                     call   0x6f99a0
0x55fdab raw=0x15f1ab  8907                           mov    DWORD PTR [edi],eax
0x55fdad raw=0x15f1ad  c7470805000000                 mov    DWORD PTR [edi+0x8],0x5
0x55fdb4 raw=0x15f1b4  83460810                       add    DWORD PTR [esi+0x8],0x10
0x55fdb8 raw=0x15f1b8  8b33                           mov    esi,DWORD PTR [ebx]
0x55fdba raw=0x15f1ba  83c40c                         add    esp,0xc
0x55fdbd raw=0x15f1bd  bf94e2c000                     mov    edi,0xc0e294
0x55fdc2 raw=0x15f1c2  b8eed8ffff                     mov    eax,0xffffd8ee
0x55fdc7 raw=0x15f1c7  e8c4591900                     call   0x6f5790
0x55fdcc raw=0x15f1cc  8b33                           mov    esi,DWORD PTR [ebx]
0x55fdce raw=0x15f1ce  b8eed8ffff                     mov    eax,0xffffd8ee
0x55fdd3 raw=0x15f1d3  e8a8581900                     call   0x6f5680
0x55fdd8 raw=0x15f1d8  8b03                           mov    eax,DWORD PTR [ebx]
0x55fdda raw=0x15f1da  8b4008                         mov    eax,DWORD PTR [eax+0x8]
0x55fddd raw=0x15f1dd  83e810                         sub    eax,0x10
0x55fde0 raw=0x15f1e0  bff0ffffff                     mov    edi,0xfffffff0
0x55fde5 raw=0x15f1e5  3dc8bfc000                     cmp    eax,0xc0bfc8
0x55fdea raw=0x15f1ea  7406                           je     0x55fdf2
0x55fdec raw=0x15f1ec  83780805                       cmp    DWORD PTR [eax+0x8],0x5
0x55fdf0 raw=0x15f1f0  7417                           je     0x55fe09
0x55fdf2 raw=0x15f1f2  6894e2c000                     push   0xc0e294
0x55fdf7 raw=0x15f1f7  68c426c400                     push   0xc426c4
0x55fdfc raw=0x15f1fc  e8bc323300                     call   0x8930bd
0x55fe01 raw=0x15f201  8b03                           mov    eax,DWORD PTR [ebx]
0x55fe03 raw=0x15f203  83c408                         add    esp,0x8
0x55fe06 raw=0x15f206  017808                         add    DWORD PTR [eax+0x8],edi
0x55fe09 raw=0x15f209  8b33                           mov    esi,DWORD PTR [ebx]
0x55fe0b raw=0x15f20b  682462c000                     push   0xc06224
0x55fe10 raw=0x15f210  e8fb561900                     call   0x6f5510
0x55fe15 raw=0x15f215  8b33                           mov    esi,DWORD PTR [ebx]
0x55fe17 raw=0x15f217  83c404                         add    esp,0x4
0x55fe1a raw=0x15f21a  6a00                           push   0x0
0x55fe1c raw=0x15f21c  68f0fe5500                     push   0x55fef0
0x55fe21 raw=0x15f221  e88a571900                     call   0x6f55b0
0x55fe26 raw=0x15f226  8b13                           mov    edx,DWORD PTR [ebx]
0x55fe28 raw=0x15f228  52                             push   edx
0x55fe29 raw=0x15f229  b8fdffffff                     mov    eax,0xfffffffd
0x55fe2e raw=0x15f22e  e8bd591900                     call   0x6f57f0
0x55fe33 raw=0x15f233  8b1b                           mov    ebx,DWORD PTR [ebx]
0x55fe35 raw=0x15f235  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x55fe38 raw=0x15f238  83c40c                         add    esp,0xc
0x55fe3b raw=0x15f23b  017b08                         add    DWORD PTR [ebx+0x8],edi
0x55fe3e raw=0x15f23e  5f                             pop    edi
0x55fe3f raw=0x15f23f  5e                             pop    esi
0x55fe40 raw=0x15f240  c70094e2c000                   mov    DWORD PTR [eax],0xc0e294
0x55fe46 raw=0x15f246  5b                             pop    ebx
0x55fe47 raw=0x15f247  59                             pop    ecx
0x55fe48 raw=0x15f248  5d                             pop    ebp
0x55fe49 raw=0x15f249  c3                             ret

; prolog_constructor | initialize active0, dialog queue/table and public Prolog.OnClose
; VA 0x55ee90..0x55f0fd RAW 0x15e290 len 621 SHA256 05c15b1d37c6269648c2139f0604509b0d8724cb65905a4c60d7a0a40b35a111
0x55ee90 raw=0x15e290  55                             push   ebp
0x55ee91 raw=0x15e291  8bec                           mov    ebp,esp
0x55ee93 raw=0x15e293  6aff                           push   0xffffffff
0x55ee95 raw=0x15e295  6845a89300                     push   0x93a845
0x55ee9a raw=0x15e29a  64a100000000                   mov    eax,fs:0x0
0x55eea0 raw=0x15e2a0  50                             push   eax
0x55eea1 raw=0x15e2a1  81ec80000000                   sub    esp,0x80
0x55eea7 raw=0x15e2a7  a1201fd600                     mov    eax,ds:0xd61f20
0x55eeac raw=0x15e2ac  33c5                           xor    eax,ebp
0x55eeae raw=0x15e2ae  8945f0                         mov    DWORD PTR [ebp-0x10],eax
0x55eeb1 raw=0x15e2b1  53                             push   ebx
0x55eeb2 raw=0x15e2b2  56                             push   esi
0x55eeb3 raw=0x15e2b3  50                             push   eax
0x55eeb4 raw=0x15e2b4  8d45f4                         lea    eax,[ebp-0xc]
0x55eeb7 raw=0x15e2b7  64a300000000                   mov    fs:0x0,eax
0x55eebd raw=0x15e2bd  33f6                           xor    esi,esi
0x55eebf raw=0x15e2bf  6a08                           push   0x8
0x55eec1 raw=0x15e2c1  c78578ffffff181bfc00           mov    DWORD PTR [ebp-0x88],0xfc1b18
0x55eecb raw=0x15e2cb  8935201bfc00                   mov    DWORD PTR ds:0xfc1b20,esi
0x55eed1 raw=0x15e2d1  8935241bfc00                   mov    DWORD PTR ds:0xfc1b24,esi
0x55eed7 raw=0x15e2d7  e88c233300                     call   0x891268
0x55eedc raw=0x15e2dc  83c404                         add    esp,0x4
0x55eedf raw=0x15e2df  3bc6                           cmp    eax,esi
0x55eee1 raw=0x15e2e1  0f84f2010000                   je     0x55f0d9
0x55eee7 raw=0x15e2e7  a3241bfc00                     mov    ds:0xfc1b24,eax
0x55eeec raw=0x15e2ec  33c9                           xor    ecx,ecx
0x55eeee raw=0x15e2ee  8908                           mov    DWORD PTR [eax],ecx
0x55eef0 raw=0x15e2f0  33d2                           xor    edx,edx
0x55eef2 raw=0x15e2f2  895004                         mov    DWORD PTR [eax+0x4],edx
0x55eef5 raw=0x15e2f5  a1241bfc00                     mov    eax,ds:0xfc1b24
0x55eefa raw=0x15e2fa  c700241bfc00                   mov    DWORD PTR [eax],0xfc1b24
0x55ef00 raw=0x15e300  8935281bfc00                   mov    DWORD PTR ds:0xfc1b28,esi
0x55ef06 raw=0x15e306  89352c1bfc00                   mov    DWORD PTR ds:0xfc1b2c,esi
0x55ef0c raw=0x15e30c  8935301bfc00                   mov    DWORD PTR ds:0xfc1b30,esi
0x55ef12 raw=0x15e312  8935341bfc00                   mov    DWORD PTR ds:0xfc1b34,esi
0x55ef18 raw=0x15e318  8975fc                         mov    DWORD PTR [ebp-0x4],esi
0x55ef1b raw=0x15e31b  6a18                           push   0x18
0x55ef1d raw=0x15e31d  89353c1bfc00                   mov    DWORD PTR ds:0xfc1b3c,esi
0x55ef23 raw=0x15e323  8935401bfc00                   mov    DWORD PTR ds:0xfc1b40,esi
0x55ef29 raw=0x15e329  8935441bfc00                   mov    DWORD PTR ds:0xfc1b44,esi
0x55ef2f raw=0x15e32f  c705481bfc0000040000           mov    DWORD PTR ds:0xfc1b48,0x400
0x55ef39 raw=0x15e339  c7054c1bfc0000030000           mov    DWORD PTR ds:0xfc1b4c,0x300
0x55ef43 raw=0x15e343  c705541bfc00bce2c000           mov    DWORD PTR ds:0xfc1b54,0xc0e2bc
0x55ef4d raw=0x15e34d  8935601bfc00                   mov    DWORD PTR ds:0xfc1b60,esi
0x55ef53 raw=0x15e353  e810233300                     call   0x891268
0x55ef58 raw=0x15e358  83c404                         add    esp,0x4
0x55ef5b raw=0x15e35b  3bc6                           cmp    eax,esi
0x55ef5d raw=0x15e35d  0f8449010000                   je     0x55f0ac
0x55ef63 raw=0x15e363  a35c1bfc00                     mov    ds:0xfc1b5c,eax
0x55ef68 raw=0x15e368  8900                           mov    DWORD PTR [eax],eax
0x55ef6a raw=0x15e36a  a15c1bfc00                     mov    eax,ds:0xfc1b5c
0x55ef6f raw=0x15e36f  894004                         mov    DWORD PTR [eax+0x4],eax
0x55ef72 raw=0x15e372  a15c1bfc00                     mov    eax,ds:0xfc1b5c
0x55ef77 raw=0x15e377  894008                         mov    DWORD PTR [eax+0x8],eax
0x55ef7a raw=0x15e37a  8b0d5c1bfc00                   mov    ecx,DWORD PTR ds:0xfc1b5c
0x55ef80 raw=0x15e380  bb01000000                     mov    ebx,0x1
0x55ef85 raw=0x15e385  885914                         mov    BYTE PTR [ecx+0x14],bl
0x55ef88 raw=0x15e388  8b155c1bfc00                   mov    edx,DWORD PTR ds:0xfc1b5c
0x55ef8e raw=0x15e38e  885a15                         mov    BYTE PTR [edx+0x15],bl
0x55ef91 raw=0x15e391  885dfc                         mov    BYTE PTR [ebp-0x4],bl
0x55ef94 raw=0x15e394  0f57c0                         xorps  xmm0,xmm0
0x55ef97 raw=0x15e397  f30f100dc056c400               movss  xmm1,DWORD PTR ds:0xc456c0
0x55ef9f raw=0x15e39f  6a40                           push   0x40
0x55efa1 raw=0x15e3a1  8d45a0                         lea    eax,[ebp-0x60]
0x55efa4 raw=0x15e3a4  56                             push   esi
0x55efa5 raw=0x15e3a5  50                             push   eax
0x55efa6 raw=0x15e3a6  f30f1105681bfc00               movss  DWORD PTR ds:0xfc1b68,xmm0
0x55efae raw=0x15e3ae  f30f110d6c1bfc00               movss  DWORD PTR ds:0xfc1b6c,xmm1
0x55efb6 raw=0x15e3b6  f30f1105701bfc00               movss  DWORD PTR ds:0xfc1b70,xmm0
0x55efbe raw=0x15e3be  8935741bfc00                   mov    DWORD PTR ds:0xfc1b74,esi
0x55efc4 raw=0x15e3c4  f30f110d781bfc00               movss  DWORD PTR ds:0xfc1b78,xmm1
0x55efcc raw=0x15e3cc  f30f11057c1bfc00               movss  DWORD PTR ds:0xfc1b7c,xmm0
0x55efd4 raw=0x15e3d4  f30f110d801bfc00               movss  DWORD PTR ds:0xfc1b80,xmm1
0x55efdc raw=0x15e3dc  8935841bfc00                   mov    DWORD PTR ds:0xfc1b84,esi
0x55efe2 raw=0x15e3e2  8935181bfc00                   mov    DWORD PTR ds:0xfc1b18,esi
0x55efe8 raw=0x15e3e8  8975e0                         mov    DWORD PTR [ebp-0x20],esi
0x55efeb raw=0x15e3eb  e870f83300                     call   0x89e860
0x55eff0 raw=0x15e3f0  8b0d3ca2d600                   mov    ecx,DWORD PTR ds:0xd6a23c
0x55eff6 raw=0x15e3f6  83c40c                         add    esp,0xc
0x55eff9 raw=0x15e3f9  51                             push   ecx
0x55effa raw=0x15e3fa  8d55a0                         lea    edx,[ebp-0x60]
0x55effd raw=0x15e3fd  6a20                           push   0x20
0x55efff raw=0x15e3ff  52                             push   edx
0x55f000 raw=0x15e400  c745e41a000000                 mov    DWORD PTR [ebp-0x1c],0x1a
0x55f007 raw=0x15e407  c745e804000000                 mov    DWORD PTR [ebp-0x18],0x4
0x55f00e raw=0x15e40e  895dec                         mov    DWORD PTR [ebp-0x14],ebx
0x55f011 raw=0x15e411  e8373e3300                     call   0x892e4d
0x55f016 raw=0x15e416  83c40c                         add    esp,0xc
0x55f019 raw=0x15e419  6a50                           push   0x50
0x55f01b raw=0x15e41b  e848223300                     call   0x891268
0x55f020 raw=0x15e420  83c404                         add    esp,0x4
0x55f023 raw=0x15e423  89459c                         mov    DWORD PTR [ebp-0x64],eax
0x55f026 raw=0x15e426  c645fc02                       mov    BYTE PTR [ebp-0x4],0x2
0x55f02a raw=0x15e42a  3bc6                           cmp    eax,esi
0x55f02c raw=0x15e42c  740c                           je     0x55f03a
0x55f02e raw=0x15e42e  8d4da0                         lea    ecx,[ebp-0x60]
0x55f031 raw=0x15e431  51                             push   ecx
0x55f032 raw=0x15e432  50                             push   eax
0x55f033 raw=0x15e433  e838d50000                     call   0x56c570
0x55f038 raw=0x15e438  eb02                           jmp    0x55f03c
0x55f03a raw=0x15e43a  33c0                           xor    eax,eax
0x55f03c raw=0x15e43c  885dfc                         mov    BYTE PTR [ebp-0x4],bl
0x55f03f raw=0x15e43f  a31c1bfc00                     mov    ds:0xfc1b1c,eax
0x55f044 raw=0x15e444  841dd4f3fd00                   test   BYTE PTR ds:0xfdf3d4,bl
0x55f04a raw=0x15e44a  751f                           jne    0x55f06b
0x55f04c raw=0x15e44c  091dd4f3fd00                   or     DWORD PTR ds:0xfdf3d4,ebx
0x55f052 raw=0x15e452  c645fc03                       mov    BYTE PTR [ebp-0x4],0x3
0x55f056 raw=0x15e456  e825531900                     call   0x6f4380
0x55f05b raw=0x15e45b  68d0e6bc00                     push   0xbce6d0
0x55f060 raw=0x15e460  e8b5323300                     call   0x89231a
0x55f065 raw=0x15e465  83c404                         add    esp,0x4
0x55f068 raw=0x15e468  885dfc                         mov    BYTE PTR [ebp-0x4],bl
0x55f06b raw=0x15e46b  8d5594                         lea    edx,[ebp-0x6c]
0x55f06e raw=0x15e46e  68c8f3fd00                     push   0xfdf3c8
0x55f073 raw=0x15e473  52                             push   edx
0x55f074 raw=0x15e474  e8f70c0000                     call   0x55fd70
0x55f079 raw=0x15e479  83c408                         add    esp,0x8
0x55f07c raw=0x15e47c  50                             push   eax
0x55f07d raw=0x15e47d  e8ce0d0000                     call   0x55fe50
0x55f082 raw=0x15e482  68541bfc00                     push   0xfc1b54
0x55f087 raw=0x15e487  e8d444fbff                     call   0x513560
0x55f08c raw=0x15e48c  b8181bfc00                     mov    eax,0xfc1b18
0x55f091 raw=0x15e491  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x55f094 raw=0x15e494  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x55f09b raw=0x15e49b  59                             pop    ecx
0x55f09c raw=0x15e49c  5e                             pop    esi
0x55f09d raw=0x15e49d  5b                             pop    ebx
0x55f09e raw=0x15e49e  8b4df0                         mov    ecx,DWORD PTR [ebp-0x10]
0x55f0a1 raw=0x15e4a1  33cd                           xor    ecx,ebp
0x55f0a3 raw=0x15e4a3  e8591f3300                     call   0x891001
0x55f0a8 raw=0x15e4a8  8be5                           mov    esp,ebp
0x55f0aa raw=0x15e4aa  5d                             pop    ebp
0x55f0ab raw=0x15e4ab  c3                             ret
0x55f0ac raw=0x15e4ac  8d4598                         lea    eax,[ebp-0x68]
0x55f0af raw=0x15e4af  50                             push   eax
0x55f0b0 raw=0x15e4b0  8d8d7cffffff                   lea    ecx,[ebp-0x84]
0x55f0b6 raw=0x15e4b6  897598                         mov    DWORD PTR [ebp-0x68],esi
0x55f0b9 raw=0x15e4b9  e8eb1f3300                     call   0x8910a9
0x55f0be raw=0x15e4be  68a857c800                     push   0xc857a8
0x55f0c3 raw=0x15e4c3  8d8d7cffffff                   lea    ecx,[ebp-0x84]
0x55f0c9 raw=0x15e4c9  51                             push   ecx
0x55f0ca raw=0x15e4ca  c7857cffffffa42cbd00           mov    DWORD PTR [ebp-0x84],0xbd2ca4
0x55f0d4 raw=0x15e4d4  e817d93300                     call   0x89c9f0
0x55f0d9 raw=0x15e4d9  8d559c                         lea    edx,[ebp-0x64]
0x55f0dc raw=0x15e4dc  52                             push   edx
0x55f0dd raw=0x15e4dd  8d4d88                         lea    ecx,[ebp-0x78]
0x55f0e0 raw=0x15e4e0  89759c                         mov    DWORD PTR [ebp-0x64],esi
0x55f0e3 raw=0x15e4e3  e8c11f3300                     call   0x8910a9
0x55f0e8 raw=0x15e4e8  68a857c800                     push   0xc857a8
0x55f0ed raw=0x15e4ed  8d4588                         lea    eax,[ebp-0x78]
0x55f0f0 raw=0x15e4f0  50                             push   eax
0x55f0f1 raw=0x15e4f1  c74588a42cbd00                 mov    DWORD PTR [ebp-0x78],0xbd2ca4
0x55f0f8 raw=0x15e4f8  e8f3d83300                     call   0x89c9f0

; binding_prolog_onclose | OnClose native-slot/name/closure registration
; VA 0x55fe50..0x55fee9 RAW 0x15f250 len 153 SHA256 42a1890c9b47f345d3aeb81cef064c928bb31ad5684638e52b369dc8ec8e31f6
0x55fe50 raw=0x15f250  55                             push   ebp
0x55fe51 raw=0x15f251  8bec                           mov    ebp,esp
0x55fe53 raw=0x15f253  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x55fe56 raw=0x15f256  53                             push   ebx
0x55fe57 raw=0x15f257  8b1d6427fe00                   mov    ebx,DWORD PTR ds:0xfe2764
0x55fe5d raw=0x15f25d  56                             push   esi
0x55fe5e raw=0x15f25e  8b33                           mov    esi,DWORD PTR [ebx]
0x55fe60 raw=0x15f260  57                             push   edi
0x55fe61 raw=0x15f261  8b38                           mov    edi,DWORD PTR [eax]
0x55fe63 raw=0x15f263  b8eed8ffff                     mov    eax,0xffffd8ee
0x55fe68 raw=0x15f268  c7056c27fe0050f95500           mov    DWORD PTR ds:0xfe276c,0x55f950
0x55fe72 raw=0x15f272  e809581900                     call   0x6f5680
0x55fe77 raw=0x15f277  8b03                           mov    eax,DWORD PTR [ebx]
0x55fe79 raw=0x15f279  8b4008                         mov    eax,DWORD PTR [eax+0x8]
0x55fe7c raw=0x15f27c  83e810                         sub    eax,0x10
0x55fe7f raw=0x15f27f  3dc8bfc000                     cmp    eax,0xc0bfc8
0x55fe84 raw=0x15f284  7406                           je     0x55fe8c
0x55fe86 raw=0x15f286  83780805                       cmp    DWORD PTR [eax+0x8],0x5
0x55fe8a raw=0x15f28a  7414                           je     0x55fea0
0x55fe8c raw=0x15f28c  57                             push   edi
0x55fe8d raw=0x15f28d  68c426c400                     push   0xc426c4
0x55fe92 raw=0x15f292  e826323300                     call   0x8930bd
0x55fe97 raw=0x15f297  8b1b                           mov    ebx,DWORD PTR [ebx]
0x55fe99 raw=0x15f299  83c408                         add    esp,0x8
0x55fe9c raw=0x15f29c  834308f0                       add    DWORD PTR [ebx+0x8],0xfffffff0
0x55fea0 raw=0x15f2a0  8b3d6427fe00                   mov    edi,DWORD PTR ds:0xfe2764
0x55fea6 raw=0x15f2a6  8b37                           mov    esi,DWORD PTR [edi]
0x55fea8 raw=0x15f2a8  68bca5d600                     push   0xd6a5bc
0x55fead raw=0x15f2ad  e85e561900                     call   0x6f5510
0x55feb2 raw=0x15f2b2  8b37                           mov    esi,DWORD PTR [edi]
0x55feb4 raw=0x15f2b4  83c404                         add    esp,0x4
0x55feb7 raw=0x15f2b7  6a00                           push   0x0
0x55feb9 raw=0x15f2b9  6810ff5500                     push   0x55ff10
0x55febe raw=0x15f2be  e8ed561900                     call   0x6f55b0
0x55fec3 raw=0x15f2c3  8b0f                           mov    ecx,DWORD PTR [edi]
0x55fec5 raw=0x15f2c5  51                             push   ecx
0x55fec6 raw=0x15f2c6  b8fdffffff                     mov    eax,0xfffffffd
0x55fecb raw=0x15f2cb  e820591900                     call   0x6f57f0
0x55fed0 raw=0x15f2d0  8b156427fe00                   mov    edx,DWORD PTR ds:0xfe2764
0x55fed6 raw=0x15f2d6  8b02                           mov    eax,DWORD PTR [edx]
0x55fed8 raw=0x15f2d8  83c40c                         add    esp,0xc
0x55fedb raw=0x15f2db  834008f0                       add    DWORD PTR [eax+0x8],0xfffffff0
0x55fedf raw=0x15f2df  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x55fee2 raw=0x15f2e2  5f                             pop    edi
0x55fee3 raw=0x15f2e3  5e                             pop    esi
0x55fee4 raw=0x15f2e4  5b                             pop    ebx
0x55fee5 raw=0x15f2e5  5d                             pop    ebp
0x55fee6 raw=0x15f2e6  c20400                         ret    0x4

; prolog_onclose_closure | normal Prolog receiver; no result push despite C return1
; VA 0x55ff10..0x55ff66 RAW 0x15f310 len 86 SHA256 273a69df1f05f3fc6b754dc0b9b5a144b204c71515907deb7c89b74d38e513b4
0x55ff10 raw=0x15f310  55                             push   ebp
0x55ff11 raw=0x15f311  8bec                           mov    ebp,esp
0x55ff13 raw=0x15f313  6aff                           push   0xffffffff
0x55ff15 raw=0x15f315  68c8839300                     push   0x9383c8
0x55ff1a raw=0x15f31a  64a100000000                   mov    eax,fs:0x0
0x55ff20 raw=0x15f320  50                             push   eax
0x55ff21 raw=0x15f321  83ec0c                         sub    esp,0xc
0x55ff24 raw=0x15f324  a1201fd600                     mov    eax,ds:0xd61f20
0x55ff29 raw=0x15f329  33c5                           xor    eax,ebp
0x55ff2b raw=0x15f32b  50                             push   eax
0x55ff2c raw=0x15f32c  8d45f4                         lea    eax,[ebp-0xc]
0x55ff2f raw=0x15f32f  64a300000000                   mov    fs:0x0,eax
0x55ff35 raw=0x15f335  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x55ff38 raw=0x15f338  8945e8                         mov    DWORD PTR [ebp-0x18],eax
0x55ff3b raw=0x15f33b  33c0                           xor    eax,eax
0x55ff3d raw=0x15f33d  8945ec                         mov    DWORD PTR [ebp-0x14],eax
0x55ff40 raw=0x15f340  8945f0                         mov    DWORD PTR [ebp-0x10],eax
0x55ff43 raw=0x15f343  8945fc                         mov    DWORD PTR [ebp-0x4],eax
0x55ff46 raw=0x15f346  8b0d6827fe00                   mov    ecx,DWORD PTR ds:0xfe2768
0x55ff4c raw=0x15f34c  ff156c27fe00                   call   DWORD PTR ds:0xfe276c
0x55ff52 raw=0x15f352  b801000000                     mov    eax,0x1
0x55ff57 raw=0x15f357  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x55ff5a raw=0x15f35a  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x55ff61 raw=0x15f361  59                             pop    ecx
0x55ff62 raw=0x15f362  8be5                           mov    esp,ebp
0x55ff64 raw=0x15f364  5d                             pop    ebp
0x55ff65 raw=0x15f365  c3                             ret

; flying_closure | Q.FlyingObject closure calls 7arg converter; no result push
; VA 0x569950..0x5699a6 RAW 0x168d50 len 86 SHA256 0dda50730c31396ce61c1296876c914e16dfbcf458fd0d3541cd780d1c089075
0x569950 raw=0x168d50  55                             push   ebp
0x569951 raw=0x168d51  8bec                           mov    ebp,esp
0x569953 raw=0x168d53  6aff                           push   0xffffffff
0x569955 raw=0x168d55  68c8839300                     push   0x9383c8
0x56995a raw=0x168d5a  64a100000000                   mov    eax,fs:0x0
0x569960 raw=0x168d60  50                             push   eax
0x569961 raw=0x168d61  83ec0c                         sub    esp,0xc
0x569964 raw=0x168d64  a1201fd600                     mov    eax,ds:0xd61f20
0x569969 raw=0x168d69  33c5                           xor    eax,ebp
0x56996b raw=0x168d6b  50                             push   eax
0x56996c raw=0x168d6c  8d45f4                         lea    eax,[ebp-0xc]
0x56996f raw=0x168d6f  64a300000000                   mov    fs:0x0,eax
0x569975 raw=0x168d75  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x569978 raw=0x168d78  8945e8                         mov    DWORD PTR [ebp-0x18],eax
0x56997b raw=0x168d7b  33c0                           xor    eax,eax
0x56997d raw=0x168d7d  8945ec                         mov    DWORD PTR [ebp-0x14],eax
0x569980 raw=0x168d80  8945f0                         mov    DWORD PTR [ebp-0x10],eax
0x569983 raw=0x168d83  8d4de8                         lea    ecx,[ebp-0x18]
0x569986 raw=0x168d86  51                             push   ecx
0x569987 raw=0x168d87  8945fc                         mov    DWORD PTR [ebp-0x4],eax
0x56998a raw=0x168d8a  e851190000                     call   0x56b2e0
0x56998f raw=0x168d8f  83c404                         add    esp,0x4
0x569992 raw=0x168d92  b801000000                     mov    eax,0x1
0x569997 raw=0x168d97  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x56999a raw=0x168d9a  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x5699a1 raw=0x168da1  59                             pop    ecx
0x5699a2 raw=0x168da2  8be5                           mov    esp,ebp
0x5699a4 raw=0x168da4  5d                             pop    ebp
0x5699a5 raw=0x168da5  c3                             ret

; delete_flying_closure | Q.DelFlyingObject noarg closure; no result push
; VA 0x5699b0..0x569a06 RAW 0x168db0 len 86 SHA256 7305e1e6a77d3c7f9ae722f3167f296c927dcf53e22fd02f812b8aecd75b18fd
0x5699b0 raw=0x168db0  55                             push   ebp
0x5699b1 raw=0x168db1  8bec                           mov    ebp,esp
0x5699b3 raw=0x168db3  6aff                           push   0xffffffff
0x5699b5 raw=0x168db5  68c8839300                     push   0x9383c8
0x5699ba raw=0x168dba  64a100000000                   mov    eax,fs:0x0
0x5699c0 raw=0x168dc0  50                             push   eax
0x5699c1 raw=0x168dc1  83ec0c                         sub    esp,0xc
0x5699c4 raw=0x168dc4  a1201fd600                     mov    eax,ds:0xd61f20
0x5699c9 raw=0x168dc9  33c5                           xor    eax,ebp
0x5699cb raw=0x168dcb  50                             push   eax
0x5699cc raw=0x168dcc  8d45f4                         lea    eax,[ebp-0xc]
0x5699cf raw=0x168dcf  64a300000000                   mov    fs:0x0,eax
0x5699d5 raw=0x168dd5  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x5699d8 raw=0x168dd8  8945e8                         mov    DWORD PTR [ebp-0x18],eax
0x5699db raw=0x168ddb  33c0                           xor    eax,eax
0x5699dd raw=0x168ddd  8945ec                         mov    DWORD PTR [ebp-0x14],eax
0x5699e0 raw=0x168de0  8945f0                         mov    DWORD PTR [ebp-0x10],eax
0x5699e3 raw=0x168de3  8945fc                         mov    DWORD PTR [ebp-0x4],eax
0x5699e6 raw=0x168de6  8b0d7827fe00                   mov    ecx,DWORD PTR ds:0xfe2778
0x5699ec raw=0x168dec  ff152028fe00                   call   DWORD PTR ds:0xfe2820
0x5699f2 raw=0x168df2  b801000000                     mov    eax,0x1
0x5699f7 raw=0x168df7  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x5699fa raw=0x168dfa  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x569a01 raw=0x168e01  59                             pop    ecx
0x569a02 raw=0x168e02  8be5                           mov    esp,ebp
0x569a04 raw=0x168e04  5d                             pop    ebp
0x569a05 raw=0x168e05  c3                             ret

; prolog_closure | Q.Prolog one numeric argument
; VA 0x569ad0..0x569b2c RAW 0x168ed0 len 92 SHA256 242004d94c540e53667325e2c6c77699156e133f465319a50124b0ef7d78e0a8
0x569ad0 raw=0x168ed0  55                             push   ebp
0x569ad1 raw=0x168ed1  8bec                           mov    ebp,esp
0x569ad3 raw=0x168ed3  6aff                           push   0xffffffff
0x569ad5 raw=0x168ed5  68c8839300                     push   0x9383c8
0x569ada raw=0x168eda  64a100000000                   mov    eax,fs:0x0
0x569ae0 raw=0x168ee0  50                             push   eax
0x569ae1 raw=0x168ee1  83ec0c                         sub    esp,0xc
0x569ae4 raw=0x168ee4  a1201fd600                     mov    eax,ds:0xd61f20
0x569ae9 raw=0x168ee9  33c5                           xor    eax,ebp
0x569aeb raw=0x168eeb  50                             push   eax
0x569aec raw=0x168eec  8d45f4                         lea    eax,[ebp-0xc]
0x569aef raw=0x168eef  64a300000000                   mov    fs:0x0,eax
0x569af5 raw=0x168ef5  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x569af8 raw=0x168ef8  8945e8                         mov    DWORD PTR [ebp-0x18],eax
0x569afb raw=0x168efb  33c0                           xor    eax,eax
0x569afd raw=0x168efd  8945ec                         mov    DWORD PTR [ebp-0x14],eax
0x569b00 raw=0x168f00  8945f0                         mov    DWORD PTR [ebp-0x10],eax
0x569b03 raw=0x168f03  8945fc                         mov    DWORD PTR [ebp-0x4],eax
0x569b06 raw=0x168f06  8b0d2c28fe00                   mov    ecx,DWORD PTR ds:0xfe282c
0x569b0c raw=0x168f0c  51                             push   ecx
0x569b0d raw=0x168f0d  8d45e8                         lea    eax,[ebp-0x18]
0x569b10 raw=0x168f10  e81b090000                     call   0x56a430
0x569b15 raw=0x168f15  83c404                         add    esp,0x4
0x569b18 raw=0x168f18  b801000000                     mov    eax,0x1
0x569b1d raw=0x168f1d  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x569b20 raw=0x168f20  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x569b27 raw=0x168f27  59                             pop    ecx
0x569b28 raw=0x168f28  8be5                           mov    esp,ebp
0x569b2a raw=0x168f2a  5d                             pop    ebp
0x569b2b raw=0x168f2b  c3                             ret

; prolog_getter_closure | push native active as Lua numeric type3
; VA 0x569b30..0x569b9e RAW 0x168f30 len 110 SHA256 2b3b866e1d8879cb06555d0545f4b8aabe4cb1ff3b720be60b0851cf51deb320
0x569b30 raw=0x168f30  55                             push   ebp
0x569b31 raw=0x168f31  8bec                           mov    ebp,esp
0x569b33 raw=0x168f33  6aff                           push   0xffffffff
0x569b35 raw=0x168f35  68d8879300                     push   0x9387d8
0x569b3a raw=0x168f3a  64a100000000                   mov    eax,fs:0x0
0x569b40 raw=0x168f40  50                             push   eax
0x569b41 raw=0x168f41  83ec0c                         sub    esp,0xc
0x569b44 raw=0x168f44  56                             push   esi
0x569b45 raw=0x168f45  a1201fd600                     mov    eax,ds:0xd61f20
0x569b4a raw=0x168f4a  33c5                           xor    eax,ebp
0x569b4c raw=0x168f4c  50                             push   eax
0x569b4d raw=0x168f4d  8d45f4                         lea    eax,[ebp-0xc]
0x569b50 raw=0x168f50  64a300000000                   mov    fs:0x0,eax
0x569b56 raw=0x168f56  8b7508                         mov    esi,DWORD PTR [ebp+0x8]
0x569b59 raw=0x168f59  33c0                           xor    eax,eax
0x569b5b raw=0x168f5b  8975e8                         mov    DWORD PTR [ebp-0x18],esi
0x569b5e raw=0x168f5e  8945ec                         mov    DWORD PTR [ebp-0x14],eax
0x569b61 raw=0x168f61  8945f0                         mov    DWORD PTR [ebp-0x10],eax
0x569b64 raw=0x168f64  8945fc                         mov    DWORD PTR [ebp-0x4],eax
0x569b67 raw=0x168f67  8b0d7827fe00                   mov    ecx,DWORD PTR ds:0xfe2778
0x569b6d raw=0x168f6d  ff153028fe00                   call   DWORD PTR ds:0xfe2830
0x569b73 raw=0x168f73  894508                         mov    DWORD PTR [ebp+0x8],eax
0x569b76 raw=0x168f76  8b4608                         mov    eax,DWORD PTR [esi+0x8]
0x569b79 raw=0x168f79  db4508                         fild   DWORD PTR [ebp+0x8]
0x569b7c raw=0x168f7c  c7400803000000                 mov    DWORD PTR [eax+0x8],0x3
0x569b83 raw=0x168f83  dd18                           fstp   QWORD PTR [eax]
0x569b85 raw=0x168f85  83460810                       add    DWORD PTR [esi+0x8],0x10
0x569b89 raw=0x168f89  b801000000                     mov    eax,0x1
0x569b8e raw=0x168f8e  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x569b91 raw=0x168f91  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x569b98 raw=0x168f98  59                             pop    ecx
0x569b99 raw=0x168f99  5e                             pop    esi
0x569b9a raw=0x168f9a  8be5                           mov    esp,ebp
0x569b9c raw=0x168f9c  5d                             pop    ebp
0x569b9d raw=0x168f9d  c3                             ret

; book_closure | Q.Book one numeric argument converter
; VA 0x569d90..0x569dec RAW 0x169190 len 92 SHA256 02b7597414232f20f1d25fa989c441d45fb617479566c7bf31a0a1763cfc662e
0x569d90 raw=0x169190  55                             push   ebp
0x569d91 raw=0x169191  8bec                           mov    ebp,esp
0x569d93 raw=0x169193  6aff                           push   0xffffffff
0x569d95 raw=0x169195  68c8839300                     push   0x9383c8
0x569d9a raw=0x16919a  64a100000000                   mov    eax,fs:0x0
0x569da0 raw=0x1691a0  50                             push   eax
0x569da1 raw=0x1691a1  83ec0c                         sub    esp,0xc
0x569da4 raw=0x1691a4  a1201fd600                     mov    eax,ds:0xd61f20
0x569da9 raw=0x1691a9  33c5                           xor    eax,ebp
0x569dab raw=0x1691ab  50                             push   eax
0x569dac raw=0x1691ac  8d45f4                         lea    eax,[ebp-0xc]
0x569daf raw=0x1691af  64a300000000                   mov    fs:0x0,eax
0x569db5 raw=0x1691b5  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x569db8 raw=0x1691b8  8945e8                         mov    DWORD PTR [ebp-0x18],eax
0x569dbb raw=0x1691bb  33c0                           xor    eax,eax
0x569dbd raw=0x1691bd  8945ec                         mov    DWORD PTR [ebp-0x14],eax
0x569dc0 raw=0x1691c0  8945f0                         mov    DWORD PTR [ebp-0x10],eax
0x569dc3 raw=0x1691c3  8945fc                         mov    DWORD PTR [ebp-0x4],eax
0x569dc6 raw=0x1691c6  8b0d4828fe00                   mov    ecx,DWORD PTR ds:0xfe2848
0x569dcc raw=0x1691cc  51                             push   ecx
0x569dcd raw=0x1691cd  8d45e8                         lea    eax,[ebp-0x18]
0x569dd0 raw=0x1691d0  e85b060000                     call   0x56a430
0x569dd5 raw=0x1691d5  83c404                         add    esp,0x4
0x569dd8 raw=0x1691d8  b801000000                     mov    eax,0x1
0x569ddd raw=0x1691dd  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x569de0 raw=0x1691e0  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x569de7 raw=0x1691e7  59                             pop    ecx
0x569de8 raw=0x1691e8  8be5                           mov    esp,ebp
0x569dea raw=0x1691ea  5d                             pop    ebp
0x569deb raw=0x1691eb  c3                             ret

; book_getter_closure | push native book active as Lua numeric type3
; VA 0x569e50..0x569ebe RAW 0x169250 len 110 SHA256 4a9c4974fddee80f959f607f47a644eb4851016a9bec3133a77fc7e7c01630e8
0x569e50 raw=0x169250  55                             push   ebp
0x569e51 raw=0x169251  8bec                           mov    ebp,esp
0x569e53 raw=0x169253  6aff                           push   0xffffffff
0x569e55 raw=0x169255  68d8879300                     push   0x9387d8
0x569e5a raw=0x16925a  64a100000000                   mov    eax,fs:0x0
0x569e60 raw=0x169260  50                             push   eax
0x569e61 raw=0x169261  83ec0c                         sub    esp,0xc
0x569e64 raw=0x169264  56                             push   esi
0x569e65 raw=0x169265  a1201fd600                     mov    eax,ds:0xd61f20
0x569e6a raw=0x16926a  33c5                           xor    eax,ebp
0x569e6c raw=0x16926c  50                             push   eax
0x569e6d raw=0x16926d  8d45f4                         lea    eax,[ebp-0xc]
0x569e70 raw=0x169270  64a300000000                   mov    fs:0x0,eax
0x569e76 raw=0x169276  8b7508                         mov    esi,DWORD PTR [ebp+0x8]
0x569e79 raw=0x169279  33c0                           xor    eax,eax
0x569e7b raw=0x16927b  8975e8                         mov    DWORD PTR [ebp-0x18],esi
0x569e7e raw=0x16927e  8945ec                         mov    DWORD PTR [ebp-0x14],eax
0x569e81 raw=0x169281  8945f0                         mov    DWORD PTR [ebp-0x10],eax
0x569e84 raw=0x169284  8945fc                         mov    DWORD PTR [ebp-0x4],eax
0x569e87 raw=0x169287  8b0d7827fe00                   mov    ecx,DWORD PTR ds:0xfe2778
0x569e8d raw=0x16928d  ff155028fe00                   call   DWORD PTR ds:0xfe2850
0x569e93 raw=0x169293  894508                         mov    DWORD PTR [ebp+0x8],eax
0x569e96 raw=0x169296  8b4608                         mov    eax,DWORD PTR [esi+0x8]
0x569e99 raw=0x169299  db4508                         fild   DWORD PTR [ebp+0x8]
0x569e9c raw=0x16929c  c7400803000000                 mov    DWORD PTR [eax+0x8],0x3
0x569ea3 raw=0x1692a3  dd18                           fstp   QWORD PTR [eax]
0x569ea5 raw=0x1692a5  83460810                       add    DWORD PTR [esi+0x8],0x10
0x569ea9 raw=0x1692a9  b801000000                     mov    eax,0x1
0x569eae raw=0x1692ae  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x569eb1 raw=0x1692b1  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x569eb8 raw=0x1692b8  59                             pop    ecx
0x569eb9 raw=0x1692b9  5e                             pop    esi
0x569eba raw=0x1692ba  8be5                           mov    esp,ebp
0x569ebc raw=0x1692bc  5d                             pop    ebp
0x569ebd raw=0x1692bd  c3                             ret

; seven_arg_converter | -7 string and -6..-1 numeric conversions, FISTP signed DWORD; target FE281C
; VA 0x56b2e0..0x56b58e RAW 0x16a6e0 len 686 SHA256 b177a3d2d58f3272a2680a75ab59485d614565349817a118d85669824fc14ff0
0x56b2e0 raw=0x16a6e0  55                             push   ebp
0x56b2e1 raw=0x16a6e1  8bec                           mov    ebp,esp
0x56b2e3 raw=0x16a6e3  83ec40                         sub    esp,0x40
0x56b2e6 raw=0x16a6e6  a11c28fe00                     mov    eax,ds:0xfe281c
0x56b2eb raw=0x16a6eb  8b0d7827fe00                   mov    ecx,DWORD PTR ds:0xfe2778
0x56b2f1 raw=0x16a6f1  53                             push   ebx
0x56b2f2 raw=0x16a6f2  8b5d08                         mov    ebx,DWORD PTR [ebp+0x8]
0x56b2f5 raw=0x16a6f5  56                             push   esi
0x56b2f6 raw=0x16a6f6  8945c0                         mov    DWORD PTR [ebp-0x40],eax
0x56b2f9 raw=0x16a6f9  894dc4                         mov    DWORD PTR [ebp-0x3c],ecx
0x56b2fc raw=0x16a6fc  8b0b                           mov    ecx,DWORD PTR [ebx]
0x56b2fe raw=0x16a6fe  57                             push   edi
0x56b2ff raw=0x16a6ff  83c8ff                         or     eax,0xffffffff
0x56b302 raw=0x16a702  e8e99d1800                     call   0x6f50f0
0x56b307 raw=0x16a707  8b4808                         mov    ecx,DWORD PTR [eax+0x8]
0x56b30a raw=0x16a70a  83f903                         cmp    ecx,0x3
0x56b30d raw=0x16a70d  742e                           je     0x56b33d
0x56b30f raw=0x16a70f  83f904                         cmp    ecx,0x4
0x56b312 raw=0x16a712  0f85ec010000                   jne    0x56b504
0x56b318 raw=0x16a718  8b30                           mov    esi,DWORD PTR [eax]
0x56b31a raw=0x16a71a  83c610                         add    esi,0x10
0x56b31d raw=0x16a71d  8d7dd0                         lea    edi,[ebp-0x30]
0x56b320 raw=0x16a720  e83bc41800                     call   0x6f7760
0x56b325 raw=0x16a725  85c0                           test   eax,eax
0x56b327 raw=0x16a727  0f84d7010000                   je     0x56b504
0x56b32d raw=0x16a72d  dd45d0                         fld    QWORD PTR [ebp-0x30]
0x56b330 raw=0x16a730  c745d003000000                 mov    DWORD PTR [ebp-0x30],0x3
0x56b337 raw=0x16a737  dd5dc8                         fstp   QWORD PTR [ebp-0x38]
0x56b33a raw=0x16a73a  8d45c8                         lea    eax,[ebp-0x38]
0x56b33d raw=0x16a73d  dd00                           fld    QWORD PTR [eax]
0x56b33f raw=0x16a73f  dd5dd0                         fstp   QWORD PTR [ebp-0x30]
0x56b342 raw=0x16a742  dd45d0                         fld    QWORD PTR [ebp-0x30]
0x56b345 raw=0x16a745  db5d08                         fistp  DWORD PTR [ebp+0x8]
0x56b348 raw=0x16a748  8b5508                         mov    edx,DWORD PTR [ebp+0x8]
0x56b34b raw=0x16a74b  8955e8                         mov    DWORD PTR [ebp-0x18],edx
0x56b34e raw=0x16a74e  8b0b                           mov    ecx,DWORD PTR [ebx]
0x56b350 raw=0x16a750  b8feffffff                     mov    eax,0xfffffffe
0x56b355 raw=0x16a755  e8969d1800                     call   0x6f50f0
0x56b35a raw=0x16a75a  8b4808                         mov    ecx,DWORD PTR [eax+0x8]
0x56b35d raw=0x16a75d  83f903                         cmp    ecx,0x3
0x56b360 raw=0x16a760  742e                           je     0x56b390
0x56b362 raw=0x16a762  83f904                         cmp    ecx,0x4
0x56b365 raw=0x16a765  0f85a5010000                   jne    0x56b510
0x56b36b raw=0x16a76b  8b30                           mov    esi,DWORD PTR [eax]
0x56b36d raw=0x16a76d  83c610                         add    esi,0x10
0x56b370 raw=0x16a770  8d7dd0                         lea    edi,[ebp-0x30]
0x56b373 raw=0x16a773  e8e8c31800                     call   0x6f7760
0x56b378 raw=0x16a778  85c0                           test   eax,eax
0x56b37a raw=0x16a77a  0f8490010000                   je     0x56b510
0x56b380 raw=0x16a780  dd45d0                         fld    QWORD PTR [ebp-0x30]
0x56b383 raw=0x16a783  c745d003000000                 mov    DWORD PTR [ebp-0x30],0x3
0x56b38a raw=0x16a78a  dd5dc8                         fstp   QWORD PTR [ebp-0x38]
0x56b38d raw=0x16a78d  8d45c8                         lea    eax,[ebp-0x38]
0x56b390 raw=0x16a790  dd00                           fld    QWORD PTR [eax]
0x56b392 raw=0x16a792  dd5dd0                         fstp   QWORD PTR [ebp-0x30]
0x56b395 raw=0x16a795  dd45d0                         fld    QWORD PTR [ebp-0x30]
0x56b398 raw=0x16a798  db5dfc                         fistp  DWORD PTR [ebp-0x4]
0x56b39b raw=0x16a79b  8b45fc                         mov    eax,DWORD PTR [ebp-0x4]
0x56b39e raw=0x16a79e  8945e4                         mov    DWORD PTR [ebp-0x1c],eax
0x56b3a1 raw=0x16a7a1  8b0b                           mov    ecx,DWORD PTR [ebx]
0x56b3a3 raw=0x16a7a3  b8fdffffff                     mov    eax,0xfffffffd
0x56b3a8 raw=0x16a7a8  e8439d1800                     call   0x6f50f0
0x56b3ad raw=0x16a7ad  8b4808                         mov    ecx,DWORD PTR [eax+0x8]
0x56b3b0 raw=0x16a7b0  83f903                         cmp    ecx,0x3
0x56b3b3 raw=0x16a7b3  742e                           je     0x56b3e3
0x56b3b5 raw=0x16a7b5  83f904                         cmp    ecx,0x4
0x56b3b8 raw=0x16a7b8  0f855e010000                   jne    0x56b51c
0x56b3be raw=0x16a7be  8b30                           mov    esi,DWORD PTR [eax]
0x56b3c0 raw=0x16a7c0  83c610                         add    esi,0x10
0x56b3c3 raw=0x16a7c3  8d7dd0                         lea    edi,[ebp-0x30]
0x56b3c6 raw=0x16a7c6  e895c31800                     call   0x6f7760
0x56b3cb raw=0x16a7cb  85c0                           test   eax,eax
0x56b3cd raw=0x16a7cd  0f8449010000                   je     0x56b51c
0x56b3d3 raw=0x16a7d3  dd45d0                         fld    QWORD PTR [ebp-0x30]
0x56b3d6 raw=0x16a7d6  c745d003000000                 mov    DWORD PTR [ebp-0x30],0x3
0x56b3dd raw=0x16a7dd  dd5dc8                         fstp   QWORD PTR [ebp-0x38]
0x56b3e0 raw=0x16a7e0  8d45c8                         lea    eax,[ebp-0x38]
0x56b3e3 raw=0x16a7e3  dd00                           fld    QWORD PTR [eax]
0x56b3e5 raw=0x16a7e5  dd5dd0                         fstp   QWORD PTR [ebp-0x30]
0x56b3e8 raw=0x16a7e8  dd45d0                         fld    QWORD PTR [ebp-0x30]
0x56b3eb raw=0x16a7eb  db5df8                         fistp  DWORD PTR [ebp-0x8]
0x56b3ee raw=0x16a7ee  8b4df8                         mov    ecx,DWORD PTR [ebp-0x8]
0x56b3f1 raw=0x16a7f1  894de0                         mov    DWORD PTR [ebp-0x20],ecx
0x56b3f4 raw=0x16a7f4  8b0b                           mov    ecx,DWORD PTR [ebx]
0x56b3f6 raw=0x16a7f6  b8fcffffff                     mov    eax,0xfffffffc
0x56b3fb raw=0x16a7fb  e8f09c1800                     call   0x6f50f0
0x56b400 raw=0x16a800  8b4808                         mov    ecx,DWORD PTR [eax+0x8]
0x56b403 raw=0x16a803  83f903                         cmp    ecx,0x3
0x56b406 raw=0x16a806  742e                           je     0x56b436
0x56b408 raw=0x16a808  83f904                         cmp    ecx,0x4
0x56b40b raw=0x16a80b  0f8517010000                   jne    0x56b528
0x56b411 raw=0x16a811  8b30                           mov    esi,DWORD PTR [eax]
0x56b413 raw=0x16a813  83c610                         add    esi,0x10
0x56b416 raw=0x16a816  8d7dd0                         lea    edi,[ebp-0x30]
0x56b419 raw=0x16a819  e842c31800                     call   0x6f7760
0x56b41e raw=0x16a81e  85c0                           test   eax,eax
0x56b420 raw=0x16a820  0f8402010000                   je     0x56b528
0x56b426 raw=0x16a826  dd45d0                         fld    QWORD PTR [ebp-0x30]
0x56b429 raw=0x16a829  c745d003000000                 mov    DWORD PTR [ebp-0x30],0x3
0x56b430 raw=0x16a830  dd5dc8                         fstp   QWORD PTR [ebp-0x38]
0x56b433 raw=0x16a833  8d45c8                         lea    eax,[ebp-0x38]
0x56b436 raw=0x16a836  dd00                           fld    QWORD PTR [eax]
0x56b438 raw=0x16a838  dd5dd0                         fstp   QWORD PTR [ebp-0x30]
0x56b43b raw=0x16a83b  dd45d0                         fld    QWORD PTR [ebp-0x30]
0x56b43e raw=0x16a83e  db5df4                         fistp  DWORD PTR [ebp-0xc]
0x56b441 raw=0x16a841  8b55f4                         mov    edx,DWORD PTR [ebp-0xc]
0x56b444 raw=0x16a844  8955dc                         mov    DWORD PTR [ebp-0x24],edx
0x56b447 raw=0x16a847  8b0b                           mov    ecx,DWORD PTR [ebx]
0x56b449 raw=0x16a849  b8fbffffff                     mov    eax,0xfffffffb
0x56b44e raw=0x16a84e  e89d9c1800                     call   0x6f50f0
0x56b453 raw=0x16a853  8b4808                         mov    ecx,DWORD PTR [eax+0x8]
0x56b456 raw=0x16a856  83f903                         cmp    ecx,0x3
0x56b459 raw=0x16a859  742e                           je     0x56b489
0x56b45b raw=0x16a85b  83f904                         cmp    ecx,0x4
0x56b45e raw=0x16a85e  0f85d0000000                   jne    0x56b534
0x56b464 raw=0x16a864  8b30                           mov    esi,DWORD PTR [eax]
0x56b466 raw=0x16a866  83c610                         add    esi,0x10
0x56b469 raw=0x16a869  8d7dd0                         lea    edi,[ebp-0x30]
0x56b46c raw=0x16a86c  e8efc21800                     call   0x6f7760
0x56b471 raw=0x16a871  85c0                           test   eax,eax
0x56b473 raw=0x16a873  0f84bb000000                   je     0x56b534
0x56b479 raw=0x16a879  dd45d0                         fld    QWORD PTR [ebp-0x30]
0x56b47c raw=0x16a87c  c745d003000000                 mov    DWORD PTR [ebp-0x30],0x3
0x56b483 raw=0x16a883  dd5dc8                         fstp   QWORD PTR [ebp-0x38]
0x56b486 raw=0x16a886  8d45c8                         lea    eax,[ebp-0x38]
0x56b489 raw=0x16a889  dd00                           fld    QWORD PTR [eax]
0x56b48b raw=0x16a88b  dd5dd0                         fstp   QWORD PTR [ebp-0x30]
0x56b48e raw=0x16a88e  dd45d0                         fld    QWORD PTR [ebp-0x30]
0x56b491 raw=0x16a891  db5df0                         fistp  DWORD PTR [ebp-0x10]
0x56b494 raw=0x16a894  8b45f0                         mov    eax,DWORD PTR [ebp-0x10]
0x56b497 raw=0x16a897  8945d8                         mov    DWORD PTR [ebp-0x28],eax
0x56b49a raw=0x16a89a  8b0b                           mov    ecx,DWORD PTR [ebx]
0x56b49c raw=0x16a89c  b8faffffff                     mov    eax,0xfffffffa
0x56b4a1 raw=0x16a8a1  e84a9c1800                     call   0x6f50f0
0x56b4a6 raw=0x16a8a6  8b4808                         mov    ecx,DWORD PTR [eax+0x8]
0x56b4a9 raw=0x16a8a9  83f903                         cmp    ecx,0x3
0x56b4ac raw=0x16a8ac  742a                           je     0x56b4d8
0x56b4ae raw=0x16a8ae  83f904                         cmp    ecx,0x4
0x56b4b1 raw=0x16a8b1  0f8589000000                   jne    0x56b540
0x56b4b7 raw=0x16a8b7  8b30                           mov    esi,DWORD PTR [eax]
0x56b4b9 raw=0x16a8b9  83c610                         add    esi,0x10
0x56b4bc raw=0x16a8bc  8d7dd0                         lea    edi,[ebp-0x30]
0x56b4bf raw=0x16a8bf  e89cc21800                     call   0x6f7760
0x56b4c4 raw=0x16a8c4  85c0                           test   eax,eax
0x56b4c6 raw=0x16a8c6  7478                           je     0x56b540
0x56b4c8 raw=0x16a8c8  dd45d0                         fld    QWORD PTR [ebp-0x30]
0x56b4cb raw=0x16a8cb  c745d003000000                 mov    DWORD PTR [ebp-0x30],0x3
0x56b4d2 raw=0x16a8d2  dd5dc8                         fstp   QWORD PTR [ebp-0x38]
0x56b4d5 raw=0x16a8d5  8d45c8                         lea    eax,[ebp-0x38]
0x56b4d8 raw=0x16a8d8  dd00                           fld    QWORD PTR [eax]
0x56b4da raw=0x16a8da  dd5dd0                         fstp   QWORD PTR [ebp-0x30]
0x56b4dd raw=0x16a8dd  dd45d0                         fld    QWORD PTR [ebp-0x30]
0x56b4e0 raw=0x16a8e0  db5dec                         fistp  DWORD PTR [ebp-0x14]
0x56b4e3 raw=0x16a8e3  8b4dec                         mov    ecx,DWORD PTR [ebp-0x14]
0x56b4e6 raw=0x16a8e6  894dd4                         mov    DWORD PTR [ebp-0x2c],ecx
0x56b4e9 raw=0x16a8e9  8b3b                           mov    edi,DWORD PTR [ebx]
0x56b4eb raw=0x16a8eb  8b7708                         mov    esi,DWORD PTR [edi+0x8]
0x56b4ee raw=0x16a8ee  83ee70                         sub    esi,0x70
0x56b4f1 raw=0x16a8f1  837e0804                       cmp    DWORD PTR [esi+0x8],0x4
0x56b4f5 raw=0x16a8f5  746a                           je     0x56b561
0x56b4f7 raw=0x16a8f7  e8d4001900                     call   0x6fb5d0
0x56b4fc raw=0x16a8fc  85c0                           test   eax,eax
0x56b4fe raw=0x16a8fe  7549                           jne    0x56b549
0x56b500 raw=0x16a900  33f6                           xor    esi,esi
0x56b502 raw=0x16a902  eb62                           jmp    0x56b566
0x56b504 raw=0x16a904  c745e800000000                 mov    DWORD PTR [ebp-0x18],0x0
0x56b50b raw=0x16a90b  e93efeffff                     jmp    0x56b34e
0x56b510 raw=0x16a910  c745e400000000                 mov    DWORD PTR [ebp-0x1c],0x0
0x56b517 raw=0x16a917  e985feffff                     jmp    0x56b3a1
0x56b51c raw=0x16a91c  c745e000000000                 mov    DWORD PTR [ebp-0x20],0x0
0x56b523 raw=0x16a923  e9ccfeffff                     jmp    0x56b3f4
0x56b528 raw=0x16a928  c745dc00000000                 mov    DWORD PTR [ebp-0x24],0x0
0x56b52f raw=0x16a92f  e913ffffff                     jmp    0x56b447
0x56b534 raw=0x16a934  c745d800000000                 mov    DWORD PTR [ebp-0x28],0x0
0x56b53b raw=0x16a93b  e95affffff                     jmp    0x56b49a
0x56b540 raw=0x16a940  c745d400000000                 mov    DWORD PTR [ebp-0x2c],0x0
0x56b547 raw=0x16a947  eba0                           jmp    0x56b4e9
0x56b549 raw=0x16a949  8b4710                         mov    eax,DWORD PTR [edi+0x10]
0x56b54c raw=0x16a94c  8b5044                         mov    edx,DWORD PTR [eax+0x44]
0x56b54f raw=0x16a94f  3b5040                         cmp    edx,DWORD PTR [eax+0x40]
0x56b552 raw=0x16a952  7207                           jb     0x56b55b
0x56b554 raw=0x16a954  8bc7                           mov    eax,edi
0x56b556 raw=0x16a956  e845fe1800                     call   0x6fb3a0
0x56b55b raw=0x16a95b  8b7708                         mov    esi,DWORD PTR [edi+0x8]
0x56b55e raw=0x16a95e  83ee70                         sub    esi,0x70
0x56b561 raw=0x16a961  8b36                           mov    esi,DWORD PTR [esi]
0x56b563 raw=0x16a963  83c610                         add    esi,0x10
0x56b566 raw=0x16a966  8b45e8                         mov    eax,DWORD PTR [ebp-0x18]
0x56b569 raw=0x16a969  8b4de4                         mov    ecx,DWORD PTR [ebp-0x1c]
0x56b56c raw=0x16a96c  8b55e0                         mov    edx,DWORD PTR [ebp-0x20]
0x56b56f raw=0x16a96f  50                             push   eax
0x56b570 raw=0x16a970  8b45dc                         mov    eax,DWORD PTR [ebp-0x24]
0x56b573 raw=0x16a973  51                             push   ecx
0x56b574 raw=0x16a974  8b4dd8                         mov    ecx,DWORD PTR [ebp-0x28]
0x56b577 raw=0x16a977  52                             push   edx
0x56b578 raw=0x16a978  8b55d4                         mov    edx,DWORD PTR [ebp-0x2c]
0x56b57b raw=0x16a97b  50                             push   eax
0x56b57c raw=0x16a97c  51                             push   ecx
0x56b57d raw=0x16a97d  8b4dc4                         mov    ecx,DWORD PTR [ebp-0x3c]
0x56b580 raw=0x16a980  52                             push   edx
0x56b581 raw=0x16a981  56                             push   esi
0x56b582 raw=0x16a982  ff55c0                         call   DWORD PTR [ebp-0x40]
0x56b585 raw=0x16a985  5f                             pop    edi
0x56b586 raw=0x16a986  5e                             pop    esi
0x56b587 raw=0x16a987  33c0                           xor    eax,eax
0x56b589 raw=0x16a989  5b                             pop    ebx
0x56b58a raw=0x16a98a  8be5                           mov    esp,ebp
0x56b58c raw=0x16a98c  5d                             pop    ebp
0x56b58d raw=0x16a98d  c3                             ret

; one_arg_converter | one numeric value or numeric string to signed DWORD; default0
; VA 0x56a430..0x56a4a3 RAW 0x169830 len 115 SHA256 ed9871da5aa7b7fb1b47dd2cdb5602c38d2554a686fe84960f2c53d470fcd479
0x56a430 raw=0x169830  55                             push   ebp
0x56a431 raw=0x169831  8bec                           mov    ebp,esp
0x56a433 raw=0x169833  8b08                           mov    ecx,DWORD PTR [eax]
0x56a435 raw=0x169835  83ec18                         sub    esp,0x18
0x56a438 raw=0x169838  53                             push   ebx
0x56a439 raw=0x169839  8b1d7827fe00                   mov    ebx,DWORD PTR ds:0xfe2778
0x56a43f raw=0x16983f  83c8ff                         or     eax,0xffffffff
0x56a442 raw=0x169842  e8a9ac1800                     call   0x6f50f0
0x56a447 raw=0x169847  8b4808                         mov    ecx,DWORD PTR [eax+0x8]
0x56a44a raw=0x16984a  83f903                         cmp    ecx,0x3
0x56a44d raw=0x16984d  742a                           je     0x56a479
0x56a44f raw=0x16984f  83f904                         cmp    ecx,0x4
0x56a452 raw=0x169852  7540                           jne    0x56a494
0x56a454 raw=0x169854  56                             push   esi
0x56a455 raw=0x169855  8b30                           mov    esi,DWORD PTR [eax]
0x56a457 raw=0x169857  57                             push   edi
0x56a458 raw=0x169858  83c610                         add    esi,0x10
0x56a45b raw=0x16985b  8d7df8                         lea    edi,[ebp-0x8]
0x56a45e raw=0x16985e  e8fdd21800                     call   0x6f7760
0x56a463 raw=0x169863  5f                             pop    edi
0x56a464 raw=0x169864  5e                             pop    esi
0x56a465 raw=0x169865  85c0                           test   eax,eax
0x56a467 raw=0x169867  742b                           je     0x56a494
0x56a469 raw=0x169869  dd45f8                         fld    QWORD PTR [ebp-0x8]
0x56a46c raw=0x16986c  c745f003000000                 mov    DWORD PTR [ebp-0x10],0x3
0x56a473 raw=0x169873  dd5de8                         fstp   QWORD PTR [ebp-0x18]
0x56a476 raw=0x169876  8d45e8                         lea    eax,[ebp-0x18]
0x56a479 raw=0x169879  dd00                           fld    QWORD PTR [eax]
0x56a47b raw=0x16987b  dd5df0                         fstp   QWORD PTR [ebp-0x10]
0x56a47e raw=0x16987e  dd45f0                         fld    QWORD PTR [ebp-0x10]
0x56a481 raw=0x169881  db5dfc                         fistp  DWORD PTR [ebp-0x4]
0x56a484 raw=0x169884  8b45fc                         mov    eax,DWORD PTR [ebp-0x4]
0x56a487 raw=0x169887  50                             push   eax
0x56a488 raw=0x169888  8bcb                           mov    ecx,ebx
0x56a48a raw=0x16988a  ff5508                         call   DWORD PTR [ebp+0x8]
0x56a48d raw=0x16988d  33c0                           xor    eax,eax
0x56a48f raw=0x16988f  5b                             pop    ebx
0x56a490 raw=0x169890  8be5                           mov    esp,ebp
0x56a492 raw=0x169892  5d                             pop    ebp
0x56a493 raw=0x169893  c3                             ret
0x56a494 raw=0x169894  33c0                           xor    eax,eax
0x56a496 raw=0x169896  50                             push   eax
0x56a497 raw=0x169897  8bcb                           mov    ecx,ebx
0x56a499 raw=0x169899  ff5508                         call   DWORD PTR [ebp+0x8]
0x56a49c raw=0x16989c  33c0                           xor    eax,eax
0x56a49e raw=0x16989e  5b                             pop    ebx
0x56a49f raw=0x16989f  8be5                           mov    esp,ebp
0x56a4a1 raw=0x1698a1  5d                             pop    ebp
0x56a4a2 raw=0x1698a2  c3                             ret

; q_flying_create | delete old handle; CFlyingImage construction; DWORD counter into M+40
; VA 0x564940..0x564a5b RAW 0x163d40 len 283 SHA256 d84fc1b6bcd5eb80ea5eecfec60a3dcbfef824fbf5e52295d518003955f943e2
0x564940 raw=0x163d40  55                             push   ebp
0x564941 raw=0x163d41  8bec                           mov    ebp,esp
0x564943 raw=0x163d43  6aff                           push   0xffffffff
0x564945 raw=0x163d45  68b9de9100                     push   0x91deb9
0x56494a raw=0x163d4a  64a100000000                   mov    eax,fs:0x0
0x564950 raw=0x163d50  50                             push   eax
0x564951 raw=0x163d51  83ec10                         sub    esp,0x10
0x564954 raw=0x163d54  53                             push   ebx
0x564955 raw=0x163d55  56                             push   esi
0x564956 raw=0x163d56  57                             push   edi
0x564957 raw=0x163d57  a1201fd600                     mov    eax,ds:0xd61f20
0x56495c raw=0x163d5c  33c5                           xor    eax,ebp
0x56495e raw=0x163d5e  50                             push   eax
0x56495f raw=0x163d5f  8d45f4                         lea    eax,[ebp-0xc]
0x564962 raw=0x163d62  64a300000000                   mov    fs:0x0,eax
0x564968 raw=0x163d68  8bd9                           mov    ebx,ecx
0x56496a raw=0x163d6a  e8f1000000                     call   0x564a60
0x56496f raw=0x163d6f  6a70                           push   0x70
0x564971 raw=0x163d71  e8f2c83200                     call   0x891268
0x564976 raw=0x163d76  8bf0                           mov    esi,eax
0x564978 raw=0x163d78  83c404                         add    esp,0x4
0x56497b raw=0x163d7b  8975ec                         mov    DWORD PTR [ebp-0x14],esi
0x56497e raw=0x163d7e  33ff                           xor    edi,edi
0x564980 raw=0x163d80  897dfc                         mov    DWORD PTR [ebp-0x4],edi
0x564983 raw=0x163d83  3bf7                           cmp    esi,edi
0x564985 raw=0x163d85  7433                           je     0x5649ba
0x564987 raw=0x163d87  397d20                         cmp    DWORD PTR [ebp+0x20],edi
0x56498a raw=0x163d8a  7405                           je     0x564991
0x56498c raw=0x163d8c  83c8ff                         or     eax,0xffffffff
0x56498f raw=0x163d8f  eb03                           jmp    0x564994
0x564991 raw=0x163d91  8b4518                         mov    eax,DWORD PTR [ebp+0x18]
0x564994 raw=0x163d94  8b4d1c                         mov    ecx,DWORD PTR [ebp+0x1c]
0x564997 raw=0x163d97  8b5508                         mov    edx,DWORD PTR [ebp+0x8]
0x56499a raw=0x163d9a  57                             push   edi
0x56499b raw=0x163d9b  51                             push   ecx
0x56499c raw=0x163d9c  8b4d14                         mov    ecx,DWORD PTR [ebp+0x14]
0x56499f raw=0x163d9f  50                             push   eax
0x5649a0 raw=0x163da0  56                             push   esi
0x5649a1 raw=0x163da1  e8eaf4feff                     call   0x553e90
0x5649a6 raw=0x163da6  8b550c                         mov    edx,DWORD PTR [ebp+0xc]
0x5649a9 raw=0x163da9  8b4510                         mov    eax,DWORD PTR [ebp+0x10]
0x5649ac raw=0x163dac  c7064807c100                   mov    DWORD PTR [esi],0xc10748
0x5649b2 raw=0x163db2  895668                         mov    DWORD PTR [esi+0x68],edx
0x5649b5 raw=0x163db5  89466c                         mov    DWORD PTR [esi+0x6c],eax
0x5649b8 raw=0x163db8  eb02                           jmp    0x5649bc
0x5649ba raw=0x163dba  33f6                           xor    esi,esi
0x5649bc raw=0x163dbc  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
0x5649c3 raw=0x163dc3  f6055473fb0001                 test   BYTE PTR ds:0xfb7354,0x1
0x5649ca raw=0x163dca  7527                           jne    0x5649f3
0x5649cc raw=0x163dcc  b801000000                     mov    eax,0x1
0x5649d1 raw=0x163dd1  09055473fb00                   or     DWORD PTR ds:0xfb7354,eax
0x5649d7 raw=0x163dd7  8945fc                         mov    DWORD PTR [ebp-0x4],eax
0x5649da raw=0x163dda  e8f1e9feff                     call   0x5533d0
0x5649df raw=0x163ddf  6800d1bc00                     push   0xbcd100
0x5649e4 raw=0x163de4  e831d93200                     call   0x89231a
0x5649e9 raw=0x163de9  83c404                         add    esp,0x4
0x5649ec raw=0x163dec  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
0x5649f3 raw=0x163df3  8b16                           mov    edx,DWORD PTR [esi]
0x5649f5 raw=0x163df5  8b4204                         mov    eax,DWORD PTR [edx+0x4]
0x5649f8 raw=0x163df8  8bce                           mov    ecx,esi
0x5649fa raw=0x163dfa  ffd0                           call   eax
0x5649fc raw=0x163dfc  a1b073fb00                     mov    eax,ds:0xfb73b0
0x564a01 raw=0x163e01  8b0dac73fb00                   mov    ecx,DWORD PTR ds:0xfb73ac
0x564a07 raw=0x163e07  8b16                           mov    edx,DWORD PTR [esi]
0x564a09 raw=0x163e09  8b5220                         mov    edx,DWORD PTR [edx+0x20]
0x564a0c raw=0x163e0c  50                             push   eax
0x564a0d raw=0x163e0d  51                             push   ecx
0x564a0e raw=0x163e0e  8bce                           mov    ecx,esi
0x564a10 raw=0x163e10  ffd2                           call   edx
0x564a12 raw=0x163e12  897e40                         mov    DWORD PTR [esi+0x40],edi
0x564a15 raw=0x163e15  a19873fb00                     mov    eax,ds:0xfb7398
0x564a1a raw=0x163e1a  8975ec                         mov    DWORD PTR [ebp-0x14],esi
0x564a1d raw=0x163e1d  8d7de8                         lea    edi,[ebp-0x18]
0x564a20 raw=0x163e20  be5873fb00                     mov    esi,0xfb7358
0x564a25 raw=0x163e25  8945e8                         mov    DWORD PTR [ebp-0x18],eax
0x564a28 raw=0x163e28  e8f3a40100                     call   0x57ef20
0x564a2d raw=0x163e2d  50                             push   eax
0x564a2e raw=0x163e2e  56                             push   esi
0x564a2f raw=0x163e2f  8d75e8                         lea    esi,[ebp-0x18]
0x564a32 raw=0x163e32  e8c9a72c00                     call   0x82f200
0x564a37 raw=0x163e37  a19873fb00                     mov    eax,ds:0xfb7398
0x564a3c raw=0x163e3c  8bc8                           mov    ecx,eax
0x564a3e raw=0x163e3e  40                             inc    eax
0x564a3f raw=0x163e3f  a39873fb00                     mov    ds:0xfb7398,eax
0x564a44 raw=0x163e44  894b40                         mov    DWORD PTR [ebx+0x40],ecx
0x564a47 raw=0x163e47  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x564a4a raw=0x163e4a  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x564a51 raw=0x163e51  59                             pop    ecx
0x564a52 raw=0x163e52  5f                             pop    edi
0x564a53 raw=0x163e53  5e                             pop    esi
0x564a54 raw=0x163e54  5b                             pop    ebx
0x564a55 raw=0x163e55  8be5                           mov    esp,ebp
0x564a57 raw=0x163e57  5d                             pop    ebp
0x564a58 raw=0x163e58  c21c00                         ret    0x1c

; q_flying_delete | tree lookup using M+40; mark payload+14=0; M+40=-1
; VA 0x564a60..0x564afb RAW 0x163e60 len 155 SHA256 a06f78b3f59ba829401588af3621b133fb49cdf733c2bde766fc5fbf6b2be535
0x564a60 raw=0x163e60  55                             push   ebp
0x564a61 raw=0x163e61  8bec                           mov    ebp,esp
0x564a63 raw=0x163e63  6aff                           push   0xffffffff
0x564a65 raw=0x163e65  68eece9000                     push   0x90ceee
0x564a6a raw=0x163e6a  64a100000000                   mov    eax,fs:0x0
0x564a70 raw=0x163e70  50                             push   eax
0x564a71 raw=0x163e71  83ec08                         sub    esp,0x8
0x564a74 raw=0x163e74  56                             push   esi
0x564a75 raw=0x163e75  a1201fd600                     mov    eax,ds:0xd61f20
0x564a7a raw=0x163e7a  33c5                           xor    eax,ebp
0x564a7c raw=0x163e7c  50                             push   eax
0x564a7d raw=0x163e7d  8d45f4                         lea    eax,[ebp-0xc]
0x564a80 raw=0x163e80  64a300000000                   mov    fs:0x0,eax
0x564a86 raw=0x163e86  8bf1                           mov    esi,ecx
0x564a88 raw=0x163e88  b801000000                     mov    eax,0x1
0x564a8d raw=0x163e8d  84055473fb00                   test   BYTE PTR ds:0xfb7354,al
0x564a93 raw=0x163e93  751f                           jne    0x564ab4
0x564a95 raw=0x163e95  09055473fb00                   or     DWORD PTR ds:0xfb7354,eax
0x564a9b raw=0x163e9b  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
0x564aa2 raw=0x163ea2  e829e9feff                     call   0x5533d0
0x564aa7 raw=0x163ea7  6800d1bc00                     push   0xbcd100
0x564aac raw=0x163eac  e869d83200                     call   0x89231a
0x564ab1 raw=0x163eb1  83c404                         add    esp,0x4
0x564ab4 raw=0x163eb4  8b4640                         mov    eax,DWORD PTR [esi+0x40]
0x564ab7 raw=0x163eb7  8d4df0                         lea    ecx,[ebp-0x10]
0x564aba raw=0x163eba  8945f0                         mov    DWORD PTR [ebp-0x10],eax
0x564abd raw=0x163ebd  51                             push   ecx
0x564abe raw=0x163ebe  8d45ec                         lea    eax,[ebp-0x14]
0x564ac1 raw=0x163ec1  b95873fb00                     mov    ecx,0xfb7358
0x564ac6 raw=0x163ec6  e835a42c00                     call   0x82ef00
0x564acb raw=0x163ecb  8b45ec                         mov    eax,DWORD PTR [ebp-0x14]
0x564ace raw=0x163ece  3b055c73fb00                   cmp    eax,DWORD PTR ds:0xfb735c
0x564ad4 raw=0x163ed4  740e                           je     0x564ae4
0x564ad6 raw=0x163ed6  8b4010                         mov    eax,DWORD PTR [eax+0x10]
0x564ad9 raw=0x163ed9  85c0                           test   eax,eax
0x564adb raw=0x163edb  7407                           je     0x564ae4
0x564add raw=0x163edd  c7401400000000                 mov    DWORD PTR [eax+0x14],0x0
0x564ae4 raw=0x163ee4  c74640ffffffff                 mov    DWORD PTR [esi+0x40],0xffffffff
0x564aeb raw=0x163eeb  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x564aee raw=0x163eee  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x564af5 raw=0x163ef5  59                             pop    ecx
0x564af6 raw=0x163ef6  5e                             pop    esi
0x564af7 raw=0x163ef7  8be5                           mov    esp,ebp
0x564af9 raw=0x163ef9  5d                             pop    ebp
0x564afa raw=0x163efa  c3                             ret

; q_owner_constructor | M=FB73C0 initializes M+40=-1
; VA 0x560170..0x56041a RAW 0x15f570 len 682 SHA256 0e935b9889bac2baf5ab9ba047542789128eeaf557655e64d43927f0d16c89bc
0x560170 raw=0x15f570  55                             push   ebp
0x560171 raw=0x15f571  8bec                           mov    ebp,esp
0x560173 raw=0x15f573  6aff                           push   0xffffffff
0x560175 raw=0x15f575  68c8ad9300                     push   0x93adc8
0x56017a raw=0x15f57a  64a100000000                   mov    eax,fs:0x0
0x560180 raw=0x15f580  50                             push   eax
0x560181 raw=0x15f581  83ec38                         sub    esp,0x38
0x560184 raw=0x15f584  53                             push   ebx
0x560185 raw=0x15f585  56                             push   esi
0x560186 raw=0x15f586  a1201fd600                     mov    eax,ds:0xd61f20
0x56018b raw=0x15f58b  33c5                           xor    eax,ebp
0x56018d raw=0x15f58d  50                             push   eax
0x56018e raw=0x15f58e  8d45f4                         lea    eax,[ebp-0xc]
0x560191 raw=0x15f591  64a300000000                   mov    fs:0x0,eax
0x560197 raw=0x15f597  33db                           xor    ebx,ebx
0x560199 raw=0x15f599  6a34                           push   0x34
0x56019b raw=0x15f59b  c745e4c073fb00                 mov    DWORD PTR [ebp-0x1c],0xfb73c0
0x5601a2 raw=0x15f5a2  891dc073fb00                   mov    DWORD PTR ds:0xfb73c0,ebx
0x5601a8 raw=0x15f5a8  891dc473fb00                   mov    DWORD PTR ds:0xfb73c4,ebx
0x5601ae raw=0x15f5ae  891dd073fb00                   mov    DWORD PTR ds:0xfb73d0,ebx
0x5601b4 raw=0x15f5b4  e8af103300                     call   0x891268
0x5601b9 raw=0x15f5b9  83c404                         add    esp,0x4
0x5601bc raw=0x15f5bc  3bc3                           cmp    eax,ebx
0x5601be raw=0x15f5be  0f8432020000                   je     0x5603f6
0x5601c4 raw=0x15f5c4  a3cc73fb00                     mov    ds:0xfb73cc,eax
0x5601c9 raw=0x15f5c9  8900                           mov    DWORD PTR [eax],eax
0x5601cb raw=0x15f5cb  a1cc73fb00                     mov    eax,ds:0xfb73cc
0x5601d0 raw=0x15f5d0  894004                         mov    DWORD PTR [eax+0x4],eax
0x5601d3 raw=0x15f5d3  a1cc73fb00                     mov    eax,ds:0xfb73cc
0x5601d8 raw=0x15f5d8  894008                         mov    DWORD PTR [eax+0x8],eax
0x5601db raw=0x15f5db  a1cc73fb00                     mov    eax,ds:0xfb73cc
0x5601e0 raw=0x15f5e0  c6403001                       mov    BYTE PTR [eax+0x30],0x1
0x5601e4 raw=0x15f5e4  8b0dcc73fb00                   mov    ecx,DWORD PTR ds:0xfb73cc
0x5601ea raw=0x15f5ea  c6413101                       mov    BYTE PTR [ecx+0x31],0x1
0x5601ee raw=0x15f5ee  895dfc                         mov    DWORD PTR [ebp-0x4],ebx
0x5601f1 raw=0x15f5f1  6a18                           push   0x18
0x5601f3 raw=0x15f5f3  891de073fb00                   mov    DWORD PTR ds:0xfb73e0,ebx
0x5601f9 raw=0x15f5f9  e86a103300                     call   0x891268
0x5601fe raw=0x15f5fe  83c404                         add    esp,0x4
0x560201 raw=0x15f601  3bc3                           cmp    eax,ebx
0x560203 raw=0x15f603  0f84c9010000                   je     0x5603d2
0x560209 raw=0x15f609  a3dc73fb00                     mov    ds:0xfb73dc,eax
0x56020e raw=0x15f60e  8900                           mov    DWORD PTR [eax],eax
0x560210 raw=0x15f610  a1dc73fb00                     mov    eax,ds:0xfb73dc
0x560215 raw=0x15f615  894004                         mov    DWORD PTR [eax+0x4],eax
0x560218 raw=0x15f618  a1dc73fb00                     mov    eax,ds:0xfb73dc
0x56021d raw=0x15f61d  894008                         mov    DWORD PTR [eax+0x8],eax
0x560220 raw=0x15f620  8b15dc73fb00                   mov    edx,DWORD PTR ds:0xfb73dc
0x560226 raw=0x15f626  c6421401                       mov    BYTE PTR [edx+0x14],0x1
0x56022a raw=0x15f62a  a1dc73fb00                     mov    eax,ds:0xfb73dc
0x56022f raw=0x15f62f  c6401501                       mov    BYTE PTR [eax+0x15],0x1
0x560233 raw=0x15f633  c645fc01                       mov    BYTE PTR [ebp-0x4],0x1
0x560237 raw=0x15f637  6a48                           push   0x48
0x560239 raw=0x15f639  891de873fb00                   mov    DWORD PTR ds:0xfb73e8,ebx
0x56023f raw=0x15f63f  891dec73fb00                   mov    DWORD PTR ds:0xfb73ec,ebx
0x560245 raw=0x15f645  e81e103300                     call   0x891268
0x56024a raw=0x15f64a  83c404                         add    esp,0x4
0x56024d raw=0x15f64d  8945e8                         mov    DWORD PTR [ebp-0x18],eax
0x560250 raw=0x15f650  c645fc02                       mov    BYTE PTR [ebp-0x4],0x2
0x560254 raw=0x15f654  3bc3                           cmp    eax,ebx
0x560256 raw=0x15f656  7409                           je     0x560261
0x560258 raw=0x15f658  8bf0                           mov    esi,eax
0x56025a raw=0x15f65a  e851d02600                     call   0x7cd2b0
0x56025f raw=0x15f65f  eb02                           jmp    0x560263
0x560261 raw=0x15f661  33c0                           xor    eax,eax
0x560263 raw=0x15f663  a3f073fb00                     mov    ds:0xfb73f0,eax
0x560268 raw=0x15f668  891df873fb00                   mov    DWORD PTR ds:0xfb73f8,ebx
0x56026e raw=0x15f66e  891dfc73fb00                   mov    DWORD PTR ds:0xfb73fc,ebx
0x560274 raw=0x15f674  c7050074fb00ffffffff           mov    DWORD PTR ds:0xfb7400,0xffffffff
0x56027e raw=0x15f67e  c7051874fb000f000000           mov    DWORD PTR ds:0xfb7418,0xf
0x560288 raw=0x15f688  891d1474fb00                   mov    DWORD PTR ds:0xfb7414,ebx
0x56028e raw=0x15f68e  881d0474fb00                   mov    BYTE PTR ds:0xfb7404,bl
0x560294 raw=0x15f694  c645fc03                       mov    BYTE PTR [ebp-0x4],0x3
0x560298 raw=0x15f698  6a14                           push   0x14
0x56029a raw=0x15f69a  891d2874fb00                   mov    DWORD PTR ds:0xfb7428,ebx
0x5602a0 raw=0x15f6a0  e8c30f3300                     call   0x891268
0x5602a5 raw=0x15f6a5  83c404                         add    esp,0x4
0x5602a8 raw=0x15f6a8  3bc3                           cmp    eax,ebx
0x5602aa raw=0x15f6aa  0f84fe000000                   je     0x5603ae
0x5602b0 raw=0x15f6b0  a32474fb00                     mov    ds:0xfb7424,eax
0x5602b5 raw=0x15f6b5  8900                           mov    DWORD PTR [eax],eax
0x5602b7 raw=0x15f6b7  a12474fb00                     mov    eax,ds:0xfb7424
0x5602bc raw=0x15f6bc  894004                         mov    DWORD PTR [eax+0x4],eax
0x5602bf raw=0x15f6bf  a12474fb00                     mov    eax,ds:0xfb7424
0x5602c4 raw=0x15f6c4  894008                         mov    DWORD PTR [eax+0x8],eax
0x5602c7 raw=0x15f6c7  8b0d2474fb00                   mov    ecx,DWORD PTR ds:0xfb7424
0x5602cd raw=0x15f6cd  c6411001                       mov    BYTE PTR [ecx+0x10],0x1
0x5602d1 raw=0x15f6d1  8b152474fb00                   mov    edx,DWORD PTR ds:0xfb7424
0x5602d7 raw=0x15f6d7  c6421101                       mov    BYTE PTR [edx+0x11],0x1
0x5602db raw=0x15f6db  c645fc04                       mov    BYTE PTR [ebp-0x4],0x4
0x5602df raw=0x15f6df  6a14                           push   0x14
0x5602e1 raw=0x15f6e1  891d3074fb00                   mov    DWORD PTR ds:0xfb7430,ebx
0x5602e7 raw=0x15f6e7  891d3c74fb00                   mov    DWORD PTR ds:0xfb743c,ebx
0x5602ed raw=0x15f6ed  e8760f3300                     call   0x891268
0x5602f2 raw=0x15f6f2  83c404                         add    esp,0x4
0x5602f5 raw=0x15f6f5  3bc3                           cmp    eax,ebx
0x5602f7 raw=0x15f6f7  0f848d000000                   je     0x56038a
0x5602fd raw=0x15f6fd  a33874fb00                     mov    ds:0xfb7438,eax
0x560302 raw=0x15f702  8900                           mov    DWORD PTR [eax],eax
0x560304 raw=0x15f704  a13874fb00                     mov    eax,ds:0xfb7438
0x560309 raw=0x15f709  894004                         mov    DWORD PTR [eax+0x4],eax
0x56030c raw=0x15f70c  a13874fb00                     mov    eax,ds:0xfb7438
0x560311 raw=0x15f711  894008                         mov    DWORD PTR [eax+0x8],eax
0x560314 raw=0x15f714  a13874fb00                     mov    eax,ds:0xfb7438
0x560319 raw=0x15f719  c6401001                       mov    BYTE PTR [eax+0x10],0x1
0x56031d raw=0x15f71d  8b0d3874fb00                   mov    ecx,DWORD PTR ds:0xfb7438
0x560323 raw=0x15f723  c6411101                       mov    BYTE PTR [ecx+0x11],0x1
0x560327 raw=0x15f727  c645fc05                       mov    BYTE PTR [ebp-0x4],0x5
0x56032b raw=0x15f72b  f30f1005c056c400               movss  xmm0,DWORD PTR ds:0xc456c0
0x560333 raw=0x15f733  f30f11054474fb00               movss  DWORD PTR ds:0xfb7444,xmm0
0x56033b raw=0x15f73b  66c7054874fb000100             mov    WORD PTR ds:0xfb7448,0x1
0x560344 raw=0x15f744  e887040000                     call   0x5607d0
0x560349 raw=0x15f749  e8f2200000                     call   0x562440
0x56034e raw=0x15f74e  f6054027fe0001                 test   BYTE PTR ds:0xfe2740,0x1
0x560355 raw=0x15f755  751d                           jne    0x560374
0x560357 raw=0x15f757  830d4027fe0001                 or     DWORD PTR ds:0xfe2740,0x1
0x56035e raw=0x15f75e  c645fc06                       mov    BYTE PTR [ebp-0x4],0x6
0x560362 raw=0x15f762  e819e3ffff                     call   0x55e680
0x560367 raw=0x15f767  68a0f2bc00                     push   0xbcf2a0
0x56036c raw=0x15f76c  e8a91f3300                     call   0x89231a
0x560371 raw=0x15f771  83c404                         add    esp,0x4
0x560374 raw=0x15f774  b8c073fb00                     mov    eax,0xfb73c0
0x560379 raw=0x15f779  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x56037c raw=0x15f77c  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x560383 raw=0x15f783  59                             pop    ecx
0x560384 raw=0x15f784  5e                             pop    esi
0x560385 raw=0x15f785  5b                             pop    ebx
0x560386 raw=0x15f786  8be5                           mov    esp,ebp
0x560388 raw=0x15f788  5d                             pop    ebp
0x560389 raw=0x15f789  c3                             ret
0x56038a raw=0x15f78a  8d55f0                         lea    edx,[ebp-0x10]
0x56038d raw=0x15f78d  52                             push   edx
0x56038e raw=0x15f78e  8d4dd8                         lea    ecx,[ebp-0x28]
0x560391 raw=0x15f791  895df0                         mov    DWORD PTR [ebp-0x10],ebx
0x560394 raw=0x15f794  e8100d3300                     call   0x8910a9
0x560399 raw=0x15f799  68a857c800                     push   0xc857a8
0x56039e raw=0x15f79e  8d45d8                         lea    eax,[ebp-0x28]
0x5603a1 raw=0x15f7a1  50                             push   eax
0x5603a2 raw=0x15f7a2  c745d8a42cbd00                 mov    DWORD PTR [ebp-0x28],0xbd2ca4
0x5603a9 raw=0x15f7a9  e842c63300                     call   0x89c9f0
0x5603ae raw=0x15f7ae  8d4dec                         lea    ecx,[ebp-0x14]
0x5603b1 raw=0x15f7b1  51                             push   ecx
0x5603b2 raw=0x15f7b2  8d4dcc                         lea    ecx,[ebp-0x34]
0x5603b5 raw=0x15f7b5  895dec                         mov    DWORD PTR [ebp-0x14],ebx
0x5603b8 raw=0x15f7b8  e8ec0c3300                     call   0x8910a9
0x5603bd raw=0x15f7bd  68a857c800                     push   0xc857a8
0x5603c2 raw=0x15f7c2  8d55cc                         lea    edx,[ebp-0x34]
0x5603c5 raw=0x15f7c5  52                             push   edx
0x5603c6 raw=0x15f7c6  c745cca42cbd00                 mov    DWORD PTR [ebp-0x34],0xbd2ca4
0x5603cd raw=0x15f7cd  e81ec63300                     call   0x89c9f0
0x5603d2 raw=0x15f7d2  8d45ec                         lea    eax,[ebp-0x14]
0x5603d5 raw=0x15f7d5  50                             push   eax
0x5603d6 raw=0x15f7d6  8d4dcc                         lea    ecx,[ebp-0x34]
0x5603d9 raw=0x15f7d9  895dec                         mov    DWORD PTR [ebp-0x14],ebx
0x5603dc raw=0x15f7dc  e8c80c3300                     call   0x8910a9
0x5603e1 raw=0x15f7e1  68a857c800                     push   0xc857a8
0x5603e6 raw=0x15f7e6  8d4dcc                         lea    ecx,[ebp-0x34]
0x5603e9 raw=0x15f7e9  51                             push   ecx
0x5603ea raw=0x15f7ea  c745cca42cbd00                 mov    DWORD PTR [ebp-0x34],0xbd2ca4
0x5603f1 raw=0x15f7f1  e8fac53300                     call   0x89c9f0
0x5603f6 raw=0x15f7f6  8d55e8                         lea    edx,[ebp-0x18]
0x5603f9 raw=0x15f7f9  52                             push   edx
0x5603fa raw=0x15f7fa  8d4dc0                         lea    ecx,[ebp-0x40]
0x5603fd raw=0x15f7fd  895de8                         mov    DWORD PTR [ebp-0x18],ebx
0x560400 raw=0x15f800  e8a40c3300                     call   0x8910a9
0x560405 raw=0x15f805  68a857c800                     push   0xc857a8
0x56040a raw=0x15f80a  8d45c0                         lea    eax,[ebp-0x40]
0x56040d raw=0x15f80d  50                             push   eax
0x56040e raw=0x15f80e  c745c0a42cbd00                 mov    DWORD PTR [ebp-0x40],0xbd2ca4
0x560415 raw=0x15f815  e8d6c53300                     call   0x89c9f0

; flying_fade_constructor | path string, counters, alive+14=1, protected+18=0
; VA 0x553e90..0x553f42 RAW 0x153290 len 178 SHA256 c28e38c3fad65e45c323c56c3bf222de83e0f8e0cacb2206b187751be51e4cd1
0x553e90 raw=0x153290  55                             push   ebp
0x553e91 raw=0x153291  8bec                           mov    ebp,esp
0x553e93 raw=0x153293  6aff                           push   0xffffffff
0x553e95 raw=0x153295  68086d9100                     push   0x916d08
0x553e9a raw=0x15329a  64a100000000                   mov    eax,fs:0x0
0x553ea0 raw=0x1532a0  50                             push   eax
0x553ea1 raw=0x1532a1  53                             push   ebx
0x553ea2 raw=0x1532a2  56                             push   esi
0x553ea3 raw=0x1532a3  57                             push   edi
0x553ea4 raw=0x1532a4  a1201fd600                     mov    eax,ds:0xd61f20
0x553ea9 raw=0x1532a9  33c5                           xor    eax,ebp
0x553eab raw=0x1532ab  50                             push   eax
0x553eac raw=0x1532ac  8d45f4                         lea    eax,[ebp-0xc]
0x553eaf raw=0x1532af  64a300000000                   mov    fs:0x0,eax
0x553eb5 raw=0x1532b5  8b4510                         mov    eax,DWORD PTR [ebp+0x10]
0x553eb8 raw=0x1532b8  8b7508                         mov    esi,DWORD PTR [ebp+0x8]
0x553ebb raw=0x1532bb  33db                           xor    ebx,ebx
0x553ebd raw=0x1532bd  894e1c                         mov    DWORD PTR [esi+0x1c],ecx
0x553ec0 raw=0x1532c0  894620                         mov    DWORD PTR [esi+0x20],eax
0x553ec3 raw=0x1532c3  894e28                         mov    DWORD PTR [esi+0x28],ecx
0x553ec6 raw=0x1532c6  8b4d14                         mov    ecx,DWORD PTR [ebp+0x14]
0x553ec9 raw=0x1532c9  89462c                         mov    DWORD PTR [esi+0x2c],eax
0x553ecc raw=0x1532cc  8b450c                         mov    eax,DWORD PTR [ebp+0xc]
0x553ecf raw=0x1532cf  895e04                         mov    DWORD PTR [esi+0x4],ebx
0x553ed2 raw=0x1532d2  895e08                         mov    DWORD PTR [esi+0x8],ebx
0x553ed5 raw=0x1532d5  895e24                         mov    DWORD PTR [esi+0x24],ebx
0x553ed8 raw=0x1532d8  894630                         mov    DWORD PTR [esi+0x30],eax
0x553edb raw=0x1532db  895e34                         mov    DWORD PTR [esi+0x34],ebx
0x553ede raw=0x1532de  885e38                         mov    BYTE PTR [esi+0x38],bl
0x553ee1 raw=0x1532e1  894e3c                         mov    DWORD PTR [esi+0x3c],ecx
0x553ee4 raw=0x1532e4  895e10                         mov    DWORD PTR [esi+0x10],ebx
0x553ee7 raw=0x1532e7  895e0c                         mov    DWORD PTR [esi+0xc],ebx
0x553eea raw=0x1532ea  c7461401000000                 mov    DWORD PTR [esi+0x14],0x1
0x553ef1 raw=0x1532f1  895e18                         mov    DWORD PTR [esi+0x18],ebx
0x553ef4 raw=0x1532f4  895dfc                         mov    DWORD PTR [ebp-0x4],ebx
0x553ef7 raw=0x1532f7  c70694ffc000                   mov    DWORD PTR [esi],0xc0ff94
0x553efd raw=0x1532fd  895e44                         mov    DWORD PTR [esi+0x44],ebx
0x553f00 raw=0x153300  8bc2                           mov    eax,edx
0x553f02 raw=0x153302  8d4801                         lea    ecx,[eax+0x1]
0x553f05 raw=0x153305  c7465c0f000000                 mov    DWORD PTR [esi+0x5c],0xf
0x553f0c raw=0x15330c  895e58                         mov    DWORD PTR [esi+0x58],ebx
0x553f0f raw=0x15330f  885e48                         mov    BYTE PTR [esi+0x48],bl
0x553f12 raw=0x153312  894d10                         mov    DWORD PTR [ebp+0x10],ecx
0x553f15 raw=0x153315  8a08                           mov    cl,BYTE PTR [eax]
0x553f17 raw=0x153317  40                             inc    eax
0x553f18 raw=0x153318  3acb                           cmp    cl,bl
0x553f1a raw=0x15331a  75f9                           jne    0x553f15
0x553f1c raw=0x15331c  2b4510                         sub    eax,DWORD PTR [ebp+0x10]
0x553f1f raw=0x15331f  8d4e48                         lea    ecx,[esi+0x48]
0x553f22 raw=0x153322  50                             push   eax
0x553f23 raw=0x153323  52                             push   edx
0x553f24 raw=0x153324  e847ebeaff                     call   0x402a70
0x553f29 raw=0x153329  895e64                         mov    DWORD PTR [esi+0x64],ebx
0x553f2c raw=0x15332c  8bc6                           mov    eax,esi
0x553f2e raw=0x15332e  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x553f31 raw=0x153331  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x553f38 raw=0x153338  59                             pop    ecx
0x553f39 raw=0x153339  5f                             pop    edi
0x553f3a raw=0x15333a  5e                             pop    esi
0x553f3b raw=0x15333b  5b                             pop    ebx
0x553f3c raw=0x15333c  8be5                           mov    esp,ebp
0x553f3e raw=0x15333e  5d                             pop    ebp
0x553f3f raw=0x15333f  c21000                         ret    0x10

; flying_image_load | CFlyingImage loads texture then fade state+34=1; actual body includes interior560049
; VA 0x560030..0x56008a RAW 0x15f430 len 90 SHA256 ae9f97be596e208633867ffc9a1e114902f329a6297849480ad7b14995e1e9f8
0x560030 raw=0x15f430  56                             push   esi
0x560031 raw=0x15f431  57                             push   edi
0x560032 raw=0x15f432  8bf9                           mov    edi,ecx
0x560034 raw=0x15f434  8b4f44                         mov    ecx,DWORD PTR [edi+0x44]
0x560037 raw=0x15f437  85c9                           test   ecx,ecx
0x560039 raw=0x15f439  740e                           je     0x560049
0x56003b raw=0x15f43b  8b01                           mov    eax,DWORD PTR [ecx]
0x56003d raw=0x15f43d  8b5008                         mov    edx,DWORD PTR [eax+0x8]
0x560040 raw=0x15f440  ffd2                           call   edx
0x560042 raw=0x15f442  c7474400000000                 mov    DWORD PTR [edi+0x44],0x0
0x560049 raw=0x15f449  837f5c10                       cmp    DWORD PTR [edi+0x5c],0x10
0x56004d raw=0x15f44d  8d7748                         lea    esi,[edi+0x48]
0x560050 raw=0x15f450  7204                           jb     0x560056
0x560052 raw=0x15f452  8b06                           mov    eax,DWORD PTR [esi]
0x560054 raw=0x15f454  eb02                           jmp    0x560058
0x560056 raw=0x15f456  8bc6                           mov    eax,esi
0x560058 raw=0x15f458  6a00                           push   0x0
0x56005a raw=0x15f45a  50                             push   eax
0x56005b raw=0x15f45b  e8d0421d00                     call   0x734330
0x560060 raw=0x15f460  83c408                         add    esp,0x8
0x560063 raw=0x15f463  894744                         mov    DWORD PTR [edi+0x44],eax
0x560066 raw=0x15f466  85c0                           test   eax,eax
0x560068 raw=0x15f468  7516                           jne    0x560080
0x56006a raw=0x15f46a  837e1410                       cmp    DWORD PTR [esi+0x14],0x10
0x56006e raw=0x15f46e  7202                           jb     0x560072
0x560070 raw=0x15f470  8b36                           mov    esi,DWORD PTR [esi]
0x560072 raw=0x15f472  56                             push   esi
0x560073 raw=0x15f473  682406c100                     push   0xc10624
0x560078 raw=0x15f478  e8e3da1800                     call   0x6edb60
0x56007d raw=0x15f47d  83c408                         add    esp,0x8
0x560080 raw=0x15f480  c7473401000000                 mov    DWORD PTR [edi+0x34],0x1
0x560087 raw=0x15f487  5f                             pop    edi
0x560088 raw=0x15f488  5e                             pop    esi
0x560089 raw=0x15f489  c3                             ret

; flying_image_position | image position=(percentX*width/100,percentY*height/100)
; VA 0x55fff0..0x560027 RAW 0x15f3f0 len 55 SHA256 3a0ac139cba0f150e3c1e086cb5736270a1e2e1cdf64ac3eea7ed7d19177b3cc
0x55fff0 raw=0x15f3f0  8b5168                         mov    edx,DWORD PTR [ecx+0x68]
0x55fff3 raw=0x15f3f3  0faf5104                       imul   edx,DWORD PTR [ecx+0x4]
0x55fff7 raw=0x15f3f7  b81f85eb51                     mov    eax,0x51eb851f
0x55fffc raw=0x15f3fc  f7ea                           imul   edx
0x55fffe raw=0x15f3fe  c1fa05                         sar    edx,0x5
0x560001 raw=0x15f401  8bc2                           mov    eax,edx
0x560003 raw=0x15f403  c1e81f                         shr    eax,0x1f
0x560006 raw=0x15f406  03c2                           add    eax,edx
0x560008 raw=0x15f408  8b516c                         mov    edx,DWORD PTR [ecx+0x6c]
0x56000b raw=0x15f40b  0faf5108                       imul   edx,DWORD PTR [ecx+0x8]
0x56000f raw=0x15f40f  89410c                         mov    DWORD PTR [ecx+0xc],eax
0x560012 raw=0x15f412  b81f85eb51                     mov    eax,0x51eb851f
0x560017 raw=0x15f417  f7ea                           imul   edx
0x560019 raw=0x15f419  c1fa05                         sar    edx,0x5
0x56001c raw=0x15f41c  8bc2                           mov    eax,edx
0x56001e raw=0x15f41e  c1e81f                         shr    eax,0x1f
0x560021 raw=0x15f421  03c2                           add    eax,edx
0x560023 raw=0x15f423  894110                         mov    DWORD PTR [ecx+0x10],eax
0x560026 raw=0x15f426  c3                             ret

; flying_resize | set width/height then virtual+1C placement
; VA 0x553c70..0x553c8a RAW 0x153070 len 26 SHA256 ec38bda98cf78adc101db84ef0e98b0e198ed10657ec7bbb75739589864dcfb1
0x553c70 raw=0x153070  55                             push   ebp
0x553c71 raw=0x153071  8bec                           mov    ebp,esp
0x553c73 raw=0x153073  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x553c76 raw=0x153076  8b550c                         mov    edx,DWORD PTR [ebp+0xc]
0x553c79 raw=0x153079  894104                         mov    DWORD PTR [ecx+0x4],eax
0x553c7c raw=0x15307c  8b01                           mov    eax,DWORD PTR [ecx]
0x553c7e raw=0x15307e  895108                         mov    DWORD PTR [ecx+0x8],edx
0x553c81 raw=0x153081  8b501c                         mov    edx,DWORD PTR [eax+0x1c]
0x553c84 raw=0x153084  ffd2                           call   edx
0x553c86 raw=0x153086  5d                             pop    ebp
0x553c87 raw=0x153087  c20800                         ret    0x8

; flying_fade_tick | per-call finite fade state machine; negative hold stays state3; state0 clears alive
; VA 0x553b60..0x553c50 RAW 0x152f60 len 240 SHA256 27d597aea61b31b92ff5be5a204e4a3dd972412b6ebec11ca21630cfbac5309e
0x553b60 raw=0x152f60  55                             push   ebp
0x553b61 raw=0x152f61  8bec                           mov    ebp,esp
0x553b63 raw=0x152f63  8b4134                         mov    eax,DWORD PTR [ecx+0x34]
0x553b66 raw=0x152f66  83ec08                         sub    esp,0x8
0x553b69 raw=0x152f69  83f804                         cmp    eax,0x4
0x553b6c raw=0x152f6c  0f87da000000                   ja     0x553c4c
0x553b72 raw=0x152f72  ff2485503c5500                 jmp    DWORD PTR [eax*4+0x553c50]
0x553b79 raw=0x152f79  c7411400000000                 mov    DWORD PTR [ecx+0x14],0x0
0x553b80 raw=0x152f80  8be5                           mov    esp,ebp
0x553b82 raw=0x152f82  5d                             pop    ebp
0x553b83 raw=0x152f83  c3                             ret
0x553b84 raw=0x152f84  8b4124                         mov    eax,DWORD PTR [ecx+0x24]
0x553b87 raw=0x152f87  85c0                           test   eax,eax
0x553b89 raw=0x152f89  7e08                           jle    0x553b93
0x553b8b raw=0x152f8b  48                             dec    eax
0x553b8c raw=0x152f8c  894124                         mov    DWORD PTR [ecx+0x24],eax
0x553b8f raw=0x152f8f  8be5                           mov    esp,ebp
0x553b91 raw=0x152f91  5d                             pop    ebp
0x553b92 raw=0x152f92  c3                             ret
0x553b93 raw=0x152f93  c7413402000000                 mov    DWORD PTR [ecx+0x34],0x2
0x553b9a raw=0x152f9a  8b4128                         mov    eax,DWORD PTR [ecx+0x28]
0x553b9d raw=0x152f9d  85c0                           test   eax,eax
0x553b9f raw=0x152f9f  7e39                           jle    0x553bda
0x553ba1 raw=0x152fa1  48                             dec    eax
0x553ba2 raw=0x152fa2  8945fc                         mov    DWORD PTR [ebp-0x4],eax
0x553ba5 raw=0x152fa5  db45fc                         fild   DWORD PTR [ebp-0x4]
0x553ba8 raw=0x152fa8  894128                         mov    DWORD PTR [ecx+0x28],eax
0x553bab raw=0x152fab  d97dfe                         fnstcw WORD PTR [ebp-0x2]
0x553bae raw=0x152fae  da711c                         fidiv  DWORD PTR [ecx+0x1c]
0x553bb1 raw=0x152fb1  0fb745fe                       movzx  eax,WORD PTR [ebp-0x2]
0x553bb5 raw=0x152fb5  0d000c0000                     or     eax,0xc00
0x553bba raw=0x152fba  8945f8                         mov    DWORD PTR [ebp-0x8],eax
0x553bbd raw=0x152fbd  dd058856c500                   fld    QWORD PTR ds:0xc55688
0x553bc3 raw=0x152fc3  dcc9                           fmul   st(1),st
0x553bc5 raw=0x152fc5  dee1                           fsubrp st(1),st
0x553bc7 raw=0x152fc7  d96df8                         fldcw  WORD PTR [ebp-0x8]
0x553bca raw=0x152fca  db5df8                         fistp  DWORD PTR [ebp-0x8]
0x553bcd raw=0x152fcd  8a45f8                         mov    al,BYTE PTR [ebp-0x8]
0x553bd0 raw=0x152fd0  884138                         mov    BYTE PTR [ecx+0x38],al
0x553bd3 raw=0x152fd3  d96dfe                         fldcw  WORD PTR [ebp-0x2]
0x553bd6 raw=0x152fd6  8be5                           mov    esp,ebp
0x553bd8 raw=0x152fd8  5d                             pop    ebp
0x553bd9 raw=0x152fd9  c3                             ret
0x553bda raw=0x152fda  c64138ff                       mov    BYTE PTR [ecx+0x38],0xff
0x553bde raw=0x152fde  c7413403000000                 mov    DWORD PTR [ecx+0x34],0x3
0x553be5 raw=0x152fe5  8be5                           mov    esp,ebp
0x553be7 raw=0x152fe7  5d                             pop    ebp
0x553be8 raw=0x152fe8  c3                             ret
0x553be9 raw=0x152fe9  8b4130                         mov    eax,DWORD PTR [ecx+0x30]
0x553bec raw=0x152fec  85c0                           test   eax,eax
0x553bee raw=0x152fee  7e08                           jle    0x553bf8
0x553bf0 raw=0x152ff0  48                             dec    eax
0x553bf1 raw=0x152ff1  894130                         mov    DWORD PTR [ecx+0x30],eax
0x553bf4 raw=0x152ff4  8be5                           mov    esp,ebp
0x553bf6 raw=0x152ff6  5d                             pop    ebp
0x553bf7 raw=0x152ff7  c3                             ret
0x553bf8 raw=0x152ff8  7552                           jne    0x553c4c
0x553bfa raw=0x152ffa  c7413404000000                 mov    DWORD PTR [ecx+0x34],0x4
0x553c01 raw=0x153001  8be5                           mov    esp,ebp
0x553c03 raw=0x153003  5d                             pop    ebp
0x553c04 raw=0x153004  c3                             ret
0x553c05 raw=0x153005  8b412c                         mov    eax,DWORD PTR [ecx+0x2c]
0x553c08 raw=0x153008  85c0                           test   eax,eax
0x553c0a raw=0x15300a  7e35                           jle    0x553c41
0x553c0c raw=0x15300c  48                             dec    eax
0x553c0d raw=0x15300d  d97dfe                         fnstcw WORD PTR [ebp-0x2]
0x553c10 raw=0x153010  8945f8                         mov    DWORD PTR [ebp-0x8],eax
0x553c13 raw=0x153013  db45f8                         fild   DWORD PTR [ebp-0x8]
0x553c16 raw=0x153016  89412c                         mov    DWORD PTR [ecx+0x2c],eax
0x553c19 raw=0x153019  0fb745fe                       movzx  eax,WORD PTR [ebp-0x2]
0x553c1d raw=0x15301d  0d000c0000                     or     eax,0xc00
0x553c22 raw=0x153022  da7120                         fidiv  DWORD PTR [ecx+0x20]
0x553c25 raw=0x153025  8945f8                         mov    DWORD PTR [ebp-0x8],eax
0x553c28 raw=0x153028  dc0d8856c500                   fmul   QWORD PTR ds:0xc55688
0x553c2e raw=0x15302e  d96df8                         fldcw  WORD PTR [ebp-0x8]
0x553c31 raw=0x153031  db5df8                         fistp  DWORD PTR [ebp-0x8]
0x553c34 raw=0x153034  8a55f8                         mov    dl,BYTE PTR [ebp-0x8]
0x553c37 raw=0x153037  885138                         mov    BYTE PTR [ecx+0x38],dl
0x553c3a raw=0x15303a  d96dfe                         fldcw  WORD PTR [ebp-0x2]
0x553c3d raw=0x15303d  8be5                           mov    esp,ebp
0x553c3f raw=0x15303f  5d                             pop    ebp
0x553c40 raw=0x153040  c3                             ret
0x553c41 raw=0x153041  c6413800                       mov    BYTE PTR [ecx+0x38],0x0
0x553c45 raw=0x153045  c7413400000000                 mov    DWORD PTR [ecx+0x34],0x0
0x553c4c raw=0x15304c  8be5                           mov    esp,ebp
0x553c4e raw=0x15304e  5d                             pop    ebp
0x553c4f raw=0x15304f  c3                             ret

; flying_alive_reader | return object+14, exact DWORD value
; VA 0x80f010..0x80f014 RAW 0x40e410 len 4 SHA256 01d3abacb68aac3537badfe563d0e21d0244fb61db1d805bcef8f455407fad96
0x80f010 raw=0x40e410  8b4114                         mov    eax,DWORD PTR [ecx+0x14]
0x80f013 raw=0x40e413  c3                             ret

; flying_protection_reader | return object+18, exact DWORD value
; VA 0x80f020..0x80f024 RAW 0x40e420 len 4 SHA256 38058506e8e859d5be73a33baa621352c08ea01f2224ee170173253757193941
0x80f020 raw=0x40e420  8b4118                         mov    eax,DWORD PTR [ecx+0x18]
0x80f023 raw=0x40e423  c3                             ret

; flying_release_tick | v+8 releases texture
; VA 0x553de0..0x553dfa RAW 0x1531e0 len 26 SHA256 ec2c067f34a2e5871b1eae876a76e5f8afbb765316c8f1d0d495f387898cdc61
0x553de0 raw=0x1531e0  56                             push   esi
0x553de1 raw=0x1531e1  8bf1                           mov    esi,ecx
0x553de3 raw=0x1531e3  8b4e44                         mov    ecx,DWORD PTR [esi+0x44]
0x553de6 raw=0x1531e6  85c9                           test   ecx,ecx
0x553de8 raw=0x1531e8  740e                           je     0x553df8
0x553dea raw=0x1531ea  8b01                           mov    eax,DWORD PTR [ecx]
0x553dec raw=0x1531ec  8b5008                         mov    edx,DWORD PTR [eax+0x8]
0x553def raw=0x1531ef  ffd2                           call   edx
0x553df1 raw=0x1531f1  c7464400000000                 mov    DWORD PTR [esi+0x44],0x0
0x553df8 raw=0x1531f8  5e                             pop    esi
0x553df9 raw=0x1531f9  c3                             ret

; flying_release_sweep | v+10 releases texture and resets fade state
; VA 0x553e00..0x553e3b RAW 0x153200 len 59 SHA256 ba607e1783863114a0517cf896450e78e294fc9f7a1e965b94992fa18818719a
0x553e00 raw=0x153200  8b01                           mov    eax,DWORD PTR [ecx]
0x553e02 raw=0x153202  8b5008                         mov    edx,DWORD PTR [eax+0x8]
0x553e05 raw=0x153205  ffd2                           call   edx
0x553e07 raw=0x153207  b801000000                     mov    eax,0x1
0x553e0c raw=0x15320c  c3                             ret
0x553e0d raw=0x15320d  cc                             int3
0x553e0e raw=0x15320e  cc                             int3
0x553e0f raw=0x15320f  cc                             int3
0x553e10 raw=0x153210  8bc1                           mov    eax,ecx
0x553e12 raw=0x153212  83784400                       cmp    DWORD PTR [eax+0x44],0x0
0x553e16 raw=0x153216  7422                           je     0x553e3a
0x553e18 raw=0x153218  8b4844                         mov    ecx,DWORD PTR [eax+0x44]
0x553e1b raw=0x15321b  d9ee                           fldz
0x553e1d raw=0x15321d  8b11                           mov    edx,DWORD PTR [ecx]
0x553e1f raw=0x15321f  8b5224                         mov    edx,DWORD PTR [edx+0x24]
0x553e22 raw=0x153222  56                             push   esi
0x553e23 raw=0x153223  8b7010                         mov    esi,DWORD PTR [eax+0x10]
0x553e26 raw=0x153226  8b400c                         mov    eax,DWORD PTR [eax+0xc]
0x553e29 raw=0x153229  6aff                           push   0xffffffff
0x553e2b raw=0x15322b  51                             push   ecx
0x553e2c raw=0x15322c  d91c24                         fstp   DWORD PTR [esp]
0x553e2f raw=0x15322f  6a01                           push   0x1
0x553e31 raw=0x153231  6a00                           push   0x0
0x553e33 raw=0x153233  6a00                           push   0x0
0x553e35 raw=0x153235  56                             push   esi
0x553e36 raw=0x153236  50                             push   eax
0x553e37 raw=0x153237  ffd2                           call   edx
0x553e39 raw=0x153239  5e                             pop    esi
0x553e3a raw=0x15323a  c3                             ret

; flying_deleting_destructor | CFlyingImage deleting destructor reaches base string/resource cleanup
; VA 0x553e40..0x553e89 RAW 0x153240 len 73 SHA256 a682e3a86980b9950b07f8390692e231d76b0a294e8b9b343c8074fe8f820aa5
0x553e40 raw=0x153240  55                             push   ebp
0x553e41 raw=0x153241  8bec                           mov    ebp,esp
0x553e43 raw=0x153243  56                             push   esi
0x553e44 raw=0x153244  8bf1                           mov    esi,ecx
0x553e46 raw=0x153246  c70694ffc000                   mov    DWORD PTR [esi],0xc0ff94
0x553e4c raw=0x15324c  837e5c10                       cmp    DWORD PTR [esi+0x5c],0x10
0x553e50 raw=0x153250  720c                           jb     0x553e5e
0x553e52 raw=0x153252  8b4648                         mov    eax,DWORD PTR [esi+0x48]
0x553e55 raw=0x153255  50                             push   eax
0x553e56 raw=0x153256  e8b1d33300                     call   0x89120c
0x553e5b raw=0x15325b  83c404                         add    esp,0x4
0x553e5e raw=0x15325e  33c0                           xor    eax,eax
0x553e60 raw=0x153260  f6450801                       test   BYTE PTR [ebp+0x8],0x1
0x553e64 raw=0x153264  c7465c0f000000                 mov    DWORD PTR [esi+0x5c],0xf
0x553e6b raw=0x15326b  894658                         mov    DWORD PTR [esi+0x58],eax
0x553e6e raw=0x15326e  884648                         mov    BYTE PTR [esi+0x48],al
0x553e71 raw=0x153271  c70634ffc000                   mov    DWORD PTR [esi],0xc0ff34
0x553e77 raw=0x153277  7409                           je     0x553e82
0x553e79 raw=0x153279  56                             push   esi
0x553e7a raw=0x15327a  e88dd33300                     call   0x89120c
0x553e7f raw=0x15327f  83c404                         add    esp,0x4
0x553e82 raw=0x153282  8bc6                           mov    eax,esi
0x553e84 raw=0x153284  5e                             pop    esi
0x553e85 raw=0x153285  5d                             pop    ebp
0x553e86 raw=0x153286  c20400                         ret    0x4

; flying_base_destructor | base destructor releases stored path string
; VA 0x553f50..0x553f82 RAW 0x153350 len 50 SHA256 65cca71f273682ba621bd3b47f08f862f552fda0dcd9c4abeca4cd128bb72053
0x553f50 raw=0x153350  56                             push   esi
0x553f51 raw=0x153351  8bf1                           mov    esi,ecx
0x553f53 raw=0x153353  c70694ffc000                   mov    DWORD PTR [esi],0xc0ff94
0x553f59 raw=0x153359  837e5c10                       cmp    DWORD PTR [esi+0x5c],0x10
0x553f5d raw=0x15335d  720c                           jb     0x553f6b
0x553f5f raw=0x15335f  8b4648                         mov    eax,DWORD PTR [esi+0x48]
0x553f62 raw=0x153362  50                             push   eax
0x553f63 raw=0x153363  e8a4d23300                     call   0x89120c
0x553f68 raw=0x153368  83c404                         add    esp,0x4
0x553f6b raw=0x15336b  33c0                           xor    eax,eax
0x553f6d raw=0x15336d  c7465c0f000000                 mov    DWORD PTR [esi+0x5c],0xf
0x553f74 raw=0x153374  894658                         mov    DWORD PTR [esi+0x58],eax
0x553f77 raw=0x153377  884648                         mov    BYTE PTR [esi+0x48],al
0x553f7a raw=0x15337a  c70634ffc000                   mov    DWORD PTR [esi],0xc0ff34
0x553f80 raw=0x153380  5e                             pop    esi
0x553f81 raw=0x153381  c3                             ret

; q_prolog_start | Q.Prolog reads one int and starts singleton FC1B18
; VA 0x564ba0..0x564c50 RAW 0x163fa0 len 176 SHA256 efd24808cfc01d72545035dafb5bc9292db5bc59cb32c4e7dbc1d81e560945c0
0x564ba0 raw=0x163fa0  55                             push   ebp
0x564ba1 raw=0x163fa1  8bec                           mov    ebp,esp
0x564ba3 raw=0x163fa3  6aff                           push   0xffffffff
0x564ba5 raw=0x163fa5  688caa9300                     push   0x93aa8c
0x564baa raw=0x163faa  64a100000000                   mov    eax,fs:0x0
0x564bb0 raw=0x163fb0  50                             push   eax
0x564bb1 raw=0x163fb1  53                             push   ebx
0x564bb2 raw=0x163fb2  a1201fd600                     mov    eax,ds:0xd61f20
0x564bb7 raw=0x163fb7  33c5                           xor    eax,ebp
0x564bb9 raw=0x163fb9  50                             push   eax
0x564bba raw=0x163fba  8d45f4                         lea    eax,[ebp-0xc]
0x564bbd raw=0x163fbd  64a300000000                   mov    fs:0x0,eax
0x564bc3 raw=0x163fc3  bb01000000                     mov    ebx,0x1
0x564bc8 raw=0x163fc8  841dd4adfa00                   test   BYTE PTR ds:0xfaadd4,bl
0x564bce raw=0x163fce  7526                           jne    0x564bf6
0x564bd0 raw=0x163fd0  091dd4adfa00                   or     DWORD PTR ds:0xfaadd4,ebx
0x564bd6 raw=0x163fd6  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
0x564bdd raw=0x163fdd  e89e280200                     call   0x587480
0x564be2 raw=0x163fe2  68c0ccbc00                     push   0xbcccc0
0x564be7 raw=0x163fe7  e82ed73200                     call   0x89231a
0x564bec raw=0x163fec  83c404                         add    esp,0x4
0x564bef raw=0x163fef  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
0x564bf6 raw=0x163ff6  d9e8                           fld1
0x564bf8 raw=0x163ff8  83ec08                         sub    esp,0x8
0x564bfb raw=0x163ffb  d9542404                       fst    DWORD PTR [esp+0x4]
0x564bff raw=0x163fff  d91c24                         fstp   DWORD PTR [esp]
0x564c02 raw=0x164002  e8194e0200                     call   0x589a20
0x564c07 raw=0x164007  841d141bfc00                   test   BYTE PTR ds:0xfc1b14,bl
0x564c0d raw=0x16400d  7522                           jne    0x564c31
0x564c0f raw=0x16400f  091d141bfc00                   or     DWORD PTR ds:0xfc1b14,ebx
0x564c15 raw=0x164015  895dfc                         mov    DWORD PTR [ebp-0x4],ebx
0x564c18 raw=0x164018  e873a2ffff                     call   0x55ee90
0x564c1d raw=0x16401d  6890dfbc00                     push   0xbcdf90
0x564c22 raw=0x164022  e8f3d63200                     call   0x89231a
0x564c27 raw=0x164027  83c404                         add    esp,0x4
0x564c2a raw=0x16402a  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
0x564c31 raw=0x164031  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x564c34 raw=0x164034  68181bfc00                     push   0xfc1b18
0x564c39 raw=0x164039  e842abffff                     call   0x55f780
0x564c3e raw=0x16403e  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x564c41 raw=0x164041  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x564c48 raw=0x164048  59                             pop    ecx
0x564c49 raw=0x164049  5b                             pop    ebx
0x564c4a raw=0x16404a  8be5                           mov    esp,ebp
0x564c4c raw=0x16404c  5d                             pop    ebp
0x564c4d raw=0x16404d  c20400                         ret    0x4

; q_prolog_read | Q.IsPrologRunning lazy initializes then returns FC1B18
; VA 0x564c50..0x564cb2 RAW 0x164050 len 98 SHA256 876c659f103de4af5a47af3405b2a2d5405cdae573a2631516be876b3f94c09e
0x564c50 raw=0x164050  55                             push   ebp
0x564c51 raw=0x164051  8bec                           mov    ebp,esp
0x564c53 raw=0x164053  6aff                           push   0xffffffff
0x564c55 raw=0x164055  68aea99300                     push   0x93a9ae
0x564c5a raw=0x16405a  64a100000000                   mov    eax,fs:0x0
0x564c60 raw=0x164060  50                             push   eax
0x564c61 raw=0x164061  a1201fd600                     mov    eax,ds:0xd61f20
0x564c66 raw=0x164066  33c5                           xor    eax,ebp
0x564c68 raw=0x164068  50                             push   eax
0x564c69 raw=0x164069  8d45f4                         lea    eax,[ebp-0xc]
0x564c6c raw=0x16406c  64a300000000                   mov    fs:0x0,eax
0x564c72 raw=0x164072  b801000000                     mov    eax,0x1
0x564c77 raw=0x164077  8405141bfc00                   test   BYTE PTR ds:0xfc1b14,al
0x564c7d raw=0x16407d  751f                           jne    0x564c9e
0x564c7f raw=0x16407f  0905141bfc00                   or     DWORD PTR ds:0xfc1b14,eax
0x564c85 raw=0x164085  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
0x564c8c raw=0x16408c  e8ffa1ffff                     call   0x55ee90
0x564c91 raw=0x164091  6890dfbc00                     push   0xbcdf90
0x564c96 raw=0x164096  e87fd63200                     call   0x89231a
0x564c9b raw=0x16409b  83c404                         add    esp,0x4
0x564c9e raw=0x16409e  a1181bfc00                     mov    eax,ds:0xfc1b18
0x564ca3 raw=0x1640a3  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x564ca6 raw=0x1640a6  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x564cad raw=0x1640ad  59                             pop    ecx
0x564cae raw=0x1640ae  8be5                           mov    esp,ebp
0x564cb0 raw=0x1640b0  5d                             pop    ebp
0x564cb1 raw=0x1640b1  c3                             ret

; prolog_start | active set1, dialogue key lookup, missing key clears0; selected rows queued
; VA 0x55f780..0x55f89b RAW 0x15eb80 len 283 SHA256 8e9f5a0e1a2f7bdea93f5230493eef1e72ba9bc26eea7033d193d57853366576
0x55f780 raw=0x15eb80  55                             push   ebp
0x55f781 raw=0x15eb81  8bec                           mov    ebp,esp
0x55f783 raw=0x15eb83  83ec10                         sub    esp,0x10
0x55f786 raw=0x15eb86  53                             push   ebx
0x55f787 raw=0x15eb87  8b5d08                         mov    ebx,DWORD PTR [ebp+0x8]
0x55f78a raw=0x15eb8a  833b00                         cmp    DWORD PTR [ebx],0x0
0x55f78d raw=0x15eb8d  56                             push   esi
0x55f78e raw=0x15eb8e  57                             push   edi
0x55f78f raw=0x15eb8f  8bf0                           mov    esi,eax
0x55f791 raw=0x15eb91  7409                           je     0x55f79c
0x55f793 raw=0x15eb93  8bc3                           mov    eax,ebx
0x55f795 raw=0x15eb95  e836feffff                     call   0x55f5d0
0x55f79a raw=0x15eb9a  eb06                           jmp    0x55f7a2
0x55f79c raw=0x15eb9c  c70301000000                   mov    DWORD PTR [ebx],0x1
0x55f7a2 raw=0x15eba2  8d45fc                         lea    eax,[ebp-0x4]
0x55f7a5 raw=0x15eba5  50                             push   eax
0x55f7a6 raw=0x15eba6  8d4b40                         lea    ecx,[ebx+0x40]
0x55f7a9 raw=0x15eba9  8d45f8                         lea    eax,[ebp-0x8]
0x55f7ac raw=0x15ebac  8975fc                         mov    DWORD PTR [ebp-0x4],esi
0x55f7af raw=0x15ebaf  e80c412e00                     call   0x8438c0
0x55f7b4 raw=0x15ebb4  8b45f8                         mov    eax,DWORD PTR [ebp-0x8]
0x55f7b7 raw=0x15ebb7  3b4344                         cmp    eax,DWORD PTR [ebx+0x44]
0x55f7ba raw=0x15ebba  740a                           je     0x55f7c6
0x55f7bc raw=0x15ebbc  8b7810                         mov    edi,DWORD PTR [eax+0x10]
0x55f7bf raw=0x15ebbf  897df8                         mov    DWORD PTR [ebp-0x8],edi
0x55f7c2 raw=0x15ebc2  85ff                           test   edi,edi
0x55f7c4 raw=0x15ebc4  7516                           jne    0x55f7dc
0x55f7c6 raw=0x15ebc6  8bc3                           mov    eax,ebx
0x55f7c8 raw=0x15ebc8  e803feffff                     call   0x55f5d0
0x55f7cd raw=0x15ebcd  c70300000000                   mov    DWORD PTR [ebx],0x0
0x55f7d3 raw=0x15ebd3  5f                             pop    edi
0x55f7d4 raw=0x15ebd4  5e                             pop    esi
0x55f7d5 raw=0x15ebd5  5b                             pop    ebx
0x55f7d6 raw=0x15ebd6  8be5                           mov    esp,ebp
0x55f7d8 raw=0x15ebd8  5d                             pop    ebp
0x55f7d9 raw=0x15ebd9  c20400                         ret    0x4
0x55f7dc raw=0x15ebdc  897338                         mov    DWORD PTR [ebx+0x38],esi
0x55f7df raw=0x15ebdf  33f6                           xor    esi,esi
0x55f7e1 raw=0x15ebe1  897328                         mov    DWORD PTR [ebx+0x28],esi
0x55f7e4 raw=0x15ebe4  8b4f04                         mov    ecx,DWORD PTR [edi+0x4]
0x55f7e7 raw=0x15ebe7  2b0f                           sub    ecx,DWORD PTR [edi]
0x55f7e9 raw=0x15ebe9  b889888888                     mov    eax,0x88888889
0x55f7ee raw=0x15ebee  f7e9                           imul   ecx
0x55f7f0 raw=0x15ebf0  03d1                           add    edx,ecx
0x55f7f2 raw=0x15ebf2  c1fa05                         sar    edx,0x5
0x55f7f5 raw=0x15ebf5  8bc2                           mov    eax,edx
0x55f7f7 raw=0x15ebf7  c1e81f                         shr    eax,0x1f
0x55f7fa raw=0x15ebfa  03c2                           add    eax,edx
0x55f7fc raw=0x15ebfc  747b                           je     0x55f879
0x55f7fe raw=0x15ebfe  33db                           xor    ebx,ebx
0x55f800 raw=0x15ec00  8945fc                         mov    DWORD PTR [ebp-0x4],eax
0x55f803 raw=0x15ec03  eb05                           jmp    0x55f80a
0x55f805 raw=0x15ec05  8b7df8                         mov    edi,DWORD PTR [ebp-0x8]
0x55f808 raw=0x15ec08  33f6                           xor    esi,esi
0x55f80a raw=0x15ec0a  6a3c                           push   0x3c
0x55f80c raw=0x15ec0c  e8571a3300                     call   0x891268
0x55f811 raw=0x15ec11  83c404                         add    esp,0x4
0x55f814 raw=0x15ec14  3bc6                           cmp    eax,esi
0x55f816 raw=0x15ec16  741e                           je     0x55f836
0x55f818 raw=0x15ec18  897010                         mov    DWORD PTR [eax+0x10],esi
0x55f81b raw=0x15ec1b  c7401407000000                 mov    DWORD PTR [eax+0x14],0x7
0x55f822 raw=0x15ec22  33c9                           xor    ecx,ecx
0x55f824 raw=0x15ec24  668908                         mov    WORD PTR [eax],cx
0x55f827 raw=0x15ec27  89702c                         mov    DWORD PTR [eax+0x2c],esi
0x55f82a raw=0x15ec2a  c740300f000000                 mov    DWORD PTR [eax+0x30],0xf
0x55f831 raw=0x15ec31  88481c                         mov    BYTE PTR [eax+0x1c],cl
0x55f834 raw=0x15ec34  8bf0                           mov    esi,eax
0x55f836 raw=0x15ec36  8b3f                           mov    edi,DWORD PTR [edi]
0x55f838 raw=0x15ec38  6aff                           push   0xffffffff
0x55f83a raw=0x15ec3a  6a00                           push   0x0
0x55f83c raw=0x15ec3c  03fb                           add    edi,ebx
0x55f83e raw=0x15ec3e  57                             push   edi
0x55f83f raw=0x15ec3f  8bce                           mov    ecx,esi
0x55f841 raw=0x15ec41  8975f4                         mov    DWORD PTR [ebp-0xc],esi
0x55f844 raw=0x15ec44  e8972eeaff                     call   0x4026e0
0x55f849 raw=0x15ec49  6aff                           push   0xffffffff
0x55f84b raw=0x15ec4b  6a00                           push   0x0
0x55f84d raw=0x15ec4d  8d571c                         lea    edx,[edi+0x1c]
0x55f850 raw=0x15ec50  52                             push   edx
0x55f851 raw=0x15ec51  8d4e1c                         lea    ecx,[esi+0x1c]
0x55f854 raw=0x15ec54  e8e737eaff                     call   0x403040
0x55f859 raw=0x15ec59  8b4738                         mov    eax,DWORD PTR [edi+0x38]
0x55f85c raw=0x15ec5c  894638                         mov    DWORD PTR [esi+0x38],eax
0x55f85f raw=0x15ec5f  8b7508                         mov    esi,DWORD PTR [ebp+0x8]
0x55f862 raw=0x15ec62  8d4df4                         lea    ecx,[ebp-0xc]
0x55f865 raw=0x15ec65  51                             push   ecx
0x55f866 raw=0x15ec66  83c60c                         add    esi,0xc
0x55f869 raw=0x15ec69  e8f2492a00                     call   0x804260
0x55f86e raw=0x15ec6e  83c33c                         add    ebx,0x3c
0x55f871 raw=0x15ec71  ff4dfc                         dec    DWORD PTR [ebp-0x4]
0x55f874 raw=0x15ec74  758f                           jne    0x55f805
0x55f876 raw=0x15ec76  8b5d08                         mov    ebx,DWORD PTR [ebp+0x8]
0x55f879 raw=0x15ec79  53                             push   ebx
0x55f87a raw=0x15ec7a  e8f1fbffff                     call   0x55f470
0x55f87f raw=0x15ec7f  c7432c01000000                 mov    DWORD PTR [ebx+0x2c],0x1
0x55f886 raw=0x15ec86  d94350                         fld    DWORD PTR [ebx+0x50]
0x55f889 raw=0x15ec89  d95b58                         fstp   DWORD PTR [ebx+0x58]
0x55f88c raw=0x15ec8c  5f                             pop    edi
0x55f88d raw=0x15ec8d  d94360                         fld    DWORD PTR [ebx+0x60]
0x55f890 raw=0x15ec90  5e                             pop    esi
0x55f891 raw=0x15ec91  d95b68                         fstp   DWORD PTR [ebx+0x68]
0x55f894 raw=0x15ec94  5b                             pop    ebx
0x55f895 raw=0x15ec95  8be5                           mov    esp,ebp
0x55f897 raw=0x15ec97  5d                             pop    ebp
0x55f898 raw=0x15ec98  c20400                         ret    0x4

; prolog_close | cleanup, active0, UI eventF434F and additional cleanup helper
; VA 0x55f8a0..0x55f94e RAW 0x15eca0 len 174 SHA256 94ab45d493e9cd91ada95d6198bc97d5eefb1c5ff2996e9b4a1b9a32936527a4
0x55f8a0 raw=0x15eca0  55                             push   ebp
0x55f8a1 raw=0x15eca1  8bec                           mov    ebp,esp
0x55f8a3 raw=0x15eca3  6aff                           push   0xffffffff
0x55f8a5 raw=0x15eca5  68bc2f9200                     push   0x922fbc
0x55f8aa raw=0x15ecaa  64a100000000                   mov    eax,fs:0x0
0x55f8b0 raw=0x15ecb0  50                             push   eax
0x55f8b1 raw=0x15ecb1  51                             push   ecx
0x55f8b2 raw=0x15ecb2  53                             push   ebx
0x55f8b3 raw=0x15ecb3  a1201fd600                     mov    eax,ds:0xd61f20
0x55f8b8 raw=0x15ecb8  33c5                           xor    eax,ebp
0x55f8ba raw=0x15ecba  50                             push   eax
0x55f8bb raw=0x15ecbb  8d45f4                         lea    eax,[ebp-0xc]
0x55f8be raw=0x15ecbe  64a300000000                   mov    fs:0x0,eax
0x55f8c4 raw=0x15ecc4  8bc6                           mov    eax,esi
0x55f8c6 raw=0x15ecc6  e805fdffff                     call   0x55f5d0
0x55f8cb raw=0x15eccb  bb01000000                     mov    ebx,0x1
0x55f8d0 raw=0x15ecd0  c70600000000                   mov    DWORD PTR [esi],0x0
0x55f8d6 raw=0x15ecd6  841dd4adfa00                   test   BYTE PTR ds:0xfaadd4,bl
0x55f8dc raw=0x15ecdc  7526                           jne    0x55f904
0x55f8de raw=0x15ecde  091dd4adfa00                   or     DWORD PTR ds:0xfaadd4,ebx
0x55f8e4 raw=0x15ece4  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
0x55f8eb raw=0x15eceb  e8907b0200                     call   0x587480
0x55f8f0 raw=0x15ecf0  68c0ccbc00                     push   0xbcccc0
0x55f8f5 raw=0x15ecf5  e8202a3300                     call   0x89231a
0x55f8fa raw=0x15ecfa  83c404                         add    esp,0x4
0x55f8fd raw=0x15ecfd  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
0x55f904 raw=0x15ed04  684f430f00                     push   0xf434f
0x55f909 raw=0x15ed09  e8c2b10200                     call   0x58aad0
0x55f90e raw=0x15ed0e  83c404                         add    esp,0x4
0x55f911 raw=0x15ed11  841da472fb00                   test   BYTE PTR ds:0xfb72a4,bl
0x55f917 raw=0x15ed17  751b                           jne    0x55f934
0x55f919 raw=0x15ed19  091da472fb00                   or     DWORD PTR ds:0xfb72a4,ebx
0x55f91f raw=0x15ed1f  895dfc                         mov    DWORD PTR [ebp-0x4],ebx
0x55f922 raw=0x15ed22  e829fff3ff                     call   0x49f850
0x55f927 raw=0x15ed27  68e0cfbc00                     push   0xbccfe0
0x55f92c raw=0x15ed2c  e8e9293300                     call   0x89231a
0x55f931 raw=0x15ed31  83c404                         add    esp,0x4
0x55f934 raw=0x15ed34  baa872fb00                     mov    edx,0xfb72a8
0x55f939 raw=0x15ed39  e8020cf4ff                     call   0x4a0540
0x55f93e raw=0x15ed3e  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x55f941 raw=0x15ed41  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x55f948 raw=0x15ed48  59                             pop    ecx
0x55f949 raw=0x15ed49  5b                             pop    ebx
0x55f94a raw=0x15ed4a  8be5                           mov    esp,ebp
0x55f94c raw=0x15ed4c  5d                             pop    ebp
0x55f94d raw=0x15ed4d  c3                             ret

; prolog_public_close | Prolog.OnClose active gate
; VA 0x55f950..0x55f95f RAW 0x15ed50 len 15 SHA256 ae235a69393c5a125e6b0a00809e784bf4f6db90d733d1859924ba50651e2d95
0x55f950 raw=0x15ed50  833900                         cmp    DWORD PTR [ecx],0x0
0x55f953 raw=0x15ed53  56                             push   esi
0x55f954 raw=0x15ed54  7407                           je     0x55f95d
0x55f956 raw=0x15ed56  8bf1                           mov    esi,ecx
0x55f958 raw=0x15ed58  e843ffffff                     call   0x55f8a0
0x55f95d raw=0x15ed5d  5e                             pop    esi
0x55f95e raw=0x15ed5e  c3                             ret

; prolog_next | finish displayed line / dequeue next; exhaustion+28 calls close
; VA 0x55f960..0x55f9c4 RAW 0x15ed60 len 100 SHA256 1a3636a80b71932b58b153efad7ebfe77379e5f7d6553c15fbe8982611336071
0x55f960 raw=0x15ed60  56                             push   esi
0x55f961 raw=0x15ed61  8bf0                           mov    esi,eax
0x55f963 raw=0x15ed63  837e2c00                       cmp    DWORD PTR [esi+0x2c],0x0
0x55f967 raw=0x15ed67  750e                           jne    0x55f977
0x55f969 raw=0x15ed69  8b4604                         mov    eax,DWORD PTR [esi+0x4]
0x55f96c raw=0x15ed6c  8b4810                         mov    ecx,DWORD PTR [eax+0x10]
0x55f96f raw=0x15ed6f  394834                         cmp    DWORD PTR [eax+0x34],ecx
0x55f972 raw=0x15ed72  7405                           je     0x55f979
0x55f974 raw=0x15ed74  894834                         mov    DWORD PTR [eax+0x34],ecx
0x55f977 raw=0x15ed77  5e                             pop    esi
0x55f978 raw=0x15ed78  c3                             ret
0x55f979 raw=0x15ed79  8b4e08                         mov    ecx,DWORD PTR [esi+0x8]
0x55f97c raw=0x15ed7c  85c9                           test   ecx,ecx
0x55f97e raw=0x15ed7e  740e                           je     0x55f98e
0x55f980 raw=0x15ed80  8b01                           mov    eax,DWORD PTR [ecx]
0x55f982 raw=0x15ed82  8b5008                         mov    edx,DWORD PTR [eax+0x8]
0x55f985 raw=0x15ed85  ffd2                           call   edx
0x55f987 raw=0x15ed87  c7460800000000                 mov    DWORD PTR [esi+0x8],0x0
0x55f98e raw=0x15ed8e  56                             push   esi
0x55f98f raw=0x15ed8f  e8dcfaffff                     call   0x55f470
0x55f994 raw=0x15ed94  837e2800                       cmp    DWORD PTR [esi+0x28],0x0
0x55f998 raw=0x15ed98  7407                           je     0x55f9a1
0x55f99a raw=0x15ed9a  e801ffffff                     call   0x55f8a0
0x55f99f raw=0x15ed9f  5e                             pop    esi
0x55f9a0 raw=0x15eda0  c3                             ret
0x55f9a1 raw=0x15eda1  57                             push   edi
0x55f9a2 raw=0x15eda2  8bfe                           mov    edi,esi
0x55f9a4 raw=0x15eda4  e8c7f9ffff                     call   0x55f370
0x55f9a9 raw=0x15eda9  8b4624                         mov    eax,DWORD PTR [esi+0x24]
0x55f9ac raw=0x15edac  5f                             pop    edi
0x55f9ad raw=0x15edad  85c0                           test   eax,eax
0x55f9af raw=0x15edaf  74c6                           je     0x55f977
0x55f9b1 raw=0x15edb1  83781408                       cmp    DWORD PTR [eax+0x14],0x8
0x55f9b5 raw=0x15edb5  7202                           jb     0x55f9b9
0x55f9b7 raw=0x15edb7  8b00                           mov    eax,DWORD PTR [eax]
0x55f9b9 raw=0x15edb9  8b4e04                         mov    ecx,DWORD PTR [esi+0x4]
0x55f9bc raw=0x15edbc  8bd0                           mov    edx,eax
0x55f9be raw=0x15edbe  5e                             pop    esi
0x55f9bf raw=0x15edbf  e95ccc0000                     jmp    0x56c620

; prolog_pop_row | own deque/current row consumer; empty queue sets +28=1
; VA 0x55f470..0x55f5c7 RAW 0x15e870 len 343 SHA256 9cff5412e683386b7c5ddca5c2c9a7a6400b68cc961216f4bcabcb1e239f6937
0x55f470 raw=0x15e870  55                             push   ebp
0x55f471 raw=0x15e871  8bec                           mov    ebp,esp
0x55f473 raw=0x15e873  6aff                           push   0xffffffff
0x55f475 raw=0x15e875  68be949200                     push   0x9294be
0x55f47a raw=0x15e87a  64a100000000                   mov    eax,fs:0x0
0x55f480 raw=0x15e880  50                             push   eax
0x55f481 raw=0x15e881  83ec10                         sub    esp,0x10
0x55f484 raw=0x15e884  53                             push   ebx
0x55f485 raw=0x15e885  56                             push   esi
0x55f486 raw=0x15e886  57                             push   edi
0x55f487 raw=0x15e887  a1201fd600                     mov    eax,ds:0xd61f20
0x55f48c raw=0x15e88c  33c5                           xor    eax,ebp
0x55f48e raw=0x15e88e  50                             push   eax
0x55f48f raw=0x15e88f  8d45f4                         lea    eax,[ebp-0xc]
0x55f492 raw=0x15e892  64a300000000                   mov    fs:0x0,eax
0x55f498 raw=0x15e898  8b5d08                         mov    ebx,DWORD PTR [ebp+0x8]
0x55f49b raw=0x15e89b  8b7324                         mov    esi,DWORD PTR [ebx+0x24]
0x55f49e raw=0x15e89e  33ff                           xor    edi,edi
0x55f4a0 raw=0x15e8a0  3bf7                           cmp    esi,edi
0x55f4a2 raw=0x15e8a2  744c                           je     0x55f4f0
0x55f4a4 raw=0x15e8a4  837e3010                       cmp    DWORD PTR [esi+0x30],0x10
0x55f4a8 raw=0x15e8a8  720c                           jb     0x55f4b6
0x55f4aa raw=0x15e8aa  8b461c                         mov    eax,DWORD PTR [esi+0x1c]
0x55f4ad raw=0x15e8ad  50                             push   eax
0x55f4ae raw=0x15e8ae  e8591d3300                     call   0x89120c
0x55f4b3 raw=0x15e8b3  83c404                         add    esp,0x4
0x55f4b6 raw=0x15e8b6  c746300f000000                 mov    DWORD PTR [esi+0x30],0xf
0x55f4bd raw=0x15e8bd  897e2c                         mov    DWORD PTR [esi+0x2c],edi
0x55f4c0 raw=0x15e8c0  c6461c00                       mov    BYTE PTR [esi+0x1c],0x0
0x55f4c4 raw=0x15e8c4  837e1408                       cmp    DWORD PTR [esi+0x14],0x8
0x55f4c8 raw=0x15e8c8  720b                           jb     0x55f4d5
0x55f4ca raw=0x15e8ca  8b06                           mov    eax,DWORD PTR [esi]
0x55f4cc raw=0x15e8cc  50                             push   eax
0x55f4cd raw=0x15e8cd  e83a1d3300                     call   0x89120c
0x55f4d2 raw=0x15e8d2  83c404                         add    esp,0x4
0x55f4d5 raw=0x15e8d5  33c0                           xor    eax,eax
0x55f4d7 raw=0x15e8d7  c7461407000000                 mov    DWORD PTR [esi+0x14],0x7
0x55f4de raw=0x15e8de  897e10                         mov    DWORD PTR [esi+0x10],edi
0x55f4e1 raw=0x15e8e1  56                             push   esi
0x55f4e2 raw=0x15e8e2  668906                         mov    WORD PTR [esi],ax
0x55f4e5 raw=0x15e8e5  e8221d3300                     call   0x89120c
0x55f4ea raw=0x15e8ea  83c404                         add    esp,0x4
0x55f4ed raw=0x15e8ed  897b24                         mov    DWORD PTR [ebx+0x24],edi
0x55f4f0 raw=0x15e8f0  397b1c                         cmp    DWORD PTR [ebx+0x1c],edi
0x55f4f3 raw=0x15e8f3  0f84b3000000                   je     0x55f5ac
0x55f4f9 raw=0x15e8f9  8d45e8                         lea    eax,[ebp-0x18]
0x55f4fc raw=0x15e8fc  8d4b0c                         lea    ecx,[ebx+0xc]
0x55f4ff raw=0x15e8ff  e80c2dfeff                     call   0x542210
0x55f504 raw=0x15e904  8b08                           mov    ecx,DWORD PTR [eax]
0x55f506 raw=0x15e906  3bcf                           cmp    ecx,edi
0x55f508 raw=0x15e908  7504                           jne    0x55f50e
0x55f50a raw=0x15e90a  33d2                           xor    edx,edx
0x55f50c raw=0x15e90c  eb02                           jmp    0x55f510
0x55f50e raw=0x15e90e  8b11                           mov    edx,DWORD PTR [ecx]
0x55f510 raw=0x15e910  8b4808                         mov    ecx,DWORD PTR [eax+0x8]
0x55f513 raw=0x15e913  8b7a08                         mov    edi,DWORD PTR [edx+0x8]
0x55f516 raw=0x15e916  8bc1                           mov    eax,ecx
0x55f518 raw=0x15e918  c1e802                         shr    eax,0x2
0x55f51b raw=0x15e91b  83e103                         and    ecx,0x3
0x55f51e raw=0x15e91e  3bf8                           cmp    edi,eax
0x55f520 raw=0x15e920  7702                           ja     0x55f524
0x55f522 raw=0x15e922  2bc7                           sub    eax,edi
0x55f524 raw=0x15e924  8b5204                         mov    edx,DWORD PTR [edx+0x4]
0x55f527 raw=0x15e927  8b0482                         mov    eax,DWORD PTR [edx+eax*4]
0x55f52a raw=0x15e92a  8d0488                         lea    eax,[eax+ecx*4]
0x55f52d raw=0x15e92d  8b08                           mov    ecx,DWORD PTR [eax]
0x55f52f raw=0x15e92f  894b24                         mov    DWORD PTR [ebx+0x24],ecx
0x55f532 raw=0x15e932  8b431c                         mov    eax,DWORD PTR [ebx+0x1c]
0x55f535 raw=0x15e935  33d2                           xor    edx,edx
0x55f537 raw=0x15e937  3bc2                           cmp    eax,edx
0x55f539 raw=0x15e939  741d                           je     0x55f558
0x55f53b raw=0x15e93b  8b7b14                         mov    edi,DWORD PTR [ebx+0x14]
0x55f53e raw=0x15e93e  ff4318                         inc    DWORD PTR [ebx+0x18]
0x55f541 raw=0x15e941  03ff                           add    edi,edi
0x55f543 raw=0x15e943  03ff                           add    edi,edi
0x55f545 raw=0x15e945  3b7b18                         cmp    edi,DWORD PTR [ebx+0x18]
0x55f548 raw=0x15e948  7703                           ja     0x55f54d
0x55f54a raw=0x15e94a  895318                         mov    DWORD PTR [ebx+0x18],edx
0x55f54d raw=0x15e94d  48                             dec    eax
0x55f54e raw=0x15e94e  89431c                         mov    DWORD PTR [ebx+0x1c],eax
0x55f551 raw=0x15e951  3bc2                           cmp    eax,edx
0x55f553 raw=0x15e953  7503                           jne    0x55f558
0x55f555 raw=0x15e955  895318                         mov    DWORD PTR [ebx+0x18],edx
0x55f558 raw=0x15e958  f605a472fb0001                 test   BYTE PTR ds:0xfb72a4,0x1
0x55f55f raw=0x15e95f  7523                           jne    0x55f584
0x55f561 raw=0x15e961  830da472fb0001                 or     DWORD PTR ds:0xfb72a4,0x1
0x55f568 raw=0x15e968  8955fc                         mov    DWORD PTR [ebp-0x4],edx
0x55f56b raw=0x15e96b  e8e002f4ff                     call   0x49f850
0x55f570 raw=0x15e970  68e0cfbc00                     push   0xbccfe0
0x55f575 raw=0x15e975  e8a02d3300                     call   0x89231a
0x55f57a raw=0x15e97a  83c404                         add    esp,0x4
0x55f57d raw=0x15e97d  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
0x55f584 raw=0x15e984  8b5338                         mov    edx,DWORD PTR [ebx+0x38]
0x55f587 raw=0x15e987  8b4324                         mov    eax,DWORD PTR [ebx+0x24]
0x55f58a raw=0x15e98a  8b4838                         mov    ecx,DWORD PTR [eax+0x38]
0x55f58d raw=0x15e98d  52                             push   edx
0x55f58e raw=0x15e98e  68a872fb00                     push   0xfb72a8
0x55f593 raw=0x15e993  e8580ef4ff                     call   0x4a03f0
0x55f598 raw=0x15e998  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x55f59b raw=0x15e99b  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x55f5a2 raw=0x15e9a2  59                             pop    ecx
0x55f5a3 raw=0x15e9a3  5f                             pop    edi
0x55f5a4 raw=0x15e9a4  5e                             pop    esi
0x55f5a5 raw=0x15e9a5  5b                             pop    ebx
0x55f5a6 raw=0x15e9a6  8be5                           mov    esp,ebp
0x55f5a8 raw=0x15e9a8  5d                             pop    ebp
0x55f5a9 raw=0x15e9a9  c20400                         ret    0x4
0x55f5ac raw=0x15e9ac  c7432801000000                 mov    DWORD PTR [ebx+0x28],0x1
0x55f5b3 raw=0x15e9b3  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x55f5b6 raw=0x15e9b6  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x55f5bd raw=0x15e9bd  59                             pop    ecx
0x55f5be raw=0x15e9be  5f                             pop    edi
0x55f5bf raw=0x15e9bf  5e                             pop    esi
0x55f5c0 raw=0x15e9c0  5b                             pop    ebx
0x55f5c1 raw=0x15e9c1  8be5                           mov    esp,ebp
0x55f5c3 raw=0x15e9c3  5d                             pop    ebp
0x55f5c4 raw=0x15e9c4  c20400                         ret    0x4

; prolog_update | active-only fade1→2→0 and text reveal, UI eventF440B
; VA 0x55f9d0..0x55fac2 RAW 0x15edd0 len 242 SHA256 a618fbe2e5c97241da2d4ea12ec5e5ee9809c8428330cf8df3c5d0e8c842b410
0x55f9d0 raw=0x15edd0  51                             push   ecx
0x55f9d1 raw=0x15edd1  56                             push   esi
0x55f9d2 raw=0x15edd2  57                             push   edi
0x55f9d3 raw=0x15edd3  8bf8                           mov    edi,eax
0x55f9d5 raw=0x15edd5  33f6                           xor    esi,esi
0x55f9d7 raw=0x15edd7  3937                           cmp    DWORD PTR [edi],esi
0x55f9d9 raw=0x15edd9  0f84df000000                   je     0x55fabe
0x55f9df raw=0x15eddf  8b472c                         mov    eax,DWORD PTR [edi+0x2c]
0x55f9e2 raw=0x15ede2  48                             dec    eax
0x55f9e3 raw=0x15ede3  7437                           je     0x55fa1c
0x55f9e5 raw=0x15ede5  48                             dec    eax
0x55f9e6 raw=0x15ede6  7568                           jne    0x55fa50
0x55f9e8 raw=0x15ede8  d905a85cc500                   fld    DWORD PTR ds:0xc55ca8
0x55f9ee raw=0x15edee  51                             push   ecx
0x55f9ef raw=0x15edef  8d4f60                         lea    ecx,[edi+0x60]
0x55f9f2 raw=0x15edf2  d91c24                         fstp   DWORD PTR [esp]
0x55f9f5 raw=0x15edf5  e866f3ffff                     call   0x55ed60
0x55f9fa raw=0x15edfa  85c0                           test   eax,eax
0x55f9fc raw=0x15edfc  7452                           je     0x55fa50
0x55f9fe raw=0x15edfe  8b4724                         mov    eax,DWORD PTR [edi+0x24]
0x55fa01 raw=0x15ee01  3bc6                           cmp    eax,esi
0x55fa03 raw=0x15ee03  7412                           je     0x55fa17
0x55fa05 raw=0x15ee05  83781408                       cmp    DWORD PTR [eax+0x14],0x8
0x55fa09 raw=0x15ee09  7202                           jb     0x55fa0d
0x55fa0b raw=0x15ee0b  8b00                           mov    eax,DWORD PTR [eax]
0x55fa0d raw=0x15ee0d  8b4f04                         mov    ecx,DWORD PTR [edi+0x4]
0x55fa10 raw=0x15ee10  8bd0                           mov    edx,eax
0x55fa12 raw=0x15ee12  e809cc0000                     call   0x56c620
0x55fa17 raw=0x15ee17  89772c                         mov    DWORD PTR [edi+0x2c],esi
0x55fa1a raw=0x15ee1a  eb34                           jmp    0x55fa50
0x55fa1c raw=0x15ee1c  d905a85cc500                   fld    DWORD PTR ds:0xc55ca8
0x55fa22 raw=0x15ee22  51                             push   ecx
0x55fa23 raw=0x15ee23  8d4f50                         lea    ecx,[edi+0x50]
0x55fa26 raw=0x15ee26  d91c24                         fstp   DWORD PTR [esp]
0x55fa29 raw=0x15ee29  e832f3ffff                     call   0x55ed60
0x55fa2e raw=0x15ee2e  85c0                           test   eax,eax
0x55fa30 raw=0x15ee30  741e                           je     0x55fa50
0x55fa32 raw=0x15ee32  c7472c02000000                 mov    DWORD PTR [edi+0x2c],0x2
0x55fa39 raw=0x15ee39  e8825aeaff                     call   0x4054c0
0x55fa3e raw=0x15ee3e  6820430f00                     push   0xf4320
0x55fa43 raw=0x15ee43  e888b00200                     call   0x58aad0
0x55fa48 raw=0x15ee48  83c404                         add    esp,0x4
0x55fa4b raw=0x15ee4b  e820f9ffff                     call   0x55f370
0x55fa50 raw=0x15ee50  39772c                         cmp    DWORD PTR [edi+0x2c],esi
0x55fa53 raw=0x15ee53  752e                           jne    0x55fa83
0x55fa55 raw=0x15ee55  8b4704                         mov    eax,DWORD PTR [edi+0x4]
0x55fa58 raw=0x15ee58  397028                         cmp    DWORD PTR [eax+0x28],esi
0x55fa5b raw=0x15ee5b  7426                           je     0x55fa83
0x55fa5d raw=0x15ee5d  8b483c                         mov    ecx,DWORD PTR [eax+0x3c]
0x55fa60 raw=0x15ee60  8d51ff                         lea    edx,[ecx-0x1]
0x55fa63 raw=0x15ee63  89503c                         mov    DWORD PTR [eax+0x3c],edx
0x55fa66 raw=0x15ee66  3bce                           cmp    ecx,esi
0x55fa68 raw=0x15ee68  7f19                           jg     0x55fa83
0x55fa6a raw=0x15ee6a  8b4838                         mov    ecx,DWORD PTR [eax+0x38]
0x55fa6d raw=0x15ee6d  8b5034                         mov    edx,DWORD PTR [eax+0x34]
0x55fa70 raw=0x15ee70  89483c                         mov    DWORD PTR [eax+0x3c],ecx
0x55fa73 raw=0x15ee73  8b4810                         mov    ecx,DWORD PTR [eax+0x10]
0x55fa76 raw=0x15ee76  3bd1                           cmp    edx,ecx
0x55fa78 raw=0x15ee78  7c05                           jl     0x55fa7f
0x55fa7a raw=0x15ee7a  894834                         mov    DWORD PTR [eax+0x34],ecx
0x55fa7d raw=0x15ee7d  eb04                           jmp    0x55fa83
0x55fa7f raw=0x15ee7f  42                             inc    edx
0x55fa80 raw=0x15ee80  895034                         mov    DWORD PTR [eax+0x34],edx
0x55fa83 raw=0x15ee83  6a14                           push   0x14
0x55fa85 raw=0x15ee85  e8de173300                     call   0x891268
0x55fa8a raw=0x15ee8a  83c404                         add    esp,0x4
0x55fa8d raw=0x15ee8d  3bc6                           cmp    eax,esi
0x55fa8f raw=0x15ee8f  7424                           je     0x55fab5
0x55fa91 raw=0x15ee91  83c9ff                         or     ecx,0xffffffff
0x55fa94 raw=0x15ee94  89700c                         mov    DWORD PTR [eax+0xc],esi
0x55fa97 raw=0x15ee97  8bf0                           mov    esi,eax
0x55fa99 raw=0x15ee99  c7000c7bc400                   mov    DWORD PTR [eax],0xc47b0c
0x55fa9f raw=0x15ee9f  894804                         mov    DWORD PTR [eax+0x4],ecx
0x55faa2 raw=0x15eea2  894808                         mov    DWORD PTR [eax+0x8],ecx
0x55faa5 raw=0x15eea5  c740100b440f00                 mov    DWORD PTR [eax+0x10],0xf440b
0x55faac raw=0x15eeac  e8ef77eaff                     call   0x4072a0
0x55fab1 raw=0x15eeb1  5f                             pop    edi
0x55fab2 raw=0x15eeb2  5e                             pop    esi
0x55fab3 raw=0x15eeb3  59                             pop    ecx
0x55fab4 raw=0x15eeb4  c3                             ret
0x55fab5 raw=0x15eeb5  33c0                           xor    eax,eax
0x55fab7 raw=0x15eeb7  8bf0                           mov    esi,eax
0x55fab9 raw=0x15eeb9  e8e277eaff                     call   0x4072a0
0x55fabe raw=0x15eebe  5f                             pop    edi
0x55fabf raw=0x15eebf  5e                             pop    esi
0x55fac0 raw=0x15eec0  59                             pop    ecx
0x55fac1 raw=0x15eec1  c3                             ret

; prolog_owner_get | native helper returns FC1B18
; VA 0x48a0b0..0x48a112 RAW 0x894b0 len 98 SHA256 e313dfb1b7feeb68b32ae21b9fd84e2741c8df128a61adbd28083e1eb8f9fadd
0x48a0b0 raw=0x894b0  55                             push   ebp
0x48a0b1 raw=0x894b1  8bec                           mov    ebp,esp
0x48a0b3 raw=0x894b3  6aff                           push   0xffffffff
0x48a0b5 raw=0x894b5  68aea99300                     push   0x93a9ae
0x48a0ba raw=0x894ba  64a100000000                   mov    eax,fs:0x0
0x48a0c0 raw=0x894c0  50                             push   eax
0x48a0c1 raw=0x894c1  a1201fd600                     mov    eax,ds:0xd61f20
0x48a0c6 raw=0x894c6  33c5                           xor    eax,ebp
0x48a0c8 raw=0x894c8  50                             push   eax
0x48a0c9 raw=0x894c9  8d45f4                         lea    eax,[ebp-0xc]
0x48a0cc raw=0x894cc  64a300000000                   mov    fs:0x0,eax
0x48a0d2 raw=0x894d2  b801000000                     mov    eax,0x1
0x48a0d7 raw=0x894d7  8405141bfc00                   test   BYTE PTR ds:0xfc1b14,al
0x48a0dd raw=0x894dd  751f                           jne    0x48a0fe
0x48a0df raw=0x894df  0905141bfc00                   or     DWORD PTR ds:0xfc1b14,eax
0x48a0e5 raw=0x894e5  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
0x48a0ec raw=0x894ec  e89f4d0d00                     call   0x55ee90
0x48a0f1 raw=0x894f1  6890dfbc00                     push   0xbcdf90
0x48a0f6 raw=0x894f6  e81f824000                     call   0x89231a
0x48a0fb raw=0x894fb  83c404                         add    esp,0x4
0x48a0fe raw=0x894fe  b8181bfc00                     mov    eax,0xfc1b18
0x48a103 raw=0x89503  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x48a106 raw=0x89506  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x48a10d raw=0x8950d  59                             pop    ecx
0x48a10e raw=0x8950e  8be5                           mov    esp,ebp
0x48a110 raw=0x89510  5d                             pop    ebp
0x48a111 raw=0x89511  c3                             ret

; prolog_frame_caller | bounded actual frame call context:48A0B0→55F9D0
; VA 0x491ed0..0x491ee6 RAW 0x912d0 len 22 SHA256 05cb4144866f036a541d37f55cdea225c8dcbfa757f0cfba90917dcec150688a
0x491ed0 raw=0x912d0  e86b10f9ff                     call   0x422f40
0x491ed5 raw=0x912d5  8bc8                           mov    ecx,eax
0x491ed7 raw=0x912d7  e844f60c00                     call   0x561520
0x491edc raw=0x912dc  e8cf81ffff                     call   0x48a0b0
0x491ee1 raw=0x912e1  e8eada0c00                     call   0x55f9d0

; prolog_panel_constructor | alloc0x8C CPrologBookPanel, cached UI id0x11C
; VA 0x5a3650..0x5a36e7 RAW 0x1a2a50 len 151 SHA256 7bd97cd6510bab7a7ba275c591450159c1d1be71144d3f46140996371ce16ec1
0x5a3650 raw=0x1a2a50  55                             push   ebp
0x5a3651 raw=0x1a2a51  8bec                           mov    ebp,esp
0x5a3653 raw=0x1a2a53  6aff                           push   0xffffffff
0x5a3655 raw=0x1a2a55  6820189200                     push   0x921820
0x5a365a raw=0x1a2a5a  64a100000000                   mov    eax,fs:0x0
0x5a3660 raw=0x1a2a60  50                             push   eax
0x5a3661 raw=0x1a2a61  51                             push   ecx
0x5a3662 raw=0x1a2a62  53                             push   ebx
0x5a3663 raw=0x1a2a63  56                             push   esi
0x5a3664 raw=0x1a2a64  57                             push   edi
0x5a3665 raw=0x1a2a65  a1201fd600                     mov    eax,ds:0xd61f20
0x5a366a raw=0x1a2a6a  33c5                           xor    eax,ebp
0x5a366c raw=0x1a2a6c  50                             push   eax
0x5a366d raw=0x1a2a6d  8d45f4                         lea    eax,[ebp-0xc]
0x5a3670 raw=0x1a2a70  64a300000000                   mov    fs:0x0,eax
0x5a3676 raw=0x1a2a76  8b7d08                         mov    edi,DWORD PTR [ebp+0x8]
0x5a3679 raw=0x1a2a79  33db                           xor    ebx,ebx
0x5a367b raw=0x1a2a7b  895f04                         mov    DWORD PTR [edi+0x4],ebx
0x5a367e raw=0x1a2a7e  895f08                         mov    DWORD PTR [edi+0x8],ebx
0x5a3681 raw=0x1a2a81  895dfc                         mov    DWORD PTR [ebp-0x4],ebx
0x5a3684 raw=0x1a2a84  688c000000                     push   0x8c
0x5a3689 raw=0x1a2a89  c707b0bec100                   mov    DWORD PTR [edi],0xc1beb0
0x5a368f raw=0x1a2a8f  e8d4e92e00                     call   0x892068
0x5a3694 raw=0x1a2a94  8bf0                           mov    esi,eax
0x5a3696 raw=0x1a2a96  83c404                         add    esp,0x4
0x5a3699 raw=0x1a2a99  8975f0                         mov    DWORD PTR [ebp-0x10],esi
0x5a369c raw=0x1a2a9c  c645fc01                       mov    BYTE PTR [ebp-0x4],0x1
0x5a36a0 raw=0x1a2aa0  3bf3                           cmp    esi,ebx
0x5a36a2 raw=0x1a2aa2  7421                           je     0x5a36c5
0x5a36a4 raw=0x1a2aa4  8bce                           mov    ecx,esi
0x5a36a6 raw=0x1a2aa6  e8451b1a00                     call   0x7451f0
0x5a36ab raw=0x1a2aab  c706f4f5c300                   mov    DWORD PTR [esi],0xc3f5f4
0x5a36b1 raw=0x1a2ab1  899e80000000                   mov    DWORD PTR [esi+0x80],ebx
0x5a36b7 raw=0x1a2ab7  899e84000000                   mov    DWORD PTR [esi+0x84],ebx
0x5a36bd raw=0x1a2abd  899e88000000                   mov    DWORD PTR [esi+0x88],ebx
0x5a36c3 raw=0x1a2ac3  eb02                           jmp    0x5a36c7
0x5a36c5 raw=0x1a2ac5  33f6                           xor    esi,esi
0x5a36c7 raw=0x1a2ac7  89770c                         mov    DWORD PTR [edi+0xc],esi
0x5a36ca raw=0x1a2aca  c747041c010000                 mov    DWORD PTR [edi+0x4],0x11c
0x5a36d1 raw=0x1a2ad1  8bc7                           mov    eax,edi
0x5a36d3 raw=0x1a2ad3  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x5a36d6 raw=0x1a2ad6  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x5a36dd raw=0x1a2add  59                             pop    ecx
0x5a36de raw=0x1a2ade  5f                             pop    edi
0x5a36df raw=0x1a2adf  5e                             pop    esi
0x5a36e0 raw=0x1a2ae0  5b                             pop    ebx
0x5a36e1 raw=0x1a2ae1  8be5                           mov    esp,ebp
0x5a36e3 raw=0x1a2ae3  5d                             pop    ebp
0x5a36e4 raw=0x1a2ae4  c20400                         ret    0x4

; prolog_panel_close_gate | panel+28 bit8 gate then tailcall close handler
; VA 0x6c0cb0..0x6c0cc5 RAW 0x2c00b0 len 21 SHA256 df7bfd178573924a810eea1199fd5fd9603fed94b0dad95115374055903f5b55
0x6c0cb0 raw=0x2c00b0  8b4128                         mov    eax,DWORD PTR [ecx+0x28]
0x6c0cb3 raw=0x2c00b3  c1e808                         shr    eax,0x8
0x6c0cb6 raw=0x2c00b6  a801                           test   al,0x1
0x6c0cb8 raw=0x2c00b8  740a                           je     0x6c0cc4
0x6c0cba raw=0x2c00ba  e8a12cd5ff                     call   0x413960
0x6c0cbf raw=0x2c00bf  e99c010000                     jmp    0x6c0e60
0x6c0cc4 raw=0x2c00c4  c3                             ret

; prolog_panel_event | event+10=0x68 advances prolog; 0x387 posts F4350
; VA 0x6c0cd0..0x6c0d97 RAW 0x2c00d0 len 199 SHA256 2d28019503f15861a08ca8e895ba9942c4c8d4b3c40ae99ab1dc4deb0cc812a9
0x6c0cd0 raw=0x2c00d0  55                             push   ebp
0x6c0cd1 raw=0x2c00d1  8bec                           mov    ebp,esp
0x6c0cd3 raw=0x2c00d3  6aff                           push   0xffffffff
0x6c0cd5 raw=0x2c00d5  680eaa9300                     push   0x93aa0e
0x6c0cda raw=0x2c00da  64a100000000                   mov    eax,fs:0x0
0x6c0ce0 raw=0x2c00e0  50                             push   eax
0x6c0ce1 raw=0x2c00e1  56                             push   esi
0x6c0ce2 raw=0x2c00e2  a1201fd600                     mov    eax,ds:0xd61f20
0x6c0ce7 raw=0x2c00e7  33c5                           xor    eax,ebp
0x6c0ce9 raw=0x2c00e9  50                             push   eax
0x6c0cea raw=0x2c00ea  8d45f4                         lea    eax,[ebp-0xc]
0x6c0ced raw=0x2c00ed  64a300000000                   mov    fs:0x0,eax
0x6c0cf3 raw=0x2c00f3  8bf1                           mov    esi,ecx
0x6c0cf5 raw=0x2c00f5  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x6c0cf8 raw=0x2c00f8  81781087030000                 cmp    DWORD PTR [eax+0x10],0x387
0x6c0cff raw=0x2c00ff  753e                           jne    0x6c0d3f
0x6c0d01 raw=0x2c0101  6a18                           push   0x18
0x6c0d03 raw=0x2c0103  e860051d00                     call   0x891268
0x6c0d08 raw=0x2c0108  83c404                         add    esp,0x4
0x6c0d0b raw=0x2c010b  85c0                           test   eax,eax
0x6c0d0d raw=0x2c010d  7427                           je     0x6c0d36
0x6c0d0f raw=0x2c010f  c74004ffffffff                 mov    DWORD PTR [eax+0x4],0xffffffff
0x6c0d16 raw=0x2c0116  c74008ffffffff                 mov    DWORD PTR [eax+0x8],0xffffffff
0x6c0d1d raw=0x2c011d  c7400c00000000                 mov    DWORD PTR [eax+0xc],0x0
0x6c0d24 raw=0x2c0124  c7401050430f00                 mov    DWORD PTR [eax+0x10],0xf4350
0x6c0d2b raw=0x2c012b  c700247bc400                   mov    DWORD PTR [eax],0xc47b24
0x6c0d31 raw=0x2c0131  897014                         mov    DWORD PTR [eax+0x14],esi
0x6c0d34 raw=0x2c0134  eb02                           jmp    0x6c0d38
0x6c0d36 raw=0x2c0136  33c0                           xor    eax,eax
0x6c0d38 raw=0x2c0138  8bf0                           mov    esi,eax
0x6c0d3a raw=0x2c013a  e86165d4ff                     call   0x4072a0
0x6c0d3f raw=0x2c013f  8b4d08                         mov    ecx,DWORD PTR [ebp+0x8]
0x6c0d42 raw=0x2c0142  83791068                       cmp    DWORD PTR [ecx+0x10],0x68
0x6c0d46 raw=0x2c0146  753d                           jne    0x6c0d85
0x6c0d48 raw=0x2c0148  b801000000                     mov    eax,0x1
0x6c0d4d raw=0x2c014d  8405141bfc00                   test   BYTE PTR ds:0xfc1b14,al
0x6c0d53 raw=0x2c0153  7526                           jne    0x6c0d7b
0x6c0d55 raw=0x2c0155  0905141bfc00                   or     DWORD PTR ds:0xfc1b14,eax
0x6c0d5b raw=0x2c015b  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
0x6c0d62 raw=0x2c0162  e829e1e9ff                     call   0x55ee90
0x6c0d67 raw=0x2c0167  6890dfbc00                     push   0xbcdf90
0x6c0d6c raw=0x2c016c  e8a9151d00                     call   0x89231a
0x6c0d71 raw=0x2c0171  83c404                         add    esp,0x4
0x6c0d74 raw=0x2c0174  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
0x6c0d7b raw=0x2c017b  b8181bfc00                     mov    eax,0xfc1b18
0x6c0d80 raw=0x2c0180  e8dbebe9ff                     call   0x55f960
0x6c0d85 raw=0x2c0185  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x6c0d88 raw=0x2c0188  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x6c0d8f raw=0x2c018f  59                             pop    ecx
0x6c0d90 raw=0x2c0190  5e                             pop    esi
0x6c0d91 raw=0x2c0191  8be5                           mov    esp,ebp
0x6c0d93 raw=0x2c0193  5d                             pop    ebp
0x6c0d94 raw=0x2c0194  c20400                         ret    0x4

; prolog_panel_key | key0xD advances prolog using exact singleton
; VA 0x6c0da0..0x6c0e28 RAW 0x2c01a0 len 136 SHA256 b005b5e8887cfee0110c9984b4d4faf216a9d4e20b9e66556e98deb65c717eeb
0x6c0da0 raw=0x2c01a0  55                             push   ebp
0x6c0da1 raw=0x2c01a1  8bec                           mov    ebp,esp
0x6c0da3 raw=0x2c01a3  6aff                           push   0xffffffff
0x6c0da5 raw=0x2c01a5  68aea99300                     push   0x93a9ae
0x6c0daa raw=0x2c01aa  64a100000000                   mov    eax,fs:0x0
0x6c0db0 raw=0x2c01b0  50                             push   eax
0x6c0db1 raw=0x2c01b1  a1201fd600                     mov    eax,ds:0xd61f20
0x6c0db6 raw=0x2c01b6  33c5                           xor    eax,ebp
0x6c0db8 raw=0x2c01b8  50                             push   eax
0x6c0db9 raw=0x2c01b9  8d45f4                         lea    eax,[ebp-0xc]
0x6c0dbc raw=0x2c01bc  64a300000000                   mov    fs:0x0,eax
0x6c0dc2 raw=0x2c01c2  837d080d                       cmp    DWORD PTR [ebp+0x8],0xd
0x6c0dc6 raw=0x2c01c6  754d                           jne    0x6c0e15
0x6c0dc8 raw=0x2c01c8  f605141bfc0001                 test   BYTE PTR ds:0xfc1b14,0x1
0x6c0dcf raw=0x2c01cf  7527                           jne    0x6c0df8
0x6c0dd1 raw=0x2c01d1  830d141bfc0001                 or     DWORD PTR ds:0xfc1b14,0x1
0x6c0dd8 raw=0x2c01d8  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
0x6c0ddf raw=0x2c01df  e8ace0e9ff                     call   0x55ee90
0x6c0de4 raw=0x2c01e4  6890dfbc00                     push   0xbcdf90
0x6c0de9 raw=0x2c01e9  e82c151d00                     call   0x89231a
0x6c0dee raw=0x2c01ee  83c404                         add    esp,0x4
0x6c0df1 raw=0x2c01f1  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
0x6c0df8 raw=0x2c01f8  b8181bfc00                     mov    eax,0xfc1b18
0x6c0dfd raw=0x2c01fd  e85eebe9ff                     call   0x55f960
0x6c0e02 raw=0x2c0202  b001                           mov    al,0x1
0x6c0e04 raw=0x2c0204  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x6c0e07 raw=0x2c0207  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x6c0e0e raw=0x2c020e  59                             pop    ecx
0x6c0e0f raw=0x2c020f  8be5                           mov    esp,ebp
0x6c0e11 raw=0x2c0211  5d                             pop    ebp
0x6c0e12 raw=0x2c0212  c20400                         ret    0x4
0x6c0e15 raw=0x2c0215  32c0                           xor    al,al
0x6c0e17 raw=0x2c0217  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x6c0e1a raw=0x2c021a  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x6c0e21 raw=0x2c0221  59                             pop    ecx
0x6c0e22 raw=0x2c0222  8be5                           mov    esp,ebp
0x6c0e24 raw=0x2c0224  5d                             pop    ebp
0x6c0e25 raw=0x2c0225  c20400                         ret    0x4

; prolog_panel_event_close | event0x578 with UI target match calls panel v+D4
; VA 0x6c0e30..0x6c0e5b RAW 0x2c0230 len 43 SHA256 e47fd8b7b627d69fe0c242e9cb731d627d0bcf8faffd7d7f82ea52e72cf24c92
0x6c0e30 raw=0x2c0230  55                             push   ebp
0x6c0e31 raw=0x2c0231  8bec                           mov    ebp,esp
0x6c0e33 raw=0x2c0233  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x6c0e36 raw=0x2c0236  81781078050000                 cmp    DWORD PTR [eax+0x10],0x578
0x6c0e3d raw=0x2c023d  7518                           jne    0x6c0e57
0x6c0e3f raw=0x2c023f  8b9184000000                   mov    edx,DWORD PTR [ecx+0x84]
0x6c0e45 raw=0x2c0245  8b4008                         mov    eax,DWORD PTR [eax+0x8]
0x6c0e48 raw=0x2c0248  3b4220                         cmp    eax,DWORD PTR [edx+0x20]
0x6c0e4b raw=0x2c024b  750a                           jne    0x6c0e57
0x6c0e4d raw=0x2c024d  8b11                           mov    edx,DWORD PTR [ecx]
0x6c0e4f raw=0x2c024f  8b82d4000000                   mov    eax,DWORD PTR [edx+0xd4]
0x6c0e55 raw=0x2c0255  ffd0                           call   eax
0x6c0e57 raw=0x2c0257  5d                             pop    ebp
0x6c0e58 raw=0x2c0258  c20400                         ret    0x4

; prolog_panel_close | native close uses FC1B18 active gate then55F8A0
; VA 0x6c0e60..0x6c0ed9 RAW 0x2c0260 len 121 SHA256 512d6727a7e826b5259b26e937669f02a0e9938ebdd36b14e26be974c18b9e97
0x6c0e60 raw=0x2c0260  55                             push   ebp
0x6c0e61 raw=0x2c0261  8bec                           mov    ebp,esp
0x6c0e63 raw=0x2c0263  6aff                           push   0xffffffff
0x6c0e65 raw=0x2c0265  680eaa9300                     push   0x93aa0e
0x6c0e6a raw=0x2c026a  64a100000000                   mov    eax,fs:0x0
0x6c0e70 raw=0x2c0270  50                             push   eax
0x6c0e71 raw=0x2c0271  56                             push   esi
0x6c0e72 raw=0x2c0272  a1201fd600                     mov    eax,ds:0xd61f20
0x6c0e77 raw=0x2c0277  33c5                           xor    eax,ebp
0x6c0e79 raw=0x2c0279  50                             push   eax
0x6c0e7a raw=0x2c027a  8d45f4                         lea    eax,[ebp-0xc]
0x6c0e7d raw=0x2c027d  64a300000000                   mov    fs:0x0,eax
0x6c0e83 raw=0x2c0283  b801000000                     mov    eax,0x1
0x6c0e88 raw=0x2c0288  8405141bfc00                   test   BYTE PTR ds:0xfc1b14,al
0x6c0e8e raw=0x2c028e  7526                           jne    0x6c0eb6
0x6c0e90 raw=0x2c0290  0905141bfc00                   or     DWORD PTR ds:0xfc1b14,eax
0x6c0e96 raw=0x2c0296  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
0x6c0e9d raw=0x2c029d  e8eedfe9ff                     call   0x55ee90
0x6c0ea2 raw=0x2c02a2  6890dfbc00                     push   0xbcdf90
0x6c0ea7 raw=0x2c02a7  e86e141d00                     call   0x89231a
0x6c0eac raw=0x2c02ac  83c404                         add    esp,0x4
0x6c0eaf raw=0x2c02af  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
0x6c0eb6 raw=0x2c02b6  833d181bfc0000                 cmp    DWORD PTR ds:0xfc1b18,0x0
0x6c0ebd raw=0x2c02bd  740a                           je     0x6c0ec9
0x6c0ebf raw=0x2c02bf  be181bfc00                     mov    esi,0xfc1b18
0x6c0ec4 raw=0x2c02c4  e8d7e9e9ff                     call   0x55f8a0
0x6c0ec9 raw=0x2c02c9  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x6c0ecc raw=0x2c02cc  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x6c0ed3 raw=0x2c02d3  59                             pop    ecx
0x6c0ed4 raw=0x2c02d4  5e                             pop    esi
0x6c0ed5 raw=0x2c02d5  8be5                           mov    esp,ebp
0x6c0ed7 raw=0x2c02d7  5d                             pop    ebp
0x6c0ed8 raw=0x2c02d8  c3                             ret

; q_book_start | Q.Book initializes owner FC1BF8 and calls config/start; formal int unused
; VA 0x565140..0x5651f0 RAW 0x164540 len 176 SHA256 8a79606e0a6e691004a9fbfa0dc684855638b0344803600d40315caa2acb2b74
0x565140 raw=0x164540  55                             push   ebp
0x565141 raw=0x164541  8bec                           mov    ebp,esp
0x565143 raw=0x164543  6aff                           push   0xffffffff
0x565145 raw=0x164545  68ac8c9300                     push   0x938cac
0x56514a raw=0x16454a  64a100000000                   mov    eax,fs:0x0
0x565150 raw=0x164550  50                             push   eax
0x565151 raw=0x164551  51                             push   ecx
0x565152 raw=0x164552  53                             push   ebx
0x565153 raw=0x164553  57                             push   edi
0x565154 raw=0x164554  a1201fd600                     mov    eax,ds:0xd61f20
0x565159 raw=0x164559  33c5                           xor    eax,ebp
0x56515b raw=0x16455b  50                             push   eax
0x56515c raw=0x16455c  8d45f4                         lea    eax,[ebp-0xc]
0x56515f raw=0x16455f  64a300000000                   mov    fs:0x0,eax
0x565165 raw=0x164565  bb01000000                     mov    ebx,0x1
0x56516a raw=0x16456a  841dd4adfa00                   test   BYTE PTR ds:0xfaadd4,bl
0x565170 raw=0x164570  7526                           jne    0x565198
0x565172 raw=0x164572  091dd4adfa00                   or     DWORD PTR ds:0xfaadd4,ebx
0x565178 raw=0x164578  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
0x56517f raw=0x16457f  e8fc220200                     call   0x587480
0x565184 raw=0x164584  68c0ccbc00                     push   0xbcccc0
0x565189 raw=0x164589  e88cd13200                     call   0x89231a
0x56518e raw=0x16458e  83c404                         add    esp,0x4
0x565191 raw=0x164591  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
0x565198 raw=0x164598  d9e8                           fld1
0x56519a raw=0x16459a  83ec08                         sub    esp,0x8
0x56519d raw=0x16459d  d9542404                       fst    DWORD PTR [esp+0x4]
0x5651a1 raw=0x1645a1  d91c24                         fstp   DWORD PTR [esp]
0x5651a4 raw=0x1645a4  e877480200                     call   0x589a20
0x5651a9 raw=0x1645a9  841df41bfc00                   test   BYTE PTR ds:0xfc1bf4,bl
0x5651af raw=0x1645af  7522                           jne    0x5651d3
0x5651b1 raw=0x1645b1  091df41bfc00                   or     DWORD PTR ds:0xfc1bf4,ebx
0x5651b7 raw=0x1645b7  895dfc                         mov    DWORD PTR [ebp-0x4],ebx
0x5651ba raw=0x1645ba  e8d19d0100                     call   0x57ef90
0x5651bf raw=0x1645bf  68b0dfbc00                     push   0xbcdfb0
0x5651c4 raw=0x1645c4  e851d13200                     call   0x89231a
0x5651c9 raw=0x1645c9  83c404                         add    esp,0x4
0x5651cc raw=0x1645cc  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
0x5651d3 raw=0x1645d3  bff81bfc00                     mov    edi,0xfc1bf8
0x5651d8 raw=0x1645d8  e8c3d40100                     call   0x5826a0
0x5651dd raw=0x1645dd  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x5651e0 raw=0x1645e0  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x5651e7 raw=0x1645e7  59                             pop    ecx
0x5651e8 raw=0x1645e8  5f                             pop    edi
0x5651e9 raw=0x1645e9  5b                             pop    ebx
0x5651ea raw=0x1645ea  8be5                           mov    esp,ebp
0x5651ec raw=0x1645ec  5d                             pop    ebp
0x5651ed raw=0x1645ed  c20400                         ret    0x4

; q_book_read | Q.IsBookFlying returns FC1C6C=owner+74
; VA 0x565270..0x5652d2 RAW 0x164670 len 98 SHA256 7ca520717d6d56734ac9ec8dc892349b70f8264b8e8d30df87d1ff8c8e9c9103
0x565270 raw=0x164670  55                             push   ebp
0x565271 raw=0x164671  8bec                           mov    ebp,esp
0x565273 raw=0x164673  6aff                           push   0xffffffff
0x565275 raw=0x164675  68ee2e9200                     push   0x922eee
0x56527a raw=0x16467a  64a100000000                   mov    eax,fs:0x0
0x565280 raw=0x164680  50                             push   eax
0x565281 raw=0x164681  a1201fd600                     mov    eax,ds:0xd61f20
0x565286 raw=0x164686  33c5                           xor    eax,ebp
0x565288 raw=0x164688  50                             push   eax
0x565289 raw=0x164689  8d45f4                         lea    eax,[ebp-0xc]
0x56528c raw=0x16468c  64a300000000                   mov    fs:0x0,eax
0x565292 raw=0x164692  b801000000                     mov    eax,0x1
0x565297 raw=0x164697  8405f41bfc00                   test   BYTE PTR ds:0xfc1bf4,al
0x56529d raw=0x16469d  751f                           jne    0x5652be
0x56529f raw=0x16469f  0905f41bfc00                   or     DWORD PTR ds:0xfc1bf4,eax
0x5652a5 raw=0x1646a5  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
0x5652ac raw=0x1646ac  e8df9c0100                     call   0x57ef90
0x5652b1 raw=0x1646b1  68b0dfbc00                     push   0xbcdfb0
0x5652b6 raw=0x1646b6  e85fd03200                     call   0x89231a
0x5652bb raw=0x1646bb  83c404                         add    esp,0x4
0x5652be raw=0x1646be  a16c1cfc00                     mov    eax,ds:0xfc1c6c
0x5652c3 raw=0x1646c3  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x5652c6 raw=0x1646c6  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x5652cd raw=0x1646cd  59                             pop    ecx
0x5652ce raw=0x1646ce  8be5                           mov    esp,ebp
0x5652d0 raw=0x1646d0  5d                             pop    ebp
0x5652d1 raw=0x1646d1  c3                             ret

; book_config_start | read Table/Book.txt config then57F950
; VA 0x5826a0..0x582870 RAW 0x181aa0 len 464 SHA256 031804ed64a9c7a461143e2fb7ec142c21f31d8cb4e8ba102a41eed435f5ed1d
0x5826a0 raw=0x181aa0  55                             push   ebp
0x5826a1 raw=0x181aa1  8bec                           mov    ebp,esp
0x5826a3 raw=0x181aa3  6aff                           push   0xffffffff
0x5826a5 raw=0x181aa5  685e8c9300                     push   0x938c5e
0x5826aa raw=0x181aaa  64a100000000                   mov    eax,fs:0x0
0x5826b0 raw=0x181ab0  50                             push   eax
0x5826b1 raw=0x181ab1  81ec1c010000                   sub    esp,0x11c
0x5826b7 raw=0x181ab7  a1201fd600                     mov    eax,ds:0xd61f20
0x5826bc raw=0x181abc  33c5                           xor    eax,ebp
0x5826be raw=0x181abe  8945f0                         mov    DWORD PTR [ebp-0x10],eax
0x5826c1 raw=0x181ac1  56                             push   esi
0x5826c2 raw=0x181ac2  50                             push   eax
0x5826c3 raw=0x181ac3  8d45f4                         lea    eax,[ebp-0xc]
0x5826c6 raw=0x181ac6  64a300000000                   mov    fs:0x0,eax
0x5826cc raw=0x181acc  b801000000                     mov    eax,0x1
0x5826d1 raw=0x181ad1  8405e879fb00                   test   BYTE PTR ds:0xfb79e8,al
0x5826d7 raw=0x181ad7  7526                           jne    0x5826ff
0x5826d9 raw=0x181ad9  0905e879fb00                   or     DWORD PTR ds:0xfb79e8,eax
0x5826df raw=0x181adf  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
0x5826e6 raw=0x181ae6  e8f5662100                     call   0x798de0
0x5826eb raw=0x181aeb  68e0d2bc00                     push   0xbcd2e0
0x5826f0 raw=0x181af0  e825fc3000                     call   0x89231a
0x5826f5 raw=0x181af5  83c404                         add    esp,0x4
0x5826f8 raw=0x181af8  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
0x5826ff raw=0x181aff  6890cdc000                     push   0xc0cd90
0x582704 raw=0x181b04  682c13c100                     push   0xc1132c
0x582709 raw=0x181b09  e862201900                     call   0x714770
0x58270e raw=0x181b0e  8bf0                           mov    esi,eax
0x582710 raw=0x181b10  83c408                         add    esp,0x8
0x582713 raw=0x181b13  85f6                           test   esi,esi
0x582715 raw=0x181b15  0f84fe000000                   je     0x582819
0x58271b raw=0x181b1b  68ff000000                     push   0xff
0x582720 raw=0x181b20  8d85f1feffff                   lea    eax,[ebp-0x10f]
0x582726 raw=0x181b26  6a00                           push   0x0
0x582728 raw=0x181b28  50                             push   eax
0x582729 raw=0x181b29  c685f0feffff00                 mov    BYTE PTR [ebp-0x110],0x0
0x582730 raw=0x181b30  e82bc13100                     call   0x89e860
0x582735 raw=0x181b35  8b16                           mov    edx,DWORD PTR [esi]
0x582737 raw=0x181b37  8b5208                         mov    edx,DWORD PTR [edx+0x8]
0x58273a raw=0x181b3a  83c40c                         add    esp,0xc
0x58273d raw=0x181b3d  68ff000000                     push   0xff
0x582742 raw=0x181b42  8d85f0feffff                   lea    eax,[ebp-0x110]
0x582748 raw=0x181b48  50                             push   eax
0x582749 raw=0x181b49  8bce                           mov    ecx,esi
0x58274b raw=0x181b4b  ffd2                           call   edx
0x58274d raw=0x181b4d  8d85e0feffff                   lea    eax,[ebp-0x120]
0x582753 raw=0x181b53  50                             push   eax
0x582754 raw=0x181b54  8d8ddcfeffff                   lea    ecx,[ebp-0x124]
0x58275a raw=0x181b5a  51                             push   ecx
0x58275b raw=0x181b5b  8d95d8feffff                   lea    edx,[ebp-0x128]
0x582761 raw=0x181b61  52                             push   edx
0x582762 raw=0x181b62  8d85f0feffff                   lea    eax,[ebp-0x110]
0x582768 raw=0x181b68  683c13c100                     push   0xc1133c
0x58276d raw=0x181b6d  50                             push   eax
0x58276e raw=0x181b6e  e819383100                     call   0x895f8c
0x582773 raw=0x181b73  83c414                         add    esp,0x14
0x582776 raw=0x181b76  6800010000                     push   0x100
0x58277b raw=0x181b7b  8d8df0feffff                   lea    ecx,[ebp-0x110]
0x582781 raw=0x181b81  6a00                           push   0x0
0x582783 raw=0x181b83  51                             push   ecx
0x582784 raw=0x181b84  e8d7c03100                     call   0x89e860
0x582789 raw=0x181b89  8b16                           mov    edx,DWORD PTR [esi]
0x58278b raw=0x181b8b  8b5208                         mov    edx,DWORD PTR [edx+0x8]
0x58278e raw=0x181b8e  83c40c                         add    esp,0xc
0x582791 raw=0x181b91  68ff000000                     push   0xff
0x582796 raw=0x181b96  8d85f0feffff                   lea    eax,[ebp-0x110]
0x58279c raw=0x181b9c  50                             push   eax
0x58279d raw=0x181b9d  8bce                           mov    ecx,esi
0x58279f raw=0x181b9f  ffd2                           call   edx
0x5827a1 raw=0x181ba1  8d85ecfeffff                   lea    eax,[ebp-0x114]
0x5827a7 raw=0x181ba7  50                             push   eax
0x5827a8 raw=0x181ba8  8d8de8feffff                   lea    ecx,[ebp-0x118]
0x5827ae raw=0x181bae  51                             push   ecx
0x5827af raw=0x181baf  8d95e4feffff                   lea    edx,[ebp-0x11c]
0x5827b5 raw=0x181bb5  52                             push   edx
0x5827b6 raw=0x181bb6  8d85f0feffff                   lea    eax,[ebp-0x110]
0x5827bc raw=0x181bbc  683c13c100                     push   0xc1133c
0x5827c1 raw=0x181bc1  50                             push   eax
0x5827c2 raw=0x181bc2  e8c5373100                     call   0x895f8c
0x5827c7 raw=0x181bc7  83c414                         add    esp,0x14
0x5827ca raw=0x181bca  6800010000                     push   0x100
0x5827cf raw=0x181bcf  8d8df0feffff                   lea    ecx,[ebp-0x110]
0x5827d5 raw=0x181bd5  6a00                           push   0x0
0x5827d7 raw=0x181bd7  51                             push   ecx
0x5827d8 raw=0x181bd8  e883c03100                     call   0x89e860
0x5827dd raw=0x181bdd  d985e4feffff                   fld    DWORD PTR [ebp-0x11c]
0x5827e3 raw=0x181be3  dd05605dc500                   fld    QWORD PTR ds:0xc55d60
0x5827e9 raw=0x181be9  83c40c                         add    esp,0xc
0x5827ec raw=0x181bec  dcc9                           fmul   st(1),st
0x5827ee raw=0x181bee  8bce                           mov    ecx,esi
0x5827f0 raw=0x181bf0  d9c9                           fxch   st(1)
0x5827f2 raw=0x181bf2  d99de4feffff                   fstp   DWORD PTR [ebp-0x11c]
0x5827f8 raw=0x181bf8  d985e8feffff                   fld    DWORD PTR [ebp-0x118]
0x5827fe raw=0x181bfe  d8c9                           fmul   st,st(1)
0x582800 raw=0x181c00  d99de8feffff                   fstp   DWORD PTR [ebp-0x118]
0x582806 raw=0x181c06  d88decfeffff                   fmul   DWORD PTR [ebp-0x114]
0x58280c raw=0x181c0c  d99decfeffff                   fstp   DWORD PTR [ebp-0x114]
0x582812 raw=0x181c12  8b16                           mov    edx,DWORD PTR [esi]
0x582814 raw=0x181c14  8b4204                         mov    eax,DWORD PTR [edx+0x4]
0x582817 raw=0x181c17  ffd0                           call   eax
0x582819 raw=0x181c19  8b8dd8feffff                   mov    ecx,DWORD PTR [ebp-0x128]
0x58281f raw=0x181c1f  8b95dcfeffff                   mov    edx,DWORD PTR [ebp-0x124]
0x582825 raw=0x181c25  8b85e0feffff                   mov    eax,DWORD PTR [ebp-0x120]
0x58282b raw=0x181c2b  894f1c                         mov    DWORD PTR [edi+0x1c],ecx
0x58282e raw=0x181c2e  8b8de4feffff                   mov    ecx,DWORD PTR [ebp-0x11c]
0x582834 raw=0x181c34  895720                         mov    DWORD PTR [edi+0x20],edx
0x582837 raw=0x181c37  8b95e8feffff                   mov    edx,DWORD PTR [ebp-0x118]
0x58283d raw=0x181c3d  894f28                         mov    DWORD PTR [edi+0x28],ecx
0x582840 raw=0x181c40  894724                         mov    DWORD PTR [edi+0x24],eax
0x582843 raw=0x181c43  8b85ecfeffff                   mov    eax,DWORD PTR [ebp-0x114]
0x582849 raw=0x181c49  89572c                         mov    DWORD PTR [edi+0x2c],edx
0x58284c raw=0x181c4c  8bcf                           mov    ecx,edi
0x58284e raw=0x181c4e  894730                         mov    DWORD PTR [edi+0x30],eax
0x582851 raw=0x181c51  e8fad0ffff                     call   0x57f950
0x582856 raw=0x181c56  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x582859 raw=0x181c59  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x582860 raw=0x181c60  59                             pop    ecx
0x582861 raw=0x181c61  5e                             pop    esi
0x582862 raw=0x181c62  8b4df0                         mov    ecx,DWORD PTR [ebp-0x10]
0x582865 raw=0x181c65  33cd                           xor    ecx,ebp
0x582867 raw=0x181c67  e895e73000                     call   0x891001
0x58286c raw=0x181c6c  8be5                           mov    esp,ebp
0x58286e raw=0x181c6e  5d                             pop    ebp
0x58286f raw=0x181c6f  c3                             ret

; book_constructor | four typed book states and owner+74=0
; VA 0x57ef90..0x57f26a RAW 0x17e390 len 730 SHA256 fc3a14a28c1cb0358607ee87e0c805867af703ee9b3ecad4e06d59f1ca8693eb
0x57ef90 raw=0x17e390  55                             push   ebp
0x57ef91 raw=0x17e391  8bec                           mov    ebp,esp
0x57ef93 raw=0x17e393  6aff                           push   0xffffffff
0x57ef95 raw=0x17e395  6832119200                     push   0x921132
0x57ef9a raw=0x17e39a  64a100000000                   mov    eax,fs:0x0
0x57efa0 raw=0x17e3a0  50                             push   eax
0x57efa1 raw=0x17e3a1  83ec0c                         sub    esp,0xc
0x57efa4 raw=0x17e3a4  53                             push   ebx
0x57efa5 raw=0x17e3a5  56                             push   esi
0x57efa6 raw=0x17e3a6  57                             push   edi
0x57efa7 raw=0x17e3a7  a1201fd600                     mov    eax,ds:0xd61f20
0x57efac raw=0x17e3ac  33c5                           xor    eax,ebp
0x57efae raw=0x17e3ae  50                             push   eax
0x57efaf raw=0x17e3af  8d45f4                         lea    eax,[ebp-0xc]
0x57efb2 raw=0x17e3b2  64a300000000                   mov    fs:0x0,eax
0x57efb8 raw=0x17e3b8  33f6                           xor    esi,esi
0x57efba raw=0x17e3ba  c745ecf81bfc00                 mov    DWORD PTR [ebp-0x14],0xfc1bf8
0x57efc1 raw=0x17e3c1  c705101cfc00ffffffff           mov    DWORD PTR ds:0xfc1c10,0xffffffff
0x57efcb raw=0x17e3cb  89352c1cfc00                   mov    DWORD PTR ds:0xfc1c2c,esi
0x57efd1 raw=0x17e3d1  8935301cfc00                   mov    DWORD PTR ds:0xfc1c30,esi
0x57efd7 raw=0x17e3d7  8935341cfc00                   mov    DWORD PTR ds:0xfc1c34,esi
0x57efdd raw=0x17e3dd  8975fc                         mov    DWORD PTR [ebp-0x4],esi
0x57efe0 raw=0x17e3e0  8935501cfc00                   mov    DWORD PTR ds:0xfc1c50,esi
0x57efe6 raw=0x17e3e6  8935541cfc00                   mov    DWORD PTR ds:0xfc1c54,esi
0x57efec raw=0x17e3ec  8935581cfc00                   mov    DWORD PTR ds:0xfc1c58,esi
0x57eff2 raw=0x17e3f2  bb01000000                     mov    ebx,0x1
0x57eff7 raw=0x17e3f7  885dfc                         mov    BYTE PTR [ebp-0x4],bl
0x57effa raw=0x17e3fa  6a38                           push   0x38
0x57effc raw=0x17e3fc  8935001cfc00                   mov    DWORD PTR ds:0xfc1c00,esi
0x57f002 raw=0x17e402  8935041cfc00                   mov    DWORD PTR ds:0xfc1c04,esi
0x57f008 raw=0x17e408  8935081cfc00                   mov    DWORD PTR ds:0xfc1c08,esi
0x57f00e raw=0x17e40e  89350c1cfc00                   mov    DWORD PTR ds:0xfc1c0c,esi
0x57f014 raw=0x17e414  8935f81bfc00                   mov    DWORD PTR ds:0xfc1bf8,esi
0x57f01a raw=0x17e41a  8935fc1bfc00                   mov    DWORD PTR ds:0xfc1bfc,esi
0x57f020 raw=0x17e420  89354c1cfc00                   mov    DWORD PTR ds:0xfc1c4c,esi
0x57f026 raw=0x17e426  8935601cfc00                   mov    DWORD PTR ds:0xfc1c60,esi
0x57f02c raw=0x17e42c  8935701cfc00                   mov    DWORD PTR ds:0xfc1c70,esi
0x57f032 raw=0x17e432  8935741cfc00                   mov    DWORD PTR ds:0xfc1c74,esi
0x57f038 raw=0x17e438  e82b223100                     call   0x891268
0x57f03d raw=0x17e43d  83c404                         add    esp,0x4
0x57f040 raw=0x17e440  8945f0                         mov    DWORD PTR [ebp-0x10],eax
0x57f043 raw=0x17e443  c645fc02                       mov    BYTE PTR [ebp-0x4],0x2
0x57f047 raw=0x17e447  3bc6                           cmp    eax,esi
0x57f049 raw=0x17e449  740d                           je     0x57f058
0x57f04b raw=0x17e44b  689810c100                     push   0xc11098
0x57f050 raw=0x17e450  50                             push   eax
0x57f051 raw=0x17e451  e89a0b0000                     call   0x57fbf0
0x57f056 raw=0x17e456  eb02                           jmp    0x57f05a
0x57f058 raw=0x17e458  33c0                           xor    eax,eax
0x57f05a raw=0x17e45a  885dfc                         mov    BYTE PTR [ebp-0x4],bl
0x57f05d raw=0x17e45d  8945f0                         mov    DWORD PTR [ebp-0x10],eax
0x57f060 raw=0x17e460  8d45f0                         lea    eax,[ebp-0x10]
0x57f063 raw=0x17e463  bf2c1cfc00                     mov    edi,0xfc1c2c
0x57f068 raw=0x17e468  e8a34cecff                     call   0x443d10
0x57f06d raw=0x17e46d  6a38                           push   0x38
0x57f06f raw=0x17e46f  e8f4213100                     call   0x891268
0x57f074 raw=0x17e474  83c404                         add    esp,0x4
0x57f077 raw=0x17e477  8945f0                         mov    DWORD PTR [ebp-0x10],eax
0x57f07a raw=0x17e47a  c645fc03                       mov    BYTE PTR [ebp-0x4],0x3
0x57f07e raw=0x17e47e  3bc6                           cmp    eax,esi
0x57f080 raw=0x17e480  740d                           je     0x57f08f
0x57f082 raw=0x17e482  68ac10c100                     push   0xc110ac
0x57f087 raw=0x17e487  50                             push   eax
0x57f088 raw=0x17e488  e8630b0000                     call   0x57fbf0
0x57f08d raw=0x17e48d  eb02                           jmp    0x57f091
0x57f08f raw=0x17e48f  33c0                           xor    eax,eax
0x57f091 raw=0x17e491  885dfc                         mov    BYTE PTR [ebp-0x4],bl
0x57f094 raw=0x17e494  8945f0                         mov    DWORD PTR [ebp-0x10],eax
0x57f097 raw=0x17e497  8d45f0                         lea    eax,[ebp-0x10]
0x57f09a raw=0x17e49a  bf2c1cfc00                     mov    edi,0xfc1c2c
0x57f09f raw=0x17e49f  e86c4cecff                     call   0x443d10
0x57f0a4 raw=0x17e4a4  6a38                           push   0x38
0x57f0a6 raw=0x17e4a6  e8bd213100                     call   0x891268
0x57f0ab raw=0x17e4ab  83c404                         add    esp,0x4
0x57f0ae raw=0x17e4ae  8945f0                         mov    DWORD PTR [ebp-0x10],eax
0x57f0b1 raw=0x17e4b1  c645fc04                       mov    BYTE PTR [ebp-0x4],0x4
0x57f0b5 raw=0x17e4b5  3bc6                           cmp    eax,esi
0x57f0b7 raw=0x17e4b7  740d                           je     0x57f0c6
0x57f0b9 raw=0x17e4b9  68c010c100                     push   0xc110c0
0x57f0be raw=0x17e4be  50                             push   eax
0x57f0bf raw=0x17e4bf  e82c0b0000                     call   0x57fbf0
0x57f0c4 raw=0x17e4c4  eb02                           jmp    0x57f0c8
0x57f0c6 raw=0x17e4c6  33c0                           xor    eax,eax
0x57f0c8 raw=0x17e4c8  885dfc                         mov    BYTE PTR [ebp-0x4],bl
0x57f0cb raw=0x17e4cb  8945f0                         mov    DWORD PTR [ebp-0x10],eax
0x57f0ce raw=0x17e4ce  8d45f0                         lea    eax,[ebp-0x10]
0x57f0d1 raw=0x17e4d1  bf2c1cfc00                     mov    edi,0xfc1c2c
0x57f0d6 raw=0x17e4d6  e8354cecff                     call   0x443d10
0x57f0db raw=0x17e4db  6a38                           push   0x38
0x57f0dd raw=0x17e4dd  e886213100                     call   0x891268
0x57f0e2 raw=0x17e4e2  83c404                         add    esp,0x4
0x57f0e5 raw=0x17e4e5  8945f0                         mov    DWORD PTR [ebp-0x10],eax
0x57f0e8 raw=0x17e4e8  c645fc05                       mov    BYTE PTR [ebp-0x4],0x5
0x57f0ec raw=0x17e4ec  3bc6                           cmp    eax,esi
0x57f0ee raw=0x17e4ee  740d                           je     0x57f0fd
0x57f0f0 raw=0x17e4f0  68d410c100                     push   0xc110d4
0x57f0f5 raw=0x17e4f5  50                             push   eax
0x57f0f6 raw=0x17e4f6  e8f50a0000                     call   0x57fbf0
0x57f0fb raw=0x17e4fb  eb02                           jmp    0x57f0ff
0x57f0fd raw=0x17e4fd  33c0                           xor    eax,eax
0x57f0ff raw=0x17e4ff  885dfc                         mov    BYTE PTR [ebp-0x4],bl
0x57f102 raw=0x17e502  8945f0                         mov    DWORD PTR [ebp-0x10],eax
0x57f105 raw=0x17e505  8d45f0                         lea    eax,[ebp-0x10]
0x57f108 raw=0x17e508  bf2c1cfc00                     mov    edi,0xfc1c2c
0x57f10d raw=0x17e50d  e8fe4becff                     call   0x443d10
0x57f112 raw=0x17e512  6a10                           push   0x10
0x57f114 raw=0x17e514  e84f213100                     call   0x891268
0x57f119 raw=0x17e519  83c404                         add    esp,0x4
0x57f11c raw=0x17e51c  bff81bfc00                     mov    edi,0xfc1bf8
0x57f121 raw=0x17e521  3bc6                           cmp    eax,esi
0x57f123 raw=0x17e523  740e                           je     0x57f133
0x57f125 raw=0x17e525  897804                         mov    DWORD PTR [eax+0x4],edi
0x57f128 raw=0x17e528  89700c                         mov    DWORD PTR [eax+0xc],esi
0x57f12b raw=0x17e52b  c7009412c100                   mov    DWORD PTR [eax],0xc11294
0x57f131 raw=0x17e531  eb02                           jmp    0x57f135
0x57f133 raw=0x17e533  33c0                           xor    eax,eax
0x57f135 raw=0x17e535  6a48                           push   0x48
0x57f137 raw=0x17e537  a33c1cfc00                     mov    ds:0xfc1c3c,eax
0x57f13c raw=0x17e53c  e827213100                     call   0x891268
0x57f141 raw=0x17e541  83c404                         add    esp,0x4
0x57f144 raw=0x17e544  3bc6                           cmp    eax,esi
0x57f146 raw=0x17e546  7462                           je     0x57f1aa
0x57f148 raw=0x17e548  f30f100dd058c500               movss  xmm1,DWORD PTR ds:0xc558d0
0x57f150 raw=0x17e550  0f57c0                         xorps  xmm0,xmm0
0x57f153 raw=0x17e553  897804                         mov    DWORD PTR [eax+0x4],edi
0x57f156 raw=0x17e556  89700c                         mov    DWORD PTR [eax+0xc],esi
0x57f159 raw=0x17e559  c700b412c100                   mov    DWORD PTR [eax],0xc112b4
0x57f15f raw=0x17e55f  f30f114810                     movss  DWORD PTR [eax+0x10],xmm1
0x57f164 raw=0x17e564  f30f114818                     movss  DWORD PTR [eax+0x18],xmm1
0x57f169 raw=0x17e569  f30f100dc056c400               movss  xmm1,DWORD PTR ds:0xc456c0
0x57f171 raw=0x17e571  f30f114014                     movss  DWORD PTR [eax+0x14],xmm0
0x57f176 raw=0x17e576  89701c                         mov    DWORD PTR [eax+0x1c],esi
0x57f179 raw=0x17e579  f30f114820                     movss  DWORD PTR [eax+0x20],xmm1
0x57f17e raw=0x17e57e  f30f114828                     movss  DWORD PTR [eax+0x28],xmm1
0x57f183 raw=0x17e583  f30f100dfcc7c000               movss  xmm1,DWORD PTR ds:0xc0c7fc
0x57f18b raw=0x17e58b  f30f114024                     movss  DWORD PTR [eax+0x24],xmm0
0x57f190 raw=0x17e590  89702c                         mov    DWORD PTR [eax+0x2c],esi
0x57f193 raw=0x17e593  f30f114030                     movss  DWORD PTR [eax+0x30],xmm0
0x57f198 raw=0x17e598  f30f114834                     movss  DWORD PTR [eax+0x34],xmm1
0x57f19d raw=0x17e59d  f30f114038                     movss  DWORD PTR [eax+0x38],xmm0
0x57f1a2 raw=0x17e5a2  89583c                         mov    DWORD PTR [eax+0x3c],ebx
0x57f1a5 raw=0x17e5a5  897040                         mov    DWORD PTR [eax+0x40],esi
0x57f1a8 raw=0x17e5a8  eb02                           jmp    0x57f1ac
0x57f1aa raw=0x17e5aa  33c0                           xor    eax,eax
0x57f1ac raw=0x17e5ac  6a10                           push   0x10
0x57f1ae raw=0x17e5ae  a3401cfc00                     mov    ds:0xfc1c40,eax
0x57f1b3 raw=0x17e5b3  e8b0203100                     call   0x891268
0x57f1b8 raw=0x17e5b8  83c404                         add    esp,0x4
0x57f1bb raw=0x17e5bb  3bc6                           cmp    eax,esi
0x57f1bd raw=0x17e5bd  740e                           je     0x57f1cd
0x57f1bf raw=0x17e5bf  897804                         mov    DWORD PTR [eax+0x4],edi
0x57f1c2 raw=0x17e5c2  89700c                         mov    DWORD PTR [eax+0xc],esi
0x57f1c5 raw=0x17e5c5  c700d412c100                   mov    DWORD PTR [eax],0xc112d4
0x57f1cb raw=0x17e5cb  eb02                           jmp    0x57f1cf
0x57f1cd raw=0x17e5cd  33c0                           xor    eax,eax
0x57f1cf raw=0x17e5cf  6a10                           push   0x10
0x57f1d1 raw=0x17e5d1  a3441cfc00                     mov    ds:0xfc1c44,eax
0x57f1d6 raw=0x17e5d6  e88d203100                     call   0x891268
0x57f1db raw=0x17e5db  83c404                         add    esp,0x4
0x57f1de raw=0x17e5de  3bc6                           cmp    eax,esi
0x57f1e0 raw=0x17e5e0  740e                           je     0x57f1f0
0x57f1e2 raw=0x17e5e2  897804                         mov    DWORD PTR [eax+0x4],edi
0x57f1e5 raw=0x17e5e5  89700c                         mov    DWORD PTR [eax+0xc],esi
0x57f1e8 raw=0x17e5e8  c700f412c100                   mov    DWORD PTR [eax],0xc112f4
0x57f1ee raw=0x17e5ee  eb02                           jmp    0x57f1f2
0x57f1f0 raw=0x17e5f0  33c0                           xor    eax,eax
0x57f1f2 raw=0x17e5f2  8b153c1cfc00                   mov    edx,DWORD PTR ds:0xfc1c3c
0x57f1f8 raw=0x17e5f8  a3481cfc00                     mov    ds:0xfc1c48,eax
0x57f1fd raw=0x17e5fd  a12c1cfc00                     mov    eax,ds:0xfc1c2c
0x57f202 raw=0x17e602  8b08                           mov    ecx,DWORD PTR [eax]
0x57f204 raw=0x17e604  894a0c                         mov    DWORD PTR [edx+0xc],ecx
0x57f207 raw=0x17e607  a12c1cfc00                     mov    eax,ds:0xfc1c2c
0x57f20c raw=0x17e60c  8b4804                         mov    ecx,DWORD PTR [eax+0x4]
0x57f20f raw=0x17e60f  8b15401cfc00                   mov    edx,DWORD PTR ds:0xfc1c40
0x57f215 raw=0x17e615  894a0c                         mov    DWORD PTR [edx+0xc],ecx
0x57f218 raw=0x17e618  a12c1cfc00                     mov    eax,ds:0xfc1c2c
0x57f21d raw=0x17e61d  8b4808                         mov    ecx,DWORD PTR [eax+0x8]
0x57f220 raw=0x17e620  8b15441cfc00                   mov    edx,DWORD PTR ds:0xfc1c44
0x57f226 raw=0x17e626  894a0c                         mov    DWORD PTR [edx+0xc],ecx
0x57f229 raw=0x17e629  a12c1cfc00                     mov    eax,ds:0xfc1c2c
0x57f22e raw=0x17e62e  8b480c                         mov    ecx,DWORD PTR [eax+0xc]
0x57f231 raw=0x17e631  8b15481cfc00                   mov    edx,DWORD PTR ds:0xfc1c48
0x57f237 raw=0x17e637  894a0c                         mov    DWORD PTR [edx+0xc],ecx
0x57f23a raw=0x17e63a  8935641cfc00                   mov    DWORD PTR ds:0xfc1c64,esi
0x57f240 raw=0x17e640  89356c1cfc00                   mov    DWORD PTR ds:0xfc1c6c,esi
0x57f246 raw=0x17e646  8935681cfc00                   mov    DWORD PTR ds:0xfc1c68,esi
0x57f24c raw=0x17e64c  c705781cfc00ffffffff           mov    DWORD PTR ds:0xfc1c78,0xffffffff
0x57f256 raw=0x17e656  8bc7                           mov    eax,edi
0x57f258 raw=0x17e658  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x57f25b raw=0x17e65b  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x57f262 raw=0x17e662  59                             pop    ecx
0x57f263 raw=0x17e663  5f                             pop    edi
0x57f264 raw=0x17e664  5e                             pop    esi
0x57f265 raw=0x17e665  5b                             pop    ebx
0x57f266 raw=0x17e666  8be5                           mov    esp,ebp
0x57f268 raw=0x17e668  5d                             pop    ebp
0x57f269 raw=0x17e669  c3                             ret

; book_start | owner+74=1, phase0 and row0, enter CBookState1
; VA 0x57f950..0x57fa31 RAW 0x17ed50 len 225 SHA256 c23f9907301cdbe308eb0b96d6b89b2c9f87f821cb34ac968c3c1e11b0875c99
0x57f950 raw=0x17ed50  55                             push   ebp
0x57f951 raw=0x17ed51  8bec                           mov    ebp,esp
0x57f953 raw=0x17ed53  6aff                           push   0xffffffff
0x57f955 raw=0x17ed55  686e899300                     push   0x93896e
0x57f95a raw=0x17ed5a  64a100000000                   mov    eax,fs:0x0
0x57f960 raw=0x17ed60  50                             push   eax
0x57f961 raw=0x17ed61  56                             push   esi
0x57f962 raw=0x17ed62  57                             push   edi
0x57f963 raw=0x17ed63  a1201fd600                     mov    eax,ds:0xd61f20
0x57f968 raw=0x17ed68  33c5                           xor    eax,ebp
0x57f96a raw=0x17ed6a  50                             push   eax
0x57f96b raw=0x17ed6b  8d45f4                         lea    eax,[ebp-0xc]
0x57f96e raw=0x17ed6e  64a300000000                   mov    fs:0x0,eax
0x57f974 raw=0x17ed74  8bf1                           mov    esi,ecx
0x57f976 raw=0x17ed76  837e7800                       cmp    DWORD PTR [esi+0x78],0x0
0x57f97a raw=0x17ed7a  b801000000                     mov    eax,0x1
0x57f97f raw=0x17ed7f  894674                         mov    DWORD PTR [esi+0x74],eax
0x57f982 raw=0x17ed82  753b                           jne    0x57f9bf
0x57f984 raw=0x17ed84  840540defc00                   test   BYTE PTR ds:0xfcde40,al
0x57f98a raw=0x17ed8a  7526                           jne    0x57f9b2
0x57f98c raw=0x17ed8c  090540defc00                   or     DWORD PTR ds:0xfcde40,eax
0x57f992 raw=0x17ed92  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
0x57f999 raw=0x17ed99  e8e26e1b00                     call   0x736880
0x57f99e raw=0x17ed9e  68f0e6bc00                     push   0xbce6f0
0x57f9a3 raw=0x17eda3  e872293100                     call   0x89231a
0x57f9a8 raw=0x17eda8  83c404                         add    esp,0x4
0x57f9ab raw=0x17edab  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
0x57f9b2 raw=0x17edb2  a128defc00                     mov    eax,ds:0xfcde28
0x57f9b7 raw=0x17edb7  50                             push   eax
0x57f9b8 raw=0x17edb8  8bfe                           mov    edi,esi
0x57f9ba raw=0x17edba  e8b1fcffff                     call   0x57f670
0x57f9bf raw=0x17edbf  837e7c00                       cmp    DWORD PTR [esi+0x7c],0x0
0x57f9c3 raw=0x17edc3  7505                           jne    0x57f9ca
0x57f9c5 raw=0x17edc5  e8f6fdffff                     call   0x57f7c0
0x57f9ca raw=0x17edca  8d4e58                         lea    ecx,[esi+0x58]
0x57f9cd raw=0x17edcd  e8be090000                     call   0x580390
0x57f9d2 raw=0x17edd2  c7467000000000                 mov    DWORD PTR [esi+0x70],0x0
0x57f9d9 raw=0x17edd9  8b4e58                         mov    ecx,DWORD PTR [esi+0x58]
0x57f9dc raw=0x17eddc  8b7e5c                         mov    edi,DWORD PTR [esi+0x5c]
0x57f9df raw=0x17eddf  2bf9                           sub    edi,ecx
0x57f9e1 raw=0x17ede1  b84fecc44e                     mov    eax,0x4ec4ec4f
0x57f9e6 raw=0x17ede6  f7ef                           imul   edi
0x57f9e8 raw=0x17ede8  8b7e44                         mov    edi,DWORD PTR [esi+0x44]
0x57f9eb raw=0x17edeb  c1fa04                         sar    edx,0x4
0x57f9ee raw=0x17edee  8bc2                           mov    eax,edx
0x57f9f0 raw=0x17edf0  c1e81f                         shr    eax,0x1f
0x57f9f3 raw=0x17edf3  03c2                           add    eax,edx
0x57f9f5 raw=0x17edf5  33d2                           xor    edx,edx
0x57f9f7 raw=0x17edf7  3bd0                           cmp    edx,eax
0x57f9f9 raw=0x17edf9  1bc0                           sbb    eax,eax
0x57f9fb raw=0x17edfb  23c1                           and    eax,ecx
0x57f9fd raw=0x17edfd  8b4e54                         mov    ecx,DWORD PTR [esi+0x54]
0x57fa00 raw=0x17ee00  894668                         mov    DWORD PTR [esi+0x68],eax
0x57fa03 raw=0x17ee03  89566c                         mov    DWORD PTR [esi+0x6c],edx
0x57fa06 raw=0x17ee06  85c9                           test   ecx,ecx
0x57fa08 raw=0x17ee08  7407                           je     0x57fa11
0x57fa0a raw=0x17ee0a  8b01                           mov    eax,DWORD PTR [ecx]
0x57fa0c raw=0x17ee0c  8b5004                         mov    edx,DWORD PTR [eax+0x4]
0x57fa0f raw=0x17ee0f  ffd2                           call   edx
0x57fa11 raw=0x17ee11  897e54                         mov    DWORD PTR [esi+0x54],edi
0x57fa14 raw=0x17ee14  85ff                           test   edi,edi
0x57fa16 raw=0x17ee16  7408                           je     0x57fa20
0x57fa18 raw=0x17ee18  8b07                           mov    eax,DWORD PTR [edi]
0x57fa1a raw=0x17ee1a  8b10                           mov    edx,DWORD PTR [eax]
0x57fa1c raw=0x17ee1c  8bcf                           mov    ecx,edi
0x57fa1e raw=0x17ee1e  ffd2                           call   edx
0x57fa20 raw=0x17ee20  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x57fa23 raw=0x17ee23  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x57fa2a raw=0x17ee2a  59                             pop    ecx
0x57fa2b raw=0x17ee2b  5f                             pop    edi
0x57fa2c raw=0x17ee2c  5e                             pop    esi
0x57fa2d raw=0x17ee2d  8be5                           mov    esp,ebp
0x57fa2f raw=0x17ee2f  5d                             pop    ebp
0x57fa30 raw=0x17ee30  c3                             ret

; book_transition | old state exit, current+54 replace, new state enter
; VA 0x57f930..0x57f94e RAW 0x17ed30 len 30 SHA256 a281f533732d8cdf1fa8d9752a65c27e7b2e5bba034f68c7bfb285c0a08e2ad1
0x57f930 raw=0x17ed30  8b4f54                         mov    ecx,DWORD PTR [edi+0x54]
0x57f933 raw=0x17ed33  85c9                           test   ecx,ecx
0x57f935 raw=0x17ed35  7407                           je     0x57f93e
0x57f937 raw=0x17ed37  8b01                           mov    eax,DWORD PTR [ecx]
0x57f939 raw=0x17ed39  8b5004                         mov    edx,DWORD PTR [eax+0x4]
0x57f93c raw=0x17ed3c  ffd2                           call   edx
0x57f93e raw=0x17ed3e  897754                         mov    DWORD PTR [edi+0x54],esi
0x57f941 raw=0x17ed41  85f6                           test   esi,esi
0x57f943 raw=0x17ed43  7408                           je     0x57f94d
0x57f945 raw=0x17ed45  8b06                           mov    eax,DWORD PTR [esi]
0x57f947 raw=0x17ed47  8b10                           mov    edx,DWORD PTR [eax]
0x57f949 raw=0x17ed49  8bce                           mov    ecx,esi
0x57f94b raw=0x17ed4b  ffe2                           jmp    edx
0x57f94d raw=0x17ed4d  c3                             ret

; book_update | current-state tick/done; phases0..3; finalphase clears owner+74
; VA 0x57fa40..0x57fbdf RAW 0x17ee40 len 415 SHA256 735ae7df3cdecc60f2072183b0a3a5ddb4b099ac279280d97c65372ecd297580
0x57fa40 raw=0x17ee40  55                             push   ebp
0x57fa41 raw=0x17ee41  8bec                           mov    ebp,esp
0x57fa43 raw=0x17ee43  51                             push   ecx
0x57fa44 raw=0x17ee44  53                             push   ebx
0x57fa45 raw=0x17ee45  8b5d08                         mov    ebx,DWORD PTR [ebp+0x8]
0x57fa48 raw=0x17ee48  56                             push   esi
0x57fa49 raw=0x17ee49  57                             push   edi
0x57fa4a raw=0x17ee4a  33ff                           xor    edi,edi
0x57fa4c raw=0x17ee4c  397b74                         cmp    DWORD PTR [ebx+0x74],edi
0x57fa4f raw=0x17ee4f  7540                           jne    0x57fa91
0x57fa51 raw=0x17ee51  397b78                         cmp    DWORD PTR [ebx+0x78],edi
0x57fa54 raw=0x17ee54  7509                           jne    0x57fa5f
0x57fa56 raw=0x17ee56  397b7c                         cmp    DWORD PTR [ebx+0x7c],edi
0x57fa59 raw=0x17ee59  0f8478010000                   je     0x57fbd7
0x57fa5f raw=0x17ee5f  397b7c                         cmp    DWORD PTR [ebx+0x7c],edi
0x57fa62 raw=0x17ee62  741e                           je     0x57fa82
0x57fa64 raw=0x17ee64  8b4b0c                         mov    ecx,DWORD PTR [ebx+0xc]
0x57fa67 raw=0x17ee67  83c108                         add    ecx,0x8
0x57fa6a raw=0x17ee6a  897b7c                         mov    DWORD PTR [ebx+0x7c],edi
0x57fa6d raw=0x17ee6d  8b01                           mov    eax,DWORD PTR [ecx]
0x57fa6f raw=0x17ee6f  8b5008                         mov    edx,DWORD PTR [eax+0x8]
0x57fa72 raw=0x17ee72  ffd2                           call   edx
0x57fa74 raw=0x17ee74  8b4b08                         mov    ecx,DWORD PTR [ebx+0x8]
0x57fa77 raw=0x17ee77  8b4108                         mov    eax,DWORD PTR [ecx+0x8]
0x57fa7a raw=0x17ee7a  8b5008                         mov    edx,DWORD PTR [eax+0x8]
0x57fa7d raw=0x17ee7d  83c108                         add    ecx,0x8
0x57fa80 raw=0x17ee80  ffd2                           call   edx
0x57fa82 raw=0x17ee82  8bf3                           mov    esi,ebx
0x57fa84 raw=0x17ee84  e8c7fcffff                     call   0x57f750
0x57fa89 raw=0x17ee89  5f                             pop    edi
0x57fa8a raw=0x17ee8a  5e                             pop    esi
0x57fa8b raw=0x17ee8b  5b                             pop    ebx
0x57fa8c raw=0x17ee8c  59                             pop    ecx
0x57fa8d raw=0x17ee8d  5d                             pop    ebp
0x57fa8e raw=0x17ee8e  c20800                         ret    0x8
0x57fa91 raw=0x17ee91  8b03                           mov    eax,DWORD PTR [ebx]
0x57fa93 raw=0x17ee93  8b08                           mov    ecx,DWORD PTR [eax]
0x57fa95 raw=0x17ee95  8d9380000000                   lea    edx,[ebx+0x80]
0x57fa9b raw=0x17ee9b  52                             push   edx
0x57fa9c raw=0x17ee9c  688b000000                     push   0x8b
0x57faa1 raw=0x17eea1  50                             push   eax
0x57faa2 raw=0x17eea2  8b81e8000000                   mov    eax,DWORD PTR [ecx+0xe8]
0x57faa8 raw=0x17eea8  ffd0                           call   eax
0x57faaa raw=0x17eeaa  d9450c                         fld    DWORD PTR [ebp+0xc]
0x57faad raw=0x17eead  8b4b54                         mov    ecx,DWORD PTR [ebx+0x54]
0x57fab0 raw=0x17eeb0  8b11                           mov    edx,DWORD PTR [ecx]
0x57fab2 raw=0x17eeb2  8b420c                         mov    eax,DWORD PTR [edx+0xc]
0x57fab5 raw=0x17eeb5  51                             push   ecx
0x57fab6 raw=0x17eeb6  d91c24                         fstp   DWORD PTR [esp]
0x57fab9 raw=0x17eeb9  ffd0                           call   eax
0x57fabb raw=0x17eebb  8b4b54                         mov    ecx,DWORD PTR [ebx+0x54]
0x57fabe raw=0x17eebe  3bcf                           cmp    ecx,edi
0x57fac0 raw=0x17eec0  0f8411010000                   je     0x57fbd7
0x57fac6 raw=0x17eec6  8b11                           mov    edx,DWORD PTR [ecx]
0x57fac8 raw=0x17eec8  8b4208                         mov    eax,DWORD PTR [edx+0x8]
0x57facb raw=0x17eecb  ffd0                           call   eax
0x57facd raw=0x17eecd  85c0                           test   eax,eax
0x57facf raw=0x17eecf  0f8402010000                   je     0x57fbd7
0x57fad5 raw=0x17eed5  8b436c                         mov    eax,DWORD PTR [ebx+0x6c]
0x57fad8 raw=0x17eed8  83f803                         cmp    eax,0x3
0x57fadb raw=0x17eedb  0f87f6000000                   ja     0x57fbd7
0x57fae1 raw=0x17eee1  ff2485e0fb5700                 jmp    DWORD PTR [eax*4+0x57fbe0]
0x57fae8 raw=0x17eee8  897b70                         mov    DWORD PTR [ebx+0x70],edi
0x57faeb raw=0x17eeeb  be01000000                     mov    esi,0x1
0x57faf0 raw=0x17eef0  8d4358                         lea    eax,[ebx+0x58]
0x57faf3 raw=0x17eef3  33ff                           xor    edi,edi
0x57faf5 raw=0x17eef5  89736c                         mov    DWORD PTR [ebx+0x6c],esi
0x57faf8 raw=0x17eef8  e8a30e0000                     call   0x5809a0
0x57fafd raw=0x17eefd  894368                         mov    DWORD PTR [ebx+0x68],eax
0x57fb00 raw=0x17ef00  85c0                           test   eax,eax
0x57fb02 raw=0x17ef02  742d                           je     0x57fb31
0x57fb04 raw=0x17ef04  8b4b10                         mov    ecx,DWORD PTR [ebx+0x10]
0x57fb07 raw=0x17ef07  85c9                           test   ecx,ecx
0x57fb09 raw=0x17ef09  740a                           je     0x57fb15
0x57fb0b raw=0x17ef0b  8b11                           mov    edx,DWORD PTR [ecx]
0x57fb0d raw=0x17ef0d  8b02                           mov    eax,DWORD PTR [edx]
0x57fb0f raw=0x17ef0f  56                             push   esi
0x57fb10 raw=0x17ef10  ffd0                           call   eax
0x57fb12 raw=0x17ef12  897b10                         mov    DWORD PTR [ebx+0x10],edi
0x57fb15 raw=0x17ef15  8b4368                         mov    eax,DWORD PTR [ebx+0x68]
0x57fb18 raw=0x17ef18  83c008                         add    eax,0x8
0x57fb1b raw=0x17ef1b  83781410                       cmp    DWORD PTR [eax+0x14],0x10
0x57fb1f raw=0x17ef1f  7202                           jb     0x57fb23
0x57fb21 raw=0x17ef21  8b00                           mov    eax,DWORD PTR [eax]
0x57fb23 raw=0x17ef23  6a00                           push   0x0
0x57fb25 raw=0x17ef25  50                             push   eax
0x57fb26 raw=0x17ef26  e805481b00                     call   0x734330
0x57fb2b raw=0x17ef2b  83c408                         add    esp,0x8
0x57fb2e raw=0x17ef2e  894310                         mov    DWORD PTR [ebx+0x10],eax
0x57fb31 raw=0x17ef31  8b4b6c                         mov    ecx,DWORD PTR [ebx+0x6c]
0x57fb34 raw=0x17ef34  8b748b44                       mov    esi,DWORD PTR [ebx+ecx*4+0x44]
0x57fb38 raw=0x17ef38  8bfb                           mov    edi,ebx
0x57fb3a raw=0x17ef3a  e8f1fdffff                     call   0x57f930
0x57fb3f raw=0x17ef3f  5f                             pop    edi
0x57fb40 raw=0x17ef40  5e                             pop    esi
0x57fb41 raw=0x17ef41  5b                             pop    ebx
0x57fb42 raw=0x17ef42  59                             pop    ecx
0x57fb43 raw=0x17ef43  5d                             pop    ebp
0x57fb44 raw=0x17ef44  c20800                         ret    0x8
0x57fb47 raw=0x17ef47  8b7b70                         mov    edi,DWORD PTR [ebx+0x70]
0x57fb4a raw=0x17ef4a  47                             inc    edi
0x57fb4b raw=0x17ef4b  8d4358                         lea    eax,[ebx+0x58]
0x57fb4e raw=0x17ef4e  e84d0e0000                     call   0x5809a0
0x57fb53 raw=0x17ef53  f7d8                           neg    eax
0x57fb55 raw=0x17ef55  1bc0                           sbb    eax,eax
0x57fb57 raw=0x17ef57  83c003                         add    eax,0x3
0x57fb5a raw=0x17ef5a  89436c                         mov    DWORD PTR [ebx+0x6c],eax
0x57fb5d raw=0x17ef5d  8b748344                       mov    esi,DWORD PTR [ebx+eax*4+0x44]
0x57fb61 raw=0x17ef61  8bfb                           mov    edi,ebx
0x57fb63 raw=0x17ef63  e8c8fdffff                     call   0x57f930
0x57fb68 raw=0x17ef68  5f                             pop    edi
0x57fb69 raw=0x17ef69  5e                             pop    esi
0x57fb6a raw=0x17ef6a  5b                             pop    ebx
0x57fb6b raw=0x17ef6b  59                             pop    ecx
0x57fb6c raw=0x17ef6c  5d                             pop    ebp
0x57fb6d raw=0x17ef6d  c20800                         ret    0x8
0x57fb70 raw=0x17ef70  be01000000                     mov    esi,0x1
0x57fb75 raw=0x17ef75  017370                         add    DWORD PTR [ebx+0x70],esi
0x57fb78 raw=0x17ef78  8b7b70                         mov    edi,DWORD PTR [ebx+0x70]
0x57fb7b raw=0x17ef7b  8d4358                         lea    eax,[ebx+0x58]
0x57fb7e raw=0x17ef7e  e81d0e0000                     call   0x5809a0
0x57fb83 raw=0x17ef83  894368                         mov    DWORD PTR [ebx+0x68],eax
0x57fb86 raw=0x17ef86  89736c                         mov    DWORD PTR [ebx+0x6c],esi
0x57fb89 raw=0x17ef89  85c0                           test   eax,eax
0x57fb8b raw=0x17ef8b  7431                           je     0x57fbbe
0x57fb8d raw=0x17ef8d  8b4b10                         mov    ecx,DWORD PTR [ebx+0x10]
0x57fb90 raw=0x17ef90  85c9                           test   ecx,ecx
0x57fb92 raw=0x17ef92  740e                           je     0x57fba2
0x57fb94 raw=0x17ef94  8b01                           mov    eax,DWORD PTR [ecx]
0x57fb96 raw=0x17ef96  8b10                           mov    edx,DWORD PTR [eax]
0x57fb98 raw=0x17ef98  56                             push   esi
0x57fb99 raw=0x17ef99  ffd2                           call   edx
0x57fb9b raw=0x17ef9b  c7431000000000                 mov    DWORD PTR [ebx+0x10],0x0
0x57fba2 raw=0x17efa2  8b4368                         mov    eax,DWORD PTR [ebx+0x68]
0x57fba5 raw=0x17efa5  83c008                         add    eax,0x8
0x57fba8 raw=0x17efa8  83781410                       cmp    DWORD PTR [eax+0x14],0x10
0x57fbac raw=0x17efac  7202                           jb     0x57fbb0
0x57fbae raw=0x17efae  8b00                           mov    eax,DWORD PTR [eax]
0x57fbb0 raw=0x17efb0  6a00                           push   0x0
0x57fbb2 raw=0x17efb2  50                             push   eax
0x57fbb3 raw=0x17efb3  e878471b00                     call   0x734330
0x57fbb8 raw=0x17efb8  83c408                         add    esp,0x8
0x57fbbb raw=0x17efbb  894310                         mov    DWORD PTR [ebx+0x10],eax
0x57fbbe raw=0x17efbe  8b436c                         mov    eax,DWORD PTR [ebx+0x6c]
0x57fbc1 raw=0x17efc1  8b748344                       mov    esi,DWORD PTR [ebx+eax*4+0x44]
0x57fbc5 raw=0x17efc5  8bfb                           mov    edi,ebx
0x57fbc7 raw=0x17efc7  e864fdffff                     call   0x57f930
0x57fbcc raw=0x17efcc  5f                             pop    edi
0x57fbcd raw=0x17efcd  5e                             pop    esi
0x57fbce raw=0x17efce  5b                             pop    ebx
0x57fbcf raw=0x17efcf  59                             pop    ecx
0x57fbd0 raw=0x17efd0  5d                             pop    ebp
0x57fbd1 raw=0x17efd1  c20800                         ret    0x8
0x57fbd4 raw=0x17efd4  897b74                         mov    DWORD PTR [ebx+0x74],edi
0x57fbd7 raw=0x17efd7  5f                             pop    edi
0x57fbd8 raw=0x17efd8  5e                             pop    esi
0x57fbd9 raw=0x17efd9  5b                             pop    ebx
0x57fbda raw=0x17efda  59                             pop    ecx
0x57fbdb raw=0x17efdb  5d                             pop    ebp
0x57fbdc raw=0x17efdc  c20800                         ret    0x8

; book_row_lookup | bounds checked row index over vector stride0x34
; VA 0x5809a0..0x5809ca RAW 0x17fda0 len 42 SHA256 9e83ed9dc44519dc484040febe53598814da114dedcd0d640e787a90e1da7d72
0x5809a0 raw=0x17fda0  8b4804                         mov    ecx,DWORD PTR [eax+0x4]
0x5809a3 raw=0x17fda3  56                             push   esi
0x5809a4 raw=0x17fda4  8b30                           mov    esi,DWORD PTR [eax]
0x5809a6 raw=0x17fda6  2bce                           sub    ecx,esi
0x5809a8 raw=0x17fda8  b84fecc44e                     mov    eax,0x4ec4ec4f
0x5809ad raw=0x17fdad  f7e9                           imul   ecx
0x5809af raw=0x17fdaf  c1fa04                         sar    edx,0x4
0x5809b2 raw=0x17fdb2  8bc2                           mov    eax,edx
0x5809b4 raw=0x17fdb4  c1e81f                         shr    eax,0x1f
0x5809b7 raw=0x17fdb7  03c2                           add    eax,edx
0x5809b9 raw=0x17fdb9  3bc7                           cmp    eax,edi
0x5809bb raw=0x17fdbb  7609                           jbe    0x5809c6
0x5809bd raw=0x17fdbd  8bc7                           mov    eax,edi
0x5809bf raw=0x17fdbf  6bc034                         imul   eax,eax,0x34
0x5809c2 raw=0x17fdc2  03c6                           add    eax,esi
0x5809c4 raw=0x17fdc4  5e                             pop    esi
0x5809c5 raw=0x17fdc5  c3                             ret
0x5809c6 raw=0x17fdc6  33c0                           xor    eax,eax
0x5809c8 raw=0x17fdc8  5e                             pop    esi
0x5809c9 raw=0x17fdc9  c3                             ret

; book_state_enter | time reset and model phase reset
; VA 0x580f90..0x580fa4 RAW 0x180390 len 20 SHA256 d2c23d75728832aa9feb452cee499c874c6397587ed57165fa8de5b296e2f924
0x580f90 raw=0x180390  0f57c0                         xorps  xmm0,xmm0
0x580f93 raw=0x180393  8b410c                         mov    eax,DWORD PTR [ecx+0xc]
0x580f96 raw=0x180396  f30f114108                     movss  DWORD PTR [ecx+0x8],xmm0
0x580f9b raw=0x18039b  8b4804                         mov    ecx,DWORD PTR [eax+0x4]
0x580f9e raw=0x18039e  f30f114138                     movss  DWORD PTR [ecx+0x38],xmm0
0x580fa3 raw=0x1803a3  c3                             ret

; book_state_time_done | state+8 * 30.0 > model+34 predicate
; VA 0x580fb0..0x580fd3 RAW 0x1803b0 len 35 SHA256 1ba984e689684638e4b00ac92c1504ad8e5460da17a5e233efce981ec6e73149
0x580fb0 raw=0x1803b0  d94108                         fld    DWORD PTR [ecx+0x8]
0x580fb3 raw=0x1803b3  8b410c                         mov    eax,DWORD PTR [ecx+0xc]
0x580fb6 raw=0x1803b6  dc0dc857c500                   fmul   QWORD PTR ds:0xc557c8
0x580fbc raw=0x1803bc  8b4804                         mov    ecx,DWORD PTR [eax+0x4]
0x580fbf raw=0x1803bf  d94134                         fld    DWORD PTR [ecx+0x34]
0x580fc2 raw=0x1803c2  d9c9                           fxch   st(1)
0x580fc4 raw=0x1803c4  dff1                           fcomip st,st(1)
0x580fc6 raw=0x1803c6  ddd8                           fstp   st(0)
0x580fc8 raw=0x1803c8  7606                           jbe    0x580fd0
0x580fca raw=0x1803ca  b801000000                     mov    eax,0x1
0x580fcf raw=0x1803cf  c3                             ret
0x580fd0 raw=0x1803d0  33c0                           xor    eax,eax
0x580fd2 raw=0x1803d2  c3                             ret

; book_state_time_update | model/camera update and state+8 += delta
; VA 0x580fe0..0x581054 RAW 0x1803e0 len 116 SHA256 cc3ee9448a4f11e51809be357a033777ed8dfb90ab8eb26017ef55f7480db8b5
0x580fe0 raw=0x1803e0  55                             push   ebp
0x580fe1 raw=0x1803e1  8bec                           mov    ebp,esp
0x580fe3 raw=0x1803e3  56                             push   esi
0x580fe4 raw=0x1803e4  8bf1                           mov    esi,ecx
0x580fe6 raw=0x1803e6  8b460c                         mov    eax,DWORD PTR [esi+0xc]
0x580fe9 raw=0x1803e9  8b4804                         mov    ecx,DWORD PTR [eax+0x4]
0x580fec raw=0x1803ec  8b4604                         mov    eax,DWORD PTR [esi+0x4]
0x580fef raw=0x1803ef  8b501c                         mov    edx,DWORD PTR [eax+0x1c]
0x580ff2 raw=0x1803f2  89513c                         mov    DWORD PTR [ecx+0x3c],edx
0x580ff5 raw=0x1803f5  8b5020                         mov    edx,DWORD PTR [eax+0x20]
0x580ff8 raw=0x1803f8  895140                         mov    DWORD PTR [ecx+0x40],edx
0x580ffb raw=0x1803fb  8b5024                         mov    edx,DWORD PTR [eax+0x24]
0x580ffe raw=0x1803fe  895144                         mov    DWORD PTR [ecx+0x44],edx
0x581001 raw=0x180401  8b501c                         mov    edx,DWORD PTR [eax+0x1c]
0x581004 raw=0x180404  8b4920                         mov    ecx,DWORD PTR [ecx+0x20]
0x581007 raw=0x180407  895168                         mov    DWORD PTR [ecx+0x68],edx
0x58100a raw=0x18040a  8b5020                         mov    edx,DWORD PTR [eax+0x20]
0x58100d raw=0x18040d  89516c                         mov    DWORD PTR [ecx+0x6c],edx
0x581010 raw=0x180410  8b4024                         mov    eax,DWORD PTR [eax+0x24]
0x581013 raw=0x180413  894170                         mov    DWORD PTR [ecx+0x70],eax
0x581016 raw=0x180416  c781c000000000000000           mov    DWORD PTR [ecx+0xc0],0x0
0x581020 raw=0x180420  8b4e0c                         mov    ecx,DWORD PTR [esi+0xc]
0x581023 raw=0x180423  8b5104                         mov    edx,DWORD PTR [ecx+0x4]
0x581026 raw=0x180426  57                             push   edi
0x581027 raw=0x180427  8b7e04                         mov    edi,DWORD PTR [esi+0x4]
0x58102a raw=0x18042a  83c728                         add    edi,0x28
0x58102d raw=0x18042d  52                             push   edx
0x58102e raw=0x18042e  e89dc82400                     call   0x7cd8d0
0x581033 raw=0x180433  d94508                         fld    DWORD PTR [ebp+0x8]
0x581036 raw=0x180436  8b460c                         mov    eax,DWORD PTR [esi+0xc]
0x581039 raw=0x180439  8b4004                         mov    eax,DWORD PTR [eax+0x4]
0x58103c raw=0x18043c  51                             push   ecx
0x58103d raw=0x18043d  d91c24                         fstp   DWORD PTR [esp]
0x581040 raw=0x180440  e8ebc72400                     call   0x7cd830
0x581045 raw=0x180445  d94608                         fld    DWORD PTR [esi+0x8]
0x581048 raw=0x180448  5f                             pop    edi
0x581049 raw=0x180449  d84508                         fadd   DWORD PTR [ebp+0x8]
0x58104c raw=0x18044c  d95e08                         fstp   DWORD PTR [esi+0x8]
0x58104f raw=0x18044f  5e                             pop    esi
0x581050 raw=0x180450  5d                             pop    ebp
0x581051 raw=0x180451  c20400                         ret    0x4

; book_state_exit | state time reset
; VA 0x581080..0x581089 RAW 0x180480 len 9 SHA256 1fb1fa8b00bb10efe7e2b59e29fe0b1c2747bd7b8dc9177f31e6107925dbfd48
0x581080 raw=0x180480  0f57c0                         xorps  xmm0,xmm0
0x581083 raw=0x180483  f30f114108                     movss  DWORD PTR [ecx+0x8],xmm0
0x581088 raw=0x180488  c3                             ret

; book_state1_tick | shared580FE0 update then rendering
; VA 0x581090..0x58118b RAW 0x180490 len 251 SHA256 c221ce42d5b377e0d9d49d890e6e1e59b9f9b75ceeaec47640b8dd4947bd166b
0x581090 raw=0x180490  55                             push   ebp
0x581091 raw=0x180491  8bec                           mov    ebp,esp
0x581093 raw=0x180493  6aff                           push   0xffffffff
0x581095 raw=0x180495  689eb79200                     push   0x92b79e
0x58109a raw=0x18049a  64a100000000                   mov    eax,fs:0x0
0x5810a0 raw=0x1804a0  50                             push   eax
0x5810a1 raw=0x1804a1  56                             push   esi
0x5810a2 raw=0x1804a2  57                             push   edi
0x5810a3 raw=0x1804a3  a1201fd600                     mov    eax,ds:0xd61f20
0x5810a8 raw=0x1804a8  33c5                           xor    eax,ebp
0x5810aa raw=0x1804aa  50                             push   eax
0x5810ab raw=0x1804ab  8d45f4                         lea    eax,[ebp-0xc]
0x5810ae raw=0x1804ae  64a300000000                   mov    fs:0x0,eax
0x5810b4 raw=0x1804b4  8bf1                           mov    esi,ecx
0x5810b6 raw=0x1804b6  d94508                         fld    DWORD PTR [ebp+0x8]
0x5810b9 raw=0x1804b9  51                             push   ecx
0x5810ba raw=0x1804ba  d91c24                         fstp   DWORD PTR [esp]
0x5810bd raw=0x1804bd  e81effffff                     call   0x580fe0
0x5810c2 raw=0x1804c2  f605e879fb0001                 test   BYTE PTR ds:0xfb79e8,0x1
0x5810c9 raw=0x1804c9  7527                           jne    0x5810f2
0x5810cb raw=0x1804cb  830de879fb0001                 or     DWORD PTR ds:0xfb79e8,0x1
0x5810d2 raw=0x1804d2  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
0x5810d9 raw=0x1804d9  e8027d2100                     call   0x798de0
0x5810de raw=0x1804de  68e0d2bc00                     push   0xbcd2e0
0x5810e3 raw=0x1804e3  e832123100                     call   0x89231a
0x5810e8 raw=0x1804e8  83c404                         add    esp,0x4
0x5810eb raw=0x1804eb  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
0x5810f2 raw=0x1804f2  68a876fb00                     push   0xfb76a8
0x5810f7 raw=0x1804f7  e8f4942100                     call   0x79a5f0
0x5810fc raw=0x1804fc  8bf8                           mov    edi,eax
0x5810fe raw=0x1804fe  8b4604                         mov    eax,DWORD PTR [esi+0x4]
0x581101 raw=0x180501  8b4808                         mov    ecx,DWORD PTR [eax+0x8]
0x581104 raw=0x180504  8b11                           mov    edx,DWORD PTR [ecx]
0x581106 raw=0x180506  8b4238                         mov    eax,DWORD PTR [edx+0x38]
0x581109 raw=0x180509  6aff                           push   0xffffffff
0x58110b raw=0x18050b  6aff                           push   0xffffffff
0x58110d raw=0x18050d  ffd0                           call   eax
0x58110f raw=0x18050f  85c0                           test   eax,eax
0x581111 raw=0x180511  7428                           je     0x58113b
0x581113 raw=0x180513  8b0f                           mov    ecx,DWORD PTR [edi]
0x581115 raw=0x180515  d9e8                           fld1
0x581117 raw=0x180517  8b91ac000000                   mov    edx,DWORD PTR [ecx+0xac]
0x58111d raw=0x18051d  6a00                           push   0x0
0x58111f raw=0x18051f  51                             push   ecx
0x581120 raw=0x180520  d91c24                         fstp   DWORD PTR [esp]
0x581123 raw=0x180523  6a00                           push   0x0
0x581125 raw=0x180525  6a01                           push   0x1
0x581127 raw=0x180527  6a00                           push   0x0
0x581129 raw=0x180529  6a00                           push   0x0
0x58112b raw=0x18052b  57                             push   edi
0x58112c raw=0x18052c  ffd2                           call   edx
0x58112e raw=0x18052e  8b4604                         mov    eax,DWORD PTR [esi+0x4]
0x581131 raw=0x180531  8b4808                         mov    ecx,DWORD PTR [eax+0x8]
0x581134 raw=0x180534  8b11                           mov    edx,DWORD PTR [ecx]
0x581136 raw=0x180536  8b423c                         mov    eax,DWORD PTR [edx+0x3c]
0x581139 raw=0x180539  ffd0                           call   eax
0x58113b raw=0x18053b  8b4e04                         mov    ecx,DWORD PTR [esi+0x4]
0x58113e raw=0x18053e  8b490c                         mov    ecx,DWORD PTR [ecx+0xc]
0x581141 raw=0x180541  8b11                           mov    edx,DWORD PTR [ecx]
0x581143 raw=0x180543  8b4238                         mov    eax,DWORD PTR [edx+0x38]
0x581146 raw=0x180546  6aff                           push   0xffffffff
0x581148 raw=0x180548  6aff                           push   0xffffffff
0x58114a raw=0x18054a  ffd0                           call   eax
0x58114c raw=0x18054c  85c0                           test   eax,eax
0x58114e raw=0x18054e  7428                           je     0x581178
0x581150 raw=0x180550  8b0f                           mov    ecx,DWORD PTR [edi]
0x581152 raw=0x180552  d9e8                           fld1
0x581154 raw=0x180554  8b91ac000000                   mov    edx,DWORD PTR [ecx+0xac]
0x58115a raw=0x18055a  6a00                           push   0x0
0x58115c raw=0x18055c  51                             push   ecx
0x58115d raw=0x18055d  d91c24                         fstp   DWORD PTR [esp]
0x581160 raw=0x180560  6a00                           push   0x0
0x581162 raw=0x180562  6a01                           push   0x1
0x581164 raw=0x180564  6a00                           push   0x0
0x581166 raw=0x180566  6a00                           push   0x0
0x581168 raw=0x180568  57                             push   edi
0x581169 raw=0x180569  ffd2                           call   edx
0x58116b raw=0x18056b  8b4604                         mov    eax,DWORD PTR [esi+0x4]
0x58116e raw=0x18056e  8b480c                         mov    ecx,DWORD PTR [eax+0xc]
0x581171 raw=0x180571  8b11                           mov    edx,DWORD PTR [ecx]
0x581173 raw=0x180573  8b423c                         mov    eax,DWORD PTR [edx+0x3c]
0x581176 raw=0x180576  ffd0                           call   eax
0x581178 raw=0x180578  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x58117b raw=0x18057b  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x581182 raw=0x180582  59                             pop    ecx
0x581183 raw=0x180583  5f                             pop    edi
0x581184 raw=0x180584  5e                             pop    esi
0x581185 raw=0x180585  8be5                           mov    esp,ebp
0x581187 raw=0x180587  5d                             pop    ebp
0x581188 raw=0x180588  c20400                         ret    0x4

; book_state2_enter | state2 counter+40 and done+44 reset0
; VA 0x581190..0x5812f2 RAW 0x180590 len 354 SHA256 a6e584c17ead6a7e636a5be03d69ba210fe7c7808c22ee52c928430eb16926ed
0x581190 raw=0x180590  55                             push   ebp
0x581191 raw=0x180591  8bec                           mov    ebp,esp
0x581193 raw=0x180593  6aff                           push   0xffffffff
0x581195 raw=0x180595  687c389300                     push   0x93387c
0x58119a raw=0x18059a  64a100000000                   mov    eax,fs:0x0
0x5811a0 raw=0x1805a0  50                             push   eax
0x5811a1 raw=0x1805a1  56                             push   esi
0x5811a2 raw=0x1805a2  57                             push   edi
0x5811a3 raw=0x1805a3  a1201fd600                     mov    eax,ds:0xd61f20
0x5811a8 raw=0x1805a8  33c5                           xor    eax,ebp
0x5811aa raw=0x1805aa  50                             push   eax
0x5811ab raw=0x1805ab  8d45f4                         lea    eax,[ebp-0xc]
0x5811ae raw=0x1805ae  64a300000000                   mov    fs:0x0,eax
0x5811b4 raw=0x1805b4  8bf1                           mov    esi,ecx
0x5811b6 raw=0x1805b6  f605e879fb0001                 test   BYTE PTR ds:0xfb79e8,0x1
0x5811bd raw=0x1805bd  8b460c                         mov    eax,DWORD PTR [esi+0xc]
0x5811c0 raw=0x1805c0  0f57c0                         xorps  xmm0,xmm0
0x5811c3 raw=0x1805c3  f30f114608                     movss  DWORD PTR [esi+0x8],xmm0
0x5811c8 raw=0x1805c8  8b4004                         mov    eax,DWORD PTR [eax+0x4]
0x5811cb raw=0x1805cb  f30f114038                     movss  DWORD PTR [eax+0x38],xmm0
0x5811d0 raw=0x1805d0  d94610                         fld    DWORD PTR [esi+0x10]
0x5811d3 raw=0x1805d3  d95e18                         fstp   DWORD PTR [esi+0x18]
0x5811d6 raw=0x1805d6  d94620                         fld    DWORD PTR [esi+0x20]
0x5811d9 raw=0x1805d9  d95e28                         fstp   DWORD PTR [esi+0x28]
0x5811dc raw=0x1805dc  d94630                         fld    DWORD PTR [esi+0x30]
0x5811df raw=0x1805df  d95e38                         fstp   DWORD PTR [esi+0x38]
0x5811e2 raw=0x1805e2  c7464000000000                 mov    DWORD PTR [esi+0x40],0x0
0x5811e9 raw=0x1805e9  c7464400000000                 mov    DWORD PTR [esi+0x44],0x0
0x5811f0 raw=0x1805f0  7527                           jne    0x581219
0x5811f2 raw=0x1805f2  830de879fb0001                 or     DWORD PTR ds:0xfb79e8,0x1
0x5811f9 raw=0x1805f9  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
0x581200 raw=0x180600  e8db7b2100                     call   0x798de0
0x581205 raw=0x180605  68e0d2bc00                     push   0xbcd2e0
0x58120a raw=0x18060a  e80b113100                     call   0x89231a
0x58120f raw=0x18060f  83c404                         add    esp,0x4
0x581212 raw=0x180612  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
0x581219 raw=0x180619  68a876fb00                     push   0xfb76a8
0x58121e raw=0x18061e  e8cd932100                     call   0x79a5f0
0x581223 raw=0x180623  8b4e04                         mov    ecx,DWORD PTR [esi+0x4]
0x581226 raw=0x180626  8b4908                         mov    ecx,DWORD PTR [ecx+0x8]
0x581229 raw=0x180629  8b11                           mov    edx,DWORD PTR [ecx]
0x58122b raw=0x18062b  6aff                           push   0xffffffff
0x58122d raw=0x18062d  8bf8                           mov    edi,eax
0x58122f raw=0x18062f  8b4238                         mov    eax,DWORD PTR [edx+0x38]
0x581232 raw=0x180632  6aff                           push   0xffffffff
0x581234 raw=0x180634  ffd0                           call   eax
0x581236 raw=0x180636  85c0                           test   eax,eax
0x581238 raw=0x180638  7428                           je     0x581262
0x58123a raw=0x18063a  8b0f                           mov    ecx,DWORD PTR [edi]
0x58123c raw=0x18063c  d9e8                           fld1
0x58123e raw=0x18063e  8b91ac000000                   mov    edx,DWORD PTR [ecx+0xac]
0x581244 raw=0x180644  6a00                           push   0x0
0x581246 raw=0x180646  51                             push   ecx
0x581247 raw=0x180647  d91c24                         fstp   DWORD PTR [esp]
0x58124a raw=0x18064a  6a00                           push   0x0
0x58124c raw=0x18064c  6a01                           push   0x1
0x58124e raw=0x18064e  6a00                           push   0x0
0x581250 raw=0x180650  6a00                           push   0x0
0x581252 raw=0x180652  57                             push   edi
0x581253 raw=0x180653  ffd2                           call   edx
0x581255 raw=0x180655  8b4604                         mov    eax,DWORD PTR [esi+0x4]
0x581258 raw=0x180658  8b4808                         mov    ecx,DWORD PTR [eax+0x8]
0x58125b raw=0x18065b  8b11                           mov    edx,DWORD PTR [ecx]
0x58125d raw=0x18065d  8b423c                         mov    eax,DWORD PTR [edx+0x3c]
0x581260 raw=0x180660  ffd0                           call   eax
0x581262 raw=0x180662  8b4e04                         mov    ecx,DWORD PTR [esi+0x4]
0x581265 raw=0x180665  8b490c                         mov    ecx,DWORD PTR [ecx+0xc]
0x581268 raw=0x180668  8b11                           mov    edx,DWORD PTR [ecx]
0x58126a raw=0x18066a  8b4238                         mov    eax,DWORD PTR [edx+0x38]
0x58126d raw=0x18066d  6aff                           push   0xffffffff
0x58126f raw=0x18066f  6aff                           push   0xffffffff
0x581271 raw=0x180671  ffd0                           call   eax
0x581273 raw=0x180673  85c0                           test   eax,eax
0x581275 raw=0x180675  7428                           je     0x58129f
0x581277 raw=0x180677  8b0f                           mov    ecx,DWORD PTR [edi]
0x581279 raw=0x180679  d9e8                           fld1
0x58127b raw=0x18067b  8b91ac000000                   mov    edx,DWORD PTR [ecx+0xac]
0x581281 raw=0x180681  6a00                           push   0x0
0x581283 raw=0x180683  51                             push   ecx
0x581284 raw=0x180684  d91c24                         fstp   DWORD PTR [esp]
0x581287 raw=0x180687  6a00                           push   0x0
0x581289 raw=0x180689  6a01                           push   0x1
0x58128b raw=0x18068b  6a00                           push   0x0
0x58128d raw=0x18068d  6a00                           push   0x0
0x58128f raw=0x18068f  57                             push   edi
0x581290 raw=0x180690  ffd2                           call   edx
0x581292 raw=0x180692  8b4604                         mov    eax,DWORD PTR [esi+0x4]
0x581295 raw=0x180695  8b480c                         mov    ecx,DWORD PTR [eax+0xc]
0x581298 raw=0x180698  8b11                           mov    edx,DWORD PTR [ecx]
0x58129a raw=0x18069a  8b423c                         mov    eax,DWORD PTR [edx+0x3c]
0x58129d raw=0x18069d  ffd0                           call   eax
0x58129f raw=0x18069f  f605a472fb0001                 test   BYTE PTR ds:0xfb72a4,0x1
0x5812a6 raw=0x1806a6  7527                           jne    0x5812cf
0x5812a8 raw=0x1806a8  b801000000                     mov    eax,0x1
0x5812ad raw=0x1806ad  0905a472fb00                   or     DWORD PTR ds:0xfb72a4,eax
0x5812b3 raw=0x1806b3  8945fc                         mov    DWORD PTR [ebp-0x4],eax
0x5812b6 raw=0x1806b6  e895e5f1ff                     call   0x49f850
0x5812bb raw=0x1806bb  68e0cfbc00                     push   0xbccfe0
0x5812c0 raw=0x1806c0  e855103100                     call   0x89231a
0x5812c5 raw=0x1806c5  83c404                         add    esp,0x4
0x5812c8 raw=0x1806c8  c745fcffffffff                 mov    DWORD PTR [ebp-0x4],0xffffffff
0x5812cf raw=0x1806cf  8b4e04                         mov    ecx,DWORD PTR [esi+0x4]
0x5812d2 raw=0x1806d2  8b4970                         mov    ecx,DWORD PTR [ecx+0x70]
0x5812d5 raw=0x1806d5  6a00                           push   0x0
0x5812d7 raw=0x1806d7  68a872fb00                     push   0xfb72a8
0x5812dc raw=0x1806dc  e80ff1f1ff                     call   0x4a03f0
0x5812e1 raw=0x1806e1  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x5812e4 raw=0x1806e4  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x5812eb raw=0x1806eb  59                             pop    ecx
0x5812ec raw=0x1806ec  5f                             pop    edi
0x5812ed raw=0x1806ed  5e                             pop    esi
0x5812ee raw=0x1806ee  8be5                           mov    esp,ebp
0x5812f0 raw=0x1806f0  5d                             pop    ebp
0x5812f1 raw=0x1806f1  c3                             ret

; book_state2_writer | bounded prefix: interpolation+30 tick, text-row count overflow sets +44=1
; VA 0x581300..0x5813c3 RAW 0x180700 len 195 SHA256 c772c1f6679dfa8f8ba90221737a1b667a527c7cc8b2c70235411633cdc1ee48
0x581300 raw=0x180700  55                             push   ebp
0x581301 raw=0x180701  8bec                           mov    ebp,esp
0x581303 raw=0x180703  83e4f8                         and    esp,0xfffffff8
0x581306 raw=0x180706  6aff                           push   0xffffffff
0x581308 raw=0x180708  683a389300                     push   0x93383a
0x58130d raw=0x18070d  64a100000000                   mov    eax,fs:0x0
0x581313 raw=0x180713  50                             push   eax
0x581314 raw=0x180714  83ec20                         sub    esp,0x20
0x581317 raw=0x180717  53                             push   ebx
0x581318 raw=0x180718  56                             push   esi
0x581319 raw=0x180719  57                             push   edi
0x58131a raw=0x18071a  a1201fd600                     mov    eax,ds:0xd61f20
0x58131f raw=0x18071f  33c4                           xor    eax,esp
0x581321 raw=0x180721  50                             push   eax
0x581322 raw=0x180722  8d442430                       lea    eax,[esp+0x30]
0x581326 raw=0x180726  64a300000000                   mov    fs:0x0,eax
0x58132c raw=0x18072c  8bf9                           mov    edi,ecx
0x58132e raw=0x18072e  d94508                         fld    DWORD PTR [ebp+0x8]
0x581331 raw=0x180731  51                             push   ecx
0x581332 raw=0x180732  d91c24                         fstp   DWORD PTR [esp]
0x581335 raw=0x180735  e8a6fcffff                     call   0x580fe0
0x58133a raw=0x18073a  d94508                         fld    DWORD PTR [ebp+0x8]
0x58133d raw=0x18073d  51                             push   ecx
0x58133e raw=0x18073e  8d4f20                         lea    ecx,[edi+0x20]
0x581341 raw=0x180741  d91c24                         fstp   DWORD PTR [esp]
0x581344 raw=0x180744  e817dafdff                     call   0x55ed60
0x581349 raw=0x180749  d94508                         fld    DWORD PTR [ebp+0x8]
0x58134c raw=0x18074c  51                             push   ecx
0x58134d raw=0x18074d  8d4f10                         lea    ecx,[edi+0x10]
0x581350 raw=0x180750  d91c24                         fstp   DWORD PTR [esp]
0x581353 raw=0x180753  e808dafdff                     call   0x55ed60
0x581358 raw=0x180758  d94508                         fld    DWORD PTR [ebp+0x8]
0x58135b raw=0x18075b  dc0d6857c500                   fmul   QWORD PTR ds:0xc55768
0x581361 raw=0x180761  51                             push   ecx
0x581362 raw=0x180762  8d4f30                         lea    ecx,[edi+0x30]
0x581365 raw=0x180765  d95c242c                       fstp   DWORD PTR [esp+0x2c]
0x581369 raw=0x180769  d944242c                       fld    DWORD PTR [esp+0x2c]
0x58136d raw=0x18076d  d91c24                         fstp   DWORD PTR [esp]
0x581370 raw=0x180770  e8ebd9fdff                     call   0x55ed60
0x581375 raw=0x180775  85c0                           test   eax,eax
0x581377 raw=0x180777  744a                           je     0x5813c3
0x581379 raw=0x180779  ff4740                         inc    DWORD PTR [edi+0x40]
0x58137c raw=0x18077c  8b4704                         mov    eax,DWORD PTR [edi+0x4]
0x58137f raw=0x18077f  8b7068                         mov    esi,DWORD PTR [eax+0x68]
0x581382 raw=0x180782  8b4e28                         mov    ecx,DWORD PTR [esi+0x28]
0x581385 raw=0x180785  2b4e24                         sub    ecx,DWORD PTR [esi+0x24]
0x581388 raw=0x180788  b893244992                     mov    eax,0x92492493
0x58138d raw=0x18078d  f7e9                           imul   ecx
0x58138f raw=0x18078f  03d1                           add    edx,ecx
0x581391 raw=0x180791  c1fa04                         sar    edx,0x4
0x581394 raw=0x180794  8bca                           mov    ecx,edx
0x581396 raw=0x180796  c1e91f                         shr    ecx,0x1f
0x581399 raw=0x180799  03ca                           add    ecx,edx
0x58139b raw=0x18079b  394f40                         cmp    DWORD PTR [edi+0x40],ecx
0x58139e raw=0x18079e  7623                           jbe    0x5813c3
0x5813a0 raw=0x1807a0  8b4e28                         mov    ecx,DWORD PTR [esi+0x28]
0x5813a3 raw=0x1807a3  2b4e24                         sub    ecx,DWORD PTR [esi+0x24]
0x5813a6 raw=0x1807a6  b893244992                     mov    eax,0x92492493
0x5813ab raw=0x1807ab  f7e9                           imul   ecx
0x5813ad raw=0x1807ad  03d1                           add    edx,ecx
0x5813af raw=0x1807af  c1fa04                         sar    edx,0x4
0x5813b2 raw=0x1807b2  8bc2                           mov    eax,edx
0x5813b4 raw=0x1807b4  c1e81f                         shr    eax,0x1f
0x5813b7 raw=0x1807b7  03c2                           add    eax,edx
0x5813b9 raw=0x1807b9  894740                         mov    DWORD PTR [edi+0x40],eax
0x5813bc raw=0x1807bc  c7474401000000                 mov    DWORD PTR [edi+0x44],0x1

; book_state2_done | state2+44 !=0 and FB72AC==0 predicate
; VA 0x581840..0x5818bf RAW 0x180c40 len 127 SHA256 cf3583a6c8905de9e44092bed5c2aa164e0923bdf7d0d368c053f4b8628dd901
0x581840 raw=0x180c40  55                             push   ebp
0x581841 raw=0x180c41  8bec                           mov    ebp,esp
0x581843 raw=0x180c43  6aff                           push   0xffffffff
0x581845 raw=0x180c45  688e8b9000                     push   0x908b8e
0x58184a raw=0x180c4a  64a100000000                   mov    eax,fs:0x0
0x581850 raw=0x180c50  50                             push   eax
0x581851 raw=0x180c51  a1201fd600                     mov    eax,ds:0xd61f20
0x581856 raw=0x180c56  33c5                           xor    eax,ebp
0x581858 raw=0x180c58  50                             push   eax
0x581859 raw=0x180c59  8d45f4                         lea    eax,[ebp-0xc]
0x58185c raw=0x180c5c  64a300000000                   mov    fs:0x0,eax
0x581862 raw=0x180c62  83794400                       cmp    DWORD PTR [ecx+0x44],0x0
0x581866 raw=0x180c66  7446                           je     0x5818ae
0x581868 raw=0x180c68  f605a472fb0001                 test   BYTE PTR ds:0xfb72a4,0x1
0x58186f raw=0x180c6f  7520                           jne    0x581891
0x581871 raw=0x180c71  830da472fb0001                 or     DWORD PTR ds:0xfb72a4,0x1
0x581878 raw=0x180c78  c745fc00000000                 mov    DWORD PTR [ebp-0x4],0x0
0x58187f raw=0x180c7f  e8ccdff1ff                     call   0x49f850
0x581884 raw=0x180c84  68e0cfbc00                     push   0xbccfe0
0x581889 raw=0x180c89  e88c0a3100                     call   0x89231a
0x58188e raw=0x180c8e  83c404                         add    esp,0x4
0x581891 raw=0x180c91  833dac72fb0000                 cmp    DWORD PTR ds:0xfb72ac,0x0
0x581898 raw=0x180c98  7514                           jne    0x5818ae
0x58189a raw=0x180c9a  b801000000                     mov    eax,0x1
0x58189f raw=0x180c9f  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x5818a2 raw=0x180ca2  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x5818a9 raw=0x180ca9  59                             pop    ecx
0x5818aa raw=0x180caa  8be5                           mov    esp,ebp
0x5818ac raw=0x180cac  5d                             pop    ebp
0x5818ad raw=0x180cad  c3                             ret
0x5818ae raw=0x180cae  33c0                           xor    eax,eax
0x5818b0 raw=0x180cb0  8b4df4                         mov    ecx,DWORD PTR [ebp-0xc]
0x5818b3 raw=0x180cb3  64890d00000000                 mov    DWORD PTR fs:0x0,ecx
0x5818ba raw=0x180cba  59                             pop    ecx
0x5818bb raw=0x180cbb  8be5                           mov    esp,ebp
0x5818bd raw=0x180cbd  5d                             pop    ebp
0x5818be raw=0x180cbe  c3                             ret

; book_state34_tick_prefix | shared580FE0 invoked by CBookState3/4 tick before rendering
; VA 0x5818c0..0x5818fa RAW 0x180cc0 len 58 SHA256 f18ec42d027c5b0dc31ef6692ecfc5e002278f3d0994cdab449da05d48629d17
0x5818c0 raw=0x180cc0  55                             push   ebp
0x5818c1 raw=0x180cc1  8bec                           mov    ebp,esp
0x5818c3 raw=0x180cc3  83e4f8                         and    esp,0xfffffff8
0x5818c6 raw=0x180cc6  6aff                           push   0xffffffff
0x5818c8 raw=0x180cc8  68ea379300                     push   0x9337ea
0x5818cd raw=0x180ccd  64a100000000                   mov    eax,fs:0x0
0x5818d3 raw=0x180cd3  50                             push   eax
0x5818d4 raw=0x180cd4  83ec18                         sub    esp,0x18
0x5818d7 raw=0x180cd7  53                             push   ebx
0x5818d8 raw=0x180cd8  56                             push   esi
0x5818d9 raw=0x180cd9  57                             push   edi
0x5818da raw=0x180cda  a1201fd600                     mov    eax,ds:0xd61f20
0x5818df raw=0x180cdf  33c4                           xor    eax,esp
0x5818e1 raw=0x180ce1  50                             push   eax
0x5818e2 raw=0x180ce2  8d442428                       lea    eax,[esp+0x28]
0x5818e6 raw=0x180ce6  64a300000000                   mov    fs:0x0,eax
0x5818ec raw=0x180cec  8bf9                           mov    edi,ecx
0x5818ee raw=0x180cee  d94508                         fld    DWORD PTR [ebp+0x8]
0x5818f1 raw=0x180cf1  51                             push   ecx
0x5818f2 raw=0x180cf2  d91c24                         fstp   DWORD PTR [esp]
0x5818f5 raw=0x180cf5  e8e6f6ffff                     call   0x580fe0

; book_frame_caller | bounded frame branch initializes owner and calls57FA40(FC1BF8,delta)
; VA 0x4927e8..0x492827 RAW 0x91be8 len 63 SHA256 9a59ab0699b3be52084f2ba5df664221c81d019e97c42066ac82a552b544b308
0x4927e8 raw=0x91be8  f605f41bfc0001                 test   BYTE PTR ds:0xfc1bf4,0x1
0x4927ef raw=0x91bef  7525                           jne    0x492816
0x4927f1 raw=0x91bf1  830df41bfc0001                 or     DWORD PTR ds:0xfc1bf4,0x1
0x4927f8 raw=0x91bf8  c744243813000000               mov    DWORD PTR [esp+0x38],0x13
0x492800 raw=0x91c00  e88bc70e00                     call   0x57ef90
0x492805 raw=0x91c05  68b0dfbc00                     push   0xbcdfb0
0x49280a raw=0x91c0a  e80bfb3f00                     call   0x89231a
0x49280f raw=0x91c0f  83c404                         add    esp,0x4
0x492812 raw=0x91c12  895c2438                       mov    DWORD PTR [esp+0x38],ebx
0x492816 raw=0x91c16  d9450c                         fld    DWORD PTR [ebp+0xc]
0x492819 raw=0x91c19  51                             push   ecx
0x49281a raw=0x91c1a  d91c24                         fstp   DWORD PTR [esp]
0x49281d raw=0x91c1d  68f81bfc00                     push   0xfc1bf8
0x492822 raw=0x91c22  e819d20e00                     call   0x57fa40

; presentation_interpolator | bounded numeric interpolation: endpoint returns1; optional repeat resets initial
; VA 0x55ed60..0x55ee19 RAW 0x15e160 len 185 SHA256 5c6b2c16f6cdff0c0cc3a6403d3403c1a125885c52abc3c2bdfbcc33fe2a650d
0x55ed60 raw=0x15e160  55                             push   ebp
0x55ed61 raw=0x15e161  8bec                           mov    ebp,esp
0x55ed63 raw=0x15e163  83ec08                         sub    esp,0x8
0x55ed66 raw=0x15e166  d94104                         fld    DWORD PTR [ecx+0x4]
0x55ed69 raw=0x15e169  f30f104508                     movss  xmm0,DWORD PTR [ebp+0x8]
0x55ed6e raw=0x15e16e  d95df8                         fstp   DWORD PTR [ebp-0x8]
0x55ed71 raw=0x15e171  33d2                           xor    edx,edx
0x55ed73 raw=0x15e173  d901                           fld    DWORD PTR [ecx]
0x55ed75 raw=0x15e175  d95dfc                         fstp   DWORD PTR [ebp-0x4]
0x55ed78 raw=0x15e178  d945f8                         fld    DWORD PTR [ebp-0x8]
0x55ed7b raw=0x15e17b  d9c0                           fld    st(0)
0x55ed7d raw=0x15e17d  d865fc                         fsub   DWORD PTR [ebp-0x4]
0x55ed80 raw=0x15e180  d9ee                           fldz
0x55ed82 raw=0x15e182  dff1                           fcomip st,st(1)
0x55ed84 raw=0x15e184  ddd8                           fstp   st(0)
0x55ed86 raw=0x15e186  7646                           jbe    0x55edce
0x55ed88 raw=0x15e188  0f2f056c56c500                 comiss xmm0,DWORD PTR ds:0xc5566c
0x55ed8f raw=0x15e18f  760c                           jbe    0x55ed9d
0x55ed91 raw=0x15e191  0f5705b057c500                 xorps  xmm0,XMMWORD PTR ds:0xc557b0
0x55ed98 raw=0x15e198  f30f114508                     movss  DWORD PTR [ebp+0x8],xmm0
0x55ed9d raw=0x15e19d  d94108                         fld    DWORD PTR [ecx+0x8]
0x55eda0 raw=0x15e1a0  d84508                         fadd   DWORD PTR [ebp+0x8]
0x55eda3 raw=0x15e1a3  d95d08                         fstp   DWORD PTR [ebp+0x8]
0x55eda6 raw=0x15e1a6  d94508                         fld    DWORD PTR [ebp+0x8]
0x55eda9 raw=0x15e1a9  d95108                         fst    DWORD PTR [ecx+0x8]
0x55edac raw=0x15e1ac  d9c9                           fxch   st(1)
0x55edae raw=0x15e1ae  dff1                           fcomip st,st(1)
0x55edb0 raw=0x15e1b0  ddd8                           fstp   st(0)
0x55edb2 raw=0x15e1b2  725d                           jb     0x55ee11
0x55edb4 raw=0x15e1b4  b801000000                     mov    eax,0x1
0x55edb9 raw=0x15e1b9  39510c                         cmp    DWORD PTR [ecx+0xc],edx
0x55edbc raw=0x15e1bc  7543                           jne    0x55ee01
0x55edbe raw=0x15e1be  f30f1045f8                     movss  xmm0,DWORD PTR [ebp-0x8]
0x55edc3 raw=0x15e1c3  f30f114108                     movss  DWORD PTR [ecx+0x8],xmm0
0x55edc8 raw=0x15e1c8  8be5                           mov    esp,ebp
0x55edca raw=0x15e1ca  5d                             pop    ebp
0x55edcb raw=0x15e1cb  c20400                         ret    0x4
0x55edce raw=0x15e1ce  0f57c9                         xorps  xmm1,xmm1
0x55edd1 raw=0x15e1d1  0f2fc8                         comiss xmm1,xmm0
0x55edd4 raw=0x15e1d4  760c                           jbe    0x55ede2
0x55edd6 raw=0x15e1d6  0f5705b057c500                 xorps  xmm0,XMMWORD PTR ds:0xc557b0
0x55eddd raw=0x15e1dd  f30f114508                     movss  DWORD PTR [ebp+0x8],xmm0
0x55ede2 raw=0x15e1e2  d94108                         fld    DWORD PTR [ecx+0x8]
0x55ede5 raw=0x15e1e5  d84508                         fadd   DWORD PTR [ebp+0x8]
0x55ede8 raw=0x15e1e8  d95d08                         fstp   DWORD PTR [ebp+0x8]
0x55edeb raw=0x15e1eb  d94508                         fld    DWORD PTR [ebp+0x8]
0x55edee raw=0x15e1ee  d95108                         fst    DWORD PTR [ecx+0x8]
0x55edf1 raw=0x15e1f1  dff1                           fcomip st,st(1)
0x55edf3 raw=0x15e1f3  ddd8                           fstp   st(0)
0x55edf5 raw=0x15e1f5  721a                           jb     0x55ee11
0x55edf7 raw=0x15e1f7  b801000000                     mov    eax,0x1
0x55edfc raw=0x15e1fc  39510c                         cmp    DWORD PTR [ecx+0xc],edx
0x55edff raw=0x15e1ff  74bd                           je     0x55edbe
0x55ee01 raw=0x15e201  f30f1045fc                     movss  xmm0,DWORD PTR [ebp-0x4]
0x55ee06 raw=0x15e206  f30f114108                     movss  DWORD PTR [ecx+0x8],xmm0
0x55ee0b raw=0x15e20b  8be5                           mov    esp,ebp
0x55ee0d raw=0x15e20d  5d                             pop    ebp
0x55ee0e raw=0x15e20e  c20400                         ret    0x4
0x55ee11 raw=0x15e211  8bc2                           mov    eax,edx
0x55ee13 raw=0x15e213  8be5                           mov    esp,ebp
0x55ee15 raw=0x15e215  5d                             pop    ebp
0x55ee16 raw=0x15e216  c20400                         ret    0x4

; binding_q_flyingobject | selected new Q.FlyingObject normal native-slot/name/closure
; VA 0x567820..0x5678b9 RAW 0x166c20 len 153 SHA256 c1ea0c89deb41929b3dc103a0a5fade4cada8ba010348f55720a776eff3e6e08
0x567820 raw=0x166c20  55                             push   ebp
0x567821 raw=0x166c21  8bec                           mov    ebp,esp
0x567823 raw=0x166c23  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x567826 raw=0x166c26  53                             push   ebx
0x567827 raw=0x166c27  8b1d7427fe00                   mov    ebx,DWORD PTR ds:0xfe2774
0x56782d raw=0x166c2d  56                             push   esi
0x56782e raw=0x166c2e  8b33                           mov    esi,DWORD PTR [ebx]
0x567830 raw=0x166c30  57                             push   edi
0x567831 raw=0x166c31  8b38                           mov    edi,DWORD PTR [eax]
0x567833 raw=0x166c33  b8eed8ffff                     mov    eax,0xffffd8ee
0x567838 raw=0x166c38  c7051c28fe0040495600           mov    DWORD PTR ds:0xfe281c,0x564940
0x567842 raw=0x166c42  e839de1800                     call   0x6f5680
0x567847 raw=0x166c47  8b03                           mov    eax,DWORD PTR [ebx]
0x567849 raw=0x166c49  8b4008                         mov    eax,DWORD PTR [eax+0x8]
0x56784c raw=0x166c4c  83e810                         sub    eax,0x10
0x56784f raw=0x166c4f  3dc8bfc000                     cmp    eax,0xc0bfc8
0x567854 raw=0x166c54  7406                           je     0x56785c
0x567856 raw=0x166c56  83780805                       cmp    DWORD PTR [eax+0x8],0x5
0x56785a raw=0x166c5a  7414                           je     0x567870
0x56785c raw=0x166c5c  57                             push   edi
0x56785d raw=0x166c5d  68c426c400                     push   0xc426c4
0x567862 raw=0x166c62  e856b83200                     call   0x8930bd
0x567867 raw=0x166c67  8b1b                           mov    ebx,DWORD PTR [ebx]
0x567869 raw=0x166c69  83c408                         add    esp,0x8
0x56786c raw=0x166c6c  834308f0                       add    DWORD PTR [ebx+0x8],0xfffffff0
0x567870 raw=0x166c70  8b3d7427fe00                   mov    edi,DWORD PTR ds:0xfe2774
0x567876 raw=0x166c76  8b37                           mov    esi,DWORD PTR [edi]
0x567878 raw=0x166c78  6890a4d600                     push   0xd6a490
0x56787d raw=0x166c7d  e88edc1800                     call   0x6f5510
0x567882 raw=0x166c82  8b37                           mov    esi,DWORD PTR [edi]
0x567884 raw=0x166c84  83c404                         add    esp,0x4
0x567887 raw=0x166c87  6a00                           push   0x0
0x567889 raw=0x166c89  6850995600                     push   0x569950
0x56788e raw=0x166c8e  e81ddd1800                     call   0x6f55b0
0x567893 raw=0x166c93  8b0f                           mov    ecx,DWORD PTR [edi]
0x567895 raw=0x166c95  51                             push   ecx
0x567896 raw=0x166c96  b8fdffffff                     mov    eax,0xfffffffd
0x56789b raw=0x166c9b  e850df1800                     call   0x6f57f0
0x5678a0 raw=0x166ca0  8b157427fe00                   mov    edx,DWORD PTR ds:0xfe2774
0x5678a6 raw=0x166ca6  8b02                           mov    eax,DWORD PTR [edx]
0x5678a8 raw=0x166ca8  83c40c                         add    esp,0xc
0x5678ab raw=0x166cab  834008f0                       add    DWORD PTR [eax+0x8],0xfffffff0
0x5678af raw=0x166caf  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x5678b2 raw=0x166cb2  5f                             pop    edi
0x5678b3 raw=0x166cb3  5e                             pop    esi
0x5678b4 raw=0x166cb4  5b                             pop    ebx
0x5678b5 raw=0x166cb5  5d                             pop    ebp
0x5678b6 raw=0x166cb6  c20400                         ret    0x4

; name_q_flyingobject | Q.FlyingObject original NUL name
; VA 0xd6a490..0xd6a49d RAW 0x967c90 len 13 SHA256 a062a8c92cf57256d76c40487c4a752ea953ce1429f389e01d95af2dbc687d63
; DATA 466c79696e674f626a65637400

; binding_q_delflyingobject | selected new Q.DelFlyingObject normal native-slot/name/closure
; VA 0x5678c0..0x567959 RAW 0x166cc0 len 153 SHA256 2e6da656786e959d760ef0c3ed6f0e5fe1a1e22c1b64be6002b12e2097daede7
0x5678c0 raw=0x166cc0  55                             push   ebp
0x5678c1 raw=0x166cc1  8bec                           mov    ebp,esp
0x5678c3 raw=0x166cc3  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x5678c6 raw=0x166cc6  53                             push   ebx
0x5678c7 raw=0x166cc7  8b1d7427fe00                   mov    ebx,DWORD PTR ds:0xfe2774
0x5678cd raw=0x166ccd  56                             push   esi
0x5678ce raw=0x166cce  8b33                           mov    esi,DWORD PTR [ebx]
0x5678d0 raw=0x166cd0  57                             push   edi
0x5678d1 raw=0x166cd1  8b38                           mov    edi,DWORD PTR [eax]
0x5678d3 raw=0x166cd3  b8eed8ffff                     mov    eax,0xffffd8ee
0x5678d8 raw=0x166cd8  c7052028fe00604a5600           mov    DWORD PTR ds:0xfe2820,0x564a60
0x5678e2 raw=0x166ce2  e899dd1800                     call   0x6f5680
0x5678e7 raw=0x166ce7  8b03                           mov    eax,DWORD PTR [ebx]
0x5678e9 raw=0x166ce9  8b4008                         mov    eax,DWORD PTR [eax+0x8]
0x5678ec raw=0x166cec  83e810                         sub    eax,0x10
0x5678ef raw=0x166cef  3dc8bfc000                     cmp    eax,0xc0bfc8
0x5678f4 raw=0x166cf4  7406                           je     0x5678fc
0x5678f6 raw=0x166cf6  83780805                       cmp    DWORD PTR [eax+0x8],0x5
0x5678fa raw=0x166cfa  7414                           je     0x567910
0x5678fc raw=0x166cfc  57                             push   edi
0x5678fd raw=0x166cfd  68c426c400                     push   0xc426c4
0x567902 raw=0x166d02  e8b6b73200                     call   0x8930bd
0x567907 raw=0x166d07  8b1b                           mov    ebx,DWORD PTR [ebx]
0x567909 raw=0x166d09  83c408                         add    esp,0x8
0x56790c raw=0x166d0c  834308f0                       add    DWORD PTR [ebx+0x8],0xfffffff0
0x567910 raw=0x166d10  8b3d7427fe00                   mov    edi,DWORD PTR ds:0xfe2774
0x567916 raw=0x166d16  8b37                           mov    esi,DWORD PTR [edi]
0x567918 raw=0x166d18  68a0a4d600                     push   0xd6a4a0
0x56791d raw=0x166d1d  e8eedb1800                     call   0x6f5510
0x567922 raw=0x166d22  8b37                           mov    esi,DWORD PTR [edi]
0x567924 raw=0x166d24  83c404                         add    esp,0x4
0x567927 raw=0x166d27  6a00                           push   0x0
0x567929 raw=0x166d29  68b0995600                     push   0x5699b0
0x56792e raw=0x166d2e  e87ddc1800                     call   0x6f55b0
0x567933 raw=0x166d33  8b0f                           mov    ecx,DWORD PTR [edi]
0x567935 raw=0x166d35  51                             push   ecx
0x567936 raw=0x166d36  b8fdffffff                     mov    eax,0xfffffffd
0x56793b raw=0x166d3b  e8b0de1800                     call   0x6f57f0
0x567940 raw=0x166d40  8b157427fe00                   mov    edx,DWORD PTR ds:0xfe2774
0x567946 raw=0x166d46  8b02                           mov    eax,DWORD PTR [edx]
0x567948 raw=0x166d48  83c40c                         add    esp,0xc
0x56794b raw=0x166d4b  834008f0                       add    DWORD PTR [eax+0x8],0xfffffff0
0x56794f raw=0x166d4f  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x567952 raw=0x166d52  5f                             pop    edi
0x567953 raw=0x166d53  5e                             pop    esi
0x567954 raw=0x166d54  5b                             pop    ebx
0x567955 raw=0x166d55  5d                             pop    ebp
0x567956 raw=0x166d56  c20400                         ret    0x4

; name_q_delflyingobject | Q.DelFlyingObject original NUL name
; VA 0xd6a4a0..0xd6a4b0 RAW 0x967ca0 len 16 SHA256 db9543e6ec53ff2d5e1ecd178d58b1d4c16c66f62c8df3e9439f4d3c3a06c702
; DATA 44656c466c79696e674f626a65637400

; binding_q_prolog | selected new Q.Prolog normal native-slot/name/closure
; VA 0x567aa0..0x567b39 RAW 0x166ea0 len 153 SHA256 655be4f65609fa161dbb47ef62649e961b1a289e56c37fd7ee1aa45eef042b01
0x567aa0 raw=0x166ea0  55                             push   ebp
0x567aa1 raw=0x166ea1  8bec                           mov    ebp,esp
0x567aa3 raw=0x166ea3  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x567aa6 raw=0x166ea6  53                             push   ebx
0x567aa7 raw=0x166ea7  8b1d7427fe00                   mov    ebx,DWORD PTR ds:0xfe2774
0x567aad raw=0x166ead  56                             push   esi
0x567aae raw=0x166eae  8b33                           mov    esi,DWORD PTR [ebx]
0x567ab0 raw=0x166eb0  57                             push   edi
0x567ab1 raw=0x166eb1  8b38                           mov    edi,DWORD PTR [eax]
0x567ab3 raw=0x166eb3  b8eed8ffff                     mov    eax,0xffffd8ee
0x567ab8 raw=0x166eb8  c7052c28fe00a04b5600           mov    DWORD PTR ds:0xfe282c,0x564ba0
0x567ac2 raw=0x166ec2  e8b9db1800                     call   0x6f5680
0x567ac7 raw=0x166ec7  8b03                           mov    eax,DWORD PTR [ebx]
0x567ac9 raw=0x166ec9  8b4008                         mov    eax,DWORD PTR [eax+0x8]
0x567acc raw=0x166ecc  83e810                         sub    eax,0x10
0x567acf raw=0x166ecf  3dc8bfc000                     cmp    eax,0xc0bfc8
0x567ad4 raw=0x166ed4  7406                           je     0x567adc
0x567ad6 raw=0x166ed6  83780805                       cmp    DWORD PTR [eax+0x8],0x5
0x567ada raw=0x166eda  7414                           je     0x567af0
0x567adc raw=0x166edc  57                             push   edi
0x567add raw=0x166edd  68c426c400                     push   0xc426c4
0x567ae2 raw=0x166ee2  e8d6b53200                     call   0x8930bd
0x567ae7 raw=0x166ee7  8b1b                           mov    ebx,DWORD PTR [ebx]
0x567ae9 raw=0x166ee9  83c408                         add    esp,0x8
0x567aec raw=0x166eec  834308f0                       add    DWORD PTR [ebx+0x8],0xfffffff0
0x567af0 raw=0x166ef0  8b3d7427fe00                   mov    edi,DWORD PTR ds:0xfe2774
0x567af6 raw=0x166ef6  8b37                           mov    esi,DWORD PTR [edi]
0x567af8 raw=0x166ef8  68d0a4d600                     push   0xd6a4d0
0x567afd raw=0x166efd  e80eda1800                     call   0x6f5510
0x567b02 raw=0x166f02  8b37                           mov    esi,DWORD PTR [edi]
0x567b04 raw=0x166f04  83c404                         add    esp,0x4
0x567b07 raw=0x166f07  6a00                           push   0x0
0x567b09 raw=0x166f09  68d09a5600                     push   0x569ad0
0x567b0e raw=0x166f0e  e89dda1800                     call   0x6f55b0
0x567b13 raw=0x166f13  8b0f                           mov    ecx,DWORD PTR [edi]
0x567b15 raw=0x166f15  51                             push   ecx
0x567b16 raw=0x166f16  b8fdffffff                     mov    eax,0xfffffffd
0x567b1b raw=0x166f1b  e8d0dc1800                     call   0x6f57f0
0x567b20 raw=0x166f20  8b157427fe00                   mov    edx,DWORD PTR ds:0xfe2774
0x567b26 raw=0x166f26  8b02                           mov    eax,DWORD PTR [edx]
0x567b28 raw=0x166f28  83c40c                         add    esp,0xc
0x567b2b raw=0x166f2b  834008f0                       add    DWORD PTR [eax+0x8],0xfffffff0
0x567b2f raw=0x166f2f  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x567b32 raw=0x166f32  5f                             pop    edi
0x567b33 raw=0x166f33  5e                             pop    esi
0x567b34 raw=0x166f34  5b                             pop    ebx
0x567b35 raw=0x166f35  5d                             pop    ebp
0x567b36 raw=0x166f36  c20400                         ret    0x4

; name_q_prolog | Q.Prolog original NUL name
; VA 0xd6a4d0..0xd6a4d7 RAW 0x967cd0 len 7 SHA256 4453d6104bc22a39381f0f668b4d6909e0711c986f54ce13f5cea4a5f1bac28d
; DATA 50726f6c6f6700

; binding_q_isprologrunning | selected new Q.IsPrologRunning normal native-slot/name/closure
; VA 0x567b40..0x567bd9 RAW 0x166f40 len 153 SHA256 4032c33d34b36c0226f85e972d23c706dfe8e314f1d414fbae3d5c0b77cf3f67
0x567b40 raw=0x166f40  55                             push   ebp
0x567b41 raw=0x166f41  8bec                           mov    ebp,esp
0x567b43 raw=0x166f43  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x567b46 raw=0x166f46  53                             push   ebx
0x567b47 raw=0x166f47  8b1d7427fe00                   mov    ebx,DWORD PTR ds:0xfe2774
0x567b4d raw=0x166f4d  56                             push   esi
0x567b4e raw=0x166f4e  8b33                           mov    esi,DWORD PTR [ebx]
0x567b50 raw=0x166f50  57                             push   edi
0x567b51 raw=0x166f51  8b38                           mov    edi,DWORD PTR [eax]
0x567b53 raw=0x166f53  b8eed8ffff                     mov    eax,0xffffd8ee
0x567b58 raw=0x166f58  c7053028fe00504c5600           mov    DWORD PTR ds:0xfe2830,0x564c50
0x567b62 raw=0x166f62  e819db1800                     call   0x6f5680
0x567b67 raw=0x166f67  8b03                           mov    eax,DWORD PTR [ebx]
0x567b69 raw=0x166f69  8b4008                         mov    eax,DWORD PTR [eax+0x8]
0x567b6c raw=0x166f6c  83e810                         sub    eax,0x10
0x567b6f raw=0x166f6f  3dc8bfc000                     cmp    eax,0xc0bfc8
0x567b74 raw=0x166f74  7406                           je     0x567b7c
0x567b76 raw=0x166f76  83780805                       cmp    DWORD PTR [eax+0x8],0x5
0x567b7a raw=0x166f7a  7414                           je     0x567b90
0x567b7c raw=0x166f7c  57                             push   edi
0x567b7d raw=0x166f7d  68c426c400                     push   0xc426c4
0x567b82 raw=0x166f82  e836b53200                     call   0x8930bd
0x567b87 raw=0x166f87  8b1b                           mov    ebx,DWORD PTR [ebx]
0x567b89 raw=0x166f89  83c408                         add    esp,0x8
0x567b8c raw=0x166f8c  834308f0                       add    DWORD PTR [ebx+0x8],0xfffffff0
0x567b90 raw=0x166f90  8b3d7427fe00                   mov    edi,DWORD PTR ds:0xfe2774
0x567b96 raw=0x166f96  8b37                           mov    esi,DWORD PTR [edi]
0x567b98 raw=0x166f98  68d8a4d600                     push   0xd6a4d8
0x567b9d raw=0x166f9d  e86ed91800                     call   0x6f5510
0x567ba2 raw=0x166fa2  8b37                           mov    esi,DWORD PTR [edi]
0x567ba4 raw=0x166fa4  83c404                         add    esp,0x4
0x567ba7 raw=0x166fa7  6a00                           push   0x0
0x567ba9 raw=0x166fa9  68309b5600                     push   0x569b30
0x567bae raw=0x166fae  e8fdd91800                     call   0x6f55b0
0x567bb3 raw=0x166fb3  8b0f                           mov    ecx,DWORD PTR [edi]
0x567bb5 raw=0x166fb5  51                             push   ecx
0x567bb6 raw=0x166fb6  b8fdffffff                     mov    eax,0xfffffffd
0x567bbb raw=0x166fbb  e830dc1800                     call   0x6f57f0
0x567bc0 raw=0x166fc0  8b157427fe00                   mov    edx,DWORD PTR ds:0xfe2774
0x567bc6 raw=0x166fc6  8b02                           mov    eax,DWORD PTR [edx]
0x567bc8 raw=0x166fc8  83c40c                         add    esp,0xc
0x567bcb raw=0x166fcb  834008f0                       add    DWORD PTR [eax+0x8],0xfffffff0
0x567bcf raw=0x166fcf  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x567bd2 raw=0x166fd2  5f                             pop    edi
0x567bd3 raw=0x166fd3  5e                             pop    esi
0x567bd4 raw=0x166fd4  5b                             pop    ebx
0x567bd5 raw=0x166fd5  5d                             pop    ebp
0x567bd6 raw=0x166fd6  c20400                         ret    0x4

; name_q_isprologrunning | Q.IsPrologRunning original NUL name
; VA 0xd6a4d8..0xd6a4e8 RAW 0x967cd8 len 16 SHA256 f44fd248bb2cdcaf70483be548e5e12b4a75bcd96f5526986e3eb9a0609af41f
; DATA 497350726f6c6f6752756e6e696e6700

; binding_q_book | selected new Q.Book normal native-slot/name/closure
; VA 0x567f00..0x567f99 RAW 0x167300 len 153 SHA256 40096e2407c007fc9b4b1eb814e02d0887d80f2f46eab6913e5c8c2111919dc1
0x567f00 raw=0x167300  55                             push   ebp
0x567f01 raw=0x167301  8bec                           mov    ebp,esp
0x567f03 raw=0x167303  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x567f06 raw=0x167306  53                             push   ebx
0x567f07 raw=0x167307  8b1d7427fe00                   mov    ebx,DWORD PTR ds:0xfe2774
0x567f0d raw=0x16730d  56                             push   esi
0x567f0e raw=0x16730e  8b33                           mov    esi,DWORD PTR [ebx]
0x567f10 raw=0x167310  57                             push   edi
0x567f11 raw=0x167311  8b38                           mov    edi,DWORD PTR [eax]
0x567f13 raw=0x167313  b8eed8ffff                     mov    eax,0xffffd8ee
0x567f18 raw=0x167318  c7054828fe0040515600           mov    DWORD PTR ds:0xfe2848,0x565140
0x567f22 raw=0x167322  e859d71800                     call   0x6f5680
0x567f27 raw=0x167327  8b03                           mov    eax,DWORD PTR [ebx]
0x567f29 raw=0x167329  8b4008                         mov    eax,DWORD PTR [eax+0x8]
0x567f2c raw=0x16732c  83e810                         sub    eax,0x10
0x567f2f raw=0x16732f  3dc8bfc000                     cmp    eax,0xc0bfc8
0x567f34 raw=0x167334  7406                           je     0x567f3c
0x567f36 raw=0x167336  83780805                       cmp    DWORD PTR [eax+0x8],0x5
0x567f3a raw=0x16733a  7414                           je     0x567f50
0x567f3c raw=0x16733c  57                             push   edi
0x567f3d raw=0x16733d  68c426c400                     push   0xc426c4
0x567f42 raw=0x167342  e876b13200                     call   0x8930bd
0x567f47 raw=0x167347  8b1b                           mov    ebx,DWORD PTR [ebx]
0x567f49 raw=0x167349  83c408                         add    esp,0x8
0x567f4c raw=0x16734c  834308f0                       add    DWORD PTR [ebx+0x8],0xfffffff0
0x567f50 raw=0x167350  8b3d7427fe00                   mov    edi,DWORD PTR ds:0xfe2774
0x567f56 raw=0x167356  8b37                           mov    esi,DWORD PTR [edi]
0x567f58 raw=0x167358  6820a5d600                     push   0xd6a520
0x567f5d raw=0x16735d  e8aed51800                     call   0x6f5510
0x567f62 raw=0x167362  8b37                           mov    esi,DWORD PTR [edi]
0x567f64 raw=0x167364  83c404                         add    esp,0x4
0x567f67 raw=0x167367  6a00                           push   0x0
0x567f69 raw=0x167369  68909d5600                     push   0x569d90
0x567f6e raw=0x16736e  e83dd61800                     call   0x6f55b0
0x567f73 raw=0x167373  8b0f                           mov    ecx,DWORD PTR [edi]
0x567f75 raw=0x167375  51                             push   ecx
0x567f76 raw=0x167376  b8fdffffff                     mov    eax,0xfffffffd
0x567f7b raw=0x16737b  e870d81800                     call   0x6f57f0
0x567f80 raw=0x167380  8b157427fe00                   mov    edx,DWORD PTR ds:0xfe2774
0x567f86 raw=0x167386  8b02                           mov    eax,DWORD PTR [edx]
0x567f88 raw=0x167388  83c40c                         add    esp,0xc
0x567f8b raw=0x16738b  834008f0                       add    DWORD PTR [eax+0x8],0xfffffff0
0x567f8f raw=0x16738f  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x567f92 raw=0x167392  5f                             pop    edi
0x567f93 raw=0x167393  5e                             pop    esi
0x567f94 raw=0x167394  5b                             pop    ebx
0x567f95 raw=0x167395  5d                             pop    ebp
0x567f96 raw=0x167396  c20400                         ret    0x4

; name_q_book | Q.Book original NUL name
; VA 0xd6a520..0xd6a525 RAW 0x967d20 len 5 SHA256 055d215aa2e6988b4eca1ad70383f518cf04857ceedf237364c2862f7720a169
; DATA 426f6f6b00

; binding_q_isbookflying | selected new Q.IsBookFlying normal native-slot/name/closure
; VA 0x568040..0x5680d9 RAW 0x167440 len 153 SHA256 e2d1a5bd49341e77661bd0fbc31a3cc792e430b0ec7e73b74a85980bd6d45adb
0x568040 raw=0x167440  55                             push   ebp
0x568041 raw=0x167441  8bec                           mov    ebp,esp
0x568043 raw=0x167443  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x568046 raw=0x167446  53                             push   ebx
0x568047 raw=0x167447  8b1d7427fe00                   mov    ebx,DWORD PTR ds:0xfe2774
0x56804d raw=0x16744d  56                             push   esi
0x56804e raw=0x16744e  8b33                           mov    esi,DWORD PTR [ebx]
0x568050 raw=0x167450  57                             push   edi
0x568051 raw=0x167451  8b38                           mov    edi,DWORD PTR [eax]
0x568053 raw=0x167453  b8eed8ffff                     mov    eax,0xffffd8ee
0x568058 raw=0x167458  c7055028fe0070525600           mov    DWORD PTR ds:0xfe2850,0x565270
0x568062 raw=0x167462  e819d61800                     call   0x6f5680
0x568067 raw=0x167467  8b03                           mov    eax,DWORD PTR [ebx]
0x568069 raw=0x167469  8b4008                         mov    eax,DWORD PTR [eax+0x8]
0x56806c raw=0x16746c  83e810                         sub    eax,0x10
0x56806f raw=0x16746f  3dc8bfc000                     cmp    eax,0xc0bfc8
0x568074 raw=0x167474  7406                           je     0x56807c
0x568076 raw=0x167476  83780805                       cmp    DWORD PTR [eax+0x8],0x5
0x56807a raw=0x16747a  7414                           je     0x568090
0x56807c raw=0x16747c  57                             push   edi
0x56807d raw=0x16747d  68c426c400                     push   0xc426c4
0x568082 raw=0x167482  e836b03200                     call   0x8930bd
0x568087 raw=0x167487  8b1b                           mov    ebx,DWORD PTR [ebx]
0x568089 raw=0x167489  83c408                         add    esp,0x8
0x56808c raw=0x16748c  834308f0                       add    DWORD PTR [ebx+0x8],0xfffffff0
0x568090 raw=0x167490  8b3d7427fe00                   mov    edi,DWORD PTR ds:0xfe2774
0x568096 raw=0x167496  8b37                           mov    esi,DWORD PTR [edi]
0x568098 raw=0x167498  6834a5d600                     push   0xd6a534
0x56809d raw=0x16749d  e86ed41800                     call   0x6f5510
0x5680a2 raw=0x1674a2  8b37                           mov    esi,DWORD PTR [edi]
0x5680a4 raw=0x1674a4  83c404                         add    esp,0x4
0x5680a7 raw=0x1674a7  6a00                           push   0x0
0x5680a9 raw=0x1674a9  68509e5600                     push   0x569e50
0x5680ae raw=0x1674ae  e8fdd41800                     call   0x6f55b0
0x5680b3 raw=0x1674b3  8b0f                           mov    ecx,DWORD PTR [edi]
0x5680b5 raw=0x1674b5  51                             push   ecx
0x5680b6 raw=0x1674b6  b8fdffffff                     mov    eax,0xfffffffd
0x5680bb raw=0x1674bb  e830d71800                     call   0x6f57f0
0x5680c0 raw=0x1674c0  8b157427fe00                   mov    edx,DWORD PTR ds:0xfe2774
0x5680c6 raw=0x1674c6  8b02                           mov    eax,DWORD PTR [edx]
0x5680c8 raw=0x1674c8  83c40c                         add    esp,0xc
0x5680cb raw=0x1674cb  834008f0                       add    DWORD PTR [eax+0x8],0xfffffff0
0x5680cf raw=0x1674cf  8b4508                         mov    eax,DWORD PTR [ebp+0x8]
0x5680d2 raw=0x1674d2  5f                             pop    edi
0x5680d3 raw=0x1674d3  5e                             pop    esi
0x5680d4 raw=0x1674d4  5b                             pop    ebx
0x5680d5 raw=0x1674d5  5d                             pop    ebp
0x5680d6 raw=0x1674d6  c20400                         ret    0x4

; name_q_isbookflying | Q.IsBookFlying original NUL name
; VA 0xd6a534..0xd6a541 RAW 0x967d34 len 13 SHA256 678e974759e10d2261a312e07b90c0c67f67ffa309bceb820e9c159ba83de86c
; DATA 4973426f6f6b466c79696e6700

; name_prolog_onclose | Prolog.OnClose original NUL name
; VA 0xd6a5bc..0xd6a5c4 RAW 0x967dbc len 8 SHA256 468e54a424f39c3dbb6ee71f86dcc9a2fe3d1988b9d8268386867f7a5ddfad7e
; DATA 4f6e436c6f736500

; time_import_iat | original unbound IAT RVA to timeGetTime import-by-name
; VA 0xbd25a0..0xbd25a4 RAW 0x7d0ba0 len 4 SHA256 a97ae5afd67781c071a0dab4669c8269d43488c2ac730375a8dfea105f7b2b6d
; DATA 0cf09500

; time_import_name | original import hint and timeGetTime NUL name
; VA 0xd5f00c..0xd5f01a RAW 0x95d60c len 14 SHA256 203387b05a6ac87a9cd0920a98ca4e42c8f7d15cf8d23f29318377e1b014dd4c
; DATA 940074696d6547657454696d6500

; flying_fade_jump_table | five absolute branch targets; not executable instructions
; VA 0x553c50..0x553c64 RAW 0x153050 len 20 SHA256 a4ba52d496227af917ab23439429026f77168835b662a3464015bdc6d6e56693
; DATA 793b5500843b55009a3b5500e93b5500053c5500

; book_phase_jump_table | four absolute phase branch targets; not executable instructions
; VA 0x57fbe0..0x57fbf0 RAW 0x17efe0 len 16 SHA256 b501c3e32e012a691de38e4d10282773f4467be75869ffeff0e07a4a416f9ec5
; DATA e8fa570047fb570070fb5700d4fb5700

; type_CFlyingImage_col_pointer | RTTI COL pointer only
; VA 0xc10744..0xc10748 RAW 0x80ed44 len 4 SHA256 f9dfb5e84e72c540746d6dda2ae6f437c56b67a47c8381a84f0158c6169eb8b8
; DATA 00cfc600

; type_CFlyingImage_col | MSVC RTTI complete object locator
; VA 0xc6cf00..0xc6cf14 RAW 0x86b500 len 20 SHA256 c51db40a5daeb20f562f4fb9a48e0654279be3a8416dd80d0d7554ac276a74b6
; DATA 00000000000000000000000080f9f70014cfc600

; type_CFlyingImage_descriptor | RTTI type descriptor and original decorated name
; VA 0xf7f980..0xf7f99b RAW 0xb7d180 len 27 SHA256 d6b35b37e5ddf1cfb403a50da7e16c0e2b86a00be154bb1dfab29adfd3dda477
; DATA f435bd00000000002e3f415643466c79696e67496d616765404000

; type_CFlyingImage_slot_0x0 | selected proven virtual method slot
; VA 0xc10748..0xc1074c RAW 0x80ed48 len 4 SHA256 204611279d706027c10efb5facdae1258f6a6a7f9b2e49ec1c54c7305536bc1c
; DATA 403e5500

; type_CFlyingImage_slot_0x4 | selected proven virtual method slot
; VA 0xc1074c..0xc10750 RAW 0x80ed4c len 4 SHA256 83be4b093a4d4ccd8a8c9b2321ea6f08b86bafcff2a562a5d917e561aaaff886
; DATA 30005600

; type_CFlyingImage_slot_0x8 | selected proven virtual method slot
; VA 0xc10750..0xc10754 RAW 0x80ed50 len 4 SHA256 94f5777e0e8c6ed8fbc632e3305b1b17cc2ff45863cfd3dfc2f4b329f89b88c8
; DATA e03d5500

; type_CFlyingImage_slot_0xc | selected proven virtual method slot
; VA 0xc10754..0xc10758 RAW 0x80ed54 len 4 SHA256 e7988f478012a5edd1abb371ad38ebadbd164352f7bf93f43f5589f7e51094eb
; DATA 903f5500

; type_CFlyingImage_slot_0x10 | selected proven virtual method slot
; VA 0xc10758..0xc1075c RAW 0x80ed58 len 4 SHA256 62898eb279407a5124aad7863b9516ce50817341e087195ab68c087b822d6f4a
; DATA 003e5500

; type_CFlyingImage_slot_0x14 | selected proven virtual method slot
; VA 0xc1075c..0xc10760 RAW 0x80ed5c len 4 SHA256 b22d4bcd1d257a88f20ff62b5a0d90856cf7e8f0d512655b3578ab3e713387b0
; DATA 603b5500

; type_CFlyingImage_slot_0x18 | selected proven virtual method slot
; VA 0xc10760..0xc10764 RAW 0x80ed60 len 4 SHA256 a60cd3181e16770165112ba6f76eedc9033d93c8f4b5ef88fedeb98496220d3c
; DATA a03f5500

; type_CFlyingImage_slot_0x1c | selected proven virtual method slot
; VA 0xc10764..0xc10768 RAW 0x80ed64 len 4 SHA256 697e99004a3386d8f922b662454bff9958ddd65db2b4876cd43531e084326862
; DATA f0ff5500

; type_CFlyingImage_slot_0x20 | selected proven virtual method slot
; VA 0xc10768..0xc1076c RAW 0x80ed68 len 4 SHA256 37368b4afa19a730aa4a1488214131cec9d2fcc4220082fe2bcfd0fde26477f0
; DATA 703c5500

; type_CFlyingImage_slot_0x24 | selected proven virtual method slot
; VA 0xc1076c..0xc10770 RAW 0x80ed6c len 4 SHA256 af032a30dbbe1983faebf26bbc7669f1080c7716ea8f8c1b4d03d098833a5ab9
; DATA 10f08000

; type_CFlyingImage_slot_0x28 | selected proven virtual method slot
; VA 0xc10770..0xc10774 RAW 0x80ed70 len 4 SHA256 9413ce98d3360e7337dea3feacc8d863b9f1108f251b57d354939b60c0d6a1dc
; DATA 20f08000

; type_CPrologBookPanel_col_pointer | RTTI COL pointer only
; VA 0xc3f5f0..0xc3f5f4 RAW 0x83dbf0 len 4 SHA256 52f1af7de6a7ee5be25344e08faa167f0006cf8e43de72481fe1991bc54a604d
; DATA 30aec700

; type_CPrologBookPanel_col | MSVC RTTI complete object locator
; VA 0xc7ae30..0xc7ae44 RAW 0x879430 len 20 SHA256 789e3fac427eafd98c3f1364dd94166028ec85bcf092d1ae9b4b3b41ae493caa
; DATA 000000000000000000000000387ff80044aec700

; type_CPrologBookPanel_descriptor | RTTI type descriptor and original decorated name
; VA 0xf87f38..0xf87f5b RAW 0xb85738 len 35 SHA256 50c07b6d51ec574bd759fa5ec3d3db61e2db9336fbc9d4512fbe1b0d9bd5587a
; DATA f435bd00000000002e3f41564350726f6c6f67426f6f6b50616e656c40465549404000

; type_CPrologBookPanel_slot_0xd4 | selected proven virtual method slot
; VA 0xc3f6c8..0xc3f6cc RAW 0x83dcc8 len 4 SHA256 c0f259bedf4e77621e2ecf5cba58b5fcf203388192eeb91a5ba61c44be2b8e9f
; DATA b00c6c00

; type_CPrologBookPanel_slot_0xec | selected proven virtual method slot
; VA 0xc3f6e0..0xc3f6e4 RAW 0x83dce0 len 4 SHA256 48b29b277f9d6b5127910ecc7c4e3a7237cab4350f66dcc17cde060b9bb28166
; DATA a00d6c00

; type_CPrologBookPanel_slot_0x140 | selected proven virtual method slot
; VA 0xc3f734..0xc3f738 RAW 0x83dd34 len 4 SHA256 2d2359fbb689e57e4c9f7b57d565b8e4630c59458885128fb636a62d4290a599
; DATA d00c6c00

; type_CPrologBookPanel_slot_0x15c | selected proven virtual method slot
; VA 0xc3f750..0xc3f754 RAW 0x83dd50 len 4 SHA256 5e45f56da1534f46e2739e2ec15fa4e0d365522b7ccc2a63a7379b980d3ed5d8
; DATA 300e6c00

; type_CBookState1_col_pointer | RTTI COL pointer only
; VA 0xc11290..0xc11294 RAW 0x80f890 len 4 SHA256 6850433541217783d9dc15d7bea7c8010b15e74b93fd02290405426e1789d599
; DATA 08d5c600

; type_CBookState1_col | MSVC RTTI complete object locator
; VA 0xc6d508..0xc6d51c RAW 0x86bb08 len 20 SHA256 6e014837d8561d6ca9dde9eafd85678919a87ca25aa7b29ceb94433b97b4278f
; DATA 000000000000000000000000ecfbf7001cd5c600

; type_CBookState1_descriptor | RTTI type descriptor and original decorated name
; VA 0xf7fbec..0xf7fc0f RAW 0xb7d3ec len 35 SHA256 992fa15bd86ebefea0db4ba528ac2b25f6e5f2569b179f97246e08208eaac226
; DATA f435bd00000000002e3f415643426f6f6b5374617465314053796e6f70736973404000

; type_CBookState1_slot_0x0 | selected proven virtual method slot
; VA 0xc11294..0xc11298 RAW 0x80f894 len 4 SHA256 1dc04e9c4b50e0912a71be9e51c1f73b89496a0f18fbf187a02c565380453a64
; DATA 900f5800

; type_CBookState1_slot_0x4 | selected proven virtual method slot
; VA 0xc11298..0xc1129c RAW 0x80f898 len 4 SHA256 3eb86fce76d9d92c36d3ac14a1ec2ba8ea2db06b06d02f5b539923ee8abe2a51
; DATA 80105800

; type_CBookState1_slot_0x8 | selected proven virtual method slot
; VA 0xc1129c..0xc112a0 RAW 0x80f89c len 4 SHA256 79d754e25613706ecceaf9005b5ddd710ad5f34dc7991c75bf4cc90d908ba29d
; DATA b00f5800

; type_CBookState1_slot_0xc | selected proven virtual method slot
; VA 0xc112a0..0xc112a4 RAW 0x80f8a0 len 4 SHA256 41cfe1ea0bc0ad3d46d168a7d8e273f57bea62dbf1bda0a0c0c6dd32655a224e
; DATA 90105800

; type_CBookState2_col_pointer | RTTI COL pointer only
; VA 0xc112b0..0xc112b4 RAW 0x80f8b0 len 4 SHA256 e283f1f4a8cfa2efc95e1ac46a898da6e35901277c56c65041f4b45f208df9a1
; DATA bcd4c600

; type_CBookState2_col | MSVC RTTI complete object locator
; VA 0xc6d4bc..0xc6d4d0 RAW 0x86babc len 20 SHA256 ee97cfdf0e9f25dc0832e5e3bafc0b988b1edd71b54ad951afe8c98bf0223a24
; DATA 000000000000000000000000c8fbf700d0d4c600

; type_CBookState2_descriptor | RTTI type descriptor and original decorated name
; VA 0xf7fbc8..0xf7fbeb RAW 0xb7d3c8 len 35 SHA256 0eca03dc5b0c10bb15f7a8e72788d0ab43b5cd9d115b0e16ccaa7c9381b8c53f
; DATA f435bd00000000002e3f415643426f6f6b5374617465324053796e6f70736973404000

; type_CBookState2_slot_0x0 | selected proven virtual method slot
; VA 0xc112b4..0xc112b8 RAW 0x80f8b4 len 4 SHA256 e4959082b64ed69346a938dd0b86d05cfc3c7cb7d2bea220e057cb44dd85f6ce
; DATA 90115800

; type_CBookState2_slot_0x4 | selected proven virtual method slot
; VA 0xc112b8..0xc112bc RAW 0x80f8b8 len 4 SHA256 3eb86fce76d9d92c36d3ac14a1ec2ba8ea2db06b06d02f5b539923ee8abe2a51
; DATA 80105800

; type_CBookState2_slot_0x8 | selected proven virtual method slot
; VA 0xc112bc..0xc112c0 RAW 0x80f8bc len 4 SHA256 22020e109134b073e2c7e3ab6c56f89005f88f10c3566fb7c2f61d63d91307d7
; DATA 40185800

; type_CBookState2_slot_0xc | selected proven virtual method slot
; VA 0xc112c0..0xc112c4 RAW 0x80f8c0 len 4 SHA256 8abf4e0e932b120acf0fc65266b4c57b6b5a441f0692018f6e04467d9c9e2fb1
; DATA 00135800

; type_CBookState3_col_pointer | RTTI COL pointer only
; VA 0xc112d0..0xc112d4 RAW 0x80f8d0 len 4 SHA256 cb377cb7ca48ded3e07a06e5e7ce39e16811207d824beeb73c92b3ece8740cc8
; DATA 70d4c600

; type_CBookState3_col | MSVC RTTI complete object locator
; VA 0xc6d470..0xc6d484 RAW 0x86ba70 len 20 SHA256 ae57850a14f1292b1126e6fea31a13fdd7ab0f0ab2af5dfbe49748f25d6e4327
; DATA 000000000000000000000000a4fbf70084d4c600

; type_CBookState3_descriptor | RTTI type descriptor and original decorated name
; VA 0xf7fba4..0xf7fbc7 RAW 0xb7d3a4 len 35 SHA256 8bb4355d43c8e83a3289667f5685d47f6be287d3bb0d762d01103792888f21fd
; DATA f435bd00000000002e3f415643426f6f6b5374617465334053796e6f70736973404000

; type_CBookState3_slot_0x0 | selected proven virtual method slot
; VA 0xc112d4..0xc112d8 RAW 0x80f8d4 len 4 SHA256 1dc04e9c4b50e0912a71be9e51c1f73b89496a0f18fbf187a02c565380453a64
; DATA 900f5800

; type_CBookState3_slot_0x4 | selected proven virtual method slot
; VA 0xc112d8..0xc112dc RAW 0x80f8d8 len 4 SHA256 3eb86fce76d9d92c36d3ac14a1ec2ba8ea2db06b06d02f5b539923ee8abe2a51
; DATA 80105800

; type_CBookState3_slot_0x8 | selected proven virtual method slot
; VA 0xc112dc..0xc112e0 RAW 0x80f8dc len 4 SHA256 79d754e25613706ecceaf9005b5ddd710ad5f34dc7991c75bf4cc90d908ba29d
; DATA b00f5800

; type_CBookState3_slot_0xc | selected proven virtual method slot
; VA 0xc112e0..0xc112e4 RAW 0x80f8e0 len 4 SHA256 623244e5c16af926d813e22fca33af4526cdb22cf0a72fcefbf5e4166a5bf6b7
; DATA c0185800

; type_CBookState4_col_pointer | RTTI COL pointer only
; VA 0xc112f0..0xc112f4 RAW 0x80f8f0 len 4 SHA256 976ee4bf39b7c11f40a22c9c553ff67e0ea7a532793de9d67d0fee80558623ea
; DATA 24d4c600

; type_CBookState4_col | MSVC RTTI complete object locator
; VA 0xc6d424..0xc6d438 RAW 0x86ba24 len 20 SHA256 9dcccd3a86c49aa22fb21f5907c57054cc74a83ff09b82dc49d4756fccb2b714
; DATA 00000000000000000000000080fbf70038d4c600

; type_CBookState4_descriptor | RTTI type descriptor and original decorated name
; VA 0xf7fb80..0xf7fba3 RAW 0xb7d380 len 35 SHA256 090a83901078dc0f6a858bffe9e83a6157c037145a9ab0c6b1bc8440781df6da
; DATA f435bd00000000002e3f415643426f6f6b5374617465344053796e6f70736973404000

; type_CBookState4_slot_0x0 | selected proven virtual method slot
; VA 0xc112f4..0xc112f8 RAW 0x80f8f4 len 4 SHA256 1dc04e9c4b50e0912a71be9e51c1f73b89496a0f18fbf187a02c565380453a64
; DATA 900f5800

; type_CBookState4_slot_0x4 | selected proven virtual method slot
; VA 0xc112f8..0xc112fc RAW 0x80f8f8 len 4 SHA256 3eb86fce76d9d92c36d3ac14a1ec2ba8ea2db06b06d02f5b539923ee8abe2a51
; DATA 80105800

; type_CBookState4_slot_0x8 | selected proven virtual method slot
; VA 0xc112fc..0xc11300 RAW 0x80f8fc len 4 SHA256 79d754e25613706ecceaf9005b5ddd710ad5f34dc7991c75bf4cc90d908ba29d
; DATA b00f5800

; type_CBookState4_slot_0xc | selected proven virtual method slot
; VA 0xc11300..0xc11304 RAW 0x80f900 len 4 SHA256 623244e5c16af926d813e22fca33af4526cdb22cf0a72fcefbf5e4166a5bf6b7
; DATA c0185800

; constant_fade_alpha_max | native constant fade_alpha_max
; VA 0xc55688..0xc55690 RAW 0x853c88 len 8 SHA256 729bef532e854760af95391c84e7ba32d372f3384227e6d952a809b8b7f35eb5
; DATA 0000000000e06f40

; constant_book_model_time_scale | native constant book_model_time_scale
; VA 0xc557c8..0xc557d0 RAW 0x853dc8 len 8 SHA256 a6eb657cf3aab7d4083b6f0eca93d6e4726d1db995b090f29decf45f2376682d
; DATA 0000000000003e40

; constant_book_text_step_scale | native constant book_text_step_scale
; VA 0xc55768..0xc55770 RAW 0x853d68 len 8 SHA256 d23ed22dfc38d6df90dd24233e59ea26555d24f372e25b5513eabf0656b2880f
; DATA 0000000000007940

; constant_book_state2_from5 | native constant book_state2_from5
; VA 0xc558d0..0xc558d4 RAW 0x853ed0 len 4 SHA256 fca31f1667a6aa1bba12fca4e4ea1becd503379d80da3213af07f6cc5702828d
; DATA 0000a040

; constant_one | native constant one
; VA 0xc456c0..0xc456c4 RAW 0x843cc0 len 4 SHA256 e00e5eb9444182f352323374ef4e08ebcb784725fdd4fd612d7730540b3e0c8c
; DATA 0000803f

; constant_book_repeat_target768 | native constant book_repeat_target768
; VA 0xc0c7fc..0xc0c800 RAW 0x80adfc len 4 SHA256 21e6059a8ebb043aa83ae9ff02bb0c443c308f0a2e1cad857317ff2128e9d073
; DATA 00004044

; literal_prolog_namespace | Prolog original NUL literal
; VA 0xc0e294..0xc0e29b RAW 0x80c894 len 7 SHA256 4453d6104bc22a39381f0f668b4d6909e0711c986f54ce13f5cea4a5f1bac28d
; DATA 50726f6c6f6700

; literal_book_config_path | Table/Book.txt original NUL literal
; VA 0xc1132c..0xc1133b RAW 0x80f92c len 15 SHA256 247106f501c4a7c3667424624034ccc175dce621f3e7491b58900668c2b62477
; DATA 5461626c652f426f6f6b2e74787400

; literal_book_config_format | %f %f %f original NUL literal
; VA 0xc1133c..0xc11345 RAW 0x80f93c len 9 SHA256 9d9949291b3b8e3c232368c93b65e79990accb06a9529b2849f12be443b13192
; DATA 256620256620256600
