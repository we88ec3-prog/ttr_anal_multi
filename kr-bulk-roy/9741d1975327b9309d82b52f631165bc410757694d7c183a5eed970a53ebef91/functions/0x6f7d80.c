
undefined4 FUN_006f7d80(void)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int in_EDX;
  
  piVar1 = *(int **)(in_EAX + 4);
  if ((piVar1[2] == 6) && (*(char *)(*piVar1 + 6) == '\0')) {
    if (in_EAX == *(int *)(in_EDX + 0x14)) {
      *(undefined4 *)(in_EAX + 0xc) = *(undefined4 *)(in_EDX + 0x18);
    }
    iVar3 = (*(int *)(in_EAX + 0xc) - *(int *)(*(int *)(*piVar1 + 0x10) + 0xc) >> 2) + -1;
    if (-1 < iVar3) {
      iVar2 = *(int *)(*(int *)(*piVar1 + 0x10) + 0x14);
      if (iVar2 != 0) {
        return *(undefined4 *)(iVar2 + iVar3 * 4);
      }
      return 0;
    }
  }
  return 0xffffffff;
}

