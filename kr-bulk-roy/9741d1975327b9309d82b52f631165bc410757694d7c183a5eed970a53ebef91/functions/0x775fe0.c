
void FUN_00775fe0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0xc))
              (param_1,param_2,0xffffffff,param_3,param_4,param_5);
  }
  return;
}

