
undefined4 FUN_0080e660(void)

{
  int iVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091c0db;
  local_10 = ExceptionList;
  if (DAT_00fba868 != 0) {
    return 0;
  }
  ExceptionList = &local_10;
  iVar1 = FUN_00891268(0x40,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0080f8a0();
  }
  DAT_00fba868 = 1;
  ExceptionList = local_10;
  return uVar2;
}

