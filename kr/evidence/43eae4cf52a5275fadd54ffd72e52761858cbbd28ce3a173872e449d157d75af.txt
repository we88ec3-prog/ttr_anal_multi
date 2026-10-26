
void FUN_00544070(void)

{
  short sVar1;
  short sVar2;
  code *pcVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  uint uVar10;
  int in_ECX;
  undefined1 *puVar11;
  float10 fVar12;
  undefined1 auStack_74 [20];
  undefined4 uStack_60;
  undefined1 **ppuStack_5c;
  undefined1 auStack_58 [20];
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 *puStack_3c;
  float fStack_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00947804;
  local_14 = ExceptionList;
  sVar1 = *(short *)(in_ECX + 0xf4);
  if (sVar1 == 3) {
    ExceptionList = &local_14;
    piVar4 = (int *)(**(code **)(*DAT_00fba7a4 + 0x20))();
    if (piVar4 != (int *)0x0) {
      local_20 = (undefined1 *)((float)piVar4[0x28] - *(float *)(in_ECX + 0xa0));
      fStack_24 = (float)piVar4[0x29] - *(float *)(in_ECX + 0xa4);
      fVar12 = (float10)FUN_008fedca();
      iVar6 = *piVar4;
      local_20 = (undefined1 *)((float)fVar12 + 1.5707964);
      puStack_3c = (undefined4 *)0x544110;
      FUN_004bb450();
      puStack_3c = (undefined4 *)0x544120;
      (**(code **)(iVar6 + 0x58))();
    }
    puVar11 = (undefined1 *)(int)*(short *)(in_ECX + 0xf6);
    if ((DAT_00fab29c & 1) == 0) {
      DAT_00fab29c = DAT_00fab29c | 1;
      local_c = 0;
      FUN_004ffe60();
      puStack_3c = (undefined4 *)0x544151;
      _atexit((_func_4879 *)&LAB_00bccf00);
      local_c = 0xffffffff;
    }
    puStack_3c = &DAT_00fab2a0;
    uStack_40 = 0x544167;
    iVar5 = FUN_00500a80();
    iVar6 = DAT_00fe1bd0;
    if (iVar5 == 5) {
      iVar6 = FUN_00404ba0();
      iVar6 = *(int *)(iVar6 + 0x5f4c);
      if (((iVar6 != 3) && (iVar6 != 7)) && ((iVar6 != 0x17 && (iVar6 != 0x18)))) {
        ExceptionList = local_14;
        return;
      }
      iVar6 = FUN_0041a4d0();
      if ((*(int *)(iVar6 + 0x5ed8) != 0) && (iVar6 = FUN_00539a70(), iVar6 != 1)) {
        FUN_004054c0();
        puStack_3c = (undefined4 *)0x544239;
        puVar7 = (undefined4 *)FUN_00891268();
        puVar9 = (undefined4 *)0x0;
        if (puVar7 != (undefined4 *)0x0) {
          puVar7[3] = 0;
          puVar7[6] = 0;
          puVar7[1] = 0xffffffff;
          puVar7[2] = 0xffffffff;
          puVar7[4] = 0xf43d6;
          *puVar7 = FoxUI::FXUIEventI2::vftable;
          puVar7[5] = puVar11;
          puVar9 = puVar7;
        }
        FUN_00404aa0();
        local_20 = auStack_58;
        ppuStack_5c = (undefined1 **)&DAT_00bed1fc;
        uStack_60 = 0x544283;
        puStack_3c = puVar9;
        FUN_00402250();
        ppuStack_5c = (undefined1 **)0x20;
        local_c = 2;
        uStack_60 = 0x544292;
        FUN_005854b0();
        uStack_60 = 0x544299;
        uVar8 = FUN_00585330();
        FUN_00402250(uVar8);
        local_c = 0xffffffff;
        FUN_0058b270(0xcf);
        ExceptionList = local_14;
        return;
      }
      puStack_3c = (undefined4 *)0x5442d2;
      FUN_00539af0();
      FUN_004054c0();
      puStack_3c = (undefined4 *)0x5442de;
      puVar9 = (undefined4 *)FUN_00891268();
      if (puVar9 == (undefined4 *)0x0) {
        puVar9 = (undefined4 *)0x0;
      }
      else {
        sVar1 = *(short *)(in_ECX + 0xf6);
        sVar2 = *(short *)(in_ECX + 0xf4);
        puVar9[1] = 0xffffffff;
        puVar9[2] = 0xffffffff;
        puVar9[3] = 0;
        puVar9[4] = 0xf43d9;
        *puVar9 = FoxUI::FXUIEventI3::vftable;
        puVar9[5] = puVar11;
        puVar9[6] = (int)sVar2;
        puVar9[7] = (int)sVar1;
      }
      FUN_00404aa0();
      local_1c = auStack_58;
      ppuStack_5c = (undefined1 **)&DAT_00bed1fc;
      uStack_60 = 0x544348;
      puStack_3c = puVar9;
      FUN_00402250();
      local_c = 3;
      local_20 = (undefined1 *)0x21;
      ppuStack_5c = (undefined1 **)0x54435d;
      iVar6 = FUN_005854b0();
      ppuStack_5c = &local_20;
      uStack_60 = 0x54436f;
      FUN_005740f0();
      if (fStack_24 == *(float *)(iVar6 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      puVar9 = (undefined4 *)((int)fStack_24 + 0x10);
      if (7 < *(uint *)((int)fStack_24 + 0x24)) {
        puVar9 = (undefined4 *)*puVar9;
      }
      local_20 = auStack_74;
      FUN_00402250(puVar9);
      local_c = 0xffffffff;
      FUN_0058b270(0xcf);
      ExceptionList = local_14;
      return;
    }
    puStack_3c = (undefined4 *)0x544187;
    local_20 = puVar11;
    FUN_008438c0();
    if (fStack_24 == *(float *)(iVar6 + 0xc)) {
      ExceptionList = local_14;
      return;
    }
    iVar6 = *(int *)((int)fStack_24 + 0x10);
    if (iVar6 == 0) {
      ExceptionList = local_14;
      return;
    }
    if (*(int *)(iVar6 + 0x40) == *(int *)(iVar6 + 0x44)) {
      ExceptionList = local_14;
      return;
    }
    puStack_3c = (undefined4 *)0x5441b4;
    local_20 = (undefined1 *)FUN_00891268();
    local_c = 1;
    if (local_20 != (undefined1 *)0x0) {
      FUN_0040f060();
      puStack_3c = (undefined4 *)0x5441e2;
      local_20 = (undefined1 *)FUN_00753f80();
      goto LAB_005444f5;
    }
  }
  else {
    if (sVar1 == 4) {
      if (DAT_00fba7ac != 4) {
        return;
      }
      DAT_00fba7a4[*(short *)(in_ECX + 0xf6) + 0x2d] = 1;
      return;
    }
    if (sVar1 == 5) {
      ExceptionList = &local_14;
      iVar6 = FUN_00404ba0();
      if (*(int *)(iVar6 + 0x5f4c) != 3) {
        ExceptionList = local_14;
        return;
      }
      iVar6 = FUN_0040f060();
      if (*(int *)(iVar6 + 0xf8) == 0) {
        ExceptionList = local_14;
        return;
      }
      if (*(char *)(*(int *)(iVar6 + 0xf8) + 0x28) == '\0') {
        FUN_00414680();
        FUN_004a35c0();
        ExceptionList = local_14;
        return;
      }
      FUN_00423240();
      FUN_00516fa0();
      FUN_00414680();
      FUN_004a35f0();
      ExceptionList = local_14;
      return;
    }
    if (sVar1 != 2) {
      ExceptionList = &local_14;
      iVar6 = FUN_00404ba0();
      if ((*(int *)(iVar6 + 0x5f4c) - 0x17U < 2) &&
         (iVar6 = FUN_0041a4d0(), *(int *)(iVar6 + 0x5ed8) != 0)) {
        FUN_00404ba0();
        puStack_3c = (undefined4 *)0x544566;
        iVar6 = FUN_00539aa0();
        uVar10 = FUN_00539a70();
        if (((iVar6 != 0) && (*(char *)(iVar6 + 6) == '\0')) ||
           (iVar5 = FUN_00404ba0(), *(int *)(iVar5 + 0x5f4c) == 5)) {
          FUN_004054c0();
          puStack_3c = (undefined4 *)0x544599;
          iVar6 = FUN_00891268();
          if (iVar6 == 0) {
            uVar8 = 0;
          }
          else {
            puStack_3c = (undefined4 *)0xf4395;
            uStack_40 = 0x5445bf;
            uVar8 = FUN_00753e00();
          }
          FUN_00404aa0();
          uStack_40 = 0x196;
          uStack_44 = 0x5445dc;
          puStack_3c = (undefined4 *)uVar8;
          FUN_005854b0();
          uStack_44 = 0x5445e3;
          ppuStack_5c = (undefined1 **)FUN_00585330();
          local_1c = auStack_58;
          uStack_60 = 0x5445f2;
          FUN_00402250();
          ppuStack_5c = (undefined1 **)0x3b;
          local_c = 5;
          uStack_60 = 0x544601;
          FUN_005854b0();
          uStack_60 = 0x544608;
          uVar8 = FUN_00585330();
          local_20 = auStack_74;
          FUN_00402250(uVar8);
          local_c = 0xffffffff;
          FUN_0058b270(0xcf);
          ExceptionList = local_14;
          return;
        }
        if (((iVar6 != 0) && (*(char *)(iVar6 + 6) != '\0')) && (1 < uVar10)) {
          FUN_004054c0();
          puStack_3c = (undefined4 *)0x544666;
          iVar6 = FUN_00891268();
          if (iVar6 == 0) {
            uVar8 = 0;
          }
          else {
            puStack_3c = (undefined4 *)0xf4395;
            uStack_40 = 0x54468c;
            uVar8 = FUN_00753e00();
          }
          FUN_00404aa0();
          uStack_40 = 0x196;
          uStack_44 = 0x5446a9;
          puStack_3c = (undefined4 *)uVar8;
          FUN_005854b0();
          uStack_44 = 0x5446b0;
          ppuStack_5c = (undefined1 **)FUN_00585330();
          local_1c = auStack_58;
          uStack_60 = 0x5446bf;
          FUN_00402250();
          ppuStack_5c = (undefined1 **)0x31;
          local_c = 6;
          uStack_60 = 0x5446ce;
          FUN_005854b0();
          uStack_60 = 0x5446d5;
          uVar8 = FUN_00585330();
          local_20 = auStack_74;
          FUN_00402250(uVar8);
          local_c = 0xffffffff;
          FUN_0058b270(0xcf);
          ExceptionList = local_14;
          return;
        }
      }
      FUN_00544020();
      ExceptionList = local_14;
      return;
    }
    ExceptionList = &local_14;
    iVar6 = FUN_004fb910();
    if (iVar6 == 0) {
      ExceptionList = local_14;
      return;
    }
    puStack_3c = (undefined4 *)0x5444af;
    iVar6 = FUN_00527010();
    if (iVar6 == 0) {
      ExceptionList = local_14;
      return;
    }
    if (*(int *)(iVar6 + 0x40) == *(int *)(iVar6 + 0x44)) {
      ExceptionList = local_14;
      return;
    }
    puStack_3c = (undefined4 *)0x5444ca;
    local_1c = (undefined1 *)FUN_00891268();
    local_c = 4;
    if (local_1c != (undefined1 *)0x0) {
      FUN_0040f060();
      puStack_3c = (undefined4 *)0x5444f1;
      local_20 = (undefined1 *)FUN_00753f80();
      goto LAB_005444f5;
    }
  }
  local_20 = (undefined1 *)0x0;
LAB_005444f5:
  local_c = 0xffffffff;
  FUN_00404aa0();
  puStack_3c = (undefined4 *)0x544516;
  FUN_00804260();
  ExceptionList = local_14;
  return;
}

