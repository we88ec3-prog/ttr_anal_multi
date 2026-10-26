
undefined4 FUN_008dcc10(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x214);
  *param_4 = 0;
  param_4[1] = 0;
  if (iVar1 != 0) {
    uVar2 = (**(code **)(iVar1 + 0x54))(param_1,param_2,param_3);
    *param_4 = uVar2;
  }
  return 0;
}

