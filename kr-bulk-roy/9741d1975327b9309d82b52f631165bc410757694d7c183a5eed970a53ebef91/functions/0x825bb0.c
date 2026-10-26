
void FUN_00825bb0(void)

{
  undefined1 *in_EAX;
  undefined1 *in_ECX;
  undefined1 *unaff_ESI;
  
  *unaff_ESI = *in_ECX;
  unaff_ESI[4] = *in_EAX;
  unaff_ESI[5] = in_EAX[1];
  FUN_0052f3b0(unaff_ESI + 8,in_EAX + 4);
  return;
}

