
void FUN_0077dc10(int param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090a4c7;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_0077dc90(param_1);
  local_8 = 1;
  FUN_0057ffd0(**(undefined4 **)(param_1 + 0x210),*(undefined4 **)(param_1 + 0x210));
  FUN_0089120c(*(undefined4 *)(param_1 + 0x210),uVar1);
  ExceptionList = local_10;
  return;
}

