
void FUN_00667080(undefined2 *param_1)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  short *psVar4;
  int in_ECX;
  short *psVar5;
  undefined2 local_68 [8];
  undefined4 local_58;
  undefined2 *local_54;
  undefined4 *puStack_50;
  undefined2 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 *puStack_30;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009331a6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(*(int *)(in_ECX + 0x118 + ((uint)param_1 & 0xff) * 4) + 0x25c) != 0) {
    FUN_004adcd0();
    puStack_30 = (undefined4 *)(*(undefined4 **)(in_ECX + 0x114))[1];
    uStack_34 = **(undefined4 **)(in_ECX + 0x114);
    local_38 = 0x6670e2;
    FUN_004ef440();
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      puStack_30 = (undefined4 *)0x667104;
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    puStack_30 = (undefined4 *)0x667119;
    puStack_30 = (undefined4 *)FUN_00891268();
    if (puStack_30 == (undefined4 *)0x0) {
      puStack_30 = (undefined4 *)0x0;
    }
    else {
      *puStack_30 = FoxUI::FXUIEvent::vftable;
      puStack_30[1] = 0xffffffff;
      puStack_30[2] = 0xffffffff;
      puStack_30[3] = 0;
      puStack_30[4] = 0xf4319;
    }
    puStack_50 = (undefined4 *)0x0;
    local_38 = 7;
    local_3c = 0;
    local_54 = &DAT_00bed1fc;
    local_4c = 0;
    local_58 = 0x66715f;
    FUN_00402160();
    local_8 = 1;
    param_1 = (undefined2 *)0xa9;
    puStack_50 = (undefined4 *)0x667172;
    iVar3 = FUN_005854b0();
    puStack_50 = &param_1;
    local_54 = (undefined2 *)0x667182;
    FUN_005740f0();
    if (local_14 == *(int *)(iVar3 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar5 = (short *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      psVar5 = *(short **)psVar5;
    }
    param_1 = local_68;
    local_54 = (undefined2 *)0x7;
    local_58 = 0;
    local_68[0] = 0;
    psVar4 = psVar5;
    do {
      sVar1 = *psVar4;
      psVar4 = psVar4 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar5,(int)psVar4 - (int)(psVar5 + 1) >> 1);
    local_8 = 0xffffffff;
    FUN_0058b270(199);
  }
  ExceptionList = local_10;
  return;
}

