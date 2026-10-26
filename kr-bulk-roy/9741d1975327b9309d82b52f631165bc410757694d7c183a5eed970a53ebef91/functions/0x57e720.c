
void FUN_0057e720(void)

{
  int *piVar1;
  int *unaff_ESI;
  
  piVar1 = *(int **)*unaff_ESI;
  if (piVar1 != (int *)*unaff_ESI) {
    *(int *)piVar1[1] = *piVar1;
    *(int *)(*piVar1 + 4) = piVar1[1];
    FUN_0089120c(piVar1);
    unaff_ESI[1] = unaff_ESI[1] + -1;
  }
  return;
}

