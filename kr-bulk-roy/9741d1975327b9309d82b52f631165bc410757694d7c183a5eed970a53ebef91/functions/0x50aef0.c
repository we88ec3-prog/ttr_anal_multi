
undefined4 FUN_0050aef0(int param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00933bb6;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  switch(*(undefined1 *)(param_1 + 2)) {
  case 1:
    FUN_005854b0();
    FUN_00585330();
    FUN_005854b0();
    FUN_00585330();
    FUN_00404b10();
    goto switchD_0050af29_default;
  case 2:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 0;
    break;
  case 3:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 1;
    break;
  case 4:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 2;
    break;
  default:
    goto switchD_0050af29_default;
  }
  FUN_005854b0();
  uVar1 = FUN_00585330();
  FUN_00402250(uVar1);
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
switchD_0050af29_default:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 3;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058afa0();
  ExceptionList = local_10;
  return 0;
}

