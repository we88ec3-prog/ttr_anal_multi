
void FUN_00595c10(void)

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
  FUN_006d7120(**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  FUN_0089120c(*(undefined4 *)(in_ECX + 4),uVar1);
  ExceptionList = local_10;
  return;
}

