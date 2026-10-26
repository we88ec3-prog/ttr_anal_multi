
undefined4 FUN_0087a4d0(int param_1)

{
  int in_ECX;
  
  if (in_ECX + 8 != 0) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),in_ECX + 8,4,0);
  }
  if (in_ECX + 0xc != 0) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),in_ECX + 0xc,4,0);
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0xc))(param_1);
  return 1;
}

