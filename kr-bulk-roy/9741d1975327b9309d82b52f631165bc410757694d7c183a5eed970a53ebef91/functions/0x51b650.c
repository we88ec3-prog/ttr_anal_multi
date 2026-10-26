
void FUN_0051b650(void)

{
  undefined1 *in_EAX;
  undefined4 *in_ECX;
  undefined4 *unaff_ESI;
  
  *unaff_ESI = *in_ECX;
  *(undefined1 *)(unaff_ESI + 1) = *in_EAX;
  FUN_007e8a90(unaff_ESI + 2,in_EAX + 4);
  return;
}

