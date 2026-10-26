
int * FUN_0065b120(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00905c70;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  uVar1 = (param_2[1] - *param_2) / 0x18;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  if (uVar1 != 0) {
    if (0xaaaaaaa < uVar1) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    iVar2 = FUN_007e0030();
    param_1[2] = iVar2 + uVar1 * 0x18;
    local_8 = 0;
    *param_1 = iVar2;
    param_1[1] = iVar2;
    iVar2 = FUN_0065cb60(*param_2,param_2[1],param_1);
    param_1[1] = iVar2;
  }
  ExceptionList = local_10;
  return param_1;
}

