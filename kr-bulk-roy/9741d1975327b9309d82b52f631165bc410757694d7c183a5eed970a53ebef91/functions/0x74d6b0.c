
int * FUN_0074d6b0(int *param_1,int param_2)

{
  int iVar1;
  undefined4 in_ECX;
  int unaff_EDI;
  
  iVar1 = FUN_0074d700(param_2,*(undefined4 *)(param_2 + 4),in_ECX);
  if (*(int *)(unaff_EDI + 4) == 0x3ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  *(int *)(unaff_EDI + 4) = *(int *)(unaff_EDI + 4) + 1;
  *(int *)(param_2 + 4) = iVar1;
  **(int **)(iVar1 + 4) = iVar1;
  *param_1 = *(int *)(param_2 + 4);
  return param_1;
}

