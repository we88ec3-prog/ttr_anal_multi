
void FUN_006e24d0(LPCWSTR param_1,int param_2,int param_3)

{
  char cVar1;
  ATOM AVar2;
  int iVar3;
  int iVar4;
  HMODULE hInst;
  undefined4 uVar5;
  DWORD DVar6;
  HWND pHVar7;
  DWORD in_ECX;
  WNDPROC in_EDX;
  LPCWSTR unaff_EDI;
  bool bVar8;
  HMODULE pHVar9;
  undefined4 uVar10;
  HWND pHVar11;
  UINT local_25c;
  WNDPROC local_258;
  int local_254;
  int local_250;
  HMODULE local_24c;
  HICON local_248;
  HCURSOR local_244;
  HBRUSH local_240;
  LPCWSTR local_23c;
  tagRECT local_228;
  WCHAR local_218 [262];
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
  cVar1 = *(char *)(iVar3 + 0x318);
  if (DAT_00d63d09 != '\0') {
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
  }
  if (cVar1 == '\0') {
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
    bVar8 = DAT_00d63d09 != '\0';
    *(undefined1 *)(iVar3 + 0x314) = 1;
    if (bVar8) {
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
    if (DAT_00d63d09 != '\0') {
      EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    cVar1 = *(char *)(iVar4 + 0x310);
    if (DAT_00d63d09 != '\0') {
      LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fba4c8);
    }
    if (cVar1 != '\0') {
      iVar3 = FUN_006dfe10();
      if (iVar3 == 0) {
        hInst = GetModuleHandleW((LPCWSTR)0x0);
        pHVar9 = hInst;
        uVar5 = FUN_006df6d0(hInst);
        FUN_006e09d0(uVar5,pHVar9);
        GetModuleFileNameW((HMODULE)0x0,local_218,0x104);
        DAT_00fba7d0 = ExtractIconW(hInst,local_218,0);
        local_25c = 8;
        local_258 = in_EDX;
        if (in_EDX == (WNDPROC)0x0) {
          local_258 = FUN_006e8e80;
        }
        DAT_00fba7d4 = 1;
        local_254 = 0;
        local_250 = 0;
        local_24c = hInst;
        local_248 = DAT_00fba7d0;
        local_244 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
        local_240 = GetStockObject(4);
        local_23c = (LPCWSTR)0x0;
        AVar2 = RegisterClassW((WNDCLASSW *)&local_25c);
        if ((AVar2 != 0) || (DVar6 = GetLastError(), DVar6 == 0x582)) {
          uVar10 = 0;
          uVar5 = FUN_006df6d0(0);
          FUN_006e0ca0(uVar5,uVar10);
          uVar10 = 1;
          uVar5 = FUN_006df6d0(1);
          FUN_006e0ca0(uVar5,uVar10);
          SetRect(&local_228,0,0,param_2,param_3);
          AdjustWindowRect(&local_228,in_ECX,0);
          uVar5 = FUN_006df6d0();
          FUN_006e1820(uVar5);
          FUN_006eadb0(unaff_EDI,0x7ffffffe);
          uVar5 = FUN_006df6d0();
          FUN_006df620(uVar5);
          FUN_006eadb0(param_1,0x7ffffffe);
          pHVar7 = CreateWindowExW(0,unaff_EDI,param_1,in_ECX,-0x80000000,-0x80000000,
                                   local_228.right - local_228.left,local_228.bottom - local_228.top
                                   ,(HWND)0x0,(HMENU)0x0,hInst,(LPVOID)0x0);
          if (pHVar7 != (HWND)0x0) {
            uVar5 = FUN_006df6d0();
            FUN_006e0d60(uVar5);
            pHVar11 = pHVar7;
            uVar5 = FUN_006df6d0(pHVar7);
            FUN_006e0400(uVar5,pHVar11);
            pHVar11 = pHVar7;
            uVar5 = FUN_006df6d0(pHVar7);
            FUN_006e0440(uVar5,pHVar11);
            uVar5 = FUN_006df6d0(pHVar7);
            FUN_006e0480(uVar5,pHVar7);
            goto LAB_006e2831;
          }
          DVar6 = GetLastError();
        }
        if (0 < (int)DVar6) {
          __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
          return;
        }
      }
LAB_006e2831:
      __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
      return;
    }
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

