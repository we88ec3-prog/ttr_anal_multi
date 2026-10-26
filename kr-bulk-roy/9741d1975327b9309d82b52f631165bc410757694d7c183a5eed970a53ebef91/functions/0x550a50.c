
void FUN_00550a50(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090ae60;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = CCustomEffectMgr::vftable;
  local_8 = 0;
  if (param_1[0x10] != 0) {
    FUN_0089120c(param_1[0x10],uVar2);
  }
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  FUN_00552640(param_1 + 0xd);
  FUN_0089120c(param_1[0xd],uVar2);
  local_8._0_1_ = 3;
  FUN_0057ffd0(*(undefined4 *)param_1[9],(undefined4 *)param_1[9]);
  FUN_0089120c(param_1[9]);
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_005540c0(*(undefined4 *)param_1[5],(undefined4 *)param_1[5]);
  FUN_0089120c(param_1[5]);
  piVar1 = (int *)param_1[1];
  piVar3 = (int *)*piVar1;
  *piVar1 = (int)piVar1;
  *(undefined4 *)(param_1[1] + 4) = param_1[1];
  param_1[2] = 0;
  if (piVar3 != (int *)param_1[1]) {
    do {
      piVar1 = (int *)*piVar3;
      FUN_0089120c(piVar3);
      piVar3 = piVar1;
    } while (piVar1 != (int *)param_1[1]);
  }
  FUN_0089120c(param_1[1]);
  *param_1 = IDXManagedObject::vftable;
  ExceptionList = local_10;
  return;
}

