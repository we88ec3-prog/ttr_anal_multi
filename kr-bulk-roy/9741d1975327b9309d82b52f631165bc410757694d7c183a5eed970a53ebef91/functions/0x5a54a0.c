
void FUN_005a54a0(undefined4 param_1)

{
  undefined4 ***pppuVar1;
  undefined4 uVar2;
  undefined4 **local_30 [4];
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_00939b16;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_1c = 7;
  local_20 = 0;
  local_30[0] = (undefined4 **)((uint)local_30[0] & 0xffff0000);
  local_8 = 0;
  switch(param_1) {
  case 0:
    uVar2 = 0x7e;
    break;
  case 1:
    uVar2 = 0x7f;
    goto LAB_005a54f9;
  case 2:
    uVar2 = 0x80;
    break;
  case 3:
    uVar2 = 0x81;
    goto LAB_005a54f9;
  case 4:
    uVar2 = 0x82;
    break;
  case 5:
    uVar2 = 0x83;
LAB_005a54f9:
    FUN_00585620(uVar2,local_14);
    FUN_00585330(uVar2);
    goto LAB_005a553c;
  case 6:
    uVar2 = 0x84;
    break;
  default:
    goto switchD_005a54ec_default;
  }
  FUN_00585620(uVar2,local_14);
  FUN_00585330(uVar2);
LAB_005a553c:
  FUN_0041f490(local_30);
  if (local_20 != 0) {
    pppuVar1 = (undefined4 ***)local_30[0];
    if (local_1c < 8) {
      pppuVar1 = local_30;
    }
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8._0_1_ = 1;
      FUN_004d4d10();
      _atexit((_func_4879 *)&LAB_00bccef0);
      local_8 = (uint)local_8._1_3_ << 8;
    }
    FUN_004d5ae0(&DAT_00fb11e8,0,pppuVar1);
  }
  if (7 < local_1c) {
    FUN_0089120c(local_30[0]);
  }
switchD_005a54ec_default:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

