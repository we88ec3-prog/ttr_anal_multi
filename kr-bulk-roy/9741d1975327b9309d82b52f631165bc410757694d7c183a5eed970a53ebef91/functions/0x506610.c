
int * FUN_00506610(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00908800;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  iVar2 = param_2[1];
  iVar1 = *param_2;
  *param_1 = 0;
  uVar3 = iVar2 - iVar1 >> 4;
  param_1[1] = 0;
  param_1[2] = 0;
  if (uVar3 != 0) {
    if (0xfffffff < uVar3) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    iVar2 = FUN_008517a0();
    local_8 = 0;
    *param_1 = iVar2;
    param_1[1] = iVar2;
    param_1[2] = uVar3 * 0x10 + iVar2;
    iVar2 = FUN_00506980(*param_2,param_2[1],iVar2,param_1);
    param_1[1] = iVar2;
  }
  ExceptionList = local_10;
  return param_1;
}

