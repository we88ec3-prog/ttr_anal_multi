
byte FUN_008fbd60(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 local_28;
  
  iVar1 = FUN_008fba60(0x38);
  if (iVar1 != 0) {
    return 6;
  }
  iVar1 = FUN_008fb0b0(4);
  if (iVar1 == 1) {
    *param_3 = local_28;
    iVar1 = FUN_008fb070();
  }
  else {
    FUN_008fb070();
    if (iVar1 == 0) {
      return 10;
    }
  }
  if (iVar1 != -4) {
    if (iVar1 == -5) {
      return 10;
    }
    return (iVar1 != -3) - 1U & 8;
  }
  return 0x40;
}

