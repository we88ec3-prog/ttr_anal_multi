
void FUN_0071beb0(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *unaff_EDI;
  
  piVar1 = (int *)*unaff_EDI;
  piVar3 = (int *)*piVar1;
  if (piVar3 != (int *)unaff_EDI[1]) {
    do {
      piVar2 = (int *)*piVar3;
      (*(code *)PTR_FUN_00d63d4c)(piVar3);
      piVar3 = piVar2;
    } while (piVar2 != (int *)unaff_EDI[1]);
  }
  *piVar1 = unaff_EDI[1];
  piVar1[1] = unaff_EDI[2];
  return;
}

