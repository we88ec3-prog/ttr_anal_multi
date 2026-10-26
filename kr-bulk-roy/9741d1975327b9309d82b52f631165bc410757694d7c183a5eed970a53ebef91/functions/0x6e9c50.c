
void FUN_006e9c50(char param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  undefined4 uVar6;
  bool bVar7;
  
  piVar2 = (int *)FUN_006dfbe0();
  if (piVar2 != (int *)0x0) {
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
    bVar7 = DAT_00d63d09 != '\0';
    *(undefined1 *)(iVar3 + 0x318) = 1;
    if (bVar7) {
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
    cVar1 = *(char *)(iVar4 + 0x317);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      iVar3 = DAT_00fba7cc;
    }
    if (cVar1 == '\x01') {
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
      pcVar5 = (code *)FUN_006e14a0(iVar3);
      if (pcVar5 != (code *)0x0) {
        uVar6 = FUN_006df6d0();
        uVar6 = FUN_006e16a0(uVar6);
        (*pcVar5)(uVar6);
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
      bVar7 = DAT_00d63d09 != '\0';
      *(undefined1 *)(iVar3 + 0x317) = 0;
      if (bVar7) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      }
      FUN_006eb5e0();
      FUN_006eb7d0();
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
    iVar4 = iVar3;
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      iVar4 = DAT_00fba7cc;
    }
    cVar1 = *(char *)(iVar3 + 0x316);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      iVar4 = DAT_00fba7cc;
    }
    if (cVar1 == '\x01') {
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
      pcVar5 = (code *)FUN_006e14e0(iVar4);
      if (pcVar5 != (code *)0x0) {
        uVar6 = FUN_006df6d0();
        uVar6 = FUN_006e16e0(uVar6);
        (*pcVar5)(uVar6);
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
      bVar7 = DAT_00d63d09 != '\0';
      *(undefined1 *)(iVar3 + 0x316) = 0;
      if (bVar7) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      }
      FUN_006eb5e0();
      FUN_006eb8b0();
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
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    bVar7 = DAT_00d63d09 != '\0';
    *(undefined1 *)(iVar4 + 0x318) = 0;
    if (bVar7) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    iVar3 = (**(code **)(*piVar2 + 8))(piVar2);
    if (iVar3 != 0) {
      FID_conflict__wprintf("notReleasedCount: %d\n",iVar3);
      FUN_006ea570(0x80040904);
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
    *(undefined4 *)(iVar3 + 4) = 0;
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    if (param_1 != '\0') {
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
      iVar3 = *(int *)(iVar3 + 0xc);
      if (DAT_00d63d09 != '\0') {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      }
      if (iVar3 != 0) {
        FUN_0089120c(iVar3);
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
      *(undefined4 *)(iVar3 + 0xc) = 0;
      if (DAT_00d63d09 != '\0') {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      }
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
    if ((DAT_00d63d09 != '\0') &&
       (EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8), DAT_00d63d09 != '\0')) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    *(undefined4 *)(iVar3 + 0x10) = 0;
    *(undefined4 *)(iVar3 + 0x14) = 0;
    *(undefined4 *)(iVar3 + 0x18) = 0;
    *(undefined4 *)(iVar3 + 0x1c) = 0;
    *(undefined4 *)(iVar3 + 0x20) = 0;
    *(undefined4 *)(iVar3 + 0x24) = 0;
    *(undefined4 *)(iVar3 + 0x28) = 0;
    *(undefined4 *)(iVar3 + 0x2c) = 0;
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
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    _memset((void *)(iVar3 + 0x30),0,0x130);
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
    bVar7 = DAT_00d63d09 != '\0';
    *(undefined1 *)(iVar3 + 0x312) = 0;
    if (bVar7) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
  }
  return;
}

