
void FUN_006e4f90(int *param_1,int param_2,char param_3,undefined4 param_4,undefined4 *param_5)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  code *pcVar5;
  int *piVar6;
  undefined4 uVar7;
  LONG LVar8;
  HWND pHVar9;
  HMENU pHVar10;
  uint uVar11;
  WINDOWPLACEMENT *pWVar12;
  HWND pHVar13;
  BOOL BVar14;
  DWORD DVar15;
  undefined4 *puVar16;
  int iVar17;
  undefined4 *puVar18;
  LONG Y;
  int iVar19;
  int iVar20;
  undefined4 uVar21;
  UINT UVar22;
  tagRECT *ptVar23;
  EXECUTION_STATE esFlags;
  uint local_218;
  int local_208;
  char local_202;
  char local_201;
  undefined1 local_200 [304];
  tagRECT local_d0;
  undefined1 local_c0 [32];
  undefined4 local_a0;
  int local_8c;
  int local_88;
  int local_84;
  int local_80;
  tagRECT local_78;
  undefined4 local_68 [4];
  undefined4 local_58;
  undefined4 local_54;
  WINDOWPLACEMENT local_4c;
  tagRECT local_1c;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
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
  piVar1 = *(int **)(iVar3 + 0xc);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  local_208 = 0;
  iVar3 = FUN_006dfb80();
  if (iVar3 == 0) {
LAB_006e5116:
    __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
    return;
  }
  piVar4 = (int *)FUN_00891268(0x48);
  iVar3 = DAT_00fba7cc;
  if (piVar4 == (int *)0x0) {
    __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
    return;
  }
  piVar6 = piVar4;
  for (iVar17 = 0x12; iVar17 != 0; iVar17 = iVar17 + -1) {
    *piVar6 = *param_1;
    param_1 = param_1 + 1;
    piVar6 = piVar6 + 1;
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
  pcVar5 = (code *)FUN_006e1420(iVar3);
  if (pcVar5 != (code *)0x0) {
    piVar6 = (int *)FUN_006dfb80();
    (**(code **)(*piVar6 + 0x38))(piVar6,*piVar4,piVar4[1],local_200);
    uVar7 = FUN_006df6d0();
    uVar7 = FUN_006e15e0(uVar7);
    cVar2 = (*pcVar5)(piVar4,local_200,uVar7);
    if (cVar2 == '\0') {
      if (piVar1 == (int *)0x0) {
        FUN_006ea570(0x80040902);
      }
      FUN_0089120c(piVar4);
      __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
      return;
    }
    uVar7 = FUN_006df6d0();
    iVar3 = FUN_006df420(uVar7);
    if (iVar3 == 0) {
      FUN_0089120c(piVar4);
      goto LAB_006e5116;
    }
  }
  piVar6 = piVar4;
  uVar7 = FUN_006df6d0(piVar4);
  FUN_006e0380(uVar7,piVar6);
  FUN_006e71f0(0,1);
  uVar21 = 1;
  uVar7 = FUN_006df6d0(1);
  FUN_006e0950(uVar7,uVar21);
  DAT_00d63d09 = (byte)((uint)piVar4[3] >> 2) & 1;
  if ((param_2 == 0) && (piVar1 == (int *)0x0)) {
    FUN_006e62d0(piVar4);
  }
  local_201 = '\0';
  if ((piVar4[4] == 0) && (piVar4[5] == 0)) {
    local_201 = '\x01';
  }
  if (piVar4[0xc] == 0) {
    if ((piVar1 == (int *)0x0) || (piVar1[0xc] != 0)) {
      uVar7 = FUN_006df6d0();
      pWVar12 = (WINDOWPLACEMENT *)FUN_006e0690(uVar7);
      _memset(pWVar12,0,0x2c);
      pWVar12->length = 0x2c;
      pHVar9 = (HWND)FUN_006dfed0();
      GetWindowPlacement(pHVar9,pWVar12);
      iVar3 = -0x14;
      pHVar9 = (HWND)FUN_006dfed0();
      uVar11 = GetWindowLongW(pHVar9,iVar3);
      local_218 = CONCAT31(local_218._1_3_,(char)(uVar11 >> 3)) & 0xffffff01;
      uVar7 = FUN_006df6d0(local_218);
      FUN_006e0750(uVar7,local_218);
      iVar3 = -0x10;
      pHVar9 = (HWND)FUN_006dfed0();
      uVar11 = GetWindowLongW(pHVar9,iVar3);
      uVar11 = uVar11 & 0xdeffffff;
      uVar7 = FUN_006df6d0(uVar11);
      FUN_006e06d0(uVar7,uVar11);
      if (piVar1 != (int *)0x0) {
        iVar3 = piVar1[4];
        uVar7 = FUN_006df6d0(iVar3);
        FUN_006dea20(uVar7,iVar3);
        iVar3 = piVar1[5];
        uVar7 = FUN_006df6d0(iVar3);
        FUN_006dea60(uVar7,iVar3);
      }
    }
    iVar3 = 0;
    pHVar9 = (HWND)FUN_006dfe70();
    ShowWindow(pHVar9,iVar3);
    LVar8 = -0x7ff80000;
    iVar3 = -0x10;
    pHVar9 = (HWND)FUN_006dfe70();
    SetWindowLongW(pHVar9,iVar3,LVar8);
    iVar3 = FUN_006dfe70();
    iVar17 = FUN_006dfed0();
    if (iVar3 == iVar17) {
      pHVar9 = (HWND)FUN_006dfe70();
      pHVar10 = GetMenu(pHVar9);
      uVar7 = FUN_006df6d0(pHVar10);
      FUN_006e0540(uVar7,pHVar10);
      pHVar10 = (HMENU)0x0;
      pHVar9 = (HWND)FUN_006dfe70();
      SetMenu(pHVar9,pHVar10);
    }
    _memset(&local_4c,0,0x2c);
    pWVar12 = &local_4c;
    local_4c.length = 0x2c;
    pHVar9 = (HWND)FUN_006dfe70();
    GetWindowPlacement(pHVar9,pWVar12);
    if ((local_4c.flags & 2) != 0) {
      local_4c.flags = local_4c.flags & 0xfffffffd;
      pWVar12 = &local_4c;
      local_4c.showCmd = 9;
      pHVar9 = (HWND)FUN_006dfe70();
      SetWindowPlacement(pHVar9,pWVar12);
    }
  }
  else {
    if ((piVar1 != (int *)0x0) && (piVar1[0xc] == 0)) {
      iVar3 = piVar1[4];
      uVar7 = FUN_006df6d0(iVar3);
      FUN_006e05c0(uVar7,iVar3);
      iVar3 = piVar1[5];
      uVar7 = FUN_006df6d0(iVar3);
      FUN_006e0600(uVar7,iVar3);
      uVar7 = FUN_006df6d0();
      LVar8 = FUN_006e0710(uVar7);
      iVar3 = -0x10;
      pHVar9 = (HWND)FUN_006dfed0();
      SetWindowLongW(pHVar9,iVar3,LVar8);
    }
    iVar3 = FUN_006dfe70();
    iVar17 = FUN_006dfed0();
    if (iVar3 != iVar17) {
      iVar3 = 0;
      pHVar9 = (HWND)FUN_006dfe70();
      ShowWindow(pHVar9,iVar3);
    }
    iVar3 = FUN_006dfe70();
    iVar17 = FUN_006dfed0();
    if (iVar3 == iVar17) {
      uVar7 = FUN_006df6d0();
      iVar3 = FUN_006e0580(uVar7);
      if (iVar3 != 0) {
        uVar7 = FUN_006df6d0();
        pHVar10 = (HMENU)FUN_006e0580(uVar7);
        pHVar9 = (HWND)FUN_006dfed0();
        SetMenu(pHVar9,pHVar10);
      }
    }
  }
  if ((param_3 == '\0') &&
     (((param_2 == 0 || (iVar3 = FUN_006dfbe0(), param_2 == iVar3)) &&
      (iVar3 = FUN_006dfbe0(), iVar3 != 0)))) {
    if (piVar1 == (int *)0x0) goto LAB_006e552a;
    if (((*piVar1 != *piVar4) || (piVar1[1] != piVar4[1])) || (piVar1[3] != piVar4[3]))
    goto LAB_006e551c;
    iVar3 = FUN_006e6c20(piVar1);
    if (iVar3 < 0) {
      if (iVar3 != -0x7789f798) {
        if ((iVar3 == -0x7ffbf6f8) || (iVar3 == -0x7ffbf6fd)) {
          if (local_208 == 0) {
            if (param_5 != (undefined4 *)0x0) {
              *param_5 = 1;
            }
            FUN_0089120c(piVar1);
          }
          FUN_006ea570(iVar3);
          FUN_006e9ae0();
          __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
          return;
        }
        piVar6 = piVar1;
        uVar7 = FUN_006df6d0(piVar1);
        FUN_006e0380(uVar7,piVar6);
        iVar3 = FUN_006e4f90(piVar4,param_2,1,param_4,&local_208);
        if (iVar3 < 0) {
          if (local_208 == 0) {
            if (param_5 != (undefined4 *)0x0) {
              *param_5 = 1;
            }
            FUN_0089120c(piVar1);
          }
          FUN_006e9ae0();
          __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
          return;
        }
        if (local_208 == 0) {
          if (param_5 != (undefined4 *)0x0) {
            *param_5 = 1;
          }
          FUN_0089120c(piVar1);
          __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
          return;
        }
        goto LAB_006e5b68;
      }
      uVar21 = 1;
      uVar7 = FUN_006df6d0(1);
      FUN_006e10a0(uVar7,uVar21);
    }
  }
  else {
LAB_006e551c:
    if (piVar1 != (int *)0x0) {
      FUN_006e9c50(0);
    }
LAB_006e552a:
    iVar3 = FUN_006e65a0();
    if (iVar3 < 0) {
      if (local_208 == 0) {
        if (param_5 != (undefined4 *)0x0) {
          *param_5 = 1;
        }
        if (piVar1 != (int *)0x0) {
          FUN_0089120c(piVar1);
        }
      }
      FUN_006e9c50(1);
      FUN_006ea570(iVar3);
      FUN_006e71f0(0,0);
      uVar21 = 0;
      uVar7 = FUN_006df6d0(0);
      FUN_006e0950(uVar7,uVar21);
      __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  if (piVar4[0xc] == 0) {
    uVar7 = FUN_006df6d0();
    uVar7 = FUN_006e0ad0(uVar7);
  }
  else {
    uVar7 = FUN_006df6d0();
    uVar7 = FUN_006e0b10(uVar7);
  }
  FUN_006e5e10(uVar7);
  piVar6 = (int *)FUN_006dfb80();
  uVar7 = (**(code **)(*piVar6 + 0x3c))(piVar6,*piVar4);
  uVar21 = FUN_006df6d0(uVar7);
  FUN_006e04c0(uVar21,uVar7);
  FUN_006e8bc0();
  if (((piVar1 != (int *)0x0) && (piVar1[0xc] == 0)) && (piVar4[0xc] != 0)) {
    uVar7 = FUN_006df6d0();
    pWVar12 = (WINDOWPLACEMENT *)FUN_006e0690(uVar7);
    pHVar9 = (HWND)FUN_006dfed0();
    SetWindowPlacement(pHVar9,pWVar12);
    uVar7 = FUN_006df6d0();
    cVar2 = FUN_006e0790(uVar7);
    UVar22 = 0xb;
    iVar20 = 0;
    iVar19 = 0;
    iVar17 = 0;
    iVar3 = 0;
    pHVar9 = (HWND)((cVar2 != '\0') - 2);
    pHVar13 = (HWND)FUN_006dfed0();
    SetWindowPos(pHVar13,pHVar9,iVar3,iVar17,iVar19,iVar20,UVar22);
  }
  local_202 = '\0';
  if ((piVar4[0xc] != 0) && (local_201 == '\0')) {
    pHVar9 = (HWND)FUN_006dfed0();
    BVar14 = IsIconic(pHVar9);
    if (BVar14 == 0) {
      ptVar23 = &local_1c;
      pHVar9 = (HWND)FUN_006dfed0();
      GetClientRect(pHVar9,ptVar23);
      iVar3 = local_1c.right - local_1c.left;
      iVar17 = local_1c.bottom - local_1c.top;
    }
    else {
      _memset(&local_4c,0,0x2c);
      pWVar12 = &local_4c;
      local_4c.length = 0x2c;
      pHVar9 = (HWND)FUN_006dfed0();
      GetWindowPlacement(pHVar9,pWVar12);
      if (((local_4c.flags & 2) == 0) || (local_4c.showCmd != 2)) {
        local_1c.left = 0;
        local_1c.top = 0;
        local_1c.right = 0;
        local_1c.bottom = 0;
        uVar7 = FUN_006df6d0();
        iVar3 = FUN_006e0580(uVar7);
        uVar11 = (uint)(iVar3 != 0);
        uVar7 = FUN_006df6d0();
        DVar15 = FUN_006e0710(uVar7);
        AdjustWindowRect(&local_1c,DVar15,uVar11);
        iVar3 = ((local_4c.rcNormalPosition.right - local_4c.rcNormalPosition.left) - local_1c.right
                ) + local_1c.left;
        iVar17 = ((local_4c.rcNormalPosition.bottom - local_4c.rcNormalPosition.top) -
                 local_1c.bottom) + local_1c.top;
      }
      else {
        iVar3 = 9;
        pHVar9 = (HWND)FUN_006dfed0();
        ShowWindow(pHVar9,iVar3);
        ptVar23 = &local_1c;
        pHVar9 = (HWND)FUN_006dfed0();
        GetClientRect(pHVar9,ptVar23);
        iVar3 = local_1c.right - local_1c.left;
        iVar17 = local_1c.bottom - local_1c.top;
        iVar19 = 6;
        pHVar9 = (HWND)FUN_006dfed0();
        ShowWindow(pHVar9,iVar19);
      }
    }
    if ((iVar3 != piVar4[4]) || (iVar17 != piVar4[5])) {
      local_202 = '\x01';
    }
    if ((char)param_4 == '\0') {
LAB_006e57ea:
      if (local_202 == '\0') goto LAB_006e5ac1;
    }
    else {
      pHVar9 = (HWND)FUN_006dfed0();
      BVar14 = IsIconic(pHVar9);
      if (BVar14 != 0) goto LAB_006e57ea;
      local_a0 = 0x28;
      piVar6 = (int *)FUN_006dfb80();
      iVar3 = (**(code **)(*piVar6 + 0x3c))(piVar6,*piVar4);
      FUN_006ed7f0(iVar3);
      uVar7 = FUN_006dfd60();
      iVar17 = FUN_006ed930(uVar7);
      ptVar23 = &local_1c;
      pHVar9 = (HWND)FUN_006dfed0();
      GetWindowRect(pHVar9,ptVar23);
      if ((((local_8c <= local_1c.left) && (local_1c.right <= local_84)) &&
          (local_88 <= local_1c.top)) && (local_1c.bottom <= local_80)) goto LAB_006e57ea;
      if (iVar17 == iVar3) {
        pHVar9 = (HWND)FUN_006dfed0();
        BVar14 = IsZoomed(pHVar9);
        if (BVar14 != 0) goto LAB_006e57ea;
      }
    }
    pHVar9 = (HWND)FUN_006dfed0();
    BVar14 = IsIconic(pHVar9);
    if (BVar14 != 0) {
      iVar3 = 9;
      pHVar9 = (HWND)FUN_006dfed0();
      ShowWindow(pHVar9,iVar3);
    }
    pHVar9 = (HWND)FUN_006dfed0();
    BVar14 = IsZoomed(pHVar9);
    if (BVar14 != 0) {
      iVar3 = 9;
      pHVar9 = (HWND)FUN_006dfed0();
      ShowWindow(pHVar9,iVar3);
    }
    if ((char)param_4 == '\0') {
      local_1c.right = piVar4[4];
      local_1c.bottom = piVar4[5];
      local_1c.left = 0;
      local_1c.top = 0;
      uVar7 = FUN_006df6d0();
      iVar3 = FUN_006e0580(uVar7);
      uVar11 = (uint)(iVar3 != 0);
      iVar3 = -0x10;
      pHVar9 = (HWND)FUN_006dfed0();
      DVar15 = GetWindowLongW(pHVar9,iVar3);
      AdjustWindowRect(&local_1c,DVar15,uVar11);
      iVar3 = local_1c.right - local_1c.left;
      iVar17 = local_1c.bottom - local_1c.top;
      UVar22 = 6;
      Y = 0;
      LVar8 = 0;
    }
    else {
      local_a0 = 0x28;
      piVar6 = (int *)FUN_006dfb80();
      uVar7 = (**(code **)(*piVar6 + 0x3c))(piVar6,*piVar4);
      FUN_006ed7f0(uVar7);
      local_4c.flags = 0x28;
      uVar7 = FUN_006dfd60();
      uVar7 = FUN_006ed930(uVar7);
      FUN_006ed7f0(uVar7);
      iVar19 = local_80 - local_88;
      iVar3 = piVar4[5];
      iVar20 = local_84 - local_8c;
      iVar17 = piVar4[4];
      ptVar23 = &local_d0;
      pHVar9 = (HWND)FUN_006dfed0();
      GetWindowRect(pHVar9,ptVar23);
      local_1c.left = 0;
      local_1c.top = 0;
      local_1c.right = iVar17;
      local_1c.bottom = iVar3;
      uVar7 = FUN_006df6d0();
      iVar3 = FUN_006e0580(uVar7);
      uVar11 = (uint)(iVar3 != 0);
      iVar3 = -0x10;
      pHVar9 = (HWND)FUN_006dfed0();
      DVar15 = GetWindowLongW(pHVar9,iVar3);
      AdjustWindowRect(&local_1c,DVar15,uVar11);
      iVar3 = local_1c.right - local_1c.left;
      if (iVar20 < local_1c.right - local_1c.left) {
        iVar3 = iVar20;
      }
      iVar17 = local_1c.bottom - local_1c.top;
      if (iVar19 < local_1c.bottom - local_1c.top) {
        iVar17 = iVar19;
      }
      if (((local_1c.left < local_8c) || (local_1c.top < local_88)) ||
         ((local_84 < local_1c.right || (local_80 < local_1c.bottom)))) {
        iVar20 = (iVar20 - iVar3) / 2;
        local_1c.left = local_8c + iVar20;
        iVar19 = (iVar19 - iVar17) / 2;
        local_1c.top = local_88 + iVar19;
        local_1c.right = iVar20 + iVar3 + local_8c;
        local_1c.bottom = iVar19 + iVar17 + local_88;
      }
      UVar22 = 4;
      LVar8 = local_1c.left;
      Y = local_1c.top;
    }
    pHVar13 = (HWND)0x0;
    pHVar9 = (HWND)FUN_006dfed0();
    SetWindowPos(pHVar9,pHVar13,LVar8,Y,iVar3,iVar17,UVar22);
    ptVar23 = &local_78;
    pHVar9 = (HWND)FUN_006dfed0();
    GetClientRect(pHVar9,ptVar23);
    if ((local_78.right - local_78.left != piVar4[4]) ||
       (local_78.bottom - local_78.top != piVar4[5])) {
      puVar16 = (undefined4 *)FUN_006ea4e0(local_c0);
      puVar18 = local_68;
      for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar18 = *puVar16;
        puVar16 = puVar16 + 1;
        puVar18 = puVar18 + 1;
      }
      local_58 = 0;
      local_54 = 0;
      iVar3 = FUN_006e4f90(local_68,0,0,param_4,&local_208);
      if (iVar3 < 0) {
        if (local_208 == 0) {
          if (param_5 != (undefined4 *)0x0) {
            *param_5 = 1;
          }
          if (piVar1 != (int *)0x0) {
            FUN_0089120c(piVar1);
          }
        }
        FUN_006e9c50(1);
        FUN_006e71f0(0,0);
        uVar21 = 0;
        uVar7 = FUN_006df6d0(0);
        FUN_006e0950(uVar7,uVar21);
        __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
        return;
      }
    }
  }
LAB_006e5ac1:
  pHVar9 = (HWND)FUN_006dfd60();
  BVar14 = IsWindowVisible(pHVar9);
  if (BVar14 == 0) {
    iVar3 = 5;
    pHVar9 = (HWND)FUN_006dfd60();
    ShowWindow(pHVar9,iVar3);
  }
  pHVar9 = (HWND)FUN_006dfd60();
  BVar14 = IsWindowVisible(pHVar9);
  if (BVar14 == 0) {
    iVar3 = 5;
    pHVar9 = (HWND)FUN_006dfd60();
    ShowWindow(pHVar9,iVar3);
  }
  cVar2 = FUN_006ea3d0();
  if (cVar2 == '\0') {
    esFlags = 0x80000002;
  }
  else {
    esFlags = 0x80000000;
  }
  SetThreadExecutionState(esFlags);
  if (local_208 == 0) {
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 1;
    }
    if (piVar1 != (int *)0x0) {
      FUN_0089120c(piVar1);
    }
  }
  uVar21 = 0;
  uVar7 = FUN_006df6d0(0);
  FUN_006e0950(uVar7,uVar21);
  FUN_006e71f0(0,0);
  uVar21 = 1;
  uVar7 = FUN_006df6d0(1);
  FUN_006e0de0(uVar7,uVar21);
LAB_006e5b68:
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

