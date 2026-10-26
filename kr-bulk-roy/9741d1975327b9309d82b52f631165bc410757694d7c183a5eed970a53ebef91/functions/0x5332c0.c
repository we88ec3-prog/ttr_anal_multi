
void FUN_005332c0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00916eeb;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CTownInfoTable::vftable;
  param_1[1] = CTownInfoTable::vftable;
  local_8 = 2;
  FUN_00533840(*(undefined4 *)param_1[3],(undefined4 *)param_1[3]);
  FUN_0089120c(param_1[3],uVar1);
  param_1[1] = IDataTable::vftable;
  *param_1 = CSingleton<CTownInfoTable>::vftable;
  DAT_00fe1d98 = 0;
  ExceptionList = local_10;
  return;
}

