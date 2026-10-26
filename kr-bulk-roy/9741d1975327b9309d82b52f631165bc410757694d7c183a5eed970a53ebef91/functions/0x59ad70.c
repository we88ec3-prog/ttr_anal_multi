
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059ad70(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x3c) != 0) && ((*(uint *)(in_ECX + 0x28) & 0x40000) == 0)) {
    FUN_00746c10();
  }
  if ((_DAT_00f8d910 & 1) == 0) {
    _DAT_00f8d910 = _DAT_00f8d910 | 1;
    _atexit((_func_4879 *)&DAT_00bccc60);
  }
  if (DAT_00f8d914 != 0) {
    FUN_00746c10();
  }
  if ((_DAT_00f8d8a8 & 1) == 0) {
    _DAT_00f8d8a8 = _DAT_00f8d8a8 | 1;
    FUN_005e93a0();
    _atexit((_func_4879 *)&DAT_00bccc40);
  }
  FUN_005e9c70(&DAT_00f8d8b0);
  if ((_DAT_00fc0db0 & 1) == 0) {
    _DAT_00fc0db0 = _DAT_00fc0db0 | 1;
    DAT_00fc0db4 = 0;
    DAT_00fc0db8 = 0;
    DAT_00fc0dbc = 0;
    DAT_00fc0dc0 = 0;
    _atexit((_func_4879 *)&DAT_00bcd9e0);
  }
  if (DAT_00fc0db4 != 0) {
    FUN_00746c10();
  }
  if (DAT_00fc0db8 != 0) {
    FUN_00746c10();
  }
  if (DAT_00fc0dbc != 0) {
    FUN_00746c10();
  }
  if (DAT_00fc0dc0 != 0) {
    FUN_00746c10();
  }
  if ((_DAT_00fe2c60 & 1) == 0) {
    _DAT_00fe2c60 = _DAT_00fe2c60 | 1;
    DAT_00fe2c64 = 0;
    _atexit((_func_4879 *)&DAT_00bcf430);
  }
  if (DAT_00fe2c64 != 0) {
    FUN_00746c10();
  }
  if ((_DAT_00fe2c78 & 1) == 0) {
    _DAT_00fe2c78 = _DAT_00fe2c78 | 1;
    DAT_00fe2c7c = 0;
    _atexit((_func_4879 *)&DAT_00bcf440);
  }
  if (DAT_00fe2c7c != 0) {
    FUN_00746c10();
  }
  if ((_DAT_00fe2c68 & 1) == 0) {
    _DAT_00fe2c68 = _DAT_00fe2c68 | 1;
    DAT_00fe2c6c = 0;
    _atexit((_func_4879 *)&DAT_00bcf450);
  }
  if (DAT_00fe2c6c != 0) {
    FUN_00746c10();
    return;
  }
  return;
}

