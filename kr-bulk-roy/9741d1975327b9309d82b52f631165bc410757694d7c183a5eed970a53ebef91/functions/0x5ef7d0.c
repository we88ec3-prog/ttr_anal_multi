
void FUN_005ef7d0(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  short *psVar4;
  short ****ppppsVar5;
  int in_ECX;
  short *psVar6;
  short ****ppppsVar7;
  undefined4 uVar8;
  undefined4 local_84;
  undefined4 local_74;
  uint local_70;
  uint local_68 [4];
  undefined4 local_58;
  uint local_54;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  short ***local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00946f70;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (short ***)((uint)local_30[0] & 0xffff0000);
  local_54 = 7;
  local_58 = 0;
  local_68[0] = local_68[0] & 0xffff0000;
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = local_4c[0] & 0xffff0000;
  local_8 = 2;
  local_14 = uVar3;
  FUN_005e2440(local_68);
  FUN_005e2510(in_ECX,local_68);
  switch(*(undefined4 *)(*(int *)(in_ECX + 0x184) + 8)) {
  case 9:
  case 10:
    uVar8 = 0x1a3;
    FUN_00585620(0x1a3,uVar3);
    psVar4 = (short *)FUN_00585330(uVar8);
    psVar6 = psVar4;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    goto LAB_005ef8f2;
  case 0xb:
    uVar8 = 0x1a3;
    FUN_00585620(0x1a3,uVar3);
    psVar4 = (short *)FUN_00585330(uVar8);
    psVar6 = psVar4;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00404300(psVar4,(int)psVar6 - (int)(psVar4 + 1) >> 1);
    FUN_005e4ff0(local_68);
    break;
  case 0x17:
    uVar8 = 0x1a4;
    FUN_00585620(0x1a4,uVar3);
    psVar4 = (short *)FUN_00585330(uVar8);
    psVar6 = psVar4;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
LAB_005ef8f2:
    FUN_00404300(psVar4,(int)psVar6 - (int)(psVar4 + 1) >> 1);
  }
  if (*(int *)(in_ECX + 0x184) != 0) {
    FUN_005e1c60(local_4c,*(int *)(in_ECX + 0x184));
  }
  iVar2 = *(int *)(in_ECX + 0x184);
  if (iVar2 == 0) goto LAB_005ef966;
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
    uVar8 = *(undefined4 *)(iVar2 + 4);
    break;
  default:
    goto switchD_005ef92e_caseD_5;
  case 0x15:
    uVar8 = *(undefined4 *)(iVar2 + 4);
  }
  FUN_005e4b70(local_4c,uVar8);
switchD_005ef92e_caseD_5:
  FUN_005e3bc0(local_4c,iVar2);
  FUN_005e4340(local_4c,iVar2);
LAB_005ef966:
  FUN_005e2770(local_4c);
  FUN_004041f0(local_68,0,0xffffffff);
  if (*(int *)(*(int *)(in_ECX + 0x184) + 0xc4) != 0) {
    FUN_00404300(L"<#F2F4BC>",9);
    iVar2 = *(int *)(in_ECX + 0x184);
    if (*(uint *)(iVar2 + 200) < 8) {
      psVar6 = (short *)(iVar2 + 0xb4);
    }
    else {
      psVar6 = *(short **)(iVar2 + 0xb4);
    }
    psVar4 = psVar6;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00404300(psVar6,(int)psVar4 - (int)(psVar6 + 1) >> 1);
    FUN_00404300(L"<br>",4);
  }
  if (*(int *)(*(int *)(in_ECX + 0x184) + 0xe0) != 0) {
    FUN_00404300(L"<#CCCCCC>",9);
    iVar2 = *(int *)(in_ECX + 0x184);
    if (*(uint *)(iVar2 + 0xe4) < 8) {
      psVar6 = (short *)(iVar2 + 0xd0);
    }
    else {
      psVar6 = *(short **)(iVar2 + 0xd0);
    }
    psVar4 = psVar6;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00404300(psVar6,(int)psVar4 - (int)(psVar6 + 1) >> 1);
    FUN_00404300(L"<br>",4);
  }
  FUN_004041f0(local_4c,0,0xffffffff);
  if (*(int *)(in_ECX + 0x174) == 0) {
    FUN_005e3750(local_30);
  }
  else {
    FUN_005e2870();
  }
  FUN_00404300(L"<br>",4);
  if (*(int *)(in_ECX + 0x180) != 0) {
    FUN_005e86e0(*(int *)(in_ECX + 0x180));
  }
  FUN_005e8c10(local_30,*(undefined4 *)(in_ECX + 0x184));
  ppppsVar7 = (short ****)local_30[0];
  if (local_1c < 8) {
    ppppsVar7 = local_30;
  }
  local_84 = (uint)local_84._2_2_ << 0x10;
  local_70 = 7;
  local_74 = 0;
  ppppsVar5 = ppppsVar7;
  do {
    sVar1 = *(short *)ppppsVar5;
    ppppsVar5 = (short ****)((int)ppppsVar5 + 2);
  } while (sVar1 != 0);
  FUN_00402160(ppppsVar7,(int)ppppsVar5 - (int)((int)ppppsVar7 + 2) >> 1);
  iVar2 = *(int *)(in_ECX + 0x198);
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_007578f0();
  FUN_00759ed0(iVar2 + 0xe8,&local_84,0x7b,0x7d);
  if (7 < local_70) {
    FUN_0089120c(local_84);
  }
  if (7 < local_38) {
    FUN_0089120c(local_4c[0]);
  }
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = local_4c[0] & 0xffff0000;
  if (7 < local_54) {
    FUN_0089120c(local_68[0]);
  }
  local_54 = 7;
  local_58 = 0;
  local_68[0] = local_68[0] & 0xffff0000;
  if (7 < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

