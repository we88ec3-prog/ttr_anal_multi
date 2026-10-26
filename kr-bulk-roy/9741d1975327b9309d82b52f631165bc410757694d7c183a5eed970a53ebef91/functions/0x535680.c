
undefined4 FUN_00535680(int param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092f4b0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  switch(*(undefined1 *)(param_1 + 2)) {
  case 0:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 0;
    FUN_005854b0();
    uVar1 = FUN_00585330();
    goto LAB_00535781;
  case 1:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 1;
    break;
  case 2:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 2;
    break;
  case 3:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 3;
    break;
  default:
    goto switchD_005356b6_default;
  }
  FUN_005854b0();
  uVar1 = FUN_00585330();
LAB_00535781:
  FUN_00402250(uVar1);
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
switchD_005356b6_default:
  if (DAT_00fba798 == 0) {
    (**(code **)(*DAT_00fba854 + 0x10))();
  }
  ExceptionList = local_10;
  return 0;
}

