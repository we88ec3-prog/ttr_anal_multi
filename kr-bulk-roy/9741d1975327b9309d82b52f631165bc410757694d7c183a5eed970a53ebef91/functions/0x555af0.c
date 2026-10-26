
int * FUN_00555af0(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916cb0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  uVar1 = (param_2[1] - *param_2) / 0x1c;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  if (uVar1 != 0) {
    if (0x9249249 < uVar1) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    if (uVar1 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00820120();
    }
    param_1[2] = iVar2 + uVar1 * 0x1c;
    local_8 = 0;
    *param_1 = iVar2;
    param_1[1] = iVar2;
    iVar2 = FUN_005566c0(*param_2,param_2[1],iVar2,param_1);
    param_1[1] = iVar2;
  }
  ExceptionList = local_10;
  return param_1;
}

