
void FUN_0065def0(int param_1)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  short *psVar5;
  int in_ECX;
  undefined2 local_a0 [4];
  undefined4 uStack_98;
  int iStack_94;
  uint *local_90;
  short *local_8c;
  int local_70;
  undefined1 *local_6c;
  uint local_68 [4];
  undefined4 local_58;
  uint local_54;
  undefined4 local_4c;
  undefined4 local_3c;
  uint local_38;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009462a2;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_68[0] = local_68[0] & 0xffff0000;
  local_8c = &DAT_00bed1fc;
  local_54 = 7;
  local_58 = 0;
  local_90 = (uint *)0x65df44;
  FUN_00402160();
  local_8 = 0;
  local_8c = &DAT_00bed1fc;
  local_38 = 7;
  local_3c = 0;
  local_4c = (short *)((uint)local_4c._2_2_ << 0x10);
  local_90 = (uint *)0x65df61;
  FUN_00402160();
  local_8._0_1_ = 1;
  iVar3 = param_1;
  switch(in_ECX) {
  case 5:
    FUN_0040f930();
    iVar3 = FUN_00500f90();
    break;
  case 6:
    FUN_0040f930();
    iVar3 = FUN_00500f90();
    break;
  case 7:
    FUN_0040f930();
    iVar3 = FUN_00500f90();
    break;
  case 8:
    FUN_0040f930();
    iVar3 = FUN_00500f90();
    break;
  case 9:
    FUN_0040f930();
    iVar3 = FUN_00500f90();
  }
  if ((in_ECX == 2) || (in_ECX == 4)) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8._0_1_ = 2;
      local_8c = (short *)0x65e0ab;
      FUN_00584c40();
      local_8c = (short *)0x65e0b5;
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8._0_1_ = 1;
    }
    local_6c = (undefined1 *)0x28b;
    local_8c = (short *)0x65e0d4;
    FUN_005740f0();
    if (local_70 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8._0_1_ = 3;
      local_8c = (short *)0x65e117;
      FUN_00584c40();
      local_8c = (short *)0x65e121;
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8._0_1_ = 1;
    }
    local_6c = (undefined1 *)0x34c;
    local_8c = (short *)0x65e140;
    FUN_005740f0();
    if (local_70 == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    FUN_004ed610();
    local_8._0_1_ = 4;
  }
  else {
    if ((DAT_00fb725c & 1) == 0) {
      DAT_00fb725c = DAT_00fb725c | 1;
      local_8._0_1_ = 5;
      FUN_004a79a0();
      local_8c = (undefined2 *)0x65e015;
      _atexit((_func_4879 *)&DAT_00bccf80);
      local_8._0_1_ = 1;
    }
    local_6c = (undefined1 *)local_a0;
    FUN_004a7f20(local_a0,*(undefined4 *)(iVar3 + 0x20));
    local_8._0_1_ = 6;
    local_70 = 0x34c;
    iVar3 = FUN_00585620();
    FUN_005740f0(&local_70);
    if (local_6c == *(undefined1 **)(iVar3 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    puVar4 = (undefined4 *)(local_6c + 0x10);
    if (7 < *(uint *)(local_6c + 0x24)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    local_8._0_1_ = 1;
    FUN_00424c80(puVar4);
    local_8._0_1_ = 7;
  }
  local_8c = (short *)0x65e174;
  FUN_00402800();
  local_8._0_1_ = 1;
  if (7 < local_1c) {
    local_8c = (short *)0x65e186;
    FUN_0089120c();
  }
  local_6c = (undefined1 *)local_a0;
  local_8c = (short *)0x7;
  local_90 = (uint *)0x0;
  local_a0[0] = 0;
  FUN_004026e0(local_68,0,0xffffffff);
  FUN_004796c0((&PTR_DAT_00d6a1c4)[in_ECX]);
  local_8._0_1_ = 8;
  local_8c = (short *)0x65e1d4;
  FUN_00402800();
  local_8._0_1_ = 1;
  if (7 < local_1c) {
    local_8c = (short *)0x65e1e6;
    FUN_0089120c();
  }
  local_8c = local_4c;
  if (local_38 < 8) {
    local_8c = (short *)&local_4c;
  }
  local_30[0] = local_30[0] & 0xffff0000;
  local_1c = 7;
  local_20 = 0;
  psVar5 = local_8c;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  local_90 = (uint *)0x65e229;
  FUN_00402160();
  iVar3 = *(int *)(param_1 + 0xf8);
  local_8._0_1_ = 9;
  FUN_007578f0();
  local_8c = (short *)0x7b;
  local_90 = local_30;
  uStack_98 = 0x65e24f;
  iStack_94 = iVar3 + 0xe8;
  FUN_00759ed0();
  local_8 = CONCAT31(local_8._1_3_,1);
  if (7 < local_1c) {
    local_8c = (short *)0x65e261;
    FUN_0089120c();
  }
  (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
  if (7 < local_38) {
    local_8c = (short *)0x65e282;
    FUN_0089120c();
  }
  local_38 = 7;
  local_3c = 0;
  local_4c = (short *)((uint)local_4c & 0xffff0000);
  if (7 < local_54) {
    local_8c = (short *)0x65e2a7;
    FUN_0089120c();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

