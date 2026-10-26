
void FUN_004787b0(void)

{
  undefined4 *puVar1;
  int unaff_EDI;
  undefined1 auStack_74 [4];
  uint local_70;
  undefined4 local_60;
  uint local_5c;
  undefined1 local_54 [56];
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00925512;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_74;
  ExceptionList = &local_14;
  puVar1 = (undefined4 *)FUN_0040ef80(DAT_00d61f20 ^ (uint)&stack0xffffff88);
  local_c = 0;
  if (7 < (uint)puVar1[5]) {
    puVar1 = (undefined4 *)*puVar1;
  }
  FUN_0041f460(puVar1);
  local_c._0_1_ = 1;
  FUN_00405300(*(int *)(unaff_EDI + 0x16c) + 0xe8);
  local_c = (uint)local_c._1_3_ << 8;
  FUN_00757640(local_54);
  local_c = 0xffffffff;
  if (7 < local_5c) {
    FUN_0089120c(local_70);
  }
  local_70 = local_70 & 0xffff0000;
  local_5c = 7;
  local_60 = 0;
  FUN_007597b0(0);
  (**(code **)(**(int **)(unaff_EDI + 0x16c) + 200))();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_74);
  return;
}

