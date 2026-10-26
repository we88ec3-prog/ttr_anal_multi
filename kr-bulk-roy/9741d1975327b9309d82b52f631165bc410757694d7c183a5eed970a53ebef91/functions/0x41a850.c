
void FUN_0041a850(int param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *in_ECX;
  uint uVar6;
  undefined1 auStack_84 [20];
  undefined4 uStack_70;
  undefined1 **ppuStack_6c;
  undefined4 uStack_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  undefined4 local_54;
  int *local_50;
  undefined4 *local_4c;
  int local_34;
  undefined1 *local_30;
  undefined1 *local_2c;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00948130;
  local_14 = ExceptionList;
  uVar6 = *(uint *)(param_1 + 0x10);
  if (0x70b < uVar6) {
    if (uVar6 == 0xf4393) {
      ExceptionList = &local_14;
      FUN_0041ae60();
      ExceptionList = local_14;
      return;
    }
    if (uVar6 != 0xf443e) {
      return;
    }
    ExceptionList = &local_14;
    iVar3 = FUN_004068c0();
    if (*(int *)(iVar3 + 0x14) != 0x6a7) {
      ExceptionList = local_14;
      return;
    }
    FUN_00414680();
    local_4c = (undefined4 *)0x41ae27;
    FUN_004a3f80();
    FUN_0064b090();
    ExceptionList = local_14;
    return;
  }
  if (uVar6 == 0x70b) {
    local_4c = (undefined4 *)in_ECX[0x3e];
    local_50 = (int *)0x41ad92;
    ExceptionList = &local_14;
    puVar4 = (undefined4 *)FUN_0041cdc0();
    local_54 = *puVar4;
    local_50 = (int *)puVar4[1];
    local_4c = (undefined4 *)puVar4[2];
    local_60 = in_ECX[3];
    local_64 = in_ECX[2];
    local_5c = in_ECX[4];
    local_58 = in_ECX[5];
    uStack_68 = 0x41add6;
    FUN_0064ba50();
    local_4c = (undefined4 *)in_ECX[0x3e];
    local_50 = (int *)0x41ade3;
    FUN_0041cb90();
    ExceptionList = local_14;
    return;
  }
  if (uVar6 != 0x578) {
    if (uVar6 != 0x70a) {
      return;
    }
    local_4c = (undefined4 *)0x41a8e8;
    ExceptionList = &local_14;
    FUN_0041ce80();
    local_4c = (undefined4 *)0x41a8f4;
    FUN_00690fa0();
    ExceptionList = local_14;
    return;
  }
  iVar3 = *(int *)(param_1 + 8);
  if (iVar3 == *(int *)(in_ECX[0x41] + 0x20)) {
    ExceptionList = &local_14;
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590();
      local_4c = (undefined4 *)0x41a948;
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    if (DAT_00f9392c == 7) {
      (**(code **)(*in_ECX + 0xd4))();
      ExceptionList = local_14;
      return;
    }
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590();
      local_4c = (undefined4 *)0x41a9a3;
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    if ((DAT_00fb1378 & 1) == 0) {
      DAT_00fb1378 = DAT_00fb1378 | 1;
      local_c = 2;
      FUN_00539c20();
      local_4c = (undefined4 *)0x41a9d0;
      _atexit((_func_4879 *)&LAB_00bccfb0);
    }
    iVar3 = DAT_00fb7258;
    local_c = 0xffffffff;
    if (DAT_00fb7258 == 0) {
LAB_0041abb5:
      local_4c = (undefined4 *)0x41abbc;
      piVar5 = (int *)FUN_00891268();
      if (piVar5 == (int *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5[1] = -1;
        piVar5[2] = -1;
        piVar5[3] = 0;
        piVar5[4] = 0xf4392;
        *piVar5 = (int)FoxUI::FXUIEventI2::vftable;
        piVar5[5] = 0;
        piVar5[6] = 0;
      }
      iVar3 = FUN_00404aa0();
      if (*(int **)(iVar3 + 0x13c4) != (int *)0x0) {
        local_4c = (undefined4 *)0x41ac01;
        (**(code **)(**(int **)(iVar3 + 0x13c4) + 0x15c))();
      }
      if (piVar5 == (int *)0x0) {
        ExceptionList = local_14;
        return;
      }
      local_4c = (undefined4 *)0x41ac14;
      (**(code **)(*piVar5 + 0x10))();
      ExceptionList = pvStack_18;
      return;
    }
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 3;
      FUN_004e1590();
      local_4c = (undefined4 *)0x41aa0c;
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    local_4c = (undefined4 *)0x41aa20;
    iVar2 = FUN_00539aa0();
    piVar5 = *(int **)(iVar3 + 0x28);
    uVar6 = 0;
    for (iVar3 = *(int *)(iVar3 + 0x2c) - (int)piVar5 >> 2; iVar3 != 0; iVar3 = iVar3 + -1) {
      if (*(char *)(*piVar5 + 10) != '\0') {
        uVar6 = uVar6 + 1;
      }
      piVar5 = piVar5 + 1;
    }
    if (((iVar2 != 0) && (*(char *)(iVar2 + 6) == '\0')) ||
       (iVar3 = FUN_00404ba0(), *(int *)(iVar3 + 0x5f4c) == 5)) {
      FUN_004054c0();
      local_4c = (undefined4 *)0x41aa6c;
      local_4c = (undefined4 *)FUN_00891268();
      if (local_4c == (undefined4 *)0x0) {
        local_4c = (undefined4 *)0x0;
      }
      else {
        local_4c[1] = 0xffffffff;
        local_4c[2] = 0xffffffff;
        local_4c[3] = 0;
        local_4c[4] = 0xf4393;
        *local_4c = FoxUI::FXUIEventI1::vftable;
        local_4c[5] = 0;
      }
      local_34 = 0x196;
      local_50 = (int *)0x41aaa7;
      iVar3 = FUN_005854b0();
      local_50 = &local_34;
      local_54 = 0x41aab9;
      FUN_005740f0();
      if (local_30 == *(undefined1 **)(iVar3 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      ppuStack_6c = (undefined1 **)(local_30 + 0x10);
      if (7 < *(uint *)(local_30 + 0x24)) {
        ppuStack_6c = (undefined1 **)*ppuStack_6c;
      }
      local_2c = (undefined1 *)&uStack_68;
      uStack_70 = 0x41aaea;
      FUN_00402250();
      local_c = 4;
      local_30 = (undefined1 *)0x3b;
      ppuStack_6c = (undefined1 **)0x41aaff;
      iVar3 = FUN_005854b0();
      ppuStack_6c = &local_30;
      uStack_70 = 0x41ab11;
      FUN_005740f0();
      if (local_34 == *(int *)(iVar3 + 4)) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      puVar4 = (undefined4 *)(local_34 + 0x10);
      if (7 < *(uint *)(local_34 + 0x24)) {
        puVar4 = (undefined4 *)*puVar4;
      }
      goto LAB_0041ad0c;
    }
    if (((iVar2 == 0) || (*(char *)(iVar2 + 6) == '\0')) || (uVar6 < 2)) goto LAB_0041abb5;
    FUN_004054c0();
    local_4c = (undefined4 *)0x41ab55;
    local_4c = (undefined4 *)FUN_00891268();
    if (local_4c == (undefined4 *)0x0) {
      local_4c = (undefined4 *)0x0;
    }
    else {
      local_4c[1] = 0xffffffff;
      local_4c[2] = 0xffffffff;
      local_4c[3] = 0;
      local_4c[4] = 0xf4393;
      *local_4c = FoxUI::FXUIEventI1::vftable;
      local_4c[5] = 0;
    }
    local_50 = (int *)0x196;
    local_54 = 0x41ab8d;
    FUN_005854b0();
    local_54 = 0x41ab94;
    ppuStack_6c = (undefined1 **)FUN_00585330();
    local_2c = (undefined1 *)&uStack_68;
    uStack_70 = 0x41aba3;
    FUN_00402250();
    local_c = 5;
    ppuStack_6c = (undefined1 **)0x31;
  }
  else {
    if (iVar3 == *(int *)(in_ECX[0x44] + 0x20)) {
      local_4c = (undefined4 *)0x41ac3a;
      ExceptionList = &local_14;
      FUN_0041b1b0();
      ExceptionList = local_14;
      return;
    }
    if (*(int *)(in_ECX[0x42] + 0x20) == iVar3) {
      local_50 = (int *)0x41ac62;
      ExceptionList = &local_14;
      FUN_0064a360();
      ExceptionList = local_14;
      return;
    }
    if (*(int *)(in_ECX[0x45] + 0x20) != iVar3) {
      return;
    }
    ExceptionList = &local_14;
    iVar3 = FUN_0041a4d0();
    if ((*(int *)(iVar3 + 0x5ed8) == 0) || (iVar3 = FUN_00539a70(), iVar3 == 1)) {
      local_4c = (undefined4 *)0x41ad47;
      FUN_00539af0();
      FUN_0064b090();
      ExceptionList = local_14;
      return;
    }
    FUN_004054c0();
    local_4c = (undefined4 *)0x41acb5;
    local_4c = (undefined4 *)FUN_00891268();
    if (local_4c == (undefined4 *)0x0) {
      local_4c = (undefined4 *)0x0;
    }
    else {
      local_4c[1] = 0xffffffff;
      local_4c[2] = 0xffffffff;
      local_4c[3] = 0;
      local_4c[4] = 0xf443e;
      *local_4c = FoxUI::FXUIEventI1::vftable;
      local_4c[5] = 0;
    }
    local_2c = (undefined1 *)&uStack_68;
    ppuStack_6c = (undefined1 **)&DAT_00bed1fc;
    uStack_70 = 0x41acf6;
    FUN_00402250();
    local_c = 6;
    ppuStack_6c = (undefined1 **)&DAT_00000025;
  }
  uStack_70 = 0x41ad05;
  FUN_005854b0();
  uStack_70 = 0x41ad0c;
  puVar4 = (undefined4 *)FUN_00585330();
LAB_0041ad0c:
  local_30 = auStack_84;
  FUN_00402250(puVar4);
  local_c = 0xffffffff;
  FUN_0058b270(0xcf);
  ExceptionList = local_14;
  return;
}

