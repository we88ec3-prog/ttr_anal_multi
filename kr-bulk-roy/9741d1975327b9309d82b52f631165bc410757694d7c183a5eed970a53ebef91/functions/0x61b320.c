
void FUN_0061b320(void)

{
  undefined4 uVar1;
  int unaff_EDI;
  undefined1 auStack_3c [4];
  uint local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093deb6;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_3c;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffc0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  uVar1 = FUN_00412df0();
  local_c = 1;
  FUN_00757800(uVar1);
  local_c = 0xffffffff;
  if (7 < local_24) {
    FUN_0089120c(local_38);
  }
  local_38 = local_38 & 0xffff0000;
  local_24 = 7;
  local_28 = 0;
  (**(code **)(**(int **)(unaff_EDI + 0xf0) + 200))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_3c);
  return;
}

