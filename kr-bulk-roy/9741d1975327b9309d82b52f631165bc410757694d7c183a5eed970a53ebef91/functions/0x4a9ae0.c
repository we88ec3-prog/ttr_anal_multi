
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004a9ae0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00924d9e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  if (DAT_00faadec != 0xf) {
    _DAT_00faadf0 = 0xf;
    ExceptionList = local_10;
    return;
  }
  FUN_0058a9a0();
  ExceptionList = local_10;
  return;
}

