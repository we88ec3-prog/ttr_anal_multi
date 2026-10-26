
int FUN_00848f50(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00918270;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar6 = (param_4 - param_3) * 0x51eb851f;
  uVar2 = (param_4 - param_3) / 100;
  if (uVar2 != 0) {
    iVar6 = (param_1[1] - *param_1) / 100;
    if (0x28f5c28U - iVar6 < uVar2) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    if ((uint)((param_1[2] - *param_1) / 100) < iVar6 + uVar2) {
      iVar3 = FUN_008486b0();
      iVar4 = FUN_008486f0();
      local_8 = 0;
      uVar5 = FUN_00848d70(*param_1,param_2,iVar4,param_4);
      uVar5 = FUN_00849370(param_3,param_4,uVar5,param_4);
      FUN_00848d70(param_2,param_1[1],uVar5,param_4);
      iVar6 = *param_1;
      iVar1 = param_1[1];
      if (iVar6 != 0) {
        FUN_00848b60(param_4);
        FUN_0089120c(*param_1);
      }
      iVar3 = iVar3 * 100 + iVar4;
      param_1[2] = iVar3;
      param_1[1] = (uVar2 + (iVar1 - iVar6) / 100) * 100 + iVar4;
      *param_1 = iVar4;
      ExceptionList = local_10;
      return iVar3;
    }
    FUN_00849370(param_3,param_4,param_1[1],param_4);
    iVar6 = FUN_008492c0(param_1[1]);
    param_1[1] = param_1[1] + uVar2 * 100;
  }
  ExceptionList = local_10;
  return iVar6;
}

