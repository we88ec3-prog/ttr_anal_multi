
undefined4 FUN_006f5910(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int unaff_ESI;
  
  piVar2 = (int *)FUN_006f50f0();
  if (*(int *)(*(int *)(unaff_ESI + 8) + -8) == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(*(int *)(unaff_ESI + 8) + -0x10);
  }
  iVar1 = piVar2[2];
  if (iVar1 == 5) {
    *(int *)(*piVar2 + 8) = iVar3;
    if (((iVar3 != 0) && ((*(byte *)(iVar3 + 5) & 3) != 0)) &&
       (iVar3 = *piVar2, (*(byte *)(iVar3 + 5) & 4) != 0)) {
      iVar1 = *(int *)(unaff_ESI + 0x10);
      *(byte *)(iVar3 + 5) = *(byte *)(iVar3 + 5) & 0xfb;
      *(undefined4 *)(iVar3 + 0x18) = *(undefined4 *)(iVar1 + 0x28);
      *(int *)(iVar1 + 0x28) = iVar3;
    }
  }
  else {
    if (iVar1 != 7) {
      *(int *)(*(int *)(unaff_ESI + 0x10) + 0x98 + iVar1 * 4) = iVar3;
      *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -0x10;
      return 1;
    }
    *(int *)(*piVar2 + 8) = iVar3;
    if (((iVar3 != 0) && ((*(byte *)(iVar3 + 5) & 3) != 0)) && ((*(byte *)(*piVar2 + 5) & 4) != 0))
    {
      FUN_006fb5a0(iVar3);
      *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -0x10;
      return 1;
    }
  }
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + -0x10;
  return 1;
}

