
void FUN_007d81d0(void)

{
  int *piVar1;
  undefined4 local_d8;
  undefined1 local_d4 [64];
  undefined1 local_94 [64];
  undefined1 local_54 [64];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00934d2a;
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
  piVar1 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
  (**(code **)(*piVar1 + 0xb4))(piVar1,2,local_54);
  (**(code **)(*piVar1 + 0xb4))(piVar1,3,local_94);
  (**(code **)(*piVar1 + 0xe8))(piVar1,8,&local_d8);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 1;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  (**(code **)(*DAT_00fb773c + 0x10))(DAT_00fb773c);
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
  (**(code **)(*piVar1 + 0xe4))(piVar1,8,local_d8);
  if (*(int *)(*(int *)(*(int *)(DAT_00fba838 + 0x54) + 0xc) + 0xc) != 0) {
    FUN_007d7260();
  }
  (**(code **)(*piVar1 + 0x104))(piVar1,1,0);
  (**(code **)(*piVar1 + 0x104))(piVar1,2,0);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x16,2);
  (**(code **)(*piVar1 + 0xe4))(piVar1,7,1);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x17,4);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x1b,1);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0xf,0);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x13,5);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x14,6);
  (**(code **)(*piVar1 + 0x10c))(piVar1,0,4,2);
  (**(code **)(*piVar1 + 0x10c))(piVar1,0,5,2);
  (**(code **)(*piVar1 + 0x10c))(piVar1,0,1,2);
  (**(code **)(*piVar1 + 0x10c))(piVar1,0,2,2);
  (**(code **)(*piVar1 + 0x10c))(piVar1,1,4,1);
  (**(code **)(*piVar1 + 0x10c))(piVar1,1,1,1);
  (**(code **)(*piVar1 + 0x10c))(piVar1,0,0xb,0);
  (**(code **)(*piVar1 + 0x10c))(piVar1,0,0x18,0);
  (**(code **)(*piVar1 + 0x114))(piVar1,0,7,2);
  (**(code **)(*piVar1 + 0x114))(piVar1,0,6,2);
  (**(code **)(*piVar1 + 0x114))(piVar1,0,5,2);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0xe,0);
  (**(code **)(*piVar1 + 0x164))(piVar1,0x112);
  (**(code **)(*piVar1 + 0xe4))(piVar1,0x98,0);
  D3DXMatrixTranslation(local_d4,0,0,0x3d4ccccd);
  (**(code **)(*piVar1 + 0xb0))(piVar1,0x100,local_d4);
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

