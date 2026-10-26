
void FUN_00787d10(void)

{
  uint uVar1;
  uint in_EAX;
  int iVar2;
  int *unaff_ESI;
  undefined4 local_8;
  
  iVar2 = unaff_ESI[1];
  uVar1 = (iVar2 - *unaff_ESI) / 0x18;
  if (in_EAX < uVar1) {
    if (*unaff_ESI + in_EAX * 0x18 != iVar2) {
      iVar2 = FUN_00789c40(iVar2);
      unaff_ESI[1] = iVar2;
      return;
    }
  }
  else if (uVar1 < in_EAX) {
    FUN_00788200(in_EAX - uVar1);
    FUN_00789960(local_8);
    unaff_ESI[1] = unaff_ESI[1] + (in_EAX - (unaff_ESI[1] - *unaff_ESI) / 0x18) * 0x18;
  }
  return;
}

