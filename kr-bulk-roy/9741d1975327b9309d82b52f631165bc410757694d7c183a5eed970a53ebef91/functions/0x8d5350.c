
undefined4 FUN_008d5350(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (param_2[4] == 0) {
    iVar1 = param_2[2];
  }
  else {
    iVar1 = (param_2[2] * param_2[4] + 0x24) / 0x48;
  }
  if (*param_2 == 0) {
    iVar3 = *(int *)(*(int *)(iVar3 + 0x20) + 0xc) + 0x20 >> 6;
  }
  else {
    if (*param_2 != 1) {
      return 7;
    }
    iVar3 = *(int *)(iVar3 + 0xd0) + *(int *)(iVar3 + 0xcc);
  }
  if (iVar1 + 0x20 >> 6 == iVar3) {
    uVar2 = FUN_008d5300(param_1,0);
    return uVar2;
  }
  return 0x17;
}

