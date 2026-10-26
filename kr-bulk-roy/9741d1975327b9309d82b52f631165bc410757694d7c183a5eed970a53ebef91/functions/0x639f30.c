
void FUN_00639f30(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093dc9a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar2 = FUN_00404ba0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (*(char *)(iVar2 + 0x6830) == '\0') {
    puVar3 = (undefined4 *)FUN_00891268(0x14);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = FoxUI::FXUIEvent::vftable;
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0xf438f;
    }
    FUN_004072a0();
    ExceptionList = local_10;
    return;
  }
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8 = 0;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
    local_8 = 0xffffffff;
  }
  local_14 = 0x196;
  FUN_005740f0(&local_14);
  if (local_18 != DAT_00fe5b10) {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8 = 1;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_8 = 0xffffffff;
    }
    local_18 = 0x5e;
    FUN_005740f0(&local_18);
    if (local_14 != DAT_00fe5b10) {
      if (*(uint *)(local_14 + 0x24) < 8) {
        iVar2 = local_14 + 0x10;
      }
      else {
        iVar2 = *(int *)(local_14 + 0x10);
      }
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        local_8 = 2;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
        local_8 = 0xffffffff;
      }
      FUN_007532b0(&DAT_00f94810,iVar2,0,0);
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

