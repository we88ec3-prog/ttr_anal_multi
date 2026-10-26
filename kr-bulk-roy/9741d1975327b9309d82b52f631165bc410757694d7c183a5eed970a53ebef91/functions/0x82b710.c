
byte * FUN_0082b710(byte param_1)

{
  byte *pbVar1;
  int iVar2;
  undefined4 *in_EAX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  
  pbVar1 = (byte *)*in_EAX;
  iVar2 = in_EAX[1] - (int)pbVar1 >> 0x1f;
  iVar5 = (in_EAX[1] - (int)pbVar1) / 0x24 + iVar2;
  uVar3 = iVar5 - iVar2;
  if (uVar3 < param_1) {
    return (byte *)0x0;
  }
  uVar4 = 0;
  pbVar6 = pbVar1;
  if (iVar5 != iVar2) {
    do {
      if (*pbVar6 == param_1) {
        if (*(uint *)(pbVar1 + uVar4 * 0x24 + 0x1c) < 8) {
          return pbVar1 + uVar4 * 0x24 + 8;
        }
        return *(byte **)(pbVar1 + uVar4 * 0x24 + 8);
      }
      uVar4 = uVar4 + 1;
      pbVar6 = pbVar6 + 0x24;
    } while (uVar4 < uVar3);
  }
  return (byte *)0x0;
}

