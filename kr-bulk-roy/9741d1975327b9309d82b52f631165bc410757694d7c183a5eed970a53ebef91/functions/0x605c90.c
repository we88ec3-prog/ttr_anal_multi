
void FUN_00605c90(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 *puVar2;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009334e2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar2 = (undefined4 *)FUN_00891268();
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = FoxUI::FXUIEvent::vftable;
    puVar2[1] = 0xffffffff;
    puVar2[2] = 0xffffffff;
    puVar2[3] = 0;
    puVar2[4] = 0xf4355;
  }
  FUN_004072a0();
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  puVar2 = (undefined4 *)FUN_00891268();
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = 0xffffffff;
    puVar2[2] = 0xffffffff;
    puVar2[3] = 0;
    puVar2[4] = 0xf43b1;
    *puVar2 = FoxUI::FXUIEventI1::vftable;
    puVar2[5] = param_2;
  }
  FUN_00402160();
  local_8._1_3_ = 0;
  if ((DAT_00fb75b0 & 1) == 0) {
    DAT_00fb75b0 = DAT_00fb75b0 | 1;
    local_8._0_1_ = 2;
    local_8._1_3_ = 0;
    FUN_004f3d80();
    _atexit((_func_4879 *)&LAB_00bcd1e0);
  }
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8._0_1_ = 3;
    FUN_00584c40();
    _atexit(FUN_00bcf370);
  }
  local_8._0_1_ = 1;
  FUN_005740f0();
  if (local_14 != DAT_00fe5b10) {
    FUN_004f6a30();
    FUN_004ed610();
    local_8 = 0xffffffff;
    FUN_0058b270(0xcf);
    ExceptionList = local_10;
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

