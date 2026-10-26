
void FUN_005f6180(int param_1)

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
  if (param_1 == 100) {
    FUN_005f61d0();
  }
  return;
}

