
void FUN_007d6510(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090c40b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar1 = FUN_00891268(0x14,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (iVar1 != 0) {
    FUN_007d5f00();
  }
  local_8 = 0xffffffff;
  uVar2 = FUN_0057ef20();
  FUN_0082f200(param_1 + 0x34,uVar2);
  ExceptionList = local_10;
  return;
}

