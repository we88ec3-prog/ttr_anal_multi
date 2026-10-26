
undefined4
FUN_00831510(int param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5)

{
  FUN_0082ef00(&param_4);
  if (param_1 == *(int *)(param_1 + 0x34)) {
    FUN_00826280(&param_3);
    if (param_1 == *(int *)(param_1 + 0x24)) {
      param_3._3_1_ = param_2;
      FUN_00831e70();
      if (param_1 == *(int *)(param_1 + 0x14)) {
        return 0;
      }
    }
  }
  *param_5 = *(undefined4 *)(param_1 + 0x10);
  return 1;
}

