
void FUN_005f1ff0(void)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  short ****ppppsVar4;
  int in_ECX;
  undefined4 *puStack_104;
  short ***pppsStack_100;
  short ***pppsStack_fc;
  short ***pppsStack_f8;
  uint local_f4;
  undefined4 local_e4;
  undefined4 local_d4;
  uint local_d0;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined4 local_c0;
  undefined4 local_bc;
  undefined1 *local_b8;
  undefined4 local_b4;
  undefined4 *local_b0;
  undefined4 local_ac;
  undefined4 *local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_90;
  uint local_8c;
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
  puStack_c = &LAB_00948ed6;
  local_10 = ExceptionList;
  local_f4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = local_f4;
  if (**(int **)(in_ECX + 0x184) == 0) goto LAB_005f2596;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (short ***)((uint)local_4c[0] & 0xffff0000);
  local_54 = 7;
  local_58 = 0;
  local_68[0] = (short ***)((uint)local_68[0] & 0xffff0000);
  local_b8 = (undefined1 *)&puStack_104;
  local_8 = 2;
  FUN_007e8a90(&puStack_104,*(int **)(in_ECX + 0x184) + 0x4e);
  FUN_005e6f40();
  pppsStack_f8 = *(short ****)(in_ECX + 0x184);
  if (pppsStack_f8 != (short ***)0x0) {
    pppsStack_fc = (short ***)local_4c;
    pppsStack_100 = (short ***)0x5f2091;
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
      pppsStack_f8 = *(short ****)(iVar2 + 4);
      break;
    default:
      goto switchD_005f20ab_caseD_5;
    case 0x15:
      pppsStack_f8 = *(short ****)(iVar2 + 4);
    }
    pppsStack_fc = (short ***)local_4c;
    pppsStack_100 = (short ***)0x5f20cf;
    FUN_005e4b70();
