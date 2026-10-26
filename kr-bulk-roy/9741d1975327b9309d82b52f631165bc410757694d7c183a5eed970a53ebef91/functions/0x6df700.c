
void FUN_006df700(int *param_1)

{
  longlong lVar1;
  uint *puVar2;
  BOOL BVar3;
  int iVar4;
  HDC pHVar5;
  uint *puVar6;
  HICON in_ECX;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  undefined1 local_ac [4];
  uint local_a8;
  uint *local_a4;
  undefined1 local_94 [4];
  uint *local_90;
  int local_8c;
  int local_88;
  int local_84;
  uint *local_80;
  int *local_7c;
  HDC local_78;
  int local_74;
  HDC local_70;
  ICONINFO local_6c;
  uint *local_58;
  HDC local_54;
  LPVOID local_50;
  uint *local_4c;
  int *local_48;
  LPVOID local_44;
  uint *local_40;
  char local_39;
  tagBITMAPINFO local_38;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_7c = param_1;
  local_48 = (int *)0x0;
  local_78 = (HDC)0x0;
  local_70 = (HDC)0x0;
  local_54 = (HDC)0x0;
  local_50 = (LPVOID)0x0;
  local_44 = (LPVOID)0x0;
  local_6c.fIcon = 0;
  local_6c.xHotspot = 0;
  local_6c.yHotspot = 0;
  local_6c.hbmMask = (HBITMAP)0x0;
  local_6c.hbmColor = (HBITMAP)0x0;
  BVar3 = GetIconInfo(in_ECX,&local_6c);
  if ((BVar3 != 0) && (iVar4 = GetObjectW(local_6c.hbmMask,0x18,local_ac), iVar4 != 0)) {
    local_39 = local_6c.hbmColor == (HBITMAP)0x0;
    local_40 = local_a4;
    puVar6 = local_a4;
    if ((bool)local_39) {
      puVar6 = (uint *)((uint)local_a4 >> 1);
    }
    iVar4 = (**(code **)(*local_7c + 0x90))(local_7c,local_a8,puVar6,0x15,3,&local_48,0);
    puVar2 = local_40;
    if (-1 < iVar4) {
      lVar1 = (ulonglong)((int)local_40 * local_a8) * 4;
      local_44 = (LPVOID)FUN_0087dc3d(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
      _memset(&local_38,0,0x2c);
      local_38.bmiHeader.biSize = 0x28;
      local_38.bmiHeader.biWidth = local_a8;
      local_38.bmiHeader.biHeight = (LONG)puVar2;
      local_38.bmiHeader.biPlanes = 1;
      local_38.bmiHeader.biBitCount = 0x20;
      local_38.bmiHeader.biCompression = 0;
      local_54 = GetDC((HWND)0x0);
      pHVar5 = CreateCompatibleDC(local_54);
      local_70 = pHVar5;
      if (pHVar5 != (HDC)0x0) {
        local_4c = SelectObject(pHVar5,local_6c.hbmMask);
        GetDIBits(pHVar5,local_6c.hbmMask,0,(UINT)local_40,local_44,&local_38,0);
        SelectObject(pHVar5,local_4c);
        if (local_39 == '\0') {
          lVar1 = (ulonglong)((int)puVar6 * local_a8) * 4;
          local_50 = (LPVOID)FUN_0087dc3d(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) |
                                          (uint)lVar1);
          pHVar5 = CreateCompatibleDC(local_54);
          local_78 = pHVar5;
          if (pHVar5 == (HDC)0x0) goto LAB_006df9ca;
          SelectObject(pHVar5,local_6c.hbmColor);
          GetDIBits(pHVar5,local_6c.hbmColor,0,(UINT)puVar6,local_50,&local_38,0);
        }
        (**(code **)(*local_48 + 0x34))(local_48,local_94,0,0);
        if (puVar6 != (uint *)0x0) {
          local_84 = -local_a8;
          local_58 = local_90;
          local_74 = ((int)local_40 + -1) * local_a8;
          local_88 = local_a8 * -4;
          local_80 = (uint *)(((int)puVar6 * 4 + -4) * local_a8 + (int)local_44);
          local_4c = puVar6;
          do {
            uVar9 = 0;
            if (local_a8 != 0) {
              local_40 = local_58;
              local_8c = (int)local_50 - (int)local_44;
              puVar6 = local_80;
              do {
                if (local_39 == '\0') {
                  uVar7 = *(uint *)(local_8c + (int)puVar6);
                  uVar8 = *puVar6;
                }
                else {
                  uVar7 = *puVar6;
                  uVar8 = *(uint *)((int)local_44 + (local_74 + uVar9) * 4);
                }
                if (uVar8 == 0) {
                  *local_40 = uVar7 | 0xff000000;
                }
                else {
                  *local_40 = 0;
                }
                local_40 = local_40 + 1;
                uVar9 = uVar9 + 1;
                puVar6 = puVar6 + 1;
              } while (uVar9 < local_a8);
            }
            local_74 = local_74 + local_84;
            local_58 = local_58 + local_a8;
            local_80 = local_80 + -local_a8;
            local_4c = (uint *)((int)local_4c + -1);
          } while (local_4c != (uint *)0x0);
        }
        (**(code **)(*local_48 + 0x38))(local_48);
        (**(code **)(*local_7c + 0x28))(local_7c,local_6c.xHotspot,local_6c.yHotspot,local_48);
      }
    }
  }
LAB_006df9ca:
  if (local_6c.hbmMask != (HBITMAP)0x0) {
    DeleteObject(local_6c.hbmMask);
  }
  if (local_6c.hbmColor != (HBITMAP)0x0) {
    DeleteObject(local_6c.hbmColor);
  }
  if (local_54 != (HDC)0x0) {
    ReleaseDC((HWND)0x0,local_54);
  }
  if (local_78 != (HDC)0x0) {
    DeleteDC(local_78);
  }
  if (local_70 != (HDC)0x0) {
    DeleteDC(local_70);
  }
  if (local_50 != (LPVOID)0x0) {
    FUN_00891d3d(local_50);
  }
  if (local_44 != (LPVOID)0x0) {
    FUN_00891d3d(local_44);
  }
  if (local_48 != (int *)0x0) {
    (**(code **)(*local_48 + 8))(local_48);
  }
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

