
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006a26b0(int param_1)

{
  code *pcVar1;
  char cVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 local_2c;
  uint local_24;
  undefined4 local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093c4fc;
  local_14 = ExceptionList;
  iVar4 = *(int *)(param_1 + 300);
  local_20 = 0;
  local_24 = local_24 & 0xffffff00;
  if (iVar4 == 0) {
    local_2c = 0xc;
  }
  else if (iVar4 == 1) {
    local_2c = 0x18;
  }
  else {
    if (iVar4 != 2) {
      return;
    }
    local_2c = 0x30;
  }
  ExceptionList = &local_14;
  local_1c = FUN_0068ace0(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
  if (local_1c < 1) {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c = 0;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_c = 0xffffffff;
    }
    local_24 = 0x196;
    FUN_005740f0(&local_24);
    if (DAT_00fe5b10 == 0x3f800000) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    puVar6 = _DAT_3f800010;
    if (_DAT_3f800024 < 8) {
      puVar6 = &DAT_3f800010;
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c = 1;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_c = 0xffffffff;
    }
    local_24 = 0xda;
    FUN_005740f0(&local_24);
    if (DAT_00fe5b10 != 0x3f800000) {
      puVar3 = &DAT_3f800010;
      if (7 < _DAT_3f800024) {
        puVar3 = _DAT_3f800010;
      }
      FUN_00404b10(0xca,puVar3,puVar6,0,0);
      ExceptionList = local_14;
      return;
    }
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  if (*(int *)(*(int *)(param_1 + 0x110) + 0x25c) != 0) {
    iVar4 = FUN_00404ba0();
    if (((*(int *)(param_1 + 0x11c) == 1) && (*(int *)(iVar4 + 0x6920) != -0x16f8)) &&
       (iVar4 = FUN_00508da0(), iVar4 != 0)) {
      FUN_00404c10();
      iVar4 = FUN_0051d6d0();
      if (iVar4 != 0) {
        iVar4 = FUN_00404ba0();
        cVar2 = FUN_004d9d20(*(undefined4 *)(iVar4 + 0x6928),0xc);
        if (cVar2 != '\0') {
          local_24 = CONCAT31(local_24._1_3_,1);
        }
        FUN_0068ace0();
        local_20 = FUN_006a3320();
        iVar4 = FUN_008fed10();
        iVar5 = FUN_00404ba0();
        if (*(int *)(iVar5 + 0x6864) < iVar4) {
          uVar8 = 0x196;
          FUN_005854b0(0x196,0,0);
          uVar8 = FUN_00585330(uVar8);
          uVar7 = 0xd0;
          FUN_005854b0(0xd0,uVar8);
          uVar8 = FUN_00585330(uVar7);
          FUN_00404b10(0xca,uVar8);
          ExceptionList = local_14;
          return;
        }
        FUN_004e14f0();
        FUN_00534230(*(undefined4 *)(param_1 + 0x11c),*(undefined4 *)(param_1 + 0x120),
                     *(undefined4 *)(param_1 + 0x124),local_2c,local_1c,local_24);
      }
    }
    ExceptionList = local_14;
    return;
  }
  local_24 = 0x196;
  iVar4 = FUN_005854b0();
  FUN_005740f0(&local_24);
  if (*(int *)(iVar4 + 4) == 0x3f800000) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  puVar6 = _DAT_3f800010;
  if (_DAT_3f800024 < 8) {
    puVar6 = &DAT_3f800010;
  }
  local_24 = 0xdb;
  iVar4 = FUN_005854b0();
  FUN_005740f0(&local_24);
  if (*(int *)(iVar4 + 4) != 0x3f800000) {
    puVar3 = &DAT_3f800010;
    if (7 < _DAT_3f800024) {
      puVar3 = _DAT_3f800010;
    }
    FUN_00404b10(0xca,puVar3,puVar6,0,0);
    ExceptionList = local_14;
    return;
  }
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}

