
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0081e6d0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091eaa9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 3;
  if (DAT_00fb7608 != (undefined4 *)0x0) {
    (**(code **)*DAT_00fb7608)(1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    DAT_00fb7608 = (undefined4 *)0x0;
  }
  if (DAT_00fb75f8 != 0) {
    FUN_0049bf30();
    FUN_0089120c(DAT_00fb75f8);
  }
  DAT_00fb75f8 = 0;
  DAT_00fb75fc = 0;
  _DAT_00fb7600 = 0;
  if (DAT_00fb75e8 != 0) {
    FUN_0049bf30();
    FUN_0089120c(DAT_00fb75e8);
  }
  DAT_00fb75e8 = 0;
  DAT_00fb75ec = 0;
  _DAT_00fb75f0 = 0;
  if (DAT_00fb75d8 != 0) {
    FUN_0049bf30();
    FUN_0089120c(DAT_00fb75d8);
  }
  DAT_00fb75d8 = 0;
  DAT_00fb75dc = 0;
  _DAT_00fb75e0 = 0;
  if (DAT_00fb75c8 != 0) {
    FUN_0049bf30();
    FUN_0089120c(DAT_00fb75c8);
  }
  DAT_00fb75c8 = 0;
  DAT_00fb75cc = 0;
  _DAT_00fb75d0 = 0;
  ExceptionList = local_10;
  return;
}

