
int FUN_005c3d40(undefined4 param_1)

{
  uint uVar1;
  int unaff_EDI;
  uint in_stack_00000018;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090ab98;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_005c7360(&local_14);
  if (local_14 != *(int *)(unaff_EDI + 0x20)) {
    if (7 < in_stack_00000018) {
      FUN_0089120c(param_1,uVar1);
    }
    ExceptionList = local_10;
    return local_14 + 0x28;
  }
  if (7 < in_stack_00000018) {
    FUN_0089120c(param_1,uVar1);
  }
  ExceptionList = local_10;
  return 0;
}

