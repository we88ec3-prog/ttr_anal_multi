
void FUN_008ca950(int param_1)

{
  int iVar1;
  int *unaff_ESI;
  
  if (param_1 == 0) {
    *unaff_ESI = 6;
    unaff_ESI[4] = 0x20;
    unaff_ESI[5] = 2;
  }
  else {
    *unaff_ESI = 0xc;
    unaff_ESI[4] = 0x100;
    unaff_ESI[5] = 0x1e;
  }
  iVar1 = 1 << ((byte)*unaff_ESI & 0x1f);
  unaff_ESI[1] = iVar1;
  unaff_ESI[2] = iVar1 / 2;
  unaff_ESI[3] = *unaff_ESI + -6;
  return;
}

