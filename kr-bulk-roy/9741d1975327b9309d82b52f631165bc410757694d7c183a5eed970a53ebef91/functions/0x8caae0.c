
uint FUN_008caae0(void)

{
  uint uVar1;
  int iVar2;
  int in_EDX;
  int iVar3;
  int unaff_ESI;
  
  uVar1 = *(uint *)(unaff_ESI + 0x30);
  iVar2 = *(int *)(unaff_ESI + 0x20) + uVar1 * -4;
  do {
    uVar1 = uVar1 - 1;
    if ((int)uVar1 < 0) goto LAB_008cab1d;
  } while (in_EDX < *(int *)(iVar2 + uVar1 * 4));
  if (-1 < (int)uVar1) {
    iVar3 = in_EDX;
    if (in_EDX <= *(int *)(iVar2 + uVar1 * 4)) goto LAB_008cab45;
    do {
      uVar1 = uVar1 - 1;
      in_EDX = *(int *)(iVar2 + 4 + uVar1 * 4);
      *(int *)(iVar2 + 4 + uVar1 * 4) = iVar3;
      iVar3 = in_EDX;
    } while (-1 < (int)uVar1);
  }
LAB_008cab1d:
  *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + -4;
  if (*(uint *)(unaff_ESI + 0x24) <= *(uint *)(unaff_ESI + 0x28)) {
    *(undefined4 *)(unaff_ESI + 0x2c) = 0x62;
    return CONCAT31((int3)(*(uint *)(unaff_ESI + 0x24) >> 8),1);
  }
  *(int *)(unaff_ESI + 0x30) = *(int *)(unaff_ESI + 0x30) + 1;
  uVar1 = *(int *)(unaff_ESI + 0x30) * 4;
  *(int *)(*(int *)(unaff_ESI + 0x20) + *(int *)(unaff_ESI + 0x30) * -4) = in_EDX;
LAB_008cab45:
  return uVar1 & 0xffffff00;
}

