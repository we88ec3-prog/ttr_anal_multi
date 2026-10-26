
void FUN_00824ee0(void)

{
  undefined4 *in_EAX;
  undefined4 *in_ECX;
  undefined4 *unaff_ESI;
  
  *unaff_ESI = *in_ECX;
  unaff_ESI[1] = *in_EAX;
  FUN_004fcd00(unaff_ESI + 2,in_EAX + 1);
  return;
}

