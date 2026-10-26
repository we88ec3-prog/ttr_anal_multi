
undefined4 FUN_008d9360(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  uVar1 = 6;
  *param_3 = 0;
  if (param_2 != 0) {
    if ((param_1 != 0) && (param_2 - 1U < *(uint *)(param_1 + 0x198))) {
      *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x1a0) + 4 + (param_2 - 1U) * 0x10);
      uVar1 = 0;
    }
  }
  return uVar1;
}

