
void FUN_00571460(undefined4 param_1)

{
  uint uVar1;
  int unaff_ESI;
  uint in_stack_00000018;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090cc58;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_004026e0(&param_1,0,0xffffffff);
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  if (7 < in_stack_00000018) {
    FUN_0089120c(param_1,uVar1);
  }
  ExceptionList = local_10;
  return;
}

