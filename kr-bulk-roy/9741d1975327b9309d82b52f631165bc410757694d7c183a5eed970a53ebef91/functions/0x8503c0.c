
void FUN_008503c0(void)

{
  int iVar1;
  int *unaff_ESI;
  
  if (*unaff_ESI != unaff_ESI[1]) {
    iVar1 = FUN_008525a0(unaff_ESI[1]);
    FUN_008510f0(unaff_ESI[1]);
    unaff_ESI[1] = iVar1;
  }
  return;
}

