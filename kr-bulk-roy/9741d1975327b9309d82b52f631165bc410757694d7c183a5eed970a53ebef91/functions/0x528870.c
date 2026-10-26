
void FUN_00528870(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090d15b;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = COptionGrantTable::vftable;
  param_1[1] = COptionGrantTable::vftable;
  local_8 = 2;
  FUN_004ffa40(*(undefined4 *)param_1[3],(undefined4 *)param_1[3]);
  FUN_0089120c(param_1[3],uVar1);
  param_1[1] = IDataTable::vftable;
  *param_1 = CSingleton<COptionGrantTable>::vftable;
  DAT_00fc0e34 = 0;
  ExceptionList = local_10;
  return;
}

