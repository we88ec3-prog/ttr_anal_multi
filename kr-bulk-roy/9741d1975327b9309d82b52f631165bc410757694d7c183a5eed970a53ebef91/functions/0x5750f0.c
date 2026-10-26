
void FUN_005750f0(undefined4 param_1)

{
  uint uVar1;
  undefined1 *unaff_ESI;
  uint in_stack_00000018;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  undefined4 in_stack_00000028;
  undefined4 in_stack_0000002c;
  undefined4 in_stack_00000030;
  undefined4 in_stack_00000034;
  undefined4 in_stack_00000038;
  undefined4 in_stack_0000003c;
  undefined4 in_stack_00000040;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00912ba8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *(undefined4 *)(unaff_ESI + 0x14) = 0xf;
  *unaff_ESI = 0;
  FUN_00403040(&param_1,0,0xffffffff);
  *(undefined4 *)(unaff_ESI + 0x1c) = in_stack_00000020;
  *(undefined4 *)(unaff_ESI + 0x20) = in_stack_00000024;
  *(undefined4 *)(unaff_ESI + 0x24) = in_stack_00000028;
  *(undefined4 *)(unaff_ESI + 0x28) = in_stack_0000002c;
  *(undefined4 *)(unaff_ESI + 0x3c) = in_stack_00000038;
  *(undefined4 *)(unaff_ESI + 0x34) = in_stack_00000030;
  *(undefined4 *)(unaff_ESI + 0x38) = in_stack_00000034;
  *(undefined4 *)(unaff_ESI + 0x40) = in_stack_0000003c;
  *(undefined4 *)(unaff_ESI + 0x44) = in_stack_00000040;
  if (0xf < in_stack_00000018) {
    FUN_0089120c(param_1,uVar1);
  }
  ExceptionList = local_10;
  return;
}

