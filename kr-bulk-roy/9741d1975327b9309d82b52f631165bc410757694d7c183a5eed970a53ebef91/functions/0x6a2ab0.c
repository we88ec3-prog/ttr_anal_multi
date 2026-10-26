
void FUN_006a2ab0(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093276e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((*(uint *)(in_ECX + 0x28) & 0x100) != 0) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    FUN_0058aad0(0xf434d);
    FUN_004067f0();
  }
  ExceptionList = local_10;
  return;
}

