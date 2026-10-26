
void FUN_004a8b90(undefined4 *param_1)

{
  double *pdVar1;
  int iVar2;
  double local_18;
  double local_10;
  
  FUN_004ad0a0(*param_1,1,"t_doCoTask");
  pdVar1 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar1 + 1) == 3) {
LAB_004a8be5:
    param_1[0xd] = (uint)((int)ROUND(*pdVar1) != 0);
    return;
  }
  if (*(int *)(pdVar1 + 1) == 4) {
    iVar2 = FUN_006f7760();
    local_18 = local_10;
    if (iVar2 != 0) {
      local_10 = (double)CONCAT44(local_10._4_4_,3);
      pdVar1 = &local_18;
      goto LAB_004a8be5;
    }
  }
  param_1[0xd] = 0;
  return;
}

