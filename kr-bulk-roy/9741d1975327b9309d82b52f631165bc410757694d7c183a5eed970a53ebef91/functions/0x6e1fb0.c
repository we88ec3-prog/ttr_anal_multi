
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006e1fb0(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  UINT UVar5;
  WCHAR *pWVar6;
  HMODULE hModule;
  FARPROC pFVar7;
  int *piVar8;
  bool bVar9;
  int local_24c;
  int local_248;
  int local_244;
  int local_240;
  int local_23c;
  int local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  undefined4 local_220;
  WCHAR local_21c [266];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (DAT_00fba7cc == (int *)0x0) {
    iVar3 = FUN_00891268(0x1380);
    if (iVar3 == 0) {
      DAT_00fba7cc = (int *)0x0;
    }
    else {
      DAT_00fba7cc = (int *)FUN_006df3d0();
    }
  }
  piVar1 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar9 = DAT_00d63d09 != '\0';
  *(undefined1 *)((int)piVar1 + 0x313) = 1;
  if (bVar9) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  InitCommonControls();
  local_244 = 8;
  local_240 = 0;
  SystemParametersInfoW(0x3a,8,&local_244,0);
  if (DAT_00fba7cc == (int *)0x0) {
    iVar3 = FUN_00891268(0x1380);
    if (iVar3 == 0) {
      DAT_00fba7cc = (int *)0x0;
    }
    else {
      DAT_00fba7cc = (int *)FUN_006df3d0();
    }
  }
  iVar4 = local_240;
  iVar3 = local_244;
  piVar1 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar9 = DAT_00d63d09 != '\0';
  piVar1[0xb5] = iVar3;
  piVar1[0xb6] = iVar4;
  if (bVar9) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  local_23c = 8;
  local_238 = 0;
  SystemParametersInfoW(0x34,8,&local_23c,0);
  if (DAT_00fba7cc == (int *)0x0) {
    iVar3 = FUN_00891268(0x1380);
    if (iVar3 == 0) {
      DAT_00fba7cc = (int *)0x0;
    }
    else {
      DAT_00fba7cc = (int *)FUN_006df3d0();
    }
  }
  iVar4 = local_238;
  iVar3 = local_23c;
  piVar1 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar9 = DAT_00d63d09 != '\0';
  piVar1[0xb7] = iVar3;
  piVar1[0xb8] = iVar4;
  if (bVar9) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  iVar3 = 0;
  local_234 = 0x18;
  local_230 = 0;
  local_22c = 0;
  local_228 = 0;
  local_224 = 0;
  local_220 = 0;
  SystemParametersInfoW(0x32,0x18,&local_234,0);
  if (DAT_00fba7cc == (int *)0x0) {
    iVar4 = FUN_00891268(0x1380);
    if (iVar4 == 0) {
      DAT_00fba7cc = (int *)0x0;
    }
    else {
      DAT_00fba7cc = (int *)FUN_006df3d0();
    }
  }
  FUN_006e0b90(local_234,local_230,local_22c,local_228,local_224,local_220);
  UVar5 = GetSystemDirectoryW(local_21c,0x105);
  if (UVar5 != 0) {
    iVar4 = 0x104;
    pWVar6 = local_21c;
    do {
      if (*pWVar6 == L'\0') {
        if (iVar4 != 0) {
          FUN_006eadb0(L"\\winmm.dll",0x7fffffff);
        }
        break;
      }
      pWVar6 = pWVar6 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    hModule = LoadLibraryW(local_21c);
    if (hModule != (HMODULE)0x0) {
      pFVar7 = GetProcAddress(hModule,"timeBeginPeriod");
      if (pFVar7 != (FARPROC)0x0) {
        (*pFVar7)(1);
      }
      FreeLibrary(hModule);
    }
  }
  if (DAT_00fba7cc == (int *)0x0) {
    iVar4 = FUN_00891268(0x1380);
    if (iVar4 == 0) {
      DAT_00fba7cc = (int *)0x0;
    }
    else {
      DAT_00fba7cc = (int *)FUN_006df3d0();
    }
  }
  piVar1 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  piVar8 = DAT_00fba7cc;
  bVar9 = DAT_00d63d09 != '\0';
  *(undefined1 *)((int)piVar1 + 0x2fd) = 1;
  if (bVar9) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    piVar8 = DAT_00fba7cc;
  }
  if (piVar8 == (int *)0x0) {
    iVar4 = FUN_00891268(0x1380);
    if (iVar4 == 0) {
      piVar8 = (int *)0x0;
      DAT_00fba7cc = piVar8;
    }
    else {
      piVar8 = (int *)FUN_006df3d0();
      DAT_00fba7cc = piVar8;
    }
  }
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar9 = DAT_00d63d09 != '\0';
  *(undefined1 *)(piVar8 + 0xbf) = 0;
  if (bVar9) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  iVar4 = D3DXCheckVersion(0x20,0x20);
  if (iVar4 != 0) {
    iVar4 = FUN_006dfb80();
    if (iVar4 == 0) {
      cVar2 = FUN_006ed6a0();
      if ((cVar2 != '\0') && (DAT_00fba7e4 != (code *)0x0)) {
        iVar3 = (*DAT_00fba7e4)(0x20);
      }
      if (DAT_00fba7cc == (int *)0x0) {
        iVar4 = FUN_00891268(0x1380);
        if (iVar4 == 0) {
          DAT_00fba7cc = (int *)0x0;
        }
        else {
          DAT_00fba7cc = (int *)FUN_006df3d0();
        }
      }
      piVar1 = DAT_00fba7cc;
      if (DAT_00d63d09 != '\0') {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      }
      bVar9 = DAT_00d63d09 != '\0';
      *piVar1 = iVar3;
      if (bVar9) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      }
      if (iVar3 == 0) {
        FUN_006ea570(0x80040901);
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
    if ((_DAT_00fe4b40 & 1) == 0) {
      _DAT_00fe4b40 = _DAT_00fe4b40 | 1;
      FUN_006eb420();
    }
    iVar3 = DAT_00fe4b2c;
    iVar4 = DAT_00fe4b28;
    if (DAT_00fe4b28 == 0 && DAT_00fe4b2c == 0) {
      FUN_006eb3c0(&local_24c);
      iVar3 = local_248;
      iVar4 = local_24c;
    }
    DAT_00fe4b28 = 0;
    DAT_00fe4b2c = 0;
    DAT_00fe4b19 = 0;
    _DAT_00fe4b30 = iVar4;
    _DAT_00fe4b34 = iVar3;
    _DAT_00fe4b38 = iVar4;
    _DAT_00fe4b3c = iVar3;
    if (DAT_00fba7cc == (int *)0x0) {
      iVar3 = FUN_00891268(0x1380);
      if (iVar3 == 0) {
        DAT_00fba7cc = (int *)0x0;
      }
      else {
        DAT_00fba7cc = (int *)FUN_006df3d0();
      }
    }
    piVar1 = DAT_00fba7cc;
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    bVar9 = DAT_00d63d09 != '\0';
    *(undefined1 *)(piVar1 + 0xc4) = 1;
    if (bVar9) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
    return;
  }
  FUN_006ea570(0x80040909);
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

