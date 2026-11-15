; common_primary_initialize VA 0x4add50..0x4ae380 raw 0xad150 SHA256 f9cee5546de393ee1584d8c621e067d56f218559a800556f9b1bdcacc1a6d0f7
0x4add50: 53                               push   ebx
0x4add51: 56                               push   esi
0x4add52: 8d5008                           lea    edx,[eax+0x8]
0x4add55: bed50b0000                       mov    esi,0xbd5
0x4add5a: b97523bf00                       mov    ecx,0xbf2375
0x4add5f: 90                               nop
0x4add60: c742fc407d4b00                   mov    DWORD PTR [edx-0x4],0x4b7d40
0x4add67: 890a                             mov    DWORD PTR [edx],ecx
0x4add69: 83c208                           add    edx,0x8
0x4add6c: 4e                               dec    esi
0x4add6d: 75f1                             jne    0x4add60
0x4add6f: ba80fb4a00                       mov    edx,0x4afb80
0x4add74: c74034307d4b00                   mov    DWORD PTR [eax+0x34],0x4b7d30
0x4add7b: 894838                           mov    DWORD PTR [eax+0x38],ecx
0x4add7e: c7403cd0e44a00                   mov    DWORD PTR [eax+0x3c],0x4ae4d0
0x4add85: 894840                           mov    DWORD PTR [eax+0x40],ecx
0x4add88: c780f4090000b0ed4a00             mov    DWORD PTR [eax+0x9f4],0x4aedb0
0x4add92: 8988f8090000                     mov    DWORD PTR [eax+0x9f8],ecx
0x4add98: c7404430f54a00                   mov    DWORD PTR [eax+0x44],0x4af530
0x4add9f: 894848                           mov    DWORD PTR [eax+0x48],ecx
0x4adda2: c7405420f94a00                   mov    DWORD PTR [eax+0x54],0x4af920
0x4adda9: 894858                           mov    DWORD PTR [eax+0x58],ecx
0x4addac: c74004f0fa4a00                   mov    DWORD PTR [eax+0x4],0x4afaf0
0x4addb3: 894808                           mov    DWORD PTR [eax+0x8],ecx
0x4addb6: 89500c                           mov    DWORD PTR [eax+0xc],edx
0x4addb9: 894810                           mov    DWORD PTR [eax+0x10],ecx
0x4addbc: c7405c60fe4a00                   mov    DWORD PTR [eax+0x5c],0x4afe60
0x4addc3: 894860                           mov    DWORD PTR [eax+0x60],ecx
0x4addc6: c7406430014b00                   mov    DWORD PTR [eax+0x64],0x4b0130
0x4addcd: 894868                           mov    DWORD PTR [eax+0x68],ecx
0x4addd0: c7406cc0014b00                   mov    DWORD PTR [eax+0x6c],0x4b01c0
0x4addd7: 894870                           mov    DWORD PTR [eax+0x70],ecx
0x4addda: c7807c050000d0034b00             mov    DWORD PTR [eax+0x57c],0x4b03d0
0x4adde4: 898880050000                     mov    DWORD PTR [eax+0x580],ecx
0x4addea: c74074406c4300                   mov    DWORD PTR [eax+0x74],0x436c40
0x4addf1: 894878                           mov    DWORD PTR [eax+0x78],ecx
0x4addf4: c780fc09000040194b00             mov    DWORD PTR [eax+0x9fc],0x4b1940
0x4addfe: 8988000a0000                     mov    DWORD PTR [eax+0xa00],ecx
0x4ade04: c7407cd0194b00                   mov    DWORD PTR [eax+0x7c],0x4b19d0
0x4ade0b: 898880000000                     mov    DWORD PTR [eax+0x80],ecx
0x4ade11: c78084000000301a4b00             mov    DWORD PTR [eax+0x84],0x4b1a30
0x4ade1b: 898888000000                     mov    DWORD PTR [eax+0x88],ecx
0x4ade21: c7808c000000701a4b00             mov    DWORD PTR [eax+0x8c],0x4b1a70
0x4ade2b: 898890000000                     mov    DWORD PTR [eax+0x90],ecx
0x4ade31: c7801c020000901a4b00             mov    DWORD PTR [eax+0x21c],0x4b1a90
0x4ade3b: 898820020000                     mov    DWORD PTR [eax+0x220],ecx
0x4ade41: c78094000000f0244b00             mov    DWORD PTR [eax+0x94],0x4b24f0
0x4ade4b: 898898000000                     mov    DWORD PTR [eax+0x98],ecx
0x4ade51: c780a400000030594c00             mov    DWORD PTR [eax+0xa4],0x4c5930
0x4ade5b: 8988a8000000                     mov    DWORD PTR [eax+0xa8],ecx
0x4ade61: c780ac00000020264b00             mov    DWORD PTR [eax+0xac],0x4b2620
0x4ade6b: 8988b0000000                     mov    DWORD PTR [eax+0xb0],ecx
0x4ade71: 8990b4000000                     mov    DWORD PTR [eax+0xb4],edx
0x4ade77: 8988b8000000                     mov    DWORD PTR [eax+0xb8],ecx
0x4ade7d: c780c400000030274b00             mov    DWORD PTR [eax+0xc4],0x4b2730
0x4ade87: 8988c8000000                     mov    DWORD PTR [eax+0xc8],ecx
0x4ade8d: c780d4000000d0284b00             mov    DWORD PTR [eax+0xd4],0x4b28d0
0x4ade97: 8988d8000000                     mov    DWORD PTR [eax+0xd8],ecx
0x4ade9d: c780dc00000080e34a00             mov    DWORD PTR [eax+0xdc],0x4ae380
0x4adea7: 8988e0000000                     mov    DWORD PTR [eax+0xe0],ecx
0x4adead: c7803c010000f02a4b00             mov    DWORD PTR [eax+0x13c],0x4b2af0
0x4adeb7: 898840010000                     mov    DWORD PTR [eax+0x140],ecx
0x4adebd: c78044020000e0324b00             mov    DWORD PTR [eax+0x244],0x4b32e0
0x4adec7: 898848020000                     mov    DWORD PTR [eax+0x248],ecx
0x4adecd: c7800c010000d02c4b00             mov    DWORD PTR [eax+0x10c],0x4b2cd0
0x4aded7: 898810010000                     mov    DWORD PTR [eax+0x110],ecx
0x4adedd: c7801401000040304b00             mov    DWORD PTR [eax+0x114],0x4b3040
0x4adee7: 898818010000                     mov    DWORD PTR [eax+0x118],ecx
0x4adeed: c7803401000060304b00             mov    DWORD PTR [eax+0x134],0x4b3060
0x4adef7: 898838010000                     mov    DWORD PTR [eax+0x138],ecx
0x4adefd: c780ec08000060304b00             mov    DWORD PTR [eax+0x8ec],0x4b3060
0x4adf07: 8988f0080000                     mov    DWORD PTR [eax+0x8f0],ecx
0x4adf0d: c78044010000d01b4b00             mov    DWORD PTR [eax+0x144],0x4b1bd0
0x4adf17: 898848010000                     mov    DWORD PTR [eax+0x148],ecx
0x4adf1d: c780a401000090304b00             mov    DWORD PTR [eax+0x1a4],0x4b3090
0x4adf27: 8988a8010000                     mov    DWORD PTR [eax+0x1a8],ecx
0x4adf2d: c780c4010000f01b4b00             mov    DWORD PTR [eax+0x1c4],0x4b1bf0
0x4adf37: 8988c8010000                     mov    DWORD PTR [eax+0x1c8],ecx
0x4adf3d: c7801402000090214b00             mov    DWORD PTR [eax+0x214],0x4b2190
0x4adf47: 898818020000                     mov    DWORD PTR [eax+0x218],ecx
0x4adf4d: c7800c02000010234b00             mov    DWORD PTR [eax+0x20c],0x4b2310
0x4adf57: 898810020000                     mov    DWORD PTR [eax+0x210],ecx
0x4adf5d: c780fc030000c0234b00             mov    DWORD PTR [eax+0x3fc],0x4b23c0
0x4adf67: 898800040000                     mov    DWORD PTR [eax+0x400],ecx
0x4adf6d: c7804c02000050334b00             mov    DWORD PTR [eax+0x24c],0x4b3350
0x4adf77: 898850020000                     mov    DWORD PTR [eax+0x250],ecx
0x4adf7d: c7805c020000f0344b00             mov    DWORD PTR [eax+0x25c],0x4b34f0
0x4adf87: 898860020000                     mov    DWORD PTR [eax+0x260],ecx
0x4adf8d: c7806c02000010354b00             mov    DWORD PTR [eax+0x26c],0x4b3510
0x4adf97: 898870020000                     mov    DWORD PTR [eax+0x270],ecx
0x4adf9d: c7807402000070354b00             mov    DWORD PTR [eax+0x274],0x4b3570
0x4adfa7: 898878020000                     mov    DWORD PTR [eax+0x278],ecx
0x4adfad: c7808402000000364b00             mov    DWORD PTR [eax+0x284],0x4b3600
0x4adfb7: 898888020000                     mov    DWORD PTR [eax+0x288],ecx
0x4adfbd: c7808c02000010374b00             mov    DWORD PTR [eax+0x28c],0x4b3710
0x4adfc7: 898890020000                     mov    DWORD PTR [eax+0x290],ecx
0x4adfcd: c780a4040000f0f14a00             mov    DWORD PTR [eax+0x4a4],0x4af1f0
0x4adfd7: 8988a8040000                     mov    DWORD PTR [eax+0x4a8],ecx
0x4adfdd: c780f4020000103c4b00             mov    DWORD PTR [eax+0x2f4],0x4b3c10
0x4adfe7: 8988f8020000                     mov    DWORD PTR [eax+0x2f8],ecx
0x4adfed: c780e4020000a03d4b00             mov    DWORD PTR [eax+0x2e4],0x4b3da0
0x4adff7: 8988e8020000                     mov    DWORD PTR [eax+0x2e8],ecx
0x4adffd: c7808401000060374b00             mov    DWORD PTR [eax+0x184],0x4b3760
0x4ae007: 898888010000                     mov    DWORD PTR [eax+0x188],ecx
0x4ae00d: c7801c030000e03e4b00             mov    DWORD PTR [eax+0x31c],0x4b3ee0
0x4ae017: 898820030000                     mov    DWORD PTR [eax+0x320],ecx
0x4ae01d: c7806403000050404b00             mov    DWORD PTR [eax+0x364],0x4b4050
0x4ae027: 898868030000                     mov    DWORD PTR [eax+0x368],ecx
0x4ae02d: c7806c030000e0404b00             mov    DWORD PTR [eax+0x36c],0x4b40e0
0x4ae037: 898870030000                     mov    DWORD PTR [eax+0x370],ecx
0x4ae03d: c780b403000080434b00             mov    DWORD PTR [eax+0x3b4],0x4b4380
0x4ae047: 8988b8030000                     mov    DWORD PTR [eax+0x3b8],ecx
0x4ae04d: c7809c03000000444b00             mov    DWORD PTR [eax+0x39c],0x4b4400
0x4ae057: 8988a0030000                     mov    DWORD PTR [eax+0x3a0],ecx
0x4ae05d: c780cc030000c0444b00             mov    DWORD PTR [eax+0x3cc],0x4b44c0
0x4ae067: 8988d0030000                     mov    DWORD PTR [eax+0x3d0],ecx
0x4ae06d: c78014040000e0444b00             mov    DWORD PTR [eax+0x414],0x4b44e0
0x4ae077: 898818040000                     mov    DWORD PTR [eax+0x418],ecx
0x4ae07d: c7808c040000b0454b00             mov    DWORD PTR [eax+0x48c],0x4b45b0
0x4ae087: 898890040000                     mov    DWORD PTR [eax+0x490],ecx
0x4ae08d: c780d4050000d0494b00             mov    DWORD PTR [eax+0x5d4],0x4b49d0
0x4ae097: 8988d8050000                     mov    DWORD PTR [eax+0x5d8],ecx
0x4ae09d: c780bc040000c04c4b00             mov    DWORD PTR [eax+0x4bc],0x4b4cc0
0x4ae0a7: 8988c0040000                     mov    DWORD PTR [eax+0x4c0],ecx
0x4ae0ad: c780ac040000b01a4b00             mov    DWORD PTR [eax+0x4ac],0x4b1ab0
0x4ae0b7: 8988b0040000                     mov    DWORD PTR [eax+0x4b0],ecx
0x4ae0bd: c780b4040000b01b4b00             mov    DWORD PTR [eax+0x4b4],0x4b1bb0
0x4ae0c7: 8988b8040000                     mov    DWORD PTR [eax+0x4b8],ecx
0x4ae0cd: c78024050000804d4b00             mov    DWORD PTR [eax+0x524],0x4b4d80
0x4ae0d7: 898828050000                     mov    DWORD PTR [eax+0x528],ecx
0x4ae0dd: c7802c050000f0534b00             mov    DWORD PTR [eax+0x52c],0x4b53f0
0x4ae0e7: 898830050000                     mov    DWORD PTR [eax+0x530],ecx
0x4ae0ed: c7806c070000105c4b00             mov    DWORD PTR [eax+0x76c],0x4b5c10
0x4ae0f7: 898870070000                     mov    DWORD PTR [eax+0x770],ecx
0x4ae0fd: c7808c080000c0444b00             mov    DWORD PTR [eax+0x88c],0x4b44c0
0x4ae107: 898890080000                     mov    DWORD PTR [eax+0x890],ecx
0x4ae10d: c7808c05000000594b00             mov    DWORD PTR [eax+0x58c],0x4b5900
0x4ae117: 898890050000                     mov    DWORD PTR [eax+0x590],ecx
0x4ae11d: c780b4050000d05d4b00             mov    DWORD PTR [eax+0x5b4],0x4b5dd0
0x4ae127: 8988b8050000                     mov    DWORD PTR [eax+0x5b8],ecx
0x4ae12d: c780bc050000505e4b00             mov    DWORD PTR [eax+0x5bc],0x4b5e50
0x4ae137: 8988c0050000                     mov    DWORD PTR [eax+0x5c0],ecx
0x4ae13d: c78054060000105f4b00             mov    DWORD PTR [eax+0x654],0x4b5f10
0x4ae147: 898858060000                     mov    DWORD PTR [eax+0x658],ecx
0x4ae14d: c7805c060000305f4b00             mov    DWORD PTR [eax+0x65c],0x4b5f30
0x4ae157: 898860060000                     mov    DWORD PTR [eax+0x660],ecx
0x4ae15d: c78044060000405f4b00             mov    DWORD PTR [eax+0x644],0x4b5f40
0x4ae167: 898848060000                     mov    DWORD PTR [eax+0x648],ecx
0x4ae16d: c78064060000605f4b00             mov    DWORD PTR [eax+0x664],0x4b5f60
0x4ae177: 898868060000                     mov    DWORD PTR [eax+0x668],ecx
0x4ae17d: c7804c060000805f4b00             mov    DWORD PTR [eax+0x64c],0x4b5f80
0x4ae187: 898850060000                     mov    DWORD PTR [eax+0x650],ecx
0x4ae18d: c7803c060000a05f4b00             mov    DWORD PTR [eax+0x63c],0x4b5fa0
0x4ae197: 898840060000                     mov    DWORD PTR [eax+0x640],ecx
0x4ae19d: c7806c060000d05f4b00             mov    DWORD PTR [eax+0x66c],0x4b5fd0
0x4ae1a7: 898870060000                     mov    DWORD PTR [eax+0x670],ecx
0x4ae1ad: c78074060000f05f4b00             mov    DWORD PTR [eax+0x674],0x4b5ff0
0x4ae1b7: 898878060000                     mov    DWORD PTR [eax+0x678],ecx
0x4ae1bd: c7807c06000010604b00             mov    DWORD PTR [eax+0x67c],0x4b6010
0x4ae1c7: 898880060000                     mov    DWORD PTR [eax+0x680],ecx
0x4ae1cd: c7808406000030604b00             mov    DWORD PTR [eax+0x684],0x4b6030
0x4ae1d7: 898888060000                     mov    DWORD PTR [eax+0x688],ecx
0x4ae1dd: c780c406000040604b00             mov    DWORD PTR [eax+0x6c4],0x4b6040
0x4ae1e7: 8988c8060000                     mov    DWORD PTR [eax+0x6c8],ecx
0x4ae1ed: c780dc06000050604b00             mov    DWORD PTR [eax+0x6dc],0x4b6050
0x4ae1f7: 8988e0060000                     mov    DWORD PTR [eax+0x6e0],ecx
0x4ae1fd: c7805c07000090614b00             mov    DWORD PTR [eax+0x75c],0x4b6190
0x4ae207: 898860070000                     mov    DWORD PTR [eax+0x760],ecx
0x4ae20d: c7806407000000624b00             mov    DWORD PTR [eax+0x764],0x4b6200
0x4ae217: 898868070000                     mov    DWORD PTR [eax+0x768],ecx
0x4ae21d: c7807407000090624b00             mov    DWORD PTR [eax+0x774],0x4b6290
0x4ae227: 898878070000                     mov    DWORD PTR [eax+0x778],ecx
0x4ae22d: c780ac080000e0634b00             mov    DWORD PTR [eax+0x8ac],0x4b63e0
0x4ae237: 8988b0080000                     mov    DWORD PTR [eax+0x8b0],ecx
0x4ae23d: c780b408000010664b00             mov    DWORD PTR [eax+0x8b4],0x4b6610
0x4ae247: 8988b8080000                     mov    DWORD PTR [eax+0x8b8],ecx
0x4ae24d: c780bc08000080654b00             mov    DWORD PTR [eax+0x8bc],0x4b6580
0x4ae257: 8988c0080000                     mov    DWORD PTR [eax+0x8c0],ecx
0x4ae25d: c780c4080000b0674b00             mov    DWORD PTR [eax+0x8c4],0x4b67b0
0x4ae267: 8988c8080000                     mov    DWORD PTR [eax+0x8c8],ecx
0x4ae26d: c780ac03000040684b00             mov    DWORD PTR [eax+0x3ac],0x4b6840
0x4ae277: 8988b0030000                     mov    DWORD PTR [eax+0x3b0],ecx
0x4ae27d: c780cc08000070524900             mov    DWORD PTR [eax+0x8cc],0x495270
0x4ae287: 8988d0080000                     mov    DWORD PTR [eax+0x8d0],ecx
0x4ae28d: c78054090000001a4b00             mov    DWORD PTR [eax+0x954],0x4b1a00
0x4ae297: 898858090000                     mov    DWORD PTR [eax+0x958],ecx
0x4ae29d: c780b4090000306a4b00             mov    DWORD PTR [eax+0x9b4],0x4b6a30
0x4ae2a7: 8988b8090000                     mov    DWORD PTR [eax+0x9b8],ecx
0x4ae2ad: c7802c0a0000b06a4b00             mov    DWORD PTR [eax+0xa2c],0x4b6ab0
0x4ae2b7: 8988300a0000                     mov    DWORD PTR [eax+0xa30],ecx
0x4ae2bd: c780e4040000906b4b00             mov    DWORD PTR [eax+0x4e4],0x4b6b90
0x4ae2c7: 8988e8040000                     mov    DWORD PTR [eax+0x4e8],ecx
0x4ae2cd: c7804c0a0000006d4b00             mov    DWORD PTR [eax+0xa4c],0x4b6d00
0x4ae2d7: 8988500a0000                     mov    DWORD PTR [eax+0xa50],ecx
0x4ae2dd: c780f404000000724b00             mov    DWORD PTR [eax+0x4f4],0x4b7200
0x4ae2e7: 8988f8040000                     mov    DWORD PTR [eax+0x4f8],ecx
0x4ae2ed: c7808c0a0000e0724b00             mov    DWORD PTR [eax+0xa8c],0x4b72e0
0x4ae2f7: 8988900a0000                     mov    DWORD PTR [eax+0xa90],ecx
0x4ae2fd: c780940a000040754b00             mov    DWORD PTR [eax+0xa94],0x4b7540
0x4ae307: 8988980a0000                     mov    DWORD PTR [eax+0xa98],ecx
0x4ae30d: c780a40a000020764b00             mov    DWORD PTR [eax+0xaa4],0x4b7620
0x4ae317: 8988a80a0000                     mov    DWORD PTR [eax+0xaa8],ecx
0x4ae31d: c780ac0a000090774b00             mov    DWORD PTR [eax+0xaac],0x4b7790
0x4ae327: 8988b00a0000                     mov    DWORD PTR [eax+0xab0],ecx
0x4ae32d: c780b40a0000a0784b00             mov    DWORD PTR [eax+0xab4],0x4b78a0
0x4ae337: 8988b80a0000                     mov    DWORD PTR [eax+0xab8],ecx
0x4ae33d: c7809c0a000050794b00             mov    DWORD PTR [eax+0xa9c],0x4b7950
0x4ae347: 8988a00a0000                     mov    DWORD PTR [eax+0xaa0],ecx
0x4ae34d: c780c40a0000a07b4b00             mov    DWORD PTR [eax+0xac4],0x4b7ba0
0x4ae357: 8988c80a0000                     mov    DWORD PTR [eax+0xac8],ecx
0x4ae35d: c7805c0a0000706f4b00             mov    DWORD PTR [eax+0xa5c],0x4b6f70
0x4ae367: 8988600a0000                     mov    DWORD PTR [eax+0xa60],ecx
0x4ae36d: 5e                               pop    esi
0x4ae36e: c7807c0a0000f06f4b00             mov    DWORD PTR [eax+0xa7c],0x4b6ff0
0x4ae378: 8988800a0000                     mov    DWORD PTR [eax+0xa80],ecx
0x4ae37e: 5b                               pop    ebx
0x4ae37f: c3                               ret

