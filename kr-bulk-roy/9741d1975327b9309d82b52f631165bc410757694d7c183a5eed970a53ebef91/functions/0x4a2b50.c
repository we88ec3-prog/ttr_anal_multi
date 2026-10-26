
int FUN_004a2b50(void)

{
  double *pdVar1;
  int iVar2;
  double local_18;
  double local_10;
  
  pdVar1 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar1 + 1) == 3) {
LAB_004a2b90:
    return (int)ROUND(*pdVar1);
  }
  if (*(int *)(pdVar1 + 1) == 4) {
    iVar2 = FUN_006f7760();
    local_18 = local_10;
    if (iVar2 != 0) {
      local_10 = (double)CONCAT44(local_10._4_4_,3);
      pdVar1 = &local_18;
      goto LAB_004a2b90;
    }
  }
  return 0;
}

