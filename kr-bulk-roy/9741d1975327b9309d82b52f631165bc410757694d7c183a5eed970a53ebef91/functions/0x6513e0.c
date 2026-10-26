
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006513e0(void)

{
  undefined4 in_ECX;
  undefined3 local_14;
  undefined1 uStack_11;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  uStack_11 = (undefined1)((uint)in_ECX >> 0x18);
  puStack_c = &LAB_009472de;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_8 = 0;
    FUN_00539c20(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  local_8 = 0xffffffff;
  if (DAT_00fb7258 != 0) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    _local_14 = CONCAT13(uStack_11,0x5d);
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_14,3);
    }
  }
  ExceptionList = local_10;
  return;
}

