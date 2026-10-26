
int FUN_00464f00(int param_1,int param_2)

{
  FUN_00466f60();
  FUN_004738a0(param_2 + 0x160);
  if (param_1 + 0x170 != param_2 + 0x170) {
    FUN_00466430(**(undefined4 **)(param_1 + 0x174),*(undefined4 **)(param_1 + 0x174));
    FUN_004664f0(param_2 + 0x170);
  }
  *(undefined4 *)(param_1 + 0x180) = *(undefined4 *)(param_2 + 0x180);
  return param_1;
}

