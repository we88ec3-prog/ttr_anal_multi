
byte * FUN_0071ab60(char param_1)

{
  byte *pbVar1;
  byte bVar2;
  byte *in_EAX;
  byte *_Src;
  byte *pbVar3;
  int iVar4;
  
  _Src = (byte *)0x0;
  iVar4 = 0;
  while( true ) {
    while( true ) {
      bVar2 = (&DAT_00c0b650)[*in_EAX];
      pbVar3 = in_EAX;
      while ((bVar2 & 0x10) == 0) {
        pbVar1 = pbVar3 + 1;
        pbVar3 = pbVar3 + 1;
        bVar2 = (&DAT_00c0b650)[*pbVar1];
      }
      bVar2 = *pbVar3;
      if (bVar2 != 0xd) break;
      *pbVar3 = 10;
      in_EAX = pbVar3 + 1;
      if (*in_EAX == 10) {
        if (_Src != (byte *)0x0) {
          FID_conflict__memcpy(_Src + -iVar4,_Src,(int)in_EAX - (int)_Src);
        }
        _Src = pbVar3 + 2;
        iVar4 = iVar4 + 1;
        in_EAX = _Src;
      }
    }
    if (((bVar2 == 0x5d) && (pbVar3[1] == 0x5d)) &&
       ((pbVar3[2] == 0x3e || ((pbVar3[2] == 0 && (param_1 == '>')))))) break;
    if (bVar2 == 0) {
      return (byte *)0x0;
    }
    in_EAX = pbVar3 + 1;
  }
  if (_Src != (byte *)0x0) {
    FID_conflict__memcpy(_Src + -iVar4,_Src,(int)pbVar3 - (int)_Src);
    pbVar3[-iVar4] = 0;
    return pbVar3 + 1;
  }
  *pbVar3 = 0;
  return pbVar3 + 1;
}

