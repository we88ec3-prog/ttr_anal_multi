
void FUN_00595e30(void)

{
  undefined4 in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092188e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 0;
    FUN_0058d410(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccdc0);
  }
  local_8 = 0xffffffff;
  FUN_0058e790(&DAT_00faaf80);
  FUN_00851420();
  FUN_00596c90(in_ECX);
  ExceptionList = local_10;
  return;
}

