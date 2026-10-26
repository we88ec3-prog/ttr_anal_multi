
undefined4 * FUN_0046f6b0(undefined4 *param_1)

{
  undefined4 *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091344b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = *unaff_EDI;
  param_1[6] = 0xf;
  param_1[5] = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  FUN_00403040(unaff_EDI + 1,0,0xffffffff);
  local_8 = 0;
  param_1[0xd] = 0xf;
  param_1[0xc] = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  FUN_00403040(unaff_EDI + 8,0,0xffffffff);
  param_1[0xf] = unaff_EDI[0xf];
  ExceptionList = local_10;
  return param_1;
}

