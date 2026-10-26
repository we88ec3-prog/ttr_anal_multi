
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_006e3660(char param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  bool bVar5;
  undefined *local_8;
  
  if (DAT_00fba7cc == 0) {
    iVar3 = FUN_00891268(0x1380);
    if (iVar3 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar3 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  local_8 = *(undefined **)(iVar3 + 8);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (local_8 == (undefined *)0x0) {
    if ((_DAT_00fe4c9c & 1) == 0) {
      _DAT_00fe4c9c = _DAT_00fe4c9c | 1;
      FUN_006eba20();
      _atexit((_func_4879 *)&LAB_00bd0730);
    }
    local_8 = &DAT_00fe3650;
    if (DAT_00fba7cc == 0) {
      iVar3 = FUN_00891268(0x1380);
      if (iVar3 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    iVar3 = DAT_00fba7cc;
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    bVar5 = DAT_00d63d09 != '\0';
    *(undefined **)(iVar3 + 8) = &DAT_00fe3650;
    if (bVar5) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
  }
  else if (param_1 == '\0') {
    return local_8;
  }
  uVar4 = FUN_006dfb80();
  if (DAT_00fba7cc == 0) {
    iVar3 = FUN_00891268(0x1380);
    if (iVar3 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar3 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  uVar1 = *(undefined4 *)(iVar3 + 0x38c);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (DAT_00fba7cc == 0) {
    iVar3 = FUN_00891268(0x1380);
    if (iVar3 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar3 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  uVar2 = *(undefined4 *)(iVar3 + 0x35c);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  FUN_006ebb90(uVar4,uVar2,uVar1);
  return local_8;
}

