
undefined4 FUN_008d0420(void)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  undefined4 *unaff_EBX;
  byte *unaff_ESI;
  
  pbVar2 = (byte *)*unaff_EBX;
  do {
    pbVar3 = pbVar2;
    pbVar2 = pbVar3 + 1;
    if ((unaff_ESI <= pbVar2) || (FUN_008d02f0(), unaff_ESI <= pbVar2)) goto LAB_008d0463;
    bVar1 = *pbVar2;
  } while ((((0x2f < bVar1) && (bVar1 < 0x3a)) || ((0x40 < bVar1 && (bVar1 < 0x47)))) ||
          ((0x60 < bVar1 && (bVar1 < 0x67))));
  if (*pbVar2 != 0x3e) {
    *unaff_EBX = pbVar2;
    return 3;
  }
LAB_008d0463:
  *unaff_EBX = pbVar3 + 2;
  return 0;
}

