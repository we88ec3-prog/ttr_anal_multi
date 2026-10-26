
void FUN_007974d0(void)

{
  float *pfVar1;
  undefined4 *puVar2;
  float *unaff_ESI;
  int unaff_EDI;
  
  FUN_00796ee0();
  puVar2 = *(undefined4 **)(unaff_EDI + 4);
  if (puVar2 != *(undefined4 **)(unaff_EDI + 8)) {
    do {
      pfVar1 = (float *)*puVar2;
      puVar2 = puVar2 + 1;
      *pfVar1 = *pfVar1 + *unaff_ESI;
      pfVar1[1] = pfVar1[1] + unaff_ESI[1];
      pfVar1[2] = unaff_ESI[2] + pfVar1[2];
    } while (puVar2 != *(undefined4 **)(unaff_EDI + 8));
  }
  return;
}

