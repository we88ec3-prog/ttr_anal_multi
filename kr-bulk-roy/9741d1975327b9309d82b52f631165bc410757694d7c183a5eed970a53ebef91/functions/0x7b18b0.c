
int * FUN_007b18b0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00918c20;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  iVar2 = param_2[1];
  iVar1 = *param_2;
  *param_1 = 0;
  uVar3 = iVar2 - iVar1 >> 5;
  param_1[1] = 0;
  param_1[2] = 0;
  if (uVar3 != 0) {
    if (0x7ffffff < uVar3) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    iVar2 = FUN_00527d70();
    local_8 = 0;
    *param_1 = iVar2;
    param_1[1] = iVar2;
    param_1[2] = uVar3 * 0x20 + iVar2;
    iVar2 = FUN_007b2ca0(*param_2,param_2[1],iVar2,param_1);
    param_1[1] = iVar2;
  }
  ExceptionList = local_10;
  return param_1;
}

