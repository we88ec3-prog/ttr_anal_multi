
void FUN_00573510(char *param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 uVar6;
  char *pcVar7;
  int *unaff_EDI;
  int local_60;
  undefined1 local_5c [4];
  undefined4 local_58;
  int local_54;
  uint local_50;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_34;
  uint local_30 [4];
  uint local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091feb3;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_58 = param_2;
  pcVar7 = param_1;
  if (0xf < *(uint *)(param_1 + 0x14)) {
    pcVar7 = *(char **)param_1;
  }
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  pcVar4 = pcVar7;
  do {
    cVar2 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar2 != '\0');
  local_14 = uVar3;
  FUN_0040b310(pcVar7);
  local_8 = 0;
  iVar1 = *unaff_EDI;
  local_60 = FUN_006cf160(local_30);
  if ((local_60 == *(int *)(iVar1 + 4)) || (cVar2 = FUN_005436a0(uVar3), cVar2 != '\0')) {
    local_54 = *(int *)(iVar1 + 4);
    piVar5 = &local_54;
  }
  else {
    piVar5 = &local_60;
  }
  iVar1 = *piVar5;
  local_8 = 0xffffffff;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0]);
  }
  if (iVar1 == *(int *)(*unaff_EDI + 4)) {
    local_54 = FUN_00891268(0x4c);
    local_8 = 1;
    if (local_54 == 0) {
      local_58 = 0;
    }
    else {
      local_58 = FUN_005727a0(local_54,local_58);
    }
    local_8 = 0xffffffff;
    uVar6 = FUN_005749e0(param_1,&local_58);
    local_8 = 2;
    iVar1 = *unaff_EDI;
    uVar6 = FUN_00574ee0(uVar6);
    FUN_00574b80(iVar1,local_5c,uVar6);
    local_8 = 0xffffffff;
    if (0xf < local_20) {
      FUN_0089120c(local_34);
    }
    if (0xf < *(uint *)(param_1 + 0x14)) {
      param_1 = *(char **)param_1;
    }
    local_3c = 0xf;
    local_40 = 0;
    local_50 = local_50 & 0xffffff00;
    pcVar7 = param_1;
    do {
      cVar2 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar2 != '\0');
    FUN_0040b310(param_1);
    local_8 = 3;
    FUN_00573ed0(unaff_EDI + 1);
    if (0xf < local_3c) {
      FUN_0089120c(local_50);
    }
    unaff_EDI[0x11] = unaff_EDI[0x11] + 1;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

