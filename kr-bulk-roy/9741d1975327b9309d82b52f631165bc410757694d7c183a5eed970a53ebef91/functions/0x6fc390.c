
void FUN_006fc390(undefined4 param_1,double *param_2,int param_3,double *param_4,undefined4 param_5)

{
  int iVar1;
  float10 fVar2;
  undefined8 local_30;
  undefined4 local_28;
  double local_20;
  double local_18;
  undefined8 local_10;
  
  if (*(int *)(param_3 + 8) == 3) {
    local_10 = (double)CONCAT44(param_3,(undefined4)local_10);
LAB_006fc3e9:
    if (*(int *)(param_4 + 1) != 3) {
      if ((*(int *)(param_4 + 1) != 4) || (iVar1 = FUN_006f7760(), local_20 = local_18, iVar1 == 0))
      goto LAB_006fc4d2;
      local_18 = (double)CONCAT44(local_18._4_4_,3);
      param_4 = &local_20;
    }
    local_10 = *local_10._4_4_;
    local_18 = *param_4;
    switch(param_5) {
    case 5:
      *(undefined4 *)(param_2 + 1) = 3;
      *param_2 = local_18 + local_10;
      return;
    case 6:
      *(undefined4 *)(param_2 + 1) = 3;
      *param_2 = local_10 - local_18;
      return;
    case 7:
      *(undefined4 *)(param_2 + 1) = 3;
      *param_2 = local_18 * local_10;
      return;
    case 8:
      *(undefined4 *)(param_2 + 1) = 3;
      *param_2 = local_10 / local_18;
      return;
    case 9:
      fVar2 = (float10)FUN_008ff2e0(local_10 / local_18);
      *(undefined4 *)(param_2 + 1) = 3;
      *param_2 = (double)((float10)local_10 - fVar2 * (float10)local_18);
      return;
    case 10:
      fVar2 = (float10)FUN_008ff5a0();
      *param_2 = (double)fVar2;
      *(undefined4 *)(param_2 + 1) = 3;
      return;
    case 0xb:
      *(undefined4 *)(param_2 + 1) = 3;
      *param_2 = -local_10;
      return;
    }
  }
  else {
    if ((*(int *)(param_3 + 8) == 4) && (iVar1 = FUN_006f7760(), iVar1 != 0)) {
      local_30 = local_10;
      local_28 = 3;
      local_10 = (double)CONCAT44(&local_30,(undefined4)local_10);
      goto LAB_006fc3e9;
    }
LAB_006fc4d2:
    iVar1 = FUN_006fbb80(param_1,param_3,param_4,param_2,param_5);
    if (iVar1 == 0) {
      if ((*(int *)(param_3 + 8) != 3) && (*(int *)(param_3 + 8) == 4)) {
        FUN_006f7760();
      }
      FUN_006f8970();
      return;
    }
  }
  return;
}

