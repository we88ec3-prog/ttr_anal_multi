
undefined4 FUN_0047d610(void)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int unaff_EDI;
  int local_40 [2];
  int local_38;
  int local_34;
  int local_30;
  int local_28 [5];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00947e4c;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  FUN_008438c0(unaff_EDI + 0x11c);
  iVar7 = *(int *)(local_40[0] + 0x10);
  if ((DAT_00fab29c & 1) == 0) {
    DAT_00fab29c = DAT_00fab29c | 1;
    local_c = 0;
    FUN_004ffe60(uVar3);
    _atexit((_func_4879 *)&LAB_00bccf00);
    local_c = 0xffffffff;
  }
  FUN_00503440(&DAT_00fab2a0,&local_38,iVar7 + 0x24);
  iVar7 = local_38;
  local_c = 1;
  iVar6 = local_34 - local_38 >> 2;
  uVar4 = 0;
  if (iVar6 != 1) {
    do {
      iVar1 = uVar4 * 4;
      uVar4 = uVar4 + 1;
      if (*(int *)(unaff_EDI + 0x120) == **(int **)(local_38 + iVar1)) {
        *(uint *)(unaff_EDI + 0x124) = uVar4;
        goto LAB_0047d78e;
      }
    } while (uVar4 < iVar6 - 1U);
  }
  local_40[0] = *(int *)(unaff_EDI + 0x11c) + 1;
  piVar5 = (int *)FUN_008438c0(local_40);
  if (*piVar5 != *(int *)(unaff_EDI + 0x110)) {
    puVar2 = *(undefined4 **)(*piVar5 + 0x10);
    if ((DAT_00fab29c & 1) == 0) {
      DAT_00fab29c = DAT_00fab29c | 1;
      local_c._0_1_ = 2;
      FUN_004ffe60(uVar3);
      _atexit((_func_4879 *)&LAB_00bccf00);
      local_c = CONCAT31(local_c._1_3_,1);
    }
    piVar5 = (int *)FUN_00503440(&DAT_00fab2a0,local_28,puVar2 + 9);
    if (&local_38 != piVar5) {
      if (local_38 != 0) {
        FUN_0089120c(local_38);
      }
      local_38 = *piVar5;
      local_34 = piVar5[1];
      local_30 = piVar5[2];
      *piVar5 = 0;
      piVar5[1] = 0;
      piVar5[2] = 0;
    }
    if (local_28[0] != 0) {
      FUN_0089120c(local_28[0]);
    }
    iVar7 = local_38;
    if (local_38 != local_34) {
      *(undefined4 *)(unaff_EDI + 0x11c) = *puVar2;
      *(undefined4 *)(unaff_EDI + 0x124) = 0;
LAB_0047d78e:
      if (local_38 != 0) {
        FUN_0089120c(local_38);
      }
      ExceptionList = local_14;
      return 1;
    }
  }
  if (iVar7 != 0) {
    FUN_0089120c(iVar7);
  }
  ExceptionList = local_14;
  return 0;
}

