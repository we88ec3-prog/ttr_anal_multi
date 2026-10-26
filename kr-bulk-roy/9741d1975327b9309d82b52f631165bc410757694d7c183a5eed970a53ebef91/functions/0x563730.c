
void FUN_00563730(float param_1,undefined4 param_2,int param_3)

{
  int in_ECX;
  
  FUN_0082ef00(&param_1);
  if ((in_ECX != *(int *)(in_ECX + 0x1c)) && (*(int **)(in_ECX + 0x10) != (int *)0x0)) {
    param_1 = (float)param_3;
    (**(code **)(**(int **)(in_ECX + 0x10) + 0x6c))(param_2,(param_3 < 0) - 1 & (uint)&param_1);
  }
  return;
}

