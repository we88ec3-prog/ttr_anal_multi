
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00448f60(void)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  short *psVar6;
  short *psVar7;
  undefined4 uVar8;
  int *piVar9;
  uint uVar10;
  int local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00945302;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 0;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  iVar4 = DAT_00fb7258;
  local_c = 0xffffffff;
  if (DAT_00fb7258 == 0) {
LAB_0044930e:
    piVar9 = (int *)FUN_00891268();
    if (piVar9 == (int *)0x0) {
      piVar9 = (int *)0x0;
    }
    else {
      piVar9[1] = -1;
      piVar9[2] = -1;
      piVar9[3] = 0;
      piVar9[4] = 0xf4392;
      *piVar9 = (int)FoxUI::FXUIEventI2::vftable;
      piVar9[5] = 0;
      piVar9[6] = 0;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 8;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    if (DAT_00f95bd4 != (int *)0x0) {
      (**(code **)(*DAT_00f95bd4 + 0x15c))();
    }
    if (piVar9 != (int *)0x0) {
      (**(code **)(*piVar9 + 0x10))();
    }
    ExceptionList = local_14;
    return;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  iVar3 = FUN_00539aa0();
  piVar9 = *(int **)(iVar4 + 0x28);
  uVar10 = 0;
  for (iVar4 = *(int *)(iVar4 + 0x2c) - (int)piVar9 >> 2; iVar4 != 0; iVar4 = iVar4 + -1) {
    if (*(char *)(*piVar9 + 10) != '\0') {
      uVar10 = uVar10 + 1;
    }
    piVar9 = piVar9 + 1;
  }
  if ((iVar3 == 0) || (*(char *)(iVar3 + 6) != '\0')) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 2;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    if (DAT_00f9392c != 5) {
      if (((iVar3 != 0) && (*(char *)(iVar3 + 6) != '\0')) && (1 < uVar10)) {
        FUN_004054c0();
        puVar5 = (undefined4 *)FUN_00891268();
        if (puVar5 != (undefined4 *)0x0) {
          *puVar5 = FoxUI::FXUIEvent::vftable;
          puVar5[1] = 0xffffffff;
          puVar5[2] = 0xffffffff;
          puVar5[3] = 0;
          puVar5[4] = 0xf4393;
        }
        FUN_005854b0();
        FUN_00585330();
        FUN_00402250();
        local_c = 7;
        FUN_005854b0();
        uVar8 = FUN_00585330();
        FUN_00402250(uVar8);
        local_c = 0xffffffff;
        FUN_0058b270(0xcf);
        ExceptionList = local_14;
        return;
      }
      goto LAB_0044930e;
    }
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 3;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  puVar5 = (undefined4 *)FUN_00891268();
  if (puVar5 != (undefined4 *)0x0) {
    *puVar5 = FoxUI::FXUIEvent::vftable;
    puVar5[1] = 0xffffffff;
    puVar5[2] = 0xffffffff;
    puVar5[3] = 0;
    puVar5[4] = 0xf4393;
  }
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c = 4;
    FUN_00584c40();
    _atexit(FUN_00bcf370);
    local_c = 0xffffffff;
  }
  FUN_005740f0();
  if (local_20 == DAT_00fe5b10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psVar6 = (short *)(local_20 + 0x10);
  if (7 < *(uint *)(local_20 + 0x24)) {
    psVar6 = *(short **)psVar6;
  }
  do {
    sVar1 = *psVar6;
    psVar6 = psVar6 + 1;
  } while (sVar1 != 0);
  FUN_00402160();
  local_c = 5;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c._0_1_ = 6;
    local_c._1_3_ = 0;
    FUN_00584c40();
    _atexit(FUN_00bcf370);
    local_c = CONCAT31(local_c._1_3_,5);
  }
  FUN_005740f0();
  if (DAT_00fe5b10 != 0x196) {
    psVar6 = (short *)&DAT_000001a6;
    if (7 < _DAT_000001ba) {
      psVar6 = _DAT_000001a6;
    }
    psVar7 = psVar6;
    do {
      sVar1 = *psVar7;
      psVar7 = psVar7 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar6,(int)psVar7 - (int)(psVar6 + 1) >> 1);
    local_c = 0xffffffff;
    FUN_0058b270(0xcf);
    ExceptionList = local_14;
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

