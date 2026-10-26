
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00587720(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009049eb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (DAT_00faae10 != (int *)0x0) {
    (**(code **)(*DAT_00faae10 + 0x10))(1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    DAT_00faae10 = (int *)0x0;
  }
  if (DAT_00faae08 != (int *)0x0) {
    (**(code **)(*DAT_00faae08 + 0x10))(1);
    DAT_00faae08 = (int *)0x0;
  }
  if (DAT_00faae04 != (int *)0x0) {
    (**(code **)(*DAT_00faae04 + 0x10))(1);
    DAT_00faae04 = (int *)0x0;
  }
  if (DAT_00faae00 != (int *)0x0) {
    (**(code **)(*DAT_00faae00 + 0x10))(1);
    DAT_00faae00 = (int *)0x0;
  }
  if (DAT_00faaddc != 0) {
    FUN_0089120c(DAT_00faaddc);
  }
  DAT_00faaddc = 0;
  _DAT_00faade0 = 0;
  _DAT_00faade4 = 0;
  ExceptionList = local_10;
  return;
}

