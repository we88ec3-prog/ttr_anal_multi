
undefined4 FUN_004a30c0(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_004a2ec0();
  if ((DAT_00fc0d94 & 1) == 0) {
    DAT_00fc0d94 = DAT_00fc0d94 | 1;
    FUN_0046fa20();
    _atexit(FUN_00bcd950);
  }
  FUN_004a2c10();
  return uVar1;
}

