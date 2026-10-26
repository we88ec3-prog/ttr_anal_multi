
void FUN_00866e90(int *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  piVar3 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090ba40;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar8 = param_4 - param_3 >> 4;
  if (uVar8 != 0) {
    iVar4 = param_1[1] - *param_1 >> 4;
    if (0xfffffffU - iVar4 < uVar8) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    uVar1 = iVar4 + uVar8;
    uVar5 = param_1[2] - *param_1 >> 4;
    if (uVar5 < uVar1) {
      if (0xfffffff - (uVar5 >> 1) < uVar5) {
        param_1 = (int *)0x0;
      }
      else {
        param_1 = (int *)(uVar5 + (uVar5 >> 1));
      }
      if (param_1 < uVar1) {
        param_1 = (int *)uVar1;
      }
      iVar6 = FUN_008517a0();
      local_8 = 0;
      uVar7 = FUN_0085fc50(param_2,iVar6,param_4);
      uVar7 = FUN_00841d70(param_3,param_4,uVar7,param_4);
      FUN_0085fc50(piVar3[1],uVar7,param_4);
      local_8 = 0xffffffff;
      iVar4 = piVar3[1];
      iVar2 = *piVar3;
      if (iVar2 != 0) {
        FUN_0083f510();
        FUN_0089120c(*piVar3);
      }
      piVar3[2] = (int)param_1 * 0x10 + iVar6;
      piVar3[1] = (uVar8 + (iVar4 - iVar2 >> 4)) * 0x10 + iVar6;
      *piVar3 = iVar6;
      ExceptionList = local_10;
      return;
    }
    FUN_00841d70(param_3,param_4,param_1[1],param_4);
    iVar2 = param_1[1];
    iVar4 = uVar8 * 0x10 + iVar2;
    if ((param_2 != iVar2) && (iVar2 != iVar4)) {
      FUN_00867050(param_2,iVar2,iVar4);
    }
    param_1[1] = param_1[1] + uVar8 * 0x10;
  }
  ExceptionList = local_10;
  return;
}

