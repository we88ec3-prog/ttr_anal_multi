
uint FUN_00679ad0(undefined4 param_1,int param_2)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined4 uVar5;
  int local_20;
  int local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093ccea;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((in_ECX == 1) && (iVar4 = DAT_00f94300 + 0x16f8, iVar4 != 0)) {
    if (param_2 - 1U < 100) {
      iVar3 = param_2 * 0x20 + iVar4;
      if (((*(int *)(param_2 * 0x20 + 0xc + iVar4) != 0) && (*(int *)(iVar3 + 8) != 0)) &&
         (iVar3 != 0)) {
        if ((DAT_00f8d9a4 & 1) == 0) {
          DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
          local_c = 2;
          FUN_0051c120();
          _atexit((_func_4879 *)&LAB_00bccc90);
        }
        local_c = 0xffffffff;
        local_1c[0] = *(int *)(iVar3 + 0xc);
        FUN_008438c0(local_1c);
        if (local_20 == DAT_00f8d91c) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(local_20 + 0x10);
        }
        if (*(int *)(iVar4 + 0x3c) != 0) {
          ExceptionList = local_14;
          return CONCAT31((int3)((uint)iVar4 >> 8),1);
        }
        uVar5 = 0x322;
        FUN_00585620(0x322);
        FUN_00585330(uVar5);
        goto LAB_00679be0;
      }
    }
    else {
      FUN_006edb60(&DAT_00c0ddc0);
    }
    local_1c[0] = 0x321;
    iVar3 = FUN_00585620();
    FUN_005740f0(local_1c);
    iVar4 = local_20;
    if (local_20 == *(int *)(iVar3 + 4)) {
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
    iVar4 = local_1c[0];
    if (local_1c[0] == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
  }
  if (7 < *(uint *)(iVar4 + 0x24)) {
    uVar2 = FUN_00679d40();
    ExceptionList = local_14;
    return uVar2 & 0xffffff00;
  }
LAB_00679be0:
  uVar2 = FUN_00679d40();
  ExceptionList = local_14;
  return uVar2 & 0xffffff00;
}

