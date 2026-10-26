
void FUN_005f3100(void)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  short ****ppppsVar4;
  int in_ECX;
  wchar_t *pwVar5;
  undefined4 *puStack_d0;
  short ***pppsStack_cc;
  short ***pppsStack_c8;
  short ***pppsStack_c4;
  uint local_c0;
  undefined4 local_b0;
  undefined4 local_a0;
  uint local_9c;
  undefined4 local_94;
  wchar_t *local_90;
  undefined4 *local_8c;
  wchar_t *local_88;
  undefined4 local_84;
  undefined4 local_74;
  uint local_70;
  short ***local_68 [4];
  undefined4 local_58;
  uint local_54;
  short ***local_4c [4];
  undefined4 local_3c;
  uint local_38;
  short ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00948e0b;
  local_10 = ExceptionList;
  local_c0 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pwVar5 = (wchar_t *)0x0;
  local_14 = local_c0;
  if (**(int **)(in_ECX + 0x184) == 0) goto LAB_005f359a;
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (short ***)((uint)local_4c[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
  local_54 = 7;
  local_58 = 0;
  local_68[0] = (short ***)((uint)local_68[0] & 0xffff0000);
  local_88 = (wchar_t *)&puStack_d0;
  local_8 = 2;
  FUN_007e8a90(&puStack_d0,*(int **)(in_ECX + 0x184) + 0x4e);
  FUN_005e6f40();
  pppsStack_c4 = *(short ****)(in_ECX + 0x184);
  if (pppsStack_c4 != (short ***)0x0) {
    pppsStack_c8 = (short ***)local_30;
    pppsStack_cc = (short ***)0x5f31a1;
    FUN_005e1c60();
  }
  iVar2 = *(int *)(in_ECX + 0x184);
  if (iVar2 != 0) {
    switch(*(undefined4 *)(iVar2 + 8)) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 0xd:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x1b:
    case 0x1f:
    case 0x20:
    case 0x24:
    case 0x25:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
      pppsStack_c4 = *(short ****)(iVar2 + 4);
      break;
    default:
      goto switchD_005f31bb_caseD_5;
    case 0x15:
      pppsStack_c4 = *(short ****)(iVar2 + 4);
    }
    pppsStack_c8 = (short ***)local_30;
    pppsStack_cc = (short ***)0x5f31df;
    FUN_005e4b70();
switchD_005f31bb_caseD_5:
    pppsStack_c8 = (short ***)local_30;
    pppsStack_cc = (short ***)0x5f31e9;
    pppsStack_c4 = (short ***)iVar2;
    FUN_005e3bc0();
    pppsStack_c8 = (short ***)local_30;
    pppsStack_cc = (short ***)0x5f31f3;
    pppsStack_c4 = (short ***)iVar2;
    FUN_005e4340();
  }
  pppsStack_c4 = (short ***)local_30;
  pppsStack_c8 = (short ***)0x5f31fe;
  FUN_005e2440();
  pppsStack_c4 = (short ***)local_30;
  pppsStack_c8 = (short ***)0x5f3209;
  FUN_005e3ab0();
  pppsStack_c4 = (short ***)local_30;
  pppsStack_cc = (short ***)0x5f3213;
  FUN_005e2510();
  pppsStack_c8 = *(short ****)(in_ECX + 0x184);
  pppsStack_c4 = *(short ****)(in_ECX + 0x188);
  if (pppsStack_c8 != (short ***)0x0) {
    pppsStack_cc = (short ***)0x5f322d;
    FUN_005e4060();
  }
  pppsStack_c4 = *(short ****)(in_ECX + 0x180);
  if (pppsStack_c4 != (short ***)0x0) {
    pppsStack_c8 = (short ***)0x5f3240;
    FUN_005e8d20();
  }
  pppsStack_c8 = (short ***)0x5f3246;
  FUN_005f35f0();
  local_70 = 7;
  local_74 = 0;
  local_84 = (short ****)((uint)local_84._2_2_ << 0x10);
  local_8 = CONCAT31(local_8._1_3_,3);
  local_94 = 0;
  if (*(int *)(in_ECX + 0x184) == 0) {
    local_8c = (undefined4 *)0x0;
  }
  else {
    pppsStack_c4 = (short ***)&local_8c;
    pppsStack_c8 = (short ***)&local_90;
    pppsStack_cc = (short ***)&local_88;
    puStack_d0 = (undefined4 *)0x5f3284;
    FUN_005e81d0();
    pwVar5 = local_90;
  }
  pppsStack_c4 = (short ***)&local_94;
  pppsStack_c8 = (short ***)&local_88;
  pppsStack_cc = (short ***)&local_90;
  puStack_d0 = (undefined4 *)0x5f32b6;
  FUN_005e8440();
  if (*(char *)(in_ECX + 0x19c) == '\0') {
    pppsStack_cc = *(short ****)(in_ECX + 0x184);
    pppsStack_c4 = (short ***)local_8c;
    puStack_d0 = &local_84;
    pppsStack_c8 = (short ***)pwVar5;
    FUN_005e7580();
  }
  else {
    pppsStack_c4 = (short ***)local_94;
    pppsStack_c8 = (short ***)local_88;
    pppsStack_cc = (short ***)local_90;
    puStack_d0 = local_8c;
    FUN_005e7750(&local_84,pwVar5);
  }
  if (*(int *)(*(int *)(in_ECX + 0x184) + 0xc4) != 0) {
    pppsStack_c4 = (short ***)0x9;
    pppsStack_c8 = (short ***)0xc26b70;
    pppsStack_cc = (short ***)0x5f3327;
    FUN_00404300();
    iVar2 = *(int *)(in_ECX + 0x184);
    if (*(uint *)(iVar2 + 200) < 8) {
      pppsStack_c8 = (short ***)(iVar2 + 0xb4);
    }
    else {
      pppsStack_c8 = *(short ****)(iVar2 + 0xb4);
    }
    psVar3 = (short *)pppsStack_c8;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    pppsStack_c4 = (short ***)((int)psVar3 - (int)((int)pppsStack_c8 + 2) >> 1);
    pppsStack_cc = (short ***)0x5f3369;
    FUN_00404300();
    pppsStack_c4 = (short ***)0x4;
    pppsStack_c8 = (short ***)0xc02b9c;
    pppsStack_cc = (short ***)0x5f3375;
    FUN_00404300();
  }
  if (*(char *)(in_ECX + 0x19c) == '\0') {
    pppsStack_c4 = (short ***)0x5f3393;
    FUN_005e5ab0();
  }
  else {
    pppsStack_c4 = (short ***)local_68;
    pppsStack_c8 = (short ***)0x5f3389;
    FUN_005e5310();
  }
  pppsStack_c4 = (short ***)local_68;
  pppsStack_c8 = (short ***)0x5f33a2;
  FUN_005e5ee0();
  pppsStack_c4 = (short ***)local_68;
  pppsStack_c8 = (short ***)0x5f33ad;
  FUN_005e2770();
  pppsStack_c4 = (short ***)0xffffffff;
  pppsStack_c8 = (short ***)0x0;
  pppsStack_cc = (short ***)local_30;
  puStack_d0 = (undefined4 *)0x5f33bd;
  FUN_004041f0();
  pppsStack_c4 = (short ***)0xffffffff;
  pppsStack_c8 = (short ***)0x0;
  pppsStack_cc = (short ***)&local_84;
  puStack_d0 = (undefined4 *)0x5f33cd;
  FUN_004041f0();
  if (*(int *)(*(int *)(in_ECX + 0x184) + 0xe0) != 0) {
    pppsStack_c4 = (short ***)0x9;
    pppsStack_c8 = (short ***)0xc26268;
    pppsStack_cc = (short ***)0x5f33eb;
    FUN_00404300();
    iVar2 = *(int *)(in_ECX + 0x184);
    if (*(uint *)(iVar2 + 0xe4) < 8) {
      pppsStack_c8 = (short ***)(iVar2 + 0xd0);
    }
    else {
      pppsStack_c8 = *(short ****)(iVar2 + 0xd0);
    }
    psVar3 = (short *)pppsStack_c8;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    pppsStack_c4 = (short ***)((int)psVar3 - (int)((int)pppsStack_c8 + 2) >> 1);
    pppsStack_cc = (short ***)0x5f3429;
    FUN_00404300();
    pppsStack_c4 = (short ***)0x4;
    pppsStack_c8 = (short ***)0xc02b9c;
    pppsStack_cc = (short ***)0x5f3435;
    FUN_00404300();
  }
  pppsStack_c4 = (short ***)0xffffffff;
  pppsStack_c8 = (short ***)0x0;
  pppsStack_cc = (short ***)local_68;
  puStack_d0 = (undefined4 *)0x5f3445;
  FUN_004041f0();
  if (*(int *)(in_ECX + 0x174) == 0) {
    pppsStack_c4 = (short ***)local_4c;
    pppsStack_c8 = (short ***)0x5f346b;
    FUN_005e3750();
  }
  else {
    pppsStack_c4 = (short ***)0x5f345e;
    FUN_005e2870();
  }
  pppsStack_c4 = (short ***)0x4;
  pppsStack_c8 = (short ***)0xc02b9c;
  pppsStack_cc = (short ***)0x5f347a;
  FUN_00404300();
  pppsStack_c4 = *(short ****)(in_ECX + 0x180);
  if (pppsStack_c4 != (short ***)0x0) {
    pppsStack_c8 = (short ***)0x5f348c;
    FUN_005e86e0();
  }
  pppsStack_c4 = *(short ****)(in_ECX + 0x184);
  pppsStack_c8 = (short ***)local_4c;
  pppsStack_cc = (short ***)0x5f349c;
  FUN_005e8c10();
  pppsStack_c8 = local_4c[0];
  if (local_38 < 8) {
    pppsStack_c8 = (short ***)local_4c;
  }
  local_9c = 7;
  local_a0 = 0;
  local_b0 = (short ****)((uint)local_b0._2_2_ << 0x10);
  ppppsVar4 = (short ****)pppsStack_c8;
  do {
    sVar1 = *(short *)ppppsVar4;
    ppppsVar4 = (short ****)((int)ppppsVar4 + 2);
  } while (sVar1 != 0);
  pppsStack_c4 = (short ***)((int)ppppsVar4 - (int)((int)pppsStack_c8 + 2) >> 1);
  pppsStack_cc = (short ***)0x5f34ec;
  FUN_00402160();
  iVar2 = *(int *)(in_ECX + 0x198);
  local_8 = CONCAT31(local_8._1_3_,4);
  pppsStack_c4 = (short ***)0x5f3503;
  FUN_007578f0();
  pppsStack_c4 = (short ***)0x7d;
  pppsStack_c8 = (short ***)0x7b;
  pppsStack_cc = (short ***)&local_b0;
  puStack_d0 = (undefined4 *)(iVar2 + 0xe8);
  FUN_00759ed0();
  if (7 < local_9c) {
    pppsStack_c4 = (short ***)local_b0;
    pppsStack_c8 = (short ***)0x5f352d;
    FUN_0089120c();
  }
  if (7 < local_70) {
    pppsStack_c4 = (short ***)local_84;
    pppsStack_c8 = (short ***)0x5f353e;
    FUN_0089120c();
  }
  local_70 = 7;
  local_74 = 0;
  local_84 = (short ****)((uint)local_84 & 0xffff0000);
  if (7 < local_54) {
    pppsStack_c4 = local_68[0];
    pppsStack_c8 = (short ***)0x5f355d;
    FUN_0089120c();
  }
  local_54 = 7;
  local_58 = 0;
  local_68[0] = (short ***)((uint)local_68[0] & 0xffff0000);
  if (7 < local_1c) {
    pppsStack_c4 = local_30[0];
    pppsStack_c8 = (short ***)0x5f357a;
    FUN_0089120c();
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
  if (7 < local_38) {
    pppsStack_c4 = local_4c[0];
    pppsStack_c8 = (short ***)0x5f3597;
    FUN_0089120c();
  }
LAB_005f359a:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

