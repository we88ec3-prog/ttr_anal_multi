
void FUN_00821810(void)

{
  undefined1 *in_EAX;
  undefined1 *in_ECX;
  undefined1 *unaff_ESI;
  
  *unaff_ESI = *in_ECX;
  unaff_ESI[4] = *in_EAX;
  FUN_00821de0(unaff_ESI + 8,in_EAX + 4);
  return;
}

