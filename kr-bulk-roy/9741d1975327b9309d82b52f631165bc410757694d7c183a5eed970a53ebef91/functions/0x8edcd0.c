
void FUN_008edcd0(void)

{
  byte *pbVar1;
  ushort uVar2;
  ushort uVar3;
  ushort *in_ECX;
  uint uVar4;
  uint uVar5;
  int unaff_ESI;
  
  uVar2 = in_ECX[2];
  uVar3 = *in_ECX;
  uVar4 = (uint)uVar3;
  if ((uVar2 < *(ushort *)(unaff_ESI + 0x98)) && (uVar3 < *(ushort *)(unaff_ESI + 0x98))) {
    if (uVar3 <= uVar2) {
      uVar5 = (uVar2 - uVar4) + 1 & 0xffff;
      do {
        pbVar1 = (byte *)(*(int *)(unaff_ESI + 0xa8) + uVar4);
        *pbVar1 = *pbVar1 | 1;
        uVar4 = uVar4 + 1;
        uVar5 = uVar5 - 1;
      } while (uVar5 != 0);
      return;
    }
  }
  else if (*(char *)(unaff_ESI + 0x231) != '\0') {
    *(undefined4 *)(unaff_ESI + 0xc) = 0x86;
  }
  return;
}

