
int FUN_008eb860(undefined4 param_1)

{
  byte bVar1;
  uint in_EAX;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  
  iVar5 = 0;
  iVar2 = FUN_008babe0(param_1);
  if (iVar2 != 0) {
    return 0;
  }
  if (3 < in_EAX) {
    iVar2 = (in_EAX - 4 >> 2) + 1;
    do {
      iVar3 = FUN_008b99c0(param_1);
      iVar5 = iVar5 + iVar3;
      in_EAX = in_EAX - 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if (in_EAX != 0) {
    bVar6 = 0x18;
    do {
      uVar4 = FUN_008b9940(param_1);
      bVar1 = bVar6 & 0x1f;
      bVar6 = bVar6 - 8;
      iVar5 = iVar5 + ((uVar4 & 0xff) << bVar1);
      in_EAX = in_EAX - 1;
    } while (in_EAX != 0);
  }
  FUN_008baca0(param_1);
  return iVar5;
}

