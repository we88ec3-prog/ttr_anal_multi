
void FUN_007d60b0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00909e02;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 2;
  FUN_00504180(*(undefined4 *)(param_1[8] + 4));
  *(undefined4 *)(param_1[8] + 4) = param_1[8];
  *(undefined4 *)param_1[8] = param_1[8];
  *(undefined4 *)(param_1[8] + 8) = param_1[8];
  param_1[9] = 0;
  local_8._0_1_ = 3;
  FUN_005540c0(*(undefined4 *)param_1[0xe],(undefined4 *)param_1[0xe]);
  FUN_0089120c(param_1[0xe],uVar1);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_004f7fe0(*(undefined4 *)param_1[8],(undefined4 *)param_1[8]);
  FUN_0089120c(param_1[8]);
  if (0xf < (uint)param_1[5]) {
    FUN_0089120c(*param_1);
  }
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  ExceptionList = local_10;
  return;
}

