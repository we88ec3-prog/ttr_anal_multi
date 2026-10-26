
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0066c090(int param_1)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  short *psVar6;
  undefined4 *puVar7;
  int *piVar8;
  int local_24;
  int local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0094617a;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar3 = *(int *)(*(int *)(param_1 + 0xf0) + 0xcc);
  if (iVar3 == 0) {
    local_24 = -1;
  }
  else {
    iVar3 = *(int *)(iVar3 + 0xdc);
    if (iVar3 == 0) {
      local_24 = -1;
    }
    else {
      local_24 = *(int *)(iVar3 + 0x20);
    }
  }
  iVar3 = FUN_005078c0();
  iVar4 = FUN_00507750();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if ((DAT_00f94294 != 0) && (iVar3 != 0)) {
    if (iVar4 == 0) {
      ExceptionList = local_14;
      return;
    }
    FUN_00414680();
    FUN_004957c0();
    iVar3 = *(int *)(*(int *)(param_1 + 0xf0) + 0xcc);
    if (iVar3 != 0) {
      iVar3 = *(int *)(iVar3 + 0xdc);
      if (iVar3 != 0) {
        DAT_00d63dcc = *(undefined4 *)(iVar3 + 0x20);
        ExceptionList = local_14;
        return;
      }
      DAT_00d63dcc = 0xffffffff;
      ExceptionList = local_14;
      return;
    }
    DAT_00d63dcc = 0xffffffff;
    ExceptionList = local_14;
    return;
  }
  if (iVar3 == 4) {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c = 1;
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
    psVar5 = (short *)(local_20 + 0x10);
    if (7 < *(uint *)(local_20 + 0x24)) {
      psVar5 = *(short **)psVar5;
    }
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160();
    local_c = 2;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c._0_1_ = 3;
      local_c._1_3_ = 0;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_c = CONCAT31(local_c._1_3_,2);
    }
    FUN_005740f0();
    if (DAT_00fe5b10 == 0x195) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar5 = (short *)&DAT_000001a5;
    if (7 < _DAT_000001b9) {
      psVar5 = _DAT_000001a5;
    }
    psVar6 = psVar5;
    do {
      sVar1 = *psVar6;
      psVar6 = psVar6 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar5,(int)psVar6 - (int)(psVar5 + 1) >> 1);
    local_c = 0xffffffff;
    FUN_0058b270(0xca);
    piVar8 = *(int **)(param_1 + 0xf8);
  }
  else {
    if (iVar3 == 0) {
      ExceptionList = local_14;
      return;
    }
    if (iVar3 != 5) {
      if (iVar4 == 0) {
        ExceptionList = local_14;
        return;
      }
      FUN_00414680();
      FUN_004957c0();
      DAT_00d63dcc = FUN_0042c530();
      ExceptionList = local_14;
      return;
    }
    iVar3 = FUN_005854b0();
    FUN_005740f0();
    if (local_24 == *(int *)(iVar3 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    FUN_00402250();
    local_c = 4;
    iVar3 = FUN_005854b0();
    FUN_005740f0();
    if (local_24 == *(int *)(iVar3 + 4)) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    puVar7 = (undefined4 *)(local_24 + 0x10);
    if (7 < *(uint *)(local_24 + 0x24)) {
      puVar7 = (undefined4 *)*puVar7;
    }
    FUN_00402250(puVar7);
    local_c = 0xffffffff;
    FUN_0058b270(0xca);
    piVar8 = *(int **)(param_1 + 0xf8);
  }
  (**(code **)(*piVar8 + 0x90))();
  ExceptionList = local_14;
  return;
}

