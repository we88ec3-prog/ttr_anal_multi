
undefined4 FUN_0054b8e0(void)

{
  undefined4 *unaff_ESI;
  undefined4 local_20;
  int local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00936efe;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(char *)((int)unaff_ESI + 10) != '\0') {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 0;
      FUN_004dec90(DAT_00d61f20 ^ (uint)&local_20);
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    local_20 = *unaff_ESI;
    FUN_008438c0(&local_20);
    if (local_1c != DAT_00fab14c) {
      ExceptionList = local_14;
      return *(undefined4 *)(local_1c + 0x10);
    }
  }
  ExceptionList = local_14;
  return 0;
}

