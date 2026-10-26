
undefined4 FUN_004d44c0(int param_1)

{
  uint in_EAX;
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  int unaff_ESI;
  
  if (in_EAX < 2) {
    uVar3 = 0;
  }
  else {
    uVar3 = (in_EAX - 2) / 5;
  }
  if (uVar3 != 0) {
    pbVar2 = (byte *)(param_1 + 2);
    do {
      if (((*pbVar2 < 10) &&
          (iVar1 = (uint)*pbVar2 * 0x210 + unaff_ESI, *(int *)(iVar1 + 0x5c) != 0)) && (iVar1 != 0))
      {
        *(undefined4 *)(iVar1 + 0xf8) = *(undefined4 *)(pbVar2 + 1);
      }
      pbVar2 = pbVar2 + 5;
      uVar3 = uVar3 - 1;
    } while (uVar3 != 0);
  }
  return 1;
}

