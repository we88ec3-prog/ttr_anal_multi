
void FUN_0066f590(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_EDI;
  
  *(undefined4 *)(unaff_EDI + 0x248) = 0;
  FUN_00757710();
  (**(code **)(**(int **)(unaff_EDI + 0x24c) + 200))();
  FUN_00757710();
  (**(code **)(**(int **)(unaff_EDI + 0x250) + 200))();
  iVar2 = *(int *)(unaff_EDI + 0x254);
  if ((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) {
    iVar4 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))();
    if (iVar4 == 0xbf6b) {
      iVar2 = *(int *)(iVar2 + 0x94);
      iVar4 = *(int *)(iVar2 + 0x10);
      if (iVar4 != 0) {
        piVar3 = *(int **)(iVar4 + 8);
        if (piVar3 != (int *)0x0) {
          piVar1 = piVar3 + 0x27;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (**(code **)(*piVar3 + 0x28))();
          }
        }
        *(undefined4 *)(iVar2 + 0x10) = 0;
      }
    }
  }
  (**(code **)(**(int **)(unaff_EDI + 0x254) + 200))();
  iVar2 = *(int *)(unaff_EDI + 600);
  if ((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) {
    iVar4 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))();
    if (iVar4 == 0xbf6b) {
      iVar2 = *(int *)(iVar2 + 0x94);
      iVar4 = *(int *)(iVar2 + 0x10);
      if (iVar4 != 0) {
        piVar3 = *(int **)(iVar4 + 8);
        if (piVar3 != (int *)0x0) {
          piVar1 = piVar3 + 0x27;
          *piVar1 = *piVar1 + -1;
          if (*piVar1 == 0) {
            (**(code **)(*piVar3 + 0x28))();
          }
        }
        *(undefined4 *)(iVar2 + 0x10) = 0;
      }
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0066f6b6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(unaff_EDI + 600) + 200))();
  return;
}

