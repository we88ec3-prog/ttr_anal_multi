
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004ed1f0(undefined4 param_1,undefined2 param_2)

{
  short sVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  short *psVar5;
  int in_ECX;
  short *psVar6;
  undefined2 local_74 [8];
  undefined4 local_64;
  undefined2 *local_60;
  undefined2 local_58 [8];
  undefined4 local_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 *puStack_3c;
  undefined4 local_24;
  undefined2 uStack_20;
  undefined2 local_1e;
  undefined1 *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00940402;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(int *)(in_ECX + 0x5ec0) != 0) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590();
      puStack_3c = (undefined4 *)0x4ed255;
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    if (*(int *)(in_ECX + 0x5ec8) == DAT_00f93930) {
      if ((_DAT_00fb1314 & 1) == 0) {
        _DAT_00fb1314 = _DAT_00fb1314 | 1;
        puStack_3c = (undefined4 *)0x4ed287;
        _atexit((_func_4879 *)&DAT_00bccf10);
      }
      local_24._0_2_ = 0xbc2;
      local_24._2_2_ = (undefined2)param_1;
      uStack_20 = (undefined2)((uint)param_1 >> 0x10);
      local_1e = param_2;
      if (DAT_00fba798 == 0) {
        puStack_3c = &local_24;
        uStack_40 = 2;
        local_44 = 0x4ed2c3;
        (**(code **)(*DAT_00fba854 + 0x10))();
      }
      ExceptionList = local_14;
      return 1;
    }
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 1;
    FUN_00587480();
    puStack_3c = (undefined4 *)0x4ed2fb;
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_c = 0xffffffff;
  puStack_3c = (undefined4 *)0x0;
  local_1c = (undefined1 *)local_58;
  local_44 = 7;
  local_48 = 0;
  local_60 = &DAT_00bed1fc;
  local_58[0] = 0;
  local_64 = 0x4ed332;
  FUN_00402160();
  local_c = 2;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c._0_1_ = 3;
    local_c._1_3_ = 0;
    local_60 = (undefined2 *)0x4ed359;
    FUN_00584c40();
    local_60 = (undefined2 *)0x4ed363;
    _atexit(FUN_00bcf370);
    local_c = CONCAT31(local_c._1_3_,2);
  }
  local_60 = (undefined2 *)0x4ed386;
  FUN_005740f0();
  iVar3 = CONCAT22(local_24._2_2_,(undefined2)local_24);
  if (iVar3 != DAT_00fe5b10) {
    psVar6 = (short *)(iVar3 + 0x10);
    if (7 < *(uint *)(iVar3 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    local_24 = local_74;
    local_60 = (undefined2 *)0x7;
    local_64 = 0;
    local_74[0] = 0;
    psVar5 = psVar6;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar6,(int)psVar5 - (int)(psVar6 + 1) >> 1);
    local_c = 0xffffffff;
    FUN_0058b270(0xca);
    ExceptionList = local_14;
    return 0;
  }
  pcVar2 = (code *)swi(3);
  uVar4 = (*pcVar2)();
  return uVar4;
}

