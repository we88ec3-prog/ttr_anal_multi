
undefined4 FUN_0053a440(int param_1)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092f350;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  switch(*(undefined1 *)(param_1 + 2)) {
  case 0:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 0;
    break;
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
  case 4:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 4;
    break;
  case 5:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 6;
    break;
  case 6:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 7;
    break;
  case 7:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 5;
    break;
  case 8:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 8;
    break;
  case 9:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 9;
    break;
  case 10:
    FUN_004054c0();
    FUN_00402250();
    local_8 = 10;
    break;
  case 0xb:
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 0xb;
    break;
  case 0xc:
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 0xc;
    break;
  case 0xd:
    FUN_004054c0();
    FUN_005854b0();
    FUN_00585330();
    FUN_00402250();
    local_8 = 0xd;
    break;
  default:
    goto switchD_0053a474_default;
  }
  FUN_005854b0();
  uVar1 = FUN_00585330();
  FUN_00402250(uVar1);
  local_8 = 0xffffffff;
  FUN_0058b270(0xca);
switchD_0053a474_default:
  ExceptionList = local_10;
  return 0;
}

