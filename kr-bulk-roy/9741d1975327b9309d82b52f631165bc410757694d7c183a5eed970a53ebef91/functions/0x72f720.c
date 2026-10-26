
void FUN_0072f720(FILE *param_1,undefined4 param_2)

{
  int *piVar1;
  int in_ECX;
  
  for (piVar1 = *(int **)(in_ECX + 0x18); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x10]) {
    (**(code **)(*piVar1 + 4))(param_1,param_2);
    _fprintf(param_1,"\n");
  }
  return;
}

