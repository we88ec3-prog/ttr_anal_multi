
undefined4 FUN_0056b590(int *param_1)

{
  int *piVar1;
  double dVar2;
  double *pdVar3;
  int iVar4;
  float10 fVar5;
  double local_1c;
  double local_14;
  code *local_c;
  undefined4 local_8;
  
  local_c = DAT_00fe27b8;
  local_8 = DAT_00fe2778;
  pdVar3 = (double *)FUN_006f50f0();
  if (*(int *)(pdVar3 + 1) == 3) {
LAB_0056b5e7:
    local_14 = *pdVar3;
    iVar4 = (int)ROUND(local_14);
  }
  else {
    if (*(int *)(pdVar3 + 1) == 4) {
      iVar4 = FUN_006f7760();
      dVar2 = local_14;
      if (iVar4 != 0) {
        local_14 = (double)CONCAT44(local_14._4_4_,3);
        local_1c = dVar2;
        pdVar3 = &local_1c;
        goto LAB_0056b5e7;
      }
    }
    iVar4 = 0;
  }
  fVar5 = (float10)(*local_c)(iVar4);
  iVar4 = *param_1;
  pdVar3 = *(double **)(iVar4 + 8);
  *pdVar3 = (double)(float)fVar5;
  *(undefined4 *)(pdVar3 + 1) = 3;
  piVar1 = (int *)(iVar4 + 8);
  *piVar1 = *piVar1 + 0x10;
  return 1;
}

