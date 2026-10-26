
void FUN_005d3fa0(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *local_3c;
  uint local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  int local_c;
  
  puStack_10 = &LAB_0093f336;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_3c;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  puVar3 = (undefined4 *)(param_1 + 0xa0);
  puVar2 = &DAT_00f834a4;
  do {
    local_24 = 7;
    local_28 = 0;
    local_38 = local_38 & 0xffff0000;
    local_c = 0;
    local_3c = puVar3;
    if ((DAT_00fdfb10 & 1) == 0) {
      DAT_00fdfb10 = DAT_00fdfb10 | 1;
      local_c._0_1_ = 1;
      local_c._1_3_ = 0;
      FUN_00590760(uVar1);
      _atexit((_func_4879 *)&LAB_00bce760);
      local_c = (uint)local_c._1_3_ << 8;
    }
    FUN_00594610(&DAT_00fdfb18,0);
    FUN_005dabe0(*puVar3);
    FUN_005dae00();
    local_c = 0xffffffff;
    if (7 < local_24) {
      FUN_0089120c(local_38);
    }
    puVar3 = local_3c + 1;
    puVar2 = puVar2 + 1;
  } while ((int)puVar2 < 0xf834b4);
  ExceptionList = local_14;
  local_3c = puVar3;
  __security_check_cookie(local_1c ^ (uint)&local_3c);
  return;
}

