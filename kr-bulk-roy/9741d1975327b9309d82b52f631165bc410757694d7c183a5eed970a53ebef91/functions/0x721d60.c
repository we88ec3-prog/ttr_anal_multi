
byte * FUN_00721d60(byte *param_1)

{
  byte *pbVar1;
  byte bVar2;
  
  while( true ) {
    bVar2 = (&DAT_00c0b650)[*param_1];
    while ((bVar2 & 1) == 0) {
      pbVar1 = param_1 + 1;
      param_1 = param_1 + 1;
      bVar2 = (&DAT_00c0b650)[*pbVar1];
    }
    if (*param_1 == 0x3c) break;
    if (*param_1 == 0) {
      return param_1;
    }
    param_1 = param_1 + 1;
  }
  *param_1 = 0;
  return param_1 + 1;
}

