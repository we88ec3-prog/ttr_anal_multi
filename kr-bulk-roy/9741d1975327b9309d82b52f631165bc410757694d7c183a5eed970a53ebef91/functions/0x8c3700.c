
undefined1 FUN_008c3700(int param_1,uint param_2)

{
  if (param_2 < 0x100) {
    return *(undefined1 *)(*(int *)(param_1 + 0x10) + 6 + param_2);
  }
  return 0;
}

