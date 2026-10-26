
void FUN_00582670(void)

{
  int *unaff_ESI;
  
  unaff_ESI[0xc] = 0;
  unaff_ESI[0xb] = 0;
  if (*unaff_ESI != 0) {
    FUN_004a47d0(*unaff_ESI);
    *unaff_ESI = 0;
  }
  return;
}

