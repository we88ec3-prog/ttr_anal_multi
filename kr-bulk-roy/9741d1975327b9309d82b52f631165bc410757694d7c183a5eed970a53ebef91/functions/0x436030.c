
void FUN_00436030(int param_1,undefined1 param_2)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00931c88;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  switch(param_2) {
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
    local_8 = 2;
    break;
  case 2:
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 1;
    break;
  case 3:
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 3;
    break;
  case 4:
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 4;
    break;
  default:
    goto switchD_00436061_default;
  }
  FUN_005854b0();
  uVar1 = FUN_00585330();
  FUN_00402250(uVar1);
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
switchD_00436061_default:
  *(undefined1 *)(param_1 + 0x158) = 0;
  ExceptionList = local_10;
  return;
}

