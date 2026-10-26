
void FUN_008656c0(void)

{
  int *piVar1;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  
  unaff_ESI[10] = 0;
  unaff_ESI[0xb] = 0;
  piVar1 = (int *)*unaff_EDI;
  *unaff_ESI = piVar1;
  (**(code **)(*piVar1 + 4))(piVar1);
  unaff_ESI[3] = unaff_EDI[3];
  unaff_ESI[4] = unaff_EDI[4];
  unaff_ESI[5] = unaff_EDI[5];
  unaff_ESI[7] = unaff_EDI[7];
  unaff_ESI[6] = unaff_EDI[6];
  unaff_ESI[1] = unaff_EDI[1];
  unaff_ESI[2] = unaff_EDI[2];
  unaff_ESI[8] = unaff_EDI[8];
  unaff_ESI[10] = unaff_EDI[10];
  unaff_ESI[0xb] = unaff_EDI[0xb];
  unaff_ESI[9] = unaff_EDI[9];
  return;
}

