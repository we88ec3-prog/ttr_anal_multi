
void FUN_006398d0(void)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00942fb8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar3 = FUN_00404ba0(uVar2);
  if (*(char *)(iVar3 + 0x6830) == '\0') {
    if ((DAT_00fb1378 & 1) == 0) {
      DAT_00fb1378 = DAT_00fb1378 | 1;
      local_8 = 3;
      FUN_00539c20();
      _atexit((_func_4879 *)&LAB_00bccfb0);
      local_8 = 0xffffffff;
    }
    if (DAT_00fb7258 != 0) {
      iVar3 = FUN_00404ba0(uVar2);
      iVar3 = FUN_00539aa0(*(undefined4 *)(iVar3 + 0x5f50));
      if (iVar3 == 0) {
        FUN_006edb60(&DAT_00c2e548);
        ExceptionList = local_10;
        return;
      }
      if (*(char *)(iVar3 + 6) == '\0') {
        uVar6 = 0x196;
        FUN_005854b0(0x196,0,0);
        uVar6 = FUN_00585330(uVar6);
        uVar5 = 0x30;
        FUN_005854b0(0x30,uVar6);
        uVar6 = FUN_00585330(uVar5);
        FUN_00404b10(0xca,uVar6);
        ExceptionList = local_10;
        return;
      }
    }
    puVar4 = (undefined4 *)FUN_00891268(0x14);
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = FoxUI::FXUIEvent::vftable;
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf431c;
      FUN_004072a0();
      ExceptionList = local_10;
      return;
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
  if (local_18 == DAT_00fe5b10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
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
      iVar3 = local_14 + 0x10;
    }
    else {
      iVar3 = *(int *)(local_14 + 0x10);
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8 = 2;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8 = 0xffffffff;
    }
    FUN_007532b0(&DAT_00f94810,iVar3,0,0);
    ExceptionList = local_10;
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

