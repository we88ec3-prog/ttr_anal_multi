
void FUN_006860b0(void)

{
  short sVar1;
  code *pcVar2;
  int *piVar3;
  int iVar4;
  short *psVar5;
  undefined4 *puVar6;
  int in_ECX;
  short *psVar7;
  undefined4 local_3c;
  undefined4 local_2c;
  uint local_28;
  int *local_20;
  int local_1c;
  int local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092c8a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00755e50(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_006895a0();
  FUN_0043c570(31000);
  FUN_0043c570(0x7d64);
  FUN_00615fc0(10000);
  FUN_00615fc0(20000);
  FUN_0043c570(0x79e0);
  FUN_0043c570(0x9c4);
  local_14 = (int *)(in_ECX + 0x14c);
  FUN_00677fa0(35000);
  FUN_00615fc0(0x891c);
  FUN_00615fc0(0x8980);
  local_20 = (int *)(in_ECX + 0x158);
  FUN_00677fa0(36000);
  FUN_00615fc0(0x8d04);
  FUN_00615fc0(0x8d68);
  FUN_00689690();
  FUN_0043c570(0x7a44);
  FUN_0043c570(0x7aa8);
  (**(code **)(**(int **)(in_ECX + 300) + 0x198))(0x7987);
  *(int *)(*(int *)(in_ECX + 300) + 0x298) = in_ECX;
  if ((*(int *)(*local_14 + 0x24c) != 0) &&
     (iVar4 = *(int *)(*(int *)(*local_14 + 0x24c) + 0xcc), iVar4 != 0)) {
    FUN_006438f0(iVar4);
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_18 = 0x1e7;
  FUN_005740f0(&local_18);
  if (local_1c == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  if (*(int *)(*local_14 + 0x24c) != 0) {
    iVar4 = *(int *)(*(int *)(*local_14 + 0x24c) + 0xcc);
    if (iVar4 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_00412c70(*(undefined4 *)(iVar4 + 0xe4));
    }
    FUN_00757710();
    if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 4))(), iVar4 != 0x4b4)) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    }
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 1;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_1c = 0x1ec;
  FUN_005740f0(&local_1c);
  if (local_18 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  local_28 = 7;
  local_2c = 0;
  local_3c = (uint)local_3c._2_2_ << 0x10;
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_8 = 2;
  FUN_004026e0(&local_3c,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_28) {
    FUN_0089120c(local_3c);
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 3;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_1c = 0x1e8;
  FUN_005740f0(&local_1c);
  if (local_18 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  if (*(int *)(*local_14 + 0x24c) != 0) {
    iVar4 = *(int *)(*(int *)(*local_14 + 0x24c) + 0xcc);
    if (iVar4 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_00412c70(*(undefined4 *)(iVar4 + 0xe4));
    }
    FUN_00757710();
    if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 4))(), iVar4 != 0x4b4)) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    }
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 4;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_1c = 0x1ee;
  FUN_005740f0(&local_1c);
  if (local_18 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  local_28 = 7;
  local_2c = 0;
  local_3c = local_3c & 0xffff0000;
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_8 = 5;
  FUN_004026e0(&local_3c,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_28) {
    FUN_0089120c(local_3c);
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 6;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_1c = 0x1ea;
  FUN_005740f0(&local_1c);
  if (local_18 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  if (*(int *)(*local_14 + 0x24c) != 0) {
    iVar4 = *(int *)(*(int *)(*local_14 + 0x24c) + 0xcc);
    if (iVar4 == 0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)FUN_00412c70(*(undefined4 *)(iVar4 + 0xe4));
    }
    FUN_00757710();
    if ((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 4))(), iVar4 != 0x4b4)) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
    }
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 7;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_1c = 0x1ef;
  FUN_005740f0(&local_1c);
  if (local_18 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  local_28 = 7;
  local_2c = 0;
  local_3c = local_3c & 0xffff0000;
  psVar5 = psVar7;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  local_8 = 8;
  FUN_004026e0(&local_3c,0,0xffffffff);
  local_8 = 0xffffffff;
  if (7 < local_28) {
    FUN_0089120c(local_3c);
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 9;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_1c = 0x1e7;
  FUN_005740f0(&local_1c);
  piVar3 = local_14;
  if (local_18 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  puVar6 = (undefined4 *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    puVar6 = (undefined4 *)*puVar6;
  }
  FUN_0075cc70(*local_14,puVar6);
  iVar4 = *(int *)(*piVar3 + 0x24c);
  if (iVar4 != 0) {
    FUN_00749920(iVar4);
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 10;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_1c = 0x1e7;
  FUN_005740f0(&local_1c);
  if (local_18 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  FUN_00757710();
  (**(code **)(*(int *)*piVar3 + 200))();
  piVar3 = local_20;
  if ((*(int *)(*local_20 + 0x24c) != 0) &&
     (iVar4 = *(int *)(*(int *)(*local_20 + 0x24c) + 0xcc), iVar4 != 0)) {
    FUN_006438f0(iVar4);
  }
  FUN_00757710();
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0xb;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_20 = (int *)0x1e7;
  FUN_005740f0(&local_20);
  if (local_1c == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  puVar6 = (undefined4 *)(local_1c + 0x10);
  if (7 < *(uint *)(local_1c + 0x24)) {
    puVar6 = (undefined4 *)*puVar6;
  }
  FUN_0075cbb0(puVar6);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0xc;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_20 = (int *)0x1e9;
  FUN_005740f0(&local_20);
  if (local_1c == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  puVar6 = (undefined4 *)(local_1c + 0x10);
  if (7 < *(uint *)(local_1c + 0x24)) {
    puVar6 = (undefined4 *)*puVar6;
  }
  FUN_0075cbb0(puVar6);
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0xd;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  local_20 = (int *)0x1eb;
  FUN_005740f0(&local_20);
  if (local_1c != DAT_00fe5ac8) {
    puVar6 = (undefined4 *)(local_1c + 0x10);
    if (7 < *(uint *)(local_1c + 0x24)) {
      puVar6 = (undefined4 *)*puVar6;
    }
    FUN_0075cc70(*piVar3,puVar6);
    if (*(int *)(*piVar3 + 0x24c) != 0) {
      FUN_00749920(*(int *)(*piVar3 + 0x24c));
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 0xe;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_20 = (int *)0x1eb;
    FUN_005740f0(&local_20);
    if (local_1c != DAT_00fe5ac8) {
      FUN_00757710();
      (**(code **)(*(int *)*piVar3 + 200))();
      ExceptionList = local_10;
      return;
    }
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

