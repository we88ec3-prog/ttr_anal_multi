
void FUN_007aad40(undefined4 param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093a038;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  FUN_007997a0(param_1);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 1;
    FUN_00798de0(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  (**(code **)(*DAT_00fb76a8 + 0xb4))();
  (**(code **)(*DAT_00fb76a8 + 0xc0))("pack.gms");
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 2;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  FUN_007998a0(&DAT_00fb76a8);
  if ((DAT_00fd94d8 & 1) == 0) {
    DAT_00fd94d8 = DAT_00fd94d8 | 1;
    local_8 = 3;
    FUN_007b5430();
    _atexit((_func_4879 *)&LAB_00bce660);
    local_8 = 0xffffffff;
  }
  if ((DAT_00fe1ac0 & 1) == 0) {
    DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
    local_8 = 4;
    FUN_007bb970();
    _atexit((_func_4879 *)&LAB_00bceac0);
    local_8 = 0xffffffff;
  }
  FUN_007bbb90(&DAT_00fe1ac8);
  if ((DAT_00fe324c & 1) == 0) {
    DAT_00fe324c = DAT_00fe324c | 1;
    local_8 = 5;
    FUN_007cdeb0();
    _atexit((_func_4879 *)&LAB_00bd09b0);
    local_8 = 0xffffffff;
  }
  FUN_007cf600(&DAT_00fe3250);
  if ((DAT_00fd93f0 & 1) == 0) {
    DAT_00fd93f0 = DAT_00fd93f0 | 1;
    local_8 = 6;
    FUN_007ab4e0();
    _atexit((_func_4879 *)&LAB_00bce6a0);
    local_8 = 0xffffffff;
  }
  FUN_007ab7d0(&DAT_00fd92a0);
  if ((DAT_00fe1770 & 1) == 0) {
    DAT_00fe1770 = DAT_00fe1770 | 1;
    local_8 = 7;
    FUN_007b7da0();
    _atexit((_func_4879 *)&LAB_00bce790);
    local_8 = 0xffffffff;
  }
  FUN_007b7fd0(&DAT_00fe173c);
  if ((DAT_00fe1e1c & 1) == 0) {
    DAT_00fe1e1c = DAT_00fe1e1c | 1;
    local_8 = 8;
    FUN_007c30c0();
    _atexit(FUN_00bcf1b0);
    local_8 = 0xffffffff;
  }
  FUN_007c2070();
  if ((DAT_00fc125c & 1) == 0) {
    DAT_00fc125c = DAT_00fc125c | 1;
    local_8 = 9;
    FUN_007b7260();
    _atexit((_func_4879 *)&LAB_00bce650);
    local_8 = 0xffffffff;
  }
  FUN_007b75d0();
  if ((DAT_00fc0f60 & 1) == 0) {
    DAT_00fc0f60 = DAT_00fc0f60 | 1;
    local_8 = 10;
    FUN_0079cf40();
    _atexit((_func_4879 *)&LAB_00bcdb80);
    local_8 = 0xffffffff;
  }
  FUN_0079d480();
  if ((DAT_00fe1bc0 & 1) == 0) {
    DAT_00fe1bc0 = DAT_00fe1bc0 | 1;
    local_8 = 0xb;
    FUN_007bef00();
    _atexit((_func_4879 *)&LAB_00bcec50);
    local_8 = 0xffffffff;
  }
  FUN_007bf540(&DAT_00fe1b60);
  (**(code **)(*DAT_00fba838 + 8))();
  ExceptionList = local_10;
  return;
}

