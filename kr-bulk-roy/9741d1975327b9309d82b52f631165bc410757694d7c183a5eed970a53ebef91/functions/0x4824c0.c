
void FUN_004824c0(void)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  code *pcVar4;
  short *psVar5;
  short *psVar6;
  undefined4 uVar7;
  int unaff_EDI;
  undefined4 local_54;
  undefined4 local_44;
  uint local_40;
  float local_38;
  float local_34;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092b2ba;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
  }
  local_8 = 0xffffffff;
  local_38 = 1.03836e-42;
  FUN_005740f0(&local_38);
  if (local_34 == DAT_00fe5ac8) {
    pcVar4 = (code *)swi(3);
    (*pcVar4)();
    return;
  }
  psVar5 = (short *)((int)local_34 + 0x10);
  if (7 < *(uint *)((int)local_34 + 0x24)) {
    psVar5 = *(short **)psVar5;
  }
  local_1c = 7;
  local_20 = 0;
  local_30 = (short *)((uint)local_30._2_2_ << 0x10);
  psVar6 = psVar5;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar6 - (int)(psVar5 + 1) >> 1);
  local_8 = 1;
  local_8._1_3_ = 0;
  if (*(int *)(*(int *)(unaff_EDI + 0xfc) + 0x250) == -1) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8._0_1_ = 3;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = CONCAT31(local_8._1_3_,1);
    }
    local_34 = 1.03976e-42;
    FUN_005740f0(&local_34);
    if (local_38 == DAT_00fe5ac8) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    if (*(uint *)((int)local_38 + 0x24) < 8) {
      psVar5 = (short *)((int)local_38 + 0x10);
      psVar6 = psVar5;
    }
    else {
      psVar5 = *(short **)((int)local_38 + 0x10);
      psVar6 = psVar5;
    }
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
  }
  else {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8._0_1_ = 2;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = CONCAT31(local_8._1_3_,1);
    }
    local_34 = 1.03836e-42;
    FUN_005740f0(&local_34);
    if (local_38 == DAT_00fe5ac8) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    if (*(uint *)((int)local_38 + 0x24) < 8) {
      psVar5 = (short *)((int)local_38 + 0x10);
      psVar6 = psVar5;
    }
    else {
      psVar5 = *(short **)((int)local_38 + 0x10);
      psVar6 = psVar5;
    }
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
  }
  FUN_00402160(psVar6,(int)psVar5 - (int)(psVar6 + 1) >> 1);
  psVar5 = local_30;
  if (local_1c < 8) {
    psVar5 = (short *)&local_30;
  }
  local_54 = (uint)local_54._2_2_ << 0x10;
  local_40 = 7;
  local_44 = 0;
  psVar6 = psVar5;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar5,(int)psVar6 - (int)(psVar5 + 1) >> 1);
  iVar2 = *(int *)(unaff_EDI + 0x11c);
  local_8._0_1_ = 4;
  FUN_007578f0();
  FUN_00759ed0(iVar2 + 0xe8,&local_54,0x7b,0x7d);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (7 < local_40) {
    FUN_0089120c(local_54);
  }
  (**(code **)(**(int **)(unaff_EDI + 0x11c) + 200))();
  piVar3 = *(int **)(unaff_EDI + 0x114);
  if (((uint)piVar3[10] >> 8 & 1) != 0) {
    local_34 = (float)piVar3[0x20];
    if (local_34 <= 0.0) {
      (**(code **)(*piVar3 + 0x94))(0);
    }
    else {
      local_34 = local_34 - 0.006666667;
      if (local_34 <= 0.0) {
        local_34 = 0.0;
      }
      (**(code **)(*piVar3 + 0xd8))(local_34);
      (**(code **)(**(int **)(unaff_EDI + 0x114) + 200))();
    }
  }
  piVar3 = *(int **)(unaff_EDI + 0x118);
  if (((uint)piVar3[10] >> 8 & 1) != 0) {
    local_34 = (float)piVar3[0x20];
    if (local_34 <= 0.0) {
      (**(code **)(*piVar3 + 0x94))(0);
    }
    else {
      local_34 = local_34 - 0.006666667;
      if (local_34 <= 0.0) {
        local_34 = 0.0;
      }
      (**(code **)(*piVar3 + 0xd8))(local_34);
      (**(code **)(**(int **)(unaff_EDI + 0x118) + 200))();
    }
  }
  if (((*(int *)(*(int *)(unaff_EDI + 0xfc) + 0x250) == -1) ||
      (*(int *)(*(int *)(unaff_EDI + 0xf8) + 0x250) == -1)) ||
     (*(char *)(unaff_EDI + 0x14c) == '\0')) {
    uVar7 = 0xffffff00;
  }
  else {
    uVar7 = 0xffffff01;
  }
  (**(code **)(**(int **)(unaff_EDI + 0x120) + 0x90))(uVar7);
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

