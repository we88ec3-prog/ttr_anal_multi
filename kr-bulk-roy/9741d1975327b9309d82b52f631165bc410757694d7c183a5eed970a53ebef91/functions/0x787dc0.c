
uint FUN_00787dc0(void)

{
  uint in_EAX;
  uint uVar1;
  int iVar2;
  int *unaff_ESI;
  undefined4 local_8;
  
  iVar2 = unaff_ESI[1];
  uVar1 = (iVar2 - *unaff_ESI) / 0x30;
  if (in_EAX < uVar1) {
    if (in_EAX * 0x30 + *unaff_ESI != iVar2) {
      uVar1 = FUN_00789c80(iVar2);
      unaff_ESI[1] = uVar1;
      return uVar1;
    }
  }
  else if (uVar1 < in_EAX) {
    FUN_00788280(in_EAX - uVar1);
    FUN_007899c0(local_8);
    iVar2 = unaff_ESI[1] - *unaff_ESI;
    uVar1 = iVar2 * 0x2aaaaaab;
    unaff_ESI[1] = (in_EAX - iVar2 / 0x30) * 0x30 + unaff_ESI[1];
  }
  return uVar1;
}

