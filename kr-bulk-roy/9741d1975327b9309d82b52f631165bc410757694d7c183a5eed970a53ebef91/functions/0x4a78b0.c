
void FUN_004a78b0(undefined4 *param_1)

{
  undefined2 *unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092774e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fe17b8 & 1) == 0) {
    DAT_00fe17b8 = DAT_00fe17b8 | 1;
    local_8 = 0;
    FUN_0050caf0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce7e0);
  }
  local_8 = 0xffffffff;
  param_1 = (undefined4 *)*param_1;
  FUN_0050db00(&param_1);
  if (DAT_00fe17c4 == 0) {
    *(undefined4 *)(unaff_ESI + 10) = 7;
    *(undefined4 *)(unaff_ESI + 8) = 0;
    *unaff_ESI = 0;
    FUN_00402160(&DAT_00bed1fc,0);
    ExceptionList = local_10;
    return;
  }
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  FUN_004026e0(0x10,0,0xffffffff);
  ExceptionList = local_10;
  return;
}

