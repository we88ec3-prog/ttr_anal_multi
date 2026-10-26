
void FUN_0051a4e0(int *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091036d;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_00537240(param_1 + 8);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_00825810(*(undefined4 *)param_1[5],(undefined4 *)param_1[5]);
  FUN_0089120c(param_1[5],uVar1);
  if (*param_1 != 0) {
    FUN_0089120c(*param_1,uVar1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  ExceptionList = local_10;
  return;
}

