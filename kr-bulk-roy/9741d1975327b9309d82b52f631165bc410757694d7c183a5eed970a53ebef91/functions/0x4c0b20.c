
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c0b20(void)

{
  undefined1 local_6 [2];
  
  if ((_DAT_00fb734c & 1) == 0) {
    _DAT_00fb734c = _DAT_00fb734c | 1;
    DAT_00fb7350 = '\x01';
    _atexit((_func_4879 *)&DAT_00bcd0b0);
  }
  if (DAT_00fb7350 != '\0') {
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,local_6,2);
    }
    if ((_DAT_00fb734c & 1) == 0) {
      _DAT_00fb734c = _DAT_00fb734c | 1;
      DAT_00fb7350 = 1;
      _atexit((_func_4879 *)&DAT_00bcd0b0);
    }
    DAT_00fb7350 = '\0';
  }
  return;
}

