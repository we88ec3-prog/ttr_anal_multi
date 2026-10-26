
void FUN_006e65a0(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  LONG LVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  code *pcVar9;
  int *in_ECX;
  int iVar10;
  DEVMODEW *pDVar11;
  bool bVar12;
  undefined4 auStack_1f8 [44];
  undefined4 uStack_148;
  int iStack_144;
  int *piStack_140;
  int *local_100;
  DEVMODEW local_fc;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_100 = (int *)0x0;
  if (DAT_00fba7cc == 0) {
    iVar3 = FUN_00891268();
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
  piVar1 = *(int **)(iVar3 + 0xc);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (in_ECX == (int *)0x0) {
    piVar4 = (int *)FUN_006dfb80();
    iVar3 = piVar1[0xc];
    iVar7 = piVar1[0x10];
    if ((iVar3 == 0) && (cVar2 = FUN_006e0200(), cVar2 != '\0')) {
      _memset(&local_fc,0,0xdc);
      local_fc.dmPelsWidth = piVar1[4];
      local_fc.dmPelsHeight = piVar1[5];
      local_fc.dmSize = 0xdc;
      local_fc.dmBitsPerPel = (-(uint)(piVar1[6] != 0x17) & 0x10) + 0x10;
      local_fc.dmFields = 0x1c0000;
      LVar5 = ChangeDisplaySettingsW(&local_fc,4);
      if (LVar5 == 0) {
        pDVar11 = &local_fc;
        puVar8 = auStack_1f8;
        for (iVar10 = 0x37; iVar10 != 0; iVar10 = iVar10 + -1) {
          *puVar8 = *(undefined4 *)pDVar11->dmDeviceName;
          pDVar11 = (DEVMODEW *)(pDVar11->dmDeviceName + 2);
          puVar8 = puVar8 + 1;
        }
        uVar6 = FUN_006df6d0();
        FUN_006e0640(uVar6);
        local_18.right = piVar1[4];
        local_18.bottom = piVar1[5];
        piVar1[0x10] = 0;
        local_18.left = 0;
        local_18.top = 0;
        piVar1[0xc] = 1;
        AdjustWindowRect(&local_18,0x80080000,0);
        MoveWindow((HWND)piVar1[0xb],local_18.left,local_18.top,local_18.right - local_18.left,
                   local_18.bottom - local_18.top,1);
        ShowWindow((HWND)piVar1[0xb],5);
      }
    }
    iVar10 = *piVar4;
    FUN_006dfe10();
    iVar10 = (**(code **)(iVar10 + 0x40))();
    piVar1[0xc] = iVar3;
    iVar3 = DAT_00fba7cc;
    if (iVar10 == -0x7789f798) {
      piVar1[0x10] = iVar7;
      if (iVar3 == 0) {
        piStack_140 = (int *)0x6e6788;
        iVar3 = FUN_00891268();
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
        piStack_140 = (int *)0x6e67b3;
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      }
      bVar12 = DAT_00d63d09 != '\0';
      *(undefined1 *)(iVar3 + 0x328) = 1;
      if (bVar12) {
        piStack_140 = (int *)0x6e67d2;
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      goto LAB_006e6c06;
    }
    if (iVar10 < 0) {
      piVar1[0x10] = iVar7;
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    piVar1[0x10] = iVar7;
  }
  else {
    (**(code **)(*in_ECX + 4))();
    local_100 = in_ECX;
  }
  if (DAT_00fba7cc == 0) {
    piStack_140 = (int *)0x6e6834;
    iVar3 = FUN_00891268();
    if (iVar3 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar3 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    piStack_140 = (int *)0x6e6865;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  iVar7 = DAT_00fba7cc;
  bVar12 = DAT_00d63d09 != '\0';
  *(int **)(iVar3 + 4) = local_100;
  if (bVar12) {
    piStack_140 = (int *)0x6e6883;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    iVar7 = DAT_00fba7cc;
  }
  if (piVar1[1] == 2) {
    if (iVar7 == 0) {
      piStack_140 = (int *)0x6e689c;
      iVar3 = FUN_00891268();
      if (iVar3 == 0) {
        iVar7 = 0;
        DAT_00fba7cc = iVar7;
      }
      else {
        iVar7 = FUN_006df3d0();
        DAT_00fba7cc = iVar7;
      }
    }
    iVar3 = iVar7;
    if (DAT_00d63d09 != '\0') {
      piStack_140 = (int *)0x6e68c7;
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      iVar3 = DAT_00fba7cc;
    }
    iVar10 = *(int *)(iVar7 + 0x30c);
    iVar7 = iVar3;
    if (DAT_00d63d09 != '\0') {
      piStack_140 = (int *)0x6e68e2;
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      iVar7 = DAT_00fba7cc;
    }
    if (iVar10 != 0) goto LAB_006e68ef;
LAB_006e6925:
    piStack_140 = (int *)0x6e692a;
    piStack_140 = (int *)FUN_006df6d0();
    iStack_144 = 0x6e6930;
    FUN_006e0ce0();
  }
  else {
LAB_006e68ef:
    if (piVar1[1] == 1) {
      if (iVar7 == 0) {
        piStack_140 = (int *)0x6e6903;
        iVar3 = FUN_00891268();
        if (iVar3 == 0) {
          DAT_00fba7cc = 0;
        }
        else {
          DAT_00fba7cc = FUN_006df3d0();
        }
      }
      piStack_140 = (int *)0x6e691e;
      iVar3 = FUN_006df5e0();
      if (iVar3 == 0xb) goto LAB_006e6925;
    }
  }
  FUN_006ea1a0();
  FUN_006dfa50();
  if (DAT_00fba7cc == 0) {
    piStack_140 = (int *)0x6e694d;
    iVar3 = FUN_00891268();
    if (iVar3 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  if (DAT_00d63d09 != '\0') {
    piStack_140 = (int *)0x6e6978;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (DAT_00d63d09 != '\0') {
    piStack_140 = (int *)0x6e698b;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  piStack_140 = (int *)FUN_006dfbe0();
  iStack_144 = 0x6e6999;
  (**(code **)(*piStack_140 + 0x1c))();
  piStack_140 = (int *)0x6e69a0;
  iVar3 = FUN_006e3660();
  iVar7 = 0;
  if (0 < *(int *)(iVar3 + 0x58)) {
    puVar8 = *(undefined4 **)(iVar3 + 0x54);
    do {
      if (*(int *)*puVar8 == *piVar1) break;
      iVar7 = iVar7 + 1;
      puVar8 = puVar8 + 1;
    } while (iVar7 < *(int *)(iVar3 + 0x58));
  }
  piStack_140 = (int *)piVar1[3];
  iStack_144 = piVar1[1];
  uStack_148 = 0x6e69d2;
  FUN_006e8360();
  FUN_006eb5e0();
  iVar3 = FUN_006dfc40();
  if (DAT_00fba7cc == 0) {
    piStack_140 = (int *)0x6e69f4;
    iVar7 = FUN_00891268();
    if (iVar7 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar7 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    piStack_140 = (int *)0x6e6a1f;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar12 = DAT_00d63d09 != '\0';
  *(undefined1 *)(iVar7 + 0x318) = 1;
  if (bVar12) {
    piStack_140 = (int *)0x6e6a3a;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (DAT_00fba7cc == 0) {
    piStack_140 = (int *)0x6e6a4d;
    iVar7 = FUN_00891268();
    if (iVar7 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar7 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    piStack_140 = (int *)0x6e6a78;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  pcVar9 = *(code **)(iVar7 + 0x364);
  if (DAT_00d63d09 != '\0') {
    piStack_140 = (int *)0x6e6a92;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  iVar7 = 0;
  if (pcVar9 != (code *)0x0) {
    FUN_006df6d0();
    piStack_140 = (int *)0x6e6aa3;
    FUN_006e1620();
    iStack_144 = 0x6e6aaa;
    piStack_140 = (int *)iVar3;
    iStack_144 = FUN_006dfbe0();
    uStack_148 = 0x6e6aad;
    iVar7 = (*pcVar9)();
  }
  if (DAT_00fba7cc == 0) {
    piStack_140 = (int *)0x6e6ac2;
    iVar10 = FUN_00891268();
    if (iVar10 == 0) {
      DAT_00fba7cc = 0;
    }
    else {
      DAT_00fba7cc = FUN_006df3d0();
    }
  }
  iVar10 = DAT_00fba7cc;
  if (DAT_00d63d09 != '\0') {
    piStack_140 = (int *)0x6e6aed;
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  bVar12 = DAT_00d63d09 != '\0';
  *(undefined1 *)(iVar10 + 0x318) = 0;
  if (bVar12) {
    piStack_140 = (int *)0x6e6b08;
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  iVar10 = FUN_006dfbe0();
  if (iVar10 != 0) {
    if (iVar7 < 0) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    piStack_140 = (int *)0x6e6b55;
    piStack_140 = (int *)FUN_006df6d0();
    iStack_144 = 0x6e6b5b;
    FUN_006e0f20();
    FUN_006eb5e0();
    iVar7 = FUN_006eb770();
    if (iVar7 < 0) {
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
    piStack_140 = (int *)0x6e6b88;
    piStack_140 = (int *)FUN_006df6d0();
    iStack_144 = 0x6e6b8e;
    FUN_006e0ea0();
    FUN_006df6d0();
    piStack_140 = (int *)0x6e6b99;
    pcVar9 = (code *)FUN_006e1460();
    iVar7 = 0;
    if (pcVar9 != (code *)0x0) {
      FUN_006df6d0();
      piStack_140 = (int *)0x6e6bac;
      FUN_006e1660();
      iStack_144 = 0x6e6bb3;
      piStack_140 = (int *)iVar3;
      iStack_144 = FUN_006dfbe0();
      uStack_148 = 0x6e6bb6;
      iVar7 = (*pcVar9)();
    }
    piStack_140 = (int *)0x6e6bbf;
    piStack_140 = (int *)FUN_006df6d0();
    iStack_144 = 0x6e6bc5;
    FUN_006e0ea0();
    iVar3 = FUN_006dfbe0();
    if (iVar3 != 0) {
      if (iVar7 < 0) {
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      piStack_140 = (int *)0x6e6c00;
      piStack_140 = (int *)FUN_006df6d0();
      iStack_144 = 0x6e6c06;
      FUN_006e0fa0();
LAB_006e6c06:
      __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

