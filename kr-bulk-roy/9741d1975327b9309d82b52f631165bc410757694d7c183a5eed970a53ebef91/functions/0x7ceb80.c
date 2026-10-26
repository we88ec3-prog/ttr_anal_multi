
void FUN_007ceb80(void)

{
  int *piVar1;
  undefined1 local_94 [64];
  undefined1 local_54 [64];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00934dda;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(local_14);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  (**(code **)(*DAT_00fb773c + 0x10))(DAT_00fb773c);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 1;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  piVar1 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
  (**(code **)(*piVar1 + 0xb4))(piVar1,2,local_54);
  (**(code **)(*piVar1 + 0xb4))(piVar1,3,local_94);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 2;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  (**(code **)(*DAT_00fb7738 + 0x14))(DAT_00fb7738);
  (**(code **)(*piVar1 + 0xb0))(piVar1,2,local_54);
  (**(code **)(*piVar1 + 0xb0))(piVar1,3,local_94);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x89,0);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x9c,1);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x9d,1);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x9b,0);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x9e,0);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x9f,0);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0xa0,0x3f800000);
  (**(code **)(*piVar1 + 0x10c))(piVar1,0,5,2);
  (**(code **)(*piVar1 + 0x10c))(piVar1,0,6,0);
  (**(code **)(*piVar1 + 0x10c))(piVar1,0,4,4);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x1b,1);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0xe,0);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x13,5);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x14,2);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0xab,3);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x16,3);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