; mission_field_construct VA 0x4bc6a0..0x4bc6db raw 0xbbaa0 SHA256 ec1918b2c927f3630c004348f5a31849a315508fa4163d83059a31faa1b30ef5
0x4bc6a0: 56                               push   esi
0x4bc6a1: 8bf0                             mov    esi,eax
0x4bc6a3: e8a816ffff                       call   0x4add50
0x4bc6a8: f30f1005c056c500                 movss  xmm0,DWORD PTR ds:0xc556c0
0x4bc6b0: c7065c70c000                     mov    DWORD PTR [esi],0xc0705c
0x4bc6b6: c78654bd000000000000             mov    DWORD PTR [esi+0xbd54],0x0
0x4bc6c0: f30f118658bd0000                 movss  DWORD PTR [esi+0xbd58],xmm0
0x4bc6c8: c70574a6d6004653494d             mov    DWORD PTR ds:0xd6a674,0x4d495346
0x4bc6d2: e809000000                       call   0x4bc6e0
0x4bc6d7: 8bc6                             mov    eax,esi
0x4bc6d9: 5e                               pop    esi
0x4bc6da: c3                               ret

; mission_secondary_initialize VA 0x4bc6e0..0x4bc74c raw 0xbbae0 SHA256 f01978556271c26c11f2c6f51b8b1537c3e7da8fcd497046a935ebaa03ea47db
0x4bc6e0: 68a85e0000                       push   0x5ea8
0x4bc6e5: 8d86ac5e0000                     lea    eax,[esi+0x5eac]
0x4bc6eb: 6a00                             push   0x0
0x4bc6ed: 50                               push   eax
0x4bc6ee: e86d213e00                       call   0x89e860
0x4bc6f3: b87523bf00                       mov    eax,0xbf2375
0x4bc6f8: 83c40c                           add    esp,0xc
0x4bc6fb: c7864c5f000030594c00             mov    DWORD PTR [esi+0x5f4c],0x4c5930
0x4bc705: 8986505f0000                     mov    DWORD PTR [esi+0x5f50],eax
0x4bc70b: c7867460000030c94b00             mov    DWORD PTR [esi+0x6074],0x4bc930
0x4bc715: 898678600000                     mov    DWORD PTR [esi+0x6078],eax
0x4bc71b: c7867c600000a0584c00             mov    DWORD PTR [esi+0x607c],0x4c58a0
0x4bc725: 898680600000                     mov    DWORD PTR [esi+0x6080],eax
0x4bc72b: c7863460000090ca4b00             mov    DWORD PTR [esi+0x6034],0x4bca90
0x4bc735: 898638600000                     mov    DWORD PTR [esi+0x6038],eax
0x4bc73b: c7868460000090554c00             mov    DWORD PTR [esi+0x6084],0x4c5590
0x4bc745: 898688600000                     mov    DWORD PTR [esi+0x6088],eax
0x4bc74b: c3                               ret

; scenario_field_construct VA 0x4c46f0..0x4c4745 raw 0xc3af0 SHA256 4aa757af1b9bd22025f771de26027954c331490419556cbd697da66831bdf905
0x4c46f0: 8bc6                             mov    eax,esi
0x4c46f2: e85996feff                       call   0x4add50
0x4c46f7: 68a85e0000                       push   0x5ea8
0x4c46fc: 8d86ac5e0000                     lea    eax,[esi+0x5eac]
0x4c4702: 6a00                             push   0x0
0x4c4704: 50                               push   eax
0x4c4705: c706b473c000                     mov    DWORD PTR [esi],0xc073b4
0x4c470b: c70574a6d60046454353             mov    DWORD PTR ds:0xd6a674,0x53434546
0x4c4715: e846a13d00                       call   0x89e860
0x4c471a: b87523bf00                       mov    eax,0xbf2375
0x4c471f: 8986505f0000                     mov    DWORD PTR [esi+0x5f50],eax
0x4c4725: 8986205f0000                     mov    DWORD PTR [esi+0x5f20],eax
0x4c472b: 83c40c                           add    esp,0xc
0x4c472e: c7864c5f000030594c00             mov    DWORD PTR [esi+0x5f4c],0x4c5930
0x4c4738: c7861c5f0000406c4300             mov    DWORD PTR [esi+0x5f1c],0x436c40
0x4c4742: 8bc6                             mov    eax,esi
0x4c4744: c3                               ret

; tutorial_field_construct VA 0x4c4ac0..0x4c4b04 raw 0xc3ec0 SHA256 e1a0928c0da336ceabf02254b2e983b676a8c62e96d459a5b61624df9ea62935
0x4c4ac0: 8bc6                             mov    eax,esi
0x4c4ac2: e88992feff                       call   0x4add50
0x4c4ac7: 68a85e0000                       push   0x5ea8
0x4c4acc: 8d86ac5e0000                     lea    eax,[esi+0x5eac]
0x4c4ad2: 6a00                             push   0x0
0x4c4ad4: 50                               push   eax
0x4c4ad5: c706e873c000                     mov    DWORD PTR [esi],0xc073e8
0x4c4adb: c70574a6d6004f545554             mov    DWORD PTR ds:0xd6a674,0x5455544f
0x4c4ae5: e8769d3d00                       call   0x89e860
0x4c4aea: 83c40c                           add    esp,0xc
0x4c4aed: c7860c610000204f4c00             mov    DWORD PTR [esi+0x610c],0x4c4f20
0x4c4af7: c786106100007523bf00             mov    DWORD PTR [esi+0x6110],0xbf2375
0x4c4b01: 8bc6                             mov    eax,esi
0x4c4b03: c3                               ret

