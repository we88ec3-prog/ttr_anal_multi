
undefined4 FUN_0073bc90(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  if ((param_1 < (uint)(*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x18) >> 2)) &&
     (iVar1 = *(int *)(*(int *)(in_ECX + 0x18) + param_1 * 4), iVar1 != 0)) {
    if (*(int *)(iVar1 + 0xb0) < 2) {
      if (*(HGDIOBJ *)(iVar1 + 0xac) != (HGDIOBJ)0x0) {
        DeleteObject(*(HGDIOBJ *)(iVar1 + 0xac));
        *(undefined4 *)(iVar1 + 0xac) = 0;
      }
      FUN_0089120c(iVar1);
      *(undefined4 *)(*(int *)(in_ECX + 0x18) + param_1 * 4) = 0;
      return 1;
    }
    *(int *)(iVar1 + 0xb0) = *(int *)(iVar1 + 0xb0) + -1;
  }
  return 0;
}

