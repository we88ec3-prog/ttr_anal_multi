
undefined4 FUN_008d6260(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (param_2[4] == 0) {
    iVar1 = param_2[2];
  }
  else {
    iVar1 = (param_2[2] * param_2[4] + 0x24) / 0x48;
  }
  if (*param_2 == 0) {
    uVar3 = *(int *)(*(int *)(*param_1 + 0x20) + 0xc) + 0x20 >> 6;
  }
  else {
    if (*param_2 != 1) {
      return 7;
    }
    uVar3 = (uint)*(ushort *)(*(int *)(*param_1 + 0x84) + 0x60);
  }
  if (iVar1 + 0x20 >> 6 == uVar3) {
    uVar2 = FUN_008d6210(param_1,0);
    return uVar2;
  }
  return 0x17;
}

