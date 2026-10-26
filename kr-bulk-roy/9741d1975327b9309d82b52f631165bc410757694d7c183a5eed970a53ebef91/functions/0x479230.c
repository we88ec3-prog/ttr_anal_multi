
void FUN_00479230(byte param_1)

{
  undefined4 *puVar1;
  byte bVar2;
  int iVar3;
  int unaff_EDI;
  int local_78;
  uint local_74;
  uint uStack_70;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined1 auStack_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094113c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_78;
  ExceptionList = &local_14;
  if ((DAT_00fbace4 & 1) == 0) {
    DAT_00fbace4 = DAT_00fbace4 | 1;
    local_c = 0;
    FUN_00825080(DAT_00d61f20 ^ (uint)&stack0xffffff80);
    _atexit((_func_4879 *)&LAB_00bcd6d0);
  }
  if ((uint)param_1 < (uint)(DAT_00fbacf4 - DAT_00fbacf0 >> 2)) {
    bVar2 = *(byte *)(DAT_00fbacf0 + 2 + (uint)param_1 * 4);
  }
  else {
    bVar2 = 0;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  iVar3 = DAT_00f94308;
  local_c = 0xffffffff;
  local_74 = (uint)bVar2;
  FUN_004dae30(&local_74);
  if (local_78 == *(int *)(iVar3 + 4)) {
    iVar3 = iVar3 + 0x30;
  }
  else {
    iVar3 = local_78 + 0x10;
  }
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_c = 2;
    FUN_005c3de0();
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_c = 0xffffffff;
  }
  if (DAT_00f943e4 != 0) {
    local_78 = *(int *)(iVar3 + 0x3c);
    FUN_0082ef00(&local_78);
  }
  FUN_00745060();
  (**(code **)(**(int **)(unaff_EDI + 0x164) + 200))();
  puVar1 = (undefined4 *)FUN_0040ef80();
  local_c = 3;
  if (7 < (uint)puVar1[5]) {
    puVar1 = (undefined4 *)*puVar1;
  }
  FUN_0041f460(puVar1);
  local_c._0_1_ = 4;
  FUN_00405300(*(int *)(unaff_EDI + 0x15c) + 0xe8);
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
  (**(code **)(**(int **)(unaff_EDI + 0x15c) + 200))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_78);
  return;
}

