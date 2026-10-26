
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0065e680(void)

{
  uint *puVar1;
  char cVar2;
  char **ppcVar3;
  code *pcVar4;
  int iVar5;
  char *pcVar6;
  char **ppcVar7;
  uint uVar8;
  int in_ECX;
  char *pcVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  undefined ***pppuVar13;
  undefined4 local_64 [5];
  uint local_50;
  undefined **local_48 [3];
  undefined **local_3c [3];
  int local_30;
  char *local_2c;
  char *local_28;
  int *local_24;
  char *local_20;
  char *local_1c [2];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092cf9c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00755e50(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_0043c570(10000);
  FUN_0043c570(0x526c);
  FUN_0043c570(0x5654);
  FUN_0043c570(0x620c);
  FUN_0046b6f0(0x6270);
  FUN_0046b6f0(0x627a);
  FUN_0043c570(0x65f4);
  iVar11 = *(int *)(in_ECX + 0x104);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar11 + 0xa4) = 1;
  iVar11 = *(int *)(in_ECX + 0x104);
  if (((*(char *)(iVar11 + 0xa4) != '\0') && (*(int **)(iVar11 + 0x94) != (int *)0x0)) &&
     (iVar5 = (**(code **)(**(int **)(iVar11 + 0x94) + 4))(), iVar5 == 0xbf6b)) {
    *(undefined1 *)(*(int *)(iVar11 + 0x94) + 0x4c) = 1;
  }
  iVar11 = *(int *)(in_ECX + 0x108);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar11 + 0xa4) = 1;
  iVar11 = *(int *)(in_ECX + 0x108);
  if (((*(char *)(iVar11 + 0xa4) != '\0') && (*(int **)(iVar11 + 0x94) != (int *)0x0)) &&
     (iVar5 = (**(code **)(**(int **)(iVar11 + 0x94) + 4))(), iVar5 == 0xbf6b)) {
    *(undefined1 *)(*(int *)(iVar11 + 0x94) + 0x4c) = 1;
  }
  local_14 = (char *)(in_ECX + 300);
  iVar11 = 0x5e38;
  do {
    FUN_0043c570(iVar11 + -10);
    FUN_0043c570(iVar11);
    local_14 = (char *)((int)local_14 + 4);
    iVar11 = iVar11 + 100;
  } while (iVar11 < 0x60f4);
  local_14 = (char *)(in_ECX + 0x188);
  iVar11 = 0x13ccc;
  do {
    FUN_00615fc0(iVar11 + -10000);
    FUN_00615fc0(iVar11);
    local_14 = (char *)((int)local_14 + 4);
    iVar11 = iVar11 + 1000;
  } while (iVar11 < 0x15c0c);
  iVar11 = *(int *)(in_ECX + 0x168);
  *(undefined4 *)(iVar11 + 0x29c) = 1;
  FUN_005e0050(iVar11,local_64);
  local_8 = 0;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  local_2c = *(char **)(in_ECX + 0x16c);
  local_2c[0x29c] = '\x02';
  local_2c[0x29d] = '\0';
  local_2c[0x29e] = '\0';
  local_2c[0x29f] = '\0';
  FUN_005e0050(local_2c,local_64);
  local_8 = 1;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  local_2c = *(char **)(in_ECX + 0x170);
  local_2c[0x29c] = '\x0f';
  local_2c[0x29d] = '\0';
  local_2c[0x29e] = '\0';
  local_2c[0x29f] = '\0';
  FUN_005e0050(local_2c,local_64);
  local_8 = 2;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  local_2c = *(char **)(in_ECX + 0x174);
  local_2c[0x29c] = '\x0e';
  local_2c[0x29d] = '\0';
  local_2c[0x29e] = '\0';
  local_2c[0x29f] = '\0';
  FUN_005e0050(local_2c,local_64);
  local_8 = 3;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  local_2c = *(char **)(in_ECX + 0x178);
  local_2c[0x29c] = '\r';
  local_2c[0x29d] = '\0';
  local_2c[0x29e] = '\0';
  local_2c[0x29f] = '\0';
  FUN_005e0050(local_2c,local_64);
  local_8 = 4;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  local_2c = *(char **)(in_ECX + 0x17c);
  local_2c[0x29c] = '\f';
  local_2c[0x29d] = '\0';
  local_2c[0x29e] = '\0';
  local_2c[0x29f] = '\0';
  FUN_005e0050(local_2c,local_64);
  local_8 = 5;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  local_2c = *(char **)(in_ECX + 0x180);
  local_2c[0x29c] = '\x03';
  local_2c[0x29d] = '\0';
  local_2c[0x29e] = '\0';
  local_2c[0x29f] = '\0';
  FUN_005e0050(local_2c,local_64);
  local_8 = 6;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  local_2c = *(char **)(in_ECX + 0x184);
  local_2c[0x29c] = '\x05';
  local_2c[0x29d] = '\0';
  local_2c[0x29e] = '\0';
  local_2c[0x29f] = '\0';
  FUN_005e0050(local_2c,local_64);
  local_8 = 7;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  local_2c = *(char **)(in_ECX + 0x188);
  local_2c[0x29c] = '\n';
  local_2c[0x29d] = '\0';
  local_2c[0x29e] = '\0';
  local_2c[0x29f] = '\0';
  FUN_005e0050(local_2c,local_64);
  local_8 = 8;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  local_2c = *(char **)(in_ECX + 0x18c);
  local_2c[0x29c] = '\v';
  local_2c[0x29d] = '\0';
  local_2c[0x29e] = '\0';
  local_2c[0x29f] = '\0';
  FUN_005e0050(local_2c,local_64);
  local_8 = 9;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  local_2c = *(char **)(in_ECX + 400);
  local_2c[0x29c] = '\x06';
  local_2c[0x29d] = '\0';
  local_2c[0x29e] = '\0';
  local_2c[0x29f] = '\0';
  FUN_005e0050(local_2c,local_64);
  local_8 = 10;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  local_2c = *(char **)(in_ECX + 0x194);
  local_2c[0x29c] = '\t';
  local_2c[0x29d] = '\0';
  local_2c[0x29e] = '\0';
  local_2c[0x29f] = '\0';
  FUN_005e0050(local_2c,local_64);
  local_8 = 0xb;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  local_2c = *(char **)(in_ECX + 0x198);
  local_2c[0x29c] = '\a';
  local_2c[0x29d] = '\0';
  local_2c[0x29e] = '\0';
  local_2c[0x29f] = '\0';
  FUN_005e0050(local_2c,local_64);
  local_8 = 0xc;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  local_2c = *(char **)(in_ECX + 0x19c);
  local_2c[0x29c] = '\b';
  local_2c[0x29d] = '\0';
  local_2c[0x29e] = '\0';
  local_2c[0x29f] = '\0';
  FUN_005e0050(local_2c,local_64);
  local_8 = 0xd;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  local_2c = *(char **)(in_ECX + 0x1a0);
  local_2c[0x29c] = '\x04';
  local_2c[0x29d] = '\0';
  local_2c[0x29e] = '\0';
  local_2c[0x29f] = '\0';
  FUN_005e0050(local_2c,local_64);
  local_8 = 0xe;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  local_2c = *(char **)(in_ECX + 0x1a4);
  local_2c[0x29c] = -1;
  local_2c[0x29d] = -1;
  local_2c[0x29e] = -1;
  local_2c[0x29f] = -1;
  FUN_005e0050(local_2c,local_64);
  local_8 = 0xf;
  FUN_004026e0(local_64,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_50) {
    FUN_0089120c(local_64[0]);
  }
  iVar11 = 0;
  piVar12 = (int *)(in_ECX + 0x168);
  do {
    (**(code **)(*(int *)*piVar12 + 0x198))(((int *)*piVar12)[8] + 1);
    *(undefined1 *)(*piVar12 + 0x268) = 1;
    if (iVar11 - 8U < 6) {
      (**(code **)(**(int **)(*piVar12 + 0x2a4) + 0x94))(1);
    }
    iVar11 = iVar11 + 1;
    piVar12 = piVar12 + 1;
  } while (iVar11 < 0x10);
  local_24 = (int *)(in_ECX + 0x148);
  FUN_00661310();
  FUN_00661400();
  FUN_0046b6f0(51000);
  FUN_00458330();
  iVar11 = *(int *)(in_ECX + 0x160);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar11 + 0xa4) = 1;
  if ((*(int *)(*local_24 + 0x24c) != 0) &&
     (iVar11 = *(int *)(*(int *)(*local_24 + 0x24c) + 0xcc), iVar11 != 0)) {
    FUN_006438f0(iVar11);
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x10;
    _DAT_00fe5acc = 0;
    pcVar6 = (char *)FUN_00891268(0x30);
    if (pcVar6 != (char *)0x0) {
      DAT_00fe5ac8 = pcVar6;
      *(char **)pcVar6 = pcVar6;
      *(char **)(DAT_00fe5ac8 + 4) = DAT_00fe5ac8;
      *(char **)(DAT_00fe5ac8 + 8) = DAT_00fe5ac8;
      DAT_00fe5ac8[0x2c] = '\x01';
      DAT_00fe5ac8[0x2d] = '\x01';
      local_8 = CONCAT31(local_8._1_3_,0x11);
      _DAT_00fe5adc = 0;
      iVar11 = FUN_00891268(0x30);
      if (iVar11 == 0) {
        local_1c[1] = (char *)0x0;
        std::exception::exception((exception *)local_3c,local_1c + 1);
        local_3c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
        __CxxThrowException_8(local_3c,&DAT_00c857a8);
      }
      DAT_00fe5ad8 = iVar11;
      *(int *)iVar11 = iVar11;
      *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
      *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
      *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
      *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
      goto LAB_0065eea3;
    }
    local_14 = (char *)0x0;
    ppcVar7 = local_1c + 2;
  }
  else {
LAB_0065eea3:
    cVar2 = (*(char **)(DAT_00fe5ac8 + 4))[0x2d];
    pcVar6 = *(char **)(DAT_00fe5ac8 + 4);
    local_2c = DAT_00fe5ac8;
    while (pcVar9 = pcVar6, cVar2 == '\0') {
      if (*(int *)(pcVar9 + 0xc) < 0x25e) {
        pcVar6 = *(char **)(pcVar9 + 8);
        pcVar9 = local_2c;
      }
      else {
        pcVar6 = *(char **)pcVar9;
      }
      cVar2 = pcVar6[0x2d];
      local_2c = pcVar9;
    }
    if ((local_2c == DAT_00fe5ac8) || (0x25e < *(int *)(local_2c + 0xc))) {
      local_28 = DAT_00fe5ac8;
      ppcVar7 = &local_28;
    }
    else {
      ppcVar7 = &local_2c;
    }
    pcVar6 = *ppcVar7;
    if (pcVar6 == DAT_00fe5ac8) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    local_20 = pcVar6 + 0x10;
    if (7 < *(uint *)(pcVar6 + 0x24)) {
      local_20 = *(char **)local_20;
    }
    local_30 = *local_24;
    if (*(int *)(local_30 + 0x24c) != 0) {
      piVar12 = *(int **)(*(int *)(local_30 + 0x24c) + 0xcc);
      if (piVar12 == (int *)0x0) {
        pcVar6 = (char *)0xffffffff;
      }
      else {
        local_2c = (char *)piVar12[0x39];
        if ((int *)piVar12[0x29] == (int *)0x0) {
          pcVar6 = (char *)0xffffffff;
        }
        else {
          iVar11 = *(int *)piVar12[0x29];
          if (piVar12[0x2e] == piVar12[0x2f]) {
            pcVar6 = (char *)(**(code **)(iVar11 + 0x28))();
            local_28 = pcVar6;
          }
          else {
            pcVar6 = *(char **)(piVar12[0x2f] + -4);
            local_28 = pcVar6;
            (**(code **)(iVar11 + 0x2c))(pcVar6);
            if (piVar12[0x2e] != piVar12[0x2f]) {
              piVar12[0x2f] = piVar12[0x2f] + -4;
            }
          }
          *(char **)(pcVar6 + 0x20) = local_2c;
          local_1c[0] = pcVar6;
          (**(code **)(*piVar12 + 0x70))(pcVar6);
          ppcVar7 = (char **)piVar12[0x2b];
          puVar1 = (uint *)(piVar12 + 0x2a);
          if ((local_1c < ppcVar7) && (ppcVar3 = (char **)*puVar1, ppcVar3 <= local_1c)) {
            local_28 = (char *)((int)local_1c - (int)ppcVar3 >> 2);
            if (ppcVar7 == (char **)piVar12[0x2c]) {
              uVar8 = (int)ppcVar7 - (int)ppcVar3 >> 2;
              if (0x3ffffffe < uVar8) {
                    /* WARNING: Subroutine does not return */
                FUN_0087db30("vector<T> too long");
              }
              uVar8 = uVar8 + 1;
              uVar10 = piVar12[0x2c] - (int)ppcVar3 >> 2;
              if (uVar10 < uVar8) {
                if (0x3fffffff - (uVar10 >> 1) < uVar10) {
                  uVar10 = 0;
                }
                else {
                  uVar10 = uVar10 + (uVar10 >> 1);
                }
                if (uVar10 < uVar8) {
                  uVar10 = uVar8;
                }
                FUN_00797980(uVar10);
              }
            }
            if ((undefined4 *)piVar12[0x2b] != (undefined4 *)0x0) {
              *(undefined4 *)piVar12[0x2b] = *(undefined4 *)(*puVar1 + (int)local_28 * 4);
            }
          }
          else {
            if (ppcVar7 == (char **)piVar12[0x2c]) {
              uVar8 = (int)((int)ppcVar7 - *puVar1) >> 2;
              if (0x3ffffffe < uVar8) {
                    /* WARNING: Subroutine does not return */
                FUN_0087db30("vector<T> too long");
              }
              uVar8 = uVar8 + 1;
              uVar10 = (int)(piVar12[0x2c] - *puVar1) >> 2;
              if (uVar10 < uVar8) {
                if (0x3fffffff - (uVar10 >> 1) < uVar10) {
                  uVar10 = 0;
                }
                else {
                  uVar10 = uVar10 + (uVar10 >> 1);
                }
                if (uVar10 < uVar8) {
                  uVar10 = uVar8;
                }
                FUN_00797980(uVar10);
                pcVar6 = local_28;
              }
            }
            if ((undefined4 *)piVar12[0x2b] != (undefined4 *)0x0) {
              *(undefined4 *)piVar12[0x2b] = pcVar6;
            }
          }
          piVar12[0x2b] = piVar12[0x2b] + 4;
          pcVar6 = local_2c + 1;
          if (local_2c + 1 <= (char *)piVar12[0x39]) {
            pcVar6 = (char *)piVar12[0x39];
          }
          piVar12[0x39] = (int)pcVar6;
          pcVar6 = local_2c;
        }
      }
      iVar11 = *(int *)(*(int *)(local_30 + 0x24c) + 0xcc);
      if (iVar11 != 0) {
        for (piVar12 = *(int **)(iVar11 + 0xa8);
            (piVar12 != *(int **)(iVar11 + 0xac) && (*(char **)(*piVar12 + 0x20) != pcVar6));
            piVar12 = piVar12 + 1) {
        }
      }
      FUN_00757710();
    }
    piVar12 = local_24;
    if ((DAT_00fe5ae4 & 1) != 0) {
LAB_0065f20c:
      pcVar6 = DAT_00fe5ac8;
      local_30 = 0x25f;
      FUN_005740f0(&local_30);
      if (local_2c == pcVar6) {
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      pcVar6 = local_2c + 0x10;
      if (7 < *(uint *)(local_2c + 0x24)) {
        pcVar6 = *(char **)pcVar6;
      }
      FUN_0075cbb0(pcVar6);
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_8 = 0x14;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
        local_8 = 0xffffffff;
      }
      local_30 = 0x260;
      FUN_005740f0(&local_30);
      if (local_2c != DAT_00fe5ac8) {
        pcVar6 = local_2c + 0x10;
        if (7 < *(uint *)(local_2c + 0x24)) {
          pcVar6 = *(char **)pcVar6;
        }
        FUN_0075cbb0(pcVar6);
        if ((DAT_00fe5ae4 & 1) == 0) {
          DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
          local_8 = 0x15;
          FUN_00584c40(&DAT_00fe5ac4);
          _atexit((_func_4879 *)&LAB_00bcf390);
          local_8 = 0xffffffff;
        }
        local_30 = 0x261;
        FUN_005740f0(&local_30);
        if (local_2c != DAT_00fe5ac8) {
          pcVar6 = local_2c + 0x10;
          if (7 < *(uint *)(local_2c + 0x24)) {
            pcVar6 = *(char **)pcVar6;
          }
          FUN_0075cbb0(pcVar6);
          if ((DAT_00fe5ae4 & 1) == 0) {
            DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
            local_8 = 0x16;
            FUN_00584c40(&DAT_00fe5ac4);
            _atexit((_func_4879 *)&LAB_00bcf390);
            local_8 = 0xffffffff;
          }
          local_30 = 0x262;
          FUN_005740f0(&local_30);
          if (local_2c != DAT_00fe5ac8) {
            pcVar6 = local_2c + 0x10;
            if (7 < *(uint *)(local_2c + 0x24)) {
              pcVar6 = *(char **)pcVar6;
            }
            FUN_0075cbb0(pcVar6);
            FUN_0075cd30(*piVar12);
            if (*(int *)(*piVar12 + 0x24c) != 0) {
              FUN_00749920(*(int *)(*piVar12 + 0x24c));
            }
            (**(code **)(*(int *)*piVar12 + 200))();
            ExceptionList = local_10;
            return;
          }
          pcVar4 = (code *)swi(3);
          (*pcVar4)();
          return;
        }
        pcVar4 = (code *)swi(3);
        (*pcVar4)();
        return;
      }
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0x12;
    _DAT_00fe5acc = 0;
    pcVar6 = (char *)FUN_00891268(0x30);
    if (pcVar6 == (char *)0x0) {
      local_24 = (int *)0x0;
      std::exception::exception((exception *)local_3c,(char **)&local_24);
      pppuVar13 = local_3c;
      local_3c[0] = std::bad_alloc::vftable;
      goto LAB_0065ef0d;
    }
    DAT_00fe5ac8 = pcVar6;
    *(char **)pcVar6 = pcVar6;
    *(char **)(DAT_00fe5ac8 + 4) = DAT_00fe5ac8;
    *(char **)(DAT_00fe5ac8 + 8) = DAT_00fe5ac8;
    DAT_00fe5ac8[0x2c] = '\x01';
    DAT_00fe5ac8[0x2d] = '\x01';
    local_8 = CONCAT31(local_8._1_3_,0x13);
    _DAT_00fe5adc = 0;
    iVar11 = FUN_00891268(0x30);
    if (iVar11 != 0) {
      DAT_00fe5ad8 = iVar11;
      *(int *)iVar11 = iVar11;
      *(int *)(DAT_00fe5ad8 + 4) = DAT_00fe5ad8;
      *(int *)(DAT_00fe5ad8 + 8) = DAT_00fe5ad8;
      *(undefined1 *)(DAT_00fe5ad8 + 0x2c) = 1;
      *(undefined1 *)(DAT_00fe5ad8 + 0x2d) = 1;
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
      goto LAB_0065f20c;
    }
    local_20 = (char *)0x0;
    ppcVar7 = &local_20;
  }
  std::exception::exception((exception *)local_48,ppcVar7);
  pppuVar13 = local_48;
  local_48[0] = std::bad_alloc::vftable;
LAB_0065ef0d:
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(pppuVar13,&DAT_00c857a8);
}

