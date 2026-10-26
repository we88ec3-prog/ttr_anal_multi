
void FUN_006aa7f0(int param_1)

{
  WCHAR WVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  HANDLE pvVar5;
  LPCWSTR *****ppppppWVar6;
  WCHAR *pWVar7;
  BOOL BVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  uint uVar12;
  undefined1 auStack_2cc [4];
  int local_2c8;
  int local_2c4;
  int *local_2c0;
  int local_2bc;
  int local_2b8;
  undefined4 local_2b4;
  undefined4 local_2ac;
  uint local_2a8;
  undefined4 local_298;
  uint local_294;
  LPCWSTR ****local_28c [4];
  undefined4 local_27c;
  uint local_278;
  _WIN32_FIND_DATAW local_270;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  puStack_10 = &LAB_009328d2;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_2cc;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffd28;
  ExceptionList = &local_14;
  local_2c8 = param_1;
  local_2bc = 0;
  local_2b8 = 0;
  local_2b4 = 0;
  local_c = 0;
  local_28c[0] = (LPCWSTR ****)((uint)local_28c[0] & 0xffff0000);
  local_278 = 7;
  local_27c = 0;
  FUN_004026e0(param_1 + 0x104,0,0xffffffff);
  local_c._0_1_ = 1;
  FUN_00404300(L"\\*.*",4);
  ppppppWVar6 = (LPCWSTR *****)local_28c[0];
  if (local_278 < 8) {
    ppppppWVar6 = local_28c;
  }
  pvVar5 = FindFirstFileW((LPCWSTR)ppppppWVar6,&local_270);
  if (pvVar5 == (HANDLE)0xffffffff) {
    local_294 = 7;
    local_298 = 0;
    local_2a8 = local_2a8 & 0xffff0000;
    local_c._0_1_ = 3;
    local_2ac = 3;
    FUN_00402160(&DAT_00c3bc90,2);
    FUN_006ab570(uVar4);
    if (7 < local_294) {
      FUN_0089120c(local_2a8);
    }
  }
  else {
    do {
      if (((byte)local_270.dwFileAttributes & 0x10) != 0) {
        local_294 = 7;
        local_298 = 0;
        local_2a8 = local_2a8 & 0xffff0000;
        local_c._0_1_ = 2;
        local_2ac = 1;
        if (local_270.cFileName[0] == L'.') {
          if (local_270.cFileName[1] == L'\0') goto LAB_006aab32;
          if ((local_270.cFileName[1] == L'.') && (local_270.cFileName[2] == L'\0')) {
            local_2ac = 3;
          }
        }
        pWVar7 = local_270.cFileName;
        do {
          WVar1 = *pWVar7;
          pWVar7 = pWVar7 + 1;
        } while (WVar1 != L'\0');
        FUN_00402160(local_270.cFileName,(int)pWVar7 - (int)(local_270.cFileName + 1) >> 1);
        FUN_006ab570();
        if (7 < local_294) {
          FUN_0089120c(local_2a8);
        }
      }
LAB_006aab32:
      BVar8 = FindNextFileW(pvVar5,&local_270);
    } while (BVar8 != 0);
  }
  FindClose(pvVar5);
  local_c._0_1_ = 0;
  if (7 < local_278) {
    FUN_0089120c(local_28c[0]);
  }
  local_28c[0] = (LPCWSTR ****)((uint)local_28c[0] & 0xffff0000);
  local_278 = 7;
  local_27c = 0;
  FUN_004026e0(local_2c8 + 0x104,0,0xffffffff);
  local_c = CONCAT31(local_c._1_3_,4);
  FUN_00404300(L"\\*.bmp",6);
  ppppppWVar6 = (LPCWSTR *****)local_28c[0];
  if (local_278 < 8) {
    ppppppWVar6 = local_28c;
  }
  pvVar5 = FindFirstFileW((LPCWSTR)ppppppWVar6,&local_270);
  if (pvVar5 != (HANDLE)0xffffffff) {
    do {
      local_294 = 7;
      local_298 = 0;
      local_2a8 = local_2a8 & 0xffff0000;
      pWVar7 = local_270.cFileName;
      local_c = CONCAT31(local_c._1_3_,5);
      local_2ac = 2;
      do {
        WVar1 = *pWVar7;
        pWVar7 = pWVar7 + 1;
      } while (WVar1 != L'\0');
      FUN_00402160(local_270.cFileName,(int)pWVar7 - (int)(local_270.cFileName + 1) >> 1);
      FUN_006ab570();
      if (7 < local_294) {
        FUN_0089120c(local_2a8);
      }
      BVar8 = FindNextFileW(pvVar5,&local_270);
    } while (BVar8 != 0);
  }
  FindClose(pvVar5);
  local_c = local_c & 0xffffff00;
  if (7 < local_278) {
    FUN_0089120c(local_28c[0]);
  }
  iVar11 = local_2c8;
  iVar9 = *(int *)(*(int *)(local_2c8 + 0x100) + 0xcc);
  uVar12 = 0;
  uVar4 = local_2b8 - local_2bc >> 5;
  if (iVar9 != 0) {
    FUN_00408920(iVar9,uVar4);
  }
  iVar9 = *(int *)(*(int *)(iVar11 + 0x100) + 0xcc);
  if (iVar9 == 0) {
    local_2c0 = (int *)0x0;
  }
  else {
    local_2c0 = (int *)(iVar9 + 0xa8);
  }
  if (uVar4 != 0) {
    local_2c4 = local_2bc;
    do {
      piVar10 = *(int **)(*local_2c0 + uVar12 * 4);
      if (piVar10 == (int *)0x0) {
LAB_006aab90:
        piVar10 = (int *)0x0;
      }
      else {
        iVar9 = (**(code **)(*piVar10 + 4))();
        if (iVar9 != 0x12d) {
          MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
          goto LAB_006aab90;
        }
      }
      FUN_006aa520(piVar10,local_2c8 + 0x104,local_2c4);
      local_2c4 = local_2c4 + 0x20;
      uVar12 = uVar12 + 1;
      iVar11 = local_2c8;
    } while (uVar12 < uVar4);
  }
  piVar10 = *(int **)(iVar11 + 0x100);
  puVar2 = (undefined4 *)piVar10[0x19];
  for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
    iVar9 = puVar3[2];
    if ((*(int *)(iVar9 + 0x60) != 0) && ((*(int **)(iVar9 + 0x1c))[2] != 6)) {
      (**(code **)(**(int **)(iVar9 + 0x1c) + 0x30))(iVar9);
    }
  }
  (**(code **)(*piVar10 + 0x128))();
  (**(code **)(**(int **)(local_2c8 + 0x100) + 200))();
  iVar9 = local_2bc;
  if (local_2bc != 0) {
    FUN_006ab960(local_2c0);
    FUN_0089120c(iVar9);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_2cc);
  return;
}

