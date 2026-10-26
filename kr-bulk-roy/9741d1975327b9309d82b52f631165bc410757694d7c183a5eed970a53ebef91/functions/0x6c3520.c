
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006c3520(int param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00932820;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  puVar2 = (undefined4 *)FUN_00891268();
  if (puVar2 != (undefined4 *)0x0) {
    uVar3 = *(undefined4 *)(param_1 + 0xb4);
    puVar2[1] = 0xffffffff;
    puVar2[2] = 0xffffffff;
    puVar2[3] = 0;
    puVar2[4] = 0xf43f8;
    *puVar2 = FoxUI::FXUIEventI1::vftable;
    puVar2[5] = uVar3;
  }
  FUN_00402160();
  local_8._1_3_ = 0;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8._0_1_ = 2;
    local_8._1_3_ = 0;
    FUN_00584c40();
    _atexit(FUN_00bcf370);
  }
  local_8._0_1_ = 1;
  FUN_005740f0();
  if (local_18 != DAT_00fe5b10) {
    if ((DAT_00fb75b0 & 1) == 0) {
      DAT_00fb75b0 = DAT_00fb75b0 | 1;
      local_8._0_1_ = 3;
      FUN_004f3d80();
      _atexit((_func_4879 *)&LAB_00bcd1e0);
      local_8._0_1_ = 1;
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 4;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_8._0_1_ = 1;
    }
    FUN_005740f0();
    if (DAT_00fe5b10 != 0x61) {
      uVar3 = FUN_004f6a30(*(undefined4 *)(param_1 + 0xb4));
      FUN_00498ef0(uVar3);
      local_8 = 0xffffffff;
      FUN_0058b270(0xcf);
      ExceptionList = local_10;
      return;
    }
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

