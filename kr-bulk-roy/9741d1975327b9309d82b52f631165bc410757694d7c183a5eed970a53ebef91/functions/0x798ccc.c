
void Catch_All_00798ccc(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x48) {
    FUN_007cd310();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}

