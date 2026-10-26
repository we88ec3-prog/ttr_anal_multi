
undefined4 FUN_005b97a0(uint param_1)

{
  undefined4 uVar1;
  
  if (DAT_00fbab38 == 0) {
    if (param_1 < 0x2914) {
      if (param_1 == 0x2913) {
        FUN_005b6fa0();
        return 1;
      }
      if (param_1 == 0xd) {
        uVar1 = FUN_005ba2e0();
        return uVar1;
      }
      if (param_1 == 0xe) {
        uVar1 = FUN_005ba430();
        return uVar1;
      }
      if (param_1 == 0x290e) {
        FUN_005b8b40();
        return 1;
      }
    }
    else {
      if (param_1 == 0x2914) {
        FUN_005b7300(0);
        return 1;
      }
      if (param_1 == 0x2915) {
        FUN_005b75e0();
        return 1;
      }
      if (param_1 == 0x2af9) {
        FUN_0059a230();
        return 1;
      }
    }
  }
  uVar1 = FUN_0059cc50(param_1);
  return uVar1;
}

