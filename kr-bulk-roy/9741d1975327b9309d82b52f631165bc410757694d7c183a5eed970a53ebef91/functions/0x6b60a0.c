
void FUN_006b60a0(int param_1,undefined4 param_2)

{
  char cVar1;
  short sVar2;
  int *piVar3;
  code *pcVar4;
  short *psVar5;
  undefined4 uVar6;
  int iVar7;
  short *psVar8;
  undefined4 *puVar9;
  short *psVar10;
  undefined4 *puVar11;
  int local_54;
  int local_50;
  undefined4 local_4c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0092c0c6;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar9 = (undefined4 *)&stack0x0000000c;
  puVar11 = (undefined4 *)(param_1 + 0x114);
  for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar11 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar11 = puVar11 + 1;
  }
  *(undefined2 *)puVar11 = *(undefined2 *)puVar9;
  *(undefined1 *)((int)puVar11 + 2) = *(undefined1 *)((int)puVar9 + 2);
  *(undefined4 *)(param_1 + 0x110) = param_2;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffff0000;
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  cVar1 = *(char *)(param_1 + 0x114);
  if (cVar1 == '\0') {
    local_50 = 0x22a;
    iVar7 = FUN_00585620(local_14);
    FUN_005740f0(&local_50);
    if (local_54 == *(int *)(iVar7 + 4)) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    if (*(uint *)(local_54 + 0x24) < 8) {
      psVar8 = (short *)(local_54 + 0x10);
    }
    else {
      psVar8 = *(short **)(local_54 + 0x10);
    }
    psVar10 = psVar8 + 1;
    psVar5 = psVar8;
    do {
      sVar2 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar2 != 0);
  }
  else if (cVar1 == '\x01') {
    local_50 = 0x229;
    iVar7 = FUN_00585620(local_14);
    FUN_005740f0(&local_50);
    if (local_54 == *(int *)(iVar7 + 4)) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    if (*(uint *)(local_54 + 0x24) < 8) {
      psVar8 = (short *)(local_54 + 0x10);
    }
    else {
      psVar8 = *(short **)(local_54 + 0x10);
    }
    psVar10 = psVar8 + 1;
    psVar5 = psVar8;
    do {
      sVar2 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar2 != 0);
  }
  else {
    if (cVar1 != '\x02') goto LAB_006b6219;
    local_54 = 0x22b;
    iVar7 = FUN_00585620(local_14);
    FUN_005740f0(&local_54);
    if (local_50 == *(int *)(iVar7 + 4)) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    if (*(uint *)(local_50 + 0x24) < 8) {
      psVar8 = (short *)(local_50 + 0x10);
    }
    else {
      psVar8 = *(short **)(local_50 + 0x10);
    }
    psVar10 = psVar8 + 1;
    psVar5 = psVar8;
    do {
      sVar2 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar2 != 0);
  }
  FUN_00402160(psVar8,(int)psVar5 - (int)psVar10 >> 1);
LAB_006b6219:
  FUN_00757800(local_30);
  (**(code **)(**(int **)(param_1 + 0xf0) + 200))();
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8._0_1_ = 1;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
    local_8._0_1_ = 0;
  }
  FUN_004f6a30(*(undefined4 *)(param_1 + 0x115));
  FUN_00757710();
  (**(code **)(**(int **)(param_1 + 0xf4) + 200))();
  uVar6 = FUN_0040ef80();
  local_8._0_1_ = 2;
  FUN_00757800(uVar6);
  local_8._0_1_ = 0;
  if (7 < local_38) {
    FUN_0089120c(local_4c);
  }
  (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
  uVar6 = FUN_0040ef80();
  local_8._0_1_ = 3;
  FUN_00757800(uVar6);
  local_8._0_1_ = 0;
  if (7 < local_38) {
    FUN_0089120c(local_4c);
  }
  (**(code **)(**(int **)(param_1 + 0xfc) + 200))();
  uVar6 = FUN_0040ef80();
  local_8._0_1_ = 4;
  FUN_00757800(uVar6);
  local_8._0_1_ = 0;
  if (7 < local_38) {
    FUN_0089120c(local_4c);
  }
  (**(code **)(**(int **)(param_1 + 0x100) + 200))();
  uVar6 = FUN_00662870();
  local_8._0_1_ = 5;
  FUN_00757800(uVar6);
  local_8 = (uint)local_8._1_3_ << 8;
  if (7 < local_38) {
    FUN_0089120c(local_4c);
  }
  (**(code **)(**(int **)(param_1 + 0x104) + 200))();
  if (((*(char *)(*(int *)(param_1 + 0x108) + 0xa4) != '\0') &&
      (piVar3 = *(int **)(*(int *)(param_1 + 0x108) + 0x94), piVar3 != (int *)0x0)) &&
     (iVar7 = (**(code **)(*piVar3 + 4))(), iVar7 == 0xbf6b)) {
    FUN_0077b200();
  }
  (**(code **)(**(int **)(param_1 + 0x108) + 200))();
  if (7 < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

