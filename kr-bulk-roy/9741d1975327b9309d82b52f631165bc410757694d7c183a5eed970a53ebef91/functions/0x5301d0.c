
undefined4 * FUN_005301d0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  int unaff_ESI;
  uint unaff_EDI;
  int local_c;
  undefined1 local_8 [4];
  
  if ((*(int *)(unaff_ESI + 0x30) != 0) && (*(int *)(*(int *)(unaff_ESI + 0x30) + 4) != in_ECX)) {
    *(undefined4 *)(unaff_ESI + 0x30) = 0;
  }
  if (*(int *)(unaff_ESI + 0x30) == 0) {
    FUN_008438c0(local_8);
    if (local_c == *(int *)(unaff_ESI + 4)) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(local_c + 0x10);
    }
    *(undefined4 *)(unaff_ESI + 0x30) = uVar2;
  }
  iVar1 = *(int *)(unaff_ESI + 0x30);
  if ((((iVar1 == 0) || (*(char *)(iVar1 + 0x24) != '\x01')) ||
      ((uint)((*(int *)(iVar1 + 0x54) - *(int *)(iVar1 + 0x50)) / 0x28) < unaff_EDI)) ||
     (iVar1 = *(int *)(iVar1 + 0x50) + -0x28 + unaff_EDI * 0x28, iVar1 == 0)) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar3 = (undefined4 *)(iVar1 + 0xc);
    if (7 < *(uint *)(iVar1 + 0x20)) {
      return (undefined4 *)*puVar3;
    }
  }
  return puVar3;
}

