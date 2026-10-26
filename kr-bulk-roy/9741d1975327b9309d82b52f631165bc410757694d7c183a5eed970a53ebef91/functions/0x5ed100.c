
void FUN_005ed100(void)

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
  uint uStack_c0;
  undefined4 local_b0;
  undefined4 local_a0;
  uint local_9c;
  undefined1 *local_94;
  undefined4 local_90;
  wchar_t *local_8c;
  undefined4 *local_88;
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
  uStack_c0 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  pwVar5 = (wchar_t *)0x0;
  local_14 = uStack_c0;
  if (**(int **)(in_ECX + 0x184) == 0) goto LAB_005ed58a;
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (short ***)((uint)local_4c[0] & 0xffff0000);
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
  local_54 = 7;
  local_58 = 0;
  local_68[0] = (short ***)((uint)local_68[0] & 0xffff0000);
  local_94 = (undefined1 *)&puStack_d0;
  local_8 = 2;
  FUN_007e8a90(&puStack_d0,*(int **)(in_ECX + 0x184) + 0x4e);
  FUN_005e6f40();
  pppsStack_c4 = *(short ****)(in_ECX + 0x184);
  if (pppsStack_c4 != (short ***)0x0) {
    pppsStack_c8 = (short ***)local_30;
    pppsStack_cc = (short ***)0x5ed1a1;
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
      goto switchD_005ed1bb_caseD_5;
    case 0x15:
      pppsStack_c4 = *(short ****)(iVar2 + 4);
    }
    pppsStack_c8 = (short ***)local_30;
    pppsStack_cc = (short ***)0x5ed1df;
    FUN_005e4b70();
