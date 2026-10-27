
void FUN_00649d50(int param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int *piVar6;
  int *in_ECX;
  uint uVar7;
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
  uVar7 = *(uint *)(param_1 + 0x10);
  if (0x70b < uVar7) {
    if (uVar7 == 0xf4393) {
      ExceptionList = &local_14;
      FUN_0041ae60();
      ExceptionList = local_14;
      return;
    }
    if (uVar7 != 0xf443e) {
      return;
    }
    ExceptionList = &local_14;
    iVar4 = FUN_004068c0();
    if (*(int *)(iVar4 + 0x14) != 0x6a7) {
      ExceptionList = local_14;
      return;
    }
    FUN_00414680();
    local_4c = (undefined4 *)0x64a327;
    FUN_004a3f80();
    FUN_0064b090();
    ExceptionList = local_14;
    return;
  }
  if (uVar7 == 0x70b) {
    if (*(int *)(in_ECX[0x43] + 0xcc) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(*(int *)(in_ECX[0x43] + 0xcc) + 0xdc);
    }
    uVar1 = *(undefined4 *)(iVar4 + 0x25c);
    local_4c = (undefined4 *)0x64a293;
    ExceptionList = &local_14;
    puVar5 = (undefined4 *)FUN_00649120();
    local_54 = *puVar5;
    local_50 = (int *)puVar5[1];
    local_4c = (undefined4 *)puVar5[2];
    local_60 = in_ECX[3];
    local_64 = in_ECX[2];
    local_5c = in_ECX[4];
    local_58 = in_ECX[5];
    uStack_68 = 0x64a2d7;
    FUN_0064ba50();
    *(undefined4 *)(in_ECX[0x3e] + 0xd8) = uVar1;
    ExceptionList = local_14;
    return;
  }
  if (uVar7 != 0x578) {
    if (uVar7 != 0x70a) {
      return;
    }
    local_4c = (undefined4 *)0x649de8;
    ExceptionList = &local_14;
    FUN_0041ce80();
    local_4c = (undefined4 *)0x649df4;
    FUN_00690fa0();
    ExceptionList = local_14;
    return;
  }
  iVar4 = *(int *)(param_1 + 8);
  if (iVar4 == *(int *)(in_ECX[0x3f] + 0x20)) {
    ExceptionList = &local_14;
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590();
      local_4c = (undefined4 *)0x649e48;
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
      local_4c = (undefined4 *)0x649ea3;
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    if ((DAT_00fb1378 & 1) == 0) {
      DAT_00fb1378 = DAT_00fb1378 | 1;
      local_c = 2;
      FUN_00539c20();
      local_4c = (undefined4 *)0x649ed0;
      _atexit((_func_4879 *)&LAB_00bccfb0);
    }
    iVar4 = DAT_00fb7258;
    local_c = 0xffffffff;
    if (DAT_00fb7258 == 0) {
LAB_0064a0b5:
      local_4c = (undefined4 *)0x64a0bc;
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
      iVar4 = FUN_00404aa0();
      if (*(int **)(iVar4 + 0x13c4) != (int *)0x0) {
        local_4c = (undefined4 *)0x64a101;
        (**(code **)(**(int **)(iVar4 + 0x13c4) + 0x15c))();
      }
      if (piVar6 == (int *)0x0) {
        ExceptionList = local_14;
        return;
      }
      local_4c = (undefined4 *)0x64a114;
      (**(code **)(*piVar6 + 0x10))();
      ExceptionList = pvStack_18;
      return;
    }
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 3;
      FUN_004e1590();
      local_4c = (undefined4 *)0x649f0c;
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    local_4c = (undefined4 *)0x649f20;
    iVar3 = FUN_00539aa0();
    piVar6 = *(int **)(iVar4 + 0x28);
    uVar7 = 0;
    for (iVar4 = *(int *)(iVar4 + 0x2c) - (int)piVar6 >> 2; iVar4 != 0; iVar4 = iVar4 + -1) {
      if (*(char *)(*piVar6 + 10) != '\0') {
        uVar7 = uVar7 + 1;
      }
      piVar6 = piVar6 + 1;
    }
    if (((iVar3 != 0) && (*(char *)(iVar3 + 6) == '\0')) ||
       (iVar4 = FUN_00404ba0(), *(int *)(iVar4 + 0x5f4c) == 5)) {
      FUN_004054c0();
      local_4c = (undefined4 *)0x649f6c;
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
      local_50 = (int *)0x649fa7;
      iVar4 = FUN_005854b0();
      local_50 = &local_34;
      local_54 = 0x649fb9;
      FUN_005740f0();
      if (local_30 == *(undefined1 **)(iVar4 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      ppuStack_6c = (undefined1 **)(local_30 + 0x10);
      if (7 < *(uint *)(local_30 + 0x24)) {
        ppuStack_6c = (undefined1 **)*ppuStack_6c;
      }
      local_2c = (undefined1 *)&uStack_68;
      uStack_70 = 0x649fea;
      FUN_00402250();
      local_c = 4;
      local_30 = (undefined1 *)0x3b;
      ppuStack_6c = (undefined1 **)0x649fff;
      iVar4 = FUN_005854b0();
      ppuStack_6c = &local_30;
      uStack_70 = 0x64a011;
      FUN_005740f0();
      if (local_34 == *(int *)(iVar4 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      puVar5 = (undefined4 *)(local_34 + 0x10);
      if (7 < *(uint *)(local_34 + 0x24)) {
        puVar5 = (undefined4 *)*puVar5;
      }
      goto LAB_0064a20c;
    }
    if (((iVar3 == 0) || (*(char *)(iVar3 + 6) == '\0')) || (uVar7 < 2)) goto LAB_0064a0b5;
    FUN_004054c0();
    local_4c = (undefined4 *)0x64a055;
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
    local_54 = 0x64a08d;
    FUN_005854b0();
    local_54 = 0x64a094;
    ppuStack_6c = (undefined1 **)FUN_00585330();
    local_2c = (undefined1 *)&uStack_68;
    uStack_70 = 0x64a0a3;
    FUN_00402250();
    local_c = 5;
    ppuStack_6c = (undefined1 **)0x31;
  }
  else {
    if (iVar4 == *(int *)(in_ECX[0x42] + 0x20)) {
      local_4c = (undefined4 *)0x64a13a;
      ExceptionList = &local_14;
      FUN_0064ac50();
      ExceptionList = local_14;
      return;
    }
    if (*(int *)(in_ECX[0x40] + 0x20) == iVar4) {
      local_50 = (int *)0x64a162;
      ExceptionList = &local_14;
      FUN_0064a360();
      ExceptionList = local_14;
      return;
    }
    if (*(int *)(in_ECX[0x49] + 0x20) != iVar4) {
      return;
    }
    ExceptionList = &local_14;
    iVar4 = FUN_0041a4d0();
    if ((*(int *)(iVar4 + 0x5ed8) == 0) || (iVar4 = FUN_00539a70(), iVar4 == 1)) {
      local_4c = (undefined4 *)0x64a247;
      FUN_00539af0();
      FUN_0064b090();
      ExceptionList = local_14;
      return;
    }
    FUN_004054c0();
    local_4c = (undefined4 *)0x64a1b5;
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
    uStack_70 = 0x64a1f6;
    FUN_00402250();
    local_c = 6;
    ppuStack_6c = (undefined1 **)&DAT_00000025;
  }
  uStack_70 = 0x64a205;
  FUN_005854b0();
  uStack_70 = 0x64a20c;
  puVar5 = (undefined4 *)FUN_00585330();
LAB_0064a20c:
  local_30 = auStack_84;
  FUN_00402250(puVar5);
  local_c = 0xffffffff;
  FUN_0058b270(0xcf);
  ExceptionList = local_14;
  return;
}

