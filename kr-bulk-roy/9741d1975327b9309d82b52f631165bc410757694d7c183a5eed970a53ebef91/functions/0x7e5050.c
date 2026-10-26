
void FUN_007e5050(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  char *pcVar4;
  undefined4 uVar5;
  void *_Src;
  int iVar6;
  int *unaff_EBX;
  uint uVar7;
  int *unaff_ESI;
  int unaff_EDI;
  int *_Size;
  int *piVar8;
  int *local_28;
  undefined4 local_24;
  int *local_20;
  int iStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00934c01;
  local_14 = ExceptionList;
  piVar3 = (int *)(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
  ExceptionList = &local_14;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_c = 0xffffffff;
  uVar7 = 0;
  local_20 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
  if (*(int *)(unaff_EDI + 0x188) - *(int *)(unaff_EDI + 0x184) >> 2 != 0) {
    do {
      iVar6 = *(int *)(*(int *)(unaff_EDI + 0x184) + uVar7 * 4);
      pcVar4 = (char *)(unaff_EDI + 0x2c);
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(unaff_EDI + 0x2c,(int)pcVar4 - (unaff_EDI + 0x2d));
      *(undefined4 *)(iVar6 + 0x30) = *(undefined4 *)(unaff_EDI + 0x158);
      *(undefined4 *)(iVar6 + 0x34) = *(undefined4 *)(unaff_EDI + 0x15c);
      FUN_007f7b10(iVar6);
      uVar7 = uVar7 + 1;
    } while (uVar7 < (uint)(*(int *)(unaff_EDI + 0x188) - *(int *)(unaff_EDI + 0x184) >> 2));
  }
  piVar2 = local_20;
  if (*(int *)(unaff_EDI + 0x148) == 0) {
    local_24 = 0;
    D3DXCreateTexture(local_20,0x100,0x100,0,0,0x15,1,&local_24);
    D3DXFillTexture(local_24,FUN_007e4d00,0);
    local_28 = (int *)0x0;
    D3DXSaveTextureToFileInMemory(&local_28,0,local_24,0);
    piVar8 = local_28;
    uVar5 = (**(code **)(*local_28 + 0x10))();
    uVar5 = FUN_0087dc3d(uVar5);
    *(undefined4 *)(unaff_EDI + 0x148) = uVar5;
    uVar5 = (**(code **)(*unaff_EBX + 0x10))(unaff_EBX);
    _Size = unaff_ESI;
    _Src = (void *)(**(code **)(*unaff_ESI + 0xc))(unaff_ESI,uVar5);
    FID_conflict__memcpy(*(void **)(unaff_EDI + 0x148),_Src,(size_t)_Size);
    uVar5 = (**(code **)(*piVar3 + 0x10))(piVar3);
    *(undefined4 *)(unaff_EDI + 0x14c) = uVar5;
    (**(code **)(*piVar8 + 8))(piVar8);
    (**(code **)(*piVar8 + 8))(piVar8);
  }
  if (*(int *)(unaff_EDI + 0x28) == 0) {
    local_20 = (int *)0x0;
    iVar6 = D3DXCreateTextureFromFileInMemory
                      (piVar2,*(undefined4 *)(unaff_EDI + 0x148),*(undefined4 *)(unaff_EDI + 0x14c),
                       &local_20);
    if ((iVar6 == 0) &&
       (uVar7 = 0, *(int *)(unaff_EDI + 0x188) - *(int *)(unaff_EDI + 0x184) >> 2 != 0)) {
      do {
        FUN_007f80a0(local_20);
        uVar7 = uVar7 + 1;
      } while (uVar7 < (uint)(*(int *)(unaff_EDI + 0x188) - *(int *)(unaff_EDI + 0x184) >> 2));
    }
    if (local_20 != (int *)0x0) {
      (**(code **)(*local_20 + 8))(local_20);
    }
  }
  else {
    local_28 = (int *)0x0;
    local_24 = 0;
    D3DXCreateTextureFromFileInMemory
              (piVar2,*(undefined4 *)(unaff_EDI + 0x148),*(undefined4 *)(unaff_EDI + 0x14c),
               &local_24);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_c = 0xffffffff;
    }
    EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 2;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_c = 0xffffffff;
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_c = 3;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_c = 0xffffffff;
      }
    }
    (**(code **)(*DAT_00fb76a8 + 0x50))("SYSTEM_LIGHTMAP",local_24,&local_28);
    (**(code **)(*unaff_ESI + 8))(unaff_ESI);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 4;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_c = 0xffffffff;
    }
    LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fb76ec);
    if (*(int *)(unaff_EDI + 0x188) - *(int *)(unaff_EDI + 0x184) >> 2 != 0) {
      uVar7 = 0;
      do {
        iStack_1c = *(int *)(*(int *)(unaff_EDI + 0x184) + uVar7 * 4);
        local_20 = (int *)FUN_00891268(0xbc);
        local_c = 5;
        if (local_20 == (int *)0x0) {
          iVar6 = 0;
        }
        else {
          iVar6 = FUN_00856910();
        }
        local_c = 0xffffffff;
        *(int **)(iVar6 + 0xb8) = local_28;
        FUN_00843fa0(*(undefined4 *)(iStack_1c + 0x80),4);
        uVar7 = uVar7 + 1;
      } while (uVar7 < (uint)(*(int *)(unaff_EDI + 0x188) - *(int *)(unaff_EDI + 0x184) >> 2));
      ExceptionList = local_14;
      return;
    }
  }
  ExceptionList = local_14;
  return;
}

