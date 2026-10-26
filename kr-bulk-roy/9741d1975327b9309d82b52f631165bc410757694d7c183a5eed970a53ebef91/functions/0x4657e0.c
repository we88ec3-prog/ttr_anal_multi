
/* WARNING: Type propagation algorithm not settling */

void FUN_004657e0(undefined4 param_1)

{
  char cVar1;
  short sVar2;
  int *piVar3;
  char **ppcVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 *******pppppppuVar8;
  short *psVar9;
  undefined4 *puVar10;
  int *piVar11;
  short *psVar12;
  char **ppcVar13;
  int iVar14;
  uint uVar15;
  char *pcVar16;
  uint uVar17;
  char *pcVar18;
  uint *puVar19;
  char *in_stack_00000014;
  uint in_stack_00000018;
  undefined **local_198 [3];
  undefined **local_18c [3];
  undefined **local_180 [3];
  undefined **local_174 [4];
  char *local_164;
  char *local_160;
  int *local_15c;
  char *local_158;
  char *local_154;
  int local_150;
  char *local_14c [2];
  int local_144;
  undefined4 local_140;
  undefined4 local_13c;
  uint local_138;
  undefined4 local_128;
  uint local_124;
  undefined4 local_11c;
  undefined4 local_110;
  undefined4 local_10c;
  undefined1 local_108 [16];
  undefined4 local_f8;
  uint local_e4;
  undefined4 local_c8;
  uint local_b4;
  undefined4 local_ac;
  undefined4 local_9c;
  uint local_98;
  undefined4 local_90;
  undefined4 local_80;
  uint local_7c;
  undefined4 *******local_6c [4];
  undefined4 local_5c;
  uint local_58;
  undefined4 local_50;
  undefined4 local_40;
  uint local_3c;
  int *local_34;
  undefined4 local_30;
  char *local_24;
  undefined4 local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092b45b;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pcVar18 = (char *)0x0;
  local_8 = 0;
  FUN_00465270(local_18);
  local_98 = 7;
  local_9c = 0;
  local_ac = (uint)local_ac._2_2_ << 0x10;
  local_8 = CONCAT31(local_8._1_3_,1);
  local_14c[1] = (char *)0xeeee;
  iVar6 = FUN_00466df0(&param_1,local_14c + 1,1);
  while (iVar6 != -1) {
    local_14c[0] = (char *)(iVar6 + 1);
    local_154 = (char *)FUN_00466df0(&param_1,&DAT_00bf3a70,1);
    if (local_154 == (char *)0xffffffff) {
      uVar7 = FUN_0043f3e0(&param_1);
      local_8._0_1_ = 2;
      FUN_004041f0(uVar7,0,0xffffffff);
      local_8 = CONCAT31(local_8._1_3_,1);
      pcVar18 = local_14c[0];
      if (7 < local_b4) {
        FUN_0089120c(local_c8);
        pcVar18 = local_14c[0];
      }
    }
    else {
      local_14c[1] = (char *)0xeeee;
      local_14c[1] = (char *)FUN_00466df0(&param_1,local_14c + 1,1);
      if (local_14c[1] == (char *)0xffffffff) break;
      FUN_0043f3e0(&param_1);
      local_8._0_1_ = 3;
      FUN_0043f3e0(&param_1);
      local_144 = 0;
      local_140 = 0;
      local_13c = 0;
      local_124 = 7;
      local_128 = 0;
      local_138 = local_138 & 0xffff0000;
      local_11c = 0;
      local_110 = 0;
      local_10c = 0;
      local_8._0_1_ = 5;
      iVar6 = FUN_0044df20(0,L"user",4);
      if (iVar6 == 0) {
        local_140 = 1;
LAB_004659ac:
        if (local_58 < 8) {
          pppppppuVar8 = local_6c;
LAB_004659e9:
          local_13c = FUN_008935e3(pppppppuVar8);
        }
        else {
          pppppppuVar8 = local_6c[0];
          if (local_6c[0] != (undefined4 *******)0x0) goto LAB_004659e9;
          local_13c = 0;
        }
        local_144 = *(int *)(local_150 + 0x180);
        *(int *)(local_150 + 0x180) = local_144 + 1;
        uVar7 = FUN_0043f3e0(&param_1);
        local_8._0_1_ = 7;
        FUN_004041f0(uVar7,0,0xffffffff);
        local_8._0_1_ = 5;
        if (7 < local_b4) {
          FUN_0089120c(local_c8);
        }
        FUN_00440010(1,0xeeec);
        psVar9 = (short *)FUN_0040ef80();
        local_8._0_1_ = 8;
        if (7 < *(uint *)(psVar9 + 10)) {
          psVar9 = *(short **)psVar9;
        }
        psVar12 = psVar9;
        do {
          sVar2 = *psVar12;
          psVar12 = psVar12 + 1;
        } while (sVar2 != 0);
        FUN_00404300(psVar9,(int)psVar12 - (int)(psVar9 + 1) >> 1);
        local_8._0_1_ = 5;
        if (7 < local_b4) {
          FUN_0089120c(local_c8);
        }
        FUN_00440010(1,0xeeed);
        FUN_00466950(local_108);
        iVar6 = local_150 + 0x170;
        local_8 = CONCAT31(local_8._1_3_,9);
        uVar7 = FUN_00466980();
        FUN_00466a50(iVar6,uVar7);
        if (7 < local_e4) {
          FUN_0089120c(local_f8);
        }
        pcVar18 = local_14c[1] + 1;
        if (7 < local_124) {
          FUN_0089120c(local_138);
        }
        if (7 < local_58) {
          FUN_0089120c(local_6c[0]);
        }
      }
      else {
        iVar6 = FUN_0044df20(0,L"product",7);
        if (iVar6 == 0) {
          local_140 = 2;
          goto LAB_004659ac;
        }
        uVar7 = FUN_0043f3e0(&param_1);
        local_8 = CONCAT31(local_8._1_3_,6);
        FUN_004041f0(uVar7,0,0xffffffff);
        if (7 < local_b4) {
          FUN_0089120c(local_c8);
        }
        pcVar18 = local_14c[0];
        if (7 < local_58) {
          FUN_0089120c(local_6c[0]);
        }
      }
      local_8 = CONCAT31(local_8._1_3_,1);
      local_6c[0] = (undefined4 *******)((uint)local_6c[0] & 0xffff0000);
      local_5c = 0;
      local_58 = 7;
      if (7 < local_7c) {
        local_58 = 7;
        local_5c = 0;
        FUN_0089120c(local_90);
      }
    }
    local_14c[1] = (char *)0xeeee;
    iVar6 = FUN_00466df0(&param_1,local_14c + 1,1);
  }
  if (pcVar18 < in_stack_00000014) {
    uVar7 = FUN_0043f3e0(&param_1);
    local_8 = CONCAT31(local_8._1_3_,10);
    FUN_004041f0(uVar7,0,0xffffffff);
    if (7 < local_b4) {
      FUN_0089120c(local_c8);
    }
  }
  local_3c = 7;
  local_40 = 0;
  local_50 = (undefined4 *)((uint)local_50._2_2_ << 0x10);
  local_8._0_1_ = 0xb;
  local_30 = 0;
  local_34 = (int *)FUN_00891268(0x10);
  if (local_34 == (int *)0x0) {
    local_164 = (char *)0x0;
    std::exception::exception((exception *)local_180,&local_164);
    local_180[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_180,&DAT_00c857a8);
  }
  *local_34 = (int)local_34;
  local_34[1] = (int)local_34;
  local_8._0_1_ = 0xc;
  local_20 = 0;
  local_24 = (char *)FUN_00891268(0x24);
  if (local_24 == (char *)0x0) {
    local_160 = (char *)0x0;
    std::exception::exception((exception *)local_18c,&local_160);
    local_18c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_18c,&DAT_00c857a8);
  }
  *(char **)local_24 = local_24;
  *(char **)(local_24 + 4) = local_24;
  *(char **)(local_24 + 8) = local_24;
  local_24[0x20] = '\x01';
  local_24[0x21] = '\x01';
  local_8._0_1_ = 0xd;
  local_7c = 7;
  local_80 = 0;
  local_90 = (uint)local_90._2_2_ << 0x10;
  FUN_004026e0(&local_ac,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,0xe);
  local_40 = 0;
  puVar10 = local_50;
  if (local_3c < 8) {
    puVar10 = &local_50;
  }
  *(undefined2 *)puVar10 = 0;
  piVar11 = (int *)*local_34;
  *local_34 = (int)local_34;
  local_34[1] = (int)local_34;
  local_30 = 0;
  if (piVar11 != local_34) {
    do {
      piVar3 = (int *)*piVar11;
      FUN_0089120c(piVar11);
      piVar11 = piVar3;
    } while (piVar3 != local_34);
  }
  cVar1 = *(char *)((int)*(int **)(local_24 + 4) + 0x21);
  piVar11 = *(int **)(local_24 + 4);
  while (cVar1 == '\0') {
    FUN_008575b0(piVar11[2]);
    piVar3 = (int *)*piVar11;
    FUN_0089120c(piVar11);
    piVar11 = piVar3;
    cVar1 = *(char *)((int)piVar3 + 0x21);
  }
  *(char **)(local_24 + 4) = local_24;
  *(char **)local_24 = local_24;
  *(char **)(local_24 + 8) = local_24;
  local_20 = 0;
  FUN_00759ed0(&local_50,&local_90,0xeeec,0xeeed);
  local_8 = CONCAT31(local_8._1_3_,0xd);
  if (7 < local_7c) {
    FUN_0089120c(local_90);
  }
  local_15c = *(int **)(local_150 + 0x174);
  piVar11 = (int *)*local_15c;
  if (piVar11 != local_15c) {
    do {
      if (piVar11[5] == 1) {
        if ((DAT_00fb75b0 & 1) == 0) {
          DAT_00fb75b0 = DAT_00fb75b0 | 1;
          local_8._0_1_ = 0xf;
          FUN_004f3d80();
          _atexit((_func_4879 *)&LAB_00bcd1e0);
          local_8 = CONCAT31(local_8._1_3_,0xd);
        }
        psVar12 = (short *)FUN_004f6a30(piVar11[6]);
        psVar9 = psVar12;
        do {
          sVar2 = *psVar9;
          psVar9 = psVar9 + 1;
        } while (sVar2 != 0);
        FUN_00402160(psVar12,(int)psVar9 - (int)(psVar12 + 1) >> 1);
      }
      else if (piVar11[5] == 2) {
        if ((DAT_00f8d9a4 & 1) == 0) {
          DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
          local_8._0_1_ = 0x10;
          FUN_0051c120();
          _atexit((_func_4879 *)&LAB_00bccc90);
          local_8 = CONCAT31(local_8._1_3_,0xd);
        }
        cVar1 = (*(char **)(DAT_00f8d91c + 4))[0x15];
        pcVar18 = *(char **)(DAT_00f8d91c + 4);
        local_14c[1] = DAT_00f8d91c;
        while (pcVar16 = pcVar18, cVar1 == '\0') {
          if (*(int *)(pcVar16 + 0xc) < piVar11[6]) {
            pcVar18 = *(char **)(pcVar16 + 8);
            pcVar16 = local_14c[1];
          }
          else {
            pcVar18 = *(char **)pcVar16;
          }
          cVar1 = pcVar18[0x15];
          local_14c[1] = pcVar16;
        }
        if ((local_14c[1] == DAT_00f8d91c) || (piVar11[6] < *(int *)(local_14c[1] + 0xc))) {
          local_154 = DAT_00f8d91c;
          ppcVar13 = &local_154;
        }
        else {
          ppcVar13 = local_14c + 1;
        }
        if ((*ppcVar13 != DAT_00f8d91c) && (iVar6 = *(int *)(*ppcVar13 + 0x10), iVar6 != 0)) {
          FUN_004026e0(iVar6,0,0xffffffff);
        }
      }
      FUN_00759ac0(piVar11[4]);
      uVar15 = piVar11[4];
      cVar1 = (*(char **)(local_24 + 4))[0x21];
      pcVar18 = *(char **)(local_24 + 4);
      local_14c[1] = local_24;
      while (pcVar16 = pcVar18, cVar1 == '\0') {
        if (*(uint *)(pcVar16 + 0xc) < uVar15) {
          pcVar18 = *(char **)(pcVar16 + 8);
          pcVar16 = local_14c[1];
        }
        else {
          pcVar18 = *(char **)pcVar16;
        }
        cVar1 = pcVar18[0x21];
        local_14c[1] = pcVar16;
      }
      if ((local_14c[1] == local_24) || (uVar15 < *(uint *)(local_14c[1] + 0xc))) {
        local_14c[0] = local_24;
        ppcVar13 = local_14c;
      }
      else {
        ppcVar13 = local_14c + 1;
      }
      if (*ppcVar13 == local_24) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(*ppcVar13 + 0x10);
      }
      piVar11[0x11] = iVar6;
      cVar1 = (*(char **)(local_24 + 4))[0x21];
      pcVar18 = *(char **)(local_24 + 4);
      local_14c[1] = local_24;
      while (pcVar16 = pcVar18, cVar1 == '\0') {
        if (*(uint *)(pcVar16 + 0xc) < uVar15) {
          pcVar18 = *(char **)(pcVar16 + 8);
          pcVar16 = local_14c[1];
        }
        else {
          pcVar18 = *(char **)pcVar16;
        }
        cVar1 = pcVar18[0x21];
        local_14c[1] = pcVar16;
      }
      if ((local_14c[1] == local_24) || (uVar15 < *(uint *)(local_14c[1] + 0xc))) {
        local_158 = local_24;
        ppcVar13 = &local_158;
      }
      else {
        ppcVar13 = local_14c + 1;
      }
      if (*ppcVar13 == local_24) {
        iVar14 = 0;
      }
      else {
        iVar14 = *(int *)(*ppcVar13 + 0x14);
      }
      piVar11[0x12] = iVar14;
      piVar11[0xf] = iVar6;
      piVar11[0x10] = iVar14;
      if (*(char *)((int)piVar11 + 0x4d) == '\0') {
        piVar3 = (int *)piVar11[2];
        if (*(char *)((int)piVar3 + 0x4d) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x4d);
          piVar11 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x4d);
            piVar11 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar11[1] + 0x4d);
          piVar5 = (int *)piVar11[1];
          piVar3 = piVar11;
          while ((piVar11 = piVar5, cVar1 == '\0' && (piVar3 == (int *)piVar11[2]))) {
            cVar1 = *(char *)(piVar11[1] + 0x4d);
            piVar5 = (int *)piVar11[1];
            piVar3 = piVar11;
          }
        }
      }
    } while (piVar11 != local_15c);
  }
  iVar6 = local_150;
  FUN_00765af0();
  pcVar18 = (char *)FUN_00891268(0x38);
  local_14c[1] = pcVar18;
  if (pcVar18 == (char *)0x0) {
    pcVar18 = (char *)0x0;
  }
  else {
    pcVar18[0x14] = '\a';
    pcVar18[0x15] = '\0';
    pcVar18[0x16] = '\0';
    pcVar18[0x17] = '\0';
    pcVar18[0x10] = '\0';
    pcVar18[0x11] = '\0';
    pcVar18[0x12] = '\0';
    pcVar18[0x13] = '\0';
    pcVar18[0] = '\0';
    pcVar18[1] = '\0';
    local_8._0_1_ = 0x12;
    pcVar18[0x20] = '\0';
    pcVar18[0x21] = '\0';
    pcVar18[0x22] = '\0';
    pcVar18[0x23] = '\0';
    iVar14 = FUN_00891268(0x10);
    if (iVar14 == 0) {
      local_158 = (char *)0x0;
      std::exception::exception((exception *)local_174,&local_158);
      local_174[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_174,&DAT_00c857a8);
    }
    *(int *)(pcVar18 + 0x1c) = iVar14;
    *(int *)iVar14 = iVar14;
    *(int *)(*(int *)(pcVar18 + 0x1c) + 4) = *(int *)(pcVar18 + 0x1c);
    local_8 = CONCAT31(local_8._1_3_,0x13);
    pcVar18[0x30] = '\0';
    pcVar18[0x31] = '\0';
    pcVar18[0x32] = '\0';
    pcVar18[0x33] = '\0';
    iVar14 = FUN_00891268(0x24);
    if (iVar14 == 0) {
      local_15c = (int *)0x0;
      std::exception::exception((exception *)local_198,(char **)&local_15c);
      local_198[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_198,&DAT_00c857a8);
    }
    *(int *)(pcVar18 + 0x2c) = iVar14;
    *(int *)iVar14 = iVar14;
    *(int *)(*(int *)(pcVar18 + 0x2c) + 4) = *(int *)(pcVar18 + 0x2c);
    *(int *)(*(int *)(pcVar18 + 0x2c) + 8) = *(int *)(pcVar18 + 0x2c);
    *(undefined1 *)(*(int *)(pcVar18 + 0x2c) + 0x20) = 1;
    *(undefined1 *)(*(int *)(pcVar18 + 0x2c) + 0x21) = 1;
  }
  local_8 = CONCAT31(local_8._1_3_,0xd);
  local_14c[0] = pcVar18;
  FUN_00757c60(pcVar18,&local_50,0,local_40,*(undefined4 *)(pcVar18 + 0x10));
  ppcVar13 = *(char ***)(iVar6 + 0x114);
  puVar19 = (uint *)(iVar6 + 0x110);
  if ((local_14c < ppcVar13) && (ppcVar4 = (char **)*puVar19, ppcVar4 <= local_14c)) {
    if (ppcVar13 == *(char ***)(iVar6 + 0x118)) {
      uVar15 = (int)ppcVar13 - (int)ppcVar4 >> 2;
      if (0x3ffffffe < uVar15) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("vector<T> too long");
      }
      uVar15 = uVar15 + 1;
      uVar17 = (int)*(char ***)(iVar6 + 0x118) - (int)ppcVar4 >> 2;
      if (uVar17 < uVar15) {
        if (0x3fffffff - (uVar17 >> 1) < uVar17) {
          uVar17 = 0;
        }
        else {
          uVar17 = uVar17 + (uVar17 >> 1);
        }
        if (uVar17 < uVar15) {
          uVar17 = uVar15;
        }
        FUN_00797980(uVar17);
      }
    }
    if (*(undefined4 **)(iVar6 + 0x114) != (undefined4 *)0x0) {
      **(undefined4 **)(iVar6 + 0x114) =
           *(undefined4 *)(*puVar19 + ((int)local_14c - (int)ppcVar4 >> 2) * 4);
    }
  }
  else {
    if (ppcVar13 == *(char ***)(iVar6 + 0x118)) {
      uVar15 = (int)((int)ppcVar13 - *puVar19) >> 2;
      if (0x3ffffffe < uVar15) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("vector<T> too long");
      }
      uVar15 = uVar15 + 1;
      uVar17 = (int)((int)*(char ***)(iVar6 + 0x118) - *puVar19) >> 2;
      if (uVar17 < uVar15) {
        if (0x3fffffff - (uVar17 >> 1) < uVar17) {
          uVar17 = 0;
        }
        else {
          uVar17 = uVar17 + (uVar17 >> 1);
        }
        if (uVar17 < uVar15) {
          uVar17 = uVar15;
        }
        FUN_00797980(uVar17);
      }
    }
    if (*(undefined4 **)(iVar6 + 0x114) != (undefined4 *)0x0) {
      **(undefined4 **)(iVar6 + 0x114) = pcVar18;
    }
  }
  *(int *)(iVar6 + 0x114) = *(int *)(iVar6 + 0x114) + 4;
  FUN_00766390(0,0,0);
  FUN_00767fa0();
  FUN_00465310(local_150);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00757640(&local_50);
  if (7 < local_98) {
    FUN_0089120c(local_ac);
  }
  local_98 = 7;
  local_9c = 0;
  local_ac = local_ac & 0xffff0000;
  if (7 < in_stack_00000018) {
    FUN_0089120c(param_1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

