
void FUN_0083ee30(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)*param_1;
  iVar2 = FUN_0083f5b0(iVar1,*(undefined4 *)(iVar1 + 4));
  if (param_1[1] == 0xccccccb) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("list<T> too long");
  }
  param_1[1] = param_1[1] + 1;
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}

