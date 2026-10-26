
undefined4 * FUN_0064fe30(undefined4 *param_1)

{
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009057f8;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = FoxUI::FXUIArchive::vftable;
  param_1[1] = *(undefined4 *)(unaff_EDI + 4);
  local_8 = 0;
  *param_1 = FoxUI::FXUIImageSetItem::vftable;
  param_1[2] = *(undefined4 *)(unaff_EDI + 8);
  param_1[7] = 0;
  param_1[8] = 7;
  *(undefined2 *)(param_1 + 3) = 0;
  FUN_004026e0(unaff_EDI + 0xc,0,0xffffffff);
  param_1[10] = *(undefined4 *)(unaff_EDI + 0x28);
  param_1[0xb] = *(undefined4 *)(unaff_EDI + 0x2c);
  param_1[0xc] = *(undefined4 *)(unaff_EDI + 0x30);
  param_1[0xd] = *(undefined4 *)(unaff_EDI + 0x34);
  ExceptionList = local_10;
  return param_1;
}

