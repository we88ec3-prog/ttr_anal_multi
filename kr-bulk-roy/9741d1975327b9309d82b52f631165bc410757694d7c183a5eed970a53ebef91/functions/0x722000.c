
byte * FUN_00722000(byte *param_1,byte param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  int iVar5;
  
  pbVar4 = (byte *)0x0;
  iVar5 = 0;
  pbVar2 = param_1;
  if (((&DAT_00c0b650)[*param_1] & 8) != 0) {
    do {
      pbVar4 = pbVar2 + 1;
      pbVar2 = pbVar2 + 1;
    } while (((&DAT_00c0b650)[*pbVar4] & 8) != 0);
    iVar5 = (int)pbVar2 - (int)param_1;
    pbVar4 = param_1 + iVar5;
    param_1 = pbVar4;
  }
  while( true ) {
    bVar1 = (&DAT_00c0b650)[*param_1];
    pbVar2 = param_1;
    while ((bVar1 & 0xc) == 0) {
      pbVar3 = pbVar2 + 1;
      pbVar2 = pbVar2 + 1;
      bVar1 = (&DAT_00c0b650)[*pbVar3];
    }
    bVar1 = *pbVar2;
    if (bVar1 == param_2) break;
    if (((&DAT_00c0b650)[bVar1] & 8) == 0) {
      if (bVar1 == 0) {
        return (byte *)0x0;
      }
      param_1 = pbVar2 + 1;
    }
    else {
      *pbVar2 = 0x20;
      param_1 = pbVar2 + 1;
      if (((&DAT_00c0b650)[pbVar2[1]] & 8) != 0) {
        pbVar3 = pbVar2 + 2;
        bVar1 = (&DAT_00c0b650)[pbVar2[2]];
        while ((bVar1 & 8) != 0) {
          pbVar2 = pbVar3 + 1;
          pbVar3 = pbVar3 + 1;
          bVar1 = (&DAT_00c0b650)[*pbVar2];
        }
        if (pbVar4 != (byte *)0x0) {
          FID_conflict__memcpy(pbVar4 + -iVar5,pbVar4,(int)param_1 - (int)pbVar4);
        }
        pbVar4 = param_1 + ((int)pbVar3 - (int)param_1);
        iVar5 = iVar5 + ((int)pbVar3 - (int)param_1);
        param_1 = pbVar4;
      }
    }
  }
  pbVar3 = pbVar2;
  if (pbVar4 != (byte *)0x0) {
    FID_conflict__memcpy(pbVar4 + -iVar5,pbVar4,(int)pbVar2 - (int)pbVar4);
    pbVar3 = pbVar2 + -iVar5;
  }
  do {
    *pbVar3 = 0;
    pbVar4 = pbVar3 + -1;
    pbVar3 = pbVar3 + -1;
  } while (((&DAT_00c0b650)[*pbVar4] & 8) != 0);
  return pbVar2 + 1;
}

