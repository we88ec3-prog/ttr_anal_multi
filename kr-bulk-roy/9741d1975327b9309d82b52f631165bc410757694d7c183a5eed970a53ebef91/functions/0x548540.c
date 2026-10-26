
undefined4 * FUN_00548540(undefined4 *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00933a8e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00544c40(param_1);
  local_8 = 0;
  *param_1 = CSingleController::vftable;
  iVar2 = FUN_00891268(0x18,uVar1);
  local_8._0_1_ = 1;
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0079c5b0();
  }
  local_8._0_1_ = 0;
  param_1[0x2d] = uVar3;
  iVar2 = FUN_00891268(0x40,uVar1);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0079cab0(iVar2,0);
  }
  param_1[0x2e] = uVar3;
  param_1[0x2f] = 0;
  DAT_00fba7ac = 2;
  ExceptionList = local_10;
  return param_1;
}

