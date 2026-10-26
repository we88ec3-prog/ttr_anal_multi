
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006a4820(void)

{
  undefined1 local_12 [2];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093b55e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_8 = 0;
    FUN_004e8010(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd6b0);
  }
  local_8 = 0xffffffff;
  if (DAT_00fc0bd8 != 0) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(2,local_12,2);
    }
  }
  ExceptionList = local_10;
  return;
}

