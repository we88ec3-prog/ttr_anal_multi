
void FUN_007619a0(void)

{
  uint uVar1;
  int iVar2;
  int unaff_ESI;
  undefined4 *puVar3;
  int local_c;
  uint local_8;
  
  uVar1 = *(uint *)(unaff_ESI + 0x168);
  iVar2 = *(int *)(unaff_ESI + 0x14c) + 1;
  if ((int)uVar1 < iVar2) {
    local_c = 0;
    local_8 = uVar1;
    if (*(uint *)(unaff_ESI + 0x118) < uVar1) {
      local_8 = *(uint *)(unaff_ESI + 0x118) - 1;
    }
    if (*(int **)(unaff_ESI + 0xf4) != (int *)0x0) {
      puVar3 = (undefined4 *)(unaff_ESI + 0x108);
      if (7 < *(uint *)(unaff_ESI + 0x11c)) {
        puVar3 = (undefined4 *)*puVar3;
      }
      (**(code **)(**(int **)(unaff_ESI + 0xf4) + 0x3c))
                (&local_c,*(int *)(unaff_ESI + 0xac) - *(int *)(unaff_ESI + 0xa4),
                 (int)puVar3 + local_8 * 2,iVar2 - uVar1);
    }
    *(int *)(unaff_ESI + 0x168) = *(int *)(unaff_ESI + 0x168) + local_c;
  }
  return;
}

