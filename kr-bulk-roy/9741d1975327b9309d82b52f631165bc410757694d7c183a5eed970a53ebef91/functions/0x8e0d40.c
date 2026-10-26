
int FUN_008e0d40(void)

{
  int iVar1;
  undefined4 *unaff_EDI;
  int local_c;
  int local_8;
  
  *unaff_EDI = 0;
  unaff_EDI[1] = 0;
  unaff_EDI[2] = 0;
  unaff_EDI[3] = 0;
  iVar1 = FUN_008e0480();
  if (iVar1 < 0) {
    return 0x12;
  }
  iVar1 = FUN_008e04c0();
  if (iVar1 == 0) {
    unaff_EDI[1] = local_8;
    unaff_EDI[3] = local_8;
    unaff_EDI[2] = local_8 + local_c;
    iVar1 = 0;
  }
  return iVar1;
}

