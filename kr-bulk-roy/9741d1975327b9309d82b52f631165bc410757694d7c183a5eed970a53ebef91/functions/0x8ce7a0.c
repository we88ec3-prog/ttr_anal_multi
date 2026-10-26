
void FUN_008ce7a0(void)

{
  undefined4 uVar1;
  undefined4 *unaff_EDI;
  
  uVar1 = unaff_EDI[4];
  FUN_008cdf80();
  FUN_008cdf80();
  FUN_008b9f80(uVar1,unaff_EDI[2]);
  unaff_EDI[2] = 0;
  FUN_008b9f80(uVar1,unaff_EDI[3]);
  unaff_EDI[3] = 0;
  *unaff_EDI = 0;
  unaff_EDI[1] = 0;
  unaff_EDI[4] = 0;
  return;
}

