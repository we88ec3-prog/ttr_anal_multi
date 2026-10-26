
void FUN_00594d40(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *local_2c;
  undefined4 *local_28;
  undefined4 local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009291e6;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_2c;
  ExceptionList = &local_14;
  if ((DAT_00fdfb10 & 1) == 0) {
    DAT_00fdfb10 = DAT_00fdfb10 | 1;
    local_c = 0;
    FUN_00590760(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    _atexit((_func_4879 *)&LAB_00bce760);
  }
  local_2c = (undefined4 *)0x0;
  local_28 = (undefined4 *)0x0;
  local_24 = 0;
  local_c = 1;
  FUN_006d4dc0(0x2910,2);
  FUN_00402160(&DAT_00bed1fc,0);
  puVar1 = local_2c;
  if (local_2c == local_28) {
    FUN_0041f490(param_1);
  }
  else {
    FUN_00594570(*local_2c);
  }
  if (puVar1 != (undefined4 *)0x0) {
    FUN_0089120c(puVar1);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_2c);
  return;
}

