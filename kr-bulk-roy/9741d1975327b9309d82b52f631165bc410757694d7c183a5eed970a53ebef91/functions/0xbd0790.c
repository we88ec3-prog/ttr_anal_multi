
void FUN_00bd0790(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a08053;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (DAT_00fe4b00 != (undefined4 *)0x0) {
    (**(code **)*DAT_00fe4b00)(1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    DAT_00fe4b00 = (undefined4 *)0x0;
  }
  local_8 = 1;
  FUN_00714eb0();
  FUN_0089120c(DAT_00fe4b04);
  ExceptionList = local_10;
  return;
}

