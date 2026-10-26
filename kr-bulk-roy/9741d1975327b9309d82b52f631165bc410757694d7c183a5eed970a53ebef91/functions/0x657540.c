
void FUN_00657540(undefined4 param_1)

{
  uint uVar1;
  undefined2 *unaff_ESI;
  uint in_stack_00000018;
  undefined1 in_stack_00000020;
  undefined1 in_stack_00000024;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090cc58;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  FUN_004026e0(&param_1,0,0xffffffff);
  *(undefined1 *)(unaff_ESI + 0xe) = in_stack_00000020;
  *(undefined1 *)((int)unaff_ESI + 0x1d) = in_stack_00000024;
  if (7 < in_stack_00000018) {
    FUN_0089120c(param_1,uVar1);
  }
  ExceptionList = local_10;
  return;
}

