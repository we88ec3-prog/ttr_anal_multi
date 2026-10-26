
undefined4 FUN_00554850(void)

{
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093b2ae;
  local_10 = ExceptionList;
  if (*(int *)(unaff_ESI + 8) == 0) {
    return 0x80004005;
  }
  if (*(int *)(unaff_ESI + 0xc) != 0) {
    ExceptionList = &local_10;
    if ((DAT_00fb73b8 & 1) == 0) {
      DAT_00fb73b8 = DAT_00fb73b8 | 1;
      local_8 = 0;
      FUN_00560170(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcd110);
    }
    local_8 = 0xffffffff;
    if (DAT_00fb73e8 == 0) {
      (**(code **)(**(int **)(unaff_ESI + 8) + 8))();
    }
  }
  ExceptionList = local_10;
  return 0;
}

