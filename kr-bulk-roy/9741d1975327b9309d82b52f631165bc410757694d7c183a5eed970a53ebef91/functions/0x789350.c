
void FUN_00789350(void)

{
  uint uVar1;
  uint in_EAX;
  uint *unaff_EDI;
  
  uVar1 = unaff_EDI[1];
  if ((in_EAX < uVar1) && (*unaff_EDI <= in_EAX)) {
    if (uVar1 == unaff_EDI[2]) {
      FUN_00788400();
    }
    if (unaff_EDI[1] != 0) {
      FUN_007866a0();
      unaff_EDI[1] = unaff_EDI[1] + 0x3c;
      return;
    }
  }
  else {
    if (uVar1 == unaff_EDI[2]) {
      FUN_00788400();
    }
    if (unaff_EDI[1] != 0) {
      FUN_007866a0();
    }
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x3c;
  return;
}

