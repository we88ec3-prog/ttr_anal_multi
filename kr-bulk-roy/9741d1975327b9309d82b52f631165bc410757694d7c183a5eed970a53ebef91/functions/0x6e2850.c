
void FUN_006e2850(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  undefined4 local_90;
  undefined4 local_8c;
  int local_88;
  uint local_84;
  undefined4 local_80;
  undefined4 local_7c;
  int local_78;
  undefined4 local_60;
  undefined4 local_58;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (DAT_00fba7cc == 0) {
    iVar2 = FUN_00891268(0x1380);
    if (iVar2 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar2 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  cVar1 = *(char *)(iVar2 + 0x318);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (cVar1 != '\0') {
LAB_006e28ce:
    __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
    return;
  }
  if (DAT_00fba7cc == 0) {
    iVar2 = FUN_00891268(0x1380);
    if (iVar2 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar2 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  iVar3 = DAT_00fba7cc;
  bVar5 = DAT_00d63d09 != '\0';
  *(undefined4 *)(iVar2 + 0x35c) = param_3;
  if (bVar5) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar3 = DAT_00fba7cc;
  }
  if (iVar3 == 0) {
    iVar2 = FUN_00891268(0x1380);
    if (iVar2 == 0) {
      iVar3 = 0;
      DAT_00fba7cc = iVar3;
    }
    else {
      iVar3 = FUN_006df3d0();
      DAT_00fba7cc = iVar3;
    }
  }
  iVar2 = iVar3;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar2 = DAT_00fba7cc;
  }
  bVar5 = DAT_00d63d09 != '\0';
  *(undefined4 *)(iVar3 + 0x360) = param_4;
  if (bVar5) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar2 = DAT_00fba7cc;
  }
  if (iVar2 == 0) {
    iVar2 = FUN_00891268(0x1380);
    if (iVar2 == 0) {
      iVar2 = 0;
      DAT_00fba7cc = iVar2;
    }
    else {
      iVar2 = FUN_006df3d0();
      DAT_00fba7cc = iVar2;
    }
  }
  iVar3 = iVar2;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar3 = DAT_00fba7cc;
  }
  bVar5 = DAT_00d63d09 != '\0';
  *(undefined4 *)(iVar2 + 0x38c) = param_5;
  if (bVar5) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar3 = DAT_00fba7cc;
  }
  if (iVar3 == 0) {
    iVar2 = FUN_00891268(0x1380);
    if (iVar2 == 0) {
      iVar3 = 0;
      DAT_00fba7cc = iVar3;
    }
    else {
      iVar3 = FUN_006df3d0();
      DAT_00fba7cc = iVar3;
    }
  }
  iVar2 = iVar3;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar2 = DAT_00fba7cc;
  }
  bVar5 = DAT_00d63d09 != '\0';
  *(undefined4 *)(iVar3 + 0x390) = param_5;
  if (bVar5) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar2 = DAT_00fba7cc;
  }
  if (iVar2 == 0) {
    iVar2 = FUN_00891268(0x1380);
    if (iVar2 == 0) {
      iVar2 = 0;
      DAT_00fba7cc = iVar2;
    }
    else {
      iVar2 = FUN_006df3d0();
      DAT_00fba7cc = iVar2;
    }
  }
  iVar3 = iVar2;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar3 = DAT_00fba7cc;
  }
  bVar5 = DAT_00d63d09 != '\0';
  *(undefined1 *)(iVar2 + 0x315) = 1;
  if (bVar5) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar3 = DAT_00fba7cc;
  }
  if (iVar3 == 0) {
    iVar2 = FUN_00891268(0x1380);
    if (iVar2 == 0) {
      iVar3 = 0;
      DAT_00fba7cc = iVar3;
    }
    else {
      iVar3 = FUN_006df3d0();
      DAT_00fba7cc = iVar3;
    }
  }
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  cVar1 = *(char *)(iVar3 + 0x311);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (cVar1 == '\0') goto LAB_006e28ce;
  FUN_006e3660(1);
  local_48 = 1;
  local_40 = 1;
  local_3c = 0;
  local_38 = 0;
  local_34 = 2;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  _memset(&local_90,0,0x48);
  local_90 = 0;
  local_60 = 1;
  local_80 = param_1;
  local_7c = param_2;
  if (DAT_00fba7cc == 0) {
    iVar2 = FUN_00891268(0x1380);
    if (iVar2 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar2 = FUN_006e11a0(DAT_00fba7cc);
  if (iVar2 != -1) {
    uVar4 = FUN_006df6d0();
    local_90 = FUN_006e11a0(uVar4);
  }
  if (DAT_00fba7cc == 0) {
    iVar2 = FUN_00891268(0x1380);
    if (iVar2 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar2 = FUN_006e12e0(DAT_00fba7cc);
  if (0 < iVar2) {
    uVar4 = FUN_006df6d0();
    iVar2 = FUN_006e12e0(uVar4);
    local_88 = 0x17 - (uint)(iVar2 != 0x10);
    uVar4 = FUN_006df6d0();
    iVar2 = FUN_006e12e0(uVar4);
    local_78 = 0x17 - (uint)(iVar2 != 0x10);
    local_3c = 2;
    local_30 = 2;
  }
  if (DAT_00fba7cc == 0) {
    iVar2 = FUN_00891268(0x1380);
    if (iVar2 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  cVar1 = FUN_006e1220(DAT_00fba7cc);
  if (cVar1 != '\0') {
    local_60 = 0;
    uVar4 = FUN_006df6d0();
    iVar2 = FUN_006e1260(uVar4);
    if (iVar2 < 1) {
      local_34 = 0;
    }
    else {
      uVar4 = FUN_006df6d0();
      local_80 = FUN_006e1260(uVar4);
      uVar4 = FUN_006df6d0();
      local_7c = FUN_006e12a0(uVar4);
      uVar4 = FUN_006df6d0();
      iVar2 = FUN_006e12e0(uVar4);
      local_88 = 0x17 - (uint)(iVar2 != 0x10);
      uVar4 = FUN_006df6d0();
      iVar2 = FUN_006e12e0(uVar4);
      local_78 = 0x17 - (uint)(iVar2 != 0x10);
      local_34 = 2;
    }
  }
  if (DAT_00fba7cc == 0) {
    iVar2 = FUN_00891268(0x1380);
    if (iVar2 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  cVar1 = FUN_006e11e0(DAT_00fba7cc);
  if (cVar1 != '\0') {
    local_60 = 1;
  }
  local_8c = 1;
  local_44 = 1;
  if (DAT_00fba7cc == 0) {
    iVar2 = FUN_00891268(0x1380);
    if (iVar2 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  cVar1 = FUN_006e1320(DAT_00fba7cc);
  if (cVar1 == '\0') {
    uVar4 = FUN_006df6d0();
    cVar1 = FUN_006e1360(uVar4);
    if (cVar1 != '\0') {
      local_84 = 0x40;
      goto LAB_006e2d59;
    }
    uVar4 = FUN_006df6d0();
    cVar1 = FUN_006e13a0(uVar4);
    if (cVar1 != '\0') {
      local_84 = 0x20;
      goto LAB_006e2d59;
    }
  }
  else {
    local_84 = 0x50;
LAB_006e2d59:
    local_38 = 1;
  }
  if (DAT_00fba7cc == 0) {
    iVar2 = FUN_00891268(0x1380);
    if (iVar2 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar2 = FUN_006e13e0(DAT_00fba7cc);
  if (iVar2 == 0) {
    local_4c = 0x80000000;
  }
  else {
    uVar4 = FUN_006df6d0();
    iVar2 = FUN_006e13e0(uVar4);
    if (iVar2 != 1) goto LAB_006e2dac;
    local_4c = 0;
  }
  local_10 = 1;
LAB_006e2dac:
  local_58 = 0x4b;
  local_1c = 1;
  iVar2 = FUN_006e3830(&local_90,&local_90);
  if (-1 < iVar2) {
    local_84 = local_84 | 4;
    FUN_006e4f90(&local_90,0,0,1,0);
    __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
    return;
  }
  FUN_006ea570(iVar2);
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

