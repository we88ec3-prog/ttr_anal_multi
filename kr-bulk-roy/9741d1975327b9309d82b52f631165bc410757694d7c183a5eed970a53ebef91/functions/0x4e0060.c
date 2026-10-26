
void FUN_004e0060(void)

{
  int *piVar1;
  int in_ECX;
  uint local_30;
  float local_20;
  float local_1c;
  float local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar1 = DAT_00fba7a4;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b1ba;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (0.0 < *(float *)(in_ECX + 0xac)) {
    DAT_00fba7a4[0x16] = 1;
  }
  (**(code **)(*piVar1 + 0x2c))(local_14);
  local_30 = local_30 & 0xffffff00;
  FUN_004e13f0(**(undefined4 **)(in_ECX + 0xc),*(undefined4 **)(in_ECX + 0xc),local_30);
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_8 = 0;
    FUN_00560170();
    _atexit((_func_4879 *)&LAB_00bcd110);
    local_8 = 0xffffffff;
  }
  if (DAT_00fb73e8 != 0) {
    if ((DAT_00fab0d4 & 1) == 0) {
      DAT_00fab0d4 = DAT_00fab0d4 | 1;
      local_8 = 1;
      FUN_0080a3a0();
      _atexit((_func_4879 *)&LAB_00bccdd0);
      local_8 = 0xffffffff;
    }
    if ((DAT_00fab090 == (int *)0x0) && (DAT_00fab028 != (int *)0x0)) {
      DAT_00fab090 = (int *)(**(code **)(*DAT_00fab028 + 0x20))();
      (**(code **)(*DAT_00fab090 + 0x18))(3);
    }
    piVar1 = DAT_00fab090;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 2;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    local_20 = *(float *)(DAT_00fb76e8 + 0xc) * 0.1;
    local_1c = *(float *)(DAT_00fb76e8 + 0x10) * 0.1;
    local_18 = *(float *)(DAT_00fb76e8 + 0x14) * 0.1;
    (**(code **)(*piVar1 + 0xc))(&local_20);
  }
  FUN_006d6ed0(in_ECX + 0xd0);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

