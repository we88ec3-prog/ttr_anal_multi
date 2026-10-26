
undefined4 * FUN_004d2120(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091086e;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_004c7070(param_1);
  local_8 = 0;
  *param_1 = CNPC::vftable;
  param_1[0x3c] = CNPC::vftable;
  param_1[0x108] = 0;
  param_1[0x109] = 0xffffffff;
  param_1[0x10a] = 0;
  puVar3 = (undefined4 *)FUN_00891268(0x3c,uVar2);
  local_8._0_1_ = 1;
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_004cb230();
    *puVar3 = ActorStates::CDeadState::vftable;
    puVar3[0xd] = 1;
  }
  local_8._0_1_ = 0;
  iVar1 = puVar3[2];
  if (param_1[iVar1 + 0x3d] != 0) {
    FUN_006edb60("State Conflict!\n");
  }
  param_1[iVar1 + 0x3d] = puVar3;
  if (param_1[0x56] == 0) {
    param_1[0x56] = puVar3;
  }
  puVar3 = (undefined4 *)FUN_00891268(0x3c,uVar2);
  local_8 = CONCAT31(local_8._1_3_,2);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_004cb230();
    puVar3[10] = 1;
    puVar3[0xb] = 1;
    puVar3[0xc] = 1;
    *puVar3 = CharStates::CMoveState::vftable;
    puVar3[0xe] = 0;
  }
  iVar1 = puVar3[2];
  if (param_1[iVar1 + 0x3d] != 0) {
    FUN_006edb60("State Conflict!\n");
  }
  param_1[iVar1 + 0x3d] = puVar3;
  if (param_1[0x56] == 0) {
    param_1[0x56] = puVar3;
  }
  param_1[0xe7] = 0;
  ExceptionList = local_10;
  return param_1;
}

