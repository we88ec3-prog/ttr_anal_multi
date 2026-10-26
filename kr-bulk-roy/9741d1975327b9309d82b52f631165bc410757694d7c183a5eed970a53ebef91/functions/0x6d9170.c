
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d9170(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090a8d6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 4;
  if (DAT_00fc1074 != (undefined4 *)0x0) {
    (**(code **)*DAT_00fc1074)(1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    DAT_00fc1074 = (undefined4 *)0x0;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00fc107c);
  if (0xf < DAT_00fc104c) {
    FUN_0089120c(DAT_00fc1038);
  }
  DAT_00fc104c = 0xf;
  _DAT_00fc1048 = 0;
  DAT_00fc1038 = DAT_00fc1038 & 0xffffff00;
  if (0xf < DAT_00fc1014) {
    FUN_0089120c(DAT_00fc1000);
  }
  DAT_00fc1014 = 0xf;
  _DAT_00fc1010 = 0;
  DAT_00fc1000 = DAT_00fc1000 & 0xffffff00;
  FUN_006dab40(&DAT_00fc0ff0);
  FUN_0089120c(DAT_00fc0ff0);
  if (0xf < DAT_00fc0fdc) {
    FUN_0089120c(_DAT_00fc0fc8);
  }
  DAT_00fc0fdc = 0xf;
  _DAT_00fc0fd8 = 0;
  _DAT_00fc0fc8 = _DAT_00fc0fc8 & 0xffffff00;
  ExceptionList = local_10;
  return;
}

