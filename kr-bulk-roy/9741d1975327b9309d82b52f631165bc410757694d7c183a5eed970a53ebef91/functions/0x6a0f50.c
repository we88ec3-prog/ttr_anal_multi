
void FUN_006a0f50(int param_1)

{
  code *pcVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int local_20;
  int local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093c6ea;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar4 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
  if (iVar4 == 0) {
    uVar7 = 0xffffffff;
  }
  else {
    iVar4 = *(int *)(iVar4 + 0xdc);
    if (iVar4 == 0) {
      uVar7 = 0xffffffff;
    }
    else {
      uVar7 = *(uint *)(iVar4 + 0x20);
    }
  }
  if ((DAT_00fe1bd8 & 1) == 0) {
    DAT_00fe1bd8 = DAT_00fe1bd8 | 1;
    local_c = 0;
    FUN_00533f80(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bced30);
  }
  local_c = 0xffffffff;
  if (uVar7 < (uint)((DAT_00fe1c30 - DAT_00fe1c2c) / 0x1f)) {
    iVar4 = *(int *)(uVar7 * 0x1f + DAT_00fe1c2c);
    iVar5 = *(int *)(uVar7 * 0x1f + 4 + DAT_00fe1c2c);
    if (iVar4 != 0 || iVar5 != 0) {
      cVar2 = FUN_006a11d0(iVar4,iVar5);
      if (cVar2 != '\0') {
        puVar3 = (undefined4 *)FUN_00891268(0x18);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          puVar3[1] = 0xffffffff;
          puVar3[2] = 0xffffffff;
          puVar3[3] = 0;
          puVar3[4] = 0xf43b7;
          *puVar3 = FoxUI::FXUIEventI1::vftable;
          puVar3[5] = iVar4;
        }
        local_20 = 0x196;
        iVar4 = FUN_005854b0();
        FUN_005740f0(&local_20);
        if (local_1c[0] != *(int *)(iVar4 + 4)) {
          if (*(uint *)(local_1c[0] + 0x24) < 8) {
            iVar4 = local_1c[0] + 0x10;
          }
          else {
            iVar4 = *(int *)(local_1c[0] + 0x10);
          }
          local_1c[0] = 0xd7;
          iVar5 = FUN_005854b0();
          FUN_005740f0(local_1c);
          if (local_20 != *(int *)(iVar5 + 4)) {
            puVar6 = (undefined4 *)(local_20 + 0x10);
            if (7 < *(uint *)(local_20 + 0x24)) {
              puVar6 = (undefined4 *)*puVar6;
            }
            FUN_00404b10(0xcf,puVar6,iVar4,puVar3,param_1);
            ExceptionList = local_14;
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
    }
  }
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c = 1;
    FUN_00584c40(&DAT_00fe5b0c);
    _atexit(FUN_00bcf370);
    local_c = 0xffffffff;
  }
  local_1c[0] = 0x1b7;
  FUN_005740f0(local_1c);
  if (local_20 != DAT_00fe5b10) {
    if (*(uint *)(local_20 + 0x24) < 8) {
      iVar4 = local_20 + 0x10;
    }
    else {
      iVar4 = *(int *)(local_20 + 0x10);
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 2;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    FUN_007532b0(&DAT_00f94810,iVar4,0,0);
    ExceptionList = local_14;
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

