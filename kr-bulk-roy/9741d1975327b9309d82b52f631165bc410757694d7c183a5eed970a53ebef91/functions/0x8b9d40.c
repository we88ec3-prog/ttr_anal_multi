
int FUN_008b9d40(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint *unaff_EBX;
  
  uVar1 = *unaff_EBX;
  uVar2 = unaff_EBX[1];
  iVar3 = FUN_008b7cb0((uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f) |
                       (uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f));
  if (iVar3 < 0x1e) {
    bVar4 = (byte)(0x1d - iVar3);
    *unaff_EBX = uVar1 << (bVar4 & 0x1f);
    unaff_EBX[1] = uVar2 << (bVar4 & 0x1f);
    return 0x1d - iVar3;
  }
  bVar4 = (byte)(iVar3 + -0x1d);
  unaff_EBX[1] = (int)uVar2 >> (bVar4 & 0x1f);
  *unaff_EBX = (int)uVar1 >> (bVar4 & 0x1f);
  return -(iVar3 + -0x1d);
}

