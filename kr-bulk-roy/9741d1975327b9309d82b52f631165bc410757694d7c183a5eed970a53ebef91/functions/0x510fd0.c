
int * FUN_00510fd0(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00910460;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  uVar1 = (param_2[1] - *param_2) / 0x24;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  if (uVar1 != 0) {
    if (0x71c71c7 < uVar1) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    iVar2 = FUN_00851260();
    param_1[2] = iVar2 + uVar1 * 0x24;
    local_8 = 0;
    *param_1 = iVar2;
    param_1[1] = iVar2;
    iVar2 = FUN_00511170(*param_2,param_2[1],iVar2,param_1);
    param_1[1] = iVar2;
  }
  ExceptionList = local_10;
  return param_1;
}

