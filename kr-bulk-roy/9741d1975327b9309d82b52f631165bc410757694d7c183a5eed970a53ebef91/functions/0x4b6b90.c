
undefined4 FUN_004b6b90(int param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009309f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  switch(*(undefined1 *)(param_1 + 2)) {
  case 0:
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 0;
    break;
  case 1:
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 1;
    break;
  case 2:
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 2;
    break;
  case 3:
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 3;
    break;
  default:
    goto switchD_004b6bc4_default;
  }
  FUN_005854b0();
  uVar1 = FUN_00585330();
  FUN_00402250(uVar1);
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
switchD_004b6bc4_default:
  ExceptionList = local_10;
  return 0;
}

