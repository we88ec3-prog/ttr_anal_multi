
uint FUN_006fbe20(double *param_1)

{
  int iVar1;
  uint uVar2;
  double *unaff_EDI;
  
  iVar1 = *(int *)(param_1 + 1);
  if (iVar1 == *(int *)(unaff_EDI + 1)) {
    if (iVar1 != 3) {
      if (iVar1 == 4) {
        iVar1 = FUN_006fbda0();
        return (uint)(iVar1 < 0);
      }
      uVar2 = FUN_006fbca0(param_1);
      if (uVar2 == 0xffffffff) {
        uVar2 = FUN_006f89f0();
      }
      return uVar2;
    }
    if (*param_1 < *unaff_EDI) {
      return 1;
    }
  }
  else {
    if ((&PTR_DAT_00c0be1c)[iVar1][2] == (&PTR_DAT_00c0be1c)[*(int *)(unaff_EDI + 1)][2]) {
      FUN_006f8b60();
      return 0;
    }
    FUN_006f8b60();
  }
  return 0;
}

