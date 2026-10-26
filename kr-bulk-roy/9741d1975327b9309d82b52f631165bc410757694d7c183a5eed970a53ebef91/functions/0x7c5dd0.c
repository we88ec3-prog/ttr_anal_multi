
void FUN_007c5dd0(void)

{
  uint uVar1;
  uint in_EAX;
  uint *unaff_EDI;
  
  uVar1 = unaff_EDI[1];
  if ((in_EAX < uVar1) && (*unaff_EDI <= in_EAX)) {
    if (uVar1 == unaff_EDI[2]) {
      FUN_007b1c00();
    }
    FUN_007b2fd0(unaff_EDI[1]);
    unaff_EDI[1] = unaff_EDI[1] + 0x38;
    return;
  }
  if (uVar1 == unaff_EDI[2]) {
    FUN_007b1c00();
  }
  FUN_007b2fd0(unaff_EDI[1]);
  unaff_EDI[1] = unaff_EDI[1] + 0x38;
  return;
}

