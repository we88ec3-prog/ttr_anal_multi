
void FUN_0068e6f0(void)

{
  short sVar1;
  ushort uVar2;
  code *pcVar3;
  uint uVar4;
  undefined1 uVar5;
  int iVar6;
  short *psVar7;
  short *psVar8;
  int iVar9;
  int iVar10;
  ushort *puVar11;
  undefined4 uVar12;
  int in_ECX;
  ushort ******ppppppuVar13;
  uint uVar14;
  ushort *unaff_EBX;
  int *piVar15;
  ushort *puVar16;
  bool bVar17;
  uint uStack_17c;
  uint uStack_174;
  uint uStack_164;
  int iStack_160;
  int iStack_15c;
  uint uStack_158;
  uint uStack_154;
  int local_150;
  int iStack_14c;
  int iStack_148;
  uint auStack_144 [4];
  undefined4 uStack_134;
  uint uStack_130;
  ushort *****apppppuStack_128 [4];
  undefined4 uStack_118;
  uint uStack_114;
  ushort *****apppppuStack_10c [4];
  undefined4 uStack_fc;
  uint uStack_f8;
  ushort *****apppppuStack_f0 [4];
  undefined4 uStack_e0;
  uint uStack_dc;
  uint auStack_d4 [4];
  undefined4 uStack_c4;
  uint uStack_c0;
  uint uStack_b8;
  undefined4 uStack_a8;
  uint uStack_a4;
  undefined4 uStack_9c;
  uint uStack_88;
  undefined4 uStack_80;
  uint uStack_6c;
  undefined4 uStack_64;
  uint uStack_50;
  undefined4 uStack_48;
  uint uStack_34;
  void *pvStack_2c;
  undefined4 uStack_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00945c83;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&uStack_164;
  uStack_174 = DAT_00d61f20 ^ (uint)&stack0xfffffe90;
  ExceptionList = &local_14;
  uVar14 = DAT_00fb1378 & 1;
  *(float *)(in_ECX + 0x1fc) = *(float *)(in_ECX + 0x1fc) + 0.033333335;
  local_150 = in_ECX;
  if (uVar14 == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 0;
    FUN_00539c20();
    uStack_17c = 0x68e770;
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  local_c = 0xffffffff;
  if (DAT_00fb7258 == 0) {
    pcVar3 = *(code **)(**(int **)(in_ECX + 0x118) + 0x94);
    bVar17 = *(int *)(in_ECX + 0x5a4) != 0;
    if (bVar17) {
      uStack_17c = 0x68e8d4;
      (*pcVar3)();
    }
    else {
      uStack_17c = 0x68e8ce;
      (*pcVar3)();
    }
    uStack_17c = (uint)bVar17;
    (**(code **)(**(int **)(in_ECX + 0x110) + 0x94))();
    (**(code **)(**(int **)(in_ECX + 0x10c) + 0x94))(0);
    if (((uint)(*(int **)(in_ECX + 0x118))[10] >> 7 & 1) == 0) {
      (**(code **)(**(int **)(in_ECX + 0x118) + 0x90))(1);
    }
    if (((uint)(*(int **)(in_ECX + 0x11c))[10] >> 7 & 1) != 0) {
      (**(code **)(**(int **)(in_ECX + 0x11c) + 0x90))(0);
    }
    if (((uint)(*(int **)(in_ECX + 0x114))[10] >> 7 & 1) != 0) {
      (**(code **)(**(int **)(in_ECX + 0x114) + 0x90))(0);
    }
  }
  else {
    pcVar3 = *(code **)(**(int **)(in_ECX + 0x10c) + 0x94);
    bVar17 = *(int *)(in_ECX + 0x5a4) != 0;
    if (bVar17) {
      uStack_17c = 0x68e7ac;
      (*pcVar3)();
    }
    else {
      uStack_17c = 0x68e7a6;
      (*pcVar3)();
    }
    uStack_17c = (uint)bVar17;
    (**(code **)(**(int **)(in_ECX + 0x110) + 0x94))();
    (**(code **)(**(int **)(in_ECX + 0x118) + 0x94))(0);
    if (((uint)(*(int **)(in_ECX + 0x118))[10] >> 7 & 1) != 0) {
      (**(code **)(**(int **)(in_ECX + 0x118) + 0x90))(0);
    }
    if (((uint)(*(int **)(in_ECX + 0x11c))[10] >> 7 & 1) == 0) {
      (**(code **)(**(int **)(in_ECX + 0x11c) + 0x90))(1);
    }
    (**(code **)(**(int **)(in_ECX + 0x100) + 0x90))(0);
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_1c = 1;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_1c = 0xffffffff;
    }
    iVar6 = FUN_00539aa0(DAT_00f93930);
    if (iVar6 != 0) {
      if (((byte)((uint)(*(int **)(in_ECX + 0x10c))[10] >> 7) & 1) != *(byte *)(iVar6 + 6)) {
        (**(code **)(**(int **)(in_ECX + 0x10c) + 0x90))(*(byte *)(iVar6 + 6));
      }
      if (((byte)((uint)(*(int **)(in_ECX + 0x114))[10] >> 7) & 1) != *(byte *)(iVar6 + 6)) {
        (**(code **)(**(int **)(in_ECX + 0x114) + 0x90))(*(byte *)(iVar6 + 6));
      }
    }
  }
  iVar6 = *(int *)(*(int *)(in_ECX + 0x134) + 0x24c);
  if (iVar6 == 0) {
LAB_0068e979:
    iVar6 = *(int *)(*(int *)(in_ECX + 0x138) + 0x24c);
    if (iVar6 == 0) goto LAB_0068f4b9;
    iVar6 = *(int *)(iVar6 + 0xcc);
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(iVar6 + 0xdc);
    }
    if ((iVar6 == 0) || (*(int *)(iVar6 + 0x20) == -1)) goto LAB_0068f4b9;
  }
  else {
    iVar6 = *(int *)(iVar6 + 0xcc);
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(iVar6 + 0xdc);
    }
    if ((iVar6 == 0) || (*(int *)(iVar6 + 0x20) == -1)) goto LAB_0068e979;
  }
  uStack_130 = 7;
  uStack_134 = 0;
  auStack_144[0] = auStack_144[0] & 0xffff0000;
  local_1c = 0;
  uStack_158 = 0xffffffff;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_1c = 3;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  if (DAT_00fb7258 != 0) {
    uStack_158 = *(uint *)(DAT_00fb7258 + 0x24);
  }
  uStack_114 = 7;
  uStack_118 = 0;
  apppppuStack_128[0] = (ushort *****)((uint)apppppuStack_128[0] & 0xffff0000);
  uStack_dc = 7;
  uStack_e0 = 0;
  apppppuStack_f0[0] = (ushort *****)((uint)apppppuStack_f0[0] & 0xffff0000);
  uStack_f8 = 7;
  uStack_fc = 0;
  apppppuStack_10c[0] = (ushort *****)((uint)apppppuStack_10c[0] & 0xffff0000);
  local_1c._0_1_ = 6;
  iVar6 = *(int *)(*(int *)(in_ECX + 0x124) + 0xcc);
  if (iVar6 == 0) {
    uStack_154 = 0xffffffff;
  }
  else {
    iVar6 = *(int *)(iVar6 + 0xdc);
    if (iVar6 == 0) {
      uStack_154 = 0xffffffff;
    }
    else {
      uStack_154 = *(uint *)(iVar6 + 0x20);
    }
  }
  unaff_EBX = (ushort *)(in_ECX + 0x230);
  uStack_164 = 0;
  iStack_15c = 0;
  piVar15 = (int *)(in_ECX + 0x184);
  do {
    if ((DAT_00fb1378 & 1) == 0) {
      DAT_00fb1378 = DAT_00fb1378 | 1;
      local_1c._0_1_ = 7;
      FUN_00539c20();
      _atexit((_func_4879 *)&LAB_00bccfb0);
      local_1c._0_1_ = 6;
    }
    if (((uint)((DAT_00fb723c - DAT_00fb7238) / 0x36) <= uStack_164) ||
       (puVar16 = (ushort *)(iStack_15c + DAT_00fb7238), puVar16 == (ushort *)0x0)) {
      FUN_00402160(&DAT_00bed1fc,0);
      FUN_00402160(&DAT_00bed1fc,0);
      FUN_00402160(&DAT_00bed1fc,0);
      uVar14 = 0xffffffff;
      uStack_174 = 0xffffffff;
      iVar6 = 0;
      if (uStack_164 == uStack_154) {
        if (*(int *)(*(int *)(iStack_160 + 0x124) + 0xcc) != 0) {
          FUN_0042c8e0(0xffffffff);
        }
        (**(code **)(*(int *)piVar15[-0x12] + 200))();
      }
      *(uint *)(piVar15[-0x12] + 0x28) = *(uint *)(piVar15[-0x12] + 0x28) | 4;
      goto LAB_0068f0f5;
    }
    iVar6 = -1;
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_1c._0_1_ = 8;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      local_1c._0_1_ = 6;
    }
    psVar7 = (short *)FUN_004f6a30(*(undefined4 *)(puVar16 + 0x17));
    auStack_d4[0] = auStack_d4[0] & 0xffff0000;
    uStack_c0 = 7;
    uStack_c4 = 0;
    psVar8 = psVar7;
    do {
      sVar1 = *psVar8;
      psVar8 = psVar8 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar8 - (int)(psVar7 + 1) >> 1);
    local_1c._0_1_ = 9;
    uVar5 = (undefined1)local_1c;
    local_1c._0_1_ = 9;
    switch((char)puVar16[1]) {
    case '\x01':
      uStack_174 = *(byte *)((int)puVar16 + 3) + 1;
      uVar12 = 0x13b;
      FUN_00585620(0x13b);
      FUN_00585330(uVar12);
      uVar12 = FUN_004068f0();
      local_1c._0_1_ = 10;
      FUN_00402800(uVar12);
      local_1c._0_1_ = 9;
      if (7 < uStack_50) {
        FUN_0089120c(uStack_64);
      }
      break;
    case '\x02':
      uStack_174 = (uint)*(byte *)((int)puVar16 + 3);
      local_1c._0_1_ = uVar5;
      iVar10 = FUN_004a77a0();
      FUN_0050db00(&uStack_174);
      if ((local_150 == *(int *)(iVar10 + 4)) || (local_150 == -0x10)) {
        uVar12 = 0x3e;
        FUN_00585620(0x3e);
        FUN_00585330(uVar12);
      }
      FUN_0041f490(auStack_144);
      uVar14 = (uint)*(byte *)((int)puVar16 + 3);
      uVar12 = FUN_00404ba0(uVar14);
      iVar10 = FUN_004e2e70(uVar12,uVar14);
      if (iVar10 == 0) {
        iVar6 = -0x10000;
      }
      break;
    case '\x03':
      uVar12 = 0x3f;
      local_1c._0_1_ = uVar5;
      FUN_00585620(0x3f);
      psVar7 = (short *)FUN_00585330(uVar12);
      psVar8 = psVar7;
      do {
        sVar1 = *psVar8;
        psVar8 = psVar8 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar7,(int)psVar8 - (int)(psVar7 + 1) >> 1);
      uStack_174 = (uint)*(byte *)((int)puVar16 + 3);
      iVar10 = FUN_004452c0();
      FUN_008438c0(&uStack_174);
      if ((iStack_148 != *(int *)(iVar10 + 4)) &&
         (iVar10 = *(int *)(iStack_148 + 0x10), iVar10 != -8)) {
        FUN_00404ba0();
        iVar9 = FUN_004d43d0();
        if (iVar9 < (int)(uint)*(byte *)(iVar10 + 0xc)) {
          iVar6 = -0x10000;
        }
      }
      break;
    default:
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_1c._0_1_ = 0xe;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
      }
      local_1c._0_1_ = 9;
      uStack_174 = 0x32c;
      FUN_005740f0(&uStack_174);
      if (iStack_14c == DAT_00fe5ac8) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      if (*(uint *)(iStack_14c + 0x24) < 8) {
        psVar8 = (short *)(iStack_14c + 0x10);
      }
      else {
        psVar8 = *(short **)(iStack_14c + 0x10);
      }
      psVar7 = psVar8;
      do {
        sVar1 = *psVar7;
        psVar7 = psVar7 + 1;
      } while (sVar1 != 0);
      iVar10 = (int)psVar7 - (int)(psVar8 + 1);
      goto LAB_0068ef93;
    case '\x05':
      uVar12 = 0x41;
      FUN_00585620(0x41);
      psVar8 = (short *)FUN_00585330(uVar12);
      psVar7 = psVar8;
      do {
        sVar1 = *psVar7;
        psVar7 = psVar7 + 1;
      } while (sVar1 != 0);
      iVar10 = (int)psVar7 - (int)(psVar8 + 1);
