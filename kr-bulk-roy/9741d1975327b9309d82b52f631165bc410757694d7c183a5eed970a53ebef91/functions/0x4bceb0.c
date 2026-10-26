
undefined4 FUN_004bceb0(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009276dc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb7354 & 1) == 0) {
    DAT_00fb7354 = DAT_00fb7354 | 1;
    local_8 = 0;
    FUN_005533d0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd100);
  }
  local_8 = 0xffffffff;
  FUN_00553740();
  if ((DAT_00fe18c8 & 1) == 0) {
    DAT_00fe18c8 = DAT_00fe18c8 | 1;
    local_8 = 1;
    FUN_0053f970();
    _atexit((_func_4879 *)&LAB_00bce810);
  }
  if (DAT_00fe18cc != DAT_00fe18d0) {
    DAT_00fe18d0 = DAT_00fe18cc;
  }
  ExceptionList = local_10;
  return 0;
}

