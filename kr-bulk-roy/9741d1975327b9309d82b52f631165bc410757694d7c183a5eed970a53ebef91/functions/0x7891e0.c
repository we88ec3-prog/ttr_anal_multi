
void FUN_007891e0(void)

{
  uint uVar1;
  uint in_EAX;
  uint *unaff_EDI;
  
  uVar1 = unaff_EDI[1];
  if ((in_EAX < uVar1) && (*unaff_EDI <= in_EAX)) {
    if (uVar1 == unaff_EDI[2]) {
      FUN_00788280(1);
    }
    if (unaff_EDI[1] != 0) {
      FUN_007865b0();
      unaff_EDI[1] = unaff_EDI[1] + 0x30;
      return;
    }
  }
  else {
    if (uVar1 == unaff_EDI[2]) {
      FUN_00788280(1);
    }
    if (unaff_EDI[1] != 0) {
      FUN_007865b0();
    }
  }
  unaff_EDI[1] = unaff_EDI[1] + 0x30;
  return;
}

