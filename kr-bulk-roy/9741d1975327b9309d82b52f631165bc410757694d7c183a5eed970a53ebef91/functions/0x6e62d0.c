
void FUN_006e62d0(undefined4 *param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
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
  iVar3 = *(int *)(iVar3 + 0x330);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  iVar4 = DAT_00fba7cc;
  if (iVar3 != -1) {
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
    uVar1 = *(undefined4 *)(iVar3 + 0x330);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    iVar4 = DAT_00fba7cc;
    *param_1 = uVar1;
  }
  if (iVar4 == 0) {
    iVar3 = FUN_00891268(0x1380);
    if (iVar3 == 0) {
      iVar4 = 0;
      DAT_00fba7cc = iVar4;
    }
    else {
      iVar4 = FUN_006df3d0();
      DAT_00fba7cc = iVar4;
    }
  }
  iVar3 = iVar4;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar3 = DAT_00fba7cc;
  }
  cVar2 = *(char *)(iVar4 + 0x335);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar3 = DAT_00fba7cc;
  }
  if (cVar2 != '\0') {
    param_1[0xc] = 0;
  }
  if (iVar3 == 0) {
    iVar3 = FUN_00891268(0x1380);
    if (iVar3 == 0) {
      iVar3 = 0;
      DAT_00fba7cc = iVar3;
    }
    else {
      iVar3 = FUN_006df3d0();
      DAT_00fba7cc = iVar3;
    }
  }
  iVar4 = iVar3;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar4 = DAT_00fba7cc;
  }
  cVar2 = *(char *)(iVar3 + 0x334);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar4 = DAT_00fba7cc;
  }
  if (cVar2 != '\0') {
    param_1[0xc] = 1;
  }
  param_1[1] = 1;
  if (iVar4 == 0) {
    iVar3 = FUN_00891268(0x1380);
    if (iVar3 == 0) {
      iVar4 = 0;
      DAT_00fba7cc = iVar4;
    }
    else {
      iVar4 = FUN_006df3d0();
      DAT_00fba7cc = iVar4;
    }
  }
  iVar3 = iVar4;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar3 = DAT_00fba7cc;
  }
  cVar2 = *(char *)(iVar4 + 0x34d);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar3 = DAT_00fba7cc;
  }
  if (cVar2 == '\0') {
    if (iVar3 == 0) {
      iVar3 = FUN_00891268(0x1380);
      if (iVar3 == 0) {
        iVar3 = 0;
        DAT_00fba7cc = iVar3;
      }
      else {
        iVar3 = FUN_006df3d0();
        DAT_00fba7cc = iVar3;
      }
    }
    iVar4 = iVar3;
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      iVar4 = DAT_00fba7cc;
    }
    cVar2 = *(char *)(iVar3 + 0x34e);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      iVar4 = DAT_00fba7cc;
    }
    if (cVar2 == '\0') {
      if (iVar4 == 0) {
        iVar3 = FUN_00891268(0x1380);
        if (iVar3 == 0) {
          iVar4 = 0;
          DAT_00fba7cc = iVar4;
        }
        else {
          iVar4 = FUN_006df3d0();
          DAT_00fba7cc = iVar4;
        }
      }
      cVar2 = FUN_006e13a0(iVar4);
      if (cVar2 != '\0') {
        param_1[3] = param_1[3] & 0xffffffaf | 0x20;
      }
      return;
    }
    param_1[3] = param_1[3] & 0xffffffcf | 0x40;
    return;
  }
  param_1[3] = param_1[3] & 0xffffffdf | 0x50;
  return;
}

