
/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b0640(int param_1,uint param_2)

{
  ushort *puVar1;
  char cVar2;
  bool bVar3;
  undefined *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  uint uVar10;
  int extraout_ECX;
  int extraout_ECX_00;
  undefined2 uVar11;
  int *piVar12;
  ushort *puVar13;
  undefined1 *puVar14;
  float10 fVar15;
  undefined4 local_1d4;
  undefined4 local_1d0;
  undefined4 *******local_1cc;
  undefined4 *******local_1c8;
  undefined *local_1c4;
  undefined1 auStack_1ac [4];
  undefined4 *******local_1a8;
  undefined *local_1a4;
  float local_1a0;
  undefined1 *local_19c;
  char local_195;
  int local_194;
  float local_190;
  float local_18c;
  uint local_188;
  uint local_184;
  float local_180;
  int local_17c;
  int local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  int local_164;
  undefined4 *******local_160;
  undefined *local_15c;
  undefined4 local_158;
  char *local_154;
  undefined4 local_150;
  int local_14c;
  undefined4 local_148;
  undefined4 local_144;
  char *local_140;
  undefined4 local_13c;
  undefined4 local_138;
  undefined4 local_134;
  undefined4 local_130;
  char *local_12c;
  undefined4 local_128;
  undefined4 local_124;
  undefined4 local_120;
  undefined4 local_11c;
  char *local_118;
  undefined4 local_114;
  int local_110;
  undefined4 local_10c;
  undefined4 *******local_108;
  undefined *local_104;
  float local_100;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00940bbf;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_1ac;
  ExceptionList = &local_14;
  local_178 = param_1;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    local_1c4 = (undefined *)0x4b06b7;
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  uVar6 = DAT_00f93930;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 1;
    FUN_004dec90();
    local_1c4 = (undefined *)0x4b06ec;
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  local_188 = uVar6;
  local_1c4 = (undefined *)0x4b070d;
  FUN_008438c0();
  if ((local_18c == DAT_00fab14c) || (*(int *)((int)local_18c + 0x10) == 0)) {
    local_1c4 = (undefined *)0x4b0729;
    FUN_006edb60();
  }
  else {
    if (param_2 < 2) {
      local_188 = 0;
    }
    else {
      local_188 = (param_2 - 2) / 0xd;
    }
    local_184 = 0;
    if (local_188 != 0) {
      do {
        puVar1 = (ushort *)(local_184 * 0xd + 2 + local_178);
        if ((DAT_00fab22c & 1) == 0) {
          DAT_00fab22c = DAT_00fab22c | 1;
          local_c = 2;
          FUN_004dec90();
          local_1c4 = (undefined *)0x4b07a5;
          _atexit((_func_4879 *)&LAB_00bcce30);
          local_c = 0xffffffff;
        }
        local_19c = (undefined1 *)(uint)*puVar1;
        local_1c4 = (undefined *)0x4b07c9;
        FUN_0082ef00();
        if (local_164 == DAT_00fab13c) {
          local_194 = 0;
        }
        else {
          local_194 = *(int *)(local_164 + 0x10);
        }
        if ((DAT_00fab22c & 1) == 0) {
          DAT_00fab22c = DAT_00fab22c | 1;
          local_c = 3;
          FUN_004dec90();
          local_1c4 = (undefined *)0x4b080f;
          _atexit((_func_4879 *)&LAB_00bcce30);
          local_c = 0xffffffff;
        }
        local_19c = (undefined1 *)(uint)puVar1[1];
        local_1c4 = (undefined *)0x4b0834;
        FUN_0082ef00();
        if (local_17c == DAT_00fab13c) {
          puVar14 = (undefined1 *)0x0;
        }
        else {
          puVar14 = *(undefined1 **)(local_17c + 0x10);
        }
        local_19c = puVar14;
        if (local_194 == 0) {
          local_1c4 = (undefined *)0x4b085c;
          FUN_006edb60();
          goto switchD_004b0b62_caseD_7;
        }
        if (puVar14 == (undefined1 *)0x0) {
          local_1c4 = (undefined *)0x4b0872;
          FUN_006edb60();
          goto switchD_004b0b62_caseD_7;
        }
        uVar6 = *(uint *)(puVar14 + 0x9c);
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c = 4;
          FUN_004e1590();
          local_1c4 = (undefined *)0x4b08aa;
          _atexit((_func_4879 *)&LAB_00bccc80);
          local_c = 0xffffffff;
        }
        if ((uVar6 == DAT_00f93930) && (DAT_00fbab18 != 0)) {
          _DAT_00fbab24 = 0;
          iVar5 = FUN_0040f060();
          *(undefined4 *)(iVar5 + 0xac) = 0x3dcccccd;
        }
        local_1a0 = *(float *)(puVar14 + 0xa8);
        local_1a8 = *(undefined4 ********)(puVar14 + 0xa0);
        local_1a4 = *(undefined **)(puVar14 + 0xa4);
        local_190 = local_1a0;
        local_160 = local_1a8;
        local_15c = local_1a4;
        if ((*(int *)(puVar14 + 0x15c) == 0) || (*(int *)(puVar14 + 0x370) == 0)) {
          local_18c = 0.0;
        }
        else {
          fVar15 = (float10)FUN_007a7100();
          local_18c = (float)fVar15;
        }
        cVar2 = (char)puVar1[2];
        local_180 = local_18c * 0.5 + local_190;
        local_108 = local_160;
        local_104 = local_15c;
        local_100 = local_180;
        if (((cVar2 == '\0') || (cVar2 == '\x02')) || (cVar2 == '\x01')) {
          iVar5 = 0;
          piVar8 = DAT_00fba7a4;
LAB_004b09a8:
          piVar8 = piVar8 + 3;
          if ((*piVar8 == 0) || (*(ushort *)(*piVar8 + 4) != *puVar1)) goto LAB_004b09b4;
          if (iVar5 == -1) goto LAB_004b0a7e;
          if ((DAT_00fab22c & 1) == 0) {
            DAT_00fab22c = DAT_00fab22c | 1;
            local_c = 5;
            FUN_004dec90();
            local_1c4 = (undefined *)0x4b09f5;
            _atexit((_func_4879 *)&LAB_00bcce30);
            local_c = 0xffffffff;
          }
          uVar6 = 0;
          local_195 = '\0';
          if (*(int *)(DAT_00fab134 + 0x24) - *(int *)(DAT_00fab134 + 0x20) >> 1 == 0)
          goto LAB_004b0a7e;
          puVar13 = *(ushort **)(DAT_00fab134 + 0x20);
          do {
            if (*puVar13 == puVar1[1]) {
              local_195 = '\x01';
            }
            uVar6 = uVar6 + 1;
            puVar13 = puVar13 + 1;
          } while (uVar6 < (uint)(*(int *)(DAT_00fab134 + 0x24) - *(int *)(DAT_00fab134 + 0x20) >> 1
                                 ));
          if (local_195 != '\0') {
            iVar5 = FUN_0040f060();
            iVar5 = *(int *)(iVar5 + 4);
            uVar6 = 0;
            uVar10 = *(int *)(iVar5 + 0x24) - *(int *)(iVar5 + 0x20) >> 1;
            puVar14 = local_19c;
            if (uVar10 == 0) goto LAB_004b0a7e;
            puVar13 = *(ushort **)(iVar5 + 0x20);
            do {
              if (*puVar13 == puVar1[1]) {
                *(undefined2 *)(iVar5 + 0x30) = *(undefined2 *)(*(int *)(iVar5 + 0x20) + uVar6 * 2);
                break;
              }
              uVar6 = uVar6 + 1;
              puVar13 = puVar13 + 1;
            } while (uVar6 < uVar10);
          }
        }
LAB_004b0a7e:
        if ((DAT_00fab22c & 1) == 0) {
          DAT_00fab22c = DAT_00fab22c | 1;
          local_c = 6;
          FUN_004dec90();
          local_1c4 = (undefined *)0x4b0aa8;
          _atexit((_func_4879 *)&LAB_00bcce30);
          local_c = 0xffffffff;
        }
        bVar3 = false;
        uVar6 = 0;
        if (*(int *)(DAT_00fab134 + 0x24) - *(int *)(DAT_00fab134 + 0x20) >> 1 != 0) {
          puVar13 = *(ushort **)(DAT_00fab134 + 0x20);
          do {
            if (*puVar13 == puVar1[1]) {
              bVar3 = true;
            }
            uVar6 = uVar6 + 1;
            puVar13 = puVar13 + 1;
          } while (uVar6 < (uint)(*(int *)(DAT_00fab134 + 0x24) - *(int *)(DAT_00fab134 + 0x20) >> 1
                                 ));
          puVar14 = local_19c;
          if (bVar3) {
            if ((char)puVar1[2] == '\x01') {
              *(int *)(puVar1 + 3) = -*(int *)(puVar1 + 3);
            }
            if ((DAT_00f94390 & 1) == 0) {
              DAT_00f94390 = DAT_00f94390 | 1;
              local_c = 7;
              FUN_004e1590();
              local_1c4 = (undefined *)0x4b0b28;
              _atexit((_func_4879 *)&LAB_00bccc80);
              local_c = 0xffffffff;
            }
            DAT_00f942c4 = DAT_00f942c4 + *(int *)(puVar1 + 3);
            puVar14 = local_19c;
            if (DAT_00f942c4 < 0) {
              DAT_00f942c4 = 0;
            }
          }
        }
        switch((char)puVar1[2]) {
        case '\0':
          local_1c8 = (undefined4 *******)(uint)*(ushort *)(puVar14 + 4);
          local_1c4 = (undefined *)(int)*(char *)((int)puVar1 + 5);
          local_1d0 = (uint)((char)*(undefined2 *)(local_194 + 4) == '\x01');
          local_1cc = &local_108;
          local_1d4 = 0x4b0b96;
          local_1d4 = FUN_0049b140();
          FUN_005521d0();
          local_1a0 = local_190 + 7.0;
          *(undefined4 *)(puVar14 + 0x40c) = 0;
          *(undefined4 *)(puVar14 + 0x414) = 6;
          *(undefined4 *)(puVar14 + 0x410) = 6;
          local_1c4 = (undefined *)0x4b0bd2;
          iVar5 = FUN_00545260();
          if (iVar5 == -1) {
            local_1c4 = (undefined *)0x4b0c29;
            iVar5 = FUN_00545260();
            if (iVar5 != -1) {
              local_1c8 = local_1a8;
              local_1c4 = local_1a4;
              local_1cc = (undefined4 *******)0x0;
              local_1d0 = 0x4b0c52;
              FUN_0049b0d0();
              local_1d0 = 0x4b0c5c;
              FUN_007abcd0();
              local_1c4 = &DAT_00c06be0;
              local_1c8 = (undefined4 *******)0x4b0c6a;
              local_1c8 = (undefined4 *******)FUN_0040cf80();
              local_1cc = (undefined4 *******)0x4b0c70;
              FUN_0049d850();
              FUN_00489fe0();
              FUN_00559a50();
              piVar8 = (int *)FUN_00489c60();
              iVar5 = 0;
              piVar12 = piVar8;
              do {
                if (4 < *piVar12) goto LAB_004b0cd6;
                iVar5 = iVar5 + 1;
                piVar12 = piVar12 + 5;
              } while (iVar5 < 0x20);
              iVar5 = 0;
              piVar12 = piVar8;
              do {
                if (*piVar12 == 0) {
                  piVar8 = piVar8 + iVar5 * 5;
                  piVar8[1] = 0;
                  *piVar8 = 4;
                  piVar8[2] = 0x40c00000;
                  piVar8[3] = 0;
                  piVar8[4] = 0;
                  break;
                }
                iVar5 = iVar5 + 1;
                piVar12 = piVar12 + 5;
              } while (iVar5 < 0x20);
            }
          }
          else {
            local_1c8 = local_1a8;
            local_1c4 = local_1a4;
            local_1cc = (undefined4 *******)0x1;
            local_1d0 = 0x4b0bf7;
            FUN_0049b0d0();
            local_1d0 = 0x4b0c01;
            FUN_007abcd0();
            local_1c4 = &DAT_00c06bc0;
            local_1c8 = (undefined4 *******)0x4b0c0f;
            local_1c8 = (undefined4 *******)FUN_0040cf80();
            local_1cc = (undefined4 *******)0x4b0c15;
            FUN_0049d850();
          }
LAB_004b0cd6:
          iVar5 = *(int *)(local_194 + 0x15c);
          if (((iVar5 != 0) && (*(int *)(local_194 + 0x370) != 0)) && (*(int *)(iVar5 + 0xac) != 0))
          {
            (**(code **)(**(int **)(iVar5 + 0xac) + 0x30))();
LAB_004b189a:
            local_1c4 = (undefined *)0x4b18ab;
            FUN_007d28e0();
          }
          goto LAB_004b18ab;
        case '\x01':
          local_110 = (int)*(char *)((int)puVar1 + 5);
          local_1cc = (undefined4 *******)(uint)*(ushort *)(puVar14 + 4);
          local_1c8 = &local_108;
          local_11c = 0;
          local_118 = "HEALEFFECT";
          local_1c4 = (undefined *)0x0;
          local_114 = 0;
          local_10c = 0;
          local_1d0 = 0x4b11d6;
          FUN_0049b140();
          local_1d0 = 0x4b11e4;
          FUN_00551f20();
          local_1a0 = local_190 + 4.0;
          local_1c4 = (undefined *)0x4b1203;
          iVar5 = FUN_00545260();
          if (iVar5 == -1) {
            local_1c4 = (undefined *)0x4b1214;
            iVar5 = FUN_00545260();
            if (iVar5 == -1) break;
          }
          puVar4 = local_1a4;
          cVar2 = *(char *)((int)puVar1 + 5);
          if (cVar2 == '\0') {
            local_1cc = (undefined4 *******)0x2;
LAB_004b1259:
            local_1c8 = local_1a8;
            local_1c4 = local_1a4;
            local_1d0 = 0x4b1264;
            FUN_0049b0d0();
            local_1d0 = 0x4b126e;
            FUN_007abcd0();
          }
          else {
            if (cVar2 == '\x01') {
              local_1cc = (undefined4 *******)0x3;
              goto LAB_004b1259;
            }
            if (cVar2 == '\x02') {
              local_1cc = (undefined4 *******)0x4;
              goto LAB_004b1259;
            }
          }
          local_1c8 = local_1a8;
          local_1c4 = puVar4;
          local_1cc = (undefined4 *******)0x2;
          local_1d0 = 0x4b1286;
          FUN_0049b0d0();
          local_1d0 = 0x4b1290;
          FUN_007abcd0();
          local_1c4 = (undefined *)0x4b1297;
          FUN_005855b0();
          local_1c4 = (undefined *)0x4b129e;
          FUN_00585330();
          FUN_004068f0();
          local_c = 8;
          local_1c4 = (undefined *)0x4b12cf;
          FUN_00402250();
          local_c = CONCAT31(local_c._1_3_,9);
          local_1c4 = (undefined *)0x4b12e4;
          FUN_0040f8c0();
          local_1c4 = (undefined *)0x4b12eb;
          FUN_004d6b30();
          FUN_004fa440();
          local_c = 0xffffffff;
          FUN_004fa440();
          break;
        case '\x02':
          local_1cc = (undefined4 *******)(uint)*(ushort *)(puVar14 + 4);
          local_1c8 = &local_108;
          local_144 = 2;
          local_140 = "CRITICAL";
          local_1c4 = (undefined *)0x0;
          local_13c = 0xffffffff;
          local_138 = 0xffffffff;
          local_134 = 0;
          local_1d0 = 0x4b0f3a;
          FUN_0049b140();
          local_1d0 = 0x4b0f48;
          FUN_00551f20();
          local_1a0 = local_190 + 7.0;
          *(undefined4 *)(puVar14 + 0x40c) = 0;
          *(undefined4 *)(puVar14 + 0x414) = 6;
          *(undefined4 *)(puVar14 + 0x410) = 6;
          local_1c4 = (undefined *)0x4b0f7e;
          iVar5 = FUN_00545260();
          if (iVar5 == -1) {
            local_1c4 = (undefined *)0x4b1067;
            iVar5 = FUN_00545260();
            if (iVar5 != -1) {
              local_1c8 = local_1a8;
              local_1c4 = local_1a4;
              local_1cc = (undefined4 *******)0x5;
              local_1d0 = 0x4b1090;
              FUN_0049b0d0();
              local_1d0 = 0x4b109a;
              FUN_007abcd0();
              local_1c4 = &DAT_00c06c44;
              local_1c8 = (undefined4 *******)0x4b10a8;
              local_1c8 = (undefined4 *******)FUN_0040cf80();
              local_1cc = (undefined4 *******)0x4b10ae;
              FUN_0049d850();
              FUN_00489fe0();
              FUN_00559a50();
              piVar8 = (int *)FUN_00489c60();
              iVar5 = 0;
              piVar12 = piVar8;
              do {
                if (4 < *piVar12) goto LAB_004b1116;
                iVar5 = iVar5 + 1;
                piVar12 = piVar12 + 5;
              } while (iVar5 < 0x20);
              iVar5 = 0;
              piVar12 = piVar8;
              do {
                if (*piVar12 == 0) {
                  piVar8 = piVar8 + iVar5 * 5;
                  *piVar8 = 4;
                  goto LAB_004b10fb;
                }
                iVar5 = iVar5 + 1;
                piVar12 = piVar12 + 5;
              } while (iVar5 < 0x20);
            }
          }
          else {
            local_1c8 = local_1a8;
            local_1c4 = local_1a4;
            local_1cc = (undefined4 *******)0x5;
            local_1d0 = 0x4b0fa7;
            FUN_0049b0d0();
            local_1d0 = 0x4b0fb1;
            FUN_007abcd0();
            local_1c4 = &DAT_00c06c18;
            local_1c8 = (undefined4 *******)0x4b0fbf;
            local_1c8 = (undefined4 *******)FUN_0040cf80();
            local_1cc = (undefined4 *******)0x4b0fc5;
            FUN_0049d850();
            iVar5 = FUN_00489fe0();
            *(undefined4 *)(iVar5 + 0x54) = 0x24;
            *(undefined4 *)(iVar5 + 0x4c) = 0x3f800000;
            *(undefined4 *)(iVar5 + 0x50) = 0x437f0000;
            *(undefined4 *)(iVar5 + 0x74) = 0xe;
            *(undefined4 *)(iVar5 + 0x6c) = 0x3f800000;
            *(undefined4 *)(iVar5 + 0x70) = 0x437f0000;
            iVar5 = FUN_00444ad0();
            if (*(char *)(iVar5 + 0x18d) == '\0') {
              piVar8 = (int *)FUN_00489c60();
              iVar5 = 0;
              piVar12 = piVar8;
              do {
                if (5 < *piVar12) goto LAB_004b1116;
                iVar5 = iVar5 + 1;
                piVar12 = piVar12 + 5;
              } while (iVar5 < 0x20);
              iVar5 = 0;
              piVar12 = piVar8;
LAB_004b1038:
              if (*piVar12 != 0) goto code_r0x004b103c;
              piVar8 = piVar8 + iVar5 * 5;
              *piVar8 = 5;
LAB_004b10fb:
              piVar8[1] = 0;
              piVar8[4] = 0;
              piVar8[3] = 0;
              piVar8[2] = 0x40c00000;
            }
          }
LAB_004b1116:
          iVar5 = *(int *)(puVar14 + 0x15c);
          if (((iVar5 != 0) && (*(int *)(puVar14 + 0x370) != 0)) && (*(int *)(iVar5 + 0xac) != 0)) {
            (**(code **)(**(int **)(iVar5 + 0xac) + 0x30))();
            local_1c4 = (undefined *)0x4b1153;
            FUN_007d28e0();
          }
          if (((*(int *)(local_194 + 0x15c) == 0) || (*(int *)(local_194 + 0x370) == 0)) ||
             (*(int *)(*(int *)(local_194 + 0x15c) + 0xac) == 0)) break;
          goto LAB_004b18c9;
        case '\x03':
          local_1a0 = local_190 + 7.0;
          local_1c4 = (undefined *)0x4b0e79;
          iVar5 = FUN_00545260();
          if (iVar5 == -1) {
            local_1c4 = (undefined *)0x4b0eb5;
            iVar5 = FUN_00545260();
            if (iVar5 != -1) {
              local_1c8 = local_1a8;
              local_1c4 = local_1a4;
              local_1cc = (undefined4 *******)0x4b0edc;
              local_1cc = (undefined4 *******)FUN_0049b0d0();
              local_1d0 = 0x4b0ee7;
              FUN_007ac030();
            }
          }
          else {
            local_1c8 = local_1a8;
            local_1c4 = local_1a4;
            local_1cc = (undefined4 *******)0x4b0e9c;
            local_1cc = (undefined4 *******)FUN_0049b0d0();
            local_1d0 = 0x4b0ea4;
            FUN_007ac030();
          }
          break;
        case '\x04':
          local_1cc = (undefined4 *******)(uint)*(ushort *)(puVar14 + 4);
          local_128 = 0xffffffff;
          local_124 = 0xffffffff;
          local_1c8 = &local_108;
          local_1c4 = (undefined *)0x0;
          local_130 = 2;
          local_12c = "BLOCK";
          local_120 = 0;
          local_1d0 = 0x4b0d62;
          FUN_0049b140();
          local_1d0 = 0x4b0d70;
          FUN_00551f20();
          local_1a0 = local_190 + 7.0;
          *(undefined4 *)(puVar14 + 0x40c) = 0;
          *(undefined4 *)(puVar14 + 0x414) = 6;
          *(undefined4 *)(puVar14 + 0x410) = 6;
          local_1c4 = (undefined *)0x4b0da6;
          iVar5 = FUN_00545260();
          if (iVar5 == -1) {
            local_1c4 = (undefined *)0x4b0db7;
            iVar5 = FUN_00545260();
            if (iVar5 != -1) goto LAB_004b0dbc;
          }
          else {
LAB_004b0dbc:
            local_1c8 = local_1a8;
            local_1c4 = local_1a4;
            local_1cc = (undefined4 *******)0x4b0dda;
            local_1cc = (undefined4 *******)FUN_0049b0d0();
            local_1d0 = 0x4b0de5;
            FUN_007ac030();
          }
          iVar5 = *(int *)(puVar14 + 0x15c);
          if (((iVar5 != 0) && (*(int *)(puVar14 + 0x370) != 0)) && (*(int *)(iVar5 + 0xac) != 0)) {
            (**(code **)(**(int **)(iVar5 + 0xac) + 0x30))();
            local_1c4 = (undefined *)0x4b0e22;
            FUN_007d28e0();
          }
          if ((*(int *)(local_194 + 0x15c) == 0) || (*(int *)(local_194 + 0x370) == 0)) break;
          iVar5 = *(int *)(*(int *)(local_194 + 0x15c) + 0xac);
          goto joined_r0x004b0e4a;
        case '\x05':
          local_1a0 = local_190 + 7.0;
          local_1c4 = (undefined *)0x4b15d5;
          iVar5 = FUN_00545260();
          if (iVar5 != -1) {
            cVar2 = *(char *)((int)puVar1 + 5);
            if (cVar2 == '\0') {
              local_1cc = (undefined4 *******)0x0;
LAB_004b1628:
              local_1c4 = local_1a4;
              local_1c8 = local_1a8;
              local_1d0 = 0x4b162d;
              FUN_0049b0d0();
              local_1d0 = 0x4b1637;
              FUN_007abcd0();
            }
            else {
              if (cVar2 == '\x01') {
                local_1cc = (undefined4 *******)0x3;
                goto LAB_004b1628;
              }
              if (cVar2 == '\x02') {
                local_1cc = (undefined4 *******)0x4;
                goto LAB_004b1628;
              }
            }
            local_1c4 = &DAT_00c06c88;
            local_1c8 = (undefined4 *******)0x4b1645;
            local_1c8 = (undefined4 *******)FUN_0040cf80();
            local_1cc = (undefined4 *******)0x4b164b;
            FUN_0049d850();
          }
          if ((*(int *)(puVar14 + 0x15c) != 0) && (*(int *)(puVar14 + 0x370) != 0)) {
            iVar5 = *(int *)(*(int *)(puVar14 + 0x15c) + 0xac);
            goto joined_r0x004b0e4a;
          }
          break;
        case '\x06':
          local_14c = (int)*(char *)((int)puVar1 + 5);
          local_1cc = (undefined4 *******)(uint)*(ushort *)(puVar14 + 4);
          local_1c8 = &local_108;
          local_158 = 0;
          local_154 = "HEALPOTION";
          local_1c4 = (undefined *)0x0;
          local_150 = 0;
          local_148 = 0;
          local_1d0 = 0x4b1352;
          FUN_0049b140();
          local_1d0 = 0x4b135d;
          FUN_00551f20();
          local_1a0 = local_190 + 4.0;
          local_1c4 = (undefined *)0x4b137c;
          iVar5 = FUN_00545260();
          if (iVar5 == -1) {
            local_1c4 = (undefined *)0x4b138d;
            iVar5 = FUN_00545260();
            if (iVar5 == -1) break;
          }
          cVar2 = *(char *)((int)puVar1 + 5);
          if (cVar2 == '\0') {
            local_1c4 = (undefined *)0x4b1511;
            FUN_005855b0();
            local_1c4 = (undefined *)0x4b1518;
            FUN_00585330();
            FUN_004068f0();
            local_c = 10;
            local_1c4 = (undefined *)0x4b1549;
            FUN_00402250();
            local_c = CONCAT31(local_c._1_3_,0xb);
            local_1c4 = (undefined *)0x4b155e;
            FUN_0040f8c0();
            local_1c4 = (undefined *)0x4b1565;
            FUN_004d6b30();
            FUN_004fa440();
            local_c = 0xffffffff;
            FUN_004fa440();
            local_1c8 = local_1a8;
            local_1c4 = local_1a4;
            local_1cc = (undefined4 *******)0x2;
            local_1d0 = 0x4b15a8;
            FUN_0049b0d0();
            local_1d0 = 0x4b15b2;
            FUN_007abcd0();
          }
          else if (cVar2 == '\x01') {
            local_1c4 = (undefined *)0x4b1464;
            FUN_005855b0();
            local_1c4 = (undefined *)0x4b146b;
            FUN_00585330();
            FUN_004068f0();
            local_c = 0xc;
            local_1c4 = (undefined *)0x4b149c;
            FUN_00402250();
            local_c = CONCAT31(local_c._1_3_,0xd);
            local_1c4 = (undefined *)0x4b14b1;
            FUN_0040f8c0();
            local_1c4 = (undefined *)0x4b14b8;
            FUN_004d6b30();
            FUN_004fa440();
            local_c = 0xffffffff;
            FUN_004fa440();
            local_1c8 = local_1a8;
            local_1c4 = local_1a4;
            local_1cc = (undefined4 *******)0x3;
            local_1d0 = 0x4b14fb;
            FUN_0049b0d0();
            local_1d0 = 0x4b1505;
            FUN_007abcd0();
          }
          else if (cVar2 == '\x02') {
            local_1c4 = (undefined *)0x4b13b7;
            FUN_005855b0();
            local_1c4 = (undefined *)0x4b13be;
            FUN_00585330();
            FUN_004068f0();
            local_c = 0xe;
            local_1c4 = (undefined *)0x4b13ef;
            FUN_00402250();
            local_c = CONCAT31(local_c._1_3_,0xf);
            local_1c4 = (undefined *)0x4b1404;
            FUN_0040f8c0();
            local_1c4 = (undefined *)0x4b140b;
            FUN_004d6b30();
            FUN_004fa440();
            local_c = 0xffffffff;
            FUN_004fa440();
            local_1c8 = local_1a8;
            local_1c4 = local_1a4;
            local_1cc = (undefined4 *******)0x4;
            local_1d0 = 0x4b144e;
            FUN_0049b0d0();
            local_1d0 = 0x4b1458;
            FUN_007abcd0();
          }
          break;
        case '\b':
          local_1c8 = (undefined4 *******)(uint)*(ushort *)(puVar14 + 4);
          local_1c4 = (undefined *)(int)*(char *)((int)puVar1 + 5);
          local_1d0 = (uint)((char)*(undefined2 *)(local_194 + 4) == '\x01');
          local_1cc = &local_108;
          local_1d4 = 0x4b16a0;
          local_1d4 = FUN_0049b140();
          FUN_005521d0();
          local_1a0 = local_190 + 7.0;
          *(undefined4 *)(puVar14 + 0x414) = 6;
          *(undefined4 *)(puVar14 + 0x410) = 6;
          *(undefined4 *)(puVar14 + 0x40c) = 0;
          local_1c4 = (undefined *)0x4b16e0;
          iVar5 = FUN_00545260();
          if (iVar5 == -1) {
            local_1c4 = (undefined *)0x4b1737;
            iVar7 = FUN_00545260();
            iVar5 = extraout_ECX_00;
            if (iVar7 != -1) {
              local_1c8 = local_1a8;
              local_1c4 = local_1a4;
              local_1cc = (undefined4 *******)0x0;
              local_1d0 = 0x4b1760;
              FUN_0049b0d0();
              local_1d0 = 0x4b176a;
              FUN_007abcd0();
              local_1c4 = &DAT_00c06be0;
              local_1c8 = (undefined4 *******)0x4b1778;
              local_1c8 = (undefined4 *******)FUN_0040cf80();
              local_1cc = (undefined4 *******)0x4b177e;
              FUN_0049d850();
              FUN_00489fe0();
              FUN_00559a50();
              piVar8 = (int *)FUN_00489c60();
              iVar5 = 0;
              piVar12 = piVar8;
              do {
                if (4 < *piVar12) goto LAB_004b17e6;
                iVar5 = iVar5 + 1;
                piVar12 = piVar12 + 5;
              } while (iVar5 < 0x20);
              iVar7 = 0;
              piVar12 = piVar8;
              do {
                if (*piVar12 == 0) {
                  iVar5 = iVar7 * 5;
                  piVar8 = piVar8 + iVar7 * 5;
                  piVar8[1] = 0;
                  *piVar8 = 4;
                  piVar8[2] = 0x40c00000;
                  piVar8[3] = 0;
                  piVar8[4] = 0;
                  break;
                }
                iVar5 = iVar7 + 1;
                piVar12 = piVar12 + 5;
                iVar7 = iVar5;
              } while (iVar5 < 0x20);
            }
          }
          else {
            local_1c8 = local_1a8;
            local_1c4 = local_1a4;
            local_1cc = (undefined4 *******)0x1;
            local_1d0 = 0x4b1705;
            FUN_0049b0d0();
            local_1d0 = 0x4b170f;
            FUN_007abcd0();
            local_1c4 = &DAT_00c06bc0;
            local_1c8 = (undefined4 *******)0x4b171d;
            local_1c8 = (undefined4 *******)FUN_0040cf80();
            local_1cc = (undefined4 *******)0x4b1723;
            FUN_0049d850();
            iVar5 = extraout_ECX;
          }
LAB_004b17e6:
          iVar7 = local_194;
          uVar11 = (undefined2)((uint)iVar5 >> 0x10);
          local_180 = 0.4;
          local_174 = 0x40000000;
          local_1cc = (undefined4 *******)0x40000000;
          local_170 = 0x3e4ccccd;
          local_1c8 = (undefined4 *******)0x3e4ccccd;
          local_16c = 0x3e4ccccd;
          local_1c4 = (undefined *)0x3e4ccccd;
          local_168 = 0x3f99999a;
          local_1d0 = CONCAT22(uVar11,*(undefined2 *)(puVar14 + 4));
          local_19c = (undefined1 *)&local_1d4;
          local_1d4 = CONCAT22(uVar11,*(undefined2 *)(local_194 + 4));
          uVar9 = FUN_0048a400();
          FUN_006d89c0(uVar9);
          iVar5 = *(int *)(iVar7 + 0x15c);
          if (((iVar5 != 0) && (*(int *)(iVar7 + 0x370) != 0)) && (*(int *)(iVar5 + 0xac) != 0)) {
            (**(code **)(**(int **)(iVar5 + 0xac) + 0x30))();
            goto LAB_004b189a;
          }
LAB_004b18ab:
          if ((*(int *)(puVar14 + 0x15c) != 0) && (*(int *)(puVar14 + 0x370) != 0)) {
            iVar5 = *(int *)(*(int *)(puVar14 + 0x15c) + 0xac);
joined_r0x004b0e4a:
            if (iVar5 != 0) {
LAB_004b18c9:
              local_1c4 = (undefined *)0x4b18d9;
              FUN_007d28e0();
            }
          }
        }
switchD_004b0b62_caseD_7:
        local_184 = local_184 + 1;
      } while (local_184 < local_188);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_1ac);
  return;
LAB_004b09b4:
  iVar5 = iVar5 + 1;
  if (2 < iVar5) goto LAB_004b0a7e;
  goto LAB_004b09a8;
code_r0x004b103c:
  iVar5 = iVar5 + 1;
  piVar12 = piVar12 + 5;
  if (0x1f < iVar5) goto LAB_004b1116;
  goto LAB_004b1038;
}

