
void FUN_00621930(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  int local_1c;
  int local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093348a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_14 = (undefined4 *)FUN_00891268(0x14,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (local_14 == (undefined4 *)0x0) {
    local_14 = (undefined4 *)0x0;
  }
  else {
    *local_14 = FoxUI::FXUIEvent::vftable;
    local_14[1] = 0xffffffff;
    local_14[2] = 0xffffffff;
    local_14[3] = 0;
    local_14[4] = 0xf43d0;
  }
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
    local_8 = 0xffffffff;
  }
  local_18 = 0x196;
  FUN_005740f0(&local_18);
  if (local_1c != DAT_00fe5b10) {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 1;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_8 = 0xffffffff;
    }
    local_1c = 0x1b5;
    FUN_005740f0(&local_1c);
    if (local_18 != DAT_00fe5b10) {
      if (*(uint *)(local_18 + 0x24) < 8) {
        iVar2 = local_18 + 0x10;
      }
      else {
        iVar2 = *(int *)(local_18 + 0x10);
      }
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        local_8 = 2;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
        local_8 = 0xffffffff;
      }
      FUN_007532b0(&DAT_00f94810,iVar2,local_14,param_1);
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

