
void FUN_00787e70(void)

{
  uint uVar1;
  uint in_EAX;
  int iVar2;
  undefined4 in_ECX;
  int *unaff_ESI;
  
  iVar2 = unaff_ESI[1];
  uVar1 = (iVar2 - *unaff_ESI) / 0x44;
  if (in_EAX < uVar1) {
    if (*unaff_ESI + in_EAX * 0x44 != iVar2) {
      iVar2 = FUN_00789cf0(iVar2);
      unaff_ESI[1] = iVar2;
      return;
    }
  }
  else if (uVar1 < in_EAX) {
    FUN_00788300(in_EAX - uVar1);
    FUN_00789a50(in_ECX);
    unaff_ESI[1] = unaff_ESI[1] + (in_EAX - (unaff_ESI[1] - *unaff_ESI) / 0x44) * 0x44;
  }
  return;
}

