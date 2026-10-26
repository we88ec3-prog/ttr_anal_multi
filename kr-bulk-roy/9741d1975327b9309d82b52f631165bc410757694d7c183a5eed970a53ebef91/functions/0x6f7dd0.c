
undefined4 FUN_006f7dd0(void)

{
  uint uVar1;
  int in_ECX;
  int in_EDX;
  int unaff_EDI;
  
  uVar1 = *(uint *)(in_EDX + 0x14);
  if (0 < in_ECX) {
    do {
      if (uVar1 <= *(uint *)(in_EDX + 0x28)) break;
      in_ECX = in_ECX + -1;
      if (*(char *)(**(int **)(uVar1 + 4) + 6) == '\0') {
        in_ECX = in_ECX - *(int *)(uVar1 + 0x14);
      }
      uVar1 = uVar1 - 0x18;
    } while (0 < in_ECX);
  }
  if (in_ECX == 0) {
    if (*(uint *)(in_EDX + 0x28) < uVar1) {
      *(int *)(unaff_EDI + 0x60) = (int)(uVar1 - *(uint *)(in_EDX + 0x28)) / 0x18;
      return 1;
    }
  }
  else if (in_ECX < 0) {
    *(undefined4 *)(unaff_EDI + 0x60) = 0;
    return 1;
  }
  return 0;
}

