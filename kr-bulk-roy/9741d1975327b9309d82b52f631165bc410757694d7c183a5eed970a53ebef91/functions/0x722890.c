
void FUN_00722890(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2 - param_1;
  iVar2 = param_1;
  iVar3 = param_2;
  while (0x20 < iVar1 >> 3) {
    FUN_00725490(iVar2 + ((iVar1 >> 3) / 2) * 8,iVar3 + -8);
    FUN_00725530(iVar2,iVar3,&param_1,&param_2);
    iVar1 = param_1;
    if ((int)(iVar3 - param_2 & 0xfffffff8U) < (int)(param_1 - iVar2 & 0xfffffff8U)) {
      FUN_00722890(param_2,iVar3,param_3);
      iVar3 = iVar1;
    }
    else {
      FUN_00722890(iVar2,param_1,param_3);
      iVar2 = param_2;
    }
    iVar1 = iVar3 - iVar2;
  }
  if (iVar2 != iVar3) {
    FUN_00725700(iVar2,iVar3);
  }
  return;
}

