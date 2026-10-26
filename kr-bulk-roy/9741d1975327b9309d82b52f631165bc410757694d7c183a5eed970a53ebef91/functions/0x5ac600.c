
void FUN_005ac600(int param_1)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093c77e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0059b9e0(param_1);
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0xf4262) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480(uVar2);
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_0058b350(0xf4321);
  }
  else {
    if (iVar1 == 0xf426f) {
      (**(code **)(**(int **)(in_ECX + 0x220) + 0xd4))();
      ExceptionList = local_10;
      return;
    }
    if (iVar1 == 0xf42ca) {
      FUN_005ac8c0(in_ECX);
      ExceptionList = local_10;
      return;
    }
  }
  ExceptionList = local_10;
  return;
}

