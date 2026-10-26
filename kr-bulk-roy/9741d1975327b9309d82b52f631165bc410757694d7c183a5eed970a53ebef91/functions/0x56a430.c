
undefined4 FUN_0056a430(code *param_1)

{
  double *pdVar1;
  int iVar2;
  double local_1c;
  double local_14;
  int iStack_8;
  
  pdVar1 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar1 + 1) == 3) {
LAB_0056a479:
    local_14 = *pdVar1;
    iStack_8 = (int)ROUND(local_14);
    (*param_1)(iStack_8);
    return 0;
  }
  if (*(int *)(pdVar1 + 1) == 4) {
    iVar2 = FUN_006f7760();
    if (iVar2 != 0) {
      local_14 = (double)CONCAT44(local_14._4_4_,3);
      pdVar1 = &local_1c;
      goto LAB_0056a479;
    }
  }
  (*param_1)(0);
  return 0;
}