switchD_005f20ab_caseD_5:
    pppsStack_fc = (short ***)local_4c;
    pppsStack_100 = (short ***)0x5f20d9;
    pppsStack_f8 = (short ***)iVar2;
    FUN_005e3bc0();
    pppsStack_fc = (short ***)local_4c;
    pppsStack_100 = (short ***)0x5f20e3;
    pppsStack_f8 = (short ***)iVar2;
    FUN_005e4340();
  }
  pppsStack_f8 = (short ***)local_4c;
  pppsStack_fc = (short ***)0x5f20ee;
  FUN_005e2440();
  if (*(int *)(*(int *)(in_ECX + 0x184) + 8) == 0x2b) {
    pppsStack_f8 = (short ***)local_4c;
    pppsStack_fc = (short ***)0x5f2105;
    FUN_005e3ab0();
  }
  pppsStack_f8 = (short ***)local_4c;
  pppsStack_100 = (short ***)0x5f210f;
  FUN_005e2510();
  pppsStack_fc = *(short ****)(in_ECX + 0x184);
  pppsStack_f8 = *(short ****)(in_ECX + 0x188);
  if (pppsStack_fc != (short ***)0x0) {
    pppsStack_100 = (short ***)0x5f2129;
    FUN_005e4060();
  }
  pppsStack_f8 = *(short ****)(in_ECX + 0x180);
  if (pppsStack_f8 != (short ***)0x0) {
    pppsStack_fc = (short ***)0x5f213c;
    FUN_005e8d20();
  }
  pppsStack_fc = (short ***)0x5f2142;
  FUN_005f14a0();
  local_70 = 7;
  local_74 = 0;
  local_84 = (short ****)((uint)local_84._2_2_ << 0x10);
  local_8c = 7;
  local_90 = 0;
  local_a0 = (short ****)((uint)local_a0._2_2_ << 0x10);
  local_8 = CONCAT31(local_8._1_3_,4);
  if (*(int *)(in_ECX + 0x184) == 0) {
    local_b4 = 0;
    local_a8 = (undefined4 *)0x0;
  }
  else {
    pppsStack_f8 = (short ***)&local_a8;
    pppsStack_fc = (short ***)&local_b4;
    pppsStack_100 = (short ***)&local_a4;
    puStack_104 = (undefined4 *)0x5f2190;
    FUN_005e81d0();
  }
  if (*(int *)(in_ECX + 0x184) == 0) {
    local_a4 = 0;
    local_b0 = (undefined4 *)0x0;
  }
  else {
    pppsStack_f8 = (short ***)&local_b0;
    pppsStack_fc = (short ***)&local_a4;
    pppsStack_100 = (short ***)&local_ac;
    puStack_104 = (undefined4 *)0x5f21ca;
    FUN_005e7f60();
  }
  pppsStack_f8 = (short ***)&local_ac;
  pppsStack_fc = (short ***)&local_c0;
  pppsStack_100 = (short ***)&local_c8;
  puStack_104 = (undefined4 *)0x5f21fa;
  FUN_005e8440();
  pppsStack_f8 = (short ***)&local_bc;
  pppsStack_fc = (short ***)&local_c4;
  pppsStack_100 = (short ***)&local_b8;
  puStack_104 = (undefined4 *)0x5f2216;
  FUN_005e7cc0();
  if (*(char *)(in_ECX + 0x19c) == '\0') {
    pppsStack_100 = *(short ****)(in_ECX + 0x184);
    pppsStack_f8 = (short ***)local_a8;
    pppsStack_fc = (short ***)local_b4;
    puStack_104 = &local_84;
    FUN_005e7580();
    pppsStack_100 = *(short ****)(in_ECX + 0x184);
    pppsStack_f8 = (short ***)local_b0;
    pppsStack_fc = (short ***)local_a4;
    puStack_104 = &local_a0;
    FUN_005e7920();
  }
  else {
    pppsStack_f8 = (short ***)local_ac;
    pppsStack_fc = (short ***)local_c0;
    pppsStack_100 = (short ***)local_c8;
    puStack_104 = local_a8;
    FUN_005e7750(&local_84,local_b4);
    pppsStack_f8 = (short ***)local_bc;
    pppsStack_fc = (short ***)local_c4;
    pppsStack_100 = (short ***)local_b8;
    puStack_104 = local_b0;
    FUN_005e7af0(&local_a0,local_a4);
  }
  pppsStack_f8 = (short ***)local_68;
  if (*(char *)(in_ECX + 0x19c) == '\0') {
    pppsStack_f8 = (short ***)0x5f22ea;
    FUN_005e5ab0();
  }
  else {
    pppsStack_fc = (short ***)0x5f22e3;
    FUN_005e5310();
  }
  pppsStack_f8 = (short ***)local_68;
  pppsStack_fc = (short ***)0x5f22f9;
  FUN_005e5ee0();
  pppsStack_f8 = (short ***)local_68;
  pppsStack_fc = (short ***)0x5f2304;
  FUN_005e2770();
  pppsStack_f8 = (short ***)0xffffffff;
  pppsStack_fc = (short ***)0x0;
  pppsStack_100 = (short ***)local_4c;
  puStack_104 = (undefined4 *)0x5f2314;
  FUN_004041f0();
  pppsStack_f8 = (short ***)0xffffffff;
  pppsStack_fc = (short ***)0x0;
  pppsStack_100 = (short ***)&local_84;
  puStack_104 = (undefined4 *)0x5f2324;
  FUN_004041f0();
  pppsStack_f8 = (short ***)0xffffffff;
  pppsStack_fc = (short ***)0x0;
  pppsStack_100 = (short ***)&local_a0;
  puStack_104 = (undefined4 *)0x5f2337;
  FUN_004041f0();
  if (*(int *)(*(int *)(in_ECX + 0x184) + 0xe0) != 0) {
    pppsStack_f8 = (short ***)0x9;
    pppsStack_fc = (short ***)0xc26268;
    pppsStack_100 = (short ***)0x5f2355;
    FUN_00404300();
    iVar2 = *(int *)(in_ECX + 0x184);
    if (*(uint *)(iVar2 + 0xe4) < 8) {
      pppsStack_fc = (short ***)(iVar2 + 0xd0);
    }
    else {
      pppsStack_fc = *(short ****)(iVar2 + 0xd0);
    }
    psVar3 = (short *)pppsStack_fc;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    pppsStack_f8 = (short ***)((int)psVar3 - (int)((int)pppsStack_fc + 2) >> 1);
    pppsStack_100 = (short ***)0x5f2390;
    FUN_00404300();
    pppsStack_f8 = (short ***)0x4;
    pppsStack_fc = (short ***)0xc02b9c;
    pppsStack_100 = (short ***)0x5f239c;
    FUN_00404300();
  }
  if (*(int *)(*(int *)(in_ECX + 0x184) + 0xc4) != 0) {
    pppsStack_f8 = (short ***)0x9;
    pppsStack_fc = (short ***)0xc26b70;
    pppsStack_100 = (short ***)0x5f23ba;
    FUN_00404300();
    iVar2 = *(int *)(in_ECX + 0x184);
    if (*(uint *)(iVar2 + 200) < 8) {
      pppsStack_fc = (short ***)(iVar2 + 0xb4);
    }
    else {
      pppsStack_fc = *(short ****)(iVar2 + 0xb4);
    }
    psVar3 = (short *)pppsStack_fc;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    pppsStack_f8 = (short ***)((int)psVar3 - (int)((int)pppsStack_fc + 2) >> 1);
    pppsStack_100 = (short ***)0x5f23f9;
    FUN_00404300();
    pppsStack_f8 = (short ***)0x4;
    pppsStack_fc = (short ***)0xc02b9c;
    pppsStack_100 = (short ***)0x5f2405;
    FUN_00404300();
  }
  pppsStack_f8 = (short ***)0xffffffff;
  pppsStack_fc = (short ***)0x0;
  pppsStack_100 = (short ***)local_68;
  puStack_104 = (undefined4 *)0x5f2415;
  FUN_004041f0();
  if (*(int *)(in_ECX + 0x174) == 0) {
    pppsStack_f8 = (short ***)local_30;
    pppsStack_fc = (short ***)0x5f2439;
    FUN_005e3750();
  }
  else {
    pppsStack_f8 = (short ***)0x5f242e;
    FUN_005e2870();
  }
  pppsStack_f8 = (short ***)0x4;
  pppsStack_fc = (short ***)0xc02b9c;
  pppsStack_100 = (short ***)0x5f2448;
  FUN_00404300();
  pppsStack_f8 = *(short ****)(in_ECX + 0x180);
  if (pppsStack_f8 != (short ***)0x0) {
    pppsStack_fc = (short ***)0x5f245a;
    FUN_005e86e0();
  }
  pppsStack_f8 = *(short ****)(in_ECX + 0x184);
  pppsStack_fc = (short ***)local_30;
  pppsStack_100 = (short ***)0x5f246a;
  FUN_005e8c10();
  pppsStack_fc = local_30[0];
  if (local_1c < 8) {
    pppsStack_fc = (short ***)local_30;
  }
  local_e4 = (short ****)((uint)local_e4._2_2_ << 0x10);
  local_d0 = 7;
  local_d4 = 0;
  ppppsVar4 = (short ****)pppsStack_fc;
  do {
    sVar1 = *(short *)ppppsVar4;
    ppppsVar4 = (short ****)((int)ppppsVar4 + 2);
  } while (sVar1 != 0);
  pppsStack_f8 = (short ***)((int)ppppsVar4 - (int)((int)pppsStack_fc + 2) >> 1);
  pppsStack_100 = (short ***)0x5f24bc;
  FUN_00402160();
  iVar2 = *(int *)(in_ECX + 0x198);
  local_8 = CONCAT31(local_8._1_3_,5);
  pppsStack_f8 = (short ***)0x5f24d3;
  FUN_007578f0();
  pppsStack_f8 = (short ***)0x7d;
  pppsStack_fc = (short ***)0x7b;
  pppsStack_100 = (short ***)&local_e4;
  puStack_104 = (undefined4 *)(iVar2 + 0xe8);
  FUN_00759ed0();
  if (7 < local_d0) {
    pppsStack_f8 = (short ***)local_e4;
    pppsStack_fc = (short ***)0x5f24fd;
    FUN_0089120c();
  }
  if (7 < local_8c) {
    pppsStack_f8 = (short ***)local_a0;
    pppsStack_fc = (short ***)0x5f2514;
    FUN_0089120c();
  }
  local_8c = 7;
  local_90 = 0;
  local_a0 = (short ****)((uint)local_a0 & 0xffff0000);
  if (7 < local_70) {
    pppsStack_f8 = (short ***)local_84;
    pppsStack_fc = (short ***)0x5f253c;
    FUN_0089120c();
  }
  local_70 = 7;
  local_74 = 0;
  local_84 = (short ****)((uint)local_84 & 0xffff0000);
  if (7 < local_54) {
    pppsStack_f8 = local_68[0];
    pppsStack_fc = (short ***)0x5f2559;
    FUN_0089120c();
  }
  local_54 = 7;
  local_58 = 0;
  local_68[0] = (short ***)((uint)local_68[0] & 0xffff0000);
  if (7 < local_38) {
    pppsStack_f8 = local_4c[0];
    pppsStack_fc = (short ***)0x5f2576;
    FUN_0089120c();
  }
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = (short ***)((uint)local_4c[0] & 0xffff0000);
  if (7 < local_1c) {
    pppsStack_f8 = local_30[0];
    pppsStack_fc = (short ***)0x5f2593;
    FUN_0089120c();
  }
LAB_005f2596:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

