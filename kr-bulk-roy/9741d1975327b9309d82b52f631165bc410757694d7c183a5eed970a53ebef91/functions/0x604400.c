
void FUN_00604400(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094799e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((*(uint *)(in_ECX + 0x28) >> 8 & 1) != 0) {
    FUN_006049b0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_0058aad0(0xf4354);
    FUN_004067f0();
  }
  ExceptionList = local_10;
  return;
}

