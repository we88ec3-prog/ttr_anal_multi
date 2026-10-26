
int FUN_00853e60(int *param_1,undefined4 param_2,int param_3,int param_4)

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
  puStack_c = &LAB_00913fd0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar6 = (param_4 - param_3) * 0x2aaaaaab;
  uVar2 = (param_4 - param_3) / 0x18;
  if (uVar2 != 0) {
    iVar6 = (param_1[1] - *param_1) / 0x18;
    if (0xaaaaaaaU - iVar6 < uVar2) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    if ((uint)((param_1[2] - *param_1) / 0x18) < iVar6 + uVar2) {
      iVar3 = FUN_00851130();
      iVar4 = FUN_007e0030();
      local_8 = 0;
      uVar5 = FUN_00853d60(param_2,iVar4,param_4);
      uVar5 = FUN_008547b0(param_3,param_4,uVar5,param_4);
      FUN_00853d60(param_1[1],uVar5,param_4);
      iVar6 = *param_1;
      iVar1 = param_1[1];
      if (iVar6 != 0) {
        FUN_008510f0(param_1[1]);
        FUN_0089120c(*param_1);
      }
      param_1[2] = iVar4 + iVar3 * 0x18;
      param_1[1] = iVar4 + (uVar2 + (iVar1 - iVar6) / 0x18) * 0x18;
      *param_1 = iVar4;
      ExceptionList = local_10;
      return iVar4;
    }
    FUN_008547b0(param_3,param_4,param_1[1],param_4);
    iVar6 = FUN_00854600(param_2);
    param_1[1] = param_1[1] + uVar2 * 0x18;
  }
  ExceptionList = local_10;
  return iVar6;
}

