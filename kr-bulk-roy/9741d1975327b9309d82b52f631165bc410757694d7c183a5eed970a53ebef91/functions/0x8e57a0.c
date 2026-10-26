
undefined4 FUN_008e57a0(int param_1,int *param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 0x25;
  }
  if (param_2 == (int *)0x0) {
    param_4 = param_4 | 3;
  }
  if ((param_4 & 1) == 0) {
    if ((param_2 != (int *)0x0) && (*param_2 != *(int *)(param_1 + 4))) {
      return 0x23;
    }
  }
  else {
    param_2 = (int *)0x0;
  }
  uVar1 = FUN_008e4de0(param_2,param_4);
  return uVar1;
}

