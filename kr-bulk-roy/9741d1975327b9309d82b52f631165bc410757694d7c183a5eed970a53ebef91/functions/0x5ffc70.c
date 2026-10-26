
undefined4 FUN_005ffc70(uint param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  int in_EDX;
  undefined4 local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093c65c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((in_EDX != 1) || (iVar5 = DAT_00f94300 + 0x16f8, iVar5 == 0)) {
    ExceptionList = local_14;
    return 1;
  }
  if (99 < in_ECX - 1U) {
    FUN_006edb60(&DAT_00c0ddc0);
    ExceptionList = local_14;
    return 2;
  }
  iVar3 = in_ECX * 0x20 + iVar5;
  if (*(int *)(in_ECX * 0x20 + 0xc + iVar5) == 0) {
    ExceptionList = local_14;
    return 2;
  }
  if (*(int *)(iVar3 + 8) == 0) {
    ExceptionList = local_14;
    return 2;
  }
  if (iVar3 == 0) {
    ExceptionList = local_14;
    return 2;
  }
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 1;
    FUN_0051c120();
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_c = 0xffffffff;
  local_20 = *(undefined4 *)(iVar3 + 0xc);
  FUN_008438c0(&local_20);
  if ((local_1c == DAT_00f8d91c) || (*(int *)(local_1c + 0x10) == 0)) {
    ExceptionList = local_14;
    return 3;
  }
  iVar5 = *(int *)(*(int *)(local_1c + 0x10) + 0x54);
  if (iVar5 == 0) {
    ExceptionList = local_14;
    return 4;
  }
  FUN_00423240();
  iVar3 = FUN_004eeb00();
  if (iVar3 == 0) {
    iVar3 = FUN_0051c080();
    if (iVar3 == 0) {
      ExceptionList = local_14;
      return 6;
    }
    iVar3 = *(int *)(iVar5 + 0x78);
    iVar1 = *(int *)(iVar5 + 0x7c);
    iVar4 = FUN_00404ba0();
    if (((param_1 < 10) &&
        (iVar4 = *(int *)(iVar4 + 0x6924) + param_1 * 0x210, *(int *)(iVar4 + 0x5c) != 0)) &&
       (iVar4 != 0)) {
      if (((*(uint *)(iVar5 + 4) != param_1) && (*(uint *)(iVar5 + 4) != 0)) &&
         ((*(int *)(iVar5 + 8) != 0x1f && (*(int *)(iVar5 + 8) != 0x1d)))) {
        ExceptionList = local_14;
        return 9;
      }
      if (((iVar3 != 0) && (*(int *)(iVar4 + 8) < iVar3)) ||
         ((iVar1 != 0 && (iVar1 < *(int *)(iVar4 + 8))))) {
        ExceptionList = local_14;
        return 7;
      }
    }
    cVar2 = FUN_005e1210();
    if ((cVar2 == '\0') && (cVar2 = FUN_005e1210(), cVar2 == '\0')) {
      ExceptionList = local_14;
      return 0;
    }
    iVar5 = FUN_0044fd50();
    if (*(int *)(iVar5 + 0x5ec0) != 0) {
      FUN_0044fd50();
      FUN_0048a740();
      FUN_006abb40();
      cVar2 = FUN_005e11d0();
      if (cVar2 != '\0') {
        FUN_0044fd50();
        FUN_0048a740();
        FUN_006abb80();
        cVar2 = FUN_005e11d0();
        if (cVar2 != '\0') {
          ExceptionList = local_14;
          return 0;
        }
      }
    }
    ExceptionList = local_14;
    return 8;
  }
  ExceptionList = local_14;
  return 5;
}

