
void FUN_004064a0(undefined2 *param_1,undefined2 *param_2,undefined2 *param_3)

{
  short sVar1;
  code *pcVar2;
  int *piVar3;
  int iVar4;
  short *psVar5;
  undefined4 uVar6;
  int in_ECX;
  short *psVar7;
  undefined2 local_60 [8];
  undefined4 local_50;
  undefined2 *local_4c;
  undefined4 *puStack_48;
  undefined2 local_44 [8];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00931f6c;
  local_10 = ExceptionList;
  if ((char)param_1 == '\0') {
    iVar4 = *(int *)(in_ECX + 0x274) + -1;
    ExceptionList = &local_10;
    *(undefined1 *)(*(int *)(in_ECX + 0x274) + 0x254 + in_ECX) = 1;
    (**(code **)(**(int **)(*(int *)(in_ECX + ((iVar4 / 7 + 0xd) * 7 + iVar4 % 7) * 4) + 0x264) +
                0x94))();
    uStack_2c = 0x406518;
    piVar3 = (int *)FUN_00891268();
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3[1] = -1;
      piVar3[2] = -1;
      piVar3[6] = (int)param_2;
      piVar3[3] = 0;
      piVar3[4] = 0xf4324;
      *(undefined1 *)(piVar3 + 5) = 1;
      *piVar3 = (int)FoxUI::FXUIEventB1I2::vftable;
      piVar3[7] = (uint)param_3 & 0xff;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 0;
      FUN_0074d990();
      uStack_2c = 0x406570;
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 0xffffffff;
    }
    if (DAT_00f95bd4 != (int *)0x0) {
      uStack_2c = 0x40658f;
      (**(code **)(*DAT_00f95bd4 + 0x15c))();
    }
    if (piVar3 != (int *)0x0) {
      uStack_2c = 0x40659d;
      (**(code **)(*piVar3 + 0x10))();
    }
    uStack_2c = 0x4065a3;
    FUN_00406050();
    ExceptionList = local_10;
    return;
  }
  if ((char)param_1 == '\x01') {
    ExceptionList = &local_10;
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 1;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    param_2 = local_44;
    puStack_48 = (undefined4 *)0x0;
    local_30 = 7;
    local_34 = 0;
    local_4c = &DAT_00bed1fc;
    local_44[0] = 0;
    local_50 = 0x406610;
    FUN_00402160();
    local_8 = 2;
    param_1 = (undefined2 *)0x1cb;
    puStack_48 = (undefined4 *)0x406623;
    iVar4 = FUN_005854b0();
    puStack_48 = &param_1;
    local_4c = (undefined2 *)0x406633;
    FUN_005740f0();
    if (param_3 == (undefined2 *)*(undefined1 **)(iVar4 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar7 = (short *)((int)param_3 + 0x10);
    if (7 < *(uint *)((int)param_3 + 0x24)) {
      psVar7 = *(short **)psVar7;
    }
    param_1 = local_60;
    local_4c = (undefined2 *)0x7;
    local_50 = 0;
    local_60[0] = 0;
    psVar5 = psVar7;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar7,(int)psVar5 - (int)(psVar7 + 1) >> 1);
  }
  else {
    if ((char)param_1 != '\x02') {
      return;
    }
    ExceptionList = &local_10;
    FUN_004054c0();
    param_1 = local_44;
    puStack_48 = (undefined4 *)&DAT_00bed1fc;
    local_4c = (undefined2 *)0x4066a7;
    FUN_00402250();
    puStack_48 = (undefined4 *)0xd;
    local_8 = 3;
    local_4c = (undefined2 *)0x4066b5;
    FUN_005854b0();
    local_4c = (undefined2 *)0x4066bc;
    uVar6 = FUN_00585330();
    param_3 = local_60;
    FUN_00402250(uVar6);
  }
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
  ExceptionList = local_10;
  return;
}

