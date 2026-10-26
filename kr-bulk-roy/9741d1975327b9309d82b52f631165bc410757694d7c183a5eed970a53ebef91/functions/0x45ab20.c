
uint FUN_0045ab20(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int unaff_EDI;
  
  uVar3 = *(int *)(unaff_EDI + 0xf4) - *(int *)(unaff_EDI + 0xf0) >> 2;
  uVar2 = 0;
  if (uVar3 != 0) {
    piVar4 = *(int **)(unaff_EDI + 0xf0);
    do {
      iVar1 = *piVar4;
      if ((*(char *)(iVar1 + 0x2a4) == '\0') &&
         ((*(int *)(iVar1 + 0x2c0) == -1 || (*(int *)(iVar1 + 0x2c4) == -1)))) {
        *(uint *)(unaff_EDI + 0x100) = uVar2;
        return uVar2;
      }
      uVar2 = uVar2 + 1;
      piVar4 = piVar4 + 1;
    } while (uVar2 < uVar3);
  }
  return 0xffffffff;
}

