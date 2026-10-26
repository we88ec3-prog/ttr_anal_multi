
void FUN_00759130(int param_1,int param_2,char param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int unaff_EDI;
  
  piVar1 = *(int **)(unaff_EDI + 0x1c);
  piVar3 = (int *)*piVar1;
  do {
    while( true ) {
      piVar4 = piVar3;
      if (piVar4 == piVar1) {
        return;
      }
      iVar2 = piVar4[2];
      if ((iVar2 < param_1) || (param_1 + param_2 <= iVar2)) break;
      piVar3 = (int *)*piVar4;
      if (piVar4 != *(int **)(unaff_EDI + 0x1c)) {
        *(int *)piVar4[1] = *piVar4;
        *(int *)(*piVar4 + 4) = piVar4[1];
        FUN_0089120c(piVar4);
        *(int *)(unaff_EDI + 0x20) = *(int *)(unaff_EDI + 0x20) + -1;
      }
    }
    if (param_1 + param_2 <= iVar2) {
      if (param_3 == '\0') {
        return;
      }
      piVar4[2] = piVar4[2] - param_2;
    }
    piVar3 = (int *)*piVar4;
  } while( true );
}

