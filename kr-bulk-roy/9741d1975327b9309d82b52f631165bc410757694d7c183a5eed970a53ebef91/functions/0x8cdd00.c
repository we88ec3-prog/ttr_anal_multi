
void FUN_008cdd00(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    param_1[1] = 0;
    param_1[0x34] = 0;
    param_1[0x67] = 0;
    param_1[0xe8] = 0;
    param_1[0x169] = 0;
    param_1[0x1ea] = 0;
    FUN_008b9f80(*param_1,param_1);
  }
  return;
}

