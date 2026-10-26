
undefined4 FUN_004acf90(int *param_1,code *param_2)

{
  int *piVar1;
  double dVar2;
  double *pdVar3;
  int iVar4;
  int iVar5;
  double local_18;
  double local_10;
  undefined4 local_8;
  
  local_8 = DAT_00fe1804;
  pdVar3 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar3 + 1) == 3) {
LAB_004acfde:
    local_10 = *pdVar3;
    iVar4 = (int)ROUND(local_10);
  }
  else {
    if (*(int *)(pdVar3 + 1) == 4) {
      iVar4 = FUN_006f7760();
      dVar2 = local_10;
      if (iVar4 != 0) {
        local_10 = (double)CONCAT44(local_10._4_4_,3);
        local_18 = dVar2;
        pdVar3 = &local_18;
        goto LAB_004acfde;
      }
    }
    iVar4 = 0;
  }
  iVar5 = (*param_2)(iVar4);
  iVar4 = *param_1;
  pdVar3 = *(double **)(iVar4 + 8);
  *(undefined4 *)(pdVar3 + 1) = 3;
  *pdVar3 = (double)iVar5;
  piVar1 = (int *)(iVar4 + 8);
  *piVar1 = *piVar1 + 0x10;
  return 1;
}

