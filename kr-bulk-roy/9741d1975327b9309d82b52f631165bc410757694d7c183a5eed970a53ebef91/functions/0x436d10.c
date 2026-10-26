
/* WARNING: Removing unreachable block (ram,0x00436f19) */

void FUN_00436d10(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009454a6;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_005ac3e0(DAT_00d61f20 ^ (uint)&stack0xffffffb8);
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_c._0_1_ = 1;
  local_c._1_3_ = 0;
  FUN_00437090();
  FUN_005a9f40((undefined4 *)(in_ECX + 0x224));
  puVar1 = (undefined4 *)(in_ECX + 0x228);
  FUN_00437170();
  FUN_005a9f40(puVar1);
  FUN_00437250();
  FUN_005a9f40((undefined4 *)(in_ECX + 0x22c));
  FUN_0040b670(in_ECX);
  (**(code **)(**(int **)(in_ECX + 0x224) + 0xd0))();
  (**(code **)(*(int *)*puVar1 + 0xd0))();
  (**(code **)(**(int **)(in_ECX + 0x22c) + 0xd0))();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c._0_1_ = 2;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c._0_1_ = 1;
  }
  if (DAT_00f942d8 == '\0') {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c._0_1_ = 5;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c._0_1_ = 1;
    }
    DAT_00f942c4 = 0;
  }
  else {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c._0_1_ = 3;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c._0_1_ = 1;
    }
    uVar2 = DAT_00f942d0;
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c._0_1_ = 4;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c._0_1_ = 1;
    }
    DAT_00f942c4 = uVar2;
  }
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_c._0_1_ = 6;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_c._0_1_ = 1;
  }
  FUN_0058e1c0(*puVar1);
  ExceptionList = local_14;
  return;
}

