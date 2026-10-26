
void FUN_006a6800(void)

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
  FUN_006a7050();
  FUN_00615fc0(15000);
  FUN_00615fc0(16000);
  FUN_00615fc0(17000);
  FUN_00615fc0(18000);
  return;
}

