
undefined4 FUN_007ffa70(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  
  iVar1 = param_1[4];
  iVar2 = param_1[3];
  iVar7 = (iVar2 + iVar1) / 2;
  iVar3 = param_1[5];
  iVar4 = param_1[6];
  iVar5 = param_1[6] + param_1[5] + iVar2 + iVar1;
  iVar5 = (int)(iVar5 + (iVar5 >> 0x1f & 3U)) >> 2;
  if (iVar1 - iVar2 < 2) {
    *param_1 = 1;
    return 0;
  }
  uVar6 = FUN_007ffb50(param_1,iVar2,iVar7);
  param_1[7] = uVar6;
  uVar6 = FUN_007ffb50(param_1,iVar7,param_1[4]);
  param_1[8] = uVar6;
  uVar6 = FUN_007ffb50(param_1,(iVar3 + iVar2) / 2,iVar5);
  param_1[9] = uVar6;
  uVar6 = FUN_007ffb50(param_1,iVar5,(iVar4 + iVar1) / 2);
  param_1[10] = uVar6;
  return 1;
}

