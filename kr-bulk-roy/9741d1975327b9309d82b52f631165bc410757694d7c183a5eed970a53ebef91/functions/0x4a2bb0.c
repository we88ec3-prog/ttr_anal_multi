
int FUN_004a2bb0(void)

{
  double *pdVar1;
  int iVar2;
  double local_1c;
  undefined4 local_14;
  undefined4 uStack_10;
  
  pdVar1 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar1 + 1) == 3) {
LAB_004a2bf0:
    return (int)ROUND(*pdVar1);
  }
  if (*(int *)(pdVar1 + 1) == 4) {
    iVar2 = FUN_006f7760();
    if (iVar2 != 0) {
      _local_14 = CONCAT44(uStack_10,3);
      pdVar1 = &local_1c;
      goto LAB_004a2bf0;
    }
  }
  return 0;
}

