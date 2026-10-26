
void FUN_00635ca0(void)

{
  int **ppiVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int **ppiVar5;
  int **ppiVar6;
  int unaff_EDI;
  int local_50;
  int local_4c;
  undefined4 local_48;
  int local_40;
  int local_3c;
  undefined4 local_38;
  int **local_30;
  int **local_2c;
  int **local_28;
  int local_20;
  int local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00948a04;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  ppiVar6 = (int **)0x0;
  if (*(int *)(unaff_EDI + 0xb8) != 0) {
    local_50 = 0;
    local_4c = 0;
    local_48 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    uStack_7 = 0;
    if ((DAT_00fab29c & 1) == 0) {
      DAT_00fab29c = DAT_00fab29c | 1;
      local_8 = 2;
      uStack_7 = 0;
      FUN_004ffe60(uVar2);
      _atexit((_func_4879 *)&LAB_00bccf00);
    }
    local_8 = 1;
    FUN_00500950(&DAT_00fab2a0,*(undefined4 *)(unaff_EDI + 0x84),&local_50);
    if ((DAT_00fab29c & 1) == 0) {
      DAT_00fab29c = DAT_00fab29c | 1;
      local_8 = 3;
      FUN_004ffe60(uVar2);
      _atexit((_func_4879 *)&LAB_00bccf00);
      local_8 = 1;
    }
    FUN_00500e00(&DAT_00fab2a0,*(undefined4 *)(unaff_EDI + 0x84),&local_40);
    *(bool *)(unaff_EDI + 0xb4) = local_50 != local_4c;
    *(bool *)(unaff_EDI + 0xb5) = local_40 != local_3c;
    local_30 = (int **)0x0;
    local_2c = (int **)0x0;
    local_28 = (int **)0x0;
    _local_8 = CONCAT31(uStack_7,4);
    iVar3 = (*(int *)(*(int *)(unaff_EDI + 0xb8) + 0x44) -
            *(int *)(*(int *)(unaff_EDI + 0xb8) + 0x40)) / 0x24;
    local_1c = 0;
    if (iVar3 != 0) {
      local_18 = 0;
      local_20 = iVar3;
      do {
        piVar4 = (int *)(*(int *)(*(int *)(unaff_EDI + 0xb8) + 0x40) + local_18);
        local_14 = piVar4;
        iVar3 = FUN_005243a0(piVar4);
        if (iVar3 != 0) {
          if (local_1c < *piVar4) {
            local_1c = *piVar4;
          }
          if ((&local_14 < ppiVar6) && (local_30 <= &local_14)) {
            iVar3 = (int)&local_14 - (int)local_30;
            if (ppiVar6 == local_28) {
              FUN_004deab0();
              ppiVar6 = local_2c;
            }
            if (ppiVar6 != (int **)0x0) {
              *ppiVar6 = local_30[iVar3 >> 2];
            }
          }
          else {
            if (ppiVar6 == local_28) {
              FUN_004deab0();
              ppiVar6 = local_2c;
            }
            if (ppiVar6 != (int **)0x0) {
              *ppiVar6 = piVar4;
            }
          }
          ppiVar6 = ppiVar6 + 1;
          local_2c = ppiVar6;
        }
        local_18 = local_18 + 0x24;
        local_20 = local_20 + -1;
      } while (local_20 != 0);
    }
    ppiVar5 = local_30;
    ppiVar1 = local_2c;
    if (local_30 != ppiVar6) {
      do {
        if (**ppiVar5 == local_1c) {
          ppiVar5 = ppiVar5 + 1;
        }
        else {
          FID_conflict__memcpy(ppiVar5,ppiVar5 + 1,((int)ppiVar6 - (int)(ppiVar5 + 1) >> 2) * 4);
          ppiVar6 = ppiVar6 + -1;
        }
        ppiVar1 = ppiVar6;
      } while (ppiVar5 != ppiVar6);
    }
    local_2c = ppiVar1;
    *(undefined4 *)(unaff_EDI + 0x98) = 0;
    if (local_30 == ppiVar6) {
      *(undefined4 *)(unaff_EDI + 0x94) = 0;
      FUN_007b6d70();
      ppiVar5 = local_30;
    }
    else {
      iVar3 = FUN_0089289d();
      ppiVar5 = local_30;
      piVar4 = local_30[iVar3 % ((int)ppiVar6 - (int)local_30 >> 2)];
      *(int **)(unaff_EDI + 0x94) = piVar4;
      FUN_00635f10(*(undefined4 *)(piVar4[5] + *(int *)(unaff_EDI + 0x98) * 4));
    }
    if (ppiVar5 != (int **)0x0) {
      FUN_0089120c(ppiVar5);
    }
    if (local_40 != 0) {
      FUN_0089120c(local_40);
    }
    if (local_50 != 0) {
      FUN_0089120c(local_50);
    }
  }
  ExceptionList = local_10;
  return;
}

