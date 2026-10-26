
void FUN_00847e40(void)

{
  uint uVar1;
  uint in_EAX;
  int *unaff_EDI;
  undefined4 local_8;
  
  uVar1 = (unaff_EDI[1] - *unaff_EDI) / 0x34;
  if (in_EAX < uVar1) {
    FUN_008481e0(unaff_EDI,&local_8,in_EAX * 0x34 + *unaff_EDI,unaff_EDI[1]);
    return;
  }
  if (uVar1 < in_EAX) {
    FUN_00848230(in_EAX - uVar1);
    FUN_00848940(unaff_EDI[1],in_EAX - (unaff_EDI[1] - *unaff_EDI) / 0x34,local_8);
    unaff_EDI[1] = (in_EAX - (unaff_EDI[1] - *unaff_EDI) / 0x34) * 0x34 + unaff_EDI[1];
  }
  return;
}

