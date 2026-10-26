
byte * FUN_007312f0(void)

{
  byte bVar1;
  byte *in_EAX;
  int iVar2;
  byte *pbVar3;
  
  FUN_00402a70(&DAT_00bf2375,0);
  if (((in_EAX == (byte *)0x0) || (bVar1 = *in_EAX, bVar1 == 0)) ||
     ((pbVar3 = in_EAX, bVar1 < 0x7f &&
      ((iVar2 = _isalpha((uint)bVar1), iVar2 == 0 && (*in_EAX != 0x5f)))))) {
    return (byte *)0x0;
  }
  do {
    bVar1 = *pbVar3;
    if ((bVar1 == 0) ||
       (((((bVar1 < 0x7f && (iVar2 = _isalnum((uint)bVar1), iVar2 == 0)) &&
          (bVar1 = *pbVar3, bVar1 != 0x5f)) && ((bVar1 != 0x2d && (bVar1 != 0x2e)))) &&
        (bVar1 != 0x3a)))) break;
    pbVar3 = pbVar3 + 1;
  } while (pbVar3 != (byte *)0x0);
  if (0 < (int)pbVar3 - (int)in_EAX) {
    FUN_00402a70(in_EAX,(int)pbVar3 - (int)in_EAX);
  }
  return pbVar3;
}

