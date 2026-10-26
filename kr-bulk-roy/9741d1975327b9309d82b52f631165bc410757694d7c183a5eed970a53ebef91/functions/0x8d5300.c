
undefined4 FUN_008d5300(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  FUN_008b8760(iVar1,param_2);
  param_1[6] = *(int *)(iVar1 + 0xcc) << 6;
  param_1[7] = *(int *)(iVar1 + 0xd0) * -0x40;
  param_1[9] = (int)*(short *)(iVar1 + 0xec) << 6;
  return 0;
}

