
void FUN_00552d20(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int in_ECX;
  int in_EDX;
  
  if (in_EDX != in_ECX) {
    if (*(int *)(in_EDX + 4) == 0x7fffffe) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("list<T> too long");
    }
    *(int *)(in_EDX + 4) = *(int *)(in_EDX + 4) + 1;
    *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + -1;
  }
  **(int **)(param_2 + 4) = param_3;
  **(int **)(param_3 + 4) = param_1;
  **(int **)(param_1 + 4) = param_2;
  uVar1 = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_3 + 4);
  *(undefined4 *)(param_3 + 4) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(param_2 + 4) = uVar1;
  return;
}

