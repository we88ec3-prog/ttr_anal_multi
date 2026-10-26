
void FUN_008e1d50(void)

{
  byte *pbVar1;
  char in_AL;
  uint uVar2;
  int iVar3;
  undefined8 uVar4;
  
  uVar4 = FUN_008e1d20();
  iVar3 = (int)((ulonglong)uVar4 >> 0x20);
  if ((int)uVar4 != 0) {
    uVar2 = 0;
    if (*(int *)(iVar3 + 0xc) != 0) {
      do {
        *(undefined1 *)(iVar3 + 0x10 + uVar2) = 0xff;
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(iVar3 + 0xc));
    }
    pbVar1 = (byte *)(*(int *)(iVar3 + 0xc) + 0xf + iVar3);
    *pbVar1 = *pbVar1 & ~((char)(1 << (-in_AL & 7U)) - 1U);
  }
  return;
}

