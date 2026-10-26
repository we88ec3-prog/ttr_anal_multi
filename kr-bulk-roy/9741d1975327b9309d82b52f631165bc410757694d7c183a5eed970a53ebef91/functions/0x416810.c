
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00416810(void)

{
  char cVar1;
  short sVar2;
  int *piVar3;
  char **ppcVar4;
  code *pcVar5;
  int *piVar6;
  uint uVar7;
  undefined4 uVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  char **ppcVar12;
  undefined4 *puVar13;
  short *psVar14;
  int in_ECX;
  int *piVar15;
  uint uVar16;
  char *pcVar17;
  short *psVar18;
  int iVar19;
  uint *puVar20;
  char *local_b8 [4];
  uint local_a8 [4];
  undefined4 local_98;
  uint local_94;
  char *local_84;
  int local_80;
  char *local_7c;
  char *local_78;
  char *local_74;
  undefined4 local_70;
  undefined **local_6c [3];
  undefined **local_60 [3];
  char *pcStack_54;
  undefined4 uStack_50;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined **appuStack_30 [3];
  undefined **appuStack_24 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00948361;
  local_14 = ExceptionList;
  uVar7 = DAT_00d61f20 ^ (uint)&stack0xffffff38;
  ExceptionList = &local_14;
  iVar19 = 0x7ad938;
  local_80 = in_ECX;
  do {
    FUN_006c09c0(iVar19,uVar7);
    iVar19 = iVar19 + 1000;
  } while (iVar19 < 0x7af0a8);
  iVar19 = 0x7b2758;
  do {
    FUN_006c09c0(iVar19,uVar7);
    iVar19 = iVar19 + 1000;
  } while (iVar19 < 0x7b3ec8);
  FUN_004184c0();
  local_b8[0] = (char *)(in_ECX + 0x84);
  local_7c = (char *)0x6;
  do {
    local_70 = *(undefined4 *)local_b8[0];
    local_74 = (char *)0x0;
    if (*(int *)(in_ECX + 0xd0) != 0) {
      piVar15 = *(int **)(in_ECX + 0xcc);
      if (*(char *)((int)piVar15 + 0x15) == '\0') {
        piVar3 = (int *)*piVar15;
        if (*(char *)((int)piVar3 + 0x15) == '\0') {
          cVar1 = *(char *)(piVar3[2] + 0x15);
          piVar6 = (int *)piVar3[2];
          while (piVar15 = piVar3, cVar1 == '\0') {
            cVar1 = *(char *)(piVar6[2] + 0x15);
            piVar3 = piVar6;
            piVar6 = (int *)piVar6[2];
          }
        }
        else {
          cVar1 = *(char *)(piVar15[1] + 0x15);
          piVar3 = (int *)piVar15[1];
          while ((cVar1 == '\0' && (piVar15 == (int *)*piVar3))) {
            cVar1 = *(char *)(piVar3[1] + 0x15);
            piVar15 = piVar3;
            piVar3 = (int *)piVar3[1];
          }
          if (*(char *)((int)piVar15 + 0x15) == '\0') {
            piVar15 = piVar3;
          }
        }
      }
      else {
        piVar15 = (int *)piVar15[2];
      }
      local_74 = (char *)(piVar15[3] + 1);
    }
    uVar8 = FUN_0057ef20();
    FUN_0082f200(in_ECX + 200,uVar8);
    iVar19 = local_80;
    local_b8[0] = local_b8[0] + 4;
    local_7c = local_7c + -1;
  } while (local_7c != (char *)0x0);
  *(undefined4 *)(local_80 + 0xd8) = 0;
  *(undefined4 *)(local_80 + 0xdc) = 3;
  pcVar9 = (char *)FUN_00891268(0x20);
  local_b8[2] = pcVar9;
  local_c._1_3_ = 0;
  if (pcVar9 == (char *)0x0) {
    pcVar9 = (char *)0x0;
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 1;
      local_c._1_3_ = 0;
      _DAT_00fe5acc = 0;
      pcVar10 = (char *)FUN_00891268(0x30);
      if (pcVar10 == (char *)0x0) {
        local_b8[0] = (char *)0x0;
        std::exception::exception((exception *)local_60,local_b8);
        local_60[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_60,&DAT_00c857a8);
      }
      DAT_00fe5ac8 = pcVar10;
      *(char **)pcVar10 = pcVar10;
      *(char **)(DAT_00fe5ac8 + 4) = DAT_00fe5ac8;
      *(char **)(DAT_00fe5ac8 + 8) = DAT_00fe5ac8;
      DAT_00fe5ac8[0x2c] = '\x01';
      DAT_00fe5ac8[0x2d] = '\x01';
      local_c._0_1_ = 2;
      _DAT_00fe5adc = 0;
      iVar11 = FUN_00891268(0x30);
      if (iVar11 == 0) {
        local_84 = (char *)0x0;
        std::exception::exception((exception *)local_6c,&local_84);
        local_6c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_6c,&DAT_00c857a8);
      }
      DAT_00fe5ad8 = iVar11;
      *(int *)iVar11 = iVar11;
      *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
      *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
      *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
      *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c._0_1_ = 0;
    cVar1 = (*(char **)(DAT_00fe5ac8 + 4))[0x2d];
    pcVar10 = *(char **)(DAT_00fe5ac8 + 4);
    local_7c = DAT_00fe5ac8;
    while (pcVar17 = pcVar10, cVar1 == '\0') {
      if (*(int *)(pcVar17 + 0xc) < 0x2f2) {
        pcVar10 = *(char **)(pcVar17 + 8);
        pcVar17 = local_7c;
      }
      else {
        pcVar10 = *(char **)pcVar17;
      }
      cVar1 = pcVar10[0x2d];
      local_7c = pcVar17;
    }
    if ((local_7c == DAT_00fe5ac8) || (0x2f2 < *(int *)(local_7c + 0xc))) {
      local_78 = DAT_00fe5ac8;
      ppcVar12 = &local_78;
    }
    else {
      ppcVar12 = &local_7c;
    }
    if (*ppcVar12 == DAT_00fe5ac8) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    FUN_0040aff0();
    local_c = CONCAT31(local_c._1_3_,3);
    pcVar9[0] = '\x0e';
    pcVar9[1] = '\0';
    pcVar9[2] = '\0';
    pcVar9[3] = '\0';
    pcVar9[0x18] = '\a';
    pcVar9[0x19] = '\0';
    pcVar9[0x1a] = '\0';
    pcVar9[0x1b] = '\0';
    pcVar9[0x14] = '\0';
    pcVar9[0x15] = '\0';
    pcVar9[0x16] = '\0';
    pcVar9[0x17] = '\0';
    pcVar9[4] = '\0';
    pcVar9[5] = '\0';
    FUN_004026e0(local_a8,0,0xffffffff);
    if (7 < local_94) {
      FUN_0089120c(local_a8[0]);
    }
    local_94 = 7;
    local_98 = 0;
    local_a8[0] = local_a8[0] & 0xffff0000;
  }
  local_c = 0xffffffff;
  ppcVar12 = *(char ***)(iVar19 + 0x144);
  puVar20 = (uint *)(iVar19 + 0x140);
  local_b8[0] = pcVar9;
  if (local_b8 < ppcVar12) {
    ppcVar4 = (char **)*puVar20;
    if (ppcVar4 <= local_b8) {
      if (ppcVar12 == *(char ***)(iVar19 + 0x148)) {
        uVar7 = (int)ppcVar12 - (int)ppcVar4 >> 2;
        if (0x3ffffffe < uVar7) {
                    /* WARNING: Subroutine does not return */
          FUN_0087db30("vector<T> too long");
        }
        uVar7 = uVar7 + 1;
        uVar16 = (int)*(char ***)(iVar19 + 0x148) - (int)ppcVar4 >> 2;
        if (uVar16 < uVar7) {
          if (0x3fffffff - (uVar16 >> 1) < uVar16) {
            uVar16 = 0;
          }
          else {
            uVar16 = uVar16 + (uVar16 >> 1);
          }
          if (uVar16 < uVar7) {
            uVar16 = uVar7;
          }
          FUN_00797980(uVar16);
        }
      }
      if (*(undefined4 **)(iVar19 + 0x144) != (undefined4 *)0x0) {
        **(undefined4 **)(iVar19 + 0x144) =
             *(undefined4 *)(*puVar20 + ((int)local_b8 - (int)ppcVar4 >> 2) * 4);
      }
      goto LAB_00416c34;
    }
  }
  if (ppcVar12 == *(char ***)(iVar19 + 0x148)) {
    uVar7 = (int)((int)ppcVar12 - *puVar20) >> 2;
    if (0x3ffffffe < uVar7) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    uVar7 = uVar7 + 1;
    uVar16 = (int)((int)*(char ***)(iVar19 + 0x148) - *puVar20) >> 2;
    if (uVar16 < uVar7) {
      if (0x3fffffff - (uVar16 >> 1) < uVar16) {
        uVar16 = 0;
      }
      else {
        uVar16 = uVar16 + (uVar16 >> 1);
      }
      if (uVar16 < uVar7) {
        uVar16 = uVar7;
      }
      FUN_00797980(uVar16);
    }
  }
  if (*(undefined4 **)(iVar19 + 0x144) != (undefined4 *)0x0) {
    **(undefined4 **)(iVar19 + 0x144) = pcVar9;
  }
