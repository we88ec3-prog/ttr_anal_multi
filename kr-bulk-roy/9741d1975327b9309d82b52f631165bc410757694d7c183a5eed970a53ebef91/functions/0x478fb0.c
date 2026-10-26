
void FUN_00478fb0(int param_1,undefined4 param_2,byte param_3)

{
  int iVar1;
  undefined4 *puVar2;
  byte bVar3;
  uint local_7c;
  int local_78;
  int local_74;
  uint uStack_70;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined1 auStack_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009411ac;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_7c;
  ExceptionList = &local_14;
  local_74 = param_1;
  if ((DAT_00fbace4 & 1) == 0) {
    DAT_00fbace4 = DAT_00fbace4 | 1;
    local_c = 0;
    FUN_00825080(DAT_00d61f20 ^ (uint)&stack0xffffff78);
    _atexit((_func_4879 *)&LAB_00bcd6d0);
  }
  local_c = 0xffffffff;
  iVar1 = FUN_008257b0();
  if ((iVar1 == 0) || ((uint)((*(int *)(iVar1 + 8) - *(int *)(iVar1 + 4)) / 0xc) <= (uint)param_3))
  {
    bVar3 = 0;
  }
  else {
    bVar3 = *(byte *)(*(int *)(iVar1 + 4) + (uint)param_3 * 0xc);
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  iVar1 = DAT_00f94308;
  local_7c = (uint)bVar3;
  FUN_004dae30(&local_7c);
  if (local_78 == *(int *)(iVar1 + 4)) {
    iVar1 = iVar1 + 0x30;
  }
  else {
    iVar1 = local_78 + 0x10;
  }
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_c = 2;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_c = 0xffffffff;
  }
  if (DAT_00f943e4 != 0) {
    local_78 = *(int *)(iVar1 + 0x3c);
    FUN_0082ef00(&local_78);
  }
  iVar1 = local_74;
  FUN_00745060();
  (**(code **)(**(int **)(iVar1 + 0x164) + 200))();
  puVar2 = (undefined4 *)FUN_0040ef80();
  local_c = 3;
  if (7 < (uint)puVar2[5]) {
    puVar2 = (undefined4 *)*puVar2;
  }
  FUN_0041f460(puVar2);
  local_c._0_1_ = 4;
  FUN_00405300(*(int *)(iVar1 + 0x15c) + 0xe8);
  local_c = CONCAT31(local_c._1_3_,3);
  FUN_00757640(auStack_54);
  local_c = 0xffffffff;
  if (7 < uStack_5c) {
    FUN_0089120c(uStack_70);
  }
  uStack_5c = 7;
  uStack_60 = 0;
  uStack_70 = uStack_70 & 0xffff0000;
  FUN_007597b0(0);
  (**(code **)(**(int **)(iVar1 + 0x15c) + 200))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_7c);
  return;
}