; field_secondary_dispatch VA 0x4c4670..0x4c46f0 raw 0xc3a70 SHA256 2deecc04ff570b803612ebcd2157d86b0659367b80cc081f6a10de1a9c8c5223
0x4c4670: 55                               push   ebp
0x4c4671: 8bec                             mov    ebp,esp
0x4c4673: 8b4510                           mov    eax,DWORD PTR [ebp+0x10]
0x4c4676: 53                               push   ebx
0x4c4677: 56                               push   esi
0x4c4678: 57                               push   edi
0x4c4679: 0fbff8                           movsx  edi,ax
0x4c467c: 8bf1                             mov    esi,ecx
0x4c467e: 8b9cfeac5e0000                   mov    ebx,DWORD PTR [esi+edi*8+0x5eac]
0x4c4685: 85db                             test   ebx,ebx
0x4c4687: 7517                             jne    0x4c46a0
0x4c4689: 8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x4c468c: 50                               push   eax
0x4c468d: 8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x4c4690: 50                               push   eax
0x4c4691: 51                               push   ecx
0x4c4692: 8bce                             mov    ecx,esi
0x4c4694: e897930300                       call   0x4fda30
0x4c4699: 5f                               pop    edi
0x4c469a: 5e                               pop    esi
0x4c469b: 5b                               pop    ebx
0x4c469c: 5d                               pop    ebp
0x4c469d: c20c00                           ret    0xc
0x4c46a0: 8b94feb05e0000                   mov    edx,DWORD PTR [esi+edi*8+0x5eb0]
0x4c46a7: 6a06                             push   0x6
0x4c46a9: 686c6cbf00                       push   0xbf6c6c
0x4c46ae: 52                               push   edx
0x4c46af: e80ae23c00                       call   0x8928be
0x4c46b4: 8b4510                           mov    eax,DWORD PTR [ebp+0x10]
0x4c46b7: 8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0x4c46ba: 8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0x4c46bd: 83c40c                           add    esp,0xc
0x4c46c0: 50                               push   eax
0x4c46c1: 51                               push   ecx
0x4c46c2: 52                               push   edx
0x4c46c3: 8bce                             mov    ecx,esi
0x4c46c5: ffd3                             call   ebx
0x4c46c7: 8bd8                             mov    ebx,eax
0x4c46c9: 81fb05400080                     cmp    ebx,0x80004005
0x4c46cf: 7516                             jne    0x4c46e7
0x4c46d1: 8b84feb05e0000                   mov    eax,DWORD PTR [esi+edi*8+0x5eb0]
0x4c46d8: 50                               push   eax
0x4c46d9: 57                               push   edi
0x4c46da: 68746cbf00                       push   0xbf6c74
0x4c46df: e87c942200                       call   0x6edb60
0x4c46e4: 83c40c                           add    esp,0xc
0x4c46e7: 5f                               pop    edi
0x4c46e8: 5e                               pop    esi
0x4c46e9: 8bc3                             mov    eax,ebx
0x4c46eb: 5b                               pop    ebx
0x4c46ec: 5d                               pop    ebp
0x4c46ed: c20c00                           ret    0xc

; primary_dispatch VA 0x4fda30..0x4fdab3 raw 0xfce30 SHA256 f972c684f3955a1d49c1e56eef445bb5f60fd3e4e16da15c654a51ef21054f88
0x4fda30: 55                               push   ebp
0x4fda31: 8bec                             mov    ebp,esp
0x4fda33: 51                               push   ecx
0x4fda34: 56                               push   esi
0x4fda35: 8bf1                             mov    esi,ecx
0x4fda37: 8b4d10                           mov    ecx,DWORD PTR [ebp+0x10]
0x4fda3a: 57                               push   edi
0x4fda3b: 0fbff9                           movsx  edi,cx
0x4fda3e: 8b44fe04                         mov    eax,DWORD PTR [esi+edi*8+0x4]
0x4fda42: 8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x4fda45: 85c0                             test   eax,eax
0x4fda47: 751a                             jne    0x4fda63
0x4fda49: 8b06                             mov    eax,DWORD PTR [esi]
0x4fda4b: 8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0x4fda4e: 8b400c                           mov    eax,DWORD PTR [eax+0xc]
0x4fda51: 51                               push   ecx
0x4fda52: 8b4d0c                           mov    ecx,DWORD PTR [ebp+0xc]
0x4fda55: 51                               push   ecx
0x4fda56: 52                               push   edx
0x4fda57: 8bce                             mov    ecx,esi
0x4fda59: ffd0                             call   eax
0x4fda5b: 5f                               pop    edi
0x4fda5c: 5e                               pop    esi
0x4fda5d: 8be5                             mov    esp,ebp
0x4fda5f: 5d                               pop    ebp
0x4fda60: c20c00                           ret    0xc
0x4fda63: 8b4cfe08                         mov    ecx,DWORD PTR [esi+edi*8+0x8]
0x4fda67: 53                               push   ebx
0x4fda68: 6a06                             push   0x6
0x4fda6a: 8d5cfe08                         lea    ebx,[esi+edi*8+0x8]
0x4fda6e: 686c6cbf00                       push   0xbf6c6c
0x4fda73: 51                               push   ecx
0x4fda74: e8454e3900                       call   0x8928be
0x4fda79: 8b5510                           mov    edx,DWORD PTR [ebp+0x10]
0x4fda7c: 8b450c                           mov    eax,DWORD PTR [ebp+0xc]
0x4fda7f: 8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x4fda82: 83c40c                           add    esp,0xc
0x4fda85: 52                               push   edx
0x4fda86: 50                               push   eax
0x4fda87: 51                               push   ecx
0x4fda88: 8bce                             mov    ecx,esi
0x4fda8a: ff55fc                           call   DWORD PTR [ebp-0x4]
0x4fda8d: 8bf0                             mov    esi,eax
0x4fda8f: 81fe05400080                     cmp    esi,0x80004005
0x4fda95: 7511                             jne    0x4fdaa8
0x4fda97: 8b13                             mov    edx,DWORD PTR [ebx]
0x4fda99: 52                               push   edx
0x4fda9a: 57                               push   edi
0x4fda9b: 68746cbf00                       push   0xbf6c74
0x4fdaa0: e8bb001f00                       call   0x6edb60
0x4fdaa5: 83c40c                           add    esp,0xc
0x4fdaa8: 5b                               pop    ebx
0x4fdaa9: 5f                               pop    edi
0x4fdaaa: 8bc6                             mov    eax,esi
0x4fdaac: 5e                               pop    esi
0x4fdaad: 8be5                             mov    esp,ebp
0x4fdaaf: 5d                               pop    ebp
0x4fdab0: c20c00                           ret    0xc

; primary_default_to_vc VA 0x4b7d40..0x4b7d45 raw 0xb7140 SHA256 36dd204b8c08514e55c5a4541c381d9c6c48ecda338001b0ac93e247ec819e94
0x4b7d40: 8b01                             mov    eax,DWORD PTR [ecx]
0x4b7d42: ff600c                           jmp    DWORD PTR [eax+0xc]

; invalid_message VA 0x4227f0..0x42280e raw 0x21bf0 SHA256 bcc9054501ad7f478f2195d2a6fc0f78fd559869a2743a70d8d6429b49ceec94
0x4227f0: 55                               push   ebp
0x4227f1: 8bec                             mov    ebp,esp
0x4227f3: 0fbf4510                         movsx  eax,WORD PTR [ebp+0x10]
0x4227f7: 50                               push   eax
0x4227f8: 68286dbf00                       push   0xbf6d28
0x4227fd: e85eb32c00                       call   0x6edb60
0x422802: 83c408                           add    esp,0x8
0x422805: b805400080                       mov    eax,0x80004005
0x42280a: 5d                               pop    ebp
0x42280b: c20c00                           ret    0xc

; scene_manager_initialize VA 0x4b7dc0..0x4b7ec0 raw 0xb71c0 SHA256 fa48613974a308ddf6c2eb90bea82195fc9d77023c4c918585f5e6dc6bcb7f32
0x4b7dc0: b8002dfd00                       mov    eax,0xfd2d00
0x4b7dc5: bac07e4b00                       mov    edx,0x4b7ec0
0x4b7dca: b97523bf00                       mov    ecx,0xbf2375
0x4b7dcf: 90                               nop
0x4b7dd0: 8950fc                           mov    DWORD PTR [eax-0x4],edx
0x4b7dd3: 8908                             mov    DWORD PTR [eax],ecx
0x4b7dd5: 83c008                           add    eax,0x8
0x4b7dd8: 3da88bfd00                       cmp    eax,0xfd8ba8
0x4b7ddd: 7cf1                             jl     0x4b7dd0
0x4b7ddf: c7050c2dfd00007f4b00             mov    DWORD PTR ds:0xfd2d0c,0x4b7f00
0x4b7de9: 890d102dfd00                     mov    DWORD PTR ds:0xfd2d10,ecx
0x4b7def: c7058c8bfd00c08d4b00             mov    DWORD PTR ds:0xfd8b8c,0x4b8dc0
0x4b7df9: 890d908bfd00                     mov    DWORD PTR ds:0xfd8b90,ecx
0x4b7dff: c705fc2ffd00508f4b00             mov    DWORD PTR ds:0xfd2ffc,0x4b8f50
0x4b7e09: 890d0030fd00                     mov    DWORD PTR ds:0xfd3000,ecx
0x4b7e0f: c7054430fd0090904b00             mov    DWORD PTR ds:0xfd3044,0x4b9090
0x4b7e19: 890d4830fd00                     mov    DWORD PTR ds:0xfd3048,ecx
0x4b7e1f: c7056c30fd0060924b00             mov    DWORD PTR ds:0xfd306c,0x4b9260
0x4b7e29: 890d7030fd00                     mov    DWORD PTR ds:0xfd3070,ecx
0x4b7e2f: c705c431fd0020934b00             mov    DWORD PTR ds:0xfd31c4,0x4b9320
0x4b7e39: 890dc831fd00                     mov    DWORD PTR ds:0xfd31c8,ecx
0x4b7e3f: c7052c32fd0010944b00             mov    DWORD PTR ds:0xfd322c,0x4b9410
0x4b7e49: 890d3032fd00                     mov    DWORD PTR ds:0xfd3230,ecx
0x4b7e4f: c7053c32fd0000954b00             mov    DWORD PTR ds:0xfd323c,0x4b9500
0x4b7e59: 890d4032fd00                     mov    DWORD PTR ds:0xfd3240,ecx
0x4b7e5f: c705d431fd00909b4b00             mov    DWORD PTR ds:0xfd31d4,0x4b9b90
0x4b7e69: 890dd831fd00                     mov    DWORD PTR ds:0xfd31d8,ecx
0x4b7e6f: c705e431fd00609c4b00             mov    DWORD PTR ds:0xfd31e4,0x4b9c60
0x4b7e79: 890de831fd00                     mov    DWORD PTR ds:0xfd31e8,ecx
0x4b7e7f: c705d434fd00309d4b00             mov    DWORD PTR ds:0xfd34d4,0x4b9d30
0x4b7e89: 890dd834fd00                     mov    DWORD PTR ds:0xfd34d8,ecx
0x4b7e8f: c705242dfd0030964b00             mov    DWORD PTR ds:0xfd2d24,0x4b9630
0x4b7e99: 890d282dfd00                     mov    DWORD PTR ds:0xfd2d28,ecx
0x4b7e9f: c7050c2efd0070974b00             mov    DWORD PTR ds:0xfd2e0c,0x4b9770
0x4b7ea9: 890d102efd00                     mov    DWORD PTR ds:0xfd2e10,ecx
0x4b7eaf: c705f42ffd00c0994b00             mov    DWORD PTR ds:0xfd2ff4,0x4b99c0
0x4b7eb9: 890df82ffd00                     mov    DWORD PTR ds:0xfd2ff8,ecx
0x4b7ebf: c3                               ret

; scene_manager_current_field VA 0x4b7ec0..0x4b7ef2 raw 0xb72c0 SHA256 feb3d2486a8d0c83cbd7c53b7334ba0935c6a4e1c650c605030b7458927e9ec0
0x4b7ec0: 55                               push   ebp
0x4b7ec1: 8bec                             mov    ebp,esp
0x4b7ec3: 83b9ac5e000000                   cmp    DWORD PTR [ecx+0x5eac],0x0
0x4b7eca: 740e                             je     0x4b7eda
0x4b7ecc: 8b89ac5e0000                     mov    ecx,DWORD PTR [ecx+0x5eac]
0x4b7ed2: 8b01                             mov    eax,DWORD PTR [ecx]
0x4b7ed4: 8b4004                           mov    eax,DWORD PTR [eax+0x4]
0x4b7ed7: 5d                               pop    ebp
0x4b7ed8: ffe0                             jmp    eax
0x4b7eda: 0fbf4d10                         movsx  ecx,WORD PTR [ebp+0x10]
0x4b7ede: 51                               push   ecx
0x4b7edf: 68f86dc000                       push   0xc06df8
0x4b7ee4: e8775c2300                       call   0x6edb60
0x4b7ee9: 83c408                           add    esp,0x8
0x4b7eec: 33c0                             xor    eax,eax
0x4b7eee: 5d                               pop    ebp
0x4b7eef: c20c00                           ret    0xc

