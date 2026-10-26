
byte * FUN_007222d0(byte *param_1,byte param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  byte *local_10;
  int local_c;
  
  local_10 = (byte *)0x0;
  local_c = 0;
  pbVar2 = param_1;
  pbVar5 = (byte *)0x0;
  iVar3 = 0;
  if (((&DAT_00c0b650)[*param_1] & 8) != 0) {
    do {
      pbVar5 = pbVar2 + 1;
      pbVar2 = pbVar2 + 1;
    } while (((&DAT_00c0b650)[*pbVar5] & 8) != 0);
    iVar3 = (int)pbVar2 - (int)param_1;
    pbVar5 = param_1 + iVar3;
    param_1 = pbVar5;
    local_10 = pbVar5;
    local_c = iVar3;
  }
  while( true ) {
    bVar1 = (&DAT_00c0b650)[*param_1];
    pbVar2 = param_1;
    while ((bVar1 & 0xc) == 0) {
      pbVar4 = pbVar2 + 1;
      pbVar2 = pbVar2 + 1;
      bVar1 = (&DAT_00c0b650)[*pbVar4];
    }
    bVar1 = *pbVar2;
    if (bVar1 == param_2) break;
    if (((&DAT_00c0b650)[bVar1] & 8) == 0) {
      if (bVar1 == 0x26) {
        param_1 = (byte *)FUN_0071a850(pbVar2,&local_10);
        pbVar5 = local_10;
        iVar3 = local_c;
      }
      else {
        if (bVar1 == 0) {
          return (byte *)0x0;
        }
        param_1 = pbVar2 + 1;
      }
    }
    else {
      *pbVar2 = 0x20;
      param_1 = pbVar2 + 1;
      if (((&DAT_00c0b650)[pbVar2[1]] & 8) != 0) {
        pbVar4 = pbVar2 + 2;
        bVar1 = (&DAT_00c0b650)[pbVar2[2]];
        while ((bVar1 & 8) != 0) {
          pbVar2 = pbVar4 + 1;
          pbVar4 = pbVar4 + 1;
          bVar1 = (&DAT_00c0b650)[*pbVar2];
        }
        if (pbVar5 != (byte *)0x0) {
          FID_conflict__memcpy(pbVar5 + -iVar3,pbVar5,(int)param_1 - (int)pbVar5);
        }
        pbVar5 = param_1 + ((int)pbVar4 - (int)param_1);
        iVar3 = iVar3 + ((int)pbVar4 - (int)param_1);
        param_1 = pbVar5;
        local_10 = pbVar5;
        local_c = iVar3;
      }
    }
  }
  pbVar4 = pbVar2;
  if (pbVar5 != (byte *)0x0) {
    FID_conflict__memcpy(pbVar5 + -iVar3,pbVar5,(int)pbVar2 - (int)pbVar5);
    pbVar4 = pbVar2 + -iVar3;
  }
  do {
    *pbVar4 = 0;
    pbVar5 = pbVar4 + -1;
    pbVar4 = pbVar4 + -1;
  } while (((&DAT_00c0b650)[*pbVar5] & 8) != 0);
  return pbVar2 + 1;
}

