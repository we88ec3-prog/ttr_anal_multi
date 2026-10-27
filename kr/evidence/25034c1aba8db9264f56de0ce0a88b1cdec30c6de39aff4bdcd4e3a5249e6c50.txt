
void FUN_006ba2c0(int param_1)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar1 = DAT_00fe18f8;
  puStack_c = &LAB_0093276e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((*(int *)(param_1 + 0x10) == 0x578) &&
     (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x10c) + 0x20))) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    FUN_0058ab80(0xf431f,*(undefined1 *)(iVar1 + 0x29));
  }
  ExceptionList = local_10;
  return;
}

