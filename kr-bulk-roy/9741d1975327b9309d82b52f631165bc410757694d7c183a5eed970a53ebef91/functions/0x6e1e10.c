
void FUN_006e1e10(undefined4 param_1)

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
  *(code **)(iVar1 + 0x380) = FUN_006eb2e0;
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
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar3 = DAT_00d63d09 != '\0';
  *(undefined4 *)(iVar2 + 0x3b4) = param_1;
  if (bVar3) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  return;
}

