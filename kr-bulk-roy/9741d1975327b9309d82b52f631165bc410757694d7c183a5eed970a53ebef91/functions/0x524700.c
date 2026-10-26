
void FUN_00524700(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091e170;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CNPCTable::vftable;
  param_1[1] = CNPCTable::vftable;
  local_8 = 0;
  if (param_1[10] != 0) {
    FUN_0089120c(param_1[10],uVar1);
  }
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  local_8._0_1_ = 3;
  FUN_00527900(*(undefined4 *)param_1[7],(undefined4 *)param_1[7]);
  FUN_0089120c(param_1[7],uVar1);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_005540c0(*(undefined4 *)param_1[3],(undefined4 *)param_1[3]);
  FUN_0089120c(param_1[3]);
  param_1[1] = IDataTable::vftable;
  *param_1 = CSingleton<CNPCTable>::vftable;
  DAT_00fe1bd0 = 0;
  ExceptionList = local_10;
  return;
}

