
undefined4
FUN_0073da10(undefined4 param_1,undefined4 param_2,short *param_3,int param_4,int param_5,
            int *param_6)

{
  short *psVar1;
  short sVar2;
  undefined4 in_EAX;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 in_ECX;
  int iVar5;
  
  uVar3 = FUN_0073d790(param_1,param_2,param_3,param_4,in_ECX,in_EAX,param_5,param_6);
  if (param_5 != 0) {
    if (param_4 < 0) {
      psVar1 = param_3 + 1;
      do {
        sVar2 = *param_3;
        param_3 = param_3 + 1;
      } while (sVar2 != 0);
      param_4 = (int)param_3 - (int)psVar1 >> 1;
    }
    iVar5 = 0;
    if (0 < param_4) {
      do {
        FUN_00892d30((double)((float)*(int *)(param_5 + iVar5 * 4) * 0.015625));
        uVar4 = FUN_008fed10();
        *(undefined4 *)(param_5 + iVar5 * 4) = uVar4;
        iVar5 = iVar5 + 1;
      } while (iVar5 < param_4);
    }
  }
  if (param_6 != (int *)0x0) {
    FUN_00892d30((double)((float)*param_6 * 0.015625));
    iVar5 = FUN_008fed10();
    *param_6 = iVar5;
    FUN_00892d30((double)((float)param_6[1] * 0.015625));
    iVar5 = FUN_008fed10();
    param_6[1] = iVar5;
  }
  return uVar3;
}

