
void FUN_00715120(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907f50;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  while( true ) {
    if (param_2 == param_3) {
      ExceptionList = local_10;
      return;
    }
    iVar1 = FUN_00714ef0(param_1,*(undefined4 *)(param_1 + 4),param_2 + 2);
    if (*(undefined **)(in_ECX + 4) == &DAT_00f0f0ef) break;
    *(undefined **)(in_ECX + 4) = *(undefined **)(in_ECX + 4) + 1;
    *(int *)(param_1 + 4) = iVar1;
    **(int **)(iVar1 + 4) = iVar1;
    param_2 = (undefined4 *)*param_2;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("list<T> too long");
}

