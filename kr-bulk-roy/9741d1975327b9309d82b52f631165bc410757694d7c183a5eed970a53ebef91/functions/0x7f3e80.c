
undefined4 FUN_007f3e80(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091c0db;
  local_10 = ExceptionList;
  if (*(int *)(unaff_ESI + 0x10) != 0) {
    return 0;
  }
  ExceptionList = &local_10;
  iVar1 = FUN_00891268(0x34,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_007f3ca0(iVar1,unaff_ESI);
  }
  local_8 = 0xffffffff;
  FUN_007bb350();
  ExceptionList = local_10;
  return uVar2;
}

