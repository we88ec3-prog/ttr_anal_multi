
void FUN_004a1440(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092780e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_8 = 0;
    FUN_006d0750(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd530);
  }
  local_8 = 0xffffffff;
  if ((param_1 == 0) || (param_1 == 1)) {
    FUN_006d1be0(&DAT_00fb8d34,&DAT_00fb8834 + param_1 * 0x280);
  }
  ExceptionList = local_10;
  return;
}

