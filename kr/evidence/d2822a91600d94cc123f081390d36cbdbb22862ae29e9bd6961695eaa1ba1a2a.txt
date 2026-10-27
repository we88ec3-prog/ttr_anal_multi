
void FUN_0064a360(int *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  undefined1 auStack_74 [20];
  undefined4 uStack_60;
  undefined1 **ppuStack_5c;
  undefined1 auStack_58 [20];
  undefined4 uStack_44;
  int *piStack_40;
  undefined4 *puStack_3c;
  int local_24;
  undefined1 *local_20;
  undefined1 *local_1c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00942f08;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    puStack_3c = (undefined4 *)0x64a3b3;
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if ((DAT_00f9392c != 7) || (param_2 != 0)) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590();
      puStack_3c = (undefined4 *)0x64a414;
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    if ((DAT_00f9392c != 0x17) || (param_2 != 1)) {
      if ((DAT_00fb1378 & 1) == 0) {
        DAT_00fb1378 = DAT_00fb1378 | 1;
        local_c = 2;
        FUN_00539c20();
        puStack_3c = (undefined4 *)0x64a44f;
        _atexit((_func_4879 *)&LAB_00bccfb0);
      }
      iVar3 = DAT_00fb7258;
      local_c = 0xffffffff;
      if (DAT_00fb7258 != 0) {
        if ((DAT_00f94390 & 1) == 0) {
          DAT_00f94390 = DAT_00f94390 | 1;
          local_c = 3;
          FUN_004e1590();
          puStack_3c = (undefined4 *)0x64a48b;
          _atexit((_func_4879 *)&LAB_00bccc80);
        }
        local_c = 0xffffffff;
        puStack_3c = (undefined4 *)0x64a49f;
        iVar2 = FUN_00539aa0();
        piVar6 = *(int **)(iVar3 + 0x28);
        uVar7 = 0;
        for (iVar3 = *(int *)(iVar3 + 0x2c) - (int)piVar6 >> 2; iVar3 != 0; iVar3 = iVar3 + -1) {
          if (*(char *)(*piVar6 + 10) != '\0') {
            uVar7 = uVar7 + 1;
          }
          piVar6 = piVar6 + 1;
        }
        if (((iVar2 != 0) && (*(char *)(iVar2 + 6) == '\0')) ||
           (iVar3 = FUN_00404ba0(), *(int *)(iVar3 + 0x5f4c) == 5)) {
          FUN_004054c0();
          puStack_3c = (undefined4 *)0x64a4e9;
          puStack_3c = (undefined4 *)FUN_00891268();
          if (puStack_3c == (undefined4 *)0x0) {
            puStack_3c = (undefined4 *)0x0;
          }
          else {
            puStack_3c[1] = 0xffffffff;
            puStack_3c[2] = 0xffffffff;
            puStack_3c[3] = 0;
            puStack_3c[4] = 0xf4393;
            *puStack_3c = FoxUI::FXUIEventI1::vftable;
            puStack_3c[5] = param_2;
          }
          local_24 = 0x196;
          piStack_40 = (int *)0x64a525;
          iVar3 = FUN_005854b0();
          piStack_40 = &local_24;
          uStack_44 = 0x64a537;
          FUN_005740f0();
          if (local_20 != *(undefined1 **)(iVar3 + 4)) {
            ppuStack_5c = (undefined1 **)(local_20 + 0x10);
            if (7 < *(uint *)(local_20 + 0x24)) {
              ppuStack_5c = (undefined1 **)*ppuStack_5c;
            }
            local_1c = auStack_58;
            uStack_60 = 0x64a568;
            FUN_00402250();
            local_c = 4;
            local_20 = (undefined1 *)0x3b;
            ppuStack_5c = (undefined1 **)0x64a57d;
            iVar3 = FUN_005854b0();
            ppuStack_5c = &local_20;
            uStack_60 = 0x64a58f;
            FUN_005740f0();
            if (local_24 != *(int *)(iVar3 + 4)) {
              puVar4 = (undefined4 *)(local_24 + 0x10);
              if (7 < *(uint *)(local_24 + 0x24)) {
                puVar4 = (undefined4 *)*puVar4;
              }
              local_20 = auStack_74;
              FUN_00402250(puVar4);
              local_c = 0xffffffff;
              FUN_0058b270(0xcf);
              ExceptionList = local_14;
              return;
            }
            pcVar1 = (code *)swi(3);
            (*pcVar1)();
            return;
          }
          pcVar1 = (code *)swi(3);
          (*pcVar1)();
          return;
        }
        if (((iVar2 != 0) && (*(char *)(iVar2 + 6) != '\0')) && (1 < uVar7)) {
          FUN_004054c0();
          puStack_3c = (undefined4 *)0x64a60b;
          puStack_3c = (undefined4 *)FUN_00891268();
          if (puStack_3c == (undefined4 *)0x0) {
            puStack_3c = (undefined4 *)0x0;
          }
          else {
            puStack_3c[1] = 0xffffffff;
            puStack_3c[2] = 0xffffffff;
            puStack_3c[3] = 0;
            puStack_3c[4] = 0xf4393;
            *puStack_3c = FoxUI::FXUIEventI1::vftable;
            puStack_3c[5] = param_2;
          }
          piStack_40 = (int *)0x196;
          uStack_44 = 0x64a647;
          FUN_005854b0();
          uStack_44 = 0x64a64e;
          ppuStack_5c = (undefined1 **)FUN_00585330();
          local_1c = auStack_58;
          uStack_60 = 0x64a65d;
          FUN_00402250();
          ppuStack_5c = (undefined1 **)0x31;
          local_c = 5;
          uStack_60 = 0x64a66c;
          FUN_005854b0();
          uStack_60 = 0x64a673;
          uVar5 = FUN_00585330();
          local_20 = auStack_74;
          FUN_00402250(uVar5);
          local_c = 0xffffffff;
          FUN_0058b270(0xcf);
          ExceptionList = local_14;
          return;
        }
      }
      if (param_2 == 0) {
        puStack_3c = (undefined4 *)0x64a6b9;
        piVar6 = (int *)FUN_00891268();
        if (piVar6 == (int *)0x0) {
          piVar6 = (int *)0x0;
        }
        else {
          piVar6[1] = -1;
          piVar6[2] = -1;
          piVar6[3] = 0;
          piVar6[4] = 0xf4392;
          *piVar6 = (int)FoxUI::FXUIEventI2::vftable;
          piVar6[5] = 0;
          piVar6[6] = 0;
        }
        iVar3 = FUN_00404aa0();
        if (*(int **)(iVar3 + 0x13c4) != (int *)0x0) {
          puStack_3c = (undefined4 *)0x64a6fc;
          (**(code **)(**(int **)(iVar3 + 0x13c4) + 0x15c))();
        }
        if (piVar6 != (int *)0x0) {
          puStack_3c = (undefined4 *)0x64a70b;
          (**(code **)(*piVar6 + 0x10))();
          ExceptionList = pvStack_18;
          return;
        }
      }
      else if (param_2 == 1) {
        puStack_3c = (undefined4 *)0x64a72c;
        puVar4 = (undefined4 *)FUN_00891268();
        if (puVar4 != (undefined4 *)0x0) {
          puVar4[1] = 0xffffffff;
          puVar4[2] = 0xffffffff;
          puVar4[3] = 0;
          puVar4[4] = 0xf4394;
          *puVar4 = FoxUI::FXUIEventI2::vftable;
          puVar4[5] = 0;
          puVar4[6] = 2;
        }
        FUN_00404aa0();
        FUN_00750020();
      }
      ExceptionList = local_14;
      return;
    }
  }
  local_c = 0xffffffff;
  (**(code **)(*param_1 + 0xd4))();
  ExceptionList = local_14;
  return;
}

