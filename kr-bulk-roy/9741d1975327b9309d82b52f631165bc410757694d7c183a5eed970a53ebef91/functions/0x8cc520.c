
void FUN_008cc520(int *param_1,int param_2,int param_3)

{
  if (param_1 != (int *)0x0) {
    if ((param_2 != 0) && (0xc03 < param_3)) {
      param_1[1] = (param_2 - (param_2 + 0x408)) + param_3;
      param_1[3] = param_2;
      *param_1 = param_2 + 0x408;
      return;
    }
    param_1[1] = 0;
    param_1[3] = 0;
    *param_1 = 0;
  }
  return;
}

