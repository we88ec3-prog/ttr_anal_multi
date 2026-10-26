
void FUN_00796120(void)

{
  float *unaff_ESI;
  float *unaff_EDI;
  float10 fVar1;
  float local_8;
  
  if (*unaff_EDI < 0.0) {
    *unaff_EDI = -*unaff_EDI;
    *unaff_ESI = -*unaff_ESI;
    unaff_ESI[1] = -unaff_ESI[1];
    unaff_ESI[2] = -unaff_ESI[2];
  }
  for (local_8 = *unaff_EDI; 6.2831855 < local_8; local_8 = local_8 - 6.2831855) {
  }
  fVar1 = (float10)FUN_004ff540(local_8);
  if ((float10)3.1415927 < fVar1) {
    local_8 = local_8 - 6.2831855;
  }
  *unaff_EDI = local_8;
  if (local_8 < 0.0) {
    *unaff_EDI = -local_8;
    *unaff_ESI = -*unaff_ESI;
    unaff_ESI[1] = -unaff_ESI[1];
    unaff_ESI[2] = -unaff_ESI[2];
    return;
  }
  return;
}

