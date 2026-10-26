
void FUN_006c3200(void)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int unaff_EDI;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009327c2;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  puVar3 = (undefined4 *)FUN_00891268();
  if (puVar3 != (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(unaff_EDI + 0xb4);
    puVar3[1] = 0xffffffff;
    puVar3[2] = 0xffffffff;
    puVar3[3] = 0;
    puVar3[4] = 0xf43f7;
    *puVar3 = FoxUI::FXUIEventI1::vftable;
    puVar3[5] = uVar1;
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
  if (local_18 != DAT_00fe5b10) {
    FUN_004f6a30();
    FUN_004ed610();
    local_8 = 0xffffffff;
    FUN_0058b270(0xcf);
    ExceptionList = local_10;
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

