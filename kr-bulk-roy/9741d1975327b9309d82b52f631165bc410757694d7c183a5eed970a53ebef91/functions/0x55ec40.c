
undefined4 FUN_0055ec40(void)

{
  code *pcVar1;
  double *pdVar2;
  int iVar3;
  double local_20;
  double local_18;
  undefined4 local_10;
  int iStack_8;
  
  pcVar1 = DAT_00fe1f38;
  local_10 = DAT_00fe1f30;
  pdVar2 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar2 + 1) == 3) {
LAB_0055ec91:
    local_18 = *pdVar2;
    iStack_8 = (int)ROUND(local_18);
    (*pcVar1)(iStack_8);
    return 0;
  }
  if (*(int *)(pdVar2 + 1) == 4) {
    iVar3 = FUN_006f7760();
    if (iVar3 != 0) {
      local_18 = (double)CONCAT44(local_18._4_4_,3);
      pdVar2 = &local_20;
      goto LAB_0055ec91;
    }
  }
  (*pcVar1)(0);
  return 0;
}