; scenario_end_writer VA 0x4c4f20..0x4c4fa2 raw 0xc4320 SHA256 931f7d521dee63a85e3ee39ba19b1ca63feebd738cb4c05f916e3a9eba220c20
0x4c4f20: 55                               push   ebp
0x4c4f21: 8bec                             mov    ebp,esp
0x4c4f23: 6aff                             push   0xffffffff
0x4c4f25: 689e769200                       push   0x92769e
0x4c4f2a: 64a100000000                     mov    eax,fs:0x0
0x4c4f30: 50                               push   eax
0x4c4f31: a1201fd600                       mov    eax,ds:0xd61f20
0x4c4f36: 33c5                             xor    eax,ebp
0x4c4f38: 50                               push   eax
0x4c4f39: 8d45f4                           lea    eax,[ebp-0xc]
0x4c4f3c: 64a300000000                     mov    fs:0x0,eax
0x4c4f42: f605800ffc0001                   test   BYTE PTR ds:0xfc0f80,0x1
0x4c4f49: 7527                             jne    0x4c4f72
0x4c4f4b: 830d800ffc0001                   or     DWORD PTR ds:0xfc0f80,0x1
0x4c4f52: c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x4c4f59: e8525ffbff                       call   0x47aeb0
0x4c4f5e: 6870dbbc00                       push   0xbcdb70
0x4c4f63: e8b2d33c00                       call   0x89231a
0x4c4f68: 83c404                           add    esp,0x4
0x4c4f6b: c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x4c4f72: 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4c4f75: 0fb74802                         movzx  ecx,WORD PTR [eax+0x2]
0x4c4f79: 8d5508                           lea    edx,[ebp+0x8]
0x4c4f7c: b8880ffc00                       mov    eax,0xfc0f88
0x4c4f81: 894d08                           mov    DWORD PTR [ebp+0x8],ecx
0x4c4f84: e8f7d8ffff                       call   0x4c2880
0x4c4f89: c70001000000                     mov    DWORD PTR [eax],0x1
0x4c4f8f: 33c0                             xor    eax,eax
0x4c4f91: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4c4f94: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4c4f9b: 59                               pop    ecx
0x4c4f9c: 8be5                             mov    esp,ebp
0x4c4f9e: 5d                               pop    ebp
0x4c4f9f: c20c00                           ret    0xc

; tutorial_startup_owner VA 0x48d7d4..0x48d7e3 raw 0x8cbd4 SHA256 9939e745f28ba70bffe91c51d7dc7254c511d56e657898937d431b14d1ee5d15
0x48d7d4: bec8f3fd00                       mov    esi,0xfdf3c8
0x48d7d9: b8840ffc00                       mov    eax,0xfc0f84
0x48d7de: e8fdb00100                       call   0x4a88e0

; tutorial_namespace_register VA 0x4a88e0..0x4a89bf raw 0xa7ce0 SHA256 c02c1bb33b21151db1ec5bbeffe4086005d24a77413a8d395d70428a8a528ff0
0x4a88e0: 55                               push   ebp
0x4a88e1: 8bec                             mov    ebp,esp
0x4a88e3: 83ec08                           sub    esp,0x8
0x4a88e6: 8d4dfc                           lea    ecx,[ebp-0x4]
0x4a88e9: 56                               push   esi
0x4a88ea: 51                               push   ecx
0x4a88eb: 8930                             mov    DWORD PTR [eax],esi
0x4a88ed: e8ae1c0000                       call   0x4aa5a0
0x4a88f2: 83c408                           add    esp,0x8
0x4a88f5: 50                               push   eax
0x4a88f6: e8851d0000                       call   0x4aa680
0x4a88fb: 50                               push   eax
0x4a88fc: e81f1e0000                       call   0x4aa720
0x4a8901: 50                               push   eax
0x4a8902: e8b91e0000                       call   0x4aa7c0
0x4a8907: 50                               push   eax
0x4a8908: e8531f0000                       call   0x4aa860
0x4a890d: 50                               push   eax
0x4a890e: e8ed1f0000                       call   0x4aa900
0x4a8913: 50                               push   eax
0x4a8914: e887200000                       call   0x4aa9a0
0x4a8919: 50                               push   eax
0x4a891a: e821210000                       call   0x4aaa40
0x4a891f: 50                               push   eax
0x4a8920: e8bb210000                       call   0x4aaae0
0x4a8925: 50                               push   eax
0x4a8926: e855220000                       call   0x4aab80
0x4a892b: 50                               push   eax
0x4a892c: e8ef220000                       call   0x4aac20
0x4a8931: 50                               push   eax
0x4a8932: e889230000                       call   0x4aacc0
0x4a8937: 50                               push   eax
0x4a8938: e823240000                       call   0x4aad60
0x4a893d: 50                               push   eax
0x4a893e: e8bd240000                       call   0x4aae00
0x4a8943: 50                               push   eax
0x4a8944: e857250000                       call   0x4aaea0
0x4a8949: 50                               push   eax
0x4a894a: e8f1250000                       call   0x4aaf40
0x4a894f: 50                               push   eax
0x4a8950: e88b260000                       call   0x4aafe0
0x4a8955: 50                               push   eax
0x4a8956: e825270000                       call   0x4ab080
0x4a895b: 50                               push   eax
0x4a895c: e8bf270000                       call   0x4ab120
0x4a8961: 50                               push   eax
0x4a8962: e859280000                       call   0x4ab1c0
0x4a8967: 50                               push   eax
0x4a8968: e8f3280000                       call   0x4ab260
0x4a896d: 50                               push   eax
0x4a896e: e88d290000                       call   0x4ab300
0x4a8973: 50                               push   eax
0x4a8974: e8272a0000                       call   0x4ab3a0
0x4a8979: 50                               push   eax
0x4a897a: e8c12a0000                       call   0x4ab440
0x4a897f: 50                               push   eax
0x4a8980: e85b2b0000                       call   0x4ab4e0
0x4a8985: 50                               push   eax
0x4a8986: e8f52b0000                       call   0x4ab580
0x4a898b: 50                               push   eax
0x4a898c: e88f2c0000                       call   0x4ab620
0x4a8991: 50                               push   eax
0x4a8992: e8292d0000                       call   0x4ab6c0
0x4a8997: 50                               push   eax
0x4a8998: e8c32d0000                       call   0x4ab760
0x4a899d: 50                               push   eax
0x4a899e: e85d2e0000                       call   0x4ab800
0x4a89a3: 50                               push   eax
0x4a89a4: e8f72e0000                       call   0x4ab8a0
0x4a89a9: 50                               push   eax
0x4a89aa: e8912f0000                       call   0x4ab940
0x4a89af: 686468c000                       push   0xc06864
0x4a89b4: 8bce                             mov    ecx,esi
0x4a89b6: e895c02400                       call   0x6f4a50
0x4a89bb: 8be5                             mov    esp,ebp
0x4a89bd: 5d                               pop    ebp
0x4a89be: c3                               ret

; tutorial_binding_owner VA 0x4aa5a0..0x4aa675 raw 0xa99a0 SHA256 7b198aa4b837241a2280cacaebdbf76857375b17a7edac95cf415c3480660dbf
0x4aa5a0: 55                               push   ebp
0x4aa5a1: 8bec                             mov    ebp,esp
0x4aa5a3: 51                               push   ecx
0x4aa5a4: 53                               push   ebx
0x4aa5a5: 8b5d0c                           mov    ebx,DWORD PTR [ebp+0xc]
0x4aa5a8: 56                               push   esi
0x4aa5a9: 8b33                             mov    esi,DWORD PTR [ebx]
0x4aa5ab: a30418fe00                       mov    ds:0xfe1804,eax
0x4aa5b0: 8b4610                           mov    eax,DWORD PTR [esi+0x10]
0x4aa5b3: 8b4844                           mov    ecx,DWORD PTR [eax+0x44]
0x4aa5b6: 57                               push   edi
0x4aa5b7: 891d0018fe00                     mov    DWORD PTR ds:0xfe1800,ebx
0x4aa5bd: 3b4840                           cmp    ecx,DWORD PTR [eax+0x40]
0x4aa5c0: 7207                             jb     0x4aa5c9
0x4aa5c2: 8bc6                             mov    eax,esi
0x4aa5c4: e8d70d2500                       call   0x6fb3a0
0x4aa5c9: 8b7e08                           mov    edi,DWORD PTR [esi+0x8]
0x4aa5cc: 6a00                             push   0x0
0x4aa5ce: 6a00                             push   0x0
0x4aa5d0: 56                               push   esi
0x4aa5d1: e8caf32400                       call   0x6f99a0
0x4aa5d6: 8907                             mov    DWORD PTR [edi],eax
0x4aa5d8: c7470805000000                   mov    DWORD PTR [edi+0x8],0x5
0x4aa5df: 83460810                         add    DWORD PTR [esi+0x8],0x10
0x4aa5e3: 8b33                             mov    esi,DWORD PTR [ebx]
0x4aa5e5: 83c40c                           add    esp,0xc
0x4aa5e8: bf5868c000                       mov    edi,0xc06858
0x4aa5ed: b8eed8ffff                       mov    eax,0xffffd8ee
0x4aa5f2: e899b12400                       call   0x6f5790
0x4aa5f7: 8b33                             mov    esi,DWORD PTR [ebx]
0x4aa5f9: b8eed8ffff                       mov    eax,0xffffd8ee
0x4aa5fe: e87db02400                       call   0x6f5680
0x4aa603: 8b03                             mov    eax,DWORD PTR [ebx]
0x4aa605: 8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x4aa608: 83e810                           sub    eax,0x10
0x4aa60b: bff0ffffff                       mov    edi,0xfffffff0
0x4aa610: 3dc8bfc000                       cmp    eax,0xc0bfc8
0x4aa615: 7406                             je     0x4aa61d
0x4aa617: 83780805                         cmp    DWORD PTR [eax+0x8],0x5
0x4aa61b: 7417                             je     0x4aa634
0x4aa61d: 685868c000                       push   0xc06858
0x4aa622: 68c426c400                       push   0xc426c4
0x4aa627: e8918a3e00                       call   0x8930bd
0x4aa62c: 8b03                             mov    eax,DWORD PTR [ebx]
0x4aa62e: 83c408                           add    esp,0x8
0x4aa631: 017808                           add    DWORD PTR [eax+0x8],edi
0x4aa634: 8b33                             mov    esi,DWORD PTR [ebx]
0x4aa636: 682462c000                       push   0xc06224
0x4aa63b: e8d0ae2400                       call   0x6f5510
0x4aa640: 8b33                             mov    esi,DWORD PTR [ebx]
0x4aa642: 83c404                           add    esp,0x4
0x4aa645: 6a00                             push   0x0
0x4aa647: 68e0bb4a00                       push   0x4abbe0
0x4aa64c: e85faf2400                       call   0x6f55b0
0x4aa651: 8b13                             mov    edx,DWORD PTR [ebx]
0x4aa653: 52                               push   edx
0x4aa654: b8fdffffff                       mov    eax,0xfffffffd
0x4aa659: e892b12400                       call   0x6f57f0
0x4aa65e: 8b1b                             mov    ebx,DWORD PTR [ebx]
0x4aa660: 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4aa663: 83c40c                           add    esp,0xc
0x4aa666: 017b08                           add    DWORD PTR [ebx+0x8],edi
0x4aa669: 5f                               pop    edi
0x4aa66a: 5e                               pop    esi
0x4aa66b: c7005868c000                     mov    DWORD PTR [eax],0xc06858
0x4aa671: 5b                               pop    ebx
0x4aa672: 59                               pop    ecx
0x4aa673: 5d                               pop    ebp
0x4aa674: c3                               ret

; scenario_end_getter_register VA 0x4ab940..0x4ab9d9 raw 0xaad40 SHA256 a10cab8a04e31b05a931bf7a47e5133d109ef0742e3f3ef44651f1a1d1535290
0x4ab940: 55                               push   ebp
0x4ab941: 8bec                             mov    ebp,esp
0x4ab943: 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4ab946: 53                               push   ebx
0x4ab947: 8b1d0018fe00                     mov    ebx,DWORD PTR ds:0xfe1800
0x4ab94d: 56                               push   esi
0x4ab94e: 8b33                             mov    esi,DWORD PTR [ebx]
0x4ab950: 57                               push   edi
0x4ab951: 8b38                             mov    edi,DWORD PTR [eax]
0x4ab953: b8eed8ffff                       mov    eax,0xffffd8ee
0x4ab958: c7058018fe0010a54a00             mov    DWORD PTR ds:0xfe1880,0x4aa510
0x4ab962: e8199d2400                       call   0x6f5680
0x4ab967: 8b03                             mov    eax,DWORD PTR [ebx]
0x4ab969: 8b4008                           mov    eax,DWORD PTR [eax+0x8]
0x4ab96c: 83e810                           sub    eax,0x10
0x4ab96f: 3dc8bfc000                       cmp    eax,0xc0bfc8
0x4ab974: 7406                             je     0x4ab97c
0x4ab976: 83780805                         cmp    DWORD PTR [eax+0x8],0x5
0x4ab97a: 7414                             je     0x4ab990
0x4ab97c: 57                               push   edi
0x4ab97d: 68c426c400                       push   0xc426c4
0x4ab982: e836773e00                       call   0x8930bd
0x4ab987: 8b1b                             mov    ebx,DWORD PTR [ebx]
0x4ab989: 83c408                           add    esp,0x8
0x4ab98c: 834308f0                         add    DWORD PTR [ebx+0x8],0xfffffff0
0x4ab990: 8b3d0018fe00                     mov    edi,DWORD PTR ds:0xfe1800
0x4ab996: 8b37                             mov    esi,DWORD PTR [edi]
0x4ab998: 6880add600                       push   0xd6ad80
0x4ab99d: e86e9b2400                       call   0x6f5510
0x4ab9a2: 8b37                             mov    esi,DWORD PTR [edi]
0x4ab9a4: 83c404                           add    esp,0x4
0x4ab9a7: 6a00                             push   0x0
0x4ab9a9: 6840ca4a00                       push   0x4aca40
0x4ab9ae: e8fd9b2400                       call   0x6f55b0
0x4ab9b3: 8b0f                             mov    ecx,DWORD PTR [edi]
0x4ab9b5: 51                               push   ecx
0x4ab9b6: b8fdffffff                       mov    eax,0xfffffffd
0x4ab9bb: e8309e2400                       call   0x6f57f0
0x4ab9c0: 8b150018fe00                     mov    edx,DWORD PTR ds:0xfe1800
0x4ab9c6: 8b02                             mov    eax,DWORD PTR [edx]
0x4ab9c8: 83c40c                           add    esp,0xc
0x4ab9cb: 834008f0                         add    DWORD PTR [eax+0x8],0xfffffff0
0x4ab9cf: 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4ab9d2: 5f                               pop    edi
0x4ab9d3: 5e                               pop    esi
0x4ab9d4: 5b                               pop    ebx
0x4ab9d5: 5d                               pop    ebp
0x4ab9d6: c20400                           ret    0x4

