
void FUN_005634e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_ECX;
  
  FUN_0082ef00(&param_1);
  if ((in_ECX != *(int *)(in_ECX + 0x1c)) && (*(int **)(in_ECX + 0x10) != (int *)0x0)) {
    (**(code **)(**(int **)(in_ECX + 0x10) + 0x68))(param_2,param_3);
  }
  return;
}

