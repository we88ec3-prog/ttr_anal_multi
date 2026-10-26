
undefined4 FUN_008295e0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int in_EAX;
  int in_ECX;
  
  FUN_00835c70(&param_1);
  if (in_ECX != *(int *)(in_EAX + 4)) {
    FUN_008438c0(&param_2);
    if (param_1 != *(int *)(in_ECX + 0x14)) {
      *param_3 = *(undefined4 *)(param_1 + 0x10);
      return 1;
    }
  }
  return 0;
}

