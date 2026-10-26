
undefined4 FUN_0067e570(undefined4 param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  int in_EDX;
  int local_20;
  int local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093cc4c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((in_EDX != 1) || (iVar4 = DAT_00f94300 + 0x16f8, iVar4 == 0)) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c = 1;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c = 0xffffffff;
    local_20 = 0x321;
    FUN_005740f0(&local_20);
    if (local_1c[0] != DAT_00fe5ac8) {
      if (7 < *(uint *)(local_1c[0] + 0x24)) {
        FUN_006803d0(param_1);
        ExceptionList = local_14;
        return 0;
      }
      FUN_006803d0(param_1);
      ExceptionList = local_14;
      return 0;
    }
    pcVar2 = (code *)swi(3);
    uVar3 = (*pcVar2)();
    return uVar3;
  }
  if (in_ECX - 1U < 100) {
    iVar1 = in_ECX * 0x20 + iVar4;
    if (((*(int *)(in_ECX * 0x20 + 0xc + iVar4) != 0) && (*(int *)(iVar1 + 8) != 0)) && (iVar1 != 0)
       ) {
      local_1c[0] = *(int *)(iVar1 + 4);
      iVar4 = FUN_004034e0();
      FUN_008438c0(local_1c);
      if ((local_20 != *(int *)(iVar4 + 4)) && (iVar4 = *(int *)(local_20 + 0x10), iVar4 != 0)) {
        iVar1 = *(int *)(iVar1 + 0xc);
        iVar5 = FUN_00404c10();
        local_1c[0] = iVar1;
        FUN_008438c0(local_1c);
        if ((local_20 != *(int *)(iVar5 + 4)) && (*(int *)(local_20 + 0x10) != 0)) {
          iVar4 = *(int *)(iVar4 + 8);
          if (((iVar4 != 0xb) && (iVar4 != 9)) && (iVar4 != 10)) {
            iVar4 = FUN_00520e70();
            if (iVar4 != 0) {
              ExceptionList = local_14;
              return 1;
            }
            uVar3 = 0x311;
            FUN_00585620(0x311);
            FUN_00585330(uVar3);
            FUN_006803d0(param_1);
            ExceptionList = local_14;
            return 0;
          }
          ExceptionList = local_14;
          return 2;
        }
      }
      uVar3 = 0x322;
      FUN_00585620(0x322);
      FUN_00585330(uVar3);
      FUN_006803d0(param_1);
      ExceptionList = local_14;
      return 0;
    }
  }
  else {
    FUN_006edb60(&DAT_00c0ddc0);
  }
  local_1c[0] = 0x321;
  iVar4 = FUN_00585620();
  FUN_005740f0(local_1c);
  if (local_20 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    uVar3 = (*pcVar2)();
    return uVar3;
  }
  if (7 < *(uint *)(local_20 + 0x24)) {
    FUN_006803d0(param_1);
    ExceptionList = local_14;
    return 0;
  }
  FUN_006803d0(param_1);
  ExceptionList = local_14;
  return 0;
}

