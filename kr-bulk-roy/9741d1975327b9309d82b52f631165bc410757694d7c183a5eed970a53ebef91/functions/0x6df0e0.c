
void FUN_006df0e0(char param_1)

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
  *(bool *)(iVar1 + 0x335) = param_1 == '\0';
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
  *(char *)(iVar2 + 0x334) = param_1;
  if (bVar3) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  return;
}

