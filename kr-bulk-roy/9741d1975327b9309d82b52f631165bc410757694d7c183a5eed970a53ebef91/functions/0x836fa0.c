
void FUN_00836fa0(void)

{
  uint uVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090f658;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00832660(**(undefined4 **)(in_ECX + 8),*(undefined4 **)(in_ECX + 8));
  FUN_0089120c(*(undefined4 *)(in_ECX + 8),uVar1);
  ExceptionList = local_10;
  return;
}

