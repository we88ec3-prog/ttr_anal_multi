
undefined4 FUN_0045c050(undefined4 param_1,int param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
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
  if ((in_ECX == 1) && (DAT_00f94300 + 0x16f8 != 0)) {
    if (param_2 - 1U < 100) {
      iVar3 = DAT_00f94300 + 0x16f8 + param_2 * 0x20;
      if (((*(int *)(iVar3 + 0xc) != 0) && (*(int *)(iVar3 + 8) != 0)) && (iVar3 != 0)) {
        local_1c[0] = *(int *)(iVar3 + 0xc);
        iVar3 = FUN_00459c20();
        FUN_008438c0(local_1c);
        if ((local_20 == *(int *)(iVar3 + 0x18)) || (uVar2 = 2, *(int *)(local_20 + 0x10) < 1)) {
          uVar2 = 1;
        }
        ExceptionList = local_14;
        return uVar2;
      }
    }
    else {
      FUN_006edb60(&DAT_00c0ddc0);
    }
    local_1c[0] = 0x321;
    iVar4 = FUN_00585620();
    FUN_005740f0(local_1c);
    iVar3 = local_20;
    if (local_20 == *(int *)(iVar4 + 4)) {
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c = 1;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c = 0xffffffff;
    local_20 = 0x321;
    FUN_005740f0(&local_20);
    iVar3 = local_1c[0];
    if (local_1c[0] == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
  }
  if (7 < *(uint *)(iVar3 + 0x24)) {
    FUN_0045b330();
    ExceptionList = local_14;
    return 0;
  }
  FUN_0045b330();
  ExceptionList = local_14;
  return 0;
}

