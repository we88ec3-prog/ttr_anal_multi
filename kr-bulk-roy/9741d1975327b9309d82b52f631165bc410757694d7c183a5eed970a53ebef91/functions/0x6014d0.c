
void FUN_006014d0(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined1 *param_4)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  undefined2 local_94 [8];
  undefined4 local_84;
  undefined2 *local_80;
  undefined1 **ppuStack_7c;
  undefined2 local_78 [8];
  undefined4 local_68;
  undefined4 local_64;
  undefined4 *puStack_5c;
  undefined1 *local_44;
  undefined1 *local_40;
  undefined1 *local_3c [6];
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093e8be;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_44;
  ExceptionList = &local_14;
  local_3c[0] = param_1;
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 0;
    FUN_0051c120();
    puStack_5c = (undefined4 *)0x601533;
    _atexit((_func_4879 *)&LAB_00bccc90);
  }
  local_c = 0xffffffff;
  local_40 = param_4;
  puStack_5c = (undefined4 *)0x60155c;
  FUN_008438c0();
  if (local_44 == DAT_00f8d91c) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(local_44 + 0x10);
  }
  if ((DAT_00f8d9a4 & 1) == 0) {
    DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
    local_c = 1;
    FUN_0051c120();
    puStack_5c = (undefined4 *)0x601596;
    _atexit((_func_4879 *)&LAB_00bccc90);
    local_c = 0xffffffff;
  }
  local_44 = *(undefined1 **)(iVar3 + 0x50);
  puStack_5c = (undefined4 *)0x6015b7;
  FUN_008438c0();
  if ((local_40 != DAT_00f8d91c) && (iVar3 = *(int *)(local_40 + 0x10), iVar3 != 0)) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 2;
      FUN_004e1590();
      puStack_5c = (undefined4 *)0x6015f9;
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    if ((double)*(int *)(iVar3 + 0x24) * 0.05 <= (double)DAT_00f94244) {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_c = 5;
        FUN_00587480();
        puStack_5c = (undefined4 *)0x60172a;
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_c = 0xffffffff;
      }
      puStack_5c = (undefined4 *)0x601738;
      puStack_5c = (undefined4 *)FUN_00891268();
      if (puStack_5c == (undefined4 *)0x0) {
        puStack_5c = (undefined4 *)0x0;
      }
      else {
        puStack_5c[1] = 0xffffffff;
        puStack_5c[2] = 0xffffffff;
        puStack_5c[3] = 0;
        puStack_5c[4] = 0xf4385;
        *puStack_5c = FoxUI::FXUIEventI2::vftable;
        puStack_5c[5] = param_2;
        puStack_5c[6] = param_3;
      }
      local_40 = (undefined1 *)local_78;
      ppuStack_7c = (undefined1 **)0x0;
      local_64 = 7;
      local_68 = 0;
      local_80 = &DAT_00bed1fc;
      local_78[0] = 0;
      local_84 = 0x60178f;
      FUN_00402160();
      local_c = 6;
      ppuStack_7c = (undefined1 **)0x6017a5;
      FUN_008fed10();
      ppuStack_7c = (undefined1 **)0x6017b0;
      FUN_00412df0();
      local_c._0_1_ = 7;
      local_3c[0] = (undefined1 *)0xea;
      ppuStack_7c = (undefined1 **)0x6017d1;
      iVar3 = FUN_005854b0();
      ppuStack_7c = local_3c;
      local_80 = (undefined2 *)0x6017e3;
      FUN_005740f0();
      if (local_44 == *(undefined1 **)(iVar3 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      local_3c[0] = (undefined1 *)local_94;
      FUN_004ed610();
      local_c = CONCAT31(local_c._1_3_,8);
      FUN_0058b270(0xcf);
      if (7 < local_24) {
        puStack_5c = (undefined4 *)0x601834;
        FUN_0089120c();
      }
    }
    else {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_c = 3;
        FUN_00587480();
        puStack_5c = (undefined4 *)0x601642;
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_c = 0xffffffff;
      }
      puStack_5c = (undefined4 *)0x0;
      local_3c[0] = (undefined1 *)local_78;
      ppuStack_7c = (undefined1 **)0x0;
      local_64 = 7;
      local_68 = 0;
      local_80 = &DAT_00bed1fc;
      local_78[0] = 0;
      local_84 = 0x60166f;
      FUN_00402160();
      local_c = 4;
      local_44 = (undefined1 *)0xc;
      ppuStack_7c = (undefined1 **)0x601684;
      iVar3 = FUN_005854b0();
      ppuStack_7c = &local_44;
      local_80 = (undefined2 *)0x601696;
      FUN_005740f0();
      if (local_40 == *(undefined1 **)(iVar3 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      psVar5 = (short *)(local_40 + 0x10);
      if (7 < *(uint *)(local_40 + 0x24)) {
        psVar5 = *(short **)psVar5;
      }
      local_44 = (undefined1 *)local_94;
      local_80 = (undefined2 *)0x7;
      local_84 = 0;
      local_94[0] = 0;
      psVar4 = psVar5;
      do {
        sVar1 = *psVar4;
        psVar4 = psVar4 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar5,(int)psVar4 - (int)(psVar5 + 1) >> 1);
      local_c = 0xffffffff;
      FUN_0058b270(0xca);
    }
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_44);
  return;
}

