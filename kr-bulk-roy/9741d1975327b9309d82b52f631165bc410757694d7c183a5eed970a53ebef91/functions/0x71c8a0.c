
bool FUN_0071c8a0(void)

{
  byte *pbVar1;
  byte bVar2;
  byte *in_EAX;
  byte bVar3;
  
  bVar2 = (&DAT_00c0b650)[*in_EAX];
  while ((bVar2 & 8) != 0) {
    pbVar1 = in_EAX + 1;
    in_EAX = in_EAX + 1;
    bVar2 = (&DAT_00c0b650)[*pbVar1];
  }
  if (*in_EAX == 0x2d) {
    in_EAX = in_EAX + 1;
  }
  bVar2 = *in_EAX;
  if (bVar2 != 0) {
    bVar3 = (&DAT_00c0b750)[bVar2] & 8;
    if ((bVar3 == 0) && ((bVar2 != 0x2e || (((&DAT_00c0b750)[in_EAX[1]] & 8) == 0)))) {
      return false;
    }
    while (bVar3 != 0) {
      pbVar1 = in_EAX + 1;
      in_EAX = in_EAX + 1;
      bVar3 = (&DAT_00c0b750)[*pbVar1] & 8;
    }
    if (*in_EAX == 0x2e) {
      bVar2 = (&DAT_00c0b750)[in_EAX[1]];
      pbVar1 = in_EAX;
      while (in_EAX = pbVar1 + 1, (bVar2 & 8) != 0) {
        bVar2 = (&DAT_00c0b750)[pbVar1[2]];
        pbVar1 = in_EAX;
      }
    }
    bVar2 = (&DAT_00c0b650)[*in_EAX];
    while ((bVar2 & 8) != 0) {
      pbVar1 = in_EAX + 1;
      in_EAX = in_EAX + 1;
      bVar2 = (&DAT_00c0b650)[*pbVar1];
    }
    return *in_EAX == 0;
  }
  return false;
}

