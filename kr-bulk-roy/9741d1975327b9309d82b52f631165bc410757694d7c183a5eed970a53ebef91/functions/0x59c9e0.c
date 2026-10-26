
void FUN_0059c9e0(undefined2 *param_1)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  short *psVar7;
  int *in_ECX;
  short *psVar8;
  undefined2 auStack_78 [8];
  undefined4 uStack_68;
  undefined2 *puStack_64;
  undefined4 *puStack_60;
  undefined2 uStack_5c;
  undefined4 uStack_4c;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00933774;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((in_ECX != (int *)0x0) && (iVar3 = (**(code **)(*in_ECX + 4))(), iVar3 != 0x105ca)) {
    uStack_4c = 0x59ca34;
    MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
  }
  FUN_004adcd0();
  piVar4 = (int *)FUN_004ef160();
  if (piVar4 != (int *)0x0) {
    if (*(char *)((int)piVar4 + 0x25) == '\0') {
      FUN_004adcd0();
      if (DAT_00fba798 == 0) {
        (**(code **)(*DAT_00fba854 + 0x10))();
      }
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_8 = 1;
        FUN_00587480();
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_8 = 0xffffffff;
      }
      puVar6 = (undefined4 *)FUN_00891268();
      if (puVar6 != (undefined4 *)0x0) {
        *puVar6 = FoxUI::FXUIEvent::vftable;
        puVar6[1] = 0xffffffff;
        puVar6[2] = 0xffffffff;
        puVar6[3] = 0;
        puVar6[4] = 0xf4318;
      }
      puStack_60 = (undefined4 *)0x0;
      uStack_4c = 0;
      puStack_64 = &DAT_00bed1fc;
      uStack_5c = 0;
      uStack_68 = 0x59cbb3;
      FUN_00402160();
      local_8 = 2;
      param_1 = (undefined2 *)0xa8;
      puStack_60 = (undefined4 *)0x59cbc6;
      iVar3 = FUN_005854b0();
      puStack_60 = &param_1;
      puStack_64 = (undefined2 *)0x59cbd6;
      FUN_005740f0();
      if (local_14 == *(int *)(iVar3 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      psVar8 = (short *)(local_14 + 0x10);
      if (7 < *(uint *)(local_14 + 0x24)) {
        psVar8 = *(short **)psVar8;
      }
      param_1 = auStack_78;
      puStack_64 = (undefined2 *)0x7;
      uStack_68 = 0;
      auStack_78[0] = 0;
      psVar7 = psVar8;
      do {
        sVar1 = *psVar7;
        psVar7 = psVar7 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar8,(int)psVar7 - (int)(psVar8 + 1) >> 1);
      local_8 = 0xffffffff;
      FUN_0058b270(199);
    }
    else {
      piVar5 = (int *)FUN_00891268();
      if (piVar5 == (int *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        iVar3 = *piVar4;
        piVar5[7] = piVar4[1];
        piVar5[1] = -1;
        piVar5[2] = -1;
        piVar5[3] = 0;
        piVar5[4] = 0xf4317;
        *piVar5 = (int)FoxUI::FXUIEventBI1::vftable;
        piVar5[6] = iVar3;
      }
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        local_8 = 0;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
        local_8 = 0xffffffff;
      }
      if (DAT_00f95bd4 != (int *)0x0) {
        (**(code **)(*DAT_00f95bd4 + 0x15c))();
      }
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0x10))();
        ExceptionList = local_10;
        return;
      }
    }
  }
  ExceptionList = local_10;
  return;
}

