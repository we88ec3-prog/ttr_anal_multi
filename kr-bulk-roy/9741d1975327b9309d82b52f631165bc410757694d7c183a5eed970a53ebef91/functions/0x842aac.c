
void Catch_All_00842aac(void)

{
  int *piVar1;
  int *piVar2;
  int unaff_EBP;
  int *piVar3;
  
  piVar1 = *(int **)(unaff_EBP + 0xc);
  for (piVar3 = *(int **)(unaff_EBP + -0x14); piVar3 != piVar1; piVar3 = piVar3 + 0xd) {
    piVar2 = (int *)*piVar3;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *piVar3 = 0;
    }
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

