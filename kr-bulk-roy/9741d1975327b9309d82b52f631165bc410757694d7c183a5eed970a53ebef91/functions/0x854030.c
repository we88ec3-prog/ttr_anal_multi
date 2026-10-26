
int FUN_00854030(int *param_1,undefined4 param_2,int param_3,int param_4)

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
  puStack_c = &LAB_00906b30;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar5 = (param_4 - param_3) * 0x2aaaaaab;
  uVar2 = (param_4 - param_3) / 0xc;
  if (uVar2 != 0) {
    iVar5 = (param_1[1] - *param_1) / 0xc;
    if (0x15555555U - iVar5 < uVar2) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    if ((uint)((param_1[2] - *param_1) / 0xc) < iVar5 + uVar2) {
      iVar3 = FUN_00850c80();
      iVar4 = FUN_0085e740();
      local_8 = 0;
      FUN_006ee5a0(*param_1,param_4);
      FUN_00825d90(param_3,param_4,param_4);
      FUN_006ee5a0(param_2,param_4);
      iVar5 = *param_1;
      iVar1 = param_1[1];
      if (iVar5 != 0) {
        FUN_0089120c(iVar5);
      }
      param_1[2] = iVar4 + iVar3 * 0xc;
      param_1[1] = iVar4 + (uVar2 + (iVar1 - iVar5) / 0xc) * 0xc;
      *param_1 = iVar4;
      ExceptionList = local_10;
      return iVar4;
    }
    FUN_00825d90(param_3,param_4,param_4);
    iVar5 = FUN_00854640(param_2);
    param_1[1] = param_1[1] + uVar2 * 0xc;
  }
  ExceptionList = local_10;
  return iVar5;
}

