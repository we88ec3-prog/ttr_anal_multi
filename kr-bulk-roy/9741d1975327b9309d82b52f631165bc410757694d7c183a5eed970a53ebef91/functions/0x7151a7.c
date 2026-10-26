
void Catch_All_007151a7(void)

{
  int unaff_EBP;
  int *piVar1;
  
  piVar1 = *(int **)(unaff_EBP + -0x14);
  if (piVar1 != *(int **)(unaff_EBP + 0xc)) {
    do {
      FUN_007151f0(unaff_EBP + -0x18,*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)*(int *)(unaff_EBP + 0xc));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

