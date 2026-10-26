
void FUN_0084bc50(int *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091c350;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (param_1[0x10] != 0) {
    FUN_0089120c(param_1[0x10],uVar1);
  }
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  if (param_1[0xc] != 0) {
    FUN_0089120c(param_1[0xc],uVar1);
  }
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  if (param_1[8] != 0) {
    FUN_0089120c(param_1[8],uVar1);
  }
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00850f30(*(undefined4 *)param_1[5],(undefined4 *)param_1[5]);
  FUN_0089120c(param_1[5],uVar1);
  if (*param_1 != 0) {
    FUN_00516210(param_1[1]);
    FUN_0089120c(*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  ExceptionList = local_10;
  return;
}

