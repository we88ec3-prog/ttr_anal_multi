
void Catch_All_007b2e16(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0xc);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x38) {
    FUN_007ee080();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

