
void FUN_00408610(void)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int unaff_ESI;
  
  uVar2 = 0;
  uVar1 = *(int *)(unaff_ESI + 0xf4) - *(int *)(unaff_ESI + 0xf0) >> 2;
  if (uVar1 != 0) {
    piVar3 = *(int **)(unaff_ESI + 0xf0);
    do {
      if (*(int *)(*piVar3 + 0x25c) == 0) {
        *(uint *)(unaff_ESI + 0x100) = uVar2;
        return;
      }
      uVar2 = uVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (uVar2 < uVar1);
  }
  *(undefined4 *)(unaff_ESI + 0x100) = 0xffffffff;
  return;
}

