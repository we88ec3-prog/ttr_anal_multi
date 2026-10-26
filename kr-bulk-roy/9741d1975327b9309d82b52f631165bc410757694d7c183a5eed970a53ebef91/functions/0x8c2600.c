
void FUN_008c2600(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  
  if (param_1 != (int *)0x0) {
    if ((param_2 != 0) && (0xd37 < param_3)) {
      param_1[4] = param_2;
      uVar1 = (param_2 - (param_2 + 0x540)) + param_3;
      param_1[1] = uVar1 & 0xfffffff0;
      param_1[2] = uVar1 >> 7;
      *param_1 = param_2 + 0x540;
      return;
    }
    param_1[1] = 0;
    param_1[4] = 0;
    *param_1 = 0;
  }
  return;
}

