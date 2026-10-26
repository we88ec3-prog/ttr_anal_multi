
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004ecd10(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  code *pcVar3;
  undefined4 uVar4;
  short *psVar5;
  short *psVar6;
  undefined2 local_4c [8];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined2 *puStack_30;
  undefined2 local_1c;
  int local_1a;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092fad4;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (((*(int *)(param_1 + 0x5ec0) != 0) && (iVar2 = *(int *)(param_1 + 0x5ebc), iVar2 != 0)) &&
     ((*(char *)(iVar2 + 0x12) != '\0' || ((*(byte *)(iVar2 + 0x14) & 2) != 0)))) {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      puStack_30 = (undefined2 *)0x4ece9c;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_1c = 0xbbc;
    local_1a = param_2;
    if (DAT_00fba798 == 0) {
      puStack_30 = &local_1c;
      uStack_34 = 2;
      local_38 = 0x4ececc;
      (**(code **)(*DAT_00fba854 + 0x10))();
    }
    ExceptionList = local_10;
    return 1;
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    puStack_30 = (undefined2 *)0x4ecd8b;
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_8 = 0xffffffff;
  puStack_30 = (undefined2 *)0x0;
  local_14 = (undefined1 *)local_4c;
  local_38 = 7;
  local_3c = 0;
  local_4c[0] = 0;
  FUN_00402160();
  local_8 = 1;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_8._0_1_ = 2;
    local_8._1_3_ = 0;
    FUN_00584c40();
    _atexit(FUN_00bcf370);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  FUN_005740f0();
  if (param_2 != DAT_00fe5b10) {
    psVar6 = (short *)(param_2 + 0x10);
    if (7 < *(uint *)(param_2 + 0x24)) {
      psVar6 = *(short **)psVar6;
    }
    psVar5 = psVar6;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar6,(int)psVar5 - (int)(psVar6 + 1) >> 1);
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
    ExceptionList = local_10;
    return 0;
  }
  pcVar3 = (code *)swi(3);
  uVar4 = (*pcVar3)();
  return uVar4;
}

