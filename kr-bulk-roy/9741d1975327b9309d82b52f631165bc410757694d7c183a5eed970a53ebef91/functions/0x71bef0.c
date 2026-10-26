
void FUN_0071bef0(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int unaff_EDI;
  
  iVar1 = **(int **)(unaff_EDI + 0x2008);
  piVar3 = *(int **)(unaff_EDI + 0x2008);
  while (iVar1 != 0) {
    piVar2 = (int *)*piVar3;
    (*(code *)PTR_FUN_00d63d4c)(piVar3);
    piVar3 = piVar2;
    iVar1 = *piVar2;
  }
  iVar1 = **(int **)(unaff_EDI + 0x2010);
  piVar3 = *(int **)(unaff_EDI + 0x2010);
  while (iVar1 != 0) {
    piVar2 = (int *)*piVar3;
    (*(code *)PTR_FUN_00d63d4c)(piVar3);
    piVar3 = piVar2;
    iVar1 = *piVar2;
  }
  return;
}

