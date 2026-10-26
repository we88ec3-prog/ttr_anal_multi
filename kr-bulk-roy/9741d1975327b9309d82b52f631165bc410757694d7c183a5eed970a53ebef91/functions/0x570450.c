
void FUN_00570450(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009082c0;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 1;
  FUN_005540c0(*(undefined4 *)param_1[9],(undefined4 *)param_1[9]);
  FUN_0089120c(param_1[9],uVar1);
  if (0xf < (uint)param_1[5]) {
    FUN_0089120c(*param_1,uVar1);
  }
  param_1[5] = 0xf;
  param_1[4] = 0;
  *(undefined1 *)param_1 = 0;
  ExceptionList = local_10;
  return;
}

