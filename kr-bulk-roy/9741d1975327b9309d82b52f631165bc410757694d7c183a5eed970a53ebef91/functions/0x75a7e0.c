
void FUN_0075a7e0(int param_1,int *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_00404fd0(param_3,*(undefined4 *)(param_3 + 4));
  if (*(int *)(param_1 + 4) == 0x1ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
  *(int *)(param_3 + 4) = iVar1;
  **(int **)(iVar1 + 4) = iVar1;
  *param_2 = *(int *)(param_3 + 4);
  return;
}

