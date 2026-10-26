
undefined4 FUN_004f2940(void)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int in_EDX;
  int *piVar4;
  int unaff_EDI;
  
  uVar2 = *(int *)(in_EDX + 0x5ec0) - *(int *)(in_EDX + 0x5ebc) >> 2;
  uVar3 = 0;
  if (uVar2 != 0) {
    piVar4 = *(int **)(in_EDX + 0x5ebc);
    do {
      if (*(int *)(*piVar4 + 4) == unaff_EDI) {
        puVar1 = (undefined4 *)(*(int **)(in_EDX + 0x5ebc))[uVar3];
        if (puVar1 == (undefined4 *)0x0) {
          return 0;
        }
        return *puVar1;
      }
      uVar3 = uVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar3 < uVar2);
  }
  return 0;
}

