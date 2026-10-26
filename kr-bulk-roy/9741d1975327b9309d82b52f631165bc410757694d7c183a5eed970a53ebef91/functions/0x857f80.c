
void FUN_00857f80(void)

{
  uint uVar1;
  uint in_EAX;
  int *unaff_ESI;
  undefined4 local_8;
  
  uVar1 = (unaff_ESI[1] - *unaff_ESI) / 0x14;
  if (in_EAX < uVar1) {
    FUN_00850dc0(unaff_ESI,&local_8,*unaff_ESI + in_EAX * 0x14,unaff_ESI[1]);
    return;
  }
  if (uVar1 < in_EAX) {
    FUN_008508f0(in_EAX - uVar1);
    FUN_008581a0(unaff_ESI[1],local_8);
    unaff_ESI[1] = unaff_ESI[1] + (in_EAX - (unaff_ESI[1] - *unaff_ESI) / 0x14) * 0x14;
  }
  return;
}

