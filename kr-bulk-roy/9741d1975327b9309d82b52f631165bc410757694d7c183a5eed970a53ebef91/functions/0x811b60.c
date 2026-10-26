
undefined1 * FUN_00811b60(undefined1 *param_1)

{
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091ead8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  FUN_00403040(unaff_EDI,0,0xffffffff);
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(unaff_EDI + 0x1c);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(unaff_EDI + 0x20);
  *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(unaff_EDI + 0x24);
  FUN_00555af0(param_1 + 0x28,unaff_EDI + 0x28);
  param_1[0x38] = *(undefined1 *)(unaff_EDI + 0x38);
  ExceptionList = local_10;
  return param_1;
}

