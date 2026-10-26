
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e71f0(char param_1,char param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  uint local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  if (DAT_00fba7cc == 0) {
    iVar1 = FUN_00891268(0x1380);
    if (iVar1 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar1 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  iVar1 = *(int *)(iVar1 + 0x324);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  _param_1 = (uint)(param_1 != '\0') * 2 + -1 + iVar1;
  if (_param_1 < 0) {
    _param_1 = 0;
  }
  if (DAT_00fba7cc == 0) {
    iVar1 = FUN_00891268(0x1380);
    if (iVar1 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar1 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar3 = DAT_00d63d09 != '\0';
  *(int *)(iVar1 + 0x324) = _param_1;
  if (bVar3) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (DAT_00fba7cc == 0) {
    iVar1 = FUN_00891268(0x1380);
    if (iVar1 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar1 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  iVar1 = *(int *)(iVar1 + 800);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  iVar1 = (uint)(param_2 != '\0') * 2 + -1 + iVar1;
  if (iVar1 < 0) {
    iVar1 = 0;
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
  bVar3 = DAT_00d63d09 != '\0';
  *(int *)(iVar2 + 800) = iVar1;
  if (bVar3) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (_param_1 < 1) {
    if ((_DAT_00fe4b40 & 1) == 0) {
      _DAT_00fe4b40 = _DAT_00fe4b40 | 1;
      FUN_006eb420();
    }
    FUN_006eb3c0(&local_14);
    if (DAT_00fe4b19 != '\0') {
      bVar3 = CARRY4(_DAT_00fe4b38,local_14 - DAT_00fe4b28);
      _DAT_00fe4b38 = _DAT_00fe4b38 + (local_14 - DAT_00fe4b28);
      _DAT_00fe4b3c =
           _DAT_00fe4b3c + ((local_10 - DAT_00fe4b2c) - (uint)(local_14 < DAT_00fe4b28)) +
           (uint)bVar3;
    }
    DAT_00fe4b28 = 0;
    DAT_00fe4b2c = 0;
    _DAT_00fe4b30 = local_14;
    _DAT_00fe4b34 = local_10;
    DAT_00fe4b19 = '\0';
  }
  else {
    if ((_DAT_00fe4b40 & 1) == 0) {
      _DAT_00fe4b40 = _DAT_00fe4b40 | 1;
      FUN_006eb420();
    }
    if (DAT_00fe4b19 == '\0') {
      FUN_006eb3c0(&local_c);
      DAT_00fe4b28 = local_c;
      DAT_00fe4b2c = local_8;
      _DAT_00fe4b30 = local_c;
      _DAT_00fe4b34 = local_8;
      DAT_00fe4b19 = '\x01';
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
  iVar2 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar3 = DAT_00d63d09 != '\0';
  *(bool *)(iVar2 + 0x31c) = 0 < iVar1;
  if (bVar3) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (DAT_00fba7cc == 0) {
    iVar1 = FUN_00891268(0x1380);
    if (iVar1 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar1 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar3 = DAT_00d63d09 != '\0';
  *(bool *)(iVar1 + 0x31b) = 0 < _param_1;
  if (bVar3) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  return;
}

