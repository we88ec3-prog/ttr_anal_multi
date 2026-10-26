
int FUN_00787fe0(void)

{
  int iVar1;
  uint uVar2;
  uint in_EAX;
  int iVar3;
  undefined4 in_ECX;
  int *unaff_ESI;
  
  iVar1 = unaff_ESI[1];
  iVar3 = (iVar1 - *unaff_ESI) * -0x77777777;
  uVar2 = (iVar1 - *unaff_ESI) / 0x3c;
  if (in_EAX < uVar2) {
    iVar3 = *unaff_ESI + in_EAX * 0x3c;
    if (iVar3 != iVar1) {
      iVar3 = FUN_00789dc0(iVar1);
      unaff_ESI[1] = iVar3;
      return iVar3;
    }
  }
  else if (uVar2 < in_EAX) {
    FUN_00788400();
    FUN_00789b20(in_ECX);
    iVar3 = (unaff_ESI[1] - *unaff_ESI) / 0x3c;
    unaff_ESI[1] = unaff_ESI[1] + (in_EAX - iVar3) * 0x3c;
  }
  return iVar3;
}

