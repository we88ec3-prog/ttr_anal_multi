
void FUN_00405030(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00913800;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  while( true ) {
    if (param_3 == param_4) {
      ExceptionList = local_10;
      return;
    }
    iVar1 = FUN_00404fd0(param_2,*(undefined4 *)(param_2 + 4));
    if (*(int *)(param_1 + 4) == 0x1ffffffe) break;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    *(int *)(param_2 + 4) = iVar1;
    **(int **)(iVar1 + 4) = iVar1;
    param_3 = (undefined4 *)*param_3;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db30("list<T> too long");
}

