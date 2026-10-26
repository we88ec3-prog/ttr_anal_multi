
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c4b10(void)

{
  int iVar1;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093a551;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((_DAT_00fd2cf0 & 1) == 0) {
    _DAT_00fd2cf0 = _DAT_00fd2cf0 | 1;
    FUN_00738090(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&DAT_00bce680);
  }
  if (DAT_00fd2bb8 != 0) {
    _DAT_00fd2bc4 = 1;
    _DAT_00fd2bc8 = 200;
    if (DAT_00fd2cd0 != (int *)0x0) {
      (**(code **)(*DAT_00fd2cd0 + 8))();
      DAT_00fd2cd0 = (int *)0x0;
    }
    _DAT_00fd2cd4 = 0;
    _DAT_00fd2bcc = 1;
    _DAT_00fd2ce8 = 1;
  }
  (**(code **)(*DAT_00fba7a4 + 0x14))();
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    uStack_c = 0;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    uStack_c = 0xffffffff;
  }
  FUN_004dfe90(&DAT_00fab130);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    uStack_c = 1;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    uStack_c = 0xffffffff;
  }
  DAT_00fab228 = 0;
  FUN_004e1070(&DAT_00fab148);
  if ((DAT_00fe18c8 & 1) == 0) {
    DAT_00fe18c8 = DAT_00fe18c8 | 1;
    uStack_c = 2;
    FUN_0053f970();
    _atexit((_func_4879 *)&LAB_00bce810);
    uStack_c = 0xffffffff;
  }
  if (DAT_00fe18cc != DAT_00fe18d0) {
    DAT_00fe18d0 = DAT_00fe18cc;
  }
  if ((DAT_00fc0f80 & 1) == 0) {
    DAT_00fc0f80 = DAT_00fc0f80 | 1;
    uStack_c = 3;
    FUN_0047aeb0();
    _atexit((_func_4879 *)&LAB_00bcdb70);
    uStack_c = 0xffffffff;
  }
  FUN_004a8c20();
  if (DAT_00fba7a4 != (int *)0x0) {
    if (DAT_00fba7ac == 4) {
      FUN_00544f50();
      goto LAB_004c4d0d;
    }
    (**(code **)(*DAT_00fba7a4 + 0x28))();
    if (DAT_00fba7a4 != (int *)0x0) {
      (**(code **)*DAT_00fba7a4)(1);
    }
  }
  iVar1 = FUN_00891268(0x138);
  uStack_c = 8;
  if (iVar1 == 0) {
    DAT_00fba7a4 = (int *)0x0;
  }
  else {
    DAT_00fba7a4 = (int *)FUN_00548b90();
  }
  uStack_c = 0xffffffff;
  (**(code **)(*DAT_00fba7a4 + 0x24))();
LAB_004c4d0d:
  if ((DAT_00fc0f80 & 1) == 0) {
    DAT_00fc0f80 = DAT_00fc0f80 | 1;
    uStack_c = 0xb;
    FUN_0047aeb0();
    _atexit((_func_4879 *)&LAB_00bcdb70);
    uStack_c = 0xffffffff;
  }
  FUN_004a8a60();
  ExceptionList = local_14;
  return 0;
}

