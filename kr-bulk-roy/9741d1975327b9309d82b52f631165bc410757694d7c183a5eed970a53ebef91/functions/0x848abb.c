
void Catch_All_00848abb(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + -0x7c);
  for (iVar2 = *(int *)(unaff_EBP + -0x80); iVar2 != iVar1; iVar2 = iVar2 + 100) {
    FUN_00848cd0();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