LAB_00416c34:
  *(int *)(iVar19 + 0x144) = *(int *)(iVar19 + 0x144) + 4;
  pcVar9 = (char *)FUN_00891268(0x20);
  local_b8[2] = pcVar9;
  local_c._1_3_ = 0;
  if (pcVar9 == (char *)0x0) {
    pcVar9 = (char *)0x0;
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 5;
      local_c._1_3_ = 0;
      _DAT_00fe5acc = 0;
      pcVar10 = (char *)FUN_00891268(0x30);
      if (pcVar10 == (char *)0x0) {
        local_b8[0] = (char *)0x0;
        std::exception::exception((exception *)local_60,local_b8);
        local_60[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_60,&DAT_00c857a8);
      }
      DAT_00fe5ac8 = pcVar10;
      *(char **)pcVar10 = pcVar10;
      *(char **)(DAT_00fe5ac8 + 4) = DAT_00fe5ac8;
      *(char **)(DAT_00fe5ac8 + 8) = DAT_00fe5ac8;
      DAT_00fe5ac8[0x2c] = '\x01';
      DAT_00fe5ac8[0x2d] = '\x01';
      local_c._0_1_ = 6;
      _DAT_00fe5adc = 0;
      iVar19 = FUN_00891268(0x30);
      if (iVar19 == 0) {
        local_84 = (char *)0x0;
        std::exception::exception((exception *)local_6c,&local_84);
        local_6c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_6c,&DAT_00c857a8);
      }
      DAT_00fe5ad8 = iVar19;
      *(int *)iVar19 = iVar19;
      *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
      *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
      *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
      *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c._0_1_ = 4;
    cVar1 = (*(char **)(DAT_00fe5ac8 + 4))[0x2d];
    pcVar10 = *(char **)(DAT_00fe5ac8 + 4);
    local_7c = DAT_00fe5ac8;
    while (pcVar17 = pcVar10, cVar1 == '\0') {
      if (*(int *)(pcVar17 + 0xc) < 0x2f5) {
        pcVar10 = *(char **)(pcVar17 + 8);
        pcVar17 = local_7c;
      }
      else {
        pcVar10 = *(char **)pcVar17;
      }
      cVar1 = pcVar10[0x2d];
      local_7c = pcVar17;
    }
    if ((local_7c == DAT_00fe5ac8) || (0x2f5 < *(int *)(local_7c + 0xc))) {
      local_78 = DAT_00fe5ac8;
      ppcVar12 = &local_78;
    }
    else {
      ppcVar12 = &local_7c;
    }
    if (*ppcVar12 == DAT_00fe5ac8) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    FUN_0040aff0();
    local_c = CONCAT31(local_c._1_3_,7);
    pcVar9[0] = '\x02';
    pcVar9[1] = '\0';
    pcVar9[2] = '\0';
    pcVar9[3] = '\0';
    pcVar9[0x18] = '\a';
    pcVar9[0x19] = '\0';
    pcVar9[0x1a] = '\0';
    pcVar9[0x1b] = '\0';
    pcVar9[0x14] = '\0';
    pcVar9[0x15] = '\0';
    pcVar9[0x16] = '\0';
    pcVar9[0x17] = '\0';
    pcVar9[4] = '\0';
    pcVar9[5] = '\0';
    FUN_004026e0(local_a8,0,0xffffffff);
    if (7 < local_94) {
      FUN_0089120c(local_a8[0]);
    }
    local_94 = 7;
    local_98 = 0;
    local_a8[0] = local_a8[0] & 0xffff0000;
  }
  iVar19 = local_80;
  puVar20 = (uint *)(local_80 + 0x150);
  local_c = 0xffffffff;
  ppcVar12 = *(char ***)(local_80 + 0x154);
  local_b8[2] = (char *)puVar20;
  local_b8[0] = pcVar9;
  if ((local_b8 < ppcVar12) && (ppcVar4 = (char **)*puVar20, ppcVar4 <= local_b8)) {
    if (ppcVar12 == *(char ***)(local_80 + 0x158)) {
      uVar7 = (int)ppcVar12 - (int)ppcVar4 >> 2;
      if (0x3ffffffe < uVar7) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("vector<T> too long");
      }
      uVar7 = uVar7 + 1;
      uVar16 = (int)*(char ***)(local_80 + 0x158) - (int)ppcVar4 >> 2;
      if (uVar16 < uVar7) {
        if (0x3fffffff - (uVar16 >> 1) < uVar16) {
          uVar16 = 0;
        }
        else {
          uVar16 = uVar16 + (uVar16 >> 1);
        }
        if (uVar16 < uVar7) {
          uVar16 = uVar7;
        }
        FUN_00797980(uVar16);
      }
    }
    if (*(undefined4 **)(iVar19 + 0x154) != (undefined4 *)0x0) {
      **(undefined4 **)(iVar19 + 0x154) =
           *(undefined4 *)(*puVar20 + ((int)local_b8 - (int)ppcVar4 >> 2) * 4);
    }
  }
  else {
    if (ppcVar12 == *(char ***)(local_80 + 0x158)) {
      uVar7 = (int)((int)ppcVar12 - *puVar20) >> 2;
      if (0x3ffffffe < uVar7) {
                    /* WARNING: Subroutine does not return */
        FUN_0087db30("vector<T> too long");
      }
      uVar7 = uVar7 + 1;
      uVar16 = (int)((int)*(char ***)(local_80 + 0x158) - *puVar20) >> 2;
      if (uVar16 < uVar7) {
        if (0x3fffffff - (uVar16 >> 1) < uVar16) {
          uVar16 = 0;
        }
        else {
          uVar16 = uVar16 + (uVar16 >> 1);
        }
        if (uVar16 < uVar7) {
          uVar16 = uVar7;
        }
        FUN_00797980(uVar16);
      }
    }
    if (*(undefined4 **)(iVar19 + 0x154) != (undefined4 *)0x0) {
      **(undefined4 **)(iVar19 + 0x154) = pcVar9;
    }
  }
  *(int *)(iVar19 + 0x154) = *(int *)(iVar19 + 0x154) + 4;
  pcVar9 = (char *)FUN_00891268(0x20);
  local_74 = pcVar9;
  local_c._1_3_ = 0;
  if (pcVar9 == (char *)0x0) {
    pcVar9 = (char *)0x0;
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 9;
      local_c._1_3_ = 0;
      _DAT_00fe5acc = 0;
      pcVar10 = (char *)FUN_00891268(0x30);
      if (pcVar10 == (char *)0x0) {
        local_84 = (char *)0x0;
        std::exception::exception((exception *)local_6c,&local_84);
        local_6c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_6c,&DAT_00c857a8);
      }
      DAT_00fe5ac8 = pcVar10;
      *(char **)pcVar10 = pcVar10;
      *(char **)(DAT_00fe5ac8 + 4) = DAT_00fe5ac8;
      *(char **)(DAT_00fe5ac8 + 8) = DAT_00fe5ac8;
      DAT_00fe5ac8[0x2c] = '\x01';
      DAT_00fe5ac8[0x2d] = '\x01';
      local_c._0_1_ = 10;
      _DAT_00fe5adc = 0;
      iVar19 = FUN_00891268(0x30);
      if (iVar19 == 0) {
        local_b8[0] = (char *)0x0;
        std::exception::exception((exception *)local_60,local_b8);
        local_60[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_60,&DAT_00c857a8);
      }
      DAT_00fe5ad8 = iVar19;
      *(int *)iVar19 = iVar19;
      *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
      *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
      *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
      *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c._0_1_ = 8;
    cVar1 = (*(char **)(DAT_00fe5ac8 + 4))[0x2d];
    pcVar10 = *(char **)(DAT_00fe5ac8 + 4);
    local_7c = DAT_00fe5ac8;
    while (pcVar17 = pcVar10, cVar1 == '\0') {
      if (*(int *)(pcVar17 + 0xc) < 0x2f4) {
        pcVar10 = *(char **)(pcVar17 + 8);
        pcVar17 = local_7c;
      }
      else {
        pcVar10 = *(char **)pcVar17;
      }
      cVar1 = pcVar10[0x2d];
      local_7c = pcVar17;
    }
    if ((local_7c == DAT_00fe5ac8) || (0x2f4 < *(int *)(local_7c + 0xc))) {
      local_78 = DAT_00fe5ac8;
      ppcVar12 = &local_78;
    }
    else {
      ppcVar12 = &local_7c;
    }
    if (*ppcVar12 == DAT_00fe5ac8) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 0xb;
      _DAT_00fe5acc = 0;
      pcVar10 = (char *)FUN_00891268(0x30);
      if (pcVar10 == (char *)0x0) {
        local_78 = (char *)0x0;
        std::exception::exception((exception *)appuStack_24,&local_78);
        appuStack_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(appuStack_24,&DAT_00c857a8);
      }
      DAT_00fe5ac8 = pcVar10;
      *(char **)pcVar10 = pcVar10;
      *(char **)(DAT_00fe5ac8 + 4) = DAT_00fe5ac8;
      *(char **)(DAT_00fe5ac8 + 8) = DAT_00fe5ac8;
      DAT_00fe5ac8[0x2c] = '\x01';
      DAT_00fe5ac8[0x2d] = '\x01';
      local_c._0_1_ = 0xc;
      _DAT_00fe5adc = 0;
      iVar19 = FUN_00891268(0x30);
      if (iVar19 == 0) {
        local_7c = (char *)0x0;
        std::exception::exception((exception *)appuStack_30,&local_7c);
        appuStack_30[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(appuStack_30,&DAT_00c857a8);
      }
      DAT_00fe5ad8 = iVar19;
      *(int *)iVar19 = iVar19;
      *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
      *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
      *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
      *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c._0_1_ = 8;
    cVar1 = (*(char **)(DAT_00fe5ac8 + 4))[0x2d];
    pcVar10 = *(char **)(DAT_00fe5ac8 + 4);
    pcStack_54 = DAT_00fe5ac8;
    while (pcVar17 = pcVar10, cVar1 == '\0') {
      if (*(int *)(pcVar17 + 0xc) < 0x2f7) {
        pcVar10 = *(char **)(pcVar17 + 8);
        pcVar17 = pcStack_54;
      }
      else {
        pcVar10 = *(char **)pcVar17;
      }
      cVar1 = pcVar10[0x2d];
      pcStack_54 = pcVar17;
    }
    if ((pcStack_54 == DAT_00fe5ac8) || (0x2f7 < *(int *)(pcStack_54 + 0xc))) {
      local_b8[1] = DAT_00fe5ac8;
      ppcVar12 = local_b8 + 1;
    }
    else {
      ppcVar12 = &pcStack_54;
    }
    if (*ppcVar12 == DAT_00fe5ac8) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    FUN_004ed610();
    local_c = CONCAT31(local_c._1_3_,0xd);
    pcVar9[0] = '\r';
    pcVar9[1] = '\0';
    pcVar9[2] = '\0';
    pcVar9[3] = '\0';
    pcVar9[0x18] = '\a';
    pcVar9[0x19] = '\0';
    pcVar9[0x1a] = '\0';
    pcVar9[0x1b] = '\0';
    pcVar9[0x14] = '\0';
    pcVar9[0x15] = '\0';
    pcVar9[0x16] = '\0';
    pcVar9[0x17] = '\0';
    pcVar9[4] = '\0';
    pcVar9[5] = '\0';
    FUN_004026e0(local_a8,0,0xffffffff);
    if (7 < local_94) {
      FUN_0089120c(local_a8[0]);
    }
    local_94 = 7;
    local_98 = 0;
    local_a8[0] = local_a8[0] & 0xffff0000;
  }
  local_c = 0xffffffff;
  local_b8[1] = pcVar9;
  FUN_00443d10();
  puVar13 = (undefined4 *)FUN_00891268(0x20);
  local_c._1_3_ = 0;
  local_74 = (char *)puVar13;
  if (puVar13 == (undefined4 *)0x0) {
    local_b8[2] = (char *)0x0;
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 0xf;
      local_c._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c._0_1_ = 0xe;
    local_b8[2] = (char *)0x2f8;
    FUN_005740f0(local_b8 + 2);
    if (local_b8[1] == DAT_00fe5ac8) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    psVar18 = (short *)(local_b8[1] + 0x10);
    if (7 < *(uint *)(local_b8[1] + 0x24)) {
      psVar18 = *(short **)psVar18;
    }
    local_a8[0] = local_a8[0] & 0xffff0000;
    local_94 = 7;
    local_98 = 0;
    psVar14 = psVar18;
    do {
      sVar2 = *psVar14;
      psVar14 = psVar14 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar18,(int)psVar14 - (int)(psVar18 + 1) >> 1);
    local_c = CONCAT31(local_c._1_3_,0x10);
    *puVar13 = 3;
    puVar13[6] = 7;
    puVar13[5] = 0;
    *(undefined2 *)(puVar13 + 1) = 0;
    FUN_004026e0(local_a8,0,0xffffffff);
    if (7 < local_94) {
      FUN_0089120c(local_a8[0]);
    }
    local_94 = 7;
    local_98 = 0;
    local_a8[0] = local_a8[0] & 0xffff0000;
    local_b8[2] = (char *)puVar13;
  }
  local_c = 0xffffffff;
  FUN_00443d10();
  puVar13 = (undefined4 *)FUN_00891268(0x20);
  local_c._1_3_ = 0;
  local_74 = (char *)puVar13;
  if (puVar13 == (undefined4 *)0x0) {
    local_b8[2] = (char *)0x0;
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 0x12;
      local_c._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c._0_1_ = 0x11;
    local_b8[2] = (char *)0x2f9;
    FUN_005740f0(local_b8 + 2);
    if (local_b8[1] == DAT_00fe5ac8) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    psVar18 = (short *)(local_b8[1] + 0x10);
    if (7 < *(uint *)(local_b8[1] + 0x24)) {
      psVar18 = *(short **)psVar18;
    }
    local_94 = 7;
    local_98 = 0;
    local_a8[0] = local_a8[0] & 0xffff0000;
    psVar14 = psVar18;
    do {
      sVar2 = *psVar14;
      psVar14 = psVar14 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar18,(int)psVar14 - (int)(psVar18 + 1) >> 1);
    local_c = CONCAT31(local_c._1_3_,0x13);
    *puVar13 = 4;
    puVar13[6] = 7;
    puVar13[5] = 0;
    *(undefined2 *)(puVar13 + 1) = 0;
    FUN_004026e0(local_a8,0,0xffffffff);
    if (7 < local_94) {
      FUN_0089120c(local_a8[0]);
    }
    local_94 = 7;
    local_98 = 0;
    local_a8[0] = local_a8[0] & 0xffff0000;
    local_b8[2] = (char *)puVar13;
  }
  local_c = 0xffffffff;
  FUN_00443d10();
  puVar13 = (undefined4 *)FUN_00891268(0x20);
  local_c._1_3_ = 0;
  local_74 = (char *)puVar13;
  if (puVar13 == (undefined4 *)0x0) {
    local_b8[2] = (char *)0x0;
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 0x15;
      local_c._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c._0_1_ = 0x14;
    local_b8[2] = (char *)0x300;
    FUN_005740f0(local_b8 + 2);
    if (local_b8[1] == DAT_00fe5ac8) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    psVar18 = (short *)(local_b8[1] + 0x10);
    if (7 < *(uint *)(local_b8[1] + 0x24)) {
      psVar18 = *(short **)psVar18;
    }
    local_a8[0] = local_a8[0] & 0xffff0000;
    local_94 = 7;
    local_98 = 0;
    psVar14 = psVar18;
    do {
      sVar2 = *psVar14;
      psVar14 = psVar14 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar18,(int)psVar14 - (int)(psVar18 + 1) >> 1);
    local_c = CONCAT31(local_c._1_3_,0x16);
    *puVar13 = 0xb;
    puVar13[6] = 7;
    puVar13[5] = 0;
    *(undefined2 *)(puVar13 + 1) = 0;
    FUN_004026e0(local_a8,0,0xffffffff);
    if (7 < local_94) {
      FUN_0089120c(local_a8[0]);
    }
    local_94 = 7;
    local_98 = 0;
    local_a8[0] = local_a8[0] & 0xffff0000;
    local_b8[2] = (char *)puVar13;
  }
  local_c = 0xffffffff;
  pcStack_54 = (char *)(local_80 + 0x180);
  FUN_00443d10();
  puVar13 = (undefined4 *)FUN_00891268(0x20);
  local_c._1_3_ = 0;
  local_74 = (char *)puVar13;
  if (puVar13 == (undefined4 *)0x0) {
    local_b8[2] = (char *)0x0;
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 0x18;
      local_c._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c._0_1_ = 0x17;
    local_b8[2] = (char *)0x301;
    FUN_005740f0(local_b8 + 2);
    if (local_b8[1] == DAT_00fe5ac8) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    psVar18 = (short *)(local_b8[1] + 0x10);
    if (7 < *(uint *)(local_b8[1] + 0x24)) {
      psVar18 = *(short **)psVar18;
    }
    local_94 = 7;
    local_98 = 0;
    local_a8[0] = local_a8[0] & 0xffff0000;
    psVar14 = psVar18;
    do {
      sVar2 = *psVar14;
      psVar14 = psVar14 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar18,(int)psVar14 - (int)(psVar18 + 1) >> 1);
    local_c = CONCAT31(local_c._1_3_,0x19);
    *puVar13 = 0xc;
    puVar13[6] = 7;
    puVar13[5] = 0;
    *(undefined2 *)(puVar13 + 1) = 0;
    FUN_004026e0(local_a8,0,0xffffffff);
    if (7 < local_94) {
      FUN_0089120c(local_a8[0]);
    }
    local_94 = 7;
    local_98 = 0;
    local_a8[0] = local_a8[0] & 0xffff0000;
    local_b8[2] = (char *)puVar13;
  }
  local_c = 0xffffffff;
  FUN_00443d10();
  puVar13 = (undefined4 *)FUN_00891268(0x20);
  local_c._1_3_ = 0;
  local_74 = (char *)puVar13;
  if (puVar13 == (undefined4 *)0x0) {
    local_b8[2] = (char *)0x0;
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 0x1b;
      local_c._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c._0_1_ = 0x1a;
    local_b8[2] = (char *)0x2fe;
    FUN_005740f0(local_b8 + 2);
    if (local_b8[1] == DAT_00fe5ac8) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    psVar18 = (short *)(local_b8[1] + 0x10);
    if (7 < *(uint *)(local_b8[1] + 0x24)) {
      psVar18 = *(short **)psVar18;
    }
    local_a8[0] = local_a8[0] & 0xffff0000;
    local_94 = 7;
    local_98 = 0;
    psVar14 = psVar18;
    do {
      sVar2 = *psVar14;
      psVar14 = psVar14 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar18,(int)psVar14 - (int)(psVar18 + 1) >> 1);
    local_c = CONCAT31(local_c._1_3_,0x1c);
    *puVar13 = 9;
    puVar13[6] = 7;
    puVar13[5] = 0;
    *(undefined2 *)(puVar13 + 1) = 0;
    FUN_004026e0(local_a8,0,0xffffffff);
    if (7 < local_94) {
      FUN_0089120c(local_a8[0]);
    }
    local_94 = 7;
    local_98 = 0;
    local_a8[0] = local_a8[0] & 0xffff0000;
    local_b8[2] = (char *)puVar13;
  }
  local_c = 0xffffffff;
  FUN_00443d10();
  puVar13 = (undefined4 *)FUN_00891268(0x20);
  local_c._1_3_ = 0;
  local_74 = (char *)puVar13;
  if (puVar13 == (undefined4 *)0x0) {
    local_b8[2] = (char *)0x0;
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 0x1e;
      local_c._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c._0_1_ = 0x1d;
    local_b8[2] = (char *)0x2ff;
    FUN_005740f0(local_b8 + 2);
    if (local_b8[1] == DAT_00fe5ac8) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    psVar18 = (short *)(local_b8[1] + 0x10);
    if (7 < *(uint *)(local_b8[1] + 0x24)) {
      psVar18 = *(short **)psVar18;
    }
    local_94 = 7;
    local_98 = 0;
    local_a8[0] = local_a8[0] & 0xffff0000;
    psVar14 = psVar18;
    do {
      sVar2 = *psVar14;
      psVar14 = psVar14 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar18,(int)psVar14 - (int)(psVar18 + 1) >> 1);
    local_c = CONCAT31(local_c._1_3_,0x1f);
    *puVar13 = 10;
    puVar13[6] = 7;
    puVar13[5] = 0;
    *(undefined2 *)(puVar13 + 1) = 0;
    FUN_004026e0(local_a8,0,0xffffffff);
    if (7 < local_94) {
      FUN_0089120c(local_a8[0]);
    }
    local_94 = 7;
    local_98 = 0;
    local_a8[0] = local_a8[0] & 0xffff0000;
    local_b8[2] = (char *)puVar13;
  }
  local_c = 0xffffffff;
  FUN_00443d10();
  puVar13 = (undefined4 *)FUN_00891268(0x20);
  local_c._1_3_ = 0;
  local_74 = (char *)puVar13;
  if (puVar13 == (undefined4 *)0x0) {
    local_b8[2] = (char *)0x0;
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 0x21;
      local_c._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c._0_1_ = 0x20;
    local_b8[2] = (char *)0x2fa;
    FUN_005740f0(local_b8 + 2);
    if (local_b8[1] == DAT_00fe5ac8) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    psVar18 = (short *)(local_b8[1] + 0x10);
    if (7 < *(uint *)(local_b8[1] + 0x24)) {
      psVar18 = *(short **)psVar18;
    }
    local_a8[0] = local_a8[0] & 0xffff0000;
    local_94 = 7;
    local_98 = 0;
    psVar14 = psVar18;
    do {
      sVar2 = *psVar14;
      psVar14 = psVar14 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar18,(int)psVar14 - (int)(psVar18 + 1) >> 1);
    local_c = CONCAT31(local_c._1_3_,0x22);
    *puVar13 = 5;
    puVar13[6] = 7;
    puVar13[5] = 0;
    *(undefined2 *)(puVar13 + 1) = 0;
    FUN_004026e0(local_a8,0,0xffffffff);
    if (7 < local_94) {
      FUN_0089120c(local_a8[0]);
    }
    local_94 = 7;
    local_98 = 0;
    local_a8[0] = local_a8[0] & 0xffff0000;
    local_b8[2] = (char *)puVar13;
  }
  local_c = 0xffffffff;
  FUN_00443d10();
  puVar13 = (undefined4 *)FUN_00891268(0x20);
  local_c._1_3_ = 0;
  local_74 = (char *)puVar13;
  if (puVar13 == (undefined4 *)0x0) {
    local_b8[2] = (char *)0x0;
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 0x24;
      local_c._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c._0_1_ = 0x23;
    local_b8[2] = (char *)0x2fb;
    FUN_005740f0(local_b8 + 2);
    if (local_b8[1] == DAT_00fe5ac8) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    psVar18 = (short *)(local_b8[1] + 0x10);
    if (7 < *(uint *)(local_b8[1] + 0x24)) {
      psVar18 = *(short **)psVar18;
    }
    local_94 = 7;
    local_98 = 0;
    local_a8[0] = local_a8[0] & 0xffff0000;
    psVar14 = psVar18;
    do {
      sVar2 = *psVar14;
      psVar14 = psVar14 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar18,(int)psVar14 - (int)(psVar18 + 1) >> 1);
    local_c = CONCAT31(local_c._1_3_,0x25);
    *puVar13 = 6;
    puVar13[6] = 7;
    puVar13[5] = 0;
    *(undefined2 *)(puVar13 + 1) = 0;
    FUN_004026e0(local_a8,0,0xffffffff);
    if (7 < local_94) {
      FUN_0089120c(local_a8[0]);
    }
    local_94 = 7;
    local_98 = 0;
    local_a8[0] = local_a8[0] & 0xffff0000;
    local_b8[2] = (char *)puVar13;
  }
  local_c = 0xffffffff;
  FUN_00443d10();
  puVar13 = (undefined4 *)FUN_00891268(0x20);
  local_c._1_3_ = 0;
  local_74 = (char *)puVar13;
  if (puVar13 == (undefined4 *)0x0) {
    local_b8[2] = (char *)0x0;
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 0x27;
      local_c._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c._0_1_ = 0x26;
    local_b8[2] = (char *)0x2fc;
    FUN_005740f0(local_b8 + 2);
    if (local_b8[1] == DAT_00fe5ac8) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    psVar18 = (short *)(local_b8[1] + 0x10);
    if (7 < *(uint *)(local_b8[1] + 0x24)) {
      psVar18 = *(short **)psVar18;
    }
    local_a8[0] = local_a8[0] & 0xffff0000;
    local_94 = 7;
    local_98 = 0;
    psVar14 = psVar18;
    do {
      sVar2 = *psVar14;
      psVar14 = psVar14 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar18,(int)psVar14 - (int)(psVar18 + 1) >> 1);
    local_c = CONCAT31(local_c._1_3_,0x28);
    *puVar13 = 7;
    puVar13[6] = 7;
    puVar13[5] = 0;
    *(undefined2 *)(puVar13 + 1) = 0;
    FUN_004026e0(local_a8,0,0xffffffff);
    if (7 < local_94) {
      FUN_0089120c(local_a8[0]);
    }
    local_94 = 7;
    local_98 = 0;
    local_a8[0] = local_a8[0] & 0xffff0000;
    local_b8[2] = (char *)puVar13;
  }
  local_c = 0xffffffff;
  FUN_00443d10();
  puVar13 = (undefined4 *)FUN_00891268(0x20);
  local_c._1_3_ = 0;
  local_74 = (char *)puVar13;
  if (puVar13 == (undefined4 *)0x0) {
    local_b8[2] = (char *)0x0;
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c._0_1_ = 0x2a;
      local_c._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c._0_1_ = 0x29;
    local_b8[2] = (char *)0x2fd;
    FUN_005740f0(local_b8 + 2);
    if (local_b8[1] == DAT_00fe5ac8) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    psVar18 = (short *)(local_b8[1] + 0x10);
    if (7 < *(uint *)(local_b8[1] + 0x24)) {
      psVar18 = *(short **)psVar18;
    }
    uStack_3c = 7;
    uStack_40 = 0;
    uStack_50 = (uint)uStack_50._2_2_ << 0x10;
    psVar14 = psVar18;
    do {
      sVar2 = *psVar14;
      psVar14 = psVar14 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar18,(int)psVar14 - (int)(psVar18 + 1) >> 1);
    local_c = CONCAT31(local_c._1_3_,0x2b);
    *puVar13 = 8;
    puVar13[6] = 7;
    puVar13[5] = 0;
    *(undefined2 *)(puVar13 + 1) = 0;
    FUN_004026e0(&uStack_50,0,0xffffffff);
    if (7 < uStack_3c) {
      FUN_0089120c(uStack_50);
    }
    uStack_3c = 7;
    uStack_40 = 0;
    uStack_50 = uStack_50 & 0xffff0000;
    local_b8[2] = (char *)puVar13;
  }
  local_c = 0xffffffff;
  FUN_00443d10();
  FUN_00416020(local_80);
  FUN_00415d50();
  FUN_00416580(local_80);
  FUN_00415380(local_80);
  ExceptionList = local_14;
  return;
}

