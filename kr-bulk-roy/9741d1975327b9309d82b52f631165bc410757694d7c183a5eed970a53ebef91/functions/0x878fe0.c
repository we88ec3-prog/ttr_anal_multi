
undefined4 FUN_00878fe0(int param_1)

{
  int in_ECX;
  int aiStack_10 [3];
  
  (**(code **)(*(int *)(in_ECX + 4) + 0x10))(param_1);
  aiStack_10[0] = (*(int *)(in_ECX + 0x2c) - *(int *)(in_ECX + 0x28)) / 0xc;
  FUN_00721910(*(undefined4 *)(param_1 + 0x88),aiStack_10,4,0);
  if (in_ECX + 0x38 != 0) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),in_ECX + 0x38,4,0);
  }
  return 1;
}