LAB_0068ef93:
      FUN_00402160(psVar8,iVar10 >> 1);
      break;
    case '\t':
      uStack_174 = *(byte *)((int)puVar16 + 3) + 1;
      uVar12 = 0x13d;
      local_1c._0_1_ = uVar5;
      FUN_00585620(0x13d);
      FUN_00585330(uVar12);
      uVar12 = FUN_004068f0();
      local_1c._0_1_ = 0xc;
      FUN_00402800(uVar12);
      local_1c._0_1_ = 9;
      if (7 < uStack_6c) {
        FUN_0089120c(uStack_80);
      }
      break;
    case '\n':
    case '\v':
      uStack_174 = *(byte *)((int)puVar16 + 3) + 1;
      uVar12 = 0x13c;
      local_1c._0_1_ = uVar5;
      FUN_00585620(0x13c);
      FUN_00585330(uVar12);
      uVar12 = FUN_004068f0();
      local_1c._0_1_ = 0xb;
      FUN_00402800(uVar12);
      local_1c._0_1_ = 9;
      if (7 < uStack_88) {
        FUN_0089120c(uStack_9c);
      }
      break;
    case '\r':
      uStack_174 = *(byte *)((int)puVar16 + 3) + 1;
      uVar12 = 0x46;
      local_1c._0_1_ = uVar5;
      FUN_00585620(0x46);
      FUN_00585330(uVar12);
      uVar12 = FUN_004068f0();
      local_1c._0_1_ = 0xd;
      FUN_00402800(uVar12);
      local_1c._0_1_ = 9;
      if (7 < uStack_34) {
        FUN_0089120c(uStack_48);
      }
      break;
    case '\x0e':
      uVar12 = 0x47;
      local_1c._0_1_ = uVar5;
      FUN_00585620(0x47);
      psVar7 = (short *)FUN_00585330(uVar12);
      psVar8 = psVar7;
      do {
        sVar1 = *psVar8;
        psVar8 = psVar8 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar7,(int)psVar8 - (int)(psVar7 + 1) >> 1);
      iVar10 = iStack_160;
      (**(code **)(**(int **)(iStack_160 + 0x10c) + 0x90))(0);
      (**(code **)(**(int **)(iVar10 + 0x108) + 0x90))(0);
      (**(code **)(**(int **)(iVar10 + 0x114) + 0x90))(0);
    }
    if (uStack_158 == *puVar16) {
      iVar6 = -0x3400;
    }
    else if (((char)puVar16[0x1a] != '\0') ||
            ((char)puVar16[0x19] == *(char *)((int)puVar16 + 0x33))) {
      iVar6 = -0x99999a;
    }
    puVar11 = puVar16 + 2;
    do {
      uVar2 = *puVar11;
      puVar11 = puVar11 + 1;
    } while (uVar2 != 0);
    FUN_00402160(puVar16 + 2,(int)puVar11 - (int)(puVar16 + 3) >> 1);
    FUN_004026e0(auStack_144,0,0xffffffff);
    FUN_004026e0(auStack_d4,0,0xffffffff);
    uStack_174 = (uint)*(byte *)((int)puVar16 + 0x33);
    uVar14 = (uint)(byte)puVar16[0x19];
    uVar4 = *(uint *)(piVar15[-0x12] + 0x28);
    if ((uVar4 & 4) != 0) {
      *(uint *)(piVar15[-0x12] + 0x28) = uVar4 ^ 4;
    }
    local_1c._0_1_ = 6;
    if (7 < uStack_c0) {
      FUN_0089120c(auStack_d4[0]);
    }
