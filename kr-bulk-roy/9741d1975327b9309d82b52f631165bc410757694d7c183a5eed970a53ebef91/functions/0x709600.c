
void FUN_00709600(int param_1)

{
  char cVar1;
  double *pdVar2;
  char *in_EDX;
  int unaff_ESI;
  
  pdVar2 = *(double **)(unaff_ESI + 8);
  *pdVar2 = (double)param_1;
  *(undefined4 *)(pdVar2 + 1) = 3;
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  do {
    cVar1 = *in_EDX;
    in_EDX = in_EDX + 1;
  } while (cVar1 != '\0');
  FUN_006fec70();
  FUN_006fb9a0();
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -0x10;
  return;
}

