
void FUN_006e8e80(HWND param_1,uint param_2,uint param_3,uint param_4)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  code *pcVar6;
  HWND pHVar7;
  BOOL BVar8;
  HMENU hMenu;
  LPCWSTR lpClassName;
  int *piVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined1 uVar12;
  uint wParam;
  uint uVar14;
  tagRECT *lpRect;
  HINSTANCE hInstance;
  undefined8 uVar13;
  undefined1 auStack_b4 [55];
  char cStack_7d;
  uint local_7c;
  HWND local_78;
  int local_74;
  uint local_70;
  uint uStack_6c;
  int iStack_68;
  uint uStack_64;
  uint uStack_60;
  tagPOINT tStack_5c;
  tagRECT tStack_54;
  uint local_44;
  
  local_44 = DAT_00d61f20 ^ (uint)auStack_b4;
  local_78 = param_1;
  local_7c = param_3;
  if ((param_2 == 0x100) || (param_2 == 0x104)) {
    uVar12 = 1;
LAB_006e8ed2:
    local_74 = CONCAT31(local_74._1_3_,uVar12);
    local_70 = CONCAT31(local_70._1_3_,(byte)(param_4 >> 0x1d)) & 0xffffff01;
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
    if ((DAT_00d63d09 != '\0') &&
       (EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8), DAT_00d63d09 != '\0')) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    *(undefined1 *)((local_7c & 0xff) + 0x3c0 + iVar3) = uVar12;
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
    pcVar6 = *(code **)(iVar3 + 0x380);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    if (pcVar6 != (code *)0x0) {
      if (DAT_00fba7cc == 0) {
        iVar3 = FUN_00891268();
        if (iVar3 == 0) {
          DAT_00fba7cc = 0;
        }
        else {
          DAT_00fba7cc = FUN_006df3d0();
        }
      }
      if (DAT_00d63d09 != '\0') {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      }
      if (DAT_00d63d09 != '\0') {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      }
      (*pcVar6)(local_7c,local_74,local_70);
    }
  }
  else if ((param_2 == 0x101) || (param_2 == 0x105)) {
    uVar12 = 0;
    goto LAB_006e8ed2;
  }
  if ((((((param_2 == 0x201) || (param_2 == 0x202)) || (param_2 == 0x203)) ||
       (((param_2 == 0x207 || (param_2 == 0x208)) ||
        ((param_2 == 0x209 || ((param_2 == 0x204 || (param_2 == 0x205)))))))) || (param_2 == 0x206))
     || ((((param_2 == 0x20b || (param_2 == 0x20c)) || (param_2 == 0x20d)) || (param_2 == 0x20a))))
  {
LAB_006e908e:
    local_74 = (int)(short)(param_4 >> 0x10);
    iVar3 = (int)(short)param_4;
    if (param_2 == 0x20a) {
      tStack_5c.x = (int)(short)param_4;
      tStack_5c.y = local_74;
      ScreenToClient(local_78,&tStack_5c);
      local_74 = tStack_5c.y;
      iVar3 = tStack_5c.x;
    }
    iStack_68 = 0;
    if (param_2 == 0x20a) {
      iStack_68 = (int)(short)(local_7c >> 0x10);
    }
    bVar2 = (byte)local_7c;
    local_70 = CONCAT31(local_70._1_3_,(char)((ushort)local_7c >> 1)) & 0xffffff01;
    uStack_6c = CONCAT31(uStack_6c._1_3_,(char)((ushort)local_7c >> 6)) & 0xffffff01;
    tStack_54.left = CONCAT31(tStack_54.left._1_3_,bVar2) & 0xffffff01;
    uStack_60 = CONCAT31(uStack_60._1_3_,(char)((ushort)local_7c >> 4)) & 0xffffff01;
    uStack_64 = CONCAT31(uStack_64._1_3_,(char)((ushort)local_7c >> 5)) & 0xffffff01;
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
    if ((DAT_00d63d09 != '\0') &&
       (EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8), DAT_00d63d09 != '\0')) {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    *(undefined1 *)(iVar4 + 0x4c1) = (undefined1)uStack_60;
    *(undefined1 *)(iVar4 + 0x4c2) = (undefined1)local_70;
    iVar5 = DAT_00fba7cc;
    *(byte *)(iVar4 + 0x4c0) = bVar2 & 1;
    *(undefined1 *)(iVar4 + 0x4c3) = (undefined1)uStack_64;
    *(undefined1 *)(iVar4 + 0x4c4) = (undefined1)uStack_6c;
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
    pcVar6 = *(code **)(iVar5 + 900);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    if (pcVar6 != (code *)0x0) {
      if (DAT_00fba7cc == 0) {
        iVar4 = FUN_00891268();
        if (iVar4 == 0) {
          DAT_00fba7cc = 0;
        }
        else {
          DAT_00fba7cc = FUN_006df3d0();
        }
      }
      if (DAT_00d63d09 != '\0') {
        EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      }
      if (DAT_00d63d09 != '\0') {
        LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
      }
      (*pcVar6)(tStack_54.left,local_70,uStack_60,uStack_64,uStack_6c,iStack_68,iVar3,local_74);
    }
  }
  else {
    FUN_006df6d0();
    cVar1 = FUN_006e10e0();
    if ((cVar1 != '\0') && (param_2 == 0x200)) goto LAB_006e908e;
  }
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
  pcVar6 = *(code **)(iVar3 + 0x388);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  wParam = local_7c;
  if (pcVar6 != (code *)0x0) {
    cStack_7d = '\0';
    if (DAT_00fba7cc == 0) {
      iVar3 = FUN_00891268();
      if (iVar3 == 0) {
        DAT_00fba7cc = 0;
      }
      else {
        DAT_00fba7cc = FUN_006df3d0();
      }
    }
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    wParam = local_7c;
    (*pcVar6)(local_78,param_2,local_7c,param_4,&cStack_7d);
    if (cStack_7d != '\0') goto LAB_006e9780;
  }
  pHVar7 = local_78;
  if (param_2 < 0x105) {
    if (param_2 == 0x104) {
      if (wParam == 0xd) {
        FUN_006df6d0();
        cVar1 = FUN_006e0c60();
        if ((cVar1 != '\0') && ((param_4 & 0x20000000) != 0)) {
          FUN_006e71f0(0,1);
          FUN_006e2e20();
          FUN_006e71f0(0,0);
          goto LAB_006e9780;
        }
      }
    }
    else {
      switch(param_2) {
      case 2:
        DAT_00d63d84 = 0;
        break;
      case 5:
        if (wParam == 1) {
          FUN_006e71f0(0);
          uVar14 = wParam;
          uVar10 = FUN_006df6d0();
          FUN_006e07d0(uVar10,uVar14);
          uVar11 = 0;
          uVar10 = FUN_006df6d0();
          FUN_006e0850(uVar10,uVar11);
        }
        else {
          lpRect = &tStack_54;
          pHVar7 = (HWND)FUN_006dfd60();
          GetClientRect(pHVar7,lpRect);
          if ((tStack_54.top != 0) || (tStack_54.bottom != 0)) {
            if (wParam == 2) {
              FUN_006df6d0();
              cVar1 = FUN_006e0810();
              if (cVar1 != '\0') {
                FUN_006e71f0(0);
              }
              uVar11 = 0;
              uVar10 = FUN_006df6d0();
              FUN_006e07d0(uVar10,uVar11);
              uVar10 = 1;
LAB_006e94f3:
              uVar11 = FUN_006df6d0();
              FUN_006e0850(uVar11,uVar10);
              FUN_006e7510();
              FUN_006ea9e0();
            }
            else if (wParam == 0) {
              FUN_006df6d0();
              cVar1 = FUN_006e0890();
              if (cVar1 != '\0') {
                uVar10 = 0;
                goto LAB_006e94f3;
              }
              FUN_006df6d0();
              cVar1 = FUN_006e0810();
              if (cVar1 == '\0') {
                FUN_006df6d0();
                cVar1 = FUN_006e1160();
                if (cVar1 == '\0') {
                  FUN_006e7510();
                  FUN_006ea9e0();
                }
              }
              else {
                FUN_006e71f0(0);
                uVar11 = 0;
                uVar10 = FUN_006df6d0();
                FUN_006e07d0(uVar10,uVar11);
                FUN_006e7510();
                FUN_006ea9e0();
              }
            }
          }
        }
        break;
      case 0xf:
        piVar9 = (int *)FUN_006dfbe0();
        if ((piVar9 != (int *)0x0) && (cVar1 = FUN_006e00d0(), cVar1 != '\0')) {
          FUN_006df6d0();
          cVar1 = FUN_006e0f60();
          if (cVar1 != '\0') {
            FUN_006df6d0();
            cVar1 = FUN_006e0fe0();
            if (cVar1 != '\0') {
              FUN_006dff30();
              FUN_006dffa0();
              FUN_006df6d0();
              pcVar6 = (code *)FUN_006e15a0();
              if (pcVar6 != (code *)0x0) {
                FUN_006df6d0();
                FUN_006e17a0();
                (*pcVar6)(piVar9);
              }
              iVar3 = (**(code **)(*piVar9 + 0x44))(piVar9,0,0,0);
              if (iVar3 == -0x7789f798) {
                uVar11 = 1;
                uVar10 = FUN_006df6d0();
                FUN_006e10a0(uVar10,uVar11);
              }
              else if (iVar3 == -0x7789f7d9) {
                uVar11 = 1;
                uVar10 = FUN_006df6d0();
                FUN_006e10a0(uVar10,uVar11);
              }
            }
          }
        }
        break;
      case 0x10:
        FUN_006e9c50();
        hMenu = GetMenu(pHVar7);
        if (hMenu != (HMENU)0x0) {
          DestroyMenu(hMenu);
        }
        DestroyWindow(pHVar7);
        hInstance = (HINSTANCE)0x0;
        uVar10 = FUN_006df6d0();
        lpClassName = (LPCWSTR)FUN_006e1820(uVar10);
        UnregisterClassW(lpClassName,hInstance);
        uVar11 = 0;
        uVar10 = FUN_006df6d0();
        FUN_006e0400(uVar10,uVar11);
        uVar11 = 0;
        uVar10 = FUN_006df6d0();
        FUN_006e0440(uVar10,uVar11);
        uVar11 = 0;
        uVar10 = FUN_006df6d0();
        FUN_006e0480(uVar10,uVar11);
        goto LAB_006e9780;
      case 0x1c:
        if (wParam == 1) {
          cVar1 = FUN_006e0140();
          if (cVar1 == '\0') {
            uVar14 = wParam;
            uVar10 = FUN_006df6d0();
            FUN_006e1020(uVar10,uVar14);
            cVar1 = FUN_006e0200();
            if (cVar1 != '\0') {
              FUN_006df6d0();
              iVar3 = FUN_006e03c0();
              if (*(int *)(iVar3 + 0x30) == 0) {
                ShowWindow(pHVar7,5);
              }
            }
            FUN_006df6d0();
            cVar1 = FUN_006e0910();
            if (cVar1 != '\0') {
              FUN_006e71f0(0);
              uVar11 = 0;
              uVar10 = FUN_006df6d0();
              FUN_006e08d0(uVar10,uVar11);
              uVar11 = 1;
              uVar10 = FUN_006df6d0();
              FUN_006e10a0(uVar10,uVar11);
            }
            cVar1 = FUN_006ea3d0();
            if (cVar1 == '\0') {
              FUN_006df6d0();
              FUN_006e0ad0();
              FUN_006e5e10();
            }
            else {
              FUN_006df6d0();
              FUN_006e0b10();
              FUN_006e5e10();
            }
          }
        }
        else if ((wParam == 0) && (cVar1 = FUN_006e0140(), cVar1 != '\0')) {
          uVar14 = wParam;
          uVar10 = FUN_006df6d0();
          FUN_006e1020(uVar10,uVar14);
          cVar1 = FUN_006e0200();
          if ((cVar1 != '\0') &&
             ((cVar1 = FUN_006ea3d0(), cVar1 == '\0' &&
              (BVar8 = IsWindowVisible(pHVar7), BVar8 != 0)))) {
            ChangeDisplaySettingsW((DEVMODEW *)0x0,0);
            ShowWindow(pHVar7,6);
          }
          cVar1 = FUN_006ea3d0();
          if (cVar1 == '\0') {
            ClipCursor((RECT *)0x0);
            FUN_006e71f0(0);
            uVar11 = 1;
            uVar10 = FUN_006df6d0();
            FUN_006e08d0(uVar10,uVar11);
          }
          FUN_006e5e10();
        }
        break;
      case 0x20:
        cVar1 = FUN_006e0140();
        if ((cVar1 != '\0') && (cVar1 = FUN_006ea3d0(), cVar1 == '\0')) {
          piVar9 = (int *)FUN_006dfbe0();
          if (piVar9 != (int *)0x0) {
            FUN_006df6d0();
            cVar1 = FUN_006df560();
            if (cVar1 != '\0') {
              (**(code **)(*piVar9 + 0x30))(piVar9,1);
            }
          }
LAB_006e95a4:
          __security_check_cookie(local_44 ^ (uint)auStack_b4);
          return;
        }
        break;
      case 0x84:
        cVar1 = FUN_006ea3d0();
        if (cVar1 == '\0') {
          __security_check_cookie(local_44 ^ (uint)auStack_b4);
          return;
        }
      }
    }
  }
  else if (param_2 < 0x219) {
    if (param_2 == 0x218) {
      if (wParam == 0) goto LAB_006e95a4;
      if (wParam == 7) {
        FUN_006eb340();
        FUN_006eb4d0();
        uVar13 = 0;
        uVar10 = FUN_006df6d0(0);
        FUN_006e0a10(uVar10,uVar13);
        __security_check_cookie(local_44 ^ (uint)auStack_b4);
        return;
      }
    }
    else if (param_2 == 0x112) {
      if (wParam < 0xf031) {
        if (((wParam == 0xf030) || (wParam == 0xf000)) || (wParam == 0xf010)) {
LAB_006e989f:
          cVar1 = FUN_006ea3d0();
          if (cVar1 == '\0') goto LAB_006e9780;
        }
      }
      else if (wParam == 0xf100) goto LAB_006e989f;
    }
    else {
      if (param_2 == 0x120) {
        __security_check_cookie(local_44 ^ (uint)auStack_b4);
        return;
      }
      if (((param_2 == 0x200) && (cVar1 = FUN_006e0140(), cVar1 != '\0')) &&
         ((cVar1 = FUN_006ea3d0(), cVar1 == '\0' &&
          (piVar9 = (int *)FUN_006dfbe0(), piVar9 != (int *)0x0)))) {
        GetCursorPos((LPPOINT)&tStack_54);
        (**(code **)(*piVar9 + 0x2c))(piVar9,tStack_54.left,tStack_54.top);
      }
    }
  }
  else {
    if (param_2 == 0x231) {
      FUN_006e71f0(0);
      uVar10 = 1;
    }
    else {
      if (param_2 != 0x232) goto switchD_006e939c_caseD_3;
      FUN_006e71f0(0);
      FUN_006e7510();
      FUN_006ea9e0();
      uVar10 = 0;
    }
    uVar11 = FUN_006df6d0();
    FUN_006e1120(uVar11,uVar10);
  }
switchD_006e939c_caseD_3:
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
  cVar1 = *(char *)(iVar3 + 0x2d3);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (cVar1 != '\0') {
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
    iVar3 = *(int *)(iVar3 + 0x170);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    if ((iVar3 != 0) || (((param_2 != 0x104 && (param_2 != 0x105)) || (wParam != 0x79)))) {
      DefWindowProcW(local_78,param_2,wParam,param_4);
      __security_check_cookie(local_44 ^ (uint)auStack_b4);
      return;
    }
  }
LAB_006e9780:
  __security_check_cookie(local_44 ^ (uint)auStack_b4);
  return;
}

