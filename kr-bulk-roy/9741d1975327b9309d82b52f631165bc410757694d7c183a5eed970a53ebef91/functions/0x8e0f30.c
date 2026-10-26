
void FUN_008e0f30(int param_1,int param_2,int param_3)

{
  int *unaff_ESI;
  int unaff_EDI;
  
  _memset(unaff_ESI,0,0xf1c);
  *(undefined1 *)((int)unaff_ESI + 0xd) = *(undefined1 *)(unaff_EDI + 0x8c);
  unaff_ESI[4] = param_3;
  *unaff_ESI = unaff_EDI;
  unaff_ESI[1] = param_1;
  unaff_ESI[2] = param_2;
  return;
}

