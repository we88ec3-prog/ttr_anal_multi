
int * FUN_004dc9d0(int param_1)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int unaff_ESI;
  
  uVar1 = *(int *)(unaff_ESI + 0x48) - *(int *)(unaff_ESI + 0x44) >> 3;
  if (uVar1 != 0) {
    uVar2 = 0;
    piVar3 = *(int **)(unaff_ESI + 0x44);
    do {
      if (*piVar3 == param_1 + 1) {
        return *(int **)(unaff_ESI + 0x44) + uVar2 * 2;
      }
      uVar2 = uVar2 + 1;
      piVar3 = piVar3 + 2;
    } while (uVar2 < uVar1);
  }
  return (int *)(*(int *)(unaff_ESI + 0x44) + param_1 * 8);
}

