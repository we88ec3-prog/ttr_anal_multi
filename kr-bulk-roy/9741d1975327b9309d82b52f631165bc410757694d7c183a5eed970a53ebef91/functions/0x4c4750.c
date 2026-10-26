
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c4750(void)

{
  int iVar1;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00936b67;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  if (DAT_00fba7a4 != (int *)0x0) {
    if (DAT_00fba7ac == 3) {
      FUN_00544f50();
      goto LAB_004c481e;
    }
    (**(code **)(*DAT_00fba7a4 + 0x28))();
    if (DAT_00fba7a4 != (int *)0x0) {
      (**(code **)*DAT_00fba7a4)(1);
    }
  }
  iVar1 = FUN_00891268(200);
  local_c = 3;
  if (iVar1 == 0) {
    DAT_00fba7a4 = (int *)0x0;
  }
  else {
    DAT_00fba7a4 = (int *)FUN_00547390(iVar1);
  }
  local_c = 0xffffffff;
  (**(code **)(*DAT_00fba7a4 + 0x24))();
LAB_004c481e:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 8;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  if (DAT_00faadec != 7) {
    _DAT_00faadf0 = 7;
    ExceptionList = local_14;
    return 0;
  }
  FUN_0058a9a0();
  ExceptionList = local_14;
  return 0;
}

