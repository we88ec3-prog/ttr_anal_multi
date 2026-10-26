
void FUN_00850490(void)

{
  uint uVar1;
  uint in_EAX;
  int iVar2;
  undefined4 in_ECX;
  int *unaff_ESI;
  
  uVar1 = (unaff_ESI[1] - *unaff_ESI) / 0x14;
  if (in_EAX < uVar1) {
    iVar2 = *unaff_ESI + in_EAX * 0x14;
    if (iVar2 != unaff_ESI[1]) {
      iVar2 = FUN_004fa270(iVar2);
      unaff_ESI[1] = iVar2;
      return;
    }
  }
  else if (uVar1 < in_EAX) {
    FUN_00850af0(in_EAX - uVar1);
    FUN_00853960(in_EAX - (unaff_ESI[1] - *unaff_ESI) / 0x14,in_ECX);
    unaff_ESI[1] = unaff_ESI[1] + (in_EAX - (unaff_ESI[1] - *unaff_ESI) / 0x14) * 0x14;
  }
  return;
}

