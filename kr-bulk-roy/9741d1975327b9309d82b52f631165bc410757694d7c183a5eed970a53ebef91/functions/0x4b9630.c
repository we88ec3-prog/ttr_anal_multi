
undefined4 FUN_004b9630(int param_1)

{
  undefined *puVar1;
  undefined2 local_1a [3];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00941c7c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_1a[0] = 9;
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,local_1a,2,DAT_00d61f20 ^ (uint)&stack0xffffffd8);
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  DAT_00f941bc = 1;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (*(char *)(param_1 + 2) != DAT_00f9392c) {
    FUN_006edb60("roomtype isn\'t match to server\'s");
  }
  if (*(char *)(param_1 + 2) == '\x01') {
    if (DAT_00d6a674 == 0x5455544f) {
      FUN_004c4eb0();
      ExceptionList = local_14;
      return 0;
    }
    puVar1 = &DAT_00c06e60;
  }
  else {
    if (*(char *)(param_1 + 2) != '\x06') {
      ExceptionList = local_14;
      return 0;
    }
    if (DAT_00d6a674 == 0x44554546) {
      FUN_004bded0();
      ExceptionList = local_14;
      return 0;
    }
    puVar1 = &DAT_00c06e78;
  }
  FUN_006edb60(puVar1);
  ExceptionList = local_14;
  return 0;
}