switchD_005ed1bb_caseD_5:
    pppsStack_c8 = (short ***)local_30;
    pppsStack_cc = (short ***)0x5ed1e9;
    pppsStack_c4 = (short ***)iVar2;
    FUN_005e3bc0();
    pppsStack_c8 = (short ***)local_30;
    pppsStack_cc = (short ***)0x5ed1f3;
    pppsStack_c4 = (short ***)iVar2;
    FUN_005e4340();
  }
  pppsStack_c4 = (short ***)local_30;
  pppsStack_c8 = (short ***)0x5ed1fe;
  FUN_005e2440();
  pppsStack_c4 = (short ***)local_30;
  pppsStack_c8 = (short ***)0x5ed209;
  FUN_005e3ab0();
  pppsStack_c4 = (short ***)local_30;
  pppsStack_cc = (short ***)0x5ed213;
  FUN_005e2510();
  pppsStack_c8 = *(short ****)(in_ECX + 0x184);
  pppsStack_c4 = *(short ****)(in_ECX + 0x188);
  if (pppsStack_c8 != (short ***)0x0) {
    pppsStack_cc = (short ***)0x5ed22d;
    FUN_005e4060();
  }
  pppsStack_c4 = *(short ****)(in_ECX + 0x180);
  if (pppsStack_c4 != (short ***)0x0) {
    pppsStack_c8 = (short ***)0x5ed240;
    FUN_005e8d20();
  }
  pppsStack_c8 = (short ***)0x5ed246;
  FUN_005ed5e0();
  if (*(int *)(in_ECX + 0x184) == 0) {
    local_88 = (undefined4 *)0x0;
  }
  else {
    pppsStack_c4 = (short ***)&local_88;
    pppsStack_c8 = (short ***)&local_8c;
    pppsStack_cc = (short ***)&local_90;
    puStack_d0 = (undefined4 *)0x5ed26a;
    FUN_005e7f60();
    pwVar5 = local_8c;
  }
  pppsStack_c4 = (short ***)&local_90;
  pppsStack_c8 = (short ***)&local_8c;
  pppsStack_cc = (short ***)&local_94;
  puStack_d0 = (undefined4 *)0x5ed29c;
  FUN_005e7cc0();
  local_70 = 7;
  local_74 = 0;
  local_84 = (short ****)((uint)local_84._2_2_ << 0x10);
  local_8 = CONCAT31(local_8._1_3_,3);
  if (*(char *)(in_ECX + 0x19c) == '\0') {
    pppsStack_cc = *(short ****)(in_ECX + 0x184);
    pppsStack_c4 = (short ***)local_88;
    puStack_d0 = &local_84;
    pppsStack_c8 = (short ***)pwVar5;
    FUN_005e7920();
  }
  else {
    pppsStack_c4 = (short ***)local_90;
    pppsStack_c8 = (short ***)local_8c;
    pppsStack_cc = (short ***)local_94;
    puStack_d0 = local_88;
    FUN_005e7af0(&local_84,pwVar5);
  }
  if (*(int *)(*(int *)(in_ECX + 0x184) + 0xc4) != 0) {
    pppsStack_c4 = (short ***)0x9;
    pppsStack_c8 = (short ***)0xc26b70;
    pppsStack_cc = (short ***)0x5ed324;
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
    pppsStack_cc = (short ***)0x5ed35f;
    FUN_00404300();
    pppsStack_c4 = (short ***)0x4;
    pppsStack_c8 = (short ***)0xc02b9c;
    pppsStack_cc = (short ***)0x5ed36b;
    FUN_00404300();
  }
  if (*(char *)(in_ECX + 0x19c) == '\0') {
    pppsStack_c4 = (short ***)0x5ed389;
    FUN_005e5ab0();
  }
  else {
    pppsStack_c4 = (short ***)local_68;
    pppsStack_c8 = (short ***)0x5ed37f;
    FUN_005e5310();
  }
  pppsStack_c4 = (short ***)local_68;
  pppsStack_c8 = (short ***)0x5ed398;
  FUN_005e5ee0();
  pppsStack_c4 = (short ***)local_68;
  pppsStack_c8 = (short ***)0x5ed3a3;
  FUN_005e2770();
  pppsStack_c4 = (short ***)0xffffffff;
  pppsStack_c8 = (short ***)0x0;
  pppsStack_cc = (short ***)local_30;
  puStack_d0 = (undefined4 *)0x5ed3b3;
  FUN_004041f0();
  pppsStack_c4 = (short ***)0xffffffff;
  pppsStack_c8 = (short ***)0x0;
  pppsStack_cc = (short ***)&local_84;
  puStack_d0 = (undefined4 *)0x5ed3c3;
  FUN_004041f0();
  if (*(int *)(*(int *)(in_ECX + 0x184) + 0xe0) != 0) {
    pppsStack_c4 = (short ***)0x9;
    pppsStack_c8 = (short ***)0xc26268;
    pppsStack_cc = (short ***)0x5ed3e1;
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
    pppsStack_cc = (short ***)0x5ed41c;
    FUN_00404300();
    pppsStack_c4 = (short ***)0x4;
    pppsStack_c8 = (short ***)0xc02b9c;
    pppsStack_cc = (short ***)0x5ed428;
    FUN_00404300();
  }
  pppsStack_c4 = (short ***)0xffffffff;
  pppsStack_c8 = (short ***)0x0;
  pppsStack_cc = (short ***)local_68;
  puStack_d0 = (undefined4 *)0x5ed438;
  FUN_004041f0();
  if (*(int *)(in_ECX + 0x174) == 0) {
    pppsStack_c4 = (short ***)local_4c;
    pppsStack_c8 = (short ***)0x5ed45e;
    FUN_005e3750();
  }
  else {
    pppsStack_c4 = (short ***)0x5ed451;
    FUN_005e2870();
  }
  pppsStack_c4 = (short ***)0x4;
  pppsStack_c8 = (short ***)0xc02b9c;
  pppsStack_cc = (short ***)0x5ed46d;
  FUN_00404300();
  pppsStack_c4 = *(short ****)(in_ECX + 0x180);
  if (pppsStack_c4 != (short ***)0x0) {
    pppsStack_c8 = (short ***)0x5ed47f;
    FUN_005e86e0();
  }
  pppsStack_c4 = *(short ****)(in_ECX + 0x184);
  pppsStack_c8 = (short ***)local_4c;
  pppsStack_cc = (short ***)0x5ed48f;
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
  pppsStack_cc = (short ***)0x5ed4dc;
  FUN_00402160();
  iVar2 = *(int *)(in_ECX + 0x198);
  local_8 = CONCAT31(local_8._1_3_,4);
  pppsStack_c4 = (short ***)0x5ed4f3;
  FUN_007578f0();
  pppsStack_c4 = (short ***)0x7d;
  pppsStack_c8 = (short ***)0x7b;
  pppsStack_cc = (short ***)&local_b0;
  puStack_d0 = (undefined4 *)(iVar2 + 0xe8);
  FUN_00759ed0();
  if (7 < local_9c) {
    pppsStack_c4 = (short ***)local_b0;
    pppsStack_c8 = (short ***)0x5ed51d;
    FUN_0089120c();
  }
  if (7 < local_70) {
    pppsStack_c4 = (short ***)local_84;
    pppsStack_c8 = (short ***)0x5ed52e;
    FUN_0089120c();
  }
  local_70 = 7;
  local_74 = 0;
  local_84 = (short ****)((uint)local_84 & 0xffff0000);
  if (7 < local_54) {
    pppsStack_c4 = local_68[0];
    pppsStack_c8 = (short ***)0x5ed54d;
    FUN_0089120c();
  }
  local_54 = 7;
  local_58 = 0;
  local_68[0] = (short ***)((uint)local_68[0] & 0xffff0000);
  if (7 < local_1c) {
    pppsStack_c4 = local_30[0];
    pppsStack_c8 = (short ***)0x5ed56a;
    FUN_0089120c();
  }
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
  if (7 < local_38) {
    pppsStack_c4 = local_4c[0];
    pppsStack_c8 = (short ***)0x5ed587;
    FUN_0089120c();
  }
LAB_005ed58a:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

