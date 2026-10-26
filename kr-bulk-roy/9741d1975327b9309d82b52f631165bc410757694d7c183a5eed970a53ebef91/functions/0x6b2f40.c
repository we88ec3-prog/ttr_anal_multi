
void FUN_006b2f40(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int local_20;
  int local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00942648;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  if ((DAT_00fab228 == 0) || (*(char *)(DAT_00fab228 + 0x28) == '\0')) {
    if ((DAT_00fb1378 & 1) == 0) {
      DAT_00fb1378 = DAT_00fb1378 | 1;
      local_c = 1;
      FUN_00539c20();
      _atexit((_func_4879 *)&LAB_00bccfb0);
    }
    if (DAT_00fb7258 == 0) {
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_c = 3;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
      }
      local_c = 0xffffffff;
      local_1c[0] = 0x15c;
      FUN_005740f0(local_1c);
      if (local_20 == DAT_00fe5ac8) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
    }
    else {
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 2;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
      }
      local_c = 0xffffffff;
      iVar2 = FUN_00539aa0(DAT_00f93930);
      if ((iVar2 == 0) || (*(char *)(iVar2 + 8) == '\0')) {
        local_1c[0] = 0x15c;
        iVar2 = FUN_00585620();
        FUN_005740f0(local_1c);
        if (local_20 == *(int *)(iVar2 + 4)) {
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
      }
      else {
        uVar3 = 0x2e9;
        FUN_00585620(0x2e9);
        FUN_00585330(uVar3);
      }
    }
  }
  else {
    local_20 = 0x15b;
    iVar2 = FUN_00585620();
    FUN_005740f0(&local_20);
    if (local_1c[0] == *(int *)(iVar2 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
  }
  FUN_00757710();
  (**(code **)(**(int **)(param_1 + 0x98) + 200))();
  ExceptionList = local_14;
  return;
}