; scenario_end_lua_thunk VA 0x4aca40..0x4aca9d raw 0xabe40 SHA256 b8b166fa190bc54ad4365226020532847406b080234591e98583a2b4aed0e676
0x4aca40: 55                               push   ebp
0x4aca41: 8bec                             mov    ebp,esp
0x4aca43: 6aff                             push   0xffffffff
0x4aca45: 68c8839300                       push   0x9383c8
0x4aca4a: 64a100000000                     mov    eax,fs:0x0
0x4aca50: 50                               push   eax
0x4aca51: 83ec0c                           sub    esp,0xc
0x4aca54: a1201fd600                       mov    eax,ds:0xd61f20
0x4aca59: 33c5                             xor    eax,ebp
0x4aca5b: 50                               push   eax
0x4aca5c: 8d45f4                           lea    eax,[ebp-0xc]
0x4aca5f: 64a300000000                     mov    fs:0x0,eax
0x4aca65: 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4aca68: 8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x4aca6b: 33c0                             xor    eax,eax
0x4aca6d: 8945ec                           mov    DWORD PTR [ebp-0x14],eax
0x4aca70: 8945f0                           mov    DWORD PTR [ebp-0x10],eax
0x4aca73: 8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x4aca76: 8b0d8018fe00                     mov    ecx,DWORD PTR ds:0xfe1880
0x4aca7c: 51                               push   ecx
0x4aca7d: 8d55e8                           lea    edx,[ebp-0x18]
0x4aca80: 52                               push   edx
0x4aca81: e80a050000                       call   0x4acf90
0x4aca86: 83c408                           add    esp,0x8
0x4aca89: b801000000                       mov    eax,0x1
0x4aca8e: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4aca91: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4aca98: 59                               pop    ecx
0x4aca99: 8be5                             mov    esp,ebp
0x4aca9b: 5d                               pop    ebp
0x4aca9c: c3                               ret

; scenario_end_marshaller VA 0x4acf90..0x4ad019 raw 0xac390 SHA256 6e8aec76b980d9ca1d74821b76457717fabf17e284fd3e182430bbb18e263674
0x4acf90: 55                               push   ebp
0x4acf91: 8bec                             mov    ebp,esp
0x4acf93: 83ec14                           sub    esp,0x14
0x4acf96: a10418fe00                       mov    eax,ds:0xfe1804
0x4acf9b: 53                               push   ebx
0x4acf9c: 8b5d08                           mov    ebx,DWORD PTR [ebp+0x8]
0x4acf9f: 8b0b                             mov    ecx,DWORD PTR [ebx]
0x4acfa1: 8945fc                           mov    DWORD PTR [ebp-0x4],eax
0x4acfa4: 83c8ff                           or     eax,0xffffffff
0x4acfa7: e844812400                       call   0x6f50f0
0x4acfac: 8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x4acfaf: 83f903                           cmp    ecx,0x3
0x4acfb2: 742a                             je     0x4acfde
0x4acfb4: 83f904                           cmp    ecx,0x4
0x4acfb7: 755c                             jne    0x4ad015
0x4acfb9: 56                               push   esi
0x4acfba: 8b30                             mov    esi,DWORD PTR [eax]
0x4acfbc: 57                               push   edi
0x4acfbd: 83c610                           add    esi,0x10
0x4acfc0: 8d7df4                           lea    edi,[ebp-0xc]
0x4acfc3: e898a72400                       call   0x6f7760
0x4acfc8: 5f                               pop    edi
0x4acfc9: 5e                               pop    esi
0x4acfca: 85c0                             test   eax,eax
0x4acfcc: 7447                             je     0x4ad015
0x4acfce: dd45f4                           fld    QWORD PTR [ebp-0xc]
0x4acfd1: c745f403000000                   mov    DWORD PTR [ebp-0xc],0x3
0x4acfd8: dd5dec                           fstp   QWORD PTR [ebp-0x14]
0x4acfdb: 8d45ec                           lea    eax,[ebp-0x14]
0x4acfde: dd00                             fld    QWORD PTR [eax]
0x4acfe0: dd5df4                           fstp   QWORD PTR [ebp-0xc]
0x4acfe3: dd45f4                           fld    QWORD PTR [ebp-0xc]
0x4acfe6: db5d08                           fistp  DWORD PTR [ebp+0x8]
0x4acfe9: 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4acfec: 8b4dfc                           mov    ecx,DWORD PTR [ebp-0x4]
0x4acfef: 50                               push   eax
0x4acff0: ff550c                           call   DWORD PTR [ebp+0xc]
0x4acff3: 89450c                           mov    DWORD PTR [ebp+0xc],eax
0x4acff6: 8b03                             mov    eax,DWORD PTR [ebx]
0x4acff8: db450c                           fild   DWORD PTR [ebp+0xc]
0x4acffb: 8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x4acffe: c7410803000000                   mov    DWORD PTR [ecx+0x8],0x3
0x4ad005: dd19                             fstp   QWORD PTR [ecx]
0x4ad007: 83400810                         add    DWORD PTR [eax+0x8],0x10
0x4ad00b: b801000000                       mov    eax,0x1
0x4ad010: 5b                               pop    ebx
0x4ad011: 8be5                             mov    esp,ebp
0x4ad013: 5d                               pop    ebp
0x4ad014: c3                               ret
0x4ad015: 33c0                             xor    eax,eax
0x4ad017: ebd3                             jmp    0x4acfec

; scenario_end_native_getter VA 0x4aa510..0x4aa524 raw 0xa9910 SHA256 56570b9ffbec6f763df4e278d34c59620e6726cb5fbbe2c42da7151cfa41e8db
0x4aa510: 55                               push   ebp
0x4aa511: 8bec                             mov    ebp,esp
0x4aa513: 8d4104                           lea    eax,[ecx+0x4]
0x4aa516: 8d5508                           lea    edx,[ebp+0x8]
0x4aa519: e862830100                       call   0x4c2880
0x4aa51e: 8b00                             mov    eax,DWORD PTR [eax]
0x4aa520: 5d                               pop    ebp
0x4aa521: c20400                           ret    0x4

; tutorial_rebind_thunk VA 0x4abbe0..0x4abbf2 raw 0xaafe0 SHA256 783f393e5fb84cfa1de77572db39d1d1b22bb816ad6311c42bb53e13db5b4ccb
0x4abbe0: a10018fe00                       mov    eax,ds:0xfe1800
0x4abbe5: e8c66fffff                       call   0x4a2bb0
0x4abbea: a30418fe00                       mov    ds:0xfe1804,eax
0x4abbef: 33c0                             xor    eax,eax
0x4abbf1: c3                               ret

; tutorial_rebind_convert VA 0x4a2bb0..0x4a2c0c raw 0xa1fb0 SHA256 a0d581e0cbd88356c947ecc8ee389973dc1ebcb85e2fd5445f90134e1907ec27
0x4a2bb0: 55                               push   ebp
0x4a2bb1: 8bec                             mov    ebp,esp
0x4a2bb3: 8b08                             mov    ecx,DWORD PTR [eax]
0x4a2bb5: 83ec18                           sub    esp,0x18
0x4a2bb8: 56                               push   esi
0x4a2bb9: 57                               push   edi
0x4a2bba: 83c8ff                           or     eax,0xffffffff
0x4a2bbd: e82e252500                       call   0x6f50f0
0x4a2bc2: 8b4808                           mov    ecx,DWORD PTR [eax+0x8]
0x4a2bc5: 83f903                           cmp    ecx,0x3
0x4a2bc8: 7426                             je     0x4a2bf0
0x4a2bca: 83f904                           cmp    ecx,0x4
0x4a2bcd: 7535                             jne    0x4a2c04
0x4a2bcf: 8b30                             mov    esi,DWORD PTR [eax]
0x4a2bd1: 83c610                           add    esi,0x10
0x4a2bd4: 8d7df8                           lea    edi,[ebp-0x8]
0x4a2bd7: e8844b2500                       call   0x6f7760
0x4a2bdc: 85c0                             test   eax,eax
0x4a2bde: 7424                             je     0x4a2c04
0x4a2be0: dd45f8                           fld    QWORD PTR [ebp-0x8]
0x4a2be3: c745f003000000                   mov    DWORD PTR [ebp-0x10],0x3
0x4a2bea: dd5de8                           fstp   QWORD PTR [ebp-0x18]
0x4a2bed: 8d45e8                           lea    eax,[ebp-0x18]
0x4a2bf0: dd00                             fld    QWORD PTR [eax]
0x4a2bf2: dd5df0                           fstp   QWORD PTR [ebp-0x10]
0x4a2bf5: dd45f0                           fld    QWORD PTR [ebp-0x10]
0x4a2bf8: db5dfc                           fistp  DWORD PTR [ebp-0x4]
0x4a2bfb: 8b45fc                           mov    eax,DWORD PTR [ebp-0x4]
0x4a2bfe: 5f                               pop    edi
0x4a2bff: 5e                               pop    esi
0x4a2c00: 8be5                             mov    esp,ebp
0x4a2c02: 5d                               pop    ebp
0x4a2c03: c3                               ret
0x4a2c04: 5f                               pop    edi
0x4a2c05: 33c0                             xor    eax,eax
0x4a2c07: 5e                               pop    esi
0x4a2c08: 8be5                             mov    esp,ebp
0x4a2c0a: 5d                               pop    ebp
0x4a2c0b: c3                               ret

; tutorial_start_clear_caller VA 0x4c4d3a..0x4c4d44 raw 0xc413a SHA256 c64dc0d34f7369bb515dd4e87d065bf63c1a2c17b4289c02e8b3c3a36416772a
0x4c4d3a: be840ffc00                       mov    esi,0xfc0f84
0x4c4d3f: e81c3dfeff                       call   0x4a8a60

; tutorial_map_clear_prefix VA 0x4a8a60..0x4a8a99 raw 0xa7e60 SHA256 537ea2cd4a9f2d596035ff0553469e6d13cd414c263ef31686bf7c90125691c4
0x4a8a60: 55                               push   ebp
0x4a8a61: 8bec                             mov    ebp,esp
0x4a8a63: 6aff                             push   0xffffffff
0x4a8a65: 684ca49300                       push   0x93a44c
0x4a8a6a: 64a100000000                     mov    eax,fs:0x0
0x4a8a70: 50                               push   eax
0x4a8a71: 83ec08                           sub    esp,0x8
0x4a8a74: 53                               push   ebx
0x4a8a75: 57                               push   edi
0x4a8a76: a1201fd600                       mov    eax,ds:0xd61f20
0x4a8a7b: 33c5                             xor    eax,ebp
0x4a8a7d: 50                               push   eax
0x4a8a7e: 8d45f4                           lea    eax,[ebp-0xc]
0x4a8a81: 64a300000000                     mov    fs:0x0,eax
0x4a8a87: 8d7e04                           lea    edi,[esi+0x4]
0x4a8a8a: c705a0a7fb0000000000             mov    DWORD PTR ds:0xfba7a0,0x0
0x4a8a94: e8b7ad3700                       call   0x823850

