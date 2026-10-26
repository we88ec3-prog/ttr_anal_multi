
void FUN_006ab220(int *param_1)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  short *psVar4;
  undefined4 uVar5;
  short *psVar6;
  int *piVar7;
  undefined2 auStack_a8 [8];
  undefined4 uStack_98;
  undefined2 *puStack_94;
  undefined4 *puStack_90;
  undefined2 auStack_8c [8];
  undefined4 uStack_7c;
  undefined4 local_58;
  undefined1 *local_54;
  undefined1 *local_50;
  int local_4c;
  int local_48;
  int local_34;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b68e;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(param_1[0x40] + 0xcc) == 0) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = *(int **)(*(int *)(param_1[0x40] + 0xcc) + 0xdc);
  }
  if (piVar7 == (int *)0x0) goto LAB_006ab546;
  iVar3 = (**(code **)(*piVar7 + 4))();
  if (iVar3 != 0x12d) {
    uStack_7c = 0x6ab294;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    piVar7 = (int *)0x0;
  }
  if (piVar7[0x93] != 2) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    local_54 = (undefined1 *)auStack_8c;
    puStack_90 = (undefined4 *)0x0;
    uStack_7c = 0;
    puStack_94 = &DAT_00bed1fc;
    auStack_8c[0] = 0;
    uStack_98 = 0x6ab305;
    FUN_00402160();
    local_8 = 1;
    local_58 = 0x91;
    puStack_90 = (undefined4 *)0x6ab314;
    iVar3 = FUN_005854b0();
    puStack_90 = &local_58;
    puStack_94 = (undefined2 *)0x6ab324;
    FUN_005740f0();
    if (local_50 == *(undefined1 **)(iVar3 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar6 = (short *)(local_50 + 0x10);
    if (7 < *(uint *)(local_50 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    local_50 = (undefined1 *)auStack_a8;
    puStack_94 = (undefined2 *)0x7;
    uStack_98 = 0;
    auStack_a8[0] = 0;
    psVar4 = psVar6;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar6,(int)psVar4 - (int)(psVar6 + 1) >> 1);
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
    goto LAB_006ab546;
  }
  local_1c = 7;
  local_20 = 0;
  local_30 = local_30 & 0xffff0000;
  FUN_004026e0();
  local_8 = 2;
  FUN_00404300();
  FUN_004041f0();
  iVar3 = D3DXGetImageInfoFromFileW();
  if (iVar3 < 0) {
    FUN_004054c0();
    local_54 = (undefined1 *)auStack_8c;
    puStack_90 = (undefined4 *)&DAT_00bed1fc;
    puStack_94 = (undefined2 *)0x6ab412;
    FUN_00402250();
    puStack_90 = (undefined4 *)0x92;
    local_8._0_1_ = 3;
    puStack_94 = (undefined2 *)0x6ab420;
    FUN_005854b0();
    puStack_94 = (undefined2 *)0x6ab427;
    uVar5 = FUN_00585330();
    local_50 = (undefined1 *)auStack_a8;
    FUN_00402250(uVar5);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_0058b270(0xca);
    if (7 < local_1c) {
      FUN_0089120c();
    }
    goto LAB_006ab546;
  }
  if (local_34 == 0) {
    if ((local_4c != 0x10) || (local_48 != 0x10)) {
      FUN_004054c0();
      local_54 = (undefined1 *)auStack_8c;
      puStack_90 = (undefined4 *)&DAT_00bed1fc;
      puStack_94 = (undefined2 *)0x6ab50a;
      FUN_00402250();
      local_8._0_1_ = 5;
      puStack_90 = (undefined4 *)0x95;
      goto LAB_006ab513;
    }
    FUN_0044fd50();
    iVar3 = FUN_004ed470();
    if (iVar3 == 0) {
      FUN_004054c0();
      local_54 = (undefined1 *)auStack_8c;
      puStack_90 = (undefined4 *)&DAT_00bed1fc;
      puStack_94 = (undefined2 *)0x6ab4d6;
      FUN_00402250();
      local_8._0_1_ = 6;
      puStack_90 = (undefined4 *)0x96;
      goto LAB_006ab513;
    }
    (**(code **)(*param_1 + 0xd4))();
  }
  else {
    FUN_004054c0();
    local_54 = (undefined1 *)auStack_8c;
    puStack_90 = (undefined4 *)&DAT_00bed1fc;
    puStack_94 = (undefined2 *)0x6ab481;
    FUN_00402250();
    local_8._0_1_ = 4;
    puStack_90 = (undefined4 *)0x94;
LAB_006ab513:
    puStack_94 = (undefined2 *)0x6ab518;
    FUN_005854b0();
    puStack_94 = (undefined2 *)0x6ab51f;
    uVar5 = FUN_00585330();
    local_50 = (undefined1 *)auStack_a8;
    FUN_00402250(uVar5);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_0058b270(0xca);
  }
  FUN_004fa440();
LAB_006ab546:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

