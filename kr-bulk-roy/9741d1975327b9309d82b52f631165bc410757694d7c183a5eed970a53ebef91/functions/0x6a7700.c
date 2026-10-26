
void FUN_006a7700(void)

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
  FUN_0043c570(1000);
  FUN_0043c570(2000);
  FUN_0043c570(3000);
  FUN_0043c570(4000);
  FUN_0043c570(5000);
  FUN_006a7a20();
  FUN_0043c570(9000);
  FUN_00615fc0(0x44c);
  FUN_00615fc0(0x4b0);
  FUN_00615fc0(0x514);
  FUN_00615fc0(0x578);
  return;
}

