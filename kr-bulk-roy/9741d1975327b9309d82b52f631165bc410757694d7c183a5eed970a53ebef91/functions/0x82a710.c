
void FUN_0082a710(undefined4 param_1)

{
  undefined4 *in_ECX;
  undefined4 *unaff_ESI;
  
  *unaff_ESI = *in_ECX;
  unaff_ESI[5] = 0;
  unaff_ESI[6] = 7;
  *(undefined2 *)(unaff_ESI + 1) = 0;
  FUN_004026e0(param_1,0,0xffffffff);
  return;
}

