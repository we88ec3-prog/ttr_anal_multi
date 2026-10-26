
uint FUN_00787c60(void)

{
  uint in_EAX;
  uint uVar1;
  undefined4 in_ECX;
  int iVar2;
  int *unaff_EDI;
  
  iVar2 = unaff_EDI[1];
  uVar1 = (iVar2 - *unaff_EDI) / 0x2c;
  if (in_EAX < uVar1) {
    if (in_EAX * 0x2c + *unaff_EDI != iVar2) {
      uVar1 = FUN_00789be0(iVar2);
      unaff_EDI[1] = uVar1;
      return uVar1;
    }
  }
  else if (uVar1 < in_EAX) {
    FUN_00788180(in_EAX - uVar1);
    FUN_007898d0(in_ECX);
    iVar2 = unaff_EDI[1] - *unaff_EDI;
    uVar1 = iVar2 * 0x2e8ba2e9;
    unaff_EDI[1] = (in_EAX - iVar2 / 0x2c) * 0x2c + unaff_EDI[1];
  }
  return uVar1;
}

