
void FUN_00856430(void)

{
  undefined4 *unaff_EDI;
  
  unaff_EDI[7] = gbParam::vftable;
  FUN_00867f40();
  if (0xf < (uint)unaff_EDI[5]) {
    FUN_0089120c(*unaff_EDI);
  }
  unaff_EDI[5] = 0xf;
  unaff_EDI[4] = 0;
  *(undefined1 *)unaff_EDI = 0;
  return;
}

