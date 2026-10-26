
int FUN_00837b80(void)

{
  int *in_EAX;
  int iVar1;
  uint uVar2;
  int *unaff_EDI;
  
  if (*unaff_EDI != 0) {
    return unaff_EDI[1];
  }
  uVar2 = in_EAX[1] * unaff_EDI[3] + *in_EAX;
  if (unaff_EDI[1] <= (int)uVar2) {
    return 0;
  }
  iVar1 = FUN_008fed10();
  uVar2 = uVar2 & 0x80000007;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffff8) + 1;
  }
  return (int)(char)(*(byte *)(unaff_EDI[2] - iVar1) & '\x01' << ((byte)uVar2 & 0x1f));
}

