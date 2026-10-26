
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00565490(int param_1,int param_2,undefined4 param_3)

{
  if (param_1 != 0) {
    if ((_DAT_00fd8f0c & 1) == 0) {
      _DAT_00fd8f0c = _DAT_00fd8f0c | 1;
      FUN_00559120();
      _atexit((_func_4879 *)&DAT_00bcdf60);
    }
    _DAT_00fd8f34 = 0x3f800000;
    _DAT_00fd8f3c = 0x3c;
    _DAT_00fd8f38 = 0x437f0000;
    _DAT_00fd8f44 = param_3;
  }
  if (param_2 != 0) {
    if ((_DAT_00fd8f0c & 1) == 0) {
      _DAT_00fd8f0c = _DAT_00fd8f0c | 1;
      FUN_00559120();
      _atexit((_func_4879 *)&DAT_00bcdf60);
    }
    _DAT_00fd8f64 = 0x24;
    _DAT_00fd8f5c = 0x3f800000;
    _DAT_00fd8f60 = 0x437f0000;
    _DAT_00fd8f84 = 0xe;
    _DAT_00fd8f7c = 0x3f800000;
    _DAT_00fd8f80 = 0x437f0000;
  }
  return;
}

