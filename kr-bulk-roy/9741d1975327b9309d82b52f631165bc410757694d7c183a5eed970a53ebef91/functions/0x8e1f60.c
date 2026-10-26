
int FUN_008e1f60(void)

{
  int iVar1;
  int iVar2;
  uint unaff_ESI;
  undefined8 uVar3;
  
  uVar3 = FUN_008e1e30();
  iVar2 = (int)((ulonglong)uVar3 >> 0x20);
  if ((uint)uVar3 <= unaff_ESI) {
    FUN_008e0760();
    return 0;
  }
  iVar1 = *(int *)(iVar2 + 0xc + unaff_ESI * 8);
  if (iVar1 == 1) {
    iVar2 = *(int *)(iVar2 + 8 + unaff_ESI * 8);
    if (iVar2 < 0) {
      return -(0x2000 - iVar2 >> 0xe);
    }
    iVar2 = iVar2 + 0x2000 >> 0xe;
  }
  else {
    iVar2 = *(int *)(iVar2 + 8 + unaff_ESI * 8);
    if (iVar1 == 2) {
      return iVar2 << 0x10;
    }
  }
  return iVar2;
}

