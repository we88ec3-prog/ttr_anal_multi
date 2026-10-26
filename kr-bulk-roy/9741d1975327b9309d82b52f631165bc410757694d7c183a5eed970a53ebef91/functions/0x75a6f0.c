
void FUN_0075a6f0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = FUN_00404fd0(iVar1,*(undefined4 *)(iVar1 + 4));
  if (param_1[1] == 0x1ffffffe) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  param_1[1] = param_1[1] + 1;
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}

