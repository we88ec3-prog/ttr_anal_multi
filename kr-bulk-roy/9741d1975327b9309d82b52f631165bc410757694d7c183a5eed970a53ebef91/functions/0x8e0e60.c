
int FUN_008e0e60(int param_1)

{
  int in_ECX;
  int in_EDX;
  int unaff_ESI;
  
  return (param_1 - unaff_ESI >> 0x10) * (in_EDX >> 0x10) -
         (in_ECX - in_EDX >> 0x10) * (unaff_ESI >> 0x10);
}

