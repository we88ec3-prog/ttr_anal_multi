
undefined4 FUN_0080edc0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  undefined4 uVar1;
  
  if (param_4 == (int *)0x0) {
    return 0;
  }
  uVar1 = (**(code **)(*param_4 + 0x10))(param_1,param_2,param_3);
  return uVar1;
}

