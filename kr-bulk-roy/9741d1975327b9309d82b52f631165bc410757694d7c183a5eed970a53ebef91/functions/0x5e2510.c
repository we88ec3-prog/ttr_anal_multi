
void FUN_005e2510(int param_1,undefined4 param_2)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  short *psVar7;
  undefined4 uVar8;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091664e;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (*(int *)(param_1 + 0x180) == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x188) == 0) {
    local_14 = 0;
  }
  else {
    local_14 = (uint)(*(char *)(*(int *)(param_1 + 0x188) + 0x15) != '\0');
  }
  ExceptionList = &local_10;
  iVar4 = FUN_0051bf00(*(int *)(param_1 + 0x180));
  iVar5 = FUN_0051bfc0(uVar3);
  if (*(char *)(param_1 + 0x179) != '\0') {
    iVar5 = 1;
  }
  if ((*(int *)(param_1 + 0x174) != 0) && (*(char *)(param_1 + 0x179) != '\0')) {
    local_14 = 1;
  }
  if (((iVar4 == 0) && (iVar5 == 0)) && (local_14 == 0)) {
    ExceptionList = local_10;
    return;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x174;
  FUN_005740f0(&local_18);
  if (local_1c == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psVar7 = (short *)(local_1c + 0x10);
  if (7 < *(uint *)(local_1c + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  psVar6 = psVar7;
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  FUN_00404300(psVar7,(int)psVar6 - (int)(psVar7 + 1) >> 1);
  if (((iVar4 == 0) || (iVar5 == 0)) && (local_14 == 0)) {
    if (iVar4 == 0) {
      if (iVar5 == 0) goto LAB_005e26d9;
      uVar8 = 0x177;
      FUN_00585620(0x177);
      FUN_00585330(uVar8);
    }
    else {
      uVar8 = 0x176;
      FUN_00585620(0x176);
      FUN_00585330(uVar8);
    }
    FUN_00404420(param_2);
  }
  else {
    local_1c = 0x175;
    iVar4 = FUN_00585620();
    FUN_005740f0(&local_1c);
    if (local_18 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar7 = (short *)(local_18 + 0x10);
    if (7 < *(uint *)(local_18 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    psVar6 = psVar7;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00404300(psVar7,(int)psVar6 - (int)(psVar7 + 1) >> 1);
  }
LAB_005e26d9:
  FUN_00404300(L"<br>",4);
  if (*(int *)(*(int *)(param_1 + 0x184) + 8) == 0x17) {
    param_2 = 0x178;
    iVar4 = FUN_00585620();
    FUN_005740f0(&param_2);
    if (param_1 == *(int *)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar7 = (short *)(param_1 + 0x10);
    if (7 < *(uint *)(param_1 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    psVar6 = psVar7;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00404300(psVar7,(int)psVar6 - (int)(psVar7 + 1) >> 1);
  }
  ExceptionList = local_10;
  return;
}

