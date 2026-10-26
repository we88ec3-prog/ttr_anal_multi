
void FUN_0040eff0(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint in_stack_0000001c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00931f18;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(int *)(param_1 + 0xcc) != 0) {
    FUN_00757800(&param_2);
  }
  if (7 < in_stack_0000001c) {
    FUN_0089120c(param_2,uVar1);
  }
  ExceptionList = local_10;
  return;
}

