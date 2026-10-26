
void FUN_00839220(void)

{
  int iVar1;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091c0db;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_00891268(0x30,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (iVar1 != 0) {
    FUN_00838980(iVar1,*(undefined4 *)(unaff_ESI + 0x58));
  }
  local_8 = 0xffffffff;
  FUN_007bb350();
  *(int *)(unaff_ESI + 0x14) = (*(int *)(unaff_ESI + 8) - *(int *)(unaff_ESI + 4) >> 2) + -1;
  ExceptionList = local_10;
  return;
}

