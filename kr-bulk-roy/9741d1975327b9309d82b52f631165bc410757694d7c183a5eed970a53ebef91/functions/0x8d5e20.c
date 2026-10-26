
undefined4 FUN_008d5e20(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(*param_1 + 0x84);
  uVar2 = (uint)*(byte *)(iVar1 + 0x68);
  param_1[4] = uVar2;
  param_1[5] = (*(byte *)(iVar1 + 0x69) - uVar2) + 1;
  return 0;
}

