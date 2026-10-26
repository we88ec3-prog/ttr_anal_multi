
void Catch_All_00678405(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + -0x14);
  if (iVar1 != *(int *)(unaff_EBP + 0x10)) {
    do {
      FUN_00404c80(*(undefined4 *)(*(int *)(unaff_EBP + 0xc) + 4));
      iVar1 = iVar1 + 4;
    } while (iVar1 != *(int *)(unaff_EBP + 0x10));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