LAB_0068f0f5:
    ppppppuVar13 = (ushort ******)apppppuStack_128[0];
    if (uStack_114 < 8) {
      ppppppuVar13 = apppppuStack_128;
    }
    puVar16 = unaff_EBX;
    if (7 < *(uint *)(unaff_EBX + 10)) {
      puVar16 = *(ushort **)unaff_EBX;
    }
    do {
      uVar2 = *puVar16;
      bVar17 = uVar2 < *(ushort *)ppppppuVar13;
      if (uVar2 != *(ushort *)ppppppuVar13) {
LAB_0068f138:
        iVar10 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
        goto LAB_0068f13d;
      }
      if (uVar2 == 0) break;
      uVar2 = puVar16[1];
      bVar17 = uVar2 < *(ushort *)((int)ppppppuVar13 + 2);
      if (uVar2 != *(ushort *)((int)ppppppuVar13 + 2)) goto LAB_0068f138;
      ppppppuVar13 = ppppppuVar13 + 1;
      puVar16 = puVar16 + 2;
    } while (uVar2 != 0);
    iVar10 = 0;
LAB_0068f13d:
    if (iVar10 == 0) {
      ppppppuVar13 = (ushort ******)apppppuStack_f0[0];
      if (uStack_dc < 8) {
        ppppppuVar13 = apppppuStack_f0;
      }
      if (*(uint *)(unaff_EBX + 0x88) < 8) {
        puVar16 = unaff_EBX + 0x7e;
      }
      else {
        puVar16 = *(ushort **)(unaff_EBX + 0x7e);
      }
      do {
        uVar2 = *puVar16;
        bVar17 = uVar2 < *(ushort *)ppppppuVar13;
        if (uVar2 != *(ushort *)ppppppuVar13) {
LAB_0068f198:
          iVar10 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
          goto LAB_0068f19d;
        }
        if (uVar2 == 0) break;
        uVar2 = puVar16[1];
        bVar17 = uVar2 < *(ushort *)((int)ppppppuVar13 + 2);
        if (uVar2 != *(ushort *)((int)ppppppuVar13 + 2)) goto LAB_0068f198;
        puVar16 = puVar16 + 2;
        ppppppuVar13 = ppppppuVar13 + 1;
      } while (uVar2 != 0);
      iVar10 = 0;
LAB_0068f19d:
      if (iVar10 != 0) goto LAB_0068f22d;
      ppppppuVar13 = (ushort ******)apppppuStack_10c[0];
      if (uStack_f8 < 8) {
        ppppppuVar13 = apppppuStack_10c;
      }
      if (*(uint *)(unaff_EBX + 0x106) < 8) {
        puVar16 = unaff_EBX + 0xfc;
      }
      else {
        puVar16 = *(ushort **)(unaff_EBX + 0xfc);
      }
      do {
        uVar2 = *puVar16;
        bVar17 = uVar2 < *(ushort *)ppppppuVar13;
        if (uVar2 != *(ushort *)ppppppuVar13) {
LAB_0068f1f6:
          iVar10 = (1 - (uint)bVar17) - (uint)(bVar17 != 0);
          goto LAB_0068f1fb;
        }
        if (uVar2 == 0) break;
        uVar2 = puVar16[1];
        bVar17 = uVar2 < *(ushort *)((int)ppppppuVar13 + 2);
        if (uVar2 != *(ushort *)((int)ppppppuVar13 + 2)) goto LAB_0068f1f6;
        puVar16 = puVar16 + 2;
        ppppppuVar13 = ppppppuVar13 + 1;
      } while (uVar2 != 0);
      iVar10 = 0;
LAB_0068f1fb:
      if ((((iVar10 != 0) || (piVar15[0xe8] != uVar14)) || (piVar15[0xf1] != uStack_174)) ||
         (piVar15[0xfa] != iVar6)) goto LAB_0068f22d;
    }
    else {
LAB_0068f22d:
      if ((uVar14 == 0xffffffff) || (uStack_174 == 0xffffffff)) {
        FUN_00757710();
        FUN_00757710();
        FUN_00757710();
        FUN_00757710();
      }
      else {
        FUN_00757800(apppppuStack_128);
        FUN_00757800(apppppuStack_f0);
        FUN_00757800(apppppuStack_10c);
        uVar12 = FUN_0040e460(&DAT_00bf2bf8);
        local_1c._0_1_ = 0xf;
        FUN_00757800(uVar12);
        local_1c._0_1_ = 6;
        if (7 < uStack_a4) {
          FUN_0089120c(uStack_b8);
        }
        uStack_b8 = uStack_b8 & 0xffff0000;
        *(int *)(piVar15[-9] + 0x154) = iVar6;
        *(int *)(*piVar15 + 0x154) = iVar6;
        *(int *)(piVar15[9] + 0x154) = iVar6;
        uStack_a4 = 7;
        uStack_a8 = 0;
        *(int *)(piVar15[0x12] + 0x154) = iVar6;
      }
      (**(code **)(*(int *)piVar15[-0x12] + 200))();
      FUN_004026e0(apppppuStack_128,0,0xffffffff);
      FUN_004026e0(apppppuStack_f0,0,0xffffffff);
      FUN_004026e0(apppppuStack_10c,0,0xffffffff);
      piVar15[0xe8] = uVar14;
      piVar15[0xf1] = uStack_174;
      piVar15[0xfa] = iVar6;
    }
    uStack_164 = uStack_164 + 1;
    iStack_15c = iStack_15c + 0x36;
    unaff_EBX = unaff_EBX + 0xe;
    piVar15 = piVar15 + 1;
  } while (iStack_15c < 0x1e6);
  if (7 < uStack_f8) {
    FUN_0089120c(apppppuStack_10c[0]);
  }
  uStack_f8 = 7;
  uStack_fc = 0;
  apppppuStack_10c[0] = (ushort *****)((uint)apppppuStack_10c[0] & 0xffff0000);
  if (7 < uStack_dc) {
    FUN_0089120c(apppppuStack_f0[0]);
  }
  uStack_dc = 7;
  uStack_e0 = 0;
  apppppuStack_f0[0] = (ushort *****)((uint)apppppuStack_f0[0] & 0xffff0000);
  if (7 < uStack_114) {
    FUN_0089120c(apppppuStack_128[0]);
  }
  local_1c = 0xffffffff;
  uStack_114 = 7;
  uStack_118 = 0;
  apppppuStack_128[0] = (ushort *****)((uint)apppppuStack_128[0] & 0xffff0000);
  if (7 < uStack_130) {
    FUN_0089120c(auStack_144[0]);
  }
  uStack_130 = 7;
  uStack_134 = 0;
  auStack_144[0] = auStack_144[0] & 0xffff0000;
  in_ECX = iStack_160;
