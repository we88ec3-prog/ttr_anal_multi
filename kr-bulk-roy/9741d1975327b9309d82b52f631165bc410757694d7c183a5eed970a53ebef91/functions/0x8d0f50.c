
undefined4 FUN_008d0f50(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(iVar1 + 0x178);
  param_1[4] = iVar2;
  param_1[5] = *(int *)(iVar1 + 0x17c) - iVar2;
  param_1[6] = *(int *)(iVar1 + 0x180);
  return 0;
}

