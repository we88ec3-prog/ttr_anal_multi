
void FUN_006173d0(void)

{
  undefined4 uVar1;
  int in_ECX;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0xb;
  FUN_0082ef00(&local_8);
  if (local_c == *(int *)(in_ECX + 0x50)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(undefined4 *)(local_c + 0x10);
  }
  *(undefined4 *)(in_ECX + 0x80) = uVar1;
  FUN_00615fc0(0xc1c);
  FUN_00615fc0(0x1004);
  FUN_00643ce0(10000);
  FUN_00643ce0(11000);
  FUN_0043c570(8000);
  FUN_0043c570(7000);
  FUN_00618a20();
  FUN_0043c570(13000);
  (**(code **)(**(int **)(in_ECX + 0xec) + 0x198))(0xc1d);
  (**(code **)(**(int **)(in_ECX + 0xf0) + 0x198))(0x1005);
  return;
}

