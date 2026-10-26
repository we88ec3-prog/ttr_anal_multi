
void FUN_008fd800(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *unaff_EDI;
  
  *unaff_EDI = 0;
  iVar1 = FUN_00891268(0x38);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00571a40();
  }
  unaff_EDI[1] = uVar2;
  iVar1 = FUN_00891268(8);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005719a0();
  }
  unaff_EDI[2] = uVar2;
  unaff_EDI[4] = 0;
  unaff_EDI[0xb] = 0;
  *(undefined1 *)(unaff_EDI + 0xc) = 0;
  unaff_EDI[3] = 0;
  unaff_EDI[8] = 0xffffffff;
  unaff_EDI[6] = 0;
  unaff_EDI[7] = 0;
  unaff_EDI[0xd] = 0xffffffff;
  unaff_EDI[9] = 0;
  unaff_EDI[10] = 0;
  return;
}

