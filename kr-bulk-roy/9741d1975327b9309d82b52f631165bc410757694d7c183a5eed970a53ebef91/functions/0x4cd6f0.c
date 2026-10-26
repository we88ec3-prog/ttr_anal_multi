
undefined4 * FUN_004cd6f0(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00917674;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_004c7070(param_1);
  local_8 = 0;
  *param_1 = CCharacter::vftable;
  param_1[0x3c] = CCharacter::vftable;
  param_1[0x108] = 0;
  param_1[0x109] = 0;
  puVar3 = (undefined4 *)FUN_00891268(0x30,uVar2);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = IS3D::CFieldPanel::vftable;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[4] = 0x3f800000;
    puVar3[5] = 0;
    puVar3[6] = 0;
    puVar3[7] = 0;
    puVar3[9] = 0;
    puVar3[10] = 0;
    puVar3[0xb] = 0;
  }
  param_1[0x10b] = puVar3;
  puVar3 = (undefined4 *)FUN_00891268(0x30,uVar2);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3[4] = 0x3f800000;
    *puVar3 = IS3D::CFieldPanel::vftable;
    puVar3[1] = 0;
    puVar3[2] = 0;
    puVar3[3] = 0;
    puVar3[5] = 0;
    puVar3[6] = 0;
    puVar3[7] = 0;
    puVar3[9] = 0;
    puVar3[10] = 0;
    puVar3[0xb] = 0;
  }
  param_1[0x10c] = puVar3;
  param_1[0x10d] = param_2;
  param_1[0x10e] = 0;
  puVar4 = (undefined2 *)FUN_00891268(0x1c,uVar2);
  if (puVar4 == (undefined2 *)0x0) {
    puVar4 = (undefined2 *)0x0;
  }
  else {
    *puVar4 = 0;
    *(undefined4 *)(puVar4 + 2) = 0;
    *(undefined4 *)(puVar4 + 4) = 0;
    *(undefined4 *)(puVar4 + 6) = 0;
    *(undefined4 *)(puVar4 + 8) = 0;
    *(undefined4 *)(puVar4 + 0xc) = 0;
  }
  param_1[0x10f] = puVar4;
  param_1[0x110] = 0;
  FUN_007bedc0(param_1[0x10b],0,0x40a00000,0x40a00000,0,0,0);
  FUN_007bedc0(param_1[0x10c],0,0x40a00000,0x40a00000,0,0,0);
  puVar3 = (undefined4 *)FUN_00891268(0x3c);
  local_8._0_1_ = 1;
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
  local_8._0_1_ = 0;
  iVar1 = puVar3[2];
  if (param_1[iVar1 + 0x3d] != 0) {
    FUN_006edb60("State Conflict!\n");
  }
  param_1[iVar1 + 0x3d] = puVar3;
  if (param_1[0x56] == 0) {
    param_1[0x56] = puVar3;
  }
  puVar3 = (undefined4 *)FUN_00891268(0x3c);
  local_8._0_1_ = 2;
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_004cb230();
    puVar3[0xe] = 9;
    puVar3[0xb] = 1;
    *puVar3 = CharStates::CAttackedState::vftable;
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
  puVar3 = (undefined4 *)FUN_00891268(0x38);
  local_8._0_1_ = 3;
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_004cb230();
    *puVar3 = CharStates::CForceState::vftable;
    puVar3[0xc] = 1;
    puVar3[0xb] = 1;
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
  puVar3 = (undefined4 *)FUN_00891268(0x3c);
  local_8 = CONCAT31(local_8._1_3_,4);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_004cb230();
    *puVar3 = CharStates::CDeadState::vftable;
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
  param_1[0xe7] = 0;
  ExceptionList = local_10;
  return param_1;
}

