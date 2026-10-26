
int FUN_008ccb00(void)

{
  int iVar1;
  uint *in_ECX;
  byte *pbVar2;
  uint unaff_EBX;
  
  if (-1 < (int)unaff_EBX) {
    if (*in_ECX <= unaff_EBX) {
      iVar1 = FUN_008cca60();
      if (iVar1 != 0) {
        return iVar1;
      }
      *in_ECX = unaff_EBX + 1;
    }
    pbVar2 = (byte *)(((int)unaff_EBX >> 3) + in_ECX[2]);
    *pbVar2 = *pbVar2 | (byte)(0x80 >> ((byte)unaff_EBX & 7));
  }
  return 0;
}

