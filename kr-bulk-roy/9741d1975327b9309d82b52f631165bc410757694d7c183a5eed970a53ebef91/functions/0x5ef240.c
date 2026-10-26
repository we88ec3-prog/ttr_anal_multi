
void FUN_005ef240(void)

{
  short sVar1;
  int iVar2;
  code *pcVar3;
  short *psVar4;
  short *****pppppsVar5;
  int in_ECX;
  short *psVar6;
  short *****pppppsVar7;
  undefined4 uVar8;
  undefined4 local_70;
  undefined4 local_60;
  uint local_5c;
  int local_54;
  undefined4 local_50;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  short ****local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00946fc6;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (short ****)((uint)local_30[0] & 0xffff0000);
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = local_4c[0] & 0xffff0000;
  local_8 = 1;
  FUN_005e2440(local_4c);
  FUN_005e2510(in_ECX,local_4c);
  iVar2 = *(int *)(in_ECX + 0x184);
  if (iVar2 == 0) goto LAB_005ef2fa;
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
    goto switchD_005ef2c2_caseD_5;
  case 0x15:
    uVar8 = *(undefined4 *)(iVar2 + 4);
  }
  FUN_005e4b70(local_4c,uVar8);
switchD_005ef2c2_caseD_5:
  FUN_005e3bc0(local_4c,iVar2);
  FUN_005e4340(local_4c,iVar2);
LAB_005ef2fa:
  FUN_004041f0(local_4c,0,0xffffffff);
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
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 2;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  local_50 = 0x1a2;
  FUN_005740f0(&local_50);
  if (local_54 != DAT_00fe5ac8) {
    psVar6 = (short *)(local_54 + 0x10);
    if (7 < *(uint *)(local_54 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    psVar4 = psVar6;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00404300(psVar6,(int)psVar4 - (int)(psVar6 + 1) >> 1);
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
    FUN_005e2770(local_30);
    FUN_005e8c10(local_30,*(undefined4 *)(in_ECX + 0x184));
    pppppsVar7 = (short *****)local_30[0];
    if (local_1c < 8) {
      pppppsVar7 = local_30;
    }
    local_70 = (uint)local_70._2_2_ << 0x10;
    local_5c = 7;
    local_60 = 0;
    pppppsVar5 = pppppsVar7;
    do {
      sVar1 = *(short *)pppppsVar5;
      pppppsVar5 = (short *****)((int)pppppsVar5 + 2);
    } while (sVar1 != 0);
    FUN_00402160(pppppsVar7,(int)pppppsVar5 - (int)((int)pppppsVar7 + 2) >> 1);
    iVar2 = *(int *)(in_ECX + 0x198);
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_007578f0();
    FUN_00759ed0(iVar2 + 0xe8,&local_70,0x7b,0x7d);
    if (7 < local_5c) {
      FUN_0089120c(local_70);
    }
    if (7 < local_38) {
      FUN_0089120c(local_4c[0]);
    }
    local_38 = 7;
    local_3c = 0;
    local_4c[0] = local_4c[0] & 0xffff0000;
    if (7 < local_1c) {
      FUN_0089120c(local_30[0]);
    }
    ExceptionList = local_10;
    __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
    return;
  }
  pcVar3 = (code *)swi(3);
  (*pcVar3)();
  return;
}

