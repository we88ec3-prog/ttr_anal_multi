
void FUN_006438b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  int *piVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x24) != 0) &&
     (piVar1 = *(int **)(*(int *)(in_ECX + 0x24) + 0x165b4), piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0x1c))();
  }
  FUN_00762350(param_1,param_2,param_3,param_4,param_5);
  return;
}

