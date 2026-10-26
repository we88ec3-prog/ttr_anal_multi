
void FUN_0071cd10(void)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte *unaff_ESI;
  
  pbVar2 = unaff_ESI;
  pbVar4 = unaff_ESI;
  if (*unaff_ESI == 0) {
    *unaff_ESI = 0;
    return;
  }
  do {
    pbVar3 = pbVar2 + 1;
    if (((&DAT_00c0b650)[*pbVar2] & 8) == 0) {
      *pbVar4 = *pbVar2;
LAB_0071cd58:
      pbVar4 = pbVar4 + 1;
    }
    else {
      bVar1 = (&DAT_00c0b650)[*pbVar3];
      while ((bVar1 & 8) != 0) {
        pbVar2 = pbVar3 + 1;
        pbVar3 = pbVar3 + 1;
        bVar1 = (&DAT_00c0b650)[*pbVar2];
      }
      if (pbVar4 != unaff_ESI) {
        *pbVar4 = 0x20;
        goto LAB_0071cd58;
      }
    }
    pbVar2 = pbVar3;
    if (*pbVar3 == 0) {
      if ((pbVar4 != unaff_ESI) && (((&DAT_00c0b650)[pbVar4[-1]] & 8) != 0)) {
        pbVar4[-1] = 0;
        return;
      }
      *pbVar4 = 0;
      return;
    }
  } while( true );
}

