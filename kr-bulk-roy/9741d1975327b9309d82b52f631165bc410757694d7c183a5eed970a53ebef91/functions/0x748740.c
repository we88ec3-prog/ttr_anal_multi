
void FUN_00748740(int *param_1,int *param_2,int param_3,int param_4,int *param_5)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  if (((((*(uint *)(in_ECX + 0x28) >> 8 & 1) != 0) && (*(int *)(in_ECX + 0x2c) <= param_3)) &&
      (param_3 <= *(int *)(in_ECX + 0x34))) &&
     ((*(int *)(in_ECX + 0x30) <= param_4 && (param_4 <= *(int *)(in_ECX + 0x38))))) {
    piVar1 = *(int **)(in_ECX + 100);
    piVar2 = (int *)*piVar1;
    for (; piVar1 != piVar2; piVar1 = (int *)piVar1[1]) {
      FUN_00748740(param_1,param_2,param_3,param_4,param_5);
      if (*param_1 != 0) {
        return;
      }
    }
    if (*param_2 == 0) {
      *param_2 = in_ECX;
    }
    if (param_5 != (int *)0x0) {
      (**(code **)(*param_5 + 4))(in_ECX,param_1);
    }
  }
  return;
}

