
void FUN_00857730(int *param_1)

{
  uint uVar1;
  int iVar2;
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908fa3;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_00850dc0(param_1,local_14,*param_1,param_1[1]);
  if (param_1[4] != param_1[5]) {
    iVar2 = FUN_00858240(param_1[5],param_1,uVar1);
    FUN_00516210(param_1[5]);
    param_1[5] = iVar2;
  }
  if (param_1[4] != 0) {
    FUN_00516210(param_1[5]);
    FUN_0089120c(param_1[4]);
  }
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  if (*param_1 != 0) {
    FUN_008508b0(param_1[1]);
    FUN_0089120c(*param_1);
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  ExceptionList = local_10;
  return;
}

