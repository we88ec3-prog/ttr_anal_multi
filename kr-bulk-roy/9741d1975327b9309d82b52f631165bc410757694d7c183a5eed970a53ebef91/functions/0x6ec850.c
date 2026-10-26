
int FUN_006ec850(int param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  int unaff_EDI;
  
  iVar2 = 0;
  if (0 < *(int *)(in_ECX + 0x58)) {
    piVar3 = *(int **)(in_ECX + 0x54);
    while (piVar1 = (int *)*piVar3, *piVar1 != unaff_EDI) {
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
      if (*(int *)(in_ECX + 0x58) <= iVar2) {
        return 0;
      }
    }
    iVar2 = 0;
    if (0 < piVar1[0x198]) {
      piVar3 = (int *)piVar1[0x197];
      do {
        if (*(int *)(*piVar3 + 4) == param_1) {
          return *piVar3;
        }
        iVar2 = iVar2 + 1;
        piVar3 = piVar3 + 1;
      } while (iVar2 < piVar1[0x198]);
    }
  }
  return 0;
}

