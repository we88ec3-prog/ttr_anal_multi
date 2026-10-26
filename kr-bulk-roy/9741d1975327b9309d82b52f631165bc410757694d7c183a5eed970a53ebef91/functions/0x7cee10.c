
void FUN_007cee10(void)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00937bec;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
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
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x89,0);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x9c,1);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x9d,1);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x9b,0);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x9e,0);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x9f,0);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0xa0,0x3f800000);
  (**(code **)(*piVar1 + 0x10c))(piVar1,0,5,2);
  (**(code **)(*piVar1 + 0x10c))(piVar1,0,4,2);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x1b,0);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0xe,1);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0xf,1);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x18,0x6f);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x19,5);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x13,5);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x14,6);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x16,3);
  ExceptionList = local_10;
  return;
}

