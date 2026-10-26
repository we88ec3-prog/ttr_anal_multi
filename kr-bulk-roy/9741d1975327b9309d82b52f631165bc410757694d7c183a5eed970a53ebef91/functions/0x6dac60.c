
void FUN_006dac60(void)

{
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  *unaff_ESI = *unaff_EDI;
  unaff_ESI[6] = 0xf;
  unaff_ESI[5] = 0;
  *(undefined1 *)(unaff_ESI + 1) = 0;
  FUN_00403040(unaff_EDI + 1,0,0xffffffff);
  unaff_ESI[8] = unaff_EDI[8];
  *(undefined2 *)(unaff_ESI + 9) = *(undefined2 *)(unaff_EDI + 9);
  unaff_ESI[10] = unaff_EDI[10];
  unaff_ESI[0xb] = unaff_EDI[0xb];
  unaff_ESI[0xc] = unaff_EDI[0xc];
  unaff_ESI[0xd] = unaff_EDI[0xd];
  return;
}

