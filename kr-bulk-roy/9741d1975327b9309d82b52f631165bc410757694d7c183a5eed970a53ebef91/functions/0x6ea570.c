
void FUN_006ea570(undefined4 param_1)

{
  char cVar1;
  WCHAR WVar2;
  bool bVar3;
  int iVar4;
  LPCWSTR pWVar5;
  short *psVar6;
  HWND pHVar7;
  int iVar8;
  undefined4 uVar9;
  bool bVar10;
  LPCWSTR lpText;
  LPCWSTR pWVar11;
  UINT uType;
  
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
  lpText = (LPCWSTR)(iVar4 + 0xf4c);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar3 = true;
  switch(param_1) {
  case 0x80040901:
    uVar9 = 2;
    iVar4 = 0x200;
    pWVar11 = lpText;
    do {
      pWVar5 = pWVar11;
      if ((iVar4 == -0x7ffffdfe) ||
         (WVar2 = *(WCHAR *)(((int)&DAT_00c414c0 - (int)lpText) + (int)pWVar5), WVar2 == L'\0')) {
        if (iVar4 == 0) {
          pWVar5 = pWVar5 + -1;
        }
        break;
      }
      *pWVar5 = WVar2;
      iVar4 = iVar4 + -1;
      pWVar11 = pWVar5 + 1;
    } while (iVar4 != 0);
    break;
  case 0x80040902:
    uVar9 = 3;
    iVar4 = GetSystemMetrics(0x1000);
    iVar8 = 0x200;
    if (iVar4 == 0) {
      uVar9 = 3;
      pWVar11 = lpText;
      do {
        pWVar5 = pWVar11;
        if ((iVar8 == -0x7ffffdfe) ||
           (WVar2 = *(WCHAR *)(((int)&DAT_00c416b4 - (int)lpText) + (int)pWVar5), WVar2 == L'\0')) {
          if (iVar8 == 0) {
            pWVar5 = pWVar5 + -1;
          }
          break;
        }
        *pWVar5 = WVar2;
        iVar8 = iVar8 + -1;
        pWVar11 = pWVar5 + 1;
      } while (iVar8 != 0);
    }
    else {
      pWVar11 = lpText;
      do {
        pWVar5 = pWVar11;
        if ((iVar8 == -0x7ffffdfe) ||
           (WVar2 = *(WCHAR *)(((int)&DAT_00c41674 - (int)lpText) + (int)pWVar5), WVar2 == L'\0')) {
          if (iVar8 == 0) {
            pWVar5 = pWVar5 + -1;
          }
          break;
        }
        *pWVar5 = WVar2;
        iVar8 = iVar8 + -1;
        pWVar11 = pWVar5 + 1;
      } while (iVar8 != 0);
    }
    break;
  default:
    iVar4 = 0x200;
    pWVar5 = lpText;
    do {
      if ((iVar4 == -0x7ffffdfe) ||
         (WVar2 = *(WCHAR *)(((int)&DAT_00c416ec - (int)lpText) + (int)pWVar5), WVar2 == L'\0')) {
        if (iVar4 != 0) goto LAB_006ea8a5;
        break;
      }
      *pWVar5 = WVar2;
      pWVar5 = pWVar5 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    pWVar5 = pWVar5 + -1;
LAB_006ea8a5:
    bVar3 = false;
    uVar9 = 1;
    break;
  case 0x80040904:
    iVar4 = 0x200;
    uVar9 = 5;
    pWVar11 = lpText;
    do {
      pWVar5 = pWVar11;
      if ((iVar4 == -0x7ffffdfe) ||
         (WVar2 = *(WCHAR *)((int)pWVar5 + ((int)&DAT_00c41528 - (int)lpText)), WVar2 == L'\0')) {
        if (iVar4 == 0) {
          pWVar5 = pWVar5 + -1;
        }
        break;
      }
      *pWVar5 = WVar2;
      iVar4 = iVar4 + -1;
      pWVar11 = pWVar5 + 1;
    } while (iVar4 != 0);
    break;
  case 0x80040905:
    uVar9 = 6;
    iVar4 = 0x200;
    pWVar11 = lpText;
    do {
      pWVar5 = pWVar11;
      if ((iVar4 == -0x7ffffdfe) ||
         (WVar2 = *(WCHAR *)((int)pWVar5 + ((int)&DAT_00c41594 - (int)lpText)), WVar2 == L'\0')) {
        if (iVar4 == 0) {
          pWVar5 = pWVar5 + -1;
        }
        break;
      }
      *pWVar5 = WVar2;
      iVar4 = iVar4 + -1;
      pWVar11 = pWVar5 + 1;
    } while (iVar4 != 0);
    break;
  case 0x80040906:
    iVar4 = 0x200;
    uVar9 = 7;
    pWVar11 = lpText;
    do {
      pWVar5 = pWVar11;
      if ((iVar4 == -0x7ffffdfe) ||
         (WVar2 = *(WCHAR *)((int)pWVar5 + ((int)&DAT_00c415c8 - (int)lpText)), WVar2 == L'\0')) {
        if (iVar4 == 0) {
          pWVar5 = pWVar5 + -1;
        }
        break;
      }
      *pWVar5 = WVar2;
      iVar4 = iVar4 + -1;
      pWVar11 = pWVar5 + 1;
    } while (iVar4 != 0);
    break;
  case 0x80040907:
    uVar9 = 8;
    iVar4 = 0x200;
    pWVar11 = lpText;
    do {
      pWVar5 = pWVar11;
      if ((iVar4 == -0x7ffffdfe) ||
         (WVar2 = *(WCHAR *)((int)pWVar5 + ((int)&DAT_00c415fc - (int)lpText)), WVar2 == L'\0')) {
        if (iVar4 == 0) {
          pWVar5 = pWVar5 + -1;
        }
        break;
      }
      *pWVar5 = WVar2;
      iVar4 = iVar4 + -1;
      pWVar11 = pWVar5 + 1;
    } while (iVar4 != 0);
    break;
  case 0x80040908:
    iVar4 = 0x200;
    uVar9 = 9;
    pWVar11 = lpText;
    do {
      pWVar5 = pWVar11;
      if ((iVar4 == -0x7ffffdfe) ||
         (WVar2 = *(WCHAR *)(((int)&DAT_00c41638 - (int)lpText) + (int)pWVar5), WVar2 == L'\0')) {
        if (iVar4 == 0) {
          pWVar5 = pWVar5 + -1;
        }
        break;
      }
      *pWVar5 = WVar2;
      iVar4 = iVar4 + -1;
      pWVar11 = pWVar5 + 1;
    } while (iVar4 != 0);
    break;
  case 0x80040909:
    uVar9 = 10;
    iVar4 = 0x200;
    pWVar11 = lpText;
    do {
      pWVar5 = pWVar11;
      if ((iVar4 == -0x7ffffdfe) ||
         (WVar2 = *(WCHAR *)((int)pWVar5 + ((int)&DAT_00c414f0 - (int)lpText)), WVar2 == L'\0')) {
        if (iVar4 == 0) {
          pWVar5 = pWVar5 + -1;
        }
        break;
      }
      *pWVar5 = WVar2;
      iVar4 = iVar4 + -1;
      pWVar11 = pWVar5 + 1;
    } while (iVar4 != 0);
  }
  bVar10 = DAT_00fba7cc == 0;
  *pWVar5 = L'\0';
  if (bVar10) {
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
  bVar10 = DAT_00d63d09 != '\0';
  *(undefined4 *)(iVar4 + 0x30c) = uVar9;
  if (bVar10) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
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
  cVar1 = *(char *)(iVar4 + 0x2fd);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if ((bVar3) && (cVar1 != '\0')) {
    psVar6 = (short *)FUN_006e0010();
    uType = 0x10;
    if (*psVar6 == 0) {
      pWVar11 = L"에러";
      pHVar7 = (HWND)FUN_006dfd60();
      MessageBoxW(pHVar7,lpText,pWVar11,uType);
      return;
    }
    pWVar11 = (LPCWSTR)FUN_006e0010();
    pHVar7 = (HWND)FUN_006dfd60();
    MessageBoxW(pHVar7,lpText,pWVar11,uType);
  }
  return;
}

