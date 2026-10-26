
void FUN_00bceb90(void)

{
  uint uVar1;
  undefined1 local_18 [4];
  undefined *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00a080c8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = &DAT_00fbaae4;
  local_8 = 0;
  FUN_004cca50(local_18,*DAT_00fbaae8,DAT_00fbaae8);
  FUN_0089120c(DAT_00fbaae8,uVar1);
  ExceptionList = local_10;
  return;
}

