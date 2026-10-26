
void FUN_006669b0(int param_1)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093276e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(iVar1 + 0xdc);
  }
  if (iVar1 != 0) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    FUN_0058aee0(0xf43df,*(undefined4 *)(iVar1 + 0x260),*(undefined4 *)(iVar1 + 0x264));
  }
  ExceptionList = local_10;
  return;
}

