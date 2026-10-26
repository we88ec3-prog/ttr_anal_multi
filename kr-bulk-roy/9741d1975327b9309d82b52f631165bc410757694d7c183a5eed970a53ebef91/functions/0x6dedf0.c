
void FUN_006dedf0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
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
  iVar2 = DAT_00fba7cc;
  bVar3 = DAT_00d63d09 != '\0';
  *(undefined4 *)(iVar1 + 0x338) = param_1;
  if (bVar3) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar2 = DAT_00fba7cc;
  }
  if (iVar2 == 0) {
    iVar1 = FUN_00891268(0x1380);
    if (iVar1 == 0) {
      iVar2 = 0;
      DAT_00fba7cc = iVar2;
    }
    else {
      iVar2 = FUN_006df3d0();
      DAT_00fba7cc = iVar2;
    }
  }
  iVar1 = iVar2;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar1 = DAT_00fba7cc;
  }
  bVar3 = DAT_00d63d09 != '\0';
  *(undefined4 *)(iVar2 + 0x33c) = param_2;
  if (bVar3) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar1 = DAT_00fba7cc;
  }
  if (iVar1 == 0) {
    iVar1 = FUN_00891268(0x1380);
    if (iVar1 == 0) {
      iVar1 = 0;
      DAT_00fba7cc = iVar1;
    }
    else {
      iVar1 = FUN_006df3d0();
      DAT_00fba7cc = iVar1;
    }
  }
  iVar2 = iVar1;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar2 = DAT_00fba7cc;
  }
  bVar3 = DAT_00d63d09 != '\0';
  *(undefined4 *)(iVar1 + 0x340) = param_3;
  if (bVar3) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar2 = DAT_00fba7cc;
  }
  if (iVar2 == 0) {
    iVar1 = FUN_00891268(0x1380);
    if (iVar1 == 0) {
      iVar2 = 0;
      DAT_00fba7cc = iVar2;
    }
    else {
      iVar2 = FUN_006df3d0();
      DAT_00fba7cc = iVar2;
    }
  }
  iVar1 = iVar2;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar1 = DAT_00fba7cc;
  }
  bVar3 = DAT_00d63d09 != '\0';
  *(undefined4 *)(iVar2 + 0x17c) = param_1;
  if (bVar3) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar1 = DAT_00fba7cc;
  }
  if (iVar1 == 0) {
    iVar1 = FUN_00891268(0x1380);
    if (iVar1 == 0) {
      iVar1 = 0;
      DAT_00fba7cc = iVar1;
    }
    else {
      iVar1 = FUN_006df3d0();
      DAT_00fba7cc = iVar1;
    }
  }
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar3 = DAT_00d63d09 != '\0';
  *(undefined4 *)(iVar1 + 0x180) = param_2;
  if (bVar3) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  return;
}

