
undefined4 FUN_004e84a0(int param_1)

{
  char cVar1;
  code *pcVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00936871;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  cVar1 = *(char *)(param_1 + 2);
  if (cVar1 == '\x01') {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    FUN_00402160();
    local_8 = 1;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 2;
      local_8._1_3_ = 0;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_8 = CONCAT31(local_8._1_3_,1);
    }
    FUN_005740f0();
    if (local_14 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      uVar3 = (*pcVar2)();
      return uVar3;
    }
    piVar4 = (int *)(local_14 + 0x10);
    piVar7 = piVar4;
    if (7 < *(uint *)(local_14 + 0x24)) {
      piVar4 = (int *)*piVar4;
      piVar7 = piVar4;
    }
    do {
      iVar5 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 2);
    } while ((short)iVar5 != 0);
  }
  else {
    if (cVar1 != '\x02') {
      if (cVar1 == '\x03') {
        FUN_004054c0();
        FUN_00402250();
        local_8 = 5;
        FUN_005854b0();
        uVar3 = FUN_00585330();
        FUN_00402250(uVar3);
        local_8 = 0xffffffff;
        FUN_0058b270(0xca);
      }
      else if (cVar1 == '\0') {
        FUN_004054c0();
        FUN_00402250();
        local_8 = 6;
        FUN_00425330();
        FUN_004f7370();
        uVar3 = 0x77;
        FUN_005854b0(0x77);
        FUN_00585330(uVar3);
        FUN_004ed610();
        local_8 = 0xffffffff;
        FUN_0058b270(0xca);
        FUN_004ec570();
        puVar6 = (undefined4 *)FUN_00891268();
        if (puVar6 != (undefined4 *)0x0) {
          *puVar6 = FoxUI::FXUIEvent::vftable;
          puVar6[1] = 0xffffffff;
          puVar6[2] = 0xffffffff;
          puVar6[3] = 0;
          puVar6[4] = 0xf4389;
        }
        FUN_004072a0();
        iVar5 = FUN_00891268();
        local_8 = 7;
        if (iVar5 != 0) {
          FUN_0040f060();
          FUN_00753f80();
        }
        local_8 = 0xffffffff;
        FUN_004072a0();
      }
      goto LAB_004e8804;
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 3;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    FUN_00402160();
    local_8 = 4;
    iVar5 = FUN_005854b0();
    FUN_005740f0();
    if (local_14 == *(int *)(iVar5 + 4)) {
      pcVar2 = (code *)swi(3);
      uVar3 = (*pcVar2)();
      return uVar3;
    }
    piVar4 = (int *)(local_14 + 0x10);
    piVar7 = piVar4;
    if (7 < *(uint *)(local_14 + 0x24)) {
      piVar4 = (int *)*piVar4;
      piVar7 = piVar4;
    }
    do {
      iVar5 = *piVar4;
      piVar4 = (int *)((int)piVar4 + 2);
    } while ((short)iVar5 != 0);
  }
  FUN_00402160(piVar7,(int)piVar4 - ((int)piVar7 + 2) >> 1);
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
LAB_004e8804:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 8;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0();
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 9;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0();
  ExceptionList = local_10;
  return 0;
}

