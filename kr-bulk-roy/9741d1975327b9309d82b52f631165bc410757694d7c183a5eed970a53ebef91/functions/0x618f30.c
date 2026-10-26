
void FUN_00618f30(void)

{
  uint uVar1;
  int in_ECX;
  int local_34;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092ddd6;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fc0dc4 & 1) == 0) {
    DAT_00fc0dc4 = DAT_00fc0dc4 | 1;
    local_8 = 0;
    FUN_0052a3b0();
    _atexit(FUN_00bcd980);
  }
  local_8 = 0xffffffff;
  FUN_0052a340();
  if ((local_34 != DAT_00fc0dcc) && (local_34 != -0x10)) {
    FUN_004026e0(local_34 + 0x14,0,0xffffffff);
    FUN_0043b280(L"{0} Lv.{1}");
    local_8 = 1;
    FUN_00757800();
    local_8 = 0xffffffff;
    if (7 < local_1c) {
      FUN_0089120c();
    }
    (**(code **)(**(int **)(in_ECX + 0x24c) + 200))();
  }
  (**(code **)(**(int **)(in_ECX + 0x248) + 0x19c))();
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

