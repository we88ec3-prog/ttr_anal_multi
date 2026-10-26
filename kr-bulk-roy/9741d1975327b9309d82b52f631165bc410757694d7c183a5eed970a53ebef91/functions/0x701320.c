
void FUN_00701320(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  double *pdVar3;
  undefined4 *puVar4;
  
  puVar4 = *(undefined4 **)(param_1 + 8);
  *puVar4 = &DAT_00c081df;
  puVar4[2] = 2;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  puVar4 = (undefined4 *)FUN_006f9c50();
  iVar1 = *(int *)(param_1 + 8);
  *(undefined4 *)(iVar1 + -0x10) = *puVar4;
  *(undefined4 *)(iVar1 + -0xc) = puVar4[1];
  *(undefined4 *)(iVar1 + -8) = puVar4[2];
  piVar2 = *(int **)(param_1 + 8);
  *piVar2 = param_1;
  piVar2[2] = 2;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  puVar4 = (undefined4 *)FUN_006f9c50();
  iVar1 = *(int *)(param_1 + 8);
  *(undefined4 *)(iVar1 + -0x10) = *puVar4;
  *(undefined4 *)(iVar1 + -0xc) = puVar4[1];
  *(undefined4 *)(iVar1 + -8) = puVar4[2];
  if ((*(undefined **)(param_1 + 8) != &DAT_00c0bfd8) &&
     (*(int *)(*(undefined **)(param_1 + 8) + -8) == 6)) {
    FUN_006f5510((&PTR_DAT_00c0be08)[*param_2]);
    iVar1 = param_2[5];
    pdVar3 = *(double **)(param_1 + 8);
    if (iVar1 < 0) {
      *(undefined4 *)(pdVar3 + 1) = 0;
    }
    else {
      *(undefined4 *)(pdVar3 + 1) = 3;
      *pdVar3 = (double)iVar1;
    }
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
    FUN_006fe550(param_1,*(int *)(param_1 + 8) + -0x30,0);
  }
  return;
}

