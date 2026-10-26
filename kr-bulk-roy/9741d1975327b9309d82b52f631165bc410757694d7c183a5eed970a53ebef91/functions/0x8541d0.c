
int FUN_008541d0(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00906b10;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar5 = (param_4 - param_3) * 0x66666667;
  uVar2 = (param_4 - param_3) / 0x14;
  if (uVar2 != 0) {
    iVar5 = (param_1[1] - *param_1) / 0x14;
    if (0xcccccccU - iVar5 < uVar2) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    if ((uint)((param_1[2] - *param_1) / 0x14) < iVar5 + uVar2) {
      iVar3 = FUN_00850e30();
      iVar4 = FUN_007e0110();
      local_8 = 0;
      FUN_004fa2b0(*param_1,param_4);
      FUN_0065cb20(param_3,param_4,param_4);
      FUN_004fa2b0(param_2,param_4);
      iVar5 = *param_1;
      iVar1 = param_1[1];
      if (iVar5 != 0) {
        FUN_0089120c(iVar5);
      }
      param_1[2] = iVar4 + iVar3 * 0x14;
      param_1[1] = iVar4 + (uVar2 + (iVar1 - iVar5) / 0x14) * 0x14;
      *param_1 = iVar4;
      ExceptionList = local_10;
      return iVar4;
    }
    FUN_0065cb20(param_3,param_4,param_4);
    iVar5 = FUN_00854680(param_2);
    param_1[1] = param_1[1] + uVar2 * 0x14;
  }
  ExceptionList = local_10;
  return iVar5;
}

