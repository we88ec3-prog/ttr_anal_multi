
void FUN_00655d40(void)

{
  uint in_EAX;
  uint uVar1;
  int iVar2;
  undefined4 in_ECX;
  int *unaff_EDI;
  
  iVar2 = unaff_EDI[1];
  uVar1 = iVar2 - *unaff_EDI >> 4;
  if (in_EAX < uVar1) {
    if (*unaff_EDI + in_EAX * 0x10 != iVar2) {
      iVar2 = FUN_00858240(iVar2);
      FUN_00516210(unaff_EDI[1]);
      unaff_EDI[1] = iVar2;
      return;
    }
  }
  else if (uVar1 < in_EAX) {
    FUN_00655dd0();
    FUN_00655f00(unaff_EDI[1],in_ECX);
    unaff_EDI[1] = (in_EAX - (unaff_EDI[1] - *unaff_EDI >> 4)) * 0x10 + unaff_EDI[1];
  }
  return;
}

