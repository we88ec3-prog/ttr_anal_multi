
void FUN_0063f690(void)

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
  FUN_0046b6f0(0x7d2);
  FUN_0046b6f0(0xbba);
  FUN_0046b6f0(0xfa2);
  FUN_0046b6f0(0x138a);
  FUN_00640180();
  FUN_00640270();
  FUN_00640360();
  FUN_00615fc0(0x2198);
  FUN_00615fc0(0x21fc);
  FUN_00615fc0(0x2260);
  return;
}

