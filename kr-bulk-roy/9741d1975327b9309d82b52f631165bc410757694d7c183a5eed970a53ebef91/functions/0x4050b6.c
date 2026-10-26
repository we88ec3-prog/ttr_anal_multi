
void Catch_All_004050b6(void)

{
  int *piVar1;
  int unaff_EBP;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0x10)) {
    do {
      FUN_00404c80(*(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0x10));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

