
int FUN_005809a0(void)

{
  int *in_EAX;
  uint unaff_EDI;
  
  if (unaff_EDI < (uint)((in_EAX[1] - *in_EAX) / 0x34)) {
    return unaff_EDI * 0x34 + *in_EAX;
  }
  return 0;
}

