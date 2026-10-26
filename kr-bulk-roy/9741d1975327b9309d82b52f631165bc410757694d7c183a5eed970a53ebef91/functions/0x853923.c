
void Catch_All_00853923(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x18) {
    FUN_007838f0();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

