
int FUN_008300d0(void)

{
  float fVar1;
  float fVar2;
  byte *in_EAX;
  int iVar3;
  
  fVar1 = (float)(int)((uint)*in_EAX * DAT_00f8bd48 + (uint)in_EAX[3] * DAT_00f8bd4c +
                       (uint)in_EAX[6] * DAT_00f8bd50 + (uint)in_EAX[1] * DAT_00f8bd54 +
                       (uint)in_EAX[4] * DAT_00f8bd58 + (uint)in_EAX[7] * DAT_00f8bd5c +
                       (uint)in_EAX[2] * DAT_00f8bd60 + (uint)in_EAX[5] * DAT_00f8bd64 +
                      (uint)in_EAX[8] * DAT_00f8bd68);
  fVar2 = (float)(int)((uint)*in_EAX * DAT_00f8bd6c + (uint)in_EAX[3] * DAT_00f8bd70 +
                       (uint)in_EAX[6] * DAT_00f8bd74 + (uint)in_EAX[1] * DAT_00f8bd78 +
                       (uint)in_EAX[4] * DAT_00f8bd7c + (uint)in_EAX[7] * DAT_00f8bd80 +
                       (uint)in_EAX[2] * DAT_00f8bd84 + (uint)in_EAX[5] * DAT_00f8bd88 +
                      (uint)in_EAX[8] * DAT_00f8bd8c);
  FUN_004ad080(fVar1 * fVar1 + fVar2 * fVar2);
  iVar3 = FUN_008fed10();
  if (0xff < iVar3) {
    iVar3 = 0xff;
  }
  return iVar3;
}

