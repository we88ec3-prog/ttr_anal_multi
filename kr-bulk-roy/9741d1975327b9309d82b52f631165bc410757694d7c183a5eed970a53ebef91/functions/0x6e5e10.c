
void FUN_006e5e10(char param_1)

{
  int iVar1;
  HHOOK pHVar2;
  HMODULE hmod;
  undefined4 uVar3;
  bool bVar4;
  DWORD dwThreadId;
  undefined4 local_150;
  uint local_14c;
  undefined4 local_148;
  uint local_144;
  _OSVERSIONINFOW local_140;
  undefined1 local_24 [4];
  uint local_20;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
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
  bVar4 = DAT_00d63d09 != '\0';
  *(char *)(iVar1 + 0x2d2) = param_1;
  if (bVar4) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (param_1 == '\0') {
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
    dwThreadId = *(DWORD *)(iVar1 + 0x2cc);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    if (dwThreadId == 0) {
      local_140.dwOSVersionInfoSize = 0x114;
      GetVersionExW(&local_140);
      if ((local_140.dwPlatformId == 2) && (4 < local_140.dwMajorVersion)) {
        hmod = GetModuleHandleW((LPCWSTR)0x0);
        pHVar2 = SetWindowsHookExW(0xd,FUN_006e5b80,hmod,dwThreadId);
        uVar3 = FUN_006df6d0(pHVar2);
        FUN_006e0a50(uVar3,pHVar2);
      }
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
    local_150 = *(undefined4 *)(iVar1 + 0x2d4);
    local_14c = *(uint *)(iVar1 + 0x2d8);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    if ((local_14c & 1) == 0) {
      local_14c = local_14c & 0xfffffff3;
      SystemParametersInfoW(0x3b,8,&local_150,0);
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
    local_148 = *(undefined4 *)(iVar1 + 0x2dc);
    local_144 = *(uint *)(iVar1 + 0x2e0);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    if ((local_144 & 1) == 0) {
      local_144 = local_144 & 0xfffffff3;
      SystemParametersInfoW(0x35,8,&local_148,0);
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
    FUN_006e0c00();
    if ((local_20 & 1) == 0) {
      local_20 = local_20 & 0xfffffff3;
      SystemParametersInfoW(0x33,0x18,local_24,0);
    }
  }
  else {
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
    local_148 = *(undefined4 *)(iVar1 + 0x2d4);
    local_144 = *(uint *)(iVar1 + 0x2d8);
    if (DAT_00d63d09 != '\0') {
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
    local_150 = *(undefined4 *)(iVar1 + 0x2dc);
    local_14c = *(uint *)(iVar1 + 0x2e0);
    if (DAT_00d63d09 != '\0') {
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
    FUN_006e0c00();
    SystemParametersInfoW(0x3b,8,&local_148,0);
    SystemParametersInfoW(0x35,8,&local_150,0);
    SystemParametersInfoW(0x33,0x18,local_24,0);
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
    iVar1 = *(int *)(iVar1 + 0x2cc);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    if (iVar1 != 0) {
      if (DAT_00fba7cc == 0) {
        iVar1 = FUN_00891268(0x1380);
        if (iVar1 == 0) {
          DAT_00fba7cc = 0;
        }
        else {
          DAT_00fba7cc = FUN_006df3d0();
        }
      }
      pHVar2 = (HHOOK)FUN_006e0a90(DAT_00fba7cc);
      UnhookWindowsHookEx(pHVar2);
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
      bVar4 = DAT_00d63d09 != '\0';
      *(undefined4 *)(iVar1 + 0x2cc) = 0;
      if (bVar4) {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
        __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
        return;
      }
    }
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

