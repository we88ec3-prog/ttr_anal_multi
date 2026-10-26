
undefined2 * FUN_0082c460(undefined2 *param_1)

{
  undefined2 *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009115a1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *unaff_EDI;
  *(undefined4 *)(param_1 + 0xc) = 0xf;
  *(undefined4 *)(param_1 + 10) = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  FUN_00403040(unaff_EDI + 2,0,0xffffffff);
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x1a) = 0xf;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined1 *)(param_1 + 0x10) = 0;
  FUN_00403040(unaff_EDI + 0x10,0,0xffffffff);
  local_8._0_1_ = 1;
  *(undefined4 *)(param_1 + 0x28) = 0xf;
  *(undefined4 *)(param_1 + 0x26) = 0;
  *(undefined1 *)(param_1 + 0x1e) = 0;
  FUN_00403040(unaff_EDI + 0x1e,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,2);
  *(undefined4 *)(param_1 + 0x36) = 0xf;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined1 *)(param_1 + 0x2c) = 0;
  FUN_00403040(unaff_EDI + 0x2c,0,0xffffffff);
  *(undefined4 *)(param_1 + 0x3a) = *(undefined4 *)(unaff_EDI + 0x3a);
  *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(unaff_EDI + 0x3c);
  *(undefined4 *)(param_1 + 0x3e) = *(undefined4 *)(unaff_EDI + 0x3e);
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(unaff_EDI + 0x40);
  *(undefined4 *)(param_1 + 0x42) = *(undefined4 *)(unaff_EDI + 0x42);
  *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(unaff_EDI + 0x44);
  *(undefined4 *)(param_1 + 0x46) = *(undefined4 *)(unaff_EDI + 0x46);
  ExceptionList = local_10;
  return param_1;
}

