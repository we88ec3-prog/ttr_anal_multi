
void FUN_00597b70(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int unaff_EDI;
  
  piVar2 = *(int **)(*(int *)(unaff_EDI + 4) + 4);
  cVar1 = *(char *)((int)piVar2 + 0x21);
  while (cVar1 == '\0') {
    FUN_008575b0(piVar2[2]);
    piVar3 = (int *)*piVar2;
    FUN_0089120c(piVar2);
    piVar2 = piVar3;
    cVar1 = *(char *)((int)piVar3 + 0x21);
  }
  *(int *)(*(int *)(unaff_EDI + 4) + 4) = *(int *)(unaff_EDI + 4);
  *(undefined4 *)*(undefined4 *)(unaff_EDI + 4) = *(undefined4 *)(unaff_EDI + 4);
  *(int *)(*(int *)(unaff_EDI + 4) + 8) = *(int *)(unaff_EDI + 4);
  *(undefined4 *)(unaff_EDI + 8) = 0;
  return;
}

