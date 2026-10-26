
int * FUN_0051de10(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00906410;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  iVar2 = param_2[1];
  iVar1 = *param_2;
  *param_1 = 0;
  uVar3 = iVar2 - iVar1 >> 3;
  param_1[1] = 0;
  param_1[2] = 0;
  if (uVar3 != 0) {
    if (0x1fffffff < uVar3) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    iVar2 = FUN_0071a0c0();
    local_8 = 0;
    *param_1 = iVar2;
    param_1[1] = iVar2;
    param_1[2] = iVar2 + uVar3 * 8;
    iVar2 = FUN_0051ded0(*param_2,param_2[1],param_1);
    param_1[1] = iVar2;
  }
  ExceptionList = local_10;
  return param_1;
}

