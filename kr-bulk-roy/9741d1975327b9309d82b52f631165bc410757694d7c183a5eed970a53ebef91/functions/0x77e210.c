
undefined4 * FUN_0077e210(undefined4 *param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00915463;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  DAT_00fba828 = DAT_00fba828 + 1;
  param_1[1] = DAT_00fba828;
  *param_1 = FoxUI::FXUICharSetItem::vftable;
  param_1[7] = 7;
  param_1[6] = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  local_8 = 1;
  FUN_00757200(param_1 + 9);
  ExceptionList = local_10;
  return param_1;
}

