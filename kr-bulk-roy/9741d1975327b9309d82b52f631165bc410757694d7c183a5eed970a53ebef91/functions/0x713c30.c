
undefined4 FUN_00713c30(int param_1,int param_2)

{
  int in_ECX;
  
  if (param_2 == 0) {
    *(int *)(in_ECX + 8) = param_1;
  }
  else {
    if (param_2 == 1) {
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
      return 0;
    }
    if (param_2 == 2) {
      *(int *)(in_ECX + 8) = *(int *)(*(int *)(in_ECX + 0x14) + 0x4c) - param_1;
      return 0;
    }
  }
  return 0;
}

