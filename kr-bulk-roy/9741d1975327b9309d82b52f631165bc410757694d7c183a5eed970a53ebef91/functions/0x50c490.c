
void FUN_0050c490(int param_1)

{
  int iVar1;
  int in_ECX;
  int in_EDX;
  undefined *puVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093edde;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((in_EDX == 1) && (DAT_00f94300 + 0x16f8 != 0)) {
    if (in_ECX - 1U < 100) {
      iVar1 = DAT_00f94300 + 0x16f8 + in_ECX * 0x20;
      if (*(int *)(iVar1 + 0xc) == 0) {
        ExceptionList = local_14;
        return;
      }
      if (*(int *)(iVar1 + 8) == 0) {
        ExceptionList = local_14;
        return;
      }
      if (iVar1 == 0) {
        ExceptionList = local_14;
        return;
      }
      if (param_1 - 1U < 5) {
        FUN_004054c0();
        FUN_0058aad0(0xf4277);
        FUN_0050ca90();
        ExceptionList = local_14;
        return;
      }
      puVar2 = &DAT_00c0de90;
    }
    else {
      puVar2 = &DAT_00c0ddc0;
    }
    FUN_006edb60(puVar2);
  }
  ExceptionList = local_14;
  return;
}

