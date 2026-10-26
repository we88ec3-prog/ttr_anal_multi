
undefined4 FUN_00879750(int param_1)

{
  int in_ECX;
  
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),in_ECX + 8,4,0);
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),in_ECX + 0xc,4,0);
  (**(code **)(*(int *)(in_ECX + 0x10) + 8))(param_1);
  return 1;
}

