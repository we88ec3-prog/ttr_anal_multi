
undefined4 FUN_0057e490(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint in_stack_00000014;
  uint in_stack_00000018;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 uStack_8;
  
  uStack_8 = 0xffffffff;
  puStack_c = &LAB_0090ac28;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar2 = in_stack_00000014;
  if (7 < in_stack_00000014) {
    uVar2 = 8;
  }
  iVar3 = FUN_00407e70(uVar2,uVar1);
  if (((iVar3 == 0) && (7 < in_stack_00000014)) && (in_stack_00000014 == 8)) {
    if (0xf < in_stack_00000018) {
      FUN_0089120c(param_1);
    }
    ExceptionList = local_10;
    return 0;
  }
  uVar2 = in_stack_00000014;
  if (9 < in_stack_00000014) {
    uVar2 = 10;
  }
  iVar3 = FUN_00407e70(uVar2,uVar1);
  if (((iVar3 == 0) && (9 < in_stack_00000014)) && (in_stack_00000014 == 10)) {
    if (0xf < in_stack_00000018) {
      FUN_0089120c(param_1);
    }
    ExceptionList = local_10;
    return 1;
  }
  if (0xf < in_stack_00000018) {
    FUN_0089120c(param_1);
  }
  ExceptionList = local_10;
  return 2;
}

