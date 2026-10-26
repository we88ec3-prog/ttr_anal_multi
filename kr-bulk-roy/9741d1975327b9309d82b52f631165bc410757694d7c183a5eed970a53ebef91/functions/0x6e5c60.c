
void FUN_006e5c60(void)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
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
  iVar4 = DAT_00fba7cc;
  bVar5 = DAT_00d63d09 != '\0';
  *(undefined1 *)(iVar3 + 0x2d1) = 0;
  if (bVar5) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar4 = DAT_00fba7cc;
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
  bVar5 = DAT_00d63d09 != '\0';
  *(undefined1 *)(iVar4 + 0x2d0) = 0;
  if (bVar5) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar3 = DAT_00fba7cc;
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
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  cVar1 = *(char *)(iVar3 + 0x310);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (cVar1 != '\0') {
    cVar1 = FUN_006ea3d0();
    if (cVar1 != '\0') {
      if (DAT_00fba7cc == 0) {
        iVar3 = FUN_00891268(0x1380);
        if (iVar3 != 0) {
          DAT_00fba7cc = FUN_006df3d0();
          uVar2 = FUN_006e0b10(DAT_00fba7cc);
          FUN_006e5e10(uVar2);
          return;
        }
        DAT_00fba7cc = 0;
      }
      uVar2 = FUN_006e0b10(DAT_00fba7cc);
      FUN_006e5e10(uVar2);
      return;
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
    uVar2 = FUN_006e0ad0(DAT_00fba7cc);
    FUN_006e5e10(uVar2);
  }
  return;
}

