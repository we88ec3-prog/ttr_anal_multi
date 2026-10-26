
uint FUN_005f60e0(void)

{
  uint uVar1;
  int *unaff_ESI;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = (**(code **)(*unaff_ESI + 0x198))();
  if (0 < (int)uVar1) {
    do {
      if (*(char *)(*(int *)(unaff_ESI[0x3d] + iVar2 * 4) + 0x2cc) != '\0') {
        return CONCAT31((int3)((uint)unaff_ESI[0x3d] >> 8),1);
      }
      iVar2 = iVar2 + 1;
      uVar1 = (**(code **)(*unaff_ESI + 0x198))();
    } while (iVar2 < (int)uVar1);
  }
  return uVar1 & 0xffffff00;
}

