
int FUN_008f1960(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  param_1[0x1c] = param_2;
  if ((*(byte *)(iVar1 + 8) & 1) != 0) {
    FUN_008b8760(iVar1,param_2);
    FUN_008ebc60(param_1);
    return 0;
  }
  iVar1 = (**(code **)(*(int *)(iVar1 + 0x214) + 0x6c))(iVar1,param_2,param_1 + 3);
  if (iVar1 != 0) {
    param_1[0x1c] = -1;
  }
  return iVar1;
}

