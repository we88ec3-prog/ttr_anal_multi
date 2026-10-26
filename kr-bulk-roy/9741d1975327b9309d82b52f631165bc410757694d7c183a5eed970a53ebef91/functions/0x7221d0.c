
byte * FUN_007221d0(byte *param_1,byte param_2)

{
  byte *pbVar1;
  byte bVar2;
  byte *_Src;
  byte *pbVar3;
  int iVar4;
  
  _Src = (byte *)0x0;
  iVar4 = 0;
  while( true ) {
    bVar2 = (&DAT_00c0b650)[*param_1];
    pbVar3 = param_1;
    while ((bVar2 & 2) == 0) {
      pbVar1 = pbVar3 + 1;
      pbVar3 = pbVar3 + 1;
      bVar2 = (&DAT_00c0b650)[*pbVar1];
    }
    bVar2 = *pbVar3;
    if (bVar2 == param_2) break;
    if (bVar2 == 0xd) {
      *pbVar3 = 10;
      param_1 = pbVar3 + 1;
      if (*param_1 == 10) {
        if (_Src != (byte *)0x0) {
          FID_conflict__memcpy(_Src + -iVar4,_Src,(int)param_1 - (int)_Src);
        }
        _Src = pbVar3 + 2;
        iVar4 = iVar4 + 1;
        param_1 = _Src;
      }
    }
    else {
      if (bVar2 == 0) {
        return (byte *)0x0;
      }
      param_1 = pbVar3 + 1;
    }
  }
  if (_Src != (byte *)0x0) {
    FID_conflict__memcpy(_Src + -iVar4,_Src,(int)pbVar3 - (int)_Src);
    pbVar3[-iVar4] = 0;
    return pbVar3 + 1;
  }
  *pbVar3 = 0;
  return pbVar3 + 1;
}

