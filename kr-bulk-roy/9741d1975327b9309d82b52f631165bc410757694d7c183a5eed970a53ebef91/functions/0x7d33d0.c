
void FUN_007d33d0(undefined4 param_1,int param_2)

{
  int in_ECX;
  
  if (0.99 <= *(float *)(in_ECX + 0x5c)) {
    FUN_007eede0();
    FUN_007d40c0();
    (**(code **)(**(int **)(in_ECX + 0x10) + 0x28))(param_1);
  }
  else if (param_2 != *(int *)(in_ECX + 4)) {
    FUN_007eede0();
    FUN_007d40c0();
    (**(code **)(**(int **)(in_ECX + 0x10) + 0x28))(param_1);
    FUN_007eede0();
    FUN_007d40c0();
    (**(code **)(**(int **)(in_ECX + 0x10) + 0x28))(param_1);
    return;
  }
  return;
}

