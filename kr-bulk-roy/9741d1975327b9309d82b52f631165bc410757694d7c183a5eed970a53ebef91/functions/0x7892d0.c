
void FUN_007892d0(void)

{
  uint uVar1;
  uint in_EAX;
  uint *unaff_EDI;
  
  uVar1 = unaff_EDI[1];
  if ((in_EAX < uVar1) && (*unaff_EDI <= in_EAX)) {
    if (uVar1 == unaff_EDI[2]) {
      FUN_00788380();
    }
    FUN_00789e60();
    unaff_EDI[1] = unaff_EDI[1] + 0x1c;
    return;
  }
  if (uVar1 == unaff_EDI[2]) {
    FUN_00788380();
  }
  FUN_00789e60();
  unaff_EDI[1] = unaff_EDI[1] + 0x1c;
  return;
}

