
float10 FUN_006f5320(void)

{
  double *pdVar1;
  int iVar2;
  double local_14;
  undefined4 local_c;
  
  pdVar1 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar1 + 1) == 3) {
LAB_006f535b:
    return (float10)*pdVar1;
  }
  if (*(int *)(pdVar1 + 1) == 4) {
    iVar2 = FUN_006f7760();
    if (iVar2 != 0) {
      local_c = 3;
      pdVar1 = &local_14;
      goto LAB_006f535b;
    }
  }
  return (float10)0;
}

