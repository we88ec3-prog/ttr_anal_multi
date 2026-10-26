
byte * FUN_00721f20(byte *param_1)

{
  byte *pbVar1;
  byte bVar2;
  byte *_Src;
  byte *pbVar3;
  int iVar4;
  byte *local_10;
  int local_c;
  
  _Src = (byte *)0x0;
  iVar4 = 0;
  local_10 = _Src;
  local_c = iVar4;
  while( true ) {
    bVar2 = (&DAT_00c0b650)[*param_1];
    pbVar3 = param_1;
    while ((bVar2 & 1) == 0) {
      pbVar1 = pbVar3 + 1;
      pbVar3 = pbVar3 + 1;
      bVar2 = (&DAT_00c0b650)[*pbVar1];
    }
    bVar2 = *pbVar3;
    if (bVar2 == 0x3c) break;
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
        local_10 = _Src;
        local_c = iVar4;
      }
    }
    else if (bVar2 == 0x26) {
      param_1 = (byte *)FUN_0071a850(pbVar3,&local_10);
      _Src = local_10;
      iVar4 = local_c;
    }
    else {
      if (bVar2 == 0) {
        return pbVar3;
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

