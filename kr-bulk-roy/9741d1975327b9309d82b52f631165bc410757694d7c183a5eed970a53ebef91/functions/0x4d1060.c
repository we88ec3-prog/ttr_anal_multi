
undefined4 * FUN_004d1060(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910923;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_004c7070(param_1);
  local_8 = 0;
  *param_1 = CEventObject::vftable;
  param_1[0x3c] = CEventObject::vftable;
  param_1[0x109] = 0;
  puVar3 = (undefined4 *)FUN_00891268(0x3c,uVar2);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_004cb230();
    *puVar3 = ActorStates::CDeadState::vftable;
    puVar3[0xd] = 1;
  }
  iVar1 = puVar3[2];
  if (param_1[iVar1 + 0x3d] != 0) {
    FUN_006edb60("State Conflict!\n");
  }
  param_1[iVar1 + 0x3d] = puVar3;
  if (param_1[0x56] == 0) {
    param_1[0x56] = puVar3;
  }
  ExceptionList = local_10;
  return param_1;
}

