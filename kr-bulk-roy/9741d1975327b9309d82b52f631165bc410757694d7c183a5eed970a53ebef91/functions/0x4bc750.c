
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004bc750(void)

{
  int iVar1;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009448b1;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 0;
    FUN_00539c20(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&LAB_00bccfb0);
  }
  local_c = 0xffffffff;
  FUN_0053b7e0(&DAT_00fb1380);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 1;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  if ((DAT_00fab100 & 1) == 0) {
    DAT_00fab100 = DAT_00fab100 | 1;
    local_c = 2;
    FUN_0049d6a0();
    _atexit((_func_4879 *)&LAB_00bcce20);
    local_c = 0xffffffff;
  }
  if (DAT_00fba7a4 != (int *)0x0) {
    if (DAT_00fba7ac == 2) {
      FUN_00544f50();
      goto LAB_004bc880;
    }
    (**(code **)(*DAT_00fba7a4 + 0x28))();
    if (DAT_00fba7a4 != (int *)0x0) {
      (**(code **)*DAT_00fba7a4)(1);
    }
  }
  iVar1 = FUN_00891268(0xc0);
  local_c = 4;
  if (iVar1 == 0) {
    DAT_00fba7a4 = (int *)0x0;
  }
  else {
    DAT_00fba7a4 = (int *)FUN_00548540(iVar1);
  }
  local_c = 0xffffffff;
  (**(code **)(*DAT_00fba7a4 + 0x24))();
LAB_004bc880:
  if ((DAT_00fb72a4 & 1) == 0) {
    DAT_00fb72a4 = DAT_00fb72a4 | 1;
    local_c = 10;
    FUN_0049f850();
    _atexit((_func_4879 *)&LAB_00bccfe0);
    local_c = 0xffffffff;
  }
  FUN_004e0fc0(&DAT_00fb72b8);
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0xb;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  if (DAT_00faadec != 5) {
    _DAT_00faadf0 = 5;
    ExceptionList = local_14;
    return 0;
  }
  FUN_0058a9a0();
  ExceptionList = local_14;
  return 0;
}

