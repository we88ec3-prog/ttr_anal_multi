
undefined4 * FUN_0086d480(undefined4 *param_1)

{
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091e756;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = gbDxEffectScriptCommands::vftable;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[0xc] = 0xf;
  param_1[0xb] = 0;
  *(undefined1 *)(param_1 + 7) = 0;
  local_8 = 1;
  param_1[1] = *(undefined4 *)(unaff_EDI + 4);
  param_1[2] = *(undefined4 *)(unaff_EDI + 8);
  FUN_00573d30(unaff_EDI + 0xc);
  FUN_00403040(unaff_EDI + 0x1c,0,0xffffffff);
  param_1[0xe] = *(undefined4 *)(unaff_EDI + 0x38);
  param_1[0xf] = *(undefined4 *)(unaff_EDI + 0x3c);
  ExceptionList = local_10;
  return param_1;
}

