
void FUN_0069fd30(int param_1)

{
  short sVar1;
  int iVar2;
  undefined1 *puVar3;
  code *pcVar4;
  int iVar5;
  byte bVar6;
  short *psVar7;
  short *psVar8;
  undefined *local_5c;
  undefined1 *puStack_58;
  undefined2 local_54 [4];
  undefined4 local_4c;
  undefined4 local_48;
  undefined *local_44;
  undefined4 *local_40;
  undefined1 local_24 [12];
  undefined1 *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  iVar5 = param_1;
  puStack_c = &LAB_009329b6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe1bd8 & 1) == 0) {
    DAT_00fe1bd8 = DAT_00fe1bd8 | 1;
    local_8 = 0;
    FUN_00533f80();
    local_40 = (undefined4 *)0x69fd85;
    _atexit((_func_4879 *)&LAB_00bced30);
    if ((DAT_00fe1bd8 & 1) == 0) {
      DAT_00fe1bd8 = DAT_00fe1bd8 | 1;
      local_8 = 1;
      FUN_00533f80();
      local_40 = (undefined4 *)0x69fdb0;
      _atexit((_func_4879 *)&LAB_00bced30);
    }
  }
  local_8 = 0xffffffff;
  FUN_005341e0();
  local_8._0_1_ = 2;
  local_8._1_3_ = 0;
  iVar2 = *(int *)(param_1 + 0x154);
  param_1._3_1_ = 0;
  if (iVar2 == 0) {
    local_40 = (undefined4 *)0x69fe52;
    param_1._3_1_ = FUN_00538770();
  }
  else if (iVar2 == 1) {
    local_40 = *(undefined4 **)(iVar5 + 0x148);
    local_44 = (undefined *)0x69fe3c;
    param_1._3_1_ = FUN_005387c0();
  }
  else if (iVar2 == 2) {
    puVar3 = *(undefined1 **)(iVar5 + 0x148);
    local_40 = (undefined4 *)&DAT_00fe1bec;
    local_44 = (undefined *)0x69fe06;
    FUN_00537df0();
    local_40 = (undefined4 *)local_24;
    local_44 = (undefined *)0x69fe10;
    FUN_00538270();
    local_44 = (undefined *)0x69fe1f;
    local_40 = (undefined4 *)puVar3;
    param_1._3_1_ = FUN_005387c0();
  }
  iVar2 = *(int *)(iVar5 + 0x10c);
  if (*(char *)(iVar2 + 0x141) != '\0') {
    local_40 = (undefined4 *)0x69fe6e;
    FUN_006edb10();
  }
  if (*(int *)(iVar2 + 0x118) != 0) {
    if (*(char *)(*(int *)(iVar5 + 0x10c) + 0x141) != '\0') {
      local_40 = (undefined4 *)0x69fe93;
      FUN_006edb10();
    }
    local_40 = (undefined4 *)0x69fead;
    FUN_008935e3();
    local_40 = (undefined4 *)local_24;
    local_44 = &DAT_00fe1bec;
    local_48 = 0x69febf;
    bVar6 = FUN_00538a40();
    param_1._3_1_ = param_1._3_1_ | bVar6;
  }
  iVar2 = *(int *)(iVar5 + 0x110);
  if (*(char *)(iVar2 + 0x141) != '\0') {
    local_40 = (undefined4 *)0x69fedb;
    FUN_006edb10();
  }
  if (*(int *)(iVar2 + 0x118) != 0) {
    if (*(char *)(*(int *)(iVar5 + 0x110) + 0x141) != '\0') {
      local_40 = (undefined4 *)0x69ff00;
      FUN_006edb10();
    }
    local_40 = (undefined4 *)0x69ff1a;
    FUN_008935e3();
    local_40 = (undefined4 *)local_24;
    local_44 = &DAT_00fe1bec;
    local_48 = 0x69ff2c;
    bVar6 = FUN_00538c50();
    param_1._3_1_ = param_1._3_1_ | bVar6;
  }
  iVar2 = *(int *)(iVar5 + 0x108);
  if (*(char *)(iVar2 + 0x141) != '\0') {
    local_40 = (undefined4 *)0x69ff48;
    FUN_006edb10();
  }
  if (*(int *)(iVar2 + 0x118) != 0) {
    if (*(char *)(*(int *)(iVar5 + 0x108) + 0x141) != '\0') {
      local_40 = (undefined4 *)0x69ff72;
      FUN_006edb10();
    }
    local_14 = (undefined1 *)local_54;
    puStack_58 = (undefined1 *)0xffffffff;
    local_5c = (undefined *)0x0;
    local_40 = (undefined4 *)0x7;
    local_44 = (undefined *)0x0;
    local_54[0] = 0;
    FUN_004026e0();
    puStack_58 = local_24;
    local_5c = &DAT_00fe1bec;
    bVar6 = FUN_00538870();
    param_1._3_1_ = param_1._3_1_ | bVar6;
  }
  if (param_1._3_1_ == 0) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8._0_1_ = 3;
      FUN_00587480();
      local_40 = (undefined4 *)0x69ffd9;
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8._0_1_ = 2;
    }
    local_40 = (undefined4 *)0x0;
    local_18 = (undefined1 *)&local_5c;
    local_48 = 7;
    local_4c = 0;
    local_5c = (undefined *)((uint)local_5c & 0xffff0000);
    FUN_00402160();
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 5;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
    }
    local_8._0_1_ = 4;
    FUN_005740f0();
    if (local_14 == DAT_00fe5b10) {
      pcVar4 = (code *)swi(3);
      (*pcVar4)();
      return;
    }
    psVar8 = (short *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      psVar8 = *(short **)psVar8;
    }
    psVar7 = psVar8;
    do {
      sVar1 = *psVar7;
      psVar7 = psVar7 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar8,(int)psVar7 - (int)(psVar8 + 1) >> 1);
    local_8._0_1_ = 2;
    FUN_0058b270(0xca);
  }
  else {
    if ((DAT_00fe1bd8 & 1) == 0) {
      DAT_00fe1bd8 = DAT_00fe1bd8 | 1;
      local_8._0_1_ = 6;
      FUN_00533f80();
      local_40 = (undefined4 *)0x6a00dc;
      _atexit((_func_4879 *)&LAB_00bced30);
      local_8._0_1_ = 2;
    }
    local_40 = &DAT_00fe1be0;
    local_44 = (undefined *)0x6a00f1;
    FUN_00534590();
  }
  FUN_0056fb00();
  ExceptionList = local_10;
  return;
}

