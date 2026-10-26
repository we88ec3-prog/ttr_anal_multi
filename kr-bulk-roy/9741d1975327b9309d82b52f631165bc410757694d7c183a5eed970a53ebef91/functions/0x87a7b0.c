
undefined4 FUN_0087a7b0(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  if (*(int *)(param_4 + 0x18) != -1) {
    *(int *)(param_4 + 0x10) = *(int *)(param_4 + 0x10) + -1;
    if (*(int *)(param_4 + 0x10) < 1) {
      *(undefined4 *)(param_4 + 0x18) = 0xffffffff;
      *(undefined4 *)(param_4 + 0x10) = 0;
    }
    else {
      *(int *)(param_4 + 4) = *(int *)(param_4 + 0x18);
    }
    if (*(int *)(param_1 + 4) != 0) {
      (**(code **)(**(int **)(param_1 + 4) + 0x68))
                (*(int **)(param_1 + 4),*(undefined4 *)(param_4 + 0x20),
                 *(undefined4 *)(param_4 + 0x10));
    }
  }
  return 1;
}

