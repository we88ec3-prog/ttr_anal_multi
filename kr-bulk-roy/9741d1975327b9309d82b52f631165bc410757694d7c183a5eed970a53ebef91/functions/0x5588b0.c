
void FUN_005588b0(undefined4 param_1,undefined4 *param_2)

{
  void *pvVar1;
  int iVar2;
  HDC hdc;
  HBITMAP h;
  undefined1 *puVar3;
  undefined1 *puVar4;
  uint in_EDX;
  undefined1 *puVar5;
  uint uVar6;
  int iVar7;
  undefined1 local_64 [4];
  int local_60;
  int local_5c;
  int *local_4c;
  undefined4 *local_48;
  int local_44;
  LONG local_40;
  undefined1 *local_3c;
  void *local_38;
  BITMAPINFO local_34;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_48 = param_2;
  local_38 = (void *)0x0;
  iVar2 = FUN_00716eb0(param_1);
  pvVar1 = local_38;
  if (iVar2 < 0) {
    local_3c = (undefined1 *)0x0;
    local_44 = 0;
    local_40 = 0;
    if (in_EDX < 0x12) goto LAB_005589a9;
    iVar2 = FUN_00558710(param_1,&local_3c,&local_44,&local_40);
    puVar5 = local_3c;
  }
  else {
    if ((*(short *)((int)local_38 + 4) == 0) || (*(short *)((int)local_38 + 4) == 2)) {
      FUN_00733ea0();
    }
    if ((*(short *)((int)pvVar1 + 4) == 1) || (*(short *)((int)pvVar1 + 4) == 2)) {
      FUN_00733ea0();
    }
    uVar6 = local_40 - 8;
    local_3c = (undefined1 *)0x0;
    local_44 = 0;
    local_40 = 0;
    if (uVar6 < 0x12) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00558710((int)pvVar1 + 8,&local_3c,&local_44,&local_40);
    }
    puVar5 = local_3c;
    FUN_00891d3d(pvVar1);
  }
  iVar7 = 0;
  if (iVar2 != 0) {
    hdc = CreateCompatibleDC((HDC)0x0);
    if (hdc != (HDC)0x0) {
      _memset(&local_34,0,0x2c);
      local_34.bmiHeader.biWidth = local_44;
      local_34.bmiHeader.biHeight = local_40;
      local_34.bmiHeader.biBitCount = 0x20;
      local_38 = (void *)0x0;
      local_34.bmiHeader.biSize = 0x28;
      local_34.bmiHeader.biPlanes = 1;
      h = CreateDIBSection(hdc,&local_34,0,&local_38,(HANDLE)0x0,0);
      *local_48 = h;
      if ((h != (HBITMAP)0x0) && (iVar2 = GetObjectW(h,0x18,local_64), iVar2 != 0)) {
        puVar4 = puVar5;
        if (0 < local_5c) {
          local_48 = (undefined4 *)(local_44 * 4);
          do {
            puVar4 = (undefined1 *)((int)local_38 + local_60 * iVar7 * 4);
            iVar2 = 0;
            puVar3 = puVar5;
            if (0 < local_60) {
              do {
                *puVar4 = puVar3[2];
                puVar4[1] = puVar3[1];
                puVar4[2] = *puVar3;
                puVar4[3] = puVar3[3];
                iVar2 = iVar2 + 1;
                puVar4 = puVar4 + 4;
                puVar3 = puVar3 + 4;
              } while (iVar2 < local_60);
            }
            puVar5 = puVar5 + (int)local_48;
            iVar7 = iVar7 + 1;
            puVar4 = local_3c;
          } while (iVar7 < local_5c);
        }
        FUN_00891d3d(puVar4);
        *local_4c = (int)local_38;
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
    }
    FUN_00891d3d(puVar5);
  }
LAB_005589a9:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

