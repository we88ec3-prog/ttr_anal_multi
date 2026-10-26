
void FUN_0086c350(undefined4 param_1)

{
  uint uVar1;
  undefined4 in_EDX;
  undefined4 *unaff_ESI;
  uint in_stack_00000018;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009110e3;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  unaff_ESI[6] = 0xf;
  unaff_ESI[5] = 0;
  *(undefined1 *)(unaff_ESI + 1) = 0;
  local_8 = 1;
  *unaff_ESI = in_EDX;
  FUN_00403040(&param_1,0,0xffffffff);
  if (0xf < in_stack_00000018) {
    FUN_0089120c(param_1,uVar1);
  }
  ExceptionList = local_10;
  return;
}

