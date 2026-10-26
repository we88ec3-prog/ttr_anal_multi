
undefined4 FUN_008b9820(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0) {
    return 0x55;
  }
  uVar1 = FUN_008b97e0(param_1,*(int *)(param_1 + 8) + param_2);
  return uVar1;
}

