
void FUN_0060dac0(void)

{
  uint uVar1;
  undefined4 uVar2;
  int unaff_EDI;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092dec6;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(unaff_EDI + 0x15c) != -1) {
    if ((DAT_00fc1094 & 1) == 0) {
      DAT_00fc1094 = DAT_00fc1094 | 1;
      local_8 = 0;
      FUN_0052f7e0(uVar1);
      _atexit((_func_4879 *)&LAB_00bcdc80);
    }
    local_8 = 0xffffffff;
    uVar2 = FUN_005300f0();
    uVar2 = FUN_00498f10(uVar2);
    local_8 = 1;
    FUN_00757800(uVar2);
    if (7 < local_1c) {
      FUN_0089120c(local_30);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc);
  return;
}

