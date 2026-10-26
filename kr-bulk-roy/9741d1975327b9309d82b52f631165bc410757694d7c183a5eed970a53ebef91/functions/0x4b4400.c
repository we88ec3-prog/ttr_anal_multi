
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004b4400(int param_1)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091b60c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 10) == 0) {
    if ((DAT_00fd9244 & 1) == 0) {
      DAT_00fd9244 = DAT_00fd9244 | 1;
      local_8 = 1;
      FUN_00554410(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcdfc0);
    }
    _DAT_00fd9254 = 0;
  }
  else {
    if ((DAT_00fd9244 & 1) == 0) {
      DAT_00fd9244 = DAT_00fd9244 | 1;
      local_8 = 0;
      FUN_00554410(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcdfc0);
    }
    _DAT_00fd9248 = *(undefined4 *)(param_1 + 2);
    _DAT_00fd924c = *(undefined4 *)(param_1 + 6);
    _DAT_00fd9254 = 1;
  }
  ExceptionList = local_10;
  return 0;
}

