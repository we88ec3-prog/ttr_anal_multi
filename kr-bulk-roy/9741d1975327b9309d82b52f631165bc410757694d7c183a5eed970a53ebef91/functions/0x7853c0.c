
void FUN_007853c0(void)

{
  uint uVar1;
  uint in_EAX;
  int iVar2;
  int *unaff_ESI;
  int iVar3;
  undefined4 local_8;
  
  iVar2 = unaff_ESI[1];
  uVar1 = (iVar2 - *unaff_ESI) / 0x60;
  if (in_EAX < uVar1) {
    iVar3 = in_EAX * 0x60 + *unaff_ESI;
    if (iVar3 != iVar2) {
      iVar2 = FUN_00788f00(iVar2,iVar3);
      unaff_ESI[1] = iVar2;
      return;
    }
  }
  else if (uVar1 < in_EAX) {
    FUN_007862b0(in_EAX - uVar1);
    FUN_00788e60(local_8);
    unaff_ESI[1] = (in_EAX - (unaff_ESI[1] - *unaff_ESI) / 0x60) * 0x60 + unaff_ESI[1];
  }
  return;
}

