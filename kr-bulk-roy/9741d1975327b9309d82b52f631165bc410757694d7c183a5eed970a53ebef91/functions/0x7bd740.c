
undefined4 * FUN_007bd740(undefined4 *param_1)

{
  undefined4 *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091194b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *unaff_EDI;
  param_1[1] = unaff_EDI[1];
  param_1[2] = unaff_EDI[2];
  param_1[8] = 0xf;
  param_1[7] = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  FUN_00403040(unaff_EDI + 3,0,0xffffffff);
  local_8 = 0;
  param_1[0xf] = 0xf;
  param_1[0xe] = 0;
  *(undefined1 *)(param_1 + 10) = 0;
  FUN_00403040(unaff_EDI + 10,0,0xffffffff);
  param_1[0x11] = unaff_EDI[0x11];
  ExceptionList = local_10;
  return param_1;
}

