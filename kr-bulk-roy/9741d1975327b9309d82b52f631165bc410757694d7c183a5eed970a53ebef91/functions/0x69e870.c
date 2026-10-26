
int FUN_0069e870(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  undefined4 *local_24;
  int local_20;
  int local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00932a7a;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar4 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
  if (iVar4 == 0) {
    uVar5 = 0xffffffff;
  }
  else {
    iVar4 = *(int *)(iVar4 + 0xdc);
    if (iVar4 == 0) {
      uVar5 = 0xffffffff;
    }
    else {
      uVar5 = *(uint *)(iVar4 + 0x20);
    }
  }
  if ((DAT_00fe1bd8 & 1) == 0) {
    DAT_00fe1bd8 = DAT_00fe1bd8 | 1;
    local_c = 0;
    FUN_00533f80(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bced30);
  }
  local_c = 0xffffffff;
  iVar4 = (DAT_00fe1c40 - DAT_00fe1c3c) * -0x7bdef7bd;
  if (uVar5 < (uint)((DAT_00fe1c40 - DAT_00fe1c3c) / 0x1f)) {
    iVar1 = *(int *)(uVar5 * 0x1f + DAT_00fe1c3c);
    iVar4 = *(int *)(uVar5 * 0x1f + 4 + DAT_00fe1c3c);
    if (iVar1 != 0 || iVar4 != 0) {
      local_24 = (undefined4 *)FUN_00891268(0x18);
      if (local_24 == (undefined4 *)0x0) {
        local_24 = (undefined4 *)0x0;
      }
      else {
        local_24[1] = 0xffffffff;
        local_24[2] = 0xffffffff;
        local_24[3] = 0;
        local_24[4] = 0xf43b8;
        *local_24 = FoxUI::FXUIEventI1::vftable;
        local_24[5] = iVar1;
      }
      if ((DAT_00fe5b2c & 1) == 0) {
        DAT_00fe5b2c = DAT_00fe5b2c | 1;
        local_c = 1;
        FUN_00584c40(&DAT_00fe5b0c);
        _atexit(FUN_00bcf370);
        local_c = 0xffffffff;
      }
      local_20 = 0x196;
      FUN_005740f0(&local_20);
      if (local_1c[0] == DAT_00fe5b10) {
        pcVar2 = (code *)swi(3);
        iVar4 = (*pcVar2)();
        return iVar4;
      }
      if (*(uint *)(local_1c[0] + 0x24) < 8) {
        iVar4 = local_1c[0] + 0x10;
      }
      else {
        iVar4 = *(int *)(local_1c[0] + 0x10);
      }
      if ((DAT_00fe5b2c & 1) == 0) {
        DAT_00fe5b2c = DAT_00fe5b2c | 1;
        local_c = 2;
        FUN_00584c40(&DAT_00fe5b0c);
        _atexit(FUN_00bcf370);
        local_c = 0xffffffff;
      }
      local_1c[0] = 0xd6;
      FUN_005740f0(local_1c);
      if (local_20 == DAT_00fe5b10) {
        pcVar2 = (code *)swi(3);
        iVar4 = (*pcVar2)();
        return iVar4;
      }
      puVar3 = (undefined4 *)(local_20 + 0x10);
      if (7 < *(uint *)(local_20 + 0x24)) {
        puVar3 = (undefined4 *)*puVar3;
      }
      iVar4 = FUN_00404b10(0xcf,puVar3,iVar4,local_24,param_1);
    }
  }
  ExceptionList = local_14;
  return iVar4;
}

