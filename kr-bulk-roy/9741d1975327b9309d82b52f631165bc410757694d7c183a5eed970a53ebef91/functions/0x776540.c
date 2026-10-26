
undefined4 FUN_00776540(int param_1)

{
  int in_ECX;
  
  if (param_1 != 0) {
    FUN_00764810(param_1);
    FUN_00776b00(*(undefined4 *)(in_ECX + 0x28));
    FUN_00776b00(*(undefined4 *)(in_ECX + 0x30));
    FUN_00776b00(*(undefined4 *)(in_ECX + 0x2c));
    FUN_00776b00(*(undefined4 *)(in_ECX + 0x34));
    return 1;
  }
  return 0;
}

