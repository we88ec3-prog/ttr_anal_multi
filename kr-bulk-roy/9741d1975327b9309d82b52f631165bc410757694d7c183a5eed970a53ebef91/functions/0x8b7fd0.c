
undefined4 FUN_008b7fd0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  if (param_1 == (undefined4 *)0x0) {
    return 6;
  }
  iVar1 = FUN_008b7f10(*param_1,param_1[3]);
  iVar2 = FUN_008b7f10(param_1[1],param_1[2]);
  iVar1 = iVar1 - iVar2;
  if (iVar1 == 0) {
    return 6;
  }
  iVar2 = FUN_008b7f40(param_1[1],iVar1);
  param_1[1] = -iVar2;
  iVar2 = FUN_008b7f40(param_1[2],iVar1);
  uVar4 = *param_1;
  param_1[2] = -iVar2;
  uVar3 = FUN_008b7f40(param_1[3],iVar1);
  *param_1 = uVar3;
  uVar4 = FUN_008b7f40(uVar4,iVar1);
  param_1[3] = uVar4;
  return 0;
}

