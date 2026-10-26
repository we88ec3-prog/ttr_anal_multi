
void FUN_008dd080(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *unaff_ESI;
  
  _memset(unaff_ESI,0,0x1a0);
  unaff_ESI[0x65] = unaff_ESI + 4;
  unaff_ESI[0x66] = param_1;
  unaff_ESI[0x67] = param_2;
  *unaff_ESI = param_3;
  return;
}

