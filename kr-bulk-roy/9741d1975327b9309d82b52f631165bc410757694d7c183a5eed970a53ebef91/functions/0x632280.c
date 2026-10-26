
void FUN_00632280(int param_1,undefined4 param_2)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  uint uVar4;
  code *pcVar5;
  uint *puVar6;
  int *piVar7;
  int *piVar8;
  short *psVar9;
  int **ppiVar10;
  undefined4 uVar11;
  short *psVar12;
  int iVar13;
  uint *puVar14;
  uint uVar15;
  int iVar16;
  undefined1 auStack_7c [4];
  int *local_78;
  uint local_74;
  int *local_70;
  int *local_6c;
  uint *local_68;
  uint *local_64;
  uint *local_60;
  int *local_58;
  int local_54;
  int *local_50 [2];
  uint local_48;
  undefined4 local_44;
  int *local_40;
  int *piStack_3c;
  uint local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00946604;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_7c;
  ExceptionList = &local_14;
  local_44 = param_2;
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_c = 0;
    FUN_004ffe60(DAT_00d61f20 ^ (uint)&stack0xffffff78);
    _atexit((_func_4879 *)&LAB_00bccf00);
  }
  iVar13 = DAT_00fb114c;
  local_c._0_1_ = 0xff;
  local_c._1_3_ = 0xffffff;
  local_6c = *(int **)(param_1 + 0xfc);
  FUN_00503d20(&local_6c);
  if ((local_70 != *(int **)(iVar13 + 4)) && (local_6c = local_70 + 4, local_70 + 4 != (int *)0x0))
  {
    puVar14 = (uint *)0x0;
    local_68 = (uint *)0x0;
    local_64 = (uint *)0x0;
    local_60 = (uint *)0x0;
    local_c._1_3_ = 0;
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c._0_1_ = 2;
      local_c._1_3_ = 0;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    local_c._0_1_ = 1;
    local_78 = (int *)(DAT_00fab134 + 0x10);
    piVar7 = (int *)((*(int *)(DAT_00fab134 + 0x14) - *(int *)(DAT_00fab134 + 0x10)) / 0x18);
    if (piVar7 != (int *)0x0) {
      iVar13 = 0;
      puVar6 = local_68;
      local_70 = piVar7;
      do {
        uVar15 = *local_78 + iVar13;
        if ((int)*(short *)(*local_78 + 0x14 + iVar13) == *local_6c) {
          local_74 = uVar15;
          if ((&local_74 < puVar14) && (puVar6 <= &local_74)) {
            iVar16 = (int)&local_74 - (int)puVar6;
            if (puVar14 == local_60) {
              FUN_004deab0();
              puVar6 = local_68;
              puVar14 = local_64;
            }
            if (puVar14 != (uint *)0x0) {
              *puVar14 = puVar6[iVar16 >> 2];
            }
          }
          else {
            if (puVar14 == local_60) {
              FUN_004deab0();
              puVar6 = local_68;
              puVar14 = local_64;
            }
            if (puVar14 != (uint *)0x0) {
              *puVar14 = uVar15;
            }
          }
          puVar14 = puVar14 + 1;
          local_64 = puVar14;
        }
        iVar13 = iVar13 + 0x18;
        local_70 = (int *)((int)local_70 + -1);
      } while (local_70 != (int *)0x0);
    }
    local_74 = 0;
    local_48 = (int)puVar14 - (int)local_68 >> 2;
    if (local_48 != 0) {
      do {
        uVar15 = local_68[local_74];
        if ((DAT_00fe5ae4 & 1) == 0) {
          DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
          local_c._0_1_ = 3;
          FUN_00584c40(&DAT_00fe5ac4);
          _atexit((_func_4879 *)&LAB_00bcf390);
          local_c._0_1_ = 1;
        }
        cVar1 = *(char *)(DAT_00fe5ac8[1] + 0x2d);
        piVar7 = (int *)DAT_00fe5ac8[1];
        local_78 = DAT_00fe5ac8;
        while (piVar8 = piVar7, cVar1 == '\0') {
          if (piVar8[3] < 0x166) {
            piVar7 = (int *)piVar8[2];
            piVar8 = local_78;
          }
          else {
            piVar7 = (int *)*piVar8;
          }
          cVar1 = *(char *)((int)piVar7 + 0x2d);
          local_78 = piVar8;
        }
        if ((local_78 == DAT_00fe5ac8) || (0x166 < local_78[3])) {
          local_70 = DAT_00fe5ac8;
          ppiVar10 = &local_70;
        }
        else {
          ppiVar10 = &local_78;
        }
        piVar7 = *ppiVar10;
        if (piVar7 == DAT_00fe5ac8) {
          pcVar5 = (code *)swi(3);
          (*pcVar5)();
          return;
        }
        piVar8 = piVar7 + 4;
        if (7 < (uint)piVar7[9]) {
          piVar8 = (int *)*piVar8;
        }
        piVar7 = piVar8;
        do {
          iVar13 = *piVar7;
          piVar7 = (int *)((int)piVar7 + 2);
        } while ((short)iVar13 != 0);
        FUN_00404300(piVar8,(int)piVar7 - (int)((int)piVar8 + 2) >> 1);
        piVar7 = local_6c;
        switch(*(undefined2 *)(uVar15 + 4)) {
        case 1:
          if ((DAT_00fb75b0 & 1) == 0) {
            DAT_00fb75b0 = DAT_00fb75b0 | 1;
            local_c._0_1_ = 4;
            FUN_004f3d80();
            _atexit((_func_4879 *)&LAB_00bcd1e0);
            local_c._0_1_ = 1;
          }
          local_78 = *(int **)(uVar15 + 0xc);
          iVar13 = FUN_004f7a70();
          if (*(uint *)(iVar13 + 0x30) < 8) {
            psVar12 = (short *)(iVar13 + 0x1c);
          }
          else {
            psVar12 = *(short **)(iVar13 + 0x1c);
          }
          psVar9 = psVar12;
          do {
            sVar3 = *psVar9;
            psVar9 = psVar9 + 1;
          } while (sVar3 != 0);
          FUN_00404300(psVar12,(int)psVar9 - (int)(psVar12 + 1) >> 1);
          if ((DAT_00fe5ae4 & 1) == 0) {
            DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
            local_c._0_1_ = 5;
            FUN_00584c40(&DAT_00fe5ac4);
            _atexit((_func_4879 *)&LAB_00bcf390);
            local_c._0_1_ = 1;
          }
          local_78 = (int *)0x167;
          FUN_005740f0(&local_78);
          if (local_40 == DAT_00fe5ac8) {
            pcVar5 = (code *)swi(3);
            (*pcVar5)();
            return;
          }
          piVar7 = local_40 + 4;
          if (7 < (uint)local_40[9]) {
            piVar7 = (int *)*piVar7;
          }
          piVar8 = piVar7;
          do {
            iVar13 = *piVar8;
            piVar8 = (int *)((int)piVar8 + 2);
          } while ((short)iVar13 != 0);
          FUN_00404300(piVar7,(int)piVar8 - (int)((int)piVar7 + 2) >> 1);
          break;
        case 2:
          if ((DAT_00fe5ae4 & 1) == 0) {
            DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
            local_c._0_1_ = 6;
            FUN_00584c40(&DAT_00fe5ac4);
            _atexit((_func_4879 *)&LAB_00bcf390);
            local_c._0_1_ = 1;
          }
          local_78 = (int *)0x168;
          FUN_005740f0(&local_78);
          if (local_58 == DAT_00fe5ac8) {
            pcVar5 = (code *)swi(3);
            (*pcVar5)();
            return;
          }
          piVar7 = local_58 + 4;
          if (7 < (uint)local_58[9]) {
            piVar7 = (int *)*piVar7;
          }
          piVar8 = piVar7;
          do {
            iVar13 = *piVar8;
            piVar8 = (int *)((int)piVar8 + 2);
          } while ((short)iVar13 != 0);
          FUN_00404300(piVar7,(int)piVar8 - (int)((int)piVar7 + 2) >> 1);
          break;
        case 3:
          uVar2 = *(ushort *)(uVar15 + 0xc);
          if ((DAT_00f8d9a4 & 1) == 0) {
            DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
            local_c._0_1_ = 7;
            FUN_0051c120();
            _atexit((_func_4879 *)&LAB_00bccc90);
            local_c._0_1_ = 1;
          }
          local_78 = (int *)(uint)uVar2;
          FUN_008438c0(&local_78);
          uVar11 = FUN_0040aff0();
          local_c._0_1_ = 8;
          FUN_004041f0(uVar11,0,0xffffffff);
          local_c._0_1_ = 1;
          if (7 < local_24) {
            FUN_0089120c(local_38);
          }
          local_24 = 7;
          local_28 = 0;
          local_38 = local_38 & 0xffff0000;
          if ((DAT_00fe5ae4 & 1) == 0) {
            DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
            local_c._0_1_ = 9;
            FUN_00584c40(&DAT_00fe5ac4);
            _atexit((_func_4879 *)&LAB_00bcf390);
            local_c._0_1_ = 1;
          }
          local_78 = (int *)0x169;
          FUN_005740f0(&local_78);
          if (piStack_3c == DAT_00fe5ac8) {
            pcVar5 = (code *)swi(3);
            (*pcVar5)();
            return;
          }
          piVar7 = piStack_3c + 4;
          if (7 < (uint)piStack_3c[9]) {
            piVar7 = (int *)*piVar7;
          }
          piVar8 = piVar7;
          do {
            iVar13 = *piVar8;
            piVar8 = (int *)((int)piVar8 + 2);
          } while ((short)iVar13 != 0);
          FUN_00404300(piVar7,(int)piVar8 - (int)((int)piVar7 + 2) >> 1);
          break;
        case 4:
          uVar4 = *(uint *)(uVar15 + 0xc);
          if ((DAT_00fb75b0 & 1) == 0) {
            DAT_00fb75b0 = DAT_00fb75b0 | 1;
            local_c._0_1_ = 10;
            FUN_004f3d80();
            _atexit((_func_4879 *)&LAB_00bcd1e0);
            local_c._0_1_ = 1;
          }
          local_78 = (int *)(uVar4 | 0x7000000);
          iVar13 = FUN_004f7a70();
          if (*(uint *)(iVar13 + 0x30) < 8) {
            psVar12 = (short *)(iVar13 + 0x1c);
          }
          else {
            psVar12 = *(short **)(iVar13 + 0x1c);
          }
          psVar9 = psVar12;
          do {
            sVar3 = *psVar9;
            psVar9 = psVar9 + 1;
          } while (sVar3 != 0);
          FUN_00404300(psVar12,(int)psVar9 - (int)(psVar12 + 1) >> 1);
          switch(*(undefined4 *)(uVar15 + 0x10)) {
          case 0:
            uVar11 = 0x16a;
            FUN_00585620(0x16a);
            psVar9 = (short *)FUN_00585330(uVar11);
            psVar12 = psVar9;
            do {
              sVar3 = *psVar12;
              psVar12 = psVar12 + 1;
            } while (sVar3 != 0);
            FUN_00404300(psVar9,(int)psVar12 - (int)(psVar9 + 1) >> 1);
            break;
          case 1:
            uVar11 = 0x16b;
            FUN_00585620(0x16b);
            psVar9 = (short *)FUN_00585330(uVar11);
            psVar12 = psVar9;
            do {
              sVar3 = *psVar12;
              psVar12 = psVar12 + 1;
            } while (sVar3 != 0);
            FUN_00404300(psVar9,(int)psVar12 - (int)(psVar9 + 1) >> 1);
            break;
          case 2:
            uVar11 = 0x16c;
            FUN_00585620(0x16c);
            psVar9 = (short *)FUN_00585330(uVar11);
            psVar12 = psVar9;
            do {
              sVar3 = *psVar12;
              psVar12 = psVar12 + 1;
            } while (sVar3 != 0);
            FUN_00404300(psVar9,(int)psVar12 - (int)(psVar9 + 1) >> 1);
            break;
          case 3:
            uVar11 = 0x16d;
            FUN_00585620(0x16d);
            psVar9 = (short *)FUN_00585330(uVar11);
            psVar12 = psVar9;
            do {
              sVar3 = *psVar12;
              psVar12 = psVar12 + 1;
            } while (sVar3 != 0);
            FUN_00404300(psVar9,(int)psVar12 - (int)(psVar9 + 1) >> 1);
          }
          break;
        case 0xb:
          local_78 = (int *)(uint)*(ushort *)(uVar15 + 2);
          FUN_005740f0(&local_78);
          if (local_54 != piVar7[0x1b]) {
            FUN_004041f0(local_54 + 0x10,0,0xffffffff);
          }
        }
        if ((DAT_00fe5ae4 & 1) == 0) {
          DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
          local_c._0_1_ = 0xb;
          FUN_00584c40(&DAT_00fe5ac4);
          _atexit((_func_4879 *)&LAB_00bcf390);
          local_c._0_1_ = 1;
        }
        cVar1 = *(char *)(DAT_00fe5ac8[1] + 0x2d);
        piVar7 = (int *)DAT_00fe5ac8[1];
        local_78 = DAT_00fe5ac8;
        while (piVar8 = piVar7, cVar1 == '\0') {
          if (piVar8[3] < 0x16e) {
            piVar7 = (int *)piVar8[2];
            piVar8 = local_78;
          }
          else {
            piVar7 = (int *)*piVar8;
          }
          cVar1 = *(char *)((int)piVar7 + 0x2d);
          local_78 = piVar8;
        }
        if ((local_78 == DAT_00fe5ac8) || (0x16e < local_78[3])) {
          local_50[0] = DAT_00fe5ac8;
          ppiVar10 = local_50;
        }
        else {
          ppiVar10 = &local_78;
        }
        piVar7 = *ppiVar10;
        if (piVar7 == DAT_00fe5ac8) {
          pcVar5 = (code *)swi(3);
          (*pcVar5)();
          return;
        }
        piVar8 = piVar7 + 4;
        if (7 < (uint)piVar7[9]) {
          piVar8 = (int *)*piVar8;
        }
        uVar11 = FUN_006332d0(piVar8);
        local_c._0_1_ = 0xc;
        FUN_004041f0(uVar11,0,0xffffffff);
        local_c._0_1_ = 1;
        if (7 < local_24) {
          FUN_0089120c(local_38);
        }
        FUN_00404300(&DAT_00bfb894,1);
        local_74 = local_74 + 1;
      } while (local_74 < local_48);
    }
    if (local_68 != (uint *)0x0) {
      FUN_0089120c(local_68);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_7c);
  return;
}

