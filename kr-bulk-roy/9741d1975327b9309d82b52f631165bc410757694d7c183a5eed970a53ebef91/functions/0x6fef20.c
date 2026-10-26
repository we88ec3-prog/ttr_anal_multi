
undefined4 FUN_006fef20(void)

{
  uint in_EAX;
  undefined4 uVar1;
  undefined4 *unaff_EDI;
  
  if (in_EAX <= (uint)unaff_EDI[2]) {
    return *unaff_EDI;
  }
  if (in_EAX < 0x20) {
    in_EAX = 0x20;
  }
  if (in_EAX + 1 < 0xfffffffe) {
    uVar1 = FUN_00700880();
    *unaff_EDI = uVar1;
    unaff_EDI[2] = in_EAX;
    return uVar1;
  }
  FUN_006f8b60();
  *unaff_EDI = 0;
  unaff_EDI[2] = in_EAX;
  return 0;
}

