
undefined4 FUN_006662f0(int param_1,int param_2)

{
  if ((*(int *)(param_2 + 0x264) <= *(int *)(param_1 + 0x264)) &&
     ((*(int *)(param_2 + 0x264) < *(int *)(param_1 + 0x264) ||
      (*(uint *)(param_2 + 0x260) < *(uint *)(param_1 + 0x260))))) {
    return 1;
  }
  return 0;
}

