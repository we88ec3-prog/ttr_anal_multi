
undefined4 * FUN_004c7070(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined **local_34 [3];
  undefined **local_28 [3];
  char *local_1c;
  char *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090dadc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_004ca730(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  FUN_004c9f90();
  param_1[0x3c] = CObjFSM::vftable;
  local_8._0_1_ = 1;
  *param_1 = CActor::vftable;
  param_1[0x3c] = CActor::vftable;
  param_1[0x57] = 0;
  param_1[0x58] = 0;
  FUN_004ca460(param_1 + 0x57,0);
  local_8._0_1_ = 2;
  param_1[0xdb] = 0;
  param_1[0xdc] = 0;
  param_1[0xdd] = 1;
  param_1[0xe0] = 0;
  iVar1 = FUN_00891268(0x14);
  if (iVar1 == 0) {
    local_18 = (char *)0x0;
    std::exception::exception((exception *)local_34,&local_18);
    local_34[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00c857a8);
  }
  param_1[0xdf] = iVar1;
  *(int *)iVar1 = iVar1;
  *(undefined4 *)(param_1[0xdf] + 4) = param_1[0xdf];
  *(undefined4 *)(param_1[0xdf] + 8) = param_1[0xdf];
  *(undefined1 *)(param_1[0xdf] + 0x10) = 1;
  *(undefined1 *)(param_1[0xdf] + 0x11) = 1;
  local_8._0_1_ = 3;
  param_1[0xe3] = 1;
  param_1[0xeb] = 1;
  *(undefined2 *)(param_1 + 0xe2) = 0;
  param_1[0xe4] = 0;
  param_1[0xe6] = 0x3f800000;
  param_1[0xe7] = 0x7f;
  param_1[0xe8] = 0;
  *(undefined1 *)(param_1 + 0xe9) = 0;
  param_1[0xea] = 0;
  param_1[0xec] = 0;
  param_1[0xed] = 0;
  param_1[0xee] = 0;
  param_1[0xef] = 100;
  param_1[0xf0] = 100;
  param_1[0xf1] = 100;
  param_1[0xf2] = 100;
  param_1[0xf3] = 100;
  param_1[0xf4] = 100;
  param_1[0xf5] = 0;
  param_1[0xf6] = 0;
  param_1[0xf7] = 0;
  param_1[0xf8] = 0;
  param_1[0xf9] = 0;
  param_1[0xfa] = 0;
  param_1[0xfe] = 0;
  iVar1 = FUN_00891268(0x18);
  if (iVar1 != 0) {
    param_1[0xfd] = iVar1;
    *(int *)iVar1 = iVar1;
    *(undefined4 *)(param_1[0xfd] + 4) = param_1[0xfd];
    *(undefined4 *)(param_1[0xfd] + 8) = param_1[0xfd];
    *(undefined1 *)(param_1[0xfd] + 0x14) = 1;
    *(undefined1 *)(param_1[0xfd] + 0x15) = 1;
    local_8._0_1_ = 4;
    param_1[0x100] = 0;
    param_1[0x101] = 0;
    param_1[0x102] = 0;
    param_1[0x104] = 0;
    param_1[0x105] = 0;
    param_1[0x106] = 0;
    param_1[0x107] = 1;
    puVar2 = (undefined4 *)FUN_00891268(0x38);
    local_8._0_1_ = 5;
    if (puVar2 == (undefined4 *)0x0) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      local_14 = puVar2;
      FUN_004cb230();
      *puVar2 = ActorStates::CWaitState::vftable;
      puVar2[10] = 1;
      puVar2[0xb] = 1;
      puVar2[0xc] = 1;
      local_14 = puVar2;
    }
    local_8._0_1_ = 4;
    local_18 = (char *)local_14[2];
    if (param_1[(int)(local_18 + 0x3d)] != 0) {
      FUN_006edb60("State Conflict!\n");
    }
    param_1[(int)(local_18 + 0x3d)] = local_14;
    if (param_1[0x56] == 0) {
      param_1[0x56] = local_14;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x38);
    local_8._0_1_ = 6;
    if (puVar2 == (undefined4 *)0x0) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      local_14 = puVar2;
      FUN_004cb230();
      *puVar2 = ActorStates::CStunState::vftable;
      local_14 = puVar2;
    }
    local_8._0_1_ = 4;
    local_18 = (char *)local_14[2];
    if (param_1[(int)(local_18 + 0x3d)] != 0) {
      FUN_006edb60("State Conflict!\n");
    }
    param_1[(int)(local_18 + 0x3d)] = local_14;
    if (param_1[0x56] == 0) {
      param_1[0x56] = local_14;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x3c);
    local_8._0_1_ = 7;
    if (puVar2 == (undefined4 *)0x0) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      local_14 = puVar2;
      FUN_004cb230();
      puVar2[0xe] = 10;
      *puVar2 = ActorStates::CKnockdownState::vftable;
      local_14 = puVar2;
    }
    local_8._0_1_ = 4;
    local_18 = (char *)local_14[2];
    if (param_1[(int)(local_18 + 0x3d)] != 0) {
      FUN_006edb60("State Conflict!\n");
    }
    param_1[(int)(local_18 + 0x3d)] = local_14;
    if (param_1[0x56] == 0) {
      param_1[0x56] = local_14;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x3c);
    local_8._0_1_ = 8;
    if (puVar2 == (undefined4 *)0x0) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      local_14 = puVar2;
      FUN_004cb230();
      puVar2[0xe] = 0xb;
      *puVar2 = ActorStates::CRollState::vftable;
      local_14 = puVar2;
    }
    local_8._0_1_ = 4;
    local_18 = (char *)local_14[2];
    if (param_1[(int)(local_18 + 0x3d)] != 0) {
      FUN_006edb60("State Conflict!\n");
    }
    param_1[(int)(local_18 + 0x3d)] = local_14;
    if (param_1[0x56] == 0) {
      param_1[0x56] = local_14;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x3c);
    local_8._0_1_ = 9;
    if (puVar2 == (undefined4 *)0x0) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      local_14 = puVar2;
      FUN_004cb230();
      puVar2[0xe] = 0xc;
      *puVar2 = ActorStates::CFlyawayState::vftable;
      local_14 = puVar2;
    }
    local_8._0_1_ = 4;
    local_18 = (char *)local_14[2];
    if (param_1[(int)(local_18 + 0x3d)] != 0) {
      FUN_006edb60("State Conflict!\n");
    }
    param_1[(int)(local_18 + 0x3d)] = local_14;
    if (param_1[0x56] == 0) {
      param_1[0x56] = local_14;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x3c);
    local_8._0_1_ = 10;
    if (puVar2 == (undefined4 *)0x0) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      local_14 = puVar2;
      FUN_004cb230();
      puVar2[0xe] = 0xe;
      *puVar2 = ActorStates::CPullState::vftable;
      local_14 = puVar2;
    }
    local_8._0_1_ = 4;
    local_18 = (char *)local_14[2];
    if (param_1[(int)(local_18 + 0x3d)] != 0) {
      FUN_006edb60("State Conflict!\n");
    }
    param_1[(int)(local_18 + 0x3d)] = local_14;
    if (param_1[0x56] == 0) {
      param_1[0x56] = local_14;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x38);
    local_8._0_1_ = 0xb;
    if (puVar2 == (undefined4 *)0x0) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      local_14 = puVar2;
      FUN_004cb230();
      *puVar2 = ActorStates::CSitdownState::vftable;
      puVar2[0xb] = 1;
      puVar2[0xc] = 1;
      local_14 = puVar2;
    }
    local_8._0_1_ = 4;
    local_18 = (char *)local_14[2];
    if (param_1[(int)(local_18 + 0x3d)] != 0) {
      FUN_006edb60("State Conflict!\n");
    }
    param_1[(int)(local_18 + 0x3d)] = local_14;
    if (param_1[0x56] == 0) {
      param_1[0x56] = local_14;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x38);
    local_8._0_1_ = 0xc;
    if (puVar2 == (undefined4 *)0x0) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      local_14 = puVar2;
      FUN_004cb230();
      *puVar2 = ActorStates::CSkillState::vftable;
      local_14 = puVar2;
    }
    local_8._0_1_ = 4;
    local_18 = (char *)local_14[2];
    if (param_1[(int)(local_18 + 0x3d)] != 0) {
      FUN_006edb60("State Conflict!\n");
    }
    param_1[(int)(local_18 + 0x3d)] = local_14;
    if (param_1[0x56] == 0) {
      param_1[0x56] = local_14;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x38);
    local_8._0_1_ = 0xd;
    if (puVar2 == (undefined4 *)0x0) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      local_14 = puVar2;
      FUN_004cb230();
      *puVar2 = ActorStates::CStandingPullState::vftable;
      puVar2[0xb] = 1;
      local_14 = puVar2;
    }
    local_8._0_1_ = 4;
    local_18 = (char *)local_14[2];
    if (param_1[(int)(local_18 + 0x3d)] != 0) {
      FUN_006edb60("State Conflict!\n");
    }
    param_1[(int)(local_18 + 0x3d)] = local_14;
    if (param_1[0x56] == 0) {
      param_1[0x56] = local_14;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x38);
    local_8._0_1_ = 0xe;
    if (puVar2 == (undefined4 *)0x0) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      local_14 = puVar2;
      FUN_004cb230();
      *puVar2 = ActorStates::CStandingKnockdownState::vftable;
      puVar2[0xb] = 1;
      local_14 = puVar2;
    }
    local_8._0_1_ = 4;
    local_18 = (char *)local_14[2];
    if (param_1[(int)(local_18 + 0x3d)] != 0) {
      FUN_006edb60("State Conflict!\n");
    }
    param_1[(int)(local_18 + 0x3d)] = local_14;
    if (param_1[0x56] == 0) {
      param_1[0x56] = local_14;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x38);
    local_8._0_1_ = 0xf;
    if (puVar2 == (undefined4 *)0x0) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      local_14 = puVar2;
      FUN_004cb230();
      *puVar2 = ActorStates::CStandingRollState::vftable;
      puVar2[0xb] = 1;
      local_14 = puVar2;
    }
    local_8._0_1_ = 4;
    local_18 = (char *)local_14[2];
    if (param_1[(int)(local_18 + 0x3d)] != 0) {
      FUN_006edb60("State Conflict!\n");
    }
    param_1[(int)(local_18 + 0x3d)] = local_14;
    if (param_1[0x56] == 0) {
      param_1[0x56] = local_14;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x38);
    local_8._0_1_ = 0x10;
    if (puVar2 == (undefined4 *)0x0) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      local_14 = puVar2;
      FUN_004cb230();
      *puVar2 = ActorStates::CStandingFlyawayState::vftable;
      puVar2[0xb] = 1;
      local_14 = puVar2;
    }
    local_8._0_1_ = 4;
    local_18 = (char *)local_14[2];
    if (param_1[(int)(local_18 + 0x3d)] != 0) {
      FUN_006edb60("State Conflict!\n");
    }
    param_1[(int)(local_18 + 0x3d)] = local_14;
    if (param_1[0x56] == 0) {
      param_1[0x56] = local_14;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x38);
    local_8._0_1_ = 0x11;
    if (puVar2 == (undefined4 *)0x0) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      local_14 = puVar2;
      FUN_004cb230();
      *puVar2 = ActorStates::CSpecialDeath::vftable;
      puVar2[0xd] = 1;
      local_14 = puVar2;
    }
    local_8._0_1_ = 4;
    local_18 = (char *)local_14[2];
    if (param_1[(int)(local_18 + 0x3d)] != 0) {
      FUN_006edb60("State Conflict!\n");
    }
    param_1[(int)(local_18 + 0x3d)] = local_14;
    if (param_1[0x56] == 0) {
      param_1[0x56] = local_14;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x38);
    local_8._0_1_ = 0x12;
    if (puVar2 == (undefined4 *)0x0) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      local_14 = puVar2;
      FUN_004cb230();
      *puVar2 = ActorStates::CVanishState::vftable;
      puVar2[0xd] = 1;
      local_14 = puVar2;
    }
    local_8._0_1_ = 4;
    local_18 = (char *)local_14[2];
    if (param_1[(int)(local_18 + 0x3d)] != 0) {
      FUN_006edb60("State Conflict!\n");
    }
    param_1[(int)(local_18 + 0x3d)] = local_14;
    if (param_1[0x56] == 0) {
      param_1[0x56] = local_14;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x38);
    local_8._0_1_ = 0x13;
    if (puVar2 == (undefined4 *)0x0) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      local_14 = puVar2;
      FUN_004cb230();
      *puVar2 = ActorStates::CNoControlState::vftable;
      puVar2[10] = 1;
      puVar2[0xb] = 1;
      puVar2[0xc] = 1;
      local_14 = puVar2;
    }
    local_8._0_1_ = 4;
    local_18 = (char *)local_14[2];
    if (param_1[(int)(local_18 + 0x3d)] != 0) {
      FUN_006edb60("State Conflict!\n");
    }
    param_1[(int)(local_18 + 0x3d)] = local_14;
    if (param_1[0x56] == 0) {
      param_1[0x56] = local_14;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x38);
    local_8._0_1_ = 0x14;
    if (puVar2 == (undefined4 *)0x0) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      local_14 = puVar2;
      FUN_004cb230();
      *puVar2 = ActorStates::CPerformanceState::vftable;
      local_14 = puVar2;
    }
    local_8._0_1_ = 4;
    local_18 = (char *)local_14[2];
    if (param_1[(int)(local_18 + 0x3d)] != 0) {
      FUN_006edb60("State Conflict!\n");
    }
    param_1[(int)(local_18 + 0x3d)] = local_14;
    if (param_1[0x56] == 0) {
      param_1[0x56] = local_14;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x38);
    local_8._0_1_ = 0x15;
    if (puVar2 == (undefined4 *)0x0) {
      local_14 = (undefined4 *)0x0;
    }
    else {
      local_14 = puVar2;
      FUN_004cb230();
      *puVar2 = ActorStates::CUnsummonState::vftable;
      puVar2[0xd] = 1;
      local_14 = puVar2;
    }
    local_8 = CONCAT31(local_8._1_3_,4);
    local_18 = (char *)local_14[2];
    if (param_1[(int)(local_18 + 0x3d)] != 0) {
      FUN_006edb60("State Conflict!\n");
    }
    param_1[(int)(local_18 + 0x3d)] = local_14;
    if (param_1[0x56] == 0) {
      param_1[0x56] = local_14;
    }
    if (param_1[0x3e] != 0) {
      (**(code **)(*(int *)param_1[0x56] + 0xc))();
      *(undefined4 *)(param_1[0x3e] + 0xc) = *(undefined4 *)(param_1[0x56] + 8);
      param_1[0x56] = (int *)param_1[0x3e];
      (**(code **)(*(int *)param_1[0x3e] + 4))();
    }
    puVar2 = param_1 + 0x59;
    for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    param_1[0xd9] = 0;
    param_1[0xda] = 0;
    ExceptionList = local_10;
    return param_1;
  }
  local_1c = (char *)0x0;
  std::exception::exception((exception *)local_28,&local_1c);
  local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_28,&DAT_00c857a8);
}

