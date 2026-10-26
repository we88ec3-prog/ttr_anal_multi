
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005e06b0(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0094362c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fab0d8 & 1) == 0) {
    DAT_00fab0d8 = DAT_00fab0d8 | 1;
    local_8 = 0;
    FUN_004dd4a0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    DAT_00fab0ec = 0;
    _DAT_00fab0f0 = 0;
    _DAT_00fab0f4 = 0;
    _atexit((_func_4879 *)&LAB_00bccdb0);
  }
  local_8 = 0xffffffff;
  local_18 = param_3;
  local_14 = param_4;
  FUN_004dd400(&DAT_00fab0dc,&param_4,&local_18);
  if (((param_4 != DAT_00fab0e0) && (*(int *)(param_4 + 0x18) != 0)) &&
     (*(int *)(*(int *)(param_4 + 0x18) + 0x24) != 0)) {
    ExceptionList = local_10;
    return 7;
  }
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 1;
    FUN_0051c120();
    _atexit((_func_4879 *)&LAB_00bccc90);
    local_8 = 0xffffffff;
  }
  param_4 = param_2;
  FUN_008438c0(&param_4);
  if ((local_14 == DAT_00f8d91c) || (param_4 = *(int *)(local_14 + 0x10), param_4 == 0)) {
    ExceptionList = local_10;
    return 2;
  }
  iVar3 = *(int *)(param_4 + 0x54);
  if (iVar3 == 0) {
    ExceptionList = local_10;
    return 1;
  }
  if ((*(uint *)(iVar3 + 4) != 0) && (*(uint *)(iVar3 + 4) != param_1)) {
    ExceptionList = local_10;
    return 4;
  }
  if ((((*(short *)(iVar3 + 0x94) != 0) || (*(short *)(iVar3 + 0x96) != 0)) ||
      (*(short *)(iVar3 + 0x90) != 0)) || (*(short *)(iVar3 + 0x92) != 0)) {
    iVar5 = FUN_0044fd50();
    if (*(int *)(iVar5 + 0x5ec0) == 0) {
      ExceptionList = local_10;
      return 8;
    }
    FUN_0044fd50();
    FUN_0048a740();
    FUN_006abb40();
    cVar4 = FUN_005e11d0();
    if (cVar4 == '\0') {
      ExceptionList = local_10;
      return 8;
    }
    FUN_0044fd50();
    FUN_0048a740();
    FUN_006abb80();
    cVar4 = FUN_005e11d0();
    if (cVar4 == '\0') {
      ExceptionList = local_10;
      return 8;
    }
  }
  if (*(int *)(param_4 + 0x68) != 0) {
    uVar2 = *(undefined2 *)(*(int *)(param_4 + 0x68) + 8);
    FUN_00404ba0();
    iVar5 = FUN_004d9c50(uVar2);
    if (iVar5 == 0) {
      ExceptionList = local_10;
      return 7;
    }
    if (*(int *)(iVar5 + 0xc) == 0) {
      ExceptionList = local_10;
      return 7;
    }
  }
  iVar5 = FUN_00404ba0();
  if (((9 < param_1) ||
      (iVar1 = param_1 * 0x210 + *(int *)(iVar5 + 0x6924),
      *(int *)(param_1 * 0x210 + 0x5c + *(int *)(iVar5 + 0x6924)) == 0)) ||
     ((iVar1 == 0 || (iVar5 = FUN_004d3f80(iVar1), iVar5 == 0)))) {
    ExceptionList = local_10;
    return 3;
  }
  if ((*(int *)(iVar3 + 0x78) != 0) && (*(int *)(iVar1 + 8) < *(int *)(iVar3 + 0x78))) {
    ExceptionList = local_10;
    return 6;
  }
  if ((*(int *)(iVar3 + 0x7c) != 0) && (*(int *)(iVar3 + 0x7c) < *(int *)(iVar1 + 8))) {
    ExceptionList = local_10;
    return 5;
  }
  ExceptionList = local_10;
  return 0;
}

