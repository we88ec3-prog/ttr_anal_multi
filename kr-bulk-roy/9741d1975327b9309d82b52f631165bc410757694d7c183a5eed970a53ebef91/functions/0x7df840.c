
void FUN_007df840(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00934cdb;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_00891268(0x3c,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (iVar1 != 0) {
    uVar2 = FUN_007f3080(*(int *)(unaff_EDI + 0x30) * 6);
    *(undefined4 *)(unaff_EDI + 4) = uVar2;
    ExceptionList = local_10;
    return;
  }
  *(undefined4 *)(unaff_EDI + 4) = 0;
  ExceptionList = local_10;
  return;
}