; selection_ack_handler VA 0x4b3570..0x4b35f5 raw 0xb2970 SHA256 6268b261a9692bcbdff5cf98f285f5a23bcd13e3f401c917107f389deb66f6df
0x4b3570: 55                               push   ebp
0x4b3571: 8bec                             mov    ebp,esp
0x4b3573: 6aff                             push   0xffffffff
0x4b3575: 689e4d9200                       push   0x924d9e
0x4b357a: 64a100000000                     mov    eax,fs:0x0
0x4b3580: 50                               push   eax
0x4b3581: a1201fd600                       mov    eax,ds:0xd61f20
0x4b3586: 33c5                             xor    eax,ebp
0x4b3588: 50                               push   eax
0x4b3589: 8d45f4                           lea    eax,[ebp-0xc]
0x4b358c: 64a300000000                     mov    fs:0x0,eax
0x4b3592: 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x4b3595: 0fb74002                         movzx  eax,WORD PTR [eax+0x2]
0x4b3599: 8b0df818fe00                     mov    ecx,DWORD PTR ds:0xfe18f8
0x4b359f: 894108                           mov    DWORD PTR [ecx+0x8],eax
0x4b35a2: b801000000                       mov    eax,0x1
0x4b35a7: 8405d4adfa00                     test   BYTE PTR ds:0xfaadd4,al
0x4b35ad: 7526                             jne    0x4b35d5
0x4b35af: 0905d4adfa00                     or     DWORD PTR ds:0xfaadd4,eax
0x4b35b5: c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x4b35bc: e8bf3e0d00                       call   0x587480
0x4b35c1: 68c0ccbc00                       push   0xbcccc0
0x4b35c6: e84fed3d00                       call   0x89231a
0x4b35cb: 83c404                           add    esp,0x4
0x4b35ce: c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x4b35d5: 68da430f00                       push   0xf43da
0x4b35da: e8f1740d00                       call   0x58aad0
0x4b35df: 83c404                           add    esp,0x4
0x4b35e2: 33c0                             xor    eax,eax
0x4b35e4: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x4b35e7: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x4b35ee: 59                               pop    ecx
0x4b35ef: 8be5                             mov    esp,ebp
0x4b35f1: 5d                               pop    ebp
0x4b35f2: c20c00                           ret    0xc

; selection_native_owner VA 0x506e06..0x506e71 raw 0x106206 SHA256 10b0c3c8852efd042b03905359fb57823dddd64bfce4dac6d93568c3d5774e72
0x506e06: 6a38                             push   0x38
0x506e08: e85ba43800                       call   0x891268
0x506e0d: 83c404                           add    esp,0x4
0x506e10: 3bc3                             cmp    eax,ebx
0x506e12: 7450                             je     0x506e64
0x506e14: c74004406dbf00                   mov    DWORD PTR [eax+0x4],0xbf6d40
0x506e1b: c70064ddc000                     mov    DWORD PTR [eax],0xc0dd64
0x506e21: c740046cddc000                   mov    DWORD PTR [eax+0x4],0xc0dd6c
0x506e28: 8d4804                           lea    ecx,[eax+0x4]
0x506e2b: 885812                           mov    BYTE PTR [eax+0x12],bl
0x506e2e: ba50000000                       mov    edx,0x50
0x506e33: 6689500c                         mov    WORD PTR [eax+0xc],dx
0x506e37: 33d2                             xor    edx,edx
0x506e39: 6689500e                         mov    WORD PTR [eax+0xe],dx
0x506e3d: 66895010                         mov    WORD PTR [eax+0x10],dx
0x506e41: 895814                           mov    DWORD PTR [eax+0x14],ebx
0x506e44: 895818                           mov    DWORD PTR [eax+0x18],ebx
0x506e47: 89581c                           mov    DWORD PTR [eax+0x1c],ebx
0x506e4a: a3f818fe00                       mov    ds:0xfe18f8,eax
0x506e4f: 895824                           mov    DWORD PTR [eax+0x24],ebx
0x506e52: 66895828                         mov    WORD PTR [eax+0x28],bx
0x506e56: 89582a                           mov    DWORD PTR [eax+0x2a],ebx
0x506e59: 89582e                           mov    DWORD PTR [eax+0x2e],ebx
0x506e5c: 895832                           mov    DWORD PTR [eax+0x32],ebx
0x506e5f: 894df0                           mov    DWORD PTR [ebp-0x10],ecx
0x506e62: eb03                             jmp    0x506e67
0x506e64: 895df0                           mov    DWORD PTR [ebp-0x10],ebx
0x506e67: 8d45f0                           lea    eax,[ebp-0x10]
0x506e6a: 8bfe                             mov    edi,esi
0x506e6c: e89fcef3ff                       call   0x443d10

; selection_token_echo VA 0x6bc0f6..0x6bc156 raw 0x2bb4f6 SHA256 807f94e6d7a48d511d112cccc3a0c1b01ee3200751f10c8c0bf949d50a583b54
0x6bc0f6: a1f818fe00                       mov    eax,ds:0xfe18f8
0x6bc0fb: 8b7008                           mov    esi,DWORD PTR [eax+0x8]
0x6bc0fe: 840d1413fb00                     test   BYTE PTR ds:0xfb1314,cl
0x6bc104: 7513                             jne    0x6bc119
0x6bc106: 090d1413fb00                     or     DWORD PTR ds:0xfb1314,ecx
0x6bc10c: 6810cfbc00                       push   0xbccf10
0x6bc111: e804621d00                       call   0x89231a
0x6bc116: 83c404                           add    esp,0x4
0x6bc119: 833d98a7fb0000                   cmp    DWORD PTR ds:0xfba798,0x0
0x6bc120: 8b55f0                           mov    edx,DWORD PTR [ebp-0x10]
0x6bc123: 8b45f4                           mov    eax,DWORD PTR [ebp-0xc]
0x6bc126: b928000000                       mov    ecx,0x28
0x6bc12b: 66894de0                         mov    WORD PTR [ebp-0x20],cx
0x6bc12f: 8a4df8                           mov    cl,BYTE PTR [ebp-0x8]
0x6bc132: 668975e2                         mov    WORD PTR [ebp-0x1e],si
0x6bc136: 8955e4                           mov    DWORD PTR [ebp-0x1c],edx
0x6bc139: 8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x6bc13c: 884dec                           mov    BYTE PTR [ebp-0x14],cl
0x6bc13f: 7545                             jne    0x6bc186
0x6bc141: 8b0d54a8fb00                     mov    ecx,DWORD PTR ds:0xfba854
0x6bc147: 8b11                             mov    edx,DWORD PTR [ecx]
0x6bc149: 8b5210                           mov    edx,DWORD PTR [edx+0x10]
0x6bc14c: 6a0d                             push   0xd
0x6bc14e: 8d45e0                           lea    eax,[ebp-0x20]
0x6bc151: 50                               push   eax
0x6bc152: 6a00                             push   0x0
0x6bc154: ffd2                             call   edx

; enqueue_generic_ui_event VA 0x58aad0..0x58ab79 raw 0x189ed0 SHA256 1777dfd1eb8dc4697404dba2ca2ed9dee34e961b350b96057f22fc64e87a7445
0x58aad0: 55                               push   ebp
0x58aad1: 8bec                             mov    ebp,esp
0x58aad3: 6aff                             push   0xffffffff
0x58aad5: 68eef89100                       push   0x91f8ee
0x58aada: 64a100000000                     mov    eax,fs:0x0
0x58aae0: 50                               push   eax
0x58aae1: 83ec08                           sub    esp,0x8
0x58aae4: 56                               push   esi
0x58aae5: a1201fd600                       mov    eax,ds:0xd61f20
0x58aaea: 33c5                             xor    eax,ebp
0x58aaec: 50                               push   eax
0x58aaed: 8d45f4                           lea    eax,[ebp-0xc]
0x58aaf0: 64a300000000                     mov    fs:0x0,eax
0x58aaf6: 6a14                             push   0x14
0x58aaf8: e86b673000                       call   0x891268
0x58aafd: 33c9                             xor    ecx,ecx
0x58aaff: 83c404                           add    esp,0x4
0x58ab02: 3bc1                             cmp    eax,ecx
0x58ab04: 7421                             je     0x58ab27
0x58ab06: 8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0x58ab09: c7000c7bc400                     mov    DWORD PTR [eax],0xc47b0c
0x58ab0f: c74004ffffffff                   mov    DWORD PTR [eax+0x4],0xffffffff
0x58ab16: c74008ffffffff                   mov    DWORD PTR [eax+0x8],0xffffffff
0x58ab1d: 89480c                           mov    DWORD PTR [eax+0xc],ecx
0x58ab20: 895010                           mov    DWORD PTR [eax+0x10],edx
0x58ab23: 8bf0                             mov    esi,eax
0x58ab25: eb02                             jmp    0x58ab29
0x58ab27: 33f6                             xor    esi,esi
0x58ab29: b801000000                       mov    eax,0x1
0x58ab2e: 8405d0adfa00                     test   BYTE PTR ds:0xfaadd0,al
0x58ab34: 7522                             jne    0x58ab58
0x58ab36: 0905d0adfa00                     or     DWORD PTR ds:0xfaadd0,eax
0x58ab3c: 894dfc                           mov    DWORD PTR [ebp-0x4],ecx
0x58ab3f: e84c2e1c00                       call   0x74d990
0x58ab44: 6870ccbc00                       push   0xbccc70
0x58ab49: e8cc773000                       call   0x89231a
0x58ab4e: 83c404                           add    esp,0x4
0x58ab51: c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x58ab58: 8d45f0                           lea    eax,[ebp-0x10]
0x58ab5b: 8975f0                           mov    DWORD PTR [ebp-0x10],esi
0x58ab5e: 50                               push   eax
0x58ab5f: be6c5cf900                       mov    esi,0xf95c6c
0x58ab64: e8f7962700                       call   0x804260
0x58ab69: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x58ab6c: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x58ab73: 59                               pop    ecx
0x58ab74: 5e                               pop    esi
0x58ab75: 8be5                             mov    esp,ebp
0x58ab77: 5d                               pop    ebp
0x58ab78: c3                               ret

; page_event_class_router VA 0x595d20..0x595d9d raw 0x195120 SHA256 921b4dd057cd320115685a183a87ab200062a8429cb73923e250f0e3920cfb1a
0x595d20: 55                               push   ebp
0x595d21: 8bec                             mov    ebp,esp
0x595d23: 8b5508                           mov    edx,DWORD PTR [ebp+0x8]
0x595d26: 8b4210                           mov    eax,DWORD PTR [edx+0x10]
0x595d29: 3dd7420f00                       cmp    eax,0xf42d7
0x595d2e: 7616                             jbe    0x595d46
0x595d30: 3d4a430f00                       cmp    eax,0xf434a
0x595d35: 7314                             jae    0x595d4b
0x595d37: 8b01                             mov    eax,DWORD PTR [ecx]
0x595d39: 52                               push   edx
0x595d3a: 8b908c010000                     mov    edx,DWORD PTR [eax+0x18c]
0x595d40: ffd2                             call   edx
0x595d42: 5d                               pop    ebp
0x595d43: c20400                           ret    0x4
0x595d46: 3d4a430f00                       cmp    eax,0xf434a
0x595d4b: 7616                             jbe    0x595d63
0x595d4d: 3d5c430f00                       cmp    eax,0xf435c
0x595d52: 730f                             jae    0x595d63
0x595d54: 8b01                             mov    eax,DWORD PTR [ecx]
0x595d56: 52                               push   edx
0x595d57: 8b9090010000                     mov    edx,DWORD PTR [eax+0x190]
0x595d5d: ffd2                             call   edx
0x595d5f: 5d                               pop    ebp
0x595d60: c20400                           ret    0x4
0x595d63: 3d40420f00                       cmp    eax,0xf4240
0x595d68: 7616                             jbe    0x595d80
0x595d6a: 3dd7420f00                       cmp    eax,0xf42d7
0x595d6f: 730f                             jae    0x595d80
0x595d71: 8b01                             mov    eax,DWORD PTR [ecx]
0x595d73: 52                               push   edx
0x595d74: 8b9094010000                     mov    edx,DWORD PTR [eax+0x194]
0x595d7a: ffd2                             call   edx
0x595d7c: 5d                               pop    ebp
0x595d7d: c20400                           ret    0x4
0x595d80: 3d5c430f00                       cmp    eax,0xf435c
0x595d85: 7612                             jbe    0x595d99
0x595d87: 3d42440f00                       cmp    eax,0xf4442
0x595d8c: 730b                             jae    0x595d99
0x595d8e: 8b01                             mov    eax,DWORD PTR [ecx]
0x595d90: 52                               push   edx
0x595d91: 8b9098010000                     mov    edx,DWORD PTR [eax+0x198]
0x595d97: ffd2                             call   edx
0x595d99: 5d                               pop    ebp
0x595d9a: c20400                           ret    0x4

; lobby_f43da_dispatch_prefix VA 0x5b7f80..0x5b7fb5 raw 0x1b7380 SHA256 f2396ef149d6a50e7dbcd6d7b71e5ec75edd7cfefbdc881a62aa3ee42905e8c2
0x5b7f80: 55                               push   ebp
0x5b7f81: 8bec                             mov    ebp,esp
0x5b7f83: 83ec08                           sub    esp,0x8
0x5b7f86: 53                               push   ebx
0x5b7f87: 56                               push   esi
0x5b7f88: 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x5b7f8b: 56                               push   esi
0x5b7f8c: 8bd9                             mov    ebx,ecx
0x5b7f8e: e8ed3dfeff                       call   0x59bd80
0x5b7f93: 8b4610                           mov    eax,DWORD PTR [esi+0x10]
0x5b7f96: 059cbcf0ff                       add    eax,0xfff0bc9c
0x5b7f9b: 3ddb000000                       cmp    eax,0xdb
0x5b7fa0: 0f87e3030000                     ja     0x5b8389
0x5b7fa6: 0fb68060845b00                   movzx  eax,BYTE PTR [eax+0x5b8460]
0x5b7fad: 57                               push   edi
0x5b7fae: ff248594835b00                   jmp    DWORD PTR [eax*4+0x5b8394]

