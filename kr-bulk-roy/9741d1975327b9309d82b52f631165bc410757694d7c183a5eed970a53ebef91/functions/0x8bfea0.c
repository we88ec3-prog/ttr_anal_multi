
undefined4 FUN_008bfea0(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*param_1 + 0x8c);
  FUN_008b8760(*param_1,param_2);
  param_1[6] = *(int *)(iVar1 + 0x28) << 6;
  param_1[7] = *(int *)(iVar1 + 0x2c) * -0x40;
  param_1[9] = (uint)*(ushort *)(iVar1 + 4) << 6;
  return 0;
}

