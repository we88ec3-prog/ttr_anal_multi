
void FUN_0047d810(int param_1,undefined2 *param_2)

{
  short sVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  short *psVar5;
  short *psVar6;
  undefined2 local_64 [8];
  undefined4 local_54;
  undefined2 *local_50;
  undefined4 *puStack_4c;
  undefined2 local_48;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 *puStack_2c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009491c2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_8 = 0;
    FUN_00539c20();
    puStack_2c = (undefined4 *)0x47d85c;
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  local_8 = 0xffffffff;
  if (DAT_00fb7258 != 0) {
    if ((*(int *)(DAT_00fb7258 + 0x2c) - *(int *)(DAT_00fb7258 + 0x28) & 0xfffffffcU) != 4) {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_8 = 1;
        FUN_00587480();
        puStack_2c = (undefined4 *)0x47d8aa;
        _atexit((_func_4879 *)&LAB_00bcccc0);
      }
      local_8 = 0xffffffff;
      puStack_2c = (undefined4 *)0x47d8b7;
      puVar3 = (undefined4 *)FUN_00891268();
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3[5] = 1;
        puVar3[1] = 0xffffffff;
        puVar3[2] = 0xffffffff;
        puVar3[3] = 0;
        puVar3[4] = 0xf4421;
        *puVar3 = FoxUI::FXUIEventI1::vftable;
      }
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        local_8 = 2;
        FUN_0074d990();
        puStack_2c = (undefined4 *)0x47d903;
        _atexit((_func_4879 *)&LAB_00bccc70);
        local_8 = 0xffffffff;
      }
      puStack_4c = (undefined4 *)0x0;
      local_34 = 7;
      local_38 = 0;
      local_50 = &DAT_00bed1fc;
      local_48 = 0;
      local_54 = 0x47d934;
      puStack_2c = puVar3;
      FUN_00402160();
      local_8 = 3;
      param_2 = (undefined2 *)0x177;
      puStack_4c = (undefined4 *)0x47d947;
      iVar4 = FUN_005854b0();
      puStack_4c = &param_2;
      local_50 = (undefined2 *)0x47d957;
      FUN_005740f0();
      if (param_1 == *(int *)(iVar4 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      psVar6 = (short *)(param_1 + 0x10);
      if (7 < *(uint *)(param_1 + 0x24)) {
        psVar6 = *(short **)psVar6;
      }
      param_2 = local_64;
      local_50 = (undefined2 *)0x7;
      local_54 = 0;
      local_64[0] = 0;
      psVar5 = psVar6;
      do {
        sVar1 = *psVar5;
        psVar5 = psVar5 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar6,(int)psVar5 - (int)(psVar6 + 1) >> 1);
      local_8 = 0xffffffff;
      FUN_0058b270(0xcf);
      ExceptionList = local_10;
      return;
    }
    puStack_2c = (undefined4 *)0x47d9d4;
    FUN_00539af0();
  }
  FUN_0047d530();
  ExceptionList = local_10;
  return;
}

