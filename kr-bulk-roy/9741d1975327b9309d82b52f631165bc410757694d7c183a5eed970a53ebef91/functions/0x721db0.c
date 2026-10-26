
byte * FUN_00721db0(byte *param_1)

{
  byte *pbVar1;
  byte bVar2;
  int iVar3;
  void *local_10;
  int local_c;
  
  local_10 = (void *)0x0;
  local_c = 0;
  while( true ) {
    iVar3 = local_c;
    bVar2 = (&DAT_00c0b650)[*param_1];
    while ((bVar2 & 1) == 0) {
      pbVar1 = param_1 + 1;
      param_1 = param_1 + 1;
      bVar2 = (&DAT_00c0b650)[*pbVar1];
    }
    bVar2 = *param_1;
    if (bVar2 == 0x3c) break;
    if (bVar2 == 0x26) {
      param_1 = (byte *)FUN_0071a850(param_1,&local_10);
    }
    else {
      if (bVar2 == 0) {
        return param_1;
      }
      param_1 = param_1 + 1;
    }
  }
  if (local_10 != (void *)0x0) {
    FID_conflict__memcpy((void *)((int)local_10 - local_c),local_10,(int)param_1 - (int)local_10);
    param_1[-iVar3] = 0;
    return param_1 + 1;
  }
  *param_1 = 0;
  return param_1 + 1;
}

