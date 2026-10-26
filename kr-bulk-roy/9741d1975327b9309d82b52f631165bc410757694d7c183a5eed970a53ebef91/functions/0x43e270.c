
void FUN_0043e270(undefined4 param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 uVar2;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092e1de;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_8 = 0;
    FUN_0051c120(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_8 = 0xffffffff;
  FUN_008438c0(&param_1);
  if (local_14 == DAT_00f8d91c) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(local_14 + 0x10);
  }
  FUN_00757710();
  (**(code **)(**(int **)(in_ECX + 0x2a4) + 0x94))(0);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x54) != 0)) {
    iVar1 = *(int *)(*(int *)(iVar1 + 0x54) + 8);
    if (iVar1 == 0xb) {
      FUN_0043e380();
      uVar2 = 0;
    }
    else {
      if (iVar1 != 0x10) {
        if (iVar1 != 0x19) {
          ExceptionList = local_10;
          return;
        }
        FUN_0043e380();
      }
      uVar2 = 1;
    }
    (**(code **)(**(int **)(in_ECX + 0x2a4) + 0x94))(uVar2);
  }
  ExceptionList = local_10;
  return;
}

