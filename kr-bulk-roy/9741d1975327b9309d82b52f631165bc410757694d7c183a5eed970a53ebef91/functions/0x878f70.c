
undefined4 FUN_00878f70(int param_1)

{
  int in_ECX;
  undefined4 auStack_10 [3];
  
  (**(code **)(*(int *)(in_ECX + 4) + 0x14))(param_1);
  auStack_10[0] = 0;
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),auStack_10,4,0);
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),in_ECX + 0x38,4,0);
  FUN_008790b0();
  FUN_00879100();
  return 1;
}

