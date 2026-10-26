
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00662b50(void)

{
  uint *puVar1;
  char cVar2;
  int *piVar3;
  char **ppcVar4;
  code *pcVar5;
  int iVar6;
  char *pcVar7;
  char **ppcVar8;
  uint uVar9;
  int in_ECX;
  char *pcVar10;
  uint uVar11;
  int iVar12;
  int *piVar13;
  undefined4 local_64 [5];
  uint local_50;
  undefined **local_48 [3];
  undefined **local_3c [3];
  int *local_30;
  char *local_2c;
  char *local_28;
  char *local_24;
  char *local_20;
  char *local_1c [2];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092cea0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00755e50(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_0043c570(10000);
  FUN_0043c570(0x526c);
  FUN_0043c570(0x5654);
  FUN_0046b6f0(0x620c);
  FUN_0046b6f0(0x6216);
  FUN_0043c570(0x6270);
  iVar12 = *(int *)(in_ECX + 0x100);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar12 + 0xa4) = 1;
  iVar12 = *(int *)(in_ECX + 0x100);
  if (((*(char *)(iVar12 + 0xa4) != '\0') && (*(int **)(iVar12 + 0x94) != (int *)0x0)) &&
     (iVar6 = (**(code **)(**(int **)(iVar12 + 0x94) + 4))(), iVar6 == 0xbf6b)) {
    *(undefined1 *)(*(int *)(iVar12 + 0x94) + 0x4c) = 1;
  }
  iVar12 = *(int *)(in_ECX + 0x104);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar12 + 0xa4) = 1;
  iVar12 = *(int *)(in_ECX + 0x104);
  if (((*(char *)(iVar12 + 0xa4) != '\0') && (*(int **)(iVar12 + 0x94) != (int *)0x0)) &&
     (iVar6 = (**(code **)(**(int **)(iVar12 + 0x94) + 4))(), iVar6 == 0xbf6b)) {
    *(undefined1 *)(*(int *)(iVar12 + 0x94) + 0x4c) = 1;
  }
  local_14 = (char *)(in_ECX + 0x128);
  iVar12 = 0x5e38;
  do {
    FUN_0043c570(iVar12 + -10);
    FUN_0043c570(iVar12);
    local_14 = (char *)((int)local_14 + 4);
    iVar12 = iVar12 + 100;
  } while (iVar12 < 0x60f4);
  local_14 = (char *)(in_ECX + 0x180);
  iVar12 = 0x13ccc;
  do {
    FUN_00615fc0(iVar12 + -10000);
    FUN_00615fc0(iVar12);
    local_14 = (char *)((int)local_14 + 4);
    iVar12 = iVar12 + 1000;
  } while (iVar12 < 0x15c0c);
  iVar12 = *(int *)(in_ECX + 0x160);
  *(undefined4 *)(iVar12 + 0x29c) = 1;
  FUN_005e0050(iVar12,local_64);
  local_8 = 0;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  iVar12 = *(int *)(in_ECX + 0x164);
  *(undefined4 *)(iVar12 + 0x29c) = 2;
  FUN_005e0050(iVar12,local_64);
  local_8 = 1;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  iVar12 = *(int *)(in_ECX + 0x168);
  *(undefined4 *)(iVar12 + 0x29c) = 0xf;
  FUN_005e0050(iVar12,local_64);
  local_8 = 2;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  iVar12 = *(int *)(in_ECX + 0x16c);
  *(undefined4 *)(iVar12 + 0x29c) = 0xe;
  FUN_005e0050(iVar12,local_64);
  local_8 = 3;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  iVar12 = *(int *)(in_ECX + 0x170);
  *(undefined4 *)(iVar12 + 0x29c) = 0xd;
  FUN_005e0050(iVar12,local_64);
  local_8 = 4;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  iVar12 = *(int *)(in_ECX + 0x174);
  *(undefined4 *)(iVar12 + 0x29c) = 0xc;
  FUN_005e0050(iVar12,local_64);
  local_8 = 5;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  iVar12 = *(int *)(in_ECX + 0x178);
  *(undefined4 *)(iVar12 + 0x29c) = 3;
  FUN_005e0050(iVar12,local_64);
  local_8 = 6;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  iVar12 = *(int *)(in_ECX + 0x17c);
  *(undefined4 *)(iVar12 + 0x29c) = 5;
  FUN_005e0050(iVar12,local_64);
  local_8 = 7;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  iVar12 = *(int *)(in_ECX + 0x180);
  *(undefined4 *)(iVar12 + 0x29c) = 10;
  FUN_005e0050(iVar12,local_64);
  local_8 = 8;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  iVar12 = *(int *)(in_ECX + 0x184);
  *(undefined4 *)(iVar12 + 0x29c) = 0xb;
  FUN_005e0050(iVar12,local_64);
  local_8 = 9;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  iVar12 = *(int *)(in_ECX + 0x188);
  *(undefined4 *)(iVar12 + 0x29c) = 6;
  FUN_005e0050(iVar12,local_64);
  local_8 = 10;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  iVar12 = *(int *)(in_ECX + 0x18c);
  *(undefined4 *)(iVar12 + 0x29c) = 9;
  FUN_005e0050(iVar12,local_64);
  local_8 = 0xb;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  iVar12 = *(int *)(in_ECX + 400);
  *(undefined4 *)(iVar12 + 0x29c) = 7;
  FUN_005e0050(iVar12,local_64);
  local_8 = 0xc;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  iVar12 = *(int *)(in_ECX + 0x194);
  *(undefined4 *)(iVar12 + 0x29c) = 8;
  FUN_005e0050(iVar12,local_64);
  local_8 = 0xd;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  iVar12 = *(int *)(in_ECX + 0x198);
  *(undefined4 *)(iVar12 + 0x29c) = 4;
  FUN_005e0050(iVar12,local_64);
  local_8 = 0xe;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  iVar12 = *(int *)(in_ECX + 0x19c);
  *(undefined4 *)(iVar12 + 0x29c) = 0xffffffff;
  FUN_005e0050(iVar12,local_64);
  local_8 = 0xf;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  piVar13 = (int *)(in_ECX + 0x160);
  iVar12 = 0x10;
  do {
    (**(code **)(*(int *)*piVar13 + 0x198))(((int *)*piVar13)[8] + 1);
    piVar13 = piVar13 + 1;
    iVar12 = iVar12 + -1;
  } while (iVar12 != 0);
  piVar13 = (int *)(in_ECX + 0x144);
  local_30 = piVar13;
  FUN_00661310();
  FUN_00661400();
  FUN_0046b6f0(51000);
  iVar12 = *(int *)(in_ECX + 0x15c);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar12 + 0xa4) = 1;
  if ((*(int *)(*piVar13 + 0x24c) != 0) &&
     (iVar12 = *(int *)(*(int *)(*piVar13 + 0x24c) + 0xcc), iVar12 != 0)) {
    FUN_006438f0(iVar12);
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x10;
    _DAT_00fe5acc = 0;
    pcVar7 = (char *)FUN_00891268(0x30);
    if (pcVar7 == (char *)0x0) {
      local_14 = (char *)0x0;
      std::exception::exception((exception *)local_48,local_1c + 2);
      local_48[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_48,&DAT_00c857a8);
    }
    DAT_00fe5ac8 = pcVar7;
    *(char **)pcVar7 = pcVar7;
    *(char **)(DAT_00fe5ac8 + 4) = DAT_00fe5ac8;
    *(char **)(DAT_00fe5ac8 + 8) = DAT_00fe5ac8;
    DAT_00fe5ac8[0x2c] = '\x01';
    DAT_00fe5ac8[0x2d] = '\x01';
    local_8 = CONCAT31(local_8._1_3_,0x11);
    _DAT_00fe5adc = 0;
    iVar12 = FUN_00891268(0x30);
    if (iVar12 == 0) {
      local_1c[1] = (char *)0x0;
      std::exception::exception((exception *)local_3c,local_1c + 1);
      local_3c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_3c,&DAT_00c857a8);
    }
    DAT_00fe5ad8 = iVar12;
    *(int *)iVar12 = iVar12;
    *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
    *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
    *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  cVar2 = (*(char **)(DAT_00fe5ac8 + 4))[0x2d];
  pcVar7 = *(char **)(DAT_00fe5ac8 + 4);
  local_28 = DAT_00fe5ac8;
  while (pcVar10 = pcVar7, cVar2 == '\0') {
    if (*(int *)(pcVar10 + 0xc) < 0x25e) {
      pcVar7 = *(char **)(pcVar10 + 8);
      pcVar10 = local_28;
    }
    else {
      pcVar7 = *(char **)pcVar10;
    }
    cVar2 = pcVar7[0x2d];
    local_28 = pcVar10;
  }
  if ((local_28 == DAT_00fe5ac8) || (0x25e < *(int *)(local_28 + 0xc))) {
    local_24 = DAT_00fe5ac8;
    ppcVar8 = &local_24;
  }
  else {
    ppcVar8 = &local_28;
  }
  pcVar7 = *ppcVar8;
  if (pcVar7 == DAT_00fe5ac8) {
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  local_20 = pcVar7 + 0x10;
  if (7 < *(uint *)(pcVar7 + 0x24)) {
    local_20 = *(char **)local_20;
  }
  local_2c = (char *)*piVar13;
  if (*(int *)(local_2c + 0x24c) != 0) {
    piVar13 = *(int **)(*(int *)(local_2c + 0x24c) + 0xcc);
    if (piVar13 == (int *)0x0) {
      pcVar7 = (char *)0xffffffff;
    }
    else {
      local_28 = (char *)piVar13[0x39];
      piVar3 = (int *)piVar13[0x29];
      if (piVar3 == (int *)0x0) {
        pcVar7 = (char *)0xffffffff;
      }
      else {
        if (piVar13[0x2e] == piVar13[0x2f]) {
          pcVar7 = (char *)(**(code **)(*piVar3 + 0x28))();
          local_24 = pcVar7;
        }
        else {
          pcVar7 = *(char **)(piVar13[0x2f] + -4);
          local_24 = pcVar7;
          (**(code **)(*piVar3 + 0x2c))(pcVar7);
          if (piVar13[0x2e] != piVar13[0x2f]) {
            piVar13[0x2f] = piVar13[0x2f] + -4;
          }
        }
        *(char **)(pcVar7 + 0x20) = local_28;
        local_1c[0] = pcVar7;
        (**(code **)(*piVar13 + 0x70))(pcVar7);
        ppcVar8 = (char **)piVar13[0x2b];
        puVar1 = (uint *)(piVar13 + 0x2a);
        if ((local_1c < ppcVar8) && (ppcVar4 = (char **)*puVar1, ppcVar4 <= local_1c)) {
          local_24 = (char *)((int)local_1c - (int)ppcVar4 >> 2);
          if (ppcVar8 == (char **)piVar13[0x2c]) {
            uVar9 = (int)ppcVar8 - (int)ppcVar4 >> 2;
            if (0x3ffffffe < uVar9) {
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("vector<T> too long");
            }
            uVar9 = uVar9 + 1;
            uVar11 = piVar13[0x2c] - (int)ppcVar4 >> 2;
            if (uVar11 < uVar9) {
              if (0x3fffffff - (uVar11 >> 1) < uVar11) {
                uVar11 = 0;
              }
              else {
                uVar11 = uVar11 + (uVar11 >> 1);
              }
              if (uVar11 < uVar9) {
                uVar11 = uVar9;
              }
              FUN_00797980(uVar11);
            }
          }
          if ((undefined4 *)piVar13[0x2b] != (undefined4 *)0x0) {
            *(undefined4 *)piVar13[0x2b] = *(undefined4 *)(*puVar1 + (int)local_24 * 4);
          }
        }
        else {
          if (ppcVar8 == (char **)piVar13[0x2c]) {
            uVar9 = (int)((int)ppcVar8 - *puVar1) >> 2;
            if (0x3ffffffe < uVar9) {
                    /* WARNING: Subroutine does not return */
              FUN_0087db30("vector<T> too long");
            }
            uVar9 = uVar9 + 1;
            uVar11 = (int)(piVar13[0x2c] - *puVar1) >> 2;
            if (uVar11 < uVar9) {
              if (0x3fffffff - (uVar11 >> 1) < uVar11) {
                uVar11 = 0;
              }
              else {
                uVar11 = uVar11 + (uVar11 >> 1);
              }
              if (uVar11 < uVar9) {
                uVar11 = uVar9;
              }
              FUN_00797980(uVar11);
              pcVar7 = local_24;
            }
          }
          if ((undefined4 *)piVar13[0x2b] != (undefined4 *)0x0) {
            *(undefined4 *)piVar13[0x2b] = pcVar7;
          }
        }
        piVar13[0x2b] = piVar13[0x2b] + 4;
        pcVar7 = local_28 + 1;
        if (local_28 + 1 <= (char *)piVar13[0x39]) {
          pcVar7 = (char *)piVar13[0x39];
        }
        piVar13[0x39] = (int)pcVar7;
        pcVar7 = local_28;
      }
    }
    iVar12 = *(int *)(*(int *)(local_2c + 0x24c) + 0xcc);
    if (iVar12 != 0) {
      for (piVar13 = *(int **)(iVar12 + 0xa8);
          (piVar13 != *(int **)(iVar12 + 0xac) && (*(char **)(*piVar13 + 0x20) != pcVar7));
          piVar13 = piVar13 + 1) {
      }
    }
    FUN_00757710();
    piVar13 = local_30;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x12;
    _DAT_00fe5acc = 0;
    pcVar7 = (char *)FUN_00891268(0x30);
    if (pcVar7 == (char *)0x0) {
      local_20 = (char *)0x0;
      std::exception::exception((exception *)local_3c,&local_20);
      local_3c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_3c,&DAT_00c857a8);
    }
    DAT_00fe5ac8 = pcVar7;
    *(char **)pcVar7 = pcVar7;
    *(char **)(DAT_00fe5ac8 + 4) = DAT_00fe5ac8;
    *(char **)(DAT_00fe5ac8 + 8) = DAT_00fe5ac8;
    DAT_00fe5ac8[0x2c] = '\x01';
    DAT_00fe5ac8[0x2d] = '\x01';
    local_8 = CONCAT31(local_8._1_3_,0x13);
    _DAT_00fe5adc = 0;
    iVar12 = FUN_00891268(0x30);
    if (iVar12 == 0) {
      local_1c[0] = (char *)0x0;
      std::exception::exception((exception *)local_48,local_1c);
      local_48[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_48,&DAT_00c857a8);
    }
    DAT_00fe5ad8 = iVar12;
    *(int *)iVar12 = iVar12;
    *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
    *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
    *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
    *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  pcVar7 = DAT_00fe5ac8;
  local_30 = (int *)0x25f;
  FUN_005740f0(&local_30);
  if (local_2c == pcVar7) {
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  pcVar7 = local_2c + 0x10;
  if (7 < *(uint *)(local_2c + 0x24)) {
    pcVar7 = *(char **)pcVar7;
  }
  FUN_0075cbb0(pcVar7);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x14;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_30 = (int *)0x260;
  FUN_005740f0(&local_30);
  if (local_2c == DAT_00fe5ac8) {
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  pcVar7 = local_2c + 0x10;
  if (7 < *(uint *)(local_2c + 0x24)) {
    pcVar7 = *(char **)pcVar7;
  }
  FUN_0075cbb0(pcVar7);
  FUN_0075cd30(*piVar13);
  if (*(int *)(*piVar13 + 0x24c) != 0) {
    FUN_00749920(*(int *)(*piVar13 + 0x24c));
  }
  (**(code **)(*(int *)*piVar13 + 200))();
  ExceptionList = local_10;
  return;
}

