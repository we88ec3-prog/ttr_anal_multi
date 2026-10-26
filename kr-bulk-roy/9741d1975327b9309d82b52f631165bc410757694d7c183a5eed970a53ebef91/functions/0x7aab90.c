
void FUN_007aab90(void)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939012;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00fba838 != (int *)0x0) {
    (**(code **)(*DAT_00fba838 + 4))(1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    DAT_00fba838 = (int *)0x0;
  }
  if ((DAT_00fe1bc0 & 1) == 0) {
    DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
    local_8 = 0;
    FUN_007bef00();
    _atexit((_func_4879 *)&LAB_00bcec50);
    local_8 = 0xffffffff;
  }
  FUN_007bf3d0(&DAT_00fe1b60);
  if ((DAT_00fc0f60 & 1) == 0) {
    DAT_00fc0f60 = DAT_00fc0f60 | 1;
    local_8 = 1;
    FUN_0079cf40();
    _atexit((_func_4879 *)&LAB_00bcdb80);
    local_8 = 0xffffffff;
  }
  FUN_0079d3e0();
  if ((DAT_00fd93f0 & 1) == 0) {
    DAT_00fd93f0 = DAT_00fd93f0 | 1;
    local_8 = 2;
    FUN_007ab4e0();
    _atexit((_func_4879 *)&LAB_00bce6a0);
    local_8 = 0xffffffff;
  }
  FUN_007ab770();
  if ((DAT_00fe1770 & 1) == 0) {
    DAT_00fe1770 = DAT_00fe1770 | 1;
    local_8 = 3;
    FUN_007b7da0();
    _atexit((_func_4879 *)&LAB_00bce790);
    local_8 = 0xffffffff;
  }
  FUN_007b7f30(&DAT_00fe173c);
  if ((DAT_00fe1e1c & 1) == 0) {
    DAT_00fe1e1c = DAT_00fe1e1c | 1;
    local_8 = 4;
    FUN_007c30c0();
    _atexit(FUN_00bcf1b0);
    local_8 = 0xffffffff;
  }
  FUN_007c2d50(&DAT_00fe1e0c);
  if ((DAT_00fe324c & 1) == 0) {
    DAT_00fe324c = DAT_00fe324c | 1;
    local_8 = 5;
    FUN_007cdeb0();
    _atexit((_func_4879 *)&LAB_00bd09b0);
    local_8 = 0xffffffff;
  }
  FUN_007cf990(&DAT_00fe3250);
  if ((DAT_00fe1ac0 & 1) == 0) {
    DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
    local_8 = 6;
    FUN_007bb970();
    _atexit((_func_4879 *)&LAB_00bceac0);
  }
  ExceptionList = local_10;
  return;
}

