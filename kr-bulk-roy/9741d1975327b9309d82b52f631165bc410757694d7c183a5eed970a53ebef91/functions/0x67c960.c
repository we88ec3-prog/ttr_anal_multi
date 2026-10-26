
void FUN_0067c960(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  
  if ((param_2 != -1) && (cVar3 = FUN_0067ce60(param_1,param_2,param_4), cVar3 != '\0')) {
    puVar4 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar4 != (undefined4 *)0x0) {
      uVar1 = *(undefined4 *)(param_1 + 0x124 + param_2 * 0x38);
      uVar2 = *(undefined4 *)(param_1 + param_2 * 0x38 + 0x120);
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf4369;
      *puVar4 = FoxUI::FXUIEventI2::vftable;
      puVar4[5] = uVar2;
      puVar4[6] = uVar1;
    }
    FUN_004072a0();
    puVar4 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar4 != (undefined4 *)0x0) {
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf4368;
      *puVar4 = FoxUI::FXUIEventI2::vftable;
      puVar4[5] = param_3;
      puVar4[6] = param_4;
    }
    FUN_004072a0();
    puVar4 = (undefined4 *)FUN_0067d0a0(param_3,param_4);
    puVar6 = (undefined4 *)(param_1 + 0x120 + param_2 * 0x38);
    for (iVar5 = 0xe; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
    FUN_0067c470();
  }
  return;
}

