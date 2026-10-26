
void Catch_All_007a3aab(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x1c); iVar2 != iVar1; iVar2 = iVar2 + 8) {
    FUN_007a1050();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

