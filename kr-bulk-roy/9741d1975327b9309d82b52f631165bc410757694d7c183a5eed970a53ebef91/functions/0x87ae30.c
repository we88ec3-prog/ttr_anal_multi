
undefined4
FUN_0087ae30(undefined4 param_1,int param_2,undefined4 *param_3,undefined4 param_4,int param_5)

{
  if (*(int *)(param_5 + 0x40) == 1) {
    if (*(int *)(param_2 + 0xec) != 0) {
      (**(code **)(**(int **)(param_2 + 0xec) + 0xac))
                (*(int **)(param_2 + 0xec),0,0,2,0,param_3[4],1);
      return 1;
    }
  }
  else if (*(int *)(param_5 + 0x40) == 2) {
    if (*(int *)(param_2 + 0xec) != 0) {
      (**(code **)(**(int **)(param_2 + 0xec) + 0xac))
                (*(int **)(param_2 + 0xec),0,0,4,0,0,param_3[5]);
      return 1;
    }
  }
  else {
    FUN_0083d7f0(*param_3,param_3[1],param_3[2],param_3[3]);
  }
  return 1;
}

