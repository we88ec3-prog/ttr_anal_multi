
void FUN_006e6c20(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  LONG LVar6;
  undefined4 uVar7;
  WINDOWPLACEMENT *lpwndpl;
  HWND hWnd;
  code *pcVar8;
  int iVar9;
  DEVMODEW *pDVar10;
  undefined4 *puVar11;
  bool bVar12;
  undefined4 auStack_1f4 [48];
  undefined4 uStack_134;
  DEVMODEW local_100;
  tagRECT local_1c;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  piVar3 = (int *)FUN_006dfbe0();
  if (DAT_00fba7cc == 0) {
    iVar4 = FUN_00891268();
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
  cVar2 = *(char *)(iVar4 + 0x317);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (cVar2 == '\x01') {
    if (DAT_00fba7cc == 0) {
      iVar4 = FUN_00891268();
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
    iVar5 = DAT_00fba7cc;
    bVar12 = DAT_00d63d09 != '\0';
    *(undefined1 *)(iVar4 + 0x318) = 1;
    if (bVar12) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      iVar5 = DAT_00fba7cc;
    }
    if (iVar5 == 0) {
      iVar4 = FUN_00891268();
      if (iVar4 == 0) {
        iVar5 = 0;
        DAT_00fba7cc = iVar5;
      }
      else {
        iVar5 = FUN_006df3d0();
        DAT_00fba7cc = iVar5;
      }
    }
    iVar4 = iVar5;
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      iVar4 = DAT_00fba7cc;
    }
    pcVar8 = *(code **)(iVar5 + 0x36c);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      iVar4 = DAT_00fba7cc;
    }
    if (pcVar8 != (code *)0x0) {
      if (iVar4 == 0) {
        iVar4 = FUN_00891268();
        if (iVar4 == 0) {
          DAT_00fba7cc = 0;
        }
        else {
          DAT_00fba7cc = FUN_006df3d0();
        }
      }
      FUN_006e16a0();
      (*pcVar8)();
      iVar4 = DAT_00fba7cc;
    }
    if (iVar4 == 0) {
      iVar4 = FUN_00891268();
      if (iVar4 == 0) {
        iVar4 = 0;
        DAT_00fba7cc = iVar4;
      }
      else {
        iVar4 = FUN_006df3d0();
        DAT_00fba7cc = iVar4;
      }
    }
    iVar5 = iVar4;
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      iVar5 = DAT_00fba7cc;
    }
    bVar12 = DAT_00d63d09 != '\0';
    *(undefined1 *)(iVar4 + 0x317) = 0;
    if (bVar12) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      iVar5 = DAT_00fba7cc;
    }
    if (iVar5 == 0) {
      iVar4 = FUN_00891268();
      if (iVar4 == 0) {
        iVar5 = 0;
        DAT_00fba7cc = iVar5;
      }
      else {
        iVar5 = FUN_006df3d0();
        DAT_00fba7cc = iVar5;
      }
    }
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    bVar12 = DAT_00d63d09 != '\0';
    *(undefined1 *)(iVar5 + 0x318) = 0;
    if (bVar12) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    FUN_006eb5e0();
    FUN_006eb7d0();
  }
  if (DAT_00fba7cc == 0) {
    iVar4 = FUN_00891268();
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
  iVar4 = *(int *)(iVar4 + 0xc);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  iVar5 = *(int *)(iVar4 + 0x30);
  uVar1 = *(undefined4 *)(iVar4 + 0x40);
  if ((iVar5 == 0) && (cVar2 = FUN_006e0200(), cVar2 != '\0')) {
    _memset(&local_100,0,0xdc);
    local_100.dmPelsWidth = *(DWORD *)(iVar4 + 0x10);
    local_100.dmPelsHeight = *(DWORD *)(iVar4 + 0x14);
    local_100.dmSize = 0xdc;
    local_100.dmBitsPerPel = (-(uint)(*(int *)(iVar4 + 0x18) != 0x17) & 0x10) + 0x10;
    local_100.dmFields = 0x1c0000;
    LVar6 = ChangeDisplaySettingsW(&local_100,4);
    if (LVar6 == 0) {
      pDVar10 = &local_100;
      puVar11 = auStack_1f4;
      for (iVar9 = 0x37; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar11 = *(undefined4 *)pDVar10->dmDeviceName;
        pDVar10 = (DEVMODEW *)(pDVar10->dmDeviceName + 2);
        puVar11 = puVar11 + 1;
      }
      uVar7 = FUN_006df6d0();
      FUN_006e0640(uVar7);
      local_1c.right = *(int *)(iVar4 + 0x10);
      local_1c.bottom = *(int *)(iVar4 + 0x14);
      *(undefined4 *)(iVar4 + 0x40) = 0;
      local_1c.left = 0;
      local_1c.top = 0;
      *(undefined4 *)(iVar4 + 0x30) = 1;
      AdjustWindowRect(&local_1c,0x80080000,0);
      uStack_134 = 0x6e6f93;
      MoveWindow(*(HWND *)(iVar4 + 0x2c),local_1c.left,local_1c.top,local_1c.right - local_1c.left,
                 local_1c.bottom - local_1c.top,1);
      ShowWindow(*(HWND *)(iVar4 + 0x2c),5);
    }
  }
  else if ((param_1 != 0) &&
          ((*(int *)(param_1 + 0x30) == 0 && (cVar2 = FUN_006e0200(), cVar2 != '\0')))) {
    FUN_006df6d0();
    lpwndpl = (WINDOWPLACEMENT *)FUN_006e0690();
    hWnd = (HWND)FUN_006dfed0();
    SetWindowPlacement(hWnd,lpwndpl);
    ChangeDisplaySettingsW((DEVMODEW *)0x0,0);
  }
  iVar9 = (**(code **)(*piVar3 + 0x40))();
  *(int *)(iVar4 + 0x30) = iVar5;
  *(undefined4 *)(iVar4 + 0x40) = uVar1;
  if (iVar9 < 0) {
    __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
    return;
  }
  FUN_006ea1a0();
  FUN_006dfa50();
  FUN_006eb5e0();
  iVar4 = FUN_006eb770();
  if (iVar4 < 0) {
    __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
    return;
  }
  if (DAT_00fba7cc == 0) {
    iVar4 = FUN_00891268();
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
  bVar12 = DAT_00d63d09 != '\0';
  *(undefined1 *)(iVar4 + 0x318) = 1;
  if (bVar12) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  FUN_006dfc40();
  if (DAT_00fba7cc == 0) {
    iVar4 = FUN_00891268();
    if (iVar4 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  pcVar8 = (code *)FUN_006e1460();
  iVar4 = 0;
  if (pcVar8 != (code *)0x0) {
    FUN_006df6d0();
    FUN_006e1660();
    iVar4 = (*pcVar8)();
  }
  if (DAT_00fba7cc == 0) {
    iVar5 = FUN_00891268();
    if (iVar5 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar5 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar12 = DAT_00d63d09 != '\0';
  *(undefined1 *)(iVar5 + 0x318) = 0;
  if (bVar12) {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (iVar4 < 0) {
    FUN_006df6d0();
    FUN_006e0ea0();
    FUN_006df6d0();
    pcVar8 = (code *)FUN_006e14a0();
    if (pcVar8 != (code *)0x0) {
      FUN_006df6d0();
      FUN_006e16a0();
      (*pcVar8)();
    }
    FUN_006df6d0();
    FUN_006e0ea0();
    FUN_006eb5e0();
    FUN_006eb7d0();
    __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
    return;
  }
  FUN_006df6d0();
  FUN_006e0fa0();
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

