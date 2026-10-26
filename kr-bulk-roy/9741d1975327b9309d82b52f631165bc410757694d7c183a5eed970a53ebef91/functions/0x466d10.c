
void FUN_00466d10(void)

{
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  *unaff_ESI = *unaff_EDI;
  unaff_ESI[1] = unaff_EDI[1];
  unaff_ESI[2] = unaff_EDI[2];
  unaff_ESI[8] = 7;
  unaff_ESI[7] = 0;
  *(undefined2 *)(unaff_ESI + 3) = 0;
  FUN_004026e0(unaff_EDI + 3,0,0xffffffff);
  unaff_ESI[10] = unaff_EDI[10];
  unaff_ESI[0xb] = unaff_EDI[0xb];
  unaff_ESI[0xc] = unaff_EDI[0xc];
  unaff_ESI[0xd] = unaff_EDI[0xd];
  unaff_ESI[0xe] = unaff_EDI[0xe];
  return;
}

