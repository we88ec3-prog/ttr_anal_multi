
undefined4 FUN_006f88d0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  int unaff_EDI;
  
  if (((((*(int **)(in_ECX + 4))[2] != 6) || (*(char *)(**(int **)(in_ECX + 4) + 6) != '\0')) ||
      (*(int *)(in_ECX + 0x14) < 1)) &&
     (((*(int **)(in_ECX + -0x14))[2] == 6 && (*(char *)(**(int **)(in_ECX + -0x14) + 6) == '\0'))))
  {
    piVar1 = *(int **)(in_ECX + -0x14);
    if ((piVar1[2] == 6) && (*(char *)(*piVar1 + 6) == '\0')) {
      if (in_ECX + -0x18 == *(int *)(unaff_EDI + 0x14)) {
        *(undefined4 *)(in_ECX + -0xc) = *(undefined4 *)(unaff_EDI + 0x18);
      }
      iVar2 = (*(int *)(in_ECX + -0xc) - *(int *)(*(int *)(*piVar1 + 0x10) + 0xc) >> 2) + -1;
    }
    else {
      iVar2 = -1;
    }
    uVar4 = *(uint *)(*(int *)(*(int *)(*piVar1 + 0x10) + 0xc) + iVar2 * 4) & 0x3f;
    if (((uVar4 == 0x1c) || (uVar4 == 0x1d)) || (uVar4 == 0x21)) {
      uVar3 = FUN_006f8750();
      return uVar3;
    }
  }
  return 0;
}