; lobby_f43da_case VA 0x5b8177..0x5b8187 raw 0x1b7577 SHA256 8171971ea03fc797994d023d2dd421c8eb8d60a1b45345df2c1fd953460e03a1
0x5b8177: 8bf3                             mov    esi,ebx
0x5b8179: e862150000                       call   0x5b96e0
0x5b817e: 5f                               pop    edi
0x5b817f: 5e                               pop    esi
0x5b8180: 5b                               pop    ebx
0x5b8181: 8be5                             mov    esp,ebp
0x5b8183: 5d                               pop    ebp
0x5b8184: c20400                           ret    0x4

; base_page_dispatch_prefix VA 0x59bd80..0x59bdb6 raw 0x19b180 SHA256 1a6b855d60818d2d0cae0e9a2e85fa52fed539f01fb65dfd9558756fedd4a51b
0x59bd80: 55                               push   ebp
0x59bd81: 8bec                             mov    ebp,esp
0x59bd83: 83e4f8                           and    esp,0xfffffff8
0x59bd86: 51                               push   ecx
0x59bd87: 53                               push   ebx
0x59bd88: 56                               push   esi
0x59bd89: 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x59bd8c: 57                               push   edi
0x59bd8d: 56                               push   esi
0x59bd8e: 8bf9                             mov    edi,ecx
0x59bd90: e87b850000                       call   0x5a4310
0x59bd95: 8b4610                           mov    eax,DWORD PTR [esi+0x10]
0x59bd98: 059fbcf0ff                       add    eax,0xfff0bc9f
0x59bd9d: 3dd8000000                       cmp    eax,0xd8
0x59bda2: 0f87af020000                     ja     0x59c057
0x59bda8: 0fb680ccc05900                   movzx  eax,BYTE PTR [eax+0x59c0cc]
0x59bdaf: ff248560c05900                   jmp    DWORD PTR [eax*4+0x59c060]

; base_page_default_return VA 0x59c057..0x59c060 raw 0x19b457 SHA256 7fbbb93cd553dee0aafd8869520a1bc81fdb80ae47e4f0ec343cae1ae63c6f5f
0x59c057: 5f                               pop    edi
0x59c058: 5e                               pop    esi
0x59c059: 5b                               pop    ebx
0x59c05a: 8be5                             mov    esp,ebp
0x59c05c: 5d                               pop    ebp
0x59c05d: c20400                           ret    0x4

; base_page_second_dispatch VA 0x5a4310..0x5a43f7 raw 0x1a3710 SHA256 2bea02abe749fdcaa7c16a4b18e68cfdd917ce652eb023e9670e7ea6075d713c
0x5a4310: 55                               push   ebp
0x5a4311: 8bec                             mov    ebp,esp
0x5a4313: 51                               push   ecx
0x5a4314: 56                               push   esi
0x5a4315: 8b7508                           mov    esi,DWORD PTR [ebp+0x8]
0x5a4318: 8b4610                           mov    eax,DWORD PTR [esi+0x10]
0x5a431b: 0525bcf0ff                       add    eax,0xfff0bc25
0x5a4320: 57                               push   edi
0x5a4321: 8bf9                             mov    edi,ecx
0x5a4323: 83f824                           cmp    eax,0x24
0x5a4326: 772f                             ja     0x5a4357
0x5a4328: 0fb6800c445a00                   movzx  eax,BYTE PTR [eax+0x5a440c]
0x5a432f: ff2485f8435a00                   jmp    DWORD PTR [eax*4+0x5a43f8]
0x5a4336: e88523ffff                       call   0x5966c0
0x5a433b: eb1a                             jmp    0x5a4357
0x5a433d: 57                               push   edi
0x5a433e: e8ed24ffff                       call   0x596830
0x5a4343: eb12                             jmp    0x5a4357
0x5a4345: 6a00                             push   0x0
0x5a4347: 57                               push   edi
0x5a4348: e88331ffff                       call   0x5974d0
0x5a434d: eb08                             jmp    0x5a4357
0x5a434f: 57                               push   edi
0x5a4350: 8bc6                             mov    eax,esi
0x5a4352: e87935ffff                       call   0x5978d0
0x5a4357: 8b4610                           mov    eax,DWORD PTR [esi+0x10]
0x5a435a: 059abcf0ff                       add    eax,0xfff0bc9a
0x5a435f: 3d80000000                       cmp    eax,0x80
0x5a4364: 0f8786000000                     ja     0x5a43f0
0x5a436a: 0fb6885c445a00                   movzx  ecx,BYTE PTR [eax+0x5a445c]
0x5a4371: ff248d34445a00                   jmp    DWORD PTR [ecx*4+0x5a4434]
0x5a4378: 8bcf                             mov    ecx,edi
0x5a437a: e891faffff                       call   0x5a3e10
0x5a437f: 5f                               pop    edi
0x5a4380: 5e                               pop    esi
0x5a4381: 59                               pop    ecx
0x5a4382: 5d                               pop    ebp
0x5a4383: c20400                           ret    0x4
0x5a4386: 8bcf                             mov    ecx,edi
0x5a4388: e8b30e0000                       call   0x5a5240
0x5a438d: 5f                               pop    edi
0x5a438e: 5e                               pop    esi
0x5a438f: 59                               pop    ecx
0x5a4390: 5d                               pop    ebp
0x5a4391: c20400                           ret    0x4
0x5a4394: 57                               push   edi
0x5a4395: 8bce                             mov    ecx,esi
0x5a4397: e804fdffff                       call   0x5a40a0
0x5a439c: 5f                               pop    edi
0x5a439d: 5e                               pop    esi
0x5a439e: 59                               pop    ecx
0x5a439f: 5d                               pop    ebp
0x5a43a0: c20400                           ret    0x4
0x5a43a3: 57                               push   edi
0x5a43a4: 8bce                             mov    ecx,esi
0x5a43a6: e8f5fdffff                       call   0x5a41a0
0x5a43ab: 5f                               pop    edi
0x5a43ac: 5e                               pop    esi
0x5a43ad: 59                               pop    ecx
0x5a43ae: 5d                               pop    ebp
0x5a43af: c20400                           ret    0x4
0x5a43b2: 8bf7                             mov    esi,edi
0x5a43b4: e887050000                       call   0x5a4940
0x5a43b9: 5f                               pop    edi
0x5a43ba: 5e                               pop    esi
0x5a43bb: 59                               pop    ecx
0x5a43bc: 5d                               pop    ebp
0x5a43bd: c20400                           ret    0x4
0x5a43c0: 8bf7                             mov    esi,edi
0x5a43c2: e819060000                       call   0x5a49e0
0x5a43c7: 5f                               pop    edi
0x5a43c8: 5e                               pop    esi
0x5a43c9: 59                               pop    ecx
0x5a43ca: 5d                               pop    ebp
0x5a43cb: c20400                           ret    0x4
0x5a43ce: 8bcf                             mov    ecx,edi
0x5a43d0: e81b070000                       call   0x5a4af0
0x5a43d5: 5f                               pop    edi
0x5a43d6: 5e                               pop    esi
0x5a43d7: 59                               pop    ecx
0x5a43d8: 5d                               pop    ebp
0x5a43d9: c20400                           ret    0x4
0x5a43dc: 8bf7                             mov    esi,edi
0x5a43de: e80dfbffff                       call   0x5a3ef0
0x5a43e3: 5f                               pop    edi
0x5a43e4: 5e                               pop    esi
0x5a43e5: 59                               pop    ecx
0x5a43e6: 5d                               pop    ebp
0x5a43e7: c20400                           ret    0x4
0x5a43ea: 57                               push   edi
0x5a43eb: e8b0160000                       call   0x5a5aa0
0x5a43f0: 5f                               pop    edi
0x5a43f1: 5e                               pop    esi
0x5a43f2: 59                               pop    ecx
0x5a43f3: 5d                               pop    ebp
0x5a43f4: c20400                           ret    0x4

; mission_lobby_factory VA 0x587a3d..0x587ad7 raw 0x186e3d SHA256 62fad9463c982a89c29e8c25a4a4d81ed6f2e0e3ab3f61f7a9924940d9f02693
0x587a3d: 680c030000                       push   0x30c
0x587a42: e821a63000                       call   0x892068
0x587a47: 8bf0                             mov    esi,eax
0x587a49: 83c404                           add    esp,0x4
0x587a4c: 897508                           mov    DWORD PTR [ebp+0x8],esi
0x587a4f: 33ff                             xor    edi,edi
0x587a51: c745fc04000000                   mov    DWORD PTR [ebp-0x4],0x4
0x587a58: 3bf7                             cmp    esi,edi
0x587a5a: 742f                             je     0x587a8b
0x587a5c: 56                               push   esi
0x587a5d: e8bed50200                       call   0x5b5020
0x587a62: 89bef8020000                     mov    DWORD PTR [esi+0x2f8],edi
0x587a68: c706a4d9c100                     mov    DWORD PTR [esi],0xc1d9a4
0x587a6e: 89befc020000                     mov    DWORD PTR [esi+0x2fc],edi
0x587a74: 89be00030000                     mov    DWORD PTR [esi+0x300],edi
0x587a7a: 89be04030000                     mov    DWORD PTR [esi+0x304],edi
0x587a80: 89be08030000                     mov    DWORD PTR [esi+0x308],edi
0x587a86: 897508                           mov    DWORD PTR [ebp+0x8],esi
0x587a89: eb03                             jmp    0x587a8e
0x587a8b: 897d08                           mov    DWORD PTR [ebp+0x8],edi
0x587a8e: c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x587a95: 8b7b2c                           mov    edi,DWORD PTR [ebx+0x2c]
0x587a98: 8d55e8                           lea    edx,[ebp-0x18]
0x587a9b: 8d7704                           lea    esi,[edi+0x4]
0x587a9e: 52                               push   edx
0x587a9f: 8d45ec                           lea    eax,[ebp-0x14]
0x587aa2: 8bce                             mov    ecx,esi
0x587aa4: c745e804000000                   mov    DWORD PTR [ebp-0x18],0x4
0x587aab: e850742a00                       call   0x82ef00
0x587ab0: 8b7f08                           mov    edi,DWORD PTR [edi+0x8]
0x587ab3: 397dec                           cmp    DWORD PTR [ebp-0x14],edi
0x587ab6: 751f                             jne    0x587ad7
0x587ab8: 8b4508                           mov    eax,DWORD PTR [ebp+0x8]
0x587abb: 8d7de4                           lea    edi,[ebp-0x1c]
0x587abe: c745e404000000                   mov    DWORD PTR [ebp-0x1c],0x4
0x587ac5: 8945e8                           mov    DWORD PTR [ebp-0x18],eax
0x587ac8: e85374ffff                       call   0x57ef20
0x587acd: 50                               push   eax
0x587ace: 56                               push   esi
0x587acf: 8d75e4                           lea    esi,[ebp-0x1c]
0x587ad2: e829772a00                       call   0x82f200

; tutorial_page_factory VA 0x588052..0x5880f1 raw 0x187452 SHA256 8b240876e5663ae41e0f7b4573c9992a9b767da0b01acf7d3bd996874c312911
0x588052: 6834020000                       push   0x234
0x588057: e80ca03000                       call   0x892068
0x58805c: 8bf0                             mov    esi,eax
0x58805e: 83c404                           add    esp,0x4
0x588061: 897508                           mov    DWORD PTR [ebp+0x8],esi
0x588064: 33ff                             xor    edi,edi
0x588066: c745fc0f000000                   mov    DWORD PTR [ebp-0x4],0xf
0x58806d: 3bf7                             cmp    esi,edi
0x58806f: 7434                             je     0x5880a5
0x588071: e8ea060100                       call   0x598760
0x588076: c706f4f5c100                     mov    DWORD PTR [esi],0xc1f5f4
0x58807c: 89be1c020000                     mov    DWORD PTR [esi+0x21c],edi
0x588082: 89be20020000                     mov    DWORD PTR [esi+0x220],edi
0x588088: 89be24020000                     mov    DWORD PTR [esi+0x224],edi
0x58808e: 89be28020000                     mov    DWORD PTR [esi+0x228],edi
0x588094: 89be2c020000                     mov    DWORD PTR [esi+0x22c],edi
0x58809a: 89be30020000                     mov    DWORD PTR [esi+0x230],edi
0x5880a0: 897508                           mov    DWORD PTR [ebp+0x8],esi
0x5880a3: eb03                             jmp    0x5880a8
0x5880a5: 897d08                           mov    DWORD PTR [ebp+0x8],edi
0x5880a8: c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x5880af: 8b7b2c                           mov    edi,DWORD PTR [ebx+0x2c]
0x5880b2: 8d45e8                           lea    eax,[ebp-0x18]
0x5880b5: 8d7704                           lea    esi,[edi+0x4]
0x5880b8: 50                               push   eax
0x5880b9: 8d45ec                           lea    eax,[ebp-0x14]
0x5880bc: 8bce                             mov    ecx,esi
0x5880be: c745e80f000000                   mov    DWORD PTR [ebp-0x18],0xf
0x5880c5: e8366e2a00                       call   0x82ef00
0x5880ca: 8b7f08                           mov    edi,DWORD PTR [edi+0x8]
0x5880cd: 397dec                           cmp    DWORD PTR [ebp-0x14],edi
0x5880d0: 751f                             jne    0x5880f1
0x5880d2: 8b4d08                           mov    ecx,DWORD PTR [ebp+0x8]
0x5880d5: 8d7de4                           lea    edi,[ebp-0x1c]
0x5880d8: c745e40f000000                   mov    DWORD PTR [ebp-0x1c],0xf
0x5880df: 894de8                           mov    DWORD PTR [ebp-0x18],ecx
0x5880e2: e8396effff                       call   0x57ef20
0x5880e7: 50                               push   eax
0x5880e8: 56                               push   esi
0x5880e9: 8d75e4                           lea    esi,[ebp-0x1c]
0x5880ec: e80f712a00                       call   0x82f200

