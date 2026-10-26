
void FUN_007ef5d0(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009377fe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x38) != 0) {
    if ((DAT_00fe1ac0 & 1) == 0) {
      DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
      local_8 = 0;
      FUN_007bb970(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bceac0);
    }
    local_8 = 0xffffffff;
    FUN_007bcf60();
  }
  FUN_007f0500();
  ExceptionList = local_10;
  return;
}

