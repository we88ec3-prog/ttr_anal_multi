
void FUN_0056fb70(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *unaff_EDI;
  
  piVar3 = *(int **)*unaff_EDI;
  if (piVar3 != (int *)*unaff_EDI) {
    do {
      iVar1 = piVar3[2];
      if (iVar1 != 0) {
        if (7 < *(uint *)(iVar1 + 0x38)) {
          FUN_0089120c(*(undefined4 *)(iVar1 + 0x24));
        }
        *(undefined4 *)(iVar1 + 0x38) = 7;
        *(undefined4 *)(iVar1 + 0x34) = 0;
        *(undefined2 *)(iVar1 + 0x24) = 0;
        FUN_0089120c(iVar1);
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)*unaff_EDI);
  }
  piVar3 = (int *)*unaff_EDI;
  piVar2 = (int *)*piVar3;
  *piVar3 = (int)piVar3;
  *(int *)(*unaff_EDI + 4) = *unaff_EDI;
  unaff_EDI[1] = 0;
  if (piVar2 != (int *)*unaff_EDI) {
    do {
      piVar3 = (int *)*piVar2;
      FUN_0089120c(piVar2);
      piVar2 = piVar3;
    } while (piVar3 != (int *)*unaff_EDI);
  }
  return;
}