; mission_lobby_event_override VA 0x5b0720..0x5b075d raw 0x1afb20 SHA256 30d2ecb59a003f81568bdcf2f5d476a574e41c2030d5516ec72ec2937873a734
0x5b0720: 55                               push   ebp
0x5b0721: 8bec                             mov    ebp,esp
0x5b0723: 56                               push   esi
0x5b0724: 57                               push   edi
0x5b0725: 8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x5b0728: 57                               push   edi
0x5b0729: 8bf1                             mov    esi,ecx
0x5b072b: e850780000                       call   0x5b7f80
0x5b0730: 8b4710                           mov    eax,DWORD PTR [edi+0x10]
0x5b0733: 2d9e430f00                       sub    eax,0xf439e
0x5b0738: 7417                             je     0x5b0751
0x5b073a: 83e866                           sub    eax,0x66
0x5b073d: 7518                             jne    0x5b0757
0x5b073f: 8b86fc020000                     mov    eax,DWORD PTR [esi+0x2fc]
0x5b0745: 50                               push   eax
0x5b0746: e8f5271000                       call   0x6b2f40
0x5b074b: 5f                               pop    edi
0x5b074c: 5e                               pop    esi
0x5b074d: 5d                               pop    ebp
0x5b074e: c20400                           ret    0x4
0x5b0751: 56                               push   esi
0x5b0752: e8e9010000                       call   0x5b0940
0x5b0757: 5f                               pop    edi
0x5b0758: 5e                               pop    esi
0x5b0759: 5d                               pop    ebp
0x5b075a: c20400                           ret    0x4

; tutorial_page_event_override VA 0x5c3370..0x5c33ac raw 0x1c2770 SHA256 ad0f4a37891aac57f283d3a5b80f4b252fee210362729c159b15a8e18a5767ab
0x5c3370: 55                               push   ebp
0x5c3371: 8bec                             mov    ebp,esp
0x5c3373: 56                               push   esi
0x5c3374: 57                               push   edi
0x5c3375: 8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x5c3378: 57                               push   edi
0x5c3379: 8bf1                             mov    esi,ecx
0x5c337b: e8008afdff                       call   0x59bd80
0x5c3380: 8b4710                           mov    eax,DWORD PTR [edi+0x10]
0x5c3383: 2dda430f00                       sub    eax,0xf43da
0x5c3388: 7417                             je     0x5c33a1
0x5c338a: 83e823                           sub    eax,0x23
0x5c338d: 7517                             jne    0x5c33a6
0x5c338f: 8b8e28020000                     mov    ecx,DWORD PTR [esi+0x228]
0x5c3395: 57                               push   edi
0x5c3396: e8d5cd0f00                       call   0x6c0170
0x5c339b: 5f                               pop    edi
0x5c339c: 5e                               pop    esi
0x5c339d: 5d                               pop    ebp
0x5c339e: c20400                           ret    0x4
0x5c33a1: e86a020000                       call   0x5c3610
0x5c33a6: 5f                               pop    edi
0x5c33a7: 5e                               pop    esi
0x5c33a8: 5d                               pop    ebp
0x5c33a9: c20400                           ret    0x4

; ordinary_mission_page_event VA 0x5ad630..0x5ad68e raw 0x1aca30 SHA256 17e0ce3e303ef36fd9d52899d48f5f8bc582fb2a4b932bdffafb7f4e378b193c
0x5ad630: 55                               push   ebp
0x5ad631: 8bec                             mov    ebp,esp
0x5ad633: 56                               push   esi
0x5ad634: 57                               push   edi
0x5ad635: 8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x5ad638: 57                               push   edi
0x5ad639: 8bf1                             mov    esi,ecx
0x5ad63b: e840e7feff                       call   0x59bd80
0x5ad640: 817f1006440f00                   cmp    DWORD PTR [edi+0x10],0xf4406
0x5ad647: 7506                             jne    0x5ad64f
0x5ad649: 56                               push   esi
0x5ad64a: e891f0ffff                       call   0x5ac6e0
0x5ad64f: 8b4710                           mov    eax,DWORD PTR [edi+0x10]
0x5ad652: 2d63430f00                       sub    eax,0xf4363
0x5ad657: 742a                             je     0x5ad683
0x5ad659: 83e83e                           sub    eax,0x3e
0x5ad65c: 7418                             je     0x5ad676
0x5ad65e: 2d86000000                       sub    eax,0x86
0x5ad663: 7523                             jne    0x5ad688
0x5ad665: 8b8e48020000                     mov    ecx,DWORD PTR [esi+0x248]
0x5ad66b: e8d014ebff                       call   0x45eb40
0x5ad670: 5f                               pop    edi
0x5ad671: 5e                               pop    esi
0x5ad672: 5d                               pop    ebp
0x5ad673: c20400                           ret    0x4
0x5ad676: 8bf7                             mov    esi,edi
0x5ad678: e8a3faffff                       call   0x5ad120
0x5ad67d: 5f                               pop    edi
0x5ad67e: 5e                               pop    esi
0x5ad67f: 5d                               pop    ebp
0x5ad680: c20400                           ret    0x4
0x5ad683: e838feffff                       call   0x5ad4c0
0x5ad688: 5f                               pop    edi
0x5ad689: 5e                               pop    esi
0x5ad68a: 5d                               pop    ebp
0x5ad68b: c20400                           ret    0x4

; ordinary_scenario_page_event VA 0x5afe70..0x5afeae raw 0x1af270 SHA256 b8c2f624756ec75e5ddb37e99e042b3cb0f277401ef245a72901504dc673f142
0x5afe70: 55                               push   ebp
0x5afe71: 8bec                             mov    ebp,esp
0x5afe73: 56                               push   esi
0x5afe74: 57                               push   edi
0x5afe75: 8b7d08                           mov    edi,DWORD PTR [ebp+0x8]
0x5afe78: 57                               push   edi
0x5afe79: 8bf1                             mov    esi,ecx
0x5afe7b: e800bffeff                       call   0x59bd80
0x5afe80: 817f1006440f00                   cmp    DWORD PTR [edi+0x10],0xf4406
0x5afe87: 7506                             jne    0x5afe8f
0x5afe89: 56                               push   esi
0x5afe8a: e851c8ffff                       call   0x5ac6e0
0x5afe8f: 817f1001440f00                   cmp    DWORD PTR [edi+0x10],0xf4401
0x5afe96: 7510                             jne    0x5afea8
0x5afe98: 8b4714                           mov    eax,DWORD PTR [edi+0x14]
0x5afe9b: 8b8e2c020000                     mov    ecx,DWORD PTR [esi+0x22c]
0x5afea1: 50                               push   eax
0x5afea2: 51                               push   ecx
0x5afea3: e8e8a91000                       call   0x6ba890
0x5afea8: 5f                               pop    edi
0x5afea9: 5e                               pop    esi
0x5afeaa: 5d                               pop    ebp
0x5afeab: c20400                           ret    0x4

; lobby_yes_callback VA 0x5b96e0..0x5b979b raw 0x1b8ae0 SHA256 21433da3b515c543e5ae587000a8d951f2539d7fa9b797809eecafea6fbffccf
0x5b96e0: 55                               push   ebp
0x5b96e1: 8bec                             mov    ebp,esp
0x5b96e3: 6aff                             push   0xffffffff
0x5b96e5: 686c739400                       push   0x94736c
0x5b96ea: 64a100000000                     mov    eax,fs:0x0
0x5b96f0: 50                               push   eax
0x5b96f1: 53                               push   ebx
0x5b96f2: a1201fd600                       mov    eax,ds:0xd61f20
0x5b96f7: 33c5                             xor    eax,ebp
0x5b96f9: 50                               push   eax
0x5b96fa: 8d45f4                           lea    eax,[ebp-0xc]
0x5b96fd: 64a300000000                     mov    fs:0x0,eax
0x5b9703: bb01000000                       mov    ebx,0x1
0x5b9708: 841dd4f3fd00                     test   BYTE PTR ds:0xfdf3d4,bl
0x5b970e: 7526                             jne    0x5b9736
0x5b9710: 091dd4f3fd00                     or     DWORD PTR ds:0xfdf3d4,ebx
0x5b9716: c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x5b971d: e85eac1300                       call   0x6f4380
0x5b9722: 68d0e6bc00                       push   0xbce6d0
0x5b9727: e8ee8b2d00                       call   0x89231a
0x5b972c: 83c404                           add    esp,0x4
0x5b972f: c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x5b9736: 6840ddc000                       push   0xc0dd40
0x5b973b: 6a00                             push   0x0
0x5b973d: 68c8f3fd00                       push   0xfdf3c8
0x5b9742: e85939efff                       call   0x4ad0a0
0x5b9747: 8b8684020000                     mov    eax,DWORD PTR [esi+0x284]
0x5b974d: 50                               push   eax
0x5b974e: 56                               push   esi
0x5b974f: e8acd6fdff                       call   0x596e00
0x5b9754: 841dd4adfa00                     test   BYTE PTR ds:0xfaadd4,bl
0x5b975a: 7522                             jne    0x5b977e
0x5b975c: 091dd4adfa00                     or     DWORD PTR ds:0xfaadd4,ebx
0x5b9762: 895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x5b9765: e816ddfcff                       call   0x587480
0x5b976a: 68c0ccbc00                       push   0xbcccc0
0x5b976f: e8a68b2d00                       call   0x89231a
0x5b9774: 83c404                           add    esp,0x4
0x5b9777: c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x5b977e: 6858430f00                       push   0xf4358
0x5b9783: e84813fdff                       call   0x58aad0
0x5b9788: 83c404                           add    esp,0x4
0x5b978b: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x5b978e: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x5b9795: 59                               pop    ecx
0x5b9796: 5b                               pop    ebx
0x5b9797: 8be5                             mov    esp,ebp
0x5b9799: 5d                               pop    ebp
0x5b979a: c3                               ret

; tutorial_yes_callback VA 0x5c3610..0x5c36cb raw 0x1c2a10 SHA256 48823fed271f423d2c6f4b47d758a15a6820d5d083f8785c96d727482cd480aa
0x5c3610: 55                               push   ebp
0x5c3611: 8bec                             mov    ebp,esp
0x5c3613: 6aff                             push   0xffffffff
0x5c3615: 686c739400                       push   0x94736c
0x5c361a: 64a100000000                     mov    eax,fs:0x0
0x5c3620: 50                               push   eax
0x5c3621: 53                               push   ebx
0x5c3622: a1201fd600                       mov    eax,ds:0xd61f20
0x5c3627: 33c5                             xor    eax,ebp
0x5c3629: 50                               push   eax
0x5c362a: 8d45f4                           lea    eax,[ebp-0xc]
0x5c362d: 64a300000000                     mov    fs:0x0,eax
0x5c3633: bb01000000                       mov    ebx,0x1
0x5c3638: 841dd4f3fd00                     test   BYTE PTR ds:0xfdf3d4,bl
0x5c363e: 7526                             jne    0x5c3666
0x5c3640: 091dd4f3fd00                     or     DWORD PTR ds:0xfdf3d4,ebx
0x5c3646: c745fc00000000                   mov    DWORD PTR [ebp-0x4],0x0
0x5c364d: e82e0d1300                       call   0x6f4380
0x5c3652: 68d0e6bc00                       push   0xbce6d0
0x5c3657: e8beec2c00                       call   0x89231a
0x5c365c: 83c404                           add    esp,0x4
0x5c365f: c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x5c3666: 6840ddc000                       push   0xc0dd40
0x5c366b: 6a00                             push   0x0
0x5c366d: 68c8f3fd00                       push   0xfdf3c8
0x5c3672: e8299aeeff                       call   0x4ad0a0
0x5c3677: 8b862c020000                     mov    eax,DWORD PTR [esi+0x22c]
0x5c367d: 50                               push   eax
0x5c367e: 56                               push   esi
0x5c367f: e87c37fdff                       call   0x596e00
0x5c3684: 841dd4adfa00                     test   BYTE PTR ds:0xfaadd4,bl
0x5c368a: 7522                             jne    0x5c36ae
0x5c368c: 091dd4adfa00                     or     DWORD PTR ds:0xfaadd4,ebx
0x5c3692: 895dfc                           mov    DWORD PTR [ebp-0x4],ebx
0x5c3695: e8e63dfcff                       call   0x587480
0x5c369a: 68c0ccbc00                       push   0xbcccc0
0x5c369f: e876ec2c00                       call   0x89231a
0x5c36a4: 83c404                           add    esp,0x4
0x5c36a7: c745fcffffffff                   mov    DWORD PTR [ebp-0x4],0xffffffff
0x5c36ae: 6858430f00                       push   0xf4358
0x5c36b3: e81874fcff                       call   0x58aad0
0x5c36b8: 83c404                           add    esp,0x4
0x5c36bb: 8b4df4                           mov    ecx,DWORD PTR [ebp-0xc]
0x5c36be: 64890d00000000                   mov    DWORD PTR fs:0x0,ecx
0x5c36c5: 59                               pop    ecx
0x5c36c6: 5b                               pop    ebx
0x5c36c7: 8be5                             mov    esp,ebp
0x5c36c9: 5d                               pop    ebp
0x5c36ca: c3                               ret
