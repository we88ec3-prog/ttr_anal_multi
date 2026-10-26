
undefined1 * FUN_004f81f0(undefined1 *param_1)

{
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00913133;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  FUN_00403040(unaff_EDI,0,0xffffffff);
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x30) = 7;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined2 *)(param_1 + 0x1c) = 0;
  FUN_004026e0(unaff_EDI + 0x1c,0,0xffffffff);
  local_8 = CONCAT31(local_8._1_3_,1);
  *(undefined4 *)(param_1 + 0x4c) = 0xf;
  *(undefined4 *)(param_1 + 0x48) = 0;
  param_1[0x38] = 0;
  FUN_00403040(unaff_EDI + 0x38,0,0xffffffff);
  *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(unaff_EDI + 0x54);
  *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(unaff_EDI + 0x58);
  *(undefined4 *)(param_1 + 0x5c) = *(undefined4 *)(unaff_EDI + 0x5c);
  param_1[0x60] = *(undefined1 *)(unaff_EDI + 0x60);
  param_1[0x61] = *(undefined1 *)(unaff_EDI + 0x61);
  ExceptionList = local_10;
  return param_1;
}

