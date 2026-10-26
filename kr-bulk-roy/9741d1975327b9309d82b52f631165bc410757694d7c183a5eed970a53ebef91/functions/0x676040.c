
void FUN_00676040(int param_1)

{
  char cVar1;
  ushort uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  int *piVar7;
  char *pcVar8;
  char **ppcVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 **ppuVar12;
  char *pcVar13;
  int *piVar14;
  int iVar15;
  int *local_50;
  char *local_4c;
  char *local_48;
  char *local_44;
  undefined4 *puStack_40;
  undefined4 *apuStack_3c [2];
  char *local_34;
  undefined4 *local_30;
  int local_2c;
  undefined **local_24 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093ce94;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_00823850(DAT_00d61f20 ^ (uint)&stack0xffffffa0);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  local_50 = (int *)0x1;
  piVar14 = (int *)(DAT_00f94300 + 0x1724);
  pcVar8 = DAT_00f8d91c;
  do {
    if ((int)local_50 - 1U < 100) {
      if (((*piVar14 != 0) && (piVar14[-1] != 0)) && (piVar14 != (int *)0xc)) {
        if ((DAT_00f8d9a4 & 1) == 0) {
          DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
          local_c = 1;
          FUN_0051c120();
          _atexit((_func_4879 *)&LAB_00bccc90);
          local_c = 0xffffffff;
          pcVar8 = DAT_00f8d91c;
        }
        cVar1 = (*(char **)(pcVar8 + 4))[0x15];
        pcVar6 = *(char **)(pcVar8 + 4);
        local_4c = pcVar8;
        while (pcVar13 = pcVar6, cVar1 == '\0') {
          if (*(int *)(pcVar13 + 0xc) < *piVar14) {
            pcVar6 = *(char **)(pcVar13 + 8);
            pcVar13 = local_4c;
          }
          else {
            pcVar6 = *(char **)pcVar13;
          }
          cVar1 = pcVar6[0x15];
          local_4c = pcVar13;
        }
        if ((local_4c == pcVar8) || (*piVar14 < *(int *)(local_4c + 0xc))) {
          local_48 = pcVar8;
          ppcVar9 = &local_48;
        }
        else {
          ppcVar9 = &local_4c;
        }
        if ((*ppcVar9 != pcVar8) && (iVar15 = *(int *)(*ppcVar9 + 0x10), iVar15 != 0)) {
          iVar15 = *(int *)(iVar15 + 0x68);
          if (iVar15 != 0) {
            uVar2 = *(ushort *)(iVar15 + 8);
            if ((DAT_00f94390 & 1) == 0) {
              DAT_00f94390 = DAT_00f94390 | 1;
              local_c = 2;
              FUN_004e1590();
              _atexit((_func_4879 *)&LAB_00bccc80);
              local_c = 0xffffffff;
              pcVar8 = DAT_00f8d91c;
            }
            local_4c = (char *)(uint)uVar2;
            FUN_004a4cc0(&local_4c);
            if (((local_44 == *(char **)(DAT_00f94308 + 0x14)) || (*(int *)(local_44 + 0x10) == 0))
               || (*(int *)(*(int *)(local_44 + 0x10) + 0xc) == 0)) goto LAB_0067621e;
          }
          piVar7 = (int *)FUN_004c2880();
          *piVar7 = *piVar7 + piVar14[-1];
          pcVar8 = DAT_00f8d91c;
        }
      }
    }
    else {
      FUN_006edb60(&DAT_00c0ddc0);
      pcVar8 = DAT_00f8d91c;
    }
LAB_0067621e:
    local_50 = (int *)((int)local_50 + 1);
    piVar14 = piVar14 + 8;
  } while ((int)local_50 < 0x65);
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 3;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  piVar14 = (int *)(DAT_00f94300 + 0x23c0);
  iVar15 = 1;
  do {
    if (iVar15 - 1U < 0x1e0) {
      if (((piVar14[1] != 0) && (*piVar14 != 0)) && (piVar14 != (int *)0x8)) {
        piVar7 = (int *)FUN_004c2880();
        *piVar7 = *piVar7 + *piVar14;
      }
    }
    else {
      FUN_006edb60(&DAT_00c0ddc0);
    }
    iVar15 = iVar15 + 1;
    piVar14 = piVar14 + 6;
  } while (iVar15 < 0x1e1);
  if ((*(int *)(param_1 + 0x18c) == 0) && (*(char *)(param_1 + 0x1d4) == '\0')) {
    uVar3 = (*(undefined4 **)(param_1 + 0x1b4))[1];
    uVar4 = **(undefined4 **)(param_1 + 0x1b4);
    local_2c = 0;
    local_30 = (undefined4 *)FUN_00891268(0xc);
    if (local_30 == (undefined4 *)0x0) {
      local_44 = (char *)0x0;
      std::exception::exception((exception *)local_24,&local_44);
      local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_24,&DAT_00c857a8);
    }
    *local_30 = local_30;
    local_30[1] = local_30;
    local_c = 4;
    FUN_00678310(&local_30,uVar4,uVar3,local_34);
    ppuVar12 = (undefined4 **)(param_1 + 0x188);
    local_c = 5;
    if (ppuVar12 != &local_30) {
      piVar14 = *ppuVar12;
      piVar7 = (int *)*piVar14;
      *piVar14 = (int)piVar14;
      (*ppuVar12)[1] = *ppuVar12;
      *(undefined4 *)(param_1 + 0x18c) = 0;
      if (piVar7 != *ppuVar12) {
        do {
          piVar14 = (int *)*piVar7;
          FUN_0089120c(piVar7);
          piVar7 = piVar14;
        } while (piVar14 != *ppuVar12);
      }
      if (local_2c != 0) {
        FUN_00677f30(**ppuVar12,*local_30,local_30);
      }
    }
    puVar10 = local_30;
    local_c = 0xffffffff;
    puVar5 = (undefined4 *)*local_30;
    *local_30 = local_30;
    local_30[1] = local_30;
    while (puVar5 != puVar10) {
      puVar11 = (undefined4 *)*puVar5;
      FUN_0089120c(puVar5);
      puVar5 = puVar11;
    }
    FUN_0089120c(puVar10);
  }
  local_50 = (int *)**(int **)(param_1 + 0x188);
  if (local_50 != *(int **)(param_1 + 0x188)) {
    do {
      if ((DAT_00fe1de0 & 1) == 0) {
        DAT_00fe1de0 = DAT_00fe1de0 | 1;
        local_c = 6;
        DAT_00fe1dec = 0;
        pcVar8 = (char *)FUN_00891268(0x3c);
        if (pcVar8 == (char *)0x0) {
          local_34 = (char *)0x0;
          std::exception::exception((exception *)local_24,&local_34);
          local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
          __CxxThrowException_8(local_24,&DAT_00c857a8);
        }
        DAT_00fe1de8 = pcVar8;
        *(char **)pcVar8 = pcVar8;
        *(char **)(DAT_00fe1de8 + 4) = DAT_00fe1de8;
        *(char **)(DAT_00fe1de8 + 8) = DAT_00fe1de8;
        DAT_00fe1de8[0x38] = '\x01';
        DAT_00fe1de8[0x39] = '\x01';
        _atexit(FUN_00bcef60);
        local_c = 0xffffffff;
      }
      cVar1 = (*(char **)(DAT_00fe1de8 + 4))[0x39];
      pcVar8 = *(char **)(DAT_00fe1de8 + 4);
      local_44 = DAT_00fe1de8;
      while (pcVar6 = pcVar8, cVar1 == '\0') {
        if (*(int *)(pcVar6 + 0xc) < local_50[2]) {
          pcVar8 = *(char **)(pcVar6 + 8);
          pcVar6 = local_44;
        }
        else {
          pcVar8 = *(char **)pcVar6;
        }
        cVar1 = pcVar8[0x39];
        local_44 = pcVar6;
      }
      if ((local_44 == DAT_00fe1de8) || (local_50[2] < *(int *)(local_44 + 0xc))) {
        local_48 = DAT_00fe1de8;
        ppcVar9 = &local_48;
      }
      else {
        ppcVar9 = &local_44;
      }
      pcVar8 = *ppcVar9;
      if ((pcVar8 == DAT_00fe1de8) || (pcVar8 == (char *)0xfffffff0)) {
LAB_006765a1:
        piVar14 = (int *)*local_50;
      }
      else {
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c = 7;
          FUN_004e1590();
          _atexit((_func_4879 *)&LAB_00bccc80);
          local_c = 0xffffffff;
        }
        if (*(int *)(pcVar8 + 0x18) <= DAT_00f94244) {
          piVar14 = *(int **)(pcVar8 + 0x28);
          pcVar8 = (char *)(*(int *)(pcVar8 + 0x2c) - (int)piVar14 >> 3);
          local_4c = (char *)0x0;
          if (pcVar8 != (char *)0x0) {
            puVar5 = *(undefined4 **)(param_1 + 0x198);
            do {
              puStack_40 = puVar5;
              if (*(char *)((int)puVar5[1] + 0x15) == '\0') {
                puVar10 = (undefined4 *)puVar5[1];
                do {
                  if ((int)puVar10[3] < *piVar14) {
                    puVar11 = (undefined4 *)puVar10[2];
                  }
                  else {
                    puVar11 = (undefined4 *)*puVar10;
                    puStack_40 = puVar10;
                  }
                  puVar10 = puVar11;
                } while (*(char *)((int)puVar11 + 0x15) == '\0');
              }
              if ((puStack_40 == puVar5) || (*piVar14 < (int)puStack_40[3])) {
                apuStack_3c[0] = puVar5;
                ppuVar12 = apuStack_3c;
              }
              else {
                ppuVar12 = &puStack_40;
              }
              if ((*ppuVar12 == puVar5) || ((int)(*ppuVar12)[4] < piVar14[1])) goto LAB_006765d3;
              local_4c = local_4c + 1;
              piVar14 = piVar14 + 2;
            } while (local_4c < pcVar8);
          }
          goto LAB_006765a1;
        }
LAB_006765d3:
        piVar14 = (int *)*local_50;
        if (local_50 != *(int **)(param_1 + 0x188)) {
          *(int **)local_50[1] = piVar14;
          *(int *)(*local_50 + 4) = local_50[1];
          FUN_0089120c(local_50);
          *(int *)(param_1 + 0x18c) = *(int *)(param_1 + 0x18c) + -1;
        }
      }
      local_50 = piVar14;
    } while (local_50 != *(int **)(param_1 + 0x188));
  }
  ExceptionList = local_14;
  return;
}

