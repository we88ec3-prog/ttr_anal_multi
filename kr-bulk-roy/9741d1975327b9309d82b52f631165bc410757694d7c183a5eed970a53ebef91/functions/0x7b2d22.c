
void Catch_All_007b2d22(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x20) {
    FUN_0048e600();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

