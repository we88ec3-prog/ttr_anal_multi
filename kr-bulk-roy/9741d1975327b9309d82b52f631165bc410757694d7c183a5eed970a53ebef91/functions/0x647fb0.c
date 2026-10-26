
void FUN_00647fb0(void)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00920dbe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8 = 0;
    FUN_0058d410(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccdc0);
  }
  local_8 = 0xffffffff;
  FUN_0058eb30(L"Folder",in_ECX + 0xb0);
  FUN_00648100();
  ExceptionList = local_10;
  return;
}

