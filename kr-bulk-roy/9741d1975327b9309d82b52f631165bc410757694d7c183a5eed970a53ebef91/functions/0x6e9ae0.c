
void FUN_006e9ae0(void)

{
  undefined4 *puVar1;
  HWND hWnd;
  int iVar2;
  int *piVar3;
  bool bVar4;
  
  hWnd = (HWND)FUN_006dfd60();
  if ((hWnd != (HWND)0x0) && (DAT_00fba7d4 != 0)) {
    PostMessageW(hWnd,0x10,100,100);
    FUN_006e7a60();
  }
  if (DAT_00fba7cc == (undefined4 *)0x0) {
    iVar2 = FUN_00891268(0x1380);
    if (iVar2 == 0) {
      DAT_00fba7cc = (undefined4 *)0x0;
    }
    else {
      DAT_00fba7cc = (undefined4 *)FUN_006df3d0();
    }
  }
  puVar1 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar4 = DAT_00d63d09 != '\0';
  puVar1[0xc3] = 0;
  if (bVar4) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  FUN_006e9c50(1);
  FUN_006e5e10(1);
  if (DAT_00fba7cc == (undefined4 *)0x0) {
    iVar2 = FUN_00891268(0x1380);
    if (iVar2 == 0) {
      DAT_00fba7cc = (undefined4 *)0x0;
    }
    else {
      DAT_00fba7cc = (undefined4 *)FUN_006df3d0();
    }
  }
  puVar1 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar4 = DAT_00d63d09 != '\0';
  puVar1[2] = 0;
  if (bVar4) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  piVar3 = (int *)FUN_006dfb80();
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
  }
  if (DAT_00fba7cc == (undefined4 *)0x0) {
    iVar2 = FUN_00891268(0x1380);
    if (iVar2 == 0) {
      DAT_00fba7cc = (undefined4 *)0x0;
    }
    else {
      DAT_00fba7cc = (undefined4 *)FUN_006df3d0();
    }
  }
  puVar1 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar4 = DAT_00d63d09 != '\0';
  *puVar1 = 0;
  if (bVar4) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  DestroyIcon(DAT_00fba7d0);
  return;
}

