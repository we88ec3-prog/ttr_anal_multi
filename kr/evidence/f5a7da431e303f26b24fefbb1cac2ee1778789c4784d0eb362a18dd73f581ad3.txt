
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_004c4920(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined2 *puVar9;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009444ea;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar6 = FUN_004b0640(param_1,param_2,param_3);
  uVar7 = _DAT_00fb7a78;
  uVar1 = _DAT_00fb7a7c;
  uVar2 = _DAT_00fb7a80;
  uVar3 = _DAT_00fb7a84;
  uVar4 = _DAT_00fb7a88;
  if (iVar6 == 0) {
    if (param_2 < 2) {
      uVar8 = 0;
    }
    else {
      uVar8 = (param_2 - 2) / 0xd;
    }
    if ((DAT_00fb7a20 & 1) == 0) {
      DAT_00fb7a20 = DAT_00fb7a20 | 1;
      local_8 = 0;
      FUN_00548da0(uVar5);
      _atexit(FUN_00bcd370);
      local_8 = 0xffffffff;
    }
    FUN_0040f060();
    _DAT_00fb7a7c = (**(code **)(*DAT_00fba7a4 + 0x1c))(0);
    FUN_0040f060();
    _DAT_00fb7a78 = (**(code **)(*DAT_00fba7a4 + 0x1c))(1);
    FUN_0040f060();
    _DAT_00fb7a80 = (**(code **)(*DAT_00fba7a4 + 0x1c))(2);
    _DAT_00fb7a84 = 0;
    _DAT_00fb7a88 = 0;
    if (uVar8 != 0) {
      puVar9 = (undefined2 *)(param_1 + 4);
      do {
        if ((*(char *)(puVar9 + 1) == '\0') || ((byte)(*(char *)(puVar9 + 1) - 2U) < 2)) {
          if ((DAT_00fb7a20 & 1) == 0) {
            DAT_00fb7a20 = DAT_00fb7a20 | 1;
            local_8 = 1;
            FUN_00548da0();
            _atexit(FUN_00bcd370);
            local_8 = 0xffffffff;
          }
          FUN_0054a8f0(puVar9[-1],*puVar9);
        }
        puVar9 = (undefined2 *)((int)puVar9 + 0xd);
        uVar8 = uVar8 - 1;
      } while (uVar8 != 0);
    }
    uVar7 = 0;
    uVar1 = uVar7;
    uVar2 = uVar7;
    uVar3 = uVar7;
    uVar4 = uVar7;
    if ((DAT_00fb7a20 & 1) == 0) {
      DAT_00fb7a20 = DAT_00fb7a20 | 1;
      local_8 = 2;
      FUN_00548da0();
      _atexit(FUN_00bcd370);
    }
  }
  _DAT_00fb7a88 = uVar4;
  _DAT_00fb7a84 = uVar3;
  _DAT_00fb7a80 = uVar2;
  _DAT_00fb7a7c = uVar1;
  _DAT_00fb7a78 = uVar7;
  ExceptionList = local_10;
  return iVar6;
}

