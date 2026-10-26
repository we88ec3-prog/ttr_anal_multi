
void FUN_00677f30(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint in_EAX;
  int in_EDX;
  int unaff_ESI;
  
  if (in_EDX != unaff_ESI) {
    if (0x3ffffffeU - *(int *)(in_EDX + 4) < in_EAX) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("list<T> too long");
    }
    *(uint *)(in_EDX + 4) = *(int *)(in_EDX + 4) + in_EAX;
    *(int *)(unaff_ESI + 4) = *(int *)(unaff_ESI + 4) - in_EAX;
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

