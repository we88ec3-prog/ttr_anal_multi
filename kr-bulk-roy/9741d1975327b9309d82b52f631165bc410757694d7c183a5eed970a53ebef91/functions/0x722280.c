
byte * FUN_00722280(byte *param_1,byte param_2)

{
  byte *pbVar1;
  byte bVar2;
  
  while( true ) {
    bVar2 = (&DAT_00c0b650)[*param_1];
    while ((bVar2 & 2) == 0) {
      pbVar1 = param_1 + 1;
      param_1 = param_1 + 1;
      bVar2 = (&DAT_00c0b650)[*pbVar1];
    }
    if (*param_1 == param_2) break;
    if (*param_1 == 0) {
      return (byte *)0x0;
    }
    param_1 = param_1 + 1;
  }
  *param_1 = 0;
  return param_1 + 1;
}

