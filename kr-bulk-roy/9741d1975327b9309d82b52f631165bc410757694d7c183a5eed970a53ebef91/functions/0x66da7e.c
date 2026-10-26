
void Catch_All_0066da7e(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x50) {
    FUN_004c4350();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

