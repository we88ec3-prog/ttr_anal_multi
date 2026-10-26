
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004b8f50(undefined4 param_1)

{
  undefined4 uVar1;
  int local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00949167;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0;
    FUN_00587480(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  local_c = 0xffffffff;
  if (DAT_00faadec == 1) {
    FUN_0058a9a0();
  }
  else {
    _DAT_00faadf0 = 1;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  uVar1 = 0;
  if (DAT_00f9392c != 0) {
    DAT_00f9392c = 0;
  }
  local_1c[0] = FUN_00891268(0xbd8c);
  local_c = 2;
  if (local_1c[0] != 0) {
    uVar1 = FUN_004c13e0(local_1c[0]);
  }
  local_c = 0xffffffff;
  FUN_004b7d50();
  FUN_004c22c0(uVar1,param_1);
  local_1c[0] = CONCAT22(local_1c[0]._2_2_,0xf5);
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))(0,local_1c,2);
  }
  ExceptionList = local_14;
  return 0;
}

