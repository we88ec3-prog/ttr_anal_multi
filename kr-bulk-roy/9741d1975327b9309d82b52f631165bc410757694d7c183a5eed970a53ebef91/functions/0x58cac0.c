
void FUN_0058cac0(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  
  if (*(int *)(param_1 + 4) != 0) {
    FUN_00443da0();
    if ((param_2 <= local_18) && (param_2 = local_18, param_4 < local_10)) {
      param_2 = param_4 - (local_10 - local_18);
    }
    if ((param_3 <= local_14) && (param_3 = local_14, param_5 < local_c)) {
      param_3 = param_5 - (local_c - local_14);
    }
    FUN_00749ae0(*(undefined4 *)(param_1 + 4),param_2,param_3,(local_10 - local_18) + param_2,
                 (local_c - local_14) + param_3);
    iVar1 = (*(int **)(param_1 + 4))[7];
    if (iVar1 != 0) {
      (**(code **)(**(int **)(param_1 + 4) + 0xb4))(*(undefined4 *)(iVar1 + 8));
    }
  }
  return;
}

