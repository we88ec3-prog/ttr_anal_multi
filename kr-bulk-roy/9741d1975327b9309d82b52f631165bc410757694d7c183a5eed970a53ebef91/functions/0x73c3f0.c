
void FUN_0073c3f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CFontDriver_GDI::vftable;
  FUN_0073bd10();
  if (in_ECX[6] != 0) {
    FUN_0089120c(in_ECX[6]);
  }
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  *in_ECX = CFontDriver::vftable;
  if ((param_1 & 1) != 0) {
    FUN_0089120c();
  }
  return;
}

