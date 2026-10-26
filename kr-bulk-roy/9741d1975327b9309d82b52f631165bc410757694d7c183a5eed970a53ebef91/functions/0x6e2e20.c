
void FUN_006e2e20(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined1 auStack_dc [4];
  int local_d8 [4];
  int local_c8;
  int local_c4;
  int local_c0;
  uint local_a8;
  undefined1 local_90 [72];
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
  
  local_c = DAT_00d61f20 ^ (uint)auStack_dc;
  piVar1 = (int *)FUN_006ea4e0(local_90);
  piVar6 = local_d8;
  for (iVar4 = 0x12; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar6 = *piVar1;
    piVar1 = piVar1 + 1;
    piVar6 = piVar6 + 1;
  }
  uVar5 = (uint)(local_a8 == 0);
  local_48 = 1;
  local_40 = 1;
  local_3c = 0;
  local_30 = 0;
  local_14 = 0;
  local_44 = 2;
  local_38 = 2;
  local_2c = 2;
  local_28 = 2;
  local_24 = 2;
  local_20 = 2;
  local_1c = 2;
  local_18 = 2;
  local_10 = 2;
  local_a8 = uVar5;
  if (DAT_00fba7cc == 0) {
    iVar4 = FUN_00891268(0x1380);
    if (iVar4 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar4 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  iVar4 = *(int *)(iVar4 + 0x340);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (0 < iVar4) {
    if (DAT_00fba7cc == 0) {
      iVar4 = FUN_00891268(0x1380);
      if (iVar4 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    iVar4 = DAT_00fba7cc;
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    iVar4 = *(int *)(iVar4 + 0x340);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    local_d8[2] = (iVar4 == 0x10) + 0x16;
    if (DAT_00fba7cc == 0) {
      iVar4 = FUN_00891268(0x1380);
      if (iVar4 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    iVar4 = DAT_00fba7cc;
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    iVar4 = *(int *)(iVar4 + 0x340);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    local_c0 = (iVar4 == 0x10) + 0x16;
    local_3c = 2;
    local_30 = 2;
  }
  if (uVar5 == 0) {
    if (DAT_00fba7cc == 0) {
      iVar4 = FUN_00891268(0x1380);
      if (iVar4 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    iVar4 = DAT_00fba7cc;
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    iVar4 = *(int *)(iVar4 + 0x174);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
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
    iVar2 = *(int *)(iVar2 + 0x178);
  }
  else {
    if (DAT_00fba7cc == 0) {
      iVar4 = FUN_00891268(0x1380);
      if (iVar4 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    iVar4 = DAT_00fba7cc;
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    iVar4 = *(int *)(iVar4 + 0x17c);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
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
    iVar2 = *(int *)(iVar2 + 0x180);
  }
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if ((iVar4 == 0) || (iVar2 == 0)) {
    local_34 = 0;
  }
  else {
    local_34 = 2;
    local_c8 = iVar4;
    local_c4 = iVar2;
  }
  iVar4 = FUN_006e3830(local_d8,local_d8);
  if (((-1 < iVar4) && (iVar4 = FUN_006e4f90(local_d8,0,0,0,0), iVar4 < 0)) &&
     (iVar4 != -0x7fffbffc)) {
    local_a8 = (uint)(local_a8 == 0);
    if (local_a8 == 0) {
      uVar3 = FUN_006df6d0();
      iVar4 = FUN_006df460(uVar3);
      uVar3 = FUN_006df6d0();
      iVar2 = FUN_006df4a0(uVar3);
    }
    else {
      uVar3 = FUN_006df6d0();
      iVar4 = FUN_006df4e0(uVar3);
      uVar3 = FUN_006df6d0();
      iVar2 = FUN_006df520(uVar3);
    }
    if ((iVar4 == 0) || (iVar2 == 0)) {
      local_34 = 0;
    }
    else {
      local_34 = 2;
      local_c8 = iVar4;
      local_c4 = iVar2;
    }
    FUN_006e3830(local_d8,local_d8);
    iVar4 = FUN_006e4f90(local_d8,0,0,0,0);
    if (iVar4 < 0) {
      FUN_006e9ae0();
    }
  }
  __security_check_cookie(local_c ^ (uint)auStack_dc);
  return;
}

