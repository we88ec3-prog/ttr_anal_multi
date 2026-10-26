
undefined4 FUN_008fc5a0(void)

{
  uint uVar1;
  undefined4 uVar2;
  int unaff_ESI;
  uint uVar3;
  int local_8;
  
  uVar1 = *(uint *)(unaff_ESI + 0x60);
  if (*(uint *)(unaff_ESI + 0x5c) < uVar1) {
    return 0;
  }
  uVar3 = (uVar1 >> 1) + 4 + uVar1;
  if (*(int *)(unaff_ESI + 0x58) == unaff_ESI + 100) {
    *(undefined4 *)(unaff_ESI + 0x58) = 0;
    uVar1 = 0;
  }
  if ((uVar3 < 0x10001) || (uVar3 = 0x10000, uVar1 != 0x10000)) {
    uVar2 = FUN_008bc7d0(*(undefined4 *)(unaff_ESI + 0xa8),1,uVar1,uVar3,
                         *(undefined4 *)(unaff_ESI + 0x58),&local_8);
    *(undefined4 *)(unaff_ESI + 0x58) = uVar2;
    if (local_8 == 0) {
      *(uint *)(unaff_ESI + 0x60) = uVar3;
      return 0;
    }
  }
  return 0xffffffff;
}

