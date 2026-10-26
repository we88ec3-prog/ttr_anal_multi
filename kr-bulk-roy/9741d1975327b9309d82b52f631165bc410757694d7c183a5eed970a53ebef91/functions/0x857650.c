
undefined4 * FUN_00857650(undefined4 *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined1 local_18 [4];
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090bc83;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  piVar1 = param_1 + 4;
  *piVar1 = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  local_8 = 1;
  uVar2 = param_2[1];
  local_14 = *param_2;
  FUN_00850dc0(param_1,local_18,*param_1,param_1[1]);
  FUN_008582d0(param_1,*param_1,local_14,uVar2,uVar2);
  local_14 = param_2[5];
  uVar3 = param_2[4];
  param_2 = (undefined4 *)uVar2;
  if (*piVar1 != param_1[5]) {
    param_2 = (undefined4 *)FUN_00858240(param_1[5],uVar2,uVar4);
    FUN_00516210(param_1[5]);
    param_1[5] = param_2;
  }
  FUN_008584a0(piVar1,*piVar1,uVar3,local_14,param_2);
  ExceptionList = local_10;
  return param_1;
}

