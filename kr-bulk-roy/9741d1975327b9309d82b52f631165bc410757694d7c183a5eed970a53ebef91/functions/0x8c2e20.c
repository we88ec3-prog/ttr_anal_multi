
undefined4 FUN_008c2e20(int param_1,int param_2,int param_3,undefined4 param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (param_2 == 0) {
    iVar1 = *(int *)(*(int *)(param_1 + 0x68) + 4);
  }
  else {
    iVar1 = FUN_008c2ad0();
    if (iVar1 == 0) {
      return 0x8e;
    }
    param_3 = param_3 + *(int *)(iVar1 + 8);
    iVar1 = *(int *)(iVar1 + 0xc);
  }
  iVar2 = iVar1;
  if ((param_5 != (int *)0x0) && (iVar2 = *param_5, iVar2 == 0)) {
    *param_5 = iVar1;
    return 0;
  }
  uVar3 = FUN_008b9860(*(undefined4 *)(param_1 + 0x68),param_3,param_4,iVar2);
  return uVar3;
}

