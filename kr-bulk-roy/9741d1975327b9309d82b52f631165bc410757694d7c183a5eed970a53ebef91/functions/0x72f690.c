
int FUN_0072f690(void)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092038b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_00891268(0x78,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0072ed80(iVar1);
  }
  local_8 = 0xffffffff;
  if (iVar1 == 0) {
    ExceptionList = local_10;
    return 0;
  }
  FUN_0072f600();
  ExceptionList = local_10;
  return iVar1;
}

