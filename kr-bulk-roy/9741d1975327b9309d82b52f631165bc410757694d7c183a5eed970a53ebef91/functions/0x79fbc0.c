
void FUN_0079fbc0(int param_1,uint param_2,uint param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  ushort *puVar12;
  undefined2 *puVar13;
  char *pcVar14;
  char *pcVar15;
  char **ppcVar16;
  int *piVar17;
  uint uVar18;
  char *pcVar19;
  int *piVar20;
  undefined1 local_78 [4];
  int *local_74;
  undefined4 local_70;
  uint local_68;
  undefined **local_64;
  int local_60;
  int local_5c;
  int local_58;
  undefined **local_54;
  int local_50;
  int local_4c;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  char *local_30;
  char *local_2c;
  char *local_28;
  char *local_24;
  char *local_20;
  int local_1c;
  int *local_18;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  uVar6 = param_3;
  uVar18 = param_2;
  local_8 = 0xffffffff;
  puStack_c = &LAB_00918f0e;
  local_10 = ExceptionList;
  uVar8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_3 != param_2) {
    FUN_004ca160(**(undefined4 **)(param_3 + 4),*(undefined4 **)(param_3 + 4));
    FUN_007a1540(uVar18);
  }
  if (uVar6 + 0x10 != uVar18 + 0x10) {
    puVar11 = *(undefined4 **)(uVar6 + 0x14);
    FUN_006d7120(*puVar11,puVar11);
    FUN_007a1660(uVar18 + 0x10);
  }
  local_70 = 0;
  local_74 = (int *)FUN_00891268(0x28,uVar8);
  if (local_74 == (int *)0x0) {
    local_2c = (char *)0x0;
    std::exception::exception((exception *)&local_64,&local_2c);
    local_64 = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(&local_64,&DAT_00c857a8);
  }
  *local_74 = (int)local_74;
  local_74[1] = (int)local_74;
  local_74[2] = (int)local_74;
  *(undefined1 *)(local_74 + 8) = 1;
  *(undefined1 *)((int)local_74 + 0x21) = 1;
  local_8 = 0;
  piVar20 = (int *)**(int **)(uVar18 + 4);
  local_18 = piVar20;
  if (piVar20 != *(int **)(uVar18 + 4)) {
    do {
      local_1c = CONCAT22((short)piVar20[3],*(undefined2 *)((int)piVar20 + 0xe));
      FUN_0082ef00(&local_1c);
      if (((local_20 != *(char **)(param_1 + 0xb8)) &&
          (local_28 = *(char **)(local_20 + 0x10), local_28 != (char *)0x0)) &&
         (piVar17 = *(int **)(local_28 + 0x38), piVar17 != *(int **)(local_28 + 0x3c))) {
        do {
          iVar2 = *piVar17;
          local_34 = piVar17[1];
          local_38 = iVar2;
          if ((DAT_00fe1bc0 & 1) == 0) {
            DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
            local_8._0_1_ = 1;
            FUN_007bef00();
            _atexit((_func_4879 *)&LAB_00bcec50);
            local_8 = (uint)local_8._1_3_ << 8;
          }
          local_3c = local_34;
          local_40 = iVar2;
          FUN_004dd400(&DAT_00fe1b60,&local_24,&local_40);
          if ((local_24 != DAT_00fe1b64) && (*(int *)(local_24 + 0x18) != 0)) {
            iVar2 = *(int *)(*(int *)(local_24 + 0x18) + 0x20);
            iVar3 = *(int *)(param_2 + 0x14);
            local_1c = iVar2;
            piVar9 = (int *)FUN_007a0c00(&local_1c);
            piVar20 = local_18;
            if (*piVar9 == iVar3) {
              local_50 = local_38;
              local_4c = local_34;
              local_58 = iVar2;
              uVar10 = FUN_007a25f0();
              FUN_007a2810(local_78,uVar10);
              piVar20 = local_18;
            }
          }
          piVar17 = piVar17 + 2;
        } while (piVar17 != *(int **)(local_28 + 0x3c));
      }
      if (*(char *)((int)piVar20 + 0x11) == '\0') {
        piVar17 = (int *)piVar20[2];
        if (*(char *)((int)piVar17 + 0x11) == '\0') {
          cVar1 = *(char *)(*piVar17 + 0x11);
          piVar20 = piVar17;
          piVar17 = (int *)*piVar17;
          while (local_18 = piVar20, cVar1 == '\0') {
            cVar1 = *(char *)(*piVar17 + 0x11);
            piVar20 = piVar17;
            piVar17 = (int *)*piVar17;
          }
        }
        else {
          cVar1 = *(char *)(piVar20[1] + 0x11);
          piVar9 = (int *)piVar20[1];
          piVar17 = piVar20;
          while ((piVar20 = piVar9, local_18 = piVar20, cVar1 == '\0' &&
                 (piVar17 == (int *)piVar20[2]))) {
            cVar1 = *(char *)(piVar20[1] + 0x11);
            piVar9 = (int *)piVar20[1];
            piVar17 = piVar20;
          }
        }
      }
    } while (piVar20 != *(int **)(param_2 + 4));
  }
  puVar11 = (undefined4 *)FUN_00891268(0x14,uVar8);
  if (puVar11 != (undefined4 *)0x0) {
    *puVar11 = puVar11;
    puVar11[1] = puVar11;
    puVar11[2] = puVar11;
    *(undefined1 *)(puVar11 + 4) = 1;
    *(undefined1 *)((int)puVar11 + 0x11) = 1;
    local_8._0_1_ = 2;
    piVar20 = (int *)**(int **)(param_2 + 0x14);
    if (piVar20 != *(int **)(param_2 + 0x14)) {
      do {
        iVar2 = piVar20[6];
        iVar3 = piVar20[7];
        if ((DAT_00fe1bc0 & 1) == 0) {
          DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
          local_8._0_1_ = 3;
          FUN_007bef00();
          _atexit((_func_4879 *)&LAB_00bcec50);
          local_8._0_1_ = 2;
        }
        local_40 = iVar2;
        local_3c = iVar3;
        puVar12 = (ushort *)FUN_007c0140();
        local_18 = (int *)(uint)*puVar12;
        if ((DAT_00fe1bc0 & 1) == 0) {
          DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
          local_8._0_1_ = 4;
          FUN_007bef00();
          _atexit((_func_4879 *)&LAB_00bcec50);
          local_8._0_1_ = 2;
        }
        local_38 = iVar2;
        local_34 = iVar3;
        puVar12 = (ushort *)FUN_007c0140();
        local_28 = (char *)(uint)*puVar12;
        if ((short)local_18 != 0) {
          puVar13 = (undefined2 *)FUN_007a0a90();
          *puVar13 = (short)local_18;
        }
        if (*(char *)((int)piVar20 + 0x21) == '\0') {
          piVar17 = (int *)piVar20[2];
          if (*(char *)((int)piVar17 + 0x21) == '\0') {
            cVar1 = *(char *)(*piVar17 + 0x21);
            piVar20 = piVar17;
            piVar17 = (int *)*piVar17;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar17 + 0x21);
              piVar20 = piVar17;
              piVar17 = (int *)*piVar17;
            }
          }
          else {
            cVar1 = *(char *)(piVar20[1] + 0x21);
            piVar9 = (int *)piVar20[1];
            piVar17 = piVar20;
            while ((piVar20 = piVar9, cVar1 == '\0' && (piVar17 == (int *)piVar20[2]))) {
              cVar1 = *(char *)(piVar20[1] + 0x21);
              piVar9 = (int *)piVar20[1];
              piVar17 = piVar20;
            }
          }
        }
      } while (piVar20 != *(int **)(param_2 + 0x14));
    }
    local_18 = (int *)*puVar11;
    while (local_18 != puVar11) {
      uVar18 = CONCAT22(*(undefined2 *)(local_18 + 3),*(undefined2 *)((int)local_18 + 0xe));
      pcVar19 = *(char **)(*(char **)(param_1 + 0xb8) + 4);
      cVar1 = pcVar19[0x15];
      local_28 = *(char **)(param_1 + 0xb8);
      while (cVar1 == '\0') {
        if (*(uint *)(pcVar19 + 0xc) < uVar18) {
          pcVar14 = *(char **)(pcVar19 + 8);
          pcVar19 = local_28;
        }
        else {
          pcVar14 = *(char **)pcVar19;
        }
        local_28 = pcVar19;
        pcVar19 = pcVar14;
        cVar1 = pcVar14[0x15];
      }
      if ((local_28 == *(char **)(param_1 + 0xb8)) || (uVar18 < *(uint *)(local_28 + 0xc))) {
        local_24 = *(char **)(param_1 + 0xb8);
        ppcVar16 = &local_24;
      }
      else {
        ppcVar16 = &local_28;
      }
      if (((*ppcVar16 != *(char **)(param_1 + 0xb8)) &&
          (local_1c = *(int *)(*ppcVar16 + 0x10), local_1c != 0)) &&
         (piVar20 = *(int **)(local_1c + 0x38), piVar20 != *(int **)(local_1c + 0x3c))) {
        do {
          iVar2 = piVar20[1];
          iVar3 = *piVar20;
          local_34 = iVar2;
          if ((DAT_00fe1bc0 & 1) == 0) {
            DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
            local_8._0_1_ = 5;
            FUN_007bef00();
            _atexit((_func_4879 *)&LAB_00bcec50);
            local_8._0_1_ = 2;
          }
          local_40 = iVar3;
          local_3c = iVar2;
          FUN_004dd400(&DAT_00fe1b60,&local_20,&local_40);
          if ((local_20 != DAT_00fe1b64) && (*(int *)(local_20 + 0x18) != 0)) {
            uVar18 = *(uint *)(*(int *)(local_20 + 0x18) + 0x20);
            pcVar19 = *(char **)(param_2 + 0x14);
            cVar1 = (*(char **)(pcVar19 + 4))[0x21];
            local_28 = pcVar19;
            pcVar14 = *(char **)(pcVar19 + 4);
            while (cVar1 == '\0') {
              if (*(uint *)(pcVar14 + 0x10) < uVar18) {
                pcVar15 = *(char **)(pcVar14 + 8);
                pcVar14 = local_28;
              }
              else {
                pcVar15 = *(char **)pcVar14;
              }
              local_28 = pcVar14;
              pcVar14 = pcVar15;
              cVar1 = pcVar15[0x21];
            }
            if ((local_28 == *(char **)(param_2 + 0x14)) || (uVar18 < *(uint *)(local_28 + 0x10))) {
              local_2c = *(char **)(param_2 + 0x14);
              ppcVar16 = &local_2c;
            }
            else {
              ppcVar16 = &local_28;
            }
            if (*ppcVar16 == pcVar19) {
              local_5c = local_34;
              local_68 = uVar18;
              local_60 = iVar3;
              uVar10 = FUN_007a25f0();
              FUN_007a2810(local_78,uVar10);
            }
          }
          piVar20 = piVar20 + 2;
        } while (piVar20 != *(int **)(local_1c + 0x3c));
      }
      if (*(char *)((int)local_18 + 0x11) == '\0') {
        puVar4 = (undefined4 *)local_18[2];
        if (*(char *)((int)puVar4 + 0x11) == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x11);
          local_18 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar4 + 0x11);
            local_18 = puVar4;
            puVar4 = (undefined4 *)*puVar4;
          }
        }
        else {
          cVar1 = *(char *)(local_18[1] + 0x11);
          puVar4 = (undefined4 *)local_18[1];
          piVar20 = local_18;
          while ((local_18 = puVar4, cVar1 == '\0' && (piVar20 == (undefined4 *)local_18[2]))) {
            cVar1 = *(char *)(local_18[1] + 0x11);
            puVar4 = (undefined4 *)local_18[1];
            piVar20 = local_18;
          }
        }
      }
    }
    piVar20 = (int *)*local_74;
    if (piVar20 != local_74) {
      do {
        iVar2 = piVar20[6];
        iVar3 = piVar20[7];
        if ((DAT_00fe1bc0 & 1) == 0) {
          DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
          local_8._0_1_ = 6;
          FUN_007bef00();
          _atexit((_func_4879 *)&LAB_00bcec50);
          local_8._0_1_ = 2;
        }
        local_40 = iVar2;
        local_3c = iVar3;
        puVar12 = (ushort *)FUN_007c0140();
        param_2 = (uint)*puVar12;
        if ((DAT_00fe1bc0 & 1) == 0) {
          DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
          local_8._0_1_ = 7;
          FUN_007bef00();
          _atexit((_func_4879 *)&LAB_00bcec50);
          local_8._0_1_ = 2;
        }
        local_38 = iVar2;
        local_34 = iVar3;
        puVar12 = (ushort *)FUN_007c0140();
        local_2c = (char *)(uint)*puVar12;
        if ((short)param_2 != 0) {
          puVar13 = (undefined2 *)FUN_007a0a90();
          *puVar13 = (short)param_2;
        }
        if (*(char *)((int)piVar20 + 0x21) == '\0') {
          piVar17 = (int *)piVar20[2];
          if (*(char *)((int)piVar17 + 0x21) == '\0') {
            cVar1 = *(char *)(*piVar17 + 0x21);
            piVar20 = piVar17;
            piVar17 = (int *)*piVar17;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar17 + 0x21);
              piVar20 = piVar17;
              piVar17 = (int *)*piVar17;
            }
          }
          else {
            cVar1 = *(char *)(piVar20[1] + 0x21);
            piVar9 = (int *)piVar20[1];
            piVar17 = piVar20;
            while ((piVar20 = piVar9, cVar1 == '\0' && (piVar17 == (int *)piVar20[2]))) {
              cVar1 = *(char *)(piVar20[1] + 0x21);
              piVar9 = (int *)piVar20[1];
              piVar17 = piVar20;
            }
          }
        }
      } while (piVar20 != local_74);
    }
    uVar18 = param_3;
    puVar4 = (undefined4 *)*puVar11;
    while (puVar4 != puVar11) {
      puVar13 = (undefined2 *)FUN_007a0a90();
      *puVar13 = *(undefined2 *)((int)puVar4 + 0xe);
      if (*(char *)((int)puVar4 + 0x11) == '\0') {
        puVar5 = (undefined4 *)puVar4[2];
        if (*(char *)((int)puVar5 + 0x11) == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x11);
          puVar4 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar5 + 0x11);
            puVar4 = puVar5;
            puVar5 = (undefined4 *)*puVar5;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar4[1] + 0x11);
          puVar7 = (undefined4 *)puVar4[1];
          puVar5 = puVar4;
          while ((puVar4 = puVar7, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar4[2]))) {
            cVar1 = *(char *)((int)puVar4[1] + 0x11);
            puVar7 = (undefined4 *)puVar4[1];
            puVar5 = puVar4;
          }
        }
      }
    }
    piVar20 = (int *)*local_74;
    if (piVar20 != local_74) {
      do {
        piVar17 = (int *)FUN_007a0b80();
        *piVar17 = piVar20[6];
        piVar17[1] = piVar20[7];
        if (*(char *)((int)piVar20 + 0x21) == '\0') {
          piVar17 = (int *)piVar20[2];
          if (*(char *)((int)piVar17 + 0x21) == '\0') {
            cVar1 = *(char *)(*piVar17 + 0x21);
            piVar20 = piVar17;
            piVar17 = (int *)*piVar17;
            while (cVar1 == '\0') {
              cVar1 = *(char *)(*piVar17 + 0x21);
              piVar20 = piVar17;
              piVar17 = (int *)*piVar17;
            }
          }
          else {
            cVar1 = *(char *)(piVar20[1] + 0x21);
            piVar9 = (int *)piVar20[1];
            piVar17 = piVar20;
            while ((piVar20 = piVar9, cVar1 == '\0' && (piVar17 == (int *)piVar20[2]))) {
              cVar1 = *(char *)(piVar20[1] + 0x21);
              piVar9 = (int *)piVar20[1];
              piVar17 = piVar20;
            }
          }
        }
      } while (piVar20 != local_74);
    }
    if (*(int *)(uVar18 + 8) == 0) {
      local_40 = 0;
      local_3c = 0;
      uVar10 = FUN_007a3510();
      FUN_007a2740(uVar18,uVar10);
    }
    else {
      param_2 = 0;
      FUN_007a15d0(&local_40,&param_2);
      FUN_004ca160(local_40,local_3c);
    }
    local_8 = CONCAT31(local_8._1_3_,8);
    FUN_004ca160(*puVar11,puVar11);
    FUN_0089120c(puVar11);
    local_8 = 9;
    FUN_006d7120(*local_74,local_74);
    FUN_0089120c(local_74);
    ExceptionList = local_10;
    return;
  }
  local_30 = (char *)0x0;
  std::exception::exception((exception *)&local_54,&local_30);
  local_54 = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(&local_54,&DAT_00c857a8);
}

