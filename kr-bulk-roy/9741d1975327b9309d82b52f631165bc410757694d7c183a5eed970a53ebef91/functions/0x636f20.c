
void FUN_00636f20(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  if (0x800 < param_3 - param_1) {
    param_1 = ((param_3 - param_1) + -0x800) / 2;
    param_3 = param_1 + 0x800;
  }
  FUN_00749b50(param_1,param_2,param_3,param_4);
  return;
}

