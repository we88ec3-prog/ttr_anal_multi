
void FUN_00722b30(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2 - param_1;
  iVar2 = param_2;
  iVar3 = param_1;
  while (0x20 < iVar1 >> 3) {
    FUN_007257c0(iVar3 + ((iVar1 >> 3) / 2) * 8,iVar2 + -8);
    FUN_00725860(iVar3,iVar2,&param_1,&param_2);
    iVar1 = param_1;
    if ((int)(iVar2 - param_2 & 0xfffffff8U) < (int)(param_1 - iVar3 & 0xfffffff8U)) {
      FUN_00722b30(param_2,iVar2,param_3);
      iVar2 = iVar1;
    }
    else {
      FUN_00722b30(iVar3,param_1,param_3);
      iVar3 = param_2;
    }
    iVar1 = iVar2 - iVar3;
  }
  if (iVar3 != iVar2) {
    FUN_00725a80(iVar2);
  }
  return;
}

