
int FUN_00840100(int *param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    return 0;
  }
  uVar1 = param_2 & 0xffff;
  if ((uVar1 < (uint)((param_1[1] - *param_1) / 0x11c)) &&
     (*(uint *)(param_1[4] + uVar1 * 4) == param_2 >> 0x10)) {
    return uVar1 * 0x11c + *param_1;
  }
  return 0;
}

