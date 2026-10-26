
undefined4 FUN_004f1dc0(int param_1)

{
  short sVar1;
  short *psVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093b09c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_8 = 0;
    FUN_00560170();
    _atexit((_func_4879 *)&LAB_00bcd110);
  }
  local_8 = 0xffffffff;
  if (DAT_00fb73e8 == 0) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 1;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    psVar2 = (short *)(param_1 + 10);
    do {
      sVar1 = *psVar2;
      psVar2 = psVar2 + 1;
    } while (sVar1 != 0);
    FUN_00402160((short *)(param_1 + 10),(int)psVar2 - (param_1 + 0xc) >> 1);
    FUN_0058adb0(*(undefined4 *)(param_1 + 6),*(undefined4 *)(param_1 + 2));
  }
  else {
    FUN_004f3000();
  }
  ExceptionList = local_10;
  return 0;
}