LAB_0068f4b9:
  (**(code **)(**(int **)(in_ECX + 0xfc) + 0x94))
            (~(byte)(*(uint *)(*(int *)(in_ECX + 0x100) + 0x28) >> 7) & 1);
  (**(code **)(**(int **)(in_ECX + 0xfc) + 0x90))
            (~(byte)(*(uint *)(*(int *)(in_ECX + 0x100) + 0x28) >> 7) & 1);
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    uStack_24 = 0x10;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
    uStack_24 = 0xffffffff;
  }
  iVar6 = DAT_00fb722c;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    uStack_24 = 0x11;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
    uStack_24 = 0xffffffff;
  }
  iVar10 = DAT_00fb7230;
  if ((*(int *)(unaff_EBX + 0x100) != iVar6) || (*(int *)(unaff_EBX + 0x102) != DAT_00fb7230)) {
    FUN_007597b0(0);
    FUN_007597b0(1);
    (**(code **)(**(int **)(unaff_EBX + 0x94) + 200))();
    *(int *)(unaff_EBX + 0x100) = iVar6;
    *(int *)(unaff_EBX + 0x102) = iVar10;
  }
  if (5.0 < *(float *)(unaff_EBX + 0xfe)) {
    if ((DAT_00fb1378 & 1) == 0) {
      DAT_00fb1378 = DAT_00fb1378 | 1;
      uStack_24 = 0x12;
      FUN_00539c20();
      _atexit((_func_4879 *)&LAB_00bccfb0);
      uStack_24 = 0xffffffff;
    }
    FUN_006904b0(DAT_00fb722c);
    unaff_EBX[0xfe] = 0;
    unaff_EBX[0xff] = 0;
  }
  ExceptionList = pvStack_2c;
  __security_check_cookie(uStack_34 ^ (uint)&uStack_17c);
  return;
}

