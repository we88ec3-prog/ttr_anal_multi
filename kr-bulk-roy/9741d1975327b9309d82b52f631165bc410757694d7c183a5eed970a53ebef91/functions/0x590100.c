
void FUN_00590100(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00912830;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  param_1[7] = FUI::FXUIAttributeHistory::vftable;
  local_8 = 1;
  FUN_0051af60(*(undefined4 *)param_1[9],(undefined4 *)param_1[9]);
  FUN_0089120c(param_1[9],uVar1);
  if (7 < (uint)param_1[5]) {
    FUN_0089120c(*param_1,uVar1);
  }
  param_1[5] = 7;
  param_1[4] = 0;
  *(undefined2 *)param_1 = 0;
  ExceptionList = local_10;
  return;
}

